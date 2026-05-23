using UnityEngine;
using UnityEngine.AI;
using Mirror;
using NodeCanvas.Framework;
using StarterAssets;

/// <summary>
/// AI 控制组件，挂载到 PlayerArmature 上，为 NodeCanvas 行为树提供 Bot 行为能力。
/// 所有公共方法由 NodeCanvas 自定义任务调用，不直接驱动 Update。
/// </summary>
[RequireComponent(typeof(NavMeshAgent))]
[RequireComponent(typeof(Animator))]
[RequireComponent(typeof(Blackboard))]
[RequireComponent(typeof(PlayerCharacter))]
public class BotController : NetworkBehaviour
{
    [Header("References")]
    [SerializeField] private GameObject bulletPrefab;
    [SerializeField] private GameObject hitEffect;
    [SerializeField] private float bulletSpeed = 800f;
    [SerializeField] private float bulletLifeTime = 2f;

    [Header("Combat")]
    [SerializeField] private float fireRate = 0.2f;
    [SerializeField] private float aimSmoothTime = 0.1f;

    [SyncVar] public int teamId;
    [SyncVar] public int currentAmmo = 30;
    [SyncVar] public bool isReloading;
    [SyncVar] public bool isDrinking;

    public const int MaxAmmo = 30;
    public const float DetectionRange = 50f;
    public const string RedBaseTag = "RedBase";
    public const string BlueBaseTag = "BlueBase";

    private NavMeshAgent _navMeshAgent;
    private Animator _animator;
    private PlayerCharacter _playerChar;
    private Blackboard _blackboard;

    private float _baseSpeed;
    private float _fireTimer;
    private Vector3 _aimVelocity;

    // Animator 参数 hash
    private static readonly int SpeedHash = Animator.StringToHash("Speed");
    private static readonly int MoveForwardHash = Animator.StringToHash("MoveForward");
    private static readonly int IsDrinkingHash = Animator.StringToHash("IsDrinking");
    private static readonly int DrinkHash = Animator.StringToHash("Drink");
    private static readonly int IsHoldingGunHash = Animator.StringToHash("IsHoldingGun");

    private void Awake()
    {
        _navMeshAgent = GetComponent<NavMeshAgent>();
        _animator = GetComponent<Animator>();
        _playerChar = GetComponent<PlayerCharacter>();
        _blackboard = GetComponent<Blackboard>();
        if (_blackboard == null)
            Debug.LogError("[BotController] Blackboard component missing on " + gameObject.name);

        _baseSpeed = _navMeshAgent != null ? _navMeshAgent.speed : 3.5f;
    }

    public override void OnStartServer()
    {
        base.OnStartServer();
        currentAmmo = MaxAmmo;

        // 确保行为树在服务器端运行。BehaviourTreeOwner 的 OnEnable 可能在
        // Mirror 网络初始化之前触发，导致行为树未正确启动。
        var bto = GetComponent<NodeCanvas.BehaviourTrees.BehaviourTreeOwner>();
        if (bto != null)
        {
            if (!bto.isRunning)
            {
                bto.StartBehaviour();
                Debug.Log($"[BotController] BehaviourTree started: teamId={teamId}, pos={transform.position}");
            }
        }

        if (_navMeshAgent != null && !_navMeshAgent.isOnNavMesh)
            Debug.LogWarning($"[BotController] NavMeshAgent not on NavMesh: teamId={teamId}, pos={transform.position}");
    }

    /// <summary>
    /// 查找最近的不同队伍的玩家，写入黑版 targetEnemy。
    /// 由 BotFindEnemy 任务调用。
    /// </summary>
    public void FindTargetEnemy()
    {
        if (_blackboard == null) return;

        GameObject nearest = null;
        float nearestDist = Mathf.Infinity;

        ThirdPersonController[] allPlayers = FindObjectsByType<ThirdPersonController>(FindObjectsSortMode.None);
        foreach (ThirdPersonController player in allPlayers)
        {
            if (player.teamId == teamId) continue;
            if (player.GetComponent<PlayerCharacter>() is PlayerCharacter pc && pc.isDead) continue;

            float dist = Vector3.Distance(transform.position, player.transform.position);
            if (dist < nearestDist)
            {
                nearestDist = dist;
                nearest = player.gameObject;
            }
        }

        _blackboard.SetVariableValue("targetEnemy", nearest);
    }

    /// <summary>
    /// 查找敌方基地（tag 为敌方颜色），写入黑版 enemyBasePos 和随机的 flankOffset。
    /// 由 BotFindEnemyBase 任务调用。
    /// </summary>
    public void FindEnemyBase()
    {
        if (_blackboard == null) return;

        string enemyTag = teamId == 0 ? BlueBaseTag : RedBaseTag;
        GameObject enemyBase = GameObject.FindGameObjectWithTag(enemyTag);

        if (enemyBase != null)
        {
            Vector3 basePos = enemyBase.transform.position;
            _blackboard.SetVariableValue("enemyBasePos", basePos);
        }
        else
        {
            // 未找到基地标记时回退到原点
            _blackboard.SetVariableValue("enemyBasePos", Vector3.zero);
        }

        SetFlankOffset();
    }

