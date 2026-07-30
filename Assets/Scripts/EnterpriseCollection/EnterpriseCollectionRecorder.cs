using System;
using System.Diagnostics;
using System.Threading;
using LitJson;
using Unity.XR.PICO.TOBSupport;
using Unity.XR.PXR;
using UnityEngine;
using UnityEngine.XR;
using CommonUsages = UnityEngine.XR.CommonUsages;
using Debug = UnityEngine.Debug;
using InputDevice = UnityEngine.XR.InputDevice;

namespace Robot
{
    public class EnterpriseCollectionRecorder : MonoBehaviour
    {
        private const string Tag = "EnterpriseCollectionRecorder";
        private const string EnterpriseHeadFile = "enterprise_head.jsonl";
        private const string EnterpriseControllerFile = "enterprise_controller_pose.jsonl";
        private const string UnityHeadFile = "unity_head.jsonl";
        private const string UnityControllerFile = "unity_controller_pose.jsonl";
        private const double MaxValidEnterpriseControllerPositionMeters = 10.0;
        public const string InvalidControllerPose = "0,0,0,0,0,0,1";
        private static bool s_enterpriseServiceBound;
        private static readonly object s_latestEnterpriseHeadLock = new object();
        private static bool s_hasLatestEnterpriseHead;
        private static string s_latestEnterpriseHeadPose;
        private static int s_latestEnterpriseHeadStatus;
        private static long s_latestEnterpriseHeadSampleSeq;
        private static readonly object s_latestEnterpriseControllerLock = new object();
        private static bool s_hasLatestEnterpriseController;
        private static EnterpriseControllerTcpPose s_latestEnterpriseLeftController;
        private static EnterpriseControllerTcpPose s_latestEnterpriseRightController;
        private static long s_latestEnterpriseControllerSampleSeq;

        [SerializeField] private bool autoStart = true;
        [SerializeField] private bool enableFileWrite = true;
        [SerializeField] private bool collectHeadPose = true;
        [SerializeField] private bool collectControllerPose = true;
        [SerializeField] private int enterpriseSampleHz = 100;
        [SerializeField] private int unitySampleHz = 90;
        [SerializeField] private int maxRecordSeconds = 100;
        [SerializeField] private bool useDynamicPredictedDisplayTimeForEnterpriseHead = false;
        [SerializeField] private bool outputSampleRateToLogWindow = false;
        [SerializeField] private float sampleRateLogIntervalSeconds = 1f;

        private readonly Stopwatch _stopwatch = new Stopwatch();
        private readonly ControllerLogState _unityLeftControllerLog = new ControllerLogState("unity", "left");
        private readonly ControllerLogState _unityRightControllerLog = new ControllerLogState("unity", "right");
        private readonly ControllerLogState _enterpriseLeftControllerLog = new ControllerLogState("enterprise", "left");
        private readonly ControllerLogState _enterpriseRightControllerLog = new ControllerLogState("enterprise", "right");

        private Thread _enterpriseThread;
        private EnterpriseCollectionFileWriter _fileWriter;
        private volatile bool _recording;
        private long _enterpriseHeadSeq;
        private long _enterpriseControllerSeq;
        private long _unityHeadSeq;
        private long _unityControllerSeq;
        private double _nextUnitySampleTimeSeconds;
        private long _lastEnterpriseHeadSampleTicks;
        private long _enterpriseHeadSamplesInWindow;
        private long _enterpriseControllerSamplesInWindow;
        private long _lastEnterpriseRateLogTicks;
        private bool _recordTimeLimitReached;

        public static void EnsureCreated()
        {
            if (FindObjectOfType<EnterpriseCollectionRecorder>() != null)
            {
                return;
            }

            GameObject recorder = new GameObject(nameof(EnterpriseCollectionRecorder));
            DontDestroyOnLoad(recorder);
            recorder.AddComponent<EnterpriseCollectionRecorder>();
        }

        private void Start()
        {
            if (autoStart)
            {
                TryAutoStart();
            }
        }

        private void OnDestroy()
        {
            StopRecording();
        }

        private void OnApplicationQuit()
        {
            StopRecording();
        }

        public static void NotifyEnterpriseServiceBound(bool bind)
        {
            s_enterpriseServiceBound = bind;
            if (!bind)
            {
                ClearLatestEnterpriseHead();
                ClearLatestEnterpriseController();
            }

            EnterpriseCollectionRecorder recorder = FindObjectOfType<EnterpriseCollectionRecorder>();
            if (recorder == null)
            {
                return;
            }

            if (bind)
            {
                recorder.TryAutoStart();
            }
        }

