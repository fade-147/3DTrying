using UnityEngine;
using UnityEditor;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// Editor 工具：一键生成背包 UI 和抽卡 UI 的完整 GameObject 层级。
/// 在菜单栏 Game → Setup Backpack UI 执行。
/// </summary>
public class BackpackUISetup : EditorWindow
{
    [MenuItem("Game/Setup Backpack & Gacha UI")]
    public static void SetupAll()
    {
        SetupCanvas();
        Debug.Log("[BackpackUISetup] UI created. Check scene hierarchy.");
    }

    private static GameObject SetupCanvas()
    {
        // If already exists and configured, skip
        var existing = GameObject.Find("BackpackCanvas");
        if (existing != null)
        {
            var bpUI = existing.GetComponentInChildren<BackpackUI>();
            if (bpUI != null && bpUI.itemIconPrefab != null)
            {
                Debug.Log("[BackpackUISetup] BackpackCanvas already configured, skipping.");
                return existing;
            }
        }

        // Find or create Canvas
        var canvasGo = existing;
        if (canvasGo == null)
        {
            canvasGo = new GameObject("BackpackCanvas");
            var canvas = canvasGo.AddComponent<Canvas>();
            canvas.renderMode = RenderMode.ScreenSpaceOverlay;
            canvasGo.AddComponent<CanvasScaler>()
                .uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
            canvasGo.AddComponent<GraphicRaycaster>();
        }

        // --- Gacha UI ---
        var gachaRoot = CreatePanel(canvasGo.transform, "GachaPanel");
        var gachaUI = gachaRoot.AddComponent<GachaUI>();
        gachaUI.panelRoot = gachaRoot;

        // Title
        CreateText(gachaRoot.transform, "GachaTitle", "🎯 抽卡", 36, TextAlignmentOptions.Center,
            new Vector2(0, 200), new Vector2(400, 60));

        // Gold
        var goldText = CreateText(gachaRoot.transform, "GoldText", "金币: --", 24, TextAlignmentOptions.Center,
            new Vector2(0, 100), new Vector2(300, 40));
        gachaUI.goldBalanceText = goldText;

        // Cost
        var costText = CreateText(gachaRoot.transform, "CostText", "消耗 10 金币", 20, TextAlignmentOptions.Center,
            new Vector2(0, 40), new Vector2(300, 40));
        gachaUI.pullCostText = costText;

        // Pull button
        var pullBtn = CreateButton(gachaRoot.transform, "PullButton", "抽奖！",
            new Vector2(0, -40), new Vector2(200, 60));
        gachaUI.singlePullButton = pullBtn;

        // Result text
        var resultText = CreateText(gachaRoot.transform, "ResultText", "", 22, TextAlignmentOptions.Center,
            new Vector2(0, -140), new Vector2(400, 60));
        gachaUI.resultText = resultText;

        // Result panel (animation)
        var resultPanel = new GameObject("ResultPanel");
        resultPanel.transform.SetParent(gachaRoot.transform, false);
        resultPanel.AddComponent<Image>().color = new Color(0, 0, 0, 0.8f);
        resultPanel.GetComponent<RectTransform>().sizeDelta = new Vector2(400, 300);
        gachaUI.resultPanel = resultPanel;
        resultPanel.SetActive(false);

        var resultIconGo = new GameObject("ResultIcon");
        resultIconGo.transform.SetParent(resultPanel.transform, false);
        gachaUI.resultIcon = resultIconGo.AddComponent<Image>();

        // Close button
        var closeBtn = CreateButton(gachaRoot.transform, "CloseButton", "✕",
            new Vector2(180, 200), new Vector2(40, 40));
        gachaUI.closeButton = closeBtn;

        // --- Backpack UI ---
        var backpackRoot = CreatePanel(canvasGo.transform, "BackpackPanel");
        var backpackUI = backpackRoot.AddComponent<BackpackUI>();
        backpackUI.panelRoot = backpackRoot;

        // Title
        CreateText(backpackRoot.transform, "Title", "背包 / 武器配置", 30, TextAlignmentOptions.Center,
            new Vector2(0, 280), new Vector2(400, 50));

        // Gold text
        var bpGold = CreateText(backpackRoot.transform, "GoldText", "金币: --", 22, TextAlignmentOptions.Left,
            new Vector2(500, 280), new Vector2(200, 40));
        backpackUI.goldText = bpGold;

        // Toggle button
        var toggleBtn = CreateButton(backpackRoot.transform, "ToggleViewBtn", "武器背包",
            new Vector2(500, 230), new Vector2(160, 40));
        backpackUI.toggleViewButton = toggleBtn;
        backpackUI.toggleViewLabel = toggleBtn.GetComponentInChildren<TextMeshProUGUI>();

        // Close button
        var bpClose = CreateButton(backpackRoot.transform, "CloseBtn", "✕",
            new Vector2(680, 280), new Vector2(40, 40));
        backpackUI.closeButton = bpClose;

        // Save button
        var saveBtn = CreateButton(backpackRoot.transform, "SaveBtn", "保存装备",
            new Vector2(500, 160), new Vector2(160, 40));
        backpackUI.saveButton = saveBtn;

        // --- Left: 3 Weapon Slots ---
        float[] slotYPositions = { 180f, 0f, -180f };
        string[] slotNames = { "Slot0_Pistol", "Slot1_Primary1", "Slot2_Primary2" };
        var slotList = new BackpackWeaponSlot[3];

        for (int i = 0; i < 3; i++)
        {
            var slotGo = new GameObject(slotNames[i], typeof(RectTransform));
            slotGo.transform.SetParent(backpackRoot.transform, false);
            var slotRect = slotGo.GetComponent<RectTransform>();
            slotRect.anchoredPosition = new Vector2(-450, slotYPositions[i]);
            slotRect.sizeDelta = new Vector2(260, 150);

            var slot = slotGo.AddComponent<BackpackWeaponSlot>();
            slot.slotIndex = i;

            // Weapon box (big)
            var weaponBox = new GameObject("WeaponBox", typeof(RectTransform));
            weaponBox.transform.SetParent(slotGo.transform, false);
            var wbRect = weaponBox.GetComponent<RectTransform>();
            wbRect.anchoredPosition = new Vector2(0, 50);
            wbRect.sizeDelta = new Vector2(240, 70);
            weaponBox.AddComponent<Image>().color = new Color(0.3f, 0.3f, 0.3f, 0.8f);
            var wbDrop = weaponBox.AddComponent<DropTarget>();
            wbDrop.targetType = DropTarget.TargetType.WeaponSlot;
            wbDrop.weaponSlotIndex = i;
            wbDrop.backpackUI = backpackUI;

            slot.weaponBox = weaponBox;
            slot.weaponDropTarget = wbDrop;

            // Weapon icon
            var wIconGo = new GameObject("WeaponIcon", typeof(RectTransform));
            wIconGo.transform.SetParent(weaponBox.transform, false);
            var wIconRect = wIconGo.GetComponent<RectTransform>();
            wIconRect.anchoredPosition = Vector2.zero;
            wIconRect.sizeDelta = new Vector2(50, 50);
            slot.weaponIcon = wIconGo.AddComponent<Image>();

            // Weapon name
            slot.weaponNameText = CreateText(weaponBox.transform, "WeaponName", "空", 14,
                TextAlignmentOptions.Center, new Vector2(40, 0), new Vector2(160, 30));

            // Weapon click button
            var wClickBtn = weaponBox.AddComponent<Button>();
            slot.weaponClickButton = wClickBtn;

            // 4 attachment slots (Scope, Muzzle, Laser, Grip)
            slot.attachmentSlots = new AttachmentSlotEntry[4];
            AttachmentCategory[] cats = {
                AttachmentCategory.Scope, AttachmentCategory.Muzzle,
                AttachmentCategory.Laser, AttachmentCategory.Grip
            };
            float[] attXPositions = { -72, -24, 24, 72 };

            for (int j = 0; j < 4; j++)
            {
                var attGo = new GameObject($"AttSlot_{cats[j]}", typeof(RectTransform));
                attGo.transform.SetParent(slotGo.transform, false);
                var attRect = attGo.GetComponent<RectTransform>();
                attRect.anchoredPosition = new Vector2(attXPositions[j], -35);
                attRect.sizeDelta = new Vector2(40, 40);
                attGo.AddComponent<Image>().color = new Color(0.2f, 0.2f, 0.2f, 0.8f);

                var attDrop = attGo.AddComponent<DropTarget>();
                attDrop.targetType = DropTarget.TargetType.AttachmentSlot;
                attDrop.weaponSlotIndex = i;
                attDrop.acceptedAttachmentCategory = cats[j];
                attDrop.backpackUI = backpackUI;

                var attEntry = new AttachmentSlotEntry
                {
                    category = cats[j],
                    root = attGo,
                    dropTarget = attDrop,
                };

                // Icon inside
                var attIconGo = new GameObject("Icon", typeof(RectTransform));
                attIconGo.transform.SetParent(attGo.transform, false);
                var attIconRect = attIconGo.GetComponent<RectTransform>();
                attIconRect.anchoredPosition = Vector2.zero;
                attIconRect.sizeDelta = new Vector2(32, 32);
                attEntry.icon = attIconGo.AddComponent<Image>();

                // Text label (fallback when no icon)
                var attLabelGo = new GameObject("Label", typeof(RectTransform));
                attLabelGo.transform.SetParent(attGo.transform, false);
                var attLabelRect = attLabelGo.GetComponent<RectTransform>();
                attLabelRect.anchoredPosition = Vector2.zero;
                attLabelRect.sizeDelta = new Vector2(36, 14);
                attEntry.label = attLabelGo.AddComponent<TMPro.TextMeshProUGUI>();
                attEntry.label.fontSize = 8;
                attEntry.label.alignment = TMPro.TextAlignmentOptions.Center;
                attEntry.label.color = Color.white;

                // Click button
                attEntry.clickButton = attGo.AddComponent<Button>();

                slot.attachmentSlots[j] = attEntry;
            }

            // Slot label
            string[] labels = { "手枪位", "主武器 1", "主武器 2" };
            slot.slotLabel = CreateText(slotGo.transform, "SlotLabel", labels[i], 14,
                TextAlignmentOptions.Center, new Vector2(0, -75), new Vector2(200, 20));

            slotList[i] = slot;
        }
        backpackUI.weaponSlots = slotList;

        // --- Right: Inventory Grid ---
        var gridGo = new GameObject("ItemGrid", typeof(RectTransform), typeof(ScrollRect), typeof(Image));
        gridGo.transform.SetParent(backpackRoot.transform, false);
        var gridRect = gridGo.GetComponent<RectTransform>();
        gridRect.anchoredPosition = new Vector2(150, 0);
        gridRect.sizeDelta = new Vector2(500, 500);
        gridGo.GetComponent<Image>().color = new Color(0.15f, 0.15f, 0.15f, 0.6f);

        // Viewport with Mask
        var viewport = new GameObject("Viewport", typeof(RectTransform), typeof(Image), typeof(Mask));
        viewport.transform.SetParent(gridGo.transform, false);
        var vpRect = viewport.GetComponent<RectTransform>();
        vpRect.anchorMin = Vector2.zero; vpRect.anchorMax = Vector2.one;
        vpRect.sizeDelta = Vector2.zero;
        viewport.GetComponent<Image>().color = new Color(0, 0, 0, 0); // invisible mask image

        // GridContent (scrolling)
        var gridContent = new GameObject("GridContent", typeof(RectTransform), typeof(GridLayoutGroup), typeof(ContentSizeFitter));
        gridContent.transform.SetParent(viewport.transform, false);
        var contentRect = gridContent.GetComponent<RectTransform>();
        contentRect.anchorMin = new Vector2(0, 1); contentRect.anchorMax = new Vector2(1, 1);
        contentRect.pivot = new Vector2(0.5f, 1f);
        contentRect.anchoredPosition = Vector2.zero;
        contentRect.sizeDelta = new Vector2(0, 0);
        var gridLayout = gridContent.GetComponent<GridLayoutGroup>();
        gridLayout.cellSize = new Vector2(80, 80);
        gridLayout.spacing = new Vector2(10, 10);
        gridLayout.padding = new RectOffset(10, 10, 10, 10);
        var fitter = gridContent.GetComponent<ContentSizeFitter>();
        fitter.verticalFit = ContentSizeFitter.FitMode.PreferredSize;

        var scrollRect = gridGo.GetComponent<ScrollRect>();
        scrollRect.content = contentRect;
        scrollRect.viewport = vpRect;
        scrollRect.horizontal = false;
        scrollRect.vertical = true;

        backpackUI.itemGridParent = gridContent;

        // --- Popups ---
        var weaponPopup = CreateWeaponPopup(backpackRoot.transform, "WeaponInfoPopup", out var wip);
        backpackUI.weaponInfoPopup = wip;

        var attPopup = CreateAttachmentPopup(backpackRoot.transform, "AttachmentInfoPopup", out var aip);
        backpackUI.attachmentInfoPopup = aip;

        // --- Item Icon Prefab: keep existing if already assigned ---
        if (backpackUI.itemIconPrefab == null)
            Debug.LogWarning("[BackpackUISetup] itemIconPrefab is null! Create a prefab and drag it in.");
        return canvasGo;
    }

