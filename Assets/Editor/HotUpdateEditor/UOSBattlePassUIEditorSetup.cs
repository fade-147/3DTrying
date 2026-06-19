using System.IO;
using TMPro;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 一键创建战令系统的所有 UI GameObject。
/// 菜单: Tools → UOS → Create Battle Pass UI
/// 注意：请先打开 StartScene，确保场景中有 Canvas。
/// </summary>
public static class UOSBattlePassUIEditorSetup
{
    private const string PrefabDir = "Assets/Scripts/Prefab";

    [MenuItem("Tools/UOS/Create Battle Pass UI")]
    public static void CreateAllUI()
    {
        Canvas canvas = Object.FindObjectOfType<Canvas>();
        if (canvas == null)
        {
            EditorUtility.DisplayDialog("错误",
                "当前场景没有 Canvas。请打开 StartScene。", "确定");
            return;
        }

        if (!Directory.Exists(PrefabDir))
            Directory.CreateDirectory(PrefabDir);

        TMP_FontAsset font = FindTMPFont();

        // ── 1. 创建 Node Prefab ──
        GameObject nodePrefab = CreateNodePrefab(font);

        // ── 2. 创建场景内 BattlePassPanel ──
        CreateBattlePassPanel(canvas.transform, nodePrefab, font);

        // ── 3. 在 Canvas 下创建 "战令" 按钮 ──
        CreateBattlePassOpenButton(canvas.transform, font);

        Selection.activeGameObject = canvas.gameObject;
        EditorUtility.DisplayDialog("完成",
            "已创建 BattlePassPanel + 战令按钮 (在 Canvas 下) + 1 个 Prefab。\n"
            + "请在 UOS 控制台创建 Leaderboard: bp-claimed-kills", "确定");
    }

    // ═══════════════════════════════════════════════
    //  Prefab: BattlePassNode（里程碑节点）
    // ═══════════════════════════════════════════════

    static GameObject CreateNodePrefab(TMP_FontAsset font)
    {
        // 根: 垂直布局，宽 100 高 130
        GameObject go = MakeUIObj("BattlePassNode", 100, 130);
        var vlg = go.AddComponent<VerticalLayoutGroup>();
        vlg.childAlignment = TextAnchor.UpperCenter;
        vlg.spacing = 4;
        vlg.padding = new RectOffset(4, 4, 4, 4);
        vlg.childControlWidth = true;
        vlg.childControlHeight = false;

        // 节点图标（圆形 Image，50x50）
        var iconGo = MakeUIObj("NodeIcon", 50, 50, go.transform);
        var iconImg = iconGo.AddComponent<Image>();
        iconImg.color = new Color(0.4f, 0.4f, 0.4f);

        // 标签 "10杀"
        var labelText = MakeTMPText("NodeLabel", font, 72, 24, go.transform);
        labelText.fontSize = 14;
        labelText.alignment = TextAlignmentOptions.Center;
        labelText.text = "10杀";

        // 领取按钮（仅 AVAILABLE 时显示）
        var claimBtn = MakeTextButton("ClaimButton", "领取", font, 64, 28, go.transform);
        claimBtn.SetActive(false);

        // 已领取对勾
        var claimedGo = MakeUIObj("ClaimedMark", 24, 24, go.transform);
        var claimedTmp = claimedGo.AddComponent<TextMeshProUGUI>();
        if (font != null) claimedTmp.font = font;
        claimedTmp.fontSize = 20;
        claimedTmp.color = Color.white;
        claimedTmp.alignment = TextAlignmentOptions.Center;
        claimedTmp.text = "✓";
        claimedGo.SetActive(false);

        // 锁定遮罩
        var lockGo = MakeUIObj("LockOverlay", 50, 50, go.transform);
        var lockTmp = lockGo.AddComponent<TextMeshProUGUI>();
        if (font != null) lockTmp.font = font;
        lockTmp.fontSize = 24;
        lockTmp.color = new Color(0.3f, 0.3f, 0.3f);
        lockTmp.alignment = TextAlignmentOptions.Center;
        lockTmp.text = "🔒";

        // 挂脚本
        var script = go.AddComponent<BattlePassNodeUI>();
        SetPrivateField(script, "nodeIcon", iconImg);
        SetPrivateField(script, "nodeLabel", labelText);
        SetPrivateField(script, "claimButton", claimBtn.GetComponent<Button>());
        SetPrivateField(script, "claimedMark", claimedGo);
        SetPrivateField(script, "lockOverlay", lockGo);

        return SavePrefab(go, "BattlePassNode.prefab");
    }

