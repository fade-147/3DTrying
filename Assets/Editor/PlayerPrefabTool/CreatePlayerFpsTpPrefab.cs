using UnityEngine;
using UnityEditor;
using System.Collections.Generic;
using Mirror;

/// <summary>
/// Creates Player_FPS_TP.prefab by combining LPSP FP_CH (first-person rig) with
/// Mirror networking and ThirdPersonController physics.
///
/// Architecture:
/// - ThirdPersonController handles Move/JumpAndGravity/GroundedCheck/CameraRotation
/// - LPSP Character handles FP weapons/animations/leaning
/// - ThirdPersonMovementBridge bridges TPC state to LPSP MovementBehaviour queries
/// - PlayerNetworkBridge handles Mirror lifecycle + view switching + animation sync
/// </summary>
public class CreatePlayerFpsTpPrefab
{
    const string OutPath = "Assets/Scripts/Prefab/Player_FPS_TP.prefab";
    const string FpChPath = "Assets/Scripts/Prefab/P_LPSP_FP_CH.prefab";
    const string Player2ViewPath = "Assets/Scripts/Prefab/Player2View.prefab";

    [MenuItem("Tools/Create FPS+TPS Player Prefab v2")]
    public static void Run()
    {
        // ── 1. Validate source assets ──
        GameObject fpAsset = AssetDatabase.LoadAssetAtPath<GameObject>(FpChPath);
        if (!fpAsset)
        {
            Debug.LogError($"[CreatePlayerFpsTpPrefab] Source prefab not found: {FpChPath}");
            return;
        }

        GameObject tpSource = AssetDatabase.LoadAssetAtPath<GameObject>(Player2ViewPath);
        if (!tpSource)
        {
            Debug.LogError($"[CreatePlayerFpsTpPrefab] Source prefab not found: {Player2ViewPath}");
            return;
        }

        // ── 2. Create root from FP_CH as base ──
        if (!AssetDatabase.CopyAsset(FpChPath, OutPath))
        {
            Debug.LogError("[CreatePlayerFpsTpPrefab] Copy failed");
            return;
        }
        AssetDatabase.Refresh();

        GameObject root = PrefabUtility.LoadPrefabContents(OutPath);
        if (!root)
        {
            Debug.LogError("[CreatePlayerFpsTpPrefab] Cannot load copy");
            return;
        }

        try
        {
            // ── 3. Set layer ──
            // Project uses "Character" layer (10), not "Player".
            int playerLayer = LayerMask.NameToLayer("Character");
            if (playerLayer < 0) playerLayer = LayerMask.NameToLayer("Player"); // fallback
            if (playerLayer >= 0)
            {
                root.layer = playerLayer;
                // Only set layer on direct root-level children, not deep LPSP hierarchy
                foreach (Transform t in root.transform)
                {
                    if (t.gameObject.layer != playerLayer && t.gameObject.layer < 8)
                        t.gameObject.layer = playerLayer;
                }
            }

            // ── 4. Ensure root has CharacterController (unique) ──
            var rootCC = root.GetComponent<CharacterController>();
            if (!rootCC)
            {
                rootCC = root.AddComponent<CharacterController>();
                rootCC.height = 1.8f;
                rootCC.radius = 0.3f;
                rootCC.center = new Vector3(0, 1.0f, 0);
                rootCC.slopeLimit = 45f;
                rootCC.stepOffset = 0.25f;
                rootCC.skinWidth = 0.08f;
            }

            // Remove any extra CharacterControllers on children
            foreach (var cc in root.GetComponentsInChildren<CharacterController>(true))
            {
                if (cc != rootCC)
                    Object.DestroyImmediate(cc, true);
            }

            // ── 5. Add Mirror networking components ──
            if (!root.TryGetComponent<NetworkIdentity>(out _))
                root.AddComponent<NetworkIdentity>();

            var netTransform = root.GetComponent<NetworkTransformReliable>();
            if (!netTransform)
            {
                netTransform = root.AddComponent<NetworkTransformReliable>();
                netTransform.syncDirection = SyncDirection.ClientToServer;
            }

            var netAnim = root.GetComponent<NetworkAnimator>();
            if (!netAnim)
                netAnim = root.AddComponent<NetworkAnimator>();

            // ── 6. Add ThirdPersonController ──
            var tpc = root.GetComponent<StarterAssets.ThirdPersonController>();
            if (!tpc)
                tpc = root.AddComponent<StarterAssets.ThirdPersonController>();

            CopyTpcConfigFromPlayer2View(tpc, tpSource);

            // ── 7. Add ThirdPersonMovementBridge ──
            if (!root.TryGetComponent<InfimaGames.LowPolyShooterPack.ThirdPersonMovementBridge>(out _))
                root.AddComponent<InfimaGames.LowPolyShooterPack.ThirdPersonMovementBridge>();

            // ── 8. Add PlayerNetworkBridge ──
            var pnb = root.GetComponent<StarterAssets.PlayerNetworkBridge>();
            if (!pnb)
                pnb = root.AddComponent<StarterAssets.PlayerNetworkBridge>();

            // ── 9. Add PlayerCharacter if missing ──
            var pc = root.GetComponent<PlayerCharacter>();
            if (!pc)
                pc = root.AddComponent<PlayerCharacter>();

            // ── 10. Destroy LPSP Movement.cs (replaced by ThirdPersonMovementBridge) ──
            var lpspMovement = root.GetComponent<InfimaGames.LowPolyShooterPack.Movement>();
            if (lpspMovement)
            {
                // Copy walk multipliers from Movement to ThirdPersonMovementBridge
                var bridge = root.GetComponent<InfimaGames.LowPolyShooterPack.ThirdPersonMovementBridge>();
                if (bridge && lpspMovement)
                {
                    var movSo = new SerializedObject(lpspMovement);
                    var bridgeSo = new SerializedObject(bridge);
                    CopySerializedProp(movSo, bridgeSo, "walkingMultiplierForward");
                    CopySerializedProp(movSo, bridgeSo, "walkingMultiplierSideways");
                    CopySerializedProp(movSo, bridgeSo, "walkingMultiplierBackwards");
                    bridgeSo.ApplyModifiedPropertiesWithoutUndo();
                }

                // Copy speed config from Movement to ThirdPersonController.
                // NOTE: Gravity and JumpHeight are NOT copied from LPSP Movement —
                // the LPSP physics model uses different units, so Player2View's tuned
                // values (set in CopyTpcConfigFromPlayer2View) are the correct baseline.
                if (tpc)
                {
                    var movSo = new SerializedObject(lpspMovement);
                    var tpcSo = new SerializedObject(tpc);
                    float walkingSpeed = movSo.FindProperty("speedWalking")?.floatValue ?? 2.0f;
                    float runningSpeed = movSo.FindProperty("speedRunning")?.floatValue ?? 5.335f;

                    tpcSo.FindProperty("MoveSpeed").floatValue = walkingSpeed;
                    tpcSo.FindProperty("SprintSpeed").floatValue = runningSpeed;
                    tpcSo.ApplyModifiedPropertiesWithoutUndo();
                }

                Object.DestroyImmediate(lpspMovement, true);
            }

            // ── 10b. Rewire all movementBehaviour references to ThirdPersonMovementBridge ──
            var bridgeRef = root.GetComponent<InfimaGames.LowPolyShooterPack.ThirdPersonMovementBridge>();
            if (bridgeRef)
            {
                // Iterate ALL MonoBehaviours (Motion, FootstepPlayer, etc.) that reference movementBehaviour
                foreach (var mb in root.GetComponentsInChildren<MonoBehaviour>(true))
                {
                    if (mb == null || mb is InfimaGames.LowPolyShooterPack.ThirdPersonMovementBridge)
                        continue;

                    var so = new SerializedObject(mb);
                    var mbProp = so.FindProperty("movementBehaviour");
                    if (mbProp != null && mbProp.objectReferenceValue == null)
                    {
                        mbProp.objectReferenceValue = bridgeRef;
                        so.ApplyModifiedPropertiesWithoutUndo();
                        Debug.Log($"[CreatePlayerFpsTpPrefab] Rewired movementBehaviour on {mb.GetType().Name} ({mb.name})");
                    }

                    // FootstepPlayer: also fix missing audioSource (was null in source prefab)
                    if (mb is InfimaGames.LowPolyShooterPack.FootstepPlayer)
                    {
                        var asProp = so.FindProperty("audioSource");
                        if (asProp != null && asProp.objectReferenceValue == null)
                        {
                            var newAS = mb.gameObject.AddComponent<AudioSource>();
                            newAS.playOnAwake = false;
                            newAS.loop = false;
                            newAS.spatialBlend = 1f;
                            asProp.objectReferenceValue = newAS;
                            so.ApplyModifiedPropertiesWithoutUndo();
                            Debug.Log("[CreatePlayerFpsTpPrefab] Created AudioSource for FootstepPlayer");
                        }
                    }
                }
            }

            // ── 10c. Fix FP cameras ──
            // LPSP has two cameras under head/SOCKET_Camera, both with
            // UniversalAdditionalCameraData (URP):
            //
            //   "Camera" (MainCamera, depth 0, TAA, volumeLayer 11):
            //     Renders world/environment. Uses TAA for anti-aliasing and
            //     layer-11 volumes for scene post-processing.
            //
            //   "Camera Depth" (child, depth 1, no AA, volumeLayer 12, clearFlags=Depth):
            //     Renders ONLY weapons (layer 9) on top of the world view.
            //     Uses layer-12 volumes for weapon/scop post-processing
            //     (bloom, glare, depth-of-field on scopes).
            //     ClearFlags=Depth means it doesn't clear the color buffer —
            //     weapons are composited on top of the world.
            //
            // BOTH cameras have finalBlitToCameraTarget=0 → output to render textures.
            //
            // Fix 1: Main camera culling mask (101687) was tuned for LPSP demo
            //   and misses layers used by the game map → set to Everything.
            // Fix 2: Ensure Camera Depth has clearFlags=Depth and weapon-only culling.
            //   The Volume on Camera Depth is KEPT — it provides scope post-processing.

            var fpMainCamGo = FindDeep(root.transform, "Camera");
            if (fpMainCamGo)
            {
                var fpMainCam = fpMainCamGo.GetComponent<Camera>();
                if (fpMainCam)
                {
                    fpMainCam.cullingMask = ~0; // Everything
                    Debug.Log("[CreatePlayerFpsTpPrefab] FP main cam cullingMask → Everything");
                }
            }

            var fpDepthCamGo = FindDeep(root.transform, "Camera Depth");
            if (fpDepthCamGo)
            {
                var fpDepthCam = fpDepthCamGo.GetComponent<Camera>();
                if (fpDepthCam)
                {
                    // Ensure correct overlay configuration
                    fpDepthCam.clearFlags = CameraClearFlags.Depth;
                    // Camera Depth renders only FP weapons. Project layer names:
                    // "First Person View" (9) or "Weapon".
                    int weaponLayer = LayerMask.NameToLayer("First Person View");
                    if (weaponLayer < 0) weaponLayer = LayerMask.NameToLayer("Weapon");
                    if (weaponLayer >= 0)
                        fpDepthCam.cullingMask = (1 << weaponLayer);
                    Debug.Log("[CreatePlayerFpsTpPrefab] Camera Depth: clearFlags=Depth, cullingMask=Weapon");
                }
                // NOTE: Do NOT destroy the Volume on Camera Depth — it provides
                // post-processing for weapon scopes (bloom/glare).
            }

            // ── 11. Create ThirdPersonVisual subtree from Player2View ──
            CreateThirdPersonVisual(root, tpSource);

            // ── 12. Wire references ──
            WireReferences(root, fpAsset, tpSource);

            // ── 13. Ensure PlayerInput is on root ──
            var playerInput = root.GetComponent<UnityEngine.InputSystem.PlayerInput>();
            if (!playerInput)
            {
                // Try to find one on children and move it up, or create new
                playerInput = root.GetComponentInChildren<UnityEngine.InputSystem.PlayerInput>();
            }

            // ── 14. Remove StarterAssetsInputs (replaced by IA_Player callbacks) ──
            var sai = root.GetComponent<StarterAssets.StarterAssetsInputs>();
            if (sai)
                Object.DestroyImmediate(sai, true);

            // ── 15. Disable characterBehaviour for now; PlayerNetworkBridge enables it for local player ──
            var charBehaviour = root.GetComponent<InfimaGames.LowPolyShooterPack.CharacterBehaviour>();
            if (charBehaviour)
                charBehaviour.enabled = false;

            // ── 16. Save ──
            PrefabUtility.SaveAsPrefabAsset(root, OutPath);
            AssetDatabase.SaveAssets();
            AssetDatabase.Refresh();

            Debug.Log("[CreatePlayerFpsTpPrefab] Player_FPS_TP.prefab created successfully.");
            EditorUtility.DisplayDialog("Done",
                "Player_FPS_TP created.\n\n" +
                "Remember to:\n" +
                "1. Set playerPrefab on MyNetworkRoomManager to Player_FPS_TP\n" +
                "2. Verify IA_Player input actions are assigned on the PlayerInput component",
                "OK");
        }
        finally
        {
            PrefabUtility.UnloadPrefabContents(root);
        }
    }

