using Mirror;
using UnityEngine;
using UnityEngine.UI;

public class BotLobbyUI : MonoBehaviour
{
    [SerializeField] private GameObject botEntryPrefab;

    private Transform _team1Container;
    private Transform _team2Container;

    bool _initialized;

    void Start()
    {
        _team1Container = GameObject.FindWithTag("Team1PlayerList")?.transform;
        _team2Container = GameObject.FindWithTag("Team2PlayerList")?.transform;

        if (_team1Container == null || _team2Container == null)
        {
            Debug.LogWarning("[BotLobbyUI] 队伍容器未找到 (Tag: Team1PlayerList/Team2PlayerList)");
            return;
        }

        if (botEntryPrefab == null)
        {
            Debug.LogWarning("[BotLobbyUI] botEntryPrefab 未赋值");
            return;
        }

        // 延迟初始化：BotTeamTracker 可能在 BotLobbyUI.Start 之后才创建
        // (如 MyNetworkRoomManager.OnStartServer 晚于场景加载时）
        _initialized = true;
        StartCoroutine(InitWhenReady());
    }

    System.Collections.IEnumerator InitWhenReady()
    {
        // 等 BotTeamTracker 就绪，最多等 5 秒
        float timeout = 5f;
        BotTeamTracker tracker = null;
        while (timeout > 0 && tracker == null)
        {
            var rm = MyNetworkRoomManager.instance;
            if (rm != null)
            {
                tracker = rm.GetComponentInChildren<BotTeamTracker>(true);
            }
            if (tracker == null)
            {
                yield return null;
                timeout -= Time.deltaTime;
            }
        }

        if (tracker == null)
        {
            Debug.LogWarning("[BotLobbyUI] 等待 BotTeamTracker 超时");
            yield break;
        }

        tracker.OnBotListChanged += RebuildAll;
        RebuildAll();
    }

    void RebuildAll()
    {
        if (!_initialized) return;

        var rm = MyNetworkRoomManager.instance;
        var tracker = rm?.GetComponentInChildren<BotTeamTracker>(true);
        if (tracker == null || _team1Container == null || _team2Container == null) return;

        ClearBotEntries();

        bool isServer = NetworkServer.active;

        int redIdx = 0, blueIdx = 0;
        for (int i = 0; i < tracker.botTeamIds.Count; i++)
        {
            int teamId = tracker.botTeamIds[i];
            Transform container = teamId == 0 ? _team1Container : _team2Container;
            int idx = teamId == 0 ? ++redIdx : ++blueIdx;
            string botName = teamId == 0 ? $"红队AI #{idx}" : $"蓝队AI #{idx}";

            GameObject entry = Instantiate(botEntryPrefab, container);
            entry.name = $"BotEntry_{teamId}_{idx}";
            entry.transform.localScale = Vector3.one;

            var nameText = entry.transform.Find("Player Name")?.GetComponent<Text>();
            if (nameText != null) nameText.text = botName;

            var readyText = entry.transform.Find("Ready State")?.GetComponent<Text>();
            if (readyText != null) readyText.text = "AI (就绪)";

            HideChild(entry, "Ready Button");
            HideChild(entry, "Cancel Button");

            if (isServer)
            {
                Transform removeTransform = entry.transform.Find("Remove Button");
                if (removeTransform != null)
                {
                    removeTransform.gameObject.SetActive(true);
                    var removeBtn = removeTransform.GetComponent<Button>();
                    if (removeBtn != null)
                    {
                        int capturedTeamId = teamId;
                        removeBtn.onClick.AddListener(() => MyNetworkRoomManager.instance.RemoveLastBot(capturedTeamId));
                    }
                }
            }
            else
            {
                HideChild(entry, "Remove Button");
            }
        }
    }

    void ClearBotEntries()
    {
        ClearContainer(_team1Container);
        ClearContainer(_team2Container);
    }

    void ClearContainer(Transform container)
    {
        if (container == null) return;
        for (int i = container.childCount - 1; i >= 0; i--)
        {
            if (container.GetChild(i).name.StartsWith("BotEntry_"))
                Destroy(container.GetChild(i).gameObject);
        }
    }

    void HideChild(GameObject parent, string childName)
    {
        Transform child = parent.transform.Find(childName);
        if (child != null) child.gameObject.SetActive(false);
    }

    void OnDestroy()
    {
        var rm = MyNetworkRoomManager.instance;
        if (rm != null)
        {
            var tracker = rm.GetComponentInChildren<BotTeamTracker>(true);
            if (tracker != null)
                tracker.OnBotListChanged -= RebuildAll;
        }
    }
}
