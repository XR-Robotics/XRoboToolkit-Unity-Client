using System;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class CameraSendInputDialog : MonoBehaviour
{
    public TMP_InputField TmpInput;
    //   public TMP_Dropdown renderModeDropdown;

    public Action<string> OnConfirmCall;

    public Button CloseBtn;
    public Button ConfirmBtn;

    private void Awake()
    {
        CloseBtn.onClick.AddListener(OnCloseBtn);
        ConfirmBtn.onClick.AddListener(OnConfirmBtn);
    }

    private void OnDestroy()
    {
        CloseBtn.onClick.RemoveListener(OnCloseBtn);
        ConfirmBtn.onClick.RemoveListener(OnConfirmBtn);
    }

    public void Show(Action<string> onConfirmCall)
    {
        TmpInput.text = PlayerPrefs.GetString("CameraSendInputDialog", "");
        OnConfirmCall = onConfirmCall;
        gameObject.SetActive(true);
    }

    private void OnConfirmBtn()
    {
        PlayerPrefs.SetString("CameraSendInputDialog", TmpInput.text);
        if (OnConfirmCall != null)
        {
            OnConfirmCall(TmpInput.text);
        }

        gameObject.SetActive(false);
    }

    private void OnCloseBtn()
    {
        gameObject.SetActive(false);
    }
}