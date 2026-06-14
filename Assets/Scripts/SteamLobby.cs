using Steamworks;
using UnityEngine;
using UnityEngine.UI;

public class SteamLobby : MonoBehaviour
{
    public static SteamLobby Instance;
    public Text debugText;
    private MyNetworkRoomManager _roomManager;
    private CSteamID _currentLobbyId;
    private const string hostAddressKey = "HostAddress";

    protected Callback<LobbyCreated_t> LobbyCreated;
    protected Callback<GameLobbyJoinRequested_t> LobbyJoinRequested;
    protected Callback<LobbyEnter_t> LobbyEntered;

    private void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
            DontDestroyOnLoad(gameObject);
        }
        else
        {
            Destroy(gameObject);
        }
    }

    private void Start()
    {
        // Steam 已在 Boot 阶段确认可用，直接初始化
        InitializeSteamCallbacks();
    }

    private void InitializeSteamCallbacks()
    {
        if (debugText != null)
            debugText.text = SteamManager.Initialized
                ? "Steam初始化成功,或已经连接到steam服务器"
                : "Steam初始化失败，或者是未连接到服务器";

        _roomManager = GetComponent<MyNetworkRoomManager>();

        LobbyCreated = Callback<LobbyCreated_t>.Create(OnLobbyCreated);
        LobbyJoinRequested = Callback<GameLobbyJoinRequested_t>.Create(OnLobbyJoinRequested);
        LobbyEntered = Callback<LobbyEnter_t>.Create(OnLobbyEntered);
    }

    private void OnLobbyCreated(LobbyCreated_t callback)
    {
        if (callback.m_eResult == EResult.k_EResultOK)
        {
            _currentLobbyId = new CSteamID(callback.m_ulSteamIDLobby);
            if (debugText != null) debugText.text = "房间创建成功";
            _roomManager.StartHost();
            SteamMatchmaking.SetLobbyData(new CSteamID(callback.m_ulSteamIDLobby), hostAddressKey, SteamUser.GetSteamID().ToString());
        }
        else
        {
            if (debugText != null) debugText.text = "房间创建失败，错误码：" + callback.m_eResult;
        }
    }

    private void OnLobbyJoinRequested(GameLobbyJoinRequested_t callback)
    {
        if (debugText != null) debugText.text = "收到加入房间请求，正在尝试加入房间...";
        SteamMatchmaking.JoinLobby(callback.m_steamIDLobby);
    }

    private void OnLobbyEntered(LobbyEnter_t callback)
    {
        _currentLobbyId = new CSteamID(callback.m_ulSteamIDLobby);
        if (debugText != null) debugText.text = "有玩家进入大厅";
        string hostAddress = SteamMatchmaking.GetLobbyData(new CSteamID(callback.m_ulSteamIDLobby), hostAddressKey);
        _roomManager.networkAddress = hostAddress;
        if (!_roomManager.isNetworkActive)
        {
            _roomManager.StartClient();
            if (debugText != null) debugText.text = "玩家正在连接到主机，请稍后......";
        }
    }

    public void HostLobby()
    {
        if (!SteamManager.Initialized)
        {
            Debug.LogError("[SteamLobby] HostLobby: Steam 未初始化");
            if (debugText != null) debugText.text = "Steam 未初始化，无法创建房间";
            return;
        }
        SteamMatchmaking.CreateLobby(ELobbyType.k_ELobbyTypeFriendsOnly, _roomManager.maxConnections);
    }

    public void BindDebugText(Text text)
    {
        debugText = text;
        if (debugText != null)
            debugText.text = SteamManager.Initialized
                ? "Steam初始化成功,或已经连接到steam服务器"
                : "Steam初始化失败，或者是未连接到服务器";
    }

    public void LeaveLobby()
    {
        if (_currentLobbyId != CSteamID.Nil)
        {
            SteamMatchmaking.LeaveLobby(_currentLobbyId);
            _currentLobbyId = CSteamID.Nil;
        }
    }
}
