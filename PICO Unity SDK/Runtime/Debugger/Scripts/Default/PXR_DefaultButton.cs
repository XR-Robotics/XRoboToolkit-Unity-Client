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
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using System.Collections;
using System.Collections.Generic;
#if UNITY_EDITOR || DEVELOPMENT_BUILD
namespace ByteDance.PICO.Debugger
{
    public class PXR_DefaultButton : MonoBehaviour
    {
        public RectTransform panel;

        // Fixed rank order (Console=Log < Inspector < Custom). Used to decide which
        // side a newly shown panel goes to, and the canonical 3-panel layout. Panels
        // whose name is not in this list (e.g. ToolPanel) are ignored by the layout.
        static readonly string[] panelOrder = { "ConsolePanel", "InspectorPanel", "CustomPanel" };

        // Current occupants of the three layout slots. A panel that is "the one that
        // was already showing" keeps the center slot; newly shown panels take a side
        // slot chosen by rank relative to the center.
        static RectTransform leftPanel;
        static RectTransform centerPanel;
        static RectTransform rightPanel;

        private const float panelRotateAngle = 25f;
        private const float moveDuration = 0.3f;     // position + rotation transition
        private const float scaleDuration = 0.3f;    // show/hide scaleX 0<->1 transition
        private const float sequenceDelay = 0.2f;    // gap before the second animation starts

        // Tracks the running transition per panel so a new one cancels the old one.
        // Move (position/rotation) and scale (show/hide) are tracked separately
        // because they animate independent transform channels in parallel.
        static readonly Dictionary<RectTransform, MonoBehaviour> moveOwner = new();
        static readonly Dictionary<RectTransform, Coroutine> moveRoutine = new();
        static readonly Dictionary<RectTransform, MonoBehaviour> scaleOwner = new();
        static readonly Dictionary<RectTransform, Coroutine> scaleRoutine = new();

        private enum Slot { Left, Center, Right }

        public void TogglePanel(Toggle toggle)
        {
            if (toggle.isOn)
            {
                ShowPanel(panel);
            }
            else
            {
                HidePanel(panel);
            }
        }

        private static int ActiveCount()
        {
            var n = 0;
            if (leftPanel != null) n++;
            if (centerPanel != null) n++;
            if (rightPanel != null) n++;
            return n;
        }

        private static bool IsShown(RectTransform p)
        {
            return p == leftPanel || p == centerPanel || p == rightPanel;
        }

        private static int GetRank(RectTransform panel)
        {
            for (var i = 0; i < panelOrder.Length; i++)
            {
                if (panel.name == panelOrder[i]) return i;
            }
            return -1;
        }

        private void ShowPanel(RectTransform panel)
        {
            if (GetRank(panel) < 0) return;          // not a layout panel (e.g. ToolPanel)
            if (IsShown(panel)) return;
            panel.gameObject.SetActive(true);

            var count = ActiveCount();
            if (count == 0)
            {
                // 0 -> 1: the panel becomes the center; only a scale animation.
                centerPanel = panel;
                PlaceInstant(panel, Slot.Center);
                ScaleIn(panel, 0f);
            }
            else if (count == 1)
            {
                // 1 -> 2: the existing panel stays at center (no move). The new panel
                // is placed instantly to the side chosen by rank, then scales in.
                var side = GetRank(panel) < GetRank(centerPanel) ? Slot.Left : Slot.Right;
                if (side == Slot.Left) leftPanel = panel; else rightPanel = panel;
                PlaceInstant(panel, side);
                ScaleIn(panel, 0f);
            }
            else
            {
                // 2 -> 3: layout returns to the canonical Log(left)/Inspector(center)/
                // Custom(right). The two existing panels move to their rank slots
                // first; the new panel is placed instantly at its slot and scales in
                // after sequenceDelay.
                AssignRankSlots(panel);
                if (leftPanel != panel) MoveToSlot(leftPanel, Slot.Left, 0f);
                if (centerPanel != panel) MoveToSlot(centerPanel, Slot.Center, 0f);
                if (rightPanel != panel) MoveToSlot(rightPanel, Slot.Right, 0f);
                PlaceInstantAtCurrentSlot(panel);
                ScaleIn(panel, sequenceDelay);
            }
        }