        private void Update()
        {
            if (!_recording)
            {
                return;
            }

            if (!_recordTimeLimitReached && maxRecordSeconds > 0 && _stopwatch.Elapsed.TotalSeconds >= maxRecordSeconds)
            {
                _recordTimeLimitReached = true;
                StopFileWriter("record time limit reached");
            }

            double nowSeconds = Time.realtimeSinceStartup;
            if (nowSeconds < _nextUnitySampleTimeSeconds)
            {
                return;
            }

            double intervalSeconds = GetIntervalSeconds(unitySampleHz);
            _nextUnitySampleTimeSeconds = nowSeconds + intervalSeconds;

            if (collectHeadPose)
            {
                Enqueue(UnityHeadFile, BuildUnityHeadLine());
            }
        }

        public void StartRecording()
        {
            if (_recording)
            {
                return;
            }

            if (!CanStartRecording())
            {
                Debug.Log($"{Tag} waiting for enterprise service bind before start recording.");
                return;
            }

            _fileWriter = new EnterpriseCollectionFileWriter(enableFileWrite, Application.persistentDataPath);
            _fileWriter.Start(new EnterpriseCollectionFileWriter.Meta
            {
                EnableFileWrite = enableFileWrite,
                CollectHeadPose = collectHeadPose,
                CollectControllerPose = collectControllerPose,
                EnterpriseSampleHz = enterpriseSampleHz,
                UnitySampleHz = unitySampleHz,
                MaxRecordSeconds = maxRecordSeconds,
                UseDynamicPredictedDisplayTimeForEnterpriseHead = useDynamicPredictedDisplayTimeForEnterpriseHead,
                EnterpriseHeadPredictTimeMode = useDynamicPredictedDisplayTimeForEnterpriseHead
                    ? "dynamic"
                    : "sample_interval",
                EnterpriseControllerPredictTimeMode = "latest"
            });

            _recording = true;
            _stopwatch.Restart();
            _nextUnitySampleTimeSeconds = 0;
            _enterpriseHeadSamplesInWindow = 0;
            _enterpriseControllerSamplesInWindow = 0;
            _lastEnterpriseHeadSampleTicks = 0;
            _lastEnterpriseRateLogTicks = Stopwatch.GetTimestamp();
            _recordTimeLimitReached = false;

            _enterpriseThread = new Thread(EnterpriseLoop)
            {
                IsBackground = true,
                Name = "EnterpriseCollection"
            };
            _enterpriseThread.Start();

            Debug.Log($"{Tag} started: {_fileWriter.RecordDir}, enableFileWrite={enableFileWrite}, " +
                $"collectHeadPose={collectHeadPose}, collectControllerPose={collectControllerPose}");
        }

        private void TryAutoStart()
        {
            if (!autoStart || _recording)
            {
                return;
            }

            StartRecording();
        }

        private static bool CanStartRecording()
        {
#if PICO_PLATFORM
            return s_enterpriseServiceBound;
#else
            return true;
#endif
        }

        public void StopRecording()
        {
            if (!_recording)
            {
                return;
            }

            Stopwatch stopProfile = Stopwatch.StartNew();
            int pendingBeforeStop = _fileWriter != null ? _fileWriter.PendingCount : 0;
            _recording = false;

            Stopwatch stageProfile = Stopwatch.StartNew();
            _enterpriseThread?.Join(1000);
            long enterpriseJoinMs = stageProfile.ElapsedMilliseconds;

            EnterpriseCollectionFileWriter.StopStats writerStats = _fileWriter != null
                ? _fileWriter.Stop(2000)
                : new EnterpriseCollectionFileWriter.StopStats();
            string recordDir = _fileWriter != null ? _fileWriter.RecordDir : "none";
            _fileWriter = null;

            _stopwatch.Stop();
            ClearLatestEnterpriseHead();
            ClearLatestEnterpriseController();
            stopProfile.Stop();
            Debug.Log($"{Tag} stopped: {recordDir}");
            Debug.Log($"{Tag} stop profile: totalMs={stopProfile.ElapsedMilliseconds}, " +
                $"enterpriseJoinMs={enterpriseJoinMs}, writerJoinMs={writerStats.WriterJoinMs}, " +
                $"closeWritersMs={writerStats.CloseWritersMs}, " +
                $"pendingBeforeStop={pendingBeforeStop}, pendingAfterStop={writerStats.PendingAfterStop}, " +
                $"enterpriseThreadAlive={(_enterpriseThread != null && _enterpriseThread.IsAlive)}, " +
                $"writerThreadAlive={writerStats.WriterThreadAlive}");
        }

