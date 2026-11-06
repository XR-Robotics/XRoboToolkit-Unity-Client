using System;
using System.Collections;
using System.Runtime.InteropServices;
using System.Threading;
using System.Threading.Tasks;
#if PICO_XR_NEW
using ByteDance.PICO.XR;
#elif PICO_XR_3
using Unity.XR.PXR;
#endif

using UnityEngine;

namespace ByteDance.PICO.CameraPack
{
    public delegate void CameraCallBack(int type);

    public readonly struct PXRCameraFrameSnapshot
    {
        public readonly long Timestamp;
        public readonly Vector2Int Resolution;
        public readonly Texture Texture;

        public PXRCameraFrameSnapshot(long timestamp, Vector2Int resolution, Texture texture)
        {
            Timestamp = timestamp;
            Resolution = resolution;
            Texture = texture;
        }
    }

    [Serializable]
    public class CameraAPI : MonoBehaviour
    {
        protected PXRCameraEye m_eye = PXRCameraEye.Left;
        protected int m_height = 0;
        protected int m_width = 0;
        protected int m_fps = 0;
        protected bool isOpened = false;
        protected PXRCameraStateCode m_State = PXRCameraStateCode.STATE_IDLE;
        protected CancellationTokenSource cancellationTokenSource; // Cancellation token source
        public PXRCameraStateCode GetState() => m_State;
        Int64 captureTime = 0;
        protected XrCameraImageDataRawBuffer imageData;
        protected readonly object imageDataLock = new object();
        public Action<int, int> OnFirstFrameReceived;
        protected bool _isFirstFrame = true;
        [SerializeField] private bool _enableVerboseFrameLogs = false;
        private byte[] imageDataBuffer;


        public virtual void OnCameraCreate()
        {
            PLog.CameraLog("CameraAPI", $"OnCameraCreate: Starting CallPluginAtEndOfFrames coroutine.");
            StopCoroutine("CallPluginAtEndOfFrames"); // Ensure only one runs
            StartCoroutine("CallPluginAtEndOfFrames");
        }

        public virtual bool GetSupportedState()
        {
            return false;
        }

        public virtual bool GetCameraImageResolution(PXRCameraEye eye, out Vector2Int[] resolutions)
        {
            resolutions = null;
            return false;
        }

        public virtual bool GetCameraImageFPS(PXRCameraEye eye, out PXRCameraFPS[] fps)
        {
            fps = null;
            return false;
        }

        protected Texture2D _targetTexture;

        public void SetTextureCameraFromUnity(Texture2D targetTexture, int width, int height)
        {
            // Parameter validation (texture must be valid)
            if (targetTexture == null)
            {
                Debug.LogError($"CameraAPI SetTextureCameraFromUnity: targetTexture = null");
                return;
            }

            _targetTexture = targetTexture;
            PLog.CameraLog("CameraAPI", $"SetTextureCameraFromUnity info: {width}x{height}, format: {targetTexture.format}");
        }

        public virtual Task<bool> OpenCameraAsync(PXRCameraEye eye, int width, int height, int fps)
        {
            PLog.CameraLog("CameraAPI", $"OpenCameraAsync: Camera {eye} requesting open, resolution {width}x{height}, fps {fps}");
            if (m_State == PXRCameraStateCode.STATE_CAMERA_OPENED ||
                m_State == PXRCameraStateCode.STATE_VIDEO_PREVIEWING)
            {
                Debug.LogError($"CameraAPI OpenCameraAsync: Camera {eye} is already running");
                return Task.FromResult(true);
            }

            m_eye = eye;
            m_width = width;
            m_height = height;
            m_fps = fps;
            _isFirstFrame = true;
            return Task.FromResult(false);
        }
        
        public virtual bool StartPreview()
        {
            if (m_State == PXRCameraStateCode.STATE_VIDEO_PREVIEWING)
            {
                Debug.LogError($"CameraAPI StartPreview: Camera {m_eye} preview is already running");
                return true;
            }

            if (m_State == PXRCameraStateCode.STATE_IDLE)
            {
                Debug.LogError($"CameraAPI StartPreview: Camera {m_eye} is not open");
                return true;
            }

            return false;
        }
       
