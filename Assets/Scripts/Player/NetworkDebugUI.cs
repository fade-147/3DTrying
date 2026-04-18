using Mirror;
using StarterAssets;
using UnityEngine;
using UnityEngine.UI;

public class NetworkDebugUI : MonoBehaviour
{
    [Header("UI引用 - 通过标签自动查找")]
    public Text debugText; // 可以拖拽，或通过标签"DebugText"查找

    [Header("调试设置")]
    public bool showDebug = true;
    public float updateInterval = 0.5f;

    private float timer;
    private string debugInfo;

    void Start()
    {
        // 自动查找UI
        if (debugText == null)
        {
            GameObject debugObj = GameObject.FindWithTag("DebugText");
            if (debugObj != null)
                debugText = debugObj.GetComponent<Text>();
        }

        if (debugText == null)
            Debug.LogWarning("未找到DebugText标签的UI，请创建Text并设置标签");
    }

    void Update()
    {
        if (!showDebug || debugText == null) return;

        timer += Time.deltaTime;
        if (timer >= updateInterval)
        {
            timer = 0;
            UpdateDebugInfo();
        }
    }

    void UpdateDebugInfo()
    {
        // 获取本地玩家
        var localPlayer = NetworkClient.localPlayer;
        if (localPlayer == null)
        {
            debugInfo = "等待本地玩家连接...";
            debugText.text = debugInfo;
            return;
        }

        var controller = localPlayer.GetComponent<ThirdPersonController>();
        var playerChar = localPlayer.GetComponent<PlayerCharacter>();
        var input = localPlayer.GetComponent<StarterAssetsInputs>();
        var animator = localPlayer.GetComponent<Animator>();
        var netAnim = localPlayer.GetComponent<NetworkAnimator>();

        debugInfo = $"=== 本地玩家 [{localPlayer.netId}] ===\n\n";

        debugInfo += "【网络状态】\n";
        debugInfo += $"  是否本地玩家: {localPlayer.isLocalPlayer}\n";
        debugInfo += $"  是否客户端: {localPlayer.isClient} | 是否服务端: {localPlayer.isServer}\n";
        debugInfo += $"  是否有权限: {localPlayer.isOwned}\n\n";

        debugInfo += "【玩家状态】\n";
        debugInfo += $"  是否死亡: {(playerChar != null ? playerChar.isDead.ToString() : "N/A")}\n";
        debugInfo += $"  当前血量: {(playerChar != null ? $"{playerChar.CurrentHealth:F0}/{playerChar.MaxHealth:F0}" : "N/A")}\n";
        debugInfo += $"  当前位置: {localPlayer.transform.position}\n\n";

        debugInfo += "【输入状态】\n";
        if (input != null)
        {
            debugInfo += $"  移动输入: {input.move} (大小: {input.move.magnitude:F2})\n";
            debugInfo += $"  视角输入: {input.look}\n";
            debugInfo += $"  跳跃: {input.jump} | 冲刺: {input.sprint}\n\n";
        }
        else
        {
            debugInfo += "  ⚠️ 输入组件未找到!\n\n";
        }

        debugInfo += "【动画状态】\n";
        if (animator != null)
        {
            debugInfo += $"  Animator启用: {animator.enabled}\n";
            debugInfo += $"  有Controller: {animator.runtimeAnimatorController != null}\n";
            debugInfo += $"  Speed参数: {animator.GetFloat("Speed"):F3}\n";
            debugInfo += $"  Grounded参数: {animator.GetBool("Grounded")}\n";
            debugInfo += $"  IsHoldingGun参数: {animator.GetBool("IsHoldingGun")}\n\n";
        }

        debugInfo += "【网络动画器】\n";
        if (netAnim != null)
        {
            debugInfo += $"  NetworkAnimator存在: 是\n";
            debugInfo += $"  同步间隔: {netAnim.syncInterval}\n";
        }
        else
        {
            debugInfo += "  ⚠️ NetworkAnimator未找到!\n";
        }

        // 查找其他玩家数量
        var allPlayers = FindObjectsOfType<NetworkIdentity>();
        int otherPlayers = 0;
        foreach (var p in allPlayers)
        {
            if (p.isClient && !p.isLocalPlayer) otherPlayers++;
        }
        debugInfo += $"\n【场景玩家】其他玩家数量: {otherPlayers}";

        debugText.text = debugInfo;
    }
}
