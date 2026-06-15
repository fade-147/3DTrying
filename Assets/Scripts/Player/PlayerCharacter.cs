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
    }

    /// <summary>启用布娃娃物理（死亡时调用）</summary>
    private void EnableRagdoll()
    {
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

        // 报告击杀到计分系统（destroy 前完成）
        if (killerIdentity != null)
        {
            PlayerCharacter killerChar = killerIdentity.GetComponent<PlayerCharacter>();
            if (killerChar != null)
            {
                int killerTeam = BotController.GetTeamId(killerChar);
                int myTeam = BotController.GetTeamId(this);
                if (killerTeam >= 0 && killerTeam != myTeam)
                {
                    TeamScoreManager.Instance?.AddKill(killerTeam);
                }
            }

            // 追踪击杀者个人击杀数（Human 玩家专用，Bot 无 connectionToClient 会被过滤）
            if (killerIdentity.connectionToClient != null)
                PlayerStatsManager.Instance?.AddKill(killerIdentity.connectionToClient);
        }

        RpcOnDie();

        int teamId = BotController.GetTeamId(this);
        NetworkConnectionToClient conn = connectionToClient;

        if (MyNetworkRoomManager.instance != null)
        {
            if (conn != null)
                MyNetworkRoomManager.instance.QueuePlayerRespawn(conn, teamId, gameObject);
            else
                MyNetworkRoomManager.instance.QueueBotRespawn(teamId, gameObject);
        }
        else
        {
            Debug.LogError("[PlayerCharacter] MyNetworkRoomManager.instance is null");
            NetworkServer.Destroy(gameObject);
        }
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