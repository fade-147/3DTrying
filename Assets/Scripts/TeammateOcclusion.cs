using UnityEngine;
using System.Collections.Generic;

public class TeammateOcclusion : MonoBehaviour
{
    public Material occlusionMaterial;

    private List<SkinnedMeshRenderer> renderers = new List<SkinnedMeshRenderer>();

    void Start()
    {
        renderers.AddRange(GetComponentsInChildren<SkinnedMeshRenderer>());
    }

    public void ToggleOcclusion(bool show)
    {
        if (occlusionMaterial == null) return;

        foreach (var renderer in renderers)
        {
            if (renderer == null) continue;

            var mats = new List<Material>(renderer.sharedMaterials);
            bool hasOcclusion = mats.Contains(occlusionMaterial);

            if (show && !hasOcclusion)
            {
                mats.Add(occlusionMaterial);
            }
            else if (!show && hasOcclusion)
            {
                mats.Remove(occlusionMaterial);
            }
            else
            {
                continue;
            }

            renderer.materials = mats.ToArray();
        }
    }
}
