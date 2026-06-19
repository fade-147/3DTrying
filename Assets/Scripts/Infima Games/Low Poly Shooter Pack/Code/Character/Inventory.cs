//Copyright 2022, Infima Games. All Rights Reserved.

using System.Collections.Generic;
using UnityEngine;

namespace InfimaGames.LowPolyShooterPack
{
    public class Inventory : InventoryBehaviour
    {
        #region FIELDS

        /// <summary>
        /// Array of all weapons. These are gotten in the order that they are parented to this object.
        /// </summary>
        private WeaponBehaviour[] weapons;

        /// <summary>
        /// Currently equipped WeaponBehaviour.
        /// </summary>
        private WeaponBehaviour equipped;
        /// <summary>
        /// Currently equipped index.
        /// </summary>
        private int equippedIndex = -1;

        /// <summary>
        /// Active loadout slots (non-empty weapon slugs), sorted by slotIndex.
        /// </summary>
        private List<LoadoutSlot> _loadoutSlots;

        #endregion

        #region METHODS

        public override void Init(int equippedAtStart = 0)
        {
            //Cache all weapons. Beware that weapons need to be parented to the object this component is on!
            weapons = GetComponentsInChildren<WeaponBehaviour>(true);

            //Disable all weapons. This makes it easier for us to only activate the one we need.
            foreach (WeaponBehaviour weapon in weapons)
                weapon.gameObject.SetActive(false);

            //Equip.
            Equip(equippedAtStart);
        }

