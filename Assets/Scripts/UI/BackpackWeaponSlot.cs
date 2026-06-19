using UnityEngine;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// 单个武器装备槽（左边竖排的一栏）。
/// 包含：武器大框 + 5 个配件小框（瞄镜/枪口/镭射/握把/弹匣）。
/// </summary>
public class BackpackWeaponSlot : MonoBehaviour
{
    [Header("Slot Identity")]
    public int slotIndex; // 0=pistol, 1=primary1, 2=primary2

    [Header("Weapon")]
    public GameObject weaponBox;        // 武器 DropTarget 大框
    public Image weaponIcon;
    public Button weaponClickButton;
    public TextMeshProUGUI weaponNameText;
    public DropTarget weaponDropTarget;

    [Header("Attachment Slots")]
    public AttachmentSlotEntry[] attachmentSlots; // 4 entries (Scope, Muzzle, Laser, Grip)

    [Header("Labels")]
    public TextMeshProUGUI slotLabel;   // "手枪" / "主武器1" / "主武器2"

    private BackpackUI _backpackUI;
    private LoadoutSlot _data;

    public void Init(BackpackUI backpackUI, int index, LoadoutSlot data)
    {
        _backpackUI = backpackUI;
        slotIndex = index;
        _data = data;

        if (slotLabel != null)
        {
            slotLabel.text = index == 0 ? "手枪位" : $"主武器{index}";
        }

        // Clear old DraggableItems in weaponBox
        if (weaponBox != null)
        {
            for (int i = weaponBox.transform.childCount - 1; i >= 0; i--)
            {
                var child = weaponBox.transform.GetChild(i);
                if (child.GetComponent<DraggableItem>() != null)
                    Destroy(child.gameObject);
            }
        }

        // Weapon
        if (!string.IsNullOrEmpty(data.weaponSlug))
        {
            var entry = WeaponPrefabRegistry.GetEntry(data.weaponSlug);
            if (weaponNameText != null)
                weaponNameText.text = WeaponPrefabRegistry.GetDisplayName(data.weaponSlug);

            // 用 DraggableItem 替换静态图标（支持拖拽卸下）
            if (weaponIcon != null) weaponIcon.enabled = false;

            if (backpackUI.itemIconPrefab != null && weaponBox != null)
            {
                var itemGo = Instantiate(backpackUI.itemIconPrefab, weaponBox.transform);
                itemGo.transform.localPosition = Vector3.zero;
                var drag = itemGo.GetComponent<DraggableItem>();
                if (drag != null)
                {
                    Sprite icon = entry?.icon ?? WeaponPrefabRegistry.GetIcon(data.weaponSlug);
                    drag.SetData(data.weaponSlug, true, icon);
                    drag.slotIndex = slotIndex;
                    drag.weaponCategory = entry?.category ?? WeaponCategory.Rifle;
                    // 点击已装备武器 → 显示描述弹窗
                    string capturedSlug = data.weaponSlug;
                    drag.onClickAction = () =>
                    {
                        var e = WeaponPrefabRegistry.GetEntry(capturedSlug);
                        if (e != null) _backpackUI.weaponInfoPopup?.Show(e);
                    };
                }
            }
        }
        else
        {
            if (weaponNameText != null) weaponNameText.text = "空";
            if (weaponIcon != null) { weaponIcon.sprite = null; weaponIcon.enabled = false; }
        }

        // Click weapon to show info
        if (weaponClickButton != null)
        {
            weaponClickButton.onClick.RemoveAllListeners();
            string capturedSlug = data.weaponSlug;
            weaponClickButton.onClick.AddListener(() =>
            {
                if (!string.IsNullOrEmpty(capturedSlug))
                {
                    var entry = WeaponPrefabRegistry.GetEntry(capturedSlug);
                    if (entry != null)
                    {
                        var popup = _backpackUI.weaponInfoPopup;
                        if (popup != null) popup.Show(entry);
                    }
                }
            });
        }

        // Attachment slots — check weapon compatibility
        var weaponEntry = string.IsNullOrEmpty(data.weaponSlug) ? null : WeaponPrefabRegistry.GetEntry(data.weaponSlug);
        var unsupported = weaponEntry?.unsupportedAttachments ?? new System.Collections.Generic.List<AttachmentCategory>();

        if (attachmentSlots != null)
        {
            foreach (var attSlot in attachmentSlots)
            {
                if (attSlot == null) continue;

                if (unsupported.Contains(attSlot.category))
                {
                    attSlot.ShowLocked(_backpackUI.lockedSlotIcon);
                }
                else
                {
                    string slug = data.GetAttachmentSlug(attSlot.category);
                    attSlot.Init(_backpackUI, slotIndex, slug, attSlot.category);
                }
            }
        }
    }
}

