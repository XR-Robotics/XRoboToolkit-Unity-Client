using System;
using UnityEngine;
using UnityEngine.UI;

namespace ByteDance.PICO.CameraPack
{
    public class PXR_StereoCameraImageMatcher : MonoBehaviour
    {
        private const long k_TimestampMatchTolerance = 1;

        public PXR_CamTextureManager LeftManager;
        public PXR_CamTextureManager RightManager;
        public Material TargetMaterial;
        public Text StatsText;

        public long LeftFrameCount;
        public long RightFrameCount;
        public long MatchedFrameCount;
        public long DroppedLeftFrameCount;
        public long DroppedRightFrameCount;

        [SerializeField] private string _texturePropertyName = "_MainTex";

        private readonly Color32 _clearColor = new Color32(0, 0, 0, 255);
        private Color32[] _leftPixels;
        private Color32[] _rightPixels;
        private Color32[] _combinedPixels;
        private Texture2D _combinedTexture;
        private Vector2Int _combinedResolution;
        private PXRCameraFrameSnapshot _pendingLeftSnapshot;
        private PXRCameraFrameSnapshot _pendingRightSnapshot;
        private long _lastLeftTimestamp;
        private long _lastRightTimestamp;
        private bool _hasPendingLeftFrame;
        private bool _hasPendingRightFrame;
        private int _mainTexId;

        private void Awake()
        {
            _mainTexId = Shader.PropertyToID(string.IsNullOrEmpty(_texturePropertyName) ? "_MainTex" : _texturePropertyName);
            UpdateStatsText();
        }

        private void Update()
        {
            TryReadLeftFrame();
            TryReadRightFrame();
            MatchPendingFrames();
            UpdateStatsText();
        }

        private void OnDestroy()
        {
            if (_combinedTexture != null)
            {
                Destroy(_combinedTexture);
                _combinedTexture = null;
            }
        }

        private bool TryReadLeftFrame()
        {
            if (!TryPrepareFrameBuffer(LeftManager, ref _leftPixels, _lastLeftTimestamp, out _))
            {
                return false;
            }

            if (!LeftManager.TryCopyLatestFramePixels(_leftPixels, out var leftSnapshot))
            {
                return false;
            }

            if (leftSnapshot.Timestamp == _lastLeftTimestamp)
            {
                return false;
            }

            _lastLeftTimestamp = leftSnapshot.Timestamp;
            LeftFrameCount++;
            if (_hasPendingLeftFrame)
            {
                DroppedLeftFrameCount++;
            }

            _pendingLeftSnapshot = leftSnapshot;
            _hasPendingLeftFrame = true;
            return true;
        }

        private bool TryReadRightFrame()
        {
            if (!TryPrepareFrameBuffer(RightManager, ref _rightPixels, _lastRightTimestamp, out _))
            {
                return false;
            }

            if (!RightManager.TryCopyLatestFramePixels(_rightPixels, out var rightSnapshot))
            {
                return false;
            }

            if (rightSnapshot.Timestamp == _lastRightTimestamp)
            {
                return false;
            }

            _lastRightTimestamp = rightSnapshot.Timestamp;
            RightFrameCount++;
            if (_hasPendingRightFrame)
            {
                DroppedRightFrameCount++;
            }

            _pendingRightSnapshot = rightSnapshot;
            _hasPendingRightFrame = true;
            return true;
        }

        private static bool TryPrepareFrameBuffer(
            PXR_CamTextureManager manager,
            ref Color32[] pixels,
            long lastTimestamp,
            out PXRCameraFrameSnapshot snapshot)
        {
            snapshot = default;
            if (manager == null || !manager.TryGetLatestFrameSnapshot(out snapshot))
            {
                return false;
            }

            if (snapshot.Timestamp == lastTimestamp)
            {
                return false;
            }

            int pixelCount = snapshot.Resolution.x * snapshot.Resolution.y;
            if (pixelCount <= 0)
            {
                return false;
            }

            if (pixels == null || pixels.Length != pixelCount)
            {
                pixels = new Color32[pixelCount];
            }

            return true;
        }

