#if PICO_MS_SDK
using System;
using System.Linq;
using System.Runtime.InteropServices;
using UnityEngine;
using UnityEngine.XR;
#if AR_FOUNDATION_6
using UnityEngine.XR.ARSubsystems;
#endif
namespace ByteDance.PICO.Spatial.Stage
{
    public enum EventAction
    {
        MESH_UPDATE = 0,
    }

    /// <summary>
    /// The semantic labels of scene anchors.
    /// </summary>
    public enum SemanticLabel
    {
        Unknown = 0,
        /// <summary>
        /// A floor.
        /// </summary>
        Floor,
        /// <summary>
        /// A ceiling.
        /// </summary>
        Ceiling,
        /// <summary>
        /// A wall in the real-world scene. Doors and windows must exist within walls.
        /// </summary>
        Wall,
        /// <summary>
        /// A door, which must exist within a wall.
        /// </summary>
        Door,
        /// <summary>
        /// A window, which must exist within a wall.
        /// </summary>
        Window,
        Opening,
        /// <summary>
        /// A table.
        /// </summary>
        Table,
        /// <summary>
        /// A sofa.
        /// </summary>
        Sofa,
        /// <summary>
        /// A chair.
        /// </summary>
        Chair,
        Human = 10,
        Beam = 11,
        Column = 12,
        Curtain = 13,
        Cabinet,
        Bed,
        Plant,
        Screen,
        /// <summary>
        /// Virtual walls are generated when scene capture is automatically closed. They are not associated with real-world walls, and you can not draw doors or windows on them.
        /// </summary>
        VirtualWall = 18,
        Refrigerator,
        WashingMachine,
        AirConditioner,
        Lamp,
        WallArt = 23,
        Stairway
    }
    public struct FrameAnchorData
    {
        public int addedAnchorCount;
        public IntPtr addedAnchors;

        public int updatedAnchorCount;
        public IntPtr updatedAnchors;

        public int removedAnchorCount;
        public IntPtr removedAnchors;
    }
    
    public struct HandPinchState
    {
        public uint isActive;
        
        public Pose PinchPose;

        public float pinchStrengthIndex;

