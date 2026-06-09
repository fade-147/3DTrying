# Player_FPS_TP 状态报告

## 已完成

### 1. 预制体生成工具 (`Assets/Editor/CreateFPSPlayerPrefab.cs`)
- CopyAsset Player2View → Player_FPS_TP
- 清除旧 LPSP PrefabInstance
- 包 3P 子对象进 ThirdPersonModule
- 创建 FirstPersonModule + 实例化 FP_CH
- 自动补 FP_CH 的 CharacterController（如果被删）
- 删 FP_CH 的 AudioSource/根 Animator/missing scripts
- 添加并连线 ViewSwitcher
- 连线 ThirdPersonController 的 fpCamera/firstPersonAnimator
- 隐藏所有 Canvas

### 2. ViewSwitcher (`Assets/Scripts/Player/ViewSwitcher.cs`)
- L 键切换 3P/1P
- 远程玩家强制 3P
- 切换 ThirdPersonController ↔ LPSP Character/Movement
- 切换 PlayerInput (StarterAssets ↔ IA_Player)
- 切换 NetworkAnimator.animator

### 3. LPSP 脚本 null-guard
- `Character.cs` Awake() → ServiceLocator.Current null check
- `Movement.cs` Awake() → 同上
- `Weapon.cs` Awake() → 同上
- `CameraLook.cs` Start() → 同上
- `PlaySoundCharacterBehaviour.cs` OnStateEnter() → 同上

### 4. 资源清理
- 删 `MenuQualitySettings.cs`（Built-in RP PostProcessing，URP 不兼容）
- 删 `AnimationReceiver.cs`（引用已删的 CharacterDemonstration）
- 删 Demo 文件夹
- 删 Toolbox Editor（Inspector 反射报错）
- 删 `EditorSettings.asset`（YooAsset 打包冲突）
- GameScene 的 Setting Panel 设 inactive

### 5. 其他修改
- `PlayerMovement.cs`：GroundLayers = 1, AD 平移代替旋转
- `PlayerActions.cs`：加 GetOnGun/PutAwayGun 动画事件接收器
- `HotUpdate.asmdef`：加 TextMeshPro、URP Runtime、Toolbox 引用
- `ThirdPersonController.cs`：注释 L 键切换逻辑

---

## 当前仍存在的问题

### 运行时错误

| 错误 | 来源 | 原因 |
|------|------|------|
| `FootstepPlayer has missing references` | LPSP_FP_Rig | `characterAnimator` 或 `movementBehaviour` 或 `audioSource` 为空 |
| `CameraHeight has missing references` | Character Root (Animator) | `characterController` 引用为空 |
| `NetworkAnimator IndexOutOfRangeException` | FixedUpdate | Animator 参数数组越界，AnimatorController 不匹配 |
| 3P 鼠标控制相机旋转不工作 | ThirdPersonController | 待查 |
| 3P 重力/移动异常 | ThirdPersonController | 待查，可能和 CC 冲突有关 |
| 3P 模型不可见 | ViewSwitcher/ThirdPersonModule | 待查 |

### 结构性问题

1. **双 CharacterController**：根有一个 CC（3P），LPSP_FP_Rig 有一个 CC（1P）。1P 时 LPSP Movement 驱动 FP_CH 的 CC，根 CC 原地不动。需要同步两个 CC 的位置。

2. **双输入系统**：StarterAssets.inputactions（3P）和 IA_Player.inputactions（1P）可能冲突。同一按键的不同绑定未验证。

3. **Cinemachine 虚拟相机**：GameScene 里的 Virtual Camera Follow 目标可能需要更新为 Player_FPS_TP 的 PlayerCameraRoot。

4. **Mirror 联机未测试**：玩家生成、动画同步、武器状态同步等。

---

## 给下一个 AI 的建议

1. **验证 Player2View 的 ThirdPersonController 在独立运行时完全正常**——先确保 3P 基线无误。
2. **Fix FootstepPlayer**：连线 `characterAnimator`/`movementBehaviour`/`audioSource` 或用 null-guard。
3. **Fix CameraHeight**：连线 `characterController` 到 FP_CH 的 CC。
4. **Fix NetworkAnimator**：Animator.parameters 数组越界，可能是 FP Animator Controller 参数和 3P Animator Controller 不匹配导致。确保切换 Animator 时重新同步参数列表。
5. **Fix 3P 相机旋转**：ThirdPersonController 的 `CameraRotation()` 在 `LateUpdate()` 中调用，依赖 `isLocalPlayer` 和 `_mainCamera` 引用。
6. **Fix 地面检测**：根 CC 和 FP_CH CC 各自设置，确保活跃的那个 GroundLayers 正确。
7. **FP_CH 恢复**：当前 `Assets/Scripts/Prefab/P_LPSP_FP_CH.prefab` 可能被之前运行永久删除了一些组件。重新导入 LPSP 包可恢复，或运行 CreateFPSPlayerPrefab 工具自动补 CC。
8. **建议清理**：删除不再需要的脚本如 `FPCharacterAdapter.cs`、`FPMovementAdapter.cs`（当前架构不需要它们）。

---

## 关键文件路径

| 用途 | 路径 |
|------|------|
| 生成工具 | `Assets/Editor/CreateFPSPlayerPrefab.cs` |
| 输出预制体 | `Assets/Scripts/Prefab/Player_FPS_TP.prefab` |
| 源 3P 预制体 | `Assets/Scripts/Prefab/Player2View.prefab` |
| FP_CH 源 | `Assets/Scripts/Prefab/P_LPSP_FP_CH.prefab` |
| ViewSwitcher | `Assets/Scripts/Player/ViewSwitcher.cs` |
| ThirdPersonController | `Assets/Scripts/Player/ThirdPersonController.cs` |
| LPSP 源码 | `Assets/Scripts/Infima Games/Low Poly Shooter Pack/Code/` |
| FPSTrying 参考 | `D:\unityxinxiangmu\FPSTrying\` |
