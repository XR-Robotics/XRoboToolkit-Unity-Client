using System;
using System.IO;
using System.Text;

namespace Robot.Network
{
    /// <summary>
    /// Camera request data structure for TCP communication
    /// </summary>
    [Serializable]
    public struct CameraRequestData
    {
        public int width;
        public int height;
        public int fps;
        public int bitrate;
        public int enableMvHevc;
        public int renderMode;
        public string camera;
        public string ip;
        public int port;

        public CameraRequestData(int width, int height, int fps, int bitrate, int enableMvHevc, int renderMode, string camera, string ip, int port)
        {
            this.width = width;
            this.height = height;
            this.fps = fps;
            this.bitrate = bitrate;
            this.enableMvHevc = enableMvHevc;
            this.renderMode = renderMode;
            this.camera = camera ?? string.Empty;
            this.ip = ip ?? string.Empty;
            this.port = port;
        }

        public override string ToString()
        {
            return $"Camera[{width}x{height}@{fps}fps, {bitrate}bps, HEVC:{enableMvHevc}, Mode:{renderMode}, Type:{camera}, {ip}:{port}]";
        }
    }

    /// <summary>
    /// Efficient binary serializer for camera request data over TCP
    /// Optimized for minimal packet size
    /// </summary>
    public static class CameraRequestSerializer
    {
        // Protocol version for future compatibility
        private const byte PROTOCOL_VERSION = 1;

        // Magic bytes to identify our packets
        private static readonly byte[] MAGIC_BYTES = { 0xCA, 0xFE }; // "CAFE" in hex

        /// <summary>
        /// Serialize CameraConfigData to binary format for TCP transmission
        /// </summary>
        /// <param name="data">Camera request data</param>
        /// <returns>Serialized binary data</returns>
        public static byte[] Serialize(CameraRequestData data)
        {
            using (var stream = new MemoryStream())
            using (var writer = new BinaryWriter(stream))
            {
                // Write magic bytes and version
                writer.Write(MAGIC_BYTES);
                writer.Write(PROTOCOL_VERSION);

                // Write integer fields (6 * 4 bytes = 24 bytes)
                writer.Write(data.width);
                writer.Write(data.height);
                writer.Write(data.fps);
                writer.Write(data.bitrate);
                writer.Write(data.enableMvHevc);
                writer.Write(data.renderMode);
                writer.Write(data.port);

                // Write strings with length prefixes for efficient parsing
                WriteCompactString(writer, data.camera);
                WriteCompactString(writer, data.ip);

                return stream.ToArray();
            }
        }

        /// <summary>
        /// Deserialize binary data back to CameraConfigData
        /// </summary>
        /// <param name="data">Binary data received from TCP</param>
        /// <returns>Deserialized camera request</returns>
        /// <exception cref="InvalidDataException">Thrown when data format is invalid</exception>
        public static CameraRequestData Deserialize(byte[] data)
        {
            if (data == null || data.Length < 10) // Minimum size check
                throw new InvalidDataException("Data is null or too small");

            using (var stream = new MemoryStream(data))
            using (var reader = new BinaryReader(stream))
            {
                // Verify magic bytes
                var magic = reader.ReadBytes(2);
                if (magic.Length != 2 || magic[0] != MAGIC_BYTES[0] || magic[1] != MAGIC_BYTES[1])
                    throw new InvalidDataException("Invalid magic bytes");

                // Check protocol version
                var version = reader.ReadByte();
                if (version != PROTOCOL_VERSION)
                    throw new InvalidDataException($"Unsupported protocol version: {version}");

                // Read integer fields
                var width = reader.ReadInt32();
                var height = reader.ReadInt32();
                var fps = reader.ReadInt32();
                var bitrate = reader.ReadInt32();
                var enableMvHevc = reader.ReadInt32();
                var renderMode = reader.ReadInt32();
                var port = reader.ReadInt32();

                // Read strings
                var camera = ReadCompactString(reader);
                var ip = ReadCompactString(reader);

                return new CameraRequestData(width, height, fps, bitrate, enableMvHevc, renderMode, camera, ip, port);
            }
        }

