using UnityEngine;
using UnityEngine.UI;
using static Unity.Burst.Intrinsics.X86;
using System.Collections;
using Unity.VisualScripting;


#if ENABLE_INPUT_SYSTEM && STARTER_ASSETS_PACKAGES_CHECKED
using UnityEngine.InputSystem;
#endif

using Mirror;

namespace StarterAssets
{
    [RequireComponent(typeof(CharacterController))]
#if ENABLE_INPUT_SYSTEM && STARTER_ASSETS_PACKAGES_CHECKED
    [RequireComponent(typeof(PlayerInput))]
#endif
    public class ThirdPersonController : NetworkBehaviour
    {
        [Header("Player")]
        [SyncVar]
        public int teamId;  //用来区分玩家的队伍
        public float MoveSpeed = 2.0f;
        public float SprintSpeed = 5.335f;
        [Range(0.0f, 0.3f)]
        public float RotationSmoothTime = 0.12f;
        public float SpeedChangeRate = 10.0f;
        private PlayerCharacter player;

        [Space(10)]
        public float JumpHeight = 1.2f;
        public float Gravity = -15.0f;

        [Space(10)]
        public float JumpTimeout = 0.50f;
        public float FallTimeout = 0.15f;

        [Header("Player Grounded")]
        public bool Grounded = true;
        public float GroundedOffset = -0.14f;
        public float GroundedRadius = 0.28f;
        public LayerMask GroundLayers;

        [Header("Cinemachine")]
        public GameObject CinemachineCameraTarget;
        public float TopClamp = 70.0f;
        public float BottomClamp = -30.0f;
        public float CameraAngleOverride = 0.0f;
        public bool LockCameraPosition = false;

        [Header("First Person Switch (L键切换)")]
        [Space(10)]
        public GameObject thirdPersonModel;   // 第三人称角色模型
        public GameObject firstPersonModel;   // 第一人称模型
        public GameObject firstPersonModelGun;   // 第一人称模型手里的枪

        public Animator firstPersonAnimator;  // 第一人称Animator
        public Camera fpCamera;              // 第一人称相机
        public Transform fpCameraRoot;     // 第一人称相机父物体（脖子/头部）
        public GameObject cameraMap;       // 小地图专用相机
        private bool isFirstPerson = false;   // 是否为第一人称
        private Cinemachine.CinemachineVirtualCamera thirdPersonVCam; // 第三人称相机

        private float fpYaw;       // 左右转向
        private float fpPitch;     // 上下视角
        private float fpRotationVelocity;
        public float fpMouseSensitivity = 1.5f;  // FPS鼠标灵敏度

        // 换枪配置
        [Header("Gun Toggle (R键切换)")]
        [SyncVar(hook = nameof(OnHoldGunStateChanged))]
        public bool isHoldingGun = false;
        public float toggleGunLockTime = 2.5f;
        private bool _canToggleGun = true;

        // 弯腰瞄准配置
        [Header("Aim Bend Settings (鼠标上下弯腰)")]
        public float AimSensitivity = 2f; // 鼠标垂直灵敏度
        public float MinBendAngle = -45f; // 最小弯腰角度（向下）
        public float MaxBendAngle = 30f;  // 最大抬头角度（向上）
        public float BendSmoothTime = 0.1f; // 弯腰过渡平滑时间
        private Transform _spine2; // 控制弯腰的核心骨骼（Spine2）
        private float _currentBendAngle; // 当前弯腰角度
        private float _bendVelocity; // 平滑插值用的速度变量
        public Transform GunTransform; // 拖拽你的枪模型Transform到这里

        // 喝水
        [Header("Drink Water Settings")]
        public float DrinkDuration = 3f; // 喝水总时长
        public Image DrinkProgressUI; // 喝水进度条UI（Radial填充的Image）
        public KeyCode DrinkKey = KeyCode.C; // 喝水触发按键
        private bool _isDrinking = false; // 是否正在喝水
        private float _currentDrinkTime = 0f; // 当前喝水计时
        private int _animIDIsDrinking; // 喝水状态动画ID

        [Header("Shooting Settings (射线)")]
        public Camera MainCamera; // 主相机（拖拽赋值）
        public Transform thirdPersonMuzzle;  // 第三人称枪口
        public Transform firstPersonMuzzle;   // 第一人称枪口
        //public Transform MuzzlePoint; // 枪口位置（枪上创建空物体）
        public float FireRate = 0.2f; // 射速（每秒10发）
        public float MaxShootDistance = 100f; // 最大射击距离
        public GameObject HitEffect; // 命中特效预制体
        public GameObject MuzzleFlash; // 枪口特效预制体
        private float _fireTimer; // 射速冷却计时器
        public bool CanShoot = true; // 是否可射击（可用于换弹/持枪判断）
        public GameObject BulletPrefab; // 子弹预制体
        public float BulletSpeed = 800f; // 子弹速度（刚体力）
        public float BulletLifeTime = 2f; // 子弹生命周期（避免内存泄漏）
        [Header("Recoil Settings")]
        public float RecoilAmount = 1f; // 后坐力幅度
        public float RecoilSmoothTime = 0.1f;
        private float _recoilVelocity;
        private float _currentRecoil;

        private float _originalTopClamp; // 记录初始的TopClamp值

        private float _cinemachineTargetYaw;
        private float _cinemachineTargetPitch;
        private float _speed;
        private float _animationBlend;
        private float _targetRotation = 0.0f;
        private float _rotationVelocity;
        private float _verticalVelocity;
        private float _terminalVelocity = 53.0f;
        private float _jumpTimeoutDelta;
        private float _fallTimeoutDelta;

        // 动画ID
        private int _animIDSpeed;
        private int _animIDGrounded;
        private int _animIDJump;
        private int _animIDFreeFall;
        private int _animIDMotionSpeed;
        private int _animIDMoveLeft;
        private int _animIDMoveRight;
        private int _animIDMoveForward;
        private int _animIDMoveBack;
        private int _animIDIsHoldingGun;
        private int _animIDToggleGun;
        private int _animIDDrink = Animator.StringToHash("Drink"); // 喝水动画触发ID
        private int _animIDAim;
        private int _animIDAiming;
        private int _animIDInspect;
        private int _animIDInspecting;
        private int _animIDReload;

        // 检视枪状态
        private bool isInspecting = false;

        [Header("换弹")]
        private bool isReloading = false;
        public int maxAmmo = 20;      // 弹匣最大弹药
        public int currentAmmo = 20;   // 当前弹匣弹药
        public float reloadDuration = 2f; // 换弹总时长
        private float currentReloadTime = 0f;

        // 弹药UI Text
        private Text ammoTextUI;
        // 换弹进度UI
        private Image reloadProgressUI;
        // 枪的动画控制器
        public Animator gunAnimator;

