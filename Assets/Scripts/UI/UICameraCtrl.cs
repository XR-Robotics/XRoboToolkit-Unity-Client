using System;
using System.IO;
using LitJson;
using Robot;
using Unity.XR.PICO.TOBSupport;
using UnityEngine;
using UnityEngine.UI;

public partial class UICameraCtrl : MonoBehaviour
{
    public GameObject RemoteCameraWindowObj;
    public RecordDialog RecordDialog;
    public CameraRequestDialog CameraRequestDialog;
    public ResolutionDialog ResolutionDialog;
    public CameraSendInputDialog CameraSendInputDialog;
    public CustomButton RecordBtn;
    public CustomButton ListenCameraBtn;
    public CustomButton CameraSendToBtn;
    
    public CustomButton ListenPCCameraBtn;
    public Dropdown cameraDropdown;

    public SetLERE setLere;

    private JsonData _recordJson;
    public Text CameraStatusText;

    private void Awake()
    {
        RecordBtn.OnChange += OnRecordBtn;
        CameraSendToBtn.OnChange += OnCameraSendToBtn;
        ListenCameraBtn.OnChange += OnListenCameraBtnBtn;
        ListenPCCameraBtn.OnChange += ListenPCCameraBtnOnOnChange;
        TcpHandler.ReceiveFunctionEvent += OnNetReceive;
        CameraHandle.AddStateListener(OnCameraStateChanged);
    }
    
    private void ListenPCCameraBtnOnOnChange(bool on)
    {
        if (on)
        {
            ListenPCCamera();
        }
        else
        {
            RemoteCameraWindowObj.SetActive(false);
        }
        ListenPCCameraBtn.SetOn(on);
    }

    private void OnCameraStateChanged(int state)
    {
        CameraStatusText.text = state.ToString();
    }


    private void OnDestroy()
    {
        TcpHandler.ReceiveFunctionEvent -= OnNetReceive;
        CameraHandle.RemoveStateListener(OnCameraStateChanged);
    }

    private void OnCameraSendToBtn(bool on)
    {
        if (on)
        {
            CameraSendInputDialog.Show(SendVRCameraToVR);
        }
        else
        {
            StopSendImage();
        }
    }

    public void SendVRCameraToVR(string ip)
    {
        CameraHandle.StartCameraPreview(1920, 1920/2, 60, 20 * 1024 * 1024, 0,
            (int)PXRCaptureRenderMode.PXRCapture_RenderMode_3D,
            () => { CameraHandle.StartSendImage(ip, 12345); });
        CameraSendToBtn.SetOn(true);
    }

    private void OnListenCameraBtnBtn(bool on)
    {
        if (on)
        {
            ListenVRCamera();
        }
        else
        {
            RemoteCameraWindowObj.SetActive(false);
        }
    }

    public void ListenVRCamera()
    {
        RemoteCameraWindowObj.SetActive(true);
        RemoteCameraWindowObj.GetComponent<RemoteCameraWindow>().StartListen(1920, 1920 / 2, 60, 20 * 1024 * 1024, 12345);
        // update shader parameters
        setLere.ResetRatios();
    }
    
    void UpdateShaderParams()
    {
        // default is vr's
        var visibleRatio = 0.555f;
        var contentRatio = 1.8f;
        switch (cameraDropdown.value)
        {
            case 0:
                // zed
                visibleRatio = 0.4394638240337372f;
                contentRatio = 1.7048496007919312f;
                break;
            default:
                break;
        }
        // Update
        setLere.UpdateRatios(visibleRatio, contentRatio);
    }
    
    public void ListenPCCamera()
    {
        RemoteCameraWindowObj.SetActive(true);
        RemoteCameraWindowObj.GetComponent<RemoteCameraWindow>().StartListen(2560, 720, 60, 4 * 1000 * 1000, 12345);
        // update shader parameters
        UpdateShaderParams();
    }

    private void OnRecordBtn(bool on)
    {
        if (on)
        {
            OpenRecord();
        }
        else
        {
            StopRecord();
        }
    }

    private void OpenRecord()
    {
        RecordDialog.Show(() =>
        {
            StartRecord(RecordDialog.ResolutionWidth, RecordDialog.ResolutionHeight,
                RecordDialog.Fps, RecordDialog.Bitrate, RecordDialog.RecordTrackingData);
        }, null);
    }

