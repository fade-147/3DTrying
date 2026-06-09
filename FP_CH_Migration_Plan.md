# Player2View 重构 + 新版 P_LPSP_FP_CH 集成方案

> 源: FPSTrying (新版 Low Poly Shooter Pack) → 目标: 3Dgame (联网FPS)
> 状态: 规划完成，待确认后执行

---

## 一、现状诊断

### 1.1 ThirdPersonController 职责清单（20项，1550行，1个类）

| # | 职责 | 类别 | # | 职责 | 类别 |
|---|------|------|---|------|------|
| 1 | 移动控制(WASD) | 共享 | 11 | 三人称后坐力 | 3P |
| 2 | 跳跃/重力 | 共享 | 12 | 散布计算 | 1P |
| 3 | 地面检测 | 共享 | 13 | 弹药管理 | 共享 |
| 4 | 三人称相机(Cinemachine) | 3P | 14 | 换弹系统 | 共享 |
| 5 | 一人称相机(FPS旋转) | 1P | 15 | 喝水系统+网络同步 | 共享 |
| 6 | 一三视角切换(L键) | 共享 | 16 | 瞄准ADS | 1P |
| 7 | 模型显隐管理 | 共享 | 17 | Spine弯腰瞄准 | 1P |
| 8 | 换枪(R键)+网络同步 | 共享 | 18 | 检视枪(T键) | 1P |
| 9 | 射击+网络生成子弹 | 共享 | 19 | 动画参数同步 | 共享 |
| 10 | 一人称后坐力 | 1P | 20 | 敌人描边/UI/灵敏度设置 | 共享 |

### 1.2 核心问题

```
当前: 一个 God Class 用 if/else 硬编码一三人称
ThirdPersonController : NetworkBehaviour
  ├── if (isFirstPerson) { 走FPS路径 } else { 走TPS路径 }
  ├── if (isHoldingGun)    { 射击逻辑 }
  └── 所有网络的[Command]/[ClientRpc]/[SyncVar]全混在一起

后果:
  - 一三人称无法独立测试、独立修改
  - 加新功能=改1550行巨类
  - 新版LPSP的模块化系统无法直接嵌入
```

---

## 二、目标架构

### 2.1 设计原则

1. **一三分离**: 1P和3P是互斥子模块，`PlayerViewManager` 一键切换
2. **功能拆分**: 每个脚本只做一件事
3. **状态集中**: `PlayerState` 统一管理 [SyncVar]
4. **网络集中**: `PlayerNetwork` 统一管理 [Command]/[ClientRpc]
5. **LPSP即插即用**: Motion/Camera/IK 作为独立组件

### 2.2 新 Prefab 结构

