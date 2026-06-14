using UnityEngine;

public class LeaveRoomButton : MonoBehaviour
{
    public void OnClick()
    {
        MyNetworkRoomManager.instance.LeaveRoom();
    }
}
