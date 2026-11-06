using System;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Text;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public static class AiSplitRequestSigner
    {
        public static string GenerateSignature(string appId, string deviceId, string salt)
        {
            string payload = (appId ?? string.Empty) + (deviceId ?? string.Empty) + (salt ?? string.Empty);
            byte[] bytes = Encoding.UTF8.GetBytes(payload);

            using SHA256 sha256 = SHA256.Create();
            byte[] hash = sha256.ComputeHash(bytes);
            StringBuilder builder = new StringBuilder(hash.Length * 2);
            for (int i = 0; i < hash.Length; i++)
            {
                builder.Append(hash[i].ToString("x2"));
            }

            return builder.ToString();
        }
    }

    public sealed class AiSplitDeviceIdProvider
    {
        private readonly Func<string> m_injectedDidProvider;
        private readonly Func<ulong> m_fallbackIdProvider;
        private string m_cachedDeviceId;

        public AiSplitDeviceIdProvider(Func<string> injectedDidProvider)
            : this(injectedDidProvider, GenerateRandomFallbackId)
        {
        }

        public AiSplitDeviceIdProvider(Func<string> injectedDidProvider, Func<ulong> fallbackIdProvider)
        {
            m_injectedDidProvider = injectedDidProvider;
            m_fallbackIdProvider = fallbackIdProvider ?? GenerateRandomFallbackId;
        }

        public string GetDeviceId()
        {
            if (!string.IsNullOrEmpty(m_cachedDeviceId))
            {
                return m_cachedDeviceId;
            }

            string injectedDid = m_injectedDidProvider?.Invoke();
            if (!string.IsNullOrWhiteSpace(injectedDid))
            {
                m_cachedDeviceId = injectedDid.Trim();
                return m_cachedDeviceId;
            }

            m_cachedDeviceId = m_fallbackIdProvider().ToString("x16");
            return m_cachedDeviceId;
        }

        private static ulong GenerateRandomFallbackId()
        {
            byte[] bytes = new byte[sizeof(ulong)];
            RandomNumberGenerator.Fill(bytes);
            return BitConverter.ToUInt64(bytes, 0);
        }
    }

    public sealed class AiSplitGenerationRateLimiter
    {
        public const string RateLimitedMessage = "Too many requests, please try again later.";

        private const int MaxRequestsPerWindow = 5;
        private static readonly TimeSpan Window = TimeSpan.FromMinutes(1);

        private readonly Func<DateTime> m_utcNowProvider;
        private readonly Queue<DateTime> m_requestTimes = new Queue<DateTime>();

        public AiSplitGenerationRateLimiter(Func<DateTime> utcNowProvider)
        {
            m_utcNowProvider = utcNowProvider ?? (() => DateTime.UtcNow);
        }

        public bool TryAcquire(out string errorMessage)
        {
            DateTime now = m_utcNowProvider();
            TrimExpiredRequests(now);

            if (m_requestTimes.Count >= MaxRequestsPerWindow)
            {
                errorMessage = RateLimitedMessage;
                return false;
            }

            m_requestTimes.Enqueue(now);
            errorMessage = string.Empty;
            return true;
        }

        private void TrimExpiredRequests(DateTime now)
        {
            while (m_requestTimes.Count > 0 && now - m_requestTimes.Peek() >= Window)
            {
                m_requestTimes.Dequeue();
            }
        }
    }
}