        /// <summary>
        /// Get the estimated size of serialized data
        /// </summary>
        /// <param name="data">Camera request data</param>
        /// <returns>Estimated byte size</returns>
        public static int GetEstimatedSize(CameraRequestData data)
        {
            int fixedSize = 3 + (7 * 4); // Magic(2) + Version(1) + 7 integers(28)
            int stringSize = GetCompactStringSize(data.camera) + GetCompactStringSize(data.ip);
            return fixedSize + stringSize;
        }

        /// <summary>
        /// Create CameraConfigData from CameraParameters and additional fields
        /// </summary>
        /// <param name="cameraParams">Camera parameters from config</param>
        /// <param name="enableMvHevc">HEVC encoding flag</param>
        /// <param name="renderMode">Render mode</param>
        /// <param name="camera">Camera type</param>
        /// <param name="ip">Target IP address</param>
        /// <param name="port">Target port</param>
        /// <returns>Complete camera request data</returns>
        public static CameraRequestData FromCameraParameters(
            CameraParameters cameraParams,
            int enableMvHevc,
            int renderMode,
            string camera,
            string ip,
            int port)
        {
            if (cameraParams == null)
                cameraParams = new CameraParameters();

            return new CameraRequestData(
                cameraParams.width,
                cameraParams.height,
                cameraParams.fps,
                cameraParams.bitrate,
                enableMvHevc,
                renderMode,
                camera ?? string.Empty,
                ip ?? string.Empty,
                port
            );
        }

        /// <summary>
        /// Write string with compact length encoding (1 byte for strings <= 255 chars)
        /// </summary>
        private static void WriteCompactString(BinaryWriter writer, string str)
        {
            if (string.IsNullOrEmpty(str))
            {
                writer.Write((byte)0);
                return;
            }

            var bytes = Encoding.UTF8.GetBytes(str);
            if (bytes.Length > 255)
                throw new ArgumentException($"String too long: {bytes.Length} bytes (max 255)");

            writer.Write((byte)bytes.Length);
            writer.Write(bytes);
        }

        /// <summary>
        /// Read string with compact length encoding
        /// </summary>
        private static string ReadCompactString(BinaryReader reader)
        {
            var length = reader.ReadByte();
            if (length == 0)
                return string.Empty;

            var bytes = reader.ReadBytes(length);
            if (bytes.Length != length)
                throw new InvalidDataException($"String length mismatch: expected {length}, got {bytes.Length}");

            return Encoding.UTF8.GetString(bytes);
        }

        /// <summary>
        /// Calculate the size needed for a compact string
        /// </summary>
        private static int GetCompactStringSize(string str)
        {
            if (string.IsNullOrEmpty(str))
                return 1; // Just the length byte

            return 1 + Encoding.UTF8.GetByteCount(str); // Length byte + UTF8 bytes
        }

        /// <summary>
        /// Validate that the data can be serialized
        /// </summary>
        /// <param name="data">Data to validate</param>
        /// <returns>True if valid, false otherwise</returns>
        public static bool IsValid(CameraRequestData data)
        {
            try
            {
                // Check string lengths
                if (!string.IsNullOrEmpty(data.camera) && Encoding.UTF8.GetByteCount(data.camera) > 255)
                    return false;

                if (!string.IsNullOrEmpty(data.ip) && Encoding.UTF8.GetByteCount(data.ip) > 255)
                    return false;

                // Check reasonable value ranges
                if (data.width < 0 || data.width > 10000) return false;
                if (data.height < 0 || data.height > 10000) return false;
                if (data.fps < 0 || data.fps > 1000) return false;
                if (data.port < 0 || data.port > 65535) return false;

                return true;
            }
            catch
            {
                return false;
            }
        }
    }
}
