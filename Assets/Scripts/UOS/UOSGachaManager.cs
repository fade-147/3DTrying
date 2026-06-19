using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Economy;
using UnityEngine;
using Unity.Passport.Runtime;

/// <summary>
/// 抽卡奖励类型。
/// </summary>
public enum GachaRewardType
{
    Weapon,
    Attachment,
    Gold,
    Nothing
}

/// <summary>
/// 抽卡结果。
/// </summary>
public class GachaResult
{
    public bool Success;
    public string ErrorMessage;
    public GachaRewardType Type;
    public string RewardSlug;
    public string RewardDisplayName;
    public int GoldAmount;
    public uint GoldRemaining;
}

/// <summary>
/// UOS 抽卡管理器 — 单抽逻辑。
/// 参照 UOSEconomyManager 的 SDK 调用模式。
/// </summary>
public class UOSGachaManager : MonoBehaviour
{
    private static UOSGachaManager _instance;
    public static UOSGachaManager Instance
    {
        get
        {
            if (_instance == null)
            {
                var go = new GameObject("UOSGachaManager");
                _instance = go.AddComponent<UOSGachaManager>();
            }
            return _instance;
        }
    }

    public const string SinglePullSlug = "single_pull";
    public const uint SinglePullCost = 10;

    // 概率常量
    private const float WeaponDropRate = 0.30f;
    private const float AttachmentDropRate = 0.30f;
    private const float Gold20DropRate = 0.10f;
    private const float Gold5DropRate = 0.20f;
    private const float ThresholdWeapon = WeaponDropRate;
    private const float ThresholdAttachment = ThresholdWeapon + AttachmentDropRate;
    private const float ThresholdGold20 = ThresholdAttachment + Gold20DropRate;
    private const float ThresholdGold5 = ThresholdGold20 + Gold5DropRate;
    private const int GoldRewardLarge = 20;
    private const int GoldRewardSmall = 5;

    private static readonly string[] AllWeaponSlugs = {
        "wpn_ar_01", "wpn_ar_02", "wpn_ar_03",
        "wpn_handgun_01", "wpn_handgun_02", "wpn_handgun_03", "wpn_handgun_04",
        "wpn_smg_01", "wpn_smg_02", "wpn_smg_03", "wpn_smg_04", "wpn_smg_05",
        "wpn_shotgun_01",
        "wpn_sniper_01", "wpn_sniper_02", "wpn_sniper_03",
        "wpn_gl_01", "wpn_rl_01"
    };

    private static readonly string[] AllAttachmentSlugs = {
        "att_scope_01", "att_scope_02", "att_scope_03", "att_scope_04",
        "att_scope_05", "att_scope_06", "att_scope_07", "att_scope_08",
        "att_muzzle_01", "att_muzzle_02", "att_muzzle_03", "att_muzzle_04",
        "att_laser_01", "att_laser_02",
        "att_grip_01", "att_grip_02", "att_grip_03"
    };

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

