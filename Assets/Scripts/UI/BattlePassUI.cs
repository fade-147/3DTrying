using System;
using System.Collections;
using System.Collections.Generic;
using System.Threading.Tasks;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class BattlePassUI : MonoBehaviour
{
    [Header("面板根")]
    [SerializeField] private GameObject panelRoot;

    [Header("节点列表")]
    [SerializeField] private Transform nodesContainer;
    [SerializeField] private BattlePassNodeUI nodePrefab;

    [Header("进度条")]
    [SerializeField] private Image progressFill;
    [SerializeField] private RectTransform progressBarRect;

    [Header("文字")]
    [SerializeField] private TMP_Text progressText;
    [SerializeField] private TMP_Text availableLabel;

    [Header("按钮")]
    [SerializeField] private Button closeButton;
    [SerializeField] private Button refreshButton;
    [SerializeField] private Button claimAllButton;

    [Header("滚动")]
    [SerializeField] private ScrollRect nodesScrollRect;

    [Header("状态")]
    [SerializeField] private GameObject loadingIndicator;

    [Header("弹窗")]
    [SerializeField] private BattlePassRewardPopup rewardPopup;

    // ── 虚拟滚动 ──
    private const int PoolSize = 12;
    private const float NodeUnitWidth = 140f;
    private const float NodeHalfWidth = 50f;
    private const float ScrollAnimDuration = 0.35f;
    private const float SnapDelay = 0.4f;

    private List<BattlePassNodeUI> _pool;
    private int _totalNodes;
    private int _firstVisibleIndex = -1;
    private int _totalKills;
    private int _claimedKills;
    private float _viewportHalf;
    private float _leftPad;

    private bool _isInitialized;
    private bool _isLoading;
    private Coroutine _scrollAnim;
    private float _snapTimer;
    private bool _snapPending;
    private bool _scrollCfgReady;

    // 正在异步领取的节点——回收时视为 Claimed
    private readonly HashSet<int> _pendingClaims = new HashSet<int>();

    private void Awake()
    {
        if (panelRoot != null)
            panelRoot.SetActive(false);

        if (closeButton != null)
            closeButton.onClick.AddListener(Hide);
        if (refreshButton != null)
            refreshButton.onClick.AddListener(() => _ = Refresh());
        if (claimAllButton != null)
            claimAllButton.onClick.AddListener(() => ClaimAll());

        InitializePool();
    }

    /// <summary>
    /// 配置 ScrollRect（阻尼 + 惯性 + 事件）。
    /// 从 Awake 或 Show 调用，由 _scrollCfgReady 保证只执行一次。
    /// </summary>
    private void ConfigureScrollRect()
    {
        if (_scrollCfgReady) return;
        if (nodesScrollRect == null) return;

        // 渐进式阻尼：Elastic + 极低 elasticity → 弹簧极硬，拖越多阻力越大
        nodesScrollRect.movementType = ScrollRect.MovementType.Elastic;
        nodesScrollRect.elasticity = 0.05f;
        nodesScrollRect.inertia = true;
        nodesScrollRect.decelerationRate = 0.08f;
        nodesScrollRect.onValueChanged.AddListener(OnScrollChanged);
        _scrollCfgReady = true;

        Debug.Log("[BattlePassUI] ScrollRect 已配置: Elastic, elasticity=0.05, decelerationRate=0.08");
    }

    public async void Show()
    {
        if (panelRoot != null)
            panelRoot.SetActive(true);

        if (!_isInitialized)
        {
            ValidateSetup();
            _isInitialized = true;
        }

        _firstVisibleIndex = -1;
        ConfigureScrollRect();

        // 等两帧让 Unity Layout 完成：第1帧 VerticalLayoutGroup 生效，第2帧 ScrollRect 更新
        await Task.Yield();
        await Task.Yield();

        // 强制刷新 Canvas 布局后再读尺寸
        Canvas.ForceUpdateCanvases();

        if (nodesScrollRect != null && nodesScrollRect.viewport != null)
        {
            _viewportHalf = nodesScrollRect.viewport.rect.width * 0.5f;
            Debug.Log($"[BattlePassUI] Viewport rect.width = {nodesScrollRect.viewport.rect.width}, _viewportHalf = {_viewportHalf}");
        }
        else
        {
            _viewportHalf = 360f;
            Debug.LogWarning("[BattlePassUI] nodesScrollRect 或 viewport 为空，使用默认 _viewportHalf=360");
        }

        _leftPad = _viewportHalf;

        await Refresh();

        // 再等一帧确保 Content 尺寸生效
        await Task.Yield();
        Canvas.ForceUpdateCanvases();
        ScrollToIndex(GetSnapTargetIndex(), smooth: false);
    }

    public void Hide()
    {
        if (panelRoot != null)
            panelRoot.SetActive(false);
    }

    public async Task<int> Refresh()
    {
        if (_isLoading) return 0;
        _isLoading = true;

        ShowLoading(true);
        int available = 0;

        try
        {
            var mgr = UOSBattlePassManager.Instance;
            var (totalKills, claimedKills, availableCount) = await mgr.GetStatus();

            _totalKills = totalKills;
            _claimedKills = claimedKills;
            available = availableCount;

            UpdateTotalNodes(totalKills);
            UpdateProgress(totalKills);
            UpdateAvailableLabel(availableCount);
            RecycleNodes();

            Debug.Log($"[BattlePassUI] Refresh: totalKills={totalKills}, claimedKills={claimedKills}, " +
                $"totalNodes={_totalNodes}, contentWidth={_leftPad * 2f + _totalNodes * NodeUnitWidth:F0}, " +
                $"viewportHalf={_viewportHalf:F0}");
        }
        catch (Exception ex)
        {
            Debug.LogError($"[BattlePassUI] 刷新失败: {ex.Message}");
        }
        finally
        {
            ShowLoading(false);
            _isLoading = false;
        }

        return available;
    }

    // ═══════════════════════════════════════════
    //  虚拟滚动
    // ═══════════════════════════════════════════

    private void InitializePool()
    {
        if (nodesContainer == null || nodePrefab == null) return;
        _pool = new List<BattlePassNodeUI>(PoolSize);
        for (int i = 0; i < PoolSize; i++)
        {
            var node = Instantiate(nodePrefab, nodesContainer);
            node.gameObject.SetActive(false);
            _pool.Add(node);
        }
    }

    private void UpdateTotalNodes(int totalKills)
    {
        int reachedNodes = totalKills / UOSBattlePassManager.KillsPerTier;
        _totalNodes = Mathf.Max(reachedNodes + 10, PoolSize);
    }

    private void OnScrollChanged(Vector2 _)
    {
        RecycleNodes();
        _snapTimer = SnapDelay;
        if (!_snapPending)
            StartCoroutine(SnapCo());
    }

    private IEnumerator SnapCo()
    {
        _snapPending = true;
        while (_snapTimer > 0f)
        {
            _snapTimer -= Time.unscaledDeltaTime;
            yield return null;
        }
        _snapPending = false;

        if (!_isLoading && panelRoot != null && panelRoot.activeSelf)
            ScrollToIndex(GetSnapTargetIndex(), smooth: true);
    }

    private void RecycleNodes()
    {
        if (_pool == null || nodesContainer == null) return;

        var contentRT = nodesContainer.parent.GetComponent<RectTransform>();
        if (contentRT == null) return;

        float nodeAreaWidth = _totalNodes * NodeUnitWidth;
        float contentWidth = _leftPad * 2f + nodeAreaWidth;

        // Content 总宽 = 左右 padding + 节点区
        contentRT.sizeDelta = new Vector2(contentWidth, contentRT.sizeDelta.y);

        // NodesRow：pivot 设左边缘，anchoredPosition.x=0 → 节点坐标直接对应 Content 空间
        var nodesRowRT = nodesContainer as RectTransform;
        nodesRowRT.pivot = new Vector2(0f, nodesRowRT.pivot.y);
        nodesRowRT.anchorMin = new Vector2(0f, nodesRowRT.anchorMin.y);
        nodesRowRT.anchorMax = new Vector2(0f, nodesRowRT.anchorMax.y);
        nodesRowRT.anchoredPosition = new Vector2(0f, nodesRowRT.anchoredPosition.y);

        // 进度条：pivot 设左边缘，anchoredPosition.x=_leftPad → 左边缘对齐第一个节点
        if (progressBarRect != null)
        {
            progressBarRect.pivot = new Vector2(0f, progressBarRect.pivot.y);
            progressBarRect.sizeDelta = new Vector2(nodeAreaWidth, progressBarRect.sizeDelta.y);
            progressBarRect.anchoredPosition = new Vector2(_leftPad, progressBarRect.anchoredPosition.y);
        }

        float scrollX = -contentRT.anchoredPosition.x;
        int newFirst = Mathf.FloorToInt((scrollX - _leftPad) / NodeUnitWidth);
        newFirst = Mathf.Clamp(newFirst, 0, Mathf.Max(0, _totalNodes - PoolSize));

        if (newFirst == _firstVisibleIndex) return;
        _firstVisibleIndex = newFirst;

        for (int slot = 0; slot < _pool.Count; slot++)
        {
            int tierIndex = _firstVisibleIndex + slot;
            var node = _pool[slot];

            if (tierIndex < _totalNodes)
            {
                node.gameObject.SetActive(true);
                float x = _leftPad + tierIndex * NodeUnitWidth;
                node.SetPositionX(x);

                BattlePassNodeState state = GetNodeState(tierIndex);
                node.Setup(tierIndex, state, OnNodeClaim);
            }
            else
            {
                node.gameObject.SetActive(false);
            }
        }
    }

    private BattlePassNodeState GetNodeState(int tierIndex)
    {
        int requiredKills = (tierIndex + 1) * UOSBattlePassManager.KillsPerTier;

        // pending 中的节点视为已领取，防止滑动回收时按钮重现
        if (_pendingClaims.Contains(tierIndex))
            return BattlePassNodeState.Claimed;

        if (_claimedKills >= requiredKills)
            return BattlePassNodeState.Claimed;
        if (_totalKills >= requiredKills)
            return BattlePassNodeState.Available;
        return BattlePassNodeState.Locked;
    }

    private float GetSnapTargetIndex()
    {
        int reachedNodes = _totalKills / UOSBattlePassManager.KillsPerTier;
        int claimedNodes = _claimedKills / UOSBattlePassManager.KillsPerTier;
        if (claimedNodes < reachedNodes)
            return claimedNodes;
        if (reachedNodes > 0)
            return reachedNodes - 0.5f;
        return 0f;
    }

    private void ScrollToIndex(float index, bool smooth)
    {
        if (nodesScrollRect == null || nodesContainer == null) return;

        var contentRT = nodesContainer.parent.GetComponent<RectTransform>();
        if (contentRT == null) return;

        float nodeAreaWidth = _totalNodes * NodeUnitWidth;
        float contentWidth = _leftPad * 2f + nodeAreaWidth;
        float viewportWidth = nodesScrollRect.viewport != null
            ? nodesScrollRect.viewport.rect.width
            : _viewportHalf * 2f;

        if (contentWidth <= viewportWidth || viewportWidth <= 0f) return;

        // 指定浮点索引在 Content 空间的中心 X
        float targetCenterX = _leftPad + index * NodeUnitWidth + NodeHalfWidth;

        // Content.anchoredPosition.x:
        //   0     = Content 左边缘对齐 Viewport 左边缘
        //   负值  = Content 左移 → 看到右侧内容
        float targetContentX = -(targetCenterX - viewportWidth * 0.5f);

        float minX = -(contentWidth - viewportWidth);
        float maxX = 0f;
        targetContentX = Mathf.Clamp(targetContentX, minX, maxX);

        if (!smooth)
        {
            nodesScrollRect.velocity = Vector2.zero;
            contentRT.anchoredPosition = new Vector2(targetContentX, contentRT.anchoredPosition.y);
            RecycleNodes();
            return;
        }

        if (_scrollAnim != null)
            StopCoroutine(_scrollAnim);
        _scrollAnim = StartCoroutine(AnimateScroll(contentRT, targetContentX));
    }

    private IEnumerator AnimateScroll(RectTransform contentRT, float targetX)
    {
        float startX = contentRT.anchoredPosition.x;
        float elapsed = 0f;
        while (elapsed < ScrollAnimDuration)
        {
            elapsed += Time.unscaledDeltaTime;
            float t = Mathf.Clamp01(elapsed / ScrollAnimDuration);
            t = 1f - (1f - t) * (1f - t);
            contentRT.anchoredPosition = new Vector2(
                Mathf.Lerp(startX, targetX, t),
                contentRT.anchoredPosition.y);
            RecycleNodes();
            yield return null;
        }
        contentRT.anchoredPosition = new Vector2(targetX, contentRT.anchoredPosition.y);
        RecycleNodes();
        _scrollAnim = null;
    }

    // ═══════════════════════════════════════════
    //  UI
    // ═══════════════════════════════════════════

    private void UpdateProgress(int totalKills)
    {
        // fillAmount 相对于节点区：killTier / _totalNodes
        float killTier = (float)totalKills / UOSBattlePassManager.KillsPerTier;
        float progress = 0f;
        if (_totalNodes > 0)
            progress = Mathf.Clamp01(killTier / _totalNodes);

        if (progressFill != null)
            progressFill.fillAmount = progress;

        int currentTierKills = totalKills % UOSBattlePassManager.KillsPerTier;
        if (progressText != null)
        {
            progressText.text = $"{currentTierKills}/{UOSBattlePassManager.KillsPerTier} 击杀"
                + $" (距下一里程碑还需 {UOSBattlePassManager.KillsPerTier - currentTierKills} 杀)";
        }
    }

    private void UpdateAvailableLabel(int availableCount)
    {
        if (availableLabel != null)
        {
            if (availableCount > 0)
                availableLabel.text = $"可领取: {availableCount} 个奖励 ({availableCount * UOSBattlePassManager.GoldPerTier} 金币)";
            else
                availableLabel.text = "暂无奖励可领取";
        }

        if (claimAllButton != null)
            claimAllButton.interactable = availableCount > 0;
    }

    // ═══════════════════════════════════════════
    //  领取
    // ═══════════════════════════════════════════

    private async void OnNodeClaim(int tierIndex)
    {
        if (_isLoading) return;

        _pendingClaims.Add(tierIndex);
        _isLoading = true;

        try
        {
            int gold = await UOSBattlePassManager.Instance.ClaimTier(tierIndex);
            Debug.Log($"[BattlePassUI] 领取节点 {tierIndex} 成功, 获得 {gold} 金币");

            if (rewardPopup != null)
                rewardPopup.Show(gold);

            _pendingClaims.Remove(tierIndex);
            await Refresh();
            ScrollToIndex(GetSnapTargetIndex(), smooth: true);
        }
        catch (Exception ex)
        {
            Debug.LogError($"[BattlePassUI] 领取节点 {tierIndex} 失败: {ex.Message}");
            _pendingClaims.Remove(tierIndex);
        }
        finally
        {
            _isLoading = false;
        }
    }

    private async void ClaimAll()
    {
        if (_isLoading) return;
        _isLoading = true;

        int reachedNodes = _totalKills / UOSBattlePassManager.KillsPerTier;
        int claimedNodes = _claimedKills / UOSBattlePassManager.KillsPerTier;
        for (int i = claimedNodes; i < reachedNodes; i++)
            _pendingClaims.Add(i);

        if (_pool != null)
        {
            foreach (var node in _pool)
                node.HideClaimButton();
        }

        try
        {
            var (claimedCount, totalGold) = await UOSBattlePassManager.Instance.ClaimAll();

            if (claimedCount <= 0)
            {
                Debug.Log("[BattlePassUI] 全部领取: 无可领取奖励");
                _pendingClaims.Clear();
                return;
            }

            Debug.Log($"[BattlePassUI] 全部领取成功: {claimedCount} 个节点, 共 {totalGold} 金币");

            if (rewardPopup != null)
                rewardPopup.Show(totalGold);

            _pendingClaims.Clear();
            await Refresh();
            ScrollToIndex(GetSnapTargetIndex(), smooth: true);
        }
        catch (Exception ex)
        {
            Debug.LogError($"[BattlePassUI] 全部领取失败: {ex.Message}");
            _pendingClaims.Clear();
        }
        finally
        {
            _isLoading = false;
        }
    }

    private void ShowLoading(bool show)
    {
        if (loadingIndicator != null)
            loadingIndicator.SetActive(show);
    }

    private void ValidateSetup()
    {
        if (nodesContainer == null)
            Debug.LogWarning("[BattlePassUI] 请在 Inspector 中拖入 Nodes Container");
        if (nodePrefab == null)
            Debug.LogWarning("[BattlePassUI] 请在 Inspector 中拖入 Node Prefab");
        if (nodesScrollRect == null)
            Debug.LogWarning("[BattlePassUI] 请在 Inspector 中拖入 Nodes Scroll Rect");
        if (progressFill == null)
            Debug.LogWarning("[BattlePassUI] 请在 Inspector 中拖入 Progress Fill Image");
    }
}
