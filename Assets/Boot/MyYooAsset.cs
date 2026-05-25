﻿using HybridCLR;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;
using UnityEngine.SceneManagement;
using YooAsset;
using System.Reflection; // 用于加载热更程序集 Assembly
using UnityEngine.UI;
using Mirror;


//本地和远程的地址变换在117行的false上面
public class MyYooAsset : MonoBehaviour
{

    [SerializeField]
    private HotUpdateView hotUpdateView;



    // 单例，方便在其他地方获取 package 或者检查初始化状态
    public static MyYooAsset Instance { get; private set; }

    // 此列表需与 Assets/Editor/AutoSyncDLLs.cs 中的 aotDlls 保持同步
    private static List<string> AOTMetaAssemblyFiles { get; } = new List<string>()
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
        // 基础类库（AOTGenericReferences 标记为热更引用了泛型）
        "mscorlib.dll",
        "System.Core.dll",
        // UniVoice 语音
        "Adrenak.UniVoice.Runtime.dll",
        "Adrenak.UniMic.Runtime.dll",
        "Adrenak.BRW.dll",
    };
    private static Dictionary<string, TextAsset> s_assetDatas = new Dictionary<string, TextAsset>();

    // 热更程序集句柄，加载完成后会保存到这里
    private Assembly _hotUpdateAss;



    public EPlayMode PlayMode = EPlayMode.HostPlayMode; //运行模式
    public string packageName = "DefaultPackage"; //默认包名
    public string packageVersion = ""; //服务器资源版本号
    public ResourcePackage package = null;
    // 标记 package 是否初始化完成（获取清单并可用于加载资源）
    public bool PackageInitialized { get; private set; } = false;
    // 标记热更程序集及主场景是否已加载完成
    public bool HotUpdateReady { get; private set; } = false;
    // 标记所有程序集是否已加载（AOT 元数据 + 热更 DLL）
    public bool AssembliesLoaded { get; private set; } = false;

    // 更新确认
    private bool _updateConfirmed;

    //网络相关
    public string defaultHostServer = "http://127.0.0.1/CDN/PC/v1.0";
    public string fallbackHostServer = "http://127.0.0.1/CDN/PC/v1.0";
    //public string defaultHostServer = "https://a.unity.cn/client_api/v1/buckets/74cefac6-736e-4b02-9fd0-2bf0168da5f8/entry_by_path/content/?path=/CDN/PC/v1.0";
    //public string fallbackHostServer = "https://a.unity.cn/client_api/v1/buckets/74cefac6-736e-4b02-9fd0-2bf0168da5f8/entry_by_path/content/?path=/CDN/PC/v1.0";

    //下载相关
    public int downloadingMaxNum = 10;
    public int filedTryAgain = 3;
    public ResourceDownloaderOperation downloader;
    
    private void Awake()
    {
        DontDestroyOnLoad(gameObject);
        Instance = this; // 设置单例
    }


    // Start is called before the first frame update
    IEnumerator Start()
    {
        yield return null;

        //1.初始化YooAsset
        YooAssets.Initialize();

        package = YooAssets.TryGetPackage(packageName);
        if (package == null)
        {
            package = YooAssets.CreatePackage(packageName);
        }
        // 将这个 package 设为默认包，以便使用 YooAssets 的静态 API（例如 YooAssets.LoadSceneAsync）
        YooAssets.SetDefaultPackage(package);
        Debug.Log($"[调试] 默认包设置: packageName={packageName}, package对象为空: {package==null}");

        IRemoteServices remoteServices = new RemoteServices(defaultHostServer, fallbackHostServer);
       
        var createParameters = new HostPlayModeParameters();
        //创建文件系统内置参数
        createParameters.BuildinFileSystemParameters = 
            FileSystemParameters.CreateDefaultBuildinFileSystemParameters();
        //创建缓存系统参数
        createParameters.CacheFileSystemParameters = 
            FileSystemParameters.CreateDefaultCacheFileSystemParameters(remoteServices, null);
        //执行异步初始化
        InitializationOperation initializationOperation = 
            package.InitializeAsync(createParameters);
        
        yield return initializationOperation;

        if (initializationOperation.Status != EOperationStatus.Succeed)
        {
            Debug.LogWarning(initializationOperation.Error);            
        }
        else
        {
            Debug.Log("初始化成功");
            PackageInitialized = true; // 标记 package 初始化完成
        }
        
        
        //2.获取资源版本
        var operation = package.RequestPackageVersionAsync(false);
        yield return operation;

        if (operation.Status != EOperationStatus.Succeed)
        {
            Debug.LogWarning(operation.Error);            
        }
        else
        {
            Debug.Log($"请求的版本: {operation.PackageVersion}");
            packageVersion = operation.PackageVersion;
        }


        //3.获取文件清单
        var operationManifest =  package.UpdatePackageManifestAsync(packageVersion);
        yield return operationManifest;
        
        
        if (operationManifest.Status != EOperationStatus.Succeed)
        {
            Debug.LogWarning(operationManifest.Error);            
        }
        else
        {
            Debug.Log("更新资源清单成功-------------------");
            // 调试：列出包内资源（带标签 hot 的资源）以确认 dll 是否存在于清单中
            try
            {
                var assetInfos = package.GetAssetInfos("hot");
                if (assetInfos != null)
                {
                    Debug.Log($"[调试] 包含资源数量(标签 hot): {assetInfos.Length}");
                    foreach (var ai in assetInfos)
                    {
                        // AssetInfo 可能包含 AssetPath 字段
                        Debug.Log($"[调试] 资源信息: {ai.AssetPath}");
                    }
                }
                else
                {
                    Debug.Log("[调试] package.GetAssetInfos 返回 null");
                }
            }
            catch (Exception ex)
            {
                Debug.LogWarning($"[调试] 无法列出包内资源，可能 API 不可用: {ex.Message}");
            }
        }
        
        
        //4.创建下载器
        downloader = package.CreateResourceDownloader(downloadingMaxNum, filedTryAgain);
        // 隐藏开始按钮，启动时不可见
        if (hotUpdateView.startButton != null)
        {
            hotUpdateView.startButton.gameObject.SetActive(false);
            hotUpdateView.startButton.onClick.RemoveAllListeners();
            hotUpdateView.startButton.onClick.AddListener(StartButtonClicked);
        }
        // 初始 UI 文本
        if (hotUpdateView != null)
        {
            hotUpdateView.RefreshUI(0f, "正在检查更新...");
        }
        if (downloader.TotalDownloadCount == 0)
        {
            Debug.Log("没有需要更新的文件");
            Debug.Log("[调试] 未检测到更新，直接进入 UpdateDone 流程，准备加载 DLL");
            UpdateDone();
            yield break;
        }

        // 有更新：弹出确认面板
        int count = downloader.TotalDownloadCount;
        long bytes = downloader.TotalDownloadBytes;
        Debug.Log($"需要更新{count}个文件, 大小是{bytes / 1024 / 1024}MB");

        if (hotUpdateView != null)
        {
            hotUpdateView.ShowUpdateInfo(count, bytes);
            // 绑定确认按钮
            if (hotUpdateView.confirmUpdateButton != null)
            {
                hotUpdateView.confirmUpdateButton.onClick.RemoveAllListeners();
                hotUpdateView.confirmUpdateButton.onClick.AddListener(OnUpdateConfirmClicked);
            }
            if (hotUpdateView.confirmQuitButton != null)
            {
                hotUpdateView.confirmQuitButton.onClick.RemoveAllListeners();
                hotUpdateView.confirmQuitButton.onClick.AddListener(OnQuitGameClicked);
            }
        }

        // 等待用户点击
        yield return new WaitUntil(() => _updateConfirmed);

        // 关闭确认面板
        if (hotUpdateView != null)
            hotUpdateView.HideUpdateConfirm();

        //5.开始下载
        downloader.DownloadUpdateCallback = ProgressCallBack;
        downloader.BeginDownload();
        yield return downloader;

        
        if (downloader.Status != EOperationStatus.Succeed)
        {
            Debug.LogWarning(downloader.Error);    
            yield break;
        }
        else
        {
            Debug.Log("下载成功-------------------");
        }
        
        
        //6.清理文件：等待清理完成再继续
        var operationClear = package.ClearCacheFilesAsync(EFileClearMode.ClearUnusedBundleFiles);
        // 等待清理完成（协程会暂停直到异步操作结束）
        yield return operationClear;

        if (operationClear.Status == EOperationStatus.Succeed)
        {
            Debug.Log("清理缓存成功");
            UpdateDone();
        }
        else
        {
            Debug.LogWarning($"清理缓存失败: {operationClear.Error}");
            // 即使清理失败，也尝试继续后续流程，避免因缓存清理失败卡住启动
            UpdateDone();
        }

    }
    
    // 注意：已改为在 Start 中直接等待 ClearCacheFilesAsync 的完成，故不再使用 Completed 回调方法。

    //监听进度条回调
    private void ProgressCallBack(DownloadUpdateData data)
    {
        Debug.Log($"需要更新{data.TotalDownloadCount}个文件, 当前已更新{data.CurrentDownloadCount}," +
                  $"大小是{data.TotalDownloadBytes / 1024/1024}MB, 已下载{data.CurrentDownloadBytes / 1024 / 1024}MB");

        // 更新 UI
        if (hotUpdateView != null)
        {
            float progress = 0f;
            if (data.TotalDownloadBytes > 0)
                progress = (float)data.CurrentDownloadBytes / (float)data.TotalDownloadBytes;
            else if (data.TotalDownloadCount > 0)
                progress = (float)data.CurrentDownloadCount / (float)data.TotalDownloadCount;

            string txt = $"下载进度【{Mathf.RoundToInt(progress * 100f)}%】";
            hotUpdateView.RefreshUI(progress, txt);
        }
    }

    //热更新结束
    private async void UpdateDone()  //
    {
        Debug.Log("热更新结束");

        //task加载资源
        //AssetHandle handle = package.LoadAssetAsync<Sprite>("Assets/Test/测试图");
        //await handle.Task;

        //Sprite car = handle.AssetObject as Sprite;
        //GameObject go = new GameObject();
        //go.AddComponent<SpriteRenderer>().sprite = car;
















        // 启动协程先加载并注册 AOT/热更程序集，但不自动切场景。
        // 完成后会显示开始游戏按钮，用户点击后才切场景。
        StartCoroutine(LoadAssemblies());

        //预制体加载和创建
        // AssetHandle handle = package.LoadAssetAsync<GameObject>
        //     ("Assets/AB/Prefab/Car.prefab");
        // await handle.Task;
        // GameObject go = handle.InstantiateSync();
        // // Instantiate(handle.AssetObject as GameObject);
        // Debug.Log("Prefab name:" + go.name);







        //模拟资源加载
        //Sprite car = package.LoadAssetSync<Sprite>("Assets/Test/测试图")
        //    .AssetObject as Sprite;
        //GameObject go = new GameObject();
        //go.AddComponent<SpriteRenderer>().sprite = car;


        //异步委托资源加载
        //AssetHandle handle = package.LoadAssetAsync<Sprite>("Assets/Test/测试图");
        //handle.Completed += Handle_Completed;

        // 协程方式加载资源
        //AssetHandle handle = package.LoadAssetAsync<Sprite>("Assets/Test/测试图");
        //yield return handle;
        //Sprite car = handle.AssetObject as Sprite;
        //GameObject go = new GameObject();
        //go.AddComponent<SpriteRenderer>().sprite = car;

        //图片子对象加载
        //SubAssetsHandle handle =
        //    package.LoadSubAssetsAsync<Sprite>("Assets/ABTest/Image/Farms");
        //await handle.Task;
        //var sprite = handle.GetSubAssetObject<Sprite>("hen");
        //new GameObject().AddComponent<SpriteRenderer>().sprite = sprite;
        //Debug.Log("Sprite name: " + sprite.name);

        //卸载未使用的资源包
        // var operation = package.UnloadUnusedAssetsAsync();
        // await operation.Task;

        //强制卸载资源包
        // var operation = package.UnloadAllAssetsAsync();
        // await operation.Task;



        //卸载资源包中某个资源 (未使用的)
        // package.TryUnloadUnusedAsset("Assets/GameRes/Panel/login.prefab");
        //



        //获取所有信息
        //AssetInfo[] assetInfos = package.GetAssetInfos("hot");
        //foreach (var assetInfo in assetInfos)
        //{
        //    Debug.Log(assetInfo.AssetPath);
        //}



    }

    // 异步委托回调
    //private void Handle_Completed(AssetHandle obj)
    //{
    //    Sprite car = obj.AssetObject as Sprite;
    //    GameObject go = new GameObject();
    //    go.AddComponent<SpriteRenderer>().sprite = car;
    //}

    // Update is called once per frame


    private IEnumerator LoadAssemblies()
    {
        var assets = new List<string> { "HotUpdate.dll" }.Concat(AOTMetaAssemblyFiles);
        //逐个加载程序集字节数据
        foreach (var asset in assets)
        {
            Debug.Log($"[调试] 尝试加载程序集资源: {asset}");

            // 使用已初始化的 ResourcePackage 实例来加载程序集资源
            // 注意：此处使用的是本类的 `package` 字段，如果要使用其他 package
            // 请自行传入或修改。
            var handle = package.LoadAssetAsync<TextAsset>(asset);
            yield return handle;
            Debug.Log($"[调试] 资源加载返回: {asset}, 状态: {handle.Status}");
            if (handle.Status == EOperationStatus.Succeed)
            {
                var textAsset = handle.AssetObject as TextAsset;
                if (textAsset == null)
                {
                    Debug.LogError($"[错误] 资源为 null: {asset}");
                }
                else
                {
                    s_assetDatas.Add(asset, textAsset);
                    Debug.Log($"[调试] 程序集加载成功：{asset}, 大小：{textAsset.bytes.Length} 字节");
                }
            }
            else
            {
                Debug.LogError($"[错误] 程序集加载失败：{asset}, 错误信息: {handle.LastError}");
            }
            //释放句柄
            handle.Release();
        }
        // 汇总检查：哪些程序集没有加载到
        var missing = assets.Where(a => !s_assetDatas.ContainsKey(a)).ToList();
        if (missing.Count > 0)
        {
            Debug.LogError($"[错误] 以下程序集未加载到 s_assetDatas: {string.Join(", ", missing)}");
            Debug.LogError("[提示] 请确认这些 dll 是否已被打包进 YooAsset 的清单，资源名称应与上面列出的名称完全一致");
        }
        else
        {
            Debug.Log($"[调试] 全部程序集资源已加载到内存: 共 {s_assetDatas.Count} 个");
        }
        LoadMetadataForAOTAssemblies();
        LoadHotUpdateDlls();
        // 所有程序集加载完成，但不切场景：显示开始按钮并等待玩家确认
        AssembliesLoaded = true;
        Debug.Log("程序集加载完成，等待用户点击开始游戏按钮切换场景");
        if (hotUpdateView != null)
        {
            hotUpdateView.RefreshUI(1f, "资源加载完成");
        }
        if (hotUpdateView.startButton != null)
        {
            hotUpdateView.startButton.gameObject.SetActive(true);
        }

        yield break;
    }

    // 点击开始游戏后的行为：真正加载主场景，并在加载后设置 HotUpdateReady
    public void StartButtonClicked()
    {
        // 防止重复点击
        if (hotUpdateView.startButton != null)
            hotUpdateView.startButton.interactable = false;

        StartCoroutine(LoadMainSceneAndFinish());
    }

    public void OnUpdateConfirmClicked()
    {
        _updateConfirmed = true;
    }

    public void OnQuitGameClicked()
    {
        Application.Quit();
#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
#endif
    }

    private IEnumerator LoadMainSceneAndFinish()
    {
        string location = "Assets/Scenes/StartScene.unity";
        var sceneMode = UnityEngine.SceneManagement.LoadSceneMode.Single;
        var physicsMode = LocalPhysicsMode.None;
        bool suspendLoad = false;
        // 使用 package 加载场景并等待完成
        SceneHandle sceneHandle = package.LoadSceneAsync(location, sceneMode, physicsMode, suspendLoad);
        // 显示加载中状态
        if (hotUpdateView != null)
            hotUpdateView.RefreshUI(0f, "正在加载场景...");

        yield return sceneHandle;

        if (sceneHandle.Status != EOperationStatus.Succeed)
        {
            Debug.LogError($"通过 YooAsset 加载主场景失败: {sceneHandle.LastError}");
            if (hotUpdateView != null)
                hotUpdateView.RefreshUI(0f, "场景加载失败");
            yield break;
        }

        Debug.Log("主场景加载完成: " + sceneHandle.SceneName);
        HotUpdateReady = true;
        if (hotUpdateView != null)
            hotUpdateView.RefreshUI(1f, "全部加载完成");
    }

    //补充元数据
    private void LoadMetadataForAOTAssemblies()
    {
        HomologousImageMode mode = HomologousImageMode.SuperSet;
        foreach (var aotDllName in AOTMetaAssemblyFiles)
        {
            if (!s_assetDatas.TryGetValue(aotDllName, out TextAsset textAsset) || textAsset == null)
            {
                Debug.LogError($"[错误] 缺少 AOT 元数据文件: {aotDllName}，请检查该 dll 是否已被打包为 TextAsset");
                continue;
            }
            byte[] dllBytes = textAsset.bytes;
            LoadImageErrorCode err = RuntimeApi.LoadMetadataForAOTAssembly(dllBytes, mode);
            if (err != LoadImageErrorCode.OK)
            {
                Debug.LogError($"[错误] 加载 AOT 元数据失败 ({aotDllName}): {err}");
            }
            else
            {
                Debug.Log($"[调试] AOT 元数据加载成功: {aotDllName}");
            }
        }
    }

    private void LoadHotUpdateDlls()
    {
        if (s_assetDatas.Count == 0)
        {
            Debug.LogError("没有加载到任何程序集！");
            return;
        }

        //加载热更新DLL
#if !UNITY_EDITOR
        if (!s_assetDatas.TryGetValue("HotUpdate.dll", out TextAsset hotText) || hotText == null)
        {
            Debug.LogError("HotUpdate.dll 未找到，无法加载热更程序集");
            return;
        }
        try
        {
            _hotUpdateAss = Assembly.Load(hotText.bytes);
            Debug.Log($"[MyYooAsset] HotUpdate.dll 加载成功，类型数: {_hotUpdateAss.GetTypes().Length}");
        }
        catch (Exception ex)
        {
            Debug.LogError($"加载 HotUpdate.dll 失败: {ex}");
            return;
        }
#else
        // 编辑器下直接尝试从已加载程序集查找
        var hot = System.AppDomain.CurrentDomain.GetAssemblies().FirstOrDefault(a => a.GetName().Name == "HotUpdate");
        if (hot == null)
        {
            Debug.LogError("编辑器下未找到 HotUpdate 程序集，请确保已编译并加载 HotUpdate");
        }
        _hotUpdateAss = hot;
#endif













        if (_hotUpdateAss == null)
        {
            Debug.LogError("[MyYooAsset] _hotUpdateAss 为空，跳过 Mirror 初始化");
            return;
        }

        // 热更程序集 InitReadWriters 扫描 — 暂时禁用，排查联机 NullReferenceException
        // （疑似 InitReadWriters 中注册的自定义 Reader/Writer 在客户端反序列化 SpawnMessage 时抛 NRE）
        /*
        int initMethodCount = 0;

        foreach (Type t in _hotUpdateAss.GetTypes())
        {
            foreach (var m in t.GetMethods(BindingFlags.Static | BindingFlags.Public | BindingFlags.NonPublic))
            {
                if (m.GetCustomAttributes(typeof(UnityEngine.RuntimeInitializeOnLoadMethodAttribute), false).Length > 0
                    && m.GetParameters().Length == 0)
                {
                    try
                    {
                        m.Invoke(null, null);
                        initMethodCount++;
                        Debug.Log($"[MyYooAsset] 初始化方法执行成功: {t.FullName}.{m.Name}");
                    }
                    catch (Exception e)
                    {
                        Debug.LogError($"[MyYooAsset] 初始化方法执行失败: {t.FullName}.{m.Name}\n{e}");
                    }
                }
            }
        }
        Debug.Log($"[MyYooAsset] 共执行 {initMethodCount} 个 RuntimeInitializeOnLoadMethod");
        */

        // 强制触发 NetworkRoomPlayer 的 .cctor（AOT 类型，IL2CPP 可能不触发）
        // 只有它的 CmdChangeReadyState 需要这个修复，不对所有类型做是为了避免
        // 其他类型的 .cctor 在 RemoteConnection 反序列化时引发 NRE
        try
        {
            System.Runtime.CompilerServices.RuntimeHelpers.RunClassConstructor(typeof(Mirror.NetworkRoomPlayer).TypeHandle);
            Debug.Log("[MyYooAsset] NetworkRoomPlayer .cctor 触发成功");
        }
        catch (Exception e)
        {
            Debug.LogWarning($"[MyYooAsset] NetworkRoomPlayer .cctor 触发失败: {e.Message}");
        }
    }

}
















public class RemoteServices : IRemoteServices
{
    private readonly string _defaultHostServer;
    private readonly string _fallbackHostServer;

    public RemoteServices(string defaultHostServer, string fallbackHostServer)
    {
        _defaultHostServer = defaultHostServer;
        _fallbackHostServer = fallbackHostServer;
    }

    string IRemoteServices.GetRemoteMainURL(string fileName)
    {
        return $"{_defaultHostServer}/{fileName}";
    }

    string IRemoteServices.GetRemoteFallbackURL(string fileName)
    {
        return $"{_fallbackHostServer}/{fileName}";
    }


}