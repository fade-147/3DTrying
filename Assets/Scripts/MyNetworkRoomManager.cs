using System.Collections;
using System.Collections.Generic;
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
    private bool _isGameEnding;
    private bool _isSinglePlayer;

    // 队伍生成配置：teamId → 生成区域 + 缓存数据
    private readonly Dictionary<int, TeamSpawnConfig> _teamSpawns = new Dictionary<int, TeamSpawnConfig>();
    private const int TeamCount = 2;

    private sealed class TeamSpawnConfig
    {
        public TeamSpawnArea area;
        public NetworkStartPosition[] positions;
        public int nextIndex;
    }

    public override void Awake()
    {
        RegisterBotListMessage();
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

    static void RegisterBotListMessage()
    {
        if (Reader<BotListMessage>.read != null) return; // 已注册，幂等

        Reader<BotListMessage>.read = reader =>
        {
            int count = reader.ReadInt();
            int[] ids = new int[count];
            for (int i = 0; i < count; i++)
                ids[i] = reader.ReadInt();
            return new BotListMessage { teamIds = ids };
        };

        Writer<BotListMessage>.write = (writer, msg) =>
        {
            int count = msg.teamIds != null ? msg.teamIds.Length : 0;
            writer.WriteInt(count);
            for (int i = 0; i < count; i++)
                writer.WriteInt(msg.teamIds[i]);
        };
    }

    public override void OnStartServer()
    {
        base.OnStartServer();
        InitBotTracker();
        // 替换 AddPlayerMessage 处理器：Mirror 内置的 OnServerAddPlayerInternal 在
        // conn.identity != null 时直接报错，无法被 OnServerAddPlayer 覆盖拦截。
        // 场景切换后远端客户端 OnClientSceneChanged 可能在 spawn 到达前就发 AddPlayer，
        // 需要在这里优雅处理而非报错。
        NetworkServer.RegisterHandler<AddPlayerMessage>(OnServerAddPlayerMessage);
    }

    public override void OnStopServer()
    {
        if (_botTracker != null)
        {
            Destroy(_botTracker.gameObject);
            _botTracker = null;
        }
        base.OnStopServer();
    }

    void OnServerAddPlayerMessage(NetworkConnectionToClient conn, AddPlayerMessage msg)
    {
        if (conn.identity != null)
        {
            NetworkServer.SetClientReady(conn);
            return;
        }

        if (autoCreatePlayer && playerPrefab == null)
        {
            Debug.LogError("The PlayerPrefab is empty on the NetworkManager.");
            return;
        }
        if (autoCreatePlayer && !playerPrefab.TryGetComponent(out NetworkIdentity _))
        {
            Debug.LogError("The PlayerPrefab does not have a NetworkIdentity.");
            return;
        }

        OnServerAddPlayer(conn);
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
        SendBotListToAll();
    }

    public void RemoveLastBot(int teamId)
    {
        if (!NetworkServer.active) return;
        InitBotTracker();
        _botTracker.RemoveLastBot(teamId);
        SendBotListToAll();
    }

    void SendBotListToAll()
    {
        int[] ids = _botTracker != null ? _botTracker.botTeamIds.ToArray() : new int[0];
        NetworkServer.SendToAll(new BotListMessage { teamIds = ids });
    }

    void SendBotListToConnection(NetworkConnectionToClient conn)
    {
        int[] ids = _botTracker != null ? _botTracker.botTeamIds.ToArray() : new int[0];
        conn.Send(new BotListMessage { teamIds = ids });
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

        // 回退到 RoomScene 时，将每个连接的 identity 从 game player 换回 room player，
        // 保留 roomSlots 不变以保证 player index 稳定、不产生重复 entry。
        if (scenePath == RoomScene && NetworkServer.active)
        {
            foreach (NetworkRoomPlayer roomPlayer in roomSlots)
            {
                if (roomPlayer == null) continue;
                roomPlayer.SetReadyToBegin(false);
                NetworkIdentity identity = roomPlayer.GetComponent<NetworkIdentity>();
                if (identity.connectionToClient != null)
                {
                    NetworkServer.ReplacePlayerForConnection(
                        identity.connectionToClient,
                        roomPlayer.gameObject,
                        ReplacePlayerOptions.KeepAuthority);
                }
            }
            allPlayersReady = false;
            _botTracker?.ClearBots();
            _teamSpawns.Clear();
            SendBotListToAll();
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

            if (scenePath == GameplayScene)
            {
                AssignTeamsToSpawnAreas();
            }

            FinishLoadScene();

            if (scenePath == GameplayScene)
            {
                // 单人模式：roomSlots 为空，需手动为本地玩家创建 game player
                if (_isSinglePlayer)
                {
                    var localConn = NetworkServer.localConnection;
                    if (localConn != null && localConn.identity == null)
                    {
                        OnServerAddPlayer(localConn);
                    }
                }

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
    /// <summary>手动加载 offline 场景（禁止 Mirror 自动场景切换后使用）。等待两帧确保网络完全清理。</summary>
    private IEnumerator LoadOfflineSceneByYooAsset(string scenePath)
    {
        if (string.IsNullOrWhiteSpace(scenePath))
            yield break;

        yield return null;
        yield return null;

        _currentSceneHandle?.Release();
        _currentSceneHandle = YooAssets.LoadSceneAsync(scenePath, LoadSceneMode.Single);
        yield return _currentSceneHandle;

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
            SendBotListToConnection(conn);
            return;
        }

        // GameplayScene: pendingPlayers 可能已被 CheckReadyToBegin 清空
        // 在此手动创建 game player，从 roomSlots 查找队伍
        int teamId = GetTeamIdForConnection(conn);
        GameObject gamePlayer = SpawnPlayerAtTeamPosition(teamId);
        SetTeamOnComponents(gamePlayer, teamId);

        NetworkServer.AddPlayerForConnection(conn, gamePlayer);
    }

    public override GameObject OnRoomServerCreateGamePlayer(NetworkConnectionToClient conn, GameObject roomPlayer)
    {
        MyNetworkRoomPlayer roomP = roomPlayer.GetComponent<MyNetworkRoomPlayer>();
        int teamId = roomP != null ? roomP.teamId : 0;

        return SpawnPlayerAtTeamPosition(teamId);
    }

    private int GetTeamIdForConnection(NetworkConnectionToClient conn)
    {
        foreach (NetworkRoomPlayer slot in roomSlots)
        {
            if (slot.connectionToClient == conn && slot is MyNetworkRoomPlayer mySlot)
                return mySlot.teamId;
        }
        return 0;
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
        StarterAssets.PlayerNetworkBridge pnb = gamePlayer.GetComponent<StarterAssets.PlayerNetworkBridge>();
        if (roomP != null && pnb != null)
        {
            pnb.teamId = roomP.teamId;
        }

        // Backward compat: also set teamId on ThirdPersonController if present
        StarterAssets.ThirdPersonController tpc = gamePlayer.GetComponent<StarterAssets.ThirdPersonController>();
        if (tpc != null)
        {
            tpc.teamId = roomP.teamId;
        }

        // Also set teamId on PlayerState if present (for BotController.GetTeamId compatibility)
        PlayerState ps = gamePlayer.GetComponent<PlayerState>();
        if (ps != null) ps.teamId = roomP.teamId;

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

    /// <summary>单人模式：跳过 Steam 大厅和 RoomScene，直接进入 5v5 对局。</summary>
    public void StartSinglePlayer()
    {
        if (NetworkServer.active || NetworkClient.active)
        {
            Debug.LogWarning("[MyNetworkRoomManager] 网络已活跃，无法启动单人模式");
            return;
        }

        _isSinglePlayer = true;

        // 预填充 Bot：4 友方 (Team0) + 5 敌方 (Team1) = 5v5
        InitBotTracker();
        for (int i = 0; i < 4; i++) _botTracker.AddBot(0);
        for (int i = 0; i < 5; i++) _botTracker.AddBot(1);

        // 临时清空 onlineScene，阻止 StartHost 自动加载 LobbyScene
        string savedOnlineScene = onlineScene;
        onlineScene = "";
        try
        {
            StartHost();
        }
        finally
        {
            onlineScene = savedOnlineScene;
        }

        // 直接加载 GameScene
        ServerChangeScene(GameplayScene);
    }

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
        if (_isSinglePlayer)
        {
            ShutdownAndLoadOfflineScene();
            return;
        }

        if (NetworkServer.active && Utils.IsSceneActive(GameplayScene))
        {
            _isGameEnding = true;
            ServerChangeScene(RoomScene);
        }
    }

    public void LeaveRoom()
    {
        if (_isSinglePlayer)
        {
            ShutdownAndLoadOfflineScene();
            return;
        }

        if (isNetworkActive)
        {
            if (SteamLobby.Instance != null)
                SteamLobby.Instance.LeaveLobby();

            string saved = offlineScene;
            offlineScene = "";

            if (mode == NetworkManagerMode.Host)
                StopHost();
            else
                StopClient();

            offlineScene = saved;
            if (!string.IsNullOrWhiteSpace(saved))
                StartCoroutine(LoadOfflineSceneByYooAsset(saved));
        }
    }

    /// <summary>单机模式：安全关闭网络并加载 offline 场景，阻止 Mirror 将 GO 移出 DontDestroyOnLoad。</summary>
    private void ShutdownAndLoadOfflineScene()
    {
        _isGameEnding = true;
        _isSinglePlayer = false;
        string saved = offlineScene;
        offlineScene = "";
        StopHost();
        offlineScene = saved;
        StartCoroutine(LoadOfflineSceneByYooAsset(saved));
    }

    #region 队伍生成区域

    private void AssignTeamsToSpawnAreas()
    {
        _teamSpawns.Clear();
        _isGameEnding = false;

        TeamSpawnArea[] areas = FindObjectsOfType<TeamSpawnArea>();

        // 按 sideId 分组
        List<TeamSpawnArea> side0Areas = new();
        List<TeamSpawnArea> side1Areas = new();
        foreach (var area in areas)
        {
            if (area.sideId == 0) side0Areas.Add(area);
            else side1Areas.Add(area);
        }

        if (side0Areas.Count > 0 && side1Areas.Count > 0)
        {
            // 两侧都有 TeamSpawnArea：随机决定 team0 在哪侧
            TeamSideMapping.AssignRandom();

            // 收集同侧所有 NetworkStartPosition
            List<NetworkStartPosition> posSide0 = new();
            foreach (var a in side0Areas)
                posSide0.AddRange(a.GetComponentsInChildren<NetworkStartPosition>());
            List<NetworkStartPosition> posSide1 = new();
            foreach (var a in side1Areas)
                posSide1.AddRange(a.GetComponentsInChildren<NetworkStartPosition>());

            int teamForSide0 = TeamSideMapping.SideToTeam[0];
            int teamForSide1 = TeamSideMapping.SideToTeam[1];

            _teamSpawns[teamForSide0] = new TeamSpawnConfig
            {
                area = side0Areas[0],
                positions = posSide0.ToArray(),
                nextIndex = 0
            };

            _teamSpawns[teamForSide1] = new TeamSpawnConfig
            {
                area = side1Areas[0],
                positions = posSide1.ToArray(),
                nextIndex = 0
            };

            Debug.Log($"[MyNetworkRoomManager] Side 0 → Team {teamForSide0} ({posSide0.Count} spawns), Side 1 → Team {teamForSide1} ({posSide1.Count} spawns)");
            return;
        }

        // 回退：未配置足够的 TeamSpawnArea 时，所有 NetworkStartPosition 作为共享生成池
        NetworkStartPosition[] all = FindObjectsOfType<NetworkStartPosition>();
        if (all.Length == 0)
        {
            Debug.LogError("[MyNetworkRoomManager] 场景中没有 NetworkStartPosition，玩家将在原点生成");
            return;
        }

        // 无 TeamSpawnArea 时回退到共享池，映射设为 side=teamId（保持原行为）
        TeamSideMapping.SideToTeam.Clear();
        TeamSideMapping.TeamToSide.Clear();
        TeamSideMapping.SideToTeam[0] = 0;
        TeamSideMapping.SideToTeam[1] = 1;
        TeamSideMapping.TeamToSide[0] = 0;
        TeamSideMapping.TeamToSide[1] = 1;

        var sharedConfig = new TeamSpawnConfig { area = null, positions = all, nextIndex = 0 };
        for (int i = 0; i < TeamCount; i++)
            _teamSpawns[i] = sharedConfig;

        Debug.LogWarning($"[MyNetworkRoomManager] TeamSpawnArea 不足，回退到共享池 ({all.Length} 个生成点)");
    }

    private Transform GetNextTeamSpawnPosition(int teamId)
    {
        if (!_teamSpawns.TryGetValue(teamId, out TeamSpawnConfig config)
            || config.positions.Length == 0)
        {
            return GetStartPosition(); // 回退到默认轮询
        }

        int index = config.nextIndex;
        config.nextIndex = (index + 1) % config.positions.Length;
        return config.positions[index].transform;
    }

    public Transform GetTeamRespawnPosition(int teamId)
    {
        if (!_teamSpawns.TryGetValue(teamId, out TeamSpawnConfig config)
            || config.positions.Length == 0)
        {
            // 统一回退：全局随机
            NetworkStartPosition[] fallback = FindObjectsOfType<NetworkStartPosition>();
            if (fallback.Length > 0)
                return fallback[Random.Range(0, fallback.Length)].transform;
            return null;
        }

        return config.positions[Random.Range(0, config.positions.Length)].transform;
    }

    private GameObject SpawnPlayerAtTeamPosition(int teamId)
    {
        Transform startPos = GetNextTeamSpawnPosition(teamId);
        return startPos != null
            ? Instantiate(playerPrefab, startPos.position, startPos.rotation)
            : Instantiate(playerPrefab, Vector3.zero, Quaternion.identity);
    }

    /// <summary>在 NetworkServer.Spawn 之前，统一设置所有组件的 teamId。</summary>
    private void SetTeamOnComponents(GameObject obj, int teamId)
    {
        var pnb = obj.GetComponent<StarterAssets.PlayerNetworkBridge>();
        if (pnb != null) pnb.teamId = teamId;

        var tpc = obj.GetComponent<StarterAssets.ThirdPersonController>();
        if (tpc != null) tpc.teamId = teamId;

        var ps = obj.GetComponent<PlayerState>();
        if (ps != null) ps.teamId = teamId;

        var bc = obj.GetComponent<BotController>();
        if (bc != null) bc.teamId = teamId;
    }

    /// <summary>复活延迟（秒），死亡后等待此时间再销毁+重建</summary>
    private const float RespawnDelay = 3f;

    /// <summary>[Server] 委托销毁 + 重建玩家（保持连接绑定）</summary>
    public void QueuePlayerRespawn(NetworkConnectionToClient conn, int teamId, GameObject objectToDestroy)
    {
        if (!NetworkServer.active) return;
        StartCoroutine(PlayerRespawnSequence(conn, teamId, objectToDestroy));
    }

    private IEnumerator PlayerRespawnSequence(NetworkConnectionToClient conn, int teamId, GameObject objectToDestroy)
    {
        if (_isGameEnding) yield break;

        // 延迟几秒再复活，给死亡画面展示时间
        yield return new WaitForSeconds(RespawnDelay);

        if (_isGameEnding) yield break;

        if (objectToDestroy != null)
            NetworkServer.Destroy(objectToDestroy);

        yield return null;

        if (_isGameEnding) yield break;
        if (conn == null || !conn.isReady) yield break;

        Transform startPos = GetTeamRespawnPosition(teamId);
        Vector3 pos = startPos != null ? startPos.position : Vector3.zero;
        Quaternion rot = startPos != null ? startPos.rotation : Quaternion.identity;

        GameObject newPlayer = Instantiate(playerPrefab, pos, rot);
        SetTeamOnComponents(newPlayer, teamId);
        NetworkServer.ReplacePlayerForConnection(conn, newPlayer, ReplacePlayerOptions.KeepAuthority);
    }

    /// <summary>[Server] 委托销毁 + 重建 Bot</summary>
    public void QueueBotRespawn(int teamId, GameObject objectToDestroy)
    {
        if (!NetworkServer.active) return;
        StartCoroutine(BotRespawnSequence(teamId, objectToDestroy));
    }

    private IEnumerator BotRespawnSequence(int teamId, GameObject objectToDestroy)
    {
        if (_isGameEnding) yield break;

        yield return new WaitForSeconds(RespawnDelay);

        if (_isGameEnding) yield break;

        if (objectToDestroy != null)
            NetworkServer.Destroy(objectToDestroy);

        yield return null;

        if (_isGameEnding) yield break;

        Transform startPos = GetTeamRespawnPosition(teamId);
        Vector3 pos = startPos != null ? startPos.position : Vector3.zero;
        pos = SnapToNavMesh(pos);

        GameObject bot = Instantiate(botGamePrefab, pos, Quaternion.identity);
        SetTeamOnComponents(bot, teamId);
        NetworkServer.Spawn(bot);
    }

    #endregion

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

        for (int i = 0; i < _botTracker.botTeamIds.Count; i++)
        {
            int teamId = _botTracker.botTeamIds[i];
            Transform startPos = GetNextTeamSpawnPosition(teamId);
            Vector3 pos = startPos != null ? startPos.position : Vector3.zero;

            pos = SnapToNavMesh(pos);

            GameObject bot = Instantiate(botGamePrefab, pos, Quaternion.identity);
            SetTeamOnComponents(bot, teamId);
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

public struct BotListMessage : NetworkMessage
{
    public int[] teamIds;
}

