using System;
using System.Linq;
using System.Threading.Tasks;
using UnityEngine;
using Unity.Passport.Runtime;

/// <summary>
/// UOS 经济系统管理器 — 封装 Economy API。
/// 单例，DontDestroyOnLoad。首次访问 Instance 时自动创建。
/// </summary>
public class UOSEconomyManager : MonoBehaviour
{
    private static UOSEconomyManager _instance;
    public static UOSEconomyManager Instance
    {
        get
        {
            if (_instance == null)
            {
                var go = new GameObject("UOSEconomyManager");
                _instance = go.AddComponent<UOSEconomyManager>();
            }
            return _instance;
        }
    }

    /// <summary>金币资源的 slug 名（需与 UOS 后台 Economy 资源配置一致）</summary>
    public const string GoldCoinSlug = "gold_coin";

    /// <summary>金币余额变化事件（领取邮件后通知 UI 刷新）</summary>
    public event Action<uint> OnGoldBalanceChanged;

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
    /// 确保 PassportFeatureSDK 已初始化（幂等，与 UOSInboxManager 共享状态）。
    /// </summary>
    public async Task Initialize()
    {
        // 共享 UOSInboxManager 的静态标记，避免重复初始化
        if (UOSInboxManager.FeatureSDKInitialized) return;

        try
        {
            Debug.Log("[UOSEconomyManager] 正在初始化 PassportFeatureSDK...");
            await PassportFeatureSDK.Initialize();
            UOSInboxManager.FeatureSDKInitialized = true;
            Debug.Log("[UOSEconomyManager] PassportFeatureSDK 初始化成功");
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSEconomyManager] Feature SDK 初始化失败: {ex.Message}");
            throw;
        }
    }

    /// <summary>
    /// 获取金币余额。
    /// </summary>
    /// <returns>金币数量，失败返回 0</returns>
    public async Task<uint> GetGoldBalance()
    {
        try
        {
            await Initialize();
            var response = await PassportFeatureSDK.Economy.SearchPersonaInventory(
                start: 0, count: 1,
                resourceSlug: GoldCoinSlug);

            if (response.Inventory != null && response.Inventory.Count > 0)
            {
                var item = response.Inventory.First();
                Debug.Log($"[UOSEconomyManager] 金币余额: {item.Quantity}");
                return item.Quantity;
            }

            Debug.Log("[UOSEconomyManager] 金币余额: 0（未找到或尚未获得）");
            return 0;
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSEconomyManager] 获取金币余额失败: {ex.Message}");
            return 0;
        }
    }

    /// <summary>
    /// 刷新金币余额并触发事件通知 UI。
    /// </summary>
    public async Task<uint> RefreshGoldBalance()
    {
        uint balance = await GetGoldBalance();
        OnGoldBalanceChanged?.Invoke(balance);
        return balance;
    }
}
