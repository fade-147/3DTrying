using UnityEngine;
using UnityEngine.AI;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
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
    private CharacterController _characterController;
    private NavMeshAgent _navMeshAgent;
    private Collider[] _rootColliders;
    private Rigidbody[] _ragdollRigidbodies;

    [Header("死亡UI")]
    public GameObject deathCanvas;
    public GameObject playerVisual;

    [Header("血条设置")]
    public Image healthFillImage;
    private float respawnTimer = 3f;

    private void Awake()
    {
        CurrentHealth = MaxHealth;
        CacheRagdollComponents();
    }

    /// <summary>缓存布娃娃相关的 Rigidbody 和根碰撞体引用</summary>
    private void CacheRagdollComponents()
    {
        _animator = GetComponent<Animator>();
        _characterController = GetComponent<CharacterController>();
        _navMeshAgent = GetComponent<NavMeshAgent>();
        _rootColliders = GetComponents<Collider>();

        var allRbs = GetComponentsInChildren<Rigidbody>();
        _ragdollRigidbodies = allRbs.Where(rb => rb.gameObject != gameObject).ToArray();
    }

    /// <summary>启用布娃娃物理（死亡时调用）</summary>
    private void EnableRagdoll()
    {
        // 停止动画并释放骨骼控制权（Rebind 是关键——清空 Animator 对 Transform 的写入）
        if (_animator != null)
        {
            _animator.enabled = false;
            _animator.Rebind();
        }

        if (_characterController != null) _characterController.enabled = false;
        if (_navMeshAgent != null) _navMeshAgent.enabled = false;
        foreach (var col in _rootColliders) col.enabled = false;

        foreach (var rb in _ragdollRigidbodies)
            rb.isKinematic = false;
    }

    /// <summary>禁用布娃娃物理（复活时调用）</summary>
    private void DisableRagdoll()
    {
        foreach (var rb in _ragdollRigidbodies)
            rb.isKinematic = true;

        if (_animator != null) _animator.enabled = true;
        if (_characterController != null) _characterController.enabled = true;
        if (_navMeshAgent != null) _navMeshAgent.enabled = true;
        foreach (var col in _rootColliders) col.enabled = true;
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
    public void TakeDamage(float damage)
    {
        if (isDead) return;

        CurrentHealth = Mathf.Max(0, CurrentHealth - damage);
        if (CurrentHealth <= 0)
        {
            Die();
        }
    }

    // 服务端加血方法
    [Server]
    public void Heal(float amount)
    {
        if (isDead) return;
        CurrentHealth = Mathf.Min(CurrentHealth + amount, MaxHealth);
    }

    // 服务端死亡逻辑
    [Server]
    void Die()
    {
        isDead = true;
        EnableRagdoll();
        RpcOnDie();
        Invoke(nameof(Respawn), respawnTimer);
    }

    // 客户端同步死亡表现
    [ClientRpc]
    void RpcOnDie()
    {
        EnableRagdoll();

        if (isLocalPlayer && deathCanvas != null)
            deathCanvas.SetActive(true);
    }

    // 服务端复活
    [Server]
    void Respawn()
    {
        CurrentHealth = MaxHealth;
        isDead = false;
        DisableRagdoll();

        int teamId = BotController.GetTeamId(this);
        Transform spawn = MyNetworkRoomManager.instance != null
            ? MyNetworkRoomManager.instance.GetTeamRespawnPosition(teamId)
            : null;

        if (spawn != null)
        {
            transform.position = spawn.position;
            transform.rotation = spawn.rotation;
        }

        RpcOnRespawn();
    }

    // 客户端同步复活表现
    [ClientRpc]
    void RpcOnRespawn()
    {
        DisableRagdoll();

        if (isLocalPlayer && deathCanvas != null)
            deathCanvas.SetActive(false);
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
}