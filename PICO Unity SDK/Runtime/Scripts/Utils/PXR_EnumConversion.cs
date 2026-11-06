using System;

namespace ByteDance.PICO.XR
{
    public static class PXR_EnumConversion
    {
        public static BlendShapeIndex ToBlendShapeIndex(this XrFaceExpressionBD expression)
        {
            return expression switch
            {
                XrFaceExpressionBD.XR_FACE_EXPRESSION_BROW_DROP_L_BD => BlendShapeIndex.BrowDown_L,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_BROW_DROP_R_BD => BlendShapeIndex.BrowDown_R,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_BROW_INNER_UPWARDS_BD => BlendShapeIndex.BrowInnerUp,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_BROW_OUTER_UPWARDS_L_BD => BlendShapeIndex.BrowOuterUp_L,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_BROW_OUTER_UPWARDS_R_BD => BlendShapeIndex.BrowOuterUp_R,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_BLINK_L_BD => BlendShapeIndex.EyeBlink_L,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_DROP_L_BD => BlendShapeIndex.EyeLookDown_L,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_IN_L_BD => BlendShapeIndex.EyeLookIn_L,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_OUT_L_BD => BlendShapeIndex.EyeLookOut_L,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_UPWARDS_L_BD => BlendShapeIndex.EyeLookUp_L,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_SQUINT_L_BD => BlendShapeIndex.EyeSquint_L,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_WIDE_L_BD => BlendShapeIndex.EyeWide_L,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_BLINK_R_BD => BlendShapeIndex.EyeBlink_R,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_DROP_R_BD => BlendShapeIndex.EyeLookDown_R,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_IN_R_BD => BlendShapeIndex.EyeLookIn_R,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_OUT_R_BD => BlendShapeIndex.EyeLookOut_R,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_UPWARDS_R_BD => BlendShapeIndex.EyeLookUp_R,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_SQUINT_R_BD => BlendShapeIndex.EyeSquint_R,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_WIDE_R_BD => BlendShapeIndex.EyeWide_R,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_NOSE_SNEER_L_BD => BlendShapeIndex.NoseSneer_L,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_NOSE_SNEER_R_BD => BlendShapeIndex.NoseSneer_R,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_CHEEK_PUFF_BD => BlendShapeIndex.CheekPuff,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_CHEEK_SQUINT_L_BD => BlendShapeIndex.CheekSquint_L,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_CHEEK_SQUINT_R_BD => BlendShapeIndex.CheekSquint_R,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_CLOSE_BD => BlendShapeIndex.MouthClose,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_FUNNEL_BD => BlendShapeIndex.MouthFunnel,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_PUCKER_BD => BlendShapeIndex.MouthPucker,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_L_BD => BlendShapeIndex.MouthLeft,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_R_BD => BlendShapeIndex.MouthRight,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_SMILE_L_BD => BlendShapeIndex.MouthSmile_L,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_SMILE_R_BD => BlendShapeIndex.MouthSmile_R,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_FROWN_L_BD => BlendShapeIndex.MouthFrown_L,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_FROWN_R_BD => BlendShapeIndex.MouthFrown_R,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_DIMPLE_L_BD => BlendShapeIndex.MouthDimple_L,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_DIMPLE_R_BD => BlendShapeIndex.MouthDimple_R,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_STRETCH_L_BD => BlendShapeIndex.MouthStretch_L,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_STRETCH_R_BD => BlendShapeIndex.MouthStretch_R,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_ROLL_LOWER_BD => BlendShapeIndex.MouthRollLower,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_ROLL_UPPER_BD => BlendShapeIndex.MouthRollUpper,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_SHRUG_LOWER_BD => BlendShapeIndex.MouthShrugLower,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_SHRUG_UPPER_BD => BlendShapeIndex.MouthShrugUpper,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_PRESS_L_BD => BlendShapeIndex.MouthPress_L,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_PRESS_R_BD => BlendShapeIndex.MouthPress_R,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_LOWER_DROP_L_BD => BlendShapeIndex.MouthLowerDown_L,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_LOWER_DROP_R_BD => BlendShapeIndex.MouthLowerDown_R,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_UPPER_UPWARDS_L_BD => BlendShapeIndex.MouthUpperUp_L,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_UPPER_UPWARDS_R_BD => BlendShapeIndex.MouthUpperUp_R,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_JAW_FORWARD_BD => BlendShapeIndex.JawForward,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_JAW_L_BD => BlendShapeIndex.JawLeft,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_JAW_R_BD => BlendShapeIndex.JawRight,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_JAW_OPEN_BD => BlendShapeIndex.JawOpen,
                XrFaceExpressionBD.XR_FACE_EXPRESSION_TONGUE_OUT_BD => BlendShapeIndex.TongueOut,
                _ => throw new ArgumentOutOfRangeException(nameof(expression), expression, null)
            };
        }

