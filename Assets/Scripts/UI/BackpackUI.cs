using System;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Threading.Tasks;

/// <summary>
/// 背包主面板 UI 控制器。
/// 左侧：3 个武器装备槽（各含 5 个配件小框）。
/// 右侧：背包物品网格（可切换武器/配件视图）。
/// </summary>
public class BackpackUI : MonoBehaviour
{
    [Header("Panel")]
    public GameObject panelRoot;

    [Header("Left - Weapon Slots")]
    public BackpackWeaponSlot[] weaponSlots; // 3 slots: index 0=pistol, 1=primary1, 2=primary2

    [Header("Collection Progress")]
    public TextMeshProUGUI weaponCollectionText;       // "已收集 X/18 种武器"
    public TextMeshProUGUI attachmentCollectionText;   // "已收集 X/17 种配件"

    [Header("Right - Inventory Grid")]
    public GameObject itemGridParent;
    public GameObject itemIconPrefab;       // DraggableItem prefab (手动拖入)
    public Button toggleViewButton;         // Switch between weapons/attachments
    public TextMeshProUGUI toggleViewLabel;
    public TextMeshProUGUI goldText;

    [Header("Locked Slot")]
    [Tooltip("不支持配件的槽位显示的 X 图标")]
    public Sprite lockedSlotIcon;

    [Header("Popup")]
    public WeaponInfoPopup weaponInfoPopup;
    public AttachmentInfoPopup attachmentInfoPopup;

    [Header("Buttons")]
    public Button closeButton;
    public Button saveButton;

    // State
    private bool _showingWeapons = true; // true=武器, false=配件
    private LoadoutData _currentLoadout;
    private List<string> _ownedWeaponSlugs = new();
    private List<string> _ownedAttachmentSlugs = new();

    private async void Awake()
    {
        panelRoot.SetActive(false);

        toggleViewButton?.onClick.AddListener(ToggleView);
        closeButton?.onClick.AddListener(() => panelRoot.SetActive(false));
        saveButton?.onClick.AddListener(async () => await SaveAndClose());

        UpdateToggleLabel();

        // 确保 itemGridParent 有 DropTarget（拖装备到背包区域 = 卸下）
        if (itemGridParent != null && itemGridParent.GetComponent<DropTarget>() == null)
        {
            var dt = itemGridParent.AddComponent<DropTarget>();
            dt.targetType = DropTarget.TargetType.InventoryGrid;
            dt.backpackUI = this;
        }

        // 自动加载 loadout（不等用户打开背包）
        await UOSLoadoutManager.Instance.LoadLoadout();
    }

    /// <summary>打开背包面板。</summary>
    public async void Open()
    {
        panelRoot.SetActive(true);

        // 刷新背包
        await UOSInventoryManager.Instance.RefreshInventory();
        _ownedWeaponSlugs = UOSInventoryManager.Instance.GetOwnedWeaponSlugs();
        _ownedAttachmentSlugs = UOSInventoryManager.Instance.GetOwnedAttachmentSlugs();

        // 加载 loadout
        _currentLoadout = await UOSLoadoutManager.Instance.LoadLoadout();

        // 更新金币显示
        if (goldText != null)
            goldText.text = $"金币: {UOSInventoryManager.Instance.GoldBalance}";

        // 刷新 UI
        RefreshWeaponSlots();
        RefreshInventoryGrid();
        RefreshCollectionText();
    }

    /// <summary>更新收集进度文本。</summary>
    private void RefreshCollectionText()
    {
        // 武器不可重复获得，用 Distinct 防 UOS 服务端冗余数据
        int ownedWeapons = _ownedWeaponSlugs.Distinct().Count();
        int totalWeapons = WeaponPrefabRegistry.GetAllSlugs().Count;
        if (weaponCollectionText != null)
            weaponCollectionText.text = $"已收集 <b>{ownedWeapons}</b>/{totalWeapons} 种武器";

        // 配件允许重复获得，Distinct 确保显示的是种类数
        int ownedAttachments = _ownedAttachmentSlugs.Distinct().Count();
        int totalAttachments = AttachmentRegistry.GetAllSlugs().Count;
        if (attachmentCollectionText != null)
            attachmentCollectionText.text = $"已收集 <b>{ownedAttachments}</b>/{totalAttachments} 种配件";
    }

