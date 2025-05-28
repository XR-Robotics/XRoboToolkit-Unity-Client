using UnityEngine;

namespace Network
{
    /// <summary>
    /// This is a unpacking tool
    /// </summary>
    public class ByteBuffer
    {
        public byte[] data;
        private int readIndex = 0;
        private int writeIndex = 0;

        public ByteBuffer(int capacity)
        {
            data = new byte[capacity];
        }

        public int GetReadableCount()
        {
            return writeIndex - readIndex;
        }

        public int GetRemainCapacity()
        {
            return data.Length - writeIndex;
        }

        public void AddWriteIndex(int count)
        {
            writeIndex += count;
            if (writeIndex > data.Length)
            {
                Debug.LogError("byte buffer error write index overlapped capacity!!!");
            }
        }

        public void AddReadIndex(int count)
        {
            readIndex += count;
            if (readIndex > writeIndex)
            {
                Debug.LogError("byte buffer error read index large than write index!!!");
            }
        }

        public void RemoveReadedBytes()
        {
            if (readIndex == 0)
            {
                return;
            }

            for (int i = 0; i < writeIndex - readIndex; ++i)
            {
                data[i] = data[i + readIndex];
            }

            writeIndex -= readIndex;
            readIndex = 0;
        }

        public int ReadIndex
        {
            get { return readIndex; }
        }

        public int WriteIndex
        {
            get { return writeIndex; }
        }
    }
}