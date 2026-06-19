using System.Collections;
using UnityEngine;
using UnityEngine.Events;
using Mirror;
using StarterAssets;

/// <summary>
/// 团队计分管理器（NetworkBehaviour，挂载在 GameplayScene 的独立 GameObject 上）。
/// Server 端累计击杀数，SyncVar hooks 通知所有客户端更新计分面板。
/// 达 20 分时触发 GameOver，5 秒后全员返回大厅。
/// </summary>
public class TeamScoreManager : NetworkBehaviour
{
    public static TeamScoreManager Instance;

    public const int ScoreToWin = 20;
    private const float GameOverDelay = 8f;
    private const float SettlementCountdown = 8f;

    /// <summary>结算面板打开时为 true，用于禁止玩家输入</summary>
    public static bool SettlementIsOpen { get; private set; }

    [SyncVar(hook = nameof(OnRedScoreChanged))]
    public int redScore;

    [SyncVar(hook = nameof(OnBlueScoreChanged))]
    public int blueScore;

    [SyncVar]
    private bool _isGameOver;

    [SyncVar]
    private int _finalRedScore;

    [SyncVar]
    private int _finalBlueScore;

    [SyncVar]
    private int _winningTeam;

    /// <summary>(redScore, blueScore) — 分数变化时触发</summary>
    public UnityEvent<int, int> OnScoreChanged = new UnityEvent<int, int>();

    /// <summary>(winningTeam, redScore, blueScore) — 游戏结束时触发</summary>
    public UnityEvent<int, int, int> OnGameOverEvent = new UnityEvent<int, int, int>();

    /// <summary>(settlementJson, countdownSeconds) — 结算数据到达时触发</summary>
    public UnityEvent<string, float> OnSettlementReceived = new UnityEvent<string, float>();

    /// <summary>(killerName, victimName, killerTeam, victimTeam) — 击杀播报到达时触发</summary>
    public event System.Action<string, string, int, int> OnKillEntryReceived;

