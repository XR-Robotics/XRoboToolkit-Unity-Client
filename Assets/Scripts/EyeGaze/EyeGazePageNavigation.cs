using UnityEngine;
using UnityEngine.UI;

namespace Robot
{
    [DisallowMultipleComponent]
    public sealed class EyeGazePageNavigation : MonoBehaviour
    {
        [SerializeField] private CanvasGroup mainPage;
        [SerializeField] private GameObject resultsPage;
        [SerializeField] private Button openButton;
        [SerializeField] private Button backButton;

        private void OnEnable()
        {
            if (mainPage == null || resultsPage == null || openButton == null || backButton == null)
            {
                Debug.LogWarning("[EyeGaze] Assign both pages and their navigation buttons.", this);
                return;
            }
            openButton.onClick.AddListener(ShowResults);
            backButton.onClick.AddListener(ShowMain);
            ShowMain();
        }

        public void ShowResults()
        {
            if (mainPage == null || resultsPage == null)
                return;
            // Keep the main page's components alive while hiding its graphics and input.
            mainPage.alpha = 0f;
            mainPage.interactable = false;
            mainPage.blocksRaycasts = false;
            resultsPage.SetActive(true);
        }

        public void ShowMain()
        {
            if (resultsPage != null)
                resultsPage.SetActive(false);
            if (mainPage == null)
                return;
            mainPage.alpha = 1f;
            mainPage.interactable = true;
            mainPage.blocksRaycasts = true;
        }

        private void OnDisable()
        {
            if (openButton != null)
                openButton.onClick.RemoveListener(ShowResults);
            if (backButton != null)
                backButton.onClick.RemoveListener(ShowMain);
            ShowMain();
        }
    }
}