    // ═══════════════════════════════════════════════
    //  场景 UI: BattlePassPanel（战令主面板）
    // ═══════════════════════════════════════════════

    static void CreateBattlePassPanel(Transform canvas, GameObject nodePrefab, TMP_FontAsset font)
    {
        var panel = MakePanel("BattlePassPanel", canvas, 760, 380);

        // ── 标题行 ──
        var titleRow = MakeUIObj("TitleRow", 720, 36, panel.transform);
        var titleHL = titleRow.AddComponent<HorizontalLayoutGroup>();
        titleHL.childAlignment = TextAnchor.MiddleLeft;
        titleHL.spacing = 16;
        titleHL.childControlWidth = false;
        titleHL.childControlHeight = false;

        var titleText = MakeTMPText("Title", font, 80, 36, titleRow.transform);
        titleText.fontSize = 28;
        titleText.text = "战令";
        titleText.alignment = TextAlignmentOptions.Left;

        // ── 关闭按钮（挂 panel 下，手动定位右上角，避免被 LayoutGroup 干扰） ──
        var closeBtn = MakeTextButton("CloseBtn", "X", font, 40, 36, panel.transform);
        var closeRT = closeBtn.GetComponent<RectTransform>();
        closeRT.anchorMin = new Vector2(1, 1);
        closeRT.anchorMax = new Vector2(1, 1);
        closeRT.pivot = new Vector2(1, 1);
        closeRT.anchoredPosition = new Vector2(-12, -8);

        // ── 滚动区域（ProgressBar + 节点一起滚动） ──
        // Content 不加 LayoutGroup——虚拟滚动代码手动管理子节点位置和 Content 宽度
        float contentWidth = (100 + 40) * 20 + 40; // 初始宽：20 节点兜底，运行时代码动态扩展
        var scrollView = MakeScrollViewH("NodesScroll", panel.transform, 720, 180);
        var scrollContent = scrollView.transform.Find("Viewport/Content");

        // ── 进度条（在 ScrollView Content 内，与节点一起滚动） ──
        var progressBar = MakeUIObj("ProgressBar", contentWidth - 16, 28, scrollContent);
        var barBgGo = MakeUIObj("Background", contentWidth - 16, 16, progressBar.transform);
        var barBgRT = barBgGo.GetComponent<RectTransform>();
        barBgRT.anchorMin = new Vector2(0, 0.5f);
        barBgRT.anchorMax = new Vector2(1, 0.5f);
        barBgRT.pivot = new Vector2(0, 0.5f);
        barBgRT.anchoredPosition = Vector2.zero;
        barBgRT.sizeDelta = new Vector2(0, 12);
        barBgGo.AddComponent<Image>().color = new Color(0.25f, 0.25f, 0.25f);

        // 填充（带白色 Sprite 才能 Filled 渲染，宽度与节点总宽一致）
        var fillGo = MakeUIObj("Fill", contentWidth - 16, 12, barBgGo.transform);
        var fillRT = fillGo.GetComponent<RectTransform>();
        fillRT.anchorMin = Vector2.zero;
        fillRT.anchorMax = Vector2.one;
        fillRT.offsetMin = Vector2.zero;
        fillRT.offsetMax = Vector2.zero;
        var fillImg = fillGo.AddComponent<Image>();
        fillImg.sprite = GetOrCreateWhiteSprite();
        fillImg.color = new Color(1f, 0.84f, 0f); // 金色
        fillImg.type = Image.Type.Filled;
        fillImg.fillMethod = Image.FillMethod.Horizontal;
        fillImg.fillOrigin = 0;

        // ── 节点容器（虚拟滚动手动定位，不加 LayoutGroup） ──
        var nodesRow = MakeUIObj("NodesRow", contentWidth - 16, 130, scrollContent);

        // ── 底部信息行（固定在面板上，不跟随滚动） ──
        var bottomRow = MakeUIObj("BottomRow", 720, 40, panel.transform);
        var bottomHL = bottomRow.AddComponent<HorizontalLayoutGroup>();
        bottomHL.childAlignment = TextAnchor.MiddleCenter;
        bottomHL.spacing = 12;
        bottomHL.childControlWidth = false;
        bottomHL.childControlHeight = false;

        var progressText = MakeTMPText("ProgressText", font, 300, 40, bottomRow.transform);
        progressText.fontSize = 18;
        progressText.alignment = TextAlignmentOptions.Left;
        progressText.text = "0/20 击杀";

        var availableLabel = MakeTMPText("AvailableLabel", font, 200, 40, bottomRow.transform);
        availableLabel.fontSize = 18;
        availableLabel.color = new Color(1f, 0.84f, 0f);
        availableLabel.alignment = TextAlignmentOptions.Center;
        availableLabel.text = "暂无奖励可领取";

        var refreshBtn = MakeTextButton("RefreshBtn", "刷新", font, 80, 36, bottomRow.transform);
        var claimAllBtn = MakeTextButton("ClaimAllBtn", "全部领取", font, 100, 36, bottomRow.transform);
        claimAllBtn.GetComponent<Image>().color = new Color(0.2f, 0.6f, 0.2f);

        // ── 加载指示器 ──
        var loadingGo = MakeUIObj("LoadingIndicator", 100, 30, panel.transform);
        var loadingTmp = loadingGo.AddComponent<TextMeshProUGUI>();
        if (font != null) loadingTmp.font = font;
        loadingTmp.fontSize = 16;
        loadingTmp.color = new Color(0.6f, 0.6f, 0.6f);
        loadingTmp.alignment = TextAlignmentOptions.Center;
        loadingTmp.text = "加载中...";
        loadingGo.SetActive(false);

        // ── 领奖弹窗 ──
        var rewardPopup = CreateRewardPopup(panel.transform, font);

        // ── 挂脚本 ──
        var script = panel.AddComponent<BattlePassUI>();
        SetPrivateField(script, "panelRoot", panel);
        SetPrivateField(script, "nodesScrollRect", scrollView.GetComponent<ScrollRect>());
        SetPrivateField(script, "nodesContainer", nodesRow.GetComponent<RectTransform>());
        SetPrivateField(script, "nodePrefab", nodePrefab.GetComponent<BattlePassNodeUI>());
        SetPrivateField(script, "progressFill", fillImg);
        SetPrivateField(script, "progressBarRect", progressBar.GetComponent<RectTransform>());
        SetPrivateField(script, "progressText", progressText);
        SetPrivateField(script, "availableLabel", availableLabel);
        SetPrivateField(script, "closeButton", closeBtn.GetComponent<Button>());
        SetPrivateField(script, "refreshButton", refreshBtn.GetComponent<Button>());
        SetPrivateField(script, "claimAllButton", claimAllBtn.GetComponent<Button>());
        SetPrivateField(script, "loadingIndicator", loadingGo);
        SetPrivateField(script, "rewardPopup", rewardPopup.GetComponent<BattlePassRewardPopup>());

        panel.SetActive(false);
    }

