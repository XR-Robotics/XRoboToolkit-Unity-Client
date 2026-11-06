using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

namespace Robot
{
    public enum EyeGazeHitKind
    {
        None,
        Collider,
        WorldSpaceUI
    }

    public struct EyeGazeHit
    {
        public EyeGazeHitKind Kind;
        public Vector3 Point;
        public Vector3 Normal;
        public float Distance;
        public GameObject Target;
        public bool HasHit => Kind != EyeGazeHitKind.None;
    }

    [DisallowMultipleComponent]
    [RequireComponent(typeof(PicoEyeGazeSource))]
    [DefaultExecutionOrder(200)]
    public sealed class EyeGazeRaycaster : MonoBehaviour
    {
        [SerializeField] private PicoEyeGazeSource source;
        [SerializeField, Min(0.1f)] private float maxDistance = 10f;
        [SerializeField] private LayerMask hitLayers = Physics.DefaultRaycastLayers;
        [Tooltip("Exclude the rig and its controller/hand geometry from gaze hits.")]
        [SerializeField] private Transform ignoredRoot;
        [SerializeField] private bool hitWorldSpaceUI = true;
        [Header("Runtime result")]
        [SerializeField] private EyeGazeHitKind hitKind;
        [SerializeField] private Vector3 hitPoint;
        [SerializeField] private GameObject hitTarget;
        [SerializeField] private float hitDistance;

        private readonly RaycastHit[] _physicsHits = new RaycastHit[64];
        private EyeGazeHit _hit;
        private int _resultFrame = -1;

        public PicoEyeGazeSource Source => source;
        public float MaxDistance => Mathf.Max(0.1f, maxDistance);
        public bool HasValidRay => isActiveAndEnabled && source != null &&
                                   source.HasValidSample && _resultFrame == Time.frameCount;
        public bool HasHit => HasValidRay && _hit.HasHit;
        public EyeGazeHit Hit => HasValidRay ? _hit : default;
        public Vector3 EndPoint => !HasValidRay ? Vector3.zero : HasHit ? _hit.Point :
            source.WorldRay.GetPoint(MaxDistance);

        private void Awake()
        {
            if (source == null)
                source = GetComponent<PicoEyeGazeSource>();
            if (ignoredRoot == null)
                ignoredRoot = transform;
        }

        private void LateUpdate()
        {
            ClearResult();
            if (source == null || !source.HasValidSample)
                return;
            _hit = Cast(source.WorldRay, source.GazeCamera);
            _resultFrame = Time.frameCount;
            hitKind = _hit.Kind;
            hitPoint = _hit.HasHit ? _hit.Point : Vector3.zero;
            hitTarget = _hit.Target;
            hitDistance = _hit.HasHit ? _hit.Distance : 0f;
        }

        /// <summary>Calculate the nearest visible surface without sending pointer or click events.</summary>
        public EyeGazeHit Cast(Ray ray, Camera eventCamera)
        {
            var nearest = new EyeGazeHit { Distance = MaxDistance };
            if (!EyeGazeMath.IsFinite(ray.origin) || !EyeGazeMath.IsFinite(ray.direction) ||
                ray.direction.sqrMagnitude < 0.000001f)
                return nearest;
            ray.direction = ray.direction.normalized;
            int count = Physics.RaycastNonAlloc(ray, _physicsHits, MaxDistance, hitLayers,
                QueryTriggerInteraction.Ignore);
            RaycastHit[] hits = _physicsHits;
            // A full non-alloc buffer is not guaranteed to contain the closest hit.
            if (count == _physicsHits.Length)
            {
                hits = Physics.RaycastAll(ray, MaxDistance, hitLayers, QueryTriggerInteraction.Ignore);
                count = hits.Length;
            }
            for (int i = 0; i < count; i++)
            {
                RaycastHit hit = hits[i];
                if (IsIgnored(hit.transform) || hit.distance > nearest.Distance)
                    continue;
                nearest = new EyeGazeHit
                {
                    Kind = EyeGazeHitKind.Collider, Point = hit.point, Normal = hit.normal,
                    Distance = hit.distance, Target = hit.collider.gameObject
                };
            }
            if (hitWorldSpaceUI && eventCamera != null)
                FindWorldUIHit(ray, eventCamera, ref nearest);
            return nearest;
        }

        private void FindWorldUIHit(Ray ray, Camera eventCamera, ref EyeGazeHit nearest)
        {
            int nearestDepth = -1;
            var raycasters = RaycasterManager.GetRaycasters();
            for (int i = 0; i < raycasters.Count; i++)
            {
                var raycaster = raycasters[i];
                if (raycaster == null || !raycaster.isActiveAndEnabled ||
                    !raycaster.TryGetComponent(out Canvas canvas) ||
                    !canvas.isActiveAndEnabled || canvas.renderMode != RenderMode.WorldSpace)
                    continue;
                var graphics = GraphicRegistry.GetRaycastableGraphicsForCanvas(canvas);
                for (int j = 0; j < graphics.Count; j++)
                {
                    Graphic graphic = graphics[j];
                    if (graphic == null || !graphic.isActiveAndEnabled || !graphic.raycastTarget ||
                        graphic.canvasRenderer.cull || graphic.depth < 0 || IsIgnored(graphic.transform) ||
                        (hitLayers.value & (1 << graphic.gameObject.layer)) == 0)
                        continue;
                    Transform surface = graphic.rectTransform;
                    Vector3 forward = surface.forward;
                    float denominator = Vector3.Dot(forward, ray.direction);
                    // World-space uGUI faces the ray when its forward vector points along the ray.
                    if (denominator <= 0.000001f)
                        continue;
                    float distance = Vector3.Dot(surface.position - ray.origin, forward) / denominator;
                    if (distance < 0f || distance > nearest.Distance)
                        continue;
                    Vector3 point = ray.GetPoint(distance);
                    Vector3 screenPoint = eventCamera.WorldToScreenPoint(point);
                    if (screenPoint.z <= 0f ||
                        !RectTransformUtility.RectangleContainsScreenPoint(graphic.rectTransform,
                            screenPoint, eventCamera, graphic.raycastPadding) ||
                        !graphic.Raycast(screenPoint, eventCamera))
                        continue;
                    if (nearest.Kind == EyeGazeHitKind.WorldSpaceUI &&
                        Mathf.Abs(distance - nearest.Distance) < 0.00001f && graphic.depth <= nearestDepth)
                        continue;
                    nearestDepth = graphic.depth;
                    nearest = new EyeGazeHit
                    {
                        Kind = EyeGazeHitKind.WorldSpaceUI, Point = point, Normal = -forward,
                        Distance = distance, Target = graphic.gameObject
                    };
                }
            }
        }

        private bool IsIgnored(Transform target)
        {
            return ignoredRoot != null && (target == ignoredRoot || target.IsChildOf(ignoredRoot));
        }

        private void OnDisable() => ClearResult();

        private void ClearResult()
        {
            _resultFrame = -1;
            _hit = default;
            hitKind = EyeGazeHitKind.None;
            hitPoint = Vector3.zero;
            hitTarget = null;
            hitDistance = 0f;
        }
    }
}