    /// <summary>关闭。</summary>
    public void Close()
    {
        panelRoot.SetActive(false);
    }

    private async Task SaveAndClose()
    {
        if (_currentLoadout != null)
        {
            UOSLoadoutManager.Instance.CachedLoadout = _currentLoadout;
            await UOSLoadoutManager.Instance.SaveLoadout();
        }
        Close();
    }

    /// <summary>切换武器/配件视图。</summary>
    private void ToggleView()
    {
        _showingWeapons = !_showingWeapons;
        UpdateToggleLabel();
        RefreshInventoryGrid();
    }

    private void UpdateToggleLabel()
    {
        if (toggleViewLabel != null)
            toggleViewLabel.text = _showingWeapons ? "武器背包" : "配件背包";
    }

    /// <summary>刷新左边 3 个武器装备槽。</summary>
    private void RefreshWeaponSlots()
    {
        if (weaponSlots == null) return;
        for (int i = 0; i < weaponSlots.Length; i++)
        {
            var slot = weaponSlots[i];
            if (slot == null) continue;

            var loadoutSlot = _currentLoadout?.GetSlot(i);
            if (loadoutSlot == null) continue;

            slot.Init(this, i, loadoutSlot);
        }
    }

    /// <summary>刷新右边背包物品网格。</summary>
    private void RefreshInventoryGrid()
    {
        // Clear existing
        foreach (Transform child in itemGridParent.transform)
            Destroy(child.gameObject);

        if (_showingWeapons)
        {
            // Show owned weapons that are NOT currently equipped
            var equippedSlugs = GetEquippedWeaponSlugs();
            var available = _ownedWeaponSlugs
                .Where(s => !equippedSlugs.Contains(s))
                .ToList();

            foreach (var slug in available)
            {
                var go = Instantiate(itemIconPrefab, itemGridParent.transform);
                var entry = WeaponPrefabRegistry.GetEntry(slug);
                var drag = go.GetComponent<DraggableItem>();
                if (drag != null)
                {
                    // 优先数据表 icon，其次从 prefab spriteBody 自动读取
                    Sprite icon = entry?.icon ?? WeaponPrefabRegistry.GetIcon(slug);
                    drag.SetData(slug, true, icon);
                    drag.weaponCategory = entry?.category ?? WeaponCategory.Rifle;
                }
                // Click to show info
                var btn = go.GetComponent<Button>();
                if (btn != null)
                {
                    string capturedSlug = slug;
                    btn.onClick.AddListener(() => ShowWeaponInfo(capturedSlug));
                }
            }
        }
        else
        {
            // Show owned attachments that are NOT currently equipped
            var equippedSlugs = GetEquippedAttachmentSlugs();
            var available = _ownedAttachmentSlugs
                .Where(s => !equippedSlugs.Contains(s))
                .ToList();

            foreach (var slug in available)
            {
                var go = Instantiate(itemIconPrefab, itemGridParent.transform);
                var entry = AttachmentRegistry.GetEntry(slug);
                var drag = go.GetComponent<DraggableItem>();
                if (drag != null)
                {
                    Sprite icon = entry?.icon ?? AttachmentRegistry.GetIcon(slug);
                    drag.SetData(slug, entry?.category ?? AttachmentCategory.Scope, icon);
                    drag.attachmentCategory = entry?.category ?? AttachmentCategory.Scope;
                }
                var btn = go.GetComponent<Button>();
                if (btn != null)
                {
                    string capturedSlug = slug;
                    btn.onClick.AddListener(() => ShowAttachmentInfo(capturedSlug));
                }
            }
        }
    }

