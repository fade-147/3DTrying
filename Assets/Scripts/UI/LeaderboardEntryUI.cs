using UnityEngine;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// 排行榜单条条目。挂在条目 prefab 上。
/// </summary>
public class LeaderboardEntryUI : MonoBehaviour
{
    [Header("背景")]
    [Tooltip("条目背景 Image（可选，用于隔行变色或高亮自己）")]
    [SerializeField] private Image background;

    [Header("文字")]
    [Tooltip("排名文字，如「#1」")]
    [SerializeField] private TMP_Text rankText;

    [Tooltip("玩家名字")]
    [SerializeField] private TMP_Text nameText;

    [Tooltip("击杀数")]
    [SerializeField] private TMP_Text scoreText;

    /// <summary>
    /// 由 LeaderboardUI 调用，填充数据。
    /// </summary>
    public void SetEntry(RankingEntry entry)
    {
        if (rankText != null)
            rankText.text = entry.Rank > 0 ? $"#{entry.Rank}" : "-";

        if (nameText != null)
            nameText.text = entry.DisplayName;

        if (scoreText != null)
            scoreText.text = entry.Score.ToString("N0");
    }

    /// <summary>
    /// 高亮当前玩家的行（可选，调用方自行决定）。
    /// </summary>
    public void Highlight(Color color)
    {
        if (background != null)
            background.color = color;
    }
}
