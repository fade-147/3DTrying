using UnityEngine;

/// <summary>
/// Handles sensitivity settings UI binding and cursor management.
/// Extracted from ThirdPersonController.SetupSensitivitySettings().
/// </summary>
public class PlayerSettings : MonoBehaviour
{
    public float sensitivityX = 0.8f;
    public float sensitivityY = 0.8f;

    private SettingManager _settingManager;
    private GameObject _settingsObj;
    private bool _settingOpen;
    private PlayerState _state;
    private PlayerCombat _combat;
    private StarterAssets.StarterAssetsInputs _input;

    void Awake()
    {
        _state = GetComponent<PlayerState>();
        _combat = GetComponent<PlayerCombat>();
        _input = GetComponent<StarterAssets.StarterAssetsInputs>();
    }

    void Start()
    {
        var identity = GetComponent<Mirror.NetworkIdentity>();
        if (identity == null || !identity.isLocalPlayer) return;

        SetupSensitivitySettings();
    }

    void Update()
    {
        var identity = GetComponent<Mirror.NetworkIdentity>();
        if (identity == null || !identity.isLocalPlayer) return;

        if (Input.GetKeyDown(KeyCode.Tab))
        {
            _settingOpen = !_settingOpen;
            if (_settingsObj != null)
                _settingsObj.SetActive(_settingOpen);

            if (_settingOpen)
            {
                Cursor.visible = true;
                Cursor.lockState = CursorLockMode.None;
                if (_input != null)
                {
                    _input.cursorInputForLook = false;
                    _input.LookInput(Vector2.zero);
                }
            }
            else
            {
                Cursor.visible = false;
                Cursor.lockState = CursorLockMode.Locked;
                if (_input != null)
                    _input.cursorInputForLook = true;
            }
        }
    }

    private void SetupSensitivitySettings()
    {
        _settingsObj = GameObject.FindGameObjectWithTag("Settings");
        if (_settingsObj != null)
        {
            _settingManager = _settingsObj.GetComponent<SettingManager>();
            if (_settingManager != null)
            {
                if (_settingManager.sensitivityXSlider != null)
                {
                    _settingManager.sensitivityXSlider.minValue = 0.1f;
                    _settingManager.sensitivityXSlider.maxValue = 1.1f;
                    _settingManager.sensitivityXSlider.value = sensitivityX;
                    _settingManager.sensitivityXSlider.onValueChanged.AddListener(OnSensitivityXChanged);
                }
                if (_settingManager.sensitivityYSlider != null)
                {
                    _settingManager.sensitivityYSlider.minValue = 0.1f;
                    _settingManager.sensitivityYSlider.maxValue = 1.1f;
                    _settingManager.sensitivityYSlider.value = sensitivityY;
                    _settingManager.sensitivityYSlider.onValueChanged.AddListener(OnSensitivityYChanged);
                }
            }
            _settingsObj.SetActive(false);
        }
    }

    private void OnSensitivityXChanged(float value)
    {
        sensitivityX = value;
        if (_combat != null) _combat.SensitivityX = value;
    }

    private void OnSensitivityYChanged(float value)
    {
        sensitivityY = value;
        if (_combat != null) _combat.SensitivityY = value;
    }
}
