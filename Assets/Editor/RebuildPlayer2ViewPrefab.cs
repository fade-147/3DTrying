using UnityEngine;
using UnityEditor;
using System;

/// <summary>
/// Editor script to rebuild Player2View prefab structure.
/// Run from menu: Tools > Rebuild Player2View Prefab
/// </summary>
public class RebuildPlayer2ViewPrefab
{
    private const string PrefabPath = "Assets/Scripts/Prefab/Player2View.prefab";
    private const string Asm = "HotUpdate";

    private static Type T(string name) => Type.GetType(name + ", " + Asm);
    private static Component AddC(GameObject go, string name) { var t = T(name); return t != null ? go.AddComponent(t) : null; }

    [MenuItem("Tools/Rebuild Player2View Prefab")]
    public static void Rebuild()
    {
        if (AssetDatabase.LoadAssetAtPath<GameObject>(PrefabPath) == null)
        {
            Debug.LogError("Prefab not found: " + PrefabPath);
            return;
        }

        if (!EditorUtility.DisplayDialog("Rebuild Player2View Prefab",
            "This will modify the Player2View prefab structure.\nMake sure you have a backup!\n\nContinue?",
            "Yes", "Cancel"))
            return;

        // Use LoadPrefabContents for full write access
        GameObject root = PrefabUtility.LoadPrefabContents(PrefabPath);
        if (root == null) { Debug.LogError("Failed to load prefab"); return; }

        try
        {
            CreateThirdPersonModule(root);
            CreateFirstPersonModule(root);
            AddPlayerScripts(root);
            WireUpReferences(root);

            PrefabUtility.SaveAsPrefabAsset(root, PrefabPath);
            Debug.Log("Player2View prefab rebuilt successfully!");
        }
        catch (Exception ex)
        {
            Debug.LogError("Failed: " + ex.Message + "\n" + ex.StackTrace);
        }
        finally
        {
            PrefabUtility.UnloadPrefabContents(root);
        }

        AssetDatabase.SaveAssets();
        AssetDatabase.Refresh();
    }

    [MenuItem("Tools/Rebuild Player2View Prefab", true)]
    public static bool ValidateRebuild() => AssetDatabase.LoadAssetAtPath<GameObject>(PrefabPath) != null;

    // =========================================
    // Step 1: ThirdPersonModule
    // =========================================
    private static void CreateThirdPersonModule(GameObject root)
    {
        // Ensure ThirdPersonModule exists
        Transform tpm = root.transform.Find("ThirdPersonModule");
        if (tpm == null)
        {
            GameObject tpmGo = new GameObject("ThirdPersonModule");
            tpmGo.transform.SetParent(root.transform);
            tpmGo.transform.localPosition = Vector3.zero;
            tpmGo.transform.localRotation = Quaternion.identity;
            tpm = tpmGo.transform;
            Debug.Log("Created ThirdPersonModule");
        }

        // Move 3P children that are still under root directly
        string[] thirdPersonChildren = { "Geometry", "CinemachineCameraTarget" };
        foreach (string name in thirdPersonChildren)
        {
            Transform child = root.transform.Find(name);
            if (child == null) continue;

            // Skip if already under ThirdPersonModule
            if (child.parent == tpm)
            {
                Debug.Log(name + " already in ThirdPersonModule");
                continue;
            }

            // If child is part of a prefab instance, unpack it first
            if (PrefabUtility.IsPartOfPrefabInstance(child.gameObject))
            {
                GameObject instanceRoot = PrefabUtility.GetNearestPrefabInstanceRoot(child.gameObject);
                if (instanceRoot != null)
                {
                    PrefabUtility.UnpackPrefabInstance(instanceRoot,
                        PrefabUnpackMode.Completely, InteractionMode.AutomatedAction);
                    Debug.Log("Unpacked prefab instance containing " + name);
                }
            }

            // Now reparent
            if (child.parent == root.transform)
            {
                child.SetParent(tpm);
                Debug.Log("Moved " + name + " into ThirdPersonModule");
            }
            else
            {
                // Child might be deeper in the hierarchy, find and reparent
                Debug.LogWarning(name + " parent is not root, parent is: " + child.parent.name + ". Trying to reparent anyway.");
                child.SetParent(tpm);
            }
        }
    }