    private HashSet<string> GetEquippedWeaponSlugs()
    {
        var set = new HashSet<string>();
        if (_currentLoadout == null) return set;
        foreach (var slot in _currentLoadout.slots)
        {
            if (!string.IsNullOrEmpty(slot.weaponSlug))
                set.Add(slot.weaponSlug);
        }
        return set;
    }

    private HashSet<string> GetEquippedAttachmentSlugs()
    {
        var set = new HashSet<string>();
        if (_currentLoadout == null) return set;
        foreach (var slot in _currentLoadout.slots)
        {
            foreach (AttachmentCategory cat in Enum.GetValues(typeof(AttachmentCategory)))
            {
                var slug = slot.GetAttachmentSlug(cat);
                if (!string.IsNullOrEmpty(slug)) set.Add(slug);
            }
        }
        return set;
    }

    #region Equip / Unequip

    public void EquipWeaponToSlot(int slotIndex, string slug, WeaponCategory category)
    {
        var slot = _currentLoadout?.GetSlot(slotIndex);
        if (slot == null) return;

        // If swapping, clear old attachments
        if (!string.IsNullOrEmpty(slot.weaponSlug) && slot.weaponSlug != slug)
        {
            slot.scopeSlug = null;
            slot.muzzleSlug = null;
            slot.laserSlug = null;
            slot.gripSlug = null;
        }

        slot.weaponSlug = slug;
        RefreshWeaponSlots();
        RefreshInventoryGrid();
    }

    public void UnequipWeaponFromSlot(int slotIndex)
    {
        var slot = _currentLoadout?.GetSlot(slotIndex);
        if (slot == null) return;

        // 保护：不能卸下最后一把武器
        int equippedCount = 0;
        foreach (var s in _currentLoadout.slots)
        {
            if (!string.IsNullOrEmpty(s.weaponSlug)) equippedCount++;
        }
        if (equippedCount <= 1)
        {
            Debug.Log("[BackpackUI] 不能卸下最后一把武器！");
            return;
        }

        ClearSlot(slot);
        RefreshWeaponSlots();
        RefreshInventoryGrid();
    }

    /// <summary>移动武器时清理源槽（绕开"最后一把"保护）。</summary>
    public void ClearWeaponSlot(int slotIndex)
    {
        var slot = _currentLoadout?.GetSlot(slotIndex);
        if (slot != null) ClearSlot(slot);
    }

    private void ClearSlot(LoadoutSlot slot)
    {
        slot.weaponSlug = null;
        slot.scopeSlug = null;
        slot.muzzleSlug = null;
        slot.laserSlug = null;
        slot.gripSlug = null;
    }

    public void EquipAttachmentToSlot(int weaponSlotIndex, AttachmentCategory cat, string slug)
    {
        var slot = _currentLoadout?.GetSlot(weaponSlotIndex);
        if (slot == null) return;

        slot.SetAttachmentSlug(cat, slug);
        RefreshWeaponSlots();
        RefreshInventoryGrid();
    }

    public void UnequipAttachmentFromSlot(int weaponSlotIndex, AttachmentCategory cat)
    {
        var slot = _currentLoadout?.GetSlot(weaponSlotIndex);
        if (slot == null) return;

        slot.SetAttachmentSlug(cat, null);
        RefreshWeaponSlots();
        RefreshInventoryGrid();
    }

    #endregion

    #region Info Popups

    private void ShowWeaponInfo(string slug)
    {
        var entry = WeaponPrefabRegistry.GetEntry(slug);
        if (entry != null && weaponInfoPopup != null)
            weaponInfoPopup.Show(entry);
    }

    private void ShowAttachmentInfo(string slug)
    {
        var entry = AttachmentRegistry.GetEntry(slug);
        if (entry != null && attachmentInfoPopup != null)
            attachmentInfoPopup.Show(entry);
    }

    #endregion
}
