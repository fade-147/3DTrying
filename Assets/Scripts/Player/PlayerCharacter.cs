using UnityEngine;
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

    [Header("死亡UI")]
    public GameObject deathCanvas;
    public GameObject playerVisual;

    [Header("血条设置")]
    public Image healthFillImage;
    private float respawnTimer = 3f;

    private bool _initialized;

    private void Awake()
    {
        CurrentHealth = MaxHealth;
        _initialized = true;
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
        // 同步死亡表现到所有客户端
        RpcOnDie();
        // 3秒后复活
        Invoke(nameof(Respawn), respawnTimer);
    }

    // 客户端同步死亡表现
    [ClientRpc]
    void RpcOnDie()
    {
        if (playerVisual != null)
            playerVisual.SetActive(false);

        if (isLocalPlayer && deathCanvas != null)
            deathCanvas.SetActive(true);
    }

    // 服务端复活
    [Server]
    void Respawn()
    {
        // 重置状态
        CurrentHealth = MaxHealth;
        isDead = false;

        // 随机找出生点
        NetworkStartPosition[] spawns = FindObjectsOfType<NetworkStartPosition>();
        if (spawns.Length > 0)
        {
            Transform randomSpawn = spawns[Random.Range(0, spawns.Length)].transform;
            transform.position = randomSpawn.position;
            transform.rotation = randomSpawn.rotation;
        }

        // 通知所有客户端复活
        RpcOnRespawn();
    }

    // 客户端同步复活表现
    [ClientRpc]
    void RpcOnRespawn()
    {
        if (playerVisual != null)
            playerVisual.SetActive(true);

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