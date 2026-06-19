using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using UnityEngine;
using Unity.Passport.Runtime;

/// <summary>
/// UOS 背包管理器 — 查询玩家背包中的武器和配件。
/// 参照 UOSEconomyManager 的 SDK 调用模式。
/// </summary>
public class UOSInventoryManager : MonoBehaviour
{
    private static UOSInventoryManager _instance;
    public static UOSInventoryManager Instance
    {
        get
        {
            if (_instance == null)
            {
                var go = new GameObject("UOSInventoryManager");
                _instance = go.AddComponent<UOSInventoryManager>();
            }
            return _instance;
        }
    }

    /// <summary>背包变化事件。</summary>
    public event Action OnInventoryChanged;

    /// <summary>默认武器 slug（新玩家自动获得）。</summary>
    public const string DefaultWeaponSlug = "wpn_ar_01";
    /// <summary>武器 slug 前缀。</summary>
    public const string WeaponPrefix = "wpn_";
    /// <summary>配件 slug 前缀。</summary>
    public const string AttachmentPrefix = "att_";

    /// <summary>金币余额。</summary>
    public uint GoldBalance { get; private set; }

    /// <summary>缓存的全部背包物品（类型为 Economy API 返回的原生类型）。</summary>
    public List<object> AllItems { get; private set; } = new();

    /// <summary>已拥有武器 slug 列表。</summary>
    private List<string> _ownedWeaponSlugs = new();
    /// <summary>已拥有配件 slug 列表。</summary>
    private List<string> _ownedAttachmentSlugs = new();

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
            Debug.LogError($"[UOSInventoryManager] Init failed: {ex.Message}");
        }
    }

    /// <summary>拉取全部背包物品并缓存。</summary>
    public async Task RefreshInventory()
    {
        await Initialize();
        _ownedWeaponSlugs.Clear();
        _ownedAttachmentSlugs.Clear();

        try
        {
            // 使用 ListPersonaInventory 获取全部背包（不传 namespace）
            var response = await PassportFeatureSDK.Economy.ListPersonaInventory(null);
            if (response?.Inventory != null)
            {
                AllItems = new List<object>(response.Inventory.Cast<object>());

                foreach (var item in response.Inventory)
                {
                    string slug = item?.Resource?.ResourceSlug;
                    if (string.IsNullOrEmpty(slug)) continue;

                    if (slug.StartsWith(WeaponPrefix))
                        _ownedWeaponSlugs.Add(slug);
                    else if (slug.StartsWith(AttachmentPrefix))
                        _ownedAttachmentSlugs.Add(slug);
                }

                Debug.Log($"[UOSInventoryManager] Loaded {AllItems.Count} items: {_ownedWeaponSlugs.Count} weapons, {_ownedAttachmentSlugs.Count} attachments.");
            }
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSInventoryManager] RefreshInventory failed: {ex.Message}");
        }
    }

    /// <summary>刷新金币余额。</summary>
    public async Task RefreshGoldBalance()
    {
        await Initialize();
        try
        {
            var response = await PassportFeatureSDK.Economy.SearchPersonaInventory(
                0, 10, null, UOSEconomyManager.GoldCoinSlug);

            if (response?.Inventory != null && response.Inventory.Count > 0)
                GoldBalance = response.Inventory[0].Quantity;
            else
                GoldBalance = 0;
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSInventoryManager] RefreshGoldBalance failed: {ex.Message}");
        }
    }

    /// <summary>获取已拥有的武器 slug 列表。</summary>
    public List<string> GetOwnedWeaponSlugs() => _ownedWeaponSlugs;

    /// <summary>获取已拥有的配件 slug 列表。</summary>
    public List<string> GetOwnedAttachmentSlugs() => _ownedAttachmentSlugs;

    /// <summary>检查是否拥有某个 slug。</summary>
    public bool HasItem(string slug) =>
        _ownedWeaponSlugs.Contains(slug) || _ownedAttachmentSlugs.Contains(slug);

    /// <summary>触发背包变化事件。</summary>
    public void NotifyChanged()
    {
        OnInventoryChanged?.Invoke();
    }
}
