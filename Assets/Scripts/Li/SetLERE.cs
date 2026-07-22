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
    private float heightCompressionFactor = 1.333333f; // 4:3 aspect ratio
    private bool projectionSuspended;
    private bool canvasStateCaptured;
    private bool canvLEWasActive;
    private bool canvREWasActive;

    public bool ProjectionSuspended => projectionSuspended;

    public void UpdateParameters(float visible, float content, float heightCompression)
    {
        // Adjust the ratios based on the height compression factor
        visibleRatio = visible;
        contentRatio = content;
        heightCompressionFactor = heightCompression;

        // Log the updated values
        Debug.Log($"Updated Ratios - visible: {visibleRatio}, content: {contentRatio}, heightCompression: {heightCompressionFactor}");
    }
    
    public void ResetCanvases()
    {
        CanvLE.SetActive(false);
        CanvRE.SetActive(false);
    }

    public void SetProjectionSuspended(bool suspended)
    {
        if (suspended == projectionSuspended)
        {
            return;
        }

        if (suspended)
        {
            canvLEWasActive = CanvLE != null && CanvLE.activeSelf;
            canvREWasActive = CanvRE != null && CanvRE.activeSelf;
            canvasStateCaptured = true;
            projectionSuspended = true;
            if (CanvLE != null)
            {
                CanvLE.SetActive(false);
            }
            if (CanvRE != null)
            {
                CanvRE.SetActive(false);
            }
            return;
        }

        projectionSuspended = false;
        if (canvasStateCaptured)
        {
            if (CanvLE != null)
            {
                CanvLE.SetActive(canvLEWasActive);
            }
            if (CanvRE != null)
            {
                CanvRE.SetActive(canvREWasActive);
            }
        }
        canvasStateCaptured = false;
    }

    void Update()
    {
        if (projectionSuspended)
        {
            // Keep the legacy eye canvases off for the complete panoramic
            // lifecycle. ResetCanvases() and another component may run in a
            // different frame, so this invariant is enforced continuously.
            if (CanvLE != null && CanvLE.activeSelf)
            {
                CanvLE.SetActive(false);
            }
            if (CanvRE != null && CanvRE.activeSelf)
            {
                CanvRE.SetActive(false);
            }
            return;
        }

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
            matLE.SetFloat("_heightCompressionFactor", heightCompressionFactor);
            matRE.SetFloat("_heightCompressionFactor", heightCompressionFactor);
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
