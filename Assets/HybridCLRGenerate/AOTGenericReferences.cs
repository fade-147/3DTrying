using System.Collections.Generic;
public class AOTGenericReferences : UnityEngine.MonoBehaviour
{

	// {{ AOT assemblies
	public static readonly IReadOnlyList<string> PatchedAOTAssemblyList = new List<string>
	{
		"Adrenak.UniVoice.Runtime.dll",
		"Mirror.dll",
		"ParadoxNotion.dll",
		"System.Core.dll",
		"Unity.InputSystem.dll",
		"UnityEngine.CoreModule.dll",
		"com.rlabrecque.steamworks.net.dll",
		"mscorlib.dll",
	};
	// }}

	// {{ constraint implement type
	// }} 

	// {{ AOT generic types
	// Adrenak.UniVoice.ClientSession.<>c<int>
	// Adrenak.UniVoice.ClientSession.FilterFactoryEntry<int>
	// Adrenak.UniVoice.ClientSession<int>
	// Adrenak.UniVoice.IAudioClient<int>
	// Adrenak.UniVoice.IAudioServer<int>
	// Mirror.NetworkClient.<>c__DisplayClass61_0<BotListMessage>
	// Mirror.NetworkMessages.<>c__DisplayClass8_0<BotListMessage,object>
	// Mirror.NetworkMessages.<>c__DisplayClass8_0<Mirror.AddPlayerMessage,object>
	// Mirror.NetworkMessages.<>c__DisplayClass9_0<BotListMessage,object>
	// Mirror.NetworkMessages.<>c__DisplayClass9_0<Mirror.AddPlayerMessage,object>
	// Mirror.Pool<object>
	// Mirror.Reader<Adrenak.UniVoice.Networks.MirrorMessage>
	// Mirror.Reader<BotListMessage>
	// Mirror.Reader<Mirror.AddPlayerMessage>
	// Mirror.Reader<Mirror.ChangeOwnerMessage>
	// Mirror.Reader<Mirror.CommandMessage>
	// Mirror.Reader<Mirror.Discovery.ServerRequest>
	// Mirror.Reader<Mirror.Discovery.ServerResponse>
	// Mirror.Reader<Mirror.EntityStateMessage>
	// Mirror.Reader<Mirror.NetworkBehaviourSyncVar>
	// Mirror.Reader<Mirror.NetworkPingMessage>
	// Mirror.Reader<Mirror.NetworkPongMessage>
	// Mirror.Reader<Mirror.NotReadyMessage>
	// Mirror.Reader<Mirror.ObjectDestroyMessage>
	// Mirror.Reader<Mirror.ObjectHideMessage>
	// Mirror.Reader<Mirror.ObjectSpawnFinishedMessage>
	// Mirror.Reader<Mirror.ObjectSpawnStartedMessage>
	// Mirror.Reader<Mirror.PredictedSyncData>
	// Mirror.Reader<Mirror.ReadyMessage>
	// Mirror.Reader<Mirror.RpcMessage>
	// Mirror.Reader<Mirror.SceneMessage>
	// Mirror.Reader<Mirror.SpawnMessage>
	// Mirror.Reader<Mirror.SyncData>
	// Mirror.Reader<Mirror.TimeSnapshotMessage>
	// Mirror.Reader<System.ArraySegment<byte>>
	// Mirror.Reader<System.DateTime>
	// Mirror.Reader<System.Decimal>
	// Mirror.Reader<System.Guid>
	// Mirror.Reader<System.Half>
	// Mirror.Reader<System.Nullable<System.DateTime>>
	// Mirror.Reader<System.Nullable<System.Decimal>>
	// Mirror.Reader<System.Nullable<System.Guid>>
	// Mirror.Reader<System.Nullable<UnityEngine.Color32>>
	// Mirror.Reader<System.Nullable<UnityEngine.Color>>
	// Mirror.Reader<System.Nullable<UnityEngine.LayerMask>>
	// Mirror.Reader<System.Nullable<UnityEngine.Matrix4x4>>
	// Mirror.Reader<System.Nullable<UnityEngine.Plane>>
	// Mirror.Reader<System.Nullable<UnityEngine.Quaternion>>
	// Mirror.Reader<System.Nullable<UnityEngine.Ray>>
	// Mirror.Reader<System.Nullable<UnityEngine.Rect>>
	// Mirror.Reader<System.Nullable<UnityEngine.Vector2>>
	// Mirror.Reader<System.Nullable<UnityEngine.Vector2Int>>
	// Mirror.Reader<System.Nullable<UnityEngine.Vector3>>
	// Mirror.Reader<System.Nullable<UnityEngine.Vector3Int>>
	// Mirror.Reader<System.Nullable<UnityEngine.Vector4>>
	// Mirror.Reader<System.Nullable<byte>>
	// Mirror.Reader<System.Nullable<double>>
	// Mirror.Reader<System.Nullable<float>>
	// Mirror.Reader<System.Nullable<int>>
	// Mirror.Reader<System.Nullable<long>>
	// Mirror.Reader<System.Nullable<sbyte>>
	// Mirror.Reader<System.Nullable<short>>
	// Mirror.Reader<System.Nullable<uint>>
	// Mirror.Reader<System.Nullable<ulong>>
	// Mirror.Reader<System.Nullable<ushort>>
	// Mirror.Reader<UnityEngine.Color32>
	// Mirror.Reader<UnityEngine.Color>
	// Mirror.Reader<UnityEngine.LayerMask>
	// Mirror.Reader<UnityEngine.Matrix4x4>
	// Mirror.Reader<UnityEngine.Plane>
	// Mirror.Reader<UnityEngine.Quaternion>
	// Mirror.Reader<UnityEngine.Ray>
	// Mirror.Reader<UnityEngine.Rect>
	// Mirror.Reader<UnityEngine.Vector2>
	// Mirror.Reader<UnityEngine.Vector2Int>
	// Mirror.Reader<UnityEngine.Vector3>
	// Mirror.Reader<UnityEngine.Vector3Int>
	// Mirror.Reader<UnityEngine.Vector4>
	// Mirror.Reader<byte>
	// Mirror.Reader<double>
	// Mirror.Reader<float>
	// Mirror.Reader<int>
	// Mirror.Reader<long>
	// Mirror.Reader<object>
	// Mirror.Reader<sbyte>
	// Mirror.Reader<short>
	// Mirror.Reader<uint>
	// Mirror.Reader<ulong>
	// Mirror.Reader<ushort>
	// Mirror.Writer<Adrenak.UniVoice.Networks.MirrorMessage>
	// Mirror.Writer<BotListMessage>
	// Mirror.Writer<Mirror.AddPlayerMessage>
	// Mirror.Writer<Mirror.ChangeOwnerMessage>
	// Mirror.Writer<Mirror.CommandMessage>
	// Mirror.Writer<Mirror.Discovery.ServerRequest>
	// Mirror.Writer<Mirror.Discovery.ServerResponse>
	// Mirror.Writer<Mirror.EntityStateMessage>
	// Mirror.Writer<Mirror.NetworkPingMessage>
	// Mirror.Writer<Mirror.NetworkPongMessage>
	// Mirror.Writer<Mirror.NotReadyMessage>
	// Mirror.Writer<Mirror.ObjectDestroyMessage>
	// Mirror.Writer<Mirror.ObjectHideMessage>
	// Mirror.Writer<Mirror.ObjectSpawnFinishedMessage>
	// Mirror.Writer<Mirror.ObjectSpawnStartedMessage>
	// Mirror.Writer<Mirror.PredictedSyncData>
	// Mirror.Writer<Mirror.ReadyMessage>
	// Mirror.Writer<Mirror.RpcMessage>
	// Mirror.Writer<Mirror.SceneMessage>
	// Mirror.Writer<Mirror.SpawnMessage>
	// Mirror.Writer<Mirror.SyncData>
	// Mirror.Writer<Mirror.TimeSnapshotMessage>
	// Mirror.Writer<System.ArraySegment<byte>>
	// Mirror.Writer<System.DateTime>
	// Mirror.Writer<System.Decimal>
	// Mirror.Writer<System.Guid>
	// Mirror.Writer<System.Half>
	// Mirror.Writer<System.Nullable<System.DateTime>>
	// Mirror.Writer<System.Nullable<System.Decimal>>
	// Mirror.Writer<System.Nullable<System.Guid>>
	// Mirror.Writer<System.Nullable<UnityEngine.Color32>>
	// Mirror.Writer<System.Nullable<UnityEngine.Color>>
	// Mirror.Writer<System.Nullable<UnityEngine.LayerMask>>
	// Mirror.Writer<System.Nullable<UnityEngine.Matrix4x4>>
	// Mirror.Writer<System.Nullable<UnityEngine.Plane>>
	// Mirror.Writer<System.Nullable<UnityEngine.Quaternion>>
	// Mirror.Writer<System.Nullable<UnityEngine.Ray>>
	// Mirror.Writer<System.Nullable<UnityEngine.Rect>>
	// Mirror.Writer<System.Nullable<UnityEngine.Vector2>>
	// Mirror.Writer<System.Nullable<UnityEngine.Vector2Int>>
	// Mirror.Writer<System.Nullable<UnityEngine.Vector3>>
	// Mirror.Writer<System.Nullable<UnityEngine.Vector3Int>>
	// Mirror.Writer<System.Nullable<UnityEngine.Vector4>>
	// Mirror.Writer<System.Nullable<byte>>
	// Mirror.Writer<System.Nullable<double>>
	// Mirror.Writer<System.Nullable<float>>
	// Mirror.Writer<System.Nullable<int>>
	// Mirror.Writer<System.Nullable<long>>
	// Mirror.Writer<System.Nullable<sbyte>>
	// Mirror.Writer<System.Nullable<short>>
	// Mirror.Writer<System.Nullable<uint>>
	// Mirror.Writer<System.Nullable<ulong>>
	// Mirror.Writer<System.Nullable<ushort>>
	// Mirror.Writer<UnityEngine.Color32>
	// Mirror.Writer<UnityEngine.Color>
	// Mirror.Writer<UnityEngine.LayerMask>
	// Mirror.Writer<UnityEngine.Matrix4x4>
	// Mirror.Writer<UnityEngine.Plane>
	// Mirror.Writer<UnityEngine.Quaternion>
	// Mirror.Writer<UnityEngine.Ray>
	// Mirror.Writer<UnityEngine.Rect>
	// Mirror.Writer<UnityEngine.Vector2>
	// Mirror.Writer<UnityEngine.Vector2Int>
	// Mirror.Writer<UnityEngine.Vector3>
	// Mirror.Writer<UnityEngine.Vector3Int>
	// Mirror.Writer<UnityEngine.Vector4>
	// Mirror.Writer<byte>
	// Mirror.Writer<double>
	// Mirror.Writer<float>
	// Mirror.Writer<int>
	// Mirror.Writer<long>
	// Mirror.Writer<object>
	// Mirror.Writer<sbyte>
	// Mirror.Writer<short>
	// Mirror.Writer<uint>
	// Mirror.Writer<ulong>
	// Mirror.Writer<ushort>
	// NodeCanvas.Framework.BBParameter.<>c<UnityEngine.Vector3>
	// NodeCanvas.Framework.BBParameter.<>c<float>
	// NodeCanvas.Framework.BBParameter.<>c<object>
	// NodeCanvas.Framework.BBParameter.<>c__DisplayClass20_0<UnityEngine.Vector3>
	// NodeCanvas.Framework.BBParameter.<>c__DisplayClass20_0<float>
	// NodeCanvas.Framework.BBParameter.<>c__DisplayClass20_0<object>
	// NodeCanvas.Framework.BBParameter.<>c__DisplayClass21_0<UnityEngine.Vector3>
	// NodeCanvas.Framework.BBParameter.<>c__DisplayClass21_0<float>
	// NodeCanvas.Framework.BBParameter.<>c__DisplayClass21_0<object>
	// NodeCanvas.Framework.BBParameter<UnityEngine.Vector3>
	// NodeCanvas.Framework.BBParameter<float>
	// NodeCanvas.Framework.BBParameter<object>
	// NodeCanvas.Framework.Variable.<>c<UnityEngine.Vector3>
	// NodeCanvas.Framework.Variable.<>c<float>
	// NodeCanvas.Framework.Variable.<>c<object>
	// NodeCanvas.Framework.Variable.<>c__DisplayClass27_0<UnityEngine.Vector3>
	// NodeCanvas.Framework.Variable.<>c__DisplayClass27_0<float>
	// NodeCanvas.Framework.Variable.<>c__DisplayClass27_0<object>
	// NodeCanvas.Framework.Variable.<>c__DisplayClass27_1<UnityEngine.Vector3>
	// NodeCanvas.Framework.Variable.<>c__DisplayClass27_1<float>
	// NodeCanvas.Framework.Variable.<>c__DisplayClass27_1<object>
	// NodeCanvas.Framework.Variable.<>c__DisplayClass27_2<UnityEngine.Vector3>
	// NodeCanvas.Framework.Variable.<>c__DisplayClass27_2<float>
	// NodeCanvas.Framework.Variable.<>c__DisplayClass27_2<object>
	// NodeCanvas.Framework.Variable<UnityEngine.Vector3>
	// NodeCanvas.Framework.Variable<float>
	// NodeCanvas.Framework.Variable<object>
	// Steamworks.Callback.DispatchDelegate<Steamworks.GameLobbyJoinRequested_t>
	// Steamworks.Callback.DispatchDelegate<Steamworks.LobbyCreated_t>
	// Steamworks.Callback.DispatchDelegate<Steamworks.LobbyEnter_t>
	// Steamworks.Callback<Steamworks.GameLobbyJoinRequested_t>
	// Steamworks.Callback<Steamworks.LobbyCreated_t>
	// Steamworks.Callback<Steamworks.LobbyEnter_t>
	// System.Action<Adrenak.UniVoice.AudioFrame>
	// System.Action<BotListMessage>
	// System.Action<Mirror.NetworkDiagnostics.MessageInfo>
	// System.Action<UnityEngine.InputSystem.InputAction.CallbackContext>
	// System.Action<UnityEngine.Vector3>
	// System.Action<byte,byte>
	// System.Action<float,float>
	// System.Action<float>
	// System.Action<int,Adrenak.UniVoice.AudioFrame>
	// System.Action<int,int>
	// System.Action<int,object>
	// System.Action<int>
	// System.Action<object,Adrenak.UniVoice.Networks.MirrorMessage>
	// System.Action<object,BotListMessage,int>
	// System.Action<object,BotListMessage>
	// System.Action<object,Mirror.AddPlayerMessage,int>
	// System.Action<object,Mirror.AddPlayerMessage>
	// System.Action<object,Mirror.ChangeOwnerMessage>
	// System.Action<object,Mirror.CommandMessage>
	// System.Action<object,Mirror.Discovery.ServerRequest>
	// System.Action<object,Mirror.Discovery.ServerResponse>
	// System.Action<object,Mirror.EntityStateMessage>
	// System.Action<object,Mirror.NetworkPingMessage>
	// System.Action<object,Mirror.NetworkPongMessage>
	// System.Action<object,Mirror.NotReadyMessage>
	// System.Action<object,Mirror.ObjectDestroyMessage>
	// System.Action<object,Mirror.ObjectHideMessage>
	// System.Action<object,Mirror.ObjectSpawnFinishedMessage>
	// System.Action<object,Mirror.ObjectSpawnStartedMessage>
	// System.Action<object,Mirror.PredictedSyncData>
	// System.Action<object,Mirror.ReadyMessage>
	// System.Action<object,Mirror.RpcMessage>
	// System.Action<object,Mirror.SceneMessage>
	// System.Action<object,Mirror.SpawnMessage>
	// System.Action<object,Mirror.SyncData>
	// System.Action<object,Mirror.TimeSnapshotMessage>
	// System.Action<object,System.ArraySegment<byte>>
	// System.Action<object,System.DateTime>
	// System.Action<object,System.Decimal>
	// System.Action<object,System.Guid>
	// System.Action<object,System.Half>
	// System.Action<object,System.Nullable<System.DateTime>>
	// System.Action<object,System.Nullable<System.Decimal>>
	// System.Action<object,System.Nullable<System.Guid>>
	// System.Action<object,System.Nullable<UnityEngine.Color32>>
	// System.Action<object,System.Nullable<UnityEngine.Color>>
	// System.Action<object,System.Nullable<UnityEngine.LayerMask>>
	// System.Action<object,System.Nullable<UnityEngine.Matrix4x4>>
	// System.Action<object,System.Nullable<UnityEngine.Plane>>
	// System.Action<object,System.Nullable<UnityEngine.Quaternion>>
	// System.Action<object,System.Nullable<UnityEngine.Ray>>
	// System.Action<object,System.Nullable<UnityEngine.Rect>>
	// System.Action<object,System.Nullable<UnityEngine.Vector2>>
	// System.Action<object,System.Nullable<UnityEngine.Vector2Int>>
	// System.Action<object,System.Nullable<UnityEngine.Vector3>>
	// System.Action<object,System.Nullable<UnityEngine.Vector3Int>>
	// System.Action<object,System.Nullable<UnityEngine.Vector4>>
	// System.Action<object,System.Nullable<byte>>
	// System.Action<object,System.Nullable<double>>
	// System.Action<object,System.Nullable<float>>
	// System.Action<object,System.Nullable<int>>
	// System.Action<object,System.Nullable<long>>
	// System.Action<object,System.Nullable<sbyte>>
	// System.Action<object,System.Nullable<short>>
	// System.Action<object,System.Nullable<uint>>
	// System.Action<object,System.Nullable<ulong>>
	// System.Action<object,System.Nullable<ushort>>
	// System.Action<object,UnityEngine.Color32>
	// System.Action<object,UnityEngine.Color>
	// System.Action<object,UnityEngine.LayerMask>
	// System.Action<object,UnityEngine.Matrix4x4>
	// System.Action<object,UnityEngine.Plane>
	// System.Action<object,UnityEngine.Quaternion>
	// System.Action<object,UnityEngine.Ray>
	// System.Action<object,UnityEngine.Rect>
	// System.Action<object,UnityEngine.Vector2>
	// System.Action<object,UnityEngine.Vector2Int>
	// System.Action<object,UnityEngine.Vector3>
	// System.Action<object,UnityEngine.Vector3Int>
	// System.Action<object,UnityEngine.Vector4>
	// System.Action<object,byte>
	// System.Action<object,double>
	// System.Action<object,float>
	// System.Action<object,int,object>
	// System.Action<object,int>
	// System.Action<object,long>
	// System.Action<object,object>
	// System.Action<object,sbyte>
	// System.Action<object,short>
	// System.Action<object,uint>
	// System.Action<object,ulong>
	// System.Action<object,ushort>
	// System.Action<object>
	// System.ArraySegment.Enumerator<byte>
	// System.ArraySegment<byte>
	// System.Collections.Generic.ArraySortHelper<int>
	// System.Collections.Generic.ArraySortHelper<object>
	// System.Collections.Generic.Comparer<int>
	// System.Collections.Generic.Comparer<object>
	// System.Collections.Generic.Dictionary.Enumerator<int,int>
	// System.Collections.Generic.Dictionary.Enumerator<int,object>
	// System.Collections.Generic.Dictionary.Enumerator<object,float>
	// System.Collections.Generic.Dictionary.Enumerator<object,object>
	// System.Collections.Generic.Dictionary.Enumerator<uint,object>
	// System.Collections.Generic.Dictionary.Enumerator<ushort,object>
	// System.Collections.Generic.Dictionary.KeyCollection.Enumerator<int,int>
	// System.Collections.Generic.Dictionary.KeyCollection.Enumerator<int,object>
	// System.Collections.Generic.Dictionary.KeyCollection.Enumerator<object,float>
	// System.Collections.Generic.Dictionary.KeyCollection.Enumerator<object,object>
	// System.Collections.Generic.Dictionary.KeyCollection.Enumerator<uint,object>
	// System.Collections.Generic.Dictionary.KeyCollection.Enumerator<ushort,object>
	// System.Collections.Generic.Dictionary.KeyCollection<int,int>
	// System.Collections.Generic.Dictionary.KeyCollection<int,object>
	// System.Collections.Generic.Dictionary.KeyCollection<object,float>
	// System.Collections.Generic.Dictionary.KeyCollection<object,object>
	// System.Collections.Generic.Dictionary.KeyCollection<uint,object>
	// System.Collections.Generic.Dictionary.KeyCollection<ushort,object>
	// System.Collections.Generic.Dictionary.ValueCollection.Enumerator<int,int>
	// System.Collections.Generic.Dictionary.ValueCollection.Enumerator<int,object>
	// System.Collections.Generic.Dictionary.ValueCollection.Enumerator<object,float>
	// System.Collections.Generic.Dictionary.ValueCollection.Enumerator<object,object>
	// System.Collections.Generic.Dictionary.ValueCollection.Enumerator<uint,object>
	// System.Collections.Generic.Dictionary.ValueCollection.Enumerator<ushort,object>
	// System.Collections.Generic.Dictionary.ValueCollection<int,int>
	// System.Collections.Generic.Dictionary.ValueCollection<int,object>
	// System.Collections.Generic.Dictionary.ValueCollection<object,float>
	// System.Collections.Generic.Dictionary.ValueCollection<object,object>
	// System.Collections.Generic.Dictionary.ValueCollection<uint,object>
	// System.Collections.Generic.Dictionary.ValueCollection<ushort,object>
	// System.Collections.Generic.Dictionary<int,int>
	// System.Collections.Generic.Dictionary<int,object>
	// System.Collections.Generic.Dictionary<object,float>
	// System.Collections.Generic.Dictionary<object,object>
	// System.Collections.Generic.Dictionary<uint,object>
	// System.Collections.Generic.Dictionary<ushort,object>
	// System.Collections.Generic.EqualityComparer<Mirror.NetworkRoomManager.PendingPlayer>
	// System.Collections.Generic.EqualityComparer<byte>
	// System.Collections.Generic.EqualityComparer<float>
	// System.Collections.Generic.EqualityComparer<int>
	// System.Collections.Generic.EqualityComparer<object>
	// System.Collections.Generic.EqualityComparer<uint>
	// System.Collections.Generic.EqualityComparer<ushort>
	// System.Collections.Generic.HashSet.Enumerator<Mirror.NetworkRoomManager.PendingPlayer>
	// System.Collections.Generic.HashSet.Enumerator<object>
	// System.Collections.Generic.HashSet<Mirror.NetworkRoomManager.PendingPlayer>
	// System.Collections.Generic.HashSet<object>
	// System.Collections.Generic.HashSetEqualityComparer<Mirror.NetworkRoomManager.PendingPlayer>
	// System.Collections.Generic.HashSetEqualityComparer<object>
	// System.Collections.Generic.ICollection<Mirror.NetworkRoomManager.PendingPlayer>
	// System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<int,int>>
	// System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<int,object>>
	// System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<object,float>>
	// System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<object,object>>
	// System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<uint,object>>
	// System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<ushort,object>>
	// System.Collections.Generic.ICollection<int>
	// System.Collections.Generic.ICollection<object>
	// System.Collections.Generic.IComparer<int>
	// System.Collections.Generic.IComparer<object>
	// System.Collections.Generic.IEnumerable<Mirror.NetworkRoomManager.PendingPlayer>
	// System.Collections.Generic.IEnumerable<System.Collections.Generic.KeyValuePair<int,int>>
	// System.Collections.Generic.IEnumerable<System.Collections.Generic.KeyValuePair<int,object>>
	// System.Collections.Generic.IEnumerable<System.Collections.Generic.KeyValuePair<object,float>>
	// System.Collections.Generic.IEnumerable<System.Collections.Generic.KeyValuePair<object,object>>
	// System.Collections.Generic.IEnumerable<System.Collections.Generic.KeyValuePair<uint,object>>
	// System.Collections.Generic.IEnumerable<System.Collections.Generic.KeyValuePair<ushort,object>>
	// System.Collections.Generic.IEnumerable<int>
	// System.Collections.Generic.IEnumerable<object>
	// System.Collections.Generic.IEnumerator<Mirror.NetworkRoomManager.PendingPlayer>
	// System.Collections.Generic.IEnumerator<System.Collections.Generic.KeyValuePair<int,int>>
	// System.Collections.Generic.IEnumerator<System.Collections.Generic.KeyValuePair<int,object>>
	// System.Collections.Generic.IEnumerator<System.Collections.Generic.KeyValuePair<object,float>>
	// System.Collections.Generic.IEnumerator<System.Collections.Generic.KeyValuePair<object,object>>
	// System.Collections.Generic.IEnumerator<System.Collections.Generic.KeyValuePair<uint,object>>
	// System.Collections.Generic.IEnumerator<System.Collections.Generic.KeyValuePair<ushort,object>>
	// System.Collections.Generic.IEnumerator<int>
	// System.Collections.Generic.IEnumerator<object>
	// System.Collections.Generic.IEqualityComparer<Mirror.NetworkRoomManager.PendingPlayer>
	// System.Collections.Generic.IEqualityComparer<int>
	// System.Collections.Generic.IEqualityComparer<object>
	// System.Collections.Generic.IEqualityComparer<uint>
	// System.Collections.Generic.IEqualityComparer<ushort>
	// System.Collections.Generic.IList<System.Collections.Generic.KeyValuePair<object,object>>
	// System.Collections.Generic.IList<int>
	// System.Collections.Generic.IList<object>
	// System.Collections.Generic.IReadOnlyList<object>
	// System.Collections.Generic.KeyValuePair<int,int>
	// System.Collections.Generic.KeyValuePair<int,object>
	// System.Collections.Generic.KeyValuePair<object,float>
	// System.Collections.Generic.KeyValuePair<object,object>
	// System.Collections.Generic.KeyValuePair<uint,object>
	// System.Collections.Generic.KeyValuePair<ushort,object>
	// System.Collections.Generic.List.Enumerator<int>
	// System.Collections.Generic.List.Enumerator<object>
	// System.Collections.Generic.List<int>
	// System.Collections.Generic.List<object>
	// System.Collections.Generic.ObjectComparer<int>
	// System.Collections.Generic.ObjectComparer<object>
	// System.Collections.Generic.ObjectEqualityComparer<Mirror.NetworkRoomManager.PendingPlayer>
	// System.Collections.Generic.ObjectEqualityComparer<byte>
	// System.Collections.Generic.ObjectEqualityComparer<float>
	// System.Collections.Generic.ObjectEqualityComparer<int>
	// System.Collections.Generic.ObjectEqualityComparer<object>
	// System.Collections.Generic.ObjectEqualityComparer<uint>
	// System.Collections.Generic.ObjectEqualityComparer<ushort>
	// System.Collections.Generic.Queue.Enumerator<UnityEngine.Vector3>
	// System.Collections.Generic.Queue.Enumerator<object>
	// System.Collections.Generic.Queue<UnityEngine.Vector3>
	// System.Collections.Generic.Queue<object>
	// System.Collections.Generic.Stack.Enumerator<object>
	// System.Collections.Generic.Stack<object>
	// System.Collections.ObjectModel.ReadOnlyCollection<int>
	// System.Collections.ObjectModel.ReadOnlyCollection<object>
	// System.Comparison<int>
	// System.Comparison<object>
	// System.Func<UnityEngine.Vector3>
	// System.Func<byte>
	// System.Func<float>
	// System.Func<object,Adrenak.UniVoice.Networks.MirrorMessage>
	// System.Func<object,BotListMessage>
	// System.Func<object,Mirror.AddPlayerMessage>
	// System.Func<object,Mirror.ChangeOwnerMessage>
	// System.Func<object,Mirror.CommandMessage>
	// System.Func<object,Mirror.Discovery.ServerRequest>
	// System.Func<object,Mirror.Discovery.ServerResponse>
	// System.Func<object,Mirror.EntityStateMessage>
	// System.Func<object,Mirror.NetworkBehaviourSyncVar>
	// System.Func<object,Mirror.NetworkPingMessage>
	// System.Func<object,Mirror.NetworkPongMessage>
	// System.Func<object,Mirror.NotReadyMessage>
	// System.Func<object,Mirror.ObjectDestroyMessage>
	// System.Func<object,Mirror.ObjectHideMessage>
	// System.Func<object,Mirror.ObjectSpawnFinishedMessage>
	// System.Func<object,Mirror.ObjectSpawnStartedMessage>
	// System.Func<object,Mirror.PredictedSyncData>
	// System.Func<object,Mirror.ReadyMessage>
	// System.Func<object,Mirror.RpcMessage>
	// System.Func<object,Mirror.SceneMessage>
	// System.Func<object,Mirror.SpawnMessage>
	// System.Func<object,Mirror.SyncData>
	// System.Func<object,Mirror.TimeSnapshotMessage>
	// System.Func<object,System.ArraySegment<byte>>
	// System.Func<object,System.DateTime>
	// System.Func<object,System.Decimal>
	// System.Func<object,System.Guid>
	// System.Func<object,System.Half>
	// System.Func<object,System.Nullable<System.DateTime>>
	// System.Func<object,System.Nullable<System.Decimal>>
	// System.Func<object,System.Nullable<System.Guid>>
	// System.Func<object,System.Nullable<UnityEngine.Color32>>
	// System.Func<object,System.Nullable<UnityEngine.Color>>
	// System.Func<object,System.Nullable<UnityEngine.LayerMask>>
	// System.Func<object,System.Nullable<UnityEngine.Matrix4x4>>
	// System.Func<object,System.Nullable<UnityEngine.Plane>>
	// System.Func<object,System.Nullable<UnityEngine.Quaternion>>
	// System.Func<object,System.Nullable<UnityEngine.Ray>>
	// System.Func<object,System.Nullable<UnityEngine.Rect>>
	// System.Func<object,System.Nullable<UnityEngine.Vector2>>
	// System.Func<object,System.Nullable<UnityEngine.Vector2Int>>
	// System.Func<object,System.Nullable<UnityEngine.Vector3>>
	// System.Func<object,System.Nullable<UnityEngine.Vector3Int>>
	// System.Func<object,System.Nullable<UnityEngine.Vector4>>
	// System.Func<object,System.Nullable<byte>>
	// System.Func<object,System.Nullable<double>>
	// System.Func<object,System.Nullable<float>>
	// System.Func<object,System.Nullable<int>>
	// System.Func<object,System.Nullable<long>>
	// System.Func<object,System.Nullable<sbyte>>
	// System.Func<object,System.Nullable<short>>
	// System.Func<object,System.Nullable<uint>>
	// System.Func<object,System.Nullable<ulong>>
	// System.Func<object,System.Nullable<ushort>>
	// System.Func<object,UnityEngine.Color32>
	// System.Func<object,UnityEngine.Color>
	// System.Func<object,UnityEngine.LayerMask>
	// System.Func<object,UnityEngine.Matrix4x4>
	// System.Func<object,UnityEngine.Plane>
	// System.Func<object,UnityEngine.Quaternion>
	// System.Func<object,UnityEngine.Ray>
	// System.Func<object,UnityEngine.Rect>
	// System.Func<object,UnityEngine.Vector2>
	// System.Func<object,UnityEngine.Vector2Int>
	// System.Func<object,UnityEngine.Vector3>
	// System.Func<object,UnityEngine.Vector3Int>
	// System.Func<object,UnityEngine.Vector4>
	// System.Func<object,byte>
	// System.Func<object,double>
	// System.Func<object,float>
	// System.Func<object,int>
	// System.Func<object,long>
	// System.Func<object,object>
	// System.Func<object,sbyte>
	// System.Func<object,short>
	// System.Func<object,uint>
	// System.Func<object,ulong>
	// System.Func<object,ushort>
	// System.Func<object>
	// System.Nullable<UnityEngine.InputSystem.InputAction.CallbackContext>
	// System.Nullable<byte>
	// System.Predicate<Mirror.NetworkRoomManager.PendingPlayer>
	// System.Predicate<int>
	// System.Predicate<object>
	// UnityEngine.Events.InvokableCall<float>
	// UnityEngine.Events.UnityAction<float>
	// UnityEngine.Events.UnityEvent<float>
	// UnityEngine.InputSystem.InputBindingComposite<UnityEngine.Vector2>
	// UnityEngine.InputSystem.InputBindingComposite<float>
	// UnityEngine.InputSystem.InputControl<UnityEngine.Vector2>
	// UnityEngine.InputSystem.InputControl<float>
	// UnityEngine.InputSystem.InputProcessor<UnityEngine.Vector2>
	// UnityEngine.InputSystem.InputProcessor<float>
	// UnityEngine.InputSystem.Utilities.InlinedArray<object>
	// }}

