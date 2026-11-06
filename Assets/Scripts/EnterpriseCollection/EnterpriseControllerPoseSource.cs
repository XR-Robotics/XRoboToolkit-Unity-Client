using System;
using System.Collections;
using System.Globalization;
using ByteDance.PICO.Enterprise;
using ByteDance.PICO.XR;
using LitJson;
using UnityEngine;
using Pose = ByteDance.PICO.Enterprise.Pose;

namespace Robot
{
    // Keep the project's Runtime-first policy outside the vendor pass-through layer.
    internal static class EnterpriseControllerPoseSource
    {
        public static Pose[] GetControllerPose(double predictTime)
        {
#if PICO_XR && UNITY_ANDROID && !UNITY_EDITOR
            AndroidJNI.AttachCurrentThread();
            if (TryGetRuntimePoses(predictTime, out Pose[] poses, out string runtimeError))
                return poses;
            if (TryGetBridgePoses(out poses, out string bridgeError))
                return poses;
            try
            {
                // The SDK adapter forwards this long argument to the same ToB binder.
                return PXR_Enterprise.GetControllerPose(0L)?.ToArray();
            }
            catch (Exception error)
            {
                throw new InvalidOperationException(runtimeError + " | " + bridgeError +
                    " | direct fallback: " + error.Message, error);
            }
#else
            return null;
#endif
        }

#if PICO_XR && UNITY_ANDROID && !UNITY_EDITOR
        private static bool TryGetRuntimePoses(double predictTime, out Pose[] poses, out string error)
        {
            poses = null;
            error = null;
            try
            {
                poses = new Pose[2];
                bool left = TryGetRuntimePose(0, predictTime, out poses[0], out string leftError);
                bool right = TryGetRuntimePose(1, predictTime, out poses[1], out string rightError);
                error = leftError + " | " + rightError;
                return left || right;
            }
            catch (Exception exception)
            {
                error = "runtime controller exception: " + exception.GetType().Name + ": " + exception.Message;
                return false;
            }
        }

        private static bool TryGetRuntimePose(uint deviceId, double predictTime, out Pose pose, out string error)
        {
            pose = null;
            error = null;
            PxrControllerTracking tracking = new PxrControllerTracking();
            int result = PXR_Plugin.Controller.UPxr_GetControllerTrackingState(
                deviceId, predictTime, ref tracking);
            if (result != 0)
            {
                error = $"runtime controller device={deviceId} result={result}";
                return false;
            }
            PxrSensorState sensor = tracking.localControllerPose;
            pose = new Pose
            {
                timestamp = unchecked((long)sensor.poseTimeStampNs),
                x = sensor.pose.position.x,
                y = sensor.pose.position.y,
                z = sensor.pose.position.z,
                rw = sensor.pose.orientation.w,
                rx = sensor.pose.orientation.x,
                ry = sensor.pose.orientation.y,
                rz = sensor.pose.orientation.z,
                type = unchecked((int)deviceId),
                confidence = sensor.status,
                poseError = result
            };
            return true;
        }

        private static bool TryGetBridgePoses(out Pose[] poses, out string error)
        {
            poses = null;
            error = null;
            try
            {
                using (var bridge = new AndroidJavaClass("com.xrobotoolkit.enterprise.EnterprisePoseBridge"))
                {
                    string json = bridge.CallStatic<string>("getControllerPoseJson", 0L);
                    JsonData root = JsonMapper.ToObject(json);
                    if (!HasKey(root, "success") || !(bool)root["success"] ||
                        !HasKey(root, "poses") || !root["poses"].IsArray)
                    {
                        error = "bridge controller failed: " + json;
                        return false;
                    }
                    JsonData items = root["poses"];
                    poses = new Pose[items.Count];
                    for (int index = 0; index < poses.Length; index++)
                    {
                        JsonData item = items[index];
                        if (item == null || !item.IsObject)
                            continue;
                        poses[index] = new Pose
                        {
                            timestamp = GetLong(item, "timestamp"),
                            x = GetDouble(item, "x"),
                            y = GetDouble(item, "y"),
                            z = GetDouble(item, "z"),
                            rw = GetDouble(item, "rw"),
                            rx = GetDouble(item, "rx"),
                            ry = GetDouble(item, "ry"),
                            rz = GetDouble(item, "rz"),
                            type = GetInt(item, "type"),
                            confidence = GetInt(item, "confidence"),
                            poseError = GetInt(item, "poseError")
                        };
                    }
                    return true;
                }
            }
            catch (Exception exception)
            {
                IntPtr pending = AndroidJNI.ExceptionOccurred();
                if (pending != IntPtr.Zero)
                {
                    AndroidJNI.ExceptionClear();
                    AndroidJNI.DeleteLocalRef(pending);
                }
                error = "bridge controller exception: " + exception.GetType().Name + ": " + exception.Message;
                return false;
            }
        }

        private static bool HasKey(JsonData data, string key) =>
            data != null && data.IsObject && ((IDictionary)data).Contains(key);

        private static long GetLong(JsonData data, string key) =>
            HasKey(data, key) ? long.Parse(data[key].ToString(), CultureInfo.InvariantCulture) : 0L;

        private static double GetDouble(JsonData data, string key) =>
            HasKey(data, key) ? double.Parse(data[key].ToString(), CultureInfo.InvariantCulture) : 0.0;

        private static int GetInt(JsonData data, string key) =>
            HasKey(data, key) ? int.Parse(data[key].ToString(), CultureInfo.InvariantCulture) : 0;
#endif
    }
}
