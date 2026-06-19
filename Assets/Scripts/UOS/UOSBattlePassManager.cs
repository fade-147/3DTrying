using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using Economy;
using UnityEngine;
using Unity.Passport.Runtime;

/// <summary>
/// 战令系统核心逻辑。单例，DontDestroyOnLoad。
/// 每 KillsPerTier 击杀 = 1 个里程碑 = GoldPerTier 金币奖励。
/// 总击杀读 UOS Leaderboard "total-kills"（已有），
/// 已领取击杀读 UOS Leaderboard "bp-claimed-kills"（需在 UOS 控制台创建）。
/// 先 UpdateScore 再 DepositResources，防止排行榜不存在时误发金币。
/// </summary>
public class UOSBattlePassManager : MonoBehaviour
{
    private static UOSBattlePassManager _instance;
    public static UOSBattlePassManager Instance
    {
        get
        {
            if (_instance == null)
            {
                var go = new GameObject("UOSBattlePassManager");
                _instance = go.AddComponent<UOSBattlePassManager>();
            }
            return _instance;
        }
    }

    internal const string TotalKillsSlug = "total-kills";
    internal const string ClaimedKillsSlug = "bp-claimed-kills";

    public const int KillsPerTier = 10;
    public const int GoldPerTier = 5;

    private void Awake()
    {
        if (_instance != null && _instance != this)
        {
            Destroy(gameObject);
            return;
        }
        _instance = this;
        DontDestroyOnLoad(gameObject);
    }

    /// <summary>
    /// 确保 PassportFeatureSDK 已初始化（幂等，复用 UOSInboxManager 共享标记）。
    /// </summary>
    private async Task Initialize()
    {
        if (UOSInboxManager.FeatureSDKInitialized) return;

        try
        {
            Debug.Log("[UOSBattlePassManager] 正在初始化 PassportFeatureSDK...");
            await PassportFeatureSDK.Initialize();
            UOSInboxManager.FeatureSDKInitialized = true;
            Debug.Log("[UOSBattlePassManager] PassportFeatureSDK 初始化成功");
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSBattlePassManager] Feature SDK 初始化失败: {ex.Message}");
            throw;
        }
    }

    /// <summary>获取累计总击杀数（UOS Leaderboard "total-kills"）。失败返回 0。</summary>
    public async Task<int> GetTotalKills()
    {
        try
        {
            await Initialize();
            var response = await PassportFeatureSDK.Leaderboard.GetScore(TotalKillsSlug, range: 0);
            if (response?.Scores != null && response.Scores.Count > 0)
                return (int)response.Scores[0].Score;
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSBattlePassManager] 获取总击杀失败: {ex.Message}");
        }
        return 0;
    }

    /// <summary>获取已领取击杀数（UOS Leaderboard "bp-claimed-kills"）。排行榜不存在时返回 0。</summary>
    public async Task<int> GetClaimedKills()
    {
        try
        {
            await Initialize();
            var response = await PassportFeatureSDK.Leaderboard.GetScore(ClaimedKillsSlug, range: 0);
            if (response?.Scores != null && response.Scores.Count > 0)
                return (int)response.Scores[0].Score;
        }
        catch (Exception ex)
        {
            // 首次使用或排行榜未创建时 GetScore 也会抛异常，视作 0
            Debug.LogWarning($"[UOSBattlePassManager] 获取已领取击杀失败（可能排行榜未创建）: {ex.Message}");
        }
        return 0;
    }

    /// <summary>
    /// 获取战令状态：总击杀、已领取击杀、可领奖数量。
    /// </summary>
    public async Task<(int totalKills, int claimedKills, int availableCount)> GetStatus()
    {
        int totalKills = await GetTotalKills();
        int claimedKills = await GetClaimedKills();

        int totalTiers = totalKills / KillsPerTier;
        int claimedTiers = claimedKills / KillsPerTier;
        int availableCount = Mathf.Max(0, totalTiers - claimedTiers);

        Debug.Log($"[UOSBattlePassManager] GetStatus: total={totalKills}, claimed={claimedKills}, available={availableCount}");
        return (totalKills, claimedKills, availableCount);
    }

    /// <summary>
    /// 领取单个里程碑奖励。tierIndex: 0~9。返回获得金币数。
    /// 先更新 UOS Leaderboard 再发金币，排行榜不存在时不会误发。
    /// </summary>
    public async Task<int> ClaimTier(int tierIndex)
    {
        if (tierIndex < 0)
            throw new ArgumentOutOfRangeException(nameof(tierIndex), "tierIndex 不能为负数");

        await Initialize();

        int currentClaimed = await GetClaimedKills();
        int requiredKills = (tierIndex + 1) * KillsPerTier;

        if (currentClaimed >= requiredKills)
        {
            Debug.LogWarning($"[UOSBattlePassManager] ClaimTier: tier {tierIndex} 已领取过，跳过");
            return 0;
        }

        // 1. 先更新 UOS Leaderboard（防排行榜不存在时误发金币）
        int newClaimed = Mathf.Max(currentClaimed, requiredKills);
        await PassportFeatureSDK.Leaderboard.UpdateScore(ClaimedKillsSlug, newClaimed);
        Debug.Log($"[UOSBattlePassManager] 已更新 bp-claimed-kills = {newClaimed}");

        // 2. 发金币
        var resources = new List<DepositResource>
        {
            new DepositResource
            {
                ResourceSlug = UOSEconomyManager.GoldCoinSlug,
                DepositQuantity = GoldPerTier
            }
        };

        await PassportFeatureSDK.Economy.DepositResources(resources);
        Debug.Log($"[UOSBattlePassManager] 已发放 {GoldPerTier} 金币 (tier {tierIndex})");

        // 3. 刷新金币余额（触发 UI 更新）
        if (UOSEconomyManager.Instance != null)
            await UOSEconomyManager.Instance.RefreshGoldBalance();

        return GoldPerTier;
    }

    /// <summary>
    /// 全部领取所有可领奖励。返回 (领取节点数, 总金币)。
    /// </summary>
    public async Task<(int claimedCount, int totalGold)> ClaimAll()
    {
        var (totalKills, claimedKills, availableCount) = await GetStatus();

        if (availableCount <= 0)
        {
            Debug.Log("[UOSBattlePassManager] ClaimAll: 无可领取奖励");
            return (0, 0);
        }

        await Initialize();

        int totalGold = availableCount * GoldPerTier;
        int currentClaimedTiers = claimedKills / KillsPerTier;
        int newClaimedKills = (currentClaimedTiers + availableCount) * KillsPerTier;

        // 1. 先更新 UOS Leaderboard
        await PassportFeatureSDK.Leaderboard.UpdateScore(ClaimedKillsSlug, newClaimedKills);
        Debug.Log($"[UOSBattlePassManager] 全部领取: 已更新 bp-claimed-kills = {newClaimedKills}");

        // 2. 发金币
        var resources = new List<DepositResource>
        {
            new DepositResource
            {
                ResourceSlug = UOSEconomyManager.GoldCoinSlug,
                DepositQuantity = (uint)totalGold
            }
        };

        await PassportFeatureSDK.Economy.DepositResources(resources);
        Debug.Log($"[UOSBattlePassManager] 全部领取: 已发放 {totalGold} 金币 ({availableCount} 个节点)");

        // 3. 刷新金币余额
        if (UOSEconomyManager.Instance != null)
            await UOSEconomyManager.Instance.RefreshGoldBalance();

        return (availableCount, totalGold);
    }
}
