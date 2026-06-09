using UnityEngine;
using UnityEngine.InputSystem;
using Mirror;

namespace StarterAssets
{
    /// <summary>
    /// Core NetworkBehaviour that bridges Mirror lifecycle, view switching (1P/3P),
    /// animation sync, and shooting between the LPSP FP system and Mirror networking.
    ///
    /// On the prefab root (Player_FPS_TP), alongside ThirdPersonController, Character (LPSP),
    /// ThirdPersonMovementBridge, and PlayerCharacter.
    /// </summary>
    [RequireComponent(typeof(NetworkIdentity))]
    [RequireComponent(typeof(NetworkTransformReliable))]
    public class PlayerNetworkBridge : NetworkBehaviour
    {
        #region SERIALIZED

        [Header("References")]
        [SerializeField]
        private ThirdPersonController thirdPersonController;

        [SerializeField]
        private InfimaGames.LowPolyShooterPack.CharacterBehaviour characterBehaviour;

        [SerializeField]
        private PlayerCharacter playerCharacter;

        [Header("Visuals")]
        [SerializeField]
        private GameObject thirdPersonVisual;

        [SerializeField]
        private GameObject characterRoot; // LPSP Character Root (Animator) root GO

        [Header("Cameras")]
        [SerializeField]
        private Camera fpCamera;

        [Header("Animators")]
        [SerializeField]
        private Animator tpAnimator;

        [SerializeField]
        private Animator fpAnimator;

        [Header("Input")]
        [SerializeField]
        private PlayerInput playerInput;

        [Header("State")]
        [SyncVar]
        public int teamId;

        #endregion

        #region FIELDS

        private bool _isFirstPerson;

        /// <summary>
        /// Public read-only accessor for ThirdPersonController to check the current view mode.
        /// </summary>
        public bool IsFirstPerson => _isFirstPerson;

        /// <summary>
        /// Cached FP animator reference (wired in prefab). Exposed for TPC fallback.
        /// </summary>
        public Animator FpAnimator => fpAnimator;

        private NetworkAnimator _networkAnimator;
        private Cinemachine.CinemachineVirtualCamera _thirdPersonVCam;
        private bool _referencesCached;

        // Cached animator parameter hashes for 3P sync
        private static readonly int HashMovement = Animator.StringToHash("Movement");
        private static readonly int HashHorizontal = Animator.StringToHash("Horizontal");
        private static readonly int HashVertical = Animator.StringToHash("Vertical");
        private static readonly int HashRunning = Animator.StringToHash("Running");
        private static readonly int HashAim = Animator.StringToHash("Aim");
        private static readonly int HashCrouching = Animator.StringToHash("Crouching");
        private static readonly int HashReloading = Animator.StringToHash("Reloading");
        private static readonly int HashHolstered = Animator.StringToHash("Holstered");
        private static readonly int HashGrounded = Animator.StringToHash("Grounded");
        private static readonly int HashJump = Animator.StringToHash("Jump");
        private static readonly int HashFreeFall = Animator.StringToHash("FreeFall");
        private static readonly int HashSpeed = Animator.StringToHash("Speed");
        private static readonly int HashMotionSpeed = Animator.StringToHash("MotionSpeed");

        #endregion

        #region UNITY LIFECYCLE

        private void Awake()
        {
            _networkAnimator = GetComponent<NetworkAnimator>();
            CacheReferences();

            // Register character with ServiceLocator NOW (in Awake) so that LPSP
            // components (CameraLook, PlaySoundCharacterBehaviour, Element, etc.)
            // can find it in their Start(). OnStartLocalPlayer runs too late.
            RegisterCharacterWithServices();
        }

        private void CacheReferences()
        {
            if (_referencesCached) return;

            if (thirdPersonController == null)
                thirdPersonController = GetComponent<ThirdPersonController>();
            if (characterBehaviour == null)
                characterBehaviour = GetComponent<InfimaGames.LowPolyShooterPack.CharacterBehaviour>();
            if (playerCharacter == null)
                playerCharacter = GetComponent<PlayerCharacter>();

            _referencesCached = true;
        }

        private void Update()
        {
            if (!isLocalPlayer) return;

            // L key toggles 1P/3P
            if (Keyboard.current != null && Keyboard.current.lKey.wasPressedThisFrame)
                ToggleView();
        }