        public uint isReady;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct HandJointResult
    {
        public uint isActive;

        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 26)]
        public Pose[] jointLocations;
    }
    public static class SpatialNativeApi
    {
        public const string MS_STAGE_DLL = "StagePlatform";
        public delegate void XrEventDataCallBack(ref int status, ref int action);
        [DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]
        public static extern bool Pmp_StartHandTracking();

        [DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]
        public static extern bool Pmp_StopHandTracking();

        [DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]
        public static extern void Pmp_SetSpatialAdapterSpatialMode(int mode);

        [DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]
        public static extern int Pmp_GetHandTrackingSupported();

        [DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]
        public static extern int Pmp_GetHandTrackingState();

        [DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]   
        public static extern int Pmp_GetHandHandJointResult(int handedness, ref HandJointResult handJointResult);
        [DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]
        public static extern int Pmp_GetHandTrackerPinchState(int hand, ref HandPinchState aimState);

#if AR_FOUNDATION_6
        [DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]
        public static extern int Pmp_CreateAnchor(UnityEngine.XR.ARSubsystems.TrackableId trackableId, ref XRAnchor anchor);
        [DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]
        public static extern int Pmp_CreateAnchorComplete(UnityEngine.XR.ARSubsystems.TrackableId trackableId, ref XRAnchor anchor);
        [DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]
        public static extern void Pmp_PersistSpatialAnchorAsync(UnityEngine.XR.ARSubsystems.TrackableId trackableId);
        [DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]
        public static extern int Pmp_LoadAnchorAsync(UnityEngine.XR.ARSubsystems.TrackableId trackableId, ref XRAnchor anchor);
        [DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]
        public static extern int Pmp_LoadAnchorComplete(UnityEngine.XR.ARSubsystems.TrackableId trackableId, ref XRAnchor anchor);

        [DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]
        public static extern int Pmp_GetFrameAnchorData(ref FrameAnchorData frameAnchorData);
        [DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]
        public static extern int Pmp_RemoveAnchor(UnityEngine.XR.ARSubsystems.TrackableId trackableId);
        [DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]
        public static extern int Pmp_RemoveAnchorAsync(UnityEngine.XR.ARSubsystems.TrackableId trackableId);
        [DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]
        public static extern int Pmp_RemoveAnchorComplete(UnityEngine.XR.ARSubsystems.TrackableId trackableId);
#endif
        [DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]
        public static extern void Pmp_Deinitialize();

        [DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]
        public static extern bool Pmp_GetSpatialMeshInfo(ref MeshInfo meshInfo);

        [DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]
        public static extern void Pmp_SetEventDataBufferCallBack(XrEventDataCallBack callback);

 		[DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]
        public static extern bool Pmp_isUpdateMesh(MeshId MeshId);
        
        [DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]
        public static extern unsafe void Pmp_AddOrUpdateMesh(ulong id1, ulong id2, int numVertices, void* vertices, int numTriangles, void* indices,
            Vector3 position, Quaternion rotation);
        [DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]
        public static extern void Pmp_RemoveMesh(ulong id1, ulong id2);
        [DllImport(MS_STAGE_DLL, CallingConvention = CallingConvention.Cdecl)]
        public static extern void Pmp_ClearMeshes();
        
        [StructLayout(LayoutKind.Sequential)]
        public struct MeshInfo
        {
            public Guid uuid;
            public int state;
            public Vector3 Position;
            public Quaternion Rotation;
            public uint vertexCapacityInput;
            public uint vertexCountOutput;
            public IntPtr vertices;//PxrVector3f[];
            public uint indexCapacityInput;
            public uint indexCountOutput;
            public IntPtr indices;// uint16_t[]
            public uint semanticCapacityInput;
            public uint semanticCountOutput;
            public IntPtr semanticLabels;//SemanticLabel[]
        }
        private static AndroidJavaClass unityPlayer = new AndroidJavaClass("com.unity3d.player.UnityPlayer");
        private static AndroidJavaObject currentActivity = unityPlayer.GetStatic<AndroidJavaObject>("currentActivity");
        private static AndroidJavaClass sysActivity = new AndroidJavaClass("com.pico.stageplatform.StageFunction");
        public static void UPxr_Init()
        {
#if UNITY_ANDROID && !UNITY_EDITOR
                try
                {
                    if (sysActivity == null) return ;
                    sysActivity.CallStatic("Init", currentActivity);
                }
                catch (Exception e)
                {
                    Debug.LogError( "InitStageFunction Error :" + e);
                }
#endif
        }
        public static int GetSpatialMeshDataInfo(
            out Guid uuid,
                out int state,
            out Vector3 position,
            out Quaternion rotation,
            out ushort[] indices, out Vector3[] vertices,out SemanticLabel[] labels)
        {
            uuid=Guid.Empty;
            state = -1;
            position = Vector3.zero;
            rotation = Quaternion.identity;
            indices = Array.Empty<ushort>();
            vertices = Array.Empty<Vector3>();
            labels = Array.Empty<SemanticLabel>();
            
            MeshInfo meshInfo = new MeshInfo()
            {
                uuid = Guid.Empty,
                state = -1,
                Position = Vector3.zero,
                Rotation = Quaternion.identity,
                vertexCapacityInput = 0,
                vertexCountOutput = 0,
                vertices = IntPtr.Zero,
                indexCapacityInput = 0,
                indexCountOutput = 0,
                indices = IntPtr.Zero
            };
            var result = Pmp_GetSpatialMeshInfo(ref meshInfo);
            if (result)
            {
                
                state=meshInfo.state;
                uuid=meshInfo.uuid;
                // position=meshInfo.Position;
                // rotation=meshInfo.Rotation;
                position=new Vector3(meshInfo.Position.x, meshInfo.Position.y, -meshInfo.Position.z);
                rotation=new Quaternion(meshInfo.Rotation.x, meshInfo.Rotation.y, -meshInfo.Rotation.z, -meshInfo.Rotation.w);
          
                meshInfo.indexCapacityInput = meshInfo.indexCountOutput;
                meshInfo.vertexCapacityInput = meshInfo.vertexCountOutput;
                meshInfo.semanticCapacityInput = meshInfo.semanticCountOutput;
                
                indices = new ushort[meshInfo.indexCountOutput];
                if (meshInfo.indexCountOutput > 0)
                {
                    var indicesTmp = new short[meshInfo.indexCountOutput];
                    Marshal.Copy(meshInfo.indices, indicesTmp, 0, (int)meshInfo.indexCountOutput);
                    indices = indicesTmp.Select(l => (ushort)l).ToArray();

                    for (int i = 0; i < indices.Length; i += 3)
                    {
                        (indices[i + 1], indices[i + 2]) = (indices[i + 2], indices[i + 1]);
                    }
                    // for (int i = 0; i < meshInfo.indexCountOutput; i++)
                    // {
                    //     Debug.Log($"GetSpatialMeshDataInfo indices[{i}]: {indices[i]}");
                    // }
                }
                
                
                vertices = new Vector3[meshInfo.vertexCountOutput];
                if (meshInfo.vertexCountOutput > 0)
                {
                    IntPtr tempPtr = meshInfo.vertices;
                    for (int i = 0; i < meshInfo.vertexCountOutput; i++)
                    {
                        vertices[i] = Marshal.PtrToStructure<Vector3>(tempPtr);
                        tempPtr += Marshal.SizeOf(typeof(Vector3));
                    }

                    vertices = vertices.Select(v => new Vector3(v.x, v.y, -v.z)).ToArray();
                    // vertices = vertices.Select(v => new Vector3(v.x, v.y, v.z)).ToArray();
                }
                // for (int i = 0; i < vertices.Length; i++)
                // {
                //     Debug.Log($"GetSpatialMeshDataInfo vertices[{i}]: {vertices[i]}");
                // }
                
                
                labels = new SemanticLabel[meshInfo.semanticCountOutput];
                if (meshInfo.semanticCountOutput > 0)
                {
                    var sTmp = new int[meshInfo.semanticCountOutput];
                    Marshal.Copy(meshInfo.semanticLabels, sTmp, 0, (int)meshInfo.semanticCountOutput);
                    labels = sTmp.Select(l => (SemanticLabel)l).ToArray();
                    // Debug.Log($"GetSpatialMeshDataInfo {meshInfo.indexCountOutput}, {meshInfo.vertexCountOutput} ,{meshInfo.semanticCountOutput}");
                    // for (int i = 0; i < labels.Length; i++)
                    // {
                    //     Debug.Log($"GetSpatialMeshDataInfo semanticLabels[{i}]: {labels[i]}");
                    // }
                }
            }

            return 0;
        }

    }
}
#endif
