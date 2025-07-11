using System;
using UnityEngine;
using UnityEngine.UI;

namespace Robot.Conf
{
    public class VideoSourceManager : MonoBehaviour
    {
        public RectTransform rawImageRect;

        public Material matLE;
        public Material matRE;

        public VideoSourceConfigManager videoSourceConfigManager;

        public void UpdateVideoSource(VideoSource videoSource)
        {
            if (videoSourceConfigManager == null)
            {
                Debug.LogError("VideoSourceConfigManager is not set.");
                return;
            }

            if (rawImageRect == null)
            {
                Debug.LogError("RawImage RectTransform is not set.");
                return;
            }

            if (matLE == null || matRE == null)
            {
                Debug.LogError("Materials are not set.");
                return;
            }

            // Update video source
            videoSourceConfigManager.SetVideoSource(videoSource);

            // update rect transform size
            rawImageRect.sizeDelta = new Vector2(videoSourceConfigManager.Width, videoSourceConfigManager.Height);

            matLE.SetFloat("_visibleRatio", videoSourceConfigManager.VisibleRatio);
            matRE.SetFloat("_visibleRatio", videoSourceConfigManager.VisibleRatio);
            matLE.SetFloat("_contentRatio", videoSourceConfigManager.ContentRatio);
            matRE.SetFloat("_contentRatio", videoSourceConfigManager.ContentRatio);
            matLE.SetFloat("_heightCompressionFactor", videoSourceConfigManager.HeightCompressionFactor);
            matRE.SetFloat("_heightCompressionFactor", videoSourceConfigManager.HeightCompressionFactor);
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