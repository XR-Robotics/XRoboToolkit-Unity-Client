using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class LogView : MonoBehaviour
{
    public const int LogCacheCount = 20;
    public Text itemTmp;

    private static Queue<LogData> _waitings = new Queue<LogData>();
    private static LogView _instance;

    private RectTransform _root;
    private ScrollRect _scrollRect;

    private void Awake()
    {
        itemTmp.gameObject.SetActive(false);
        _root = (RectTransform)itemTmp.transform.parent;
        _scrollRect = itemTmp.GetComponentInParent<ScrollRect>();
    }

    public static void Push(string condition, string stackTrace, LogType type)
    {
        LogData data = new LogData();
        data.Condition = condition;
        data.StackTrace = stackTrace;
        data.LogType = type;
        _waitings.Enqueue(data);
    }


    private bool _change = false;

    private void Update()
    {
        if (_change)
        {
            _scrollRect.verticalNormalizedPosition = 0;
            _change = false;
        }

        while (_waitings.Count > 0)
        {
            LogData data = _waitings.Dequeue();

            Text item;
            if (_root.childCount > LogCacheCount)
            {
                item = _root.GetChild(0).GetComponent<Text>();
                item.transform.SetSiblingIndex(_root.childCount - 1);
            }
            else
            {
                item = Instantiate(itemTmp, _root);
            }

            item.gameObject.SetActive(true);

            if (data.LogType == LogType.Error || data.LogType == LogType.Exception)
            {
                item.color = Color.red;
            }
            else if (data.LogType == LogType.Warning || data.LogType == LogType.Assert)
            {
                item.color = Color.yellow;
            }
            else
            {
                item.color = Color.white;
            }

            item.text = data.Condition;
            _change = true;
        }
    }

    struct LogData
    {
        public string Condition;
        public string StackTrace;
        public LogType LogType;
    }
}