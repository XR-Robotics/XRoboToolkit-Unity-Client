using System;
using System.Collections.Generic;
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
    public class OpenxrCameraAPI : CameraAPI
    {
        private XrCameraIdPICO activeCamera = XrCameraIdPICO.XR_CAMERA_ID_RGB_LEFT_PICO;
        XrCameraIdPICO[] availableCameras;
        private bool isDeviceCreated;
        private bool isCaptureSessionCreated;
        private bool isCaptureStarted;
        private Int64 lastCaptureTime;
        private int cameraLifecycleGeneration;
        private bool hasActiveOpenConfiguration;
        private PXRCameraEye activeOpenEye = PXRCameraEye.Left;
        private int activeOpenWidth;
        private int activeOpenHeight;
        private int activeOpenFps;
        private static long nextLifecycleOwnerToken;
        private readonly object lifecycleOwnersLock = new object();
        private readonly Dictionary<ulong, XrCameraIdPICO> lifecycleOwners =
            new Dictionary<ulong, XrCameraIdPICO>();
        private ulong activeLifecycleOwnerToken;
        private bool isLifecycleClosing;

        private static ulong CreateLifecycleOwnerToken()
        {
            return (ulong)Interlocked.Increment(ref nextLifecycleOwnerToken);
        }

        private bool TryRegisterLifecycleOwner(ulong ownerToken, XrCameraIdPICO cameraId)
        {
            lock (lifecycleOwnersLock)
            {
                if (isLifecycleClosing)
                {
                    return false;
                }

                lifecycleOwners[ownerToken] = cameraId;
                return true;
            }
        }

        private void SetLifecycleClosing(bool isClosing)
        {
            lock (lifecycleOwnersLock)
            {
                isLifecycleClosing = isClosing;
            }
        }

        private void UnregisterLifecycleOwner(ulong ownerToken)
        {
            lock (lifecycleOwnersLock)
            {
                lifecycleOwners.Remove(ownerToken);
            }
        }

        private KeyValuePair<ulong, XrCameraIdPICO>[] GetLifecycleOwnersSnapshot()
        {
            lock (lifecycleOwnersLock)
            {
                var owners = new KeyValuePair<ulong, XrCameraIdPICO>[lifecycleOwners.Count];
                int index = 0;
                foreach (var owner in lifecycleOwners)
                {
                    owners[index++] = owner;
                }
                return owners;
            }
        }

        private int InvalidateCameraOpenGeneration()
        {
            CancelAndDisposeCancellationTokenSource();
            cameraLifecycleGeneration++;
            return cameraLifecycleGeneration;
        }

        private CancellationToken CreateOpenCancellationToken()
        {
            cancellationTokenSource = new CancellationTokenSource();
            return cancellationTokenSource.Token;
        }

        private bool IsCurrentCameraOpenGeneration(int openGeneration)
        {
            return openGeneration == cameraLifecycleGeneration;
        }

        private bool IsActiveOpenConfiguration(PXRCameraEye eye, int width, int height, int fps)
        {
            return hasActiveOpenConfiguration &&
                   activeOpenEye == eye &&
                   activeOpenWidth == width &&
                   activeOpenHeight == height &&
                   activeOpenFps == fps;
        }

        private void SetActiveOpenConfiguration(PXRCameraEye eye, int width, int height, int fps)
        {
            activeOpenEye = eye;
            activeOpenWidth = width;
            activeOpenHeight = height;
            activeOpenFps = fps;
            hasActiveOpenConfiguration = true;
        }

        private void ClearActiveOpenConfiguration()
        {
            hasActiveOpenConfiguration = false;
            activeOpenWidth = 0;
            activeOpenHeight = 0;
            activeOpenFps = 0;
        }

        public override bool GetSupportedState()
        {
            base.GetSupportedState();
            PxrResult ret = PXR_CameraImage.GetAvailableCameras(out availableCameras);
            return ret == PxrResult.SUCCESS;
        }

        public override bool GetCameraImageResolution(PXRCameraEye eye, out Vector2Int[] resolutions)
        {
            var camera = getCameraAvailable(eye);
            PxrResult ret = PXR_CameraImage.GetCameraImageResolutionCapability(camera,
                out PxrExtent2Di[] _resolutions);
            if (ret == PxrResult.SUCCESS)
            {
                resolutions = new Vector2Int[_resolutions.Length];
                for (int i = 0; i < _resolutions.Length; i++)
                {
                    resolutions[i] = new Vector2Int(_resolutions[i].width, _resolutions[i].height);
                }

                return true;
            }

            resolutions = null;
            return false;
        }

        public override bool GetCameraImageFPS(PXRCameraEye eye, out PXRCameraFPS[] fps)
        {
            var camera = getCameraAvailable(eye);
            PxrResult ret = PXR_CameraImage.GetCameraImageFpsCapability(camera, out XrCameraImageFpsPICO[] _fpss);
            if (ret == PxrResult.SUCCESS)
            {
                var fpsList = new System.Collections.Generic.List<PXRCameraFPS>();
                foreach (var f in _fpss)
                {
                    if (f == XrCameraImageFpsPICO.XR_CAMERA_IMAGE_FPS_30_PICO) fpsList.Add(PXRCameraFPS.FPS30);
                    if (f == XrCameraImageFpsPICO.XR_CAMERA_IMAGE_FPS_60_PICO) fpsList.Add(PXRCameraFPS.FPS60);
                }
                fps = fpsList.ToArray();
                return true;
            }
            fps = null;
            return false;
        }

        public override async Task<bool> OpenCameraAsync(PXRCameraEye eye, int width, int height, int fps)
        {
            if (await base.OpenCameraAsync(eye, width, height, fps))
            {
                if (IsActiveOpenConfiguration(eye, width, height, fps))
                {
                    return true;
                }

                Debug.LogError(
                    $"OpenxrCameraAPI OpenCameraAsync: Camera is already open with {activeOpenEye} {activeOpenWidth}x{activeOpenHeight}@{activeOpenFps}fps. " +
                    $"Requested {eye} {width}x{height}@{fps}fps. CloseCamera before opening a different configuration.");
                return false;
            }

            bool cameraAvailable = false;
            XrCameraIdPICO openTargetCamera = getCameraAvailable(eye);
            int openGeneration = InvalidateCameraOpenGeneration();
            ulong openOwnerToken = 0;
            bool deviceCreatedInThisOpen = false;
            bool captureSessionCreatedInThisOpen = false;
          
            try
            {
                if (availableCameras == null)
                {
                    GetSupportedState();
                }

                if (availableCameras == null || availableCameras.Length == 0)
                {
                    Debug.LogError($"OpenxrCameraAPI OpenCameraAsync: No available cameras");
                    return false;
                }
                
                PLog.CameraLog("OpenxrCameraAPI", $"Found {availableCameras.Length} available cameras.");

                foreach (var cameraId in availableCameras)
                {
                    if (cameraId == openTargetCamera)
                    {
                        cameraAvailable = true;
                        break;
                    }
                }

                if (!cameraAvailable)
                {
                    Debug.LogError($"OpenxrCameraAPI OpenCameraAsync: Camera {eye} unavailable");
                    return false;
                }

                // Check if the camera supports the target resolution
                cameraAvailable = false;
                PxrExtent2Di targetResolution = new PxrExtent2Di(width, height);
                PxrResult ret = PXR_CameraImage.GetCameraImageResolutionCapability(openTargetCamera,
                    out PxrExtent2Di[] resolutions);
                if (ret == PxrResult.SUCCESS)
                {
                    foreach (var resolution in resolutions)
                    {
                        if (targetResolution.width == resolution.width && targetResolution.height == resolution.height)
                        {
                            cameraAvailable = true;
                            break;
                        }
                    }
                }

                if (!cameraAvailable)
                {
                    Debug.LogError($"OpenxrCameraAPI OpenCameraAsync: Camera {eye} does not support resolution {width}x{height}");
                    return false;
                }

                cameraAvailable = false;
                XrCameraImageFpsPICO targetFps = XrCameraImageFpsPICO.XR_CAMERA_IMAGE_FPS_30_PICO;
                ret = PXR_CameraImage.GetCameraImageFpsCapability(openTargetCamera,
                    out XrCameraImageFpsPICO[] fpss);
                if (ret == PxrResult.SUCCESS)
                {
                    foreach (var _fps in fpss)
                    {
                        if (_fps == XrCameraImageFpsPICO.XR_CAMERA_IMAGE_FPS_30_PICO && fps == 30)
                        {
                            cameraAvailable = true;
                            targetFps = XrCameraImageFpsPICO.XR_CAMERA_IMAGE_FPS_30_PICO;
                            break;
                        }
                        else if (_fps == XrCameraImageFpsPICO.XR_CAMERA_IMAGE_FPS_60_PICO && fps == 60)
                        {
                            cameraAvailable = true;
                            targetFps = XrCameraImageFpsPICO.XR_CAMERA_IMAGE_FPS_60_PICO;
                            break;
                        }
                    }
                }

                if (!cameraAvailable)
                {
                    Debug.LogError($"OpenxrCameraAPI OpenCameraAsync: Camera {eye} does not support FPS {fps}");
                    return false;
                }

                lastCaptureTime = 0;
                openOwnerToken = CreateLifecycleOwnerToken();
                if (!TryRegisterLifecycleOwner(openOwnerToken, openTargetCamera))
                {
                    Debug.LogError("OpenxrCameraAPI OpenCameraAsync: Camera lifecycle is closing.");
                    return false;
                }
                CancellationToken openToken = CreateOpenCancellationToken();

                PxrResult createDeviceResult = await PXR_CameraImage.CreateCameraDeviceAsync(
                    openTargetCamera, openOwnerToken, openToken);
                if (createDeviceResult != PxrResult.SUCCESS)
                {
                    Debug.LogError($"OpenxrCameraAPI OpenCameraAsync: Failed to create device for camera {eye}");
                    CleanupOpenAttemptResources(
                        openTargetCamera, openOwnerToken, false, false, false);
                    if (IsCurrentCameraOpenGeneration(openGeneration))
                    {
                        CancelAndDisposeCancellationTokenSource();
                    }
                    return false;
                }
                deviceCreatedInThisOpen = true;

                if (!IsCurrentCameraOpenGeneration(openGeneration))
                {
                    CleanupOpenAttemptResources(
                        openTargetCamera, openOwnerToken,
                        deviceCreatedInThisOpen, captureSessionCreatedInThisOpen, false);
                    return false;
                }
                activeCamera = openTargetCamera;
                activeLifecycleOwnerToken = openOwnerToken;
                isDeviceCreated = true;

                PxrResult createSessionResult = await PXR_CameraImage.CreateCameraCaptureSessionAsync(
                        openTargetCamera,
                        openOwnerToken,
                        targetResolution.width,
                        targetResolution.height,
                        targetFps,
                        XrCameraImageFormatPICO.XR_CAMERA_IMAGE_FORMAT_RGBA_8888_PICO,
                        XrCameraDataTransferTypePICO.XR_CAMERA_DATA_TRANSFER_TYPE_RAW_BUFFER_PICO,
                        XrCameraModelPICO.XR_CAMERA_MODEL_PINHOLE_PICO, openToken);
                if (createSessionResult != PxrResult.SUCCESS)
                {
                    Debug.LogError($"OpenxrCameraAPI CreateCameraCaptureSessionAsync: Failed to create capture session for camera {eye}");
                    bool clearCurrentResourceFlags = IsCurrentCameraOpenGeneration(openGeneration);
                    CleanupOpenAttemptResources(
                        openTargetCamera,
                        openOwnerToken,
                        deviceCreatedInThisOpen,
                        captureSessionCreatedInThisOpen,
                        clearCurrentResourceFlags);
                    if (clearCurrentResourceFlags)
                    {
                        CancelAndDisposeCancellationTokenSource();
                    }
                    return false;
                }
                captureSessionCreatedInThisOpen = true;

                if (!IsCurrentCameraOpenGeneration(openGeneration))
                {
                    CleanupOpenAttemptResources(
                        openTargetCamera, openOwnerToken,
                        deviceCreatedInThisOpen, captureSessionCreatedInThisOpen, false);
                    return false;
                }
                activeCamera = openTargetCamera;
                isCaptureSessionCreated = true;

                if (!IsCurrentCameraOpenGeneration(openGeneration))
                {
                    CleanupOpenAttemptResources(
                        openTargetCamera, openOwnerToken,
                        deviceCreatedInThisOpen, captureSessionCreatedInThisOpen, false);
                    return false;
                }

                SetActiveOpenConfiguration(eye, targetResolution.width, targetResolution.height, fps);
                m_State = PXRCameraStateCode.STATE_CAMERA_OPENED;
                return true;
            }
            catch (Exception e)
            {
                bool clearCurrentResourceFlags = openGeneration != 0 && IsCurrentCameraOpenGeneration(openGeneration);
                if (openOwnerToken != 0)
                {
                    CleanupOpenAttemptResources(
                        openTargetCamera,
                        openOwnerToken,
                        deviceCreatedInThisOpen,
                        captureSessionCreatedInThisOpen,
                        clearCurrentResourceFlags);
                }
                if (clearCurrentResourceFlags)
                {
                    CancelAndDisposeCancellationTokenSource();
                }
                Debug.LogError($"OpenxrCameraAPI OpenCameraAsync: {e.Message}");
                return false;
            }
        }

        public override bool StartPreview()
        {
            if (isCaptureStarted)
            {
                PLog.CameraLog("OpenxrCameraAPI", $"Camera {m_eye} capture is already started.");
                return true;
            }

            if (base.StartPreview())
            {
                return false;
            }

            if (!isCaptureSessionCreated)
            {
                Debug.LogError($"OpenxrCameraAPI StartPreview: Camera {m_eye} capture session is not created");
                return false;
            }

            XrCameraIdPICO previewCamera = activeCamera;
            // 5. Start capture
            if (PXR_CameraImage.BeginCameraCapture(previewCamera) != PxrResult.SUCCESS)
            {
                Debug.LogError($"OpenxrCameraAPI StartPreview: Failed to start capture for camera {m_eye}");
                return false;
            }

            lastCaptureTime = 0;
            isCaptureStarted = true;
            m_State = PXRCameraStateCode.STATE_VIDEO_PREVIEWING;
            return true;
        }

        private bool CleanupOpenAttemptResources(
            XrCameraIdPICO openTargetCamera,
            ulong openOwnerToken,
            bool deviceCreatedInThisOpen,
            bool captureSessionCreatedInThisOpen,
            bool clearCurrentResourceFlags)
        {
            bool success = true;

            PxrResult sessionResult = PXR_CameraImage.DestroyCameraCaptureSession(
                openTargetCamera, openOwnerToken);
            if (sessionResult != PxrResult.SUCCESS)
            {
                Debug.LogError($"OpenxrCameraAPI OpenCameraAsync: Failed to destroy stale capture session for camera {m_eye}");
                success = false;
            }

            PxrResult deviceResult = PxrResult.ERROR_RUNTIME_FAILURE;
            if (sessionResult == PxrResult.SUCCESS)
            {
                deviceResult = PXR_CameraImage.DestroyCameraDevice(
                    openTargetCamera, openOwnerToken);
                if (deviceResult != PxrResult.SUCCESS)
                {
                    Debug.LogError($"OpenxrCameraAPI OpenCameraAsync: Failed to destroy stale device for camera {m_eye}");
                    success = false;
                }
            }

            if (clearCurrentResourceFlags)
            {
                if (captureSessionCreatedInThisOpen && sessionResult == PxrResult.SUCCESS)
                {
                    isCaptureSessionCreated = false;
                }

                if (deviceCreatedInThisOpen && deviceResult == PxrResult.SUCCESS)
                {
                    isDeviceCreated = false;
                }
            }

            if (success)
            {
                UnregisterLifecycleOwner(openOwnerToken);
                if (activeLifecycleOwnerToken == openOwnerToken)
                {
                    activeLifecycleOwnerToken = 0;
                }
            }

            return success;
        }

        public override bool StopPreview()
        {
            lock (imageDataLock)
            {
                cameraLifecycleGeneration++;
                XrCameraIdPICO captureCamera = activeCamera;
                CancelAndDisposeCancellationTokenSource();
                bool success = EndCaptureIfNeeded(captureCamera);
                if (success && m_State == PXRCameraStateCode.STATE_VIDEO_PREVIEWING)
                {
                    m_State = PXRCameraStateCode.STATE_CAMERA_OPENED;
                }
                return success;
            }
        }

        public override bool CloseCamera()
        {
            SetLifecycleClosing(true);
            try
            {
                lock (imageDataLock)
                {
                    bool success = CleanupCameraResources();
                    if (!isCaptureSessionCreated)
                    {
                        imageData = default;
                    }
                    if (success)
                    {
                        m_State = PXRCameraStateCode.STATE_IDLE;
                    }
                    return success;
                }
            }
            finally
            {
                SetLifecycleClosing(false);
            }
        }

        public override bool AcquireCameraImage(PXRCameraEye eye, out ulong imageId, out Int64 captureTime)
        {
            base.AcquireCameraImage(eye, out imageId, out captureTime);
            XrCameraIdPICO frameCamera = activeCamera;
            PxrResult ret = PXR_CameraImage.AcquireCameraImage(frameCamera, lastCaptureTime, out imageId, out captureTime);
            if (ret == PxrResult.SUCCESS && imageId > 0)
            {
                lastCaptureTime = captureTime;
            }

            return ret == PxrResult.SUCCESS;
        }

        public override bool GetCameraImageData(PXRCameraEye deviceId, ulong imageId,
            out XrCameraImageDataRawBuffer rawBufferData)
        {
            base.GetCameraImageData(deviceId, imageId, out rawBufferData);
            XrCameraIdPICO frameCamera = activeCamera;
            return PXR_CameraImage.GetCameraImageData(frameCamera, imageId, out rawBufferData) ==
                   PxrResult.SUCCESS;
        }

        public override bool ReleaseCameraImage(PXRCameraEye deviceId, ulong imageId)
        {
            XrCameraIdPICO frameCamera = activeCamera;
            return PXR_CameraImage.ReleaseCameraImage(frameCamera, imageId) == PxrResult.SUCCESS;
        }


        public override bool GetCameraIntrinsics(PXRCameraEye deviceId, out CameraIntrinsics intrinsics)
        {
            intrinsics = new CameraIntrinsics();
            if (m_State == PXRCameraStateCode.STATE_IDLE)
            {
                return base.GetCameraIntrinsics(deviceId, out intrinsics);
            }

            XrCameraIdPICO calibrationCamera = activeCamera;
            PxrResult ret =
                PXR_CameraImage.GetCameraIntrinsics(calibrationCamera, out XrCameraIntrinsics _intrinsics);
            if (ret == PxrResult.SUCCESS)
            {
                intrinsics.FocalLength = new Vector2(_intrinsics.focalLength.X, _intrinsics.focalLength.Y);
                intrinsics.CornerPoint = new Vector2(_intrinsics.principalPoint.X, _intrinsics.principalPoint.Y);
                intrinsics.Fov = new Vector2(_intrinsics.fov.X, _intrinsics.fov.Y);
                intrinsics.Resolution= new Vector2Int(m_width, m_height);
                return true;
            }

            return false;
        }


        public override bool GetCameraExtrinsics(PXRCameraEye cameraId, out CameraExtrinsics extrinsics)
        {
            extrinsics = new CameraExtrinsics();
            if (m_State == PXRCameraStateCode.STATE_IDLE)
            {
                return base.GetCameraExtrinsics(cameraId, out extrinsics);
            }

            XrCameraIdPICO calibrationCamera = activeCamera;
            PxrResult ret =
                PXR_CameraImage.GetCameraExtrinsics(calibrationCamera, out XrCameraExtrinsics _extrinsics);
            if (ret == PxrResult.SUCCESS)
            {
                extrinsics.CameraPos = new Vector3(_extrinsics.pose.Position.X, _extrinsics.pose.Position.Y,
                    -_extrinsics.pose.Position.Z);
                extrinsics.CameraRot = new Quaternion(_extrinsics.pose.Orientation.X, _extrinsics.pose.Orientation.Y,
                    -_extrinsics.pose.Orientation.Z, -_extrinsics.pose.Orientation.W);
                return true;
            }

            return false;
        }

        private bool CleanupCameraResources()
        {
            bool success = true;
            cameraLifecycleGeneration++;
            ulong cleanupOwnerToken = activeLifecycleOwnerToken;
            KeyValuePair<ulong, XrCameraIdPICO>[] owners = GetLifecycleOwnersSnapshot();

            if (!EndCaptureIfNeeded(activeCamera))
            {
                success = false;
            }

            CancelAndDisposeCancellationTokenSource();

            if (success && cleanupOwnerToken != 0)
            {
                XrCameraIdPICO cleanupCamera = activeCamera;
                for (int i = 0; i < owners.Length; i++)
                {
                    if (owners[i].Key == cleanupOwnerToken)
                    {
                        cleanupCamera = owners[i].Value;
                        break;
                    }
                }

                PxrResult ret = PXR_CameraImage.DestroyCameraCaptureSession(
                    cleanupCamera, cleanupOwnerToken);
                if (ret == PxrResult.SUCCESS)
                {
                    isCaptureSessionCreated = false;
                }
                else
                {
                    Debug.LogError($"OpenxrCameraAPI CloseCamera: Failed to destroy capture session for camera {m_eye}");
                    success = false;
                }

                if (!isCaptureSessionCreated && isDeviceCreated)
                {
                    ret = PXR_CameraImage.DestroyCameraDevice(
                        cleanupCamera, cleanupOwnerToken);
                    if (ret == PxrResult.SUCCESS)
                    {
                        isDeviceCreated = false;
                    }
                    else
                    {
                        Debug.LogError($"OpenxrCameraAPI CloseCamera: Failed to destroy device for camera {m_eye}");
                        success = false;
                    }
                }
                else if (!isCaptureSessionCreated)
                {
                    ret = PXR_CameraImage.DestroyCameraDevice(
                        cleanupCamera, cleanupOwnerToken);
                    if (ret != PxrResult.SUCCESS)
                    {
                        success = false;
                    }
                }

                if (!isCaptureSessionCreated && !isDeviceCreated)
                {
                    UnregisterLifecycleOwner(cleanupOwnerToken);
                    activeLifecycleOwnerToken = 0;
                }
            }

            for (int i = 0; i < owners.Length; i++)
            {
                if (owners[i].Key == cleanupOwnerToken)
                {
                    continue;
                }

                if (!CleanupOpenAttemptResources(
                        owners[i].Value, owners[i].Key, false, false, false))
                {
                    success = false;
                }
            }

            bool allOwnersReleased = GetLifecycleOwnersSnapshot().Length == 0;
            if (success && allOwnersReleased)
            {
                lastCaptureTime = 0;
                ClearActiveOpenConfiguration();
            }
            else if (!allOwnersReleased)
            {
                success = false;
            }
            return success;
        }

        private bool EndCaptureIfNeeded(XrCameraIdPICO captureCamera)
        {
            if (!isCaptureStarted)
            {
                return true;
            }

            PxrResult ret = PXR_CameraImage.EndCameraCapture(captureCamera);
            if (ret != PxrResult.SUCCESS)
            {
                Debug.LogError($"OpenxrCameraAPI StopPreview: Failed to end capture for camera {m_eye}");
                return false;
            }

            isCaptureStarted = false;
            return true;
        }
 
      
        private XrCameraIdPICO getCameraAvailable(PXRCameraEye eye)
        {
            if (eye == PXRCameraEye.Left)
            {
                return XrCameraIdPICO.XR_CAMERA_ID_RGB_LEFT_PICO;
            }

            if (eye == PXRCameraEye.Right)
            {
                return XrCameraIdPICO.XR_CAMERA_ID_RGB_RIGHT_PICO;
            }

            return XrCameraIdPICO.XR_CAMERA_ID_RGB_LEFT_PICO;
        }
    }
}
