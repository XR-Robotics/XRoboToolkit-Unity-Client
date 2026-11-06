using System;
using System.IO;
using NUnit.Framework;
using UnityEditor.PackageManager;

namespace ByteDance.PICO.CameraPack.Editor.Tests
{
    public class CameraApiAsyncPatternTests
    {
        [Test]
        public void CameraApiOpenCameraAsync_ReturnsTaskWithoutAsyncStateMachine()
        {
            string source = ReadPackageFile("CameraPack/Scripts/CameraAPI/CameraAPI.cs");
            string openSource = ExtractSourceSpan(
                source,
                "public virtual Task<bool> OpenCameraAsync",
                "public virtual bool StartPreview");

            Assert.That(source, Does.Not.Contain("public virtual async Task<bool> OpenCameraAsync"));
            Assert.That(source, Does.Contain("public virtual Task<bool> OpenCameraAsync"));
            Assert.That(source, Does.Contain("Task.FromResult(true)"));
            Assert.That(source, Does.Contain("Task.FromResult(false)"));
            AssertOccursBefore(openSource, "if (m_State == PXRCameraStateCode.STATE_CAMERA_OPENED", "m_eye = eye;");
            AssertOccursBefore(openSource, "if (m_State == PXRCameraStateCode.STATE_CAMERA_OPENED", "_isFirstFrame = true;");
        }

        [Test]
        public void OpenxrCameraApi_UsesSingleBaseOpenRequestAndBaseCancellationToken()
        {
            string source = ReadPackageFile("CameraPack/Scripts/CameraAPI/OpenxrCameraAPI.cs");

            Assert.That(source, Does.Not.Contain("private CancellationTokenSource cancellationTokenSource"));
            Assert.That(CountOccurrences(source, "base.OpenCameraAsync("), Is.EqualTo(1));
        }

        [Test]
        public void CameraApiState_IsInstanceScopedForIndependentEyeSessions()
        {
            string source = ReadPackageFile("CameraPack/Scripts/CameraAPI/CameraAPI.cs");

            Assert.That(source, Does.Not.Contain("static PXRCameraStateCode m_State"));
            Assert.That(source, Does.Contain("protected PXRCameraStateCode m_State"));
        }

        [Test]
        public void PxrCamTextureManagerPlay_SkipsWhenInstanceAlreadyPreviewing()
        {
            string source = ReadPackageFile("CameraPack/Scripts/PXR_CamTextureManager.cs");

            Assert.That(source, Does.Contain("_cameraAPI.GetState() == PXRCameraStateCode.STATE_VIDEO_PREVIEWING"));
            Assert.That(source, Does.Contain($"Camera {{Eye}} is already previewing."));
        }

        [Test]
        public void PxrCamTextureManagerStop_ClosesCameraForAllLifecycleStates()
        {
            string source = ReadPackageFile("CameraPack/Scripts/PXR_CamTextureManager.cs");

            Assert.That(source, Does.Contain("_cameraAPI.CloseCamera();"));
            Assert.That(source, Does.Not.Contain("if (_cameraAPI.GetState() >= PXRCameraStateCode.STATE_CAMERA_OPENED)"));
        }

        [Test]
        public void PxrCamTextureManagerPlay_RetriesPendingCleanupBeforePreviewShortCircuit()
        {
            string source = ReadPackageFile("CameraPack/Scripts/PXR_CamTextureManager.cs");
            string playSource = ExtractSourceSpan(
                source,
                "public void Play()",
                "private void OnFirstFrameReceived");
            string stopSource = ExtractSourceSpan(
                source,
                "public void Stop()",
                "public Texture GetTexture()");

            Assert.That(source, Does.Contain("private bool _cameraCleanupPending;"));
            Assert.That(source, Does.Contain("private bool CloseCameraAndTrackPendingCleanup()"));
            Assert.That(playSource, Does.Contain("_cameraCleanupPending"));
            Assert.That(playSource, Does.Contain("CloseCameraAndTrackPendingCleanup()"));
            AssertOccursBefore(
                playSource,
                "_cameraCleanupPending",
                "_cameraAPI.GetState() == PXRCameraStateCode.STATE_VIDEO_PREVIEWING");
            Assert.That(stopSource, Does.Contain("CloseCameraAndTrackPendingCleanup();"));
        }

        [Test]
        public void PxrCamTextureManagerOpen_UsesGenerationGuardForStaleAsyncOpen()
        {
            string source = ReadPackageFile("CameraPack/Scripts/PXR_CamTextureManager.cs");

            Assert.That(source, Does.Contain("private int _cameraOpenGeneration;"));
            Assert.That(source, Does.Contain("int openGeneration = ++_cameraOpenGeneration;"));
            Assert.That(source, Does.Contain("StartCameraRoutine(openGeneration)"));
            Assert.That(source, Does.Contain("private IEnumerator StartCameraRoutine(int openGeneration)"));
            Assert.That(source, Does.Contain("if (openGeneration != _cameraOpenGeneration)"));
            Assert.That(source, Does.Contain("_cameraAPI.CloseCamera();"));
            Assert.That(source, Does.Contain("_cameraOpenGeneration++;"));
        }

        [Test]
        public void PxrCamTextureManagerOpen_RestartsBeforeChangingActiveConfiguration()
        {
            string source = ReadPackageFile("CameraPack/Scripts/PXR_CamTextureManager.cs");
            string openSource = ExtractSourceSpan(
                source,
                "public void OpenCameraAsync",
                "public Vector2Int[] GetSupportedResolutions");

            Assert.That(source, Does.Contain("private bool IsCurrentConfiguration(PXRCameraEye eye, PXRCameraFPS fps, Vector2Int resolution)"));
            Assert.That(source, Does.Contain("private bool HasActiveOpenOrPendingRequest()"));
            Assert.That(openSource, Does.Contain("bool shouldRestartCamera = !IsCurrentConfiguration(eye, fps, resolution) && HasActiveOpenOrPendingRequest();"));
            Assert.That(openSource, Does.Contain("Stop();"));
            Assert.That(openSource, Does.Contain("Eye = eye;"));
            Assert.That(openSource, Does.Contain("FPS = fps;"));
            Assert.That(openSource, Does.Contain("Resolution = resolution;"));
            AssertOccursBefore(openSource, "Stop();", "Eye = eye;");
            AssertOccursBefore(openSource, "Stop();", "FPS = fps;");
            AssertOccursBefore(openSource, "Stop();", "Resolution = resolution;");
            AssertOccursBefore(openSource, "Eye = eye;", "Play();");
        }

