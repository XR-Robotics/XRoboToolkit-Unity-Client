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
using System;
using System.Collections.Generic;
using System.Reflection;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
#if UNITY_EDITOR || DEVELOPMENT_BUILD
namespace ByteDance.PICO.Debugger
{
    // Builds the right-detail controls for [PICODebuggerItem] members at runtime.
    //
    // Each DebuggerType maps to a dedicated prefab supplied by the caller
    // (PXR_CustomController wires them via the Inspector). The prefabs are kept
    // out of any Resources/ folder so they are not exposed for runtime loading;
    // they carry visual structure only and this factory finds the well-known
    // child nodes by path to fill in text / wire listeners. Node-path contract
    // per type:
    //   Default -> Content/Title (member name) + Rotation/Value (value text)
    //   Toggle  -> Name/Title (member name)    + Content/title  (true/false text)
    //   Range   -> Content/title (member name) + Content/value (current value)
    //                                          + Content/slide  (Slider, [min,max])
    //   Action  -> Name/Title (method name)    + EditorButtonArea/button (Button)
    public static class PXR_CustomItemFactory
    {
        private const int HeaderFontSize = 20;
        private const int MaxTextLength = 256;

        private static readonly Color HeaderColor = new Color(0f, 0f, 0f, 1f);

        // Members are discovered purely by the presence of [PICODebuggerItem];
        // there is no separate class-level marker. A type "qualifies" iff it has
        // at least one renderable item. Results are cached per Type because the
        // left list re-scans every loaded MonoBehaviour on each Refresh().
        public const BindingFlags MemberFlags = BindingFlags.Public | BindingFlags.NonPublic |
                                                BindingFlags.Instance | BindingFlags.Static;
        private static readonly Dictionary<Type, bool> HasItemsCache =
            new Dictionary<Type, bool>();

        // True if the type exposes at least one member that the Custom panel can
        // render (any field/property with [PICODebuggerItem], or a no-arg void
        // method tagged Action).
        public static bool HasDebuggerItems(Type type)
        {
            if (type == null) return false;
            if (HasItemsCache.TryGetValue(type, out bool cached)) return cached;

            bool has = false;
            foreach (var field in type.GetFields(MemberFlags))
            {
                if (field.GetCustomAttribute<PICODebuggerItemAttribute>(true) != null) { has = true; break; }
            }
            if (!has)
            {
                foreach (var prop in type.GetProperties(MemberFlags))
                {
                    if (prop.GetCustomAttribute<PICODebuggerItemAttribute>(true) != null) { has = true; break; }
                }
            }
            if (!has)
            {
                foreach (var method in type.GetMethods(MemberFlags))
                {
                    if (!IsRenderableActionMethod(method)) continue;
                    has = true;
                    break;
                }
            }
            HasItemsCache[type] = has;
            return has;
        }

        // Action members must be no-arg void methods tagged with the Action type.
        public static bool IsRenderableActionMethod(MethodInfo method)
        {
            var attr = method.GetCustomAttribute<PICODebuggerItemAttribute>(true);
            if (attr == null || attr.type != DebuggerType.Action) return false;
            return method.ReturnType == typeof(void) && method.GetParameters().Length == 0;
        }

        // ---- group header (one per debuggable component) ---------------------
        // Kept as a lightweight code-built row: it is a label only, with no
        // type-specific control, so it needs no prefab.
        public static void BuildGroupHeader(Transform parent, string title)
        {
            var go = new GameObject("Group:" + title, typeof(RectTransform), typeof(LayoutElement));
            go.transform.SetParent(parent, false);
            var le = go.GetComponent<LayoutElement>();
            le.minHeight = 44;
            le.preferredHeight = 44;
            var rt = go.GetComponent<RectTransform>();
            rt.anchorMin = new Vector2(0f, 1f);
            rt.anchorMax = new Vector2(1f, 1f);
            rt.pivot = new Vector2(0.5f, 1f);

            var t = go.AddComponent<TextMeshProUGUI>();
            t.text = title;
            t.fontSize = HeaderFontSize;
            t.color = HeaderColor;
            t.fontStyle = FontStyles.Bold;
            t.alignment = TextAlignmentOptions.Left;
#if UNITY_6000_0_OR_NEWER
            t.textWrappingMode = TextWrappingModes.NoWrap;
#else
            t.enableWordWrapping = false;
#endif
            t.overflowMode = TextOverflowModes.Ellipsis;
            t.raycastTarget = false;
        }

