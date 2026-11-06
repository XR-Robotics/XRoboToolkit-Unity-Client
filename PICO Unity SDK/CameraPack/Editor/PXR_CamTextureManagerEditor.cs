using UnityEditor;

namespace ByteDance.PICO.CameraPack
{
    [CustomEditor(typeof(PXR_CamTextureManager))]
    [CanEditMultipleObjects]
    public class PXR_CamTextureManagerEditor : Editor
    {
        public override void OnInspectorGUI()
        {
            serializedObject.Update();
            DrawDefaultInspector();
            serializedObject.ApplyModifiedProperties();
        }
    }
}
