using StarterAssets;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ChangeAnimator : MonoBehaviour
{
    public ThirdPersonController controller;
    
    public void OnAnimChange()
    {
        controller.OnInspectComplete();
    }
}
