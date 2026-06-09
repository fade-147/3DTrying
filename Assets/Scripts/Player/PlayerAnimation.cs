using UnityEngine;

/// <summary>
/// Updates animator parameters for both first-person and third-person animators.
/// Extracted from ThirdPersonController.UpdateFirstPersonAnim() + AssignAnimationIDs().
/// Third-person animation logic preserved as-is.
/// </summary>
public class PlayerAnimation : MonoBehaviour
{
    [Header("Animator Refs (set in Inspector or found at runtime)")]
    public Animator thirdPersonAnimator;
    public Animator firstPersonAnimator;
    public Animator gunAnimator;

    // Animation parameter hashes
    private int _animIDSpeed;
    private int _animIDGrounded;
    private int _animIDJump;
    private int _animIDFreeFall;
    private int _animIDMotionSpeed;
    private int _animIDMoveLeft;
    private int _animIDMoveRight;
    private int _animIDMoveForward;
    private int _animIDMoveBack;
    private int _animIDIsHoldingGun;
    private int _animIDToggleGun;
    private int _animIDInspect;
    private int _animIDInspecting;
    private int _animIDReload;

    // LPSP-style animator hashes (for new AC_LPSP_PCH.controller)
    private int _lpspMovement;
    private int _lpspRunning;
    private int _lpspHolstered;
    private int _lpspAiming;
    private int _lpspAimingAlpha;
    private int _lpspCrouching;
    private int _lpspTurning;
    private int _lpspHorizontal;
    private int _lpspVertical;
    private int _lpspReloading;
    private int _lpspInspecting;

    // References
    private PlayerMovement _movement;
    private PlayerState _state;
    private PlayerViewManager _view;
    private PlayerCombat _combat;
    private StarterAssets.StarterAssetsInputs _input;

    void Awake()
    {
        _movement = GetComponent<PlayerMovement>();
        _state = GetComponent<PlayerState>();
        _view = GetComponent<PlayerViewManager>();
        _combat = GetComponent<PlayerCombat>();
        _input = GetComponent<StarterAssets.StarterAssetsInputs>();
    }

    void Start()
    {
        AssignAnimationIDs();
    }

    void Update()
    {
        if (_state == null || _input == null) return;

        UpdateThirdPersonAnimator();
        UpdateFirstPersonAnimator();
    }

    void LateUpdate()
    {
        if (_state == null) return;
        UpdateFirstPersonInspecting();
    }

    #region Animation ID Assignment

    private void AssignAnimationIDs()
    {
        // Third-person (StarterAssets style)
        _animIDSpeed = Animator.StringToHash("Speed");
        _animIDGrounded = Animator.StringToHash("Grounded");
        _animIDJump = Animator.StringToHash("Jump");
        _animIDFreeFall = Animator.StringToHash("FreeFall");
        _animIDMotionSpeed = Animator.StringToHash("MotionSpeed");
        _animIDMoveLeft = Animator.StringToHash("MoveLeft");
        _animIDMoveRight = Animator.StringToHash("MoveRight");
        _animIDMoveForward = Animator.StringToHash("MoveForward");
        _animIDMoveBack = Animator.StringToHash("MoveBack");
        _animIDIsHoldingGun = Animator.StringToHash("IsHoldingGun");
        _animIDToggleGun = Animator.StringToHash("ToggleGun");
        _animIDInspect = Animator.StringToHash("Inspect");
        _animIDInspecting = Animator.StringToHash("inspecting");
        _animIDReload = Animator.StringToHash("Reload");

        // First-person (LPSP style)
        _lpspMovement = Animator.StringToHash("Movement");
        _lpspRunning = Animator.StringToHash("Running");
        _lpspHolstered = Animator.StringToHash("Holstered");
        _lpspAiming = Animator.StringToHash("Aim");
        _lpspAimingAlpha = Animator.StringToHash("Aiming");
        _lpspCrouching = Animator.StringToHash("Crouching");
        _lpspTurning = Animator.StringToHash("Turning");
        _lpspHorizontal = Animator.StringToHash("Horizontal");
        _lpspVertical = Animator.StringToHash("Vertical");
        _lpspReloading = Animator.StringToHash("Reloading");
        _lpspInspecting = Animator.StringToHash("Inspecting");
    }

    #endregion

    #region Third-Person Animator (UNCHANGED)

