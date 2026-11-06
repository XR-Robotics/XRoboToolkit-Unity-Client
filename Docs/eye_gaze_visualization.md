# Eye gaze direction and landing point

The Main scene's `XR Origin (XR Rig)` prefab now contains three independent
components. They do not depend on the head/controller interaction mode or the
Enterprise EyeFrame image preview.

| Component | Responsibility |
| --- | --- |
| `PicoEyeGazeSource` | Start/reuse PICO binocular eye tracking, validate each sample, convert it to a world ray |
| `EyeGazeRaycaster` | Find the closest collider or world-space UI surface along that ray |
| `EyeGazeVisualizer` | Show the direction line and surface marker |

`EyeGazeToggle` on the Main scene's EyeTracking option binds the checkbox and
editor shortcut to the source's shared activation state.

## SDK and coordinates

This implementation uses local PICO Unity SDK 6.1.1 in PICO XR mode:

- `PXR_MotionTracking.GetEyeTrackingSupported`
- `GetEyeTrackingState`, `StartEyeTracking`, `StopEyeTracking`
- `PXR_EyeTracking.GetCombinedEyePoseStatus`
- `GetCombineEyeGazePoint`, `GetCombineEyeGazeVector`

All native access is guarded by `PICO_XR && UNITY_ANDROID && !UNITY_EDITOR`.
The separate assembly references `ByteDance.PICO.XR` and defines `PICO_XR` from
the `com.bytedance.pico.xr` package version. The project's global SDK symbol is
`ENABLE_PICO_XR_SDK`.

The SDK's combined gaze point is the **eye origin in camera coordinates, in
metres**. It is not the point on the object being viewed. The combined vector
is the camera-local gaze direction. No additional millimetre conversion or
coordinate-axis flip is applied:

```csharp
worldOrigin = gazeCamera.transform.TransformPoint(localEyeOrigin);
worldDirection = gazeCamera.transform.TransformDirection(localDirection.normalized).normalized;
landingPoint = closestSurfaceHit.Point;
```

All three SDK getters must succeed, combined pose status must indicate a valid
origin and direction, and the vectors must be finite with a nonzero direction.
SDK 6.1.1 documents a Boolean `0/1` status, but the 2026-11-05 Swan capture returned
`1539` (`0x603`) and `515` (`0x203`). Both include the gaze-point and gaze-vector
validity bits. The source accepts those bits together, ignores additional
metadata bits, and preserves support for the documented status `1`. Status `0`
or a partial validity mask is rejected. Invalid samples clear the
ray and hit immediately. There is no head-forward replacement for missing eye
data and no reuse of the previous frame's result.

## Display and hit rules

- Real gaze uses a cyan line and a 16 mm surface marker.
- Editor simulation uses orange.
- The default maximum distance is 10 Unity world units. With the rig's default
  scale of one, this is 10 metres.
- No surface hit: draw the direction line to the maximum distance, without a
  marker. `HasValidRay` can be true while `HasHit` is false.
- Invalid/paused/unfocused tracking: hide the line and marker.
- Physics hits exclude triggers, Ignore Raycast layers and rig descendants.
- World-space UI uses enabled canvas raycasters, raycast-target Graphics,
  rectangle bounds and `Graphic.Raycast` filters, including masks and
  `CanvasGroup.blocksRaycasts`.
- The closest surface wins across physics and UI, so a nearer object blocks a
  panel behind it. UI checks never submit pointer, hover or click events.
- Screen-space canvases and UI rendered into a texture are not intersected as
  world UI. For a texture projected onto a curved/mesh screen, add a collider
  matching that physical surface to obtain its world landing point.
- Other visible scene meshes need matching colliders to provide landing points.

The custom stereo-compatible unlit shader is in `Resources/EyeGazeUnlit.shader`
so it is included by Unity. The marker is offset 2 mm toward the viewer to avoid
overlapping its surface. The generated visuals have no colliders.

## Editor use

Click **Results >** beside the Main page's **EyeTracking** checkbox to open the
dedicated **EyeTracking results** page. The page uses the full main panel area,
with larger text for the validity state, world-space eye origin and direction,
actual hit point, target, hit distance, and the eye tracking service's last return
code. Gaze-ray and surface-hit values are grouped separately. Positions and
distance are in metres. **Activity** uses the full bottom row on Main.

Use the results page's **EyeTracking** checkbox to start or stop tracking; it
shares the same source and activation state as the Main checkbox and **F8**.
Click **Back** to return to Main. Opening or closing the page does not change
tracking state or stop collection. The independent EyeFrame side panel can
remain open alongside either page.

Numeric values refresh at 10 Hz after gaze sampling and raycasting. Switching
EyeTracking off or losing valid data clears the last pose/hit immediately.
A valid ray without a surface hit shows `--` for the hit point, target and
distance. **SIMULATED** identifies Editor data; simulated/off states do not
present a service return code as a device result.

When tracking shows **NO DATA**, the message distinguishes unavailable Unity XR
status/origin/direction, an invalid combined pose, and rejected numeric values.
`Service code: 0` only means the support/state/start operation succeeded; it does
not prove that an eye pose is valid.

While the service is ready, a separate `PXR_MotionTracking.GetEyeTrackingData`
diagnostic query runs every two seconds. **Last eye data code** shows its return
code; **Last pose valid (L/R/C)** shows the last native left/right/combined
`isPoseValid` flags. Failed queries show `--` for the flags. These are diagnostic
snapshots, not the per-frame gaze result, and they are cleared when tracking is
turned off, suspended, or the service is unavailable. Native poses are logged
without publishing them as camera-local rays, since the native reference space
must be verified on the device before replacing the Unity XR data path.

