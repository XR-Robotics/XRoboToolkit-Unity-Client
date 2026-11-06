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
    [SerializeField] private string _idleLabel;
    [SerializeField] private string _activeLabel;

    public bool On { get; private set; }

    private void Awake()
    {
        _image = GetComponent<Image>();
        _defaultColor = _image.color;
        RefreshLabel();
    }

    public void SetOn(bool value)
    {
        On = value;
        _image.color = On ? selectedColor : _defaultColor;
        RefreshLabel();
    }

    private void RefreshLabel()
    {
        if (string.IsNullOrEmpty(_idleLabel) || string.IsNullOrEmpty(_activeLabel)) return;
        Text label = GetComponentInChildren<Text>(true);
        if (label != null) label.text = On ? _activeLabel : _idleLabel;
    }

    public void OnPointerClick(PointerEventData eventData)
    {
        if (OnChange != null)
        {
            OnChange.Invoke(!On);
        }
    }
}