    private static GameObject CreatePanel(Transform parent, string name)
    {
        var go = new GameObject(name, typeof(RectTransform), typeof(Image));
        go.transform.SetParent(parent, false);
        go.GetComponent<RectTransform>().sizeDelta = new Vector2(800, 600);
        go.GetComponent<Image>().color = new Color(0.1f, 0.1f, 0.12f, 0.95f);
        return go;
    }

    private static TextMeshProUGUI CreateText(Transform parent, string name, string text,
        int fontSize, TextAlignmentOptions align, Vector2 pos, Vector2 size)
    {
        var go = new GameObject(name, typeof(RectTransform));
        go.transform.SetParent(parent, false);
        var rt = go.GetComponent<RectTransform>();
        rt.anchoredPosition = pos;
        rt.sizeDelta = size;

        var tmp = go.AddComponent<TextMeshProUGUI>();
        tmp.text = text;
        tmp.fontSize = fontSize;
        tmp.alignment = align;
        tmp.color = Color.white;
        return tmp;
    }

    private static Button CreateButton(Transform parent, string name, string label,
        Vector2 pos, Vector2 size)
    {
        var go = new GameObject(name, typeof(RectTransform), typeof(Image), typeof(Button));
        go.transform.SetParent(parent, false);
        var rt = go.GetComponent<RectTransform>();
        rt.anchoredPosition = pos;
        rt.sizeDelta = size;

        var img = go.GetComponent<Image>();
        img.color = new Color(0.3f, 0.5f, 0.8f, 1f);

        // Label
        var labelGo = new GameObject("Label", typeof(RectTransform));
        labelGo.transform.SetParent(go.transform, false);
        var lrt = labelGo.GetComponent<RectTransform>();
        lrt.anchoredPosition = Vector2.zero;
        lrt.sizeDelta = size;

        var tmp = labelGo.AddComponent<TextMeshProUGUI>();
        tmp.text = label;
        tmp.fontSize = 18;
        tmp.alignment = TextAlignmentOptions.Center;
        tmp.color = Color.white;

        return go.GetComponent<Button>();
    }

