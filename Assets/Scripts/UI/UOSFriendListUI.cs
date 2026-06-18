using System.Collections.Generic;
using System.Threading.Tasks;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 好友列表面板。显示已有好友 + 刷新 + "添加好友"按钮 + "好友申请"按钮。
/// </summary>
public class UOSFriendListUI : MonoBehaviour
{
    [Header("面板")]
    [SerializeField] private GameObject panelRoot;

    [Header("列表")]
    [SerializeField] private Transform contentParent;
    [SerializeField] private UOSFriendEntryUI entryPrefab;

    [Header("按钮")]
    [SerializeField] private Button refreshButton;
    [SerializeField] private Button addFriendButton;
    [SerializeField] private Button friendRequestsButton;

    [Header("子面板")]
    [SerializeField] private UOSAddFriendUI addFriendPanel;
    [SerializeField] private UOSFriendRequestsUI friendRequestsPanel;

    [Header("状态")]
    [SerializeField] private GameObject loadingIndicator;
    [SerializeField] private GameObject emptyHint;

    private readonly List<UOSFriendEntryUI> _entries = new List<UOSFriendEntryUI>();

    private void Awake()
    {
        if (panelRoot != null)
            panelRoot.SetActive(false);

        if (refreshButton != null)
            refreshButton.onClick.AddListener(() => _ = Refresh());

        if (addFriendButton != null)
            addFriendButton.onClick.AddListener(OpenAddFriend);

        if (friendRequestsButton != null)
            friendRequestsButton.onClick.AddListener(OpenFriendRequests);
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
    }

    public async Task Refresh()
    {
        if (UOSFriendsManager.Instance == null) return;

        ShowLoading(true);
        ClearList();

        var friends = await UOSFriendsManager.Instance.GetFriendList();
        if (friends.Count == 0)
        {
            ShowEmpty(true);
            ShowLoading(false);
            return;
        }

        var ids = new List<string>();
        foreach (var f in friends) ids.Add(f.Id);
        var presences = await UOSFriendsManager.Instance.GetFriendPresenceBatch(ids);

        foreach (var friend in friends)
        {
            string status = UOSFriendsConst.PresenceOnline;
            if (presences != null && presences.TryGetValue(friend.Id, out var p)
                && p != null && !string.IsNullOrEmpty(p.status))
                status = p.status;

            var entry = Instantiate(entryPrefab, contentParent);
            entry.SetEntry(friend.Id, friend.DisplayName ?? friend.TargetPersonaID,
                status, OnDeleteFriend);
            _entries.Add(entry);
        }

        ShowEmpty(false);
        ShowLoading(false);
    }

    private async void OnDeleteFriend(string friendshipID)
    {
        if (UOSFriendsManager.Instance == null) return;
        if (await UOSFriendsManager.Instance.RemoveFriend(friendshipID))
            _ = Refresh();
    }

    private void OpenAddFriend()
    {
        if (addFriendPanel != null) addFriendPanel.Show();
    }

    private void OpenFriendRequests()
    {
        if (friendRequestsPanel != null) friendRequestsPanel.Show();
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
