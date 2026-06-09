using Mirror;
using UnityEngine;

/// <summary>
/// Centralized SyncVar state for the player.
/// All networked components read/write through this.
/// Extracted from ThirdPersonController.
/// </summary>
public class PlayerState : NetworkBehaviour
{
    [Header("Team")]
    [SyncVar(hook = nameof(OnTeamIdChanged))]
    public int teamId;

    [Header("Weapon State")]
    [SyncVar(hook = nameof(OnHoldingGunChanged))]
    public bool isHoldingGun;

    [Header("View State")]
    [SyncVar]
    public bool isFirstPerson;

    [Header("Combat State")]
    [SyncVar]
    public int currentAmmo = 30;
    [SyncVar]
    public int maxAmmo = 30;
    [SyncVar]
    public bool isReloading;
    [SyncVar]
    public bool isInspecting;

    [Header("Action State")]
    [SyncVar]
    public bool isDrinking;

    // Callbacks for SyncVar hooks (can be subscribed to by other components)
    public event System.Action<bool, bool> OnHoldingGunChangedEvent;
    public event System.Action<int, int> OnTeamIdChangedEvent;

    void OnHoldingGunChanged(bool oldValue, bool newValue)
    {
        OnHoldingGunChangedEvent?.Invoke(oldValue, newValue);
    }

    void OnTeamIdChanged(int oldValue, int newValue)
    {
        OnTeamIdChangedEvent?.Invoke(oldValue, newValue);
    }
}
