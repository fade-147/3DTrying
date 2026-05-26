using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// 服务端静态映射表：存储当前对局的 sideId ↔ teamId 映射。
/// 每局开始时通过 AssignRandom() 随机决定哪队在哪侧，
/// StrategyZone 通过查表确定区域归属队伍。
/// </summary>
public static class TeamSideMapping
{
    /// <summary>sideId → teamId</summary>
    public static readonly Dictionary<int, int> SideToTeam = new();
    /// <summary>teamId → sideId</summary>
    public static readonly Dictionary<int, int> TeamToSide = new();

    /// <summary>
    /// 随机分配队伍到两侧：随机决定 team0 在 side0 还是 side1。
    /// </summary>
    public static void AssignRandom()
    {
        SideToTeam.Clear();
        TeamToSide.Clear();
        int team0Side = Random.Range(0, 2); // 0 or 1
        int team1Side = 1 - team0Side;
        SideToTeam[team0Side] = 0;
        SideToTeam[team1Side] = 1;
        TeamToSide[0] = team0Side;
        TeamToSide[1] = team1Side;
    }
}
