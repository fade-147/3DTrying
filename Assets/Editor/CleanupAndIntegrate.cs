using UnityEngine;
using UnityEditor;
using System.Collections.Generic;
using System.IO;

/// <summary>
/// One-shot: Clean up duplicate FP skeletons and properly integrate the LPSP rig.
/// Run: Tools > Clean Duplicates & Fix Player2View
/// </summary>
public class CleanupAndIntegrate
{
    private const string Player2ViewPath = "Assets/Scripts/Prefab/Player2View.prefab";
    private const string FPPrefabPath = "Assets/Scripts/Infima Games/Low Poly Shooter Pack/Prefabs/P_LPSP_FP_CH.prefab";

    [MenuItem("Tools/Clean Duplicates & Fix Player2View")]
    public static void Run()
    {
        GameObject playerRoot = PrefabUtility.LoadPrefabContents(Player2ViewPath);
        if (!playerRoot) return;

        try
        {
            Transform fpm = playerRoot.transform.Find("FirstPersonModule");
            Transform tpm = playerRoot.transform.Find("ThirdPersonModule");
            if (!fpm) { Debug.LogError("FirstPersonModule not found"); return; }

            // === STEP 1: Clean ALL children from FP_CharacterRoot ===
            Transform fpCharRoot = fpm.Find("FP_CharacterRoot");
            if (!fpCharRoot)
            {
                fpCharRoot = new GameObject("FP_CharacterRoot").transform;
                fpCharRoot.SetParent(fpm);
                fpCharRoot.localPosition = new Vector3(0, 1.8f, 0);
                Debug.Log("Created FP_CharacterRoot");
            }
            else
            {
                // Delete ALL existing children
                var allChildren = new List<Transform>();
                foreach (Transform child in fpCharRoot)
                    allChildren.Add(child);
                foreach (var child in allChildren)
                    Object.DestroyImmediate(child.gameObject, true);
                Debug.Log($"Cleaned {allChildren.Count} objects from FP_CharacterRoot");
            }

            // Keep FP_Weapons and FP_CharacterMesh under FirstPersonModule
            // but clean any old duplicates
            var fpmChildren = new List<Transform>();
            foreach (Transform child in fpm)
            {
                if (child.name != "FP_CharacterRoot" &&
                    child.name != "FP_Weapons" &&
                    child.name != "FP_CharacterMesh")
                {
                    fpmChildren.Add(child);
                }
            }
            foreach (var child in fpmChildren)
                Object.DestroyImmediate(child.gameObject, true);
            if (fpmChildren.Count > 0)
                Debug.Log($"Removed {fpmChildren.Count} extra objects from FirstPersonModule");

            // === STEP 2: Remove old FP bones from 3P skeleton ===
            // Old FP bones (lowercase naming) are mixed into the 3P skeleton
            // They're under ThirdPersonModule > Skeleton or Geometry
            RemoveOldFPBones(playerRoot.transform);

            // === STEP 3: Instantiate fresh LPSP FP_CH into FP_CharacterRoot ===
            GameObject fpPrefab = AssetDatabase.LoadAssetAtPath<GameObject>(FPPrefabPath);
            if (fpPrefab)
            {
                GameObject instance = PrefabUtility.InstantiatePrefab(fpPrefab, fpCharRoot) as GameObject;
                if (instance)
                {
                    instance.name = "LPSP_FP_Rig";
                    instance.transform.localPosition = Vector3.zero;
                    instance.transform.localRotation = Quaternion.identity;

                    // Unpack
                    UnpackDeep(instance);

                    // Remove LPSP input components (conflict with StarterAssets.inputactions)
                    var toRemove = new List<Component>();
                    string[] conflictNames = { "CrouchingInput", "LeaningInput", "LowerWeapon", "LaserToggleInput" };
                    foreach (var mb in instance.GetComponentsInChildren<MonoBehaviour>(true))
                    {
                        if (!mb) continue;
                        foreach (string cn in conflictNames)
                            if (mb.GetType().Name == cn) { toRemove.Add(mb); break; }
                    }
                    foreach (var c in toRemove) Object.DestroyImmediate(c, true);
                    Debug.Log($"Removed {toRemove.Count} conflicting LPSP input components");

                    // Remove ALL missing MonoBehaviours (scripts that don't exist in this project)
                    int missingCleaned = 0;
                    foreach (var t in instance.GetComponentsInChildren<Transform>(true))
                    {
                        if (!t) continue;
                        int missing = GameObjectUtility.GetMonoBehavioursWithMissingScriptCount(t.gameObject);
                        if (missing > 0)
                        {
                            GameObjectUtility.RemoveMonoBehavioursWithMissingScript(t.gameObject);
                            missingCleaned += missing;
                        }
                    }
                    Debug.Log($"Cleaned {missingCleaned} missing MonoBehaviour(s) from LPSP_FP_Rig");

                    Debug.Log("Integrated LPSP FP Rig");
                }
            }
            else
            {
                Debug.LogError("FP_CH prefab not found at: " + FPPrefabPath);
            }

            // === STEP 4: Wire up PlayerViewManager camera reference ===
            var viewMgr = playerRoot.GetComponent(System.Type.GetType("PlayerViewManager, HotUpdate"));
            if (viewMgr != null)
            {
                Camera fpCam = FindDeep(fpm, "FP_Camera")?.GetComponent<Camera>();
                // The actual camera might be under SOCKET_Camera > Camera
                if (!fpCam)
                {
                    var camTransform = FindDeep(fpm, "Camera");
                    if (camTransform) fpCam = camTransform.GetComponent<Camera>();
                }
                if (fpCam)
                {
                    SerializedObject so = new SerializedObject(viewMgr);
                    var prop = so.FindProperty("fpCamera");
                    if (prop != null) { prop.objectReferenceValue = fpCam; so.ApplyModifiedPropertiesWithoutUndo(); }
                    Debug.Log("Wired fpCamera reference");
                }
            }

            // === STEP 5: Wire FPCharacterAdapter fpWorldCamera ===
            var adapter = fpCharRoot.GetComponent(System.Type.GetType("FPCharacterAdapter, HotUpdate"));
            if (adapter != null)
            {
                Camera fpCam = FindDeep(fpm, "Camera")?.GetComponent<Camera>();
                if (fpCam)
                {
                    SerializedObject so = new SerializedObject(adapter);
                    var prop = so.FindProperty("fpWorldCamera");
                    if (prop != null) { prop.objectReferenceValue = fpCam; so.ApplyModifiedPropertiesWithoutUndo(); }
                }
            }

            // Fix 1: FP_CharacterRoot at Y=0 (LPSP rig has its own Y=1.8 offset internally)
            fpCharRoot.localPosition = Vector3.zero;
            // Fix 2: FirstPersonModule starts inactive (3P is default mode)
            fpm.gameObject.SetActive(false);

            PrefabUtility.SaveAsPrefabAsset(playerRoot, Player2ViewPath);
            Debug.Log("Player2View cleaned and rebuilt successfully!");
        }
        finally
        {
            PrefabUtility.UnloadPrefabContents(playerRoot);
        }

        AssetDatabase.SaveAssets();
        AssetDatabase.Refresh();
        EditorUtility.DisplayDialog("Done", "Player2View cleaned and LPSP rig integrated.", "OK");
    }

