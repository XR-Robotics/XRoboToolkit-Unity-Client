using System;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

[RequireComponent(typeof(Image))]
public class CustomButton : MonoBehaviour, IPointerClickHandler
{
    public event Action<bool> OnChange;

    public Color selectedColor;

    private Color _defaultColor;

    private Image _image;

    public bool On { get; private set; }

    private void Awake()
    {
        _image = GetComponent<Image>();
        _defaultColor = _image.color;
    }

    public void SetOn(bool value)
    {
        On = value;
        _image.color = On ? selectedColor : _defaultColor;
    }

    public void SetOnAndNotify(bool value)
    {
        SetOn(value);
        OnChange?.Invoke(value);
    }

    public void OnPointerClick(PointerEventData eventData)
    {
        if (OnChange != null)
        {
            OnChange.Invoke(!On);
        }
    }
}