        // 准星物体
        private GameObject collimatorUI;

        private Animator _animator;
        private NetworkAnimator _networkAnimator;

        private CharacterController _controller;
        private StarterAssetsInputs _input;
        private GameObject _mainCamera;
        private const float _threshold = 0.01f;
        private bool _hasAnimator;
        public bool IsRunning=false;

        private float _recoilPitch; // 后坐力目标角度（枪口上跳）
        private int _shotCount;                // 连续射击计数
        public int RecoilStartShot = 3;        // 第几发开始上跳
        public float RecoilRampSpeed = 0.5f;   // 上跳累积速度

        private SettingManager _settingManager;
        private bool SettingOpen=false;
        private GameObject settingsObj;
        private float _outlineUpdateTimer = 0f;
        private const float OUTLINE_UPDATE_INTERVAL = 1f; // 每秒更新一次敌人描边
        public float sensitivityX = 0.8f; // 设置中绑定，水平灵敏度
        public float sensitivityY = 0.8f;


        //枪口上跳配置
        [Header("第一人称 枪口上跳配置")]
        [Tooltip("垂直上跳基础幅度")] public float FpVerticalRecoil = 0.6f;
        [Tooltip("水平随机偏移最大幅度")] public float FpHorizontalRecoil = 0.2f;
        [Tooltip("连续射击上跳累积倍率")] public float RecoilRampMultiplier = 1.1f;
        [Tooltip("上跳平滑速度")] public float RecoilSmoothSpeed = 15f;
        [Tooltip("回弹平滑速度")] public float RecoilReturnSpeed = 8f;
        [Tooltip("最大上跳角度限制")] public float MaxRecoilAngle;
        [SerializeField] private Vector2 _currentRecoilOffset; // 当前后坐力偏移
        [SerializeField] private Vector2 _targetRecoilOffset;  // 目标后坐力偏移

        //新增：腰射散射配置
        [Header("腰射散射配置")]
        [Tooltip("基础最小散布角度（度）")] public float BaseSpread = 0.3f;
        [Tooltip("走路散布倍率")] public float WalkSpreadMultiplier = 1.5f;
        [Tooltip("跑步散布倍率")] public float SprintSpreadMultiplier = 3f;
        [Tooltip("每枪累积散布增量")] public float SpreadPerShot = 0.2f;
        [Tooltip("最大散布上限")] public float MaxSpread = 3f;
        [Tooltip("散布回落速度")] public float SpreadDecaySpeed = 5f;
        [Tooltip("开镜散布倍率")] public float AimSpreadMultiplier = 0.2f;
        [SerializeField] private float _currentSpread; // 当前实时散布值

        private void Awake()
        {
            if (_mainCamera == null)
            {
                _mainCamera = GameObject.FindGameObjectWithTag("MainCamera");
            }
            PlayerInput pi = GetComponent<PlayerInput>();
            if (pi != null) pi.enabled = false;
            // 获取Spine2骨骼
            if (_animator == null) TryGetComponent(out _animator);
            _networkAnimator = GetComponent<NetworkAnimator>();

            if (_animator != null)
            {
                _animator.enabled = false; // 先关闭
                _animator.enabled = true;  // 再开启 → 你本地终于有动画了！
                _animator.Rebind();        // 加固重置
                _animator.Play(0, 0);      // 强制播放
            }


            if (_networkAnimator != null && _animator != null)
            {
                _networkAnimator.animator = _animator;
            }

            if (_animator != null)
            {
                _spine2 = _animator.GetBoneTransform(HumanBodyBones.Spine);
                if (_spine2 == null)
                {
                    Debug.LogWarning("未找到Spine2骨骼！请检查角色Avatar是否正确配置");
                }
            }
            player = GetComponent<PlayerCharacter>();
        }

        // 本地玩家相机跟随设置
        public override void OnStartLocalPlayer()
        {
            base.OnStartLocalPlayer();

            PlayerInput pi = GetComponent<PlayerInput>();
            if (pi != null) pi.enabled = true;


            // 仅本地玩家绑定主相机
            if (CinemachineCameraTarget != null)
            {
                Cinemachine.CinemachineVirtualCamera vcam = FindObjectOfType<Cinemachine.CinemachineVirtualCamera>();
                if (vcam != null)
                {
                    vcam.Follow = CinemachineCameraTarget.transform;
                    vcam.LookAt = CinemachineCameraTarget.transform;
                }
            }

            // 仅本地玩家开启小地图相机
            if (cameraMap != null) cameraMap.SetActive(true);

            // 游戏启动时锁定隐藏鼠标
            Cursor.visible = false;
            Cursor.lockState = CursorLockMode.Locked;

            UpdateEnemyOutlines();  //给敌人加描边
        }

        private void OnDestroy()
        {
            Cursor.visible = true;
            Cursor.lockState = CursorLockMode.None;
        }

        private void Start()
        {
            _hasAnimator = TryGetComponent(out _animator);
            _controller = GetComponent<CharacterController>();
            _input = GetComponent<StarterAssetsInputs>();
            AssignAnimationIDs();


            _jumpTimeoutDelta = JumpTimeout;
            _fallTimeoutDelta = FallTimeout;
            _canToggleGun = true;

            // 初始化弯腰角度
            _currentBendAngle = 0f;

            // 初始化射击变量
            if (MainCamera == null)
                MainCamera = Camera.main; // 自动获取主相机
            _fireTimer = 0f;
            _originalTopClamp = TopClamp; // 保存初始值

            // 喝水功能初始化
            _animIDIsDrinking = Animator.StringToHash("IsDrinking");
            if (isLocalPlayer)
            {
                if (DrinkProgressUI == null)
                {
                    GameObject uiObj = GameObject.FindWithTag("DrinkUI");
                    if (uiObj != null)
                    {
                        DrinkProgressUI = uiObj.GetComponent<Image>();
                        DrinkProgressUI.fillAmount = 0;
                        DrinkProgressUI.gameObject.SetActive(false);
                    }
                }
            }

            thirdPersonVCam = FindObjectOfType<Cinemachine.CinemachineVirtualCamera>();

            // 新增：初始化换弹系统（仅本地玩家）
            if (isLocalPlayer)
            {
                // 通过标签找弹药UI Text
                if (ammoTextUI == null)
                {
                    GameObject ammoObj = GameObject.FindGameObjectWithTag("AmmoText");
                    if (ammoObj != null)
                    {
                        ammoTextUI = ammoObj.GetComponent<Text>();
                    }
                }
                // 通过标签ReloadUI找换弹进度条
                if (reloadProgressUI == null)
                {
                    GameObject reloadObj = GameObject.FindGameObjectWithTag("ReloadUI");
                    if (reloadObj != null)
                    {
                        reloadProgressUI = reloadObj.GetComponent<Image>();
                        reloadProgressUI.fillAmount = 0;
                        reloadProgressUI.gameObject.SetActive(false);
                    }
                }
                //初始化弹药显示
                UpdateAmmoUI();
            }

            // 灵敏度设置
            if (isLocalPlayer)
            {
                SetupSensitivitySettings();
            }

            // 默认显示第三人称，隐藏第一人称
            if (isLocalPlayer)
            {
                if (thirdPersonModel != null) thirdPersonModel.SetActive(true);
                if (firstPersonModel != null) firstPersonModel.SetActive(false);
                if (firstPersonModel != null) firstPersonModelGun.SetActive(false);
                if (fpCamera != null) fpCamera.gameObject.SetActive(false);
                if (_mainCamera != null) _mainCamera.SetActive(true);
                if (firstPersonAnimator != null)
                {
                    firstPersonAnimator.SetBool("Holstered", !isHoldingGun);
                }
            }
            else
            {
                if (thirdPersonModel != null) thirdPersonModel.SetActive(true);
                // 远程玩家的第一人称永远隐藏！
                if (firstPersonModel != null) firstPersonModel.SetActive(false);
                if (firstPersonModelGun != null) firstPersonModelGun.SetActive(false);
                if (fpCamera != null) fpCamera.gameObject.SetActive(false);
            }
        }

