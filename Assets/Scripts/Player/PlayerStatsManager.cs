using System.Collections.Generic;
using UnityEngine;
using Mirror;

/// <summary>
/// 服务端权威的每玩家击杀统计。
/// 在 MyNetworkRoomManager.OnStartServer 时动态创建。
/// 游戏结束时通过 TargetRpc 通知各客户端提交 UOS 排行榜。
/// 注意：此文件在 HotUpdate.asmdef 中，不能直接引用 Boot/Assembly-CSharp 的类。
/// </summary>
public class PlayerStatsManager : NetworkBehaviour
{
    public static PlayerStatsManager Instance { get; private set; }

    /// <summary>connectionId → 本局击杀数</summary>
    private readonly Dictionary<int, int> _sessionKills = new Dictionary<int, int>();

    /// <summary>connectionId → 本局死亡数</summary>
    private readonly Dictionary<int, int> _sessionDeaths = new Dictionary<int, int>();

    /// <summary>connectionId → 玩家显示名</summary>
    private readonly Dictionary<int, string> _playerNames = new Dictionary<int, string>();

    /// <summary>connectionId → 队伍 ID (0=红, 1=蓝)</summary>
    private readonly Dictionary<int, int> _playerTeams = new Dictionary<int, int>();

    /// <summary>Bot 显示名 → 击杀数</summary>
    private readonly Dictionary<string, int> _botKills = new Dictionary<string, int>();

    /// <summary>Bot 显示名 → 死亡数</summary>
    private readonly Dictionary<string, int> _botDeaths = new Dictionary<string, int>();

    /// <summary>Bot 显示名 → 队伍 ID</summary>
    private readonly Dictionary<string, int> _botTeams = new Dictionary<string, int>();

    /// <summary>客户端结算事件 (SettlementData, countdownSeconds)</summary>
    public event System.Action<SettlementData, float> OnSettlementReceived;

