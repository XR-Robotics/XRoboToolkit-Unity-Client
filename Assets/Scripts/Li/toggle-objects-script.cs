using UnityEngine;
using UnityEngine.XR;

public class ToggleCameraClippingPlane : MonoBehaviour
{
    [Header("Cameras to Adjust")]
    [SerializeField] private Camera firstCamera;
    [SerializeField] private Camera secondCamera;
    
    [Header("Clipping Plane Values")]
    [SerializeField] private float nearClipValueA = 0.1f;
    [SerializeField] private float nearClipValueB = 0.35f;

    [Header("RemoteCameraWindow")] public GameObject remoteCameraWindow;
    
    private bool wasButtonPressed = false;
    private bool useValueA = true; // Start with the first value
    
    void Update()
    {
        // Return if the remote camera window is not active
        if (!remoteCameraWindow.activeSelf) return;
        
        // Get the right controller directly using XRNode
        var rightControllerDevice = InputDevices.GetDeviceAtXRNode(XRNode.RightHand);
        
        // Check if B button (secondaryButton) is pressed
        bool buttonValue = false;
        if (rightControllerDevice.TryGetFeatureValue(CommonUsages.secondaryButton, out buttonValue) && buttonValue)
        {
            // Only toggle on button press (not while holding)
            if (!wasButtonPressed)
            {
                // Toggle between the two near clip values
                float newClipValue = useValueA ? nearClipValueB : nearClipValueA;
                useValueA = !useValueA;
                
                // Apply to first camera
                if (firstCamera != null)
                {
                    firstCamera.nearClipPlane = newClipValue;
                }
                
                // Apply to second camera
                if (secondCamera != null)
                {
                    secondCamera.nearClipPlane = newClipValue;
                }
                
                Debug.Log($"Camera near clip plane changed to: {newClipValue}");
            }
            
            wasButtonPressed = true;
        }
        else
        {
            wasButtonPressed = false;
        }
    }
}
