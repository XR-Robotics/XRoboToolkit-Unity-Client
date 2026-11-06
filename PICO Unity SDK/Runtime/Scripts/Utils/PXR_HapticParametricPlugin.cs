using System;
using System.Runtime.InteropServices;
using UnityEngine;

namespace ByteDance.PICO.XR
{
    // 1:1 mirror of XrHapticParametricPointEXT (XR_EXT_haptic_parametric).
    // A single sample point of an amplitude or frequency envelope.
    // Pack = 8 matches the native header's default 8-byte alignment (XrDuration is
    // int64_t; the header carries no #pragma pack). Layout: time@0, value@8, size 16.
    [StructLayout(LayoutKind.Sequential, Pack = 8)]
    public struct XrHapticParametricPointEXT
    {
        // Offset from the start of the effect, in nanoseconds.
        public long time;

        // Normalized value in [0,1]. For amplitudePoints this is the amplitude.
        // For frequencyPoints this is the normalized frequency, which the runtime
        // maps onto [minFrequencyHz, maxFrequencyHz]; it is NOT an absolute Hz value.
        // Values outside [0,1] are rejected with XR_ERROR_VALIDATION_FAILURE.
        public float value;
    }

    // 1:1 mirror of XrHapticParametricTransientEXT (XR_EXT_haptic_parametric).
    // A discrete transient impulse superimposed on the envelopes.
    // Pack = 8 matches the native header's default alignment. Layout:
    // time@0, amplitude@8, frequency@12, size 16.
    [StructLayout(LayoutKind.Sequential, Pack = 8)]
    public struct XrHapticParametricTransientEXT
    {
        // Offset from the start of the effect, in nanoseconds.
        public long time;

        // Normalized amplitude in [0,1].
        public float amplitude;

        // Normalized frequency in [0,1] (NOT absolute Hz). The runtime maps it onto
        // [minFrequencyHz, maxFrequencyHz]. Values outside [0,1] are rejected with
        // XR_ERROR_VALIDATION_FAILURE.
        public float frequency;
    }

    // Frame role when an effect is split across multiple submissions for streaming.
    // Mirrors XrHapticParametricStreamFrameTypeEXT.
    public enum XrHapticParametricStreamFrameTypeEXT
    {
        // The effect is submitted in a single frame (non-streaming).
        XR_HAPTIC_PARAMETRIC_STREAM_FRAME_TYPE_NONE_EXT = 0,
        XR_HAPTIC_PARAMETRIC_STREAM_FRAME_TYPE_FIRST_FRAME_EXT = 1,
        XR_HAPTIC_PARAMETRIC_STREAM_FRAME_TYPE_INTERMEDIATE_FRAME_EXT = 2,
        XR_HAPTIC_PARAMETRIC_STREAM_FRAME_TYPE_LAST_FRAME_EXT = 3,
    }

    // Managed-friendly description of a parametric vibration effect.
    // The marshalling layer pins the arrays and forwards pointers to native,
    // keeping the call path allocation-free on the hot path.
    //
    // Value ranges (enforced by the runtime; the C# layer pre-validates the
    // normalized fields and rejects violations with ERROR_VALIDATION_FAILURE):
    //   - amplitudePoints / frequencyPoints .value : normalized [0,1]
    //   - transients .amplitude / .frequency       : normalized [0,1]
    //   - point/transient counts                   : <= MAX_POINTS_TRANSIENTS (500)
    //   - min/maxFrequencyHz                       : both 0 (XR_FREQUENCY_UNSPECIFIED)
    //       or both within [FREQUENCY_MIN_HZ, FREQUENCY_MAX_HZ] = [1,1000], maxHz >= minHz
    public struct PxrHapticParametricVibration
    {
        // Amplitude envelope (required, >= 1 point; >= 2 points for NONE/FIRST frames).
        public XrHapticParametricPointEXT[] amplitudePoints;

        // Optional frequency envelope. Null/empty means constant device frequency.
        public XrHapticParametricPointEXT[] frequencyPoints;

        // Optional discrete transient impulses. NOTE: transients need a non-zero
        // baseline amplitude envelope to be felt. The runtime renders a transient by
        // reserving headroom above the amplitude points, so a flat-zero envelope has no
        // carrier and produces no perceivable output even though the call returns success.
        // Pair transients with a low baseline (e.g. amplitudePoints value ~0.15).
        public XrHapticParametricTransientEXT[] transients;

