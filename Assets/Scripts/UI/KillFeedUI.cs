using UnityEngine;
using UnityEngine.UI;
using Mirror;

/// <summary>
/// 击杀播报 UI 管理器。
/// 挂载到 GameScene Canvas 中的 ScrollView GameObject 上。
/// 监听 TeamScoreManager.OnKillEntryReceived，在 ScrollView 中创建条目。
/// </summary>
public class KillFeedUI : MonoBehaviour
{
    [SerializeField] private GameObject entryPrefab;
    [SerializeField] private Transform contentParent;
    [SerializeField] private ScrollRect scrollRect;
    [SerializeField] private int maxEntries = 20;

    private int _localTeamId = -1;
    private float _subscribeRetryTimer;
    private const float SubscribeRetryInterval = 0.5f;
    private bool _subscribed;

    private void Start()
    {
        TrySubscribe();
    }

    private void Update()
    {
        if (_subscribed) return;
        _subscribeRetryTimer += Time.deltaTime;
        if (_subscribeRetryTimer >= SubscribeRetryInterval)
        {
            _subscribeRetryTimer = 0f;
            TrySubscribe();
        }
    }

    private void TrySubscribe()
    {
        if (_subscribed) return;
        if (TeamScoreManager.Instance == null) return;

        TeamScoreManager.Instance.OnKillEntryReceived += OnKillEntry;
        _subscribed = true;
    }

    private void OnKillEntry(string killer, string victim, int killerTeam, int victimTeam)
    {
        // 首次接收时确定本地队伍
        if (_localTeamId < 0)
        {
            var localPlayer = NetworkClient.localPlayer;
            if (localPlayer != null)
            {
                var pnb = localPlayer.GetComponent<StarterAssets.PlayerNetworkBridge>();
                if (pnb != null) _localTeamId = pnb.teamId;
            }
        }

        // 限制条目数：超过上限则移除最旧的
        while (contentParent.childCount >= maxEntries)
            Destroy(contentParent.GetChild(0).gameObject);

        var go = Instantiate(entryPrefab, contentParent);
        go.GetComponent<KillFeedEntry>().Setup(killer, victim, killerTeam, victimTeam, _localTeamId);

        // 强制滚动到底部
        Canvas.ForceUpdateCanvases();
        scrollRect.verticalNormalizedPosition = 0f;
    }

    private void OnDestroy()
    {
        if (TeamScoreManager.Instance != null)
            TeamScoreManager.Instance.OnKillEntryReceived -= OnKillEntry;
    }
}
