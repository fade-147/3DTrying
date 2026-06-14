using UnityEngine;
using UnityEngine.UI;
using TMPro;
using UnityEngine.Events;

/// <summary>
/// Steam 初始化失败时显示的 UI（纯被动，由 SteamBootCheck 控制）。
/// 按钮在 Inspector 中绑定 HandleRetry/HandleQuit。
/// 勾选 debugForceShow 可在编辑器中强制显示，方便测试 UI。
/// </summary>
public class SteamErrorUI : MonoBehaviour
{
    public static SteamErrorUI Instance;

    [SerializeField] private GameObject errorPanel;
    [SerializeField] private TMP_Text statusText;
    [SerializeField] private Button retryButton;
    [SerializeField] private Button quitButton;

    [Header("事件 — SteamLobby 运行时 AddListener")]
    public UnityEvent OnRetryClicked;
    public UnityEvent OnQuitClicked;

    [Header("调试 — 勾选后启动时强制显示")]
    [SerializeField] private bool debugForceShow;

    private void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
            DontDestroyOnLoad(gameObject);
        }
        else
        {
            Destroy(gameObject);
            return;
        }

        // 初始隐藏 — 必须在 Awake 中做（非 Start），确保在 SteamLobby.Start() 之前执行
        if (errorPanel != null)
            errorPanel.SetActive(false);
    }

    private void Start()
    {
        if (debugForceShow)
            Show("您未打开steam/初始化失败，是否重试？（调试模式）");
    }

    public void Show(string message)
    {
        if (errorPanel != null)
            errorPanel.SetActive(true);
        if (statusText != null)
            statusText.text = message;
        if (retryButton != null)
            retryButton.interactable = true;
    }

    public void Hide()
    {
        if (errorPanel != null)
            errorPanel.SetActive(false);
    }

    public void SetStatus(string message)
    {
        if (statusText != null)
            statusText.text = message;
    }

    public void SetRetryInteractable(bool interactable)
    {
        if (retryButton != null)
            retryButton.interactable = interactable;
    }

    /// <summary>重试按钮（Inspector 绑定）</summary>
    public void HandleRetry()
    {
        SetStatus("正在重新连接 Steam...");
        SetRetryInteractable(false);
        OnRetryClicked?.Invoke();
    }

    /// <summary>退出按钮（Inspector 绑定）</summary>
    public void HandleQuit()
    {
        OnQuitClicked?.Invoke();
#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
#else
        Application.Quit();
#endif
    }
}