        //设置面板获
        private void SetupSensitivitySettings()
        {
            // 通过标签找到设置管理器物体
            settingsObj = GameObject.FindGameObjectWithTag("Settings");

            if (settingsObj != null)
            {
                _settingManager = settingsObj.GetComponent<SettingManager>();

                if (_settingManager != null)
                {
                    // 初始化滑动条的范围 (0.1 - 1.1)
                    if (_settingManager.sensitivityXSlider != null)
                    {
                        _settingManager.sensitivityXSlider.minValue = 0.1f;
                        _settingManager.sensitivityXSlider.maxValue = 1.1f;
                        // 初始化当前值
                        _settingManager.sensitivityXSlider.value = sensitivityX;
                        // 监听滑动事件
                        _settingManager.sensitivityXSlider.onValueChanged.AddListener(OnSensitivityXChanged);
                    }

                    if (_settingManager.sensitivityYSlider != null)
                    {
                        _settingManager.sensitivityYSlider.minValue = 0.1f;
                        _settingManager.sensitivityYSlider.maxValue = 1.1f;
                        // 初始化当前值
                        _settingManager.sensitivityYSlider.value = sensitivityY;
                        // 监听滑动事件
                        _settingManager.sensitivityYSlider.onValueChanged.AddListener(OnSensitivityYChanged);
                    }

                }

                settingsObj.SetActive(false);
            }

        }

        // 水平灵敏度变化回调
        private void OnSensitivityXChanged(float value)
        {
            sensitivityX = value;
        }

        // 垂直灵敏度变化回调
        private void OnSensitivityYChanged(float value)
        {
            sensitivityY = value;
        }

        // 更新弹药UI显示
        private void UpdateAmmoUI()
        {
            if (ammoTextUI != null)
            {
                ammoTextUI.text = currentAmmo + "/" + maxAmmo;
            }
        }

        //Update仅本地玩家执行，死亡后禁用输入
        private void Update()
        {
            // 非本地玩家/死亡状态/未初始化完成 不执行逻辑
            if (!isLocalPlayer || player == null || player.isDead) return;

            _hasAnimator = TryGetComponent(out _animator);
            JumpAndGravity();
            GroundedCheck();

            // 喝水逻辑优先级最高
            if (Input.GetKeyDown(DrinkKey) && !_isDrinking && !isHoldingGun)
            {
                StartDrink();
            }

            // 更新喝水进度
            if (_isDrinking)
            {
                UpdateDrinkProgress();

                // 检测打断条件（WASD/R/空格）
                if (Input.GetKey(KeyCode.W) || Input.GetKey(KeyCode.A) ||
                    Input.GetKey(KeyCode.S) || Input.GetKey(KeyCode.D) ||
                    Input.GetKey(KeyCode.R) || Input.GetKey(KeyCode.Space))
                {
                    InterruptDrink();
                }
            }

            // 喝水时跳过移动逻辑
            if (!_isDrinking)
            {
                Move();
            }

            Aim();
            // 每帧更新散布+后坐力
            CalculateCurrentSpread();
            UpdateFpRecoil();
            UpdateReloadProgress();  //更新换弹进度

            if (Input.GetKeyDown(KeyCode.T) && isLocalPlayer && isFirstPerson && isHoldingGun && !_isDrinking && !isInspecting)
            {
                StartInspect();
            }
            if (Input.GetKeyDown(KeyCode.Z) && isLocalPlayer && isFirstPerson && isHoldingGun && !_isDrinking && !isInspecting && !isReloading && currentAmmo < maxAmmo)
            {
                StartReload();
            }

            // 原有换枪逻辑
            if (Input.GetKeyDown(KeyCode.R) && _canToggleGun && !_isDrinking)
            {
                ToggleGun();
                _canToggleGun = false;
                Invoke(nameof(UnlockGunToggle), toggleGunLockTime);
                CanShoot = false;
            }

            // 射速冷却
            if (_fireTimer > 0)
                _fireTimer -= Time.deltaTime;

            // 射击触发：鼠标左键 + 可射击 + 持枪 + 冷却完成 + 非喝水状态
            if (Input.GetMouseButton(0) && !IsRunning && CanShoot && isHoldingGun && _fireTimer <= 0 && !_isDrinking && !isReloading && currentAmmo > 0 && !SettingOpen)
            {
                isInspecting = false;

                if (_input.sprint == true)
                {
                    _input.sprint = false;
                    firstPersonAnimator.SetBool("Running", false);
                    return;
                }

                //计算当前散布值
                CalculateCurrentSpread();
                //累积射击散布
                _currentSpread = Mathf.Min(_currentSpread + SpreadPerShot, MaxSpread);
                //触发第一人称枪口上跳
                ApplyFpRecoil();

                // 消耗弹药
                currentAmmo--;
                UpdateAmmoUI();

                // 计算带散射的射击方向（核心）
                Camera currentCamera = isFirstPerson ? fpCamera : MainCamera;
                if (currentCamera == null) currentCamera = Camera.main;

                // 准星中心射线
                Ray baseRay = currentCamera.ScreenPointToRay(new Vector3(Screen.width / 2-60, Screen.height / 2+60, 0));
                Vector3 shootDirection = baseRay.direction;

                // 第一人称持枪时，应用腰射散射
                if (isFirstPerson && isHoldingGun)
                {
                    // 生成随机散布偏移
                    float randomX = Random.Range(-_currentSpread, _currentSpread);
                    float randomY = Random.Range(-_currentSpread, _currentSpread);

                    // 把角度偏移转成方向向量
                    Quaternion spreadRotation = Quaternion.Euler(randomY, randomX, 0f);
                    shootDirection = spreadRotation * baseRay.direction;
                }

                //获取对应枪口位置
                Vector3 targetMuzzlePos = isFirstPerson ? firstPersonMuzzle.position : thirdPersonMuzzle.position;
                //传给服务端生成子弹
                CmdFire(shootDirection, targetMuzzlePos);
                // 重置射速冷却
                _fireTimer = FireRate;
            }

            if (Input.GetKeyDown(KeyCode.L) && !_isDrinking)  //按L键切换视角
            {
                ToggleFirstPerson();
            }
            if (Input.GetKeyDown(KeyCode.Tab))
            {
                SettingOpen = !SettingOpen;
                settingsObj.SetActive(SettingOpen);

                if (SettingOpen)
                {
                    Cursor.visible = true;
                    Cursor.lockState = CursorLockMode.None;
                    _input.cursorInputForLook = false;
                    _input.LookInput(Vector2.zero);  // 清空残留的鼠标 delta，防止视角继续转动
                }
                else
                {
                    Cursor.visible = false;
                    Cursor.lockState = CursorLockMode.Locked;
                    _input.cursorInputForLook = true;
                }
            }

            // 周期性更新敌人描边
            _outlineUpdateTimer -= Time.deltaTime;
            if (_outlineUpdateTimer <= 0f)
            {
                _outlineUpdateTimer = OUTLINE_UPDATE_INTERVAL;
                UpdateEnemyOutlines();
            }
        }