/// <summary>
/// 单个配件小框。
/// </summary>
[System.Serializable]
public class AttachmentSlotEntry
{
    public AttachmentCategory category;
    public GameObject root;
    public Image icon;
    public TMPro.TextMeshProUGUI label; // fallback: show name when no icon
    public Button clickButton;
    public DropTarget dropTarget;

    /// <summary>此槽位是否被锁定（武器不支持该配件类别）。</summary>
    public bool isLocked { get; private set; }

    /// <summary>显示锁定状态（X 图标，不可拖入）。</summary>
    public void ShowLocked(Sprite lockedIcon)
    {
        isLocked = true;

        if (root != null)
        {
            for (int i = root.transform.childCount - 1; i >= 0; i--)
            {
                var child = root.transform.GetChild(i);
                if (child.GetComponent<DraggableItem>() != null)
                    Object.Destroy(child.gameObject);
            }
        }

        if (icon != null) { icon.sprite = lockedIcon; icon.enabled = true; }
        if (label != null) label.gameObject.SetActive(false);
        if (dropTarget != null) dropTarget.enabled = false;
    }

    public void Init(BackpackUI backpackUI, int weaponSlotIndex, string slug, AttachmentCategory cat)
    {
        isLocked = false;
        if (dropTarget != null) dropTarget.enabled = true;

        if (root == null) return;

        // Clear old DraggableItems
        for (int i = root.transform.childCount - 1; i >= 0; i--)
        {
            var child = root.transform.GetChild(i);
            if (child.GetComponent<DraggableItem>() != null)
                Object.Destroy(child.gameObject);
        }

        if (!string.IsNullOrEmpty(slug))
        {
            var entry = AttachmentRegistry.GetEntry(slug);
            Sprite sprite = entry?.icon ?? AttachmentRegistry.GetIcon(slug);

            // Hide static elements
            if (icon != null) icon.enabled = false;
            if (label != null) label.gameObject.SetActive(false);

            // 用 DraggableItem 替换（支持拖拽卸下 + 点击显示描述）
            if (backpackUI.itemIconPrefab != null)
            {
                var itemGo = Object.Instantiate(backpackUI.itemIconPrefab, root.transform);
                itemGo.transform.localPosition = Vector3.zero;
                var drag = itemGo.GetComponent<DraggableItem>();
                if (drag != null)
                {
                    drag.SetData(slug, cat, sprite);
                    drag.slotIndex = weaponSlotIndex;
                    drag.isWeapon = false;
                    // 点击已装备配件 → 显示描述弹窗
                    string capturedSlug = slug;
                    drag.onClickAction = () =>
                    {
                        var e = AttachmentRegistry.GetEntry(capturedSlug);
                        if (e != null) backpackUI.attachmentInfoPopup?.Show(e);
                    };
                }
            }
        }
        else
        {
            if (icon != null) { icon.sprite = null; icon.enabled = false; }
            if (label != null) { label.text = ""; label.gameObject.SetActive(false); }
        }

        if (clickButton != null)
        {
            clickButton.onClick.RemoveAllListeners();
            string capturedSlug = slug;
            clickButton.onClick.AddListener(() =>
            {
                if (!string.IsNullOrEmpty(capturedSlug))
                {
                    var entry = AttachmentRegistry.GetEntry(capturedSlug);
                    if (entry != null)
                    {
                        var popup = backpackUI.attachmentInfoPopup;
                        if (popup != null) popup.Show(entry);
                    }
                }
            });
        }
    }
}
