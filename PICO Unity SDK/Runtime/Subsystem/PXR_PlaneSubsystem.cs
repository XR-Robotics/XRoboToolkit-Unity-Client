#if ENABLE_PICO_XR_SDK || ENABLE_PICO_OPENXR_SDK
#if AR_FOUNDATION_5 || AR_FOUNDATION_6
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Unity.Collections;
using UnityEditor;
using UnityEngine;
using UnityEngine.XR;
using UnityEngine.XR.ARSubsystems;


namespace ByteDance.PICO.XR
{
    public class PXR_PlaneSubsystem : XRPlaneSubsystem
    {
        internal const string k_SubsystemId = "PXR_PlaneSubsystem";

        class PXR_PlaneProvider : Provider
        {
            private bool hasNewPlaneData = false;
            private List<BoundedPlane> addedPlanes = new List<BoundedPlane>();
            private List<BoundedPlane> updatedPlanes = new List<BoundedPlane>();
            private List<BoundedPlane> removedPlanes = new List<BoundedPlane>();
            
            private Dictionary<TrackableId, NativeArray<Vector2>> trackableToPlaneVertices;
            public override void Start()
            {
                PXR_Manager.PlaneDetectionDataUpdated += PlaneDetectionDataUpdated; 
                trackableToPlaneVertices = new Dictionary<TrackableId, NativeArray<Vector2>>();
                StartPlaneDetectionProvider();
            }
            
            private async void StartPlaneDetectionProvider()
            {
                var result = await PXR_MixedReality.StartSenseDataProvider(PxrSenseDataProviderType.PlaneDetection);
                if (result == PxrResult.SUCCESS)
                {
                    
                }
                else
                {
                    Debug.LogError("Spatial Anchor Provider Start Failed:" + result);
                }
            }

            private void PlaneDetectionDataUpdated(List<PxrPlaneData> planeDatas)
            {
                for (int i = 0; i < planeDatas.Count; i++)
                {
                    var bytes = planeDatas[i].uuid.ToByteArray();
                    var trackabledId = new TrackableId(BitConverter.ToUInt64(bytes, 0), BitConverter.ToUInt64(bytes, 8));
                    var boundedPlane = new BoundedPlane(trackabledId, TrackableId.invalidId,
                        new Pose(planeDatas[i].position, planeDatas[i].rotation), Vector2.zero, planeDatas[i].box2D.extent.ToVector2(),
                        ConvertPxrPlaneOrientationToPlaneAlignment(planeDatas[i].orientationMode), TrackingState.Tracking, IntPtr.Zero, ConvertPxrSemanticToPlaneClassifications(planeDatas[i].label));
                    
                    Vector2[] vectors2 = planeDatas[i].vertices.Select(v => new Vector2(v.x, v.y)).ToArray();
                    Vector2[] reversedVectors = vectors2.Reverse().ToArray();
                    var planeVertices = new NativeArray<Vector2>(reversedVectors, Allocator.Persistent);
                    
                    trackableToPlaneVertices[trackabledId] = planeVertices;
                    switch (planeDatas[i].state)
                    {
                        case MeshChangeState.Added:
                        {
                            addedPlanes.Add(boundedPlane);
                        }
                            break;
                        case MeshChangeState.Updated:
                        {
                            updatedPlanes.Add(boundedPlane);
                        }
                            break;
                        case MeshChangeState.Removed:
                        {
                            removedPlanes.Add(boundedPlane);
                        }
                            break;
                    }
                }

                hasNewPlaneData = true;
            }

            public override void Stop()
            {
                PXR_Manager.PlaneDetectionDataUpdated -= PlaneDetectionDataUpdated; 
                var result = PXR_MixedReality.StopSenseDataProvider(PxrSenseDataProviderType.PlaneDetection);
                if (result == PxrResult.SUCCESS)
                {

                }
                else
                {
                    Debug.LogError("Spatial Anchor Provider Stop Failed:" + result);
                }
            }

            public override void GetBoundary(TrackableId trackableId, Allocator allocator, ref NativeArray<Vector2> boundary)
            {
                
                if (!trackableToPlaneVertices.TryGetValue(trackableId, out NativeArray<Vector2> sourceBoundary))
                {
                    if (boundary.IsCreated)
                        boundary.Dispose();

                    return;
                }

                if (!IsConvexPolygon(sourceBoundary.ToArray()))
                {
                    var newBoundary = ConvexHull(sourceBoundary.ToArray()).ToArray();
                    if (boundary.IsCreated)
                    {
                        if (boundary.Length != newBoundary.Length)
                        {
                            boundary.Dispose();
                            boundary = new NativeArray<Vector2>(newBoundary, allocator);
                        }
                    }
                }
                else
                {
                    CreateOrResizeNativeArrayIfNecessary(sourceBoundary.Length, allocator, ref boundary);
                    NativeArray<Vector2>.Copy(sourceBoundary, boundary);
                }
            }
            
