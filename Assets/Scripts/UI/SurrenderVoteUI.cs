using UnityEngine;
using TMPro;

/// <summary>
/// Surrender vote UI display and input handling.
/// Shows countdown, vote progress, and handles F2/F3 input.
/// Visual layout is user-created; this script provides the logic interface.
/// </summary>
public class SurrenderVoteUI : MonoBehaviour
{
    [Header("Panel")]
    [SerializeField] private GameObject _panelRoot;

    [Header("Text")]
    [SerializeField] private TMP_Text _countdownText;
    [SerializeField] private TMP_Text _voteProgressText;

    private bool _active;
    private float _endTime;
    private int _teamId;
    private int _totalMembers;
    private bool _hasVoted;
    private int _yesVotes;
    private int _votedCount;

    private const string KEY_HINT = "F2 同意投降  |  F3 拒绝投降";

    public void Show(int teamId, float serverEndTime, int totalMembers)
    {
        _teamId = teamId;
        _endTime = serverEndTime;
        _totalMembers = totalMembers;
        _active = true;
        _hasVoted = false;
        _yesVotes = 0;
        _votedCount = 0;

        if (_panelRoot != null)
            _panelRoot.SetActive(true);

        RefreshDisplay();
    }

    public void Hide()
    {
        _active = false;
        if (_panelRoot != null)
            _panelRoot.SetActive(false);
    }

    public void UpdateProgress(int yesVotes, int votedCount, int totalMembers)
    {
        _yesVotes = yesVotes;
        _votedCount = votedCount;
        _totalMembers = totalMembers;

        if (_active)
            RefreshDisplay();
    }

    private void RefreshDisplay()
    {
        if (_countdownText != null)
        {
            float remaining = _endTime - Time.time;
            int seconds = Mathf.CeilToInt(Mathf.Max(0, remaining));
            _countdownText.text = $"投降投票倒计时: {seconds} 秒";
        }

        if (_voteProgressText != null)
        {
            if (_hasVoted)
                _voteProgressText.text = $"你已投票  |  同意 {_yesVotes}/{_votedCount}  ({_totalMembers}人)";
            else
                _voteProgressText.text = $"同意 {_yesVotes}/{_votedCount}  ({_totalMembers}人)\n{KEY_HINT}";
        }
    }

    private void Update()
    {
        if (!_active) return;

        // Countdown tick
        float remaining = _endTime - Time.time;
        if (remaining <= 0f)
        {
            if (_countdownText != null)
                _countdownText.text = "投票结束";
            return;
        }

        if (_countdownText != null && Time.frameCount % 30 == 0)
        {
            int seconds = Mathf.CeilToInt(remaining);
            _countdownText.text = $"投降投票倒计时: {seconds} 秒";
        }

        // F2/F3 input (only if not yet voted)
        if (!_hasVoted)
        {
            if (Input.GetKeyDown(KeyCode.F2))
            {
                _hasVoted = true;
                var mgr = SurrenderVoteManager.Instance;
                if (mgr != null)
                    mgr.CmdVoteSurrender(_teamId, true);

                RefreshDisplay();
            }
            else if (Input.GetKeyDown(KeyCode.F3))
            {
                _hasVoted = true;
                var mgr = SurrenderVoteManager.Instance;
                if (mgr != null)
                    mgr.CmdVoteSurrender(_teamId, false);

                RefreshDisplay();
            }
        }
    }
}
