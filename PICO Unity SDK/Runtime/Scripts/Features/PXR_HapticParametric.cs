using UnityEngine;

namespace ByteDance.PICO.XR
{
    /// <summary>
    /// High-level entry point for the XR_EXT_haptic_parametric extension, which lets you
    /// drive controller vibration with time-varying amplitude/frequency envelopes and
    /// discrete transients instead of a single constant pulse.
    /// </summary>
    public static class PXR_HapticParametric
    {
        /// <summary>The maximum number of points or transients per envelope array.</summary>
        public const int MaxPointsTransients = PXR_HapticParametricPlugin.MAX_POINTS_TRANSIENTS;

        /// <summary>
        /// The default frame duration, in nanoseconds (50ms), defined by the extension's
        /// vibration-extend window. Use it to pace streaming when the runtime does not report
        /// an idealFrameSubmissionRate.
        /// </summary>
        public const long VibrationExtendDurationNs = PXR_HapticParametricPlugin.VIBRATION_EXTEND_DURATION;

        /// <summary>The minimum frequency, in Hz, defined by the extension.</summary>
        public const float FrequencyMinHz = PXR_HapticParametricPlugin.FREQUENCY_MIN_HZ;

        /// <summary>The maximum frequency, in Hz, defined by the extension.</summary>
        public const float FrequencyMaxHz = PXR_HapticParametricPlugin.FREQUENCY_MAX_HZ;

        /// <summary>
        /// Gets whether the current device supports parametric haptics.
        /// </summary>
        /// <param name="supported">Returns whether the device supports parametric haptics.</param>
        /// <returns>Returns PxrResult.SUCCESS for success and other values for failure.</returns>
        public static PxrResult GetSupported(ref bool supported)
        {
            return PXR_HapticParametricPlugin.UPxr_GetSystemSupportsParametricHaptics(ref supported);
        }

        /// <summary>
        /// Queries the runtime's recommended submission parameters for a controller, such as
        /// the ideal frame submission rate and supported frequency range for streaming effects.
        /// </summary>
        /// <param name="hand">The controller to query: `0` (left), `1` (right), or `3` (both/unspecified).</param>
        /// <param name="properties">Returns the parametric haptics properties.</param>
        /// <returns>Returns PxrResult.SUCCESS for success and other values for failure.</returns>
        public static PxrResult GetProperties(int hand, ref PxrHapticParametricProperties properties)
        {
            return PXR_HapticParametricPlugin.UPxr_GetHapticParametricProperties(hand, ref properties);
        }

        /// <summary>
        /// Plays a parametric vibration effect on the specified controller(s).
        /// </summary>
        /// <param name="hand">The controller to vibrate: `0` (left), `1` (right), or `3` (both).</param>
        /// <param name="vibration">The parametric vibration effect to play. `amplitudePoints` is required.
        /// All point/transient `value`/`amplitude`/`frequency` fields are <b>normalized to [0,1]</b>
        /// (the frequency is mapped onto `minFrequencyHz`..`maxFrequencyHz`, which are the only
        /// absolute-Hz fields and must be 0 or within [1,1000]). Out-of-range values are rejected.</param>
        /// <returns>Returns PxrResult.SUCCESS for success and other values for failure.</returns>
        public static PxrResult Apply(int hand, in PxrHapticParametricVibration vibration)
        {
            return PXR_HapticParametricPlugin.UPxr_ApplyHapticParametricVibration(hand, vibration);
        }

        /// <summary>
        /// Stops any parametric vibration currently playing on the specified controller(s).
        /// </summary>
        /// <param name="hand">The controller to stop: `0` (left), `1` (right), or `3` (both).</param>
        /// <returns>Returns PxrResult.SUCCESS for success and other values for failure.</returns>
        public static PxrResult Stop(int hand)
        {
            return PXR_HapticParametricPlugin.UPxr_StopHapticParametricVibration(hand);
        }
    }
}
