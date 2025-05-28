using System;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.XR.Interaction.Toolkit.Inputs.Readers;

public class HandDotColorTween : MonoBehaviour
{
    [SerializeField] private InputAction pinch;
    [SerializeField] private InputAction pinchStrength;

    [Range(0, 1)] public float pressSize = 0.5f;
    public float clickAnimationMidpoint = 0.3f;
    public float clickAnimationDuration = 0.1f;

    [SerializeField] private Color _pressColor = Color.black;

    [SerializeField] private Color _clickColor = Color.black;

    [SerializeField] private Color _cursorPressColor = Color.black;

    [SerializeField] private Color _cursorClickColor = Color.black;

    [SerializeField] private float _cursorMinClick = 0.00f;

    [SerializeField] private float _cursorMinPress = 0.7f;

    private Renderer _dotRender;

    private void Awake()
    {
        if (_dotRender == null)
        {
            _dotRender = gameObject.GetComponent<Renderer>();
        }
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

    private void Update()
    {
        if (pinch.IsPressed())
        {
            UpdatePressStateColor();
        }
        else
        {
            UpdateNormalColor(pinchStrength.ReadValue<float>());
        }
    }

    public void UpdatePressStateColor()
    {
        _dotRender.material.SetFloat("_ClickStrength", clickAnimation(clickAnimationMidpoint));
        _dotRender.material.SetColor("_OutColor", _clickColor);
        _dotRender.material.SetColor("_InnerColor", _cursorClickColor);
        _dotRender.material.SetFloat("_MinClose", _cursorMinClick);
    }

    float mappedClickStrength = 0f;

    public void UpdateNormalColor(float clickStrength)
    {
        clicked = false;
        clickStrength = 1 - clickStrength;
        mappedClickStrength =
            (1f - Mathf.Pow(clickStrength, 2)) * pressSize /*(1 - Mathf.Pow(strenght, 2)) * pressSize*/;
        _dotRender.material.SetFloat("_ClickStrength", mappedClickStrength);
        _dotRender.material.SetColor("_OutColor", _pressColor);
        _dotRender.material.SetColor("_InnerColor", _cursorPressColor);
        _dotRender.material.SetFloat("_MinClose", _cursorMinPress);
    }


    bool clicked;
    float clickTime;
    float cursorScale;

    private float clickAnimation(float midPoint)
    {
        if (!clicked)
        {
            clickTime += Time.deltaTime;
            cursorScale = Mathf.Min(clickTime / clickAnimationDuration, 1);
            if (cursorScale < midPoint)
            {
                cursorScale = cursorScale / midPoint;
            }
            else
            {
                cursorScale = 1 - (cursorScale - midPoint) / (1 - midPoint);
            }

            cursorScale = pressSize + (1 - pressSize) * cursorScale;
            if (clickTime >= clickAnimationDuration)
            {
                clickTime = 0;
                clicked = true;
            }
        }

        if (cursorScale < 0.872f)
            cursorScale = 0.872f;
        return cursorScale;
    }
}