        // 计算当前实时散布值
        private void CalculateCurrentSpread()
        {
            // 基础散布
            float finalSpread = BaseSpread;

            // 移动状态倍率
            if (_input.sprint)
                finalSpread *= SprintSpreadMultiplier;
            else if (_input.move.sqrMagnitude > _threshold)
                finalSpread *= WalkSpreadMultiplier;

            // 开镜倍率
            if (Input.GetMouseButton(1))
                finalSpread *= AimSpreadMultiplier;

            // 散布自然回落
            _currentSpread = Mathf.Lerp(_currentSpread, finalSpread, Time.deltaTime * SpreadDecaySpeed);
        }

        // 应用单次射击的枪口上跳
        private void ApplyFpRecoil()
        {
            if (!isFirstPerson) return;

            // 计算上跳幅度（连续射击累积）
            float verticalRecoil = FpVerticalRecoil * Mathf.Pow(RecoilRampMultiplier, _shotCount);
            float horizontalRecoil = Random.Range(-FpHorizontalRecoil, FpHorizontalRecoil) * Mathf.Pow(RecoilRampMultiplier, _shotCount);

            // 叠加目标偏移，限制最大上跳
            _targetRecoilOffset.x = Mathf.Clamp(_targetRecoilOffset.x + verticalRecoil, 0, MaxRecoilAngle);
            _targetRecoilOffset.y = Mathf.Clamp(_targetRecoilOffset.y + horizontalRecoil, -MaxRecoilAngle / 2, MaxRecoilAngle / 2);
        }

        // 更新后坐力平滑+回弹
        private void UpdateFpRecoil()
        {
            if (!isFirstPerson)
            {
                // 第三人称时重置后坐力
                _targetRecoilOffset = Vector2.Lerp(_targetRecoilOffset, Vector2.zero, Time.deltaTime * RecoilReturnSpeed * 2f);
                _currentRecoilOffset = Vector2.Lerp(_currentRecoilOffset, _targetRecoilOffset, Time.deltaTime * RecoilSmoothSpeed);
                return;
            }

            // 松开左键时，回弹到0
            if (!Input.GetMouseButton(0))
            {
                _targetRecoilOffset = Vector2.Lerp(_targetRecoilOffset, Vector2.zero, Time.deltaTime * RecoilReturnSpeed);
                _shotCount = 0;
            }

            // 平滑插值当前后坐力到目标值
            _currentRecoilOffset = Vector2.Lerp(_currentRecoilOffset, _targetRecoilOffset, Time.deltaTime * RecoilSmoothSpeed);
        }

        //开始换弹
        private void StartReload()
        {
            isReloading = true;
            currentReloadTime = 0f;

            _shotCount = 0;
            //换弹重置后坐力和散布
            _targetRecoilOffset = Vector2.zero;
            _currentRecoilOffset = Vector2.zero;
            _currentSpread = BaseSpread;

            // 显示换弹进度条
            if (reloadProgressUI != null)
            {
                reloadProgressUI.fillAmount = 0;
                reloadProgressUI.gameObject.SetActive(true);
            }

            // 触发枪的动画控制器的Reload
            if (gunAnimator != null)
            {
                gunAnimator.SetTrigger(_animIDReload);
                gunAnimator.SetBool("Reloading", true);
            }
            // 触发firstPersonAnimator的Reload触发器
            if (firstPersonAnimator != null)
            {
                firstPersonAnimator.SetTrigger(_animIDReload);
                // 你要的 Reloading bool 设为 true
                firstPersonAnimator.SetBool("Reloading", true);
            }

            // 换弹时强制退出瞄准
            if (collimatorUI != null) collimatorUI.SetActive(true);
            if (firstPersonAnimator != null)
            {
                firstPersonAnimator.SetBool(_animIDAim, false);
                firstPersonAnimator.SetFloat(_animIDAiming, 0f);
            }
        }
        // 每帧更新换弹进度
        private void UpdateReloadProgress()
        {
            if (!isReloading) return;

            currentReloadTime += Time.deltaTime;
            float progress = currentReloadTime / reloadDuration;

            // 更新换弹进度条UI
            if (reloadProgressUI != null)
            {
                reloadProgressUI.fillAmount = progress;
            }

            // 换弹完成
            if (progress >= 1f)
            {
                CompleteReload();
            }
        }
        // 换弹完成
        private void CompleteReload()
        {
            isReloading = false;
            // 补满弹药
            currentAmmo = maxAmmo;
            UpdateAmmoUI();

            // 隐藏换弹进度条
            if (reloadProgressUI != null)
            {
                reloadProgressUI.fillAmount = 0;
                reloadProgressUI.gameObject.SetActive(false);
            }

            if (firstPersonAnimator != null)
            {
                firstPersonAnimator.SetBool("Reloading", false);
            }
            if (gunAnimator != null)
            {
                gunAnimator.SetBool("Reloading", false);
            }
        }

        #region 发射子弹，客户端预测和回滚（未完成）

