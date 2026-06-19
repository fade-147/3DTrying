//Copyright 2022, Infima Games. All Rights Reserved.

using UnityEngine;

namespace InfimaGames.LowPolyShooterPack
{
    /// <summary>
    /// Magazine.
    /// </summary>
    public class Magazine : MagazineBehaviour, IAttachmentEffect
    {
        #region FIELDS SERIALIZED

        [Title(label: "Settings")]

        [Tooltip("Total Ammunition (base value).")]
        [SerializeField]
        private int ammunitionTotal = 10;

        [Title(label: "Attachment Effects")]

        [Tooltip("Ammo capacity multiplier (1.0=default, 1.2=+20%, 1.5=+50%)")]
        [SerializeField]
        private float ammoCapacityMultiplier = 1.0f;

        [Title(label: "Interface")]

        [Tooltip("Interface Sprite.")]
        [SerializeField]
        private Sprite sprite;

        #endregion

        #region GETTERS

        /// <summary>
        /// Effective Ammunition Total = base * multiplier.
        /// </summary>
        public override int GetAmmunitionTotal() => Mathf.RoundToInt(ammunitionTotal * ammoCapacityMultiplier);

        /// <summary>
        /// Base ammo (without multiplier).
        /// </summary>
        public int GetBaseAmmunitionTotal() => ammunitionTotal;

        /// <summary>
        /// Sprite.
        /// </summary>
        public override Sprite GetSprite() => sprite;

        // IAttachmentEffect
        public float RecoilReduction => 0f;
        public float SpreadReduction => 0f;
        public float SwayReduction => 0f;
        public bool SuppressSound => false;
        public float AmmoCapacityMultiplier => ammoCapacityMultiplier;
        public float HipfireSpreadReduction => 0f;

        /// <summary>
        /// Sets the ammo capacity multiplier at runtime (from loadout preset).
        /// </summary>
        public void SetCapacityMultiplier(float multiplier)
        {
            ammoCapacityMultiplier = multiplier;
        }

        #endregion
    }
}
