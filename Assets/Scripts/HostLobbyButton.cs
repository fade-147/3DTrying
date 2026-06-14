using UnityEngine;

public class HostLobbyButton : MonoBehaviour
{
    public void OnClick() => SteamLobby.Instance.HostLobby();
}
