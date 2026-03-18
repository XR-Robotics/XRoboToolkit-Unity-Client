# Unity + Android Mixed Project Demo (Form B)

This is a minimal example of a Unity + Android mixed project structure, following the **Form B: Unity Main + Android Plugin** approach, as seen in `LSpaceLib` and `LSpaceU3d`.

## Structure

```
unity_android_mix_demo/
├── android/                 # Android Library Project (Plugin Source)
│   ├── android_plugin/      # Android Library Module
│   │   ├── src/main/java/   # Java/Kotlin Source (Plugin logic)
│   │   ├── build.gradle     # Library build config
│   │   └── ...
│   ├── build.gradle         # Root build configuration
│   └── settings.gradle      # Project settings
├── unity/                   # Unity Project (Main Entry)
│   ├── Assets/
│   │   ├── Plugins/Android/ # Where the built AAR will be placed
│   │   ├── Scripts/         # C# Scripts to call Android Plugin
│   │   └── Editor/Build.cs  # Unity Build Script
│   └── ...
├── scripts/                 # Build Automation Scripts
│   ├── build_plugin.sh      # 1. Build Android Library -> Copy AAR to Unity
│   └── build_apk.sh         # 2. Build Unity Project -> APK
└── ...
```

## Workflow

The development workflow consists of two main steps:

1.  **Develop Android Plugin**: Write Java/Kotlin code in `android/android_plugin`.
2.  **Integrate & Build**:
    *   Run `./scripts/build_plugin.sh` to compile the Android code into an `.aar` file and copy it to `unity/Assets/Plugins/Android/`.
    *   Open Unity to use the plugin functionality (e.g., via `AndroidJavaObject`).
    *   Run `./scripts/build_apk.sh` (or build from Unity Editor) to generate the final APK.

## Usage

### Prerequisites

1.  **Unity Editor**: Ensure you have a compatible Unity version installed. Update `scripts/build_apk.sh` with your Unity path.
2.  **Android SDK & NDK**: Required for building both the plugin and the final APK.

### Step 1: Build the Plugin

```bash
./scripts/build_plugin.sh
```

This will:
*   Build `android_plugin-release.aar`.
*   Copy it to `unity/Assets/Plugins/Android/android_plugin.aar`.

### Step 2: Build the APK

```bash
./scripts/build_apk.sh
```

This will:
*   Launch Unity in batch mode.
*   Build the project using the AAR plugin.
*   Output the APK to `build/android/UnityAndroidMixDemo.apk`.

## Key Concepts

*   **Android Plugin**: The `android/android_plugin` module encapsulates native Android functionality. It is built independently as an AAR.
*   **Unity Integration**: Unity consumes the AAR via the `Plugins/Android` folder. The build system automatically merges manifests and resources.
*   **Interaction**: C# scripts in Unity communicate with the Android plugin using `AndroidJavaClass` and `AndroidJavaObject`.

## References

*   Based on the internal guide: `TTP Unity Android 混编工程执行操作指南`
*   Structure aligned with: `LSpaceLib` (Library Producer) and `LSpaceU3d` (Library Consumer)