    // =========================================
    // Step 2: FirstPersonModule
    // =========================================
    private static void CreateFirstPersonModule(GameObject root)
    {
        Transform fpm = root.transform.Find("FirstPersonModule");
        if (fpm == null)
        {
            GameObject fpmGo = new GameObject("FirstPersonModule");
            fpmGo.transform.SetParent(root.transform);
            fpmGo.transform.localPosition = Vector3.zero;
            fpmGo.SetActive(false);
            fpm = fpmGo.transform;
        }

        // Only create children if they don't exist yet
        if (fpm.Find("FP_CharacterRoot") == null)
        {
            // -- FP_CharacterRoot --
            GameObject charRoot = new GameObject("FP_CharacterRoot");
            charRoot.transform.SetParent(fpm);
            charRoot.transform.localPosition = new Vector3(0, 1.8f, 0);

            // -- FP_Motion_Body --
            GameObject motionBody = new GameObject("FP_Motion_Body");
            motionBody.transform.SetParent(charRoot.transform);

            AddC(motionBody, "InfimaGames.LowPolyShooterPack.MotionApplier");
            AddC(motionBody, "InfimaGames.LowPolyShooterPack.SwayMotion");
            AddC(motionBody, "InfimaGames.LowPolyShooterPack.LeaningMotion");
            AddC(motionBody, "InfimaGames.LowPolyShooterPack.JumpMotion");
            AddC(motionBody, "InfimaGames.LowPolyShooterPack.LandMotion");

            // -- Dual Camera --
            GameObject camRoot = new GameObject("FP_Camera_Root");
            camRoot.transform.SetParent(charRoot.transform);

            GameObject fpCam = new GameObject("FP_Camera");
            fpCam.transform.SetParent(camRoot.transform);
            fpCam.tag = "MainCamera";
            Camera c = fpCam.AddComponent<Camera>();
            c.fieldOfView = 112.6f;
            c.nearClipPlane = 0.01f;
            c.farClipPlane = 1000f;
            c.clearFlags = CameraClearFlags.Skybox;
            fpCam.AddComponent<AudioListener>();

            GameObject wpnCam = new GameObject("FP_WeaponCamera");
            wpnCam.transform.SetParent(fpCam.transform);
            Camera wc = wpnCam.AddComponent<Camera>();
            wc.fieldOfView = 53.1f;
            wc.depth = 1;
            wc.clearFlags = CameraClearFlags.Depth;
            wc.cullingMask = 1 << 9;

            // -- Containers --
            GameObject weapons = new GameObject("FP_Weapons");
            weapons.transform.SetParent(fpm);
            new GameObject("FP_CharacterMesh").transform.SetParent(fpm);

            // -- Helper components on FirstPersonModule --
            AddC(fpm.gameObject, "InfimaGames.LowPolyShooterPack.FootstepPlayer");
            AddC(fpm.gameObject, "InfimaGames.LowPolyShooterPack.WallAvoidance");
            AddC(fpm.gameObject, "InfimaGames.LowPolyShooterPack.FeelManager");
            AddC(fpm.gameObject, "InfimaGames.LowPolyShooterPack.CharacterKinematics");
            AddC(fpm.gameObject, "InfimaGames.LowPolyShooterPack.CrouchingInput");
            AddC(fpm.gameObject, "InfimaGames.LowPolyShooterPack.LeaningInput");
            AddC(fpm.gameObject, "InfimaGames.LowPolyShooterPack.LowerWeapon");

            // -- Adapters --
            AddC(charRoot, "FPCharacterAdapter");
            AddC(charRoot, "FPMovementAdapter");

            Debug.Log("FirstPersonModule children created");
        }
        else
        {
            Debug.Log("FirstPersonModule children already exist");
        }
    }

