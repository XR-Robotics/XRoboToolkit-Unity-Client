using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Toast : MonoBehaviour
{
    public GameObject Panel;
    public Text text;
    private static Queue<string> _message = new Queue<string>();
    private static float _lastTime = 0;

    private static float _hideStartTime = 0;

    private static Toast _instance;

    private void Awake()
    {
        _instance = this;
    }

    public static void Show(string info)
    {
        _message.Enqueue(info);
        if (_instance != null && !_instance.Panel.activeSelf)
        {
            _lastTime = 0;
        }
    }


    public void Update()
    {
        if (Time.time - _lastTime > 1)
        {
            _lastTime = Time.time;
            if (_message.Count > 0)
            {
                if (!Panel.activeSelf)
                    Panel.SetActive(true);
                text.text = _message.Dequeue();
                _hideStartTime = Time.time;
            }
            else
            {
                if (Time.time - _hideStartTime > 5)
                {
                    Panel.SetActive(false);
                }
            }
        }
    }

    [ContextMenu("Test")]
    private void Test()
    {
        Show("Test " + Time.time);
    }
}