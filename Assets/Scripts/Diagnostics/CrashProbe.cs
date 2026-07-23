using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using UnityEngine;

public static class CrashProbe
{
    private const string Schema = "g1_pico_crash_probe_v1";
    private const string BreadcrumbSchema = "g1_pico_crash_breadcrumb_v1";
    private const string DirectoryName = "g1_wuji_crash_probe";
    private const string SentinelFileName = "active_session.json";
    private const string LastExitFileName = "last_exit.json";
    private const string BreadcrumbFileName = "breadcrumbs.jsonl";
    private const long MaxBreadcrumbBytes = 1024 * 1024;
    private const int MaxBreadcrumbLinesAfterTrim = 2000;
    private const float SentinelHeartbeatIntervalSeconds = 5f;
    private const float BreadcrumbHeartbeatIntervalSeconds = 30f;
    private const int MaxFieldLength = 2048;
    private const int MaxStackLength = 4096;
    private const int WatchdogPollMilliseconds = 2000;
    private const double MainThreadStallSeconds = 10.0;

    private static readonly object Sync = new object();
    private static bool initialized;
    private static string sessionId = "";
    private static string probeDirectory = "";
    private static string sentinelPath = "";
    private static string lastExitPath = "";
    private static string breadcrumbPath = "";
    private static string appVersion = "";
    private static string unityVersion = "";
    private static string platform = "";
    private static string deviceModel = "";
    private static string deviceName = "";
    private static string operatingSystem = "";
    private static string persistentDataPath = "";
    private static int mainThreadId;
    private static long startTimestamp;
    private static long lastMainThreadTickTimestamp;
    private static long lastWatchdogReportTimestamp;
    private static double stopwatchFrequency;
    private static long sequence;
    private static float nextSentinelHeartbeat;
    private static float nextBreadcrumbHeartbeat;
    private static int logHookDepth;
    private static bool previousUncleanExitDetected;
    private static volatile bool appPaused;
    private static volatile bool watchdogStopRequested;
    private static Thread watchdogThread;

    public static string ProbeDirectory => probeDirectory;
    public static string BreadcrumbPath => breadcrumbPath;
    public static string LastExitPath => lastExitPath;
    public static string SessionId => sessionId;

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
    private static void InitializeBeforeSceneLoad()
    {
        Initialize();
    }

    public static void Initialize()
    {
        if (initialized)
        {
            return;
        }

        try
        {
            lock (Sync)
            {
                if (initialized)
                {
                    return;
                }

                sessionId = DateTime.UtcNow.ToString("yyyyMMddTHHmmssfffZ") + "-" +
                            Guid.NewGuid().ToString("N").Substring(0, 8);
                mainThreadId = Thread.CurrentThread.ManagedThreadId;
                startTimestamp = System.Diagnostics.Stopwatch.GetTimestamp();
                lastMainThreadTickTimestamp = startTimestamp;
                stopwatchFrequency = System.Diagnostics.Stopwatch.Frequency;
                appVersion = Application.version;
                unityVersion = Application.unityVersion;
                platform = Application.platform.ToString();
                deviceModel = SystemInfo.deviceModel;
                deviceName = SystemInfo.deviceName;
                operatingSystem = SystemInfo.operatingSystem;
                persistentDataPath = Application.persistentDataPath;
                probeDirectory = Path.Combine(persistentDataPath, DirectoryName);
                sentinelPath = Path.Combine(probeDirectory, SentinelFileName);
                lastExitPath = Path.Combine(probeDirectory, LastExitFileName);
                breadcrumbPath = Path.Combine(probeDirectory, BreadcrumbFileName);
                Directory.CreateDirectory(probeDirectory);

                string previousSentinel = ReadAllTextOrEmpty(sentinelPath);
                bool previousClean = previousSentinel.Contains("\"clean_exit\":\"true\"");
                if (!string.IsNullOrWhiteSpace(previousSentinel) && !previousClean)
                {
                    previousUncleanExitDetected = true;
                    WriteLastExit(previousSentinel);
                }

                WriteSentinel("started", cleanExit: false, detail: "");
                initialized = true;
            }
        }
        catch (Exception e)
        {
            Debug.LogWarning("CrashProbe disabled during initialization: " + e.Message);
            return;
        }

        Application.logMessageReceivedThreaded += OnLogMessageReceivedThreaded;
        Application.quitting += OnApplicationQuitting;
        AppDomain.CurrentDomain.UnhandledException += OnUnhandledException;
        TaskScheduler.UnobservedTaskException += OnUnobservedTaskException;
        StartWatchdog();

        Breadcrumb(
            "app.start",
            $"session={sessionId}; path={probeDirectory}",
            LogType.Log,
            new Dictionary<string, string>
            {
                {"app_version", appVersion},
                {"unity_version", unityVersion},
                {"platform", platform},
                {"device_model", deviceModel},
                {"device_name", deviceName},
                {"operating_system", operatingSystem},
                {"persistent_data_path", persistentDataPath}
            });

        if (previousUncleanExitDetected)
        {
            Breadcrumb("app.previous_unclean_exit", "previous session did not mark clean exit", LogType.Warning);
            Debug.LogWarning("Previous Pico app session did not exit cleanly; CrashProbe captured the prior session marker.");
        }
    }

