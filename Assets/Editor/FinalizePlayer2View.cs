using UnityEngine;
using UnityEditor;
using System;
using System.Collections.Generic;
using System.IO;

/// <summary>
/// FINAL setup script: wires ALL remaining references on Player2View prefab.
/// Run once, then only manual steps remain (Avatar, RootBone, BulletPrefab).
/// Menu: Tools > Finalize Player2View (Complete Wiring)
/// </summary>
public class FinalizePlayer2View
{
    private const string PrefabPath = "Assets/Scripts/Prefab/Player2View.prefab";
    private const string Asm = "HotUpdate";

    // Type resolver (reflection-based, avoids compile-time asm reference issues)
    private static Type T(string n) => Type.GetType(n + ", " + Asm);

    [MenuItem("Tools/Finalize Player2View (Complete Wiring)")]
    public static void Run()
    {
        GameObject root = PrefabUtility.LoadPrefabContents(PrefabPath);
        if (!root) { Debug.LogError("Cannot load: " + PrefabPath); return; }

        try
        {
            Transform tpm = root.transform.Find("ThirdPersonModule");
            Transform fpm = root.transform.Find("FirstPersonModule");

            // Find the LPSP rig structure (may be nested under FP_CharacterRoot)
            Transform lpspRig = FindDeep(fpm, "LPSP_FP_Rig");
            if (!lpspRig) { Debug.LogError("LPSP_FP_Rig not found in FirstPersonModule. Run Clean Duplicates first."); return; }
            Transform charRootAnim = FindDeep(lpspRig, "Character Root (Animator)");
            Transform charRootMotion = FindDeep(lpspRig, "Character Root Motion");
            Transform armature = FindDeep(lpspRig, "Armature");
            Transform fpCharRoot = fpm.Find("FP_CharacterRoot");
            Transform fpCharMesh = fpm.Find("FP_CharacterMesh");

            Debug.Log("=== Starting complete wiring ===");

            // =====================================================
            // 1. WIRE ROOT COMPONENTS
            // =====================================================
            Wire(root, "PlayerViewManager", so => {
                SetRef(so, "thirdPersonModule", tpm?.gameObject);
                SetRef(so, "firstPersonModule", fpm?.gameObject);
                // Find camera - it's in SOCKET_Camera under Armature
                Camera fpCam = FindCamera(fpm);
                if (fpCam) SetRef(so, "fpCamera", fpCam);
                Transform camParent = fpCam ? fpCam.transform.parent : null;
                if (camParent) SetRef(so, "fpCameraRoot", camParent);
                // 3P model ref
                if (tpm) {
                    var geom = tpm.Find("Geometry");
                    if (geom) {
                        var model = FindDeep(geom, "SK_Military_Survivalist");
                        if (model) SetRef(so, "thirdPersonModel", model.gameObject);
                    }
                }
            });

            Wire(root, "PlayerAnimation", so => {
                if (tpm) {
                    var geom = tpm.Find("Geometry");
                    if (geom) SetRef(so, "thirdPersonAnimator", geom.GetComponent<Animator>());
                }
                if (charRootAnim) SetRef(so, "firstPersonAnimator", charRootAnim.GetComponent<Animator>());
            });

            Wire(root, "PlayerCombat", so => {
                // Find muzzle in LPSP rig
                if (fpm) {
                    var firePoints = FindDeep(fpm, "FirePoints");
                    if (firePoints) SetRef(so, "firstPersonMuzzle", firePoints);
                }
                if (tpm) {
                    var firePoints3p = FindDeep(tpm, "FirePoints");
                    if (!firePoints3p) firePoints3p = FindDeep(tpm, "thirdPersonMuzzle");
                    if (firePoints3p) SetRef(so, "thirdPersonMuzzle", firePoints3p);
                }
                // Auto-assign BulletPrefab / HitEffect / MuzzleFlash
                var bulletPrefab = AssetDatabase.LoadAssetAtPath<GameObject>(
                    "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Prefabs/Projectiles/P_LPSP_PROJ_Bullet_01.prefab");
                if (bulletPrefab) SetRef(so, "BulletPrefab", bulletPrefab);
                var hitEffect = AssetDatabase.LoadAssetAtPath<GameObject>(
                    "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Prefabs/Effects/Impacts/P_IMP_Concrete.prefab");
                if (hitEffect) SetRef(so, "HitEffect", hitEffect);
                var muzzleFlash = AssetDatabase.LoadAssetAtPath<GameObject>(
                    "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Prefabs/Effects/Particles/P_LPSP_WEP_Flash.prefab");
                if (muzzleFlash) SetRef(so, "MuzzleFlash", muzzleFlash);
            });

            Wire(root, "PlayerActions", so => {
                // No serialized refs needed, just ensure it's enabled
            });

            // Wire NetworkAnimator to 3P animator
            var netAnim = root.GetComponent<Mirror.NetworkAnimator>();
            if (netAnim && tpm) {
                var geom = tpm.Find("Geometry");
                if (geom) {
                    var anim3p = geom.GetComponent<Animator>();
                    if (anim3p) {
                        SerializedObject so = new SerializedObject(netAnim);
                        so.FindProperty("animator").objectReferenceValue = anim3p;
                        so.ApplyModifiedPropertiesWithoutUndo();
                    }
                }
            }

            // =====================================================
            // 2. WIRE FPCharacterRoot ADAPTERS
            // =====================================================
            if (fpCharRoot) {
                Wire(fpCharRoot.gameObject, "FPCharacterAdapter", so => {
                    SetRef(so, "playerState",  GetComp(root, "PlayerState"));
                    SetRef(so, "playerMovement", GetComp(root, "PlayerMovement"));
                    SetRef(so, "playerCombat",  GetComp(root, "PlayerCombat"));
                    SetRef(so, "playerView",    GetComp(root, "PlayerViewManager"));
                    SetRef(so, "playerInput",   GetComp(root, "StarterAssets.StarterAssetsInputs"));
                    Camera fpCam = FindCamera(fpm);
                    if (fpCam) SetRef(so, "fpWorldCamera", fpCam);
                    // Find weapon camera (Camera Depth)
                    var camDepth = FindDeep(fpm, "Camera Depth");
                    if (camDepth) SetRef(so, "fpWeaponCamera", camDepth.GetComponent<Camera>());
                });

                Wire(fpCharRoot.gameObject, "FPMovementAdapter", so => {
                    SetRef(so, "playerMovement", GetComp(root, "PlayerMovement"));
                });
            }

            // =====================================================
            // 3. WIRE MOTION COMPONENTS
            // =====================================================
            // Body layer (Character Root Motion)
            if (charRootMotion) {
                var feelMgr = FindFeelManager(fpm, lpspRig);
                Component charBhv = fpCharRoot?.GetComponent(T("FPCharacterAdapter"));
                Animator anim = charRootAnim?.GetComponent<Animator>();

                foreach (var comp in charRootMotion.GetComponents<MonoBehaviour>()) {
                    if (!comp) continue;
                    WireMotion(comp, feelMgr, charBhv, anim, null);
                }
            }

            // Weapon layer (ik_hand_gun)
            Transform ikHandGun = FindDeep(fpm ?? lpspRig, "ik_hand_gun");
            if (ikHandGun) {
                var feelMgr = FindFeelManager(fpm, lpspRig);
                Component charBhv = fpCharRoot?.GetComponent(T("FPCharacterAdapter"));
                Animator anim = charRootAnim?.GetComponent<Animator>();

                foreach (var comp in ikHandGun.GetComponents<MonoBehaviour>()) {
                    if (!comp) continue;
                    WireMotion(comp, feelMgr, charBhv, anim, null);
                }
            }

            // =====================================================
            // 4. WIRE FeelManager PRESET
            // =====================================================
            var feelMgrComp = FindFeelManager(fpm, lpspRig);
            if (feelMgrComp) {
                var preset = AssetDatabase.LoadAssetAtPath<ScriptableObject>(
                    "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Data/Feels/SO_FP_Default.asset");
                if (preset) {
                    SerializedObject so = new SerializedObject(feelMgrComp);
                    var prop = so.FindProperty("preset");
                    if (prop != null) { prop.objectReferenceValue = preset; so.ApplyModifiedPropertiesWithoutUndo(); }
                    Debug.Log("Set FeelManager Preset to SO_FP_Default");
                }
            }

            // =====================================================
            // 5. WIRE SKINNED MESH RENDERER
            // =====================================================
            if (fpCharMesh) {
                SkinnedMeshRenderer smr = fpCharMesh.GetComponent<SkinnedMeshRenderer>();
                if (!smr) smr = fpCharMesh.gameObject.AddComponent<SkinnedMeshRenderer>();

                Mesh mesh = AssetDatabase.LoadAssetAtPath<Mesh>(
                    "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Art/Meshes/Character/SK_FP_CH_Default_Root.fbx");
                if (mesh) { smr.sharedMesh = mesh; Debug.Log("Set FP_CharacterMesh mesh"); }

                Material mat = AssetDatabase.LoadAssetAtPath<Material>(
                    "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Art/Materials/Character/FP/M_FP_Camo_001_001.mat");
                if (mat) { smr.sharedMaterial = mat; Debug.Log("Set FP_CharacterMesh material"); }

                // Try to set root bone
                if (armature) {
                    Transform rootBone = FindDeep(armature, "root");
                    if (rootBone) { smr.rootBone = rootBone; Debug.Log("Set FP_CharacterMesh rootBone"); }
                }
            }

            // =====================================================
            // 6. WIRE Animator AVATAR & CONTROLLER
            // =====================================================
            if (charRootAnim) {
                Animator anim = charRootAnim.GetComponent<Animator>();
                if (!anim) anim = charRootAnim.gameObject.AddComponent<Animator>();

                // Controller
                var ctrl = AssetDatabase.LoadAssetAtPath<RuntimeAnimatorController>(
                    "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Animators/Character/AC_LPSP_PCH.controller");
                if (ctrl && !anim.runtimeAnimatorController) {
                    anim.runtimeAnimatorController = ctrl;
                    Debug.Log("Set Animator Controller");
                }

                // Avatar - try to load from FBX
                if (!anim.avatar) {
                    var avatars = AssetDatabase.LoadAllAssetsAtPath(
                        "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Art/Meshes/Character/SK_FP_CH_Default_Root.fbx");
                    foreach (var a in avatars) {
                        if (a is Avatar av) { anim.avatar = av; Debug.Log("Set Animator Avatar"); break; }
                    }
                }
            }

            // =====================================================
            // 7. ENSURE FirstPersonModule INACTIVE (3P default)
            // =====================================================
            if (fpm) fpm.gameObject.SetActive(false);

            // =====================================================
            // 8. ENSURE FP_CharacterRoot at Y=0
            // =====================================================
            if (fpCharRoot) fpCharRoot.localPosition = Vector3.zero;

            // =====================================================
            // 9. REMOVE LPSP INPUT COMPONENTS (conflict)
            // =====================================================
            if (lpspRig) {
                string[] toRemove = { "CrouchingInput", "LeaningInput", "LowerWeapon", "LaserToggleInput" };
                int removed = 0;
                foreach (var mb in lpspRig.GetComponentsInChildren<MonoBehaviour>(true)) {
                    if (!mb) continue;
                    foreach (string rn in toRemove) {
                        if (mb.GetType().Name == rn) {
                            UnityEngine.Object.DestroyImmediate(mb, true);
                            removed++;
                            break;
                        }
                    }
                }
                if (removed > 0) Debug.Log($"Removed {removed} conflicting LPSP input components");
            }

            // =====================================================
            // 10. DISABLE OLD ThirdPersonController
            // =====================================================
            var oldCtrl = root.GetComponent(T("StarterAssets.ThirdPersonController"));
            if (oldCtrl) {
                SerializedObject so = new SerializedObject(oldCtrl);
                var ep = so.FindProperty("m_Enabled");
                if (ep != null && ep.boolValue) { ep.boolValue = false; so.ApplyModifiedPropertiesWithoutUndo(); }
            }

            PrefabUtility.SaveAsPrefabAsset(root, PrefabPath);
            Debug.Log("=== FinalizePlayer2View COMPLETE ===");
        }
        finally
        {
            PrefabUtility.UnloadPrefabContents(root);
        }
        AssetDatabase.SaveAssets();
        AssetDatabase.Refresh();

        EditorUtility.DisplayDialog("Done",
            "Player2View is fully wired.\n\n" +
            "REMAINING MANUAL STEPS (see plan doc for details):\n" +
            "1. Assign Avatar to Animator (if not auto-set)\n" +
            "2. Set SkinnedMeshRenderer rootBone (if not auto-set)\n" +
            "3. Assign BulletPrefab / HitEffect / MuzzleFlash on PlayerCombat\n" +
            "4. Confirm NetworkManager player prefab in GameScene", "OK");
    }

