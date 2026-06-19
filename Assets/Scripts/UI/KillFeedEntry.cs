using System.Collections;
using UnityEngine;
using TMPro;

/// <summary>
/// 单条击杀播报条目。
/// 挂载到 KillFeedEntry 预制体上，包含 TMP_Text + CanvasGroup。
/// 显示指定时长后自动淡出并销毁。
/// </summary>
public class KillFeedEntry : MonoBehaviour
{
    [SerializeField] private TMP_Text messageText;
    [SerializeField] private CanvasGroup canvasGroup;

    [Header("Timing")]
    [SerializeField] private float displayDuration = 10f;
    [SerializeField] private float fadeDuration = 1f;

    /// <summary>
    /// 设置条目内容并开始自动淡出协程。
    /// </summary>
    /// <param name="killerName">击杀者显示名</param>
    /// <param name="victimName">被击杀者显示名</param>
    /// <param name="killerTeam">击杀者队伍 0=红方,1=蓝方</param>
    /// <param name="victimTeam">被击杀者队伍</param>
    /// <param name="localTeam">本地玩家队伍，用于决定着色（己方蓝、敌方红）</param>
    public void Setup(string killerName, string victimName, int killerTeam, int victimTeam, int localTeam)
    {
        string killerColor = killerTeam == localTeam ? "#5588FF" : "#FF5555";
        string victimColor = victimTeam == localTeam ? "#5588FF" : "#FF5555";
        messageText.text = $"<color={killerColor}>{killerName}</color> 击杀 <color={victimColor}>{victimName}</color>";
        StartCoroutine(AutoFadeRoutine());
    }

    private IEnumerator AutoFadeRoutine()
    {
        yield return new WaitForSeconds(displayDuration);

        float elapsed = 0f;
        while (elapsed < fadeDuration)
        {
            elapsed += Time.deltaTime;
            if (canvasGroup != null)
                canvasGroup.alpha = Mathf.Lerp(1, 0, elapsed / fadeDuration);
            yield return null;
        }

        Destroy(gameObject);
    }
}
