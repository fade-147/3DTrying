using System;
using System.Threading.Tasks;
using Inbox;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 邮件详情弹窗。显示邮件正文、附件列表，提供领取/删除操作。
/// </summary>
public class UOSInboxDetailUI : MonoBehaviour
{
    [Header("面板根")]
    [SerializeField] private GameObject panelRoot;

    [Header("信息")]
    [SerializeField] private TMP_Text titleText;
    [SerializeField] private TMP_Text senderText;
    [SerializeField] private TMP_Text timeText;
    [SerializeField] private TMP_Text bodyText;

    [Header("附件")]
    [SerializeField] private Transform attachmentParent;
    [SerializeField] private GameObject attachmentEntryPrefab; // 简单 TMP_Text 条目

    [Header("按钮")]
    [SerializeField] private Button consumeButton;
    [SerializeField] private Button deleteButton;
    [SerializeField] private Button closeButton;

    [Header("状态")]
    [SerializeField] private GameObject loadingIndicator;

    private InboxMessage _currentMessage;
    private Action _onStatusChanged; // 回调通知列表刷新

    private void Awake()
    {
        if (panelRoot != null)
            panelRoot.SetActive(false);

        if (consumeButton != null)
            consumeButton.onClick.AddListener(() => _ = OnConsumeClicked());

        if (deleteButton != null)
            deleteButton.onClick.AddListener(() => _ = OnDeleteClicked());

        if (closeButton != null)
            closeButton.onClick.AddListener(Hide);
    }

    /// <summary>
    /// 显示邮件详情。
    /// </summary>
    /// <param name="message">邮件数据</param>
    /// <param name="onStatusChanged">状态变化后回调（通知列表刷新）</param>
    public void Show(InboxMessage message, Action onStatusChanged = null)
    {
        _currentMessage = message;
        _onStatusChanged = onStatusChanged;

        if (panelRoot != null)
            panelRoot.SetActive(true);

        // 标题
        if (titleText != null)
            titleText.text = message.Title ?? "(无标题)";

        // 发送方
        if (senderText != null)
            senderText.text = $"发送方：{message.Source ?? "系统"}";

        // 时间
        if (timeText != null)
        {
            if (message.SendAt != null)
            {
                var dt = message.SendAt.ToDateTime();
                timeText.text = dt.ToLocalTime().ToString("yyyy-MM-dd HH:mm");
            }
            else
            {
                timeText.text = "";
            }
        }

        // 正文
        if (bodyText != null)
            bodyText.text = message.Body ?? "";

        // 附件
        ClearAttachments();
        if (message.Attachment != null && message.Attachment.Count > 0)
        {
            foreach (var att in message.Attachment)
            {
                CreateAttachmentEntry(att);
            }
        }

        // 按钮状态
        UpdateButtonStates(message.Status);
    }

    public void Hide()
    {
        if (panelRoot != null)
            panelRoot.SetActive(false);
        _currentMessage = null;
    }

    private void UpdateButtonStates(Inbox.MessageStatusType status)
    {
        if (consumeButton != null)
        {
            // 只有 Unconsumed 状态可以领取（Unread 需要先阅读）
            consumeButton.interactable =
                status == Inbox.MessageStatusType.Unconsumed ||
                status == Inbox.MessageStatusType.Unread;
        }

        if (deleteButton != null)
        {
            // Completed 状态可以删除
            deleteButton.interactable = status == Inbox.MessageStatusType.Completed;
        }
    }

    private async Task OnConsumeClicked()
    {
        if (_currentMessage == null) return;

        // 先标记已读
        if (_currentMessage.Status == Inbox.MessageStatusType.Unread)
        {
            ShowLoading(true);
            bool readOk = await UOSInboxManager.Instance.ReadMessage(_currentMessage.Id);
            if (!readOk)
            {
                ShowLoading(false);
                return;
            }
        }

        ShowLoading(true);
        var result = await UOSInboxManager.Instance.ConsumeMessage(_currentMessage.Id);
        ShowLoading(false);

        if (result != null)
        {
            // 更新当前邮件状态
            _currentMessage = new InboxMessage(_currentMessage)
            {
                Status = Inbox.MessageStatusType.Completed
            };
            UpdateButtonStates(Inbox.MessageStatusType.Completed);

            // 通知金币刷新
            _ = UOSEconomyManager.Instance?.RefreshGoldBalance();

            // 通知列表刷新
            _onStatusChanged?.Invoke();
        }
    }

    private async Task OnDeleteClicked()
    {
        if (_currentMessage == null) return;

        ShowLoading(true);
        bool ok = await UOSInboxManager.Instance.DeleteMessage(_currentMessage.Id);
        ShowLoading(false);

        if (ok)
        {
            Hide();
            _onStatusChanged?.Invoke();
        }
    }

    private void ClearAttachments()
    {
        if (attachmentParent == null) return;
        foreach (Transform child in attachmentParent)
        {
            Destroy(child.gameObject);
        }
    }

    private void CreateAttachmentEntry(AttachmentItem item)
    {
        if (attachmentParent == null || attachmentEntryPrefab == null) return;

        var go = Instantiate(attachmentEntryPrefab, attachmentParent);
        var label = go.GetComponentInChildren<TMP_Text>();
        if (label != null)
        {
            string resName = item.Resource != null && !string.IsNullOrEmpty(item.Resource.DisplayName)
                ? item.Resource.DisplayName
                : item.ItemSlug;
            label.text = $"{resName} × {item.Quantity}";
        }
    }

    private void ShowLoading(bool show)
    {
        if (loadingIndicator != null)
            loadingIndicator.SetActive(show);
    }
}
