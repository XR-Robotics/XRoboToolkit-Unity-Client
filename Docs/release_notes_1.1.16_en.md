# XRoboToolkit v1.1.16 Release Notes

Draft release notes covering the recent PICO SDK migration, eye tracking integration, and current local fixes.

## Features and Improvements

1. **EyeTracking gaze visualization**: Read the combined binocular gaze origin and direction, and display the gaze ray and surface hit point in real time.
2. **Dedicated EyeTracking results page**: Display tracking status, world-space gaze origin and direction, hit position, target, distance, and SDK service return codes. Open the page from the main dashboard and return without changing tracking state.
3. **Scene and UI hit detection**: Support colliders and world-space UI, selecting the nearest surface while accounting for occlusion, layer filtering, and exclusion of the XR Rig's own geometry.
4. **Frame-based gaze updates**: Update gaze sampling, raycasting, and visualization once per Unity render frame. Refresh regular numeric readouts at 10 Hz, with immediate updates when status changes or data becomes invalid.
5. **Editor gaze simulation**: Simulate gaze using the mouse or a custom camera-local direction. Press F8 to toggle simulation and F9 to toggle sample validity. Distinguish simulated and device data through separate colors and status labels.
6. **Enterprise EyeFrame preview**: Receive four raw eye-camera image streams through the enterprise service. Display each camera's ID, dimensions, and nanosecond timestamp, with start/stop and display-orientation controls.
7. **Dashboard layout and navigation updates**: Reorganize stream controls, add an EyeTracking results entry and a separate EyeFrame side panel, and preserve active sampling when switching pages.
8. **Diagnostics and development validation tools**: Add logs for gaze validity, service state, native eye poses, and hand input, together with validation tools for SDK migration, gaze behavior, and hand buttons.
9. **Development documentation**: Add an EyeTracking integration guide and provide documentation for gaze visualization, EyeFrame preview, and SDK migration.

## Fixes

1. **Swan gaze validity handling**: Accept the combined pose validity flags returned by the device, preventing valid samples from being rejected by a check that only accepted status `1`.
2. **Stale gaze data cleanup**: Clear previous rays and hit points when tracking is invalid, disabled, paused, or unfocused. Display only the direction line when a valid ray has no surface hit.
3. **Eye tracking service lifecycle**: Reuse healthy existing sessions, stop only sessions started by the component, and recheck service state after resuming.
4. **SDK 6.1.1 hand-ray input adaptation**: Bind to the new SDK's `pointer/position` and `pointer/rotation`, correcting the ray-following issue encountered after migration.
5. **SDK 6.1.1 pinch-button encoding**: Write pressed and released states using the full BYTE range, preventing pressed states from being normalized to values too low for UI click recognition. Final on-device pinch-click validation is still pending.
6. **Local build parameter fallback**: Use the version, Android version code, and product name from the current Player Settings when external build parameters are not supplied.

## Environment and Compatibility

1. Migrate the active PICO package from Integration SDK 3.1.2 to **PICO Unity SDK 6.1.1**, while retaining **Unity 2022.3.16f1** and PICO XR.
2. Update SDK namespaces and adapt APIs for head tracking, controllers, trackers, body tracking, USB networking, and video see-through (VST). Preserve existing head/controller acquisition and transmission flows.
3. Retain the enterprise alpha ToB client and adapter, exclude duplicate enterprise clients, and preserve the application's existing camera library to avoid conflicts with the new SDK's camera dependencies.
4. Tracker and peripheral identifiers in the new SDK are numeric device IDs. Existing string identifier fields contain their decimal representations. Receivers or mapping configurations that depend on legacy hardware serial numbers require adaptation.

## Usage Notes and Validation Status

- EyeTracking gaze data and EyeFrame raw camera images are independent features. Neither has been added to a TCP eye tracking protocol or eye tracking recording files.
- Gaze rays calculate and display surface hit points; they do not automatically trigger gaze-based clicks.
- Existing validation covers Unity Editor import, Editor/Android C# compilation, coordinate conversion, surface intersection, asset references, and synthetic-frame tests for the EyeFrame bridge.
- Actual EyeFrame capture, pixel format, and on-device rendering still require device validation. Gaze calibration accuracy, long-term stability, and the full tracking lifecycle also require further validation.

For integration steps, see the [EyeTracking Integration Guide](eye_tracking_integration_guide.md) (Chinese). For upgrade differences, see the [PICO SDK 6.1.1 Migration Report](../pico_sdk_6_1_1_migration_report.md) (Chinese).
