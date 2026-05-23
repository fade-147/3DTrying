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
    MyNetworkRoomPlayer player;


    public void InitializeUI()
    {
        player = GetComponent<MyNetworkRoomPlayer>();
        
        // 关键防拷贝！如果已经有旧的UI面板，我们应该先把它销毁或剔除！以免界面堆积很多个重复玩家！
        if (playerPanel != null)
        {
            Destroy(playerPanel);
        }

        // 根据队伍ID，找到对应的UI容器
        Transform teamContainer = GetTeamContainer(player.teamId);
        // 实例化玩家面板到对应的队伍容器里
        playerPanel = Instantiate(playerPanelPrefab, teamContainer) as GameObject;

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

    public void DestroyUI()
    {
        if (playerPanel != null)
        {
            Destroy(playerPanel);
        }
    }

    // 队伍变化时，更新UI面板的位置
    public void UpdateTeamUI(int newTeamId)
    {
        if (playerPanel == null) return;

        // 把面板移动到新队伍的容器里
        Transform newContainer = GetTeamContainer(newTeamId);
        playerPanel.transform.SetParent(newContainer);
        playerPanel.transform.localScale = Vector3.one; // 修复UGUI缩放问题
    }

    // 根据队伍ID获取对应的UI容器
    private Transform GetTeamContainer(int teamId)
    {
        if (teamId == 0)
        {
            // 红队的列表容器
            return GameObject.FindWithTag("Team1PlayerList").transform;
        }
        else
        {
            // 蓝队的列表容器
            return GameObject.FindWithTag("Team2PlayerList").transform;
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
