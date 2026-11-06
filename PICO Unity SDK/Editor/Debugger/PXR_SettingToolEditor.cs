/*******************************************************************************
Copyright © 2015-2022 PICO Technology Co., Ltd.All rights reserved.  

NOTICE：All information contained herein is, and remains the property of 
PICO Technology Co., Ltd. The intellectual and technical concepts 
contained herein are proprietary to PICO Technology Co., Ltd. and may be 
covered by patents, patents in process, and are protected by trade secret or 
copyright law. Dissemination of this information or reproduction of this 
material is strictly forbidden unless prior written permission is obtained from
PICO Technology Co., Ltd. 
*******************************************************************************/
#if UNITY_EDITOR
using System.Collections.Generic;
using System.Linq;
using UnityEditor;
using UnityEditor.UIElements;
using UnityEngine;
using UnityEngine.UIElements;
using System;
using ByteDance.PICO.XR.Editor;
using UnityEngine.InputSystem;
using System.IO;


namespace ByteDance.PICO.Debugger
{
    // Generate a setting item in the editor project settings screen
    static class SettingToolEditor
    {
        [SettingsProvider]
        public static SettingsProvider CreateMyCustomSettingsProvider()
        {
            var config = PXR_PicoDebuggerSO.Instance;

            var provider = new SettingsProvider("Project/PICO Debugger", SettingsScope.Project)
            {
                label = "PICO Debugger",
                activateHandler = (obj, rootElement) =>
                {
                    var visualTree = AssetDatabase.LoadAssetAtPath<VisualTreeAsset>($"{PXR_Utils.sdkPackageName}{PXR_DebuggerConst.uiPath}{PXR_DebuggerConst.debuggerXMLName}");
                    var rootVisualElement = visualTree.Instantiate();
                    rootElement.Add(rootVisualElement);

                    var isOpenToggle = rootVisualElement.Q<Toggle>("IsOpen");
                    var inputActionAsset = rootVisualElement.Q<ObjectField>("InputActionAsset");
                    var startPositionDropdown = rootVisualElement.Q<DropdownField>("StartPosition");
                    var maxInfoCountSlider = rootVisualElement.Q<SliderInt>("MaxInfoCount");

                    var worldPositionStepSlider = rootVisualElement.Q<Slider>("WorldPositionStep");
                    var localPositionStepSlider = rootVisualElement.Q<Slider>("LocalPositionStep");
                    var worldRotationStepSlider = rootVisualElement.Q<Slider>("WorldRotationStep");
                    var localRotationStepSlider = rootVisualElement.Q<Slider>("LocalRotationStep");
                    var worldScaleStepSlider = rootVisualElement.Q<Slider>("WorldScaleStep");

                    Debug.Assert(isOpenToggle != null, $"{isOpenToggle} is Null");
                    Debug.Assert(inputActionAsset != null, $"{inputActionAsset} is Null");
                    Debug.Assert(startPositionDropdown != null, $"{startPositionDropdown} is Null");
                    Debug.Assert(maxInfoCountSlider != null, $"{maxInfoCountSlider} is Null");
                    Debug.Assert(worldPositionStepSlider != null, $"{worldPositionStepSlider} is Null");
                    Debug.Assert(localPositionStepSlider != null, $"{localPositionStepSlider} is Null");
                    Debug.Assert(worldRotationStepSlider != null, $"{worldRotationStepSlider} is Null");
                    Debug.Assert(localRotationStepSlider != null, $"{localRotationStepSlider} is Null");
                    Debug.Assert(worldScaleStepSlider != null, $"{worldScaleStepSlider} is Null");

                    isOpenToggle.value = config.isOpen;
                    isOpenToggle.RegisterValueChangedCallback(evt =>
                    {
                        config.isOpen = evt.newValue;
                        EditorUtility.SetDirty(config); // Mark as dirty to save the changes
                        if (config.isOpen)
                        {
                            PXR_AppLog.PXR_OnEvent($"{PXR_AppLog.strPICODebugger}", PXR_AppLog.strPICODebugger_Enable, "enable");
                            if (!Directory.Exists("Assets/TextMesh Pro"))
                            {
                                bool userConfirmed = EditorUtility.DisplayDialog(
                                    "Import TextMesh Pro",                  // dialog title
                                    "The PICO Debugger depends on TextMesh Pro. Should TextMesh Pro be imported to ensure the normal operation of the debugger function?", // dialog content
                                    "Yes",                             // confirm button text
                                    "Cancel"                              // cancel button text
                                );
                                if (userConfirmed)
                                {
                                    // Try to locate the TMP Essential Resources unitypackage.
                                    // Unity ships it inside the package folder; the exact location
                                    // varies between Unity versions, so search by asset name.
                                    string tmpPackagePath = null;
                                    string[] guids = AssetDatabase.FindAssets("TMP Essential Resources");
                                    foreach (var guid in guids)
                                    {
                                        var p = AssetDatabase.GUIDToAssetPath(guid);
                                        if (p.EndsWith(".unitypackage", StringComparison.OrdinalIgnoreCase))
                                        {
                                            tmpPackagePath = p;
                                            break;
                                        }
                                    }

                                    if (!string.IsNullOrEmpty(tmpPackagePath))
                                    {
                                        // Use AssetDatabase.ImportPackage with callbacks so we can
                                        // detect whether the user cancelled the import in the
                                        // "Import Unity Package" window. ExecuteMenuItem is
                                        // fire-and-forget and cannot detect cancellation.
                                        // interactive: true keeps the import dialog so the user
                                        // can confirm or cancel, which is required for the
                                        // importPackageCancelled callback to fire.
                                        AssetDatabase.importPackageCompleted += OnTMPImpPackageCompleted;
                                        AssetDatabase.importPackageCancelled += OnTMPImpPackageCancelled;
                                        AssetDatabase.ImportPackage(tmpPackagePath, true);
                                    }
                                    else
                                    {
                                        // Could not locate the TMP Essential Resources .unitypackage.
                                        // Roll back Enable and ask the user to import TMP manually.
                                        config.isOpen = false;
                                        isOpenToggle.value = false;
                                        EditorUtility.SetDirty(config);
                                        Debug.LogWarning("Unable to locate TextMesh Pro Essential Resources automatically. Please import TMP Essential Resources manually via Window > TextMeshPro > Import TMP Essential Resources, then enable PICO Debugger again.");
                                    }
                                }
                                else
                                {
                                    Debug.Log("User canceled the import of TextMesh Pro Essential Resources.");
                                    isOpenToggle.value = false;
                                    config.isOpen = false;
                                    EditorUtility.SetDirty(config);
                                }
                            }
                        }
                    });

                    var inputActionPath = $"{PXR_Utils.sdkPackageName}{PXR_DebuggerConst.debuggerPath}{PXR_DebuggerConst.inputActionName}";
                    if (!string.IsNullOrEmpty(inputActionPath))
                    {
                        var loadedAsset = AssetDatabase.LoadAssetAtPath<InputActionAsset>(inputActionPath);
                        // If the loading is successful, assign it to ObjectField
                        if (loadedAsset != null)
                        {
                            inputActionAsset.value = loadedAsset;
                            config.inputActionAsset = loadedAsset;
                        }
                        else
                        {
                            Debug.LogWarning($"The corresponding resource file cannot be found under the path {inputActionPath}.");
                        }

                    }

                    startPositionDropdown.choices = Enum.GetNames(typeof(StartPosiion)).ToList();
                    startPositionDropdown.index = (int)config.startPosition;
                    startPositionDropdown.RegisterValueChangedCallback(evt =>
                    {
                        config.startPosition = (StartPosiion)Enum.Parse(typeof(StartPosiion), evt.newValue);
                        EditorUtility.SetDirty(config);
                    });

                    maxInfoCountSlider.value = config.maxInfoCount;
                    maxInfoCountSlider.RegisterValueChangedCallback(evt =>
                    {
                        config.maxInfoCount = Mathf.RoundToInt(evt.newValue);
                        EditorUtility.SetDirty(config);
                    });

                    worldPositionStepSlider.value = config.worldPositionStep;
                    worldPositionStepSlider.RegisterValueChangedCallback(evt =>
                    {
                        config.worldPositionStep = evt.newValue;
                        EditorUtility.SetDirty(config);
                    });

                    localPositionStepSlider.value = config.localPositionStep;
                    localPositionStepSlider.RegisterValueChangedCallback(evt =>
                    {
                        config.localPositionStep = evt.newValue;
                        EditorUtility.SetDirty(config);
                    });

                    worldRotationStepSlider.value = config.worldRotationStep;
                    worldRotationStepSlider.RegisterValueChangedCallback(evt =>
                    {
                        config.worldRotationStep = evt.newValue;
                        EditorUtility.SetDirty(config);
                    });

                    localRotationStepSlider.value = config.localRotationStep;
                    localRotationStepSlider.RegisterValueChangedCallback(evt =>
                    {
                        config.localRotationStep = evt.newValue;
                        EditorUtility.SetDirty(config);
                    });

                    worldScaleStepSlider.value = config.worldScaleStep;
                    worldScaleStepSlider.RegisterValueChangedCallback(evt =>
                    {
                        config.worldScaleStep = evt.newValue;
                        EditorUtility.SetDirty(config);
                    });

                    AssetDatabase.Refresh();
                },
                keywords = new HashSet<string>(new[] { "PICO", "Debugger Tool" })
            };
            return provider;
        }