            bool IsConvexPolygon(Vector2[] vertices)
            {
                int n = vertices.Length;
                if (n < 3) return false;

                bool? isPositive = null;

                for (int i = 0; i < n; i++)
                {
                    Vector2 a = vertices[i];
                    Vector2 b = vertices[(i + 1) % n];
                    Vector2 c = vertices[(i + 2) % n];

                    Vector2 ab = b - a;
                    Vector2 bc = c - b;

                    float cross = ab.x * bc.y - ab.y * bc.x;

                    if (cross == 0) continue; 

                    if (isPositive == null)
                        isPositive = cross > 0;
                    else if ((cross > 0) != isPositive.Value)
                        return false; 
                }

                return true;
            }
            
            List<Vector2> ConvexHull(Vector2[] points)
            {
                if (points.Length <= 3)
                    return new List<Vector2>(points);

                List<Vector2> sorted = new List<Vector2>(points);
                sorted.Sort((a, b) => a.x == b.x ? a.y.CompareTo(b.y) : a.x.CompareTo(b.x));

                List<Vector2> lower = new List<Vector2>();
                foreach (var p in sorted)
                {
                    while (lower.Count >= 2 && Cross(lower[^2], lower[^1], p) <= 0)
                        lower.RemoveAt(lower.Count - 1);
                    lower.Add(p);
                }

                List<Vector2> upper = new List<Vector2>();
                for (int i = sorted.Count - 1; i >= 0; i--)
                {
                    var p = sorted[i];
                    while (upper.Count >= 2 && Cross(upper[^2], upper[^1], p) <= 0)
                        upper.RemoveAt(upper.Count - 1);
                    upper.Add(p);
                }

                lower.RemoveAt(lower.Count - 1);
                upper.RemoveAt(upper.Count - 1);

                lower.AddRange(upper);
                return lower;
            }

            float Cross(Vector2 o, Vector2 a, Vector2 b)
            {
                return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
            }

            public override void Destroy()
            {
                throw new System.NotImplementedException();
            }

