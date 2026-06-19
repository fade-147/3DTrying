using UnityEngine;
using UnityEngine.AI;
using Mirror;
using NodeCanvas.Framework;
using StarterAssets;
using System.Collections.Generic;

/// <summary>
/// Bot 感知等级，控制视野锥、检测距离和射击精度。
/// Unaware: 巡逻中，正面 120 度锥形，35 单位检测范围
/// Suspicious: 听到枪声/队友受伤，正面 180 度，50 单位
/// Aware: 发现敌人但未交火，正面 240 度，50 单位
/// Engaged: 交战中，360 度全方向，60 单位，8 秒后衰减到 Aware
/// </summary>
public enum AwarenessLevel
{
    Unaware,
    Suspicious,
    Aware,
    Engaged
}

/// <summary>
/// Bot 玩法风格，影响 zone 选择偏好、交战距离和移动速度。
/// Aggressive: 偏好 Frontline，近战，高射速，速度快 10%
/// Defensive: 偏好 Defend，远战，谨慎，速度慢 10%
/// Flanker: 偏好 Flank，侧翼路线，速度略快 5%
/// Roamer: 偏好 Roam，自由巡逻，速度略慢 5%
/// </summary>
public enum BotPlayStyle
{
    Aggressive,
    Defensive,
    Flanker,
    Roamer
}

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
    [SyncVar] public string displayName = "";
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

    // Zone 类型冷却：防止 Bot 在同类 zone 间振荡
    private ZoneType _lastZoneType = (ZoneType)(-1);
    private int _sameTypeStreak;
    private float _zoneLockUntil = -1f;
    private const int MaxSameTypeStreak = 2;
    private const float MinZoneLockDuration = 8f;
    private const float MaxZoneLockDuration = 15f;

    // 个性参数
    [SyncVar] public BotPlayStyle playStyle;
    private Dictionary<ZoneType, float> _zoneTypeWeights;
    private float _preferredEngageDistance = 15f;

    // 感知状态（非 SyncVar，服务端逻辑）
    private AwarenessLevel _awareness = AwarenessLevel.Unaware;
    private Vector3 _lastHeardGunfirePos;
    private float _awarenessTimer;

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

        InitPersonality();
        BotZoneManager.Instance?.RegisterBot(this);

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

    private void OnDestroy()
    {
        BotZoneManager.Instance?.UnregisterBot(this);
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
    /// 排除最近去过的、已被队友认领的区，按距离+个性权重+类型评分。
    /// Zone 到达锁定和同类型连续访问限制防止振荡。
    /// </summary>
    public StrategyZone PickStrategyZone()
    {
        var allZones = StrategyZone.AllZones;
        if (allZones == null || allZones.Count == 0)
            return null;

        uint myNetId = netId;
        var mgr = BotZoneManager.Instance;

        // 到达锁定：锁定期内不能重选
        if (Time.time < _zoneLockUntil)
            return _currentZone;

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

            // 同类型连续访问限制：强制换类型
            if (_sameTypeStreak >= MaxSameTypeStreak && zone.zoneType == _lastZoneType)
                continue;

            float dist = Vector3.Distance(transform.position, zone.WorldPosition);

            // 使用个性权重替代硬编码值
            float typeWeight = _zoneTypeWeights != null && _zoneTypeWeights.TryGetValue(zone.zoneType, out float w)
                ? w
                : zone.zoneType switch
                {
                    ZoneType.Frontline => 1.5f,
                    ZoneType.Defend => 1.2f,
                    ZoneType.Flank => 1.0f,
                    ZoneType.Roam => 0.8f,
                    _ => 1f,
                };

            float score = zone.priority * typeWeight / Mathf.Max(dist, 1f);

            // 队友密度惩罚：避免多个 Bot 挤同一区
            if (mgr != null)
            {
                int nearbyTeammates = mgr.GetTeammateDensityNear(zone, teamId, myNetId, 30f);
                if (nearbyTeammates >= 2)
                    score *= 0.3f;
                else if (nearbyTeammates >= 1)
                    score *= 0.6f;
            }

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

            // 更新同类型连续计数
            if (best.zoneType == _lastZoneType)
                _sameTypeStreak++;
            else
            {
                _lastZoneType = best.zoneType;
                _sameTypeStreak = 1;
            }
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
    /// 设置到达锁定计时器，防止立即重选同一区引起振荡。
    /// </summary>
    public void ArriveAtZone()
    {
        _zoneLockUntil = Time.time + Random.Range(MinZoneLockDuration, MaxZoneLockDuration);

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

        // 通知场景内其他 Bot 听到枪声
        BotZoneManager.Instance?.BroadcastGunfire(muzzlePos, netId);
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
    /// 基于命中率和散布角度对射击方向添加随机偏移。
    /// 命中时不加偏移，未命中时在 effectiveSpread 范围内随机偏转。
    /// </summary>
    public Vector3 ApplySpread(Vector3 baseDirection, float effectiveHitProb, float effectiveSpread)
    {
        if (Random.value <= effectiveHitProb)
            return baseDirection;

        float spreadX = Random.Range(-effectiveSpread, effectiveSpread);
        float spreadY = Random.Range(-effectiveSpread, effectiveSpread);
        return Quaternion.Euler(spreadX, spreadY, 0f) * baseDirection;
    }

    /// <summary>
    /// 每帧更新射击冷却计时器和感知衰减。
    /// 由 BotAimAndShoot 的 OnUpdate 调用。
    /// Engaged→Aware(8s), Aware→Suspicious(5s), Suspicious→Unaware(10s)
    /// </summary>
    public void UpdateTimers()
    {
        if (_fireTimer > 0f)
            _fireTimer -= Time.deltaTime;

        _awarenessTimer += Time.deltaTime;
        switch (_awareness)
        {
            case AwarenessLevel.Engaged:
                if (_awarenessTimer > 8f) SetAwareness(AwarenessLevel.Aware);
                break;
            case AwarenessLevel.Aware:
                if (_awarenessTimer > 5f) SetAwareness(AwarenessLevel.Suspicious);
                break;
            case AwarenessLevel.Suspicious:
                if (_awarenessTimer > 10f) SetAwareness(AwarenessLevel.Unaware);
                break;
        }
    }

    /// <summary>
    /// 根据当前移动状态计算动态射击精度参数。
    /// 站立不动保持基础值；移动中精度下降、散布增大；冲刺时进一步恶化。
    /// </summary>
    public void GetDynamicAccuracy(out float effectiveHitProb, out float effectiveSpread)
    {
        float speed = _navMeshAgent != null ? _navMeshAgent.velocity.magnitude : 0f;
        bool isMoving = speed > 0.5f;
        bool isSprinting = speed > _baseSpeed * 0.7f;

        effectiveHitProb = hitProbability;
        effectiveSpread = spreadAngle;

        if (isSprinting)
        {
            effectiveHitProb *= 0.3f;
            effectiveSpread *= 4f;
        }
        else if (isMoving)
        {
            effectiveHitProb *= 0.55f;
            effectiveSpread *= 2f;
        }
    }

    /// <summary>
    /// 当前感知等级对应的敌人检测距离。
    /// Unaware 只能看到近处，Engaged 保持最大追踪距离。
    /// </summary>
    public float GetCurrentDetectionRange()
    {
        return _awareness switch
        {
            AwarenessLevel.Unaware => 35f,
            AwarenessLevel.Suspicious => 50f,
            AwarenessLevel.Aware => 50f,
            AwarenessLevel.Engaged => 60f,
            _ => DetectionRange
        };
    }

    /// <summary>
    /// 当前感知等级对应的视野锥半角（度）。
    /// Unaware=60(120°锥), Suspicious=90(180°锥), Aware=120(240°锥), Engaged=180(360°全方向)
    /// </summary>
    public float GetCurrentVisionHalfAngle()
    {
        return _awareness switch
        {
            AwarenessLevel.Unaware => 60f,
            AwarenessLevel.Suspicious => 90f,
            AwarenessLevel.Aware => 120f,
            AwarenessLevel.Engaged => 180f,
            _ => 60f
        };
    }

    /// <summary>
    /// 设置感知等级并重置等级计时器。
    /// </summary>
    public void SetAwareness(AwarenessLevel level)
    {
        _awareness = level;
        _awarenessTimer = 0f;
    }

    /// <summary>
    /// 听到枪声通知。200 单位内且当前未交战时提升到 Suspicious 等级并转向声源。
    /// </summary>
    public void OnHearGunfire(Vector3 gunfirePos)
    {
        if (_awareness == AwarenessLevel.Engaged) return;

        _lastHeardGunfirePos = gunfirePos;
        float dist = Vector3.Distance(transform.position, gunfirePos);
        if (dist < 200f && _awareness < AwarenessLevel.Suspicious)
        {
            SetAwareness(AwarenessLevel.Suspicious);
            Vector3 dir = (gunfirePos - transform.position).normalized;
            dir.y = 0f;
            if (dir != Vector3.zero)
                transform.rotation = Quaternion.LookRotation(dir);
        }
    }

    /// <summary>
    /// 被击中时直接升至 Engaged 等级。
    /// </summary>
    public void OnTakeDamage(Vector3 attackerPos)
    {
        SetAwareness(AwarenessLevel.Engaged);
        _lastHeardGunfirePos = attackerPos;
    }

    /// <summary>
    /// 个性初始化：随机分配玩法风格，据此设置 zone 偏好权重、交战距离和移动速度。
    /// </summary>
    private void InitPersonality()
    {
        playStyle = (BotPlayStyle)Random.Range(0, 4);

        _zoneTypeWeights = playStyle switch
        {
            BotPlayStyle.Aggressive => new Dictionary<ZoneType, float>
                { [ZoneType.Frontline] = 1.8f, [ZoneType.Defend] = 0.9f, [ZoneType.Flank] = 1.2f, [ZoneType.Roam] = 0.6f },
            BotPlayStyle.Defensive => new Dictionary<ZoneType, float>
                { [ZoneType.Frontline] = 0.8f, [ZoneType.Defend] = 1.8f, [ZoneType.Flank] = 0.9f, [ZoneType.Roam] = 1.0f },
            BotPlayStyle.Flanker => new Dictionary<ZoneType, float>
                { [ZoneType.Frontline] = 1.0f, [ZoneType.Defend] = 0.8f, [ZoneType.Flank] = 1.8f, [ZoneType.Roam] = 1.1f },
            BotPlayStyle.Roamer => new Dictionary<ZoneType, float>
                { [ZoneType.Frontline] = 1.0f, [ZoneType.Defend] = 1.0f, [ZoneType.Flank] = 1.0f, [ZoneType.Roam] = 1.8f },
            _ => new Dictionary<ZoneType, float>
                { [ZoneType.Frontline] = 1.5f, [ZoneType.Defend] = 1.2f, [ZoneType.Flank] = 1.0f, [ZoneType.Roam] = 0.8f },
        };

        _preferredEngageDistance = playStyle switch
        {
            BotPlayStyle.Aggressive => Random.Range(8f, 14f),
            BotPlayStyle.Defensive => Random.Range(18f, 28f),
            BotPlayStyle.Flanker => Random.Range(12f, 20f),
            BotPlayStyle.Roamer => Random.Range(10f, 22f),
            _ => 15f
        };

        _baseSpeed *= playStyle switch
        {
            BotPlayStyle.Aggressive => 1.1f,
            BotPlayStyle.Defensive => 0.9f,
            BotPlayStyle.Flanker => 1.05f,
            BotPlayStyle.Roamer => 0.95f,
            _ => 1f
        };

        if (_navMeshAgent != null)
            _navMeshAgent.speed = _baseSpeed;

        Debug.Log($"[BotController] InitPersonality: style={playStyle}, engageDist={_preferredEngageDistance:F1}, speed={_baseSpeed:F2}");
    }
}
