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

    /// <summary>connectionId → 玩家显示名</summary>
    private readonly Dictionary<int, string> _playerNames = new Dictionary<int, string>();

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
        _playerNames.Clear();
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
    /// [Server] 查询某玩家本局击杀数。
    /// </summary>
    public int GetSessionKills(NetworkConnectionToClient conn)
    {
        if (conn == null) return 0;
        return _sessionKills.TryGetValue(conn.connectionId, out int kills) ? kills : 0;
    }

    /// <summary>
    /// [Server] 获取所有玩家本局击杀数据（供结算 UI 使用）。
    /// </summary>
    public IEnumerable<(int connectionId, string playerName, int kills)> GetAllPlayerStats()
    {
        foreach (var kv in _sessionKills)
        {
            string name = _playerNames.TryGetValue(kv.Key, out string n) ? n : $"Player {kv.Key}";
            yield return (kv.Key, name, kv.Value);
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
}
