using UnityEngine;
using UnityEditor;
using System.Collections.Generic;
using System.Linq;
using System.IO;

/// <summary>
/// Fixes the imported P_LPSP_FP_CH.prefab from FPSTrying:
/// 1. Remaps old script GUIDs to new 3Dgame GUIDs
/// 2. Removes unwanted components (Character, Movement, CanvasSpawner, TimeHandler, PlayerInput)
/// 3. Strips nested inventory (weapons handled separately)
/// 4. Integrates into Player2View's FirstPersonModule
/// Run: Tools > Fix Imported LPSP Prefab & Integrate
/// </summary>
public class FixImportedLPSPPrefab
{
    private const string ImportedPrefabPath = "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Prefabs/P_LPSP_FP_CH.prefab";
    private const string Player2ViewPath = "Assets/Scripts/Prefab/Player2View.prefab";
    private const string SourceProjectPath = "D:/unityxinxiangmu/FPSTrying";

    // Old GUID (FPSTrying) -> New GUID (3Dgame) mapping
    private static readonly Dictionary<string, string> GuidMap = new Dictionary<string, string>
    {
        // Animation
        {"0adbdf8319816044786da04710105e40", "493d6a7736241594da32e7e7f8b4272e"}, // CharacterAnimationEventHandler
        {"942eea6ffcf143f6bfd02682ecc2e4c6", "42342a0215450234ab5a6ccd9fe83eae"}, // PlaySoundBehaviour
        // Camera
        {"8f3bf1a7fb805fa4f8ed6ff4960ecd38", "f5d7238510ce5fc499ca7198ad10af65"}, // CameraHeight
        {"a74379b44be369043afd8160e1b39c49", "1c81ece855eabef4d9fa7724167bb8a8"}, // CameraLook
        // Character
        {"d66db7ceb69749299abd18d1dd182814", "34ef7c117a67aa040831e5e666950453"}, // CharacterBehaviour
        {"ef46ecb879c940f3bd09e457dd5a4e8a", "6cdc8d93992fe104ba72c2011a09cda8"}, // CharacterKinematics
        {"068e9f8c7fb4bb14fabe13486f25a118", "4e76ead28227dd3498eaa9650ccf25ad"}, // CrouchingInput
        {"4755222491b08b34ca9475bf410efdaa", "7715cbde426d2a845a4e62c56bf6d6c5"}, // FootstepPlayer
        {"1aa67abca7a8b344ca4481c000eb9afa", "dd60afdc32451ea4793adeb31d7eaaca"}, // InventoryBehaviour
        {"2b28c8f6095448fc8a7a24e8388c12f5", "90972091f3c470a42b716bd4e8212037"}, // LeaningInput
        {"080fbe381d204f9bb36b73dbe7986f5b", "5d43d343156f0af4a904f6aee7718094"}, // LowerWeapon
        {"d2103020a6ec413c9fbf35e8a39da54b", "40fe36d585a177a4fa456fc67dca52ab"}, // MovementBehaviour
        {"8aa9dc031c1147649bc156eadca1dd05", "f572bae8bcc89d84a93a27a449bb9895"}, // WallAvoidance
        // Motion
        {"e0767d3599ac5134d8cccc1585251bf5", "0178b9a9583a23c4e90305f21c4af6b5"}, // Feel
        {"ec45c68f109987346815a1c506c890c1", "31b335106873aac4188aec1bd1caf2b7"}, // FeelManager
        {"8f68d77734f34842a18d41eff2585ed5", "d4562ea6eb71c934eb55fd4fd8ffc43e"}, // FeelState
        {"6d9089efba93466da58495b9a0cd5ebb", "d9c2551611383454192d98877d11014b"}, // JumpMotion
        {"0f9894694a504bb2959a4349864484d5", "7e5ce6fb831ba2049ac877029723de1d"}, // LandMotion
        {"a4ae7b4d407e4775a8b1be4f7ea56751", "2b3e30be1e1d625438d60d15f1584096"}, // LeaningMotion
        {"80ef32f4e13342f0b612221cde4a9128", "8fd66e9591a36c740b7deb9cea5291a7"}, // LoweredMotion
        {"7b3925ade3e612345ab594a0f866ac7f", "f1c69e2f4f66b28439474a0051f1e06a"}, // Motion
        {"ca784528c15a1994cb6c30bc8aac364b", "e92efc65be73dd84894453d579f82806"}, // MotionApplier
        {"ec532924a19fc964b9180d4ed131beeb", "559da6129186d6247b66a495a5c1ba80"}, // OffsetMotion
        {"5fac31dadcaeecc48bb8a5e0e62329c3", "c44abdb8486b2704297093d5941a535b"}, // RecoilMotion
        {"05347275cfef4379abe461ce98a99921", "9a898fd945d13a74aaeb106399abe6c4"}, // SwayDirection
        {"ded5e0b19c75d8c498ab4927864f57c1", "033ae33921423ea4996b32a094d448c0"}, // SwayMotion
        // Scriptable
        {"2cdbbec5bb3d96b468183b8e76de3af7", "0719387d5de3d1246a4071f13011ec63"}, // FeelPreset
        {"85a34293309840ca976315e7ad199d77", "edfb324be3f37f8499d810f38032d706"}, // FeelStateOffset
        {"b9aed70918114183b734ff5a1b5f4593", "a857e9a096dc25540b869cbd7b5463f7"}, // ItemOffsets
        {"b628253a8cb84ba0be750d5c311a03dc", "784b554cc19d6ee41a58447f197fc1ba"}, // LeaningData
        {"82217a2ba9844e9a965cd6dac840dd89", "bc29e2280f2197147bcd99b3f40181a0"}, // LowerData
        {"355e4f9f697079548abc2f1f2b33b97f", "1b61602cec33b2846835c5476274a64f"}, // RecoilData
        {"c5c9e5eb469b4330a32275c51227490e", "bec30a91212457e478bcc89be03ff02b"}, // SwayData
        {"c34a6f7f241e40358d09986ebf95c29f", "eab762cb8bb7bd94ab5472dd1ea2c0e7"}, // SwayType
        // Services
        {"26f9249bcb324948a7ba3a6ae3c7b39b", "92a2f73e8bb36fc45a2de8c7acecc578"}, // AudioManagerService
        {"b92980d55c8c4ddf878b44632a03c861", "67872f394a4b7114790f533ab994bb35"}, // AudioSettings
        {"40854f0b12351f04bba05498305d4aad", "b8aaac0cce1b79044baffde2d31e27f8"}, // Bootstraper
        {"4c9c93e8da8b94646bab00b7b56eb376", "79b82d07c184bc647bfc131153e81c45"}, // GameModeService
        {"0bb88bad134445c88b7b26f1eaf374d1", "c8e2b4a1ea0830c4db4c9e1b9be880ef"}, // IAudioManagerService
        {"e7cf32c7a3b1df642947955bc9a3e157", "4aa77ffcd3aafc54b842513be98a1a81"}, // IGameModeService
        {"07c381ae858298748ad015b94f85311b", "488e4b5e5a4e1b64aa13f92eff88ae00"}, // IGameService
        {"d089545b7f5e23a44abf814edd1b4cb8", "39391d109265045498e8f6f9eccb37dd"}, // ServiceLocator
        // Utilities
        {"a1094e2a6ba108f4cabfab0be6eb6b72", "c25d94261a362cc429dbc4a2bce0282f"}, // AHashes
        {"4acf2ef2dce357c409a72b767c006b1d", "d79543546aa05f3489382ecc8894c128"}, // CopyTransform
        {"e0e1d1e2102c4990a00ed6b4662e5c09", "57408aa0ffd2a2a469be94c551361d49"}, // FaceCamera
        {"938c92c7721b48aab8f2a5c0012d180e", "76c1dcbbbbe2e244d844995b6848b9a2"}, // Offsets
        {"501cab9e129e47fcb7315e9916792ef3", "3191d39994248cb45906e5b88df36b8e"}, // UtilitiesArrays
        // Weapons (abstract behaviours)
        {"38b50e1c19f94b33b387b8713cf96ea0", "04a8987c5f9a7ae4f9627af2ff1de7ab"}, // GripBehaviour
        {"3af6dec5da9605b47aecd69b9858325c", "19a28fa56ac8ea44bbdb9bf0b95ff8ac"}, // ItemAnimationData
        {"02215c63d7254196a13bd17f30b68eca", "7f5760a4adaa6074d9575d2c9bfd8420"}, // ItemAnimationDataBehaviour
        {"257fdfb96c464d6fa2d6be88c524ff9b", "31160b436b767bf40bf6bf38244e7ce5"}, // LaserBehaviour
        {"397683da482d4cadbee5c6fa60235f67", "1ddb15e777b7044488462b18e0550d2b"}, // MagazineBehaviour
        {"2a92673477ac4300b71d282db4d37e14", "42522c53fde61bd48805ee5791739419"}, // MuzzleBehaviour
        {"96221029ccbd41cd93a0158756c61cd4", "ee5cddf0d60e5d44d81ab7aba0ac1448"}, // ScopeBehaviour
        {"903f4a9e79084198b9cecfa8509b35d4", "fb9c00bb83e04c94ba5002f4fccd96f8"}, // WeaponAttachmentManagerBehaviour
        {"ddd5efe58878f93448e0fc3fdca21f9c", "3913d6f8c75a97d4ca2c495883f1f015"}, // WeaponBehaviour
    };

