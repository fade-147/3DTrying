using Steamworks;
using UnityEngine;

/// <summary>
/// Boot 场景的 Steam 探测器 + 重试控制器。
/// 放在 SteamErrorUI 所在的 Canvas 上。
/// 直接调用 SteamAPI.Init()（不经过 SteamManager），成功即 Shutdown，
/// 让 StartScene 的 SteamManager + FizzySteamworks 干净初始化。
/// 重试：Shutdown 上次失败残留 → Init → BLoggedOn → Shutdown → 加载 StartScene。
/// </summary>
public class SteamBootCheck : MonoBehaviour
{
    public static SteamBootCheck Instance;

    [Header("调试 — 勾选跳过 Steam 检查")]
    [SerializeField] private bool debugSkipCheck;

    private System.Action _onSuccess;
    private bool _steamInitCalled;

    private void Awake()
    {
        if (Instance == null) Instance = this;
        else Destroy(this);
    }

    /// <summary>MyYooAsset.StartButtonClicked 调用。成功后回调加载 StartScene。</summary>
    public void InitSteamAndProceed(System.Action onSuccess)
    {
        _onSuccess = onSuccess;
        _steamInitCalled = false;

        if (debugSkipCheck)
        {
            Debug.Log("[SteamBootCheck] debugSkipCheck 开启，跳过检查");
            onSuccess?.Invoke();
            return;
        }

        if (TryInitSteam())
        {
            // 探测成功，立即 Shutdown，放 StartScene 干净初始化
            SteamAPI.Shutdown();
            onSuccess?.Invoke();
        }
        else
        {
            ShowUI();
        }
    }

    private bool TryInitSteam()
    {
        try
        {
            if (!SteamAPI.Init()) return false;
            _steamInitCalled = true;
            return SteamUser.BLoggedOn();
        }
        catch (System.Exception ex)
        {
            Debug.LogWarning($"[SteamBootCheck] Steam 探测异常: {ex.Message}");
            return false;
        }
    }

    private void ShowUI()
    {
        var ui = SteamErrorUI.Instance;
        if (ui == null) return;

        ui.OnRetryClicked.RemoveAllListeners();
        ui.OnRetryClicked.AddListener(HandleRetry);
        ui.Show("您未打开steam/初始化失败，是否重试？");
    }

    private void HandleRetry()
    {
        // 清理上次失败/成功的残留状态
        if (_steamInitCalled)
        {
            try { SteamAPI.Shutdown(); } catch { }
            _steamInitCalled = false;
        }

        if (TryInitSteam())
        {
            SteamAPI.Shutdown();
            SteamErrorUI.Instance?.Hide();
            _onSuccess?.Invoke();
        }
        else
        {
            var ui = SteamErrorUI.Instance;
            if (ui != null)
            {
                ui.SetStatus("Steam 连接失败，请检查 Steam 客户端是否运行");
                ui.SetRetryInteractable(true);
            }
        }
    }
}
