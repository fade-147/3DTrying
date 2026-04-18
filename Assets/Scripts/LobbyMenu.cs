using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class LobbyMenu : MonoBehaviour
{
    [SerializeField]
    GameObject startButton;
    [SerializeField]
    Text debugText;

    private void Awake()
    {
        MyNetworkRoomManager.instance.startGameButton = startButton;
    }
    private void Start()
    {
        startButton.SetActive(false);
    }
    public void StartGame()
    {
        MyNetworkRoomManager.instance.StartGame();  //在这里执行开始游戏
    }
}
