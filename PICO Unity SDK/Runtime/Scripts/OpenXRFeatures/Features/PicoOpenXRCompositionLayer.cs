#if ENABLE_PICO_OPENXR_SDK&&UNITY_OPENXR_1_16_0
#if XR_COMPOSITION_LAYERS
using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using Unity.XR.CompositionLayers;
using Unity.XR.CompositionLayers.Layers;
using Unity.XR.CompositionLayers.Services;
using UnityEngine;
using UnityEngine.XR.OpenXR.CompositionLayers;
using UnityEngine.XR.OpenXR.NativeTypes;

#if UNITY_EDITOR
using System.Reflection;
using UnityEditor;
using UnityEngine.UIElements;
#endif

namespace ByteDance.PICO.OpenXR
{
    [Serializable]
    [CompositionLayerData(
        Provider = "PICO OpenXR",
        Name = "CompositionLayer",
        IconPath = "",
        InspectorIcon = "",
        ListViewIcon = "",
        Description = "PICO Composition Layer",
        SuggestedExtenstionTypes = new Type[] { }
    )]
    public class PicoLayerData : LayerData
    {
    }

    [StructLayout(LayoutKind.Sequential)]
    unsafe struct PICOCompositionLayer
    {
        public void* next;
        public XrCompositionLayerFlags flags;
    }

    class PicoOpenXRCompositionLayer : OpenXRCustomLayerHandler<PICOCompositionLayer>
    {

        protected override bool CreateSwapchain(CompositionLayerManager.LayerInfo layer, out SwapchainCreateInfo swapchainCreateInfo)
        {
            swapchainCreateInfo = default;
            return false;
        }

        protected override bool CreateNativeLayer(
            CompositionLayerManager.LayerInfo layerInfo,
            SwapchainCreatedOutput swapchainOutput,
            out PICOCompositionLayer nativeLayer)
        {
            nativeLayer = default;
            return false;
        }

        protected override bool ModifyNativeLayer(CompositionLayerManager.LayerInfo layerInfo, ref PICOCompositionLayer nativeLayer)
        {
            return false;
        }

        protected override bool ActiveNativeLayer(CompositionLayerManager.LayerInfo layerInfo, ref PICOCompositionLayer nativeLayer)
        {
            return false;
        }

        public override void RemoveLayer(int removedLayerId)
        {

        }
    }

#if UNITY_EDITOR
    static class PicoCompositionhLayerCreateUtil
    {
        [MenuItem("GameObject/XR/Composition Layers/PICO Composition Layer", false, 80)]
        static void CreateCompositionLayer()
        {
            var gameObject = new GameObject("PICO Composition Layer");
            Undo.RegisterCreatedObjectUndo(gameObject, "Create PICO Composition layer");
            gameObject.SetActive(false);
            AddCompositionLayer(gameObject);
            gameObject.SetActive(true);
        }

        [MenuItem("Component/XR/Composition Layers/PICO Composition Layer", false, 120)]
        static void CreateCompositionLayerComponent()
        {
            var gameObject = Selection.activeGameObject;
            AddCompositionLayer(gameObject);
        }

        [MenuItem("Component/XR/Composition Layers/PICO Composition Layer", true)]
        static bool ValidateCompositionLayerComponent()
        {
            var gameObject = Selection.activeGameObject;
            if (gameObject == null)
                return false;

            var layer = gameObject.GetComponent(typeof(CompositionLayer));
            if (layer != null)
                return false;

            return true;
        }

        static void AddCompositionLayer(GameObject gameObject)
        {
            if (gameObject == null)
                return;

            var layerDataType = typeof(PicoLayerData);
            var descriptor = CompositionLayerUtils.GetLayerDescriptor(layerDataType);

            var layer = Undo.AddComponent<CompositionLayer>(gameObject);
            if (layer == null)
                return;

            var layerData = CompositionLayerUtils.CreateLayerData(layerDataType);
            layer.ChangeLayerDataType(layerData);
            foreach (var extension in descriptor.SuggestedExtensions)
            {
                if (extension.IsSubclassOf(typeof(MonoBehaviour)))
                    Undo.AddComponent(gameObject, extension);
            }
        }
    }

