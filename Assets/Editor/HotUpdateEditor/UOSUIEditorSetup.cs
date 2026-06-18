using System.IO;
using TMPro;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 一键创建 UOS 好友系统的所有 UI GameObject。
/// 菜单: Tools → UOS → Create All Friend UI
/// 注意：请先打开 StartScene 或 LobbyScene，确保场景中有 Canvas。
/// </summary>
public static class UOSUIEditorSetup
{
    private const string PrefabDir = "Assets/Scripts/Prefab";

    [MenuItem("Tools/UOS/Create All Friend UI")]
    public static void CreateAllUI()
    {
        Canvas canvas = Object.FindObjectOfType<Canvas>();
        if (canvas == null)
        {
            EditorUtility.DisplayDialog("错误",
                "当前场景没有 Canvas。请打开 StartScene 或 LobbyScene（它们已有 Canvas）。", "确定");
            return;
        }

        if (!Directory.Exists(PrefabDir))
            Directory.CreateDirectory(PrefabDir);

        TMP_FontAsset font = FindTMPFont();

        // ── 1. 创建 Entry Prefabs ──
        GameObject friendEntry = CreateFriendEntryPrefab(font);
        GameObject addFriendEntry = CreateAddFriendEntryPrefab(font);
        GameObject requestEntry = CreateRequestEntryPrefab(font);
        GameObject lobbyCard = CreateLobbyCardPrefab(font);

        // ── 2. 创建面板（场景内，Canvas 下） ──
        CreateFriendListPanel(canvas.transform, friendEntry, addFriendEntry, requestEntry, font);
        CreateLobbyBrowserPanel(canvas.transform, lobbyCard, font);
        CreateAddFriendPanel(canvas.transform, addFriendEntry, font);
        CreateFriendRequestsPanel(canvas.transform, requestEntry, font);

        Selection.activeGameObject = canvas.gameObject;
        EditorUtility.DisplayDialog("完成",
            "已创建 4 个面板 (在 Canvas 下) + 4 个 Prefab。\n"
            + "面板默认隐藏 (SetActive=false)。请绑定打开按钮到对应 Show() 方法。", "确定");
    }

    // ═══════════════════════════════════════════════
    //  Prefab 创建
    // ═══════════════════════════════════════════════

    static GameObject CreateFriendEntryPrefab(TMP_FontAsset font)
    {
        // FriendEntry: 宽 400 高 56，水平排列
        GameObject go = MakeUIObj("FriendEntry", 400, 56);
        var layout = go.AddComponent<HorizontalLayoutGroup>();
        layout.childAlignment = TextAnchor.MiddleLeft;
        layout.padding = new RectOffset(8, 8, 0, 0);
        layout.spacing = 12;
        go.AddComponent<ContentSizeFitter>().horizontalFit = ContentSizeFitter.FitMode.Unconstrained;

        // 名字
        var nameT = MakeTMPText("Name", font, 180, 56, go.transform);
        // 状态
        var statusT = MakeTMPText("Status", font, 80, 56, go.transform);
        // 删除按钮
        var delBtn = MakeTextButton("DeleteBtn", "删除", font, 80, 36, go.transform);

        var script = go.AddComponent<UOSFriendEntryUI>();
        SetPrivateField(script, "nameText", nameT);
        SetPrivateField(script, "statusText", statusT);
        SetPrivateField(script, "deleteButton", delBtn.GetComponent<Button>());

        return SavePrefab(go, "FriendEntry.prefab");
    }

    static GameObject CreateAddFriendEntryPrefab(TMP_FontAsset font)
    {
        GameObject go = MakeUIObj("AddFriendEntry", 400, 48);
        var layout = go.AddComponent<HorizontalLayoutGroup>();
        layout.childAlignment = TextAnchor.MiddleLeft;
        layout.padding = new RectOffset(8, 8, 0, 0);
        layout.spacing = 12;

        var nameT = MakeTMPText("Name", font, 220, 48, go.transform);
        var btn = MakeTextButton("SendBtn", "发送请求", font, 120, 36, go.transform);

        var script = go.AddComponent<UOSAddFriendEntryUI>();
        SetPrivateField(script, "nameText", nameT);
        SetPrivateField(script, "sendRequestButton", btn.GetComponent<Button>());

        return SavePrefab(go, "AddFriendEntry.prefab");
    }

