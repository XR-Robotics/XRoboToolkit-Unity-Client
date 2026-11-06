# InteractionPack Module Documentation

## 1. Module Overview
`InteractionPack` is a lightweight interaction extension package for the PICO XR SDK, built on top of the **Unity XR Interaction Toolkit**. It is primarily aimed at addressing complex **Hand Tracking** and **Eye Tracking** interaction needs in VR/MR development, providing an out-of-the-box interaction solution.

The core value of this module lies in:
*   **Multi-modal Fusion**: Unified management of Controller and bare-hand input, supporting automatic switching.
*   **Algorithm Enhancement**: Built-in OneEuroFilter and nonlinear gain algorithms, significantly improving the stability and precision of bare-hand operations.
*   **UI Interaction Extension**: Enhances standard UI components, supporting advanced interaction events such as eye gaze, hand pinch, double-click/long-press.

---

## 2. Directory Structure

| Path | Description |
| :--- | :--- |
| **Scripts/Base/** | **Low-level algorithm library**. Includes filtering algorithms (`OneEuroFilter`), drag smoothing algorithms (`HandDragFrame`), tap detection (`Tap`), etc. |
| **Scripts/Feature/** | **Core feature logic**. Includes interaction manager, interactor implementations (Aim/Pinch), UI enhancement components. |
| **Scripts/Input/** | **Input system adaptation**. Custom Input Layout (`PXR_InteractionLayout`), interfacing with Unity Input System. |
| **Scripts/Utils/** | **Utility classes**. Includes camera utilities, math calculation helpers, etc. |
| **Param/** | **Configuration files**. ScriptableObjects storing interaction parameters (such as rotation/scaling sensitivity). |
| **Param/** | **Configuration files**. ScriptableObjects storing interaction parameters (such as rotation/scaling sensitivity). |
---

## 3. Core Components

### 3.1 Interaction Manager: PXR_InteractorManager
*   **Location**: `Scripts/Feature/PXR_InteractorManager.cs`
*   **Role**: The singleton manager of the entire interaction system.
*   **Core Features**:
    *   **Input Mode Management**: Monitors the current input device (Controller vs. bare hand) and maintains the `CurrentInputMode` state.
    *   **Event Dispatch**: Uniformly dispatches global gesture events such as `PinchDown` and `PinchUp`.
    *   **Data Center**: Maintains `InteractionData`, updating shared data such as HMD position, gaze direction, cursor position in real time.

### 3.2 Aim Interactor: PXR_AimInteractor
*   **Location**: `Scripts/Feature/PXR_AimInteractor.cs`
*   **Role**: Responsible for "pointing" and "aiming".
*   **Core Features**:
    *   **Dual Mode Support**: Supports both EyeGaze (eye tracking) and Hand Ray (hand ray) aiming methods.
    *   **Cursor Management**: Controls the position, rotation, and scale of the Cursor in the scene.
    *   **Interaction Detection**: Performs raycasting to determine the target object the user is currently focusing on.

### 3.3 Pinch Interactor: PXR_PinchInteractor
*   **Location**: `Scripts/Feature/PXR_PinchInteractor.cs`
*   **Role**: Responsible for "confirmation" and "operation".
*   **Core Features**:
    *   **Motion Capture**: Handles finger pinch motions, calculating per-frame displacement (`PositionChange`) and rotation (`RotationChange`).
    *   **State Machine**: Maintains the `Began` -> `Moved` -> `Ended` interaction lifecycle.
    *   **Algorithm Integration**: Calls `HandDragFrame` to smooth raw hand data.

### 3.4 Interaction Transformers
Extensions of XR Interaction Toolkit's `XRBaseGrabTransformer`:
*   **HandDragTransformer**: `Scripts/Feature/Transformer/HandDragTransformer.cs`
    *   Used for grabbing and dragging 3D objects, integrated with smoothing algorithms for a more natural feel.
*   **PXR_DragHandleTransformer**: `Scripts/Feature/Transformer/PXR_DragHandleTransformer.cs`
    *   Dedicated drag logic for UI handles or specific controls.

### 3.5 Core Prefabs
*   **XR Origin (VR).prefab**: 
    *   **Location**: `Prefabs/XR Origin (VR).prefab`
    *   **Role**: Standardized starting point for interaction scenes.
    *   **Integrated Content**:
        *   Standard `XR Origin` structure (Camera Offset, Main Camera).
        *   `PXR_InteractorManager`: Core interaction management singleton.
        *   `PXR_AimInteractor`: Preconfigured ray/eye gaze interactor.
        *   Necessary controller and gesture interaction configurations.
    *   **Advantage**: Drag into the scene to directly gain full gesture/controller interaction capabilities, no need to manually assemble individual scripts.

---

## 4. Key Algorithms and Optimizations

### 4.1 Smart Anti-shake and Distance-based Gain (HandDragFrame)
*   **Location**: `Scripts/Base/HandDragFrame.cs`
*   **Problem**: In bare-hand interaction, tiny physiological hand tremors can cause distant objects to shake violently (lever effect).
*   **Solution**:
    *   **OneEuroFilter**: Performs real-time filtering on hand coordinates, maintaining low latency during fast motion and eliminating jitter during slow motion.
    *   **Nonlinear Gain (Distance/Speed Gain)**: 
        *   When the hand moves extremely slowly, suppresses object movement (anti-drift).
        *   When the hand moves quickly, amplifies object movement (improving efficiency).
        *   Dynamically adjusts the gain coefficient based on the object's distance, solving the problem of long-distance operations.

### 4.2 Advanced Tap Recognition (Tap)
*   **Location**: `Scripts/Base/Tap.cs`
*   **Function**: On top of pure "press/release", encapsulates the following events using time threshold detection:
    *   **Click**: Single click
    *   **DoubleClick**: Double click
    *   **LongPress**: Long press

---

## 5. UI System Enhancement

### 5.1 PXR_EnhancedButton
*   **Location**: `Scripts/Feature/UI/PXR_EnhancedButton.cs`
*   **Description**: An XR-compatible super button.
*   **Usage**: Attach to a uGUI Button object.
*   **Capabilities**:
    *   Supports standard `OnClick`.
    *   Adds `OnDoubleClick` and `OnLongPress` callbacks.
    *   Automatically adapts to controller buttons and gesture pinches.
.  **Scene Setup (Recommended)**:
    *   Delete the default Camera in the scene.
    *   Drag `Prefabs/XR Origin (VR)prefab` into the scene.
     This prefab already includes `XR Origin`, `PXR_InteractorManager`, and the necessary interactors, ready out of the box.
2.  *Manual (Advanced)
### 5.2 PXR_ScrollFrame
*   **Location**: `Scripts/Feature/UI/PXR_ScrollFrame.cs`
*   **Description**: List scroll container.
3   **Capabilities**: Allows users to drag and scroll a list by gazing at it and pinching their fingers, providing an experience similar to swiping on a mobile touchscreen.

---

## 6. Usage Guide

1.  **Scene Setup**:
    *   Ensure the scene contains an `XR Origin`.
    *   Add the `PXR_InteractorManager` component (usually as a singleton).
    *   Configure `PXR_AimInteractor` for ray/eye gaze detection.
2.  **Object Interaction**:
    *   Add `XRGrabInteractable` to the target object.
    *   Add `HandDragTransformer` to `Grab Transformers`.
3.  **UI Interaction**:
    *   Use a World Space Canvas.
    *   Add the `PXR_EnhancedButton` script to the Button.
