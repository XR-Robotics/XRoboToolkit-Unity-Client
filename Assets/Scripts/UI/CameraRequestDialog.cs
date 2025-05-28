using System;
using LitJson;
using TMPro;
using UnityEngine;

public class CameraRequestDialog : MonoBehaviour
{
    public TMP_Dropdown cameraDropdown;

    public TMP_Dropdown resolutionDropdown;

    public TMP_InputField fpsInputField;

    public TMP_InputField bitrateInputField;

    public int ResolutionWidth { get; private set; }
    public int ResolutionHeight { get; private set; }
    public int Fps { get; private set; }
    public int Bitrate { get; private set; }

    private Action _confirm;
    private Action _cancel;

    private string[] _resolutions;

    private JsonData _cameraJsonList;


    private void Awake()
    {
        cameraDropdown.onValueChanged.AddListener(OnCameraSelect);
    }

    public void SetCameraList(JsonData jsons)
    {
        Debug.Log("SetCameraList:" + jsons.ToJson());
        _cameraJsonList = jsons;
        int oldValue = cameraDropdown.value;
        try
        {
            cameraDropdown.ClearOptions();
            for (int i = 0; i < _cameraJsonList.Count; i++)
            {
                JsonData joint = _cameraJsonList[i];
                cameraDropdown.options.Add(new TMP_Dropdown.OptionData(joint["cameraName"].ToString()));
            }
        }
        catch (Exception e)
        {
            Debug.LogError(e.ToString());
        }

        if (oldValue >= _cameraJsonList.Count)
        {
            oldValue = _cameraJsonList.Count - 1;
        }

        cameraDropdown.SetValueWithoutNotify(oldValue);
        cameraDropdown.RefreshShownValue();
        OnCameraSelect(oldValue);
    }

    private void OnCameraSelect(int index)
    {
        string resolutionInfo = _cameraJsonList[index]["Resolution"].ToString();
        SetResolutionData(resolutionInfo);
        int.TryParse(_cameraJsonList[index]["fps"].ToString(), out var fps);
        int bitrate = 1024 * 1024 * 10;
        if (_cameraJsonList[index].ContainsKey("bitrate"))
        {
            bitrate = int.Parse(_cameraJsonList[index]["bitrate"].ToString());
        }

        SetDefaultValue(fps, bitrate);
    }

    public void SetResolutionData(string data)
    {
        int oldValue = resolutionDropdown.value;
        _resolutions = data.Split(',');
        resolutionDropdown.ClearOptions();
        for (int i = 0; i < _resolutions.Length; i++)
        {
            resolutionDropdown.options.Add(new TMP_Dropdown.OptionData(_resolutions[i]));
        }

        if (oldValue >= _resolutions.Length)
        {
            oldValue = _resolutions.Length - 1;
        }

        resolutionDropdown.SetValueWithoutNotify(oldValue);
        resolutionDropdown.RefreshShownValue();
    }

    public void SetDefaultValue(int fps, int bitrate)
    {
        this.fpsInputField.text = fps.ToString();
        this.bitrateInputField.text = bitrate.ToString();
    }

    public void Show(Action confirm, Action cancel)
    {
        gameObject.SetActive(true);

        _confirm = confirm;
        _cancel = cancel;
    }


    public void OnConfirm()
    {
        gameObject.SetActive(false);
        if (_confirm != null)
        {
            if (resolutionDropdown.value >= 0 && resolutionDropdown.value < _resolutions.Length)
            {
                string[] resolutionArr = _resolutions[resolutionDropdown.value].Split("x");

                if (resolutionArr.Length > 1)
                {
                    ResolutionWidth = int.Parse(resolutionArr[0]);
                    ResolutionHeight = int.Parse(resolutionArr[1]);
                    Fps = int.Parse(fpsInputField.text);
                    Bitrate = int.Parse(bitrateInputField.text);
                    _confirm.Invoke();
                }
            }
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