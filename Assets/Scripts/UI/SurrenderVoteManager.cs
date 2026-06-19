using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Mirror;
using StarterAssets;

/// <summary>
/// Networked surrender vote system.
/// Server manages sessions; clients display vote UI via SurrenderVoteUI.
/// Must be placed on a GameObject with NetworkIdentity in GameScene.
/// </summary>
public class SurrenderVoteManager : NetworkBehaviour
{
    public static SurrenderVoteManager Instance { get; private set; }

    [Header("Settings")]
    [SerializeField] private float _voteTimeout = 30f;

    [Header("UI Reference (optional — falls back to FindObjectOfType)")]
    [SerializeField] private SurrenderVoteUI _voteUI;

    /// <summary>
    /// Server-side active sessions, keyed by teamId.
    /// </summary>
    private readonly Dictionary<int, SurrenderSession> _sessions = new Dictionary<int, SurrenderSession>();

    private void Awake()
    {
        Instance = this;
    }

    private SurrenderVoteUI VoteUI
    {
        get
        {
            if (_voteUI == null)
                _voteUI = FindObjectOfType<SurrenderVoteUI>();
            return _voteUI;
        }
    }

    #region Public API

    /// <summary>
    /// Called by SettingsMenu on the initiating client.
    /// </summary>
    public void InitiateSurrender(int teamId)
    {
        Debug.Log($"[Surrender] Client initiating surrender for team {teamId}");
        CmdInitiateSurrender(teamId);
    }

    #endregion

    #region Server Commands

    [Command(requiresAuthority = false)]
    private void CmdInitiateSurrender(int teamId, NetworkConnectionToClient sender = null)
    {
        if (_sessions.ContainsKey(teamId))
        {
            Debug.LogWarning($"[Surrender] Vote already in progress for team {teamId}");
            return;
        }

        int totalMembers = CountTeamMembers(teamId);
        Debug.Log($"[Surrender] Team {teamId} has {totalMembers} real player(s)");

        if (totalMembers < 2)
        {
            Debug.Log($"[Surrender] Team {teamId} only {totalMembers} player(s), auto-accepted.");
            DoSurrenderResult(teamId, true);
            return;
        }

        var session = new SurrenderSession
        {
            teamId = teamId,
            endTime = (float)NetworkTime.time + _voteTimeout,
            totalMembers = totalMembers
        };
        _sessions[teamId] = session;

        Debug.Log($"[Surrender] Vote started for team {teamId} ({totalMembers} members)");
        RpcShowVote(teamId, session.endTime, totalMembers);
        StartCoroutine(TimeoutCheck(teamId));
    }

    [Command(requiresAuthority = false)]
    public void CmdVoteSurrender(int teamId, bool voteYes, NetworkConnectionToClient sender = null)
    {
        if (!_sessions.TryGetValue(teamId, out var session) || session.finished)
            return;

        if (sender == null) return;
        uint netId = sender.identity.netId;

        if (!session.votedPlayers.Add(netId))
        {
            Debug.LogWarning($"[Surrender] Player {netId} already voted.");
            return;
        }

        if (voteYes)
            session.yesVotes++;
        else
            session.noVotes++;

        Debug.Log($"[Surrender] Team {teamId}: yes={session.yesVotes}/{session.totalMembers}, voted={session.votedPlayers.Count}/{session.totalMembers}");

        RpcUpdateVoteProgress(teamId, session.yesVotes, session.votedPlayers.Count, session.totalMembers);
        CheckResult(teamId);
    }

    #endregion

    #region Server Logic

    /// <summary>
    /// Counts only REAL players (from NetworkServer.connections). Bots are excluded.
    /// </summary>
    private int CountTeamMembers(int teamId)
    {
        int count = 0;
        foreach (var conn in NetworkServer.connections)
        {
            var identity = conn.Value?.identity;
            if (identity == null) continue;

            var tpc = identity.GetComponent<ThirdPersonController>();
            if (tpc != null && tpc.teamId == teamId)
                count++;
        }
        return count;
    }

