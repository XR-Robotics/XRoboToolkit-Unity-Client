using UnityEngine;
namespace ByteDance.PICO.Interaction
{
    /// <summary>
    /// Local-space quaternion rotation utility
    /// Core: Only handles quaternion rotations around its own X/Y axes, ensuring the rotation is in local space rather than world space
    /// </summary>
    public static class QuaternionLocalRotationTool
    {
        /// <summary>
        /// Rotate a quaternion by a specified angle around its local X axis
        /// </summary>
        /// <param name="originalRot">Original quaternion (initial rotation)</param>
        /// <param name="angleX">Angle around local X axis (degrees)</param>
        /// <returns>Rotated quaternion</returns>
        public static Quaternion RotateLocalX(Quaternion originalRot, float angleX)
        {
            // Safety check: if the angle is invalid (NaN/Infinity), return the original quaternion
            if (float.IsNaN(angleX) || float.IsInfinity(angleX))
            {
                Debug.LogWarning($"[LocalRotTool] Invalid local X rotation angle: {angleX}. Returning original quaternion.");
                return originalRot;
            }

            // Step 1: build an incremental quaternion rotating around local X (Euler X,Y,Z)
            Quaternion rotStepX = Quaternion.Euler(angleX, 0f, 0f);
            // Step 2: right-multiply to rotate in local space
            Quaternion newRot = originalRot * rotStepX;
            // Normalize to avoid drift due to floating-point error
            return NormalizeQuaternion(newRot);
        }

        /// <summary>
        /// Rotate a quaternion by a specified angle around its local Y axis
        /// </summary>
        /// <param name="originalRot">Original quaternion</param>
        /// <param name="angleY">Angle around local Y axis (degrees)</param>
        /// <returns>Rotated quaternion</returns>
        public static Quaternion RotateLocalY(Quaternion originalRot, float angleY)
        {
            if (float.IsNaN(angleY) || float.IsInfinity(angleY))
            {
                Debug.LogWarning($"[LocalRotTool] Invalid local Y rotation angle: {angleY}. Returning original quaternion.");
                return originalRot;
            }

            // Build an incremental quaternion rotating around local Y
            Quaternion rotStepY = Quaternion.Euler(0f, angleY, 0f);
            // Right-multiply to rotate in local space
            Quaternion newRot = originalRot * rotStepY;
            return NormalizeQuaternion(newRot);
        }

        /// <summary>
        /// Rotate a quaternion around both local X and local Y axes (composite rotation)
        /// </summary>
        /// <param name="originalRot">Original quaternion</param>
        /// <param name="angleX">Angle around local X axis</param>
        /// <param name="angleY">Angle around local Y axis</param>
        /// <returns>Rotated quaternion</returns>
        public static Quaternion RotateLocalXY(Quaternion originalRot, float angleX, float angleY)
        {
            // Rotate X first, then Y (order can be adjusted if needed)
            Quaternion rotAfterX = RotateLocalX(originalRot, angleX);
            Quaternion rotAfterXY = RotateLocalY(rotAfterX, angleY);
            return rotAfterXY;
        }

        /// <summary>
        /// Normalize a quaternion (internal helper)
        /// Fixes magnitude drift caused by floating-point operations
        /// </summary>
        private static Quaternion NormalizeQuaternion(Quaternion quat)
        {
            // Compute quaternion magnitude
            float magnitude = Mathf.Sqrt(quat.x * quat.x + quat.y * quat.y + quat.z * quat.z + quat.w * quat.w);
            // If magnitude is close to zero, return identity; otherwise normalize
            if (magnitude < 0.001f)
                return Quaternion.identity;

            return new Quaternion(
                quat.x / magnitude,
                quat.y / magnitude,
                quat.z / magnitude,
                quat.w / magnitude
            );
        }

        #region Extension Methods (More Concise Usage)

        /// <summary>
        /// Transform extension method: rotate around local X axis (modifies rotation directly)
        /// </summary>
        public static void RotateLocalX(this Transform transform, float angleX)
        {
            if (transform == null)
            {
                Debug.LogError("[LocalRotTool] Transform is null. Cannot rotate.");
                return;
            }

            transform.rotation = RotateLocalX(transform.rotation, angleX);
        }

        /// <summary>
        /// Transform extension method: rotate around local Y axis (modifies rotation directly)
        /// </summary>
        public static void RotateLocalY(this Transform transform, float angleY)
        {
            if (transform == null)
            {
                Debug.LogError("[LocalRotTool] Transform is null. Cannot rotate.");
                return;
            }

            transform.rotation = RotateLocalY(transform.rotation, angleY);
        }

        #endregion
    }
}
