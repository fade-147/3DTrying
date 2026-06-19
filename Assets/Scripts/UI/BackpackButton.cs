using UnityEngine;

/// <summary>
/// 打开背包 UI 的按钮包装。挂在 StartScene 的按钮上。
/// </summary>
public class BackpackButton : MonoBehaviour
{
    public void OpenBackpack()
    {
        var backpackUI = FindObjectOfType<BackpackUI>(true);
        if (backpackUI != null)
        {
            backpackUI.Open();
        }
        else
        {
            Debug.LogError("[BackpackButton] No BackpackUI found in scene!");
        }
    }
}
