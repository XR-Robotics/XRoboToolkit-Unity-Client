using System.Collections;
using UnityEngine;
using System.Net.Sockets;
using System.Threading;
using System.Threading.Tasks;
using LitJson;
using Robot;
using UnityEngine.UI;


/// <summary>
/// Display window of PC camera
/// Responsible for receiving, decoding, and displaying data
/// </summary>
public class RemoteCameraWindow : MonoBehaviour
{
    public RawImage RemoteCameraImage;
    private TcpListener _tcpListener;
    private TcpClient _client;
    private NetworkStream _stream;
    private Texture2D _texture;
    public Texture2D Texture => _texture;
    private byte[] _imageBuffer;
    private CancellationTokenSource _receiveImageTs = null;
    private Task _imageReceiveTask;

    private int _resolutionWidth = 2160;
    private int _resolutionHeight = 2160 / 2*4/3;
    private int _videoFps = 60;
    private int _bitrate = 40 * 1024 * 1024;

    private void Awake()
    {
        transform.position = Camera.main.transform.position;
        transform.rotation = Camera.main.transform.rotation;
    }

    public void StartListen(int width, int height, int fps, int bitrate, int port)
    {
        _resolutionWidth = width;
        _resolutionHeight = height;
        _videoFps = fps;
        _bitrate = bitrate;

        StartCoroutine(OnStartListen(port));
    }

    private void OnDisable()
    {
        MediaDecoder.release();
        Debug.Log("RemoteCameraWindow OnDisable");
        TcpHandler.SendFunctionValue("StopReceivePcCamera", "");
    }

    public void OnCloseBtn()
    {
        gameObject.SetActive(false);
    }

    public IEnumerator OnStartListen(int port)
    {
        Debug.Log("StartListen port:" + port);

        _texture = new Texture2D(_resolutionWidth, _resolutionHeight, TextureFormat.RGB24, false, false);
        RemoteCameraImage.texture = _texture;
        yield return null;

        MediaDecoder.initialize((int)_texture.GetNativeTexturePtr(), _resolutionWidth, _resolutionHeight);
        MediaDecoder.startTCPServer(port, true);
        yield return null;

        JsonData cameraParam = new JsonData();
        cameraParam["ip"] = Utils.GetLocalIPv4();
        cameraParam["port"] = port;
        cameraParam["width"] = _resolutionWidth;
        cameraParam["height"] = _resolutionHeight;
        cameraParam["fps"] = _videoFps;
        cameraParam["bitrate"] = _bitrate;
        TcpHandler.SendFunctionValue("StartReceivePcCamera", cameraParam.ToJson());
    }

    private void LateUpdate()
    {
        //Keep the window facing the camera at all times
        if (Camera.main != null)
        {
            transform.position = Camera.main.transform.position;
            transform.rotation = Camera.main.transform.rotation;
        }
    }

    private void Update()
    {
        if (_texture != null)
        {
            if (Application.platform == RuntimePlatform.Android)
            {
                if (MediaDecoder.isUpdateFrame())
                {
                    MediaDecoder.updateTexture();
                    GL.InvalidateState();
                }
            }
        }
    }
}