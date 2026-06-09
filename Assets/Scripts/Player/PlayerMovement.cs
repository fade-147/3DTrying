using UnityEngine;
using StarterAssets;

/// <summary>
/// Handles movement, jumping, gravity, and ground detection.
/// Extracted from ThirdPersonController.Move() + JumpAndGravity() + GroundedCheck().
/// Works for both first-person and third-person modes.
/// </summary>
public class PlayerMovement : MonoBehaviour
{
    #region Fields Serialized

    [Header("Speeds")]
    public float MoveSpeed = 2.0f;
    public float SprintSpeed = 5.335f;

    [Range(0.0f, 0.3f)]
    public float RotationSmoothTime = 0.12f;
    public float SpeedChangeRate = 10.0f;

    [Header("Jump & Gravity")]
    public float JumpHeight = 1.2f;
    public float Gravity = -15.0f;
    public float JumpTimeout = 0.50f;
    public float FallTimeout = 0.15f;

    [Header("Ground Detection")]
    public bool Grounded = true;
    public float GroundedOffset = -0.14f;
    public float GroundedRadius = 0.28f;
    public LayerMask GroundLayers = 1; // Default layer (bit 0)

    #endregion

    #region Public State (read by other components)

    public bool IsRunning { get; private set; }
    public bool IsJumping { get; private set; }
    public bool IsCrouching { get; private set; }
    public Vector3 Velocity => _controller != null ? _controller.velocity : Vector3.zero;
    public bool WasGrounded { get; private set; }
    public float LastJumpTime { get; private set; }
    public float MultiplierForward => 1.0f;
    public float MultiplierSideways => 1.0f;
    public float MultiplierBackwards => 1.0f;

    #endregion

    #region Private Fields

    private CharacterController _controller;
    private StarterAssetsInputs _input;
    private PlayerViewManager _view;
    private PlayerState _state;

    private float _speed;
    private float _animationBlend;
    private float _targetRotation;
    private float _rotationVelocity;
    private float _verticalVelocity;
    private float _terminalVelocity = 53.0f;
    private float _jumpTimeoutDelta;
    private float _fallTimeoutDelta;
    private const float _threshold = 0.01f;

    #endregion

    void Awake()
    {
        _controller = GetComponent<CharacterController>();
        _input = GetComponent<StarterAssetsInputs>();
        _view = GetComponent<PlayerViewManager>();
        _state = GetComponent<PlayerState>();
    }

    void Start()
    {
        _jumpTimeoutDelta = JumpTimeout;
        _fallTimeoutDelta = FallTimeout;
    }

    void Update()
    {
        // Only process movement for local player
        var identity = GetComponent<Mirror.NetworkIdentity>();
        if (identity == null || !identity.isLocalPlayer) return;

        // Skip movement if dead
        var character = GetComponent<PlayerCharacter>();
        if (character != null && character.isDead) return;

        WasGrounded = Grounded;
        JumpAndGravity();
        GroundedCheck();

        // Skip movement if drinking
        if (_state != null && _state.isDrinking) return;

        Move();
    }

    #region Movement

