#!/bin/bash
set -e

# Assuming script is run from project root
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
ANDROID_PROJECT_PATH="$PROJECT_ROOT/android"
UNITY_PLUGINS_PATH="$PROJECT_ROOT/unity/Assets/Plugins/Android"

# Set JAVA_HOME to Java 11 for compatibility with Unity 2021
export JAVA_HOME="/Users/bytedance/Library/Java/JavaVirtualMachines/ms-11.0.26/Contents/Home"

echo "Starting Android Plugin build..."
echo "Using JAVA_HOME: $JAVA_HOME"
cd "$ANDROID_PROJECT_PATH"

# Ensure gradlew is executable
chmod +x gradlew

# Build Release AAR
./gradlew clean :android_plugin:assembleRelease

echo "Build successful. Copying AAR to Unity..."

# Define source and destination
AAR_SOURCE="$ANDROID_PROJECT_PATH/android_plugin/build/outputs/aar/android_plugin-release.aar"
# If using AGP 8.0+, path might be different, checking...
if [ ! -f "$AAR_SOURCE" ]; then
    # Fallback or check other paths if needed
    echo "Warning: AAR not found at expected path: $AAR_SOURCE"
    # Try finding it
    AAR_SOURCE=$(find "$ANDROID_PROJECT_PATH/android_plugin/build/outputs/aar" -name "*.aar" | head -n 1)
fi

if [ -f "$AAR_SOURCE" ]; then
    mkdir -p "$UNITY_PLUGINS_PATH"
    cp "$AAR_SOURCE" "$UNITY_PLUGINS_PATH/android_plugin.aar"
    echo "AAR copied to $UNITY_PLUGINS_PATH/android_plugin.aar"
else
    echo "Error: AAR file could not be found!"
    exit 1
fi

echo "Android Plugin build and copy completed."