`[EyeGaze] Pose diagnostics` logs include the failed stage, raw Unity XR combined
status, service/data codes, native validity flags, native combined pose and
valid/invalid sample counts. Logs are limited to one snapshot every two seconds
(or the longer service retry interval). If the service is running but both paths
report invalid poses, verify eye tracking in the device's system settings,
complete system eye calibration, keep the headset worn and the app focused,
then toggle EyeTracking off and on. If the native combined pose is valid while
the Unity XR pose is invalid/unavailable, the logs identify a data-path
compatibility issue for further investigation.

The 2026-11-05 follow-up capture aligned 16 valid native eye snapshots with the
head recording within 5 ms. Native eye positions followed the head's tracking
positions with millimetre-scale offsets. These native poses must not be passed
directly to the camera-local conversion above: doing so would apply head motion
twice. A native data-path replacement needs an explicit tracking-space-to-world
transform or rebasing against a head pose in the same reference space. The current
fix keeps the Unity XR camera-local getters and corrects the combined-status
filter that previously rejected the observed `0x603` and `0x203` values before
attempting either vector getter.

The authored results page is `Assets/InteractionTools/Prefabs/EyeGazeReadout.prefab`;
Main binds it to the same gaze source and raycaster as both checkboxes.
`EyeGazePageNavigation` on the Main canvas switches pages. A `CanvasGroup` hides
Main and disables its UI input without disabling its components or their
capture lifecycle. The results text is read-only; the page background, checkbox
and Back button participate in pointer and gaze hit tests.

Enter Play mode in Main and focus the Game view:

Check **EyeTracking** beside the other stream options to enable the orange mouse
gaze ray and landing point. Unchecking it turns them off. This is the same
activation path as **F8**, and keyboard changes update the checkbox automatically.
The Main scene starts with EyeTracking unchecked.

The project's XRI device simulator starts automatically in the Editor. Hold the
**right mouse button** and move the mouse to rotate the head camera. While holding
it, use **W/A/S/D** to move and **Q/E** to move vertically. Release the right button
to use the mouse normally on UI.

Hold **Space** and move the mouse to aim the right controller independently of
the camera. Hold **Left Shift** instead to aim the left controller. While holding
the chosen controller key, use **W/A/S/D/Q/E** to move that controller,
**Left Mouse Button** to press UI, and **G** for grip/select. Release the right
mouse button before operating a controller: holding both requests both devices
to move. The camera and controller controls are separate from the orange eye
gaze simulation and work when eye gaze simulation is off.

1. Press **F8** to enable mouse simulation and move the mouse over the panel.
2. Press **F9** to switch simulated data validity; both visuals should disappear
   when invalid.
3. Press **F8** again to turn simulation off.

Alternatively, change `Editor Gaze Mode` on `PicoEyeGazeSource` to
`Camera Local Direction` and set the local origin/direction in the Inspector.
Simulation fields and shortcuts are excluded from the Android player.

The simulator prefab and its two input action assets are under
`Assets/XRI/Simulation`. Its action assets are copied unchanged from the installed
XR Interaction Toolkit 3.0.3 sample. The project prefab enables HMD and left/right
controller tracking and disables simulated hand tracking and the sample's extra UI.
The PICO input action asset includes explicit `XRSimulatedController` bindings
for controller tracking state and the otherwise PICO-specific interaction inputs.
`XRDeviceSimulatorSettings` enables automatic instantiation only in the Editor;
the Android player continues to use device tracking. Stop and restart Play mode
after changing simulator startup settings.

Runtime `Status`, `World Origin`, `World Direction`, `Hit Kind`, `Hit Point`,
`Hit Target` and `Hit Distance` are visible on the components. Consumers should
read results in LateUpdate after these components (execution order above 300):

```csharp
if (gazeSource.HasValidSample)
{
    Vector3 direction = gazeSource.WorldDirection;
    if (gazeRaycaster.HasHit)
    {
        EyeGazeHit hit = gazeRaycaster.Hit;
        Vector3 point = hit.Point;
        GameObject target = hit.Target;
    }
}
```

`EndPoint` includes the distance-limited endpoint when no surface is hit; only
`HasHit` identifies an actual landing point.

## Device lifecycle and validation

Eye tracking is enabled on `PXR_Manager` in the XR Rig and in
`Assets/Resources/PXR_ProjectSetting.asset`. The local SDK build processor uses
that setting to add `com.picovr.permission.EYE_TRACKING` and the eye tracking
manifest metadata during an authorized future build.

On Android, checking **EyeTracking** starts real SDK eye tracking after the
support/state checks. Unchecking it clears the ray and stops the component's owned
session. A running session is reused; the component only stops a session that
it started. Pausing or disabling the component stops its owned session. Losing Unity/XR focus clears
the visualization and suspends sampling. Service checks/retries default to two
seconds, while pose validity is checked every rendered frame.

Calibration is not forced by default. Complete device calibration before
checking accuracy, or enable `Request Calibration On First Start` to request it
once for the first session started by this component. SDK permission/service
failures and unsupported devices are reported in `Status` and `[EyeGaze]` logs.
Enabling the feature does not guarantee that a particular device/firmware
provides supported, valid eye tracking data.

`python tools/ai/validate_eye_gaze.py` validates asset references and compiles
Editor and Android C# using existing Unity 2022.3.16f1 compiler references. It
does not build an APK.

`Tools > XRoboToolkit > Validate Eye Gaze` runs real Unity API checks in a
temporary additive scene, restores the active scene, and checks coordinates,
invalid vectors, colliders, world UI, occlusion, filters, shader import and
prefab references. It does not enter Play mode or change the user's scene.
Device gaze data, calibration accuracy and on-headset stereo rendering require
separate device validation.
