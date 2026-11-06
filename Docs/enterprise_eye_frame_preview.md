# Enterprise EyeFrame preview

The **Data sync** card now includes **EyeFrame** in a two-by-two stream grid with
**Head**, **Controller** and **Hand**.
Checking it opens a preview panel to the right of the main dashboard and starts
capture once the enterprise service is ready. The dashboard remains visible and
interactive. **Close** or unchecking **EyeFrame** stops capture, clears the
checkbox and hides only the preview panel. The preview shows four raw camera
images separately, with dimensions and the SDK timestamp in nanoseconds:

| Camera ID | SDK camera label |
| --- | --- |
| 15 | Top Left |
| 16 | Top Right |
| 17 | Bottom Left |
| 18 | Bottom Right |

These are camera images, not computed gaze vectors or gaze targets. Camera IDs
are not mapped to anatomical left/right eyes. **Flip Y** changes display
orientation only; confirm the sensor row order with the SDK owner.

## Selected dependency

The project retains Unity 2022.3.16f1 and uses local PICO Unity SDK 6.1.1 at
`file:../PICO Unity SDK` through `com.bytedance.pico.xr`. The enterprise client is
`Enterprise/android/tobservicelib-0.6.0-alpha.0.aar`, with Android import enabled.
The bundled `tobservicelib-release.aar` Android importer is disabled. Keep
`tob_api-release.aar` enabled because it adapts `ByteDance.PICO.Enterprise` to the
alpha client's `com.pvr.tobservice` interfaces. Keep only one ToB client.

Selected AAR SHA-256:
`53d1cee59fb116c98eefa4cdd05d68656f525858b423013c87f48da2f35e2882`.

Bytecode inspection and reflection against the actual alpha AAR confirmed:

```java
ToBServiceHelper.getInstance().getEyeTrackingManager();
void setListener(EyeTrackingListener listener);
int setConfig(EyeOutputConfig config);
int startCapture();
int stopCapture();
```

The `com.pvr.tobservice.eyetracking` package provides `EyeFrame`,
`EyeTrackingListener`, `EyeTrackingManager`, and `EyeOutputConfig`. `EyeFrame`
has public `long timestamp`, `int id/width/height`, and `byte[] data` fields.
The listener provides `onFrameAvailable(EyeFrame)` and `onError(int)`.

The acquisition sequence is:

1. Bind the ToB service.
2. Obtain `ToBServiceHelper.getInstance().getEyeTrackingManager()`.
3. Set `EyeOutputConfig.targetFps = 30` through `setConfig`.
4. Register `setListener(EyeTrackingListener)`.
5. Call `startCapture()`.
6. Receive `onFrameAvailable(EyeFrame)` or `onError(int)`.

The bridge reuses the project's existing `PXR_Enterprise.BindEnterpriseService`
notification. It does not call `bindTobService` again or replace its callback.
It resolves public fields or Java/Kotlin getters through reflection, allowing
the project to compile against its current dependency and report missing
capabilities at runtime.

The client restricts `targetFps` to 30 through 90 inclusive and returns `-3`
outside this range. The bridge requests 30 Hz to reduce service-to-app traffic;
the preview still refreshes at up to 15 Hz per camera. A configuration failure
prevents capture from starting.

`setListener(null)` unregisters the listener. `startCapture() == -1` can also
mean that the service is not ready or a service call threw an exception.
It must not be interpreted as proof of missing `enableET` authorization.

Before declaring real capture verified, confirm supported firmware and
enterprise authorization, plus the pixel format, row stride and image
orientation. This preview interprets exactly `width * height` bytes as packed
Gray8; byte-array length alone does not prove that pixel interpretation.

## Runtime behavior

`EnterpriseEyeFrameBridge.java` handles SDK capability checks and callback data
ownership. It copies data before the SDK callback returns and keeps three
bounded slots per camera; leased slots are never overwritten. Preview copies
are limited to 15 Hz per camera, with a 1 MiB per-frame limit. Unknown IDs,
invalid dimensions/timestamps or incompatible lengths stop the session with a
diagnostic instead of interpreting an unknown buffer.

`EnterpriseEyeFrameSource.cs` acquires and releases JNI frame leases on Unity's
main thread, copying leased direct buffers into reusable managed arrays rather
than allocating a JNI byte array for each frame.
`EnterpriseEyeFramePreview.cs` uploads them into reusable R8
textures using the grayscale shader in Resources. Frames older than two
seconds are hidden to avoid displaying a frozen image as current data.

Checking **EyeFrame** queues one capture start while the enterprise service is
binding. **Stop**, **Close**, application pause/focus loss, component destruction
and service disconnection cancel that pending start and stop capture. Capture
errors do not trigger automatic retries. Resume requires **Start**, or unchecking
and checking **EyeFrame** again. SDK callback errors are cleaned
up by the polling thread; failed cleanup requires an explicit Stop before a new
session can start.

The EyeFrame components use a dedicated assembly whose package version definition
enables `PICO_XR` for PICO Unity SDK 6.1.1 and later. The predefined
`Assembly-CSharp` also receives project `PICO_XR` and `ENABLE_PICO_XR_SDK` symbols.
All JNI calls also require Android and exclude the Editor.
Frame dimensions must remain stable within a capture session.

Each camera logs its first frame with ID, size, byte count and the full
nanosecond timestamp. Every two seconds, `[EnterpriseEyeFrames]` logs
`previewFrames`, `previewHz`, `lastTimestampNs` and `bytes` for IDs 15 through 18.
These counts describe frames delivered to Unity's preview, not the sensor's
native sampling frequency.