        private void LateUpdate()
        {
            if (!isLocalPlayer) return;

            // Sync LPSP FP animator parameters to 3P animator for networked animation.
            // NetworkAnimator stays on tpAnimator always (set by Editor tool) — only 3P
            // needs network sync; FP animator is local-only. Swapping animators at runtime
            // causes Mirror IndexOutOfRange because layer arrays don't resize.
            SyncAnimatorParameters();
        }

        #endregion

        #region MIRROR LIFECYCLE

        public override void OnStartLocalPlayer()
        {
            base.OnStartLocalPlayer();

            CacheReferences();

            // --- Component conflict resolution ---
            //
            // Two systems coexist on this prefab:
            //   A) LPSP (Character + Movement + CameraLook + LowerWeapon + Motion + Recoil)
            //   B) TPC  (ThirdPersonController — custom movement, camera, shooting)
            //
            // Permanent conflicts (ALWAYS disable, Editor and Build):
            //   • Movement   — calls Move() on same CharacterController, overwrites TPC's velocity
            //   • CameraLook — rotates camera in LateUpdate, conflicts with TPC.UpdateFPSCamera()
            //
            // Build-only conflicts (only in IL2CPP, InvokeUnityEvents broken):
            //   • Character   — OnLook/OnMovement/OnFire never fire, equippedWeapon NRE
            //   • LowerWeapon — NRE when characterBehaviour is disabled
            //   • Motion/Recoil — NRE in LateUpdate when characterBehaviour is disabled
            //
            // In Editor, InvokeUnityEvents works correctly. Keep Character enabled
            // for Q/E leaning, weapon animations, procedural motion, and recoil.

            // ── Always disabled (Editor + Build) ──
            // Movement: calls Move() on same CharacterController, overwrites TPC velocity.
            var allMovement = GetComponentsInChildren<InfimaGames.LowPolyShooterPack.Movement>(true);
            foreach (var m in allMovement)
            {
                m.enabled = false;
                Debug.Log($"[PNB] Disabled LPSP Movement on '{m.gameObject.name}'.");
            }

            // ── Build-only: disable LPSP chain (InvokeUnityEvents broken in IL2CPP) ──
            // In Editor, InvokeUnityEvents works correctly. Keep Character, CameraLook,
            // LowerWeapon, MotionApplier, and RecoilMotion enabled for Q/E leaning,
            // smooth animations, procedural motion, recoil, and camera rotation.
#if !UNITY_EDITOR
            if (characterBehaviour != null)
            {
                characterBehaviour.enabled = false;
                Debug.Log("[PNB] Disabled LPSP Character (IL2CPP: InvokeUnityEvents broken).");
            }

            var allCameraLook = GetComponentsInChildren<InfimaGames.LowPolyShooterPack.CameraLook>(true);
            foreach (var c in allCameraLook)
            {
                c.enabled = false;
                Debug.Log($"[PNB] Disabled LPSP CameraLook on '{c.gameObject.name}'.");
            }

            var allLowerWeapon = GetComponentsInChildren<InfimaGames.LowPolyShooterPack.LowerWeapon>(true);
            foreach (var lw in allLowerWeapon)
            {
                lw.enabled = false;
                Debug.Log($"[PNB] Disabled LPSP LowerWeapon on '{lw.gameObject.name}'.");
            }

            var allMotionApplier = GetComponentsInChildren<InfimaGames.LowPolyShooterPack.MotionApplier>(true);
            foreach (var ma in allMotionApplier)
            {
                ma.enabled = false;
                Debug.Log($"[PNB] Disabled LPSP MotionApplier on '{ma.gameObject.name}'.");
            }
            var allRecoilMotion = GetComponentsInChildren<InfimaGames.LowPolyShooterPack.RecoilMotion>(true);
            foreach (var rm in allRecoilMotion)
            {
                rm.enabled = false;
                Debug.Log($"[PNB] Disabled LPSP RecoilMotion on '{rm.gameObject.name}'.");
            }
#else
            // Character starts disabled in prefab (m_Enabled: 0). Enable it so that
            // InvokeUnityEvents fire — OnLook/OnMovement/OnTryFire/OnTryPlayReload —
            // which drive CameraLook, UpdateAnimator, weapon firing, reload, and ammo.
            if (characterBehaviour != null)
            {
                characterBehaviour.enabled = true;
                Debug.Log("[PNB] Editor mode: LPSP Character enabled.");
            }
            Debug.Log("[PNB] Editor mode: CameraLook + animation chain kept enabled.");
#endif

            // Enable input
            if (playerInput != null)
            {
                playerInput.enabled = true;
            }

            // Default to 1P for local player
            _isFirstPerson = true;
            ApplyViewMode();

            // Lock cursor
            Cursor.visible = false;
            Cursor.lockState = CursorLockMode.Locked;
        }

