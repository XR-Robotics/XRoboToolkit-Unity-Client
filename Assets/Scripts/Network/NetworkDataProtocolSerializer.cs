using System;
using System.Collections.Generic;
using System.Text;

namespace XRoboToolkit.Network
{
    /// <summary>
    /// Serializer and deserializer for NetworkDataProtocol
    /// </summary>
    public static class NetworkDataProtocolSerializer
    {
        // Protocol header format: [command_length(4 bytes)][command][data_length(4 bytes)][data]
        private const int INT_SIZE = sizeof(int);

        /// <summary>
        /// Serializes a NetworkDataProtocol object to byte array
        /// </summary>
        /// <param name="protocol">The protocol object to serialize</param>
        /// <returns>Serialized byte array</returns>
        public static byte[] Serialize(NetworkDataProtocol protocol)
        {
            if (protocol == null)
                throw new ArgumentNullException(nameof(protocol));

            // Convert command to UTF-8 bytes
            byte[] commandBytes = Encoding.UTF8.GetBytes(protocol.command ?? string.Empty);
            int commandLength = commandBytes.Length;

            // Ensure data is not null
            byte[] data = protocol.data ?? new byte[0];
            int dataLength = data.Length;

            // Calculate total size: command_length + command + data_length + data
            int totalSize = INT_SIZE + commandLength + INT_SIZE + dataLength;
            byte[] result = new byte[totalSize];

            int offset = 0;

            // Write command length
            BitConverter.GetBytes(commandLength).CopyTo(result, offset);
            offset += INT_SIZE;

            // Write command
            if (commandBytes.Length > 0)
            {
                commandBytes.CopyTo(result, offset);
            }
            offset += commandLength;

            // Write data length
            BitConverter.GetBytes(dataLength).CopyTo(result, offset);
            offset += INT_SIZE;

            // Write data
            if (data.Length > 0)
            {
                data.CopyTo(result, offset);
            }

            return result;
        }

        /// <summary>
        /// Deserializes a byte array to NetworkDataProtocol object
        /// </summary>
        /// <param name="buffer">The byte array to deserialize</param>
        /// <returns>Deserialized NetworkDataProtocol object</returns>
        public static NetworkDataProtocol Deserialize(byte[] buffer)
        {
            if (buffer == null)
                throw new ArgumentNullException(nameof(buffer));

            if (buffer.Length < INT_SIZE * 2)
                throw new ArgumentException($"Buffer too small to contain valid protocol data. Buffer length: {buffer.Length}, minimum required: {INT_SIZE * 2}");

            try
            {
                int offset = 0;

                // Read command length
                int commandLength = BitConverter.ToInt32(buffer, offset);
                offset += INT_SIZE;

                if (commandLength < 0)
                    throw new ArgumentException($"Invalid command length: {commandLength} (cannot be negative)");

                if (offset + commandLength > buffer.Length)
                    throw new ArgumentException($"Invalid command length: {commandLength}, buffer length: {buffer.Length}, offset: {offset}");

                // Read command
                string command = string.Empty;
                if (commandLength > 0)
                {
                    command = Encoding.UTF8.GetString(buffer, offset, commandLength);
                }
                offset += commandLength;

                if (offset + INT_SIZE > buffer.Length)
                    throw new ArgumentException($"Buffer too small to contain data length. Buffer length: {buffer.Length}, offset: {offset}");

                // Read data length
                int dataLength = BitConverter.ToInt32(buffer, offset);
                offset += INT_SIZE;

                if (dataLength < 0)
                    throw new ArgumentException($"Invalid data length: {dataLength} (cannot be negative)");

                if (offset + dataLength > buffer.Length)
                    throw new ArgumentException($"Invalid data length: {dataLength}, buffer length: {buffer.Length}, offset: {offset}");

                // Read data
                byte[] data = new byte[dataLength];
                if (dataLength > 0)
                {
                    Buffer.BlockCopy(buffer, offset, data, 0, dataLength);
                }

                return new NetworkDataProtocol(command, dataLength, data);
            }
            catch (Exception ex) when (!(ex is ArgumentException))
            {
                throw new ArgumentException($"Error deserializing buffer: {ex.Message}", ex);
            }
        }

