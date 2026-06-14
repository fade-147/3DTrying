using UnityEngine;

public class StartSinglePlayerButton : MonoBehaviour
{
    public void OnClick() => MyNetworkRoomManager.instance.StartSinglePlayer();
}
