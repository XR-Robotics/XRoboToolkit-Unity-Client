namespace Network
{
    public class NetUtils
    {
        public static string Get16String(byte value)
        {
            return "0x" + value.ToString("X2");
        }
    }
}