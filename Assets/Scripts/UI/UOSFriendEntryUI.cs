using TMPro;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 好友列表单项。显示好友名字 + 在线状态 + 删除按钮。
/// </summary>
public class UOSFriendEntryUI : MonoBehaviour
{
    [SerializeField] private TMP_Text nameText;
    [SerializeField] private TMP_Text statusText;
    [SerializeField] private Button deleteButton;

    private string _friendshipID;
    private System.Action<string> _onDelete;

    private void Awake()
    {
        if (deleteButton != null)
            deleteButton.onClick.AddListener(() => _onDelete?.Invoke(_friendshipID));
    }

    public void SetEntry(string friendshipID, string displayName, string status,
        System.Action<string> onDelete)
    {
        _friendshipID = friendshipID;
        _onDelete = onDelete;

        if (nameText != null)
            nameText.text = displayName ?? "???";

        if (statusText != null)
        {
            statusText.text = status switch
            {
                UOSFriendsConst.PresenceInLobby => "在大厅",
                UOSFriendsConst.PresenceInGame => "游戏中",
                _ => "在线"
            };
        }
    }
}
