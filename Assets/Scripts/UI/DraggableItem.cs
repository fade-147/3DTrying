using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

/// <summary>
/// 可拖拽的物品图标。挂在右边背包格子和左边已装备物品上。
/// </summary>
[RequireComponent(typeof(CanvasGroup))]
public class DraggableItem : MonoBehaviour, IBeginDragHandler, IDragHandler, IEndDragHandler, IPointerClickHandler
{
    [Header("Data")]
    public string itemSlug;           // UOS slug
    public AttachmentCategory attachmentCategory; // 仅配件有效
    public WeaponCategory weaponCategory;         // 仅武器有效
    public bool isWeapon;
    public int slotIndex = -1;        // 如果在装备槽中，slot 的 index
    public int attachmentSlotIndex = -1; // 配件小框索引 (0=scope,1=muzzle,2=laser,3=grip,4=magazine)

    [Header("Visual")]
    public Image iconImage;
    public TMPro.TextMeshProUGUI nameLabel; // fallback text when no icon

    /// <summary>点击回调（由 BackpackWeaponSlot / AttachmentSlotEntry 注入）。</summary>
    public System.Action onClickAction;

    private Transform _originalParent;
    private CanvasGroup _canvasGroup;
    private Canvas _rootCanvas;
    private bool _wasDragged;

    private void Awake()
    {
        _canvasGroup = GetComponent<CanvasGroup>();
        _rootCanvas = GetComponentInParent<Canvas>();
    }

    public void SetData(string slug, bool weapon, Sprite icon)
    {
        itemSlug = slug;
        isWeapon = weapon;
        bool hasIcon = icon != null;
        if (iconImage != null) { iconImage.sprite = icon; iconImage.enabled = hasIcon; }
        if (nameLabel != null)
        {
            nameLabel.text = hasIcon ? "" : WeaponPrefabRegistry.GetDisplayName(slug);
        }
    }

    public void SetData(string slug, AttachmentCategory cat, Sprite icon)
    {
        itemSlug = slug;
        isWeapon = false;
        attachmentCategory = cat;
        bool hasIcon = icon != null;
        if (iconImage != null) { iconImage.sprite = icon; iconImage.enabled = hasIcon; }
        if (nameLabel != null)
        {
            nameLabel.text = hasIcon ? "" : AttachmentRegistry.GetDisplayName(slug);
        }
    }

    private const float DragAlpha = 0.6f;

    public void OnBeginDrag(PointerEventData eventData)
    {
        if (_rootCanvas == null) return;

        _wasDragged = false;
        _originalParent = transform.parent;
        _canvasGroup.alpha = DragAlpha;
        _canvasGroup.blocksRaycasts = false;
        transform.SetParent(_rootCanvas.transform, true); // Move to root for drag
    }

    public void OnDrag(PointerEventData eventData)
    {
        _wasDragged = true;
        if (_rootCanvas != null)
            transform.position = eventData.position;
    }

    public void OnEndDrag(PointerEventData eventData)
    {
        _canvasGroup.alpha = 1f;
        _canvasGroup.blocksRaycasts = true;

        // Check if dropped on a valid target
        var results = new System.Collections.Generic.List<RaycastResult>();
        EventSystem.current.RaycastAll(eventData, results);

        bool handled = false;
        foreach (var hit in results)
        {
            var dropTarget = hit.gameObject.GetComponent<DropTarget>();
            if (dropTarget != null && dropTarget != this)
            {
                handled = dropTarget.OnDropReceived(this);
                break;
            }
        }

        if (!handled)
        {
            // Return to original parent
            transform.SetParent(_originalParent, true);
            transform.localPosition = Vector3.zero;
        }
        else
        {
            // Drop was consumed — destroy this draggable
            Destroy(gameObject);
        }
    }

    /// <summary>重置父节点（由 DropTarget 调用）。</summary>
    public void SetParent(Transform newParent)
    {
        transform.SetParent(newParent, true);
        transform.localPosition = Vector3.zero;
        _originalParent = newParent;
    }

    public void OnPointerClick(PointerEventData eventData)
    {
        if (_wasDragged) return;
        onClickAction?.Invoke();
    }
}
