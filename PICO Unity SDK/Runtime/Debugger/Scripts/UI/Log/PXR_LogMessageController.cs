/*******************************************************************************
Copyright © 2015-2022 PICO Technology Co., Ltd.All rights reserved.  

NOTICE：All information contained herein is, and remains the property of 
PICO Technology Co., Ltd. The intellectual and technical concepts 
contained herein are proprietary to PICO Technology Co., Ltd. and may be 
covered by patents, patents in process, and are protected by trade secret or 
copyright law. Dissemination of this information or reproduction of this 
material is strictly forbidden unless prior written permission is obtained from
PICO Technology Co., Ltd. 
*******************************************************************************/
using System.Text;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
#if UNITY_EDITOR || DEVELOPMENT_BUILD
namespace ByteDance.PICO.Debugger
{
    [RequireComponent(typeof(RectTransform))]
    public class PXR_LogMessageController : MonoBehaviour
    {
        // Start is called before the first frame update
        public TextMeshProUGUI title;
        public TextMeshProUGUI content;
        public RectTransform icon;
        private bool isShowAll = false;
        private string fullContent;
        private string firstLineContent;
        private System.Action<PXR_LogMessageController> onDelete;
        public void SetOnDelete(System.Action<PXR_LogMessageController> callback)
        {
            onDelete = callback;
        }
        public void DeleteSelf()
        {
            onDelete?.Invoke(this);
        }
        public void Init(string title, string content)
        {
            // Fix 1: Guard against null/empty logString from Unity internal
            // warnings (e.g. graphics driver, GC notifications) that pass
            // null or empty strings via Application.logMessageReceived.
            if (string.IsNullOrEmpty(title))
            {
                title = "(empty message)";
            }
            if (string.IsNullOrEmpty(content))
            {
                content = "(no stack trace)";
            }

            // Fix 3: Replace control characters (except \n and \t) with
            // spaces to prevent TMP rendering issues.
            title = SanitizeForDisplay(title);
            content = SanitizeForDisplay(content);

            string timestamp = System.DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss");
            string finalTitle = $"{timestamp}: {title}";

            this.title.text = finalTitle;
            fullContent = $"{title}\n{content}";
            firstLineContent = title;
            ApplyContent();
            LayoutRebuild();
        }
        public void ToggleContent()
        {
            isShowAll = !isShowAll;
            icon.eulerAngles = isShowAll? new Vector3(0,0,180):Vector3.zero;
            ApplyContent();
            LayoutRebuild();
        }
        private void ApplyContent()
        {
            // Collapsed: render only the first line so the item is exactly one line tall.
            // Expanded: render the full multi-line content with word wrapping.
#if UNITY_6000_0_OR_NEWER
            content.textWrappingMode = isShowAll ? TextWrappingModes.Normal : TextWrappingModes.NoWrap;
#else
            content.enableWordWrapping = isShowAll;
#endif
            content.text = isShowAll ? fullContent : firstLineContent;
        }
        private void LayoutRebuild()
        {
            LayoutRebuilder.ForceRebuildLayoutImmediate(GetComponent<RectTransform>());
            LayoutRebuilder.ForceRebuildLayoutImmediate(transform.parent.GetComponent<RectTransform>());
        }

        // Fix 2: Ensure TMP font assets have fallback fonts configured so
        // that characters not in the primary atlas (e.g. en-dash, smart
        // quotes, Unicode arrows from .NET/Unity stack traces) can be
        // rendered instead of showing as square boxes (tofu).
        private static bool _fallbackFontsChecked;
        private void EnsureFallbackFonts()
        {
            if (_fallbackFontsChecked) return;
            _fallbackFontsChecked = true;

            var fontsToCheck = new[] { title != null ? title.font : null, content != null ? content.font : null };
            foreach (var font in fontsToCheck)
            {
                if (font == null) continue;
                if (font.fallbackFontAssetTable == null)
                {
                    font.fallbackFontAssetTable = new System.Collections.Generic.List<TMP_FontAsset>();
                }
                if (font.fallbackFontAssetTable.Count > 0) continue;

                // Attempt to load a fallback font from Resources. Place a
                // TMP_FontAsset named "PXR_FallbackFont" in a Resources
                // folder to provide extended glyph coverage.
                var fallback = Resources.Load<TMP_FontAsset>("PXR_FallbackFont");
                if (fallback != null)
                {
                    font.fallbackFontAssetTable.Add(fallback);
                }
            }
        }

        // Fix 3: Replace control characters (except newline and tab) with
        // spaces. Some Unity internal warnings and .NET stack traces may
        // contain control characters that TextMeshPro cannot render.
        private static string SanitizeForDisplay(string text)
        {
            if (string.IsNullOrEmpty(text)) return text;

            bool needsSanitizing = false;
            foreach (char c in text)
            {
                if (c != '\n' && c != '\t' && char.IsControl(c))
                {
                    needsSanitizing = true;
                    break;
                }
            }
            if (!needsSanitizing) return text;

            var sb = new StringBuilder(text.Length);
            foreach (char c in text)
            {
                if (c == '\n' || c == '\t' || !char.IsControl(c))
                    sb.Append(c);
                else
                    sb.Append(' ');
            }
            return sb.ToString();
        }

        void Awake()
        {
            EnsureFallbackFonts();
        }
    }
}
#endif