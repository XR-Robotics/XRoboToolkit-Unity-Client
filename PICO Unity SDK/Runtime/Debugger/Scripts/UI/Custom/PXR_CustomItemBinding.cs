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
using System;
using UnityEngine;
#if UNITY_EDITOR || DEVELOPMENT_BUILD
namespace ByteDance.PICO.Debugger
{
    // Drives the property -> UI direction of an item row. The factory builds a
    // closure that re-reads the member value and pushes it into the row's control
    // (text / toggle / slider) using set-without-notify, and this component calls
    // it once per frame. The UI -> property direction is handled by the control's
    // own onValueChanged listener, so the two together give two-way binding.
    public class PXR_CustomItemBinding : MonoBehaviour
    {
        private Action refresh;

        public void Bind(Action refreshAction)
        {
            refresh = refreshAction;
            // Apply the initial value immediately so the row is correct on the
            // first frame, before Update runs.
            try { refresh?.Invoke(); }
            catch (Exception e) { Debug.LogWarning($"[PICODebugger] binding refresh failed: {e.Message}"); }
        }

        private void Update()
        {
            if (refresh == null) return;
            try { refresh(); }
            catch (Exception e)
            {
                // A failing member read should not spam every frame: drop the
                // binding after the first error.
                Debug.LogWarning($"[PICODebugger] binding refresh failed, unbinding: {e.Message}");
                refresh = null;
            }
        }
    }
}
#endif
