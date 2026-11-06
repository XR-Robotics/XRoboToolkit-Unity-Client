using System;
using System.Reflection;
using UnityEditor;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public sealed class AiSplitEnvironmentService
    {
        public const string SpatialGlobalEnvironmentVariable = "SPATIAL_GLOBAL";
        public const string PpeInternalEditorPrefsKey = "IconConfigurator.AiSplit.UsePpeInternal";
        public const string RegionOverrideEditorPrefsKey = "IconConfigurator.AiSplit.RegionOverride";

        private readonly Func<bool?> m_envInternalProvider;
        private readonly Func<string, string> m_environmentVariableProvider;

        public AiSplitEnvironmentService()
            : this(ReadSpatialPluginEnvInternal, Environment.GetEnvironmentVariable)
        {
        }

        public AiSplitEnvironmentService(
            Func<bool?> envInternalProvider,
            Func<string, string> environmentVariableProvider)
        {
            m_envInternalProvider = envInternalProvider ?? (() => null);
            m_environmentVariableProvider = environmentVariableProvider ?? (_ => null);
        }

        public AiSplitRegionPreference ResolvePreference()
        {
            if (TryReadEditorOverride(out AiSplitRegionPreference overridePreference))
            {
                return overridePreference;
            }

            if (EditorPrefs.GetBool(PpeInternalEditorPrefsKey, false) || m_envInternalProvider() == true)
            {
                return AiSplitRegionPreference.Internal;
            }

            return IsTruthy(m_environmentVariableProvider(SpatialGlobalEnvironmentVariable))
                ? AiSplitRegionPreference.Global
                : AiSplitRegionPreference.Cn;
        }

        public string ResolveRegionKey()
        {
            return AiSplitTccManager.GetRegionName(ResolvePreference());
        }

        private static bool TryReadEditorOverride(out AiSplitRegionPreference preference)
        {
            string rawValue = EditorPrefs.GetString(RegionOverrideEditorPrefsKey, string.Empty);
            if (Enum.TryParse(rawValue, true, out preference))
            {
                return true;
            }

            preference = default;
            return false;
        }

        private static bool IsTruthy(string value)
        {
            return string.Equals(value, "1", StringComparison.OrdinalIgnoreCase)
                || string.Equals(value, "true", StringComparison.OrdinalIgnoreCase)
                || string.Equals(value, "yes", StringComparison.OrdinalIgnoreCase);
        }

        private static bool? ReadSpatialPluginEnvInternal()
        {
            Type type = FindType("SpatialPlugin.EnvInternal");
            if (type == null)
            {
                return null;
            }

            return ReadBooleanMember(type, "Value")
                ?? ReadBooleanMember(type, "Enabled")
                ?? ReadBooleanMember(type, "IsEnabled")
                ?? ReadBooleanMember(type, "IsInternal");
        }

        private static Type FindType(string fullName)
        {
            Assembly[] assemblies = AppDomain.CurrentDomain.GetAssemblies();
            for (int i = 0; i < assemblies.Length; i++)
            {
                Type type = assemblies[i].GetType(fullName, false);
                if (type != null)
                {
                    return type;
                }
            }

            return null;
        }

        private static bool? ReadBooleanMember(Type type, string name)
        {
            const BindingFlags Flags = BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Static;
            PropertyInfo property = type.GetProperty(name, Flags);
            if (property != null && property.PropertyType == typeof(bool))
            {
                return (bool)property.GetValue(null);
            }

            FieldInfo field = type.GetField(name, Flags);
            if (field != null && field.FieldType == typeof(bool))
            {
                return (bool)field.GetValue(null);
            }

            MethodInfo method = type.GetMethod(name, Flags, null, Type.EmptyTypes, null);
            if (method != null && method.ReturnType == typeof(bool))
            {
                return (bool)method.Invoke(null, null);
            }

            return null;
        }
    }
}
