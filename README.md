# XRoboToolkit-Unity-Client Project Documentation

## Project Overview
`XRoboToolkit-Unity-Client` is a Unity-based software developed for PICO devices to facilitate robot training and remote teleoperation. It works in conjunction with PC-side software to achieve robot training and teleoperation functionalities.

## Unity UI Main Panel Reference

![ui.png](Docs/ui.png)

| Item                                           | Description                                                                                              |
|------------------------------------------------|----------------------------------------------------------------------------------------------------------|
| Network - SN                                   | Display Serial number of the XR device, only functional with Pico 4 Ultra enterprise version             |
| Network - IP                                   | IP address of the XR device                                                                              |
| Network - FPS                                  | Data syncing frames per second                                                                           |
| Network - Status                               | Connection status between robot and XR device                                                            |
| Network - PC Service                           | IP address of the PC running PC service                                                                  |
| Network - Enter                                | Manually input the PC service's IP                                                                       |
| Tracking - Head                                | Toggle On/Off to send out head 6 DoF pose                                                                |
| Tracking - Controller                          | Toggle On/Off to parse VR controller's 6 DoF pose and button status in data stream                       |
| Tracking - Hand                                | Toggle On/Off to parse hand tracking data in data stream                                                 |
| Tracking - PICO Motion Tracker - Mode          | Dropdown menu to select None, full body tracking (require Pico tracker) to parse in data stream          |
| Tracking - PICO Motion Tracker - TrackerNum    | Number of the trackers                                                                                   |
| Tracking - Data & Control - Send               | Toggle On/Off to sync above selected poses between XR device and robot PC                                |
| Tracking - Data & Control - Switch w/ A Button | Toggle On/Off to rapid pause or resume sync with  the right-hand controller button A                     |
| Tracking - Info                                | Panel to show tracking related information                                                               |
| Camera - Dropdown (Video Source)               | Select a supported video source (configured in the `video_source.yml` file)                              |
| Camera - Listen                                | Open a connection to receive the video stream to the selected video source (used on human operator side) |
| Camera - Save Camera Parameters                | Save camera intrinsic and extrinsic parameters in local path                                             |
| Camera - Record                                | Record data                                                                                              |
| Camera - Camera State                          | Panel to show the camera status (available on the VR headset serving as robot eyes)                      |

## Feature list
- **Pose sync between XR device and robot PC**
  Transmits pose data from the XR headset to the robot-side PC for robot teleoperation.
- **Local pose and stereo vision data collection**
  Synchronously records stereo vision and pose data collected from the XR headset, stored in the device's `/Download` directory.
- **Remote stereo vision sync between two XR headsets**
  Transmits stereo vision from the robot-side headset to operator-side for 3D display.
- **Remote stereo vision sync between PC camera and XR headset**
  Transmits stereo vision from the robot-side PC camera to operator-side headset for 3D display.
## Feature instructions

### Pose sync between XR device and robot PC
1. Connect robot PC and Pico 4 Ultra under the same network
2. On robot PC, run service:
   - **Windows**: Run `\Program Files (x86)\roboticsservice\runService.bat`
   - **Linux (Ubuntu/Debian x86)**: Run `/opt/apps/roboticsservice/runService.sh`
3. Open app XR-Robotics-Toolkit-Unity-Sample on Pico 4 Ultra

If the PC service is running successfully, when you open the app on Pico headset, you will receive a prompt window for server connection. Point to the IP address and click it with the trigger button on the controller.

<div align="center">
  <img src="Docs/pc_service_connection.png" alt="pc_service_connection" width="387"/>
</div>

The main panel will display "WORKING" if connection is established.

<div align="center">
  <img src="Docs/pc_service_connected.png" alt="pc_service_connected" width="394"/>
</div>

On the main panel, select preferred pose information to be synced, such as head tracking, controller tracking, or body tracking. If your headset and PC have established connection, then the pose data will be synced to PC when "Send" is toggled On. When "Switch w/ A Button" option toggles On, you may also use "A" button on the right controller to toggle "Send" On or Off during data syncing.

### Local pose and stereo vision data collection

**Note:** At this moment, camera data collection still requires special approval through Pico's enterprise service.

