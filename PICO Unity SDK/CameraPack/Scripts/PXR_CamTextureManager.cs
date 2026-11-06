using System;
using System.Collections;
using System.Linq;
using UnityEngine;
using UnityEngine.Android;

#if PICO_XR_NEW
using ByteDance.PICO.XR;
#elif PICO_XR_3
using Unity.XR.PXR;
#endif

namespace ByteDance.PICO.CameraPack
{
    /// <summary>
    /// Manages the PICO Passthrough Camera access, integrating texture management and spatial utilities.
    /// Modeled after PassthroughCameraAccess.cs from QuestCameraKit.
    /// </summary>
    public class PXR_CamTextureManager : MonoBehaviour
    {
        [Header("Camera Configuration")]
        [SerializeField] public PXRCameraEye Eye = PXRCameraEye.Left;
        [SerializeField] public PXRCameraFPS FPS = PXRCameraFPS.FPS30;
        [SerializeField] public Vector2Int Resolution = new Vector2Int(640, 640);
        [SerializeField] public bool AutoOpen = true;
        [Tooltip("If set, PXRCamTextureManager will assign its internal Texture2D into this Material each frame.")]
        [SerializeField] public Material TargetMaterial;
        [Tooltip("(Optional) The name of the texture property to update. If blank, uses _MainTex.")]
        [SerializeField] private string _texturePropertyName = "";

        private Texture2D _texture;
        private CameraAPI _cameraAPI;
        private bool _isPlaying;
        private bool _hasPermission;
        private bool _hasReceivedFirstFrame;
        private Coroutine _startCameraCoroutine = null;
        private int _cameraOpenGeneration;
        private bool _cameraCleanupPending;
        // Internal state
        private int _requestedWidth;
        private int _requestedHeight;
        private int _requestedFPS;

        private string Tag = "PXRCameraPack";
        public Texture2D Texture => _texture;
        public bool IsPlaying => _isPlaying;

        /// <summary>
        /// Gets the current resolution.
        /// Returns the latest _requestedWidth and _requestedHeight dynamically.
        /// </summary>
        public Vector2Int CurrentResolution => new Vector2Int(_requestedWidth, _requestedHeight);
        
        /// <summary>
        /// Indicates if the underlying Camera API is ready.
        /// </summary>
        public bool IsSupported => _cameraAPI != null && _cameraAPI.GetSupportedState();
        
        

        private void Awake()
        {
            InitializeCameraAPI();
        }

        private void Start()
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            AskCameraPermissions();
#else
            _hasPermission = true; // Assume true in Editor for testing logic flow, though PICO API won't work
#endif
            if (AutoOpen && _hasPermission)
            {
                Play();
            }
        }
        
        private void OnEnable()
        {
            if (_hasPermission && AutoOpen && !IsPlaying)
            {
                Play();
            }
        }

        private void OnDisable()
        {
            Stop();
        }

        private void OnDestroy()
        {
            Stop();
            if (_texture != null)
            {
                Destroy(_texture);
                _texture = null;
            }
        }

        private void Update()
        {
            if (!_hasPermission) return;

            // Auto-retry initialization if permission was just granted
            if (_cameraAPI == null)
            {
                InitializeCameraAPI();
            }

            // Update status
            if (_cameraAPI != null)
            {
                var state = _cameraAPI.GetState();
                _isPlaying = state == PXRCameraStateCode.STATE_VIDEO_PREVIEWING && _hasReceivedFirstFrame;
            }
            else
            {
                _isPlaying = false;
            }

        }

        #region Public API

        /// <summary>
        /// Manually opens the camera with custom settings.
        /// This is useful if AutoOpen is disabled and you want to control when and how the camera starts.
        /// </summary>
        /// <param name="eye">The camera eye to use (Left/Right).</param>
        /// <param name="fps">The desired frame rate.</param>
        /// <param name="resolution">The desired resolution.</param>
        public void OpenCameraAsync(PXRCameraEye eye, PXRCameraFPS fps, Vector2Int resolution)
        {
            bool shouldRestartCamera = !IsCurrentConfiguration(eye, fps, resolution) && HasActiveOpenOrPendingRequest();
            if (shouldRestartCamera)
            {
                Stop();
            }

            // Update internal configuration
            Eye = eye;
            FPS = fps;
            Resolution = resolution;
            
            // Trigger Play logic
            Play();
        }