        //服务端射击命令，网络生成子弹
        [Command]
        private void CmdFire(Vector3 shootDirection, Vector3 muzzleWorldPos)
        {
            // 服务端校验空对象
            if (BulletPrefab == null) return;

            // 服务端生成子弹
            GameObject bullet = Instantiate(BulletPrefab, muzzleWorldPos, Quaternion.LookRotation(shootDirection));
            NetworkServer.Spawn(bullet);

            // 设置子弹归属，防止自伤
            Bullet bulletScript = bullet.GetComponent<Bullet>();
            if (bulletScript != null)
            {
                bulletScript.ownerNetIdentity = netIdentity;
                bulletScript.HitEffect = HitEffect;
                bulletScript.BulletLifeTime = BulletLifeTime;
            }

            // 服务端统一给子弹推力（用客户端传的方向，绝对正确）
            if (bullet.TryGetComponent<Rigidbody>(out var rb))
            {
                rb.velocity = Vector3.zero; // 重置速度
                rb.AddForce(shootDirection.normalized * BulletSpeed, ForceMode.VelocityChange);
            }

            // 服务端定时销毁子弹
            Destroy(bullet, BulletLifeTime);
            // 同步枪口特效到所有客户端
            RpcShowMuzzleFlash(muzzleWorldPos);

            _shotCount++;
        }

        // 客户端同步枪口特效
        [ClientRpc]
        private void RpcShowMuzzleFlash(Vector3 muzzleWorldPos)
        {
            if (MuzzleFlash != null )
            {
                var flash = Instantiate(MuzzleFlash, muzzleWorldPos, Quaternion.identity);
                Destroy(flash, 0.1f);
            }
        }

        #endregion

        #region 喝水以及打断逻辑

        // 喝水逻辑
        // 开始喝水,客户端发起请求
        private void StartDrink()
        {
            isInspecting = false;
            isReloading = false;

            _shotCount = 0;
            //重置后坐力和散布
            _targetRecoilOffset = Vector2.zero;
            _currentRecoilOffset = Vector2.zero;
            _currentSpread = BaseSpread;
            if (firstPersonAnimator != null)
            {
                firstPersonAnimator.SetBool("Reloading", false);
            }
            if (gunAnimator != null)
            {
                gunAnimator.SetBool("Reloading", false);
            }
            if (isHoldingGun || _isDrinking) return;
            CmdStartDrink(); // 发给服务器，同步所有人
        }

        // 服务端：允许喝水，同步状态
        [Command]
        private void CmdStartDrink()
        {
            RpcStartDrink(); // 全网播放喝水动画
        }

        // 所有客户端：播放喝水动画
        [ClientRpc]
        private void RpcStartDrink()
        {
            _isDrinking = true;
            _currentDrinkTime = 0f;

            // UI只本地显示（自己看进度条）
            if (isLocalPlayer && DrinkProgressUI != null)
            {
                DrinkProgressUI.fillAmount = 0;
                DrinkProgressUI.gameObject.SetActive(true);
            }

            // 全网同步喝水动画
            if (_animator != null)
            {
                _animator.SetBool(_animIDIsDrinking, true);
                _networkAnimator.SetTrigger(_animIDDrink);
            }

            if (isLocalPlayer && firstPersonAnimator != null)
            {
                firstPersonAnimator.SetTrigger("Drink");
            }
        }

        // 更新喝水进度（仅本地玩家执行）
        private void UpdateDrinkProgress()
        {
            if (!isLocalPlayer || !_isDrinking) return;

            _currentDrinkTime += Time.deltaTime;
            float progress = _currentDrinkTime / DrinkDuration;

            // 本地更新UI
            if (DrinkProgressUI != null)
            {
                DrinkProgressUI.fillAmount = progress;
            }

            // 喝水完成（本地触发，发给服务器）
            if (progress >= 1f)
            {
                CmdCompleteDrink();
            }
        }

        // 服务端：完成喝水，同步停止动画+加血
        [Command]
        private void CmdCompleteDrink()
        {
            RpcCompleteDrink();
            // 服务端加血（全网同步血量）
            if (player != null) player.Heal(30f);
        }

        // 所有客户端：停止喝水动画
        [ClientRpc]
        private void RpcCompleteDrink()
        {
            _isDrinking = false;

            // 本地隐藏UI
            if (isLocalPlayer && DrinkProgressUI != null)
            {
                DrinkProgressUI.fillAmount = 0;
                DrinkProgressUI.gameObject.SetActive(false);
            }

            // 停止动画
            if (_animator != null)
            {
                _animator.SetBool(_animIDIsDrinking, false);
            }
            Debug.Log("喝水完成 + 加血30");
        }

        // 打断喝水（同步）
        private void InterruptDrink()
        {
            CmdInterruptDrink();
        }

        [Command]
        private void CmdInterruptDrink()
        {
            RpcInterruptDrink();
        }

        [ClientRpc]
        private void RpcInterruptDrink()
        {
            _isDrinking = false;
            if (isLocalPlayer && DrinkProgressUI != null)
            {
                DrinkProgressUI.fillAmount = 0;
                DrinkProgressUI.gameObject.SetActive(false);
            }
            if (_animator != null)
            {
                _animator.SetBool(_animIDIsDrinking, false);
            }

            if (isLocalPlayer && firstPersonAnimator != null)
            {
                firstPersonAnimator.SetTrigger("NotDrink");
            }
            Debug.Log("喝水被打断！");
        }

        #endregion

        public void GetOnGun()
        {
            //用于换枪动画和换弹动画结束时的回调
            CanShoot = true;
        }

        // LateUpdate仅本地玩家执行相机/后坐力逻辑
        private void LateUpdate()
        {
            if (!isLocalPlayer) return;

            if (isFirstPerson)
            {
                UpdateFPSCamera(); // 第一人称：FPS鼠标控制
            }
            else
            {
                CameraRotation(); // 第三人称
                UpdateRecoil();
            }
            // 执行弯腰逻辑（LateUpdate确保跟随相机）
            UpdateAimBend();

            UpdateFirstPersonAnim();

            if (firstPersonAnimator != null)
            {
                firstPersonAnimator.SetBool(_animIDInspecting, isInspecting);
            }
        }

        // FPS相机控制
        //X轴俯仰
        private void UpdateFPSCamera()
        {
            if (_input == null || fpCameraRoot == null) return;

            // 鼠标输入
            float mouseX = _input.look.x * fpMouseSensitivity * Time.deltaTime* sensitivityX;    //可以调整灵敏度
            float mouseY = _input.look.y * fpMouseSensitivity * Time.deltaTime*sensitivityY;

            // 基础视角旋转
            fpYaw += mouseX;
            fpPitch = Mathf.Clamp(fpPitch + mouseY, -40f, 60f);

            // 叠加枪口上跳偏移
            float finalPitch = fpPitch - _currentRecoilOffset.x;
            float finalYaw = fpYaw + _currentRecoilOffset.y;

            // 应用最终旋转节点
            transform.rotation = Quaternion.Euler(0f, finalYaw, 0f);
            fpCameraRoot.localEulerAngles = new Vector3(finalPitch, 0f, 0f);

            // 确保第一人称相机方向 = 人物前方向
            if (fpCamera != null)
            {
                fpCamera.transform.forward = fpCameraRoot.forward;
            }
        }

