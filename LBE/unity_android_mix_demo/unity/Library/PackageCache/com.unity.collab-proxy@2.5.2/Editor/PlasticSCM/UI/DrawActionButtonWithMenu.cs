using System;

using UnityEditor;
using UnityEngine;

namespace Unity.PlasticSCM.Editor.UI
{
    internal static class DrawActionButtonWithMenu
    {
        internal static void For(string buttonText, Action buttonAction, GenericMenu actionMenu)
        {
            // Action button
            GUIContent buttonContent = new GUIContent(buttonText);

            GUIStyle buttonStyle = new GUIStyle(EditorStyles.miniButtonLeft);
            buttonStyle.stretchWidth = false;

            float width = MeasureMaxWidth.ForTexts(buttonStyle, buttonText);

            Rect rt = GUILayoutUtility.GetRect(
                buttonContent,
                buttonStyle,
                GUILayout.MinWidth(width),
                GUILayout.MaxWidth(width));

            if (GUI.Button(rt, buttonContent, buttonStyle))
            {
                buttonAction();
            }

            // Menu dropdown
            GUIStyle dropDownStyle = new GUIStyle(EditorStyles.miniButtonRight);

            GUIContent dropDownContent = new GUIContent(string.Empty, Images.GetDropDownIcon());

            Rect dropDownRect = GUILayoutUtility.GetRect(
                dropDownContent,
                dropDownStyle,
                GUILayout.MinWidth(DROPDOWN_BUTTON_WIDTH),
                GUILayout.MaxWidth(DROPDOWN_BUTTON_WIDTH));

            if (EditorGUI.DropdownButton(dropDownRect, dropDownContent, FocusType.Passive, dropDownStyle))
            {
                actionMenu.DropDown(dropDownRect);
            }
        }

        const int DROPDOWN_BUTTON_WIDTH = 16;
    }
}