    // GUIDs of scripts to REMOVE from the imported prefab (replaced by our new Player scripts)
    private static readonly HashSet<string> RemoveGuids = new HashSet<string>
    {
        "cedea47162792a74cb9ec77109d20e72", // Character.cs
        "1ba9a63e484e8f142b3b13cfd976e290", // Movement.cs
        "c2bd74ba84b94cd4bbb9b189a5e89fba", // CanvasSpawner.cs
        "e55e7a428d82413e839adb23b9351c98", // TimeHandler.cs
        "62899f850307741f2a39c98a8b639597", // PlayerInput (Unity Input System)
    };

    [MenuItem("Tools/Fix ALL Imported LPSP Prefabs && Integrate")]
    public static void RunAll()
    {
        if (!EditorUtility.DisplayDialog("Fix ALL LPSP Prefabs && Integrate",
            "This will:\n" +
            "1. Fix script GUIDs on ALL imported LPSP prefabs\n" +
            "2. Remove Character/Movement/CanvasSpawner/TimeHandler/PlayerInput from FP_CH\n" +
            "3. Integrate FP_CH armature into Player2View\n\n" +
            "Continue?", "Yes", "Cancel"))
            return;

        // Only fix essential prefabs - skip Casings/Damageables/Effects/Demo/Interface
        string[] essentialPaths = {
            "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Prefabs/P_LPSP_FP_CH.prefab",
            "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Prefabs/Weapons/P_LPSP_Inventory.prefab",
        };
        // Also include all weapon prefabs
        string[] weaponPrefabs = AssetDatabase.FindAssets("t:Prefab", new[] { "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Prefabs/Weapons" });
        var allPaths = new List<string>(essentialPaths);
        foreach (string g in weaponPrefabs)
        {
            string p = AssetDatabase.GUIDToAssetPath(g);
            if (!allPaths.Contains(p)) allPaths.Add(p);
        }

        int fixedCount = 0;
        foreach (string path in allPaths)
        {
            if (File.Exists(path.Replace("Assets", Application.dataPath))) // verify exists
            {
                FixPrefab(path);
                fixedCount++;
            }
        }
        Debug.Log($"Fixed {fixedCount} prefabs (FP_CH + Inventory + Weapons only)");

        // Now integrate FP_CH into Player2View
        IntegrateIntoPlayer2View();

        AssetDatabase.SaveAssets();
        AssetDatabase.Refresh();

        EditorUtility.DisplayDialog("Done",
            $"Fixed {fixedCount} prefabs and integrated armature.\n\n" +
            "Check Player2View > FirstPersonModule > FP_CharacterRoot.", "OK");
    }

