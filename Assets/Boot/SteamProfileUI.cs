using UnityEngine;
using UnityEngine.UI;
using TMPro;

#if !(UNITY_STANDALONE_WIN || UNITY_STANDALONE_LINUX || UNITY_STANDALONE_OSX || STEAMWORKS_WIN || STEAMWORKS_LIN_OSX)
#define DISABLESTEAMWORKS
#endif

#if !DISABLESTEAMWORKS
using Steamworks;
#endif

/// <summary>
/// 显示当前 Steam 用户的头像和昵称。
/// 挂到 StartScene 的 Canvas 下，Inespctor 拖入 RawImage（头像）和 TMP_Text（昵称）。
/// 未绑定则跳过对应功能。
/// </summary>
public class SteamProfileUI : MonoBehaviour
{
    [Header("UI 绑定")]
    [SerializeField] private RawImage _avatarImage;
    [SerializeField] private TMP_Text _nameText;

#if !DISABLESTEAMWORKS
    private Callback<AvatarImageLoaded_t> _avatarCallback;
#endif

    private void Start()
    {
#if !DISABLESTEAMWORKS
        LoadName();
        RequestAvatar();
#else
        if (_nameText != null) _nameText.text = "(Steam 未启用)";
#endif
    }

    // ================================================================
    // 昵称（同步可用）
    // ================================================================
#if !DISABLESTEAMWORKS
    private void LoadName()
    {
        if (_nameText == null) return;

        if (SteamUser.BLoggedOn())
        {
            _nameText.text = SteamFriends.GetPersonaName();
        }
        else
        {
            _nameText.text = "(Steam 登录中...)";
            StartCoroutine(PollUntilLoggedOn());
        }
    }

    private System.Collections.IEnumerator PollUntilLoggedOn()
    {
        float waited = 0f;
        while (!SteamUser.BLoggedOn() && waited < 30f)
        {
            yield return new WaitForSeconds(0.5f);
            waited += 0.5f;
        }

        if (SteamUser.BLoggedOn() && _nameText != null)
        {
            _nameText.text = SteamFriends.GetPersonaName();
        }
    }

    // ================================================================
    // 头像（需要回调，异步）
    // ================================================================
    private void RequestAvatar()
    {
        if (_avatarImage == null) return;
        if (!SteamUser.BLoggedOn())
        {
            StartCoroutine(PollSteamThenRequestAvatar());
            return;
        }

        _avatarCallback ??= Callback<AvatarImageLoaded_t>.Create(OnAvatarLoaded);
        TryGetAvatarNow();
    }

    private System.Collections.IEnumerator PollSteamThenRequestAvatar()
    {
        float waited = 0f;
        while (!SteamUser.BLoggedOn() && waited < 30f)
        {
            yield return new WaitForSeconds(0.5f);
            waited += 0.5f;
        }

        if (SteamUser.BLoggedOn())
        {
            _avatarCallback = Callback<AvatarImageLoaded_t>.Create(OnAvatarLoaded);
            TryGetAvatarNow();
        }
    }

    private void TryGetAvatarNow()
    {
        int handle = SteamFriends.GetLargeFriendAvatar(SteamUser.GetSteamID());

        if (handle == 0)
        {
            Debug.Log("[SteamProfileUI] 用户未设置 Steam 头像");
            return;
        }
        // handle == -1: 请求已发出，等 AvatarImageLoaded_t 回调
        if (handle > 0)
        {
            ApplyAvatarTexture(handle);
        }
    }

    private void OnAvatarLoaded(AvatarImageLoaded_t cb)
    {
        if (cb.m_steamID != SteamUser.GetSteamID()) return;
        if (cb.m_iImage > 0) ApplyAvatarTexture(cb.m_iImage);
    }

    private void ApplyAvatarTexture(int handle)
    {
        if (!SteamUtils.GetImageSize(handle, out uint w, out uint h)) return;

        byte[] buf = new byte[w * h * 4];
        if (!SteamUtils.GetImageRGBA(handle, buf, buf.Length)) return;

        var tex = new Texture2D((int)w, (int)h, TextureFormat.RGBA32, false);
        tex.LoadRawTextureData(buf);
        tex.Apply();

        _avatarImage.texture = tex;
    }

    private void OnDestroy()
    {
        _avatarCallback?.Dispose();
    }
#endif
}