    private void StartRecord(int width, int height, int fps, int bitrate,
        bool onTrackingData)
    {
        //The VR camera image acquisition is only effective on the B-end device of Pico4U.
        if (!Utils.IsPico4U())
        {
            Toast.Show("Please use B-end pico4U devices and apply for camera permissions.");
            return;
        }

        Toast.Show("Start Record");
        Debug.Log("StartRecord:" + width + "," + height + "," + fps + "," + bitrate + "," + onTrackingData);
        CameraHandle.StartCameraPreview(width, height, fps, bitrate, 0,
            (int)PXRCaptureRenderMode.PXRCapture_RenderMode_3D,
            () =>
            {
                string timeStamp = DateTime.Now.ToString("yyyyMMdd_HHmmss");
                string trackingFileName = $"CameraRecord_{timeStamp}.mp4";
                string filePath = Path.Combine("/sdcard/Download/", trackingFileName);
                CameraHandle.StartRecord(filePath);
                _recordTrackingData = onTrackingData;
                if (_recordTrackingData)
                    OnStartRecordTracking(width, height);
            });

        RecordBtn.SetOn(true);
        // PreviewCameraTog.gameObject.SetActive(true);
    }

    public void UpdateCameraParamsNew()
    {
        ResolutionDialog.Show("Setting the resolution", (width, height) =>
        {
            string cameraIntrinsics = CameraHandle.GetCameraIntrinsics(width, height);
            string cameraExtrinsics = CameraHandle.GetCameraExtrinsics();

            string saveStr = "CameraExtrinsics:" + cameraExtrinsics + "\n";
            saveStr += "cameraIntrinsics:" + cameraIntrinsics;
            WriteLocalText(string.Format("cameraParams_{0}x{1}", width, height), saveStr);
            Toast.Show("Parameter saved successfully!");
        }, null);
    }

    private void WriteLocalText(string fileName, string content)
    {
        string parentPath = Application.persistentDataPath;
        string filePath = Path.Combine(parentPath, fileName + ".txt");
        using (StreamWriter writer = new StreamWriter(filePath, false))
        {
            writer.Write(content + "\n");
        }

        Debug.Log("The file has been successfully written: " + filePath);
    }

    private void StopRecord()
    {
        Debug.Log(this + "StopRecord");
        if (_writer != null)
        {
            _writer.Close();
            _writer = null;
        }

        CameraHandle.StopPreview();
        CameraHandle.CloseCamera();
        RecordBtn.SetOn(false);
    }

    private void StopSendImage()
    {
        CameraHandle.StopPreview();
        CameraHandle.CloseCamera();
        CameraSendToBtn.SetOn(false);
    }

    public void OnRemoteCameraBtn()
    {
        Toast.Show("Request  camera screen on PC!");
        //Request camera screen on PC
        TcpHandler.SendFunctionValue("requestCameraList", "");
    }

    private StreamWriter _writer;
    private bool _recordTrackingData = false;
    private JsonData _trackingJsonData = new JsonData();
    private TrackingData _trackingData = new TrackingData();

    private void OnStartRecordTracking(int width, int height)
    {
        Debug.Log("OnStartRecordTracking");
        string timeStamp = DateTime.Now.ToString("yyyyMMdd_HHmmss");
        string trackingFileName = $"trackingData_{timeStamp}.txt";
        string filePath = Path.Combine("/sdcard/Download/", trackingFileName);
        Debug.Log("trackingFilePath:" + filePath);
        _writer = new StreamWriter(filePath, true);
        _writer.AutoFlush = true; // Enable automatic refresh to prevent data loss

        JsonData cameraParam = new JsonData();
        long nsTime = Utils.GetCurrentTimestamp();
        cameraParam["notice"] =
            "This is the timestamp and head pose information when obtaining the image for the first frame.";
        cameraParam["timeStampNs"] = nsTime;
        //Convert coordinate system to right-handed system (X right, Y up, Z in)

        string cameraExtrinsics = CameraHandle.GetCameraExtrinsics();
        string cameraIntrinsics = CameraHandle.GetCameraIntrinsics(width, height);
        cameraParam["cameraExtrinsics"] = cameraExtrinsics;
        cameraParam["cameraIntrinsics"] = cameraIntrinsics;
        _writer.WriteLine(cameraParam.ToJson());
    }

    private void Update()
    {
        if (_recordTrackingData)
        {
            if (_writer != null)
            {
                _trackingData.Get(ref _trackingJsonData);
                _writer.WriteLine(_trackingJsonData.ToJson());
            }
        }
    }

    private void OnApplicationPause(bool pauseStatus)
    {
        if (CameraHandle.GetCaptureState() == (int)PXRCaptureState.CAPTURE_STATE_CAMERA_OPENING)
        {
            if (pauseStatus)
            {
                //release camera
                CameraHandle.CloseCamera();
            }
            else
            {
                //reopen camera
                CameraHandle.OpenCamera();
            }
        }
    }
}