        private void MatchPendingFrames()
        {
            while (_hasPendingLeftFrame && _hasPendingRightFrame)
            {
                PXRCameraFrameSnapshot leftSnapshot = _pendingLeftSnapshot;
                PXRCameraFrameSnapshot rightSnapshot = _pendingRightSnapshot;

                if (AreTimestampsMatched(leftSnapshot.Timestamp, rightSnapshot.Timestamp))
                {
                    PublishMatchedFrame(leftSnapshot, rightSnapshot);
                    _hasPendingLeftFrame = false;
                    _hasPendingRightFrame = false;
                    MatchedFrameCount++;
                }
                else if (leftSnapshot.Timestamp + k_TimestampMatchTolerance < rightSnapshot.Timestamp)
                {
                    _hasPendingLeftFrame = false;
                    DroppedLeftFrameCount++;
                }
                else if (rightSnapshot.Timestamp + k_TimestampMatchTolerance < leftSnapshot.Timestamp)
                {
                    _hasPendingRightFrame = false;
                    DroppedRightFrameCount++;
                }
            }
        }

        private static bool AreTimestampsMatched(long leftTimestamp, long rightTimestamp)
        {
            return Math.Abs(leftTimestamp - rightTimestamp) <= k_TimestampMatchTolerance;
        }

        private void PublishMatchedFrame(PXRCameraFrameSnapshot leftSnapshot, PXRCameraFrameSnapshot rightSnapshot)
        {
            EnsureCombinedTexture(leftSnapshot.Resolution, rightSnapshot.Resolution);
            FillCombinedPixels(_clearColor);
            CopyFrameIntoCombined(_leftPixels, leftSnapshot.Resolution, 0);
            CopyFrameIntoCombined(_rightPixels, rightSnapshot.Resolution, leftSnapshot.Resolution.x);
            _combinedTexture.SetPixels32(_combinedPixels);
            _combinedTexture.Apply(false);

            if (TargetMaterial != null)
            {
                TargetMaterial.SetTexture(_mainTexId, _combinedTexture);
            }
        }

        private void EnsureCombinedTexture(Vector2Int leftResolution, Vector2Int rightResolution)
        {
            Vector2Int requiredResolution = new Vector2Int(
                leftResolution.x + rightResolution.x,
                Mathf.Max(leftResolution.y, rightResolution.y));

            int pixelCount = requiredResolution.x * requiredResolution.y;
            if (_combinedTexture != null && _combinedResolution == requiredResolution && _combinedPixels != null && _combinedPixels.Length == pixelCount)
            {
                return;
            }

            if (_combinedTexture != null)
            {
                Destroy(_combinedTexture);
            }

            _combinedResolution = requiredResolution;
            _combinedPixels = new Color32[pixelCount];
            _combinedTexture = new Texture2D(requiredResolution.x, requiredResolution.y, TextureFormat.RGBA32, false);
            _combinedTexture.wrapMode = TextureWrapMode.Clamp;
            _combinedTexture.filterMode = FilterMode.Bilinear;
        }

        private void FillCombinedPixels(Color32 color)
        {
            for (int i = 0; i < _combinedPixels.Length; i++)
            {
                _combinedPixels[i] = color;
            }
        }

        private void CopyFrameIntoCombined(Color32[] sourcePixels, Vector2Int sourceResolution, int destinationX)
        {
            if (sourcePixels == null || sourceResolution.x <= 0 || sourceResolution.y <= 0)
            {
                return;
            }

            for (int y = 0; y < sourceResolution.y; y++)
            {
                int sourceIndex = y * sourceResolution.x;
                int destinationIndex = y * _combinedResolution.x + destinationX;
                System.Array.Copy(sourcePixels, sourceIndex, _combinedPixels, destinationIndex, sourceResolution.x);
            }
        }

        private void UpdateStatsText()
        {
            if (StatsText == null)
            {
                return;
            }

            StatsText.text =
                $"Left Frames: {LeftFrameCount}\n" +
                $"Right Frames: {RightFrameCount}\n" +
                $"Matched Frames: {MatchedFrameCount}\n" +
                $"Dropped Left: {DroppedLeftFrameCount}\n" +
                $"Dropped Right: {DroppedRightFrameCount}";
        }
    }
}