    [MenuItem("Tools/Create FPS+TPS Player Prefab v2", true)]
    public static bool Validate()
    {
        return AssetDatabase.LoadAssetAtPath<GameObject>(FpChPath) != null
            && AssetDatabase.LoadAssetAtPath<GameObject>(Player2ViewPath) != null;
    }

    #region Helpers

    private static void CopyTpcConfigFromPlayer2View(
        StarterAssets.ThirdPersonController tpc, GameObject tpSource)
    {
        var srcTpc = tpSource.GetComponent<StarterAssets.ThirdPersonController>();
        if (!srcTpc) return;

        var srcSo = new SerializedObject(srcTpc);
        var dstSo = new SerializedObject(tpc);

        string[] fieldsToCopy =
        {
            "MoveSpeed", "SprintSpeed", "RotationSmoothTime", "SpeedChangeRate",
            "JumpHeight", "Gravity", "JumpTimeout", "FallTimeout",
            "GroundedOffset", "GroundedRadius", "TopClamp", "BottomClamp",
            "CameraAngleOverride", "LockCameraPosition",
            "fpMouseSensitivity", "BulletSpeed", "BulletLifeTime",
            "FireRate", "MaxShootDistance", "GroundLayers"
        };

        foreach (string field in fieldsToCopy)
        {
            var srcProp = srcSo.FindProperty(field);
            var dstProp = dstSo.FindProperty(field);
            if (srcProp != null && dstProp != null)
                CopyPropertyValue(srcProp, dstProp);
        }

        // Copy object references
        string[] refFieldsToCopy =
        {
            "CinemachineCameraTarget", "BulletPrefab",
            "HitEffect", "MuzzleFlash"
        };

        foreach (string field in refFieldsToCopy)
        {
            var srcProp = srcSo.FindProperty(field);
            var dstProp = dstSo.FindProperty(field);
            if (srcProp != null && dstProp != null)
                dstProp.objectReferenceValue = srcProp.objectReferenceValue;
        }

        dstSo.ApplyModifiedPropertiesWithoutUndo();
    }