        private void StopFileWriter(string reason)
        {
            if (_fileWriter == null)
            {
                return;
            }

            int pendingBeforeStop = _fileWriter.PendingCount;
            string recordDir = _fileWriter.RecordDir;
            EnterpriseCollectionFileWriter.StopStats writerStats = _fileWriter.Stop(2000);
            _fileWriter = null;
            Debug.Log($"{Tag} file writer stopped: {recordDir}, reason={reason}");
            Debug.Log($"{Tag} file writer stop profile: writerJoinMs={writerStats.WriterJoinMs}, " +
                $"closeWritersMs={writerStats.CloseWritersMs}, " +
                $"pendingBeforeStop={pendingBeforeStop}, pendingAfterStop={writerStats.PendingAfterStop}, " +
                $"writerThreadAlive={writerStats.WriterThreadAlive}");
        }

        private void EnterpriseLoop()
        {
#if PICO_PLATFORM
            AndroidJNI.AttachCurrentThread();
#endif

            long nextSampleTicks = Stopwatch.GetTimestamp();
            while (_recording)
            {
                int sampleHz = EnterpriseSampleHz;
                if (sampleHz <= 0)
                {
                    Thread.Sleep(100);
                    nextSampleTicks = Stopwatch.GetTimestamp();
                    continue;
                }

                if (collectHeadPose)
                {
                    Enqueue(EnterpriseHeadFile, BuildEnterpriseHeadLine());
                }

                if (collectControllerPose)
                {
                    Enqueue(EnterpriseControllerFile, BuildEnterpriseControllerLine());
                }

                LogEnterpriseSampleRateIfNeeded();

                long intervalTicks = Math.Max(1, (long)Math.Round(Stopwatch.Frequency / (double)sampleHz));
                nextSampleTicks += intervalTicks;
                long remainingTicks = nextSampleTicks - Stopwatch.GetTimestamp();
                if (remainingTicks > 0)
                {
                    int sleepMs = (int)(remainingTicks * 1000 / Stopwatch.Frequency);
                    if (sleepMs > 0)
                    {
                        Thread.Sleep(sleepMs);
                    }
                    else
                    {
                        Thread.Yield();
                    }
                }
                else
                {
                    nextSampleTicks = Stopwatch.GetTimestamp();
                    Thread.Yield();
                }
            }
        }

        public int EnterpriseSampleHz
        {
            get => Volatile.Read(ref enterpriseSampleHz);
        }

        public void SetEnterpriseSampleHz(int sampleHz)
        {
            int clampedSampleHz = Mathf.Clamp(sampleHz, 0, 1000);
            Volatile.Write(ref enterpriseSampleHz, clampedSampleHz);
            Debug.Log($"{Tag} enterprise sample hz set to {clampedSampleHz}");
        }

        public int AdjustEnterpriseSampleHz(int delta)
        {
            int sampleHz = EnterpriseSampleHz + delta;
            SetEnterpriseSampleHz(sampleHz);
            return EnterpriseSampleHz;
        }

        public static bool TryGetLatestEnterpriseHeadForTcp(out string pose, out int status)
        {
            return TryGetLatestEnterpriseHeadForTcp(out pose, out status, out _);
        }

        public static bool TryGetLatestEnterpriseHeadForTcp(out string pose, out int status, out long sampleSeq)
        {
            lock (s_latestEnterpriseHeadLock)
            {
                pose = s_latestEnterpriseHeadPose;
                status = s_latestEnterpriseHeadStatus;
                sampleSeq = s_latestEnterpriseHeadSampleSeq;
                return s_hasLatestEnterpriseHead && !string.IsNullOrEmpty(pose);
            }
        }

        public static bool TryGetLatestEnterpriseControllerForTcp(
            out EnterpriseControllerTcpPose left,
            out EnterpriseControllerTcpPose right,
            out long sampleSeq)
        {
            lock (s_latestEnterpriseControllerLock)
            {
                left = s_latestEnterpriseLeftController;
                right = s_latestEnterpriseRightController;
                sampleSeq = s_latestEnterpriseControllerSampleSeq;
                return s_hasLatestEnterpriseController && (left.HasPose || right.HasPose);
            }
        }

        private string BuildEnterpriseHeadLine()
        {
            try
            {
                double predictTimeMs = GetEnterpriseHeadPredictTimeMs();
                PxrSensorState2 sensorState = new PxrSensorState2();
                int sensorFrameIndex = 0;
                int result = PXR_EnterprisePlugin.Pxr_GetPredictedMainSensorState2(
                    predictTimeMs,
                    ref sensorState,
                    ref sensorFrameIndex);

                JsonData data = BuildUnityHeadJson(sensorState);
                data["sensorFrameIndex"] = sensorFrameIndex;
                data["predictTimeMs"] = predictTimeMs;
                data["predictTimeMode"] = useDynamicPredictedDisplayTimeForEnterpriseHead
                    ? "dynamic"
                    : "sample_interval";
                data["nativeResult"] = result;
                if (result == 0)
                {
                    Interlocked.Increment(ref _enterpriseHeadSamplesInWindow);
                    UpdateLatestEnterpriseHead(sensorState);
                }
                return BuildEnvelope("enterprise", "head", Interlocked.Increment(ref _enterpriseHeadSeq),
                    result == 0, data, null);
            }
            catch (Exception e)
            {
                return BuildEnvelope("enterprise", "head", Interlocked.Increment(ref _enterpriseHeadSeq),
                    false, null, e.GetType().Name + ": " + e.Message);
            }
        }

