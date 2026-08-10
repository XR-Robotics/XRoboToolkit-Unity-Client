using System;
using System.Collections.Generic;
using UnityEditor;
using UnityEditor.Build;
using UnityEngine;

public static class RemoteVisionAddressStoreSelfTest
{
    private const string SourceA = "__SELF_TEST_PICO4U__";
    private const string SourceB = "__SELF_TEST_PANORAMA_MONO__";

    [MenuItem("Tools/Validation/Remote Vision Address Store Self-Test")]
    public static void Run()
    {
        string[] keys =
        {
            RemoteVisionAddressStore.GetSourceKey(SourceA),
            RemoteVisionAddressStore.GetSourceKey(SourceB),
            RemoteVisionAddressStore.LastAddressKey,
            RemoteVisionAddressStore.LastVideoSourceKey,
            RemoteVisionAddressStore.LegacyAddressKey,
            PcServiceAddressStore.LastAddressKey,
        };
        var snapshot = new Dictionary<string, SavedPreference>();
        foreach (string key in keys)
        {
            snapshot[key] = SavedPreference.Capture(key);
            PlayerPrefs.DeleteKey(key);
        }
        PlayerPrefs.Save();

        try
        {
            RunAssertions();
            Debug.Log("REMOTE_VISION_ADDRESS_STORE_SELF_TEST=PASS");
        }
        catch (Exception exception)
        {
            throw new BuildFailedException(
                $"Remote Vision address store self-test failed: {exception}"
            );
        }
        finally
        {
            foreach (KeyValuePair<string, SavedPreference> item in snapshot)
            {
                item.Value.Restore(item.Key);
            }
            PlayerPrefs.Save();
        }
    }

    private static void RunAssertions()
    {
        AssertNormalized(" 192.168.020.057 ", true, "192.168.20.57");
        AssertNormalized("2001:0db8::1", true, "2001:db8::1");
        AssertRejected(string.Empty, true);
        AssertRejected("operator.local", true);
        AssertRejected("192.168.1", true);
        AssertRejected("192.168.1.256", true);
        AssertRejected("192.168.1.1:13579", true);
        AssertRejected("2001:db8::1", false);
        AssertRejected("0.0.0.0", true);
        AssertRejected("224.0.0.1", true);
        AssertRejected("255.255.255.255", true);
        AssertRejected("::", true);
        AssertRejected("ff02::1", true);
        AssertTrue(
            !string.Equals(
                RemoteVisionAddressStore.GetSourceKey("A-B"),
                RemoteVisionAddressStore.GetSourceKey("A_B"),
                StringComparison.Ordinal
            ),
            "punctuation-distinct source keys"
        );
        AssertTrue(
            !string.Equals(
                RemoteVisionAddressStore.GetSourceKey("全景一"),
                RemoteVisionAddressStore.GetSourceKey("全景二"),
                StringComparison.Ordinal
            ),
            "Unicode-distinct source keys"
        );

        AssertEqual(string.Empty, RemoteVisionAddressStore.Load(SourceA), "empty install");
        AssertTrue(
            RemoteVisionAddressStore.TrySave(SourceA, "10.0.0.1", out string sourceA),
            "save source A"
        );
        AssertEqual("10.0.0.1", sourceA, "source A normalization");
        AssertTrue(
            RemoteVisionAddressStore.TrySave(SourceB, "10.0.0.2", out string sourceB),
            "save source B"
        );
        AssertEqual("10.0.0.2", sourceB, "source B normalization");
        AssertEqual("10.0.0.1", RemoteVisionAddressStore.Load(SourceA), "source A isolation");
        AssertEqual("10.0.0.2", RemoteVisionAddressStore.Load(SourceB), "source B isolation");
        AssertEqual(SourceB, RemoteVisionAddressStore.LoadLastVideoSource(), "last source");

        string[] invalidSaveKeys =
        {
            RemoteVisionAddressStore.GetSourceKey(SourceA),
            RemoteVisionAddressStore.LastAddressKey,
            RemoteVisionAddressStore.LastVideoSourceKey,
            RemoteVisionAddressStore.LegacyAddressKey,
        };
        var invalidSaveSnapshot = new Dictionary<string, SavedPreference>();
        foreach (string key in invalidSaveKeys)
        {
            invalidSaveSnapshot[key] = SavedPreference.Capture(key);
        }
        AssertTrue(
            !RemoteVisionAddressStore.TrySave(SourceA, "not-an-ip", out _),
            "invalid save must fail"
        );
        foreach (KeyValuePair<string, SavedPreference> item in invalidSaveSnapshot)
        {
            AssertTrue(item.Value.Matches(item.Key), $"invalid save mutated {item.Key}");
        }

        PlayerPrefs.SetString(RemoteVisionAddressStore.GetSourceKey(SourceA), "invalid");
        PlayerPrefs.SetString(RemoteVisionAddressStore.LastAddressKey, "10.0.0.3");
        PlayerPrefs.SetString(RemoteVisionAddressStore.LegacyAddressKey, "10.0.0.4");
        AssertEqual("10.0.0.3", RemoteVisionAddressStore.Load(SourceA), "global fallback");

        PlayerPrefs.SetString(RemoteVisionAddressStore.LastAddressKey, "invalid");
        AssertEqual("10.0.0.4", RemoteVisionAddressStore.Load(SourceA), "legacy fallback");
        PlayerPrefs.SetString(RemoteVisionAddressStore.LegacyAddressKey, "invalid");
        AssertEqual(string.Empty, RemoteVisionAddressStore.Load(SourceA), "invalid fallback");

        AssertTrue(
            PcServiceAddressStore.TrySave(" 172.31.3.184 ", out string pcService),
            "save PC service IPv4"
        );
        AssertEqual("172.31.3.184", pcService, "PC service normalization");
        AssertEqual("172.31.3.184", PcServiceAddressStore.Load(), "load PC service");
        AssertTrue(
            !PcServiceAddressStore.TrySave("2001:db8::1", out _),
            "PC service must reject IPv6 until TcpHandler supports it"
        );
        AssertEqual(
            "172.31.3.184",
            PcServiceAddressStore.Load(),
            "rejected PC service input must not mutate prefs"
        );
    }