        public static BlendShapeIndex ToBlendShapeIndex(this XrLipExpressionBD expression)
        {
            return expression switch
            {
                XrLipExpressionBD.XR_LIP_EXPRESSION_PP_BD => BlendShapeIndex.PP,
                XrLipExpressionBD.XR_LIP_EXPRESSION_CH_BD => BlendShapeIndex.CH,
                XrLipExpressionBD.XR_LIP_EXPRESSION_LO_BD => BlendShapeIndex.o,
                XrLipExpressionBD.XR_LIP_EXPRESSION_O_BD => BlendShapeIndex.O,
                XrLipExpressionBD.XR_LIP_EXPRESSION_I_BD => BlendShapeIndex.I,
                XrLipExpressionBD.XR_LIP_EXPRESSION_LU_BD => BlendShapeIndex.u,
                XrLipExpressionBD.XR_LIP_EXPRESSION_RR_BD => BlendShapeIndex.RR,
                XrLipExpressionBD.XR_LIP_EXPRESSION_XX_BD => BlendShapeIndex.XX,
                XrLipExpressionBD.XR_LIP_EXPRESSION_LAA_BD => BlendShapeIndex.aa,
                XrLipExpressionBD.XR_LIP_EXPRESSION_LI_BD => BlendShapeIndex.i,
                XrLipExpressionBD.XR_LIP_EXPRESSION_FF_BD => BlendShapeIndex.FF,
                XrLipExpressionBD.XR_LIP_EXPRESSION_U_BD => BlendShapeIndex.U,
                XrLipExpressionBD.XR_LIP_EXPRESSION_TH_BD => BlendShapeIndex.TH,
                XrLipExpressionBD.XR_LIP_EXPRESSION_LKK_BD => BlendShapeIndex.kk,
                XrLipExpressionBD.XR_LIP_EXPRESSION_SS_BD => BlendShapeIndex.SS,
                XrLipExpressionBD.XR_LIP_EXPRESSION_LE_BD => BlendShapeIndex.e,
                XrLipExpressionBD.XR_LIP_EXPRESSION_DD_BD => BlendShapeIndex.DD,
                XrLipExpressionBD.XR_LIP_EXPRESSION_E_BD => BlendShapeIndex.E,
                XrLipExpressionBD.XR_LIP_EXPRESSION_LNN_BD => BlendShapeIndex.nn,
                XrLipExpressionBD.XR_LIP_EXPRESSION_SIL_BD => BlendShapeIndex.sil,
                _ => throw new ArgumentOutOfRangeException(nameof(expression), expression, null)
            };
        }

