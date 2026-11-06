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
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;
using TMPro;
#if UNITY_EDITOR || DEVELOPMENT_BUILD
namespace ByteDance.PICO.Debugger
{
    public class PXR_InspectorItem : MonoBehaviour
    {
        public TextMeshProUGUI text;
        public GameObject folderIcon;
        private bool hasChild = false;
        private string nodeName;
        private GameObject target;
        public GameObject Target => target;
        public Transform group;

        // Lazy-expansion / diff state.
        private Transform targetTransform;
#if UNITY_6000_4_OR_NEWER
        private EntityId targetId;
#else
        private int targetId;
#endif
        private bool childrenBuilt;
        private ulong lastChildSig;
        // Scratch buffer reused by SyncChildren to avoid per-tick GC.
#if UNITY_6000_4_OR_NEWER
        private static readonly Dictionary<EntityId, PXR_InspectorItem> s_existing = new Dictionary<EntityId, PXR_InspectorItem>();
#else
        private static readonly Dictionary<int, PXR_InspectorItem> s_existing = new Dictionary<int, PXR_InspectorItem>();
#endif

        /// <summary>The still-alive Transform this row represents (null if destroyed).</summary>
        public Transform TargetTransform => targetTransform;
#if UNITY_6000_4_OR_NEWER
        public EntityId TargetId => targetId;
#else
        public int TargetId => targetId;
#endif
        /// <summary>True when this node is expanded and its child rows are realised.</summary>
        public bool IsExpanded => childrenBuilt && group != null && group.gameObject.activeSelf;
        public bool HasChild => hasChild;

        public void SetTitle()
        {
            text.text = nodeName;
        }

        /// <summary>
        /// Register this row for the given Transform WITHOUT recursing into the
        /// subtree. Child rows are created lazily on first expand (Stage 1).
        /// </summary>
        public void Init(Transform item)
        {
            target = item.gameObject;
            targetTransform = item;
#if UNITY_6000_4_OR_NEWER
            targetId = item.gameObject.GetEntityId();
#else
            targetId = item.gameObject.GetInstanceID();
#endif
            nodeName = item.name;
            hasChild = item.childCount > 0;
            if (folderIcon != null)
            {
                folderIcon.SetActive(hasChild);
            }
            childrenBuilt = false;
            lastChildSig = 0UL;
            SetTitle();
        }

        /// <summary>
        /// Realise direct child rows on demand. Idempotent: on first call it
        /// instantiates every direct child; on later calls it reconciles the
        /// existing rows against the live Transform children (add / remove /
        /// reorder / rename). Only one level deep — descendants are handled
        /// when they themselves expand, keeping cost O(visible).
        /// </summary>
        public void EnsureChildren()
        {
            if (childrenBuilt) return;
            SyncChildren();
        }

        public void SyncChildren()
        {
            if (group == null) return;
            if (targetTransform == null) return; // destroyed; parent will prune this row.

            // Index existing rows by instanceID.
            s_existing.Clear();
            for (int i = group.childCount - 1; i >= 0; i--)
            {
                var childGo = group.GetChild(i).gameObject;
                if (childGo.TryGetComponent(out PXR_InspectorItem existing) && existing.targetTransform != null)
                {
                    s_existing[existing.targetId] = existing;
                }
                else
                {
                    // Orphaned / destroyed row -> drop it.
                    DestroyImmediate(childGo);
                }
            }

            int liveCount = targetTransform.childCount;
            for (int i = 0; i < liveCount; i++)
            {
                var childTf = targetTransform.GetChild(i);
#if UNITY_6000_4_OR_NEWER
                EntityId id = childTf.gameObject.GetEntityId();
#else
                int id = childTf.gameObject.GetInstanceID();
#endif
                if (s_existing.TryGetValue(id, out var row))
                {
                    // Reuse: fix order, refresh cheap visuals (rename / new grandchildren).
                    row.transform.SetSiblingIndex(i);
                    row.RefreshSelf(childTf);
                    s_existing.Remove(id);
                }
                else
                {
                    AddItem(childTf, i);
                }
            }

            // Whatever is left in s_existing no longer exists in the scene.
            foreach (var stale in s_existing.Values)
            {
                if (stale != null) DestroyImmediate(stale.gameObject);
            }
            s_existing.Clear();

            hasChild = liveCount > 0;
            if (folderIcon != null) folderIcon.SetActive(hasChild);
            childrenBuilt = true;
            lastChildSig = ComputeChildSignature();
        }

        /// <summary>Refresh this row's own cheap visuals against its (possibly renamed) Transform.</summary>
        public void RefreshSelf(Transform item)
        {
            targetTransform = item;
            target = item.gameObject;
            if (nodeName != item.name)
            {
                nodeName = item.name;
                SetTitle();
            }
            bool nowHasChild = item.childCount > 0;
            if (nowHasChild != hasChild)
            {
                hasChild = nowHasChild;
                if (folderIcon != null) folderIcon.SetActive(hasChild);
            }
        }

        public void AddItem(Transform item)
        {
            AddItem(item, -1);
        }

        private void AddItem(Transform item, int siblingIndex)
        {
            var go = Instantiate(PXR_InspectorManager.Instance.inspectItem, group);
            if (siblingIndex >= 0) go.transform.SetSiblingIndex(siblingIndex);
            if (go.TryGetComponent(out PXR_InspectorItem inspectItem))
            {
                inspectItem.Init(item);
            }
        }

        /// <summary>
        /// Recompute the direct-child signature and report whether it changed
        /// since the last sync. Cheap O(direct children) ordered hash used by
        /// the tracker to skip untouched nodes (Stage 4).
        /// </summary>
        public bool ChildrenChanged()
        {
            ulong sig = ComputeChildSignature();
            if (sig == lastChildSig) return false;
            lastChildSig = sig;
            return true;
        }

        private ulong ComputeChildSignature()
        {
            if (targetTransform == null) return 0UL;
            // FNV-1a over ordered (instanceID, name hash, grandchild count).
            ulong h = 1469598103934665603UL;
            int count = targetTransform.childCount;
            h = Fnv(h, (ulong)count);
            for (int i = 0; i < count; i++)
            {
                var c = targetTransform.GetChild(i);
#if UNITY_6000_4_OR_NEWER
                h = Fnv(h, EntityId.ToULong(c.gameObject.GetEntityId()));
#else
                h = Fnv(h, (ulong)c.gameObject.GetInstanceID());
#endif
                h = Fnv(h, (ulong)c.name.GetHashCode());
                h = Fnv(h, (ulong)c.childCount);
            }
            return h;
        }

        private static ulong Fnv(ulong h, ulong v)
        {
            h ^= v;
            h *= 1099511628211UL;
            return h;
        }
    }
}
#endif