    public static void Tick()
    {
        if (!initialized)
        {
            return;
        }

        Interlocked.Exchange(ref lastMainThreadTickTimestamp, System.Diagnostics.Stopwatch.GetTimestamp());

        float now = Time.realtimeSinceStartup;
        if (now >= nextSentinelHeartbeat)
        {
            nextSentinelHeartbeat = now + SentinelHeartbeatIntervalSeconds;
            try
            {
                lock (Sync)
                {
                    WriteSentinel("running", cleanExit: false, detail: "");
                }
            }
            catch
            {
                // Diagnostic heartbeats are best-effort.
            }
        }

        if (now >= nextBreadcrumbHeartbeat)
        {
            nextBreadcrumbHeartbeat = now + BreadcrumbHeartbeatIntervalSeconds;
            Breadcrumb("app.heartbeat", $"frame={Time.frameCount}");
        }
    }

    public static void Lifecycle(string eventName, string detail = "")
    {
        if (eventName == "pause")
        {
            appPaused = true;
        }
        else if (eventName == "resume")
        {
            appPaused = false;
            Interlocked.Exchange(ref lastMainThreadTickTimestamp, System.Diagnostics.Stopwatch.GetTimestamp());
        }

        Breadcrumb("lifecycle." + eventName, detail);
        try
        {
            lock (Sync)
            {
                WriteSentinel("lifecycle." + eventName, cleanExit: false, detail: detail);
            }
        }
        catch
        {
            // Lifecycle logging must not affect app lifecycle handling.
        }
    }

    public static void MarkCleanExit(string reason)
    {
        watchdogStopRequested = true;
        Breadcrumb("app.clean_exit", reason);
        try
        {
            lock (Sync)
            {
                WriteSentinel("clean_exit", cleanExit: true, detail: reason);
            }
        }
        catch
        {
            // Clean-exit marking is best-effort; never block shutdown.
        }
    }

    public static void Breadcrumb(
        string eventName,
        string detail = "",
        LogType severity = LogType.Log,
        IDictionary<string, string> fields = null)
    {
        if (!initialized)
        {
            return;
        }

        try
        {
            lock (Sync)
            {
                AppendBreadcrumb(eventName, detail, severity, "", fields);
            }
        }
        catch
        {
            // CrashProbe must never take the app down while trying to report a failure.
        }
    }

    public static void Exception(string eventName, Exception exception)
    {
        if (exception == null)
        {
            Breadcrumb(eventName, "null exception", LogType.Exception);
            return;
        }

        Breadcrumb(
            eventName,
            exception.GetType().FullName + ": " + exception.Message,
            LogType.Exception,
            new Dictionary<string, string> {{"stack", exception.StackTrace ?? ""}});
    }

    private static void OnApplicationQuitting()
    {
        MarkCleanExit("Application.quitting");
    }

    private static void StartWatchdog()
    {
        if (watchdogThread != null)
        {
            return;
        }

        watchdogStopRequested = false;
        watchdogThread = new Thread(WatchdogLoop);
        watchdogThread.IsBackground = true;
        watchdogThread.Name = "G1PicoCrashProbeWatchdog";
        watchdogThread.Start();
    }

    private static void WatchdogLoop()
    {
        while (!watchdogStopRequested)
        {
            Thread.Sleep(WatchdogPollMilliseconds);
            if (watchdogStopRequested || appPaused || !initialized || stopwatchFrequency <= 0)
            {
                continue;
            }

            long now = System.Diagnostics.Stopwatch.GetTimestamp();
            long lastTick = Interlocked.Read(ref lastMainThreadTickTimestamp);
            double stalledSeconds = (now - lastTick) / stopwatchFrequency;
            if (stalledSeconds < MainThreadStallSeconds)
            {
                continue;
            }

            long lastReport = Interlocked.Read(ref lastWatchdogReportTimestamp);
            if (lastReport != 0 && (now - lastReport) / stopwatchFrequency < MainThreadStallSeconds)
            {
                continue;
            }

            Interlocked.Exchange(ref lastWatchdogReportTimestamp, now);
            Breadcrumb(
                "app.main_thread_stall",
                $"no_main_tick_s={stalledSeconds:F1}",
                LogType.Warning);
            try
            {
                lock (Sync)
                {
                    WriteSentinel(
                        "main_thread_stall",
                        cleanExit: false,
                        detail: $"no_main_tick_s={stalledSeconds:F1}");
                }
            }
            catch
            {
            }
        }
    }

