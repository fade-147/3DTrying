//Copyright 2022, Infima Games. All Rights Reserved.

using System.Collections.Generic;
using UnityEngine;

namespace InfimaGames.LowPolyShooterPack
{
    /// <summary>
    /// Weapon Attachment Manager. Handles equipping and storing a Weapon's Attachments.
    /// </summary>
    public class WeaponAttachmentManager : WeaponAttachmentManagerBehaviour
    {
        #region FIELDS SERIALIZED

        [Title(label: "Scope")]

        [Tooltip("Determines if the ironsights should be shown on the weapon model.")]
        [SerializeField]
        private bool scopeDefaultShow = true;

        [Tooltip("Default Scope!")]
        [SerializeField]
        private ScopeBehaviour scopeDefaultBehaviour;

        [Tooltip("Selected Scope Index. If you set this to a negative number, ironsights will be selected as the enabled scope.")]
        [SerializeField]
        private int scopeIndex = -1;

        [Tooltip("First scope index when using random scopes.")]
        [SerializeField]
        private int scopeIndexFirst = -1;

        [Tooltip("Should we pick a random index when starting the game?")]
        [SerializeField]
        private bool scopeIndexRandom;

        [Tooltip("All possible Scope Attachments that this Weapon can use!")]
        [SerializeField]
        private ScopeBehaviour[] scopeArray;

        [Title(label: "Muzzle")]

        [Tooltip("Selected Muzzle Index.")]
        [SerializeField]
        private int muzzleIndex;

        [Tooltip("Should we pick a random index when starting the game?")]
        [SerializeField]
        private bool muzzleIndexRandom = true;

        [Tooltip("All possible Muzzle Attachments that this Weapon can use!")]
        [SerializeField]
        private MuzzleBehaviour[] muzzleArray;

        [Title(label: "Laser")]

        [Tooltip("Selected Laser Index.")]
        [SerializeField]
        private int laserIndex = -1;

        [Tooltip("Should we pick a random index when starting the game?")]
        [SerializeField]
        private bool laserIndexRandom = true;

        [Tooltip("All possible Laser Attachments that this Weapon can use!")]
        [SerializeField]
        private LaserBehaviour[] laserArray;

        [Title(label: "Grip")]

        [Tooltip("Selected Grip Index.")]
        [SerializeField]
        private int gripIndex = -1;

        [Tooltip("Should we pick a random index when starting the game?")]
        [SerializeField]
        private bool gripIndexRandom = true;

        [Tooltip("All possible Grip Attachments that this Weapon can use!")]
        [SerializeField]
        private GripBehaviour[] gripArray;

        [Title(label: "Magazine")]

        [Tooltip("Selected Magazine Index.")]
        [SerializeField]
        private int magazineIndex;

        [Tooltip("Should we pick a random index when starting the game?")]
        [SerializeField]
        private bool magazineIndexRandom = true;

        [Tooltip("All possible Magazine Attachments that this Weapon can use!")]
        [SerializeField]
        private Magazine[] magazineArray;

        #endregion

        #region STATIC PRESET QUEUE

        /// <summary>
        /// 预设数据队列。Inventory.Init(LoadoutData) 在 Instantiate 之前入队，
        /// Awake 时出队消费。避免直接修改 prefab 共享状态。
        /// </summary>
        private struct PendingPreset
        {
            public string scopeSlug, muzzleSlug, laserSlug, gripSlug;
        }
        private static readonly Queue<PendingPreset> _presetQueue = new();

        /// <summary>入队一个预设（在 Instantiate 前调用）。</summary>
        public static void QueuePreset(string scopeSlug, string muzzleSlug, string laserSlug, string gripSlug)
        {
            _presetQueue.Enqueue(new PendingPreset
            {
                scopeSlug = scopeSlug,
                muzzleSlug = muzzleSlug,
                laserSlug = laserSlug,
                gripSlug = gripSlug
            });
        }

        #endregion

        #region FIELDS

        /// <summary>
        /// Equipped Scope.
        /// </summary>
        private ScopeBehaviour scopeBehaviour;
        /// <summary>
        /// Equipped Muzzle.
        /// </summary>
        private MuzzleBehaviour muzzleBehaviour;
        /// <summary>
        /// Equipped Laser.
        /// </summary>
        private LaserBehaviour laserBehaviour;
        /// <summary>
        /// Equipped Grip.
        /// </summary>
        private GripBehaviour gripBehaviour;
        /// <summary>
        /// Equipped Magazine.
        /// </summary>
        private MagazineBehaviour magazineBehaviour;

        #endregion

        #region UNITY FUNCTIONS

