using System;
using TMPro;
using UnityEngine;

public class ResolutionDialog : MonoBehaviour
{
    public TextMeshProUGUI titleTmp;
    public TMP_InputField widthInputField;

    public TMP_InputField heightInputField;

    public int ResolutionWidth
    {
        get { return PlayerPrefs.GetInt("ResolutionWidth", 1024); }
        set { PlayerPrefs.SetInt("ResolutionWidth", value); }
    }

    public int ResolutionHeight
    {
        get { return PlayerPrefs.GetInt("ResolutionHeight", 768 / 2); }
        set { PlayerPrefs.SetInt("ResolutionHeight", value); }
    }

    private Action _cancel;
    private Action<int, int> _confirm;

    public void Show(string title, Action<int, int> call, Action cancel)
    {
        gameObject.SetActive(true);
        titleTmp.text = title;
        widthInputField.text = ResolutionWidth.ToString();
        heightInputField.text = ResolutionHeight.ToString();
        _confirm = call;
        _cancel = cancel;
    }

    public void OnConfirm()
    {
        gameObject.SetActive(false);
        ResolutionWidth = int.Parse(widthInputField.text);
        ResolutionHeight = int.Parse(heightInputField.text);
        if (_confirm != null)
        {
            _confirm.Invoke(ResolutionWidth, ResolutionHeight);
        }
    }

    public void OnCancel()
    {
        gameObject.SetActive(false);
        if (_cancel != null)
        {
            _cancel.Invoke();
        }
    }
}