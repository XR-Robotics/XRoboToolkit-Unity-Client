using System;

[Serializable]
public class CameraParameters
{
    public int width;
    public int height;
    public int fps;
    public int bitrate;

    public CameraParameters()
    {
        width = 1920;
        height = 1080;
        fps = 30;
        bitrate = 5000000; // 5 Mbps default
    }

    public CameraParameters(int width, int height, int fps, int bitrate)
    {
        this.width = width;
        this.height = height;
        this.fps = fps;
        this.bitrate = bitrate;
    }

    /// <summary>
    /// Create CameraParameters from a VideoSource
    /// </summary>
    /// <param name="videoSource">VideoSource containing camera properties</param>
    /// <returns>CameraParameters object</returns>
    public static CameraParameters FromVideoSource(VideoSource videoSource)
    {
        if (videoSource == null)
            return new CameraParameters();

        return new CameraParameters(
            videoSource.GetPropertyValue<int>("CamWidth"),
            videoSource.GetPropertyValue<int>("CamHeight"),
            videoSource.GetPropertyValue<int>("CamFPS"),
            videoSource.GetPropertyValue<int>("CamBitrate")
        );
    }

    /// <summary>
    /// Get aspect ratio of the camera
    /// </summary>
    public float AspectRatio => height > 0 ? (float)width / height : 16f / 9f;

    /// <summary>
    /// Get bitrate in Mbps
    /// </summary>
    public float BitrateInMbps => bitrate / 1000000f;

    /// <summary>
    /// Get total pixels
    /// </summary>
    public int TotalPixels => width * height;

    /// <summary>
    /// Check if the parameters are valid
    /// </summary>
    public bool IsValid => width > 0 && height > 0 && fps > 0 && bitrate > 0;

    public override string ToString()
    {
        return $"Camera: {width}x{height}@{fps}fps, {BitrateInMbps:F1}Mbps";
    }
}