    private void CheckResult(int teamId)
    {
        if (!_sessions.TryGetValue(teamId, out var session) || session.finished)
            return;

        int remaining = session.totalMembers - session.votedPlayers.Count;
        bool accepted;

        if (session.yesVotes * 2 >= session.totalMembers)
        {
            accepted = true;
            session.finished = true;
        }
        else if ((session.yesVotes + remaining) * 2 < session.totalMembers)
        {
            accepted = false;
            session.finished = true;
        }
        else if (remaining == 0)
        {
            accepted = false;
            session.finished = true;
        }
        else
        {
            return;
        }

        Debug.Log($"[Surrender] Team {teamId} result: {(accepted ? "SURRENDER" : "REJECTED")}");
        _sessions.Remove(teamId);
        DoSurrenderResult(teamId, accepted);
    }

    /// <summary>
    /// Handles surrender result: notify clients + trigger game-over for losing team.
    /// </summary>
    private void DoSurrenderResult(int teamId, bool accepted)
    {
        RpcSurrenderResult(teamId, accepted);

        if (accepted)
        {
            var tsm = TeamScoreManager.Instance;
            if (tsm != null)
            {
                tsm.ForceGameOver(teamId);
            }
            else
            {
                Debug.LogError("[Surrender] TeamScoreManager.Instance is null — cannot trigger game over!");
            }
        }
    }

    private IEnumerator TimeoutCheck(int teamId)
    {
        if (!_sessions.TryGetValue(teamId, out var session))
            yield break;

        float waitTime = session.endTime - (float)NetworkTime.time;
        if (waitTime > 0)
            yield return new WaitForSeconds(waitTime);

        if (_sessions.TryGetValue(teamId, out var s) && !s.finished)
        {
            s.finished = true;
            _sessions.Remove(teamId);
            Debug.Log($"[Surrender] Team {teamId}: vote timed out — rejected.");
            DoSurrenderResult(teamId, false);
        }
    }

    #endregion

    #region Client RPCs

    [ClientRpc]
    private void RpcShowVote(int teamId, float endTime, int totalMembers)
    {
        int myTeam = GetMyTeamId();
        Debug.Log($"[Surrender] RpcShowVote received: team={teamId}, myTeam={myTeam}, voteUI={VoteUI != null}");

        if (myTeam != teamId) return;

        if (VoteUI != null)
        {
            VoteUI.Show(teamId, endTime, totalMembers);
            Debug.Log($"[Surrender] Vote UI shown for team {teamId}");
        }
        else
        {
            Debug.LogError("[Surrender] VoteUI is null! Make sure SurrenderVotePanel exists in scene with SurrenderVoteUI component.");
        }
    }

    [ClientRpc]
    private void RpcUpdateVoteProgress(int teamId, int yesVotes, int votedCount, int totalMembers)
    {
        int myTeam = GetMyTeamId();
        if (myTeam != teamId) return;

        if (VoteUI != null)
            VoteUI.UpdateProgress(yesVotes, votedCount, totalMembers);
    }

    [ClientRpc]
    private void RpcSurrenderResult(int teamId, bool accepted)
    {
        int myTeam = GetMyTeamId();

        if (VoteUI != null)
            VoteUI.Hide();

        var settingsMenu = FindObjectOfType<SettingsMenu>();
        if (settingsMenu != null)
            settingsMenu.EnableSurrenderButton();

        if (myTeam == teamId)
        {
            Debug.Log($"[Surrender] Result for your team: {(accepted ? "SURRENDERED" : "REJECTED")}");
        }
    }

    #endregion

    #region Helpers

    private int GetMyTeamId()
    {
        var identity = NetworkClient.connection?.identity;
        if (identity == null)
        {
            Debug.LogWarning("[Surrender] GetMyTeamId: NetworkClient.connection.identity is null — player not spawned yet?");
            return -1;
        }

        var tpc = identity.GetComponent<ThirdPersonController>();
        if (tpc != null) return tpc.teamId;

        var pnb = identity.GetComponent<PlayerNetworkBridge>();
        if (pnb != null) return pnb.teamId;

        Debug.LogWarning("[Surrender] GetMyTeamId: no TPC or PNB on player identity");
        return -1;
    }

    #endregion

    #region Data Types

    private class SurrenderSession
    {
        public int teamId;
        public float endTime;
        public int totalMembers;
        public int yesVotes;
        public int noVotes;
        public bool finished;
        public HashSet<uint> votedPlayers = new HashSet<uint>();
    }

    #endregion
}