            public override TrackableChanges<BoundedPlane> GetChanges(BoundedPlane defaultPlane, Allocator allocator)
            {
                if (!hasNewPlaneData)
                {
                    return new TrackableChanges<BoundedPlane>(0, 0, 0, allocator);
                }
                
                var numAddedPlanes = addedPlanes.Count;
                var numUpdatedPlanes = updatedPlanes.Count;
                var numRemovedPlanes = removedPlanes.Count;
                var changes = new TrackableChanges<BoundedPlane>(numAddedPlanes, numUpdatedPlanes, numRemovedPlanes, allocator);
                if (numAddedPlanes > 0)
                {
                    var added = changes.added;
                    for (var i = 0; i < numAddedPlanes; i++)
                    {
                        added[i] = addedPlanes[i];
                    }

                    addedPlanes.Clear();
                }
                if (numUpdatedPlanes > 0)
                {
                    var updated = changes.updated;
                    for (var i = 0; i < numUpdatedPlanes; i++)
                    {
                        updated[i] = updatedPlanes[i];
                    }

                    updatedPlanes.Clear();
                }

                if (numRemovedPlanes > 0)
                {
                    var removed = changes.removed;
                    for (var i = 0; i < numRemovedPlanes; i++)
                    {
                        removed[i] = removedPlanes[i].trackableId;
                    }

                    removedPlanes.Clear();
                }
                
                hasNewPlaneData = false;
                return changes;
            }

#if AR_FOUNDATION_5
            private PlaneClassification ConvertPxrSemanticToPlaneClassifications(PxrSemanticLabel label)
            {
                switch (label)
                {
                    case PxrSemanticLabel.Unknown:
                    case PxrSemanticLabel.Opening:
                    case PxrSemanticLabel.Human:
                    case PxrSemanticLabel.Cabinet:
                    case PxrSemanticLabel.Bed:
                    case PxrSemanticLabel.VirtualWall:
                    case PxrSemanticLabel.Screen:
                    case PxrSemanticLabel.Refrigerator:
                    case PxrSemanticLabel.Plant:
                    case PxrSemanticLabel.AirConditioner:
                    case PxrSemanticLabel.WashingMachine:
                    case PxrSemanticLabel.Stairway:
                    case PxrSemanticLabel.Lamp:
                    case PxrSemanticLabel.Curtain:
                    case PxrSemanticLabel.WallArt:
                        return PlaneClassification.Other;
                    case PxrSemanticLabel.Floor:
                        return PlaneClassification.Floor;
                    case PxrSemanticLabel.Ceiling:
                        return PlaneClassification.Ceiling;
                    case PxrSemanticLabel.Wall:
                        return PlaneClassification.Wall;
                    case PxrSemanticLabel.Door:
                        return PlaneClassification.Door;
                    case PxrSemanticLabel.Window:
                        return PlaneClassification.Window;
                    case PxrSemanticLabel.Table:
                        return PlaneClassification.Table;
                    case PxrSemanticLabel.Sofa:
                        return PlaneClassification.Seat;
                    case PxrSemanticLabel.Chair:
                        return PlaneClassification.Seat;
                    default:
                        throw new ArgumentOutOfRangeException(nameof(label), label, null);
                }
            }
#endif
            
#if AR_FOUNDATION_6
            private PlaneClassifications ConvertPxrSemanticToPlaneClassifications(PxrSemanticLabel label)
            {
                switch (label)
                {
                    case PxrSemanticLabel.Unknown:
                    case PxrSemanticLabel.Opening:
                    case PxrSemanticLabel.Human:
                    case PxrSemanticLabel.Cabinet:
                    case PxrSemanticLabel.Bed:
                    case PxrSemanticLabel.VirtualWall:
                    case PxrSemanticLabel.Screen:
                    case PxrSemanticLabel.Refrigerator:
                    case PxrSemanticLabel.Plant:
                    case PxrSemanticLabel.AirConditioner:
                    case PxrSemanticLabel.WashingMachine:
                    case PxrSemanticLabel.Stairway:
                    case PxrSemanticLabel.Lamp:
                    case PxrSemanticLabel.Curtain:
                        return PlaneClassifications.Other;
                    case PxrSemanticLabel.Floor:
                        return PlaneClassifications.Floor;
                    case PxrSemanticLabel.Ceiling:
                        return PlaneClassifications.Ceiling;
                    case PxrSemanticLabel.Wall:
                        return PlaneClassifications.WallFace;
                    case PxrSemanticLabel.Door:
                        return PlaneClassifications.DoorFrame;
                    case PxrSemanticLabel.Window:
                        return PlaneClassifications.WindowFrame;
                    case PxrSemanticLabel.Table:
                        return PlaneClassifications.Table;
                    case PxrSemanticLabel.Sofa:
                        return PlaneClassifications.Couch;
                    case PxrSemanticLabel.Chair:
                        return PlaneClassifications.Seat;
                    case PxrSemanticLabel.WallArt:
                        return PlaneClassifications.WallArt;
                    default:
                        throw new ArgumentOutOfRangeException(nameof(label), label, null);
                }
            }
#endif
            
            private PlaneAlignment ConvertPxrPlaneOrientationToPlaneAlignment(PxrPlaneOrientation orientationMode)
            {
                switch (orientationMode)
                {
                    case PxrPlaneOrientation.HorizontalUpward:
                        return PlaneAlignment.HorizontalUp;
                    case PxrPlaneOrientation.HorizontalDownward:
                        return PlaneAlignment.HorizontalDown;
                    case PxrPlaneOrientation.Vertical:
                        return PlaneAlignment.Vertical;
                    case PxrPlaneOrientation.Arbitrary:
                        return PlaneAlignment.NotAxisAligned;
                    default:
                        throw new ArgumentOutOfRangeException(nameof(orientationMode), orientationMode, null);
                }
            }
            
            public override PlaneDetectionMode requestedPlaneDetectionMode { get; set; }
        }
        
        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void RegisterDescriptor()
        {
            var cinfo = new XRPlaneSubsystemDescriptor.Cinfo
            {
                id = k_SubsystemId,
                providerType = typeof(PXR_PlaneProvider),
                subsystemTypeOverride = typeof(PXR_PlaneSubsystem),
                supportsHorizontalPlaneDetection = true,
                supportsVerticalPlaneDetection = true,
                supportsArbitraryPlaneDetection = true,
                supportsBoundaryVertices = true,
                supportsClassification = true,
            };
#if AR_FOUNDATION_5
            XRPlaneSubsystemDescriptor.Create(cinfo);
#endif
            
#if AR_FOUNDATION_6
            XRPlaneSubsystemDescriptor.Register(cinfo);
#endif
        }
    }
}
#endif
#endif
