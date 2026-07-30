using Robot;
using UnityEngine;
using UnityEngine.UI;

public class EnterpriseSampleRateUI : MonoBehaviour
{
    public CustomButton IncreaseButton;
    public CustomButton DecreaseButton;
    public Text SampleHzText;

    [Min(0)]
    public int Step = 50;

    private void Awake()
    {
        if (IncreaseButton != null)
        {
            IncreaseButton.OnChange += OnIncreaseButton;
        }

        if (DecreaseButton != null)
        {
            DecreaseButton.OnChange += OnDecreaseButton;
        }

        RefreshButtonText();
        RefreshText();
    }

    private void OnValidate()
    {
        Step = Mathf.Max(0, Step);
        RefreshButtonText();
    }

    private void OnDestroy()
    {
        if (IncreaseButton != null)
        {
            IncreaseButton.OnChange -= OnIncreaseButton;
        }

        if (DecreaseButton != null)
        {
            DecreaseButton.OnChange -= OnDecreaseButton;
        }
    }

    private void Update()
    {
        RefreshButtonText();
        RefreshText();
    }

    public void IncreaseSampleHz()
    {
        AdjustSampleHz(Step);
    }

    public void DecreaseSampleHz()
    {
        AdjustSampleHz(-Step);
    }

    private void OnIncreaseButton(bool _)
    {
        IncreaseSampleHz();
    }

    private void OnDecreaseButton(bool _)
    {
        DecreaseSampleHz();
    }

    public void RefreshText()
    {
        if (SampleHzText == null)
        {
            return;
        }

        EnterpriseCollectionRecorder recorder = FindObjectOfType<EnterpriseCollectionRecorder>();
        SampleHzText.text = recorder != null ? $"Hz: {recorder.EnterpriseSampleHz}" : "0";
    }

    private void RefreshButtonText()
    {
        SetChildText(IncreaseButton, "+" + Step);
        SetChildText(DecreaseButton, "-" + Step);
    }

    private static void SetChildText(CustomButton button, string text)
    {
        if (button == null)
        {
            return;
        }

        Text childText = button.GetComponentInChildren<Text>(true);
        if (childText == null)
        {
            return;
        }

        childText.text = text;
    }

    private void AdjustSampleHz(int delta)
    {
        EnterpriseCollectionRecorder recorder = FindObjectOfType<EnterpriseCollectionRecorder>();
        if (recorder == null)
        {
            RefreshText();
            return;
        }

        recorder.AdjustEnterpriseSampleHz(delta);
        RefreshText();
    }
}
