#if AR_FOUNDATION_5 || AR_FOUNDATION_6
using System;
using System.Collections;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Tasks;
using Unity.Collections;
using UnityEngine;
using UnityEngine.XR.ARSubsystems;
#if PICO_MS_SDK && AR_FOUNDATION_6
using ByteDance.PICO.SpatialAdapter;
using ByteDance.PICO.Spatial.Stage;
#endif
using TrackableId = UnityEngine.XR.ARSubsystems.TrackableId;

namespace ByteDance.PICO.XR
{
    public class PXR_AnchorSubsystem : XRAnchorSubsystem
    {
        internal const string k_SubsystemId = "PXR_AnchorSubsystem";

        public class PXR_AnchorProvider : Provider
        {
#if PICO_MS_SDK && AR_FOUNDATION_6
            private Dictionary<TrackableId, XRAnchor> rackableIdToXRAnchorMap;
            private Spatial.Stage.FrameAnchorData frameAnchorData = new Spatial.Stage.FrameAnchorData();
            private NativeArray<XRAnchor> addedAnchors;
            private NativeArray<XRAnchor> updatedAnchors;
            private NativeArray<TrackableId> removedAnchors;
#else
            private Dictionary<TrackableId, ulong> trackableIdToHandleMap;
            private Dictionary<ulong, XRAnchor> handleToXRAnchorMap;
            private HashSet<ulong> managedAnchorHandles;
            private Dictionary<Guid, ulong> lastAnchorToTime;
#endif
            private bool isInit = false;

            public override void Start()
            {
#if ENABLE_PICO_XR_SDK || ENABLE_PICO_OPENXR_SDK
                StartSpatialAnchorProvider();
#elif PICO_MS_SDK && AR_FOUNDATION_6
                if (!isInit)
                {
                    rackableIdToXRAnchorMap = new Dictionary<TrackableId, XRAnchor>();
                    isInit = true;
                }
#endif
            }

            public override void Stop()
            {
#if ENABLE_PICO_XR_SDK || ENABLE_PICO_OPENXR_SDK
                var result = PXR_MixedReality.StopSenseDataProvider(PxrSenseDataProviderType.SpatialAnchor);
                if (result == PxrResult.SUCCESS)
                {
                }
                else
                {
                    Debug.LogError("Spatial Anchor Provider Stop Failed:" + result);
                }
#endif
            }

            public override void Destroy()
            {
#if PICO_MS_SDK && AR_FOUNDATION_6
                addedAnchors.Dispose();
                updatedAnchors.Dispose();
                removedAnchors.Dispose();
#endif
            }

