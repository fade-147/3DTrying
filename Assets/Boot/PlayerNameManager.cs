using System;
using UnityEngine;

/// <summary>
/// 玩家游戏内名字管理。
/// 首次登录无名字时触发 OnNameRequired；有名字后触发 OnNameReady。
/// UI 调用 SetName() 保存，调用 ChangeName() 修改。
/// 单例，DontDestroyOnLoad。
/// </summary>
public class PlayerNameManager : MonoBehaviour
{
    public static PlayerNameManager Instance { get; private set; }

    private const string PLAYER_NAME_KEY = "PlayerCustomName";

    /// <summary>玩家当前游戏名字（未设置时为空字符串）</summary>
    public string PlayerName { get; private set; } = "";

    /// <summary>是否已经设置过自定义名字</summary>
    public bool HasName => !string.IsNullOrWhiteSpace(PlayerName);

    /// <summary>名字就绪（加载已有名字 或 用户刚刚设置了名字）</summary>
    public event Action<string> OnNameReady;

    /// <summary>需要用户输入名字（首次登录，无已保存名字）</summary>
    public event Action OnNameRequired;

    /// <summary>名字变更后触发</summary>
    public event Action<string> OnNameChanged;

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

    private void Start()
    {
        // 尝试从 PlayerPrefs 加载已有名字
        string saved = PlayerPrefs.GetString(PLAYER_NAME_KEY, "");
        if (!string.IsNullOrWhiteSpace(saved))
        {
            PlayerName = saved;
            Debug.Log($"[PlayerNameManager] 已加载名字: {PlayerName}");
            OnNameReady?.Invoke(PlayerName);
        }
        else
        {
            Debug.Log("[PlayerNameManager] 首次登录，等待用户输入名字");
            OnNameRequired?.Invoke();
        }
    }

    /// <summary>
    /// 设置初始名字（首次登录 UI 确认后调用）。
    /// </summary>
    public void SetName(string name)
    {
        if (string.IsNullOrWhiteSpace(name))
        {
            Debug.LogWarning("[PlayerNameManager] 名字不能为空");
            return;
        }

        name = name.Trim();
        PlayerName = name;
        PlayerPrefs.SetString(PLAYER_NAME_KEY, name);
        PlayerPrefs.Save();
        Debug.Log($"[PlayerNameManager] 名字已设置: {name}");
        OnNameReady?.Invoke(name);
        OnNameChanged?.Invoke(name);

        // 同步到 UOS（如果还未就绪则等待）
        SyncToUOS(name);
    }

    /// <summary>
    /// 修改已有名字（更改名字 UI 确认后调用）。
    /// </summary>
    public void ChangeName(string newName)
    {
        if (string.IsNullOrWhiteSpace(newName))
        {
            Debug.LogWarning("[PlayerNameManager] 新名字不能为空");
            return;
        }

        newName = newName.Trim();
        string oldName = PlayerName;
        PlayerName = newName;
        PlayerPrefs.SetString(PLAYER_NAME_KEY, newName);
        PlayerPrefs.Save();
        Debug.Log($"[PlayerNameManager] 名字已更改: {oldName} → {newName}");
        OnNameChanged?.Invoke(newName);

        // 同步更新 UOS Persona 的 displayName
        SyncToUOS(newName);
    }

    /// <summary>同步名字到 UOS。如果 UOS 还没就绪，等待最多 30 秒。</summary>
    private async void SyncToUOS(string name)
    {
        try
        {
            // 等待 UOS 就绪
            float waited = 0f;
            while ((UOSManager.Instance == null || !UOSManager.Instance.IsReady) && waited < 30f)
            {
                await System.Threading.Tasks.Task.Delay(500);
                waited += 0.5f;
            }

            if (UOSManager.Instance == null || !UOSManager.Instance.IsReady)
            {
                Debug.LogWarning("[PlayerNameManager] UOS 未就绪，名字不同步（下次登录时同步）");
                return;
            }

            await Unity.Passport.Runtime.PassportSDK.Identity.UpdatePersona(
                displayName: name
            );
            Debug.Log($"[PlayerNameManager] UOS Persona displayName 已同步: {name}");
        }
        catch (Exception ex)
        {
            Debug.LogWarning($"[PlayerNameManager] UOS 名字同步失败（不影响游戏）: {ex.Message}");
        }
    }
}
