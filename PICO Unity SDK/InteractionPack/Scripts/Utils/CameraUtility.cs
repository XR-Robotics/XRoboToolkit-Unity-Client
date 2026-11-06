using UnityEngine;

namespace ByteDance.PICO.Interaction
{
    /// <summary>
    /// Camera utility class that provides cached access to Camera.main.transform, etc.
    /// </summary>
    public static class CameraUtility
    {
        private static Transform _mainCameraTransform;
        private static Camera _mainCamera;

        /// <summary>
        /// Cached main camera transform accessor
        /// </summary>
        public static Transform MainCameraTransform
        {
            get
            {
                if (_mainCameraTransform == null)
                {
                    if (_mainCamera == null)
                    {
                        _mainCamera = Camera.main;
                    }
                    
                    if (_mainCamera != null)
                    {
                        _mainCameraTransform = _mainCamera.transform;
                    }
                }
                return _mainCameraTransform;
            }
        }

        /// <summary>
        /// Cached main camera accessor
        /// </summary>
        public static Camera MainCamera
        {
            get
            {
                if (_mainCamera == null)
                {
                    _mainCamera = Camera.main;
                }
                return _mainCamera;
            }
        }

        /// <summary>
        /// Reset cached camera references
        /// Call when switching scenes or when the main camera may change
        /// </summary>
        public static void ResetCache()
        {
            _mainCamera = null;
            _mainCameraTransform = null;
        }
    }
}