```
Player2View (Root, Layer 8, Tag "Player")
│
│  ═══════════ 共享组件 (始终激活) ═══════════
│  ├── CharacterController, CapsuleCollider            [Unity]
│  ├── NetworkIdentity, NetworkTransform, NetworkAnimator [Mirror]
│  ├── PlayerInput, StarterAssetsInputs                [Input]
│  ├── BasicRigidBodyPush, CharacterOutline            [现有]
│  │
│  ├── PlayerState : NetworkBehaviour         ← [SyncVar] 容器
│  ├── PlayerNetwork : NetworkBehaviour       ← [Command]/[Rpc] 集中
│  ├── PlayerMovement : MonoBehaviour         ← 移动+跳跃+重力
│  ├── PlayerViewManager : MonoBehaviour      ← 一三切换
│  ├── PlayerCombat : NetworkBehaviour        ← 射击+弹药+换弹
│  ├── PlayerActions : NetworkBehaviour       ← 喝水+检视+换枪
│  ├── PlayerAnimation : MonoBehaviour        ← 动画参数更新
│  └── PlayerSettings : MonoBehaviour         ← 灵敏度设置
│
│  ═══════════ 第三人称模块 (3P激活) ═══════════
├── ThirdPersonModule
│   ├── Animator (StarterAssetsThirdPerson.controller)
│   ├── Geometry (3P模型+SkinnedMeshRenderer)
│   ├── CinemachineCameraTarget
│   └── M4_8 (3P枪模型)
│
│  ═══════════ 第一人称模块 (1P激活) - 集成新版LPSP ═══════════
├── FirstPersonModule
│   │
│   ├── FP_CharacterRoot
│   │   ├── Animator (AC_LPSP_PCH.controller)          ← [新] 动画
│   │   ├── CameraLook                                  ← [新] ★替代 UpdateFPSCamera
│   │   ├── CameraHeight                                ← [新] 蹲伏相机
│   │   └── CharacterAnimationEventHandler              ← [新] 动画事件
│   │
│   ├── FP_Motion_Body (身体运动层)
│   │   ├── MotionApplier (Override模式)                ← [新]
│   │   ├── SwayMotion (Camera)                         ← [新]
│   │   ├── LeaningMotion (Camera)                      ← [新] ★替代 UpdateAimBend
│   │   ├── JumpMotion                                  ← [新]
│   │   └── LandMotion                                  ← [新]
│   │
│   ├── FP_Skeleton (新版骨架, 68骨骼)
│   │   ├── ik_hand_gun
│   │   │   └── MotionApplier (Add模式, 武器层)         ← [新]
│   │   │       ├── SwayMotion (Item)                   ← [新]
│   │   │       ├── RecoilMotion (Item)                 ← [新] ★替代旧后坐力
│   │   │       ├── OffsetMotion                        ← [新]
│   │   │       ├── LoweredMotion                       ← [新]
│   │   │       ├── LeaningMotion (Item)                ← [新]
│   │   │       ├── JumpMotion (Item)                   ← [新]
│   │   │       └── LandMotion (Item)                   ← [新]
│   │   │
│   │   └── SOCKET_Camera
│   │       ├── FP_Camera (MainCamera, FOV=112.6)       ← [新] 双相机
│   │       │   ├── AudioListener
│   │       │   └── FP_WeaponCamera (Depth=1, 仅武器层)← [新] 防穿墙
│   │       └── PostProcessLayer
│   │
│   ├── FP_Mesh (SkinnedMeshRenderer, 新版手部模型)    ← [新]
│   ├── FootstepPlayer                                  ← [新]
│   ├── CharacterKinematics (IK)                        ← [新]
│   ├── WallAvoidance                                   ← [新]
│   ├── FeelManager (SO_FP_Default)                     ← [新] 手感管理
│   ├── CrouchingInput, LeaningInput                    ← [新]
│   ├── LowerWeapon, LaserToggleInput                   ← [新]
│   │
│   └── FP_Weapons
│       └── P_LPSP_WEP_AR_01 (现有武器)
│
│  ═══════════ 其他 ═══════════
├── CameraMap (小地图)
└── Canvas (准星UI)
```

### 2.3 重构后脚本职责一览

| 新脚本 | 基类 | 职责 | 替换旧代码 |
|--------|------|------|-----------|
| **PlayerState** | NetworkBehaviour | [SyncVar]集中容器 | ThirdPersonController中的SyncVar |
| **PlayerNetwork** | NetworkBehaviour | [Command]/[Rpc]集中 | ThirdPersonController中的Cmd/Rpc |
| **PlayerMovement** | MonoBehaviour | 移动+跳跃+重力+地面检测 | Move()+JumpAndGravity()+GroundedCheck() |
| **PlayerViewManager** | MonoBehaviour | 一三切换+模型显隐 | ToggleFirstPerson()+ApplyPersonView() |
| **PlayerCombat** | NetworkBehaviour | 射击+弹药+换弹+散布 | 射击/弹药/换弹所有代码 |
| **PlayerActions** | NetworkBehaviour | 喝水+检视+换枪 | 喝水/检视/换枪代码 |
| **PlayerAnimation** | MonoBehaviour | 动画参数更新 | UpdateFirstPersonAnim()+AssignAnimationIDs() |
| **PlayerSettings** | MonoBehaviour | 灵敏度设置面板 | SetupSensitivitySettings() |
| **FPCharacterAdapter** | CharacterBehaviour | 桥接LPSP Motion系统 | 无(新增) |
| **FPMovementAdapter** | MovementBehaviour | 桥接LPSP Movement接口 | 无(新增) |

