using ByteDance.PICO.XR;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.Serialization;
using UnityEngine.XR;
using UnityEngine.XR.Interaction.Toolkit.Interactors;

public class RayPoseAnima : MonoBehaviour
{
    [FormerlySerializedAs("aimFlags")]
    [SerializeField] private InputAction trackingState;

    [SerializeField] private InputAction pinchStrength;

    [SerializeField] private SkinnedMeshRenderer model;
    public bool RayValid { get; private set; }
    private bool _hasReportedState;
    private UnityEngine.InputSystem.InputDevice _lastDevice;
    private float _nextPoseReportTime;
    private XRRayInteractor _rayInteractor;
    private bool _hasReportedButtonState;
    private bool _lastPressed;
    private bool _lastUiPerformed;

    private void OnEnable()
    {
        _hasReportedState = false;
        _nextPoseReportTime = 0f;
        _hasReportedButtonState = false;
        _rayInteractor = GetComponentInParent<XRRayInteractor>(true);
        trackingState.Enable();
        pinchStrength.Enable();
    }

    private void OnDisable()
    {
        trackingState.Disable();
        pinchStrength.Disable();
        RayValid = false;
        if (model != null)
            model.gameObject.SetActive(false);
    }

    // Update is called once per frame
    void Update()
    {
        UpdateRayPose();
    }

    private void UpdateRayPose()
    {
        var flags = (InputTrackingState)trackingState.ReadValue<int>();
        const InputTrackingState required = InputTrackingState.Position | InputTrackingState.Rotation;
        var device = trackingState.activeControl?.device;
        bool valid = (flags & required) == required;
#if PICO_XR
        // SDK 6.1 tracks the grip separately from the pointer used by the UI ray.
        if (device is PicoHandInteraction hand)
            valid &= (hand.compatAimFlags & HandAimStatus.AimRayValid) != 0;
#endif
        if (!_hasReportedState || RayValid != valid || _lastDevice != device)
        {
            Debug.Log($"[HandRay] {name}: valid={valid}, tracking={flags}, " +
                      $"device={device?.layout ?? "none"}, boundControls={trackingState.controls.Count}", this);
            _hasReportedState = true;
            _lastDevice = device;
        }
        RayValid = valid;
        ReportButtonState(device);
        if (RayValid)
            ReportRayPoseAlignment(device);
        if (model == null) return;

        if (RayValid)
        {
            model.gameObject.SetActive(true);
            float touchStrengthRay = pinchStrength.ReadValue<float>();
            model.SetBlendShapeWeight(0, touchStrengthRay * 100);
        }
        else
        {
            model.gameObject.SetActive(false);
        }
    }

    private void ReportRayPoseAlignment(UnityEngine.InputSystem.InputDevice device)
    {
#if PICO_XR
        if (!(device is PicoHandInteraction hand) || Time.unscaledTime < _nextPoseReportTime)
            return;

        _nextPoseReportTime = Time.unscaledTime + 2f;
        var pointerPosition = hand.pointer.position.ReadValue();
        var pointerRotation = hand.pointer.rotation.ReadValue();
        float positionError = Vector3.Distance(transform.localPosition, pointerPosition);
        float rotationError = Quaternion.Angle(transform.localRotation, pointerRotation);
        string side = hand == PicoHandInteraction.left ? "Left" : "Right";
        Debug.Log($"[HandRayPose] {side}: pointer={pointerPosition:F3}, ray={transform.localPosition:F3}, " +
                  $"positionError={positionError:F4}m, rotationError={rotationError:F2}deg, " +
                  $"pinch={hand.pointerActivateValue.ReadValue():F2}, " +
                  $"button={hand.pointerActivated.ReadValue():F3}, pressed={hand.pointerActivated.isPressed}", this);
#endif
    }

    private void ReportButtonState(UnityEngine.InputSystem.InputDevice device)
    {
#if PICO_XR
        if (!(device is PicoHandInteraction hand))
            return;

        bool pressed = hand.pointerActivated.isPressed;
        bool uiPerformed = _rayInteractor != null && _rayInteractor.uiPressInput.ReadIsPerformed();
        if (_hasReportedButtonState && _lastPressed == pressed && _lastUiPerformed == uiPerformed)
            return;

        _hasReportedButtonState = true;
        _lastPressed = pressed;
        _lastUiPerformed = uiPerformed;
        string target = _rayInteractor != null &&
                        _rayInteractor.TryGetCurrentUIRaycastResult(out var hit) && hit.gameObject != null
            ? hit.gameObject.name : "none";
        string side = hand == PicoHandInteraction.left ? "Left" : "Right";
        Debug.Log($"[HandUIPress] {side}: pinch={hand.pointerActivateValue.ReadValue():F2}, " +
                  $"button={hand.pointerActivated.ReadValue():F3}, pressed={pressed}, " +
                  $"uiPerformed={uiPerformed}, rayValid={RayValid}, target={target}", this);
#endif
    }
}
