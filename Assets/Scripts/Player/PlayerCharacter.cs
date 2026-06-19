using UnityEngine;
using UnityEngine.AI;
using System.Collections;
using System.Collections.Generic;
using Mirror;
using UnityEngine.UI;

// 继承NetworkBehaviour实现网络同步
public class PlayerCharacter : NetworkBehaviour
{
    public float MaxHealth = 100f;

    [SyncVar(hook = nameof(OnHealthChanged))]
    public float CurrentHealth;

    [SyncVar] public bool isDead;

    // 布娃娃组件缓存
    private Animator _animator;
    private RuntimeAnimatorController _originalController;
    private CharacterController _characterController;
    private NavMeshAgent _navMeshAgent;
    private Collider[] _rootColliders;
    private Rigidbody[] _boneRigidbodies;
    private Collider[] _boneColliders;

    [Tooltip("BehaviourTreeOwner")]
    public MonoBehaviour behaviourTreeOwner;
    [Tooltip("拖拽 NetworkAnimator")]
    public NetworkAnimator networkAnimator;

    [Header("死亡UI")]
    public GameObject deathCanvas;
    public GameObject playerVisual;

    [Header("死亡视角（本地玩家）")]
    public GameObject deathThirdPersonModel;   // 死亡时显示第三人称模型
    public GameObject deathFirstPersonModel;   // 死亡时隐藏第一人称模型
    public GameObject deathFirstPersonModelGun; // 死亡时隐藏第一人称枪
    public Camera deadCamera;                  // 死亡时启用的相机

    [Header("受伤方向指示器")]
    [Tooltip("拖入 DamageIndicators prefab（Assets/Resources/DamageIndicators.prefab）")]
    public GameObject damageIndicatorPrefab;

    [Header("血条设置")]
    public Image healthFillImage;

    private void Awake()
    {
        CurrentHealth = MaxHealth;
        CacheRagdollComponents();
    }

    /// <summary>缓存布娃娃相关的组件引用</summary>
    private void CacheRagdollComponents()
    {
        _animator = GetComponent<Animator>();
        if (_animator != null) _originalController = _animator.runtimeAnimatorController;

        // Player_FPS_TP 的 3P Animator 在子物体上，从 PlayerNetworkBridge 获取
        if (_animator == null)
        {
            var pnb = GetComponent<StarterAssets.PlayerNetworkBridge>();
            if (pnb != null) _animator = pnb.TpAnimator;
            if (_animator != null) _originalController = _animator.runtimeAnimatorController;
        }

        _characterController = GetComponent<CharacterController>();
        _navMeshAgent = GetComponent<NavMeshAgent>();
        _rootColliders = GetComponents<Collider>();

        // 仅本地玩家：缓存 3P 骨骼 Rigidbody/Collider，存活时冻结骨骼+关闭碰撞体。
        // 远程玩家 3P 模型始终活跃，Animator 正常驱动骨骼，不需要干预。
        if (isLocalPlayer && _animator != null)
        {
            _boneRigidbodies = _animator.GetComponentsInChildren<Rigidbody>(true);
            SetBoneKinematic(true);

            _boneColliders = _animator.GetComponentsInChildren<Collider>(true);
            SetBoneCollidersEnabled(false);
        }
    }

    /// <summary>启用布娃娃物理（死亡时调用）</summary>
    private void EnableRagdoll()
    {
        // 1. 冻结骨骼在动画姿态（kinematic + collider 关闭状态）
        SetBoneKinematic(true);

        if (_animator != null)
        {
            _animator.cullingMode = AnimatorCullingMode.AlwaysAnimate;
            _animator.runtimeAnimatorController = null;
            _animator.Update(0);
        }

        // 强制 SMR 不因包围盒问题被裁剪（布娃娃倒地后骨骼超出原始包围盒）
        foreach (var smr in GetComponentsInChildren<SkinnedMeshRenderer>(true))
            smr.updateWhenOffscreen = true;

        if (_characterController != null) _characterController.enabled = false;
        if (_navMeshAgent != null) _navMeshAgent.enabled = false;
        if (behaviourTreeOwner != null) behaviourTreeOwner.enabled = false;
        if (networkAnimator != null) networkAnimator.enabled = false;
        foreach (var col in _rootColliders) col.enabled = false;

        // 2. 开启骨骼碰撞体 + 解锁 kinematic → 布娃娃从当前动画姿态自然下落
        SetBoneCollidersEnabled(true);
        SetBoneKinematic(false);
    }