        /// <summary>
        /// Tries to deserialize a byte array to NetworkDataProtocol object
        /// </summary>
        /// <param name="buffer">The byte array to deserialize</param>
        /// <param name="protocol">The output protocol object</param>
        /// <returns>True if deserialization was successful, false otherwise</returns>
        public static bool TryDeserialize(byte[] buffer, out NetworkDataProtocol protocol)
        {
            protocol = null;
            try
            {
                protocol = Deserialize(buffer);
                return true;
            }
            catch
            {
                return false;
            }
        }

        /// <summary>
        /// Gets the minimum buffer size required for a protocol with given command and data sizes
        /// </summary>
        /// <param name="commandLength">Length of the command string in bytes</param>
        /// <param name="dataLength">Length of the data array</param>
        /// <returns>Minimum required buffer size</returns>
        public static int GetMinimumBufferSize(int commandLength, int dataLength)
        {
            return INT_SIZE + commandLength + INT_SIZE + dataLength;
        }

        /// <summary>
        /// Validates if a buffer contains a complete protocol message
        /// </summary>
        /// <param name="buffer">The buffer to validate</param>
        /// <returns>True if buffer contains a complete message, false otherwise</returns>
        public static bool IsCompleteMessage(byte[] buffer)
        {
            if (buffer == null || buffer.Length < INT_SIZE * 2)
                return false;

            try
            {
                int commandLength = BitConverter.ToInt32(buffer, 0);
                if (commandLength < 0 || INT_SIZE + commandLength + INT_SIZE > buffer.Length)
                    return false;

                int dataLength = BitConverter.ToInt32(buffer, INT_SIZE + commandLength);
                if (dataLength < 0)
                    return false;

                int requiredSize = GetMinimumBufferSize(commandLength, dataLength);
                return buffer.Length >= requiredSize;
            }
            catch
            {
                return false;
            }
        }

        /// <summary>
        /// Debug helper method to analyze buffer contents
        /// </summary>
        /// <param name="buffer">The buffer to analyze</param>
        /// <returns>String containing debug information about the buffer</returns>
        public static string DebugBufferContents(byte[] buffer)
        {
            if (buffer == null)
                return "Buffer is null";

            StringBuilder sb = new StringBuilder();
            sb.AppendLine($"Buffer length: {buffer.Length}");

            if (buffer.Length == 0)
                return sb.ToString();

            // Show first 32 bytes in hex
            int displayBytes = Math.Min(buffer.Length, 32);
            sb.AppendLine($"First {displayBytes} bytes (hex): {BitConverter.ToString(buffer, 0, displayBytes)}");

            if (buffer.Length >= INT_SIZE)
            {
                int cmdLen = BitConverter.ToInt32(buffer, 0);
                sb.AppendLine($"Command length (first 4 bytes): {cmdLen}");

                if (cmdLen >= 0 && cmdLen < 1000 && buffer.Length >= INT_SIZE + cmdLen)
                {
                    try
                    {
                        string cmd = Encoding.UTF8.GetString(buffer, INT_SIZE, cmdLen);
                        sb.AppendLine($"Command string: '{cmd}'");

                        if (buffer.Length >= INT_SIZE + cmdLen + INT_SIZE)
                        {
                            int dataLen = BitConverter.ToInt32(buffer, INT_SIZE + cmdLen);
                            sb.AppendLine($"Data length: {dataLen}");
                            sb.AppendLine($"Expected total size: {INT_SIZE + cmdLen + INT_SIZE + dataLen}");
                        }
                    }
                    catch (Exception ex)
                    {
                        sb.AppendLine($"Error reading command: {ex.Message}");
                    }
                }
                else
                {
                    sb.AppendLine($"Invalid command length: {cmdLen}");
                }
            }

            return sb.ToString();
        }
    }
}
