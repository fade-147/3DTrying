# 3Dgame — LPSP 第一人称集成·执行计划

> **一句话**：打开 Unity → 运行 3 个菜单工具 → 补几个手动引用 → 测试  
> 资产/脚本/prefab 结构已完成，Inspector 连线已自动化 90%

---

## 执行步骤

### Step 1：打开项目，等编译通过

打开 `D:\unityxinxiangmu\3Dgame`，等待 Unity 编译完成。

### Step 2：依次运行 3 个菜单工具

| 顺序 | 菜单路径 | 作用 |
|------|----------|------|
| 1 | `Tools → Fix ALL Imported LPSP Prefabs & Integrate` | 修复从 FPSTrying 导入的 prefab 脚本 GUID |
| 2 | `Tools → Clean Duplicates & Fix Player2View` | 清重复骨架，集成新版 FP Rig，删冲突输入组件 |
| 3 | `Tools → Finalize Player2View (Complete Wiring)` | 全面自动连线：Motion/Camera/Adapter/Animator/SkinnedMeshRenderer/FeelManager |

> 每次运行完看 Console 有无报错。第三步会完成约 90% 的 Inspector 连线。

### Step 3：手动补全（Unity Editor Inspector）

打开 `Assets/Scripts/Prefab/Player2View.prefab`，检查以下项：

#### 必须手动做的

| 位置 | 操作 |
|------|------|
| `Character Root (Animator)` 的 Animator | 确认 **Avatar** 不为 None（应从 SK_FP_CH_Default_Root.fbx 选取） |
| `FP_CharacterMesh` 的 SkinnedMeshRenderer | 确认 **Root Bone** 指向骨架的 `root` 骨骼 |
| `PlayerCombat`（根上） | 拖入 **BulletPrefab** / **HitEffect** / **MuzzleFlash**（用项目中已有的） |
| `NetworkManager`（GameScene 中） | 确认 **Player Prefab** = `Player2View` |

#### 自动配置好了但检查一下

| 位置 | 内容 |
|------|------|
| PlayerViewManager | thirdPersonModule / firstPersonModule / fpCamera / fpCameraRoot |
| PlayerAnimation | thirdPersonAnimator / firstPersonAnimator |
| FPCharacterAdapter | playerState / playerMovement / playerCombat / playerView / playerInput / fpWorldCamera |
| FPMovementAdapter | playerMovement |
| FeelManager | Preset = SO_FP_Default |
| Motion 组件 (Character Root Motion / ik_hand_gun) | feelManager / characterBehaviour / characterAnimator |
| Root Player2View | 旧 ThirdPersonController 已 Disabled |

---

## 联机（Mirror）检查清单

- [ ] `NetworkIdentity` 在 Player2View 上
- [ ] `NetworkTransform` (Reliable) 在 Player2View 上
- [ ] `NetworkAnimator` → animator 指向 ThirdPersonModule 下的 3P Animator
- [ ] `PlayerState` (NetworkBehaviour) → 含 teamId / isHoldingGun / isFirstPerson / currentAmmo / isReloading / isDrinking / isInspecting 的 [SyncVar]
- [ ] `PlayerNetwork` (NetworkBehaviour) → 含 CmdFire / CmdToggleGun / CmdStartDrink 等 [Command] 和 [ClientRpc]
- [ ] `PlayerCombat` / `PlayerActions` (NetworkBehaviour) → 调用 PlayerNetwork 的 Cmd
- [ ] `PlayerCharacter` (NetworkBehaviour) → 血量/死亡/复活，保持原样
- [ ] Bot 系统 → `BotController.GetTeamId()` 已改用 `PlayerState.teamId`（已修好）

---

## Input System 检查

- [ ] `PlayerInput` 组件 Actions = `StarterAssets`
- [ ] `StarterAssetsInputs` 组件在根上
- [ ] 绑定的 action：Move / Look / Jump / Sprint（WASD + 鼠标 + 空格 + Shift）
- [ ] LPSP 输入组件（CrouchingInput/LeaningInput/LowerWeapon/LaserToggleInput）**已删除**（Finalize 脚本自动处理）

---

## 热更新（HybridCLR）

- [ ] `HotUpdate.asmdef` = `Assets/Scripts/` 覆盖所有新脚本
- [ ] 新 Player 脚本 + LPSP 脚本都在 HotUpdate 程序集中
- [ ] 热更新构建流程不变，DLL 会自动包含

---

## 测试

### 单人
- [ ] 启动游戏 → 第三人称视角正常
- [ ] WASD 移动、鼠标旋转、空格跳跃
- [ ] L 键切第一人称 → 手臂模型 + 新动画 + 双相机
- [ ] 射击（左键）、换弹（Z）、换枪（R）、喝水（C）、检视（T）
- [ ] L 键切回第三人称

### 联网（需两个客户端）
- [ ] 双方玩家可见、动画同步
- [ ] 射击/换枪/喝水/死亡/复活全部同步正确

---

## 完成后清理

测试全部通过后：

```
可删除：
  Assets/Scripts/Player/ThirdPersonController.cs
  Assets/Scripts/ChangeAnimator.cs
  Assets/Scripts/Prefab/P_LPSP_FP_CH.prefab（旧的 FP_CH）

Editor 脚本（保留或删除均可）：
  Assets/Editor/RebuildPlayer2ViewPrefab.cs
  Assets/Editor/CompletePlayer2ViewSetup.cs
  Assets/Editor/CleanupAndIntegrate.cs
  Assets/Editor/FixImportedLPSPPrefab.cs
  Assets/Editor/UnpackHelper.cs
  Assets/Editor/FinalizePlayer2View.cs
```
