using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Unity.XR.CoreUtils;
using Unity.XR.CoreUtils.Editor;
using UnityEditor;
using UnityEditor.PackageManager;
using UnityEditor.PackageManager.Requests;
using UnityEngine;
using UnityEngine.SceneManagement;


namespace ByteDance.PICO.CameraPack
{
    static class CameraProjectValidation
    {
        const string k_Category_Required = "PICO CameraPack Required";
        const string k_Category_Recommended = "PICO CameraPack Recommended";
        const string k_ManifestCameraFeature = "android.permission.CAMERA";
        static readonly string ManifestFolder = Path.Combine(Application.dataPath, "Plugins", "Android");
        const string k_PackageId = "com.unity.ai.inference";
        private static AddRequest _addRequest;

        static readonly string DefaultManifestContent = @"<?xml version=""1.0"" encoding=""utf-8""?>
<manifest
    xmlns:android=""http://schemas.android.com/apk/res/android""
    xmlns:tools=""http://schemas.android.com/tools"">
    <uses-permission android:name=""android.permission.CAMERA"" />
    <application>
        <activity android:name=""com.unity3d.player.UnityPlayerActivity""
                  android:theme=""@style/UnityThemeSelector"">
            <intent-filter>
                <action android:name=""android.intent.action.MAIN"" />
                <category android:name=""android.intent.category.LAUNCHER"" />
            </intent-filter>
            <meta-data android:name=""unityplayer.UnityActivity"" android:value=""true"" />
        </activity>
    </application>
</manifest>
";

        [InitializeOnLoadMethod]
        static void AddRequiredRules()
        {
            var androidGlobalRules = new[]
            {
                new BuildValidationRule
                {
                    Category = k_Category_Required,
                    Message = "The TrackingOriginMode needs to be set to \"Floor\" in XR Origin.",
                    IsRuleEnabled = IsValidationEnabled(),
                    CheckPredicate = IsXROriginFloor,
                    FixItMessage = "Set TrackingOriginMode to \"Floor\" in XR Origin.",
                    FixIt = () =>
                    {
                        var xrOrigins = FindComponentsInScene<XROrigin>().ToList();
                        foreach (var xrOrigin in xrOrigins)
                        {
                            Debug.Log($"xrOrigin.RequestedTrackingOriginMode: {xrOrigin.RequestedTrackingOriginMode}");
                            xrOrigin.RequestedTrackingOriginMode = XROrigin.TrackingOriginMode.Floor;
                        }
                    },
                    Error = true
                },
                new BuildValidationRule
                {
                    Category = k_Category_Required,
                    Message =
                        $"To use the PICO Camera Api you need to add the \"{k_ManifestCameraFeature}\" permission in your AndroidManifest.xml.",
                    IsRuleEnabled = IsValidationEnabled(),
                    CheckPredicate = HasCameraPermission,
                    FixItMessage =
                        $"Open AndroidManifest.xml in /Plugins/Android folder and add the \"{k_ManifestCameraFeature}\" permission.",
                    FixIt = () =>
                    {
                        var manifestPath = Path.Combine(ManifestFolder, "AndroidManifest.xml");
                        if (File.Exists(manifestPath))
                        {
                            var manifestContent = File.ReadAllText(manifestPath);
                            if (!manifestContent.Contains(k_ManifestCameraFeature))
                            {
                                if (manifestContent.Contains("</manifest>"))
                                {
                                    manifestContent = manifestContent.Replace("</manifest>",
                                        $"    <uses-permission android:name=\"{k_ManifestCameraFeature}\" />\n</manifest>");
                                }
                                else
                                {
                                    manifestContent += $"\n<uses-permission android:name=\"{k_ManifestCameraFeature}\" />";
                                }
                                File.WriteAllText(manifestPath, manifestContent);
                                AssetDatabase.Refresh();
                            }
                        }
                        else
                        {
                            if (!Directory.Exists(ManifestFolder))
                            {
                                Directory.CreateDirectory(ManifestFolder);
                            }

                            File.WriteAllText(manifestPath, DefaultManifestContent);
                            AssetDatabase.Refresh();
                        }
                    },
                    Error = true
                }
#if UNITY_6000
                , new BuildValidationRule
                {
                    Category = k_Category_Recommended,
                    Message = "Using recommended 'using Unity.InferenceEngine' package.",
                    IsRuleEnabled = IsValidationEnabled(),
                    CheckPredicate = () =>
                    {
                        bool isUnityAI = false;
#if UNITY_AI_INFERENCE
                        isUnityAI = true;
#endif
                        return isUnityAI;
                    },
                    FixItMessage =
                        "Open PackageManager Settings > Unity Registry > Inference Engine.",
                    FixIt = () => { _addRequest = Client.Add(k_PackageId); },
                    Error = false
                }
#endif
            };
            BuildValidator.AddRules(BuildTargetGroup.Android, androidGlobalRules);
        }


        private static bool HasCameraPermission()
        {
            var manifestPath = Path.Combine(ManifestFolder, "AndroidManifest.xml");
            if (File.Exists(manifestPath))
            {
                var manifestContent = File.ReadAllText(manifestPath);
                return manifestContent.Contains(k_ManifestCameraFeature);
            }

            return false;
        }

        public static Func<bool> IsValidationEnabled()
        {
            return () =>
                FindComponentsInScene<PXR_CamTextureManager>().Any(component => component.isActiveAndEnabled);
        }

        public static bool GetValidationIssues()
        {
            var isEnabled = IsValidationEnabled();
            if (!isEnabled())
            {
                return true;
            }
            return HasCameraPermission() && IsXROriginFloor();
        }

        private static bool IsXROriginFloor()
        {
            bool isFloor = true;
            var xrOrigins = FindComponentsInScene<XROrigin>().ToList();
            foreach (var xrOrigin in xrOrigins)
            {
                isFloor &= xrOrigin.RequestedTrackingOriginMode ==
                                   XROrigin.TrackingOriginMode.Floor;
            }

            return isFloor;
        }

        public static List<T> FindComponentsInScene<T>() where T : Component
        {
            var activeScene = SceneManager.GetActiveScene();
            var foundComponents = new List<T>();

            var rootObjects = activeScene.GetRootGameObjects();
            foreach (var rootObject in rootObjects)
            {
                var components = rootObject.GetComponentsInChildren<T>(true);
                foundComponents.AddRange(components);
            }

            return foundComponents;
        }
    }
}