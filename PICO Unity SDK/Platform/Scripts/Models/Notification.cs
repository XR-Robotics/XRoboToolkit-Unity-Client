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
using ByteDance.PICO.Platform.Framework;
using UnityEngine;

namespace ByteDance.PICO.Platform.Models
{
    /// <summary>
    /// Invitation notification.
    /// </summary>
    public class RoomInviteNotification
    {
        /// Invitation ID. 
        public readonly UInt64 ID;
        /// Room ID. 
        public readonly UInt64 RoomID;
        /// Inviter's user ID. 
        public readonly string SenderID;
        /// The time when the invitation is sent. 
        public readonly DateTime SentTime;


        public RoomInviteNotification(IntPtr o)
        {
            ID = CLIB.CLIB.ppf_RoomInviteNotification_GetID(o);
            RoomID = CLIB.CLIB.ppf_RoomInviteNotification_GetRoomID(o);
            SenderID = CLIB.CLIB.ppf_RoomInviteNotification_GetSenderID(o);
            SentTime = new DateTime();
            try
            {
                SentTime = TimeUtil.SecondsToDateTime((long) CLIB.CLIB.ppf_RoomInviteNotification_GetSentTime(o));
            }
            catch (UnityException ex)
            {
                Debug.LogWarning($"RoomInviteNotification get SentTime fail {ex}");
                throw;
            }
        }
    }
    /// <summary>
    /// Each element is \ref RoomInviteNotification
    /// </summary>
    public class RoomInviteNotificationList : MessageArray<RoomInviteNotification>
    {
        /// The total number. 
        public readonly int TotalCount;
        public RoomInviteNotificationList(IntPtr a)
        {
            TotalCount = CLIB.CLIB.ppf_RoomInviteNotificationArray_GetTotalCount(a);
            NextPageParam = CLIB.CLIB.ppf_RoomInviteNotificationArray_HasNextPage(a) ? "true" : string.Empty;
            int count = (int) CLIB.CLIB.ppf_RoomInviteNotificationArray_GetSize(a);
            this.Capacity = count;
            for (uint i = 0; i < count; i++)
            {
                this.Add(new RoomInviteNotification(CLIB.CLIB.ppf_RoomInviteNotificationArray_GetElement(a, (UIntPtr)i)));
            }
        }
    }
}