        // 弯腰核心方法
        private void UpdateAimBend()
        {
            if (_spine2 == null || _input == null || _isDrinking) return; // 喝水时禁用弯腰

            if (isHoldingGun && _input.move.sqrMagnitude > _threshold)
            {
                // 计算Spine2的弯腰角度
                float mouseYInput = _input.look.y * AimSensitivity;
                float targetBendAngle = Mathf.Clamp(_currentBendAngle + mouseYInput, MinBendAngle, MaxBendAngle);
                _currentBendAngle = Mathf.SmoothDamp(_currentBendAngle, targetBendAngle, ref _bendVelocity, BendSmoothTime);

                // 角色Spine2旋转
                _spine2.localRotation = Quaternion.Euler(
                    _spine2.localEulerAngles.x,
                    _spine2.localEulerAngles.y,
                    _currentBendAngle
                );

                // 枪绕Spine2的世界Z轴旋转
                if (GunTransform != null)
                {
                    Vector3 spineWorldZAxis = _spine2.TransformDirection(Vector3.forward);
                    Quaternion gunInitialRot = GunTransform.rotation;
                    Quaternion rotateAroundSpine = Quaternion.AngleAxis(_currentBendAngle, spineWorldZAxis);
                    GunTransform.rotation = rotateAroundSpine * gunInitialRot;
                }
            }
        }


        private void AssignAnimationIDs()
        {
            _animIDSpeed = Animator.StringToHash("Speed");
            _animIDGrounded = Animator.StringToHash("Grounded");
            _animIDJump = Animator.StringToHash("Jump");
            _animIDFreeFall = Animator.StringToHash("FreeFall");
            _animIDMotionSpeed = Animator.StringToHash("MotionSpeed");
            _animIDMoveLeft = Animator.StringToHash("MoveLeft");
            _animIDMoveRight = Animator.StringToHash("MoveRight");
            _animIDMoveForward = Animator.StringToHash("MoveForward");
            _animIDMoveBack = Animator.StringToHash("MoveBack");
            _animIDIsHoldingGun = Animator.StringToHash("IsHoldingGun");
            _animIDToggleGun = Animator.StringToHash("ToggleGun");
            _animIDAim = Animator.StringToHash("Aim");
            _animIDAiming = Animator.StringToHash("Aiming");
            _animIDInspect = Animator.StringToHash("Inspect");
            _animIDInspecting = Animator.StringToHash("inspecting");
            _animIDReload = Animator.StringToHash("Reload");
        }

        // 每帧更新后坐力（LateUpdate 调用）
        private void UpdateRecoil()
        {
            bool isShooting = Input.GetMouseButton(0) && CanShoot && isHoldingGun && !_isDrinking;

            if (isShooting)
            {
                // 只有 >= 第3发才开始慢慢上跳
                if (_shotCount >= RecoilStartShot)
                {
                    _recoilPitch = Mathf.SmoothDamp(
                        _recoilPitch,
                        RecoilAmount,
                        ref _recoilVelocity,
                        RecoilSmoothTime + RecoilRampSpeed
                    );
                }
            }
            else
            {
                // 松手：重置计数 + 平滑回落
                _shotCount = 0;
                _recoilPitch = Mathf.SmoothDamp(_recoilPitch, 0f, ref _recoilVelocity, RecoilSmoothTime);
            }
        }


        // 换枪逻辑
        private void ToggleGun()
        {
            isInspecting = false;
            if (!_hasAnimator) return;
            CmdToggleGun();

            Debug.Log(isHoldingGun ? "拿起枪" : "卸下枪");

        }
        // 服务端命令：仅修改同步变量
        [Command]
        private void CmdToggleGun()
        {
            // 只有服务器能改 SyncVar！
            isHoldingGun = !isHoldingGun;

            RpcPlayToggleGunAnim();
        }

        // 客户端：所有玩家都播放换枪动画
        [ClientRpc]
        private void RpcPlayToggleGunAnim()
        {
            if (_hasAnimator) _networkAnimator.SetTrigger(_animIDToggleGun);
        }

        void OnHoldGunStateChanged(bool oldValue, bool newValue)
        {
            if (_hasAnimator)
            {
                _animator.SetBool(_animIDIsHoldingGun, newValue);
            }


            // 相机逻辑,本地 + 远程都生效
            if (newValue)
            {
                TopClamp = 20f;
                Debug.Log("持枪状态，TopClamp已改为20");
            }
            else
            {
                TopClamp = _originalTopClamp;
                Debug.Log("卸枪状态，TopClamp恢复为" + _originalTopClamp);
            }

            if (isLocalPlayer && firstPersonModelGun != null)
            {
                firstPersonModelGun.SetActive(isFirstPerson && newValue);
            }

            CanShoot = newValue;
            _fireTimer = 0;  //重置射击冷却
        }

        // 解锁换枪
        private void UnlockGunToggle()
        {
            _canToggleGun = true;
            Debug.Log("可以再次换枪了");
        }

        // 地面检测
        private void GroundedCheck()
        {
            Vector3 spherePosition = new Vector3(transform.position.x, transform.position.y - GroundedOffset, transform.position.z);
            Grounded = Physics.CheckSphere(spherePosition, GroundedRadius, GroundLayers, QueryTriggerInteraction.Ignore);
            if (_hasAnimator)
            {
                _animator.SetBool(_animIDGrounded, Grounded);
            }
        }

        // 相机旋转
        private void CameraRotation()
        {
            if (_input.look.sqrMagnitude >= _threshold && !LockCameraPosition)
            {
                _cinemachineTargetYaw += _input.look.x * Time.deltaTime;
                _cinemachineTargetPitch += _input.look.y * Time.deltaTime;
            }

            _cinemachineTargetYaw = ClampAngle(_cinemachineTargetYaw, float.MinValue, float.MaxValue);
            _cinemachineTargetPitch = ClampAngle(_cinemachineTargetPitch, BottomClamp, TopClamp);

            float finalPitch = _cinemachineTargetPitch + _recoilPitch;

            CinemachineCameraTarget.transform.rotation = Quaternion.Euler(
                finalPitch + CameraAngleOverride,
                _cinemachineTargetYaw,
                0.0f
            );
        }

