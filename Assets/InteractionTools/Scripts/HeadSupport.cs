using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.Layouts;

// This example uses a MonoBehaviour with [ExecuteInEditMode]
// on it to run the setup code. You can do this many other ways.
[ExecuteInEditMode]
public class HeadSupport : MonoBehaviour
{
    private void OnDeviceAdded(string name)
    {
        // Feed a description of the Device into the system. In response, the
        // system matches it to the layouts it has and creates a Device.
        InputSystem.AddDevice(
            new InputDeviceDescription
            {
                interfaceName = "PicoHeadSDKAPI",
                product = name
            });
    }

    private void OnDeviceRemoved(string name)
    {
        var device = InputSystem.devices.FirstOrDefault(
            x => x.description == new InputDeviceDescription
            {
                interfaceName = "PicoHeadSDKAPI",
                product = name,
            });

        if (device != null)
            InputSystem.RemoveDevice(device);
    }

    // Move the registration of MyDevice from the
    // static constructor to here, and change the
    // registration to also supply a matcher.
    void Start()
    {
        // Add a match that catches any Input Device that reports its
        // interface as "ThirdPartyAPI".

        // Debug.Log("----Test---- Start Register Layout.");
        InputSystem.RegisterLayout<PicoHeadDevice>(
            matches: new InputDeviceMatcher()
                .WithInterface("PicoHeadSDKAPI"));
        // Debug.Log("----Test---- Register Layout End.");
        
        // Debug.Log("----Test---- Start Add Device.");
        OnDeviceAdded("PicoHeadController");
        // Debug.Log("----Test---- Add Device End.");
    }

    private void OnDestroy()
    {
        OnDeviceRemoved("PicoHeadController");
    }
}
