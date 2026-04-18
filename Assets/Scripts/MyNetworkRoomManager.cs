using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Mirror;

public class MyNetworkRoomManager : NetworkRoomManager   //这个是官方的NetworkRoomManager，继承自NetworkManager，提供了房间管理的功能
{
    public static MyNetworkRoomManager instance;  //单例模式，方便在其他地方访问这个类的实例

    public GameObject startGameButton;

    public override void Awake()
    {
        base.Awake();  //调用父类的Awake方法，确保NetworkRoomManager的初始化逻辑被执行
        if (instance == null)
        {
            instance = this;
            DontDestroyOnLoad(gameObject);  //在加载新场景时不销毁这个对象，保持单例实例的持续存在
        }
        else
        {
            Destroy(gameObject);
        }
    }

    public override void Start()
    {
        base.Start();
        if(Utils.IsSceneActive(RoomScene)&&startGameButton != null)   //如果当前场景是房间场景，并且startGameButton不为null,先给它关闭
        {
            startGameButton.SetActive(false);
        }
    }

    public override void OnRoomServerPlayersReady()   //如果玩家都准备好了，就显示开始游戏的按钮
    {
        //base.OnRoomServerPlayersReady();
        if (Utils.IsSceneActive(RoomScene) && startGameButton != null)  
        {
            startGameButton.SetActive(true);
        }
    }

    public override void OnRoomServerPlayersNotReady()   //如果玩家没有都准备好，那么就不显示开始游戏的按钮
    {
        //base.OnRoomServerPlayersNotReady();
        if (Utils.IsSceneActive(RoomScene) && startGameButton != null)
        {
            startGameButton.SetActive(false);
        }
    }
    public override void OnGUI()
    {
        //base.OnGUI();
        if(!showRoomGUI)   //如果不显示房间GUI，就直接返回，不执行后面的代码
        {
            return;
        }
        if (!Utils.IsSceneActive(RoomScene))  //如果当前场景不是大厅的话，也不执行
        {
            return;
        }
    }

    #region UI按钮类执行逻辑
    public void StartGame()  //开始游戏的按钮
    {
        ServerChangeScene(GameplayScene);
    }
    public void ReturnToLobby()   //返回大厅的按钮
    {
        if (NetworkServer.active && Utils.IsSceneActive(GameplayScene))
        {
            ServerChangeScene(RoomScene);
        }
    }
    #endregion
}