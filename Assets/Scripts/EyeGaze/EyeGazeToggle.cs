using UnityEngine;
using UnityEngine.UI;

namespace Robot
{
    [DisallowMultipleComponent]
    [RequireComponent(typeof(Toggle))]
    [DefaultExecutionOrder(150)]
    public sealed class EyeGazeToggle : MonoBehaviour
    {
        [SerializeField] private PicoEyeGazeSource source;
        private Toggle _toggle;

        private void OnEnable()
        {
            _toggle = GetComponent<Toggle>();
            if (source == null)
            {
                Debug.LogWarning("[EyeGaze] Assign the EyeTracking toggle's gaze source.", this);
                _toggle.interactable = false;
                return;
            }
            _toggle.SetIsOnWithoutNotify(source.TrackingRequested);
            _toggle.onValueChanged.AddListener(OnToggleChanged);
            source.TrackingRequestedChanged += SyncToggle;
        }

        private void OnToggleChanged(bool requested)
        {
            source.SetTrackingRequested(requested);
        }

        private void SyncToggle(bool requested)
        {
            _toggle.SetIsOnWithoutNotify(requested);
        }

        private void LateUpdate()
        {
            // Inspector simulation-mode changes also stay in sync without recursive callbacks.
            if (source != null && _toggle.isOn != source.TrackingRequested)
                SyncToggle(source.TrackingRequested);
        }

        private void OnDisable()
        {
            if (_toggle != null)
                _toggle.onValueChanged.RemoveListener(OnToggleChanged);
            if (source != null)
                source.TrackingRequestedChanged -= SyncToggle;
        }
    }
}