    private static void CopySerializedProp(SerializedObject src, SerializedObject dst, string propName)
    {
        var sp = src.FindProperty(propName);
        var dp = dst.FindProperty(propName);
        if (sp != null && dp != null)
            CopyPropertyValue(sp, dp);
    }

    private static void CopyPropertyValue(SerializedProperty src, SerializedProperty dst)
    {
        switch (dst.propertyType)
        {
            case SerializedPropertyType.Float:
                dst.floatValue = src.floatValue;
                break;
            case SerializedPropertyType.Integer:
                dst.intValue = src.intValue;
                break;
            case SerializedPropertyType.Boolean:
                dst.boolValue = src.boolValue;
                break;
            case SerializedPropertyType.Vector3:
                dst.vector3Value = src.vector3Value;
                break;
            case SerializedPropertyType.Vector2:
                dst.vector2Value = src.vector2Value;
                break;
            case SerializedPropertyType.LayerMask:
                dst.intValue = src.intValue;
                break;
            case SerializedPropertyType.ObjectReference:
                dst.objectReferenceValue = src.objectReferenceValue;
                break;
        }
    }

    private static void CreateThirdPersonVisual(GameObject root, GameObject tpSource)
    {
        // Find or create ThirdPersonVisual container
        Transform visualRoot = root.transform.Find("ThirdPersonVisual");
        if (!visualRoot)
        {
            var go = new GameObject("ThirdPersonVisual");
            go.transform.SetParent(root.transform);
            go.transform.localPosition = Vector3.zero;
            go.transform.localRotation = Quaternion.identity;
            visualRoot = go.transform;
        }

        // Copy 3P model (Geometry) from Player2View
        Transform srcGeometry = tpSource.transform.Find("Geometry");
        if (srcGeometry)
        {
            // Remove any existing geometry copy
            Transform existingGeo = visualRoot.Find("Geometry");
            if (existingGeo)
                Object.DestroyImmediate(existingGeo.gameObject, true);

            GameObject geoCopy = Object.Instantiate(srcGeometry.gameObject, visualRoot);
            geoCopy.name = "Geometry";
            geoCopy.transform.localPosition = Vector3.zero;
            geoCopy.transform.localRotation = Quaternion.identity;

            // Unpack any prefab instances in the copy
            UnpackAllPrefabInstances(geoCopy);
        }

        // Copy PlayerCameraRoot if it exists
        Transform srcCamRoot = tpSource.transform.Find("PlayerCameraRoot");
        if (srcCamRoot && !visualRoot.Find("PlayerCameraRoot"))
        {
            GameObject camRootCopy = Object.Instantiate(srcCamRoot.gameObject, visualRoot);
            camRootCopy.name = "PlayerCameraRoot";
            camRootCopy.transform.localPosition = srcCamRoot.localPosition;
            camRootCopy.transform.localRotation = srcCamRoot.localRotation;
            UnpackAllPrefabInstances(camRootCopy);
        }

        // Copy 3P Animator from Player2View's Geometry
        var srcAnim = tpSource.GetComponent<Animator>();
        if (srcAnim)
        {
            var geo = visualRoot.Find("Geometry");
            if (geo)
            {
                var geoAnim = geo.GetComponent<Animator>();
                if (!geoAnim)
                    geoAnim = geo.gameObject.AddComponent<Animator>();

                geoAnim.runtimeAnimatorController = srcAnim.runtimeAnimatorController;
                geoAnim.avatar = srcAnim.avatar;
                geoAnim.applyRootMotion = srcAnim.applyRootMotion;
                geoAnim.updateMode = srcAnim.updateMode;
                geoAnim.cullingMode = srcAnim.cullingMode;
            }
        }
    }

