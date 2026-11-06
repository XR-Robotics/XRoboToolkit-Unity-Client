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
namespace ByteDance.PICO.Debugger
{
    // Drives which control PXR_CustomItemFactory builds for a [PICODebuggerItem]
    // member. Not wrapped in #if so user code that references it compiles in all
    // build configurations (the debugger UI that consumes it stays dev-only).
    public enum DebuggerType
    {
        Default,
        Range,
        Toggle,
        Action
    }
}
