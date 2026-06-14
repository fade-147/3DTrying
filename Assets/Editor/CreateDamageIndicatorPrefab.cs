using UnityEditor;
using UnityEngine;

/// <summary>
/// 一次性工具：创建 DamageIndicatorManager 的 prefab。
/// 菜单：Tools → Create Damage Indicator Prefab
/// 生成后请打开 Assets/Resources/DamageIndicators.prefab，拖拽 Sprite 赋值。
/// </summary>
public static class CreateDamageIndicatorPrefab
{
    [MenuItem("Tools/Create Damage Indicator Prefab")]
    public static void Create()
    {
        // 确保 Resources 目录存在
        if (!AssetDatabase.IsValidFolder("Assets/Resources"))
            AssetDatabase.CreateFolder("Assets", "Resources");

        // 创建根 GameObject（带 RectTransform，作为 Canvas 子对象）
        GameObject go = new GameObject("DamageIndicators", typeof(RectTransform));

        // 通过名称添加组件，避免跨程序集引用 HotUpdate
        System.Type type = System.Type.GetType("DamageIndicatorManager, HotUpdate");
        if (type != null)
        {
            go.AddComponent(type);
        }
        else
        {
            Debug.LogError("找不到 DamageIndicatorManager 类型，请确认 HotUpdate 程序集已编译。");
            Object.DestroyImmediate(go);
            return;
        }

        // 保存为 prefab
        string path = "Assets/Resources/DamageIndicators.prefab";
        PrefabUtility.SaveAsPrefabAsset(go, path);
        Object.DestroyImmediate(go);

        AssetDatabase.Refresh();
        Debug.Log("[CreateDamageIndicatorPrefab] Prefab 已创建: " + path);
        Debug.Log("1. 打开该 prefab，拖拽箭头 Sprite 到 Inspector 的 Indicator Sprite 字段");
        Debug.Log("2. 打开 Player_FPS_TP prefab → PlayerCharacter → 拖此 prefab 到 Damage Indicator Prefab 字段");
    }
}