    [CustomPropertyDrawer(typeof(PicoLayerData))]
    class PicoCompositionLayerDataDrawer : PropertyDrawer
    {
        const string k_BlendTypePropertyName = "m_BlendType";
        static readonly MethodInfo s_ReportStateChangeMethod =
            typeof(CompositionLayer).GetMethod("ReportStateChange", BindingFlags.Instance | BindingFlags.NonPublic);

        public override void OnGUI(Rect position, SerializedProperty property, GUIContent label)
        {
            if (property == null ||
                property.propertyType != SerializedPropertyType.ManagedReference ||
                property.managedReferenceValue == null)
            {
                return;
            }

            using (var change = new EditorGUI.ChangeCheckScope())
            {
                EditorGUI.BeginProperty(position, label, property);
                EditorGUI.LabelField(position, label);
                EditorGUI.indentLevel++;

                if (property.hasVisibleChildren)
                {
                    var enumerator = property.GetEnumerator();
                    while (enumerator.MoveNext())
                    {
                        var currentProperty = enumerator.Current as SerializedProperty;
                        if (currentProperty == null)
                            continue;

                        if (currentProperty.name == k_BlendTypePropertyName)
                            continue;

                        EditorGUILayout.PropertyField(currentProperty);
                    }
                }
                else
                {
                    EditorGUI.BeginDisabledGroup(true);
                    EditorGUILayout.LabelField("No modifiable properties");
                    EditorGUI.EndDisabledGroup();
                }

                if (change.changed)
                    ApplyChangesWithReportStateChange(property);

                EditorGUI.indentLevel--;
                EditorGUI.EndProperty();
            }
        }

        static void ApplyChangesWithReportStateChange(SerializedProperty property)
        {
            var serializedObject = property.serializedObject;
            serializedObject.ApplyModifiedProperties();
            foreach (var targetObject in serializedObject.targetObjects)
            {
                if (targetObject is CompositionLayer layer)
                    s_ReportStateChangeMethod?.Invoke(layer, null);
            }
        }
    }

    [CustomEditor(typeof(CompositionLayer))]
    [CanEditMultipleObjects]
    class PicoCompositionLayerConditionalEditor : UnityEditor.Editor
    {
        const string k_CompositionLayersEditorAssemblyName = "Unity.XR.CompositionLayers.Editor";
        const string k_CompositionLayerEditorTypeName = "Unity.XR.CompositionLayers.Layers.Editor.CompositionLayerEditor";
        const string k_CompositionLayerEditorAssemblyQualifiedName =
            "Unity.XR.CompositionLayers.Layers.Editor.CompositionLayerEditor, Unity.XR.CompositionLayers.Editor";

        static string[] s_TypeIds;
        static string[] s_DisplayNames;
        static bool s_TypeListInitialized;

        VisualElement m_Root;
        UnityEditor.Editor m_DefaultEditor;

        void OnEnable()
        {
            EnsureDefaultEditor();
        }

        void OnDisable()
        {
            if (m_DefaultEditor != null)
            {
                DestroyImmediate(m_DefaultEditor);
                m_DefaultEditor = null;
            }
        }

        public override VisualElement CreateInspectorGUI()
        {
            EnsureDefaultEditor();
            m_Root = new VisualElement();
            Rebuild();
            return m_Root;
        }

        void Rebuild()
        {
            if (m_Root == null)
                return;

            m_Root.Clear();

            EnsureDefaultEditor();

            if (ShouldUseMinimalInspector())
            {
                EnsureTypeLists();
                m_Root.Add(BuildMinimalInspector());
                return;
            }

            if (m_DefaultEditor != null)
            {
                var ve = m_DefaultEditor.CreateInspectorGUI();
                if (ve != null)
                {
                    m_Root.Add(ve);
                    return;
                }

                m_Root.Add(new IMGUIContainer(() => m_DefaultEditor.OnInspectorGUI()));
                return;
            }

            EnsureTypeLists();
            m_Root.Add(BuildMinimalInspector());
        }

