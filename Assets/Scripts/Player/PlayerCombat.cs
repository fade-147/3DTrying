using UnityEngine;
using UnityEngine.Events;
using Mirror;

/// <summary>
/// Handles shooting, ammo management, reload, spread, and recoil triggering.
/// Extracted from ThirdPersonController.
/// Third-person shooting path preserved as-is.
/// </summary>
public class PlayerCombat : NetworkBehaviour
{
    #region Serialized Fields

    [Header("Shooting")]
    public float FireRate = 0.1f;
    public float MaxShootDistance = 100f;
    public GameObject HitEffect;
    public GameObject MuzzleFlash;
    public GameObject BulletPrefab;
    public float BulletSpeed = 100f;
    public float BulletLifeTime = 2f;

    [Header("Muzzles")]
    public Transform thirdPersonMuzzle;
    public Transform firstPersonMuzzle;

    [Header("Ammo")]
    public int maxAmmo = 30;
    public int currentAmmo = 30;
    public float reloadDuration = 2f;

    [Header("Recoil (trigger only - actual motion by LPSP RecoilMotion)")]
    public int RecoilStartShot = 3;
    public float RecoilRampSpeed = 0.5f;

    [Header("Spread")]
    public float BaseSpread = 0.3f;
    public float WalkSpreadMultiplier = 1.5f;
    public float SprintSpreadMultiplier = 3f;
    public float SpreadPerShot = 0.2f;
    public float MaxSpread = 3f;
    public float SpreadDecaySpeed = 5f;
    public float AimSpreadMultiplier = 0.2f;

    [Header("First Person Recoil (visual only, legacy)")]
    public float FpVerticalRecoil = 0.6f;
    public float FpHorizontalRecoil = 0.2f;
    public float RecoilRampMultiplier = 1.1f;
    public float RecoilSmoothSpeed = 15f;
    public float RecoilReturnSpeed = 8f;
    public float MaxRecoilAngle = 10f;

    #endregion

    #region Public State

    public bool CanShoot = true;
    public bool IsReloading { get; set; }
    public bool IsAiming { get; set; }
    public float CurrentSpread { get; set; }
    public int ShotsFired { get; set; }

    [HideInInspector] public Vector2 CurrentRecoilOffset;
    [HideInInspector] public Vector2 TargetRecoilOffset;
    [HideInInspector] public float SensitivityX = 0.8f;
    [HideInInspector] public float SensitivityY = 0.8f;

    #endregion

    #region Events

    [Header("Events")]
    public UnityEvent OnFire;
    public UnityEvent OnReloadStart;
    public UnityEvent OnReloadComplete;

    #endregion

    #region Private

    private PlayerState _state;
    private PlayerNetwork _network;
    private PlayerViewManager _view;
    private PlayerMovement _movement;
    private StarterAssets.StarterAssetsInputs _input;
    private float _fireTimer;
    private float _currentReloadTime;
    private Animator _firstPersonAnimator;
    private Animator _gunAnimator;

    // UI references (cached)
    private UnityEngine.UI.Text _ammoTextUI;
    private UnityEngine.UI.Image _reloadProgressUI;

    #endregion

    void Awake()
    {
        _state = GetComponent<PlayerState>();
        _network = GetComponent<PlayerNetwork>();
        _view = GetComponent<PlayerViewManager>();
        _movement = GetComponent<PlayerMovement>();
        _input = GetComponent<StarterAssets.StarterAssetsInputs>();
    }

    void Start()
    {
        currentAmmo = maxAmmo;
        CurrentSpread = BaseSpread;

        if (isLocalPlayer)
        {
            CacheUI();
            UpdateAmmoUI();
        }
    }

