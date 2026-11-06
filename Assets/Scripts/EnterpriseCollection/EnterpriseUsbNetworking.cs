using System;
using UnityEngine;

namespace Robot
{
    internal static class EnterpriseUsbNetworking
    {
        private enum LegacySystemFunction
        {
            UsbTetheringStaticAddress = 104
        }

        public static string GetLocalAddress() =>
            GetAddress("getUsbTetheringStaticIPLocal", "get_usb_tethering_static_ip_local", "local_addr");

        public static string GetClientAddress() =>
            GetAddress("getUsbTetheringStaticIPClient", "get_usb_tethering_static_ip_client", "client_addr");

        public static int SetStaticAddresses(string localAddress, string clientAddress)
        {
            return WithBinder(binder =>
            {
                try
                {
                    return binder.Call<int>("setUsbTetheringStaticIP", localAddress, clientAddress);
                }
                catch (Exception exception)
                {
                    Debug.LogWarning($"USB static IP direct set unavailable; using fallback: {exception.Message}");
                }
                using (var parameters = new AndroidJavaObject("android.os.Bundle"))
                {
                    parameters.Call("putString", "local_addr", localAddress);
                    parameters.Call("putString", "client_addr", clientAddress);
                    using (AndroidJavaObject result = binder.Call<AndroidJavaObject>(
                        "pbsCommonMessageLocked", "set_usb_tethering_static_ip", parameters))
                    {
                        return result?.Call<int>("getInt", "key_result_code", 1) ?? 1;
                    }
                }
            }, 1);
        }

        public static void EnableStaticAddress()
        {
            WithBinder(binder =>
            {
                using (var parameters = new AndroidJavaObject("android.os.Bundle"))
                {
                    parameters.Call("putInt", "system_function", (int)LegacySystemFunction.UsbTetheringStaticAddress);
                    parameters.Call("putInt", "switch", 0);
                    parameters.Call("putInt", "extension_bit", 0);
                    using (AndroidJavaObject ignored = binder.Call<AndroidJavaObject>(
                        "pbsCommonMessageLocked", "switch_system_function", parameters)) { }
                }
                return true;
            }, false);
        }

        private static string GetAddress(string directMethod, string fallbackMethod, string resultKey)
        {
            return WithBinder(binder =>
            {
                try
                {
                    return binder.Call<string>(directMethod) ?? "";
                }
                catch (Exception exception)
                {
                    Debug.LogWarning($"USB static IP direct get unavailable; using fallback: {exception.Message}");
                }
                using (var parameters = new AndroidJavaObject("android.os.Bundle"))
                using (AndroidJavaObject result = binder.Call<AndroidJavaObject>(
                    "pbsCommonMessageLocked", fallbackMethod, parameters))
                    return result?.Call<string>("getString", resultKey) ?? "";
            }, "");
        }

        private static T WithBinder<T>(Func<AndroidJavaObject, T> operation, T fallback)
        {
#if PICO_XR && UNITY_ANDROID && !UNITY_EDITOR
            try
            {
                using (AndroidJavaObject binder = GetBinder())
                    return binder == null ? fallback : operation(binder);
            }
            catch (Exception exception)
            {
                Debug.LogError($"USB static IP operation failed: {exception}");
            }
#endif
            return fallback;
        }

#if PICO_XR && UNITY_ANDROID && !UNITY_EDITOR
        private static AndroidJavaObject GetBinder()
        {
            using (var helperClass = new AndroidJavaClass("com.pvr.tobservice.ToBServiceHelper"))
            using (AndroidJavaObject helper = helperClass.CallStatic<AndroidJavaObject>("getInstance"))
                return helper.Call<AndroidJavaObject>("getServiceBinder");
        }
#endif
    }
}