    static GameObject CreateRequestEntryPrefab(TMP_FontAsset font)
    {
        GameObject go = MakeUIObj("RequestEntry", 400, 48);
        var layout = go.AddComponent<HorizontalLayoutGroup>();
        layout.childAlignment = TextAnchor.MiddleLeft;
        layout.padding = new RectOffset(8, 8, 0, 0);
        layout.spacing = 12;

        var nameT = MakeTMPText("Name", font, 180, 48, go.transform);
        var acceptBtn = MakeTextButton("AcceptBtn", "接受", font, 70, 36, go.transform);
        var rejectBtn = MakeTextButton("RejectBtn", "拒绝", font, 70, 36, go.transform);

        var script = go.AddComponent<UOSRequestEntryUI>();
        SetPrivateField(script, "nameText", nameT);
        SetPrivateField(script, "acceptButton", acceptBtn.GetComponent<Button>());
        SetPrivateField(script, "rejectButton", rejectBtn.GetComponent<Button>());

        return SavePrefab(go, "RequestEntry.prefab");
    }

    static GameObject CreateLobbyCardPrefab(TMP_FontAsset font)
    {
        GameObject go = MakeUIObj("LobbyCard", 360, 100);
        var img = go.AddComponent<Image>();
        img.color = new Color(0.15f, 0.15f, 0.15f, 0.85f);

        var layout = go.AddComponent<VerticalLayoutGroup>();
        layout.childAlignment = TextAnchor.MiddleCenter;
        layout.padding = new RectOffset(16, 16, 8, 8);
        layout.spacing = 8;

        var nameT = MakeTMPText("FriendName", font, 300, 40, go.transform);
        nameT.alignment = TextAlignmentOptions.Center;
        var joinBtn = MakeTextButton("JoinBtn", "加入", font, 140, 40, go.transform);

        var script = go.AddComponent<UOSLobbyCardUI>();
        SetPrivateField(script, "backgroundImage", img);
        SetPrivateField(script, "friendNameText", nameT);
        SetPrivateField(script, "joinButton", joinBtn.GetComponent<Button>());

        return SavePrefab(go, "LobbyCard.prefab");
    }

    // ═══════════════════════════════════════════════
    //  面板创建（Canvas 下）
    // ═══════════════════════════════════════════════

