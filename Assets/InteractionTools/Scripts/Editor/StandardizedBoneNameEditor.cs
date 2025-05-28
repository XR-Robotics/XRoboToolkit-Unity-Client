using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

[CustomEditor(typeof(StandardizedBoneName))]
public class StandardizedBoneNameEditor : Editor
{
    public override void OnInspectorGUI()
    {
        DrawDefaultInspector();

        StandardizedBoneName renameScript = (StandardizedBoneName)target;
        if (GUILayout.Button("Rename Children"))
        {
            RenameChildren(renameScript.transform);
            EditorUtility.SetDirty(renameScript.gameObject);
        }
    }

    // This method will be called by the button
    public void RenameChildren(Transform transform)
    {
        string newName = ModifyName(transform.name);
        if (!string.IsNullOrEmpty(newName))
        {
            transform.gameObject.name = newName;
        }

        foreach (Transform child in transform)
        {
            RenameChildren(child);
        }
    }


    // Change the name, remove the second '_' character according to the rules, and capitalize the letters after '_'
    private string ModifyName(string name)
    {
        int firstIndex = name.IndexOf('_');
        if (firstIndex == -1) return name; //If there is no '_', return the original name

        int secondIndex = name.IndexOf('_', firstIndex + 1);
        if (secondIndex == -1) return CapitalizeAfterUnderscore(name); // If there is no second '_', only capitalize it

        // Remove the second '_' and capitalize it
        string newName = name.Remove(secondIndex, 1);
        return CapitalizeAfterUnderscore(newName);
    }

    // Capitalize the letter after '_'
    private string CapitalizeAfterUnderscore(string name)
    {
        char[] nameArray = name.ToCharArray();
        for (int i = 0; i < nameArray.Length - 1; i++)
        {
            if (nameArray[i] == '_' && char.IsLetter(nameArray[i + 1]))
            {
                nameArray[i + 1] = char.ToUpper(nameArray[i + 1]);
            }
        }

        return new string(nameArray);
    }
}