using System;
using System.Collections.Generic;
using UnityEngine;

namespace ByteDance.PICO.Enterprise
{
    [Serializable]
    public class IMUData
    {
        public long timestamp;
        public double vx;
        public double vy;
        public double vz;
        public double ax;
        public double ay;
        public double az;
        public double wx;
        public double wy;
        public double wz;
        public double w_ax;
        public double w_ay;
        public double w_az;
        public List<int> reservedInt;
        public List<double> reservedDouble;
        public IMUData()
        {
            timestamp = 0;
            vx = vy = vz = 0.0;
            ax = ay = az = 0.0;
            wx = wy = wz = 0.0;
            w_ax = w_ay = w_az = 0.0;
            reservedInt = new List<int>();
            reservedDouble = new List<double>();
        }
    }
  
    [Serializable]
    public class IMUDataListWrapper
    {
        public List<IMUData> IMUDatas;
    }
    public partial class JsonParser
    {
        public static IMUData ParseIMUDataFromJson(string json)
        {
            try
            {
                return JsonUtility.FromJson<IMUData>(json);
            }
            catch (Exception ex)
            {
                Debug.LogError($"JSON parse error: {ex.Message}");
                return null;
            }
        }
        public static  List<IMUData>  ParseIMUDatasFromJson(string json)
        {
            try
            {
                // Parse to wrapper class first
                IMUDataListWrapper wrapper = JsonUtility.FromJson<IMUDataListWrapper>(json);
                if (wrapper != null && wrapper.IMUDatas != null)
                {
                    return wrapper.IMUDatas;
                }
                return null;
            }
            catch (Exception ex)
            {
                Debug.LogError($"JSON parse error: {ex.Message}");
                return null;
            }
        }
        public static string IMUDataToJson(IMUData data)
        {
            try
            {
                return JsonUtility.ToJson(data);
            }
            catch (Exception ex)
            {
                Debug.LogError($"Object to JSON error: {ex.Message}");
                return null;
            }
        }
        public static string IMUDataArrayToJson(List<IMUData> datas)
        {
            try
            {
                // Create wrapper class instance
                IMUDataListWrapper wrapper = new IMUDataListWrapper
                {
                    IMUDatas = datas
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