    static void CreateFriendListPanel(Transform canvas, GameObject friendEntry,
        GameObject addFriendEntry, GameObject requestEntry, TMP_FontAsset font)
    {
        var panel = MakePanel("FriendListPanel", canvas);

        // ScrollView
        var scrollView = MakeScrollView("FriendScrollView", panel.transform, 380, 300);
        var content = scrollView.transform.Find("Viewport/Content");

        // 按钮行
        var btnRow = MakeUIObj("ButtonRow", 380, 40, panel.transform);
        var btnRowHL = btnRow.AddComponent<HorizontalLayoutGroup>();
        btnRowHL.spacing = 8;
        btnRowHL.childAlignment = TextAnchor.MiddleCenter;

        var refreshBtn = MakeTextButton("RefreshBtn", "刷新", font, 80, 36, btnRow.transform);
        var addBtn = MakeTextButton("AddFriendBtn", "添加好友", font, 120, 36, btnRow.transform);
        var reqBtn = MakeTextButton("RequestsBtn", "好友申请", font, 120, 36, btnRow.transform);

        var emptyH = MakeTMPText("EmptyHint", font, 300, 30, panel.transform);
        emptyH.text = "暂无好友";
        emptyH.alignment = TextAlignmentOptions.Center;
        emptyH.gameObject.SetActive(false);

        var loadingH = MakeTMPText("Loading", font, 100, 30, panel.transform);
        loadingH.text = "加载中...";
        loadingH.gameObject.SetActive(false);

        // 子面板引用 — 创建后赋值
        var script = panel.AddComponent<UOSFriendListUI>();
        SetPrivateField(script, "panelRoot", panel);
        SetPrivateField(script, "contentParent", content.GetComponent<RectTransform>());
        SetPrivateField(script, "entryPrefab", friendEntry.GetComponent<UOSFriendEntryUI>());
        SetPrivateField(script, "refreshButton", refreshBtn.GetComponent<Button>());
        SetPrivateField(script, "addFriendButton", addBtn.GetComponent<Button>());
        SetPrivateField(script, "friendRequestsButton", reqBtn.GetComponent<Button>());
        SetPrivateField(script, "loadingIndicator", loadingH.gameObject);
        SetPrivateField(script, "emptyHint", emptyH.gameObject);
        // addFriendPanel 和 friendRequestsPanel 由下文赋值

        // 创建子面板（嵌套在 FriendListPanel 下）
        var addFriendPanel = CreateAddFriendPanel(panel.transform, addFriendEntry, font);
        var requestsPanel = CreateFriendRequestsPanel(panel.transform, requestEntry, font);

        SetPrivateField(script, "addFriendPanel", addFriendPanel.GetComponent<UOSAddFriendUI>());
        SetPrivateField(script, "friendRequestsPanel", requestsPanel.GetComponent<UOSFriendRequestsUI>());

        panel.SetActive(false);
    }

    static void CreateLobbyBrowserPanel(Transform canvas, GameObject lobbyCard, TMP_FontAsset font)
    {
        var panel = MakePanel("LobbyBrowserPanel", canvas);

        var scrollView = MakeScrollView("LobbyScrollView", panel.transform, 380, 300);
        var content = scrollView.transform.Find("Viewport/Content");

        var refreshBtn = MakeTextButton("RefreshBtn", "刷新", font, 80, 36, panel.transform);

        var emptyH = MakeTMPText("EmptyHint", font, 300, 30, panel.transform);
        emptyH.text = "当前没有好友在大厅";
        emptyH.alignment = TextAlignmentOptions.Center;
        emptyH.gameObject.SetActive(false);

        var loadingH = MakeTMPText("Loading", font, 100, 30, panel.transform);
        loadingH.text = "加载中...";
        loadingH.gameObject.SetActive(false);

        var closeBtn = MakeTextButton("CloseBtn", "关闭", font, 80, 36, panel.transform);

        var script = panel.AddComponent<UOSLobbyBrowserUI>();
        SetPrivateField(script, "panelRoot", panel);
        SetPrivateField(script, "contentParent", content.GetComponent<RectTransform>());
        SetPrivateField(script, "cardPrefab", lobbyCard.GetComponent<UOSLobbyCardUI>());
        SetPrivateField(script, "refreshButton", refreshBtn.GetComponent<Button>());
        SetPrivateField(script, "loadingIndicator", loadingH.gameObject);
        SetPrivateField(script, "emptyHint", emptyH.gameObject);
        SetPrivateField(script, "closeButton", closeBtn.GetComponent<Button>());

        panel.SetActive(false);
    }