    private static void AssertNormalized(
        string rawAddress,
        bool allowIpv6,
        string expected
    )
    {
        AssertTrue(
            IpAddressNormalizer.TryNormalize(rawAddress, allowIpv6, out string actual),
            $"normalize {rawAddress}"
        );
        AssertEqual(expected, actual, $"normalized value for {rawAddress}");
    }

    private static void AssertRejected(string rawAddress, bool allowIpv6)
    {
        AssertTrue(
            !IpAddressNormalizer.TryNormalize(rawAddress, allowIpv6, out _),
            $"reject {rawAddress}"
        );
    }

    private static void AssertTrue(bool condition, string context)
    {
        if (!condition)
        {
            throw new InvalidOperationException(context);
        }
    }

    private static void AssertEqual(string expected, string actual, string context)
    {
        if (!string.Equals(expected, actual, StringComparison.Ordinal))
        {
            throw new InvalidOperationException(
                $"{context}: expected '{expected}', got '{actual}'"
            );
        }
    }

    private readonly struct SavedPreference
    {
        private readonly bool exists;
        private readonly string value;

        private SavedPreference(bool exists, string value)
        {
            this.exists = exists;
            this.value = value;
        }

        public static SavedPreference Capture(string key)
        {
            return PlayerPrefs.HasKey(key)
                ? new SavedPreference(true, PlayerPrefs.GetString(key, string.Empty))
                : new SavedPreference(false, string.Empty);
        }

        public void Restore(string key)
        {
            if (exists)
            {
                PlayerPrefs.SetString(key, value);
            }
            else
            {
                PlayerPrefs.DeleteKey(key);
            }
        }

        public bool Matches(string key)
        {
            if (exists != PlayerPrefs.HasKey(key))
            {
                return false;
            }

            return !exists ||
                   string.Equals(
                       value,
                       PlayerPrefs.GetString(key, string.Empty),
                       StringComparison.Ordinal
                   );
        }
    }
}
