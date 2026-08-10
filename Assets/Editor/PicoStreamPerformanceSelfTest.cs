using System;
using System.IO;
using UnityEditor;
using UnityEditor.Build;
using UnityEngine;

public static class PicoStreamPerformanceSelfTest
{
    [MenuItem("Tools/Validation/Pico Stream Performance Self-Test")]
    public static void Run()
    {
        try
        {
            AssertCloudVideoProfile();
            AssertLegacyProfileMigration();
            AssertMicrophoneCapturePlan();
            Debug.Log("PICO_STREAM_PERFORMANCE_SELF_TEST=PASS");
        }
        catch (Exception exception)
        {
            throw new BuildFailedException(
                $"Pico stream performance self-test failed: {exception}");
        }
    }

    private static void AssertLegacyProfileMigration()
    {
        string path = Path.Combine(Application.streamingAssetsPath, "video_source.yml");
        string currentYaml = File.ReadAllText(path);
        if (LegacyPicoVideoProfileMigration.TryMigrate(currentYaml, out _))
        {
            throw new InvalidOperationException("Current low-latency profile must be idempotent");
        }

        string legacyYaml = currentYaml
            .Replace("value: 1280", "value: 2160")
            .Replace("value: 480", "value: 810")
            .Replace("value: 15", "value: 60")
            .Replace("value: 1000000", "value: 20971520");
        if (!LegacyPicoVideoProfileMigration.TryMigrate(legacyYaml, out string migratedYaml))
        {
            throw new InvalidOperationException("Known beta.7 profile was not migrated");
        }
        AssertContains(migratedYaml, "value: 1280", "migrated width");
        AssertContains(migratedYaml, "value: 480", "migrated height");
        AssertContains(migratedYaml, "value: 15", "migrated FPS");
        AssertContains(migratedYaml, "value: 1000000", "migrated bitrate");

        string customYaml = legacyYaml.Replace("value: 60", "value: 30");
        if (LegacyPicoVideoProfileMigration.TryMigrate(customYaml, out _))
        {
            throw new InvalidOperationException("Customized video profile must be preserved");
        }
    }

    private static void AssertCloudVideoProfile()
    {
        string path = Path.Combine(Application.streamingAssetsPath, "video_source.yml");
        VideoSource pico4U = VideoSourceYamlParser.ParseYamlFile(path)
            .Find(source => string.Equals(source.name, "PICO4U", StringComparison.OrdinalIgnoreCase));
        if (pico4U == null)
        {
            throw new InvalidOperationException("PICO4U source is missing");
        }

        AssertEqual(1280, pico4U.GetIntProperty("CamWidth"), "PICO4U width");
        AssertEqual(480, pico4U.GetIntProperty("CamHeight"), "PICO4U height");
        AssertEqual(15, pico4U.GetIntProperty("CamFPS"), "PICO4U FPS");
        AssertEqual(1000000, pico4U.GetIntProperty("CamBitrate"), "PICO4U bitrate");
    }

    private static void AssertMicrophoneCapturePlan()
    {
        AssertEqual(320, MicrophoneCapturePlan.ChunkFrames(16000, 20), "16 kHz chunk");
        AssertEqual(960, MicrophoneCapturePlan.ChunkFrames(48000, 20), "48 kHz chunk");
        AssertEqual(100, MicrophoneCapturePlan.AvailableFrames(200, 100, 1000), "linear");
        AssertEqual(150, MicrophoneCapturePlan.AvailableFrames(50, 900, 1000), "wrapped");
        AssertEqual(400, MicrophoneCapturePlan.BacklogSkipFrames(2000, 1600), "backlog");
        AssertEqual(
            0,
            MicrophoneCapturePlan.BacklogSkipForSingleChunkBudget(319, 320),
            "short latest chunk");
        AssertEqual(
            0,
            MicrophoneCapturePlan.BacklogSkipForSingleChunkBudget(320, 320),
            "exact latest chunk");
        AssertEqual(
            0,
            MicrophoneCapturePlan.BacklogSkipForSingleChunkBudget(640, 320),
            "normal two chunk buffer");
        AssertEqual(
            321,
            MicrophoneCapturePlan.BacklogSkipForSingleChunkBudget(641, 320),
            "backlog latest chunk");
        AssertEqual(
            1680,
            MicrophoneCapturePlan.BacklogSkipForSingleChunkBudget(2000, 320),
            "large backlog latest chunk");
        AssertEqual(0, MicrophoneCapturePlan.ConsumableFrames(319, 320), "short chunk");
        AssertEqual(320, MicrophoneCapturePlan.ConsumableFrames(320, 320), "exact chunk");
        AssertEqual(960, MicrophoneCapturePlan.ConsumableFrames(1000, 320), "whole chunks");
        AssertEqual(320, MicrophoneCapturePlan.ConsumableFrames(350, 320), "wrapped chunk");
    }

    private static void AssertContains(string value, string expected, string context)
    {
        if (!value.Contains(expected))
        {
            throw new InvalidOperationException($"Missing {context}: {expected}");
        }
    }

    private static void AssertEqual(int expected, int actual, string context)
    {
        if (expected != actual)
        {
            throw new InvalidOperationException(
                $"{context}: expected={expected} actual={actual}");
        }
    }
}