        public static bool TryToXrFaceExpressionBD(this BlendShapeIndex index, out XrFaceExpressionBD expression)
        {
            switch (index)
            {
                case BlendShapeIndex.BrowDown_L: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_BROW_DROP_L_BD; return true;
                case BlendShapeIndex.BrowDown_R: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_BROW_DROP_R_BD; return true;
                case BlendShapeIndex.BrowInnerUp: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_BROW_INNER_UPWARDS_BD; return true;
                case BlendShapeIndex.BrowOuterUp_L: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_BROW_OUTER_UPWARDS_L_BD; return true;
                case BlendShapeIndex.BrowOuterUp_R: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_BROW_OUTER_UPWARDS_R_BD; return true;
                case BlendShapeIndex.EyeBlink_L: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_BLINK_L_BD; return true;
                case BlendShapeIndex.EyeLookDown_L: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_DROP_L_BD; return true;
                case BlendShapeIndex.EyeLookIn_L: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_IN_L_BD; return true;
                case BlendShapeIndex.EyeLookOut_L: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_OUT_L_BD; return true;
                case BlendShapeIndex.EyeLookUp_L: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_UPWARDS_L_BD; return true;
                case BlendShapeIndex.EyeSquint_L: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_SQUINT_L_BD; return true;
                case BlendShapeIndex.EyeWide_L: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_WIDE_L_BD; return true;
                case BlendShapeIndex.EyeBlink_R: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_BLINK_R_BD; return true;
                case BlendShapeIndex.EyeLookDown_R: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_DROP_R_BD; return true;
                case BlendShapeIndex.EyeLookIn_R: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_IN_R_BD; return true;
                case BlendShapeIndex.EyeLookOut_R: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_OUT_R_BD; return true;
                case BlendShapeIndex.EyeLookUp_R: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_UPWARDS_R_BD; return true;
                case BlendShapeIndex.EyeSquint_R: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_SQUINT_R_BD; return true;
                case BlendShapeIndex.EyeWide_R: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_EYE_LOOK_WIDE_R_BD; return true;
                case BlendShapeIndex.NoseSneer_L: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_NOSE_SNEER_L_BD; return true;
                case BlendShapeIndex.NoseSneer_R: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_NOSE_SNEER_R_BD; return true;
                case BlendShapeIndex.CheekPuff: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_CHEEK_PUFF_BD; return true;
                case BlendShapeIndex.CheekSquint_L: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_CHEEK_SQUINT_L_BD; return true;
                case BlendShapeIndex.CheekSquint_R: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_CHEEK_SQUINT_R_BD; return true;
                case BlendShapeIndex.MouthClose: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_CLOSE_BD; return true;
                case BlendShapeIndex.MouthFunnel: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_FUNNEL_BD; return true;
                case BlendShapeIndex.MouthPucker: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_PUCKER_BD; return true;
                case BlendShapeIndex.MouthLeft: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_L_BD; return true;
                case BlendShapeIndex.MouthRight: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_R_BD; return true;
                case BlendShapeIndex.MouthSmile_L: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_SMILE_L_BD; return true;
                case BlendShapeIndex.MouthSmile_R: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_SMILE_R_BD; return true;
                case BlendShapeIndex.MouthFrown_L: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_FROWN_L_BD; return true;
                case BlendShapeIndex.MouthFrown_R: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_FROWN_R_BD; return true;
                case BlendShapeIndex.MouthDimple_L: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_DIMPLE_L_BD; return true;
                case BlendShapeIndex.MouthDimple_R: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_DIMPLE_R_BD; return true;
                case BlendShapeIndex.MouthStretch_L: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_STRETCH_L_BD; return true;
                case BlendShapeIndex.MouthStretch_R: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_STRETCH_R_BD; return true;
                case BlendShapeIndex.MouthRollLower: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_ROLL_LOWER_BD; return true;
                case BlendShapeIndex.MouthRollUpper: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_ROLL_UPPER_BD; return true;
                case BlendShapeIndex.MouthShrugLower: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_SHRUG_LOWER_BD; return true;
                case BlendShapeIndex.MouthShrugUpper: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_SHRUG_UPPER_BD; return true;
                case BlendShapeIndex.MouthPress_L: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_PRESS_L_BD; return true;
                case BlendShapeIndex.MouthPress_R: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_PRESS_R_BD; return true;
                case BlendShapeIndex.MouthLowerDown_L: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_LOWER_DROP_L_BD; return true;
                case BlendShapeIndex.MouthLowerDown_R: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_LOWER_DROP_R_BD; return true;
                case BlendShapeIndex.MouthUpperUp_L: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_UPPER_UPWARDS_L_BD; return true;
                case BlendShapeIndex.MouthUpperUp_R: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_MOUTH_UPPER_UPWARDS_R_BD; return true;
                case BlendShapeIndex.JawForward: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_JAW_FORWARD_BD; return true;
                case BlendShapeIndex.JawLeft: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_JAW_L_BD; return true;
                case BlendShapeIndex.JawRight: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_JAW_R_BD; return true;
                case BlendShapeIndex.JawOpen: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_JAW_OPEN_BD; return true;
                case BlendShapeIndex.TongueOut: expression = XrFaceExpressionBD.XR_FACE_EXPRESSION_TONGUE_OUT_BD; return true;
                default:
                    expression = default;
                    return false;
            }
        }