    private static void OnUnhandledException(object sender, UnhandledExceptionEventArgs args)
    {
        Exception exception = args.ExceptionObject as Exception;
        if (exception != null)
        {
            Exception("managed.unhandled_exception", exception);
        }
        else
        {
            Breadcrumb(
                "managed.unhandled_exception",
                args.ExceptionObject != null ? args.ExceptionObject.ToString() : "unknown exception",
                LogType.Exception);
        }

        try
        {
            lock (Sync)
            {
                WriteSentinel("managed.unhandled_exception", cleanExit: false, detail: "terminating=" + args.IsTerminating);
            }
        }
        catch
        {
        }
    }

    private static void OnUnobservedTaskException(object sender, UnobservedTaskExceptionEventArgs args)
    {
        Exception("managed.unobserved_task_exception", args.Exception);
        try
        {
            lock (Sync)
            {
                WriteSentinel("managed.unobserved_task_exception", cleanExit: false, detail: "");
            }
        }
        catch
        {
        }
    }

    private static void OnLogMessageReceivedThreaded(string condition, string stackTrace, LogType type)
    {
        if (type != LogType.Exception && type != LogType.Error && type != LogType.Assert && type != LogType.Warning)
        {
            return;
        }

        if (Interlocked.Increment(ref logHookDepth) > 1)
        {
            Interlocked.Decrement(ref logHookDepth);
            return;
        }

        try
        {
            lock (Sync)
            {
                AppendBreadcrumb(
                    "unity.log",
                    condition,
                    type,
                    stackTrace,
                    new Dictionary<string, string> {{"log_type", type.ToString()}});

                if (type == LogType.Exception || type == LogType.Error || type == LogType.Assert)
                {
                    WriteSentinel("unity." + type.ToString().ToLowerInvariant(), cleanExit: false, detail: condition);
                }
            }
        }
        catch
        {
            // Ignore probe failures from Unity's log callback path.
        }
        finally
        {
            Interlocked.Decrement(ref logHookDepth);
        }
    }

    private static void AppendBreadcrumb(
        string eventName,
        string detail,
        LogType severity,
        string stackTrace,
        IDictionary<string, string> fields)
    {
        Directory.CreateDirectory(probeDirectory);
        string line = BuildJsonLine(eventName, detail, severity, stackTrace, fields);
        File.AppendAllText(breadcrumbPath, line + "\n", Encoding.UTF8);
        TrimBreadcrumbFileIfNeeded();
    }

    private static string BuildJsonLine(
        string eventName,
        string detail,
        LogType severity,
        string stackTrace,
        IDictionary<string, string> fields)
    {
        var builder = new StringBuilder(512);
        builder.Append('{');
        AppendJsonField(builder, "schema", BreadcrumbSchema, first: true);
        AppendJsonField(builder, "session_id", sessionId);
        AppendJsonField(builder, "seq", Interlocked.Increment(ref sequence).ToString());
        AppendJsonField(builder, "ts_utc", DateTime.UtcNow.ToString("O"));
        AppendJsonField(builder, "realtime_s", SafeRealtimeSeconds());
        AppendJsonField(builder, "frame", SafeFrameCount());
        AppendJsonField(builder, "level", severity.ToString());
        AppendJsonField(builder, "event", eventName);
        AppendJsonField(builder, "detail", Truncate(detail, MaxFieldLength));
        if (!string.IsNullOrEmpty(stackTrace))
        {
            AppendJsonField(builder, "stack", Truncate(stackTrace, MaxStackLength));
        }

        if (fields != null)
        {
            foreach (KeyValuePair<string, string> field in fields)
            {
                string key = "field_" + SanitizeKey(field.Key);
                AppendJsonField(builder, key, Truncate(field.Value, MaxFieldLength));
            }
        }

        builder.Append('}');
        return builder.ToString();
    }

    private static void WriteSentinel(string state, bool cleanExit, string detail)
    {
        Directory.CreateDirectory(probeDirectory);
        var fields = new Dictionary<string, string>
        {
            {"schema", Schema},
            {"session_id", sessionId},
            {"state", state},
            {"clean_exit", cleanExit ? "true" : "false"},
            {"detail", Truncate(detail, MaxFieldLength)},
            {"ts_utc", DateTime.UtcNow.ToString("O")},
            {"realtime_s", SafeRealtimeSeconds()},
            {"frame", SafeFrameCount()},
            {"app_version", appVersion},
            {"unity_version", unityVersion},
            {"platform", platform}
        };
        WriteJsonObject(sentinelPath, fields);
    }

