using UnityEngine;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// 武器详情弹窗。点击武器图标时弹出。
/// </summary>
public class WeaponInfoPopup : MonoBehaviour
{
    [Header("UI")]
    public GameObject panelRoot;
    public Image icon;
    public TextMeshProUGUI nameText;
    public TextMeshProUGUI descriptionText;
    public TextMeshProUGUI statsText;    // 射速、弹容、自动/栓动等
    public Button closeButton;

    private void Awake()
    {
        panelRoot.SetActive(false);
        closeButton?.onClick.AddListener(() => panelRoot.SetActive(false));
    }

    public void Show(WeaponEntry entry)
    {
        if (entry == null) return;

        if (icon != null) icon.sprite = entry.icon;
        if (nameText != null) nameText.text = entry.displayName;
        if (descriptionText != null) descriptionText.text = entry.description;

        if (statsText != null)
        {
            string fireMode = entry.isBoltAction ? "栓动" : (entry.isAutomatic ? "全自动" : "半自动");
            string reloadMode = entry.cycledReload ? "逐发装填" : "弹匣装填";
            statsText.text = $"射速: {entry.roundsPerMinute} RPM\n"
                           + $"弹容: {entry.magazineSize} 发\n"
                           + $"射击模式: {fireMode}\n"
                           + $"装填: {reloadMode}\n"
                           + $"弹丸数/发: {entry.shotCount}\n"
                           + $"移动速度: ×{entry.movementSpeedMultiplier:F1}";
        }

        panelRoot.SetActive(true);
    }

    public void Hide() => panelRoot.SetActive(false);
}
