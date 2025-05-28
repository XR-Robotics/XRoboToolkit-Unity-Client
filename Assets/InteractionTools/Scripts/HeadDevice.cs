using System.Runtime.InteropServices;
using UnityEditor;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.Controls;
using UnityEngine.InputSystem.Layouts;
using UnityEngine.InputSystem.LowLevel;
using UnityEngine.InputSystem.Utilities;

// A "state struct" describes the memory format that a Device uses. Each Device can
// receive and store memory in its custom format. InputControls then connect to
// the individual pieces of memory and read out values from them.
//
// If it's important for the memory format to match 1:1 at the binary level
// to an external representation, it's generally advisable to use
// LayoutLind.Explicit.
[StructLayout(LayoutKind.Auto)]
public struct PicoHeadDeviceState : IInputStateTypeInfo
{
    // You must tag every state with a FourCC code for type
    // checking. The characters can be anything. Choose something that allows
    // you to easily recognize memory that belongs to your own Device.
    public FourCC format => new FourCC('H', 'E', 'A', 'D');

    // InputControlAttributes on fields tell the Input System to create Controls
    // for the public fields found in the struct.

    // Assume a 16bit field of buttons. Create one button that is tied to
    // bit #3 (zero-based). Note that buttons don't need to be stored as bits.
    // They can also be stored as floats or shorts, for example. The
    // InputControlAttribute.format property determines which format the
    // data is stored in. If omitted, the system generally infers it from the value
    // type of the field.
    [InputControl(name = "confirm", layout = "Button", offset = 0)]
    public bool confirm;

    [InputControl(name = "cancel", layout = "Button", offset = 1)]
    public bool cancel;
}


// InputControlLayoutAttribute attribute is only necessary if you want
// to override the default behavior that occurs when you register your Device
// as a layout.
// The most common use of InputControlLayoutAttribute is to direct the system
// to a custom "state struct" through the `stateType` property. See below for details.
#if UNITY_EDITOR
[InitializeOnLoad]
#endif
[InputControlLayout(displayName = "Pico Head Device", stateType = typeof(PicoHeadDeviceState))]
public class PicoHeadDevice : InputDevice, IInputUpdateCallbackReceiver
{
    // In the state struct, you added two Controls that you now want to
    // surface on the Device, for convenience. The Controls
    // get added to the Device either way. When you expose them as properties,
    // it is easier to get to the Controls in code.

    public ButtonControl confirm { get; private set; }

    public ButtonControl cancel { get; private set; }

    protected override void FinishSetup()
    {
        base.FinishSetup();

        // NOTE: The Input System creates the Controls automatically.
        //       This is why don't do `new` here but rather just look
        //       the Controls up.
        confirm = GetChildControl<ButtonControl>("confirm");
        cancel = GetChildControl<ButtonControl>("cancel");
    }

    public void OnUpdate()
    {
        // In practice, this would read out data from an external
        // API. This example uses some empty input.
        var state = new PicoHeadDeviceState();
        state.confirm = Input.GetKey(KeyCode.JoystickButton0);
        state.cancel = Input.GetButton("Cancel");

#if UNITY_EDITOR
        state.confirm = Input.GetKey(KeyCode.P);
        state.cancel = Input.GetKey(KeyCode.R);
#endif

        InputSystem.QueueStateEvent(this, state);
    }

    static PicoHeadDevice()
    {
        // RegisterLayout() adds a "Control layout" to the system.
        // These can be layouts for individual Controls (like sticks)
        // or layouts for entire Devices (which are themselves
        // Controls) like in our case.
        InputSystem.RegisterLayout<PicoHeadDevice>();
    }

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
    private static void InitializeInPlayer()
    {
    }
}