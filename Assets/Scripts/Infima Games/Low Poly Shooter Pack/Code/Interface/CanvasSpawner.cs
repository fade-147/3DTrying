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
        /// </summary>
        private static bool _canvasSpawned;

        #endregion

        #region UNITY

        private void Awake()
        {
            // No longer spawns automatically — PlayerNetworkBridge.OnStartLocalPlayer()
            // calls SpawnForCharacter() at the right time with the local player's Character.
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

            if (canvasPrefab != null)
            {
                var canvas = Instantiate(canvasPrefab);
                // Wire the local Character into every UI Element on the Canvas.
                foreach (var element in canvas.GetComponentsInChildren<Element>(true))
                {
                    element.SetCharacter(character);
                }
            }

            if (qualitySettingsPrefab != null)
                Instantiate(qualitySettingsPrefab);
        }

        /// <summary>
        /// 玩家重生时重置静态标志，并销毁旧的 UI Canvas。
        /// 由 MyNetworkRoomManager.PlayerRespawnSequence 在生成新玩家前调用。
        /// </summary>
        public static void DestroyCanvasAndResetFlag()
        {
            _canvasSpawned = false;
            var oldCanvas = GameObject.Find("P_LPSP_UI_Canvas(Clone)");
            if (oldCanvas != null)
                Destroy(oldCanvas);
        }

        #endregion
    }
}