    void Update()
    {
        if (!isLocalPlayer) return;

        var character = GetComponent<PlayerCharacter>();
        if (character != null && character.isDead) return;
        if (_state != null && _state.isDrinking) return;

        // Fire timer
        if (_fireTimer > 0)
            _fireTimer -= Time.deltaTime;

        // Spread decay
        CalculateCurrentSpread();

        // Recoil smoothing
        UpdateFpRecoil();

        // Reload progress
        if (IsReloading)
            UpdateReloadProgress();

        // Fire input
        bool fireHeld = Input.GetMouseButton(0);
        if (fireHeld && CanShoot && _state.isHoldingGun && _fireTimer <= 0 &&
            !IsReloading && currentAmmo > 0 && !_state.isInspecting)
        {
            if (_input.sprint)
            {
                _input.sprint = false;
                return;
            }

            TryFire();
        }

        // Reload input
        if (Input.GetKeyDown(KeyCode.Z) && _state.isHoldingGun &&
            !IsReloading && currentAmmo < maxAmmo && !_state.isInspecting)
        {
            StartReload();
        }

        // Find animator references lazily
        if (_firstPersonAnimator == null && _view != null && _view.firstPersonModule != null)
            _firstPersonAnimator = _view.firstPersonModule.GetComponentInChildren<Animator>();
    }

    #region Shooting

    public void TryFire()
    {
        CalculateCurrentSpread();
        CurrentSpread = Mathf.Min(CurrentSpread + SpreadPerShot, MaxSpread);
        ApplyFpRecoil();

        currentAmmo--;
        ShotsFired++;
        _state.currentAmmo = currentAmmo;
        UpdateAmmoUI();

        Camera currentCamera = (_view != null && _view.isFirstPerson) ? _view.fpCamera : Camera.main;
        if (currentCamera == null) currentCamera = Camera.main;

        Ray baseRay = currentCamera.ViewportPointToRay(new Vector3(0.5f, 0.5f, 0f));
        Vector3 shootDirection = baseRay.direction;

        bool isFirstPerson = _view != null && _view.isFirstPerson;
        if (isFirstPerson && _state.isHoldingGun)
        {
            float randomX = Random.Range(-CurrentSpread, CurrentSpread);
            float randomY = Random.Range(-CurrentSpread, CurrentSpread);
            Quaternion spreadRotation = Quaternion.Euler(randomY, randomX, 0f);
            shootDirection = spreadRotation * baseRay.direction;
        }

        Vector3 muzzlePos = isFirstPerson && firstPersonMuzzle != null
            ? firstPersonMuzzle.position
            : thirdPersonMuzzle != null
                ? thirdPersonMuzzle.position
                : transform.position + transform.forward;

        _network.CmdFire(shootDirection, muzzlePos);

        _fireTimer = FireRate;
        OnFire?.Invoke();
    }

    public void OnServerShotFired()
    {
        ShotsFired++;
    }

    #endregion

    #region Spread

    private void CalculateCurrentSpread()
    {
        float finalSpread = BaseSpread;
        if (_input != null)
        {
            if (_input.sprint)
                finalSpread *= SprintSpreadMultiplier;
            else if (_input.move.sqrMagnitude > 0.01f)
                finalSpread *= WalkSpreadMultiplier;
        }
        if (Input.GetMouseButton(1))
            finalSpread *= AimSpreadMultiplier;

        IsAiming = Input.GetMouseButton(1) && _state.isHoldingGun;
        CurrentSpread = Mathf.Lerp(CurrentSpread, finalSpread, Time.deltaTime * SpreadDecaySpeed);
    }

    #endregion

    #region Recoil (Legacy - can be replaced by LPSP RecoilMotion)

    private void ApplyFpRecoil()
    {
        if (_view == null || !_view.isFirstPerson) return;
        float verticalRecoil = FpVerticalRecoil * Mathf.Pow(RecoilRampMultiplier, ShotsFired);
        float horizontalRecoil = Random.Range(-FpHorizontalRecoil, FpHorizontalRecoil) *
            Mathf.Pow(RecoilRampMultiplier, ShotsFired);
        TargetRecoilOffset.x = Mathf.Clamp(TargetRecoilOffset.x + verticalRecoil, 0, MaxRecoilAngle);
        TargetRecoilOffset.y = Mathf.Clamp(TargetRecoilOffset.y + horizontalRecoil, -MaxRecoilAngle / 2,
            MaxRecoilAngle / 2);
    }