        public virtual bool StopPreview()
        {
            if (m_State != PXRCameraStateCode.STATE_VIDEO_PREVIEWING)
            {
                Debug.LogError($"CameraAPI StopPreview: Camera {m_eye} preview is not running");
                return true;
            }

            CancelAndDisposeCancellationTokenSource();

            return false;
        }

        public virtual bool CloseCamera()
        {
            if (m_State == PXRCameraStateCode.STATE_VIDEO_PREVIEWING)
            {
                StopPreview();
            }
            else
            {
                CancelAndDisposeCancellationTokenSource();
            }

            return false;
        }

        protected void CancelAndDisposeCancellationTokenSource()
        {
            if (cancellationTokenSource == null)
            {
                return;
            }

            cancellationTokenSource.Cancel();
            cancellationTokenSource.Dispose();
            cancellationTokenSource = null;
        }


        public virtual double GetLatestTimestamp()
        {
            return captureTime;
        }

        public virtual bool TryGetLatestFrameSnapshot(out PXRCameraFrameSnapshot snapshot)
        {
            lock (imageDataLock)
            {
                snapshot = default;
                if (captureTime <= 0 || m_width <= 0 || m_height <= 0 || _targetTexture == null)
                {
                    return false;
                }

                snapshot = new PXRCameraFrameSnapshot(captureTime, new Vector2Int(m_width, m_height), _targetTexture);
                return true;
            }
        }

        public virtual bool TryCopyLatestFramePixels(Color32[] buffer, out PXRCameraFrameSnapshot snapshot)
        {
            lock (imageDataLock)
            {
                snapshot = default;
                if (!TryGetImageBufferLayout(out int bytesPerPixel, out int stride, out int bufferSize))
                {
                    return false;
                }

                snapshot = new PXRCameraFrameSnapshot(captureTime, new Vector2Int(m_width, m_height), _targetTexture);

                if (buffer == null)
                {
                    Debug.LogError("Color32 buffer is null");
                    return false;
                }

                int pixelCount = m_width * m_height;
                if (buffer.Length != pixelCount)
                {
                    Debug.LogError($"Color32 buffer length mismatch: actual {buffer.Length}, expected {pixelCount}");
                    return false;
                }

                if (!EnsureImageDataBuffer(bufferSize))
                {
                    return false;
                }

                Marshal.Copy(imageData.buffer, imageDataBuffer, 0, bufferSize);
                for (int y = 0; y < m_height; y++)
                {
                    int rowOffset = y * stride;
                    for (int x = 0; x < m_width; x++)
                    {
                        int pixelIndex = rowOffset + x * bytesPerPixel;
                        buffer[y * m_width + x] = ReadColor32(imageDataBuffer, pixelIndex, bytesPerPixel);
                    }
                }

                return true;
            }
        }

        public virtual bool GetPixels32(Color32[] color32)
        {
            return TryCopyLatestFramePixels(color32, out _);
        }

        public virtual Color GetPixel(int x, int y)
        {
            lock (imageDataLock)
            {
                if (!TryGetImageBufferLayout(out int bytesPerPixel, out int stride, out _))
                {
                    return Color.clear;
                }

                if (!TryGetPixelIndex(x, y, bytesPerPixel, stride, out int pixelIndex))
                {
                    return Color.clear;
                }

                byte r = Marshal.ReadByte(imageData.buffer, pixelIndex);
                byte g = Marshal.ReadByte(imageData.buffer, pixelIndex + 1);
                byte b = Marshal.ReadByte(imageData.buffer, pixelIndex + 2);
                byte a = bytesPerPixel > 3
                    ? Marshal.ReadByte(imageData.buffer, pixelIndex + 3)
                    : (byte)255;

                return new Color32(r, g, b, a);
            }
        }

        private bool EnsureImageDataBuffer(int bufferSize)
        {
            if (bufferSize <= 0)
            {
                Debug.LogError($"Invalid image buffer size: {bufferSize}");
                return false;
            }

            if (imageDataBuffer == null || imageDataBuffer.Length != bufferSize)
            {
                imageDataBuffer = new byte[bufferSize];
            }

            return true;
        }