        public override void Init(LoadoutData loadout, int equippedAtStart = 0)
        {
            if (loadout == null)
            {
                Init(equippedAtStart);
                return;
            }

            _loadoutSlots = loadout.GetEquippedWeapons();

            // 检查 WeaponPrefabRegistry 是否可用
            bool registryAvailable = false;
            foreach (var slot in _loadoutSlots)
            {
                if (string.IsNullOrEmpty(slot.weaponSlug)) continue;
                if (WeaponPrefabRegistry.GetPrefab(slot.weaponSlug) != null)
                {
                    registryAvailable = true;
                    break;
                }
            }

            if (registryAvailable)
            {
                // ── PATH A: Registry 可用 → Destroy 全部已有武器，从 Registry Instantiate ──
                var existing = GetComponentsInChildren<WeaponBehaviour>(true);

                // 保存弹丸覆写 + 首个武器位姿（作为模板）
                var projectileOverrides = new Dictionary<string, GameObject>();
                var projectileField = typeof(Weapon).GetField("prefabProjectile",
                    System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
                Vector3 templatePos = Vector3.zero;
                Quaternion templateRot = Quaternion.identity;
                Vector3 templateScale = Vector3.one;
                int templateLayer = -1;
                int templateSiblingIdx = 0;
                Transform templateParent = transform;
                bool hasTemplate = false;

                foreach (var w in existing)
                {
                    if (w == null || w.gameObject == null) continue;
                    if (!hasTemplate)
                    {
                        var t = w.transform;
                        templatePos = t.localPosition;
                        templateRot = t.localRotation;
                        templateScale = t.localScale;
                        templateLayer = w.gameObject.layer;
                        templateSiblingIdx = t.GetSiblingIndex();
                        templateParent = t.parent;
                        hasTemplate = true;
                    }
                    if (projectileField != null)
                    {
                        var proj = projectileField.GetValue(w) as GameObject;
                        if (proj != null) projectileOverrides[w.gameObject.name] = proj;
                    }
                    Destroy(w.gameObject);
                }

                var newWeapons = new List<WeaponBehaviour>();
                foreach (var slot in _loadoutSlots)
                {
                    if (string.IsNullOrEmpty(slot.weaponSlug)) continue;

                    GameObject prefab = WeaponPrefabRegistry.GetPrefab(slot.weaponSlug);
                    if (prefab == null) continue;

                    WeaponAttachmentManager.QueuePreset(
                        slot.scopeSlug, slot.muzzleSlug, slot.laserSlug, slot.gripSlug);

                    GameObject instance = Instantiate(prefab, templateParent);
                    instance.name = prefab.name;
                    if (hasTemplate)
                    {
                        instance.transform.localPosition = templatePos;
                        instance.transform.localRotation = templateRot;
                        instance.transform.localScale = templateScale;
                        SetLayerRecursively(instance, templateLayer);
                        instance.transform.SetSiblingIndex(templateSiblingIdx);
                    }

                    // 恢复弹丸覆写
                    if (projectileField != null && projectileOverrides.TryGetValue(instance.name, out var savedProj))
                    {
                        var wc = instance.GetComponent<Weapon>();
                        if (wc != null) projectileField.SetValue(wc, savedProj);
                    }

                    var wb = instance.GetComponent<WeaponBehaviour>();
                    if (wb != null)
                    {
                        wb.gameObject.SetActive(false);
                        newWeapons.Add(wb);
                    }
                }

                weapons = newWeapons.ToArray();
            }
            else
            {
                // ── PATH B: Registry 不可用 → 用已有子对象，按名称匹配 loadout ──
                var existingAll = GetComponentsInChildren<WeaponBehaviour>(true);
                var existingWeapons = new List<WeaponBehaviour>();
                var existingNames = new List<string>();

                foreach (var w in existingAll)
                {
                    if (w == null || w.gameObject == null) continue;
                    existingWeapons.Add(w);
                    existingNames.Add(w.gameObject.name);
                }

                var newWeapons = new List<WeaponBehaviour>();
                var used = new bool[existingWeapons.Count];

                foreach (var slot in _loadoutSlots)
                {
                    if (string.IsNullOrEmpty(slot.weaponSlug)) continue;

                    string rest = slot.weaponSlug.StartsWith("wpn_")
                        ? slot.weaponSlug.Substring(4) : slot.weaponSlug;

                    int match = -1;
                    for (int i = 0; i < existingWeapons.Count; i++)
                    {
                        if (used[i]) continue;
                        int prefixIdx = existingNames[i].LastIndexOf("P_LPSP_WEP_", System.StringComparison.OrdinalIgnoreCase);
                        string nameRest = prefixIdx >= 0 ? existingNames[i].Substring(prefixIdx + 12) : existingNames[i];
                        if (string.Equals(nameRest, rest, System.StringComparison.OrdinalIgnoreCase))
                        { match = i; break; }
                    }

                    if (match >= 0)
                    {
                        used[match] = true;
                        existingWeapons[match].gameObject.SetActive(false);

                        // 重新配置附件（WAM.Awake 已执行，需手动 ApplyPreset）
                        var wam = existingWeapons[match].GetComponent<WeaponAttachmentManager>();
                        if (wam != null)
                        {
                            wam.ApplyPreset(slot.scopeSlug, slot.muzzleSlug, slot.laserSlug, slot.gripSlug);
                        }

                        newWeapons.Add(existingWeapons[match]);
                    }
                    else
                    {
                        Debug.LogWarning($"[Inventory] Weapon for slug '{slot.weaponSlug}' not found in existing children.");
                    }
                }

                // 清理未使用的已有武器
                for (int i = 0; i < existingWeapons.Count; i++)
                {
                    if (!used[i]) Destroy(existingWeapons[i].gameObject);
                }

                weapons = newWeapons.ToArray();
            }

            if (weapons.Length > 0)
                Equip(Mathf.Clamp(equippedAtStart, 0, weapons.Length - 1));
            else
                Debug.LogError("[Inventory] No weapons initialized from loadout!");
        }

        /// <summary>
        /// Gets the WeaponBehaviour at the given loadout slot index (0-based among equipped weapons).
        /// </summary>
        public WeaponBehaviour GetWeaponAtSlot(int slotIndex)
        {
            if (weapons == null || slotIndex < 0 || slotIndex >= weapons.Length)
                return null;
            return weapons[slotIndex];
        }

        /// <summary>
        /// Returns the number of active (equipped) weapons in the loadout.
        /// </summary>
        public int GetEquippedWeaponCount() => weapons?.Length ?? 0;

        /// <summary>递归设置 GameObject 及其所有子对象的 layer。</summary>
        private static void SetLayerRecursively(GameObject obj, int layer)
        {
            obj.layer = layer;
            foreach (Transform child in obj.transform)
                SetLayerRecursively(child.gameObject, layer);
        }

        public override WeaponBehaviour Equip(int index)
        {
            //If we have no weapons, we can't really equip anything.
            if (weapons == null || weapons.Length == 0)
                return equipped;

            //The index needs to be within the array's bounds.
            if (index > weapons.Length - 1)
                return equipped;

            //No point in allowing equipping the already-equipped weapon.
            if (equippedIndex == index)
                return equipped;

            //Disable the currently equipped weapon, if we have one.
            if (equipped != null)
                equipped.gameObject.SetActive(false);

            //Update index.
            equippedIndex = index;
            //Update equipped.
            equipped = weapons[equippedIndex];
            //Activate the newly-equipped weapon.
            equipped.gameObject.SetActive(true);

            // 联网同步：通知服务端当前装备武器 slug。
            if (_loadoutSlots != null && index < _loadoutSlots.Count)
            {
                string slug = _loadoutSlots[index].weaponSlug;
                if (!string.IsNullOrEmpty(slug))
                {
                    // PlayerWeaponSync 挂在 Player_FPS_TP 根节点上。
                    var sync = GetComponentInParent<PlayerWeaponSync>();
                    if (sync != null)
                        sync.CmdSwitchWeapon(slug);
                }
            }

            //Return.
            return equipped;
        }

        #endregion

        #region Getters

        public override int GetLastIndex()
        {
            //Get last index with wrap around.
            int newIndex = equippedIndex - 1;
            if (newIndex < 0)
                newIndex = weapons.Length - 1;

            //Return.
            return newIndex;
        }

        public override int GetNextIndex()
        {
            //Get next index with wrap around.
            int newIndex = equippedIndex + 1;
            if (newIndex > weapons.Length - 1)
                newIndex = 0;

            //Return.
            return newIndex;
        }

        public override WeaponBehaviour GetEquipped() => equipped;
        public override int GetEquippedIndex() => equippedIndex;

        /// <summary>
        /// Returns the loadout slug for the currently equipped weapon.
        /// </summary>
        public string GetEquippedSlug()
        {
            if (_loadoutSlots == null || equippedIndex < 0 || equippedIndex >= _loadoutSlots.Count)
                return null;
            return _loadoutSlots[equippedIndex].weaponSlug;
        }

        #endregion
    }
}
