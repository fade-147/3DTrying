using TMPro;
using UnityEngine;

/// <summary>
/// 在 StartScene 显示玩家当前游戏名。
/// 挂到任意有 TMP_Text 的 GameObject 上即可。
/// </summary>
public class PlayerNameDisplay : MonoBehaviour
{
    [SerializeField] private TMP_Text _nameText;

    private void Start()
    {
        // 名字就绪后刷新
        if (PlayerNameManager.Instance.HasName)
            _nameText.text = PlayerNameManager.Instance.PlayerName;

        PlayerNameManager.Instance.OnNameChanged += OnNameChanged;
    }

    private void OnNameChanged(string name)
    {
        _nameText.text = name;
    }

    private void OnDestroy()
    {
        if (PlayerNameManager.Instance != null)
            PlayerNameManager.Instance.OnNameChanged -= OnNameChanged;
    }
}
