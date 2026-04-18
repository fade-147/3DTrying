using Mirror;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class RoomPlayerGUI : MonoBehaviour
{
    [SerializeField]
    GameObject playerPanelPrefab;

   
    Button readyBtn;
    Button cancelBtn;
    Button removeBtn;
    Text playerName;
    Text readyState;
    GameObject playerList;
    GameObject playerPanel;
    NetworkRoomPlayer player;

    private void Start()
    {
        InitializeUI();    //初始化UI组件
    }
    private void OnEnable()
    {
        SceneManager.sceneLoaded += OnSceneLoaded;   //注册场景加载的回调函数，当场景加载完成后会调用OnSceneLoaded函数
    }
    private void OnDisable()
    {
        SceneManager.sceneLoaded -= OnSceneLoaded;   //取消注册场景加载的回调函数，避免内存泄漏
    }

    private void OnSceneLoaded(Scene scene, LoadSceneMode mode)  //传入场景以及加载场景的模式，当场景加载完成后会调用这个函数
    {
        if (scene.name == "LobbyScene 1")   //如果加载的场景是LobbyScene场景的话，初始化UI组件.。保证按下返回大厅按钮后，玩家的UI组件能够重新显示出来
        {
            InitializeUI();
        }
    }

    private void InitializeUI()
    {
        player = GetComponent<NetworkRoomPlayer>();
        playerList = GameObject.FindWithTag("PlayerList");
        playerPanel = Instantiate(playerPanelPrefab, playerList.transform) as GameObject;
        readyBtn = playerPanel.transform.Find("Ready Button").GetComponent<Button>();
        cancelBtn = playerPanel.transform.Find("Cancel Button").GetComponent<Button>();
        removeBtn = playerPanel.transform.Find("Remove Button").GetComponent<Button>();
        playerName = playerPanel.transform.Find("Player Name").GetComponent<Text>();
        readyState = playerPanel.transform.Find("Ready State").GetComponent<Text>();

        readyBtn.gameObject.SetActive(false);
        cancelBtn.gameObject.SetActive(false);
        removeBtn.gameObject.SetActive(false);

        if(NetworkClient.active && player.isLocalPlayer)   //如果客户端已经启动并且是本地玩家的话,可以自己准备和取消
        {
            readyBtn.onClick.AddListener(OnReadyButtonClickered);
            cancelBtn.onClick.AddListener(OnCancelButtonClicked);
        }

        if (player.isServer && !player.isLocalPlayer)  //如果是主机的话，可以在非本地的UI上显示踢出的按钮
        {
            removeBtn.gameObject.SetActive(true);
            removeBtn.onClick.AddListener(OnRemoveButtonClicked);
        }
    }

    private void Update()
    {
        //每帧更新玩家的名字和准备状态，以及自己的准备和取消按钮的显示状态
        if (playerName != null)
        {
            playerName.text = $"Player[{player.index + 1}]";    //显示玩家的名字，index是从0开始的，所以加1。这样第一个玩家就是玩家1，第二个是玩家2
        }
        if(readyState != null)
        {
            readyState.text = player.readyToBegin ? "准备" : "未准备";   //显示玩家的准备状态，如果readyToBegin是true，就显示准备，否则显示未准备
        }
        if(NetworkClient.active && player.isLocalPlayer)   //如果客户端已经启动并且是本地玩家的话,可以自己准备和取消
        {
            if (readyBtn != null && cancelBtn != null)
            {
                cancelBtn.gameObject.SetActive(player.readyToBegin);
                readyBtn.gameObject.SetActive(!player.readyToBegin);
            }
        }
    }

private void OnReadyButtonClickered()
    {
        readyBtn.gameObject.SetActive(false);
        cancelBtn.gameObject.SetActive(true);
        player.CmdChangeReadyState(true);    //将玩家的准备状态改为true
    }

    private void OnCancelButtonClicked()
    {
        cancelBtn.gameObject.SetActive(false);
        readyBtn.gameObject.SetActive(true);
        player.CmdChangeReadyState(false);   //将玩家的准备状态改为false
    }

    private void OnRemoveButtonClicked()
    {
        GetComponent<NetworkIdentity>().connectionToClient.Disconnect();    //找到他的网络连接，并断开
        if (playerPanel != null)
        {
            Destroy(playerPanel.gameObject);   //销毁大厅中该玩家的UI
        }
    }

    private void OnDestroy()
    {
        //结束时，销毁监听
        readyBtn.onClick.RemoveAllListeners();
        cancelBtn.onClick.RemoveAllListeners();
        removeBtn.onClick.RemoveAllListeners();
    }
}
