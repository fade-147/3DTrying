using System.IO;
using TMPro;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 一键创建 UOS 收件箱系统 + 金币显示的所有 UI GameObject。
/// 菜单: Tools → UOS → Create All Inbox UI
/// 注意：请先打开 StartScene，确保场景中有 Canvas。
/// </summary>
public static class UOSInboxUIEditorSetup
{
    private const string PrefabDir = "Assets/Scripts/Prefab";

    [MenuItem("Tools/UOS/Create All Inbox UI")]
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

        // ── 1. 创建 Prefabs ──
        GameObject inboxEntry = CreateInboxEntryPrefab(font);
        GameObject attachmentEntry = CreateAttachmentEntryPrefab(font);

        // ── 2. 创建场景内 UI ──
        CreateGoldDisplay(canvas.transform, font);
        CreateInboxPanel(canvas.transform, inboxEntry, attachmentEntry, font);

        Selection.activeGameObject = canvas.gameObject;
        EditorUtility.DisplayDialog("完成",
            "已创建 GoldDisplay + InboxPanel (在 Canvas 下) + 2 个 Prefab。\n"
            + "请在 StartScene 找一个按钮，将其 onClick 绑定到 InboxPanel 的 UOSInboxUI.Show()。", "确定");
    }

    // ═══════════════════════════════════════════════
    //  Prefab: InboxEntry（邮件列表条目）
    // ═══════════════════════════════════════════════

    static GameObject CreateInboxEntryPrefab(TMP_FontAsset font)
    {
        // 根: 宽 580 高 56，水平布局，有 Button 组件用于点击
        GameObject go = MakeUIObj("InboxEntry", 580, 56);
        var btn = go.AddComponent<Button>();
        go.AddComponent<Image>().color = new Color(0.18f, 0.18f, 0.18f, 0.9f);

        var layout = go.AddComponent<HorizontalLayoutGroup>();
        layout.childAlignment = TextAnchor.MiddleLeft;
        layout.padding = new RectOffset(12, 12, 0, 0);
        layout.spacing = 12;
        layout.childControlWidth = false;
        layout.childControlHeight = false;
        layout.childForceExpandWidth = false;
        layout.childForceExpandHeight = false;

        // 状态图标 (圆形 Image，20x20)
        var statusIcon = MakeUIObj("StatusIcon", 20, 20, go.transform);
        var statusImg = statusIcon.AddComponent<Image>();
        statusImg.color = Color.red;

        // 标题
        var titleText = MakeTMPText("TitleText", font, 320, 56, go.transform);
        titleText.fontSize = 22;
        titleText.alignment = TextAlignmentOptions.Left;

        // 时间
        var timeText = MakeTMPText("TimeText", font, 140, 56, go.transform);
        timeText.fontSize = 18;
        timeText.color = new Color(0.6f, 0.6f, 0.6f);
        timeText.alignment = TextAlignmentOptions.Right;

        // 挂脚本
        var script = go.AddComponent<UOSInboxEntryUI>();
        SetPrivateField(script, "titleText", titleText);
        SetPrivateField(script, "timeText", timeText);
        SetPrivateField(script, "statusIcon", statusImg);
        SetPrivateField(script, "button", btn);

        return SavePrefab(go, "InboxEntry.prefab");
    }

    // ═══════════════════════════════════════════════
    //  Prefab: AttachmentEntry（附件单行条目）
    // ═══════════════════════════════════════════════

    static GameObject CreateAttachmentEntryPrefab(TMP_FontAsset font)
    {
        GameObject go = MakeUIObj("AttachmentEntry", 360, 36);
        var tmp = go.AddComponent<TextMeshProUGUI>();
        if (font != null) tmp.font = font;
        tmp.fontSize = 20;
        tmp.color = new Color(0.9f, 0.8f, 0.3f);
        tmp.alignment = TextAlignmentOptions.Left;
        tmp.text = "物品 × 1";

        return SavePrefab(go, "AttachmentEntry.prefab");
    }

    // ═══════════════════════════════════════════════
    //  场景 UI: GoldDisplay（金币显示）
    // ═══════════════════════════════════════════════

    static void CreateGoldDisplay(Transform canvas, TMP_FontAsset font)
    {
        // 放在左上角
        var go = MakeUIObj("GoldDisplay", 250, 50, canvas);
        var rt = go.GetComponent<RectTransform>();
        rt.anchorMin = new Vector2(0, 1);
        rt.anchorMax = new Vector2(0, 1);
        rt.pivot = new Vector2(0, 1);
        rt.anchoredPosition = new Vector2(20, -20);

        var layout = go.AddComponent<HorizontalLayoutGroup>();
        layout.childAlignment = TextAnchor.MiddleLeft;
        layout.spacing = 8;
        layout.childControlWidth = false;
        layout.childControlHeight = false;

        // 金币文本
        var goldText = MakeTMPText("GoldText", font, 180, 50, go.transform);
        goldText.fontSize = 28;
        goldText.color = new Color(1f, 0.85f, 0.2f);
        goldText.alignment = TextAlignmentOptions.Left;
        goldText.text = "金币: 0";

        // 刷新按钮
        var refreshBtn = MakeTextButton("RefreshGoldBtn", "刷", font, 50, 40, go.transform);
        refreshBtn.GetComponent<Image>().color = new Color(0.25f, 0.25f, 0.25f, 0.6f);

        var script = go.AddComponent<GoldDisplayUI>();
        SetPrivateField(script, "goldText", goldText);
        SetPrivateField(script, "refreshButton", refreshBtn.GetComponent<Button>());
    }

    // ═══════════════════════════════════════════════
    //  场景 UI: InboxPanel（收件箱主面板 + 详情弹窗）
    // ═══════════════════════════════════════════════

    static void CreateInboxPanel(Transform canvas, GameObject inboxEntry, GameObject attachmentEntry, TMP_FontAsset font)
    {
        var panel = MakePanel("InboxPanel", canvas, 640, 520);

        // 标题行
        var titleRow = MakeUIObj("TitleRow", 600, 44, panel.transform);
        var titleHL = titleRow.AddComponent<HorizontalLayoutGroup>();
        titleHL.childAlignment = TextAnchor.MiddleLeft;
        titleHL.spacing = 16;
        titleHL.childControlWidth = false;
        titleHL.childControlHeight = false;

        var titleText = MakeTMPText("Title", font, 120, 44, titleRow.transform);
        titleText.fontSize = 28;
        titleText.text = "收件箱";
        titleText.alignment = TextAlignmentOptions.Left;

        // 右上角关闭
        var closeBtn = MakeTextButton("CloseBtn", "X", font, 50, 44, titleRow.transform);
        SetRightAnchor(closeBtn);

        // 按钮行
        var btnRow = MakeUIObj("ButtonRow", 600, 40, panel.transform);
        var btnHL = btnRow.AddComponent<HorizontalLayoutGroup>();
        btnHL.spacing = 10;
        btnHL.childAlignment = TextAnchor.MiddleCenter;
        btnHL.childControlWidth = false;
        btnHL.childControlHeight = false;

        var consumeAllBtn = MakeTextButton("ConsumeAllBtn", "全部领取", font, 140, 40, btnRow.transform);
        var deleteAllBtn = MakeTextButton("DeleteAllBtn", "删除已完成", font, 140, 40, btnRow.transform);
        var refreshBtn = MakeTextButton("RefreshBtn", "刷新", font, 100, 40, btnRow.transform);

        // ScrollView
        var scrollView = MakeScrollView("InboxScrollView", panel.transform, 600, 320);
        var content = scrollView.transform.Find("Viewport/Content");
        // 调整 Content 布局
        var cVlg = content.GetComponent<VerticalLayoutGroup>();
        cVlg.childAlignment = TextAnchor.UpperCenter;
        cVlg.spacing = 4;
        cVlg.padding = new RectOffset(4, 4, 4, 4);

        // 状态文本
        var emptyH = MakeTMPText("EmptyHint", font, 300, 30, panel.transform);
        emptyH.text = "暂无邮件";
        emptyH.alignment = TextAlignmentOptions.Center;
        emptyH.gameObject.SetActive(false);

        var loadingH = MakeTMPText("Loading", font, 100, 30, panel.transform);
        loadingH.text = "加载中...";
        loadingH.alignment = TextAlignmentOptions.Center;
        loadingH.gameObject.SetActive(false);

        var totalText = MakeTMPText("TotalText", font, 200, 30, panel.transform);
        totalText.text = "共 0 封邮件";
        totalText.fontSize = 16;
        totalText.color = new Color(0.5f, 0.5f, 0.5f);
        totalText.alignment = TextAlignmentOptions.Center;

        // ── 详情弹窗（嵌套在 InboxPanel 下） ──
        var detailPanel = CreateDetailPanel(panel.transform, attachmentEntry, font);

        // ── 挂脚本 ──
        var script = panel.AddComponent<UOSInboxUI>();
        SetPrivateField(script, "panelRoot", panel);
        SetPrivateField(script, "contentParent", content.GetComponent<RectTransform>());
        SetPrivateField(script, "entryPrefab", inboxEntry.GetComponent<UOSInboxEntryUI>());
        SetPrivateField(script, "refreshButton", refreshBtn.GetComponent<Button>());
        SetPrivateField(script, "closeButton", closeBtn.GetComponent<Button>());
        SetPrivateField(script, "consumeAllButton", consumeAllBtn.GetComponent<Button>());
        SetPrivateField(script, "deleteAllButton", deleteAllBtn.GetComponent<Button>());
        SetPrivateField(script, "loadingIndicator", loadingH.gameObject);
        SetPrivateField(script, "emptyHint", emptyH.gameObject);
        SetPrivateField(script, "totalText", totalText.GetComponent<TMP_Text>());
        SetPrivateField(script, "detailPanel", detailPanel.GetComponent<UOSInboxDetailUI>());

        panel.SetActive(false);
    }

    static GameObject CreateDetailPanel(Transform parent, GameObject attachmentEntry, TMP_FontAsset font)
    {
        // 遮罩背景
        var overlay = MakeUIObj("DetailOverlay", 0, 0, parent);
        var overlayRT = overlay.GetComponent<RectTransform>();
        overlayRT.anchorMin = Vector2.zero;
        overlayRT.anchorMax = Vector2.one;
        overlayRT.offsetMin = Vector2.zero;
        overlayRT.offsetMax = Vector2.zero;
        overlay.AddComponent<Image>().color = new Color(0, 0, 0, 0.6f);

        // 详情面板（居中）
        var panel = MakeUIObj("DetailPanel", 560, 460, overlay.transform);
        var panelRT = panel.GetComponent<RectTransform>();
        panelRT.anchorMin = new Vector2(0.5f, 0.5f);
        panelRT.anchorMax = new Vector2(0.5f, 0.5f);
        panelRT.anchoredPosition = Vector2.zero;
        panel.AddComponent<Image>().color = new Color(0.12f, 0.12f, 0.12f, 0.95f);
        var vlg = panel.AddComponent<VerticalLayoutGroup>();
        vlg.childAlignment = TextAnchor.UpperCenter;
        vlg.padding = new RectOffset(20, 20, 16, 16);
        vlg.spacing = 8;
        vlg.childControlWidth = true;
        vlg.childControlHeight = false;

        // 标题行
        var titleRow = MakeUIObj("TitleRow", 520, 40, panel.transform);
        var thl = titleRow.AddComponent<HorizontalLayoutGroup>();
        thl.childAlignment = TextAnchor.MiddleLeft;
        thl.childControlWidth = false;
        thl.childControlHeight = false;

        var titleText = MakeTMPText("TitleText", font, 400, 40, titleRow.transform);
        titleText.fontSize = 24;
        titleText.alignment = TextAlignmentOptions.Left;

        var closeBtn = MakeTextButton("CloseBtn", "X", font, 44, 40, titleRow.transform);
        SetRightAnchor(closeBtn);

        // 发送方
        var senderText = MakeTMPText("SenderText", font, 520, 28, panel.transform);
        senderText.fontSize = 16;
        senderText.color = new Color(0.5f, 0.5f, 0.5f);
        senderText.alignment = TextAlignmentOptions.Left;

        // 时间
        var timeText = MakeTMPText("TimeText", font, 520, 28, panel.transform);
        timeText.fontSize = 16;
        timeText.color = new Color(0.5f, 0.5f, 0.5f);
        timeText.alignment = TextAlignmentOptions.Left;

        // 分隔线
        var sep = MakeUIObj("Separator", 520, 2, panel.transform);
        sep.AddComponent<Image>().color = new Color(0.3f, 0.3f, 0.3f);

        // 正文
        var bodyText = MakeTMPText("BodyText", font, 520, 140, panel.transform);
        bodyText.fontSize = 18;
        bodyText.alignment = TextAlignmentOptions.Left;
        bodyText.enableWordWrapping = true;

        // 附件区域标题
        var attachTitle = MakeTMPText("AttachmentTitle", font, 520, 28, panel.transform);
        attachTitle.fontSize = 18;
        attachTitle.color = new Color(0.8f, 0.8f, 0.8f);
        attachTitle.text = "附件:";
        attachTitle.alignment = TextAlignmentOptions.Left;

        // 附件列表
        var attachScroll = MakeScrollView("AttachmentScroll", panel.transform, 520, 80);
        var attachContent = attachScroll.transform.Find("Viewport/Content");

        // 按钮行
        var btnRow = MakeUIObj("ButtonRow", 520, 48, panel.transform);
        var bhl = btnRow.AddComponent<HorizontalLayoutGroup>();
        bhl.spacing = 16;
        bhl.childAlignment = TextAnchor.MiddleCenter;
        bhl.childControlWidth = false;
        bhl.childControlHeight = false;

        var consumeBtn = MakeTextButton("ConsumeBtn", "领取奖励", font, 160, 44, btnRow.transform);
        consumeBtn.GetComponent<Image>().color = new Color(0.2f, 0.6f, 0.2f);

        var deleteBtn = MakeTextButton("DeleteBtn", "删除", font, 100, 44, btnRow.transform);
        deleteBtn.GetComponent<Image>().color = new Color(0.6f, 0.2f, 0.2f);

        var loading = MakeUIObj("LoadingIndicator", 100, 30, panel.transform);
        var loadTmp = loading.AddComponent<TextMeshProUGUI>();
        if (font != null) loadTmp.font = font;
        loadTmp.fontSize = 16;
        loadTmp.text = "处理中...";
        loadTmp.alignment = TextAlignmentOptions.Center;
        loading.SetActive(false);

        // ── 挂脚本 ──
        var script = panel.AddComponent<UOSInboxDetailUI>();
        SetPrivateField(script, "panelRoot", overlay);
        SetPrivateField(script, "titleText", titleText);
        SetPrivateField(script, "senderText", senderText);
        SetPrivateField(script, "timeText", timeText);
        SetPrivateField(script, "bodyText", bodyText);
        SetPrivateField(script, "attachmentParent", attachContent.GetComponent<RectTransform>());
        SetPrivateField(script, "attachmentEntryPrefab", attachmentEntry);
        SetPrivateField(script, "consumeButton", consumeBtn.GetComponent<Button>());
        SetPrivateField(script, "deleteButton", deleteBtn.GetComponent<Button>());
        SetPrivateField(script, "closeButton", closeBtn.GetComponent<Button>());
        SetPrivateField(script, "loadingIndicator", loading);

        overlay.SetActive(false);
        return overlay;
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
        go.AddComponent<Image>().color = new Color(0, 0, 0, 0.8f);
        var vlg = go.AddComponent<VerticalLayoutGroup>();
        vlg.childAlignment = TextAnchor.UpperCenter;
        vlg.padding = new RectOffset(16, 16, 12, 12);
        vlg.spacing = 8;
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

    static GameObject MakeScrollView(string name, Transform parent, float w, float h)
    {
        var go = MakeUIObj(name, w, h, parent);
        var scrollRect = go.AddComponent<ScrollRect>();
        go.AddComponent<Image>().color = new Color(0.1f, 0.1f, 0.1f, 0.5f);
        go.AddComponent<Mask>();

        var viewport = MakeUIObj("Viewport", w, h, go.transform);
        viewport.AddComponent<Image>().color = Color.clear;
        viewport.AddComponent<Mask>();
        var vpRT = viewport.GetComponent<RectTransform>();
        vpRT.anchorMin = Vector2.zero; vpRT.anchorMax = Vector2.one;
        vpRT.offsetMin = Vector2.zero; vpRT.offsetMax = Vector2.zero;

        var content = MakeUIObj("Content", w, h, viewport.transform);
        var cRT = content.GetComponent<RectTransform>();
        cRT.anchorMin = new Vector2(0, 1); cRT.anchorMax = new Vector2(1, 1);
        cRT.pivot = new Vector2(0.5f, 1);
        cRT.anchoredPosition = Vector2.zero;
        var cVlg = content.AddComponent<VerticalLayoutGroup>();
        cVlg.childAlignment = TextAnchor.UpperCenter;
        cVlg.spacing = 4;
        cVlg.padding = new RectOffset(4, 4, 4, 4);
        cVlg.childControlWidth = true;
        cVlg.childControlHeight = false;
        var cFitter = content.AddComponent<ContentSizeFitter>();
        cFitter.verticalFit = ContentSizeFitter.FitMode.PreferredSize;

        scrollRect.viewport = vpRT;
        scrollRect.content = cRT;
        scrollRect.horizontal = false;
        scrollRect.vertical = true;

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

    static TMP_FontAsset FindTMPFont()
    {
        // 与 UOSUIEditorSetup 使用相同的字体
        var font = AssetDatabase.LoadAssetAtPath<TMP_FontAsset>(
            "Assets/TextMesh Pro/Resources/Fonts & Materials/LiberationSans SDF.asset");
        if (font != null) return font;

        // 备用：搜索任意 TMP 字体
        var guids = AssetDatabase.FindAssets("t:TMP_FontAsset");
        if (guids.Length > 0)
        {
            string path = AssetDatabase.GUIDToAssetPath(guids[0]);
            return AssetDatabase.LoadAssetAtPath<TMP_FontAsset>(path);
        }

        Debug.LogWarning("[UOSInboxUIEditorSetup] 未找到 TMP_FontAsset，Text 可能无法正常显示。请手动拖入字体到创建的 UI 上。");
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
            Debug.LogWarning($"UOSInboxUIEditorSetup: 字段 '{fieldName}' 未找到在 {obj.GetType().Name}");
    }
}
