using System.Collections;
using UnityEngine;
using UnityEngine.AI;
using UnityEngine.SceneManagement;
using Mirror;
using YooAsset;
using Mirror.FizzySteam;
using StarterAssets;


public class MyNetworkRoomManager : NetworkRoomManager
{
    public static MyNetworkRoomManager instance;

    public GameObject startGameButton;
    public GameObject botGamePrefab;

    private BotTeamTracker _botTracker;

    private SceneHandle _currentSceneHandle;
    private bool _isSwitchingScene = false;

    public override void Awake()
    {
        base.Awake();
        if (instance == null)
        {
            instance = this;
            DontDestroyOnLoad(gameObject);
        }
        else
        {
            Destroy(gameObject);
        }
    }

    public override void OnStartServer()
    {
        base.OnStartServer();
        InitBotTracker();
    }

    void InitBotTracker()
    {
        if (_botTracker != null) return;
        GameObject botTrackerGO = new GameObject("BotTracker");
        botTrackerGO.transform.SetParent(transform);
        _botTracker = botTrackerGO.AddComponent<BotTeamTracker>();
    }

    public void AddBot(int teamId)
    {
        if (!NetworkServer.active) return;
        InitBotTracker();
        _botTracker.AddBot(teamId);
    }

    public void RemoveLastBot(int teamId)
    {
        if (!NetworkServer.active) return;
        InitBotTracker();
        _botTracker.RemoveLastBot(teamId);
    }

    public override void Start()
    {
        base.Start();
        if (Utils.IsSceneActive(RoomScene) && startGameButton != null)
        {
            startGameButton.SetActive(false);
        }
    }

    #region YooAsset 场景加载
    public override void ServerChangeScene(string newScenePath)
    {
        if (_isSwitchingScene)
        {
            Debug.LogWarning("[MyNetworkRoomManager] 场景正在切换中，忽略重复调用");
            return;
        }

        StartCoroutine(ServerLoadSceneByYooAsset(newScenePath));
    }

    private IEnumerator ServerLoadSceneByYooAsset(string scenePath)
    {
        _isSwitchingScene = true;

        // 回退到 RoomScene 时，先销毁所有 game player，让后续 AddPlayer 正常创建 room player
        if (scenePath == RoomScene && NetworkServer.active)
        {
            foreach (NetworkConnectionToClient conn in NetworkServer.connections.Values)
            {
                if (conn.identity != null)
                {
                    NetworkServer.Destroy(conn.identity.gameObject);
                }
            }
            roomSlots.Clear();
            allPlayersReady = false;
            _botTracker?.ClearBots();
        }

        NetworkServer.SetAllClientsNotReady();
        NetworkManager.networkSceneName = scenePath;
        OnServerChangeScene(scenePath);
        NetworkServer.isLoadingScene = true;

        if (NetworkServer.active)
        {
            NetworkServer.SendToAll(new SceneMessage { sceneName = scenePath });
        }

        try
        {
            _currentSceneHandle?.Release();
            _currentSceneHandle = YooAssets.LoadSceneAsync(scenePath, LoadSceneMode.Single);
            yield return _currentSceneHandle;

            startPositionIndex = 0;
            startPositions.Clear();

            FinishLoadScene();

            if (scenePath == GameplayScene)
            {
                StartCoroutine(SpawnBotsNextFrame());
            }
        }
        finally
        {
            _isSwitchingScene = false;
        }
    }

    public override void OnClientChangeScene(string newScenePath, SceneOperation sceneOperation, bool customHandling)
    {
        if (NetworkServer.active)
        {
            base.OnClientChangeScene(newScenePath, sceneOperation, true);
            return;
        }

        if (sceneOperation == SceneOperation.Normal || sceneOperation == SceneOperation.LoadAdditive)
        {
            base.OnClientChangeScene(newScenePath, sceneOperation, true);

            if (sceneOperation == SceneOperation.Normal)
                NetworkManager.networkSceneName = newScenePath;

            StartCoroutine(ClientLoadSceneByYooAsset(newScenePath, sceneOperation));
        }
        else
        {
            base.OnClientChangeScene(newScenePath, sceneOperation, customHandling);
        }
    }

    private IEnumerator ClientLoadSceneByYooAsset(string scenePath, SceneOperation sceneOperation)
    {
        _currentSceneHandle?.Release();

        LoadSceneMode loadMode = sceneOperation == SceneOperation.LoadAdditive ? LoadSceneMode.Additive : LoadSceneMode.Single;
        _currentSceneHandle = YooAssets.LoadSceneAsync(scenePath, loadMode);
        yield return _currentSceneHandle;

        if (sceneOperation == SceneOperation.Normal)
            NetworkManager.networkSceneName = scenePath;

        FinishLoadScene();
    }
    #endregion