        public static bool TryToXrLipExpressionBD(this BlendShapeIndex index, out XrLipExpressionBD expression)
        {
            switch (index)
            {
                case BlendShapeIndex.PP: expression = XrLipExpressionBD.XR_LIP_EXPRESSION_PP_BD; return true;
                case BlendShapeIndex.CH: expression = XrLipExpressionBD.XR_LIP_EXPRESSION_CH_BD; return true;
                case BlendShapeIndex.o: expression = XrLipExpressionBD.XR_LIP_EXPRESSION_LO_BD; return true;
                case BlendShapeIndex.O: expression = XrLipExpressionBD.XR_LIP_EXPRESSION_O_BD; return true;
                case BlendShapeIndex.I: expression = XrLipExpressionBD.XR_LIP_EXPRESSION_I_BD; return true;
                case BlendShapeIndex.u: expression = XrLipExpressionBD.XR_LIP_EXPRESSION_LU_BD; return true;
                case BlendShapeIndex.RR: expression = XrLipExpressionBD.XR_LIP_EXPRESSION_RR_BD; return true;
                case BlendShapeIndex.XX: expression = XrLipExpressionBD.XR_LIP_EXPRESSION_XX_BD; return true;
                case BlendShapeIndex.aa: expression = XrLipExpressionBD.XR_LIP_EXPRESSION_LAA_BD; return true;
                case BlendShapeIndex.i: expression = XrLipExpressionBD.XR_LIP_EXPRESSION_LI_BD; return true;
                case BlendShapeIndex.FF: expression = XrLipExpressionBD.XR_LIP_EXPRESSION_FF_BD; return true;
                case BlendShapeIndex.U: expression = XrLipExpressionBD.XR_LIP_EXPRESSION_U_BD; return true;
                case BlendShapeIndex.TH: expression = XrLipExpressionBD.XR_LIP_EXPRESSION_TH_BD; return true;
                case BlendShapeIndex.kk: expression = XrLipExpressionBD.XR_LIP_EXPRESSION_LKK_BD; return true;
                case BlendShapeIndex.SS: expression = XrLipExpressionBD.XR_LIP_EXPRESSION_SS_BD; return true;
                case BlendShapeIndex.e: expression = XrLipExpressionBD.XR_LIP_EXPRESSION_LE_BD; return true;
                case BlendShapeIndex.DD: expression = XrLipExpressionBD.XR_LIP_EXPRESSION_DD_BD; return true;
                case BlendShapeIndex.E: expression = XrLipExpressionBD.XR_LIP_EXPRESSION_E_BD; return true;
                case BlendShapeIndex.nn: expression = XrLipExpressionBD.XR_LIP_EXPRESSION_LNN_BD; return true;
                case BlendShapeIndex.sil: expression = XrLipExpressionBD.XR_LIP_EXPRESSION_SIL_BD; return true;
                default:
                    expression = default;
                    return false;
            }
        }
    }
}
