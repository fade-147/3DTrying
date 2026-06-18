using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 好友请求面板。显示待处理的收到请求，接受/拒绝。
/// </summary>
public class UOSFriendRequestsUI : MonoBehaviour
{
    [Header("面板")]
    [SerializeField] private GameObject panelRoot;

    [Header("列表")]
    [SerializeField] private Transform contentParent;
    [SerializeField] private UOSRequestEntryUI entryPrefab;

    [Header("操作")]
    [SerializeField] private Button refreshButton;

    [Header("状态")]
    [SerializeField] private GameObject loadingIndicator;
    [SerializeField] private GameObject emptyHint;

    [Header("关闭")]
    [SerializeField] private Button closeButton;

    private readonly List<UOSRequestEntryUI> _entries = new List<UOSRequestEntryUI>();

    private void Awake()
    {
        if (panelRoot != null) panelRoot.SetActive(false);
        if (refreshButton != null) refreshButton.onClick.AddListener(() => _ = Refresh());
        if (closeButton != null) closeButton.onClick.AddListener(Hide);
    }

    public void Show()
    {
        if (panelRoot != null) panelRoot.SetActive(true);
        _ = Refresh();
    }

    public void Hide()
    {
        if (panelRoot != null) panelRoot.SetActive(false);
    }

    private async System.Threading.Tasks.Task Refresh()
    {
        if (UOSFriendsManager.Instance == null) return;

        ShowLoading(true);
        ClearList();

        var requests = await UOSFriendsManager.Instance.GetReceivedRequests();
        if (requests.Count == 0)
        {
            ShowEmpty(true);
            ShowLoading(false);
            return;
        }

        foreach (var req in requests)
        {
            var entry = Instantiate(entryPrefab, contentParent);
            entry.SetEntry(req.Id, req.SourceDisplayName ?? req.SourcePersonaID,
                OnAccept, OnReject);
            _entries.Add(entry);
        }

        ShowEmpty(false);
        ShowLoading(false);
    }

    private async void OnAccept(string requestID)
    {
        if (UOSFriendsManager.Instance == null) return;
        if (await UOSFriendsManager.Instance.ApproveFriendRequest(requestID))
            _ = Refresh();
    }

    private async void OnReject(string requestID)
    {
        if (UOSFriendsManager.Instance == null) return;
        if (await UOSFriendsManager.Instance.RejectFriendRequest(requestID))
            _ = Refresh();
    }

    private void ClearList()
    {
        foreach (var e in _entries) { if (e != null) Destroy(e.gameObject); }
        _entries.Clear();
    }

    private void ShowLoading(bool show)
    {
        if (loadingIndicator != null) loadingIndicator.SetActive(show);
    }

    private void ShowEmpty(bool show)
    {
        if (emptyHint != null) emptyHint.SetActive(show);
    }
}