        // ---- one member row ---------------------------------------------------
        // The caller passes the prefab to instantiate for this member's type, so
        // no Resources lookup happens here and the prefabs can live anywhere.
        public static void BuildItem(Transform parent, object target, MemberInfo member,
            PICODebuggerItemAttribute attr, GameObject prefab)
        {
            string label = string.IsNullOrEmpty(attr.displayName) ? member.Name : attr.displayName;
            switch (attr.type)
            {
                case DebuggerType.Range:
                    BuildRange(parent, target, member, attr, label, prefab);
                    break;
                case DebuggerType.Toggle:
                    BuildToggle(parent, target, member, label, prefab);
                    break;
                case DebuggerType.Action:
                    BuildAction(parent, target, member, label, prefab);
                    break;
                default:
                    BuildDefault(parent, target, member, label, prefab);
                    break;
            }
        }

        private static void BuildDefault(Transform parent, object target, MemberInfo member, string label,
            GameObject prefab)
        {
            var row = Instantiate(prefab, parent);
            if (row == null) return;

            SetText(row, "Content/Title", label);

            var valText = FindText(row, "Rotation/Value");
            Bind(row, () =>
            {
                object value = TryGetMemberValue(target, member, out bool ok);
                string display = !ok ? "<n/a>" : value == null ? "null" : value.ToString();
                if (display.Length > MaxTextLength) display = display.Substring(0, MaxTextLength) + "…";
                if (valText != null) valText.text = display;
            });
        }

        private static void BuildToggle(Transform parent, object target, MemberInfo member, string label,
            GameObject prefab)
        {
            var row = Instantiate(prefab, parent);
            if (row == null) return;

            SetText(row, "Name/Title", label);

            var titleText = FindText(row, "Content/title");

            // The PICOSwitch under EditorButtonArea drives the member value: flipping
            // it writes the bool back to the displayed target.
            var area = row.transform.Find("EditorButtonArea");
            var toggle = area != null ? area.GetComponentInChildren<Toggle>(true) : null;
            if (toggle != null)
            {
                toggle.onValueChanged.AddListener(isOn =>
                {
                    TrySetMemberValue(target, member, isOn);
                    if (titleText != null) titleText.text = isOn ? "true" : "false";
                });
            }

            // property -> UI: keep the toggle and text in sync with the member.
            Bind(row, () =>
            {
                object cur = TryGetMemberValue(target, member, out bool ok);
                bool b = ok && cur is bool bb && bb;
                if (toggle != null && toggle.isOn != b) toggle.SetIsOnWithoutNotify(b);
                if (titleText != null) titleText.text = b ? "true" : "false";
            });
        }

        private static void BuildRange(Transform parent, object target, MemberInfo member,
            PICODebuggerItemAttribute attr, string label, GameObject prefab)
        {
            var row = Instantiate(prefab, parent);
            if (row == null) return;

            SetText(row, "Content/title", label);

            Type mt = GetMemberType(member);
            bool isInt = mt == typeof(int) || mt == typeof(long) || mt == typeof(short) || mt == typeof(byte);
            float min = attr.min;
            float max = attr.max < attr.min ? attr.min : attr.max;

            var valText = FindText(row, "Content/value");
            var slider = FindComponent<Slider>(row, "Content/slide");

            string Format(float v) => isInt ? Mathf.RoundToInt(v).ToString() : v.ToString("0.###");

            if (slider != null)
            {
                slider.minValue = min;
                slider.maxValue = max;
                slider.wholeNumbers = isInt;
                slider.onValueChanged.AddListener(v =>
                {
                    // Dragging only ever writes a value inside the declared range.
                    float clamped = Mathf.Clamp(v, min, max);
                    if (isInt)
                    {
                        int iv = Mathf.RoundToInt(clamped);
                        TrySetMemberValue(target, member, Convert.ChangeType(iv, mt));
                        if (valText != null) valText.text = iv.ToString();
                    }
                    else
                    {
                        TrySetMemberValue(target, member, Convert.ChangeType(clamped, mt));
                        if (valText != null) valText.text = clamped.ToString("0.###");
                    }
                });
            }

            // property -> UI: the value text always shows the TRUE member value,
            // even when it lies outside [min,max] (the slider cannot represent an
            // out-of-range value, so the handle is clamped to the nearest bound
            // while the text stays truthful).
            Bind(row, () =>
            {
                object cur = TryGetMemberValue(target, member, out bool ok);
                float curF = ok && cur != null ? Convert.ToSingle(cur) : min;
                if (valText != null) valText.text = Format(curF);
                if (slider != null)
                {
                    float handle = Mathf.Clamp(curF, min, max);
                    if (!Mathf.Approximately(slider.value, handle)) slider.SetValueWithoutNotify(handle);
                }
            });
        }

