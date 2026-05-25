using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;   

public class HotUpdateView : MonoBehaviour
{
    [SerializeField] private Text _texPrgs;
    //[SerializeField] private Text _texTips;
    [SerializeField] private Slider _slider;
    [SerializeField] public Button startButton;

    [Header("更新确认面板")]
    [SerializeField] public GameObject updateConfirmPanel;
    [SerializeField] public Button confirmUpdateButton;
    [SerializeField] public Button confirmQuitButton;
    [SerializeField] private Text _updateInfoText;

    public void RefreshUI(float prgs, string prgsTex)
    {
        _slider.value = prgs;
        _texPrgs.text = prgsTex;
    }

    public void ShowUpdateInfo(int fileCount, long totalBytes)
    {
        if (_updateInfoText != null)
            _updateInfoText.text = $"发现 {fileCount} 个文件需要更新，总计 {totalBytes / 1024f / 1024f:F1} MB";
        if (updateConfirmPanel != null)
            updateConfirmPanel.SetActive(true);
    }

    public void HideUpdateConfirm()
    {
        if (updateConfirmPanel != null)
            updateConfirmPanel.SetActive(false);
    }
}
