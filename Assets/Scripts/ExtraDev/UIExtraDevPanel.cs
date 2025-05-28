using System;
using Robot;
using Unity.XR.PXR;
using UnityEngine;
using UnityEngine.UI;

public class UIExtraDevPanel : MonoBehaviour
{
    public Text Num;
    public ExtraDevItem TmpItem;
    public Toggle OpenTransform;
    public GameObject ExtDevTracking;
    public Button CloseBtn;

    private void Awake()
    {
        bool tracking = PlayerPrefs.GetInt("OnOpenTransform", 0) == 1;
        ExtDevTracking.SetActive(tracking);
        OpenTransform.onValueChanged.AddListener(OnOpenTransform);
        CloseBtn.onClick.AddListener(OnCloseBtn);
    }

    private void OnCloseBtn()
    {
        gameObject.SetActive(false);
    }

    private void OnOpenTransform(bool on)
    {
        PlayerPrefs.SetInt("OnOpenTransform", on ? 1 : 0);
        ExtDevTracking.SetActive(on);
    }

    private void OnEnable()
    {
        TmpItem.gameObject.SetActive(false);
#if UNITY_EDITOR
        Test();
       return;
#endif
        ExtDevTrackerConnectState connectState = new ExtDevTrackerConnectState();
        PXR_MotionTracking.GetExtDevTrackerConnectState(ref connectState);
        Debug.Log("connectState.extNumber:" + connectState.extNumber);
        RefreshUI(connectState);
    }

    [ContextMenu("Test")]
    public void Test()
    {
        ExtDevTrackerConnectState state = new ExtDevTrackerConnectState();
        state.extNumber = 3;
        state.info = new ExtDevTrackerInfo[3];
        state.info[0] = new ExtDevTrackerInfo();
        state.info[0].trackerSN.value = "PA8E10MGH3229396D";
        state.info[0].chargerStatus = 0;
        state.info[0].batteryVolume = 1;

        state.info[1].trackerSN.value = "PA8E10MGH32293962";
        state.info[1].chargerStatus = 2;
        state.info[1].batteryVolume = 3;

        state.info[2].trackerSN.value = "PA8E10MGH32293961";
        state.info[2].chargerStatus = 4;
        state.info[2].batteryVolume = 5;
        RefreshUI(state);
    }


    private void RefreshUI(ExtDevTrackerConnectState connectState)
    {
        Num.text = "extNumber:" + connectState.extNumber.ToString();

        Transform parent = TmpItem.transform.parent;
        for (int i = 0; i < connectState.extNumber && i < connectState.info.Length; i++)
        {
            ExtDevTrackerInfo info = connectState.info[i];
            ExtraDevItem item;
            if (i < parent.childCount)
            {
                item = parent.GetChild(i).GetComponent<ExtraDevItem>();
            }
            else
            {
                item = GameObject.Instantiate(TmpItem, parent);
            }

            item.SN.text = info.trackerSN.value;
            Debug.Log("item.SN:" + info.trackerSN.value);
            item.ChargerStatus.text = info.chargerStatus.ToString();
            item.BatteryVolume.text = info.batteryVolume.ToString();
            item.gameObject.SetActive(true);
        }

        for (int i = connectState.info.Length; i < parent.childCount; i++)
        {
            parent.GetChild(i).gameObject.SetActive(false);
        }
    }
}