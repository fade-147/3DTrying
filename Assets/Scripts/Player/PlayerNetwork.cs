using Mirror;
using UnityEngine;

/// <summary>
/// Centralized network commands and RPCs.
/// All game-logic network calls go through this component.
/// Extracted from ThirdPersonController.
/// </summary>
public class PlayerNetwork : NetworkBehaviour
{
    #region References
    private PlayerState _state;
    private PlayerCombat _combat;
    private PlayerCharacter _character;
    #endregion

    #region Projectile Prefabs

    [Header("联网弹丸 Prefabs")]
    [Tooltip("火箭弹 prefab（改造后的 P_LPSP_PROJ_RL）")]
    public GameObject rocketPrefab;

    [Tooltip("榴弹 prefab（改造后的 P_LPSP_PROJ_GL）")]
    public GameObject grenadeLauncherPrefab;

    [Tooltip("手榴弹 prefab（改造后的 P_LPSP_PROJ_Grenade_01）")]
    public GameObject grenadeNetworkPrefab;

    [Header("霰弹枪")]
    [Tooltip("多弹丸散布角（度），仅 shotCount>1 时生效")]
    public float pelletSpreadAngleField = 3f;

    #endregion

    void Awake()
    {
        _state = GetComponent<PlayerState>();
        _combat = GetComponent<PlayerCombat>();
        _character = GetComponent<PlayerCharacter>();
    }

    #region Shooting

    [Command]
    public void CmdFire(Vector3 shootDirection, Vector3 muzzleWorldPos, string weaponSlug)
    {
        if (_combat == null) return;

        GameObject prefab = GetProjectilePrefab(weaponSlug);
        if (prefab == null) return;

        var entry = WeaponPrefabRegistry.GetEntry(weaponSlug);
        int shotCount = entry != null ? entry.shotCount : 1;
        float baseDamage = entry != null ? entry.damage : 15f;
        float pelletSpreadAngle = pelletSpreadAngleField;

        for (int i = 0; i < shotCount; i++)
        {
            Vector3 pelletDir = shootDirection;
            if (shotCount > 1)
            {
                float offsetX = Random.Range(-pelletSpreadAngle, pelletSpreadAngle);
                float offsetY = Random.Range(-pelletSpreadAngle, pelletSpreadAngle);
                pelletDir = Quaternion.Euler(offsetY, offsetX, 0) * shootDirection;
            }

            Vector3 spawnPos = muzzleWorldPos + pelletDir.normalized * 1.5f;
            GameObject projectile = Instantiate(prefab, spawnPos, Quaternion.LookRotation(pelletDir));

            // 必须在 Spawn 前设置 ownerNetIdentity，否则 OnStartServer 中 SetupTeammateIgnore 拿不到
            NetworkedExplosive explosive = null;
            Bullet bullet = null;
            if (projectile.TryGetComponent<NetworkedExplosive>(out var exp))
            {
                exp.ownerNetIdentity = netIdentity;
                explosive = exp;
            }
            else if (projectile.TryGetComponent<Bullet>(out var bul))
            {
                bul.ownerNetIdentity = netIdentity;
                bullet = bul;
            }

            NetworkServer.Spawn(projectile);

            // 爆炸类弹丸
            if (explosive != null)
            {
                if (projectile.TryGetComponent<Rigidbody>(out var rbExp))
                {
                    rbExp.velocity = Vector3.zero;
                    rbExp.AddForce(pelletDir.normalized * explosive.InitialSpeed, ForceMode.VelocityChange);
                }
            }
            // 普通子弹
            else if (bullet != null)
            {
                bullet.damage = baseDamage;
                bullet.HitEffect = _combat.HitEffect;
                bullet.BulletLifeTime = _combat.BulletLifeTime;

                if (projectile.TryGetComponent<Rigidbody>(out var rbBullet))
                {
                    rbBullet.velocity = Vector3.zero;
                    rbBullet.AddForce(pelletDir.normalized * _combat.BulletSpeed, ForceMode.VelocityChange);
                }

                Destroy(projectile, _combat.BulletLifeTime);
            }
        }

        RpcShowMuzzleFlash(muzzleWorldPos);
        _combat.OnServerShotFired();
    }

