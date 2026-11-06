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
using System.Runtime.InteropServices;
using ByteDance.PICO.Platform.CLIB;
using ByteDance.PICO.Platform.Framework;

namespace ByteDance.PICO.Platform.Models
{

    /// <summary>Achievement update info.</summary>
    public class AchievementUpdate
    {
        /// Whether the achievement is unlocked in this time. 
        public readonly bool JustUnlocked;

        /// Achievement name. 
        public readonly string Name;

        public AchievementUpdate(IntPtr o)
        {
            JustUnlocked = CLIB.CLIB.ppf_AchievementUpdate_GetJustUnlocked(o);
            Name = CLIB.CLIB.ppf_AchievementUpdate_GetName(o);
        }
    }

    /// <summary>Achievement info.</summary>
    public class AchievementDefinition
    {
        /// Achievement type. 
        public readonly AchievementType Type;

        /// Achievement name. 
        public readonly string Name;

        /// The target to reach for unlocking a bitfield achievement. 
        public readonly uint BitfieldLength;

        /// The target to reach for unlocking a count achievement. 
        public readonly long Target;

        /// Achievement description. 
        public readonly string Description;

        /// Achievement title. 
        public readonly string Title;

        /// Whether the achievement is archieved. 
        public readonly bool IsArchived;

        /// Whether the achievement is a secret achievement. If so, it can be visible after being unlocked only. 
        public readonly bool IsSecret;

        /// Achievement ID. 
        public readonly ulong ID;

        /// The description shown to users when unlocking the achievement. 
        public readonly string UnlockedDescription;

        /// The write policy of the achievement. 
        public readonly AchievementWritePolicy WritePolicy;

        /// The URL of the image displayed when the achievement is still locked. 
        public readonly string LockedImageURL;

        /// The URL of the image displayed when the achievement is unlocked. 
        public readonly string UnlockedImageURL;

        public AchievementDefinition(IntPtr o)
        {
            Type = CLIB.CLIB.ppf_AchievementDefinition_GetType(o);
            Name = CLIB.CLIB.ppf_AchievementDefinition_GetName(o);
            BitfieldLength = CLIB.CLIB.ppf_AchievementDefinition_GetBitfieldLength(o);
            Target = CLIB.CLIB.ppf_AchievementDefinition_GetTarget(o);
            Description = CLIB.CLIB.ppf_AchievementDefinition_GetDescription(o);
            Title = CLIB.CLIB.ppf_AchievementDefinition_GetTitle(o);
            IsArchived = CLIB.CLIB.ppf_AchievementDefinition_IsArchived(o);
            IsSecret = CLIB.CLIB.ppf_AchievementDefinition_IsSecret(o);
            ID = CLIB.CLIB.ppf_AchievementDefinition_GetID(o);
            UnlockedDescription = CLIB.CLIB.ppf_AchievementDefinition_GetUnlockedDescription(o);
            WritePolicy = CLIB.CLIB.ppf_AchievementDefinition_GetWritePolicy(o);
            LockedImageURL = CLIB.CLIB.ppf_AchievementDefinition_GetLockedImageURL(o);
            UnlockedImageURL = CLIB.CLIB.ppf_AchievementDefinition_GetUnlockedImageURL(o);
        }
    }

    /// <summary>Achievement definition list.
    /// Each element is \ref AchievementDefinition.
    /// </summary>
    public class AchievementDefinitionList : MessageArray<AchievementDefinition>
    {
        /// The total number of `AchievementDefinition`.
        public readonly ulong TotalSize;

        public AchievementDefinitionList(IntPtr a)
        {
            TotalSize = (ulong) CLIB.CLIB.ppf_AchievementDefinitionArray_GetTotalSize(a);
            var count = (int) CLIB.CLIB.ppf_AchievementDefinitionArray_GetSize(a);
            this.Capacity = count;
            for (uint i = 0; i < count; i++)
            {
                this.Add(new AchievementDefinition(CLIB.CLIB.ppf_AchievementDefinitionArray_GetElement(a, (UIntPtr) i)));
            }

            NextPageParam = CLIB.CLIB.ppf_AchievementDefinitionArray_HasNextPage(a) ? "true" : string.Empty;
        }
    }

    /// <summary>Achievement progress info. </summary>
    public class AchievementProgress
    {
        /// Achievement ID. 
        public readonly ulong ID;

        /// The progress of a bitfield achievement. `1` represents a completed bit. 
        public readonly string Bitfield;

        /// The progress of a count achievement. 
        public readonly long Count;

        /// Whether the achievement is unlocked 
        public readonly bool IsUnlocked;

        /// Achievement name. 
        public readonly string Name;

        /// The time when the achievement is unlocked. 
        public readonly DateTime UnlockTime;

        ///  Additional info, no more than 2KB.
        public readonly byte[] ExtraData;


        public AchievementProgress(IntPtr o)
        {
            ID = CLIB.CLIB.ppf_AchievementProgress_GetID(o);
            Bitfield = CLIB.CLIB.ppf_AchievementProgress_GetBitfield(o);
            Count = CLIB.CLIB.ppf_AchievementProgress_GetCount(o);
            IsUnlocked = CLIB.CLIB.ppf_AchievementProgress_GetIsUnlocked(o);
            Name = CLIB.CLIB.ppf_AchievementProgress_GetName(o);

            uint size = CLIB.CLIB.ppf_AchievementProgress_GetExtraDataLength(o);
            ExtraData = new byte[size];
            Marshal.Copy(CLIB.CLIB.ppf_AchievementProgress_GetExtraData(o), ExtraData, 0, (int) size);
            var unlockTime = CLIB.CLIB.ppf_AchievementProgress_GetUnlockTime(o);
            if (unlockTime != 0)
            {
                UnlockTime = TimeUtil.SecondsToDateTime((long) unlockTime);
            }
        }
    }

    /// <summary>The list of achievements with their progress info.
    /// Each element is \ref AchievementProgress.
    /// </summary>
    public class AchievementProgressList : MessageArray<AchievementProgress>
    {
        /// The total number of achievements with progress info. 
        public readonly ulong TotalSize;

        public AchievementProgressList(IntPtr a)
        {
            TotalSize = (ulong) CLIB.CLIB.ppf_AchievementProgressArray_GetTotalSize(a);
            var count = (int) CLIB.CLIB.ppf_AchievementProgressArray_GetSize(a);
            this.Capacity = count;
            for (uint i = 0; i < count; i++)
            {
                this.Add(new AchievementProgress(CLIB.CLIB.ppf_AchievementProgressArray_GetElement(a, (UIntPtr) i)));
            }

            NextPageParam = CLIB.CLIB.ppf_AchievementProgressArray_HasNextPage(a) ? "true" : string.Empty;
        }
    }
}