        // Absolute frequency range, in Hz, that the normalized values map onto.
        // Both must be 0 (unspecified) or both within [1,1000]. For streaming, only the
        // FIRST frame may set the range; INTERMEDIATE/LAST frames must pass 0/0.
        public float minFrequencyHz;
        public float maxFrequencyHz;

        // Single-shot (NONE) or one role of a multi-frame stream.
        public XrHapticParametricStreamFrameTypeEXT streamFrameType;
    }

    // ABI mirror of XrHapticParametricPropertiesEXT, returned by the per-action query.
    // The type/next header must be present because native writes `type`/`next` (see
    // OpenXrProgram::GetHapticParametricProperties) and treats this pointer as the full
    // OpenXR struct. Pack = 8 matches the native header (default alignment): type@0,
    // next@8, idealFrameSubmissionRate@16, minimumFirstFrameDuration@24, minFrequencyHz@32,
    // maxFrequencyHz@36, size 40.
    [StructLayout(LayoutKind.Sequential, Pack = 8)]
    public struct PxrHapticParametricProperties
    {
        public XrStructureType type;
        public IntPtr next;
        public long idealFrameSubmissionRate;
        public long minimumFirstFrameDuration;
        public float minFrequencyHz;
        public float maxFrequencyHz;
    }

    public static class PXR_HapticParametricPlugin
    {
        // Hard limits from the extension (XR_HAPTIC_PARAMETRIC_*).
        public const int MAX_POINTS_TRANSIENTS = 500;
        public const long VIBRATION_EXTEND_DURATION = 50000000;
        public const float FREQUENCY_MIN_HZ = 1f;
        public const float FREQUENCY_MAX_HZ = 1000f;

        // Native side packs these flat arrays into XrHapticParametricVibrationEXT and
        // submits it through xrApplyHapticFeedback. EntryPoint names follow the PICO
        // Pxr_* convention and must be confirmed against the shipping libPxrPlatform.
        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static unsafe extern PxrResult Pxr_ApplyHapticParametricVibration(
            int hand,
            XrHapticParametricPointEXT* amplitudePoints, uint amplitudePointCount,
            XrHapticParametricPointEXT* frequencyPoints, uint frequencyPointCount,
            XrHapticParametricTransientEXT* transients, uint transientCount,
            float minFrequencyHz, float maxFrequencyHz,
            int streamFrameType);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern PxrResult Pxr_StopHapticParametricVibration(int hand);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern PxrResult Pxr_GetSystemSupportsParametricHaptics(
            [MarshalAs(UnmanagedType.I1)] ref bool supported);

        [DllImport(PXR_Plugin.PXR_PLATFORM_DLL, CallingConvention = CallingConvention.Cdecl)]
        private static extern PxrResult Pxr_GetHapticParametricProperties(int hand, ref PxrHapticParametricProperties properties);

