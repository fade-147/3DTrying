using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 添加好友弹窗。输入名字搜索 → 结果列表 → 发送请求。
/// </summary>
public class UOSAddFriendUI : MonoBehaviour
{
    [Header("面板")]
    [SerializeField] private GameObject panelRoot;

    [Header("搜索")]
    [SerializeField] private TMP_InputField searchInput;
    [SerializeField] private Button searchButton;

    [Header("结果列表")]
    [SerializeField] private Transform contentParent;
    [SerializeField] private UOSAddFriendEntryUI entryPrefab;

    [Header("状态")]
    [SerializeField] private GameObject loadingIndicator;
    [SerializeField] private GameObject emptyHint;

    [Header("关闭")]
    [SerializeField] private Button closeButton;

    private readonly List<UOSAddFriendEntryUI> _entries = new List<UOSAddFriendEntryUI>();

    private void Awake()
    {
        if (panelRoot != null) panelRoot.SetActive(false);
        if (searchButton != null) searchButton.onClick.AddListener(() => _ = Search());
        if (closeButton != null) closeButton.onClick.AddListener(Hide);
    }

    public void Show()
    {
        if (panelRoot != null) panelRoot.SetActive(true);
        ClearResults();
        if (searchInput != null) searchInput.text = "";
    }

    public void Hide()
    {
        if (panelRoot != null) panelRoot.SetActive(false);
    }

    private async System.Threading.Tasks.Task Search()
    {
        if (UOSFriendsManager.Instance == null) return;
        if (searchInput == null) return;
        string query = searchInput.text.Trim();
        if (string.IsNullOrEmpty(query)) return;

        ShowLoading(true);
        ClearResults();

        var personas = await UOSFriendsManager.Instance.SearchByDisplayName(query);
        if (personas.Count == 0)
        {
            ShowEmpty(true);
            ShowLoading(false);
            return;
        }

        foreach (var p in personas)
        {
            var entry = Instantiate(entryPrefab, contentParent);
            entry.SetEntry(p.PersonaID, p.DisplayName ?? p.PersonaID, OnSendRequest);
            _entries.Add(entry);
        }

        ShowEmpty(false);
        ShowLoading(false);
    }

    private async void OnSendRequest(string personaID)
    {
        if (UOSFriendsManager.Instance == null) return;
        bool ok = await UOSFriendsManager.Instance.SendFriendRequest(personaID);
        Debug.Log(ok
            ? $"[UOSAddFriendUI] 好友请求已发送 → {personaID}"
            : $"[UOSAddFriendUI] 发送失败 → {personaID}");
    }

    private void ClearResults()
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
