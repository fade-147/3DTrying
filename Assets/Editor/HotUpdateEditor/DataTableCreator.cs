using UnityEngine;
using UnityEditor;

/// <summary>
/// Editor 工具：创建 WeaponDataTable 和 AttachmentDataTable ScriptableObject。
/// </summary>
public class DataTableCreator : EditorWindow
{
    [MenuItem("Game/Create Weapon Data Table")]
    public static void CreateWeaponDataTable()
    {
        var table = ScriptableObject.CreateInstance<WeaponDataTable>();

        // 添加所有武器条目（需要手动拖入 prefab 引用）
        AddWeapon(table, "wpn_ar_01", "突击步枪 01", WeaponCategory.Rifle,
            "标准突击步枪，可靠的全能武器。", true, false, 650, 30);
        AddWeapon(table, "wpn_ar_02", "突击步枪 02", WeaponCategory.Rifle,
            "改良型突击步枪，弹匣容量更大。", true, false, 650, 32);
        AddWeapon(table, "wpn_ar_03", "突击步枪 03", WeaponCategory.Rifle,
            "紧凑型突击步枪，适合近距离作战。", true, false, 650, 25);
        AddWeapon(table, "wpn_handgun_01", "半自动手枪 01", WeaponCategory.Handgun,
            "标准半自动手枪。", false, false, 500, 12);
        AddWeapon(table, "wpn_handgun_02", "半自动手枪 02", WeaponCategory.Handgun,
            "紧凑型手枪。", false, false, 500, 10);
        AddWeapon(table, "wpn_handgun_03", "半自动手枪 03", WeaponCategory.Handgun,
            "大口径手枪。", false, false, 500, 10);
        AddWeapon(table, "wpn_handgun_04", "半自动手枪 04", WeaponCategory.Handgun,
            "轻型手枪。", false, false, 500, 10);
        AddWeapon(table, "wpn_smg_01", "冲锋枪 01", WeaponCategory.SMG,
            "高射速冲锋枪，弹容量大。", true, false, 750, 37);
        AddWeapon(table, "wpn_smg_02", "冲锋枪 02", WeaponCategory.SMG,
            "超高速冲锋枪，射速极快。", true, false, 800, 30);
        AddWeapon(table, "wpn_smg_03", "冲锋枪 03", WeaponCategory.SMG,
            "均衡型冲锋枪。", true, false, 750, 35);
        AddWeapon(table, "wpn_smg_04", "冲锋枪 04", WeaponCategory.SMG,
            "大容量冲锋枪，持续火力。", true, false, 680, 54);
        AddWeapon(table, "wpn_smg_05", "冲锋枪 05", WeaponCategory.SMG,
            "精准型冲锋枪。", true, false, 700, 32);
        AddWeapon(table, "wpn_shotgun_01", "泵动霰弹枪", WeaponCategory.Shotgun,
            "近距离毁灭性火力，每次发射6颗弹丸。", false, true, 125, 8, 6, true);
        AddWeapon(table, "wpn_sniper_01", "栓动狙击枪", WeaponCategory.Sniper,
            "高精度栓动狙击枪。", false, true, 125, 7, 1, true);
        AddWeapon(table, "wpn_sniper_02", "半自动狙击枪 02", WeaponCategory.Sniper,
            "半自动狙击枪，射速更快。", false, false, 125, 9);
        AddWeapon(table, "wpn_sniper_03", "半自动狙击枪 03", WeaponCategory.Sniper,
            "轻型半自动狙击枪。", false, false, 125, 8);
        AddWeapon(table, "wpn_gl_01", "榴弹发射器", WeaponCategory.Special,
            "发射榴弹，自动装填。", false, false, 200, 1);
        AddWeapon(table, "wpn_rl_01", "火箭筒", WeaponCategory.Special,
            "发射火箭弹，威力巨大。", false, false, 500, 1);

        string path = "Assets/GameAssets/DataTables/WeaponDataTable.asset";
        AssetDatabase.CreateAsset(table, path);
        AssetDatabase.SaveAssets();
        Debug.Log($"[DataTableCreator] Created {path} with {table.weapons.Count} weapons.");
        Selection.activeObject = table;
    }

