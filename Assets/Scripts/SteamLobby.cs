using Steamworks;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SteamLobby : MonoBehaviour
{
    public static SteamLobby Instance;
    public Text debugText;
    private MyNetworkRoomManager _roomManager;
    private const string hostAddressKey = "HostAddress";      //这个是用来存储主机地址的键

    protected Callback<LobbyCreated_t> LobbyCreated;   //创建房间的回调
    protected Callback<GameLobbyJoinRequested_t> LobbyJoinRequested;   //加入房间的回调
    protected Callback<LobbyEnter_t> LobbyEntered;   //进入房间的回调

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
        if(!SteamManager.Initialized)
        {
            debugText.text = "Steam初始化失败，或者是未连接到服务器";
            return;
        }
        
        debugText.text = "Steam初始化成功,或已经连接到steam服务器";
        _roomManager = GetComponent<MyNetworkRoomManager>();

        //注册回调函数，当创建房间、加入房间请求和进入房间时会调用相应的函数
        LobbyCreated = Callback<LobbyCreated_t>.Create(OnLobbyCreated);
        LobbyJoinRequested = Callback<GameLobbyJoinRequested_t>.Create(OnLobbyJoinRequested);
        LobbyEntered = Callback<LobbyEnter_t>.Create(OnLobbyEntered);
    }

    private void OnLobbyCreated(LobbyCreated_t callback)
    {
        if (callback.m_eResult == EResult.k_EResultOK)
        {
            debugText.text = "房间创建成功";
            _roomManager.StartHost();    //创建房间成功后，设置房间数据并启动主机
            SteamMatchmaking.SetLobbyData(new CSteamID(callback.m_ulSteamIDLobby), hostAddressKey, SteamUser.GetSteamID().ToString());   //设置房间数据，获取大厅ID并转换为字符串作为主机地址，获取当前用户的SteamID并转换为字符串作为主机地址
        }
        else
        {
            debugText.text = "房间创建失败，错误码：" + callback.m_eResult;
        }
    }
    private void OnLobbyJoinRequested(GameLobbyJoinRequested_t callback)
    {
        debugText.text = "收到加入房间请求，正在尝试加入房间...";
        SteamMatchmaking.JoinLobby(callback.m_steamIDLobby);    //获取到加入房间请求中的大厅ID，并尝试加入该房间
    }

    private void OnLobbyEntered(LobbyEnter_t callback)
    {
        //if (callback.m_EChatRoomEnterResponse == (uint)EChatRoomEnterResponse.k_EChatRoomEnterResponseSuccess)
        //{
        //    debugText.text = "成功进入房间";
        //    if (SteamMatchmaking.GetLobbyOwner(new CSteamID(callback.m_ulSteamIDLobby)) != SteamUser.GetSteamID())
        //    {
        //        string hostAddress = SteamMatchmaking.GetLobbyData(new CSteamID(callback.m_ulSteamIDLobby), hostAddressKey);
        //        _roomManager.networkAddress = hostAddress;
        //        _roomManager.StartClient();
        //    }
        //}
        //else
        //{
        //    debugText.text = "进入房间失败，错误码：" + callback.m_EChatRoomEnterResponse;
        //}
        debugText.text = "有玩家进入大厅";
        string hostAddress = SteamMatchmaking.GetLobbyData(new CSteamID(callback.m_ulSteamIDLobby), hostAddressKey);  //获取主机地址
        _roomManager.networkAddress = hostAddress;   //传给roomManager让他作为网络的地址
        if (!_roomManager.isNetworkActive)    //如果主机端还没有启用网络服务
        {
            _roomManager.StartClient();   //让客户端让他启用一下客户端的服务
            debugText.text = "玩家正在连接到主机，请稍后......";
        }

    }
    public void HostLobby()   //点击创建房间按钮时调用这个函数来创建房间
    {
        SteamMatchmaking.CreateLobby(ELobbyType.k_ELobbyTypeFriendsOnly, _roomManager.maxConnections);  //前一个是创建的房间类型（仅好友可进），第二个是可进入的玩家数量（最大连接数量
                                                                                                //）
    }
}
