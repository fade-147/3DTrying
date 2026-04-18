using UnityEngine;
using Mirror;

// 替代官方 NetworkAnimator，100%解决动画不同步问题
public class PlayerAnimationSync : NetworkBehaviour
{
    [Header("绑定角色 Animator")]
    public Animator animator;

    // ===================== 你角色真正用到的动画参数 =====================
    [SyncVar(hook = nameof(OnSpeedChanged))]
    public float speed;

    [SyncVar(hook = nameof(OnMotionSpeedChanged))]
    public float motionSpeed;

    [SyncVar(hook = nameof(OnGroundedChanged))]
    public bool grounded;

    [SyncVar(hook = nameof(OnJumpChanged))]
    public bool isJumping;

    [SyncVar(hook = nameof(OnFreeFallChanged))]
    public bool isFreeFall;

    [SyncVar(hook = nameof(OnMoveLeftChanged))]
    public bool moveLeft;

    [SyncVar(hook = nameof(OnMoveRightChanged))]
    public bool moveRight;

    [SyncVar(hook = nameof(OnMoveForwardChanged))]
    public bool moveForward;

    [SyncVar(hook = nameof(OnMoveBackChanged))]
    public bool moveBack;

    [SyncVar(hook = nameof(OnIsHoldingGunChanged))]
    public bool isHoldingGun;

    [SyncVar(hook = nameof(OnIsDrinkingChanged))]
    public bool isDrinking;

    // ===================== 生命周期 =====================
    void Start()
    {
        if (animator == null)
            animator = GetComponentInChildren<Animator>();
    }

    // ===================== 供 ThirdPersonController 调用 =====================
    [Command]
    public void CmdSetSpeed(float value)
    {
        speed = value;
    }

    [Command]
    public void CmdSetMotionSpeed(float value)
    {
        motionSpeed = value;
    }

    [Command]
    public void CmdSetGrounded(bool value)
    {
        grounded = value;
    }

    [Command]
    public void CmdSetJump(bool value)
    {
        isJumping = value;
    }

    [Command]
    public void CmdSetFreeFall(bool value)
    {
        isFreeFall = value;
    }

    [Command]
    public void CmdSetMoveLeft(bool value)
    {
        moveLeft = value;
    }

    [Command]
    public void CmdSetMoveRight(bool value)
    {
        moveRight = value;
    }

    [Command]
    public void CmdSetMoveForward(bool value)
    {
        moveForward = value;
    }

    [Command]
    public void CmdSetMoveBack(bool value)
    {
        moveBack = value;
    }

    [Command]
    public void CmdSetIsHoldingGun(bool value)
    {
        isHoldingGun = value;
    }

    [Command]
    public void CmdSetIsDrinking(bool value)
    {
        isDrinking = value;
    }

    // ===================== 同步钩子（自动更新所有客户端动画） =====================
    void OnSpeedChanged(float oldValue, float newValue)
    {
        if (animator) animator.SetFloat("Speed", newValue);
    }

    void OnMotionSpeedChanged(float oldValue, float newValue)
    {
        if (animator) animator.SetFloat("MotionSpeed", newValue);
    }

    void OnGroundedChanged(bool oldValue, bool newValue)
    {
        if (animator) animator.SetBool("Grounded", newValue);
    }

    void OnJumpChanged(bool oldValue, bool newValue)
    {
        if (animator) animator.SetBool("Jump", newValue);
    }

    void OnFreeFallChanged(bool oldValue, bool newValue)
    {
        if (animator) animator.SetBool("FreeFall", newValue);
    }

    void OnMoveLeftChanged(bool oldValue, bool newValue)
    {
        if (animator) animator.SetBool("MoveLeft", newValue);
    }

    void OnMoveRightChanged(bool oldValue, bool newValue)
    {
        if (animator) animator.SetBool("MoveRight", newValue);
    }

    void OnMoveForwardChanged(bool oldValue, bool newValue)
    {
        if (animator) animator.SetBool("MoveForward", newValue);
    }

    void OnMoveBackChanged(bool oldValue, bool newValue)
    {
        if (animator) animator.SetBool("MoveBack", newValue);
    }

    void OnIsHoldingGunChanged(bool oldValue, bool newValue)
    {
        if (animator) animator.SetBool("IsHoldingGun", newValue);
    }

    void OnIsDrinkingChanged(bool oldValue, bool newValue)
    {
        if (animator) animator.SetBool("IsDrinking", newValue);
    }
}