        public static unsafe PxrResult UPxr_ApplyHapticParametricVibration(int hand, in PxrHapticParametricVibration vibration)
        {
#if UNITY_EDITOR || !UNITY_ANDROID
            return PxrResult.SUCCESS;
#else
            if (hand != 0 && hand != 1 && hand != 3)
            {
                Debug.LogError($"PXR_HapticParametricPlugin: invalid hand={hand}. Expected 0 (left), 1 (right), or 3 (both).");
                return PxrResult.ERROR_VALIDATION_FAILURE;
            }

            if (vibration.amplitudePoints == null || vibration.amplitudePoints.Length == 0)
            {
                Debug.LogError("PXR_HapticParametricPlugin: amplitudePoints is required and must be non-empty.");
                return PxrResult.ERROR_VALIDATION_FAILURE;
            }

            // NONE (single-shot) and FIRST stream frames describe a span of time, so they
            // need at least 2 amplitude points to form an envelope. INTERMEDIATE/LAST frames
            // may carry a single point. Catching this here yields a clear message instead of
            // an opaque XR_ERROR_VALIDATION_FAILURE from the runtime.
            var frameType = vibration.streamFrameType;
            bool requiresTwoPoints =
                frameType == XrHapticParametricStreamFrameTypeEXT.XR_HAPTIC_PARAMETRIC_STREAM_FRAME_TYPE_NONE_EXT ||
                frameType == XrHapticParametricStreamFrameTypeEXT.XR_HAPTIC_PARAMETRIC_STREAM_FRAME_TYPE_FIRST_FRAME_EXT;
            if (requiresTwoPoints && vibration.amplitudePoints.Length < 2)
            {
                Debug.LogError($"PXR_HapticParametricPlugin: streamFrameType={frameType} requires at least 2 amplitudePoints " +
                               $"to form a time envelope (got {vibration.amplitudePoints.Length}).");
                return PxrResult.ERROR_VALIDATION_FAILURE;
            }

            if (vibration.amplitudePoints.Length > MAX_POINTS_TRANSIENTS ||
                (vibration.frequencyPoints != null && vibration.frequencyPoints.Length > MAX_POINTS_TRANSIENTS) ||
                (vibration.transients != null && vibration.transients.Length > MAX_POINTS_TRANSIENTS))
            {
                Debug.LogError($"PXR_HapticParametricPlugin: point/transient count exceeds {MAX_POINTS_TRANSIENTS}.");
                return PxrResult.ERROR_VALIDATION_FAILURE;
            }

            // Per XR_EXT_haptic_parametric, the value of amplitude/frequency points and
            // the amplitude/frequency of transients are NORMALIZED to [0,1]; the runtime
            // maps the frequency onto [minFrequencyHz, maxFrequencyHz]. Submitting an
            // absolute Hz here (e.g. 200f) is the most common mistake and the runtime
            // rejects it with an opaque XR_ERROR_VALIDATION_FAILURE. Catch it early.
            if (!AreNormalized(vibration.amplitudePoints, "amplitudePoints") ||
                !AreNormalized(vibration.frequencyPoints, "frequencyPoints") ||
                !AreTransientsNormalized(vibration.transients))
            {
                return PxrResult.ERROR_VALIDATION_FAILURE;
            }

            // Validate absolute Hz range for minFrequencyHz/maxFrequencyHz:
            // both must be 0 (XR_FREQUENCY_UNSPECIFIED) or both within [1,1000] with maxHz >= minHz.
            float minHz = vibration.minFrequencyHz;
            float maxHz = vibration.maxFrequencyHz;
            bool bothUnspecified = (minHz == 0f && maxHz == 0f);
            bool bothInRange = (minHz >= FREQUENCY_MIN_HZ && minHz <= FREQUENCY_MAX_HZ) &&
                               (maxHz >= FREQUENCY_MIN_HZ && maxHz <= FREQUENCY_MAX_HZ) &&
                               (maxHz >= minHz);
            if (!bothUnspecified && !bothInRange)
            {
                Debug.LogError($"PXR_HapticParametricPlugin: minFrequencyHz={minHz}, maxFrequencyHz={maxHz} invalid. " +
                               "Both must be 0 (XR_FREQUENCY_UNSPECIFIED) or both within [1,1000] with maxHz >= minHz.");
                return PxrResult.ERROR_VALIDATION_FAILURE;
            }

            // Streaming frame constraint: INTERMEDIATE and LAST frames must set minHz=maxHz=0
            // (XR_FREQUENCY_UNSPECIFIED). Only the FIRST frame may carry a valid frequency range.
            if (frameType == XrHapticParametricStreamFrameTypeEXT.XR_HAPTIC_PARAMETRIC_STREAM_FRAME_TYPE_INTERMEDIATE_FRAME_EXT ||
                frameType == XrHapticParametricStreamFrameTypeEXT.XR_HAPTIC_PARAMETRIC_STREAM_FRAME_TYPE_LAST_FRAME_EXT)
            {
                if (minHz != 0f || maxHz != 0f)
                {
                    Debug.LogError($"PXR_HapticParametricPlugin: streamFrameType={frameType} requires minFrequencyHz=0 and maxFrequencyHz=0 " +
                                   "(XR_FREQUENCY_UNSPECIFIED). Only the FIRST frame may set a valid frequency range.");
                    return PxrResult.ERROR_VALIDATION_FAILURE;
                }
            }

            uint amplitudeCount = (uint)vibration.amplitudePoints.Length;
            uint frequencyCount = vibration.frequencyPoints == null ? 0u : (uint)vibration.frequencyPoints.Length;
            uint transientCount = vibration.transients == null ? 0u : (uint)vibration.transients.Length;

            fixed (XrHapticParametricPointEXT* amplitudePtr = vibration.amplitudePoints)
            fixed (XrHapticParametricPointEXT* frequencyPtr = vibration.frequencyPoints)
            fixed (XrHapticParametricTransientEXT* transientPtr = vibration.transients)
            {
                return Pxr_ApplyHapticParametricVibration(
                    hand,
                    amplitudePtr, amplitudeCount,
                    frequencyPtr, frequencyCount,
                    transientPtr, transientCount,
                    vibration.minFrequencyHz, vibration.maxFrequencyHz,
                    (int)vibration.streamFrameType);
            }
#endif
        }

