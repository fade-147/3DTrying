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

    void Awake()
    {
        _state = GetComponent<PlayerState>();
        _combat = GetComponent<PlayerCombat>();
        _character = GetComponent<PlayerCharacter>();
    }

    #region Shooting

    [Command]
    public void CmdFire(Vector3 shootDirection, Vector3 muzzleWorldPos)
    {
        if (_combat == null || _combat.BulletPrefab == null) return;

        GameObject bullet = Instantiate(_combat.BulletPrefab, muzzleWorldPos, Quaternion.LookRotation(shootDirection));
        NetworkServer.Spawn(bullet);

        Bullet bulletScript = bullet.GetComponent<Bullet>();
        if (bulletScript != null)
        {
            bulletScript.ownerNetIdentity = netIdentity;
            bulletScript.HitEffect = _combat.HitEffect;
            bulletScript.BulletLifeTime = _combat.BulletLifeTime;
        }

        if (bullet.TryGetComponent<Rigidbody>(out var rb))
        {
            rb.velocity = Vector3.zero;
            rb.AddForce(shootDirection.normalized * _combat.BulletSpeed, ForceMode.VelocityChange);
        }

        Destroy(bullet, _combat.BulletLifeTime);
        RpcShowMuzzleFlash(muzzleWorldPos);

        _combat.OnServerShotFired();
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
