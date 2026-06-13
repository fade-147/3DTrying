using InfimaGames.LowPolyShooterPack;

/// <summary>
/// Gameplay UI 管理器接口，通过 ServiceLocator 注册。
/// 每个客户端独立注册，实现计分面板个性化（左=己方，右=敌方）。
/// </summary>
public interface IGameUIManager : IGameService
{
    void RegisterLocalPlayerTeam(int teamId);
    void UpdateScoreDisplay(int redScore, int blueScore);
    void ShowGameOver(int winningTeam, int redScore, int blueScore);
    void HideGameOver();
}
