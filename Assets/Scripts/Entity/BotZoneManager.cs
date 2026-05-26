using System.Collections.Generic;
using UnityEngine;
using Mirror;

/// <summary>
/// 服务端单例，追踪每个 Bot 前往的区和区的冷却时间。
/// 防止多个 Bot 挤同一区。
/// </summary>
public class BotZoneManager : NetworkBehaviour
{
    public static BotZoneManager Instance { get; private set; }

    public float zoneCooldownDuration = 30f;

    private readonly Dictionary<uint, StrategyZone> _botClaims = new();
    private readonly Dictionary<StrategyZone, float> _zoneCooldowns = new();

    private void Awake()
    {
        if (Instance != null)
        {
            Destroy(gameObject);
            return;
        }
        Instance = this;
    }

    public override void OnStartServer()
    {
        base.OnStartServer();
        if (Instance != this)
        {
            Destroy(gameObject);
            return;
        }
        Instance = this;
    }

    /// <summary>
    /// 尝试认领一个区。已被其他 Bot 认领或冷却中则返回 false。
    /// </summary>
    public bool TryClaimZone(StrategyZone zone, uint botNetId)
    {
        if (zone == null) return false;

        if (_zoneCooldowns.TryGetValue(zone, out float cd) && cd > Time.time)
            return false;

        foreach (var kv in _botClaims)
        {
            if (kv.Value == zone && kv.Key != botNetId)
                return false;
        }

        _botClaims[botNetId] = zone;
        return true;
    }

    /// <summary>
    /// Bot 到达/切换目标时释放认领。
    /// </summary>
    public void ReleaseZone(uint botNetId)
    {
        _botClaims.Remove(botNetId);
    }

    /// <summary>
    /// Bot 到达后标记该区进入冷却，防止所有 Bot 排队同一区。
    /// </summary>
    public void MarkZoneVisited(StrategyZone zone)
    {
        if (zone == null) return;
        _zoneCooldowns[zone] = Time.time + zoneCooldownDuration;
    }

    /// <summary>
    /// 查询某区是否已被其他 Bot 认领。
    /// </summary>
    public bool IsZoneClaimedByOther(StrategyZone zone, uint botNetId)
    {
        foreach (var kv in _botClaims)
        {
            if (kv.Value == zone && kv.Key != botNetId)
                return true;
        }
        return false;
    }
}