        private void HidePanel(RectTransform panel)
        {
            if (!IsShown(panel)) return;

            var count = ActiveCount();
            var wasCenter = panel == centerPanel;

            // Free the slot the panel occupied.
            if (panel == leftPanel) leftPanel = null;
            else if (panel == centerPanel) centerPanel = null;
            else if (panel == rightPanel) rightPanel = null;

            if (count == 3)
            {
                if (!wasCenter)
                {
                    // 3 -> 2 hiding a side: the other two stay put; only scale out.
                    ScaleOut(panel, 0f);
                }
                else
                {
                    // 3 -> 2 hiding the center: left stays, right slides to center.
                    var mover = rightPanel;
                    rightPanel = null;
                    centerPanel = mover;
                    ScaleOut(panel, 0f);
                    if (mover != null) MoveToSlot(mover, Slot.Center, sequenceDelay);
                }
            }
            else if (count == 2)
            {
                if (!wasCenter)
                {
                    // 2 -> 1 hiding a side: the center stays; only scale out.
                    ScaleOut(panel, 0f);
                }
                else
                {
                    // 2 -> 1 hiding the center: the remaining side moves to center.
                    var mover = leftPanel != null ? leftPanel : rightPanel;
                    leftPanel = null;
                    rightPanel = null;
                    centerPanel = mover;
                    ScaleOut(panel, 0f);
                    if (mover != null) MoveToSlot(mover, Slot.Center, sequenceDelay);
                }
            }
            else
            {
                // 1 -> 0: only scale out.
                ScaleOut(panel, 0f);
            }
        }

        // Reassigns the three slots to the canonical rank order using the currently
        // shown panels plus the newly added one.
        private void AssignRankSlots(RectTransform newPanel)
        {
            var panels = new List<RectTransform>();
            if (leftPanel != null) panels.Add(leftPanel);
            if (centerPanel != null) panels.Add(centerPanel);
            if (rightPanel != null) panels.Add(rightPanel);
            panels.Add(newPanel);
            panels.Sort((a, b) => GetRank(a).CompareTo(GetRank(b)));
            // Exactly three panels here (2 -> 3 transition).
            leftPanel = panels[0];
            centerPanel = panels[1];
            rightPanel = panels[2];
        }

        // ---- slot geometry -------------------------------------------------------

        private Vector3 SlotPosition(Slot slot, RectTransform target)
        {
            if (slot == Slot.Center || centerPanel == null) return Vector3.zero;
            var mainPanelWidth = centerPanel.rect.width;
            var halfW = target.rect.width * 0.5f;
            var offset = Mathf.Sin(panelRotateAngle * Mathf.Deg2Rad) * halfW;
            var sign = slot == Slot.Left ? -1f : 1f;
            return new Vector3(sign * (mainPanelWidth * 0.5f + halfW), 0, -offset);
        }

        private Vector3 SlotRotation(Slot slot)
        {
            if (slot == Slot.Center) return Vector3.zero;
            var sign = slot == Slot.Left ? -1f : 1f;
            return new Vector3(0, sign * panelRotateAngle, 0);
        }

        private Slot SlotOf(RectTransform p)
        {
            if (p == leftPanel) return Slot.Left;
            if (p == rightPanel) return Slot.Right;
            return Slot.Center;
        }

        private void PlaceInstant(RectTransform target, Slot slot)
        {
            target.localPosition = SlotPosition(slot, target);
            target.localEulerAngles = SlotRotation(slot);
        }

        private void PlaceInstantAtCurrentSlot(RectTransform target)
        {
            PlaceInstant(target, SlotOf(target));
        }

        private void MoveToSlot(RectTransform target, Slot slot, float delay)
        {
            if (target == null) return;
            AnimateMove(target, SlotPosition(slot, target), SlotRotation(slot), delay);
        }

        private void ScaleIn(RectTransform target, float delay)
        {
            SetScaleX(target, 0f);
            AnimateScaleX(target, 1f, false, delay);
        }

        private void ScaleOut(RectTransform target, float delay)
        {
            AnimateScaleX(target, 0f, true, delay);
        }

        private static void SetScaleX(RectTransform target, float x)
        {
            var s = target.localScale;
            s.x = x;
            target.localScale = s;
        }

