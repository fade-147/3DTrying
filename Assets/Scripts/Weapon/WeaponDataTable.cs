using System;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// 武器静态属性（射速、弹容等），用于 UI 展示。
/// 通过 ScriptableObject 在 Editor 中配置。
/// </summary>
[CreateAssetMenu(fileName = "WeaponDataTable", menuName = "Game/Weapon Data Table")]
public class WeaponDataTable : ScriptableObject
{
    public List<WeaponEntry> weapons = new();

    public WeaponEntry GetBySlug(string slug)
    {
        return weapons.Find(w => w.slug == slug);
    }

    public bool HasWeapon(string slug) => weapons.Exists(w => w.slug == slug);
}

[Serializable]
public class WeaponEntry
{
    [Tooltip("UOS 资源 slug，如 wpn_ar_01")]
    public string slug;

    [Tooltip("显示名称")]
    public string displayName;

    [Tooltip("中文描述")]
    public string description;

    [Tooltip("武器类别")]
    public WeaponCategory category;

    [Tooltip("武器 prefab（用于 Inventory 动态实例化）")]
    public GameObject prefab;

    [Tooltip("武器图标")]
    public Sprite icon;

    [Header("属性")]
    public bool isAutomatic;
    public bool isBoltAction;
    public int roundsPerMinute;
    public int magazineSize;
    public int shotCount = 1;
    public bool cycledReload;
    public float movementSpeedMultiplier = 1f;
    [Tooltip("每发子弹伤害（普通枪械用，爆炸武器走 NetworkedExplosive.MaxDamage）")]
    public float damage = 15f;

    [Tooltip("此武器不支持的配件类别（列表中的类别将显示锁定 X 图标，不可拖入）")]
    public List<AttachmentCategory> unsupportedAttachments = new();
}
