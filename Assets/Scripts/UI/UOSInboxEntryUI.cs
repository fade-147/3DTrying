using System;
using Inbox;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 收件箱邮件列表条目。显示邮件标题、时间、状态图标。
/// </summary>
public class UOSInboxEntryUI : MonoBehaviour
{
    [Header("UI 元素")]
    [SerializeField] private TMP_Text titleText;
    [SerializeField] private TMP_Text timeText;
    [SerializeField] private Image statusIcon;
    [SerializeField] private Button button;

    /// <summary>未读状态颜色</summary>
    [Header("状态颜色")]
    [SerializeField] private Color unreadColor = new Color(0.9f, 0.2f, 0.2f);   // 红色
    [SerializeField] private Color unconsumedColor = new Color(0.9f, 0.7f, 0.1f); // 黄色
    [SerializeField] private Color completedColor = new Color(0.5f, 0.5f, 0.5f);   // 灰色

    private InboxMessage _message;
    private Action<InboxMessage> _onClick;

    private void Awake()
    {
        if (button != null)
            button.onClick.AddListener(OnButtonClicked);
    }

    private void OnDestroy()
    {
        if (button != null)
            button.onClick.RemoveListener(OnButtonClicked);
    }

    /// <summary>
    /// 设置条目数据。
    /// </summary>
    /// <param name="message">邮件数据</param>
    /// <param name="onClick">点击回调</param>
    public void SetEntry(InboxMessage message, Action<InboxMessage> onClick)
    {
        _message = message;
        _onClick = onClick;

        if (titleText != null)
            titleText.text = message.Title ?? "(无标题)";

        if (timeText != null)
        {
            if (message.SendAt != null)
            {
                var dt = message.SendAt.ToDateTime();
                timeText.text = dt.ToLocalTime().ToString("MM-dd HH:mm");
            }
            else
            {
                timeText.text = "";
            }
        }

        UpdateStatusIcon(message.Status);
    }

    private void UpdateStatusIcon(Inbox.MessageStatusType status)
    {
        if (statusIcon == null) return;

        switch (status)
        {
            case Inbox.MessageStatusType.Unread:
                statusIcon.color = unreadColor;
                break;
            case Inbox.MessageStatusType.Unconsumed:
                statusIcon.color = unconsumedColor;
                break;
            case Inbox.MessageStatusType.Completed:
                statusIcon.color = completedColor;
                break;
            default:
                statusIcon.color = completedColor;
                break;
        }
    }

    private void OnButtonClicked()
    {
        _onClick?.Invoke(_message);
    }
}
