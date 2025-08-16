using System;
using UnityEngine;
using UnityEngine.UI;

namespace Robot.Conf
{
    public class VideoSourceManager : MonoBehaviour
    {
        public RectTransform rawImageRect;

        public SetLERE setLere;

        public VideoSourceConfigManager videoSourceConfigManager;

        public void UpdateVideoSource(string videoSourceName)
        {
            var videoSource = videoSourceConfigManager.GetVideoSource(videoSourceName);
            if (videoSource == null) return;

            UpdateVideoSource(videoSource);
        }

        public void UpdateVideoSource(VideoSource videoSource)
        {
            if (videoSourceConfigManager == null)
            {
                Debug.LogError("VideoSourceConfigManager is not set.");
                LogWindow.Error("VideoSourceConfigManager is not set.");
                return;
            }

            if (rawImageRect == null)
            {
                Debug.LogError("RawImage RectTransform is not set.");
                LogWindow.Error("RawImage RectTransform is not set.");
                return;
            }

            // Update video source
            videoSourceConfigManager.SetVideoSource(videoSource);

            // Get camera parameters
            var cameraParams = videoSourceConfigManager.CameraParameters;
            Debug.Log($"Updating video source to: {videoSource.name}");
            LogWindow.Info($"Updating video source to: {videoSource.name}");
            Debug.Log($"Camera Parameters: {cameraParams}");
            LogWindow.Info($"Camera Parameters: {cameraParams}");
            Debug.Log($"type: {videoSource.camera}");
            LogWindow.Info($"type: {videoSource.camera}");

            // update rect transform size
            rawImageRect.sizeDelta =
                new Vector2(videoSourceConfigManager.RectWidth, videoSourceConfigManager.RectHeight);

            // log rect transform size for debugging
            Debug.Log($"RawImage RectTransform Size: {rawImageRect.sizeDelta}");
            LogWindow.Info($"RectTransform Size: {rawImageRect.sizeDelta}");

            // Update SetLERE component
            setLere.UpdateParameters(videoSourceConfigManager.VisibleRatio,
                videoSourceConfigManager.ContentRatio, videoSourceConfigManager.HeightCompressionFactor);

            // log shader properties for debugging
            Debug.Log($"Shader Properties - Visible Ratio: {videoSourceConfigManager.VisibleRatio}, " +
                      $"Content Ratio: {videoSourceConfigManager.ContentRatio}, " +
                      $"Height Compression Factor: {videoSourceConfigManager.HeightCompressionFactor}");
            LogWindow.Info($"Shader Properties - Visible Ratio: {videoSourceConfigManager.VisibleRatio}, " +
                           $"Content Ratio: {videoSourceConfigManager.ContentRatio}, " +
                           $"Height Compression Factor: {videoSourceConfigManager.HeightCompressionFactor}");

            // Log camera settings for debugging
            Debug.Log(
                $"Camera Settings - Width: {cameraParams.width}, Height: {cameraParams.height}, FPS: {cameraParams.fps}, Bitrate: {cameraParams.BitrateInMbps:F1}Mbps");
            LogWindow.Info(
                $"Camera Settings - Width: {cameraParams.width}, Height: {cameraParams.height}, FPS: {cameraParams.fps}, Bitrate: {cameraParams.BitrateInMbps:F1}Mbps");
        }

        private void OnGUI()
        {
            GUILayout.BeginVertical();
            if (GUILayout.Button("PICO4U"))
            {
                UpdateVideoSource(videoSourceConfigManager.PICO4U);
            }

            if (GUILayout.Button("ZEDMINI"))
            {
                UpdateVideoSource(videoSourceConfigManager.ZEDMINI);
            }

            GUILayout.EndVertical();
        }
    }
}