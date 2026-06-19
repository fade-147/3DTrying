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

    /// <summary>
    /// 已注册的 Bot 列表，用于枪声广播等全局通知。
    /// </summary>
    public readonly List<BotController> RegisteredBots = new();

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

    /// <summary>
    /// 查询某 zone 附近（radius 内）有多少队友 Bot 正在前往或已到达。
    /// 用于密度惩罚，避免多个 Bot 挤同一区。
    /// </summary>
    public int GetTeammateDensityNear(StrategyZone zone, int teamId, uint excludeNetId, float radius = 30f)
    {
        int count = 0;
        foreach (var kv in _botClaims)
        {
            if (kv.Key == excludeNetId) continue;
            if (kv.Value == null) continue;
            if (Vector3.Distance(zone.WorldPosition, kv.Value.WorldPosition) < radius)
                count++;
        }
        return count;
    }

    /// <summary>
    /// 注册 Bot 到全局列表，供枪声广播等通知使用。
    /// 由 BotController.OnStartServer 调用。
    /// </summary>
    public void RegisterBot(BotController bc)
    {
        if (bc != null && !RegisteredBots.Contains(bc))
            RegisteredBots.Add(bc);
    }

    /// <summary>
    /// 从全局列表注销 Bot。
    /// 由 BotController.OnDestroy 调用。
    /// </summary>
    public void UnregisterBot(BotController bc)
    {
        RegisteredBots.Remove(bc);
    }

    /// <summary>
    /// 向所有 Bot（除发射者外）广播枪声位置，触发听觉感知。
    /// 由 BotController.ServerFire 调用。
    /// </summary>
    public void BroadcastGunfire(Vector3 pos, uint sourceNetId)
    {
        foreach (var bc in RegisteredBots)
        {
            if (bc != null && bc.netId != sourceNetId)
                bc.OnHearGunfire(pos);
        }
    }
}
