using System.Collections;
using System.Collections.Generic;
using System.Net;
using System.Net.NetworkInformation;
using Robot;
using Robot.Conf;
using Unity.XR.PICO.TOBSupport;
using Unity.XR.PXR;
using UnityEngine;
using UnityEngine.Android;
using UnityEngine.InputSystem;
using UnityEngine.Serialization;
using UnityEngine.UI;

public class UIOperate : MonoBehaviour
{
    private const string UsbTetheringLocalAddress = "192.168.10.30";
    private const string UsbTetheringClientAddress = "192.168.10.40";
    private const float AutoConnectRetrySeconds = 2.0f;
    private const float UsbTetheringStatusIntervalSeconds = 3.0f;

    public Text SN;
    public Text LocalIP;
    public Text TargetIP;
    public Text TrackNum;
    public Toggle HeadTog;
    public Toggle ControllerTog;
    public Toggle HandTrackingTog;
    public Toggle SendTog;
    public Toggle AcontrolerTog;
    public Dropdown bodyModeDrop;
    public TcpHandler TcpHandler;
    public Text BodyInfo;
    public Toggle HighAccuracy;
    public Text Version;
    public Button ReconnectBtn;
    public Toggle NetshareTog;

    public GameObject Simulator;
    public GameObject CameraObj;
    public GameObject IpInputDialog;
    public GameObject ExtDevPanel;
    public InputActionProperty SendDataAction;

    [Space(30)] [Header("Refactoring")] public VideoSourceManager videoSource;
    public VideoSourceConfigManager sourceConfig => videoSource.videoSourceConfigManager;

    public Dropdown videoSourceDropdown;

    private bool _enterpriseServiceBound;
    private bool _usbNetworkingConfigured;
    private bool _usbNetworkingConfigurationInProgress;
    private bool _usbTetheringRecoveryInProgress;
    private float _nextAutoConnectTime;
    private float _nextUsbTetheringStatusTime;

    // Start is called before the first frame update
    private void Awake()
    {
#if UNITY_EDITOR
        if (Simulator != null)
        {
            Simulator.SetActive(true);
        }
#endif
        // ReconnectBtn.gameObject.SetActive(false);

        bodyModeDrop.onValueChanged.AddListener(OnBodyModeDrop);
        HeadTog.onValueChanged.AddListener(OnHeadTog);
        ControllerTog.onValueChanged.AddListener(OnControllerTog);
        HandTrackingTog.onValueChanged.AddListener(OnHandTrackingTog);

        SendTog.onValueChanged.AddListener(OnSendTog);
        Version.text = "v: " + Application.version;
        HighAccuracy.gameObject.SetActive(bodyModeDrop.value > 0);
        NetshareTog.onValueChanged.AddListener(OnNetShareTog);
        HighAccuracy.onValueChanged.AddListener(OnHighAccuracy);
        ReconnectBtn.onClick.AddListener(OnReconnectBtn);
        EnableCollectionStreams();
        //The shared network function is only available on B-end devices.
        NetshareTog.gameObject.SetActive(false);
        // Bypass getting sn via enterprise service to enable data transport
        SetDeviceSN("TestDevice");
        bool intEnterprise = PXR_Enterprise.InitEnterpriseService();
        Debug.Log("---InitEnterpriseService :" + intEnterprise);
        PXR_Enterprise.BindEnterpriseService(OnBindEnterpriseService);

        // if (CameraObj != null)
        // {
        //     CameraObj.SetActive(false);
        // }

        AndroidProxy.CallBack += OnAndroidCallBack;
#if UNITY_EDITOR
        SetDeviceSN("TestDevice");
#endif
        // Refactoring
        sourceConfig.OnInitialized += OnSourceConfigOnOnInitialized;
        // Initialize video source configuration
        sourceConfig.Initialize();
    }