    private static void WriteLastExit(string previousSentinel)
    {
        var builder = new StringBuilder(512);
        builder.Append('{');
        AppendJsonField(builder, "schema", "g1_pico_last_exit_v1", first: true);
        AppendJsonField(builder, "detected_ts_utc", DateTime.UtcNow.ToString("O"));
        AppendJsonField(builder, "reason", "previous session did not mark clean_exit=true");
        AppendJsonField(builder, "previous_sentinel", Truncate(previousSentinel, MaxStackLength));
        builder.Append('}');
        File.WriteAllText(lastExitPath, builder.ToString() + "\n", Encoding.UTF8);
    }

    private static void WriteJsonObject(string path, IDictionary<string, string> fields)
    {
        string temporary = path + ".tmp";
        var builder = new StringBuilder(512);
        builder.Append('{');
        bool first = true;
        foreach (KeyValuePair<string, string> field in fields)
        {
            AppendJsonField(builder, field.Key, field.Value, first);
            first = false;
        }
        builder.Append('}');
        builder.Append('\n');
        File.WriteAllText(temporary, builder.ToString(), Encoding.UTF8);
        if (File.Exists(path))
        {
            File.Delete(path);
        }
        File.Move(temporary, path);
    }

    private static void TrimBreadcrumbFileIfNeeded()
    {
        var info = new FileInfo(breadcrumbPath);
        if (!info.Exists || info.Length <= MaxBreadcrumbBytes)
        {
            return;
        }

        string[] lines = File.ReadAllLines(breadcrumbPath, Encoding.UTF8);
        int start = Math.Max(0, lines.Length - MaxBreadcrumbLinesAfterTrim);
        string temporary = breadcrumbPath + ".tmp";
        using (var writer = new StreamWriter(temporary, append: false, encoding: Encoding.UTF8))
        {
            for (int i = start; i < lines.Length; i++)
            {
                writer.WriteLine(lines[i]);
            }
        }
        File.Delete(breadcrumbPath);
        File.Move(temporary, breadcrumbPath);
    }

    private static string ReadAllTextOrEmpty(string path)
    {
        try
        {
            return File.Exists(path) ? File.ReadAllText(path, Encoding.UTF8) : "";
        }
        catch
        {
            return "";
        }
    }

    private static void AppendJsonField(StringBuilder builder, string key, string value, bool first = false)
    {
        if (!first)
        {
            builder.Append(',');
        }
        builder.Append('"');
        builder.Append(JsonEscape(key));
        builder.Append("\":\"");
        builder.Append(JsonEscape(value ?? ""));
        builder.Append('"');
    }

    private static string JsonEscape(string value)
    {
        if (string.IsNullOrEmpty(value))
        {
            return "";
        }

        var builder = new StringBuilder(value.Length + 16);
        foreach (char ch in value)
        {
            switch (ch)
            {
                case '\\':
                    builder.Append("\\\\");
                    break;
                case '"':
                    builder.Append("\\\"");
                    break;
                case '\n':
                    builder.Append("\\n");
                    break;
                case '\r':
                    builder.Append("\\r");
                    break;
                case '\t':
                    builder.Append("\\t");
                    break;
                default:
                    if (ch < 32)
                    {
                        builder.Append("\\u");
                        builder.Append(((int)ch).ToString("x4"));
                    }
                    else
                    {
                        builder.Append(ch);
                    }
                    break;
            }
        }
        return builder.ToString();
    }

    private static string SanitizeKey(string key)
    {
        if (string.IsNullOrEmpty(key))
        {
            return "value";
        }

        var builder = new StringBuilder(key.Length);
        foreach (char ch in key)
        {
            if ((ch >= 'a' && ch <= 'z') ||
                (ch >= 'A' && ch <= 'Z') ||
                (ch >= '0' && ch <= '9') ||
                ch == '_')
            {
                builder.Append(ch);
            }
            else
            {
                builder.Append('_');
            }
        }
        return builder.ToString();
    }

    private static string Truncate(string value, int maxLength)
    {
        if (string.IsNullOrEmpty(value) || value.Length <= maxLength)
        {
            return value ?? "";
        }
        return value.Substring(0, maxLength) + "...<truncated>";
    }

    private static string SafeRealtimeSeconds()
    {
        try
        {
            if (Thread.CurrentThread.ManagedThreadId == mainThreadId)
            {
                return Time.realtimeSinceStartup.ToString("F3");
            }

            long elapsed = System.Diagnostics.Stopwatch.GetTimestamp() - startTimestamp;
            return (elapsed / stopwatchFrequency).ToString("F3");
        }
        catch
        {
            return "";
        }
    }

    private static string SafeFrameCount()
    {
        try
        {
            if (Thread.CurrentThread.ManagedThreadId != mainThreadId)
            {
                return "";
            }

            return Time.frameCount.ToString();
        }
        catch
        {
            return "";
        }
    }
}
