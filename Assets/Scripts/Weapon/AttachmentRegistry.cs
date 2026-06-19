using System.Collections.Generic;
using System.Linq;
using UnityEngine;

/// <summary>
/// 配件 slug → AttachmentEntry 静态映射。由 AttachmentDataTable 初始化。
/// </summary>
public static class AttachmentRegistry
{
    private static Dictionary<string, AttachmentEntry> _entries = new();
    private static bool _initialized;

    public static void Init(AttachmentDataTable table)
    {
        if (_initialized) return;
        _entries.Clear();

        if (table == null)
        {
            Debug.LogError("[AttachmentRegistry] AttachmentDataTable is null!");
            return;
        }

        foreach (var entry in table.attachments)
        {
            if (string.IsNullOrEmpty(entry.slug)) continue;
            _entries[entry.slug] = entry;
        }

        _initialized = true;
        Debug.Log($"[AttachmentRegistry] Loaded {_entries.Count} attachments.");
    }

    public static AttachmentEntry GetEntry(string slug)
    {
        return _entries.TryGetValue(slug, out var entry) ? entry : null;
    }

    public static bool HasAttachment(string slug) => _entries.ContainsKey(slug);

    /// <summary>从配件 prefab 读取 GetSprite() 作为图标。</summary>
    public static Sprite GetIcon(string slug)
    {
        var entry = GetEntry(slug);
        if (entry?.prefab == null) return null;

        return entry.category switch
        {
            AttachmentCategory.Scope => entry.prefab.GetComponent<InfimaGames.LowPolyShooterPack.ScopeBehaviour>()?.GetSprite(),
            AttachmentCategory.Muzzle => entry.prefab.GetComponent<InfimaGames.LowPolyShooterPack.MuzzleBehaviour>()?.GetSprite(),
            AttachmentCategory.Laser => entry.prefab.GetComponent<InfimaGames.LowPolyShooterPack.LaserBehaviour>()?.GetSprite(),
            AttachmentCategory.Grip => entry.prefab.GetComponent<InfimaGames.LowPolyShooterPack.GripBehaviour>()?.GetSprite(),
            _ => null
        };
    }

    public static List<AttachmentEntry> GetByCategory(AttachmentCategory cat)
    {
        return _entries.Values.Where(e => e.category == cat).ToList();
    }

    public static List<string> GetAllSlugs() => new(_entries.Keys);

    #region Fallback Display Names

    /// <summary>中文名后备字典（Registry 未初始化时使用）。</summary>
    private static readonly Dictionary<string, string> FallbackNames = new()
    {
        {"att_scope_01", "铁瞄"}, {"att_scope_02", "红点"}, {"att_scope_03", "全息"},
        {"att_scope_04", "4倍镜"}, {"att_scope_05", "6倍镜"}, {"att_scope_06", "热成像"},
        {"att_scope_07", "夜视"}, {"att_scope_08", "8倍镜"},
        {"att_muzzle_01", "消焰器"}, {"att_muzzle_02", "消音器"}, {"att_muzzle_03", "战术消音"},
        {"att_muzzle_04", "高级消音"},
        {"att_laser_01", "镭射"}, {"att_laser_02", "镭射手电"},
        {"att_grip_01", "前握把"}, {"att_grip_02", "双脚架"}, {"att_grip_03", "重双脚架"},
    };

    /// <summary>获取配件显示名。优先数据表 displayName，其次后备字典，最后返回 slug。</summary>
    public static string GetDisplayName(string slug)
    {
        var entry = GetEntry(slug);
        if (entry != null && !string.IsNullOrEmpty(entry.displayName))
            return entry.displayName;
        return FallbackNames.TryGetValue(slug, out var name) ? name : slug;
    }

    #endregion
}
