using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// Inspector-binding container for settings panel UI references.
/// Logic lives in SettingsMenu; this class only holds serialized field references.
/// </summary>
public class SettingManager : MonoBehaviour
{
    public Slider sensitivityXSlider;
    public Slider sensitivityYSlider;
    public Slider volumeSlider;
    public Button surrenderButton;
}