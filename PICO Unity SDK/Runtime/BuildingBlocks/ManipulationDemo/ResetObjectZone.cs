#if PICO_MS_SDK
using UnityEngine;

namespace ByteDance.PICO.SpatialAdapter
{
    /// <summary>
    /// Respawns pieces that fall out of bounds
    /// </summary>
    class ResetObjectZone : MonoBehaviour
    {
        /// <summary>
        /// Location where pieces are respawned
        /// </summary>
        [SerializeField]
        Transform m_RespawnPosition;

        void OnTriggerEnter(Collider other)
        {
            if (other.gameObject.TryGetComponent(out PieceSelectionBehavior piece))
            {
                var pieceTransform = piece.transform;
                var pieceRigidbody = pieceTransform.GetComponent<Rigidbody>();

                // Reset the velocity and position of the piece
                pieceRigidbody.isKinematic = true;
                pieceTransform.position = m_RespawnPosition.position;

                // Re-enable physics on this piece
                pieceRigidbody.isKinematic = false;
            }
        }
    }
}
#endif