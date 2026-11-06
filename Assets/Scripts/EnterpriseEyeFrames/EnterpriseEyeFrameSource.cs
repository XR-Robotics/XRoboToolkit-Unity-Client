using System;
using System.Runtime.InteropServices;
using System.Threading;
using UnityEngine;

namespace Robot
{
    public enum EnterpriseEyeCamera
    {
        TopLeft = 15,
        TopRight = 16,
        BottomLeft = 17,
        BottomRight = 18
    }

    public enum EnterpriseEyeFrameState
    {
        Waiting,
        Ready,
        Capturing,
        Stopped,
        Unavailable,
        Error
    }

    public readonly struct EnterpriseEyeFrame
    {
        public readonly EnterpriseEyeCamera Camera;
        public readonly int Width;
        public readonly int Height;
        public readonly long TimestampNanoseconds;
        // The buffer belongs to the source and is valid until the next frame for this camera.
        public readonly byte[] Gray8;

        public EnterpriseEyeFrame(EnterpriseEyeCamera camera, int width, int height, long timestamp, byte[] gray8)
        {
            Camera = camera;
            Width = width;
            Height = height;
            TimestampNanoseconds = timestamp;
            Gray8 = gray8;
        }
    }

    /// <summary>Polls bounded native frame leases and delivers images on Unity's main thread.</summary>
    public sealed class EnterpriseEyeFrameSource : MonoBehaviour
    {
        private const string Tag = "[EnterpriseEyeFrames]";
        private const float PreviewIntervalSeconds = 1f / 15f;
        private const int CameraCount = 4;
        private readonly byte[][] _pixels = new byte[CameraCount][];
        private readonly long[] _frameCounts = new long[CameraCount];
        private readonly long[] _windowFrameCounts = new long[CameraCount];
        private readonly long[] _lastTimestampsNs = new long[CameraCount];
        private volatile bool _serviceBound;
        private bool _observedServiceBound;
        private bool _paused;
        private bool _focused = true;
        private int _disconnectPending;
        private bool _backendAvailable;
        private bool _receivedFrame;
        private float _nextPreviewTime;
        private float _captureStartedAt;
        private float _statisticsStartedAt;

#if PICO_XR && UNITY_ANDROID && !UNITY_EDITOR
        private AndroidJavaObject _bridge;
#endif

        public EnterpriseEyeFrameState State { get; private set; } = EnterpriseEyeFrameState.Waiting;
        public string Status { get; private set; } = "Waiting for the enterprise service.";
        public bool CanStart => _backendAvailable && _serviceBound && !_paused && _focused &&
                                (State == EnterpriseEyeFrameState.Ready ||
                                 State == EnterpriseEyeFrameState.Stopped ||
                                 State == EnterpriseEyeFrameState.Error);

        public event Action<EnterpriseEyeFrame> FrameAvailable;
        public event Action<string> CaptureStopped;

        // The enterprise service callback may arrive outside Unity's main thread.
        public void NotifyServiceBound(bool bound)
        {
            if (!bound)
            {
                Interlocked.Exchange(ref _disconnectPending, 1);
            }
            _serviceBound = bound;
        }

        private void Awake()
        {
#if !(PICO_XR && UNITY_ANDROID && !UNITY_EDITOR)
            SetStatus(EnterpriseEyeFrameState.Unavailable,
                "Real EyeFrame capture requires an Android PICO device and the enterprise EyeFrame client API.");
#endif
        }

        private void Update()
        {
            ObserveServiceBinding();
#if PICO_XR && UNITY_ANDROID && !UNITY_EDITOR
            if (_bridge == null || Time.realtimeSinceStartup < _nextPreviewTime)
            {
                return;
            }
            _nextPreviewTime = Time.realtimeSinceStartup + PreviewIntervalSeconds;
            try
            {
                _bridge.Call("refresh");
                RefreshStatus();
                if (State != EnterpriseEyeFrameState.Capturing)
                {
                    return;
                }
                for (int i = 0; i < CameraCount; i++)
                {
                    ReadFrame((EnterpriseEyeCamera)((int)EnterpriseEyeCamera.TopLeft + i), i);
                }
                LogFrameStatistics();
            }
            catch (Exception error)
            {
                HandleBridgeFailure(error);
            }
#endif
        }

