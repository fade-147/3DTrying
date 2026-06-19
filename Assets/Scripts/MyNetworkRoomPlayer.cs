using Mirror;
using UnityEngine;
using UnityEngine.PlayerLoop;

// 继承Mirror的NetworkRoomPlayer，保留所有原生功能，只加我们自己的队伍逻辑
public class MyNetworkRoomPlayer : NetworkRoomPlayer
{
    // 队伍ID：0=红队，1=蓝队，后续可以扩展更多
    [SyncVar(hook = nameof(OnTeamIdChanged))]
    public int teamId = 0;

    /// <summary>玩家昵称（从 PlayerPrefs 上传，大厅 UI 显示用）</summary>
    [SyncVar]
    public string playerName = "";

    // 队伍人数上限（可自己改，比如4v4就设4）
    public const int MAX_PER_TEAM = 4;

    // 队伍变化的Hook：当服务器修改teamId，所有客户端会自动触发这个函数
    private void OnTeamIdChanged(int oldTeam, int newTeam)
    {
        // 通知UI更新，让玩家面板自动跑到对应队伍的列表里
        GetComponent<RoomPlayerGUI>()?.UpdateTeamUI(newTeam);
    }

    public override void OnClientEnterRoom()
    {
        base.OnClientEnterRoom();
        GetComponent<RoomPlayerGUI>()?.InitializeUI();

        // 上传本地玩家昵称到服务端
        if (isLocalPlayer)
        {
            string name = PlayerNameUtility.GetSavedUserName();
            if (!string.IsNullOrEmpty(name))
                CmdSetPlayerName(name);
        }
    }

    /// <summary>[Command] 服务端设置玩家昵称</summary>
    [Command]
    public void CmdSetPlayerName(string name)
    {
        playerName = name;
    }

    public override void OnClientExitRoom()
    {
        base.OnClientExitRoom();
        GetComponent<RoomPlayerGUI>()?.DestroyUI();
    }

    // 客户端点击切换队伍，发送命令给服务器
    [Command]
    public void CmdSwitchTeam()
    {
        // 只有服务器能处理队伍变更
        if (!isServer) return;

        // 场景过渡期间禁止换队——此时 roomSlots 和场景状态可能不一致，
        // 且 CmdChangeReadyState 可能干扰 CheckReadyToBegin 流程
        if (MyNetworkRoomManager.instance != null
            && !Utils.IsSceneActive(MyNetworkRoomManager.instance.RoomScene))
        {
            Debug.Log("[MyNetworkRoomPlayer] 当前不在房间场景，无法切换队伍");
            return;
        }

        //确保RoomManager实例存在
        if (MyNetworkRoomManager.instance == null)
        {
            Debug.LogError("[MyNetworkRoomPlayer] CmdSwitchTeam: MyNetworkRoomManager.instance 为空！");
            return;
        }

        // 统计当前两个队伍的人数
        int team1Count = 0, team2Count = 0;
        foreach (var slot in MyNetworkRoomManager.instance.roomSlots)
        {
            if (slot is MyNetworkRoomPlayer player)
            {
                if (player.teamId == 0) team1Count++;
                else team2Count++;
            }
        }

        //计算要切换到的目标队伍
        int targetTeam = teamId == 0 ? 1 : 0;

        //  检查目标队伍是否已满
        if ((targetTeam == 0 && team1Count >= MAX_PER_TEAM) ||
            (targetTeam == 1 && team2Count >= MAX_PER_TEAM))
        {
            Debug.Log("目标队伍已满，无法切换");
            return;
        }

        // 执行队伍切换
        this.teamId = targetTeam;

        // 切换队伍后，自动取消准备，防止所有人都准备好时有人偷偷换队
        this.SetReadyToBegin(false);

        // 通知 RoomManager 更新 allPlayersReady 状态
        // SetReadyToBegin 只改 SyncVar，不会触发 ReadyStatusChanged，
        // 不调用会导致 allPlayersReady 与实际状态不一致
        if (MyNetworkRoomManager.instance != null)
            MyNetworkRoomManager.instance.ReadyStatusChanged();
    }

    
}