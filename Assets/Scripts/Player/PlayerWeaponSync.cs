using UnityEngine;
using Mirror;

/// <summary>
/// 武器切换网络同步。
/// 本地玩家切换武器时通过 CmdSwitchWeapon 通知服务端，
/// 服务端通过 SyncVar 广播到所有客户端，触发 3P 武器显示更新。
/// </summary>
public class PlayerWeaponSync : NetworkBehaviour
{
    /// <summary>
    /// 当前装备的武器 slug。仅服务端可写，客户端通过 hook 响应。
    /// </summary>
    [SyncVar(hook = nameof(OnSlugChanged))]
    public string equippedWeaponSlug;

    /// <summary>
    /// [Command] 服务端更新武器 slug。
    /// </summary>
    [Command]
    public void CmdSwitchWeapon(string slug)
    {
        equippedWeaponSlug = slug;
    }

    void OnSlugChanged(string oldSlug, string newSlug)
    {
        var display = GetComponent<ThirdPersonWeaponDisplay>();
        if (display != null)
            display.OnWeaponChanged(oldSlug, newSlug);
    }
}