The dashboard and EyeFrame side panel are authored directly in `Assets/Main.unity`.
The preview is anchored to the Canvas right edge with a 24-unit gap. Its width
is 599.8 units and its height matches the main Panel. It pivots around its left
edge with a local Y rotation of 30 degrees, folding the right edge toward the
viewer. Its local Z offset is -50 units (15 cm at the authored UI scale), bringing
the whole preview closer. Adjust the EyeFramePreview RectTransform's Y rotation
and Z position in the Inspector to tune viewing comfort.
Both panels exist before Play mode and can be edited through the Hierarchy and
Inspector:

```text
UIOperate
  Canvas
    Panel
      OperateDashboard
        NetworkPanel
        TrackingPanel/Toggles/StreamControls/Streams/EyeFrameToggle
        CameraPanel
        DataCollection
        Log
    EyeFramePreview (inactive by default)
      BackButton
      CaptureState
      Cameras
        Topleft/Viewport/Image
        Topright/Viewport/Image
        Bottomleft/Viewport/Image
        Bottomright/Viewport/Image
      CaptureMessage
      StartButton
      StopButton
      FlipButton
```

`UIOperate.EyeFrameTog`, its source and its preview references are serialized in
the scene. The preview component on the `UIOperate` owner references the main
page, preview page, four RawImages, labels and buttons. Keep that component and
the source outside both pages so hiding the main page does not disable capture.
The image, frame-label and empty-label arrays are ordered by IDs 15 through 18.

To edit the preview in Scene view, temporarily deactivate `Panel` and activate
`EyeFramePreview`. Restore the main page to active and the preview to inactive
when finished. The image slots show waiting messages until sensor frames arrive.
The scene includes the layout groups, aspect fitters, colors, fonts and the
sliced sprite `Assets/Art/XRoboUIRounded.png`; no runtime UI factory or dashboard
reparenting remains.

Data-source, sampling-rate, camera and recording bindings retain their original
component IDs and owners. `DataSource` and `CollectionRate` remain siblings;
sampling controls stay conditional on the selected data source. The scene
stores listening/recording action labels in `CustomButton`. Runtime code only
binds interactions, controls capture, updates state and uploads image textures.
`XRoboUIStyle` holds semantic colors for live sensor status.

The preview places navigation and capture state at the top, camera names/IDs
above the images, frame metadata below, and diagnostics plus Start/Stop/Flip
controls at the bottom. Empty and stale cameras show explicit messages.

EyeFrames are not written to collection files or added to the existing TCP
protocol. Head/controller collection stays on its existing path.

## Validation

Local validation uses the installed JDK and Unity 2022.3 compiler references;
it does not build an APK. A fake ToB client can exercise callback copying,
lease ownership, late callbacks, invalid payloads and capture errors, but does
not establish device/firmware compatibility.

The static scene conversion also passed complete YAML parsing with the locally
installed YamlDotNet parser, file-ID and parent/child reference checks, preserved
business reference/event checks, and layout dimension checks at the authored
599.8 x 723.3 canvas size. The final preview assembly and `Assembly-CSharp`
compiled for both Editor and Android conditions. See
`main_scene_ui_validation_20261103.json`. These checks do not establish Unity
Editor scene import, pointer interaction or device rendering.

The November 3 validation passed:

- Actual alpha AAR method/field reflection without initializing its Android
  manager on Windows.
- Java 8 bridge compilation and callback/lease lifecycle fixtures, including
  30 Hz configuration, rejected configuration, byte-array reuse, bounded leases,
  late callbacks and concurrent producers.
- Synthetic 640x480 frames using the actual alpha SDK `EyeFrame` type for IDs
  15 through 18, preserving all 307200 bytes and 64-bit timestamps across copies.
  These inputs were generated on the host and are not captured eye images.
- Editor and Android component compilation and the `UIOperate` integration
  against Unity 2022.3.16f1. The cached player ToB assembly predates existing USB
  network methods, so a temporary assembly was compiled from the local SDK
  sources. Existing compiled caches were not overwritten.
- Android importer selection at validation time: alpha enabled, old release
  disabled. The old release AAR and its metadata were subsequently removed.

Results and tool output are in `enterprise_eye_frame_validation_20261103.json`
and `enterprise_eye_frame_validation_20261103.log`.
The log also contains negative-control checks performed against the old release
AAR before its removal. Its missing EyeFrame accessors were expected and do not
describe the selected alpha client.

Read-only device checks found Swan B3110, serial `PB321XJGL3090095G`,
firmware `6.2.0`, ToB service `5.9.0`, and the system
`pxreyetrackingservice` binder. The project package `com.xrobotoolkit.client`
was not found, and there were no existing `[EnterpriseEyeFrames]` logs.
The presence of the system eye service does not establish that the enterprise
raw-frame API works or is authorized.

Real sensor capture and shader rendering remain unverified. Building and
installing a test APK require the separate authorization specified in
`AGENTS.md`. Once authorized, install the updated app and check **EyeFrame** in
**Data Sync**. Verify increasing timestamps and nonzero counts for all four IDs,
image format/orientation, Stop/Start, Close and checkbox reset, pause/resume and
service loss.

Read the frame diagnostics without clearing device logs:

```powershell
adb -s PB321XJGL3090095G logcat -d -v threadtime | Select-String 'EnterpriseEyeFrames'
```
