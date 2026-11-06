#if ENABLE_PICO_OPENXR_SDK
using UnityEditor;
using UnityEngine;

namespace ByteDance.PICO.OpenXR.Editor
{
    internal static class OpenXRInspectorLayout
    {
        internal const float LabelWidth = 210f;
    }

    [CustomEditor(typeof(OpenXRExtensions))]
    internal class PXR_OpenXRExtensionsEditor : UnityEditor.Editor
    {
        public override void OnInspectorGUI()
        {
            float originalLabelWidth = EditorGUIUtility.labelWidth;
            EditorGUIUtility.labelWidth = OpenXRInspectorLayout.LabelWidth;
            serializedObject.Update();
            SerializedProperty iterator = serializedObject.GetIterator();
            bool enterChildren = true;
            while (iterator.NextVisible(enterChildren))
            {
                enterChildren = false;
                if (iterator.propertyPath == "m_Script")
                {
                    using (new EditorGUI.DisabledScope(true))
                    {
                        EditorGUILayout.PropertyField(iterator, true);
                    }
                    continue;
                }
                EditorGUILayout.PropertyField(iterator, true);
            }
            serializedObject.ApplyModifiedProperties();
            EditorGUIUtility.labelWidth = originalLabelWidth;
        }
    }

    [CustomEditor(typeof(FacialSimulationFeature))]
    internal class FacialSimulationFeatureEditor : UnityEditor.Editor
    {
        private const float LabelWidth = OpenXRInspectorLayout.LabelWidth;

        public override void OnInspectorGUI()
        {
            float originalLabelWidth = EditorGUIUtility.labelWidth;
            EditorGUIUtility.labelWidth = LabelWidth;

            serializedObject.Update();

            using (new EditorGUI.DisabledScope(true))
            {
                EditorGUILayout.PropertyField(serializedObject.FindProperty("m_Script"));
            }

            EditorGUILayout.PropertyField(serializedObject.FindProperty("enableFaceTrackingPermission"));
            EditorGUILayout.PropertyField(serializedObject.FindProperty("enableRecordAudioPermission"));

            serializedObject.ApplyModifiedProperties();
            EditorGUIUtility.labelWidth = originalLabelWidth;
        }
    }
}
#endif
