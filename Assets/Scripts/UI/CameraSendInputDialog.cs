using System;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class CameraSendInputDialog : MonoBehaviour
{
    public TMP_InputField TmpInput;
    public TextMeshProUGUI Remind;
    //   public TMP_Dropdown renderModeDropdown;

    public Action<string> OnConfirmCall;
    public Action OnCancelCall;

    public Button CloseBtn;
    public Button ConfirmBtn;

    private string videoSourceName;
    private Color defaultInputTextColor;
    private Color defaultRemindColor;

    private void Awake()
    {
        if (Remind == null)
        {
            foreach (TextMeshProUGUI label in GetComponentsInChildren<TextMeshProUGUI>(true))
            {
                if (label.gameObject.name == "Remind")
                {
                    Remind = label;
                    break;
                }
            }
        }

        if (TmpInput != null && TmpInput.textComponent != null)
        {
            defaultInputTextColor = TmpInput.textComponent.color;
        }
        if (Remind != null)
        {
            defaultRemindColor = Remind.color;
        }

        CloseBtn.onClick.AddListener(OnCloseBtn);
        ConfirmBtn.onClick.AddListener(OnConfirmBtn);
        TmpInput.onValueChanged.AddListener(OnInputValueChanged);
    }

    private void OnDestroy()
    {
        CloseBtn.onClick.RemoveListener(OnCloseBtn);
        ConfirmBtn.onClick.RemoveListener(OnConfirmBtn);
        TmpInput.onValueChanged.RemoveListener(OnInputValueChanged);
        ClearCallbacks();
    }

    public void Show(Action<string> onConfirmCall)
    {
        Show(onConfirmCall, null, null);
    }

    public void Show(Action<string> onConfirmCall, string sourceName)
    {
        Show(onConfirmCall, sourceName, null);
    }

    public void Show(
        Action<string> onConfirmCall,
        string sourceName,
        Action onCancelCall
    )
    {
        videoSourceName = sourceName == null ? string.Empty : sourceName.Trim();
        OnConfirmCall = onConfirmCall;
        OnCancelCall = onCancelCall;
        // An inactive scene object may not have run Awake yet. Activate it before
        // restoring colors or resolving the optional Remind label.
        gameObject.SetActive(true);
        TmpInput.SetTextWithoutNotify(RemoteVisionAddressStore.Load(videoSourceName));
        ClearValidationError();
        TmpInput.Select();
        TmpInput.ActivateInputField();
    }

    private void OnConfirmBtn()
    {
        if (!RemoteVisionAddressStore.TrySave(
                videoSourceName,
                TmpInput.text,
                out string normalizedAddress
            ))
        {
            ShowValidationError("Enter a valid operator IP address.");
            return;
        }

        TmpInput.SetTextWithoutNotify(normalizedAddress);
        Action<string> confirmCall = OnConfirmCall;
        ClearCallbacks();
        gameObject.SetActive(false);
        confirmCall?.Invoke(normalizedAddress);
    }

    private void OnCloseBtn()
    {
        Action cancelCall = OnCancelCall;
        ClearCallbacks();
        gameObject.SetActive(false);
        cancelCall?.Invoke();
    }

    private void OnInputValueChanged(string _)
    {
        ClearValidationError();
    }

    private void ShowValidationError(string message)
    {
        if (Remind != null)
        {
            Remind.color = Color.red;
            Remind.text = message;
        }
        if (TmpInput != null && TmpInput.textComponent != null)
        {
            TmpInput.textComponent.color = Color.red;
        }

        LogWindow.Warn(message);
        Toast.Show(message);
        TmpInput.Select();
        TmpInput.ActivateInputField();
    }

    private void ClearValidationError()
    {
        if (Remind != null)
        {
            Remind.color = defaultRemindColor;
            Remind.text = string.Empty;
        }
        if (TmpInput != null && TmpInput.textComponent != null)
        {
            TmpInput.textComponent.color = defaultInputTextColor;
        }
    }

    private void ClearCallbacks()
    {
        OnConfirmCall = null;
        OnCancelCall = null;
        videoSourceName = string.Empty;
    }
}
