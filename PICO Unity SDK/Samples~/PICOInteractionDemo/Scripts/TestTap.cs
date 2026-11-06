using System.Collections;
using System.Collections.Generic;
using ByteDance.PICO.Interaction;
using UnityEngine;
using UnityEngine.UI;

public class TestTap : MonoBehaviour
{
    public Text tapText;
    /// <summary>
    /// Single click callback example
    /// </summary>
    /// <param name="uiObject">UI object that triggered the event</param>
    public void OnUISingleClick()
    {
        tapText.text = "Single Click";
        Debug.Log($"Business logic: single clicked UI ");
        // Example: change UI color
        // var image = this.GetComponent<UnityEngine.UI.Image>();
        // if (image != null) image.color = Color.green;
    }

    /// <summary>
    /// Double click callback example
    /// </summary>
    public void OnUIDoubleClick()
    {
        tapText.text = "Double Click";
        Debug.Log($"Business logic: double clicked UI ");
        // var image = this.GetComponent<UnityEngine.UI.Image>();
        // if (image != null) image.color = Color.blue;
    }

    /// <summary>
    /// Long press start callback example
    /// </summary>
    public void OnUILongPress()
    {
        tapText.text = "Long Press";
        Debug.Log($"Business logic: long press - UI ");
        // var image = this.GetComponent<UnityEngine.UI.Image>();
        // if (image != null) image.color = Color.red;
    }

   
}