    private static void UnpackAllPrefabInstances(GameObject root)
    {
        for (int i = 0; i < 20; i++)
        {
            GameObject target = null;
            foreach (Transform t in root.GetComponentsInChildren<Transform>(true))
            {
                if (!t || !t.gameObject) continue;
                if (PrefabUtility.IsPartOfPrefabInstance(t.gameObject))
                {
                    var r = PrefabUtility.GetNearestPrefabInstanceRoot(t.gameObject);
                    if (r) { target = r; break; }
                }
            }
            if (!target) break;
            PrefabUtility.UnpackPrefabInstance(target, PrefabUnpackMode.Completely, InteractionMode.AutomatedAction);
        }
    }

    private static void WireReferences(GameObject root, GameObject fpAsset, GameObject tpSource)
    {
        // ThirdPersonController references
        var tpc = root.GetComponent<StarterAssets.ThirdPersonController>();
        if (tpc)
        {
            var tpcSo = new SerializedObject(tpc);

            // CinemachineCameraTarget → ThirdPersonVisual/PlayerCameraRoot
            var camTarget = root.transform.Find("ThirdPersonVisual/PlayerCameraRoot");
            if (camTarget)
                tpcSo.FindProperty("CinemachineCameraTarget").objectReferenceValue = camTarget.gameObject;

            // fpCamera → Character Root (Animator)/.../Camera (world cam)
            var fpCam = FindDeep(root.transform, "Camera");
            if (fpCam)
            {
                var cam = fpCam.GetComponent<Camera>();
                if (cam)
                {
                    // Find the "Camera" tagged as MainCamera
                    if (cam.CompareTag("MainCamera"))
                        tpcSo.FindProperty("fpCamera").objectReferenceValue = cam;
                }
            }

            tpcSo.ApplyModifiedPropertiesWithoutUndo();
        }

        // PlayerNetworkBridge references
        var pnb = root.GetComponent<StarterAssets.PlayerNetworkBridge>();
        if (pnb)
        {
            var pnbSo = new SerializedObject(pnb);

            pnbSo.FindProperty("thirdPersonController").objectReferenceValue = tpc;

            var charBehaviour = root.GetComponent<InfimaGames.LowPolyShooterPack.CharacterBehaviour>();
            pnbSo.FindProperty("characterBehaviour").objectReferenceValue = charBehaviour;

            var pc = root.GetComponent<PlayerCharacter>();
            pnbSo.FindProperty("playerCharacter").objectReferenceValue = pc;

            var thirdPersonVisual = root.transform.Find("ThirdPersonVisual");
            if (thirdPersonVisual)
                pnbSo.FindProperty("thirdPersonVisual").objectReferenceValue = thirdPersonVisual.gameObject;

            var charRoot = root.transform.Find("Character Root (Animator)");
            if (charRoot)
                pnbSo.FindProperty("characterRoot").objectReferenceValue = charRoot.gameObject;

            // fpCamera
            var fpCamGo = FindDeep(root.transform, "Camera");
            if (fpCamGo)
            {
                var cam = fpCamGo.GetComponent<Camera>();
                if (cam && cam.CompareTag("MainCamera"))
                    pnbSo.FindProperty("fpCamera").objectReferenceValue = cam;
            }

            // tpAnimator → ThirdPersonVisual/Geometry animator
            var geoAnim = root.transform.Find("ThirdPersonVisual/Geometry");
            if (geoAnim)
                pnbSo.FindProperty("tpAnimator").objectReferenceValue = geoAnim.GetComponent<Animator>();

            // fpAnimator → Character Root (Animator) animator
            if (charRoot)
                pnbSo.FindProperty("fpAnimator").objectReferenceValue = charRoot.GetComponent<Animator>();

            // playerInput → root's PlayerInput
            var pi = root.GetComponent<UnityEngine.InputSystem.PlayerInput>();
            pnbSo.FindProperty("playerInput").objectReferenceValue = pi;

            pnbSo.ApplyModifiedPropertiesWithoutUndo();
        }

        // ── NetworkAnimator: default animator → 3P (safe default for remote players) ──
        var netAnim = root.GetComponent<NetworkAnimator>();
        if (netAnim != null && netAnim.animator == null)
        {
            var tpAnim = root.transform.Find("ThirdPersonVisual/Geometry")?.GetComponent<Animator>();
            if (tpAnim != null)
                netAnim.animator = tpAnim;
        }

        // ── CameraHeight: rewire characterController → root CC ──
        foreach (var ch in root.GetComponentsInChildren<InfimaGames.LowPolyShooterPack.CameraHeight>(true))
        {
            var chSo = new SerializedObject(ch);
            var ccProp = chSo.FindProperty("characterController");
            if (ccProp != null && ccProp.objectReferenceValue == null)
            {
                var rootCC = root.GetComponent<CharacterController>();
                if (rootCC != null)
                {
                    ccProp.objectReferenceValue = rootCC;
                    chSo.ApplyModifiedPropertiesWithoutUndo();
                    Debug.Log("[CreatePlayerFpsTpPrefab] Rewired CameraHeight.characterController");
                }
            }
        }
    }

    private static Transform FindDeep(Transform parent, string name)
    {
        if (!parent) return null;
        foreach (Transform child in parent)
        {
            if (child.name == name) return child;
            var found = FindDeep(child, name);
            if (found) return found;
        }
        return null;
    }

    #endregion
}
