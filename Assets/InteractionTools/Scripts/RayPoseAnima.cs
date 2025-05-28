using System.Collections;
using System.Collections.Generic;
using Unity.XR.PXR;
using UnityEngine;
using UnityEngine.InputSystem;

public class RayPoseAnima : MonoBehaviour
{
    [SerializeField] private InputAction aimFlags;

    [SerializeField] private InputAction pinchStrength;

    [SerializeField] private SkinnedMeshRenderer model;
    public bool RayValid { get; private set; }

    private void OnEnable()
    {
        aimFlags.Enable();
        pinchStrength.Enable();
    }

    private void OnDisable()
    {
        aimFlags.Disable();
        pinchStrength.Disable();
    }

    // Update is called once per frame
    void Update()
    {
        UpdateRayPose();
    }

    private void UpdateRayPose()
    {
        if (model == null) return;

        ulong aimStatus = (ulong)aimFlags.ReadValue<int>();
        RayValid = ((HandAimStatus)aimStatus & HandAimStatus.AimRayValid) != 0;

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
}