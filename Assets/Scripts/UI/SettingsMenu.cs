using UnityEngine;
using UnityEngine.UI;
using StarterAssets;

/// <summary>
/// Settings panel logic for GameScene.
/// F1 to toggle, manages volume / sensitivity sliders, surrender button.
/// MUST be on an always-active GameObject. The visual _panel child toggles visibility.
/// </summary>
public class SettingsMenu : MonoBehaviour
{
    public static bool IsOpen { get; private set; }

    [Header("Visual Panel (child that toggles)")]
    [SerializeField] private GameObject _panel;

    [Header("Sliders")]
    [SerializeField] private Slider _volumeSlider;
    [SerializeField] private Slider _sensitivityXSlider;
    [SerializeField] private Slider _sensitivityYSlider;

    [Header("Surrender")]
    [SerializeField] private Button _surrenderButton;

    private ThirdPersonController _tpc;
    private InfimaGames.LowPolyShooterPack.Character _lpspCharacter;
    private InfimaGames.LowPolyShooterPack.CameraLook _cameraLook;
    private SurrenderVoteManager _voteManager;
    private bool _initialized;

    private const string PP_VOLUME = "Settings_Volume";
    private const string PP_SENS_X = "Settings_SensX";
    private const string PP_SENS_Y = "Settings_SensY";

    private const float SENS_MIN = 0.1f;
    private const float SENS_MAX = 1.9f;
    private const float SENS_DEFAULT = 1.0f;
    private const float VOL_DEFAULT = 0.8f;

    private void Start()
    {
        TryInit();
    }

    private void Update()
    {
        if (Input.GetKeyDown(KeyCode.F1))
        {
            TryInit(); // lazy init in case player spawned after us
            TogglePanel();
        }
    }

    /// <summary>
    /// One-time slider setup. Player refs are refreshed on each OpenPanel() call
    /// because respawn destroys old player objects.
    /// </summary>
    private void TryInit()
    {
        if (_initialized) return;

        // Slider setup (once)
        if (_volumeSlider != null)
        {
            _volumeSlider.minValue = 0f;
            _volumeSlider.maxValue = 1f;
            _volumeSlider.value = PlayerPrefs.GetFloat(PP_VOLUME, VOL_DEFAULT);
            _volumeSlider.onValueChanged.AddListener(OnVolumeChanged);
            AudioListener.volume = _volumeSlider.value;
        }

        if (_sensitivityXSlider != null)
        {
            _sensitivityXSlider.minValue = SENS_MIN;
            _sensitivityXSlider.maxValue = SENS_MAX;
            _sensitivityXSlider.value = PlayerPrefs.GetFloat(PP_SENS_X, SENS_DEFAULT);
            _sensitivityXSlider.onValueChanged.AddListener(OnSensitivityXChanged);
        }

        if (_sensitivityYSlider != null)
        {
            _sensitivityYSlider.minValue = SENS_MIN;
            _sensitivityYSlider.maxValue = SENS_MAX;
            _sensitivityYSlider.value = PlayerPrefs.GetFloat(PP_SENS_Y, SENS_DEFAULT);
            _sensitivityYSlider.onValueChanged.AddListener(OnSensitivityYChanged);
        }

        if (_surrenderButton != null)
            _surrenderButton.onClick.AddListener(OnSurrenderClicked);

        _voteManager = FindObjectOfType<SurrenderVoteManager>();
        _initialized = true;
        Debug.Log("[SettingsMenu] Sliders initialized.");
    }

    /// <summary>
    /// Re-finds local player references. Called every time panel opens,
    /// so respawned players get fresh refs (old ones become fake-null after destroy).
    /// </summary>
    private void RefreshPlayerRefs()
    {
        _tpc = null;
        _lpspCharacter = null;
        _cameraLook = null;

        var tpcArray = FindObjectsOfType<ThirdPersonController>();
        foreach (var t in tpcArray)
        {
            if (t.isLocalPlayer)
            {
                _tpc = t;
                break;
            }
        }

        if (_tpc != null)
        {
            _lpspCharacter = _tpc.GetComponentInChildren<InfimaGames.LowPolyShooterPack.Character>(true);
            _cameraLook = _tpc.GetComponentInChildren<InfimaGames.LowPolyShooterPack.CameraLook>(true);

            // Re-apply saved sensitivity to new player instance
            if (_sensitivityXSlider != null) _tpc.sensitivityX = _sensitivityXSlider.value;
            if (_sensitivityYSlider != null) _tpc.sensitivityY = _sensitivityYSlider.value;
            SyncCameraLookSensitivity();
        }
    }

    public void TogglePanel()
    {
        if (IsOpen)
            ClosePanel();
        else
            OpenPanel();
    }

    private void OpenPanel()
    {
        // Always refresh — respawn destroys old player object
        RefreshPlayerRefs();

        IsOpen = true;
        if (_panel != null) _panel.SetActive(true);

        Cursor.visible = true;
        Cursor.lockState = CursorLockMode.None;

        // Block LPSP input path (Editor)
        if (_lpspCharacter != null)
            _lpspCharacter.SetCursorLocked(false);

        // Block TPC Build input path
        if (_tpc != null)
            _tpc.CursorInputForLook = false;
    }

    private void ClosePanel()
    {
        IsOpen = false;
        if (_panel != null) _panel.SetActive(false);

        Cursor.visible = false;
        Cursor.lockState = CursorLockMode.Locked;

        // Restore LPSP input path (Editor)
        if (_lpspCharacter != null)
            _lpspCharacter.SetCursorLocked(true);

        // Restore TPC Build input path
        if (_tpc != null)
            _tpc.CursorInputForLook = true;
    }

    private void OnVolumeChanged(float value)
    {
        AudioListener.volume = value;
        PlayerPrefs.SetFloat(PP_VOLUME, value);
        PlayerPrefs.Save();
    }

    private void OnSensitivityXChanged(float value)
    {
        if (_tpc != null) _tpc.sensitivityX = value;
        SyncCameraLookSensitivity();
        PlayerPrefs.SetFloat(PP_SENS_X, value);
        PlayerPrefs.Save();
    }

    private void OnSensitivityYChanged(float value)
    {
        if (_tpc != null) _tpc.sensitivityY = value;
        SyncCameraLookSensitivity();
        PlayerPrefs.SetFloat(PP_SENS_Y, value);
        PlayerPrefs.Save();
    }

    /// <summary>
    /// Applies TPC sensitivity values to LPSP CameraLook so Editor-mode camera also responds.
    /// </summary>
    private void SyncCameraLookSensitivity()
    {
        if (_cameraLook != null && _tpc != null)
            _cameraLook.SetSensitivityMultiplier(_tpc.sensitivityX, _tpc.sensitivityY);
    }

    private void OnSurrenderClicked()
    {
        if (_tpc == null) return;

        // Refresh every time — SurrenderVoteManager might have spawned after us
        if (_voteManager == null)
            _voteManager = FindObjectOfType<SurrenderVoteManager>();

        if (_voteManager == null)
        {
            Debug.LogError("[SettingsMenu] SurrenderVoteManager not found in scene! Make sure it exists with NetworkIdentity.");
            return;
        }

        int myTeam = _tpc.teamId;
        _voteManager.InitiateSurrender(myTeam);

        // Auto-close panel so the vote UI is visible
        ClosePanel();

        if (_surrenderButton != null)
            _surrenderButton.interactable = false;
    }

    public void EnableSurrenderButton()
    {
        if (_surrenderButton != null)
            _surrenderButton.interactable = true;
    }
}
