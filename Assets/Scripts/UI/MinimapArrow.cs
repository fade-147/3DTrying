using Mirror;
using StarterAssets;
using UnityEngine;

/// <summary>
/// Controls minimap arrow visibility for players and bots.
/// Arrow is hidden by default. Delays 0.5s after spawn then shows only
/// for entities on the same team as the local player.
///
/// Add to: Player_FPS_TP.prefab and PlayerArmature 1.prefab root.
/// Assign: arrowObject field → child arrow GameObject you create on the prefab.
/// </summary>
public class MinimapArrow : NetworkBehaviour
{
    [Header("Minimap")]
    [SerializeField]
    [Tooltip("The arrow/indicator GameObject shown on the minimap. Assign in prefab.")]
    private GameObject arrowObject;

    private void Start()
    {
        if (arrowObject != null)
            arrowObject.SetActive(false);
    }

    public override void OnStartClient()
    {
        base.OnStartClient();
        Debug.Log($"[MinimapArrow] OnStartClient on '{name}', scheduling UpdateArrow in 0.5s");
        Invoke(nameof(UpdateArrow), 0.5f);
    }

    private void UpdateArrow()
    {
        Debug.Log($"[MinimapArrow] UpdateArrow on '{name}' — checking conditions...");

        if (arrowObject == null)
        {
            Debug.LogWarning($"[MinimapArrow] '{name}' — arrowObject is null (未在 Inspector 赋值)");
            return;
        }

        if (NetworkClient.localPlayer == null)
        {
            Debug.LogWarning($"[MinimapArrow] '{name}' — NetworkClient.localPlayer is null (本地玩家尚未生成)");
            return;
        }

        Debug.Log($"[MinimapArrow] '{name}' — localPlayer = '{NetworkClient.localPlayer.name}'");

        var localPNB = NetworkClient.localPlayer.GetComponent<PlayerNetworkBridge>();
        if (localPNB == null)
        {
            Debug.LogWarning($"[MinimapArrow] '{name}' — localPlayer 上没有 PlayerNetworkBridge 组件");
            return;
        }

        int localTeam = localPNB.teamId;
        Debug.Log($"[MinimapArrow] '{name}' — localTeam = {localTeam}");

        var pnb = GetComponent<PlayerNetworkBridge>();
        if (pnb != null)
        {
            Debug.Log($"[MinimapArrow] '{name}' — found PNB, myTeam = {pnb.teamId}, sameTeam = {pnb.teamId == localTeam}");
            arrowObject.SetActive(pnb.teamId == localTeam);
            return;
        }

        var bc = GetComponent<BotController>();
        if (bc != null)
        {
            Debug.Log($"[MinimapArrow] '{name}' — found BotController, myTeam = {bc.teamId}, sameTeam = {bc.teamId == localTeam}");
            arrowObject.SetActive(bc.teamId == localTeam);
            return;
        }

        Debug.LogWarning($"[MinimapArrow] '{name}' — 自身没有 PlayerNetworkBridge 也没有 BotController");
        return;
    }
}