        [Test]
        public void PxrCamTextureManagerOpen_StartsFrameLoopOnlyAfterPreviewStarts()
        {
            string source = ReadPackageFile("CameraPack/Scripts/PXR_CamTextureManager.cs");
            string startRoutineSource = ExtractSourceSpan(
                source,
                "private IEnumerator StartCameraRoutine",
                "public void Stop()");

            Assert.That(startRoutineSource, Does.Contain("bool success = _cameraAPI.StartPreview();"));
            Assert.That(startRoutineSource, Does.Contain("_cameraAPI.OnCameraCreate();"));
            Assert.That(startRoutineSource, Does.Contain("Debug.LogError(\"Failed to start camera preview.\");"));
            AssertOccursBefore(startRoutineSource, "bool success = _cameraAPI.StartPreview();", "_cameraAPI.OnCameraCreate();");
            AssertOccursBefore(startRoutineSource, "if (success)", "_cameraAPI.OnCameraCreate();");
        }

        [Test]
        public void OpenxrCameraApi_TracksCreatedResourcesAndUsesCentralCleanup()
        {
            string source = ReadPackageFile("CameraPack/Scripts/CameraAPI/OpenxrCameraAPI.cs");

            Assert.That(source, Does.Contain("private bool isDeviceCreated"));
            Assert.That(source, Does.Contain("private bool isCaptureSessionCreated"));
            Assert.That(source, Does.Contain("private bool isCaptureStarted"));
            Assert.That(source, Does.Contain("CleanupCameraResources"));
            Assert.That(source, Does.Contain("isDeviceCreated = true"));
            Assert.That(source, Does.Contain("isCaptureSessionCreated = true"));
            Assert.That(source, Does.Contain("isCaptureStarted = true"));
        }

        [Test]
        public void OpenxrCameraApi_UsesLifecycleGenerationBeforeSettingResourceFlags()
        {
            string source = ReadPackageFile("CameraPack/Scripts/CameraAPI/OpenxrCameraAPI.cs");

            Assert.That(source, Does.Contain("private int cameraLifecycleGeneration;"));
            Assert.That(source, Does.Contain("private XrCameraIdPICO activeCamera"));
            Assert.That(source, Does.Contain("private bool hasActiveOpenConfiguration;"));
            Assert.That(source, Does.Contain("private PXRCameraEye activeOpenEye"));
            Assert.That(source, Does.Contain("private int activeOpenWidth;"));
            Assert.That(source, Does.Contain("private int activeOpenHeight;"));
            Assert.That(source, Does.Contain("private int activeOpenFps;"));
            Assert.That(source, Does.Contain("private int InvalidateCameraOpenGeneration()"));
            Assert.That(source, Does.Contain("private CancellationToken CreateOpenCancellationToken()"));
            Assert.That(source, Does.Contain("private bool IsCurrentCameraOpenGeneration(int openGeneration)"));
            Assert.That(source, Does.Contain("private bool IsActiveOpenConfiguration(PXRCameraEye eye, int width, int height, int fps)"));
            Assert.That(source, Does.Contain("private void SetActiveOpenConfiguration(PXRCameraEye eye, int width, int height, int fps)"));
            Assert.That(source, Does.Contain("private void ClearActiveOpenConfiguration()"));
            Assert.That(source, Does.Contain("int openGeneration = InvalidateCameraOpenGeneration();"));
            Assert.That(source, Does.Contain("CancellationToken openToken = CreateOpenCancellationToken();"));
            Assert.That(source, Does.Contain("cameraLifecycleGeneration++;"));
            Assert.That(source, Does.Contain("XrCameraIdPICO openTargetCamera = getCameraAvailable(eye);"));
            Assert.That(source, Does.Contain("ulong openOwnerToken = 0;"));
            Assert.That(source, Does.Contain("openOwnerToken = CreateLifecycleOwnerToken();"));
            Assert.That(source, Does.Contain("bool deviceCreatedInThisOpen = false;"));
            Assert.That(source, Does.Contain("bool captureSessionCreatedInThisOpen = false;"));
            Assert.That(source, Does.Contain("CleanupOpenAttemptResources("));
            Assert.That(source, Does.Contain("openTargetCamera, openOwnerToken"));
            Assert.That(source, Does.Not.Contain("targetCamera"));

            string openSource = ExtractSourceSpan(
                source,
                "public override async Task<bool> OpenCameraAsync",
                "public override bool StartPreview");
            Assert.That(openSource, Does.Contain("if (IsActiveOpenConfiguration(eye, width, height, fps))"));
            Assert.That(openSource, Does.Contain("CloseCamera before opening a different configuration."));
            Assert.That(openSource, Does.Contain("PXR_CameraImage.CreateCameraDeviceAsync("));
            Assert.That(openSource, Does.Contain("openTargetCamera, openOwnerToken, openToken"));
            Assert.That(openSource, Does.Contain("PXR_CameraImage.CreateCameraCaptureSessionAsync("));
            Assert.That(openSource, Does.Contain("openTargetCamera,"));
            Assert.That(openSource, Does.Contain("activeCamera = openTargetCamera;"));
            Assert.That(openSource, Does.Contain("SetActiveOpenConfiguration(eye, targetResolution.width, targetResolution.height, fps);"));
            Assert.That(openSource, Does.Contain("CleanupOpenAttemptResources("));
            Assert.That(openSource, Does.Not.Contain("CleanupCameraResources();"));
            AssertOccursBefore(openSource, "if (IsActiveOpenConfiguration(eye, width, height, fps))", "int openGeneration = InvalidateCameraOpenGeneration();");
            AssertOccursBefore(openSource, "int openGeneration = InvalidateCameraOpenGeneration();", "PXR_CameraImage.GetCameraImageResolutionCapability(openTargetCamera");
            AssertOccursBefore(openSource, "int openGeneration = InvalidateCameraOpenGeneration();", "PXR_CameraImage.GetCameraImageFpsCapability(openTargetCamera");
            AssertOccursBefore(openSource, "CancellationToken openToken = CreateOpenCancellationToken();", "PXR_CameraImage.CreateCameraDeviceAsync(");
            AssertOccursBefore(openSource, "deviceCreatedInThisOpen = true", "if (!IsCurrentCameraOpenGeneration(openGeneration))");
            AssertOccursBefore(openSource, "if (!IsCurrentCameraOpenGeneration(openGeneration))", "isDeviceCreated = true");
            AssertOccursBefore(openSource, "activeCamera = openTargetCamera;", "isDeviceCreated = true");
            AssertOccursBefore(openSource, "captureSessionCreatedInThisOpen = true", "isCaptureSessionCreated = true");
            AssertOccursBefore(openSource, "if (!IsCurrentCameraOpenGeneration(openGeneration))", "isCaptureSessionCreated = true");
            AssertOccursBefore(openSource, "SetActiveOpenConfiguration(eye, targetResolution.width, targetResolution.height, fps);", "m_State = PXRCameraStateCode.STATE_CAMERA_OPENED;");

            string openCleanupSource = ExtractSourceSpan(
                source,
                "private bool CleanupOpenAttemptResources",
                "public override bool StopPreview");
            Assert.That(openCleanupSource, Does.Contain("XrCameraIdPICO openTargetCamera"));
            Assert.That(openCleanupSource, Does.Contain("ulong openOwnerToken"));
            Assert.That(openCleanupSource, Does.Contain("bool clearCurrentResourceFlags"));
            Assert.That(openCleanupSource, Does.Contain("DestroyCameraCaptureSession("));
            Assert.That(openCleanupSource, Does.Contain("DestroyCameraDevice("));
            Assert.That(openCleanupSource, Does.Contain("openTargetCamera, openOwnerToken"));
            Assert.That(openCleanupSource, Does.Contain("isCaptureSessionCreated = false;"));
            Assert.That(openCleanupSource, Does.Contain("isDeviceCreated = false;"));
            AssertOccursBefore(openCleanupSource, "DestroyCameraCaptureSession(", "DestroyCameraDevice(");

            string startPreviewSource = ExtractSourceSpan(
                source,
                "public override bool StartPreview",
                "private bool CleanupOpenAttemptResources");
            Assert.That(startPreviewSource, Does.Contain("XrCameraIdPICO previewCamera = activeCamera;"));
            Assert.That(startPreviewSource, Does.Contain("PXR_CameraImage.BeginCameraCapture(previewCamera)"));

            string cleanupSource = ExtractSourceSpan(
                source,
                "private bool CleanupCameraResources",
                "private bool EndCaptureIfNeeded");
            Assert.That(cleanupSource, Does.Contain("cameraLifecycleGeneration++;"));
            Assert.That(cleanupSource, Does.Contain("ulong cleanupOwnerToken = activeLifecycleOwnerToken;"));
            Assert.That(cleanupSource, Does.Contain("EndCaptureIfNeeded(activeCamera)"));
            Assert.That(cleanupSource, Does.Contain("DestroyCameraCaptureSession("));
            Assert.That(cleanupSource, Does.Contain("DestroyCameraDevice("));
            Assert.That(cleanupSource, Does.Contain("cleanupCamera, cleanupOwnerToken"));
            Assert.That(cleanupSource, Does.Contain("ClearActiveOpenConfiguration();"));
        }

