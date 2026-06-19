using UnityEngine;

/// <summary>
/// 玩家昵称工具类。
/// 优先读取 PlayerNameManager 的 "PlayerCustomName"（UOS 角色名），
/// 回退到旧版 HelloInput 的 "UserGameData" JSON。
/// </summary>
public static class PlayerNameUtility
{
    private const string PlayerCustomNameKey = "PlayerCustomName";

    [System.Serializable]
    private struct UserNameData { public string userName; public int setInCount; }

    /// <summary>
    /// 从 PlayerPrefs 读取已保存的玩家昵称。
    /// 优先 PlayerNameManager 的 key（"PlayerCustomName"），回退旧 HelloInput JSON。
    /// 返回空字符串表示未设置。
    /// </summary>
    public static string GetSavedUserName()
    {
        // 优先：PlayerNameManager 的名字（UOS 角色名，纯字符串）
        string customName = PlayerPrefs.GetString(PlayerCustomNameKey, "");
        if (!string.IsNullOrWhiteSpace(customName))
            return customName;

        // 回退：旧 HelloInput 的 JSON（兼容老存档）
        if (!PlayerPrefs.HasKey("UserGameData")) return "";
        string json = PlayerPrefs.GetString("UserGameData");
        if (string.IsNullOrEmpty(json)) return "";
        try
        {
            var data = JsonUtility.FromJson<UserNameData>(json);
            return data.userName ?? "";
        }
        catch { return ""; }
    }
}