            public unsafe override TrackableChanges<XRAnchor> GetChanges(XRAnchor defaultAnchor, Allocator allocator)
            {
#if PICO_MS_SDK && AR_FOUNDATION_6
                SpatialNativeApi.Pmp_GetFrameAnchorData(ref frameAnchorData);
                
                void* addedAnchorPtr = null;
                if (frameAnchorData.addedAnchorCount > 0)
                {
                    addedAnchorPtr = (void*)frameAnchorData.addedAnchors;
                   
                }

                void* updatedAnchorPtr = null;
                if (frameAnchorData.updatedAnchorCount > 0)
                {
                    updatedAnchorPtr = (void*)frameAnchorData.updatedAnchors;
                }

                void* removedAnchorPtr = null;
                if (frameAnchorData.removedAnchorCount > 0)
                {
                    removedAnchorPtr = (void*)frameAnchorData.removedAnchors;
                }

                var trackableChanges = new TrackableChanges<XRAnchor>(
                    addedAnchorPtr,
                    frameAnchorData.addedAnchorCount,
                    updatedAnchorPtr,
                    frameAnchorData.updatedAnchorCount,
                    removedAnchorPtr,
                    frameAnchorData.removedAnchorCount,
                    defaultAnchor, sizeof(XRAnchor), allocator);

                return trackableChanges;
#else
                return new TrackableChanges<XRAnchor>();
#endif
            }

#if ENABLE_PICO_XR_SDK || ENABLE_PICO_OPENXR_SDK
            private async void StartSpatialAnchorProvider()
            {
                var result = await PXR_MixedReality.StartSenseDataProvider(PxrSenseDataProviderType.SpatialAnchor);
                if (result == PxrResult.SUCCESS)
                {
                    if (!isInit)
                    {
                        trackableIdToHandleMap = new Dictionary<TrackableId, ulong>();
                        handleToXRAnchorMap = new Dictionary<ulong, XRAnchor>();
                        managedAnchorHandles = new HashSet<ulong>();
                        isInit = true;
                    }
                }
                else
                {
                    Debug.LogError("Spatial Anchor Provider Start Failed:" + result);
                }
            }
#endif

#if PICO_MS_SDK && AR_FOUNDATION_6
            public enum ResultMsg
            {
                Unknown = int.MaxValue,
                SUCCESS = 0,
                PENDING = 1,
                FAILED = -1,
                TIMEOUT = -2,
            }
            public static async Task<ResultMsg> RemoveAnchorAsync(TrackableId trackableId)
            {
                Debug.Log($"[MultiSpatialPlatform] RemoveAnchorAsync retry {trackableId}");
                return await Task.Run(async () =>
               {
                   var loadResult = (ResultMsg)SpatialNativeApi.Pmp_RemoveAnchorAsync(trackableId);
                   if (loadResult == ResultMsg.SUCCESS)
                   {
                       int retryCount = 0;
                       int baseDelay = 5;
                       DateTime startTime = DateTime.Now;
                       TimeSpan maxWaitTime = TimeSpan.FromSeconds(5);
                       while (DateTime.Now - startTime < maxWaitTime)
                       {
                           var completeResult = (ResultMsg)SpatialNativeApi.Pmp_RemoveAnchorComplete(trackableId);
                           if (completeResult == ResultMsg.SUCCESS)
                           {
                               return (completeResult);
                           }
                           else if (completeResult == ResultMsg.PENDING)
                           {
                               if (retryCount > 10)
                               {
                                   Debug.LogError($"RemoveAnchorAsync retry {retryCount}");
                                   return (ResultMsg.TIMEOUT);
                               }
                               retryCount++;
                               int delay = baseDelay * (int)Math.Pow(2, Math.Min(retryCount, 4));
                               await Task.Delay(delay);
                           }
                           else
                           {
                               Debug.LogError($"RemoveAnchorAsync completeResult {completeResult}");
                               return (completeResult);
                           }
                       }
                       Debug.LogError($"RemoveAnchorAsync timed out after {maxWaitTime.TotalSeconds} seconds.");
                       return (ResultMsg.TIMEOUT);
                   }
                   else
                   {
                       Debug.LogError($"RemoveAnchorAsync loadResult {loadResult}");
                       return (loadResult);
                   }
               });
            }
            public static async Task<(ResultMsg result, XRAnchor xrAnchor)> LoadAnchorAsync(TrackableId trackableId)
            {
                // Debug.Log($"[MultiSpatialPlatform] LoadAnchorAsync retry {trackableId}");
                XRAnchor anchor = new XRAnchor(trackableId, Pose.identity, TrackingState.None, IntPtr.Zero);
                return await Task.Run(async () =>
               {
                   var loadResult = (ResultMsg)SpatialNativeApi.Pmp_LoadAnchorAsync(trackableId, ref anchor);
                   if (loadResult == ResultMsg.SUCCESS)
                   {
                       int retryCount = 0;
                       int baseDelay = 5;
                       DateTime startTime = DateTime.Now;
                       TimeSpan maxWaitTime = TimeSpan.FromSeconds(5);
                       while (DateTime.Now - startTime < maxWaitTime)
                       {
                           var completeResult = (ResultMsg)SpatialNativeApi.Pmp_LoadAnchorComplete(trackableId, ref anchor);
                           if (completeResult == ResultMsg.SUCCESS)
                           {
                               return (completeResult, anchor);
                           }
                           else if (completeResult == ResultMsg.PENDING)
                           {
                               if (retryCount > 10)
                               {
                                   Debug.LogError($"LoadAnchorAsync retry {retryCount}");
                                   return (ResultMsg.TIMEOUT, XRAnchor.defaultValue);
                               }
                               retryCount++;
                               int delay = baseDelay * (int)Math.Pow(2, Math.Min(retryCount, 4));
                               await Task.Delay(delay);
                           }
                           else
                           {
                               Debug.LogError($"LoadAnchorAsync completeResult {completeResult}");
                               return (completeResult, XRAnchor.defaultValue);
                           }
                       }
                       Debug.LogError($"LoadAnchorAsync timed out after {maxWaitTime.TotalSeconds} seconds.");
                       return (ResultMsg.TIMEOUT, XRAnchor.defaultValue);
                   }
                   else
                   {
                       Debug.LogError($"LoadAnchorAsync loadResult {loadResult}");
                       return (loadResult, XRAnchor.defaultValue);
                   }
               });
            }
            public static async Task<(ResultMsg result, XRAnchor xrAnchor)> CreateAnchorAsync(TrackableId trackableId, Pose pose)
            {
                XRAnchor anchor = new XRAnchor(trackableId, pose, TrackingState.None, IntPtr.Zero);
                return await Task.Run(async () =>
                {
                    var createResult = (ResultMsg)SpatialNativeApi.Pmp_CreateAnchor(trackableId,ref anchor);

                    if (createResult == ResultMsg.SUCCESS)
                    {
                        int retryCount = 0;
                        int baseDelay = 5;
                        DateTime startTime = DateTime.Now;
                        TimeSpan maxWaitTime = TimeSpan.FromSeconds(5);
                        while (DateTime.Now - startTime < maxWaitTime)
                        {
                            var completeResult = (ResultMsg)SpatialNativeApi.Pmp_CreateAnchorComplete(trackableId,ref anchor);
                            if (completeResult == ResultMsg.SUCCESS)
                            {
                                return (completeResult, anchor);
                            }
                            else if (completeResult == ResultMsg.PENDING)
                            {
                                if (retryCount>10)
                                {
                                    Debug.LogError($"CreateAnchorAsync retry {retryCount}");
                                    return (ResultMsg.TIMEOUT, XRAnchor.defaultValue);
                                }
                                retryCount++;
                                int delay = baseDelay * (int)Math.Pow(2, Math.Min(retryCount, 4));
                                await Task.Delay(delay);
                            }
                            else
                            {
                                Debug.LogError($"Anchor creation failed with result: {completeResult}");
                                return (completeResult, XRAnchor.defaultValue);
                            }
                        }

                        Debug.LogError($"Anchor creation timed out after {maxWaitTime.TotalSeconds} seconds.");
                        return (ResultMsg.TIMEOUT, XRAnchor.defaultValue);
                    }
                    else
                    {
                        Debug.LogError($"Initial anchor creation failed with result: {createResult}");
                        return (createResult, XRAnchor.defaultValue);
                    }
                });
            }
#endif

#if AR_FOUNDATION_5
#if ENABLE_PICO_XR_SDK || ENABLE_PICO_OPENXR_SDK
            public override bool TryAddAnchor(Pose pose, out XRAnchor anchor)
            {

                var tcs = new TaskCompletionSource<(PxrResult result, ulong anchorHandle, Guid uuid)>();
                var tcs2 = new TaskCompletionSource<PxrResult>();
                Task.Run(() =>
                {
                    var (pxrResult, handle, guid) =
                        PXR_MixedReality.CreateSpatialAnchorAsync(pose.position, pose.rotation).Result;

                    tcs.SetResult((pxrResult, handle, guid));
                });
                var (result, anchorHandle, uuid) = tcs.Task.Result;
                if (result == PxrResult.SUCCESS)
                {
                    Task.Run(() =>
                    {
                        var pxrResult = PXR_MixedReality.PersistSpatialAnchorAsync(anchorHandle).Result;

                        tcs2.SetResult(pxrResult);
                    });

                    var result2 = tcs2.Task.Result;
                    if (result2 == PxrResult.SUCCESS)
                    {
                        var bytes = uuid.ToByteArray();
                        var trackabledId = new TrackableId(BitConverter.ToUInt64(bytes, 0),
                            BitConverter.ToUInt64(bytes, 8));
                        var nativePtr = new IntPtr((long)anchorHandle);
                        anchor = new XRAnchor(trackabledId, pose, TrackingState.Tracking, nativePtr);
                        trackableIdToHandleMap[trackabledId] = anchorHandle;
                        handleToXRAnchorMap[anchorHandle] = anchor;
                        return true;
                    }
                    else
                    {
                        anchor = XRAnchor.defaultValue;
                        return false;
                    }
                }
                else
                {
                    anchor = XRAnchor.defaultValue;
                    return false;
                }
// #elif PICO_MS_SDK
//                 ulong subId1 = GetRandomULong();
//                 ulong subId2 = GetRandomULong();
                
//                 TrackableId randomTrackableId = new TrackableId(subId1, subId2);
//                 var tcs = new TaskCompletionSource<(ResultMsg result, XRAnchor anchorHandle)>();
//                 Task.Run(() =>
//                 {
//                     var (pxrResult, handle) = CreateAnchorAsync(randomTrackableId,pose).Result;

//                     tcs.SetResult((pxrResult, handle));
//                 });
//                 var (result, anchorHandle) = tcs.Task.Result;
//                 if (result == ResultMsg.SUCCESS)
//                 {
//                     anchor = anchorHandle;
//                     return true;
//                 }
//                 else
//                 {
//                     anchor = XRAnchor.defaultValue;
//                     return false;
//                 }
// #else
                 anchor = XRAnchor.defaultValue;
                 return false;
            }

