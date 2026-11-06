using System;
using System.Collections.Generic;
using UnityEngine;

namespace ByteDance.PICO.Enterprise
{
    [System.Serializable]
    public class SwiftDevice
    {
        public const int STATUS_OFFLINE = 0;
        public const int STATUS_ONLINE = 1;
        public const int POSITION_UNDEFINED = 0;
        public const int POSITION_LEFT = 1;
        public const int POSITION_RIGHT = 2;
        public const int POSITION_CENTER = 3;
        public const int BIND_NONE = 0;
        public const int BIND_DONE = 1;
        public const int ID_ALL = 0;
        public const int ID_T1 = 1;
        public const int ID_T2 = 2;
        public const int ID_T3 = 3;
        public const int CHARGE_STATUS_NONE = 0;
        public const int CHARGE_STATUS_PRE = 1;
        public const int CHARGE_STATUS_GOING = 2;
        public const int CHARGE_STATUS_DONE = 3;
        public const int BATTERY_LOW = 0;
        
        
        public int connectState;
        public int position;
        public int bindState;
        public int id;
        public string fwVersion;
        public string hwVersion;
        public string sn;
        public string addr;
        public int chargeStatus;
        public int battery;
        public int imuType;
        public int generation;
        public SwiftDevice()
        {
            connectState = 0;
            position = 0;
            bindState = 0;
            id = 0;
            fwVersion = string.Empty;
            hwVersion = string.Empty;
            sn = string.Empty;
            addr = string.Empty;
            chargeStatus = 0;
            battery = 0;
            imuType = 0;
            generation = 0;
        }
    }
    [Serializable]
    public class SwiftDeviceListWrapper
    {
        public List<SwiftDevice> SwiftDevices;
    }
    public partial class JsonParser
    {
        public static SwiftDevice ParseSwiftDeviceFromJson(string json)
        {
            try
            {
                // Use Unity's JsonUtility to parse the JSON string into a Pose object
                return JsonUtility.FromJson<SwiftDevice>(json);
            }
            catch (Exception ex)
            {
                Debug.LogError($"JSON parse error: {ex.Message}");
                return null;
            }
        }
        public static List<SwiftDevice> ParseSwiftDeviceArrayFromJson(string json)
        {
            try
            {
                // Parse to wrapper class first
                SwiftDeviceListWrapper wrapper = JsonUtility.FromJson<SwiftDeviceListWrapper>(json);
                if (wrapper != null && wrapper.SwiftDevices != null)
                {
                    return wrapper.SwiftDevices;
                }
                return null;
            }
            catch (Exception ex)
            {
                Debug.LogError($"JSON parse error: {ex.Message}");
                return null;
            }
        }
        public static string SwiftDeviceArrayToJson(List<SwiftDevice> devices)
        {
            try
            {
                // Create wrapper class instance
                SwiftDeviceListWrapper wrapper = new SwiftDeviceListWrapper
                {
                    SwiftDevices = devices
                };
                // Use JsonUtility.ToJson to convert the wrapper class object to a JSON string
                return JsonUtility.ToJson(wrapper);
            }
            catch (Exception ex)
            {
                Debug.LogError($"Object array to JSON error: {ex.Message}");
                return null;
            }
        }
    }
}