        private void ObserveServiceBinding()
        {
            bool bound = _serviceBound;
            bool disconnected = Interlocked.Exchange(ref _disconnectPending, 0) != 0;
            if (!disconnected && bound == _observedServiceBound)
            {
                return;
            }
            _observedServiceBound = bound;
#if PICO_XR && UNITY_ANDROID && !UNITY_EDITOR
            try
            {
                if (disconnected && _bridge != null)
                {
                    _backendAvailable = false;
                    _bridge.Call("serviceDisconnected");
                    RefreshStatus();
                }
                if (bound)
                {
                    if (_bridge == null)
                    {
                        _bridge = new AndroidJavaObject("com.xrobotoolkit.enterprise.EnterpriseEyeFrameBridge");
                    }
                    _backendAvailable = _bridge.Call<bool>("prepare");
                }
                else if (!disconnected && _bridge != null)
                {
                    _backendAvailable = false;
                    _bridge.Call("serviceDisconnected");
                }
                RefreshStatus();
            }
            catch (Exception error)
            {
                HandleBridgeFailure(error);
            }
#endif
        }

        public void StartCapture()
        {
            ObserveServiceBinding();
            if (!CanStart || !isActiveAndEnabled)
            {
                return;
            }
#if PICO_XR && UNITY_ANDROID && !UNITY_EDITOR
            try
            {
                _captureStartedAt = Time.realtimeSinceStartup;
                _statisticsStartedAt = _captureStartedAt;
                _receivedFrame = false;
                Array.Clear(_frameCounts, 0, CameraCount);
                Array.Clear(_windowFrameCounts, 0, CameraCount);
                Array.Clear(_lastTimestampsNs, 0, CameraCount);
                _nextPreviewTime = 0f;
                _bridge.Call<bool>("startCapture");
                RefreshStatus();
            }
            catch (Exception error)
            {
                HandleBridgeFailure(error);
            }
#endif
        }

        public void StopCapture(string reason)
        {
#if PICO_XR && UNITY_ANDROID && !UNITY_EDITOR
            if (_bridge != null && State != EnterpriseEyeFrameState.Unavailable)
            {
                try
                {
                    _bridge.Call("stopCapture", reason);
                    RefreshStatus();
                    _backendAvailable = _serviceBound &&
                        (State == EnterpriseEyeFrameState.Ready || State == EnterpriseEyeFrameState.Stopped);
                }
                catch (Exception error)
                {
                    SetStatus(EnterpriseEyeFrameState.Error, "EyeFrame Stop failed: " + error.Message);
                }
            }
#endif
            CaptureStopped?.Invoke(reason);
        }

#if PICO_XR && UNITY_ANDROID && !UNITY_EDITOR
        private unsafe void ReadFrame(EnterpriseEyeCamera camera, int index)
        {
            using (AndroidJavaObject nativeFrame = _bridge.Call<AndroidJavaObject>("acquireFrame", (int)camera))
            {
                if (nativeFrame == null)
                {
                    return;
                }
                try
                {
                    int width = nativeFrame.Call<int>("getWidth");
                    int height = nativeFrame.Call<int>("getHeight");
                    long timestamp = nativeFrame.Call<long>("getTimestamp");
                    long size = (long)width * height;
                    if (width <= 0 || height <= 0 || size > 1024 * 1024 || timestamp <= 0)
                    {
                        throw new InvalidOperationException("EyeFrame lease has invalid Gray8 dimensions.");
                    }
                    if (_pixels[index] == null || _pixels[index].Length != size)
                    {
                        _pixels[index] = new byte[(int)size];
                    }
                    using (AndroidJavaObject buffer = nativeFrame.Call<AndroidJavaObject>("getBuffer"))
                    {
                        IntPtr address = buffer == null ? IntPtr.Zero :
                            (IntPtr)AndroidJNI.GetDirectBufferAddress(buffer.GetRawObject());
                        if (address == IntPtr.Zero || AndroidJNI.GetDirectBufferCapacity(buffer.GetRawObject()) != size)
                        {
                            throw new InvalidOperationException("EyeFrame lease has an invalid direct buffer.");
                        }
                        // A leased direct buffer avoids a large JNI byte-array allocation on every frame.
                        Marshal.Copy(address, _pixels[index], 0, (int)size);
                    }
                    if (_frameCounts[index] == 0)
                    {
                        Debug.Log($"{Tag} first frame: camera={(int)camera}, size={width}x{height}, " +
                                  $"bytes={size}, timestampNs={timestamp}");
                    }
                    _receivedFrame = true;
                    _frameCounts[index]++;
                    _windowFrameCounts[index]++;
                    _lastTimestampsNs[index] = timestamp;
                    FrameAvailable?.Invoke(new EnterpriseEyeFrame(camera, width, height, timestamp, _pixels[index]));
                }
                finally
                {
                    nativeFrame.Call("release");
                }
            }
        }

