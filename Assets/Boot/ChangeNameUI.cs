using TMPro;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 更改名字 UI — 有确认和取消按钮，可关闭。
/// 挂到 StartScene Canvas 下的更改名字面板上。
/// </summary>
public class ChangeNameUI : MonoBehaviour
{
    [Header("UI 控件")]
    [SerializeField] private GameObject _panelRoot;
    [SerializeField] private TMP_InputField _inputField;
    [SerializeField] private Button _confirmButton;
    [SerializeField] private Button _cancelButton;
    [SerializeField] private TMP_Text _errorText;

    [Header("触发按钮（点击打开此面板）")]
    [SerializeField] private Button _openButton;

    [Header("字数限制")]
    [SerializeField] private int _maxChars = 16;

    private void Start()
    {
        _confirmButton.onClick.AddListener(OnConfirm);
        _cancelButton.onClick.AddListener(OnCancel);

        if (_openButton != null)
            _openButton.onClick.AddListener(Open);

        if (_inputField != null)
            _inputField.characterLimit = _maxChars;

        _panelRoot.SetActive(false);
    }

    /// <summary>按钮点击打开面板（挂到更改名字 Button 的 onClick 上）</summary>
    public void Open()
    {
        _panelRoot.SetActive(true);
        if (_inputField != null)
            _inputField.text = PlayerNameManager.Instance.PlayerName;
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

        PlayerNameManager.Instance.ChangeName(name);
        _panelRoot.SetActive(false);
    }

    private void OnCancel()
    {
        _panelRoot.SetActive(false);
    }
}
