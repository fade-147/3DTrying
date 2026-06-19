using UnityEngine;

/// <summary>
/// 打开抽卡 UI 的按钮包装。挂在 StartScene 的按钮上。
/// </summary>
public class GachaButton : MonoBehaviour
{
    public void OpenGacha()
    {
        var gachaUI = FindObjectOfType<GachaUI>(true);
        if (gachaUI != null)
        {
            gachaUI.Open();
        }
        else
        {
            Debug.LogError("[GachaButton] No GachaUI found in scene!");
        }
    }
}
