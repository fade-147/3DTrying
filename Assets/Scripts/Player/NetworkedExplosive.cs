using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Mirror;

/// <summary>
/// 统一联网爆炸弹丸 — 覆盖火箭弹(RL)、榴弹(GL)、手榴弹(Grenade)。
/// 替换原 LPSP Legacy 的 ProjectileScript / GrenadeScript。
/// 服务端权威：飞行、碰撞、AOE 伤害、队友穿透。
/// </summary>
[RequireComponent(typeof(Rigidbody))]
public class NetworkedExplosive : NetworkBehaviour
{
    public enum ExplosiveType
    {
        Impact, // 碰撞即爆 (RL, GL)
        Timed,  // 定时引信 (Grenade)
    }

    #region Inspector Fields

    [Header("Flight")]
    public ExplosiveType Type = ExplosiveType.Impact;
    [Tooltip("初始发射速度 (m/s)，用于 Impact 型")]
    public float InitialSpeed = 50f;
    [Tooltip("持续加速度 (m/s²)，仅 UseConstantForce=true 时有效")]
    public float ConstantAcceleration = 100f;
    public float MaxLifetime = 10f;
    [Tooltip("恒定推力模式 (火箭弹=true, 榴弹/手榴弹=false)")]
    public bool UseConstantForce;

    [Header("Explosion")]
    [Tooltip("引信时间 (仅 Timed 型，手榴弹)")]
    public float FuseTime = 5f;
    [Tooltip("爆炸伤害半径 (m)")]
    public float ExplosionRadius = 10f;
    [Tooltip("爆炸中心最高伤害")]
    public float MaxDamage = 100f;
    [Tooltip("爆炸特效 prefab（需含 NetworkIdentity）")]
    public GameObject ExplosionEffect;

    [Header("Visuals (local)")]
    public bool UsesParticles;
    public ParticleSystem SmokeParticles;
    public ParticleSystem FlameParticles;

    [Header("Owner")]
    [HideInInspector] public NetworkIdentity ownerNetIdentity;

    #endregion

    private bool _exploded;
    private Rigidbody _rb;

    // ── Unity Lifecycle ──

    void Awake()
    {
        _rb = GetComponent<Rigidbody>();
    }

    // ── Server Lifecycle ──

    public override void OnStartServer()
    {
        base.OnStartServer();

        Debug.Log($"[NET_EXP] OnStartServer — obj={gameObject.name}, ownerNetId={(ownerNetIdentity != null ? ownerNetIdentity.netId.ToString() : "NULL")}, isServer={isServer}");

        // 队友穿透
        SetupTeammateIgnore();

        // 忽略所有其他联网弹丸（防止弹丸互撞）
        SetupProjectileIgnore();

        // 延迟一帧启用碰撞，避免出生时与发射者重叠即爆
        StartCoroutine(EnableColliderAfterFrame());

        // 定时自毁（保底）
        Destroy(gameObject, MaxLifetime);

        // 定时引信
        if (Type == ExplosiveType.Timed)
            StartCoroutine(FuseCountdown());
    }

    void FixedUpdate()
    {
        if (!isServer || _exploded) return;

        // 恒定推力（火箭弹）
        if (UseConstantForce && _rb != null)
            _rb.AddForce(transform.forward * ConstantAcceleration, ForceMode.Acceleration);

        // Impact 型（火箭/榴弹）：旋转跟随速度方向。Timed 型（手榴弹）：保留物理翻滚。
        if (Type == ExplosiveType.Impact && _rb != null && _rb.velocity != Vector3.zero)
            _rb.rotation = Quaternion.LookRotation(_rb.velocity);
    }

    // ── 队友穿透 ──

    [Server]
    void SetupTeammateIgnore()
    {
        if (ownerNetIdentity == null)
        {
            Debug.LogError("[NET_EXP] ownerNetIdentity is null — teammate ignore skipped.");
            return;
        }

        var ownerChar = ownerNetIdentity.GetComponent<PlayerCharacter>();
        if (ownerChar == null)
        {
            Debug.LogError("[NET_EXP] ownerNetIdentity has no PlayerCharacter.");
            return;
        }

        int shooterTeam = BotController.GetTeamId(ownerChar);
        Debug.Log($"[NET_EXP] SetupTeammateIgnore — shooterTeam={shooterTeam}, ownerChar.name={ownerChar.name}");

        Collider myCollider = GetComponent<Collider>();
        if (myCollider == null)
        {
            Debug.LogError("[NET_EXP] No Collider found on projectile.");
            return;
        }
        Debug.Log($"[NET_EXP] My collider: {myCollider.GetType().Name}, enabled={myCollider.enabled}, isTrigger={myCollider.isTrigger}");

        PlayerCharacter[] allChars = FindObjectsByType<PlayerCharacter>(FindObjectsSortMode.None);
        Debug.Log($"[NET_EXP] Found {allChars.Length} PlayerCharacters in scene.");
        int totalIgnored = 0;
        foreach (PlayerCharacter pc in allChars)
        {
            int pcTeam = BotController.GetTeamId(pc);
            Debug.Log($"[NET_EXP]   PC: {pc.name}, team={pcTeam}, colliders={pc.GetComponentsInChildren<Collider>().Length}");
            if (pcTeam != shooterTeam) continue;

            foreach (Collider c in pc.GetComponentsInChildren<Collider>())
            {
                Physics.IgnoreCollision(myCollider, c);
                totalIgnored++;
                Debug.Log($"[NET_EXP]     Ignored: {c.GetType().Name} on {c.gameObject.name} (layer={c.gameObject.layer})");
            }
        }
        Debug.Log($"[NET_EXP] Total colliders ignored: {totalIgnored}");
    }

