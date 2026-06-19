//Copyright 2022, Infima Games. All Rights Reserved.

using UnityEngine;

namespace InfimaGames.LowPolyShooterPack
{
    /// <summary>
    /// Grip.
    /// </summary>
    public class Grip : GripBehaviour, IAttachmentEffect
    {
        #region FIELDS SERIALIZED

        [Title(label: "Settings")]

        [Tooltip("Sprite. Displayed on the player's interface.")]
        [SerializeField]
        private Sprite sprite;

        [Title(label: "Attachment Effects")]

        [Tooltip("后坐力减少百分比（0~1，0.12=减少12%）")]
        [SerializeField]
        private float recoilReduction = 0.12f;

        [Tooltip("散布减少百分比（0~1）")]
        [SerializeField]
        private float spreadReduction = 0.05f;

        [Tooltip("蹲伏/趴下时额外后坐力减少（0~1，与 recoilReduction 叠加）")]
        [SerializeField]
        private float crouchRecoilBonus = 0.15f;

        #endregion

        #region GETTERS

        public override Sprite GetSprite() => sprite;

        // IAttachmentEffect
        public float RecoilReduction => recoilReduction;
        public float SpreadReduction => spreadReduction;
        public float SwayReduction => 0f;
        public bool SuppressSound => false;
        public float AmmoCapacityMultiplier => 1f;
        public float HipfireSpreadReduction => 0f;

        /// <summary>蹲伏时总后坐力减少（含 bonus）。</summary>
        public float GetCrouchRecoilReduction() => recoilReduction + crouchRecoilBonus;

        #endregion
    }
}