    private void OnSourceConfigOnOnInitialized()
    {
        // Update videoSourceDropdown options
        print("OnSourceConfigOnOnInitialized");
        videoSourceDropdown.ClearOptions();
        videoSourceDropdown.AddOptions(sourceConfig.GetVideoSourceNames());
    }

    private void OnAndroidCallBack(string key, string value)
    {
        if (key == "RequestPermissionsBack")
        {
            if (value == "0")
            {
                if (CameraObj != null)
                {
                    CameraObj.SetActive(true);
                }
            }
            else
            {
                Toast.Show("Permission denied!");
            }
        }
    }

    private void OnReconnectBtn()
    {
        TcpHandler.Reconnect();
    }

    public void TcpConnect(string ip)
    {
        TargetIP.text = "PC Service: " + ip;
        ReconnectBtn.gameObject.SetActive(true);
        if (ip == UsbTetheringClientAddress)
        {
            TcpHandler.Connect(ip, UsbTetheringLocalAddress);
        }
        else
        {
            TcpHandler.Connect(ip);
        }
        ConnectSuccess();
    }

    public void ConnectSuccess()
    {
        TargetIP.text = "PC Service: " + TcpHandler.GetTargetIP;
    }

    private void OnBindEnterpriseService(bool bind)
    {
        Debug.Log("OnBindEnterpriseService " + bind);
        _enterpriseServiceBound = bind;
        EnterpriseCollectionRecorder.NotifyEnterpriseServiceBound(bind);
        if (bind && !_usbNetworkingConfigured)
        {
            _usbNetworkingConfigured = true;
            //The shared network function is only available on B-end devices.
            NetshareTog.gameObject.SetActive(true);
            _nextUsbTetheringStatusTime =
                Time.realtimeSinceStartup + UsbTetheringStatusIntervalSeconds;
            StartCoroutine(ConfigureUsbNetworking());

            string sn = PXR_Enterprise.StateGetDeviceInfo(SystemInfoEnum.EQUIPMENT_SN);
            SetDeviceSN(sn);
        }
    }

    private IEnumerator ConfigureUsbNetworking()
    {
        _usbNetworkingConfigurationInProgress = true;
        string currentLocal = PXR_Enterprise.GetUsbTetheringStaticIPLocal();
        string currentClient = PXR_Enterprise.GetUsbTetheringStaticIPClient();
        bool addressesChanged = currentLocal != UsbTetheringLocalAddress ||
                                currentClient != UsbTetheringClientAddress;

        Debug.Log($"USB tethering static IP before: local={currentLocal}, client={currentClient}");
        int result = PXR_Enterprise.SetUsbTetheringStaticIP(
            UsbTetheringLocalAddress, UsbTetheringClientAddress);
        Debug.Log($"SetUsbTetheringStaticIP result={result}, addressesChanged={addressesChanged}");
        if (result != 0 && addressesChanged)
        {
            LogWindow.Error($"USB static IP configuration failed: result={result}");
            _usbNetworkingConfigurationInProgress = false;
            yield break;
        }
        if (result != 0)
        {
            Debug.LogWarning(
                $"USB static IP setter returned {result}, but the configured addresses already match.");
        }

        PXR_Enterprise.EnableUsbTetheringStaticIP();
        PXR_Enterprise.SwitchSystemFunction(
            SystemFunctionSwitchEnum.SFS_USB_TETHERING, SwitchEnum.S_OFF);
        yield return new WaitForSecondsRealtime(1.0f);
        PXR_Enterprise.SwitchSystemFunction(
            SystemFunctionSwitchEnum.SFS_USB_TETHERING, SwitchEnum.S_ON);
        NetshareTog.SetIsOnWithoutNotify(true);
        _nextAutoConnectTime = 0.0f;
        _nextUsbTetheringStatusTime =
            Time.realtimeSinceStartup + UsbTetheringStatusIntervalSeconds;
        _usbNetworkingConfigurationInProgress = false;
        Debug.Log($"USB tethering configured: local={UsbTetheringLocalAddress}, client={UsbTetheringClientAddress}");
    }

