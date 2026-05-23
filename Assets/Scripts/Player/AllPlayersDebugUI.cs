using Mirror;
using StarterAssets;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class AllPlayersDebugUI : MonoBehaviour
{
    public Text debugText;
    public float updateInterval = 0.3f;

    private float timer;

    void Start()
    {
        if (debugText == null)
        {
            var debugObj = GameObject.FindWithTag("DebugText");
            if (debugObj != null) debugText = debugObj.GetComponent<Text>();
        }
    }

    void Update()
    {
        if (debugText == null) return;

        timer += Time.deltaTime;
        if (timer < updateInterval) return;
        timer = 0;

        string info = "";

        // 查找所有玩家
        var allPlayers = FindObjectsOfType<NetworkIdentity>();

        foreach (var netId in allPlayers)
        {
            if (!netId.isClient) continue; // 只显示客户端控制的物体

            bool isLocal = netId.isLocalPlayer;
            var controller = netId.GetComponent<ThirdPersonController>();
            var animator = netId.GetComponent<Animator>();

            info += $"=== 玩家 {netId.netId} {(isLocal ? "[本地]" : "[其他]")} ===\n";
            info += $"位置: {netId.transform.position}\n";

            if (controller != null)
            {
                info += $"队伍ID: {controller.teamId} | 持枪: {controller.isHoldingGun} | 速度: {controller.MoveSpeed}\n";
            }

            if (animator != null)
            {
                info += $"动画Speed: {animator.GetFloat("Speed"):F2} | ";
                info += $"Grounded: {animator.GetBool("Grounded")} | ";
                info += $"Gun: {animator.GetBool("IsHoldingGun")}\n";
                info += $"Animator启用: {animator.enabled}\n";
            }
            else
            {
                info += "⚠️ 无Animator组件\n";
            }

            info += "\n";
        }

        if (string.IsNullOrEmpty(info))
            info = "未找到任何玩家对象";

        debugText.text = info;
    }
}