        [Test]
        public void OpenxrCameraApi_StopPreviewInvalidatesLifecycleGenerationBeforeCancel()
        {
            string source = ReadPackageFile("CameraPack/Scripts/CameraAPI/OpenxrCameraAPI.cs");
            string stopPreviewSource = ExtractSourceSpan(
                source,
                "public override bool StopPreview",
                "public override bool CloseCamera");

            Assert.That(stopPreviewSource, Does.Contain("cameraLifecycleGeneration++;"));
            Assert.That(stopPreviewSource, Does.Contain("XrCameraIdPICO captureCamera = activeCamera;"));
            Assert.That(stopPreviewSource, Does.Contain("EndCaptureIfNeeded(captureCamera)"));
            AssertOccursBefore(stopPreviewSource, "cameraLifecycleGeneration++;", "CancelAndDisposeCancellationTokenSource();");
        }

        [Test]
        public void OpenxrCameraApi_AcquiresOnlyFramesNewerThanLastCaptureTime()
        {
            string source = ReadPackageFile("CameraPack/Scripts/CameraAPI/OpenxrCameraAPI.cs");
            string acquireSource = ExtractSourceSpan(
                source,
                "public override bool AcquireCameraImage",
                "public override bool GetCameraImageData");
            string getImageDataSource = ExtractSourceSpan(
                source,
                "public override bool GetCameraImageData",
                "public override bool ReleaseCameraImage");
            string releaseSource = ExtractSourceSpan(
                source,
                "public override bool ReleaseCameraImage",
                "public override bool GetCameraIntrinsics");
            string intrinsicsSource = ExtractSourceSpan(
                source,
                "public override bool GetCameraIntrinsics",
                "public override bool GetCameraExtrinsics");
            string extrinsicsSource = ExtractSourceSpan(
                source,
                "public override bool GetCameraExtrinsics",
                "private bool CleanupCameraResources");

            Assert.That(source, Does.Contain("private Int64 lastCaptureTime"));
            Assert.That(acquireSource, Does.Contain("XrCameraIdPICO frameCamera = activeCamera;"));
            Assert.That(acquireSource, Does.Contain("PXR_CameraImage.AcquireCameraImage(frameCamera, lastCaptureTime, out imageId, out captureTime)"));
            Assert.That(acquireSource, Does.Not.Contain("getCameraAvailable(eye)"));
            Assert.That(source, Does.Contain("lastCaptureTime = captureTime"));
            Assert.That(getImageDataSource, Does.Contain("XrCameraIdPICO frameCamera = activeCamera;"));
            Assert.That(getImageDataSource, Does.Contain("PXR_CameraImage.GetCameraImageData(frameCamera, imageId, out rawBufferData)"));
            Assert.That(getImageDataSource, Does.Not.Contain("getCameraAvailable(deviceId)"));
            Assert.That(releaseSource, Does.Contain("XrCameraIdPICO frameCamera = activeCamera;"));
            Assert.That(releaseSource, Does.Contain("PXR_CameraImage.ReleaseCameraImage(frameCamera, imageId)"));
            Assert.That(releaseSource, Does.Not.Contain("getCameraAvailable(deviceId)"));
            Assert.That(intrinsicsSource, Does.Contain("XrCameraIdPICO calibrationCamera = activeCamera;"));
            Assert.That(intrinsicsSource, Does.Contain("PXR_CameraImage.GetCameraIntrinsics(calibrationCamera, out XrCameraIntrinsics _intrinsics)"));
            Assert.That(intrinsicsSource, Does.Not.Contain("getCameraAvailable(deviceId)"));
            Assert.That(extrinsicsSource, Does.Contain("XrCameraIdPICO calibrationCamera = activeCamera;"));
            Assert.That(extrinsicsSource, Does.Contain("PXR_CameraImage.GetCameraExtrinsics(calibrationCamera, out XrCameraExtrinsics _extrinsics)"));
            Assert.That(extrinsicsSource, Does.Not.Contain("getCameraAvailable(cameraId)"));
        }