    [MenuItem("Game/Create Attachment Data Table")]
    public static void CreateAttachmentDataTable()
    {
        var table = ScriptableObject.CreateInstance<AttachmentDataTable>();

        // Scopes (8)
        AddAttachment(table, "att_scope_01", "铁瞄", AttachmentCategory.Scope,
            "标准机械瞄准具。", recoil: 0, spread: 0, sway: 0.05f);
        AddAttachment(table, "att_scope_02", "红点瞄准镜", AttachmentCategory.Scope,
            "快速瞄准红点镜，提高反应速度。", recoil: 0, spread: 0, sway: 0.1f);
        AddAttachment(table, "att_scope_03", "全息瞄准镜", AttachmentCategory.Scope,
            "全息投影瞄准，精准且视野开阔。", recoil: 0, spread: 0.05f, sway: 0.08f);
        AddAttachment(table, "att_scope_04", "ACOG 4×", AttachmentCategory.Scope,
            "4倍光学瞄准镜，中距离作战利器。", recoil: 0, spread: 0.1f, sway: 0.02f);
        AddAttachment(table, "att_scope_05", "6× 高倍镜", AttachmentCategory.Scope,
            "6倍光学瞄准镜，远距离精确打击。", recoil: 0, spread: 0.15f, sway: 0.01f);
        AddAttachment(table, "att_scope_06", "热成像瞄准镜", AttachmentCategory.Scope,
            "热成像技术，穿透烟雾发现敌人。", recoil: 0, spread: 0.1f, sway: 0.03f);
        AddAttachment(table, "att_scope_07", "夜视瞄准镜", AttachmentCategory.Scope,
            "微光夜视瞄准，夜间作战必备。", recoil: 0, spread: 0.08f, sway: 0.05f);
        AddAttachment(table, "att_scope_08", "8× 狙击镜", AttachmentCategory.Scope,
            "8倍超高倍率，终极远距离瞄准镜。", recoil: 0, spread: 0.2f, sway: 0f);

        // Muzzles (4)
        AddAttachment(table, "att_muzzle_01", "消焰器", AttachmentCategory.Muzzle,
            "标准消焰器，隐藏枪口火焰。", recoil: 0.03f, spread: 0);
        AddAttachment(table, "att_muzzle_02", "消音器 01", AttachmentCategory.Muzzle,
            "轻型消音器，略微降低后坐力。隐藏枪声方向指示器。", recoil: 0.05f, spread: 0, suppress: true);
        AddAttachment(table, "att_muzzle_03", "消音器 02", AttachmentCategory.Muzzle,
            "战术消音器，有效降低后坐力。隐藏枪声方向指示器。", recoil: 0.08f, spread: 0, suppress: true);
        AddAttachment(table, "att_muzzle_04", "消音器 03", AttachmentCategory.Muzzle,
            "高级消音器，大幅降低后坐力。隐藏枪声方向指示器。", recoil: 0.10f, spread: 0.02f, suppress: true);

        // Lasers (2)
        AddAttachment(table, "att_laser_01", "镭射瞄准器", AttachmentCategory.Laser,
            "红色镭射线，腰射精度大幅提升。", hipfire: 0.15f);
        AddAttachment(table, "att_laser_02", "镭射手电组合", AttachmentCategory.Laser,
            "镭射+战术手电组合，腰射精度小幅提升。", hipfire: 0.10f);

        // Grips (3)
        AddAttachment(table, "att_grip_01", "前握把", AttachmentCategory.Grip,
            "标准前握把，降低后坐力和散布。", recoil: 0.12f, spread: 0.05f);
        AddAttachment(table, "att_grip_02", "双脚架 01", AttachmentCategory.Grip,
            "轻型双脚架，蹲伏/趴下时大幅降低后坐力。", recoil: 0.05f, spread: 0.03f);
        AddAttachment(table, "att_grip_03", "双脚架 02", AttachmentCategory.Grip,
            "重型双脚架，蹲伏/趴下时极大降低后坐力。", recoil: 0.08f, spread: 0.05f);

        string path = "Assets/GameAssets/DataTables/AttachmentDataTable.asset";
        AssetDatabase.CreateAsset(table, path);
        AssetDatabase.SaveAssets();
        Debug.Log($"[DataTableCreator] Created {path} with {table.attachments.Count} attachments.");
        Selection.activeObject = table;
    }

