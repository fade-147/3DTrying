using System.Collections.Generic;
using UnityEngine;
using TMPro;

/// <summary>
/// 排行榜 UI 面板。挂在排行榜 Canvas 根节点。
/// 公开 Show()/Hide() 供按钮绑定。
/// </summary>
public class LeaderboardUI : MonoBehaviour
{
    [Header("面板根")]
    [Tooltip("整个排行榜面板的根 GameObject（用于 Show/Hide）")]
    [SerializeField] private GameObject panelRoot;

    [Header("列表")]
    [Tooltip("ScrollView 的 Content Transform，条目会生成在这里")]
    [SerializeField] private Transform contentParent;

    [Tooltip("排行榜条目模板 prefab，子物体上挂有 LeaderboardEntryUI 组件")]
    [SerializeField] private LeaderboardEntryUI entryPrefab;

    [Header("个人排名")]
    [Tooltip("显示自己排名的 TMP_Text，如「我的排名: #3  击杀: 42」")]
    [SerializeField] private TMP_Text myRankText;

    [Header("状态提示")]
    [Tooltip("加载中转圈")]
    [SerializeField] private GameObject loadingIndicator;

    [Tooltip("排行榜为空时显示")]
    [SerializeField] private GameObject emptyHint;

    private bool _isInitialized;

    private void Awake()
    {
        if (panelRoot != null)
            panelRoot.SetActive(false);
    }

    /// <summary>
    /// 显示排行榜面板并加载数据。绑定到打开按钮的 onClick。
    /// </summary>
    public async void Show()
    {
        if (panelRoot != null)
            panelRoot.SetActive(true);

        if (!_isInitialized)
        {
            ValidateSetup();
            _isInitialized = true;
        }

        await RefreshData();
    }

    /// <summary>
    /// 隐藏面板。绑定到关闭按钮的 onClick。
    /// </summary>
    public void Hide()
    {
        if (panelRoot != null)
            panelRoot.SetActive(false);
    }

    /// <summary>
    /// 刷新数据。绑定到刷新按钮的 onClick。
    /// </summary>
    public async void Refresh()
    {
        await RefreshData();
    }

    private void ValidateSetup()
    {
        if (contentParent == null)
            Debug.LogWarning("[LeaderboardUI] 请在 Inspector 中拖入 Content Parent（ScrollView 的 Content）");
        if (entryPrefab == null)
            Debug.LogWarning("[LeaderboardUI] 请在 Inspector 中拖入 Entry Prefab（排行榜条目模板）");
    }

    private async System.Threading.Tasks.Task RefreshData()
    {
        if (UOSLeaderboard.Instance == null)
        {
            Debug.LogWarning("[LeaderboardUI] UOSLeaderboard.Instance 为空");
            return;
        }

        ShowLoading(true);

        // 并行获取排行和个人排名
        var topTask = UOSLeaderboard.Instance.GetTopRankings(50);
        var myTask = UOSLeaderboard.Instance.GetMyRank();

        await System.Threading.Tasks.Task.WhenAll(topTask, myTask);

        var rankings = topTask.Result;
        var myRank = myTask.Result;

        ShowLoading(false);
        ClearList();
        PopulateList(rankings);
        UpdateMyRank(myRank);
    }

    private void ClearList()
    {
        if (contentParent == null) return;

        foreach (Transform child in contentParent)
        {
            Destroy(child.gameObject);
        }
    }

    private void PopulateList(List<RankingEntry> rankings)
    {
        if (contentParent == null || entryPrefab == null) return;

        if (rankings.Count == 0)
        {
            if (emptyHint != null) emptyHint.SetActive(true);
            return;
        }

        if (emptyHint != null) emptyHint.SetActive(false);

        foreach (var entry in rankings)
        {
            LeaderboardEntryUI row = Instantiate(entryPrefab, contentParent);
            row.SetEntry(entry);
        }
    }

    private void UpdateMyRank(RankingEntry my)
    {
        if (myRankText != null)
        {
            if (my.Rank > 0)
                myRankText.text = $"您的排名: #{my.Rank}  击杀: {my.Score:N0}";
            else
                myRankText.text = "暂无排名数据";
        }
    }

    private void ShowLoading(bool show)
    {
        if (loadingIndicator != null)
            loadingIndicator.SetActive(show);
    }
}
