#if PICO_MS_SDK
using System.Collections.Generic;
using ByteDance.PICO.SpatialAdapter;
using UnityEngine;
using UnityEngine.InputSystem.EnhancedTouch;
using UnityEngine.InputSystem.LowLevel;
using Touch = UnityEngine.InputSystem.EnhancedTouch.Touch;
using TouchPhase = UnityEngine.InputSystem.TouchPhase;

namespace ByteDance.PICO.SpatialAdapter
{
    /// <summary>
    /// This script supports selecting multiple objects at a time 
    /// </summary>
    public class ManipulationInputManager : MonoBehaviour
    {
        struct Selection
        {
            /// <summary>
            /// The piece that is selected
            /// </summary>
            public PieceSelectionBehavior Piece;

            /// <summary>
            /// The offset between the interaction position and the position selected object for an identity device rotation.
            /// This is computed at the beginning of the interaction and combined with the current device rotation and interaction position to translate the object
            /// as the user moves their hand.
            /// </summary>
            public Vector3 PositionOffset;

            /// <summary>
            /// The difference in rotations between the initial device rotation and the selected object.
            /// This is computed at the beginning of the interaction and combined with the current device rotation to rotate the object as the user moves their hand.
            /// </summary>
            public Quaternion RotationOffset;
        }

        internal const int k_Deselected = -1;

        /// <summary>
        /// Mapping of pointers to active selections
        /// </summary>        
        readonly Dictionary<int, Selection> m_CurrentSelections = new();

        void OnEnable()
        {
            EnhancedTouchSupport.Enable();
        }

        void Update()
        {
            foreach (var touch in Touch.activeTouches)
            {
                var inputState = SpatialInputSupport.GetInputState(touch);
                var interactionId = inputState.interactionId;
        
                // Ignore poke input--piece will get stuck to the user's finger
                if (inputState.type == InteractionType.Touch)
                    continue;
        
                var pieceObject = inputState.targetObject;
                if (pieceObject != null)
                {
                    if (pieceObject.TryGetComponent(out PieceSelectionBehavior piece) && piece.selectingPointer == -1)
                    {
                        // Record initial relative position & rotation from hand to object for later use when the piece is selected
                        var pieceTransform = piece.transform;
                        var currentPosition = inputState.currentPosition;
                        var inverseDeviceRotation = Quaternion.Inverse(inputState.deviceRotation);
                        var rotationOffset = inverseDeviceRotation * pieceTransform.rotation;
                        var positionOffset = inverseDeviceRotation * (pieceTransform.position - currentPosition);
        
                        // Mark the piece as selected
                        piece.SetSelected(interactionId);
        
                        // Because events can come in faster than they are consumed, it is possible for target id to change without a prior end/cancel event
                        if (m_CurrentSelections.TryGetValue(interactionId, out var selection))
                            selection.Piece.SetSelected(k_Deselected);
        
                        // Add selection info to the map of current selections
                        m_CurrentSelections[interactionId] = new Selection
                        {
                            Piece = piece,
                            RotationOffset = rotationOffset,
                            PositionOffset = positionOffset
                        };
                    }
                }
        
                switch (inputState.phase)
                {
                    case TouchPhase.Moved:
                        if (m_CurrentSelections.TryGetValue(interactionId, out var selection))
                        {
                            // Position the piece at the interaction position, maintaining the same relative transform from interaction position to selection pivot
                            var deviceRotation = inputState.deviceRotation;
                            var rotation = deviceRotation * selection.RotationOffset;
                            var position = inputState.currentPosition + deviceRotation * selection.PositionOffset;
                            selection.Piece.transform.SetPositionAndRotation(position, rotation);
                        }
        
                        break;
                    case TouchPhase.None:
                    case TouchPhase.Ended:
                    case TouchPhase.Canceled:
                        DeselectPiece(interactionId);
                        break;
                }
            }
        }

        void DeselectPiece(int interactionId)
        {
            if (m_CurrentSelections.TryGetValue(interactionId, out var selection))
            {
                // Swap materials back when the piece is deselected
                selection.Piece.SetSelected(k_Deselected);
                m_CurrentSelections.Remove(interactionId);
            }
        }
    }
}
#endif