using System;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// 抽卡面板 UI。挂在 StartScene 的抽卡面板 GameObject 上。
/// 通过 GachaButton 触发打开。
/// </summary>
public class GachaUI : MonoBehaviour
{
    [Header("Panel")]
    public GameObject panelRoot;

    [Header("Buttons")]
    public Button singlePullButton;
    public Button closeButton;

    [Header("Displays")]
    public TextMeshProUGUI goldBalanceText;
    public TextMeshProUGUI resultText;
    public TextMeshProUGUI pullCostText;

    [Header("Animation")]
    public GameObject resultPanel;
    public Image resultIcon;
    public Image resultGoldIcon;
    public float resultShowDuration = 2f;

    private bool _isPulling;

    private void Awake()
    {
        panelRoot.SetActive(false);
        resultPanel.SetActive(false);

        singlePullButton?.onClick.AddListener(OnSinglePullClicked);
        closeButton?.onClick.AddListener(() => panelRoot.SetActive(false));

        if (pullCostText != null)
            pullCostText.text = $"消耗 {UOSGachaManager.SinglePullCost} 金币";
    }

    private void OnEnable()
    {
        RefreshGoldDisplay();
    }

    private async void RefreshGoldDisplay()
    {
        var invMgr = UOSInventoryManager.Instance;
        await invMgr.RefreshGoldBalance();
        UpdateGoldText(invMgr.GoldBalance);
    }

    private void UpdateGoldText(uint amount)
    {
        if (goldBalanceText != null)
            goldBalanceText.text = $"金币: {amount}";
    }

    public void Open()
    {
        panelRoot.SetActive(true);
        resultPanel.SetActive(false);
        resultText.text = "";
        RefreshGoldDisplay();
    }

    public void Close()
    {
        panelRoot.SetActive(false);
    }

    private async void OnSinglePullClicked()
    {
        if (_isPulling) return;
        _isPulling = true;

        resultText.text = "抽奖中...";
        singlePullButton.interactable = false;

        var result = await UOSGachaManager.Instance.SinglePull();

        if (!result.Success)
        {
            resultText.text = result.ErrorMessage;
        }
        else
        {
            switch (result.Type)
            {
                case GachaRewardType.Weapon:
                    resultText.text = $"🎯 获得武器: {result.RewardDisplayName}!";
                    break;
                case GachaRewardType.Attachment:
                    resultText.text = $"🔧 获得配件: {result.RewardDisplayName}!";
                    break;
                case GachaRewardType.Gold:
                    resultText.text = $"💰 获得 {result.GoldAmount} 金币!";
                    break;
                case GachaRewardType.Nothing:
                    resultText.text = "😞 很遗憾，什么都没有...";
                    break;
            }

            UpdateGoldText(result.GoldRemaining);
            ShowResultAnimation(result);
            StartCoroutine(AutoHideResult());
        }

        singlePullButton.interactable = true;
        _isPulling = false;
    }

    private void ShowResultAnimation(GachaResult result)
    {
        bool isGold = result.Type == GachaRewardType.Gold;

        // 武器/配件图标
        if (resultIcon != null)
        {
            resultIcon.enabled = !isGold;
            if (!isGold && result.Type != GachaRewardType.Nothing)
            {
                if (result.Type == GachaRewardType.Weapon)
                {
                    var entry = WeaponPrefabRegistry.GetEntry(result.RewardSlug);
                    resultIcon.sprite = entry?.icon ?? WeaponPrefabRegistry.GetIcon(result.RewardSlug);
                }
                else if (result.Type == GachaRewardType.Attachment)
                {
                    var entry = AttachmentRegistry.GetEntry(result.RewardSlug);
                    resultIcon.sprite = entry?.icon ?? AttachmentRegistry.GetIcon(result.RewardSlug);
                }
            }
        }

        // 金币图标
        if (resultGoldIcon != null)
            resultGoldIcon.enabled = isGold;

        resultPanel.SetActive(true);
    }

    /// <summary>外部调用：关闭结果面板。</summary>
    public void HideResult()
    {
        resultPanel.SetActive(false);
    }

    private System.Collections.IEnumerator AutoHideResult()
    {
        yield return new WaitForSeconds(resultShowDuration);
        resultPanel.SetActive(false);
    }
}
