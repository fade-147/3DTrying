using UnityEngine;
using StarterAssets;

/// <summary>
/// Manages first-person / third-person view switching.
/// Extracted from ThirdPersonController.ToggleFirstPerson() + ApplyPersonView().
/// Third-person module REMAINS UNCHANGED (StarterAssetsThirdPerson, Cinemachine, etc.)
/// </summary>
public class PlayerViewManager : MonoBehaviour
{
    [Header("View Modules")]
    [Tooltip("Root GameObject containing all third-person elements (model, Cinemachine, etc.)")]
    public GameObject thirdPersonModule;
    [Tooltip("Root GameObject containing all first-person elements (new LPSP FP rig)")]
    public GameObject firstPersonModule;

    [Header("First-Person References")]
    public Camera fpCamera;
    public Transform fpCameraRoot;
    public GameObject firstPersonModelGun;

    [Header("Third-Person References")]
    public Cinemachine.CinemachineVirtualCamera thirdPersonVCam;
    public GameObject thirdPersonModel;
    public GameObject firstPersonModel;   // The old FP_CH mesh (will be replaced)

    [Header("Settings")]
    public bool startInFirstPerson = false;
    public float fpMouseSensitivity = 1.5f;

    [Header("Misc")]
    public GameObject cameraMap;

    // Internal state
    [HideInInspector] public bool isFirstPerson;
    [HideInInspector] public float fpYaw;
    [HideInInspector] public float fpPitch;

    // References
    private PlayerState _state;
    private PlayerNetwork _network;
    private StarterAssetsInputs _input;
    private GameObject _mainCamera;

    private const float _threshold = 0.01f;

    void Awake()
    {
        _state = GetComponent<PlayerState>();
        _network = GetComponent<PlayerNetwork>();
        _input = GetComponent<StarterAssetsInputs>();

        if (_mainCamera == null)
            _mainCamera = GameObject.FindGameObjectWithTag("MainCamera");

        // Find Cinemachine camera
        thirdPersonVCam = FindObjectOfType<Cinemachine.CinemachineVirtualCamera>();
    }

    void Start()
    {
        // Remote players: always show third person, hide first person
        if (!isLocalPlayer)
        {
            if (thirdPersonModel != null) thirdPersonModel.SetActive(true);
            if (firstPersonModel != null) firstPersonModel.SetActive(false);
            if (firstPersonModelGun != null) firstPersonModelGun.SetActive(false);
            if (fpCamera != null) fpCamera.gameObject.SetActive(false);
            return;
        }

        // Local player initialization
        isFirstPerson = startInFirstPerson;

        if (thirdPersonVCam != null)
        {
            Transform target = null;
            if (thirdPersonModule != null)
            {
                target = thirdPersonModule.transform.Find("CinemachineCameraTarget");
                if (target == null) target = thirdPersonModule.transform.Find("PlayerCameraRoot");
                // Search deeper if not found directly
                if (target == null)
                {
                    var deep = FindDeep(thirdPersonModule.transform, "PlayerCameraRoot");
                    if (deep != null) target = deep;
                }
            }
            if (target != null)
            {
                thirdPersonVCam.Follow = target;
                thirdPersonVCam.LookAt = target;
                Debug.Log("VCam target set to: " + target.name);
            }
            else
                Debug.LogWarning("Could not find CinemachineCameraTarget or PlayerCameraRoot under ThirdPersonModule");
        }

        ApplyPersonView();
        if (cameraMap != null) cameraMap.SetActive(true);

        Cursor.visible = false;
        Cursor.lockState = CursorLockMode.Locked;
    }

    void Update()
    {
        if (!isLocalPlayer) return;

        // L key toggles first/third person
        if (Input.GetKeyDown(KeyCode.L) && !_state.isDrinking)
        {
            ToggleFirstPerson();
        }
    }

    /// <summary>
    /// Toggle between first-person and third-person view.
    /// </summary>
    public void ToggleFirstPerson()
    {
        if (!isLocalPlayer) return;

        isFirstPerson = !isFirstPerson;
        _state.isFirstPerson = isFirstPerson;
        ApplyPersonView();

        if (!isFirstPerson && _state.isHoldingGun)
        {
            _network.CmdTriggerChangeGunView();
        }

        Debug.Log("View switched to: " + (isFirstPerson ? "First Person" : "Third Person"));
    }

    /// <summary>
    /// Apply the current view state: show/hide modules and cameras.
    /// </summary>
    public void ApplyPersonView()
    {
        // Third-person module
        if (thirdPersonModule != null)
            thirdPersonModule.SetActive(!isFirstPerson);

        // First-person module
        if (firstPersonModule != null)
            firstPersonModule.SetActive(isFirstPerson);

        // Legacy references (for backward compatibility during transition)
        if (thirdPersonModel != null) thirdPersonModel.SetActive(!isFirstPerson);
        if (firstPersonModel != null) firstPersonModel.SetActive(isFirstPerson);
        if (firstPersonModelGun != null)
            firstPersonModelGun.SetActive(isFirstPerson && _state.isHoldingGun);

        // Cameras
        if (fpCamera != null) fpCamera.gameObject.SetActive(isFirstPerson);
        if (thirdPersonVCam != null) thirdPersonVCam.gameObject.SetActive(!isFirstPerson);

        if (_mainCamera != null) _mainCamera.SetActive(!isFirstPerson);

        // Reset FPS angles when entering first person
        if (isFirstPerson)
        {
            fpYaw = transform.eulerAngles.y;
            fpPitch = 0;
            if (fpCameraRoot != null)
                fpCameraRoot.localRotation = Quaternion.Euler(0f, 0f, 0f);
        }
    }

    /// <summary>
    /// Returns the currently active camera.
    /// </summary>
    public Camera GetActiveCamera()
    {
        return isFirstPerson ? fpCamera : Camera.main;
    }

    // Helper property for compatibility
    private bool isLocalPlayer
    {
        get
        {
            var identity = GetComponent<Mirror.NetworkIdentity>();
            return identity != null && identity.isLocalPlayer;
        }
    }

    void OnDestroy()
    {
        Cursor.visible = true;
        Cursor.lockState = CursorLockMode.None;
    }

    private Transform FindDeep(Transform parent, string name)
    {
        foreach (Transform child in parent)
        {
            if (child.name == name) return child;
            var f = FindDeep(child, name);
            if (f != null) return f;
        }
        return null;
    }
}