        void EnsureDefaultEditor()
        {
            if (m_DefaultEditor != null)
                return;

            var editorType = GetCompositionLayersDefaultEditorType();
            if (editorType == null)
                return;

            m_DefaultEditor = CreateEditor(targets, editorType);
        }

        static System.Type GetCompositionLayersDefaultEditorType()
        {
            var direct = System.Type.GetType(k_CompositionLayerEditorAssemblyQualifiedName, false);
            if (direct != null)
                return direct;

            try
            {
                var loaded = Assembly.Load(k_CompositionLayersEditorAssemblyName);
                if (loaded != null)
                {
                    var t = loaded.GetType(k_CompositionLayerEditorTypeName);
                    if (t != null)
                        return t;
                }
            }
            catch
            {
            }

            var assemblies = System.AppDomain.CurrentDomain.GetAssemblies();
            for (var i = 0; i < assemblies.Length; i++)
            {
                var asm = assemblies[i];
                var name = asm.GetName().Name;
                if (name != k_CompositionLayersEditorAssemblyName)
                    continue;

                return asm.GetType(k_CompositionLayerEditorTypeName);
            }

            return null;
        }

        bool ShouldUseMinimalInspector()
        {
            for (var i = 0; i < targets.Length; i++)
            {
                if (targets[i] is not CompositionLayer layer)
                    return false;

                if (layer.LayerData == null)
                    return false;

                if (layer.LayerData.GetType() != typeof(PicoLayerData))
                    return false;
            }

            return targets.Length > 0;
        }

        static void EnsureTypeLists()
        {
            if (s_TypeListInitialized && s_TypeIds != null && s_DisplayNames != null && s_TypeIds.Length == s_DisplayNames.Length)
                return;

            s_TypeListInitialized = true;
            var descriptors = CompositionLayerUtils.GetAllLayerDescriptors();
            descriptors.Sort((a, b) =>
            {
                var providerCompare = string.Compare(a.Provider, b.Provider, StringComparison.Ordinal);
                if (providerCompare != 0)
                    return providerCompare;
                return string.Compare(a.Name, b.Name, StringComparison.Ordinal);
            });

            var ids = new List<string>(descriptors.Count);
            var names = new List<string>(descriptors.Count);
            for (var i = 0; i < descriptors.Count; i++)
            {
                var d = descriptors[i];
                ids.Add(d.TypeFullName);
                names.Add($"{d.Provider} - {d.Name}");
            }

            s_TypeIds = ids.ToArray();
            s_DisplayNames = names.ToArray();
        }

        VisualElement BuildMinimalInspector()
        {
            var first = target as CompositionLayer;
            if (first == null)
                return new VisualElement();

            var firstTypeId = first.LayerData != null ? first.LayerData.GetType().FullName : string.Empty;
            var hasMixed = false;
            for (var i = 0; i < targets.Length; i++)
            {
                if (targets[i] is not CompositionLayer layer)
                    continue;

                var typeId = layer.LayerData != null ? layer.LayerData.GetType().FullName : string.Empty;
                if (typeId != firstTypeId)
                {
                    hasMixed = true;
                    break;
                }
            }

            var currentIndex = 0;
            for (var i = 0; i < s_TypeIds.Length; i++)
            {
                if (s_TypeIds[i] == firstTypeId)
                {
                    currentIndex = i;
                    break;
                }
            }

            var displayName =
                !hasMixed && currentIndex >= 0 && currentIndex < s_DisplayNames.Length
                    ? s_DisplayNames[currentIndex]
                    : "Mixed";

            var layerTypeField = new TextField("Layer Type")
            {
                value = displayName,
                isReadOnly = true
            };
            layerTypeField.SetEnabled(false);

            var container = new VisualElement();
            container.Add(layerTypeField);
            return container;
        }
    }
#endif
}
#endif
#endif