    #region 房间流程
    public override void OnServerAddPlayer(NetworkConnectionToClient conn)
    {
        // 远端客户端 OnClientSceneChanged 可能在 spawn 消息到达前就发送 AddPlayer，
        // 此时 conn.identity 已在 OnServerSceneChanged 中被设置为 game player
        if (conn.identity != null)
        {
            NetworkServer.SetClientReady(conn);
            return;
        }

        if (Utils.IsSceneActive(RoomScene))
        {
            base.OnServerAddPlayer(conn);
            return;
        }

        // GameplayScene: pendingPlayers 可能已被 CheckReadyToBegin 清空
        // 在此手动创建 game player
        Transform startPos = GetStartPosition();
        GameObject gamePlayer = startPos != null
            ? Instantiate(playerPrefab, startPos.position, startPos.rotation)
            : Instantiate(playerPrefab, Vector3.zero, Quaternion.identity);

        NetworkServer.AddPlayerForConnection(conn, gamePlayer);
    }

    public override void OnRoomServerPlayersReady()
    {
        if (Utils.IsSceneActive(RoomScene) && startGameButton != null)
        {
            startGameButton.SetActive(true);
        }
    }

    public override bool OnRoomServerSceneLoadedForPlayer(NetworkConnectionToClient conn, GameObject roomPlayer, GameObject gamePlayer)
    {
        MyNetworkRoomPlayer roomP = roomPlayer.GetComponent<MyNetworkRoomPlayer>();
        ThirdPersonController tpc = gamePlayer.GetComponent<ThirdPersonController>();
        if (roomP != null && tpc != null)
        {
            tpc.teamId = roomP.teamId;
        }
        return true;
    }

    public override void OnRoomServerPlayersNotReady()
    {
        if (Utils.IsSceneActive(RoomScene) && startGameButton != null)
        {
            startGameButton.SetActive(false);
        }
    }

    public override void OnGUI()
    {
        if (!showRoomGUI) return;
        if (!Utils.IsSceneActive(RoomScene)) return;
    }
    #endregion

    #region UI 按钮 + Bot 生成
    public void StartGame()
    {
        if (Utils.IsSceneActive(RoomScene))
        {
            // CheckReadyToBegin 可能已清空 pendingPlayers，重建以保证 OnServerSceneChanged 能创建 game player
            pendingPlayers.Clear();
            foreach (NetworkConnectionToClient conn in NetworkServer.connections.Values)
            {
                if (conn.identity != null && conn.identity.TryGetComponent<NetworkRoomPlayer>(out _))
                {
                    pendingPlayers.Add(new PendingPlayer
                    {
                        conn = conn,
                        roomPlayer = conn.identity.gameObject
                    });
                }
            }
        }
        ServerChangeScene(GameplayScene);
    }

    public void ReturnToLobby()
    {
        if (NetworkServer.active && Utils.IsSceneActive(GameplayScene))
        {
            ServerChangeScene(RoomScene);
        }
    }

    /// <summary>
    /// 将位置修正到离 NavMesh 最近的有效点，失败则返回原始位置。
    /// </summary>
    private static Vector3 SnapToNavMesh(Vector3 pos)
    {
        if (NavMesh.SamplePosition(pos, out NavMeshHit hit, 50f, NavMesh.AllAreas))
            return hit.position;

        // 回退：从原点大范围搜索
        if (NavMesh.SamplePosition(Vector3.zero, out hit, 500f, NavMesh.AllAreas))
            return hit.position;

        Debug.LogError("[MyNetworkRoomManager] SnapToNavMesh 失败");
        return pos;
    }

    void SpawnBots()
    {
        if (botGamePrefab == null)
        {
            Debug.LogError("[MyNetworkRoomManager] botGamePrefab 未设置！");
            return;
        }
        if (_botTracker == null) return;

        NetworkStartPosition[] spawns = FindObjectsOfType<NetworkStartPosition>();

        for (int i = 0; i < _botTracker.botTeamIds.Count; i++)
        {
            Vector3 pos = spawns.Length > 0
                ? spawns[i % spawns.Length].transform.position
                : Vector3.zero;

            pos = SnapToNavMesh(pos);

            GameObject bot = Instantiate(botGamePrefab, pos, Quaternion.identity);

            int teamId = _botTracker.botTeamIds[i];
            BotController bc = bot.GetComponent<BotController>();
            if (bc != null) bc.teamId = teamId;

            ThirdPersonController tpc = bot.GetComponent<ThirdPersonController>();
            if (tpc != null) tpc.teamId = teamId;

            NetworkServer.Spawn(bot);
        }
    }

    IEnumerator SpawnBotsNextFrame()
    {
        yield return null;
        SpawnBots();
    }
    #endregion

    private void OnDestroy()
    {
        _currentSceneHandle?.Release();
    }
}