        // These validators are only referenced by the native (Android, non-Editor) branch
        // of UPxr_ApplyHapticParametricVibration. The guard mirrors that call site's
        // `#if UNITY_EDITOR || !UNITY_ANDROID ... #else` exactly (negated) so both stay in sync.
#if !(UNITY_EDITOR || !UNITY_ANDROID)
        // Validates that every point's normalized value is within [0,1].
        // Null arrays are allowed (frequencyPoints is optional).
        private static bool AreNormalized(XrHapticParametricPointEXT[] points, string fieldName)
        {
            if (points == null)
            {
                return true;
            }

            for (int i = 0; i < points.Length; i++)
            {
                float v = points[i].value;
                if (v < 0f || v > 1f)
                {
                    Debug.LogError($"PXR_HapticParametricPlugin: {fieldName}[{i}].value={v} is out of the normalized [0,1] range. " +
                                   "Use minFrequencyHz/maxFrequencyHz for absolute Hz; point values are normalized.");
                    return false;
                }
            }

            return true;
        }

        // Validates that every transient's normalized amplitude and frequency are within [0,1].
        private static bool AreTransientsNormalized(XrHapticParametricTransientEXT[] transients)
        {
            if (transients == null)
            {
                return true;
            }

            for (int i = 0; i < transients.Length; i++)
            {
                float amp = transients[i].amplitude;
                float freq = transients[i].frequency;
                if (amp < 0f || amp > 1f || freq < 0f || freq > 1f)
                {
                    Debug.LogError($"PXR_HapticParametricPlugin: transients[{i}] amplitude={amp}, frequency={freq} out of normalized [0,1] range. " +
                                   "Use minFrequencyHz/maxFrequencyHz for absolute Hz; transient frequency is normalized.");
                    return false;
                }
            }

            return true;
        }
#endif

        public static PxrResult UPxr_StopHapticParametricVibration(int hand)
        {
#if UNITY_EDITOR || !UNITY_ANDROID
            return PxrResult.SUCCESS;
#else
            if (hand != 0 && hand != 1 && hand != 3)
            {
                Debug.LogError($"PXR_HapticParametricPlugin: invalid hand={hand}. Expected 0 (left), 1 (right), or 3 (both).");
                return PxrResult.ERROR_VALIDATION_FAILURE;
            }
            return Pxr_StopHapticParametricVibration(hand);
#endif
        }

        public static PxrResult UPxr_GetSystemSupportsParametricHaptics(ref bool supported)
        {
#if UNITY_EDITOR || !UNITY_ANDROID
            supported = false;
            return PxrResult.SUCCESS;
#else
            supported = false;
            return Pxr_GetSystemSupportsParametricHaptics(ref supported);
#endif
        }

        public static PxrResult UPxr_GetHapticParametricProperties(int hand, ref PxrHapticParametricProperties properties)
        {
#if UNITY_EDITOR || !UNITY_ANDROID
            // Editor/非Android 平台没有真实 haptic 设备，返回合理默认值以便上层有一致的回退行为：
            // idealFrameSubmissionRate 回退到扩展定义的 50ms extend window，频率范围取常见设备能力。
            properties = default;
            properties.idealFrameSubmissionRate = VIBRATION_EXTEND_DURATION;
            properties.minimumFirstFrameDuration = VIBRATION_EXTEND_DURATION;
            properties.minFrequencyHz = 50f;
            properties.maxFrequencyHz = 300f;
            return PxrResult.SUCCESS;
#else
            if (hand != 0 && hand != 1 && hand != 3)
            {
                Debug.LogError($"PXR_HapticParametricPlugin: invalid hand={hand}. Expected 0 (left), 1 (right), or 3 (both).");
                properties = default;
                return PxrResult.ERROR_VALIDATION_FAILURE;
            }
            // Zero-initialize the struct; native side writes `type`/`next` and populates
            // all property fields, treating this pointer as a full XrHapticParametricPropertiesEXT.
            properties = default;
            return Pxr_GetHapticParametricProperties(hand, ref properties);
#endif
        }
    }
}
