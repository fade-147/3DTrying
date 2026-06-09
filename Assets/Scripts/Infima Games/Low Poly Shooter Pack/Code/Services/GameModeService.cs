//Copyright 2022, Infima Games. All Rights Reserved.

namespace InfimaGames.LowPolyShooterPack
{
    /// <summary>
    /// Game Mode Service.
    /// </summary>
    public class GameModeService : IGameModeService
    {
        #region FIELDS
        
        /// <summary>
        /// The Player Character.
        /// </summary>
        private CharacterBehaviour playerCharacter;
        
        #endregion
        
        #region FUNCTIONS
        
        public CharacterBehaviour GetPlayerCharacter()
        {
            //Make sure we have a player character that is good to go!
            if (playerCharacter == null)
                playerCharacter = UnityEngine.Object.FindObjectOfType<CharacterBehaviour>();

            //Return.
            return playerCharacter;
        }

        /// <summary>
        /// Registers a specific CharacterBehaviour instance as the player character.
        /// Called by PlayerNetworkBridge.OnStartLocalPlayer to ensure each client's
        /// Movement/CameraLook components find their own Character, not another player's.
        /// </summary>
        public void RegisterPlayerCharacter(CharacterBehaviour character)
        {
            playerCharacter = character;
        }

        #endregion
    }
}