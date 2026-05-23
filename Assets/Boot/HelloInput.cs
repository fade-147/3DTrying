using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class HelloInput : MonoBehaviour
{
    public InputField userInputField; 
    public Text userNameText;
    public Text setInCountText;

    public Button saveButton;
    public GameObject userNameUI;


    [System.Serializable]
    public class UserGameData
    {
        // 玩家输入的名字
        public string userName;
        // 进入游戏的次数
        public int setInCount;
    }

    private UserGameData userGameData = new UserGameData();

    void Start()
    {
        if(PlayerPrefs.HasKey("UserGameData"))
        {
            SaveManager.Instance.Load(userGameData, "UserGameData");

            if(!string.IsNullOrEmpty(userGameData.userName))
            {
                userNameUI.SetActive(false);
            }
            else
            {
                userNameUI.SetActive(true);
                saveButton.onClick.AddListener(OnSaveButtonClicked);
                userInputField.interactable = true;
            }

            userGameData.setInCount++;
            SaveManager.Instance.Save(userGameData, "UserGameData");
            ShowUserUsing();
        }
        else
        {
            userNameUI.SetActive(true);
            saveButton.onClick.AddListener(OnSaveButtonClicked);
            userInputField.interactable = true;

            userGameData.setInCount = 1;
            SaveManager.Instance.Save(userGameData, "UserGameData");
        }
        
    }

    void OnSaveButtonClicked()
    {
        // 锁定输入
        userInputField.interactable = false;
        userInputField.DeactivateInputField();
        saveButton.interactable = false;

        userGameData.userName = userInputField.text;   ///获取用户的输入
        Debug.Log($"用户输入：{userGameData.userName}");
        SaveManager.Instance.Save(userGameData, "UserGameData");
        PlayerPrefs.Save();
        userNameUI.SetActive(false);
        ShowUserUsing();
    }

    public void ShowUserUsing()
    {
        userNameText.text = userGameData.userName;
        setInCountText.text = $"这是你第{userGameData.setInCount}次进入游戏，玩的开心哦";
    }

    // 解锁方法
    // public void UnlockInput()
    // {
    //     userInputField.interactable = true;
    //     saveButton.interactable = true;
    // }
}