    [MenuItem("Tools/Finalize Player2View (Complete Wiring)", true)]
    public static bool V() => AssetDatabase.LoadAssetAtPath<GameObject>(PrefabPath) != null;

    // === HELPERS ===

    private static void Wire(GameObject go, string compName, Action<SerializedObject> config) {
        var comp = go.GetComponent(T(compName));
        if (!comp) { Debug.LogWarning($"Component not found: {compName}"); return; }
        var so = new SerializedObject(comp);
        config(so);
        so.ApplyModifiedPropertiesWithoutUndo();
    }

    private static void SetRef(SerializedObject so, string field, UnityEngine.Object val) {
        if (!val) return;
        var p = so.FindProperty(field);
        if (p != null && p.propertyType == SerializedPropertyType.ObjectReference)
            p.objectReferenceValue = val;
    }

    private static Component GetComp(GameObject go, string typeName) {
        var t = T(typeName);
        return t != null ? go.GetComponent(t) : null;
    }

    private static Camera FindCamera(Transform root) {
        if (!root) return null;
        // Look for Camera tagged MainCamera
        foreach (var cam in root.GetComponentsInChildren<Camera>(true)) {
            if (cam.CompareTag("MainCamera")) return cam;
        }
        // Fallback: any camera
        var c = root.GetComponentInChildren<Camera>(true);
        return c;
    }

