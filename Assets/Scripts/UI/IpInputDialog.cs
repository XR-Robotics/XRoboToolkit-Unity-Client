using Robot;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class IpInputDialog : MonoBehaviour
{
    public TMP_InputField TmpInput;
    public TextMeshProUGUI Remind;
    public Button ConnectBtn;
    public Button CloseBtn;
    public TcpHandler TcpHandler;

    public UIOperate uiRobot;

    private bool _connecting = false;

    private void Awake()
    {
        ConnectBtn.onClick.AddListener(OnConnectBtn);
        CloseBtn.onClick.AddListener(OnCloseBtn);
    }

    private void OnEnable()
    {
        Remind.text = "";
        TmpInput.SetTextWithoutNotify(PcServiceAddressStore.Load());
        ConnectBtn.gameObject.SetActive(true);
        _connecting = false;
    }

    private void OnDestroy()
    {
        ConnectBtn.onClick.RemoveListener(OnConnectBtn);
        CloseBtn.onClick.RemoveListener(OnCloseBtn);
    }

    private void OnCloseBtn()
    {
        gameObject.SetActive(false);
    }

    public void OnConnectBtn()
    {
        if (!PcServiceAddressStore.TrySave(TmpInput.text, out string ip))
        {
            SetRemind(LogType.Error, "The IP format is incorrect!");
            return;
        }

        TmpInput.SetTextWithoutNotify(ip);
        SetRemind(LogType.Log, "Connecting...");
        _connecting = true;
        TcpHandler.Connect(ip);
        ConnectBtn.gameObject.SetActive(false);
    }

    private void Update()
    {
        if (TcpHandler != null && _connecting)
        {
            if (TcpHandler.State == SocketState.WORKING)
            {
                uiRobot.ConnectSuccess();
                gameObject.SetActive(false);
            }
            else if (TcpHandler.State == SocketState.CONNECT_ERROR || TcpHandler.State == SocketState.CLOSE)
            {
                if (!string.IsNullOrEmpty(TcpHandler.ConnectErrorInfo))
                {
                    SetRemind(LogType.Error, TcpHandler.ConnectErrorInfo);
                }
                else
                {
                    SetRemind(LogType.Error, "Connect fail!");
                }

                ConnectBtn.gameObject.SetActive(true);
                _connecting = false;
            }
        }
    }

    public void SetRemind(LogType type, string content)
    {
        if (type == LogType.Error)
        {
            Remind.color = Color.red;
        }
        else
        {
            Remind.color = Color.white;
        }

        Remind.text = content;
    }
}
