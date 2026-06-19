using UnityEngine;
using Mirror;
using InfimaGames.LowPolyShooterPack;

/// <summary>
/// Server-authoritative melee combat.
/// Client sends intent; server computes hit detection from its own transform — zero trust in client geometry.
/// </summary>
public class PlayerMelee : NetworkBehaviour
{
    #region Serialized Fields

    [Header("Melee Settings")]
    [SerializeField]
    [Tooltip("前方检测距离（米）")]
    private float meleeRange = 1.8f;

    [SerializeField]
    [Tooltip("SphereCast 球体半径（米）")]
    private float meleeRadius = 0.4f;

    [SerializeField]
    [Tooltip("每次近战伤害")]
    private float meleeDamage = 50f;

    [SerializeField]
    [Tooltip("近战冷却时间（秒）")]
    private float meleeCooldown = 0.6f;

    [SerializeField]
    [Tooltip("发起点高度偏移（米）")]
    private float chestHeight = 1.3f;

    [Header("Detection")]
    [SerializeField]
    [Tooltip("可命中层级（至少应包含 Default + Character）")]
    private LayerMask damageMask = -1;

    [Header("Visual Feedback")]
    [SerializeField]
    [Tooltip("命中特效预制体")]
    private GameObject meleeHitEffect;

    [SerializeField]
    [Tooltip("命中特效存活时间（秒）")]
    private float meleeHitEffectLifetime = 2f;

    #endregion

    #region Private Fields

    /// <summary>服务端维护的最后攻击时间，通过 SyncVar 同步防作弊</summary>
    [SyncVar]
    private double _lastMeleeTime;

    private PlayerCharacter _playerCharacter;
    private Character _character;

    #endregion

    #region Unity Lifecycle

    void Awake()
    {
        _playerCharacter = GetComponent<PlayerCharacter>();
        _character = GetComponent<Character>();

    }

    void Start()
    {
        if (!isLocalPlayer) return;

        var playerInput = GetComponent<UnityEngine.InputSystem.PlayerInput>();
        if (playerInput != null)
        {
            var meleeAction = playerInput.actions.FindAction("Melee");
            if (meleeAction != null)
            {
                meleeAction.performed += OnMeleePerformed;
                Debug.Log("[PlayerMelee] Subscribed to Melee input action.");
            }
            else
            {
                Debug.LogWarning("[PlayerMelee] Melee action not found in PlayerInput actions.");
            }
        }
    }

    void OnDestroy()
    {
        if (!isLocalPlayer) return;

        var playerInput = GetComponent<UnityEngine.InputSystem.PlayerInput>();
        if (playerInput != null)
        {
            var meleeAction = playerInput.actions.FindAction("Melee");
            if (meleeAction != null)
                meleeAction.performed -= OnMeleePerformed;
        }
    }

    #endregion

    #region Client → Server

    private void OnMeleePerformed(UnityEngine.InputSystem.InputAction.CallbackContext ctx)
    {
        Debug.Log("[PlayerMelee] Client: Melee action triggered.");
        if (!CanMelee())
        {
            Debug.LogWarning("[PlayerMelee] Client: CanMelee() returned false.");
            return;
        }

        Debug.Log("[PlayerMelee] Client: Sending CmdMelee to server.");
        CmdMelee();
    }

    private bool CanMelee()
    {
        double elapsed = NetworkTime.time - _lastMeleeTime;
        if (elapsed < meleeCooldown)
        {
            Debug.LogWarning($"[PlayerMelee] CanMelee BLOCKED: cooldown. elapsed={elapsed:F3} cooldown={meleeCooldown} NetworkTime={NetworkTime.time} _lastMeleeTime={_lastMeleeTime}");
            return false;
        }

        if (_playerCharacter != null && _playerCharacter.isDead)
        {
            Debug.LogWarning("[PlayerMelee] CanMelee BLOCKED: dead");
            return false;
        }

        if (_character != null)
        {
            if (_character.IsInspecting()) { Debug.LogWarning("[PlayerMelee] CanMelee BLOCKED: inspecting"); return false; }
            if (_character.IsThrowingGrenade()) { Debug.LogWarning("[PlayerMelee] CanMelee BLOCKED: throwingGrenade"); return false; }
        }

        return true;
    }

    #endregion

    #region Server Hit Detection

