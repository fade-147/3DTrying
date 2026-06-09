using UnityEngine;
using UnityEditor;
using System.Collections.Generic;

/// <summary>
/// COMPREHENSIVE one-shot repair: clean, instantiate, unpack, wire EVERYTHING.
/// Run: Tools > Complete Player2View Setup (One-Shot)
/// </summary>
public class CompletePlayer2ViewSetup
{
    private const string Player2ViewPath = "Assets/Scripts/Prefab/Player2View.prefab";
    private const string FPPrefabPath = "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Prefabs/P_LPSP_FP_CH.prefab";

    /// <summary>
    /// Resolve a type by name across ALL loaded assemblies (not just calling assembly).
    /// Type.GetType("Name, Assembly") fails when called from Assembly-CSharp-Editor
    /// because HotUpdate may not be in the search path.
    /// </summary>
    private static System.Type T(string typeName)
    {
        foreach (var asm in System.AppDomain.CurrentDomain.GetAssemblies())
        {
            var t = asm.GetType(typeName);
            if (t != null) return t;
        }
        // Also try with namespace prefixes
        string[] prefixes = { "", "StarterAssets.", "InfimaGames.LowPolyShooterPack." };
        foreach (var asm in System.AppDomain.CurrentDomain.GetAssemblies())
        {
            foreach (var prefix in prefixes)
            {
                var t = asm.GetType(prefix + typeName);
                if (t != null) return t;
            }
        }
        return null;
    }

