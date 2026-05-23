using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using YooAsset;

public class Load : MonoBehaviour
{

    private ResourcePackage package;
    private void Awake()
    {
        InitYoo();
    }

    private void InitYoo()
    {
        // 初始化资源系统
        YooAssets.Initialize();

        // 创建默认的资源包
        package = YooAssets.CreatePackage("DefaultPackage");

        //// 获取指定的资源包，如果没有找到会报错
        //var package = YooAssets.GetPackage("DefaultPackage");

        //// 获取指定的资源包，如果没有找到不会报错
        //var package = YooAssets.TryGetPackage("DefaultPackage");

        // 设置该资源包为默认的资源包，可以使用YooAssets相关加载接口加载该资源包内容。
        YooAssets.SetDefaultPackage(package);
    }
}
