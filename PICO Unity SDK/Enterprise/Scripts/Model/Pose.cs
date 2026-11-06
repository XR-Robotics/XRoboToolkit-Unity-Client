using System;
using System.Collections.Generic;
using UnityEngine;

namespace ByteDance.PICO.Enterprise
{
    [Serializable]
    public class PoseListWrapper
    {
        public List<Pose> Poses;
    }
    [Serializable]
    public class Pose
    {
        public long timestamp;
        public double x;
        public double y;
        public double z;
        public double rw;
        public double rx;
        public double ry;
        public double rz;
        public int type;
        public int confidence;
        public int poseError;
        public  List<int> reservedInt;
        public List<double> reservedDouble;
        
        
        public Pose()
        {
            timestamp = 0;
            x = 0.0;
            y = 0.0;
            z = 0.0;
            rw = 0.0;
            rx = 0.0;
            ry = 0.0;
            rz = 0.0;
            type = 0;
            confidence = 0;
            poseError = 0;
            reservedInt = new List<int>();
            reservedDouble = new List<double>();
        }
        
    }

    public partial class JsonParser
    {
        public static Pose ParsePoseFromJson(string json)
        {
            try
            {
                return JsonUtility.FromJson<Pose>(json);
            }
            catch (Exception ex)
            {
                Debug.LogError($"JSON parse error: {ex.Message}");
                return null;
            }
        }
        public static List<Pose> ParsePoseArrayFromJson(string json)
        {
            try
            {
                PoseListWrapper wrapper = JsonUtility.FromJson<PoseListWrapper>(json);
                if (wrapper != null && wrapper.Poses != null)
                {
                    return wrapper.Poses;
                }
                return null;
            }
            catch (Exception ex)
            {
                Debug.LogError($"JSON parse error: {ex.Message}");
                return null;
            }
        }

        public static string PoseToJson(Pose pose)
        {
            try
            {
                return JsonUtility.ToJson(pose);
            }
            catch (Exception ex)
            {
                Debug.LogError($"Object to JSON error: {ex.Message}");
                return null;
            }
        }
        
        public static string PoseArrayToJson(List<Pose> poses)
        {
            try
            {
                PoseListWrapper wrapper = new PoseListWrapper
                {
                    Poses =poses
                };
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