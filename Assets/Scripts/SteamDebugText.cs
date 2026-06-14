using UnityEngine;
using UnityEngine.UI;

/// <summary>挂到 StartScene 的调试 Text 上，Start 时自动绑定到 SteamLobby 单例。</summary>
public class SteamDebugText : MonoBehaviour
{
    void Start()
    {
        if (SteamLobby.Instance != null)
            SteamLobby.Instance.BindDebugText(GetComponent<Text>());
    }
}
