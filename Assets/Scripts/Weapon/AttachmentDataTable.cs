using System;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// 配件静态属性（名称、效果数值、图标），用于 UI 展示。
/// </summary>
[CreateAssetMenu(fileName = "AttachmentDataTable", menuName = "Game/Attachment Data Table")]
public class AttachmentDataTable : ScriptableObject
{
    public List<AttachmentEntry> attachments = new();

    public AttachmentEntry GetBySlug(string slug)
    {
        return attachments.Find(a => a.slug == slug);
    }

    public bool HasAttachment(string slug) => attachments.Exists(a => a.slug == slug);
}

[Serializable]
public class AttachmentEntry
{
    [Tooltip("UOS 资源 slug，如 att_scope_02")]
    public string slug;

    [Tooltip("显示名称")]
    public string displayName;

    [Tooltip("中文描述")]
    public string description;

    [Tooltip("配件类别")]
    public AttachmentCategory category;

    [Tooltip("配件图标")]
    public Sprite icon;

    [Tooltip("配件 prefab（用于自动读取图标，可选）")]
    public GameObject prefab;

    [Header("效果数值")]
    [Tooltip("后坐力减少百分比（0~1）")]
    public float recoilReduction;

    [Tooltip("散布减少百分比（0~1）")]
    public float spreadReduction;

    [Tooltip("摇摆减少百分比（0~1）")]
    public float swayReduction;

    [Tooltip("是否消音")]
    public bool suppressSound;

    [Tooltip("弹药容量倍率（弹匣类>1.0，其他=1.0）")]
    public float ammoCapacityMultiplier = 1f;

    [Tooltip("腰射散布减少百分比（0~1）")]
    public float hipfireSpreadReduction;
}