    private async Task Initialize()
    {
        if (UOSInboxManager.FeatureSDKInitialized) return;
        try
        {
            await PassportFeatureSDK.Initialize();
            UOSInboxManager.FeatureSDKInitialized = true;
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSGachaManager] Init failed: {ex.Message}");
        }
    }

    /// <summary>单抽。</summary>
    public async Task<GachaResult> SinglePull()
    {
        await Initialize();

        var invMgr = UOSInventoryManager.Instance;

        // 1. 检查金币余额
        await invMgr.RefreshGoldBalance();
        uint balance = invMgr.GoldBalance;
        if (balance < SinglePullCost)
        {
            return new GachaResult
            {
                Success = false,
                ErrorMessage = $"金币不足！需要 {SinglePullCost}，当前 {balance}。"
            };
        }

        // 2. 刷新背包（获取已拥有武器用于去重）
        await invMgr.RefreshInventory();
        var ownedWeapons = invMgr.GetOwnedWeaponSlugs();

        // 3. 客户端随机抽奖（武器去重，配件允许重复）
        var (type, slug, goldAmount) = RollGacha(ownedWeapons);

        try
        {
            // 4. 调用 UOS 虚拟购买（扣金币）
            await PassportFeatureSDK.Economy.VirtualPurchaseAndGetInventory(
                SinglePullSlug, 1, null);

            // 5. 发放真实奖励到 UOS 背包
            await GrantReward(type, slug, goldAmount);

            // 6. 构建结果
            var result = new GachaResult
            {
                Success = true,
                Type = type,
                RewardSlug = slug,
                GoldAmount = goldAmount,
            };

            if (type == GachaRewardType.Weapon)
            {
                result.RewardDisplayName = WeaponPrefabRegistry.GetDisplayName(slug);
            }
            else if (type == GachaRewardType.Attachment)
            {
                result.RewardDisplayName = AttachmentRegistry.GetDisplayName(slug);
            }

            // 7. 刷新背包缓存
            await invMgr.RefreshInventory();
            result.GoldRemaining = await UOSEconomyManager.Instance.RefreshGoldBalance();

            invMgr.NotifyChanged();
            Debug.Log($"[UOSGachaManager] Pull: {type} → {slug ?? goldAmount.ToString()}");
            return result;
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSGachaManager] VirtualPurchase failed: {ex.Message}");
            return new GachaResult { Success = false, ErrorMessage = ex.Message };
        }
    }

    private static (GachaRewardType type, string slug, int goldAmount) RollGacha(
        List<string> ownedWeapons)
    {
        float roll = UnityEngine.Random.value;

        if (roll < ThresholdWeapon)
        {
            var available = AllWeaponSlugs.Except(ownedWeapons).ToArray();
            if (available.Length > 0)
            {
                string weapon = available[UnityEngine.Random.Range(0, available.Length)];
                return (GachaRewardType.Weapon, weapon, 0);
            }
            return (GachaRewardType.Gold, null, GoldRewardSmall);
        }
        else if (roll < ThresholdAttachment)
        {
            // 配件允许重复获得，不去重
            if (AllAttachmentSlugs.Length > 0)
            {
                string att = AllAttachmentSlugs[UnityEngine.Random.Range(0, AllAttachmentSlugs.Length)];
                return (GachaRewardType.Attachment, att, 0);
            }
            return (GachaRewardType.Gold, null, GoldRewardSmall);
        }
        else if (roll < ThresholdGold20)
        {
            return (GachaRewardType.Gold, null, GoldRewardLarge);
        }
        else if (roll < ThresholdGold5)
        {
            return (GachaRewardType.Gold, null, GoldRewardSmall);
        }
        else
        {
            return (GachaRewardType.Nothing, null, 0);
        }
    }

    /// <summary>将抽到的真实奖励写入 UOS 背包。</summary>
    private static async Task GrantReward(GachaRewardType type, string slug, int goldAmount)
    {
        if (type == GachaRewardType.Nothing) return;

        try
        {
            List<DepositResource> resources;
            if (type == GachaRewardType.Gold)
            {
                resources = new List<DepositResource>
                {
                    new DepositResource
                    {
                        ResourceSlug = UOSEconomyManager.GoldCoinSlug,
                        DepositQuantity = (uint)goldAmount
                    }
                };
            }
            else
            {
                resources = new List<DepositResource>
                {
                    new DepositResource
                    {
                        ResourceSlug = slug,
                        DepositQuantity = 1
                    }
                };
            }

            await PassportFeatureSDK.Economy.DepositResources(resources);
            Debug.Log($"[UOSGachaManager] Granted: {type} -> {slug ?? goldAmount.ToString()}");
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSGachaManager] GrantReward failed ({type}, {slug}): {ex.Message}. " +
                           "奖励已丢失，需人工补偿！");
        }
    }
}
