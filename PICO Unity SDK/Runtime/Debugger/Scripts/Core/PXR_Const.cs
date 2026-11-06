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
#if UNITY_EDITOR || DEVELOPMENT_BUILD
namespace ByteDance.PICO.Debugger
{
    public class PXR_DebuggerConst
    {
        public static string sdkPackageName = "Packages/com.bytedance.pico.xr/";
        public static string sdkRootName = "com.bytedance.pico.xr/";
        public static string debuggerPath = "Debugger/";
        public static string uiPath = "Debugger/UI/";
        public static string prefabsPath = "Debugger/Prefabs/";
        public static string resourcePath = "Assets/Resources/";

        public static string inputActionName =  "PICODebuggerActions.inputactions";
        public static string debuggerPanelPrefabName = "DebuggerPanel.prefab";
        public static string debuggerPrefabName = "PICODebugger.prefab";
        public static string debuggerXMLName = "PICODebuggerPanel.uxml";
        public static string soName = "PICODebuggerPanel.uxml";

        
        public static string version = "0.4.2";
        // Action
        public const string debuggerStartButton = "DebuggerStartButton";
        public const string timerControllerButton = "TimerControllerButton";
        public const string rulerControllerButton = "RulerControllerButton";
        public const string rulerReleaseButton = "RulerReleaseButton";
        public const string leftControllerPosition = "LeftControllerPositionAction";
        public const string leftControllerRotation = "LeftControllerRotationAction";
        public const string rightControllerPosition = "RightControllerPositionAction";
        public const string rightControllerRotation = "RightControllerRotationAction";
        public const string actionName = "PICODebugger_XRI_UI";
    }

    public enum StartPosiion
    {
        Far,
        Near,
        Medium,
    }
}
#endif
