using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using ByteDance.PICO.XR.Editor;
using UnityEditor;

namespace ByteDance.PICO.XR.Interaction.Samples.Starter.Editor
{
    class StarterSampleProjectValidation
    {

        static string AutoSetupDoneKey => $"PXR_PICOInteractionDemo_AutoSetupDone:{UnityEngine.Application.dataPath}";


        [InitializeOnLoadMethod]
        static void RegisterProjectValidationRules()
        {
            UnityEngine.Debug.Log("RegisterProjectValidationRules");
            EditorApplication.delayCall += AddRulesAndRunCheck;

        }

        static void AddRulesAndRunCheck()
        {
            if (EditorApplication.isCompiling || EditorApplication.isUpdating)
            {
                EditorApplication.delayCall += AddRulesAndRunCheck;
                return;
            }

            if (!EditorPrefs.GetBool(AutoSetupDoneKey, false))
            {
                UnityEngine.Debug.Log("AddRulesAndRunCheck");
#if !ENABLE_PICO_INTERACTION_PACK
                if (PXR_Utils.SetDefineSymbols("ENABLE_PICO_INTERACTION_PACK"))
                {
                    EditorApplication.delayCall += AddRulesAndRunCheck;
                    return;
                }
#endif
                const string menuPath = "GameObject/PICO Building Blocks/PICO Hand/XRI Hand Interaction";
                const string menuPathAlt = "PICO/PICO Building Blocks/PICO Hand/XRI Hand Interaction";
                var executed = EditorApplication.ExecuteMenuItem(menuPath) || EditorApplication.ExecuteMenuItem(menuPathAlt);
                if (executed)
                {
                    EditorPrefs.SetBool(AutoSetupDoneKey, true);
                }
            }
            else
            {
                UnityEngine.Debug.Log("AddRulesAndRunCheck: Already done");
            }
        }
    }
}