        private bool TryGetImageBufferLayout(out int bytesPerPixel, out int stride, out int bufferSize)
        {
            bytesPerPixel = (int)imageData.bytesPerPixel;
            stride = (int)imageData.stride;
            bufferSize = (int)imageData.bufferSize;

            if (imageData.buffer == IntPtr.Zero)
            {
                Debug.LogError("Buffer pointer is null");
                return false;
            }

            if (m_width <= 0 || m_height <= 0)
            {
                Debug.LogError($"Invalid image dimensions: {m_width}x{m_height}");
                return false;
            }

            if (bytesPerPixel <= 0)
            {
                bytesPerPixel = 4;
            }

            if (bytesPerPixel < 3)
            {
                Debug.LogError($"Unsupported image bytes per pixel: {bytesPerPixel}");
                return false;
            }

            if (stride <= 0)
            {
                stride = m_width * bytesPerPixel;
            }

            int requiredBytes = (m_height - 1) * stride + m_width * bytesPerPixel;
            if (bufferSize < requiredBytes)
            {
                Debug.LogError($"Image buffer size mismatch: actual {bufferSize}, expected at least {requiredBytes}");
                return false;
            }

            return true;
        }

        private bool TryGetPixelIndex(int x, int y, int bytesPerPixel, int stride, out int pixelIndex)
        {
            pixelIndex = 0;
            if (x < 0 || x >= m_width || y < 0 || y >= m_height)
            {
                Debug.LogError($"Coordinates ({x},{y}) out of image bounds (Width: {m_width}, Height: {m_height})");
                return false;
            }

            pixelIndex = y * stride + x * bytesPerPixel;
            return true;
        }

        private static Color32 ReadColor32(byte[] buffer, int pixelIndex, int bytesPerPixel)
        {
            return new Color32(
                buffer[pixelIndex],
                buffer[pixelIndex + 1],
                buffer[pixelIndex + 2],
                bytesPerPixel > 3 ? buffer[pixelIndex + 3] : (byte)255);
        }

        public PxrSensorState2 GetPredictedMainSensorState2(double predictTime)
        {
            PxrSensorState2 sensorState2 = new PxrSensorState2();
            int sensorFrameIndex = 0;
            PXR_Plugin.Pxr_GetPredictedMainSensorState2(predictTime, ref sensorState2, ref sensorFrameIndex);
            return sensorState2;
        }

        private void LogVerboseFrame(string message)
        {
            if (!_enableVerboseFrameLogs)
            {
                return;
            }

            PLog.CameraLog("CameraAPI", message);
        }

        private IEnumerator CallPluginAtEndOfFrames()
        {
            PLog.CameraLog("CameraAPI", "CallPluginAtEndOfFrames started.");
            ulong imageId = 0;
            while (true)
            {
                yield return new WaitForEndOfFrame();
                lock (imageDataLock)
                {
                    bool shouldReleaseImage = false;
                    try
                    {
                        bool acquireResult = AcquireCameraImage(m_eye, out imageId, out captureTime);

                        if (acquireResult && imageId > 0)
                        {
                            shouldReleaseImage = true;
                            LogVerboseFrame($"CameraAPI: Acquired image {imageId}, captureTime {captureTime}");
                            if (GetCameraImageData(m_eye, imageId, out imageData))
                            {
                                if (_isFirstFrame)
                                {
                                    PLog.CameraLog("CameraAPI",
                                        $"CameraAPI: First frame received rsl: {imageData.width}*{imageData.height},before rsl {m_width}*{m_height}");
                                    _isFirstFrame = false;
                                    m_width = (int)imageData.width;
                                    m_height = (int)imageData.height;
                                    OnFirstFrameReceived?.Invoke(m_width, m_height);
                                }

                                if (_targetTexture != null)
                                {
                                    _targetTexture.LoadRawTextureData(imageData.buffer, (int)imageData.bufferSize);
                                    _targetTexture.Apply();
                                }
                            }
                            else
                            {
                                PLog.CameraLog("CameraAPI", $"CameraAPI: Failed to get image data for imageId {imageId}");
                            }
                        }
                        else if (acquireResult)
                        {
                            LogVerboseFrame("CameraAPI: Acquired image but ID is 0");
                        }
                    }
                    finally
                    {
                        if (shouldReleaseImage)
                        {
                            ReleaseCameraImage(m_eye, imageId);
                            imageId = 0;
                        }
                    }
                }
            }
        }