    static GameObject CreateAddFriendPanel(Transform parent, GameObject addFriendEntry, TMP_FontAsset font)
    {
        var panel = MakePanel("AddFriendPanel", parent);

        var inputRow = MakeUIObj("InputRow", 380, 40, panel.transform);
        var hl = inputRow.AddComponent<HorizontalLayoutGroup>();
        hl.spacing = 8;

        var inputField = MakeTMPInput("SearchInput", font, 260, 36, inputRow.transform);
        var searchBtn = MakeTextButton("SearchBtn", "搜索", font, 80, 36, inputRow.transform);

        var scrollView = MakeScrollView("ResultScrollView", panel.transform, 380, 260);
        var content = scrollView.transform.Find("Viewport/Content");

        var emptyH = MakeTMPText("EmptyHint", font, 300, 30, panel.transform);
        emptyH.text = "未找到玩家";
        emptyH.alignment = TextAlignmentOptions.Center;
        emptyH.gameObject.SetActive(false);

        var loadingH = MakeTMPText("Loading", font, 100, 30, panel.transform);
        loadingH.text = "加载中...";
        loadingH.gameObject.SetActive(false);

        var closeBtn = MakeTextButton("CloseBtn", "关闭", font, 80, 36, panel.transform);

        var script = panel.AddComponent<UOSAddFriendUI>();
        SetPrivateField(script, "panelRoot", panel);
        SetPrivateField(script, "searchInput", inputField);
        SetPrivateField(script, "searchButton", searchBtn.GetComponent<Button>());
        SetPrivateField(script, "contentParent", content.GetComponent<RectTransform>());
        SetPrivateField(script, "entryPrefab", addFriendEntry.GetComponent<UOSAddFriendEntryUI>());
        SetPrivateField(script, "loadingIndicator", loadingH.gameObject);
        SetPrivateField(script, "emptyHint", emptyH.gameObject);
        SetPrivateField(script, "closeButton", closeBtn.GetComponent<Button>());

        panel.SetActive(false);
        return panel;
    }

