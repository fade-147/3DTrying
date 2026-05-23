using UnityEngine;
using System.Collections.Generic;

public class CharacterOutline : MonoBehaviour
{
    public Material outlineMaterial;

    private List<SkinnedMeshRenderer> renderers = new List<SkinnedMeshRenderer>();
    private int _lastMatCount;
    private bool _lastHasOutline;

    void Start()
    {
        renderers.AddRange(GetComponentsInChildren<SkinnedMeshRenderer>());
    }

    public void ToggleOutline(bool show)
    {
        if (outlineMaterial == null) return;

        foreach (var renderer in renderers)
        {
            if (renderer == null) continue;

            var mats = new List<Material>(renderer.sharedMaterials);
            bool hasOutline = mats.Contains(outlineMaterial);

            if (show && !hasOutline)
            {
                mats.Add(outlineMaterial);
            }
            else if (!show && hasOutline)
            {
                mats.Remove(outlineMaterial);
            }
            else
            {
                continue; // 已经正确，跳过赋值
            }

            renderer.materials = mats.ToArray();
            _lastMatCount = renderer.materials.Length;
            _lastHasOutline = show;
        }
    }

    void OnGUI()
    {
        if (Camera.main == null) return;

        Vector3 screenPos = Camera.main.WorldToScreenPoint(transform.position);
        if (screenPos.z < 0) return;

        screenPos.y = Screen.height - screenPos.y;

        string matInfo = outlineMaterial == null ? "M:NULL" : $"M:{outlineMaterial.name}";
        string info = $"Outline:{_lastHasOutline} MC:{_lastMatCount} R:{renderers.Count} {matInfo}";
        GUI.Label(new Rect(screenPos.x - 80, screenPos.y - 40, 280, 20), info);
    }
}
