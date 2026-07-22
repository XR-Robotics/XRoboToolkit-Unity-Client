using System.Collections;
using UnityEngine;
using System.Net.Sockets;
using System.Threading;
using System.Threading.Tasks;
using LitJson;
using Network;
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
    private bool _listening;

    public bool IsListening => _listening;

    private int _resolutionWidth = 2160;
    private int _resolutionHeight = 2160 / 2 * 4 / 3;
    private int _videoFps = 60;
    private int _bitrate = 40 * 1024 * 1024;

    public CustomButton listenBtn;

    private void Awake()
    {
        transform.position = Camera.main.transform.position;
        transform.rotation = Camera.main.transform.rotation;
    }

    public void StartListen(int width, int height, int fps, int bitrate, int port)
    {
        if (_listening)
        {
            return;
        }

        _listening = true;
        _resolutionWidth = width;
        _resolutionHeight = height;
        _videoFps = fps;
        _bitrate = bitrate;

        StartCoroutine(OnStartListen(port));
    }

    private void OnDisable()
    {
        if (_listening)
        {
            MediaDecoder.release();
            _listening = false;
        }
        Debug.Log("RemoteCameraWindow OnDisable");
        TcpHandler.SendFunctionValue("StopReceivePcCamera", "");
    }

    public void OnCloseBtn()
    {
        // Notify the owner instead of changing only the visual toggle. The
        // Listen-off callback sends CLOSE_CAMERA, revokes audio, and disconnects
        // the managed control socket before this window is hidden.
        listenBtn.SetOnAndNotify(false);
        gameObject.SetActive(false);
    }

    public IEnumerator OnStartListen(int port)
    {
        Debug.Log("StartListen port:" + port);

        _texture = new Texture2D(_resolutionWidth, _resolutionHeight, TextureFormat.RGB24, false, false);
        RemoteCameraImage.texture = _texture;
        yield return null;

        MediaDecoder.initialize((int)_texture.GetNativeTexturePtr(), _resolutionWidth, _resolutionHeight);
        MediaDecoder.startServer(port, false);
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
