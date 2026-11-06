using System;
using UnityEngine;

namespace ByteDance.PICO.XR
{
    public static class PXR_FacialSimulation
    {
        public const int FACE_COUNT = 52;
        public const int LIPSYNC_COUNT = 20;

        /// <summary>
        /// Gets whether the current device supports facial simulation.
        /// </summary>
        /// <param name="supported">Indicates whether the device supports facial simulation:
        /// * `true`: support
        /// * `false`: not support
        /// </param>
        /// <param name="supportedModesCount">Returns the total number of facial simulation modes supported by the device.</param>
        /// <param name="supportedModes">Returns the specific facial simulation modes supported by the device.</param>
        /// <returns>Returns PxrResult.SUCCESS for success and other values for failure.</returns>
        public static PxrResult GetFacialSimulationSupported(ref bool supported, ref int supportedModesCount, ref XrFacialSimulationModeBD[] supportedModes)
        {
            return PXR_FacialSimulationPlugin.UPxr_GetFacialSimulationSupported(ref supported, ref supportedModesCount, ref supportedModes);
        }

        /// <summary>
        /// Starts facial simulation.
        /// </summary>
        /// <param name="mode">Passes the information for starting facial simulation.</param>
        /// <returns>Returns PxrResult.SUCCESS for success and other values for failure.</returns>
        public static PxrResult StartFacialSimulation(XrFacialSimulationModeBD mode)
        {
            return PXR_FacialSimulationPlugin.UPxr_StartFacialSimulation(mode);
        }

        /// <summary>
        /// Stops facial simulation.
        /// </summary>
        /// <returns>Returns PxrResult.SUCCESS for success and other values for failure.</returns>
        public static PxrResult StopFacialSimulation()
        {
            return PXR_FacialSimulationPlugin.UPxr_StopFacialSimulation();
        }
        /// <summary>
        /// Gets the current facial simulation mode.
        /// </summary>
        /// <param name="mode">Returns the current facial simulation mode.</param>
        /// <returns>Returns PxrResult.SUCCESS for success and other values for failure.</returns>
        public static PxrResult GetFacialSimulationMode(ref XrFacialSimulationModeBD mode)
        {
            return PXR_FacialSimulationPlugin.UPxr_GetFacialSimulationMode(ref mode);
        }
        /// <summary>
        /// Sets the current facial simulation mode.
        /// </summary>
        /// <param name="mode">Passes the information for setting the current facial simulation mode.</param>
        /// <returns>Returns PxrResult.SUCCESS for success and other values for failure.</returns>
        public static PxrResult SetFacialSimulationMode(XrFacialSimulationModeBD mode)
        {
            return PXR_FacialSimulationPlugin.UPxr_SetFacialSimulationMode(mode);
        }
        /// <summary>
        /// Gets the current facial simulation data.
        /// </summary>
        /// <param name="timestamp">Returns the timestamp of the facial simulation data.</param>
        /// <param name="data">Returns the facial simulation data.</param>
        /// <returns>Returns PxrResult.SUCCESS for success and other values for failure.</returns>
        public static PxrResult GetFacialSimulationData(Int64 timestamp, ref PxrFacialSimulationData data)
        {
            return PXR_FacialSimulationPlugin.UPxr_GetFacialSimulationData(timestamp, ref data);
        }
    }
}
