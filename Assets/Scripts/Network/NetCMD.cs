namespace Network
{
    public class NetCMD
    {
        public const byte PACKET_CCMD_CONNECT = 0x19; //Client sends connection command

        public const byte
            PACKET_CMD_FROM_CONTROLLER_COMMON_FUNCTION = 0x5F; //General commands sent from the control end

        public const byte RECEIVE_PACKET_HEAD = 0xCF;
        public const byte RECEIVE_PACKET_EDN = 0xA5;
        public const byte SEND_PACKET_HEAD = 0x3F;
        public const byte SEND_PACKET_EDN = 0xA5;
        public const byte PACKET_CCMD_TO_CONTROLLER_FUNCTION = 0x6D; //General message returned to the control end
        public const byte PACKET_CCMD_CLIENT_HEARTBEAT = 0x23;

        public const byte
            PACKET_CCMD_SEND_VERSION =
                0x6C; //Send Rom version number and Apk version number information from the head mounted end to the control end

        public const byte PACKET_CMD_TCPIP = 0x7E;
        public const byte PACKET_CMD_MEDIAIP = 0x7F; //
        public const byte PACKET_CMD_CUSTOM_TO_VR = 0x71;
        public const byte PACKET_CMD_CUSTOM_TO_PC = 0x72;
    }

    public class CustomDataType
    {
        public const byte TRACKER_EXTRA_DEVICE = 0xA1;
    }
}