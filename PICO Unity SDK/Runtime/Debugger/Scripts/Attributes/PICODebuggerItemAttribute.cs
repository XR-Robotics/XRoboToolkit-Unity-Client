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
namespace ByteDance.PICO.Debugger
{
    // Member-level marker for fields / properties / methods that should appear in
    // the Custom panel right detail list.
    //
    // Usage:
    //   [PICODebuggerItem]                                         -> Default (read-only)
    //   [PICODebuggerItem(DebuggerType.Range, min = 0f, max = 10f)] -> Slider
    //   [PICODebuggerItem(DebuggerType.Toggle)]                    -> Toggle (bool)
    //   [PICODebuggerItem(DebuggerType.Action)]                    -> Button (no-arg void method)
    //
    // Note: C# attributes cannot take another attribute (e.g. Range(..)) as an
    // argument, so the slider bounds are plain min/max fields here.
    [AttributeUsage(AttributeTargets.Field | AttributeTargets.Property | AttributeTargets.Method,
        Inherited = true, AllowMultiple = false)]
    public class PICODebuggerItemAttribute : Attribute
    {
        public DebuggerType type = DebuggerType.Default;
        // Range bounds (only used when type == DebuggerType.Range).
        public float min = 0f;
        public float max = 1f;
        // Optional label override; falls back to the member name when empty.
        public string displayName = null;

        public PICODebuggerItemAttribute()
        {
        }

        public PICODebuggerItemAttribute(DebuggerType type)
        {
            this.type = type;
        }
    }
}
