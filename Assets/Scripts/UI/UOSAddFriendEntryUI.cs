using TMPro;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 添加好友搜索结果单项。显示名字 + "发送请求"按钮。
/// </summary>
public class UOSAddFriendEntryUI : MonoBehaviour
{
    [SerializeField] private TMP_Text nameText;
    [SerializeField] private Button sendRequestButton;

    private string _personaID;
    private System.Action<string> _onSend;

    private void Awake()
    {
        if (sendRequestButton != null)
            sendRequestButton.onClick.AddListener(() => _onSend?.Invoke(_personaID));
    }

    public void SetEntry(string personaID, string displayName, System.Action<string> onSend)
    {
        _personaID = personaID;
        _onSend = onSend;
        if (nameText != null) nameText.text = displayName ?? "???";
    }
}
