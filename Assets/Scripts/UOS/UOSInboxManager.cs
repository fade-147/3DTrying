using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using Inbox;
using UnityEngine;
using Unity.Passport.Runtime;

/// <summary>
/// UOS 收件箱管理器 — 封装 Inbox API。
/// 单例，DontDestroyOnLoad。首次访问 Instance 时自动创建。
/// </summary>
public class UOSInboxManager : MonoBehaviour
{
    private static UOSInboxManager _instance;
    public static UOSInboxManager Instance
    {
        get
        {
            if (_instance == null)
            {
                var go = new GameObject("UOSInboxManager");
                _instance = go.AddComponent<UOSInboxManager>();
            }
            return _instance;
        }
    }

    /// <summary>跨 Manager 共享，避免重复初始化 PassportFeatureSDK</summary>
    internal static bool FeatureSDKInitialized;

    private void Awake()
    {
        if (_instance != null && _instance != this)
        {
            Destroy(gameObject);
            return;
        }
        _instance = this;
        DontDestroyOnLoad(gameObject);
    }

    /// <summary>
    /// 确保 PassportFeatureSDK 已初始化（幂等，全局只执行一次）。
    /// </summary>
    public async Task Initialize()
    {
        if (FeatureSDKInitialized) return;

        try
        {
            Debug.Log("[UOSInboxManager] 正在初始化 PassportFeatureSDK...");
            await PassportFeatureSDK.Initialize();
            FeatureSDKInitialized = true;
            Debug.Log("[UOSInboxManager] PassportFeatureSDK 初始化成功");
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSInboxManager] Feature SDK 初始化失败: {ex.Message}");
            throw;
        }
    }

    #region 收件箱

    /// <summary>
    /// 接收邮件 — 拉取服务器已发送的邮件到收件箱。
    /// 必须先调用此方法才能在新邮件出现在 ViewInbox 中。
    /// </summary>
    public async Task<bool> ReceiveMessages()
    {
        try
        {
            await Initialize();
            await PassportFeatureSDK.Inbox.ReceiveMessages();
            Debug.Log("[UOSInboxManager] 邮件接收完成");
            return true;
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSInboxManager] 接收邮件失败: {ex.Message}");
            return false;
        }
    }

    /// <summary>
    /// 查看收件箱（分页）。
    /// </summary>
    /// <param name="start">起始位置</param>
    /// <param name="count">获取数量，最大 50</param>
    /// <param name="onlyUncompleted">是否只显示未完成的邮件</param>
    /// <returns>(总数, 邮件列表)，失败返回 (0, 空列表)</returns>
    public async Task<(uint total, List<InboxMessage> messages)> GetInbox(
        uint start = 0, uint count = 20, bool onlyUncompleted = false)
    {
        try
        {
            await Initialize();
            var response = await PassportFeatureSDK.Inbox.ViewInbox(
                start, count,
                InboxOrderType.Time,
                onlyUncompleted);
            return (response.Total, new List<InboxMessage>(response.Messages));
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSInboxManager] 查看收件箱失败: {ex.Message}");
            return (0, new List<InboxMessage>());
        }
    }

    /// <summary>
    /// 阅读邮件 — 标记为已读。
    /// </summary>
    public async Task<bool> ReadMessage(string messageId)
    {
        try
        {
            await Initialize();
            await PassportFeatureSDK.Inbox.ReadMessage(messageId);
            Debug.Log($"[UOSInboxManager] 邮件已读: {messageId}");
            return true;
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSInboxManager] 阅读邮件失败: {ex.Message}");
            return false;
        }
    }

    /// <summary>
    /// 领取邮件附件 — 附件自动入账 Economy。
    /// </summary>
    /// <returns>领取后的邮件信息（含附件列表），失败返回 null</returns>
    public async Task<InboxConsumedMessage> ConsumeMessage(string messageId)
    {
        try
        {
            await Initialize();
            var response = await PassportFeatureSDK.Inbox.ConsumeMessage(messageId);
            Debug.Log($"[UOSInboxManager] 邮件已领取: {messageId}");
            return response.Message;
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSInboxManager] 领取邮件失败: {ex.Message}");
            return null;
        }
    }

    /// <summary>
    /// 删除邮件（必须是 Completed 状态）。
    /// </summary>
    public async Task<bool> DeleteMessage(string messageId)
    {
        try
        {
            await Initialize();
            await PassportFeatureSDK.Inbox.DeleteMessage(messageId);
            Debug.Log($"[UOSInboxManager] 邮件已删除: {messageId}");
            return true;
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSInboxManager] 删除邮件失败: {ex.Message}");
            return false;
        }
    }

    /// <summary>
    /// 一键领取所有邮件附件。
    /// </summary>
    public async Task<bool> ConsumeAllMessages()
    {
        try
        {
            await Initialize();
            var response = await PassportFeatureSDK.Inbox.ConsumeAllMessages();
            Debug.Log($"[UOSInboxManager] 已领取 {response.Messages.Count} 封邮件");
            return true;
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSInboxManager] 全部领取失败: {ex.Message}");
            return false;
        }
    }

    /// <summary>
    /// 删除所有已完成的邮件。
    /// </summary>
    /// <returns>删除数量</returns>
    public async Task<uint> DeleteAllCompletedMessages()
    {
        try
        {
            await Initialize();
            var response = await PassportFeatureSDK.Inbox.DeleteAllMessages();
            Debug.Log($"[UOSInboxManager] 已删除 {response.Count} 封已完成邮件");
            return response.Count;
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UOSInboxManager] 全部删除失败: {ex.Message}");
            return 0;
        }
    }

    #endregion
}
