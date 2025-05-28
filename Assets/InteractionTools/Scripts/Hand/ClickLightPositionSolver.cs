using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

public class ClickLightPositionSolver : MonoBehaviour
{
    [SerializeField] Transform thumb_null;
    [SerializeField] Transform index_null;
    [SerializeField] Transform index_3;
    [SerializeField] Transform index_2;

    [SerializeField] private InputAction pinch;
    [SerializeField] private InputAction pinchStrength;

    Vector3 tpoint0;
    Vector3 tpoint1;
    float t0;
    float t1;
    Vector3 clickPosition;
    Vector4 postionToShader = new Vector4();

    Renderer renderer;

    private void Start()
    {
        renderer = GetComponent<Renderer>();
    }

    private void OnEnable()
    {
        pinch.Enable();
        pinchStrength.Enable();
    }

    private void OnDisable()
    {
        pinch.Disable();
        pinchStrength.Disable();
    }

    void Update()
    {
        t0 = DistancePointLine(thumb_null.position, index_null.position, index_3.position, out tpoint0);
        t1 = DistancePointLine(thumb_null.position, index_3.position, index_2.position, out tpoint1);
        clickPosition = (thumb_null.position + (t0 < t1 ? tpoint0 : tpoint1)) / 2f;
        postionToShader.Set(clickPosition.x, clickPosition.y, clickPosition.z, 1.0f);

        if (pinch.IsPressed())
        {
            renderer.material.SetFloat("_PressIntensity", 1);
        }
        else
        {
            renderer.material.SetFloat("_PressIntensity", pinchStrength.ReadValue<float>());
        }

        renderer.material.SetVector("_ClickPosition", postionToShader);
    }

    /// <summary>
    /// Calculate the shortest distance from a point to a line segment
    /// </summary>
    /// <param name="point"></param>
    /// <param name="lineStart"></param>
    /// <param name="lineEnd"></param>
    /// <returns></returns>
    public static float DistancePointLine(Vector3 point, Vector3 lineStart, Vector3 lineEnd, out Vector3 projectPoint)
    {
        Vector3 rhs = point - lineStart;
        Vector3 vector3 = lineEnd - lineStart;
        float magnitude = vector3.magnitude;
        Vector3 lhs = vector3;
        if ((double)magnitude > 9.99999997475243E-07)
            lhs /= magnitude;
        float num = Mathf.Clamp(Vector3.Dot(lhs, rhs), 0.0f, magnitude);
        //投射点
        projectPoint = lineStart + lhs * num;
        return Vector3.Magnitude(projectPoint - point);
    }
}