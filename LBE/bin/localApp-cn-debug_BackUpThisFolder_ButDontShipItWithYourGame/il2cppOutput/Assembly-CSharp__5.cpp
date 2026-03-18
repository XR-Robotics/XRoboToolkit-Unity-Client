#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>


template <typename T1, typename T2>
struct VirtualActionInvoker2
{
	typedef void (*Action)(void*, T1, T2, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj, p1, p2, invokeData.method);
	}
};
template <typename R>
struct VirtualFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename T1, typename T2>
struct GenericVirtualActionInvoker2
{
	typedef void (*Action)(void*, T1, T2, const RuntimeMethod*);

	static inline void Invoke (const RuntimeMethod* method, RuntimeObject* obj, T1 p1, T2 p2)
	{
		VirtualInvokeData invokeData;
		il2cpp_codegen_get_generic_virtual_invoke_data(method, obj, &invokeData);
		((Action)invokeData.methodPtr)(obj, p1, p2, invokeData.method);
	}
};
template <typename T1, typename T2>
struct InterfaceActionInvoker2
{
	typedef void (*Action)(void*, T1, T2, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, p1, p2, invokeData.method);
	}
};
template <typename T1, typename T2>
struct GenericInterfaceActionInvoker2
{
	typedef void (*Action)(void*, T1, T2, const RuntimeMethod*);

	static inline void Invoke (const RuntimeMethod* method, RuntimeObject* obj, T1 p1, T2 p2)
	{
		VirtualInvokeData invokeData;
		il2cpp_codegen_get_generic_interface_invoke_data(method, obj, &invokeData);
		((Action)invokeData.methodPtr)(obj, p1, p2, invokeData.method);
	}
};
template <typename T1>
struct InvokerActionInvoker1
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1 p1)
	{
		void* params[1] = { &p1 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};
template <typename T1, typename T2>
struct InvokerActionInvoker2
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1 p1, T2 p2)
	{
		void* params[2] = { &p1, &p2 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};
template <typename T1, typename T2>
struct InvokerActionInvoker2<T1*, T2>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2 p2)
	{
		void* params[2] = { p1, &p2 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};
template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3;
template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3<T1*, T2, T3>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2 p2, T3 p3)
	{
		void* params[3] = { p1, &p2, &p3 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};
template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3<T1, T2*, T3*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1 p1, T2* p2, T3* p3)
	{
		void* params[3] = { &p1, p2, p3 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};
template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3<T1*, T2*, T3*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2, T3* p3)
	{
		void* params[3] = { p1, p2, p3 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};
template <typename T1, typename T2, typename T3, typename T4>
struct InvokerActionInvoker4;
template <typename T1, typename T2, typename T3, typename T4>
struct InvokerActionInvoker4<T1*, T2, T3*, T4*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2 p2, T3* p3, T4* p4)
	{
		void* params[4] = { p1, &p2, p3, p4 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};
template <typename T1, typename T2, typename T3, typename T4>
struct InvokerActionInvoker4<T1*, T2*, T3*, T4*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2, T3* p3, T4* p4)
	{
		void* params[4] = { p1, p2, p3, p4 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};

// <>f__AnonymousType0`1<System.Int32>
struct U3CU3Ef__AnonymousType0_1_tCC81029179B6F4DAC7D8BC271C35F5CDBC097D55;
// System.Action`1<System.Boolean>
struct Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C;
// System.Action`1<System.Int32>
struct Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404;
// System.Action`1<UnityEngine.XR.Interaction.Toolkit.InteractorRegisteredEventArgs>
struct Action_1_tBE7729820CBA793D8D5D57207BA5938B012863C5;
// System.Action`1<UnityEngine.XR.Interaction.Toolkit.InteractorUnregisteredEventArgs>
struct Action_1_t9A06C49FCB3ADF4C984887951A3DC1DA07CFFBF0;
// System.Action`1<System.Single>
struct Action_1_t310F18CB4338A2740CA701F160C62E2C3198E66A;
// System.Action`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo>
struct Action_1_t1EE3C77B386F0D0C621A13E4401EC8A7E3819D93;
// Unity.XR.CoreUtils.Bindings.Variables.BindableVariable`1<System.Single>
struct BindableVariable_1_tAB8C2D23769D801C8E39D4AA927DD23AF0E6816C;
// System.Collections.Concurrent.ConcurrentDictionary`2<System.String,Jeffijoe.MessageFormat.Parsing.IFormatterRequestCollection>
struct ConcurrentDictionary_2_t11BB466A2D80E315699FA0821C3DDBC98A586DC0;
// System.Collections.Generic.Dictionary`2<UnityEngine.XR.Interaction.Toolkit.IXRInteractable,System.Single>
struct Dictionary_2_tEABA4693399BB94F9F9031F041277F4D01CA9BB2;
// System.Collections.Generic.Dictionary`2<UnityEngine.XR.Interaction.Toolkit.IXRSelectInteractable,UnityEngine.Pose>
struct Dictionary_2_tC8CDB97AFC9E538A6AF3126874A321065572174C;
// System.Collections.Generic.Dictionary`2<System.Int32,System.Object>
struct Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907;
// System.Collections.Generic.Dictionary`2<System.Int32,com.picoxr.tobframwork.Timer/Handle>
struct Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6;
// System.Collections.Generic.Dictionary`2<System.Object,System.Int32>
struct Dictionary_2_t5C96F4B6841710A9013966F76224BAE01FB4B4D1;
// System.Collections.Generic.Dictionary`2<System.Object,System.Object>
struct Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA;
// System.Collections.Generic.Dictionary`2<System.String,System.Delegate>
struct Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6;
// System.Collections.Generic.Dictionary`2<System.Type,System.Int32>
struct Dictionary_2_t384D2A0FF42BF1302A3F513FC32DB105F1CD5455;
// System.Collections.Generic.Dictionary`2<System.Type,com.picoxr.tobframwork.UIPage>
struct Dictionary_2_t1BF400F50D50E19CF6FCD3FF520384A96269F89F;
// UnityEngine.XR.Interaction.Toolkit.Utilities.ExposedRegistrationList`1<UnityEngine.XR.Interaction.Toolkit.Filtering.IXRHoverFilter>
struct ExposedRegistrationList_1_t11A438A04DF188A3BE1950639AAF0CBFAF9065A5;
// UnityEngine.XR.Interaction.Toolkit.Utilities.ExposedRegistrationList`1<UnityEngine.XR.Interaction.Toolkit.Filtering.IXRSelectFilter>
struct ExposedRegistrationList_1_t0AF641D8E06922C1FFAF3DA223105F57CE5BC4D8;
// Unity.XR.CoreUtils.Collections.HashSetList`1<UnityEngine.XR.Interaction.Toolkit.IXRHoverInteractable>
struct HashSetList_1_tC521CA1513DA32AFAD8144C7529793E24EA52945;
// Unity.XR.CoreUtils.Collections.HashSetList`1<UnityEngine.XR.Interaction.Toolkit.IXRInteractionStrengthInteractable>
struct HashSetList_1_tC1867B681AE7023306C341F97E7483BB3C8532B2;
// Unity.XR.CoreUtils.Collections.HashSetList`1<UnityEngine.XR.Interaction.Toolkit.IXRSelectInteractable>
struct HashSetList_1_t4D485A2E14AF33326E4D8B5E60BEDD0E47CEE3F0;
// System.Collections.Generic.HashSet`1<UnityEngine.Collider>
struct HashSet_1_t109CCE87260348881F7ED50EEE3FFD003542DC8B;
// System.Collections.Generic.IEnumerable`1<System.Delegate>
struct IEnumerable_1_tAF3C8B37028E582F90B53E0593D7286ABE98D722;
// System.Collections.Generic.IEnumerable`1<System.Object>
struct IEnumerable_1_tF95C9E01A913DD50575531C8305932628663D9E9;
// System.Collections.Generic.IEqualityComparer`1<System.Int32>
struct IEqualityComparer_1_tDBFC8496F14612776AF930DBF84AFE7D06D1F0E9;
// System.Collections.Generic.IEqualityComparer`1<System.String>
struct IEqualityComparer_1_tAE94C8F24AD5B94D4EE85CA9FC59E3409D41CAF7;
// System.Collections.Generic.IEqualityComparer`1<System.Type>
struct IEqualityComparer_1_t0C79004BFE79D9DBCE6C2250109D31D468A9A68E;
// System.Collections.Generic.Dictionary`2/KeyCollection<System.Int32,com.picoxr.tobframwork.Timer/Handle>
struct KeyCollection_tB57895601DB66AA6C52845C41D23126AF09E83FC;
// System.Collections.Generic.Dictionary`2/KeyCollection<System.String,System.Delegate>
struct KeyCollection_t29B1E367D95E46B2E45B4C33E1F3C5644F15EC98;
// System.Collections.Generic.Dictionary`2/KeyCollection<System.Type,System.Int32>
struct KeyCollection_tE2F56A37776137F5D3C1BA6C49999EF1EC0E216F;
// System.Collections.Generic.Dictionary`2/KeyCollection<System.Type,com.picoxr.tobframwork.UIPage>
struct KeyCollection_tE3802AACC5EA3577CD36EBE3E85965902C414BFE;
// UnityEngine.XR.Interaction.Toolkit.Utilities.Pooling.LinkedPool`1<UnityEngine.XR.Interaction.Toolkit.ActivateEventArgs>
struct LinkedPool_1_t99CFF33CB8085652A0F2FC6579D0388FB3CBAA01;
// UnityEngine.XR.Interaction.Toolkit.Utilities.Pooling.LinkedPool`1<UnityEngine.XR.Interaction.Toolkit.DeactivateEventArgs>
struct LinkedPool_1_t0F5C109EA19EF35798DEF24B63645919D0B7B53B;
// System.Collections.Generic.List`1<System.Collections.Generic.List`1<System.Int32>>
struct List_1_tB5A0E21D0A7C39DF93D616FD5B94C4737A083E35;
// System.Collections.Generic.List`1<System.Collections.Generic.List`1<System.Single>>
struct List_1_tFF2BC422A193D7F048E03ABCCC32292E892A12F7;
// System.Collections.Generic.List`1<System.Collections.Generic.List`1<UnityEngine.Vector3>>
struct List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F;
// System.Collections.Generic.List`1<Boundary.Data.BoundaryItem>
struct List_1_t9B1B27900D11844BED9AD08E793EE74AB63688C5;
// System.Collections.Generic.List`1<UnityEngine.XR.Interaction.Toolkit.IXRActivateInteractable>
struct List_1_tAB2FD3FF9900A585A26C6DC2D8EE94D30F2AECCA;
// System.Collections.Generic.List`1<UnityEngine.XR.Interaction.Toolkit.IXRInteractable>
struct List_1_t3B3CED900C4A273E3B63AAB5493C4D6D4B112810;
// System.Collections.Generic.List`1<UnityEngine.XR.Interaction.Toolkit.IXRSelectInteractable>
struct List_1_tC3FDFEE51803D5C604CED1C088BC2B8A566E0E5B;
// System.Collections.Generic.List`1<System.Int32>
struct List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73;
// System.Collections.Generic.List`1<Boundary.Data.Item>
struct List_1_tDCE834B5223117F51ED29F0327C1C20731F3D0CD;
// System.Collections.Generic.List`1<System.Object>
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D;
// System.Collections.Generic.List`1<UnityEngine.Object>
struct List_1_t9A2E2984B23260AECDFA90CEB1F2887075FA4DF3;
// System.Collections.Generic.List`1<UnityEngine.Vector3>
struct List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B;
// System.Collections.Generic.List`1<UnityEngine.XR.Interaction.Toolkit.XRBaseInteractable>
struct List_1_t02510C493B34D49F210C22C40442D863A08509CB;
// System.Collections.Generic.List`1<com.picoxr.tobframwork.Timer/Handle>
struct List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5;
// System.Collections.Generic.List`1<UnityEngine.XR.Interaction.Toolkit.XRRayInteractor/SamplePoint>
struct List_1_tC0F6311D5ACC55EC4184D225E50673DBDAC555BD;
// System.Collections.Generic.Queue`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo>
struct Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.Int32,com.picoxr.tobframwork.Timer/Handle>
struct ValueCollection_t116A43BE8D6490021446FC80915F6E1A0A39CB40;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.String,System.Delegate>
struct ValueCollection_t6C0A84D04F87D3A05857431804390724962C3F6F;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.Type,System.Int32>
struct ValueCollection_tAD56DF94D7373625A22E80E942606DC8509CB6D2;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.Type,com.picoxr.tobframwork.UIPage>
struct ValueCollection_t4D47B859E1DE64BE6F72446E09432F17759FAC00;
// System.Collections.Generic.Dictionary`2/Entry<System.Int32,com.picoxr.tobframwork.Timer/Handle>[]
struct EntryU5BU5D_tE38603B97779B846C497E38D2FAB43CA13D444C4;
// System.Collections.Generic.Dictionary`2/Entry<System.String,System.Delegate>[]
struct EntryU5BU5D_tBACA0DA26A77797D416943C38A345F0E2F0BD9F4;
// System.Collections.Generic.Dictionary`2/Entry<System.Type,System.Int32>[]
struct EntryU5BU5D_tD80C7495BA8BE64BC139A54FA961AB3EC66D7319;
// System.Collections.Generic.Dictionary`2/Entry<System.Type,com.picoxr.tobframwork.UIPage>[]
struct EntryU5BU5D_t6743F267FE53E639AADC75D64CDEAF2DF5A76EF9;
// System.Collections.Generic.List`1<System.Int32>[]
struct List_1U5BU5D_t37294D7C303231F2FD83B3C398AED0937F4F3206;
// System.Collections.Generic.List`1<System.Single>[]
struct List_1U5BU5D_tB3324071AD89A3E4C72B73C6C5D42DCAC9EC993F;
// System.Collections.Generic.List`1<UnityEngine.Vector3>[]
struct List_1U5BU5D_tC1B009E92641A2C993F3BB28A80D61D2AB67979B;
// System.Boolean[]
struct BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4;
// Boundary.Data.BoundaryItem[]
struct BoundaryItemU5BU5D_tFA1A2813C2E9A578225D157CCDC1532B27EC7221;
// System.Byte[]
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
// System.Char[]
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
// System.Delegate[]
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
// System.Int32[]
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
// System.IntPtr[]
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
// Boundary.Data.Item[]
struct ItemU5BU5D_t1BB908030FAE0B323EDC9CD4CE537EB6B9A6CB49;
// System.Object[]
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
// UnityEngine.RaycastHit[]
struct RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8;
// System.Diagnostics.StackTrace[]
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
// System.String[]
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
// System.Type[]
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
// com.picoxr.tobframwork.UIPage[]
struct UIPageU5BU5D_t7F52BDD6ABCD90C3DC53772307DC5681B3D58496;
// UnityEngine.Vector3[]
struct Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C;
// Unity.Mathematics.float3[]
struct float3U5BU5D_t94C1DF28FA7E0FA017D0C77B720D9FF3519E0D45;
// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALine[]
struct GSALineU5BU5D_tC2644452FF1B88D2D201F355FA28F65A5D8CF685;
// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i[]
struct GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1;
// com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo[]
struct TextureInfoU5BU5D_tC46E5F4213D1A76EC15060BD225B8C7D54235C82;
// com.picoxr.tobframwork.Timer/Handle[]
struct HandleU5BU5D_t32660A977D98D1266A234A1C5378D6A41C9A30C7;
// System.Action
struct Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07;
// UnityEngine.XR.Interaction.Toolkit.ActionBasedController
struct ActionBasedController_tB9D8E7E013191571EA5507EA68057414B6969A68;
// Boundary.Data.AlgorithmData
struct AlgorithmData_tBED6E92124E6F80F7B4862A143CCAB790E87DC35;
// UnityEngine.AndroidJavaClass
struct AndroidJavaClass_tE6296B30CC4BF84434A9B765267F3FD0DD8DDB03;
// UnityEngine.AndroidJavaObject
struct AndroidJavaObject_t8FFB930F335C1178405B82AC2BF512BB1EEF9EB0;
// System.AsyncCallback
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C;
// UnityEngine.AudioClip
struct AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20;
// UnityEngine.AudioSource
struct AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299;
// UnityEngine.EventSystems.BaseRaycaster
struct BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832;
// System.Reflection.Binder
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
// Boundary.Data.BoundaryConfigData
struct BoundaryConfigData_t4201DE14529DC1A53FF80BAB4E8019BE6D226748;
// Boundary.Data.BoundaryData
struct BoundaryData_tDC8C8A6879E571C7A509C93AA6737D479B27F1A9;
// Boundary.Data.BoundaryItem
struct BoundaryItem_t4F4A542118E39B1229AFC8916C2D37333E0A7E68;
// UnityEngine.Component
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3;
// Jeffijoe.MessageFormat.CustomValueFormatter
struct CustomValueFormatter_tBD981B5F72D8EADB8B6258BE76BEBEE7EF2403AC;
// System.Delegate
struct Delegate_t;
// System.DelegateData
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
// System.Enum
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2;
// com.picoxr.tobframwork.EventManager
struct EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5;
// UnityEngine.GameObject
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F;
// UnityEngine.XR.Interaction.Toolkit.HoverEnterEvent
struct HoverEnterEvent_t2BDBCA14FF94DA18C9AC12B43297F6C1641788AB;
// UnityEngine.XR.Interaction.Toolkit.HoverExitEvent
struct HoverExitEvent_t256704BC79FE0AA61EB2DE3FDDF43A1FC97F5832;
// System.IAsyncResult
struct IAsyncResult_t7B9B5A0ECB35DCEC31B8A8122C37D687369253B5;
// System.Collections.IDictionary
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
// Jeffijoe.MessageFormat.Formatting.IFormatterLibrary
struct IFormatterLibrary_tDA940B81494B37C0847BBAFAAD65C0CBC8695B68;
// Jeffijoe.MessageFormat.IMessageFormatter
struct IMessageFormatter_t78DF488C7418839D7CA6035DB1101ECA629AAEA3;
// Jeffijoe.MessageFormat.Parsing.IPatternParser
struct IPatternParser_tA0597964D4D3EE474A45A2BDA625A4E8BA5AF7C9;
// UnityEngine.XR.Interaction.Toolkit.IXRInteractable
struct IXRInteractable_t31CD4FF4D45899471D81D43D605D9C6118BF50CA;
// UnityEngine.XR.Interaction.Toolkit.IXRInteractionGroup
struct IXRInteractionGroup_tAD9069A6C37036CE5C97D68CF2F97B1F25044D5D;
// UnityEngine.XR.Interaction.Toolkit.IXRSelectInteractable
struct IXRSelectInteractable_t588B8BE99E84540D5A1A9D6E5AAC9EDF12985735;
// UnityEngine.XR.Interaction.Toolkit.Filtering.IXRTargetFilter
struct IXRTargetFilter_t51750E0C671ECA90F38CC75BCD395285E61D2778;
// Boundary.Data.Item
struct Item_t51A6B6268FD582ED0ADB924808FCA5449EE278F4;
// com.picoxr.tobframwork.LanguageUtils
struct LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D;
// System.Reflection.MemberFilter
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
// Jeffijoe.MessageFormat.MessageFormatter
struct MessageFormatter_t59AB4D9D22B9B2403C45FF755A0AB60223D2035F;
// System.Reflection.MethodInfo
struct MethodInfo_t;
// UnityEngine.MonoBehaviour
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71;
// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C;
// BoundarySystem_Ext.Pvr_BoundarySystem
struct Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544;
// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule
struct Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05;
// com.picoxr.tobframwork.RayHitPoint
struct RayHitPoint_t4906E263121D0B6973D5818145F76E7E3DD1C9CE;
// UnityEngine.XR.Interaction.Toolkit.UI.RegisteredUIInteractorCache
struct RegisteredUIInteractorCache_t81419313AA113B206AF3FF94CD9D3B64A09CE413;
// System.Runtime.Serialization.SafeSerializationManager
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
// UnityEngine.XR.Interaction.Toolkit.SelectEnterEvent
struct SelectEnterEvent_tBA2614C8C25D8794D5804C4F66195D74E64FC5D0;
// UnityEngine.XR.Interaction.Toolkit.SelectExitEvent
struct SelectExitEvent_t15DC0A39F9657BA9E6BAE6250D8D64C9671201F6;
// com.picoxr.blsapce.SpatialTextureMain
struct SpatialTextureMain_tA0B9AB4FB7C9920C93B5AEE43B3F12BFE42C57DB;
// com.picoxr.blsapce.SpatialTextureToSystem
struct SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3;
// System.String
struct String_t;
// System.Text.StringBuilder
struct StringBuilder_t;
// com.picoxr.tobframwork.Timer
struct Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0;
// UnityEngine.Transform
struct Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1;
// System.Type
struct Type_t;
// com.picoxr.tobframwork.UIGroup
struct UIGroup_tC217247301A179C554813A009381C0404ECC1DDF;
// UnityEngine.XR.Interaction.Toolkit.UI.UIHoverEnterEvent
struct UIHoverEnterEvent_t4C957A3405A5D9CB867C5EC446620BB4BA7E7298;
// UnityEngine.XR.Interaction.Toolkit.UI.UIHoverExitEvent
struct UIHoverExitEvent_t63E5E9C921AFB8E2CB9CA4D32882DD4F62CD509B;
// com.picoxr.tobframwork.UIPage
struct UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387;
// com.picoxr.tobframwork.UIPageManager
struct UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B;
// com.picoxr.tobframwork.Unitls
struct Unitls_t2BA1216F702C7798ED366C4C77A5148AE77216A8;
// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
// UnityEngine.XR.Interaction.Toolkit.XRBaseController
struct XRBaseController_t44C1BB30A7E1D279DD2508F34D3352B33A9AD60C;
// UnityEngine.XR.Interaction.Toolkit.XRBaseInteractable
struct XRBaseInteractable_tC2C966C710AE6AC232E248B1BCF323386110D0F6;
// UnityEngine.XR.Interaction.Toolkit.Filtering.XRBaseTargetFilter
struct XRBaseTargetFilter_t24D9DBCEA900DFEA08D543C91DFC070C1C91594F;
// UnityEngine.XR.Interaction.Toolkit.XRController
struct XRController_t928E104C899E51FDE12C0A8AC68874587C46C28F;
// UnityEngine.XR.Interaction.Toolkit.XRInteractionManager
struct XRInteractionManager_t93C7F7F0CFEAD83E1A70F92D05B0E663483746CD;
// UnityEngine.XR.Interaction.Toolkit.XRInteractorEvent
struct XRInteractorEvent_tA90E755406526412871F25BB621E7F4536CD00E2;
// UnityEngine.XR.Interaction.Toolkit.XRRayInteractor
struct XRRayInteractor_t0B25C1D5A938B199A71908E189AB351B43DA4C76;
// UnityEngine.XR.Interaction.Toolkit.XRScreenSpaceController
struct XRScreenSpaceController_t046F18C2FE01EB347832DB82D42C84131771FF17;
// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallback
struct SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C;
// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallbackShrink
struct SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754;
// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundarySystemCallback
struct BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD;
// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundarySystemCallbackShrink
struct BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75;
// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/ExtraInfo
struct ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54;
// com.picoxr.blsapce.SpatialTextureToSystem/CallBackDelegate
struct CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC;
// com.picoxr.tobframwork.Timer/Handle
struct Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5;
// UnityEngine.XR.Interaction.Toolkit.XRRayInteractor/RaycastHitComparer
struct RaycastHitComparer_tC59C36D577B7426F5EE8E3AE65B988F953757E9D;

IL2CPP_EXTERN_C RuntimeClass* Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Action_1_t1EE3C77B386F0D0C621A13E4401EC8A7E3819D93_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2_t1BF400F50D50E19CF6FCD3FF520384A96269F89F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2_t384D2A0FF42BF1302A3F513FC32DB105F1CD5455_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Exception_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GSALineU5BU5D_tC2644452FF1B88D2D201F355FA28F65A5D8CF685_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IntPtr_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* LocalizationTool_t7DBF16B905FAD36B32A980793330018B6CFC44A2_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* MessageFormatter_t59AB4D9D22B9B2403C45FF755A0AB60223D2035F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ScanState_tC2A7E771A0FB73056F3BFF17BFB32A3D7B9184BB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringBuilder_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* System_t4255BA2E24C230336F7C003E6DD13B25588178DB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* TextureLevelType_t9605D1AFDEBBBAA51AAC3F4AA94492ED053FBE8B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Type_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CU3Ef__AnonymousType0_1_tCC81029179B6F4DAC7D8BC271C35F5CDBC097D55_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral00B28FF06B788B9B67C6B259800F404F9F3761FD;
IL2CPP_EXTERN_C String_t* _stringLiteral02E24DDAA670412016D1B7AE4DA2B990261581AF;
IL2CPP_EXTERN_C String_t* _stringLiteral07D4E98E332EC0D17F8FB3F458B42EBB2C4EAF29;
IL2CPP_EXTERN_C String_t* _stringLiteral0B0D645C93F6D3B9458F33B2DFB8210A46C123F7;
IL2CPP_EXTERN_C String_t* _stringLiteral0F7D01CDED5602DC095024EB991F40C9D3A564B3;
IL2CPP_EXTERN_C String_t* _stringLiteral132195FDF8564E10AC7A2AFE7D2DB7C9BEA52DD2;
IL2CPP_EXTERN_C String_t* _stringLiteral1F5F89035B9A8102A656517DE605AA84A1A3A454;
IL2CPP_EXTERN_C String_t* _stringLiteral2386E77CF610F786B06A91AF2C1B3FD2282D2745;
IL2CPP_EXTERN_C String_t* _stringLiteral2CF2ABA8D917B10559A7EA55260971A03AA54AB5;
IL2CPP_EXTERN_C String_t* _stringLiteral307E4E9ED9EDF0491BA858A2CD1BC00E65FFA257;
IL2CPP_EXTERN_C String_t* _stringLiteral31C00001AA53ABB55EC8A399C462608AA8FE077A;
IL2CPP_EXTERN_C String_t* _stringLiteral3BD04D31675F8DF792A6C8A1153D895FE991A0A3;
IL2CPP_EXTERN_C String_t* _stringLiteral42559C2140EDFAB50DB6AE7DCF62B93B4DA42968;
IL2CPP_EXTERN_C String_t* _stringLiteral43EF9CFD5F4CF32E84213BE3484FCAD18DCDC3EE;
IL2CPP_EXTERN_C String_t* _stringLiteral47DAD2DC5D493BB0500F8358F87D18769C0769BA;
IL2CPP_EXTERN_C String_t* _stringLiteral4CDCDF88C3C531360CF21120C5C3AEE6B6FB27A2;
IL2CPP_EXTERN_C String_t* _stringLiteral4F6EF6B8FCA2DF0D1B799A9EEBFC44CA196D1B74;
IL2CPP_EXTERN_C String_t* _stringLiteral52DD90E356E26DE0E1D7BC521CBAC1ED5D677D4D;
IL2CPP_EXTERN_C String_t* _stringLiteral551354F804B6BDEA008C4C36F589CEC4A07FFD4A;
IL2CPP_EXTERN_C String_t* _stringLiteral587DC89F824CC86773888F46D34374A78EB6E433;
IL2CPP_EXTERN_C String_t* _stringLiteral5C80B10EDFAF8B92E4363946E9D63233E65D691F;
IL2CPP_EXTERN_C String_t* _stringLiteral5F329E7A2983074AA233A92603C370A5AF39DD05;
IL2CPP_EXTERN_C String_t* _stringLiteral698465F560A6DD0E0808454A77676B2FF6CF16E4;
IL2CPP_EXTERN_C String_t* _stringLiteral6DE8DD1886BBF05CE4638B678071D70F7A706931;
IL2CPP_EXTERN_C String_t* _stringLiteral6E16C4C2594F76B5D6EEFC421689AE28C6AD5D0D;
IL2CPP_EXTERN_C String_t* _stringLiteral708B7431D97D837F21F808E2619E983B0FA9B7F4;
IL2CPP_EXTERN_C String_t* _stringLiteral7A805D623CF373F194487BF7035FA94ADF5E5C9B;
IL2CPP_EXTERN_C String_t* _stringLiteral81C5F640B84128CAF1CF95585CFC17A20C6F262A;
IL2CPP_EXTERN_C String_t* _stringLiteral87156C7367168BB1A9532BE4E84C37170C423556;
IL2CPP_EXTERN_C String_t* _stringLiteral8784BB62541B5BDD09FFAB9A87B1EBBE14156566;
IL2CPP_EXTERN_C String_t* _stringLiteral940684AC39F0F6E67443D7A7AE8BCC0443B07B86;
IL2CPP_EXTERN_C String_t* _stringLiteral9CB459ADC305561267AD22C5CC73F6F88CA38134;
IL2CPP_EXTERN_C String_t* _stringLiteralA9312B81EA200B982D376EFED9466966CAEF31CC;
IL2CPP_EXTERN_C String_t* _stringLiteralABEA19C219C733FF3FE45E06F0F298F769041ABD;
IL2CPP_EXTERN_C String_t* _stringLiteralB0A16419399D9150913BC905D0DA4EF93DB44958;
IL2CPP_EXTERN_C String_t* _stringLiteralBC77136E09CE6E2CA8BC7074AD23EE15709847E9;
IL2CPP_EXTERN_C String_t* _stringLiteralC368529EFBEDA8057918D749B143C32B739CE4A9;
IL2CPP_EXTERN_C String_t* _stringLiteralC6387E9C5A822DD5AA6EEBF9DF80A690DBC81B7E;
IL2CPP_EXTERN_C String_t* _stringLiteralC6DE535D828F30C374EB3BE3FFDE520228FC3096;
IL2CPP_EXTERN_C String_t* _stringLiteralC6F551CEE034848BB7699CB3BD3517BE37BCBB45;
IL2CPP_EXTERN_C String_t* _stringLiteralCA5A84BD2449CEC8316496E6966EF088F55F1688;
IL2CPP_EXTERN_C String_t* _stringLiteralCDF1157616009A2B26E7D53D070334F4188B9624;
IL2CPP_EXTERN_C String_t* _stringLiteralCEAFFB1A5B2970796F2CD60BE8C4BD9D6BCA9431;
IL2CPP_EXTERN_C String_t* _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709;
IL2CPP_EXTERN_C String_t* _stringLiteralDD3558EBAC9E15A5DECBC18AA71DAD6DF0F7CE66;
IL2CPP_EXTERN_C String_t* _stringLiteralDFCF5C8693CD5D607CE4AF43C48DAA6C9B24A959;
IL2CPP_EXTERN_C String_t* _stringLiteralDFF981EBDBDEC964BB46EFD6C842AA2F2BC59425;
IL2CPP_EXTERN_C String_t* _stringLiteralE2E7949F16C14C19C531338CF881B2DF2F6F9052;
IL2CPP_EXTERN_C String_t* _stringLiteralEAA0AD4C9DDC7B173ACD12710BBE084A3B32C5F6;
IL2CPP_EXTERN_C String_t* _stringLiteralEFC88795E0479464AC4E9B8B031D9720CE94E3C5;
IL2CPP_EXTERN_C String_t* _stringLiteralF3E84B722399601AD7E281754E917478AA9AD48D;
IL2CPP_EXTERN_C String_t* _stringLiteralF451A5CBDC80A01890663D7E00C100CC766F460E;
IL2CPP_EXTERN_C String_t* _stringLiteralF4A6F683F4A7F6B8CF4C7B36D6FB9DC9FE6770D2;
IL2CPP_EXTERN_C String_t* _stringLiteralF69B7FD4DC0E47B3768005646AEE819A970AE1F3;
IL2CPP_EXTERN_C String_t* _stringLiteralFDB79CD128E738BD4E720C3243B9DD2867D1504E;
IL2CPP_EXTERN_C const RuntimeMethod* Component_GetComponentInParent_TisUIGroup_tC217247301A179C554813A009381C0404ECC1DDF_mE896505A28C23576CBC229CC8A54B6429415E378_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Component_GetComponent_TisXRRayInteractor_t0B25C1D5A938B199A71908E189AB351B43DA4C76_m0347BCF4E0361AA2A76B2D7C9C21327E8C4ADFE4_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Component_GetComponentsInChildren_TisUIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387_m94464D52C05DF542C9B351530FA9E1E517AD9265_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Add_m127CA9CF3BF949F685FC3BC47942C2EAB717A1B7_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Add_mF5BAF98BB9FA8006CAAA49255DB0A4564F5EB444_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Add_mFC740DC4B588DEACABD94E8C79C0DD26C7065799_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Clear_mA5ED112FDE23E98A0E9A24339BF83DC1E0D2AB04_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_ContainsKey_mF167985044EB36A7BE3A47902F46FCEBAA42BFF3_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_GetEnumerator_m270AF704B3913CD85D83DD9FFF33D86EFEA32AFF_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Remove_m1BF02B71B85F664D88F7EE0AA5733E7F013C81E3_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Remove_mD553250DE5E74AB751576D4DFA330B74162C8926_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_TryGetValue_m347E8803DB0864154991F6FB10D201FD8D4D4AC3_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_TryGetValue_m3EF4F6B2EC138E3A20BD7549CE6DE54B0608CD4D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_TryGetValue_mB9EEAAD08A35C274F212D4C739347DE6120A6C2B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_TryGetValue_mEC9E9DC5A9A7DC8EC9D73564D35C0CEB7182ED6B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_m0AF6A9E01056850C9F7AE464B4099CA3F6D5E8EC_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_m1499CB733B03C3B63D06D1A01E35197AC21B59BD_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_m94EDCF44D203BF48FDAEAEB36F5DB4BF67E17CAA_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_mC11B8D87D7D6237273D0616824847584DA85B003_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_get_Item_m3F278CCF586B177F156F2E6AB38D00CA6E002B15_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_get_Item_mD9FD66064367BDD11E0CBCA5D45B14FCFE58DD57_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_set_Item_m0F4F2D2F1BEB8E000743301197554FD90E83F8A2_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_set_Item_m523CB8EB40145B2FB212BB32F0E7B19E62D582BD_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerable_Contains_TisDelegate_t_mFF006746882AAD944ED5B3D2CE5531200BE7F92B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_MoveNext_m7E56A8F9E76BB0BBBB349B08ED376B19C973EF53_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_get_Current_mA55505E5DED43F682FF4A841E7E1B29506D44D22_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* GameObject_AddComponent_TisTimer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0_m66276B9B1490B3979BF93ED13478B3B3E58EA41C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* GameObject_GetComponentsInChildren_TisUIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387_mD11B8C3BB77751DD9FC69ABF4546E706BBEF1F2A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* KeyValuePair_2_get_Value_mE69B7D19A7BC4B402D3F61148E96B3509CB69FAC_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m79E50C4F592B1703F4B76A8BE7B4855515460CA1_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m8B5DEF3F8F4F49003BB953399B6E84A6DC941AC6_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_mAA50EFD5EEC9735C47DD68C4CC4DEB3CCFE01C98_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_RemoveAt_m76C4CDACF47BA529BAFADFC8D5E13DB9587F4004_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_RemoveAt_mD9D3FCCCEBDF9E17EEE5A8CB0656F195F585AD3D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_m17F501B5A5C289ECE1B4F3D6EBF05DFA421433F8_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_mA02C96C46346D3D1952391F0E97ACFA08A59E206_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_mBE9255218FAB0B859E0DD1B944986BBC7F1C3A33_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_mC54E2BCBE43279A96FC082F5CDE2D76388BD8F9C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_get_Count_m8CE395B93EA7127861F983E3C2FE02E08A41D42E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_get_Count_mF590592E32D421DE2C6E2F0D5C2F62FB14CCEFDF_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_get_Item_m9BC9267741CE11FCC731D1D0F6E98A08295D2545_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_get_Item_mD99081BEFA1AB3526715F489192B0F7F596C183D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Marshal_UnsafeAddrOfPinnedArrayElement_TisGSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E_m2655F1BCF3E2FE7B028C56300363CA8898B97CC4_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Marshal_UnsafeAddrOfPinnedArrayElement_TisGSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_m2FCC5D2D2C14567CAEFBA54CB0BE80EA9E9ED980_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Pvr_BoundaryAPI_IntPtrToStruct_TisGSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E_m3C7EC489283FB44610163AB0091A1C279E4F7156_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Pvr_BoundaryAPI_IntPtrToStruct_TisGSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3_mF94DF99548B07FAD05377E537D93589DB1845B7F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Pvr_BoundaryAPI_StructToIntPtr_TisGSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E_m4A4DF55B0B16B585FA2439BED123BE4CA5ED44D5_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Pvr_SafeAreaAlgoModule__SafeAreaCallbackShrink_m20C04C87D5E2E2708E462363D98BC4924BD3E354_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Pvr_SafeAreaAlgoModule__SafeAreaCallback_m756D201F90CFD3D062D71245E9C85697F8766969_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Queue_1_Clear_m6B2EEBAC23F6D33E3209B3CDD5663163329AF523_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Queue_1_Dequeue_mF641B4D1C707EF56082B2E8DF4351EBDEB8357F8_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Queue_1_Enqueue_m575BD66AE362D5DB74AE95DCB203046EDE78991B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Queue_1__ctor_mBC4678D497EB50E3826BB8B1818E4A38B45B486B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Queue_1_get_Count_m166D9E7A5DA18ACC5799C3963DD64F400A9F21BC_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpatialTextureMain_OnBindEnterpriseService_mDF04F8002285E4188A4C78C9CF2F0E7C8BA0108B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpatialTextureMain_OnFocusStateAcquired_m09E08ECD14CE3ADE88B375D92B5B79023FE36719_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpatialTextureToSystem_EditorTest_mD7948F4D04A321BD3BC399921104CD2B509266D1_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpatialTextureToSystem_RuntimeCall_mEB3B29789D850F95A4172D9A46668168EA90F83F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CU3Ef__AnonymousType0_1__ctor_mF4E4C5F9CD02AEAF4F890E22441AE2B516285AB6_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeType* GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_0_0_0_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;
struct ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54;;
struct ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshaled_com;
struct ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshaled_com;;
struct ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshaled_pinvoke;
struct ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshaled_pinvoke;;

struct BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct UIPageU5BU5D_t7F52BDD6ABCD90C3DC53772307DC5681B3D58496;
struct Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C;
struct GSALineU5BU5D_tC2644452FF1B88D2D201F355FA28F65A5D8CF685;
struct GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// <>f__AnonymousType0`1<System.Int32>
struct U3CU3Ef__AnonymousType0_1_tCC81029179B6F4DAC7D8BC271C35F5CDBC097D55  : public RuntimeObject
{
	// <num>j__TPar <>f__AnonymousType0`1::<num>i__Field
	int32_t ___U3CnumU3Ei__Field_0;
};

// System.Collections.Generic.Dictionary`2<System.Int32,com.picoxr.tobframwork.Timer/Handle>
struct Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_tE38603B97779B846C497E38D2FAB43CA13D444C4* ____entries_1;
	// System.Int32 System.Collections.Generic.Dictionary`2::_count
	int32_t ____count_2;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeList
	int32_t ____freeList_3;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeCount
	int32_t ____freeCount_4;
	// System.Int32 System.Collections.Generic.Dictionary`2::_version
	int32_t ____version_5;
	// System.Collections.Generic.IEqualityComparer`1<TKey> System.Collections.Generic.Dictionary`2::_comparer
	RuntimeObject* ____comparer_6;
	// System.Collections.Generic.Dictionary`2/KeyCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_keys
	KeyCollection_tB57895601DB66AA6C52845C41D23126AF09E83FC* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_t116A43BE8D6490021446FC80915F6E1A0A39CB40* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.Collections.Generic.Dictionary`2<System.String,System.Delegate>
struct Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_tBACA0DA26A77797D416943C38A345F0E2F0BD9F4* ____entries_1;
	// System.Int32 System.Collections.Generic.Dictionary`2::_count
	int32_t ____count_2;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeList
	int32_t ____freeList_3;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeCount
	int32_t ____freeCount_4;
	// System.Int32 System.Collections.Generic.Dictionary`2::_version
	int32_t ____version_5;
	// System.Collections.Generic.IEqualityComparer`1<TKey> System.Collections.Generic.Dictionary`2::_comparer
	RuntimeObject* ____comparer_6;
	// System.Collections.Generic.Dictionary`2/KeyCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_keys
	KeyCollection_t29B1E367D95E46B2E45B4C33E1F3C5644F15EC98* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_t6C0A84D04F87D3A05857431804390724962C3F6F* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.Collections.Generic.Dictionary`2<System.Type,System.Int32>
struct Dictionary_2_t384D2A0FF42BF1302A3F513FC32DB105F1CD5455  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_tD80C7495BA8BE64BC139A54FA961AB3EC66D7319* ____entries_1;
	// System.Int32 System.Collections.Generic.Dictionary`2::_count
	int32_t ____count_2;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeList
	int32_t ____freeList_3;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeCount
	int32_t ____freeCount_4;
	// System.Int32 System.Collections.Generic.Dictionary`2::_version
	int32_t ____version_5;
	// System.Collections.Generic.IEqualityComparer`1<TKey> System.Collections.Generic.Dictionary`2::_comparer
	RuntimeObject* ____comparer_6;
	// System.Collections.Generic.Dictionary`2/KeyCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_keys
	KeyCollection_tE2F56A37776137F5D3C1BA6C49999EF1EC0E216F* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_tAD56DF94D7373625A22E80E942606DC8509CB6D2* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.Collections.Generic.Dictionary`2<System.Type,com.picoxr.tobframwork.UIPage>
struct Dictionary_2_t1BF400F50D50E19CF6FCD3FF520384A96269F89F  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_t6743F267FE53E639AADC75D64CDEAF2DF5A76EF9* ____entries_1;
	// System.Int32 System.Collections.Generic.Dictionary`2::_count
	int32_t ____count_2;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeList
	int32_t ____freeList_3;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeCount
	int32_t ____freeCount_4;
	// System.Int32 System.Collections.Generic.Dictionary`2::_version
	int32_t ____version_5;
	// System.Collections.Generic.IEqualityComparer`1<TKey> System.Collections.Generic.Dictionary`2::_comparer
	RuntimeObject* ____comparer_6;
	// System.Collections.Generic.Dictionary`2/KeyCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_keys
	KeyCollection_tE3802AACC5EA3577CD36EBE3E85965902C414BFE* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_t4D47B859E1DE64BE6F72446E09432F17759FAC00* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.Collections.Generic.List`1<System.Collections.Generic.List`1<System.Int32>>
struct List_1_tB5A0E21D0A7C39DF93D616FD5B94C4737A083E35  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	List_1U5BU5D_t37294D7C303231F2FD83B3C398AED0937F4F3206* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<System.Collections.Generic.List`1<System.Single>>
struct List_1_tFF2BC422A193D7F048E03ABCCC32292E892A12F7  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	List_1U5BU5D_tB3324071AD89A3E4C72B73C6C5D42DCAC9EC993F* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<System.Collections.Generic.List`1<UnityEngine.Vector3>>
struct List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	List_1U5BU5D_tC1B009E92641A2C993F3BB28A80D61D2AB67979B* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<Boundary.Data.BoundaryItem>
struct List_1_t9B1B27900D11844BED9AD08E793EE74AB63688C5  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	BoundaryItemU5BU5D_tFA1A2813C2E9A578225D157CCDC1532B27EC7221* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<System.Int32>
struct List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<Boundary.Data.Item>
struct List_1_tDCE834B5223117F51ED29F0327C1C20731F3D0CD  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	ItemU5BU5D_t1BB908030FAE0B323EDC9CD4CE537EB6B9A6CB49* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<System.Object>
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<UnityEngine.Vector3>
struct List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<com.picoxr.tobframwork.Timer/Handle>
struct List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	HandleU5BU5D_t32660A977D98D1266A234A1C5378D6A41C9A30C7* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.Queue`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo>
struct Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9  : public RuntimeObject
{
	// T[] System.Collections.Generic.Queue`1::_array
	TextureInfoU5BU5D_tC46E5F4213D1A76EC15060BD225B8C7D54235C82* ____array_0;
	// System.Int32 System.Collections.Generic.Queue`1::_head
	int32_t ____head_1;
	// System.Int32 System.Collections.Generic.Queue`1::_tail
	int32_t ____tail_2;
	// System.Int32 System.Collections.Generic.Queue`1::_size
	int32_t ____size_3;
	// System.Int32 System.Collections.Generic.Queue`1::_version
	int32_t ____version_4;
	// System.Object System.Collections.Generic.Queue`1::_syncRoot
	RuntimeObject* ____syncRoot_5;
};

// <PrivateImplementationDetails>
struct U3CPrivateImplementationDetailsU3E_t0F5473E849A5A5185A9F4C5246F0C32816C49FCA  : public RuntimeObject
{
};

// Boundary.Data.AlgorithmData
struct AlgorithmData_tBED6E92124E6F80F7B4862A143CCAB790E87DC35  : public RuntimeObject
{
	// System.Int32 Boundary.Data.AlgorithmData::<AreaCnt>k__BackingField
	int32_t ___U3CAreaCntU3Ek__BackingField_0;
	// System.String Boundary.Data.AlgorithmData::<MapUUID>k__BackingField
	String_t* ___U3CMapUUIDU3Ek__BackingField_1;
	// System.Collections.Generic.List`1<Boundary.Data.BoundaryItem> Boundary.Data.AlgorithmData::<Boundary>k__BackingField
	List_1_t9B1B27900D11844BED9AD08E793EE74AB63688C5* ___U3CBoundaryU3Ek__BackingField_2;
	// System.Single Boundary.Data.AlgorithmData::DeltaHeight
	float ___DeltaHeight_3;
};

// Boundary.Data.BoundaryConfigData
struct BoundaryConfigData_t4201DE14529DC1A53FF80BAB4E8019BE6D226748  : public RuntimeObject
{
	// System.Int32 Boundary.Data.BoundaryConfigData::<seethroughtype>k__BackingField
	int32_t ___U3CseethroughtypeU3Ek__BackingField_0;
	// System.Double Boundary.Data.BoundaryConfigData::<ground>k__BackingField
	double ___U3CgroundU3Ek__BackingField_1;
	// System.String Boundary.Data.BoundaryConfigData::<posture>k__BackingField
	String_t* ___U3CpostureU3Ek__BackingField_2;
	// System.Double Boundary.Data.BoundaryConfigData::<StandHeight>k__BackingField
	double ___U3CStandHeightU3Ek__BackingField_3;
	// System.Double Boundary.Data.BoundaryConfigData::<SitHeight>k__BackingField
	double ___U3CSitHeightU3Ek__BackingField_4;
	// System.String Boundary.Data.BoundaryConfigData::<centerpath>k__BackingField
	String_t* ___U3CcenterpathU3Ek__BackingField_5;
	// System.String Boundary.Data.BoundaryConfigData::<pointdatapath>k__BackingField
	String_t* ___U3CpointdatapathU3Ek__BackingField_6;
	// System.Int32 Boundary.Data.BoundaryConfigData::<WallRidius>k__BackingField
	int32_t ___U3CWallRidiusU3Ek__BackingField_7;
};

// Boundary.Data.BoundaryData
struct BoundaryData_tDC8C8A6879E571C7A509C93AA6737D479B27F1A9  : public RuntimeObject
{
	// System.Int32 Boundary.Data.BoundaryData::<isSaveMap>k__BackingField
	int32_t ___U3CisSaveMapU3Ek__BackingField_0;
	// System.Int32 Boundary.Data.BoundaryData::<isCurrentType>k__BackingField
	int32_t ___U3CisCurrentTypeU3Ek__BackingField_1;
	// System.UInt64 Boundary.Data.BoundaryData::<BoundarySaveTime>k__BackingField
	uint64_t ___U3CBoundarySaveTimeU3Ek__BackingField_2;
	// System.Int32 Boundary.Data.BoundaryData::<AreaCnt>k__BackingField
	int32_t ___U3CAreaCntU3Ek__BackingField_3;
	// System.String Boundary.Data.BoundaryData::<MapUUID>k__BackingField
	String_t* ___U3CMapUUIDU3Ek__BackingField_4;
	// System.Collections.Generic.List`1<Boundary.Data.Item> Boundary.Data.BoundaryData::<Boundary>k__BackingField
	List_1_tDCE834B5223117F51ED29F0327C1C20731F3D0CD* ___U3CBoundaryU3Ek__BackingField_5;
};

// Boundary.Data.BoundaryItem
struct BoundaryItem_t4F4A542118E39B1229AFC8916C2D37333E0A7E68  : public RuntimeObject
{
	// System.Int32 Boundary.Data.BoundaryItem::<Type>k__BackingField
	int32_t ___U3CTypeU3Ek__BackingField_0;
	// System.Int32 Boundary.Data.BoundaryItem::<Size>k__BackingField
	int32_t ___U3CSizeU3Ek__BackingField_1;
	// System.Collections.Generic.List`1<System.Collections.Generic.List`1<System.Single>> Boundary.Data.BoundaryItem::<Points>k__BackingField
	List_1_tFF2BC422A193D7F048E03ABCCC32292E892A12F7* ___U3CPointsU3Ek__BackingField_2;
};

// Jeffijoe.MessageFormat.CustomValueFormatter
struct CustomValueFormatter_tBD981B5F72D8EADB8B6258BE76BEBEE7EF2403AC  : public RuntimeObject
{
};

// com.picoxr.tobframwork.EventManager
struct EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5  : public RuntimeObject
{
};

// Boundary.Data.Item
struct Item_t51A6B6268FD582ED0ADB924808FCA5449EE278F4  : public RuntimeObject
{
	// System.Int32 Boundary.Data.Item::<Type>k__BackingField
	int32_t ___U3CTypeU3Ek__BackingField_0;
	// System.Int32 Boundary.Data.Item::<Size>k__BackingField
	int32_t ___U3CSizeU3Ek__BackingField_1;
	// System.Collections.Generic.List`1<System.Collections.Generic.List`1<System.Single>> Boundary.Data.Item::<Points>k__BackingField
	List_1_tFF2BC422A193D7F048E03ABCCC32292E892A12F7* ___U3CPointsU3Ek__BackingField_2;
	// System.Int32 Boundary.Data.Item::<triangleSize>k__BackingField
	int32_t ___U3CtriangleSizeU3Ek__BackingField_3;
	// System.Collections.Generic.List`1<System.Collections.Generic.List`1<System.Int32>> Boundary.Data.Item::<triangles>k__BackingField
	List_1_tB5A0E21D0A7C39DF93D616FD5B94C4737A083E35* ___U3CtrianglesU3Ek__BackingField_4;
	// System.Int32 Boundary.Data.Item::<uvsize>k__BackingField
	int32_t ___U3CuvsizeU3Ek__BackingField_5;
	// System.Collections.Generic.List`1<System.Collections.Generic.List`1<System.Single>> Boundary.Data.Item::<uv>k__BackingField
	List_1_tFF2BC422A193D7F048E03ABCCC32292E892A12F7* ___U3CuvU3Ek__BackingField_6;
	// System.Double Boundary.Data.Item::<areagirth>k__BackingField
	double ___U3CareagirthU3Ek__BackingField_7;
};

// com.picoxr.tobframwork.LanguageUtils
struct LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D  : public RuntimeObject
{
};

// System.Reflection.MemberInfo
struct MemberInfo_t  : public RuntimeObject
{
};

// Jeffijoe.MessageFormat.MessageFormatter
struct MessageFormatter_t59AB4D9D22B9B2403C45FF755A0AB60223D2035F  : public RuntimeObject
{
	// System.Collections.Concurrent.ConcurrentDictionary`2<System.String,Jeffijoe.MessageFormat.Parsing.IFormatterRequestCollection> Jeffijoe.MessageFormat.MessageFormatter::cache
	ConcurrentDictionary_2_t11BB466A2D80E315699FA0821C3DDBC98A586DC0* ___cache_2;
	// Jeffijoe.MessageFormat.Formatting.IFormatterLibrary Jeffijoe.MessageFormat.MessageFormatter::library
	RuntimeObject* ___library_3;
	// Jeffijoe.MessageFormat.Parsing.IPatternParser Jeffijoe.MessageFormat.MessageFormatter::patternParser
	RuntimeObject* ___patternParser_4;
	// Jeffijoe.MessageFormat.CustomValueFormatter Jeffijoe.MessageFormat.MessageFormatter::<CustomValueFormatter>k__BackingField
	CustomValueFormatter_tBD981B5F72D8EADB8B6258BE76BEBEE7EF2403AC* ___U3CCustomValueFormatterU3Ek__BackingField_5;
	// System.String Jeffijoe.MessageFormat.MessageFormatter::<Locale>k__BackingField
	String_t* ___U3CLocaleU3Ek__BackingField_6;
};

// BoundarySystem_Ext.Pvr_BoundaryAPI
struct Pvr_BoundaryAPI_t82D5D1F6169832E7C19EA338B061868C8946EF47  : public RuntimeObject
{
};

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI
struct Pvr_SafeAreaAlgoAPI_tD13216FAE36ACA6FD1DF670E549EE9DD888648B1  : public RuntimeObject
{
};

// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule
struct Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05  : public RuntimeObject
{
	// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundarySystemCallback BoundarySystem_Ext.Pvr_SafeAreaAlgoModule::boundarySystemCallback
	BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD* ___boundarySystemCallback_1;
	// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundarySystemCallbackShrink BoundarySystem_Ext.Pvr_SafeAreaAlgoModule::boundarySystemCallbackShrink
	BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75* ___boundarySystemCallbackShrink_2;
};

// System.String
struct String_t  : public RuntimeObject
{
	// System.Int32 System.String::_stringLength
	int32_t ____stringLength_4;
	// System.Char System.String::_firstChar
	Il2CppChar ____firstChar_5;
};

// System.Text.StringBuilder
struct StringBuilder_t  : public RuntimeObject
{
	// System.Char[] System.Text.StringBuilder::m_ChunkChars
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___m_ChunkChars_0;
	// System.Text.StringBuilder System.Text.StringBuilder::m_ChunkPrevious
	StringBuilder_t* ___m_ChunkPrevious_1;
	// System.Int32 System.Text.StringBuilder::m_ChunkLength
	int32_t ___m_ChunkLength_2;
	// System.Int32 System.Text.StringBuilder::m_ChunkOffset
	int32_t ___m_ChunkOffset_3;
	// System.Int32 System.Text.StringBuilder::m_MaxCapacity
	int32_t ___m_MaxCapacity_4;
};

// com.picoxr.tobframwork.Unitls
struct Unitls_t2BA1216F702C7798ED366C4C77A5148AE77216A8  : public RuntimeObject
{
};

// System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
// Native definition for P/Invoke marshalling of System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
// Native definition for COM marshalling of System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};

// Unity.XR.PXR.PXR_Plugin/System
struct System_t4255BA2E24C230336F7C003E6DD13B25588178DB  : public RuntimeObject
{
};

// com.picoxr.tobframwork.Timer/Handle
struct Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5  : public RuntimeObject
{
	// System.Single com.picoxr.tobframwork.Timer/Handle::StartTime
	float ___StartTime_0;
	// System.Single com.picoxr.tobframwork.Timer/Handle::Delay
	float ___Delay_1;
	// System.Single com.picoxr.tobframwork.Timer/Handle::RepeatRate
	float ___RepeatRate_2;
	// System.Action com.picoxr.tobframwork.Timer/Handle::Call
	Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___Call_3;
	// System.Int32 com.picoxr.tobframwork.Timer/Handle::ID
	int32_t ___ID_4;
	// System.Single com.picoxr.tobframwork.Timer/Handle::LastCallTime
	float ___LastCallTime_5;
};

// System.Collections.Generic.KeyValuePair`2<System.Int32,System.Object>
struct KeyValuePair_2_tDC26B09C26BA829DDE331BCB6AF7C508C763D7A3 
{
	// TKey System.Collections.Generic.KeyValuePair`2::key
	int32_t ___key_0;
	// TValue System.Collections.Generic.KeyValuePair`2::value
	RuntimeObject* ___value_1;
};

// System.Collections.Generic.KeyValuePair`2<System.Int32,com.picoxr.tobframwork.Timer/Handle>
struct KeyValuePair_2_t7D5F51FBC6FB4B34CCA91B6881B1DCFDCCEEE2B3 
{
	// TKey System.Collections.Generic.KeyValuePair`2::key
	int32_t ___key_0;
	// TValue System.Collections.Generic.KeyValuePair`2::value
	Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* ___value_1;
};

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	// System.Boolean System.Boolean::m_value
	bool ___m_value_0;
};

// System.Char
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17 
{
	// System.Char System.Char::m_value
	Il2CppChar ___m_value_0;
};

// System.Double
struct Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F 
{
	// System.Double System.Double::m_value
	double ___m_value_0;
};

// System.Enum
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2  : public ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F
{
};
// Native definition for P/Invoke marshalling of System.Enum
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_pinvoke
{
};
// Native definition for COM marshalling of System.Enum
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_com
{
};

// System.Int32
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	// System.Int32 System.Int32::m_value
	int32_t ___m_value_0;
};

// System.Int64
struct Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3 
{
	// System.Int64 System.Int64::m_value
	int64_t ___m_value_0;
};

// System.IntPtr
struct IntPtr_t 
{
	// System.Void* System.IntPtr::m_value
	void* ___m_value_0;
};

// UnityEngine.XR.Interaction.Toolkit.InteractionLayerMask
struct InteractionLayerMask_t3B3480A4A5E1E0C43314C0D2CEB3BB39175E1FD4 
{
	// System.UInt32 UnityEngine.XR.Interaction.Toolkit.InteractionLayerMask::m_Bits
	uint32_t ___m_Bits_0;
	// System.Int32 UnityEngine.XR.Interaction.Toolkit.InteractionLayerMask::m_Mask
	int32_t ___m_Mask_1;
};

// UnityEngine.LayerMask
struct LayerMask_t97CB6BDADEDC3D6423C7BCFEA7F86DA2EC6241DB 
{
	// System.Int32 UnityEngine.LayerMask::m_Mask
	int32_t ___m_Mask_0;
};

// System.Reflection.MethodBase
struct MethodBase_t  : public MemberInfo_t
{
};

// UnityEngine.PhysicsScene
struct PhysicsScene_t55222DD37072E8560EE054A07C0E3FE391D9D9DE 
{
	// System.Int32 UnityEngine.PhysicsScene::m_Handle
	int32_t ___m_Handle_0;
};

// System.Single
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	// System.Single System.Single::m_value
	float ___m_value_0;
};

// System.UInt32
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	// System.UInt32 System.UInt32::m_value
	uint32_t ___m_value_0;
};

// System.UInt64
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF 
{
	// System.UInt64 System.UInt64::m_value
	uint64_t ___m_value_0;
};

// UnityEngine.Vector2
struct Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 
{
	// System.Single UnityEngine.Vector2::x
	float ___x_0;
	// System.Single UnityEngine.Vector2::y
	float ___y_1;
};

// UnityEngine.Vector3
struct Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 
{
	// System.Single UnityEngine.Vector3::x
	float ___x_2;
	// System.Single UnityEngine.Vector3::y
	float ___y_3;
	// System.Single UnityEngine.Vector3::z
	float ___z_4;
};

// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=24
struct __StaticArrayInitTypeSizeU3D24_t3464DA68B6CCAB9A0A43F94B3DB9AA7E7FDDB19A 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D24_t3464DA68B6CCAB9A0A43F94B3DB9AA7E7FDDB19A__padding[24];
	};
};

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALegalData
struct GSALegalData_tB87501C567F852AFE055E4A612E06DC6360EB2E7 
{
	// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALegalData::overMaxRange
	int32_t ___overMaxRange_0;
	// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALegalData::includeBigGrap
	int32_t ___includeBigGrap_1;
	// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALegalData::bigGapNum
	int32_t ___bigGapNum_2;
	// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALegalData::centerOut
	int32_t ___centerOut_3;
	// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALegalData::removeNarrow
	int32_t ___removeNarrow_4;
	// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALegalData::overMaxRange_more
	int32_t ___overMaxRange_more_5;
	// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALegalData::validShrinkArea
	int32_t ___validShrinkArea_6;
};

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i
struct GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 
{
	// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i::x
	int32_t ___x_0;
	// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i::y
	int32_t ___y_1;
	// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i::z
	int32_t ___z_2;
};

// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/ExtraInfo
struct ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54 
{
	// System.Boolean BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/ExtraInfo::overMaxRange
	bool ___overMaxRange_0;
	// System.Boolean BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/ExtraInfo::includeBigGap
	bool ___includeBigGap_1;
	// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/ExtraInfo::bigGapNum
	int32_t ___bigGapNum_2;
	// System.Boolean BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/ExtraInfo::centerOut
	bool ___centerOut_3;
	// System.Boolean BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/ExtraInfo::removeNarrow
	bool ___removeNarrow_4;
	// System.Boolean BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/ExtraInfo::overMaxRange_more
	bool ___overMaxRange_more_5;
	// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/ExtraInfo::validShrinkArea
	int32_t ___validShrinkArea_6;
};
// Native definition for P/Invoke marshalling of BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/ExtraInfo
struct ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshaled_pinvoke
{
	int32_t ___overMaxRange_0;
	int32_t ___includeBigGap_1;
	int32_t ___bigGapNum_2;
	int32_t ___centerOut_3;
	int32_t ___removeNarrow_4;
	int32_t ___overMaxRange_more_5;
	int32_t ___validShrinkArea_6;
};
// Native definition for COM marshalling of BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/ExtraInfo
struct ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshaled_com
{
	int32_t ___overMaxRange_0;
	int32_t ___includeBigGap_1;
	int32_t ___bigGapNum_2;
	int32_t ___centerOut_3;
	int32_t ___removeNarrow_4;
	int32_t ___overMaxRange_more_5;
	int32_t ___validShrinkArea_6;
};

// System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>
struct Enumerator_tE92C1AC40A104A179B94F8A013728FD9314CFBD3 
{
	// System.Collections.Generic.Dictionary`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator::_dictionary
	Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* ____dictionary_0;
	// System.Int32 System.Collections.Generic.Dictionary`2/Enumerator::_version
	int32_t ____version_1;
	// System.Int32 System.Collections.Generic.Dictionary`2/Enumerator::_index
	int32_t ____index_2;
	// System.Collections.Generic.KeyValuePair`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator::_current
	KeyValuePair_2_tDC26B09C26BA829DDE331BCB6AF7C508C763D7A3 ____current_3;
	// System.Int32 System.Collections.Generic.Dictionary`2/Enumerator::_getEnumeratorRetType
	int32_t ____getEnumeratorRetType_4;
};

// System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,com.picoxr.tobframwork.Timer/Handle>
struct Enumerator_t2EE140C33897AA9EA14EF9B66B7AA963EEB1E888 
{
	// System.Collections.Generic.Dictionary`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator::_dictionary
	Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6* ____dictionary_0;
	// System.Int32 System.Collections.Generic.Dictionary`2/Enumerator::_version
	int32_t ____version_1;
	// System.Int32 System.Collections.Generic.Dictionary`2/Enumerator::_index
	int32_t ____index_2;
	// System.Collections.Generic.KeyValuePair`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator::_current
	KeyValuePair_2_t7D5F51FBC6FB4B34CCA91B6881B1DCFDCCEEE2B3 ____current_3;
	// System.Int32 System.Collections.Generic.Dictionary`2/Enumerator::_getEnumeratorRetType
	int32_t ____getEnumeratorRetType_4;
};

// System.Delegate
struct Delegate_t  : public RuntimeObject
{
	// System.IntPtr System.Delegate::method_ptr
	intptr_t ___method_ptr_0;
	// System.IntPtr System.Delegate::invoke_impl
	intptr_t ___invoke_impl_1;
	// System.Object System.Delegate::m_target
	RuntimeObject* ___m_target_2;
	// System.IntPtr System.Delegate::method
	intptr_t ___method_3;
	// System.IntPtr System.Delegate::delegate_trampoline
	intptr_t ___delegate_trampoline_4;
	// System.IntPtr System.Delegate::extra_arg
	intptr_t ___extra_arg_5;
	// System.IntPtr System.Delegate::method_code
	intptr_t ___method_code_6;
	// System.IntPtr System.Delegate::interp_method
	intptr_t ___interp_method_7;
	// System.IntPtr System.Delegate::interp_invoke_impl
	intptr_t ___interp_invoke_impl_8;
	// System.Reflection.MethodInfo System.Delegate::method_info
	MethodInfo_t* ___method_info_9;
	// System.Reflection.MethodInfo System.Delegate::original_method_info
	MethodInfo_t* ___original_method_info_10;
	// System.DelegateData System.Delegate::data
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	// System.Boolean System.Delegate::method_is_virtual
	bool ___method_is_virtual_12;
};
// Native definition for P/Invoke marshalling of System.Delegate
struct Delegate_t_marshaled_pinvoke
{
	intptr_t ___method_ptr_0;
	intptr_t ___invoke_impl_1;
	Il2CppIUnknown* ___m_target_2;
	intptr_t ___method_3;
	intptr_t ___delegate_trampoline_4;
	intptr_t ___extra_arg_5;
	intptr_t ___method_code_6;
	intptr_t ___interp_method_7;
	intptr_t ___interp_invoke_impl_8;
	MethodInfo_t* ___method_info_9;
	MethodInfo_t* ___original_method_info_10;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	int32_t ___method_is_virtual_12;
};
// Native definition for COM marshalling of System.Delegate
struct Delegate_t_marshaled_com
{
	intptr_t ___method_ptr_0;
	intptr_t ___invoke_impl_1;
	Il2CppIUnknown* ___m_target_2;
	intptr_t ___method_3;
	intptr_t ___delegate_trampoline_4;
	intptr_t ___extra_arg_5;
	intptr_t ___method_code_6;
	intptr_t ___interp_method_7;
	intptr_t ___interp_invoke_impl_8;
	MethodInfo_t* ___method_info_9;
	MethodInfo_t* ___original_method_info_10;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	int32_t ___method_is_virtual_12;
};

// System.Exception
struct Exception_t  : public RuntimeObject
{
	// System.String System.Exception::_className
	String_t* ____className_1;
	// System.String System.Exception::_message
	String_t* ____message_2;
	// System.Collections.IDictionary System.Exception::_data
	RuntimeObject* ____data_3;
	// System.Exception System.Exception::_innerException
	Exception_t* ____innerException_4;
	// System.String System.Exception::_helpURL
	String_t* ____helpURL_5;
	// System.Object System.Exception::_stackTrace
	RuntimeObject* ____stackTrace_6;
	// System.String System.Exception::_stackTraceString
	String_t* ____stackTraceString_7;
	// System.String System.Exception::_remoteStackTraceString
	String_t* ____remoteStackTraceString_8;
	// System.Int32 System.Exception::_remoteStackIndex
	int32_t ____remoteStackIndex_9;
	// System.Object System.Exception::_dynamicMethods
	RuntimeObject* ____dynamicMethods_10;
	// System.Int32 System.Exception::_HResult
	int32_t ____HResult_11;
	// System.String System.Exception::_source
	String_t* ____source_12;
	// System.Runtime.Serialization.SafeSerializationManager System.Exception::_safeSerializationManager
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager_13;
	// System.Diagnostics.StackTrace[] System.Exception::captured_traces
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces_14;
	// System.IntPtr[] System.Exception::native_trace_ips
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips_15;
	// System.Int32 System.Exception::caught_in_unmanaged
	int32_t ___caught_in_unmanaged_16;
};
// Native definition for P/Invoke marshalling of System.Exception
struct Exception_t_marshaled_pinvoke
{
	char* ____className_1;
	char* ____message_2;
	RuntimeObject* ____data_3;
	Exception_t_marshaled_pinvoke* ____innerException_4;
	char* ____helpURL_5;
	Il2CppIUnknown* ____stackTrace_6;
	char* ____stackTraceString_7;
	char* ____remoteStackTraceString_8;
	int32_t ____remoteStackIndex_9;
	Il2CppIUnknown* ____dynamicMethods_10;
	int32_t ____HResult_11;
	char* ____source_12;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager_13;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces_14;
	Il2CppSafeArray/*NONE*/* ___native_trace_ips_15;
	int32_t ___caught_in_unmanaged_16;
};
// Native definition for COM marshalling of System.Exception
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className_1;
	Il2CppChar* ____message_2;
	RuntimeObject* ____data_3;
	Exception_t_marshaled_com* ____innerException_4;
	Il2CppChar* ____helpURL_5;
	Il2CppIUnknown* ____stackTrace_6;
	Il2CppChar* ____stackTraceString_7;
	Il2CppChar* ____remoteStackTraceString_8;
	int32_t ____remoteStackIndex_9;
	Il2CppIUnknown* ____dynamicMethods_10;
	int32_t ____HResult_11;
	Il2CppChar* ____source_12;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager_13;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces_14;
	Il2CppSafeArray/*NONE*/* ___native_trace_ips_15;
	int32_t ___caught_in_unmanaged_16;
};

// System.Reflection.MethodInfo
struct MethodInfo_t  : public MethodBase_t
{
};

// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C  : public RuntimeObject
{
	// System.IntPtr UnityEngine.Object::m_CachedPtr
	intptr_t ___m_CachedPtr_0;
};
// Native definition for P/Invoke marshalling of UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_pinvoke
{
	intptr_t ___m_CachedPtr_0;
};
// Native definition for COM marshalling of UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_com
{
	intptr_t ___m_CachedPtr_0;
};

// BoundarySystem_Ext.Pvr_BoundarySystem
struct Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544  : public RuntimeObject
{
	// System.IntPtr BoundarySystem_Ext.Pvr_BoundarySystem::CameraFramePtr
	intptr_t ___CameraFramePtr_3;
};

// UnityEngine.QueryTriggerInteraction
struct QueryTriggerInteraction_t5AA443202C8B671F391534A002B7CF48A1412D23 
{
	// System.Int32 UnityEngine.QueryTriggerInteraction::value__
	int32_t ___value___2;
};

// UnityEngine.RaycastHit
struct RaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5 
{
	// UnityEngine.Vector3 UnityEngine.RaycastHit::m_Point
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_Point_0;
	// UnityEngine.Vector3 UnityEngine.RaycastHit::m_Normal
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_Normal_1;
	// System.UInt32 UnityEngine.RaycastHit::m_FaceID
	uint32_t ___m_FaceID_2;
	// System.Single UnityEngine.RaycastHit::m_Distance
	float ___m_Distance_3;
	// UnityEngine.Vector2 UnityEngine.RaycastHit::m_UV
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___m_UV_4;
	// System.Int32 UnityEngine.RaycastHit::m_Collider
	int32_t ___m_Collider_5;
};

// UnityEngine.EventSystems.RaycastResult
struct RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 
{
	// UnityEngine.GameObject UnityEngine.EventSystems.RaycastResult::m_GameObject
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___m_GameObject_0;
	// UnityEngine.EventSystems.BaseRaycaster UnityEngine.EventSystems.RaycastResult::module
	BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* ___module_1;
	// System.Single UnityEngine.EventSystems.RaycastResult::distance
	float ___distance_2;
	// System.Single UnityEngine.EventSystems.RaycastResult::index
	float ___index_3;
	// System.Int32 UnityEngine.EventSystems.RaycastResult::depth
	int32_t ___depth_4;
	// System.Int32 UnityEngine.EventSystems.RaycastResult::sortingGroupID
	int32_t ___sortingGroupID_5;
	// System.Int32 UnityEngine.EventSystems.RaycastResult::sortingGroupOrder
	int32_t ___sortingGroupOrder_6;
	// System.Int32 UnityEngine.EventSystems.RaycastResult::sortingLayer
	int32_t ___sortingLayer_7;
	// System.Int32 UnityEngine.EventSystems.RaycastResult::sortingOrder
	int32_t ___sortingOrder_8;
	// UnityEngine.Vector3 UnityEngine.EventSystems.RaycastResult::worldPosition
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___worldPosition_9;
	// UnityEngine.Vector3 UnityEngine.EventSystems.RaycastResult::worldNormal
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___worldNormal_10;
	// UnityEngine.Vector2 UnityEngine.EventSystems.RaycastResult::screenPosition
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___screenPosition_11;
	// System.Int32 UnityEngine.EventSystems.RaycastResult::displayIndex
	int32_t ___displayIndex_12;
};
// Native definition for P/Invoke marshalling of UnityEngine.EventSystems.RaycastResult
struct RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_marshaled_pinvoke
{
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___m_GameObject_0;
	BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* ___module_1;
	float ___distance_2;
	float ___index_3;
	int32_t ___depth_4;
	int32_t ___sortingGroupID_5;
	int32_t ___sortingGroupOrder_6;
	int32_t ___sortingLayer_7;
	int32_t ___sortingOrder_8;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___worldPosition_9;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___worldNormal_10;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___screenPosition_11;
	int32_t ___displayIndex_12;
};
// Native definition for COM marshalling of UnityEngine.EventSystems.RaycastResult
struct RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_marshaled_com
{
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___m_GameObject_0;
	BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* ___module_1;
	float ___distance_2;
	float ___index_3;
	int32_t ___depth_4;
	int32_t ___sortingGroupID_5;
	int32_t ___sortingGroupOrder_6;
	int32_t ___sortingLayer_7;
	int32_t ___sortingOrder_8;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___worldPosition_9;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___worldNormal_10;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___screenPosition_11;
	int32_t ___displayIndex_12;
};

// System.RuntimeTypeHandle
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	// System.IntPtr System.RuntimeTypeHandle::value
	intptr_t ___value_0;
};

// UnityEngine.XR.Interaction.Toolkit.ScaleMode
struct ScaleMode_t3C7757E6F3AEE311EF7B19F8CA7B66DE240D6807 
{
	// System.Int32 UnityEngine.XR.Interaction.Toolkit.ScaleMode::value__
	int32_t ___value___2;
};

// UnityEngine.XR.Interaction.Toolkit.TargetPriorityMode
struct TargetPriorityMode_tCD65C787957C5C0E5E8C8AAC56C2C3B219C3043B 
{
	// System.Int32 UnityEngine.XR.Interaction.Toolkit.TargetPriorityMode::value__
	int32_t ___value___2;
};

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALine
struct GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E 
{
	// System.IntPtr BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALine::pointArray
	intptr_t ___pointArray_0;
	// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALine::pointCount
	int32_t ___pointCount_1;
};

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALineCollection
struct GSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E 
{
	// System.IntPtr BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALineCollection::lineArray
	intptr_t ___lineArray_0;
	// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALineCollection::lineCount
	int32_t ___lineCount_1;
};

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSARect
struct GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 
{
	// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSARect::leftup
	GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 ___leftup_0;
	// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSARect::leftdown
	GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 ___leftdown_1;
	// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSARect::rightup
	GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 ___rightup_2;
	// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSARect::rightdown
	GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 ___rightdown_3;
	// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSARect::center
	GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 ___center_4;
	// System.UInt32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSARect::width
	uint32_t ___width_5;
	// System.UInt32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSARect::height
	uint32_t ___height_6;
	// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSARect::isLegal
	int32_t ___isLegal_7;
	// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALegalData BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSARect::legalData
	GSALegalData_tB87501C567F852AFE055E4A612E06DC6360EB2E7 ___legalData_8;
	// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSARect::firstCenter
	GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 ___firstCenter_9;
};

// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundaryPlayerArea
struct BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B 
{
	// UnityEngine.Vector3 BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundaryPlayerArea::lowerleft
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___lowerleft_0;
	// UnityEngine.Vector3 BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundaryPlayerArea::upperleft
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___upperleft_1;
	// UnityEngine.Vector3 BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundaryPlayerArea::upperRight
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___upperRight_2;
	// UnityEngine.Vector3 BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundaryPlayerArea::lowerRight
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___lowerRight_3;
	// UnityEngine.Vector3 BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundaryPlayerArea::center
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___center_4;
	// System.UInt32 BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundaryPlayerArea::width
	uint32_t ___width_5;
	// System.UInt32 BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundaryPlayerArea::height
	uint32_t ___height_6;
	// System.Boolean BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundaryPlayerArea::isLegal
	bool ___isLegal_7;
	// UnityEngine.Vector3 BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundaryPlayerArea::firstcenter
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___firstcenter_8;
	// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/ExtraInfo BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundaryPlayerArea::extraInfo
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54 ___extraInfo_9;
};
// Native definition for P/Invoke marshalling of BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundaryPlayerArea
struct BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B_marshaled_pinvoke
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___lowerleft_0;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___upperleft_1;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___upperRight_2;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___lowerRight_3;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___center_4;
	uint32_t ___width_5;
	uint32_t ___height_6;
	int32_t ___isLegal_7;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___firstcenter_8;
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshaled_pinvoke ___extraInfo_9;
};
// Native definition for COM marshalling of BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundaryPlayerArea
struct BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B_marshaled_com
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___lowerleft_0;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___upperleft_1;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___upperRight_2;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___lowerRight_3;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___center_4;
	uint32_t ___width_5;
	uint32_t ___height_6;
	int32_t ___isLegal_7;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___firstcenter_8;
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshaled_com ___extraInfo_9;
};

// com.picoxr.blsapce.SpatialTextureToSystem/ScanState
struct ScanState_tC2A7E771A0FB73056F3BFF17BFB32A3D7B9184BB 
{
	// System.Int32 com.picoxr.blsapce.SpatialTextureToSystem/ScanState::value__
	int32_t ___value___2;
};

// com.picoxr.blsapce.SpatialTextureToSystem/TextureLevelType
struct TextureLevelType_t9605D1AFDEBBBAA51AAC3F4AA94492ED053FBE8B 
{
	// System.Int32 com.picoxr.blsapce.SpatialTextureToSystem/TextureLevelType::value__
	int32_t ___value___2;
};

// UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor/InputTriggerType
struct InputTriggerType_t51135E1379C18C54A1E915651CF09F06545F2E10 
{
	// System.Int32 UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor/InputTriggerType::value__
	int32_t ___value___2;
};

// UnityEngine.XR.Interaction.Toolkit.XRRayInteractor/AnchorRotationMode
struct AnchorRotationMode_tFC49851D1B4066821779F392F404AF170B7F7627 
{
	// System.Int32 UnityEngine.XR.Interaction.Toolkit.XRRayInteractor/AnchorRotationMode::value__
	int32_t ___value___2;
};

// UnityEngine.XR.Interaction.Toolkit.XRRayInteractor/HitDetectionType
struct HitDetectionType_tE29310A96101F16A06F8AE8363F7D7E819C02964 
{
	// System.Int32 UnityEngine.XR.Interaction.Toolkit.XRRayInteractor/HitDetectionType::value__
	int32_t ___value___2;
};

// UnityEngine.XR.Interaction.Toolkit.XRRayInteractor/LineType
struct LineType_tCCCB556902C18C56AD05BC3E9D351ADA3762D4C2 
{
	// System.Int32 UnityEngine.XR.Interaction.Toolkit.XRRayInteractor/LineType::value__
	int32_t ___value___2;
};

// UnityEngine.XR.Interaction.Toolkit.XRRayInteractor/QuerySnapVolumeInteraction
struct QuerySnapVolumeInteraction_t6623710591BE780632AC1DF9531866FBC9590D01 
{
	// System.Int32 UnityEngine.XR.Interaction.Toolkit.XRRayInteractor/QuerySnapVolumeInteraction::value__
	int32_t ___value___2;
};

// UnityEngine.Component
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// UnityEngine.GameObject
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// System.MulticastDelegate
struct MulticastDelegate_t  : public Delegate_t
{
	// System.Delegate[] System.MulticastDelegate::delegates
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* ___delegates_13;
};
// Native definition for P/Invoke marshalling of System.MulticastDelegate
struct MulticastDelegate_t_marshaled_pinvoke : public Delegate_t_marshaled_pinvoke
{
	Delegate_t_marshaled_pinvoke** ___delegates_13;
};
// Native definition for COM marshalling of System.MulticastDelegate
struct MulticastDelegate_t_marshaled_com : public Delegate_t_marshaled_com
{
	Delegate_t_marshaled_com** ___delegates_13;
};

// System.Type
struct Type_t  : public MemberInfo_t
{
	// System.RuntimeTypeHandle System.Type::_impl
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl_8;
};

// com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo
struct TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 
{
	// com.picoxr.blsapce.SpatialTextureToSystem/TextureLevelType com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo::textureLevel
	int32_t ___textureLevel_0;
	// com.picoxr.blsapce.SpatialTextureToSystem/ScanState com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo::iScanStatus
	int32_t ___iScanStatus_1;
	// System.Double com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo::dTextureScore
	double ___dTextureScore_2;
	// System.Double com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo::dTimestamp
	double ___dTimestamp_3;
	// System.Double com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo::dScanRate
	double ___dScanRate_4;
	// System.IntPtr com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo::reserve
	intptr_t ___reserve_5;
};

// System.Action`1<System.Boolean>
struct Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C  : public MulticastDelegate_t
{
};

// System.Action`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo>
struct Action_1_t1EE3C77B386F0D0C621A13E4401EC8A7E3819D93  : public MulticastDelegate_t
{
};

// System.Action
struct Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07  : public MulticastDelegate_t
{
};

// System.AsyncCallback
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C  : public MulticastDelegate_t
{
};

// UnityEngine.Behaviour
struct Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};

// UnityEngine.Transform
struct Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallback
struct SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C  : public MulticastDelegate_t
{
};

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallbackShrink
struct SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754  : public MulticastDelegate_t
{
};

// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundarySystemCallback
struct BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD  : public MulticastDelegate_t
{
};

// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundarySystemCallbackShrink
struct BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75  : public MulticastDelegate_t
{
};

// com.picoxr.blsapce.SpatialTextureToSystem/CallBackDelegate
struct CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC  : public MulticastDelegate_t
{
};

// UnityEngine.MonoBehaviour
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
};

// com.picoxr.tobframwork.RayHitPoint
struct RayHitPoint_t4906E263121D0B6973D5818145F76E7E3DD1C9CE  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.Transform com.picoxr.tobframwork.RayHitPoint::UIPoint
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___UIPoint_4;
	// UnityEngine.XR.Interaction.Toolkit.XRRayInteractor com.picoxr.tobframwork.RayHitPoint::_rayInteractor
	XRRayInteractor_t0B25C1D5A938B199A71908E189AB351B43DA4C76* ____rayInteractor_5;
};

// com.picoxr.blsapce.SpatialTextureMain
struct SpatialTextureMain_tA0B9AB4FB7C9920C93B5AEE43B3F12BFE42C57DB  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// System.String com.picoxr.blsapce.SpatialTextureMain::Language
	String_t* ___Language_4;
};

// com.picoxr.blsapce.SpatialTextureToSystem
struct SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
};

// com.picoxr.tobframwork.Timer
struct Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// System.Collections.Generic.Dictionary`2<System.Int32,com.picoxr.tobframwork.Timer/Handle> com.picoxr.tobframwork.Timer::_handles
	Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6* ____handles_4;
	// System.Collections.Generic.List`1<com.picoxr.tobframwork.Timer/Handle> com.picoxr.tobframwork.Timer::_recyles
	List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5* ____recyles_5;
	// System.Collections.Generic.List`1<System.Int32> com.picoxr.tobframwork.Timer::_waitingToRemove
	List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* ____waitingToRemove_6;
	// System.Collections.Generic.List`1<com.picoxr.tobframwork.Timer/Handle> com.picoxr.tobframwork.Timer::_waitingToCall
	List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5* ____waitingToCall_7;
};

// com.picoxr.tobframwork.UIGroup
struct UIGroup_tC217247301A179C554813A009381C0404ECC1DDF  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// com.picoxr.tobframwork.UIPage[] com.picoxr.tobframwork.UIGroup::_allUI
	UIPageU5BU5D_t7F52BDD6ABCD90C3DC53772307DC5681B3D58496* ____allUI_4;
	// System.Boolean[] com.picoxr.tobframwork.UIGroup::_openStates
	BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4* ____openStates_5;
	// System.Collections.Generic.Dictionary`2<System.Type,System.Int32> com.picoxr.tobframwork.UIGroup::_uiTypeToIndex
	Dictionary_2_t384D2A0FF42BF1302A3F513FC32DB105F1CD5455* ____uiTypeToIndex_6;
	// System.Type com.picoxr.tobframwork.UIGroup::_current
	Type_t* ____current_7;
	// System.Int32 com.picoxr.tobframwork.UIGroup::_visibleIndex
	int32_t ____visibleIndex_8;
};

// com.picoxr.tobframwork.UIPage
struct UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// com.picoxr.tobframwork.UIGroup com.picoxr.tobframwork.UIPage::_group
	UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* ____group_4;
	// System.Boolean com.picoxr.tobframwork.UIPage::nonExclusive
	bool ___nonExclusive_5;
};

// com.picoxr.tobframwork.UIPageManager
struct UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// System.Collections.Generic.Dictionary`2<System.Type,com.picoxr.tobframwork.UIPage> com.picoxr.tobframwork.UIPageManager::_cachePage
	Dictionary_2_t1BF400F50D50E19CF6FCD3FF520384A96269F89F* ____cachePage_4;
};

// UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor
struct XRBaseInteractor_tB48889E8D95695ABF46D2012EC55EA660103D158  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// System.Action`1<UnityEngine.XR.Interaction.Toolkit.InteractorRegisteredEventArgs> UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::registered
	Action_1_tBE7729820CBA793D8D5D57207BA5938B012863C5* ___registered_6;
	// System.Action`1<UnityEngine.XR.Interaction.Toolkit.InteractorUnregisteredEventArgs> UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::unregistered
	Action_1_t9A06C49FCB3ADF4C984887951A3DC1DA07CFFBF0* ___unregistered_7;
	// UnityEngine.XR.Interaction.Toolkit.XRInteractionManager UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_InteractionManager
	XRInteractionManager_t93C7F7F0CFEAD83E1A70F92D05B0E663483746CD* ___m_InteractionManager_8;
	// UnityEngine.XR.Interaction.Toolkit.IXRInteractionGroup UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::<containingGroup>k__BackingField
	RuntimeObject* ___U3CcontainingGroupU3Ek__BackingField_9;
	// UnityEngine.LayerMask UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_InteractionLayerMask
	LayerMask_t97CB6BDADEDC3D6423C7BCFEA7F86DA2EC6241DB ___m_InteractionLayerMask_10;
	// UnityEngine.XR.Interaction.Toolkit.InteractionLayerMask UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_InteractionLayers
	InteractionLayerMask_t3B3480A4A5E1E0C43314C0D2CEB3BB39175E1FD4 ___m_InteractionLayers_11;
	// UnityEngine.Transform UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_AttachTransform
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___m_AttachTransform_12;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_KeepSelectedTargetValid
	bool ___m_KeepSelectedTargetValid_13;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_DisableVisualsWhenBlockedInGroup
	bool ___m_DisableVisualsWhenBlockedInGroup_14;
	// UnityEngine.XR.Interaction.Toolkit.XRBaseInteractable UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_StartingSelectedInteractable
	XRBaseInteractable_tC2C966C710AE6AC232E248B1BCF323386110D0F6* ___m_StartingSelectedInteractable_15;
	// UnityEngine.XR.Interaction.Toolkit.Filtering.XRBaseTargetFilter UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_StartingTargetFilter
	XRBaseTargetFilter_t24D9DBCEA900DFEA08D543C91DFC070C1C91594F* ___m_StartingTargetFilter_16;
	// UnityEngine.XR.Interaction.Toolkit.HoverEnterEvent UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_HoverEntered
	HoverEnterEvent_t2BDBCA14FF94DA18C9AC12B43297F6C1641788AB* ___m_HoverEntered_17;
	// UnityEngine.XR.Interaction.Toolkit.HoverExitEvent UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_HoverExited
	HoverExitEvent_t256704BC79FE0AA61EB2DE3FDDF43A1FC97F5832* ___m_HoverExited_18;
	// UnityEngine.XR.Interaction.Toolkit.SelectEnterEvent UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_SelectEntered
	SelectEnterEvent_tBA2614C8C25D8794D5804C4F66195D74E64FC5D0* ___m_SelectEntered_19;
	// UnityEngine.XR.Interaction.Toolkit.SelectExitEvent UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_SelectExited
	SelectExitEvent_t15DC0A39F9657BA9E6BAE6250D8D64C9671201F6* ___m_SelectExited_20;
	// UnityEngine.XR.Interaction.Toolkit.Filtering.IXRTargetFilter UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_TargetFilter
	RuntimeObject* ___m_TargetFilter_21;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_AllowHover
	bool ___m_AllowHover_22;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_AllowSelect
	bool ___m_AllowSelect_23;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_IsPerformingManualInteraction
	bool ___m_IsPerformingManualInteraction_24;
	// Unity.XR.CoreUtils.Collections.HashSetList`1<UnityEngine.XR.Interaction.Toolkit.IXRHoverInteractable> UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_InteractablesHovered
	HashSetList_1_tC521CA1513DA32AFAD8144C7529793E24EA52945* ___m_InteractablesHovered_25;
	// Unity.XR.CoreUtils.Collections.HashSetList`1<UnityEngine.XR.Interaction.Toolkit.IXRSelectInteractable> UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_InteractablesSelected
	HashSetList_1_t4D485A2E14AF33326E4D8B5E60BEDD0E47CEE3F0* ___m_InteractablesSelected_26;
	// UnityEngine.XR.Interaction.Toolkit.IXRSelectInteractable UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::<firstInteractableSelected>k__BackingField
	RuntimeObject* ___U3CfirstInteractableSelectedU3Ek__BackingField_27;
	// System.Collections.Generic.List`1<UnityEngine.Object> UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_StartingHoverFilters
	List_1_t9A2E2984B23260AECDFA90CEB1F2887075FA4DF3* ___m_StartingHoverFilters_28;
	// UnityEngine.XR.Interaction.Toolkit.Utilities.ExposedRegistrationList`1<UnityEngine.XR.Interaction.Toolkit.Filtering.IXRHoverFilter> UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_HoverFilters
	ExposedRegistrationList_1_t11A438A04DF188A3BE1950639AAF0CBFAF9065A5* ___m_HoverFilters_29;
	// System.Collections.Generic.List`1<UnityEngine.Object> UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_StartingSelectFilters
	List_1_t9A2E2984B23260AECDFA90CEB1F2887075FA4DF3* ___m_StartingSelectFilters_30;
	// UnityEngine.XR.Interaction.Toolkit.Utilities.ExposedRegistrationList`1<UnityEngine.XR.Interaction.Toolkit.Filtering.IXRSelectFilter> UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_SelectFilters
	ExposedRegistrationList_1_t0AF641D8E06922C1FFAF3DA223105F57CE5BC4D8* ___m_SelectFilters_31;
	// Unity.XR.CoreUtils.Bindings.Variables.BindableVariable`1<System.Single> UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_LargestInteractionStrength
	BindableVariable_1_tAB8C2D23769D801C8E39D4AA927DD23AF0E6816C* ___m_LargestInteractionStrength_32;
	// System.Collections.Generic.Dictionary`2<UnityEngine.XR.Interaction.Toolkit.IXRSelectInteractable,UnityEngine.Pose> UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_AttachPoseOnSelect
	Dictionary_2_tC8CDB97AFC9E538A6AF3126874A321065572174C* ___m_AttachPoseOnSelect_33;
	// System.Collections.Generic.Dictionary`2<UnityEngine.XR.Interaction.Toolkit.IXRSelectInteractable,UnityEngine.Pose> UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_LocalAttachPoseOnSelect
	Dictionary_2_tC8CDB97AFC9E538A6AF3126874A321065572174C* ___m_LocalAttachPoseOnSelect_34;
	// Unity.XR.CoreUtils.Collections.HashSetList`1<UnityEngine.XR.Interaction.Toolkit.IXRInteractionStrengthInteractable> UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_InteractionStrengthInteractables
	HashSetList_1_tC1867B681AE7023306C341F97E7483BB3C8532B2* ___m_InteractionStrengthInteractables_35;
	// System.Collections.Generic.Dictionary`2<UnityEngine.XR.Interaction.Toolkit.IXRInteractable,System.Single> UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_InteractionStrengths
	Dictionary_2_tEABA4693399BB94F9F9031F041277F4D01CA9BB2* ___m_InteractionStrengths_36;
	// UnityEngine.XR.Interaction.Toolkit.IXRSelectInteractable UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_ManualInteractionInteractable
	RuntimeObject* ___m_ManualInteractionInteractable_37;
	// UnityEngine.XR.Interaction.Toolkit.XRInteractionManager UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_RegisteredInteractionManager
	XRInteractionManager_t93C7F7F0CFEAD83E1A70F92D05B0E663483746CD* ___m_RegisteredInteractionManager_38;
	// UnityEngine.Transform UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_XROriginTransform
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___m_XROriginTransform_40;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_HasXROrigin
	bool ___m_HasXROrigin_41;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_FailedToFindXROrigin
	bool ___m_FailedToFindXROrigin_42;
	// UnityEngine.XR.Interaction.Toolkit.TargetPriorityMode UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::<targetPriorityMode>k__BackingField
	int32_t ___U3CtargetPriorityModeU3Ek__BackingField_43;
	// System.Collections.Generic.List`1<UnityEngine.XR.Interaction.Toolkit.IXRSelectInteractable> UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::<targetsForSelection>k__BackingField
	List_1_tC3FDFEE51803D5C604CED1C088BC2B8A566E0E5B* ___U3CtargetsForSelectionU3Ek__BackingField_44;
	// UnityEngine.XR.Interaction.Toolkit.XRInteractorEvent UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_OnHoverEntered
	XRInteractorEvent_tA90E755406526412871F25BB621E7F4536CD00E2* ___m_OnHoverEntered_45;
	// UnityEngine.XR.Interaction.Toolkit.XRInteractorEvent UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_OnHoverExited
	XRInteractorEvent_tA90E755406526412871F25BB621E7F4536CD00E2* ___m_OnHoverExited_46;
	// UnityEngine.XR.Interaction.Toolkit.XRInteractorEvent UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_OnSelectEntered
	XRInteractorEvent_tA90E755406526412871F25BB621E7F4536CD00E2* ___m_OnSelectEntered_47;
	// UnityEngine.XR.Interaction.Toolkit.XRInteractorEvent UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::m_OnSelectExited
	XRInteractorEvent_tA90E755406526412871F25BB621E7F4536CD00E2* ___m_OnSelectExited_48;
	// System.Collections.Generic.List`1<UnityEngine.XR.Interaction.Toolkit.XRBaseInteractable> UnityEngine.XR.Interaction.Toolkit.XRBaseInteractor::<hoverTargets>k__BackingField
	List_1_t02510C493B34D49F210C22C40442D863A08509CB* ___U3ChoverTargetsU3Ek__BackingField_49;
};

// UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor
struct XRBaseControllerInteractor_t718A447F8F3D646B51B42E1FAFEA2C1A1EF1C66E  : public XRBaseInteractor_tB48889E8D95695ABF46D2012EC55EA660103D158
{
	// UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor/InputTriggerType UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_SelectActionTrigger
	int32_t ___m_SelectActionTrigger_50;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_HideControllerOnSelect
	bool ___m_HideControllerOnSelect_51;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_AllowHoveredActivate
	bool ___m_AllowHoveredActivate_52;
	// UnityEngine.XR.Interaction.Toolkit.TargetPriorityMode UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_TargetPriorityMode
	int32_t ___m_TargetPriorityMode_53;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_PlayAudioClipOnSelectEntered
	bool ___m_PlayAudioClipOnSelectEntered_54;
	// UnityEngine.AudioClip UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_AudioClipForOnSelectEntered
	AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* ___m_AudioClipForOnSelectEntered_55;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_PlayAudioClipOnSelectExited
	bool ___m_PlayAudioClipOnSelectExited_56;
	// UnityEngine.AudioClip UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_AudioClipForOnSelectExited
	AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* ___m_AudioClipForOnSelectExited_57;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_PlayAudioClipOnSelectCanceled
	bool ___m_PlayAudioClipOnSelectCanceled_58;
	// UnityEngine.AudioClip UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_AudioClipForOnSelectCanceled
	AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* ___m_AudioClipForOnSelectCanceled_59;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_PlayAudioClipOnHoverEntered
	bool ___m_PlayAudioClipOnHoverEntered_60;
	// UnityEngine.AudioClip UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_AudioClipForOnHoverEntered
	AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* ___m_AudioClipForOnHoverEntered_61;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_PlayAudioClipOnHoverExited
	bool ___m_PlayAudioClipOnHoverExited_62;
	// UnityEngine.AudioClip UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_AudioClipForOnHoverExited
	AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* ___m_AudioClipForOnHoverExited_63;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_PlayAudioClipOnHoverCanceled
	bool ___m_PlayAudioClipOnHoverCanceled_64;
	// UnityEngine.AudioClip UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_AudioClipForOnHoverCanceled
	AudioClip_t5D272C4EB4F2D3ED49F1C346DEA373CF6D585F20* ___m_AudioClipForOnHoverCanceled_65;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_AllowHoverAudioWhileSelecting
	bool ___m_AllowHoverAudioWhileSelecting_66;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_PlayHapticsOnSelectEntered
	bool ___m_PlayHapticsOnSelectEntered_67;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_HapticSelectEnterIntensity
	float ___m_HapticSelectEnterIntensity_68;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_HapticSelectEnterDuration
	float ___m_HapticSelectEnterDuration_69;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_PlayHapticsOnSelectExited
	bool ___m_PlayHapticsOnSelectExited_70;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_HapticSelectExitIntensity
	float ___m_HapticSelectExitIntensity_71;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_HapticSelectExitDuration
	float ___m_HapticSelectExitDuration_72;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_PlayHapticsOnSelectCanceled
	bool ___m_PlayHapticsOnSelectCanceled_73;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_HapticSelectCancelIntensity
	float ___m_HapticSelectCancelIntensity_74;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_HapticSelectCancelDuration
	float ___m_HapticSelectCancelDuration_75;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_PlayHapticsOnHoverEntered
	bool ___m_PlayHapticsOnHoverEntered_76;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_HapticHoverEnterIntensity
	float ___m_HapticHoverEnterIntensity_77;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_HapticHoverEnterDuration
	float ___m_HapticHoverEnterDuration_78;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_PlayHapticsOnHoverExited
	bool ___m_PlayHapticsOnHoverExited_79;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_HapticHoverExitIntensity
	float ___m_HapticHoverExitIntensity_80;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_HapticHoverExitDuration
	float ___m_HapticHoverExitDuration_81;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_PlayHapticsOnHoverCanceled
	bool ___m_PlayHapticsOnHoverCanceled_82;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_HapticHoverCancelIntensity
	float ___m_HapticHoverCancelIntensity_83;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_HapticHoverCancelDuration
	float ___m_HapticHoverCancelDuration_84;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_AllowHoverHapticsWhileSelecting
	bool ___m_AllowHoverHapticsWhileSelecting_85;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_AllowActivate
	bool ___m_AllowActivate_86;
	// UnityEngine.XR.Interaction.Toolkit.XRBaseController UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_Controller
	XRBaseController_t44C1BB30A7E1D279DD2508F34D3352B33A9AD60C* ___m_Controller_87;
	// UnityEngine.XR.Interaction.Toolkit.Utilities.Pooling.LinkedPool`1<UnityEngine.XR.Interaction.Toolkit.ActivateEventArgs> UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_ActivateEventArgs
	LinkedPool_1_t99CFF33CB8085652A0F2FC6579D0388FB3CBAA01* ___m_ActivateEventArgs_88;
	// UnityEngine.XR.Interaction.Toolkit.Utilities.Pooling.LinkedPool`1<UnityEngine.XR.Interaction.Toolkit.DeactivateEventArgs> UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_DeactivateEventArgs
	LinkedPool_1_t0F5C109EA19EF35798DEF24B63645919D0B7B53B* ___m_DeactivateEventArgs_89;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_ToggleSelectActive
	bool ___m_ToggleSelectActive_91;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_ToggleSelectDeactivatedThisFrame
	bool ___m_ToggleSelectDeactivatedThisFrame_92;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_WaitingForSelectDeactivate
	bool ___m_WaitingForSelectDeactivate_93;
	// UnityEngine.AudioSource UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::m_EffectsAudioSource
	AudioSource_t871AC2272F896738252F04EE949AEF5B241D3299* ___m_EffectsAudioSource_94;
	// System.Collections.Generic.List`1<UnityEngine.XR.Interaction.Toolkit.XRBaseInteractable> UnityEngine.XR.Interaction.Toolkit.XRBaseControllerInteractor::<validTargets>k__BackingField
	List_1_t02510C493B34D49F210C22C40442D863A08509CB* ___U3CvalidTargetsU3Ek__BackingField_95;
};

// UnityEngine.XR.Interaction.Toolkit.XRRayInteractor
struct XRRayInteractor_t0B25C1D5A938B199A71908E189AB351B43DA4C76  : public XRBaseControllerInteractor_t718A447F8F3D646B51B42E1FAFEA2C1A1EF1C66E
{
	// UnityEngine.XR.Interaction.Toolkit.XRRayInteractor/LineType UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_LineType
	int32_t ___m_LineType_103;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_BlendVisualLinePoints
	bool ___m_BlendVisualLinePoints_104;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_MaxRaycastDistance
	float ___m_MaxRaycastDistance_105;
	// UnityEngine.Transform UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_RayOriginTransform
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___m_RayOriginTransform_106;
	// UnityEngine.Transform UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_ReferenceFrame
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___m_ReferenceFrame_107;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_Velocity
	float ___m_Velocity_108;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_Acceleration
	float ___m_Acceleration_109;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_AdditionalGroundHeight
	float ___m_AdditionalGroundHeight_110;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_AdditionalFlightTime
	float ___m_AdditionalFlightTime_111;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_EndPointDistance
	float ___m_EndPointDistance_112;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_EndPointHeight
	float ___m_EndPointHeight_113;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_ControlPointDistance
	float ___m_ControlPointDistance_114;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_ControlPointHeight
	float ___m_ControlPointHeight_115;
	// System.Int32 UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_SampleFrequency
	int32_t ___m_SampleFrequency_116;
	// UnityEngine.XR.Interaction.Toolkit.XRRayInteractor/HitDetectionType UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_HitDetectionType
	int32_t ___m_HitDetectionType_117;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_SphereCastRadius
	float ___m_SphereCastRadius_118;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_ConeCastAngle
	float ___m_ConeCastAngle_119;
	// UnityEngine.LayerMask UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_RaycastMask
	LayerMask_t97CB6BDADEDC3D6423C7BCFEA7F86DA2EC6241DB ___m_RaycastMask_120;
	// UnityEngine.QueryTriggerInteraction UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_RaycastTriggerInteraction
	int32_t ___m_RaycastTriggerInteraction_121;
	// UnityEngine.XR.Interaction.Toolkit.XRRayInteractor/QuerySnapVolumeInteraction UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_RaycastSnapVolumeInteraction
	int32_t ___m_RaycastSnapVolumeInteraction_122;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_HitClosestOnly
	bool ___m_HitClosestOnly_123;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_HoverToSelect
	bool ___m_HoverToSelect_124;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_HoverTimeToSelect
	float ___m_HoverTimeToSelect_125;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_AutoDeselect
	bool ___m_AutoDeselect_126;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_TimeToAutoDeselect
	float ___m_TimeToAutoDeselect_127;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_EnableUIInteraction
	bool ___m_EnableUIInteraction_128;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_BlockUIOnInteractableSelection
	bool ___m_BlockUIOnInteractableSelection_129;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_AllowAnchorControl
	bool ___m_AllowAnchorControl_130;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_UseForceGrab
	bool ___m_UseForceGrab_131;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_RotateSpeed
	float ___m_RotateSpeed_132;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_TranslateSpeed
	float ___m_TranslateSpeed_133;
	// UnityEngine.Transform UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_AnchorRotateReferenceFrame
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___m_AnchorRotateReferenceFrame_134;
	// UnityEngine.XR.Interaction.Toolkit.XRRayInteractor/AnchorRotationMode UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_AnchorRotationMode
	int32_t ___m_AnchorRotationMode_135;
	// UnityEngine.XR.Interaction.Toolkit.UI.UIHoverEnterEvent UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_UIHoverEntered
	UIHoverEnterEvent_t4C957A3405A5D9CB867C5EC446620BB4BA7E7298* ___m_UIHoverEntered_136;
	// UnityEngine.XR.Interaction.Toolkit.UI.UIHoverExitEvent UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_UIHoverExited
	UIHoverExitEvent_t63E5E9C921AFB8E2CB9CA4D32882DD4F62CD509B* ___m_UIHoverExited_137;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_EnableARRaycasting
	bool ___m_EnableARRaycasting_138;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_OccludeARHitsWith3DObjects
	bool ___m_OccludeARHitsWith3DObjects_139;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_OccludeARHitsWith2DObjects
	bool ___m_OccludeARHitsWith2DObjects_140;
	// UnityEngine.XR.Interaction.Toolkit.IXRInteractable UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::<currentNearestValidTarget>k__BackingField
	RuntimeObject* ___U3CcurrentNearestValidTargetU3Ek__BackingField_141;
	// UnityEngine.Vector3 UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::<rayEndPoint>k__BackingField
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___U3CrayEndPointU3Ek__BackingField_142;
	// UnityEngine.Transform UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::<rayEndTransform>k__BackingField
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___U3CrayEndTransformU3Ek__BackingField_143;
	// UnityEngine.XR.Interaction.Toolkit.ScaleMode UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_ScaleMode
	int32_t ___m_ScaleMode_144;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::<scaleValue>k__BackingField
	float ___U3CscaleValueU3Ek__BackingField_145;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_HasRayOriginTransform
	bool ___m_HasRayOriginTransform_146;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_HasReferenceFrame
	bool ___m_HasReferenceFrame_147;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_ScaleInputActive
	bool ___m_ScaleInputActive_148;
	// System.Collections.Generic.List`1<UnityEngine.XR.Interaction.Toolkit.IXRInteractable> UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_ValidTargets
	List_1_t3B3CED900C4A273E3B63AAB5493C4D6D4B112810* ___m_ValidTargets_149;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_LastTimeHoveredObjectChanged
	float ___m_LastTimeHoveredObjectChanged_150;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_PassedHoverTimeToSelect
	bool ___m_PassedHoverTimeToSelect_151;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_LastTimeAutoSelected
	float ___m_LastTimeAutoSelected_152;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_PassedTimeToAutoDeselect
	bool ___m_PassedTimeToAutoDeselect_153;
	// UnityEngine.GameObject UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_LastUIObject
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___m_LastUIObject_154;
	// System.Single UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_LastTimeHoveredUIChanged
	float ___m_LastTimeHoveredUIChanged_155;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_HoverUISelectActive
	bool ___m_HoverUISelectActive_156;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_BlockUIAutoDeselect
	bool ___m_BlockUIAutoDeselect_157;
	// UnityEngine.RaycastHit[] UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_RaycastHits
	RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8* ___m_RaycastHits_158;
	// System.Int32 UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_RaycastHitsCount
	int32_t ___m_RaycastHitsCount_159;
	// UnityEngine.XR.Interaction.Toolkit.XRRayInteractor/RaycastHitComparer UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_RaycastHitComparer
	RaycastHitComparer_tC59C36D577B7426F5EE8E3AE65B988F953757E9D* ___m_RaycastHitComparer_160;
	// System.Collections.Generic.List`1<UnityEngine.XR.Interaction.Toolkit.XRRayInteractor/SamplePoint> UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_SamplePoints
	List_1_tC0F6311D5ACC55EC4184D225E50673DBDAC555BD* ___m_SamplePoints_161;
	// System.Int32 UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_SamplePointsFrameUpdated
	int32_t ___m_SamplePointsFrameUpdated_162;
	// System.Int32 UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_RaycastHitEndpointIndex
	int32_t ___m_RaycastHitEndpointIndex_163;
	// System.Int32 UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_UIRaycastHitEndpointIndex
	int32_t ___m_UIRaycastHitEndpointIndex_164;
	// Unity.Mathematics.float3[] UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_ControlPoints
	float3U5BU5D_t94C1DF28FA7E0FA017D0C77B720D9FF3519E0D45* ___m_ControlPoints_165;
	// Unity.Mathematics.float3[] UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_HitChordControlPoints
	float3U5BU5D_t94C1DF28FA7E0FA017D0C77B720D9FF3519E0D45* ___m_HitChordControlPoints_166;
	// UnityEngine.PhysicsScene UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_LocalPhysicsScene
	PhysicsScene_t55222DD37072E8560EE054A07C0E3FE391D9D9DE ___m_LocalPhysicsScene_169;
	// UnityEngine.XR.Interaction.Toolkit.UI.RegisteredUIInteractorCache UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_RegisteredUIInteractorCache
	RegisteredUIInteractorCache_t81419313AA113B206AF3FF94CD9D3B64A09CE413* ___m_RegisteredUIInteractorCache_170;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_RaycastHitOccurred
	bool ___m_RaycastHitOccurred_171;
	// UnityEngine.RaycastHit UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_RaycastHit
	RaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5 ___m_RaycastHit_172;
	// UnityEngine.EventSystems.RaycastResult UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_UIRaycastHit
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 ___m_UIRaycastHit_173;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_IsUIHitClosest
	bool ___m_IsUIHitClosest_174;
	// UnityEngine.XR.Interaction.Toolkit.IXRInteractable UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_RaycastInteractable
	RuntimeObject* ___m_RaycastInteractable_175;
	// UnityEngine.XR.Interaction.Toolkit.ActionBasedController UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_ActionBasedController
	ActionBasedController_tB9D8E7E013191571EA5507EA68057414B6969A68* ___m_ActionBasedController_176;
	// UnityEngine.XR.Interaction.Toolkit.XRController UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_DeviceBasedController
	XRController_t928E104C899E51FDE12C0A8AC68874587C46C28F* ___m_DeviceBasedController_177;
	// UnityEngine.XR.Interaction.Toolkit.XRScreenSpaceController UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_ScreenSpaceController
	XRScreenSpaceController_t046F18C2FE01EB347832DB82D42C84131771FF17* ___m_ScreenSpaceController_178;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_IsActionBasedController
	bool ___m_IsActionBasedController_179;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_IsDeviceBasedController
	bool ___m_IsDeviceBasedController_180;
	// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::m_IsScreenSpaceController
	bool ___m_IsScreenSpaceController_181;
};

// <>f__AnonymousType0`1<System.Int32>

// <>f__AnonymousType0`1<System.Int32>

// System.Collections.Generic.Dictionary`2<System.Int32,com.picoxr.tobframwork.Timer/Handle>

// System.Collections.Generic.Dictionary`2<System.Int32,com.picoxr.tobframwork.Timer/Handle>

// System.Collections.Generic.Dictionary`2<System.String,System.Delegate>

// System.Collections.Generic.Dictionary`2<System.String,System.Delegate>

// System.Collections.Generic.Dictionary`2<System.Type,System.Int32>

// System.Collections.Generic.Dictionary`2<System.Type,System.Int32>

// System.Collections.Generic.Dictionary`2<System.Type,com.picoxr.tobframwork.UIPage>

// System.Collections.Generic.Dictionary`2<System.Type,com.picoxr.tobframwork.UIPage>

// System.Collections.Generic.List`1<System.Collections.Generic.List`1<System.Int32>>
struct List_1_tB5A0E21D0A7C39DF93D616FD5B94C4737A083E35_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	List_1U5BU5D_t37294D7C303231F2FD83B3C398AED0937F4F3206* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<System.Collections.Generic.List`1<System.Int32>>

// System.Collections.Generic.List`1<System.Collections.Generic.List`1<System.Single>>
struct List_1_tFF2BC422A193D7F048E03ABCCC32292E892A12F7_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	List_1U5BU5D_tB3324071AD89A3E4C72B73C6C5D42DCAC9EC993F* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<System.Collections.Generic.List`1<System.Single>>

// System.Collections.Generic.List`1<System.Collections.Generic.List`1<UnityEngine.Vector3>>
struct List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	List_1U5BU5D_tC1B009E92641A2C993F3BB28A80D61D2AB67979B* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<System.Collections.Generic.List`1<UnityEngine.Vector3>>

// System.Collections.Generic.List`1<Boundary.Data.BoundaryItem>
struct List_1_t9B1B27900D11844BED9AD08E793EE74AB63688C5_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	BoundaryItemU5BU5D_tFA1A2813C2E9A578225D157CCDC1532B27EC7221* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<Boundary.Data.BoundaryItem>

// System.Collections.Generic.List`1<System.Int32>
struct List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<System.Int32>

// System.Collections.Generic.List`1<Boundary.Data.Item>
struct List_1_tDCE834B5223117F51ED29F0327C1C20731F3D0CD_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	ItemU5BU5D_t1BB908030FAE0B323EDC9CD4CE537EB6B9A6CB49* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<Boundary.Data.Item>

// System.Collections.Generic.List`1<System.Object>
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<System.Object>

// System.Collections.Generic.List`1<UnityEngine.Vector3>
struct List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<UnityEngine.Vector3>

// System.Collections.Generic.List`1<com.picoxr.tobframwork.Timer/Handle>
struct List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	HandleU5BU5D_t32660A977D98D1266A234A1C5378D6A41C9A30C7* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<com.picoxr.tobframwork.Timer/Handle>

// System.Collections.Generic.Queue`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo>

// System.Collections.Generic.Queue`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo>

// <PrivateImplementationDetails>
struct U3CPrivateImplementationDetailsU3E_t0F5473E849A5A5185A9F4C5246F0C32816C49FCA_StaticFields
{
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=24 <PrivateImplementationDetails>::3ADF2F3CB4A6A8DD46D21F3ACF546E2D819D40F31F528B977721979506B436C1
	__StaticArrayInitTypeSizeU3D24_t3464DA68B6CCAB9A0A43F94B3DB9AA7E7FDDB19A ___3ADF2F3CB4A6A8DD46D21F3ACF546E2D819D40F31F528B977721979506B436C1_0;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=24 <PrivateImplementationDetails>::723D3A8F43BF3C213C1D1EA16EDFFE015BE443C1FBA6B408CE4CEA496EEB91C0
	__StaticArrayInitTypeSizeU3D24_t3464DA68B6CCAB9A0A43F94B3DB9AA7E7FDDB19A ___723D3A8F43BF3C213C1D1EA16EDFFE015BE443C1FBA6B408CE4CEA496EEB91C0_1;
};

// <PrivateImplementationDetails>

// Boundary.Data.AlgorithmData

// Boundary.Data.AlgorithmData

// Boundary.Data.BoundaryConfigData

// Boundary.Data.BoundaryConfigData

// Boundary.Data.BoundaryData

// Boundary.Data.BoundaryData

// Boundary.Data.BoundaryItem

// Boundary.Data.BoundaryItem

// Jeffijoe.MessageFormat.CustomValueFormatter

// Jeffijoe.MessageFormat.CustomValueFormatter

// com.picoxr.tobframwork.EventManager
struct EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_StaticFields
{
	// System.Collections.Generic.Dictionary`2<System.String,System.Delegate> com.picoxr.tobframwork.EventManager::listenerDic
	Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* ___listenerDic_0;
};

// com.picoxr.tobframwork.EventManager

// Boundary.Data.Item

// Boundary.Data.Item

// com.picoxr.tobframwork.LanguageUtils
struct LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_StaticFields
{
	// System.Text.StringBuilder com.picoxr.tobframwork.LanguageUtils::strBuilder
	StringBuilder_t* ___strBuilder_0;
	// Jeffijoe.MessageFormat.MessageFormatter com.picoxr.tobframwork.LanguageUtils::_messageFormatter
	MessageFormatter_t59AB4D9D22B9B2403C45FF755A0AB60223D2035F* ____messageFormatter_1;
};

// com.picoxr.tobframwork.LanguageUtils

// System.Reflection.MemberInfo

// System.Reflection.MemberInfo

// Jeffijoe.MessageFormat.MessageFormatter
struct MessageFormatter_t59AB4D9D22B9B2403C45FF755A0AB60223D2035F_StaticFields
{
	// Jeffijoe.MessageFormat.IMessageFormatter Jeffijoe.MessageFormat.MessageFormatter::Instance
	RuntimeObject* ___Instance_0;
	// System.Object Jeffijoe.MessageFormat.MessageFormatter::Lock
	RuntimeObject* ___Lock_1;
};

// Jeffijoe.MessageFormat.MessageFormatter

// BoundarySystem_Ext.Pvr_BoundaryAPI

// BoundarySystem_Ext.Pvr_BoundaryAPI

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI

// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule
struct Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05_StaticFields
{
	// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule BoundarySystem_Ext.Pvr_SafeAreaAlgoModule::instance
	Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05* ___instance_0;
};

// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule

// System.String
struct String_t_StaticFields
{
	// System.String System.String::Empty
	String_t* ___Empty_6;
};

// System.String

// System.Text.StringBuilder

// System.Text.StringBuilder

// com.picoxr.tobframwork.Unitls

// com.picoxr.tobframwork.Unitls

// Unity.XR.PXR.PXR_Plugin/System
struct System_t4255BA2E24C230336F7C003E6DD13B25588178DB_StaticFields
{
	// System.Action Unity.XR.PXR.PXR_Plugin/System::RecenterSuccess
	Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___RecenterSuccess_0;
	// System.Action Unity.XR.PXR.PXR_Plugin/System::FocusStateAcquired
	Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___FocusStateAcquired_1;
	// System.Action Unity.XR.PXR.PXR_Plugin/System::FocusStateLost
	Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___FocusStateLost_2;
	// System.Action Unity.XR.PXR.PXR_Plugin/System::SensorReady
	Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___SensorReady_3;
	// System.Action`1<System.Int32> Unity.XR.PXR.PXR_Plugin/System::SessionStateChanged
	Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* ___SessionStateChanged_4;
	// System.Action`1<System.Int32> Unity.XR.PXR.PXR_Plugin/System::InputDeviceChanged
	Action_1_tD69A6DC9FBE94131E52F5A73B2A9D4AB51EEC404* ___InputDeviceChanged_5;
	// System.Action`1<System.Single> Unity.XR.PXR.PXR_Plugin/System::DisplayRefreshRateChangedAction
	Action_1_t310F18CB4338A2740CA701F160C62E2C3198E66A* ___DisplayRefreshRateChangedAction_6;
	// System.String Unity.XR.PXR.PXR_Plugin/System::ProductName
	String_t* ___ProductName_7;
	// System.Boolean Unity.XR.PXR.PXR_Plugin/System::lastAppFocusState
	bool ___lastAppFocusState_8;
	// System.Boolean Unity.XR.PXR.PXR_Plugin/System::lastSensorReadyState
	bool ___lastSensorReadyState_9;
	// UnityEngine.AndroidJavaClass Unity.XR.PXR.PXR_Plugin/System::unityPlayer
	AndroidJavaClass_tE6296B30CC4BF84434A9B765267F3FD0DD8DDB03* ___unityPlayer_11;
	// UnityEngine.AndroidJavaObject Unity.XR.PXR.PXR_Plugin/System::currentActivity
	AndroidJavaObject_t8FFB930F335C1178405B82AC2BF512BB1EEF9EB0* ___currentActivity_12;
	// UnityEngine.AndroidJavaClass Unity.XR.PXR.PXR_Plugin/System::sysActivity
	AndroidJavaClass_tE6296B30CC4BF84434A9B765267F3FD0DD8DDB03* ___sysActivity_13;
	// UnityEngine.AndroidJavaClass Unity.XR.PXR.PXR_Plugin/System::batteryReceiver
	AndroidJavaClass_tE6296B30CC4BF84434A9B765267F3FD0DD8DDB03* ___batteryReceiver_14;
	// UnityEngine.AndroidJavaClass Unity.XR.PXR.PXR_Plugin/System::audioReceiver
	AndroidJavaClass_tE6296B30CC4BF84434A9B765267F3FD0DD8DDB03* ___audioReceiver_15;
	// System.Boolean Unity.XR.PXR.PXR_Plugin/System::isInitAudio
	bool ___isInitAudio_16;
};

// Unity.XR.PXR.PXR_Plugin/System

// com.picoxr.tobframwork.Timer/Handle
struct Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5_StaticFields
{
	// System.Int32 com.picoxr.tobframwork.Timer/Handle::_id
	int32_t ____id_6;
};

// com.picoxr.tobframwork.Timer/Handle

// System.Collections.Generic.KeyValuePair`2<System.Int32,System.Object>

// System.Collections.Generic.KeyValuePair`2<System.Int32,System.Object>

// System.Collections.Generic.KeyValuePair`2<System.Int32,com.picoxr.tobframwork.Timer/Handle>

// System.Collections.Generic.KeyValuePair`2<System.Int32,com.picoxr.tobframwork.Timer/Handle>

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	// System.String System.Boolean::TrueString
	String_t* ___TrueString_5;
	// System.String System.Boolean::FalseString
	String_t* ___FalseString_6;
};

// System.Boolean

// System.Char
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17_StaticFields
{
	// System.Byte[] System.Char::s_categoryForLatin1
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___s_categoryForLatin1_3;
};

// System.Char

// System.Double

// System.Double

// System.Enum
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_StaticFields
{
	// System.Char[] System.Enum::enumSeperatorCharArray
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___enumSeperatorCharArray_0;
};

// System.Enum

// System.Int32

// System.Int32

// System.Int64

// System.Int64

// System.IntPtr
struct IntPtr_t_StaticFields
{
	// System.IntPtr System.IntPtr::Zero
	intptr_t ___Zero_1;
};

// System.IntPtr

// System.Single

// System.Single

// System.UInt32

// System.UInt32

// System.UInt64

// System.UInt64

// UnityEngine.Vector3
struct Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_StaticFields
{
	// UnityEngine.Vector3 UnityEngine.Vector3::zeroVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___zeroVector_5;
	// UnityEngine.Vector3 UnityEngine.Vector3::oneVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___oneVector_6;
	// UnityEngine.Vector3 UnityEngine.Vector3::upVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___upVector_7;
	// UnityEngine.Vector3 UnityEngine.Vector3::downVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___downVector_8;
	// UnityEngine.Vector3 UnityEngine.Vector3::leftVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___leftVector_9;
	// UnityEngine.Vector3 UnityEngine.Vector3::rightVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___rightVector_10;
	// UnityEngine.Vector3 UnityEngine.Vector3::forwardVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___forwardVector_11;
	// UnityEngine.Vector3 UnityEngine.Vector3::backVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___backVector_12;
	// UnityEngine.Vector3 UnityEngine.Vector3::positiveInfinityVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___positiveInfinityVector_13;
	// UnityEngine.Vector3 UnityEngine.Vector3::negativeInfinityVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___negativeInfinityVector_14;
};

// UnityEngine.Vector3

// System.Void

// System.Void

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=24

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=24

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALegalData

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALegalData

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i

// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/ExtraInfo

// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/ExtraInfo

// System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>

// System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>

// System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,com.picoxr.tobframwork.Timer/Handle>

// System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,com.picoxr.tobframwork.Timer/Handle>

// System.Delegate

// System.Delegate

// System.Exception
struct Exception_t_StaticFields
{
	// System.Object System.Exception::s_EDILock
	RuntimeObject* ___s_EDILock_0;
};

// System.Exception

// System.Reflection.MethodInfo

// System.Reflection.MethodInfo

// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_StaticFields
{
	// System.Int32 UnityEngine.Object::OffsetOfInstanceIDInCPlusPlusObject
	int32_t ___OffsetOfInstanceIDInCPlusPlusObject_1;
};

// UnityEngine.Object

// BoundarySystem_Ext.Pvr_BoundarySystem
struct Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544_StaticFields
{
	// BoundarySystem_Ext.Pvr_BoundarySystem BoundarySystem_Ext.Pvr_BoundarySystem::instance
	Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544* ___instance_0;
};

// BoundarySystem_Ext.Pvr_BoundarySystem

// System.RuntimeTypeHandle

// System.RuntimeTypeHandle

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALine

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALine

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALineCollection

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALineCollection

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSARect

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSARect

// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundaryPlayerArea

// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundaryPlayerArea

// com.picoxr.blsapce.SpatialTextureToSystem/ScanState

// com.picoxr.blsapce.SpatialTextureToSystem/ScanState

// com.picoxr.blsapce.SpatialTextureToSystem/TextureLevelType

// com.picoxr.blsapce.SpatialTextureToSystem/TextureLevelType

// UnityEngine.Component

// UnityEngine.Component

// UnityEngine.GameObject

// UnityEngine.GameObject

// System.Type
struct Type_t_StaticFields
{
	// System.Reflection.Binder modreq(System.Runtime.CompilerServices.IsVolatile) System.Type::s_defaultBinder
	Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235* ___s_defaultBinder_0;
	// System.Char System.Type::Delimiter
	Il2CppChar ___Delimiter_1;
	// System.Type[] System.Type::EmptyTypes
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___EmptyTypes_2;
	// System.Object System.Type::Missing
	RuntimeObject* ___Missing_3;
	// System.Reflection.MemberFilter System.Type::FilterAttribute
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterAttribute_4;
	// System.Reflection.MemberFilter System.Type::FilterName
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterName_5;
	// System.Reflection.MemberFilter System.Type::FilterNameIgnoreCase
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterNameIgnoreCase_6;
};

// System.Type

// com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo

// com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo

// System.Action`1<System.Boolean>

// System.Action`1<System.Boolean>

// System.Action`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo>

// System.Action`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo>

// System.Action

// System.Action

// System.AsyncCallback

// System.AsyncCallback

// UnityEngine.Transform

// UnityEngine.Transform

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallback

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallback

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallbackShrink

// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallbackShrink

// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundarySystemCallback

// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundarySystemCallback

// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundarySystemCallbackShrink

// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundarySystemCallbackShrink

// com.picoxr.blsapce.SpatialTextureToSystem/CallBackDelegate

// com.picoxr.blsapce.SpatialTextureToSystem/CallBackDelegate

// UnityEngine.MonoBehaviour

// UnityEngine.MonoBehaviour

// com.picoxr.tobframwork.RayHitPoint

// com.picoxr.tobframwork.RayHitPoint

// com.picoxr.blsapce.SpatialTextureMain

// com.picoxr.blsapce.SpatialTextureMain

// com.picoxr.blsapce.SpatialTextureToSystem
struct SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields
{
	// System.IntPtr com.picoxr.blsapce.SpatialTextureToSystem::_spatialtexturePtr
	intptr_t ____spatialtexturePtr_5;
	// com.picoxr.blsapce.SpatialTextureToSystem/CallBackDelegate com.picoxr.blsapce.SpatialTextureToSystem::_callback
	CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC* ____callback_6;
	// System.Collections.Generic.Queue`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo> com.picoxr.blsapce.SpatialTextureToSystem::_receives
	Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9* ____receives_7;
	// com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo com.picoxr.blsapce.SpatialTextureToSystem::_testInfo
	TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 ____testInfo_8;
	// System.Int32 com.picoxr.blsapce.SpatialTextureToSystem::timerId
	int32_t ___timerId_9;
	// System.Boolean com.picoxr.blsapce.SpatialTextureToSystem::_started
	bool ____started_10;
	// System.Boolean com.picoxr.blsapce.SpatialTextureToSystem::TestMode
	bool ___TestMode_11;
	// System.Int32 com.picoxr.blsapce.SpatialTextureToSystem::testNum
	int32_t ___testNum_12;
};

// com.picoxr.blsapce.SpatialTextureToSystem

// com.picoxr.tobframwork.Timer
struct Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0_StaticFields
{
	// com.picoxr.tobframwork.Timer com.picoxr.tobframwork.Timer::_instance
	Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0* ____instance_8;
};

// com.picoxr.tobframwork.Timer

// com.picoxr.tobframwork.UIGroup

// com.picoxr.tobframwork.UIGroup

// com.picoxr.tobframwork.UIPage

// com.picoxr.tobframwork.UIPage

// com.picoxr.tobframwork.UIPageManager
struct UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B_StaticFields
{
	// com.picoxr.tobframwork.UIPageManager com.picoxr.tobframwork.UIPageManager::_instance
	UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B* ____instance_5;
};

// com.picoxr.tobframwork.UIPageManager

// UnityEngine.XR.Interaction.Toolkit.XRRayInteractor
struct XRRayInteractor_t0B25C1D5A938B199A71908E189AB351B43DA4C76_StaticFields
{
	// System.Collections.Generic.List`1<UnityEngine.XR.Interaction.Toolkit.IXRInteractable> UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::s_Results
	List_1_t3B3CED900C4A273E3B63AAB5493C4D6D4B112810* ___s_Results_100;
	// UnityEngine.RaycastHit[] UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::s_SpherecastScratch
	RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8* ___s_SpherecastScratch_101;
	// System.Collections.Generic.HashSet`1<UnityEngine.Collider> UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::s_OptimalHits
	HashSet_1_t109CCE87260348881F7ED50EEE3FFD003542DC8B* ___s_OptimalHits_102;
	// System.Collections.Generic.List`1<UnityEngine.XR.Interaction.Toolkit.XRRayInteractor/SamplePoint> UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::s_ScratchSamplePoints
	List_1_tC0F6311D5ACC55EC4184D225E50673DBDAC555BD* ___s_ScratchSamplePoints_167;
	// Unity.Mathematics.float3[] UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::s_ScratchControlPoints
	float3U5BU5D_t94C1DF28FA7E0FA017D0C77B720D9FF3519E0D45* ___s_ScratchControlPoints_168;
};

// UnityEngine.XR.Interaction.Toolkit.XRRayInteractor
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// System.Delegate[]
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771  : public RuntimeArray
{
	ALIGN_FIELD (8) Delegate_t* m_Items[1];

	inline Delegate_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Delegate_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Delegate_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Delegate_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Delegate_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Delegate_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
// System.String[]
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248  : public RuntimeArray
{
	ALIGN_FIELD (8) String_t* m_Items[1];

	inline String_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline String_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, String_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline String_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline String_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, String_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
// System.Boolean[]
struct BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4  : public RuntimeArray
{
	ALIGN_FIELD (8) bool m_Items[1];

	inline bool GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline bool* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, bool value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline bool GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline bool* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, bool value)
	{
		m_Items[index] = value;
	}
};
// com.picoxr.tobframwork.UIPage[]
struct UIPageU5BU5D_t7F52BDD6ABCD90C3DC53772307DC5681B3D58496  : public RuntimeArray
{
	ALIGN_FIELD (8) UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* m_Items[1];

	inline UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
// System.Int32[]
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C  : public RuntimeArray
{
	ALIGN_FIELD (8) int32_t m_Items[1];

	inline int32_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline int32_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, int32_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline int32_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline int32_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, int32_t value)
	{
		m_Items[index] = value;
	}
};
// UnityEngine.Vector3[]
struct Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C  : public RuntimeArray
{
	ALIGN_FIELD (8) Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 m_Items[1];

	inline Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 value)
	{
		m_Items[index] = value;
	}
};
// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALine[]
struct GSALineU5BU5D_tC2644452FF1B88D2D201F355FA28F65A5D8CF685  : public RuntimeArray
{
	ALIGN_FIELD (8) GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E m_Items[1];

	inline GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E value)
	{
		m_Items[index] = value;
	}
};
// BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i[]
struct GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1  : public RuntimeArray
{
	ALIGN_FIELD (8) GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 m_Items[1];

	inline GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 value)
	{
		m_Items[index] = value;
	}
};
// System.Object[]
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918  : public RuntimeArray
{
	ALIGN_FIELD (8) RuntimeObject* m_Items[1];

	inline RuntimeObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RuntimeObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline RuntimeObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RuntimeObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};

IL2CPP_EXTERN_C void ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshal_pinvoke(const ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54& unmarshaled, ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshaled_pinvoke& marshaled);
IL2CPP_EXTERN_C void ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshal_pinvoke_back(const ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshaled_pinvoke& marshaled, ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54& unmarshaled);
IL2CPP_EXTERN_C void ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshal_pinvoke_cleanup(ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshaled_pinvoke& marshaled);
IL2CPP_EXTERN_C void ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshal_com(const ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54& unmarshaled, ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshaled_com& marshaled);
IL2CPP_EXTERN_C void ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshal_com_back(const ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshaled_com& marshaled, ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54& unmarshaled);
IL2CPP_EXTERN_C void ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshal_com_cleanup(ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshaled_com& marshaled);

// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::Clear()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Clear_mCFB5EA7351D5860D2B91592B91A84CA265A41433_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Object>::TryGetValue(TKey,TValue&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryGetValue_mD15380A4ED7CDEE99EA45881577D26BA9CE1B849_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, RuntimeObject** ___1_value, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Object>::ContainsKey(TKey)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_ContainsKey_m703047C213F7AB55C9DC346596287773A1F670CD_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, const RuntimeMethod* method) ;
// TValue System.Collections.Generic.Dictionary`2<System.Object,System.Object>::get_Item(TKey)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_get_Item_m4AAAECBE902A211BF2126E6AFA280AEF73A3E0D6_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::set_Item(TKey,TValue)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_m1A840355E8EDAECEA9D0C6F5E51B248FAA449CBD_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::Add(TKey,TValue)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Add_m93FFFABE8FCE7FA9793F0915E2A8842C7CD0C0C1_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
// System.Boolean System.Linq.Enumerable::Contains<System.Object>(System.Collections.Generic.IEnumerable`1<TSource>,TSource)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerable_Contains_TisRuntimeObject_mBCDB5870C52FC5BD2B6AE472A749FC03B9CF8958_gshared (RuntimeObject* ___0_source, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Object>::Remove(TKey)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m5C7C45E75D951A75843F3F7AADD56ECD64F6BC86_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m5B32FBC624618211EB461D59CFBB10E987FD1329_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, const RuntimeMethod* method) ;
// T UnityEngine.Component::GetComponent<System.Object>()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Component_GetComponent_TisRuntimeObject_m7181F81CAEC2CF53F5D2BC79B7425C16E1F80D33_gshared (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;
// T[] UnityEngine.Component::GetComponentsInChildren<System.Object>(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* Component_GetComponentsInChildren_TisRuntimeObject_m90734C3A39A158985239CB90DE2F0792F1D99926_gshared (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, bool ___0_includeInactive, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Int32>::set_Item(TKey,TValue)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_m72CC2F1213D1C1B8ABEDE31082D07B67EC873B13_gshared (Dictionary_2_t5C96F4B6841710A9013966F76224BAE01FB4B4D1* __this, RuntimeObject* ___0_key, int32_t ___1_value, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Int32>::TryGetValue(TKey,TValue&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryGetValue_m4B8EE45640C70BBFD6F3EFF1040983404C098342_gshared (Dictionary_2_t5C96F4B6841710A9013966F76224BAE01FB4B4D1* __this, RuntimeObject* ___0_key, int32_t* ___1_value, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Int32>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m517E7F9D104FEAE6646EABDDC9C852510E86077C_gshared (Dictionary_2_t5C96F4B6841710A9013966F76224BAE01FB4B4D1* __this, const RuntimeMethod* method) ;
// T[] UnityEngine.GameObject::GetComponentsInChildren<System.Object>(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* GameObject_GetComponentsInChildren_TisRuntimeObject_m511E687BF2424F8D832EA2EAA459870887FB9540_gshared (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, bool ___0_includeInactive, const RuntimeMethod* method) ;
// T UnityEngine.Component::GetComponentInParent<System.Object>()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Component_GetComponentInParent_TisRuntimeObject_m6746D6BB99912B1B509746C993906492F86CD119_gshared (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;
// System.Void <>f__AnonymousType0`1<System.Int32>::.ctor(<num>j__TPar)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ef__AnonymousType0_1__ctor_mF4E4C5F9CD02AEAF4F890E22441AE2B516285AB6_gshared (U3CU3Ef__AnonymousType0_1_tCC81029179B6F4DAC7D8BC271C35F5CDBC097D55* __this, int32_t ___0_num, const RuntimeMethod* method) ;
// System.Collections.Generic.Dictionary`2/Enumerator<TKey,TValue> System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::GetEnumerator()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tE92C1AC40A104A179B94F8A013728FD9314CFBD3 Dictionary_2_GetEnumerator_m3F1620145BA0815B7C7CD648EF054558AA26556A_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, const RuntimeMethod* method) ;
// System.Collections.Generic.KeyValuePair`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>::get_Current()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR KeyValuePair_2_tDC26B09C26BA829DDE331BCB6AF7C508C763D7A3 Enumerator_get_Current_m90160D324DA0D9F5624A345F47D8E226A118911A_gshared_inline (Enumerator_tE92C1AC40A104A179B94F8A013728FD9314CFBD3* __this, const RuntimeMethod* method) ;
// TValue System.Collections.Generic.KeyValuePair`2<System.Int32,System.Object>::get_Value()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* KeyValuePair_2_get_Value_m8508BCECB0654E2E93B1A141382E2688ADE7EE7C_gshared_inline (KeyValuePair_2_tDC26B09C26BA829DDE331BCB6AF7C508C763D7A3* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::Add(T)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Int32>::Add(T)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_gshared_inline (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, int32_t ___0_item, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>::MoveNext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_m4DC143BC57F14EDD85AB13B6D6F3B5D0E319B30E_gshared (Enumerator_tE92C1AC40A104A179B94F8A013728FD9314CFBD3* __this, const RuntimeMethod* method) ;
// T System.Collections.Generic.List`1<System.Object>::get_Item(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_get_Item_m33561245D64798C2AB07584C0EC4F240E4839A38_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, int32_t ___0_index, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::RemoveAt(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m54F62297ADEE4D4FDA697F49ED807BF901201B54_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, int32_t ___0_index, const RuntimeMethod* method) ;
// System.Int32 System.Collections.Generic.List`1<System.Object>::get_Count()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
// T System.Collections.Generic.List`1<System.Int32>::get_Item(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_get_Item_mD99081BEFA1AB3526715F489192B0F7F596C183D_gshared (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, int32_t ___0_index, const RuntimeMethod* method) ;
// TValue System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::get_Item(TKey)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_get_Item_mC3FEA647E750C27367C990777D8890E0E712E514_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, int32_t ___0_key, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::Remove(TKey)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m12BAB2F82E34CAA21A7245AB61E48F106340C1A4_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, int32_t ___0_key, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Int32>::RemoveAt(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m76C4CDACF47BA529BAFADFC8D5E13DB9587F4004_gshared (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, int32_t ___0_index, const RuntimeMethod* method) ;
// System.Int32 System.Collections.Generic.List`1<System.Int32>::get_Count()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_mF590592E32D421DE2C6E2F0D5C2F62FB14CCEFDF_gshared_inline (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::Add(TKey,TValue)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Add_mAF1EF7DA16BD70E252EA5C4B0F74DE519A02CBCD_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, int32_t ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::TryGetValue(TKey,TValue&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryGetValue_m7316301B8CF47FB538886B229B2749EC160B9D5C_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, int32_t ___0_key, RuntimeObject** ___1_value, const RuntimeMethod* method) ;
// T UnityEngine.GameObject::AddComponent<System.Object>()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* GameObject_AddComponent_TisRuntimeObject_m69B93700FACCF372F5753371C6E8FB780800B824_gshared (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m92E9AB321FBD7147CA109C822D99C8B0610C27B7_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Int32>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m17F501B5A5C289ECE1B4F3D6EBF05DFA421433F8_gshared (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, const RuntimeMethod* method) ;
// System.Void System.Action`1<System.Boolean>::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Action_1__ctor_mA8C3AC97D1F076EA5D1D0C10CEE6BD3E94711501_gshared (Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
// System.Void System.Action`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo>::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Action_1__ctor_mFC92FF99210AA666DCCBC082A7C89AE48C380DE9_gshared (Action_1_t1EE3C77B386F0D0C621A13E4401EC8A7E3819D93* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Queue`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo>::Enqueue(T)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_Enqueue_m575BD66AE362D5DB74AE95DCB203046EDE78991B_gshared (Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9* __this, TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 ___0_item, const RuntimeMethod* method) ;
// System.Int32 System.Collections.Generic.Queue`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo>::get_Count()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Queue_1_get_Count_m166D9E7A5DA18ACC5799C3963DD64F400A9F21BC_gshared_inline (Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9* __this, const RuntimeMethod* method) ;
// T System.Collections.Generic.Queue`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo>::Dequeue()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 Queue_1_Dequeue_mF641B4D1C707EF56082B2E8DF4351EBDEB8357F8_gshared (Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Queue`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo>::Clear()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1_Clear_m6B2EEBAC23F6D33E3209B3CDD5663163329AF523_gshared (Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Queue`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Queue_1__ctor_mBC4678D497EB50E3826BB8B1818E4A38B45B486B_gshared (Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9* __this, const RuntimeMethod* method) ;
// System.IntPtr System.Runtime.InteropServices.Marshal::UnsafeAddrOfPinnedArrayElement<BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i>(T[],System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t Marshal_UnsafeAddrOfPinnedArrayElement_TisGSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_m2FCC5D2D2C14567CAEFBA54CB0BE80EA9E9ED980_gshared (GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1* ___0_arr, int32_t ___1_index, const RuntimeMethod* method) ;
// System.IntPtr System.Runtime.InteropServices.Marshal::UnsafeAddrOfPinnedArrayElement<BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALine>(T[],System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t Marshal_UnsafeAddrOfPinnedArrayElement_TisGSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E_m2655F1BCF3E2FE7B028C56300363CA8898B97CC4_gshared (GSALineU5BU5D_tC2644452FF1B88D2D201F355FA28F65A5D8CF685* ___0_arr, int32_t ___1_index, const RuntimeMethod* method) ;
// System.IntPtr BoundarySystem_Ext.Pvr_BoundaryAPI::StructToIntPtr<BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALineCollection>(T)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t Pvr_BoundaryAPI_StructToIntPtr_TisGSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E_m4A4DF55B0B16B585FA2439BED123BE4CA5ED44D5_gshared (GSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E ___0_info, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<UnityEngine.Vector3>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mC54E2BCBE43279A96FC082F5CDE2D76388BD8F9C_gshared (List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* __this, const RuntimeMethod* method) ;
// T BoundarySystem_Ext.Pvr_BoundaryAPI::IntPtrToStruct<BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALineCollection>(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E Pvr_BoundaryAPI_IntPtrToStruct_TisGSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E_m3C7EC489283FB44610163AB0091A1C279E4F7156_gshared (intptr_t ___0_info, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<UnityEngine.Vector3>::Add(T)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m79E50C4F592B1703F4B76A8BE7B4855515460CA1_gshared_inline (List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_item, const RuntimeMethod* method) ;
// T BoundarySystem_Ext.Pvr_BoundaryAPI::IntPtrToStruct<BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSARect>(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 Pvr_BoundaryAPI_IntPtrToStruct_TisGSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3_mF94DF99548B07FAD05377E537D93589DB1845B7F_gshared (intptr_t ___0_info, const RuntimeMethod* method) ;

// System.Void System.Collections.Generic.Dictionary`2<System.String,System.Delegate>::Clear()
inline void Dictionary_2_Clear_mA5ED112FDE23E98A0E9A24339BF83DC1E0D2AB04 (Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6*, const RuntimeMethod*))Dictionary_2_Clear_mCFB5EA7351D5860D2B91592B91A84CA265A41433_gshared)(__this, method);
}
// System.Boolean System.Collections.Generic.Dictionary`2<System.String,System.Delegate>::TryGetValue(TKey,TValue&)
inline bool Dictionary_2_TryGetValue_mEC9E9DC5A9A7DC8EC9D73564D35C0CEB7182ED6B (Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* __this, String_t* ___0_key, Delegate_t** ___1_value, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6*, String_t*, Delegate_t**, const RuntimeMethod*))Dictionary_2_TryGetValue_mD15380A4ED7CDEE99EA45881577D26BA9CE1B849_gshared)(__this, ___0_key, ___1_value, method);
}
// System.Void Log::Error(System.String,System.String,System.String,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Log_Error_m2BCA24D454AF5A5E27541D7E21326D478C9BDE0B (String_t* ___0_msg, String_t* ___1_callerFilePath, String_t* ___2_callerMemberName, int32_t ___3_callerLineNumber, const RuntimeMethod* method) ;
// System.Void System.Action::Invoke()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_Invoke_m7126A54DACA72B845424072887B5F3A51FC3808E_inline (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* __this, const RuntimeMethod* method) ;
// System.Object System.Delegate::get_Target()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Delegate_get_Target_m6E203F111C1548193A5AB7E616BD5834CD269753_inline (Delegate_t* __this, const RuntimeMethod* method) ;
// System.Type System.Object::GetType()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3 (RuntimeObject* __this, const RuntimeMethod* method) ;
// System.Reflection.MethodInfo System.Delegate::get_Method()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MethodInfo_t* Delegate_get_Method_mB684A7525653DFE0EFC35E58449E1FC8E2A9F019 (Delegate_t* __this, const RuntimeMethod* method) ;
// System.String System.String::Concat(System.String[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m647EBF831F54B6DF7D5AFA5FD012CF4EE7571B6A (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___0_values, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<System.String,System.Delegate>::ContainsKey(TKey)
inline bool Dictionary_2_ContainsKey_mF167985044EB36A7BE3A47902F46FCEBAA42BFF3 (Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* __this, String_t* ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6*, String_t*, const RuntimeMethod*))Dictionary_2_ContainsKey_m703047C213F7AB55C9DC346596287773A1F670CD_gshared)(__this, ___0_key, method);
}
// System.Boolean com.picoxr.tobframwork.EventManager::HasEventListener(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool EventManager_HasEventListener_m7ECA640FF6A36A1B887CA93F2832B33D8EBCEACB (String_t* ___0_eventID, const RuntimeMethod* method) ;
// TValue System.Collections.Generic.Dictionary`2<System.String,System.Delegate>::get_Item(TKey)
inline Delegate_t* Dictionary_2_get_Item_m3F278CCF586B177F156F2E6AB38D00CA6E002B15 (Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* __this, String_t* ___0_key, const RuntimeMethod* method)
{
	return ((  Delegate_t* (*) (Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6*, String_t*, const RuntimeMethod*))Dictionary_2_get_Item_m4AAAECBE902A211BF2126E6AFA280AEF73A3E0D6_gshared)(__this, ___0_key, method);
}
// System.Boolean System.Delegate::op_Equality(System.Delegate,System.Delegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Delegate_op_Equality_m8B96593B665536587FFD27DE233442C075971C32 (Delegate_t* ___0_d1, Delegate_t* ___1_d2, const RuntimeMethod* method) ;
// System.Boolean com.picoxr.tobframwork.EventManager::OnListenerAdding(System.String,System.Delegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool EventManager_OnListenerAdding_m9FD8682351AA51BD53DE27FB97B5B3A986338651 (String_t* ___0_eventID, Delegate_t* ___1_listener, const RuntimeMethod* method) ;
// System.Delegate System.Delegate::Combine(System.Delegate,System.Delegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Delegate_t* Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00 (Delegate_t* ___0_a, Delegate_t* ___1_b, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.String,System.Delegate>::set_Item(TKey,TValue)
inline void Dictionary_2_set_Item_m0F4F2D2F1BEB8E000743301197554FD90E83F8A2 (Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* __this, String_t* ___0_key, Delegate_t* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6*, String_t*, Delegate_t*, const RuntimeMethod*))Dictionary_2_set_Item_m1A840355E8EDAECEA9D0C6F5E51B248FAA449CBD_gshared)(__this, ___0_key, ___1_value, method);
}
// System.Void System.Collections.Generic.Dictionary`2<System.String,System.Delegate>::Add(TKey,TValue)
inline void Dictionary_2_Add_mFC740DC4B588DEACABD94E8C79C0DD26C7065799 (Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* __this, String_t* ___0_key, Delegate_t* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6*, String_t*, Delegate_t*, const RuntimeMethod*))Dictionary_2_Add_m93FFFABE8FCE7FA9793F0915E2A8842C7CD0C0C1_gshared)(__this, ___0_key, ___1_value, method);
}
// System.Boolean System.Type::op_Inequality(System.Type,System.Type)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Type_op_Inequality_m83209C7BB3C05DFBEA3B6199B0BEFE8037301172 (Type_t* ___0_left, Type_t* ___1_right, const RuntimeMethod* method) ;
// System.Void Log::Debug(System.String,System.String,System.String,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Log_Debug_mBC6B7CAF0E12CB5777FB8FAAE59289CCDAED17A2 (String_t* ___0_msg, String_t* ___1_callerFilePath, String_t* ___2_callerMemberName, int32_t ___3_callerLineNumber, const RuntimeMethod* method) ;
// System.Boolean System.Linq.Enumerable::Contains<System.Delegate>(System.Collections.Generic.IEnumerable`1<TSource>,TSource)
inline bool Enumerable_Contains_TisDelegate_t_mFF006746882AAD944ED5B3D2CE5531200BE7F92B (RuntimeObject* ___0_source, Delegate_t* ___1_value, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, Delegate_t*, const RuntimeMethod*))Enumerable_Contains_TisRuntimeObject_mBCDB5870C52FC5BD2B6AE472A749FC03B9CF8958_gshared)(___0_source, ___1_value, method);
}
// System.Boolean com.picoxr.tobframwork.EventManager::OnListenerRemoving(System.String,System.Delegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool EventManager_OnListenerRemoving_mF3EBB332D736B27865615A12B9B6C26B63F58A1B (String_t* ___0_eventID, Delegate_t* ___1_listener, const RuntimeMethod* method) ;
// System.Delegate System.Delegate::Remove(System.Delegate,System.Delegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Delegate_t* Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3 (Delegate_t* ___0_source, Delegate_t* ___1_value, const RuntimeMethod* method) ;
// System.Void com.picoxr.tobframwork.EventManager::OnListenerRemoved(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventManager_OnListenerRemoved_m841ABBC22DF83E797CB4CBACFA8039E293FAAF7C (String_t* ___0_eventID, const RuntimeMethod* method) ;
// System.String System.String::Format(System.String,System.Object,System.Object,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mA0534D6E2AE4D67A6BD8D45B3321323930EB930C (String_t* ___0_format, RuntimeObject* ___1_arg0, RuntimeObject* ___2_arg1, RuntimeObject* ___3_arg2, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<System.String,System.Delegate>::Remove(TKey)
inline bool Dictionary_2_Remove_m1BF02B71B85F664D88F7EE0AA5733E7F013C81E3 (Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* __this, String_t* ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6*, String_t*, const RuntimeMethod*))Dictionary_2_Remove_m5C7C45E75D951A75843F3F7AADD56ECD64F6BC86_gshared)(__this, ___0_key, method);
}
// System.Void System.Object::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.String,System.Delegate>::.ctor()
inline void Dictionary_2__ctor_mC11B8D87D7D6237273D0616824847584DA85B003 (Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6*, const RuntimeMethod*))Dictionary_2__ctor_m5B32FBC624618211EB461D59CFBB10E987FD1329_gshared)(__this, method);
}
// T UnityEngine.Component::GetComponent<UnityEngine.XR.Interaction.Toolkit.XRRayInteractor>()
inline XRRayInteractor_t0B25C1D5A938B199A71908E189AB351B43DA4C76* Component_GetComponent_TisXRRayInteractor_t0B25C1D5A938B199A71908E189AB351B43DA4C76_m0347BCF4E0361AA2A76B2D7C9C21327E8C4ADFE4 (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method)
{
	return ((  XRRayInteractor_t0B25C1D5A938B199A71908E189AB351B43DA4C76* (*) (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3*, const RuntimeMethod*))Component_GetComponent_TisRuntimeObject_m7181F81CAEC2CF53F5D2BC79B7425C16E1F80D33_gshared)(__this, method);
}
// System.Boolean UnityEngine.XR.Interaction.Toolkit.XRRayInteractor::TryGetHitInfo(UnityEngine.Vector3&,UnityEngine.Vector3&,System.Int32&,System.Boolean&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool XRRayInteractor_TryGetHitInfo_mCC8B3B99CCA30572E3B29C7E9C019BD79E8B99BE (XRRayInteractor_t0B25C1D5A938B199A71908E189AB351B43DA4C76* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* ___0_position, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* ___1_normal, int32_t* ___2_positionInLine, bool* ___3_isValidTarget, const RuntimeMethod* method) ;
// UnityEngine.GameObject UnityEngine.Component::get_gameObject()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.GameObject::get_activeSelf()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool GameObject_get_activeSelf_m4F3E5240E138B66AAA080EA30759A3D0517DA368 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.GameObject::SetActive(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, bool ___0_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.Transform::set_position(UnityEngine.Vector3)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Transform_set_position_mA1A817124BB41B685043DED2A9BA48CDF37C4156 (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_value, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Vector3::op_UnaryNegation(UnityEngine.Vector3)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_op_UnaryNegation_m5450829F333BD2A88AF9A592C4EE331661225915_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_a, const RuntimeMethod* method) ;
// System.Void UnityEngine.Transform::set_forward(UnityEngine.Vector3)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Transform_set_forward_mA178B5CF4F0F6133F9AF8ED3A4ECD2C604C60C26 (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.MonoBehaviour::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, const RuntimeMethod* method) ;
// T[] UnityEngine.Component::GetComponentsInChildren<com.picoxr.tobframwork.UIPage>(System.Boolean)
inline UIPageU5BU5D_t7F52BDD6ABCD90C3DC53772307DC5681B3D58496* Component_GetComponentsInChildren_TisUIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387_m94464D52C05DF542C9B351530FA9E1E517AD9265 (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, bool ___0_includeInactive, const RuntimeMethod* method)
{
	return ((  UIPageU5BU5D_t7F52BDD6ABCD90C3DC53772307DC5681B3D58496* (*) (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3*, bool, const RuntimeMethod*))Component_GetComponentsInChildren_TisRuntimeObject_m90734C3A39A158985239CB90DE2F0792F1D99926_gshared)(__this, ___0_includeInactive, method);
}
// System.Void System.Collections.Generic.Dictionary`2<System.Type,System.Int32>::set_Item(TKey,TValue)
inline void Dictionary_2_set_Item_m523CB8EB40145B2FB212BB32F0E7B19E62D582BD (Dictionary_2_t384D2A0FF42BF1302A3F513FC32DB105F1CD5455* __this, Type_t* ___0_key, int32_t ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t384D2A0FF42BF1302A3F513FC32DB105F1CD5455*, Type_t*, int32_t, const RuntimeMethod*))Dictionary_2_set_Item_m72CC2F1213D1C1B8ABEDE31082D07B67EC873B13_gshared)(__this, ___0_key, ___1_value, method);
}
// System.Boolean System.Collections.Generic.Dictionary`2<System.Type,System.Int32>::TryGetValue(TKey,TValue&)
inline bool Dictionary_2_TryGetValue_m3EF4F6B2EC138E3A20BD7549CE6DE54B0608CD4D (Dictionary_2_t384D2A0FF42BF1302A3F513FC32DB105F1CD5455* __this, Type_t* ___0_key, int32_t* ___1_value, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t384D2A0FF42BF1302A3F513FC32DB105F1CD5455*, Type_t*, int32_t*, const RuntimeMethod*))Dictionary_2_TryGetValue_m4B8EE45640C70BBFD6F3EFF1040983404C098342_gshared)(__this, ___0_key, ___1_value, method);
}
// System.Void com.picoxr.tobframwork.UIGroup::UpdateState()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIGroup_UpdateState_m1B5A0F23B73D375A2410ADC2128466E73E7E8FCB (UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Type,System.Int32>::.ctor()
inline void Dictionary_2__ctor_m0AF6A9E01056850C9F7AE464B4099CA3F6D5E8EC (Dictionary_2_t384D2A0FF42BF1302A3F513FC32DB105F1CD5455* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t384D2A0FF42BF1302A3F513FC32DB105F1CD5455*, const RuntimeMethod*))Dictionary_2__ctor_m517E7F9D104FEAE6646EABDDC9C852510E86077C_gshared)(__this, method);
}
// System.Void com.picoxr.tobframwork.UIPageManager::Close(System.Type)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIPageManager_Close_mEBB5FCBE4D27BE856B8D78C73AA2DF70D84E7BE5 (Type_t* ___0_type, const RuntimeMethod* method) ;
// System.String System.String::Concat(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m9E3155FB84015C823606188F53B47CB44C444991 (String_t* ___0_str0, String_t* ___1_str1, const RuntimeMethod* method) ;
// T[] UnityEngine.GameObject::GetComponentsInChildren<com.picoxr.tobframwork.UIPage>(System.Boolean)
inline UIPageU5BU5D_t7F52BDD6ABCD90C3DC53772307DC5681B3D58496* GameObject_GetComponentsInChildren_TisUIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387_mD11B8C3BB77751DD9FC69ABF4546E706BBEF1F2A (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, bool ___0_includeInactive, const RuntimeMethod* method)
{
	return ((  UIPageU5BU5D_t7F52BDD6ABCD90C3DC53772307DC5681B3D58496* (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, bool, const RuntimeMethod*))GameObject_GetComponentsInChildren_TisRuntimeObject_m511E687BF2424F8D832EA2EAA459870887FB9540_gshared)(__this, ___0_includeInactive, method);
}
// T UnityEngine.Component::GetComponentInParent<com.picoxr.tobframwork.UIGroup>()
inline UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* Component_GetComponentInParent_TisUIGroup_tC217247301A179C554813A009381C0404ECC1DDF_mE896505A28C23576CBC229CC8A54B6429415E378 (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method)
{
	return ((  UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* (*) (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3*, const RuntimeMethod*))Component_GetComponentInParent_TisRuntimeObject_m6746D6BB99912B1B509746C993906492F86CD119_gshared)(__this, method);
}
// System.Void com.picoxr.tobframwork.UIPage::SetGroup(com.picoxr.tobframwork.UIGroup)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIPage_SetGroup_mBFAE61AE2F91F5FB313B45853A19A71F4E0B625B (UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* __this, UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* ___0_group, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Type,com.picoxr.tobframwork.UIPage>::Add(TKey,TValue)
inline void Dictionary_2_Add_mF5BAF98BB9FA8006CAAA49255DB0A4564F5EB444 (Dictionary_2_t1BF400F50D50E19CF6FCD3FF520384A96269F89F* __this, Type_t* ___0_key, UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t1BF400F50D50E19CF6FCD3FF520384A96269F89F*, Type_t*, UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387*, const RuntimeMethod*))Dictionary_2_Add_m93FFFABE8FCE7FA9793F0915E2A8842C7CD0C0C1_gshared)(__this, ___0_key, ___1_value, method);
}
// System.Boolean System.Collections.Generic.Dictionary`2<System.Type,com.picoxr.tobframwork.UIPage>::TryGetValue(TKey,TValue&)
inline bool Dictionary_2_TryGetValue_mB9EEAAD08A35C274F212D4C739347DE6120A6C2B (Dictionary_2_t1BF400F50D50E19CF6FCD3FF520384A96269F89F* __this, Type_t* ___0_key, UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387** ___1_value, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t1BF400F50D50E19CF6FCD3FF520384A96269F89F*, Type_t*, UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387**, const RuntimeMethod*))Dictionary_2_TryGetValue_mD15380A4ED7CDEE99EA45881577D26BA9CE1B849_gshared)(__this, ___0_key, ___1_value, method);
}
// com.picoxr.tobframwork.UIGroup com.picoxr.tobframwork.UIPage::get_Group()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* UIPage_get_Group_m1553A3E497FCF802E7EB13649C50DE62EF308F12 (UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* __this, const RuntimeMethod* method) ;
// System.Void com.picoxr.tobframwork.UIGroup::Close(System.Type)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIGroup_Close_m40933FE144C6A4E765D2944639734A2068952E39 (UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* __this, Type_t* ___0_type, const RuntimeMethod* method) ;
// System.Boolean com.picoxr.tobframwork.UIPageManager::_CloseUI(System.Type)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool UIPageManager__CloseUI_m9AF9FCA67ECF7C6FDD2C9E2C7250787C1094FF51 (UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B* __this, Type_t* ___0_type, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Type,com.picoxr.tobframwork.UIPage>::.ctor()
inline void Dictionary_2__ctor_m94EDCF44D203BF48FDAEAEB36F5DB4BF67E17CAA (Dictionary_2_t1BF400F50D50E19CF6FCD3FF520384A96269F89F* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t1BF400F50D50E19CF6FCD3FF520384A96269F89F*, const RuntimeMethod*))Dictionary_2__ctor_m5B32FBC624618211EB461D59CFBB10E987FD1329_gshared)(__this, method);
}
// System.String LocalizationTool::GetContentWithUnicodeSpace(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* LocalizationTool_GetContentWithUnicodeSpace_m0B2266E7D68CD9D2CC0B4B43A0A82692C07CCD01 (String_t* ___0_key, const RuntimeMethod* method) ;
// System.Void <>f__AnonymousType0`1<System.Int32>::.ctor(<num>j__TPar)
inline void U3CU3Ef__AnonymousType0_1__ctor_mF4E4C5F9CD02AEAF4F890E22441AE2B516285AB6 (U3CU3Ef__AnonymousType0_1_tCC81029179B6F4DAC7D8BC271C35F5CDBC097D55* __this, int32_t ___0_num, const RuntimeMethod* method)
{
	((  void (*) (U3CU3Ef__AnonymousType0_1_tCC81029179B6F4DAC7D8BC271C35F5CDBC097D55*, int32_t, const RuntimeMethod*))U3CU3Ef__AnonymousType0_1__ctor_mF4E4C5F9CD02AEAF4F890E22441AE2B516285AB6_gshared)(__this, ___0_num, method);
}
// System.String Jeffijoe.MessageFormat.MessageFormatterExtensions::FormatMessage(Jeffijoe.MessageFormat.IMessageFormatter,System.String,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* MessageFormatterExtensions_FormatMessage_mAF75489D52D425037E9E600B4A0F67755E00AFA1 (RuntimeObject* ___0_formatter, String_t* ___1_pattern, RuntimeObject* ___2_args, const RuntimeMethod* method) ;
// System.String System.Int32::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5 (int32_t* __this, const RuntimeMethod* method) ;
// System.String System.String::Replace(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Replace_mABDB7003A1D0AEDCAE9FF85E3DFFFBA752D2A166 (String_t* __this, String_t* ___0_oldValue, String_t* ___1_newValue, const RuntimeMethod* method) ;
// System.String com.picoxr.tobframwork.LanguageUtils::GetRichContent(System.String,System.Int32[],System.String[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* LanguageUtils_GetRichContent_m373FE4083C1BF7653F390A8952C31FB1C4027A79 (String_t* ___0_key, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___1_intArr, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___2_stringArr, const RuntimeMethod* method) ;
// System.String com.picoxr.tobframwork.LanguageUtils::Convert(System.String,System.Int32[],System.String[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* LanguageUtils_Convert_m330A88108808D44309EC107E2D78BAED0E15AF1D (String_t* ___0_content, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___1_intArr, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___2_stringArr, const RuntimeMethod* method) ;
// System.Text.StringBuilder System.Text.StringBuilder::Clear()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_Clear_m2D76F6533574F40A4E3E2DC4E730277CBD0AF8F6 (StringBuilder_t* __this, const RuntimeMethod* method) ;
// System.Char System.String::get_Chars(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppChar String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3 (String_t* __this, int32_t ___0_index, const RuntimeMethod* method) ;
// System.Int32 System.String::get_Length()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) ;
// System.Text.StringBuilder System.Text.StringBuilder::Append(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D (StringBuilder_t* __this, String_t* ___0_value, const RuntimeMethod* method) ;
// System.Text.StringBuilder System.Text.StringBuilder::Append(System.Char)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1 (StringBuilder_t* __this, Il2CppChar ___0_value, const RuntimeMethod* method) ;
// System.Void System.Text.StringBuilder::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D (StringBuilder_t* __this, const RuntimeMethod* method) ;
// System.Void Jeffijoe.MessageFormat.MessageFormatter::.ctor(System.Boolean,System.String,Jeffijoe.MessageFormat.CustomValueFormatter)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageFormatter__ctor_mE163C7425D7EE65EBE62E161CA9FF363C9E8784E (MessageFormatter_t59AB4D9D22B9B2403C45FF755A0AB60223D2035F* __this, bool ___0_useCache, String_t* ___1_locale, CustomValueFormatter_tBD981B5F72D8EADB8B6258BE76BEBEE7EF2403AC* ___2_customValueFormatter, const RuntimeMethod* method) ;
// System.Collections.Generic.Dictionary`2/Enumerator<TKey,TValue> System.Collections.Generic.Dictionary`2<System.Int32,com.picoxr.tobframwork.Timer/Handle>::GetEnumerator()
inline Enumerator_t2EE140C33897AA9EA14EF9B66B7AA963EEB1E888 Dictionary_2_GetEnumerator_m270AF704B3913CD85D83DD9FFF33D86EFEA32AFF (Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t2EE140C33897AA9EA14EF9B66B7AA963EEB1E888 (*) (Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6*, const RuntimeMethod*))Dictionary_2_GetEnumerator_m3F1620145BA0815B7C7CD648EF054558AA26556A_gshared)(__this, method);
}
// System.Collections.Generic.KeyValuePair`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,com.picoxr.tobframwork.Timer/Handle>::get_Current()
inline KeyValuePair_2_t7D5F51FBC6FB4B34CCA91B6881B1DCFDCCEEE2B3 Enumerator_get_Current_mA55505E5DED43F682FF4A841E7E1B29506D44D22_inline (Enumerator_t2EE140C33897AA9EA14EF9B66B7AA963EEB1E888* __this, const RuntimeMethod* method)
{
	return ((  KeyValuePair_2_t7D5F51FBC6FB4B34CCA91B6881B1DCFDCCEEE2B3 (*) (Enumerator_t2EE140C33897AA9EA14EF9B66B7AA963EEB1E888*, const RuntimeMethod*))Enumerator_get_Current_m90160D324DA0D9F5624A345F47D8E226A118911A_gshared_inline)(__this, method);
}
// TValue System.Collections.Generic.KeyValuePair`2<System.Int32,com.picoxr.tobframwork.Timer/Handle>::get_Value()
inline Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* KeyValuePair_2_get_Value_mE69B7D19A7BC4B402D3F61148E96B3509CB69FAC_inline (KeyValuePair_2_t7D5F51FBC6FB4B34CCA91B6881B1DCFDCCEEE2B3* __this, const RuntimeMethod* method)
{
	return ((  Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* (*) (KeyValuePair_2_t7D5F51FBC6FB4B34CCA91B6881B1DCFDCCEEE2B3*, const RuntimeMethod*))KeyValuePair_2_get_Value_m8508BCECB0654E2E93B1A141382E2688ADE7EE7C_gshared_inline)(__this, method);
}
// System.Single UnityEngine.Time::get_time()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Time_get_time_m3A271BB1B20041144AC5B7863B71AB1F0150374B (const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<com.picoxr.tobframwork.Timer/Handle>::Add(T)
inline void List_1_Add_mAA50EFD5EEC9735C47DD68C4CC4DEB3CCFE01C98_inline (List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5* __this, Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5*, Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.Void System.Collections.Generic.List`1<System.Int32>::Add(T)
inline void List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_inline (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, int32_t ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73*, int32_t, const RuntimeMethod*))List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_gshared_inline)(__this, ___0_item, method);
}
// System.Boolean System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,com.picoxr.tobframwork.Timer/Handle>::MoveNext()
inline bool Enumerator_MoveNext_m7E56A8F9E76BB0BBBB349B08ED376B19C973EF53 (Enumerator_t2EE140C33897AA9EA14EF9B66B7AA963EEB1E888* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t2EE140C33897AA9EA14EF9B66B7AA963EEB1E888*, const RuntimeMethod*))Enumerator_MoveNext_m4DC143BC57F14EDD85AB13B6D6F3B5D0E319B30E_gshared)(__this, method);
}
// T System.Collections.Generic.List`1<com.picoxr.tobframwork.Timer/Handle>::get_Item(System.Int32)
inline Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* List_1_get_Item_m9BC9267741CE11FCC731D1D0F6E98A08295D2545 (List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	return ((  Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* (*) (List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5*, int32_t, const RuntimeMethod*))List_1_get_Item_m33561245D64798C2AB07584C0EC4F240E4839A38_gshared)(__this, ___0_index, method);
}
// System.Void System.Collections.Generic.List`1<com.picoxr.tobframwork.Timer/Handle>::RemoveAt(System.Int32)
inline void List_1_RemoveAt_mD9D3FCCCEBDF9E17EEE5A8CB0656F195F585AD3D (List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5*, int32_t, const RuntimeMethod*))List_1_RemoveAt_m54F62297ADEE4D4FDA697F49ED807BF901201B54_gshared)(__this, ___0_index, method);
}
// System.Void com.picoxr.tobframwork.Timer::HandleCall(com.picoxr.tobframwork.Timer/Handle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Timer_HandleCall_mC6CF5E4AEC98E4F69B95CCC8E385E43E6086758B (Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0* __this, Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* ___0_handle, const RuntimeMethod* method) ;
// System.Int32 System.Collections.Generic.List`1<com.picoxr.tobframwork.Timer/Handle>::get_Count()
inline int32_t List_1_get_Count_m8CE395B93EA7127861F983E3C2FE02E08A41D42E_inline (List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5*, const RuntimeMethod*))List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline)(__this, method);
}
// T System.Collections.Generic.List`1<System.Int32>::get_Item(System.Int32)
inline int32_t List_1_get_Item_mD99081BEFA1AB3526715F489192B0F7F596C183D (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73*, int32_t, const RuntimeMethod*))List_1_get_Item_mD99081BEFA1AB3526715F489192B0F7F596C183D_gshared)(__this, ___0_index, method);
}
// TValue System.Collections.Generic.Dictionary`2<System.Int32,com.picoxr.tobframwork.Timer/Handle>::get_Item(TKey)
inline Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* Dictionary_2_get_Item_mD9FD66064367BDD11E0CBCA5D45B14FCFE58DD57 (Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6* __this, int32_t ___0_key, const RuntimeMethod* method)
{
	return ((  Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* (*) (Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6*, int32_t, const RuntimeMethod*))Dictionary_2_get_Item_mC3FEA647E750C27367C990777D8890E0E712E514_gshared)(__this, ___0_key, method);
}
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,com.picoxr.tobframwork.Timer/Handle>::Remove(TKey)
inline bool Dictionary_2_Remove_mD553250DE5E74AB751576D4DFA330B74162C8926 (Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6* __this, int32_t ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6*, int32_t, const RuntimeMethod*))Dictionary_2_Remove_m12BAB2F82E34CAA21A7245AB61E48F106340C1A4_gshared)(__this, ___0_key, method);
}
// System.Void System.Collections.Generic.List`1<System.Int32>::RemoveAt(System.Int32)
inline void List_1_RemoveAt_m76C4CDACF47BA529BAFADFC8D5E13DB9587F4004 (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	((  void (*) (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73*, int32_t, const RuntimeMethod*))List_1_RemoveAt_m76C4CDACF47BA529BAFADFC8D5E13DB9587F4004_gshared)(__this, ___0_index, method);
}
// System.Int32 System.Collections.Generic.List`1<System.Int32>::get_Count()
inline int32_t List_1_get_Count_mF590592E32D421DE2C6E2F0D5C2F62FB14CCEFDF_inline (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73*, const RuntimeMethod*))List_1_get_Count_mF590592E32D421DE2C6E2F0D5C2F62FB14CCEFDF_gshared_inline)(__this, method);
}
// System.Void com.picoxr.tobframwork.Timer/Handle::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Handle__ctor_mA693FB99957F5F22DA33083461F2EC356206301D (Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,com.picoxr.tobframwork.Timer/Handle>::Add(TKey,TValue)
inline void Dictionary_2_Add_m127CA9CF3BF949F685FC3BC47942C2EAB717A1B7 (Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6* __this, int32_t ___0_key, Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6*, int32_t, Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5*, const RuntimeMethod*))Dictionary_2_Add_mAF1EF7DA16BD70E252EA5C4B0F74DE519A02CBCD_gshared)(__this, ___0_key, ___1_value, method);
}
// System.Boolean System.Collections.Generic.Dictionary`2<System.Int32,com.picoxr.tobframwork.Timer/Handle>::TryGetValue(TKey,TValue&)
inline bool Dictionary_2_TryGetValue_m347E8803DB0864154991F6FB10D201FD8D4D4AC3 (Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6* __this, int32_t ___0_key, Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5** ___1_value, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6*, int32_t, Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5**, const RuntimeMethod*))Dictionary_2_TryGetValue_m7316301B8CF47FB538886B229B2749EC160B9D5C_gshared)(__this, ___0_key, ___1_value, method);
}
// System.Int32 com.picoxr.tobframwork.Timer::Add(System.Single,System.Action,System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Timer_Add_m60043B0A6BE292995EA3C4ACDA2B8B307231B23C (float ___0_delay, Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___1_call, float ___2_repeatRate, const RuntimeMethod* method) ;
// com.picoxr.tobframwork.Timer com.picoxr.tobframwork.Timer::GetInstance()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0* Timer_GetInstance_m3C9D320D4141D2F80D27913A6D149EB8057E2BB7 (const RuntimeMethod* method) ;
// System.Int32 com.picoxr.tobframwork.Timer::_Add(System.Single,System.Action,System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Timer__Add_mB1D79903C31073C6A171200E211C6EBC5571C554 (Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0* __this, float ___0_delay, Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___1_call, float ___2_repeatRate, const RuntimeMethod* method) ;
// System.Void com.picoxr.tobframwork.Timer::_Remove(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Timer__Remove_m9C463D8653375AEB6390448C0FF02879B2A4D7A0 (Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0* __this, int32_t ___0_id, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Object::op_Equality(UnityEngine.Object,UnityEngine.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_x, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_y, const RuntimeMethod* method) ;
// System.Void UnityEngine.GameObject::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameObject__ctor_m7D0340DE160786E6EFA8DABD39EC3B694DA30AAD (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method) ;
// T UnityEngine.GameObject::AddComponent<com.picoxr.tobframwork.Timer>()
inline Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0* GameObject_AddComponent_TisTimer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0_m66276B9B1490B3979BF93ED13478B3B3E58EA41C (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method)
{
	return ((  Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0* (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, const RuntimeMethod*))GameObject_AddComponent_TisRuntimeObject_m69B93700FACCF372F5753371C6E8FB780800B824_gshared)(__this, method);
}
// System.Void UnityEngine.Object::DontDestroyOnLoad(UnityEngine.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object_DontDestroyOnLoad_m4B70C3AEF886C176543D1295507B6455C9DCAEA7 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_target, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Int32,com.picoxr.tobframwork.Timer/Handle>::.ctor()
inline void Dictionary_2__ctor_m1499CB733B03C3B63D06D1A01E35197AC21B59BD (Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6*, const RuntimeMethod*))Dictionary_2__ctor_m92E9AB321FBD7147CA109C822D99C8B0610C27B7_gshared)(__this, method);
}
// System.Void System.Collections.Generic.List`1<com.picoxr.tobframwork.Timer/Handle>::.ctor()
inline void List_1__ctor_mA02C96C46346D3D1952391F0E97ACFA08A59E206 (List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
// System.Void System.Collections.Generic.List`1<System.Int32>::.ctor()
inline void List_1__ctor_m17F501B5A5C289ECE1B4F3D6EBF05DFA421433F8 (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73*, const RuntimeMethod*))List_1__ctor_m17F501B5A5C289ECE1B4F3D6EBF05DFA421433F8_gshared)(__this, method);
}
// System.Single com.picoxr.tobframwork.Unitls::AdjustAngle(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Unitls_AdjustAngle_mB4C788AFA7BCB283EA20290DC2C67D0010B8FDAB (float ___0_angle, const RuntimeMethod* method) ;
// System.Void Unity.XR.PXR.PXR_Manager::set_EnableVideoSeeThrough(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PXR_Manager_set_EnableVideoSeeThrough_mD1A96A700204E54FEE73DC142A9824C18D1EB42B (bool ___0_value, const RuntimeMethod* method) ;
// System.Int32 Unity.XR.PXR.PXR_Plugin/Boundary::UPxr_SetGuardianSystemDisable(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Boundary_UPxr_SetGuardianSystemDisable_m2E6F8683908119A5CA656628B58C953E2434EC4A (bool ___0_value, const RuntimeMethod* method) ;
// System.Boolean Unity.XR.PICO.TOBSupport.PXR_Enterprise::InitEnterpriseService(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool PXR_Enterprise_InitEnterpriseService_mA5E6CD31F2D00D76CC0EA930E2B25FA61900B3A1 (bool ___0_isCamera, const RuntimeMethod* method) ;
// System.Int32 Unity.XR.PXR.PXR_Plugin/Boundary::UPxr_ShutdownSdkGuardianSystem()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Boundary_UPxr_ShutdownSdkGuardianSystem_m9AEF2EED29C12800A56230E0EE7BABD0767BD751 (const RuntimeMethod* method) ;
// System.Void System.Action`1<System.Boolean>::.ctor(System.Object,System.IntPtr)
inline void Action_1__ctor_mA8C3AC97D1F076EA5D1D0C10CEE6BD3E94711501 (Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C*, RuntimeObject*, intptr_t, const RuntimeMethod*))Action_1__ctor_mA8C3AC97D1F076EA5D1D0C10CEE6BD3E94711501_gshared)(__this, ___0_object, ___1_method, method);
}
// System.Void Unity.XR.PICO.TOBSupport.PXR_Enterprise::BindEnterpriseService(System.Action`1<System.Boolean>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PXR_Enterprise_BindEnterpriseService_m5A5610A0983FB0CBEE2F0C2FD791F66FE3FB7F1B (Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C* ___0_callback, const RuntimeMethod* method) ;
// System.Void System.Action::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Action__ctor_mBDC7B0B4A3F583B64C2896F01BDED360772F67DC (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
// System.String System.Boolean::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Boolean_ToString_m6646C8026B1DF381A1EE8CD13549175E9703CC63 (bool* __this, const RuntimeMethod* method) ;
// System.Void Unity.XR.PICO.TOBSupport.PXR_Enterprise::UnBindEnterpriseService()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PXR_Enterprise_UnBindEnterpriseService_m7C64EB437499AEE8388B6E1AE4667FA0F8A14D99 (const RuntimeMethod* method) ;
// System.Void com.picoxr.blsapce.SpatialTextureToSystem::RuntimeCall(com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpatialTextureToSystem_RuntimeCall_mEB3B29789D850F95A4172D9A46668168EA90F83F (TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 ___0_info, const RuntimeMethod* method) ;
// System.Boolean System.IntPtr::op_Inequality(System.IntPtr,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool IntPtr_op_Inequality_m90EFC9C4CAD9A33E309F2DDF98EE4E1DD253637B (intptr_t ___0_value1, intptr_t ___1_value2, const RuntimeMethod* method) ;
// System.IntPtr com.picoxr.blsapce.SpatialTextureToSystem::CreateClient()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t SpatialTextureToSystem_CreateClient_m1EB6468E9961E55CDB96A15D16DB46C7888E1659 (const RuntimeMethod* method) ;
// System.String System.IntPtr::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* IntPtr_ToString_mDA1150F4802E1FB9313FB4E32C684EEE19116E5C (intptr_t* __this, const RuntimeMethod* method) ;
// System.Void System.Action`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo>::.ctor(System.Object,System.IntPtr)
inline void Action_1__ctor_mFC92FF99210AA666DCCBC082A7C89AE48C380DE9 (Action_1_t1EE3C77B386F0D0C621A13E4401EC8A7E3819D93* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Action_1_t1EE3C77B386F0D0C621A13E4401EC8A7E3819D93*, RuntimeObject*, intptr_t, const RuntimeMethod*))Action_1__ctor_mFC92FF99210AA666DCCBC082A7C89AE48C380DE9_gshared)(__this, ___0_object, ___1_method, method);
}
// System.Int32 com.picoxr.blsapce.SpatialTextureToSystem::startTextureScanning(System.IntPtr,System.Action`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SpatialTextureToSystem_startTextureScanning_mCF4FBB56ACEA5DF5D2F102641835CE8E4653248B (intptr_t ___0_client, Action_1_t1EE3C77B386F0D0C621A13E4401EC8A7E3819D93* ___1_callback, const RuntimeMethod* method) ;
// System.Void com.picoxr.blsapce.SpatialTextureToSystem/CallBackDelegate::Invoke(com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void CallBackDelegate_Invoke_m42D4CEED99DFAE02791F0098A5657031B3A3BADE_inline (CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC* __this, TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 ___0_info, const RuntimeMethod* method) ;
// System.Int32 com.picoxr.blsapce.SpatialTextureToSystem::stopTextureScanning(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SpatialTextureToSystem_stopTextureScanning_m7845B2A3AD031093922454463C886C057FA28FDF (intptr_t ___0_client, const RuntimeMethod* method) ;
// System.Void com.picoxr.tobframwork.Timer::Remove(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Timer_Remove_m5EA5375017A3E956DE9E5C697B8E6C8730D00123 (int32_t ___0_id, const RuntimeMethod* method) ;
// System.String System.Enum::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Enum_ToString_m946B0B83C4470457D0FF555D862022C72BB55741 (RuntimeObject* __this, const RuntimeMethod* method) ;
// System.String System.Double::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339 (double* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Queue`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo>::Enqueue(T)
inline void Queue_1_Enqueue_m575BD66AE362D5DB74AE95DCB203046EDE78991B (Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9* __this, TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 ___0_item, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9*, TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6, const RuntimeMethod*))Queue_1_Enqueue_m575BD66AE362D5DB74AE95DCB203046EDE78991B_gshared)(__this, ___0_item, method);
}
// System.Int32 System.Collections.Generic.Queue`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo>::get_Count()
inline int32_t Queue_1_get_Count_m166D9E7A5DA18ACC5799C3963DD64F400A9F21BC_inline (Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9*, const RuntimeMethod*))Queue_1_get_Count_m166D9E7A5DA18ACC5799C3963DD64F400A9F21BC_gshared_inline)(__this, method);
}
// T System.Collections.Generic.Queue`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo>::Dequeue()
inline TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 Queue_1_Dequeue_mF641B4D1C707EF56082B2E8DF4351EBDEB8357F8 (Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9* __this, const RuntimeMethod* method)
{
	return ((  TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 (*) (Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9*, const RuntimeMethod*))Queue_1_Dequeue_mF641B4D1C707EF56082B2E8DF4351EBDEB8357F8_gshared)(__this, method);
}
// System.Void System.Collections.Generic.Queue`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo>::Clear()
inline void Queue_1_Clear_m6B2EEBAC23F6D33E3209B3CDD5663163329AF523 (Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9* __this, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9*, const RuntimeMethod*))Queue_1_Clear_m6B2EEBAC23F6D33E3209B3CDD5663163329AF523_gshared)(__this, method);
}
// System.Void System.Collections.Generic.Queue`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo>::.ctor()
inline void Queue_1__ctor_mBC4678D497EB50E3826BB8B1818E4A38B45B486B (Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9* __this, const RuntimeMethod* method)
{
	((  void (*) (Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9*, const RuntimeMethod*))Queue_1__ctor_mBC4678D497EB50E3826BB8B1818E4A38B45B486B_gshared)(__this, method);
}
// System.Int32 BoundarySystem_Ext.Pvr_BoundaryAPI::Pvr_GetMainSensorStateExt(System.Single&,System.Single&,System.Single&,System.Single&,System.Single&,System.Single&,System.Single&,System.Single&,System.Single&,System.Int32&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_BoundaryAPI_Pvr_GetMainSensorStateExt_m321C1D462B4E5376D3CD28EB5DA3AC024EAD6085 (float* ___0_x, float* ___1_y, float* ___2_z, float* ___3_w, float* ___4_px, float* ___5_py, float* ___6_pz, float* ___7_vfov, float* ___8_hfov, int32_t* ___9_viewNumber, const RuntimeMethod* method) ;
// System.IntPtr BoundarySystem_Ext.Pvr_BoundaryAPI::Pvr_GetCameraData_Ext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t Pvr_BoundaryAPI_Pvr_GetCameraData_Ext_m2AD3E265FAD65F33A3FBEEDFEDF9F496CFF788B5 (const RuntimeMethod* method) ;
// System.Boolean BoundarySystem_Ext.Pvr_BoundaryAPI::Pvr_ResumeBoundaryForSTS()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Pvr_BoundaryAPI_Pvr_ResumeBoundaryForSTS_m06A9BD2FF0203CB84BE1B8F0BBA175A6A6851908 (const RuntimeMethod* method) ;
// System.Void BoundarySystem_Ext.Pvr_BoundaryAPI::Pvr_PauseBoundaryForSTS()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_BoundaryAPI_Pvr_PauseBoundaryForSTS_mD10EB55298A054955FB95D086565543EEFA6883A (const RuntimeMethod* method) ;
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSAInit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_GSAInit_mA3C9B395453CB6E9C2BC1F919A5E2DA76BE64D47 (const RuntimeMethod* method) ;
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSAInit(System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_GSAInit_m53EB258F87415DFACB6158CB1795715B6133F7D6 (int32_t ___0_width, int32_t ___1_height, const RuntimeMethod* method) ;
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSASetCallback(BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_GSASetCallback_m2CA2BA1908468D19A690D97286CD5B03B61C7745 (SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C* ___0_cb, const RuntimeMethod* method) ;
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSASetCallbackShrink(BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallbackShrink)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_GSASetCallbackShrink_m836980D9F1557C2C112557ED4E78DE0F3F47034A (SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754* ___0_cb, const RuntimeMethod* method) ;
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSAUpDateData(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_GSAUpDateData_m5AA2B1CB047F9EEC6A21C0EA0A60D9BD7D0D943B (intptr_t ___0_lineCollectionPtr, const RuntimeMethod* method) ;
// System.Boolean BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSAGetClosedAreaUpdateFlag()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Pvr_SafeAreaAlgoAPI_GSAGetClosedAreaUpdateFlag_m309CA1FD4FA9C0FABD416D3B6A40DF992DD98AE4 (const RuntimeMethod* method) ;
// System.IntPtr System.Runtime.InteropServices.Marshal::StringToHGlobalAnsi(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t Marshal_StringToHGlobalAnsi_mE6070591B7CC1DC279324657D93B6EB0FD4CACDD (String_t* ___0_s, const RuntimeMethod* method) ;
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSASetConfigFilePath(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_GSASetConfigFilePath_m1AE31E958500B9264A963CC5F3DF983B81FD9304 (intptr_t ___0_configPath, const RuntimeMethod* method) ;
// System.Void System.Runtime.InteropServices.Marshal::FreeHGlobal(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Marshal_FreeHGlobal_m298EF0650E82E326EDA8048488DC384BB9171EB9 (intptr_t ___0_hglobal, const RuntimeMethod* method) ;
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSALoadSafetyArea(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_GSALoadSafetyArea_m79C5644419EDE0B858486289AD937ABAA56017A3 (intptr_t ___0_lineCollectionPtr, const RuntimeMethod* method) ;
// System.Double BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSABoundaryDetector(BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Pvr_SafeAreaAlgoAPI_GSABoundaryDetector_m3C4D62E7071EFEB4139B3BA4F6AE8E8DA66149EA (GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17* ___0_pointPtr, const RuntimeMethod* method) ;
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSAShutDown()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_GSAShutDown_m762ABA1ABA78A161A2EC88F465CA19A5575D447C (const RuntimeMethod* method) ;
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSALoadSafetyArea2(System.IntPtr,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_GSALoadSafetyArea2_m6AEA62E27C5DEF48885DAA27F3047B743A2244DA (intptr_t ___0_lineCollectionPtr, bool ___1_isPlayArea, const RuntimeMethod* method) ;
// System.Double BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSABoundaryDetector2(BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i&,System.Boolean,BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i&,BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Pvr_SafeAreaAlgoAPI_GSABoundaryDetector2_m46B39B06530845701CCD110AD32A221A1FAB3EAC (GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17* ___0_point, bool ___1_isPlayArea, GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17* ___2_closestPoint, GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17* ___3_normalDir, const RuntimeMethod* method) ;
// System.Void BoundarySystem_Ext.Pvr_BoundarySystem::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_BoundarySystem__ctor_mBE03F7817B4691380E14CDABB8075CDDDC0E23EE (Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544* __this, const RuntimeMethod* method) ;
// System.Void BoundarySystem_Ext.Pvr_BoundaryAPI::Pvr_StartSDKBoundary()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_BoundaryAPI_Pvr_StartSDKBoundary_mAF7538BF823A7DA40D4F3B7BADB6C012D202C8C7 (const RuntimeMethod* method) ;
// System.Void BoundarySystem_Ext.Pvr_BoundaryAPI::Pvr_ShutdownSDKBoundary()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_BoundaryAPI_Pvr_ShutdownSDKBoundary_mA1D0C393D07DB079468FFAB969390AFF8B0063B2 (const RuntimeMethod* method) ;
// System.Void BoundarySystem_Ext.Pvr_BoundaryAPI::Pvr_DisableBoundary()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_BoundaryAPI_Pvr_DisableBoundary_mAF9486035CB9BABC00F4DF8721A3DAA6485D99EE (const RuntimeMethod* method) ;
// System.Void BoundarySystem_Ext.Pvr_BoundaryAPI::Pvr_BoundarySetSTBackground()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_BoundaryAPI_Pvr_BoundarySetSTBackground_m562BC298818979E6B757E4DD403348976A8CCD09 (const RuntimeMethod* method) ;
// System.Void BoundarySystem_Ext.Pvr_BoundaryAPI::Pvr_ResetVrModebyForce()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_BoundaryAPI_Pvr_ResetVrModebyForce_m4765B51C2360FED37DDDF6B1E099D496862762F1 (const RuntimeMethod* method) ;
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoModule::_SafeAreaCallback(System.IntPtr,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_SafeAreaAlgoModule__SafeAreaCallback_m756D201F90CFD3D062D71245E9C85697F8766969 (intptr_t ___0_lineCollectionPtr, intptr_t ___1_safeAreaRectPtr, const RuntimeMethod* method) ;
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoModule::_SafeAreaCallbackShrink(System.IntPtr,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_SafeAreaAlgoModule__SafeAreaCallbackShrink_m20C04C87D5E2E2708E462363D98BC4924BD3E354 (intptr_t ___0_lineCollectionPtr, intptr_t ___1_safeAreaDetailRectPtr, const RuntimeMethod* method) ;
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoModule::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_SafeAreaAlgoModule__ctor_mA8244BBC99C77398D1BC4BC85F483CF0A7AC8943 (Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05* __this, const RuntimeMethod* method) ;
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallback::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SafeAreaCallback__ctor_m5D6D26CADFF88B9822C7CBCEEC1C4C19244A8FF1 (SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::Pvr_GSASetCallback(BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_Pvr_GSASetCallback_mB2E1844A1B9CDF0C7B60BB0D004CCC69B0193EB5 (SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C* ___0_cb, const RuntimeMethod* method) ;
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallbackShrink::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SafeAreaCallbackShrink__ctor_m2665B8A76BA57763E8388611BA10C568215F7343 (SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::Pvr_GSASetCallbackShrink(BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallbackShrink)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_Pvr_GSASetCallbackShrink_m15C7B66FFD3672FC085E8608D2AAED9AF94EB8E2 (SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754* ___0_cb, const RuntimeMethod* method) ;
// System.Void UnityEngine.Debug::LogError(System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2 (RuntimeObject* ___0_message, const RuntimeMethod* method) ;
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::Pvr_GSAInit(System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_Pvr_GSAInit_m0FD61C053CACCEFCFCA5DC2A8C76C2DCD6D44E6C (int32_t ___0_width, int32_t ___1_height, const RuntimeMethod* method) ;
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::Pvr_GSAInit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_Pvr_GSAInit_m1C17FA05C9A9943779823DEA64EBACDAC863CF86 (const RuntimeMethod* method) ;
// System.IntPtr System.Runtime.InteropServices.Marshal::UnsafeAddrOfPinnedArrayElement<BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i>(T[],System.Int32)
inline intptr_t Marshal_UnsafeAddrOfPinnedArrayElement_TisGSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_m2FCC5D2D2C14567CAEFBA54CB0BE80EA9E9ED980 (GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1* ___0_arr, int32_t ___1_index, const RuntimeMethod* method)
{
	return ((  intptr_t (*) (GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1*, int32_t, const RuntimeMethod*))Marshal_UnsafeAddrOfPinnedArrayElement_TisGSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_m2FCC5D2D2C14567CAEFBA54CB0BE80EA9E9ED980_gshared)(___0_arr, ___1_index, method);
}
// System.IntPtr System.Runtime.InteropServices.Marshal::UnsafeAddrOfPinnedArrayElement<BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALine>(T[],System.Int32)
inline intptr_t Marshal_UnsafeAddrOfPinnedArrayElement_TisGSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E_m2655F1BCF3E2FE7B028C56300363CA8898B97CC4 (GSALineU5BU5D_tC2644452FF1B88D2D201F355FA28F65A5D8CF685* ___0_arr, int32_t ___1_index, const RuntimeMethod* method)
{
	return ((  intptr_t (*) (GSALineU5BU5D_tC2644452FF1B88D2D201F355FA28F65A5D8CF685*, int32_t, const RuntimeMethod*))Marshal_UnsafeAddrOfPinnedArrayElement_TisGSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E_m2655F1BCF3E2FE7B028C56300363CA8898B97CC4_gshared)(___0_arr, ___1_index, method);
}
// System.IntPtr BoundarySystem_Ext.Pvr_BoundaryAPI::StructToIntPtr<BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALineCollection>(T)
inline intptr_t Pvr_BoundaryAPI_StructToIntPtr_TisGSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E_m4A4DF55B0B16B585FA2439BED123BE4CA5ED44D5 (GSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E ___0_info, const RuntimeMethod* method)
{
	return ((  intptr_t (*) (GSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E, const RuntimeMethod*))Pvr_BoundaryAPI_StructToIntPtr_TisGSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E_m4A4DF55B0B16B585FA2439BED123BE4CA5ED44D5_gshared)(___0_info, method);
}
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::Pvr_GSAUpDateData(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_Pvr_GSAUpDateData_m2075353F1784E7877960B0A2BB9D98041C856D90 (intptr_t ___0_lineCollectionPtr, const RuntimeMethod* method) ;
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::Pvr_GSAShutDown()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_Pvr_GSAShutDown_mE515E181C0D3FF1EBB0EC648F2C8C31E2D17CE3B (const RuntimeMethod* method) ;
// System.Double BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::Pvr_GSABoundaryDetector(BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Pvr_SafeAreaAlgoAPI_Pvr_GSABoundaryDetector_mE4BC4C704D06B0F3B33987BA59E5B63618570308 (GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17* ___0_point, const RuntimeMethod* method) ;
// System.Double BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::Pvr_GSABoundaryDetector2(BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i&,System.Boolean,BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i&,BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Pvr_SafeAreaAlgoAPI_Pvr_GSABoundaryDetector2_m0009C8B90F40C2EDDD744D468E5F3EC0AFCEFAFD (GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17* ___0_point, bool ___1_isPlayArea, GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17* ___2_closestPoint, GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17* ___3_normalDir, const RuntimeMethod* method) ;
// System.Boolean System.IntPtr::op_Equality(System.IntPtr,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool IntPtr_op_Equality_m7D9CDCDE9DC2A0C2C614633F4921E90187FAB271 (intptr_t ___0_value1, intptr_t ___1_value2, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<UnityEngine.Vector3>::.ctor()
inline void List_1__ctor_mC54E2BCBE43279A96FC082F5CDE2D76388BD8F9C (List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, const RuntimeMethod*))List_1__ctor_mC54E2BCBE43279A96FC082F5CDE2D76388BD8F9C_gshared)(__this, method);
}
// System.Void System.Collections.Generic.List`1<System.Collections.Generic.List`1<UnityEngine.Vector3>>::.ctor()
inline void List_1__ctor_mBE9255218FAB0B859E0DD1B944986BBC7F1C3A33 (List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
// System.Type System.Type::GetTypeFromHandle(System.RuntimeTypeHandle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57 (RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ___0_handle, const RuntimeMethod* method) ;
// System.Int32 System.Runtime.InteropServices.Marshal::SizeOf(System.Type)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Marshal_SizeOf_mED64846722033D6F60C2973CA604B7C2D7D4A1B7 (Type_t* ___0_t, const RuntimeMethod* method) ;
// T BoundarySystem_Ext.Pvr_BoundaryAPI::IntPtrToStruct<BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSALineCollection>(System.IntPtr)
inline GSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E Pvr_BoundaryAPI_IntPtrToStruct_TisGSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E_m3C7EC489283FB44610163AB0091A1C279E4F7156 (intptr_t ___0_info, const RuntimeMethod* method)
{
	return ((  GSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E (*) (intptr_t, const RuntimeMethod*))Pvr_BoundaryAPI_IntPtrToStruct_TisGSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E_m3C7EC489283FB44610163AB0091A1C279E4F7156_gshared)(___0_info, method);
}
// System.Int64 System.IntPtr::ToInt64()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t IntPtr_ToInt64_m0F81FB6FB08014074D4F5B915EDAB06A08552032 (intptr_t* __this, const RuntimeMethod* method) ;
// System.Void System.IntPtr::.ctor(System.Int64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IntPtr__ctor_m2C033540A2F274766CF5C2A120587DD997E3F6DC (intptr_t* __this, int64_t ___0_value, const RuntimeMethod* method) ;
// System.Object System.Runtime.InteropServices.Marshal::PtrToStructure(System.IntPtr,System.Type)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Marshal_PtrToStructure_m235E141E21BFB69A01B07DDDF1702BA7D5723AC3 (intptr_t ___0_ptr, Type_t* ___1_structureType, const RuntimeMethod* method) ;
// System.Void UnityEngine.Vector3::.ctor(System.Single,System.Single,System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* __this, float ___0_x, float ___1_y, float ___2_z, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<UnityEngine.Vector3>::Add(T)
inline void List_1_Add_m79E50C4F592B1703F4B76A8BE7B4855515460CA1_inline (List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2, const RuntimeMethod*))List_1_Add_m79E50C4F592B1703F4B76A8BE7B4855515460CA1_gshared_inline)(__this, ___0_item, method);
}
// System.Void System.Collections.Generic.List`1<System.Collections.Generic.List`1<UnityEngine.Vector3>>::Add(T)
inline void List_1_Add_m8B5DEF3F8F4F49003BB953399B6E84A6DC941AC6_inline (List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* __this, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F*, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// T BoundarySystem_Ext.Pvr_BoundaryAPI::IntPtrToStruct<BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSARect>(System.IntPtr)
inline GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 Pvr_BoundaryAPI_IntPtrToStruct_TisGSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3_mF94DF99548B07FAD05377E537D93589DB1845B7F (intptr_t ___0_info, const RuntimeMethod* method)
{
	return ((  GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 (*) (intptr_t, const RuntimeMethod*))Pvr_BoundaryAPI_IntPtrToStruct_TisGSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3_mF94DF99548B07FAD05377E537D93589DB1845B7F_gshared)(___0_info, method);
}
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundarySystemCallback::Invoke(BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundaryPlayerArea,System.Collections.Generic.List`1<UnityEngine.Vector3>,System.Collections.Generic.List`1<System.Collections.Generic.List`1<UnityEngine.Vector3>>)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void BoundarySystemCallback_Invoke_m33091366DF51DF2DA3EA52496D5D30C2E56D5DAD_inline (BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD* __this, BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B ___0_playAreaInfo, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___1_boundaryPoints, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* ___2_unusedLines, const RuntimeMethod* method) ;
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundarySystemCallbackShrink::Invoke(System.Collections.Generic.List`1<UnityEngine.Vector3>,System.Collections.Generic.List`1<UnityEngine.Vector3>,System.Collections.Generic.List`1<System.Collections.Generic.List`1<UnityEngine.Vector3>>)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void BoundarySystemCallbackShrink_Invoke_m69E0E70D187835048D58FDE12323505C86C604F5_inline (BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75* __this, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___0_rectPoints, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___1_boundaryPoints, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* ___2_unusedLines, const RuntimeMethod* method) ;
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_libtrackingclient_INTERNAL
IL2CPP_EXTERN_C intptr_t CDECL CreateClient();
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_libtrackingclient_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL startTextureScanning(intptr_t, Il2CppMethodPointer);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_libtrackingclient_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL stopTextureScanning(intptr_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
IL2CPP_EXTERN_C void CDECL Pvr_StartSDKBoundary();
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
IL2CPP_EXTERN_C void CDECL Pvr_ShutdownSDKBoundary();
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL Pvr_GetMainSensorStateExt(float*, float*, float*, float*, float*, float*, float*, float*, float*, int32_t*);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
IL2CPP_EXTERN_C intptr_t CDECL Pvr_GetCameraData_Ext();
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
IL2CPP_EXTERN_C void CDECL Pvr_ResetVrModebyForce();
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL Pvr_ResumeBoundaryForSTS();
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
IL2CPP_EXTERN_C void CDECL Pvr_PauseBoundaryForSTS();
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
IL2CPP_EXTERN_C void CDECL Pvr_DisableBoundary();
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
IL2CPP_EXTERN_C void CDECL Pvr_BoundarySetSTBackground();
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL GSAInit();
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL GSAShutDown();
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL GSASetCallback(Il2CppMethodPointer);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL GSASetCallbackShrink(Il2CppMethodPointer);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL GSAUpDateData(intptr_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL GSASetConfigFilePath(intptr_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL GSAGetClosedAreaUpdateFlag();
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL GSALoadSafetyArea(intptr_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
IL2CPP_EXTERN_C double CDECL GSABoundaryDetector(GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17*);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL GSALoadSafetyArea2(intptr_t, int32_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
IL2CPP_EXTERN_C double CDECL GSABoundaryDetector2(GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17*, int32_t, GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17*, GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17*);
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void com.picoxr.tobframwork.EventManager::ClearListener()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventManager_ClearListener_m48B27511FE7CBDBBAC1BECB5DC28B9641C05CD1C (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Clear_mA5ED112FDE23E98A0E9A24339BF83DC1E0D2AB04_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// listenerDic.Clear();
		il2cpp_codegen_runtime_class_init_inline(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* L_0 = ((EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_StaticFields*)il2cpp_codegen_static_fields_for(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var))->___listenerDic_0;
		NullCheck(L_0);
		Dictionary_2_Clear_mA5ED112FDE23E98A0E9A24339BF83DC1E0D2AB04(L_0, Dictionary_2_Clear_mA5ED112FDE23E98A0E9A24339BF83DC1E0D2AB04_RuntimeMethod_var);
		// }
		return;
	}
}
// System.Void com.picoxr.tobframwork.EventManager::TriggerEvent(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventManager_TriggerEvent_m30611D2897C875A08828566C0AFC8CCBFA28F122 (String_t* ___0_eventID, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_TryGetValue_mEC9E9DC5A9A7DC8EC9D73564D35C0CEB7182ED6B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1F5F89035B9A8102A656517DE605AA84A1A3A454);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral87156C7367168BB1A9532BE4E84C37170C423556);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralA9312B81EA200B982D376EFED9466966CAEF31CC);
		s_Il2CppMethodInitialized = true;
	}
	Delegate_t* V_0 = NULL;
	bool V_1 = false;
	bool V_2 = false;
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* V_3 = NULL;
	int32_t V_4 = 0;
	Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* V_5 = NULL;
	bool V_6 = false;
	Exception_t* V_7 = NULL;
	bool V_8 = false;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	Type_t* G_B9_0 = NULL;
	int32_t G_B9_1 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B9_2 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B9_3 = NULL;
	Type_t* G_B8_0 = NULL;
	int32_t G_B8_1 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B8_2 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B8_3 = NULL;
	String_t* G_B10_0 = NULL;
	int32_t G_B10_1 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B10_2 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B10_3 = NULL;
	Exception_t* G_B12_0 = NULL;
	int32_t G_B12_1 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B12_2 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B12_3 = NULL;
	Exception_t* G_B11_0 = NULL;
	int32_t G_B11_1 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B11_2 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B11_3 = NULL;
	String_t* G_B13_0 = NULL;
	int32_t G_B13_1 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B13_2 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B13_3 = NULL;
	{
		// if (listenerDic.TryGetValue(eventID, out var d))
		il2cpp_codegen_runtime_class_init_inline(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* L_0 = ((EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_StaticFields*)il2cpp_codegen_static_fields_for(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var))->___listenerDic_0;
		String_t* L_1 = ___0_eventID;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_TryGetValue_mEC9E9DC5A9A7DC8EC9D73564D35C0CEB7182ED6B(L_0, L_1, (&V_0), Dictionary_2_TryGetValue_mEC9E9DC5A9A7DC8EC9D73564D35C0CEB7182ED6B_RuntimeMethod_var);
		V_1 = L_2;
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_0113;
		}
	}
	{
		// if (d != null)
		Delegate_t* L_4 = V_0;
		V_2 = (bool)((!(((RuntimeObject*)(Delegate_t*)L_4) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		bool L_5 = V_2;
		if (!L_5)
		{
			goto IL_0112;
		}
	}
	{
		// Delegate[] callbacks = d.GetInvocationList();
		Delegate_t* L_6 = V_0;
		NullCheck(L_6);
		DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* L_7;
		L_7 = VirtualFuncInvoker0< DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* >::Invoke(10 /* System.Delegate[] System.Delegate::GetInvocationList() */, L_6);
		V_3 = L_7;
		// for (int i = 0; i < callbacks.Length; i++)
		V_4 = 0;
		goto IL_0101;
	}

IL_0031:
	{
		// if (!(callbacks[i] is Action callback))
		DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* L_8 = V_3;
		int32_t L_9 = V_4;
		NullCheck(L_8);
		int32_t L_10 = L_9;
		Delegate_t* L_11 = (L_8)->GetAt(static_cast<il2cpp_array_size_t>(L_10));
		V_5 = ((Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)IsInstSealed((RuntimeObject*)L_11, Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var));
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_12 = V_5;
		V_6 = (bool)((((int32_t)((!(((RuntimeObject*)(Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)L_12) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_13 = V_6;
		if (!L_13)
		{
			goto IL_0068;
		}
	}
	{
		// Log.Error("Event Listener is Null");
		il2cpp_codegen_runtime_class_init_inline(Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		Log_Error_m2BCA24D454AF5A5E27541D7E21326D478C9BDE0B(_stringLiteralA9312B81EA200B982D376EFED9466966CAEF31CC, _stringLiteral1F5F89035B9A8102A656517DE605AA84A1A3A454, _stringLiteral87156C7367168BB1A9532BE4E84C37170C423556, ((int32_t)35), NULL);
		// return;
		goto IL_0113;
	}

IL_0068:
	{
	}
	try
	{// begin try (depth: 1)
		// callback();
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_14 = V_5;
		NullCheck(L_14);
		Action_Invoke_m7126A54DACA72B845424072887B5F3A51FC3808E_inline(L_14, NULL);
		goto IL_00fa;
	}// end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0078;
		}
		throw e;
	}

CATCH_0078:
	{// begin catch(System.Exception)
		{
			Exception_t* L_15 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
			// catch (Exception e)
			V_7 = L_15;
			// Log.Error("EventManager trigger event error, execute callback action exception. eventId="
			//            + eventID + ", target=" + callback.Target.GetType() + "." +
			//            callback.Method.Name + "\n" + e);
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_16 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var)), (uint32_t)8);
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_17 = L_16;
			NullCheck(L_17);
			ArrayElementTypeCheck (L_17, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF451A5CBDC80A01890663D7E00C100CC766F460E)));
			(L_17)->SetAt(static_cast<il2cpp_array_size_t>(0), (String_t*)((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF451A5CBDC80A01890663D7E00C100CC766F460E)));
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_18 = L_17;
			String_t* L_19 = ___0_eventID;
			NullCheck(L_18);
			ArrayElementTypeCheck (L_18, L_19);
			(L_18)->SetAt(static_cast<il2cpp_array_size_t>(1), (String_t*)L_19);
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_20 = L_18;
			NullCheck(L_20);
			ArrayElementTypeCheck (L_20, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2CF2ABA8D917B10559A7EA55260971A03AA54AB5)));
			(L_20)->SetAt(static_cast<il2cpp_array_size_t>(2), (String_t*)((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2CF2ABA8D917B10559A7EA55260971A03AA54AB5)));
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_21 = L_20;
			Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_22 = V_5;
			NullCheck(L_22);
			RuntimeObject* L_23;
			L_23 = Delegate_get_Target_m6E203F111C1548193A5AB7E616BD5834CD269753_inline(L_22, NULL);
			NullCheck(L_23);
			Type_t* L_24;
			L_24 = Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3(L_23, NULL);
			Type_t* L_25 = L_24;
			G_B8_0 = L_25;
			G_B8_1 = 3;
			G_B8_2 = L_21;
			G_B8_3 = L_21;
			if (L_25)
			{
				G_B9_0 = L_25;
				G_B9_1 = 3;
				G_B9_2 = L_21;
				G_B9_3 = L_21;
				goto IL_00aa;
			}
		}
		{
			G_B10_0 = ((String_t*)(NULL));
			G_B10_1 = G_B8_1;
			G_B10_2 = G_B8_2;
			G_B10_3 = G_B8_3;
			goto IL_00af;
		}

IL_00aa:
		{
			NullCheck(G_B9_0);
			String_t* L_26;
			L_26 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, G_B9_0);
			G_B10_0 = L_26;
			G_B10_1 = G_B9_1;
			G_B10_2 = G_B9_2;
			G_B10_3 = G_B9_3;
		}

IL_00af:
		{
			NullCheck(G_B10_2);
			ArrayElementTypeCheck (G_B10_2, G_B10_0);
			(G_B10_2)->SetAt(static_cast<il2cpp_array_size_t>(G_B10_1), (String_t*)G_B10_0);
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_27 = G_B10_3;
			NullCheck(L_27);
			ArrayElementTypeCheck (L_27, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF3E84B722399601AD7E281754E917478AA9AD48D)));
			(L_27)->SetAt(static_cast<il2cpp_array_size_t>(4), (String_t*)((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF3E84B722399601AD7E281754E917478AA9AD48D)));
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_28 = L_27;
			Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_29 = V_5;
			NullCheck(L_29);
			MethodInfo_t* L_30;
			L_30 = Delegate_get_Method_mB684A7525653DFE0EFC35E58449E1FC8E2A9F019(L_29, NULL);
			NullCheck(L_30);
			String_t* L_31;
			L_31 = VirtualFuncInvoker0< String_t* >::Invoke(7 /* System.String System.Reflection.MemberInfo::get_Name() */, L_30);
			NullCheck(L_28);
			ArrayElementTypeCheck (L_28, L_31);
			(L_28)->SetAt(static_cast<il2cpp_array_size_t>(5), (String_t*)L_31);
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_32 = L_28;
			NullCheck(L_32);
			ArrayElementTypeCheck (L_32, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral00B28FF06B788B9B67C6B259800F404F9F3761FD)));
			(L_32)->SetAt(static_cast<il2cpp_array_size_t>(6), (String_t*)((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral00B28FF06B788B9B67C6B259800F404F9F3761FD)));
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_33 = L_32;
			Exception_t* L_34 = V_7;
			Exception_t* L_35 = L_34;
			G_B11_0 = L_35;
			G_B11_1 = 7;
			G_B11_2 = L_33;
			G_B11_3 = L_33;
			if (L_35)
			{
				G_B12_0 = L_35;
				G_B12_1 = 7;
				G_B12_2 = L_33;
				G_B12_3 = L_33;
				goto IL_00da;
			}
		}
		{
			G_B13_0 = ((String_t*)(NULL));
			G_B13_1 = G_B11_1;
			G_B13_2 = G_B11_2;
			G_B13_3 = G_B11_3;
			goto IL_00df;
		}

IL_00da:
		{
			NullCheck(G_B12_0);
			String_t* L_36;
			L_36 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, G_B12_0);
			G_B13_0 = L_36;
			G_B13_1 = G_B12_1;
			G_B13_2 = G_B12_2;
			G_B13_3 = G_B12_3;
		}

IL_00df:
		{
			NullCheck(G_B13_2);
			ArrayElementTypeCheck (G_B13_2, G_B13_0);
			(G_B13_2)->SetAt(static_cast<il2cpp_array_size_t>(G_B13_1), (String_t*)G_B13_0);
			String_t* L_37;
			L_37 = String_Concat_m647EBF831F54B6DF7D5AFA5FD012CF4EE7571B6A(G_B13_3, NULL);
			il2cpp_codegen_runtime_class_init_inline(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var)));
			Log_Error_m2BCA24D454AF5A5E27541D7E21326D478C9BDE0B(L_37, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral1F5F89035B9A8102A656517DE605AA84A1A3A454)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral87156C7367168BB1A9532BE4E84C37170C423556)), ((int32_t)45), NULL);
			IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
			goto IL_00fa;
		}
	}// end catch (depth: 1)

IL_00fa:
	{
		// for (int i = 0; i < callbacks.Length; i++)
		int32_t L_38 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_38, 1));
	}

IL_0101:
	{
		// for (int i = 0; i < callbacks.Length; i++)
		int32_t L_39 = V_4;
		DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* L_40 = V_3;
		NullCheck(L_40);
		V_8 = (bool)((((int32_t)L_39) < ((int32_t)((int32_t)(((RuntimeArray*)L_40)->max_length))))? 1 : 0);
		bool L_41 = V_8;
		if (L_41)
		{
			goto IL_0031;
		}
	}
	{
	}

IL_0112:
	{
	}

IL_0113:
	{
		// }
		return;
	}
}
// System.Boolean com.picoxr.tobframwork.EventManager::HasEventListener(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool EventManager_HasEventListener_m7ECA640FF6A36A1B887CA93F2832B33D8EBCEACB (String_t* ___0_eventID, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_ContainsKey_mF167985044EB36A7BE3A47902F46FCEBAA42BFF3_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	{
		// return listenerDic.ContainsKey(eventID);
		il2cpp_codegen_runtime_class_init_inline(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* L_0 = ((EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_StaticFields*)il2cpp_codegen_static_fields_for(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var))->___listenerDic_0;
		String_t* L_1 = ___0_eventID;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_ContainsKey_mF167985044EB36A7BE3A47902F46FCEBAA42BFF3(L_0, L_1, Dictionary_2_ContainsKey_mF167985044EB36A7BE3A47902F46FCEBAA42BFF3_RuntimeMethod_var);
		V_0 = L_2;
		goto IL_000f;
	}

IL_000f:
	{
		// }
		bool L_3 = V_0;
		return L_3;
	}
}
// System.Boolean com.picoxr.tobframwork.EventManager::HasEventListener(System.String,System.Action)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool EventManager_HasEventListener_mADAFFB4FE6EE0BF90A8899D863ABBBAF26AB7850 (String_t* ___0_eventID, Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___1_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_get_Item_m3F278CCF586B177F156F2E6AB38D00CA6E002B15_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* V_0 = NULL;
	bool V_1 = false;
	bool V_2 = false;
	int32_t V_3 = 0;
	bool V_4 = false;
	bool V_5 = false;
	{
		// if (!HasEventListener(eventID))
		String_t* L_0 = ___0_eventID;
		il2cpp_codegen_runtime_class_init_inline(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = EventManager_HasEventListener_m7ECA640FF6A36A1B887CA93F2832B33D8EBCEACB(L_0, NULL);
		V_1 = (bool)((((int32_t)L_1) == ((int32_t)0))? 1 : 0);
		bool L_2 = V_1;
		if (!L_2)
		{
			goto IL_0013;
		}
	}
	{
		// return false;
		V_2 = (bool)0;
		goto IL_0052;
	}

IL_0013:
	{
		// var InvocationList = listenerDic[eventID].GetInvocationList();
		il2cpp_codegen_runtime_class_init_inline(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* L_3 = ((EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_StaticFields*)il2cpp_codegen_static_fields_for(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var))->___listenerDic_0;
		String_t* L_4 = ___0_eventID;
		NullCheck(L_3);
		Delegate_t* L_5;
		L_5 = Dictionary_2_get_Item_m3F278CCF586B177F156F2E6AB38D00CA6E002B15(L_3, L_4, Dictionary_2_get_Item_m3F278CCF586B177F156F2E6AB38D00CA6E002B15_RuntimeMethod_var);
		NullCheck(L_5);
		DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* L_6;
		L_6 = VirtualFuncInvoker0< DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* >::Invoke(10 /* System.Delegate[] System.Delegate::GetInvocationList() */, L_5);
		V_0 = L_6;
		// for (int i = 0; i < InvocationList.Length; i++)
		V_3 = 0;
		goto IL_0042;
	}

IL_0028:
	{
		// if (InvocationList[i] == (Delegate)handler)
		DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* L_7 = V_0;
		int32_t L_8 = V_3;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		Delegate_t* L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_11 = ___1_handler;
		bool L_12;
		L_12 = Delegate_op_Equality_m8B96593B665536587FFD27DE233442C075971C32(L_10, L_11, NULL);
		V_4 = L_12;
		bool L_13 = V_4;
		if (!L_13)
		{
			goto IL_003d;
		}
	}
	{
		// return true;
		V_2 = (bool)1;
		goto IL_0052;
	}

IL_003d:
	{
		// for (int i = 0; i < InvocationList.Length; i++)
		int32_t L_14 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_14, 1));
	}

IL_0042:
	{
		// for (int i = 0; i < InvocationList.Length; i++)
		int32_t L_15 = V_3;
		DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* L_16 = V_0;
		NullCheck(L_16);
		V_5 = (bool)((((int32_t)L_15) < ((int32_t)((int32_t)(((RuntimeArray*)L_16)->max_length))))? 1 : 0);
		bool L_17 = V_5;
		if (L_17)
		{
			goto IL_0028;
		}
	}
	{
		// return false;
		V_2 = (bool)0;
		goto IL_0052;
	}

IL_0052:
	{
		// }
		bool L_18 = V_2;
		return L_18;
	}
}
// System.Void com.picoxr.tobframwork.EventManager::AddEventListener(System.String,System.Action)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventManager_AddEventListener_m1C4B6F13DF82CCA6AC142AF21E7A0A844DD43DD8 (String_t* ___0_eventID, Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___1_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_get_Item_m3F278CCF586B177F156F2E6AB38D00CA6E002B15_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_set_Item_m0F4F2D2F1BEB8E000743301197554FD90E83F8A2_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	{
		// if (OnListenerAdding(eventID, handler))
		String_t* L_0 = ___0_eventID;
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_1 = ___1_handler;
		il2cpp_codegen_runtime_class_init_inline(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = EventManager_OnListenerAdding_m9FD8682351AA51BD53DE27FB97B5B3A986338651(L_0, L_1, NULL);
		V_0 = L_2;
		bool L_3 = V_0;
		if (!L_3)
		{
			goto IL_0035;
		}
	}
	{
		// listenerDic[eventID] = (Action)listenerDic[eventID] + handler;
		il2cpp_codegen_runtime_class_init_inline(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* L_4 = ((EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_StaticFields*)il2cpp_codegen_static_fields_for(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var))->___listenerDic_0;
		String_t* L_5 = ___0_eventID;
		Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* L_6 = ((EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_StaticFields*)il2cpp_codegen_static_fields_for(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var))->___listenerDic_0;
		String_t* L_7 = ___0_eventID;
		NullCheck(L_6);
		Delegate_t* L_8;
		L_8 = Dictionary_2_get_Item_m3F278CCF586B177F156F2E6AB38D00CA6E002B15(L_6, L_7, Dictionary_2_get_Item_m3F278CCF586B177F156F2E6AB38D00CA6E002B15_RuntimeMethod_var);
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_9 = ___1_handler;
		Delegate_t* L_10;
		L_10 = Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00(((Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)CastclassSealed((RuntimeObject*)L_8, Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var)), L_9, NULL);
		NullCheck(L_4);
		Dictionary_2_set_Item_m0F4F2D2F1BEB8E000743301197554FD90E83F8A2(L_4, L_5, ((Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)CastclassSealed((RuntimeObject*)L_10, Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var)), Dictionary_2_set_Item_m0F4F2D2F1BEB8E000743301197554FD90E83F8A2_RuntimeMethod_var);
	}

IL_0035:
	{
		// }
		return;
	}
}
// System.Boolean com.picoxr.tobframwork.EventManager::OnListenerAdding(System.String,System.Delegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool EventManager_OnListenerAdding_m9FD8682351AA51BD53DE27FB97B5B3A986338651 (String_t* ___0_eventID, Delegate_t* ___1_listener, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Add_mFC740DC4B588DEACABD94E8C79C0DD26C7065799_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_ContainsKey_mF167985044EB36A7BE3A47902F46FCEBAA42BFF3_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_get_Item_m3F278CCF586B177F156F2E6AB38D00CA6E002B15_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerable_Contains_TisDelegate_t_mFF006746882AAD944ED5B3D2CE5531200BE7F92B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral02E24DDAA670412016D1B7AE4DA2B990261581AF);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0F7D01CDED5602DC095024EB991F40C9D3A564B3);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1F5F89035B9A8102A656517DE605AA84A1A3A454);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral5F329E7A2983074AA233A92603C370A5AF39DD05);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral708B7431D97D837F21F808E2619E983B0FA9B7F4);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral940684AC39F0F6E67443D7A7AE8BCC0443B07B86);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF3E84B722399601AD7E281754E917478AA9AD48D);
		s_Il2CppMethodInitialized = true;
	}
	Delegate_t* V_0 = NULL;
	bool V_1 = false;
	bool V_2 = false;
	bool V_3 = false;
	bool V_4 = false;
	int32_t G_B5_0 = 0;
	int32_t G_B10_0 = 0;
	{
		// if (!listenerDic.ContainsKey(eventID))
		il2cpp_codegen_runtime_class_init_inline(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* L_0 = ((EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_StaticFields*)il2cpp_codegen_static_fields_for(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var))->___listenerDic_0;
		String_t* L_1 = ___0_eventID;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_ContainsKey_mF167985044EB36A7BE3A47902F46FCEBAA42BFF3(L_0, L_1, Dictionary_2_ContainsKey_mF167985044EB36A7BE3A47902F46FCEBAA42BFF3_RuntimeMethod_var);
		V_1 = (bool)((((int32_t)L_2) == ((int32_t)0))? 1 : 0);
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_0022;
		}
	}
	{
		// listenerDic.Add(eventID, null);
		il2cpp_codegen_runtime_class_init_inline(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* L_4 = ((EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_StaticFields*)il2cpp_codegen_static_fields_for(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var))->___listenerDic_0;
		String_t* L_5 = ___0_eventID;
		NullCheck(L_4);
		Dictionary_2_Add_mFC740DC4B588DEACABD94E8C79C0DD26C7065799(L_4, L_5, (Delegate_t*)NULL, Dictionary_2_Add_mFC740DC4B588DEACABD94E8C79C0DD26C7065799_RuntimeMethod_var);
	}

IL_0022:
	{
		// Delegate d = listenerDic[eventID];
		il2cpp_codegen_runtime_class_init_inline(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* L_6 = ((EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_StaticFields*)il2cpp_codegen_static_fields_for(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var))->___listenerDic_0;
		String_t* L_7 = ___0_eventID;
		NullCheck(L_6);
		Delegate_t* L_8;
		L_8 = Dictionary_2_get_Item_m3F278CCF586B177F156F2E6AB38D00CA6E002B15(L_6, L_7, Dictionary_2_get_Item_m3F278CCF586B177F156F2E6AB38D00CA6E002B15_RuntimeMethod_var);
		V_0 = L_8;
		// if (d != null && d.GetType() != listener.GetType())
		Delegate_t* L_9 = V_0;
		if (!L_9)
		{
			goto IL_0044;
		}
	}
	{
		Delegate_t* L_10 = V_0;
		NullCheck(L_10);
		Type_t* L_11;
		L_11 = Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3(L_10, NULL);
		Delegate_t* L_12 = ___1_listener;
		NullCheck(L_12);
		Type_t* L_13;
		L_13 = Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3(L_12, NULL);
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		bool L_14;
		L_14 = Type_op_Inequality_m83209C7BB3C05DFBEA3B6199B0BEFE8037301172(L_11, L_13, NULL);
		G_B5_0 = ((int32_t)(L_14));
		goto IL_0045;
	}

IL_0044:
	{
		G_B5_0 = 0;
	}

IL_0045:
	{
		V_2 = (bool)G_B5_0;
		bool L_15 = V_2;
		if (!L_15)
		{
			goto IL_00b1;
		}
	}
	{
		// Log.Debug($"Try to add not correct event {eventID}. Current type is {d.GetType().Name}, adding type is {listener.GetType().Name}.");
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_16 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)7);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_17 = L_16;
		NullCheck(L_17);
		ArrayElementTypeCheck (L_17, _stringLiteral708B7431D97D837F21F808E2619E983B0FA9B7F4);
		(L_17)->SetAt(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteral708B7431D97D837F21F808E2619E983B0FA9B7F4);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_18 = L_17;
		String_t* L_19 = ___0_eventID;
		NullCheck(L_18);
		ArrayElementTypeCheck (L_18, L_19);
		(L_18)->SetAt(static_cast<il2cpp_array_size_t>(1), (String_t*)L_19);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_20 = L_18;
		NullCheck(L_20);
		ArrayElementTypeCheck (L_20, _stringLiteral02E24DDAA670412016D1B7AE4DA2B990261581AF);
		(L_20)->SetAt(static_cast<il2cpp_array_size_t>(2), (String_t*)_stringLiteral02E24DDAA670412016D1B7AE4DA2B990261581AF);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_21 = L_20;
		Delegate_t* L_22 = V_0;
		NullCheck(L_22);
		Type_t* L_23;
		L_23 = Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3(L_22, NULL);
		NullCheck(L_23);
		String_t* L_24;
		L_24 = VirtualFuncInvoker0< String_t* >::Invoke(7 /* System.String System.Reflection.MemberInfo::get_Name() */, L_23);
		NullCheck(L_21);
		ArrayElementTypeCheck (L_21, L_24);
		(L_21)->SetAt(static_cast<il2cpp_array_size_t>(3), (String_t*)L_24);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_25 = L_21;
		NullCheck(L_25);
		ArrayElementTypeCheck (L_25, _stringLiteral0F7D01CDED5602DC095024EB991F40C9D3A564B3);
		(L_25)->SetAt(static_cast<il2cpp_array_size_t>(4), (String_t*)_stringLiteral0F7D01CDED5602DC095024EB991F40C9D3A564B3);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_26 = L_25;
		Delegate_t* L_27 = ___1_listener;
		NullCheck(L_27);
		Type_t* L_28;
		L_28 = Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3(L_27, NULL);
		NullCheck(L_28);
		String_t* L_29;
		L_29 = VirtualFuncInvoker0< String_t* >::Invoke(7 /* System.String System.Reflection.MemberInfo::get_Name() */, L_28);
		NullCheck(L_26);
		ArrayElementTypeCheck (L_26, L_29);
		(L_26)->SetAt(static_cast<il2cpp_array_size_t>(5), (String_t*)L_29);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_30 = L_26;
		NullCheck(L_30);
		ArrayElementTypeCheck (L_30, _stringLiteralF3E84B722399601AD7E281754E917478AA9AD48D);
		(L_30)->SetAt(static_cast<il2cpp_array_size_t>(6), (String_t*)_stringLiteralF3E84B722399601AD7E281754E917478AA9AD48D);
		String_t* L_31;
		L_31 = String_Concat_m647EBF831F54B6DF7D5AFA5FD012CF4EE7571B6A(L_30, NULL);
		il2cpp_codegen_runtime_class_init_inline(Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		Log_Debug_mBC6B7CAF0E12CB5777FB8FAAE59289CCDAED17A2(L_31, _stringLiteral1F5F89035B9A8102A656517DE605AA84A1A3A454, _stringLiteral5F329E7A2983074AA233A92603C370A5AF39DD05, ((int32_t)314), NULL);
		// return false;
		V_3 = (bool)0;
		goto IL_0132;
	}

IL_00b1:
	{
		// if (d != null && d.GetInvocationList().Contains(listener))
		Delegate_t* L_32 = V_0;
		if (!L_32)
		{
			goto IL_00c2;
		}
	}
	{
		Delegate_t* L_33 = V_0;
		NullCheck(L_33);
		DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* L_34;
		L_34 = VirtualFuncInvoker0< DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* >::Invoke(10 /* System.Delegate[] System.Delegate::GetInvocationList() */, L_33);
		Delegate_t* L_35 = ___1_listener;
		bool L_36;
		L_36 = Enumerable_Contains_TisDelegate_t_mFF006746882AAD944ED5B3D2CE5531200BE7F92B((RuntimeObject*)L_34, L_35, Enumerable_Contains_TisDelegate_t_mFF006746882AAD944ED5B3D2CE5531200BE7F92B_RuntimeMethod_var);
		G_B10_0 = ((int32_t)(L_36));
		goto IL_00c3;
	}

IL_00c2:
	{
		G_B10_0 = 0;
	}

IL_00c3:
	{
		V_4 = (bool)G_B10_0;
		bool L_37 = V_4;
		if (!L_37)
		{
			goto IL_012e;
		}
	}
	{
		// Log.Debug($"Try to add identical delegate to {eventID}. Current type is {d.GetType().Name}, adding type is {listener.GetType().Name}.");
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_38 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)7);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_39 = L_38;
		NullCheck(L_39);
		ArrayElementTypeCheck (L_39, _stringLiteral940684AC39F0F6E67443D7A7AE8BCC0443B07B86);
		(L_39)->SetAt(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteral940684AC39F0F6E67443D7A7AE8BCC0443B07B86);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_40 = L_39;
		String_t* L_41 = ___0_eventID;
		NullCheck(L_40);
		ArrayElementTypeCheck (L_40, L_41);
		(L_40)->SetAt(static_cast<il2cpp_array_size_t>(1), (String_t*)L_41);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_42 = L_40;
		NullCheck(L_42);
		ArrayElementTypeCheck (L_42, _stringLiteral02E24DDAA670412016D1B7AE4DA2B990261581AF);
		(L_42)->SetAt(static_cast<il2cpp_array_size_t>(2), (String_t*)_stringLiteral02E24DDAA670412016D1B7AE4DA2B990261581AF);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_43 = L_42;
		Delegate_t* L_44 = V_0;
		NullCheck(L_44);
		Type_t* L_45;
		L_45 = Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3(L_44, NULL);
		NullCheck(L_45);
		String_t* L_46;
		L_46 = VirtualFuncInvoker0< String_t* >::Invoke(7 /* System.String System.Reflection.MemberInfo::get_Name() */, L_45);
		NullCheck(L_43);
		ArrayElementTypeCheck (L_43, L_46);
		(L_43)->SetAt(static_cast<il2cpp_array_size_t>(3), (String_t*)L_46);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_47 = L_43;
		NullCheck(L_47);
		ArrayElementTypeCheck (L_47, _stringLiteral0F7D01CDED5602DC095024EB991F40C9D3A564B3);
		(L_47)->SetAt(static_cast<il2cpp_array_size_t>(4), (String_t*)_stringLiteral0F7D01CDED5602DC095024EB991F40C9D3A564B3);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_48 = L_47;
		Delegate_t* L_49 = ___1_listener;
		NullCheck(L_49);
		Type_t* L_50;
		L_50 = Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3(L_49, NULL);
		NullCheck(L_50);
		String_t* L_51;
		L_51 = VirtualFuncInvoker0< String_t* >::Invoke(7 /* System.String System.Reflection.MemberInfo::get_Name() */, L_50);
		NullCheck(L_48);
		ArrayElementTypeCheck (L_48, L_51);
		(L_48)->SetAt(static_cast<il2cpp_array_size_t>(5), (String_t*)L_51);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_52 = L_48;
		NullCheck(L_52);
		ArrayElementTypeCheck (L_52, _stringLiteralF3E84B722399601AD7E281754E917478AA9AD48D);
		(L_52)->SetAt(static_cast<il2cpp_array_size_t>(6), (String_t*)_stringLiteralF3E84B722399601AD7E281754E917478AA9AD48D);
		String_t* L_53;
		L_53 = String_Concat_m647EBF831F54B6DF7D5AFA5FD012CF4EE7571B6A(L_52, NULL);
		il2cpp_codegen_runtime_class_init_inline(Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		Log_Debug_mBC6B7CAF0E12CB5777FB8FAAE59289CCDAED17A2(L_53, _stringLiteral1F5F89035B9A8102A656517DE605AA84A1A3A454, _stringLiteral5F329E7A2983074AA233A92603C370A5AF39DD05, ((int32_t)326), NULL);
		// return false;
		V_3 = (bool)0;
		goto IL_0132;
	}

IL_012e:
	{
		// return true;
		V_3 = (bool)1;
		goto IL_0132;
	}

IL_0132:
	{
		// }
		bool L_54 = V_3;
		return L_54;
	}
}
// System.Void com.picoxr.tobframwork.EventManager::RemoveEventListener(System.String,System.Action)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventManager_RemoveEventListener_mDA08E4B6E0965BE5CE2524D699D09CCD15ECC7BF (String_t* ___0_eventID, Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___1_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_get_Item_m3F278CCF586B177F156F2E6AB38D00CA6E002B15_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_set_Item_m0F4F2D2F1BEB8E000743301197554FD90E83F8A2_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	{
		// if (OnListenerRemoving(eventID, handler))
		String_t* L_0 = ___0_eventID;
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_1 = ___1_handler;
		il2cpp_codegen_runtime_class_init_inline(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = EventManager_OnListenerRemoving_mF3EBB332D736B27865615A12B9B6C26B63F58A1B(L_0, L_1, NULL);
		V_0 = L_2;
		bool L_3 = V_0;
		if (!L_3)
		{
			goto IL_003c;
		}
	}
	{
		// listenerDic[eventID] = (Action)listenerDic[eventID] - handler;
		il2cpp_codegen_runtime_class_init_inline(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* L_4 = ((EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_StaticFields*)il2cpp_codegen_static_fields_for(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var))->___listenerDic_0;
		String_t* L_5 = ___0_eventID;
		Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* L_6 = ((EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_StaticFields*)il2cpp_codegen_static_fields_for(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var))->___listenerDic_0;
		String_t* L_7 = ___0_eventID;
		NullCheck(L_6);
		Delegate_t* L_8;
		L_8 = Dictionary_2_get_Item_m3F278CCF586B177F156F2E6AB38D00CA6E002B15(L_6, L_7, Dictionary_2_get_Item_m3F278CCF586B177F156F2E6AB38D00CA6E002B15_RuntimeMethod_var);
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_9 = ___1_handler;
		Delegate_t* L_10;
		L_10 = Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3(((Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)CastclassSealed((RuntimeObject*)L_8, Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var)), L_9, NULL);
		NullCheck(L_4);
		Dictionary_2_set_Item_m0F4F2D2F1BEB8E000743301197554FD90E83F8A2(L_4, L_5, ((Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)CastclassSealed((RuntimeObject*)L_10, Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var)), Dictionary_2_set_Item_m0F4F2D2F1BEB8E000743301197554FD90E83F8A2_RuntimeMethod_var);
		// OnListenerRemoved(eventID);
		String_t* L_11 = ___0_eventID;
		EventManager_OnListenerRemoved_m841ABBC22DF83E797CB4CBACFA8039E293FAAF7C(L_11, NULL);
	}

IL_003c:
	{
		// }
		return;
	}
}
// System.Boolean com.picoxr.tobframwork.EventManager::OnListenerRemoving(System.String,System.Delegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool EventManager_OnListenerRemoving_mF3EBB332D736B27865615A12B9B6C26B63F58A1B (String_t* ___0_eventID, Delegate_t* ___1_listener, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_ContainsKey_mF167985044EB36A7BE3A47902F46FCEBAA42BFF3_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_get_Item_m3F278CCF586B177F156F2E6AB38D00CA6E002B15_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1F5F89035B9A8102A656517DE605AA84A1A3A454);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB0A16419399D9150913BC905D0DA4EF93DB44958);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralFDB79CD128E738BD4E720C3243B9DD2867D1504E);
		s_Il2CppMethodInitialized = true;
	}
	Delegate_t* V_0 = NULL;
	bool V_1 = false;
	bool V_2 = false;
	bool V_3 = false;
	int32_t G_B5_0 = 0;
	{
		// if (!listenerDic.ContainsKey(eventID))
		il2cpp_codegen_runtime_class_init_inline(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* L_0 = ((EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_StaticFields*)il2cpp_codegen_static_fields_for(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var))->___listenerDic_0;
		String_t* L_1 = ___0_eventID;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_ContainsKey_mF167985044EB36A7BE3A47902F46FCEBAA42BFF3(L_0, L_1, Dictionary_2_ContainsKey_mF167985044EB36A7BE3A47902F46FCEBAA42BFF3_RuntimeMethod_var);
		V_1 = (bool)((((int32_t)L_2) == ((int32_t)0))? 1 : 0);
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_0018;
		}
	}
	{
		// return false;
		V_2 = (bool)0;
		goto IL_0075;
	}

IL_0018:
	{
		// Delegate d = listenerDic[eventID];
		il2cpp_codegen_runtime_class_init_inline(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* L_4 = ((EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_StaticFields*)il2cpp_codegen_static_fields_for(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var))->___listenerDic_0;
		String_t* L_5 = ___0_eventID;
		NullCheck(L_4);
		Delegate_t* L_6;
		L_6 = Dictionary_2_get_Item_m3F278CCF586B177F156F2E6AB38D00CA6E002B15(L_4, L_5, Dictionary_2_get_Item_m3F278CCF586B177F156F2E6AB38D00CA6E002B15_RuntimeMethod_var);
		V_0 = L_6;
		// if ((d != null) && (d.GetType() != listener.GetType()))
		Delegate_t* L_7 = V_0;
		if (!L_7)
		{
			goto IL_003a;
		}
	}
	{
		Delegate_t* L_8 = V_0;
		NullCheck(L_8);
		Type_t* L_9;
		L_9 = Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3(L_8, NULL);
		Delegate_t* L_10 = ___1_listener;
		NullCheck(L_10);
		Type_t* L_11;
		L_11 = Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3(L_10, NULL);
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		bool L_12;
		L_12 = Type_op_Inequality_m83209C7BB3C05DFBEA3B6199B0BEFE8037301172(L_9, L_11, NULL);
		G_B5_0 = ((int32_t)(L_12));
		goto IL_003b;
	}

IL_003a:
	{
		G_B5_0 = 0;
	}

IL_003b:
	{
		V_3 = (bool)G_B5_0;
		bool L_13 = V_3;
		if (!L_13)
		{
			goto IL_0070;
		}
	}
	{
		// Log.Error(
		//     $"Remove listener {eventID}\" failed, Current type is {d.GetType()}, adding type is {listener.GetType()}.");
		String_t* L_14 = ___0_eventID;
		Delegate_t* L_15 = V_0;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3(L_15, NULL);
		Delegate_t* L_17 = ___1_listener;
		NullCheck(L_17);
		Type_t* L_18;
		L_18 = Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3(L_17, NULL);
		String_t* L_19;
		L_19 = String_Format_mA0534D6E2AE4D67A6BD8D45B3321323930EB930C(_stringLiteralB0A16419399D9150913BC905D0DA4EF93DB44958, L_14, L_16, L_18, NULL);
		il2cpp_codegen_runtime_class_init_inline(Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		Log_Error_m2BCA24D454AF5A5E27541D7E21326D478C9BDE0B(L_19, _stringLiteral1F5F89035B9A8102A656517DE605AA84A1A3A454, _stringLiteralFDB79CD128E738BD4E720C3243B9DD2867D1504E, ((int32_t)400), NULL);
		// return false;
		V_2 = (bool)0;
		goto IL_0075;
	}

IL_0070:
	{
		// return true;
		V_2 = (bool)1;
		goto IL_0075;
	}

IL_0075:
	{
		// }
		bool L_20 = V_2;
		return L_20;
	}
}
// System.Void com.picoxr.tobframwork.EventManager::OnListenerRemoved(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventManager_OnListenerRemoved_m841ABBC22DF83E797CB4CBACFA8039E293FAAF7C (String_t* ___0_eventID, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_ContainsKey_mF167985044EB36A7BE3A47902F46FCEBAA42BFF3_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Remove_m1BF02B71B85F664D88F7EE0AA5733E7F013C81E3_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_get_Item_m3F278CCF586B177F156F2E6AB38D00CA6E002B15_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	int32_t G_B3_0 = 0;
	{
		// if (listenerDic.ContainsKey(eventID) && listenerDic[eventID] == null)
		il2cpp_codegen_runtime_class_init_inline(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* L_0 = ((EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_StaticFields*)il2cpp_codegen_static_fields_for(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var))->___listenerDic_0;
		String_t* L_1 = ___0_eventID;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_ContainsKey_mF167985044EB36A7BE3A47902F46FCEBAA42BFF3(L_0, L_1, Dictionary_2_ContainsKey_mF167985044EB36A7BE3A47902F46FCEBAA42BFF3_RuntimeMethod_var);
		if (!L_2)
		{
			goto IL_001e;
		}
	}
	{
		il2cpp_codegen_runtime_class_init_inline(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* L_3 = ((EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_StaticFields*)il2cpp_codegen_static_fields_for(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var))->___listenerDic_0;
		String_t* L_4 = ___0_eventID;
		NullCheck(L_3);
		Delegate_t* L_5;
		L_5 = Dictionary_2_get_Item_m3F278CCF586B177F156F2E6AB38D00CA6E002B15(L_3, L_4, Dictionary_2_get_Item_m3F278CCF586B177F156F2E6AB38D00CA6E002B15_RuntimeMethod_var);
		G_B3_0 = ((((RuntimeObject*)(Delegate_t*)L_5) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		goto IL_001f;
	}

IL_001e:
	{
		G_B3_0 = 0;
	}

IL_001f:
	{
		V_0 = (bool)G_B3_0;
		bool L_6 = V_0;
		if (!L_6)
		{
			goto IL_0031;
		}
	}
	{
		// listenerDic.Remove(eventID);
		il2cpp_codegen_runtime_class_init_inline(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* L_7 = ((EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_StaticFields*)il2cpp_codegen_static_fields_for(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var))->___listenerDic_0;
		String_t* L_8 = ___0_eventID;
		NullCheck(L_7);
		bool L_9;
		L_9 = Dictionary_2_Remove_m1BF02B71B85F664D88F7EE0AA5733E7F013C81E3(L_7, L_8, Dictionary_2_Remove_m1BF02B71B85F664D88F7EE0AA5733E7F013C81E3_RuntimeMethod_var);
	}

IL_0031:
	{
		// }
		return;
	}
}
// System.Void com.picoxr.tobframwork.EventManager::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventManager__ctor_m22CF004D043996A4D8AFA006A0D980424E7B8170 (EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
// System.Void com.picoxr.tobframwork.EventManager::.cctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EventManager__cctor_mA29C6E86E5F981F347CC67BCB95B42AF1425B6EB (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_mC11B8D87D7D6237273D0616824847584DA85B003_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private static readonly Dictionary<string, Delegate> listenerDic = new Dictionary<string, Delegate>();
		Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6* L_0 = (Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6*)il2cpp_codegen_object_new(Dictionary_2_tB14BC85C9EF5609A18FF14EC110F222FCF09EDB6_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Dictionary_2__ctor_mC11B8D87D7D6237273D0616824847584DA85B003(L_0, Dictionary_2__ctor_mC11B8D87D7D6237273D0616824847584DA85B003_RuntimeMethod_var);
		((EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_StaticFields*)il2cpp_codegen_static_fields_for(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var))->___listenerDic_0 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_StaticFields*)il2cpp_codegen_static_fields_for(EventManager_t7DEC9EF6FA86140640605C878736520723B2A4B5_il2cpp_TypeInfo_var))->___listenerDic_0), (void*)L_0);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void com.picoxr.tobframwork.RayHitPoint::Awake()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RayHitPoint_Awake_mA3370294446711A0E3DE2EEBC6364B8493C92DA2 (RayHitPoint_t4906E263121D0B6973D5818145F76E7E3DD1C9CE* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisXRRayInteractor_t0B25C1D5A938B199A71908E189AB351B43DA4C76_m0347BCF4E0361AA2A76B2D7C9C21327E8C4ADFE4_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// _rayInteractor = GetComponent<XRRayInteractor>();
		XRRayInteractor_t0B25C1D5A938B199A71908E189AB351B43DA4C76* L_0;
		L_0 = Component_GetComponent_TisXRRayInteractor_t0B25C1D5A938B199A71908E189AB351B43DA4C76_m0347BCF4E0361AA2A76B2D7C9C21327E8C4ADFE4(__this, Component_GetComponent_TisXRRayInteractor_t0B25C1D5A938B199A71908E189AB351B43DA4C76_m0347BCF4E0361AA2A76B2D7C9C21327E8C4ADFE4_RuntimeMethod_var);
		__this->____rayInteractor_5 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____rayInteractor_5), (void*)L_0);
		// }
		return;
	}
}
// System.Void com.picoxr.tobframwork.RayHitPoint::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RayHitPoint_Update_m3875D5E6DB8CCFFABB035B55083D953408B366BF (RayHitPoint_t4906E263121D0B6973D5818145F76E7E3DD1C9CE* __this, const RuntimeMethod* method) 
{
	bool V_0 = false;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_1;
	memset((&V_1), 0, sizeof(V_1));
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_2;
	memset((&V_2), 0, sizeof(V_2));
	int32_t V_3 = 0;
	bool V_4 = false;
	bool V_5 = false;
	bool V_6 = false;
	bool V_7 = false;
	{
		// bool hit = _rayInteractor.TryGetHitInfo(out var position, out var normal, out var positionInLine,
		//     out var isValidTarget);
		XRRayInteractor_t0B25C1D5A938B199A71908E189AB351B43DA4C76* L_0 = __this->____rayInteractor_5;
		NullCheck(L_0);
		bool L_1;
		L_1 = XRRayInteractor_TryGetHitInfo_mCC8B3B99CCA30572E3B29C7E9C019BD79E8B99BE(L_0, (&V_1), (&V_2), (&V_3), (&V_4), NULL);
		V_0 = L_1;
		// if (hit && isValidTarget)
		bool L_2 = V_0;
		bool L_3 = V_4;
		V_5 = (bool)((int32_t)((int32_t)L_2&(int32_t)L_3));
		bool L_4 = V_5;
		if (!L_4)
		{
			goto IL_006f;
		}
	}
	{
		// if (!UIPoint.gameObject.activeSelf)
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_5 = __this->___UIPoint_4;
		NullCheck(L_5);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_6;
		L_6 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_5, NULL);
		NullCheck(L_6);
		bool L_7;
		L_7 = GameObject_get_activeSelf_m4F3E5240E138B66AAA080EA30759A3D0517DA368(L_6, NULL);
		V_6 = (bool)((((int32_t)L_7) == ((int32_t)0))? 1 : 0);
		bool L_8 = V_6;
		if (!L_8)
		{
			goto IL_004d;
		}
	}
	{
		// UIPoint.gameObject.SetActive(true);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_9 = __this->___UIPoint_4;
		NullCheck(L_9);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_10;
		L_10 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_9, NULL);
		NullCheck(L_10);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_10, (bool)1, NULL);
	}

IL_004d:
	{
		// UIPoint.position = position;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_11 = __this->___UIPoint_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_12 = V_1;
		NullCheck(L_11);
		Transform_set_position_mA1A817124BB41B685043DED2A9BA48CDF37C4156(L_11, L_12, NULL);
		// UIPoint.forward = -normal;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_13 = __this->___UIPoint_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_14 = V_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_15;
		L_15 = Vector3_op_UnaryNegation_m5450829F333BD2A88AF9A592C4EE331661225915_inline(L_14, NULL);
		NullCheck(L_13);
		Transform_set_forward_mA178B5CF4F0F6133F9AF8ED3A4ECD2C604C60C26(L_13, L_15, NULL);
		goto IL_009b;
	}

IL_006f:
	{
		// if (UIPoint.gameObject.activeSelf)
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_16 = __this->___UIPoint_4;
		NullCheck(L_16);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_17;
		L_17 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_16, NULL);
		NullCheck(L_17);
		bool L_18;
		L_18 = GameObject_get_activeSelf_m4F3E5240E138B66AAA080EA30759A3D0517DA368(L_17, NULL);
		V_7 = L_18;
		bool L_19 = V_7;
		if (!L_19)
		{
			goto IL_009a;
		}
	}
	{
		// UIPoint.gameObject.SetActive(false);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_20 = __this->___UIPoint_4;
		NullCheck(L_20);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_21;
		L_21 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_20, NULL);
		NullCheck(L_21);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_21, (bool)0, NULL);
	}

IL_009a:
	{
	}

IL_009b:
	{
		// }
		return;
	}
}
// System.Void com.picoxr.tobframwork.RayHitPoint::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RayHitPoint__ctor_mD02EEFDE09A401C5E76527D499277CCBFA597699 (RayHitPoint_t4906E263121D0B6973D5818145F76E7E3DD1C9CE* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Type com.picoxr.tobframwork.UIGroup::get_VisibleType()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* UIGroup_get_VisibleType_mA41CE179ED2056EB660A6E986FC81C19BDC96E97 (UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* __this, const RuntimeMethod* method) 
{
	bool V_0 = false;
	Type_t* V_1 = NULL;
	int32_t G_B3_0 = 0;
	{
		// if (_visibleIndex < 0 || _visibleIndex > _openStates.Length - 1)
		int32_t L_0 = __this->____visibleIndex_8;
		if ((((int32_t)L_0) < ((int32_t)0)))
		{
			goto IL_001e;
		}
	}
	{
		int32_t L_1 = __this->____visibleIndex_8;
		BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4* L_2 = __this->____openStates_5;
		NullCheck(L_2);
		G_B3_0 = ((((int32_t)L_1) > ((int32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_2)->max_length)), 1))))? 1 : 0);
		goto IL_001f;
	}

IL_001e:
	{
		G_B3_0 = 1;
	}

IL_001f:
	{
		V_0 = (bool)G_B3_0;
		bool L_3 = V_0;
		if (!L_3)
		{
			goto IL_0028;
		}
	}
	{
		// return null;
		V_1 = (Type_t*)NULL;
		goto IL_003d;
	}

IL_0028:
	{
		// return _allUI[_visibleIndex].GetType();
		UIPageU5BU5D_t7F52BDD6ABCD90C3DC53772307DC5681B3D58496* L_4 = __this->____allUI_4;
		int32_t L_5 = __this->____visibleIndex_8;
		NullCheck(L_4);
		int32_t L_6 = L_5;
		UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* L_7 = (L_4)->GetAt(static_cast<il2cpp_array_size_t>(L_6));
		NullCheck(L_7);
		Type_t* L_8;
		L_8 = Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3(L_7, NULL);
		V_1 = L_8;
		goto IL_003d;
	}

IL_003d:
	{
		// }
		Type_t* L_9 = V_1;
		return L_9;
	}
}
// System.Void com.picoxr.tobframwork.UIGroup::Awake()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIGroup_Awake_m4944AAF3761E378302EEB775181D586EB3D3DEB8 (UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponentsInChildren_TisUIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387_m94464D52C05DF542C9B351530FA9E1E517AD9265_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_set_Item_m523CB8EB40145B2FB212BB32F0E7B19E62D582BD_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	Type_t* V_1 = NULL;
	bool V_2 = false;
	{
		// _allUI = GetComponentsInChildren<UIPage>(true);
		UIPageU5BU5D_t7F52BDD6ABCD90C3DC53772307DC5681B3D58496* L_0;
		L_0 = Component_GetComponentsInChildren_TisUIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387_m94464D52C05DF542C9B351530FA9E1E517AD9265(__this, (bool)1, Component_GetComponentsInChildren_TisUIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387_m94464D52C05DF542C9B351530FA9E1E517AD9265_RuntimeMethod_var);
		__this->____allUI_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____allUI_4), (void*)L_0);
		// _openStates = new bool[_allUI.Length];
		UIPageU5BU5D_t7F52BDD6ABCD90C3DC53772307DC5681B3D58496* L_1 = __this->____allUI_4;
		NullCheck(L_1);
		BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4* L_2 = (BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4*)(BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4*)SZArrayNew(BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4_il2cpp_TypeInfo_var, (uint32_t)((int32_t)(((RuntimeArray*)L_1)->max_length)));
		__this->____openStates_5 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____openStates_5), (void*)L_2);
		// for (int i = 0; i < _allUI.Length; i++)
		V_0 = 0;
		goto IL_0047;
	}

IL_0025:
	{
		// Type uiType = _allUI[i].GetType();
		UIPageU5BU5D_t7F52BDD6ABCD90C3DC53772307DC5681B3D58496* L_3 = __this->____allUI_4;
		int32_t L_4 = V_0;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		NullCheck(L_6);
		Type_t* L_7;
		L_7 = Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3(L_6, NULL);
		V_1 = L_7;
		// _uiTypeToIndex[uiType] = i;
		Dictionary_2_t384D2A0FF42BF1302A3F513FC32DB105F1CD5455* L_8 = __this->____uiTypeToIndex_6;
		Type_t* L_9 = V_1;
		int32_t L_10 = V_0;
		NullCheck(L_8);
		Dictionary_2_set_Item_m523CB8EB40145B2FB212BB32F0E7B19E62D582BD(L_8, L_9, L_10, Dictionary_2_set_Item_m523CB8EB40145B2FB212BB32F0E7B19E62D582BD_RuntimeMethod_var);
		// for (int i = 0; i < _allUI.Length; i++)
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_0047:
	{
		// for (int i = 0; i < _allUI.Length; i++)
		int32_t L_12 = V_0;
		UIPageU5BU5D_t7F52BDD6ABCD90C3DC53772307DC5681B3D58496* L_13 = __this->____allUI_4;
		NullCheck(L_13);
		V_2 = (bool)((((int32_t)L_12) < ((int32_t)((int32_t)(((RuntimeArray*)L_13)->max_length))))? 1 : 0);
		bool L_14 = V_2;
		if (L_14)
		{
			goto IL_0025;
		}
	}
	{
		// }
		return;
	}
}
// com.picoxr.tobframwork.UIPage com.picoxr.tobframwork.UIGroup::OpenUI(System.Type)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* UIGroup_OpenUI_mBAC95032DBF27BADDCCC00F8E0205A327847AA26 (UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* __this, Type_t* ___0_type, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_TryGetValue_m3EF4F6B2EC138E3A20BD7549CE6DE54B0608CD4D_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	bool V_1 = false;
	UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* V_2 = NULL;
	{
		// if (_uiTypeToIndex.TryGetValue(type, out var index))
		Dictionary_2_t384D2A0FF42BF1302A3F513FC32DB105F1CD5455* L_0 = __this->____uiTypeToIndex_6;
		Type_t* L_1 = ___0_type;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_TryGetValue_m3EF4F6B2EC138E3A20BD7549CE6DE54B0608CD4D(L_0, L_1, (&V_0), Dictionary_2_TryGetValue_m3EF4F6B2EC138E3A20BD7549CE6DE54B0608CD4D_RuntimeMethod_var);
		V_1 = L_2;
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_002f;
		}
	}
	{
		// _openStates[index] = true;
		BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4* L_4 = __this->____openStates_5;
		int32_t L_5 = V_0;
		NullCheck(L_4);
		(L_4)->SetAt(static_cast<il2cpp_array_size_t>(L_5), (bool)1);
		// UpdateState();
		UIGroup_UpdateState_m1B5A0F23B73D375A2410ADC2128466E73E7E8FCB(__this, NULL);
		// return _allUI[index];
		UIPageU5BU5D_t7F52BDD6ABCD90C3DC53772307DC5681B3D58496* L_6 = __this->____allUI_4;
		int32_t L_7 = V_0;
		NullCheck(L_6);
		int32_t L_8 = L_7;
		UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* L_9 = (L_6)->GetAt(static_cast<il2cpp_array_size_t>(L_8));
		V_2 = L_9;
		goto IL_0033;
	}

IL_002f:
	{
		// return null;
		V_2 = (UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387*)NULL;
		goto IL_0033;
	}

IL_0033:
	{
		// }
		UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* L_10 = V_2;
		return L_10;
	}
}
// System.Void com.picoxr.tobframwork.UIGroup::Close(System.Type)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIGroup_Close_m40933FE144C6A4E765D2944639734A2068952E39 (UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* __this, Type_t* ___0_type, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_TryGetValue_m3EF4F6B2EC138E3A20BD7549CE6DE54B0608CD4D_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	bool V_1 = false;
	{
		// if (_uiTypeToIndex.TryGetValue(type, out var index))
		Dictionary_2_t384D2A0FF42BF1302A3F513FC32DB105F1CD5455* L_0 = __this->____uiTypeToIndex_6;
		Type_t* L_1 = ___0_type;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_TryGetValue_m3EF4F6B2EC138E3A20BD7549CE6DE54B0608CD4D(L_0, L_1, (&V_0), Dictionary_2_TryGetValue_m3EF4F6B2EC138E3A20BD7549CE6DE54B0608CD4D_RuntimeMethod_var);
		V_1 = L_2;
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_001e;
		}
	}
	{
		// _openStates[index] = false;
		BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4* L_4 = __this->____openStates_5;
		int32_t L_5 = V_0;
		NullCheck(L_4);
		(L_4)->SetAt(static_cast<il2cpp_array_size_t>(L_5), (bool)0);
	}

IL_001e:
	{
		// UpdateState();
		UIGroup_UpdateState_m1B5A0F23B73D375A2410ADC2128466E73E7E8FCB(__this, NULL);
		// }
		return;
	}
}
// System.Void com.picoxr.tobframwork.UIGroup::UpdateState()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIGroup_UpdateState_m1B5A0F23B73D375A2410ADC2128466E73E7E8FCB (UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	bool V_2 = false;
	UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* V_3 = NULL;
	bool V_4 = false;
	bool V_5 = false;
	bool V_6 = false;
	bool V_7 = false;
	int32_t G_B6_0 = 0;
	{
		// int priority = -1;
		V_0 = (-1);
		// for (int i = _openStates.Length - 1; i >= 0; i--)
		BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4* L_0 = __this->____openStates_5;
		NullCheck(L_0);
		V_1 = ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_0)->max_length)), 1));
		goto IL_005d;
	}

IL_0010:
	{
		// bool active = _openStates[i];
		BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4* L_1 = __this->____openStates_5;
		int32_t L_2 = V_1;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		uint8_t L_4 = (uint8_t)(L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_2 = (bool)L_4;
		// UIPage page = _allUI[i];
		UIPageU5BU5D_t7F52BDD6ABCD90C3DC53772307DC5681B3D58496* L_5 = __this->____allUI_4;
		int32_t L_6 = V_1;
		NullCheck(L_5);
		int32_t L_7 = L_6;
		UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* L_8 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		V_3 = L_8;
		// if (page.nonExclusive)
		UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* L_9 = V_3;
		NullCheck(L_9);
		bool L_10 = L_9->___nonExclusive_5;
		V_5 = L_10;
		bool L_11 = V_5;
		if (!L_11)
		{
			goto IL_0032;
		}
	}
	{
		// continue;
		goto IL_0059;
	}

IL_0032:
	{
		// bool show = active && i > priority;
		bool L_12 = V_2;
		if (!L_12)
		{
			goto IL_003b;
		}
	}
	{
		int32_t L_13 = V_1;
		int32_t L_14 = V_0;
		G_B6_0 = ((((int32_t)L_13) > ((int32_t)L_14))? 1 : 0);
		goto IL_003c;
	}

IL_003b:
	{
		G_B6_0 = 0;
	}

IL_003c:
	{
		V_4 = (bool)G_B6_0;
		// page.gameObject.SetActive(show);
		UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* L_15 = V_3;
		NullCheck(L_15);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_16;
		L_16 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_15, NULL);
		bool L_17 = V_4;
		NullCheck(L_16);
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_16, L_17, NULL);
		// if (show)
		bool L_18 = V_4;
		V_6 = L_18;
		bool L_19 = V_6;
		if (!L_19)
		{
			goto IL_0058;
		}
	}
	{
		// priority = i;
		int32_t L_20 = V_1;
		V_0 = L_20;
	}

IL_0058:
	{
	}

IL_0059:
	{
		// for (int i = _openStates.Length - 1; i >= 0; i--)
		int32_t L_21 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_subtract(L_21, 1));
	}

IL_005d:
	{
		// for (int i = _openStates.Length - 1; i >= 0; i--)
		int32_t L_22 = V_1;
		V_7 = (bool)((((int32_t)((((int32_t)L_22) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_23 = V_7;
		if (L_23)
		{
			goto IL_0010;
		}
	}
	{
		// }
		return;
	}
}
// System.Void com.picoxr.tobframwork.UIGroup::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIGroup__ctor_m8D8D420E7B7F2D09248F9D093F5EA39EC49CCAD0 (UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_m0AF6A9E01056850C9F7AE464B4099CA3F6D5E8EC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_t384D2A0FF42BF1302A3F513FC32DB105F1CD5455_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public UIPage[] _allUI = null;
		__this->____allUI_4 = (UIPageU5BU5D_t7F52BDD6ABCD90C3DC53772307DC5681B3D58496*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____allUI_4), (void*)(UIPageU5BU5D_t7F52BDD6ABCD90C3DC53772307DC5681B3D58496*)NULL);
		// private bool[] _openStates = null;
		__this->____openStates_5 = (BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____openStates_5), (void*)(BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4*)NULL);
		// private Dictionary<Type, int> _uiTypeToIndex = new Dictionary<Type, int>();
		Dictionary_2_t384D2A0FF42BF1302A3F513FC32DB105F1CD5455* L_0 = (Dictionary_2_t384D2A0FF42BF1302A3F513FC32DB105F1CD5455*)il2cpp_codegen_object_new(Dictionary_2_t384D2A0FF42BF1302A3F513FC32DB105F1CD5455_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Dictionary_2__ctor_m0AF6A9E01056850C9F7AE464B4099CA3F6D5E8EC(L_0, Dictionary_2__ctor_m0AF6A9E01056850C9F7AE464B4099CA3F6D5E8EC_RuntimeMethod_var);
		__this->____uiTypeToIndex_6 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____uiTypeToIndex_6), (void*)L_0);
		// private int _visibleIndex = -1;
		__this->____visibleIndex_8 = (-1);
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// com.picoxr.tobframwork.UIGroup com.picoxr.tobframwork.UIPage::get_Group()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* UIPage_get_Group_m1553A3E497FCF802E7EB13649C50DE62EF308F12 (UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* __this, const RuntimeMethod* method) 
{
	UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* V_0 = NULL;
	{
		// get { return _group; }
		UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* L_0 = __this->____group_4;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		// get { return _group; }
		UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* L_1 = V_0;
		return L_1;
	}
}
// System.Void com.picoxr.tobframwork.UIPage::SetGroup(com.picoxr.tobframwork.UIGroup)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIPage_SetGroup_mBFAE61AE2F91F5FB313B45853A19A71F4E0B625B (UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* __this, UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* ___0_group, const RuntimeMethod* method) 
{
	{
		// _group = group;
		UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* L_0 = ___0_group;
		__this->____group_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____group_4), (void*)L_0);
		// }
		return;
	}
}
// System.Void com.picoxr.tobframwork.UIPage::OnOpen(System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIPage_OnOpen_m0E8B930ABDCAFAF243166B4E998F73CD08FED297 (UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* __this, RuntimeObject* ___0_data, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void com.picoxr.tobframwork.UIPage::Close()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIPage_Close_m7A5C26702E2141E8EFCF34A301EE7E1C6CF86F2D (UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* __this, const RuntimeMethod* method) 
{
	{
		// UIPageManager.Close(GetType());
		Type_t* L_0;
		L_0 = Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3(__this, NULL);
		UIPageManager_Close_mEBB5FCBE4D27BE856B8D78C73AA2DF70D84E7BE5(L_0, NULL);
		// }
		return;
	}
}
// System.Void com.picoxr.tobframwork.UIPage::OnEnable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIPage_OnEnable_m433DB71FD5FAB31F32E0CF0382845830D5E76530 (UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral43EF9CFD5F4CF32E84213BE3484FCAD18DCDC3EE);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral6E16C4C2594F76B5D6EEFC421689AE28C6AD5D0D);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral9CB459ADC305561267AD22C5CC73F6F88CA38134);
		s_Il2CppMethodInitialized = true;
	}
	UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* G_B2_0 = NULL;
	UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* G_B1_0 = NULL;
	String_t* G_B3_0 = NULL;
	{
		// Log.Debug(this + " OnEnable");
		G_B1_0 = __this;
		if (__this)
		{
			G_B2_0 = __this;
			goto IL_0009;
		}
	}
	{
		G_B3_0 = ((String_t*)(NULL));
		goto IL_000e;
	}

IL_0009:
	{
		NullCheck(G_B2_0);
		String_t* L_0;
		L_0 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, G_B2_0);
		G_B3_0 = L_0;
	}

IL_000e:
	{
		String_t* L_1;
		L_1 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(G_B3_0, _stringLiteral43EF9CFD5F4CF32E84213BE3484FCAD18DCDC3EE, NULL);
		il2cpp_codegen_runtime_class_init_inline(Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		Log_Debug_mBC6B7CAF0E12CB5777FB8FAAE59289CCDAED17A2(L_1, _stringLiteral6E16C4C2594F76B5D6EEFC421689AE28C6AD5D0D, _stringLiteral9CB459ADC305561267AD22C5CC73F6F88CA38134, ((int32_t)38), NULL);
		// }
		return;
	}
}
// System.Void com.picoxr.tobframwork.UIPage::OnDisable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIPage_OnDisable_mC4133C883C73427603A90DA27F0E357803662681 (UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral3BD04D31675F8DF792A6C8A1153D895FE991A0A3);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral6E16C4C2594F76B5D6EEFC421689AE28C6AD5D0D);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDFCF5C8693CD5D607CE4AF43C48DAA6C9B24A959);
		s_Il2CppMethodInitialized = true;
	}
	UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* G_B2_0 = NULL;
	UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* G_B1_0 = NULL;
	String_t* G_B3_0 = NULL;
	{
		// Log.Debug(this + " OnDisable");
		G_B1_0 = __this;
		if (__this)
		{
			G_B2_0 = __this;
			goto IL_0009;
		}
	}
	{
		G_B3_0 = ((String_t*)(NULL));
		goto IL_000e;
	}

IL_0009:
	{
		NullCheck(G_B2_0);
		String_t* L_0;
		L_0 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, G_B2_0);
		G_B3_0 = L_0;
	}

IL_000e:
	{
		String_t* L_1;
		L_1 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(G_B3_0, _stringLiteral3BD04D31675F8DF792A6C8A1153D895FE991A0A3, NULL);
		il2cpp_codegen_runtime_class_init_inline(Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		Log_Debug_mBC6B7CAF0E12CB5777FB8FAAE59289CCDAED17A2(L_1, _stringLiteral6E16C4C2594F76B5D6EEFC421689AE28C6AD5D0D, _stringLiteralDFCF5C8693CD5D607CE4AF43C48DAA6C9B24A959, ((int32_t)43), NULL);
		// }
		return;
	}
}
// System.Void com.picoxr.tobframwork.UIPage::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIPage__ctor_m0639E3FF82D740B6346A17CC778CE6477AEB7F31 (UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* __this, const RuntimeMethod* method) 
{
	{
		// public bool nonExclusive = false;
		__this->___nonExclusive_5 = (bool)0;
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void com.picoxr.tobframwork.UIPageManager::Awake()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIPageManager_Awake_m4BA0FC37EBA50A1BFBC1611308C06A95B09688A7 (UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponentInParent_TisUIGroup_tC217247301A179C554813A009381C0404ECC1DDF_mE896505A28C23576CBC229CC8A54B6429415E378_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Add_mF5BAF98BB9FA8006CAAA49255DB0A4564F5EB444_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_GetComponentsInChildren_TisUIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387_mD11B8C3BB77751DD9FC69ABF4546E706BBEF1F2A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	UIPageU5BU5D_t7F52BDD6ABCD90C3DC53772307DC5681B3D58496* V_0 = NULL;
	int32_t V_1 = 0;
	UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* V_2 = NULL;
	UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* V_3 = NULL;
	bool V_4 = false;
	{
		// _instance = this;
		((UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B_StaticFields*)il2cpp_codegen_static_fields_for(UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B_il2cpp_TypeInfo_var))->____instance_5 = __this;
		Il2CppCodeGenWriteBarrier((void**)(&((UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B_StaticFields*)il2cpp_codegen_static_fields_for(UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B_il2cpp_TypeInfo_var))->____instance_5), (void*)__this);
		// UIPage[] pages = gameObject.GetComponentsInChildren<UIPage>(true);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0;
		L_0 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(__this, NULL);
		NullCheck(L_0);
		UIPageU5BU5D_t7F52BDD6ABCD90C3DC53772307DC5681B3D58496* L_1;
		L_1 = GameObject_GetComponentsInChildren_TisUIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387_mD11B8C3BB77751DD9FC69ABF4546E706BBEF1F2A(L_0, (bool)1, GameObject_GetComponentsInChildren_TisUIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387_mD11B8C3BB77751DD9FC69ABF4546E706BBEF1F2A_RuntimeMethod_var);
		V_0 = L_1;
		// for (int i = 0; i < pages.Length; i++)
		V_1 = 0;
		goto IL_0044;
	}

IL_0018:
	{
		// UIPage page = pages[i];
		UIPageU5BU5D_t7F52BDD6ABCD90C3DC53772307DC5681B3D58496* L_2 = V_0;
		int32_t L_3 = V_1;
		NullCheck(L_2);
		int32_t L_4 = L_3;
		UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* L_5 = (L_2)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		V_2 = L_5;
		// UIGroup group = page.GetComponentInParent<UIGroup>();
		UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* L_6 = V_2;
		NullCheck(L_6);
		UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* L_7;
		L_7 = Component_GetComponentInParent_TisUIGroup_tC217247301A179C554813A009381C0404ECC1DDF_mE896505A28C23576CBC229CC8A54B6429415E378(L_6, Component_GetComponentInParent_TisUIGroup_tC217247301A179C554813A009381C0404ECC1DDF_mE896505A28C23576CBC229CC8A54B6429415E378_RuntimeMethod_var);
		V_3 = L_7;
		// page.SetGroup(group);
		UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* L_8 = V_2;
		UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* L_9 = V_3;
		NullCheck(L_8);
		UIPage_SetGroup_mBFAE61AE2F91F5FB313B45853A19A71F4E0B625B(L_8, L_9, NULL);
		// _cachePage.Add(page.GetType(), page);
		Dictionary_2_t1BF400F50D50E19CF6FCD3FF520384A96269F89F* L_10 = __this->____cachePage_4;
		UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* L_11 = V_2;
		NullCheck(L_11);
		Type_t* L_12;
		L_12 = Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3(L_11, NULL);
		UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* L_13 = V_2;
		NullCheck(L_10);
		Dictionary_2_Add_mF5BAF98BB9FA8006CAAA49255DB0A4564F5EB444(L_10, L_12, L_13, Dictionary_2_Add_mF5BAF98BB9FA8006CAAA49255DB0A4564F5EB444_RuntimeMethod_var);
		// for (int i = 0; i < pages.Length; i++)
		int32_t L_14 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_14, 1));
	}

IL_0044:
	{
		// for (int i = 0; i < pages.Length; i++)
		int32_t L_15 = V_1;
		UIPageU5BU5D_t7F52BDD6ABCD90C3DC53772307DC5681B3D58496* L_16 = V_0;
		NullCheck(L_16);
		V_4 = (bool)((((int32_t)L_15) < ((int32_t)((int32_t)(((RuntimeArray*)L_16)->max_length))))? 1 : 0);
		bool L_17 = V_4;
		if (L_17)
		{
			goto IL_0018;
		}
	}
	{
		// }
		return;
	}
}
// com.picoxr.tobframwork.UIPageManager com.picoxr.tobframwork.UIPageManager::get_Instance()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B* UIPageManager_get_Instance_m5120E48454206F376E0C1E55A4A9DDE4FFAE2E91 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B* V_0 = NULL;
	{
		// get { return _instance; }
		UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B* L_0 = ((UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B_StaticFields*)il2cpp_codegen_static_fields_for(UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B_il2cpp_TypeInfo_var))->____instance_5;
		V_0 = L_0;
		goto IL_0009;
	}

IL_0009:
	{
		// get { return _instance; }
		UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B* L_1 = V_0;
		return L_1;
	}
}
// System.Boolean com.picoxr.tobframwork.UIPageManager::_CloseUI(System.Type)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool UIPageManager__CloseUI_m9AF9FCA67ECF7C6FDD2C9E2C7250787C1094FF51 (UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B* __this, Type_t* ___0_type, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_TryGetValue_mB9EEAAD08A35C274F212D4C739347DE6120A6C2B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralABEA19C219C733FF3FE45E06F0F298F769041ABD);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC6387E9C5A822DD5AA6EEBF9DF80A690DBC81B7E);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCDF1157616009A2B26E7D53D070334F4188B9624);
		s_Il2CppMethodInitialized = true;
	}
	UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* V_0 = NULL;
	bool V_1 = false;
	bool V_2 = false;
	Type_t* G_B3_0 = NULL;
	String_t* G_B3_1 = NULL;
	Type_t* G_B2_0 = NULL;
	String_t* G_B2_1 = NULL;
	String_t* G_B4_0 = NULL;
	String_t* G_B4_1 = NULL;
	Type_t* G_B7_0 = NULL;
	String_t* G_B7_1 = NULL;
	Type_t* G_B6_0 = NULL;
	String_t* G_B6_1 = NULL;
	String_t* G_B8_0 = NULL;
	String_t* G_B8_1 = NULL;
	{
		// if (!_cachePage.TryGetValue(type, out page))
		Dictionary_2_t1BF400F50D50E19CF6FCD3FF520384A96269F89F* L_0 = __this->____cachePage_4;
		Type_t* L_1 = ___0_type;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_TryGetValue_mB9EEAAD08A35C274F212D4C739347DE6120A6C2B(L_0, L_1, (&V_0), Dictionary_2_TryGetValue_mB9EEAAD08A35C274F212D4C739347DE6120A6C2B_RuntimeMethod_var);
		V_1 = (bool)((((int32_t)L_2) == ((int32_t)0))? 1 : 0);
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_0044;
		}
	}
	{
		// Log.Error("_CloseUI " + type);
		Type_t* L_4 = ___0_type;
		Type_t* L_5 = L_4;
		G_B2_0 = L_5;
		G_B2_1 = _stringLiteralABEA19C219C733FF3FE45E06F0F298F769041ABD;
		if (L_5)
		{
			G_B3_0 = L_5;
			G_B3_1 = _stringLiteralABEA19C219C733FF3FE45E06F0F298F769041ABD;
			goto IL_0024;
		}
	}
	{
		G_B4_0 = ((String_t*)(NULL));
		G_B4_1 = G_B2_1;
		goto IL_0029;
	}

IL_0024:
	{
		NullCheck(G_B3_0);
		String_t* L_6;
		L_6 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, G_B3_0);
		G_B4_0 = L_6;
		G_B4_1 = G_B3_1;
	}

IL_0029:
	{
		String_t* L_7;
		L_7 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(G_B4_1, G_B4_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		Log_Error_m2BCA24D454AF5A5E27541D7E21326D478C9BDE0B(L_7, _stringLiteralCDF1157616009A2B26E7D53D070334F4188B9624, _stringLiteralC6387E9C5A822DD5AA6EEBF9DF80A690DBC81B7E, ((int32_t)91), NULL);
		// return false;
		V_2 = (bool)0;
		goto IL_007e;
	}

IL_0044:
	{
		// Log.Debug("_CloseUI " + type);
		Type_t* L_8 = ___0_type;
		Type_t* L_9 = L_8;
		G_B6_0 = L_9;
		G_B6_1 = _stringLiteralABEA19C219C733FF3FE45E06F0F298F769041ABD;
		if (L_9)
		{
			G_B7_0 = L_9;
			G_B7_1 = _stringLiteralABEA19C219C733FF3FE45E06F0F298F769041ABD;
			goto IL_0051;
		}
	}
	{
		G_B8_0 = ((String_t*)(NULL));
		G_B8_1 = G_B6_1;
		goto IL_0056;
	}

IL_0051:
	{
		NullCheck(G_B7_0);
		String_t* L_10;
		L_10 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, G_B7_0);
		G_B8_0 = L_10;
		G_B8_1 = G_B7_1;
	}

IL_0056:
	{
		String_t* L_11;
		L_11 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(G_B8_1, G_B8_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		Log_Debug_mBC6B7CAF0E12CB5777FB8FAAE59289CCDAED17A2(L_11, _stringLiteralCDF1157616009A2B26E7D53D070334F4188B9624, _stringLiteralC6387E9C5A822DD5AA6EEBF9DF80A690DBC81B7E, ((int32_t)95), NULL);
		// page.Group.Close(type);
		UIPage_t3EBB2C365895C991E142AF9F8C09DABCA1E47387* L_12 = V_0;
		NullCheck(L_12);
		UIGroup_tC217247301A179C554813A009381C0404ECC1DDF* L_13;
		L_13 = UIPage_get_Group_m1553A3E497FCF802E7EB13649C50DE62EF308F12(L_12, NULL);
		Type_t* L_14 = ___0_type;
		NullCheck(L_13);
		UIGroup_Close_m40933FE144C6A4E765D2944639734A2068952E39(L_13, L_14, NULL);
		// return true;
		V_2 = (bool)1;
		goto IL_007e;
	}

IL_007e:
	{
		// }
		bool L_15 = V_2;
		return L_15;
	}
}
// System.Void com.picoxr.tobframwork.UIPageManager::Close(System.Type)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIPageManager_Close_mEBB5FCBE4D27BE856B8D78C73AA2DF70D84E7BE5 (Type_t* ___0_type, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// _instance._CloseUI(type);
		UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B* L_0 = ((UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B_StaticFields*)il2cpp_codegen_static_fields_for(UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B_il2cpp_TypeInfo_var))->____instance_5;
		Type_t* L_1 = ___0_type;
		NullCheck(L_0);
		bool L_2;
		L_2 = UIPageManager__CloseUI_m9AF9FCA67ECF7C6FDD2C9E2C7250787C1094FF51(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void com.picoxr.tobframwork.UIPageManager::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIPageManager__ctor_m9809AED166DC6374CAFBA9857D42E4050B491813 (UIPageManager_tA009FE0BF1C5B8A253B00CECB2BBCA402CF6C75B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_m94EDCF44D203BF48FDAEAEB36F5DB4BF67E17CAA_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_t1BF400F50D50E19CF6FCD3FF520384A96269F89F_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private Dictionary<Type, UIPage> _cachePage = new Dictionary<Type, UIPage>();
		Dictionary_2_t1BF400F50D50E19CF6FCD3FF520384A96269F89F* L_0 = (Dictionary_2_t1BF400F50D50E19CF6FCD3FF520384A96269F89F*)il2cpp_codegen_object_new(Dictionary_2_t1BF400F50D50E19CF6FCD3FF520384A96269F89F_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Dictionary_2__ctor_m94EDCF44D203BF48FDAEAEB36F5DB4BF67E17CAA(L_0, Dictionary_2__ctor_m94EDCF44D203BF48FDAEAEB36F5DB4BF67E17CAA_RuntimeMethod_var);
		__this->____cachePage_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____cachePage_4), (void*)L_0);
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.String com.picoxr.tobframwork.LanguageUtils::GetRichContent(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* LanguageUtils_GetRichContent_m0292342ECFA9E84E2D3A07A496E7091F8CDE2300 (String_t* ___0_key, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&LocalizationTool_t7DBF16B905FAD36B32A980793330018B6CFC44A2_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	{
		// return LocalizationTool.GetContentWithUnicodeSpace(key);
		String_t* L_0 = ___0_key;
		il2cpp_codegen_runtime_class_init_inline(LocalizationTool_t7DBF16B905FAD36B32A980793330018B6CFC44A2_il2cpp_TypeInfo_var);
		String_t* L_1;
		L_1 = LocalizationTool_GetContentWithUnicodeSpace_m0B2266E7D68CD9D2CC0B4B43A0A82692C07CCD01(L_0, NULL);
		V_0 = L_1;
		goto IL_000a;
	}

IL_000a:
	{
		// }
		String_t* L_2 = V_0;
		return L_2;
	}
}
// System.String com.picoxr.tobframwork.LanguageUtils::GetRichContent(System.String,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* LanguageUtils_GetRichContent_m948660D60F54E21C3A7DE05F93A2E992B43CE84E (String_t* ___0_key, int32_t ___1_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&LocalizationTool_t7DBF16B905FAD36B32A980793330018B6CFC44A2_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ef__AnonymousType0_1__ctor_mF4E4C5F9CD02AEAF4F890E22441AE2B516285AB6_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ef__AnonymousType0_1_tCC81029179B6F4DAC7D8BC271C35F5CDBC097D55_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC368529EFBEDA8057918D749B143C32B739CE4A9);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	String_t* V_1 = NULL;
	String_t* V_2 = NULL;
	{
		// string content = LocalizationTool.GetContentWithUnicodeSpace(key);
		String_t* L_0 = ___0_key;
		il2cpp_codegen_runtime_class_init_inline(LocalizationTool_t7DBF16B905FAD36B32A980793330018B6CFC44A2_il2cpp_TypeInfo_var);
		String_t* L_1;
		L_1 = LocalizationTool_GetContentWithUnicodeSpace_m0B2266E7D68CD9D2CC0B4B43A0A82692C07CCD01(L_0, NULL);
		V_0 = L_1;
		// string result = _messageFormatter.FormatMessage(content, new { num = value });
		il2cpp_codegen_runtime_class_init_inline(LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_il2cpp_TypeInfo_var);
		MessageFormatter_t59AB4D9D22B9B2403C45FF755A0AB60223D2035F* L_2 = ((LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_StaticFields*)il2cpp_codegen_static_fields_for(LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_il2cpp_TypeInfo_var))->____messageFormatter_1;
		String_t* L_3 = V_0;
		int32_t L_4 = ___1_value;
		U3CU3Ef__AnonymousType0_1_tCC81029179B6F4DAC7D8BC271C35F5CDBC097D55* L_5 = (U3CU3Ef__AnonymousType0_1_tCC81029179B6F4DAC7D8BC271C35F5CDBC097D55*)il2cpp_codegen_object_new(U3CU3Ef__AnonymousType0_1_tCC81029179B6F4DAC7D8BC271C35F5CDBC097D55_il2cpp_TypeInfo_var);
		NullCheck(L_5);
		U3CU3Ef__AnonymousType0_1__ctor_mF4E4C5F9CD02AEAF4F890E22441AE2B516285AB6(L_5, L_4, U3CU3Ef__AnonymousType0_1__ctor_mF4E4C5F9CD02AEAF4F890E22441AE2B516285AB6_RuntimeMethod_var);
		String_t* L_6;
		L_6 = MessageFormatterExtensions_FormatMessage_mAF75489D52D425037E9E600B4A0F67755E00AFA1(L_2, L_3, L_5, NULL);
		V_1 = L_6;
		// result = result.Replace("%d", value.ToString());
		String_t* L_7 = V_1;
		String_t* L_8;
		L_8 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&___1_value), NULL);
		NullCheck(L_7);
		String_t* L_9;
		L_9 = String_Replace_mABDB7003A1D0AEDCAE9FF85E3DFFFBA752D2A166(L_7, _stringLiteralC368529EFBEDA8057918D749B143C32B739CE4A9, L_8, NULL);
		V_1 = L_9;
		// return result;
		String_t* L_10 = V_1;
		V_2 = L_10;
		goto IL_0031;
	}

IL_0031:
	{
		// }
		String_t* L_11 = V_2;
		return L_11;
	}
}
// System.String com.picoxr.tobframwork.LanguageUtils::GetRichContent(System.String,System.Int32[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* LanguageUtils_GetRichContent_m7B25E753810509B8AEAE02D0F8B85D0A9081B399 (String_t* ___0_key, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___1_intArr, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	{
		// return GetRichContent(key, intArr, null);
		String_t* L_0 = ___0_key;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = ___1_intArr;
		il2cpp_codegen_runtime_class_init_inline(LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_il2cpp_TypeInfo_var);
		String_t* L_2;
		L_2 = LanguageUtils_GetRichContent_m373FE4083C1BF7653F390A8952C31FB1C4027A79(L_0, L_1, (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)NULL, NULL);
		V_0 = L_2;
		goto IL_000c;
	}

IL_000c:
	{
		// }
		String_t* L_3 = V_0;
		return L_3;
	}
}
// System.String com.picoxr.tobframwork.LanguageUtils::GetRichContent(System.String,System.Int32[],System.String[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* LanguageUtils_GetRichContent_m373FE4083C1BF7653F390A8952C31FB1C4027A79 (String_t* ___0_key, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___1_intArr, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___2_stringArr, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&LocalizationTool_t7DBF16B905FAD36B32A980793330018B6CFC44A2_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	String_t* V_1 = NULL;
	{
		// string content = LocalizationTool.GetContentWithUnicodeSpace(key);
		String_t* L_0 = ___0_key;
		il2cpp_codegen_runtime_class_init_inline(LocalizationTool_t7DBF16B905FAD36B32A980793330018B6CFC44A2_il2cpp_TypeInfo_var);
		String_t* L_1;
		L_1 = LocalizationTool_GetContentWithUnicodeSpace_m0B2266E7D68CD9D2CC0B4B43A0A82692C07CCD01(L_0, NULL);
		V_0 = L_1;
		// return Convert(content, intArr, stringArr);
		String_t* L_2 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = ___1_intArr;
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_4 = ___2_stringArr;
		il2cpp_codegen_runtime_class_init_inline(LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_il2cpp_TypeInfo_var);
		String_t* L_5;
		L_5 = LanguageUtils_Convert_m330A88108808D44309EC107E2D78BAED0E15AF1D(L_2, L_3, L_4, NULL);
		V_1 = L_5;
		goto IL_0013;
	}

IL_0013:
	{
		// }
		String_t* L_6 = V_1;
		return L_6;
	}
}
// System.String com.picoxr.tobframwork.LanguageUtils::Convert(System.String,System.Int32[],System.String[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* LanguageUtils_Convert_m330A88108808D44309EC107E2D78BAED0E15AF1D (String_t* ___0_content, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___1_intArr, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___2_stringArr, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	bool V_2 = false;
	int32_t V_3 = 0;
	String_t* V_4 = NULL;
	bool V_5 = false;
	bool V_6 = false;
	Il2CppChar V_7 = 0x0;
	Il2CppChar V_8 = 0x0;
	bool V_9 = false;
	bool V_10 = false;
	bool V_11 = false;
	bool V_12 = false;
	Exception_t* V_13 = NULL;
	String_t* V_14 = NULL;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	int32_t G_B12_0 = 0;
	int32_t G_B18_0 = 0;
	{
		// strBuilder.Clear();
		il2cpp_codegen_runtime_class_init_inline(LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_il2cpp_TypeInfo_var);
		StringBuilder_t* L_0 = ((LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_StaticFields*)il2cpp_codegen_static_fields_for(LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_il2cpp_TypeInfo_var))->___strBuilder_0;
		NullCheck(L_0);
		StringBuilder_t* L_1;
		L_1 = StringBuilder_Clear_m2D76F6533574F40A4E3E2DC4E730277CBD0AF8F6(L_0, NULL);
		// int intIndex = 0;
		V_0 = 0;
		// int stringIndex = 0;
		V_1 = 0;
		// bool has = false;
		V_2 = (bool)0;
	}
	try
	{// begin try (depth: 1)
		{
			// for (int i = 0; i < content.Length; i++)
			V_3 = 0;
			goto IL_00f0_1;
		}

IL_001a_1:
		{
			// string value = "";
			V_4 = _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709;
			// has = false;
			V_2 = (bool)0;
			// if (content[i] == '%')
			String_t* L_2 = ___0_content;
			int32_t L_3 = V_3;
			NullCheck(L_2);
			Il2CppChar L_4;
			L_4 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_2, L_3, NULL);
			V_5 = (bool)((((int32_t)L_4) == ((int32_t)((int32_t)37)))? 1 : 0);
			bool L_5 = V_5;
			if (!L_5)
			{
				goto IL_00d9_1;
			}
		}
		{
			// if (i + 1 >= content.Length)
			int32_t L_6 = V_3;
			String_t* L_7 = ___0_content;
			NullCheck(L_7);
			int32_t L_8;
			L_8 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_7, NULL);
			V_6 = (bool)((((int32_t)((((int32_t)((int32_t)il2cpp_codegen_add(L_6, 1))) < ((int32_t)L_8))? 1 : 0)) == ((int32_t)0))? 1 : 0);
			bool L_9 = V_6;
			if (!L_9)
			{
				goto IL_0053_1;
			}
		}
		{
			// break;
			goto IL_0102_1;
		}

IL_0053_1:
		{
			// switch (content[i + 1])
			String_t* L_10 = ___0_content;
			int32_t L_11 = V_3;
			NullCheck(L_10);
			Il2CppChar L_12;
			L_12 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_10, ((int32_t)il2cpp_codegen_add(L_11, 1)), NULL);
			V_8 = L_12;
			Il2CppChar L_13 = V_8;
			V_7 = L_13;
			Il2CppChar L_14 = V_7;
			if ((((int32_t)L_14) == ((int32_t)((int32_t)100))))
			{
				goto IL_0072_1;
			}
		}
		{
			goto IL_006a_1;
		}

IL_006a_1:
		{
			Il2CppChar L_15 = V_7;
			if ((((int32_t)L_15) == ((int32_t)((int32_t)115))))
			{
				goto IL_009c_1;
			}
		}
		{
			goto IL_00bd_1;
		}

IL_0072_1:
		{
			// if (intArr != null && intIndex < intArr.Length)
			Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_16 = ___1_intArr;
			if (!L_16)
			{
				goto IL_007d_1;
			}
		}
		{
			int32_t L_17 = V_0;
			Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_18 = ___1_intArr;
			NullCheck(L_18);
			G_B12_0 = ((((int32_t)L_17) < ((int32_t)((int32_t)(((RuntimeArray*)L_18)->max_length))))? 1 : 0);
			goto IL_007e_1;
		}

IL_007d_1:
		{
			G_B12_0 = 0;
		}

IL_007e_1:
		{
			V_9 = (bool)G_B12_0;
			bool L_19 = V_9;
			if (!L_19)
			{
				goto IL_009a_1;
			}
		}
		{
			// value = intArr[intIndex].ToString();
			Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_20 = ___1_intArr;
			int32_t L_21 = V_0;
			NullCheck(L_20);
			String_t* L_22;
			L_22 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5(((L_20)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_21))), NULL);
			V_4 = L_22;
			// intIndex++;
			int32_t L_23 = V_0;
			V_0 = ((int32_t)il2cpp_codegen_add(L_23, 1));
			// has = true;
			V_2 = (bool)1;
		}

IL_009a_1:
		{
			// break;
			goto IL_00bd_1;
		}

IL_009c_1:
		{
			// if (stringArr != null && stringIndex < stringArr.Length)
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_24 = ___2_stringArr;
			if (!L_24)
			{
				goto IL_00a7_1;
			}
		}
		{
			int32_t L_25 = V_1;
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_26 = ___2_stringArr;
			NullCheck(L_26);
			G_B18_0 = ((((int32_t)L_25) < ((int32_t)((int32_t)(((RuntimeArray*)L_26)->max_length))))? 1 : 0);
			goto IL_00a8_1;
		}

IL_00a7_1:
		{
			G_B18_0 = 0;
		}

IL_00a8_1:
		{
			V_10 = (bool)G_B18_0;
			bool L_27 = V_10;
			if (!L_27)
			{
				goto IL_00bb_1;
			}
		}
		{
			// value = stringArr[stringIndex];
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_28 = ___2_stringArr;
			int32_t L_29 = V_1;
			NullCheck(L_28);
			int32_t L_30 = L_29;
			String_t* L_31 = (L_28)->GetAt(static_cast<il2cpp_array_size_t>(L_30));
			V_4 = L_31;
			// stringIndex++;
			int32_t L_32 = V_1;
			V_1 = ((int32_t)il2cpp_codegen_add(L_32, 1));
			// has = true;
			V_2 = (bool)1;
		}

IL_00bb_1:
		{
			// break;
			goto IL_00bd_1;
		}

IL_00bd_1:
		{
			// if (has)
			bool L_33 = V_2;
			V_11 = L_33;
			bool L_34 = V_11;
			if (!L_34)
			{
				goto IL_00d8_1;
			}
		}
		{
			// strBuilder.Append(value);
			il2cpp_codegen_runtime_class_init_inline(LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_il2cpp_TypeInfo_var);
			StringBuilder_t* L_35 = ((LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_StaticFields*)il2cpp_codegen_static_fields_for(LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_il2cpp_TypeInfo_var))->___strBuilder_0;
			String_t* L_36 = V_4;
			NullCheck(L_35);
			StringBuilder_t* L_37;
			L_37 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_35, L_36, NULL);
			// i++;
			int32_t L_38 = V_3;
			V_3 = ((int32_t)il2cpp_codegen_add(L_38, 1));
			// continue;
			goto IL_00ec_1;
		}

IL_00d8_1:
		{
		}

IL_00d9_1:
		{
			// strBuilder.Append(content[i]);
			il2cpp_codegen_runtime_class_init_inline(LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_il2cpp_TypeInfo_var);
			StringBuilder_t* L_39 = ((LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_StaticFields*)il2cpp_codegen_static_fields_for(LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_il2cpp_TypeInfo_var))->___strBuilder_0;
			String_t* L_40 = ___0_content;
			int32_t L_41 = V_3;
			NullCheck(L_40);
			Il2CppChar L_42;
			L_42 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_40, L_41, NULL);
			NullCheck(L_39);
			StringBuilder_t* L_43;
			L_43 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_39, L_42, NULL);
		}

IL_00ec_1:
		{
			// for (int i = 0; i < content.Length; i++)
			int32_t L_44 = V_3;
			V_3 = ((int32_t)il2cpp_codegen_add(L_44, 1));
		}

IL_00f0_1:
		{
			// for (int i = 0; i < content.Length; i++)
			int32_t L_45 = V_3;
			String_t* L_46 = ___0_content;
			NullCheck(L_46);
			int32_t L_47;
			L_47 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_46, NULL);
			V_12 = (bool)((((int32_t)L_45) < ((int32_t)L_47))? 1 : 0);
			bool L_48 = V_12;
			if (L_48)
			{
				goto IL_001a_1;
			}
		}

IL_0102_1:
		{
			goto IL_0124;
		}
	}// end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0105;
		}
		throw e;
	}

CATCH_0105:
	{// begin catch(System.Exception)
		Exception_t* L_49 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		// catch (Exception e)
		V_13 = L_49;
		// Log.Error(e.ToString());
		Exception_t* L_50 = V_13;
		NullCheck(L_50);
		String_t* L_51;
		L_51 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_50);
		il2cpp_codegen_runtime_class_init_inline(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var)));
		Log_Error_m2BCA24D454AF5A5E27541D7E21326D478C9BDE0B(L_51, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral6DE8DD1886BBF05CE4638B678071D70F7A706931)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralEFC88795E0479464AC4E9B8B031D9720CE94E3C5)), ((int32_t)97), NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0124;
	}// end catch (depth: 1)

IL_0124:
	{
		// return strBuilder.ToString();
		il2cpp_codegen_runtime_class_init_inline(LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_il2cpp_TypeInfo_var);
		StringBuilder_t* L_52 = ((LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_StaticFields*)il2cpp_codegen_static_fields_for(LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_il2cpp_TypeInfo_var))->___strBuilder_0;
		NullCheck(L_52);
		String_t* L_53;
		L_53 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_52);
		V_14 = L_53;
		goto IL_0132;
	}

IL_0132:
	{
		// }
		String_t* L_54 = V_14;
		return L_54;
	}
}
// System.Void com.picoxr.tobframwork.LanguageUtils::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LanguageUtils__ctor_m3EA924D7D312668525D8719ECA51ED581ED3AD64 (LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
// System.Void com.picoxr.tobframwork.LanguageUtils::.cctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LanguageUtils__cctor_m01E263A5F0FBC920BAE8BC74EADBB6B1B553A34E (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageFormatter_t59AB4D9D22B9B2403C45FF755A0AB60223D2035F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC6DE535D828F30C374EB3BE3FFDE520228FC3096);
		s_Il2CppMethodInitialized = true;
	}
	{
		// static StringBuilder strBuilder = new StringBuilder();
		StringBuilder_t* L_0 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D(L_0, NULL);
		((LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_StaticFields*)il2cpp_codegen_static_fields_for(LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_il2cpp_TypeInfo_var))->___strBuilder_0 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_StaticFields*)il2cpp_codegen_static_fields_for(LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_il2cpp_TypeInfo_var))->___strBuilder_0), (void*)L_0);
		// static MessageFormatter _messageFormatter = new MessageFormatter();
		MessageFormatter_t59AB4D9D22B9B2403C45FF755A0AB60223D2035F* L_1 = (MessageFormatter_t59AB4D9D22B9B2403C45FF755A0AB60223D2035F*)il2cpp_codegen_object_new(MessageFormatter_t59AB4D9D22B9B2403C45FF755A0AB60223D2035F_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		MessageFormatter__ctor_mE163C7425D7EE65EBE62E161CA9FF363C9E8784E(L_1, (bool)1, _stringLiteralC6DE535D828F30C374EB3BE3FFDE520228FC3096, (CustomValueFormatter_tBD981B5F72D8EADB8B6258BE76BEBEE7EF2403AC*)NULL, NULL);
		((LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_StaticFields*)il2cpp_codegen_static_fields_for(LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_il2cpp_TypeInfo_var))->____messageFormatter_1 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&((LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_StaticFields*)il2cpp_codegen_static_fields_for(LanguageUtils_tEAAAD044913BACB4099EE0FE20D5E58A77ED855D_il2cpp_TypeInfo_var))->____messageFormatter_1), (void*)L_1);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void com.picoxr.tobframwork.Timer::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Timer_Update_m53EB50DA5A944875D62C84B99BDC844C2177092E (Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_GetEnumerator_m270AF704B3913CD85D83DD9FFF33D86EFEA32AFF_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Remove_mD553250DE5E74AB751576D4DFA330B74162C8926_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_get_Item_mD9FD66064367BDD11E0CBCA5D45B14FCFE58DD57_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_MoveNext_m7E56A8F9E76BB0BBBB349B08ED376B19C973EF53_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_get_Current_mA55505E5DED43F682FF4A841E7E1B29506D44D22_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&KeyValuePair_2_get_Value_mE69B7D19A7BC4B402D3F61148E96B3509CB69FAC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAA50EFD5EEC9735C47DD68C4CC4DEB3CCFE01C98_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_RemoveAt_m76C4CDACF47BA529BAFADFC8D5E13DB9587F4004_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_RemoveAt_mD9D3FCCCEBDF9E17EEE5A8CB0656F195F585AD3D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_m8CE395B93EA7127861F983E3C2FE02E08A41D42E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_mF590592E32D421DE2C6E2F0D5C2F62FB14CCEFDF_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Item_m9BC9267741CE11FCC731D1D0F6E98A08295D2545_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Item_mD99081BEFA1AB3526715F489192B0F7F596C183D_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	Enumerator_t2EE140C33897AA9EA14EF9B66B7AA963EEB1E888 V_0;
	memset((&V_0), 0, sizeof(V_0));
	Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* V_1 = NULL;
	KeyValuePair_2_t7D5F51FBC6FB4B34CCA91B6881B1DCFDCCEEE2B3 V_2;
	memset((&V_2), 0, sizeof(V_2));
	bool V_3 = false;
	bool V_4 = false;
	bool V_5 = false;
	bool V_6 = false;
	bool V_7 = false;
	bool V_8 = false;
	Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* V_9 = NULL;
	bool V_10 = false;
	int32_t V_11 = 0;
	bool V_12 = false;
	{
		// for (var e = _handles.GetEnumerator(); e.MoveNext();)
		Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6* L_0 = __this->____handles_4;
		NullCheck(L_0);
		Enumerator_t2EE140C33897AA9EA14EF9B66B7AA963EEB1E888 L_1;
		L_1 = Dictionary_2_GetEnumerator_m270AF704B3913CD85D83DD9FFF33D86EFEA32AFF(L_0, Dictionary_2_GetEnumerator_m270AF704B3913CD85D83DD9FFF33D86EFEA32AFF_RuntimeMethod_var);
		V_0 = L_1;
		goto IL_00e1;
	}

IL_0012:
	{
		// Handle handle = e.Current.Value as Handle;
		KeyValuePair_2_t7D5F51FBC6FB4B34CCA91B6881B1DCFDCCEEE2B3 L_2;
		L_2 = Enumerator_get_Current_mA55505E5DED43F682FF4A841E7E1B29506D44D22_inline((&V_0), Enumerator_get_Current_mA55505E5DED43F682FF4A841E7E1B29506D44D22_RuntimeMethod_var);
		V_2 = L_2;
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_3;
		L_3 = KeyValuePair_2_get_Value_mE69B7D19A7BC4B402D3F61148E96B3509CB69FAC_inline((&V_2), KeyValuePair_2_get_Value_mE69B7D19A7BC4B402D3F61148E96B3509CB69FAC_RuntimeMethod_var);
		V_1 = L_3;
		// if (handle.LastCallTime < handle.StartTime)
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_4 = V_1;
		NullCheck(L_4);
		float L_5 = L_4->___LastCallTime_5;
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_6 = V_1;
		NullCheck(L_6);
		float L_7 = L_6->___StartTime_0;
		V_3 = (bool)((((float)L_5) < ((float)L_7))? 1 : 0);
		bool L_8 = V_3;
		if (!L_8)
		{
			goto IL_0097;
		}
	}
	{
		// if (Time.time - handle.StartTime > handle.Delay)
		float L_9;
		L_9 = Time_get_time_m3A271BB1B20041144AC5B7863B71AB1F0150374B(NULL);
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_10 = V_1;
		NullCheck(L_10);
		float L_11 = L_10->___StartTime_0;
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_12 = V_1;
		NullCheck(L_12);
		float L_13 = L_12->___Delay_1;
		V_4 = (bool)((((float)((float)il2cpp_codegen_subtract(L_9, L_11))) > ((float)L_13))? 1 : 0);
		bool L_14 = V_4;
		if (!L_14)
		{
			goto IL_0094;
		}
	}
	{
		// handle.LastCallTime = Time.time;
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_15 = V_1;
		float L_16;
		L_16 = Time_get_time_m3A271BB1B20041144AC5B7863B71AB1F0150374B(NULL);
		NullCheck(L_15);
		L_15->___LastCallTime_5 = L_16;
		// _waitingToCall.Add(handle);
		List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5* L_17 = __this->____waitingToCall_7;
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_18 = V_1;
		NullCheck(L_17);
		List_1_Add_mAA50EFD5EEC9735C47DD68C4CC4DEB3CCFE01C98_inline(L_17, L_18, List_1_Add_mAA50EFD5EEC9735C47DD68C4CC4DEB3CCFE01C98_RuntimeMethod_var);
		// if (handle.RepeatRate <= 0)
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_19 = V_1;
		NullCheck(L_19);
		float L_20 = L_19->___RepeatRate_2;
		V_5 = (bool)((((int32_t)((!(((float)L_20) <= ((float)(0.0f))))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_21 = V_5;
		if (!L_21)
		{
			goto IL_0093;
		}
	}
	{
		// _waitingToRemove.Add(handle.ID);
		List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_22 = __this->____waitingToRemove_6;
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_23 = V_1;
		NullCheck(L_23);
		int32_t L_24 = L_23->___ID_4;
		NullCheck(L_22);
		List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_inline(L_22, L_24, List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_RuntimeMethod_var);
	}

IL_0093:
	{
	}

IL_0094:
	{
		goto IL_00e0;
	}

IL_0097:
	{
		// else if (handle.RepeatRate > 0)
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_25 = V_1;
		NullCheck(L_25);
		float L_26 = L_25->___RepeatRate_2;
		V_6 = (bool)((((float)L_26) > ((float)(0.0f)))? 1 : 0);
		bool L_27 = V_6;
		if (!L_27)
		{
			goto IL_00e0;
		}
	}
	{
		// if (Time.time - handle.LastCallTime > handle.RepeatRate)
		float L_28;
		L_28 = Time_get_time_m3A271BB1B20041144AC5B7863B71AB1F0150374B(NULL);
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_29 = V_1;
		NullCheck(L_29);
		float L_30 = L_29->___LastCallTime_5;
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_31 = V_1;
		NullCheck(L_31);
		float L_32 = L_31->___RepeatRate_2;
		V_7 = (bool)((((float)((float)il2cpp_codegen_subtract(L_28, L_30))) > ((float)L_32))? 1 : 0);
		bool L_33 = V_7;
		if (!L_33)
		{
			goto IL_00df;
		}
	}
	{
		// handle.LastCallTime = Time.time;
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_34 = V_1;
		float L_35;
		L_35 = Time_get_time_m3A271BB1B20041144AC5B7863B71AB1F0150374B(NULL);
		NullCheck(L_34);
		L_34->___LastCallTime_5 = L_35;
		// _waitingToCall.Add(handle);
		List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5* L_36 = __this->____waitingToCall_7;
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_37 = V_1;
		NullCheck(L_36);
		List_1_Add_mAA50EFD5EEC9735C47DD68C4CC4DEB3CCFE01C98_inline(L_36, L_37, List_1_Add_mAA50EFD5EEC9735C47DD68C4CC4DEB3CCFE01C98_RuntimeMethod_var);
	}

IL_00df:
	{
	}

IL_00e0:
	{
	}

IL_00e1:
	{
		// for (var e = _handles.GetEnumerator(); e.MoveNext();)
		bool L_38;
		L_38 = Enumerator_MoveNext_m7E56A8F9E76BB0BBBB349B08ED376B19C973EF53((&V_0), Enumerator_MoveNext_m7E56A8F9E76BB0BBBB349B08ED376B19C973EF53_RuntimeMethod_var);
		V_8 = L_38;
		bool L_39 = V_8;
		if (L_39)
		{
			goto IL_0012;
		}
	}
	{
		goto IL_0119;
	}

IL_00f3:
	{
		// Handle handle = _waitingToCall[0];
		List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5* L_40 = __this->____waitingToCall_7;
		NullCheck(L_40);
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_41;
		L_41 = List_1_get_Item_m9BC9267741CE11FCC731D1D0F6E98A08295D2545(L_40, 0, List_1_get_Item_m9BC9267741CE11FCC731D1D0F6E98A08295D2545_RuntimeMethod_var);
		V_9 = L_41;
		// _waitingToCall.RemoveAt(0);
		List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5* L_42 = __this->____waitingToCall_7;
		NullCheck(L_42);
		List_1_RemoveAt_mD9D3FCCCEBDF9E17EEE5A8CB0656F195F585AD3D(L_42, 0, List_1_RemoveAt_mD9D3FCCCEBDF9E17EEE5A8CB0656F195F585AD3D_RuntimeMethod_var);
		// HandleCall(handle);
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_43 = V_9;
		Timer_HandleCall_mC6CF5E4AEC98E4F69B95CCC8E385E43E6086758B(__this, L_43, NULL);
	}

IL_0119:
	{
		// while (_waitingToCall.Count > 0)
		List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5* L_44 = __this->____waitingToCall_7;
		NullCheck(L_44);
		int32_t L_45;
		L_45 = List_1_get_Count_m8CE395B93EA7127861F983E3C2FE02E08A41D42E_inline(L_44, List_1_get_Count_m8CE395B93EA7127861F983E3C2FE02E08A41D42E_RuntimeMethod_var);
		V_10 = (bool)((((int32_t)L_45) > ((int32_t)0))? 1 : 0);
		bool L_46 = V_10;
		if (L_46)
		{
			goto IL_00f3;
		}
	}
	{
		goto IL_0173;
	}

IL_012f:
	{
		// int id = _waitingToRemove[0];
		List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_47 = __this->____waitingToRemove_6;
		NullCheck(L_47);
		int32_t L_48;
		L_48 = List_1_get_Item_mD99081BEFA1AB3526715F489192B0F7F596C183D(L_47, 0, List_1_get_Item_mD99081BEFA1AB3526715F489192B0F7F596C183D_RuntimeMethod_var);
		V_11 = L_48;
		// _recyles.Add(_handles[id]);
		List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5* L_49 = __this->____recyles_5;
		Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6* L_50 = __this->____handles_4;
		int32_t L_51 = V_11;
		NullCheck(L_50);
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_52;
		L_52 = Dictionary_2_get_Item_mD9FD66064367BDD11E0CBCA5D45B14FCFE58DD57(L_50, L_51, Dictionary_2_get_Item_mD9FD66064367BDD11E0CBCA5D45B14FCFE58DD57_RuntimeMethod_var);
		NullCheck(L_49);
		List_1_Add_mAA50EFD5EEC9735C47DD68C4CC4DEB3CCFE01C98_inline(L_49, L_52, List_1_Add_mAA50EFD5EEC9735C47DD68C4CC4DEB3CCFE01C98_RuntimeMethod_var);
		// _handles.Remove(id);
		Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6* L_53 = __this->____handles_4;
		int32_t L_54 = V_11;
		NullCheck(L_53);
		bool L_55;
		L_55 = Dictionary_2_Remove_mD553250DE5E74AB751576D4DFA330B74162C8926(L_53, L_54, Dictionary_2_Remove_mD553250DE5E74AB751576D4DFA330B74162C8926_RuntimeMethod_var);
		// _waitingToRemove.RemoveAt(0);
		List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_56 = __this->____waitingToRemove_6;
		NullCheck(L_56);
		List_1_RemoveAt_m76C4CDACF47BA529BAFADFC8D5E13DB9587F4004(L_56, 0, List_1_RemoveAt_m76C4CDACF47BA529BAFADFC8D5E13DB9587F4004_RuntimeMethod_var);
	}

IL_0173:
	{
		// while (_waitingToRemove.Count > 0)
		List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_57 = __this->____waitingToRemove_6;
		NullCheck(L_57);
		int32_t L_58;
		L_58 = List_1_get_Count_mF590592E32D421DE2C6E2F0D5C2F62FB14CCEFDF_inline(L_57, List_1_get_Count_mF590592E32D421DE2C6E2F0D5C2F62FB14CCEFDF_RuntimeMethod_var);
		V_12 = (bool)((((int32_t)L_58) > ((int32_t)0))? 1 : 0);
		bool L_59 = V_12;
		if (L_59)
		{
			goto IL_012f;
		}
	}
	{
		// }
		return;
	}
}
// System.Void com.picoxr.tobframwork.Timer::HandleCall(com.picoxr.tobframwork.Timer/Handle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Timer_HandleCall_mC6CF5E4AEC98E4F69B95CCC8E385E43E6086758B (Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0* __this, Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* ___0_handle, const RuntimeMethod* method) 
{
	Exception_t* V_0 = NULL;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{// begin try (depth: 1)
		// handle.Call.Invoke();
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_0 = ___0_handle;
		NullCheck(L_0);
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_1 = L_0->___Call_3;
		NullCheck(L_1);
		Action_Invoke_m7126A54DACA72B845424072887B5F3A51FC3808E_inline(L_1, NULL);
		goto IL_002e;
	}// end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0011;
		}
		throw e;
	}

CATCH_0011:
	{// begin catch(System.Exception)
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		// catch (Exception exception)
		V_0 = L_2;
		// Log.Error(exception.ToString());
		Exception_t* L_3 = V_0;
		NullCheck(L_3);
		String_t* L_4;
		L_4 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_3);
		il2cpp_codegen_runtime_class_init_inline(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var)));
		Log_Error_m2BCA24D454AF5A5E27541D7E21326D478C9BDE0B(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral551354F804B6BDEA008C4C36F589CEC4A07FFD4A)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral587DC89F824CC86773888F46D34374A78EB6E433)), ((int32_t)94), NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002e;
	}// end catch (depth: 1)

IL_002e:
	{
		// }
		return;
	}
}
// System.Int32 com.picoxr.tobframwork.Timer::_Add(System.Single,System.Action,System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Timer__Add_mB1D79903C31073C6A171200E211C6EBC5571C554 (Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0* __this, float ___0_delay, Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___1_call, float ___2_repeatRate, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Add_m127CA9CF3BF949F685FC3BC47942C2EAB717A1B7_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_RemoveAt_mD9D3FCCCEBDF9E17EEE5A8CB0656F195F585AD3D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_m8CE395B93EA7127861F983E3C2FE02E08A41D42E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Item_m9BC9267741CE11FCC731D1D0F6E98A08295D2545_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* V_0 = NULL;
	bool V_1 = false;
	int32_t V_2 = 0;
	{
		// if (_recyles.Count > 0)
		List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5* L_0 = __this->____recyles_5;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = List_1_get_Count_m8CE395B93EA7127861F983E3C2FE02E08A41D42E_inline(L_0, List_1_get_Count_m8CE395B93EA7127861F983E3C2FE02E08A41D42E_RuntimeMethod_var);
		V_1 = (bool)((((int32_t)L_1) > ((int32_t)0))? 1 : 0);
		bool L_2 = V_1;
		if (!L_2)
		{
			goto IL_0031;
		}
	}
	{
		// handle = _recyles[0];
		List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5* L_3 = __this->____recyles_5;
		NullCheck(L_3);
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_4;
		L_4 = List_1_get_Item_m9BC9267741CE11FCC731D1D0F6E98A08295D2545(L_3, 0, List_1_get_Item_m9BC9267741CE11FCC731D1D0F6E98A08295D2545_RuntimeMethod_var);
		V_0 = L_4;
		// _recyles.RemoveAt(0);
		List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5* L_5 = __this->____recyles_5;
		NullCheck(L_5);
		List_1_RemoveAt_mD9D3FCCCEBDF9E17EEE5A8CB0656F195F585AD3D(L_5, 0, List_1_RemoveAt_mD9D3FCCCEBDF9E17EEE5A8CB0656F195F585AD3D_RuntimeMethod_var);
		goto IL_0039;
	}

IL_0031:
	{
		// handle = new Handle();
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_6 = (Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5*)il2cpp_codegen_object_new(Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5_il2cpp_TypeInfo_var);
		NullCheck(L_6);
		Handle__ctor_mA693FB99957F5F22DA33083461F2EC356206301D(L_6, NULL);
		V_0 = L_6;
	}

IL_0039:
	{
		// handle.StartTime = Time.time;
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_7 = V_0;
		float L_8;
		L_8 = Time_get_time_m3A271BB1B20041144AC5B7863B71AB1F0150374B(NULL);
		NullCheck(L_7);
		L_7->___StartTime_0 = L_8;
		// handle.LastCallTime = 0;
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_9 = V_0;
		NullCheck(L_9);
		L_9->___LastCallTime_5 = (0.0f);
		// handle.Delay = delay;
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_10 = V_0;
		float L_11 = ___0_delay;
		NullCheck(L_10);
		L_10->___Delay_1 = L_11;
		// handle.Call = call;
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_12 = V_0;
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_13 = ___1_call;
		NullCheck(L_12);
		L_12->___Call_3 = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&L_12->___Call_3), (void*)L_13);
		// handle.RepeatRate = repeatRate;
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_14 = V_0;
		float L_15 = ___2_repeatRate;
		NullCheck(L_14);
		L_14->___RepeatRate_2 = L_15;
		// _handles.Add(handle.ID, handle);
		Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6* L_16 = __this->____handles_4;
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_17 = V_0;
		NullCheck(L_17);
		int32_t L_18 = L_17->___ID_4;
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_19 = V_0;
		NullCheck(L_16);
		Dictionary_2_Add_m127CA9CF3BF949F685FC3BC47942C2EAB717A1B7(L_16, L_18, L_19, Dictionary_2_Add_m127CA9CF3BF949F685FC3BC47942C2EAB717A1B7_RuntimeMethod_var);
		// return handle.ID;
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_20 = V_0;
		NullCheck(L_20);
		int32_t L_21 = L_20->___ID_4;
		V_2 = L_21;
		goto IL_0080;
	}

IL_0080:
	{
		// }
		int32_t L_22 = V_2;
		return L_22;
	}
}
// System.Void com.picoxr.tobframwork.Timer::_Remove(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Timer__Remove_m9C463D8653375AEB6390448C0FF02879B2A4D7A0 (Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0* __this, int32_t ___0_id, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Remove_mD553250DE5E74AB751576D4DFA330B74162C8926_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_TryGetValue_m347E8803DB0864154991F6FB10D201FD8D4D4AC3_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAA50EFD5EEC9735C47DD68C4CC4DEB3CCFE01C98_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* V_0 = NULL;
	bool V_1 = false;
	{
		// if (_handles.TryGetValue(id, out handle))
		Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6* L_0 = __this->____handles_4;
		int32_t L_1 = ___0_id;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_TryGetValue_m347E8803DB0864154991F6FB10D201FD8D4D4AC3(L_0, L_1, (&V_0), Dictionary_2_TryGetValue_m347E8803DB0864154991F6FB10D201FD8D4D4AC3_RuntimeMethod_var);
		V_1 = L_2;
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_002f;
		}
	}
	{
		// _handles.Remove(id);
		Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6* L_4 = __this->____handles_4;
		int32_t L_5 = ___0_id;
		NullCheck(L_4);
		bool L_6;
		L_6 = Dictionary_2_Remove_mD553250DE5E74AB751576D4DFA330B74162C8926(L_4, L_5, Dictionary_2_Remove_mD553250DE5E74AB751576D4DFA330B74162C8926_RuntimeMethod_var);
		// _recyles.Add(handle);
		List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5* L_7 = __this->____recyles_5;
		Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* L_8 = V_0;
		NullCheck(L_7);
		List_1_Add_mAA50EFD5EEC9735C47DD68C4CC4DEB3CCFE01C98_inline(L_7, L_8, List_1_Add_mAA50EFD5EEC9735C47DD68C4CC4DEB3CCFE01C98_RuntimeMethod_var);
	}

IL_002f:
	{
		// }
		return;
	}
}
// System.Int32 com.picoxr.tobframwork.Timer::Add(System.Single,System.Action)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Timer_Add_mCCDB5AD6858A30B530AB8FA0EE90BE1D19A3FA23 (float ___0_delay, Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___1_call, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		// return Add(delay, call, 0);
		float L_0 = ___0_delay;
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_1 = ___1_call;
		int32_t L_2;
		L_2 = Timer_Add_m60043B0A6BE292995EA3C4ACDA2B8B307231B23C(L_0, L_1, (0.0f), NULL);
		V_0 = L_2;
		goto IL_0010;
	}

IL_0010:
	{
		// }
		int32_t L_3 = V_0;
		return L_3;
	}
}
// System.Int32 com.picoxr.tobframwork.Timer::Add(System.Single,System.Action,System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Timer_Add_m60043B0A6BE292995EA3C4ACDA2B8B307231B23C (float ___0_delay, Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___1_call, float ___2_repeatRate, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		// return GetInstance()._Add(delay, call, repeatRate);
		Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0* L_0;
		L_0 = Timer_GetInstance_m3C9D320D4141D2F80D27913A6D149EB8057E2BB7(NULL);
		float L_1 = ___0_delay;
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_2 = ___1_call;
		float L_3 = ___2_repeatRate;
		NullCheck(L_0);
		int32_t L_4;
		L_4 = Timer__Add_mB1D79903C31073C6A171200E211C6EBC5571C554(L_0, L_1, L_2, L_3, NULL);
		V_0 = L_4;
		goto IL_0011;
	}

IL_0011:
	{
		// }
		int32_t L_5 = V_0;
		return L_5;
	}
}
// System.Void com.picoxr.tobframwork.Timer::Remove(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Timer_Remove_m5EA5375017A3E956DE9E5C697B8E6C8730D00123 (int32_t ___0_id, const RuntimeMethod* method) 
{
	{
		// GetInstance()._Remove(id);
		Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0* L_0;
		L_0 = Timer_GetInstance_m3C9D320D4141D2F80D27913A6D149EB8057E2BB7(NULL);
		int32_t L_1 = ___0_id;
		NullCheck(L_0);
		Timer__Remove_m9C463D8653375AEB6390448C0FF02879B2A4D7A0(L_0, L_1, NULL);
		// }
		return;
	}
}
// com.picoxr.tobframwork.Timer com.picoxr.tobframwork.Timer::GetInstance()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0* Timer_GetInstance_m3C9D320D4141D2F80D27913A6D149EB8057E2BB7 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_AddComponent_TisTimer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0_m66276B9B1490B3979BF93ED13478B3B3E58EA41C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* V_1 = NULL;
	Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0* V_2 = NULL;
	{
		// if (_instance == null)
		Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0* L_0 = ((Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0_StaticFields*)il2cpp_codegen_static_fields_for(Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0_il2cpp_TypeInfo_var))->____instance_8;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		V_0 = L_1;
		bool L_2 = V_0;
		if (!L_2)
		{
			goto IL_002a;
		}
	}
	{
		// GameObject obj = new GameObject();
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_3 = (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*)il2cpp_codegen_object_new(GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		GameObject__ctor_m7D0340DE160786E6EFA8DABD39EC3B694DA30AAD(L_3, NULL);
		V_1 = L_3;
		// _instance = obj.AddComponent<Timer>();
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_4 = V_1;
		NullCheck(L_4);
		Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0* L_5;
		L_5 = GameObject_AddComponent_TisTimer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0_m66276B9B1490B3979BF93ED13478B3B3E58EA41C(L_4, GameObject_AddComponent_TisTimer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0_m66276B9B1490B3979BF93ED13478B3B3E58EA41C_RuntimeMethod_var);
		((Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0_StaticFields*)il2cpp_codegen_static_fields_for(Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0_il2cpp_TypeInfo_var))->____instance_8 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&((Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0_StaticFields*)il2cpp_codegen_static_fields_for(Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0_il2cpp_TypeInfo_var))->____instance_8), (void*)L_5);
		// DontDestroyOnLoad(obj);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_6 = V_1;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		Object_DontDestroyOnLoad_m4B70C3AEF886C176543D1295507B6455C9DCAEA7(L_6, NULL);
	}

IL_002a:
	{
		// return _instance;
		Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0* L_7 = ((Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0_StaticFields*)il2cpp_codegen_static_fields_for(Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0_il2cpp_TypeInfo_var))->____instance_8;
		V_2 = L_7;
		goto IL_0032;
	}

IL_0032:
	{
		// }
		Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0* L_8 = V_2;
		return L_8;
	}
}
// System.Void com.picoxr.tobframwork.Timer::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Timer__ctor_mD89EF7C71B5EAC6CA780AF9269426EF5F863FC5C (Timer_tC3A41270C19AD44301C5B1154CB8C99E64B221A0* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_m1499CB733B03C3B63D06D1A01E35197AC21B59BD_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m17F501B5A5C289ECE1B4F3D6EBF05DFA421433F8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_mA02C96C46346D3D1952391F0E97ACFA08A59E206_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private Dictionary<int, Handle> _handles = new Dictionary<int, Handle>();
		Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6* L_0 = (Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6*)il2cpp_codegen_object_new(Dictionary_2_tCCC38EFCCDDDB3D4A6E392AA8429C9915520E3D6_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Dictionary_2__ctor_m1499CB733B03C3B63D06D1A01E35197AC21B59BD(L_0, Dictionary_2__ctor_m1499CB733B03C3B63D06D1A01E35197AC21B59BD_RuntimeMethod_var);
		__this->____handles_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____handles_4), (void*)L_0);
		// private List<Handle> _recyles = new List<Handle>();
		List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5* L_1 = (List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5*)il2cpp_codegen_object_new(List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		List_1__ctor_mA02C96C46346D3D1952391F0E97ACFA08A59E206(L_1, List_1__ctor_mA02C96C46346D3D1952391F0E97ACFA08A59E206_RuntimeMethod_var);
		__this->____recyles_5 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____recyles_5), (void*)L_1);
		// private List<int> _waitingToRemove = new List<int>();
		List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_2 = (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73*)il2cpp_codegen_object_new(List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		List_1__ctor_m17F501B5A5C289ECE1B4F3D6EBF05DFA421433F8(L_2, List_1__ctor_m17F501B5A5C289ECE1B4F3D6EBF05DFA421433F8_RuntimeMethod_var);
		__this->____waitingToRemove_6 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____waitingToRemove_6), (void*)L_2);
		// private List<Handle> _waitingToCall = new List<Handle>();
		List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5* L_3 = (List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5*)il2cpp_codegen_object_new(List_1_t6387D73F8231956D0330B4D24D9809552DB7CDA5_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		List_1__ctor_mA02C96C46346D3D1952391F0E97ACFA08A59E206(L_3, List_1__ctor_mA02C96C46346D3D1952391F0E97ACFA08A59E206_RuntimeMethod_var);
		__this->____waitingToCall_7 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____waitingToCall_7), (void*)L_3);
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void com.picoxr.tobframwork.Timer/Handle::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Handle__ctor_mA693FB99957F5F22DA33083461F2EC356206301D (Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	{
		// public Handle()
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// ID = _id++;
		int32_t L_0 = ((Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5_StaticFields*)il2cpp_codegen_static_fields_for(Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5_il2cpp_TypeInfo_var))->____id_6;
		int32_t L_1 = L_0;
		((Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5_StaticFields*)il2cpp_codegen_static_fields_for(Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5_il2cpp_TypeInfo_var))->____id_6 = ((int32_t)il2cpp_codegen_add(L_1, 1));
		__this->___ID_4 = L_1;
		// if (_id > int.MaxValue - 1)
		int32_t L_2 = ((Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5_StaticFields*)il2cpp_codegen_static_fields_for(Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5_il2cpp_TypeInfo_var))->____id_6;
		V_0 = (bool)((((int32_t)L_2) > ((int32_t)((int32_t)2147483646)))? 1 : 0);
		bool L_3 = V_0;
		if (!L_3)
		{
			goto IL_0033;
		}
	}
	{
		// _id = 0;
		((Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5_StaticFields*)il2cpp_codegen_static_fields_for(Handle_t37A328755C4678810F0ED412B0A37E17B4551AC5_il2cpp_TypeInfo_var))->____id_6 = 0;
	}

IL_0033:
	{
		// }
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Single com.picoxr.tobframwork.Unitls::AngleAbsIn180(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Unitls_AngleAbsIn180_mF2A0D221B702D47CCF163508DBB466D76BD63CAE (float ___0_angle, const RuntimeMethod* method) 
{
	bool V_0 = false;
	bool V_1 = false;
	float V_2 = 0.0f;
	{
		// if (angle < 0)
		float L_0 = ___0_angle;
		V_0 = (bool)((((float)L_0) < ((float)(0.0f)))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		// angle *= -1;
		float L_2 = ___0_angle;
		___0_angle = ((float)il2cpp_codegen_multiply(L_2, (-1.0f)));
	}

IL_0018:
	{
		// angle %= 360;
		float L_3 = ___0_angle;
		___0_angle = (fmodf(L_3, (360.0f)));
		// if (angle > 180)
		float L_4 = ___0_angle;
		V_1 = (bool)((((float)L_4) > ((float)(180.0f)))? 1 : 0);
		bool L_5 = V_1;
		if (!L_5)
		{
			goto IL_0038;
		}
	}
	{
		// angle = 360 - angle;
		float L_6 = ___0_angle;
		___0_angle = ((float)il2cpp_codegen_subtract((360.0f), L_6));
	}

IL_0038:
	{
		// return angle;
		float L_7 = ___0_angle;
		V_2 = L_7;
		goto IL_003c;
	}

IL_003c:
	{
		// }
		float L_8 = V_2;
		return L_8;
	}
}
// UnityEngine.Vector3 com.picoxr.tobframwork.Unitls::AdjustEulerAngles(UnityEngine.Vector3)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Unitls_AdjustEulerAngles_mA3772539D466DCF42DF3692B69977BFFCF7A9B7A (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_angles, const RuntimeMethod* method) 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		// angles.x = AdjustAngle(angles.x);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ___0_angles;
		float L_1 = L_0.___x_2;
		float L_2;
		L_2 = Unitls_AdjustAngle_mB4C788AFA7BCB283EA20290DC2C67D0010B8FDAB(L_1, NULL);
		(&___0_angles)->___x_2 = L_2;
		// angles.y = AdjustAngle(angles.y);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_3 = ___0_angles;
		float L_4 = L_3.___y_3;
		float L_5;
		L_5 = Unitls_AdjustAngle_mB4C788AFA7BCB283EA20290DC2C67D0010B8FDAB(L_4, NULL);
		(&___0_angles)->___y_3 = L_5;
		// angles.z = AdjustAngle(angles.z);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_6 = ___0_angles;
		float L_7 = L_6.___z_4;
		float L_8;
		L_8 = Unitls_AdjustAngle_mB4C788AFA7BCB283EA20290DC2C67D0010B8FDAB(L_7, NULL);
		(&___0_angles)->___z_4 = L_8;
		// return angles;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_9 = ___0_angles;
		V_0 = L_9;
		goto IL_003b;
	}

IL_003b:
	{
		// }
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_10 = V_0;
		return L_10;
	}
}
// System.Single com.picoxr.tobframwork.Unitls::AdjustAngle(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Unitls_AdjustAngle_mB4C788AFA7BCB283EA20290DC2C67D0010B8FDAB (float ___0_angle, const RuntimeMethod* method) 
{
	bool V_0 = false;
	bool V_1 = false;
	float V_2 = 0.0f;
	{
		goto IL_000e;
	}

IL_0003:
	{
		// angle -= 360;
		float L_0 = ___0_angle;
		___0_angle = ((float)il2cpp_codegen_subtract(L_0, (360.0f)));
	}

IL_000e:
	{
		// while (angle > 180)
		float L_1 = ___0_angle;
		V_0 = (bool)((((float)L_1) > ((float)(180.0f)))? 1 : 0);
		bool L_2 = V_0;
		if (L_2)
		{
			goto IL_0003;
		}
	}
	{
		goto IL_0027;
	}

IL_001c:
	{
		// angle += 360;
		float L_3 = ___0_angle;
		___0_angle = ((float)il2cpp_codegen_add(L_3, (360.0f)));
	}

IL_0027:
	{
		// while (angle < -180)
		float L_4 = ___0_angle;
		V_1 = (bool)((((float)L_4) < ((float)(-180.0f)))? 1 : 0);
		bool L_5 = V_1;
		if (L_5)
		{
			goto IL_001c;
		}
	}
	{
		// return angle;
		float L_6 = ___0_angle;
		V_2 = L_6;
		goto IL_0037;
	}

IL_0037:
	{
		// }
		float L_7 = V_2;
		return L_7;
	}
}
// System.Void com.picoxr.tobframwork.Unitls::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unitls__ctor_mE1E950872B266B76CC1120298D27300DF6F2A7E1 (Unitls_t2BA1216F702C7798ED366C4C77A5148AE77216A8* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void com.picoxr.blsapce.SpatialTextureMain::Awake()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpatialTextureMain_Awake_m735B3B25413F1E8911074EC6161A2281367B3E91 (SpatialTextureMain_tA0B9AB4FB7C9920C93B5AEE43B3F12BFE42C57DB* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpatialTextureMain_OnBindEnterpriseService_mDF04F8002285E4188A4C78C9CF2F0E7C8BA0108B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpatialTextureMain_OnFocusStateAcquired_m09E08ECD14CE3ADE88B375D92B5B79023FE36719_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&System_t4255BA2E24C230336F7C003E6DD13B25588178DB_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// PXR_Manager.EnableVideoSeeThrough = true;
		PXR_Manager_set_EnableVideoSeeThrough_mD1A96A700204E54FEE73DC142A9824C18D1EB42B((bool)1, NULL);
		// PXR_Plugin.Boundary.UPxr_SetGuardianSystemDisable(true);
		int32_t L_0;
		L_0 = Boundary_UPxr_SetGuardianSystemDisable_m2E6F8683908119A5CA656628B58C953E2434EC4A((bool)1, NULL);
		// PXR_Enterprise.InitEnterpriseService();
		bool L_1;
		L_1 = PXR_Enterprise_InitEnterpriseService_mA5E6CD31F2D00D76CC0EA930E2B25FA61900B3A1((bool)0, NULL);
		// PXR_Plugin.Boundary.UPxr_ShutdownSdkGuardianSystem();
		int32_t L_2;
		L_2 = Boundary_UPxr_ShutdownSdkGuardianSystem_m9AEF2EED29C12800A56230E0EE7BABD0767BD751(NULL);
		// PXR_Enterprise.BindEnterpriseService(OnBindEnterpriseService);
		Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C* L_3 = (Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C*)il2cpp_codegen_object_new(Action_1_t10DCB0C07D0D3C565CEACADC80D1152B35A45F6C_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		Action_1__ctor_mA8C3AC97D1F076EA5D1D0C10CEE6BD3E94711501(L_3, __this, (intptr_t)((void*)SpatialTextureMain_OnBindEnterpriseService_mDF04F8002285E4188A4C78C9CF2F0E7C8BA0108B_RuntimeMethod_var), NULL);
		PXR_Enterprise_BindEnterpriseService_m5A5610A0983FB0CBEE2F0C2FD791F66FE3FB7F1B(L_3, NULL);
		// PXR_Plugin.System.FocusStateAcquired += OnFocusStateAcquired;
		il2cpp_codegen_runtime_class_init_inline(System_t4255BA2E24C230336F7C003E6DD13B25588178DB_il2cpp_TypeInfo_var);
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_4 = ((System_t4255BA2E24C230336F7C003E6DD13B25588178DB_StaticFields*)il2cpp_codegen_static_fields_for(System_t4255BA2E24C230336F7C003E6DD13B25588178DB_il2cpp_TypeInfo_var))->___FocusStateAcquired_1;
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_5 = (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)il2cpp_codegen_object_new(Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		NullCheck(L_5);
		Action__ctor_mBDC7B0B4A3F583B64C2896F01BDED360772F67DC(L_5, __this, (intptr_t)((void*)SpatialTextureMain_OnFocusStateAcquired_m09E08ECD14CE3ADE88B375D92B5B79023FE36719_RuntimeMethod_var), NULL);
		Delegate_t* L_6;
		L_6 = Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00(L_4, L_5, NULL);
		((System_t4255BA2E24C230336F7C003E6DD13B25588178DB_StaticFields*)il2cpp_codegen_static_fields_for(System_t4255BA2E24C230336F7C003E6DD13B25588178DB_il2cpp_TypeInfo_var))->___FocusStateAcquired_1 = ((Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)CastclassSealed((RuntimeObject*)L_6, Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var));
		Il2CppCodeGenWriteBarrier((void**)(&((System_t4255BA2E24C230336F7C003E6DD13B25588178DB_StaticFields*)il2cpp_codegen_static_fields_for(System_t4255BA2E24C230336F7C003E6DD13B25588178DB_il2cpp_TypeInfo_var))->___FocusStateAcquired_1), (void*)((Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)CastclassSealed((RuntimeObject*)L_6, Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var)));
		// }
		return;
	}
}
// System.Void com.picoxr.blsapce.SpatialTextureMain::OnBindEnterpriseService(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpatialTextureMain_OnBindEnterpriseService_mDF04F8002285E4188A4C78C9CF2F0E7C8BA0108B (SpatialTextureMain_tA0B9AB4FB7C9920C93B5AEE43B3F12BFE42C57DB* __this, bool ___0_bind, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral132195FDF8564E10AC7A2AFE7D2DB7C9BEA52DD2);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDD3558EBAC9E15A5DECBC18AA71DAD6DF0F7CE66);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE2E7949F16C14C19C531338CF881B2DF2F6F9052);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Log.Debug("--- PXR_Enterprise.BindEnterpriseService:" + bind);
		il2cpp_codegen_runtime_class_init_inline(Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_il2cpp_TypeInfo_var);
		String_t* L_0;
		L_0 = Boolean_ToString_m6646C8026B1DF381A1EE8CD13549175E9703CC63((&___0_bind), NULL);
		String_t* L_1;
		L_1 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteralDD3558EBAC9E15A5DECBC18AA71DAD6DF0F7CE66, L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		Log_Debug_mBC6B7CAF0E12CB5777FB8FAAE59289CCDAED17A2(L_1, _stringLiteral132195FDF8564E10AC7A2AFE7D2DB7C9BEA52DD2, _stringLiteralE2E7949F16C14C19C531338CF881B2DF2F6F9052, ((int32_t)30), NULL);
		// }
		return;
	}
}
// System.Void com.picoxr.blsapce.SpatialTextureMain::OnApplicationQuit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpatialTextureMain_OnApplicationQuit_m223854CDF740FA48881335321BB396191DEC3A06 (SpatialTextureMain_tA0B9AB4FB7C9920C93B5AEE43B3F12BFE42C57DB* __this, const RuntimeMethod* method) 
{
	{
		// PXR_Manager.EnableVideoSeeThrough = false;
		PXR_Manager_set_EnableVideoSeeThrough_mD1A96A700204E54FEE73DC142A9824C18D1EB42B((bool)0, NULL);
		// }
		return;
	}
}
// System.Void com.picoxr.blsapce.SpatialTextureMain::OnFocusStateAcquired()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpatialTextureMain_OnFocusStateAcquired_m09E08ECD14CE3ADE88B375D92B5B79023FE36719 (SpatialTextureMain_tA0B9AB4FB7C9920C93B5AEE43B3F12BFE42C57DB* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral132195FDF8564E10AC7A2AFE7D2DB7C9BEA52DD2);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral307E4E9ED9EDF0491BA858A2CD1BC00E65FFA257);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral47DAD2DC5D493BB0500F8358F87D18769C0769BA);
		s_Il2CppMethodInitialized = true;
	}
	{
		// PXR_Manager.EnableVideoSeeThrough = true;
		PXR_Manager_set_EnableVideoSeeThrough_mD1A96A700204E54FEE73DC142A9824C18D1EB42B((bool)1, NULL);
		// PXR_Plugin.Boundary.UPxr_SetGuardianSystemDisable(true);
		int32_t L_0;
		L_0 = Boundary_UPxr_SetGuardianSystemDisable_m2E6F8683908119A5CA656628B58C953E2434EC4A((bool)1, NULL);
		// Log.Debug("---OnFocusStateAcquired-");
		il2cpp_codegen_runtime_class_init_inline(Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		Log_Debug_mBC6B7CAF0E12CB5777FB8FAAE59289CCDAED17A2(_stringLiteral307E4E9ED9EDF0491BA858A2CD1BC00E65FFA257, _stringLiteral132195FDF8564E10AC7A2AFE7D2DB7C9BEA52DD2, _stringLiteral47DAD2DC5D493BB0500F8358F87D18769C0769BA, ((int32_t)43), NULL);
		// }
		return;
	}
}
// System.Void com.picoxr.blsapce.SpatialTextureMain::OnDestroy()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpatialTextureMain_OnDestroy_m773E6D5837B0BFDAEA42CAB147CF507405E6273C (SpatialTextureMain_tA0B9AB4FB7C9920C93B5AEE43B3F12BFE42C57DB* __this, const RuntimeMethod* method) 
{
	{
		// PXR_Enterprise.UnBindEnterpriseService();
		PXR_Enterprise_UnBindEnterpriseService_m7C64EB437499AEE8388B6E1AE4667FA0F8A14D99(NULL);
		// }
		return;
	}
}
// System.Void com.picoxr.blsapce.SpatialTextureMain::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpatialTextureMain__ctor_m4F8996EBF54E8244D51B7AF53EC564D8256E7938 (SpatialTextureMain_tA0B9AB4FB7C9920C93B5AEE43B3F12BFE42C57DB* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralEAA0AD4C9DDC7B173ACD12710BBE084A3B32C5F6);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public string Language = "zh";
		__this->___Language_4 = _stringLiteralEAA0AD4C9DDC7B173ACD12710BBE084A3B32C5F6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Language_4), (void*)_stringLiteralEAA0AD4C9DDC7B173ACD12710BBE084A3B32C5F6);
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
extern "C" void DEFAULT_CALL ReversePInvokeWrapper_SpatialTextureToSystem_RuntimeCall_mEB3B29789D850F95A4172D9A46668168EA90F83F(TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 ___0_info)
{
	il2cpp::vm::ScopedThreadAttacher _vmThreadHelper;

	// Managed method invocation
	SpatialTextureToSystem_RuntimeCall_mEB3B29789D850F95A4172D9A46668168EA90F83F(___0_info, NULL);

}
// System.IntPtr com.picoxr.blsapce.SpatialTextureToSystem::CreateClient()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t SpatialTextureToSystem_CreateClient_m1EB6468E9961E55CDB96A15D16DB46C7888E1659 (const RuntimeMethod* method) 
{
	typedef intptr_t (CDECL *PInvokeFunc) ();
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_libtrackingclient_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = 0;
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("libtrackingclient.pxr"), "CreateClient", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_libtrackingclient_INTERNAL
	intptr_t returnValue = reinterpret_cast<PInvokeFunc>(CreateClient)();
	#else
	intptr_t returnValue = il2cppPInvokeFunc();
	#endif

	return returnValue;
}
// System.Int32 com.picoxr.blsapce.SpatialTextureToSystem::startTextureScanning(System.IntPtr,System.Action`1<com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SpatialTextureToSystem_startTextureScanning_mCF4FBB56ACEA5DF5D2F102641835CE8E4653248B (intptr_t ___0_client, Action_1_t1EE3C77B386F0D0C621A13E4401EC8A7E3819D93* ___1_callback, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t, Il2CppMethodPointer);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_libtrackingclient_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t) + sizeof(Il2CppMethodPointer);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("libtrackingclient.pxr"), "startTextureScanning", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Marshaling of parameter '___1_callback' to native representation
	Il2CppMethodPointer ____1_callback_marshaled = NULL;
	____1_callback_marshaled = il2cpp_codegen_marshal_delegate(reinterpret_cast<MulticastDelegate_t*>(___1_callback));

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_libtrackingclient_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(startTextureScanning)(___0_client, ____1_callback_marshaled);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_client, ____1_callback_marshaled);
	#endif

	return returnValue;
}
// System.Int32 com.picoxr.blsapce.SpatialTextureToSystem::stopTextureScanning(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SpatialTextureToSystem_stopTextureScanning_m7845B2A3AD031093922454463C886C057FA28FDF (intptr_t ___0_client, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_libtrackingclient_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("libtrackingclient.pxr"), "stopTextureScanning", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_libtrackingclient_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(stopTextureScanning)(___0_client);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_client);
	#endif

	return returnValue;
}
// System.Void com.picoxr.blsapce.SpatialTextureToSystem::Create()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpatialTextureToSystem_Create_m38CF8833B3F5D1FC25215B0A15364BE7FCB2E84A (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral42559C2140EDFAB50DB6AE7DCF62B93B4DA42968);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral4F6EF6B8FCA2DF0D1B799A9EEBFC44CA196D1B74);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF4A6F683F4A7F6B8CF4C7B36D6FB9DC9FE6770D2);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	{
		// if (TestMode)
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		bool L_0 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->___TestMode_11;
		V_0 = L_0;
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_000d;
		}
	}
	{
		// return;
		goto IL_0059;
	}

IL_000d:
	{
		// if (_spatialtexturePtr != IntPtr.Zero)
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		intptr_t L_2 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____spatialtexturePtr_5;
		intptr_t L_3 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		bool L_4;
		L_4 = IntPtr_op_Inequality_m90EFC9C4CAD9A33E309F2DDF98EE4E1DD253637B(L_2, L_3, NULL);
		V_1 = L_4;
		bool L_5 = V_1;
		if (!L_5)
		{
			goto IL_0023;
		}
	}
	{
		// return;
		goto IL_0059;
	}

IL_0023:
	{
		// _started = false;
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____started_10 = (bool)0;
		// _spatialtexturePtr = CreateClient();
		intptr_t L_6;
		L_6 = SpatialTextureToSystem_CreateClient_m1EB6468E9961E55CDB96A15D16DB46C7888E1659(NULL);
		((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____spatialtexturePtr_5 = L_6;
		// Log.Debug("CreateClient _spatialtexturePtr:" + _spatialtexturePtr);
		String_t* L_7;
		L_7 = IntPtr_ToString_mDA1150F4802E1FB9313FB4E32C684EEE19116E5C((&((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____spatialtexturePtr_5), NULL);
		String_t* L_8;
		L_8 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral4F6EF6B8FCA2DF0D1B799A9EEBFC44CA196D1B74, L_7, NULL);
		il2cpp_codegen_runtime_class_init_inline(Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		Log_Debug_mBC6B7CAF0E12CB5777FB8FAAE59289CCDAED17A2(L_8, _stringLiteralF4A6F683F4A7F6B8CF4C7B36D6FB9DC9FE6770D2, _stringLiteral42559C2140EDFAB50DB6AE7DCF62B93B4DA42968, ((int32_t)80), NULL);
	}

IL_0059:
	{
		// }
		return;
	}
}
// System.Int32 com.picoxr.blsapce.SpatialTextureToSystem::StartTextureScanning(com.picoxr.blsapce.SpatialTextureToSystem/CallBackDelegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SpatialTextureToSystem_StartTextureScanning_m928AB6F9BE70F7A9CBAFCC65C80A0FAF09BE02A3 (CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC* ___0_callback, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t1EE3C77B386F0D0C621A13E4401EC8A7E3819D93_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpatialTextureToSystem_EditorTest_mD7948F4D04A321BD3BC399921104CD2B509266D1_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpatialTextureToSystem_RuntimeCall_mEB3B29789D850F95A4172D9A46668168EA90F83F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC6F551CEE034848BB7699CB3BD3517BE37BCBB45);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF4A6F683F4A7F6B8CF4C7B36D6FB9DC9FE6770D2);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF69B7FD4DC0E47B3768005646AEE819A970AE1F3);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	bool V_1 = false;
	int32_t V_2 = 0;
	bool V_3 = false;
	bool V_4 = false;
	{
		// if (_started)
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		bool L_0 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____started_10;
		V_1 = L_0;
		bool L_1 = V_1;
		if (!L_1)
		{
			goto IL_0012;
		}
	}
	{
		// return -1;
		V_2 = (-1);
		goto IL_00b6;
	}

IL_0012:
	{
		// _callback = callback;
		CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC* L_2 = ___0_callback;
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____callback_6 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____callback_6), (void*)L_2);
		// _started = true;
		((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____started_10 = (bool)1;
		// int res = -1;
		V_0 = (-1);
		// if (TestMode)
		bool L_3 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->___TestMode_11;
		V_3 = L_3;
		bool L_4 = V_3;
		if (!L_4)
		{
			goto IL_0061;
		}
	}
	{
		// timerId = Timer.Add(1, EditorTest, 0.5f);
		Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* L_5 = (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07*)il2cpp_codegen_object_new(Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07_il2cpp_TypeInfo_var);
		NullCheck(L_5);
		Action__ctor_mBDC7B0B4A3F583B64C2896F01BDED360772F67DC(L_5, NULL, (intptr_t)((void*)SpatialTextureToSystem_EditorTest_mD7948F4D04A321BD3BC399921104CD2B509266D1_RuntimeMethod_var), NULL);
		int32_t L_6;
		L_6 = Timer_Add_m60043B0A6BE292995EA3C4ACDA2B8B307231B23C((1.0f), L_5, (0.5f), NULL);
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->___timerId_9 = L_6;
		// _testInfo.dScanRate = 0;
		(&((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____testInfo_8)->___dScanRate_4 = (0.0);
		// return 0;
		V_2 = 0;
		goto IL_00b6;
	}

IL_0061:
	{
		// if (_spatialtexturePtr != IntPtr.Zero)
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		intptr_t L_7 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____spatialtexturePtr_5;
		intptr_t L_8 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		bool L_9;
		L_9 = IntPtr_op_Inequality_m90EFC9C4CAD9A33E309F2DDF98EE4E1DD253637B(L_7, L_8, NULL);
		V_4 = L_9;
		bool L_10 = V_4;
		if (!L_10)
		{
			goto IL_00b2;
		}
	}
	{
		// res = startTextureScanning(_spatialtexturePtr, RuntimeCall);
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		intptr_t L_11 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____spatialtexturePtr_5;
		Action_1_t1EE3C77B386F0D0C621A13E4401EC8A7E3819D93* L_12 = (Action_1_t1EE3C77B386F0D0C621A13E4401EC8A7E3819D93*)il2cpp_codegen_object_new(Action_1_t1EE3C77B386F0D0C621A13E4401EC8A7E3819D93_il2cpp_TypeInfo_var);
		NullCheck(L_12);
		Action_1__ctor_mFC92FF99210AA666DCCBC082A7C89AE48C380DE9(L_12, NULL, (intptr_t)((void*)SpatialTextureToSystem_RuntimeCall_mEB3B29789D850F95A4172D9A46668168EA90F83F_RuntimeMethod_var), NULL);
		int32_t L_13;
		L_13 = SpatialTextureToSystem_startTextureScanning_mCF4FBB56ACEA5DF5D2F102641835CE8E4653248B(L_11, L_12, NULL);
		V_0 = L_13;
		// Log.Debug("--startTextureScanning res:" + res);
		String_t* L_14;
		L_14 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&V_0), NULL);
		String_t* L_15;
		L_15 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteralC6F551CEE034848BB7699CB3BD3517BE37BCBB45, L_14, NULL);
		il2cpp_codegen_runtime_class_init_inline(Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		Log_Debug_mBC6B7CAF0E12CB5777FB8FAAE59289CCDAED17A2(L_15, _stringLiteralF4A6F683F4A7F6B8CF4C7B36D6FB9DC9FE6770D2, _stringLiteralF69B7FD4DC0E47B3768005646AEE819A970AE1F3, ((int32_t)104), NULL);
	}

IL_00b2:
	{
		// return res;
		int32_t L_16 = V_0;
		V_2 = L_16;
		goto IL_00b6;
	}

IL_00b6:
	{
		// }
		int32_t L_17 = V_2;
		return L_17;
	}
}
// System.Void com.picoxr.blsapce.SpatialTextureToSystem::EditorTest()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpatialTextureToSystem_EditorTest_mD7948F4D04A321BD3BC399921104CD2B509266D1 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	bool V_2 = false;
	bool V_3 = false;
	{
		// if (_testInfo.dScanRate < 1)
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		double L_0 = (&((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____testInfo_8)->___dScanRate_4;
		V_0 = (bool)((((double)L_0) < ((double)(1.0)))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0040;
		}
	}
	{
		// _testInfo.dScanRate += 0.06f;
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		double* L_2 = (double*)(&(&((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____testInfo_8)->___dScanRate_4);
		double* L_3 = L_2;
		double L_4 = *((double*)L_3);
		*((double*)L_3) = (double)((double)il2cpp_codegen_add(L_4, (0.059999998658895493)));
		// _testInfo.iScanStatus = ScanState.Scanning;
		(&((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____testInfo_8)->___iScanStatus_1 = 2;
		goto IL_006c;
	}

IL_0040:
	{
		// _testInfo.dScanRate = 1f;
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		(&((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____testInfo_8)->___dScanRate_4 = (1.0);
		// _testInfo.iScanStatus = ScanState.Finished;
		(&((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____testInfo_8)->___iScanStatus_1 = 1;
		// testNum++;
		int32_t L_5 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->___testNum_12;
		((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->___testNum_12 = ((int32_t)il2cpp_codegen_add(L_5, 1));
	}

IL_006c:
	{
		// if (testNum % 3 == 0)
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		int32_t L_6 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->___testNum_12;
		V_1 = (bool)((((int32_t)((int32_t)(L_6%3))) == ((int32_t)0))? 1 : 0);
		bool L_7 = V_1;
		if (!L_7)
		{
			goto IL_0089;
		}
	}
	{
		// _testInfo.textureLevel = TextureLevelType.LOW_TEXTURE_LEVEL;
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		(&((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____testInfo_8)->___textureLevel_0 = 1;
		goto IL_00b3;
	}

IL_0089:
	{
		// else if (testNum % 2 == 0)
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		int32_t L_8 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->___testNum_12;
		V_2 = (bool)((((int32_t)((int32_t)(L_8%2))) == ((int32_t)0))? 1 : 0);
		bool L_9 = V_2;
		if (!L_9)
		{
			goto IL_00a6;
		}
	}
	{
		// _testInfo.textureLevel = TextureLevelType.MEDIAN_TEXTURE_LEVEL;
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		(&((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____testInfo_8)->___textureLevel_0 = 2;
		goto IL_00b3;
	}

IL_00a6:
	{
		// _testInfo.textureLevel = TextureLevelType.HIGH_TEXTURE_LEVEL;
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		(&((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____testInfo_8)->___textureLevel_0 = 4;
	}

IL_00b3:
	{
		// if (testNum == 4)
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		int32_t L_10 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->___testNum_12;
		V_3 = (bool)((((int32_t)L_10) == ((int32_t)4))? 1 : 0);
		bool L_11 = V_3;
		if (!L_11)
		{
			goto IL_00cc;
		}
	}
	{
		// _testInfo.iScanStatus = ScanState.Unfinished;
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		(&((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____testInfo_8)->___iScanStatus_1 = 0;
	}

IL_00cc:
	{
		// _callback.Invoke(_testInfo);
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC* L_12 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____callback_6;
		TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 L_13 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____testInfo_8;
		NullCheck(L_12);
		CallBackDelegate_Invoke_m42D4CEED99DFAE02791F0098A5657031B3A3BADE_inline(L_12, L_13, NULL);
		// }
		return;
	}
}
// System.Int32 com.picoxr.blsapce.SpatialTextureToSystem::StopTextureScanning()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SpatialTextureToSystem_StopTextureScanning_m58648531C9F61872668CC31724E3D76BF11B3014 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral52DD90E356E26DE0E1D7BC521CBAC1ED5D677D4D);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral5C80B10EDFAF8B92E4363946E9D63233E65D691F);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF4A6F683F4A7F6B8CF4C7B36D6FB9DC9FE6770D2);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	bool V_1 = false;
	bool V_2 = false;
	bool V_3 = false;
	int32_t V_4 = 0;
	{
		// int res = -1;
		V_0 = (-1);
		// if (_spatialtexturePtr != IntPtr.Zero)
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		intptr_t L_0 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____spatialtexturePtr_5;
		intptr_t L_1 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		bool L_2;
		L_2 = IntPtr_op_Inequality_m90EFC9C4CAD9A33E309F2DDF98EE4E1DD253637B(L_0, L_1, NULL);
		V_1 = L_2;
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_005a;
		}
	}
	{
		// if (_started)
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		bool L_4 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____started_10;
		V_2 = L_4;
		bool L_5 = V_2;
		if (!L_5)
		{
			goto IL_0059;
		}
	}
	{
		// res = stopTextureScanning(_spatialtexturePtr);
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		intptr_t L_6 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____spatialtexturePtr_5;
		int32_t L_7;
		L_7 = SpatialTextureToSystem_stopTextureScanning_m7845B2A3AD031093922454463C886C057FA28FDF(L_6, NULL);
		V_0 = L_7;
		// Log.Debug("--stopTextureScanning res:" + res);
		String_t* L_8;
		L_8 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&V_0), NULL);
		String_t* L_9;
		L_9 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral52DD90E356E26DE0E1D7BC521CBAC1ED5D677D4D, L_8, NULL);
		il2cpp_codegen_runtime_class_init_inline(Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		Log_Debug_mBC6B7CAF0E12CB5777FB8FAAE59289CCDAED17A2(L_9, _stringLiteralF4A6F683F4A7F6B8CF4C7B36D6FB9DC9FE6770D2, _stringLiteral5C80B10EDFAF8B92E4363946E9D63233E65D691F, ((int32_t)161), NULL);
		// _started = false;
		((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____started_10 = (bool)0;
	}

IL_0059:
	{
	}

IL_005a:
	{
		// if (TestMode)
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		bool L_10 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->___TestMode_11;
		V_3 = L_10;
		bool L_11 = V_3;
		if (!L_11)
		{
			goto IL_0074;
		}
	}
	{
		// Timer.Remove(timerId);
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		int32_t L_12 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->___timerId_9;
		Timer_Remove_m5EA5375017A3E956DE9E5C697B8E6C8730D00123(L_12, NULL);
		// return 0;
		V_4 = 0;
		goto IL_0079;
	}

IL_0074:
	{
		// return res;
		int32_t L_13 = V_0;
		V_4 = L_13;
		goto IL_0079;
	}

IL_0079:
	{
		// }
		int32_t L_14 = V_4;
		return L_14;
	}
}
// System.Void com.picoxr.blsapce.SpatialTextureToSystem::RuntimeCall(com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpatialTextureToSystem_RuntimeCall_mEB3B29789D850F95A4172D9A46668168EA90F83F (TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 ___0_info, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Queue_1_Enqueue_m575BD66AE362D5DB74AE95DCB203046EDE78991B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScanState_tC2A7E771A0FB73056F3BFF17BFB32A3D7B9184BB_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TextureLevelType_t9605D1AFDEBBBAA51AAC3F4AA94492ED053FBE8B_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2386E77CF610F786B06A91AF2C1B3FD2282D2745);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral31C00001AA53ABB55EC8A399C462608AA8FE077A);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral698465F560A6DD0E0808454A77676B2FF6CF16E4);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCEAFFB1A5B2970796F2CD60BE8C4BD9D6BCA9431);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF4A6F683F4A7F6B8CF4C7B36D6FB9DC9FE6770D2);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	{
		// Log.Debug("--callBack TextureInfo:" + info.textureLevel + " " + info.iScanStatus + " " +
		//           info.dTextureScore + " " + info.dScanRate);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_0 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)8);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_1 = L_0;
		NullCheck(L_1);
		ArrayElementTypeCheck (L_1, _stringLiteralCEAFFB1A5B2970796F2CD60BE8C4BD9D6BCA9431);
		(L_1)->SetAt(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteralCEAFFB1A5B2970796F2CD60BE8C4BD9D6BCA9431);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_2 = L_1;
		int32_t* L_3 = (int32_t*)(&(&___0_info)->___textureLevel_0);
		Il2CppFakeBox<int32_t> L_4(TextureLevelType_t9605D1AFDEBBBAA51AAC3F4AA94492ED053FBE8B_il2cpp_TypeInfo_var, L_3);
		String_t* L_5;
		L_5 = Enum_ToString_m946B0B83C4470457D0FF555D862022C72BB55741((Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2*)(&L_4), NULL);
		NullCheck(L_2);
		ArrayElementTypeCheck (L_2, L_5);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(1), (String_t*)L_5);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_6 = L_2;
		NullCheck(L_6);
		ArrayElementTypeCheck (L_6, _stringLiteral2386E77CF610F786B06A91AF2C1B3FD2282D2745);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(2), (String_t*)_stringLiteral2386E77CF610F786B06A91AF2C1B3FD2282D2745);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_7 = L_6;
		int32_t* L_8 = (int32_t*)(&(&___0_info)->___iScanStatus_1);
		Il2CppFakeBox<int32_t> L_9(ScanState_tC2A7E771A0FB73056F3BFF17BFB32A3D7B9184BB_il2cpp_TypeInfo_var, L_8);
		String_t* L_10;
		L_10 = Enum_ToString_m946B0B83C4470457D0FF555D862022C72BB55741((Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2*)(&L_9), NULL);
		NullCheck(L_7);
		ArrayElementTypeCheck (L_7, L_10);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(3), (String_t*)L_10);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_11 = L_7;
		NullCheck(L_11);
		ArrayElementTypeCheck (L_11, _stringLiteral2386E77CF610F786B06A91AF2C1B3FD2282D2745);
		(L_11)->SetAt(static_cast<il2cpp_array_size_t>(4), (String_t*)_stringLiteral2386E77CF610F786B06A91AF2C1B3FD2282D2745);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_12 = L_11;
		double* L_13 = (double*)(&(&___0_info)->___dTextureScore_2);
		String_t* L_14;
		L_14 = Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339(L_13, NULL);
		NullCheck(L_12);
		ArrayElementTypeCheck (L_12, L_14);
		(L_12)->SetAt(static_cast<il2cpp_array_size_t>(5), (String_t*)L_14);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_15 = L_12;
		NullCheck(L_15);
		ArrayElementTypeCheck (L_15, _stringLiteral2386E77CF610F786B06A91AF2C1B3FD2282D2745);
		(L_15)->SetAt(static_cast<il2cpp_array_size_t>(6), (String_t*)_stringLiteral2386E77CF610F786B06A91AF2C1B3FD2282D2745);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_16 = L_15;
		double* L_17 = (double*)(&(&___0_info)->___dScanRate_4);
		String_t* L_18;
		L_18 = Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339(L_17, NULL);
		NullCheck(L_16);
		ArrayElementTypeCheck (L_16, L_18);
		(L_16)->SetAt(static_cast<il2cpp_array_size_t>(7), (String_t*)L_18);
		String_t* L_19;
		L_19 = String_Concat_m647EBF831F54B6DF7D5AFA5FD012CF4EE7571B6A(L_16, NULL);
		il2cpp_codegen_runtime_class_init_inline(Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		Log_Debug_mBC6B7CAF0E12CB5777FB8FAAE59289CCDAED17A2(L_19, _stringLiteralF4A6F683F4A7F6B8CF4C7B36D6FB9DC9FE6770D2, _stringLiteral31C00001AA53ABB55EC8A399C462608AA8FE077A, ((int32_t)179), NULL);
		// if (_started)
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		bool L_20 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____started_10;
		V_0 = L_20;
		bool L_21 = V_0;
		if (!L_21)
		{
			goto IL_00ba;
		}
	}
	{
		// _receives.Enqueue(info);
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9* L_22 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____receives_7;
		TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 L_23 = ___0_info;
		NullCheck(L_22);
		Queue_1_Enqueue_m575BD66AE362D5DB74AE95DCB203046EDE78991B(L_22, L_23, Queue_1_Enqueue_m575BD66AE362D5DB74AE95DCB203046EDE78991B_RuntimeMethod_var);
		// Log.Debug("callback TextureInfo euque.");
		il2cpp_codegen_runtime_class_init_inline(Log_t081B3C9E17F006C4C3EA99069E77DBA6733910ED_il2cpp_TypeInfo_var);
		Log_Debug_mBC6B7CAF0E12CB5777FB8FAAE59289CCDAED17A2(_stringLiteral698465F560A6DD0E0808454A77676B2FF6CF16E4, _stringLiteralF4A6F683F4A7F6B8CF4C7B36D6FB9DC9FE6770D2, _stringLiteral31C00001AA53ABB55EC8A399C462608AA8FE077A, ((int32_t)184), NULL);
	}

IL_00ba:
	{
		// }
		return;
	}
}
// System.Void com.picoxr.blsapce.SpatialTextureToSystem::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpatialTextureToSystem_Update_m03CA59E1091EBC3FC4CB9529C83A8964ED41E527 (SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Queue_1_Dequeue_mF641B4D1C707EF56082B2E8DF4351EBDEB8357F8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Queue_1_get_Count_m166D9E7A5DA18ACC5799C3963DD64F400A9F21BC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 V_1;
	memset((&V_1), 0, sizeof(V_1));
	bool V_2 = false;
	int32_t G_B4_0 = 0;
	{
		// if (_receives.Count > 0)
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9* L_0 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____receives_7;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = Queue_1_get_Count_m166D9E7A5DA18ACC5799C3963DD64F400A9F21BC_inline(L_0, Queue_1_get_Count_m166D9E7A5DA18ACC5799C3963DD64F400A9F21BC_RuntimeMethod_var);
		V_0 = (bool)((((int32_t)L_1) > ((int32_t)0))? 1 : 0);
		bool L_2 = V_0;
		if (!L_2)
		{
			goto IL_0043;
		}
	}
	{
		// TextureInfo info = _receives.Dequeue();
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9* L_3 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____receives_7;
		NullCheck(L_3);
		TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 L_4;
		L_4 = Queue_1_Dequeue_mF641B4D1C707EF56082B2E8DF4351EBDEB8357F8(L_3, Queue_1_Dequeue_mF641B4D1C707EF56082B2E8DF4351EBDEB8357F8_RuntimeMethod_var);
		V_1 = L_4;
		// if (_started&&_callback != null)
		bool L_5 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____started_10;
		if (!L_5)
		{
			goto IL_002f;
		}
	}
	{
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC* L_6 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____callback_6;
		G_B4_0 = ((!(((RuntimeObject*)(CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC*)L_6) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		goto IL_0030;
	}

IL_002f:
	{
		G_B4_0 = 0;
	}

IL_0030:
	{
		V_2 = (bool)G_B4_0;
		bool L_7 = V_2;
		if (!L_7)
		{
			goto IL_0042;
		}
	}
	{
		// _callback.Invoke(info);
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC* L_8 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____callback_6;
		TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 L_9 = V_1;
		NullCheck(L_8);
		CallBackDelegate_Invoke_m42D4CEED99DFAE02791F0098A5657031B3A3BADE_inline(L_8, L_9, NULL);
	}

IL_0042:
	{
	}

IL_0043:
	{
		// }
		return;
	}
}
// System.Void com.picoxr.blsapce.SpatialTextureToSystem::ClearReceiveQueue()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpatialTextureToSystem_ClearReceiveQueue_mFA19795E99AD02766030D71F26F0BFEEBC07670E (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Queue_1_Clear_m6B2EEBAC23F6D33E3209B3CDD5663163329AF523_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// _receives.Clear();
		il2cpp_codegen_runtime_class_init_inline(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9* L_0 = ((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____receives_7;
		NullCheck(L_0);
		Queue_1_Clear_m6B2EEBAC23F6D33E3209B3CDD5663163329AF523(L_0, Queue_1_Clear_m6B2EEBAC23F6D33E3209B3CDD5663163329AF523_RuntimeMethod_var);
		// }
		return;
	}
}
// System.Void com.picoxr.blsapce.SpatialTextureToSystem::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpatialTextureToSystem__ctor_mA5EAF1812F1E927D55E7C508E948AE2295B61A3E (SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
// System.Void com.picoxr.blsapce.SpatialTextureToSystem::.cctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpatialTextureToSystem__cctor_mDE934F00F95C634D96C48E92A5EF742A27F03565 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Queue_1__ctor_mBC4678D497EB50E3826BB8B1818E4A38B45B486B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private static IntPtr _spatialtexturePtr = IntPtr.Zero;
		intptr_t L_0 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____spatialtexturePtr_5 = L_0;
		// private static Queue<TextureInfo> _receives = new Queue<TextureInfo>();
		Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9* L_1 = (Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9*)il2cpp_codegen_object_new(Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		Queue_1__ctor_mBC4678D497EB50E3826BB8B1818E4A38B45B486B(L_1, Queue_1__ctor_mBC4678D497EB50E3826BB8B1818E4A38B45B486B_RuntimeMethod_var);
		((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____receives_7 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____receives_7), (void*)L_1);
		// private static bool _started = false;
		((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->____started_10 = (bool)0;
		// public static bool TestMode = false;
		((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->___TestMode_11 = (bool)0;
		// private static int testNum = 0;
		((SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_StaticFields*)il2cpp_codegen_static_fields_for(SpatialTextureToSystem_t8BC2742A1ABB552521C09E252B30130141ED1CE3_il2cpp_TypeInfo_var))->___testNum_12 = 0;
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void CallBackDelegate_Invoke_m42D4CEED99DFAE02791F0098A5657031B3A3BADE_Multicast(CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC* __this, TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 ___0_info, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates_13->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates_13->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC* currentDelegate = reinterpret_cast<CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl_1)((Il2CppObject*)currentDelegate->___method_code_6, ___0_info, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method_3));
	}
}
void CallBackDelegate_Invoke_m42D4CEED99DFAE02791F0098A5657031B3A3BADE_OpenInst(CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC* __this, TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 ___0_info, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___0_info, method);
}
void CallBackDelegate_Invoke_m42D4CEED99DFAE02791F0098A5657031B3A3BADE_OpenStatic(CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC* __this, TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 ___0_info, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___0_info, method);
}
void CallBackDelegate_Invoke_m42D4CEED99DFAE02791F0098A5657031B3A3BADE_OpenStaticInvoker(CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC* __this, TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 ___0_info, const RuntimeMethod* method)
{
	InvokerActionInvoker1< TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, ___0_info);
}
void CallBackDelegate_Invoke_m42D4CEED99DFAE02791F0098A5657031B3A3BADE_ClosedStaticInvoker(CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC* __this, TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 ___0_info, const RuntimeMethod* method)
{
	InvokerActionInvoker2< RuntimeObject*, TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, __this->___m_target_2, ___0_info);
}
IL2CPP_EXTERN_C  void DelegatePInvokeWrapper_CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC (CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC* __this, TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 ___0_info, const RuntimeMethod* method)
{
	typedef void (DEFAULT_CALL *PInvokeFunc)(TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6);
	PInvokeFunc il2cppPInvokeFunc = reinterpret_cast<PInvokeFunc>(il2cpp_codegen_get_reverse_pinvoke_function_ptr(__this));
	// Native function invocation
	il2cppPInvokeFunc(___0_info);

}
// System.Void com.picoxr.blsapce.SpatialTextureToSystem/CallBackDelegate::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CallBackDelegate__ctor_m89058847D333A244352AC5AF5EF53A9C99B47148 (CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr_0 = (intptr_t)il2cpp_codegen_get_virtual_call_method_pointer((RuntimeMethod*)___1_method);
	__this->___method_3 = ___1_method;
	__this->___m_target_2 = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target_2), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code_6 = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 1;
		if (il2cpp_codegen_call_method_via_invoker((RuntimeMethod*)___1_method))
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&CallBackDelegate_Invoke_m42D4CEED99DFAE02791F0098A5657031B3A3BADE_OpenStaticInvoker;
			else
				__this->___invoke_impl_1 = (intptr_t)&CallBackDelegate_Invoke_m42D4CEED99DFAE02791F0098A5657031B3A3BADE_ClosedStaticInvoker;
		else
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&CallBackDelegate_Invoke_m42D4CEED99DFAE02791F0098A5657031B3A3BADE_OpenStatic;
			else
				{
					__this->___invoke_impl_1 = __this->___method_ptr_0;
					__this->___method_code_6 = (intptr_t)__this->___m_target_2;
				}
	}
	else
	{
		if (___0_object == NULL)
			il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
		__this->___invoke_impl_1 = __this->___method_ptr_0;
		__this->___method_code_6 = (intptr_t)__this->___m_target_2;
	}
	__this->___extra_arg_5 = (intptr_t)&CallBackDelegate_Invoke_m42D4CEED99DFAE02791F0098A5657031B3A3BADE_Multicast;
}
// System.Void com.picoxr.blsapce.SpatialTextureToSystem/CallBackDelegate::Invoke(com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CallBackDelegate_Invoke_m42D4CEED99DFAE02791F0098A5657031B3A3BADE (CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC* __this, TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 ___0_info, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_info, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
// System.IAsyncResult com.picoxr.blsapce.SpatialTextureToSystem/CallBackDelegate::BeginInvoke(com.picoxr.blsapce.SpatialTextureToSystem/TextureInfo,System.AsyncCallback,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* CallBackDelegate_BeginInvoke_m26C2A9B1C5484E1A7B6ACACC3E0F17C8878014B4 (CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC* __this, TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 ___0_info, AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___1_callback, RuntimeObject* ___2_object, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	void *__d_args[2] = {0};
	__d_args[0] = Box(TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6_il2cpp_TypeInfo_var, &___0_info);
	return (RuntimeObject*)il2cpp_codegen_delegate_begin_invoke((RuntimeDelegate*)__this, __d_args, (RuntimeDelegate*)___1_callback, (RuntimeObject*)___2_object);
}
// System.Void com.picoxr.blsapce.SpatialTextureToSystem/CallBackDelegate::EndInvoke(System.IAsyncResult)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CallBackDelegate_EndInvoke_mCCC179B475506409574D46B474E563D7F1B73696 (CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC* __this, RuntimeObject* ___0_result, const RuntimeMethod* method) 
{
	il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___0_result, 0);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Int32 Boundary.Data.BoundaryItem::get_Type()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t BoundaryItem_get_Type_m2ACA12BF531FA0FD8CA7C85EBC07F82C125B4C98 (BoundaryItem_t4F4A542118E39B1229AFC8916C2D37333E0A7E68* __this, const RuntimeMethod* method) 
{
	{
		// public int Type { get; set; }
		int32_t L_0 = __this->___U3CTypeU3Ek__BackingField_0;
		return L_0;
	}
}
// System.Void Boundary.Data.BoundaryItem::set_Type(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundaryItem_set_Type_m11F7D8F6E980F50A7AD194C10EC641A6A03CDD15 (BoundaryItem_t4F4A542118E39B1229AFC8916C2D37333E0A7E68* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int Type { get; set; }
		int32_t L_0 = ___0_value;
		__this->___U3CTypeU3Ek__BackingField_0 = L_0;
		return;
	}
}
// System.Int32 Boundary.Data.BoundaryItem::get_Size()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t BoundaryItem_get_Size_m44A721DC7570FF65C4EE5416ECECF6BF5BF0CDDA (BoundaryItem_t4F4A542118E39B1229AFC8916C2D37333E0A7E68* __this, const RuntimeMethod* method) 
{
	{
		// public int Size { get; set; }
		int32_t L_0 = __this->___U3CSizeU3Ek__BackingField_1;
		return L_0;
	}
}
// System.Void Boundary.Data.BoundaryItem::set_Size(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundaryItem_set_Size_m6811315693E73C4CEC25933C8BAA79025E3F4718 (BoundaryItem_t4F4A542118E39B1229AFC8916C2D37333E0A7E68* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int Size { get; set; }
		int32_t L_0 = ___0_value;
		__this->___U3CSizeU3Ek__BackingField_1 = L_0;
		return;
	}
}
// System.Collections.Generic.List`1<System.Collections.Generic.List`1<System.Single>> Boundary.Data.BoundaryItem::get_Points()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_tFF2BC422A193D7F048E03ABCCC32292E892A12F7* BoundaryItem_get_Points_m946B9FB4D8CBB8E081016714BA815132295A469A (BoundaryItem_t4F4A542118E39B1229AFC8916C2D37333E0A7E68* __this, const RuntimeMethod* method) 
{
	{
		// public List<List<float>> Points { get; set; }
		List_1_tFF2BC422A193D7F048E03ABCCC32292E892A12F7* L_0 = __this->___U3CPointsU3Ek__BackingField_2;
		return L_0;
	}
}
// System.Void Boundary.Data.BoundaryItem::set_Points(System.Collections.Generic.List`1<System.Collections.Generic.List`1<System.Single>>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundaryItem_set_Points_m5C3B44792292F9C4E9C9DA3A8592787656B10941 (BoundaryItem_t4F4A542118E39B1229AFC8916C2D37333E0A7E68* __this, List_1_tFF2BC422A193D7F048E03ABCCC32292E892A12F7* ___0_value, const RuntimeMethod* method) 
{
	{
		// public List<List<float>> Points { get; set; }
		List_1_tFF2BC422A193D7F048E03ABCCC32292E892A12F7* L_0 = ___0_value;
		__this->___U3CPointsU3Ek__BackingField_2 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CPointsU3Ek__BackingField_2), (void*)L_0);
		return;
	}
}
// System.Void Boundary.Data.BoundaryItem::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundaryItem__ctor_m8A87FFFA0877874CF567F4E1DFB054761F0FF5C7 (BoundaryItem_t4F4A542118E39B1229AFC8916C2D37333E0A7E68* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void Boundary.Data.AlgorithmData::set_AreaCnt(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AlgorithmData_set_AreaCnt_m17C48E98C69B4503C68EC7848B45DE5BF52F928C (AlgorithmData_tBED6E92124E6F80F7B4862A143CCAB790E87DC35* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int AreaCnt { set; get; }
		int32_t L_0 = ___0_value;
		__this->___U3CAreaCntU3Ek__BackingField_0 = L_0;
		return;
	}
}
// System.Int32 Boundary.Data.AlgorithmData::get_AreaCnt()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t AlgorithmData_get_AreaCnt_m53221A333E817A4ECB61A9A6CB75296F63204A92 (AlgorithmData_tBED6E92124E6F80F7B4862A143CCAB790E87DC35* __this, const RuntimeMethod* method) 
{
	{
		// public int AreaCnt { set; get; }
		int32_t L_0 = __this->___U3CAreaCntU3Ek__BackingField_0;
		return L_0;
	}
}
// System.Void Boundary.Data.AlgorithmData::set_MapUUID(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AlgorithmData_set_MapUUID_m63EF8DCC23349872564FCF487DF0055C963086A2 (AlgorithmData_tBED6E92124E6F80F7B4862A143CCAB790E87DC35* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		// public string MapUUID { set; get; }
		String_t* L_0 = ___0_value;
		__this->___U3CMapUUIDU3Ek__BackingField_1 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CMapUUIDU3Ek__BackingField_1), (void*)L_0);
		return;
	}
}
// System.String Boundary.Data.AlgorithmData::get_MapUUID()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* AlgorithmData_get_MapUUID_m20C7D9971DC706B7AE90AC07A7C734C2406EA0A6 (AlgorithmData_tBED6E92124E6F80F7B4862A143CCAB790E87DC35* __this, const RuntimeMethod* method) 
{
	{
		// public string MapUUID { set; get; }
		String_t* L_0 = __this->___U3CMapUUIDU3Ek__BackingField_1;
		return L_0;
	}
}
// System.Collections.Generic.List`1<Boundary.Data.BoundaryItem> Boundary.Data.AlgorithmData::get_Boundary()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_t9B1B27900D11844BED9AD08E793EE74AB63688C5* AlgorithmData_get_Boundary_m3AD37721EA63A306C5BF7647A835E7EEAC86370D (AlgorithmData_tBED6E92124E6F80F7B4862A143CCAB790E87DC35* __this, const RuntimeMethod* method) 
{
	{
		// public List<BoundaryItem> Boundary { get; set; }
		List_1_t9B1B27900D11844BED9AD08E793EE74AB63688C5* L_0 = __this->___U3CBoundaryU3Ek__BackingField_2;
		return L_0;
	}
}
// System.Void Boundary.Data.AlgorithmData::set_Boundary(System.Collections.Generic.List`1<Boundary.Data.BoundaryItem>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AlgorithmData_set_Boundary_mA3E59D6F8C13F9C993405F5ED6F4B9F25189EB34 (AlgorithmData_tBED6E92124E6F80F7B4862A143CCAB790E87DC35* __this, List_1_t9B1B27900D11844BED9AD08E793EE74AB63688C5* ___0_value, const RuntimeMethod* method) 
{
	{
		// public List<BoundaryItem> Boundary { get; set; }
		List_1_t9B1B27900D11844BED9AD08E793EE74AB63688C5* L_0 = ___0_value;
		__this->___U3CBoundaryU3Ek__BackingField_2 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CBoundaryU3Ek__BackingField_2), (void*)L_0);
		return;
	}
}
// System.Void Boundary.Data.AlgorithmData::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AlgorithmData__ctor_mAE04676A9F81479B3932B4C6DDB18E9672C9379E (AlgorithmData_tBED6E92124E6F80F7B4862A143CCAB790E87DC35* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Int32 Boundary.Data.BoundaryConfigData::get_seethroughtype()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t BoundaryConfigData_get_seethroughtype_mBB2748C5116279F3C9A00917E98130ED2B41661F (BoundaryConfigData_t4201DE14529DC1A53FF80BAB4E8019BE6D226748* __this, const RuntimeMethod* method) 
{
	{
		// public int seethroughtype { get; set; }
		int32_t L_0 = __this->___U3CseethroughtypeU3Ek__BackingField_0;
		return L_0;
	}
}
// System.Void Boundary.Data.BoundaryConfigData::set_seethroughtype(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundaryConfigData_set_seethroughtype_mCF58AA2AD3B8D39D82923285A283AED59E0E1730 (BoundaryConfigData_t4201DE14529DC1A53FF80BAB4E8019BE6D226748* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int seethroughtype { get; set; }
		int32_t L_0 = ___0_value;
		__this->___U3CseethroughtypeU3Ek__BackingField_0 = L_0;
		return;
	}
}
// System.Double Boundary.Data.BoundaryConfigData::get_ground()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double BoundaryConfigData_get_ground_m5DF0114751F0FEA3446A2A6218F19549506D2C47 (BoundaryConfigData_t4201DE14529DC1A53FF80BAB4E8019BE6D226748* __this, const RuntimeMethod* method) 
{
	{
		// public double ground { get; set; }
		double L_0 = __this->___U3CgroundU3Ek__BackingField_1;
		return L_0;
	}
}
// System.Void Boundary.Data.BoundaryConfigData::set_ground(System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundaryConfigData_set_ground_m6CFF2AAF60512386C5BC0D1425EFCD720C5B0F24 (BoundaryConfigData_t4201DE14529DC1A53FF80BAB4E8019BE6D226748* __this, double ___0_value, const RuntimeMethod* method) 
{
	{
		// public double ground { get; set; }
		double L_0 = ___0_value;
		__this->___U3CgroundU3Ek__BackingField_1 = L_0;
		return;
	}
}
// System.String Boundary.Data.BoundaryConfigData::get_posture()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* BoundaryConfigData_get_posture_mA206A92F5BB5CF5F02384A00666B0EC74F740C27 (BoundaryConfigData_t4201DE14529DC1A53FF80BAB4E8019BE6D226748* __this, const RuntimeMethod* method) 
{
	{
		// public String posture { get; set; }
		String_t* L_0 = __this->___U3CpostureU3Ek__BackingField_2;
		return L_0;
	}
}
// System.Void Boundary.Data.BoundaryConfigData::set_posture(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundaryConfigData_set_posture_mF1594EAB815CCF2DB43CB949163019EC45372279 (BoundaryConfigData_t4201DE14529DC1A53FF80BAB4E8019BE6D226748* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		// public String posture { get; set; }
		String_t* L_0 = ___0_value;
		__this->___U3CpostureU3Ek__BackingField_2 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CpostureU3Ek__BackingField_2), (void*)L_0);
		return;
	}
}
// System.Double Boundary.Data.BoundaryConfigData::get_StandHeight()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double BoundaryConfigData_get_StandHeight_mD7659B3C634E226F80626809E1F3B0071F08F0B1 (BoundaryConfigData_t4201DE14529DC1A53FF80BAB4E8019BE6D226748* __this, const RuntimeMethod* method) 
{
	{
		// public double StandHeight { get; set; }
		double L_0 = __this->___U3CStandHeightU3Ek__BackingField_3;
		return L_0;
	}
}
// System.Void Boundary.Data.BoundaryConfigData::set_StandHeight(System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundaryConfigData_set_StandHeight_mAE7197D136D55DA95EC9279FE687C362D16500EC (BoundaryConfigData_t4201DE14529DC1A53FF80BAB4E8019BE6D226748* __this, double ___0_value, const RuntimeMethod* method) 
{
	{
		// public double StandHeight { get; set; }
		double L_0 = ___0_value;
		__this->___U3CStandHeightU3Ek__BackingField_3 = L_0;
		return;
	}
}
// System.Double Boundary.Data.BoundaryConfigData::get_SitHeight()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double BoundaryConfigData_get_SitHeight_m7EBECB71B8CB7E4313B2FDD65BEBFCD4152F61B6 (BoundaryConfigData_t4201DE14529DC1A53FF80BAB4E8019BE6D226748* __this, const RuntimeMethod* method) 
{
	{
		// public double SitHeight { get; set; }
		double L_0 = __this->___U3CSitHeightU3Ek__BackingField_4;
		return L_0;
	}
}
// System.Void Boundary.Data.BoundaryConfigData::set_SitHeight(System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundaryConfigData_set_SitHeight_m566DD83D8E435AA507258F3A0ECEBC7F8B7D73D0 (BoundaryConfigData_t4201DE14529DC1A53FF80BAB4E8019BE6D226748* __this, double ___0_value, const RuntimeMethod* method) 
{
	{
		// public double SitHeight { get; set; }
		double L_0 = ___0_value;
		__this->___U3CSitHeightU3Ek__BackingField_4 = L_0;
		return;
	}
}
// System.String Boundary.Data.BoundaryConfigData::get_centerpath()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* BoundaryConfigData_get_centerpath_m3B9D969A1BB8AC1B9D5F2712E42B4F9718E9146D (BoundaryConfigData_t4201DE14529DC1A53FF80BAB4E8019BE6D226748* __this, const RuntimeMethod* method) 
{
	{
		// public string centerpath { get; set; }
		String_t* L_0 = __this->___U3CcenterpathU3Ek__BackingField_5;
		return L_0;
	}
}
// System.Void Boundary.Data.BoundaryConfigData::set_centerpath(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundaryConfigData_set_centerpath_m8A7A7125582C15CE191550E5E0F2397CDDD51A9A (BoundaryConfigData_t4201DE14529DC1A53FF80BAB4E8019BE6D226748* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		// public string centerpath { get; set; }
		String_t* L_0 = ___0_value;
		__this->___U3CcenterpathU3Ek__BackingField_5 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CcenterpathU3Ek__BackingField_5), (void*)L_0);
		return;
	}
}
// System.String Boundary.Data.BoundaryConfigData::get_pointdatapath()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* BoundaryConfigData_get_pointdatapath_mB6D25F1D497B77E29D17329A0D51480B803C7EDD (BoundaryConfigData_t4201DE14529DC1A53FF80BAB4E8019BE6D226748* __this, const RuntimeMethod* method) 
{
	{
		// public string pointdatapath { get; set; }
		String_t* L_0 = __this->___U3CpointdatapathU3Ek__BackingField_6;
		return L_0;
	}
}
// System.Void Boundary.Data.BoundaryConfigData::set_pointdatapath(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundaryConfigData_set_pointdatapath_m5AF4453AF4ACC1C570CF2AD462C5C0172CB86020 (BoundaryConfigData_t4201DE14529DC1A53FF80BAB4E8019BE6D226748* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		// public string pointdatapath { get; set; }
		String_t* L_0 = ___0_value;
		__this->___U3CpointdatapathU3Ek__BackingField_6 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CpointdatapathU3Ek__BackingField_6), (void*)L_0);
		return;
	}
}
// System.Int32 Boundary.Data.BoundaryConfigData::get_WallRidius()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t BoundaryConfigData_get_WallRidius_mA12AC703669957ACE8C59E02C5704BFC73D5486D (BoundaryConfigData_t4201DE14529DC1A53FF80BAB4E8019BE6D226748* __this, const RuntimeMethod* method) 
{
	{
		// public int WallRidius { get; set; }
		int32_t L_0 = __this->___U3CWallRidiusU3Ek__BackingField_7;
		return L_0;
	}
}
// System.Void Boundary.Data.BoundaryConfigData::set_WallRidius(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundaryConfigData_set_WallRidius_m09F3B0234635BEEFEE90F37390323BB2E8BBE767 (BoundaryConfigData_t4201DE14529DC1A53FF80BAB4E8019BE6D226748* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int WallRidius { get; set; }
		int32_t L_0 = ___0_value;
		__this->___U3CWallRidiusU3Ek__BackingField_7 = L_0;
		return;
	}
}
// System.Void Boundary.Data.BoundaryConfigData::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundaryConfigData__ctor_mC678069939C49FDD6523A59359BAB5BFD4F7F5D6 (BoundaryConfigData_t4201DE14529DC1A53FF80BAB4E8019BE6D226748* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Int32 Boundary.Data.Item::get_Type()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Item_get_Type_m7CCA928798F7FD6F772C350DA69F4B27AA682FEF (Item_t51A6B6268FD582ED0ADB924808FCA5449EE278F4* __this, const RuntimeMethod* method) 
{
	{
		// public int Type { get; set; }
		int32_t L_0 = __this->___U3CTypeU3Ek__BackingField_0;
		return L_0;
	}
}
// System.Void Boundary.Data.Item::set_Type(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Item_set_Type_mFA3855149E29E25368989F73A520F8C0DBA5F09F (Item_t51A6B6268FD582ED0ADB924808FCA5449EE278F4* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int Type { get; set; }
		int32_t L_0 = ___0_value;
		__this->___U3CTypeU3Ek__BackingField_0 = L_0;
		return;
	}
}
// System.Int32 Boundary.Data.Item::get_Size()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Item_get_Size_m26A3D5C2C9E1AB6B65B534C81E25FE1894579C44 (Item_t51A6B6268FD582ED0ADB924808FCA5449EE278F4* __this, const RuntimeMethod* method) 
{
	{
		// public int Size { get; set; }
		int32_t L_0 = __this->___U3CSizeU3Ek__BackingField_1;
		return L_0;
	}
}
// System.Void Boundary.Data.Item::set_Size(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Item_set_Size_m4B8EB2CBADF5820EF784682037E698F544BDE634 (Item_t51A6B6268FD582ED0ADB924808FCA5449EE278F4* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int Size { get; set; }
		int32_t L_0 = ___0_value;
		__this->___U3CSizeU3Ek__BackingField_1 = L_0;
		return;
	}
}
// System.Collections.Generic.List`1<System.Collections.Generic.List`1<System.Single>> Boundary.Data.Item::get_Points()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_tFF2BC422A193D7F048E03ABCCC32292E892A12F7* Item_get_Points_m385BA3D1DFE1B6F64F06246AC5D6B1338EAE6EAF (Item_t51A6B6268FD582ED0ADB924808FCA5449EE278F4* __this, const RuntimeMethod* method) 
{
	{
		// public List<List<float>> Points { get; set; }
		List_1_tFF2BC422A193D7F048E03ABCCC32292E892A12F7* L_0 = __this->___U3CPointsU3Ek__BackingField_2;
		return L_0;
	}
}
// System.Void Boundary.Data.Item::set_Points(System.Collections.Generic.List`1<System.Collections.Generic.List`1<System.Single>>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Item_set_Points_mE2D90DEC5332AB5AD286442D7A851C269C6D99E2 (Item_t51A6B6268FD582ED0ADB924808FCA5449EE278F4* __this, List_1_tFF2BC422A193D7F048E03ABCCC32292E892A12F7* ___0_value, const RuntimeMethod* method) 
{
	{
		// public List<List<float>> Points { get; set; }
		List_1_tFF2BC422A193D7F048E03ABCCC32292E892A12F7* L_0 = ___0_value;
		__this->___U3CPointsU3Ek__BackingField_2 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CPointsU3Ek__BackingField_2), (void*)L_0);
		return;
	}
}
// System.Int32 Boundary.Data.Item::get_triangleSize()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Item_get_triangleSize_m4A0CE64DA6B9CB2A08203DCB2491EB23A973E526 (Item_t51A6B6268FD582ED0ADB924808FCA5449EE278F4* __this, const RuntimeMethod* method) 
{
	{
		// public int triangleSize { get; set; }
		int32_t L_0 = __this->___U3CtriangleSizeU3Ek__BackingField_3;
		return L_0;
	}
}
// System.Void Boundary.Data.Item::set_triangleSize(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Item_set_triangleSize_m5A30928ADD11E5C5AAFDE8BD8FF497A9FC5329DE (Item_t51A6B6268FD582ED0ADB924808FCA5449EE278F4* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int triangleSize { get; set; }
		int32_t L_0 = ___0_value;
		__this->___U3CtriangleSizeU3Ek__BackingField_3 = L_0;
		return;
	}
}
// System.Collections.Generic.List`1<System.Collections.Generic.List`1<System.Int32>> Boundary.Data.Item::get_triangles()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_tB5A0E21D0A7C39DF93D616FD5B94C4737A083E35* Item_get_triangles_mF76EE5A73E4BFB3F60F707DD847D71FCE47EE531 (Item_t51A6B6268FD582ED0ADB924808FCA5449EE278F4* __this, const RuntimeMethod* method) 
{
	{
		// public List<List<int>> triangles { get; set; }
		List_1_tB5A0E21D0A7C39DF93D616FD5B94C4737A083E35* L_0 = __this->___U3CtrianglesU3Ek__BackingField_4;
		return L_0;
	}
}
// System.Void Boundary.Data.Item::set_triangles(System.Collections.Generic.List`1<System.Collections.Generic.List`1<System.Int32>>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Item_set_triangles_m64AFBD51A9672E1258FCDA17D9D336C6C621AC66 (Item_t51A6B6268FD582ED0ADB924808FCA5449EE278F4* __this, List_1_tB5A0E21D0A7C39DF93D616FD5B94C4737A083E35* ___0_value, const RuntimeMethod* method) 
{
	{
		// public List<List<int>> triangles { get; set; }
		List_1_tB5A0E21D0A7C39DF93D616FD5B94C4737A083E35* L_0 = ___0_value;
		__this->___U3CtrianglesU3Ek__BackingField_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CtrianglesU3Ek__BackingField_4), (void*)L_0);
		return;
	}
}
// System.Int32 Boundary.Data.Item::get_uvsize()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Item_get_uvsize_m1AC72B296286C4D6BA7B345AE0CD6CD1D18C7DBE (Item_t51A6B6268FD582ED0ADB924808FCA5449EE278F4* __this, const RuntimeMethod* method) 
{
	{
		// public int uvsize { get; set; }
		int32_t L_0 = __this->___U3CuvsizeU3Ek__BackingField_5;
		return L_0;
	}
}
// System.Void Boundary.Data.Item::set_uvsize(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Item_set_uvsize_mE9090770AFECAEDD9EA5210834F6FBB3CAD8DAF6 (Item_t51A6B6268FD582ED0ADB924808FCA5449EE278F4* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int uvsize { get; set; }
		int32_t L_0 = ___0_value;
		__this->___U3CuvsizeU3Ek__BackingField_5 = L_0;
		return;
	}
}
// System.Collections.Generic.List`1<System.Collections.Generic.List`1<System.Single>> Boundary.Data.Item::get_uv()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_tFF2BC422A193D7F048E03ABCCC32292E892A12F7* Item_get_uv_mE5A121E6B2AEF2E81423243BA72250A99CFC1474 (Item_t51A6B6268FD582ED0ADB924808FCA5449EE278F4* __this, const RuntimeMethod* method) 
{
	{
		// public List<List<float>> uv { get; set; }
		List_1_tFF2BC422A193D7F048E03ABCCC32292E892A12F7* L_0 = __this->___U3CuvU3Ek__BackingField_6;
		return L_0;
	}
}
// System.Void Boundary.Data.Item::set_uv(System.Collections.Generic.List`1<System.Collections.Generic.List`1<System.Single>>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Item_set_uv_m3E732B02840C3551B8CCA80D829B17213FD91D6B (Item_t51A6B6268FD582ED0ADB924808FCA5449EE278F4* __this, List_1_tFF2BC422A193D7F048E03ABCCC32292E892A12F7* ___0_value, const RuntimeMethod* method) 
{
	{
		// public List<List<float>> uv { get; set; }
		List_1_tFF2BC422A193D7F048E03ABCCC32292E892A12F7* L_0 = ___0_value;
		__this->___U3CuvU3Ek__BackingField_6 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CuvU3Ek__BackingField_6), (void*)L_0);
		return;
	}
}
// System.Double Boundary.Data.Item::get_areagirth()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Item_get_areagirth_mFD4F226B2DCF24C7346D362F36BB4594F68AA35C (Item_t51A6B6268FD582ED0ADB924808FCA5449EE278F4* __this, const RuntimeMethod* method) 
{
	{
		// public double areagirth { get; set; }
		double L_0 = __this->___U3CareagirthU3Ek__BackingField_7;
		return L_0;
	}
}
// System.Void Boundary.Data.Item::set_areagirth(System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Item_set_areagirth_m189426B925A24F9E235ACC40D6DE755EFC5D1B17 (Item_t51A6B6268FD582ED0ADB924808FCA5449EE278F4* __this, double ___0_value, const RuntimeMethod* method) 
{
	{
		// public double areagirth { get; set; }
		double L_0 = ___0_value;
		__this->___U3CareagirthU3Ek__BackingField_7 = L_0;
		return;
	}
}
// System.Void Boundary.Data.Item::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Item__ctor_mF4CDCB196813C40365FF76D49890CB6923C36424 (Item_t51A6B6268FD582ED0ADB924808FCA5449EE278F4* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Int32 Boundary.Data.BoundaryData::get_isSaveMap()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t BoundaryData_get_isSaveMap_mD4D5A0638716F14BF20834313C1CDD2BCCD5E708 (BoundaryData_tDC8C8A6879E571C7A509C93AA6737D479B27F1A9* __this, const RuntimeMethod* method) 
{
	{
		// public int isSaveMap { get; set; }
		int32_t L_0 = __this->___U3CisSaveMapU3Ek__BackingField_0;
		return L_0;
	}
}
// System.Void Boundary.Data.BoundaryData::set_isSaveMap(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundaryData_set_isSaveMap_m7D412DD3784E7FF3AE07CAAA253B93742D0EAB57 (BoundaryData_tDC8C8A6879E571C7A509C93AA6737D479B27F1A9* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int isSaveMap { get; set; }
		int32_t L_0 = ___0_value;
		__this->___U3CisSaveMapU3Ek__BackingField_0 = L_0;
		return;
	}
}
// System.Int32 Boundary.Data.BoundaryData::get_isCurrentType()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t BoundaryData_get_isCurrentType_mAC3A797B3234F259F207D3391F5962430C14F9A2 (BoundaryData_tDC8C8A6879E571C7A509C93AA6737D479B27F1A9* __this, const RuntimeMethod* method) 
{
	{
		// public int isCurrentType { get; set; }
		int32_t L_0 = __this->___U3CisCurrentTypeU3Ek__BackingField_1;
		return L_0;
	}
}
// System.Void Boundary.Data.BoundaryData::set_isCurrentType(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundaryData_set_isCurrentType_m437617DD6B1881FED73E84FC5641BCC11A6C1DAE (BoundaryData_tDC8C8A6879E571C7A509C93AA6737D479B27F1A9* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int isCurrentType { get; set; }
		int32_t L_0 = ___0_value;
		__this->___U3CisCurrentTypeU3Ek__BackingField_1 = L_0;
		return;
	}
}
// System.UInt64 Boundary.Data.BoundaryData::get_BoundarySaveTime()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t BoundaryData_get_BoundarySaveTime_m628B1C8D4EABCA8F2BEAA17B632CB75F5D66DFE0 (BoundaryData_tDC8C8A6879E571C7A509C93AA6737D479B27F1A9* __this, const RuntimeMethod* method) 
{
	{
		// public ulong BoundarySaveTime { get; set; }
		uint64_t L_0 = __this->___U3CBoundarySaveTimeU3Ek__BackingField_2;
		return L_0;
	}
}
// System.Void Boundary.Data.BoundaryData::set_BoundarySaveTime(System.UInt64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundaryData_set_BoundarySaveTime_m6DCC50EBA0FC5A1FBFB6463F1ED691AC24B464C6 (BoundaryData_tDC8C8A6879E571C7A509C93AA6737D479B27F1A9* __this, uint64_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public ulong BoundarySaveTime { get; set; }
		uint64_t L_0 = ___0_value;
		__this->___U3CBoundarySaveTimeU3Ek__BackingField_2 = L_0;
		return;
	}
}
// System.Int32 Boundary.Data.BoundaryData::get_AreaCnt()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t BoundaryData_get_AreaCnt_m3EFE70E515666891938A627C73D69E3E5AF3529E (BoundaryData_tDC8C8A6879E571C7A509C93AA6737D479B27F1A9* __this, const RuntimeMethod* method) 
{
	{
		// public int AreaCnt { get; set; }
		int32_t L_0 = __this->___U3CAreaCntU3Ek__BackingField_3;
		return L_0;
	}
}
// System.Void Boundary.Data.BoundaryData::set_AreaCnt(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundaryData_set_AreaCnt_m901748286FC1AABD68658D036ACDD0B44C32120D (BoundaryData_tDC8C8A6879E571C7A509C93AA6737D479B27F1A9* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int AreaCnt { get; set; }
		int32_t L_0 = ___0_value;
		__this->___U3CAreaCntU3Ek__BackingField_3 = L_0;
		return;
	}
}
// System.String Boundary.Data.BoundaryData::get_MapUUID()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* BoundaryData_get_MapUUID_m9E21DFDAA006E9B572BFC943778DCC163F108012 (BoundaryData_tDC8C8A6879E571C7A509C93AA6737D479B27F1A9* __this, const RuntimeMethod* method) 
{
	{
		// public string MapUUID { get; set; }
		String_t* L_0 = __this->___U3CMapUUIDU3Ek__BackingField_4;
		return L_0;
	}
}
// System.Void Boundary.Data.BoundaryData::set_MapUUID(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundaryData_set_MapUUID_mCACE76236590F4307A93FF368B4BAFF9581DF629 (BoundaryData_tDC8C8A6879E571C7A509C93AA6737D479B27F1A9* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		// public string MapUUID { get; set; }
		String_t* L_0 = ___0_value;
		__this->___U3CMapUUIDU3Ek__BackingField_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CMapUUIDU3Ek__BackingField_4), (void*)L_0);
		return;
	}
}
// System.Collections.Generic.List`1<Boundary.Data.Item> Boundary.Data.BoundaryData::get_Boundary()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_tDCE834B5223117F51ED29F0327C1C20731F3D0CD* BoundaryData_get_Boundary_m921A014F542AE869CB657081FDD7DD835C9BD670 (BoundaryData_tDC8C8A6879E571C7A509C93AA6737D479B27F1A9* __this, const RuntimeMethod* method) 
{
	{
		// public List<Item> Boundary { get; set; }
		List_1_tDCE834B5223117F51ED29F0327C1C20731F3D0CD* L_0 = __this->___U3CBoundaryU3Ek__BackingField_5;
		return L_0;
	}
}
// System.Void Boundary.Data.BoundaryData::set_Boundary(System.Collections.Generic.List`1<Boundary.Data.Item>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundaryData_set_Boundary_m3A0D0D5D5E05F07CADA9A6724444AB428BDE3D68 (BoundaryData_tDC8C8A6879E571C7A509C93AA6737D479B27F1A9* __this, List_1_tDCE834B5223117F51ED29F0327C1C20731F3D0CD* ___0_value, const RuntimeMethod* method) 
{
	{
		// public List<Item> Boundary { get; set; }
		List_1_tDCE834B5223117F51ED29F0327C1C20731F3D0CD* L_0 = ___0_value;
		__this->___U3CBoundaryU3Ek__BackingField_5 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CBoundaryU3Ek__BackingField_5), (void*)L_0);
		return;
	}
}
// System.Void Boundary.Data.BoundaryData::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundaryData__ctor_mBFDDF35DE6F9E6961A411C5D9A92F6BA535B654E (BoundaryData_tDC8C8A6879E571C7A509C93AA6737D479B27F1A9* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void BoundarySystem_Ext.Pvr_BoundaryAPI::Pvr_StartSDKBoundary()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_BoundaryAPI_Pvr_StartSDKBoundary_mAF7538BF823A7DA40D4F3B7BADB6C012D202C8C7 (const RuntimeMethod* method) 
{
	typedef void (CDECL *PInvokeFunc) ();
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = 0;
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("Pvr_UnitySDK"), "Pvr_StartSDKBoundary", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
	reinterpret_cast<PInvokeFunc>(Pvr_StartSDKBoundary)();
	#else
	il2cppPInvokeFunc();
	#endif

}
// System.Void BoundarySystem_Ext.Pvr_BoundaryAPI::Pvr_ShutdownSDKBoundary()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_BoundaryAPI_Pvr_ShutdownSDKBoundary_mA1D0C393D07DB079468FFAB969390AFF8B0063B2 (const RuntimeMethod* method) 
{
	typedef void (CDECL *PInvokeFunc) ();
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = 0;
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("Pvr_UnitySDK"), "Pvr_ShutdownSDKBoundary", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
	reinterpret_cast<PInvokeFunc>(Pvr_ShutdownSDKBoundary)();
	#else
	il2cppPInvokeFunc();
	#endif

}
// System.Int32 BoundarySystem_Ext.Pvr_BoundaryAPI::Pvr_GetMainSensorStateExt(System.Single&,System.Single&,System.Single&,System.Single&,System.Single&,System.Single&,System.Single&,System.Single&,System.Single&,System.Int32&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_BoundaryAPI_Pvr_GetMainSensorStateExt_m321C1D462B4E5376D3CD28EB5DA3AC024EAD6085 (float* ___0_x, float* ___1_y, float* ___2_z, float* ___3_w, float* ___4_px, float* ___5_py, float* ___6_pz, float* ___7_vfov, float* ___8_hfov, int32_t* ___9_viewNumber, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (float*, float*, float*, float*, float*, float*, float*, float*, float*, int32_t*);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(float*) + sizeof(float*) + sizeof(float*) + sizeof(float*) + sizeof(float*) + sizeof(float*) + sizeof(float*) + sizeof(float*) + sizeof(float*) + sizeof(int32_t*);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("Pvr_UnitySDK"), "Pvr_GetMainSensorStateExt", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(Pvr_GetMainSensorStateExt)(___0_x, ___1_y, ___2_z, ___3_w, ___4_px, ___5_py, ___6_pz, ___7_vfov, ___8_hfov, ___9_viewNumber);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_x, ___1_y, ___2_z, ___3_w, ___4_px, ___5_py, ___6_pz, ___7_vfov, ___8_hfov, ___9_viewNumber);
	#endif

	return returnValue;
}
// System.IntPtr BoundarySystem_Ext.Pvr_BoundaryAPI::Pvr_GetCameraData_Ext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t Pvr_BoundaryAPI_Pvr_GetCameraData_Ext_m2AD3E265FAD65F33A3FBEEDFEDF9F496CFF788B5 (const RuntimeMethod* method) 
{
	typedef intptr_t (CDECL *PInvokeFunc) ();
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = 0;
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("Pvr_UnitySDK"), "Pvr_GetCameraData_Ext", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
	intptr_t returnValue = reinterpret_cast<PInvokeFunc>(Pvr_GetCameraData_Ext)();
	#else
	intptr_t returnValue = il2cppPInvokeFunc();
	#endif

	return returnValue;
}
// System.Void BoundarySystem_Ext.Pvr_BoundaryAPI::Pvr_ResetVrModebyForce()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_BoundaryAPI_Pvr_ResetVrModebyForce_m4765B51C2360FED37DDDF6B1E099D496862762F1 (const RuntimeMethod* method) 
{
	typedef void (CDECL *PInvokeFunc) ();
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = 0;
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("Pvr_UnitySDK"), "Pvr_ResetVrModebyForce", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
	reinterpret_cast<PInvokeFunc>(Pvr_ResetVrModebyForce)();
	#else
	il2cppPInvokeFunc();
	#endif

}
// System.Boolean BoundarySystem_Ext.Pvr_BoundaryAPI::Pvr_ResumeBoundaryForSTS()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Pvr_BoundaryAPI_Pvr_ResumeBoundaryForSTS_m06A9BD2FF0203CB84BE1B8F0BBA175A6A6851908 (const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) ();
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = 0;
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("Pvr_UnitySDK"), "Pvr_ResumeBoundaryForSTS", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(Pvr_ResumeBoundaryForSTS)();
	#else
	int32_t returnValue = il2cppPInvokeFunc();
	#endif

	return static_cast<bool>(returnValue);
}
// System.Void BoundarySystem_Ext.Pvr_BoundaryAPI::Pvr_PauseBoundaryForSTS()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_BoundaryAPI_Pvr_PauseBoundaryForSTS_mD10EB55298A054955FB95D086565543EEFA6883A (const RuntimeMethod* method) 
{
	typedef void (CDECL *PInvokeFunc) ();
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = 0;
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("Pvr_UnitySDK"), "Pvr_PauseBoundaryForSTS", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
	reinterpret_cast<PInvokeFunc>(Pvr_PauseBoundaryForSTS)();
	#else
	il2cppPInvokeFunc();
	#endif

}
// System.Void BoundarySystem_Ext.Pvr_BoundaryAPI::Pvr_DisableBoundary()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_BoundaryAPI_Pvr_DisableBoundary_mAF9486035CB9BABC00F4DF8721A3DAA6485D99EE (const RuntimeMethod* method) 
{
	typedef void (CDECL *PInvokeFunc) ();
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = 0;
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("Pvr_UnitySDK"), "Pvr_DisableBoundary", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
	reinterpret_cast<PInvokeFunc>(Pvr_DisableBoundary)();
	#else
	il2cppPInvokeFunc();
	#endif

}
// System.Void BoundarySystem_Ext.Pvr_BoundaryAPI::Pvr_BoundarySetSTBackground()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_BoundaryAPI_Pvr_BoundarySetSTBackground_m562BC298818979E6B757E4DD403348976A8CCD09 (const RuntimeMethod* method) 
{
	typedef void (CDECL *PInvokeFunc) ();
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = 0;
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("Pvr_UnitySDK"), "Pvr_BoundarySetSTBackground", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_Pvr_UnitySDK_INTERNAL
	reinterpret_cast<PInvokeFunc>(Pvr_BoundarySetSTBackground)();
	#else
	il2cppPInvokeFunc();
	#endif

}
// System.Int32 BoundarySystem_Ext.Pvr_BoundaryAPI::UPvr_GetMainSensorStateExt(System.Single&,System.Single&,System.Single&,System.Single&,System.Single&,System.Single&,System.Single&,System.Single&,System.Single&,System.Int32&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_BoundaryAPI_UPvr_GetMainSensorStateExt_mD540D5557CA72FBB6AD3D6AE76418C4EB5186A5A (float* ___0_x, float* ___1_y, float* ___2_z, float* ___3_w, float* ___4_px, float* ___5_py, float* ___6_pz, float* ___7_vfov, float* ___8_hfov, int32_t* ___9_viewNumber, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		// return Pvr_GetMainSensorStateExt(ref x, ref y, ref z, ref w, ref px, ref py, ref pz, ref vfov, ref hfov, ref viewNumber);
		float* L_0 = ___0_x;
		float* L_1 = ___1_y;
		float* L_2 = ___2_z;
		float* L_3 = ___3_w;
		float* L_4 = ___4_px;
		float* L_5 = ___5_py;
		float* L_6 = ___6_pz;
		float* L_7 = ___7_vfov;
		float* L_8 = ___8_hfov;
		int32_t* L_9 = ___9_viewNumber;
		int32_t L_10;
		L_10 = Pvr_BoundaryAPI_Pvr_GetMainSensorStateExt_m321C1D462B4E5376D3CD28EB5DA3AC024EAD6085(L_0, L_1, L_2, L_3, L_4, L_5, L_6, L_7, L_8, L_9, NULL);
		V_0 = L_10;
		goto IL_0019;
	}

IL_0019:
	{
		// }
		int32_t L_11 = V_0;
		return L_11;
	}
}
// System.IntPtr BoundarySystem_Ext.Pvr_BoundaryAPI::UPvr_GetCameraData_Ext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t Pvr_BoundaryAPI_UPvr_GetCameraData_Ext_mCC38F9DCC4669679EF0FBBC3CDE29B0123374973 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	intptr_t V_0;
	memset((&V_0), 0, sizeof(V_0));
	intptr_t V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		// IntPtr ptr = IntPtr.Zero;
		intptr_t L_0 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		V_0 = L_0;
		// ptr = Pvr_GetCameraData_Ext();
		intptr_t L_1;
		L_1 = Pvr_BoundaryAPI_Pvr_GetCameraData_Ext_m2AD3E265FAD65F33A3FBEEDFEDF9F496CFF788B5(NULL);
		V_0 = L_1;
		// return ptr;
		intptr_t L_2 = V_0;
		V_1 = L_2;
		goto IL_0011;
	}

IL_0011:
	{
		// }
		intptr_t L_3 = V_1;
		return L_3;
	}
}
// System.Boolean BoundarySystem_Ext.Pvr_BoundaryAPI::UPvr_ResumeBoundaryForSTS()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Pvr_BoundaryAPI_UPvr_ResumeBoundaryForSTS_m033EEE3F07E07FDDC4452DAC11F6F3AB2895B201 (const RuntimeMethod* method) 
{
	bool V_0 = false;
	bool V_1 = false;
	{
		// bool ret = false;
		V_0 = (bool)0;
		// ret = Pvr_ResumeBoundaryForSTS();
		bool L_0;
		L_0 = Pvr_BoundaryAPI_Pvr_ResumeBoundaryForSTS_m06A9BD2FF0203CB84BE1B8F0BBA175A6A6851908(NULL);
		V_0 = L_0;
		// return ret;
		bool L_1 = V_0;
		V_1 = L_1;
		goto IL_000d;
	}

IL_000d:
	{
		// }
		bool L_2 = V_1;
		return L_2;
	}
}
// System.Void BoundarySystem_Ext.Pvr_BoundaryAPI::UPvr_PauseBoundaryForSTS()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_BoundaryAPI_UPvr_PauseBoundaryForSTS_m326331FE0CAC03B490598AB1AADC6F13089F9AF6 (const RuntimeMethod* method) 
{
	{
		// Pvr_PauseBoundaryForSTS();
		Pvr_BoundaryAPI_Pvr_PauseBoundaryForSTS_mD10EB55298A054955FB95D086565543EEFA6883A(NULL);
		// }
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSAInit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_GSAInit_mA3C9B395453CB6E9C2BC1F919A5E2DA76BE64D47 (const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) ();
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_SafetyArea_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = 0;
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("SafetyArea"), "GSAInit", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(GSAInit)();
	#else
	int32_t returnValue = il2cppPInvokeFunc();
	#endif

	return returnValue;
}
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSAInit(System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_GSAInit_m53EB258F87415DFACB6158CB1795715B6133F7D6 (int32_t ___0_width, int32_t ___1_height, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (int32_t, int32_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_SafetyArea_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(int32_t) + sizeof(int32_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("SafetyArea"), "GSAInit", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(GSAInit)(___0_width, ___1_height);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_width, ___1_height);
	#endif

	return returnValue;
}
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSAShutDown()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_GSAShutDown_m762ABA1ABA78A161A2EC88F465CA19A5575D447C (const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) ();
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_SafetyArea_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = 0;
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("SafetyArea"), "GSAShutDown", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(GSAShutDown)();
	#else
	int32_t returnValue = il2cppPInvokeFunc();
	#endif

	return returnValue;
}
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSASetCallback(BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_GSASetCallback_m2CA2BA1908468D19A690D97286CD5B03B61C7745 (SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C* ___0_cb, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (Il2CppMethodPointer);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_SafetyArea_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(void*);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("SafetyArea"), "GSASetCallback", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Marshaling of parameter '___0_cb' to native representation
	Il2CppMethodPointer ____0_cb_marshaled = NULL;
	____0_cb_marshaled = il2cpp_codegen_marshal_delegate(reinterpret_cast<MulticastDelegate_t*>(___0_cb));

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(GSASetCallback)(____0_cb_marshaled);
	#else
	int32_t returnValue = il2cppPInvokeFunc(____0_cb_marshaled);
	#endif

	return returnValue;
}
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSASetCallbackShrink(BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallbackShrink)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_GSASetCallbackShrink_m836980D9F1557C2C112557ED4E78DE0F3F47034A (SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754* ___0_cb, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (Il2CppMethodPointer);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_SafetyArea_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(void*);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("SafetyArea"), "GSASetCallbackShrink", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Marshaling of parameter '___0_cb' to native representation
	Il2CppMethodPointer ____0_cb_marshaled = NULL;
	____0_cb_marshaled = il2cpp_codegen_marshal_delegate(reinterpret_cast<MulticastDelegate_t*>(___0_cb));

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(GSASetCallbackShrink)(____0_cb_marshaled);
	#else
	int32_t returnValue = il2cppPInvokeFunc(____0_cb_marshaled);
	#endif

	return returnValue;
}
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSAUpDateData(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_GSAUpDateData_m5AA2B1CB047F9EEC6A21C0EA0A60D9BD7D0D943B (intptr_t ___0_lineCollectionPtr, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_SafetyArea_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("SafetyArea"), "GSAUpDateData", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(GSAUpDateData)(___0_lineCollectionPtr);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_lineCollectionPtr);
	#endif

	return returnValue;
}
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSASetConfigFilePath(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_GSASetConfigFilePath_m1AE31E958500B9264A963CC5F3DF983B81FD9304 (intptr_t ___0_configPath, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_SafetyArea_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("SafetyArea"), "GSASetConfigFilePath", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(GSASetConfigFilePath)(___0_configPath);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_configPath);
	#endif

	return returnValue;
}
// System.Boolean BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSAGetClosedAreaUpdateFlag()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Pvr_SafeAreaAlgoAPI_GSAGetClosedAreaUpdateFlag_m309CA1FD4FA9C0FABD416D3B6A40DF992DD98AE4 (const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) ();
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_SafetyArea_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = 0;
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("SafetyArea"), "GSAGetClosedAreaUpdateFlag", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(GSAGetClosedAreaUpdateFlag)();
	#else
	int32_t returnValue = il2cppPInvokeFunc();
	#endif

	return static_cast<bool>(returnValue);
}
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSALoadSafetyArea(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_GSALoadSafetyArea_m79C5644419EDE0B858486289AD937ABAA56017A3 (intptr_t ___0_lineCollectionPtr, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_SafetyArea_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("SafetyArea"), "GSALoadSafetyArea", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(GSALoadSafetyArea)(___0_lineCollectionPtr);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_lineCollectionPtr);
	#endif

	return returnValue;
}
// System.Double BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSABoundaryDetector(BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Pvr_SafeAreaAlgoAPI_GSABoundaryDetector_m3C4D62E7071EFEB4139B3BA4F6AE8E8DA66149EA (GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17* ___0_pointPtr, const RuntimeMethod* method) 
{
	typedef double (CDECL *PInvokeFunc) (GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17*);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_SafetyArea_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17*);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("SafetyArea"), "GSABoundaryDetector", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
	double returnValue = reinterpret_cast<PInvokeFunc>(GSABoundaryDetector)(___0_pointPtr);
	#else
	double returnValue = il2cppPInvokeFunc(___0_pointPtr);
	#endif

	return returnValue;
}
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSALoadSafetyArea2(System.IntPtr,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_GSALoadSafetyArea2_m6AEA62E27C5DEF48885DAA27F3047B743A2244DA (intptr_t ___0_lineCollectionPtr, bool ___1_isPlayArea, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t, int32_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_SafetyArea_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t) + 4;
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("SafetyArea"), "GSALoadSafetyArea2", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(GSALoadSafetyArea2)(___0_lineCollectionPtr, static_cast<int32_t>(___1_isPlayArea));
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_lineCollectionPtr, static_cast<int32_t>(___1_isPlayArea));
	#endif

	return returnValue;
}
// System.Double BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::GSABoundaryDetector2(BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i&,System.Boolean,BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i&,BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Pvr_SafeAreaAlgoAPI_GSABoundaryDetector2_m46B39B06530845701CCD110AD32A221A1FAB3EAC (GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17* ___0_point, bool ___1_isPlayArea, GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17* ___2_closestPoint, GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17* ___3_normalDir, const RuntimeMethod* method) 
{
	typedef double (CDECL *PInvokeFunc) (GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17*, int32_t, GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17*, GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17*);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_SafetyArea_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17*) + 4 + sizeof(GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17*) + sizeof(GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17*);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("SafetyArea"), "GSABoundaryDetector2", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	// Native function invocation
	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_SafetyArea_INTERNAL
	double returnValue = reinterpret_cast<PInvokeFunc>(GSABoundaryDetector2)(___0_point, static_cast<int32_t>(___1_isPlayArea), ___2_closestPoint, ___3_normalDir);
	#else
	double returnValue = il2cppPInvokeFunc(___0_point, static_cast<int32_t>(___1_isPlayArea), ___2_closestPoint, ___3_normalDir);
	#endif

	return returnValue;
}
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::Pvr_GSAInit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_Pvr_GSAInit_m1C17FA05C9A9943779823DEA64EBACDAC863CF86 (const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		// int ret = -1;
		V_0 = (-1);
		// ret = GSAInit();
		int32_t L_0;
		L_0 = Pvr_SafeAreaAlgoAPI_GSAInit_mA3C9B395453CB6E9C2BC1F919A5E2DA76BE64D47(NULL);
		V_0 = L_0;
		// return ret;
		int32_t L_1 = V_0;
		V_1 = L_1;
		goto IL_000d;
	}

IL_000d:
	{
		// }
		int32_t L_2 = V_1;
		return L_2;
	}
}
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::Pvr_GSAInit(System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_Pvr_GSAInit_m0FD61C053CACCEFCFCA5DC2A8C76C2DCD6D44E6C (int32_t ___0_width, int32_t ___1_height, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	Exception_t* V_1 = NULL;
	int32_t V_2 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		// int ret = -1;
		V_0 = (-1);
	}
	try
	{// begin try (depth: 1)
		// ret = GSAInit(width, height);
		int32_t L_0 = ___0_width;
		int32_t L_1 = ___1_height;
		int32_t L_2;
		L_2 = Pvr_SafeAreaAlgoAPI_GSAInit_m53EB258F87415DFACB6158CB1795715B6133F7D6(L_0, L_1, NULL);
		V_0 = L_2;
		goto IL_0017;
	}// end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000f;
		}
		throw e;
	}

CATCH_000f:
	{// begin catch(System.Exception)
		Exception_t* L_3 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		// catch (Exception e)
		V_1 = L_3;
		// ret = -2;
		V_0 = ((int32_t)-2);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0017;
	}// end catch (depth: 1)

IL_0017:
	{
		// return ret;
		int32_t L_4 = V_0;
		V_2 = L_4;
		goto IL_001b;
	}

IL_001b:
	{
		// }
		int32_t L_5 = V_2;
		return L_5;
	}
}
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::Pvr_GSASetCallback(BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_Pvr_GSASetCallback_mB2E1844A1B9CDF0C7B60BB0D004CCC69B0193EB5 (SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C* ___0_cb, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		// int ret = -1;
		V_0 = (-1);
		// ret = GSASetCallback(cb);
		SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C* L_0 = ___0_cb;
		int32_t L_1;
		L_1 = Pvr_SafeAreaAlgoAPI_GSASetCallback_m2CA2BA1908468D19A690D97286CD5B03B61C7745(L_0, NULL);
		V_0 = L_1;
		// return ret;
		int32_t L_2 = V_0;
		V_1 = L_2;
		goto IL_000e;
	}

IL_000e:
	{
		// }
		int32_t L_3 = V_1;
		return L_3;
	}
}
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::Pvr_GSASetCallbackShrink(BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallbackShrink)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_Pvr_GSASetCallbackShrink_m15C7B66FFD3672FC085E8608D2AAED9AF94EB8E2 (SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754* ___0_cb, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		// int ret = -1;
		V_0 = (-1);
		// ret = GSASetCallbackShrink(cb);
		SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754* L_0 = ___0_cb;
		int32_t L_1;
		L_1 = Pvr_SafeAreaAlgoAPI_GSASetCallbackShrink_m836980D9F1557C2C112557ED4E78DE0F3F47034A(L_0, NULL);
		V_0 = L_1;
		// return ret;
		int32_t L_2 = V_0;
		V_1 = L_2;
		goto IL_000e;
	}

IL_000e:
	{
		// }
		int32_t L_3 = V_1;
		return L_3;
	}
}
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::Pvr_GSAUpDateData(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_Pvr_GSAUpDateData_m2075353F1784E7877960B0A2BB9D98041C856D90 (intptr_t ___0_lineCollectionPtr, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		// int ret = -1;
		V_0 = (-1);
		// ret = GSAUpDateData(lineCollectionPtr);
		intptr_t L_0 = ___0_lineCollectionPtr;
		int32_t L_1;
		L_1 = Pvr_SafeAreaAlgoAPI_GSAUpDateData_m5AA2B1CB047F9EEC6A21C0EA0A60D9BD7D0D943B(L_0, NULL);
		V_0 = L_1;
		// return ret;
		int32_t L_2 = V_0;
		V_1 = L_2;
		goto IL_000e;
	}

IL_000e:
	{
		// }
		int32_t L_3 = V_1;
		return L_3;
	}
}
// System.Boolean BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::Pvr_GSAGetClosedAreaUpdateFlag()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Pvr_SafeAreaAlgoAPI_Pvr_GSAGetClosedAreaUpdateFlag_mE9F3925D6F95128EA4DD6D68DF2394A243257D00 (const RuntimeMethod* method) 
{
	bool V_0 = false;
	bool V_1 = false;
	{
		// bool ret = false;
		V_0 = (bool)0;
		// ret = GSAGetClosedAreaUpdateFlag();
		bool L_0;
		L_0 = Pvr_SafeAreaAlgoAPI_GSAGetClosedAreaUpdateFlag_m309CA1FD4FA9C0FABD416D3B6A40DF992DD98AE4(NULL);
		V_0 = L_0;
		// return ret;
		bool L_1 = V_0;
		V_1 = L_1;
		goto IL_000d;
	}

IL_000d:
	{
		// }
		bool L_2 = V_1;
		return L_2;
	}
}
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::Pvr_GSASetConfigFilePath(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_Pvr_GSASetConfigFilePath_mB05651C1C63E6FCA999296247C95F92857FEF740 (String_t* ___0_configPath, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	intptr_t V_1;
	memset((&V_1), 0, sizeof(V_1));
	int32_t V_2 = 0;
	{
		// int ret = -1;
		V_0 = (-1);
		// IntPtr pathPtr = Marshal.StringToHGlobalAnsi(configPath);
		String_t* L_0 = ___0_configPath;
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		intptr_t L_1;
		L_1 = Marshal_StringToHGlobalAnsi_mE6070591B7CC1DC279324657D93B6EB0FD4CACDD(L_0, NULL);
		V_1 = L_1;
		// ret = GSASetConfigFilePath(pathPtr);
		intptr_t L_2 = V_1;
		int32_t L_3;
		L_3 = Pvr_SafeAreaAlgoAPI_GSASetConfigFilePath_m1AE31E958500B9264A963CC5F3DF983B81FD9304(L_2, NULL);
		V_0 = L_3;
		// Marshal.FreeHGlobal(pathPtr);
		intptr_t L_4 = V_1;
		Marshal_FreeHGlobal_m298EF0650E82E326EDA8048488DC384BB9171EB9(L_4, NULL);
		// return ret;
		int32_t L_5 = V_0;
		V_2 = L_5;
		goto IL_001c;
	}

IL_001c:
	{
		// }
		int32_t L_6 = V_2;
		return L_6;
	}
}
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::Pvr_GSALoadSafetyArea(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_Pvr_GSALoadSafetyArea_m3AF753A1A73BE22326634E7D672BA7DA97A4CDF6 (intptr_t ___0_lineCollectionPtr, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		// int ret = -1;
		V_0 = (-1);
		// ret = GSALoadSafetyArea(lineCollectionPtr);
		intptr_t L_0 = ___0_lineCollectionPtr;
		int32_t L_1;
		L_1 = Pvr_SafeAreaAlgoAPI_GSALoadSafetyArea_m79C5644419EDE0B858486289AD937ABAA56017A3(L_0, NULL);
		V_0 = L_1;
		// return ret;
		int32_t L_2 = V_0;
		V_1 = L_2;
		goto IL_000e;
	}

IL_000e:
	{
		// }
		int32_t L_3 = V_1;
		return L_3;
	}
}
// System.Double BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::Pvr_GSABoundaryDetector(BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Pvr_SafeAreaAlgoAPI_Pvr_GSABoundaryDetector_mE4BC4C704D06B0F3B33987BA59E5B63618570308 (GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17* ___0_point, const RuntimeMethod* method) 
{
	double V_0 = 0.0;
	double V_1 = 0.0;
	{
		// double distance = 0;
		V_0 = (0.0);
		// distance = GSABoundaryDetector(ref point);
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17* L_0 = ___0_point;
		double L_1;
		L_1 = Pvr_SafeAreaAlgoAPI_GSABoundaryDetector_m3C4D62E7071EFEB4139B3BA4F6AE8E8DA66149EA(L_0, NULL);
		V_0 = L_1;
		// return distance;
		double L_2 = V_0;
		V_1 = L_2;
		goto IL_0016;
	}

IL_0016:
	{
		// }
		double L_3 = V_1;
		return L_3;
	}
}
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::Pvr_GSAShutDown()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_Pvr_GSAShutDown_mE515E181C0D3FF1EBB0EC648F2C8C31E2D17CE3B (const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		// int ret = -1;
		V_0 = (-1);
		// ret = GSAShutDown();
		int32_t L_0;
		L_0 = Pvr_SafeAreaAlgoAPI_GSAShutDown_m762ABA1ABA78A161A2EC88F465CA19A5575D447C(NULL);
		V_0 = L_0;
		// return ret;
		int32_t L_1 = V_0;
		V_1 = L_1;
		goto IL_000d;
	}

IL_000d:
	{
		// }
		int32_t L_2 = V_1;
		return L_2;
	}
}
// System.Int32 BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::Pvr_GSALoadSafetyArea2(System.IntPtr,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Pvr_SafeAreaAlgoAPI_Pvr_GSALoadSafetyArea2_m5B0012AF5D9C290F8C7FD06A2724EF40493350F6 (intptr_t ___0_lineCollectionPtr, bool ___1_isPlayArea, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		// int ret = -1;
		V_0 = (-1);
		// ret = GSALoadSafetyArea2(lineCollectionPtr, isPlayArea);
		intptr_t L_0 = ___0_lineCollectionPtr;
		bool L_1 = ___1_isPlayArea;
		int32_t L_2;
		L_2 = Pvr_SafeAreaAlgoAPI_GSALoadSafetyArea2_m6AEA62E27C5DEF48885DAA27F3047B743A2244DA(L_0, L_1, NULL);
		V_0 = L_2;
		// return ret;
		int32_t L_3 = V_0;
		V_1 = L_3;
		goto IL_000f;
	}

IL_000f:
	{
		// }
		int32_t L_4 = V_1;
		return L_4;
	}
}
// System.Double BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI::Pvr_GSABoundaryDetector2(BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i&,System.Boolean,BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i&,BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/GSAPoint3i&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Pvr_SafeAreaAlgoAPI_Pvr_GSABoundaryDetector2_m0009C8B90F40C2EDDD744D468E5F3EC0AFCEFAFD (GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17* ___0_point, bool ___1_isPlayArea, GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17* ___2_closestPoint, GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17* ___3_normalDir, const RuntimeMethod* method) 
{
	double V_0 = 0.0;
	double V_1 = 0.0;
	{
		// double distance = 0;
		V_0 = (0.0);
		// distance = GSABoundaryDetector2(ref point, isPlayArea, ref closestPoint, ref normalDir);
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17* L_0 = ___0_point;
		bool L_1 = ___1_isPlayArea;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17* L_2 = ___2_closestPoint;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17* L_3 = ___3_normalDir;
		double L_4;
		L_4 = Pvr_SafeAreaAlgoAPI_GSABoundaryDetector2_m46B39B06530845701CCD110AD32A221A1FAB3EAC(L_0, L_1, L_2, L_3, NULL);
		V_0 = L_4;
		// return distance;
		double L_5 = V_0;
		V_1 = L_5;
		goto IL_0019;
	}

IL_0019:
	{
		// }
		double L_6 = V_1;
		return L_6;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void SafeAreaCallback_Invoke_m829AC1E165CD0E4D7302E819FC38C922BB4A6419_Multicast(SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C* __this, intptr_t ___0_lineCollectionPtr, intptr_t ___1_safeAreaRectPtr, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates_13->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates_13->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C* currentDelegate = reinterpret_cast<SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, intptr_t, intptr_t, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl_1)((Il2CppObject*)currentDelegate->___method_code_6, ___0_lineCollectionPtr, ___1_safeAreaRectPtr, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method_3));
	}
}
void SafeAreaCallback_Invoke_m829AC1E165CD0E4D7302E819FC38C922BB4A6419_OpenInst(SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C* __this, intptr_t ___0_lineCollectionPtr, intptr_t ___1_safeAreaRectPtr, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (intptr_t, intptr_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___0_lineCollectionPtr, ___1_safeAreaRectPtr, method);
}
void SafeAreaCallback_Invoke_m829AC1E165CD0E4D7302E819FC38C922BB4A6419_OpenStatic(SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C* __this, intptr_t ___0_lineCollectionPtr, intptr_t ___1_safeAreaRectPtr, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (intptr_t, intptr_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___0_lineCollectionPtr, ___1_safeAreaRectPtr, method);
}
void SafeAreaCallback_Invoke_m829AC1E165CD0E4D7302E819FC38C922BB4A6419_OpenStaticInvoker(SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C* __this, intptr_t ___0_lineCollectionPtr, intptr_t ___1_safeAreaRectPtr, const RuntimeMethod* method)
{
	InvokerActionInvoker2< intptr_t, intptr_t >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, ___0_lineCollectionPtr, ___1_safeAreaRectPtr);
}
void SafeAreaCallback_Invoke_m829AC1E165CD0E4D7302E819FC38C922BB4A6419_ClosedStaticInvoker(SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C* __this, intptr_t ___0_lineCollectionPtr, intptr_t ___1_safeAreaRectPtr, const RuntimeMethod* method)
{
	InvokerActionInvoker3< RuntimeObject*, intptr_t, intptr_t >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, __this->___m_target_2, ___0_lineCollectionPtr, ___1_safeAreaRectPtr);
}
IL2CPP_EXTERN_C  void DelegatePInvokeWrapper_SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C (SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C* __this, intptr_t ___0_lineCollectionPtr, intptr_t ___1_safeAreaRectPtr, const RuntimeMethod* method)
{
	typedef void (CDECL *PInvokeFunc)(intptr_t, intptr_t);
	PInvokeFunc il2cppPInvokeFunc = reinterpret_cast<PInvokeFunc>(il2cpp_codegen_get_reverse_pinvoke_function_ptr(__this));
	// Native function invocation
	il2cppPInvokeFunc(___0_lineCollectionPtr, ___1_safeAreaRectPtr);

}
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallback::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SafeAreaCallback__ctor_m5D6D26CADFF88B9822C7CBCEEC1C4C19244A8FF1 (SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr_0 = (intptr_t)il2cpp_codegen_get_virtual_call_method_pointer((RuntimeMethod*)___1_method);
	__this->___method_3 = ___1_method;
	__this->___m_target_2 = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target_2), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code_6 = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 2;
		if (il2cpp_codegen_call_method_via_invoker((RuntimeMethod*)___1_method))
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&SafeAreaCallback_Invoke_m829AC1E165CD0E4D7302E819FC38C922BB4A6419_OpenStaticInvoker;
			else
				__this->___invoke_impl_1 = (intptr_t)&SafeAreaCallback_Invoke_m829AC1E165CD0E4D7302E819FC38C922BB4A6419_ClosedStaticInvoker;
		else
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&SafeAreaCallback_Invoke_m829AC1E165CD0E4D7302E819FC38C922BB4A6419_OpenStatic;
			else
				{
					__this->___invoke_impl_1 = __this->___method_ptr_0;
					__this->___method_code_6 = (intptr_t)__this->___m_target_2;
				}
	}
	else
	{
		if (___0_object == NULL)
			il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
		__this->___invoke_impl_1 = __this->___method_ptr_0;
		__this->___method_code_6 = (intptr_t)__this->___m_target_2;
	}
	__this->___extra_arg_5 = (intptr_t)&SafeAreaCallback_Invoke_m829AC1E165CD0E4D7302E819FC38C922BB4A6419_Multicast;
}
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallback::Invoke(System.IntPtr,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SafeAreaCallback_Invoke_m829AC1E165CD0E4D7302E819FC38C922BB4A6419 (SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C* __this, intptr_t ___0_lineCollectionPtr, intptr_t ___1_safeAreaRectPtr, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, intptr_t, intptr_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_lineCollectionPtr, ___1_safeAreaRectPtr, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
// System.IAsyncResult BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallback::BeginInvoke(System.IntPtr,System.IntPtr,System.AsyncCallback,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* SafeAreaCallback_BeginInvoke_m34880A33E1E7C63F6F5D2E7B2DADB9169D7C76C9 (SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C* __this, intptr_t ___0_lineCollectionPtr, intptr_t ___1_safeAreaRectPtr, AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___2_callback, RuntimeObject* ___3_object, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	void *__d_args[3] = {0};
	__d_args[0] = Box(IntPtr_t_il2cpp_TypeInfo_var, &___0_lineCollectionPtr);
	__d_args[1] = Box(IntPtr_t_il2cpp_TypeInfo_var, &___1_safeAreaRectPtr);
	return (RuntimeObject*)il2cpp_codegen_delegate_begin_invoke((RuntimeDelegate*)__this, __d_args, (RuntimeDelegate*)___2_callback, (RuntimeObject*)___3_object);
}
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallback::EndInvoke(System.IAsyncResult)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SafeAreaCallback_EndInvoke_mDDAC4C4D4406243C670E0C0D556D750258C58E4B (SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C* __this, RuntimeObject* ___0_result, const RuntimeMethod* method) 
{
	il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___0_result, 0);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void SafeAreaCallbackShrink_Invoke_m42C510152D60D2AEAAB3EBC0D8359F6DE61EEBE0_Multicast(SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754* __this, intptr_t ___0_lineCollectionPtr, intptr_t ___1_safeAreaDetailRectPtr, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates_13->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates_13->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754* currentDelegate = reinterpret_cast<SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, intptr_t, intptr_t, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl_1)((Il2CppObject*)currentDelegate->___method_code_6, ___0_lineCollectionPtr, ___1_safeAreaDetailRectPtr, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method_3));
	}
}
void SafeAreaCallbackShrink_Invoke_m42C510152D60D2AEAAB3EBC0D8359F6DE61EEBE0_OpenInst(SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754* __this, intptr_t ___0_lineCollectionPtr, intptr_t ___1_safeAreaDetailRectPtr, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (intptr_t, intptr_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___0_lineCollectionPtr, ___1_safeAreaDetailRectPtr, method);
}
void SafeAreaCallbackShrink_Invoke_m42C510152D60D2AEAAB3EBC0D8359F6DE61EEBE0_OpenStatic(SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754* __this, intptr_t ___0_lineCollectionPtr, intptr_t ___1_safeAreaDetailRectPtr, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (intptr_t, intptr_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___0_lineCollectionPtr, ___1_safeAreaDetailRectPtr, method);
}
void SafeAreaCallbackShrink_Invoke_m42C510152D60D2AEAAB3EBC0D8359F6DE61EEBE0_OpenStaticInvoker(SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754* __this, intptr_t ___0_lineCollectionPtr, intptr_t ___1_safeAreaDetailRectPtr, const RuntimeMethod* method)
{
	InvokerActionInvoker2< intptr_t, intptr_t >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, ___0_lineCollectionPtr, ___1_safeAreaDetailRectPtr);
}
void SafeAreaCallbackShrink_Invoke_m42C510152D60D2AEAAB3EBC0D8359F6DE61EEBE0_ClosedStaticInvoker(SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754* __this, intptr_t ___0_lineCollectionPtr, intptr_t ___1_safeAreaDetailRectPtr, const RuntimeMethod* method)
{
	InvokerActionInvoker3< RuntimeObject*, intptr_t, intptr_t >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, __this->___m_target_2, ___0_lineCollectionPtr, ___1_safeAreaDetailRectPtr);
}
IL2CPP_EXTERN_C  void DelegatePInvokeWrapper_SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754 (SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754* __this, intptr_t ___0_lineCollectionPtr, intptr_t ___1_safeAreaDetailRectPtr, const RuntimeMethod* method)
{
	typedef void (CDECL *PInvokeFunc)(intptr_t, intptr_t);
	PInvokeFunc il2cppPInvokeFunc = reinterpret_cast<PInvokeFunc>(il2cpp_codegen_get_reverse_pinvoke_function_ptr(__this));
	// Native function invocation
	il2cppPInvokeFunc(___0_lineCollectionPtr, ___1_safeAreaDetailRectPtr);

}
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallbackShrink::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SafeAreaCallbackShrink__ctor_m2665B8A76BA57763E8388611BA10C568215F7343 (SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr_0 = (intptr_t)il2cpp_codegen_get_virtual_call_method_pointer((RuntimeMethod*)___1_method);
	__this->___method_3 = ___1_method;
	__this->___m_target_2 = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target_2), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code_6 = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 2;
		if (il2cpp_codegen_call_method_via_invoker((RuntimeMethod*)___1_method))
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&SafeAreaCallbackShrink_Invoke_m42C510152D60D2AEAAB3EBC0D8359F6DE61EEBE0_OpenStaticInvoker;
			else
				__this->___invoke_impl_1 = (intptr_t)&SafeAreaCallbackShrink_Invoke_m42C510152D60D2AEAAB3EBC0D8359F6DE61EEBE0_ClosedStaticInvoker;
		else
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&SafeAreaCallbackShrink_Invoke_m42C510152D60D2AEAAB3EBC0D8359F6DE61EEBE0_OpenStatic;
			else
				{
					__this->___invoke_impl_1 = __this->___method_ptr_0;
					__this->___method_code_6 = (intptr_t)__this->___m_target_2;
				}
	}
	else
	{
		if (___0_object == NULL)
			il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
		__this->___invoke_impl_1 = __this->___method_ptr_0;
		__this->___method_code_6 = (intptr_t)__this->___m_target_2;
	}
	__this->___extra_arg_5 = (intptr_t)&SafeAreaCallbackShrink_Invoke_m42C510152D60D2AEAAB3EBC0D8359F6DE61EEBE0_Multicast;
}
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallbackShrink::Invoke(System.IntPtr,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SafeAreaCallbackShrink_Invoke_m42C510152D60D2AEAAB3EBC0D8359F6DE61EEBE0 (SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754* __this, intptr_t ___0_lineCollectionPtr, intptr_t ___1_safeAreaDetailRectPtr, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, intptr_t, intptr_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_lineCollectionPtr, ___1_safeAreaDetailRectPtr, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
// System.IAsyncResult BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallbackShrink::BeginInvoke(System.IntPtr,System.IntPtr,System.AsyncCallback,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* SafeAreaCallbackShrink_BeginInvoke_m3A1911E2E403C7C6ECFB3B4B7A7F12DB5B304CEF (SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754* __this, intptr_t ___0_lineCollectionPtr, intptr_t ___1_safeAreaDetailRectPtr, AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___2_callback, RuntimeObject* ___3_object, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	void *__d_args[3] = {0};
	__d_args[0] = Box(IntPtr_t_il2cpp_TypeInfo_var, &___0_lineCollectionPtr);
	__d_args[1] = Box(IntPtr_t_il2cpp_TypeInfo_var, &___1_safeAreaDetailRectPtr);
	return (RuntimeObject*)il2cpp_codegen_delegate_begin_invoke((RuntimeDelegate*)__this, __d_args, (RuntimeDelegate*)___2_callback, (RuntimeObject*)___3_object);
}
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoAPI/SafeAreaCallbackShrink::EndInvoke(System.IAsyncResult)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SafeAreaCallbackShrink_EndInvoke_mBACBBB53D9E28ACEEEF5BB137E8FAB2D53EE718F (SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754* __this, RuntimeObject* ___0_result, const RuntimeMethod* method) 
{
	il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___0_result, 0);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// BoundarySystem_Ext.Pvr_BoundarySystem BoundarySystem_Ext.Pvr_BoundarySystem::get_Instance()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544* Pvr_BoundarySystem_get_Instance_m6632D5D2E9B3FFD524E3C8C40B92B968E084B246 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544* V_1 = NULL;
	{
		// if (instance == null)
		Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544* L_0 = ((Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544_StaticFields*)il2cpp_codegen_static_fields_for(Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544_il2cpp_TypeInfo_var))->___instance_0;
		V_0 = (bool)((((RuntimeObject*)(Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544*)L_0) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0019;
		}
	}
	{
		// instance = new Pvr_BoundarySystem();
		Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544* L_2 = (Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544*)il2cpp_codegen_object_new(Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		Pvr_BoundarySystem__ctor_mBE03F7817B4691380E14CDABB8075CDDDC0E23EE(L_2, NULL);
		((Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544_StaticFields*)il2cpp_codegen_static_fields_for(Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544_il2cpp_TypeInfo_var))->___instance_0 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&((Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544_StaticFields*)il2cpp_codegen_static_fields_for(Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544_il2cpp_TypeInfo_var))->___instance_0), (void*)L_2);
	}

IL_0019:
	{
		// return instance;
		Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544* L_3 = ((Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544_StaticFields*)il2cpp_codegen_static_fields_for(Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544_il2cpp_TypeInfo_var))->___instance_0;
		V_1 = L_3;
		goto IL_0021;
	}

IL_0021:
	{
		// }
		Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544* L_4 = V_1;
		return L_4;
	}
}
// System.Void BoundarySystem_Ext.Pvr_BoundarySystem::OpenBoundary()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_BoundarySystem_OpenBoundary_m115865934891518579972CA21426237EE44D3AD4 (Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544* __this, const RuntimeMethod* method) 
{
	{
		// Pvr_BoundaryAPI.Pvr_StartSDKBoundary();
		Pvr_BoundaryAPI_Pvr_StartSDKBoundary_mAF7538BF823A7DA40D4F3B7BADB6C012D202C8C7(NULL);
		// }
		return;
	}
}
// System.Void BoundarySystem_Ext.Pvr_BoundarySystem::CloseBoundary()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_BoundarySystem_CloseBoundary_mF8031C1C811F893EE85C8DBD23167C4563CD8C29 (Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544* __this, const RuntimeMethod* method) 
{
	{
		// Pvr_BoundaryAPI.Pvr_ShutdownSDKBoundary();
		Pvr_BoundaryAPI_Pvr_ShutdownSDKBoundary_mA1D0C393D07DB079468FFAB969390AFF8B0063B2(NULL);
		// }
		return;
	}
}
// System.Void BoundarySystem_Ext.Pvr_BoundarySystem::DisableBoundary()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_BoundarySystem_DisableBoundary_mCB6A586C020DD5153E8D322C932D299799C4A365 (Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544* __this, const RuntimeMethod* method) 
{
	{
		// Pvr_BoundaryAPI.Pvr_DisableBoundary();
		Pvr_BoundaryAPI_Pvr_DisableBoundary_mAF9486035CB9BABC00F4DF8721A3DAA6485D99EE(NULL);
		// }
		return;
	}
}
// System.Void BoundarySystem_Ext.Pvr_BoundarySystem::BoundarySetSTBackground()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_BoundarySystem_BoundarySetSTBackground_m7FA9725356632985828A445369D0BB232D4DAC15 (Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544* __this, const RuntimeMethod* method) 
{
	{
		// Pvr_BoundaryAPI.Pvr_BoundarySetSTBackground();
		Pvr_BoundaryAPI_Pvr_BoundarySetSTBackground_m562BC298818979E6B757E4DD403348976A8CCD09(NULL);
		// }
		return;
	}
}
// System.Void BoundarySystem_Ext.Pvr_BoundarySystem::Reset6Dof()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_BoundarySystem_Reset6Dof_mBCD8E384BBD1D952A89D87F00628464DF1CED032 (Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544* __this, const RuntimeMethod* method) 
{
	{
		// Pvr_BoundaryAPI.Pvr_ResetVrModebyForce();
		Pvr_BoundaryAPI_Pvr_ResetVrModebyForce_m4765B51C2360FED37DDDF6B1E099D496862762F1(NULL);
		// }
		return;
	}
}
// System.Void BoundarySystem_Ext.Pvr_BoundarySystem::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_BoundarySystem__ctor_mBE03F7817B4691380E14CDABB8075CDDDC0E23EE (Pvr_BoundarySystem_t1C69A1F66D17FCAF6901A225536057DEFC6DE544* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public IntPtr CameraFramePtr = IntPtr.Zero;
		intptr_t L_0 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		__this->___CameraFramePtr_3 = L_0;
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
extern "C" void CDECL ReversePInvokeWrapper_Pvr_SafeAreaAlgoModule__SafeAreaCallback_m756D201F90CFD3D062D71245E9C85697F8766969(intptr_t ___0_lineCollectionPtr, intptr_t ___1_safeAreaRectPtr)
{
	il2cpp::vm::ScopedThreadAttacher _vmThreadHelper;

	// Managed method invocation
	Pvr_SafeAreaAlgoModule__SafeAreaCallback_m756D201F90CFD3D062D71245E9C85697F8766969(___0_lineCollectionPtr, ___1_safeAreaRectPtr, NULL);

}
extern "C" void CDECL ReversePInvokeWrapper_Pvr_SafeAreaAlgoModule__SafeAreaCallbackShrink_m20C04C87D5E2E2708E462363D98BC4924BD3E354(intptr_t ___0_lineCollectionPtr, intptr_t ___1_safeAreaDetailRectPtr)
{
	il2cpp::vm::ScopedThreadAttacher _vmThreadHelper;

	// Managed method invocation
	Pvr_SafeAreaAlgoModule__SafeAreaCallbackShrink_m20C04C87D5E2E2708E462363D98BC4924BD3E354(___0_lineCollectionPtr, ___1_safeAreaDetailRectPtr, NULL);

}
// BoundarySystem_Ext.Pvr_SafeAreaAlgoModule BoundarySystem_Ext.Pvr_SafeAreaAlgoModule::get_Instance()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05* Pvr_SafeAreaAlgoModule_get_Instance_mC93B295F3817151AE7B84C66BC42B75E63F35445 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05* V_1 = NULL;
	{
		// if (instance == null)
		Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05* L_0 = ((Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05_StaticFields*)il2cpp_codegen_static_fields_for(Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05_il2cpp_TypeInfo_var))->___instance_0;
		V_0 = (bool)((((RuntimeObject*)(Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05*)L_0) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0019;
		}
	}
	{
		// instance = new Pvr_SafeAreaAlgoModule();
		Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05* L_2 = (Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05*)il2cpp_codegen_object_new(Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		Pvr_SafeAreaAlgoModule__ctor_mA8244BBC99C77398D1BC4BC85F483CF0A7AC8943(L_2, NULL);
		((Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05_StaticFields*)il2cpp_codegen_static_fields_for(Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05_il2cpp_TypeInfo_var))->___instance_0 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&((Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05_StaticFields*)il2cpp_codegen_static_fields_for(Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05_il2cpp_TypeInfo_var))->___instance_0), (void*)L_2);
	}

IL_0019:
	{
		// return instance;
		Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05* L_3 = ((Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05_StaticFields*)il2cpp_codegen_static_fields_for(Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05_il2cpp_TypeInfo_var))->___instance_0;
		V_1 = L_3;
		goto IL_0021;
	}

IL_0021:
	{
		// }
		Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05* L_4 = V_1;
		return L_4;
	}
}
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoModule::RegisterCallBack(BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundarySystemCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_SafeAreaAlgoModule_RegisterCallBack_mDB726D5A04E61321B1F9B65A9956FEE343EE80D6 (Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05* __this, BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD* ___0_callback, const RuntimeMethod* method) 
{
	{
		// this.boundarySystemCallback = callback;
		BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD* L_0 = ___0_callback;
		__this->___boundarySystemCallback_1 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___boundarySystemCallback_1), (void*)L_0);
		// }
		return;
	}
}
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoModule::RegisterCallBackShrink(BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundarySystemCallbackShrink)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_SafeAreaAlgoModule_RegisterCallBackShrink_mC12FA4FFE9D7EDC4EE5BC767C19C5BC5B975E56B (Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05* __this, BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75* ___0_callback, const RuntimeMethod* method) 
{
	{
		// this.boundarySystemCallbackShrink = callback;
		BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75* L_0 = ___0_callback;
		__this->___boundarySystemCallbackShrink_2 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___boundarySystemCallbackShrink_2), (void*)L_0);
		// }
		return;
	}
}
// System.Boolean BoundarySystem_Ext.Pvr_SafeAreaAlgoModule::Start(System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Pvr_SafeAreaAlgoModule_Start_m244A7D27FFD918710471E07D6459E556C5EC9B1E (Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05* __this, int32_t ___0_width, int32_t ___1_height, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Pvr_SafeAreaAlgoModule__SafeAreaCallbackShrink_m20C04C87D5E2E2708E462363D98BC4924BD3E354_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Pvr_SafeAreaAlgoModule__SafeAreaCallback_m756D201F90CFD3D062D71245E9C85697F8766969_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0B0D645C93F6D3B9458F33B2DFB8210A46C123F7);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7A805D623CF373F194487BF7035FA94ADF5E5C9B);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral81C5F640B84128CAF1CF95585CFC17A20C6F262A);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral8784BB62541B5BDD09FFAB9A87B1EBBE14156566);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralBC77136E09CE6E2CA8BC7074AD23EE15709847E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCA5A84BD2449CEC8316496E6966EF088F55F1688);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	bool V_3 = false;
	bool V_4 = false;
	bool V_5 = false;
	bool V_6 = false;
	int32_t G_B3_0 = 0;
	{
		// int ret1 = Pvr_SafeAreaAlgoAPI.Pvr_GSASetCallback(_SafeAreaCallback);
		SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C* L_0 = (SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C*)il2cpp_codegen_object_new(SafeAreaCallback_tBFBEDF7F7A874E95B560EA7AC69D7F357AE3511C_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		SafeAreaCallback__ctor_m5D6D26CADFF88B9822C7CBCEEC1C4C19244A8FF1(L_0, NULL, (intptr_t)((void*)Pvr_SafeAreaAlgoModule__SafeAreaCallback_m756D201F90CFD3D062D71245E9C85697F8766969_RuntimeMethod_var), NULL);
		int32_t L_1;
		L_1 = Pvr_SafeAreaAlgoAPI_Pvr_GSASetCallback_mB2E1844A1B9CDF0C7B60BB0D004CCC69B0193EB5(L_0, NULL);
		V_0 = L_1;
		// int ret2 = Pvr_SafeAreaAlgoAPI.Pvr_GSASetCallbackShrink(_SafeAreaCallbackShrink);
		SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754* L_2 = (SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754*)il2cpp_codegen_object_new(SafeAreaCallbackShrink_t25CA7C66F28435EC4D006891AAC562FCC050C754_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		SafeAreaCallbackShrink__ctor_m2665B8A76BA57763E8388611BA10C568215F7343(L_2, NULL, (intptr_t)((void*)Pvr_SafeAreaAlgoModule__SafeAreaCallbackShrink_m20C04C87D5E2E2708E462363D98BC4924BD3E354_RuntimeMethod_var), NULL);
		int32_t L_3;
		L_3 = Pvr_SafeAreaAlgoAPI_Pvr_GSASetCallbackShrink_m15C7B66FFD3672FC085E8608D2AAED9AF94EB8E2(L_2, NULL);
		V_1 = L_3;
		// if (ret1 != 0 || ret2 != 0)
		int32_t L_4 = V_0;
		if (L_4)
		{
			goto IL_002e;
		}
	}
	{
		int32_t L_5 = V_1;
		G_B3_0 = ((!(((uint32_t)L_5) <= ((uint32_t)0)))? 1 : 0);
		goto IL_002f;
	}

IL_002e:
	{
		G_B3_0 = 1;
	}

IL_002f:
	{
		V_3 = (bool)G_B3_0;
		bool L_6 = V_3;
		if (!L_6)
		{
			goto IL_0047;
		}
	}
	{
		// Debug.LogError("BoundarySystem register callback failed!");
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(_stringLiteral8784BB62541B5BDD09FFAB9A87B1EBBE14156566, NULL);
		// return false;
		V_4 = (bool)0;
		goto IL_00da;
	}

IL_0047:
	{
		// int ret = Pvr_SafeAreaAlgoAPI.Pvr_GSAInit(width * 100, height * 100);
		int32_t L_7 = ___0_width;
		int32_t L_8 = ___1_height;
		int32_t L_9;
		L_9 = Pvr_SafeAreaAlgoAPI_Pvr_GSAInit_m0FD61C053CACCEFCFCA5DC2A8C76C2DCD6D44E6C(((int32_t)il2cpp_codegen_multiply(L_7, ((int32_t)100))), ((int32_t)il2cpp_codegen_multiply(L_8, ((int32_t)100))), NULL);
		V_2 = L_9;
		// Debug.LogError("BoundarySystem ret:" + ret + "_width:" + width + "_height:" + height);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_10 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)6);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_11 = L_10;
		NullCheck(L_11);
		ArrayElementTypeCheck (L_11, _stringLiteralBC77136E09CE6E2CA8BC7074AD23EE15709847E9);
		(L_11)->SetAt(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteralBC77136E09CE6E2CA8BC7074AD23EE15709847E9);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_12 = L_11;
		String_t* L_13;
		L_13 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&V_2), NULL);
		NullCheck(L_12);
		ArrayElementTypeCheck (L_12, L_13);
		(L_12)->SetAt(static_cast<il2cpp_array_size_t>(1), (String_t*)L_13);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_14 = L_12;
		NullCheck(L_14);
		ArrayElementTypeCheck (L_14, _stringLiteral0B0D645C93F6D3B9458F33B2DFB8210A46C123F7);
		(L_14)->SetAt(static_cast<il2cpp_array_size_t>(2), (String_t*)_stringLiteral0B0D645C93F6D3B9458F33B2DFB8210A46C123F7);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_15 = L_14;
		String_t* L_16;
		L_16 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&___0_width), NULL);
		NullCheck(L_15);
		ArrayElementTypeCheck (L_15, L_16);
		(L_15)->SetAt(static_cast<il2cpp_array_size_t>(3), (String_t*)L_16);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_17 = L_15;
		NullCheck(L_17);
		ArrayElementTypeCheck (L_17, _stringLiteral7A805D623CF373F194487BF7035FA94ADF5E5C9B);
		(L_17)->SetAt(static_cast<il2cpp_array_size_t>(4), (String_t*)_stringLiteral7A805D623CF373F194487BF7035FA94ADF5E5C9B);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_18 = L_17;
		String_t* L_19;
		L_19 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&___1_height), NULL);
		NullCheck(L_18);
		ArrayElementTypeCheck (L_18, L_19);
		(L_18)->SetAt(static_cast<il2cpp_array_size_t>(5), (String_t*)L_19);
		String_t* L_20;
		L_20 = String_Concat_m647EBF831F54B6DF7D5AFA5FD012CF4EE7571B6A(L_18, NULL);
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_20, NULL);
		// if (ret == -2)
		int32_t L_21 = V_2;
		V_5 = (bool)((((int32_t)L_21) == ((int32_t)((int32_t)-2)))? 1 : 0);
		bool L_22 = V_5;
		if (!L_22)
		{
			goto IL_00ba;
		}
	}
	{
		// ret = Pvr_SafeAreaAlgoAPI.Pvr_GSAInit();
		int32_t L_23;
		L_23 = Pvr_SafeAreaAlgoAPI_Pvr_GSAInit_m1C17FA05C9A9943779823DEA64EBACDAC863CF86(NULL);
		V_2 = L_23;
		// Debug.LogError("BoundarySystem Use Old version");
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(_stringLiteralCA5A84BD2449CEC8316496E6966EF088F55F1688, NULL);
	}

IL_00ba:
	{
		// if (ret != 0)
		int32_t L_24 = V_2;
		V_6 = (bool)((!(((uint32_t)L_24) <= ((uint32_t)0)))? 1 : 0);
		bool L_25 = V_6;
		if (!L_25)
		{
			goto IL_00d5;
		}
	}
	{
		// Debug.LogError("BoundarySystem init failed!");
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(_stringLiteral81C5F640B84128CAF1CF95585CFC17A20C6F262A, NULL);
		// return false;
		V_4 = (bool)0;
		goto IL_00da;
	}

IL_00d5:
	{
		// return true;
		V_4 = (bool)1;
		goto IL_00da;
	}

IL_00da:
	{
		// }
		bool L_26 = V_4;
		return L_26;
	}
}
// System.Boolean BoundarySystem_Ext.Pvr_SafeAreaAlgoModule::CommitNewLineData(System.Boolean,UnityEngine.Vector3[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Pvr_SafeAreaAlgoModule_CommitNewLineData_m60E4EBBD2097E83C3AD4BDBD5EF3BBE78E6F424C (Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05* __this, bool ___0_isFistLine, Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* ___1_points, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GSALineU5BU5D_tC2644452FF1B88D2D201F355FA28F65A5D8CF685_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_UnsafeAddrOfPinnedArrayElement_TisGSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E_m2655F1BCF3E2FE7B028C56300363CA8898B97CC4_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_UnsafeAddrOfPinnedArrayElement_TisGSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_m2FCC5D2D2C14567CAEFBA54CB0BE80EA9E9ED980_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Pvr_BoundaryAPI_StructToIntPtr_TisGSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E_m4A4DF55B0B16B585FA2439BED123BE4CA5ED44D5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral4CDCDF88C3C531360CF21120C5C3AEE6B6FB27A2);
		s_Il2CppMethodInitialized = true;
	}
	GSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E V_0;
	memset((&V_0), 0, sizeof(V_0));
	GSALineU5BU5D_tC2644452FF1B88D2D201F355FA28F65A5D8CF685* V_1 = NULL;
	GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1* V_2 = NULL;
	intptr_t V_3;
	memset((&V_3), 0, sizeof(V_3));
	int32_t V_4 = 0;
	bool V_5 = false;
	GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1* V_6 = NULL;
	GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 V_7;
	memset((&V_7), 0, sizeof(V_7));
	int32_t V_8 = 0;
	GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 V_9;
	memset((&V_9), 0, sizeof(V_9));
	bool V_10 = false;
	bool V_11 = false;
	bool V_12 = false;
	{
		// Pvr_SafeAreaAlgoAPI.GSALineCollection lineCollection = new Pvr_SafeAreaAlgoAPI.GSALineCollection();
		il2cpp_codegen_initobj((&V_0), sizeof(GSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E));
		// lineCollection.lineCount = 2;
		(&V_0)->___lineCount_1 = 2;
		// Pvr_SafeAreaAlgoAPI.GSALine[] lineArray = new Pvr_SafeAreaAlgoAPI.GSALine[2];
		GSALineU5BU5D_tC2644452FF1B88D2D201F355FA28F65A5D8CF685* L_0 = (GSALineU5BU5D_tC2644452FF1B88D2D201F355FA28F65A5D8CF685*)(GSALineU5BU5D_tC2644452FF1B88D2D201F355FA28F65A5D8CF685*)SZArrayNew(GSALineU5BU5D_tC2644452FF1B88D2D201F355FA28F65A5D8CF685_il2cpp_TypeInfo_var, (uint32_t)2);
		V_1 = L_0;
		// if (isFistLine)
		bool L_1 = ___0_isFistLine;
		V_5 = L_1;
		bool L_2 = V_5;
		if (!L_2)
		{
			goto IL_0041;
		}
	}
	{
		// lineArray[0].pointArray = IntPtr.Zero;
		GSALineU5BU5D_tC2644452FF1B88D2D201F355FA28F65A5D8CF685* L_3 = V_1;
		NullCheck(L_3);
		intptr_t L_4 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		((L_3)->GetAddressAt(static_cast<il2cpp_array_size_t>(0)))->___pointArray_0 = L_4;
		// lineArray[0].pointCount = 0;
		GSALineU5BU5D_tC2644452FF1B88D2D201F355FA28F65A5D8CF685* L_5 = V_1;
		NullCheck(L_5);
		((L_5)->GetAddressAt(static_cast<il2cpp_array_size_t>(0)))->___pointCount_1 = 0;
		goto IL_0096;
	}

IL_0041:
	{
		// Pvr_SafeAreaAlgoAPI.GSAPoint3i[] tPoint = new Pvr_SafeAreaAlgoAPI.GSAPoint3i[1];
		GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1* L_6 = (GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1*)(GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1*)SZArrayNew(GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1_il2cpp_TypeInfo_var, (uint32_t)1);
		V_6 = L_6;
		// tPoint[0] = new Pvr_SafeAreaAlgoAPI.GSAPoint3i() { x = 0, y = 0, z = 0 };
		GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1* L_7 = V_6;
		il2cpp_codegen_initobj((&V_7), sizeof(GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17));
		(&V_7)->___x_0 = 0;
		(&V_7)->___y_1 = 0;
		(&V_7)->___z_2 = 0;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_8 = V_7;
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(0), (GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17)L_8);
		// lineArray[0].pointArray = Marshal.UnsafeAddrOfPinnedArrayElement(tPoint, 0); // unsafe
		GSALineU5BU5D_tC2644452FF1B88D2D201F355FA28F65A5D8CF685* L_9 = V_1;
		NullCheck(L_9);
		GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1* L_10 = V_6;
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		intptr_t L_11;
		L_11 = Marshal_UnsafeAddrOfPinnedArrayElement_TisGSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_m2FCC5D2D2C14567CAEFBA54CB0BE80EA9E9ED980(L_10, 0, Marshal_UnsafeAddrOfPinnedArrayElement_TisGSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_m2FCC5D2D2C14567CAEFBA54CB0BE80EA9E9ED980_RuntimeMethod_var);
		((L_9)->GetAddressAt(static_cast<il2cpp_array_size_t>(0)))->___pointArray_0 = L_11;
		// lineArray[0].pointCount = 1;
		GSALineU5BU5D_tC2644452FF1B88D2D201F355FA28F65A5D8CF685* L_12 = V_1;
		NullCheck(L_12);
		((L_12)->GetAddressAt(static_cast<il2cpp_array_size_t>(0)))->___pointCount_1 = 1;
	}

IL_0096:
	{
		// Pvr_SafeAreaAlgoAPI.GSAPoint3i[] pointArray = new Pvr_SafeAreaAlgoAPI.GSAPoint3i[points.Length];
		Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* L_13 = ___1_points;
		NullCheck(L_13);
		GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1* L_14 = (GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1*)(GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1*)SZArrayNew(GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1_il2cpp_TypeInfo_var, (uint32_t)((int32_t)(((RuntimeArray*)L_13)->max_length)));
		V_2 = L_14;
		// for (int i = 0; i < points.Length; i++)
		V_8 = 0;
		goto IL_010f;
	}

IL_00a4:
	{
		// Pvr_SafeAreaAlgoAPI.GSAPoint3i newPoint = new Pvr_SafeAreaAlgoAPI.GSAPoint3i();
		il2cpp_codegen_initobj((&V_9), sizeof(GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17));
		// newPoint.x = (int)(points[i].x * 1000);
		Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* L_15 = ___1_points;
		int32_t L_16 = V_8;
		NullCheck(L_15);
		float L_17 = ((L_15)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_16)))->___x_2;
		(&V_9)->___x_0 = il2cpp_codegen_cast_double_to_int<int32_t>(((float)il2cpp_codegen_multiply(L_17, (1000.0f))));
		// newPoint.y = (int)(points[i].y * 1000);
		Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* L_18 = ___1_points;
		int32_t L_19 = V_8;
		NullCheck(L_18);
		float L_20 = ((L_18)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_19)))->___y_3;
		(&V_9)->___y_1 = il2cpp_codegen_cast_double_to_int<int32_t>(((float)il2cpp_codegen_multiply(L_20, (1000.0f))));
		// newPoint.z = (int)(points[i].z * 1000);
		Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* L_21 = ___1_points;
		int32_t L_22 = V_8;
		NullCheck(L_21);
		float L_23 = ((L_21)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_22)))->___z_4;
		(&V_9)->___z_2 = il2cpp_codegen_cast_double_to_int<int32_t>(((float)il2cpp_codegen_multiply(L_23, (1000.0f))));
		// pointArray[i] = newPoint;
		GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1* L_24 = V_2;
		int32_t L_25 = V_8;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_26 = V_9;
		NullCheck(L_24);
		(L_24)->SetAt(static_cast<il2cpp_array_size_t>(L_25), (GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17)L_26);
		// for (int i = 0; i < points.Length; i++)
		int32_t L_27 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_27, 1));
	}

IL_010f:
	{
		// for (int i = 0; i < points.Length; i++)
		int32_t L_28 = V_8;
		Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* L_29 = ___1_points;
		NullCheck(L_29);
		V_10 = (bool)((((int32_t)L_28) < ((int32_t)((int32_t)(((RuntimeArray*)L_29)->max_length))))? 1 : 0);
		bool L_30 = V_10;
		if (L_30)
		{
			goto IL_00a4;
		}
	}
	{
		// lineArray[1].pointArray = Marshal.UnsafeAddrOfPinnedArrayElement(pointArray, 0); // unsafe
		GSALineU5BU5D_tC2644452FF1B88D2D201F355FA28F65A5D8CF685* L_31 = V_1;
		NullCheck(L_31);
		GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1* L_32 = V_2;
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		intptr_t L_33;
		L_33 = Marshal_UnsafeAddrOfPinnedArrayElement_TisGSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_m2FCC5D2D2C14567CAEFBA54CB0BE80EA9E9ED980(L_32, 0, Marshal_UnsafeAddrOfPinnedArrayElement_TisGSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_m2FCC5D2D2C14567CAEFBA54CB0BE80EA9E9ED980_RuntimeMethod_var);
		((L_31)->GetAddressAt(static_cast<il2cpp_array_size_t>(1)))->___pointArray_0 = L_33;
		// lineArray[1].pointCount = pointArray.Length;
		GSALineU5BU5D_tC2644452FF1B88D2D201F355FA28F65A5D8CF685* L_34 = V_1;
		NullCheck(L_34);
		GSAPoint3iU5BU5D_tC6A865F67AEC4AEAFB085FE6A60BF34F4280C5C1* L_35 = V_2;
		NullCheck(L_35);
		((L_34)->GetAddressAt(static_cast<il2cpp_array_size_t>(1)))->___pointCount_1 = ((int32_t)(((RuntimeArray*)L_35)->max_length));
		// lineCollection.lineArray = Marshal.UnsafeAddrOfPinnedArrayElement(lineArray, 0);
		GSALineU5BU5D_tC2644452FF1B88D2D201F355FA28F65A5D8CF685* L_36 = V_1;
		intptr_t L_37;
		L_37 = Marshal_UnsafeAddrOfPinnedArrayElement_TisGSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E_m2655F1BCF3E2FE7B028C56300363CA8898B97CC4(L_36, 0, Marshal_UnsafeAddrOfPinnedArrayElement_TisGSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E_m2655F1BCF3E2FE7B028C56300363CA8898B97CC4_RuntimeMethod_var);
		(&V_0)->___lineArray_0 = L_37;
		// IntPtr collectionPtr = Pvr_BoundaryAPI.StructToIntPtr<Pvr_SafeAreaAlgoAPI.GSALineCollection>(lineCollection);
		GSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E L_38 = V_0;
		intptr_t L_39;
		L_39 = Pvr_BoundaryAPI_StructToIntPtr_TisGSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E_m4A4DF55B0B16B585FA2439BED123BE4CA5ED44D5(L_38, Pvr_BoundaryAPI_StructToIntPtr_TisGSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E_m4A4DF55B0B16B585FA2439BED123BE4CA5ED44D5_RuntimeMethod_var);
		V_3 = L_39;
		// int ret = Pvr_SafeAreaAlgoAPI.Pvr_GSAUpDateData(collectionPtr);
		intptr_t L_40 = V_3;
		int32_t L_41;
		L_41 = Pvr_SafeAreaAlgoAPI_Pvr_GSAUpDateData_m2075353F1784E7877960B0A2BB9D98041C856D90(L_40, NULL);
		V_4 = L_41;
		// Marshal.FreeHGlobal(collectionPtr);
		intptr_t L_42 = V_3;
		Marshal_FreeHGlobal_m298EF0650E82E326EDA8048488DC384BB9171EB9(L_42, NULL);
		// if (ret != 0)
		int32_t L_43 = V_4;
		V_11 = (bool)((!(((uint32_t)L_43) <= ((uint32_t)0)))? 1 : 0);
		bool L_44 = V_11;
		if (!L_44)
		{
			goto IL_017e;
		}
	}
	{
		// Debug.LogError("BoundarySystem commit new line data failed!");
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(_stringLiteral4CDCDF88C3C531360CF21120C5C3AEE6B6FB27A2, NULL);
		// return false;
		V_12 = (bool)0;
		goto IL_0183;
	}

IL_017e:
	{
		// return true;
		V_12 = (bool)1;
		goto IL_0183;
	}

IL_0183:
	{
		// }
		bool L_45 = V_12;
		return L_45;
	}
}
// System.Boolean BoundarySystem_Ext.Pvr_SafeAreaAlgoModule::Shutdown()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Pvr_SafeAreaAlgoModule_Shutdown_m4BC3231B03DC59F5AD03374384B72F02691A4A03 (Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDFF981EBDBDEC964BB46EFD6C842AA2F2BC59425);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	bool V_1 = false;
	bool V_2 = false;
	{
		// int ret = Pvr_SafeAreaAlgoAPI.Pvr_GSAShutDown();
		int32_t L_0;
		L_0 = Pvr_SafeAreaAlgoAPI_Pvr_GSAShutDown_mE515E181C0D3FF1EBB0EC648F2C8C31E2D17CE3B(NULL);
		V_0 = L_0;
		// if (ret != 0)
		int32_t L_1 = V_0;
		V_1 = (bool)((!(((uint32_t)L_1) <= ((uint32_t)0)))? 1 : 0);
		bool L_2 = V_1;
		if (!L_2)
		{
			goto IL_001f;
		}
	}
	{
		// Debug.LogError("BoundarySystem shutdown failed!");
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(_stringLiteralDFF981EBDBDEC964BB46EFD6C842AA2F2BC59425, NULL);
		// return false;
		V_2 = (bool)0;
		goto IL_0023;
	}

IL_001f:
	{
		// return true;
		V_2 = (bool)1;
		goto IL_0023;
	}

IL_0023:
	{
		// }
		bool L_3 = V_2;
		return L_3;
	}
}
// System.Double BoundarySystem_Ext.Pvr_SafeAreaAlgoModule::QueryDistanceOfPoint(UnityEngine.Vector3)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Pvr_SafeAreaAlgoModule_QueryDistanceOfPoint_mD8865AB6DC1CBD90EAD8144C44651FB125473838 (Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_point, const RuntimeMethod* method) 
{
	GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 V_0;
	memset((&V_0), 0, sizeof(V_0));
	double V_1 = 0.0;
	double V_2 = 0.0;
	{
		// Pvr_SafeAreaAlgoAPI.GSAPoint3i point3i = new Pvr_SafeAreaAlgoAPI.GSAPoint3i();
		il2cpp_codegen_initobj((&V_0), sizeof(GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17));
		// point3i.x = (int)(point.x * 1000);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ___0_point;
		float L_1 = L_0.___x_2;
		(&V_0)->___x_0 = il2cpp_codegen_cast_double_to_int<int32_t>(((float)il2cpp_codegen_multiply(L_1, (1000.0f))));
		// point3i.y = (int)(point.y * 1000);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_2 = ___0_point;
		float L_3 = L_2.___y_3;
		(&V_0)->___y_1 = il2cpp_codegen_cast_double_to_int<int32_t>(((float)il2cpp_codegen_multiply(L_3, (1000.0f))));
		// point3i.z = (int)(point.z * 1000);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4 = ___0_point;
		float L_5 = L_4.___z_4;
		(&V_0)->___z_2 = il2cpp_codegen_cast_double_to_int<int32_t>(((float)il2cpp_codegen_multiply(L_5, (1000.0f))));
		// double distance = Pvr_SafeAreaAlgoAPI.Pvr_GSABoundaryDetector(ref point3i);
		double L_6;
		L_6 = Pvr_SafeAreaAlgoAPI_Pvr_GSABoundaryDetector_mE4BC4C704D06B0F3B33987BA59E5B63618570308((&V_0), NULL);
		V_1 = L_6;
		// return distance / 1000.0f; // mm -> m
		double L_7 = V_1;
		V_2 = ((double)(L_7/(1000.0)));
		goto IL_005b;
	}

IL_005b:
	{
		// }
		double L_8 = V_2;
		return L_8;
	}
}
// System.Double BoundarySystem_Ext.Pvr_SafeAreaAlgoModule::QueryDistanceOfPoint(UnityEngine.Vector3,System.Boolean,UnityEngine.Vector3&,UnityEngine.Vector3&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Pvr_SafeAreaAlgoModule_QueryDistanceOfPoint_mE9B2ECF4C641078C5416A627AB1AA9F24928FECA (Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_point, bool ___1_isPlayArea, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* ___2_closestPoint, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* ___3_normalDir, const RuntimeMethod* method) 
{
	GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 V_0;
	memset((&V_0), 0, sizeof(V_0));
	GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 V_1;
	memset((&V_1), 0, sizeof(V_1));
	GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 V_2;
	memset((&V_2), 0, sizeof(V_2));
	double V_3 = 0.0;
	double V_4 = 0.0;
	{
		// Pvr_SafeAreaAlgoAPI.GSAPoint3i point3i = new Pvr_SafeAreaAlgoAPI.GSAPoint3i();
		il2cpp_codegen_initobj((&V_0), sizeof(GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17));
		// point3i.x = (int)(point.x * 1000);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ___0_point;
		float L_1 = L_0.___x_2;
		(&V_0)->___x_0 = il2cpp_codegen_cast_double_to_int<int32_t>(((float)il2cpp_codegen_multiply(L_1, (1000.0f))));
		// point3i.y = (int)(point.y * 1000);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_2 = ___0_point;
		float L_3 = L_2.___y_3;
		(&V_0)->___y_1 = il2cpp_codegen_cast_double_to_int<int32_t>(((float)il2cpp_codegen_multiply(L_3, (1000.0f))));
		// point3i.z = (int)(point.z * 1000);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4 = ___0_point;
		float L_5 = L_4.___z_4;
		(&V_0)->___z_2 = il2cpp_codegen_cast_double_to_int<int32_t>(((float)il2cpp_codegen_multiply(L_5, (1000.0f))));
		// Pvr_SafeAreaAlgoAPI.GSAPoint3i closestPoint3i = new Pvr_SafeAreaAlgoAPI.GSAPoint3i();
		il2cpp_codegen_initobj((&V_1), sizeof(GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17));
		// Pvr_SafeAreaAlgoAPI.GSAPoint3i normalDir3i = new Pvr_SafeAreaAlgoAPI.GSAPoint3i();
		il2cpp_codegen_initobj((&V_2), sizeof(GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17));
		// double distance = Pvr_SafeAreaAlgoAPI.Pvr_GSABoundaryDetector2(ref point3i, isPlayArea, ref closestPoint3i, ref normalDir3i);
		bool L_6 = ___1_isPlayArea;
		double L_7;
		L_7 = Pvr_SafeAreaAlgoAPI_Pvr_GSABoundaryDetector2_m0009C8B90F40C2EDDD744D468E5F3EC0AFCEFAFD((&V_0), L_6, (&V_1), (&V_2), NULL);
		V_3 = L_7;
		// closestPoint.x = closestPoint3i.x / 1000.0f;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* L_8 = ___2_closestPoint;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_9 = V_1;
		int32_t L_10 = L_9.___x_0;
		L_8->___x_2 = ((float)(((float)L_10)/(1000.0f)));
		// closestPoint.y = closestPoint3i.y / 1000.0f;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* L_11 = ___2_closestPoint;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_12 = V_1;
		int32_t L_13 = L_12.___y_1;
		L_11->___y_3 = ((float)(((float)L_13)/(1000.0f)));
		// closestPoint.z = closestPoint3i.z / 1000.0f;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* L_14 = ___2_closestPoint;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_15 = V_1;
		int32_t L_16 = L_15.___z_2;
		L_14->___z_4 = ((float)(((float)L_16)/(1000.0f)));
		// normalDir.x = normalDir3i.x / 1000.0f;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* L_17 = ___3_normalDir;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_18 = V_2;
		int32_t L_19 = L_18.___x_0;
		L_17->___x_2 = ((float)(((float)L_19)/(1000.0f)));
		// normalDir.y = normalDir3i.y / 1000.0f;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* L_20 = ___3_normalDir;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_21 = V_2;
		int32_t L_22 = L_21.___y_1;
		L_20->___y_3 = ((float)(((float)L_22)/(1000.0f)));
		// normalDir.z = normalDir3i.z / 1000.0f;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* L_23 = ___3_normalDir;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_24 = V_2;
		int32_t L_25 = L_24.___z_2;
		L_23->___z_4 = ((float)(((float)L_25)/(1000.0f)));
		// return distance / 1000.0f; // mm -> m
		double L_26 = V_3;
		V_4 = ((double)(L_26/(1000.0)));
		goto IL_00e6;
	}

IL_00e6:
	{
		// }
		double L_27 = V_4;
		return L_27;
	}
}
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoModule::_SafeAreaCallback(System.IntPtr,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_SafeAreaAlgoModule__SafeAreaCallback_m756D201F90CFD3D062D71245E9C85697F8766969 (intptr_t ___0_lineCollectionPtr, intptr_t ___1_safeAreaRectPtr, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m79E50C4F592B1703F4B76A8BE7B4855515460CA1_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m8B5DEF3F8F4F49003BB953399B6E84A6DC941AC6_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_mBE9255218FAB0B859E0DD1B944986BBC7F1C3A33_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_mC54E2BCBE43279A96FC082F5CDE2D76388BD8F9C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Pvr_BoundaryAPI_IntPtrToStruct_TisGSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E_m3C7EC489283FB44610163AB0091A1C279E4F7156_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Pvr_BoundaryAPI_IntPtrToStruct_TisGSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3_mF94DF99548B07FAD05377E537D93589DB1845B7F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral07D4E98E332EC0D17F8FB3F458B42EBB2C4EAF29);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* V_2 = NULL;
	List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	GSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E V_6;
	memset((&V_6), 0, sizeof(V_6));
	intptr_t V_7;
	memset((&V_7), 0, sizeof(V_7));
	GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 V_8;
	memset((&V_8), 0, sizeof(V_8));
	BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B V_9;
	memset((&V_9), 0, sizeof(V_9));
	int32_t V_10 = 0;
	GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E V_11;
	memset((&V_11), 0, sizeof(V_11));
	List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* V_12 = NULL;
	int32_t V_13 = 0;
	intptr_t V_14;
	memset((&V_14), 0, sizeof(V_14));
	GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 V_15;
	memset((&V_15), 0, sizeof(V_15));
	bool V_16 = false;
	bool V_17 = false;
	bool V_18 = false;
	int32_t G_B3_0 = 0;
	BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B* G_B17_0 = NULL;
	BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B* G_B16_0 = NULL;
	int32_t G_B18_0 = 0;
	BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B* G_B18_1 = NULL;
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54* G_B20_0 = NULL;
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54* G_B19_0 = NULL;
	int32_t G_B21_0 = 0;
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54* G_B21_1 = NULL;
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54* G_B23_0 = NULL;
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54* G_B22_0 = NULL;
	int32_t G_B24_0 = 0;
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54* G_B24_1 = NULL;
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54* G_B26_0 = NULL;
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54* G_B25_0 = NULL;
	int32_t G_B27_0 = 0;
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54* G_B27_1 = NULL;
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54* G_B29_0 = NULL;
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54* G_B28_0 = NULL;
	int32_t G_B30_0 = 0;
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54* G_B30_1 = NULL;
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54* G_B32_0 = NULL;
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54* G_B31_0 = NULL;
	int32_t G_B33_0 = 0;
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54* G_B33_1 = NULL;
	{
		// if (lineCollectionPtr == IntPtr.Zero || safeAreaRectPtr == IntPtr.Zero)
		intptr_t L_0 = ___0_lineCollectionPtr;
		intptr_t L_1 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		bool L_2;
		L_2 = IntPtr_op_Equality_m7D9CDCDE9DC2A0C2C614633F4921E90187FAB271(L_0, L_1, NULL);
		if (L_2)
		{
			goto IL_001b;
		}
	}
	{
		intptr_t L_3 = ___1_safeAreaRectPtr;
		intptr_t L_4 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		bool L_5;
		L_5 = IntPtr_op_Equality_m7D9CDCDE9DC2A0C2C614633F4921E90187FAB271(L_3, L_4, NULL);
		G_B3_0 = ((int32_t)(L_5));
		goto IL_001c;
	}

IL_001b:
	{
		G_B3_0 = 1;
	}

IL_001c:
	{
		V_0 = (bool)G_B3_0;
		bool L_6 = V_0;
		if (!L_6)
		{
			goto IL_0031;
		}
	}
	{
		// Debug.LogError("BoundarySystem callback is inValid!");
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(_stringLiteral07D4E98E332EC0D17F8FB3F458B42EBB2C4EAF29, NULL);
		// return;
		goto IL_0439;
	}

IL_0031:
	{
		// if (instance.boundarySystemCallback != null)
		Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05* L_7 = ((Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05_StaticFields*)il2cpp_codegen_static_fields_for(Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05_il2cpp_TypeInfo_var))->___instance_0;
		NullCheck(L_7);
		BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD* L_8 = L_7->___boundarySystemCallback_1;
		V_1 = (bool)((!(((RuntimeObject*)(BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD*)L_8) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		bool L_9 = V_1;
		if (!L_9)
		{
			goto IL_0439;
		}
	}
	{
		// List<Vector3> boundaryPoints = new List<Vector3>();
		List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* L_10 = (List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*)il2cpp_codegen_object_new(List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B_il2cpp_TypeInfo_var);
		NullCheck(L_10);
		List_1__ctor_mC54E2BCBE43279A96FC082F5CDE2D76388BD8F9C(L_10, List_1__ctor_mC54E2BCBE43279A96FC082F5CDE2D76388BD8F9C_RuntimeMethod_var);
		V_2 = L_10;
		// List<List<Vector3>> unusedLines = new List<List<Vector3>>();
		List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* L_11 = (List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F*)il2cpp_codegen_object_new(List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F_il2cpp_TypeInfo_var);
		NullCheck(L_11);
		List_1__ctor_mBE9255218FAB0B859E0DD1B944986BBC7F1C3A33(L_11, List_1__ctor_mBE9255218FAB0B859E0DD1B944986BBC7F1C3A33_RuntimeMethod_var);
		V_3 = L_11;
		// int byteNum = Marshal.SizeOf(typeof(Pvr_SafeAreaAlgoAPI.GSALine));
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_12 = { reinterpret_cast<intptr_t> (GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_13;
		L_13 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_12, NULL);
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		int32_t L_14;
		L_14 = Marshal_SizeOf_mED64846722033D6F60C2973CA604B7C2D7D4A1B7(L_13, NULL);
		V_4 = L_14;
		// int byteNum2 = Marshal.SizeOf(typeof(Pvr_SafeAreaAlgoAPI.GSAPoint3i));
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_15 = { reinterpret_cast<intptr_t> (GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_0_0_0_var) };
		Type_t* L_16;
		L_16 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_15, NULL);
		int32_t L_17;
		L_17 = Marshal_SizeOf_mED64846722033D6F60C2973CA604B7C2D7D4A1B7(L_16, NULL);
		V_5 = L_17;
		// Pvr_SafeAreaAlgoAPI.GSALineCollection collection = Pvr_BoundaryAPI.IntPtrToStruct<Pvr_SafeAreaAlgoAPI.GSALineCollection>(lineCollectionPtr);
		intptr_t L_18 = ___0_lineCollectionPtr;
		GSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E L_19;
		L_19 = Pvr_BoundaryAPI_IntPtrToStruct_TisGSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E_m3C7EC489283FB44610163AB0091A1C279E4F7156(L_18, Pvr_BoundaryAPI_IntPtrToStruct_TisGSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E_m3C7EC489283FB44610163AB0091A1C279E4F7156_RuntimeMethod_var);
		V_6 = L_19;
		// for (int i = 0; i < collection.lineCount; i++)
		V_10 = 0;
		goto IL_016c;
	}

IL_0084:
	{
		// ptr = new IntPtr(collection.lineArray.ToInt64() + (byteNum * i));
		intptr_t* L_20 = (intptr_t*)(&(&V_6)->___lineArray_0);
		int64_t L_21;
		L_21 = IntPtr_ToInt64_m0F81FB6FB08014074D4F5B915EDAB06A08552032(L_20, NULL);
		int32_t L_22 = V_4;
		int32_t L_23 = V_10;
		IntPtr__ctor_m2C033540A2F274766CF5C2A120587DD997E3F6DC((&V_7), ((int64_t)il2cpp_codegen_add(L_21, ((int64_t)((int32_t)il2cpp_codegen_multiply(L_22, L_23))))), NULL);
		// Pvr_SafeAreaAlgoAPI.GSALine line = (Pvr_SafeAreaAlgoAPI.GSALine)Marshal.PtrToStructure(ptr, typeof(Pvr_SafeAreaAlgoAPI.GSALine));
		intptr_t L_24 = V_7;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_25 = { reinterpret_cast<intptr_t> (GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_26;
		L_26 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_25, NULL);
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		RuntimeObject* L_27;
		L_27 = Marshal_PtrToStructure_m235E141E21BFB69A01B07DDDF1702BA7D5723AC3(L_24, L_26, NULL);
		V_11 = ((*(GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E*)((GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E*)(GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E*)UnBox(L_27, GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E_il2cpp_TypeInfo_var))));
		// List<Vector3> newLine = new List<Vector3>();
		List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* L_28 = (List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*)il2cpp_codegen_object_new(List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B_il2cpp_TypeInfo_var);
		NullCheck(L_28);
		List_1__ctor_mC54E2BCBE43279A96FC082F5CDE2D76388BD8F9C(L_28, List_1__ctor_mC54E2BCBE43279A96FC082F5CDE2D76388BD8F9C_RuntimeMethod_var);
		V_12 = L_28;
		// for (int j = 0; j < line.pointCount; j++)
		V_13 = 0;
		goto IL_0134;
	}

IL_00c3:
	{
		// IntPtr tptr = new IntPtr(line.pointArray.ToInt64() + (byteNum2 * j));
		intptr_t* L_29 = (intptr_t*)(&(&V_11)->___pointArray_0);
		int64_t L_30;
		L_30 = IntPtr_ToInt64_m0F81FB6FB08014074D4F5B915EDAB06A08552032(L_29, NULL);
		int32_t L_31 = V_5;
		int32_t L_32 = V_13;
		IntPtr__ctor_m2C033540A2F274766CF5C2A120587DD997E3F6DC((&V_14), ((int64_t)il2cpp_codegen_add(L_30, ((int64_t)((int32_t)il2cpp_codegen_multiply(L_31, L_32))))), NULL);
		// Pvr_SafeAreaAlgoAPI.GSAPoint3i point = (Pvr_SafeAreaAlgoAPI.GSAPoint3i)Marshal.PtrToStructure(tptr, typeof(Pvr_SafeAreaAlgoAPI.GSAPoint3i));
		intptr_t L_33 = V_14;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_34 = { reinterpret_cast<intptr_t> (GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_35;
		L_35 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_34, NULL);
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		RuntimeObject* L_36;
		L_36 = Marshal_PtrToStructure_m235E141E21BFB69A01B07DDDF1702BA7D5723AC3(L_33, L_35, NULL);
		V_15 = ((*(GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17*)((GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17*)(GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17*)UnBox(L_36, GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_il2cpp_TypeInfo_var))));
		// newLine.Add(new Vector3(point.x / 1000f, point.y / 1000f, point.z / 1000f));
		List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* L_37 = V_12;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_38 = V_15;
		int32_t L_39 = L_38.___x_0;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_40 = V_15;
		int32_t L_41 = L_40.___y_1;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_42 = V_15;
		int32_t L_43 = L_42.___z_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_44;
		memset((&L_44), 0, sizeof(L_44));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_44), ((float)(((float)L_39)/(1000.0f))), ((float)(((float)L_41)/(1000.0f))), ((float)(((float)L_43)/(1000.0f))), /*hidden argument*/NULL);
		NullCheck(L_37);
		List_1_Add_m79E50C4F592B1703F4B76A8BE7B4855515460CA1_inline(L_37, L_44, List_1_Add_m79E50C4F592B1703F4B76A8BE7B4855515460CA1_RuntimeMethod_var);
		// for (int j = 0; j < line.pointCount; j++)
		int32_t L_45 = V_13;
		V_13 = ((int32_t)il2cpp_codegen_add(L_45, 1));
	}

IL_0134:
	{
		// for (int j = 0; j < line.pointCount; j++)
		int32_t L_46 = V_13;
		GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E L_47 = V_11;
		int32_t L_48 = L_47.___pointCount_1;
		V_16 = (bool)((((int32_t)L_46) < ((int32_t)L_48))? 1 : 0);
		bool L_49 = V_16;
		if (L_49)
		{
			goto IL_00c3;
		}
	}
	{
		// if (i == 0) // first line for colsed boundary
		int32_t L_50 = V_10;
		V_17 = (bool)((((int32_t)L_50) == ((int32_t)0))? 1 : 0);
		bool L_51 = V_17;
		if (!L_51)
		{
			goto IL_015a;
		}
	}
	{
		// boundaryPoints = newLine;
		List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* L_52 = V_12;
		V_2 = L_52;
		goto IL_0165;
	}

IL_015a:
	{
		// unusedLines.Add(newLine);
		List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* L_53 = V_3;
		List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* L_54 = V_12;
		NullCheck(L_53);
		List_1_Add_m8B5DEF3F8F4F49003BB953399B6E84A6DC941AC6_inline(L_53, L_54, List_1_Add_m8B5DEF3F8F4F49003BB953399B6E84A6DC941AC6_RuntimeMethod_var);
	}

IL_0165:
	{
		// for (int i = 0; i < collection.lineCount; i++)
		int32_t L_55 = V_10;
		V_10 = ((int32_t)il2cpp_codegen_add(L_55, 1));
	}

IL_016c:
	{
		// for (int i = 0; i < collection.lineCount; i++)
		int32_t L_56 = V_10;
		GSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E L_57 = V_6;
		int32_t L_58 = L_57.___lineCount_1;
		V_18 = (bool)((((int32_t)L_56) < ((int32_t)L_58))? 1 : 0);
		bool L_59 = V_18;
		if (L_59)
		{
			goto IL_0084;
		}
	}
	{
		// Pvr_SafeAreaAlgoAPI.GSARect algoResult = Pvr_BoundaryAPI.IntPtrToStruct<Pvr_SafeAreaAlgoAPI.GSARect>(safeAreaRectPtr);
		intptr_t L_60 = ___1_safeAreaRectPtr;
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_61;
		L_61 = Pvr_BoundaryAPI_IntPtrToStruct_TisGSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3_mF94DF99548B07FAD05377E537D93589DB1845B7F(L_60, Pvr_BoundaryAPI_IntPtrToStruct_TisGSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3_mF94DF99548B07FAD05377E537D93589DB1845B7F_RuntimeMethod_var);
		V_8 = L_61;
		// BoundaryPlayerArea playAreaInfo = new BoundaryPlayerArea();
		il2cpp_codegen_initobj((&V_9), sizeof(BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B));
		// playAreaInfo.lowerleft = new Vector3(algoResult.leftup.x / 1000f, algoResult.leftup.y / 1000f, algoResult.leftup.z / 1000f);
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_62 = V_8;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_63 = L_62.___leftup_0;
		int32_t L_64 = L_63.___x_0;
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_65 = V_8;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_66 = L_65.___leftup_0;
		int32_t L_67 = L_66.___y_1;
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_68 = V_8;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_69 = L_68.___leftup_0;
		int32_t L_70 = L_69.___z_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_71;
		memset((&L_71), 0, sizeof(L_71));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_71), ((float)(((float)L_64)/(1000.0f))), ((float)(((float)L_67)/(1000.0f))), ((float)(((float)L_70)/(1000.0f))), /*hidden argument*/NULL);
		(&V_9)->___lowerleft_0 = L_71;
		// playAreaInfo.upperleft = new Vector3(algoResult.leftdown.x / 1000f, algoResult.leftdown.y / 1000f, algoResult.leftdown.z / 1000f);
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_72 = V_8;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_73 = L_72.___leftdown_1;
		int32_t L_74 = L_73.___x_0;
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_75 = V_8;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_76 = L_75.___leftdown_1;
		int32_t L_77 = L_76.___y_1;
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_78 = V_8;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_79 = L_78.___leftdown_1;
		int32_t L_80 = L_79.___z_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_81;
		memset((&L_81), 0, sizeof(L_81));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_81), ((float)(((float)L_74)/(1000.0f))), ((float)(((float)L_77)/(1000.0f))), ((float)(((float)L_80)/(1000.0f))), /*hidden argument*/NULL);
		(&V_9)->___upperleft_1 = L_81;
		// playAreaInfo.upperRight = new Vector3(algoResult.rightdown.x / 1000f, algoResult.rightdown.y / 1000f, algoResult.rightdown.z / 1000f);
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_82 = V_8;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_83 = L_82.___rightdown_3;
		int32_t L_84 = L_83.___x_0;
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_85 = V_8;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_86 = L_85.___rightdown_3;
		int32_t L_87 = L_86.___y_1;
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_88 = V_8;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_89 = L_88.___rightdown_3;
		int32_t L_90 = L_89.___z_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_91;
		memset((&L_91), 0, sizeof(L_91));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_91), ((float)(((float)L_84)/(1000.0f))), ((float)(((float)L_87)/(1000.0f))), ((float)(((float)L_90)/(1000.0f))), /*hidden argument*/NULL);
		(&V_9)->___upperRight_2 = L_91;
		// playAreaInfo.lowerRight = new Vector3(algoResult.rightup.x / 1000f, algoResult.rightup.y / 1000f, algoResult.rightup.z / 1000f);
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_92 = V_8;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_93 = L_92.___rightup_2;
		int32_t L_94 = L_93.___x_0;
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_95 = V_8;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_96 = L_95.___rightup_2;
		int32_t L_97 = L_96.___y_1;
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_98 = V_8;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_99 = L_98.___rightup_2;
		int32_t L_100 = L_99.___z_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_101;
		memset((&L_101), 0, sizeof(L_101));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_101), ((float)(((float)L_94)/(1000.0f))), ((float)(((float)L_97)/(1000.0f))), ((float)(((float)L_100)/(1000.0f))), /*hidden argument*/NULL);
		(&V_9)->___lowerRight_3 = L_101;
		// playAreaInfo.center = new Vector3(algoResult.center.x / 1000f, algoResult.center.y / 1000f, algoResult.center.z / 1000f);
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_102 = V_8;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_103 = L_102.___center_4;
		int32_t L_104 = L_103.___x_0;
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_105 = V_8;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_106 = L_105.___center_4;
		int32_t L_107 = L_106.___y_1;
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_108 = V_8;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_109 = L_108.___center_4;
		int32_t L_110 = L_109.___z_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_111;
		memset((&L_111), 0, sizeof(L_111));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_111), ((float)(((float)L_104)/(1000.0f))), ((float)(((float)L_107)/(1000.0f))), ((float)(((float)L_110)/(1000.0f))), /*hidden argument*/NULL);
		(&V_9)->___center_4 = L_111;
		// playAreaInfo.width = algoResult.width;
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_112 = V_8;
		uint32_t L_113 = L_112.___width_5;
		(&V_9)->___width_5 = L_113;
		// playAreaInfo.height = algoResult.height;
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_114 = V_8;
		uint32_t L_115 = L_114.___height_6;
		(&V_9)->___height_6 = L_115;
		// playAreaInfo.isLegal = algoResult.isLegal == 0 ? false : true;
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_116 = V_8;
		int32_t L_117 = L_116.___isLegal_7;
		G_B16_0 = (&V_9);
		if (!L_117)
		{
			G_B17_0 = (&V_9);
			goto IL_0313;
		}
	}
	{
		G_B18_0 = 1;
		G_B18_1 = G_B16_0;
		goto IL_0314;
	}

IL_0313:
	{
		G_B18_0 = 0;
		G_B18_1 = G_B17_0;
	}

IL_0314:
	{
		G_B18_1->___isLegal_7 = (bool)G_B18_0;
		// playAreaInfo.firstcenter = new Vector3(algoResult.firstCenter.x / 1000f, algoResult.firstCenter.y / 1000f, algoResult.firstCenter.z / 1000f);
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_118 = V_8;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_119 = L_118.___firstCenter_9;
		int32_t L_120 = L_119.___x_0;
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_121 = V_8;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_122 = L_121.___firstCenter_9;
		int32_t L_123 = L_122.___y_1;
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_124 = V_8;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_125 = L_124.___firstCenter_9;
		int32_t L_126 = L_125.___z_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_127;
		memset((&L_127), 0, sizeof(L_127));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_127), ((float)(((float)L_120)/(1000.0f))), ((float)(((float)L_123)/(1000.0f))), ((float)(((float)L_126)/(1000.0f))), /*hidden argument*/NULL);
		(&V_9)->___firstcenter_8 = L_127;
		// playAreaInfo.extraInfo.overMaxRange = algoResult.legalData.overMaxRange == 0 ? false : true;
		ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54* L_128 = (ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54*)(&(&V_9)->___extraInfo_9);
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_129 = V_8;
		GSALegalData_tB87501C567F852AFE055E4A612E06DC6360EB2E7 L_130 = L_129.___legalData_8;
		int32_t L_131 = L_130.___overMaxRange_0;
		G_B19_0 = L_128;
		if (!L_131)
		{
			G_B20_0 = L_128;
			goto IL_0376;
		}
	}
	{
		G_B21_0 = 1;
		G_B21_1 = G_B19_0;
		goto IL_0377;
	}

IL_0376:
	{
		G_B21_0 = 0;
		G_B21_1 = G_B20_0;
	}

IL_0377:
	{
		G_B21_1->___overMaxRange_0 = (bool)G_B21_0;
		// playAreaInfo.extraInfo.includeBigGap = algoResult.legalData.includeBigGrap == 0 ? false : true;
		ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54* L_132 = (ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54*)(&(&V_9)->___extraInfo_9);
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_133 = V_8;
		GSALegalData_tB87501C567F852AFE055E4A612E06DC6360EB2E7 L_134 = L_133.___legalData_8;
		int32_t L_135 = L_134.___includeBigGrap_1;
		G_B22_0 = L_132;
		if (!L_135)
		{
			G_B23_0 = L_132;
			goto IL_0394;
		}
	}
	{
		G_B24_0 = 1;
		G_B24_1 = G_B22_0;
		goto IL_0395;
	}

IL_0394:
	{
		G_B24_0 = 0;
		G_B24_1 = G_B23_0;
	}

IL_0395:
	{
		G_B24_1->___includeBigGap_1 = (bool)G_B24_0;
		// playAreaInfo.extraInfo.bigGapNum = algoResult.legalData.bigGapNum;
		ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54* L_136 = (ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54*)(&(&V_9)->___extraInfo_9);
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_137 = V_8;
		GSALegalData_tB87501C567F852AFE055E4A612E06DC6360EB2E7 L_138 = L_137.___legalData_8;
		int32_t L_139 = L_138.___bigGapNum_2;
		L_136->___bigGapNum_2 = L_139;
		// playAreaInfo.extraInfo.centerOut = algoResult.legalData.centerOut == 0 ? false : true;
		ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54* L_140 = (ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54*)(&(&V_9)->___extraInfo_9);
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_141 = V_8;
		GSALegalData_tB87501C567F852AFE055E4A612E06DC6360EB2E7 L_142 = L_141.___legalData_8;
		int32_t L_143 = L_142.___centerOut_3;
		G_B25_0 = L_140;
		if (!L_143)
		{
			G_B26_0 = L_140;
			goto IL_03ca;
		}
	}
	{
		G_B27_0 = 1;
		G_B27_1 = G_B25_0;
		goto IL_03cb;
	}

IL_03ca:
	{
		G_B27_0 = 0;
		G_B27_1 = G_B26_0;
	}

IL_03cb:
	{
		G_B27_1->___centerOut_3 = (bool)G_B27_0;
		// playAreaInfo.extraInfo.removeNarrow = algoResult.legalData.removeNarrow == 0 ? false : true;
		ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54* L_144 = (ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54*)(&(&V_9)->___extraInfo_9);
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_145 = V_8;
		GSALegalData_tB87501C567F852AFE055E4A612E06DC6360EB2E7 L_146 = L_145.___legalData_8;
		int32_t L_147 = L_146.___removeNarrow_4;
		G_B28_0 = L_144;
		if (!L_147)
		{
			G_B29_0 = L_144;
			goto IL_03e8;
		}
	}
	{
		G_B30_0 = 1;
		G_B30_1 = G_B28_0;
		goto IL_03e9;
	}

IL_03e8:
	{
		G_B30_0 = 0;
		G_B30_1 = G_B29_0;
	}

IL_03e9:
	{
		G_B30_1->___removeNarrow_4 = (bool)G_B30_0;
		// playAreaInfo.extraInfo.overMaxRange_more = algoResult.legalData.overMaxRange_more == 0 ? false : true;
		ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54* L_148 = (ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54*)(&(&V_9)->___extraInfo_9);
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_149 = V_8;
		GSALegalData_tB87501C567F852AFE055E4A612E06DC6360EB2E7 L_150 = L_149.___legalData_8;
		int32_t L_151 = L_150.___overMaxRange_more_5;
		G_B31_0 = L_148;
		if (!L_151)
		{
			G_B32_0 = L_148;
			goto IL_0406;
		}
	}
	{
		G_B33_0 = 1;
		G_B33_1 = G_B31_0;
		goto IL_0407;
	}

IL_0406:
	{
		G_B33_0 = 0;
		G_B33_1 = G_B32_0;
	}

IL_0407:
	{
		G_B33_1->___overMaxRange_more_5 = (bool)G_B33_0;
		// playAreaInfo.extraInfo.validShrinkArea = algoResult.legalData.validShrinkArea;
		ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54* L_152 = (ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54*)(&(&V_9)->___extraInfo_9);
		GSARect_tDCA16D43A4FD244233F9F2671958A3089A092EC3 L_153 = V_8;
		GSALegalData_tB87501C567F852AFE055E4A612E06DC6360EB2E7 L_154 = L_153.___legalData_8;
		int32_t L_155 = L_154.___validShrinkArea_6;
		L_152->___validShrinkArea_6 = L_155;
		// instance.boundarySystemCallback(playAreaInfo, boundaryPoints, unusedLines);
		Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05* L_156 = ((Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05_StaticFields*)il2cpp_codegen_static_fields_for(Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05_il2cpp_TypeInfo_var))->___instance_0;
		NullCheck(L_156);
		BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD* L_157 = L_156->___boundarySystemCallback_1;
		BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B L_158 = V_9;
		List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* L_159 = V_2;
		List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* L_160 = V_3;
		NullCheck(L_157);
		BoundarySystemCallback_Invoke_m33091366DF51DF2DA3EA52496D5D30C2E56D5DAD_inline(L_157, L_158, L_159, L_160, NULL);
	}

IL_0439:
	{
		// }
		return;
	}
}
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoModule::_SafeAreaCallbackShrink(System.IntPtr,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_SafeAreaAlgoModule__SafeAreaCallbackShrink_m20C04C87D5E2E2708E462363D98BC4924BD3E354 (intptr_t ___0_lineCollectionPtr, intptr_t ___1_safeAreaDetailRectPtr, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m79E50C4F592B1703F4B76A8BE7B4855515460CA1_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m8B5DEF3F8F4F49003BB953399B6E84A6DC941AC6_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_mBE9255218FAB0B859E0DD1B944986BBC7F1C3A33_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_mC54E2BCBE43279A96FC082F5CDE2D76388BD8F9C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Pvr_BoundaryAPI_IntPtrToStruct_TisGSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E_m3C7EC489283FB44610163AB0091A1C279E4F7156_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral07D4E98E332EC0D17F8FB3F458B42EBB2C4EAF29);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* V_2 = NULL;
	List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	GSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E V_6;
	memset((&V_6), 0, sizeof(V_6));
	intptr_t V_7;
	memset((&V_7), 0, sizeof(V_7));
	List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* V_8 = NULL;
	GSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E V_9;
	memset((&V_9), 0, sizeof(V_9));
	intptr_t V_10;
	memset((&V_10), 0, sizeof(V_10));
	int32_t V_11 = 0;
	GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E V_12;
	memset((&V_12), 0, sizeof(V_12));
	List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* V_13 = NULL;
	int32_t V_14 = 0;
	intptr_t V_15;
	memset((&V_15), 0, sizeof(V_15));
	GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 V_16;
	memset((&V_16), 0, sizeof(V_16));
	bool V_17 = false;
	bool V_18 = false;
	bool V_19 = false;
	int32_t V_20 = 0;
	GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E V_21;
	memset((&V_21), 0, sizeof(V_21));
	int32_t V_22 = 0;
	intptr_t V_23;
	memset((&V_23), 0, sizeof(V_23));
	GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 V_24;
	memset((&V_24), 0, sizeof(V_24));
	bool V_25 = false;
	bool V_26 = false;
	int32_t G_B3_0 = 0;
	{
		// if (lineCollectionPtr == IntPtr.Zero || safeAreaDetailRectPtr == IntPtr.Zero)
		intptr_t L_0 = ___0_lineCollectionPtr;
		intptr_t L_1 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		bool L_2;
		L_2 = IntPtr_op_Equality_m7D9CDCDE9DC2A0C2C614633F4921E90187FAB271(L_0, L_1, NULL);
		if (L_2)
		{
			goto IL_001b;
		}
	}
	{
		intptr_t L_3 = ___1_safeAreaDetailRectPtr;
		intptr_t L_4 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		bool L_5;
		L_5 = IntPtr_op_Equality_m7D9CDCDE9DC2A0C2C614633F4921E90187FAB271(L_3, L_4, NULL);
		G_B3_0 = ((int32_t)(L_5));
		goto IL_001c;
	}

IL_001b:
	{
		G_B3_0 = 1;
	}

IL_001c:
	{
		V_0 = (bool)G_B3_0;
		bool L_6 = V_0;
		if (!L_6)
		{
			goto IL_0031;
		}
	}
	{
		// Debug.LogError("BoundarySystem callback is inValid!");
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(_stringLiteral07D4E98E332EC0D17F8FB3F458B42EBB2C4EAF29, NULL);
		// return;
		goto IL_0284;
	}

IL_0031:
	{
		// if (instance.boundarySystemCallbackShrink != null)
		Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05* L_7 = ((Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05_StaticFields*)il2cpp_codegen_static_fields_for(Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05_il2cpp_TypeInfo_var))->___instance_0;
		NullCheck(L_7);
		BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75* L_8 = L_7->___boundarySystemCallbackShrink_2;
		V_1 = (bool)((!(((RuntimeObject*)(BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75*)L_8) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		bool L_9 = V_1;
		if (!L_9)
		{
			goto IL_0284;
		}
	}
	{
		// List<Vector3> boundaryPoints = new List<Vector3>();
		List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* L_10 = (List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*)il2cpp_codegen_object_new(List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B_il2cpp_TypeInfo_var);
		NullCheck(L_10);
		List_1__ctor_mC54E2BCBE43279A96FC082F5CDE2D76388BD8F9C(L_10, List_1__ctor_mC54E2BCBE43279A96FC082F5CDE2D76388BD8F9C_RuntimeMethod_var);
		V_2 = L_10;
		// List<List<Vector3>> unusedLines = new List<List<Vector3>>();
		List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* L_11 = (List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F*)il2cpp_codegen_object_new(List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F_il2cpp_TypeInfo_var);
		NullCheck(L_11);
		List_1__ctor_mBE9255218FAB0B859E0DD1B944986BBC7F1C3A33(L_11, List_1__ctor_mBE9255218FAB0B859E0DD1B944986BBC7F1C3A33_RuntimeMethod_var);
		V_3 = L_11;
		// int byteNum = Marshal.SizeOf(typeof(Pvr_SafeAreaAlgoAPI.GSALine));
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_12 = { reinterpret_cast<intptr_t> (GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_13;
		L_13 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_12, NULL);
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		int32_t L_14;
		L_14 = Marshal_SizeOf_mED64846722033D6F60C2973CA604B7C2D7D4A1B7(L_13, NULL);
		V_4 = L_14;
		// int byteNum2 = Marshal.SizeOf(typeof(Pvr_SafeAreaAlgoAPI.GSAPoint3i));
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_15 = { reinterpret_cast<intptr_t> (GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_0_0_0_var) };
		Type_t* L_16;
		L_16 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_15, NULL);
		int32_t L_17;
		L_17 = Marshal_SizeOf_mED64846722033D6F60C2973CA604B7C2D7D4A1B7(L_16, NULL);
		V_5 = L_17;
		// Pvr_SafeAreaAlgoAPI.GSALineCollection collection = Pvr_BoundaryAPI.IntPtrToStruct<Pvr_SafeAreaAlgoAPI.GSALineCollection>(lineCollectionPtr);
		intptr_t L_18 = ___0_lineCollectionPtr;
		GSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E L_19;
		L_19 = Pvr_BoundaryAPI_IntPtrToStruct_TisGSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E_m3C7EC489283FB44610163AB0091A1C279E4F7156(L_18, Pvr_BoundaryAPI_IntPtrToStruct_TisGSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E_m3C7EC489283FB44610163AB0091A1C279E4F7156_RuntimeMethod_var);
		V_6 = L_19;
		// for (int i = 0; i < collection.lineCount; i++)
		V_11 = 0;
		goto IL_016c;
	}

IL_0084:
	{
		// ptr = new IntPtr(collection.lineArray.ToInt64() + (byteNum * i));
		intptr_t* L_20 = (intptr_t*)(&(&V_6)->___lineArray_0);
		int64_t L_21;
		L_21 = IntPtr_ToInt64_m0F81FB6FB08014074D4F5B915EDAB06A08552032(L_20, NULL);
		int32_t L_22 = V_4;
		int32_t L_23 = V_11;
		IntPtr__ctor_m2C033540A2F274766CF5C2A120587DD997E3F6DC((&V_7), ((int64_t)il2cpp_codegen_add(L_21, ((int64_t)((int32_t)il2cpp_codegen_multiply(L_22, L_23))))), NULL);
		// Pvr_SafeAreaAlgoAPI.GSALine line = (Pvr_SafeAreaAlgoAPI.GSALine)Marshal.PtrToStructure(ptr, typeof(Pvr_SafeAreaAlgoAPI.GSALine));
		intptr_t L_24 = V_7;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_25 = { reinterpret_cast<intptr_t> (GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_26;
		L_26 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_25, NULL);
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		RuntimeObject* L_27;
		L_27 = Marshal_PtrToStructure_m235E141E21BFB69A01B07DDDF1702BA7D5723AC3(L_24, L_26, NULL);
		V_12 = ((*(GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E*)((GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E*)(GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E*)UnBox(L_27, GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E_il2cpp_TypeInfo_var))));
		// List<Vector3> newLine = new List<Vector3>();
		List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* L_28 = (List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*)il2cpp_codegen_object_new(List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B_il2cpp_TypeInfo_var);
		NullCheck(L_28);
		List_1__ctor_mC54E2BCBE43279A96FC082F5CDE2D76388BD8F9C(L_28, List_1__ctor_mC54E2BCBE43279A96FC082F5CDE2D76388BD8F9C_RuntimeMethod_var);
		V_13 = L_28;
		// for (int j = 0; j < line.pointCount; j++)
		V_14 = 0;
		goto IL_0134;
	}

IL_00c3:
	{
		// IntPtr tptr = new IntPtr(line.pointArray.ToInt64() + (byteNum2 * j));
		intptr_t* L_29 = (intptr_t*)(&(&V_12)->___pointArray_0);
		int64_t L_30;
		L_30 = IntPtr_ToInt64_m0F81FB6FB08014074D4F5B915EDAB06A08552032(L_29, NULL);
		int32_t L_31 = V_5;
		int32_t L_32 = V_14;
		IntPtr__ctor_m2C033540A2F274766CF5C2A120587DD997E3F6DC((&V_15), ((int64_t)il2cpp_codegen_add(L_30, ((int64_t)((int32_t)il2cpp_codegen_multiply(L_31, L_32))))), NULL);
		// Pvr_SafeAreaAlgoAPI.GSAPoint3i point = (Pvr_SafeAreaAlgoAPI.GSAPoint3i)Marshal.PtrToStructure(tptr, typeof(Pvr_SafeAreaAlgoAPI.GSAPoint3i));
		intptr_t L_33 = V_15;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_34 = { reinterpret_cast<intptr_t> (GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_35;
		L_35 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_34, NULL);
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		RuntimeObject* L_36;
		L_36 = Marshal_PtrToStructure_m235E141E21BFB69A01B07DDDF1702BA7D5723AC3(L_33, L_35, NULL);
		V_16 = ((*(GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17*)((GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17*)(GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17*)UnBox(L_36, GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_il2cpp_TypeInfo_var))));
		// newLine.Add(new Vector3(point.x / 1000f, point.y / 1000f, point.z / 1000f));
		List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* L_37 = V_13;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_38 = V_16;
		int32_t L_39 = L_38.___x_0;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_40 = V_16;
		int32_t L_41 = L_40.___y_1;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_42 = V_16;
		int32_t L_43 = L_42.___z_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_44;
		memset((&L_44), 0, sizeof(L_44));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_44), ((float)(((float)L_39)/(1000.0f))), ((float)(((float)L_41)/(1000.0f))), ((float)(((float)L_43)/(1000.0f))), /*hidden argument*/NULL);
		NullCheck(L_37);
		List_1_Add_m79E50C4F592B1703F4B76A8BE7B4855515460CA1_inline(L_37, L_44, List_1_Add_m79E50C4F592B1703F4B76A8BE7B4855515460CA1_RuntimeMethod_var);
		// for (int j = 0; j < line.pointCount; j++)
		int32_t L_45 = V_14;
		V_14 = ((int32_t)il2cpp_codegen_add(L_45, 1));
	}

IL_0134:
	{
		// for (int j = 0; j < line.pointCount; j++)
		int32_t L_46 = V_14;
		GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E L_47 = V_12;
		int32_t L_48 = L_47.___pointCount_1;
		V_17 = (bool)((((int32_t)L_46) < ((int32_t)L_48))? 1 : 0);
		bool L_49 = V_17;
		if (L_49)
		{
			goto IL_00c3;
		}
	}
	{
		// if (i == 0) // first line for colsed boundary
		int32_t L_50 = V_11;
		V_18 = (bool)((((int32_t)L_50) == ((int32_t)0))? 1 : 0);
		bool L_51 = V_18;
		if (!L_51)
		{
			goto IL_015a;
		}
	}
	{
		// boundaryPoints = newLine;
		List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* L_52 = V_13;
		V_2 = L_52;
		goto IL_0165;
	}

IL_015a:
	{
		// unusedLines.Add(newLine);
		List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* L_53 = V_3;
		List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* L_54 = V_13;
		NullCheck(L_53);
		List_1_Add_m8B5DEF3F8F4F49003BB953399B6E84A6DC941AC6_inline(L_53, L_54, List_1_Add_m8B5DEF3F8F4F49003BB953399B6E84A6DC941AC6_RuntimeMethod_var);
	}

IL_0165:
	{
		// for (int i = 0; i < collection.lineCount; i++)
		int32_t L_55 = V_11;
		V_11 = ((int32_t)il2cpp_codegen_add(L_55, 1));
	}

IL_016c:
	{
		// for (int i = 0; i < collection.lineCount; i++)
		int32_t L_56 = V_11;
		GSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E L_57 = V_6;
		int32_t L_58 = L_57.___lineCount_1;
		V_19 = (bool)((((int32_t)L_56) < ((int32_t)L_58))? 1 : 0);
		bool L_59 = V_19;
		if (L_59)
		{
			goto IL_0084;
		}
	}
	{
		// List<Vector3> rectPoints = new List<Vector3>();
		List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* L_60 = (List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*)il2cpp_codegen_object_new(List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B_il2cpp_TypeInfo_var);
		NullCheck(L_60);
		List_1__ctor_mC54E2BCBE43279A96FC082F5CDE2D76388BD8F9C(L_60, List_1__ctor_mC54E2BCBE43279A96FC082F5CDE2D76388BD8F9C_RuntimeMethod_var);
		V_8 = L_60;
		// Pvr_SafeAreaAlgoAPI.GSALineCollection safeAreaRectLineCollection = Pvr_BoundaryAPI.IntPtrToStruct<Pvr_SafeAreaAlgoAPI.GSALineCollection>(safeAreaDetailRectPtr);
		intptr_t L_61 = ___1_safeAreaDetailRectPtr;
		GSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E L_62;
		L_62 = Pvr_BoundaryAPI_IntPtrToStruct_TisGSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E_m3C7EC489283FB44610163AB0091A1C279E4F7156(L_61, Pvr_BoundaryAPI_IntPtrToStruct_TisGSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E_m3C7EC489283FB44610163AB0091A1C279E4F7156_RuntimeMethod_var);
		V_9 = L_62;
		// for (int i = 0; i < safeAreaRectLineCollection.lineCount; i++)
		V_20 = 0;
		goto IL_025b;
	}

IL_0197:
	{
		// safeAreaRectLinePtr = new IntPtr(safeAreaRectLineCollection.lineArray.ToInt64() + (byteNum * i));
		intptr_t* L_63 = (intptr_t*)(&(&V_9)->___lineArray_0);
		int64_t L_64;
		L_64 = IntPtr_ToInt64_m0F81FB6FB08014074D4F5B915EDAB06A08552032(L_63, NULL);
		int32_t L_65 = V_4;
		int32_t L_66 = V_20;
		IntPtr__ctor_m2C033540A2F274766CF5C2A120587DD997E3F6DC((&V_10), ((int64_t)il2cpp_codegen_add(L_64, ((int64_t)((int32_t)il2cpp_codegen_multiply(L_65, L_66))))), NULL);
		// Pvr_SafeAreaAlgoAPI.GSALine line = (Pvr_SafeAreaAlgoAPI.GSALine)Marshal.PtrToStructure(safeAreaRectLinePtr, typeof(Pvr_SafeAreaAlgoAPI.GSALine));
		intptr_t L_67 = V_10;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_68 = { reinterpret_cast<intptr_t> (GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_69;
		L_69 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_68, NULL);
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		RuntimeObject* L_70;
		L_70 = Marshal_PtrToStructure_m235E141E21BFB69A01B07DDDF1702BA7D5723AC3(L_67, L_69, NULL);
		V_21 = ((*(GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E*)((GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E*)(GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E*)UnBox(L_70, GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E_il2cpp_TypeInfo_var))));
		// for (int j = 0; j < line.pointCount; j++)
		V_22 = 0;
		goto IL_0240;
	}

IL_01cf:
	{
		// IntPtr tptr = new IntPtr(line.pointArray.ToInt64() + (byteNum2 * j));
		intptr_t* L_71 = (intptr_t*)(&(&V_21)->___pointArray_0);
		int64_t L_72;
		L_72 = IntPtr_ToInt64_m0F81FB6FB08014074D4F5B915EDAB06A08552032(L_71, NULL);
		int32_t L_73 = V_5;
		int32_t L_74 = V_22;
		IntPtr__ctor_m2C033540A2F274766CF5C2A120587DD997E3F6DC((&V_23), ((int64_t)il2cpp_codegen_add(L_72, ((int64_t)((int32_t)il2cpp_codegen_multiply(L_73, L_74))))), NULL);
		// Pvr_SafeAreaAlgoAPI.GSAPoint3i point = (Pvr_SafeAreaAlgoAPI.GSAPoint3i)Marshal.PtrToStructure(tptr, typeof(Pvr_SafeAreaAlgoAPI.GSAPoint3i));
		intptr_t L_75 = V_23;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_76 = { reinterpret_cast<intptr_t> (GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_77;
		L_77 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_76, NULL);
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		RuntimeObject* L_78;
		L_78 = Marshal_PtrToStructure_m235E141E21BFB69A01B07DDDF1702BA7D5723AC3(L_75, L_77, NULL);
		V_24 = ((*(GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17*)((GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17*)(GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17*)UnBox(L_78, GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17_il2cpp_TypeInfo_var))));
		// rectPoints.Add(new Vector3(point.x / 1000f, point.y / 1000f, point.z / 1000f));
		List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* L_79 = V_8;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_80 = V_24;
		int32_t L_81 = L_80.___x_0;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_82 = V_24;
		int32_t L_83 = L_82.___y_1;
		GSAPoint3i_t2DA179D864DF3D979E16E4D755FDBC5FF1474B17 L_84 = V_24;
		int32_t L_85 = L_84.___z_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_86;
		memset((&L_86), 0, sizeof(L_86));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_86), ((float)(((float)L_81)/(1000.0f))), ((float)(((float)L_83)/(1000.0f))), ((float)(((float)L_85)/(1000.0f))), /*hidden argument*/NULL);
		NullCheck(L_79);
		List_1_Add_m79E50C4F592B1703F4B76A8BE7B4855515460CA1_inline(L_79, L_86, List_1_Add_m79E50C4F592B1703F4B76A8BE7B4855515460CA1_RuntimeMethod_var);
		// for (int j = 0; j < line.pointCount; j++)
		int32_t L_87 = V_22;
		V_22 = ((int32_t)il2cpp_codegen_add(L_87, 1));
	}

IL_0240:
	{
		// for (int j = 0; j < line.pointCount; j++)
		int32_t L_88 = V_22;
		GSALine_t6A49988B917A7709C1B52B7087F9B4F051B61C0E L_89 = V_21;
		int32_t L_90 = L_89.___pointCount_1;
		V_25 = (bool)((((int32_t)L_88) < ((int32_t)L_90))? 1 : 0);
		bool L_91 = V_25;
		if (L_91)
		{
			goto IL_01cf;
		}
	}
	{
		// for (int i = 0; i < safeAreaRectLineCollection.lineCount; i++)
		int32_t L_92 = V_20;
		V_20 = ((int32_t)il2cpp_codegen_add(L_92, 1));
	}

IL_025b:
	{
		// for (int i = 0; i < safeAreaRectLineCollection.lineCount; i++)
		int32_t L_93 = V_20;
		GSALineCollection_tFE4CD5999DE47E9BCF5030FB21DED65BC96D2B9E L_94 = V_9;
		int32_t L_95 = L_94.___lineCount_1;
		V_26 = (bool)((((int32_t)L_93) < ((int32_t)L_95))? 1 : 0);
		bool L_96 = V_26;
		if (L_96)
		{
			goto IL_0197;
		}
	}
	{
		// instance.boundarySystemCallbackShrink(rectPoints, boundaryPoints, unusedLines);
		Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05* L_97 = ((Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05_StaticFields*)il2cpp_codegen_static_fields_for(Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05_il2cpp_TypeInfo_var))->___instance_0;
		NullCheck(L_97);
		BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75* L_98 = L_97->___boundarySystemCallbackShrink_2;
		List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* L_99 = V_8;
		List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* L_100 = V_2;
		List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* L_101 = V_3;
		NullCheck(L_98);
		BoundarySystemCallbackShrink_Invoke_m69E0E70D187835048D58FDE12323505C86C604F5_inline(L_98, L_99, L_100, L_101, NULL);
	}

IL_0284:
	{
		// }
		return;
	}
}
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoModule::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pvr_SafeAreaAlgoModule__ctor_mA8244BBC99C77398D1BC4BC85F483CF0A7AC8943 (Pvr_SafeAreaAlgoModule_t69DFBBFD404803F5FBD5E50CB8C499BF36A70B05* __this, const RuntimeMethod* method) 
{
	{
		// private BoundarySystemCallback boundarySystemCallback = null;
		__this->___boundarySystemCallback_1 = (BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___boundarySystemCallback_1), (void*)(BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD*)NULL);
		// private BoundarySystemCallbackShrink boundarySystemCallbackShrink = null;
		__this->___boundarySystemCallbackShrink_2 = (BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___boundarySystemCallbackShrink_2), (void*)(BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75*)NULL);
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Conversion methods for marshalling of: BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/ExtraInfo
IL2CPP_EXTERN_C void ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshal_pinvoke(const ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54& unmarshaled, ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshaled_pinvoke& marshaled)
{
	marshaled.___overMaxRange_0 = static_cast<int32_t>(unmarshaled.___overMaxRange_0);
	marshaled.___includeBigGap_1 = static_cast<int32_t>(unmarshaled.___includeBigGap_1);
	marshaled.___bigGapNum_2 = unmarshaled.___bigGapNum_2;
	marshaled.___centerOut_3 = static_cast<int32_t>(unmarshaled.___centerOut_3);
	marshaled.___removeNarrow_4 = static_cast<int32_t>(unmarshaled.___removeNarrow_4);
	marshaled.___overMaxRange_more_5 = static_cast<int32_t>(unmarshaled.___overMaxRange_more_5);
	marshaled.___validShrinkArea_6 = unmarshaled.___validShrinkArea_6;
}
IL2CPP_EXTERN_C void ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshal_pinvoke_back(const ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshaled_pinvoke& marshaled, ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54& unmarshaled)
{
	bool unmarshaledoverMaxRange_temp_0 = false;
	unmarshaledoverMaxRange_temp_0 = static_cast<bool>(marshaled.___overMaxRange_0);
	unmarshaled.___overMaxRange_0 = unmarshaledoverMaxRange_temp_0;
	bool unmarshaledincludeBigGap_temp_1 = false;
	unmarshaledincludeBigGap_temp_1 = static_cast<bool>(marshaled.___includeBigGap_1);
	unmarshaled.___includeBigGap_1 = unmarshaledincludeBigGap_temp_1;
	int32_t unmarshaledbigGapNum_temp_2 = 0;
	unmarshaledbigGapNum_temp_2 = marshaled.___bigGapNum_2;
	unmarshaled.___bigGapNum_2 = unmarshaledbigGapNum_temp_2;
	bool unmarshaledcenterOut_temp_3 = false;
	unmarshaledcenterOut_temp_3 = static_cast<bool>(marshaled.___centerOut_3);
	unmarshaled.___centerOut_3 = unmarshaledcenterOut_temp_3;
	bool unmarshaledremoveNarrow_temp_4 = false;
	unmarshaledremoveNarrow_temp_4 = static_cast<bool>(marshaled.___removeNarrow_4);
	unmarshaled.___removeNarrow_4 = unmarshaledremoveNarrow_temp_4;
	bool unmarshaledoverMaxRange_more_temp_5 = false;
	unmarshaledoverMaxRange_more_temp_5 = static_cast<bool>(marshaled.___overMaxRange_more_5);
	unmarshaled.___overMaxRange_more_5 = unmarshaledoverMaxRange_more_temp_5;
	int32_t unmarshaledvalidShrinkArea_temp_6 = 0;
	unmarshaledvalidShrinkArea_temp_6 = marshaled.___validShrinkArea_6;
	unmarshaled.___validShrinkArea_6 = unmarshaledvalidShrinkArea_temp_6;
}
// Conversion method for clean up from marshalling of: BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/ExtraInfo
IL2CPP_EXTERN_C void ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshal_pinvoke_cleanup(ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshaled_pinvoke& marshaled)
{
}
// Conversion methods for marshalling of: BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/ExtraInfo
IL2CPP_EXTERN_C void ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshal_com(const ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54& unmarshaled, ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshaled_com& marshaled)
{
	marshaled.___overMaxRange_0 = static_cast<int32_t>(unmarshaled.___overMaxRange_0);
	marshaled.___includeBigGap_1 = static_cast<int32_t>(unmarshaled.___includeBigGap_1);
	marshaled.___bigGapNum_2 = unmarshaled.___bigGapNum_2;
	marshaled.___centerOut_3 = static_cast<int32_t>(unmarshaled.___centerOut_3);
	marshaled.___removeNarrow_4 = static_cast<int32_t>(unmarshaled.___removeNarrow_4);
	marshaled.___overMaxRange_more_5 = static_cast<int32_t>(unmarshaled.___overMaxRange_more_5);
	marshaled.___validShrinkArea_6 = unmarshaled.___validShrinkArea_6;
}
IL2CPP_EXTERN_C void ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshal_com_back(const ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshaled_com& marshaled, ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54& unmarshaled)
{
	bool unmarshaledoverMaxRange_temp_0 = false;
	unmarshaledoverMaxRange_temp_0 = static_cast<bool>(marshaled.___overMaxRange_0);
	unmarshaled.___overMaxRange_0 = unmarshaledoverMaxRange_temp_0;
	bool unmarshaledincludeBigGap_temp_1 = false;
	unmarshaledincludeBigGap_temp_1 = static_cast<bool>(marshaled.___includeBigGap_1);
	unmarshaled.___includeBigGap_1 = unmarshaledincludeBigGap_temp_1;
	int32_t unmarshaledbigGapNum_temp_2 = 0;
	unmarshaledbigGapNum_temp_2 = marshaled.___bigGapNum_2;
	unmarshaled.___bigGapNum_2 = unmarshaledbigGapNum_temp_2;
	bool unmarshaledcenterOut_temp_3 = false;
	unmarshaledcenterOut_temp_3 = static_cast<bool>(marshaled.___centerOut_3);
	unmarshaled.___centerOut_3 = unmarshaledcenterOut_temp_3;
	bool unmarshaledremoveNarrow_temp_4 = false;
	unmarshaledremoveNarrow_temp_4 = static_cast<bool>(marshaled.___removeNarrow_4);
	unmarshaled.___removeNarrow_4 = unmarshaledremoveNarrow_temp_4;
	bool unmarshaledoverMaxRange_more_temp_5 = false;
	unmarshaledoverMaxRange_more_temp_5 = static_cast<bool>(marshaled.___overMaxRange_more_5);
	unmarshaled.___overMaxRange_more_5 = unmarshaledoverMaxRange_more_temp_5;
	int32_t unmarshaledvalidShrinkArea_temp_6 = 0;
	unmarshaledvalidShrinkArea_temp_6 = marshaled.___validShrinkArea_6;
	unmarshaled.___validShrinkArea_6 = unmarshaledvalidShrinkArea_temp_6;
}
// Conversion method for clean up from marshalling of: BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/ExtraInfo
IL2CPP_EXTERN_C void ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshal_com_cleanup(ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshaled_com& marshaled)
{
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif


// Conversion methods for marshalling of: BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundaryPlayerArea
IL2CPP_EXTERN_C void BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B_marshal_pinvoke(const BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B& unmarshaled, BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B_marshaled_pinvoke& marshaled)
{
	marshaled.___lowerleft_0 = unmarshaled.___lowerleft_0;
	marshaled.___upperleft_1 = unmarshaled.___upperleft_1;
	marshaled.___upperRight_2 = unmarshaled.___upperRight_2;
	marshaled.___lowerRight_3 = unmarshaled.___lowerRight_3;
	marshaled.___center_4 = unmarshaled.___center_4;
	marshaled.___width_5 = unmarshaled.___width_5;
	marshaled.___height_6 = unmarshaled.___height_6;
	marshaled.___isLegal_7 = static_cast<int32_t>(unmarshaled.___isLegal_7);
	marshaled.___firstcenter_8 = unmarshaled.___firstcenter_8;
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshal_pinvoke(unmarshaled.___extraInfo_9, marshaled.___extraInfo_9);
}
IL2CPP_EXTERN_C void BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B_marshal_pinvoke_back(const BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B_marshaled_pinvoke& marshaled, BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B& unmarshaled)
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 unmarshaledlowerleft_temp_0;
	memset((&unmarshaledlowerleft_temp_0), 0, sizeof(unmarshaledlowerleft_temp_0));
	unmarshaledlowerleft_temp_0 = marshaled.___lowerleft_0;
	unmarshaled.___lowerleft_0 = unmarshaledlowerleft_temp_0;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 unmarshaledupperleft_temp_1;
	memset((&unmarshaledupperleft_temp_1), 0, sizeof(unmarshaledupperleft_temp_1));
	unmarshaledupperleft_temp_1 = marshaled.___upperleft_1;
	unmarshaled.___upperleft_1 = unmarshaledupperleft_temp_1;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 unmarshaledupperRight_temp_2;
	memset((&unmarshaledupperRight_temp_2), 0, sizeof(unmarshaledupperRight_temp_2));
	unmarshaledupperRight_temp_2 = marshaled.___upperRight_2;
	unmarshaled.___upperRight_2 = unmarshaledupperRight_temp_2;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 unmarshaledlowerRight_temp_3;
	memset((&unmarshaledlowerRight_temp_3), 0, sizeof(unmarshaledlowerRight_temp_3));
	unmarshaledlowerRight_temp_3 = marshaled.___lowerRight_3;
	unmarshaled.___lowerRight_3 = unmarshaledlowerRight_temp_3;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 unmarshaledcenter_temp_4;
	memset((&unmarshaledcenter_temp_4), 0, sizeof(unmarshaledcenter_temp_4));
	unmarshaledcenter_temp_4 = marshaled.___center_4;
	unmarshaled.___center_4 = unmarshaledcenter_temp_4;
	uint32_t unmarshaledwidth_temp_5 = 0;
	unmarshaledwidth_temp_5 = marshaled.___width_5;
	unmarshaled.___width_5 = unmarshaledwidth_temp_5;
	uint32_t unmarshaledheight_temp_6 = 0;
	unmarshaledheight_temp_6 = marshaled.___height_6;
	unmarshaled.___height_6 = unmarshaledheight_temp_6;
	bool unmarshaledisLegal_temp_7 = false;
	unmarshaledisLegal_temp_7 = static_cast<bool>(marshaled.___isLegal_7);
	unmarshaled.___isLegal_7 = unmarshaledisLegal_temp_7;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 unmarshaledfirstcenter_temp_8;
	memset((&unmarshaledfirstcenter_temp_8), 0, sizeof(unmarshaledfirstcenter_temp_8));
	unmarshaledfirstcenter_temp_8 = marshaled.___firstcenter_8;
	unmarshaled.___firstcenter_8 = unmarshaledfirstcenter_temp_8;
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54 unmarshaledextraInfo_temp_9;
	memset((&unmarshaledextraInfo_temp_9), 0, sizeof(unmarshaledextraInfo_temp_9));
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshal_pinvoke_back(marshaled.___extraInfo_9, unmarshaledextraInfo_temp_9);
	unmarshaled.___extraInfo_9 = unmarshaledextraInfo_temp_9;
}
// Conversion method for clean up from marshalling of: BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundaryPlayerArea
IL2CPP_EXTERN_C void BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B_marshal_pinvoke_cleanup(BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B_marshaled_pinvoke& marshaled)
{
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshal_pinvoke_cleanup(marshaled.___extraInfo_9);
}


// Conversion methods for marshalling of: BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundaryPlayerArea
IL2CPP_EXTERN_C void BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B_marshal_com(const BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B& unmarshaled, BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B_marshaled_com& marshaled)
{
	marshaled.___lowerleft_0 = unmarshaled.___lowerleft_0;
	marshaled.___upperleft_1 = unmarshaled.___upperleft_1;
	marshaled.___upperRight_2 = unmarshaled.___upperRight_2;
	marshaled.___lowerRight_3 = unmarshaled.___lowerRight_3;
	marshaled.___center_4 = unmarshaled.___center_4;
	marshaled.___width_5 = unmarshaled.___width_5;
	marshaled.___height_6 = unmarshaled.___height_6;
	marshaled.___isLegal_7 = static_cast<int32_t>(unmarshaled.___isLegal_7);
	marshaled.___firstcenter_8 = unmarshaled.___firstcenter_8;
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshal_com(unmarshaled.___extraInfo_9, marshaled.___extraInfo_9);
}
IL2CPP_EXTERN_C void BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B_marshal_com_back(const BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B_marshaled_com& marshaled, BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B& unmarshaled)
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 unmarshaledlowerleft_temp_0;
	memset((&unmarshaledlowerleft_temp_0), 0, sizeof(unmarshaledlowerleft_temp_0));
	unmarshaledlowerleft_temp_0 = marshaled.___lowerleft_0;
	unmarshaled.___lowerleft_0 = unmarshaledlowerleft_temp_0;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 unmarshaledupperleft_temp_1;
	memset((&unmarshaledupperleft_temp_1), 0, sizeof(unmarshaledupperleft_temp_1));
	unmarshaledupperleft_temp_1 = marshaled.___upperleft_1;
	unmarshaled.___upperleft_1 = unmarshaledupperleft_temp_1;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 unmarshaledupperRight_temp_2;
	memset((&unmarshaledupperRight_temp_2), 0, sizeof(unmarshaledupperRight_temp_2));
	unmarshaledupperRight_temp_2 = marshaled.___upperRight_2;
	unmarshaled.___upperRight_2 = unmarshaledupperRight_temp_2;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 unmarshaledlowerRight_temp_3;
	memset((&unmarshaledlowerRight_temp_3), 0, sizeof(unmarshaledlowerRight_temp_3));
	unmarshaledlowerRight_temp_3 = marshaled.___lowerRight_3;
	unmarshaled.___lowerRight_3 = unmarshaledlowerRight_temp_3;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 unmarshaledcenter_temp_4;
	memset((&unmarshaledcenter_temp_4), 0, sizeof(unmarshaledcenter_temp_4));
	unmarshaledcenter_temp_4 = marshaled.___center_4;
	unmarshaled.___center_4 = unmarshaledcenter_temp_4;
	uint32_t unmarshaledwidth_temp_5 = 0;
	unmarshaledwidth_temp_5 = marshaled.___width_5;
	unmarshaled.___width_5 = unmarshaledwidth_temp_5;
	uint32_t unmarshaledheight_temp_6 = 0;
	unmarshaledheight_temp_6 = marshaled.___height_6;
	unmarshaled.___height_6 = unmarshaledheight_temp_6;
	bool unmarshaledisLegal_temp_7 = false;
	unmarshaledisLegal_temp_7 = static_cast<bool>(marshaled.___isLegal_7);
	unmarshaled.___isLegal_7 = unmarshaledisLegal_temp_7;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 unmarshaledfirstcenter_temp_8;
	memset((&unmarshaledfirstcenter_temp_8), 0, sizeof(unmarshaledfirstcenter_temp_8));
	unmarshaledfirstcenter_temp_8 = marshaled.___firstcenter_8;
	unmarshaled.___firstcenter_8 = unmarshaledfirstcenter_temp_8;
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54 unmarshaledextraInfo_temp_9;
	memset((&unmarshaledextraInfo_temp_9), 0, sizeof(unmarshaledextraInfo_temp_9));
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshal_com_back(marshaled.___extraInfo_9, unmarshaledextraInfo_temp_9);
	unmarshaled.___extraInfo_9 = unmarshaledextraInfo_temp_9;
}
// Conversion method for clean up from marshalling of: BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundaryPlayerArea
IL2CPP_EXTERN_C void BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B_marshal_com_cleanup(BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B_marshaled_com& marshaled)
{
	ExtraInfo_tFBF561AE0E37A2E37379E442D2E24CDCFD93BA54_marshal_com_cleanup(marshaled.___extraInfo_9);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void BoundarySystemCallback_Invoke_m33091366DF51DF2DA3EA52496D5D30C2E56D5DAD_Multicast(BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD* __this, BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B ___0_playAreaInfo, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___1_boundaryPoints, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* ___2_unusedLines, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates_13->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates_13->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD* currentDelegate = reinterpret_cast<BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F*, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl_1)((Il2CppObject*)currentDelegate->___method_code_6, ___0_playAreaInfo, ___1_boundaryPoints, ___2_unusedLines, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method_3));
	}
}
void BoundarySystemCallback_Invoke_m33091366DF51DF2DA3EA52496D5D30C2E56D5DAD_OpenInst(BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD* __this, BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B ___0_playAreaInfo, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___1_boundaryPoints, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* ___2_unusedLines, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F*, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___0_playAreaInfo, ___1_boundaryPoints, ___2_unusedLines, method);
}
void BoundarySystemCallback_Invoke_m33091366DF51DF2DA3EA52496D5D30C2E56D5DAD_OpenStatic(BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD* __this, BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B ___0_playAreaInfo, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___1_boundaryPoints, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* ___2_unusedLines, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F*, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___0_playAreaInfo, ___1_boundaryPoints, ___2_unusedLines, method);
}
void BoundarySystemCallback_Invoke_m33091366DF51DF2DA3EA52496D5D30C2E56D5DAD_OpenStaticInvoker(BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD* __this, BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B ___0_playAreaInfo, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___1_boundaryPoints, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* ___2_unusedLines, const RuntimeMethod* method)
{
	InvokerActionInvoker3< BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, ___0_playAreaInfo, ___1_boundaryPoints, ___2_unusedLines);
}
void BoundarySystemCallback_Invoke_m33091366DF51DF2DA3EA52496D5D30C2E56D5DAD_ClosedStaticInvoker(BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD* __this, BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B ___0_playAreaInfo, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___1_boundaryPoints, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* ___2_unusedLines, const RuntimeMethod* method)
{
	InvokerActionInvoker4< RuntimeObject*, BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, __this->___m_target_2, ___0_playAreaInfo, ___1_boundaryPoints, ___2_unusedLines);
}
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundarySystemCallback::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundarySystemCallback__ctor_m694BDE0105688926273F88E1E5B52949A2995660 (BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr_0 = (intptr_t)il2cpp_codegen_get_virtual_call_method_pointer((RuntimeMethod*)___1_method);
	__this->___method_3 = ___1_method;
	__this->___m_target_2 = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target_2), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code_6 = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 3;
		if (il2cpp_codegen_call_method_via_invoker((RuntimeMethod*)___1_method))
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&BoundarySystemCallback_Invoke_m33091366DF51DF2DA3EA52496D5D30C2E56D5DAD_OpenStaticInvoker;
			else
				__this->___invoke_impl_1 = (intptr_t)&BoundarySystemCallback_Invoke_m33091366DF51DF2DA3EA52496D5D30C2E56D5DAD_ClosedStaticInvoker;
		else
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&BoundarySystemCallback_Invoke_m33091366DF51DF2DA3EA52496D5D30C2E56D5DAD_OpenStatic;
			else
				{
					__this->___invoke_impl_1 = __this->___method_ptr_0;
					__this->___method_code_6 = (intptr_t)__this->___m_target_2;
				}
	}
	else
	{
		if (___0_object == NULL)
			il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
		__this->___invoke_impl_1 = __this->___method_ptr_0;
		__this->___method_code_6 = (intptr_t)__this->___m_target_2;
	}
	__this->___extra_arg_5 = (intptr_t)&BoundarySystemCallback_Invoke_m33091366DF51DF2DA3EA52496D5D30C2E56D5DAD_Multicast;
}
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundarySystemCallback::Invoke(BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundaryPlayerArea,System.Collections.Generic.List`1<UnityEngine.Vector3>,System.Collections.Generic.List`1<System.Collections.Generic.List`1<UnityEngine.Vector3>>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundarySystemCallback_Invoke_m33091366DF51DF2DA3EA52496D5D30C2E56D5DAD (BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD* __this, BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B ___0_playAreaInfo, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___1_boundaryPoints, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* ___2_unusedLines, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_playAreaInfo, ___1_boundaryPoints, ___2_unusedLines, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
// System.IAsyncResult BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundarySystemCallback::BeginInvoke(BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundaryPlayerArea,System.Collections.Generic.List`1<UnityEngine.Vector3>,System.Collections.Generic.List`1<System.Collections.Generic.List`1<UnityEngine.Vector3>>,System.AsyncCallback,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* BoundarySystemCallback_BeginInvoke_mF44BC1F483DE7D9051EFED51CC3EAE28CF8092F1 (BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD* __this, BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B ___0_playAreaInfo, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___1_boundaryPoints, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* ___2_unusedLines, AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___3_callback, RuntimeObject* ___4_object, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	void *__d_args[4] = {0};
	__d_args[0] = Box(BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B_il2cpp_TypeInfo_var, &___0_playAreaInfo);
	__d_args[1] = ___1_boundaryPoints;
	__d_args[2] = ___2_unusedLines;
	return (RuntimeObject*)il2cpp_codegen_delegate_begin_invoke((RuntimeDelegate*)__this, __d_args, (RuntimeDelegate*)___3_callback, (RuntimeObject*)___4_object);
}
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundarySystemCallback::EndInvoke(System.IAsyncResult)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundarySystemCallback_EndInvoke_m5AECAC09503FB28AEAB04BF7D91B31A1B658C207 (BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD* __this, RuntimeObject* ___0_result, const RuntimeMethod* method) 
{
	il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___0_result, 0);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void BoundarySystemCallbackShrink_Invoke_m69E0E70D187835048D58FDE12323505C86C604F5_Multicast(BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75* __this, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___0_rectPoints, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___1_boundaryPoints, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* ___2_unusedLines, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates_13->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates_13->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75* currentDelegate = reinterpret_cast<BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F*, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl_1)((Il2CppObject*)currentDelegate->___method_code_6, ___0_rectPoints, ___1_boundaryPoints, ___2_unusedLines, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method_3));
	}
}
void BoundarySystemCallbackShrink_Invoke_m69E0E70D187835048D58FDE12323505C86C604F5_OpenInst(BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75* __this, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___0_rectPoints, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___1_boundaryPoints, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* ___2_unusedLines, const RuntimeMethod* method)
{
	NullCheck(___0_rectPoints);
	typedef void (*FunctionPointerType) (List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F*, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___0_rectPoints, ___1_boundaryPoints, ___2_unusedLines, method);
}
void BoundarySystemCallbackShrink_Invoke_m69E0E70D187835048D58FDE12323505C86C604F5_OpenStatic(BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75* __this, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___0_rectPoints, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___1_boundaryPoints, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* ___2_unusedLines, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F*, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___0_rectPoints, ___1_boundaryPoints, ___2_unusedLines, method);
}
void BoundarySystemCallbackShrink_Invoke_m69E0E70D187835048D58FDE12323505C86C604F5_OpenStaticInvoker(BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75* __this, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___0_rectPoints, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___1_boundaryPoints, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* ___2_unusedLines, const RuntimeMethod* method)
{
	InvokerActionInvoker3< List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, ___0_rectPoints, ___1_boundaryPoints, ___2_unusedLines);
}
void BoundarySystemCallbackShrink_Invoke_m69E0E70D187835048D58FDE12323505C86C604F5_ClosedStaticInvoker(BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75* __this, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___0_rectPoints, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___1_boundaryPoints, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* ___2_unusedLines, const RuntimeMethod* method)
{
	InvokerActionInvoker4< RuntimeObject*, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, __this->___m_target_2, ___0_rectPoints, ___1_boundaryPoints, ___2_unusedLines);
}
void BoundarySystemCallbackShrink_Invoke_m69E0E70D187835048D58FDE12323505C86C604F5_OpenVirtual(BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75* __this, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___0_rectPoints, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___1_boundaryPoints, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* ___2_unusedLines, const RuntimeMethod* method)
{
	NullCheck(___0_rectPoints);
	VirtualActionInvoker2< List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* >::Invoke(il2cpp_codegen_method_get_slot(method), ___0_rectPoints, ___1_boundaryPoints, ___2_unusedLines);
}
void BoundarySystemCallbackShrink_Invoke_m69E0E70D187835048D58FDE12323505C86C604F5_OpenInterface(BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75* __this, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___0_rectPoints, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___1_boundaryPoints, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* ___2_unusedLines, const RuntimeMethod* method)
{
	NullCheck(___0_rectPoints);
	InterfaceActionInvoker2< List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* >::Invoke(il2cpp_codegen_method_get_slot(method), il2cpp_codegen_method_get_declaring_type(method), ___0_rectPoints, ___1_boundaryPoints, ___2_unusedLines);
}
void BoundarySystemCallbackShrink_Invoke_m69E0E70D187835048D58FDE12323505C86C604F5_OpenGenericVirtual(BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75* __this, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___0_rectPoints, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___1_boundaryPoints, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* ___2_unusedLines, const RuntimeMethod* method)
{
	NullCheck(___0_rectPoints);
	GenericVirtualActionInvoker2< List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* >::Invoke(method, ___0_rectPoints, ___1_boundaryPoints, ___2_unusedLines);
}
void BoundarySystemCallbackShrink_Invoke_m69E0E70D187835048D58FDE12323505C86C604F5_OpenGenericInterface(BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75* __this, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___0_rectPoints, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___1_boundaryPoints, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* ___2_unusedLines, const RuntimeMethod* method)
{
	NullCheck(___0_rectPoints);
	GenericInterfaceActionInvoker2< List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* >::Invoke(method, ___0_rectPoints, ___1_boundaryPoints, ___2_unusedLines);
}
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundarySystemCallbackShrink::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundarySystemCallbackShrink__ctor_m6C97A77E91FC8455141249638E2464192F6E0318 (BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr_0 = (intptr_t)il2cpp_codegen_get_virtual_call_method_pointer((RuntimeMethod*)___1_method);
	__this->___method_3 = ___1_method;
	__this->___m_target_2 = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target_2), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code_6 = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 3;
		if (il2cpp_codegen_call_method_via_invoker((RuntimeMethod*)___1_method))
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&BoundarySystemCallbackShrink_Invoke_m69E0E70D187835048D58FDE12323505C86C604F5_OpenStaticInvoker;
			else
				__this->___invoke_impl_1 = (intptr_t)&BoundarySystemCallbackShrink_Invoke_m69E0E70D187835048D58FDE12323505C86C604F5_ClosedStaticInvoker;
		else
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&BoundarySystemCallbackShrink_Invoke_m69E0E70D187835048D58FDE12323505C86C604F5_OpenStatic;
			else
				{
					__this->___invoke_impl_1 = __this->___method_ptr_0;
					__this->___method_code_6 = (intptr_t)__this->___m_target_2;
				}
	}
	else
	{
		bool isOpen = parameterCount == 2;
		if (isOpen)
		{
			if (__this->___method_is_virtual_12)
			{
				if (il2cpp_codegen_method_is_generic_instance_method((RuntimeMethod*)___1_method))
					if (il2cpp_codegen_method_is_interface_method((RuntimeMethod*)___1_method))
						__this->___invoke_impl_1 = (intptr_t)&BoundarySystemCallbackShrink_Invoke_m69E0E70D187835048D58FDE12323505C86C604F5_OpenGenericInterface;
					else
						__this->___invoke_impl_1 = (intptr_t)&BoundarySystemCallbackShrink_Invoke_m69E0E70D187835048D58FDE12323505C86C604F5_OpenGenericVirtual;
				else
					if (il2cpp_codegen_method_is_interface_method((RuntimeMethod*)___1_method))
						__this->___invoke_impl_1 = (intptr_t)&BoundarySystemCallbackShrink_Invoke_m69E0E70D187835048D58FDE12323505C86C604F5_OpenInterface;
					else
						__this->___invoke_impl_1 = (intptr_t)&BoundarySystemCallbackShrink_Invoke_m69E0E70D187835048D58FDE12323505C86C604F5_OpenVirtual;
			}
			else
			{
				__this->___invoke_impl_1 = (intptr_t)&BoundarySystemCallbackShrink_Invoke_m69E0E70D187835048D58FDE12323505C86C604F5_OpenInst;
			}
		}
		else
		{
			if (___0_object == NULL)
				il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
			__this->___invoke_impl_1 = __this->___method_ptr_0;
			__this->___method_code_6 = (intptr_t)__this->___m_target_2;
		}
	}
	__this->___extra_arg_5 = (intptr_t)&BoundarySystemCallbackShrink_Invoke_m69E0E70D187835048D58FDE12323505C86C604F5_Multicast;
}
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundarySystemCallbackShrink::Invoke(System.Collections.Generic.List`1<UnityEngine.Vector3>,System.Collections.Generic.List`1<UnityEngine.Vector3>,System.Collections.Generic.List`1<System.Collections.Generic.List`1<UnityEngine.Vector3>>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundarySystemCallbackShrink_Invoke_m69E0E70D187835048D58FDE12323505C86C604F5 (BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75* __this, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___0_rectPoints, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___1_boundaryPoints, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* ___2_unusedLines, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_rectPoints, ___1_boundaryPoints, ___2_unusedLines, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
// System.IAsyncResult BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundarySystemCallbackShrink::BeginInvoke(System.Collections.Generic.List`1<UnityEngine.Vector3>,System.Collections.Generic.List`1<UnityEngine.Vector3>,System.Collections.Generic.List`1<System.Collections.Generic.List`1<UnityEngine.Vector3>>,System.AsyncCallback,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* BoundarySystemCallbackShrink_BeginInvoke_m156B982BE0205A44AC3B440DE0E00A3B00C915FD (BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75* __this, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___0_rectPoints, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___1_boundaryPoints, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* ___2_unusedLines, AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___3_callback, RuntimeObject* ___4_object, const RuntimeMethod* method) 
{
	void *__d_args[4] = {0};
	__d_args[0] = ___0_rectPoints;
	__d_args[1] = ___1_boundaryPoints;
	__d_args[2] = ___2_unusedLines;
	return (RuntimeObject*)il2cpp_codegen_delegate_begin_invoke((RuntimeDelegate*)__this, __d_args, (RuntimeDelegate*)___3_callback, (RuntimeObject*)___4_object);
}
// System.Void BoundarySystem_Ext.Pvr_SafeAreaAlgoModule/BoundarySystemCallbackShrink::EndInvoke(System.IAsyncResult)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoundarySystemCallbackShrink_EndInvoke_mD37F8D3FA0C009F0FE2FB77BDF395EF962F8E22A (BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75* __this, RuntimeObject* ___0_result, const RuntimeMethod* method) 
{
	il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___0_result, 0);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_Invoke_m7126A54DACA72B845424072887B5F3A51FC3808E_inline (Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* __this, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Delegate_get_Target_m6E203F111C1548193A5AB7E616BD5834CD269753_inline (Delegate_t* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___m_target_2;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_op_UnaryNegation_m5450829F333BD2A88AF9A592C4EE331661225915_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_a, const RuntimeMethod* method) 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ___0_a;
		float L_1 = L_0.___x_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_2 = ___0_a;
		float L_3 = L_2.___y_3;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4 = ___0_a;
		float L_5 = L_4.___z_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_6;
		memset((&L_6), 0, sizeof(L_6));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_6), ((-L_1)), ((-L_3)), ((-L_5)), /*hidden argument*/NULL);
		V_0 = L_6;
		goto IL_001e;
	}

IL_001e:
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_7 = V_0;
		return L_7;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____stringLength_4;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void CallBackDelegate_Invoke_m42D4CEED99DFAE02791F0098A5657031B3A3BADE_inline (CallBackDelegate_t81C491346A63F826EE8020F93F85282833DB48AC* __this, TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6 ___0_info, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, TextureInfo_tAF6920455ADD42354FE3331CE73CEC5EDE875DF6, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_info, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* __this, float ___0_x, float ___1_y, float ___2_z, const RuntimeMethod* method) 
{
	{
		float L_0 = ___0_x;
		__this->___x_2 = L_0;
		float L_1 = ___1_y;
		__this->___y_3 = L_1;
		float L_2 = ___2_z;
		__this->___z_4 = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void BoundarySystemCallback_Invoke_m33091366DF51DF2DA3EA52496D5D30C2E56D5DAD_inline (BoundarySystemCallback_tA85133ECF82EF8A2C5D561B0AA2D16F3DD6A40AD* __this, BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B ___0_playAreaInfo, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___1_boundaryPoints, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* ___2_unusedLines, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, BoundaryPlayerArea_tEEC3092545E8E254B55AADC98995C1B2A53D459B, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_playAreaInfo, ___1_boundaryPoints, ___2_unusedLines, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void BoundarySystemCallbackShrink_Invoke_m69E0E70D187835048D58FDE12323505C86C604F5_inline (BoundarySystemCallbackShrink_t74086250BA9122B0561C0AC52ACC526790B5EE75* __this, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___0_rectPoints, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* ___1_boundaryPoints, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F* ___2_unusedLines, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, List_1_tE5E2F520A1D08DC8DA6B8BF059CF6AE99CA46D0F*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_rectPoints, ___1_boundaryPoints, ___2_unusedLines, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR KeyValuePair_2_tDC26B09C26BA829DDE331BCB6AF7C508C763D7A3 Enumerator_get_Current_m90160D324DA0D9F5624A345F47D8E226A118911A_gshared_inline (Enumerator_tE92C1AC40A104A179B94F8A013728FD9314CFBD3* __this, const RuntimeMethod* method) 
{
	{
		KeyValuePair_2_tDC26B09C26BA829DDE331BCB6AF7C508C763D7A3 L_0 = __this->____current_3;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* KeyValuePair_2_get_Value_m8508BCECB0654E2E93B1A141382E2688ADE7EE7C_gshared_inline (KeyValuePair_2_tDC26B09C26BA829DDE331BCB6AF7C508C763D7A3* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___value_1;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version_3;
		__this->____version_3 = ((int32_t)il2cpp_codegen_add(L_0, 1));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1 = __this->____items_1;
		V_0 = L_1;
		int32_t L_2 = __this->____size_2;
		V_1 = L_2;
		int32_t L_3 = V_1;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_4 = V_0;
		NullCheck(L_4);
		if ((!(((uint32_t)L_3) < ((uint32_t)((int32_t)(((RuntimeArray*)L_4)->max_length))))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_5 = V_1;
		__this->____size_2 = ((int32_t)il2cpp_codegen_add(L_5, 1));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_6 = V_0;
		int32_t L_7 = V_1;
		RuntimeObject* L_8 = ___0_item;
		NullCheck(L_6);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(L_7), (RuntimeObject*)L_8);
		return;
	}

IL_0034:
	{
		RuntimeObject* L_9 = ___0_item;
		((  void (*) (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 11)))(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m0248A96C5334E9A93E6994B7780478BCD994EA3D_gshared_inline (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, int32_t ___0_item, const RuntimeMethod* method) 
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version_3;
		__this->____version_3 = ((int32_t)il2cpp_codegen_add(L_0, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____items_1;
		V_0 = L_1;
		int32_t L_2 = __this->____size_2;
		V_1 = L_2;
		int32_t L_3 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = V_0;
		NullCheck(L_4);
		if ((!(((uint32_t)L_3) < ((uint32_t)((int32_t)(((RuntimeArray*)L_4)->max_length))))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_5 = V_1;
		__this->____size_2 = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_6 = V_0;
		int32_t L_7 = V_1;
		int32_t L_8 = ___0_item;
		NullCheck(L_6);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(L_7), (int32_t)L_8);
		return;
	}

IL_0034:
	{
		int32_t L_9 = ___0_item;
		((  void (*) (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 11)))(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size_2;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_mF590592E32D421DE2C6E2F0D5C2F62FB14CCEFDF_gshared_inline (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size_2;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Queue_1_get_Count_m166D9E7A5DA18ACC5799C3963DD64F400A9F21BC_gshared_inline (Queue_1_t73397D17133F6DB7BE30373D9138C3C6F4722AD9* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size_3;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m79E50C4F592B1703F4B76A8BE7B4855515460CA1_gshared_inline (List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_item, const RuntimeMethod* method) 
{
	Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version_3;
		__this->____version_3 = ((int32_t)il2cpp_codegen_add(L_0, 1));
		Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* L_1 = __this->____items_1;
		V_0 = L_1;
		int32_t L_2 = __this->____size_2;
		V_1 = L_2;
		int32_t L_3 = V_1;
		Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* L_4 = V_0;
		NullCheck(L_4);
		if ((!(((uint32_t)L_3) < ((uint32_t)((int32_t)(((RuntimeArray*)L_4)->max_length))))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_5 = V_1;
		__this->____size_2 = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* L_6 = V_0;
		int32_t L_7 = V_1;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_8 = ___0_item;
		NullCheck(L_6);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(L_7), (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2)L_8);
		return;
	}

IL_0034:
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_9 = ___0_item;
		((  void (*) (List_1_t77B94703E05C519A9010DD0614F757F974E1CD8B*, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2, const RuntimeMethod*))il2cpp_codegen_get_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 11)))(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
		return;
	}
}
