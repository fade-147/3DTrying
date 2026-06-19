using UnityEngine;
using TMPro;

/// <summary>
/// 结算滚动列表中的单行条目：名字 + 击杀数 + 死亡数。
/// </summary>
public class SettlementEntry : MonoBehaviour
{
    [SerializeField] private TMP_Text nameText;
    [SerializeField] private TMP_Text killsText;
    [SerializeField] private TMP_Text deathsText;

    public void Setup(string playerName, int kills, int deaths, bool isBot)
    {
        if (nameText != null)
            nameText.text = isBot ? $"{playerName} [AI]" : playerName;
        if (killsText != null)
            killsText.text = kills.ToString();
        if (deathsText != null)
            deathsText.text = deaths.ToString();
    }
}