    /// <summary>设置 3P 骨骼 Rigidbody 的运动学状态。存活时 true，死亡时 false。</summary>
    private void SetBoneKinematic(bool kinematic)
    {
        if (_boneRigidbodies == null) return;
        foreach (var rb in _boneRigidbodies)
        {
            if (rb != null) rb.isKinematic = kinematic;
        }
    }

    /// <summary>开关 3P 骨骼碰撞体。存活时 false（避免干扰 CharacterController），死亡时 true。</summary>
    private void SetBoneCollidersEnabled(bool enabled)
    {
        if (_boneColliders == null) return;
        foreach (var col in _boneColliders)
        {
            if (col != null) col.enabled = enabled;
        }
    }

    private void Start()
    {


        // 本地玩家：自动查找 死亡UI
        if (isLocalPlayer)
        {
            if (deathCanvas == null)
            {
                deathCanvas = GameObject.FindWithTag("DeathCanvas");
            }
            if (deathCanvas != null)
                deathCanvas.SetActive(false);


            // 自动通过标签查找自己的血条（你要求的标签绑定）
            if (healthFillImage == null)
            {
                GameObject hpBar = GameObject.FindWithTag("HealthBar");
                if (hpBar != null)
                {
                    healthFillImage = hpBar.GetComponent<Image>();
                }
            }
        }

        // 初始化血条显示
        UpdateHealthUI();
    }

    // 服务端扣血，保证数据安全
    [Server]
    public void TakeDamage(float damage, NetworkIdentity killerIdentity = null, Vector3 attackerPosition = default)
    {
        if (isDead) return;

        CurrentHealth = Mathf.Max(0, CurrentHealth - damage);

        // 向被击中的客户端发送伤害方向（仅玩家，Bot 无 connectionToClient）
        if (connectionToClient != null && attackerPosition != Vector3.zero)
            TargetShowDamageDirection(connectionToClient, attackerPosition);

        if (CurrentHealth <= 0)
        {
            Die(killerIdentity);
        }
    }

    // 服务端加血方法
    [Server]
    public void Heal(float amount)
    {
        if (isDead) return;
        CurrentHealth = Mathf.Min(CurrentHealth + amount, MaxHealth);
    }

    // 服务端死亡逻辑：销毁旧实例，委托 RoomManager 重建
    [Server]
    void Die(NetworkIdentity killerIdentity = null)
    {
        if (isDead) return;
        isDead = true;

        // 立即禁用 Bot 行为树和寻路，防止死亡后 1 帧内仍执行 AI 动作
        if (behaviourTreeOwner != null) behaviourTreeOwner.enabled = false;
        if (_navMeshAgent != null) _navMeshAgent.enabled = false;

        // 击杀计分 + 击杀播报 + 死亡统计
        ProcessKillScoring(killerIdentity);

        RpcOnDie();

        int teamId = BotController.GetTeamId(this);
        NetworkConnectionToClient conn = connectionToClient;

        if (MyNetworkRoomManager.instance != null)
        {
            if (conn != null)
                MyNetworkRoomManager.instance.QueuePlayerRespawn(conn, teamId, gameObject);
            else
            {
                BotController bc = GetComponent<BotController>();
                string botName = bc != null ? bc.displayName : null;
                MyNetworkRoomManager.instance.QueueBotRespawn(teamId, gameObject, botName);
            }
        }
        else
        {
            Debug.LogError("[PlayerCharacter] MyNetworkRoomManager.instance is null");
            NetworkServer.Destroy(gameObject);
        }
    }

