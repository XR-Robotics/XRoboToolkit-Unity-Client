using System.Linq;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.Layouts;

[ExecuteInEditMode]
public class HandSupport : MonoBehaviour
{
    private void OnDeviceAdded(string name)
    {
        InputSystem.AddDevice(
            new InputDeviceDescription
            {
                interfaceName = "PicoHandSDKAPI",
                product = name
            });
    }

    private void OnDeviceRemoved(string name)
    {
        var device = InputSystem.devices.FirstOrDefault(
            x => x.description == new InputDeviceDescription
            {
                interfaceName = "PicoHandSDKAPI",
                product = name,
            });

        if (device != null)
            InputSystem.RemoveDevice(device);
    }

    void Start()
    {
        InputSystem.RegisterLayout<PicoHandDevice>(
            matches: new InputDeviceMatcher()
                .WithInterface("PicoHandSDKAPI"));
        
        OnDeviceAdded("PicoHandController");
    }

    private void OnDestroy()
    {
        OnDeviceRemoved("PicoHandController");
    }
}