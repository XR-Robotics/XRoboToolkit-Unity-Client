using System.Collections;
using System.Collections.Generic;
using TMPro;
using Unity.XR.PXR;
using UnityEngine;

public class EyeRotationSetter : MonoBehaviour
{
    public Transform gazePoint;
    
    void Update()
    {
        Vector3 vector;
#if UNITY_EDITOR
        vector = new Vector3(0.5f, 0.5f, 1.0f);
#else
        bool isTracking = false;
        EyeTrackingState state = new EyeTrackingState();
        PXR_MotionTracking.GetEyeTrackingState(ref isTracking, ref state);
        if (isTracking)
        {
            PXR_EyeTracking.GetCombineEyeGazeVector(out vector);
        }
        else
        {
            vector = new Vector3(0.0f, 0.0f, 1.0f);
        }
#endif
        gazePoint.localPosition = vector;
        transform.LookAt(gazePoint);
    }
}
