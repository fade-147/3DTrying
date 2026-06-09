using UnityEngine;
using UnityEngine.AI;
using Mirror;
using NodeCanvas.Framework;
using StarterAssets;
using System.Collections.Generic;

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
    [SerializeField] private float fireRate = 0.35f;
    [SerializeField] private float aimSmoothTime = 0.1f;
    [SerializeField] private float spreadAngle = 2f;
    [SerializeField] private float hitProbability = 0.7f;

    [SyncVar] public int teamId;
    [SyncVar] public int currentAmmo = 30;
    [SyncVar] public bool isReloading;
    [SyncVar] public bool isDrinking;

    public const int MaxAmmo = 30;
    public const float DetectionRange = 50f;
    public const string RedBaseTag = "RedBase";
    public const string BlueBaseTag = "BlueBase";
    public const string TargetEnemyVarName = "targetEnemy";

    private NavMeshAgent _navMeshAgent;
    private Animator _animator;
    private PlayerCharacter _playerChar;
    private Blackboard _blackboard;

    private float _baseSpeed;
    private float _fireTimer;

    // 巡逻记忆：避免短时间内重复访问同一区域
    private readonly Queue<Vector3> _visitedPositions = new Queue<Vector3>();
    private const int MaxVisitedMemory = 10;
    private const float PatrolRevisitRadius = 10f;
    private const float PatrolRadius = 30f;
    private const int MaxPatrolSamples = 20;

    // 策略区记忆：避免短时间内重复去同一区
    private readonly Queue<StrategyZone> _visitedZones = new Queue<StrategyZone>();
    private const int MaxVisitedZones = 3;
    private StrategyZone _currentZone;

    // Animator 参数 hash
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

        if (_animator != null)
        {
            _animator.enabled = false;
            _animator.enabled = true;
            _animator.Rebind();
            _animator.Play(0, 0);
        }

        _baseSpeed = _navMeshAgent != null ? _navMeshAgent.speed : 3.5f;
    }

    public override void OnStartServer()
    {
        base.OnStartServer();
        currentAmmo = MaxAmmo;

        var bto = GetComponent<NodeCanvas.BehaviourTrees.BehaviourTreeOwner>();
        if (bto != null)
        {
            if (bto.isRunning)
            {
                Debug.Log($"[BotController] OnStartServer: teamId={teamId}, pos={transform.position}, BT already running");
            }
            else
            {
                bto.StartBehaviour();
                Debug.Log($"[BotController] OnStartServer: teamId={teamId}, pos={transform.position}, BT started, graph={(bto.graph != null ? bto.graph.name : "NULL")}");
            }
        }
        else
        {
            Debug.LogWarning($"[BotController] OnStartServer: teamId={teamId}, pos={transform.position}, BehaviourTreeOwner NOT FOUND!");
        }
    }

    /// <summary>
    /// 查找最近的不同队伍目标（玩家或人机），写入黑版 targetEnemy。
    /// 无目标时清除黑版变量，防止残留旧引用导致巡逻误退出。
    /// </summary>
    public void FindTargetEnemy()
    {
        if (_blackboard == null) return;

        GameObject nearest = null;
        float nearestDist = Mathf.Infinity;

        PlayerCharacter[] allChars = FindObjectsByType<PlayerCharacter>(FindObjectsSortMode.None);
        foreach (PlayerCharacter pc in allChars)
        {
            if (pc.isDead) continue;
            if (pc.gameObject == gameObject) continue;

            int otherTeamId = GetTeamId(pc);
            if (otherTeamId == -1 || otherTeamId == teamId) continue;

            float dist = Vector3.Distance(transform.position, pc.transform.position);
            if (dist < nearestDist)
            {
                nearestDist = dist;
                nearest = pc.gameObject;
            }
        }

        if (nearest != null)
            _blackboard.SetVariableValue(TargetEnemyVarName, nearest);
        else
            _blackboard.SetVariableValue(TargetEnemyVarName, null);
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
    /// 从 PlayerCharacter 获取队伍 ID，兼容人机（BotController）和玩家（PlayerState / PlayerNetworkBridge / ThirdPersonController）。
    /// </summary>
    public static int GetTeamId(PlayerCharacter pc)
    {
        BotController bc = pc.GetComponent<BotController>();
        if (bc != null) return bc.teamId;
        PlayerState ps = pc.GetComponent<PlayerState>();
        if (ps != null) return ps.teamId;
        PlayerNetworkBridge pnb = pc.GetComponent<PlayerNetworkBridge>();
        if (pnb != null) return pnb.teamId;
        ThirdPersonController tpc = pc.GetComponent<ThirdPersonController>();
        if (tpc != null) return tpc.teamId;
        return -1;
    }

    /// <summary>
    /// 生成一个智能巡逻点，避开最近访问过的区域，并修正 Y 坐标到 NavMesh 表面。
    /// 最多尝试 20 次随机采样，找不到合适点则回退到随机点。
    /// 采样失败则重新随机，确保返回的点在 NavMesh 上。
    /// </summary>
    public Vector3 PickPatrolPoint()
    {
        Vector3 patrolTarget = Vector3.zero;
        bool found = false;

        for (int i = 0; i < MaxPatrolSamples; i++)
        {
            Vector2 randomCircle = Random.insideUnitCircle * PatrolRadius;
            Vector3 candidate = transform.position + new Vector3(randomCircle.x, 0f, randomCircle.y);

            // 修正 Y 坐标到 NavMesh 表面
            if (NavMesh.SamplePosition(candidate, out NavMeshHit hit, 10f, NavMesh.AllAreas))
                candidate = hit.position;
            else
                continue;

            bool tooClose = false;
            foreach (Vector3 visited in _visitedPositions)
            {
                if (Vector3.Distance(candidate, visited) < PatrolRevisitRadius)
                {
                    tooClose = true;
                    break;
                }
            }

            if (!tooClose)
            {
                patrolTarget = candidate;
                found = true;
                Debug.Log($"[BotController] PickPatrolPoint: found after {i + 1} samples, target={patrolTarget}, distFromSelf={Vector3.Distance(transform.position, patrolTarget):F1}");
                break;
            }
        }

        if (!found)
        {
            // 回退：随机方向 + NavMesh 修正
            for (int i = 0; i < MaxPatrolSamples; i++)
            {
                Vector3 fallback = transform.position + new Vector3(Random.Range(-1f, 1f), 0f, Random.Range(-1f, 1f)) * PatrolRadius;
                if (NavMesh.SamplePosition(fallback, out NavMeshHit hit, 10f, NavMesh.AllAreas))
                {
                    patrolTarget = hit.position;
                    found = true;
                    Debug.Log($"[BotController] PickPatrolPoint: fallback found at sample {i + 1}, target={patrolTarget}");
                    break;
                }
            }
        }

        if (!found)
        {
            patrolTarget = transform.position;
            Debug.LogWarning($"[BotController] PickPatrolPoint: ALL SAMPLES FAILED, staying at {patrolTarget}. NavMesh status: agentOnNavMesh={_navMeshAgent != null && _navMeshAgent.isOnNavMesh}");
        }

        _visitedPositions.Enqueue(patrolTarget);
        if (_visitedPositions.Count > MaxVisitedMemory)
            _visitedPositions.Dequeue();

        return patrolTarget;
    }

    /// <summary>
    /// 从场景 StrategyZone 中智能选择一个目标区。
    /// 排除最近去过的、已被队友认领的区，按距离+权重+类型评分。
    /// </summary>
    public StrategyZone PickStrategyZone()
    {
        var allZones = StrategyZone.AllZones;
        if (allZones == null || allZones.Count == 0)
            return null;

        uint myNetId = netId;
        var mgr = BotZoneManager.Instance;

        // 已有目标区且仍有效，不重选，防止树重置时 zone 跳变
        if (_currentZone != null
            && _currentZone.IsValidForTeam(teamId)
            && !IsZoneRecentlyVisited(_currentZone)
            && (mgr == null || !mgr.IsZoneClaimedByOther(_currentZone, myNetId)))
        {
            return _currentZone;
        }

        // 旧 zone 无效，释放认领
        if (_currentZone != null && mgr != null)
        {
            mgr.ReleaseZone(myNetId);
            AddVisitedZone(_currentZone);
            _currentZone = null;
        }

        StrategyZone best = null;
        float bestScore = -1f;

        foreach (var zone in allZones)
        {
            if (zone == null) continue;
            if (!zone.IsValidForTeam(teamId)) continue;
            if (IsZoneRecentlyVisited(zone)) continue;
            if (mgr != null && mgr.IsZoneClaimedByOther(zone, myNetId)) continue;

            float dist = Vector3.Distance(transform.position, zone.WorldPosition);
            float typeWeight = zone.zoneType switch
            {
                ZoneType.Frontline => 1.5f,
                ZoneType.Defend => 1.2f,
                ZoneType.Flank => 1.0f,
                ZoneType.Roam => 0.8f,
                _ => 1f,
            };

            float score = zone.priority * typeWeight / Mathf.Max(dist, 1f);

            if (score > bestScore)
            {
                bestScore = score;
                best = zone;
            }
        }

        // 所有区都被排除：选最近的有效区
        if (best == null)
        {
            float minDist = Mathf.Infinity;
            foreach (var zone in allZones)
            {
                if (zone == null || !zone.IsValidForTeam(teamId)) continue;
                float d = Vector3.Distance(transform.position, zone.WorldPosition);
                if (d < minDist) { minDist = d; best = zone; }
            }
        }

        if (best != null)
        {
            mgr?.TryClaimZone(best, myNetId);
            _currentZone = best;
        }

        return best;
    }

    private bool IsZoneRecentlyVisited(StrategyZone zone)
    {
        foreach (var vz in _visitedZones)
            if (vz == zone) return true;
        return false;
    }

    private void AddVisitedZone(StrategyZone zone)
    {
        _visitedZones.Enqueue(zone);
        if (_visitedZones.Count > MaxVisitedZones)
            _visitedZones.Dequeue();
    }

    /// <summary>
    /// 到达当前策略区时调用，释放认领 + 标记冷却 + 清空 currentZone 以便下次选新区。
    /// </summary>
    public void ArriveAtZone()
    {
        if (_currentZone != null && BotZoneManager.Instance != null)
        {
            BotZoneManager.Instance.ReleaseZone(netId);
            AddVisitedZone(_currentZone);
            BotZoneManager.Instance.MarkZoneVisited(_currentZone);
            _currentZone = null;
        }
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
    /// 服务端生成子弹（不用 Mirror [Command]，直接 isServer 检查）。
    /// 由 BotAimAndShoot 任务调用。
    /// </summary>
    public void ServerFire(Vector3 shootDirection, Vector3 muzzlePos)
    {
        if (!isServer) return;
        if (bulletPrefab == null) return;

        GameObject bullet = Instantiate(bulletPrefab, muzzlePos, Quaternion.LookRotation(shootDirection));
        NetworkServer.Spawn(bullet);

        Bullet bulletScript = bullet.GetComponent<Bullet>();
        if (bulletScript != null)
        {
            bulletScript.ownerNetIdentity = netIdentity;
            bulletScript.HitEffect = hitEffect;
            bulletScript.BulletLifeTime = bulletLifeTime;
            bulletScript.SetupTeammateIgnore();
        }

        if (bullet.TryGetComponent<Rigidbody>(out Rigidbody rb))
        {
            rb.velocity = Vector3.zero;
            rb.AddForce(shootDirection.normalized * bulletSpeed, ForceMode.VelocityChange);
        }

        Destroy(bullet, bulletLifeTime);
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
    /// 基于命中率对射击方向添加随机散布。
    /// 命中时不加偏移，未命中时在 spreadAngle 范围内随机偏转。
    /// </summary>
    public Vector3 ApplySpread(Vector3 baseDirection)
    {
        if (Random.value <= hitProbability)
            return baseDirection;

        float spreadX = Random.Range(-spreadAngle, spreadAngle);
        float spreadY = Random.Range(-spreadAngle, spreadAngle);
        return Quaternion.Euler(spreadX, spreadY, 0f) * baseDirection;
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