        private double GetEnterpriseHeadPredictTimeMs()
        {
            if (useDynamicPredictedDisplayTimeForEnterpriseHead)
            {
                return PXR_Enterprise.GetPredictedDisplayTime();
            }

            long nowTicks = Stopwatch.GetTimestamp();
            long previousTicks = _lastEnterpriseHeadSampleTicks;
            _lastEnterpriseHeadSampleTicks = nowTicks;
            if (previousTicks <= 0)
            {
                return 0;
            }

            return (nowTicks - previousTicks) * 1000.0 / Stopwatch.Frequency;
        }

        private string BuildEnterpriseControllerLine()
        {
            try
            {
                double predictTimeMs = GetEnterpriseControllerPredictTimeMs();
                PoseInfo[] poses = PXR_Enterprise.GetControllerPose(predictTimeMs);
                if (poses != null)
                {
                    Interlocked.Increment(ref _enterpriseControllerSamplesInWindow);
                    UpdateLatestEnterpriseController(poses);
                }
                JsonData data = new JsonData();
                data["predictTimeMs"] = predictTimeMs;
                data["predictTimeMode"] = "latest";
                data["left"] = BuildEnterpriseControllerSide(poses, 0, _enterpriseLeftControllerLog);
                data["right"] = BuildEnterpriseControllerSide(poses, 1, _enterpriseRightControllerLog);
                return BuildEnvelope("enterprise", "controller_pose",
                    Interlocked.Increment(ref _enterpriseControllerSeq), poses != null, data, null);
            }
            catch (Exception e)
            {
                return BuildEnvelope("enterprise", "controller_pose",
                    Interlocked.Increment(ref _enterpriseControllerSeq), false, null, e.GetType().Name + ": " + e.Message);
            }
        }

        private double GetEnterpriseControllerPredictTimeMs()
        {
            return 0;
        }

        private string BuildUnityHeadLine()
        {
            try
            {
                PxrSensorState2 sensor = new PxrSensorState2();
                int sensorFrameIndex = 0;
                PXR_System.GetPredictedMainSensorStateNew(ref sensor, ref sensorFrameIndex);
                JsonData data = BuildUnityHeadJson(sensor);
                data["sensorFrameIndex"] = sensorFrameIndex;
                return BuildEnvelope("unity", "head", Interlocked.Increment(ref _unityHeadSeq), true, data, null);
            }
            catch (Exception e)
            {
                return BuildEnvelope("unity", "head", Interlocked.Increment(ref _unityHeadSeq),
                    false, null, e.GetType().Name + ": " + e.Message);
            }
        }

        private string BuildUnityControllerLine()
        {
            try
            {
                double predictTime = PXR_Enterprise.GetPredictedDisplayTime() * 1000;
                JsonData data = new JsonData();
                data["predictTime"] = predictTime;
                data["left"] = BuildUnityControllerSide(PXR_Input.Controller.LeftController, XRNode.LeftHand, predictTime,
                    _unityLeftControllerLog);
                data["right"] = BuildUnityControllerSide(PXR_Input.Controller.RightController, XRNode.RightHand, predictTime,
                    _unityRightControllerLog);
                return BuildEnvelope("unity", "controller_pose",
                    Interlocked.Increment(ref _unityControllerSeq), true, data, null);
            }
            catch (Exception e)
            {
                return BuildEnvelope("unity", "controller_pose",
                    Interlocked.Increment(ref _unityControllerSeq), false, null, e.GetType().Name + ": " + e.Message);
            }
        }

        private JsonData BuildEnterpriseControllerSide(PoseInfo[] poses, int index, ControllerLogState logState)
        {
            JsonData json = new JsonData();
            PoseInfo poseInfo = poses != null && index >= 0 && index < poses.Length ? poses[index] : null;
            LogEnterpriseControllerState(logState, poseInfo);
            bool hasPose = IsValidEnterpriseControllerPose(poseInfo);
            json["hasPose"] = hasPose;
            if (hasPose)
            {
                json["pose"] = BuildPoseJson(poseInfo);
            }

            return json;
        }