    [MenuItem("Tools/Clean Duplicates & Fix Player2View", true)]
    public static bool Validate() =>
        AssetDatabase.LoadAssetAtPath<GameObject>(Player2ViewPath) != null;

    // ========================================
    // Remove old FP bones from 3P skeleton
    // ========================================
    private static void RemoveOldFPBones(Transform root)
    {
        // FP bones use lowercase: hand_l, lowerarm_l, calf_l, etc.
        // 3P bones use PascalCase: Left_Hand, Right_LowerLeg, etc.
        // Remove FP-style bones that are attached to the 3P skeleton

        string[] fpPatterns = {
            "hand_l", "hand_r", "hand_l_holder",
            "lowerarm_l", "lowerarm_r", "upperarm_l", "upperarm_r",
            "clavicle_l", "clavicle_r",
            "calf_l", "calf_r", "foot_l", "foot_r", "ball_l", "ball_r",
            "thigh_l", "thigh_r", "neck_01", "head",
            "spine_01", "spine_02", "spine_03", "pelvis", "root",
            "thumb_01_l", "thumb_02_l", "thumb_03_l",
            "thumb_01_r", "thumb_02_r", "thumb_03_r",
            "index_01_l", "index_02_l", "index_03_l",
            "index_01_r", "index_02_r", "index_03_r",
            "middle_01_l", "middle_02_l", "middle_03_l",
            "middle_01_r", "middle_02_r", "middle_03_r",
            "ring_01_l", "ring_02_l", "ring_03_l",
            "ring_01_r", "ring_02_r", "ring_03_r",
            "pinky_01_l", "pinky_02_l", "pinky_03_l",
            "pinky_01_r", "pinky_02_r", "pinky_03_r",
            "lowerarm_twist_01_l", "lowerarm_twist_01_r",
            "upperarm_twist_01_l", "upperarm_twist_01_r",
            "calf_twist_01_l", "calf_twist_01_r",
            "thigh_twist_01_l", "thigh_twist_01_r",
            "ik_hand_root", "ik_hand_gun", "ik_hand_l", "ik_hand_r",
            "ik_foot_root", "ik_foot_l", "ik_foot_r",
            "SOCKET_Camera", "Effector Hand Left", "Effector Hand Right",
            "hand_l_holder",
        };

        // Collect all GOs to remove (don't modify during iteration)
        var toRemove = new List<GameObject>();
        foreach (var t in root.GetComponentsInChildren<Transform>(true))
        {
            if (!t) continue;
            string name = t.name;

            // Skip GOs inside FirstPersonModule - those are the new rig, don't touch
            Transform check = t;
            bool inFPM = false;
            while (check != null && check != root)
            {
                if (check.name == "FirstPersonModule") { inFPM = true; break; }
                check = check.parent;
            }
            if (inFPM) continue;

            // Check if this looks like an FP bone
            foreach (string pattern in fpPatterns)
            {
                if (name == pattern)
                {
                    toRemove.Add(t.gameObject);
                    break;
                }
            }
        }

        foreach (var go in toRemove)
            Object.DestroyImmediate(go, true);

        Debug.Log($"Removed {toRemove.Count} old FP bones from 3P skeleton");
    }

    // ========================================
    // Unpack nested instances safely
    // ========================================
    private static void UnpackDeep(GameObject root)
    {
        for (int i = 0; i < 20; i++)
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
            PrefabUtility.UnpackPrefabInstance(target, PrefabUnpackMode.Completely,
                InteractionMode.AutomatedAction);
        }
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
