using System.Text;

namespace Network
{
    public struct NetPacket
    {
        private bool _valid;

        //  private byte head;
        private byte _cmd;
        private byte[] _data;

        private long _timeStamp;
        //   private byte end;

        public void SetData(byte cmd, byte[] body, long timeStamp)
        {
            _cmd = cmd;
            _data = body;
            _timeStamp = timeStamp;
            _valid = true;
        }

        public bool Valid
        {
            get { return _valid; }
        }

        public byte Cmd
        {
            get { return _cmd; }
        }

        public byte[] Data
        {
            get { return _data; }
        }

        public long TimeStamp
        {
            get { return _timeStamp; }
        }

        public new string ToString()
        {
            return Encoding.UTF8.GetString(_data);
        }
    }
}