    private void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }
        Instance = this;
        SettlementIsOpen = false;
    }

    public override void OnStartServer()
    {
        base.OnStartServer();
        redScore = 0;
        blueScore = 0;
        _isGameOver = false;
    }

    /// <summary>
    /// [Server] 为指定队伍增加一次击杀。仅 Server 端调用。
    /// </summary>
    [Server]
    public void AddKill(int teamId)
    {
        if (_isGameOver) return;

        switch (teamId)
        {
            case 0:
                redScore++;
                break;
            case 1:
                blueScore++;
                break;
            default:
                return;
        }

        CheckWinCondition();
    }

    [Server]
    private void CheckWinCondition()
    {
        if (_isGameOver) return;

        if (redScore >= ScoreToWin)
        {
            _winningTeam = 0;
            _isGameOver = true;
            _finalRedScore = redScore;
            _finalBlueScore = blueScore;
            TriggerGameOver(_winningTeam, _finalRedScore, _finalBlueScore);
        }
        else if (blueScore >= ScoreToWin)
        {
            _winningTeam = 1;
            _isGameOver = true;
            _finalRedScore = redScore;
            _finalBlueScore = blueScore;
            TriggerGameOver(_winningTeam, _finalRedScore, _finalBlueScore);
        }
    }

    /// <summary>
    /// [Server] Forces game over — losingTeam surrenders, the other team wins.
    /// Called by SurrenderVoteManager when surrender vote passes.
    /// </summary>
    [Server]
    public void ForceGameOver(int losingTeam)
    {
        if (_isGameOver) return;

        int winningTeam = losingTeam == 0 ? 1 : 0;
        _winningTeam = winningTeam;
        _isGameOver = true;
        _finalRedScore = redScore;
        _finalBlueScore = blueScore;

        // Ensure all connected human players appear in settlement
        var ps = PlayerStatsManager.Instance;
        if (ps != null)
        {
            foreach (var kvp in NetworkServer.connections)
            {
                var conn = kvp.Value;
                if (conn == null || !conn.isReady) continue;
                var tpc = conn.identity?.GetComponent<ThirdPersonController>();
                if (tpc != null)
                {
                    ps.RecordPlayerTeam(conn.connectionId, tpc.teamId);
                    ps.RecordPlayerName(conn, $"Player {conn.connectionId}");
                }
            }
        }

        TriggerGameOver(_winningTeam, _finalRedScore, _finalBlueScore);
    }

    /// <summary>
    /// [Server] Common game-over trigger: RPC + settlement + return-to-lobby.
    /// </summary>
    [Server]
    private void TriggerGameOver(int winningTeam, int redFinal, int blueFinal)
    {
        // 1. Win/lose panel (works reliably — TeamScoreManager is a scene NB)
        RpcOnGameOver(winningTeam, redFinal, blueFinal);

        // 2. Settlement via PlayerStatsManager (primary path)
        var ps = PlayerStatsManager.Instance;
        ps?.NotifyPlayersSessionKills();

        // 3. Build settlement data and send via BOTH paths for reliability
        if (ps != null)
        {
            SettlementData data = ps.BuildSettlementData(winningTeam, redFinal, blueFinal);
            string json = JsonUtility.ToJson(data);

            // Primary: PlayerStatsManager RPC
            ps.RpcShowSettlement(json, SettlementCountdown);

            // Fallback: TeamScoreManager RPC (scene NB, guaranteed to reach all clients)
            RpcShowSettlementFallback(json, SettlementCountdown);
        }

        StartCoroutine(DelayedReturnToLobby());
    }

    [Server]
    private IEnumerator DelayedReturnToLobby()
    {
        yield return new WaitForSeconds(GameOverDelay);

        var mgr = MyNetworkRoomManager.instance;
        if (mgr != null)
        {
            mgr.ReturnToLobby();
        }
    }

    #region Client RPCs

    /// <summary>
    /// [Server] 广播击杀播报到所有客户端。
    /// 挂在 TeamScoreManager 而非动态创建的 NB 上，确保远端客户端可靠接收。
    /// </summary>
    [ClientRpc]
    public void RpcAddKillEntry(string killerName, string victimName, int killerTeam, int victimTeam)
    {
        OnKillEntryReceived?.Invoke(killerName, victimName, killerTeam, victimTeam);
    }

    [ClientRpc]
    private void RpcOnGameOver(int winningTeam, int redFinal, int blueFinal)
    {
        _winningTeam = winningTeam;
        _finalRedScore = redFinal;
        _finalBlueScore = blueFinal;
        _isGameOver = true;
        SettlementIsOpen = true;
        OnGameOverEvent?.Invoke(winningTeam, redFinal, blueFinal);
    }

    /// <summary>
    /// Fallback settlement RPC via TeamScoreManager (scene NetworkBehaviour).
    /// Ensures clients always receive settlement data even if PlayerStatsManager
    /// (dynamically-spawned NB) fails to deliver.
    /// </summary>
    [ClientRpc]
    private void RpcShowSettlementFallback(string settlementJson, float countdownSeconds)
    {
        SettlementIsOpen = true;
        OnSettlementReceived?.Invoke(settlementJson, countdownSeconds);
    }

    #endregion

    public override void OnStartClient()
    {
        base.OnStartClient();
        if (_isGameOver)
        {
            SettlementIsOpen = true;
            OnGameOverEvent?.Invoke(_winningTeam, _finalRedScore, _finalBlueScore);
        }
    }

    private void OnRedScoreChanged(int oldValue, int newValue)
    {
        OnScoreChanged?.Invoke(newValue, blueScore);
    }

    private void OnBlueScoreChanged(int oldValue, int newValue)
    {
        OnScoreChanged?.Invoke(redScore, newValue);
    }
}