---

## 三、新旧 LPSP 脚本迁移

### 3.1 直接可用（不改代码直接挂载）

Motion系统: `MotionApplier`, `SwayMotion`, `RecoilMotion`, `LeaningMotion`, `JumpMotion`, `LandMotion`, `OffsetMotion`, `LoweredMotion`, `FeelManager`
相机系统: `CameraLook`, `CameraHeight`
辅助: `CharacterKinematics`, `FootstepPlayer`, `WallAvoidance`, `CharacterAnimationEventHandler`
输入: `CrouchingInput`, `LeaningInput`, `LowerWeapon`, `LaserToggleInput`

### 3.2 不能直接用的

| 脚本 | 原因 | 方案 |
|------|------|------|
| `Character.cs` | 密封类,非NetworkBehaviour,依赖ServiceLocator | **不用**，功能拆到PlayerCombat/PlayerActions |
| `Movement.cs` | 自带CharacterController,非NetworkBehaviour | **不用**，用PlayerMovement |
| `Weapon.cs` | 本地射击,无网络 | Phase 4可选 |

### 3.3 关键适配器

因为 LPSP 的 Motion 系统通过 `CharacterBehaviour`(35个抽象成员) 和 `MovementBehaviour`(8个抽象成员) 读取角色状态, 而我们的新架构用 PlayerState/PlayerMovement 存储状态。需要两个适配器桥接:

```
FPCharacterAdapter : CharacterBehaviour
  → 桥接 PlayerState + PlayerMovement + PlayerCombat + PlayerViewManager
  → 实现 IsRunning, IsCrouching, IsAiming, IsReloading, GetCameraWorld() 等35个方法

FPMovementAdapter : MovementBehaviour  
  → 桥接 PlayerMovement
  → 实现 IsGrounded, IsJumping, GetVelocity() 等8个方法
```

---

## 四、逐步执行计划

### Phase 0: 准备 [1-2h]

```
□ 0.1 Git commit 备份当前项目
□ 0.2 在 3Dgame 创建目录结构:
    Assets/Infima Games/Low Poly Shooter Pack/
      Code/{Motion,Camera,Animation,Character,Scriptable,Utilities,Services}/
      Animators/Character/
      Data/
      Art/{Animations/Character/,Meshes/Character/,Materials/Character/FP/}
□ 0.3 从 FPSTrying 复制所有脚本到对应位置
□ 0.4 复制动画FBX、模型FBX、材质、贴图、Data资产
□ 0.5 确认项目能打开
```

### Phase 1: 编译通过 [2-3h]

```
□ 1.1 处理命名空间 InfimaGames.LowPolyShooterPack
□ 1.2 确认依赖包: TextMeshPro, Input System 1.14.2, PostProcessing
□ 1.3 创建 FPCharacterAdapter : CharacterBehaviour (桥接35个抽象方法)
□ 1.4 创建 FPMovementAdapter : MovementBehaviour (桥接8个抽象方法)
□ 1.5 确保全部.cs编译通过
```

### Phase 2: 新脚本 [3-4h]

```
按依赖顺序:
□ 2.1 PlayerState.cs      -- [SyncVar] 纯容器
□ 2.2 PlayerNetwork.cs    -- [Command]/[Rpc] 集中
□ 2.3 PlayerMovement.cs   -- 从旧代码抽取移动/跳跃/重力
□ 2.4 PlayerViewManager.cs -- 从旧代码抽取一三切换
□ 2.5 PlayerCombat.cs     -- 从旧代码抽取射击/弹药/换弹
□ 2.6 PlayerActions.cs    -- 从旧代码抽取喝水/检视/换枪
□ 2.7 PlayerAnimation.cs  -- 从旧代码抽取动画参数
□ 2.8 PlayerSettings.cs   -- 从旧代码抽取灵敏度设置
```

