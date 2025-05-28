using System.Collections;
using System.Collections.Generic;
using com.picoxr.tobframwork;
using Unity.XR.CoreUtils;
using Unity.XR.PXR;
using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit;
using UnityEngine.XR.Interaction.Toolkit.Interactors;

public class InteractionModeManager : MonoBehaviour
{
    [SerializeField] private GameObject headController;
    [SerializeField] private GameObject leftController;
    [SerializeField] private GameObject rightController;
    [SerializeField] private GameObject leftHand;
    [SerializeField] private GameObject rightHand;

    /// <summary>
    /// Option 1:
    /// Is it allowed for both head ray interactors and gestures to exist simultaneously.
    /// If allowed, then hand eye interaction (or head hand interaction) can be performed;
    /// On the contrary, traditional gesture ray interaction is used.
    /// </summary>
    [SerializeField] private bool _isAllowHeadHandInteraction = true;

    /// <summary>
    /// Option 2:
    /// Is near-field interaction allowed.
    /// </summary>
    [SerializeField] private bool _isAllowNearFieldInteraction = true;

    public bool Dirty = false;
#if UNITY_EDITOR
    public ActiveInputDevice EditorActiveInputDevice = ActiveInputDevice.ControllerActive;
#endif

    private ActiveInputDevice _currentActiveInputDevice = ActiveInputDevice.ControllerActive;

    //Do you want to hide the handle ray
    private bool _hideLine = false;
    private bool _isFocusStateAcquired = true;

    private bool _controllerLeftConnected = false;
    private bool _controllerRightConnected = false;

    private static InteractionModeManager _instance;

    public static InteractionModeManager Instance
    {
        get { return _instance; }
    }

    public static event System.Action DeviceChange;

    private void Awake()
    {
        _instance = this;
        DontDestroyOnLoad(gameObject);
        XROrigin xrOrigin = FindObjectOfType<XROrigin>();
        DontDestroyOnLoad(xrOrigin.gameObject);
    }

    void Start()
    {
        // Connect to the focus perception interface and block the interactors within the application when calling out the system page.
        PXR_Plugin.System.FocusStateLost += FocusStateLost;
        PXR_Plugin.System.FocusStateAcquired += FocusStateAcquired;
        if (Application.platform == RuntimePlatform.Android)
        {
            _isFocusStateAcquired = PXR_Plugin.Pxr_GetFocusState();
        }

        UpdateInputDevice();
        Dirty = true;
    }

    private void FocusStateLost()
    {
        _isFocusStateAcquired = false;
        Debug.Log(this + " FocusStateLost");
        UpdateInputDevice();
    }

    private void FocusStateAcquired()
    {
        _isFocusStateAcquired = true;
        Debug.Log(this + " FocusStateAcquired");
        Dirty = true;
    }

    private void OnDestroy()
    {
        PXR_Plugin.System.FocusStateLost -= FocusStateLost;
        PXR_Plugin.System.FocusStateAcquired -= FocusStateAcquired;
    }

    private void Update()
    {
        ActiveInputDevice activeInputDevice = PXR_HandTracking.GetActiveInputDevice();
#if UNITY_EDITOR
        activeInputDevice = EditorActiveInputDevice;
#endif
        if (activeInputDevice != _currentActiveInputDevice)
        {
            _currentActiveInputDevice = activeInputDevice;
            Debug.Log(this + "InputDeviceChange:" + _currentActiveInputDevice);
            Dirty = true;
        }

        if (_currentActiveInputDevice == ActiveInputDevice.ControllerActive)
        {
            //Has the connection status of the left and right handles changed
            if (_controllerLeftConnected != ControllerIsConnect(PXR_Input.Controller.LeftController) ||
                _controllerRightConnected != ControllerIsConnect(PXR_Input.Controller.RightController))
            {
                _controllerLeftConnected = ControllerIsConnect(PXR_Input.Controller.LeftController);
                _controllerRightConnected = ControllerIsConnect(PXR_Input.Controller.RightController);

                Dirty = true;
            }
        }

        if (Dirty)
        {
            Dirty = false;
            UpdateInputDevice();
            //StartCoroutine(StartUpdateInputDevice());
        }
    }

    /// <summary>
    /// Activate the game object corresponding to the currently running input device.
    /// </summary>
    private void UpdateInputDevice()
    {
        Debug.Log(this + " UpdateInputDevice:" + _isFocusStateAcquired);

        //Is it a head to hand interaction
        bool headHandInteraction = _currentActiveInputDevice == ActiveInputDevice.HandTrackingActive &&
                                   _isAllowHeadHandInteraction;

        if (_isFocusStateAcquired)
        {
            bool inControllerMode = _currentActiveInputDevice == ActiveInputDevice.ControllerActive;

            bool leftConnected = ControllerIsConnect(PXR_Input.Controller.LeftController);
            bool rightConnected = ControllerIsConnect(PXR_Input.Controller.RightController);
            Debug.Log(this + "InputDevice:" + _currentActiveInputDevice + " UpdateControllerState left:" +
                      leftConnected + " right:" + rightConnected);

            SetControllerActive(leftController, inControllerMode && leftConnected);
            SetControllerActive(rightController, inControllerMode && rightConnected);

            SetControllerActive(leftHand, _currentActiveInputDevice == ActiveInputDevice.HandTrackingActive);
            SetControllerActive(rightHand, _currentActiveInputDevice == ActiveInputDevice.HandTrackingActive);

            SetControllerActive(headController,
                (headHandInteraction || _currentActiveInputDevice == ActiveInputDevice.HeadActive));
        }
        else
        {
            SetControllerActive(headController, false);
            SetControllerActive(leftController, false);
            SetControllerActive(rightController, false);
            SetControllerActive(leftHand, false);
            SetControllerActive(rightHand, false);
        }

        if (_currentActiveInputDevice == ActiveInputDevice.HandTrackingActive)
        {
            //头手交互要把手势射线隐藏
            leftHand.GetComponentInChildren<XRRayInteractor>(true).gameObject.SetActive(!headHandInteraction);
            rightHand.GetComponentInChildren<XRRayInteractor>(true).gameObject.SetActive(!headHandInteraction);
        }

        if (DeviceChange != null)
        {
            DeviceChange.Invoke();
        }
    }

    public static bool ControllerIsConnect(PXR_Input.Controller controller)
    {
#if UNITY_EDITOR
        return true;
#endif
        return PXR_Input.IsControllerConnected(controller);
    }

    private void SetControllerActive(GameObject controller, bool active)
    {
        if (controller.activeSelf != active)
        {
            controller.SetActive(active);
        }
    }

    public bool HideLine
    {
        get { return _hideLine; }
        set
        {
            string trackStr = new System.Diagnostics.StackTrace().ToString();
            Debug.Log("HideLine:" + value + " " + trackStr);
            if (_hideLine != value)
            {
                _hideLine = value;
                SetHideLine(_hideLine);
            }
        }
    }

    private void SetHideLine(bool hide)
    {
        SetControllerHideLine(leftController, hide);
        SetControllerHideLine(rightController, hide);
        SetControllerHideLine(headController, hide);
    }

    private void SetControllerHideLine(GameObject controller, bool hide)
    {
        HandController handController = controller.GetComponent<HandController>();

        if (handController != null)
        {
            if (handController.model != null)
            {
                handController.model.SetActive(!hide);
            }

            if (handController.hitPoint != null)
            {
                handController.hitPoint.Hide = hide;
            }
        }
    }
}