    // =========================================
    // Step 3: Add Player scripts to root
    // =========================================
    private static void AddPlayerScripts(GameObject root)
    {
        string[] names = { "PlayerState", "PlayerNetwork", "PlayerMovement",
            "PlayerViewManager", "PlayerCombat", "PlayerActions",
            "PlayerAnimation", "PlayerSettings" };

        foreach (string n in names)
        {
            Type t = T(n);
            if (t != null && root.GetComponent(t) == null)
                root.AddComponent(t);
        }
    }

    // =========================================
    // Step 4: Wire up references
    // =========================================
    private static void WireUpReferences(GameObject root)
    {
        Transform tpm = root.transform.Find("ThirdPersonModule");
        Transform fpm = root.transform.Find("FirstPersonModule");

        // -- PlayerViewManager --
        var vm = root.GetComponent(T("PlayerViewManager"));
        if (vm != null)
        {
            SerializedObject so = new SerializedObject(vm);
            SetSO(so, "thirdPersonModule", tpm?.gameObject);
            SetSO(so, "firstPersonModule", fpm?.gameObject);
            if (fpm != null)
            {
                var ct = FindDeep(fpm, "FP_Camera");
                var crt = FindDeep(fpm, "FP_Camera_Root");
                if (ct != null) SetSO(so, "fpCamera", ct.GetComponent<Camera>());
                if (crt != null) SetSO(so, "fpCameraRoot", crt);
            }
            so.ApplyModifiedPropertiesWithoutUndo();
        }

        // -- PlayerAnimation --
        var anim = root.GetComponent(T("PlayerAnimation"));
        if (anim != null)
        {
            SerializedObject so = new SerializedObject(anim);
            if (tpm != null)
            {
                var geom = tpm.Find("Geometry");
                if (geom != null) SetSO(so, "thirdPersonAnimator", geom.GetComponent<Animator>());
            }
            if (fpm != null)
            {
                var fpAnim = fpm.GetComponentInChildren<Animator>();
                if (fpAnim != null) SetSO(so, "firstPersonAnimator", fpAnim);
            }
            so.ApplyModifiedPropertiesWithoutUndo();
        }

        // -- FPCharacterAdapter / FPMovementAdapter --
        if (fpm != null)
        {
            var cr = fpm.Find("FP_CharacterRoot");
            if (cr != null)
            {
                var adp = cr.GetComponent(T("FPCharacterAdapter"));
                if (adp != null)
                {
                    SerializedObject so = new SerializedObject(adp);
                    SetSO(so, "playerState", root.GetComponent(T("PlayerState")));
                    SetSO(so, "playerMovement", root.GetComponent(T("PlayerMovement")));
                    SetSO(so, "playerCombat", root.GetComponent(T("PlayerCombat")));
                    SetSO(so, "playerView", root.GetComponent(T("PlayerViewManager")));
                    SetSO(so, "playerInput", root.GetComponent(T("StarterAssets.StarterAssetsInputs")));
                    so.ApplyModifiedPropertiesWithoutUndo();
                }

                var madp = cr.GetComponent(T("FPMovementAdapter"));
                if (madp != null)
                {
                    SerializedObject so = new SerializedObject(madp);
                    SetSO(so, "playerMovement", root.GetComponent(T("PlayerMovement")));
                    so.ApplyModifiedPropertiesWithoutUndo();
                }
            }
        }

        // -- Disable old ThirdPersonController --
        var old = root.GetComponent(T("StarterAssets.ThirdPersonController"));
        if (old != null)
        {
            SerializedObject so = new SerializedObject(old);
            var ep = so.FindProperty("m_Enabled");
            if (ep != null) { ep.boolValue = false; so.ApplyModifiedPropertiesWithoutUndo(); }
            Debug.Log("Disabled old ThirdPersonController");
        }

        Debug.Log("References wired");
    }

    private static void SetSO(SerializedObject so, string field, UnityEngine.Object val)
    {
        var p = so.FindProperty(field);
        if (p != null && p.propertyType == SerializedPropertyType.ObjectReference)
            p.objectReferenceValue = val;
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