        public override void OnStartServer()
        {
            base.OnStartServer();
            CacheReferences();
        }

        public override void OnStartClient()
        {
            base.OnStartClient();

            if (!isLocalPlayer)
            {
                // Remote players are always 3P
                _isFirstPerson = false;
                ApplyViewMode();

                // Disable FP character system for remote players
                if (characterBehaviour != null)
                    characterBehaviour.enabled = false;
            }
        }

        private void RegisterCharacterWithServices()
        {
            var sl = InfimaGames.LowPolyShooterPack.ServiceLocator.Current;
            if (sl == null) return;

            var gm = sl.Get<InfimaGames.LowPolyShooterPack.IGameModeService>();
            gm?.RegisterPlayerCharacter(characterBehaviour);
        }

        #endregion

        #region VIEW MANAGEMENT

        /// <summary>
        /// Toggles between first-person and third-person view.
        /// </summary>
        public void ToggleView()
        {
            _isFirstPerson = !_isFirstPerson;
            ApplyViewMode();
        }

        private void ApplyViewMode()
        {
            // 3P visual (model, Cinemachine target)
            if (thirdPersonVisual != null)
                thirdPersonVisual.SetActive(!_isFirstPerson);

            // LPSP Character Root (FP rig + animator + camera)
            if (characterRoot != null)
                characterRoot.SetActive(_isFirstPerson);

            // FP camera
            if (fpCamera != null)
                fpCamera.gameObject.SetActive(_isFirstPerson);

            // Cinemachine 3P camera
            if (_thirdPersonVCam == null)
                _thirdPersonVCam = FindObjectOfType<Cinemachine.CinemachineVirtualCamera>();
            if (_thirdPersonVCam != null)
                _thirdPersonVCam.gameObject.SetActive(!_isFirstPerson);

            // ThirdPersonController reads IsFirstPerson from this bridge each frame.
            // CameraLook handles FP camera when in 1P; CameraRotation is skipped automatically.
            // NetworkAnimator.animator is NOT swapped here — it stays on tpAnimator
            // (set by Editor tool). Swapping causes Mirror layer array IndexOutOfRange.
        }

        #endregion

        #region ANIMATOR SYNC

        /// <summary>
        /// Copies key parameters from the LPSP FP animator to the 3P animator
        /// so that remote players see correct locomotion animations.
        /// </summary>
        private void SyncAnimatorParameters()
        {
            if (fpAnimator == null || tpAnimator == null) return;

            // Locomotion
            tpAnimator.SetFloat(HashMovement, fpAnimator.GetFloat(HashMovement));
            tpAnimator.SetFloat(HashHorizontal, fpAnimator.GetFloat(HashHorizontal));
            tpAnimator.SetFloat(HashVertical, fpAnimator.GetFloat(HashVertical));
            tpAnimator.SetBool(HashRunning, fpAnimator.GetBool(HashRunning));
            tpAnimator.SetBool(HashAim, fpAnimator.GetBool(HashAim));
            tpAnimator.SetBool(HashCrouching, fpAnimator.GetBool(HashCrouching));
            tpAnimator.SetBool(HashReloading, fpAnimator.GetBool(HashReloading));
            tpAnimator.SetBool(HashHolstered, fpAnimator.GetBool(HashHolstered));

            // Also sync TPC-driven grounded/jump state from tpAnimator (set by TPC GroundedCheck/JumpAndGravity)
            // No need to sync back -- TPC already writes to tpAnimator directly.
        }

        #endregion

        #region TEAM MANAGEMENT

        /// <summary>
        /// Assigns team on server and propagates via SyncVar.
        /// </summary>
        public void SetTeam(int id)
        {
            if (isServer)
                teamId = id;
            else
                CmdSetTeam(id);
        }

        [Command]
        private void CmdSetTeam(int id)
        {
            teamId = id;
        }

        #endregion
    }
}
