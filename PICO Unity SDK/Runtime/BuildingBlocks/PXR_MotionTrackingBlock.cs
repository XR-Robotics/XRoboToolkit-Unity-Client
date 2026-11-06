#if ENABLE_PICO_XR_SDK || ENABLE_PICO_OPENXR_SDK
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Rendering;

namespace ByteDance.PICO.XR
{
    public class PXR_MotionTrackingBlock : MonoBehaviour
    {
        private Transform motionTrackers;
        private bool updateMotionTracking = true;
        private int motionTrackersMaxNum = 3;
        int DeviceCount = 1;
        List<long> trackerIds = new List<long>();


        // Start is called before the first frame update
        void Start()
        {
            motionTrackers = transform;
            for (int i = 0; i < motionTrackersMaxNum; i++)
            {
                GameObject ga = GameObject.CreatePrimitive(PrimitiveType.Cube);
                ga.transform.parent = motionTrackers;
                ga.transform.localScale = Vector3.one * 0f;
#if UNITY_6000_0_OR_NEWER
            if (GraphicsSettings.defaultRenderPipeline != null)
#else
                if (GraphicsSettings.renderPipelineAsset != null)
#endif
                {
                    Material material = new Material(Shader.Find("Universal Render Pipeline/Lit"));
                    Renderer renderer = ga.GetComponent<Renderer>();
                    if (renderer != null)
                    {
                        renderer.sharedMaterial = material;
                    }
                }
            }

            int res = -1;
#if ENABLE_PICO_OPENXR_SDK
#else
            PXR_MotionTracking.RequestMotionTrackerCompleteAction += RequestMotionTrackerComplete;
            res = PXR_MotionTracking.CheckMotionTrackerNumber(MotionTrackerNum.TWO);
#endif


            if (res == 0)
            {
                motionTrackers.gameObject.SetActive(true);

            }
        }

        private void RequestMotionTrackerComplete(RequestMotionTrackerCompleteEventData obj)
        {
            DeviceCount = (int)obj.trackerCount;
            for (int i = 0; i < DeviceCount; i++)
            {
                trackerIds.Add(obj.trackerIds[i]);
            }

            updateMotionTracking = true;
        }

        // Update is called once per frame
        void Update()
        {

            for (int i = 0; i < motionTrackersMaxNum; i++)
            {
                var child = motionTrackers.GetChild(i);
                if (child)
                {
                    child.localScale = Vector3.zero;
                }
            }

            // Update motiontrackers pose.
            if (updateMotionTracking)
            {
                MotionTrackerLocation location = new MotionTrackerLocation();
                for (int i = 0; i < trackerIds.Count; i++)
                {
                    bool isValidPose = false;
                    int result = -1;
#if ENABLE_PICO_OPENXR_SDK
#else
                    result = PXR_MotionTracking.GetMotionTrackerLocation(trackerIds[i], ref location, ref isValidPose);
#endif
                    // if the return is successful
                    if (result == 0)
                    {
                        var child = motionTrackers.GetChild(i);
                        if (child)
                        {
                            child.localPosition = location.pose.Position.ToVector3();
                            child.localRotation = location.pose.Orientation.ToQuat();
                            child.localScale = Vector3.one * 0.1f;
                        }
                    }
                }
            }
        }
    }
}
#endif
