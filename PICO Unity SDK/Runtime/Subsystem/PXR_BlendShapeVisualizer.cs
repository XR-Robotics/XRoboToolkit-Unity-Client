#if AR_FOUNDATION_5 || AR_FOUNDATION_6
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR;

namespace ByteDance.PICO.XR
{
    public class PXR_BlendShapeVisualizer : MonoBehaviour
    {
        [SerializeField] private float m_CoefficientScale = 100.0f;
        [SerializeField] private SkinnedMeshRenderer m_SkinnedMeshRenderer;

        public float coefficientScale
        {
            get => m_CoefficientScale;
            set => m_CoefficientScale = value;
        }

        public SkinnedMeshRenderer skinnedMeshRenderer
        {
            get => m_SkinnedMeshRenderer;
            set
            {
                m_SkinnedMeshRenderer = value;
                CreateFeatureBlendMapping();
            }
        }

        private PXR_FaceSubsystem m_PICOFaceSubsystem;
        private Dictionary<BlendShapeIndex, int> m_FaceBlendShapeIndexMap;
        private PxrFacialSimulationData ftData;
        private bool m_IsInitialized;
        private const string BlendShapePrefix = "blendShape2.";

        private void Awake()
        {
            CreateFeatureBlendMapping();
        }

        private void CreateFeatureBlendMapping()
        {
            if (m_SkinnedMeshRenderer == null || m_SkinnedMeshRenderer.sharedMesh == null)
            {
                m_IsInitialized = false;
                return;
            }

            m_FaceBlendShapeIndexMap = new Dictionary<BlendShapeIndex, int>(128);
            var sharedMesh = m_SkinnedMeshRenderer.sharedMesh;

            AddBlendShapeMapping(BlendShapeIndex.EyeLookDown_L, "eyeLookDown_L");
            AddBlendShapeMapping(BlendShapeIndex.NoseSneer_L, "noseSneer_L");
            AddBlendShapeMapping(BlendShapeIndex.EyeLookIn_L, "eyeLookIn_L");
            AddBlendShapeMapping(BlendShapeIndex.BrowInnerUp, "browInnerUp");
            AddBlendShapeMapping(BlendShapeIndex.BrowDown_R, "browDown_R");
            AddBlendShapeMapping(BlendShapeIndex.MouthClose, "mouthClose");
            AddBlendShapeMapping(BlendShapeIndex.MouthLowerDown_R, "mouthLowerDown_R");
            AddBlendShapeMapping(BlendShapeIndex.JawOpen, "jawOpen");
            AddBlendShapeMapping(BlendShapeIndex.MouthUpperUp_R, "mouthUpperUp_R");
            AddBlendShapeMapping(BlendShapeIndex.MouthShrugUpper, "mouthShrugUpper");
            AddBlendShapeMapping(BlendShapeIndex.MouthFunnel, "mouthFunnel");
            AddBlendShapeMapping(BlendShapeIndex.EyeLookIn_R, "eyeLookIn_R");
            AddBlendShapeMapping(BlendShapeIndex.EyeLookDown_R, "eyeLookDown_R");
            AddBlendShapeMapping(BlendShapeIndex.NoseSneer_R, "noseSneer_R");
            AddBlendShapeMapping(BlendShapeIndex.MouthRollUpper, "mouthRollUpper");
            AddBlendShapeMapping(BlendShapeIndex.JawRight, "jawRight");
            AddBlendShapeMapping(BlendShapeIndex.BrowDown_L, "browDown_L");
            AddBlendShapeMapping(BlendShapeIndex.MouthShrugLower, "mouthShrugLower");
            AddBlendShapeMapping(BlendShapeIndex.MouthRollLower, "mouthRollLower");
            AddBlendShapeMapping(BlendShapeIndex.MouthSmile_L, "mouthSmile_L");
            AddBlendShapeMapping(BlendShapeIndex.MouthPress_L, "mouthPress_L");
            AddBlendShapeMapping(BlendShapeIndex.MouthSmile_R, "mouthSmile_R");
            AddBlendShapeMapping(BlendShapeIndex.MouthPress_R, "mouthPress_R");
            AddBlendShapeMapping(BlendShapeIndex.MouthDimple_R, "mouthDimple_R");
            AddBlendShapeMapping(BlendShapeIndex.MouthLeft, "mouthLeft");
            AddBlendShapeMapping(BlendShapeIndex.JawForward, "jawForward");
            AddBlendShapeMapping(BlendShapeIndex.EyeSquint_L, "eyeSquint_L");
            AddBlendShapeMapping(BlendShapeIndex.MouthFrown_L, "mouthFrown_L");
            AddBlendShapeMapping(BlendShapeIndex.EyeBlink_L, "eyeBlink_L");
            AddBlendShapeMapping(BlendShapeIndex.CheekSquint_L, "cheekSquint_L");
            AddBlendShapeMapping(BlendShapeIndex.BrowOuterUp_L, "browOuterUp_L");
            AddBlendShapeMapping(BlendShapeIndex.EyeLookUp_L, "eyeLookUp_L");
            AddBlendShapeMapping(BlendShapeIndex.JawLeft, "jawLeft");
            AddBlendShapeMapping(BlendShapeIndex.MouthStretch_L, "mouthStretch_L");
            AddBlendShapeMapping(BlendShapeIndex.MouthPucker, "mouthPucker");
            AddBlendShapeMapping(BlendShapeIndex.EyeLookUp_R, "eyeLookUp_R");
            AddBlendShapeMapping(BlendShapeIndex.BrowOuterUp_R, "browOuterUp_R");
            AddBlendShapeMapping(BlendShapeIndex.CheekSquint_R, "cheekSquint_R");
            AddBlendShapeMapping(BlendShapeIndex.EyeBlink_R, "eyeBlink_R");
            AddBlendShapeMapping(BlendShapeIndex.MouthUpperUp_L, "mouthUpperUp_L");
            AddBlendShapeMapping(BlendShapeIndex.MouthFrown_R, "mouthFrown_R");
            AddBlendShapeMapping(BlendShapeIndex.EyeSquint_R, "eyeSquint_R");
            AddBlendShapeMapping(BlendShapeIndex.MouthStretch_R, "mouthStretch_R");
            AddBlendShapeMapping(BlendShapeIndex.CheekPuff, "cheekPuff");
            AddBlendShapeMapping(BlendShapeIndex.EyeLookOut_L, "eyeLookOut_L");
            AddBlendShapeMapping(BlendShapeIndex.EyeLookOut_R, "eyeLookOut_R");
            AddBlendShapeMapping(BlendShapeIndex.EyeWide_R, "eyeWide_R");
            AddBlendShapeMapping(BlendShapeIndex.EyeWide_L, "eyeWide_L");
            AddBlendShapeMapping(BlendShapeIndex.MouthDimple_L, "mouthDimple_L");
            AddBlendShapeMapping(BlendShapeIndex.MouthLowerDown_L, "mouthLowerDown_L");
            AddBlendShapeMapping(BlendShapeIndex.MouthRight, "mouthRight");
            AddBlendShapeMapping(BlendShapeIndex.TongueOut, "tongueOut");

            m_IsInitialized = true;
        }

