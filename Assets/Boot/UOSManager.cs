using System;
using System.Threading.Tasks;
using UnityEngine;

#if !(UNITY_STANDALONE_WIN || UNITY_STANDALONE_LINUX || UNITY_STANDALONE_OSX || STEAMWORKS_WIN || STEAMWORKS_LIN_OSX)
#define DISABLESTEAMWORKS
#endif

#if !DISABLESTEAMWORKS
using Steamworks;
#endif

/// <summary>
/// UOS Passport 管理器 — 通过 ExternalLogin 用 Steam ID 登录 UOS。
/// 单例，DontDestroyOnLoad。在 Boot 流程中由 MyYooAsset 创建。
/// Token 过期后外部服务抛异常时，重新调用 InitializeWithSteam() 即可续期。
/// </summary>
public class UOSManager : MonoBehaviour
{
    public static UOSManager Instance { get; private set; }

    /// <summary>UOS 登录是否完成</summary>
    public bool IsReady { get; private set; }

    /// <summary>AuthTokenManager.ExternalLogin 返回的完整 Token 信息</summary>
    public Unity.UOS.Auth.TokenInfo TokenInfo { get; private set; }

    /// <summary>UOS 侧的用户 ID（与传入的 SteamID 不同，由 UOS 生成）</summary>
    public string UserId { get; private set; }

    [Header("调试")]
    [SerializeField] private bool _debugBypassSteam;

    private void Awake()
    {
        if (Instance != null)
        {
            Destroy(gameObject);
            return;
        }
        Instance = this;
        DontDestroyOnLoad(gameObject);
    }

    /// <summary>
    /// 使用当前 Steam 用户信息初始化 UOS Passport（fire-and-forget）。
    /// Steam 必须已初始化（SteamAPI.Init 已调用）且用户已登录。
    /// </summary>
    public async void InitializeWithSteam()
    {
        string userId;
        string personaName;

#if !DISABLESTEAMWORKS
        if (!_debugBypassSteam)
        {
            // 等待 Steam 用户登录就绪（最长 30 秒）
            float waited = 0f;
            while (!SteamUser.BLoggedOn() && waited < 30f)
            {
                await Task.Delay(500);
                waited += 0.5f;
            }

            if (!SteamUser.BLoggedOn())
            {
                Debug.LogError("[UOSManager] Steam 用户未在 30s 内登录，UOS 登录跳过");
                return;
            }

            userId = SteamUser.GetSteamID().ToString();
            personaName = SteamFriends.GetPersonaName();
            Debug.Log($"[UOSManager] Steam 已就绪 — SteamID: {userId}");
        }
        else
#endif
        {
            // 调试模式：用设备 ID 模拟
            userId = "debug_" + SystemInfo.deviceUniqueIdentifier;
            personaName = "DebugUser";
            Debug.LogWarning("[UOSManager] debugBypassSteam 开启，使用设备 ID 代替 SteamID");
        }

        await DoExternalLogin(userId, null, GetDisplayName(personaName), "8a9bd113-95d0-40f7-adad-d38c2685d227");
    }

    /// <summary>
    /// 名字优先级：游戏内自定义名 > Steam 昵称
    /// </summary>
    private static string GetDisplayName(string steamFallback)
    {
        if (PlayerNameManager.Instance != null && PlayerNameManager.Instance.HasName)
            return PlayerNameManager.Instance.PlayerName;
        return steamFallback;
    }

    /// <summary>
    /// 执行 ExternalLogin。token 过期后可重新调用。
    /// </summary>
    public async Task DoExternalLogin(string externalUserId, string personaId,
        string displayName, string realmId)
    {
        try
        {
            // 1. 初始化 Passport SDK（从 UOSSettings.asset 读取 AppID/AppSecret）
            var userInfo = await Unity.Passport.Runtime.PassportLoginSDK.Init(true);
            Debug.Log($"[UOSManager] PassportLoginSDK.Init 完成");

            // 2. ExternalLogin — 将 SteamID 关联到 UOS 账号
            TokenInfo = await Unity.UOS.Auth.AuthTokenManager.ExternalLogin(
                userID: externalUserId,
                personaID: personaId,
                displayName: displayName,
                realmID: realmId
            );

            UserId = TokenInfo.UserId;
            IsReady = true;
            Debug.Log($"[UOSManager] ExternalLogin 成功 — UOS UserId: {UserId}, " +
                      $"IsNew: {TokenInfo.IsNew}");
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSManager] UOS 初始化失败: {ex}");
            IsReady = false;
        }
    }
}
