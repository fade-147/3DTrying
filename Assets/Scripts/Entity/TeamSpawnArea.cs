using UnityEngine;

/// <summary>
/// 标记组件：挂载在生成区域父物体上，用于识别队伍出生点分组。
/// 每个 TeamSpawnArea 下放置若干 NetworkStartPosition 子物体。
/// </summary>
public class TeamSpawnArea : MonoBehaviour
{
    /// <summary>
    /// 地图侧标识：0 或 1，用于区分同一地图中的两侧出生区。
    /// </summary>
    public int sideId = 0;
}
