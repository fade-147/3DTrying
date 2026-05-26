using System.Collections.Generic;
using UnityEngine;

public enum ZoneType
{
    Frontline,  // 前线 — 敌方半场方向，团队推进目标
    Defend,     // 防守 — 己方半场，优先分配 Bot 驻守
    Flank,      // 侧翼 — 侧路包抄
    Roam        // 游走 — 中场开阔区，自由巡逻
}

public enum SideAssignment
{
    Side0,  // 地图一侧（开局时随机分配给 Red 或 Blue 队）
    Side1,  // 地图另一侧 
    Both    // 双方通用
}

public class StrategyZone : MonoBehaviour
{
    [Header("Type")]
    public ZoneType zoneType = ZoneType.Roam;
    public SideAssignment sideAssignment = SideAssignment.Both;

    [Header("Parameters")]
    public float radius = 5f;
    public float priority = 1f;
    public float stayDuration = 3f;

    public Vector3 WorldPosition => transform.position;

    public static List<StrategyZone> AllZones { get; private set; } = new();

    private void OnEnable() => AllZones.Add(this);
    private void OnDisable() => AllZones.Remove(this);

    /// <summary>
    /// 通过 TeamSideMapping 动态查表判断 zone 是否属于指定队伍。
    /// Side0 → 查 SideToTeam[0] 获取当前局在该侧的队伍, Side1 → 查 SideToTeam[1]。
    /// 无映射时回退为 side=teamId（直等）。
    /// </summary>
    public bool IsValidForTeam(int teamId)
    {
        if (sideAssignment == SideAssignment.Both) return true;
        int expectedSide = sideAssignment == SideAssignment.Side0 ? 0 : 1;
        if (!TeamSideMapping.SideToTeam.TryGetValue(expectedSide, out int expectedTeam))
            expectedTeam = expectedSide; // 回退：无映射时 side=teamId
        return teamId == expectedTeam;
    }

    private void OnDrawGizmos()
    {
        Color c = zoneType switch
        {
            ZoneType.Frontline => Color.red,
            ZoneType.Defend => Color.blue,
            ZoneType.Flank => Color.yellow,
            ZoneType.Roam => Color.green,
            _ => Color.gray,
        };

        Gizmos.color = new Color(c.r, c.g, c.b, 0.3f);
        Gizmos.DrawSphere(transform.position, radius);
        Gizmos.color = c;
        Gizmos.DrawWireSphere(transform.position, radius);

#if UNITY_EDITOR
        Vector3 labelPos = transform.position + Vector3.up * (radius + 1f);
        UnityEditor.Handles.Label(labelPos, $"{zoneType}\nP:{priority}");
#endif
    }
}