        private static void BuildAction(Transform parent, object target, MemberInfo member, string label,
            GameObject prefab)
        {
            var row = Instantiate(prefab, parent);
            if (row == null) return;

            SetText(row, "Name/Title", label);

            var method = member as MethodInfo;
            var button = FindComponent<Button>(row, "EditorButtonArea/button");
            if (button == null) return;

            // Only no-arg void methods are supported (verified by the scanner too).
            if (method != null && method.GetParameters().Length == 0)
            {
                button.onClick.AddListener(() =>
                {
                    // Static methods must be invoked with a null target; passing the
                    // component instance would throw (and get swallowed below).
                    object invokeTarget = method.IsStatic ? null : target;
                    try { method.Invoke(invokeTarget, null); }
                    catch (Exception e) { Debug.LogError($"[PICODebugger] Action '{label}' threw: {e}"); }
                });
            }
            else
            {
                button.interactable = false;
            }
        }

        // ---- two-way binding -------------------------------------------------
        // Attaches a per-frame refresh closure to the row so that external
        // changes to the member (property -> UI) are reflected back into the
        // controls. The closure runs once immediately, then every Update.
        private static void Bind(GameObject row, Action refresh)
        {
            if (row == null || refresh == null) return;
            var binding = row.AddComponent<PXR_CustomItemBinding>();
            binding.Bind(refresh);
        }

        // ---- prefab + node-path helpers --------------------------------------
        private static GameObject Instantiate(GameObject prefab, Transform parent)
        {
            if (prefab == null)
            {
                Debug.LogError("[PICODebugger] item prefab reference is not assigned on PXR_CustomController");
                return null;
            }
            return UnityEngine.Object.Instantiate(prefab, parent, false);
        }

        private static TextMeshProUGUI FindText(GameObject root, string path)
        {
            var t = root.transform.Find(path);
            if (t == null)
            {
                Debug.LogWarning($"[PICODebugger] node '{path}' missing in {root.name}");
                return null;
            }
            return t.GetComponent<TextMeshProUGUI>();
        }

        private static void SetText(GameObject root, string path, string value)
        {
            var tmp = FindText(root, path);
            if (tmp != null) tmp.text = value;
        }

        private static T FindComponent<T>(GameObject root, string path) where T : Component
        {
            var t = root.transform.Find(path);
            if (t == null)
            {
                Debug.LogWarning($"[PICODebugger] node '{path}' missing in {root.name}");
                return null;
            }
            return t.GetComponent<T>();
        }

        // ---- reflection accessors --------------------------------------------
        public static Type GetMemberType(MemberInfo member)
        {
            if (member is FieldInfo f) return f.FieldType;
            if (member is PropertyInfo p) return p.PropertyType;
            return null;
        }

        public static object TryGetMemberValue(object target, MemberInfo member, out bool ok)
        {
            ok = false;
            try
            {
                if (member is FieldInfo f) { ok = true; return f.GetValue(target); }
                if (member is PropertyInfo p && p.CanRead) { ok = true; return p.GetValue(target); }
            }
            catch (Exception e) { Debug.LogWarning($"[PICODebugger] read '{member.Name}' failed: {e.Message}"); }
            return null;
        }

        public static void TrySetMemberValue(object target, MemberInfo member, object value)
        {
            try
            {
                if (member is FieldInfo f) { f.SetValue(target, value); return; }
                if (member is PropertyInfo p && p.CanWrite) { p.SetValue(target, value); }
            }
            catch (Exception e) { Debug.LogWarning($"[PICODebugger] write '{member.Name}' failed: {e.Message}"); }
        }
    }
}
#endif
