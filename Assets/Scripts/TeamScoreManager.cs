using System.Collections;
using UnityEngine;
using UnityEngine.Events;
using Mirror;

/// <summary>
/// 团队计分管理器（NetworkBehaviour，挂载在 GameplayScene 的独立 GameObject 上）。
/// Server 端累计击杀数，SyncVar hooks 通知所有客户端更新计分面板。
/// 达 20 分时触发 GameOver，5 秒后全员返回大厅。
/// </summary>
public class TeamScoreManager : NetworkBehaviour
{
    public static TeamScoreManager Instance;

    public const int ScoreToWin = 20;
    private const float GameOverDelay = 5f;

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
            RpcOnGameOver(_winningTeam, _finalRedScore, _finalBlueScore);
            StartCoroutine(DelayedReturnToLobby());
        }
        else if (blueScore >= ScoreToWin)
        {
            _winningTeam = 1;
            _isGameOver = true;
            _finalRedScore = redScore;
            _finalBlueScore = blueScore;
            RpcOnGameOver(_winningTeam, _finalRedScore, _finalBlueScore);
            StartCoroutine(DelayedReturnToLobby());
        }
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

    [ClientRpc]
    private void RpcOnGameOver(int winningTeam, int redFinal, int blueFinal)
    {
        _winningTeam = winningTeam;
        _finalRedScore = redFinal;
        _finalBlueScore = blueFinal;
        _isGameOver = true;
        OnGameOverEvent?.Invoke(winningTeam, redFinal, blueFinal);
    }

    public override void OnStartClient()
    {
        base.OnStartClient();

        // 中途加入时，如果游戏已结束则同步 GameOver 面板
        if (_isGameOver)
        {
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
