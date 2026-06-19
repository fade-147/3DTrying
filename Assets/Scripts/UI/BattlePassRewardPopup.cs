using System.Threading.Tasks;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 战令领奖结果弹窗。显示"获得 X 金币!"后自动消失。
/// </summary>
public class BattlePassRewardPopup : MonoBehaviour
{
    [Header("弹窗根")]
    [SerializeField] private GameObject popupRoot;

    [Header("UI 元素")]
    [SerializeField] private TMP_Text rewardText;
    [SerializeField] private Image coinIcon;

    [Header("配置")]
    [SerializeField] private float autoHideDelay = 2f;
    [SerializeField] private string rewardFormat = "获得 {0} 金币!";

    private System.Threading.CancellationTokenSource _hideCts;

    private void Awake()
    {
        if (popupRoot != null)
            popupRoot.SetActive(false);
    }

    /// <summary>
    /// 显示领奖弹窗。自动隐藏。连续调用会取消前一次的自动隐藏。
    /// </summary>
    public async void Show(int goldAmount)
    {
        // 取消前一次的自动隐藏定时器
        _hideCts?.Cancel();
        _hideCts = new System.Threading.CancellationTokenSource();
        var token = _hideCts.Token;

        if (rewardText != null)
            rewardText.text = string.Format(rewardFormat, goldAmount);

        if (popupRoot != null)
            popupRoot.SetActive(true);

        try
        {
            await Task.Delay((int)(autoHideDelay * 1000), token);
            if (popupRoot != null)
                popupRoot.SetActive(false);
        }
        catch (TaskCanceledException)
        {
            // 被新的 Show 调用取消，正常
        }
    }
}
