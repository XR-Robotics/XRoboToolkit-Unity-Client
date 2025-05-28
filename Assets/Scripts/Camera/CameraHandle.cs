using System;
using UnityEngine;
using System.Threading.Tasks;

namespace Robot
{
    enum PXRCaptureState : int
    {
        CAPTURE_STATE_IDLE,
        CAPTURE_STATE_CAMERA_OPENING,
        CAPTURE_STATE_CAMERA_OPENED,
        CAPTURE_STATE_CONFIGURED,
        CAPTURE_STATE_PHOTO_CAPTURING,
        CAPTURE_STATE_VIDEO_CAPTURING,
        CAPTURE_STATE_VIDEO_PREVIEWING
    }

    public class CameraHandle : AndroidJavaProxy
    {
        private static int _width = 1280;
        private static int _height = 480;
        private static int _fps = 30;
        private static int _bitrate = 10 * 1024 * 1024;
        private static int _enableMvHevc = 0;
        private static int _captureRenderMode = 0;
        private static PXRCaptureState CaptureState;

        private Action OnCameraOpened;

        //  private Action OnConfigured;
        private event Action<int> OnStateChanged;
        private Action OnReset;

        private static CameraHandle _callbackProxy = new CameraHandle();

        public CameraHandle() : base("com.pxr.capturelib.PXRCameraCallBack")
        {
        }

        public void captureOnStateChanged(int state)
        {
            Debug.Log($"[PXRCapture] State Changed: {state}");
            UnityMainThreadDispatcher.Instance().Enqueue(() => { captureOnStateChangedInternal(state); });
        }

        private async void captureOnStateChangedInternal(int state)
        {
            await Task.Delay(10);
            CaptureState = (PXRCaptureState)state;
            Debug.Log($"captureOnStateChanged: {state}");
            switch (CaptureState)
            {
                case PXRCaptureState.CAPTURE_STATE_IDLE:
                    if (OnReset != null)
                    {
                        OnReset();
                    }

                    break;
                case PXRCaptureState.CAPTURE_STATE_CAMERA_OPENED:

                    Debug.Log($"[PXRCapture] Camera Opened ");
                    GetJavaObject().Call("SetConfig", _enableMvHevc, _fps);
                    break;

                case PXRCaptureState.CAPTURE_STATE_CONFIGURED:

                    Debug.Log($"[PXRCapture]  OnConfigured ");
                    GetJavaObject().Call<int>("StartPreview", _width, _height, _captureRenderMode);

                    break;
                case PXRCaptureState.CAPTURE_STATE_VIDEO_PREVIEWING:

                    Debug.Log($"[PXRCapture] OnPreviewing ");
                    if (OnCameraOpened != null)
                    {
                        OnCameraOpened();
                    }

                    break;
            }

            if (OnStateChanged != null)
            {
                OnStateChanged.Invoke(state);
            }
        }

        public void captureOnError(int errorCode)
        {
            Debug.LogError($"[PXRCapture] Error: {errorCode}");
        }

        public void captureOnEnviromentInfoChanged(int info1, int info2)
        {
            Debug.Log($"[PXRCapture] Environment Info Changed: {info1}, {info2}");
        }

        public void captureOnTakePictureComplete(float p1, float p2, float p3, float p4, float p5)
        {
            Debug.Log($"[PXRCapture] Picture Taken: {p1}, {p2}, {p3}, {p4}, {p5}");
        }

        public void captureOnTakePictureTimeOut()
        {
            Debug.LogWarning("[PXRCapture] Picture Capture Timed Out");
        }

        private static AndroidJavaObject _javaObj = null;

        private static AndroidJavaObject GetJavaObject()
        {
            if (_javaObj == null)
            {
                _javaObj = new AndroidJavaObject("com.picovr.robotassistantlib.CameraHandle");
            }

            return _javaObj;
        }

        public static int GetCaptureState()
        {
            return GetJavaObject().Call<int>("GetCaptureState");
        }

        public static int StartCameraPreview(int width, int height, int fps, int bitrate, int enableMvHevc,
            int renderMode, Action onCameraOpened)
        {
            _callbackProxy.OnCameraOpened = onCameraOpened;
            _width = width;
            _height = height;
            _fps = fps;
            _bitrate = bitrate;
            _enableMvHevc = enableMvHevc;
            _captureRenderMode = renderMode;
            return GetJavaObject().Call<int>("OpenCamera", _callbackProxy);
        }

        public static int OpenCamera()
        {
            return GetJavaObject().Call<int>("OpenCamera", _callbackProxy);
        }

        public static int StartRecord(string savePath)
        {
            return GetJavaObject().Call<int>("StartRecord", savePath);
        }

        public static int StartPreview(int width, int height, int renderMode, Action onPreviewing)
        {
            return GetJavaObject().Call<int>("StartPreview", width, height, renderMode);
        }

        public static void AddStateListener(Action<int> onStateChanged)
        {
            _callbackProxy.OnStateChanged += onStateChanged;
        }

        public static void RemoveStateListener(Action<int> onStateChanged)
        {
            _callbackProxy.OnStateChanged -= onStateChanged;
        }

        public static int StartSendImage(string ip, int port)
        {
            return GetJavaObject().Call<int>("StartSendImage", ip, port);
        }

        public static int StopPreview()
        {
            return GetJavaObject().Call<int>("StopPreview");
        }

        public static string GetCameraExtrinsics()
        {
            return GetJavaObject().Call<string>("getCameraExtrinsics");
        }

        public static string GetCameraIntrinsics(int width, int height)
        {
            return GetJavaObject().Call<string>("getCameraIntrinsics", width, height);
        }

        public static int CloseCamera()
        {
            return GetJavaObject().Call<int>("CloseCamera");
        }
    }
}