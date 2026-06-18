using TMPro;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 好友请求单项。显示请求者名字 + "接受"/"拒绝"按钮。
/// </summary>
public class UOSRequestEntryUI : MonoBehaviour
{
    [SerializeField] private TMP_Text nameText;
    [SerializeField] private Button acceptButton;
    [SerializeField] private Button rejectButton;

    private string _requestID;
    private System.Action<string> _onAccept;
    private System.Action<string> _onReject;

    private void Awake()
    {
        if (acceptButton != null)
            acceptButton.onClick.AddListener(() => _onAccept?.Invoke(_requestID));
        if (rejectButton != null)
            rejectButton.onClick.AddListener(() => _onReject?.Invoke(_requestID));
    }

    public void SetEntry(string requestID, string displayName,
        System.Action<string> onAccept, System.Action<string> onReject)
    {
        _requestID = requestID;
        _onAccept = onAccept;
        _onReject = onReject;
        if (nameText != null) nameText.text = displayName ?? "???";
    }
}
