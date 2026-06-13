using UnityEngine;
using UnityEngine.UI;
using TMPro;
using InfimaGames.LowPolyShooterPack;

/// <summary>
/// GameplayScene Canvas 上的 UI 管理器，负责计分面板和胜负判定显示。
/// 通过 ServiceLocator 注册为 IGameUIManager，场景对象可直接 Inspector 拖拽 UI 引用。
/// </summary>
public class GameUIManager : MonoBehaviour, IGameUIManager
{
    [Header("Score Fill Images")]
    [SerializeField]
    private Image ownTeamScoreFill;

    [SerializeField]
    private Image enemyTeamScoreFill;

    [Header("Win/Lose Panels")]
    [SerializeField]
    private GameObject winPanel;

    [SerializeField]
    private GameObject losePanel;

    [Header("Optional Text")]
    [SerializeField]
    private TMP_Text ownScoreText;

    [SerializeField]
    private TMP_Text enemyScoreText;

    [SerializeField]
    private TMP_Text countdownText;

    private int _localTeamId = -1;
    private bool _gameOverShown;
    private bool _eventsRegistered;

    private void Awake()
    {
        var sl = ServiceLocator.Current;
        if (sl != null)
        {
            sl.Register<IGameUIManager>(this);
        }
    }

    private void Start()
    {
        HideGameOver();
        TryRegisterEvents();
    }

    /// <summary>
    /// 注册计分事件。由 Start() 和 RegisterLocalPlayerTeam() 双端调用，
    /// 确保不管谁先执行，事件只订阅一次且后续计分变化能正确刷新。
    /// </summary>
    private void TryRegisterEvents()
    {
        if (_eventsRegistered) return;

        var tsm = TeamScoreManager.Instance;
        if (tsm == null) return;

        tsm.OnScoreChanged.AddListener(UpdateScoreDisplay);
        tsm.OnGameOverEvent.AddListener(ShowGameOver);
        _eventsRegistered = true;

        // 立即刷新一次当前分数
        UpdateScoreDisplay(tsm.redScore, tsm.blueScore);
    }

    public void RegisterLocalPlayerTeam(int teamId)
    {
        _localTeamId = teamId;
        // 确保事件已注册，并立即刷新分数显示
        TryRegisterEvents();
        RefreshScoreDisplay();
    }

    /// <summary>使用 TeamScoreManager 当前值刷新分数（无视 _localTeamId 守卫）</summary>
    private void RefreshScoreDisplay()
    {
        var tsm = TeamScoreManager.Instance;
        if (tsm != null)
            UpdateScoreDisplay(tsm.redScore, tsm.blueScore);
    }

    public void UpdateScoreDisplay(int redScore, int blueScore)
    {
        if (_localTeamId < 0) return;

        float maxScore = TeamScoreManager.ScoreToWin;
        int ownScore = (_localTeamId == 0) ? redScore : blueScore;
        int enemyScore = (_localTeamId == 0) ? blueScore : redScore;

        if (ownTeamScoreFill != null)
            ownTeamScoreFill.fillAmount = ownScore / maxScore;
        if (enemyTeamScoreFill != null)
            enemyTeamScoreFill.fillAmount = enemyScore / maxScore;

        if (ownScoreText != null)
            ownScoreText.text = ownScore.ToString();
        if (enemyScoreText != null)
            enemyScoreText.text = enemyScore.ToString();
    }

    public void ShowGameOver(int winningTeam, int redScore, int blueScore)
    {
        _gameOverShown = true;

        if (_localTeamId < 0) return;

        bool isWin = _localTeamId == winningTeam;

        if (winPanel != null)
            winPanel.SetActive(isWin);
        if (losePanel != null)
            losePanel.SetActive(!isWin);

        // 最终分数显示
        UpdateScoreDisplay(redScore, blueScore);
    }

    public void HideGameOver()
    {
        _gameOverShown = false;

        if (winPanel != null)
            winPanel.SetActive(false);
        if (losePanel != null)
            losePanel.SetActive(false);
    }

    private void OnDestroy()
    {
        var tsm = TeamScoreManager.Instance;
        if (tsm != null)
        {
            tsm.OnScoreChanged.RemoveListener(UpdateScoreDisplay);
            tsm.OnGameOverEvent.RemoveListener(ShowGameOver);
        }

        var sl = ServiceLocator.Current;
        if (sl != null)
        {
            sl.Unregister<IGameUIManager>();
        }
    }
}