        [Test]
        public void PxrCameraImageAsyncCreate_CompletesFutureAndCleansUpWhenCanceled()
        {
            string source = ReadPackageFile("Runtime/Scripts/Features/PXR_CameraImage.cs");

            Assert.That(source, Does.Contain("private readonly struct CameraFutureWaitResult"));
            Assert.That(source, Does.Contain("private static async Task<CameraFutureWaitResult> WaitForCameraFutureReadyAsync"));
            Assert.That(source, Does.Contain("if (token.IsCancellationRequested)"));
            Assert.That(source, Does.Contain("await Task.Delay(CameraFuturePollDelayMilliseconds);"));
            Assert.That(source, Does.Not.Contain("Task.Delay(11, token)"));
            Assert.That(source, Does.Contain("waitResult.CancellationRequested || token.IsCancellationRequested"));
            Assert.That(source, Does.Contain("completion.futureResult == PxrResult.SUCCESS"));
            Assert.That(source, Does.Contain("PXR_CameraImagePlugin.UPxr_DestroyCameraDevice((int)cameraId);"));
            Assert.That(source, Does.Contain("PXR_CameraImagePlugin.UPxr_DestroyCameraCaptureSession((int)cameraId);"));
        }

        [Test]
        public void CameraApi_FrameAcquireLogsAreVerboseOnly()
        {
            string source = ReadPackageFile("CameraPack/Scripts/CameraAPI/CameraAPI.cs");

            Assert.That(source, Does.Contain("[SerializeField] private bool _enableVerboseFrameLogs = false;"));
            Assert.That(source, Does.Contain("private void LogVerboseFrame("));
            Assert.That(source, Does.Contain("if (!_enableVerboseFrameLogs)"));
            Assert.That(source, Does.Contain("LogVerboseFrame($\"CameraAPI: Acquired image {imageId}, captureTime {captureTime}\")"));
            Assert.That(source, Does.Not.Contain("PLog.CameraLog(\"CameraAPI\", $\"CameraAPI: Acquired image {imageId}, captureTime {captureTime}\")"));
        }

        [Test]
        public void CameraApiPixelReads_ReuseManagedBufferAndAvoidFullCopyForSinglePixel()
        {
            string cameraApiSource = ReadPackageFile("CameraPack/Scripts/CameraAPI/CameraAPI.cs");
            string managerSource = ReadPackageFile("CameraPack/Scripts/PXR_CamTextureManager.cs");

            Assert.That(cameraApiSource, Does.Contain("private byte[] imageDataBuffer"));
            Assert.That(cameraApiSource, Does.Contain("private bool EnsureImageDataBuffer(int bufferSize)"));
            Assert.That(cameraApiSource, Does.Contain("public virtual bool GetPixels32(Color32[] color32)"));
            Assert.That(cameraApiSource, Does.Contain("Marshal.ReadByte(imageData.buffer, pixelIndex)"));
            Assert.That(cameraApiSource, Does.Not.Contain("byte[] imageData_ = new byte[bufferSize]"));
            Assert.That(cameraApiSource, Does.Not.Contain("color32 = new Color32[m_width * m_height]"));
            Assert.That(managerSource, Does.Contain("return _cameraAPI.GetPixels32(colors);"));
        }

        [Test]
        public void CameraApiFrameLoop_ReleasesAcquiredImageEvenWhenFrameDataFails()
        {
            string source = ReadPackageFile("CameraPack/Scripts/CameraAPI/CameraAPI.cs");
            string frameLoop = ExtractSourceSpan(
                source,
                "private IEnumerator CallPluginAtEndOfFrames",
                "public virtual bool AcquireCameraImage");

            Assert.That(frameLoop, Does.Contain("bool shouldReleaseImage = false;"));
            Assert.That(frameLoop, Does.Contain("try"));
            Assert.That(frameLoop, Does.Contain("shouldReleaseImage = true;"));
            Assert.That(frameLoop, Does.Contain("finally"));
            Assert.That(frameLoop, Does.Contain("if (shouldReleaseImage)"));
            Assert.That(frameLoop, Does.Contain("ReleaseCameraImage(m_eye, imageId)"));
        }

        [Test]
        public void NativeCameraImage_UsesCameraIdMappedStreamState()
        {
            string header = ReadRepositoryFile("PxrPlatform/Source/Extensions/PICOCameraImage.h");
            string source = ReadRepositoryFile("PxrPlatform/Source/Extensions/PICOCameraImage.cpp");

            Assert.That(header, Does.Contain("#include <unordered_map>"));
            Assert.That(header, Does.Contain("struct CameraImageBufferCache"));
            Assert.That(header, Does.Contain("struct CameraStreamState"));
            Assert.That(header, Does.Contain("using CameraStreamStatePtr = std::shared_ptr<CameraStreamState>;"));
            Assert.That(header, Does.Contain("std::unordered_map<int, CameraStreamStatePtr> cameraStreams_"));
            Assert.That(header, Does.Contain("CameraStreamStatePtr GetOrCreateCameraStream(int cameraId)"));
            Assert.That(header, Does.Contain("CameraStreamStatePtr FindCameraStream(int cameraId)"));
            Assert.That(header, Does.Contain("pendingDeviceFuture"));
            Assert.That(header, Does.Contain("pendingDeviceGeneration"));
            Assert.That(header, Does.Contain("pendingCaptureSessionFuture"));
            Assert.That(header, Does.Contain("pendingCaptureSessionGeneration"));
            Assert.That(header, Does.Not.Contain("leftCameraDevice_"));
            Assert.That(header, Does.Not.Contain("rightCameraDevice_"));
            Assert.That(header, Does.Not.Contain("leftCameraCaptureSession_"));
            Assert.That(header, Does.Not.Contain("rightCameraCaptureSession_"));
            Assert.That(header, Does.Not.Contain("leftCameraIntrinsics_"));
            Assert.That(header, Does.Not.Contain("rightCameraIntrinsics_"));
            Assert.That(header, Does.Not.Contain("leftExtrinsics_"));
            Assert.That(header, Does.Not.Contain("rightExtrinsics_"));
            Assert.That(header, Does.Not.Contain("leftCameraImageBuffer_"));
            Assert.That(header, Does.Not.Contain("rightCameraImageBuffer_"));
            Assert.That(header, Does.Not.Contain("const int RGBLeftCamera"));
            Assert.That(header, Does.Not.Contain("const int RGBRightCamera"));
            Assert.That(header, Does.Not.Contain("std::unique_ptr<unsigned char[]> m_cachedBuffer"));

            Assert.That(source, Does.Contain("PICOCameraImage::CameraStreamStatePtr PICOCameraImage::GetOrCreateCameraStream(int cameraId)"));
            Assert.That(source, Does.Contain("stream = std::make_shared<CameraStreamState>();"));
            Assert.That(source, Does.Contain("auto stream = cameraStreams_.find(cameraId);"));
            Assert.That(source, Does.Contain("CameraStreamStatePtr stream = GetOrCreateCameraStream(cameraId);"));
            Assert.That(source, Does.Contain("CameraImageBufferCachePtr bufferCache;"));
            Assert.That(source, Does.Contain("stream->imageBuffers.emplace(imageId, bufferCache);"));
            Assert.That(source, Does.Contain("bufferCache->buffer"));
            Assert.That(source, Does.Not.Contain("RGBLeftCamera"));
            Assert.That(source, Does.Not.Contain("RGBRightCamera"));
            Assert.That(source, Does.Not.Contain("leftCamera"));
            Assert.That(source, Does.Not.Contain("rightCamera"));
            Assert.That(source, Does.Not.Contain("m_cachedBuffer.get()"));
        }