    private static GameObject CreateWeaponPopup(Transform parent, string name, out WeaponInfoPopup popup)
    {
        var go = new GameObject(name, typeof(RectTransform), typeof(Image));
        go.transform.SetParent(parent, false);
        go.GetComponent<RectTransform>().sizeDelta = new Vector2(350, 400);
        go.GetComponent<Image>().color = new Color(0.15f, 0.15f, 0.2f, 0.98f);
        popup = go.AddComponent<WeaponInfoPopup>();
        popup.panelRoot = go;

        popup.icon = CreateImage(go.transform, "Icon", Vector2.up * 140, new Vector2(80, 80));
        popup.nameText = CreateText(go.transform, "Name", "武器名", 24, TextAlignmentOptions.Center,
            new Vector2(0, 80), new Vector2(300, 40));
        popup.descriptionText = CreateText(go.transform, "Desc", "", 16, TextAlignmentOptions.Center,
            new Vector2(0, 40), new Vector2(300, 60));
        popup.statsText = CreateText(go.transform, "Stats", "", 16, TextAlignmentOptions.Left,
            new Vector2(0, -80), new Vector2(300, 180));
        popup.closeButton = CreateButton(go.transform, "CloseBtn", "关闭",
            new Vector2(0, -170), new Vector2(100, 40));

        go.SetActive(false);
        return go;
    }

