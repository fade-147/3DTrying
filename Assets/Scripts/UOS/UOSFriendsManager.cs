using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using UnityEngine;
using Unity.Passport.Runtime;
using Unity.Passport.Runtime.Model;
using Passport;
using FriendRequestStatus = Unity.Passport.Runtime.Model.FriendRequestStatus;

/// <summary>
/// UOS 好友系统管理器 — 封装 Friends API + Presence。
/// 单例，DontDestroyOnLoad。挂载在 Steam Network Room Manager GO 上。
/// </summary>
public class UOSFriendsManager : MonoBehaviour
{
    public static UOSFriendsManager Instance { get; private set; }

    /// <summary>UOS Realm ID（与 UOSManager.DoExternalLogin 传入的一致）</summary>
    private const string RealmId = "8a9bd113-95d0-40f7-adad-d38c2685d227";

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
    }

    /// <summary>
    /// 确保 Feature SDK 已初始化（幂等）。
    /// </summary>
    public async Task Initialize()
    {
        if (_featureSdkInitialized) return;

        try
        {
            Debug.Log("[UOSFriendsManager] 正在初始化 PassportFeatureSDK...");
            await PassportFeatureSDK.Initialize();
            _featureSdkInitialized = true;
            Debug.Log("[UOSFriendsManager] PassportFeatureSDK 初始化成功");
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSFriendsManager] Feature SDK 初始化失败: {ex.Message}");
            throw;
        }
    }

    #region 好友搜索

    /// <summary>
    /// 按显示名搜索角色。
    /// </summary>
    public async Task<List<Persona>> SearchByDisplayName(string name)
    {
        if (string.IsNullOrWhiteSpace(name)) return new List<Persona>();

        try
        {
            await Initialize();
            var response = await PassportFeatureSDK.Friends.SearchFriends(
                personaName: name,
                realmID: RealmId,
                count: 20
            );
            return new List<Persona>(response.Personas);
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSFriendsManager] 搜索好友失败: {ex.Message}");
            return new List<Persona>();
        }
    }

    /// <summary>
    /// 随机推荐可添加的角色。
    /// </summary>
    public async Task<List<Persona>> FindRandom(int count = 10)
    {
        try
        {
            await Initialize();
            var response = await PassportFeatureSDK.Friends.FindFriendsRandomly(
                RealmId, (uint)count);
            return new List<Persona>(response.Personas);
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSFriendsManager] 随机搜索失败: {ex.Message}");
            return new List<Persona>();
        }
    }

    #endregion

    #region 好友请求

    /// <summary>
    /// 发送好友请求。
    /// </summary>
    public async Task<bool> SendFriendRequest(string targetPersonaID)
    {
        try
        {
            await Initialize();
            var request = await PassportFeatureSDK.Friends.SendFriendRequest(targetPersonaID);
            Debug.Log($"[UOSFriendsManager] 好友请求已发送 → {targetPersonaID}, requestId={request.Id}");
            return true;
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSFriendsManager] 好友请求发送失败: {ex.Message}");
            return false;
        }
    }

    /// <summary>
    /// 通过好友请求。
    /// </summary>
    public async Task<bool> ApproveFriendRequest(string requestID)
    {
        try
        {
            await Initialize();
            await PassportFeatureSDK.Friends.ApproveFriendRequest(requestID);
            Debug.Log($"[UOSFriendsManager] 已通过好友请求: {requestID}");
            return true;
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSFriendsManager] 通过好友请求失败: {ex.Message}");
            return false;
        }
    }

    /// <summary>
    /// 拒绝好友请求。
    /// </summary>
    public async Task<bool> RejectFriendRequest(string requestID)
    {
        try
        {
            await Initialize();
            await PassportFeatureSDK.Friends.RejectFriendRequest(requestID);
            Debug.Log($"[UOSFriendsManager] 已拒绝好友请求: {requestID}");
            return true;
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSFriendsManager] 拒绝好友请求失败: {ex.Message}");
            return false;
        }
    }

    /// <summary>
    /// 获取收到的待处理好友请求列表。
    /// </summary>
    public async Task<List<FriendRequest>> GetReceivedRequests()
    {
        try
        {
            await Initialize();
            var response = await PassportFeatureSDK.Friends.GetFriendRequestReceivedList(
                start: 0, count: 50, requestStatus: FriendRequestStatus.Pending);
            return new List<FriendRequest>(response.Requests);
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSFriendsManager] 获取好友请求失败: {ex.Message}");
            return new List<FriendRequest>();
        }
    }

    #endregion

    #region 好友列表

    /// <summary>
    /// 获取全部好友列表（自动分页取全）。
    /// </summary>
    public async Task<List<FriendInfo>> GetFriendList()
    {
        try
        {
            await Initialize();
            const int pageSize = 50;
            var allFriends = new List<FriendInfo>();
            int start = 0;

            while (true)
            {
                var response = await PassportFeatureSDK.Friends.GetFriendList(start, pageSize);
                if (response.Friends == null || response.Friends.Count == 0)
                    break;

                allFriends.AddRange(response.Friends);

                if (response.Friends.Count < pageSize || start + pageSize >= response.Total)
                    break;

                start += pageSize;
            }

            Debug.Log($"[UOSFriendsManager] 获取到 {allFriends.Count} 个好友");
            return allFriends;
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSFriendsManager] 获取好友列表失败: {ex.Message}");
            return new List<FriendInfo>();
        }
    }

    /// <summary>
    /// 删除好友。
    /// </summary>
    public async Task<bool> RemoveFriend(string friendshipID)
    {
        try
        {
            await Initialize();
            await PassportFeatureSDK.Friends.RemoveFriend(friendshipID, removeBoth: true);
            Debug.Log($"[UOSFriendsManager] 已删除好友: {friendshipID}");
            return true;
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSFriendsManager] 删除好友失败: {ex.Message}");
            return false;
        }
    }

    #endregion

    #region Presence

    /// <summary>
    /// 设置自身 Presence 状态。
    /// </summary>
    public async Task SetPresence(string status, Dictionary<string, string> props)
    {
        try
        {
            await Initialize();
            var presence = new PassportFriendPresence
            {
                status = status,
                Properties = props ?? new Dictionary<string, string>()
            };
            await PassportFeatureSDK.Friends.SetPresence(presence);
            Debug.Log($"[UOSFriendsManager] Presence 已设置: status={status}");
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSFriendsManager] 设置 Presence 失败: {ex.Message}");
        }
    }

    /// <summary>
    /// 获取单个好友的 Presence。
    /// </summary>
    public async Task<PassportFriendPresence> GetFriendPresence(string friendshipID)
    {
        try
        {
            await Initialize();
            return await PassportFeatureSDK.Friends.GetFriendPresence(friendshipID);
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSFriendsManager] 获取好友 Presence 失败: {ex.Message}");
            return null;
        }
    }

    /// <summary>
    /// 批量获取好友 Presence。
    /// </summary>
    public async Task<Dictionary<string, PassportFriendPresence>> GetFriendPresenceBatch(
        List<string> friendshipIDs)
    {
        try
        {
            await Initialize();
            if (friendshipIDs == null || friendshipIDs.Count == 0)
                return new Dictionary<string, PassportFriendPresence>();

            return await PassportFeatureSDK.Friends.GetFriendPresenceList(friendshipIDs);
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSFriendsManager] 批量获取 Presence 失败: {ex.Message}");
            return new Dictionary<string, PassportFriendPresence>();
        }
    }

    /// <summary>
    /// 发布大厅 Presence — 让好友知道你在大厅里。
    /// </summary>
    public async Task PublishLobbyPresence(ulong lobbyId, string hostAddress)
    {
        await SetPresence(UOSFriendsConst.PresenceInLobby, new Dictionary<string, string>
        {
            [UOSFriendsConst.PropLobbyId] = lobbyId.ToString(),
            [UOSFriendsConst.PropHostAddress] = hostAddress
        });
    }

    /// <summary>
    /// 清除大厅 Presence — 离开大厅时调用。
    /// </summary>
    public async Task ClearLobbyPresence()
    {
        await SetPresence(UOSFriendsConst.PresenceOnline, new Dictionary<string, string>());
    }

    #endregion
}