        private JsonData BuildUnityControllerSide(PXR_Input.Controller controller, XRNode xrNode, double predictTime,
            ControllerLogState logState)
        {
            Vector3 position = PXR_Input.GetControllerPredictPosition(controller, predictTime);
            Quaternion rotation = PXR_Input.GetControllerPredictRotation(controller, predictTime);
            InputDevice inputDevice = InputDevices.GetDeviceAtXRNode(xrNode);

            JsonData json = BuildInputJson(inputDevice, out ControllerInputSnapshot inputSnapshot);
            json["pose"] = GetPoseStr(position, rotation);
            json["isValid"] = inputDevice.isValid;
            json["deviceName"] = inputDevice.name;
            LogUnityControllerState(logState, inputDevice, inputSnapshot, position, rotation);
            return json;
        }

        private JsonData BuildInputJson(InputDevice inputDevice, out ControllerInputSnapshot inputSnapshot)
        {
            bool axis2DSuccess = inputDevice.TryGetFeatureValue(CommonUsages.primary2DAxis, out Vector2 axis2D);
            bool axisClickSuccess = inputDevice.TryGetFeatureValue(CommonUsages.primary2DAxisClick, out bool axisClick);
            bool gripSuccess = inputDevice.TryGetFeatureValue(CommonUsages.grip, out float grip);
            bool triggerSuccess = inputDevice.TryGetFeatureValue(CommonUsages.trigger, out float trigger);
            bool primaryButtonSuccess = inputDevice.TryGetFeatureValue(CommonUsages.primaryButton, out bool primaryButton);
            bool secondaryButtonSuccess = inputDevice.TryGetFeatureValue(CommonUsages.secondaryButton, out bool secondaryButton);
            bool menuButtonSuccess = inputDevice.TryGetFeatureValue(CommonUsages.menuButton, out bool menuButton);

            inputSnapshot = new ControllerInputSnapshot
            {
                Axis2DSuccess = axis2DSuccess,
                AxisClickSuccess = axisClickSuccess,
                GripSuccess = gripSuccess,
                TriggerSuccess = triggerSuccess,
                PrimaryButtonSuccess = primaryButtonSuccess,
                SecondaryButtonSuccess = secondaryButtonSuccess,
                MenuButtonSuccess = menuButtonSuccess
            };

            JsonData json = new JsonData();
            json["axisX"] = axis2D.x;
            json["axisY"] = axis2D.y;
            json["axisClick"] = axisClick;
            json["grip"] = grip;
            json["trigger"] = trigger;
            json["primaryButton"] = primaryButton;
            json["secondaryButton"] = secondaryButton;
            json["menuButton"] = menuButton;
            return json;
        }

        private void LogUnityControllerState(ControllerLogState state, InputDevice inputDevice,
            ControllerInputSnapshot inputSnapshot, Vector3 position, Quaternion rotation)
        {
            string featureMask = inputSnapshot.GetFeatureMask();
            bool stateChanged = !state.Initialized ||
                state.IsValid != inputDevice.isValid ||
                state.DeviceName != inputDevice.name ||
                state.FeatureMask != featureMask;

            if (stateChanged)
            {
                Debug.Log($"{Tag} controller state source=unity side={state.Side} elapsedMs={_stopwatch.ElapsedMilliseconds} " +
                    $"isValid={inputDevice.isValid} deviceName={inputDevice.name} featureMask={featureMask} " +
                    $"position={GetPosePositionStr(position)} rotation={GetPoseRotationStr(rotation)}");
            }

            UpdatePoseStagnation(state, "unity", position, rotation, GetUnityPoseStagnationThreshold());
            state.Initialized = true;
            state.HasPose = true;
            state.IsValid = inputDevice.isValid;
            state.DeviceName = inputDevice.name;
            state.FeatureMask = featureMask;
            state.Position = position;
            state.Rotation = rotation;
        }

        private void LogEnterpriseControllerState(ControllerLogState state, PoseInfo poseInfo)
        {
            bool hasPose = IsValidEnterpriseControllerPose(poseInfo);
            int confidence = hasPose ? poseInfo.confidence : -1;
            int poseError = hasPose ? poseInfo.poseError : 0;
            long timestamp = hasPose ? poseInfo.timestamp : 0L;
            bool stateChanged = !state.Initialized ||
                state.HasPose != hasPose ||
                state.Confidence != confidence ||
                state.PoseError != poseError;

            if (stateChanged)
            {
                Debug.Log($"{Tag} controller state source=enterprise side={state.Side} elapsedMs={_stopwatch.ElapsedMilliseconds} " +
                    $"hasPose={hasPose} confidence={confidence} poseError={poseError} timeStampNs={timestamp}");
            }

            if (hasPose)
            {
                Vector3 position = new Vector3((float)poseInfo.x, (float)poseInfo.y, (float)poseInfo.z);
                Quaternion rotation = new Quaternion((float)poseInfo.rx, (float)poseInfo.ry, (float)poseInfo.rz, (float)poseInfo.rw);
                UpdatePoseStagnation(state, "enterprise", position, rotation, GetEnterprisePoseStagnationThreshold());
                UpdateTimestampStagnation(state, timestamp, GetEnterprisePoseStagnationThreshold());
                state.Position = position;
                state.Rotation = rotation;
                state.Timestamp = timestamp;
            }
            else
            {
                state.SamePoseCount = 0;
                state.SameTimestampCount = 0;
            }

            state.Initialized = true;
            state.HasPose = hasPose;
            state.Confidence = confidence;
            state.PoseError = poseError;
        }