    [MenuItem("Tools/Fix ALL Imported LPSP Prefabs && Integrate", true)]
    public static bool ValidateAll()
    {
        return AssetDatabase.LoadAssetAtPath<GameObject>(ImportedPrefabPath) != null
            && AssetDatabase.LoadAssetAtPath<GameObject>(Player2ViewPath) != null;
    }

    /// <summary>
    /// Copy FP_CH, Inventory, and all weapon prefabs from FPSTrying source to current project.
    /// This ensures we always start from the pristine source with all components intact.
    /// </summary>
    public static void RestoreFromSource()
    {
        // Map: source relative path (from FPSTrying Assets) -> dest Unity asset path
        var restoreMap = new Dictionary<string, string>
        {
            { "Infima Games/Low Poly Shooter Pack/Prefabs/P_LPSP_FP_CH.prefab",
              ImportedPrefabPath },
            { "Infima Games/Low Poly Shooter Pack/Prefabs/Weapons/P_LPSP_Inventory.prefab",
              "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Prefabs/Weapons/P_LPSP_Inventory.prefab" },
        };

        // Also find all weapon prefabs from source
        string sourceWeaponsDir = Path.Combine(SourceProjectPath, "Assets/Infima Games/Low Poly Shooter Pack/Prefabs/Weapons");
        string destWeaponsDir = "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Prefabs/Weapons";

        if (Directory.Exists(sourceWeaponsDir))
        {
            foreach (string f in Directory.GetFiles(sourceWeaponsDir, "*.prefab"))
            {
                string relPath = f.Substring(SourceProjectPath.Length + "/Assets/Infima Games/Low Poly Shooter Pack/Prefabs/Weapons/".Length);
                string destKey = "Infima Games/Low Poly Shooter Pack/Prefabs/Weapons/" + relPath;
                string destAssetPath = "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Prefabs/Weapons/" + relPath;
                if (!restoreMap.ContainsKey(destKey))
                    restoreMap[destKey] = destAssetPath.Replace("\\", "/");
            }
            // NOTE: Do NOT copy .meta files — the existing project's .meta files
            // contain the correct asset GUIDs, and overwriting them would break references.
        }

        int restored = 0;
        foreach (var kvp in restoreMap)
        {
            string sourcePath = Path.Combine(SourceProjectPath, "Assets", kvp.Key);
            // kvp.Value is like "Assets/Scripts/...", convert to filesystem path
            string destFullPath = Path.Combine(Application.dataPath, kvp.Value.Substring("Assets/".Length));

            if (!File.Exists(sourcePath))
            {
                Debug.LogWarning($"[Restore] Source not found: {sourcePath}");
                continue;
            }

            // Ensure destination directory exists
            string destDir = Path.GetDirectoryName(destFullPath);
            if (!Directory.Exists(destDir))
                Directory.CreateDirectory(destDir);

            File.Copy(sourcePath, destFullPath, true);
            restored++;
        }

        AssetDatabase.Refresh();
        Debug.Log($"[Restore] Restored {restored} files from FPSTrying source");
    }