        /// <summary>
        /// Called by AssetDatabase when a package import is completed.
        /// If TMP was successfully imported, "Assets/TextMesh Pro" should now exist,
        /// so we just clean up the callback and keep Enable checked.
        /// </summary>
        private static void OnTMPImpPackageCompleted(string packageName)
        {
            AssetDatabase.importPackageCompleted -= OnTMPImpPackageCompleted;
            AssetDatabase.importPackageCancelled -= OnTMPImpPackageCancelled;

            if (!Directory.Exists("Assets/TextMesh Pro"))
            {
                // Import completed but the expected folder is still missing.
                // Roll back the Enable toggle to reflect reality.
                var config = PXR_PicoDebuggerSO.Instance;
                config.isOpen = false;
                EditorUtility.SetDirty(config);
                AssetDatabase.SaveAssets();
                Debug.LogWarning("TextMesh Pro import completed, but 'Assets/TextMesh Pro' was not found. Enable has been rolled back.");
                // Refresh the Settings window so the Toggle visually reflects the rollback.
                EditorApplication.delayCall += SettingsService.NotifySettingsProviderChanged;
            }
        }

        /// <summary>
        /// Called by AssetDatabase when the user cancels a package import.
        /// Roll back the Enable toggle since TMP was not imported.
        /// </summary>
        private static void OnTMPImpPackageCancelled(string packageName)
        {
            AssetDatabase.importPackageCompleted -= OnTMPImpPackageCompleted;
            AssetDatabase.importPackageCancelled -= OnTMPImpPackageCancelled;

            var config = PXR_PicoDebuggerSO.Instance;
            config.isOpen = false;
            EditorUtility.SetDirty(config);
            AssetDatabase.SaveAssets();
            Debug.Log("User canceled the import of TextMesh Pro Essential Resources. Enable has been rolled back.");
            // Refresh the Settings window so the Toggle visually reflects the rollback.
            EditorApplication.delayCall += SettingsService.NotifySettingsProviderChanged;
        }
    }
}
#endif