        public virtual bool AcquireCameraImage(PXRCameraEye eye, out ulong imageId, out Int64 captureTime)
        {
            imageId = 0;
            captureTime = 0;
            return false;
        }

        public virtual bool GetCameraImageData(PXRCameraEye deviceId, ulong imageId,
            out XrCameraImageDataRawBuffer rawBufferData)
        {
            rawBufferData = new XrCameraImageDataRawBuffer();
            return false;
        }

        public virtual bool ReleaseCameraImage(PXRCameraEye deviceId, ulong imageId)
        {
            return false;
        }

        public virtual bool GetCameraIntrinsics(PXRCameraEye cameraId, out CameraIntrinsics intrinsics)
        {
            intrinsics = new CameraIntrinsics();
            return false;
        }


        public virtual bool GetCameraExtrinsics(PXRCameraEye cameraId, out CameraExtrinsics extrinsics)
        {
            extrinsics = new CameraExtrinsics();
            return false;
        }

        public Color GetColorFromRGBAByteArray(byte[] byteArray, int width, int height, int x, int y)
        {
            // Validate parameters
            if (byteArray == null || byteArray.Length == 0)
            {
                Debug.LogError("Byte array is null or empty");
                return Color.clear;
            }

            if (x < 0 || x >= width || y < 0 || y >= height)
            {
                Debug.LogError($"Coordinates ({x},{y}) out of image bounds (Width: {width}, Height: {height})");
                return Color.clear;
            }

            int requiredLength = width * height * 4;
            if (byteArray.Length != requiredLength)
            {
                Debug.LogError($"Byte array length mismatch: actual {byteArray.Length}, expected {requiredLength} (RGBA8888 format)");
                return Color.clear;
            }

            int pixelIndex = (y * width + x) * 4;

            byte r = byteArray[pixelIndex];
            byte g = byteArray[pixelIndex + 1];
            byte b = byteArray[pixelIndex + 2];
            byte a = byteArray[pixelIndex + 3];

            PLog.CameraLog("CameraAPI", $"GetColorFromRGBAByteArray Pixel ({x},{y}) Color: R={r}, G={g}, B={b}, A={a}");
            return new Color(r / 255f, g / 255f, b / 255f, a / 255f);
        }

        public virtual void OnApplicationPause(bool pauseStatus)
        {
        }

        private void OnDestroy()
        {
            StopAllCoroutines();
        }
    }

    public enum PXRCameraEye
    {
        Left,
        Right
    }

    public enum PXRCameraFPS
    {
        FPS15 = 15,
        FPS30 = 30,
        FPS45 = 45,
        FPS60 = 60
    }

    public enum PXRCameraStateCode
    {
        STATE_IDLE = 0, // Initial state
        STATE_CAMERA_OPENED, // Camera opened
        STATE_VIDEO_PREVIEWING, // Entering preview state
    }

    public struct CameraIntrinsics
    {
        /// <summary>
        /// Focal length in pixels (horizontal/vertical)
        /// </summary>
        public Vector2 FocalLength;

        /// <summary>
        /// Principal point coordinates (optical center on image plane, unit: pixels)
        /// </summary>
        public Vector2 CornerPoint;

        /// <summary>
        /// Image resolution (width/height)
        /// </summary>
        public Vector2 Resolution;

        /// <summary>
        /// Field of view angles (horizontal/vertical)
        /// </summary>
        public Vector2 Fov;
    }

    public struct CameraExtrinsics
    {
        public Vector3 CameraPos;
        public Quaternion CameraRot;
    }
}