        private void AddBlendShapeMapping(BlendShapeIndex index, string shapeName)
        {
            int blendShapeIndex = m_SkinnedMeshRenderer.sharedMesh.GetBlendShapeIndex(BlendShapePrefix + shapeName);
            if (blendShapeIndex >= 0)
            {
                m_FaceBlendShapeIndexMap[index] = blendShapeIndex;
            }
        }

        private void Update()
        {
            if (!m_IsInitialized || m_SkinnedMeshRenderer == null || !m_SkinnedMeshRenderer.enabled)
            {
                return;
            }

            UpdateBlendShapeWeight();
        }

        private unsafe void UpdateBlendShapeWeight()
        {
            if (m_FaceBlendShapeIndexMap == null || m_FaceBlendShapeIndexMap.Count == 0)
            {
                return;
            }

            PXR_FaceSubsystem.GetBlendShapeCoefficients(ref ftData);

            if (!ftData.isUpperFaceDataValid && !ftData.isLowerFaceDataValid)
            {
                return;
            }

            float scale = m_CoefficientScale;
            var meshRenderer = m_SkinnedMeshRenderer;

            for (int i = 0; i < PXR_FacialSimulation.FACE_COUNT; i++)
            {
                XrFaceExpressionBD faceExpr = (XrFaceExpressionBD)i;
                BlendShapeIndex bsIndex = faceExpr.ToBlendShapeIndex();

                if (m_FaceBlendShapeIndexMap.TryGetValue(bsIndex, out int mappedBlendShapeIndex))
                {
                    meshRenderer.SetBlendShapeWeight(mappedBlendShapeIndex, ftData.faceExpressionWeights[i] * scale);
                }
            }

            for (int i = 0; i < PXR_FacialSimulation.LIPSYNC_COUNT; i++)
            {
                XrLipExpressionBD lipExpr = (XrLipExpressionBD)i;
                BlendShapeIndex bsIndex = lipExpr.ToBlendShapeIndex();

                if (m_FaceBlendShapeIndexMap.TryGetValue(bsIndex, out int mappedBlendShapeIndex))
                {
                    meshRenderer.SetBlendShapeWeight(mappedBlendShapeIndex, ftData.lipsyncExpressionWeights[i] * scale);
                }
            }
        }
    }
}
#endif
