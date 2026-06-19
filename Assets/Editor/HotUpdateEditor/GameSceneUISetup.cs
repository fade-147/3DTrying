using UnityEngine;
using UnityEngine.UI;
using TMPro;
using UnityEditor;
using UnityEditor.SceneManagement;
using Mirror;

/// <summary>
/// Editor tool: one-click creation of SettingsPanel + SurrenderVotePanel + SurrenderVoteManager
/// in the currently open GameScene. Run from menu: Tools -> Setup GameScene UI
///
/// Structure:
///   SettingsRoot (always active, has SettingsMenu)
///     L Panel (visual child, toggled by SettingsMenu)
///         Title / VolumeSlider / SensitivityXSlider / SensitivityYSlider / SurrenderButton
///   SurrenderVotePanel (inactive, has SurrenderVoteUI)
///     CountdownText / VoteProgressText
///   SurrenderVoteManager (has NetworkIdentity + SurrenderVoteManager)
/// </summary>
public class GameSceneUISetup : EditorWindow
{
    [MenuItem("Tools/Setup GameScene UI")]
    public static void SetupAll()
    {
        var scene = EditorSceneManager.GetActiveScene();
        if (!scene.name.Contains("Game"))
        {
            if (!EditorUtility.DisplayDialog("Not GameScene?",
                    $"Current scene is '{scene.name}'. Run anyway?", "Yes", "Cancel"))
                return;
        }

        var canvas = FindOrCreateCanvas();
        SetupSurrenderVoteManager();
        SetupSettings(canvas);
        SetupSurrenderVotePanel(canvas);

        EditorSceneManager.MarkSceneDirty(scene);
        Debug.Log("[Setup] GameScene UI created/updated. Check hierarchy.");
    }

    #region Canvas

    private static Canvas FindOrCreateCanvas()
    {
        Canvas canvas = Object.FindObjectOfType<Canvas>();
        if (canvas != null) return canvas;

        var go = new GameObject("Canvas");
        canvas = go.AddComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceOverlay;
        go.AddComponent<CanvasScaler>().uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        go.AddComponent<GraphicRaycaster>();
        Debug.Log("[Setup] Canvas created.");
        return canvas;
    }

    #endregion

    #region Settings (root always active, panel child toggles)

    private static void SetupSettings(Canvas canvas)
    {
        // Clean up old flat structure
        var oldFlat = canvas.transform.Find("SettingsPanel");
        if (oldFlat != null) Object.DestroyImmediate(oldFlat.gameObject);

        // --- SettingsRoot (always active) ---
        var root = GetOrCreateChild(canvas.transform, "SettingsRoot");
        var settingsMenu = root.gameObject.GetComponent<SettingsMenu>();
        if (settingsMenu == null)
            settingsMenu = root.gameObject.AddComponent<SettingsMenu>();
        root.gameObject.SetActive(true);

        // --- Panel (visual child, toggled) ---
        var panel = GetOrCreateChild(root, "Panel");
        panel.gameObject.SetActive(false); // hidden by default

        var panelRT = panel as RectTransform;
        panelRT.anchorMin = new Vector2(0.3f, 0.25f);
        panelRT.anchorMax = new Vector2(0.7f, 0.75f);
        panelRT.offsetMin = Vector2.zero;
        panelRT.offsetMax = Vector2.zero;

        // Background
        var bgImg = panel.gameObject.GetComponent<Image>();
        if (bgImg == null) bgImg = panel.gameObject.AddComponent<Image>();
        bgImg.color = new Color(0.1f, 0.1f, 0.1f, 0.92f);

        // Title
        var title = CreateText("Title", panel, "设  置", 32, TextAlignmentOptions.Center);
        var titleRT = title.GetComponent<RectTransform>();
        SetAnchors(titleRT, 0f, 0.84f, 1f, 0.95f);

        // Sliders
        var volSlider = CreateSlider("VolumeSlider", panel, "音量", 0f, 1f, 0.8f, 0.60f, 0.72f);
        var volSliderComp = volSlider.GetComponentInChildren<Slider>();

        var sensXSlider = CreateSlider("SensitivityXSlider", panel, "水平灵敏度", 0.1f, 1.9f, 1.0f, 0.42f, 0.54f);
        var sensXSliderComp = sensXSlider.GetComponentInChildren<Slider>();

        var sensYSlider = CreateSlider("SensitivityYSlider", panel, "垂直灵敏度", 0.1f, 1.9f, 1.0f, 0.24f, 0.36f);
        var sensYSliderComp = sensYSlider.GetComponentInChildren<Slider>();

        // Surrender button
        var surrenderBtn = CreateButton("SurrenderButton", panel, "发起投降",
            new Color(0.75f, 0.15f, 0.15f), 0.04f, 0.15f);
        var surrenderBtnComp = surrenderBtn.GetComponentInChildren<Button>();

        // --- SettingManager on root ---
        var settingMgr = root.gameObject.GetComponent<SettingManager>();
        if (settingMgr == null)
            settingMgr = root.gameObject.AddComponent<SettingManager>();
        settingMgr.volumeSlider = volSliderComp;
        settingMgr.sensitivityXSlider = sensXSliderComp;
        settingMgr.sensitivityYSlider = sensYSliderComp;
        settingMgr.surrenderButton = surrenderBtnComp;

        // Wire SettingsMenu serialized fields
        var so = new SerializedObject(settingsMenu);
        so.FindProperty("_panel").objectReferenceValue = panel.gameObject;
        so.FindProperty("_volumeSlider").objectReferenceValue = volSliderComp;
        so.FindProperty("_sensitivityXSlider").objectReferenceValue = sensXSliderComp;
        so.FindProperty("_sensitivityYSlider").objectReferenceValue = sensYSliderComp;
        so.FindProperty("_surrenderButton").objectReferenceValue = surrenderBtnComp;
        so.ApplyModifiedProperties();

        // Tag the root
        root.gameObject.tag = "Settings";

        Debug.Log("[Setup] SettingsRoot (always active) + Panel (hidden) created.");
    }

