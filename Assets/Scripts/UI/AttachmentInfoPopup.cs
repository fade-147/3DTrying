using UnityEngine;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// 配件详情弹窗。点击配件图标时弹出。
/// </summary>
public class AttachmentInfoPopup : MonoBehaviour
{
    [Header("UI")]
    public GameObject panelRoot;
    public Image icon;
    public TextMeshProUGUI nameText;
    public TextMeshProUGUI descriptionText;
    public TextMeshProUGUI effectsText;
    public Button closeButton;

    private void Awake()
    {
        panelRoot.SetActive(false);
        closeButton?.onClick.AddListener(() => panelRoot.SetActive(false));
    }

    public void Show(AttachmentEntry entry)
    {
        if (entry == null) return;

        if (icon != null) icon.sprite = entry.icon;
        if (nameText != null) nameText.text = entry.displayName;
        if (descriptionText != null) descriptionText.text = entry.description;

        if (effectsText != null)
        {
            var parts = new System.Collections.Generic.List<string>();
            const float percentMul = 100f;

            float recoil = entry.recoilReduction;
            float spread = entry.spreadReduction;
            float sway = entry.swayReduction;
            float ammoMult = entry.ammoCapacityMultiplier;
            float hipfire = entry.hipfireSpreadReduction;

            if (recoil > 0f)
                parts.Add($"后坐力 -{recoil * percentMul:F0}%");
            if (spread > 0f)
                parts.Add($"散布 -{spread * percentMul:F0}%");
            if (sway > 0f)
                parts.Add($"摇摆 -{sway * percentMul:F0}%");
            if (entry.suppressSound)
                parts.Add("🔇 消音（隐藏伤害方向）");
            if (ammoMult > 1f)
                parts.Add($"弹容 ×{ammoMult:F1} (+{(ammoMult - 1f) * percentMul:F0}%)");
            if (hipfire > 0f)
                parts.Add($"腰射散布 -{hipfire * percentMul:F0}%");

            effectsText.text = parts.Count > 0 ? string.Join("\n", parts) : "无特殊效果";
        }

        panelRoot.SetActive(true);
    }

    public void Hide() => panelRoot.SetActive(false);
}
