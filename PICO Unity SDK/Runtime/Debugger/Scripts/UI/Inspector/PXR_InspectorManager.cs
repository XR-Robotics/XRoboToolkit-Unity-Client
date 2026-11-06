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
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
#if UNITY_EDITOR || DEVELOPMENT_BUILD
namespace ByteDance.PICO.Debugger
{
    public class PXR_InspectorManager : MonoBehaviour
    {
        public static PXR_InspectorManager Instance;
        private void Awake(){
            if(Instance == null){
                Instance = this;
            }
        }
        public GameObject inspectItem;
        public Transform content;
        public GameObject transformInfoNode;

        [Tooltip("Per-frame time budget (ms) for spreading the initial root build across frames (Stage 3).")]
        public float buildBudgetMs = 2f;
        [Tooltip("How often (seconds) to poll the live hierarchy for changes (Stage 4). <=0 disables auto-tracking.")]
        public float trackIntervalSeconds = 0.3f;

        // Reused scratch buffers to avoid per-tick GC.
#if UNITY_6000_4_OR_NEWER
        private static readonly Dictionary<EntityId, PXR_InspectorItem> s_existingRoots = new Dictionary<EntityId, PXR_InspectorItem>();
#else
        private static readonly Dictionary<int, PXR_InspectorItem> s_existingRoots = new Dictionary<int, PXR_InspectorItem>();
#endif
        private static readonly List<PXR_InspectorItem> s_walk = new List<PXR_InspectorItem>();
        private readonly Stopwatch buildWatch = new Stopwatch();
        private Coroutine buildRoutine;
        private Coroutine trackRoutine;

        private void ClearAllChildren(){
            int childCount = content.childCount;
            for (int i = childCount - 1; i >= 0; i--)
            {
                DestroyImmediate(content.GetChild(i).gameObject);
            }
        }
        public void CreateInspector()
        {
            // Stage 3: build root rows under a frame budget instead of all at once.
            if (buildRoutine != null) StopCoroutine(buildRoutine);
            buildRoutine = StartCoroutine(BuildRootsRoutine());
        }
        private void Start() {
            CreateInspector();
            // Stage 4: replace the manual-only refresh with idle hierarchy tracking.
            if (trackIntervalSeconds > 0f)
            {
                trackRoutine = StartCoroutine(TrackRoutine());
            }
        }
        private void OnDestroy()
        {
            if (buildRoutine != null) StopCoroutine(buildRoutine);
            if (trackRoutine != null) StopCoroutine(trackRoutine);
        }
        public void Reset(){
            for (int i = 0; i < content.childCount; i++)
            {
                LayoutRebuilder.ForceRebuildLayoutImmediate(content.GetChild(i).GetComponent<RectTransform>());
            }
        }

        /// <summary>
        /// Manual hard rescan (still bound to the Refresh button via
        /// DebuggerPanel.prefab). No longer tears the tree down: it reconciles
        /// the existing rows against the live hierarchy in place, so there is no
        /// flicker and expand/selection/scroll survive.
        /// </summary>
        public void Refresh(){
            SyncRoots();
            Reset();
            if (PXR_InspectorController.Instance != null)
            {
                PXR_InspectorController.Instance.RefreshTarget();
            }
        }

        private IEnumerator BuildRootsRoutine()
        {
            buildWatch.Restart();
            GameObject[] rootObjects = SceneManager.GetActiveScene().GetRootGameObjects();
            foreach (GameObject obj in rootObjects)
            {
                if (!ShouldShowRoot(obj)) continue;
                var go = Instantiate(inspectItem, content);
                if (go.TryGetComponent(out PXR_InspectorItem item))
                {
                    item.Init(obj.transform);
                }
                if (buildWatch.Elapsed.TotalMilliseconds >= buildBudgetMs)
                {
                    yield return null; // hand the frame back, resume next frame.
                    buildWatch.Restart();
                }
            }
            Reset();
            buildRoutine = null;
        }

        private static bool ShouldShowRoot(GameObject obj)
        {
            return !obj.TryGetComponent<PXR_UIController>(out _) && !obj.TryGetComponent<PXR_UIManager>(out _);
        }