    private static void AddWeapon(WeaponDataTable table, string slug, string name,
        WeaponCategory cat, string desc, bool auto, bool bolt, int rpm, int mag,
        int shotCount = 1, bool cycled = false)
    {
        table.weapons.Add(new WeaponEntry
        {
            slug = slug,
            displayName = name,
            description = desc,
            category = cat,
            isAutomatic = auto,
            isBoltAction = bolt,
            roundsPerMinute = rpm,
            magazineSize = mag,
            shotCount = shotCount,
            cycledReload = cycled,
            movementSpeedMultiplier = 1f
        });
    }

    private static void AddAttachment(AttachmentDataTable table, string slug, string name,
        AttachmentCategory cat, string desc, float recoil = 0, float spread = 0,
        float sway = 0, bool suppress = false, float ammoMult = 1f, float hipfire = 0)
    {
        table.attachments.Add(new AttachmentEntry
        {
            slug = slug,
            displayName = name,
            description = desc,
            category = cat,
            recoilReduction = recoil,
            spreadReduction = spread,
            swayReduction = sway,
            suppressSound = suppress,
            ammoCapacityMultiplier = ammoMult,
            hipfireSpreadReduction = hipfire
        });
    }

    [MenuItem("Game/Auto-Fill Weapon Icons from Prefabs")]
    public static void AutoFillWeaponIcons()
    {
        var table = AssetDatabase.LoadAssetAtPath<WeaponDataTable>(
            "Assets/GameAssets/DataTables/WeaponDataTable.asset");
        if (table == null)
        {
            Debug.LogError("[DataTableCreator] WeaponDataTable.asset not found! Create it first.");
            return;
        }

        int filled = 0;
        foreach (var entry in table.weapons)
        {
            if (entry.icon != null) continue; // skip already-filled
            if (entry.prefab == null) continue;

            var weapon = entry.prefab.GetComponent<InfimaGames.LowPolyShooterPack.WeaponBehaviour>();
            if (weapon != null)
            {
                entry.icon = weapon.GetSpriteBody();
                if (entry.icon != null) filled++;
            }
        }

        EditorUtility.SetDirty(table);
        AssetDatabase.SaveAssets();
        Debug.Log($"[DataTableCreator] Auto-filled {filled} weapon icons from prefab spriteBody.");
    }

    [MenuItem("Game/Auto-Fill Attachment Icons from Prefabs")]
    public static void AutoFillAttachmentIcons()
    {
        var table = AssetDatabase.LoadAssetAtPath<AttachmentDataTable>(
            "Assets/GameAssets/DataTables/AttachmentDataTable.asset");
        if (table == null)
        {
            Debug.LogError("[DataTableCreator] AttachmentDataTable.asset not found! Create it first.");
            return;
        }

        int filled = 0;
        foreach (var entry in table.attachments)
        {
            if (entry.icon != null) continue;
            if (entry.prefab == null) continue;

            Sprite sprite = null;
            switch (entry.category)
            {
                case AttachmentCategory.Scope:
                    var sc = entry.prefab.GetComponent<InfimaGames.LowPolyShooterPack.ScopeBehaviour>();
                    sprite = sc?.GetSprite(); break;
                case AttachmentCategory.Muzzle:
                    var mu = entry.prefab.GetComponent<InfimaGames.LowPolyShooterPack.MuzzleBehaviour>();
                    sprite = mu?.GetSprite(); break;
                case AttachmentCategory.Laser:
                    var la = entry.prefab.GetComponent<InfimaGames.LowPolyShooterPack.LaserBehaviour>();
                    sprite = la?.GetSprite(); break;
                case AttachmentCategory.Grip:
                    var gr = entry.prefab.GetComponent<InfimaGames.LowPolyShooterPack.GripBehaviour>();
                    sprite = gr?.GetSprite(); break;
            }

            if (sprite != null) { entry.icon = sprite; filled++; }
        }

        EditorUtility.SetDirty(table);
        AssetDatabase.SaveAssets();
        Debug.Log($"[DataTableCreator] Auto-filled {filled} attachment icons.");
    }
}
