using UnityEngine;

#if MIRROR
using Adrenak.UniMic;
using Adrenak.UniVoice;
using Adrenak.UniVoice.Networks;
using Adrenak.UniVoice.Outputs;
using Adrenak.UniVoice.Inputs;
using Adrenak.UniVoice.Filters;
using Mirror;
#endif

public enum MicMode
{
    All,        // 开麦，听全部
    TeamOnly,   // 开麦，仅队伍
    Muted,      // 关麦，但仍能听到（保留之前的收听范围）
    Deafened    // 关麦，也听不到
}

public class VoiceChatManager : MonoBehaviour
{
    public static VoiceChatManager Instance { get; private set; }

#if MIRROR
    public static IAudioServer<int> AudioServer { get; private set; }
    public static ClientSession<int> ClientSession { get; private set; }
#endif

    [SerializeField] bool useOpusCompression = true;
    [SerializeField] bool useVad = true;
    [SerializeField] int recordingDurationSeconds = 60;

    public MicMode CurrentMode { get; private set; } = MicMode.Deafened;

    // 关麦前的收听模式，用于 Muted 状态下保持正确的收听范围
    MicMode _lastActiveMode = MicMode.All;

    int _localTeamId = 0;
    public int LocalTeamId
    {
        get => _localTeamId;
        set
        {
            if (_localTeamId != value)
            {
                _localTeamId = value;
                if (CurrentMode == MicMode.TeamOnly
                    || (CurrentMode == MicMode.Muted && _lastActiveMode == MicMode.TeamOnly))
                    ApplyTeamOnlyVoiceSettings();
            }
        }
    }

    void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
            DontDestroyOnLoad(gameObject);
        }
        else
        {
            Destroy(gameObject);
            return;
        }
    }

    void Start()
    {
#if MIRROR
        Setup();
#else
        Debug.LogError("[VoiceChatManager] MIRROR scripting define symbol not found.");
#endif
    }

#if MIRROR
    void Setup()
    {
        AudioServer = new MirrorServer();
        AudioServer.OnServerStart += () => Debug.Log("[VoiceChatManager] Audio server started");
        AudioServer.OnServerStop += () => Debug.Log("[VoiceChatManager] Audio server stopped");

        IAudioInput input;
        Mic.Init();
        if (Mic.AvailableDevices.Count == 0)
        {
            Debug.LogWarning("[VoiceChatManager] No microphone detected, listen only mode.");
            input = new EmptyAudioInput();
        }
        else
        {
            var mic = Mic.AvailableDevices[0];
            mic.StartRecording(recordingDurationSeconds);
            Debug.Log($"[VoiceChatManager] Using mic: {mic.Name}, freq={mic.SamplingFrequency}, frameMs={mic.FrameDurationMS}");
            input = new UniMicInput(mic);
        }

        var outputFactory = new StreamedAudioSourceOutput.Factory();

        var client = new MirrorClient();
        client.OnJoined += (id, peers) => Debug.Log($"[VoiceChatManager] Joined chatroom. ID={id}, Peers={string.Join(", ", peers)}");
        client.OnLeft += () => Debug.Log("[VoiceChatManager] Left chatroom");
        client.OnPeerJoined += id => Debug.Log($"[VoiceChatManager] Peer {id} joined");
        client.OnPeerLeft += id => Debug.Log($"[VoiceChatManager] Peer {id} left");

        ClientSession = new ClientSession<int>(client, input, outputFactory);
        ClientSession.InputEnabled = false;
        ClientSession.OutputsEnabled = false;

        ClientSession.InputFilters.Add(new GaussianAudioBlur());

        if (useVad)
            ClientSession.InputFilters.Add(new SimpleVadFilter(new SimpleVad()));

        if (useOpusCompression)
        {
            ClientSession.InputFilters.Add(new ConcentusEncodeFilter());
            ClientSession.AddOutputFilter<ConcentusDecodeFilter>(() => new ConcentusDecodeFilter());
        }

        Debug.Log("[VoiceChatManager] UniVoice setup complete.");
    }

    public void SetMode(MicMode mode)
    {
        CurrentMode = mode;
        switch (mode)
        {
            case MicMode.All:
                _lastActiveMode = MicMode.All;
                ClientSession.InputEnabled = true;
                ClientSession.OutputsEnabled = true;
                ClientSession.Client.UpdateVoiceSettings(s =>
                {
                    s.myTags.Clear();
                    s.mutedTags.Clear();
                    s.deafenedTags.Clear();
                });
                break;

            case MicMode.TeamOnly:
                _lastActiveMode = MicMode.TeamOnly;
                ClientSession.InputEnabled = true;
                ClientSession.OutputsEnabled = true;
                ApplyTeamOnlyVoiceSettings();
                break;

            case MicMode.Muted:
                ClientSession.InputEnabled = false;
                ClientSession.OutputsEnabled = true;
                // 不改变 VoiceSettings，保持之前的收听范围
                break;

            case MicMode.Deafened:
                ClientSession.InputEnabled = false;
                ClientSession.OutputsEnabled = false;
                break;
        }
        Debug.Log($"[VoiceChatManager] Mode changed to: {CurrentMode}");
    }

    public void ToggleMode()
    {
        MicMode next = CurrentMode switch
        {
            MicMode.All => MicMode.TeamOnly,
            MicMode.TeamOnly => MicMode.Muted,
            MicMode.Muted => MicMode.Deafened,
            MicMode.Deafened => MicMode.All,
            _ => MicMode.All
        };
        SetMode(next);
    }

    void ApplyTeamOnlyVoiceSettings()
    {
        string myTag = $"team{_localTeamId}";
        string oppTag = $"team{1 - _localTeamId}";

        ClientSession.Client.UpdateVoiceSettings(s =>
        {
            s.myTags.Clear();
            s.myTags.Add(myTag);
            s.mutedTags.Clear();
            s.mutedTags.Add(oppTag);
            s.deafenedTags.Clear();
            s.deafenedTags.Add(oppTag);
        });
    }

    void OnDestroy()
    {
        if (Instance == this)
        {
            ClientSession?.Dispose();
            // AudioServer?.Dispose() 内部访问 NetworkManager.singleton.transport，
            // 服务端关闭时 singleton 可能已销毁导致 NRE。需在 NetworkManager 存活时才释放。
            if (NetworkManager.singleton != null)
                AudioServer?.Dispose();
        }
    }
#endif
}
