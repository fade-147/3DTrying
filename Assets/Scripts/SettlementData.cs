using System;
using System.Collections.Generic;

/// <summary>
/// 结算数据，由服务端构建后 JSON 序列化发给所有客户端。
/// </summary>
[Serializable]
public class SettlementData
{
    public int winningTeam;
    public int redScore;
    public int blueScore;
    public List<SettlementPlayerEntry> entries = new List<SettlementPlayerEntry>();
}

/// <summary>
/// 结算中单个玩家/Bot 的击杀/死亡条目。
/// </summary>
[Serializable]
public class SettlementPlayerEntry
{
    public string playerName;
    public int kills;
    public int deaths;
    public int teamId;   // 0=红方, 1=蓝方
    public bool isBot;
}
