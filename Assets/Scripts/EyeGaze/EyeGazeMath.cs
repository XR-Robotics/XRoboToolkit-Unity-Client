using UnityEngine;

namespace Robot
{
    public static class EyeGazeMath
    {
        [System.Flags]
        private enum CombinedEyePoseValidity : uint
        {
            GazePointValid = 1u << 0,
            GazeVectorValid = 1u << 1
        }

        /// <summary>Accept the documented Boolean status and Swan's gaze validity flags.</summary>
        public static bool IsCombinedEyePoseValid(uint status)
        {
            const uint documentedAvailableStatus = 1u;
            const CombinedEyePoseValidity required = CombinedEyePoseValidity.GazePointValid |
                                                     CombinedEyePoseValidity.GazeVectorValid;
            return status == documentedAvailableStatus ||
                   ((CombinedEyePoseValidity)status & required) == required;
        }

        public static bool IsFinite(Vector3 value)
        {
            return IsFinite(value.x) && IsFinite(value.y) && IsFinite(value.z);
        }

        private static bool IsFinite(float value)
        {
            return !float.IsNaN(value) && !float.IsInfinity(value);
        }

        /// <summary>Convert the SDK's camera-local eye origin and direction to a world ray.</summary>
        public static bool TryCreateWorldRay(Transform cameraTransform, Vector3 localOrigin,
            Vector3 localDirection, out Ray ray)
        {
            ray = default;
            if (cameraTransform == null || !IsFinite(localOrigin) || !IsFinite(localDirection))
                return false;

            float magnitude = localDirection.magnitude;
            if (!IsFinite(magnitude) || magnitude < 0.000001f)
                return false;

            Vector3 origin = cameraTransform.TransformPoint(localOrigin);
            Vector3 direction = cameraTransform.TransformDirection(localDirection / magnitude);
            if (!IsFinite(origin) || !IsFinite(direction) || direction.sqrMagnitude < 0.000001f)
                return false;

            ray = new Ray(origin, direction.normalized);
            return true;
        }
    }
}
