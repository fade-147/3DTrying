using UnityEngine;
using UnityEngine.EventSystems;

/// <summary>
/// 拖拽放置目标。挂在装备槽大框、配件小框、背包格子上。
/// </summary>
public class DropTarget : MonoBehaviour, IDropHandler
{
    public enum TargetType
    {
        WeaponSlot,       // 左边武器大框（接受武器拖入）
        AttachmentSlot,   // 左边配件小框（接受对应类型配件拖入）
        InventoryGrid,    // 右边背包格子（接受卸下的物品）
    }

    [Header("Settings")]
    public TargetType targetType;

    [Tooltip("武器槽 index（0=pistol, 1/2=primary）")]
    public int weaponSlotIndex = -1;

    [Tooltip("配件小框类型")]
    public AttachmentCategory acceptedAttachmentCategory;

    [Header("References")]
    public BackpackUI backpackUI;

    public bool OnDropReceived(DraggableItem draggedItem)
    {
        if (draggedItem == null) return false;
        if (!enabled) return false; // 锁定槽位（如火箭筒不支持瞄镜）

        switch (targetType)
        {
            case TargetType.WeaponSlot:
                return HandleWeaponSlotDrop(draggedItem);

            case TargetType.AttachmentSlot:
                return HandleAttachmentSlotDrop(draggedItem);

            case TargetType.InventoryGrid:
                return HandleInventoryDrop(draggedItem);

            default:
                return false;
        }
    }

    private bool HandleWeaponSlotDrop(DraggableItem dragged)
    {
        if (!dragged.isWeapon) return false;

        // 检查武器类别兼容性：slot 0 只能放手枪
        if (weaponSlotIndex == 0 && dragged.weaponCategory != WeaponCategory.Handgun)
        {
            Debug.Log("[DropTarget] Slot 0 only accepts Handguns!");
            return false;
        }
        if (weaponSlotIndex != 0 && dragged.weaponCategory == WeaponCategory.Handgun)
        {
            Debug.Log("[DropTarget] Pistol must go in slot 0!");
            return false;
        }

        if (backpackUI != null)
        {
            // 如果从其他装备槽拖过来，先清源槽（绕开"最后一把"保护）
            if (dragged.slotIndex >= 0 && dragged.slotIndex != weaponSlotIndex)
            {
                backpackUI.ClearWeaponSlot(dragged.slotIndex);
            }

            backpackUI.EquipWeaponToSlot(weaponSlotIndex, dragged.itemSlug, dragged.weaponCategory);
            return true;
        }

        return false;
    }

    private bool HandleAttachmentSlotDrop(DraggableItem dragged)
    {
        if (dragged.isWeapon) return false;
        if (dragged.attachmentCategory != acceptedAttachmentCategory) return false;

        if (backpackUI != null)
        {
            // 如果从其他装备槽拖过来，先清源槽
            if (dragged.slotIndex >= 0 && dragged.slotIndex != weaponSlotIndex)
            {
                backpackUI.UnequipAttachmentFromSlot(dragged.slotIndex, dragged.attachmentCategory);
            }

            backpackUI.EquipAttachmentToSlot(
                weaponSlotIndex,
                acceptedAttachmentCategory,
                dragged.itemSlug);
            return true;
        }

        return false;
    }

    private bool HandleInventoryDrop(DraggableItem dragged)
    {
        // 只有从装备槽拖过来的才卸下（slotIndex >= 0）
        if (dragged.slotIndex < 0) return false;

        if (backpackUI != null)
        {
            if (dragged.isWeapon)
                backpackUI.UnequipWeaponFromSlot(dragged.slotIndex);
            else
                backpackUI.UnequipAttachmentFromSlot(dragged.slotIndex, dragged.attachmentCategory);
            return true;
        }

        return false;
    }

    public void OnDrop(PointerEventData eventData)
    {
        // Handled by DraggableItem.OnEndDrag via RaycastAll
    }
}