	public void RefMethods()
	{
		// System.Void Adrenak.UniVoice.ClientSession<int>.AddOutputFilter<object>(System.Func<Adrenak.UniVoice.IAudioFilter>)
		// System.Void Mirror.NetworkBehaviour.GeneratedSyncVarDeserialize<byte>(byte&,System.Action<byte,byte>,byte)
		// System.Void Mirror.NetworkBehaviour.GeneratedSyncVarDeserialize<float>(float&,System.Action<float,float>,float)
		// System.Void Mirror.NetworkBehaviour.GeneratedSyncVarDeserialize<int>(int&,System.Action<int,int>,int)
		// System.Void Mirror.NetworkBehaviour.GeneratedSyncVarSetter<byte>(byte,byte&,ulong,System.Action<byte,byte>)
		// System.Void Mirror.NetworkBehaviour.GeneratedSyncVarSetter<float>(float,float&,ulong,System.Action<float,float>)
		// System.Void Mirror.NetworkBehaviour.GeneratedSyncVarSetter<int>(int,int&,ulong,System.Action<int,int>)
		// System.Void Mirror.NetworkBehaviour.SetSyncVar<byte>(byte,byte&,ulong)
		// System.Void Mirror.NetworkBehaviour.SetSyncVar<float>(float,float&,ulong)
		// System.Void Mirror.NetworkBehaviour.SetSyncVar<int>(int,int&,ulong)
		// bool Mirror.NetworkBehaviour.SyncVarEqual<byte>(byte,byte&)
		// bool Mirror.NetworkBehaviour.SyncVarEqual<float>(float,float&)
		// bool Mirror.NetworkBehaviour.SyncVarEqual<int>(int,int&)
		// System.Void Mirror.NetworkClient.RegisterHandler<BotListMessage>(System.Action<BotListMessage>,bool)
		// System.Void Mirror.NetworkConnection.Send<BotListMessage>(BotListMessage,int)
		// System.Void Mirror.NetworkDiagnostics.OnSend<BotListMessage>(BotListMessage,int,int,int)
		// System.Void Mirror.NetworkDiagnostics.OnSend<Mirror.SceneMessage>(Mirror.SceneMessage,int,int,int)
		// System.Void Mirror.NetworkMessages.Pack<BotListMessage>(BotListMessage,Mirror.NetworkWriter)
		// System.Void Mirror.NetworkMessages.Pack<Mirror.SceneMessage>(Mirror.SceneMessage,Mirror.NetworkWriter)
		// Mirror.NetworkMessageDelegate Mirror.NetworkMessages.WrapHandler<BotListMessage,object>(System.Action<object,BotListMessage,int>,bool,bool)
		// Mirror.NetworkMessageDelegate Mirror.NetworkMessages.WrapHandler<BotListMessage,object>(System.Action<object,BotListMessage>,bool,bool)
		// Mirror.NetworkMessageDelegate Mirror.NetworkMessages.WrapHandler<Mirror.AddPlayerMessage,object>(System.Action<object,Mirror.AddPlayerMessage,int>,bool,bool)
		// Mirror.NetworkMessageDelegate Mirror.NetworkMessages.WrapHandler<Mirror.AddPlayerMessage,object>(System.Action<object,Mirror.AddPlayerMessage>,bool,bool)
		// int Mirror.NetworkReader.Read<int>()
		// int[] Mirror.NetworkReaderExtensions.ReadArray<int>(Mirror.NetworkReader)
		// System.Void Mirror.NetworkServer.RegisterHandler<Mirror.AddPlayerMessage>(System.Action<Mirror.NetworkConnectionToClient,Mirror.AddPlayerMessage>,bool)
		// System.Void Mirror.NetworkServer.SendToAll<BotListMessage>(BotListMessage,int,bool)
		// System.Void Mirror.NetworkServer.SendToAll<Mirror.SceneMessage>(Mirror.SceneMessage,int,bool)
		// System.Void Mirror.NetworkWriter.Write<BotListMessage>(BotListMessage)
		// System.Void Mirror.NetworkWriter.Write<Mirror.SceneMessage>(Mirror.SceneMessage)
		// System.Void Mirror.NetworkWriter.Write<int>(int)
		// System.Void Mirror.NetworkWriterExtensions.WriteArray<int>(Mirror.NetworkWriter,int[])
		// int System.Linq.Enumerable.Count<System.Collections.Generic.KeyValuePair<object,object>>(System.Collections.Generic.IEnumerable<System.Collections.Generic.KeyValuePair<object,object>>)
		// int System.Linq.Enumerable.Count<object>(System.Collections.Generic.IEnumerable<object>)
		// System.Collections.Generic.KeyValuePair<object,object> System.Linq.Enumerable.ElementAt<System.Collections.Generic.KeyValuePair<object,object>>(System.Collections.Generic.IEnumerable<System.Collections.Generic.KeyValuePair<object,object>>,int)
		// object System.Linq.Enumerable.ElementAt<object>(System.Collections.Generic.IEnumerable<object>,int)
		// object& System.Runtime.CompilerServices.Unsafe.As<object,object>(object&)
		// System.Void* System.Runtime.CompilerServices.Unsafe.AsPointer<object>(object&)
		// System.Void* Unity.Collections.LowLevel.Unsafe.UnsafeUtility.AddressOf<UnityEngine.Vector2>(UnityEngine.Vector2&)
		// System.Void* Unity.Collections.LowLevel.Unsafe.UnsafeUtility.AddressOf<float>(float&)
		// int Unity.Collections.LowLevel.Unsafe.UnsafeUtility.SizeOf<UnityEngine.Vector2>()
		// int Unity.Collections.LowLevel.Unsafe.UnsafeUtility.SizeOf<float>()
		// object UnityEngine.Component.GetComponent<object>()
		// object UnityEngine.Component.GetComponentInChildren<object>()
		// object UnityEngine.Component.GetComponentInChildren<object>(bool)
		// object[] UnityEngine.Component.GetComponents<object>()
		// object[] UnityEngine.Component.GetComponentsInChildren<object>()
		// object[] UnityEngine.Component.GetComponentsInChildren<object>(bool)
		// bool UnityEngine.Component.TryGetComponent<object>(object&)
		// object UnityEngine.GameObject.AddComponent<object>()
		// object UnityEngine.GameObject.GetComponent<object>()
		// object UnityEngine.GameObject.GetComponentInChildren<object>()
		// object UnityEngine.GameObject.GetComponentInChildren<object>(bool)
		// object UnityEngine.GameObject.GetComponentInParent<object>()
		// object UnityEngine.GameObject.GetComponentInParent<object>(bool)
		// object[] UnityEngine.GameObject.GetComponents<object>()
		// object[] UnityEngine.GameObject.GetComponentsInChildren<object>(bool)
		// bool UnityEngine.GameObject.TryGetComponent<object>(object&)
		// UnityEngine.Vector2 UnityEngine.InputSystem.InputAction.ReadValue<UnityEngine.Vector2>()
		// UnityEngine.Vector2 UnityEngine.InputSystem.InputAction.CallbackContext.ReadValue<UnityEngine.Vector2>()
		// float UnityEngine.InputSystem.InputAction.CallbackContext.ReadValue<float>()
		// UnityEngine.Vector2 UnityEngine.InputSystem.InputActionState.ApplyProcessors<UnityEngine.Vector2>(int,UnityEngine.Vector2,UnityEngine.InputSystem.InputControl<UnityEngine.Vector2>)
		// float UnityEngine.InputSystem.InputActionState.ApplyProcessors<float>(int,float,UnityEngine.InputSystem.InputControl<float>)
		// UnityEngine.Vector2 UnityEngine.InputSystem.InputActionState.ReadValue<UnityEngine.Vector2>(int,int,bool)
		// float UnityEngine.InputSystem.InputActionState.ReadValue<float>(int,int,bool)
		// UnityEngine.Vector2 UnityEngine.InputSystem.InputValue.Get<UnityEngine.Vector2>()
		// object UnityEngine.Object.FindObjectOfType<object>()
		// object[] UnityEngine.Object.FindObjectsByType<object>(UnityEngine.FindObjectsSortMode)
		// object[] UnityEngine.Object.FindObjectsOfType<object>()
		// object UnityEngine.Object.Instantiate<object>(object)
		// object UnityEngine.Object.Instantiate<object>(object,UnityEngine.Transform)
		// object UnityEngine.Object.Instantiate<object>(object,UnityEngine.Transform,bool)
		// object UnityEngine.Object.Instantiate<object>(object,UnityEngine.Vector3,UnityEngine.Quaternion)
		// object[] UnityEngine.Resources.ConvertObjects<object>(UnityEngine.Object[])
		// string string.Join<int>(string,System.Collections.Generic.IEnumerable<int>)
		// string string.JoinCore<int>(System.Char*,int,System.Collections.Generic.IEnumerable<int>)
	}
}