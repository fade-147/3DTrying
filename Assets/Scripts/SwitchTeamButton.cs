using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SwitchTeamButton : MonoBehaviour
{
    public void OnClick()
    {
        // 找到本地玩家
        foreach (var player in FindObjectsOfType<MyNetworkRoomPlayer>())
        {
            if (player.isLocalPlayer)
            {
                player.CmdSwitchTeam();
                break;
            }
        }
    }
}
