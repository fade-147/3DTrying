using System;
using System.Threading.Tasks;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 金币数量显示。挂在 StartScene 的 UI GameObject 上。
/// 启动后自动轮询 Economy 余额。
/// </summary>
public class GoldDisplayUI : MonoBehaviour
{
    [Header("UI 元素")]
    [SerializeField] private TMP_Text goldText;
    [SerializeField] private Button refreshButton;

    [Header("格式")]
    [SerializeField] private string displayFormat = "金币: {0:N0}";

    /// <summary>是否已成功初始查询</summary>
    private bool _initialQueryDone;

    private async void Start()
    {
        if (refreshButton != null)
            refreshButton.onClick.AddListener(() => _ = RefreshGold());

        // 订阅余额变化事件
        if (UOSEconomyManager.Instance != null)
            UOSEconomyManager.Instance.OnGoldBalanceChanged += OnGoldBalanceChanged;

        // 轮询等待 UOS 登录就绪后首次查询
        await InitialQuery();
    }

    private void OnDestroy()
    {
        if (UOSEconomyManager.Instance != null)
            UOSEconomyManager.Instance.OnGoldBalanceChanged -= OnGoldBalanceChanged;

        if (refreshButton != null)
            refreshButton.onClick.RemoveAllListeners();
    }

    /// <summary>
    /// 公开的刷新方法，供外部（如邮件领取后）调用。
    /// </summary>
    public async Task RefreshGold()
    {
        if (UOSEconomyManager.Instance == null) return;

        uint balance = await UOSEconomyManager.Instance.GetGoldBalance();
        UpdateDisplay(balance);
    }

    private void OnGoldBalanceChanged(uint balance)
    {
        _initialQueryDone = true;
        UpdateDisplay(balance);
    }

    private void UpdateDisplay(uint balance)
    {
        if (goldText != null)
            goldText.text = string.Format(displayFormat, balance);
    }

    /// <summary>
    /// 轮询等待 UOS 登录完成后首次查询金币余额。
    /// 通过尝试初始化 Economy SDK 判断登录是否就绪（最长 60 秒）。
    /// </summary>
    private async Task InitialQuery()
    {
        if (UOSEconomyManager.Instance == null)
        {
            Debug.LogWarning("[GoldDisplayUI] UOSEconomyManager.Instance 为空");
            return;
        }

        float waited = 0f;
        while (!_initialQueryDone && waited < 60f)
        {
            try
            {
                // Initialize 在未登录时会抛异常——用这个判断登录是否就绪
                await UOSEconomyManager.Instance.Initialize();
                // 初始化成功 → 查询余额
                uint balance = await UOSEconomyManager.Instance.GetGoldBalance();
                UpdateDisplay(balance);
                _initialQueryDone = true;
                Debug.Log($"[GoldDisplayUI] 初始查询完成，金币: {balance}");
                break;
            }
            catch (Exception)
            {
                // 登录未就绪，等待后重试
                await Task.Delay(2000);
                waited += 2f;
            }
        }

        if (!_initialQueryDone)
            Debug.LogWarning("[GoldDisplayUI] 初始查询超时，UOS 登录可能未完成");
    }
}