        private void UpdatePoseStagnation(ControllerLogState state, string source, Vector3 position, Quaternion rotation,
            int threshold)
        {
            if (state.Initialized && state.HasPose && IsSamePose(state.Position, state.Rotation, position, rotation))
            {
                state.SamePoseCount++;
                LogStagnationIfNeeded(state, source, "pose", state.SamePoseCount, threshold,
                    $"position={GetPosePositionStr(position)} rotation={GetPoseRotationStr(rotation)}");
            }
            else
            {
                state.SamePoseCount = 0;
                state.LastPoseStagnationLogMs = 0;
            }
        }

        private void UpdateTimestampStagnation(ControllerLogState state, long timestamp, int threshold)
        {
            if (state.Initialized && state.HasPose && state.Timestamp == timestamp)
            {
                state.SameTimestampCount++;
                LogStagnationIfNeeded(state, "enterprise", "timestamp", state.SameTimestampCount, threshold,
                    $"timeStampNs={timestamp}");
            }
            else
            {
                state.SameTimestampCount = 0;
                state.LastTimestampStagnationLogMs = 0;
            }
        }

        private void LogStagnationIfNeeded(ControllerLogState state, string source, string kind, int count, int threshold,
            string detail)
        {
            if (count < threshold)
            {
                return;
            }

            long elapsedMs = _stopwatch.ElapsedMilliseconds;
            bool firstLog = count == threshold;
            bool periodicLog = elapsedMs - (kind == "pose" ? state.LastPoseStagnationLogMs : state.LastTimestampStagnationLogMs) >= 5000;
            if (!firstLog && !periodicLog)
            {
                return;
            }

            if (kind == "pose")
            {
                state.LastPoseStagnationLogMs = elapsedMs;
            }
            else
            {
                state.LastTimestampStagnationLogMs = elapsedMs;
            }

            Debug.Log($"{Tag} controller stagnant source={source} side={state.Side} kind={kind} elapsedMs={elapsedMs} " +
                $"sameCount={count} threshold={threshold} {detail}");
        }

        private JsonData BuildUnityHeadJson(PxrSensorState2 sensorState)
        {
            JsonData json = new JsonData();
            json["pose"] = GetPoseStr(sensorState.pose.position, sensorState.pose.orientation);
            json["status"] = sensorState.status;
            json["timeStampNs"] = sensorState.poseTimeStampNs.ToString();
            return json;
        }

        private static void UpdateLatestEnterpriseHead(PxrSensorState2 sensorState)
        {
            string pose = GetPoseStr(sensorState.pose.position, sensorState.pose.orientation);
            lock (s_latestEnterpriseHeadLock)
            {
                s_latestEnterpriseHeadPose = pose;
                s_latestEnterpriseHeadStatus = sensorState.status;
                s_latestEnterpriseHeadSampleSeq++;
                s_hasLatestEnterpriseHead = true;
            }
        }

        private static void ClearLatestEnterpriseHead()
        {
            lock (s_latestEnterpriseHeadLock)
            {
                s_hasLatestEnterpriseHead = false;
                s_latestEnterpriseHeadPose = null;
                s_latestEnterpriseHeadStatus = 0;
                s_latestEnterpriseHeadSampleSeq = 0;
            }
        }

        private static void UpdateLatestEnterpriseController(PoseInfo[] poses)
        {
            EnterpriseControllerTcpPose left = CreateEnterpriseControllerTcpPose(poses, 0);
            EnterpriseControllerTcpPose right = CreateEnterpriseControllerTcpPose(poses, 1);
            lock (s_latestEnterpriseControllerLock)
            {
                s_latestEnterpriseLeftController = left;
                s_latestEnterpriseRightController = right;
                s_latestEnterpriseControllerSampleSeq++;
                s_hasLatestEnterpriseController = left.HasPose || right.HasPose;
            }
        }

        private static void ClearLatestEnterpriseController()
        {
            lock (s_latestEnterpriseControllerLock)
            {
                s_hasLatestEnterpriseController = false;
                s_latestEnterpriseLeftController = new EnterpriseControllerTcpPose();
                s_latestEnterpriseRightController = new EnterpriseControllerTcpPose();
                s_latestEnterpriseControllerSampleSeq = 0;
            }
        }