            public override bool TryRemoveAnchor(TrackableId anchorId)
            {
                if (trackableIdToHandleMap.TryGetValue(anchorId, out var anchorHandle))
                {
                    var result = PXR_MixedReality.DestroyAnchor(anchorHandle);
                    if (result == PxrResult.SUCCESS)
                    {
                        var tcs = new TaskCompletionSource<PxrResult>();
                        Task.Run(() =>
                        {
                            var pxrResult = PXR_MixedReality.UnPersistSpatialAnchorAsync(anchorHandle).Result;

                            tcs.SetResult(pxrResult);
                        });
                        var result1 = tcs.Task.Result;
                        if (result1 == PxrResult.SUCCESS)
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
// #elif PICO_MS_SDK
//                 return SpatialNativeApi.Pmp_RemoveAnchor(anchorId) == 0;
// #else
                 return false;
                
            }
#endif
#endif
            private ulong GetRandomULong()
            {
                System.Random random = new System.Random();
                ulong high = ((ulong)random.Next(int.MinValue, int.MaxValue)) << 32;
                ulong low = (uint)random.Next(int.MinValue, int.MaxValue);
                
                return high | low;
            }
#if AR_FOUNDATION_6

            public override Awaitable<Result<XRAnchor>> TryAddAnchorAsync(Pose pose)
            {
                var synchronousResultStatus = new XRResultStatus(XRResultStatus.StatusCode.UnknownError);
                var awaitable = new AwaitableCompletionSource<Result<XRAnchor>>();
                var anchor = XRAnchor.defaultValue;
               

#if ENABLE_PICO_XR_SDK || ENABLE_PICO_OPENXR_SDK
                var tcs = new TaskCompletionSource<(PxrResult result, ulong anchorHandle, Guid uuid)>();
                Task.Run(() =>
                {
                    var (pxrResult, handle, guid) =
 PXR_MixedReality.CreateSpatialAnchorAsync(pose.position, pose.rotation).Result;

                    tcs.SetResult((pxrResult, handle, guid));
                });
                var (result, anchorHandle, uuid) = tcs.Task.Result;
                if (result == PxrResult.SUCCESS)
                {
                    var bytes = uuid.ToByteArray();
                    var trackabledId =
 new TrackableId(BitConverter.ToUInt64(bytes, 0), BitConverter.ToUInt64(bytes, 8));
                    var nativePtr = new IntPtr((long)anchorHandle);
                    synchronousResultStatus = new XRResultStatus(XRResultStatus.StatusCode.UnqualifiedSuccess);
                    anchor = new XRAnchor(trackabledId, pose, TrackingState.Tracking, nativePtr);
                    trackableIdToHandleMap[trackabledId] = anchorHandle;
                    handleToXRAnchorMap[anchorHandle] = anchor;
                }

                var returnResult = new Result<XRAnchor>(synchronousResultStatus, anchor);
                awaitable.SetResult(returnResult);
                return awaitable.Awaitable;
#elif PICO_MS_SDK
                ulong subId1 = GetRandomULong();
                ulong subId2 = GetRandomULong();
                
                TrackableId randomTrackableId = new TrackableId(subId1, subId2);
                var tcs = new TaskCompletionSource<(ResultMsg result, XRAnchor anchorHandle)>();
                Task.Run(() =>
                {
                    var (pxrResult, handle) = CreateAnchorAsync(randomTrackableId,pose).Result;

                    tcs.SetResult((pxrResult, handle));
                });
                var (result, anchorHandle) = tcs.Task.Result;
                if (result == ResultMsg.SUCCESS)
                {
                    anchor = anchorHandle;
                    synchronousResultStatus = new XRResultStatus(XRResultStatus.StatusCode.UnqualifiedSuccess);
                    rackableIdToXRAnchorMap[anchor.trackableId] = anchorHandle;
                    Debug.Log($"Add Anchor Success, trackableId: {anchor.trackableId}, anchorHandle: {anchorHandle}");
                }
               
                var returnResult = new Result<XRAnchor>(synchronousResultStatus, anchor);
                awaitable.SetResult(returnResult);
                return awaitable.Awaitable;
#else

                var returnResult = new Result<XRAnchor>(synchronousResultStatus, anchor);
                awaitable.SetResult(returnResult);
                return awaitable.Awaitable;
#endif
            }

            public override Awaitable<Result<SerializableGuid>> TrySaveAnchorAsync(TrackableId anchorId, CancellationToken cancellationToken
 = default)
            {
                var tcs2 = new TaskCompletionSource<PxrResult>();
                var synchronousResultStatus = new XRResultStatus(XRResultStatus.StatusCode.UnknownError);
                var awaitable = new AwaitableCompletionSource<Result<SerializableGuid>>();
                var returnResult = new Result<SerializableGuid>(synchronousResultStatus, default);
#if ENABLE_PICO_XR_SDK || ENABLE_PICO_OPENXR_SDK
                if (trackableIdToHandleMap.TryGetValue(anchorId, out var anchorHandle))
                {
                    Task.Run(() =>
                    {
                        var pxrResult =
 PXR_MixedReality.PersistSpatialAnchorAsync(anchorHandle, cancellationToken).Result;

                        tcs2.SetResult(pxrResult);
                    });

                    var result2 = tcs2.Task.Result;
                    if (result2 == PxrResult.SUCCESS)
                    {
                        synchronousResultStatus = new XRResultStatus(XRResultStatus.StatusCode.UnqualifiedSuccess);
                        returnResult = new Result<SerializableGuid>(synchronousResultStatus, anchorId);
                    }
                    else
                    {
                        synchronousResultStatus =
 new XRResultStatus(XRResultStatus.StatusCode.PlatformError, (int)result2);
                        returnResult = new Result<SerializableGuid>(synchronousResultStatus, default);
                    }

                }
                awaitable.SetResult(returnResult);
                return awaitable.Awaitable;
#elif PICO_MS_SDK
                if (rackableIdToXRAnchorMap.TryGetValue(anchorId, out var anchorHandle))
                {
                    SpatialNativeApi.Pmp_PersistSpatialAnchorAsync(anchorId);
                    synchronousResultStatus = new XRResultStatus(XRResultStatus.StatusCode.UnqualifiedSuccess);
                    returnResult = new Result<SerializableGuid>(synchronousResultStatus, anchorId);
                    awaitable.SetResult(returnResult);
                }

                return awaitable.Awaitable;
#else
                return awaitable.Awaitable;
#endif
            }

            public override Awaitable<XRResultStatus> TryEraseAnchorAsync(SerializableGuid savedAnchorGuid, CancellationToken cancellationToken
 = default)
            {
              
                var synchronousResultStatus = new XRResultStatus(XRResultStatus.StatusCode.UnknownError);
                var awaitable = new AwaitableCompletionSource<XRResultStatus>();

#if ENABLE_PICO_XR_SDK || ENABLE_PICO_OPENXR_SDK
                var tcs = new TaskCompletionSource<PxrResult>();
                if (trackableIdToHandleMap.TryGetValue(savedAnchorGuid, out var anchorHandle))
                {
                    Task.Run(() =>
                    {
                        var pxrResult =
 PXR_MixedReality.UnPersistSpatialAnchorAsync(anchorHandle, cancellationToken).Result;

                        tcs.SetResult(pxrResult);
                    });
                    var result1 = tcs.Task.Result;
                    if (result1 == PxrResult.SUCCESS)
                    {
                        synchronousResultStatus = new XRResultStatus(XRResultStatus.StatusCode.UnqualifiedSuccess);
                    }
                    else
                    {
                        synchronousResultStatus =
 new XRResultStatus(XRResultStatus.StatusCode.PlatformError, (int)result1);
                    }
                }
                awaitable.SetResult(synchronousResultStatus);
                return awaitable.Awaitable;
#elif PICO_MS_SDK
                var tcs = new TaskCompletionSource<ResultMsg>();
                if (rackableIdToXRAnchorMap.TryGetValue(savedAnchorGuid, out var anchorHandle))
                {
                    Task.Run(() =>
                    {
                        var pxrResult = RemoveAnchorAsync(savedAnchorGuid).Result;
                        tcs.SetResult((pxrResult));
                    });
                    var result = tcs.Task.Result;
                    if (result == ResultMsg.SUCCESS)
                    {

                        synchronousResultStatus = new XRResultStatus(XRResultStatus.StatusCode.UnqualifiedSuccess);
                        rackableIdToXRAnchorMap.Remove(savedAnchorGuid);
                    }
                    else
                    {
                        synchronousResultStatus = new XRResultStatus(XRResultStatus.StatusCode.PlatformError, (int)result);
                    }
                    awaitable.SetResult(synchronousResultStatus);
                    return awaitable.Awaitable;
                }
                return awaitable.Awaitable;
#else
                return awaitable.Awaitable;
#endif
            }

            public override bool TryRemoveAnchor(TrackableId anchorId)
            {
#if ENABLE_PICO_XR_SDK || ENABLE_PICO_OPENXR_SDK
                if (trackableIdToHandleMap.TryGetValue(anchorId, out var anchorHandle))
                {
                    var result = PXR_MixedReality.DestroyAnchor(anchorHandle);
                    if (result == PxrResult.SUCCESS)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
#else
                return false;
#endif
            }


            public override Awaitable<Result<XRAnchor>> TryLoadAnchorAsync(SerializableGuid savedAnchorGuid, CancellationToken cancellationToken
 = default)
            {
           
                var synchronousResultStatus = new XRResultStatus(XRResultStatus.StatusCode.UnknownError);
                var awaitable = new AwaitableCompletionSource<Result<XRAnchor>>();
                var anchor = XRAnchor.defaultValue;
              
#if ENABLE_PICO_XR_SDK || ENABLE_PICO_OPENXR_SDK
                var tcs = new TaskCompletionSource<(PxrResult result, List<ulong> anchorHandleList)>();
                var guid = savedAnchorGuid.guid;
                Guid[] guids = { guid };
                Task.Run(() =>
                {
                    var pxrResult = PXR_MixedReality.QuerySpatialAnchorAsync(guids).Result;

                    tcs.SetResult(pxrResult);
                });
                var result1 = tcs.Task.Result;
                if (result1.result == PxrResult.SUCCESS)
                {
                    for (int i = 0; i < result1.anchorHandleList.Count; i++)
                    {
                        var nativePtr = new IntPtr((long)result1.anchorHandleList[i]);
                        synchronousResultStatus = new XRResultStatus(XRResultStatus.StatusCode.UnqualifiedSuccess);
                        PXR_MixedReality.LocateAnchor(result1.anchorHandleList[i], out var position, out var quaternion);
                        anchor =
 new XRAnchor(savedAnchorGuid, new Pose(position,quaternion), TrackingState.Tracking, nativePtr);

                        trackableIdToHandleMap[savedAnchorGuid] = result1.anchorHandleList[i];
                        handleToXRAnchorMap[result1.anchorHandleList[i]] = anchor;
                    }
                }
                var returnResult = new Result<XRAnchor>(synchronousResultStatus, anchor);
                awaitable.SetResult(returnResult);
                return awaitable.Awaitable;
#elif PICO_MS_SDK
                var tcs = new TaskCompletionSource<(ResultMsg result, XRAnchor anchorHandle)>();
                Task.Run(() =>
                {
                    var (pxrResult, handle) = LoadAnchorAsync(savedAnchorGuid).Result;

                    tcs.SetResult((pxrResult, handle));
                });
                var (result, anchorHandle) = tcs.Task.Result;
                if (result == ResultMsg.SUCCESS)
                {
                    anchor = anchorHandle;
                    synchronousResultStatus = new XRResultStatus(XRResultStatus.StatusCode.UnqualifiedSuccess);
                    rackableIdToXRAnchorMap[anchor.trackableId] = anchorHandle;
                    Debug.Log($"Load Anchor Success, trackableId: {anchor.trackableId}, anchorHandle: {anchorHandle}");
                }
                var returnResult = new Result<XRAnchor>(synchronousResultStatus, anchor);
                awaitable.SetResult(returnResult);
                return awaitable.Awaitable;
#else
                return awaitable.Awaitable;
#endif
            }
#endif
        }

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void RegisterDescriptor()
        {
#if AR_FOUNDATION_5
#if ENABLE_PICO_XR_SDK || ENABLE_PICO_OPENXR_SDK
            var cInfo = new XRAnchorSubsystemDescriptor.Cinfo()
            {
                id = k_SubsystemId,
                providerType = typeof(PXR_AnchorProvider),
                subsystemTypeOverride = typeof(PXR_AnchorSubsystem),
                supportsTrackableAttachments = false
            };
            XRAnchorSubsystemDescriptor.Create(cInfo);
#endif
#endif

#if AR_FOUNDATION_6
            var cInfo = new XRAnchorSubsystemDescriptor.Cinfo()
            {
                id = k_SubsystemId,
                providerType = typeof(PXR_AnchorProvider),
                subsystemTypeOverride = typeof(PXR_AnchorSubsystem),
                supportsTrackableAttachments = false,
                supportsSynchronousAdd = false,
                supportsSaveAnchor = true,
                supportsLoadAnchor = true,
                supportsEraseAnchor = true,
                supportsGetSavedAnchorIds = false,
                supportsAsyncCancellation = false
            };
            XRAnchorSubsystemDescriptor.Register(cInfo);
#endif
        }
    }
}
#endif