        private bool IsCurrentConfiguration(PXRCameraEye eye, PXRCameraFPS fps, Vector2Int resolution)
        {
            return Eye == eye && FPS == fps && Resolution == resolution;
        }

        private bool HasActiveOpenOrPendingRequest()
        {
            if (_startCameraCoroutine != null)
            {
                return true;
            }

            if (_cameraAPI == null)
            {
                return false;
            }

            PXRCameraStateCode state = _cameraAPI.GetState();
            return state == PXRCameraStateCode.STATE_CAMERA_OPENED ||
                   state == PXRCameraStateCode.STATE_VIDEO_PREVIEWING;
        }

        /// <summary>
        /// Gets the list of supported resolutions for the current camera.
        /// </summary>
        /// <returns>Array of supported resolutions, or empty array if not supported.</returns>
        public Vector2Int[] GetSupportedResolutions()
        {
            // Initialize API if needed (e.g. if called before Play)
            if (_cameraAPI == null)
            {
                InitializeCameraAPI();
            }

            if (_cameraAPI != null && _cameraAPI.GetCameraImageResolution(Eye, out var resolutions))
            {
                return resolutions;
            }
            return new Vector2Int[0];
        }

        /// <summary>
        /// Gets the list of supported FPS for the current camera.
        /// </summary>
        /// <returns>Array of supported FPS, or empty array if not supported.</returns>
        public PXRCameraFPS[] GetSupportedFPS()
        {
            // Initialize API if needed
            if (_cameraAPI == null)
            {
                InitializeCameraAPI();
            }

            if (_cameraAPI != null && _cameraAPI.GetCameraImageFPS(Eye, out var fps))
            {
                return fps;
            }
            return new PXRCameraFPS[0];
        }

        public void Play()
        {
            PLog.CameraLog("PXRCamTextureManager", "Play() called.");
            if (!_hasPermission)
            {
                Debug.LogError("Camera permissions not granted.");
                return;
            }

            if (_cameraAPI == null)
            {
                Debug.LogError("Camera API not initialized.");
                return;
            }

            if (_cameraCleanupPending && !CloseCameraAndTrackPendingCleanup())
            {
                Debug.LogWarning($"Camera {Eye} cleanup is still pending; Play will retry later.");
                return;
            }

            if (_cameraAPI.GetState() == PXRCameraStateCode.STATE_VIDEO_PREVIEWING)
            {
                PLog.CameraLog(Tag, $"Camera {Eye} is already previewing.");
                return;
            }

            // Unsubscribe first to avoid duplicates
            _cameraAPI.OnFirstFrameReceived -= OnFirstFrameReceived;
            _cameraAPI.OnFirstFrameReceived += OnFirstFrameReceived;

            // Determine best resolution based on supported list
            Vector2Int[] supportedResolutions = GetSupportedResolutions();
            Vector2Int finalResolution = Resolution;

            if (supportedResolutions != null && supportedResolutions.Length > 0)
            {
                // Sort by area (width * height)
                Array.Sort(supportedResolutions, (a, b) => (a.x * a.y).CompareTo(b.x * b.y));

                bool found = false;
                
                // 1. Check for exact match
                foreach (var res in supportedResolutions)
                {
                    PLog.CameraLog(Tag, $"Get supported resolution: {res}");
                    if (res.x == Resolution.x && res.y == Resolution.y)
                    {
                        finalResolution = res;
                        found = true;
                        PLog.CameraLog(Tag, $"Found exact match resolution: {finalResolution}");
                        break;
                    }
                }

                if (!found)
                {
                    // 2. Find largest supported resolution that is <= requested resolution
                    // Iterate backwards from largest to smallest
                    for (int i = supportedResolutions.Length - 1; i >= 0; i--)
                    {
                        var res = supportedResolutions[i];
                        if (res.x <= Resolution.x && res.y <= Resolution.y)
                        {
                            finalResolution = res;
                            found = true;
                            PLog.CameraLog(Tag, $"Selected largest supported resolution <= requested: {finalResolution}");
                            break;
                        }
                    }
                }

                if (!found)
                {
                    // 3. If requested resolution is smaller than the smallest supported resolution, pick the smallest supported
                    finalResolution = supportedResolutions[0];
                    PLog.CameraLog(Tag, $"Requested resolution too small, fallback to smallest supported: {finalResolution}");
                }
            }
            else
            {
                 Debug.LogWarning("PXRCamTextureManager: No supported resolutions found or API unavailable, using requested resolution directly.");
            }

            // Convert resolution enum to actual size
            
            // Determine best FPS based on supported list
            PXRCameraFPS[] supportedFPS = GetSupportedFPS();
            int finalFPS = (int)FPS;

            if (supportedFPS != null && supportedFPS.Length > 0)
            {
                // Sort supported FPS
                System.Array.Sort(supportedFPS, (a, b) => ((int)a).CompareTo((int)b));

                bool fpsFound = false;
                foreach (var f in supportedFPS)
                {
                    if ((int)f == finalFPS)
                    {
                        fpsFound = true;
                        PLog.CameraLog(Tag, $"Found exact match FPS: {finalFPS}");
                        break;
                    }
                }

                if (!fpsFound)
                {
                    // Fallback: Find the closest supported FPS
                    PXRCameraFPS bestFPS = supportedFPS[0];
                    int minDiff = int.MaxValue;
                    
                    foreach (var f in supportedFPS)
                    {
                        int diff = Mathf.Abs((int)f - finalFPS);
                        if (diff < minDiff)
                        {
                            minDiff = diff;
                            bestFPS = f;
                        }
                    }
                    finalFPS = (int)bestFPS;
                    PLog.CameraLog(Tag, $"Requested FPS {(int)FPS} not supported, fallback to closest: {finalFPS}");
                }
            }
            else
            {
                 Debug.LogWarning("PXRCamTextureManager: No supported FPS found or API unavailable, using requested FPS directly.");
            }

            _requestedWidth = finalResolution.x;
            _requestedHeight = finalResolution.y;
            _requestedFPS = Mathf.Max(1, finalFPS);

            _hasReceivedFirstFrame = false;

            // Start Camera
            PLog.CameraLog(Tag, $"Starting camera routine. Requested: {_requestedWidth}x{_requestedHeight} @ {_requestedFPS}fps");

            int openGeneration = ++_cameraOpenGeneration;
            if (_startCameraCoroutine != null)
            {
                StopCoroutine(_startCameraCoroutine);
            }
            _startCameraCoroutine = StartCoroutine(StartCameraRoutine(openGeneration));
        }


