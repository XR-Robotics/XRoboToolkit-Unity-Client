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
using System.IO;
using UnityEditor;
using UnityEngine;
using UnityEngine.InputSystem;

namespace ByteDance.PICO.Debugger
{
    [InitializeOnLoad]
    public class PXR_PicoDebuggerSetup
    {
        static PXR_PicoDebuggerSetup()
        {
            EditorApplication.update += Init_PXR_PicoDebuggerSetup;
        }
        static void Init_PXR_PicoDebuggerSetup()
        {
            string currentPanelPath = $"{PXR_DebuggerConst.sdkPackageName}{PXR_DebuggerConst.prefabsPath}{PXR_DebuggerConst.debuggerPanelPrefabName}";
            string targetPanelPath = $"{PXR_DebuggerConst.resourcePath}PXR_DebuggerPanel.prefab";
            string currentEntryPath = $"{PXR_DebuggerConst.sdkPackageName}{PXR_DebuggerConst.prefabsPath}{PXR_DebuggerConst.debuggerPrefabName}";
            string targetEntryPath = $"{PXR_DebuggerConst.resourcePath}PXR_PICODebugger.prefab";

            string currentInputSystemSettingsPath = $"{PXR_DebuggerConst.sdkPackageName}{PXR_DebuggerConst.debuggerPath}{PXR_DebuggerConst.inputActionName}";
            string targetInputSystemSettingsPath = $"{PXR_DebuggerConst.resourcePath}PXR_{PXR_DebuggerConst.inputActionName}";
            
            CreateResource<GameObject>(targetEntryPath, currentEntryPath);
            CreateResource<GameObject>(targetPanelPath, currentPanelPath);
            CreateResource<InputActionAsset>(targetInputSystemSettingsPath, currentInputSystemSettingsPath);
            string currentSoPath = $"{PXR_DebuggerConst.resourcePath}PXR_PicoDebuggerSO.asset";
            if(File.Exists(currentSoPath)){
                var so = AssetDatabase.LoadAssetAtPath<PXR_PicoDebuggerSO>(currentSoPath);
                if(so == null)
                {
                    Debug.LogError("PXR_PicoDebuggerSO asset is missing or corrupted,Please reset settings");
                    return;
                }
                if(AssetDatabase.LoadAssetAtPath<InputActionAsset>(targetInputSystemSettingsPath) == null)
                {
                    Debug.LogError("PXR_InputActionAsset asset is missing or corrupted,Please reset settings");
                    return;
                }
                so.inputActionAsset = AssetDatabase.LoadAssetAtPath<InputActionAsset>(targetInputSystemSettingsPath);
                AssetDatabase.SaveAssets();
                if(so.version != PXR_DebuggerConst.version)
                {
                    Debug.Log("PicoDebuggerSO Version Update,Please reset settings");
                    if(File.Exists(targetPanelPath)){
                        File.Delete(targetPanelPath);
                    }
                    if(File.Exists(targetEntryPath)){
                        File.Delete(targetEntryPath);
                    }
                    File.Delete(currentSoPath);
                }
            }
        }
        static void CreateResource<T>(string targetPath,string currentPath) where T : Object{
            if(!File.Exists(targetPath)){
                if (!Directory.Exists("Assets/Resources"))
                {
                    AssetDatabase.CreateFolder("Assets", "Resources");
                }
                
                if (AssetDatabase.LoadAssetAtPath<T>(currentPath) == null)
                {
                    Debug.LogError("File not found at path: " + currentPath);
                }else{
                    AssetDatabase.CopyAsset(currentPath, targetPath);
                    AssetDatabase.SaveAssets();
                }
                
            }
        }
    }
}
#endif