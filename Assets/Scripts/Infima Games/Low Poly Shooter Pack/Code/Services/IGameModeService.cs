//Copyright 2022, Infima Games. All Rights Reserved.

namespace InfimaGames.LowPolyShooterPack
{
    /// <summary>
    /// Game Mode Service.
    /// </summary>
    public interface IGameModeService : IGameService
    {
        /// <summary>
        /// Returns the Player Character.
        /// </summary>
        CharacterBehaviour GetPlayerCharacter();

        /// <summary>
        /// Registers a specific CharacterBehaviour instance as the player character.
        /// Called by PlayerNetworkBridge.OnStartLocalPlayer to ensure each client's
        /// Movement/CameraLook components find their own Character in multiplayer.
        /// </summary>
        void RegisterPlayerCharacter(CharacterBehaviour character);
    }
}