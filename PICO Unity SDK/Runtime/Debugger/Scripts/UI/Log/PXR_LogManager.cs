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
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
#if UNITY_EDITOR || DEVELOPMENT_BUILD
namespace ByteDance.PICO.Debugger
{
    public class PXR_LogManager : MonoBehaviour, IPXR_PanelManager
    {
        public List<GameObject> infoList = new();
        public List<GameObject> warningList = new();
        public List<GameObject> errorList = new();
        public PXR_LogMessageController errorMessage;
        public PXR_LogMessageController warningMessage;
        public PXR_LogMessageController infoMessage;
        public PXR_TabBarVisualController errorIcon;
        public PXR_TabBarVisualController warningIcon;
        public PXR_TabBarVisualController infoIcon;
        public Transform messageContainer;
        private int ListCount => infoList.Count + warningList.Count + errorList.Count;

        // Queue to buffer log messages received inside the Application.logMessageReceived
        // callback. UI creation (Instantiate) and layout rebuild (ForceRebuildLayoutImmediate)
        // must NOT happen inside that callback because it may fire during Unity's internal
        // graphic rebuild loop, causing infinite recursion and SIGABRT.
        private struct QueuedLogEntry
        {
            public string logString;
            public string stackTrace;
            public LogType type;
        }
        private readonly Queue<QueuedLogEntry> _logQueue = new();
        private bool _isProcessingQueue;
        private void AddMessage(string title, string content, LogType type)
        {
            switch (type)
            {
                case LogType.Error:
                    CreateMessage(title, content, type, errorList, errorMessage, errorIcon);
                    errorIcon.AddMessage();
                    break;
                case LogType.Assert:
                    break;
                case LogType.Warning:
                    CreateMessage(title, content, type, warningList, warningMessage, warningIcon);
                    warningIcon.AddMessage();
                    break;
                case LogType.Log:
                    CreateMessage(title, content, type, infoList, infoMessage, infoIcon);
                    infoIcon.AddMessage();
                    break;
                case LogType.Exception:
                    break;
            }
        }
        private void CreateMessage(string title, string content, in LogType type, in List<GameObject> list, in PXR_LogMessageController template, PXR_TabBarVisualController icon)
        {
            var msg = Instantiate(template, messageContainer).GetComponent<PXR_LogMessageController>();
            msg.Init(title, content);
            // Keep new items consistent with the current filter toggle: if this type
            // is currently filtered out, the new item must start hidden too.
            if (icon != null && icon.transform.TryGetComponent(out Toggle toggle))
            {
                msg.gameObject.SetActive(toggle.isOn);
            }
            var targetList = list;
            msg.SetOnDelete(deleted => DeleteSingleMessage(deleted, targetList, icon));
            list.Add(msg.gameObject);
        }
        private void DeleteSingleMessage(PXR_LogMessageController message, List<GameObject> list, PXR_TabBarVisualController icon)
        {
            if (message == null) return;
            if (list.Remove(message.gameObject))
            {
                icon.RemoveMessage();
            }
            Destroy(message.gameObject);
            LayoutRebuild();
        }
        public void FilterLogs(LogType type, bool isFilter)
        {
            if (_isProcessingQueue) return;
            switch (type)
            {
                case LogType.Error:
                    ToggleLogs(errorList, isFilter);
                    break;
                case LogType.Assert:
                    break;
                case LogType.Warning:
                    ToggleLogs(warningList, isFilter);
                    break;
                case LogType.Log:
                    ToggleLogs(infoList, isFilter);
                    break;
                case LogType.Exception:
                    break;
            }
        }
        private void ToggleLogs(in List<GameObject> list, bool status)
        {
            foreach (var item in list)
            {
                item.SetActive(status);
            }
        }
        void Start()
        {
            Application.logMessageReceived += OnLogMessageReceived;
        }
        private void OnLogMessageReceived(string logString, string stackTrace, LogType type)
        {
            // Do NOT create UI elements or call LayoutRebuild here.
            // This callback can fire during Unity's graphic rebuild loop,
            // causing infinite recursion. Buffer the message and process
            // it in LateUpdate instead.
            _logQueue.Enqueue(new QueuedLogEntry
            {
                logString = logString,
                stackTrace = stackTrace,
                type = type
            });
        }
        void LateUpdate()
        {
            if (_isProcessingQueue || _logQueue.Count == 0) return;
            _isProcessingQueue = true;
            try
            {
                var ui = PXR_UIController.Instance;
                if (ui == null || ui.config == null)
                {
                    _logQueue.Clear();
                    return;
                }
                while (_logQueue.Count > 0 &&
                       ui.config.maxInfoCount > ListCount)
                {
                    var entry = _logQueue.Dequeue();
                    AddMessage(entry.logString, entry.stackTrace, entry.type);
                }
                if (_logQueue.Count > 0)
                {
                    // Capacity reached; discard remaining to avoid unbounded growth.
                    _logQueue.Clear();
                }
                // Call LayoutRebuilder directly (not LayoutRebuild()) because
                // _isProcessingQueue guard would skip the wrapped method.
                LayoutRebuilder.ForceRebuildLayoutImmediate(messageContainer.GetComponent<RectTransform>());
            }
            finally
            {
                _isProcessingQueue = false;
            }
        }
        public void DeleteAllMessages()
        {
            DeleteMessage(infoList, infoIcon);
            DeleteMessage(warningList, warningIcon);
            DeleteMessage(errorList, errorIcon);
        }
        private void DeleteMessage(in List<GameObject> list,in PXR_TabBarVisualController icon){
            for (var i = list.Count-1; i >=0; i--)
            {
                Destroy(list[i], 0.1f);
                infoList.Remove(list[i]);
            }
            icon.ChangeMessageCount(0);
            if(icon.transform.TryGetComponent(out Toggle toggle)){
                toggle.isOn = true;
            }
        }
        void OnEnable()
        {
            LayoutRebuild();
        }
        private void LayoutRebuild()
        {
            if (_isProcessingQueue) return;
            LayoutRebuilder.ForceRebuildLayoutImmediate(messageContainer.GetComponent<RectTransform>());
            // LayoutRebuilder.ForceRebuildLayoutImmediate(transform.parent.GetComponent<RectTransform>());
        }
        public void Init(){
            
        }
        void OnDestroy()
        {
            Application.logMessageReceived -= OnLogMessageReceived;
        }
    }
}
#endif