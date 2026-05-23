using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class LobbyMenu : MonoBehaviour
{
    [SerializeField] GameObject startButton;
    [SerializeField] Text debugText;
    [SerializeField] Button addRedBotButton;
    [SerializeField] Button addBlueBotButton;

    private void Awake()
    {
        MyNetworkRoomManager.instance.startGameButton = startButton;
    }
    void Start()
    {
        startButton.SetActive(false);

        if (addRedBotButton != null)
            addRedBotButton.onClick.AddListener(() => MyNetworkRoomManager.instance.AddBot(0));
        if (addBlueBotButton != null)
            addBlueBotButton.onClick.AddListener(() => MyNetworkRoomManager.instance.AddBot(1));
    }
    public void StartGame()
    {
        MyNetworkRoomManager.instance.StartGame();
    }
}
