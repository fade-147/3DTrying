using TMPro;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 首次登录名字输入 UI — 强制输入，不可关闭。
/// 挂到 StartScene Canvas 下的名字面板上。
/// </summary>
public class FirstLoginNameUI : MonoBehaviour
{
    [Header("UI 控件")]
    [SerializeField] private GameObject _panelRoot;
    [SerializeField] private TMP_InputField _inputField;
    [SerializeField] private Button _confirmButton;
    [SerializeField] private TMP_Text _errorText;

    [Header("字数限制")]
    [SerializeField] private int _maxChars = 16;

    private void Start()
    {
        _confirmButton.onClick.AddListener(OnConfirm);

        if (_inputField != null)
            _inputField.characterLimit = _maxChars;

        // 已有名字 → 不显示
        if (PlayerNameManager.Instance.HasName)
        {
            _panelRoot.SetActive(false);
            return;
        }

        // 首次登录 → 弹出
        _panelRoot.SetActive(true);
        if (_errorText != null) _errorText.text = "";
    }

    private void OnConfirm()
    {
        string name = _inputField?.text?.Trim() ?? "";

        if (string.IsNullOrEmpty(name))
        {
            if (_errorText != null) _errorText.text = "名字不能为空";
            return;
        }

        PlayerNameManager.Instance.SetName(name);
        _panelRoot.SetActive(false);
    }
}
