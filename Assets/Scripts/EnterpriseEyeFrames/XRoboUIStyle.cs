using UnityEngine;

namespace Robot
{
    /// <summary>Semantic colors for live sensor status; scene assets own the UI appearance.</summary>
    public static class XRoboUIStyle
    {
        public static readonly Color Muted = Hex(0xA8B6C6);
        public static readonly Color Accent = Hex(0x69DDC6);
        public static readonly Color OnAccent = Hex(0x12342D);
        public static readonly Color Warning = Hex(0xF6C56F);
        public static readonly Color Error = Hex(0xF39B9C);

        private static Color Hex(int value)
        {
            return new Color(((value >> 16) & 255) / 255f, ((value >> 8) & 255) / 255f, (value & 255) / 255f);
        }
    }
}