    /// <summary>
    /// 生成一个随机侧翼偏移向量，写入黑版 flankOffset。
    /// 让多个 Bot 走不同路径，避免拥堵。
    /// </summary>
    public void SetFlankOffset()
    {
        if (_blackboard == null) return;

        Vector3 offset = new Vector3(
            Random.Range(-5f, 5f),
            0f,
            Random.Range(-3f, 3f)
        );
        _blackboard.SetVariableValue("flankOffset", offset);
    }

    /// <summary>
    /// 每帧平滑瞄准目标敌人。
    /// 由 BotAimAndShoot 的 OnUpdate 调用。
    /// </summary>
    public void AimAtTarget(Transform targetEnemy)
    {
        if (targetEnemy == null) return;

        Vector3 direction = (targetEnemy.position - transform.position).normalized;
        direction.y = 0f;
        if (direction == Vector3.zero) return;

        Quaternion targetRotation = Quaternion.LookRotation(direction);
        transform.rotation = Quaternion.Slerp(transform.rotation, targetRotation, Time.deltaTime / Mathf.Max(aimSmoothTime, 0.01f));
    }

    /// <summary>
    /// 服务端射击指令，通过 Mirror 生成子弹。
    /// 由 BotAimAndShoot 任务调用。
    /// </summary>
    [Command]
    public void CmdFire(Vector3 shootDirection, Vector3 muzzlePos)
    {
        if (bulletPrefab == null) return;

        GameObject bullet = Instantiate(bulletPrefab, muzzlePos, Quaternion.LookRotation(shootDirection));
        NetworkServer.Spawn(bullet);

        Bullet bulletScript = bullet.GetComponent<Bullet>();
        if (bulletScript != null)
        {
            bulletScript.ownerNetIdentity = netIdentity;
            bulletScript.HitEffect = hitEffect;
            bulletScript.BulletLifeTime = bulletLifeTime;
        }

        if (bullet.TryGetComponent<Rigidbody>(out Rigidbody rb))
        {
            rb.velocity = Vector3.zero;
            rb.AddForce(shootDirection.normalized * bulletSpeed, ForceMode.VelocityChange);
        }

        Destroy(bullet, bulletLifeTime);
    }

    /// <summary>
    /// 根据 NavMeshAgent 速度更新 Animator 参数。
    /// 由 BotUpdateAnim 任务每帧调用。
    /// </summary>
    public void UpdateMovementAnim()
    {
        if (_animator == null) return;

        Vector3 velocity = _navMeshAgent != null ? _navMeshAgent.velocity : Vector3.zero;

        // 世界速度转局部速度，用于 MoveForward 等方向判定
        Vector3 localVelocity = transform.InverseTransformDirection(velocity);
        float speed = velocity.magnitude;

        _animator.SetFloat(SpeedHash, speed);
        _animator.SetBool(MoveForwardHash, localVelocity.z > 0.1f);

        // 确保持枪状态为 true（Bot 始终持枪）
        _animator.SetBool(IsHoldingGunHash, true);
    }

    /// <summary>
    /// 设置 NavMeshAgent 的速度倍率。
    /// 由 BotSetSpeed 任务调用。
    /// 换弹时设 0.9 减速，喝药时设 0 停下。
    /// </summary>
    public void SetSpeedMultiplier(float multiplier)
    {
        if (_navMeshAgent == null) return;
        _navMeshAgent.speed = _baseSpeed * multiplier;
    }

    /// <summary>
    /// 当前是否有弹药。
    /// </summary>
    public bool HasAmmo()
    {
        return currentAmmo > 0;
    }

    /// <summary>
    /// 当前血量是否低于指定百分比。
    /// </summary>
    public bool IsHealthLow(float percent)
    {
        if (_playerChar == null) return false;
        return _playerChar.CurrentHealth < _playerChar.MaxHealth * percent;
    }

    /// <summary>
    /// 获取枪口世界坐标（用于子弹生成位置）。
    /// 优先尝试从子物体查找，其次使用自身位置加偏移。
    /// </summary>
    public Vector3 GetMuzzlePosition()
    {
        Transform muzzle = transform.Find("MuzzlePoint");
        if (muzzle != null) return muzzle.position;

        // 回退：自身前方 1m 处作为枪口
        return transform.position + transform.forward * 1f + Vector3.up * 1f;
    }

    /// <summary>
    /// 判断射击冷却是否完成。
    /// </summary>
    public bool CanFire()
    {
        return _fireTimer <= 0f;
    }

    /// <summary>
    /// 消耗弹药并重置射击冷却。
    /// </summary>
    public void ConsumeAmmo()
    {
        currentAmmo = Mathf.Max(0, currentAmmo - 1);
        _fireTimer = fireRate;
    }

    /// <summary>
    /// 每帧更新射击冷却计时器。
    /// 由 BotAimAndShoot 的 OnUpdate 调用。
    /// </summary>
    public void UpdateFireTimer()
    {
        if (_fireTimer > 0f)
        {
            _fireTimer -= Time.deltaTime;
        }
    }
}