    [MenuItem("Tools/Complete Player2View Setup (One-Shot)")]
    public static void Run()
    {
        GameObject root = PrefabUtility.LoadPrefabContents(Player2ViewPath);
        if (!root) { Debug.LogError("Cannot load Player2View"); return; }

        try
        {
            Transform tpm = root.transform.Find("ThirdPersonModule");
            Transform fpm = root.transform.Find("FirstPersonModule");
            if (!fpm) { Debug.LogError("FirstPersonModule not found"); return; }

            // ── STEP 1: Clean FP_CharacterRoot ──
            Transform fpCharRoot = fpm.Find("FP_CharacterRoot");
            if (!fpCharRoot)
            {
                fpCharRoot = new GameObject("FP_CharacterRoot").transform;
                fpCharRoot.SetParent(fpm);
                fpCharRoot.localPosition = Vector3.zero;
            }
            else
            {
                var kids = new List<Transform>();
                foreach (Transform c in fpCharRoot) kids.Add(c);
                foreach (var c in kids) Object.DestroyImmediate(c.gameObject, true);
                Debug.Log($"Cleaned {kids.Count} objects from FP_CharacterRoot");
            }

            // Remove any extra objects directly under FirstPersonModule
            var extra = new List<Transform>();
            foreach (Transform c in fpm)
            {
                if (c.name != "FP_CharacterRoot" && c.name != "FP_Weapons" && c.name != "FP_CharacterMesh")
                    extra.Add(c);
            }
            foreach (var c in extra) Object.DestroyImmediate(c.gameObject, true);
            if (extra.Count > 0) Debug.Log($"Removed {extra.Count} extra objects from FirstPersonModule");

            // ── STEP 2: Instantiate fresh FP_CH ──
            GameObject fpPrefab = AssetDatabase.LoadAssetAtPath<GameObject>(FPPrefabPath);
            if (!fpPrefab) { Debug.LogError("FP_CH prefab not found: " + FPPrefabPath); return; }

            GameObject instance = PrefabUtility.InstantiatePrefab(fpPrefab, fpCharRoot) as GameObject;
            if (!instance) { Debug.LogError("Failed to instantiate FP_CH"); return; }
            instance.name = "LPSP_FP_Rig";
            instance.transform.localPosition = Vector3.zero;
            instance.transform.localRotation = Quaternion.identity;

            // ── STEP 3: Unpack ALL nested prefab instances ──
            UnpackAll(instance);

            // ── STEP 4: Clean ALL missing MonoBehaviours ──
            int missingTotal = 0;
            foreach (var t in instance.GetComponentsInChildren<Transform>(true))
            {
                if (!t) continue;
                int m = GameObjectUtility.GetMonoBehavioursWithMissingScriptCount(t.gameObject);
                if (m > 0) { GameObjectUtility.RemoveMonoBehavioursWithMissingScript(t.gameObject); missingTotal += m; }
            }
            Debug.Log($"Cleaned {missingTotal} missing scripts from LPSP_FP_Rig");

            // Also clean missing scripts from ALL of Player2View
            foreach (var t in root.GetComponentsInChildren<Transform>(true))
            {
                if (!t) continue;
                int m = GameObjectUtility.GetMonoBehavioursWithMissingScriptCount(t.gameObject);
                if (m > 0) { GameObjectUtility.RemoveMonoBehavioursWithMissingScript(t.gameObject); }
            }

            // ── STEP 5: Remove conflict input components ──
            string[] conflictNames = { "CrouchingInput", "LeaningInput", "LowerWeapon", "LaserToggleInput", "PlayerInput" };
            int removedConflicts = 0;
            foreach (var mb in instance.GetComponentsInChildren<MonoBehaviour>(true))
            {
                if (!mb) continue;
                foreach (string cn in conflictNames)
                    if (mb.GetType().Name == cn) { Object.DestroyImmediate(mb, true); removedConflicts++; break; }
            }
            Debug.Log($"Removed {removedConflicts} conflicting input components");

            // ── STEP 6: Find key references in the LPSP rig ──
            Transform charRootAnim = FindDeep(instance.transform, "Character Root (Animator)");
            Transform charRootMotion = FindDeep(instance.transform, "Character Root Motion");
            Transform armature = FindDeep(instance.transform, "Armature");
            Transform ikHandGun = FindDeep(instance.transform, "ik_hand_gun");
            Camera fpCam = FindCamera(instance.transform);
            Camera fpWeaponCam = FindWeaponCamera(instance.transform);
            Animator fpAnimator = charRootAnim ? charRootAnim.GetComponent<Animator>() : null;
            if (!fpAnimator && charRootAnim) fpAnimator = charRootAnim.gameObject.AddComponent<Animator>();

            // Find ALL FeelManager instances
            var feelMgrs = new List<Component>();
            foreach (var mb in instance.GetComponentsInChildren<MonoBehaviour>(true))
                if (mb && mb.GetType().Name == "FeelManager") feelMgrs.Add(mb);

            // Find CharacterBehaviour and InventoryBehaviour in the LPSP rig
            Component characterBhv = null;
            Component inventoryBhv = null;
            foreach (var mb in instance.GetComponentsInChildren<MonoBehaviour>(true))
            {
                if (!mb) continue;
                if (mb.GetType().Name == "CharacterBehaviour") characterBhv = mb;
                if (mb.GetType().Name == "InventoryBehaviour") inventoryBhv = mb;
            }

            // Find the FP_CharacterMesh SMR
            Transform fpCharMesh = fpm.Find("FP_CharacterMesh");
            SkinnedMeshRenderer fpSMR = fpCharMesh ? fpCharMesh.GetComponent<SkinnedMeshRenderer>() : null;
            if (!fpSMR && fpCharMesh) fpSMR = fpCharMesh.gameObject.AddComponent<SkinnedMeshRenderer>();

            // Find 3P references
            // The 3P Animator is on the Player2View root GameObject (not Geometry)
            Animator tpAnim = root.GetComponent<Animator>();
            // Fallback: check if there's an Animator under ThirdPersonModule
            if (!tpAnim && tpm)
            {
                tpAnim = tpm.GetComponentInChildren<Animator>();
            }

            Debug.Log($"Found: charRootAnim={charRootAnim!=null}, fpCam={fpCam!=null}, fpAnimator={fpAnimator!=null}, " +
                $"feelMgrs={feelMgrs.Count}, charBhv={characterBhv!=null}, fpSMR={fpSMR!=null}, tpAnim={tpAnim!=null}");

            // ── STEP 7: WIRE ALL PlayerViewManager instances (use GetComponents, not GetComponent) ──
            foreach (var viewMgr in root.GetComponents(T("PlayerViewManager")))
            {
                if (!viewMgr) continue;
                var so = new SerializedObject(viewMgr);
                SetProp(so, "thirdPersonModule", tpm?.gameObject);
                SetProp(so, "firstPersonModule", fpm?.gameObject);
                if (fpCam) SetProp(so, "fpCamera", fpCam);
                if (fpCam) SetProp(so, "fpCameraRoot", fpCam.transform.parent?.gameObject);
                if (tpm) { var geo = tpm.Find("Geometry"); if (geo) { var model = FindDeep(geo, "SK_Military_Survivalist"); if (model) SetProp(so, "thirdPersonModel", model.gameObject); } }
                so.ApplyModifiedPropertiesWithoutUndo();
            }

            // ── STEP 8: WIRE ALL PlayerAnimation instances ──
            foreach (var pa in root.GetComponents(T("PlayerAnimation")))
            {
                if (!pa) continue;
                var so = new SerializedObject(pa);
                if (tpAnim) SetProp(so, "thirdPersonAnimator", tpAnim);
                if (fpAnimator) SetProp(so, "firstPersonAnimator", fpAnimator);
                so.ApplyModifiedPropertiesWithoutUndo();
            }

            // ── STEP 9: WIRE ALL PlayerCombat instances ──
            foreach (var pc in root.GetComponents(T("PlayerCombat")))
            {
                if (!pc) continue;
                var so = new SerializedObject(pc);
                if (fpm) { var fp = FindDeep(fpm, "FirePoints"); if (fp) SetProp(so, "firstPersonMuzzle", fp); }
                if (tpm) { var tp = FindDeep(tpm, "FirePoints"); if (!tp) tp = FindDeep(tpm, "thirdPersonMuzzle"); if (tp) SetProp(so, "thirdPersonMuzzle", tp); }
                var bullet = AssetDatabase.LoadAssetAtPath<GameObject>("Assets/Scripts/Infima Games/Low Poly Shooter Pack/Prefabs/Projectiles/P_LPSP_PROJ_Bullet_01.prefab");
                var hit = AssetDatabase.LoadAssetAtPath<GameObject>("Assets/Scripts/Infima Games/Low Poly Shooter Pack/Prefabs/Effects/Impacts/P_IMP_Concrete.prefab");
                var flash = AssetDatabase.LoadAssetAtPath<GameObject>("Assets/Scripts/Infima Games/Low Poly Shooter Pack/Prefabs/Effects/Particles/P_LPSP_WEP_Flash.prefab");
                if (bullet) SetProp(so, "BulletPrefab", bullet);
                if (hit) SetProp(so, "HitEffect", hit);
                if (flash) SetProp(so, "MuzzleFlash", flash);
                so.ApplyModifiedPropertiesWithoutUndo();
            }

            // ── STEP 10: WIRE NetworkAnimator ──
            var netAnim = root.GetComponent<Mirror.NetworkAnimator>();
            if (netAnim && tpAnim)
            {
                var so = new SerializedObject(netAnim);
                so.FindProperty("animator").objectReferenceValue = tpAnim;
                so.ApplyModifiedPropertiesWithoutUndo();
            }

            // ── STEP 11: WIRE ALL FPCharacterAdapter instances ──
            foreach (var adapter in root.GetComponentsInChildren(T("FPCharacterAdapter"), true))
            {
                if (!adapter) continue;
                var so = new SerializedObject(adapter);
                SetProp(so, "playerState", root.GetComponent(T("PlayerState")));
                SetProp(so, "playerMovement", root.GetComponent(T("PlayerMovement")));
                SetProp(so, "playerCombat", root.GetComponent(T("PlayerCombat")));
                SetProp(so, "playerView", root.GetComponent(T("PlayerViewManager")));
                SetProp(so, "playerInput", root.GetComponent(T("StarterAssets.StarterAssetsInputs")));
                if (fpCam) SetProp(so, "fpWorldCamera", fpCam);
                if (fpWeaponCam) SetProp(so, "fpWeaponCamera", fpWeaponCam);
                so.ApplyModifiedPropertiesWithoutUndo();
            }

            // ── STEP 12: WIRE ALL FPMovementAdapter instances ──
            foreach (var adapter in root.GetComponentsInChildren(T("FPMovementAdapter"), true))
            {
                if (!adapter) continue;
                var so = new SerializedObject(adapter);
                SetProp(so, "playerMovement", root.GetComponent(T("PlayerMovement")));
                so.ApplyModifiedPropertiesWithoutUndo();
            }

            // ── STEP 13: WIRE ALL FeelManager instances ──
            var feelPreset = AssetDatabase.LoadAssetAtPath<ScriptableObject>(
                "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Data/Feels/SO_FP_Default.asset");
            foreach (var fm in feelMgrs)
            {
                if (!fm || !feelPreset) continue;
                var so = new SerializedObject(fm);
                var prop = so.FindProperty("preset");
                if (prop != null && prop.objectReferenceValue == null)
                {
                    prop.objectReferenceValue = feelPreset;
                    so.ApplyModifiedPropertiesWithoutUndo();
                }
            }
            Debug.Log($"Wired preset on {feelMgrs.Count} FeelManager(s)");

            // ── STEP 14: WIRE ALL Motion components on ALL layers ──
            WireAllMotion(instance.transform, feelMgrs.Count > 0 ? feelMgrs[0] : null, characterBhv, fpAnimator, inventoryBhv);
            if (charRootMotion) WireAllMotion(charRootMotion, feelMgrs.Count > 0 ? feelMgrs[0] : null, characterBhv, fpAnimator, inventoryBhv);
            if (ikHandGun) WireAllMotion(ikHandGun, feelMgrs.Count > 0 ? feelMgrs[0] : null, characterBhv, fpAnimator, inventoryBhv);

            // ── STEP 15: WIRE FP Animator (Avatar + Controller) ──
            if (fpAnimator)
            {
                var so = new SerializedObject(fpAnimator);
                if (!fpAnimator.runtimeAnimatorController)
                {
                    var ctrl = AssetDatabase.LoadAssetAtPath<RuntimeAnimatorController>(
                        "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Animators/Character/AC_LPSP_PCH.controller");
                    if (ctrl) { so.FindProperty("m_Controller").objectReferenceValue = ctrl; Debug.Log("Set FP Animator Controller"); }
                }
                if (!fpAnimator.avatar)
                {
                    var avatars = AssetDatabase.LoadAllAssetsAtPath(
                        "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Art/Meshes/Character/SK_FP_CH_Default_Root.fbx");
                    foreach (var a in avatars)
                        if (a is Avatar av) { so.FindProperty("m_Avatar").objectReferenceValue = av; Debug.Log("Set FP Animator Avatar"); break; }
                }
                so.ApplyModifiedPropertiesWithoutUndo();
            }

            // ── STEP 16: WIRE FP_CharacterMesh SkinnedMeshRenderer ──
            if (fpSMR)
            {
                var so = new SerializedObject(fpSMR);
                if (!fpSMR.sharedMesh)
                {
                    var objs = AssetDatabase.LoadAllAssetsAtPath(
                        "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Art/Meshes/Character/SK_FP_CH_Default_Root.fbx");
                    foreach (var o in objs)
                        if (o is Mesh m) { so.FindProperty("m_Mesh").objectReferenceValue = m; Debug.Log("Set FP_CharacterMesh mesh"); break; }
                }
                if (fpSMR.sharedMaterial == null || fpSMR.sharedMaterials.Length == 0 || fpSMR.sharedMaterials[0] == null)
                {
                    var mat = AssetDatabase.LoadAssetAtPath<Material>(
                        "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Art/Materials/Character/FP/M_FP_Camo_001_001.mat");
                    if (mat) { fpSMR.sharedMaterial = mat; Debug.Log("Set FP_CharacterMesh material"); }
                }
                if (fpSMR.rootBone == null && armature)
                {
                    var rootBone = FindDeep(armature, "root");
                    if (rootBone) { so.FindProperty("m_RootBone").objectReferenceValue = rootBone; Debug.Log("Set FP_CharacterMesh rootBone"); }
                }
                so.ApplyModifiedPropertiesWithoutUndo();
            }

            // ── STEP 17: Final positioning ──
            fpCharRoot.localPosition = Vector3.zero;
            fpm.gameObject.SetActive(false); // 3P is default mode

            // ── STEP 18: Save ──
            PrefabUtility.SaveAsPrefabAsset(root, Player2ViewPath);
            AssetDatabase.SaveAssets();
            AssetDatabase.Refresh();
            Debug.Log("=== CompletePlayer2ViewSetup DONE ===");
            EditorUtility.DisplayDialog("Done", "Player2View fully repaired.\n\nCheck Console for details.", "OK");
        }
        finally
        {
            PrefabUtility.UnloadPrefabContents(root);
        }
    }