    private void UpdateThirdPersonAnimator()
    {
        if (thirdPersonAnimator == null) return;

        // Grounded
        thirdPersonAnimator.SetBool(_animIDGrounded, _movement.Grounded);

        // Speed and motion
        float inputMagnitude = _input.analogMovement ? _input.move.magnitude : 1f;
        thirdPersonAnimator.SetFloat(_animIDSpeed, _movement.IsRunning ? _movement.SprintSpeed : _movement.MoveSpeed);
        thirdPersonAnimator.SetFloat(_animIDMotionSpeed, inputMagnitude);

        // Direction
        float moveX = _input.move.x;
        float moveY = _input.move.y;
        const float threshold = 0.01f;

        thirdPersonAnimator.SetBool(_animIDMoveLeft, false);
        thirdPersonAnimator.SetBool(_animIDMoveRight, false);
        thirdPersonAnimator.SetBool(_animIDMoveForward, false);
        thirdPersonAnimator.SetBool(_animIDMoveBack, false);

        if (moveX < -threshold)
            thirdPersonAnimator.SetBool(_animIDMoveLeft, true);
        else if (moveX > threshold)
            thirdPersonAnimator.SetBool(_animIDMoveRight, true);
        else if (moveY > threshold && Mathf.Abs(moveX) < threshold)
            thirdPersonAnimator.SetBool(_animIDMoveForward, true);
        else if (moveY < -threshold && Mathf.Abs(moveX) < threshold)
            thirdPersonAnimator.SetBool(_animIDMoveBack, true);

        // Jump / FreeFall
        thirdPersonAnimator.SetBool(_animIDJump, _movement.IsJumping);
        thirdPersonAnimator.SetBool(_animIDFreeFall, !_movement.Grounded && !_movement.IsJumping);

        // Holding gun
        thirdPersonAnimator.SetBool(_animIDIsHoldingGun, _state.isHoldingGun);
    }

    #endregion

    #region First-Person Animator (NEW LPSP)

    private void UpdateFirstPersonAnimator()
    {
        // Lazily find animator
        if (firstPersonAnimator == null && _view != null && _view.firstPersonModule != null)
            firstPersonAnimator = _view.firstPersonModule.GetComponentInChildren<Animator>();

        if (firstPersonAnimator == null) return;
        if (_view == null) return;

        // Only update when in first person
        bool isFirstPerson = _view.isFirstPerson;

        // Movement speed
        float inputMagnitude = _input.analogMovement ? _input.move.magnitude : 1f;
        float animationBlend = _input.sprint ? _movement.SprintSpeed : _movement.MoveSpeed;
        firstPersonAnimator.SetFloat(_lpspMovement, animationBlend);

        // Running
        firstPersonAnimator.SetBool(_lpspRunning, _input.sprint && _input.move != Vector2.zero);

        // Holstered (inverse of holding gun)
        firstPersonAnimator.SetBool(_lpspHolstered, !_state.isHoldingGun);

        // Crouching
        firstPersonAnimator.SetBool(_lpspCrouching, _movement.IsCrouching);

        // Reloading
        firstPersonAnimator.SetBool(_lpspReloading, _combat != null && _combat.IsReloading);

        // Turning (horizontal input in first person)
        firstPersonAnimator.SetFloat(_lpspTurning, _input.look.x);
        firstPersonAnimator.SetFloat(_lpspHorizontal, _input.move.x);
        firstPersonAnimator.SetFloat(_lpspVertical, _input.move.y);
    }

    private void UpdateFirstPersonInspecting()
    {
        if (firstPersonAnimator == null) return;
        firstPersonAnimator.SetBool(_lpspInspecting, _state.isInspecting);
    }

    #endregion

    #region Public Methods

    /// <summary>
    /// Set a trigger on the first-person animator.
    /// </summary>
    public void SetFPTrigger(string triggerName)
    {
        if (firstPersonAnimator != null)
            firstPersonAnimator.SetTrigger(triggerName);
    }

    /// <summary>
    /// Set a trigger on the third-person animator.
    /// </summary>
    public void SetTPTrigger(string triggerName)
    {
        if (thirdPersonAnimator != null)
            thirdPersonAnimator.SetTrigger(triggerName);
    }

    /// <summary>
    /// Set a trigger on the weapon animator.
    /// </summary>
    public void SetGunTrigger(string triggerName)
    {
        if (gunAnimator != null)
            gunAnimator.SetTrigger(triggerName);
    }

    #endregion
}
