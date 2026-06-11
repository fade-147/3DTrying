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

        /// <summary>
        /// 3P Animator reference (wired in prefab). Exposed for PlayerCharacter ragdoll.
        /// </summary>
        public Animator TpAnimator => tpAnimator;

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

            // ── Component conflict resolution ──
            // Two systems coexist: LPSP (visuals) + TPC (movement/networking).
            //
            // Always disabled:
            //   • Movement — calls Move() on same CC, overwrites TPC velocity.
            //
            // Always enabled (Editor + Build):
            //   • Character — animations, weapons, ammo, firing.
            //   • CameraLook — FP camera rotation.
            //   • LowerWeapon, MotionApplier, RecoilMotion — visual polish.
            //
            // Input delivery:
            //   Editor: InvokeUnityEvents (m_NotificationBehavior=2) calls Character.OnMove/OnLook/...
            //   Build:  PNB C# event bridge subscribes to pi.actions[*].performed and forwards to Character+TPC.
            //   TPC reads _moveInput from pi.actions in Editor; from bridge in Build.

            // ── Always disabled (Editor + Build) ──
            // Movement: calls Move() on same CharacterController, overwrites TPC velocity.
            var allMovement = GetComponentsInChildren<InfimaGames.LowPolyShooterPack.Movement>(true);
            foreach (var m in allMovement)
            {
                m.enabled = false;
                Debug.Log($"[PNB] Disabled LPSP Movement on '{m.gameObject.name}'.");
            }

            // ── Unified (Editor + Build): Character always enabled ──
            // Build uses C# event bridge to forward input to Character;
            // Editor uses InvokeUnityEvents (works correctly in Editor).

            // Character starts disabled in prefab (m_Enabled: 0). Enable it.
            if (characterBehaviour != null && !characterBehaviour.enabled)
            {
                characterBehaviour.enabled = true;
                Debug.Log("[PNB] LPSP Character enabled.");
            }
            Debug.Log("[PNB] Unified mode: all LPSP components enabled (Editor + Build).");

            // Spawn UI Canvas for the local player only, with correct Character reference.
            var canvasSpawner = GetComponent<InfimaGames.LowPolyShooterPack.Interface.CanvasSpawner>();
            if (canvasSpawner != null)
            {
                canvasSpawner.SpawnForCharacter(characterBehaviour);
                Debug.Log("[PNB] Canvas spawned for local player.");
            }

            // Enable input
            if (playerInput != null)
            {
                playerInput.enabled = true;
            }

#if !UNITY_EDITOR
            // Build: C# event bridge. InvokeUnityEvents may fail in IL2CPP+AssetBundle.
            // Subscribe to InputAction events directly and forward to Character + TPC.
            // Editor relies on InvokeUnityEvents (works correctly in Editor).
            SetupInputEventBridge();
#endif

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

        #region INPUT EVENT BRIDGE (Build)

#if !UNITY_EDITOR
        /// <summary>
        /// Build-only: forwards InputAction events to Character and TPC via C# API.
        /// InvokeUnityEvents (m_NotificationBehavior=2) may fail in IL2CPP+AssetBundle builds.
        /// C# event subscriptions are standard .NET and work reliably.
        ///
        /// Editor relies on InvokeUnityEvents — this bridge is NOT set up in Editor.
        /// </summary>
        private void SetupInputEventBridge()
        {
            if (playerInput == null) return;

            var chr = characterBehaviour as InfimaGames.LowPolyShooterPack.Character;
            var tpc = thirdPersonController;

            // Use PlayerInput.onActionTriggered — fires for EVERY action, independent of
            // pi.actions reference validity. Does not conflict with InvokeUnityEvents.
            playerInput.onActionTriggered += ctx =>
            {
                switch (ctx.action.name)
                {
                    case "Movement":
                        chr?.OnMove(ctx);
                        tpc?.OnMove(ctx);
                        break;
                    case "Look":
                        chr?.OnLook(ctx);
                        tpc?.OnLook(ctx);
                        break;
                    case "Fire":
                        chr?.OnTryFire(ctx);
                        break;
                    case "Reload":
                        chr?.OnTryPlayReload(ctx);
                        break;
                    case "Aim":
                        chr?.OnTryAiming(ctx);
                        break;
                    case "Inspect":
                        chr?.OnTryInspect(ctx);
                        break;
                    case "Run":
                        chr?.OnTryRun(ctx);
                        tpc?.OnSprint(ctx);
                        break;
                    case "Jump":
                        chr?.OnTryJump(ctx);
                        tpc?.OnJump(ctx);
                        break;
                    case "Holster":
                        chr?.OnTryHolster(ctx);
                        break;
                    case "Inventory Next":
                        chr?.OnTryInventoryNext(ctx);
                        break;
                }
            };

            Debug.Log("[PNB] Build: C# input bridge (onActionTriggered) active.");
        }
#endif

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
