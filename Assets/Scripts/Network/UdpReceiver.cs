using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using Network;
using UnityEngine;

public class UdpReceiver : MonoBehaviour
{
    public static event ReceiveMassage ReceiveEvent;

    public delegate void ReceiveMassage(NetPacket packet);

    private UdpClient _udpClient;
    private Thread _receiveThread;
    private Queue<NetPacket> _receivePackages = new Queue<NetPacket>();
    private IPEndPoint _endPoint;
    private bool _isListening; // Used to control thread loops

    public void ListenTo(int port)
    {
        Close(); // Ensure that previous resources are released

        Debug.Log(this + " UdpReceiver ListenTo " + port);
        _udpClient = new UdpClient(port);
        _endPoint = new IPEndPoint(IPAddress.Any, port);

        _isListening = true;
        _receiveThread = new Thread(ReceiveData);
        _receiveThread.IsBackground = true;
        _receiveThread.Start();
    }

    private void Update()
    {
        while (GetReceivePacket(out var packet))
        {
            ReceiveHandle(packet);
        }
    }

    private void ReceiveHandle(NetPacket packet)
    {
        try
        {
            Debug.Log("receive cmd:" + NetUtils.Get16String(packet.Cmd) + " msg:" + packet.ToString());
            if (ReceiveEvent != null)
            {
                ReceiveEvent.Invoke(packet);
            }
        }
        catch (Exception e)
        {
            Debug.LogError(e.ToString());
        }
    }

    private bool GetReceivePacket(out NetPacket packet)
    {
        packet = new NetPacket();
        lock (_receivePackages)
        {
            if (_receivePackages.Count == 0)
            {
                return false;
            }
            else
            {
                packet = _receivePackages.Dequeue();
                return true;
            }
        }
    }

    private void ReceiveData()
    {
        while (_isListening)
        {
            try
            {
                byte[] data = _udpClient.Receive(ref _endPoint);
                if (PackageHandle.Unpack(data, out var packet))
                {
                    lock (_receivePackages)
                    {
                        _receivePackages.Enqueue(packet);
                    }
                }
            }
            catch (SocketException ex)
            {
                if (_isListening)
                {
                    Debug.LogError("SocketException: " + ex.Message);
                }

                break;
            }
            catch (ObjectDisposedException)
            {
                if (_isListening)
                {
                    Debug.LogError("UdpClient was disposed unexpectedly.");
                }

                break;
            }
        }
    }


    public void Close()
    {
        _isListening = false;
        _udpClient?.Close();
        if (_receiveThread != null && _receiveThread.IsAlive)
        {
            _receiveThread.Join();
        }
    }
}