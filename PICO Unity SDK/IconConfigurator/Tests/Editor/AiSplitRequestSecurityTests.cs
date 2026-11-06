using System;
using NUnit.Framework;

namespace ByteDance.PICO.IconConfigurator.Editor.Tests
{
    public class AiSplitRequestSecurityTests
    {
        [Test]
        public void GenerateSignature_WhenGivenSigningInputs_ReturnsLowercaseSha256Hex()
        {
            string signature = AiSplitRequestSigner.GenerateSignature("app-1", "device-1", "salt-1");

            Assert.That(signature, Is.EqualTo("8eca0432c91637352ba7ec48f3c4c6e05561be2228036c4018b1d6f8e16ddae8"));
            Assert.That(signature, Has.Length.EqualTo(64));
            Assert.That(signature, Does.Match("^[0-9a-f]{64}$"));
        }

        [Test]
        public void GetDeviceId_WhenInjectedDidExists_ReturnsInjectedDid()
        {
            AiSplitDeviceIdProvider provider = new AiSplitDeviceIdProvider(() => " injected-did ");

            string deviceId = provider.GetDeviceId();

            Assert.That(deviceId, Is.EqualTo("injected-did"));
        }

        [Test]
        public void GetDeviceId_WhenInjectedDidIsMissing_GeneratesStableFallback64BitHex()
        {
            int fallbackCalls = 0;
            AiSplitDeviceIdProvider provider = new AiSplitDeviceIdProvider(
                () => string.Empty,
                () =>
                {
                    fallbackCalls++;
                    return 0x0102030405060708UL;
                });

            string firstDeviceId = provider.GetDeviceId();
            string secondDeviceId = provider.GetDeviceId();

            Assert.That(firstDeviceId, Is.EqualTo("0102030405060708"));
            Assert.That(secondDeviceId, Is.EqualTo(firstDeviceId));
            Assert.That(firstDeviceId, Does.Match("^[0-9a-f]{16}$"));
            Assert.That(fallbackCalls, Is.EqualTo(1));
        }

        [Test]
        public void TryAcquire_WhenMoreThanFiveGenerationsStartWithinOneMinute_BlocksRequest()
        {
            DateTime now = new DateTime(2026, 6, 10, 10, 0, 0, DateTimeKind.Utc);
            AiSplitGenerationRateLimiter limiter = new AiSplitGenerationRateLimiter(() => now);

            for (int i = 0; i < 5; i++)
            {
                Assert.That(limiter.TryAcquire(out string allowedError), Is.True);
                Assert.That(allowedError, Is.Empty);
            }

            bool sixthAllowed = limiter.TryAcquire(out string blockedError);

            Assert.That(sixthAllowed, Is.False);
            Assert.That(blockedError, Is.EqualTo(AiSplitGenerationRateLimiter.RateLimitedMessage));
        }

        [Test]
        public void TryAcquire_WhenOneMinuteWindowPasses_AllowsNewGeneration()
        {
            DateTime now = new DateTime(2026, 6, 10, 10, 0, 0, DateTimeKind.Utc);
            AiSplitGenerationRateLimiter limiter = new AiSplitGenerationRateLimiter(() => now);

            for (int i = 0; i < 5; i++)
            {
                Assert.That(limiter.TryAcquire(out _), Is.True);
            }

            now = now.AddSeconds(60);

            Assert.That(limiter.TryAcquire(out string errorMessage), Is.True);
            Assert.That(errorMessage, Is.Empty);
        }
    }
}
