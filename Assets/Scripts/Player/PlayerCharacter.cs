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

    [Header("血条设置")]
    public Image healthFillImage;
    private float respawnTimer = 3f;

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

    /// <summary>禁用布娃娃物理（复活时调用）</summary>
    private void DisableRagdoll()
    {
        if (_animator != null)
        {
            _animator.runtimeAnimatorController = _originalController;
            _animator.cullingMode = AnimatorCullingMode.CullUpdateTransforms;
        }
        if (_characterController != null) _characterController.enabled = true;
        if (_navMeshAgent != null) _navMeshAgent.enabled = true;
        if (behaviourTreeOwner != null) behaviourTreeOwner.enabled = true;
        if (networkAnimator != null) networkAnimator.enabled = true;
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

        if (isLocalPlayer)
        {
            if (deathCanvas != null)
                deathCanvas.SetActive(false);
            if (deathFirstPersonModel != null)
                deathFirstPersonModel.SetActive(true);
            if (deathFirstPersonModelGun != null)
                deathFirstPersonModelGun.SetActive(true);
            if (deathThirdPersonModel != null)
                deathThirdPersonModel.SetActive(false);
            if (deadCamera != null)
                deadCamera.gameObject.SetActive(false);
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
}