    // ═══════════════════════════════════════════════
    //  领奖弹窗
    // ═══════════════════════════════════════════════

    static GameObject CreateRewardPopup(Transform parent, TMP_FontAsset font)
    {
        // 遮罩背景
        var overlay = MakeUIObj("RewardPopupOverlay", 0, 0, parent);
        var overlayRT = overlay.GetComponent<RectTransform>();
        overlayRT.anchorMin = Vector2.zero;
        overlayRT.anchorMax = Vector2.one;
        overlayRT.offsetMin = Vector2.zero;
        overlayRT.offsetMax = Vector2.zero;
        overlay.AddComponent<Image>().color = new Color(0, 0, 0, 0.5f);

        // 弹窗卡片（居中）
        var card = MakeUIObj("RewardCard", 260, 140, overlay.transform);
        var cardRT = card.GetComponent<RectTransform>();
        cardRT.anchorMin = new Vector2(0.5f, 0.5f);
        cardRT.anchorMax = new Vector2(0.5f, 0.5f);
        cardRT.anchoredPosition = Vector2.zero;
        card.AddComponent<Image>().color = new Color(0.15f, 0.15f, 0.15f, 0.95f);

        var vlg = card.AddComponent<VerticalLayoutGroup>();
        vlg.childAlignment = TextAnchor.MiddleCenter;
        vlg.spacing = 8;
        vlg.padding = new RectOffset(20, 20, 20, 20);
        vlg.childControlWidth = true;
        vlg.childControlHeight = false;

        // 金币图标
        var coinIcon = MakeUIObj("CoinIcon", 48, 48, card.transform);
        coinIcon.AddComponent<Image>().color = new Color(1f, 0.84f, 0f);

        // 文字 "获得 5 金币!"
        var rewardText = MakeTMPText("RewardText", font, 220, 36, card.transform);
        rewardText.fontSize = 24;
        rewardText.color = new Color(1f, 0.84f, 0f);
        rewardText.alignment = TextAlignmentOptions.Center;
        rewardText.text = "获得 5 金币!";

        // 挂脚本
        var script = overlay.AddComponent<BattlePassRewardPopup>();
        SetPrivateField(script, "popupRoot", overlay);
        SetPrivateField(script, "rewardText", rewardText);
        SetPrivateField(script, "coinIcon", coinIcon.GetComponent<Image>());

        overlay.SetActive(false);
        return overlay;
    }

