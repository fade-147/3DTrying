using System;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 战令里程碑节点状态。
/// </summary>
public enum BattlePassNodeState
{
    Locked,
    Available,
    Claimed
}

/// <summary>
/// 战令面板中单个里程碑节点 UI。
/// 挂在节点 prefab 上。
/// </summary>
public class BattlePassNodeUI : MonoBehaviour
{
    [Header("节点外观")]
    [SerializeField] private Image nodeIcon;
    [SerializeField] private TMP_Text nodeLabel;

    [Header("按钮")]
    [SerializeField] private Button claimButton;

    [Header("状态标记")]
    [SerializeField] private GameObject claimedMark;
    [SerializeField] private GameObject lockOverlay;

    [Header("颜色")]
    [SerializeField] private Color lockedColor = new Color(0.4f, 0.4f, 0.4f);
    [SerializeField] private Color availableColor = new Color(1f, 0.84f, 0f);
    [SerializeField] private Color claimedColor = new Color(1f, 0.84f, 0f);

    private int _tierIndex;
    private Action<int> _onClaim;

    public int TierIndex => _tierIndex;

    /// <summary>
    /// 配置节点（内容 + 状态）。
    /// </summary>
    public void Setup(int tierIndex, BattlePassNodeState state, Action<int> onClaim)
    {
        _tierIndex = tierIndex;
        _onClaim = onClaim;

        int requiredKills = (tierIndex + 1) * UOSBattlePassManager.KillsPerTier;

        if (nodeLabel != null)
            nodeLabel.text = $"{requiredKills}杀";

        ApplyState(state);
    }

    /// <summary>
    /// 设置节点在 ScrollView Content 中的 X 位置（虚拟滚动用）。
    /// </summary>
    public void SetPositionX(float x)
    {
        var rt = GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0, 0.5f);
        rt.anchorMax = new Vector2(0, 0.5f);
        rt.pivot = new Vector2(0, 0.5f);
        rt.anchoredPosition = new Vector2(x, 0);
    }

    private void ApplyState(BattlePassNodeState state)
    {
        switch (state)
        {
            case BattlePassNodeState.Locked:
                SetNodeColor(lockedColor);
                if (lockOverlay != null) lockOverlay.SetActive(true);
                if (claimedMark != null) claimedMark.SetActive(false);
                if (claimButton != null) claimButton.gameObject.SetActive(false);
                break;

            case BattlePassNodeState.Available:
                SetNodeColor(availableColor);
                if (lockOverlay != null) lockOverlay.SetActive(false);
                if (claimedMark != null) claimedMark.SetActive(false);
                if (claimButton != null)
                {
                    claimButton.gameObject.SetActive(true);
                    claimButton.onClick.RemoveAllListeners();
                    claimButton.onClick.AddListener(OnClaimClicked);
                }
                break;

            case BattlePassNodeState.Claimed:
                SetNodeColor(claimedColor);
                if (lockOverlay != null) lockOverlay.SetActive(false);
                if (claimedMark != null) claimedMark.SetActive(true);
                if (claimButton != null) claimButton.gameObject.SetActive(false);
                break;
        }
    }

    private void SetNodeColor(Color color)
    {
        if (nodeIcon != null)
            nodeIcon.color = color;
    }

    private void OnClaimClicked()
    {
        // 立即隐藏按钮，避免用户重复点击
        if (claimButton != null)
            claimButton.gameObject.SetActive(false);
        if (lockOverlay != null)
            lockOverlay.SetActive(false);

        _onClaim?.Invoke(_tierIndex);
    }

    /// <summary>
    /// 外部批量隐藏领取按钮（如全部领取时）。
    /// </summary>
    public void HideClaimButton()
    {
        if (claimButton != null)
            claimButton.gameObject.SetActive(false);
    }
}
