using System.Collections;
using Mirror;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using StarterAssets;
using InfimaGames.LowPolyShooterPack;

/// <summary>
/// 游戏结束后的结算面板。显示双方所有玩家/Bot 的击杀/死亡统计 + 返回大厅倒计时。
/// 双路径订阅：PlayerStatsManager (primary) + TeamScoreManager (scene NB fallback).
/// </summary>
public class SettlementUI : MonoBehaviour
{
    [Header("Panel")]
    [SerializeField] private GameObject settlementPanel;

    [Header("Team Contents")]
    [SerializeField] private Transform redTeamContent;
    [SerializeField] private Transform blueTeamContent;

    [Header("Entry Prefab")]
    [SerializeField] private GameObject settlementEntryPrefab;

    [Header("Result")]
    [SerializeField] private TMP_Text resultText;
    [SerializeField] private TMP_Text scoreText;

    [Header("Countdown")]
    [SerializeField] private TMP_Text countdownText;

    [Header("Timing")]
    [SerializeField] private float winLoseDelay = 3f;

    private bool _subscribed;
    private bool _settlementShown;
    private float _retryTimer;

    private void Start()
    {
        if (settlementPanel != null)
            settlementPanel.SetActive(false);
        TrySubscribe();
    }

    private void Update()
    {
        if (!_subscribed)
        {
            _retryTimer += Time.deltaTime;
            if (_retryTimer >= 0.5f)
            {
                _retryTimer = 0f;
                TrySubscribe();
            }
        }
    }

    private void TrySubscribe()
    {
        if (_subscribed) return;

        // Path 1: PlayerStatsManager (works on host, may work on clients)
        if (PlayerStatsManager.Instance != null)
        {
            PlayerStatsManager.Instance.OnSettlementReceived += OnSettlementDataReceived;
            _subscribed = true;
            Debug.Log("[SettlementUI] Subscribed via PlayerStatsManager.");
            return;
        }

        // Path 2: TeamScoreManager (scene NB, guaranteed on all clients)
        if (TeamScoreManager.Instance != null)
        {
            TeamScoreManager.Instance.OnSettlementReceived.AddListener(OnSettlementJsonReceived);
            _subscribed = true;
            Debug.Log("[SettlementUI] Subscribed via TeamScoreManager fallback.");
            return;
        }
    }

    private void OnSettlementDataReceived(SettlementData data, float countdownSeconds)
    {
        TriggerSettlement(data, countdownSeconds);
    }

    private void OnSettlementJsonReceived(string json, float countdownSeconds)
    {
        SettlementData data = JsonUtility.FromJson<SettlementData>(json);
        TriggerSettlement(data, countdownSeconds);
    }

    private void TriggerSettlement(SettlementData data, float countdownSeconds)
    {
        if (_settlementShown) return;
        _settlementShown = true;
        StartCoroutine(SettlementSequence(data, countdownSeconds));
    }

    private IEnumerator SettlementSequence(SettlementData data, float countdownSeconds)
    {
        // 1. 等待 win/lose panel 先展示
        yield return new WaitForSeconds(winLoseDelay);

        // 2. 显示结算面板
        if (settlementPanel != null)
            settlementPanel.SetActive(true);

        // Block player input: unlock cursor, disable Character look
        Cursor.visible = true;
        Cursor.lockState = CursorLockMode.None;
        var localPlayer = NetworkClient.localPlayer;
        if (localPlayer != null)
        {
            var chr = localPlayer.GetComponentInChildren<Character>(true);
            if (chr != null) chr.SetCursorLocked(false);
            var tpc = localPlayer.GetComponent<ThirdPersonController>();
            if (tpc != null) tpc.CursorInputForLook = false;
        }

        bool isWin = GetLocalTeam() == data.winningTeam;
        if (resultText != null)
            resultText.text = isWin ? "胜利" : "失败";
        if (scoreText != null)
            scoreText.text = $"红方 {data.redScore} : {data.blueScore} 蓝方";

        // 3. 填充条目
        PopulateEntries(data);

        // 4. 倒计时
        float remaining = countdownSeconds;
        while (remaining > 0)
        {
            if (countdownText != null)
                countdownText.text = $"{Mathf.CeilToInt(remaining)}秒后返回大厅";
            yield return new WaitForSeconds(1f);
            remaining -= 1f;
        }
        if (countdownText != null)
            countdownText.text = "0秒后返回大厅";
    }

    private void PopulateEntries(SettlementData data)
    {
        foreach (Transform child in redTeamContent) Destroy(child.gameObject);
        foreach (Transform child in blueTeamContent) Destroy(child.gameObject);

        foreach (var entry in data.entries)
        {
            Transform parent = entry.teamId == 0 ? redTeamContent : blueTeamContent;
            var go = Instantiate(settlementEntryPrefab, parent);
            go.GetComponent<SettlementEntry>()?.Setup(entry.playerName, entry.kills, entry.deaths, entry.isBot);
        }
    }

    private int GetLocalTeam()
    {
        if (NetworkClient.localPlayer != null)
        {
            var pnb = NetworkClient.localPlayer.GetComponent<PlayerNetworkBridge>();
            if (pnb != null) return pnb.teamId;
        }
        return -1;
    }

    private void OnDestroy()
    {
        if (PlayerStatsManager.Instance != null)
            PlayerStatsManager.Instance.OnSettlementReceived -= OnSettlementDataReceived;
        if (TeamScoreManager.Instance != null)
            TeamScoreManager.Instance.OnSettlementReceived.RemoveListener(OnSettlementJsonReceived);
    }
}
