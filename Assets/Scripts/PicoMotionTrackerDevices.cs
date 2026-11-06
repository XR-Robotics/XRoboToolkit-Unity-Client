using System;
using System.Collections.Generic;
using System.Globalization;
using ByteDance.PICO.XR;
using UnityEngine;

namespace Robot
{
    internal static class PicoMotionTrackerDevices
    {
        private static readonly List<long> TrackerIds = new List<long>();
        private static readonly object Sync = new object();

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
        private static void Initialize()
        {
            lock (Sync)
                TrackerIds.Clear();
            PXR_MotionTracking.RequestMotionTrackerCompleteAction -= OnRequestComplete;
            PXR_MotionTracking.MotionTrackerConnectionAction -= OnConnection;
            PXR_MotionTracking.RequestMotionTrackerCompleteAction += OnRequestComplete;
            PXR_MotionTracking.MotionTrackerConnectionAction += OnConnection;
        }

        public static long[] GetConnectedIds()
        {
            lock (Sync)
                return TrackerIds.ToArray();
        }

        // SDK 6.1 uses numeric tracker IDs. Keep identifiers serialized as strings.
        public static string GetIdentifier(long deviceId) => deviceId.ToString(CultureInfo.InvariantCulture);

        private static void OnRequestComplete(RequestMotionTrackerCompleteEventData result)
        {
            if (result.result != PxrResult.SUCCESS)
                return;
            lock (Sync)
            {
                TrackerIds.Clear();
                int count = Math.Min((int)result.trackerCount, result.trackerIds?.Length ?? 0);
                for (int index = 0; index < count; index++)
                    OnConnection(result.trackerIds[index], 1);
            }
        }

        private static void OnConnection(long deviceId, int state)
        {
            lock (Sync)
            {
                if (state == 1 && !TrackerIds.Contains(deviceId))
                    TrackerIds.Add(deviceId);
                else if (state == 0)
                    TrackerIds.Remove(deviceId);
            }
        }

        public static ExtDevTrackerConnectState GetExternalDevices()
        {
            var state = new ExtDevTrackerConnectState { info = Array.Empty<ExtDevTrackerInfo>() };
#if PICO_XR && UNITY_ANDROID && !UNITY_EDITOR
            if (PXR_MotionTracking.GetExpandDevice(out long[] ids) != 0 || ids == null)
                return state;
            state.extNumber = ids.Length;
            state.info = new ExtDevTrackerInfo[ids.Length];
            for (int index = 0; index < ids.Length; index++)
            {
                float battery = 0f;
                XrBatteryChargingState charger = default;
                PXR_MotionTracking.GetExpandDeviceBattery(ids[index], ref battery, ref charger);
                state.info[index] = new ExtDevTrackerInfo
                {
                    trackerSN = new TrackerSN { value = GetIdentifier(ids[index]) },
                    batteryVolume = (byte)Mathf.Clamp(Mathf.RoundToInt(battery * 10f), 0, 10),
                    chargerStatus = (byte)(charger == XrBatteryChargingState.XR_MOTION_TRACKER_CHARGING_STATE_CHARGING ||
                        charger == XrBatteryChargingState.XR_MOTION_TRACKER_CHARGING_STATE_TRICKLE_CHARGING ? 0 : 1)
                };
            }
#endif
            return state;
        }
    }
}
