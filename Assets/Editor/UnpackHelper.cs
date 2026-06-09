using UnityEngine;
using UnityEditor;

public static class UnpackHelper
{
    /// <summary>
    /// Unpack a PrefabInstance root and all nested instances within it.
    /// Keeps trying until no PrefabInstance remains.
    /// </summary>
    public static void UnpackAll(GameObject root)
    {
        int maxIterations = 20; // safety limit
        for (int i = 0; i < maxIterations; i++)
        {
            // Find the first PrefabInstance in the hierarchy
            GameObject instanceRoot = null;
            foreach (var t in root.GetComponentsInChildren<Transform>(true))
            {
                if (!t) continue;
                var go = t.gameObject;
                if (!go || !PrefabUtility.IsPartOfPrefabInstance(go)) continue;
                var candidate = PrefabUtility.GetNearestPrefabInstanceRoot(go);
                if (candidate)
                {
                    instanceRoot = candidate;
                    break;
                }
            }

            if (!instanceRoot) break; // no more instances

            PrefabUtility.UnpackPrefabInstance(instanceRoot,
                PrefabUnpackMode.Completely, InteractionMode.AutomatedAction);
            Debug.Log("Unpacked: " + instanceRoot.name);
        }
    }
}
