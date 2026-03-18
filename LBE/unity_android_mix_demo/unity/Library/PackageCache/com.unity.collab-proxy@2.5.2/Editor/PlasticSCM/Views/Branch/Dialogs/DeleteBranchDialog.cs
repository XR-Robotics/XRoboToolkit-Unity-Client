using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Codice.CM.Common;
using PlasticGui;
using Unity.PlasticSCM.Editor.UI;

using UnityEditor;
using UnityEngine;

namespace Unity.PlasticSCM.Editor.Views.Branches.Dialogs
{
    internal class DeleteBranchDialog : PlasticDialog
    {
        protected override Rect DefaultRect
        {
            get
            {
                var baseRect = base.DefaultRect;
                var increaseFactor = mNumberOfBranches <= MAX_ITEMS_TO_SHOW ?
                    TEXT_LINE_HEIGHT * mNumberOfBranches :
                    TEXT_LINE_HEIGHT * (MAX_ITEMS_TO_SHOW + 1);
                return new Rect(baseRect.x, baseRect.y, baseRect.width, baseRect.height + increaseFactor);
            }
        }

        internal static bool ConfirmDelete(IList<BranchInfo> branches)
        {
            DeleteBranchDialog dialog = Create(branches);

            return dialog.RunModal(null) == ResponseType.Ok;
        }

        protected override string GetTitle()
        {
            return mTitle;
        }

        protected override void OnModalGUI()
        {
            Paragraph(mMessage);

            GUILayout.Space(5);

            DoButtonsArea();
        }

        void DoButtonsArea()
        {
            using (new EditorGUILayout.HorizontalScope())
            {
                GUILayout.FlexibleSpace();
                
                mConfirmDelete = ToggleEntry(
                    PlasticLocalization.Name.ConfirmationCheckBox.GetString(),
                    mConfirmDelete);

                GUILayout.Space(10);

                if (Application.platform == RuntimePlatform.WindowsEditor)
                {
                    DoDeleteButton();
                    DoCancelButton();
                    return;
                }

                DoCancelButton();
                DoDeleteButton();
            }
        }

        void DoCancelButton()
        {
            if (!NormalButton(PlasticLocalization.Name.NoButton.GetString()))
                return;

            CancelButtonAction();
        }

        void DoDeleteButton()
        {
            GUI.enabled = mConfirmDelete;

            if (NormalButton(PlasticLocalization.Name.DeleteButton.GetString()))
            {
                OkButtonAction();
            }

            GUI.enabled = true;
        }

        static DeleteBranchDialog Create(IList<BranchInfo> branches)
        {
            var instance = CreateInstance<DeleteBranchDialog>();
            instance.mMessage = BuildDeleteBranchesConfirmationMessage(branches);
            instance.mNumberOfBranches = branches.Count;
            instance.mTitle = PlasticLocalization.Name.ConfirmDeleteTitle.GetString();
            return instance;
        }

        static string BuildDeleteBranchesConfirmationMessage(IList<BranchInfo> branchToDelete)
        {
            string[] itemNames = branchToDelete.Select(x => x.Name).ToArray();

            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.AppendLine(PlasticLocalization.Name.DeleteBranchesExplanation.GetString());
            stringBuilder.AppendLine();
            int num = Math.Min(itemNames.Length, MAX_ITEMS_TO_SHOW);
            for (int i = 0; i < num; i++)
            {
                stringBuilder.AppendLine(" " + (i + 1) + ". " + itemNames[i]);
            }

            if (itemNames.Length > MAX_ITEMS_TO_SHOW)
            {
                stringBuilder.AppendLine(PlasticLocalization.Name.DeleteOthersMessage.GetString(itemNames.Length - MAX_ITEMS_TO_SHOW));
            }

            stringBuilder.AppendLine();
            stringBuilder.AppendLine(PlasticLocalization.Name.DeleteBranchesConfirmation.GetString());

            return stringBuilder.ToString();
        }

        const int TEXT_LINE_HEIGHT = 15;
        const int MAX_ITEMS_TO_SHOW = 10;

        string mMessage;
        string mTitle;
        int mNumberOfBranches;
        bool mConfirmDelete;
    }
}