    [Command]
    private void CmdMelee()
    {
        Debug.Log($"[PlayerMelee] CmdMelee called. pos={transform.position}");

        // 1. 冷却检查
        if (NetworkTime.time - _lastMeleeTime < meleeCooldown)
        {
            Debug.LogWarning($"[PlayerMelee] BLOCKED by cooldown. elapsed={NetworkTime.time - _lastMeleeTime:F3}");
            return;
        }

        // 2. 死亡检查
        if (_playerCharacter != null && _playerCharacter.isDead)
        {
            Debug.LogWarning("[PlayerMelee] BLOCKED: attacker is dead");
            return;
        }

        // 3. 状态检查
        if (_character != null)
        {
            if (_character.IsInspecting()) { Debug.LogWarning("[PlayerMelee] BLOCKED: inspecting"); return; }
            if (_character.IsThrowingGrenade()) { Debug.LogWarning("[PlayerMelee] BLOCKED: throwing grenade"); return; }
        }

        _lastMeleeTime = NetworkTime.time;

        // 4. 计算攻击检测球体中心（前方 meleeRange * 0.6f 处，与 Bullet 投递逻辑一致）
        float height = chestHeight;
        if (_character != null && _character.IsCrouching())
            height *= 0.6f;
        Vector3 origin = transform.position + Vector3.up * height;
        Vector3 forward = transform.forward;

        float detectionRadius = meleeRange * 0.7f;  // 球体覆盖半径
        Vector3 center = origin + forward * meleeRange * 0.6f;

        Debug.Log($"[PlayerMelee] OverlapSphere center={center} radius={detectionRadius} mask={damageMask.value}");

        // 5. OverlapSphere 全量检测（仿 Bullet 的物理碰撞模型）
        Collider[] hits = Physics.OverlapSphere(center, detectionRadius, damageMask);
        Debug.Log($"[PlayerMelee] OverlapSphere found {hits.Length} collider(s)");

        Vector3 hitPoint = center;
        Vector3 hitNormal = -forward;

        foreach (Collider c in hits)
        {
            // 仿 Bullet.cs: 用 GetComponentInParent 找 PlayerCharacter
            PlayerCharacter target = c.GetComponentInParent<PlayerCharacter>();
            if (target == null) continue;
            if (target.isDead) continue;

            // 防自伤（仿 Bullet.cs: targetPlayer.netIdentity != ownerNetIdentity）
            if (target.netIdentity == netIdentity) continue;

            // 队友过滤（仿 Bullet.cs SetupTeammateIgnore 思路）
            int myTeam = _playerCharacter != null ? BotController.GetTeamId(_playerCharacter) : -1;
            int targetTeam = BotController.GetTeamId(target);
            if (myTeam >= 0 && targetTeam >= 0 && myTeam == targetTeam) continue;

            // 命中！记录碰撞点
            hitPoint = c.ClosestPoint(center);
            hitNormal = (center - hitPoint).normalized;

            Debug.Log($"[PlayerMelee] HIT target={c.name} team={targetTeam} HP before={target.CurrentHealth}");
            target.TakeDamage(meleeDamage, netIdentity, origin);
            Debug.Log($"[PlayerMelee] Damage applied. HP after={target.CurrentHealth}");
            RpcOnMeleeHit(hitPoint, hitNormal);
            return; // 只伤害第一个有效目标
        }

        Debug.LogWarning($"[PlayerMelee] NO valid target found among {hits.Length} collider(s)");
    }

    #endregion

    #region Client RPCs

    [ClientRpc]
    private void RpcOnMeleeHit(Vector3 hitPoint, Vector3 hitNormal)
    {
        if (meleeHitEffect != null)
        {
            GameObject effect = Instantiate(meleeHitEffect, hitPoint, Quaternion.LookRotation(hitNormal));
            Destroy(effect, meleeHitEffectLifetime);
        }
    }

    #endregion

    #region Editor Gizmos

#if UNITY_EDITOR
    private void OnDrawGizmosSelected()
    {
        float h = chestHeight;
        Vector3 origin = transform.position + Vector3.up * h;
        Vector3 forward = transform.forward;
        float range = meleeRange;
        float detectRadius = range * 0.7f;
        Vector3 center = origin + forward * range * 0.6f;

        // 检测球体（橙色半透明 + 线框）
        Gizmos.color = new Color(1f, 0.5f, 0f, 0.2f);
        Gizmos.DrawSphere(center, detectRadius);
        Gizmos.color = new Color(1f, 0.5f, 0f, 0.6f);
        Gizmos.DrawWireSphere(center, detectRadius);

        // 起点 → 球心方向线
        Gizmos.color = Color.yellow;
        Gizmos.DrawLine(origin, center);

        // 起点标记
        Gizmos.color = Color.green;
        Gizmos.DrawWireSphere(origin, 0.1f);
    }
#endif

    #endregion
}
