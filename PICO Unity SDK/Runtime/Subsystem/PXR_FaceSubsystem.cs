#if AR_FOUNDATION_5 || AR_FOUNDATION_6
using System;
using Unity.Collections;
using UnityEngine;
using UnityEngine.XR.ARSubsystems;
#if ENABLE_PICO_OPENXR_SDK
using ByteDance.PICO.OpenXR;
#endif

namespace ByteDance.PICO.XR
{
    public class PXR_FaceSubsystem : XRFaceSubsystem
    {
        internal const string k_SubsystemId = "PXR_FaceSubsystem";

        public override TrackableChanges<XRFace> GetChanges(Allocator allocator)
        {
            return base.GetChanges(allocator);
        }
        [Obsolete("GetBlendShapeCoefficients is not supported..", true)]
        public unsafe static int GetBlendShapeCoefficients(ref PxrFaceTrackingInfo ftInfo)
        {
          
            return -1;
        }

        public unsafe static int GetBlendShapeCoefficients(ref PxrFacialSimulationData ftData)
        {
#if ENABLE_PICO_OPENXR_SDK
            return (int)FacialSimulationFeature.GetFacialSimulationData(0, ref ftData);
#else
            return (int)PXR_FacialSimulation.GetFacialSimulationData(0, ref ftData);
#endif
        }
        class FaceProvider : Provider
        {
            bool isFaceTrackingSupported = false;
            int inited;

            int supportedModesCount;
            XrFacialSimulationModeBD[] supportedModes;
            public override int supportedFaceCount => base.supportedFaceCount;

            public override int requestedMaximumFaceCount
            {
                get => base.requestedMaximumFaceCount;
                set => base.requestedMaximumFaceCount = value;
            }

            public override int currentMaximumFaceCount => base.currentMaximumFaceCount;

            public override void Destroy()
            {
                PLog.i(k_SubsystemId, "Destroy");
            }

            public override bool Equals(object obj)
            {
                return base.Equals(obj);
            }

            public unsafe override TrackableChanges<XRFace> GetChanges(XRFace defaultFace, Allocator allocator)
            {
                return new TrackableChanges<XRFace>();
            }

            public override int GetHashCode()
            {
                return base.GetHashCode();
            }

            public override void Start()
            {
#if ENABLE_PICO_OPENXR_SDK
                FacialSimulationFeature.GetFacialSimulationSupported(ref isFaceTrackingSupported, ref supportedModesCount, ref supportedModes);
                if (isFaceTrackingSupported)
                {
                    inited = (int)FacialSimulationFeature.StartFacialSimulation(XrFacialSimulationModeBD.XR_FACIAL_SIMULATION_MODE_DEFAULT_BD);
                }
#else
                PXR_FacialSimulation.GetFacialSimulationSupported(ref isFaceTrackingSupported, ref supportedModesCount, ref supportedModes);
                if (isFaceTrackingSupported)
                {
                    inited = (int)PXR_FacialSimulation.StartFacialSimulation(XrFacialSimulationModeBD.XR_FACIAL_SIMULATION_MODE_DEFAULT_BD);
                }
#endif
                Debug.Log($"{k_SubsystemId} Start(). isFaceTrackingSupported:{isFaceTrackingSupported}, init:{inited}");
            }

            public override void Stop()
            {
                if (isFaceTrackingSupported)
                {
#if ENABLE_PICO_OPENXR_SDK
                    inited = (int)FacialSimulationFeature.StopFacialSimulation();
#else
                    inited = (int)PXR_FacialSimulation.StopFacialSimulation();
#endif
                }
                Debug.Log($"{k_SubsystemId} Stop(). isFaceTrackingSupported:{isFaceTrackingSupported}, init:{inited}");
            }

            public override string ToString()
            {
                return base.ToString();
            }

            protected override bool TryInitialize()
            {
                return base.TryInitialize();
            }
        }

        // this method is run on startup of the app to register this provider with XR Subsystem Manager
        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void RegisterDescriptor()
        {
            PLog.i(k_SubsystemId, "RegisterDescriptor");
#if AR_FOUNDATION_5
            var descriptorParams = new FaceSubsystemParams
#endif

#if AR_FOUNDATION_6
        var descriptorParams = new XRFaceSubsystemDescriptor.Cinfo
#endif
            {
                supportsFacePose = false,
                supportsFaceMeshVerticesAndIndices = true,
                supportsFaceMeshUVs = true,
                supportsFaceMeshNormals = true,
                id = k_SubsystemId,
                providerType = typeof(FaceProvider),
                subsystemTypeOverride = typeof(PXR_FaceSubsystem)
            };

#if AR_FOUNDATION_5
            XRFaceSubsystemDescriptor.Create(descriptorParams);
#endif

#if AR_FOUNDATION_6
        XRFaceSubsystemDescriptor.Register(descriptorParams);
#endif
        }
    }
}
#endif