    private void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }
        Instance = this;
    }

    public override void OnStartServer()
    {
        base.OnStartServer();
        _sessionKills.Clear();
        _sessionDeaths.Clear();
        _playerNames.Clear();
        _playerTeams.Clear();
        _botKills.Clear();
        _botDeaths.Clear();
        _botTeams.Clear();
    }

    /// <summary>
    /// [Server] 击杀者计数 +1。必须从 Server 端调用。
    /// </summary>
    [Server]
    public void AddKill(NetworkConnectionToClient conn)
    {
        if (conn == null) return;

        int connId = conn.connectionId;
        if (_sessionKills.ContainsKey(connId))
            _sessionKills[connId]++;
        else
            _sessionKills[connId] = 1;

        // 首次击杀时记录名字
        if (!_playerNames.ContainsKey(connId))
        {
            _playerNames[connId] = $"Player {connId}";
        }
    }

    /// <summary>
    /// [Server] 记录玩家名字（在 AddPlayer 时调用）。
    /// </summary>
    [Server]
    public void RecordPlayerName(NetworkConnectionToClient conn, string name)
    {
        if (conn == null) return;
        _playerNames[conn.connectionId] = name;
    }

    /// <summary>
    /// [Server] 被击杀者死亡数 +1。必须从 Server 端调用。
    /// </summary>
    [Server]
    public void AddDeath(NetworkConnectionToClient conn)
    {
        if (conn == null) return;

        int connId = conn.connectionId;
        if (_sessionDeaths.ContainsKey(connId))
            _sessionDeaths[connId]++;
        else
            _sessionDeaths[connId] = 1;
    }

    /// <summary>
    /// [Server] 记录 Bot 基本信息（首次出现时调用，可重复调用覆盖队伍）。
    /// </summary>
    [Server]
    public void RecordBotInfo(string botName, int teamId)
    {
        if (string.IsNullOrEmpty(botName)) return;
        _botTeams[botName] = teamId;
    }

    /// <summary>
    /// [Server] Bot 击杀数 +1。以 displayName 为 key（跨复活稳定）。
    /// </summary>
    [Server]
    public void AddBotKill(string botName)
    {
        if (string.IsNullOrEmpty(botName)) return;
        if (_botKills.ContainsKey(botName))
            _botKills[botName]++;
        else
            _botKills[botName] = 1;
    }

    /// <summary>
    /// [Server] Bot 死亡数 +1。
    /// </summary>
    [Server]
    public void AddBotDeath(string botName)
    {
        if (string.IsNullOrEmpty(botName)) return;
        if (_botDeaths.ContainsKey(botName))
            _botDeaths[botName]++;
        else
            _botDeaths[botName] = 1;
    }

    /// <summary>
    /// [Server] 记录人类玩家队伍（在 AddPlayer 或首次击杀时调用）。
    /// </summary>
    [Server]
    public void RecordPlayerTeam(int connId, int teamId)
    {
        _playerTeams[connId] = teamId;
    }

    /// <summary>
    /// [Server] 查询某玩家本局击杀数。
    /// </summary>
    public int GetSessionKills(NetworkConnectionToClient conn)
    {
        if (conn == null) return 0;
        return _sessionKills.TryGetValue(conn.connectionId, out int kills) ? kills : 0;
    }

    /// <summary>
    /// [Server] 查询某玩家本局死亡数。
    /// </summary>
    public int GetSessionDeaths(NetworkConnectionToClient conn)
    {
        if (conn == null) return 0;
        return _sessionDeaths.TryGetValue(conn.connectionId, out int deaths) ? deaths : 0;
    }

    /// <summary>
    /// [Server] 获取所有玩家本局击杀/死亡数据（供结算 UI 使用）。
    /// </summary>
    public IEnumerable<(int connectionId, string playerName, int kills, int deaths)> GetAllPlayerStats()
    {
        // 收集所有有击杀或死亡记录的 connectionId
        var allIds = new HashSet<int>();
        foreach (var kv in _sessionKills) allIds.Add(kv.Key);
        foreach (var kv in _sessionDeaths) allIds.Add(kv.Key);

        foreach (int id in allIds)
        {
            string name = _playerNames.TryGetValue(id, out string n) ? n : $"Player {id}";
            int kills = _sessionKills.TryGetValue(id, out int k) ? k : 0;
            int deaths = _sessionDeaths.TryGetValue(id, out int d) ? d : 0;
            yield return (id, name, kills, deaths);
        }
    }

    /// <summary>
    /// [Server] 游戏结束时调用：通知每个在线玩家接收本局击杀数，触发 UOS 提交。
    /// </summary>
    [Server]
    public void NotifyPlayersSessionKills()
    {
        foreach (var conn in NetworkServer.connections.Values)
        {
            if (conn == null || !conn.isReady) continue;

            int connId = conn.connectionId;
            int kills = _sessionKills.TryGetValue(connId, out int k) ? k : 0;

            TargetReceiveSessionKills(conn, kills);
        }
    }

    /// <summary>
    /// [TargetRpc] 服务端→客户端：通知本局击杀数，客户端负责提交 UOS。
    /// </summary>
    [TargetRpc]
    public void TargetReceiveSessionKills(NetworkConnection target, int sessionKills)
    {
        if (sessionKills <= 0) return;

        Debug.Log($"[PlayerStatsManager] 本局击杀: {sessionKills}，正在提交 UOS 排行榜...");

        if (UOSLeaderboard.Instance != null)
        {
            UOSLeaderboard.Instance.SubmitKillScore(sessionKills);
        }
        else
        {
            Debug.LogWarning("[PlayerStatsManager] UOSLeaderboard.Instance 为空，无法提交分数");
        }
    }

    /// <summary>
    /// [Server] 构建结算数据，聚合人类玩家和 Bot 的击杀/死亡。
    /// </summary>
    [Server]
    public SettlementData BuildSettlementData(int winningTeam, int redScore, int blueScore)
    {
        var data = new SettlementData
        {
            winningTeam = winningTeam,
            redScore = redScore,
            blueScore = blueScore
        };

        // 人类玩家：收集所有出现过的 connectionId
        var allHumanIds = new HashSet<int>();
        foreach (var kv in _sessionKills) allHumanIds.Add(kv.Key);
        foreach (var kv in _sessionDeaths) allHumanIds.Add(kv.Key);
        foreach (var kv in _playerTeams) allHumanIds.Add(kv.Key);

        foreach (int connId in allHumanIds)
        {
            data.entries.Add(new SettlementPlayerEntry
            {
                playerName = _playerNames.TryGetValue(connId, out string n) ? n : $"Player {connId}",
                kills = _sessionKills.TryGetValue(connId, out int k) ? k : 0,
                deaths = _sessionDeaths.TryGetValue(connId, out int d) ? d : 0,
                teamId = _playerTeams.TryGetValue(connId, out int t) ? t : -1,
                isBot = false
            });
        }

        // Bot：以 displayName 遍历
        foreach (var kv in _botTeams)
        {
            string name = kv.Key;
            data.entries.Add(new SettlementPlayerEntry
            {
                playerName = name,
                kills = _botKills.TryGetValue(name, out int k) ? k : 0,
                deaths = _botDeaths.TryGetValue(name, out int d) ? d : 0,
                teamId = kv.Value,
                isBot = true
            });
        }

        return data;
    }

    /// <summary>
    /// [Server] 构建结算数据并广播到所有客户端。
    /// </summary>
    [Server]
    public void SendSettlementToAll(int winningTeam, int redScore, int blueScore, float countdownSeconds)
    {
        SettlementData data = BuildSettlementData(winningTeam, redScore, blueScore);
        string json = JsonUtility.ToJson(data);
        RpcShowSettlement(json, countdownSeconds);
    }

    /// <summary>
    /// [ClientRpc] 服务端下发结算数据到所有客户端，触发 SettlementUI 显示。
    /// </summary>
    [ClientRpc]
    public void RpcShowSettlement(string settlementJson, float countdownSeconds)
    {
        InvokeSettlementReceived(settlementJson, countdownSeconds);
    }

    /// <summary>
    /// Allows TeamScoreManager fallback RPC to trigger settlement locally.
    /// </summary>
    public void InvokeSettlementReceived(string settlementJson, float countdownSeconds)
    {
        SettlementData data = JsonUtility.FromJson<SettlementData>(settlementJson);
        OnSettlementReceived?.Invoke(data, countdownSeconds);
    }
}