        [Test]
        public void NativeCameraImage_ReleasesCaptureConfigArrayAndDestroysIdempotently()
        {
            string source = ReadRepositoryFile("PxrPlatform/Source/Extensions/PICOCameraImage.cpp");

            Assert.That(source, Does.Contain("const XrCameraCapabilityBaseHeaderPICO* configs[configCount] = {};"));
            Assert.That(source, Does.Contain("createInfo.configs = configs;"));
            Assert.That(source, Does.Not.Contain("new XrCameraCapabilityBaseHeaderPICO*[configCount]"));
            Assert.That(source, Does.Not.Contain("delete[] configs"));

            string destroyDevice = ExtractSourceSpan(
                source,
                "int PICOCameraImage:: DestroyCameraDevice",
                "int PICOCameraImage::DestroyCameraCaptureSession");
            Assert.That(destroyDevice, Does.Contain("DestroyCameraDevice camera stream is already released."));
            Assert.That(destroyDevice, Does.Contain("DestroyCameraDevice camera device is already null."));
            Assert.That(destroyDevice, Does.Contain("return XR_SUCCESS;"));
            Assert.That(destroyDevice, Does.Not.Contain("DestroyCameraDevice camera stream is null."));

            string destroySession = ExtractSourceSpan(
                source,
                "int PICOCameraImage::DestroyCameraCaptureSession",
                "int PICOCameraImage::GetCameraIntrinsics");
            Assert.That(destroySession, Does.Contain("DestroyCameraCaptureSession camera stream is already released."));
            Assert.That(destroySession, Does.Contain("DestroyCameraCaptureSession capture session is already null."));
            Assert.That(destroySession, Does.Contain("return XR_SUCCESS;"));
        }

        [Test]
        public void NativeCameraImage_TreatsInvalidDestroyedHandlesAsReleased()
        {
            string source = ReadRepositoryFile("PxrPlatform/Source/Extensions/PICOCameraImage.cpp");
            string destroyDevice = ExtractSourceSpan(
                source,
                "int PICOCameraImage:: DestroyCameraDevice",
                "int PICOCameraImage::DestroyCameraCaptureSession");
            string destroySession = ExtractSourceSpan(
                source,
                "int PICOCameraImage::DestroyCameraCaptureSession",
                "int PICOCameraImage::GetCameraIntrinsics");

            Assert.That(destroyDevice, Does.Contain("ret == XR_ERROR_HANDLE_INVALID"));
            Assert.That(destroyDevice, Does.Contain("ret = XR_SUCCESS;"));
            Assert.That(destroySession, Does.Contain("ret == XR_ERROR_HANDLE_INVALID"));
            Assert.That(destroySession, Does.Contain("ret = XR_SUCCESS;"));
        }

        [Test]
        public void NativeCameraImage_GuardsCameraStreamMapAccessForAsyncOpenAndFrameRead()
        {
            string header = ReadRepositoryFile("PxrPlatform/Source/Extensions/PICOCameraImage.h");
            string source = ReadRepositoryFile("PxrPlatform/Source/Extensions/PICOCameraImage.cpp");

            Assert.That(header, Does.Contain("#include <mutex>"));
            Assert.That(header, Does.Contain("std::mutex mutex;"));
            Assert.That(header, Does.Contain("std::mutex cameraStreamsMutex_"));
            Assert.That(header, Does.Not.Contain("std::recursive_mutex"));
            Assert.That(source, Does.Not.Contain("std::lock_guard<std::recursive_mutex>"));
            Assert.That(source, Does.Contain("Lock ordering: cameraStreamsMutex_ before CameraStreamState::mutex."));
            Assert.That(source, Does.Contain("std::lock_guard<std::mutex> mapLock(cameraStreamsMutex_);"));
            Assert.That(
                CountOccurrences(source, "std::lock_guard<std::mutex> streamLock(stream->mutex);"),
                Is.GreaterThanOrEqualTo(10));
            Assert.That(source, Does.Contain("void PICOCameraImage::EraseCameraStreamIfReleased"));
            Assert.That(source, Does.Contain("stream.use_count() != 2"));
        }

        [Test]
        public void NativeCameraImage_TracksPendingFuturesAndRejectsStaleCompletes()
        {
            string source = ReadRepositoryFile("PxrPlatform/Source/Extensions/PICOCameraImage.cpp");

            Assert.That(source, Does.Contain("stream->pendingDeviceFuture = *future;"));
            Assert.That(source, Does.Contain("stream->pendingDeviceGeneration++;"));
            Assert.That(source, Does.Contain("stream->pendingCaptureSessionFuture = *future;"));
            Assert.That(source, Does.Contain("stream->pendingCaptureSessionGeneration++;"));
            Assert.That(source, Does.Contain("const bool isCurrentFuture ="));
            Assert.That(source, Does.Contain("stream->pendingDeviceFuture == future"));
            Assert.That(source, Does.Contain("stream->pendingCaptureSessionFuture == future"));
            Assert.That(source, Does.Contain("xrDestroyCameraDevicePICO(completion->device);"));
            Assert.That(source, Does.Contain("xrDestroyCameraCaptureSessionPICO(completion->captureSession);"));
            Assert.That(source, Does.Contain("ret = XR_ERROR_FUTURE_INVALID_EXT;"));
        }

