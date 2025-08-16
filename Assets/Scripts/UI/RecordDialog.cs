using System;
using TMPro;
using Unity.XR.PICO.TOBSupport;
using UnityEngine;
using UnityEngine.UI;

public class RecordDialog : MonoBehaviour
{
    public TMP_InputField widthInputField;

    public TMP_InputField heightInputField;

    public TMP_InputField fpsInputField;

    public TMP_InputField bitrateInputField;

    //   public TMP_Dropdown renderModeDropdown;

    public Toggle trackingDataTog;
    private Action _confirm;
    private Action _cancel;
    public int ResolutionWidth
    {
        get { return PlayerPrefs.GetInt("RecordResolutionWidth", 2160); }
        set { PlayerPrefs.SetInt("RecordResolutionWidth", value); }
    }

    public int ResolutionHeight
    {
        get { return PlayerPrefs.GetInt("RecordResolutionHeight", 810); }
        set { PlayerPrefs.SetInt("RecordResolutionHeight", value); }
    }

    public int Fps
    {
        get { return PlayerPrefs.GetInt("RecordFps", 30); }
        set { PlayerPrefs.SetInt("RecordFps", value); }
    }

    public int Bitrate
    {
        get { return PlayerPrefs.GetInt("RecordBitrate", 20 * 1024 * 1024); }
        set { PlayerPrefs.SetInt("RecordBitrate", value); }
    }

    /* public int CaptureRenderMode
     {
         get
         {
             return PlayerPrefs.GetInt("RecordCaptureRenderMode", (int)PXRCaptureRenderMode.PXRCapture_RenderMode_3D);
         }
         set { PlayerPrefs.SetInt("RecordCaptureRenderMode", value); }
     }
 */
    public bool RecordTrackingData { get; private set; }

    /*  private void Awake()
      {
          renderModeDropdown.ClearOptions();
          renderModeDropdown.options.Add(new TMP_Dropdown.OptionData("RenderMode_LEFT"));
          renderModeDropdown.options.Add(new TMP_Dropdown.OptionData("RenderMode_RIGHT"));
          renderModeDropdown.options.Add(new TMP_Dropdown.OptionData("RenderMode_3D"));
          renderModeDropdown.options.Add(new TMP_Dropdown.OptionData("RenderMode_Interlace"));
      }
  */
    private void Start()
    {
        this.widthInputField.text = ResolutionWidth.ToString();
        this.heightInputField.text = ResolutionHeight.ToString();
        this.fpsInputField.text = Fps.ToString();
        this.bitrateInputField.text = Bitrate.ToString();
        trackingDataTog.isOn = true;
        //   renderModeDropdown.SetValueWithoutNotify(CaptureRenderMode);
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
        ResolutionWidth = int.Parse(widthInputField.text);
        ResolutionHeight = int.Parse(heightInputField.text);
        Fps = int.Parse(fpsInputField.text);
        Bitrate = int.Parse(bitrateInputField.text);
        //     CaptureRenderMode = renderModeDropdown.value;

        RecordTrackingData = trackingDataTog.isOn;
        if (_confirm != null)
        {
            _confirm.Invoke();
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