        /// <summary>
        /// Awake.
        /// </summary>
        protected override void Awake()
        {
            // Check static preset queue (populated by Inventory.Init before Instantiate)
            if (_presetQueue.Count > 0)
            {
                var preset = _presetQueue.Dequeue();

                scopeIndex = ParseSlugIndex(preset.scopeSlug, "scope");
                laserIndex = ParseSlugIndex(preset.laserSlug, "laser");
                gripIndex = ParseSlugIndex(preset.gripSlug, "grip");

                // Muzzle 必须存在（开火音效 + 子弹生成点；为空时用默认 index 0）
                muzzleIndex = string.IsNullOrEmpty(preset.muzzleSlug)
                    ? 0 : ParseSlugIndex(preset.muzzleSlug, "muzzle");

                Debug.Log($"[WAM] Preset applied from queue: scope={scopeIndex}, muzzle={muzzleIndex}, laser={laserIndex}, grip={gripIndex}");
            }
            else
            {
                // 保留原有随机逻辑（向后兼容 / 编辑器测试）
                if (scopeIndexRandom)
                    scopeIndex = Random.Range(scopeIndexFirst, scopeArray.Length);
                if (muzzleIndexRandom)
                    muzzleIndex = Random.Range(0, muzzleArray.Length);
                if (laserIndexRandom)
                    laserIndex = Random.Range(0, laserArray.Length);
                if (gripIndexRandom)
                    gripIndex = Random.Range(0, gripArray.Length);
                if (magazineIndexRandom)
                    magazineIndex = Random.Range(0, magazineArray.Length);
            }

            //Select Scope!
            scopeBehaviour = scopeArray.SelectAndSetActive(scopeIndex);
            //Check if we have no scope. This could happen if we have an incorrect index.
            if (scopeBehaviour == null)
            {
                //Select Default Scope.
                scopeBehaviour = scopeDefaultBehaviour;
                //Set Active.
                scopeBehaviour.gameObject.SetActive(scopeDefaultShow);
            }

            //Select Muzzle!
            muzzleBehaviour = muzzleArray.SelectAndSetActive(muzzleIndex);
            if (muzzleBehaviour == null && muzzleArray.Length > 0)
                muzzleBehaviour = muzzleArray.SelectAndSetActive(0);

            //Select Laser! (null = not equipped)
            laserBehaviour = laserArray.SelectAndSetActive(laserIndex);

            //Select Grip! (null = not equipped)
            gripBehaviour = gripArray.SelectAndSetActive(gripIndex);

            //Select Magazine!
            magazineBehaviour = magazineArray.SelectAndSetActive(magazineIndex);
        }

        #endregion

        #region METHODS

        /// <summary>
        /// 从 slug 解析出对应配件数组的 index。
        /// slug 格式: "att_{category}_{NN}"（如 "att_scope_02" → 1）。
        /// null/空 → 返回 -1（不装备）。
        /// </summary>
        private static int ParseSlugIndex(string slug, string category)
        {
            if (string.IsNullOrEmpty(slug)) return -1;

            // 验证 slug 类别前缀: "att_{category}_"
            string prefix = $"att_{category}_";
            if (!slug.StartsWith(prefix))
            {
                Debug.LogWarning($"[WAM] Slug '{slug}' does not match expected prefix '{prefix}'.");
                return -1;
            }

            // 提取末尾数字
            string numStr = slug.Substring(prefix.Length);
            if (int.TryParse(numStr, out int num) && num > 0)
                return num - 1; // slug 编号从 01 开始

            Debug.LogWarning($"[WAM] Cannot parse index from slug '{slug}', using 0.");
            return 0;
        }

        /// <summary>
        /// 运行时重新配置附件（供 Inventory PATH B 使用，WAM.Awake 已执行后调用）。
        /// 直接设置 index 并重新选择对应的附件 GameObject。
        /// </summary>
        public void ApplyPreset(string scopeSlug, string muzzleSlug, string laserSlug, string gripSlug)
        {
            scopeIndex = string.IsNullOrEmpty(scopeSlug) ? -1 : ParseSlugIndex(scopeSlug, "scope");
            muzzleIndex = string.IsNullOrEmpty(muzzleSlug) ? 0 : ParseSlugIndex(muzzleSlug, "muzzle");
            laserIndex = string.IsNullOrEmpty(laserSlug) ? -1 : ParseSlugIndex(laserSlug, "laser");
            gripIndex = string.IsNullOrEmpty(gripSlug) ? -1 : ParseSlugIndex(gripSlug, "grip");

            // Re-select scope
            scopeBehaviour = scopeArray.SelectAndSetActive(scopeIndex);
            if (scopeBehaviour == null)
            {
                scopeBehaviour = scopeDefaultBehaviour;
                if (scopeBehaviour != null)
                    scopeBehaviour.gameObject.SetActive(scopeDefaultShow);
            }

            // Re-select muzzle (must exist for fire sound + bullet spawn)
            muzzleBehaviour = muzzleArray.SelectAndSetActive(muzzleIndex);
            if (muzzleBehaviour == null && muzzleArray.Length > 0)
                muzzleBehaviour = muzzleArray.SelectAndSetActive(0);

            // Re-select laser (nullable)
            laserBehaviour = laserArray.SelectAndSetActive(laserIndex);

            // Re-select grip (nullable)
            gripBehaviour = gripArray.SelectAndSetActive(gripIndex);

            // Magazine stays at default (serialized magazineIndex or 0)
            if (magazineArray.Length > 0)
                magazineBehaviour = magazineArray.SelectAndSetActive(magazineIndex);
        }

        #endregion

        #region GETTERS

        public override ScopeBehaviour GetEquippedScope() => scopeBehaviour;
        public override ScopeBehaviour GetEquippedScopeDefault() => scopeDefaultBehaviour;

        public override MagazineBehaviour GetEquippedMagazine() => magazineBehaviour;
        public override MuzzleBehaviour GetEquippedMuzzle() => muzzleBehaviour;

        public override LaserBehaviour GetEquippedLaser() => laserBehaviour;
        public override GripBehaviour GetEquippedGrip() => gripBehaviour;

        #endregion
    }
}