    private void EnsureUsbTetheringEnabled()
    {
        if (!_enterpriseServiceBound || _usbTetheringRecoveryInProgress ||
            Time.realtimeSinceStartup < _nextUsbTetheringStatusTime)
        {
            return;
        }

        _nextUsbTetheringStatusTime =
            Time.realtimeSinceStartup + UsbTetheringStatusIntervalSeconds;
        if (HasLocalIPv4Address(UsbTetheringLocalAddress))
        {
            return;
        }

        StartCoroutine(RestartUsbTetheringForRecovery());
    }

    private IEnumerator RestartUsbTetheringForRecovery()
    {
        _usbTetheringRecoveryInProgress = true;
        Debug.LogWarning($"USB address {UsbTetheringLocalAddress} is missing; restarting USB tethering.");
        PXR_Enterprise.EnableUsbTetheringStaticIP();
        PXR_Enterprise.SwitchSystemFunction(
            SystemFunctionSwitchEnum.SFS_USB_TETHERING, SwitchEnum.S_OFF);
        yield return new WaitForSecondsRealtime(0.5f);
        PXR_Enterprise.SwitchSystemFunction(
            SystemFunctionSwitchEnum.SFS_USB_TETHERING, SwitchEnum.S_ON);
        yield return new WaitForSecondsRealtime(1.0f);
        _usbTetheringRecoveryInProgress = false;
    }

    private static bool HasLocalIPv4Address(string expectedAddress)
    {
        foreach (NetworkInterface networkInterface in NetworkInterface.GetAllNetworkInterfaces())
        {
            foreach (UnicastIPAddressInformation addressInfo in
                     networkInterface.GetIPProperties().UnicastAddresses)
            {
                IPAddress address = addressInfo.Address;
                if (address.AddressFamily == System.Net.Sockets.AddressFamily.InterNetwork &&
                    address.ToString() == expectedAddress)
                {
                    return true;
                }
            }
        }

        return false;
    }

    private void EnableCollectionStreams()
    {
        TrackingData.SetHeadOn(true);
        TrackingData.SetControllerOn(true);
        TcpHandler.SendTrackingData = true;
        HeadTog.SetIsOnWithoutNotify(true);
        ControllerTog.SetIsOnWithoutNotify(true);
        SendTog.SetIsOnWithoutNotify(true);
    }

    private void EnsureUsbTcpConnected()
    {
        if (!_enterpriseServiceBound || _usbNetworkingConfigurationInProgress ||
            _usbTetheringRecoveryInProgress || TcpHandler == null)
        {
            return;
        }

        if (!HasLocalIPv4Address(UsbTetheringLocalAddress))
        {
            return;
        }

        bool configuredForUsb = TcpHandler.GetTargetIP == UsbTetheringClientAddress &&
                                TcpHandler.GetSourceIP == UsbTetheringLocalAddress;
        if (configuredForUsb &&
            (TcpHandler.State == SocketState.WORKING ||
             TcpHandler.State == SocketState.CONNECTING))
        {
            return;
        }
        if (Time.realtimeSinceStartup < _nextAutoConnectTime)
        {
            return;
        }

        _nextAutoConnectTime = Time.realtimeSinceStartup + AutoConnectRetrySeconds;
        if (TcpHandler.State == SocketState.WORKING || TcpHandler.State == SocketState.CONNECTING)
        {
            Debug.LogWarning(
                $"Replacing non-USB TCP route: source={TcpHandler.GetSourceIP}, " +
                $"target={TcpHandler.GetTargetIP}");
        }
        Debug.Log($"USB auto-connect: {UsbTetheringClientAddress}:{Robot.TcpHandler.TCP_PORT}");
        TcpConnect(UsbTetheringClientAddress);
    }

