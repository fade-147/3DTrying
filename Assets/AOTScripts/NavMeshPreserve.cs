using UnityEngine;
using Unity.AI.Navigation;

/// <summary>
/// AOT 引用锚点：防止 HybridCLR IL2CPP 构建时裁剪 Unity.AI.Navigation 程序集。
/// Unity 场景中的 NavMeshSurface 组件依赖此程序集——若无 AOT 引用，场景加载时反序列化失败，NavMesh 永远不可用。
/// 此文件位于 Assets/AOTScripts/（无 asmdef），编译到 Assembly-CSharp，确保 AOT 编译。
/// </summary>
public class NavMeshPreserve : MonoBehaviour
{
    private NavMeshSurface _surface;

    private void Awake()
    {
        _surface = GetComponent<NavMeshSurface>();
    }
}