    // ═══════════════════════════════════════════════
    //  "战令" 打开按钮
    // ═══════════════════════════════════════════════

    static void CreateBattlePassOpenButton(Transform canvas, TMP_FontAsset font)
    {
        var go = MakeUIObj("BattlePassOpenBtn", 120, 50, canvas);
        var rt = go.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(1, 1);
        rt.anchorMax = new Vector2(1, 1);
        rt.pivot = new Vector2(1, 1);
        rt.anchoredPosition = new Vector2(-20, -60);

        go.AddComponent<Image>().color = new Color(0.2f, 0.6f, 0.2f);
        var btn = go.AddComponent<Button>();

        var textGo = MakeUIObj("Text (TMP)", 108, 38, go.transform);
        var tmp = textGo.AddComponent<TextMeshProUGUI>();
        if (font != null) tmp.font = font;
        tmp.fontSize = 20;
        tmp.color = Color.white;
        tmp.alignment = TextAlignmentOptions.Center;
        tmp.text = "战令";

        go.AddComponent<BattlePassButton>();
    }

    // ═══════════════════════════════════════════════
    //  工具方法
    // ═══════════════════════════════════════════════

    static GameObject MakeUIObj(string name, float w, float h, Transform parent = null)
    {
        var go = new GameObject(name, typeof(RectTransform));
        if (parent != null) go.transform.SetParent(parent, false);
        go.transform.localScale = Vector3.one;
        var rt = go.GetComponent<RectTransform>();
        rt.sizeDelta = new Vector2(w, h);
        return go;
    }

    static GameObject MakePanel(string name, Transform parent, float w, float h)
    {
        var go = MakeUIObj(name, w, h, parent);
        go.AddComponent<Image>().color = new Color(0, 0, 0, 0.85f);
        var vlg = go.AddComponent<VerticalLayoutGroup>();
        vlg.childAlignment = TextAnchor.UpperCenter;
        vlg.padding = new RectOffset(16, 16, 12, 12);
        vlg.spacing = 10;
        vlg.childControlWidth = true;
        vlg.childControlHeight = false;
        return go;
    }

    static TMP_Text MakeTMPText(string name, TMP_FontAsset font, float w, float h, Transform parent)
    {
        var go = MakeUIObj(name, w, h, parent);
        var tmp = go.AddComponent<TextMeshProUGUI>();
        if (font != null) tmp.font = font;
        tmp.fontSize = 20;
        tmp.color = Color.white;
        return tmp;
    }

    static GameObject MakeTextButton(string name, string label, TMP_FontAsset font, float w, float h, Transform parent)
    {
        var go = MakeUIObj(name, w, h, parent);
        go.AddComponent<Image>().color = new Color(0.3f, 0.3f, 0.3f);
        var btn = go.AddComponent<Button>();

        var textGo = MakeUIObj("Text (TMP)", w - 4, h - 4, go.transform);
        var tmp = textGo.AddComponent<TextMeshProUGUI>();
        if (font != null) tmp.font = font;
        tmp.fontSize = 18;
        tmp.color = Color.white;
        tmp.alignment = TextAlignmentOptions.Center;
        tmp.text = label;

        return go;
    }

    static void SetRightAnchor(GameObject go)
    {
        var rt = go.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(1, 0.5f);
        rt.anchorMax = new Vector2(1, 0.5f);
        rt.pivot = new Vector2(1, 0.5f);
        rt.anchoredPosition = Vector2.zero;
    }