    /// <summary>
    /// Non-interactive version for batch mode / automated execution.
    /// Fixes GUIDs and integrates without showing dialogs.
    /// </summary>
    public static void RunAllNonInteractive()
    {
        // First restore FP_CH and weapon prefabs from FPSTrying source
        RestoreFromSource();

        string[] essentialPaths = {
            "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Prefabs/P_LPSP_FP_CH.prefab",
            "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Prefabs/Weapons/P_LPSP_Inventory.prefab",
        };
        string[] weaponPrefabs = AssetDatabase.FindAssets("t:Prefab", new[] { "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Prefabs/Weapons" });
        var allPaths = new List<string>(essentialPaths);
        foreach (string g in weaponPrefabs)
        {
            string p = AssetDatabase.GUIDToAssetPath(g);
            if (!allPaths.Contains(p)) allPaths.Add(p);
        }

        int fixedCount = 0;
        foreach (string path in allPaths)
        {
            if (File.Exists(path.Replace("Assets", Application.dataPath)))
            {
                FixPrefab(path);
                fixedCount++;
            }
        }
        Debug.Log($"[Batch] Fixed {fixedCount} prefabs (FP_CH + Inventory + Weapons only)");

        IntegrateIntoPlayer2View();
        AssetDatabase.SaveAssets();
        AssetDatabase.Refresh();
        Debug.Log("[Batch] FixImportedLPSPPrefab done.");
    }

