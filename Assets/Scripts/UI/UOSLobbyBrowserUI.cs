using System.Collections.Generic;
using System.Threading.Tasks;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 好友大厅面板。显示所有好友正在活跃的大厅卡片。
/// </summary>
public class UOSLobbyBrowserUI : MonoBehaviour
{
    [Header("面板")]
    [SerializeField] private GameObject panelRoot;

    [Header("列表")]
    [SerializeField] private Transform contentParent;
    [SerializeField] private UOSLobbyCardUI cardPrefab;

    [Header("操作")]
    [SerializeField] private Button refreshButton;
    [SerializeField] private Button closeButton;

    [Header("状态")]
    [SerializeField] private GameObject loadingIndicator;
    [SerializeField] private GameObject emptyHint;

    private readonly List<UOSLobbyCardUI> _cards = new List<UOSLobbyCardUI>();

    private void Awake()
    {
        if (panelRoot != null)
            panelRoot.SetActive(false);

        if (refreshButton != null)
            refreshButton.onClick.AddListener(OnRefreshClicked);

        if (closeButton != null)
            closeButton.onClick.AddListener(Hide);
    }

    public void Show()
    {
        if (panelRoot != null)
            panelRoot.SetActive(true);
        _ = RefreshLobbies();
    }

    public void Hide()
    {
        if (panelRoot != null)
            panelRoot.SetActive(false);
    }

    private void OnRefreshClicked()
    {
        _ = RefreshLobbies();
    }

    private async Task RefreshLobbies()
    {
        if (UOSFriendsManager.Instance == null) return;

        ShowLoading(true);
        ClearCards();

        var friends = await UOSFriendsManager.Instance.GetFriendList();
        if (friends.Count == 0)
        {
            ShowEmpty(true);
            ShowLoading(false);
            return;
        }

        // 批量获取 Presence
        var friendshipIDs = new List<string>();
        foreach (var f in friends)
            friendshipIDs.Add(f.Id);

        var presences = await UOSFriendsManager.Instance.GetFriendPresenceBatch(friendshipIDs);

        // 筛选：只显示 status == "in_lobby" 且有 lobby_id 的好友
        int cardCount = 0;
        foreach (var friend in friends)
        {
            if (presences == null) break;
            if (!presences.TryGetValue(friend.Id, out var presence)) continue;
            if (presence == null || presence.status != UOSFriendsConst.PresenceInLobby) continue;
            if (!presence.Properties.TryGetValue(UOSFriendsConst.PropLobbyId, out string lobbyId)) continue;

            var data = new LobbyCardData
            {
                displayName = friend.DisplayName ?? friend.TargetPersonaID,
                lobbyId = lobbyId,
                hostAddress = presence.Properties.TryGetValue(UOSFriendsConst.PropHostAddress, out string addr) ? addr : ""
            };

            var card = Instantiate(cardPrefab, contentParent);
            card.SetData(data);
            _cards.Add(card);
            cardCount++;
        }

        ShowEmpty(cardCount == 0);
        ShowLoading(false);
    }

    private void ClearCards()
    {
        foreach (var card in _cards)
        {
            if (card != null)
                Destroy(card.gameObject);
        }
        _cards.Clear();
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
