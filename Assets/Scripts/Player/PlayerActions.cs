using UnityEngine;
using Mirror;

/// <summary>
/// Handles weapon toggle, drinking, and inspect actions.
/// Extracted from ThirdPersonController.
/// </summary>
public class PlayerActions : NetworkBehaviour
{
    #region Weapon Toggle

    [Header("Weapon Toggle")]
    public float toggleGunLockTime = 2.5f;
    private bool _canToggleGun = true;

    #endregion

    #region Drinking

    [Header("Drinking")]
    public float DrinkDuration = 3f;
    public KeyCode DrinkKey = KeyCode.C;
    private float _currentDrinkTime;

    #endregion

    #region Inspect

    [Header("Inspect")]
    public KeyCode InspectKey = KeyCode.T;

    #endregion

    #region References

    private PlayerState _state;
    private PlayerNetwork _network;
    private PlayerViewManager _view;
    private PlayerCombat _combat;
    private PlayerMovement _movement;
    private StarterAssets.StarterAssetsInputs _input;
    private Animator _firstPersonAnimator;
    private Animator _gunAnimator;

    // UI
    private UnityEngine.UI.Image _drinkProgressUI;
    private UnityEngine.UI.Image _reloadProgressUI;

    // Animation hashes
    private int _animIDInspect;
    private int _animIDReload;
    private int _animIDAim;
    private int _animIDAiming;

    #endregion

    void Awake()
    {
        _state = GetComponent<PlayerState>();
        _network = GetComponent<PlayerNetwork>();
        _view = GetComponent<PlayerViewManager>();
        _combat = GetComponent<PlayerCombat>();
        _movement = GetComponent<PlayerMovement>();
        _input = GetComponent<StarterAssets.StarterAssetsInputs>();
    }

    void Start()
    {
        _canToggleGun = true;
        _animIDInspect = Animator.StringToHash("Inspect");
        _animIDReload = Animator.StringToHash("Reload");
        _animIDAim = Animator.StringToHash("Aim");
        _animIDAiming = Animator.StringToHash("Aiming");

        if (isLocalPlayer)
        {
            CacheDrinkUI();
        }
    }

    void Update()
    {
        if (!isLocalPlayer) return;

        var character = GetComponent<PlayerCharacter>();
        if (character != null && character.isDead) return;

        // Cache animator references lazily
        if (_firstPersonAnimator == null && _view != null && _view.firstPersonModule != null)
            _firstPersonAnimator = _view.firstPersonModule.GetComponentInChildren<Animator>();

        // === Drinking ===
        if (Input.GetKeyDown(DrinkKey) && !_state.isDrinking && !_state.isHoldingGun)
        {
            StartDrink();
        }

        if (_state.isDrinking)
        {
            UpdateDrinkProgress();
            if (Input.GetKey(KeyCode.W) || Input.GetKey(KeyCode.A) ||
                Input.GetKey(KeyCode.S) || Input.GetKey(KeyCode.D) ||
                Input.GetKey(KeyCode.R) || Input.GetKey(KeyCode.Space))
            {
                InterruptDrink();
            }
        }

        if (_state.isDrinking) return; // Block other actions while drinking

        // === Weapon Toggle (R key) ===
        if (Input.GetKeyDown(KeyCode.R) && _canToggleGun)
        {
            TryToggleGun();
        }

        // === Inspect (T key) ===
        bool isFirstPerson = _view != null && _view.isFirstPerson;
        if (Input.GetKeyDown(InspectKey) && isFirstPerson && _state.isHoldingGun &&
            !_state.isInspecting)
        {
            StartInspect();
        }
    }

    #region Weapon Toggle

    public void TryToggleGun()
    {
        _state.isInspecting = false;
        _network.CmdToggleGun();
        _canToggleGun = false;
        Invoke(nameof(UnlockGunToggle), toggleGunLockTime);
        _combat.CanShoot = false;

        Debug.Log(_state.isHoldingGun ? "Holstered weapon" : "Drew weapon");
    }

