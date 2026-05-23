using System.IO;
using UnityEngine;
using Mirror;

public class RuntimeInspector : MonoBehaviour
{
    void Start()
    {
        DumpRoomPlayers();
    }

    void DumpRoomPlayers()
    {
        string logPath = Path.Combine(Application.persistentDataPath, "runtime_dump.txt");
        using (var sw = new StreamWriter(logPath, false))
        {
            sw.WriteLine("Runtime dump at: " + System.DateTime.Now);
            // dump registered remote call handlers
            try
            {
                sw.WriteLine("--- Registered Remote Call Handlers ---");
                Mirror.RemoteCalls.RemoteProcedureCalls.DumpRegisteredHandlers();
            }
            catch { }
            foreach (var ni in FindObjectsOfType<NetworkIdentity>())
            {
                if (ni.name.Contains("Room Player") || ni.name.Contains("RoomPlayer"))
                {
                    sw.WriteLine($"--- NetworkIdentity: {ni.name} netId={ni.netId} sceneId={ni.sceneId:X}");
                    Debug.Log($"[Inspector] {ni.name} netId={ni.netId}");

                    Component[] comps = ni.GetComponents<Component>();
                    for (int i = 0; i < comps.Length; i++)
                    {
                        string compInfo = comps[i] != null ? comps[i].GetType().FullName : "<Missing Script>";
                        sw.WriteLine($"comp[{i}] = {compInfo}");
                        Debug.Log($"comp[{i}] = {compInfo}");
                    }

                    var nbs = ni.NetworkBehaviours;
                    sw.WriteLine($"NetworkBehaviours.Length = {nbs.Length}");
                    for (int i = 0; i < nbs.Length; i++)
                    {
                        var nb = nbs[i];
                        if (nb == null)
                        {
                            sw.WriteLine($"nb[{i}] = <null - missing script?>");
                            Debug.Log($"nb[{i}] = <null - missing script?>");
                            continue;
                        }
                        string typeName = nb.GetType().FullName;
                        string asm = nb.GetType().Assembly.GetName().Name;
                        bool weaved = false;
                        try { weaved = nb.Weaved(); } catch { weaved = false; }
                        sw.WriteLine($"nb[{i}] = {typeName} (asm:{asm}) weaved={weaved}");
                        Debug.Log($"nb[{i}] = {typeName} (asm:{asm}) weaved={weaved}");
                    }
                    sw.WriteLine("");
                }
            }
            sw.Flush();
        }
        Debug.Log($"RuntimeInspector: dump written to {logPath}");
    }
}