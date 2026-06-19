using UnityEngine;
using Mirror;

/// <summary>
/// 第三人称武器模型显示。
/// 监听 equippedWeaponSlug 变化，在 3P 模型的手部挂点动态实例化/切换武器模型。
/// 仅对客户端生效（isServer | isClient 均可），不需要 isLocalPlayer。
/// </summary>
public class ThirdPersonWeaponDisplay : NetworkBehaviour
{
    [Header("挂点")]
    [Tooltip("右手武器挂点（thirdPersonVisual/WeaponSlot_RightHand）")]
    public Transform rightHandSlot;

    [Header("当前显示的武器模型")]
    private GameObject currentWeaponModel;

    /// <summary>
    /// 当 SyncVar 变更时由 PlayerWeaponSync 调用。
    /// </summary>
    public void OnWeaponChanged(string oldSlug, string newSlug)
    {
        // 本地玩家不需要 3P 显示（已在 1P 视角中看到自己的 LPSP 武器）
        if (isLocalPlayer) return;

        // 销毁旧模型
        if (currentWeaponModel != null)
        {
            Destroy(currentWeaponModel);
            currentWeaponModel = null;
        }

        if (string.IsNullOrEmpty(newSlug)) return;
        if (rightHandSlot == null)
        {
            Debug.LogWarning("[ThirdPersonWeaponDisplay] rightHandSlot is not assigned.");
            return;
        }

        GameObject prefab = WeaponPrefabRegistry.GetPrefab(newSlug);
        if (prefab == null)
        {
            Debug.LogWarning($"[ThirdPersonWeaponDisplay] No prefab registered for slug '{newSlug}'.");
            return;
        }

        currentWeaponModel = Instantiate(prefab, rightHandSlot);
        currentWeaponModel.transform.localPosition = Vector3.zero;
        currentWeaponModel.transform.localRotation = Quaternion.identity;
        DisableAllScripts(currentWeaponModel);
    }

    /// <summary>
    /// 禁用 GameObject 及其子对象上所有 MonoBehaviour（保留 Transform 和模型可见性）。
    /// </summary>
    void DisableAllScripts(GameObject obj)
    {
        foreach (var mb in obj.GetComponentsInChildren<MonoBehaviour>(true))
        {
            if (mb is Transform)
                continue;
            mb.enabled = false;
        }
    }
}
