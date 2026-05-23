using System.Collections;
using System.Collections.Generic;
//using StarterAssets;
using UnityEngine;

public class SaveManager : MonoBehaviour
{
    public static SaveManager Instance { get; private set; }

    private void Awake()
    {
        Instance = this;      
        DontDestroyOnLoad(this.gameObject);
    }

    public void Save(System.Object data ,string key)
    {
        var jsonData = JsonUtility.ToJson(data);
        PlayerPrefs.SetString(key, jsonData);
        PlayerPrefs.Save();
    }

    public void Load(System.Object data, string key)
    {
        if(PlayerPrefs.HasKey(key))
        {
            var jsonData = PlayerPrefs.GetString(key);
            JsonUtility.FromJsonOverwrite(jsonData, data);
        }
    }
    
    public void Destroy()
    {

    }

}