    /// <summary>根据武器 slug 选择对应的联网弹丸 prefab。</summary>
    GameObject GetProjectilePrefab(string slug)
    {
        switch (slug)
        {
            case "wpn_rl_01":
                return rocketPrefab != null ? rocketPrefab : _combat.BulletPrefab;
            case "wpn_gl_01":
                return grenadeLauncherPrefab != null ? grenadeLauncherPrefab : _combat.BulletPrefab;
            default:
                return _combat.BulletPrefab;
        }
    }

    [ClientRpc]
    public void RpcShowMuzzleFlash(Vector3 muzzleWorldPos)
    {
        if (_combat != null && _combat.MuzzleFlash != null)
        {
            var flash = Instantiate(_combat.MuzzleFlash, muzzleWorldPos, Quaternion.identity);
            Destroy(flash, 0.1f);
        }
    }

    #endregion

    #region Grenade

    [Command]
    public void CmdThrowGrenade(Vector3 throwDirection, Vector3 throwPosition, float throwForce)
    {
        if (grenadeNetworkPrefab == null)
        {
            Debug.LogError("[PlayerNetwork] grenadeNetworkPrefab is null — cannot throw networked grenade.");
            return;
        }

        GameObject grenade = Instantiate(grenadeNetworkPrefab, throwPosition,
            Quaternion.LookRotation(throwDirection));
        NetworkServer.Spawn(grenade);

        var explosive = grenade.GetComponent<NetworkedExplosive>();
        if (explosive != null)
            explosive.ownerNetIdentity = netIdentity;

        if (grenade.TryGetComponent<Rigidbody>(out var rb))
        {
            // ForceMode.Force = 持续力（与 GrenadeScript.Start 一致）
            rb.AddForce(throwDirection * throwForce, ForceMode.Force);
            // 复刻 GrenadeScript.Awake 的随机翻滚（X轴 500~1500）
            rb.AddRelativeTorque(
                Random.Range(500f, 1500f),
                0f,
                0f
            );
        }
    }

    #endregion

    #region Toggle Gun

    [Command]
    public void CmdToggleGun()
    {
        _state.isHoldingGun = !_state.isHoldingGun;
        RpcPlayToggleGunAnim();
    }

    [ClientRpc]
    public void RpcPlayToggleGunAnim()
    {
        NetworkAnimator netAnim = GetComponent<NetworkAnimator>();
        if (netAnim != null)
            netAnim.SetTrigger("ToggleGun");
    }

    #endregion

    #region Drinking

    [Command]
    public void CmdStartDrink()
    {
        RpcStartDrink();
    }

    [ClientRpc]
    public void RpcStartDrink()
    {
        _state.isDrinking = true;

        NetworkAnimator netAnim = GetComponent<NetworkAnimator>();
        if (netAnim != null)
            netAnim.SetTrigger("Drink");

        // Local UI handled by PlayerActions
        var actions = GetComponent<PlayerActions>();
        if (actions != null) actions.OnDrinkStarted();
    }

    [Command]
    public void CmdCompleteDrink()
    {
        RpcCompleteDrink();
        if (_character != null) _character.Heal(30f);
    }

    [ClientRpc]
    public void RpcCompleteDrink()
    {
        _state.isDrinking = false;
        var actions = GetComponent<PlayerActions>();
        if (actions != null) actions.OnDrinkCompleted();
    }

    [Command]
    public void CmdInterruptDrink()
    {
        RpcInterruptDrink();
    }

    [ClientRpc]
    public void RpcInterruptDrink()
    {
        _state.isDrinking = false;
        var actions = GetComponent<PlayerActions>();
        if (actions != null) actions.OnDrinkInterrupted();
    }

    #endregion

    #region View Change

    [Command]
    public void CmdTriggerChangeGunView()
    {
        RpcTriggerChangeGunView();
    }

    [ClientRpc]
    public void RpcTriggerChangeGunView()
    {
        NetworkAnimator netAnim = GetComponent<NetworkAnimator>();
        if (netAnim != null)
            netAnim.SetTrigger("ChangeGun");
    }

    #endregion
}