    private void Move()
    {
        if (_input == null) return;

        float targetSpeed = _input.sprint ? SprintSpeed : MoveSpeed;
        if (_input.move == Vector2.zero) targetSpeed = 0.0f;

        float currentHorizontalSpeed = new Vector3(_controller.velocity.x, 0.0f, _controller.velocity.z).magnitude;
        float speedOffset = 0.1f;
        float inputMagnitude = _input.analogMovement ? _input.move.magnitude : 1f;

        if (currentHorizontalSpeed < targetSpeed - speedOffset ||
            currentHorizontalSpeed > targetSpeed + speedOffset)
        {
            _speed = Mathf.Lerp(currentHorizontalSpeed, targetSpeed * inputMagnitude,
                Time.deltaTime * SpeedChangeRate);
            _speed = Mathf.Round(_speed * 1000f) / 1000f;
        }
        else
        {
            _speed = targetSpeed;
        }

        _animationBlend = Mathf.Lerp(_animationBlend, targetSpeed, Time.deltaTime * SpeedChangeRate);
        IsRunning = _input.sprint && _input.move != Vector2.zero;

        float moveX = _input.move.x;
        float moveY = _input.move.y;

        // Determine camera-forward direction based on view mode
        Vector3 cameraForward, cameraRight;

        bool isFirstPerson = _view != null && _view.isFirstPerson;
        if (isFirstPerson)
        {
            cameraForward = transform.forward;
            cameraRight = transform.right;
        }
        else
        {
            Camera mainCam = Camera.main;
            if (mainCam == null)
            {
                cameraForward = transform.forward;
                cameraRight = transform.right;
            }
            else
            {
                cameraForward = mainCam.transform.forward;
                cameraRight = mainCam.transform.right;
            }
        }
        cameraForward.y = 0;
        cameraRight.y = 0;
        cameraForward.Normalize();
        cameraRight.Normalize();

        bool isHoldingGun = _state != null && _state.isHoldingGun;

        // Always strafe relative to camera direction
        {
            Vector3 moveDirection = cameraRight * moveX + cameraForward * moveY;

            // In 3P, smoothly face camera direction (no AD rotation)
            if (!isFirstPerson && moveX == 0 && moveY == 0)
            {
                // Standing still: face forward
            }
            else if (!isFirstPerson)
            {
                Camera mainCam = Camera.main;
                _targetRotation = mainCam != null ? mainCam.transform.eulerAngles.y : transform.eulerAngles.y;
                float rotation = Mathf.SmoothDampAngle(transform.eulerAngles.y, _targetRotation,
                    ref _rotationVelocity, RotationSmoothTime);
                transform.rotation = Quaternion.Euler(0.0f, rotation, 0.0f);
            }

            _controller.Move(moveDirection.normalized * (_speed * Time.deltaTime) +
                new Vector3(0.0f, _verticalVelocity, 0.0f) * Time.deltaTime);
        }
    }

    #endregion

    #region Jump & Gravity

    private void JumpAndGravity()
    {
        if (Grounded)
        {
            _fallTimeoutDelta = FallTimeout;
            if (_verticalVelocity < 0.0f)
                _verticalVelocity = -2f;

            if (_input.jump && _jumpTimeoutDelta <= 0.0f)
            {
                Jump();
            }

            if (_jumpTimeoutDelta >= 0.0f)
                _jumpTimeoutDelta -= Time.deltaTime;
        }
        else
        {
            _jumpTimeoutDelta = JumpTimeout;
            if (_fallTimeoutDelta >= 0.0f)
                _fallTimeoutDelta -= Time.deltaTime;

            _input.jump = false;
        }

        if (_verticalVelocity < _terminalVelocity)
            _verticalVelocity += Gravity * Time.deltaTime;

        IsJumping = !Grounded && _verticalVelocity > 0;
    }

    public void Jump()
    {
        _verticalVelocity = Mathf.Sqrt(JumpHeight * -2f * Gravity);
        LastJumpTime = Time.time;
    }

    #endregion

    #region Ground Detection

    private void GroundedCheck()
    {
        Vector3 spherePosition = new Vector3(transform.position.x, transform.position.y - GroundedOffset,
            transform.position.z);
        Grounded = Physics.CheckSphere(spherePosition, GroundedRadius, GroundLayers,
            QueryTriggerInteraction.Ignore);
    }

    void OnDrawGizmosSelected()
    {
        Color transparentGreen = new Color(0.0f, 1.0f, 0.0f, 0.35f);
        Color transparentRed = new Color(1.0f, 0.0f, 0.0f, 0.35f);
        Gizmos.color = Grounded ? transparentGreen : transparentRed;
        Gizmos.DrawSphere(
            new Vector3(transform.position.x, transform.position.y - GroundedOffset, transform.position.z),
            GroundedRadius);
    }

    #endregion

    #region Crouching

    public bool CanCrouch(bool newCrouching)
    {
        // If trying to stand up, check for ceiling
        if (!newCrouching)
        {
            float checkHeight = _controller.height * 0.5f + _controller.radius;
            Vector3 checkOrigin = transform.position + Vector3.up * (_controller.height * 0.5f - _controller.radius);
            return !Physics.SphereCast(checkOrigin, _controller.radius, Vector3.up, out _, checkHeight, ~0,
                QueryTriggerInteraction.Ignore);
        }
        return true;
    }

    public void Crouch(bool crouching)
    {
        IsCrouching = crouching;
        _controller.height = crouching ? 1.0f : 1.8f;
        _controller.center = crouching
            ? new Vector3(0, 0.5f, 0)
            : new Vector3(0, 1.0f, 0);
    }

    public void TryCrouch(bool value)
    {
        if (CanCrouch(value))
            Crouch(value);
    }

    public void TryToggleCrouch()
    {
        TryCrouch(!IsCrouching);
    }

    #endregion
}