### Phase 3: 重建预制体 [4-6h]

```
□ 3.1 创建 ThirdPersonModule (迁移现有3P内容)
□ 3.2 创建 FirstPersonModule (搭建新版LPSP结构)
    - FP_CharacterRoot + Animator + CameraLook
    - FP_Motion_Body + MotionApplier(身体层)
    - FP_Skeleton + IK + 双相机
    - ik_hand_gun + MotionApplier(武器层)
    - 辅助组件: IK/Footstep/WallAvoidance/FeelManager
□ 3.3 更新 Player2View 根组件
    - 挂载全部新脚本
    - Inspector连线 (引用+事件订阅)
    - 旧 ThirdPersonController 保留但Disable
□ 3.4 配置 Motion 数据 (FeelPreset, 曲线, ScriptableObjects)
```

### Phase 4: 测试 [3-4h]

```
□ 4.1 基础: 编译+运行+玩家生成+移动+视角
□ 4.2 一三切换: L键切换, 模型/相机正确显隐
□ 4.3 射击: 子弹+散布+后坐力+弹药UI+换弹
□ 4.4 网络: 双客户端测试移动/射击/换枪/喝水/死亡同步
□ 4.5 动画: 1P/3P动画+IK+动画事件
□ 4.6 Motion: Sway/Recoil/Leaning/Jump/Land/Lower/Offset
```

### Phase 5: 清理 [1-2h]

```
□ 5.1 删除 ThirdPersonController.cs
□ 5.2 删除旧 P_LPSP_FP_CH.prefab
□ 5.3 删除 ChangeAnimator.cs
□ 5.4 更新 BotController 等引用
□ 5.5 回归测试
```

---

## 五、关键数据流

### 输入流
```
PlayerInput → StarterAssetsInputs → PlayerMovement (移动)
                                  → CameraLook (1P视角)
                                  → PlayerActions (换枪/喝水/检视)
                                  → PlayerCombat (射击)
```

### 射击流
```
PlayerCombat.TryFire()
  → 散布计算 → 射线方向
  → PlayerNetwork.CmdFire() [Server]
    → Bullet (NetworkServer.Spawn)
    → RpcShowMuzzleFlash() [All Clients]
  → OnFire事件 → RecoilMotion.Tick() → 后坐力表现
```

### 一三切换流
```
L键 → PlayerViewManager.ToggleFirstPerson()
  → PlayerState.isFirstPerson 翻转
  → ThirdPersonModule.SetActive(!1P)
  → FirstPersonModule.SetActive(1P)
```

---

## 六、风险

| 风险 | 等级 | 缓解 |
|------|------|------|
| 网络消息时序 (State+Network分离) | 高 | 测试确认SyncVar和Cmd在同一帧内 |
| CharacterBehaviour 35方法适配遗漏 | 中 | 用throw NotImplementedException标记 |
| 新旧Avatar骨骼不兼容 | 中 | 确认FBX骨骼结构一致 |
| BotController依赖ThirdPersonController | 高 | Phase 2同步更新Bot引用 |
| URP双相机兼容 | 中 | 测试确认Camera Stack |

---

## 七、文件变更汇总

**新增 (~50个文件):**
- 8个新Player脚本 (Assets/Scripts/Player/)
- 2个适配器 (FPCharacterAdapter, FPMovementAdapter)
- 18个LPSP脚本 (Motion/Camera/Animation/Character/Scriptable/Utilities/Services)
- 动画控制器 + 动画FBX + 模型 + 材质 + Data资产

**修改:**
- Player2View.prefab (全面重构)
- BotController.cs (更新组件引用)

**删除 (Phase 5):**
- ThirdPersonController.cs
- ChangeAnimator.cs
- 旧 P_LPSP_FP_CH.prefab
