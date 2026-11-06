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
using ByteDance.PICO.Platform.CLIB;

namespace ByteDance.PICO.Platform.Models
{
    public class KVPairArray
    {
        public uint Size { get; private set; }
        IntPtr Handle;

        public IntPtr GetHandle()
        {
            return Handle;
        }

        public KVPairArray(uint size)
        {
            Size = size;
            Handle = CLIB.CLIB.ppf_KeyValuePairArray_Create((UIntPtr) size);
        }

        ~KVPairArray()
        {
            CLIB.CLIB.ppf_KeyValuePairArray_Destroy(Handle);
            Handle = IntPtr.Zero;
        }

        public KVPair GetElement(uint index)
        {
            return new KVPair(CLIB.CLIB.ppf_KeyValuePairArray_GetElement(Handle, (UIntPtr) index));
        }
    }

    public class KVPair
    {
        IntPtr Handle;
        bool destroyable = true;

        public KVPair()
        {
            Handle = CLIB.CLIB.ppf_KeyValuePair_Create();
        }

        public KVPair(IntPtr o)
        {
            Handle = o;
            destroyable = false;
        }

        public void SetIntValue(int value)
        {
            CLIB.CLIB.ppf_KeyValuePair_SetIntValue(Handle, value);
        }

        public void SetStringValue(string value)
        {
            CLIB.CLIB.ppf_KeyValuePair_SetStringValue(Handle, value);
        }

        public void SetDoubleValue(double value)
        {
            CLIB.CLIB.ppf_KeyValuePair_SetDoubleValue(Handle, value);
        }

        public int GetIntValue()
        {
            return CLIB.CLIB.ppf_KeyValuePair_GetIntValue(Handle);
        }

        public string GetStringValue()
        {
            return CLIB.CLIB.ppf_KeyValuePair_GetStringValue(Handle);
        }

        public double GetDoubleValue()
        {
            return CLIB.CLIB.ppf_KeyValuePair_GetDoubleValue(Handle);
        }

        public void SetKey(string key)
        {
            CLIB.CLIB.ppf_KeyValuePair_SetKey(Handle, key);
        }

        public string GetKey()
        {
            return CLIB.CLIB.ppf_KeyValuePair_GetKey(Handle);
        }

        public KVPairType GetValueType()
        {
            return (KVPairType) CLIB.CLIB.ppf_KeyValuePair_GetValueType(Handle);
        }

        ~KVPair()
        {
            if (destroyable)
            {
                CLIB.CLIB.ppf_KeyValuePair_Destroy(Handle);
                Handle = IntPtr.Zero;
            }
        }
    }  
}