    // Keep old menu item for backward compat
    [MenuItem("Tools/Fix Imported LPSP Prefab && Integrate")]
    public static void Run()
    {
        if (!AssetDatabase.LoadAssetAtPath<GameObject>(ImportedPrefabPath))
        {
            Debug.LogError("Imported P_LPSP_FP_CH.prefab not found at: " + ImportedPrefabPath);
            return;
        }

        if (!EditorUtility.DisplayDialog("Fix && Integrate LPSP Prefab",
            "This will:\n" +
            "1. Remap all old script GUIDs to new 3Dgame GUIDs\n" +
            "2. Remove Character/Movement/CanvasSpawner/TimeHandler/PlayerInput\n" +
            "3. Strip nested Inventory (weapons handled separately)\n" +
            "4. Integrate the fixed armature into Player2View\n\n" +
            "Continue?", "Yes", "Cancel"))
            return;

        // === STEP 1: Fix the imported FP_CH prefab ===
        FixPrefab(ImportedPrefabPath);

        // === STEP 2: Integrate into Player2View ===
        IntegrateIntoPlayer2View();

        AssetDatabase.SaveAssets();
        AssetDatabase.Refresh();

        EditorUtility.DisplayDialog("Done",
            "Imported prefab fixed and integrated.\n\n" +
            "Check Player2View > FirstPersonModule > FP_CharacterRoot.\n" +
            "The new armature should be there with all components remapped.\n\n" +
            "You may need to:\n" +
            "- Verify the Animator Avatar is set\n" +
            "- Configure FeelManager Preset reference", "OK");
    }

    [MenuItem("Tools/Fix Imported LPSP Prefab && Integrate", true)]
    public static bool Validate()
    {
        return AssetDatabase.LoadAssetAtPath<GameObject>(ImportedPrefabPath) != null
            && AssetDatabase.LoadAssetAtPath<GameObject>(Player2ViewPath) != null;
    }