    #endregion

    #region Surrender Vote Panel

    private static void SetupSurrenderVotePanel(Canvas canvas)
    {
        var existing = canvas.transform.Find("SurrenderVotePanel");
        if (existing != null) Object.DestroyImmediate(existing.gameObject);

        var panel = new GameObject("SurrenderVotePanel", typeof(RectTransform));
        panel.transform.SetParent(canvas.transform, false);
        var panelRT = panel.GetComponent<RectTransform>();
        panelRT.anchorMin = new Vector2(0.25f, 0.3f);
        panelRT.anchorMax = new Vector2(0.75f, 0.7f);
        panelRT.offsetMin = Vector2.zero;
        panelRT.offsetMax = Vector2.zero;

        var bg = panel.AddComponent<Image>();
        bg.color = new Color(0.05f, 0.05f, 0.05f, 0.95f);

        var voteUI = panel.AddComponent<SurrenderVoteUI>();

        var countdownText = CreateText("CountdownText", panel.transform,
            "投降投票倒计时: 30 秒", 36, TextAlignmentOptions.Center);
        var cdRT = countdownText.GetComponent<RectTransform>();
        SetAnchors(cdRT, 0.05f, 0.7f, 0.95f, 0.9f);

        var progressText = CreateText("VoteProgressText", panel.transform,
            "F2 同意投降  |  F3 拒绝投降", 28, TextAlignmentOptions.Center);
        progressText.color = new Color(0.9f, 0.9f, 0.5f);
        var pgRT = progressText.GetComponent<RectTransform>();
        SetAnchors(pgRT, 0.05f, 0.3f, 0.95f, 0.6f);

        var so = new SerializedObject(voteUI);
        so.FindProperty("_panelRoot").objectReferenceValue = panel;
        so.FindProperty("_countdownText").objectReferenceValue = countdownText;
        so.FindProperty("_voteProgressText").objectReferenceValue = progressText;
        so.ApplyModifiedProperties();

        panel.SetActive(false);
        Debug.Log("[Setup] SurrenderVotePanel created.");
    }

    #endregion

    #region Surrender Vote Manager

    private static void SetupSurrenderVoteManager()
    {
        var existing = Object.FindObjectOfType<SurrenderVoteManager>();
        if (existing != null)
        {
            Debug.Log("[Setup] SurrenderVoteManager already exists, updating UI ref.");
            var canvas = FindOrCreateCanvas();
            var votePanel = canvas.transform.Find("SurrenderVotePanel");
            if (votePanel != null)
            {
                var ui = votePanel.GetComponent<SurrenderVoteUI>();
                var so = new SerializedObject(existing);
                so.FindProperty("_voteUI").objectReferenceValue = ui;
                so.ApplyModifiedProperties();
            }
            return;
        }

        var go = new GameObject("SurrenderVoteManager");
        go.AddComponent<NetworkIdentity>();
        go.AddComponent<SurrenderVoteManager>();

        var canvas2 = FindOrCreateCanvas();
        var sp = canvas2.transform.Find("SurrenderVotePanel");
        if (sp != null)
        {
            var ui = sp.GetComponent<SurrenderVoteUI>();
            var mgr = go.GetComponent<SurrenderVoteManager>();
            var so = new SerializedObject(mgr);
            so.FindProperty("_voteUI").objectReferenceValue = ui;
            so.ApplyModifiedProperties();
        }

        Debug.Log("[Setup] SurrenderVoteManager created.");
    }

    #endregion

    #region Helpers

    private static Transform GetOrCreateChild(Transform parent, string name)
    {
        var existing = parent.Find(name);
        if (existing != null) return existing;

        var go = new GameObject(name, typeof(RectTransform));
        go.transform.SetParent(parent, false);
        return go.transform;
    }

