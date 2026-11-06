#if PICO_MS_SDK
using UnityEngine;

namespace ByteDance.PICO.SpatialAdapter
{
    /// <summary>
    /// Container for parameters that control a piece. For actual manipulation logic, see ManipulationInputManager.cs
    /// </summary>
    [RequireComponent(typeof(Rigidbody))]
    public class PieceSelectionBehavior : MonoBehaviour
    {
        private MeshRenderer m_MeshRenderer;

        private Material m_DefaultMat;

        [SerializeField]
        Material m_SelectedMat;

        Rigidbody m_RigidBody;

        public int selectingPointer { get; private set; } = ManipulationInputManager.k_Deselected;

        void Start()
        {
            m_RigidBody = GetComponent<Rigidbody>();
            m_MeshRenderer = GetComponent<MeshRenderer>();
            m_DefaultMat = m_MeshRenderer.sharedMaterial;
        }

        public void SetSelected(int pointer)
        {
            var isSelected = pointer != ManipulationInputManager.k_Deselected;
            selectingPointer = pointer;
            m_MeshRenderer.material = isSelected ? m_SelectedMat : m_DefaultMat;
            m_RigidBody.isKinematic = isSelected;
        }
    }
}
#endif