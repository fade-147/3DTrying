//Copyright 2022, Infima Games. All Rights Reserved.

using UnityEngine;

namespace InfimaGames.LowPolyShooterPack.Interface
{
    /// <summary>
    /// Player Interface.
    /// </summary>
    public class CanvasSpawner : MonoBehaviour
    {
        #region FIELDS SERIALIZED

        [Title(label: "Settings")]

        [Tooltip("Canvas prefab spawned at start. Displays the player's user interface.")]
        [SerializeField]
        private GameObject canvasPrefab;

        [Tooltip("Quality settings menu prefab spawned at start. Used for switching between different quality settings in-game.")]
        [SerializeField]
        private GameObject qualitySettingsPrefab;

        #endregion

        #region FIELDS

        /// <summary>
        /// Static flag to ensure only one canvas is spawned per process.
        /// In multiplayer, each player prefab instance would otherwise spawn its own canvas.
        /// </summary>
        private static bool _canvasSpawned;

        #endregion

        #region UNITY

        /// <summary>
        /// Awake.
        /// </summary>
        private void Awake()
        {
            //Only spawn the UI canvas once per game instance.
            if (_canvasSpawned)
                return;
            _canvasSpawned = true;

            //Spawn Interface.
            if (canvasPrefab != null)
                Instantiate(canvasPrefab);
            //Spawn Quality Settings Menu (only if assigned).
            if (qualitySettingsPrefab != null)
                Instantiate(qualitySettingsPrefab);
        }

        #endregion
    }
}