    private void SetDeviceSN(string sn)
    {
        TcpHandler.SetDeviceSn(sn);
        Debug.Log("SN: " + sn);
        SN.text = "SN: " + sn;
    }

    private void OnNetShareTog(bool ison)
    {
        Debug.Log("OnNetShareTog:" + ison);
        if (ison)
            PXR_Enterprise.SwitchSystemFunction(SystemFunctionSwitchEnum.SFS_USB_TETHERING, SwitchEnum.S_ON);
        else
            PXR_Enterprise.SwitchSystemFunction(SystemFunctionSwitchEnum.SFS_USB_TETHERING, SwitchEnum.S_OFF);

        PXR_Enterprise.GetSwitchSystemFunctionStatus(SystemFunctionSwitchEnum.SFS_USB_TETHERING,
            (value) => { Debug.Log("SFS_USB_TETHERING:" + value); });
    }

    public void OnQuit()
    {
        Application.Quit();
    }

    public void OnExtraDevBtn()
    {
        ExtDevPanel.SetActive(true);
    }

    public void OnWriteIpBtn()
    {
        IpInputDialog.SetActive(true);
    }

    private void OnBodyModeDrop(int index)
    {
        TrackingData.TrackingType tType = (TrackingData.TrackingType)bodyModeDrop.value;
        int res = 0;
        bool support = false;

        MotionTrackerMode trackingMode = PXR_MotionTracking.GetMotionTrackerMode();
        if (tType == TrackingData.TrackingType.Body)
        {
            if (trackingMode != MotionTrackerMode.BodyTracking)
            {
                res = PXR_MotionTracking.CheckMotionTrackerModeAndNumber(MotionTrackerMode.BodyTracking,
                    MotionTrackerNum.TWO);
            }

            PXR_MotionTracking.GetBodyTrackingSupported(ref support);
        }
        else if (tType == TrackingData.TrackingType.Motion)
        {
            if (trackingMode != MotionTrackerMode.MotionTracking)
            {
                res = PXR_MotionTracking.CheckMotionTrackerModeAndNumber(MotionTrackerMode.MotionTracking,
                    MotionTrackerNum.ONE);
            }

            support = true;
        }

        if (!support || res != 0)
        {
            BodyInfo.text = "Tracker exception, please connect to calibrate tracker!";
            BodyInfo.color = Color.red;

            bodyModeDrop.SetValueWithoutNotify(0);
            // Update UI
            HighAccuracy.gameObject.SetActive(false);
            return;
        }
        
        // Update UI
        HighAccuracy.gameObject.SetActive(index > 0);

        BodyInfo.color = Color.white;
        BodyInfo.text = "Tracker detection is normal!";

        UpdateBodyTracking();
    }


    public void OnOpenCameraOperate()
    {
        if (CameraObj != null)
        {
            if (Permission.HasUserAuthorizedPermission(Permission.Camera) &&
                Permission.HasUserAuthorizedPermission(Permission.Microphone))
            {
                CameraObj.SetActive(!CameraObj.activeSelf);
            }
            else if (!CameraObj.activeSelf)
            {
                var permissionCallbacks = new PermissionCallbacks();
                permissionCallbacks.PermissionGranted += PermissionGranted;
                permissionCallbacks.PermissionDenied += PermissionDenied;

                string[] permissions = { Permission.Camera, Permission.Microphone };
                Permission.RequestUserPermissions(permissions, permissionCallbacks);
            }

            if (!Permission.HasUserAuthorizedPermission(Permission.ExternalStorageRead))
            {
                Permission.RequestUserPermission(Permission.ExternalStorageRead);
            }

            if (!Permission.HasUserAuthorizedPermission(Permission.ExternalStorageWrite))
            {
                Permission.RequestUserPermission(Permission.ExternalStorageWrite);
            }
        }
    }

    private void PermissionDenied(string obj)
    {
        Toast.Show("Permission denied!");
    }