    private static void SetAnchors(RectTransform rt, float xMin, float yMin, float xMax, float yMax)
    {
        rt.anchorMin = new Vector2(xMin, yMin);
        rt.anchorMax = new Vector2(xMax, yMax);
        rt.offsetMin = Vector2.zero;
        rt.offsetMax = Vector2.zero;
    }

    private static TextMeshProUGUI CreateText(string name, Transform parent, string content,
        int fontSize, TextAlignmentOptions alignment)
    {
        var go = new GameObject(name, typeof(RectTransform));
        go.transform.SetParent(parent, false);
        var tmp = go.AddComponent<TextMeshProUGUI>();
        tmp.text = content;
        tmp.fontSize = fontSize;
        tmp.alignment = alignment;
        tmp.color = Color.white;
        return tmp;
    }

    private static GameObject CreateSlider(string name, Transform parent, string label,
        float min, float max, float defaultValue, float yAnchorMin, float yAnchorMax)
    {
        var container = new GameObject(name, typeof(RectTransform));
        container.transform.SetParent(parent, false);
        var crt = container.GetComponent<RectTransform>();
        SetAnchors(crt, 0.05f, yAnchorMin, 0.95f, yAnchorMax);

        // Label
        var labelGo = CreateText("Label", container.transform, label, 20, TextAlignmentOptions.Left);
        var lrt = labelGo.GetComponent<RectTransform>();
        SetAnchors(lrt, 0f, 0.1f, 0.3f, 0.9f);

        // Slider area
        var sliderArea = new GameObject("SliderArea", typeof(RectTransform));
        sliderArea.transform.SetParent(container.transform, false);
        var srt = sliderArea.GetComponent<RectTransform>();
        SetAnchors(srt, 0.32f, 0f, 1f, 1f);

        // Background
        var bgGo = new GameObject("Background", typeof(RectTransform), typeof(Image));
        bgGo.transform.SetParent(sliderArea.transform, false);
        var bgrt = bgGo.GetComponent<RectTransform>();
        SetAnchors(bgrt, 0f, 0.3f, 1f, 0.7f);
        bgGo.GetComponent<Image>().color = new Color(0.3f, 0.3f, 0.3f);

        // Fill Area
        var fillArea = new GameObject("Fill Area", typeof(RectTransform));
        fillArea.transform.SetParent(sliderArea.transform, false);
        SetAnchors(fillArea.GetComponent<RectTransform>(), 0f, 0.3f, 1f, 0.7f);

        // Fill
        var fillGo = new GameObject("Fill", typeof(RectTransform), typeof(Image));
        fillGo.transform.SetParent(fillArea.transform, false);
        var frt = fillGo.GetComponent<RectTransform>();
        frt.anchorMin = Vector2.zero;
        frt.anchorMax = Vector2.one;
        frt.offsetMin = Vector2.zero;
        frt.offsetMax = Vector2.zero;
        fillGo.GetComponent<Image>().color = new Color(0.5f, 0.5f, 0.9f);

        // Handle Slide Area
        var handleSlideArea = new GameObject("Handle Slide Area", typeof(RectTransform));
        handleSlideArea.transform.SetParent(sliderArea.transform, false);
        SetAnchors(handleSlideArea.GetComponent<RectTransform>(), 0f, 0f, 1f, 1f);

        // Handle
        var handleGo = new GameObject("Handle", typeof(RectTransform), typeof(Image));
        handleGo.transform.SetParent(handleSlideArea.transform, false);
        var hhrt = handleGo.GetComponent<RectTransform>();
        hhrt.anchorMin = new Vector2(0.5f, 0f);
        hhrt.anchorMax = new Vector2(0.5f, 1f);
        hhrt.sizeDelta = new Vector2(20, 0);
        handleGo.GetComponent<Image>().color = Color.white;

        // Slider component
        var slider = sliderArea.AddComponent<Slider>();
        slider.minValue = min;
        slider.maxValue = max;
        slider.value = defaultValue;
        slider.fillRect = frt;
        slider.handleRect = hhrt;
        slider.targetGraphic = handleGo.GetComponent<Image>();

        return container;
    }

    private static GameObject CreateButton(string name, Transform parent, string label,
        Color color, float yAnchorMin, float yAnchorMax)
    {
        var container = new GameObject(name, typeof(RectTransform));
        container.transform.SetParent(parent, false);
        var crt = container.GetComponent<RectTransform>();
        SetAnchors(crt, 0.2f, yAnchorMin, 0.8f, yAnchorMax);

        var img = container.AddComponent<Image>();
        img.color = color;

        var btn = container.AddComponent<Button>();
        btn.targetGraphic = img;

        var labelGo = CreateText("Text", container.transform, label, 24, TextAlignmentOptions.Center);
        var lrt = labelGo.GetComponent<RectTransform>();
        lrt.anchorMin = Vector2.zero;
        lrt.anchorMax = Vector2.one;
        lrt.offsetMin = Vector2.zero;
        lrt.offsetMax = Vector2.zero;

        return container;
    }

    #endregion
}
