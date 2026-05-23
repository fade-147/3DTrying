using System;
using System.Collections.Generic;
using UnityEngine;

public class BotTeamTracker : MonoBehaviour
{
    public readonly List<int> botTeamIds = new List<int>();

    public event Action OnBotListChanged;

    public void AddBot(int teamId)
    {
        botTeamIds.Add(teamId);
        OnBotListChanged?.Invoke();
    }

    public void RemoveLastBot(int teamId)
    {
        for (int i = botTeamIds.Count - 1; i >= 0; i--)
        {
            if (botTeamIds[i] == teamId)
            {
                botTeamIds.RemoveAt(i);
                OnBotListChanged?.Invoke();
                return;
            }
        }
    }

    public void ClearBots()
    {
        if (botTeamIds.Count > 0)
        {
            botTeamIds.Clear();
            OnBotListChanged?.Invoke();
        }
    }
}