        [Test]
        public void NativeCameraImage_HasOptInFrameTimingLogsForDeviceProfiling()
        {
            string source = ReadRepositoryFile("PxrPlatform/Source/Extensions/PICOCameraImage.cpp");

            Assert.That(source, Does.Contain("#include <chrono>"));
            Assert.That(source, Does.Contain("PICO_CAMERA_IMAGE_PROFILE"));
            Assert.That(source, Does.Contain("LogCameraImageProfile("));
            Assert.That(source, Does.Contain("LogCameraImageProfile(\"AcquireCameraImage\""));
            Assert.That(source, Does.Contain("LogCameraImageProfile(\"GetCameraImageDataPICO\""));
            Assert.That(source, Does.Contain("LogCameraImageProfile(\"ReleaseCameraImageData\""));
        }

        [Test]
        public void NativeCameraImage_QueryResultsHavePerCallOwnership()
        {
            string header = ReadRepositoryFile("PxrPlatform/Source/Extensions/PICOCameraImage.h");
            string source = ReadRepositoryFile("PxrPlatform/Source/Extensions/PICOCameraImage.cpp");
            string bridge = ReadRepositoryFile("PxrPlatform/Source/MR_API.cpp");
            string plugin = ReadPackageFile("Runtime/Scripts/Utils/PXR_CameraImagePlugin.cs");

            Assert.That(header, Does.Contain("void FreeCameraData(void *data);"));
            Assert.That(header, Does.Not.Contain("XrCameraIdPICO *cameraIds = nullptr;"));
            Assert.That(header, Does.Not.Contain("XrCameraPropertyTypePICO *types = nullptr;"));
            Assert.That(header, Does.Not.Contain("XrCameraCapabilityTypePICO *capabilities = nullptr;"));
            Assert.That(header, Does.Not.Contain("XrExtent2Di *resolutions_ = nullptr;"));
            Assert.That(source, Does.Contain("void PICOCameraImage::FreeCameraData(void *data)"));
            Assert.That(bridge, Does.Contain("Pxr_FreeCameraData(void *data)"));
            Assert.That(plugin, Does.Contain("private static extern void Pxr_FreeCameraData(IntPtr data);"));
            Assert.That(plugin, Does.Contain("finally"));
            Assert.That(plugin, Does.Contain("Pxr_FreeCameraData("));
        }

        [Test]
        public void NativeCameraImage_LeasesImageBuffersByImageId()
        {
            string header = ReadRepositoryFile("PxrPlatform/Source/Extensions/PICOCameraImage.h");
            string source = ReadRepositoryFile("PxrPlatform/Source/Extensions/PICOCameraImage.cpp");

            Assert.That(header, Does.Contain("using CameraImageBufferCachePtr = std::shared_ptr<CameraImageBufferCache>;"));
            Assert.That(header, Does.Contain("std::unordered_map<XrCameraImageIdPICO, CameraImageBufferCachePtr> imageBuffers;"));
            Assert.That(header, Does.Contain("std::vector<CameraImageBufferCachePtr> reusableImageBuffers;"));
            Assert.That(source, Does.Contain("stream->imageBuffers.find(imageId)"));
            Assert.That(source, Does.Contain("stream->imageBuffers.erase(imageBuffer)"));
            Assert.That(source, Does.Contain("stream->reusableImageBuffers.push_back"));
            Assert.That(source, Does.Not.Contain("CameraImageBufferCache* bufferCache = &stream->imageBuffer;"));
        }

        [Test]
        public void CameraApi_FrameReadsAndCloseShareImageDataLock()
        {
            string cameraApi = ReadPackageFile("CameraPack/Scripts/CameraAPI/CameraAPI.cs");
            string openxrApi = ReadPackageFile("CameraPack/Scripts/CameraAPI/OpenxrCameraAPI.cs");

            Assert.That(cameraApi, Does.Contain("protected readonly object imageDataLock = new object();"));
            Assert.That(
                CountOccurrences(cameraApi, "lock (imageDataLock)"),
                Is.GreaterThanOrEqualTo(3));
            Assert.That(openxrApi, Does.Contain("lock (imageDataLock)"));
            Assert.That(openxrApi, Does.Contain("imageData = default;"));
        }

        [Test]
        public void CameraLifecycleCleanupUsesOwnerToken()
        {
            string header = ReadRepositoryFile("PxrPlatform/Source/Extensions/PICOCameraImage.h");
            string source = ReadRepositoryFile("PxrPlatform/Source/Extensions/PICOCameraImage.cpp");
            string bridge = ReadRepositoryFile("PxrPlatform/Source/MR_API.cpp");
            string plugin = ReadPackageFile("Runtime/Scripts/Utils/PXR_CameraImagePlugin.cs");
            string managed = ReadPackageFile("CameraPack/Scripts/CameraAPI/OpenxrCameraAPI.cs");

            Assert.That(header, Does.Contain("uint64_t lifecycleOwnerToken = 0;"));
            Assert.That(header, Does.Contain("bool hasLifecycleOwner = false;"));
            Assert.That(source, Does.Contain("stream->lifecycleOwnerToken != ownerToken"));
            Assert.That(bridge, Does.Contain("Pxr_CreateCameraDeviceWithOwner"));
            Assert.That(bridge, Does.Contain("Pxr_DestroyCameraDeviceWithOwner"));
            Assert.That(plugin, Does.Contain("UPxr_CreateCameraDeviceWithOwner"));
            Assert.That(plugin, Does.Contain("UPxr_DestroyCameraDeviceWithOwner"));
            Assert.That(managed, Does.Contain("private static long nextLifecycleOwnerToken;"));
            Assert.That(managed, Does.Contain("private bool isLifecycleClosing;"));
            Assert.That(managed, Does.Contain("private bool TryRegisterLifecycleOwner("));
            Assert.That(managed, Does.Contain("if (isLifecycleClosing)"));
            Assert.That(managed, Does.Contain("SetLifecycleClosing(true);"));
            Assert.That(managed, Does.Contain("SetLifecycleClosing(false);"));
            Assert.That(managed, Does.Contain("openOwnerToken = CreateLifecycleOwnerToken();"));
            Assert.That(managed, Does.Contain("openTargetCamera, openOwnerToken"));
        }

