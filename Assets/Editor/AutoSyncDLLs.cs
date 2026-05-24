using System.IO;
using UnityEditor;
using UnityEngine;

/// <summary>
/// 自动将 HybridCLR 构建产出的 DLL 同步到 Assets/DLLS/ 并添加 .bytes 后缀，
/// 以便 YooAsset 打包进 AssetBundle。
/// </summary>
public class AutoSyncDLLs : EditorWindow
{
    // ====== 按需修改 ======
    private const string Platform = "StandaloneWindows64";
    private const string AOTSourceDir = "HybridCLRData/AssembliesPostIl2CppStrip/" + Platform;
    private const string HotUpdateSourceDir = "HybridCLRData/HotUpdateDlls/" + Platform;
    private const string TargetDir = "Assets/DLLS";

    // 需与 MyYooAsset.AOTMetaAssemblyFiles 保持同步
    private static readonly string[] AOTDlls =
    {
        // Mirror 系列
        "Mirror.dll",
        "Mirror.Components.dll",
        "Mirror.Authenticators.dll",
        "Mirror.Transports.dll",
        // 传输层
        "YooAsset.dll",
        "FizzySteamworks.dll",
        "com.rlabrecque.steamworks.net.dll",
        "kcp2k.dll",
        "Telepathy.dll",
        "SimpleWebTransport.dll",
        // Unity 模块
        "UnityEngine.UI.dll",
        "Unity.InputSystem.dll",
        "Unity.TextMeshPro.dll",
        "UnityEngine.CoreModule.dll",
        "Unity.AI.Navigation.dll",
        // 影视 & 基础
        "Cinemachine.dll",
        // 基础类库
        "mscorlib.dll",
        "System.Core.dll",
        // UniVoice 语音
        "Adrenak.UniVoice.Runtime.dll",
        "Adrenak.UniMic.Runtime.dll",
        "Adrenak.BRW.dll",
    };

    // 热更 DLL
    private static readonly string[] HotUpdateDlls =
    {
        "HotUpdate.dll",
    };

    [MenuItem("Tools/HybridCLR/同步 DLL 到 Assets/DLLS")]
    public static void SyncAllDlls()
    {
        if (!Directory.Exists(TargetDir))
        {
            Directory.CreateDirectory(TargetDir);
            Debug.Log($"[AutoSyncDLLs] 已创建目标目录: {TargetDir}");
        }

        if (!Directory.Exists(AOTSourceDir))
        {
            Debug.LogError($"[AutoSyncDLLs] AOT 源目录不存在: {AOTSourceDir}");
            Debug.LogError("[AutoSyncDLLs] 请先执行 HybridCLR → Generate → CopyAOTAssemblies");
            return;
        }

        if (!Directory.Exists(HotUpdateSourceDir))
        {
            Debug.LogWarning($"[AutoSyncDLLs] 热更源目录不存在: {HotUpdateSourceDir}");
        }

        int copied = 0;
        int skipped = 0;
        int missing = 0;

        // 同步 AOT DLL
        foreach (string dllName in AOTDlls)
        {
            string src = Path.Combine(AOTSourceDir, dllName);
            string dst = Path.Combine(TargetDir, dllName + ".bytes");

            if (!File.Exists(src))
            {
                Debug.LogWarning($"[AutoSyncDLLs] 源文件缺失: {dllName}");
                missing++;
                continue;
            }

            if (File.Exists(dst) && FileContentsEqual(src, dst))
            {
                skipped++;
                continue;
            }

            File.Copy(src, dst, true);
            Debug.Log($"[AutoSyncDLLs] 已复制: {dllName}");
            copied++;
        }

        // 同步热更 DLL
        foreach (string dllName in HotUpdateDlls)
        {
            string src = Path.Combine(HotUpdateSourceDir, dllName);
            string dst = Path.Combine(TargetDir, dllName + ".bytes");

            if (!File.Exists(src))
            {
                Debug.LogWarning($"[AutoSyncDLLs] 热更源文件缺失: {dllName}");
                missing++;
                continue;
            }

            if (File.Exists(dst) && FileContentsEqual(src, dst))
            {
                skipped++;
                continue;
            }

            File.Copy(src, dst, true);
            Debug.Log($"[AutoSyncDLLs] 已复制(热更): {dllName}");
            copied++;
        }

        AssetDatabase.Refresh();

        Debug.Log($"[AutoSyncDLLs] 同步完成 — 复制: {copied}, 跳过(内容未变): {skipped}, 缺失源文件: {missing}");
    }

    private static bool FileContentsEqual(string path1, string path2)
    {
        var b1 = File.ReadAllBytes(path1);
        var b2 = File.ReadAllBytes(path2);
        if (b1.Length != b2.Length) return false;
        for (int i = 0; i < b1.Length; i++)
        {
            if (b1[i] != b2[i]) return false;
        }
        return true;
    }

    // ====== 构建前自动执行 ======
    // 如果希望在 YooAsset 构建前自动同步，取消注释下面这个方法
    // [UnityEditor.Callbacks.DidReloadScripts]
    // 或参考 YooAsset 的构建流程，添加到自定义构建管线的预步骤中
}
