using UnityEngine;
using UnityEngine.UI;

namespace Robot
{
    /// <summary>Binds the authored four-camera side panel and updates its live image content.</summary>
    public sealed class EnterpriseEyeFramePreview : MonoBehaviour
    {
        [Header("Scene bindings")]
        [SerializeField] private EnterpriseEyeFrameSource _source;
        [SerializeField] private Toggle _syncToggle;
        [SerializeField] private GameObject _panel;

        [Header("Camera views, ordered by IDs 15 to 18")]
        [SerializeField] private RawImage[] _images = new RawImage[4];
        [SerializeField] private Text[] _frameLabels = new Text[4];
        [SerializeField] private Text[] _emptyLabels = new Text[4];

        [Header("Capture controls")]
        [SerializeField] private Text _status;
        [SerializeField] private Text _stateLabel;
        [SerializeField] private Text _summaryLabel;
        [SerializeField] private Button _backButton;
        [SerializeField] private Button _startButton;
        [SerializeField] private Text _startLabel;
        [SerializeField] private Button _stopButton;
        [SerializeField] private Button _flipButton;
        [SerializeField] private Text _flipLabel;

        private readonly Texture2D[] _textures = new Texture2D[4];
        private readonly float[] _lastFrameTimes = new float[4];
        private bool _initialized;
        private bool _isOpen;
        private bool _startPending;
        private Material _material;
        private bool _flipVertically;
        private string _renderingError;

        public void Initialize()
        {
            if (_initialized)
            {
                return;
            }
            if (!HasSceneReferences())
            {
                Debug.LogWarning("[EnterpriseEyeFrames] Assign all authored preview references in the scene.");
                return;
            }
            Shader shader = Resources.Load<Shader>("EnterpriseEyeGray");
            if (shader == null || !shader.isSupported || !SystemInfo.SupportsTextureFormat(TextureFormat.R8))
            {
                _renderingError = "This device cannot render the R8 EyeFrame preview.";
            }
            else
            {
                _material = new Material(shader);
            }

            for (int i = 0; i < _images.Length; i++)
            {
                _images[i].material = _material;
            }
            _backButton.onClick.AddListener(Close);
            _startButton.onClick.AddListener(StartPreview);
            _stopButton.onClick.AddListener(StopPreview);
            _flipButton.onClick.AddListener(FlipImages);
            _source.FrameAvailable += ShowFrame;
            _source.CaptureStopped += OnCaptureStopped;
            _initialized = true;
            ClearImages("initialized");
            _panel.SetActive(false);
            _syncToggle.onValueChanged.AddListener(OnSyncToggleChanged);
            if (_syncToggle.isOn)
            {
                Open();
            }
        }

        private bool HasSceneReferences()
        {
            if (_source == null || _syncToggle == null || _panel == null ||
                transform.IsChildOf(_panel.transform) ||
                _status == null || _stateLabel == null || _summaryLabel == null ||
                _backButton == null || _startButton == null || _startLabel == null ||
                _stopButton == null || _flipButton == null || _flipLabel == null ||
                _images == null || _images.Length != 4 ||
                _frameLabels == null || _frameLabels.Length != 4 ||
                _emptyLabels == null || _emptyLabels.Length != 4)
            {
                return false;
            }
            for (int i = 0; i < _images.Length; i++)
            {
                if (_images[i] == null || _images[i].GetComponent<AspectRatioFitter>() == null ||
                    _frameLabels[i] == null || _emptyLabels[i] == null)
                {
                    return false;
                }
            }
            return true;
        }

        private void OnSyncToggleChanged(bool enabled)
        {
            if (enabled)
            {
                Open();
            }
            else
            {
                Close();
            }
        }

        private void Open()
        {
            if (!_initialized || _isOpen || !isActiveAndEnabled)
            {
                return;
            }
            _isOpen = true;
            _startPending = _renderingError == null;
            _panel.SetActive(true);
            TryStartPendingCapture();
            RefreshControls();
        }

        private void StartPreview()
        {
            _startPending = false;
            if (_renderingError != null || !_source.CanStart || !_source.isActiveAndEnabled)
            {
                return;
            }
            ClearImages("new session");
            _source.StartCapture();
        }

        private void TryStartPendingCapture()
        {
            if (!_startPending)
            {
                return;
            }
            if (_source.CanStart && _source.isActiveAndEnabled)
            {
                StartPreview();
            }
            else if (_source.State != EnterpriseEyeFrameState.Waiting &&
                     _source.State != EnterpriseEyeFrameState.Ready)
            {
                // Errors and lifecycle stops require an explicit retry.
                _startPending = false;
            }
        }

        private void StopPreview()
        {
            _startPending = false;
            _source.StopCapture("user stopped");
        }

        private void Close()
        {
            if (!_initialized)
            {
                return;
            }
            bool wasOpen = _isOpen;
            _isOpen = false;
            _startPending = false;
            if (_syncToggle != null)
            {
                _syncToggle.SetIsOnWithoutNotify(false);
            }
            if (wasOpen && _source != null)
            {
                _source.StopCapture("preview closed");
            }
            ClearImages("preview closed");
            if (_panel != null)
            {
                _panel.SetActive(false);
            }
        }

