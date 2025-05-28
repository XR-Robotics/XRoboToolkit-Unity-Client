using System;
using Network;
using Robot;
using UnityEngine;
using UnityEngine.UI;

public class TcpState : MonoBehaviour
{
    public Text ConnectState;
    private SocketState _lastTcpState = SocketState.NONE;

    public TcpHandler tcpHandle;

    // Update is called once per frame
    void Update()
    {
        try
        {
            if (tcpHandle != null)
            {
                if (_lastTcpState != tcpHandle.State)
                {
                    _lastTcpState = tcpHandle.State;
                    if (ConnectState != null)
                    {
                        ConnectState.text = _lastTcpState.ToString();
                        if (_lastTcpState > SocketState.WORKING)
                        {
                            ConnectState.color = Color.red;
                        }
                        else if (_lastTcpState == SocketState.WORKING)
                        {
                            ConnectState.color = Color.green;
                        }
                        else
                        {
                            ConnectState.color = Color.white;
                        }
                    }
                }
            }
        }
        catch (Exception e)
        {
            Debug.LogError(this + " " + e.ToString());
            throw;
        }
    }
}