On the main panel, select preferred pose data to be collected, click Record. You will see a brief blur effect on the screen, record button will turn red, and camera status will turn to 6. When you finish recording, press recording button again to end the collection session. The video files and pose files will be saved on your local headset. You may also click "Save Camera Parameters" to save camera intrinsic and extrinsic parameters for the local headset.

### Remote stereo vision sync between two XR headsets

1. Connect both XR headsets to the same network.
2. Make sure that the camera to be used as the camera source has VST camera permission (requires special approval).
3. Open **XRRoboToolkit** on both headsets.
> **Note:** The headset serving as robot eyes (H1) should have the camera permission enabled, while the other headset (H2) is for the human operator side.
4. H1: Remember the IP of the VR headset and **DON'T DO ANYTHING**.
5. H2: On the Camera panel, Select **PICO4U** as the video source, Click Listen, input H1's IP, and click Confirm.
6. H2: You should now be able to see the live camera. Press B button on the right-hand controller to switch between side-by-side views and stereo-3D views.
7. H2: If you close the live camera window, you can simply repeat Step 5.
8. If you want to stop the camera streaming, quit **XRRoboToolkit** on H1 and H2.

### Remote stereo vision sync between ZED camera (Orin) and XR headset

1. Clone [XRoboToolkit-Orin-Video-Sender](https://github.com/XR-Robotics/XRoboToolkit-Orin-Video-Sender.git) on Orin.
2. Build 
3. Run the following command on Orin:
   ```bash
   ./OrinVideoSender --listen <IP of Orin>:13579
   ```
4. Open **XRRoboToolkit** on the XR headset.
5. On the Camera panel, select "ZEDMINI" as the video source.
6. Click "Listen", input the IP of Orin, and click Confirm.
7. You should now be able to see the live camera. Press B button on the right-hand controller to switch between side-by-side views and stereo-3D views.
8. If you close the live camera window, you can simply repeat Step 6.
9. If you want to stop the camera streaming, quit **XRRoboToolkit** on the XR headset and stop the OrinVideoSender on Orin.


## Directory Structure

### Assets
Core resource folder containing all project assets:
- **InteractionTools**
  XR interaction scripts and 3D models.
- **Plugins**
  Android interface implementations including `robotassistant_lib.aar` and Android platform configurations.
- **Resources**
  Project-specific assets.
- **Scripts**
  Core application logic:
  - **Camera**
    Camera-related functionality.
  - **ExtraDev**
    PICO tracker peripheral integration.
  - **Network**
    Network communication implementation.
  - **UI**
    User interface components.

### robotassistant_lib.aar
Android library containing PICO device interfaces and image processing logic.

### Key Classes
- **UIOperater**
  UI interaction logic.
- **UICameraCtrl**
  Camera control implementation.
- **TcpHandler**
  Network data transmission handler.
- **TrackingData**
  Pose data processing module.

### Packages
Managed via Unity Package Manager.

### ProjectSettings
Unity project configuration files:
- Audio/Physics/Input settings
- Quality/Graphics configurations

## PICO Unity Integration SDK
Official SDK for PICO device integration:
[Download Link](https://developer.picoxr.com/en/resources/)

## Project Configuration

### Environment Requirements
- Unity 2022.3.16f1+
- Android Studio 4.2.2+
- Android SDK 29
- Android NDK 21.4.7075529
- PICO Unity SDK 1.1.0 (Recommended)

⚠️ **Important Notes**:
1. Use exact Unity version 2022.3.16f1 to avoid compatibility issues
2. Verify Android SDK/NDK paths in Unity Preferences
3. Ensure PICO SDK compatibility with Unity version
4. Complete Android module installation during Unity setup

### APK Build Process
1. Set platform to Android:
  - File → Build Settings → Android → Switch Platform
2. Configure signing:
  - Player Settings → Publishing Settings
  - Create new Keystore via Keystore Manager for first build
3. Build execution:
  - File → Build Settings → Build (macOS)
  - Output path: `ProjectRoot/ProjectSettings/Android/`

## One-Click Build System

### Activation
- **Hotkeys**:
  - Windows: `Ctrl + Shift + B`
  - macOS: `Cmd + Shift + B`
- **Menu Path**:
  Build → One - click packaging

### Version Management
Auto-increments version number (Format: `Major.Minor.Build`):
- Example: 1.0.0 → 1.0.1 → ... → 1.1.0

### Output Structure
```
ProjectRoot/
└── Builds/
    ├── Android/
    ├── iOS/
    ├── macOS/
    └── Windows/
```

### Post-Build Actions
- **Windows**:
  Automatically opens File Explorer with output file selected
- **macOS**:
  Reveals build output in Finder
- **Universal**:
  Displays build result dialog

### Core Interfaces
- **Hardware Interaction Layer**
  - PICO Enterprise API Calls (Requires Device Permissions)
    ```csharp
    PXR_Enterprise.SwitchSystemFunction(SystemFunctionSwitchEnum.SFS_SECURITY_ZONE_PERMANENTLY, SwitchEnum.S_OFF);
    PXR_Enterprise.OpenVSTCamera(); // Enable VST Passthrough Camera
    ```

- **Image Processing Pipeline**
  - Android Native Decoder Bridge
    ```csharp
    private static AndroidJavaObject _javaObj = new AndroidJavaObject("com.picovr.robotassistantlib.MediaDecoder");
    public static void initialize(int unityTextureId, int width, int height) {
        GetJavaObject().Call("initialize", unityTextureId, width, height);
    }
    ```

- **Network Transport Layer**
  - Asynchronous UDP Data Reception
    ```csharp
    UdpClient client = new UdpClient(port);
    BeginReceive();
    void BeginReceive() {
        client.BeginReceive(ReceiveCallback, null);
    }
    void ReceiveCallback(IAsyncResult ar) {
        IPEndPoint remoteEP = null;
        byte[] data = client.EndReceive(ar, ref remoteEP);
        // Data parsing...
    }
    ```

- **Data Synchronization Mechanism**
  - `TcpHandler → NetPacket`: Data packet encapsulation
  - `NetPacket → ByteBuffer`: Serialization processing
  - `ByteBuffer → Socket`: Asynchronous transmission
  - `Socket → TcpHandler`: Callback handling

- **Unity Business Logic**
  - IP Address Validation
    ```csharp
    if (!IPAddress.TryParse(ip, out _)) {
        SetRemind(LogType.Error, "The IP format is incorrect!");
        return;
    }
    TcpHandler.Connect(ip); // Trigger TCP connection
    ```

---

### Architecture Overview
- **Cross-Platform Hybrid Architecture**:
  Unity C# layer and Android Java layer communicate via JNI bridge for hardware-accelerated encoding/decoding.

- **Dual Data Channels**:
  - Video Stream: 60 FPS with adaptive QoS
  - Pose Data Channel: 90Hz with low-latency priority

- **Thread Model**:
  | Thread Type          | Responsibilities                          |
  |----------------------|-------------------------------------------|
  | Main Thread          | UI rendering & user input handling       |
  | Worker Thread        | Video encoding/network transmission       |
  | GL Thread            | OpenGL ES texture operations              |

- **Memory Management**:
  Uses ring buffer for video frames to prevent GC stutter.

- **Fault Recovery**:
  - Automatic TCP reconnection
  - Keyframe retransmission support for video decoding

- **Key Performance Metrics**:
  | Metric                     | Value                        |
  |----------------------------|------------------------------|
  | End-to-End Latency          | ~100ms (720P *2 @60FPS)          |
  | Pose Data Packet Size       | 56 bytes/frame               |
  | Video Encoding Bitrate      | 5 Mbps                      |
  | Network Fault Tolerance     | 3 retries + FEC              |

---

### Q&A

- Q: Can not sign the application

![unable_to_sign.png](Docs/unable_to_sign.png)

A: Please refer to this [link](https://developer-cn.picoxr.com/en/document/unity/number-of-apks-associated-with-a-key-exceeds-limit/) for the solution.

- Q: No entitlement info ......

![no_entitlement](Docs/no_entitlement.png)

A: Connect the headset to public internet and run it.

- Q: Failed to connect on Linux.

A: Ensure the PC and headset are in the same WiFi network. Run the 3D application first and then run the Headset App.

---

For technical support or documentation updates, contact the development team.