        private void Update()
        {
            if (!_initialized || !_isOpen)
            {
                return;
            }
            if (!_panel.activeInHierarchy)
            {
                Close();
                return;
            }
            TryStartPendingCapture();
            for (int i = 0; i < _images.Length; i++)
            {
                if (_images[i].enabled && Time.realtimeSinceStartup - _lastFrameTimes[i] > 2f)
                {
                    _images[i].enabled = false;
                    _emptyLabels[i].text = "No recent frame (>2s)";
                    _emptyLabels[i].gameObject.SetActive(true);
                }
            }
            RefreshControls();
        }

        private void RefreshControls()
        {
            _status.text = _renderingError ?? _source.Status;
            _stateLabel.text = _renderingError != null ? "Unavailable" :
                _startPending ? "Preparing" : _source.State.ToString();
            _stateLabel.color = _renderingError != null ? XRoboUIStyle.Warning :
                _source.State == EnterpriseEyeFrameState.Capturing ? XRoboUIStyle.Accent :
                _source.State == EnterpriseEyeFrameState.Error ? XRoboUIStyle.Error : XRoboUIStyle.Muted;
            int activeCameras = 0;
            foreach (RawImage image in _images) if (image.enabled) activeCameras++;
            _summaryLabel.text = _source.State == EnterpriseEyeFrameState.Capturing ?
                $"{activeCameras}/4 cameras receiving" : "Four cameras / live preview";
            _startButton.interactable = _renderingError == null && _source.CanStart &&
                                        _source.isActiveAndEnabled;
            _startLabel.color = _startButton.interactable ? XRoboUIStyle.OnAccent : XRoboUIStyle.Muted;
            _stopButton.interactable = _startPending || _source.State == EnterpriseEyeFrameState.Capturing ||
                                       _source.State == EnterpriseEyeFrameState.Error;
        }

        private void ShowFrame(EnterpriseEyeFrame frame)
        {
            if (!_isOpen || _panel == null || !_panel.activeInHierarchy || _material == null)
            {
                return;
            }
            int index = (int)frame.Camera - (int)EnterpriseEyeCamera.TopLeft;
            if (_textures[index] == null || _textures[index].width != frame.Width ||
                _textures[index].height != frame.Height)
            {
                if (_textures[index] != null)
                {
                    Destroy(_textures[index]);
                }
                _textures[index] = new Texture2D(frame.Width, frame.Height, TextureFormat.R8, false, true)
                {
                    name = $"EyeFrame{(int)frame.Camera}",
                    filterMode = FilterMode.Bilinear,
                    wrapMode = TextureWrapMode.Clamp
                };
                _images[index].texture = _textures[index];
                _images[index].GetComponent<AspectRatioFitter>().aspectRatio = (float)frame.Width / frame.Height;
            }
            _textures[index].LoadRawTextureData(frame.Gray8);
            _textures[index].Apply(false, false);
            _images[index].enabled = true;
            _emptyLabels[index].gameObject.SetActive(false);
            _lastFrameTimes[index] = Time.realtimeSinceStartup;
            _frameLabels[index].text =
                $"{frame.Width} x {frame.Height} / Gray8\n{frame.TimestampNanoseconds} ns";
        }

        private void OnCaptureStopped(string reason)
        {
            _startPending = false;
            ClearImages(reason);
        }

        private void ClearImages(string reason)
        {
            for (int i = 0; i < _images.Length; i++)
            {
                if (_images[i] != null)
                {
                    _images[i].enabled = false;
                    if (_frameLabels[i] != null) _frameLabels[i].text = "No frame received";
                    if (_emptyLabels[i] != null)
                    {
                        _emptyLabels[i].text = "Waiting for frames";
                        _emptyLabels[i].gameObject.SetActive(true);
                    }
                }
            }
        }

        private void FlipImages()
        {
            _flipVertically = !_flipVertically;
            _flipLabel.text = _flipVertically ? "Flip Y: on" : "Flip Y: off";
            foreach (RawImage image in _images)
            {
                image.uvRect = _flipVertically ? new Rect(0, 1, 1, -1) : new Rect(0, 0, 1, 1);
            }
        }

        private void OnDisable()
        {
            Close();
        }

        private void OnDestroy()
        {
            Close();
            if (_initialized && _syncToggle != null)
            {
                _syncToggle.onValueChanged.RemoveListener(OnSyncToggleChanged);
            }
            if (_initialized && _source != null)
            {
                _source.FrameAvailable -= ShowFrame;
                _source.CaptureStopped -= OnCaptureStopped;
            }
            if (_initialized)
            {
                if (_backButton != null) _backButton.onClick.RemoveListener(Close);
                if (_startButton != null) _startButton.onClick.RemoveListener(StartPreview);
                if (_stopButton != null) _stopButton.onClick.RemoveListener(StopPreview);
                if (_flipButton != null) _flipButton.onClick.RemoveListener(FlipImages);
            }
            foreach (Texture2D texture in _textures)
            {
                if (texture != null)
                {
                    Destroy(texture);
                }
            }
            if (_material != null) Destroy(_material);
        }
    }
}
