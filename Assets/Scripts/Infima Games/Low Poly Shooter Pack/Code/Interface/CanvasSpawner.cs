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
        /// Instance flag: true when this CanvasSpawner has created a canvas.
        /// No longer static — each instance tracks its own canvas to avoid
        /// a race condition where Unity's deferred Destroy causes the old
        /// instance's OnDestroy to run AFTER the new instance's SpawnForCharacter,
        /// leaving the new player with no UI.
        /// </summary>
        private bool _canvasSpawned;

        /// <summary>
        /// Reference to the canvas spawned by this instance, so OnDestroy can clean it up.
        /// </summary>
        private GameObject _spawnedCanvas;

        /// <summary>
        /// Instance flag: true only for the CanvasSpawner that actually called SpawnForCharacter.
        /// Prevents non-local-player clones from destroying the canvas on their OnDestroy.
        /// </summary>
        private bool _didSpawn;

        #endregion

        #region UNITY

        private void Awake()
        {
            // No longer spawns automatically — PlayerNetworkBridge.OnStartLocalPlayer()
            // calls SpawnForCharacter() at the right time with the local player's Character.
        }

        /// <summary>
        /// When the player prefab is destroyed (respawn or scene unload),
        /// clean up the canvas that this instance created.
        /// Only the instance that actually spawned the canvas performs cleanup.
        /// This runs on EVERY process (server + all clients), so remote clients
        /// can clean up their own canvas state without relying on server RPCs.
        /// </summary>
        private void OnDestroy()
        {
            if (_didSpawn && _canvasSpawned)
            {
                _canvasSpawned = false;
                if (_spawnedCanvas != null)
                {
                    Destroy(_spawnedCanvas);
                    _spawnedCanvas = null;
                }
            }
        }

        #endregion

        #region METHODS

        /// <summary>
        /// Spawns the UI Canvas and injects the local player's Character into all UI Elements.
        /// Called by PlayerNetworkBridge.OnStartLocalPlayer() — ensures the Canvas always
        /// references the local player, not a remote player.
        /// </summary>
        public void SpawnForCharacter(CharacterBehaviour character)
        {
            if (_canvasSpawned) return;
            _canvasSpawned = true;
            _didSpawn = true;

            if (canvasPrefab != null)
            {
                var canvas = Instantiate(canvasPrefab);
                _spawnedCanvas = canvas;
                // Wire the local Character into every UI Element on the Canvas.
                foreach (var element in canvas.GetComponentsInChildren<Element>(true))
                {
                    element.SetCharacter(character);
                }
            }

            if (qualitySettingsPrefab != null)
                Instantiate(qualitySettingsPrefab);
        }

        #endregion
    }
}