        [Test]
        public void OpenxrCameraApi_PreservesResourceFlagsWhenCleanupFails()
        {
            string source = ReadPackageFile("CameraPack/Scripts/CameraAPI/OpenxrCameraAPI.cs");
            string cleanupSource = ExtractSourceSpan(
                source,
                "private bool CleanupCameraResources",
                "private bool EndCaptureIfNeeded");
            string endCaptureSource = ExtractSourceSpan(
                source,
                "private bool EndCaptureIfNeeded",
                "private XrCameraIdPICO getCameraAvailable");

            AssertOccursBefore(
                cleanupSource,
                "if (ret == PxrResult.SUCCESS)",
                "isCaptureSessionCreated = false;");
            Assert.That(cleanupSource, Does.Contain("if (!isCaptureSessionCreated && isDeviceCreated)"));
            AssertOccursBefore(
                cleanupSource,
                "if (ret == PxrResult.SUCCESS)",
                "isDeviceCreated = false;");
            AssertOccursBefore(
                endCaptureSource,
                "if (ret != PxrResult.SUCCESS)",
                "isCaptureStarted = false;");
        }

        [Test]
        public void CameraPackBuildingBlocks_HasStereoVisualizerForLeftAndRightCameraPanels()
        {
            string source = ReadPackageFile("Editor/BuildingBlocks/PXR_BuildingBlocks.cs");
            string sectionSource = ExtractSourceSpan(
                source,
                "class PXR_CameraPackSection",
                "class PXR_BuildingBlocksAddCameraPack");
            string stereoSource = ExtractSourceSpan(
                source,
                "class PXR_BuildingBlocksAddStereoCameraPackVisualizer",
                "#endregion");

            Assert.That(sectionSource, Does.Contain("new PXR_BuildingBlocksAddStereoCameraPackVisualizer()"));
            Assert.That(stereoSource, Does.Contain("const string k_Id = \"Stereo Camera Pack Visualizer\""));
            Assert.That(stereoSource, Does.Contain("PICO Camera Pack PXRCamTextureManager Left"));
            Assert.That(stereoSource, Does.Contain("PICO Camera Pack PXRCamTextureManager Right"));
            Assert.That(stereoSource, Does.Contain("PICO Camera Pack Visualizer Left"));
            Assert.That(stereoSource, Does.Contain("PICO Camera Pack Visualizer Right"));
            Assert.That(stereoSource, Does.Contain("ConfigureCameraPackManager(leftManager, \"Left\", leftMaterial)"));
            Assert.That(stereoSource, Does.Contain("ConfigureCameraPackManager(rightManager, \"Right\", rightMaterial)"));
            Assert.That(stereoSource, Does.Contain("eyeField.SetValue(camManager, System.Enum.Parse(eyeField.FieldType, eyeName))"));
            Assert.That(stereoSource, Does.Contain("targetMaterialField.SetValue(camManager, targetMaterial)"));
            Assert.That(stereoSource, Does.Not.Contain("PXR_BuildingBlocksAddCameraPack.ExecuteMenuItem(null)"));
        }

        [Test]
        public void CameraPackFrameSnapshot_InterfaceSupportsTextureAndCpuPixelCallers()
        {
            string managerSource = ReadPackageFile("CameraPack/Scripts/PXR_CamTextureManager.cs");
            string cameraApiSource = ReadPackageFile("CameraPack/Scripts/CameraAPI/CameraAPI.cs");

            Assert.That(cameraApiSource, Does.Contain("public readonly struct PXRCameraFrameSnapshot"));
            Assert.That(cameraApiSource, Does.Contain("public readonly long Timestamp"));
            Assert.That(cameraApiSource, Does.Contain("public readonly Vector2Int Resolution"));
            Assert.That(cameraApiSource, Does.Contain("public readonly Texture Texture"));
            Assert.That(cameraApiSource, Does.Contain("public virtual bool TryGetLatestFrameSnapshot(out PXRCameraFrameSnapshot snapshot)"));
            Assert.That(cameraApiSource, Does.Contain("public virtual bool TryCopyLatestFramePixels(Color32[] buffer, out PXRCameraFrameSnapshot snapshot)"));

            string copySource = ExtractSourceSpan(
                cameraApiSource,
                "public virtual bool TryCopyLatestFramePixels",
                "public virtual Color GetPixel");
            Assert.That(copySource, Does.Contain("lock (imageDataLock)"));
            Assert.That(copySource, Does.Contain("snapshot = new PXRCameraFrameSnapshot(captureTime"));
            Assert.That(copySource, Does.Contain("Marshal.Copy(imageData.buffer, imageDataBuffer, 0, bufferSize);"));

            Assert.That(managerSource, Does.Contain("public bool TryGetLatestFrameSnapshot(out PXRCameraFrameSnapshot snapshot)"));
            Assert.That(managerSource, Does.Contain("public bool TryCopyLatestFramePixels(Color32[] buffer, out PXRCameraFrameSnapshot snapshot)"));
            Assert.That(managerSource, Does.Contain("return _cameraAPI.TryGetLatestFrameSnapshot(out snapshot);"));
            Assert.That(managerSource, Does.Contain("return _cameraAPI.TryCopyLatestFramePixels(buffer, out snapshot);"));
        }

        [Test]
        public void StereoCameraImageMatcher_MatchesTimestampsWithinOneAndDropsStaleFrames()
        {
            string source = ReadPackageFile("CameraPack/Scripts/PXR_StereoCameraImageMatcher.cs");

            Assert.That(source, Does.Contain("public class PXR_StereoCameraImageMatcher : MonoBehaviour"));
            Assert.That(source, Does.Contain("public PXR_CamTextureManager LeftManager"));
            Assert.That(source, Does.Contain("public PXR_CamTextureManager RightManager"));
            Assert.That(source, Does.Contain("public Material TargetMaterial"));
            Assert.That(source, Does.Contain("public Text StatsText"));
            Assert.That(source, Does.Contain("public long LeftFrameCount"));
            Assert.That(source, Does.Contain("public long RightFrameCount"));
            Assert.That(source, Does.Contain("public long MatchedFrameCount"));
            Assert.That(source, Does.Contain("public long DroppedLeftFrameCount"));
            Assert.That(source, Does.Contain("public long DroppedRightFrameCount"));
            Assert.That(source, Does.Contain("TryCopyLatestFramePixels(_leftPixels, out var leftSnapshot)"));
            Assert.That(source, Does.Contain("TryCopyLatestFramePixels(_rightPixels, out var rightSnapshot)"));
            Assert.That(source, Does.Contain("private const long k_TimestampMatchTolerance = 1"));
            Assert.That(source, Does.Contain("AreTimestampsMatched(leftSnapshot.Timestamp, rightSnapshot.Timestamp)"));
            Assert.That(source, Does.Contain("Math.Abs(leftTimestamp - rightTimestamp) <= k_TimestampMatchTolerance"));
            Assert.That(source, Does.Contain("leftSnapshot.Timestamp + k_TimestampMatchTolerance < rightSnapshot.Timestamp"));
            Assert.That(source, Does.Contain("rightSnapshot.Timestamp + k_TimestampMatchTolerance < leftSnapshot.Timestamp"));
            Assert.That(source, Does.Contain("DroppedLeftFrameCount++"));
            Assert.That(source, Does.Contain("DroppedRightFrameCount++"));
            Assert.That(source, Does.Contain("EnsureCombinedTexture(leftSnapshot.Resolution, rightSnapshot.Resolution)"));
            Assert.That(source, Does.Contain("_combinedTexture.SetPixels32(_combinedPixels);"));
            Assert.That(source, Does.Contain("TargetMaterial.SetTexture(_mainTexId, _combinedTexture);"));
        }