        private void Move()
        {
            if (!isLocalPlayer) return;
            float targetSpeed = _input.sprint ? SprintSpeed : MoveSpeed;
            if (_input.move == Vector2.zero) targetSpeed = 0.0f;
            float currentHorizontalSpeed = new Vector3(_controller.velocity.x, 0.0f, _controller.velocity.z).magnitude;
            float speedOffset = 0.1f;
            float inputMagnitude = _input.analogMovement ? _input.move.magnitude : 1f;

            if (currentHorizontalSpeed < targetSpeed - speedOffset || currentHorizontalSpeed > targetSpeed + speedOffset)
            {
                _speed = Mathf.Lerp(currentHorizontalSpeed, targetSpeed * inputMagnitude, Time.deltaTime * SpeedChangeRate);
                _speed = Mathf.Round(_speed * 1000f) / 1000f;
            }
            else
            {
                _speed = targetSpeed;
            }
            _animationBlend = Mathf.Lerp(_animationBlend, targetSpeed, Time.deltaTime * SpeedChangeRate);

            float moveX = _input.move.x;
            float moveY = _input.move.y;

            Vector3 cameraForward;
            Vector3 cameraRight;
            if (isFirstPerson)
            {
                //鼠标看哪，哪就是前
                cameraForward = transform.forward;
                cameraRight = transform.right;
            }
            else
            {
                // 第三人称原有逻辑
                cameraForward = _mainCamera.transform.forward;
                cameraRight = _mainCamera.transform.right;
            }
            cameraForward.y = 0;
            cameraRight.y = 0;
            cameraForward.Normalize();
            cameraRight.Normalize();

            if (!isHoldingGun)
            {
                //第一人称无枪 正常鼠标转向
                if (isFirstPerson)
                {
                    Vector3 moveDirection = cameraRight * moveX + cameraForward * moveY;
                    _controller.Move(moveDirection.normalized * (_speed * Time.deltaTime) + new Vector3(0.0f, _verticalVelocity, 0.0f) * Time.deltaTime);
                }
                // 第三人称无枪逻辑不变
                else
                {
                    Vector3 inputDirection = new Vector3(_input.move.x, 0.0f, _input.move.y).normalized;
                    if (_input.move != Vector2.zero)
                    {
                        _targetRotation = Mathf.Atan2(inputDirection.x, inputDirection.z) * Mathf.Rad2Deg + _mainCamera.transform.eulerAngles.y;
                        float rotation = Mathf.SmoothDampAngle(transform.eulerAngles.y, _targetRotation, ref _rotationVelocity, RotationSmoothTime);
                        transform.rotation = Quaternion.Euler(0.0f, rotation, 0.0f);
                    }
                    Vector3 targetDirection = Quaternion.Euler(0.0f, _targetRotation, 0.0f) * Vector3.forward;
                    _controller.Move(targetDirection.normalized * (_speed * Time.deltaTime) + new Vector3(0.0f, _verticalVelocity, 0.0f) * Time.deltaTime);
                }
            }
            else
            {
                Vector3 moveDirection = cameraRight * moveX + cameraForward * moveY;

                // 第一人称不旋转角色，只保持朝向；第三人称正常旋转
                if (!isFirstPerson)
                {
                    _targetRotation = _mainCamera.transform.eulerAngles.y;
                    float rotation = Mathf.SmoothDampAngle(transform.eulerAngles.y, _targetRotation, ref _rotationVelocity, RotationSmoothTime);
                    transform.rotation = Quaternion.Euler(0.0f, rotation, 0.0f);
                }

                _controller.Move(moveDirection.normalized * (_speed * Time.deltaTime) + new Vector3(0.0f, _verticalVelocity, 0.0f) * Time.deltaTime);
            }

            // 动画逻辑
            if (_hasAnimator)
            {
                _animator.SetBool(_animIDMoveLeft, false);
                _animator.SetBool(_animIDMoveRight, false);
                _animator.SetBool(_animIDMoveForward, false);
                _animator.SetBool(_animIDMoveBack, false);

                if (moveX < -_threshold)
                {
                    _animator.SetBool(_animIDMoveLeft, true);
                }
                else if (moveX > _threshold)
                {
                    _animator.SetBool(_animIDMoveRight, true);
                }
                else if (moveY > _threshold && Mathf.Abs(moveX) < _threshold)
                {
                    _animator.SetBool(_animIDMoveForward, true);
                }
                else if (moveY < -_threshold && Mathf.Abs(moveX) < _threshold)
                {
                    _animator.SetBool(_animIDMoveBack, true);
                }

                _animator.SetFloat(_animIDSpeed, _animationBlend);
                _animator.SetFloat(_animIDMotionSpeed, inputMagnitude);
            }
        }


        // 跳跃和重力
        private void JumpAndGravity()
        {
            if (Grounded)
            {
                _fallTimeoutDelta = FallTimeout;
                if (_hasAnimator)
                {
                    _animator.SetBool(_animIDJump, false);
                    _animator.SetBool(_animIDFreeFall, false);
                }
                if (_verticalVelocity < 0.0f)
                {
                    _verticalVelocity = -2f;
                }
                if (_input.jump && _jumpTimeoutDelta <= 0.0f && !_isDrinking)
                {
                    _verticalVelocity = Mathf.Sqrt(JumpHeight * -2f * Gravity);
                    if (_hasAnimator)
                    {
                        _animator.SetBool(_animIDJump, true);
                    }
                }
                if (_jumpTimeoutDelta >= 0.0f)
                {
                    _jumpTimeoutDelta -= Time.deltaTime;
                }
            }
            else
            {
                _jumpTimeoutDelta = JumpTimeout;
                if (_fallTimeoutDelta >= 0.0f)
                {
                    _fallTimeoutDelta -= Time.deltaTime;
                }
                else
                {
                    if (_hasAnimator)
                    {
                        _animator.SetBool(_animIDFreeFall, true);
                    }
                }
                _input.jump = false;
            }
            if (_verticalVelocity < _terminalVelocity)
            {
                _verticalVelocity += Gravity * Time.deltaTime;
            }
        }

        // 角度限制
        private static float ClampAngle(float lfAngle, float lfMin, float lfMax)
        {
            if (lfAngle < -360f) lfAngle += 360f;
            if (lfAngle > 360f) lfAngle -= 360f;
            return Mathf.Clamp(lfAngle, lfMin, lfMax);
        }

        private void OnDrawGizmosSelected()
        {
            Color transparentGreen = new Color(0.0f, 1.0f, 0.0f, 0.35f);
            Color transparentRed = new Color(1.0f, 0.0f, 0.0f, 0.35f);
            if (Grounded) Gizmos.color = transparentGreen;
            else Gizmos.color = transparentRed;
            Gizmos.DrawSphere(new Vector3(transform.position.x, transform.position.y - GroundedOffset, transform.position.z), GroundedRadius);
        }

