using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using Economy;
using UnityEngine;
using Unity.Passport.Runtime;

/// <summary>
/// UOS Loadout 管理器 — 读取/保存玩家的武器装备配置。
/// Loadout 存储为一个特殊的背包 Item（slug: "loadout"），使用 customData JSON。
/// 参照 UOSEconomyManager 的 SDK 调用模式。
/// </summary>
public class UOSLoadoutManager : MonoBehaviour
{
    private static UOSLoadoutManager _instance;
    public static UOSLoadoutManager Instance
    {
        get
        {
            if (_instance == null)
            {
                var go = new GameObject("UOSLoadoutManager");
                _instance = go.AddComponent<UOSLoadoutManager>();
            }
            return _instance;
        }
    }

    public const string LoadoutItemSlug = "loadout";
    private const string CustomDataKey = "data";

    public LoadoutData CachedLoadout { get; set; }
    private string _loadoutInventoryItemId;

    public event Action OnLoadoutChanged;

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
            Debug.LogError($"[UOSLoadoutManager] Init failed: {ex.Message}");
        }
    }

    /// <summary>从 UOS 加载 Loadout。</summary>
    public async Task<LoadoutData> LoadLoadout()
    {
        await Initialize();

        try
        {
            var response = await PassportFeatureSDK.Economy.SearchPersonaInventory(
                0, 10, null, LoadoutItemSlug);

            if (response?.Inventory != null && response.Inventory.Count > 0)
            {
                var item = response.Inventory[0];
                _loadoutInventoryItemId = item.InventoryItemId;

                if (item.CustomData != null && item.CustomData.TryGetValue(CustomDataKey, out string json))
                    CachedLoadout = LoadoutData.FromJson(json);
                else
                    CachedLoadout = CreateDefaultLoadout();

                LoadoutData.CurrentLoadout = CachedLoadout;
                Debug.Log($"[UOSLoadoutManager] Loadout loaded: {CachedLoadout.GetEquippedWeapons().Count} weapons.");
            }
            else
            {
                // 首次登录：发放默认武器 + 创建 loadout 物品
                await GrantFirstTimeItems();
                CachedLoadout = CreateDefaultLoadout();
                LoadoutData.CurrentLoadout = CachedLoadout;
                await SaveLoadout();
                Debug.Log("[UOSLoadoutManager] Created default loadout.");
            }
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSLoadoutManager] LoadLoadout failed: {ex.Message}");
            CachedLoadout = CreateDefaultLoadout();
            LoadoutData.CurrentLoadout = CachedLoadout;
        }

        OnLoadoutChanged?.Invoke();
        return CachedLoadout;
    }

    /// <summary>保存 Loadout 到 UOS。</summary>
    public async Task<bool> SaveLoadout()
    {
        await Initialize();

        if (CachedLoadout == null)
        {
            Debug.LogError("[UOSLoadoutManager] No loadout to save!");
            return false;
        }

        LoadoutData.CurrentLoadout = CachedLoadout;
        string json = CachedLoadout.ToJson();

        try
        {
            if (string.IsNullOrEmpty(_loadoutInventoryItemId))
            {
                var response = await PassportFeatureSDK.Economy.SearchPersonaInventory(
                    0, 10, null, LoadoutItemSlug);

                if (response?.Inventory != null && response.Inventory.Count > 0)
                {
                    _loadoutInventoryItemId = response.Inventory[0].InventoryItemId;
                }
                else
                {
                    // 先创建 loadout 物品
                    await PassportFeatureSDK.Economy.DepositResources(new List<DepositResource>
                    {
                        new DepositResource { ResourceSlug = LoadoutItemSlug, DepositQuantity = 1 }
                    });
                    // 再搜索获取 InventoryItemId
                    response = await PassportFeatureSDK.Economy.SearchPersonaInventory(
                        0, 10, null, LoadoutItemSlug);
                    if (response?.Inventory != null && response.Inventory.Count > 0)
                        _loadoutInventoryItemId = response.Inventory[0].InventoryItemId;
                    else
                    {
                        Debug.LogWarning("[UOSLoadoutManager] Failed to create loadout item on server.");
                        return false;
                    }
                }
            }

            var customData = new Dictionary<string, string> { [CustomDataKey] = json };
            await PassportFeatureSDK.Economy.UpdateInventoryItem(_loadoutInventoryItemId, customData);
            Debug.Log("[UOSLoadoutManager] Loadout saved.");
            OnLoadoutChanged?.Invoke();
            return true;
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSLoadoutManager] SaveLoadout failed: {ex.Message}");
            return false;
        }
    }

    /// <summary>首次登录：发放默认武器 + loadout 物品。</summary>
    private static async Task GrantFirstTimeItems()
    {
        try
        {
            // 检查是否已有 wpn_ar_01，避免重复发放
            var invResponse = await PassportFeatureSDK.Economy.SearchPersonaInventory(
                0, 1, null, UOSInventoryManager.DefaultWeaponSlug);
            bool hasDefaultWeapon = invResponse?.Inventory != null && invResponse.Inventory.Count > 0;

            var resources = new List<DepositResource>();
            if (!hasDefaultWeapon)
            {
                resources.Add(new DepositResource
                {
                    ResourceSlug = UOSInventoryManager.DefaultWeaponSlug,
                    DepositQuantity = 1
                });
            }
            resources.Add(new DepositResource
            {
                ResourceSlug = LoadoutItemSlug,
                DepositQuantity = 1
            });

            await PassportFeatureSDK.Economy.DepositResources(resources);
            Debug.Log("[UOSLoadoutManager] First-time items granted.");
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSLoadoutManager] GrantFirstTimeItems failed: {ex.Message}");
        }
    }

    public static LoadoutData CreateDefaultLoadout()
    {
        var loadout = new LoadoutData();
        loadout.GetSlot(1).weaponSlug = UOSInventoryManager.DefaultWeaponSlug;
        return loadout;
    }
}
