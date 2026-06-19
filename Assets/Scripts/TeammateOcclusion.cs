using UnityEngine;
using System.Collections.Generic;

public class TeammateOcclusion : MonoBehaviour
{
    public Material occlusionMaterial;

    // GameObjects whose names CONTAIN any of these strings will NOT get
    // the occlusion effect.  Tweak these to match your character's inner
    // body meshes — you only want the outermost shell to glow.
    public string[] excludeNameContains = new string[]
    {
        "Shirt",        // body torso — typically under vest / jacket
        "Pants",        // legs — under boots (if separate)
        "Head",         // skull — under helmet / cap / hair
        "Arms",         // arms — under gloves
        "FPS_Arms",     // first-person arm meshes (always disabled anyway)
        "Character",    // "Character Mesh" / "Character Root"
        "Body",         // generic body
        "Skin",         // generic skin
    };

    private List<SkinnedMeshRenderer> renderers = new List<SkinnedMeshRenderer>();
    private bool isActive;

    void Start()
    {
        var all = GetComponentsInChildren<SkinnedMeshRenderer>();
        foreach (var r in all)
        {
            if (r == null) continue;
            if (ShouldExclude(r.name)) continue;
            renderers.Add(r);
        }
    }

    private bool ShouldExclude(string name)
    {
        foreach (var pattern in excludeNameContains)
        {
            if (name.Contains(pattern)) return true;
        }
        return false;
    }

    public void ToggleOcclusion(bool show)
    {
        if (occlusionMaterial == null) return;

        if (show == isActive) return;
        isActive = show;

        foreach (var renderer in renderers)
        {
            if (renderer == null) continue;

            var mats = new List<Material>(renderer.sharedMaterials);
            bool hasOcclusion = mats.Contains(occlusionMaterial);

            if (show && !hasOcclusion)
            {
                mats.Add(occlusionMaterial);
                renderer.materials = mats.ToArray();
            }
            else if (!show && hasOcclusion)
            {
                mats.Remove(occlusionMaterial);
                renderer.materials = mats.ToArray();
            }
        }
    }
}