        private void OnFirstFrameReceived(int width, int height)
        {
            PLog.CameraLog(Tag, $"OnFirstFrameReceived called with {width}x{height}");
            _hasReceivedFirstFrame = true;
            
            // If dimensions mismatch what we created, recreate
            if (_texture == null || _texture.width != width || _texture.height != height)
            {
                CreateTexture(width, height);
            }
        }

        private void CreateTexture(int width, int height)
        {
            if (_texture != null)
            {
                Destroy(_texture);
            }
            
            _texture = new Texture2D(width, height, TextureFormat.RGBA32, false);
            _texture.wrapMode = TextureWrapMode.Clamp;
            _texture.filterMode = FilterMode.Bilinear;
            
            // Update internal tracking
            _requestedWidth = width;
            _requestedHeight = height;
            
            // Pass texture to underlying API
            _cameraAPI.SetTextureCameraFromUnity(_texture, width, height);
            Debug.Log($"PXRCamTextureManager: Texture created with size {width}x{height}");
            
            // Apply to material if set
            if (TargetMaterial != null)
            {
                 int propID = Shader.PropertyToID(string.IsNullOrEmpty(_texturePropertyName) ? "_MainTex" : _texturePropertyName);
                 TargetMaterial.SetTexture(propID, _texture);
            }
        }

        private IEnumerator StartCameraRoutine(int openGeneration)
        {
            var task = _cameraAPI.OpenCameraAsync(Eye, _requestedWidth, _requestedHeight, _requestedFPS);
            yield return new WaitUntil(() => task.IsCompleted);

            if (openGeneration != _cameraOpenGeneration)
            {
                if (!task.IsFaulted && !task.IsCanceled && task.Result)
                {
                    CloseCameraAndTrackPendingCleanup();
                }
                yield break;
            }

            if (task.IsFaulted)
            {
                Debug.LogError($"Failed to open camera: {task.Exception?.GetBaseException().Message}");
                _startCameraCoroutine = null;
                yield break;
            }

            if (task.IsCanceled)
            {
                Debug.LogError("Failed to open camera: operation was canceled.");
                _startCameraCoroutine = null;
                yield break;
            }

            if (task.Result)
            {
                bool success = _cameraAPI.StartPreview();
                if (success)
                {
                    // Start the frame loop only after native capture has entered preview.
                    _cameraAPI.OnCameraCreate();
                    Debug.Log($"PICO Camera Preview Started: {Eye}, {CurrentResolution.x}x{CurrentResolution.y} @ {_requestedFPS}fps");
                }
                else
                {
                    Debug.LogError("Failed to start camera preview.");
                    CloseCameraAndTrackPendingCleanup();
                }
            }
            else
            {
                Debug.LogError("Failed to open camera.");
            }

            _startCameraCoroutine = null;
        }

