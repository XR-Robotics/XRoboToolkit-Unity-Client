using System.Runtime.InteropServices;
using Unity.XR.PXR;
using UnityEditor;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.Controls;
using UnityEngine.InputSystem.Layouts;
using UnityEngine.InputSystem.LowLevel;
using UnityEngine.InputSystem.Utilities;
using UnityEngine.XR;
using CommonUsages = UnityEngine.InputSystem.CommonUsages;
using InputDevice = UnityEngine.InputSystem.InputDevice;

[StructLayout(LayoutKind.Auto)]
public struct PicoHandDeviceState : IInputStateTypeInfo
{
    public FourCC format => new FourCC('H', 'A', 'N', 'D');

    [InputControl(name = "leftConfirm", layout = "Button", offset = 0)]
    public bool leftConfirm;

    [InputControl(name = "rightConfirm", layout = "Button", offset = 1)]
    public bool rightConfirm;


    [InputControl(name = "leftPinch", layout = "Button", offset = 2)]
    public bool leftPinch;

    [InputControl(name = "rightPinch", layout = "Button", offset = 3)]
    public bool rightPinch;

    [InputControl(layout = "Axis", offset = 4)]
    public float rightPinchStrength;

    [InputControl(layout = "Axis", offset = 8)]
    public float leftPinchStrength;

    [InputControl(layout = "Vector2", displayName = "leftJoystick", offset = 12)]
    public Vector2 leftJoystick;

    [InputControl(layout = "Vector2", displayName = "rightJoystick", offset = 20)]
    public Vector2 rightJoystick;
}

#if UNITY_EDITOR
[InitializeOnLoad]
#endif
[InputControlLayout(displayName = "Pico Hand Device", stateType = typeof(PicoHandDeviceState))]
public class PicoHandDevice : InputDevice, IInputUpdateCallbackReceiver
{
    public ButtonControl leftConfirm { get; private set; }
    public ButtonControl rightConfirm { get; private set; }

    public ButtonControl leftPinch { get; private set; }
    public ButtonControl rightPinch { get; private set; }

    public AxisControl leftPinchStrength { get; private set; }
    public AxisControl rightPinchStrength { get; private set; }

    public Vector2Control leftJoystick { get; protected set; }
    public Vector2Control rightJoystick { get; protected set; }

    protected override void FinishSetup()
    {
        base.FinishSetup();

        leftConfirm = GetChildControl<ButtonControl>("leftConfirm");
        rightConfirm = GetChildControl<ButtonControl>("rightConfirm");

        leftPinch = GetChildControl<ButtonControl>("leftPinch");
        rightPinch = GetChildControl<ButtonControl>("leftPinch");

        leftPinchStrength = GetChildControl<AxisControl>("leftPinchStrength");
        rightPinchStrength = GetChildControl<AxisControl>("rightPinchStrength");

        leftJoystick = GetChildControl<Vector2Control>("leftJoystick");
        rightJoystick = GetChildControl<Vector2Control>("rightJoystick");
    }

    public void OnUpdate()
    {
        var state = new PicoHandDeviceState();

        HandAimState handAimState = new HandAimState();
        PXR_HandTracking.GetAimState(HandType.HandLeft, ref handAimState);
        state.leftConfirm = handAimState.touchStrengthRay > 0.9;

        state.leftPinch = (handAimState.aimStatus & HandAimStatus.AimRayTouched) != 0;
        state.leftPinchStrength = handAimState.touchStrengthRay;


        PXR_HandTracking.GetAimState(HandType.HandRight, ref handAimState);
        state.rightConfirm = handAimState.touchStrengthRay > 0.9;

        state.rightPinch = (handAimState.aimStatus & HandAimStatus.AimRayTouched) != 0;
        state.rightPinchStrength = handAimState.touchStrengthRay;
#if UNITY_EDITOR
        state.rightPinch = Input.GetMouseButton(0);
        state.rightPinchStrength = 1f;
#endif


        InputDevices.GetDeviceAtXRNode(XRNode.LeftHand)
            .TryGetFeatureValue(UnityEngine.XR.CommonUsages.primary2DAxis, out var leftTempAxis2d);
        state.leftJoystick = leftTempAxis2d;

        InputDevices.GetDeviceAtXRNode(XRNode.RightHand)
            .TryGetFeatureValue(UnityEngine.XR.CommonUsages.primary2DAxis, out var rightTempAxis2d);
        state.rightJoystick = rightTempAxis2d;

#if UNITY_EDITOR
        float upDown = Input.GetAxis("Vertical");
        float right = Input.GetAxis("Horizontal");
        if (Mathf.Abs(upDown) > 0.1f || Mathf.Abs(right) > 0.1f)
        {
            state.rightJoystick = new Vector2(right, upDown);
        }

#endif

        InputSystem.QueueStateEvent(this, state);
    }

    static PicoHandDevice()
    {
        InputSystem.RegisterLayout<PicoHandDevice>();
    }

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
    private static void InitializeInPlayer()
    {
    }
}