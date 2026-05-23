using System.Collections;
using System.Collections.Generic;
using UnityEngine;
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

        if (newScenePath == RoomScene)
        {
            foreach (NetworkRoomPlayer roomPlayer in roomSlots)
            {
                if (roomPlayer == null) continue;

                NetworkIdentity identity = roomPlayer.GetComponent<NetworkIdentity>();
                if (NetworkServer.active)
                {
                    roomPlayer.SetReadyToBegin(false);
                    NetworkServer.ReplacePlayerForConnection(identity.connectionToClient, roomPlayer.gameObject, ReplacePlayerOptions.KeepAuthority);
                }
            }
            allPlayersReady = false;
            _botTracker?.ClearBots();
        }

        StartCoroutine(ServerLoadSceneByYooAsset(newScenePath));
    }

    private IEnumerator ServerLoadSceneByYooAsset(string scenePath)
    {
        _isSwitchingScene = true;

        // 在场景加载前通知所有客户端：准备切换场景
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

            // 场景加载完成后触发 Ready 流程，Mirror 会自动创建 game player
            NetworkClient.ready = false;

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
    public override void OnRoomServerPlayersReady()
    {
        if (Utils.IsSceneActive(RoomScene) && startGameButton != null)
        {
            startGameButton.SetActive(true);
        }
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
        ServerChangeScene(GameplayScene);
    }

    public void ReturnToLobby()
    {
        if (NetworkServer.active && Utils.IsSceneActive(GameplayScene))
        {
            ServerChangeScene(RoomScene);
        }
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
