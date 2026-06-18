using Steamworks;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 好友大厅卡片 UI。挂在 LobbyCard prefab 上。
/// 每个卡片显示好友名字 + 加入按钮。
/// </summary>
public class UOSLobbyCardUI : MonoBehaviour
{
    [Header("UI 元素")]
    [SerializeField] private Image backgroundImage;
    [SerializeField] private TMP_Text friendNameText;
    [SerializeField] private Button joinButton;

    private LobbyCardData _data;

    private void Awake()
    {
        if (joinButton != null)
            joinButton.onClick.AddListener(OnJoinClicked);
    }

    /// <summary>
    /// 填充大厅卡片数据。
    /// </summary>
    public void SetData(LobbyCardData data)
    {
        _data = data;

        if (friendNameText != null)
            friendNameText.text = $"{data.displayName} 的房间";
    }

    private void OnJoinClicked()
    {
        if (_data == null) return;

        // 通过 Lobby ID 加入 Steam 大厅
        if (ulong.TryParse(_data.lobbyId, out ulong lobbyId))
        {
            Debug.Log($"[UOSLobbyCard] 加入好友大厅: {_data.displayName}, lobbyId={_data.lobbyId}");
            SteamMatchmaking.JoinLobby(new CSteamID(lobbyId));
        }
        else
        {
            Debug.LogError($"[UOSLobbyCard] Lobby ID 解析失败: {_data.lobbyId}");
        }
    }
}

/// <summary>
/// 大厅卡片数据模型。
/// </summary>
public class LobbyCardData
{
    public string displayName;
    public string lobbyId;
    public string hostAddress;
}
