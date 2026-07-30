using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Threading;
using LitJson;

namespace Robot
{
    public sealed class EnterpriseCollectionFileWriter : IDisposable
    {
        private readonly bool _enabled;
        private readonly string _persistentDataPath;
        private readonly ConcurrentQueue<FileLine> _pendingLines = new ConcurrentQueue<FileLine>();
        private readonly Dictionary<string, StreamWriter> _writers = new Dictionary<string, StreamWriter>();

        private Thread _writerThread;
        private volatile bool _acceptingLines;

        public EnterpriseCollectionFileWriter(bool enabled, string persistentDataPath)
        {
            _enabled = enabled;
            _persistentDataPath = persistentDataPath;
            RecordDir = "file-write-disabled";
        }

        public string RecordDir { get; private set; }

        public int PendingCount => _pendingLines.Count;

        public bool IsWriterThreadAlive => _writerThread != null && _writerThread.IsAlive;

        public void Start(Meta meta)
        {
            if (!_enabled)
            {
                RecordDir = "file-write-disabled";
                return;
            }

            RecordDir = Path.Combine(_persistentDataPath, "EnterpriseCollection",
                DateTime.Now.ToString("yyyyMMdd_HHmmss"));
            Directory.CreateDirectory(RecordDir);
            WriteMetaFile(meta);

            _acceptingLines = true;
            _writerThread = new Thread(WriterLoop)
            {
                IsBackground = true,
                Name = "EnterpriseCollectionWriter"
            };
            _writerThread.Start();
        }

        public void Enqueue(string fileName, string line)
        {
            if (!_enabled || !_acceptingLines || string.IsNullOrEmpty(line))
            {
                return;
            }

            _pendingLines.Enqueue(new FileLine(fileName, line));
        }

        public StopStats Stop(int joinTimeoutMs)
        {
            StopStats stats = new StopStats
            {
                PendingBeforeStop = PendingCount
            };

            Stopwatch stageProfile = Stopwatch.StartNew();
            _acceptingLines = false;
            _writerThread?.Join(joinTimeoutMs);
            stats.WriterJoinMs = stageProfile.ElapsedMilliseconds;

            stageProfile.Restart();
            CloseWriters();
            stats.CloseWritersMs = stageProfile.ElapsedMilliseconds;
            stats.PendingAfterStop = PendingCount;
            stats.WriterThreadAlive = IsWriterThreadAlive;
            return stats;
        }

        public void Dispose()
        {
            Stop(2000);
        }

        private void WriterLoop()
        {
            while (_acceptingLines || !_pendingLines.IsEmpty)
            {
                if (_pendingLines.TryDequeue(out FileLine fileLine))
                {
                    StreamWriter writer = GetWriter(fileLine.FileName);
                    writer.WriteLine(fileLine.Line);
                }
                else
                {
                    Thread.Sleep(5);
                }
            }
        }

        private StreamWriter GetWriter(string fileName)
        {
            if (_writers.TryGetValue(fileName, out StreamWriter writer))
            {
                return writer;
            }

            string path = Path.Combine(RecordDir, fileName);
            writer = new StreamWriter(path, true);
            _writers[fileName] = writer;
            return writer;
        }

        private void CloseWriters()
        {
            foreach (StreamWriter writer in _writers.Values)
            {
                writer.Flush();
                writer.Dispose();
            }

            _writers.Clear();
        }

        private void WriteMetaFile(Meta meta)
        {
            JsonData json = new JsonData();
            json["startTime"] = DateTime.Now.ToString("O");
            json["persistentDataPath"] = _persistentDataPath;
            json["recordDir"] = RecordDir;
            json["enableFileWrite"] = meta.EnableFileWrite;
            json["collectHeadPose"] = meta.CollectHeadPose;
            json["collectControllerPose"] = meta.CollectControllerPose;
            json["enterpriseSampleHz"] = meta.EnterpriseSampleHz;
            json["unitySampleHz"] = meta.UnitySampleHz;
            json["maxRecordSeconds"] = meta.MaxRecordSeconds;
            json["useDynamicPredictedDisplayTimeForEnterpriseHead"] = meta.UseDynamicPredictedDisplayTimeForEnterpriseHead;
            json["enterpriseHeadPredictTimeMode"] = meta.EnterpriseHeadPredictTimeMode;
            json["enterpriseControllerPredictTimeMode"] = meta.EnterpriseControllerPredictTimeMode;
            json["enterpriseControllerPoseOrder"] = "index 0 = left, index 1 = right";
            File.WriteAllText(Path.Combine(RecordDir, "meta.json"), json.ToJson());
        }

        public struct Meta
        {
            public bool EnableFileWrite;
            public bool CollectHeadPose;
            public bool CollectControllerPose;
            public int EnterpriseSampleHz;
            public int UnitySampleHz;
            public int MaxRecordSeconds;
            public bool UseDynamicPredictedDisplayTimeForEnterpriseHead;
            public string EnterpriseHeadPredictTimeMode;
            public string EnterpriseControllerPredictTimeMode;
        }

        public struct StopStats
        {
            public int PendingBeforeStop;
            public int PendingAfterStop;
            public long WriterJoinMs;
            public long CloseWritersMs;
            public bool WriterThreadAlive;
        }

        private struct FileLine
        {
            public readonly string FileName;
            public readonly string Line;

            public FileLine(string fileName, string line)
            {
                FileName = fileName;
                Line = line;
            }
        }
    }
}
