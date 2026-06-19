using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using Inbox;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 收件箱主面板。显示邮件列表，支持刷新、全部领取、删除已完成。
/// </summary>
public class UOSInboxUI : MonoBehaviour
{
    [Header("面板")]
    [SerializeField] private GameObject panelRoot;

    [Header("列表")]
    [SerializeField] private Transform contentParent;
    [SerializeField] private UOSInboxEntryUI entryPrefab;

    [Header("按钮")]
    [SerializeField] private Button refreshButton;
    [SerializeField] private Button closeButton;
    [SerializeField] private Button consumeAllButton;
    [SerializeField] private Button deleteAllButton;

    [Header("状态")]
    [SerializeField] private GameObject loadingIndicator;
    [SerializeField] private GameObject emptyHint;
    [SerializeField] private TMP_Text totalText;

    [Header("详情弹窗")]
    [SerializeField] private UOSInboxDetailUI detailPanel;

    private readonly List<UOSInboxEntryUI> _entries = new List<UOSInboxEntryUI>();

    private void Awake()
    {
        if (panelRoot != null)
            panelRoot.SetActive(false);

        if (refreshButton != null)
            refreshButton.onClick.AddListener(() => _ = Refresh());

        if (closeButton != null)
            closeButton.onClick.AddListener(Hide);

        if (consumeAllButton != null)
            consumeAllButton.onClick.AddListener(() => _ = ConsumeAll());

        if (deleteAllButton != null)
            deleteAllButton.onClick.AddListener(() => _ = DeleteAllCompleted());
    }

    public void Show()
    {
        if (panelRoot != null)
            panelRoot.SetActive(true);
        _ = Refresh();
    }

    public void Hide()
    {
        if (panelRoot != null)
            panelRoot.SetActive(false);
        if (detailPanel != null)
            detailPanel.Hide();
    }

    public async Task Refresh()
    {
        if (UOSInboxManager.Instance == null)
        {
            Debug.LogWarning("[UOSInboxUI] UOSInboxManager.Instance 为空");
            return;
        }

        ShowLoading(true);
        ClearList();

        // 先拉取新邮件
        await UOSInboxManager.Instance.ReceiveMessages();

        // 再查看收件箱
        var (total, messages) = await UOSInboxManager.Instance.GetInbox(0, 50);

        if (totalText != null)
            totalText.text = $"共 {total} 封邮件";

        if (messages.Count == 0)
        {
            ShowEmpty(true);
            ShowLoading(false);
            return;
        }

        ShowEmpty(false);

        foreach (var msg in messages)
        {
            var entry = Instantiate(entryPrefab, contentParent);
            entry.SetEntry(msg, OnEntryClicked);
            _entries.Add(entry);
        }

        ShowLoading(false);
    }

    private void OnEntryClicked(InboxMessage message)
    {
        if (detailPanel != null)
            detailPanel.Show(message, () => _ = Refresh());
    }

    private async Task ConsumeAll()
    {
        if (UOSInboxManager.Instance == null) return;

        ShowLoading(true);
        await UOSInboxManager.Instance.ConsumeAllMessages();
        _ = UOSEconomyManager.Instance?.RefreshGoldBalance();
        ShowLoading(false);

        await Refresh();
    }

    private async Task DeleteAllCompleted()
    {
        if (UOSInboxManager.Instance == null) return;

        ShowLoading(true);
        await UOSInboxManager.Instance.DeleteAllCompletedMessages();
        ShowLoading(false);

        await Refresh();
    }

    private void ClearList()
    {
        foreach (var e in _entries)
        {
            if (e != null) Destroy(e.gameObject);
        }
        _entries.Clear();
    }

    private void ShowLoading(bool show)
    {
        if (loadingIndicator != null)
            loadingIndicator.SetActive(show);
    }

    private void ShowEmpty(bool show)
    {
        if (emptyHint != null)
            emptyHint.SetActive(show);
    }
}