        private static EnterpriseControllerTcpPose CreateEnterpriseControllerTcpPose(PoseInfo[] poses, int index)
        {
            PoseInfo poseInfo = poses != null && index >= 0 && index < poses.Length ? poses[index] : null;
            if (!IsValidEnterpriseControllerPose(poseInfo))
            {
                return CreateInvalidEnterpriseControllerTcpPose();
            }

            return new EnterpriseControllerTcpPose
            {
                HasPose = true,
                Pose = GetPoseStr(
                    new Vector3((float)poseInfo.x, (float)poseInfo.y, (float)poseInfo.z),
                    new Quaternion((float)poseInfo.rx, (float)poseInfo.ry, (float)poseInfo.rz, (float)poseInfo.rw)),
                Status = poseInfo.confidence,
                TimeStampNs = poseInfo.timestamp,
                Type = poseInfo.type,
                PoseError = poseInfo.poseError
            };
        }

        public static EnterpriseControllerTcpPose CreateInvalidEnterpriseControllerTcpPose()
        {
            return new EnterpriseControllerTcpPose
            {
                HasPose = false,
                Pose = InvalidControllerPose,
                Status = 0,
                TimeStampNs = 0,
                Type = 0,
                PoseError = 0
            };
        }

        private static bool IsValidEnterpriseControllerPose(PoseInfo poseInfo)
        {
            if (poseInfo == null)
            {
                return false;
            }

            bool isZeroIdentityPose =
                Math.Abs(poseInfo.x) <= 0.000001 &&
                Math.Abs(poseInfo.y) <= 0.000001 &&
                Math.Abs(poseInfo.z) <= 0.000001 &&
                Math.Abs(poseInfo.rx) <= 0.000001 &&
                Math.Abs(poseInfo.ry) <= 0.000001 &&
                Math.Abs(poseInfo.rz) <= 0.000001 &&
                Math.Abs(poseInfo.rw - 1.0) <= 0.000001;
            bool isFinitePose =
                IsFinite(poseInfo.x) &&
                IsFinite(poseInfo.y) &&
                IsFinite(poseInfo.z) &&
                IsFinite(poseInfo.rx) &&
                IsFinite(poseInfo.ry) &&
                IsFinite(poseInfo.rz) &&
                IsFinite(poseInfo.rw);
            bool isPositionInRange =
                Math.Abs(poseInfo.x) <= MaxValidEnterpriseControllerPositionMeters &&
                Math.Abs(poseInfo.y) <= MaxValidEnterpriseControllerPositionMeters &&
                Math.Abs(poseInfo.z) <= MaxValidEnterpriseControllerPositionMeters;
            return (poseInfo.timestamp != 0 || !isZeroIdentityPose) && isFinitePose && isPositionInRange;
        }

        private static bool IsFinite(double value)
        {
            return !double.IsNaN(value) && !double.IsInfinity(value);
        }

        private JsonData BuildPoseJson(PoseInfo poseInfo)
        {
            JsonData json = new JsonData();
            json["pose"] = GetPoseStr(
                new Vector3((float)poseInfo.x, (float)poseInfo.y, (float)poseInfo.z),
                new Quaternion((float)poseInfo.rx, (float)poseInfo.ry, (float)poseInfo.rz, (float)poseInfo.rw));
            json["status"] = poseInfo.confidence;
            json["timeStampNs"] = poseInfo.timestamp;
            json["type"] = poseInfo.type;
            json["poseError"] = poseInfo.poseError;
            return json;
        }

        private string BuildEnvelope(string source, string kind, long seq, bool success, JsonData data, string error)
        {
            JsonData envelope = new JsonData();
            envelope["source"] = source;
            envelope["kind"] = kind;
            envelope["seq"] = seq;
            envelope["captureElapsedMs"] = _stopwatch.ElapsedMilliseconds;
            envelope["captureUnixTimeMs"] = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds();
            envelope["threadId"] = Thread.CurrentThread.ManagedThreadId;
            envelope["success"] = success;
            if (data != null)
            {
                envelope["data"] = data;
            }

            if (!string.IsNullOrEmpty(error))
            {
                envelope["error"] = error;
            }

            return envelope.ToJson();
        }

        private void Enqueue(string fileName, string line)
        {
            _fileWriter?.Enqueue(fileName, line);
        }

        private static double GetIntervalSeconds(int sampleHz)
        {
            return sampleHz > 0 ? 1.0 / sampleHz : 0.0;
        }

