using Unity.XR.CoreUtils.Capabilities;
using UnityEngine;
#if UNITY_EDITOR
using UnityEditor;
#endif
namespace ByteDance.PICO.OpenXR.Editor  
{
    class PXR_OpenXR_SDKCapability : CapabilityProfile, ICapabilityModifier
    {
        static CapabilityDictionary m_CurrentCapabilities = new CapabilityDictionary();


        public bool TryGetCapabilityValue(string capabilityKey, out bool capabilityValue)
        {
            return m_CurrentCapabilities.TryGetValue(capabilityKey, out capabilityValue);
        }
    }

}