    private static Component FindFeelManager(Transform fpm, Transform lpspRig) {
        // Check FirstPersonModule first
        if (fpm) {
            var fm = fpm.GetComponent(T("InfimaGames.LowPolyShooterPack.FeelManager"));
            if (fm) return fm;
        }
        // Check LPSP rig
        if (lpspRig) {
            return lpspRig.GetComponentInChildren(T("InfimaGames.LowPolyShooterPack.FeelManager"));
        }
        return null;
    }

    private static void WireMotion(Component comp, Component feelMgr, Component charBhv, Animator anim, Component invBhv) {
        if (!comp) return;
        string name = comp.GetType().Name;
        if (!name.Contains("Motion") && name != "MotionApplier") return;

        SerializedObject so = new SerializedObject(comp);
        if (feelMgr) SetRef(so, "feelManager", feelMgr);
        if (charBhv) SetRef(so, "characterBehaviour", charBhv);
        if (anim) SetRef(so, "characterAnimator", anim);
        if (invBhv) SetRef(so, "inventoryBehaviour", invBhv);
        so.ApplyModifiedPropertiesWithoutUndo();
    }

    private static Transform FindDeep(Transform parent, string name) {
        if (!parent) return null;
        foreach (Transform child in parent) {
            if (child.name == name) return child;
            var f = FindDeep(child, name);
            if (f != null) return f;
        }
        return null;
    }
}
