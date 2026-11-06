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
#if ENABLE_PICO_OPENXR_SDK
using ByteDance.PICO.OpenXR;
#endif
using UnityEngine;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System;
using UnityEditor;

namespace ByteDance.PICO.XR.Editor
{
#if UNITY_EDITOR
    public static class PXR_InstallPreprocessor
    {
        /// <summary>
        /// Delete the configuration files left over from the old version.
        /// </summary>
        [InitializeOnLoadMethod]
        private static void PreHandler(){
            
        }
        private static void DeleteLegacyConfigFiles()
        {
            // bool hasPromptedBefore = EditorPrefs.GetBool("PXR_LegacyConfigCleaner_Prompted_UpdateV0.8.0", false);

            // if (!hasPromptedBefore){
                // bool userWantsToDelete = EditorUtility.DisplayDialog(
                // "Whether to delete the PICO configuration", // title
                // "Project upgrades may cause abnormal portal functions. If you choose No, it is recommended to manually clean up the relevant configurations", // msg
                // "Yes, clean it up immediately", // "OK" button
                // "No, handle it manually later"  // "Cancel" button
                // );

                // if (userWantsToDelete)
                // {
                //     PerformDeletion();
                // }
                // EditorPrefs.SetBool("PXR_LegacyConfigCleaner_Prompted_UpdateV0.8.0", true);
            // }
        }
        private static void PerformDeletion(){
            string resourcesPath = Path.Combine(Application.dataPath, "Resources");
            if (!Directory.Exists(resourcesPath)) return;

            string[] files = Directory.GetFiles(resourcesPath, "PXR_*", SearchOption.AllDirectories);

            foreach (string filePath in files)
            {
                string fileNameWithExtension = Path.GetFileName(filePath);
                string fileNameWithoutExtension = Path.GetFileNameWithoutExtension(filePath);
                bool isInWhitelist = Array.Exists(PXR_Utils.LegacyConfigFilesWhitelist, element => (element == fileNameWithExtension || element == fileNameWithoutExtension));

                if (filePath.EndsWith(".meta") || isInWhitelist) continue;
                Debug.Log($"{fileNameWithExtension} file");
                
                File.Delete(filePath);
                if(File.Exists(filePath + ".meta")) File.Delete(filePath + ".meta");
                
                // Debug.Log($"{filePath} has deleted");
            }
            
            // Refresh Editor
            UnityEditor.AssetDatabase.Refresh();

        }
    }
#endif
}