        private void LogFrameStatistics()
        {
            float elapsed = Time.realtimeSinceStartup - _statisticsStartedAt;
            if (elapsed < 2f)
            {
                return;
            }
            for (int i = 0; i < CameraCount; i++)
            {
                int cameraId = (int)EnterpriseEyeCamera.TopLeft + i;
                Debug.Log($"{Tag} camera={cameraId}, previewFrames={_frameCounts[i]}, " +
                          $"previewHz={_windowFrameCounts[i] / elapsed:F1}, " +
                          $"lastTimestampNs={_lastTimestampsNs[i]}, bytes={_pixels[i]?.Length ?? 0}");
                _windowFrameCounts[i] = 0;
            }
            _statisticsStartedAt = Time.realtimeSinceStartup;
        }

        private void RefreshStatus()
        {
            if (_bridge == null)
            {
                return;
            }
            var state = (EnterpriseEyeFrameState)_bridge.Call<int>("getState");
            string message = _bridge.Call<string>("getStatus");
            if (state == EnterpriseEyeFrameState.Capturing)
            {
                if (_receivedFrame)
                {
                    message = "Receiving packed Gray8 EyeFrames. Preview refresh: up to 15 Hz per camera.";
                }
                else if (Time.realtimeSinceStartup - _captureStartedAt > 5f)
                {
                    message = "Capturing; no EyeFrame received after 5 seconds. Check device support and enableET.";
                }
            }
            SetStatus(state, message);
        }

        private void HandleBridgeFailure(Exception error)
        {
            StopCapture("bridge failure");
            _backendAvailable = false;
            if (_bridge != null)
            {
                _bridge.Dispose();
                _bridge = null;
            }
            SetStatus(EnterpriseEyeFrameState.Error, "EyeFrame bridge failed: " + error.Message);
        }
#endif

        private void SetStatus(EnterpriseEyeFrameState state, string message)
        {
            if (State == state && Status == message)
            {
                return;
            }
            bool stopped = State == EnterpriseEyeFrameState.Capturing && state != State;
            State = state;
            Status = message;
            Debug.Log($"{Tag} state={state}, {message}");
            if (stopped)
            {
                CaptureStopped?.Invoke(message);
            }
        }

        private void OnApplicationPause(bool paused)
        {
            _paused = paused;
            if (paused)
            {
                StopCapture("application paused");
            }
        }

        private void OnDisable()
        {
            StopCapture("component disabled");
        }

        private void OnApplicationFocus(bool focused)
        {
            _focused = focused;
            if (!focused)
            {
                StopCapture("application focus lost");
            }
        }

        private void OnDestroy()
        {
#if PICO_XR && UNITY_ANDROID && !UNITY_EDITOR
            if (_bridge != null)
            {
                try
                {
                    _bridge.Call("dispose");
                }
                catch (Exception error)
                {
                    Debug.LogWarning($"{Tag} dispose failed: {error.Message}");
                }
                _bridge.Dispose();
                _bridge = null;
            }
#endif
        }
    }
}
