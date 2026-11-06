using UnityEngine;
using UnityEngine.Rendering;

namespace Robot
{
    [DisallowMultipleComponent]
    [RequireComponent(typeof(EyeGazeRaycaster))]
    [DefaultExecutionOrder(300)]
    public sealed class EyeGazeVisualizer : MonoBehaviour
    {
        [SerializeField] private EyeGazeRaycaster gazeRaycaster;
        [SerializeField] private bool showDirection = true;
        [SerializeField] private bool showHitPoint = true;
        [SerializeField, Min(0.0001f)] private float lineWidth = 0.002f;
        [SerializeField, Min(0.001f)] private float pointDiameter = 0.016f;
        [SerializeField, Min(0f)] private float surfaceOffset = 0.002f;
        [Tooltip("Skip the part of the ray too close to the eyes to render in VR.")]
        [SerializeField, Min(0f)] private float lineStartDistance = 0.08f;
        [SerializeField] private Color gazeColor = new Color(0.1f, 1f, 0.8f, 0.9f);
        [SerializeField] private Color simulationColor = new Color(1f, 0.65f, 0.1f, 0.9f);

        private GameObject _visualRoot;
        private LineRenderer _line;
        private Transform _point;
        private MeshRenderer _pointRenderer;
        private Material _material;
        private Mesh _pointMesh;

        private void Awake()
        {
            if (gazeRaycaster == null)
                gazeRaycaster = GetComponent<EyeGazeRaycaster>();
            Shader shader = Resources.Load<Shader>("EyeGazeUnlit");
            if (shader == null)
            {
                Debug.LogError("[EyeGaze] Missing Resources/EyeGazeUnlit.shader.", this);
                enabled = false;
                return;
            }
            _material = new Material(shader) { name = "Eye Gaze Visualization" };
            // Keep world sizes independent of the rig scale. No colliders or UI raycast targets.
            _visualRoot = new GameObject("Eye Gaze Visualization") { layer = 2 };
            var lineObject = new GameObject("Gaze Direction") { layer = 2 };
            lineObject.transform.SetParent(_visualRoot.transform, false);
            _line = lineObject.AddComponent<LineRenderer>();
            _line.sharedMaterial = _material;
            _line.useWorldSpace = true;
            _line.positionCount = 2;
            _line.numCapVertices = 4;
            _line.shadowCastingMode = ShadowCastingMode.Off;
            _line.receiveShadows = false;
            var pointObject = new GameObject("Gaze Landing Point") { layer = 2 };
            _point = pointObject.transform;
            _point.SetParent(_visualRoot.transform, false);
            _pointMesh = CreatePointMesh();
            pointObject.AddComponent<MeshFilter>().sharedMesh = _pointMesh;
            _pointRenderer = pointObject.AddComponent<MeshRenderer>();
            _pointRenderer.sharedMaterial = _material;
            _pointRenderer.shadowCastingMode = ShadowCastingMode.Off;
            _pointRenderer.receiveShadows = false;
            Hide();
        }

        private void LateUpdate()
        {
            if (_line == null || gazeRaycaster == null || !gazeRaycaster.HasValidRay)
            {
                Hide();
                return;
            }
            _visualRoot.SetActive(true);
            Color color = gazeRaycaster.Source.IsSimulated ? simulationColor : gazeColor;
            _material.SetColor("_Color", color);
            Ray ray = gazeRaycaster.Source.WorldRay;
            float endDistance = gazeRaycaster.HasHit ? gazeRaycaster.Hit.Distance : gazeRaycaster.MaxDistance;
            _line.enabled = showDirection && endDistance > lineStartDistance;
            _line.startWidth = _line.endWidth = Mathf.Max(0.0001f, lineWidth);
            _line.SetPosition(0, ray.GetPoint(Mathf.Min(lineStartDistance, endDistance)));
            _line.SetPosition(1, gazeRaycaster.EndPoint);
            _pointRenderer.enabled = showHitPoint && gazeRaycaster.HasHit;
            if (_pointRenderer.enabled)
            {
                EyeGazeHit hit = gazeRaycaster.Hit;
                _point.position = hit.Point + hit.Normal * Mathf.Max(0f, surfaceOffset);
                _point.rotation = Quaternion.LookRotation(hit.Normal);
                _point.localScale = Vector3.one * Mathf.Max(0.001f, pointDiameter);
            }
        }

        private static Mesh CreatePointMesh()
        {
            const int segments = 24;
            var vertices = new Vector3[segments + 1];
            var triangles = new int[segments * 3];
            var colors = new Color[segments + 1];
            colors[0] = Color.white;
            for (int i = 0; i < segments; i++)
            {
                float angle = i * Mathf.PI * 2f / segments;
                vertices[i + 1] = new Vector3(Mathf.Cos(angle), Mathf.Sin(angle), 0f) * 0.5f;
                colors[i + 1] = Color.white;
                triangles[i * 3] = 0;
                triangles[i * 3 + 1] = i + 1;
                triangles[i * 3 + 2] = (i + 1) % segments + 1;
            }
            var mesh = new Mesh { name = "Eye Gaze Point" };
            mesh.vertices = vertices;
            mesh.triangles = triangles;
            mesh.colors = colors;
            mesh.RecalculateBounds();
            return mesh;
        }

        private void Hide()
        {
            if (_line != null)
                _line.enabled = false;
            if (_pointRenderer != null)
                _pointRenderer.enabled = false;
        }

        private void OnDisable() => Hide();

        private void OnApplicationPause(bool paused)
        {
            if (paused)
                Hide();
        }

        private void OnApplicationFocus(bool focused)
        {
#if !UNITY_EDITOR
            if (!focused)
                Hide();
#endif
        }

        private void OnDestroy()
        {
            if (_visualRoot != null)
                Destroy(_visualRoot);
            if (_material != null)
                Destroy(_material);
            if (_pointMesh != null)
                Destroy(_pointMesh);
        }
    }
}
