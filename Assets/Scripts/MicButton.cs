using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;

[RequireComponent(typeof(Button))]
public class MicButton : MonoBehaviour
{
    [SerializeField] Image iconImage;
    [SerializeField] GameObject iconMicOn;
    [SerializeField] GameObject iconMicOff;
    [SerializeField] Text labelText;

    VoiceChatManager voiceChatManager;
    Button button;

    void Start()
    {
        voiceChatManager = VoiceChatManager.Instance;
        if (voiceChatManager == null)
            voiceChatManager = FindObjectOfType<VoiceChatManager>();

        button = GetComponent<Button>();
        button.navigation = new Navigation { mode = Navigation.Mode.None };
        button.onClick.AddListener(OnClick);
        UpdateVisual();

        if (EventSystem.current != null)
            EventSystem.current.SetSelectedGameObject(null);
    }

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.B))
            OnClick();
    }

    void OnClick()
    {
        if (voiceChatManager != null)
        {
            voiceChatManager.ToggleMode();
            UpdateVisual();
        }
    }

    void UpdateVisual()
    {
        if (voiceChatManager == null) return;

        MicMode mode = voiceChatManager.CurrentMode;
        if (iconImage != null)
        {
            iconImage.color = mode switch
            {
                MicMode.All => Color.green,
                MicMode.TeamOnly => new Color(1f, 0.92f, 0.016f), // 黄色
                MicMode.Muted => new Color(1f, 0.6f, 0f),         // 橙色 — 关麦但能听
                MicMode.Deafened => Color.red,
                _ => Color.red
            };

            // 开麦图标：全部、仅队伍；关麦图标：关麦、静音
            bool isMicOn = mode == MicMode.All || mode == MicMode.TeamOnly;
            if (iconMicOn != null) iconMicOn.SetActive(isMicOn);
            if (iconMicOff != null) iconMicOff.SetActive(!isMicOn);
        }
        if (labelText != null)
        {
            labelText.text = mode switch
            {
                MicMode.All => "全部",
                MicMode.TeamOnly => "仅队伍",
                MicMode.Muted => "已关麦",
                MicMode.Deafened => "已静音",
                _ => "已静音"
            };
        }
    }
}