        // Waits for the given seconds using unscaled time so the delay is consistent
        // with the animations (which also run on unscaled time).
        private static IEnumerator WaitUnscaled(float seconds)
        {
            var elapsed = 0f;
            while (elapsed < seconds)
            {
                elapsed += Time.unscaledDeltaTime;
                yield return null;
            }
        }

        // Smoothly transitions a panel to its target local position/rotation over
        // moveDuration seconds, optionally after startDelay seconds. Any in-flight
        // move for the same panel is cancelled first so layouts triggered in quick
        // succession do not fight.
        private void AnimateMove(RectTransform target, Vector3 targetPos, Vector3 targetRot, float startDelay)
        {
            if (moveRoutine.TryGetValue(target, out var running) && running != null
                && moveOwner.TryGetValue(target, out var owner) && owner != null)
            {
                owner.StopCoroutine(running);
            }

            if (!isActiveAndEnabled)
            {
                target.localPosition = targetPos;
                target.localEulerAngles = targetRot;
                moveRoutine.Remove(target);
                moveOwner.Remove(target);
                return;
            }

            moveOwner[target] = this;
            moveRoutine[target] = StartCoroutine(MoveRoutine(target, targetPos, targetRot, startDelay));
        }

        private IEnumerator MoveRoutine(RectTransform target, Vector3 targetPos, Vector3 targetRot, float startDelay)
        {
            if (startDelay > 0f) yield return WaitUnscaled(startDelay);
            var startPos = target.localPosition;
            var startRot = target.localEulerAngles;
            var elapsed = 0f;
            while (elapsed < moveDuration)
            {
                elapsed += Time.unscaledDeltaTime;
                var t = Mathf.Clamp01(elapsed / moveDuration);
                target.localPosition = Vector3.Lerp(startPos, targetPos, t);
                target.localEulerAngles = new Vector3(
                    Mathf.LerpAngle(startRot.x, targetRot.x, t),
                    Mathf.LerpAngle(startRot.y, targetRot.y, t),
                    Mathf.LerpAngle(startRot.z, targetRot.z, t));
                yield return null;
            }
            target.localPosition = targetPos;
            target.localEulerAngles = targetRot;
            moveRoutine.Remove(target);
            moveOwner.Remove(target);
        }

        // Animates a panel's scaleX to targetX over scaleDuration, optionally after
        // startDelay seconds. When deactivateOnEnd is true (hide), the panel is set
        // inactive and its scaleX restored to 1 after the animation so it is ready
        // for the next show. Any in-flight scale for the same panel is cancelled first.
        private void AnimateScaleX(RectTransform target, float targetX, bool deactivateOnEnd, float startDelay)
        {
            if (scaleRoutine.TryGetValue(target, out var running) && running != null
                && scaleOwner.TryGetValue(target, out var owner) && owner != null)
            {
                owner.StopCoroutine(running);
            }

            if (!isActiveAndEnabled)
            {
                if (deactivateOnEnd)
                {
                    target.gameObject.SetActive(false);
                    SetScaleX(target, 1f);
                }
                else
                {
                    SetScaleX(target, targetX);
                }
                scaleRoutine.Remove(target);
                scaleOwner.Remove(target);
                return;
            }

            scaleOwner[target] = this;
            scaleRoutine[target] = StartCoroutine(ScaleRoutine(target, targetX, deactivateOnEnd, startDelay));
        }

        private IEnumerator ScaleRoutine(RectTransform target, float targetX, bool deactivateOnEnd, float startDelay)
        {
            if (startDelay > 0f) yield return WaitUnscaled(startDelay);
            var startX = target.localScale.x;
            var elapsed = 0f;
            while (elapsed < scaleDuration)
            {
                elapsed += Time.unscaledDeltaTime;
                var t = Mathf.Clamp01(elapsed / scaleDuration);
                SetScaleX(target, Mathf.Lerp(startX, targetX, t));
                yield return null;
            }
            SetScaleX(target, targetX);
            scaleRoutine.Remove(target);
            scaleOwner.Remove(target);
            if (deactivateOnEnd)
            {
                target.gameObject.SetActive(false);
                // Restore scaleX so the panel shows at full size next time before
                // its own show animation overrides it.
                SetScaleX(target, 1f);
            }
        }
    }
}
#endif