    private void UpdateFpRecoil()
    {
        if (_view == null || !_view.isFirstPerson)
        {
            TargetRecoilOffset = Vector2.Lerp(TargetRecoilOffset, Vector2.zero,
                Time.deltaTime * RecoilReturnSpeed * 2f);
            CurrentRecoilOffset = Vector2.Lerp(CurrentRecoilOffset, TargetRecoilOffset,
                Time.deltaTime * RecoilSmoothSpeed);
            return;
        }

        if (!Input.GetMouseButton(0))
        {
            TargetRecoilOffset = Vector2.Lerp(TargetRecoilOffset, Vector2.zero,
                Time.deltaTime * RecoilReturnSpeed);
            ShotsFired = 0;
        }
        CurrentRecoilOffset = Vector2.Lerp(CurrentRecoilOffset, TargetRecoilOffset,
            Time.deltaTime * RecoilSmoothSpeed);
    }

    #endregion

    #region Reload

    public void StartReload()
    {
        IsReloading = true;
        _currentReloadTime = 0f;
        ShotsFired = 0;
        TargetRecoilOffset = Vector2.zero;
        CurrentRecoilOffset = Vector2.zero;
        CurrentSpread = BaseSpread;
        _state.isReloading = true;

        if (_reloadProgressUI != null)
        {
            _reloadProgressUI.fillAmount = 0;
            _reloadProgressUI.gameObject.SetActive(true);
        }

        var animatorHash_Reload = Animator.StringToHash("Reload");
        if (_gunAnimator != null)
        {
            _gunAnimator.SetTrigger(animatorHash_Reload);
            _gunAnimator.SetBool("Reloading", true);
        }
        if (_firstPersonAnimator != null)
        {
            _firstPersonAnimator.SetTrigger(animatorHash_Reload);
            _firstPersonAnimator.SetBool("Reloading", true);
        }

        OnReloadStart?.Invoke();
    }

    private void UpdateReloadProgress()
    {
        _currentReloadTime += Time.deltaTime;
        float progress = _currentReloadTime / reloadDuration;

        if (_reloadProgressUI != null)
            _reloadProgressUI.fillAmount = progress;

        if (progress >= 1f)
            CompleteReload();
    }

    public void CompleteReload()
    {
        IsReloading = false;
        currentAmmo = maxAmmo;
        _state.currentAmmo = currentAmmo;
        _state.isReloading = false;
        UpdateAmmoUI();

        if (_reloadProgressUI != null)
        {
            _reloadProgressUI.fillAmount = 0;
            _reloadProgressUI.gameObject.SetActive(false);
        }

        if (_firstPersonAnimator != null) _firstPersonAnimator.SetBool("Reloading", false);
        if (_gunAnimator != null) _gunAnimator.SetBool("Reloading", false);

        OnReloadComplete?.Invoke();
    }

    #endregion

    #region UI

    private void CacheUI()
    {
        GameObject ammoObj = GameObject.FindGameObjectWithTag("AmmoText");
        if (ammoObj != null) _ammoTextUI = ammoObj.GetComponent<UnityEngine.UI.Text>();

        GameObject reloadObj = GameObject.FindGameObjectWithTag("ReloadUI");
        if (reloadObj != null)
        {
            _reloadProgressUI = reloadObj.GetComponent<UnityEngine.UI.Image>();
            _reloadProgressUI.fillAmount = 0;
            _reloadProgressUI.gameObject.SetActive(false);
        }
    }

    private void UpdateAmmoUI()
    {
        if (_ammoTextUI != null)
            _ammoTextUI.text = currentAmmo + "/" + maxAmmo;
    }

    #endregion
}
