using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SetLERE : MonoBehaviour
{

    public GameObject CanvLE;
    public GameObject CanvRE;
    public RemoteCameraWindow remoteCameraWindow;
    public Material matLE;

    public Material matRE;

    //private float visibleRatio = 0.75f;
    //private float contentRatio = 0.88f;
    private float visibleRatio = 0.555f;
    private float contentRatio = 1.8f;

    public void ResetRatios()
    {
        visibleRatio = 0.555f;
        contentRatio = 1.8f;
        Debug.Log($"Reset - visibleRatio: {visibleRatio} - contentRatio: {contentRatio}");
    }

    public void UpdateRatios(float visible, float content)
    {
        visibleRatio = visible;
        contentRatio = content;
        Debug.Log($"Updated - visibleRatio: {visibleRatio} - contentRatio: {contentRatio}");
    }
    
    public void ResetCanvases()
    {
        CanvLE.SetActive(false);
        CanvRE.SetActive(false);
    }

    void Update()
    {
        if ((!CanvLE.activeSelf) || (!CanvRE.activeSelf))
        {
            CanvLE.SetActive(true);
            CanvRE.SetActive(true);

            matLE.SetTexture("_mainRT", remoteCameraWindow.Texture);
            matRE.SetTexture("_mainRT", remoteCameraWindow.Texture);

            matLE.SetInt("_isLE", 1);
            matRE.SetInt("_isLE", 0);

            matLE.SetFloat("_visibleRatio", visibleRatio);
            matRE.SetFloat("_visibleRatio", visibleRatio);
            matLE.SetFloat("_contentRatio", contentRatio);
            matRE.SetFloat("_contentRatio", contentRatio);
        }

        if (Input.GetKeyDown(KeyCode.Q))
        {
            visibleRatio += 0.005f;
            matLE.SetFloat("_visibleRatio", visibleRatio);
            matRE.SetFloat("_visibleRatio", visibleRatio);
            Debug.Log($"visibleRatio: {visibleRatio} - contentRatio: {contentRatio}");
        }

        if (Input.GetKeyDown(KeyCode.E))
        {
            visibleRatio -= 0.005f;
            matLE.SetFloat("_visibleRatio", visibleRatio);
            matRE.SetFloat("_visibleRatio", visibleRatio);
            Debug.Log($"visibleRatio: {visibleRatio} - contentRatio: {contentRatio}");
        }

        if (Input.GetKeyDown(KeyCode.A))
        {
            contentRatio += 0.005f;
            matLE.SetFloat("_contentRatio", contentRatio);
            matRE.SetFloat("_contentRatio", contentRatio);
            Debug.Log($"visibleRatio: {visibleRatio} - contentRatio: {contentRatio}");
        }

        if (Input.GetKeyDown(KeyCode.D))
        {
            contentRatio -= 0.005f;
            matLE.SetFloat("_contentRatio", contentRatio);
            matRE.SetFloat("_contentRatio", contentRatio);
            Debug.Log($"visibleRatio: {visibleRatio} - contentRatio: {contentRatio}");
        }
    }
}
