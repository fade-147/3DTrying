using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// slug → prefab 静态映射。由 WeaponDataTable 初始化。
/// </summary>
public static class WeaponPrefabRegistry
{
    private static Dictionary<string, GameObject> _prefabs = new();
    private static Dictionary<string, WeaponEntry> _entries = new();
    private static bool _initialized;

    public static void Init(WeaponDataTable table)
    {
        if (_initialized) return;
        _prefabs.Clear();
        _entries.Clear();

        if (table == null)
        {
            Debug.LogError("[WeaponPrefabRegistry] WeaponDataTable is null!");
            return;
        }

        foreach (var entry in table.weapons)
        {
            if (string.IsNullOrEmpty(entry.slug)) continue;
            _prefabs[entry.slug] = entry.prefab;
            _entries[entry.slug] = entry;
        }

        _initialized = true;
        Debug.Log($"[WeaponPrefabRegistry] Loaded {_prefabs.Count} weapons.");
    }

    public static GameObject GetPrefab(string slug)
    {
        return _prefabs.TryGetValue(slug, out var prefab) ? prefab : null;
    }

    public static WeaponEntry GetEntry(string slug)
    {
        return _entries.TryGetValue(slug, out var entry) ? entry : null;
    }

    public static bool HasWeapon(string slug) => _prefabs.ContainsKey(slug);

    /// <summary>从武器 prefab 的 Weapon 组件读取 spriteBody 作为图标。</summary>
    public static Sprite GetIcon(string slug)
    {
        var prefab = GetPrefab(slug);
        if (prefab == null) return null;
        var weapon = prefab.GetComponent<InfimaGames.LowPolyShooterPack.WeaponBehaviour>();
        return weapon?.GetSpriteBody();
    }

    /// <summary>获取所有已注册的武器 slug 列表。</summary>
    public static List<string> GetAllSlugs() => new(_prefabs.Keys);

    #region Fallback Display Names

    /// <summary>中文名后备字典（Registry 未初始化时使用）。</summary>
    private static readonly Dictionary<string, string> FallbackNames = new()
    {
        {"wpn_ar_01", "突击步枪"},
        {"wpn_ar_02", "突击步枪 02"},
        {"wpn_ar_03", "突击步枪 03"},
        {"wpn_handgun_01", "半自动手枪"},
        {"wpn_handgun_02", "紧凑手枪"},
        {"wpn_handgun_03", "大口径手枪"},
        {"wpn_handgun_04", "轻型手枪"},
        {"wpn_smg_01", "冲锋枪"},
        {"wpn_smg_02", "高速冲锋枪"},
        {"wpn_smg_03", "均衡冲锋枪"},
        {"wpn_smg_04", "大容量冲锋枪"},
        {"wpn_smg_05", "精准冲锋枪"},
        {"wpn_shotgun_01", "泵动霰弹枪"},
        {"wpn_sniper_01", "栓动狙击枪"},
        {"wpn_sniper_02", "半自动狙击枪"},
        {"wpn_sniper_03", "轻型狙击枪"},
        {"wpn_gl_01", "榴弹发射器"},
        {"wpn_rl_01", "火箭筒"},
    };

    /// <summary>获取武器显示名。优先数据表 displayName，其次后备字典，最后返回 slug。</summary>
    public static string GetDisplayName(string slug)
    {
        var entry = GetEntry(slug);
        if (entry != null && !string.IsNullOrEmpty(entry.displayName))
            return entry.displayName;
        return FallbackNames.TryGetValue(slug, out var name) ? name : slug;
    }

    #endregion
}
