#!/bin/bash
set -e

# Define paths
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
ANDROID_PROJECT_PATH="$PROJECT_ROOT/android"
UNITY_PROJECT_PATH="$PROJECT_ROOT/unity"
EXPORT_OUTPUT_PATH="$PROJECT_ROOT/build/exported_project"
FINAL_APK_PATH="$PROJECT_ROOT/build/android/UnityAndroidMixDemo.apk"

# Updated Unity Editor path
UNITY_EXECUTABLE="/Applications/Unity/Hub/Editor/2021.3.45f2/Unity.app/Contents/MacOS/Unity" 
LOG_FILE="$PROJECT_ROOT/unity_build.log"

# Set JAVA_HOME for Gradle (Java 11 for Unity 2021 export)
export JAVA_HOME="/Users/bytedance/Library/Java/JavaVirtualMachines/ms-11.0.26/Contents/Home"

echo "Starting Unity Export..."
echo "Project Path: $UNITY_PROJECT_PATH"
echo "Export Path: $EXPORT_OUTPUT_PATH"
echo "Unity Executable: $UNITY_EXECUTABLE"

if [ ! -f "$UNITY_EXECUTABLE" ]; then
    echo "Error: Unity executable not found at $UNITY_EXECUTABLE"
    exit 1
fi

mkdir -p "$(dirname "$FINAL_APK_PATH")"

# Export the project
"$UNITY_EXECUTABLE" \
  -quit \
  -batchmode \
  -nographics \
  -projectPath "$UNITY_PROJECT_PATH" \
  -executeMethod Build.ExportAndroidProject \
  -logFile "$LOG_FILE"

if [ $? -ne 0 ]; then
  echo "Unity export failed. Check log at $LOG_FILE"
  tail -n 50 "$LOG_FILE"
  exit 1
fi

echo "Unity export successful."

# Now build the exported project with Gradle
echo "Building exported project with Gradle..."
cd "$EXPORT_OUTPUT_PATH"

# Copy gradlew if missing (Unity sometimes doesn't generate it or uses different structure)
if [ ! -f "gradlew" ]; then
    echo "Copying gradlew from android project..."
    cp "$ANDROID_PROJECT_PATH/gradlew" .
    cp "$ANDROID_PROJECT_PATH/gradlew.bat" .
    mkdir -p gradle
    cp -r "$ANDROID_PROJECT_PATH/gradle/wrapper" gradle/
fi

# Ensure gradlew is executable
chmod +x gradlew

# Build
./gradlew assembleRelease

# Copy APK to final destination
# The APK location in exported project depends on structure. Usually launcher/build/outputs/apk/release/launcher-release.apk
EXPORTED_APK="launcher/build/outputs/apk/release/launcher-release.apk"

if [ -f "$EXPORTED_APK" ]; then
    cp "$EXPORTED_APK" "$FINAL_APK_PATH"
    echo "Build successful. APK located at $FINAL_APK_PATH"
else
    echo "Error: Exported APK not found at $EXPORTED_APK"
    # List outputs to help debugging
    find . -name "*.apk"
    exit 1
fi