        private void LogEnterpriseSampleRateIfNeeded()
        {
            float intervalSeconds = Mathf.Max(0.1f, sampleRateLogIntervalSeconds);
            long nowTicks = Stopwatch.GetTimestamp();
            long elapsedTicks = nowTicks - _lastEnterpriseRateLogTicks;
            if (elapsedTicks < intervalSeconds * Stopwatch.Frequency)
            {
                return;
            }

            double elapsedSeconds = elapsedTicks / (double)Stopwatch.Frequency;
            long headCount = Interlocked.Exchange(ref _enterpriseHeadSamplesInWindow, 0);
            long controllerCount = Interlocked.Exchange(ref _enterpriseControllerSamplesInWindow, 0);
            _lastEnterpriseRateLogTicks = nowTicks;

            double headHz = elapsedSeconds > 0 ? headCount / elapsedSeconds : 0;
            double controllerHz = elapsedSeconds > 0 ? controllerCount / elapsedSeconds : 0;
            string rateMessage =
                $"Enterprise sample rate: head={headHz:F1}Hz controller={controllerHz:F1}Hz target={EnterpriseSampleHz}Hz";
            if (outputSampleRateToLogWindow)
            {
                LogWindow.Info(rateMessage);
            }

            Debug.Log($"{Tag} {rateMessage}");
        }

        private static string GetPoseStr(Vector3 position, Quaternion rotation)
        {
            return position.x.ToString("R") + "," + position.y.ToString("R") + "," + position.z.ToString("R") + "," +
                   rotation.x.ToString("R") + "," + rotation.y.ToString("R") + "," + rotation.z.ToString("R") + "," +
                   rotation.w.ToString("R");
        }

        private static string GetPoseStr(PxrVector3f position, PxrVector4f rotation)
        {
            return position.x.ToString("R") + "," + position.y.ToString("R") + "," + position.z.ToString("R") + "," +
                   rotation.x.ToString("R") + "," + rotation.y.ToString("R") + "," + rotation.z.ToString("R") + "," +
                   rotation.w.ToString("R");
        }

        private int GetUnityPoseStagnationThreshold()
        {
            return Math.Max(1, unitySampleHz);
        }

        private int GetEnterprisePoseStagnationThreshold()
        {
            return Math.Max(1, EnterpriseSampleHz);
        }

        private static bool IsSamePose(Vector3 oldPosition, Quaternion oldRotation, Vector3 newPosition,
            Quaternion newRotation)
        {
            return Approximately(oldPosition.x, newPosition.x) &&
                   Approximately(oldPosition.y, newPosition.y) &&
                   Approximately(oldPosition.z, newPosition.z) &&
                   Approximately(oldRotation.x, newRotation.x) &&
                   Approximately(oldRotation.y, newRotation.y) &&
                   Approximately(oldRotation.z, newRotation.z) &&
                   Approximately(oldRotation.w, newRotation.w);
        }

        private static bool Approximately(float left, float right)
        {
            return Math.Abs(left - right) <= 0.000001f;
        }

        private static string GetPosePositionStr(Vector3 position)
        {
            return position.x.ToString("R") + "," + position.y.ToString("R") + "," + position.z.ToString("R");
        }

        private static string GetPoseRotationStr(Quaternion rotation)
        {
            return rotation.x.ToString("R") + "," + rotation.y.ToString("R") + "," + rotation.z.ToString("R") + "," +
                   rotation.w.ToString("R");
        }

        public struct EnterpriseControllerTcpPose
        {
            public bool HasPose;
            public string Pose;
            public int Status;
            public long TimeStampNs;
            public int Type;
            public int PoseError;
        }

        private struct ControllerInputSnapshot
        {
            public bool Axis2DSuccess;
            public bool AxisClickSuccess;
            public bool GripSuccess;
            public bool TriggerSuccess;
            public bool PrimaryButtonSuccess;
            public bool SecondaryButtonSuccess;
            public bool MenuButtonSuccess;

            public string GetFeatureMask()
            {
                return "axis2D=" + Axis2DSuccess +
                       ",axisClick=" + AxisClickSuccess +
                       ",grip=" + GripSuccess +
                       ",trigger=" + TriggerSuccess +
                       ",primary=" + PrimaryButtonSuccess +
                       ",secondary=" + SecondaryButtonSuccess +
                       ",menu=" + MenuButtonSuccess;
            }
        }

        private class ControllerLogState
        {
            public readonly string Source;
            public readonly string Side;
            public bool Initialized;
            public bool HasPose;
            public bool IsValid;
            public string DeviceName;
            public string FeatureMask;
            public int Confidence;
            public int PoseError;
            public long Timestamp;
            public Vector3 Position;
            public Quaternion Rotation;
            public int SamePoseCount;
            public int SameTimestampCount;
            public long LastPoseStagnationLogMs;
            public long LastTimestampStagnationLogMs;

            public ControllerLogState(string source, string side)
            {
                Source = source;
                Side = side;
            }
        }

    }
}
