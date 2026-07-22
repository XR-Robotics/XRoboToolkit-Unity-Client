using System;
using System.Globalization;
using System.Net;
using System.Net.Sockets;
using System.Text;
using UnityEngine;

public static class IpAddressNormalizer
{
    public static bool TryNormalize(string rawAddress, bool allowIpv6, out string normalized)
    {
        normalized = string.Empty;
        if (string.IsNullOrWhiteSpace(rawAddress))
        {
            return false;
        }

        string candidate = rawAddress.Trim();
        if (candidate.IndexOf(':') >= 0)
        {
            if (!allowIpv6 || candidate.IndexOf('%') >= 0)
            {
                return false;
            }

            if (!IPAddress.TryParse(candidate, out IPAddress ipv6) ||
                ipv6.AddressFamily != AddressFamily.InterNetworkV6 ||
                ipv6.Equals(IPAddress.IPv6Any) ||
                ipv6.IsIPv6Multicast)
            {
                return false;
            }

            normalized = ipv6.ToString();
            return true;
        }

        string[] parts = candidate.Split('.');
        if (parts.Length != 4)
        {
            return false;
        }

        string[] normalizedParts = new string[parts.Length];
        for (int i = 0; i < parts.Length; i++)
        {
            string part = parts[i];
            if (part.Length == 0 ||
                part.Length > 3 ||
                !int.TryParse(
                    part,
                    NumberStyles.None,
                    CultureInfo.InvariantCulture,
                    out int octet
                ) ||
                octet < 0 ||
                octet > 255)
            {
                return false;
            }

            normalizedParts[i] = octet.ToString(CultureInfo.InvariantCulture);
        }

        string canonicalIpv4 = string.Join(".", normalizedParts);
        if (!IPAddress.TryParse(canonicalIpv4, out IPAddress ipv4) ||
            ipv4.AddressFamily != AddressFamily.InterNetwork)
        {
            return false;
        }

        byte[] addressBytes = ipv4.GetAddressBytes();
        if (addressBytes[0] == 0 || addressBytes[0] >= 224)
        {
            return false;
        }

        normalized = ipv4.ToString();
        return true;
    }
}

public static class RemoteVisionAddressStore
{
    public const string LastAddressKey = "RemoteVision.OperatorIp.Last";
    public const string LastVideoSourceKey = "RemoteVision.VideoSource.Last";
    public const string LegacyAddressKey = "CameraSendInputDialog";
    public const string SourceAddressKeyPrefix = "RemoteVision.OperatorIp.Source.";

    public static string Load(string videoSourceName)
    {
        if (!string.IsNullOrWhiteSpace(videoSourceName))
        {
            string sourceAddress = LoadValidAddress(GetSourceKey(videoSourceName), true);
            if (!string.IsNullOrEmpty(sourceAddress))
            {
                return sourceAddress;
            }
        }

        string lastAddress = LoadValidAddress(LastAddressKey, true);
        if (!string.IsNullOrEmpty(lastAddress))
        {
            return lastAddress;
        }

        return LoadValidAddress(LegacyAddressKey, true);
    }

    public static string LoadLastVideoSource()
    {
        return PlayerPrefs.HasKey(LastVideoSourceKey)
            ? PlayerPrefs.GetString(LastVideoSourceKey, string.Empty).Trim()
            : string.Empty;
    }

    public static bool TrySave(
        string videoSourceName,
        string rawAddress,
        out string normalizedAddress
    )
    {
        if (!IpAddressNormalizer.TryNormalize(rawAddress, true, out normalizedAddress))
        {
            return false;
        }

        string sourceName = videoSourceName == null ? string.Empty : videoSourceName.Trim();
        if (!string.IsNullOrEmpty(sourceName))
        {
            PlayerPrefs.SetString(GetSourceKey(sourceName), normalizedAddress);
            PlayerPrefs.SetString(LastVideoSourceKey, sourceName);
        }

        PlayerPrefs.SetString(LastAddressKey, normalizedAddress);
        // Keep the old key current so an in-place rollback can still recover the last address.
        PlayerPrefs.SetString(LegacyAddressKey, normalizedAddress);
        PlayerPrefs.Save();
        return true;
    }

    public static string GetSourceKey(string videoSourceName)
    {
        return SourceAddressKeyPrefix + EncodeSourceName(videoSourceName);
    }

    private static string LoadValidAddress(string key, bool allowIpv6)
    {
        if (!PlayerPrefs.HasKey(key))
        {
            return string.Empty;
        }

        return IpAddressNormalizer.TryNormalize(
            PlayerPrefs.GetString(key, string.Empty),
            allowIpv6,
            out string normalized
        )
            ? normalized
            : string.Empty;
    }

    private static string EncodeSourceName(string videoSourceName)
    {
        string sourceName = string.IsNullOrWhiteSpace(videoSourceName)
            ? "default"
            : videoSourceName.Trim();
        return Convert.ToBase64String(Encoding.UTF8.GetBytes(sourceName))
            .TrimEnd('=')
            .Replace('+', '-')
            .Replace('/', '_');
    }
}

public static class PcServiceAddressStore
{
    public const string LastAddressKey = "PCService.Ip.Last";

    public static string Load()
    {
        if (!PlayerPrefs.HasKey(LastAddressKey))
        {
            return string.Empty;
        }

        return IpAddressNormalizer.TryNormalize(
            PlayerPrefs.GetString(LastAddressKey, string.Empty),
            false,
            out string normalized
        )
            ? normalized
            : string.Empty;
    }

    public static bool TrySave(string rawAddress, out string normalizedAddress)
    {
        if (!IpAddressNormalizer.TryNormalize(rawAddress, false, out normalizedAddress))
        {
            return false;
        }

        PlayerPrefs.SetString(LastAddressKey, normalizedAddress);
        PlayerPrefs.Save();
        return true;
    }
}
