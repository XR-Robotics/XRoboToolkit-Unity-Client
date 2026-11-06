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
using UnityEditor;
using UnityEngine;

namespace ByteDance.PICO.XR.Editor
{
    public class PXR_EditorStyles
    {
        public Color colorLine;
        public Color colorSelected;
        public Color colorDocumentationUrlNormal;
        public Color colorDocumentationUrlHover;

        private bool isProSkin;
        private bool isInitialized;

        private GUIStyle _dialogIconStyle;
        private GUIStyle _bigIconStyle;
        private GUIStyle _headerText;
        private GUIStyle _versionText;
        private GUIStyle _contentArea;
        private GUIStyle _contentText;
        private GUIStyle _buttonStyle;
        private GUIStyle _buttonSelectedStyle;
        private GUIStyle _backgroundColorStyle;
        private GUIStyle _bigWhiteTitleStyle;
        private GUIStyle _smallBlueLinkStyle;


        public GUIStyle HeaderText => _headerText ??= new GUIStyle(EditorStyles.largeLabel)
        {
            fontStyle = FontStyle.Bold,
            fontSize = 48,
            alignment = TextAnchor.MiddleCenter,
            fixedHeight = 69,
            fixedWidth = 600,
            normal = new GUIStyleState()
            {
                textColor = TextPrimary
            }
        };

        public GUIStyle BigWhiteTitleStyle => _bigWhiteTitleStyle ??= new GUIStyle(EditorStyles.largeLabel)
        {
            fontStyle = FontStyle.Bold,
            fontSize = 20,
            fixedHeight = 25,
            alignment = TextAnchor.MiddleLeft,
            normal = new GUIStyleState()
            {
                textColor = TextPrimary
            }
        };

        public GUIStyle VersionText => _versionText ??= new GUIStyle(EditorStyles.miniLabel)
        {
            fontStyle = FontStyle.Normal,
            fontSize = 18,
            alignment = TextAnchor.LowerCenter,
            fixedHeight = 69,
            fixedWidth = 200,
            padding = new RectOffset(8, 0, 0, 8),
            normal = new GUIStyleState()
            {
                textColor = TextSecondary
            }
        };

        public GUIStyle ContentText => _contentText ??= new GUIStyle(EditorStyles.wordWrappedLabel)
        {
            richText = true,
            stretchHeight = true,
            fontSize = 16,
            alignment = TextAnchor.MiddleLeft,
            normal = new GUIStyleState()
            {
                textColor = TextPrimary
            }
        };

        public GUIStyle SmallBlueLinkStyle => _smallBlueLinkStyle ??= new GUIStyle(EditorStyles.linkLabel)
        {
            fontStyle = FontStyle.Normal,
            fontSize = 16,
            fixedHeight = 25,
            alignment = TextAnchor.MiddleCenter,
            normal = new GUIStyleState()
            {
                textColor = colorDocumentationUrlNormal
            },
            hover = new GUIStyleState()
            {
                textColor = colorDocumentationUrlHover
            }
        };

        public GUIStyle IconStyle => _dialogIconStyle ??= new GUIStyle()
        {
            fixedHeight = 80,
            fixedWidth = 250,
            padding = new RectOffset(0, 10, 0, 0),
            alignment = TextAnchor.UpperRight,
        };

        public GUIStyle IconBigStyle => _bigIconStyle ??= new GUIStyle()
        {
            fixedHeight = 296,
            fixedWidth = 360,
            alignment = TextAnchor.MiddleCenter,
        };

        public Texture2D MakeTexture(int width, int height, Color color)
        {
            Texture2D texture = new Texture2D(width, height);
            for (int x = 0; x < width; x++)
            {
                for (int y = 0; y < height; y++)
                {
                    texture.SetPixel(x, y, color);
                }
            }
            texture.Apply();
            return texture;
        }

        public GUIStyle Button => _buttonStyle ??= new GUIStyle(EditorStyles.miniButton)
        {
            stretchWidth = true,
            fixedWidth = 180,
            fixedHeight = 40,
            fontStyle = FontStyle.Bold,
            richText = true,
            padding = new RectOffset(4, 4, 4, 4),
            normal = new GUIStyleState()
            {
                textColor = ButtonText,
                background = MakeTexture(2, 2, ButtonBackground)
            },
            onActive = new GUIStyleState()
            {
                textColor = ButtonSelectedText,
                background = MakeTexture(2, 2, colorSelected)
            }
            
        };

        public GUIStyle ButtonSelected => _buttonSelectedStyle ??= new GUIStyle(EditorStyles.miniButton)
        {
            stretchWidth = true,
            fixedWidth = 180,
            fixedHeight = 40,
            fontStyle = FontStyle.Bold,
            richText = true,
            padding = new RectOffset(4, 4, 4, 4),
            normal = new GUIStyleState() {
                textColor = ButtonSelectedText,
                background = MakeTexture(2, 2, colorSelected)
            }
        };

        public GUIStyle BackgroundColor => _backgroundColorStyle ??= new GUIStyle(EditorStyles.wordWrappedLabel)
        {
            padding = new RectOffset(24, 24, 24, 24),
            normal = new GUIStyleState()
            {
                background = MakeTexture(2, 2, PanelBackground)
            }
        };

        public void RefreshTheme()
        {
            var proSkin = EditorGUIUtility.isProSkin;
            if (isInitialized && isProSkin == proSkin)
            {
                return;
            }

            isProSkin = proSkin;
            isInitialized = true;

            colorLine = isProSkin ? new Color32(0x3A, 0x3A, 0x3A, 255) : new Color32(0xD0, 0xD5, 0xDD, 255);
            colorSelected = new Color32(0x2D, 0x7F, 0xF9, 255);
            colorDocumentationUrlNormal = isProSkin ? new Color32(0x7B, 0xB7, 0xFF, 255) : new Color32(0x0F, 0x6F, 0xD5, 255);
            colorDocumentationUrlHover = isProSkin ? new Color32(0x7B, 0xB7, 0xFF, 205) : new Color32(0x0F, 0x6F, 0xD5, 205);

            _dialogIconStyle = null;
            _bigIconStyle = null;
            _headerText = null;
            _versionText = null;
            _contentArea = null;
            _contentText = null;
            _buttonStyle = null;
            _buttonSelectedStyle = null;
            _backgroundColorStyle = null;
            _bigWhiteTitleStyle = null;
            _smallBlueLinkStyle = null;
        }

        private Color TextPrimary => isProSkin ? new Color32(0xE6, 0xE8, 0xEC, 255) : new Color32(0x10, 0x15, 0x1A, 255);
        private Color TextSecondary => isProSkin ? new Color32(0xB6, 0xBE, 0xCA, 255) : new Color32(0x47, 0x55, 0x69, 255);
        private Color PanelBackground => isProSkin ? new Color32(0x1E, 0x21, 0x26, 255) : new Color32(0xF8, 0xFA, 0xFC, 255);
        private Color ButtonBackground => isProSkin ? new Color32(0x2B, 0x2F, 0x35, 255) : new Color32(0xE5, 0xE7, 0xEB, 255);
        private Color ButtonText => isProSkin ? new Color32(0xF5, 0xF7, 0xFA, 255) : new Color32(0x1F, 0x29, 0x37, 255);
        private Color ButtonSelectedText => Color.white;
    }
}
