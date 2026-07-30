using Robot;
using UnityEngine;
using UnityEngine.UI;

public class TrackingDataSourceCtrl : MonoBehaviour
{
    public enum TrackingDataSource
    {
        UnityXR,
        EnterpriseSDK
    }

    public static TrackingDataSource CurrentSource { get; private set; } = TrackingDataSource.UnityXR;
    public static bool UseEnterpriseSDK => CurrentSource == TrackingDataSource.EnterpriseSDK;

    public Toggle UnityXRToggle;
    public Toggle EnterpriseSDKToggle;
    public GameObject CollectionRate;

    private bool _updatingToggleState;
    private ToggleGroup _toggleGroup;

    private void Awake()
    {
        ResolveReferences();
        SetupToggleGroup();

        if (UnityXRToggle != null)
        {
            UnityXRToggle.onValueChanged.AddListener(OnUnityXRChanged);
        }

        if (EnterpriseSDKToggle != null)
        {
            EnterpriseSDKToggle.onValueChanged.AddListener(OnEnterpriseSDKChanged);
        }
    }

    private void Start()
    {
        TrackingDataSource initialSource = EnterpriseSDKToggle != null && EnterpriseSDKToggle.isOn
            ? TrackingDataSource.EnterpriseSDK
            : TrackingDataSource.UnityXR;
        ApplySource(initialSource);
    }

    private void OnDestroy()
    {
        if (UnityXRToggle != null)
        {
            UnityXRToggle.onValueChanged.RemoveListener(OnUnityXRChanged);
        }

        if (EnterpriseSDKToggle != null)
        {
            EnterpriseSDKToggle.onValueChanged.RemoveListener(OnEnterpriseSDKChanged);
        }
    }

    private void OnUnityXRChanged(bool isOn)
    {
        if (_updatingToggleState)
        {
            return;
        }

        if (isOn)
        {
            ApplySource(TrackingDataSource.UnityXR);
        }
    }

    private void OnEnterpriseSDKChanged(bool isOn)
    {
        if (_updatingToggleState)
        {
            return;
        }

        if (isOn)
        {
            ApplySource(TrackingDataSource.EnterpriseSDK);
        }
    }

    private void ApplySource(TrackingDataSource source)
    {
        CurrentSource = source;
        TcpHandler.EnterpriseDirectTrackingEnabled = UseEnterpriseSDK;

        _updatingToggleState = true;
        if (UnityXRToggle != null)
        {
            UnityXRToggle.SetIsOnWithoutNotify(source == TrackingDataSource.UnityXR);
        }

        if (EnterpriseSDKToggle != null)
        {
            EnterpriseSDKToggle.SetIsOnWithoutNotify(source == TrackingDataSource.EnterpriseSDK);
        }

        _updatingToggleState = false;

        if (CollectionRate != null)
        {
            CollectionRate.SetActive(UseEnterpriseSDK);
        }

        string message = $"Tracking data source selected: {source}";
        LogWindow.Info(message);
        Debug.Log(message);
    }

    private void ResolveReferences()
    {
        if (UnityXRToggle == null)
        {
            UnityXRToggle = FindChildToggle("UnityXR");
        }

        if (EnterpriseSDKToggle == null)
        {
            EnterpriseSDKToggle = FindChildToggle("EnterpriseSDK");
        }

        if (CollectionRate == null && transform.parent != null)
        {
            Transform collectionRate = transform.parent.Find("CollectionRate");
            if (collectionRate != null)
            {
                CollectionRate = collectionRate.gameObject;
            }
        }
    }

    private Toggle FindChildToggle(string childName)
    {
        Transform child = transform.Find(childName);
        return child != null ? child.GetComponent<Toggle>() : null;
    }

    private void SetupToggleGroup()
    {
        _toggleGroup = GetComponent<ToggleGroup>();
        if (_toggleGroup == null)
        {
            _toggleGroup = gameObject.AddComponent<ToggleGroup>();
        }

        _toggleGroup.allowSwitchOff = false;

        if (UnityXRToggle != null)
        {
            UnityXRToggle.group = _toggleGroup;
        }

        if (EnterpriseSDKToggle != null)
        {
            EnterpriseSDKToggle.group = _toggleGroup;
        }
    }
}