    public void OnGunStateChanged(bool oldValue, bool newValue)
    {
        // View model visibility
        if (isLocalPlayer && _view != null && _view.firstPersonModelGun != null)
        {
            _view.firstPersonModelGun.SetActive(
                _view.isFirstPerson && newValue);
        }

        _combat.CanShoot = newValue;
        if (_combat != null) _combat.CurrentSpread = _combat.BaseSpread;
    }

    private void UnlockGunToggle()
    {
        _canToggleGun = true;
    }

    #endregion

    #region Drinking

    private void StartDrink()
    {
        if (_state.isHoldingGun) return;
        _state.isInspecting = false;
        _combat.ShotsFired = 0;
        _combat.TargetRecoilOffset = Vector2.zero;
        _combat.CurrentRecoilOffset = Vector2.zero;
        _combat.CurrentSpread = _combat.BaseSpread;

        if (_firstPersonAnimator != null)
        {
            _firstPersonAnimator.SetBool("Reloading", false);
        }
        if (_gunAnimator != null)
        {
            _gunAnimator.SetBool("Reloading", false);
        }

        _network.CmdStartDrink();
    }

    public void OnDrinkStarted()
    {
        _currentDrinkTime = 0f;
        if (isLocalPlayer && _drinkProgressUI != null)
        {
            _drinkProgressUI.fillAmount = 0;
            _drinkProgressUI.gameObject.SetActive(true);
        }
        if (_firstPersonAnimator != null)
            _firstPersonAnimator.SetTrigger("Drink");
    }

    private void UpdateDrinkProgress()
    {
        if (!isLocalPlayer || !_state.isDrinking) return;
        _currentDrinkTime += Time.deltaTime;
        float progress = _currentDrinkTime / DrinkDuration;
        if (_drinkProgressUI != null) _drinkProgressUI.fillAmount = progress;
        if (progress >= 1f) _network.CmdCompleteDrink();
    }

    public void OnDrinkCompleted()
    {
        HideDrinkUI();
    }

    public void OnDrinkInterrupted()
    {
        HideDrinkUI();
        if (_firstPersonAnimator != null)
            _firstPersonAnimator.SetTrigger("NotDrink");
    }

    private void InterruptDrink()
    {
        _network.CmdInterruptDrink();
    }

    private void HideDrinkUI()
    {
        if (_drinkProgressUI != null)
        {
            _drinkProgressUI.fillAmount = 0;
            _drinkProgressUI.gameObject.SetActive(false);
        }
    }

    private void CacheDrinkUI()
    {
        GameObject uiObj = GameObject.FindWithTag("DrinkUI");
        if (uiObj != null)
        {
            _drinkProgressUI = uiObj.GetComponent<UnityEngine.UI.Image>();
            _drinkProgressUI.fillAmount = 0;
            _drinkProgressUI.gameObject.SetActive(false);
        }
    }

    #endregion

    #region Inspect

    public void StartInspect()
    {
        _state.isInspecting = true;
        _combat.IsReloading = false;
        _combat.ShotsFired = 0;
        _combat.TargetRecoilOffset = Vector2.zero;
        _combat.CurrentRecoilOffset = Vector2.zero;
        _combat.CurrentSpread = _combat.BaseSpread;

        if (_firstPersonAnimator != null)
        {
            _firstPersonAnimator.SetTrigger(_animIDInspect);
            _firstPersonAnimator.SetBool(_animIDAim, false);
            _firstPersonAnimator.SetFloat(_animIDAiming, 0f);
            _firstPersonAnimator.SetBool("Reloading", false);
        }
        if (_gunAnimator != null)
        {
            _gunAnimator.SetBool("Reloading", false);
        }
    }

    public void OnInspectComplete()
    {
        _state.isInspecting = false;
    }

    /// <summary>
    /// Animation event receiver — called when weapon pull-out animation finishes.
    /// </summary>
    public void GetOnGun()
    {
        var combat = GetComponent<PlayerCombat>();
        if (combat != null) combat.CanShoot = true;
    }

    /// <summary>
    /// Animation event receiver — called when weapon put-away animation finishes.
    /// </summary>
    public void PutAwayGun()
    {
        _canToggleGun = true;
    }

    #endregion
}
