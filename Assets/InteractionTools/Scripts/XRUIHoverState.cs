using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit.UI;

public class XRUIHoverState : MonoBehaviour
{
    private IUIHoverInteractor _uiHoverInteractor;

    private GameObject _hoverUI = null;

    private static List<XRUIHoverState> _list = new List<XRUIHoverState>();

    private void Awake()
    {
        _list.Add(this);
        _uiHoverInteractor = GetComponent<IUIHoverInteractor>();
        _uiHoverInteractor.uiHoverEntered.AddListener((eventArgs) => { _hoverUI = eventArgs.uiObject; });
        _uiHoverInteractor.uiHoverExited.AddListener((eventArgs) => { _hoverUI = null; });
    }

    public bool UIHovering
    {
        get { return _hoverUI != null && _hoverUI.activeInHierarchy; }
    }

    public static bool AnyInteractorHoverUI()
    {
        for (int i = 0; i < _list.Count; i++)
        {
            if (_list[i].UIHovering)
            {
                return true;
            }
        }

        return false;
    }
}