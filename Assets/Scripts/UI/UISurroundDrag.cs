using System;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.XR.Interaction.Toolkit.UI;

public class UISurroundDrag : MonoBehaviour, IPointerDownHandler, IPointerUpHandler
{
    public Transform Target;
    public GameObject Panel;
    public GameObject OpenImage;
    public GameObject CloseImage;
    private const float ROTATION_SPEED = 10.0f; //

    private TrackedDeviceModel _pressedDeviceState;
    private IUIInteractor _pressedInteractor;
    private XRUIInputModule _pressedInputModel;

    private Quaternion _originQua;

    private void Awake()
    {
        if (Camera.main != null)
        {
            Target.transform.position = Camera.main.transform.position;
        }
    }

    public void OnPointerDown(PointerEventData eventData)
    {
        TrackedDeviceEventData deviceEventData = eventData as TrackedDeviceEventData;

        if (deviceEventData != null)
        {
            _pressedInputModel = eventData.currentInputModule as XRUIInputModule;
            if (_pressedInputModel == null)
            {
                return;
            }

            _pressedInteractor = deviceEventData.interactor;
            _pressedInputModel.GetTrackedDeviceModel(_pressedInteractor, out _pressedDeviceState);
            _originQua = Target.rotation;
            _draggingAngle = AdjustEulerAngles(_originQua.eulerAngles);
        }
    }

    private Vector3 _draggingAngle = new Vector3();

    private void Update()
    {
        if (_pressedInteractor != null)
        {
            _pressedInputModel.GetTrackedDeviceModel(_pressedInteractor, out var deviceModel);
            //  Quaternion diff = GetXYRotationDifference(_pressedDeviceState.orientation, deviceModel.orientation);
            //Quaternion targetQua = _originQua * diff;

            // Calculate the difference between two quaternions
            Quaternion difference = Quaternion.Inverse(_pressedDeviceState.orientation) * deviceModel.orientation;

            // Obtain the Euler angles of the differences and retain only the X and Y axes
            Vector3 angleDifference = difference.eulerAngles;
            Vector3 diff = new Vector3();
            diff.x = (angleDifference.x > 180) ? angleDifference.x - 360 : angleDifference.x;
            diff.y = (angleDifference.y > 180) ? angleDifference.y - 360 : angleDifference.y;

            Vector3 target = _originQua.eulerAngles + diff;
            target = AdjustEulerAngles(target);

            //  _draggingAngle = _originQua.eulerAngles + diff;
            _draggingAngle = Vector3.Lerp(_draggingAngle, target, ROTATION_SPEED * Time.deltaTime);
            _draggingAngle = AdjustEulerAngles(_draggingAngle);

            _draggingAngle.z = 0;
            Target.transform.rotation = Quaternion.Euler(_draggingAngle);
        }
    }

    public void OnPointerUp(PointerEventData eventData)
    {
        float angle = Quaternion.Angle(_originQua, Target.rotation);
//Judging that the angle has not changed
        if (angle < 1)
        {
            if (Panel != null)
            {
                Panel.SetActive(!Panel.gameObject.activeSelf);
                OpenImage.SetActive(Panel.gameObject.activeSelf);
                CloseImage.SetActive(!Panel.gameObject.activeSelf);
            }
        }

        _pressedInteractor = null;
        _pressedInputModel = null;
    }

    public static Vector3 AdjustEulerAngles(Vector3 angles)
    {
        angles.x = AdjustAngle(angles.x);
        angles.y = AdjustAngle(angles.y);
        angles.z = AdjustAngle(angles.z);
        return angles;
    }

    public static float AdjustAngle(float angle)
    {
        if (angle > 180)
        {
            angle -= 360;
        }
        else if (angle < -180)
        {
            angle += 360;
        }

        return angle;
    }
}