    // ============================================================
    /// <summary>
    /// Fix a prefab by doing YAML-level GUID replacement BEFORE Unity loads it.
    /// This avoids the "missing script" problem where old-GUID components get
    /// cleaned before we have a chance to remap them.
    /// </summary>
    private static void FixPrefab(string path)
    {
        string fullPath = path.Replace("Assets", Application.dataPath);
        if (!File.Exists(fullPath))
        {
            Debug.LogWarning($"Prefab file not found: {fullPath}");
            return;
        }

        // === PHASE 0: YAML-level GUID replacement in m_Script lines ONLY ===
        // Only replace GUIDs in "m_Script: {fileID: ..., guid: <old>, type: 3}" lines
        // to avoid corrupting asset references (material, mesh, etc.)
        string yaml = File.ReadAllText(fullPath);
        int yamlReplacements = 0;
        string originalYaml = yaml;

        foreach (var kvp in GuidMap)
        {
            string oldGuid = kvp.Key;
            string newGuid = kvp.Value;
            // Only replace in "guid: <old>," patterns within m_Script blocks
            string pattern = "guid: " + oldGuid + ",";
            string replacement = "guid: " + newGuid + ",";
            if (yaml.Contains(pattern))
            {
                yaml = yaml.Replace(pattern, replacement);
                yamlReplacements++;
            }
        }

        if (yaml != originalYaml)
        {
            File.WriteAllText(fullPath, yaml);
            AssetDatabase.ImportAsset(path, ImportAssetOptions.ForceUpdate);
            Debug.Log($"[YAML] {yamlReplacements} m_Script GUIDs replaced in {Path.GetFileName(path)}");
        }

        // === PHASE 1: Load prefab (now with correct GUIDs), clean up missing/unwanted ===
        GameObject prefab;
        try
        {
            prefab = PrefabUtility.LoadPrefabContents(path);
        }
        catch (System.Exception e)
        {
            Debug.LogWarning($"Cannot load prefab {path}, skipping: {e.Message}");
            return;
        }

        if (!prefab) { Debug.LogWarning($"Failed to load prefab: {path}"); return; }

        int cleaned = 0, removedByType = 0;

        try
        {
            // Clean any missing MonoBehaviours (scripts that don't exist in this project)
            // This handles Character.cs, Movement.cs, CanvasSpawner.cs, TimeHandler.cs
            foreach (var go in prefab.GetComponentsInChildren<Transform>(true))
            {
                if (!go) continue;
                int missing = GameObjectUtility.GetMonoBehavioursWithMissingScriptCount(go.gameObject);
                if (missing > 0)
                {
                    GameObjectUtility.RemoveMonoBehavioursWithMissingScript(go.gameObject);
                    cleaned += missing;
                }
            }

            // Remove specific unwanted components by type name
            // PlayerInput: replaced by StarterAssets
            // CrouchingInput, LeaningInput, LowerWeapon, LaserToggleInput: conflict with StarterAssets.inputactions
            string[] removeTypeNames = { "CrouchingInput", "LeaningInput", "LowerWeapon", "LaserToggleInput", "PlayerInput" };
            foreach (var mb in prefab.GetComponentsInChildren<MonoBehaviour>(true))
            {
                if (!mb) continue;
                foreach (string tn in removeTypeNames)
                {
                    if (mb.GetType().Name == tn)
                    {
                        Object.DestroyImmediate(mb, true);
                        removedByType++;
                        break;
                    }
                }
            }

            // Unpack nested prefab instances (keep ik_hand_gun, remove Inventory)
            var allTransforms = prefab.GetComponentsInChildren<Transform>(true);
            var processedRoots = new System.Collections.Generic.HashSet<GameObject>();
            foreach (var t in allTransforms)
            {
                if (!t) continue;
                var go = t.gameObject;
                if (!go) continue;
                if (!PrefabUtility.IsPartOfPrefabInstance(go)) continue;
                var root = PrefabUtility.GetNearestPrefabInstanceRoot(go);
                if (!root || processedRoots.Contains(root)) continue;
                processedRoots.Add(root);

                string name = root.name.ToLower();
                if (name.Contains("ik_hand_gun"))
                {
                    PrefabUtility.UnpackPrefabInstance(root,
                        PrefabUnpackMode.Completely, InteractionMode.AutomatedAction);
                    Debug.Log($"Unpacked {root.name}");
                }
                else if (name.Contains("inventory"))
                {
                    Object.DestroyImmediate(root, true);
                    Debug.Log($"Removed Inventory instance");
                }
            }

            PrefabUtility.SaveAsPrefabAsset(prefab, path);
            Debug.Log($"Fixed {Path.GetFileName(path)}: {cleaned} cleaned, {removedByType} removed-by-type, {yamlReplacements} YAML GUIDs remapped");
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"Error fixing {path}: {ex.Message}");
        }
        finally
        {
            PrefabUtility.UnloadPrefabContents(prefab);
        }
    }

    // ============================================================
    private static void IntegrateIntoPlayer2View()
    {
        GameObject playerRoot = PrefabUtility.LoadPrefabContents(Player2ViewPath);
        GameObject fpPrefab = AssetDatabase.LoadAssetAtPath<GameObject>(ImportedPrefabPath);
        if (!playerRoot || !fpPrefab) return;

        Transform fpm = playerRoot.transform.Find("FirstPersonModule");
        if (!fpm)
        {
            Debug.LogError("FirstPersonModule not found in Player2View");
            PrefabUtility.UnloadPrefabContents(playerRoot);
            return;
        }

        // Find or create FP_CharacterRoot
        Transform fpCharRoot = fpm.Find("FP_CharacterRoot");
        if (!fpCharRoot)
        {
            GameObject cr = new GameObject("FP_CharacterRoot");
            cr.transform.SetParent(fpm);
            cr.transform.localPosition = new Vector3(0, 1.8f, 0);
            fpCharRoot = cr.transform;
        }

        // Remove old FP bones that are inside FP_CharacterRoot (but keep FP_Motion_Body, FP_Camera_Root)
        var toRemove = new List<Transform>();
        foreach (Transform child in fpCharRoot)
        {
            string n = child.name.ToLower();
            // Keep motion body, camera root, and anything with "fp_" prefix
            if (n.Contains("motion") || n.Contains("camera") || n.StartsWith("fp_"))
                continue;
            toRemove.Add(child);
        }
        foreach (var t in toRemove)
        {
            // Only remove if it looks like the old skeleton
            if (t.name.Contains("Armature") || t.name.Contains("root") ||
                t.name.Contains("hand_") || t.name.Contains("spine") ||
                t.name.Contains("pelvis") || t.name.Contains("thigh"))
            {
                Object.DestroyImmediate(t.gameObject);
            }
        }
        Debug.Log($"Cleaned {toRemove.Count} old skeleton objects from FP_CharacterRoot");

        // Instantiate the fixed prefab directly into FP_CharacterRoot
        // The LPSP FP_CH prefab is self-contained with Animator, Motion, Armature, Camera
        // We keep it as-is rather than rearranging its internal hierarchy
        GameObject fpInstance = PrefabUtility.InstantiatePrefab(fpPrefab, fpCharRoot) as GameObject;
        if (!fpInstance)
        {
            Debug.LogError("Failed to instantiate LPSP prefab");
            PrefabUtility.UnloadPrefabContents(playerRoot);
            return;
        }

        fpInstance.name = "LPSP_FP_Rig";
        fpInstance.transform.localPosition = Vector3.zero;
        fpInstance.transform.localRotation = Quaternion.identity;

        // Unpack ALL nested prefab instances so the hierarchy is fully editable
        UnpackHelper.UnpackAll(fpInstance);

        // Remove our duplicate FP_Camera_Root since the LPSP rig has its own camera
        Transform fpCameraRoot = fpCharRoot.Find("FP_Camera_Root");
        if (fpCameraRoot)
        {
            // Keep the LPSP camera - remove our placeholder
            Object.DestroyImmediate(fpCameraRoot.gameObject);
        }

        // Remove our duplicate FP_Motion_Body since LPSP has Character Root Motion
        Transform fpMotionBody = fpCharRoot.Find("FP_Motion_Body");
        if (fpMotionBody)
        {
            Object.DestroyImmediate(fpMotionBody.gameObject);
        }

        // Copy SkinnedMeshRenderer from LPSP rig to our FP_CharacterMesh
        Transform charMesh = FindDeep(fpCharRoot, "Character Mesh");
        Transform fpCharMeshGO = fpm.Find("FP_CharacterMesh");
        if (charMesh && fpCharMeshGO)
        {
            SkinnedMeshRenderer oldSmr = charMesh.GetComponent<SkinnedMeshRenderer>();
            SkinnedMeshRenderer newSmr = fpCharMeshGO.GetComponent<SkinnedMeshRenderer>();
            if (!newSmr) newSmr = fpCharMeshGO.gameObject.AddComponent<SkinnedMeshRenderer>();
            if (oldSmr && newSmr)
            {
                newSmr.sharedMesh = oldSmr.sharedMesh;
                newSmr.sharedMaterial = oldSmr.sharedMaterial;
                newSmr.rootBone = oldSmr.rootBone;
                newSmr.bones = oldSmr.bones;
            }
        }

        Debug.Log("Integrated complete LPSP First Person Rig into FirstPersonModule");

        PrefabUtility.SaveAsPrefabAsset(playerRoot, Player2ViewPath);
        PrefabUtility.UnloadPrefabContents(playerRoot);
        Debug.Log("Integration complete!");
    }

    private static Transform FindDeep(Transform parent, string name)
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
