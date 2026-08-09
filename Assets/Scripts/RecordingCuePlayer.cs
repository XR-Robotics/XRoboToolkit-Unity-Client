using System;
using System.Collections.Concurrent;
using UnityEngine;

namespace Robot
{
    /// <summary>Plays non-spatial recording state cues through the PICO headset.</summary>
    public sealed class RecordingCuePlayer : MonoBehaviour
    {
        private const string FunctionName = "recording_cue";
        private const int SampleRate = 44100;
        private static RecordingCuePlayer _instance;

        private readonly ConcurrentQueue<string> _pendingCues =
            new ConcurrentQueue<string>();

        private AudioSource _audioSource;
        private AudioClip _startClip;
        private AudioClip _stopClip;
        private AudioClip _deleteClip;
        private AudioClip _errorClip;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
        private static void Bootstrap()
        {
            if (_instance != null)
            {
                return;
            }

            GameObject cueObject = new GameObject(nameof(RecordingCuePlayer));
            DontDestroyOnLoad(cueObject);
            _instance = cueObject.AddComponent<RecordingCuePlayer>();
        }

        private void Awake()
        {
            if (_instance != null && _instance != this)
            {
                Destroy(gameObject);
                return;
            }

            _instance = this;
            DontDestroyOnLoad(gameObject);
            _audioSource = gameObject.AddComponent<AudioSource>();
            _audioSource.playOnAwake = false;
            _audioSource.loop = false;
            _audioSource.spatialBlend = 0.0f;
            _audioSource.volume = 0.75f;
            _audioSource.ignoreListenerPause = true;

            _startClip = CreateTone("recording_start", 1200.0f, 0.14f, 1);
            _stopClip = CreateTone("recording_stop", 520.0f, 0.22f, 1);
            _deleteClip = CreateTone("recording_delete", 760.0f, 0.09f, 2);
            _errorClip = CreateTone("recording_error", 360.0f, 0.12f, 3);
        }

        private void OnEnable()
        {
            TcpHandler.ReceiveFunctionEvent += OnFunctionMessage;
        }

        private void OnDisable()
        {
            TcpHandler.ReceiveFunctionEvent -= OnFunctionMessage;
        }

        private void OnFunctionMessage(string functionName, string value)
        {
            if (string.Equals(functionName, FunctionName, StringComparison.Ordinal))
            {
                _pendingCues.Enqueue(value);
            }
        }

        private void Update()
        {
            if (!_pendingCues.TryDequeue(out string value))
            {
                return;
            }

            switch (value)
            {
                case "start":
                    Play(_startClip);
                    break;
                case "stop":
                    Play(_stopClip);
                    break;
                case "delete":
                    Play(_deleteClip);
                    break;
                case "error":
                    Play(_errorClip);
                    break;
                default:
                    Debug.LogWarning($"Unknown recording cue: {value}");
                    break;
            }
        }

        private void Play(AudioClip clip)
        {
            if (_audioSource == null || clip == null)
            {
                return;
            }

            _audioSource.Stop();
            _audioSource.PlayOneShot(clip);
            Debug.Log($"PICO recording cue played: {clip.name}");
        }

        private static AudioClip CreateTone(string name, float frequencyHz, float pulseDurationS, int pulses)
        {
            const float gapDurationS = 0.07f;
            float totalDurationS = pulses * pulseDurationS + Math.Max(0, pulses - 1) * gapDurationS;
            int sampleCount = Math.Max(1, Mathf.CeilToInt(totalDurationS * SampleRate));
            float[] samples = new float[sampleCount];
            int pulseSamples = Mathf.CeilToInt(pulseDurationS * SampleRate);
            int strideSamples = Mathf.CeilToInt((pulseDurationS + gapDurationS) * SampleRate);
            int fadeSamples = Mathf.Max(1, Mathf.CeilToInt(0.006f * SampleRate));

            for (int pulse = 0; pulse < pulses; pulse++)
            {
                int start = pulse * strideSamples;
                int end = Math.Min(sampleCount, start + pulseSamples);
                for (int i = start; i < end; i++)
                {
                    int local = i - start;
                    float envelope = 1.0f;
                    if (local < fadeSamples)
                    {
                        envelope = local / (float)fadeSamples;
                    }
                    else if (end - i <= fadeSamples)
                    {
                        envelope = (end - i) / (float)fadeSamples;
                    }

                    samples[i] = 0.32f * envelope *
                                 Mathf.Sin(2.0f * Mathf.PI * frequencyHz * i / SampleRate);
                }
            }

            AudioClip clip = AudioClip.Create(name, sampleCount, 1, SampleRate, false);
            clip.SetData(samples, 0);
            return clip;
        }
    }
}