    private static Image CreateImage(Transform parent, string name, Vector2 pos, Vector2 size)
    {
        var go = new GameObject(name, typeof(RectTransform));
        go.transform.SetParent(parent, false);
        var rt = go.GetComponent<RectTransform>();
        rt.anchoredPosition = pos;
        rt.sizeDelta = size;
        return go.AddComponent<Image>();
    }

    // Separate overload for AttachmentInfoPopup
    private static GameObject CreateAttachmentPopup(Transform parent, string name, out AttachmentInfoPopup popup)
    {
        var go = new GameObject(name, typeof(RectTransform), typeof(Image));
        go.transform.SetParent(parent, false);
        go.GetComponent<RectTransform>().sizeDelta = new Vector2(350, 350);
        go.GetComponent<Image>().color = new Color(0.15f, 0.15f, 0.2f, 0.98f);
        popup = go.AddComponent<AttachmentInfoPopup>();
        popup.panelRoot = go;

        popup.icon = CreateImage(go.transform, "Icon", Vector2.up * 120, new Vector2(80, 80));
        popup.nameText = CreateText(go.transform, "Name", "配件名", 24, TextAlignmentOptions.Center,
            new Vector2(0, 60), new Vector2(300, 40));
        popup.descriptionText = CreateText(go.transform, "Desc", "", 16, TextAlignmentOptions.Center,
            new Vector2(0, 10), new Vector2(300, 50));
        popup.effectsText = CreateText(go.transform, "Effects", "", 16, TextAlignmentOptions.Left,
            new Vector2(0, -80), new Vector2(300, 160));
        popup.closeButton = CreateButton(go.transform, "CloseBtn", "关闭",
            new Vector2(0, -160), new Vector2(100, 40));

        go.SetActive(false);
        return go;
    }
}
