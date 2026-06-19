using System;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// 一个武器槽的完整配置（武器 + 5 个配件位）。
/// </summary>
[Serializable]
public class LoadoutSlot
{
    [Tooltip("0 = 手枪位, 1/2 = 主武器位")]
    public int slotIndex;

    [Tooltip("武器 slug，null 表示空槽")]
    public string weaponSlug;

    [Tooltip("瞄准镜 slug")]
    public string scopeSlug;
    [Tooltip("枪口 slug")]
    public string muzzleSlug;
    [Tooltip("镭射 slug")]
    public string laserSlug;
    [Tooltip("握把 slug")]
    public string gripSlug;

    public bool IsEmpty => string.IsNullOrEmpty(weaponSlug);
    public bool IsPistolSlot => slotIndex == 0;

    public bool HasAttachment(AttachmentCategory cat)
    {
        return cat switch
        {
            AttachmentCategory.Scope => !string.IsNullOrEmpty(scopeSlug),
            AttachmentCategory.Muzzle => !string.IsNullOrEmpty(muzzleSlug),
            AttachmentCategory.Laser => !string.IsNullOrEmpty(laserSlug),
            AttachmentCategory.Grip => !string.IsNullOrEmpty(gripSlug),
            _ => false
        };
    }

    public string GetAttachmentSlug(AttachmentCategory cat)
    {
        return cat switch
        {
            AttachmentCategory.Scope => scopeSlug,
            AttachmentCategory.Muzzle => muzzleSlug,
            AttachmentCategory.Laser => laserSlug,
            AttachmentCategory.Grip => gripSlug,
            _ => null
        };
    }

    public void SetAttachmentSlug(AttachmentCategory cat, string slug)
    {
        switch (cat)
        {
            case AttachmentCategory.Scope: scopeSlug = slug; break;
            case AttachmentCategory.Muzzle: muzzleSlug = slug; break;
            case AttachmentCategory.Laser: laserSlug = slug; break;
            case AttachmentCategory.Grip: gripSlug = slug; break;
            default:
                throw new ArgumentOutOfRangeException(nameof(cat), cat, $"Unknown attachment category: {cat}");
        }
    }
}

/// <summary>
/// 玩家完整 Loadout（3 个武器槽）。
/// </summary>
[Serializable]
public class LoadoutData
{
    public List<LoadoutSlot> slots = new(3)
    {
        new LoadoutSlot { slotIndex = 0 },
        new LoadoutSlot { slotIndex = 1 },
        new LoadoutSlot { slotIndex = 2 }
    };

    /// <summary>获取已装备武器的 slot 列表（按 slotIndex 排序）。</summary>
    public List<LoadoutSlot> GetEquippedWeapons()
    {
        var result = new List<LoadoutSlot>();
        for (int i = 0; i < slots.Count; i++)
        {
            if (!slots[i].IsEmpty)
                result.Add(slots[i]);
        }
        result.Sort((a, b) => a.slotIndex.CompareTo(b.slotIndex));
        return result;
    }

    /// <summary>获取某个槽位。</summary>
    public LoadoutSlot GetSlot(int index)
    {
        return slots.Find(s => s.slotIndex == index);
    }

    /// <summary>当前玩家的 Loadout 静态缓存（在 StartScene 设置，GameScene Character.Awake 读取）。</summary>
    public static LoadoutData CurrentLoadout { get; set; }

    /// <summary>将 loadout 序列化为 JSON（存 UOS customData）。</summary>
    public string ToJson()
    {
        return JsonUtility.ToJson(this);
    }

    /// <summary>从 JSON 反序列化。</summary>
    public static LoadoutData FromJson(string json)
    {
        if (string.IsNullOrEmpty(json)) return new LoadoutData();
        return JsonUtility.FromJson<LoadoutData>(json) ?? new LoadoutData();
    }
}