        //切换人称视角
        private void ToggleFirstPerson()
        {
            isInspecting = false;
            if (!isLocalPlayer) return; // 仅本地玩家可切换
            _shotCount = 0;
            //重置后坐力和散布
            _targetRecoilOffset = Vector2.zero;
            _currentRecoilOffset = Vector2.zero;
            _currentSpread = BaseSpread;

            isFirstPerson = !isFirstPerson;

            // 本地模型切换
            if (thirdPersonModel != null)
                thirdPersonModel.SetActive(!isFirstPerson);
            if (firstPersonModel != null)
            {
                firstPersonModel.SetActive(isFirstPerson);
                firstPersonModelGun.SetActive(isFirstPerson && isHoldingGun);
            }

            // 相机切换
            if (thirdPersonVCam != null)
                thirdPersonVCam.gameObject.SetActive(!isFirstPerson);
            if (_mainCamera != null)
                _mainCamera.SetActive(!isFirstPerson); // 禁用场景主相机
            if (fpCamera != null)
                fpCamera.gameObject.SetActive(isFirstPerson);

            // 切换时重置相机角度，防止跳变
            if (isFirstPerson)
            {
                fpYaw = transform.eulerAngles.y;
                fpPitch = 0;
                fpCameraRoot.localRotation = Quaternion.Euler(0f, 0f, 0f);
            }
            else
            {
                // 重置角色朝向
                _targetRotation = _mainCamera.transform.eulerAngles.y;
                transform.rotation = Quaternion.Euler(0, _targetRotation, 0);

                // 如果是持枪状态，全网同步触发 ChangeGun 动画
                if (isHoldingGun)
                {
                    CmdTriggerChangeGun();
                }
            }

            ResetAnimatorAndNetwork();

            CanShoot = isHoldingGun;
            Debug.Log("切换至：" + (isFirstPerson ? "第一人称" : "第三人称"));
        }

        // 服务端命令触发ChangeGun并同步给所有玩家
        [Command]
        private void CmdTriggerChangeGun()
        {
            RpcTriggerChangeGun();
        }

        // 所有客户端播放ChangeGun动画
        [ClientRpc]
        private void RpcTriggerChangeGun()
        {
            if (_hasAnimator)
            {
                _networkAnimator.SetTrigger("ChangeGun");
            }
        }

        private void UpdateFirstPersonAnim()   //第一人称动画同步
        {
            if (!isLocalPlayer || firstPersonAnimator == null) return;

            //移动速度
            firstPersonAnimator.SetFloat("Movement", _animationBlend);

            //冲刺
            firstPersonAnimator.SetBool("Running", _input.sprint);

            // 持枪状态
            firstPersonAnimator.SetBool("Holstered", !isHoldingGun);
        }

        private void ResetAnimatorAndNetwork()
        {
            if (_animator != null)
            {
                _animator.enabled = false; // 先关闭
                _animator.enabled = true;  // 再开启
                _animator.Rebind();        // 加固重置
                _animator.Play(0, 0);      // 强制播放
            }

            if (_networkAnimator != null && _animator != null)
            {
                _networkAnimator.animator = _animator; // 重新赋值
            }
        }

        // 右键瞄准动画
        private void Aim()
        {
            // 限制条件：有动画组件、第一人称、持枪、非喝水状态 才能瞄准
            if (!firstPersonAnimator || !isFirstPerson || !isHoldingGun || _isDrinking) return;
            Debug.Log("瞄准状态：" + Input.GetMouseButton(1));
            // 鼠标右键按住进入瞄准
            if (Input.GetMouseButton(1))
            {
                firstPersonAnimator.SetBool(_animIDAim, true);
                float currentAimValue = firstPersonAnimator.GetFloat(_animIDAiming);
                // 平滑过渡到瞄准状态（Time.deltaTime保证不同帧率下速度一致）
                firstPersonAnimator.SetFloat(_animIDAiming, Mathf.Lerp(currentAimValue, 1f, Time.deltaTime * 10f));
                if (collimatorUI != null) collimatorUI.SetActive(false);
            }
            else
            {
                firstPersonAnimator.SetBool(_animIDAim, false);
                float currentAimValue = firstPersonAnimator.GetFloat(_animIDAiming);
                // 平滑过渡到非瞄准状态
                firstPersonAnimator.SetFloat(_animIDAiming, Mathf.Lerp(currentAimValue, 0f, Time.deltaTime * 10f));
                if (collimatorUI != null) collimatorUI.SetActive(true);   //显示准星
            }
        }

        private void StartInspect()
        {
            isInspecting = true;
            isReloading = false;
            // 触发检视动画

            _shotCount = 0;
            //重置后坐力和散布
            _targetRecoilOffset = Vector2.zero;
            _currentRecoilOffset = Vector2.zero;
            _currentSpread = BaseSpread;


            firstPersonAnimator.SetTrigger(_animIDInspect);

            // 检视时强制退出瞄准
            if (collimatorUI != null) collimatorUI.SetActive(true);
            if (_hasAnimator)
            {
                firstPersonAnimator.SetBool(_animIDAim, false);
                firstPersonAnimator.SetFloat(_animIDAiming, 0f);
                firstPersonAnimator.SetBool("Reloading", false);
            }
            if (gunAnimator != null)
            {
                gunAnimator.SetBool("Reloading", false);
            }
            if (reloadProgressUI != null)
            {
                reloadProgressUI.fillAmount = 0;
                reloadProgressUI.gameObject.SetActive(false);
            }
        }

        // 更新所有敌人的描边状态
        private void UpdateEnemyOutlines()
        {
            if (!isLocalPlayer) return;

            // 处理玩家角色
            ThirdPersonController[] allPlayers = FindObjectsOfType<ThirdPersonController>();
            foreach (ThirdPersonController player in allPlayers)
            {
                if (player == this) continue;
                CharacterOutline outline = player.GetComponent<CharacterOutline>();
                if (outline == null) continue;
                outline.ToggleOutline(player.teamId != this.teamId);
            }

            // 处理 Bot
            BotController[] allBots = FindObjectsOfType<BotController>();
            foreach (BotController bot in allBots)
            {
                CharacterOutline outline = bot.GetComponent<CharacterOutline>();
                if (outline == null) continue;
                outline.ToggleOutline(bot.teamId != this.teamId);
            }
        }


        //动画回调函数
        public void OnInspectComplete()
        {
            isInspecting = false;
        }

        void OnGUI()
        {
            if (Camera.main == null) return;

            Vector3 screenPos = Camera.main.WorldToScreenPoint(transform.position);
            if (screenPos.z < 0) return;

            screenPos.y = Screen.height - screenPos.y;

            bool isLocal = isLocalPlayer;
            string teamName = teamId == 0 ? "红队" : "蓝队";
            string text = $"{(isLocal ? "我" : "")} T:{teamId}({teamName})";
            GUI.Label(new Rect(screenPos.x - 40, screenPos.y - 20, 200, 20), text);
        }
    }
}