    /// <summary>
    /// [Server] 从 killerIdentity 收集击杀者/被击杀者名字和队伍，报告计分、播报击杀、统计死亡。
    /// </summary>
    [Server]
    void ProcessKillScoring(NetworkIdentity killerIdentity)
    {
        string killerName = "未知";
        string victimName = "未知";
        int killerTeam = -1;
        int victimTeam = BotController.GetTeamId(this);

        // 获取被击杀者名字
        if (connectionToClient != null)
        {
            var victimPnb = GetComponent<StarterAssets.PlayerNetworkBridge>();
            victimName = victimPnb != null && !string.IsNullOrEmpty(victimPnb.playerName)
                ? victimPnb.playerName
                : $"Player {netId}";
        }
        else
        {
            var victimBc = GetComponent<BotController>();
            victimName = victimBc != null && !string.IsNullOrEmpty(victimBc.displayName)
                ? victimBc.displayName
                : "未知";
        }

        if (killerIdentity != null)
        {
            PlayerCharacter killerChar = killerIdentity.GetComponent<PlayerCharacter>();
            if (killerChar != null)
            {
                killerTeam = BotController.GetTeamId(killerChar);
                if (killerTeam >= 0 && killerTeam != victimTeam)
                {
                    if (TeamScoreManager.Instance != null)
                        TeamScoreManager.Instance.AddKill(killerTeam);
                }
            }

            // 获取击杀者名字
            if (killerIdentity.connectionToClient != null)
            {
                var killerPnb = killerIdentity.GetComponent<StarterAssets.PlayerNetworkBridge>();
                killerName = killerPnb != null && !string.IsNullOrEmpty(killerPnb.playerName)
                    ? killerPnb.playerName
                    : $"Player {killerIdentity.netId}";
            }
            else
            {
                var killerBc = killerIdentity.GetComponent<BotController>();
                killerName = killerBc != null && !string.IsNullOrEmpty(killerBc.displayName)
                    ? killerBc.displayName
                    : "未知";
            }

            // 追踪击杀者个人击杀数（Human 玩家专用）
            if (killerIdentity.connectionToClient != null)
            {
                if (PlayerStatsManager.Instance != null)
                    PlayerStatsManager.Instance.AddKill(killerIdentity.connectionToClient);
            }
            else
            {
                // 击杀者是 Bot
                var killerBc = killerIdentity.GetComponent<BotController>();
                if (killerBc != null)
                    PlayerStatsManager.Instance?.AddBotKill(killerBc.displayName);
            }
        }

        // 追踪被击杀者死亡数
        if (connectionToClient != null)
        {
            if (PlayerStatsManager.Instance != null)
                PlayerStatsManager.Instance.AddDeath(connectionToClient);
        }
        else
        {
            // 被击杀者是 Bot
            var victimBc = GetComponent<BotController>();
            if (victimBc != null)
                PlayerStatsManager.Instance?.AddBotDeath(victimBc.displayName);
        }

        // 人类玩家懒记录名字和队伍（确保跨复活/重连后结算数据完整）
        var ps = PlayerStatsManager.Instance;
        if (ps != null)
        {
            if (killerIdentity != null && killerIdentity.connectionToClient != null)
            {
                ps.RecordPlayerName(killerIdentity.connectionToClient, killerName);
                ps.RecordPlayerTeam(killerIdentity.connectionToClient.connectionId, killerTeam);
            }
            if (connectionToClient != null)
            {
                ps.RecordPlayerName(connectionToClient, victimName);
                ps.RecordPlayerTeam(connectionToClient.connectionId, victimTeam);
            }
        }

        // 广播击杀播报到所有客户端（通过场景 NB 确保远端可靠接收）
        if (TeamScoreManager.Instance != null)
            TeamScoreManager.Instance.RpcAddKillEntry(killerName, victimName, killerTeam, victimTeam);
    }

    // 客户端同步死亡表现
    [ClientRpc]
    void RpcOnDie()
    {
        EnableRagdoll();

        if (isLocalPlayer)
        {
            if (deathCanvas != null)
                deathCanvas.SetActive(true);
            if (deathFirstPersonModel != null)
                deathFirstPersonModel.SetActive(false);
            if (deathFirstPersonModelGun != null)
                deathFirstPersonModelGun.SetActive(false);
            if (deathThirdPersonModel != null)
                deathThirdPersonModel.SetActive(true);
            if (deadCamera != null)
                deadCamera.gameObject.SetActive(true);
        }
    }


    // 血量变化时自动更新UI
    void OnHealthChanged(float oldHp, float newHp)
    {
        UpdateHealthUI();
    }

    // 更新血条显示（横向填充）
    void UpdateHealthUI()
    {
        if (healthFillImage == null) return;

        // 计算 0~1 填充值
        float fillAmount = CurrentHealth / MaxHealth;
        healthFillImage.fillAmount = fillAmount;
    }

    /// <summary>
    /// 服务端→客户端：通知被击中的玩家伤害来源方向。
    /// 在客户端创建或找到 DamageIndicatorManager 并显示方向指示器。
    /// </summary>
    [TargetRpc]
    private void TargetShowDamageDirection(NetworkConnection target, Vector3 attackerWorldPos)
    {
        if (attackerWorldPos == Vector3.zero) return;

        if (_cachedDamageIndicators == null)
        {
            _cachedDamageIndicators = FindObjectOfType<DamageIndicatorManager>();
            if (_cachedDamageIndicators == null)
            {
                Canvas canvas = FindObjectOfType<Canvas>();
                if (canvas != null && damageIndicatorPrefab != null)
                {
                    GameObject go = Instantiate(damageIndicatorPrefab, canvas.transform);
                    _cachedDamageIndicators = go.GetComponent<DamageIndicatorManager>();
                }
            }
        }
        _cachedDamageIndicators?.ShowIndicator(attackerWorldPos);
    }

    private static DamageIndicatorManager _cachedDamageIndicators;
}