        public void Stop()
        {
            PLog.CameraLog(Tag, "Stop() called.");
            _cameraOpenGeneration++;
            if (_cameraAPI != null)
            {
                _cameraAPI.OnFirstFrameReceived -= OnFirstFrameReceived;

                if (_startCameraCoroutine != null)
                {
                    StopCoroutine(_startCameraCoroutine);
                    _startCameraCoroutine = null;
                }

                CloseCameraAndTrackPendingCleanup();

                // Stop the frame loop coroutine in CameraAPI
                _cameraAPI.StopAllCoroutines();
            }
            _isPlaying = false;
        }

        private bool CloseCameraAndTrackPendingCleanup()
        {
            if (_cameraAPI == null)
            {
                _cameraCleanupPending = false;
                return true;
            }

            bool success = _cameraAPI.CloseCamera();
            _cameraCleanupPending = !success;
            return success;
        }

        public Texture GetTexture()
        {
            return _texture;
        }

        public Color GetPixel(int x, int y)
        {
            if (_texture == null || _cameraAPI == null) return Color.clear;
            return _cameraAPI.GetPixel(x, y);
        }

        public bool GetPixels32(Color32[] colors)
        {
            if (colors == null || _cameraAPI == null) return false;
            return _cameraAPI.GetPixels32(colors);
        }

        public bool TryGetLatestFrameSnapshot(out PXRCameraFrameSnapshot snapshot)
        {
            snapshot = default;
            if (_cameraAPI == null)
            {
                InitializeCameraAPI();
            }

            if (_cameraAPI == null)
            {
                return false;
            }

            return _cameraAPI.TryGetLatestFrameSnapshot(out snapshot);
        }

        public bool TryCopyLatestFramePixels(Color32[] buffer, out PXRCameraFrameSnapshot snapshot)
        {
            snapshot = default;
            if (buffer == null)
            {
                return false;
            }

            if (_cameraAPI == null)
            {
                InitializeCameraAPI();
            }

            if (_cameraAPI == null)
            {
                return false;
            }

            return _cameraAPI.TryCopyLatestFramePixels(buffer, out snapshot);
        }

        #endregion

        #region Spatial Utilities (Integrated from PXRCameraUtils)
        
        
        public  Ray ScreenPointToRayInCamera(Vector2Int screenPoint)
        {
            if (_cameraAPI == null) return default;

            var Params = GetCameraIntrinsics();
            var directionInCamera = new Vector3
            {
                x = (screenPoint.x - Params.CornerPoint.x) / Params.FocalLength.x,
                y = (screenPoint.y - Params.CornerPoint.y) / Params.FocalLength.y,
                z = 1
            };

            return new Ray(Vector3.zero, directionInCamera);
        }
        
        

        /// <summary>
        /// Returns a world-space ray going from camera through a viewport point (0-1).
        /// </summary>
        public Ray ViewportPointToRayInWorld(Vector2Int viewportPoint)
        {
            if (_cameraAPI == null) return default;

            var rayInCamera = ScreenPointToRayInCamera( viewportPoint);
            var cameraPoseInWorld = GetCameraPoseInWorld();
            var rayDirectionInWorld = cameraPoseInWorld.rotation * rayInCamera.direction;
            return new Ray(cameraPoseInWorld.position, rayDirectionInWorld);
        }

