using System.Collections.Generic;
using Network;
using UnityEngine;
using UnityEngine.Serialization;
using UnityEngine.UI;

public class UIUdpReceiver : MonoBehaviour
{
    private const int TCP_PORT = 63901;

    private const int UdpListenPort = 29888; // 监听的端口
    [FormerlySerializedAs("UIRobot")] public UIOperate uiOperate;
    public UdpReceiver UdpReceiver;
    public GameObject IpSelectDialog;
    public Button IpButtonItem;

    private bool _closed = false;

    // Start is called before the first frame update
    void Start()
    {
        IpButtonItem.gameObject.SetActive(false);
        UdpReceiver.ReceiveEvent += OnUdpReceive;
        UdpReceiver.ListenTo(UdpListenPort);
        IpSelectDialog.SetActive(false);
    }


    private HashSet<string> _receiveIps = new HashSet<string>();

    private void ReceiveUdpIP(NetPacket package)
    {
        IpSelectDialog.SetActive(true);
        string ip = package.ToString();
        if (_receiveIps.Contains(ip))
        {
            return;
        }

        Button but = Instantiate(IpButtonItem, IpButtonItem.transform.parent);
        but.gameObject.SetActive(true);
        but.GetComponentInChildren<Text>().text = ip;
        but.onClick.AddListener(() => { OnClickIP(ip); });
        _receiveIps.Add(ip);
    }

    private void OnClickIP(string ip)
    {
        UdpReceiver.Close();
        uiOperate.TcpConnect(ip);
        IpSelectDialog.SetActive(false);
    }

    private void OnUdpReceive(NetPacket package)
    {
        if (_closed)
        {
            return;
        }

        if (package.Cmd == NetCMD.PACKET_CMD_TCPIP)
        {
            ReceiveUdpIP(package);
        }
    }

    public void Close()
    {
        _closed = true;
        UdpReceiver.Close();
        IpSelectDialog.SetActive(false);
    }
}