    /// <summary>水平 ScrollView，用于战令节点横向滚动。</summary>
    static GameObject MakeScrollViewH(string name, Transform parent, float w, float h)
    {
        var go = MakeUIObj(name, w, h, parent);
        var scrollRect = go.AddComponent<ScrollRect>();
        go.AddComponent<Image>().color = new Color(0.1f, 0.1f, 0.1f, 0f);
        go.AddComponent<Mask>();

        var viewport = MakeUIObj("Viewport", w, h, go.transform);
        viewport.AddComponent<Image>().color = Color.clear;
        viewport.AddComponent<Mask>();
        var vpRT = viewport.GetComponent<RectTransform>();
        vpRT.anchorMin = Vector2.zero; vpRT.anchorMax = Vector2.one;
        vpRT.offsetMin = Vector2.zero; vpRT.offsetMax = Vector2.zero;

        var content = MakeUIObj("Content", w * 2, h, viewport.transform);
        var cRT = content.GetComponent<RectTransform>();
        cRT.anchorMin = new Vector2(0, 0); cRT.anchorMax = new Vector2(0, 1);
        cRT.pivot = new Vector2(0, 0.5f);
        cRT.anchoredPosition = Vector2.zero;

        scrollRect.viewport = vpRT;
        scrollRect.content = cRT;
        scrollRect.horizontal = true;
        scrollRect.vertical = false;

        return go;
    }

    /// <summary>获取或创建白色填充 Sprite，供进度条 Filled Image 使用。</summary>
    static Sprite GetOrCreateWhiteSprite()
    {
        string assetPath = PrefabDir + "/WhiteFill.png";
        var existing = AssetDatabase.LoadAssetAtPath<Sprite>(assetPath);
        if (existing != null) return existing;

        var tex = new Texture2D(4, 4);
        var pixels = new Color[16];
        for (int i = 0; i < pixels.Length; i++) pixels[i] = Color.white;
        tex.SetPixels(pixels);
        tex.Apply();

        System.IO.File.WriteAllBytes(assetPath, tex.EncodeToPNG());
        Object.DestroyImmediate(tex);
        AssetDatabase.ImportAsset(assetPath);

        var importer = AssetImporter.GetAtPath(assetPath) as TextureImporter;
        if (importer != null)
        {
            importer.textureType = TextureImporterType.Sprite;
            importer.SaveAndReimport();
        }

        return AssetDatabase.LoadAssetAtPath<Sprite>(assetPath);
    }

    static TMP_FontAsset FindTMPFont()
    {
        var font = AssetDatabase.LoadAssetAtPath<TMP_FontAsset>(
            "Assets/TextMesh Pro/Resources/Fonts & Materials/LiberationSans SDF.asset");
        if (font != null) return font;

        var guids = AssetDatabase.FindAssets("t:TMP_FontAsset");
        if (guids.Length > 0)
        {
            string path = AssetDatabase.GUIDToAssetPath(guids[0]);
            return AssetDatabase.LoadAssetAtPath<TMP_FontAsset>(path);
        }

        Debug.LogWarning("[UOSBattlePassUIEditorSetup] 未找到 TMP_FontAsset，Text 可能无法正常显示。");
        return null;
    }

    static GameObject SavePrefab(GameObject go, string fileName)
    {
        string path = Path.Combine(PrefabDir, fileName);
        if (File.Exists(path))
        {
            GameObject existing = AssetDatabase.LoadAssetAtPath<GameObject>(path);
            if (existing != null)
                PrefabUtility.SaveAsPrefabAssetAndConnect(go, path, InteractionMode.AutomatedAction);
            else
                PrefabUtility.SaveAsPrefabAsset(go, path);
        }
        else
        {
            PrefabUtility.SaveAsPrefabAsset(go, path);
        }
        Object.DestroyImmediate(go);
        return AssetDatabase.LoadAssetAtPath<GameObject>(path);
    }

    static void SetPrivateField(object obj, string fieldName, object value)
    {
        var field = obj.GetType().GetField(fieldName,
            System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Public);
        if (field != null)
            field.SetValue(obj, value);
        else
            Debug.LogWarning($"UOSBattlePassUIEditorSetup: 字段 '{fieldName}' 未找到在 {obj.GetType().Name}");
    }
}
