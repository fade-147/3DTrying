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

    public void RefreshUI(float prgs,string prgsTex)
    {
        _slider.value = prgs;
        _texPrgs.text = prgsTex;
    }
}