        /// <summary>
        /// Transforms worldPosition from world-space into viewport-space (0-1).
        /// </summary>
        public Vector2 WorldToViewportPoint(Vector3 worldPosition)
        {
            if (_cameraAPI == null) return default;

            Pose cameraPose = GetCameraPoseInWorld();
            Vector3 localPoint = Quaternion.Inverse(cameraPose.rotation) * (worldPosition - cameraPose.position);
            
            CameraIntrinsics intrinsics = GetCameraIntrinsics();
            
            // Project to pixel coordinates
            if (localPoint.z <= 0) return Vector2.zero; // Behind camera

            float uPixel = intrinsics.FocalLength.x * (localPoint.x / localPoint.z) + intrinsics.CornerPoint.x;
            float vPixel = intrinsics.FocalLength.y * (localPoint.y / localPoint.z) + intrinsics.CornerPoint.y;

            // Normalize to 0-1
            float u = uPixel / intrinsics.Resolution.x;
            float v = vPixel / intrinsics.Resolution.y;

            return new Vector2(u, v);
        }

        public Pose GetCameraPoseInWorld()
        {
            if (_cameraAPI == null) return Pose.identity;

            CameraExtrinsics extrinsics = GetCameraExtrinsics();
            
            // Extrinsics: Camera relative to Head
            Vector3 p_cameraFromHead = extrinsics.CameraPos;
            Quaternion q_cameraFromHead = extrinsics.CameraRot;
            Pose headFromCamera = new Pose(p_cameraFromHead, q_cameraFromHead);
            
            // Head Pose in World
            Pose worldFromHead = GetHeadPose();

            // Compose: World = Head * Camera
            Pose worldFromCamera = new Pose();
            worldFromCamera.position = worldFromHead.position + worldFromHead.rotation * headFromCamera.position;
            worldFromCamera.rotation = worldFromHead.rotation * headFromCamera.rotation;

            // PICO camera coordinate system adjustment (Flip Y/Z usually needed or handled here?)
            // Original code: worldFromCamera.rotation *= Quaternion.Euler(180, 0, 0);
            worldFromCamera.rotation *= Quaternion.Euler(180, 0, 0);

            return worldFromCamera;
        }

        public CameraIntrinsics GetCameraIntrinsics()
        {
            if (_cameraAPI == null) return new CameraIntrinsics();
            _cameraAPI.GetCameraIntrinsics(Eye, out var intrinsics);
            return intrinsics;
        }

        public CameraExtrinsics GetCameraExtrinsics()
        {
            if (_cameraAPI == null) return new CameraExtrinsics();
            _cameraAPI.GetCameraExtrinsics(Eye, out var extrinsics);
            return extrinsics;
        }

        public Pose GetHeadPose()
        {
             if (_cameraAPI == null) return Pose.identity;
             
             var timestamp = PXR_Plugin.System.UPxr_GetPredictedDisplayTime();
             var sensorState = _cameraAPI.GetPredictedMainSensorState2(timestamp);
             
             return new Pose(
                 sensorState.pose.position.ToVector3FlippedZ(),
                 sensorState.pose.orientation.ToQuatFlippedZ()
             );
        }

        public Pose GetFramePose()
        {
            if (_cameraAPI == null) return Pose.identity;
            var timestamp = _cameraAPI.GetLatestTimestamp();
            var sensorState = _cameraAPI.GetPredictedMainSensorState2(timestamp);
            return new Pose(sensorState.pose.position.ToVector3FlippedZ(),
                sensorState.pose.orientation.ToQuatFlippedZ());
        }
        #endregion

        #region Internal Helpers

        private void InitializeCameraAPI()
        {
            if (_cameraAPI != null) return;

            _cameraAPI = GetComponent<CameraAPI>();

            // Use the OpenXR implementation only.
            if (_cameraAPI == null || !(_cameraAPI is OpenxrCameraAPI))
            {
                if (_cameraAPI != null) Destroy(_cameraAPI);

                _cameraAPI = gameObject.AddComponent<OpenxrCameraAPI>();
            }
        }

        private void AskCameraPermissions()
        {
            if (_hasPermission) return;
            
            string[] permissions = { "android.permission.CAMERA" };
            if (permissions.All(Permission.HasUserAuthorizedPermission))
            {
                _hasPermission = true;
            }
            else
            {
                var callbacks = new PermissionCallbacks();
                callbacks.PermissionDenied += s => _hasPermission = false;
                callbacks.PermissionGranted += s => 
                { 
                    _hasPermission = true;
                    // Auto play if granted
                    if (AutoOpen && !IsPlaying) Play();
                };
                Permission.RequestUserPermissions(permissions, callbacks);
            }
        }

        #endregion
    }
}
