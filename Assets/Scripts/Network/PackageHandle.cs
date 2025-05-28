using System;
using System.Text;
using UnityEngine;

namespace Network
{
    /**
     * packet including： head----cmd----params Length-----params----time stamp------end；
     * total length = 1+1+4+（参数长度的值*2）+9
     * head：     1 byte;
     * cmd:    1 byte;   
     * params len: 4 byte;
     * params:    （len*2）byte ;
     * time stamp：  8 byte;
     * end：    1 byte.
     */
    public class PackageHandle
    {
        public const int DEFAULT_PACKAGE_SIZE = 15;
        public static bool BigEndian = false;

        public static bool Unpack(byte[] data, out NetPacket package)
        {
            package = new NetPacket();

            if (data == null || data.Length < DEFAULT_PACKAGE_SIZE)
            {
                Debug.LogWarning("parsePacket: is not valid packet data");
                return false;
            }

            int arraySize = data.Length;

            // head
            byte head = data[0];
            if (head != NetCMD.RECEIVE_PACKET_HEAD)
            {
                return false;
            }

            byte cmd = data[1];

            // params length
            byte[] paramLengthArray = new byte[4];
            Array.Copy(data, 2, paramLengthArray, 0, 4);
            if (BigEndian)
            {
                Array.Reverse(paramLengthArray);
            }

            int paramLength = BitConverter.ToInt32(paramLengthArray, 0);

            byte[] body;
            // params
            if (arraySize > (5 + paramLength) && paramLength != 0)
            {
                body = new byte[paramLength];
                Array.Copy(data, 6, body, 0, paramLength);
            }
            else
            {
                body = null;
            }

            // timestamp
            if (arraySize > 13 + paramLength)
            {
                byte[] timeStampArray = new byte[8];
                if (BigEndian)
                {
                    Array.Reverse(timeStampArray);
                }

                Array.Copy(data, 6 + paramLength, timeStampArray, 0, 8);
                long timeStamp = BitConverter.ToInt64(timeStampArray, 0);
                byte end = data[paramLength + DEFAULT_PACKAGE_SIZE - 1];

                package.SetData(cmd, body, timeStamp);
                return true;
            }
            else
            {
                return false;
            }
        }

        public static bool Unpack(ByteBuffer buffer, out NetPacket package)
        {
            package = new NetPacket();
            if (buffer.GetReadableCount() < 15)
            {
                return false;
            }

            byte head = buffer.data[buffer.ReadIndex];
            if (head != NetCMD.RECEIVE_PACKET_HEAD)
            {
                Debug.LogError("Receive data head error!" + head);
                buffer.AddReadIndex(buffer.GetReadableCount());
                return false;
            }

            byte cmd = buffer.data[buffer.ReadIndex + 1];
            int length = BitConverter.ToInt32(buffer.data, buffer.ReadIndex + 2);
            // length = IPAddress.NetworkToHostOrder(length);

            Debug.Log("Receive:" + NetUtils.Get16String(cmd) + " length:" + length);
            if (buffer.GetReadableCount() < 15 + length)
            {
                if (length > buffer.data.Length)
                {
                    Debug.LogError("Receive data length error!" + length);
                    buffer.AddReadIndex(buffer.GetReadableCount());
                }

                return false;
            }

            byte end = buffer.data[buffer.ReadIndex + 2 + 4 + length + 8];

            if (end != NetCMD.RECEIVE_PACKET_EDN)
            {
                Debug.LogError("Receive data end error!" + end);
                buffer.AddReadIndex(buffer.GetReadableCount());
                return false;
            }

            byte[] data = new byte[length];
            Buffer.BlockCopy(buffer.data, buffer.ReadIndex + 2 + 4, data, 0, length);

            long timeStamp = BitConverter.ToInt32(buffer.data, buffer.ReadIndex + 2 + 4 + length);


            buffer.AddReadIndex(2 + 4 + length + 8 + 1);

            package.SetData(cmd, data, timeStamp);

            return true;
        }

        public static byte[] Pack(byte cmd, byte[] message)
        {
            byte[] data = new byte[15 + message.Length];
            data[0] = NetCMD.SEND_PACKET_HEAD;
            data[1] = cmd;
            byte[] len = long2Bytes(message.Length); //BitConverter.GetBytes();
            Buffer.BlockCopy(len, 0, data, 2, 4);

            Buffer.BlockCopy(message, 0, data, 6, message.Length);

            long timeStamp = DateTimeOffset.Now.ToUnixTimeMilliseconds();
            // onvert long to byte array (8 bytes)
            byte[] longBytes = BitConverter.GetBytes(timeStamp);
            Buffer.BlockCopy(longBytes, 0, data, 6 + message.Length, 8);

            data[data.Length - 1] = NetCMD.SEND_PACKET_EDN;

            return data;
        }

        public static byte[] long2Bytes(long num)
        {
            byte[] byteNum = new byte[8];
            for (int ix = 0; ix < 8; ++ix)
            {
                int offset = 64 - (ix + 1) * 8;
                byteNum[7 - ix] = (byte)((num >> offset) & 0xff);
            }

            return byteNum;
        }
        public static byte[] CustomPacket(byte dataType, string sn, byte[] data)
        {
            // 1. SN 转换为 17 字节的 ASCII 编码
            byte[] snBytes = Encoding.ASCII.GetBytes(sn);
            byte snLength = (byte)snBytes.Length; // SN 长度，固定17字节

            // 2. 包体长度转为 4 字节大端序
            byte[] lengthBytes = BitConverter.GetBytes(data.Length);

            // 3. 构建数据包
            byte[] packet = new byte[1 + 1 + 4 + snLength + data.Length];
            packet[0] = dataType; // 数据类型 (1字节)
            packet[1] = snLength; // SN 长度 (1字节)
            Array.Copy(lengthBytes, 0, packet, 2, 4); // 包体长度 (4字节)
            Array.Copy(snBytes, 0, packet, 6, snLength); // SN 
            Array.Copy(data, 0, packet, 6 + snLength, data.Length); // 具体数据 (可变长度)

            return packet;
        }
    }
}