    [MenuItem("Tools/Complete Player2View Setup (One-Shot)", true)]
    public static bool Validate() =>
        AssetDatabase.LoadAssetAtPath<GameObject>(Player2ViewPath) != null &&
        AssetDatabase.LoadAssetAtPath<GameObject>(FPPrefabPath) != null;

    // ── HELPERS ──

    private static void SetProp(SerializedObject so, string field, Object val)
    {
        if (!val) return;
        var p = so.FindProperty(field);
        if (p != null && p.propertyType == SerializedPropertyType.ObjectReference)
            p.objectReferenceValue = val;
    }

    private static Camera FindCamera(Transform root)
    {
        foreach (var cam in root.GetComponentsInChildren<Camera>(true))
            if (cam.CompareTag("MainCamera")) return cam;
        return root.GetComponentInChildren<Camera>(true);
    }

    private static Camera FindWeaponCamera(Transform root)
    {
        foreach (var cam in root.GetComponentsInChildren<Camera>(true))
            if (!cam.CompareTag("MainCamera") && cam.depth > 0) return cam;
        return null;
    }

    private static void WireAllMotion(Transform parent, Component feelMgr, Component charBhv, Animator anim, Component invBhv)
    {
        if (!parent) return;
        int wired = 0;
        foreach (var mb in parent.GetComponentsInChildren<MonoBehaviour>(true))
        {
            if (!mb) continue;
            string n = mb.GetType().Name;
            if (!n.Contains("Motion") && n != "MotionApplier") continue;

            var so = new SerializedObject(mb);
            if (feelMgr) SetProp(so, "feelManager", feelMgr);
            if (charBhv) SetProp(so, "characterBehaviour", charBhv);
            if (anim) SetProp(so, "characterAnimator", anim);
            if (invBhv) SetProp(so, "inventoryBehaviour", invBhv);
            so.ApplyModifiedPropertiesWithoutUndo();
            wired++;
        }
        if (wired > 0) Debug.Log($"Wired {wired} Motion components under {parent.name}");
    }

    private static void UnpackAll(GameObject root)
    {
        for (int i = 0; i < 30; i++)
        {
            GameObject target = null;
            foreach (var t in root.GetComponentsInChildren<Transform>(true))
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

    private static Transform FindDeep(Transform parent, string name)
    {
        if (!parent) return null;
        foreach (Transform child in parent)
        {
            if (child.name == name) return child;
            var f = FindDeep(child, name);
            if (f != null) return f;
        }
        return null;
    }
}