        [Test]
        public void CameraPackBuildingBlocks_HasTimestampMatchedStereoVisualizer()
        {
            string source = ReadPackageFile("Editor/BuildingBlocks/PXR_BuildingBlocks.cs");
            string sectionSource = ExtractSourceSpan(
                source,
                "class PXR_CameraPackSection",
                "class PXR_BuildingBlocksAddCameraPack");
            string blockSource = ExtractSourceSpan(
                source,
                "class PXR_BuildingBlocksAddStereoTimestampMatchedCameraPackVisualizer",
                "#endregion");

            Assert.That(sectionSource, Does.Contain("new PXR_BuildingBlocksAddStereoTimestampMatchedCameraPackVisualizer()"));
            Assert.That(blockSource, Does.Contain("const string k_Id = \"Stereo Timestamp Matched Camera Pack Visualizer\""));
            Assert.That(blockSource, Does.Contain("PICO Camera Pack Timestamp Matched PXRCamTextureManager Left"));
            Assert.That(blockSource, Does.Contain("PICO Camera Pack Timestamp Matched PXRCamTextureManager Right"));
            Assert.That(blockSource, Does.Contain("PICO Camera Pack Timestamp Matched Visualizer"));
            Assert.That(blockSource, Does.Contain("PICO Camera Pack Timestamp Matched Stats"));
            Assert.That(blockSource, Does.Contain("ByteDance.PICO.CameraPack.PXR_StereoCameraImageMatcher"));
            Assert.That(blockSource, Does.Contain("ConfigureCameraPackManager(leftManager, \"Left\", null)"));
            Assert.That(blockSource, Does.Contain("ConfigureCameraPackManager(rightManager, \"Right\", null)"));
            Assert.That(blockSource, Does.Contain("ConfigureMatcher(matcherGO, leftManager, rightManager, targetMaterial, statsText)"));
            Assert.That(blockSource, Does.Contain("return EnsureStatsText(existingStats.gameObject);"));
            Assert.That(blockSource, Does.Contain("static Text EnsureStatsText(GameObject statsRoot)"));
            Assert.That(blockSource, Does.Contain("FindCameraPackManagerComponent(leftManager, managerType)"));
            Assert.That(blockSource, Does.Contain("FindCameraPackManagerComponent(rightManager, managerType)"));
            Assert.That(blockSource, Does.Contain("GetComponentInChildren(managerType, true)"));
        }

        private static string ReadPackageFile(string relativePath)
        {
            string normalizedPath = relativePath.Replace('/', Path.DirectorySeparatorChar);
            string projectPath = Path.Combine(Directory.GetCurrentDirectory(), normalizedPath);
            if (File.Exists(projectPath))
            {
                return File.ReadAllText(projectPath);
            }

            PackageInfo packageInfo = PackageInfo.FindForAssetPath("Packages/com.bytedance.pico.xr/package.json");
            if (packageInfo != null && !string.IsNullOrEmpty(packageInfo.resolvedPath))
            {
                string packagePath = Path.Combine(packageInfo.resolvedPath, normalizedPath);
                if (File.Exists(packagePath))
                {
                    return File.ReadAllText(packagePath);
                }
            }

            throw new FileNotFoundException($"Could not find package file '{relativePath}'.", projectPath);
        }

        private static string ReadRepositoryFile(string relativePath)
        {
            string normalizedPath = relativePath.Replace('/', Path.DirectorySeparatorChar);
            string projectPath = Path.Combine(Directory.GetCurrentDirectory(), normalizedPath);
            if (File.Exists(projectPath))
            {
                return File.ReadAllText(projectPath);
            }

            PackageInfo packageInfo = PackageInfo.FindForAssetPath("Packages/com.bytedance.pico.xr/package.json");
            if (packageInfo != null && !string.IsNullOrEmpty(packageInfo.resolvedPath))
            {
                string repositoryRoot = Path.GetFullPath(Path.Combine(packageInfo.resolvedPath, ".."));
                string repositoryPath = Path.Combine(repositoryRoot, normalizedPath);
                if (File.Exists(repositoryPath))
                {
                    return File.ReadAllText(repositoryPath);
                }
            }

            throw new FileNotFoundException($"Could not find repository file '{relativePath}'.", projectPath);
        }

        private static int CountOccurrences(string source, string value)
        {
            int count = 0;
            int startIndex = 0;

            while ((startIndex = source.IndexOf(value, startIndex, StringComparison.Ordinal)) >= 0)
            {
                count++;
                startIndex += value.Length;
            }

            return count;
        }

        private static string ExtractSourceSpan(string source, string startMarker, string endMarker)
        {
            int start = source.IndexOf(startMarker, StringComparison.Ordinal);
            Assert.That(start, Is.GreaterThanOrEqualTo(0), $"Could not find start marker: {startMarker}");

            int end = source.IndexOf(endMarker, start + startMarker.Length, StringComparison.Ordinal);
            Assert.That(end, Is.GreaterThan(start), $"Could not find end marker: {endMarker}");

            return source.Substring(start, end - start);
        }

        private static void AssertOccursBefore(string source, string first, string second)
        {
            int firstIndex = source.IndexOf(first, StringComparison.Ordinal);
            int secondIndex = source.IndexOf(second, StringComparison.Ordinal);

            Assert.That(firstIndex, Is.GreaterThanOrEqualTo(0), $"Could not find first marker: {first}");
            Assert.That(secondIndex, Is.GreaterThanOrEqualTo(0), $"Could not find second marker: {second}");
            Assert.That(firstIndex, Is.LessThan(secondIndex), $"Expected '{first}' to appear before '{second}'.");
        }
    }
}