    private void PermissionGranted(string obj)
    {
        if (CameraObj != null)
        {
            CameraObj.SetActive(true);
        }
    }

    private void RefreshLocalIP()
    {
        string localIP = Utils.GetLocalIPv4();
        LocalIP.text = localIP;
    }

    // Obtain the local IPv6 address
    private string GetLocalIPv6()
    {
        string localIP = "Not found";
        foreach (IPAddress ip in Dns.GetHostAddresses(Dns.GetHostName()))
        {
            if (ip.AddressFamily == System.Net.Sockets.AddressFamily.InterNetworkV6)
            {
                localIP = ip.ToString();
                break;
            }
        }

        return localIP;
    }


    private void OnHeadTog(bool on)
    {
        TrackingData.SetHeadOn(on);
        LogWindow.Info($"Tracking Head toggled: {on}");
    }

    private void OnControllerTog(bool on)
    {
        TrackingData.SetControllerOn(on);
        LogWindow.Info($"Tracking Controller toggled: {on}");
    }

    private void OnHandTrackingTog(bool on)
    {
        TrackingData.SetHandTrackingOn(on);
    }

    private void OnSendTog(bool on)
    {
        TcpHandler.SendTrackingData = on;
        // Reset FPS
        if (!on)
        {
            FPSDisplay.Reset();
        }
    }

    private void OnHighAccuracy(bool on)
    {
        UpdateBodyTracking();
    }

    private void UpdateBodyTracking()
    {
        TrackingData.TrackingType tType = (TrackingData.TrackingType)bodyModeDrop.value;
        HighAccuracy.gameObject.SetActive(bodyModeDrop.value > 0);
        Debug.Log("UpdateBodyTracking " + tType);
        TrackNum.text = "";
        // Set bone length
        BodyTrackingBoneLength boneLength = new BodyTrackingBoneLength();
        if (bodyModeDrop.value <= 0)
        {
            int ret = PXR_MotionTracking.StopBodyTracking();
            BodyInfo.text = "BodyTracking close";
        }
        else
        {
            MotionTrackerConnectState state = new MotionTrackerConnectState();
            PXR_MotionTracking.GetMotionTrackerConnectStateWithSN(ref state);
            //  PXR_MotionTracking.GetMotionTrackerConnectStateWithSN(ref state);
            TrackNum.text = "Num: " + state.trackerSum;

            if (tType == TrackingData.TrackingType.Body)
            {
                BodyTrackingMode mode = BodyTrackingMode.BTM_FULL_BODY_LOW;
                if (HighAccuracy.isOn)
                {
                    mode = BodyTrackingMode.BTM_FULL_BODY_HIGH;
                }

                // Enable full body motion capture default mode
                int ret = PXR_MotionTracking.StartBodyTracking(mode, boneLength);
                BodyInfo.text = "Start BodyTracking " + ret;
                Debug.Log(" UpdateBodyTracking :" + ret + " trackerSum:" + state.trackerSum);
            }
            else if (tType == TrackingData.TrackingType.Motion)
            {
                BodyInfo.text = "Start MotionTracking";
            }
        }

        TrackingData.SetTrackingType(tType);
    }

    private float _lastTime = 0;

    // Update is called once per frame
    void Update()
    {
        EnableCollectionStreams();
        EnsureUsbTetheringEnabled();
        EnsureUsbTcpConnected();

        if (TcpHandler.State != SocketState.WORKING)
        {
            if (Time.time - _lastTime > 2)
            {
                _lastTime = Time.time;
                RefreshLocalIP();
            }
        }

        if (AcontrolerTog != null && AcontrolerTog.isOn)
        {
            if (SendDataAction.action != null && SendDataAction.action.WasReleasedThisFrame())
            {
                SendTog.isOn = !SendTog.isOn;
                LogWindow.Info("Sending data: " + SendTog.isOn);
            }
        }
    }

    public void OnQuitBtn()
    {
        Application.Quit();
    }
}