    // ── 弹丸互穿（忽略所有其他联网爆炸弹丸的碰撞） ──

    void SetupProjectileIgnore()
    {
        Collider myCollider = GetComponent<Collider>();
        if (myCollider == null) return;

        NetworkedExplosive[] allExplosives = FindObjectsByType<NetworkedExplosive>(FindObjectsSortMode.None);
        int ignored = 0;
        foreach (NetworkedExplosive other in allExplosives)
        {
            if (other == this) continue;
            Collider otherCol = other.GetComponent<Collider>();
            if (otherCol != null)
            {
                Physics.IgnoreCollision(myCollider, otherCol);
                ignored++;
            }
        }
        if (ignored > 0)
            Debug.Log($"[NET_EXP] Projectile ignore: {ignored} other projectile colliders ignored.");
    }

    // ── 定时引信协程 ──

    [Server]
    IEnumerator FuseCountdown()
    {
        yield return new WaitForSeconds(FuseTime);
        if (!_exploded)
            Explode();
    }

    IEnumerator EnableColliderAfterFrame()
    {
        var col = GetComponent<Collider>();
        Debug.Log($"[NET_EXP] EnableColliderAfterFrame START — col={col?.GetType().Name}, enabled={col?.enabled}");
        if (col != null) col.enabled = false;
        yield return null; // 等一帧，弹丸已离开枪口
        if (col != null)
        {
            col.enabled = true;
            Debug.Log($"[NET_EXP] EnableColliderAfterFrame DONE — col re-enabled, pos={transform.position}");
        }
    }

    // ── 碰撞 ──

    void OnCollisionEnter(Collision other)
    {
        string otherName = other.gameObject.name;
        string otherTag = other.gameObject.tag;
        int otherLayer = other.gameObject.layer;
        var otherChar = other.gameObject.GetComponentInParent<PlayerCharacter>();
        string charInfo = otherChar != null
            ? $"PC:{otherChar.name} netId:{otherChar.netId}"
            : "no PlayerCharacter";

        Debug.Log($"[NET_EXP] OnCollisionEnter — hit={otherName} tag={otherTag} layer={otherLayer} {charInfo} | isServer={isServer} exploded={_exploded} type={Type}");

        if (!isServer || _exploded) return;

        // 防御性检查：碰撞到发射者自己则忽略
        if (ownerNetIdentity != null)
        {
            if (otherChar != null && otherChar.netIdentity == ownerNetIdentity)
            {
                Debug.Log($"[NET_EXP] → IGNORED (self-owner)");
                return;
            }
        }

        // 忽略其他爆炸弹丸（含子对象上的碰撞体）
        if (other.gameObject.GetComponentInParent<NetworkedExplosive>() != null)
        {
            Debug.Log($"[NET_EXP] → IGNORED (other explosive)");
            return;
        }

        if (Type == ExplosiveType.Impact)
        {
            Debug.Log($"[NET_EXP] → EXPLODE at {transform.position}");
            Explode();
        }
    }

    // ── AOE 爆炸 (服务端) ──

    [Server]
    void Explode()
    {
        if (_exploded) return;
        _exploded = true;

        Vector3 center = transform.position;
        Debug.Log($"[NET_EXP] EXPLODE at {center}, radius={ExplosionRadius}, maxDamage={MaxDamage}");

        // 1. 爆炸特效（网络同步，所有客户端可见）
        if (ExplosionEffect != null)
        {
            var fx = Instantiate(ExplosionEffect, center, Quaternion.identity);
            NetworkServer.Spawn(fx);
            Destroy(fx, 3f);
        }

        // 2. 客户端本地视觉处理
        RpcPlayExplosionVisuals();

        // 3. AOE 伤害
        Collider[] hits = Physics.OverlapSphere(center, ExplosionRadius);
        HashSet<PlayerCharacter> damaged = new();

        foreach (Collider hit in hits)
        {
            var target = hit.GetComponentInParent<PlayerCharacter>();
            if (target == null) continue;
            if (damaged.Contains(target)) continue;

            // 跳过持有者自己
            if (target.netIdentity == ownerNetIdentity) continue;

            float distance = Vector3.Distance(center, target.transform.position);
            float damage = MaxDamage * (1f - distance / ExplosionRadius);
            damage = Mathf.Clamp(damage, 0f, MaxDamage);

            if (damage > 0f)
            {
                damaged.Add(target);
                Vector3 attackerPos = ownerNetIdentity != null
                    ? ownerNetIdentity.transform.position
                    : center;
                target.TakeDamage(damage, ownerNetIdentity, attackerPos);
            }
        }

        // 4. 爆炸物理力
        foreach (Collider hit in hits)
        {
            Rigidbody rb = hit.GetComponent<Rigidbody>();
            if (rb != null)
                rb.AddExplosionForce(500f, center, ExplosionRadius, 3f);
        }

        // 5. 销毁弹丸
        NetworkServer.Destroy(gameObject);
    }

    // ── 客户端爆炸视觉 ──

    [ClientRpc]
    void RpcPlayExplosionVisuals()
    {
        var renderer = GetComponent<MeshRenderer>();
        if (renderer != null) renderer.enabled = false;

        if (_rb != null) _rb.isKinematic = true;

        var col = GetComponent<Collider>();
        if (col != null) col.enabled = false;

        if (UsesParticles)
        {
            if (SmokeParticles != null) SmokeParticles.Stop();
            if (FlameParticles != null) FlameParticles.Stop();
        }
    }
}
