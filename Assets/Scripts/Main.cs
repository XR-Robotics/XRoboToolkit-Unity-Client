using Unity.XR.PICO.TOBSupport;
using Unity.XR.PXR;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.XR;
using Robot;

public class Main : MonoBehaviour
{
    // Pose collection does not require the VST camera.  Keep it opt-in because
    // the device-side VST/black-screen recovery path was the only path that
    // correlated with the multi-GB native memory climb in our logs.
    [SerializeField] private bool enableVstCamera = false;
    [SerializeField] private float eyeTextureResolutionScale = 1.0f;

    private bool _vstCameraOpen;

    private void Awake()
    {
        EnterpriseCollectionRecorder.EnsureCreated();
        DebugManager.instance.enableRuntimeUI = false;
        Application.logMessageReceived += OnLogMessageReceived;
        float clampedEyeTextureScale = Mathf.Clamp(eyeTextureResolutionScale, 0.7f, 1.0f);
        XRSettings.eyeTextureResolutionScale = clampedEyeTextureScale;
        PXR_Manager.EnableVideoSeeThrough = enableVstCamera;
        Debug.Log($"Main memory guard: VST={enableVstCamera}, eyeTextureResolutionScale={clampedEyeTextureScale:F2}");
        //Closing the security fence is only effective on B-end devices.
        PXR_Enterprise.SwitchSystemFunction(SystemFunctionSwitchEnum.SFS_SECURITY_ZONE_PERMANENTLY, SwitchEnum.S_OFF);
    }

    private void OnLogMessageReceived(string condition, string stackTrace, LogType type)
    {
        LogView.Push(condition, stackTrace, type);
        if (type == LogType.Error)
        {
            Toast.Show(condition);
        }
    }

    private void OnEnable()
    {
        SetVstCameraEnabled(enableVstCamera, "OnEnable");
    }

    private void OnDisable()
    {
        SetVstCameraEnabled(false, "OnDisable");
    }

    private void OnApplicationPause(bool pauseStatus)
    {
        Debug.Log("OnApplicationPause " + pauseStatus);
        if (pauseStatus)
        {
            SetVstCameraEnabled(false, "pause");
            PXR_Enterprise.SwitchSystemFunction(SystemFunctionSwitchEnum.SFS_SECURITY_ZONE_PERMANENTLY,
                SwitchEnum.S_ON);
        }
        else
        {
            //Closing the security fence is only effective on B-end devices.
            PXR_Enterprise.SwitchSystemFunction(SystemFunctionSwitchEnum.SFS_SECURITY_ZONE_PERMANENTLY,
                SwitchEnum.S_OFF);
            SetVstCameraEnabled(enableVstCamera, "resume");
        }
    }

    private void SetVstCameraEnabled(bool enabled, string reason)
    {
        if (Application.platform != RuntimePlatform.Android)
        {
            return;
        }

        if (enabled == _vstCameraOpen && PXR_Manager.EnableVideoSeeThrough == enabled)
        {
            Debug.Log($"Main VST unchanged: enabled={enabled}, reason={reason}");
            return;
        }

        if (enabled)
        {
            PXR_Manager.EnableVideoSeeThrough = true;
            bool openResult = PXR_Enterprise.OpenVSTCamera();
            _vstCameraOpen = openResult;
            Debug.Log($"Main VST open: result={openResult}, reason={reason}");
            return;
        }

        // Disable the compositor background before closing the camera so a
        // resume/black-screen transition cannot keep a stale VST layer alive.
        PXR_Manager.EnableVideoSeeThrough = false;
        bool closeResult = PXR_Enterprise.CloseVSTCamera();
        _vstCameraOpen = !closeResult;
        Debug.Log($"Main VST close: result={closeResult}, reason={reason}");
    }
}
