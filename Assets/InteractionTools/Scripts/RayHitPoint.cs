using UnityEngine;


namespace com.picoxr.tobframwork
{
    /// -------------------------------
    /// Des: RayHitPoint Display white dots for ray and UI collision points
    /// Author：wangchuang.1113@bytedance.com
    /// Date：2024-1-23
    /// -------------------------------
    [RequireComponent(typeof(UnityEngine.XR.Interaction.Toolkit.Interactors.XRRayInteractor))]
    public class RayHitPoint : MonoBehaviour
    {
        public Transform UIPoint;
        public bool HideRayline = false;
        public bool FixPosition = false;
        protected UnityEngine.XR.Interaction.Toolkit.Interactors.XRRayInteractor _rayInteractor;
        protected LineRenderer _lineRender;

        private bool _hide = false;
        public LayerMask OverlayLayerMask;

        protected virtual void Awake()
        {
            _lineRender = GetComponent<LineRenderer>();
            _rayInteractor = GetComponent<UnityEngine.XR.Interaction.Toolkit.Interactors.XRRayInteractor>();
        }

        public bool Hide
        {
            get { return _hide; }
            set
            {
                if (_hide != value)
                {
                    _hide = value;
                    SetHide(_hide);
                }
            }
        }

        protected virtual void SetHide(bool value)
        {
            if (UIPoint != null)
            {
                UIPoint.gameObject.SetActive(!value);
            }

            _lineRender.enabled = !HideRayline && !value;
            enabled = !value;
        }

        // Update is called once per frame
        protected virtual void Update()
        {
            if (!FixPosition)
            {
                UpdatePoint();
            }
        }

        private void UpdatePoint()
        {
            _rayInteractor.GetLineOriginAndDirection(out var origin, out var direction);
            var ray = new Ray(origin, direction);
            Vector3 endPoint = origin + direction * _rayInteractor.maxRaycastDistance;
            Vector3 hitNormal = Vector3.forward;
            bool pointActive = false;

            if (_rayInteractor.TryGetCurrentUIRaycastResult(out var raycast) &&
                raycast.module is RenderTargetGraphicRaycaster)
            {
                if (Physics.Raycast(ray, out var hit, _rayInteractor.maxRaycastDistance, OverlayLayerMask))
                {
                    hitNormal = hit.normal;
                    endPoint = hit.point;
                    pointActive = true;
                }
            }
            else if (_rayInteractor.TryGetHitInfo(out var hitPoint, out var normal, out var positionInLine,
                         out var isValidTarget) && isValidTarget)
            {
                endPoint = hitPoint;
                hitNormal = normal;
                pointActive = true;
            }

            if (UIPoint != null)
            {
                if (UIPoint.gameObject.activeSelf != pointActive)
                {
                    UIPoint.gameObject.SetActive(pointActive);
                }

                if (pointActive)
                {
                    UIPoint.position = endPoint;
                    if (hitNormal != Vector3.zero)
                    {
                        UIPoint.forward = -hitNormal;
                    }
                }
            }

            _lineRender.enabled = !HideRayline && !_hide;
            if (_lineRender.enabled)
            {
                _lineRender.positionCount = 2;
                _lineRender.SetPosition(0, origin);
                _lineRender.SetPosition(1, endPoint);
            }
        }
    }
}