    static GameObject CreateFriendRequestsPanel(Transform parent, GameObject requestEntry, TMP_FontAsset font)
    {
        var panel = MakePanel("FriendRequestsPanel", parent);

        var scrollView = MakeScrollView("RequestsScrollView", panel.transform, 380, 280);
        var content = scrollView.transform.Find("Viewport/Content");

        var btnRow = MakeUIObj("BtnRow", 380, 40, panel.transform);
        var hl = btnRow.AddComponent<HorizontalLayoutGroup>();
        hl.spacing = 8;
        hl.childAlignment = TextAnchor.MiddleCenter;

        var refreshBtn = MakeTextButton("RefreshBtn", "刷新", font, 80, 36, btnRow.transform);
        var closeBtn = MakeTextButton("CloseBtn", "关闭", font, 80, 36, btnRow.transform);

        var emptyH = MakeTMPText("EmptyHint", font, 300, 30, panel.transform);
        emptyH.text = "没有待处理的好友请求";
        emptyH.alignment = TextAlignmentOptions.Center;
        emptyH.gameObject.SetActive(false);

        var loadingH = MakeTMPText("Loading", font, 100, 30, panel.transform);
        loadingH.text = "加载中...";
        loadingH.gameObject.SetActive(false);

        var script = panel.AddComponent<UOSFriendRequestsUI>();
        SetPrivateField(script, "panelRoot", panel);
        SetPrivateField(script, "contentParent", content.GetComponent<RectTransform>());
        SetPrivateField(script, "entryPrefab", requestEntry.GetComponent<UOSRequestEntryUI>());
        SetPrivateField(script, "refreshButton", refreshBtn.GetComponent<Button>());
        SetPrivateField(script, "loadingIndicator", loadingH.gameObject);
        SetPrivateField(script, "emptyHint", emptyH.gameObject);
        SetPrivateField(script, "closeButton", closeBtn.GetComponent<Button>());

        panel.SetActive(false);
        return panel;
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

    static GameObject MakePanel(string name, Transform parent)
    {
        var go = MakeUIObj(name, 420, 440, parent);
        go.AddComponent<Image>().color = new Color(0, 0, 0, 0.7f);
        var vlg = go.AddComponent<VerticalLayoutGroup>();
        vlg.childAlignment = TextAnchor.UpperCenter;
        vlg.padding = new RectOffset(16, 16, 16, 16);
        vlg.spacing = 8;
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

        var textGo = MakeUIObj("Text (TMP)", w, h, go.transform);
        var tmp = textGo.AddComponent<TextMeshProUGUI>();
        if (font != null) tmp.font = font;
        tmp.fontSize = 18;
        tmp.color = Color.white;
        tmp.alignment = TextAlignmentOptions.Center;
        tmp.text = label;

        return go;
    }

    static TMP_InputField MakeTMPInput(string name, TMP_FontAsset font, float w, float h, Transform parent)
    {
        var go = MakeUIObj(name, w, h, parent);
        go.AddComponent<Image>().color = new Color(0.2f, 0.2f, 0.2f);
        var input = go.AddComponent<TMP_InputField>();

        // 文本区域
        var textArea = MakeUIObj("Text Area", w - 16, h - 8, go.transform);
        var rt = textArea.GetComponent<RectTransform>();
        rt.anchorMin = Vector2.zero; rt.anchorMax = Vector2.one;
        rt.offsetMin = new Vector2(8, 4); rt.offsetMax = new Vector2(-8, -4);

        var placeholder = MakeUIObj("Placeholder", w - 24, h - 8, textArea.transform);
        var ph = placeholder.AddComponent<TextMeshProUGUI>();
        if (font != null) ph.font = font;
        ph.fontSize = 18; ph.color = new Color(0.5f, 0.5f, 0.5f);
        ph.text = "输入玩家名称...";
        ph.alignment = TextAlignmentOptions.Left;

        var textGo = MakeUIObj("Text", w - 24, h - 8, textArea.transform);
        var txt = textGo.AddComponent<TextMeshProUGUI>();
        if (font != null) txt.font = font;
        txt.fontSize = 18; txt.color = Color.white;
        txt.alignment = TextAlignmentOptions.Left;

        input.textViewport = textArea.GetComponent<RectTransform>();
        input.textComponent = txt;
        input.placeholder = ph;

        return input;
    }

    static GameObject MakeScrollView(string name, Transform parent, float w, float h)
    {
        // Use default UI ScrollView creation approach
        var go = MakeUIObj(name, w, h, parent);
        var scrollRect = go.AddComponent<ScrollRect>();
        go.AddComponent<Image>().color = new Color(0.1f, 0.1f, 0.1f, 0.5f);
        go.AddComponent<Mask>();

        // Viewport
        var viewport = MakeUIObj("Viewport", w, h, go.transform);
        viewport.AddComponent<Image>().color = Color.clear;
        viewport.AddComponent<Mask>();
        var vpRT = viewport.GetComponent<RectTransform>();
        vpRT.anchorMin = Vector2.zero; vpRT.anchorMax = Vector2.one;
        vpRT.offsetMin = Vector2.zero; vpRT.offsetMax = Vector2.zero;

        // Content
        var content = MakeUIObj("Content", w, h, viewport.transform);
        var cRT = content.GetComponent<RectTransform>();
        cRT.anchorMin = new Vector2(0, 1); cRT.anchorMax = new Vector2(1, 1);
        cRT.pivot = new Vector2(0.5f, 1);
        cRT.anchoredPosition = Vector2.zero;
        var cVlg = content.AddComponent<VerticalLayoutGroup>();
        cVlg.childAlignment = TextAnchor.UpperCenter;
        cVlg.spacing = 6;
        cVlg.padding = new RectOffset(8, 8, 8, 8);
        var cFitter = content.AddComponent<ContentSizeFitter>();
        cFitter.verticalFit = ContentSizeFitter.FitMode.PreferredSize;

        scrollRect.viewport = vpRT;
        scrollRect.content = cRT;
        scrollRect.horizontal = false;
        scrollRect.vertical = true;

        return go;
    }

    static TMP_FontAsset FindTMPFont()
    {
        return AssetDatabase.LoadAssetAtPath<TMP_FontAsset>(
            "Assets/TextMesh Pro/Resources/Fonts & Materials/LiberationSans SDF.asset");
    }

    static GameObject SavePrefab(GameObject go, string fileName)
    {
        string path = Path.Combine(PrefabDir, fileName);
        // 如果已存在则更新，否则创建
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
            Debug.LogWarning($"UOSUIEditorSetup: 字段 '{fieldName}' 未找到在 {obj.GetType().Name}");
    }
}
