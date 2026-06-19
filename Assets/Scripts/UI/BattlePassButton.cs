using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 打开战令面板的按钮 wrapper。
/// 挂在 StartScene 的"战令"按钮 GameObject 上。
/// </summary>
public class BattlePassButton : MonoBehaviour
{
    private void Start()
    {
        var button = GetComponent<Button>();
        if (button != null)
        {
            button.onClick.AddListener(() =>
            {
                var panel = Object.FindObjectOfType<BattlePassUI>(true);
                if (panel != null)
                    panel.Show();
            });
        }
        else
        {
            Debug.LogWarning("[BattlePassButton] 未找到 Button 组件");
        }

        Destroy(this);
    }
}
