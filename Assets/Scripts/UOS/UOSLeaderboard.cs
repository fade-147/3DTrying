using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using UnityEngine;
using Unity.Passport.Runtime;
using Leaderboard;

/// <summary>
/// UOS 排行榜封装。单例，挂载在 Steam Network Room Manager 上。
/// 每个客户端用自己的 JWT 提交/查询排行榜。
/// </summary>
public class UOSLeaderboard : MonoBehaviour
{
    public static UOSLeaderboard Instance { get; private set; }

    [Header("排行榜配置")]
    [Tooltip("UOS 控制台创建的排行榜 slugName")]
    [SerializeField] private string killLeaderboardSlugName = "total-kills";

    private static bool _featureSdkInitialized;

    private void Awake()
    {
        if (Instance != null)
        {
            Destroy(gameObject);
            return;
        }
        Instance = this;
        DontDestroyOnLoad(gameObject);
        Debug.Log($"[UOSLeaderboard] 单例已初始化, slugName={killLeaderboardSlugName}");
    }

    /// <summary>
    /// 确保 Feature SDK 已初始化（首次调用时异步初始化一次）。
    /// </summary>
    private static async Task EnsureFeatureSdkReady()
    {
        if (_featureSdkInitialized) return;

        try
        {
            Debug.Log("[UOSLeaderboard] 正在初始化 PassportFeatureSDK...");
            await PassportFeatureSDK.Initialize();
            _featureSdkInitialized = true;
            Debug.Log("[UOSLeaderboard] PassportFeatureSDK 初始化成功");
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSLeaderboard] Feature SDK 初始化失败: {ex.GetType().Name} - {ex.Message}");
            throw;
        }
    }

    /// <summary>
    /// 提交击杀分数：读取 UOS 当前累计值，加上本局增量，提交新值。
    /// fire-and-forget，失败静默。
    /// </summary>
    public async void SubmitKillScore(int killsToAdd)
    {
        if (killsToAdd <= 0) return;

        Debug.Log($"[UOSLeaderboard] SubmitKillScore 开始, killsToAdd={killsToAdd}");

        try
        {
            await EnsureFeatureSdkReady();

            // 1. 读取当前 UOS 累计分数
            double oldScore = 0;
            try
            {
                Debug.Log($"[UOSLeaderboard] 正在获取旧分数...");
                var oldResponse = await PassportFeatureSDK.Leaderboard.GetScore(killLeaderboardSlugName, range: 0);
                if (oldResponse?.Scores != null && oldResponse.Scores.Count > 0)
                {
                    oldScore = oldResponse.Scores[0].Score;
                    Debug.Log($"[UOSLeaderboard] 旧分数: {oldScore}");
                }
                else
                {
                    Debug.Log("[UOSLeaderboard] 无旧分数（首次提交）");
                }
            }
            catch (Exception ex)
            {
                Debug.Log($"[UOSLeaderboard] 获取旧分数失败（首次提交正常）: {ex.Message}");
            }

            // 2. 累加后提交
            double newScore = oldScore + killsToAdd;
            Debug.Log($"[UOSLeaderboard] 正在提交新分数: {newScore}");

            var response = await PassportFeatureSDK.Leaderboard.UpdateScore(killLeaderboardSlugName, newScore);

            Debug.Log($"[UOSLeaderboard] 击杀分数已提交! old={oldScore} + add={killsToAdd} = {newScore}, 排名: {response.Rank}, 成员ID: {response.MemberId}");
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSLeaderboard] 提交击杀分数失败: {ex.GetType().Name} - {ex.Message}\n{ex.StackTrace}");
        }
    }

    /// <summary>
    /// 获取排行榜前 N 名（最多 50）。
    /// </summary>
    public async Task<List<RankingEntry>> GetTopRankings(int count = 50)
    {
        var result = new List<RankingEntry>();

        try
        {
            await EnsureFeatureSdkReady();

            uint fetchCount = (uint)Mathf.Clamp(count, 1, 50);
            Debug.Log($"[UOSLeaderboard] 正在获取排行榜前 {fetchCount} 名...");

            var response = await PassportFeatureSDK.Leaderboard.ListLeaderboardScores(
                killLeaderboardSlugName, count: fetchCount);

            if (response?.Scores != null)
            {
                Debug.Log($"[UOSLeaderboard] 获取到 {response.Scores.Count} 条记录 (共 {response.Total} 条)");
                foreach (var score in response.Scores)
                {
                    result.Add(new RankingEntry
                    {
                        Rank = (int)score.Rank,
                        DisplayName = score.DisplayName ?? "???",
                        Score = (int)score.Score
                    });
                }
            }
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSLeaderboard] 获取排行榜失败: {ex.GetType().Name} - {ex.Message}");
        }

        return result;
    }

    /// <summary>
    /// 获取当前玩家自己的排名和分数。失败返回 Rank=-1。
    /// </summary>
    public async Task<RankingEntry> GetMyRank()
    {
        try
        {
            await EnsureFeatureSdkReady();

            var response = await PassportFeatureSDK.Leaderboard.GetScore(killLeaderboardSlugName, range: 0);
            if (response?.Scores != null && response.Scores.Count > 0)
            {
                var s = response.Scores[0];
                return new RankingEntry
                {
                    Rank = (int)s.Rank,
                    DisplayName = s.DisplayName ?? "???",
                    Score = (int)s.Score
                };
            }
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSLeaderboard] 获取个人排名失败: {ex.GetType().Name} - {ex.Message}");
        }

        return new RankingEntry { Rank = -1, DisplayName = "无记录", Score = 0 };
    }
}

/// <summary>
/// 排行榜条目，供 UI 层使用。
/// </summary>
[Serializable]
public class RankingEntry
{
    public int Rank;
    public string DisplayName;
    public int Score;
}
