using System;
using System.Collections.Generic;
using System.Text;

namespace XRoboToolkit.Network
{
    /// <summary>
    /// Custom network data protocol structure containing command, length, and data
    /// </summary>
    [Serializable]
    public class NetworkDataProtocol
    {
        public string command;
        public int length;
        public byte[] data;

        public NetworkDataProtocol()
        {
            command = string.Empty;
            length = 0;
            data = new byte[0];
        }

        public NetworkDataProtocol(string command, byte[] data)
        {
            this.command = command ?? string.Empty;
            this.data = data ?? new byte[0];
            this.length = this.data.Length;
        }

        public NetworkDataProtocol(string command, int length, byte[] data)
        {
            this.command = command ?? string.Empty;
            this.length = length;
            this.data = data ?? new byte[0];
        }
    }
}