        /// <summary>
        /// Reconcile root rows against the live root GameObjects by instanceID:
        /// add new, remove gone, fix order, rename in place. Then re-sync any
        /// expanded subtree so deeper changes show too.
        /// </summary>
        private void SyncRoots()
        {
            s_existingRoots.Clear();
            for (int i = content.childCount - 1; i >= 0; i--)
            {
                var childGo = content.GetChild(i).gameObject;
                if (childGo.TryGetComponent(out PXR_InspectorItem existing) && existing.TargetTransform != null)
                {
                    s_existingRoots[existing.TargetId] = existing;
                }
                else
                {
                    DestroyImmediate(childGo);
                }
            }

            GameObject[] rootObjects = SceneManager.GetActiveScene().GetRootGameObjects();
            int slot = 0;
            foreach (GameObject obj in rootObjects)
            {
                if (!ShouldShowRoot(obj)) continue;
#if UNITY_6000_4_OR_NEWER
                EntityId id = obj.GetEntityId();
#else
                int id = obj.GetInstanceID();
#endif
                if (s_existingRoots.TryGetValue(id, out var row))
                {
                    row.transform.SetSiblingIndex(slot);
                    row.RefreshSelf(obj.transform);
                    ResyncExpanded(row);
                    s_existingRoots.Remove(id);
                }
                else
                {
                    var go = Instantiate(inspectItem, content);
                    go.transform.SetSiblingIndex(slot);
                    if (go.TryGetComponent(out PXR_InspectorItem item))
                    {
                        item.Init(obj.transform);
                    }
                }
                slot++;
            }

            foreach (var stale in s_existingRoots.Values)
            {
                if (stale != null) DestroyImmediate(stale.gameObject);
            }
            s_existingRoots.Clear();
        }

        /// <summary>Recursively re-sync only the expanded part of a subtree.</summary>
        private static void ResyncExpanded(PXR_InspectorItem node)
        {
            if (node == null || !node.IsExpanded) return;
            node.SyncChildren();
            var grp = node.group;
            if (grp == null) return;
            for (int i = 0; i < grp.childCount; i++)
            {
                if (grp.GetChild(i).TryGetComponent(out PXR_InspectorItem child))
                {
                    ResyncExpanded(child);
                }
            }
        }

        /// <summary>
        /// Stage 4 idle tracker. On an interval, visit only realised/expanded
        /// rows and re-sync just the ones whose cheap child signature changed.
        /// Untouched nodes cost O(1); a single layout patch runs if anything moved.
        /// </summary>
        private IEnumerator TrackRoutine()
        {
            var wait = new WaitForSeconds(trackIntervalSeconds);
            while (true)
            {
                yield return wait;
                if (buildRoutine != null) continue; // still doing the initial build.
                if (content == null) continue;

                bool changed = false;

                // Root level: detect add/remove/reorder via the content child set.
                // Collect current realised root rows.
                s_walk.Clear();
                for (int i = 0; i < content.childCount; i++)
                {
                    if (content.GetChild(i).TryGetComponent(out PXR_InspectorItem rootItem))
                    {
                        s_walk.Add(rootItem);
                    }
                }

                // A destroyed root target means the root set changed -> resync roots.
                bool rootSetDirty = false;
                foreach (var r in s_walk)
                {
                    if (r == null || r.TargetTransform == null) { rootSetDirty = true; break; }
                    if (r.ChildrenChanged()) { rootSetDirty = true; break; }
                }
                // Cheap extra guard: live root count vs realised root count.
                if (!rootSetDirty)
                {
                    int liveRoots = CountVisibleRoots();
                    if (liveRoots != s_walk.Count) rootSetDirty = true;
                }

                if (rootSetDirty)
                {
                    SyncRoots();
                    changed = true;
                }
                else
                {
                    // Roots stable: walk expanded subtrees, resync only changed nodes.
                    for (int i = 0; i < s_walk.Count; i++)
                    {
                        if (TrackNode(s_walk[i])) changed = true;
                    }
                }

                if (changed) Reset();
            }
        }

        private static bool TrackNode(PXR_InspectorItem node)
        {
            if (node == null || node.TargetTransform == null) return false;
            if (!node.IsExpanded) return false; // collapsed: invisible, skip until expanded.

            bool changed = false;
            if (node.ChildrenChanged())
            {
                node.SyncChildren();
                changed = true;
            }
            var grp = node.group;
            if (grp != null)
            {
                for (int i = 0; i < grp.childCount; i++)
                {
                    if (grp.GetChild(i).TryGetComponent(out PXR_InspectorItem child))
                    {
                        if (TrackNode(child)) changed = true;
                    }
                }
            }
            return changed;
        }

        private static int CountVisibleRoots()
        {
            int n = 0;
            GameObject[] rootObjects = SceneManager.GetActiveScene().GetRootGameObjects();
            foreach (GameObject obj in rootObjects)
            {
                if (ShouldShowRoot(obj)) n++;
            }
            return n;
        }
    }
}
#endif