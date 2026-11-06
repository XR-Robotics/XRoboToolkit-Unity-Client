using System;
using System.Linq;
using System.Reflection;
using ByteDance.PICO.XR;
using UnityEditor;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.Controls;
using UnityEngine.XR;

public static class HandButtonValidation
{
    [MenuItem("Tools/XRoboToolkit/Validate Hand Buttons")]
    public static void Run()
    {
        var hand = PicoHandInteraction.CreateHand(InputDeviceCharacteristics.Right);
        InputActionAsset actions = null;
        try
        {
            actions = UnityEngine.Object.Instantiate(AssetDatabase.LoadAssetAtPath<InputActionAsset>(
                "Assets/InteractionTools/PICO Input Actions.inputactions"));
            var press = actions.FindAction("XRI RightHand Interaction/UI Press", true);
            int performed = 0;
            int canceled = 0;
            press.performed += context => performed++;
            press.canceled += context => canceled++;
            press.Enable();

            var update = typeof(PicoHandInteraction).GetMethods(BindingFlags.Instance | BindingFlags.NonPublic)
                .Single(method => method.Name == "UpdateHand" && method.GetParameters()[0].ParameterType == typeof(bool));
            var stateType = update.GetParameters()[1].ParameterType.GetElementType();
            var poseType = stateType.GetField("gripPose").FieldType;
            var flagsType = stateType.Assembly.GetType("ByteDance.PICO.XR.PxrHandInteractionLocationFlags", true);
            ulong validFlags = Convert.ToUInt64(Enum.Parse(flagsType, "PositionValid, OrientationValid"));
            var buttons = new[] { hand.pinchReady, hand.pinchTouched, hand.pointerActivateReady,
                hand.pointerActivated, hand.graspReady, hand.graspFirm, hand.isTracked };

            foreach (bool pressed in new[] { true, false })
            {
                object state = Activator.CreateInstance(stateType);
                object pose = Activator.CreateInstance(poseType);
                poseType.GetField("isActive").SetValue(pose, pressed);
                poseType.GetField("locationFlags").SetValue(pose, validFlags);
                stateType.GetField("gripPose").SetValue(state, pose);
                stateType.GetField("aimPose").SetValue(state, pose);
                foreach (string field in new[] { "pinchReady", "aimActivateReady", "graspReady" })
                    stateType.GetField(field).SetValue(state, pressed);
                foreach (string field in new[] { "pinchValue", "aimActivateValue", "graspValue" })
                    stateType.GetField(field).SetValue(state, pressed ? 1f : 0f);
                update.Invoke(hand, new[] { (object)pressed, state });
                InputSystem.Update();
                foreach (ButtonControl button in buttons)
                {
                    float expected = pressed ? 1f : 0f;
                    if (!Mathf.Approximately(button.ReadValue(), expected) || button.isPressed != pressed)
                        throw new InvalidOperationException($"{button.name}: expected {expected}, read {button.ReadValue()}");
                }
                if (press.IsPressed() != pressed)
                    throw new InvalidOperationException($"Right UI Press did not follow the button: {press.phase}");
            }
            if (performed != 1 || canceled != 1)
                throw new InvalidOperationException($"UI Press events: performed={performed}, canceled={canceled}");
            Debug.Log("[HandButtonValidation] PASS: seven BYTE buttons read 1/0; right UI Press performed and canceled once.");
        }
        finally
        {
            if (actions != null)
            {
                actions.Disable();
                UnityEngine.Object.DestroyImmediate(actions);
            }
            InputSystem.RemoveDevice(hand);
        }
    }
}
