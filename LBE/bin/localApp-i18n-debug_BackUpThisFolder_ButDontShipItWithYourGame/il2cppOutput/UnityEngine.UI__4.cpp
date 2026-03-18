#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>


template <typename T1>
struct VirtualActionInvoker1
{
	typedef void (*Action)(void*, T1, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj, p1, invokeData.method);
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
template <typename R, typename T1>
struct VirtualFuncInvoker1
{
	typedef R (*Func)(void*, T1, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};

// System.Comparison`1<UnityEngine.EventSystems.RaycastResult>
struct Comparison_1_t9FCAC8C8CE160A96C5AAD2DE1D353DCE8A2FEEFC;
// System.Collections.Generic.Dictionary`2<System.Int32,System.Object>
struct Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907;
// System.Collections.Generic.Dictionary`2<System.Int32,UnityEngine.EventSystems.PointerEventData>
struct Dictionary_2_t489B023479196B8FC9709A9F834FC38729BD9493;
// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IDropHandler>
struct EventFunction_1_tB3864D36512C3A896DAC44E898E5D9E1A92CB733;
// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IEndDragHandler>
struct EventFunction_1_t33BA7CA3F9202146F70BE77589CE24F7451C584C;
// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IInitializePotentialDragHandler>
struct EventFunction_1_t7DFDB0A0C9926E06BF7870695CD48A0533DFABAD;
// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IPointerClickHandler>
struct EventFunction_1_t586168BFEFD0CF29A2B706B5411BF712BD73359E;
// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IPointerDownHandler>
struct EventFunction_1_t00024D26E9CCD074EEBC25568B0383863A4CF117;
// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IPointerExitHandler>
struct EventFunction_1_tA70AAFA2BD47CD0A094BCB586E2EA3E04C5F8916;
// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IPointerUpHandler>
struct EventFunction_1_t919A3841A202FB8C678BC0172FAB7E2F79B88AD8;
// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<System.Object>
struct EventFunction_1_t297B5C47242D1B98BEC955E2804FA142B43E7927;
// System.Collections.Generic.IComparer`1<UnityEngine.RaycastHit>
struct IComparer_1_t4029032A6ED22A873F128CBE44DE2F52D471C18F;
// System.Collections.Generic.IEqualityComparer`1<System.Int32>
struct IEqualityComparer_1_tDBFC8496F14612776AF930DBF84AFE7D06D1F0E9;
// System.Collections.Generic.Dictionary`2/KeyCollection<System.Int32,UnityEngine.EventSystems.PointerEventData>
struct KeyCollection_t358D9D86EA73609D5A330DEAD2AFC492CC3882BA;
// System.Collections.Generic.List`1<UnityEngine.EventSystems.BaseInputModule>
struct List_1_tA5BDE435C735A082941CD33D212F97F4AE9FA55F;
// System.Collections.Generic.List`1<UnityEngine.EventSystems.BaseRaycaster>
struct List_1_t02E640552264E3DEAE676267B620815D33BCD0DF;
// System.Collections.Generic.List`1<UnityEngine.EventSystems.EventSystem>
struct List_1_tF2FE88545EFEC788CAAE6C74EC2F78E937FCCAC3;
// System.Collections.Generic.List`1<UnityEngine.GameObject>
struct List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B;
// System.Collections.Generic.List`1<System.Object>
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D;
// System.Collections.Generic.List`1<UnityEngine.EventSystems.RaycastResult>
struct List_1_t8292C421BBB00D7661DC07462822936152BAB446;
// System.Collections.Generic.List`1<UnityEngine.EventSystems.PointerInputModule/ButtonState>
struct List_1_t6D515F3BEDA0E1BF16E735CE960F740AB8ACBDD3;
// UnityEngine.Events.UnityEvent`1<UnityEngine.SpriteRenderer>
struct UnityEvent_1_t8ABE5544759145B8D7A09F1C54FFCB6907EDD56E;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.Int32,UnityEngine.EventSystems.PointerEventData>
struct ValueCollection_tE4A676F89CE73FFF8A0046F16CEAF380F9A9CA41;
// System.Collections.Generic.Dictionary`2/Entry<System.Int32,UnityEngine.EventSystems.PointerEventData>[]
struct EntryU5BU5D_t9F389575B9AE1F230AC15DBCA6E6007A112E6440;
// UnityEngine.EventSystems.BaseRaycaster[]
struct BaseRaycasterU5BU5D_tAE62D3FF1A5FF9DE20B2756DA4F4F8981925A799;
// System.Char[]
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
// System.Delegate[]
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
// System.Int32[]
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
// System.Object[]
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
// UnityEngine.RaycastHit[]
struct RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8;
// UnityEngine.RaycastHit2D[]
struct RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7;
// UnityEngine.EventSystems.RaycastResult[]
struct RaycastResultU5BU5D_tEAF6B3C3088179304676571328CBB001D8CECBC7;
// System.String[]
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
// System.AsyncCallback
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C;
// UnityEngine.EventSystems.AxisEventData
struct AxisEventData_t4AA742BC101B1AA300B16EE7F19E31B91F37A938;
// UnityEngine.EventSystems.BaseEventData
struct BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F;
// UnityEngine.EventSystems.BaseInput
struct BaseInput_t69C46B0AA3C24F1CA842A0D03CACACC4EC788622;
// UnityEngine.EventSystems.BaseInputModule
struct BaseInputModule_tF3B7C22AF1419B2AC9ECE6589357DC1B88ED96B1;
// UnityEngine.EventSystems.BaseRaycaster
struct BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832;
// UnityEngine.Behaviour
struct Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA;
// UnityEngine.Camera
struct Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184;
// UnityEngine.Collider
struct Collider_t1CC3163924FCD6C4CC2E816373A929C1E3D55E76;
// UnityEngine.Collider2D
struct Collider2D_t6A17BA7734600EF3F26588E9ED903617D5B8EB52;
// UnityEngine.Component
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3;
// System.DelegateData
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
// UnityEngine.EventSystems.EventSystem
struct EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707;
// UnityEngine.GameObject
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F;
// System.IAsyncResult
struct IAsyncResult_t7B9B5A0ECB35DCEC31B8A8122C37D687369253B5;
// UnityEngine.EventSystems.IDropHandler
struct IDropHandler_t9F3B358BA4812886852E9AB85A653ABF73B9AA35;
// UnityEngine.EventSystems.IEndDragHandler
struct IEndDragHandler_t9A93E4A27E7CEED446E5FE3DACF39B1A552C23A9;
// UnityEngine.EventSystems.IInitializePotentialDragHandler
struct IInitializePotentialDragHandler_tAFCBB3BBC98C928ED8D5703C39F4781446AB8E9E;
// UnityEngine.EventSystems.IPointerClickHandler
struct IPointerClickHandler_t77341AA19DE37C26F5F619DE8BD28B70D5A2B5D8;
// UnityEngine.EventSystems.IPointerDownHandler
struct IPointerDownHandler_t42CC83619BB6295404D44090142F7726003CE573;
// UnityEngine.EventSystems.IPointerExitHandler
struct IPointerExitHandler_t1AA3FC124CC77401AF27435A3D6E611F5C7A57EE;
// UnityEngine.EventSystems.IPointerUpHandler
struct IPointerUpHandler_tB2D4D0ABEAFF77BE8D0159D638D85E1AF7BAF210;
// System.Reflection.MethodInfo
struct MethodInfo_t;
// UnityEngine.MonoBehaviour
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71;
// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C;
// UnityEngine.EventSystems.Physics2DRaycaster
struct Physics2DRaycaster_t8E0FE5BD8DC96C60EE4BA334B0607B63A69761A7;
// UnityEngine.EventSystems.PhysicsRaycaster
struct PhysicsRaycaster_t0ACA9046D8D0B195B59DB1F7CA4DD6BB634A56DD;
// UnityEngine.EventSystems.PointerEventData
struct PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB;
// UnityEngine.EventSystems.PointerInputModule
struct PointerInputModule_tD71E11FA989C22D83883E120EAA4F05929907556;
// UnityEngine.UI.ReflectionMethodsCache
struct ReflectionMethodsCache_t711B47CE11EA2092B94127FF8D3361AE2E4859F5;
// UnityEngine.Renderer
struct Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF;
// UnityEngine.Rendering.SortingGroup
struct SortingGroup_tA8DA95BF22F76688DAF54122EB3EEA35C70E9759;
// System.String
struct String_t;
// System.Text.StringBuilder
struct StringBuilder_t;
// UnityEngine.EventSystems.TouchInputModule
struct TouchInputModule_t154B7CF685F02D5B9529572B1A96EBD75AAA945C;
// UnityEngine.Transform
struct Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1;
// UnityEngine.EventSystems.UIBehaviour
struct UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D;
// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
// UnityEngine.Camera/CameraCallback
struct CameraCallback_t844E527BFE37BC0495E7F67993E43C07642DA9DD;
// UnityEngine.EventSystems.PhysicsRaycaster/RaycastHitComparer
struct RaycastHitComparer_t8EF6567C19BE9FB575E01A10941FBF7DE3D3DDF1;
// UnityEngine.EventSystems.PointerInputModule/ButtonState
struct ButtonState_tB671FC9C48F167DBC1CDAFEB53C373D8567AE503;
// UnityEngine.EventSystems.PointerInputModule/MouseButtonEventData
struct MouseButtonEventData_t0761D63D3A2B13090597C22DD97597CC7FE4D154;
// UnityEngine.EventSystems.PointerInputModule/MouseState
struct MouseState_tCCE70861DE1EEECF949AFE8E2A922541D4E08A09;
// UnityEngine.UI.ReflectionMethodsCache/GetRayIntersectionAllCallback
struct GetRayIntersectionAllCallback_t52E7AE4ECEA3F9744FF7F8448F852C872A70315C;
// UnityEngine.UI.ReflectionMethodsCache/GetRayIntersectionAllNonAllocCallback
struct GetRayIntersectionAllNonAllocCallback_t28D7ACEBBE525DE0CBEA67986E4C3891D694F980;
// UnityEngine.UI.ReflectionMethodsCache/GetRaycastNonAllocCallback
struct GetRaycastNonAllocCallback_tC3DA6EE6063FE663DD0A9FC52439D825DE4A1FFC;
// UnityEngine.UI.ReflectionMethodsCache/Raycast2DCallback
struct Raycast2DCallback_tC7E4C51859884370CFA01C0DD124F214F46E08E0;
// UnityEngine.UI.ReflectionMethodsCache/Raycast3DCallback
struct Raycast3DCallback_t6D90FA1FB092312B3B52812191581F209A9C2B4A;
// UnityEngine.UI.ReflectionMethodsCache/RaycastAllCallback
struct RaycastAllCallback_t4AFFDCDAA6F02DD74E1E2DE455BA011D82BED47A;

IL2CPP_EXTERN_C RuntimeClass* ExecuteEvents_t74DCF8B83743EE2773ACF182344612A048E2CC59_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_t02E640552264E3DEAE676267B620815D33BCD0DF_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RaycastHitComparer_t8EF6567C19BE9FB575E01A10941FBF7DE3D3DDF1_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SpriteRenderer_t1DD7FE258F072E1FA87D6577BA27225892B8047B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SpriteShapeRenderer_tE998BB73CF661079736CCC23617E597AB230A4AC_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringBuilder_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* TilemapRenderer_t1A45FD335E86172CFBB77D657E1D6705A477A6CB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeField* RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023____m_GameObject_0_FieldInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral0F310FF3EBC19D65A536D81F5D8C7093E972DCA0;
IL2CPP_EXTERN_C String_t* _stringLiteral12BA26D2F44E032136B3146CB230F4F45C5D45DE;
IL2CPP_EXTERN_C String_t* _stringLiteral267CC871678BDBD934CBEA872CCB8F0C72D94E44;
IL2CPP_EXTERN_C String_t* _stringLiteral2A98949D28301C3B04EAD557512780C8D89A9607;
IL2CPP_EXTERN_C String_t* _stringLiteral2B2D9FCF87BC5B281C797365D6EE6332266A0B63;
IL2CPP_EXTERN_C String_t* _stringLiteral2E8BE7BC315CC297C7A3C2864B3A2ED1BD553384;
IL2CPP_EXTERN_C String_t* _stringLiteral30A589687C1FFF9D1706D115A0C664F2A49D9CEF;
IL2CPP_EXTERN_C String_t* _stringLiteral4B1F6E5C644F13999A134C243088737884A6B5D2;
IL2CPP_EXTERN_C String_t* _stringLiteral55489C2AE4CD8276F5514C1F5C0FC0E6C828316F;
IL2CPP_EXTERN_C String_t* _stringLiteral62105F6FE34556E3D1EE1FB639ABDA34F249420F;
IL2CPP_EXTERN_C String_t* _stringLiteral70F1769C72FCAF144F53009F7DA60ED467C29635;
IL2CPP_EXTERN_C String_t* _stringLiteral75B536F4B16F980DC1BE8BFB67378A32681C6F79;
IL2CPP_EXTERN_C String_t* _stringLiteral94A94F7BD0F52C17BB06F5A6BB4E316DC4B69DF8;
IL2CPP_EXTERN_C String_t* _stringLiteral9778C320E07EB86C3995D33DDB63310A2DC91762;
IL2CPP_EXTERN_C String_t* _stringLiteral9D2B27E9061DE91A9190184698F3F04E23827CA1;
IL2CPP_EXTERN_C String_t* _stringLiteralC10E23F5AEEE6BB98CA98C5F6720ED7A4B1DE089;
IL2CPP_EXTERN_C String_t* _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709;
IL2CPP_EXTERN_C String_t* _stringLiteralED69593F1852661D74AD04003C30B937EE7310BF;
IL2CPP_EXTERN_C const RuntimeMethod* Array_Sort_TisRaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5_mBF83A49E9B1F007DD08F7E076AF45D2AED7A45EB_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Component_GetComponent_TisCamera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184_m64AC6C06DD93C5FB249091FEC84FA8475457CCC4_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Component_GetComponentsInParent_TisBaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832_mA869CA05E07609C8F435F1D779B138F3F2425F8C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_GetEnumerator_m5127D66D8AB03E7A21778DD898242C65F0EED034_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_Dispose_m939CB6214446517A933B0216F1C64AB86E291714_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_MoveNext_m69F94D82492DD2778B91F594B491223C02265150_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_get_Current_mEC2B6AFDB80F9344C20DF0D6A63925642A413615_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ExecuteEvents_ExecuteHierarchy_TisIDropHandler_t9F3B358BA4812886852E9AB85A653ABF73B9AA35_m0C0E2A729F88D6AB5AC2B4FD9C4E33D181A52A57_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ExecuteEvents_ExecuteHierarchy_TisIPointerDownHandler_t42CC83619BB6295404D44090142F7726003CE573_mF031AC46543C02039764EDB1B0673DFA36B1F58C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ExecuteEvents_ExecuteHierarchy_TisIPointerExitHandler_t1AA3FC124CC77401AF27435A3D6E611F5C7A57EE_m50CEB3F041077A74C37270714BBF0CC3EB37DD92_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ExecuteEvents_Execute_TisIEndDragHandler_t9A93E4A27E7CEED446E5FE3DACF39B1A552C23A9_m6AA443D4F53AF0FEBAC269F761A158635243467E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ExecuteEvents_Execute_TisIInitializePotentialDragHandler_tAFCBB3BBC98C928ED8D5703C39F4781446AB8E9E_mABD9E1ECC8C04235760B3855DF03F2308F62071C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ExecuteEvents_Execute_TisIPointerClickHandler_t77341AA19DE37C26F5F619DE8BD28B70D5A2B5D8_m024FB23AA1DBB1B7A5E1935FA35A1E4FF57AC5F6_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ExecuteEvents_Execute_TisIPointerUpHandler_tB2D4D0ABEAFF77BE8D0159D638D85E1AF7BAF210_mBB70745D5D17BF6402CABEFF0F52911F88C197A6_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ExecuteEvents_GetEventHandler_TisIDragHandler_t9FF2B3D79AB401D7E2485254973D15C0F117D00D_m9AA4E18082F53C60962F70D75570F1D400C37FBA_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ExecuteEvents_GetEventHandler_TisIPointerClickHandler_t77341AA19DE37C26F5F619DE8BD28B70D5A2B5D8_m3363BED905E60A4545A8CA5B8C68BA709E99536E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* GameObject_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_m026EB44DB6238F13E2AFBECF1FBBE924CB1B040A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* KeyValuePair_2_ToString_m5F8161F26E20B830F794E3C0B87C0570D011D4AD_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m82AF5EAB1EA13F21CE5250B008E4EBCFEDAB6D53_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_mEB6DFEA132B5B7BF540D34177054003185D250E7_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Contains_m1F747311B8D41F5857768B1D6D5C51C43CA8BE4C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Remove_m585A9E471D1C60EE46BA224A58947647F1E2B83B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_m53B48CB7A08406A33847E0C3D9D7511DE8FB0D41_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_get_Count_mE2EBEDC861C1EC398EDBE6CF2C9FB604AA71523E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeType* RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_0_0_0_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;

struct BaseRaycasterU5BU5D_tAE62D3FF1A5FF9DE20B2756DA4F4F8981925A799;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8;
struct RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7;
struct RaycastResultU5BU5D_tEAF6B3C3088179304676571328CBB001D8CECBC7;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Collections.Generic.Dictionary`2<System.Int32,UnityEngine.EventSystems.PointerEventData>
struct Dictionary_2_t489B023479196B8FC9709A9F834FC38729BD9493  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_t9F389575B9AE1F230AC15DBCA6E6007A112E6440* ____entries_1;
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
	KeyCollection_t358D9D86EA73609D5A330DEAD2AFC492CC3882BA* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_tE4A676F89CE73FFF8A0046F16CEAF380F9A9CA41* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.Collections.Generic.List`1<UnityEngine.EventSystems.BaseRaycaster>
struct List_1_t02E640552264E3DEAE676267B620815D33BCD0DF  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	BaseRaycasterU5BU5D_tAE62D3FF1A5FF9DE20B2756DA4F4F8981925A799* ____items_1;
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

// System.Collections.Generic.List`1<UnityEngine.EventSystems.RaycastResult>
struct List_1_t8292C421BBB00D7661DC07462822936152BAB446  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	RaycastResultU5BU5D_tEAF6B3C3088179304676571328CBB001D8CECBC7* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// <PrivateImplementationDetails>
struct U3CPrivateImplementationDetailsU3E_t3A51899FBAA581553000230A6A0F92898553245F  : public RuntimeObject
{
};

// UnityEngine.EventSystems.AbstractEventData
struct AbstractEventData_tAE1A127ED657117548181D29FFE4B1B14D8E67F7  : public RuntimeObject
{
	// System.Boolean UnityEngine.EventSystems.AbstractEventData::m_Used
	bool ___m_Used_0;
};

// UnityEngine.EventSystems.RaycasterManager
struct RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074  : public RuntimeObject
{
};

// UnityEngine.UI.ReflectionMethodsCache
struct ReflectionMethodsCache_t711B47CE11EA2092B94127FF8D3361AE2E4859F5  : public RuntimeObject
{
	// UnityEngine.UI.ReflectionMethodsCache/Raycast3DCallback UnityEngine.UI.ReflectionMethodsCache::raycast3D
	Raycast3DCallback_t6D90FA1FB092312B3B52812191581F209A9C2B4A* ___raycast3D_0;
	// UnityEngine.UI.ReflectionMethodsCache/RaycastAllCallback UnityEngine.UI.ReflectionMethodsCache::raycast3DAll
	RaycastAllCallback_t4AFFDCDAA6F02DD74E1E2DE455BA011D82BED47A* ___raycast3DAll_1;
	// UnityEngine.UI.ReflectionMethodsCache/GetRaycastNonAllocCallback UnityEngine.UI.ReflectionMethodsCache::getRaycastNonAlloc
	GetRaycastNonAllocCallback_tC3DA6EE6063FE663DD0A9FC52439D825DE4A1FFC* ___getRaycastNonAlloc_2;
	// UnityEngine.UI.ReflectionMethodsCache/Raycast2DCallback UnityEngine.UI.ReflectionMethodsCache::raycast2D
	Raycast2DCallback_tC7E4C51859884370CFA01C0DD124F214F46E08E0* ___raycast2D_3;
	// UnityEngine.UI.ReflectionMethodsCache/GetRayIntersectionAllCallback UnityEngine.UI.ReflectionMethodsCache::getRayIntersectionAll
	GetRayIntersectionAllCallback_t52E7AE4ECEA3F9744FF7F8448F852C872A70315C* ___getRayIntersectionAll_4;
	// UnityEngine.UI.ReflectionMethodsCache/GetRayIntersectionAllNonAllocCallback UnityEngine.UI.ReflectionMethodsCache::getRayIntersectionAllNonAlloc
	GetRayIntersectionAllNonAllocCallback_t28D7ACEBBE525DE0CBEA67986E4C3891D694F980* ___getRayIntersectionAllNonAlloc_5;
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

// UnityEngine.EventSystems.PhysicsRaycaster/RaycastHitComparer
struct RaycastHitComparer_t8EF6567C19BE9FB575E01A10941FBF7DE3D3DDF1  : public RuntimeObject
{
};

// UnityEngine.EventSystems.PointerInputModule/MouseState
struct MouseState_tCCE70861DE1EEECF949AFE8E2A922541D4E08A09  : public RuntimeObject
{
	// System.Collections.Generic.List`1<UnityEngine.EventSystems.PointerInputModule/ButtonState> UnityEngine.EventSystems.PointerInputModule/MouseState::m_TrackedButtons
	List_1_t6D515F3BEDA0E1BF16E735CE960F740AB8ACBDD3* ___m_TrackedButtons_0;
};

// System.Collections.Generic.KeyValuePair`2<System.Int32,System.Object>
struct KeyValuePair_2_tDC26B09C26BA829DDE331BCB6AF7C508C763D7A3 
{
	// TKey System.Collections.Generic.KeyValuePair`2::key
	int32_t ___key_0;
	// TValue System.Collections.Generic.KeyValuePair`2::value
	RuntimeObject* ___value_1;
};

// System.Collections.Generic.KeyValuePair`2<System.Int32,UnityEngine.EventSystems.PointerEventData>
struct KeyValuePair_2_tC51A92A69CB9B2F98A91443EE066E405EDCA4296 
{
	// TKey System.Collections.Generic.KeyValuePair`2::key
	int32_t ___key_0;
	// TValue System.Collections.Generic.KeyValuePair`2::value
	PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* ___value_1;
};

// UnityEngine.EventSystems.BaseEventData
struct BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F  : public AbstractEventData_tAE1A127ED657117548181D29FFE4B1B14D8E67F7
{
	// UnityEngine.EventSystems.EventSystem UnityEngine.EventSystems.BaseEventData::m_EventSystem
	EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707* ___m_EventSystem_1;
};

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	// System.Boolean System.Boolean::m_value
	bool ___m_value_0;
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

// System.IntPtr
struct IntPtr_t 
{
	// System.Void* System.IntPtr::m_value
	void* ___m_value_0;
};

// UnityEngine.LayerMask
struct LayerMask_t97CB6BDADEDC3D6423C7BCFEA7F86DA2EC6241DB 
{
	// System.Int32 UnityEngine.LayerMask::m_Mask
	int32_t ___m_Mask_0;
};

// UnityEngine.Mathf
struct Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682 
{
	union
	{
		struct
		{
		};
		uint8_t Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682__padding[1];
	};
};

// UnityEngine.Rect
struct Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D 
{
	// System.Single UnityEngine.Rect::m_XMin
	float ___m_XMin_0;
	// System.Single UnityEngine.Rect::m_YMin
	float ___m_YMin_1;
	// System.Single UnityEngine.Rect::m_Width
	float ___m_Width_2;
	// System.Single UnityEngine.Rect::m_Height
	float ___m_Height_3;
};

// System.Single
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	// System.Single System.Single::m_value
	float ___m_value_0;
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

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=12
struct __StaticArrayInitTypeSizeU3D12_tE6E9A5118C80D71EA1E9325D404FAB06593F00C3 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D12_tE6E9A5118C80D71EA1E9325D404FAB06593F00C3__padding[12];
	};
};

// UnityEngine.EventSystems.EventSystem/UIToolkitOverrideConfig
struct UIToolkitOverrideConfig_t4E6B4528E38BCA7DA72C45424634806200A50182 
{
	// UnityEngine.EventSystems.EventSystem UnityEngine.EventSystems.EventSystem/UIToolkitOverrideConfig::activeEventSystem
	EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707* ___activeEventSystem_0;
	// System.Boolean UnityEngine.EventSystems.EventSystem/UIToolkitOverrideConfig::sendEvents
	bool ___sendEvents_1;
	// System.Boolean UnityEngine.EventSystems.EventSystem/UIToolkitOverrideConfig::createPanelGameObjectsOnStart
	bool ___createPanelGameObjectsOnStart_2;
};
// Native definition for P/Invoke marshalling of UnityEngine.EventSystems.EventSystem/UIToolkitOverrideConfig
struct UIToolkitOverrideConfig_t4E6B4528E38BCA7DA72C45424634806200A50182_marshaled_pinvoke
{
	EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707* ___activeEventSystem_0;
	int32_t ___sendEvents_1;
	int32_t ___createPanelGameObjectsOnStart_2;
};
// Native definition for COM marshalling of UnityEngine.EventSystems.EventSystem/UIToolkitOverrideConfig
struct UIToolkitOverrideConfig_t4E6B4528E38BCA7DA72C45424634806200A50182_marshaled_com
{
	EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707* ___activeEventSystem_0;
	int32_t ___sendEvents_1;
	int32_t ___createPanelGameObjectsOnStart_2;
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

// System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,UnityEngine.EventSystems.PointerEventData>
struct Enumerator_tAC6F215019B1EAEAEE81308CEBA6052DECD5EE7E 
{
	// System.Collections.Generic.Dictionary`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator::_dictionary
	Dictionary_2_t489B023479196B8FC9709A9F834FC38729BD9493* ____dictionary_0;
	// System.Int32 System.Collections.Generic.Dictionary`2/Enumerator::_version
	int32_t ____version_1;
	// System.Int32 System.Collections.Generic.Dictionary`2/Enumerator::_index
	int32_t ____index_2;
	// System.Collections.Generic.KeyValuePair`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator::_current
	KeyValuePair_2_tC51A92A69CB9B2F98A91443EE066E405EDCA4296 ____current_3;
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

// UnityEngine.EventSystems.MoveDirection
struct MoveDirection_t0981B415CB2BEB70F14E647EDE5DE29F52DEC5E6 
{
	// System.Int32 UnityEngine.EventSystems.MoveDirection::value__
	int32_t ___value___2;
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

// UnityEngine.Ray
struct Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 
{
	// UnityEngine.Vector3 UnityEngine.Ray::m_Origin
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_Origin_0;
	// UnityEngine.Vector3 UnityEngine.Ray::m_Direction
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_Direction_1;
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

// UnityEngine.RaycastHit2D
struct RaycastHit2D_t3EAAA06E6603C6BC61AC1291DD881C5C1E23BDFA 
{
	// UnityEngine.Vector2 UnityEngine.RaycastHit2D::m_Centroid
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___m_Centroid_0;
	// UnityEngine.Vector2 UnityEngine.RaycastHit2D::m_Point
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___m_Point_1;
	// UnityEngine.Vector2 UnityEngine.RaycastHit2D::m_Normal
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___m_Normal_2;
	// System.Single UnityEngine.RaycastHit2D::m_Distance
	float ___m_Distance_3;
	// System.Single UnityEngine.RaycastHit2D::m_Fraction
	float ___m_Fraction_4;
	// System.Int32 UnityEngine.RaycastHit2D::m_Collider
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

// UnityEngine.TouchPhase
struct TouchPhase_t54E0A1AF80465997849420A72317B733E1D49A9E 
{
	// System.Int32 UnityEngine.TouchPhase::value__
	int32_t ___value___2;
};

// UnityEngine.TouchType
struct TouchType_t84F82C73BC1A6012141735AD84DA67AA7F7AB43F 
{
	// System.Int32 UnityEngine.TouchType::value__
	int32_t ___value___2;
};

// UnityEngine.EventSystems.PointerEventData/FramePressState
struct FramePressState_t1C7FDAE5827219BC328972DD7E496343581BDF95 
{
	// System.Int32 UnityEngine.EventSystems.PointerEventData/FramePressState::value__
	int32_t ___value___2;
};

// UnityEngine.EventSystems.PointerEventData/InputButton
struct InputButton_t7F40241CC7C406EBD574D426F736CB744DE86CDA 
{
	// System.Int32 UnityEngine.EventSystems.PointerEventData/InputButton::value__
	int32_t ___value___2;
};

// UnityEngine.EventSystems.StandaloneInputModule/InputMode
struct InputMode_tEF03AE26DCD4F01309831EAF155B063E39EAFA9E 
{
	// System.Int32 UnityEngine.EventSystems.StandaloneInputModule/InputMode::value__
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

// UnityEngine.EventSystems.PointerEventData
struct PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB  : public BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F
{
	// UnityEngine.GameObject UnityEngine.EventSystems.PointerEventData::<pointerEnter>k__BackingField
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___U3CpointerEnterU3Ek__BackingField_2;
	// UnityEngine.GameObject UnityEngine.EventSystems.PointerEventData::m_PointerPress
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___m_PointerPress_3;
	// UnityEngine.GameObject UnityEngine.EventSystems.PointerEventData::<lastPress>k__BackingField
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___U3ClastPressU3Ek__BackingField_4;
	// UnityEngine.GameObject UnityEngine.EventSystems.PointerEventData::<rawPointerPress>k__BackingField
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___U3CrawPointerPressU3Ek__BackingField_5;
	// UnityEngine.GameObject UnityEngine.EventSystems.PointerEventData::<pointerDrag>k__BackingField
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___U3CpointerDragU3Ek__BackingField_6;
	// UnityEngine.GameObject UnityEngine.EventSystems.PointerEventData::<pointerClick>k__BackingField
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___U3CpointerClickU3Ek__BackingField_7;
	// UnityEngine.EventSystems.RaycastResult UnityEngine.EventSystems.PointerEventData::<pointerCurrentRaycast>k__BackingField
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 ___U3CpointerCurrentRaycastU3Ek__BackingField_8;
	// UnityEngine.EventSystems.RaycastResult UnityEngine.EventSystems.PointerEventData::<pointerPressRaycast>k__BackingField
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 ___U3CpointerPressRaycastU3Ek__BackingField_9;
	// System.Collections.Generic.List`1<UnityEngine.GameObject> UnityEngine.EventSystems.PointerEventData::hovered
	List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* ___hovered_10;
	// System.Boolean UnityEngine.EventSystems.PointerEventData::<eligibleForClick>k__BackingField
	bool ___U3CeligibleForClickU3Ek__BackingField_11;
	// System.Int32 UnityEngine.EventSystems.PointerEventData::<pointerId>k__BackingField
	int32_t ___U3CpointerIdU3Ek__BackingField_12;
	// UnityEngine.Vector2 UnityEngine.EventSystems.PointerEventData::<position>k__BackingField
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___U3CpositionU3Ek__BackingField_13;
	// UnityEngine.Vector2 UnityEngine.EventSystems.PointerEventData::<delta>k__BackingField
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___U3CdeltaU3Ek__BackingField_14;
	// UnityEngine.Vector2 UnityEngine.EventSystems.PointerEventData::<pressPosition>k__BackingField
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___U3CpressPositionU3Ek__BackingField_15;
	// UnityEngine.Vector3 UnityEngine.EventSystems.PointerEventData::<worldPosition>k__BackingField
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___U3CworldPositionU3Ek__BackingField_16;
	// UnityEngine.Vector3 UnityEngine.EventSystems.PointerEventData::<worldNormal>k__BackingField
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___U3CworldNormalU3Ek__BackingField_17;
	// System.Single UnityEngine.EventSystems.PointerEventData::<clickTime>k__BackingField
	float ___U3CclickTimeU3Ek__BackingField_18;
	// System.Int32 UnityEngine.EventSystems.PointerEventData::<clickCount>k__BackingField
	int32_t ___U3CclickCountU3Ek__BackingField_19;
	// UnityEngine.Vector2 UnityEngine.EventSystems.PointerEventData::<scrollDelta>k__BackingField
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___U3CscrollDeltaU3Ek__BackingField_20;
	// System.Boolean UnityEngine.EventSystems.PointerEventData::<useDragThreshold>k__BackingField
	bool ___U3CuseDragThresholdU3Ek__BackingField_21;
	// System.Boolean UnityEngine.EventSystems.PointerEventData::<dragging>k__BackingField
	bool ___U3CdraggingU3Ek__BackingField_22;
	// UnityEngine.EventSystems.PointerEventData/InputButton UnityEngine.EventSystems.PointerEventData::<button>k__BackingField
	int32_t ___U3CbuttonU3Ek__BackingField_23;
	// System.Single UnityEngine.EventSystems.PointerEventData::<pressure>k__BackingField
	float ___U3CpressureU3Ek__BackingField_24;
	// System.Single UnityEngine.EventSystems.PointerEventData::<tangentialPressure>k__BackingField
	float ___U3CtangentialPressureU3Ek__BackingField_25;
	// System.Single UnityEngine.EventSystems.PointerEventData::<altitudeAngle>k__BackingField
	float ___U3CaltitudeAngleU3Ek__BackingField_26;
	// System.Single UnityEngine.EventSystems.PointerEventData::<azimuthAngle>k__BackingField
	float ___U3CazimuthAngleU3Ek__BackingField_27;
	// System.Single UnityEngine.EventSystems.PointerEventData::<twist>k__BackingField
	float ___U3CtwistU3Ek__BackingField_28;
	// UnityEngine.Vector2 UnityEngine.EventSystems.PointerEventData::<radius>k__BackingField
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___U3CradiusU3Ek__BackingField_29;
	// UnityEngine.Vector2 UnityEngine.EventSystems.PointerEventData::<radiusVariance>k__BackingField
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___U3CradiusVarianceU3Ek__BackingField_30;
	// System.Boolean UnityEngine.EventSystems.PointerEventData::<fullyExited>k__BackingField
	bool ___U3CfullyExitedU3Ek__BackingField_31;
	// System.Boolean UnityEngine.EventSystems.PointerEventData::<reentered>k__BackingField
	bool ___U3CreenteredU3Ek__BackingField_32;
};

// UnityEngine.Touch
struct Touch_t03E51455ED508492B3F278903A0114FA0E87B417 
{
	// System.Int32 UnityEngine.Touch::m_FingerId
	int32_t ___m_FingerId_0;
	// UnityEngine.Vector2 UnityEngine.Touch::m_Position
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___m_Position_1;
	// UnityEngine.Vector2 UnityEngine.Touch::m_RawPosition
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___m_RawPosition_2;
	// UnityEngine.Vector2 UnityEngine.Touch::m_PositionDelta
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___m_PositionDelta_3;
	// System.Single UnityEngine.Touch::m_TimeDelta
	float ___m_TimeDelta_4;
	// System.Int32 UnityEngine.Touch::m_TapCount
	int32_t ___m_TapCount_5;
	// UnityEngine.TouchPhase UnityEngine.Touch::m_Phase
	int32_t ___m_Phase_6;
	// UnityEngine.TouchType UnityEngine.Touch::m_Type
	int32_t ___m_Type_7;
	// System.Single UnityEngine.Touch::m_Pressure
	float ___m_Pressure_8;
	// System.Single UnityEngine.Touch::m_maximumPossiblePressure
	float ___m_maximumPossiblePressure_9;
	// System.Single UnityEngine.Touch::m_Radius
	float ___m_Radius_10;
	// System.Single UnityEngine.Touch::m_RadiusVariance
	float ___m_RadiusVariance_11;
	// System.Single UnityEngine.Touch::m_AltitudeAngle
	float ___m_AltitudeAngle_12;
	// System.Single UnityEngine.Touch::m_AzimuthAngle
	float ___m_AzimuthAngle_13;
};

// UnityEngine.EventSystems.PointerInputModule/ButtonState
struct ButtonState_tB671FC9C48F167DBC1CDAFEB53C373D8567AE503  : public RuntimeObject
{
	// UnityEngine.EventSystems.PointerEventData/InputButton UnityEngine.EventSystems.PointerInputModule/ButtonState::m_Button
	int32_t ___m_Button_0;
	// UnityEngine.EventSystems.PointerInputModule/MouseButtonEventData UnityEngine.EventSystems.PointerInputModule/ButtonState::m_EventData
	MouseButtonEventData_t0761D63D3A2B13090597C22DD97597CC7FE4D154* ___m_EventData_1;
};

// UnityEngine.EventSystems.PointerInputModule/MouseButtonEventData
struct MouseButtonEventData_t0761D63D3A2B13090597C22DD97597CC7FE4D154  : public RuntimeObject
{
	// UnityEngine.EventSystems.PointerEventData/FramePressState UnityEngine.EventSystems.PointerInputModule/MouseButtonEventData::buttonState
	int32_t ___buttonState_0;
	// UnityEngine.EventSystems.PointerEventData UnityEngine.EventSystems.PointerInputModule/MouseButtonEventData::buttonData
	PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* ___buttonData_1;
};

// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IDropHandler>
struct EventFunction_1_tB3864D36512C3A896DAC44E898E5D9E1A92CB733  : public MulticastDelegate_t
{
};

// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IEndDragHandler>
struct EventFunction_1_t33BA7CA3F9202146F70BE77589CE24F7451C584C  : public MulticastDelegate_t
{
};

// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IInitializePotentialDragHandler>
struct EventFunction_1_t7DFDB0A0C9926E06BF7870695CD48A0533DFABAD  : public MulticastDelegate_t
{
};

// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IPointerClickHandler>
struct EventFunction_1_t586168BFEFD0CF29A2B706B5411BF712BD73359E  : public MulticastDelegate_t
{
};

// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IPointerDownHandler>
struct EventFunction_1_t00024D26E9CCD074EEBC25568B0383863A4CF117  : public MulticastDelegate_t
{
};

// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IPointerExitHandler>
struct EventFunction_1_tA70AAFA2BD47CD0A094BCB586E2EA3E04C5F8916  : public MulticastDelegate_t
{
};

// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IPointerUpHandler>
struct EventFunction_1_t919A3841A202FB8C678BC0172FAB7E2F79B88AD8  : public MulticastDelegate_t
{
};

// UnityEngine.Behaviour
struct Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};

// UnityEngine.Collider
struct Collider_t1CC3163924FCD6C4CC2E816373A929C1E3D55E76  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};

// UnityEngine.Renderer
struct Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};

// UnityEngine.Transform
struct Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};

// UnityEngine.UI.ReflectionMethodsCache/GetRayIntersectionAllCallback
struct GetRayIntersectionAllCallback_t52E7AE4ECEA3F9744FF7F8448F852C872A70315C  : public MulticastDelegate_t
{
};

// UnityEngine.UI.ReflectionMethodsCache/GetRayIntersectionAllNonAllocCallback
struct GetRayIntersectionAllNonAllocCallback_t28D7ACEBBE525DE0CBEA67986E4C3891D694F980  : public MulticastDelegate_t
{
};

// UnityEngine.UI.ReflectionMethodsCache/GetRaycastNonAllocCallback
struct GetRaycastNonAllocCallback_tC3DA6EE6063FE663DD0A9FC52439D825DE4A1FFC  : public MulticastDelegate_t
{
};

// UnityEngine.UI.ReflectionMethodsCache/RaycastAllCallback
struct RaycastAllCallback_t4AFFDCDAA6F02DD74E1E2DE455BA011D82BED47A  : public MulticastDelegate_t
{
};

// UnityEngine.Camera
struct Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
};

// UnityEngine.Collider2D
struct Collider2D_t6A17BA7734600EF3F26588E9ED903617D5B8EB52  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
};

// UnityEngine.MonoBehaviour
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
};

// UnityEngine.Rendering.SortingGroup
struct SortingGroup_tA8DA95BF22F76688DAF54122EB3EEA35C70E9759  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
};

// UnityEngine.SpriteRenderer
struct SpriteRenderer_t1DD7FE258F072E1FA87D6577BA27225892B8047B  : public Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF
{
	// UnityEngine.Events.UnityEvent`1<UnityEngine.SpriteRenderer> UnityEngine.SpriteRenderer::m_SpriteChangeEvent
	UnityEvent_1_t8ABE5544759145B8D7A09F1C54FFCB6907EDD56E* ___m_SpriteChangeEvent_4;
};

// UnityEngine.U2D.SpriteShapeRenderer
struct SpriteShapeRenderer_tE998BB73CF661079736CCC23617E597AB230A4AC  : public Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF
{
};

// UnityEngine.Tilemaps.TilemapRenderer
struct TilemapRenderer_t1A45FD335E86172CFBB77D657E1D6705A477A6CB  : public Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF
{
};

// UnityEngine.EventSystems.UIBehaviour
struct UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
};

// UnityEngine.EventSystems.BaseInput
struct BaseInput_t69C46B0AA3C24F1CA842A0D03CACACC4EC788622  : public UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D
{
};

// UnityEngine.EventSystems.BaseInputModule
struct BaseInputModule_tF3B7C22AF1419B2AC9ECE6589357DC1B88ED96B1  : public UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D
{
	// System.Collections.Generic.List`1<UnityEngine.EventSystems.RaycastResult> UnityEngine.EventSystems.BaseInputModule::m_RaycastResultCache
	List_1_t8292C421BBB00D7661DC07462822936152BAB446* ___m_RaycastResultCache_4;
	// System.Boolean UnityEngine.EventSystems.BaseInputModule::m_SendPointerHoverToParent
	bool ___m_SendPointerHoverToParent_5;
	// UnityEngine.EventSystems.AxisEventData UnityEngine.EventSystems.BaseInputModule::m_AxisEventData
	AxisEventData_t4AA742BC101B1AA300B16EE7F19E31B91F37A938* ___m_AxisEventData_6;
	// UnityEngine.EventSystems.EventSystem UnityEngine.EventSystems.BaseInputModule::m_EventSystem
	EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707* ___m_EventSystem_7;
	// UnityEngine.EventSystems.BaseEventData UnityEngine.EventSystems.BaseInputModule::m_BaseEventData
	BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F* ___m_BaseEventData_8;
	// UnityEngine.EventSystems.BaseInput UnityEngine.EventSystems.BaseInputModule::m_InputOverride
	BaseInput_t69C46B0AA3C24F1CA842A0D03CACACC4EC788622* ___m_InputOverride_9;
	// UnityEngine.EventSystems.BaseInput UnityEngine.EventSystems.BaseInputModule::m_DefaultInput
	BaseInput_t69C46B0AA3C24F1CA842A0D03CACACC4EC788622* ___m_DefaultInput_10;
};

// UnityEngine.EventSystems.BaseRaycaster
struct BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832  : public UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D
{
	// UnityEngine.EventSystems.BaseRaycaster UnityEngine.EventSystems.BaseRaycaster::m_RootRaycaster
	BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* ___m_RootRaycaster_4;
};

// UnityEngine.EventSystems.EventSystem
struct EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707  : public UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D
{
	// System.Collections.Generic.List`1<UnityEngine.EventSystems.BaseInputModule> UnityEngine.EventSystems.EventSystem::m_SystemInputModules
	List_1_tA5BDE435C735A082941CD33D212F97F4AE9FA55F* ___m_SystemInputModules_4;
	// UnityEngine.EventSystems.BaseInputModule UnityEngine.EventSystems.EventSystem::m_CurrentInputModule
	BaseInputModule_tF3B7C22AF1419B2AC9ECE6589357DC1B88ED96B1* ___m_CurrentInputModule_5;
	// UnityEngine.GameObject UnityEngine.EventSystems.EventSystem::m_FirstSelected
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___m_FirstSelected_7;
	// System.Boolean UnityEngine.EventSystems.EventSystem::m_sendNavigationEvents
	bool ___m_sendNavigationEvents_8;
	// System.Int32 UnityEngine.EventSystems.EventSystem::m_DragThreshold
	int32_t ___m_DragThreshold_9;
	// UnityEngine.GameObject UnityEngine.EventSystems.EventSystem::m_CurrentSelected
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___m_CurrentSelected_10;
	// System.Boolean UnityEngine.EventSystems.EventSystem::m_HasFocus
	bool ___m_HasFocus_11;
	// System.Boolean UnityEngine.EventSystems.EventSystem::m_SelectionGuard
	bool ___m_SelectionGuard_12;
	// UnityEngine.EventSystems.BaseEventData UnityEngine.EventSystems.EventSystem::m_DummyData
	BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F* ___m_DummyData_13;
};

// UnityEngine.EventSystems.PhysicsRaycaster
struct PhysicsRaycaster_t0ACA9046D8D0B195B59DB1F7CA4DD6BB634A56DD  : public BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832
{
	// UnityEngine.Camera UnityEngine.EventSystems.PhysicsRaycaster::m_EventCamera
	Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* ___m_EventCamera_6;
	// UnityEngine.LayerMask UnityEngine.EventSystems.PhysicsRaycaster::m_EventMask
	LayerMask_t97CB6BDADEDC3D6423C7BCFEA7F86DA2EC6241DB ___m_EventMask_7;
	// System.Int32 UnityEngine.EventSystems.PhysicsRaycaster::m_MaxRayIntersections
	int32_t ___m_MaxRayIntersections_8;
	// System.Int32 UnityEngine.EventSystems.PhysicsRaycaster::m_LastMaxRayIntersections
	int32_t ___m_LastMaxRayIntersections_9;
	// UnityEngine.RaycastHit[] UnityEngine.EventSystems.PhysicsRaycaster::m_Hits
	RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8* ___m_Hits_10;
};

// UnityEngine.EventSystems.PointerInputModule
struct PointerInputModule_tD71E11FA989C22D83883E120EAA4F05929907556  : public BaseInputModule_tF3B7C22AF1419B2AC9ECE6589357DC1B88ED96B1
{
	// System.Collections.Generic.Dictionary`2<System.Int32,UnityEngine.EventSystems.PointerEventData> UnityEngine.EventSystems.PointerInputModule::m_PointerData
	Dictionary_2_t489B023479196B8FC9709A9F834FC38729BD9493* ___m_PointerData_15;
	// UnityEngine.EventSystems.PointerInputModule/MouseState UnityEngine.EventSystems.PointerInputModule::m_MouseState
	MouseState_tCCE70861DE1EEECF949AFE8E2A922541D4E08A09* ___m_MouseState_16;
};

// UnityEngine.EventSystems.Physics2DRaycaster
struct Physics2DRaycaster_t8E0FE5BD8DC96C60EE4BA334B0607B63A69761A7  : public PhysicsRaycaster_t0ACA9046D8D0B195B59DB1F7CA4DD6BB634A56DD
{
	// UnityEngine.RaycastHit2D[] UnityEngine.EventSystems.Physics2DRaycaster::m_Hits
	RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7* ___m_Hits_11;
};

// UnityEngine.EventSystems.TouchInputModule
struct TouchInputModule_t154B7CF685F02D5B9529572B1A96EBD75AAA945C  : public PointerInputModule_tD71E11FA989C22D83883E120EAA4F05929907556
{
	// UnityEngine.Vector2 UnityEngine.EventSystems.TouchInputModule::m_LastMousePosition
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___m_LastMousePosition_17;
	// UnityEngine.Vector2 UnityEngine.EventSystems.TouchInputModule::m_MousePosition
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___m_MousePosition_18;
	// UnityEngine.EventSystems.PointerEventData UnityEngine.EventSystems.TouchInputModule::m_InputPointerEvent
	PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* ___m_InputPointerEvent_19;
	// System.Boolean UnityEngine.EventSystems.TouchInputModule::m_ForceModuleActive
	bool ___m_ForceModuleActive_20;
};

// System.Collections.Generic.Dictionary`2<System.Int32,UnityEngine.EventSystems.PointerEventData>

// System.Collections.Generic.Dictionary`2<System.Int32,UnityEngine.EventSystems.PointerEventData>

// System.Collections.Generic.List`1<UnityEngine.EventSystems.BaseRaycaster>
struct List_1_t02E640552264E3DEAE676267B620815D33BCD0DF_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	BaseRaycasterU5BU5D_tAE62D3FF1A5FF9DE20B2756DA4F4F8981925A799* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<UnityEngine.EventSystems.BaseRaycaster>

// System.Collections.Generic.List`1<System.Object>
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<System.Object>

// System.Collections.Generic.List`1<UnityEngine.EventSystems.RaycastResult>
struct List_1_t8292C421BBB00D7661DC07462822936152BAB446_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	RaycastResultU5BU5D_tEAF6B3C3088179304676571328CBB001D8CECBC7* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<UnityEngine.EventSystems.RaycastResult>

// <PrivateImplementationDetails>
struct U3CPrivateImplementationDetailsU3E_t3A51899FBAA581553000230A6A0F92898553245F_StaticFields
{
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=12 <PrivateImplementationDetails>::1C3635C112D556F4C11A4FE6BDE6ED3F126C4B2B546811BDB64DE7BDED3A05CB
	__StaticArrayInitTypeSizeU3D12_tE6E9A5118C80D71EA1E9325D404FAB06593F00C3 ___1C3635C112D556F4C11A4FE6BDE6ED3F126C4B2B546811BDB64DE7BDED3A05CB_0;
};

// <PrivateImplementationDetails>

// UnityEngine.EventSystems.RaycasterManager
struct RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_StaticFields
{
	// System.Collections.Generic.List`1<UnityEngine.EventSystems.BaseRaycaster> UnityEngine.EventSystems.RaycasterManager::s_Raycasters
	List_1_t02E640552264E3DEAE676267B620815D33BCD0DF* ___s_Raycasters_0;
};

// UnityEngine.EventSystems.RaycasterManager

// UnityEngine.UI.ReflectionMethodsCache
struct ReflectionMethodsCache_t711B47CE11EA2092B94127FF8D3361AE2E4859F5_StaticFields
{
	// UnityEngine.UI.ReflectionMethodsCache UnityEngine.UI.ReflectionMethodsCache::s_ReflectionMethodsCache
	ReflectionMethodsCache_t711B47CE11EA2092B94127FF8D3361AE2E4859F5* ___s_ReflectionMethodsCache_6;
};

// UnityEngine.UI.ReflectionMethodsCache

// System.String
struct String_t_StaticFields
{
	// System.String System.String::Empty
	String_t* ___Empty_6;
};

// System.String

// System.Text.StringBuilder

// System.Text.StringBuilder

// UnityEngine.EventSystems.PhysicsRaycaster/RaycastHitComparer
struct RaycastHitComparer_t8EF6567C19BE9FB575E01A10941FBF7DE3D3DDF1_StaticFields
{
	// UnityEngine.EventSystems.PhysicsRaycaster/RaycastHitComparer UnityEngine.EventSystems.PhysicsRaycaster/RaycastHitComparer::instance
	RaycastHitComparer_t8EF6567C19BE9FB575E01A10941FBF7DE3D3DDF1* ___instance_0;
};

// UnityEngine.EventSystems.PhysicsRaycaster/RaycastHitComparer

// UnityEngine.EventSystems.PointerInputModule/MouseState

// UnityEngine.EventSystems.PointerInputModule/MouseState

// System.Collections.Generic.KeyValuePair`2<System.Int32,System.Object>

// System.Collections.Generic.KeyValuePair`2<System.Int32,System.Object>

// System.Collections.Generic.KeyValuePair`2<System.Int32,UnityEngine.EventSystems.PointerEventData>

// System.Collections.Generic.KeyValuePair`2<System.Int32,UnityEngine.EventSystems.PointerEventData>

// UnityEngine.EventSystems.BaseEventData

// UnityEngine.EventSystems.BaseEventData

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	// System.String System.Boolean::TrueString
	String_t* ___TrueString_5;
	// System.String System.Boolean::FalseString
	String_t* ___FalseString_6;
};

// System.Boolean

// System.Double

// System.Double

// System.Int32

// System.Int32

// UnityEngine.LayerMask

// UnityEngine.LayerMask

// UnityEngine.Mathf
struct Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682_StaticFields
{
	// System.Single UnityEngine.Mathf::Epsilon
	float ___Epsilon_0;
};

// UnityEngine.Mathf

// UnityEngine.Rect

// UnityEngine.Rect

// System.Single

// System.Single

// UnityEngine.Vector2
struct Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7_StaticFields
{
	// UnityEngine.Vector2 UnityEngine.Vector2::zeroVector
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___zeroVector_2;
	// UnityEngine.Vector2 UnityEngine.Vector2::oneVector
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___oneVector_3;
	// UnityEngine.Vector2 UnityEngine.Vector2::upVector
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___upVector_4;
	// UnityEngine.Vector2 UnityEngine.Vector2::downVector
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___downVector_5;
	// UnityEngine.Vector2 UnityEngine.Vector2::leftVector
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___leftVector_6;
	// UnityEngine.Vector2 UnityEngine.Vector2::rightVector
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___rightVector_7;
	// UnityEngine.Vector2 UnityEngine.Vector2::positiveInfinityVector
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___positiveInfinityVector_8;
	// UnityEngine.Vector2 UnityEngine.Vector2::negativeInfinityVector
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___negativeInfinityVector_9;
};

// UnityEngine.Vector2

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

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=12

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=12

// System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>

// System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>

// System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,UnityEngine.EventSystems.PointerEventData>

// System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,UnityEngine.EventSystems.PointerEventData>

// UnityEngine.EventSystems.MoveDirection

// UnityEngine.EventSystems.MoveDirection

// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_StaticFields
{
	// System.Int32 UnityEngine.Object::OffsetOfInstanceIDInCPlusPlusObject
	int32_t ___OffsetOfInstanceIDInCPlusPlusObject_1;
};

// UnityEngine.Object

// UnityEngine.Ray

// UnityEngine.Ray

// UnityEngine.RaycastHit

// UnityEngine.RaycastHit

// UnityEngine.RaycastHit2D

// UnityEngine.RaycastHit2D

// UnityEngine.EventSystems.RaycastResult

// UnityEngine.EventSystems.RaycastResult

// UnityEngine.TouchType

// UnityEngine.TouchType

// UnityEngine.EventSystems.PointerEventData/InputButton

// UnityEngine.EventSystems.PointerEventData/InputButton

// UnityEngine.EventSystems.StandaloneInputModule/InputMode

// UnityEngine.EventSystems.StandaloneInputModule/InputMode

// UnityEngine.Component

// UnityEngine.Component

// UnityEngine.GameObject

// UnityEngine.GameObject

// UnityEngine.EventSystems.PointerEventData

// UnityEngine.EventSystems.PointerEventData

// UnityEngine.Touch

// UnityEngine.Touch

// UnityEngine.EventSystems.PointerInputModule/ButtonState

// UnityEngine.EventSystems.PointerInputModule/ButtonState

// UnityEngine.EventSystems.PointerInputModule/MouseButtonEventData

// UnityEngine.EventSystems.PointerInputModule/MouseButtonEventData

// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IDropHandler>

// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IDropHandler>

// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IEndDragHandler>

// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IEndDragHandler>

// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IInitializePotentialDragHandler>

// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IInitializePotentialDragHandler>

// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IPointerClickHandler>

// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IPointerClickHandler>

// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IPointerDownHandler>

// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IPointerDownHandler>

// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IPointerExitHandler>

// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IPointerExitHandler>

// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IPointerUpHandler>

// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IPointerUpHandler>

// UnityEngine.Behaviour

// UnityEngine.Behaviour

// UnityEngine.Collider

// UnityEngine.Collider

// UnityEngine.Renderer

// UnityEngine.Renderer

// UnityEngine.Transform

// UnityEngine.Transform

// UnityEngine.UI.ReflectionMethodsCache/GetRayIntersectionAllCallback

// UnityEngine.UI.ReflectionMethodsCache/GetRayIntersectionAllCallback

// UnityEngine.UI.ReflectionMethodsCache/GetRayIntersectionAllNonAllocCallback

// UnityEngine.UI.ReflectionMethodsCache/GetRayIntersectionAllNonAllocCallback

// UnityEngine.UI.ReflectionMethodsCache/GetRaycastNonAllocCallback

// UnityEngine.UI.ReflectionMethodsCache/GetRaycastNonAllocCallback

// UnityEngine.UI.ReflectionMethodsCache/RaycastAllCallback

// UnityEngine.UI.ReflectionMethodsCache/RaycastAllCallback

// UnityEngine.Camera
struct Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184_StaticFields
{
	// UnityEngine.Camera/CameraCallback UnityEngine.Camera::onPreCull
	CameraCallback_t844E527BFE37BC0495E7F67993E43C07642DA9DD* ___onPreCull_4;
	// UnityEngine.Camera/CameraCallback UnityEngine.Camera::onPreRender
	CameraCallback_t844E527BFE37BC0495E7F67993E43C07642DA9DD* ___onPreRender_5;
	// UnityEngine.Camera/CameraCallback UnityEngine.Camera::onPostRender
	CameraCallback_t844E527BFE37BC0495E7F67993E43C07642DA9DD* ___onPostRender_6;
};

// UnityEngine.Camera

// UnityEngine.Collider2D

// UnityEngine.Collider2D

// UnityEngine.MonoBehaviour

// UnityEngine.MonoBehaviour

// UnityEngine.Rendering.SortingGroup

// UnityEngine.Rendering.SortingGroup

// UnityEngine.SpriteRenderer

// UnityEngine.SpriteRenderer

// UnityEngine.U2D.SpriteShapeRenderer

// UnityEngine.U2D.SpriteShapeRenderer

// UnityEngine.Tilemaps.TilemapRenderer

// UnityEngine.Tilemaps.TilemapRenderer

// UnityEngine.EventSystems.UIBehaviour

// UnityEngine.EventSystems.UIBehaviour

// UnityEngine.EventSystems.BaseInput

// UnityEngine.EventSystems.BaseInput

// UnityEngine.EventSystems.BaseInputModule

// UnityEngine.EventSystems.BaseInputModule

// UnityEngine.EventSystems.BaseRaycaster

// UnityEngine.EventSystems.BaseRaycaster

// UnityEngine.EventSystems.EventSystem
struct EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707_StaticFields
{
	// System.Collections.Generic.List`1<UnityEngine.EventSystems.EventSystem> UnityEngine.EventSystems.EventSystem::m_EventSystems
	List_1_tF2FE88545EFEC788CAAE6C74EC2F78E937FCCAC3* ___m_EventSystems_6;
	// System.Comparison`1<UnityEngine.EventSystems.RaycastResult> UnityEngine.EventSystems.EventSystem::s_RaycastComparer
	Comparison_1_t9FCAC8C8CE160A96C5AAD2DE1D353DCE8A2FEEFC* ___s_RaycastComparer_14;
	// UnityEngine.EventSystems.EventSystem/UIToolkitOverrideConfig UnityEngine.EventSystems.EventSystem::s_UIToolkitOverride
	UIToolkitOverrideConfig_t4E6B4528E38BCA7DA72C45424634806200A50182 ___s_UIToolkitOverride_15;
};

// UnityEngine.EventSystems.EventSystem

// UnityEngine.EventSystems.PhysicsRaycaster

// UnityEngine.EventSystems.PhysicsRaycaster

// UnityEngine.EventSystems.PointerInputModule

// UnityEngine.EventSystems.PointerInputModule

// UnityEngine.EventSystems.Physics2DRaycaster

// UnityEngine.EventSystems.Physics2DRaycaster

// UnityEngine.EventSystems.TouchInputModule

// UnityEngine.EventSystems.TouchInputModule
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// UnityEngine.EventSystems.BaseRaycaster[]
struct BaseRaycasterU5BU5D_tAE62D3FF1A5FF9DE20B2756DA4F4F8981925A799  : public RuntimeArray
{
	ALIGN_FIELD (8) BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* m_Items[1];

	inline BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* value)
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
// UnityEngine.RaycastHit2D[]
struct RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7  : public RuntimeArray
{
	ALIGN_FIELD (8) RaycastHit2D_t3EAAA06E6603C6BC61AC1291DD881C5C1E23BDFA m_Items[1];

	inline RaycastHit2D_t3EAAA06E6603C6BC61AC1291DD881C5C1E23BDFA GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RaycastHit2D_t3EAAA06E6603C6BC61AC1291DD881C5C1E23BDFA* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RaycastHit2D_t3EAAA06E6603C6BC61AC1291DD881C5C1E23BDFA value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline RaycastHit2D_t3EAAA06E6603C6BC61AC1291DD881C5C1E23BDFA GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RaycastHit2D_t3EAAA06E6603C6BC61AC1291DD881C5C1E23BDFA* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RaycastHit2D_t3EAAA06E6603C6BC61AC1291DD881C5C1E23BDFA value)
	{
		m_Items[index] = value;
	}
};
// UnityEngine.RaycastHit[]
struct RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8  : public RuntimeArray
{
	ALIGN_FIELD (8) RaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5 m_Items[1];

	inline RaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline RaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5 value)
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
// UnityEngine.EventSystems.RaycastResult[]
struct RaycastResultU5BU5D_tEAF6B3C3088179304676571328CBB001D8CECBC7  : public RuntimeArray
{
	ALIGN_FIELD (8) RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 m_Items[1];

	inline RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_GameObject_0), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___module_1), (void*)NULL);
		#endif
	}
	inline RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_GameObject_0), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___module_1), (void*)NULL);
		#endif
	}
};


// System.Boolean UnityEngine.EventSystems.ExecuteEvents::Execute<System.Object>(UnityEngine.GameObject,UnityEngine.EventSystems.BaseEventData,UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<T>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ExecuteEvents_Execute_TisRuntimeObject_mDC4455B743BE4A6BA46DD741D0E0AB150FF1209A_gshared (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_target, BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F* ___1_eventData, EventFunction_1_t297B5C47242D1B98BEC955E2804FA142B43E7927* ___2_functor, const RuntimeMethod* method) ;
// UnityEngine.GameObject UnityEngine.EventSystems.ExecuteEvents::ExecuteHierarchy<System.Object>(UnityEngine.GameObject,UnityEngine.EventSystems.BaseEventData,UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<T>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ExecuteEvents_ExecuteHierarchy_TisRuntimeObject_m47C22A77611C31042CA566EE345A4A1017A40A65_gshared (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_root, BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F* ___1_eventData, EventFunction_1_t297B5C47242D1B98BEC955E2804FA142B43E7927* ___2_callbackFunction, const RuntimeMethod* method) ;
// UnityEngine.GameObject UnityEngine.EventSystems.ExecuteEvents::GetEventHandler<System.Object>(UnityEngine.GameObject)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ExecuteEvents_GetEventHandler_TisRuntimeObject_m86588AD6FDDC9670CE26E5111D23F49B821330C5_gshared (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_root, const RuntimeMethod* method) ;
// System.Collections.Generic.Dictionary`2/Enumerator<TKey,TValue> System.Collections.Generic.Dictionary`2<System.Int32,System.Object>::GetEnumerator()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tE92C1AC40A104A179B94F8A013728FD9314CFBD3 Dictionary_2_GetEnumerator_m3F1620145BA0815B7C7CD648EF054558AA26556A_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>::Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator_Dispose_mAECCBE12C0427D7ACF88F82FA266F1AE37402565_gshared (Enumerator_tE92C1AC40A104A179B94F8A013728FD9314CFBD3* __this, const RuntimeMethod* method) ;
// System.Collections.Generic.KeyValuePair`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>::get_Current()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR KeyValuePair_2_tDC26B09C26BA829DDE331BCB6AF7C508C763D7A3 Enumerator_get_Current_m90160D324DA0D9F5624A345F47D8E226A118911A_gshared_inline (Enumerator_tE92C1AC40A104A179B94F8A013728FD9314CFBD3* __this, const RuntimeMethod* method) ;
// System.String System.Collections.Generic.KeyValuePair`2<System.Int32,System.Object>::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* KeyValuePair_2_ToString_mCCDA8E0F389BAA2675BC9C032158839E073A7A37_gshared (KeyValuePair_2_tDC26B09C26BA829DDE331BCB6AF7C508C763D7A3* __this, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,System.Object>::MoveNext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_m4DC143BC57F14EDD85AB13B6D6F3B5D0E319B30E_gshared (Enumerator_tE92C1AC40A104A179B94F8A013728FD9314CFBD3* __this, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.List`1<System.Object>::Contains(T)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m4C9139C2A6B23E9343D3F87807B32C6E2CFE660D_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::Add(T)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.List`1<System.Object>::Remove(T)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_m4DFA48F4CEB9169601E75FC28517C5C06EFA5AD7_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
// T[] UnityEngine.Component::GetComponentsInParent<System.Object>()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* Component_GetComponentsInParent_TisRuntimeObject_m161F08219ECBE099E346F616990662F0117D4C8E_gshared (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;
// T UnityEngine.GameObject::GetComponent<System.Object>()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* GameObject_GetComponent_TisRuntimeObject_m6EAED4AA356F0F48288F67899E5958792395563B_gshared (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method) ;
// System.Int32 System.Collections.Generic.List`1<UnityEngine.EventSystems.RaycastResult>::get_Count()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_mE2EBEDC861C1EC398EDBE6CF2C9FB604AA71523E_gshared_inline (List_1_t8292C421BBB00D7661DC07462822936152BAB446* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<UnityEngine.EventSystems.RaycastResult>::Add(T)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEB6DFEA132B5B7BF540D34177054003185D250E7_gshared_inline (List_1_t8292C421BBB00D7661DC07462822936152BAB446* __this, RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 ___0_item, const RuntimeMethod* method) ;
// T UnityEngine.Component::GetComponent<System.Object>()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Component_GetComponent_TisRuntimeObject_m7181F81CAEC2CF53F5D2BC79B7425C16E1F80D33_gshared (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;
// System.Void System.Array::Sort<UnityEngine.RaycastHit>(T[],System.Int32,System.Int32,System.Collections.Generic.IComparer`1<T>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisRaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5_mBF83A49E9B1F007DD08F7E076AF45D2AED7A45EB_gshared (RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;

// System.Void UnityEngine.EventSystems.PointerInputModule::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PointerInputModule__ctor_mBF074492478BFC24F87EF2C941D6C11A8ACDAF11 (PointerInputModule_tD71E11FA989C22D83883E120EAA4F05929907556* __this, const RuntimeMethod* method) ;
// UnityEngine.EventSystems.EventSystem UnityEngine.EventSystems.BaseInputModule::get_eventSystem()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707* BaseInputModule_get_eventSystem_m341B2378F61A58D5432906B9EE1E12265E2FAB33 (BaseInputModule_tF3B7C22AF1419B2AC9ECE6589357DC1B88ED96B1* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.EventSystems.EventSystem::get_isFocused()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool EventSystem_get_isFocused_mB0BB5BE03F7203A06D2F351ACD28BA177079104A (EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707* __this, const RuntimeMethod* method) ;
// UnityEngine.GameObject UnityEngine.EventSystems.PointerEventData::get_pointerDrag()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* PointerEventData_get_pointerDrag_m36BF08A32216845A8095C5F74DFE6C9959A11E96_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Object::op_Inequality(UnityEngine.Object,UnityEngine.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_x, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_y, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.EventSystems.PointerEventData::get_dragging()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool PointerEventData_get_dragging_mE0AD837F228E3830D4A74657AD3D47F53F6C87E9_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, const RuntimeMethod* method) ;
// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IEndDragHandler> UnityEngine.EventSystems.ExecuteEvents::get_endDragHandler()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EventFunction_1_t33BA7CA3F9202146F70BE77589CE24F7451C584C* ExecuteEvents_get_endDragHandler_mE78FEEEAE114635E416FF1FE33C851E62B60555B (const RuntimeMethod* method) ;
// System.Boolean UnityEngine.EventSystems.ExecuteEvents::Execute<UnityEngine.EventSystems.IEndDragHandler>(UnityEngine.GameObject,UnityEngine.EventSystems.BaseEventData,UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<T>)
inline bool ExecuteEvents_Execute_TisIEndDragHandler_t9A93E4A27E7CEED446E5FE3DACF39B1A552C23A9_m6AA443D4F53AF0FEBAC269F761A158635243467E (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_target, BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F* ___1_eventData, EventFunction_1_t33BA7CA3F9202146F70BE77589CE24F7451C584C* ___2_functor, const RuntimeMethod* method)
{
	return ((  bool (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F*, EventFunction_1_t33BA7CA3F9202146F70BE77589CE24F7451C584C*, const RuntimeMethod*))ExecuteEvents_Execute_TisRuntimeObject_mDC4455B743BE4A6BA46DD741D0E0AB150FF1209A_gshared)(___0_target, ___1_eventData, ___2_functor, method);
}
// UnityEngine.EventSystems.BaseInput UnityEngine.EventSystems.BaseInputModule::get_input()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BaseInput_t69C46B0AA3C24F1CA842A0D03CACACC4EC788622* BaseInputModule_get_input_mCB3F78528AA14A7AD7E957870DBB0152B4BF13FB (BaseInputModule_tF3B7C22AF1419B2AC9ECE6589357DC1B88ED96B1* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.EventSystems.TouchInputModule::get_forceModuleActive()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool TouchInputModule_get_forceModuleActive_m7200F7B6C80EDD69987615B8356B6B2497461FCA (TouchInputModule_t154B7CF685F02D5B9529572B1A96EBD75AAA945C* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.EventSystems.BaseInputModule::ShouldActivateModule()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool BaseInputModule_ShouldActivateModule_m51B70F9097EF7FEB20B62D4D775F7FEA853185A1 (BaseInputModule_tF3B7C22AF1419B2AC9ECE6589357DC1B88ED96B1* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.EventSystems.TouchInputModule::UseFakeInput()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool TouchInputModule_UseFakeInput_m66A84384ADA044187F239B1CFC143C42E5E56774 (TouchInputModule_t154B7CF685F02D5B9529572B1A96EBD75AAA945C* __this, const RuntimeMethod* method) ;
// UnityEngine.Vector2 UnityEngine.Vector2::op_Subtraction(UnityEngine.Vector2,UnityEngine.Vector2)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 Vector2_op_Subtraction_m44475FCDAD2DA2F98D78A6625EC2DCDFE8803837_inline (Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___0_a, Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___1_b, const RuntimeMethod* method) ;
// System.Single UnityEngine.Vector2::get_sqrMagnitude()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Vector2_get_sqrMagnitude_mA16336720C14EEF8BA9B55AE33B98C9EE2082BDC_inline (Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.TouchInputModule::FakeTouches()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TouchInputModule_FakeTouches_m264BF2C70234CD04B0162FE4CED673B1A77A84F9 (TouchInputModule_t154B7CF685F02D5B9529572B1A96EBD75AAA945C* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.TouchInputModule::ProcessTouchEvents()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TouchInputModule_ProcessTouchEvents_mBB28D85996F6280141E39A462BC35EF01373E514 (TouchInputModule_t154B7CF685F02D5B9529572B1A96EBD75AAA945C* __this, const RuntimeMethod* method) ;
// UnityEngine.EventSystems.PointerInputModule/ButtonState UnityEngine.EventSystems.PointerInputModule/MouseState::GetButtonState(UnityEngine.EventSystems.PointerEventData/InputButton)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ButtonState_tB671FC9C48F167DBC1CDAFEB53C373D8567AE503* MouseState_GetButtonState_mD25E7D214B0499DBBE3B3E532CD7085C1A021E51 (MouseState_tCCE70861DE1EEECF949AFE8E2A922541D4E08A09* __this, int32_t ___0_button, const RuntimeMethod* method) ;
// UnityEngine.EventSystems.PointerInputModule/MouseButtonEventData UnityEngine.EventSystems.PointerInputModule/ButtonState::get_eventData()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MouseButtonEventData_t0761D63D3A2B13090597C22DD97597CC7FE4D154* ButtonState_get_eventData_m4767730784143F1DCE06B6138658A31CBC5E155F (ButtonState_tB671FC9C48F167DBC1CDAFEB53C373D8567AE503* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.EventSystems.PointerInputModule/MouseButtonEventData::PressedThisFrame()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool MouseButtonEventData_PressedThisFrame_mEE5DC95537AAEB346C57DCA85917E0701A44388D (MouseButtonEventData_t0761D63D3A2B13090597C22DD97597CC7FE4D154* __this, const RuntimeMethod* method) ;
// UnityEngine.Vector2 UnityEngine.Vector2::get_zero()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 Vector2_get_zero_m32506C40EC2EE7D5D4410BF40D3EE683A3D5F32C_inline (const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.PointerEventData::set_delta(UnityEngine.Vector2)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PointerEventData_set_delta_mD200AF7CCAEAD92D947091902AF864CB4ACE0F1D_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___0_value, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.EventSystems.PointerInputModule/MouseButtonEventData::ReleasedThisFrame()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool MouseButtonEventData_ReleasedThisFrame_m5AD4F06D1CA6E0ACD6E84EEFAD4FB112098AFD51 (MouseButtonEventData_t0761D63D3A2B13090597C22DD97597CC7FE4D154* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.TouchInputModule::ProcessTouchPress(UnityEngine.EventSystems.PointerEventData,System.Boolean,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TouchInputModule_ProcessTouchPress_m1DC51E52E6B419F02626EB567A60411A0FCFA517 (TouchInputModule_t154B7CF685F02D5B9529572B1A96EBD75AAA945C* __this, PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* ___0_pointerEvent, bool ___1_pressed, bool ___2_released, const RuntimeMethod* method) ;
// UnityEngine.TouchType UnityEngine.Touch::get_type()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Touch_get_type_mB505EF2DCF13160DFA0C6AAF406DCB4CBED20745 (Touch_t03E51455ED508492B3F278903A0114FA0E87B417* __this, const RuntimeMethod* method) ;
// UnityEngine.EventSystems.PointerEventData UnityEngine.EventSystems.PointerInputModule::GetTouchPointerEventData(UnityEngine.Touch,System.Boolean&,System.Boolean&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* PointerInputModule_GetTouchPointerEventData_m55EBA8BD04214AAD8E98B9109D44610496A5B2E1 (PointerInputModule_tD71E11FA989C22D83883E120EAA4F05929907556* __this, Touch_t03E51455ED508492B3F278903A0114FA0E87B417 ___0_input, bool* ___1_pressed, bool* ___2_released, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.PointerInputModule::RemovePointerData(UnityEngine.EventSystems.PointerEventData)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PointerInputModule_RemovePointerData_m012713A1B4511855549793D6BA2B7998134B1BE9 (PointerInputModule_tD71E11FA989C22D83883E120EAA4F05929907556* __this, PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* ___0_data, const RuntimeMethod* method) ;
// UnityEngine.EventSystems.RaycastResult UnityEngine.EventSystems.PointerEventData::get_pointerCurrentRaycast()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 PointerEventData_get_pointerCurrentRaycast_m1C6B7D707CEE9C6574DD443289D90102EDC7A2C4_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, const RuntimeMethod* method) ;
// UnityEngine.GameObject UnityEngine.EventSystems.RaycastResult::get_gameObject()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* RaycastResult_get_gameObject_m77014B442B9E2D10F2CC3AEEDC07AA95CDE1E2F1 (RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.PointerEventData::set_eligibleForClick(System.Boolean)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PointerEventData_set_eligibleForClick_m360125CB3E348F3CF64C39F163467A842E479C21_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, bool ___0_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.PointerEventData::set_dragging(System.Boolean)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PointerEventData_set_dragging_m43982B3F95F05986F40A736914CFBC45D2A9BB8E_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, bool ___0_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.PointerEventData::set_useDragThreshold(System.Boolean)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PointerEventData_set_useDragThreshold_m63FE2034E4B240F1A0A902B1EB893B3DBA2D848B_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, bool ___0_value, const RuntimeMethod* method) ;
// UnityEngine.Vector2 UnityEngine.EventSystems.PointerEventData::get_position()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 PointerEventData_get_position_m5BE71C28EB72EFB8435749E4E6E839213AEF458C_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.PointerEventData::set_pressPosition(UnityEngine.Vector2)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PointerEventData_set_pressPosition_m85544FBAB798DABE70067508294A6C4841A95379_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___0_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.PointerEventData::set_pointerPressRaycast(UnityEngine.EventSystems.RaycastResult)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PointerEventData_set_pointerPressRaycast_m55CA127474B4CBCA795A9C872B7630AAF766F852_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 ___0_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.PointerInputModule::DeselectIfSelectionChanged(UnityEngine.GameObject,UnityEngine.EventSystems.BaseEventData)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PointerInputModule_DeselectIfSelectionChanged_m8F111DD2317E33C4F0498F651BC52BD5C984A95B (PointerInputModule_tD71E11FA989C22D83883E120EAA4F05929907556* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_currentOverGo, BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F* ___1_pointerEvent, const RuntimeMethod* method) ;
// UnityEngine.GameObject UnityEngine.EventSystems.PointerEventData::get_pointerEnter()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* PointerEventData_get_pointerEnter_m6CE76D5C0C36C4666CDDE348B57885C52D495A4B_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.BaseInputModule::HandlePointerExitAndEnter(UnityEngine.EventSystems.PointerEventData,UnityEngine.GameObject)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseInputModule_HandlePointerExitAndEnter_m0815F06EAF8F937916E0656D66A69844CB211298 (BaseInputModule_tF3B7C22AF1419B2AC9ECE6589357DC1B88ED96B1* __this, PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* ___0_currentPointerData, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___1_newEnterTarget, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.PointerEventData::set_pointerEnter(UnityEngine.GameObject)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PointerEventData_set_pointerEnter_m2DA660C24CBDE9B83DF2B2D09D9AF0E94A770D17_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_value, const RuntimeMethod* method) ;
// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IPointerDownHandler> UnityEngine.EventSystems.ExecuteEvents::get_pointerDownHandler()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EventFunction_1_t00024D26E9CCD074EEBC25568B0383863A4CF117* ExecuteEvents_get_pointerDownHandler_mA67CE33D32540939A273DB88D6456C7FE43C13EF (const RuntimeMethod* method) ;
// UnityEngine.GameObject UnityEngine.EventSystems.ExecuteEvents::ExecuteHierarchy<UnityEngine.EventSystems.IPointerDownHandler>(UnityEngine.GameObject,UnityEngine.EventSystems.BaseEventData,UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<T>)
inline GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ExecuteEvents_ExecuteHierarchy_TisIPointerDownHandler_t42CC83619BB6295404D44090142F7726003CE573_mF031AC46543C02039764EDB1B0673DFA36B1F58C (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_root, BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F* ___1_eventData, EventFunction_1_t00024D26E9CCD074EEBC25568B0383863A4CF117* ___2_callbackFunction, const RuntimeMethod* method)
{
	return ((  GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F*, EventFunction_1_t00024D26E9CCD074EEBC25568B0383863A4CF117*, const RuntimeMethod*))ExecuteEvents_ExecuteHierarchy_TisRuntimeObject_m47C22A77611C31042CA566EE345A4A1017A40A65_gshared)(___0_root, ___1_eventData, ___2_callbackFunction, method);
}
// System.Boolean UnityEngine.Object::op_Equality(UnityEngine.Object,UnityEngine.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_x, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_y, const RuntimeMethod* method) ;
// UnityEngine.GameObject UnityEngine.EventSystems.ExecuteEvents::GetEventHandler<UnityEngine.EventSystems.IPointerClickHandler>(UnityEngine.GameObject)
inline GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ExecuteEvents_GetEventHandler_TisIPointerClickHandler_t77341AA19DE37C26F5F619DE8BD28B70D5A2B5D8_m3363BED905E60A4545A8CA5B8C68BA709E99536E (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_root, const RuntimeMethod* method)
{
	return ((  GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, const RuntimeMethod*))ExecuteEvents_GetEventHandler_TisRuntimeObject_m86588AD6FDDC9670CE26E5111D23F49B821330C5_gshared)(___0_root, method);
}
// System.Single UnityEngine.Time::get_unscaledTime()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Time_get_unscaledTime_mAF4040B858903E1325D1C65B8BF1AC61460B2503 (const RuntimeMethod* method) ;
// UnityEngine.GameObject UnityEngine.EventSystems.PointerEventData::get_lastPress()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* PointerEventData_get_lastPress_m46720C62503214A44EE947679A8BA307BC2AEEDC_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, const RuntimeMethod* method) ;
// System.Single UnityEngine.EventSystems.PointerEventData::get_clickTime()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float PointerEventData_get_clickTime_m5ABE0298E8CEF28B6BD7E750E940756CD78AB96E_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.EventSystems.PointerEventData::get_clickCount()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t PointerEventData_get_clickCount_m3977011C09DB9F904B1AAC3708B821B8D6AC0F9F_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.PointerEventData::set_clickCount(System.Int32)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PointerEventData_set_clickCount_m0A87C2C367987492F310786DC9C3DF1616EA4D49_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, int32_t ___0_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.PointerEventData::set_clickTime(System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PointerEventData_set_clickTime_m93D27EB35F490AC9100369A23002F09148F85996_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, float ___0_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.PointerEventData::set_pointerPress(UnityEngine.GameObject)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PointerEventData_set_pointerPress_m51241AAA6E5F87ADEBBB8DB7D4452CE45200BEE8 (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.PointerEventData::set_rawPointerPress(UnityEngine.GameObject)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PointerEventData_set_rawPointerPress_mEEC4E3C7CD00F1DDCD3DA98DA5837E71BB8455E3_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_value, const RuntimeMethod* method) ;
// UnityEngine.GameObject UnityEngine.EventSystems.ExecuteEvents::GetEventHandler<UnityEngine.EventSystems.IDragHandler>(UnityEngine.GameObject)
inline GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ExecuteEvents_GetEventHandler_TisIDragHandler_t9FF2B3D79AB401D7E2485254973D15C0F117D00D_m9AA4E18082F53C60962F70D75570F1D400C37FBA (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_root, const RuntimeMethod* method)
{
	return ((  GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, const RuntimeMethod*))ExecuteEvents_GetEventHandler_TisRuntimeObject_m86588AD6FDDC9670CE26E5111D23F49B821330C5_gshared)(___0_root, method);
}
// System.Void UnityEngine.EventSystems.PointerEventData::set_pointerDrag(UnityEngine.GameObject)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PointerEventData_set_pointerDrag_m0E8D72362B07962843671C39ADC8F4D5E4915010_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_value, const RuntimeMethod* method) ;
// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IInitializePotentialDragHandler> UnityEngine.EventSystems.ExecuteEvents::get_initializePotentialDrag()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EventFunction_1_t7DFDB0A0C9926E06BF7870695CD48A0533DFABAD* ExecuteEvents_get_initializePotentialDrag_m16F4CD40448FB1B78F6683AA26A9CC574F48AFBD (const RuntimeMethod* method) ;
// System.Boolean UnityEngine.EventSystems.ExecuteEvents::Execute<UnityEngine.EventSystems.IInitializePotentialDragHandler>(UnityEngine.GameObject,UnityEngine.EventSystems.BaseEventData,UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<T>)
inline bool ExecuteEvents_Execute_TisIInitializePotentialDragHandler_tAFCBB3BBC98C928ED8D5703C39F4781446AB8E9E_mABD9E1ECC8C04235760B3855DF03F2308F62071C (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_target, BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F* ___1_eventData, EventFunction_1_t7DFDB0A0C9926E06BF7870695CD48A0533DFABAD* ___2_functor, const RuntimeMethod* method)
{
	return ((  bool (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F*, EventFunction_1_t7DFDB0A0C9926E06BF7870695CD48A0533DFABAD*, const RuntimeMethod*))ExecuteEvents_Execute_TisRuntimeObject_mDC4455B743BE4A6BA46DD741D0E0AB150FF1209A_gshared)(___0_target, ___1_eventData, ___2_functor, method);
}
// UnityEngine.GameObject UnityEngine.EventSystems.PointerEventData::get_pointerPress()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* PointerEventData_get_pointerPress_mEE815DDB67E40AA587090BCCE0E3CABA6405C50A (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, const RuntimeMethod* method) ;
// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IPointerUpHandler> UnityEngine.EventSystems.ExecuteEvents::get_pointerUpHandler()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EventFunction_1_t919A3841A202FB8C678BC0172FAB7E2F79B88AD8* ExecuteEvents_get_pointerUpHandler_m51B83B4AD7498D6F7A2CBD5F2331E91A37AE4CF2 (const RuntimeMethod* method) ;
// System.Boolean UnityEngine.EventSystems.ExecuteEvents::Execute<UnityEngine.EventSystems.IPointerUpHandler>(UnityEngine.GameObject,UnityEngine.EventSystems.BaseEventData,UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<T>)
inline bool ExecuteEvents_Execute_TisIPointerUpHandler_tB2D4D0ABEAFF77BE8D0159D638D85E1AF7BAF210_mBB70745D5D17BF6402CABEFF0F52911F88C197A6 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_target, BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F* ___1_eventData, EventFunction_1_t919A3841A202FB8C678BC0172FAB7E2F79B88AD8* ___2_functor, const RuntimeMethod* method)
{
	return ((  bool (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F*, EventFunction_1_t919A3841A202FB8C678BC0172FAB7E2F79B88AD8*, const RuntimeMethod*))ExecuteEvents_Execute_TisRuntimeObject_mDC4455B743BE4A6BA46DD741D0E0AB150FF1209A_gshared)(___0_target, ___1_eventData, ___2_functor, method);
}
// System.Boolean UnityEngine.EventSystems.PointerEventData::get_eligibleForClick()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool PointerEventData_get_eligibleForClick_m4B01A1640C694FD7421BDFB19CF763BC85672C8E_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, const RuntimeMethod* method) ;
// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IPointerClickHandler> UnityEngine.EventSystems.ExecuteEvents::get_pointerClickHandler()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EventFunction_1_t586168BFEFD0CF29A2B706B5411BF712BD73359E* ExecuteEvents_get_pointerClickHandler_m0017F9D1EAF7C02CDDB4C148C92D6685D88EA8D5 (const RuntimeMethod* method) ;
// System.Boolean UnityEngine.EventSystems.ExecuteEvents::Execute<UnityEngine.EventSystems.IPointerClickHandler>(UnityEngine.GameObject,UnityEngine.EventSystems.BaseEventData,UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<T>)
inline bool ExecuteEvents_Execute_TisIPointerClickHandler_t77341AA19DE37C26F5F619DE8BD28B70D5A2B5D8_m024FB23AA1DBB1B7A5E1935FA35A1E4FF57AC5F6 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_target, BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F* ___1_eventData, EventFunction_1_t586168BFEFD0CF29A2B706B5411BF712BD73359E* ___2_functor, const RuntimeMethod* method)
{
	return ((  bool (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F*, EventFunction_1_t586168BFEFD0CF29A2B706B5411BF712BD73359E*, const RuntimeMethod*))ExecuteEvents_Execute_TisRuntimeObject_mDC4455B743BE4A6BA46DD741D0E0AB150FF1209A_gshared)(___0_target, ___1_eventData, ___2_functor, method);
}
// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IDropHandler> UnityEngine.EventSystems.ExecuteEvents::get_dropHandler()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EventFunction_1_tB3864D36512C3A896DAC44E898E5D9E1A92CB733* ExecuteEvents_get_dropHandler_m8E00FA7361DE68780ACEB365E6B14206A2180D03 (const RuntimeMethod* method) ;
// UnityEngine.GameObject UnityEngine.EventSystems.ExecuteEvents::ExecuteHierarchy<UnityEngine.EventSystems.IDropHandler>(UnityEngine.GameObject,UnityEngine.EventSystems.BaseEventData,UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<T>)
inline GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ExecuteEvents_ExecuteHierarchy_TisIDropHandler_t9F3B358BA4812886852E9AB85A653ABF73B9AA35_m0C0E2A729F88D6AB5AC2B4FD9C4E33D181A52A57 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_root, BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F* ___1_eventData, EventFunction_1_tB3864D36512C3A896DAC44E898E5D9E1A92CB733* ___2_callbackFunction, const RuntimeMethod* method)
{
	return ((  GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F*, EventFunction_1_tB3864D36512C3A896DAC44E898E5D9E1A92CB733*, const RuntimeMethod*))ExecuteEvents_ExecuteHierarchy_TisRuntimeObject_m47C22A77611C31042CA566EE345A4A1017A40A65_gshared)(___0_root, ___1_eventData, ___2_callbackFunction, method);
}
// UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<UnityEngine.EventSystems.IPointerExitHandler> UnityEngine.EventSystems.ExecuteEvents::get_pointerExitHandler()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EventFunction_1_tA70AAFA2BD47CD0A094BCB586E2EA3E04C5F8916* ExecuteEvents_get_pointerExitHandler_m03735363884BC967C1B04246B51FE98886C9C6DE (const RuntimeMethod* method) ;
// UnityEngine.GameObject UnityEngine.EventSystems.ExecuteEvents::ExecuteHierarchy<UnityEngine.EventSystems.IPointerExitHandler>(UnityEngine.GameObject,UnityEngine.EventSystems.BaseEventData,UnityEngine.EventSystems.ExecuteEvents/EventFunction`1<T>)
inline GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ExecuteEvents_ExecuteHierarchy_TisIPointerExitHandler_t1AA3FC124CC77401AF27435A3D6E611F5C7A57EE_m50CEB3F041077A74C37270714BBF0CC3EB37DD92 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_root, BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F* ___1_eventData, EventFunction_1_tA70AAFA2BD47CD0A094BCB586E2EA3E04C5F8916* ___2_callbackFunction, const RuntimeMethod* method)
{
	return ((  GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, BaseEventData_tE03A848325C0AE8E76C6CA15FD86395EBF83364F*, EventFunction_1_tA70AAFA2BD47CD0A094BCB586E2EA3E04C5F8916*, const RuntimeMethod*))ExecuteEvents_ExecuteHierarchy_TisRuntimeObject_m47C22A77611C31042CA566EE345A4A1017A40A65_gshared)(___0_root, ___1_eventData, ___2_callbackFunction, method);
}
// System.Void UnityEngine.EventSystems.BaseInputModule::DeactivateModule()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseInputModule_DeactivateModule_mAE698307DADBE4DE8A26BD3DE5F3F7E3D75B385D (BaseInputModule_tF3B7C22AF1419B2AC9ECE6589357DC1B88ED96B1* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.PointerInputModule::ClearSelection()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PointerInputModule_ClearSelection_mC5852667E5B9CA97C2A4CAB3D7C907344511C1D2 (PointerInputModule_tD71E11FA989C22D83883E120EAA4F05929907556* __this, const RuntimeMethod* method) ;
// System.Void System.Text.StringBuilder::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D (StringBuilder_t* __this, const RuntimeMethod* method) ;
// System.Text.StringBuilder System.Text.StringBuilder::AppendLine(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_AppendLine_mF75744CE941C63E33188E22E936B71A24D3CBF88 (StringBuilder_t* __this, String_t* ___0_value, const RuntimeMethod* method) ;
// UnityEngine.EventSystems.PointerEventData UnityEngine.EventSystems.PointerInputModule::GetLastPointerEventData(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* PointerInputModule_GetLastPointerEventData_m6355023718EB2DCF6D9C226A57B63B70CCEECAB4 (PointerInputModule_tD71E11FA989C22D83883E120EAA4F05929907556* __this, int32_t ___0_id, const RuntimeMethod* method) ;
// System.Collections.Generic.Dictionary`2/Enumerator<TKey,TValue> System.Collections.Generic.Dictionary`2<System.Int32,UnityEngine.EventSystems.PointerEventData>::GetEnumerator()
inline Enumerator_tAC6F215019B1EAEAEE81308CEBA6052DECD5EE7E Dictionary_2_GetEnumerator_m5127D66D8AB03E7A21778DD898242C65F0EED034 (Dictionary_2_t489B023479196B8FC9709A9F834FC38729BD9493* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_tAC6F215019B1EAEAEE81308CEBA6052DECD5EE7E (*) (Dictionary_2_t489B023479196B8FC9709A9F834FC38729BD9493*, const RuntimeMethod*))Dictionary_2_GetEnumerator_m3F1620145BA0815B7C7CD648EF054558AA26556A_gshared)(__this, method);
}
// System.Void System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,UnityEngine.EventSystems.PointerEventData>::Dispose()
inline void Enumerator_Dispose_m939CB6214446517A933B0216F1C64AB86E291714 (Enumerator_tAC6F215019B1EAEAEE81308CEBA6052DECD5EE7E* __this, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_tAC6F215019B1EAEAEE81308CEBA6052DECD5EE7E*, const RuntimeMethod*))Enumerator_Dispose_mAECCBE12C0427D7ACF88F82FA266F1AE37402565_gshared)(__this, method);
}
// System.Collections.Generic.KeyValuePair`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,UnityEngine.EventSystems.PointerEventData>::get_Current()
inline KeyValuePair_2_tC51A92A69CB9B2F98A91443EE066E405EDCA4296 Enumerator_get_Current_mEC2B6AFDB80F9344C20DF0D6A63925642A413615_inline (Enumerator_tAC6F215019B1EAEAEE81308CEBA6052DECD5EE7E* __this, const RuntimeMethod* method)
{
	return ((  KeyValuePair_2_tC51A92A69CB9B2F98A91443EE066E405EDCA4296 (*) (Enumerator_tAC6F215019B1EAEAEE81308CEBA6052DECD5EE7E*, const RuntimeMethod*))Enumerator_get_Current_m90160D324DA0D9F5624A345F47D8E226A118911A_gshared_inline)(__this, method);
}
// System.String System.Collections.Generic.KeyValuePair`2<System.Int32,UnityEngine.EventSystems.PointerEventData>::ToString()
inline String_t* KeyValuePair_2_ToString_m5F8161F26E20B830F794E3C0B87C0570D011D4AD (KeyValuePair_2_tC51A92A69CB9B2F98A91443EE066E405EDCA4296* __this, const RuntimeMethod* method)
{
	return ((  String_t* (*) (KeyValuePair_2_tC51A92A69CB9B2F98A91443EE066E405EDCA4296*, const RuntimeMethod*))KeyValuePair_2_ToString_mCCDA8E0F389BAA2675BC9C032158839E073A7A37_gshared)(__this, method);
}
// System.Boolean System.Collections.Generic.Dictionary`2/Enumerator<System.Int32,UnityEngine.EventSystems.PointerEventData>::MoveNext()
inline bool Enumerator_MoveNext_m69F94D82492DD2778B91F594B491223C02265150 (Enumerator_tAC6F215019B1EAEAEE81308CEBA6052DECD5EE7E* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_tAC6F215019B1EAEAEE81308CEBA6052DECD5EE7E*, const RuntimeMethod*))Enumerator_MoveNext_m4DC143BC57F14EDD85AB13B6D6F3B5D0E319B30E_gshared)(__this, method);
}
// System.Boolean System.Collections.Generic.List`1<UnityEngine.EventSystems.BaseRaycaster>::Contains(T)
inline bool List_1_Contains_m1F747311B8D41F5857768B1D6D5C51C43CA8BE4C (List_1_t02E640552264E3DEAE676267B620815D33BCD0DF* __this, BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* ___0_item, const RuntimeMethod* method)
{
	return ((  bool (*) (List_1_t02E640552264E3DEAE676267B620815D33BCD0DF*, BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832*, const RuntimeMethod*))List_1_Contains_m4C9139C2A6B23E9343D3F87807B32C6E2CFE660D_gshared)(__this, ___0_item, method);
}
// System.Void System.Collections.Generic.List`1<UnityEngine.EventSystems.BaseRaycaster>::Add(T)
inline void List_1_Add_m82AF5EAB1EA13F21CE5250B008E4EBCFEDAB6D53_inline (List_1_t02E640552264E3DEAE676267B620815D33BCD0DF* __this, BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t02E640552264E3DEAE676267B620815D33BCD0DF*, BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.Boolean System.Collections.Generic.List`1<UnityEngine.EventSystems.BaseRaycaster>::Remove(T)
inline bool List_1_Remove_m585A9E471D1C60EE46BA224A58947647F1E2B83B (List_1_t02E640552264E3DEAE676267B620815D33BCD0DF* __this, BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* ___0_item, const RuntimeMethod* method)
{
	return ((  bool (*) (List_1_t02E640552264E3DEAE676267B620815D33BCD0DF*, BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832*, const RuntimeMethod*))List_1_Remove_m4DFA48F4CEB9169601E75FC28517C5C06EFA5AD7_gshared)(__this, ___0_item, method);
}
// System.Void System.Collections.Generic.List`1<UnityEngine.EventSystems.BaseRaycaster>::.ctor()
inline void List_1__ctor_m53B48CB7A08406A33847E0C3D9D7511DE8FB0D41 (List_1_t02E640552264E3DEAE676267B620815D33BCD0DF* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_t02E640552264E3DEAE676267B620815D33BCD0DF*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
// T[] UnityEngine.Component::GetComponentsInParent<UnityEngine.EventSystems.BaseRaycaster>()
inline BaseRaycasterU5BU5D_tAE62D3FF1A5FF9DE20B2756DA4F4F8981925A799* Component_GetComponentsInParent_TisBaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832_mA869CA05E07609C8F435F1D779B138F3F2425F8C (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method)
{
	return ((  BaseRaycasterU5BU5D_tAE62D3FF1A5FF9DE20B2756DA4F4F8981925A799* (*) (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3*, const RuntimeMethod*))Component_GetComponentsInParent_TisRuntimeObject_m161F08219ECBE099E346F616990662F0117D4C8E_gshared)(__this, method);
}
// UnityEngine.GameObject UnityEngine.Component::get_gameObject()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;
// System.String System.Int32::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5 (int32_t* __this, const RuntimeMethod* method) ;
// System.String System.String::Concat(System.String[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m647EBF831F54B6DF7D5AFA5FD012CF4EE7571B6A (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___0_values, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.UIBehaviour::OnEnable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIBehaviour_OnEnable_m8989ABF5C038905A68E5536BED2E6FFAF8767FFC (UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.RaycasterManager::AddRaycaster(UnityEngine.EventSystems.BaseRaycaster)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RaycasterManager_AddRaycaster_mD2EE52F55FBDB3BEAAF583C4445D4D16B09B6350 (BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* ___0_baseRaycaster, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.RaycasterManager::RemoveRaycasters(UnityEngine.EventSystems.BaseRaycaster)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RaycasterManager_RemoveRaycasters_m0800E0ACE007AD43B62D10C1029EC85E7DE28999 (BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* ___0_baseRaycaster, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.UIBehaviour::OnDisable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIBehaviour_OnDisable_m18D5A0B93F65FB50F4D6CE8197EC07F3452C5DDE (UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.UIBehaviour::OnCanvasHierarchyChanged()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIBehaviour_OnCanvasHierarchyChanged_mCAC018CB33FA00E857288B64E3722226638A1229 (UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.UIBehaviour::OnTransformParentChanged()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIBehaviour_OnTransformParentChanged_mAD56D3C6049A1746F00DC2643D1666F7DE921384 (UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.UIBehaviour::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIBehaviour__ctor_m24C66A65DDD996E779871C6655CF11B871F11337 (UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.PhysicsRaycaster::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PhysicsRaycaster__ctor_mB7D4BAC26DC219A10060B35498EE9D5F05AD0E80 (PhysicsRaycaster_t0ACA9046D8D0B195B59DB1F7CA4DD6BB634A56DD* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.EventSystems.PhysicsRaycaster::ComputeRayAndDistance(UnityEngine.EventSystems.PointerEventData,UnityEngine.Ray&,System.Int32&,System.Single&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool PhysicsRaycaster_ComputeRayAndDistance_mCFEFA9D83EC1E63393454E383FFFEF89E14C173B (PhysicsRaycaster_t0ACA9046D8D0B195B59DB1F7CA4DD6BB634A56DD* __this, PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* ___0_eventData, Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00* ___1_ray, int32_t* ___2_eventDisplayIndex, float* ___3_distanceToClipPlane, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.EventSystems.PhysicsRaycaster::get_maxRayIntersections()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t PhysicsRaycaster_get_maxRayIntersections_mA06D0B5E291BCF94AE1EF4ED7B68890F39395911 (PhysicsRaycaster_t0ACA9046D8D0B195B59DB1F7CA4DD6BB634A56DD* __this, const RuntimeMethod* method) ;
// UnityEngine.UI.ReflectionMethodsCache UnityEngine.UI.ReflectionMethodsCache::get_Singleton()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReflectionMethodsCache_t711B47CE11EA2092B94127FF8D3361AE2E4859F5* ReflectionMethodsCache_get_Singleton_m77EFD7AC0043333E09987BD601113B810453C42B (const RuntimeMethod* method) ;
// System.Int32 UnityEngine.EventSystems.PhysicsRaycaster::get_finalEventMask()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t PhysicsRaycaster_get_finalEventMask_m20AD2327FE81B38A5853B23970A587EAA2ECCB1B (PhysicsRaycaster_t0ACA9046D8D0B195B59DB1F7CA4DD6BB634A56DD* __this, const RuntimeMethod* method) ;
// UnityEngine.RaycastHit2D[] UnityEngine.UI.ReflectionMethodsCache/GetRayIntersectionAllCallback::Invoke(UnityEngine.Ray,System.Single,System.Int32)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7* GetRayIntersectionAllCallback_Invoke_m917AA4108EBDC724AFEF39BFD06A586B7461F497_inline (GetRayIntersectionAllCallback_t52E7AE4ECEA3F9744FF7F8448F852C872A70315C* __this, Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 ___0_r, float ___1_f, int32_t ___2_i, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.UI.ReflectionMethodsCache/GetRayIntersectionAllNonAllocCallback::Invoke(UnityEngine.Ray,UnityEngine.RaycastHit2D[],System.Single,System.Int32)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t GetRayIntersectionAllNonAllocCallback_Invoke_mFAA36E9AF362DC72204EEF53B28DBFC3367D09A7_inline (GetRayIntersectionAllNonAllocCallback_t28D7ACEBBE525DE0CBEA67986E4C3891D694F980* __this, Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 ___0_r, RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7* ___1_results, float ___2_f, int32_t ___3_i, const RuntimeMethod* method) ;
// UnityEngine.Collider2D UnityEngine.RaycastHit2D::get_collider()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Collider2D_t6A17BA7734600EF3F26588E9ED903617D5B8EB52* RaycastHit2D_get_collider_mB56DFCD16B708852EEBDBB490BC8665DBF7487FD (RaycastHit2D_t3EAAA06E6603C6BC61AC1291DD881C5C1E23BDFA* __this, const RuntimeMethod* method) ;
// T UnityEngine.GameObject::GetComponent<UnityEngine.Renderer>()
inline Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* GameObject_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_m026EB44DB6238F13E2AFBECF1FBBE924CB1B040A (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method)
{
	return ((  Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, const RuntimeMethod*))GameObject_GetComponent_TisRuntimeObject_m6EAED4AA356F0F48288F67899E5958792395563B_gshared)(__this, method);
}
// System.Void UnityEngine.EventSystems.RaycastResult::set_gameObject(UnityEngine.GameObject)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RaycastResult_set_gameObject_mCFEB66C0E3F01AC5E55040FE8BEB16E40427BD9E (RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_value, const RuntimeMethod* method) ;
// UnityEngine.Transform UnityEngine.Component::get_transform()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371 (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Transform::get_position()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1 (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, const RuntimeMethod* method) ;
// UnityEngine.Vector2 UnityEngine.RaycastHit2D::get_point()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 RaycastHit2D_get_point_mB35E988E9E04328EFE926228A18334326721A36B (RaycastHit2D_t3EAAA06E6603C6BC61AC1291DD881C5C1E23BDFA* __this, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Vector2::op_Implicit(UnityEngine.Vector2)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector2_op_Implicit_m6D9CABB2C791A192867D7A4559D132BE86DD3EB7_inline (Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___0_v, const RuntimeMethod* method) ;
// System.Single UnityEngine.Vector3::Distance(UnityEngine.Vector3,UnityEngine.Vector3)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Vector3_Distance_m2314DB9B8BD01157E013DF87BEA557375C7F9FF9_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_a, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___1_b, const RuntimeMethod* method) ;
// UnityEngine.Vector2 UnityEngine.RaycastHit2D::get_normal()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 RaycastHit2D_get_normal_m75F1EBDE347BACEB5A6A6AA72543C740806AB5F2 (RaycastHit2D_t3EAAA06E6603C6BC61AC1291DD881C5C1E23BDFA* __this, const RuntimeMethod* method) ;
// System.Int32 System.Collections.Generic.List`1<UnityEngine.EventSystems.RaycastResult>::get_Count()
inline int32_t List_1_get_Count_mE2EBEDC861C1EC398EDBE6CF2C9FB604AA71523E_inline (List_1_t8292C421BBB00D7661DC07462822936152BAB446* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t8292C421BBB00D7661DC07462822936152BAB446*, const RuntimeMethod*))List_1_get_Count_mE2EBEDC861C1EC398EDBE6CF2C9FB604AA71523E_gshared_inline)(__this, method);
}
// System.Int32 UnityEngine.Rendering.SortingGroup::get_invalidSortingGroupID()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SortingGroup_get_invalidSortingGroupID_mEA453186185B225FA2410988959180BAEC604310 (const RuntimeMethod* method) ;
// System.Int32 UnityEngine.Renderer::get_sortingGroupID()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Renderer_get_sortingGroupID_m1DEFE39027236FF31AB603993BBC13C072E52118 (Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* __this, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.Renderer::get_sortingGroupOrder()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Renderer_get_sortingGroupOrder_m40F058B3AFC92CCEF2475E0BD9A96464154E999E (Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* __this, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.Renderer::get_sortingLayerID()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Renderer_get_sortingLayerID_m3D7AE74F1B87099810CF969CB4520C85F9AE5F92 (Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* __this, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.Renderer::get_sortingOrder()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Renderer_get_sortingOrder_m4CE7ADEEC8E2F28CC1D10B1D4091A10F8F1583FA (Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* __this, const RuntimeMethod* method) ;
// UnityEngine.Rendering.SortingGroup UnityEngine.Rendering.SortingGroup::GetSortingGroupByIndex(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SortingGroup_tA8DA95BF22F76688DAF54122EB3EEA35C70E9759* SortingGroup_GetSortingGroupByIndex_mC4CFB06D8C4B0EA27FC4BDC60AA05F4E0B28426B (int32_t ___0_index, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Ray::get_direction()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Ray_get_direction_m21C2D22D3BD4A683BD4DC191AB22DD05F5EC2086 (Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00* __this, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Ray::get_origin()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Ray_get_origin_m97604A8F180316A410DCD77B7D74D04522FA1BA6 (Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00* __this, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Vector3::op_Subtraction(UnityEngine.Vector3,UnityEngine.Vector3)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_op_Subtraction_mE42023FF80067CB44A1D4A27EB7CF2B24CABB828_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_a, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___1_b, const RuntimeMethod* method) ;
// System.Single UnityEngine.Vector3::Dot(UnityEngine.Vector3,UnityEngine.Vector3)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Vector3_Dot_mBB86BB940AA0A32FA7D3C02AC42E5BC7095A5D52_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_lhs, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___1_rhs, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.Rendering.SortingGroup::get_sortingLayerID()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SortingGroup_get_sortingLayerID_m37C70CEA78DA6E28F405C67EDE95D5C2191F0055 (SortingGroup_tA8DA95BF22F76688DAF54122EB3EEA35C70E9759* __this, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.Rendering.SortingGroup::get_sortingOrder()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SortingGroup_get_sortingOrder_mC80606E6BB9A6D5E3AB61A0451C48203A0C1AB6A (SortingGroup_tA8DA95BF22F76688DAF54122EB3EEA35C70E9759* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<UnityEngine.EventSystems.RaycastResult>::Add(T)
inline void List_1_Add_mEB6DFEA132B5B7BF540D34177054003185D250E7_inline (List_1_t8292C421BBB00D7661DC07462822936152BAB446* __this, RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t8292C421BBB00D7661DC07462822936152BAB446*, RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023, const RuntimeMethod*))List_1_Add_mEB6DFEA132B5B7BF540D34177054003185D250E7_gshared_inline)(__this, ___0_item, method);
}
// UnityEngine.LayerMask UnityEngine.LayerMask::op_Implicit(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR LayerMask_t97CB6BDADEDC3D6423C7BCFEA7F86DA2EC6241DB LayerMask_op_Implicit_m01C8996A2CB2085328B9C33539C43139660D8222 (int32_t ___0_intVal, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.BaseRaycaster::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseRaycaster__ctor_m1B6A963368E54C1E450BE15FAF1AE082142A1683 (BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* __this, const RuntimeMethod* method) ;
// T UnityEngine.Component::GetComponent<UnityEngine.Camera>()
inline Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* Component_GetComponent_TisCamera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184_m64AC6C06DD93C5FB249091FEC84FA8475457CCC4 (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method)
{
	return ((  Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* (*) (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3*, const RuntimeMethod*))Component_GetComponent_TisRuntimeObject_m7181F81CAEC2CF53F5D2BC79B7425C16E1F80D33_gshared)(__this, method);
}
// UnityEngine.Camera UnityEngine.Camera::get_main()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* Camera_get_main_m52C992F18E05355ABB9EEB64A4BF2215E12762DF (const RuntimeMethod* method) ;
// System.Single UnityEngine.Camera::get_depth()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Camera_get_depth_mDF67FFF8ED61750467DFC4C6D8F236850AD1BB1D (Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* __this, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.Camera::get_cullingMask()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Camera_get_cullingMask_m6F5AFF8FB522F876D99E839BF77D8F27F26A1EF8 (Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* __this, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.LayerMask::op_Implicit(UnityEngine.LayerMask)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t LayerMask_op_Implicit_m7F5A5B9D079281AC445ED39DEE1FCFA9D795810D (LayerMask_t97CB6BDADEDC3D6423C7BCFEA7F86DA2EC6241DB ___0_mask, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.UI.MultipleDisplayUtilities::RelativeMouseAtScaled(UnityEngine.Vector2)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 MultipleDisplayUtilities_RelativeMouseAtScaled_mE3B0EE3E697B4316CE8588D05F3A75E47A75A855 (Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___0_position, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Vector3::get_zero()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_get_zero_m0C1249C3F25B1C70EAD3CC8B31259975A457AE39_inline (const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Vector3::op_Inequality(UnityEngine.Vector3,UnityEngine.Vector3)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector3_op_Inequality_m9F170CDFBF1E490E559DA5D06D6547501A402BBF_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_lhs, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___1_rhs, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.Camera::get_targetDisplay()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Camera_get_targetDisplay_m204A169C94EEABDB491FA5A77CC684146B10DF80 (Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* __this, const RuntimeMethod* method) ;
// UnityEngine.Rect UnityEngine.Camera::get_pixelRect()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D Camera_get_pixelRect_m5F40F5C324EB252261F66962411EE08CC4BE39E7 (Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Rect::Contains(UnityEngine.Vector3)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Rect_Contains_mB1160CD465F3E9616AA4EED72AFFD611BD8D2B6B (Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_point, const RuntimeMethod* method) ;
// UnityEngine.Ray UnityEngine.Camera::ScreenPointToRay(UnityEngine.Vector3)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 Camera_ScreenPointToRay_m2887B9A49880B7AB670C57D66B67D6A6689FE315 (Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_pos, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Mathf::Approximately(System.Single,System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Mathf_Approximately_m1DADD012A8FC82E11FB282501AE2EBBF9A77150B_inline (float ___0_a, float ___1_b, const RuntimeMethod* method) ;
// System.Single UnityEngine.Camera::get_farClipPlane()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Camera_get_farClipPlane_m1D7128B85B5DB866F75FBE8CEBA48335716B67BD (Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* __this, const RuntimeMethod* method) ;
// System.Single UnityEngine.Camera::get_nearClipPlane()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Camera_get_nearClipPlane_m5E8FAF84326E3192CB036BD29DCCDAF6A9861013 (Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* __this, const RuntimeMethod* method) ;
// UnityEngine.RaycastHit[] UnityEngine.UI.ReflectionMethodsCache/RaycastAllCallback::Invoke(UnityEngine.Ray,System.Single,System.Int32)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8* RaycastAllCallback_Invoke_mB30319766AF5F0D5145A6C0AFFEA829A31A5D4B7_inline (RaycastAllCallback_t4AFFDCDAA6F02DD74E1E2DE455BA011D82BED47A* __this, Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 ___0_r, float ___1_f, int32_t ___2_i, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.UI.ReflectionMethodsCache/GetRaycastNonAllocCallback::Invoke(UnityEngine.Ray,UnityEngine.RaycastHit[],System.Single,System.Int32)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t GetRaycastNonAllocCallback_Invoke_m36411365E9622819DAB93D0BB0F169FEE99F07D9_inline (GetRaycastNonAllocCallback_tC3DA6EE6063FE663DD0A9FC52439D825DE4A1FFC* __this, Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 ___0_r, RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8* ___1_results, float ___2_f, int32_t ___3_i, const RuntimeMethod* method) ;
// System.Void System.Array::Sort<UnityEngine.RaycastHit>(T[],System.Int32,System.Int32,System.Collections.Generic.IComparer`1<T>)
inline void Array_Sort_TisRaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5_mBF83A49E9B1F007DD08F7E076AF45D2AED7A45EB (RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method)
{
	((  void (*) (RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8*, int32_t, int32_t, RuntimeObject*, const RuntimeMethod*))Array_Sort_TisRaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5_mBF83A49E9B1F007DD08F7E076AF45D2AED7A45EB_gshared)(___0_array, ___1_index, ___2_length, ___3_comparer, method);
}
// UnityEngine.Collider UnityEngine.RaycastHit::get_collider()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Collider_t1CC3163924FCD6C4CC2E816373A929C1E3D55E76* RaycastHit_get_collider_m84B160439BBEAB6D9E94B799F720E25C9E2D444D (RaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5* __this, const RuntimeMethod* method) ;
// System.Single UnityEngine.RaycastHit::get_distance()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float RaycastHit_get_distance_m035194B0E9BB6229259CFC43B095A9C8E5011C78 (RaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5* __this, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.RaycastHit::get_point()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 RaycastHit_get_point_m02B764612562AFE0F998CC7CFB2EEDE41BA47F39 (RaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5* __this, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.RaycastHit::get_normal()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 RaycastHit_get_normal_mD8741B70D2039C5CAFC4368D4CE59D89562040B5 (RaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5* __this, const RuntimeMethod* method) ;
// System.Int32 System.Single::CompareTo(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Single_CompareTo_m06F7868162EB392D3E99103D1A0BD27463C9E66F (float* __this, float ___0_value, const RuntimeMethod* method) ;
// System.Void System.Object::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.PhysicsRaycaster/RaycastHitComparer::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RaycastHitComparer__ctor_mAB0536EE515BF2BD1B29BE3B39E8BA9E9CFE97C3 (RaycastHitComparer_t8EF6567C19BE9FB575E01A10941FBF7DE3D3DDF1* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.EventSystems.RaycastResult::get_isValid()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RaycastResult_get_isValid_m69957B97C041A9E3FAF4ECA82BB8099C9FA171CE (RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* __this, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Vector3::get_up()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_get_up_m128AF3FDC820BF59D5DE86D973E7DE3F20C3AEBA_inline (const RuntimeMethod* method) ;
// UnityEngine.Vector2 UnityEngine.Vector2::op_Implicit(UnityEngine.Vector3)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 Vector2_op_Implicit_mE8EBEE9291F11BB02F062D6E000F4798968CBD96_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_v, const RuntimeMethod* method) ;
// System.Void UnityEngine.EventSystems.RaycastResult::Clear()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RaycastResult_Clear_m0E9DA70AC69CF143CEA8428AFC5BA552F99643AE (RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* __this, const RuntimeMethod* method) ;
// System.String System.Single::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Single_ToString_mE282EDA9CA4F7DF88432D807732837A629D04972 (float* __this, const RuntimeMethod* method) ;
// System.String UnityEngine.Vector3::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector3_ToString_m6C24B9F0382D25D75B05C606E127CD14660574EE (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* __this, const RuntimeMethod* method) ;
// System.String UnityEngine.Vector2::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector2_ToString_mB47B29ECB21FA3A4ACEABEFA18077A5A6BBCCB27 (Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7* __this, const RuntimeMethod* method) ;
// System.String UnityEngine.EventSystems.RaycastResult::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* RaycastResult_ToString_m0267000494B09783ABD507B9329ADB01FBBC5428 (RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Behaviour::get_isActiveAndEnabled()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Behaviour_get_isActiveAndEnabled_mEB4ECCE9761A7016BC619557CEFEA1A30D3BF28A (Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.MonoBehaviour::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.Vector2::.ctor(System.Single,System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Vector2__ctor_m9525B79969AFFE3254B303A40997A56DEEB6F548_inline (Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7* __this, float ___0_x, float ___1_y, const RuntimeMethod* method) ;
// System.Void UnityEngine.Vector3::.ctor(System.Single,System.Single,System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* __this, float ___0_x, float ___1_y, float ___2_z, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Vector3::op_Equality(UnityEngine.Vector3,UnityEngine.Vector3)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector3_op_Equality_mCDCBB8D2EDC3D3BF20F31A25ACB34705D352B479_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_lhs, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___1_rhs, const RuntimeMethod* method) ;
// System.Single UnityEngine.Mathf::Max(System.Single,System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Mathf_Max_mF5379E63D2BBAC76D090748695D833934F8AD051_inline (float ___0_a, float ___1_b, const RuntimeMethod* method) ;
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
// System.Void UnityEngine.EventSystems.TouchInputModule::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TouchInputModule__ctor_mCBE23B5A3A8CE1CD042A061D7E070B04A45E3075 (TouchInputModule_t154B7CF685F02D5B9529572B1A96EBD75AAA945C* __this, const RuntimeMethod* method) 
{
	{
		// protected TouchInputModule()
		PointerInputModule__ctor_mBF074492478BFC24F87EF2C941D6C11A8ACDAF11(__this, NULL);
		// {}
		return;
	}
}
// System.Boolean UnityEngine.EventSystems.TouchInputModule::get_allowActivationOnStandalone()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool TouchInputModule_get_allowActivationOnStandalone_m2F9A65E10F7BE98D250CC3D6C9CABA3BCCE95995 (TouchInputModule_t154B7CF685F02D5B9529572B1A96EBD75AAA945C* __this, const RuntimeMethod* method) 
{
	bool V_0 = false;
	{
		// get { return m_ForceModuleActive; }
		bool L_0 = __this->___m_ForceModuleActive_20;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		// get { return m_ForceModuleActive; }
		bool L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.EventSystems.TouchInputModule::set_allowActivationOnStandalone(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TouchInputModule_set_allowActivationOnStandalone_m5AB9798D9B6071B37FC67E0D1A81A58A0A59D7AD (TouchInputModule_t154B7CF685F02D5B9529572B1A96EBD75AAA945C* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		// set { m_ForceModuleActive = value; }
		bool L_0 = ___0_value;
		__this->___m_ForceModuleActive_20 = L_0;
		// set { m_ForceModuleActive = value; }
		return;
	}
}
// System.Boolean UnityEngine.EventSystems.TouchInputModule::get_forceModuleActive()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool TouchInputModule_get_forceModuleActive_m7200F7B6C80EDD69987615B8356B6B2497461FCA (TouchInputModule_t154B7CF685F02D5B9529572B1A96EBD75AAA945C* __this, const RuntimeMethod* method) 
{
	bool V_0 = false;
	{
		// get { return m_ForceModuleActive; }
		bool L_0 = __this->___m_ForceModuleActive_20;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		// get { return m_ForceModuleActive; }
		bool L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.EventSystems.TouchInputModule::set_forceModuleActive(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TouchInputModule_set_forceModuleActive_m32676A04010774CA55055EE93A05ED6C6388D2C2 (TouchInputModule_t154B7CF685F02D5B9529572B1A96EBD75AAA945C* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		// set { m_ForceModuleActive = value; }
		bool L_0 = ___0_value;
		__this->___m_ForceModuleActive_20 = L_0;
		// set { m_ForceModuleActive = value; }
		return;
	}
}
// System.Void UnityEngine.EventSystems.TouchInputModule::UpdateModule()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TouchInputModule_UpdateModule_mE6F4F74D770ACFEF3C46611C71CBE705342EA608 (TouchInputModule_t154B7CF685F02D5B9529572B1A96EBD75AAA945C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ExecuteEvents_Execute_TisIEndDragHandler_t9A93E4A27E7CEED446E5FE3DACF39B1A552C23A9_m6AA443D4F53AF0FEBAC269F761A158635243467E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ExecuteEvents_t74DCF8B83743EE2773ACF182344612A048E2CC59_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	int32_t G_B5_0 = 0;
	{
		// if (!eventSystem.isFocused)
		EventSystem_t61C51380B105BE9D2C39C4F15B7E655659957707* L_0;
		L_0 = BaseInputModule_get_eventSystem_m341B2378F61A58D5432906B9EE1E12265E2FAB33(__this, NULL);
		NullCheck(L_0);
		bool L_1;
		L_1 = EventSystem_get_isFocused_mB0BB5BE03F7203A06D2F351ACD28BA177079104A(L_0, NULL);
		V_0 = (bool)((((int32_t)L_1) == ((int32_t)0))? 1 : 0);
		bool L_2 = V_0;
		if (!L_2)
		{
			goto IL_0065;
		}
	}
	{
		// if (m_InputPointerEvent != null && m_InputPointerEvent.pointerDrag != null && m_InputPointerEvent.dragging)
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_3 = __this->___m_InputPointerEvent_19;
		if (!L_3)
		{
			goto IL_003c;
		}
	}
	{
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_4 = __this->___m_InputPointerEvent_19;
		NullCheck(L_4);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_5;
		L_5 = PointerEventData_get_pointerDrag_m36BF08A32216845A8095C5F74DFE6C9959A11E96_inline(L_4, NULL);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_6;
		L_6 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_5, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_6)
		{
			goto IL_003c;
		}
	}
	{
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_7 = __this->___m_InputPointerEvent_19;
		NullCheck(L_7);
		bool L_8;
		L_8 = PointerEventData_get_dragging_mE0AD837F228E3830D4A74657AD3D47F53F6C87E9_inline(L_7, NULL);
		G_B5_0 = ((int32_t)(L_8));
		goto IL_003d;
	}

IL_003c:
	{
		G_B5_0 = 0;
	}

IL_003d:
	{
		V_1 = (bool)G_B5_0;
		bool L_9 = V_1;
		if (!L_9)
		{
			goto IL_005d;
		}
	}
	{
		// ExecuteEvents.Execute(m_InputPointerEvent.pointerDrag, m_InputPointerEvent, ExecuteEvents.endDragHandler);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_10 = __this->___m_InputPointerEvent_19;
		NullCheck(L_10);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_11;
		L_11 = PointerEventData_get_pointerDrag_m36BF08A32216845A8095C5F74DFE6C9959A11E96_inline(L_10, NULL);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_12 = __this->___m_InputPointerEvent_19;
		il2cpp_codegen_runtime_class_init_inline(ExecuteEvents_t74DCF8B83743EE2773ACF182344612A048E2CC59_il2cpp_TypeInfo_var);
		EventFunction_1_t33BA7CA3F9202146F70BE77589CE24F7451C584C* L_13;
		L_13 = ExecuteEvents_get_endDragHandler_mE78FEEEAE114635E416FF1FE33C851E62B60555B(NULL);
		bool L_14;
		L_14 = ExecuteEvents_Execute_TisIEndDragHandler_t9A93E4A27E7CEED446E5FE3DACF39B1A552C23A9_m6AA443D4F53AF0FEBAC269F761A158635243467E(L_11, L_12, L_13, ExecuteEvents_Execute_TisIEndDragHandler_t9A93E4A27E7CEED446E5FE3DACF39B1A552C23A9_m6AA443D4F53AF0FEBAC269F761A158635243467E_RuntimeMethod_var);
	}

IL_005d:
	{
		// m_InputPointerEvent = null;
		__this->___m_InputPointerEvent_19 = (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_InputPointerEvent_19), (void*)(PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB*)NULL);
	}

IL_0065:
	{
		// m_LastMousePosition = m_MousePosition;
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_15 = __this->___m_MousePosition_18;
		__this->___m_LastMousePosition_17 = L_15;
		// m_MousePosition = input.mousePosition;
		BaseInput_t69C46B0AA3C24F1CA842A0D03CACACC4EC788622* L_16;
		L_16 = BaseInputModule_get_input_mCB3F78528AA14A7AD7E957870DBB0152B4BF13FB(__this, NULL);
		NullCheck(L_16);
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_17;
		L_17 = VirtualFuncInvoker0< Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 >::Invoke(26 /* UnityEngine.Vector2 UnityEngine.EventSystems.BaseInput::get_mousePosition() */, L_16);
		__this->___m_MousePosition_18 = L_17;
		// }
		return;
	}
}
// System.Boolean UnityEngine.EventSystems.TouchInputModule::IsModuleSupported()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool TouchInputModule_IsModuleSupported_m795B5298EC90DC063A96147CF3B3287EC27C9799 (TouchInputModule_t154B7CF685F02D5B9529572B1A96EBD75AAA945C* __this, const RuntimeMethod* method) 
{
	bool V_0 = false;
	int32_t G_B3_0 = 0;
	{
		// return forceModuleActive || input.touchSupported;
		bool L_0;
		L_0 = TouchInputModule_get_forceModuleActive_m7200F7B6C80EDD69987615B8356B6B2497461FCA(__this, NULL);
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		BaseInput_t69C46B0AA3C24F1CA842A0D03CACACC4EC788622* L_1;
		L_1 = BaseInputModule_get_input_mCB3F78528AA14A7AD7E957870DBB0152B4BF13FB(__this, NULL);
		NullCheck(L_1);
		bool L_2;
		L_2 = VirtualFuncInvoker0< bool >::Invoke(28 /* System.Boolean UnityEngine.EventSystems.BaseInput::get_touchSupported() */, L_1);
		G_B3_0 = ((int32_t)(L_2));
		goto IL_0017;
	}

IL_0016:
	{
		G_B3_0 = 1;
	}

IL_0017:
	{
		V_0 = (bool)G_B3_0;
		goto IL_001a;
	}

IL_001a:
	{
		// }
		bool L_3 = V_0;
		return L_3;
	}
}
// System.Boolean UnityEngine.EventSystems.TouchInputModule::ShouldActivateModule()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool TouchInputModule_ShouldActivateModule_m4B17231DE579430D27088D6592378FB7547ADBDC (TouchInputModule_t154B7CF685F02D5B9529572B1A96EBD75AAA945C* __this, const RuntimeMethod* method) 
{
	bool V_0 = false;
	bool V_1 = false;
	bool V_2 = false;
	bool V_3 = false;
	bool V_4 = false;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 V_5;
	memset((&V_5), 0, sizeof(V_5));
	{
		// if (!base.ShouldActivateModule())
		bool L_0;
		L_0 = BaseInputModule_ShouldActivateModule_m51B70F9097EF7FEB20B62D4D775F7FEA853185A1(__this, NULL);
		V_0 = (bool)((((int32_t)L_0) == ((int32_t)0))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0012;
		}
	}
	{
		// return false;
		V_1 = (bool)0;
		goto IL_0075;
	}

IL_0012:
	{
		// if (m_ForceModuleActive)
		bool L_2 = __this->___m_ForceModuleActive_20;
		V_2 = L_2;
		bool L_3 = V_2;
		if (!L_3)
		{
			goto IL_0020;
		}
	}
	{
		// return true;
		V_1 = (bool)1;
		goto IL_0075;
	}

IL_0020:
	{
		// if (UseFakeInput())
		bool L_4;
		L_4 = TouchInputModule_UseFakeInput_m66A84384ADA044187F239B1CFC143C42E5E56774(__this, NULL);
		V_3 = L_4;
		bool L_5 = V_3;
		if (!L_5)
		{
			goto IL_0064;
		}
	}
	{
		// bool wantsEnable = input.GetMouseButtonDown(0);
		BaseInput_t69C46B0AA3C24F1CA842A0D03CACACC4EC788622* L_6;
		L_6 = BaseInputModule_get_input_mCB3F78528AA14A7AD7E957870DBB0152B4BF13FB(__this, NULL);
		NullCheck(L_6);
		bool L_7;
		L_7 = VirtualFuncInvoker1< bool, int32_t >::Invoke(23 /* System.Boolean UnityEngine.EventSystems.BaseInput::GetMouseButtonDown(System.Int32) */, L_6, 0);
		V_4 = L_7;
		// wantsEnable |= (m_MousePosition - m_LastMousePosition).sqrMagnitude > 0.0f;
		bool L_8 = V_4;
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_9 = __this->___m_MousePosition_18;
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_10 = __this->___m_LastMousePosition_17;
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_11;
		L_11 = Vector2_op_Subtraction_m44475FCDAD2DA2F98D78A6625EC2DCDFE8803837_inline(L_9, L_10, NULL);
		V_5 = L_11;
		float L_12;
		L_12 = Vector2_get_sqrMagnitude_mA16336720C14EEF8BA9B55AE33B98C9EE2082BDC_inline((&V_5), NULL);
		V_4 = (bool)((int32_t)((int32_t)L_8|((((float)L_12) > ((float)(0.0f)))? 1 : 0)));
		// return wantsEnable;
		bool L_13 = V_4;
		V_1 = L_13;
		goto IL_0075;
	}

IL_0064:
	{
		// return input.touchCount > 0;
		BaseInput_t69C46B0AA3C24F1CA842A0D03CACACC4EC788622* L_14;
		L_14 = BaseInputModule_get_input_mCB3F78528AA14A7AD7E957870DBB0152B4BF13FB(__this, NULL);
		NullCheck(L_14);
		int32_t L_15;
		L_15 = VirtualFuncInvoker0< int32_t >::Invoke(29 /* System.Int32 UnityEngine.EventSystems.BaseInput::get_touchCount() */, L_14);
		V_1 = (bool)((((int32_t)L_15) > ((int32_t)0))? 1 : 0);
		goto IL_0075;
	}

IL_0075:
	{
		// }
		bool L_16 = V_1;
		return L_16;
	}
}
// System.Boolean UnityEngine.EventSystems.TouchInputModule::UseFakeInput()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool TouchInputModule_UseFakeInput_m66A84384ADA044187F239B1CFC143C42E5E56774 (TouchInputModule_t154B7CF685F02D5B9529572B1A96EBD75AAA945C* __this, const RuntimeMethod* method) 
{
	bool V_0 = false;
	{
		// return !input.touchSupported;
		BaseInput_t69C46B0AA3C24F1CA842A0D03CACACC4EC788622* L_0;
		L_0 = BaseInputModule_get_input_mCB3F78528AA14A7AD7E957870DBB0152B4BF13FB(__this, NULL);
		NullCheck(L_0);
		bool L_1;
		L_1 = VirtualFuncInvoker0< bool >::Invoke(28 /* System.Boolean UnityEngine.EventSystems.BaseInput::get_touchSupported() */, L_0);
		V_0 = (bool)((((int32_t)L_1) == ((int32_t)0))? 1 : 0);
		goto IL_0012;
	}

IL_0012:
	{
		// }
		bool L_2 = V_0;
		return L_2;
	}
}
// System.Void UnityEngine.EventSystems.TouchInputModule::Process()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TouchInputModule_Process_m3C0CB50AB7D9E92B519787F7742AE0976FB36841 (TouchInputModule_t154B7CF685F02D5B9529572B1A96EBD75AAA945C* __this, const RuntimeMethod* method) 
{
	bool V_0 = false;
	{
		// if (UseFakeInput())
		bool L_0;
		L_0 = TouchInputModule_UseFakeInput_m66A84384ADA044187F239B1CFC143C42E5E56774(__this, NULL);
		V_0 = L_0;
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0014;
		}
	}
	{
		// FakeTouches();
		TouchInputModule_FakeTouches_m264BF2C70234CD04B0162FE4CED673B1A77A84F9(__this, NULL);
		goto IL_001b;
	}

IL_0014:
	{
		// ProcessTouchEvents();
		TouchInputModule_ProcessTouchEvents_mBB28D85996F6280141E39A462BC35EF01373E514(__this, NULL);
	}

IL_001b:
	{
		// }
		return;
	}
}
// System.Void UnityEngine.EventSystems.TouchInputModule::FakeTouches()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TouchInputModule_FakeTouches_m264BF2C70234CD04B0162FE4CED673B1A77A84F9 (TouchInputModule_t154B7CF685F02D5B9529572B1A96EBD75AAA945C* __this, const RuntimeMethod* method) 
{
	MouseState_tCCE70861DE1EEECF949AFE8E2A922541D4E08A09* V_0 = NULL;
	MouseButtonEventData_t0761D63D3A2B13090597C22DD97597CC7FE4D154* V_1 = NULL;
	bool V_2 = false;
	bool V_3 = false;
	{
		// var pointerData = GetMousePointerEventData(0);
		MouseState_tCCE70861DE1EEECF949AFE8E2A922541D4E08A09* L_0;
		L_0 = VirtualFuncInvoker1< MouseState_tCCE70861DE1EEECF949AFE8E2A922541D4E08A09*, int32_t >::Invoke(28 /* UnityEngine.EventSystems.PointerInputModule/MouseState UnityEngine.EventSystems.PointerInputModule::GetMousePointerEventData(System.Int32) */, __this, 0);
		V_0 = L_0;
		// var leftPressData = pointerData.GetButtonState(PointerEventData.InputButton.Left).eventData;
		MouseState_tCCE70861DE1EEECF949AFE8E2A922541D4E08A09* L_1 = V_0;
		NullCheck(L_1);
		ButtonState_tB671FC9C48F167DBC1CDAFEB53C373D8567AE503* L_2;
		L_2 = MouseState_GetButtonState_mD25E7D214B0499DBBE3B3E532CD7085C1A021E51(L_1, 0, NULL);
		NullCheck(L_2);
		MouseButtonEventData_t0761D63D3A2B13090597C22DD97597CC7FE4D154* L_3;
		L_3 = ButtonState_get_eventData_m4767730784143F1DCE06B6138658A31CBC5E155F(L_2, NULL);
		V_1 = L_3;
		// if (leftPressData.PressedThisFrame())
		MouseButtonEventData_t0761D63D3A2B13090597C22DD97597CC7FE4D154* L_4 = V_1;
		NullCheck(L_4);
		bool L_5;
		L_5 = MouseButtonEventData_PressedThisFrame_mEE5DC95537AAEB346C57DCA85917E0701A44388D(L_4, NULL);
		V_2 = L_5;
		bool L_6 = V_2;
		if (!L_6)
		{
			goto IL_0031;
		}
	}
	{
		// leftPressData.buttonData.delta = Vector2.zero;
		MouseButtonEventData_t0761D63D3A2B13090597C22DD97597CC7FE4D154* L_7 = V_1;
		NullCheck(L_7);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_8 = L_7->___buttonData_1;
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_9;
		L_9 = Vector2_get_zero_m32506C40EC2EE7D5D4410BF40D3EE683A3D5F32C_inline(NULL);
		NullCheck(L_8);
		PointerEventData_set_delta_mD200AF7CCAEAD92D947091902AF864CB4ACE0F1D_inline(L_8, L_9, NULL);
	}

IL_0031:
	{
		// ProcessTouchPress(leftPressData.buttonData, leftPressData.PressedThisFrame(), leftPressData.ReleasedThisFrame());
		MouseButtonEventData_t0761D63D3A2B13090597C22DD97597CC7FE4D154* L_10 = V_1;
		NullCheck(L_10);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_11 = L_10->___buttonData_1;
		MouseButtonEventData_t0761D63D3A2B13090597C22DD97597CC7FE4D154* L_12 = V_1;
		NullCheck(L_12);
		bool L_13;
		L_13 = MouseButtonEventData_PressedThisFrame_mEE5DC95537AAEB346C57DCA85917E0701A44388D(L_12, NULL);
		MouseButtonEventData_t0761D63D3A2B13090597C22DD97597CC7FE4D154* L_14 = V_1;
		NullCheck(L_14);
		bool L_15;
		L_15 = MouseButtonEventData_ReleasedThisFrame_m5AD4F06D1CA6E0ACD6E84EEFAD4FB112098AFD51(L_14, NULL);
		TouchInputModule_ProcessTouchPress_m1DC51E52E6B419F02626EB567A60411A0FCFA517(__this, L_11, L_13, L_15, NULL);
		// if (input.GetMouseButton(0))
		BaseInput_t69C46B0AA3C24F1CA842A0D03CACACC4EC788622* L_16;
		L_16 = BaseInputModule_get_input_mCB3F78528AA14A7AD7E957870DBB0152B4BF13FB(__this, NULL);
		NullCheck(L_16);
		bool L_17;
		L_17 = VirtualFuncInvoker1< bool, int32_t >::Invoke(25 /* System.Boolean UnityEngine.EventSystems.BaseInput::GetMouseButton(System.Int32) */, L_16, 0);
		V_3 = L_17;
		bool L_18 = V_3;
		if (!L_18)
		{
			goto IL_0076;
		}
	}
	{
		// ProcessMove(leftPressData.buttonData);
		MouseButtonEventData_t0761D63D3A2B13090597C22DD97597CC7FE4D154* L_19 = V_1;
		NullCheck(L_19);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_20 = L_19->___buttonData_1;
		VirtualActionInvoker1< PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* >::Invoke(29 /* System.Void UnityEngine.EventSystems.PointerInputModule::ProcessMove(UnityEngine.EventSystems.PointerEventData) */, __this, L_20);
		// ProcessDrag(leftPressData.buttonData);
		MouseButtonEventData_t0761D63D3A2B13090597C22DD97597CC7FE4D154* L_21 = V_1;
		NullCheck(L_21);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_22 = L_21->___buttonData_1;
		VirtualActionInvoker1< PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* >::Invoke(30 /* System.Void UnityEngine.EventSystems.PointerInputModule::ProcessDrag(UnityEngine.EventSystems.PointerEventData) */, __this, L_22);
	}

IL_0076:
	{
		// }
		return;
	}
}
// System.Void UnityEngine.EventSystems.TouchInputModule::ProcessTouchEvents()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TouchInputModule_ProcessTouchEvents_mBB28D85996F6280141E39A462BC35EF01373E514 (TouchInputModule_t154B7CF685F02D5B9529572B1A96EBD75AAA945C* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	Touch_t03E51455ED508492B3F278903A0114FA0E87B417 V_1;
	memset((&V_1), 0, sizeof(V_1));
	bool V_2 = false;
	bool V_3 = false;
	PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* V_4 = NULL;
	bool V_5 = false;
	bool V_6 = false;
	bool V_7 = false;
	{
		// for (int i = 0; i < input.touchCount; ++i)
		V_0 = 0;
		goto IL_006b;
	}

IL_0005:
	{
		// Touch touch = input.GetTouch(i);
		BaseInput_t69C46B0AA3C24F1CA842A0D03CACACC4EC788622* L_0;
		L_0 = BaseInputModule_get_input_mCB3F78528AA14A7AD7E957870DBB0152B4BF13FB(__this, NULL);
		int32_t L_1 = V_0;
		NullCheck(L_0);
		Touch_t03E51455ED508492B3F278903A0114FA0E87B417 L_2;
		L_2 = VirtualFuncInvoker1< Touch_t03E51455ED508492B3F278903A0114FA0E87B417, int32_t >::Invoke(30 /* UnityEngine.Touch UnityEngine.EventSystems.BaseInput::GetTouch(System.Int32) */, L_0, L_1);
		V_1 = L_2;
		// if (touch.type == TouchType.Indirect)
		int32_t L_3;
		L_3 = Touch_get_type_mB505EF2DCF13160DFA0C6AAF406DCB4CBED20745((&V_1), NULL);
		V_5 = (bool)((((int32_t)L_3) == ((int32_t)1))? 1 : 0);
		bool L_4 = V_5;
		if (!L_4)
		{
			goto IL_0025;
		}
	}
	{
		// continue;
		goto IL_0067;
	}

IL_0025:
	{
		// var pointer = GetTouchPointerEventData(touch, out pressed, out released);
		Touch_t03E51455ED508492B3F278903A0114FA0E87B417 L_5 = V_1;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_6;
		L_6 = PointerInputModule_GetTouchPointerEventData_m55EBA8BD04214AAD8E98B9109D44610496A5B2E1(__this, L_5, (&V_3), (&V_2), NULL);
		V_4 = L_6;
		// ProcessTouchPress(pointer, pressed, released);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_7 = V_4;
		bool L_8 = V_3;
		bool L_9 = V_2;
		TouchInputModule_ProcessTouchPress_m1DC51E52E6B419F02626EB567A60411A0FCFA517(__this, L_7, L_8, L_9, NULL);
		// if (!released)
		bool L_10 = V_2;
		V_6 = (bool)((((int32_t)L_10) == ((int32_t)0))? 1 : 0);
		bool L_11 = V_6;
		if (!L_11)
		{
			goto IL_005d;
		}
	}
	{
		// ProcessMove(pointer);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_12 = V_4;
		VirtualActionInvoker1< PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* >::Invoke(29 /* System.Void UnityEngine.EventSystems.PointerInputModule::ProcessMove(UnityEngine.EventSystems.PointerEventData) */, __this, L_12);
		// ProcessDrag(pointer);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_13 = V_4;
		VirtualActionInvoker1< PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* >::Invoke(30 /* System.Void UnityEngine.EventSystems.PointerInputModule::ProcessDrag(UnityEngine.EventSystems.PointerEventData) */, __this, L_13);
		goto IL_0066;
	}

IL_005d:
	{
		// RemovePointerData(pointer);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_14 = V_4;
		PointerInputModule_RemovePointerData_m012713A1B4511855549793D6BA2B7998134B1BE9(__this, L_14, NULL);
	}

IL_0066:
	{
	}

IL_0067:
	{
		// for (int i = 0; i < input.touchCount; ++i)
		int32_t L_15 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_15, 1));
	}

IL_006b:
	{
		// for (int i = 0; i < input.touchCount; ++i)
		int32_t L_16 = V_0;
		BaseInput_t69C46B0AA3C24F1CA842A0D03CACACC4EC788622* L_17;
		L_17 = BaseInputModule_get_input_mCB3F78528AA14A7AD7E957870DBB0152B4BF13FB(__this, NULL);
		NullCheck(L_17);
		int32_t L_18;
		L_18 = VirtualFuncInvoker0< int32_t >::Invoke(29 /* System.Int32 UnityEngine.EventSystems.BaseInput::get_touchCount() */, L_17);
		V_7 = (bool)((((int32_t)L_16) < ((int32_t)L_18))? 1 : 0);
		bool L_19 = V_7;
		if (L_19)
		{
			goto IL_0005;
		}
	}
	{
		// }
		return;
	}
}
// System.Void UnityEngine.EventSystems.TouchInputModule::ProcessTouchPress(UnityEngine.EventSystems.PointerEventData,System.Boolean,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TouchInputModule_ProcessTouchPress_m1DC51E52E6B419F02626EB567A60411A0FCFA517 (TouchInputModule_t154B7CF685F02D5B9529572B1A96EBD75AAA945C* __this, PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* ___0_pointerEvent, bool ___1_pressed, bool ___2_released, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ExecuteEvents_ExecuteHierarchy_TisIDropHandler_t9F3B358BA4812886852E9AB85A653ABF73B9AA35_m0C0E2A729F88D6AB5AC2B4FD9C4E33D181A52A57_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ExecuteEvents_ExecuteHierarchy_TisIPointerDownHandler_t42CC83619BB6295404D44090142F7726003CE573_mF031AC46543C02039764EDB1B0673DFA36B1F58C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ExecuteEvents_ExecuteHierarchy_TisIPointerExitHandler_t1AA3FC124CC77401AF27435A3D6E611F5C7A57EE_m50CEB3F041077A74C37270714BBF0CC3EB37DD92_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ExecuteEvents_Execute_TisIEndDragHandler_t9A93E4A27E7CEED446E5FE3DACF39B1A552C23A9_m6AA443D4F53AF0FEBAC269F761A158635243467E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ExecuteEvents_Execute_TisIInitializePotentialDragHandler_tAFCBB3BBC98C928ED8D5703C39F4781446AB8E9E_mABD9E1ECC8C04235760B3855DF03F2308F62071C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ExecuteEvents_Execute_TisIPointerClickHandler_t77341AA19DE37C26F5F619DE8BD28B70D5A2B5D8_m024FB23AA1DBB1B7A5E1935FA35A1E4FF57AC5F6_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ExecuteEvents_Execute_TisIPointerUpHandler_tB2D4D0ABEAFF77BE8D0159D638D85E1AF7BAF210_mBB70745D5D17BF6402CABEFF0F52911F88C197A6_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ExecuteEvents_GetEventHandler_TisIDragHandler_t9FF2B3D79AB401D7E2485254973D15C0F117D00D_m9AA4E18082F53C60962F70D75570F1D400C37FBA_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ExecuteEvents_GetEventHandler_TisIPointerClickHandler_t77341AA19DE37C26F5F619DE8BD28B70D5A2B5D8_m3363BED905E60A4545A8CA5B8C68BA709E99536E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ExecuteEvents_t74DCF8B83743EE2773ACF182344612A048E2CC59_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* V_0 = NULL;
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 V_1;
	memset((&V_1), 0, sizeof(V_1));
	bool V_2 = false;
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* V_3 = NULL;
	float V_4 = 0.0f;
	bool V_5 = false;
	bool V_6 = false;
	bool V_7 = false;
	float V_8 = 0.0f;
	bool V_9 = false;
	int32_t V_10 = 0;
	bool V_11 = false;
	bool V_12 = false;
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* V_13 = NULL;
	bool V_14 = false;
	bool V_15 = false;
	bool V_16 = false;
	int32_t G_B18_0 = 0;
	int32_t G_B23_0 = 0;
	int32_t G_B28_0 = 0;
	{
		// var currentOverGo = pointerEvent.pointerCurrentRaycast.gameObject;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_0 = ___0_pointerEvent;
		NullCheck(L_0);
		RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 L_1;
		L_1 = PointerEventData_get_pointerCurrentRaycast_m1C6B7D707CEE9C6574DD443289D90102EDC7A2C4_inline(L_0, NULL);
		V_1 = L_1;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_2;
		L_2 = RaycastResult_get_gameObject_m77014B442B9E2D10F2CC3AEEDC07AA95CDE1E2F1((&V_1), NULL);
		V_0 = L_2;
		// if (pressed)
		bool L_3 = ___1_pressed;
		V_2 = L_3;
		bool L_4 = V_2;
		if (!L_4)
		{
			goto IL_015f;
		}
	}
	{
		// pointerEvent.eligibleForClick = true;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_5 = ___0_pointerEvent;
		NullCheck(L_5);
		PointerEventData_set_eligibleForClick_m360125CB3E348F3CF64C39F163467A842E479C21_inline(L_5, (bool)1, NULL);
		// pointerEvent.delta = Vector2.zero;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_6 = ___0_pointerEvent;
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_7;
		L_7 = Vector2_get_zero_m32506C40EC2EE7D5D4410BF40D3EE683A3D5F32C_inline(NULL);
		NullCheck(L_6);
		PointerEventData_set_delta_mD200AF7CCAEAD92D947091902AF864CB4ACE0F1D_inline(L_6, L_7, NULL);
		// pointerEvent.dragging = false;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_8 = ___0_pointerEvent;
		NullCheck(L_8);
		PointerEventData_set_dragging_m43982B3F95F05986F40A736914CFBC45D2A9BB8E_inline(L_8, (bool)0, NULL);
		// pointerEvent.useDragThreshold = true;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_9 = ___0_pointerEvent;
		NullCheck(L_9);
		PointerEventData_set_useDragThreshold_m63FE2034E4B240F1A0A902B1EB893B3DBA2D848B_inline(L_9, (bool)1, NULL);
		// pointerEvent.pressPosition = pointerEvent.position;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_10 = ___0_pointerEvent;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_11 = ___0_pointerEvent;
		NullCheck(L_11);
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_12;
		L_12 = PointerEventData_get_position_m5BE71C28EB72EFB8435749E4E6E839213AEF458C_inline(L_11, NULL);
		NullCheck(L_10);
		PointerEventData_set_pressPosition_m85544FBAB798DABE70067508294A6C4841A95379_inline(L_10, L_12, NULL);
		// pointerEvent.pointerPressRaycast = pointerEvent.pointerCurrentRaycast;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_13 = ___0_pointerEvent;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_14 = ___0_pointerEvent;
		NullCheck(L_14);
		RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 L_15;
		L_15 = PointerEventData_get_pointerCurrentRaycast_m1C6B7D707CEE9C6574DD443289D90102EDC7A2C4_inline(L_14, NULL);
		NullCheck(L_13);
		PointerEventData_set_pointerPressRaycast_m55CA127474B4CBCA795A9C872B7630AAF766F852_inline(L_13, L_15, NULL);
		// DeselectIfSelectionChanged(currentOverGo, pointerEvent);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_16 = V_0;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_17 = ___0_pointerEvent;
		PointerInputModule_DeselectIfSelectionChanged_m8F111DD2317E33C4F0498F651BC52BD5C984A95B(__this, L_16, L_17, NULL);
		// if (pointerEvent.pointerEnter != currentOverGo)
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_18 = ___0_pointerEvent;
		NullCheck(L_18);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_19;
		L_19 = PointerEventData_get_pointerEnter_m6CE76D5C0C36C4666CDDE348B57885C52D495A4B_inline(L_18, NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_20 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_21;
		L_21 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_19, L_20, NULL);
		V_5 = L_21;
		bool L_22 = V_5;
		if (!L_22)
		{
			goto IL_0085;
		}
	}
	{
		// HandlePointerExitAndEnter(pointerEvent, currentOverGo);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_23 = ___0_pointerEvent;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_24 = V_0;
		BaseInputModule_HandlePointerExitAndEnter_m0815F06EAF8F937916E0656D66A69844CB211298(__this, L_23, L_24, NULL);
		// pointerEvent.pointerEnter = currentOverGo;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_25 = ___0_pointerEvent;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_26 = V_0;
		NullCheck(L_25);
		PointerEventData_set_pointerEnter_m2DA660C24CBDE9B83DF2B2D09D9AF0E94A770D17_inline(L_25, L_26, NULL);
	}

IL_0085:
	{
		// var newPressed = ExecuteEvents.ExecuteHierarchy(currentOverGo, pointerEvent, ExecuteEvents.pointerDownHandler);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_27 = V_0;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_28 = ___0_pointerEvent;
		il2cpp_codegen_runtime_class_init_inline(ExecuteEvents_t74DCF8B83743EE2773ACF182344612A048E2CC59_il2cpp_TypeInfo_var);
		EventFunction_1_t00024D26E9CCD074EEBC25568B0383863A4CF117* L_29;
		L_29 = ExecuteEvents_get_pointerDownHandler_mA67CE33D32540939A273DB88D6456C7FE43C13EF(NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_30;
		L_30 = ExecuteEvents_ExecuteHierarchy_TisIPointerDownHandler_t42CC83619BB6295404D44090142F7726003CE573_mF031AC46543C02039764EDB1B0673DFA36B1F58C(L_27, L_28, L_29, ExecuteEvents_ExecuteHierarchy_TisIPointerDownHandler_t42CC83619BB6295404D44090142F7726003CE573_mF031AC46543C02039764EDB1B0673DFA36B1F58C_RuntimeMethod_var);
		V_3 = L_30;
		// if (newPressed == null)
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_31 = V_3;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_32;
		L_32 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_31, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		V_6 = L_32;
		bool L_33 = V_6;
		if (!L_33)
		{
			goto IL_00a6;
		}
	}
	{
		// newPressed = ExecuteEvents.GetEventHandler<IPointerClickHandler>(currentOverGo);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_34 = V_0;
		il2cpp_codegen_runtime_class_init_inline(ExecuteEvents_t74DCF8B83743EE2773ACF182344612A048E2CC59_il2cpp_TypeInfo_var);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_35;
		L_35 = ExecuteEvents_GetEventHandler_TisIPointerClickHandler_t77341AA19DE37C26F5F619DE8BD28B70D5A2B5D8_m3363BED905E60A4545A8CA5B8C68BA709E99536E(L_34, ExecuteEvents_GetEventHandler_TisIPointerClickHandler_t77341AA19DE37C26F5F619DE8BD28B70D5A2B5D8_m3363BED905E60A4545A8CA5B8C68BA709E99536E_RuntimeMethod_var);
		V_3 = L_35;
	}

IL_00a6:
	{
		// float time = Time.unscaledTime;
		float L_36;
		L_36 = Time_get_unscaledTime_mAF4040B858903E1325D1C65B8BF1AC61460B2503(NULL);
		V_4 = L_36;
		// if (newPressed == pointerEvent.lastPress)
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_37 = V_3;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_38 = ___0_pointerEvent;
		NullCheck(L_38);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_39;
		L_39 = PointerEventData_get_lastPress_m46720C62503214A44EE947679A8BA307BC2AEEDC_inline(L_38, NULL);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_40;
		L_40 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_37, L_39, NULL);
		V_7 = L_40;
		bool L_41 = V_7;
		if (!L_41)
		{
			goto IL_0103;
		}
	}
	{
		// var diffTime = time - pointerEvent.clickTime;
		float L_42 = V_4;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_43 = ___0_pointerEvent;
		NullCheck(L_43);
		float L_44;
		L_44 = PointerEventData_get_clickTime_m5ABE0298E8CEF28B6BD7E750E940756CD78AB96E_inline(L_43, NULL);
		V_8 = ((float)il2cpp_codegen_subtract(L_42, L_44));
		// if (diffTime < 0.3f)
		float L_45 = V_8;
		V_9 = (bool)((((float)L_45) < ((float)(0.300000012f)))? 1 : 0);
		bool L_46 = V_9;
		if (!L_46)
		{
			goto IL_00ef;
		}
	}
	{
		// ++pointerEvent.clickCount;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_47 = ___0_pointerEvent;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_48 = L_47;
		NullCheck(L_48);
		int32_t L_49;
		L_49 = PointerEventData_get_clickCount_m3977011C09DB9F904B1AAC3708B821B8D6AC0F9F_inline(L_48, NULL);
		V_10 = ((int32_t)il2cpp_codegen_add(L_49, 1));
		int32_t L_50 = V_10;
		NullCheck(L_48);
		PointerEventData_set_clickCount_m0A87C2C367987492F310786DC9C3DF1616EA4D49_inline(L_48, L_50, NULL);
		goto IL_00f7;
	}

IL_00ef:
	{
		// pointerEvent.clickCount = 1;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_51 = ___0_pointerEvent;
		NullCheck(L_51);
		PointerEventData_set_clickCount_m0A87C2C367987492F310786DC9C3DF1616EA4D49_inline(L_51, 1, NULL);
	}

IL_00f7:
	{
		// pointerEvent.clickTime = time;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_52 = ___0_pointerEvent;
		float L_53 = V_4;
		NullCheck(L_52);
		PointerEventData_set_clickTime_m93D27EB35F490AC9100369A23002F09148F85996_inline(L_52, L_53, NULL);
		goto IL_010d;
	}

IL_0103:
	{
		// pointerEvent.clickCount = 1;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_54 = ___0_pointerEvent;
		NullCheck(L_54);
		PointerEventData_set_clickCount_m0A87C2C367987492F310786DC9C3DF1616EA4D49_inline(L_54, 1, NULL);
	}

IL_010d:
	{
		// pointerEvent.pointerPress = newPressed;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_55 = ___0_pointerEvent;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_56 = V_3;
		NullCheck(L_55);
		PointerEventData_set_pointerPress_m51241AAA6E5F87ADEBBB8DB7D4452CE45200BEE8(L_55, L_56, NULL);
		// pointerEvent.rawPointerPress = currentOverGo;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_57 = ___0_pointerEvent;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_58 = V_0;
		NullCheck(L_57);
		PointerEventData_set_rawPointerPress_mEEC4E3C7CD00F1DDCD3DA98DA5837E71BB8455E3_inline(L_57, L_58, NULL);
		// pointerEvent.clickTime = time;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_59 = ___0_pointerEvent;
		float L_60 = V_4;
		NullCheck(L_59);
		PointerEventData_set_clickTime_m93D27EB35F490AC9100369A23002F09148F85996_inline(L_59, L_60, NULL);
		// pointerEvent.pointerDrag = ExecuteEvents.GetEventHandler<IDragHandler>(currentOverGo);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_61 = ___0_pointerEvent;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_62 = V_0;
		il2cpp_codegen_runtime_class_init_inline(ExecuteEvents_t74DCF8B83743EE2773ACF182344612A048E2CC59_il2cpp_TypeInfo_var);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_63;
		L_63 = ExecuteEvents_GetEventHandler_TisIDragHandler_t9FF2B3D79AB401D7E2485254973D15C0F117D00D_m9AA4E18082F53C60962F70D75570F1D400C37FBA(L_62, ExecuteEvents_GetEventHandler_TisIDragHandler_t9FF2B3D79AB401D7E2485254973D15C0F117D00D_m9AA4E18082F53C60962F70D75570F1D400C37FBA_RuntimeMethod_var);
		NullCheck(L_61);
		PointerEventData_set_pointerDrag_m0E8D72362B07962843671C39ADC8F4D5E4915010_inline(L_61, L_63, NULL);
		// if (pointerEvent.pointerDrag != null)
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_64 = ___0_pointerEvent;
		NullCheck(L_64);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_65;
		L_65 = PointerEventData_get_pointerDrag_m36BF08A32216845A8095C5F74DFE6C9959A11E96_inline(L_64, NULL);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_66;
		L_66 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_65, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		V_11 = L_66;
		bool L_67 = V_11;
		if (!L_67)
		{
			goto IL_0157;
		}
	}
	{
		// ExecuteEvents.Execute(pointerEvent.pointerDrag, pointerEvent, ExecuteEvents.initializePotentialDrag);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_68 = ___0_pointerEvent;
		NullCheck(L_68);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_69;
		L_69 = PointerEventData_get_pointerDrag_m36BF08A32216845A8095C5F74DFE6C9959A11E96_inline(L_68, NULL);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_70 = ___0_pointerEvent;
		il2cpp_codegen_runtime_class_init_inline(ExecuteEvents_t74DCF8B83743EE2773ACF182344612A048E2CC59_il2cpp_TypeInfo_var);
		EventFunction_1_t7DFDB0A0C9926E06BF7870695CD48A0533DFABAD* L_71;
		L_71 = ExecuteEvents_get_initializePotentialDrag_m16F4CD40448FB1B78F6683AA26A9CC574F48AFBD(NULL);
		bool L_72;
		L_72 = ExecuteEvents_Execute_TisIInitializePotentialDragHandler_tAFCBB3BBC98C928ED8D5703C39F4781446AB8E9E_mABD9E1ECC8C04235760B3855DF03F2308F62071C(L_69, L_70, L_71, ExecuteEvents_Execute_TisIInitializePotentialDragHandler_tAFCBB3BBC98C928ED8D5703C39F4781446AB8E9E_mABD9E1ECC8C04235760B3855DF03F2308F62071C_RuntimeMethod_var);
	}

IL_0157:
	{
		// m_InputPointerEvent = pointerEvent;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_73 = ___0_pointerEvent;
		__this->___m_InputPointerEvent_19 = L_73;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_InputPointerEvent_19), (void*)L_73);
	}

IL_015f:
	{
		// if (released)
		bool L_74 = ___2_released;
		V_12 = L_74;
		bool L_75 = V_12;
		if (!L_75)
		{
			goto IL_025d;
		}
	}
	{
		// ExecuteEvents.Execute(pointerEvent.pointerPress, pointerEvent, ExecuteEvents.pointerUpHandler);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_76 = ___0_pointerEvent;
		NullCheck(L_76);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_77;
		L_77 = PointerEventData_get_pointerPress_mEE815DDB67E40AA587090BCCE0E3CABA6405C50A(L_76, NULL);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_78 = ___0_pointerEvent;
		il2cpp_codegen_runtime_class_init_inline(ExecuteEvents_t74DCF8B83743EE2773ACF182344612A048E2CC59_il2cpp_TypeInfo_var);
		EventFunction_1_t919A3841A202FB8C678BC0172FAB7E2F79B88AD8* L_79;
		L_79 = ExecuteEvents_get_pointerUpHandler_m51B83B4AD7498D6F7A2CBD5F2331E91A37AE4CF2(NULL);
		bool L_80;
		L_80 = ExecuteEvents_Execute_TisIPointerUpHandler_tB2D4D0ABEAFF77BE8D0159D638D85E1AF7BAF210_mBB70745D5D17BF6402CABEFF0F52911F88C197A6(L_77, L_78, L_79, ExecuteEvents_Execute_TisIPointerUpHandler_tB2D4D0ABEAFF77BE8D0159D638D85E1AF7BAF210_mBB70745D5D17BF6402CABEFF0F52911F88C197A6_RuntimeMethod_var);
		// var pointerUpHandler = ExecuteEvents.GetEventHandler<IPointerClickHandler>(currentOverGo);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_81 = V_0;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_82;
		L_82 = ExecuteEvents_GetEventHandler_TisIPointerClickHandler_t77341AA19DE37C26F5F619DE8BD28B70D5A2B5D8_m3363BED905E60A4545A8CA5B8C68BA709E99536E(L_81, ExecuteEvents_GetEventHandler_TisIPointerClickHandler_t77341AA19DE37C26F5F619DE8BD28B70D5A2B5D8_m3363BED905E60A4545A8CA5B8C68BA709E99536E_RuntimeMethod_var);
		V_13 = L_82;
		// if (pointerEvent.pointerPress == pointerUpHandler && pointerEvent.eligibleForClick)
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_83 = ___0_pointerEvent;
		NullCheck(L_83);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_84;
		L_84 = PointerEventData_get_pointerPress_mEE815DDB67E40AA587090BCCE0E3CABA6405C50A(L_83, NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_85 = V_13;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_86;
		L_86 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_84, L_85, NULL);
		if (!L_86)
		{
			goto IL_019b;
		}
	}
	{
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_87 = ___0_pointerEvent;
		NullCheck(L_87);
		bool L_88;
		L_88 = PointerEventData_get_eligibleForClick_m4B01A1640C694FD7421BDFB19CF763BC85672C8E_inline(L_87, NULL);
		G_B18_0 = ((int32_t)(L_88));
		goto IL_019c;
	}

IL_019b:
	{
		G_B18_0 = 0;
	}

IL_019c:
	{
		V_14 = (bool)G_B18_0;
		bool L_89 = V_14;
		if (!L_89)
		{
			goto IL_01b8;
		}
	}
	{
		// ExecuteEvents.Execute(pointerEvent.pointerPress, pointerEvent, ExecuteEvents.pointerClickHandler);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_90 = ___0_pointerEvent;
		NullCheck(L_90);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_91;
		L_91 = PointerEventData_get_pointerPress_mEE815DDB67E40AA587090BCCE0E3CABA6405C50A(L_90, NULL);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_92 = ___0_pointerEvent;
		il2cpp_codegen_runtime_class_init_inline(ExecuteEvents_t74DCF8B83743EE2773ACF182344612A048E2CC59_il2cpp_TypeInfo_var);
		EventFunction_1_t586168BFEFD0CF29A2B706B5411BF712BD73359E* L_93;
		L_93 = ExecuteEvents_get_pointerClickHandler_m0017F9D1EAF7C02CDDB4C148C92D6685D88EA8D5(NULL);
		bool L_94;
		L_94 = ExecuteEvents_Execute_TisIPointerClickHandler_t77341AA19DE37C26F5F619DE8BD28B70D5A2B5D8_m024FB23AA1DBB1B7A5E1935FA35A1E4FF57AC5F6(L_91, L_92, L_93, ExecuteEvents_Execute_TisIPointerClickHandler_t77341AA19DE37C26F5F619DE8BD28B70D5A2B5D8_m024FB23AA1DBB1B7A5E1935FA35A1E4FF57AC5F6_RuntimeMethod_var);
		goto IL_01e4;
	}

IL_01b8:
	{
		// else if (pointerEvent.pointerDrag != null && pointerEvent.dragging)
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_95 = ___0_pointerEvent;
		NullCheck(L_95);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_96;
		L_96 = PointerEventData_get_pointerDrag_m36BF08A32216845A8095C5F74DFE6C9959A11E96_inline(L_95, NULL);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_97;
		L_97 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_96, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_97)
		{
			goto IL_01ce;
		}
	}
	{
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_98 = ___0_pointerEvent;
		NullCheck(L_98);
		bool L_99;
		L_99 = PointerEventData_get_dragging_mE0AD837F228E3830D4A74657AD3D47F53F6C87E9_inline(L_98, NULL);
		G_B23_0 = ((int32_t)(L_99));
		goto IL_01cf;
	}

IL_01ce:
	{
		G_B23_0 = 0;
	}

IL_01cf:
	{
		V_15 = (bool)G_B23_0;
		bool L_100 = V_15;
		if (!L_100)
		{
			goto IL_01e4;
		}
	}
	{
		// ExecuteEvents.ExecuteHierarchy(currentOverGo, pointerEvent, ExecuteEvents.dropHandler);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_101 = V_0;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_102 = ___0_pointerEvent;
		il2cpp_codegen_runtime_class_init_inline(ExecuteEvents_t74DCF8B83743EE2773ACF182344612A048E2CC59_il2cpp_TypeInfo_var);
		EventFunction_1_tB3864D36512C3A896DAC44E898E5D9E1A92CB733* L_103;
		L_103 = ExecuteEvents_get_dropHandler_m8E00FA7361DE68780ACEB365E6B14206A2180D03(NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_104;
		L_104 = ExecuteEvents_ExecuteHierarchy_TisIDropHandler_t9F3B358BA4812886852E9AB85A653ABF73B9AA35_m0C0E2A729F88D6AB5AC2B4FD9C4E33D181A52A57(L_101, L_102, L_103, ExecuteEvents_ExecuteHierarchy_TisIDropHandler_t9F3B358BA4812886852E9AB85A653ABF73B9AA35_m0C0E2A729F88D6AB5AC2B4FD9C4E33D181A52A57_RuntimeMethod_var);
	}

IL_01e4:
	{
		// pointerEvent.eligibleForClick = false;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_105 = ___0_pointerEvent;
		NullCheck(L_105);
		PointerEventData_set_eligibleForClick_m360125CB3E348F3CF64C39F163467A842E479C21_inline(L_105, (bool)0, NULL);
		// pointerEvent.pointerPress = null;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_106 = ___0_pointerEvent;
		NullCheck(L_106);
		PointerEventData_set_pointerPress_m51241AAA6E5F87ADEBBB8DB7D4452CE45200BEE8(L_106, (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*)NULL, NULL);
		// pointerEvent.rawPointerPress = null;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_107 = ___0_pointerEvent;
		NullCheck(L_107);
		PointerEventData_set_rawPointerPress_mEEC4E3C7CD00F1DDCD3DA98DA5837E71BB8455E3_inline(L_107, (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*)NULL, NULL);
		// if (pointerEvent.pointerDrag != null && pointerEvent.dragging)
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_108 = ___0_pointerEvent;
		NullCheck(L_108);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_109;
		L_109 = PointerEventData_get_pointerDrag_m36BF08A32216845A8095C5F74DFE6C9959A11E96_inline(L_108, NULL);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_110;
		L_110 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_109, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_110)
		{
			goto IL_0212;
		}
	}
	{
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_111 = ___0_pointerEvent;
		NullCheck(L_111);
		bool L_112;
		L_112 = PointerEventData_get_dragging_mE0AD837F228E3830D4A74657AD3D47F53F6C87E9_inline(L_111, NULL);
		G_B28_0 = ((int32_t)(L_112));
		goto IL_0213;
	}

IL_0212:
	{
		G_B28_0 = 0;
	}

IL_0213:
	{
		V_16 = (bool)G_B28_0;
		bool L_113 = V_16;
		if (!L_113)
		{
			goto IL_022b;
		}
	}
	{
		// ExecuteEvents.Execute(pointerEvent.pointerDrag, pointerEvent, ExecuteEvents.endDragHandler);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_114 = ___0_pointerEvent;
		NullCheck(L_114);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_115;
		L_115 = PointerEventData_get_pointerDrag_m36BF08A32216845A8095C5F74DFE6C9959A11E96_inline(L_114, NULL);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_116 = ___0_pointerEvent;
		il2cpp_codegen_runtime_class_init_inline(ExecuteEvents_t74DCF8B83743EE2773ACF182344612A048E2CC59_il2cpp_TypeInfo_var);
		EventFunction_1_t33BA7CA3F9202146F70BE77589CE24F7451C584C* L_117;
		L_117 = ExecuteEvents_get_endDragHandler_mE78FEEEAE114635E416FF1FE33C851E62B60555B(NULL);
		bool L_118;
		L_118 = ExecuteEvents_Execute_TisIEndDragHandler_t9A93E4A27E7CEED446E5FE3DACF39B1A552C23A9_m6AA443D4F53AF0FEBAC269F761A158635243467E(L_115, L_116, L_117, ExecuteEvents_Execute_TisIEndDragHandler_t9A93E4A27E7CEED446E5FE3DACF39B1A552C23A9_m6AA443D4F53AF0FEBAC269F761A158635243467E_RuntimeMethod_var);
	}

IL_022b:
	{
		// pointerEvent.dragging = false;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_119 = ___0_pointerEvent;
		NullCheck(L_119);
		PointerEventData_set_dragging_m43982B3F95F05986F40A736914CFBC45D2A9BB8E_inline(L_119, (bool)0, NULL);
		// pointerEvent.pointerDrag = null;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_120 = ___0_pointerEvent;
		NullCheck(L_120);
		PointerEventData_set_pointerDrag_m0E8D72362B07962843671C39ADC8F4D5E4915010_inline(L_120, (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*)NULL, NULL);
		// ExecuteEvents.ExecuteHierarchy(pointerEvent.pointerEnter, pointerEvent, ExecuteEvents.pointerExitHandler);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_121 = ___0_pointerEvent;
		NullCheck(L_121);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_122;
		L_122 = PointerEventData_get_pointerEnter_m6CE76D5C0C36C4666CDDE348B57885C52D495A4B_inline(L_121, NULL);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_123 = ___0_pointerEvent;
		il2cpp_codegen_runtime_class_init_inline(ExecuteEvents_t74DCF8B83743EE2773ACF182344612A048E2CC59_il2cpp_TypeInfo_var);
		EventFunction_1_tA70AAFA2BD47CD0A094BCB586E2EA3E04C5F8916* L_124;
		L_124 = ExecuteEvents_get_pointerExitHandler_m03735363884BC967C1B04246B51FE98886C9C6DE(NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_125;
		L_125 = ExecuteEvents_ExecuteHierarchy_TisIPointerExitHandler_t1AA3FC124CC77401AF27435A3D6E611F5C7A57EE_m50CEB3F041077A74C37270714BBF0CC3EB37DD92(L_122, L_123, L_124, ExecuteEvents_ExecuteHierarchy_TisIPointerExitHandler_t1AA3FC124CC77401AF27435A3D6E611F5C7A57EE_m50CEB3F041077A74C37270714BBF0CC3EB37DD92_RuntimeMethod_var);
		// pointerEvent.pointerEnter = null;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_126 = ___0_pointerEvent;
		NullCheck(L_126);
		PointerEventData_set_pointerEnter_m2DA660C24CBDE9B83DF2B2D09D9AF0E94A770D17_inline(L_126, (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*)NULL, NULL);
		// m_InputPointerEvent = pointerEvent;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_127 = ___0_pointerEvent;
		__this->___m_InputPointerEvent_19 = L_127;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_InputPointerEvent_19), (void*)L_127);
	}

IL_025d:
	{
		// }
		return;
	}
}
// System.Void UnityEngine.EventSystems.TouchInputModule::DeactivateModule()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TouchInputModule_DeactivateModule_m7CF377DBC376C3EC560523E76514E9F47CCC9DEE (TouchInputModule_t154B7CF685F02D5B9529572B1A96EBD75AAA945C* __this, const RuntimeMethod* method) 
{
	{
		// base.DeactivateModule();
		BaseInputModule_DeactivateModule_mAE698307DADBE4DE8A26BD3DE5F3F7E3D75B385D(__this, NULL);
		// ClearSelection();
		PointerInputModule_ClearSelection_mC5852667E5B9CA97C2A4CAB3D7C907344511C1D2(__this, NULL);
		// }
		return;
	}
}
// System.String UnityEngine.EventSystems.TouchInputModule::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* TouchInputModule_ToString_m1AD08DB012D85A33FC0EA3322D5AA5EB98CD1956 (TouchInputModule_t154B7CF685F02D5B9529572B1A96EBD75AAA945C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_GetEnumerator_m5127D66D8AB03E7A21778DD898242C65F0EED034_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_Dispose_m939CB6214446517A933B0216F1C64AB86E291714_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_MoveNext_m69F94D82492DD2778B91F594B491223C02265150_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_get_Current_mEC2B6AFDB80F9344C20DF0D6A63925642A413615_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&KeyValuePair_2_ToString_m5F8161F26E20B830F794E3C0B87C0570D011D4AD_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral55489C2AE4CD8276F5514C1F5C0FC0E6C828316F);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral9778C320E07EB86C3995D33DDB63310A2DC91762);
		s_Il2CppMethodInitialized = true;
	}
	StringBuilder_t* V_0 = NULL;
	bool V_1 = false;
	PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* V_2 = NULL;
	bool V_3 = false;
	Enumerator_tAC6F215019B1EAEAEE81308CEBA6052DECD5EE7E V_4;
	memset((&V_4), 0, sizeof(V_4));
	KeyValuePair_2_tC51A92A69CB9B2F98A91443EE066E405EDCA4296 V_5;
	memset((&V_5), 0, sizeof(V_5));
	String_t* V_6 = NULL;
	StringBuilder_t* G_B2_0 = NULL;
	StringBuilder_t* G_B1_0 = NULL;
	String_t* G_B3_0 = NULL;
	StringBuilder_t* G_B3_1 = NULL;
	{
		// var sb = new StringBuilder();
		StringBuilder_t* L_0 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D(L_0, NULL);
		V_0 = L_0;
		// sb.AppendLine(UseFakeInput() ? "Input: Faked" : "Input: Touch");
		StringBuilder_t* L_1 = V_0;
		bool L_2;
		L_2 = TouchInputModule_UseFakeInput_m66A84384ADA044187F239B1CFC143C42E5E56774(__this, NULL);
		G_B1_0 = L_1;
		if (L_2)
		{
			G_B2_0 = L_1;
			goto IL_0017;
		}
	}
	{
		G_B3_0 = _stringLiteral55489C2AE4CD8276F5514C1F5C0FC0E6C828316F;
		G_B3_1 = G_B1_0;
		goto IL_001c;
	}

IL_0017:
	{
		G_B3_0 = _stringLiteral9778C320E07EB86C3995D33DDB63310A2DC91762;
		G_B3_1 = G_B2_0;
	}

IL_001c:
	{
		NullCheck(G_B3_1);
		StringBuilder_t* L_3;
		L_3 = StringBuilder_AppendLine_mF75744CE941C63E33188E22E936B71A24D3CBF88(G_B3_1, G_B3_0, NULL);
		// if (UseFakeInput())
		bool L_4;
		L_4 = TouchInputModule_UseFakeInput_m66A84384ADA044187F239B1CFC143C42E5E56774(__this, NULL);
		V_1 = L_4;
		bool L_5 = V_1;
		if (!L_5)
		{
			goto IL_004d;
		}
	}
	{
		// var pointerData = GetLastPointerEventData(kMouseLeftId);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_6;
		L_6 = PointerInputModule_GetLastPointerEventData_m6355023718EB2DCF6D9C226A57B63B70CCEECAB4(__this, (-1), NULL);
		V_2 = L_6;
		// if (pointerData != null)
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_7 = V_2;
		V_3 = (bool)((!(((RuntimeObject*)(PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB*)L_7) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		bool L_8 = V_3;
		if (!L_8)
		{
			goto IL_004a;
		}
	}
	{
		// sb.AppendLine(pointerData.ToString());
		StringBuilder_t* L_9 = V_0;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_10 = V_2;
		NullCheck(L_10);
		String_t* L_11;
		L_11 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_10);
		NullCheck(L_9);
		StringBuilder_t* L_12;
		L_12 = StringBuilder_AppendLine_mF75744CE941C63E33188E22E936B71A24D3CBF88(L_9, L_11, NULL);
	}

IL_004a:
	{
		goto IL_0096;
	}

IL_004d:
	{
		// foreach (var pointerEventData in m_PointerData)
		Dictionary_2_t489B023479196B8FC9709A9F834FC38729BD9493* L_13 = ((PointerInputModule_tD71E11FA989C22D83883E120EAA4F05929907556*)__this)->___m_PointerData_15;
		NullCheck(L_13);
		Enumerator_tAC6F215019B1EAEAEE81308CEBA6052DECD5EE7E L_14;
		L_14 = Dictionary_2_GetEnumerator_m5127D66D8AB03E7A21778DD898242C65F0EED034(L_13, Dictionary_2_GetEnumerator_m5127D66D8AB03E7A21778DD898242C65F0EED034_RuntimeMethod_var);
		V_4 = L_14;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0086:
			{// begin finally (depth: 1)
				Enumerator_Dispose_m939CB6214446517A933B0216F1C64AB86E291714((&V_4), Enumerator_Dispose_m939CB6214446517A933B0216F1C64AB86E291714_RuntimeMethod_var);
				return;
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			{
				goto IL_007b_1;
			}

IL_005e_1:
			{
				// foreach (var pointerEventData in m_PointerData)
				KeyValuePair_2_tC51A92A69CB9B2F98A91443EE066E405EDCA4296 L_15;
				L_15 = Enumerator_get_Current_mEC2B6AFDB80F9344C20DF0D6A63925642A413615_inline((&V_4), Enumerator_get_Current_mEC2B6AFDB80F9344C20DF0D6A63925642A413615_RuntimeMethod_var);
				V_5 = L_15;
				// sb.AppendLine(pointerEventData.ToString());
				StringBuilder_t* L_16 = V_0;
				String_t* L_17;
				L_17 = KeyValuePair_2_ToString_m5F8161F26E20B830F794E3C0B87C0570D011D4AD((&V_5), KeyValuePair_2_ToString_m5F8161F26E20B830F794E3C0B87C0570D011D4AD_RuntimeMethod_var);
				NullCheck(L_16);
				StringBuilder_t* L_18;
				L_18 = StringBuilder_AppendLine_mF75744CE941C63E33188E22E936B71A24D3CBF88(L_16, L_17, NULL);
			}

IL_007b_1:
			{
				// foreach (var pointerEventData in m_PointerData)
				bool L_19;
				L_19 = Enumerator_MoveNext_m69F94D82492DD2778B91F594B491223C02265150((&V_4), Enumerator_MoveNext_m69F94D82492DD2778B91F594B491223C02265150_RuntimeMethod_var);
				if (L_19)
				{
					goto IL_005e_1;
				}
			}
			{
				goto IL_0095;
			}
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0095:
	{
	}

IL_0096:
	{
		// return sb.ToString();
		StringBuilder_t* L_20 = V_0;
		NullCheck(L_20);
		String_t* L_21;
		L_21 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_20);
		V_6 = L_21;
		goto IL_00a0;
	}

IL_00a0:
	{
		// }
		String_t* L_22 = V_6;
		return L_22;
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
// System.Void UnityEngine.EventSystems.RaycasterManager::AddRaycaster(UnityEngine.EventSystems.BaseRaycaster)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RaycasterManager_AddRaycaster_mD2EE52F55FBDB3BEAAF583C4445D4D16B09B6350 (BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* ___0_baseRaycaster, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m82AF5EAB1EA13F21CE5250B008E4EBCFEDAB6D53_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Contains_m1F747311B8D41F5857768B1D6D5C51C43CA8BE4C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	{
		// if (s_Raycasters.Contains(baseRaycaster))
		il2cpp_codegen_runtime_class_init_inline(RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_il2cpp_TypeInfo_var);
		List_1_t02E640552264E3DEAE676267B620815D33BCD0DF* L_0 = ((RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_StaticFields*)il2cpp_codegen_static_fields_for(RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_il2cpp_TypeInfo_var))->___s_Raycasters_0;
		BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* L_1 = ___0_baseRaycaster;
		NullCheck(L_0);
		bool L_2;
		L_2 = List_1_Contains_m1F747311B8D41F5857768B1D6D5C51C43CA8BE4C(L_0, L_1, List_1_Contains_m1F747311B8D41F5857768B1D6D5C51C43CA8BE4C_RuntimeMethod_var);
		V_0 = L_2;
		bool L_3 = V_0;
		if (!L_3)
		{
			goto IL_0012;
		}
	}
	{
		// return;
		goto IL_001e;
	}

IL_0012:
	{
		// s_Raycasters.Add(baseRaycaster);
		il2cpp_codegen_runtime_class_init_inline(RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_il2cpp_TypeInfo_var);
		List_1_t02E640552264E3DEAE676267B620815D33BCD0DF* L_4 = ((RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_StaticFields*)il2cpp_codegen_static_fields_for(RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_il2cpp_TypeInfo_var))->___s_Raycasters_0;
		BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* L_5 = ___0_baseRaycaster;
		NullCheck(L_4);
		List_1_Add_m82AF5EAB1EA13F21CE5250B008E4EBCFEDAB6D53_inline(L_4, L_5, List_1_Add_m82AF5EAB1EA13F21CE5250B008E4EBCFEDAB6D53_RuntimeMethod_var);
	}

IL_001e:
	{
		// }
		return;
	}
}
// System.Collections.Generic.List`1<UnityEngine.EventSystems.BaseRaycaster> UnityEngine.EventSystems.RaycasterManager::GetRaycasters()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_t02E640552264E3DEAE676267B620815D33BCD0DF* RaycasterManager_GetRaycasters_m876BA9CA8DB8E6D351DC4A97473753503B7017DE (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	List_1_t02E640552264E3DEAE676267B620815D33BCD0DF* V_0 = NULL;
	{
		// return s_Raycasters;
		il2cpp_codegen_runtime_class_init_inline(RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_il2cpp_TypeInfo_var);
		List_1_t02E640552264E3DEAE676267B620815D33BCD0DF* L_0 = ((RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_StaticFields*)il2cpp_codegen_static_fields_for(RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_il2cpp_TypeInfo_var))->___s_Raycasters_0;
		V_0 = L_0;
		goto IL_0009;
	}

IL_0009:
	{
		// }
		List_1_t02E640552264E3DEAE676267B620815D33BCD0DF* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.EventSystems.RaycasterManager::RemoveRaycasters(UnityEngine.EventSystems.BaseRaycaster)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RaycasterManager_RemoveRaycasters_m0800E0ACE007AD43B62D10C1029EC85E7DE28999 (BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* ___0_baseRaycaster, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Contains_m1F747311B8D41F5857768B1D6D5C51C43CA8BE4C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Remove_m585A9E471D1C60EE46BA224A58947647F1E2B83B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	{
		// if (!s_Raycasters.Contains(baseRaycaster))
		il2cpp_codegen_runtime_class_init_inline(RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_il2cpp_TypeInfo_var);
		List_1_t02E640552264E3DEAE676267B620815D33BCD0DF* L_0 = ((RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_StaticFields*)il2cpp_codegen_static_fields_for(RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_il2cpp_TypeInfo_var))->___s_Raycasters_0;
		BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* L_1 = ___0_baseRaycaster;
		NullCheck(L_0);
		bool L_2;
		L_2 = List_1_Contains_m1F747311B8D41F5857768B1D6D5C51C43CA8BE4C(L_0, L_1, List_1_Contains_m1F747311B8D41F5857768B1D6D5C51C43CA8BE4C_RuntimeMethod_var);
		V_0 = (bool)((((int32_t)L_2) == ((int32_t)0))? 1 : 0);
		bool L_3 = V_0;
		if (!L_3)
		{
			goto IL_0015;
		}
	}
	{
		// return;
		goto IL_0021;
	}

IL_0015:
	{
		// s_Raycasters.Remove(baseRaycaster);
		il2cpp_codegen_runtime_class_init_inline(RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_il2cpp_TypeInfo_var);
		List_1_t02E640552264E3DEAE676267B620815D33BCD0DF* L_4 = ((RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_StaticFields*)il2cpp_codegen_static_fields_for(RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_il2cpp_TypeInfo_var))->___s_Raycasters_0;
		BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* L_5 = ___0_baseRaycaster;
		NullCheck(L_4);
		bool L_6;
		L_6 = List_1_Remove_m585A9E471D1C60EE46BA224A58947647F1E2B83B(L_4, L_5, List_1_Remove_m585A9E471D1C60EE46BA224A58947647F1E2B83B_RuntimeMethod_var);
	}

IL_0021:
	{
		// }
		return;
	}
}
// System.Void UnityEngine.EventSystems.RaycasterManager::.cctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RaycasterManager__cctor_m06146026A557346F1469D15E855918E746125F90 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m53B48CB7A08406A33847E0C3D9D7511DE8FB0D41_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_t02E640552264E3DEAE676267B620815D33BCD0DF_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private static readonly List<BaseRaycaster> s_Raycasters = new List<BaseRaycaster>();
		List_1_t02E640552264E3DEAE676267B620815D33BCD0DF* L_0 = (List_1_t02E640552264E3DEAE676267B620815D33BCD0DF*)il2cpp_codegen_object_new(List_1_t02E640552264E3DEAE676267B620815D33BCD0DF_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		List_1__ctor_m53B48CB7A08406A33847E0C3D9D7511DE8FB0D41(L_0, List_1__ctor_m53B48CB7A08406A33847E0C3D9D7511DE8FB0D41_RuntimeMethod_var);
		((RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_StaticFields*)il2cpp_codegen_static_fields_for(RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_il2cpp_TypeInfo_var))->___s_Raycasters_0 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_StaticFields*)il2cpp_codegen_static_fields_for(RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_il2cpp_TypeInfo_var))->___s_Raycasters_0), (void*)L_0);
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
// System.Int32 UnityEngine.EventSystems.BaseRaycaster::get_priority()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t BaseRaycaster_get_priority_m79C109ECC138B84A60F9CFA40242628A8B29C838 (BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		// get { return 0; }
		V_0 = 0;
		goto IL_0005;
	}

IL_0005:
	{
		// get { return 0; }
		int32_t L_0 = V_0;
		return L_0;
	}
}
// System.Int32 UnityEngine.EventSystems.BaseRaycaster::get_sortOrderPriority()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t BaseRaycaster_get_sortOrderPriority_m4E0BEBF85F720AE4B7C78E99CCD786779C3E7226 (BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		// get { return int.MinValue; }
		V_0 = ((int32_t)-2147483648LL);
		goto IL_0009;
	}

IL_0009:
	{
		// get { return int.MinValue; }
		int32_t L_0 = V_0;
		return L_0;
	}
}
// System.Int32 UnityEngine.EventSystems.BaseRaycaster::get_renderOrderPriority()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t BaseRaycaster_get_renderOrderPriority_m03C407856FF76393AB6EE26FA173131B8F36CA66 (BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		// get { return int.MinValue; }
		V_0 = ((int32_t)-2147483648LL);
		goto IL_0009;
	}

IL_0009:
	{
		// get { return int.MinValue; }
		int32_t L_0 = V_0;
		return L_0;
	}
}
// UnityEngine.EventSystems.BaseRaycaster UnityEngine.EventSystems.BaseRaycaster::get_rootRaycaster()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* BaseRaycaster_get_rootRaycaster_m63E20D85A8B9867AC196768924F8BE579668BF28 (BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponentsInParent_TisBaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832_mA869CA05E07609C8F435F1D779B138F3F2425F8C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	BaseRaycasterU5BU5D_tAE62D3FF1A5FF9DE20B2756DA4F4F8981925A799* V_1 = NULL;
	bool V_2 = false;
	BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* V_3 = NULL;
	{
		// if (m_RootRaycaster == null)
		BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* L_0 = __this->___m_RootRaycaster_4;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		V_0 = L_1;
		bool L_2 = V_0;
		if (!L_2)
		{
			goto IL_0030;
		}
	}
	{
		// var baseRaycasters = GetComponentsInParent<BaseRaycaster>();
		BaseRaycasterU5BU5D_tAE62D3FF1A5FF9DE20B2756DA4F4F8981925A799* L_3;
		L_3 = Component_GetComponentsInParent_TisBaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832_mA869CA05E07609C8F435F1D779B138F3F2425F8C(__this, Component_GetComponentsInParent_TisBaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832_mA869CA05E07609C8F435F1D779B138F3F2425F8C_RuntimeMethod_var);
		V_1 = L_3;
		// if (baseRaycasters.Length != 0)
		BaseRaycasterU5BU5D_tAE62D3FF1A5FF9DE20B2756DA4F4F8981925A799* L_4 = V_1;
		NullCheck(L_4);
		V_2 = (bool)((!(((uint32_t)(((RuntimeArray*)L_4)->max_length)) <= ((uint32_t)0)))? 1 : 0);
		bool L_5 = V_2;
		if (!L_5)
		{
			goto IL_002f;
		}
	}
	{
		// m_RootRaycaster = baseRaycasters[baseRaycasters.Length - 1];
		BaseRaycasterU5BU5D_tAE62D3FF1A5FF9DE20B2756DA4F4F8981925A799* L_6 = V_1;
		BaseRaycasterU5BU5D_tAE62D3FF1A5FF9DE20B2756DA4F4F8981925A799* L_7 = V_1;
		NullCheck(L_7);
		NullCheck(L_6);
		int32_t L_8 = ((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_7)->max_length)), 1));
		BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* L_9 = (L_6)->GetAt(static_cast<il2cpp_array_size_t>(L_8));
		__this->___m_RootRaycaster_4 = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_RootRaycaster_4), (void*)L_9);
	}

IL_002f:
	{
	}

IL_0030:
	{
		// return m_RootRaycaster;
		BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* L_10 = __this->___m_RootRaycaster_4;
		V_3 = L_10;
		goto IL_0039;
	}

IL_0039:
	{
		// }
		BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* L_11 = V_3;
		return L_11;
	}
}
// System.String UnityEngine.EventSystems.BaseRaycaster::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* BaseRaycaster_ToString_m12811CE16AB7E07C949B78CDE309C4B2E44B5377 (BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2E8BE7BC315CC297C7A3C2864B3A2ED1BD553384);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral70F1769C72FCAF144F53009F7DA60ED467C29635);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral75B536F4B16F980DC1BE8BFB67378A32681C6F79);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral9D2B27E9061DE91A9190184698F3F04E23827CA1);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	String_t* V_1 = NULL;
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* G_B2_0 = NULL;
	int32_t G_B2_1 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B2_2 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B2_3 = NULL;
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* G_B1_0 = NULL;
	int32_t G_B1_1 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B1_2 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B1_3 = NULL;
	String_t* G_B3_0 = NULL;
	int32_t G_B3_1 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B3_2 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B3_3 = NULL;
	Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* G_B5_0 = NULL;
	int32_t G_B5_1 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B5_2 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B5_3 = NULL;
	Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* G_B4_0 = NULL;
	int32_t G_B4_1 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B4_2 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B4_3 = NULL;
	String_t* G_B6_0 = NULL;
	int32_t G_B6_1 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B6_2 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B6_3 = NULL;
	{
		// return "Name: " + gameObject + "\n" +
		//     "eventCamera: " + eventCamera + "\n" +
		//     "sortOrderPriority: " + sortOrderPriority + "\n" +
		//     "renderOrderPriority: " + renderOrderPriority;
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_0 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)8);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_1 = L_0;
		NullCheck(L_1);
		ArrayElementTypeCheck (L_1, _stringLiteral70F1769C72FCAF144F53009F7DA60ED467C29635);
		(L_1)->SetAt(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteral70F1769C72FCAF144F53009F7DA60ED467C29635);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_2 = L_1;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_3;
		L_3 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(__this, NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_4 = L_3;
		G_B1_0 = L_4;
		G_B1_1 = 1;
		G_B1_2 = L_2;
		G_B1_3 = L_2;
		if (L_4)
		{
			G_B2_0 = L_4;
			G_B2_1 = 1;
			G_B2_2 = L_2;
			G_B2_3 = L_2;
			goto IL_001e;
		}
	}
	{
		G_B3_0 = ((String_t*)(NULL));
		G_B3_1 = G_B1_1;
		G_B3_2 = G_B1_2;
		G_B3_3 = G_B1_3;
		goto IL_0023;
	}

IL_001e:
	{
		NullCheck(G_B2_0);
		String_t* L_5;
		L_5 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, G_B2_0);
		G_B3_0 = L_5;
		G_B3_1 = G_B2_1;
		G_B3_2 = G_B2_2;
		G_B3_3 = G_B2_3;
	}

IL_0023:
	{
		NullCheck(G_B3_2);
		ArrayElementTypeCheck (G_B3_2, G_B3_0);
		(G_B3_2)->SetAt(static_cast<il2cpp_array_size_t>(G_B3_1), (String_t*)G_B3_0);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_6 = G_B3_3;
		NullCheck(L_6);
		ArrayElementTypeCheck (L_6, _stringLiteral9D2B27E9061DE91A9190184698F3F04E23827CA1);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(2), (String_t*)_stringLiteral9D2B27E9061DE91A9190184698F3F04E23827CA1);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_7 = L_6;
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_8;
		L_8 = VirtualFuncInvoker0< Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* >::Invoke(18 /* UnityEngine.Camera UnityEngine.EventSystems.BaseRaycaster::get_eventCamera() */, __this);
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_9 = L_8;
		G_B4_0 = L_9;
		G_B4_1 = 3;
		G_B4_2 = L_7;
		G_B4_3 = L_7;
		if (L_9)
		{
			G_B5_0 = L_9;
			G_B5_1 = 3;
			G_B5_2 = L_7;
			G_B5_3 = L_7;
			goto IL_003b;
		}
	}
	{
		G_B6_0 = ((String_t*)(NULL));
		G_B6_1 = G_B4_1;
		G_B6_2 = G_B4_2;
		G_B6_3 = G_B4_3;
		goto IL_0040;
	}

IL_003b:
	{
		NullCheck(G_B5_0);
		String_t* L_10;
		L_10 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, G_B5_0);
		G_B6_0 = L_10;
		G_B6_1 = G_B5_1;
		G_B6_2 = G_B5_2;
		G_B6_3 = G_B5_3;
	}

IL_0040:
	{
		NullCheck(G_B6_2);
		ArrayElementTypeCheck (G_B6_2, G_B6_0);
		(G_B6_2)->SetAt(static_cast<il2cpp_array_size_t>(G_B6_1), (String_t*)G_B6_0);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_11 = G_B6_3;
		NullCheck(L_11);
		ArrayElementTypeCheck (L_11, _stringLiteral2E8BE7BC315CC297C7A3C2864B3A2ED1BD553384);
		(L_11)->SetAt(static_cast<il2cpp_array_size_t>(4), (String_t*)_stringLiteral2E8BE7BC315CC297C7A3C2864B3A2ED1BD553384);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_12 = L_11;
		int32_t L_13;
		L_13 = VirtualFuncInvoker0< int32_t >::Invoke(20 /* System.Int32 UnityEngine.EventSystems.BaseRaycaster::get_sortOrderPriority() */, __this);
		V_0 = L_13;
		String_t* L_14;
		L_14 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&V_0), NULL);
		NullCheck(L_12);
		ArrayElementTypeCheck (L_12, L_14);
		(L_12)->SetAt(static_cast<il2cpp_array_size_t>(5), (String_t*)L_14);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_15 = L_12;
		NullCheck(L_15);
		ArrayElementTypeCheck (L_15, _stringLiteral75B536F4B16F980DC1BE8BFB67378A32681C6F79);
		(L_15)->SetAt(static_cast<il2cpp_array_size_t>(6), (String_t*)_stringLiteral75B536F4B16F980DC1BE8BFB67378A32681C6F79);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_16 = L_15;
		int32_t L_17;
		L_17 = VirtualFuncInvoker0< int32_t >::Invoke(21 /* System.Int32 UnityEngine.EventSystems.BaseRaycaster::get_renderOrderPriority() */, __this);
		V_0 = L_17;
		String_t* L_18;
		L_18 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&V_0), NULL);
		NullCheck(L_16);
		ArrayElementTypeCheck (L_16, L_18);
		(L_16)->SetAt(static_cast<il2cpp_array_size_t>(7), (String_t*)L_18);
		String_t* L_19;
		L_19 = String_Concat_m647EBF831F54B6DF7D5AFA5FD012CF4EE7571B6A(L_16, NULL);
		V_1 = L_19;
		goto IL_007b;
	}

IL_007b:
	{
		// }
		String_t* L_20 = V_1;
		return L_20;
	}
}
// System.Void UnityEngine.EventSystems.BaseRaycaster::OnEnable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseRaycaster_OnEnable_m87CCF1ACD4116BB8BC0D9DB427F5B07C6FDE3D96 (BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// base.OnEnable();
		UIBehaviour_OnEnable_m8989ABF5C038905A68E5536BED2E6FFAF8767FFC(__this, NULL);
		// RaycasterManager.AddRaycaster(this);
		il2cpp_codegen_runtime_class_init_inline(RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_il2cpp_TypeInfo_var);
		RaycasterManager_AddRaycaster_mD2EE52F55FBDB3BEAAF583C4445D4D16B09B6350(__this, NULL);
		// }
		return;
	}
}
// System.Void UnityEngine.EventSystems.BaseRaycaster::OnDisable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseRaycaster_OnDisable_mC90A700D5F78DDAD0DD926983C2A8D7C50A5D880 (BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// RaycasterManager.RemoveRaycasters(this);
		il2cpp_codegen_runtime_class_init_inline(RaycasterManager_tE359EBDE4F0EF3681A6E3662B340AC4D53502074_il2cpp_TypeInfo_var);
		RaycasterManager_RemoveRaycasters_m0800E0ACE007AD43B62D10C1029EC85E7DE28999(__this, NULL);
		// base.OnDisable();
		UIBehaviour_OnDisable_m18D5A0B93F65FB50F4D6CE8197EC07F3452C5DDE(__this, NULL);
		// }
		return;
	}
}
// System.Void UnityEngine.EventSystems.BaseRaycaster::OnCanvasHierarchyChanged()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseRaycaster_OnCanvasHierarchyChanged_m20A82CFED659012D1F052C5026B8294B44D99BD7 (BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* __this, const RuntimeMethod* method) 
{
	{
		// base.OnCanvasHierarchyChanged();
		UIBehaviour_OnCanvasHierarchyChanged_mCAC018CB33FA00E857288B64E3722226638A1229(__this, NULL);
		// m_RootRaycaster = null;
		__this->___m_RootRaycaster_4 = (BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_RootRaycaster_4), (void*)(BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832*)NULL);
		// }
		return;
	}
}
// System.Void UnityEngine.EventSystems.BaseRaycaster::OnTransformParentChanged()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseRaycaster_OnTransformParentChanged_m121068CDDBC97032FF51C4ED944D4C126CB58F7F (BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* __this, const RuntimeMethod* method) 
{
	{
		// base.OnTransformParentChanged();
		UIBehaviour_OnTransformParentChanged_mAD56D3C6049A1746F00DC2643D1666F7DE921384(__this, NULL);
		// m_RootRaycaster = null;
		__this->___m_RootRaycaster_4 = (BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_RootRaycaster_4), (void*)(BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832*)NULL);
		// }
		return;
	}
}
// System.Void UnityEngine.EventSystems.BaseRaycaster::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseRaycaster__ctor_m1B6A963368E54C1E450BE15FAF1AE082142A1683 (BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* __this, const RuntimeMethod* method) 
{
	{
		UIBehaviour__ctor_m24C66A65DDD996E779871C6655CF11B871F11337(__this, NULL);
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
// System.Void UnityEngine.EventSystems.Physics2DRaycaster::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Physics2DRaycaster__ctor_mF2F12F2AF9DDCA74EB09349D038A67F3D3F88CF9 (Physics2DRaycaster_t8E0FE5BD8DC96C60EE4BA334B0607B63A69761A7* __this, const RuntimeMethod* method) 
{
	{
		// protected Physics2DRaycaster()
		PhysicsRaycaster__ctor_mB7D4BAC26DC219A10060B35498EE9D5F05AD0E80(__this, NULL);
		// {}
		return;
	}
}
// System.Void UnityEngine.EventSystems.Physics2DRaycaster::Raycast(UnityEngine.EventSystems.PointerEventData,System.Collections.Generic.List`1<UnityEngine.EventSystems.RaycastResult>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Physics2DRaycaster_Raycast_m9F6AA9C9DC7A34C01959F2053446D3FFCE567630 (Physics2DRaycaster_t8E0FE5BD8DC96C60EE4BA334B0607B63A69761A7* __this, PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* ___0_eventData, List_1_t8292C421BBB00D7661DC07462822936152BAB446* ___1_resultAppendList, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_m026EB44DB6238F13E2AFBECF1FBBE924CB1B040A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mEB6DFEA132B5B7BF540D34177054003185D250E7_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_mE2EBEDC861C1EC398EDBE6CF2C9FB604AA71523E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpriteRenderer_t1DD7FE258F072E1FA87D6577BA27225892B8047B_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpriteShapeRenderer_tE998BB73CF661079736CCC23617E597AB230A4AC_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TilemapRenderer_t1A45FD335E86172CFBB77D657E1D6705A477A6CB_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 V_0;
	memset((&V_0), 0, sizeof(V_0));
	float V_1 = 0.0f;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	bool V_4 = false;
	bool V_5 = false;
	bool V_6 = false;
	bool V_7 = false;
	bool V_8 = false;
	bool V_9 = false;
	int32_t V_10 = 0;
	int32_t V_11 = 0;
	Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* V_12 = NULL;
	Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* V_13 = NULL;
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 V_14;
	memset((&V_14), 0, sizeof(V_14));
	SortingGroup_tA8DA95BF22F76688DAF54122EB3EEA35C70E9759* V_15 = NULL;
	bool V_16 = false;
	bool V_17 = false;
	bool V_18 = false;
	bool V_19 = false;
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 V_20;
	memset((&V_20), 0, sizeof(V_20));
	bool V_21 = false;
	bool V_22 = false;
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* G_B23_0 = NULL;
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* G_B22_0 = NULL;
	int32_t G_B24_0 = 0;
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* G_B24_1 = NULL;
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* G_B26_0 = NULL;
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* G_B25_0 = NULL;
	int32_t G_B27_0 = 0;
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* G_B27_1 = NULL;
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* G_B29_0 = NULL;
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* G_B28_0 = NULL;
	int32_t G_B30_0 = 0;
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* G_B30_1 = NULL;
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* G_B32_0 = NULL;
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* G_B31_0 = NULL;
	int32_t G_B33_0 = 0;
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* G_B33_1 = NULL;
	int32_t G_B36_0 = 0;
	{
		// Ray ray = new Ray();
		il2cpp_codegen_initobj((&V_0), sizeof(Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00));
		// float distanceToClipPlane = 0;
		V_1 = (0.0f);
		// int displayIndex = 0;
		V_2 = 0;
		// if (!ComputeRayAndDistance(eventData, ref ray, ref displayIndex, ref distanceToClipPlane))
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_0 = ___0_eventData;
		bool L_1;
		L_1 = PhysicsRaycaster_ComputeRayAndDistance_mCFEFA9D83EC1E63393454E383FFFEF89E14C173B(__this, L_0, (&V_0), (&V_2), (&V_1), NULL);
		V_4 = (bool)((((int32_t)L_1) == ((int32_t)0))? 1 : 0);
		bool L_2 = V_4;
		if (!L_2)
		{
			goto IL_002c;
		}
	}
	{
		// return;
		goto IL_0342;
	}

IL_002c:
	{
		// int hitCount = 0;
		V_3 = 0;
		// if (maxRayIntersections == 0)
		int32_t L_3;
		L_3 = PhysicsRaycaster_get_maxRayIntersections_mA06D0B5E291BCF94AE1EF4ED7B68890F39395911(__this, NULL);
		V_5 = (bool)((((int32_t)L_3) == ((int32_t)0))? 1 : 0);
		bool L_4 = V_5;
		if (!L_4)
		{
			goto IL_007f;
		}
	}
	{
		// if (ReflectionMethodsCache.Singleton.getRayIntersectionAll == null)
		ReflectionMethodsCache_t711B47CE11EA2092B94127FF8D3361AE2E4859F5* L_5;
		L_5 = ReflectionMethodsCache_get_Singleton_m77EFD7AC0043333E09987BD601113B810453C42B(NULL);
		NullCheck(L_5);
		GetRayIntersectionAllCallback_t52E7AE4ECEA3F9744FF7F8448F852C872A70315C* L_6 = L_5->___getRayIntersectionAll_4;
		V_6 = (bool)((((RuntimeObject*)(GetRayIntersectionAllCallback_t52E7AE4ECEA3F9744FF7F8448F852C872A70315C*)L_6) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_7 = V_6;
		if (!L_7)
		{
			goto IL_0056;
		}
	}
	{
		// return;
		goto IL_0342;
	}

IL_0056:
	{
		// m_Hits = ReflectionMethodsCache.Singleton.getRayIntersectionAll(ray, distanceToClipPlane, finalEventMask);
		ReflectionMethodsCache_t711B47CE11EA2092B94127FF8D3361AE2E4859F5* L_8;
		L_8 = ReflectionMethodsCache_get_Singleton_m77EFD7AC0043333E09987BD601113B810453C42B(NULL);
		NullCheck(L_8);
		GetRayIntersectionAllCallback_t52E7AE4ECEA3F9744FF7F8448F852C872A70315C* L_9 = L_8->___getRayIntersectionAll_4;
		Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 L_10 = V_0;
		float L_11 = V_1;
		int32_t L_12;
		L_12 = PhysicsRaycaster_get_finalEventMask_m20AD2327FE81B38A5853B23970A587EAA2ECCB1B(__this, NULL);
		NullCheck(L_9);
		RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7* L_13;
		L_13 = GetRayIntersectionAllCallback_Invoke_m917AA4108EBDC724AFEF39BFD06A586B7461F497_inline(L_9, L_10, L_11, L_12, NULL);
		__this->___m_Hits_11 = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Hits_11), (void*)L_13);
		// hitCount = m_Hits.Length;
		RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7* L_14 = __this->___m_Hits_11;
		NullCheck(L_14);
		V_3 = ((int32_t)(((RuntimeArray*)L_14)->max_length));
		goto IL_00ed;
	}

IL_007f:
	{
		// if (ReflectionMethodsCache.Singleton.getRayIntersectionAllNonAlloc == null)
		ReflectionMethodsCache_t711B47CE11EA2092B94127FF8D3361AE2E4859F5* L_15;
		L_15 = ReflectionMethodsCache_get_Singleton_m77EFD7AC0043333E09987BD601113B810453C42B(NULL);
		NullCheck(L_15);
		GetRayIntersectionAllNonAllocCallback_t28D7ACEBBE525DE0CBEA67986E4C3891D694F980* L_16 = L_15->___getRayIntersectionAllNonAlloc_5;
		V_7 = (bool)((((RuntimeObject*)(GetRayIntersectionAllNonAllocCallback_t28D7ACEBBE525DE0CBEA67986E4C3891D694F980*)L_16) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_17 = V_7;
		if (!L_17)
		{
			goto IL_0098;
		}
	}
	{
		// return;
		goto IL_0342;
	}

IL_0098:
	{
		// if (m_LastMaxRayIntersections != m_MaxRayIntersections)
		int32_t L_18 = ((PhysicsRaycaster_t0ACA9046D8D0B195B59DB1F7CA4DD6BB634A56DD*)__this)->___m_LastMaxRayIntersections_9;
		int32_t L_19 = ((PhysicsRaycaster_t0ACA9046D8D0B195B59DB1F7CA4DD6BB634A56DD*)__this)->___m_MaxRayIntersections_8;
		V_8 = (bool)((((int32_t)((((int32_t)L_18) == ((int32_t)L_19))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_20 = V_8;
		if (!L_20)
		{
			goto IL_00ce;
		}
	}
	{
		// m_Hits = new RaycastHit2D[maxRayIntersections];
		int32_t L_21;
		L_21 = PhysicsRaycaster_get_maxRayIntersections_mA06D0B5E291BCF94AE1EF4ED7B68890F39395911(__this, NULL);
		RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7* L_22 = (RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7*)(RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7*)SZArrayNew(RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7_il2cpp_TypeInfo_var, (uint32_t)L_21);
		__this->___m_Hits_11 = L_22;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Hits_11), (void*)L_22);
		// m_LastMaxRayIntersections = m_MaxRayIntersections;
		int32_t L_23 = ((PhysicsRaycaster_t0ACA9046D8D0B195B59DB1F7CA4DD6BB634A56DD*)__this)->___m_MaxRayIntersections_8;
		((PhysicsRaycaster_t0ACA9046D8D0B195B59DB1F7CA4DD6BB634A56DD*)__this)->___m_LastMaxRayIntersections_9 = L_23;
	}

IL_00ce:
	{
		// hitCount = ReflectionMethodsCache.Singleton.getRayIntersectionAllNonAlloc(ray, m_Hits, distanceToClipPlane, finalEventMask);
		ReflectionMethodsCache_t711B47CE11EA2092B94127FF8D3361AE2E4859F5* L_24;
		L_24 = ReflectionMethodsCache_get_Singleton_m77EFD7AC0043333E09987BD601113B810453C42B(NULL);
		NullCheck(L_24);
		GetRayIntersectionAllNonAllocCallback_t28D7ACEBBE525DE0CBEA67986E4C3891D694F980* L_25 = L_24->___getRayIntersectionAllNonAlloc_5;
		Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 L_26 = V_0;
		RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7* L_27 = __this->___m_Hits_11;
		float L_28 = V_1;
		int32_t L_29;
		L_29 = PhysicsRaycaster_get_finalEventMask_m20AD2327FE81B38A5853B23970A587EAA2ECCB1B(__this, NULL);
		NullCheck(L_25);
		int32_t L_30;
		L_30 = GetRayIntersectionAllNonAllocCallback_Invoke_mFAA36E9AF362DC72204EEF53B28DBFC3367D09A7_inline(L_25, L_26, L_27, L_28, L_29, NULL);
		V_3 = L_30;
	}

IL_00ed:
	{
		// if (hitCount != 0)
		int32_t L_31 = V_3;
		V_9 = (bool)((!(((uint32_t)L_31) <= ((uint32_t)0)))? 1 : 0);
		bool L_32 = V_9;
		if (!L_32)
		{
			goto IL_0342;
		}
	}
	{
		// for (int b = 0, bmax = hitCount; b < bmax; ++b)
		V_10 = 0;
		// for (int b = 0, bmax = hitCount; b < bmax; ++b)
		int32_t L_33 = V_3;
		V_11 = L_33;
		goto IL_0332;
	}

IL_0106:
	{
		// Renderer r2d = null;
		V_12 = (Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF*)NULL;
		// var rendererResult = m_Hits[b].collider.gameObject.GetComponent<Renderer>();
		RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7* L_34 = __this->___m_Hits_11;
		int32_t L_35 = V_10;
		NullCheck(L_34);
		Collider2D_t6A17BA7734600EF3F26588E9ED903617D5B8EB52* L_36;
		L_36 = RaycastHit2D_get_collider_mB56DFCD16B708852EEBDBB490BC8665DBF7487FD(((L_34)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_35))), NULL);
		NullCheck(L_36);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_37;
		L_37 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_36, NULL);
		NullCheck(L_37);
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_38;
		L_38 = GameObject_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_m026EB44DB6238F13E2AFBECF1FBBE924CB1B040A(L_37, GameObject_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_m026EB44DB6238F13E2AFBECF1FBBE924CB1B040A_RuntimeMethod_var);
		V_13 = L_38;
		// if (rendererResult != null)
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_39 = V_13;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_40;
		L_40 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_39, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		V_16 = L_40;
		bool L_41 = V_16;
		if (!L_41)
		{
			goto IL_017a;
		}
	}
	{
		// if (rendererResult is SpriteRenderer)
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_42 = V_13;
		V_17 = (bool)((!(((RuntimeObject*)(SpriteRenderer_t1DD7FE258F072E1FA87D6577BA27225892B8047B*)((SpriteRenderer_t1DD7FE258F072E1FA87D6577BA27225892B8047B*)IsInstSealed((RuntimeObject*)L_42, SpriteRenderer_t1DD7FE258F072E1FA87D6577BA27225892B8047B_il2cpp_TypeInfo_var))) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		bool L_43 = V_17;
		if (!L_43)
		{
			goto IL_014d;
		}
	}
	{
		// r2d = rendererResult;
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_44 = V_13;
		V_12 = L_44;
	}

IL_014d:
	{
		// if (rendererResult is TilemapRenderer)
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_45 = V_13;
		V_18 = (bool)((!(((RuntimeObject*)(TilemapRenderer_t1A45FD335E86172CFBB77D657E1D6705A477A6CB*)((TilemapRenderer_t1A45FD335E86172CFBB77D657E1D6705A477A6CB*)IsInstSealed((RuntimeObject*)L_45, TilemapRenderer_t1A45FD335E86172CFBB77D657E1D6705A477A6CB_il2cpp_TypeInfo_var))) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		bool L_46 = V_18;
		if (!L_46)
		{
			goto IL_0163;
		}
	}
	{
		// r2d = rendererResult;
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_47 = V_13;
		V_12 = L_47;
	}

IL_0163:
	{
		// if (rendererResult is SpriteShapeRenderer)
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_48 = V_13;
		V_19 = (bool)((!(((RuntimeObject*)(SpriteShapeRenderer_tE998BB73CF661079736CCC23617E597AB230A4AC*)((SpriteShapeRenderer_tE998BB73CF661079736CCC23617E597AB230A4AC*)IsInstClass((RuntimeObject*)L_48, SpriteShapeRenderer_tE998BB73CF661079736CCC23617E597AB230A4AC_il2cpp_TypeInfo_var))) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		bool L_49 = V_19;
		if (!L_49)
		{
			goto IL_0179;
		}
	}
	{
		// r2d = rendererResult;
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_50 = V_13;
		V_12 = L_50;
	}

IL_0179:
	{
	}

IL_017a:
	{
		// var result = new RaycastResult
		// {
		//     gameObject = m_Hits[b].collider.gameObject,
		//     module = this,
		//     distance = Vector3.Distance(eventCamera.transform.position, m_Hits[b].point),
		//     worldPosition = m_Hits[b].point,
		//     worldNormal = m_Hits[b].normal,
		//     screenPosition = eventData.position,
		//     displayIndex = displayIndex,
		//     index = resultAppendList.Count,
		//     sortingGroupID = r2d != null ? r2d.sortingGroupID : SortingGroup.invalidSortingGroupID,
		//     sortingGroupOrder = r2d != null ? r2d.sortingGroupOrder : 0,
		//     sortingLayer = r2d != null ? r2d.sortingLayerID : 0,
		//     sortingOrder = r2d != null ? r2d.sortingOrder : 0
		// };
		il2cpp_codegen_initobj((&V_20), sizeof(RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023));
		RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7* L_51 = __this->___m_Hits_11;
		int32_t L_52 = V_10;
		NullCheck(L_51);
		Collider2D_t6A17BA7734600EF3F26588E9ED903617D5B8EB52* L_53;
		L_53 = RaycastHit2D_get_collider_mB56DFCD16B708852EEBDBB490BC8665DBF7487FD(((L_51)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_52))), NULL);
		NullCheck(L_53);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_54;
		L_54 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_53, NULL);
		RaycastResult_set_gameObject_mCFEB66C0E3F01AC5E55040FE8BEB16E40427BD9E((&V_20), L_54, NULL);
		(&V_20)->___module_1 = __this;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_20)->___module_1), (void*)__this);
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_55;
		L_55 = VirtualFuncInvoker0< Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* >::Invoke(18 /* UnityEngine.Camera UnityEngine.EventSystems.BaseRaycaster::get_eventCamera() */, __this);
		NullCheck(L_55);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_56;
		L_56 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(L_55, NULL);
		NullCheck(L_56);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_57;
		L_57 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_56, NULL);
		RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7* L_58 = __this->___m_Hits_11;
		int32_t L_59 = V_10;
		NullCheck(L_58);
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_60;
		L_60 = RaycastHit2D_get_point_mB35E988E9E04328EFE926228A18334326721A36B(((L_58)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_59))), NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_61;
		L_61 = Vector2_op_Implicit_m6D9CABB2C791A192867D7A4559D132BE86DD3EB7_inline(L_60, NULL);
		float L_62;
		L_62 = Vector3_Distance_m2314DB9B8BD01157E013DF87BEA557375C7F9FF9_inline(L_57, L_61, NULL);
		(&V_20)->___distance_2 = L_62;
		RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7* L_63 = __this->___m_Hits_11;
		int32_t L_64 = V_10;
		NullCheck(L_63);
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_65;
		L_65 = RaycastHit2D_get_point_mB35E988E9E04328EFE926228A18334326721A36B(((L_63)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_64))), NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_66;
		L_66 = Vector2_op_Implicit_m6D9CABB2C791A192867D7A4559D132BE86DD3EB7_inline(L_65, NULL);
		(&V_20)->___worldPosition_9 = L_66;
		RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7* L_67 = __this->___m_Hits_11;
		int32_t L_68 = V_10;
		NullCheck(L_67);
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_69;
		L_69 = RaycastHit2D_get_normal_m75F1EBDE347BACEB5A6A6AA72543C740806AB5F2(((L_67)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_68))), NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_70;
		L_70 = Vector2_op_Implicit_m6D9CABB2C791A192867D7A4559D132BE86DD3EB7_inline(L_69, NULL);
		(&V_20)->___worldNormal_10 = L_70;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_71 = ___0_eventData;
		NullCheck(L_71);
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_72;
		L_72 = PointerEventData_get_position_m5BE71C28EB72EFB8435749E4E6E839213AEF458C_inline(L_71, NULL);
		(&V_20)->___screenPosition_11 = L_72;
		int32_t L_73 = V_2;
		(&V_20)->___displayIndex_12 = L_73;
		List_1_t8292C421BBB00D7661DC07462822936152BAB446* L_74 = ___1_resultAppendList;
		NullCheck(L_74);
		int32_t L_75;
		L_75 = List_1_get_Count_mE2EBEDC861C1EC398EDBE6CF2C9FB604AA71523E_inline(L_74, List_1_get_Count_mE2EBEDC861C1EC398EDBE6CF2C9FB604AA71523E_RuntimeMethod_var);
		(&V_20)->___index_3 = ((float)L_75);
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_76 = V_12;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_77;
		L_77 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_76, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		G_B22_0 = (&V_20);
		if (L_77)
		{
			G_B23_0 = (&V_20);
			goto IL_024e;
		}
	}
	{
		int32_t L_78;
		L_78 = SortingGroup_get_invalidSortingGroupID_mEA453186185B225FA2410988959180BAEC604310(NULL);
		G_B24_0 = L_78;
		G_B24_1 = G_B22_0;
		goto IL_0255;
	}

IL_024e:
	{
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_79 = V_12;
		NullCheck(L_79);
		int32_t L_80;
		L_80 = Renderer_get_sortingGroupID_m1DEFE39027236FF31AB603993BBC13C072E52118(L_79, NULL);
		G_B24_0 = L_80;
		G_B24_1 = G_B23_0;
	}

IL_0255:
	{
		G_B24_1->___sortingGroupID_5 = G_B24_0;
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_81 = V_12;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_82;
		L_82 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_81, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		G_B25_0 = (&V_20);
		if (L_82)
		{
			G_B26_0 = (&V_20);
			goto IL_0269;
		}
	}
	{
		G_B27_0 = 0;
		G_B27_1 = G_B25_0;
		goto IL_0270;
	}

IL_0269:
	{
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_83 = V_12;
		NullCheck(L_83);
		int32_t L_84;
		L_84 = Renderer_get_sortingGroupOrder_m40F058B3AFC92CCEF2475E0BD9A96464154E999E(L_83, NULL);
		G_B27_0 = L_84;
		G_B27_1 = G_B26_0;
	}

IL_0270:
	{
		G_B27_1->___sortingGroupOrder_6 = G_B27_0;
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_85 = V_12;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_86;
		L_86 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_85, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		G_B28_0 = (&V_20);
		if (L_86)
		{
			G_B29_0 = (&V_20);
			goto IL_0284;
		}
	}
	{
		G_B30_0 = 0;
		G_B30_1 = G_B28_0;
		goto IL_028b;
	}

IL_0284:
	{
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_87 = V_12;
		NullCheck(L_87);
		int32_t L_88;
		L_88 = Renderer_get_sortingLayerID_m3D7AE74F1B87099810CF969CB4520C85F9AE5F92(L_87, NULL);
		G_B30_0 = L_88;
		G_B30_1 = G_B29_0;
	}

IL_028b:
	{
		G_B30_1->___sortingLayer_7 = G_B30_0;
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_89 = V_12;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_90;
		L_90 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_89, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		G_B31_0 = (&V_20);
		if (L_90)
		{
			G_B32_0 = (&V_20);
			goto IL_029f;
		}
	}
	{
		G_B33_0 = 0;
		G_B33_1 = G_B31_0;
		goto IL_02a6;
	}

IL_029f:
	{
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_91 = V_12;
		NullCheck(L_91);
		int32_t L_92;
		L_92 = Renderer_get_sortingOrder_m4CE7ADEEC8E2F28CC1D10B1D4091A10F8F1583FA(L_91, NULL);
		G_B33_0 = L_92;
		G_B33_1 = G_B32_0;
	}

IL_02a6:
	{
		G_B33_1->___sortingOrder_8 = G_B33_0;
		RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 L_93 = V_20;
		V_14 = L_93;
		// if (result.sortingGroupID != SortingGroup.invalidSortingGroupID &&
		//     SortingGroup.GetSortingGroupByIndex(r2d.sortingGroupID) is SortingGroup sortingGroup)
		RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 L_94 = V_14;
		int32_t L_95 = L_94.___sortingGroupID_5;
		int32_t L_96;
		L_96 = SortingGroup_get_invalidSortingGroupID_mEA453186185B225FA2410988959180BAEC604310(NULL);
		if ((((int32_t)L_95) == ((int32_t)L_96)))
		{
			goto IL_02d2;
		}
	}
	{
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_97 = V_12;
		NullCheck(L_97);
		int32_t L_98;
		L_98 = Renderer_get_sortingGroupID_m1DEFE39027236FF31AB603993BBC13C072E52118(L_97, NULL);
		SortingGroup_tA8DA95BF22F76688DAF54122EB3EEA35C70E9759* L_99;
		L_99 = SortingGroup_GetSortingGroupByIndex_mC4CFB06D8C4B0EA27FC4BDC60AA05F4E0B28426B(L_98, NULL);
		V_15 = L_99;
		SortingGroup_tA8DA95BF22F76688DAF54122EB3EEA35C70E9759* L_100 = V_15;
		G_B36_0 = ((!(((RuntimeObject*)(SortingGroup_tA8DA95BF22F76688DAF54122EB3EEA35C70E9759*)L_100) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		goto IL_02d3;
	}

IL_02d2:
	{
		G_B36_0 = 0;
	}

IL_02d3:
	{
		V_21 = (bool)G_B36_0;
		bool L_101 = V_21;
		if (!L_101)
		{
			goto IL_0322;
		}
	}
	{
		// result.distance = Vector3.Dot(ray.direction, sortingGroup.transform.position - ray.origin);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_102;
		L_102 = Ray_get_direction_m21C2D22D3BD4A683BD4DC191AB22DD05F5EC2086((&V_0), NULL);
		SortingGroup_tA8DA95BF22F76688DAF54122EB3EEA35C70E9759* L_103 = V_15;
		NullCheck(L_103);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_104;
		L_104 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(L_103, NULL);
		NullCheck(L_104);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_105;
		L_105 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_104, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_106;
		L_106 = Ray_get_origin_m97604A8F180316A410DCD77B7D74D04522FA1BA6((&V_0), NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_107;
		L_107 = Vector3_op_Subtraction_mE42023FF80067CB44A1D4A27EB7CF2B24CABB828_inline(L_105, L_106, NULL);
		float L_108;
		L_108 = Vector3_Dot_mBB86BB940AA0A32FA7D3C02AC42E5BC7095A5D52_inline(L_102, L_107, NULL);
		(&V_14)->___distance_2 = L_108;
		// result.sortingLayer = sortingGroup.sortingLayerID;
		SortingGroup_tA8DA95BF22F76688DAF54122EB3EEA35C70E9759* L_109 = V_15;
		NullCheck(L_109);
		int32_t L_110;
		L_110 = SortingGroup_get_sortingLayerID_m37C70CEA78DA6E28F405C67EDE95D5C2191F0055(L_109, NULL);
		(&V_14)->___sortingLayer_7 = L_110;
		// result.sortingOrder = sortingGroup.sortingOrder;
		SortingGroup_tA8DA95BF22F76688DAF54122EB3EEA35C70E9759* L_111 = V_15;
		NullCheck(L_111);
		int32_t L_112;
		L_112 = SortingGroup_get_sortingOrder_mC80606E6BB9A6D5E3AB61A0451C48203A0C1AB6A(L_111, NULL);
		(&V_14)->___sortingOrder_8 = L_112;
	}

IL_0322:
	{
		// resultAppendList.Add(result);
		List_1_t8292C421BBB00D7661DC07462822936152BAB446* L_113 = ___1_resultAppendList;
		RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 L_114 = V_14;
		NullCheck(L_113);
		List_1_Add_mEB6DFEA132B5B7BF540D34177054003185D250E7_inline(L_113, L_114, List_1_Add_mEB6DFEA132B5B7BF540D34177054003185D250E7_RuntimeMethod_var);
		// for (int b = 0, bmax = hitCount; b < bmax; ++b)
		int32_t L_115 = V_10;
		V_10 = ((int32_t)il2cpp_codegen_add(L_115, 1));
	}

IL_0332:
	{
		// for (int b = 0, bmax = hitCount; b < bmax; ++b)
		int32_t L_116 = V_10;
		int32_t L_117 = V_11;
		V_22 = (bool)((((int32_t)L_116) < ((int32_t)L_117))? 1 : 0);
		bool L_118 = V_22;
		if (L_118)
		{
			goto IL_0106;
		}
	}
	{
	}

IL_0342:
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
// System.Void UnityEngine.EventSystems.PhysicsRaycaster::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PhysicsRaycaster__ctor_mB7D4BAC26DC219A10060B35498EE9D5F05AD0E80 (PhysicsRaycaster_t0ACA9046D8D0B195B59DB1F7CA4DD6BB634A56DD* __this, const RuntimeMethod* method) 
{
	{
		// protected LayerMask m_EventMask = kNoEventMaskSet;
		LayerMask_t97CB6BDADEDC3D6423C7BCFEA7F86DA2EC6241DB L_0;
		L_0 = LayerMask_op_Implicit_m01C8996A2CB2085328B9C33539C43139660D8222((-1), NULL);
		__this->___m_EventMask_7 = L_0;
		// protected int m_MaxRayIntersections = 0;
		__this->___m_MaxRayIntersections_8 = 0;
		// protected int m_LastMaxRayIntersections = 0;
		__this->___m_LastMaxRayIntersections_9 = 0;
		// protected PhysicsRaycaster()
		BaseRaycaster__ctor_m1B6A963368E54C1E450BE15FAF1AE082142A1683(__this, NULL);
		// {}
		return;
	}
}
// UnityEngine.Camera UnityEngine.EventSystems.PhysicsRaycaster::get_eventCamera()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* PhysicsRaycaster_get_eventCamera_m95026618116D1781A906DDE4AF9C415F2374013C (PhysicsRaycaster_t0ACA9046D8D0B195B59DB1F7CA4DD6BB634A56DD* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisCamera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184_m64AC6C06DD93C5FB249091FEC84FA8475457CCC4_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* V_1 = NULL;
	Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* G_B4_0 = NULL;
	Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* G_B3_0 = NULL;
	{
		// if (m_EventCamera == null)
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_0 = __this->___m_EventCamera_6;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		V_0 = L_1;
		bool L_2 = V_0;
		if (!L_2)
		{
			goto IL_001d;
		}
	}
	{
		// m_EventCamera = GetComponent<Camera>();
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_3;
		L_3 = Component_GetComponent_TisCamera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184_m64AC6C06DD93C5FB249091FEC84FA8475457CCC4(__this, Component_GetComponent_TisCamera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184_m64AC6C06DD93C5FB249091FEC84FA8475457CCC4_RuntimeMethod_var);
		__this->___m_EventCamera_6 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_EventCamera_6), (void*)L_3);
	}

IL_001d:
	{
		// return m_EventCamera ?? Camera.main;
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_4 = __this->___m_EventCamera_6;
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_5 = L_4;
		G_B3_0 = L_5;
		if (L_5)
		{
			G_B4_0 = L_5;
			goto IL_002c;
		}
	}
	{
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_6;
		L_6 = Camera_get_main_m52C992F18E05355ABB9EEB64A4BF2215E12762DF(NULL);
		G_B4_0 = L_6;
	}

IL_002c:
	{
		V_1 = G_B4_0;
		goto IL_002f;
	}

IL_002f:
	{
		// }
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_7 = V_1;
		return L_7;
	}
}
// System.Int32 UnityEngine.EventSystems.PhysicsRaycaster::get_depth()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t PhysicsRaycaster_get_depth_mCC2E924588088DB1DCA160765C09734D3C4F7F60 (PhysicsRaycaster_t0ACA9046D8D0B195B59DB1F7CA4DD6BB634A56DD* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t G_B3_0 = 0;
	{
		// get { return (eventCamera != null) ? (int)eventCamera.depth : 0xFFFFFF; }
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_0;
		L_0 = VirtualFuncInvoker0< Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* >::Invoke(18 /* UnityEngine.Camera UnityEngine.EventSystems.BaseRaycaster::get_eventCamera() */, __this);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (L_1)
		{
			goto IL_0016;
		}
	}
	{
		G_B3_0 = ((int32_t)16777215);
		goto IL_0022;
	}

IL_0016:
	{
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_2;
		L_2 = VirtualFuncInvoker0< Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* >::Invoke(18 /* UnityEngine.Camera UnityEngine.EventSystems.BaseRaycaster::get_eventCamera() */, __this);
		NullCheck(L_2);
		float L_3;
		L_3 = Camera_get_depth_mDF67FFF8ED61750467DFC4C6D8F236850AD1BB1D(L_2, NULL);
		G_B3_0 = il2cpp_codegen_cast_double_to_int<int32_t>(L_3);
	}

IL_0022:
	{
		V_0 = G_B3_0;
		goto IL_0025;
	}

IL_0025:
	{
		// get { return (eventCamera != null) ? (int)eventCamera.depth : 0xFFFFFF; }
		int32_t L_4 = V_0;
		return L_4;
	}
}
// System.Int32 UnityEngine.EventSystems.PhysicsRaycaster::get_finalEventMask()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t PhysicsRaycaster_get_finalEventMask_m20AD2327FE81B38A5853B23970A587EAA2ECCB1B (PhysicsRaycaster_t0ACA9046D8D0B195B59DB1F7CA4DD6BB634A56DD* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t G_B3_0 = 0;
	{
		// get { return (eventCamera != null) ? eventCamera.cullingMask & m_EventMask : kNoEventMaskSet; }
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_0;
		L_0 = VirtualFuncInvoker0< Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* >::Invoke(18 /* UnityEngine.Camera UnityEngine.EventSystems.BaseRaycaster::get_eventCamera() */, __this);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (L_1)
		{
			goto IL_0012;
		}
	}
	{
		G_B3_0 = (-1);
		goto IL_0029;
	}

IL_0012:
	{
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_2;
		L_2 = VirtualFuncInvoker0< Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* >::Invoke(18 /* UnityEngine.Camera UnityEngine.EventSystems.BaseRaycaster::get_eventCamera() */, __this);
		NullCheck(L_2);
		int32_t L_3;
		L_3 = Camera_get_cullingMask_m6F5AFF8FB522F876D99E839BF77D8F27F26A1EF8(L_2, NULL);
		LayerMask_t97CB6BDADEDC3D6423C7BCFEA7F86DA2EC6241DB L_4 = __this->___m_EventMask_7;
		int32_t L_5;
		L_5 = LayerMask_op_Implicit_m7F5A5B9D079281AC445ED39DEE1FCFA9D795810D(L_4, NULL);
		G_B3_0 = ((int32_t)(L_3&L_5));
	}

IL_0029:
	{
		V_0 = G_B3_0;
		goto IL_002c;
	}

IL_002c:
	{
		// get { return (eventCamera != null) ? eventCamera.cullingMask & m_EventMask : kNoEventMaskSet; }
		int32_t L_6 = V_0;
		return L_6;
	}
}
// UnityEngine.LayerMask UnityEngine.EventSystems.PhysicsRaycaster::get_eventMask()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR LayerMask_t97CB6BDADEDC3D6423C7BCFEA7F86DA2EC6241DB PhysicsRaycaster_get_eventMask_mA8FE3884CD425BD59BD22784F4D5219159426DB9 (PhysicsRaycaster_t0ACA9046D8D0B195B59DB1F7CA4DD6BB634A56DD* __this, const RuntimeMethod* method) 
{
	LayerMask_t97CB6BDADEDC3D6423C7BCFEA7F86DA2EC6241DB V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		// get { return m_EventMask; }
		LayerMask_t97CB6BDADEDC3D6423C7BCFEA7F86DA2EC6241DB L_0 = __this->___m_EventMask_7;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		// get { return m_EventMask; }
		LayerMask_t97CB6BDADEDC3D6423C7BCFEA7F86DA2EC6241DB L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.EventSystems.PhysicsRaycaster::set_eventMask(UnityEngine.LayerMask)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PhysicsRaycaster_set_eventMask_mD5110BE565C7E3F1738369519D44587452CA056D (PhysicsRaycaster_t0ACA9046D8D0B195B59DB1F7CA4DD6BB634A56DD* __this, LayerMask_t97CB6BDADEDC3D6423C7BCFEA7F86DA2EC6241DB ___0_value, const RuntimeMethod* method) 
{
	{
		// set { m_EventMask = value; }
		LayerMask_t97CB6BDADEDC3D6423C7BCFEA7F86DA2EC6241DB L_0 = ___0_value;
		__this->___m_EventMask_7 = L_0;
		// set { m_EventMask = value; }
		return;
	}
}
// System.Int32 UnityEngine.EventSystems.PhysicsRaycaster::get_maxRayIntersections()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t PhysicsRaycaster_get_maxRayIntersections_mA06D0B5E291BCF94AE1EF4ED7B68890F39395911 (PhysicsRaycaster_t0ACA9046D8D0B195B59DB1F7CA4DD6BB634A56DD* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		// get { return m_MaxRayIntersections; }
		int32_t L_0 = __this->___m_MaxRayIntersections_8;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		// get { return m_MaxRayIntersections; }
		int32_t L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.EventSystems.PhysicsRaycaster::set_maxRayIntersections(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PhysicsRaycaster_set_maxRayIntersections_mECCF07932870A3B5C8875AE6204FC1ECB2CE01F7 (PhysicsRaycaster_t0ACA9046D8D0B195B59DB1F7CA4DD6BB634A56DD* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// set { m_MaxRayIntersections = value; }
		int32_t L_0 = ___0_value;
		__this->___m_MaxRayIntersections_8 = L_0;
		// set { m_MaxRayIntersections = value; }
		return;
	}
}
// System.Boolean UnityEngine.EventSystems.PhysicsRaycaster::ComputeRayAndDistance(UnityEngine.EventSystems.PointerEventData,UnityEngine.Ray&,System.Int32&,System.Single&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool PhysicsRaycaster_ComputeRayAndDistance_mCFEFA9D83EC1E63393454E383FFFEF89E14C173B (PhysicsRaycaster_t0ACA9046D8D0B195B59DB1F7CA4DD6BB634A56DD* __this, PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* ___0_eventData, Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00* ___1_ray, int32_t* ___2_eventDisplayIndex, float* ___3_distanceToClipPlane, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	float V_1 = 0.0f;
	bool V_2 = false;
	bool V_3 = false;
	bool V_4 = false;
	bool V_5 = false;
	bool V_6 = false;
	Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D V_7;
	memset((&V_7), 0, sizeof(V_7));
	float* G_B11_0 = NULL;
	float* G_B10_0 = NULL;
	float G_B12_0 = 0.0f;
	float* G_B12_1 = NULL;
	{
		// if (eventCamera == null)
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_0;
		L_0 = VirtualFuncInvoker0< Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* >::Invoke(18 /* UnityEngine.Camera UnityEngine.EventSystems.BaseRaycaster::get_eventCamera() */, __this);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		V_2 = L_1;
		bool L_2 = V_2;
		if (!L_2)
		{
			goto IL_0018;
		}
	}
	{
		// return false;
		V_3 = (bool)0;
		goto IL_00e8;
	}

IL_0018:
	{
		// var eventPosition = MultipleDisplayUtilities.RelativeMouseAtScaled(eventData.position);
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_3 = ___0_eventData;
		NullCheck(L_3);
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_4;
		L_4 = PointerEventData_get_position_m5BE71C28EB72EFB8435749E4E6E839213AEF458C_inline(L_3, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_5;
		L_5 = MultipleDisplayUtilities_RelativeMouseAtScaled_mE3B0EE3E697B4316CE8588D05F3A75E47A75A855(L_4, NULL);
		V_0 = L_5;
		// if (eventPosition != Vector3.zero)
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_6 = V_0;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_7;
		L_7 = Vector3_get_zero_m0C1249C3F25B1C70EAD3CC8B31259975A457AE39_inline(NULL);
		bool L_8;
		L_8 = Vector3_op_Inequality_m9F170CDFBF1E490E559DA5D06D6547501A402BBF_inline(L_6, L_7, NULL);
		V_4 = L_8;
		bool L_9 = V_4;
		if (!L_9)
		{
			goto IL_0061;
		}
	}
	{
		// eventDisplayIndex = (int)eventPosition.z;
		int32_t* L_10 = ___2_eventDisplayIndex;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_11 = V_0;
		float L_12 = L_11.___z_4;
		*((int32_t*)L_10) = (int32_t)il2cpp_codegen_cast_double_to_int<int32_t>(L_12);
		// if (eventDisplayIndex != eventCamera.targetDisplay)
		int32_t* L_13 = ___2_eventDisplayIndex;
		int32_t L_14 = *((int32_t*)L_13);
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_15;
		L_15 = VirtualFuncInvoker0< Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* >::Invoke(18 /* UnityEngine.Camera UnityEngine.EventSystems.BaseRaycaster::get_eventCamera() */, __this);
		NullCheck(L_15);
		int32_t L_16;
		L_16 = Camera_get_targetDisplay_m204A169C94EEABDB491FA5A77CC684146B10DF80(L_15, NULL);
		V_5 = (bool)((((int32_t)((((int32_t)L_14) == ((int32_t)L_16))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_17 = V_5;
		if (!L_17)
		{
			goto IL_005e;
		}
	}
	{
		// return false;
		V_3 = (bool)0;
		goto IL_00e8;
	}

IL_005e:
	{
		goto IL_006f;
	}

IL_0061:
	{
		// eventPosition = eventData.position;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_18 = ___0_eventData;
		NullCheck(L_18);
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_19;
		L_19 = PointerEventData_get_position_m5BE71C28EB72EFB8435749E4E6E839213AEF458C_inline(L_18, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_20;
		L_20 = Vector2_op_Implicit_m6D9CABB2C791A192867D7A4559D132BE86DD3EB7_inline(L_19, NULL);
		V_0 = L_20;
	}

IL_006f:
	{
		// if (!eventCamera.pixelRect.Contains(eventPosition))
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_21;
		L_21 = VirtualFuncInvoker0< Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* >::Invoke(18 /* UnityEngine.Camera UnityEngine.EventSystems.BaseRaycaster::get_eventCamera() */, __this);
		NullCheck(L_21);
		Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D L_22;
		L_22 = Camera_get_pixelRect_m5F40F5C324EB252261F66962411EE08CC4BE39E7(L_21, NULL);
		V_7 = L_22;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_23 = V_0;
		bool L_24;
		L_24 = Rect_Contains_mB1160CD465F3E9616AA4EED72AFFD611BD8D2B6B((&V_7), L_23, NULL);
		V_6 = (bool)((((int32_t)L_24) == ((int32_t)0))? 1 : 0);
		bool L_25 = V_6;
		if (!L_25)
		{
			goto IL_0091;
		}
	}
	{
		// return false;
		V_3 = (bool)0;
		goto IL_00e8;
	}

IL_0091:
	{
		// ray = eventCamera.ScreenPointToRay(eventPosition);
		Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00* L_26 = ___1_ray;
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_27;
		L_27 = VirtualFuncInvoker0< Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* >::Invoke(18 /* UnityEngine.Camera UnityEngine.EventSystems.BaseRaycaster::get_eventCamera() */, __this);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_28 = V_0;
		NullCheck(L_27);
		Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 L_29;
		L_29 = Camera_ScreenPointToRay_m2887B9A49880B7AB670C57D66B67D6A6689FE315(L_27, L_28, NULL);
		*(Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00*)L_26 = L_29;
		// float projectionDirection = ray.direction.z;
		Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00* L_30 = ___1_ray;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_31;
		L_31 = Ray_get_direction_m21C2D22D3BD4A683BD4DC191AB22DD05F5EC2086(L_30, NULL);
		float L_32 = L_31.___z_4;
		V_1 = L_32;
		// distanceToClipPlane = Mathf.Approximately(0.0f, projectionDirection)
		//     ? Mathf.Infinity
		//     : Mathf.Abs((eventCamera.farClipPlane - eventCamera.nearClipPlane) / projectionDirection);
		float* L_33 = ___3_distanceToClipPlane;
		float L_34 = V_1;
		bool L_35;
		L_35 = Mathf_Approximately_m1DADD012A8FC82E11FB282501AE2EBBF9A77150B_inline((0.0f), L_34, NULL);
		G_B10_0 = L_33;
		if (L_35)
		{
			G_B11_0 = L_33;
			goto IL_00de;
		}
	}
	{
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_36;
		L_36 = VirtualFuncInvoker0< Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* >::Invoke(18 /* UnityEngine.Camera UnityEngine.EventSystems.BaseRaycaster::get_eventCamera() */, __this);
		NullCheck(L_36);
		float L_37;
		L_37 = Camera_get_farClipPlane_m1D7128B85B5DB866F75FBE8CEBA48335716B67BD(L_36, NULL);
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_38;
		L_38 = VirtualFuncInvoker0< Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* >::Invoke(18 /* UnityEngine.Camera UnityEngine.EventSystems.BaseRaycaster::get_eventCamera() */, __this);
		NullCheck(L_38);
		float L_39;
		L_39 = Camera_get_nearClipPlane_m5E8FAF84326E3192CB036BD29DCCDAF6A9861013(L_38, NULL);
		float L_40 = V_1;
		float L_41;
		L_41 = fabsf(((float)(((float)il2cpp_codegen_subtract(L_37, L_39))/L_40)));
		G_B12_0 = L_41;
		G_B12_1 = G_B10_0;
		goto IL_00e3;
	}

IL_00de:
	{
		G_B12_0 = (std::numeric_limits<float>::infinity());
		G_B12_1 = G_B11_0;
	}

IL_00e3:
	{
		*((float*)G_B12_1) = (float)G_B12_0;
		// return true;
		V_3 = (bool)1;
		goto IL_00e8;
	}

IL_00e8:
	{
		// }
		bool L_42 = V_3;
		return L_42;
	}
}
// System.Void UnityEngine.EventSystems.PhysicsRaycaster::Raycast(UnityEngine.EventSystems.PointerEventData,System.Collections.Generic.List`1<UnityEngine.EventSystems.RaycastResult>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PhysicsRaycaster_Raycast_mB29925EB33102E9BEAA76658F8A59CA666C78B1A (PhysicsRaycaster_t0ACA9046D8D0B195B59DB1F7CA4DD6BB634A56DD* __this, PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* ___0_eventData, List_1_t8292C421BBB00D7661DC07462822936152BAB446* ___1_resultAppendList, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Array_Sort_TisRaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5_mBF83A49E9B1F007DD08F7E076AF45D2AED7A45EB_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mEB6DFEA132B5B7BF540D34177054003185D250E7_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_mE2EBEDC861C1EC398EDBE6CF2C9FB604AA71523E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RaycastHitComparer_t8EF6567C19BE9FB575E01A10941FBF7DE3D3DDF1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	float V_2 = 0.0f;
	int32_t V_3 = 0;
	bool V_4 = false;
	bool V_5 = false;
	bool V_6 = false;
	bool V_7 = false;
	bool V_8 = false;
	bool V_9 = false;
	bool V_10 = false;
	int32_t V_11 = 0;
	int32_t V_12 = 0;
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 V_13;
	memset((&V_13), 0, sizeof(V_13));
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 V_14;
	memset((&V_14), 0, sizeof(V_14));
	bool V_15 = false;
	{
		// Ray ray = new Ray();
		il2cpp_codegen_initobj((&V_0), sizeof(Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00));
		// int displayIndex = 0;
		V_1 = 0;
		// float distanceToClipPlane = 0;
		V_2 = (0.0f);
		// if (!ComputeRayAndDistance(eventData, ref ray, ref displayIndex, ref distanceToClipPlane))
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_0 = ___0_eventData;
		bool L_1;
		L_1 = PhysicsRaycaster_ComputeRayAndDistance_mCFEFA9D83EC1E63393454E383FFFEF89E14C173B(__this, L_0, (&V_0), (&V_1), (&V_2), NULL);
		V_4 = (bool)((((int32_t)L_1) == ((int32_t)0))? 1 : 0);
		bool L_2 = V_4;
		if (!L_2)
		{
			goto IL_002c;
		}
	}
	{
		// return;
		goto IL_01f5;
	}

IL_002c:
	{
		// int hitCount = 0;
		V_3 = 0;
		// if (m_MaxRayIntersections == 0)
		int32_t L_3 = __this->___m_MaxRayIntersections_8;
		V_5 = (bool)((((int32_t)L_3) == ((int32_t)0))? 1 : 0);
		bool L_4 = V_5;
		if (!L_4)
		{
			goto IL_007f;
		}
	}
	{
		// if (ReflectionMethodsCache.Singleton.raycast3DAll == null)
		ReflectionMethodsCache_t711B47CE11EA2092B94127FF8D3361AE2E4859F5* L_5;
		L_5 = ReflectionMethodsCache_get_Singleton_m77EFD7AC0043333E09987BD601113B810453C42B(NULL);
		NullCheck(L_5);
		RaycastAllCallback_t4AFFDCDAA6F02DD74E1E2DE455BA011D82BED47A* L_6 = L_5->___raycast3DAll_1;
		V_6 = (bool)((((RuntimeObject*)(RaycastAllCallback_t4AFFDCDAA6F02DD74E1E2DE455BA011D82BED47A*)L_6) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_7 = V_6;
		if (!L_7)
		{
			goto IL_0056;
		}
	}
	{
		// return;
		goto IL_01f5;
	}

IL_0056:
	{
		// m_Hits = ReflectionMethodsCache.Singleton.raycast3DAll(ray, distanceToClipPlane, finalEventMask);
		ReflectionMethodsCache_t711B47CE11EA2092B94127FF8D3361AE2E4859F5* L_8;
		L_8 = ReflectionMethodsCache_get_Singleton_m77EFD7AC0043333E09987BD601113B810453C42B(NULL);
		NullCheck(L_8);
		RaycastAllCallback_t4AFFDCDAA6F02DD74E1E2DE455BA011D82BED47A* L_9 = L_8->___raycast3DAll_1;
		Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 L_10 = V_0;
		float L_11 = V_2;
		int32_t L_12;
		L_12 = PhysicsRaycaster_get_finalEventMask_m20AD2327FE81B38A5853B23970A587EAA2ECCB1B(__this, NULL);
		NullCheck(L_9);
		RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8* L_13;
		L_13 = RaycastAllCallback_Invoke_mB30319766AF5F0D5145A6C0AFFEA829A31A5D4B7_inline(L_9, L_10, L_11, L_12, NULL);
		__this->___m_Hits_10 = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Hits_10), (void*)L_13);
		// hitCount = m_Hits.Length;
		RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8* L_14 = __this->___m_Hits_10;
		NullCheck(L_14);
		V_3 = ((int32_t)(((RuntimeArray*)L_14)->max_length));
		goto IL_00ed;
	}

IL_007f:
	{
		// if (ReflectionMethodsCache.Singleton.getRaycastNonAlloc == null)
		ReflectionMethodsCache_t711B47CE11EA2092B94127FF8D3361AE2E4859F5* L_15;
		L_15 = ReflectionMethodsCache_get_Singleton_m77EFD7AC0043333E09987BD601113B810453C42B(NULL);
		NullCheck(L_15);
		GetRaycastNonAllocCallback_tC3DA6EE6063FE663DD0A9FC52439D825DE4A1FFC* L_16 = L_15->___getRaycastNonAlloc_2;
		V_7 = (bool)((((RuntimeObject*)(GetRaycastNonAllocCallback_tC3DA6EE6063FE663DD0A9FC52439D825DE4A1FFC*)L_16) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_17 = V_7;
		if (!L_17)
		{
			goto IL_0098;
		}
	}
	{
		// return;
		goto IL_01f5;
	}

IL_0098:
	{
		// if (m_LastMaxRayIntersections != m_MaxRayIntersections)
		int32_t L_18 = __this->___m_LastMaxRayIntersections_9;
		int32_t L_19 = __this->___m_MaxRayIntersections_8;
		V_8 = (bool)((((int32_t)((((int32_t)L_18) == ((int32_t)L_19))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_20 = V_8;
		if (!L_20)
		{
			goto IL_00ce;
		}
	}
	{
		// m_Hits = new RaycastHit[m_MaxRayIntersections];
		int32_t L_21 = __this->___m_MaxRayIntersections_8;
		RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8* L_22 = (RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8*)(RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8*)SZArrayNew(RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8_il2cpp_TypeInfo_var, (uint32_t)L_21);
		__this->___m_Hits_10 = L_22;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Hits_10), (void*)L_22);
		// m_LastMaxRayIntersections = m_MaxRayIntersections;
		int32_t L_23 = __this->___m_MaxRayIntersections_8;
		__this->___m_LastMaxRayIntersections_9 = L_23;
	}

IL_00ce:
	{
		// hitCount = ReflectionMethodsCache.Singleton.getRaycastNonAlloc(ray, m_Hits, distanceToClipPlane, finalEventMask);
		ReflectionMethodsCache_t711B47CE11EA2092B94127FF8D3361AE2E4859F5* L_24;
		L_24 = ReflectionMethodsCache_get_Singleton_m77EFD7AC0043333E09987BD601113B810453C42B(NULL);
		NullCheck(L_24);
		GetRaycastNonAllocCallback_tC3DA6EE6063FE663DD0A9FC52439D825DE4A1FFC* L_25 = L_24->___getRaycastNonAlloc_2;
		Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 L_26 = V_0;
		RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8* L_27 = __this->___m_Hits_10;
		float L_28 = V_2;
		int32_t L_29;
		L_29 = PhysicsRaycaster_get_finalEventMask_m20AD2327FE81B38A5853B23970A587EAA2ECCB1B(__this, NULL);
		NullCheck(L_25);
		int32_t L_30;
		L_30 = GetRaycastNonAllocCallback_Invoke_m36411365E9622819DAB93D0BB0F169FEE99F07D9_inline(L_25, L_26, L_27, L_28, L_29, NULL);
		V_3 = L_30;
	}

IL_00ed:
	{
		// if (hitCount != 0)
		int32_t L_31 = V_3;
		V_9 = (bool)((!(((uint32_t)L_31) <= ((uint32_t)0)))? 1 : 0);
		bool L_32 = V_9;
		if (!L_32)
		{
			goto IL_01f5;
		}
	}
	{
		// if (hitCount > 1)
		int32_t L_33 = V_3;
		V_10 = (bool)((((int32_t)L_33) > ((int32_t)1))? 1 : 0);
		bool L_34 = V_10;
		if (!L_34)
		{
			goto IL_0118;
		}
	}
	{
		// System.Array.Sort(m_Hits, 0, hitCount, RaycastHitComparer.instance);
		RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8* L_35 = __this->___m_Hits_10;
		int32_t L_36 = V_3;
		il2cpp_codegen_runtime_class_init_inline(RaycastHitComparer_t8EF6567C19BE9FB575E01A10941FBF7DE3D3DDF1_il2cpp_TypeInfo_var);
		RaycastHitComparer_t8EF6567C19BE9FB575E01A10941FBF7DE3D3DDF1* L_37 = ((RaycastHitComparer_t8EF6567C19BE9FB575E01A10941FBF7DE3D3DDF1_StaticFields*)il2cpp_codegen_static_fields_for(RaycastHitComparer_t8EF6567C19BE9FB575E01A10941FBF7DE3D3DDF1_il2cpp_TypeInfo_var))->___instance_0;
		Array_Sort_TisRaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5_mBF83A49E9B1F007DD08F7E076AF45D2AED7A45EB(L_35, 0, L_36, L_37, Array_Sort_TisRaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5_mBF83A49E9B1F007DD08F7E076AF45D2AED7A45EB_RuntimeMethod_var);
	}

IL_0118:
	{
		// for (int b = 0, bmax = hitCount; b < bmax; ++b)
		V_11 = 0;
		// for (int b = 0, bmax = hitCount; b < bmax; ++b)
		int32_t L_38 = V_3;
		V_12 = L_38;
		goto IL_01e5;
	}

IL_0123:
	{
		// var result = new RaycastResult
		// {
		//     gameObject = m_Hits[b].collider.gameObject,
		//     module = this,
		//     distance = m_Hits[b].distance,
		//     worldPosition = m_Hits[b].point,
		//     worldNormal = m_Hits[b].normal,
		//     screenPosition = eventData.position,
		//     displayIndex = displayIndex,
		//     index = resultAppendList.Count,
		//     sortingLayer = 0,
		//     sortingOrder = 0
		// };
		il2cpp_codegen_initobj((&V_14), sizeof(RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023));
		RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8* L_39 = __this->___m_Hits_10;
		int32_t L_40 = V_11;
		NullCheck(L_39);
		Collider_t1CC3163924FCD6C4CC2E816373A929C1E3D55E76* L_41;
		L_41 = RaycastHit_get_collider_m84B160439BBEAB6D9E94B799F720E25C9E2D444D(((L_39)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_40))), NULL);
		NullCheck(L_41);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_42;
		L_42 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_41, NULL);
		RaycastResult_set_gameObject_mCFEB66C0E3F01AC5E55040FE8BEB16E40427BD9E((&V_14), L_42, NULL);
		(&V_14)->___module_1 = __this;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_14)->___module_1), (void*)__this);
		RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8* L_43 = __this->___m_Hits_10;
		int32_t L_44 = V_11;
		NullCheck(L_43);
		float L_45;
		L_45 = RaycastHit_get_distance_m035194B0E9BB6229259CFC43B095A9C8E5011C78(((L_43)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_44))), NULL);
		(&V_14)->___distance_2 = L_45;
		RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8* L_46 = __this->___m_Hits_10;
		int32_t L_47 = V_11;
		NullCheck(L_46);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_48;
		L_48 = RaycastHit_get_point_m02B764612562AFE0F998CC7CFB2EEDE41BA47F39(((L_46)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_47))), NULL);
		(&V_14)->___worldPosition_9 = L_48;
		RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8* L_49 = __this->___m_Hits_10;
		int32_t L_50 = V_11;
		NullCheck(L_49);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_51;
		L_51 = RaycastHit_get_normal_mD8741B70D2039C5CAFC4368D4CE59D89562040B5(((L_49)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_50))), NULL);
		(&V_14)->___worldNormal_10 = L_51;
		PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* L_52 = ___0_eventData;
		NullCheck(L_52);
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_53;
		L_53 = PointerEventData_get_position_m5BE71C28EB72EFB8435749E4E6E839213AEF458C_inline(L_52, NULL);
		(&V_14)->___screenPosition_11 = L_53;
		int32_t L_54 = V_1;
		(&V_14)->___displayIndex_12 = L_54;
		List_1_t8292C421BBB00D7661DC07462822936152BAB446* L_55 = ___1_resultAppendList;
		NullCheck(L_55);
		int32_t L_56;
		L_56 = List_1_get_Count_mE2EBEDC861C1EC398EDBE6CF2C9FB604AA71523E_inline(L_55, List_1_get_Count_mE2EBEDC861C1EC398EDBE6CF2C9FB604AA71523E_RuntimeMethod_var);
		(&V_14)->___index_3 = ((float)L_56);
		(&V_14)->___sortingLayer_7 = 0;
		(&V_14)->___sortingOrder_8 = 0;
		RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 L_57 = V_14;
		V_13 = L_57;
		// resultAppendList.Add(result);
		List_1_t8292C421BBB00D7661DC07462822936152BAB446* L_58 = ___1_resultAppendList;
		RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 L_59 = V_13;
		NullCheck(L_58);
		List_1_Add_mEB6DFEA132B5B7BF540D34177054003185D250E7_inline(L_58, L_59, List_1_Add_mEB6DFEA132B5B7BF540D34177054003185D250E7_RuntimeMethod_var);
		// for (int b = 0, bmax = hitCount; b < bmax; ++b)
		int32_t L_60 = V_11;
		V_11 = ((int32_t)il2cpp_codegen_add(L_60, 1));
	}

IL_01e5:
	{
		// for (int b = 0, bmax = hitCount; b < bmax; ++b)
		int32_t L_61 = V_11;
		int32_t L_62 = V_12;
		V_15 = (bool)((((int32_t)L_61) < ((int32_t)L_62))? 1 : 0);
		bool L_63 = V_15;
		if (L_63)
		{
			goto IL_0123;
		}
	}
	{
	}

IL_01f5:
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
// System.Int32 UnityEngine.EventSystems.PhysicsRaycaster/RaycastHitComparer::Compare(UnityEngine.RaycastHit,UnityEngine.RaycastHit)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RaycastHitComparer_Compare_mB5B88FE52375A12B781682C712FE58193F417A03 (RaycastHitComparer_t8EF6567C19BE9FB575E01A10941FBF7DE3D3DDF1* __this, RaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5 ___0_x, RaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5 ___1_y, const RuntimeMethod* method) 
{
	float V_0 = 0.0f;
	int32_t V_1 = 0;
	{
		// return x.distance.CompareTo(y.distance);
		float L_0;
		L_0 = RaycastHit_get_distance_m035194B0E9BB6229259CFC43B095A9C8E5011C78((&___0_x), NULL);
		V_0 = L_0;
		float L_1;
		L_1 = RaycastHit_get_distance_m035194B0E9BB6229259CFC43B095A9C8E5011C78((&___1_y), NULL);
		int32_t L_2;
		L_2 = Single_CompareTo_m06F7868162EB392D3E99103D1A0BD27463C9E66F((&V_0), L_1, NULL);
		V_1 = L_2;
		goto IL_001a;
	}

IL_001a:
	{
		// }
		int32_t L_3 = V_1;
		return L_3;
	}
}
// System.Void UnityEngine.EventSystems.PhysicsRaycaster/RaycastHitComparer::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RaycastHitComparer__ctor_mAB0536EE515BF2BD1B29BE3B39E8BA9E9CFE97C3 (RaycastHitComparer_t8EF6567C19BE9FB575E01A10941FBF7DE3D3DDF1* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
// System.Void UnityEngine.EventSystems.PhysicsRaycaster/RaycastHitComparer::.cctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RaycastHitComparer__cctor_m772D29066D594105261C78CDDB5724BE28A773FA (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RaycastHitComparer_t8EF6567C19BE9FB575E01A10941FBF7DE3D3DDF1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static RaycastHitComparer instance = new RaycastHitComparer();
		RaycastHitComparer_t8EF6567C19BE9FB575E01A10941FBF7DE3D3DDF1* L_0 = (RaycastHitComparer_t8EF6567C19BE9FB575E01A10941FBF7DE3D3DDF1*)il2cpp_codegen_object_new(RaycastHitComparer_t8EF6567C19BE9FB575E01A10941FBF7DE3D3DDF1_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		RaycastHitComparer__ctor_mAB0536EE515BF2BD1B29BE3B39E8BA9E9CFE97C3(L_0, NULL);
		((RaycastHitComparer_t8EF6567C19BE9FB575E01A10941FBF7DE3D3DDF1_StaticFields*)il2cpp_codegen_static_fields_for(RaycastHitComparer_t8EF6567C19BE9FB575E01A10941FBF7DE3D3DDF1_il2cpp_TypeInfo_var))->___instance_0 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((RaycastHitComparer_t8EF6567C19BE9FB575E01A10941FBF7DE3D3DDF1_StaticFields*)il2cpp_codegen_static_fields_for(RaycastHitComparer_t8EF6567C19BE9FB575E01A10941FBF7DE3D3DDF1_il2cpp_TypeInfo_var))->___instance_0), (void*)L_0);
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
// Conversion methods for marshalling of: UnityEngine.EventSystems.RaycastResult
IL2CPP_EXTERN_C void RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_marshal_pinvoke(const RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023& unmarshaled, RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_marshaled_pinvoke& marshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023____m_GameObject_0_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* ___m_GameObject_0Exception = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '%s' of type '%s': Reference type field marshaling is not supported.", RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023____m_GameObject_0_FieldInfo_var, RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_0_0_0_var);
	IL2CPP_RAISE_MANAGED_EXCEPTION(___m_GameObject_0Exception, NULL);
}
IL2CPP_EXTERN_C void RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_marshal_pinvoke_back(const RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_marshaled_pinvoke& marshaled, RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023& unmarshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023____m_GameObject_0_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* ___m_GameObject_0Exception = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '%s' of type '%s': Reference type field marshaling is not supported.", RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023____m_GameObject_0_FieldInfo_var, RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_0_0_0_var);
	IL2CPP_RAISE_MANAGED_EXCEPTION(___m_GameObject_0Exception, NULL);
}
// Conversion method for clean up from marshalling of: UnityEngine.EventSystems.RaycastResult
IL2CPP_EXTERN_C void RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_marshal_pinvoke_cleanup(RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_marshaled_pinvoke& marshaled)
{
}
// Conversion methods for marshalling of: UnityEngine.EventSystems.RaycastResult
IL2CPP_EXTERN_C void RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_marshal_com(const RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023& unmarshaled, RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_marshaled_com& marshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023____m_GameObject_0_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* ___m_GameObject_0Exception = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '%s' of type '%s': Reference type field marshaling is not supported.", RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023____m_GameObject_0_FieldInfo_var, RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_0_0_0_var);
	IL2CPP_RAISE_MANAGED_EXCEPTION(___m_GameObject_0Exception, NULL);
}
IL2CPP_EXTERN_C void RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_marshal_com_back(const RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_marshaled_com& marshaled, RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023& unmarshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023____m_GameObject_0_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* ___m_GameObject_0Exception = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '%s' of type '%s': Reference type field marshaling is not supported.", RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023____m_GameObject_0_FieldInfo_var, RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_0_0_0_var);
	IL2CPP_RAISE_MANAGED_EXCEPTION(___m_GameObject_0Exception, NULL);
}
// Conversion method for clean up from marshalling of: UnityEngine.EventSystems.RaycastResult
IL2CPP_EXTERN_C void RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_marshal_com_cleanup(RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023_marshaled_com& marshaled)
{
}
// UnityEngine.GameObject UnityEngine.EventSystems.RaycastResult::get_gameObject()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* RaycastResult_get_gameObject_m77014B442B9E2D10F2CC3AEEDC07AA95CDE1E2F1 (RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* __this, const RuntimeMethod* method) 
{
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* V_0 = NULL;
	{
		// get { return m_GameObject; }
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___m_GameObject_0;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		// get { return m_GameObject; }
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_1 = V_0;
		return L_1;
	}
}
IL2CPP_EXTERN_C  GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* RaycastResult_get_gameObject_m77014B442B9E2D10F2CC3AEEDC07AA95CDE1E2F1_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023*>(__this + _offset);
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* _returnValue;
	_returnValue = RaycastResult_get_gameObject_m77014B442B9E2D10F2CC3AEEDC07AA95CDE1E2F1(_thisAdjusted, method);
	return _returnValue;
}
// System.Void UnityEngine.EventSystems.RaycastResult::set_gameObject(UnityEngine.GameObject)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RaycastResult_set_gameObject_mCFEB66C0E3F01AC5E55040FE8BEB16E40427BD9E (RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_value, const RuntimeMethod* method) 
{
	{
		// set { m_GameObject = value; }
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = ___0_value;
		__this->___m_GameObject_0 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_GameObject_0), (void*)L_0);
		// set { m_GameObject = value; }
		return;
	}
}
IL2CPP_EXTERN_C  void RaycastResult_set_gameObject_mCFEB66C0E3F01AC5E55040FE8BEB16E40427BD9E_AdjustorThunk (RuntimeObject* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_value, const RuntimeMethod* method)
{
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023*>(__this + _offset);
	RaycastResult_set_gameObject_mCFEB66C0E3F01AC5E55040FE8BEB16E40427BD9E(_thisAdjusted, ___0_value, method);
}
// System.Boolean UnityEngine.EventSystems.RaycastResult::get_isValid()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool RaycastResult_get_isValid_m69957B97C041A9E3FAF4ECA82BB8099C9FA171CE (RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	int32_t G_B3_0 = 0;
	{
		// get { return module != null && gameObject != null; }
		BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* L_0 = __this->___module_1;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_1)
		{
			goto IL_001d;
		}
	}
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_2;
		L_2 = RaycastResult_get_gameObject_m77014B442B9E2D10F2CC3AEEDC07AA95CDE1E2F1(__this, NULL);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_3;
		L_3 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_2, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		G_B3_0 = ((int32_t)(L_3));
		goto IL_001e;
	}

IL_001d:
	{
		G_B3_0 = 0;
	}

IL_001e:
	{
		V_0 = (bool)G_B3_0;
		goto IL_0021;
	}

IL_0021:
	{
		// get { return module != null && gameObject != null; }
		bool L_4 = V_0;
		return L_4;
	}
}
IL2CPP_EXTERN_C  bool RaycastResult_get_isValid_m69957B97C041A9E3FAF4ECA82BB8099C9FA171CE_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023*>(__this + _offset);
	bool _returnValue;
	_returnValue = RaycastResult_get_isValid_m69957B97C041A9E3FAF4ECA82BB8099C9FA171CE(_thisAdjusted, method);
	return _returnValue;
}
// System.Void UnityEngine.EventSystems.RaycastResult::Clear()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RaycastResult_Clear_m0E9DA70AC69CF143CEA8428AFC5BA552F99643AE (RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* __this, const RuntimeMethod* method) 
{
	{
		// gameObject = null;
		RaycastResult_set_gameObject_mCFEB66C0E3F01AC5E55040FE8BEB16E40427BD9E(__this, (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*)NULL, NULL);
		// module = null;
		__this->___module_1 = (BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___module_1), (void*)(BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832*)NULL);
		// distance = 0;
		__this->___distance_2 = (0.0f);
		// index = 0;
		__this->___index_3 = (0.0f);
		// depth = 0;
		__this->___depth_4 = 0;
		// sortingLayer = 0;
		__this->___sortingLayer_7 = 0;
		// sortingOrder = 0;
		__this->___sortingOrder_8 = 0;
		// worldNormal = Vector3.up;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0;
		L_0 = Vector3_get_up_m128AF3FDC820BF59D5DE86D973E7DE3F20C3AEBA_inline(NULL);
		__this->___worldNormal_10 = L_0;
		// worldPosition = Vector3.zero;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_1;
		L_1 = Vector3_get_zero_m0C1249C3F25B1C70EAD3CC8B31259975A457AE39_inline(NULL);
		__this->___worldPosition_9 = L_1;
		// screenPosition = Vector3.zero;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_2;
		L_2 = Vector3_get_zero_m0C1249C3F25B1C70EAD3CC8B31259975A457AE39_inline(NULL);
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_3;
		L_3 = Vector2_op_Implicit_mE8EBEE9291F11BB02F062D6E000F4798968CBD96_inline(L_2, NULL);
		__this->___screenPosition_11 = L_3;
		// }
		return;
	}
}
IL2CPP_EXTERN_C  void RaycastResult_Clear_m0E9DA70AC69CF143CEA8428AFC5BA552F99643AE_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023*>(__this + _offset);
	RaycastResult_Clear_m0E9DA70AC69CF143CEA8428AFC5BA552F99643AE(_thisAdjusted, method);
}
// System.String UnityEngine.EventSystems.RaycastResult::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* RaycastResult_ToString_m0267000494B09783ABD507B9329ADB01FBBC5428 (RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0F310FF3EBC19D65A536D81F5D8C7093E972DCA0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral12BA26D2F44E032136B3146CB230F4F45C5D45DE);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral267CC871678BDBD934CBEA872CCB8F0C72D94E44);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2A98949D28301C3B04EAD557512780C8D89A9607);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2B2D9FCF87BC5B281C797365D6EE6332266A0B63);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral30A589687C1FFF9D1706D115A0C664F2A49D9CEF);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral4B1F6E5C644F13999A134C243088737884A6B5D2);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral62105F6FE34556E3D1EE1FB639ABDA34F249420F);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral70F1769C72FCAF144F53009F7DA60ED467C29635);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral94A94F7BD0F52C17BB06F5A6BB4E316DC4B69DF8);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC10E23F5AEEE6BB98CA98C5F6720ED7A4B1DE089);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralED69593F1852661D74AD04003C30B937EE7310BF);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	String_t* V_1 = NULL;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_2;
	memset((&V_2), 0, sizeof(V_2));
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 V_3;
	memset((&V_3), 0, sizeof(V_3));
	int32_t V_4 = 0;
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* G_B4_0 = NULL;
	int32_t G_B4_1 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B4_2 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B4_3 = NULL;
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* G_B3_0 = NULL;
	int32_t G_B3_1 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B3_2 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B3_3 = NULL;
	String_t* G_B5_0 = NULL;
	int32_t G_B5_1 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B5_2 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B5_3 = NULL;
	BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* G_B7_0 = NULL;
	int32_t G_B7_1 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B7_2 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B7_3 = NULL;
	BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* G_B6_0 = NULL;
	int32_t G_B6_1 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B6_2 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B6_3 = NULL;
	String_t* G_B8_0 = NULL;
	int32_t G_B8_1 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B8_2 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B8_3 = NULL;
	{
		// if (!isValid)
		bool L_0;
		L_0 = RaycastResult_get_isValid_m69957B97C041A9E3FAF4ECA82BB8099C9FA171CE(__this, NULL);
		V_0 = (bool)((((int32_t)L_0) == ((int32_t)0))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0019;
		}
	}
	{
		// return "";
		V_1 = _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709;
		goto IL_017a;
	}

IL_0019:
	{
		// return "Name: " + gameObject + "\n" +
		//     "module: " + module + "\n" +
		//     "distance: " + distance + "\n" +
		//     "index: " + index + "\n" +
		//     "depth: " + depth + "\n" +
		//     "worldNormal: " + worldNormal + "\n" +
		//     "worldPosition: " + worldPosition + "\n" +
		//     "screenPosition: " + screenPosition + "\n" +
		//     "module.sortOrderPriority: " + module.sortOrderPriority + "\n" +
		//     "module.renderOrderPriority: " + module.renderOrderPriority + "\n" +
		//     "sortingLayer: " + sortingLayer + "\n" +
		//     "sortingOrder: " + sortingOrder;
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_2 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)((int32_t)24));
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_3 = L_2;
		NullCheck(L_3);
		ArrayElementTypeCheck (L_3, _stringLiteral70F1769C72FCAF144F53009F7DA60ED467C29635);
		(L_3)->SetAt(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteral70F1769C72FCAF144F53009F7DA60ED467C29635);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_4 = L_3;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_5;
		L_5 = RaycastResult_get_gameObject_m77014B442B9E2D10F2CC3AEEDC07AA95CDE1E2F1(__this, NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_6 = L_5;
		G_B3_0 = L_6;
		G_B3_1 = 1;
		G_B3_2 = L_4;
		G_B3_3 = L_4;
		if (L_6)
		{
			G_B4_0 = L_6;
			G_B4_1 = 1;
			G_B4_2 = L_4;
			G_B4_3 = L_4;
			goto IL_0037;
		}
	}
	{
		G_B5_0 = ((String_t*)(NULL));
		G_B5_1 = G_B3_1;
		G_B5_2 = G_B3_2;
		G_B5_3 = G_B3_3;
		goto IL_003c;
	}

IL_0037:
	{
		NullCheck(G_B4_0);
		String_t* L_7;
		L_7 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, G_B4_0);
		G_B5_0 = L_7;
		G_B5_1 = G_B4_1;
		G_B5_2 = G_B4_2;
		G_B5_3 = G_B4_3;
	}

IL_003c:
	{
		NullCheck(G_B5_2);
		ArrayElementTypeCheck (G_B5_2, G_B5_0);
		(G_B5_2)->SetAt(static_cast<il2cpp_array_size_t>(G_B5_1), (String_t*)G_B5_0);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_8 = G_B5_3;
		NullCheck(L_8);
		ArrayElementTypeCheck (L_8, _stringLiteral12BA26D2F44E032136B3146CB230F4F45C5D45DE);
		(L_8)->SetAt(static_cast<il2cpp_array_size_t>(2), (String_t*)_stringLiteral12BA26D2F44E032136B3146CB230F4F45C5D45DE);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_9 = L_8;
		BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* L_10 = __this->___module_1;
		BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* L_11 = L_10;
		G_B6_0 = L_11;
		G_B6_1 = 3;
		G_B6_2 = L_9;
		G_B6_3 = L_9;
		if (L_11)
		{
			G_B7_0 = L_11;
			G_B7_1 = 3;
			G_B7_2 = L_9;
			G_B7_3 = L_9;
			goto IL_0054;
		}
	}
	{
		G_B8_0 = ((String_t*)(NULL));
		G_B8_1 = G_B6_1;
		G_B8_2 = G_B6_2;
		G_B8_3 = G_B6_3;
		goto IL_0059;
	}

IL_0054:
	{
		NullCheck(G_B7_0);
		String_t* L_12;
		L_12 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, G_B7_0);
		G_B8_0 = L_12;
		G_B8_1 = G_B7_1;
		G_B8_2 = G_B7_2;
		G_B8_3 = G_B7_3;
	}

IL_0059:
	{
		NullCheck(G_B8_2);
		ArrayElementTypeCheck (G_B8_2, G_B8_0);
		(G_B8_2)->SetAt(static_cast<il2cpp_array_size_t>(G_B8_1), (String_t*)G_B8_0);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_13 = G_B8_3;
		NullCheck(L_13);
		ArrayElementTypeCheck (L_13, _stringLiteral94A94F7BD0F52C17BB06F5A6BB4E316DC4B69DF8);
		(L_13)->SetAt(static_cast<il2cpp_array_size_t>(4), (String_t*)_stringLiteral94A94F7BD0F52C17BB06F5A6BB4E316DC4B69DF8);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_14 = L_13;
		float* L_15 = (float*)(&__this->___distance_2);
		String_t* L_16;
		L_16 = Single_ToString_mE282EDA9CA4F7DF88432D807732837A629D04972(L_15, NULL);
		NullCheck(L_14);
		ArrayElementTypeCheck (L_14, L_16);
		(L_14)->SetAt(static_cast<il2cpp_array_size_t>(5), (String_t*)L_16);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_17 = L_14;
		NullCheck(L_17);
		ArrayElementTypeCheck (L_17, _stringLiteralC10E23F5AEEE6BB98CA98C5F6720ED7A4B1DE089);
		(L_17)->SetAt(static_cast<il2cpp_array_size_t>(6), (String_t*)_stringLiteralC10E23F5AEEE6BB98CA98C5F6720ED7A4B1DE089);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_18 = L_17;
		float* L_19 = (float*)(&__this->___index_3);
		String_t* L_20;
		L_20 = Single_ToString_mE282EDA9CA4F7DF88432D807732837A629D04972(L_19, NULL);
		NullCheck(L_18);
		ArrayElementTypeCheck (L_18, L_20);
		(L_18)->SetAt(static_cast<il2cpp_array_size_t>(7), (String_t*)L_20);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_21 = L_18;
		NullCheck(L_21);
		ArrayElementTypeCheck (L_21, _stringLiteral4B1F6E5C644F13999A134C243088737884A6B5D2);
		(L_21)->SetAt(static_cast<il2cpp_array_size_t>(8), (String_t*)_stringLiteral4B1F6E5C644F13999A134C243088737884A6B5D2);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_22 = L_21;
		int32_t* L_23 = (int32_t*)(&__this->___depth_4);
		String_t* L_24;
		L_24 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5(L_23, NULL);
		NullCheck(L_22);
		ArrayElementTypeCheck (L_22, L_24);
		(L_22)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)9)), (String_t*)L_24);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_25 = L_22;
		NullCheck(L_25);
		ArrayElementTypeCheck (L_25, _stringLiteral62105F6FE34556E3D1EE1FB639ABDA34F249420F);
		(L_25)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)10)), (String_t*)_stringLiteral62105F6FE34556E3D1EE1FB639ABDA34F249420F);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_26 = L_25;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_27 = __this->___worldNormal_10;
		V_2 = L_27;
		String_t* L_28;
		L_28 = Vector3_ToString_m6C24B9F0382D25D75B05C606E127CD14660574EE((&V_2), NULL);
		NullCheck(L_26);
		ArrayElementTypeCheck (L_26, L_28);
		(L_26)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)11)), (String_t*)L_28);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_29 = L_26;
		NullCheck(L_29);
		ArrayElementTypeCheck (L_29, _stringLiteral30A589687C1FFF9D1706D115A0C664F2A49D9CEF);
		(L_29)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)12)), (String_t*)_stringLiteral30A589687C1FFF9D1706D115A0C664F2A49D9CEF);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_30 = L_29;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_31 = __this->___worldPosition_9;
		V_2 = L_31;
		String_t* L_32;
		L_32 = Vector3_ToString_m6C24B9F0382D25D75B05C606E127CD14660574EE((&V_2), NULL);
		NullCheck(L_30);
		ArrayElementTypeCheck (L_30, L_32);
		(L_30)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)13)), (String_t*)L_32);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_33 = L_30;
		NullCheck(L_33);
		ArrayElementTypeCheck (L_33, _stringLiteralED69593F1852661D74AD04003C30B937EE7310BF);
		(L_33)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)14)), (String_t*)_stringLiteralED69593F1852661D74AD04003C30B937EE7310BF);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_34 = L_33;
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_35 = __this->___screenPosition_11;
		V_3 = L_35;
		String_t* L_36;
		L_36 = Vector2_ToString_mB47B29ECB21FA3A4ACEABEFA18077A5A6BBCCB27((&V_3), NULL);
		NullCheck(L_34);
		ArrayElementTypeCheck (L_34, L_36);
		(L_34)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)15)), (String_t*)L_36);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_37 = L_34;
		NullCheck(L_37);
		ArrayElementTypeCheck (L_37, _stringLiteral267CC871678BDBD934CBEA872CCB8F0C72D94E44);
		(L_37)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)16)), (String_t*)_stringLiteral267CC871678BDBD934CBEA872CCB8F0C72D94E44);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_38 = L_37;
		BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* L_39 = __this->___module_1;
		NullCheck(L_39);
		int32_t L_40;
		L_40 = VirtualFuncInvoker0< int32_t >::Invoke(20 /* System.Int32 UnityEngine.EventSystems.BaseRaycaster::get_sortOrderPriority() */, L_39);
		V_4 = L_40;
		String_t* L_41;
		L_41 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&V_4), NULL);
		NullCheck(L_38);
		ArrayElementTypeCheck (L_38, L_41);
		(L_38)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)17)), (String_t*)L_41);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_42 = L_38;
		NullCheck(L_42);
		ArrayElementTypeCheck (L_42, _stringLiteral0F310FF3EBC19D65A536D81F5D8C7093E972DCA0);
		(L_42)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)18)), (String_t*)_stringLiteral0F310FF3EBC19D65A536D81F5D8C7093E972DCA0);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_43 = L_42;
		BaseRaycaster_t7DC8158FD3CA0193455344379DD5FF7CD5F1F832* L_44 = __this->___module_1;
		NullCheck(L_44);
		int32_t L_45;
		L_45 = VirtualFuncInvoker0< int32_t >::Invoke(21 /* System.Int32 UnityEngine.EventSystems.BaseRaycaster::get_renderOrderPriority() */, L_44);
		V_4 = L_45;
		String_t* L_46;
		L_46 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&V_4), NULL);
		NullCheck(L_43);
		ArrayElementTypeCheck (L_43, L_46);
		(L_43)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)19)), (String_t*)L_46);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_47 = L_43;
		NullCheck(L_47);
		ArrayElementTypeCheck (L_47, _stringLiteral2A98949D28301C3B04EAD557512780C8D89A9607);
		(L_47)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)20)), (String_t*)_stringLiteral2A98949D28301C3B04EAD557512780C8D89A9607);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_48 = L_47;
		int32_t* L_49 = (int32_t*)(&__this->___sortingLayer_7);
		String_t* L_50;
		L_50 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5(L_49, NULL);
		NullCheck(L_48);
		ArrayElementTypeCheck (L_48, L_50);
		(L_48)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)21)), (String_t*)L_50);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_51 = L_48;
		NullCheck(L_51);
		ArrayElementTypeCheck (L_51, _stringLiteral2B2D9FCF87BC5B281C797365D6EE6332266A0B63);
		(L_51)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)22)), (String_t*)_stringLiteral2B2D9FCF87BC5B281C797365D6EE6332266A0B63);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_52 = L_51;
		int32_t* L_53 = (int32_t*)(&__this->___sortingOrder_8);
		String_t* L_54;
		L_54 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5(L_53, NULL);
		NullCheck(L_52);
		ArrayElementTypeCheck (L_52, L_54);
		(L_52)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)23)), (String_t*)L_54);
		String_t* L_55;
		L_55 = String_Concat_m647EBF831F54B6DF7D5AFA5FD012CF4EE7571B6A(L_52, NULL);
		V_1 = L_55;
		goto IL_017a;
	}

IL_017a:
	{
		// }
		String_t* L_56 = V_1;
		return L_56;
	}
}
IL2CPP_EXTERN_C  String_t* RaycastResult_ToString_m0267000494B09783ABD507B9329ADB01FBBC5428_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023*>(__this + _offset);
	String_t* _returnValue;
	_returnValue = RaycastResult_ToString_m0267000494B09783ABD507B9329ADB01FBBC5428(_thisAdjusted, method);
	return _returnValue;
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void UnityEngine.EventSystems.UIBehaviour::Awake()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIBehaviour_Awake_mDF9D1A4867C8E730C59A7CAE97709CA9B8F3A0F2 (UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D* __this, const RuntimeMethod* method) 
{
	{
		// {}
		return;
	}
}
// System.Void UnityEngine.EventSystems.UIBehaviour::OnEnable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIBehaviour_OnEnable_m8989ABF5C038905A68E5536BED2E6FFAF8767FFC (UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D* __this, const RuntimeMethod* method) 
{
	{
		// {}
		return;
	}
}
// System.Void UnityEngine.EventSystems.UIBehaviour::Start()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIBehaviour_Start_mB12643ED6D859CD3682B4BF5B9CA7F72E8A72B45 (UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D* __this, const RuntimeMethod* method) 
{
	{
		// {}
		return;
	}
}
// System.Void UnityEngine.EventSystems.UIBehaviour::OnDisable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIBehaviour_OnDisable_m18D5A0B93F65FB50F4D6CE8197EC07F3452C5DDE (UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D* __this, const RuntimeMethod* method) 
{
	{
		// {}
		return;
	}
}
// System.Void UnityEngine.EventSystems.UIBehaviour::OnDestroy()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIBehaviour_OnDestroy_mF225CF9163823F19BE5E2B2735D35898A20D608B (UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D* __this, const RuntimeMethod* method) 
{
	{
		// {}
		return;
	}
}
// System.Boolean UnityEngine.EventSystems.UIBehaviour::IsActive()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool UIBehaviour_IsActive_m9E79A0650C81204AF9A861BBBA8685D9563AE9C4 (UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D* __this, const RuntimeMethod* method) 
{
	bool V_0 = false;
	{
		// return isActiveAndEnabled;
		bool L_0;
		L_0 = Behaviour_get_isActiveAndEnabled_mEB4ECCE9761A7016BC619557CEFEA1A30D3BF28A(__this, NULL);
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		// }
		bool L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.EventSystems.UIBehaviour::OnRectTransformDimensionsChange()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIBehaviour_OnRectTransformDimensionsChange_m86A6D20E0EBF41CDB89DD1E87F23624263B68159 (UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D* __this, const RuntimeMethod* method) 
{
	{
		// {}
		return;
	}
}
// System.Void UnityEngine.EventSystems.UIBehaviour::OnBeforeTransformParentChanged()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIBehaviour_OnBeforeTransformParentChanged_m980EF41E33A7541BD6C65AEC305B25A19C9CA30F (UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D* __this, const RuntimeMethod* method) 
{
	{
		// {}
		return;
	}
}
// System.Void UnityEngine.EventSystems.UIBehaviour::OnTransformParentChanged()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIBehaviour_OnTransformParentChanged_mAD56D3C6049A1746F00DC2643D1666F7DE921384 (UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D* __this, const RuntimeMethod* method) 
{
	{
		// {}
		return;
	}
}
// System.Void UnityEngine.EventSystems.UIBehaviour::OnDidApplyAnimationProperties()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIBehaviour_OnDidApplyAnimationProperties_mE011A7C92134E28AE2AF3A0EBFB2E4AB88ABE748 (UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D* __this, const RuntimeMethod* method) 
{
	{
		// {}
		return;
	}
}
// System.Void UnityEngine.EventSystems.UIBehaviour::OnCanvasGroupChanged()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIBehaviour_OnCanvasGroupChanged_m592FA8BF5238E712E73E2D99258EE0DB6D88D84B (UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D* __this, const RuntimeMethod* method) 
{
	{
		// {}
		return;
	}
}
// System.Void UnityEngine.EventSystems.UIBehaviour::OnCanvasHierarchyChanged()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIBehaviour_OnCanvasHierarchyChanged_mCAC018CB33FA00E857288B64E3722226638A1229 (UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D* __this, const RuntimeMethod* method) 
{
	{
		// {}
		return;
	}
}
// System.Boolean UnityEngine.EventSystems.UIBehaviour::IsDestroyed()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool UIBehaviour_IsDestroyed_m2E9FFA28686D1C82697FB467002541CC58A06BCA (UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	{
		// return this == null;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_0;
		L_0 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(__this, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		V_0 = L_0;
		goto IL_000b;
	}

IL_000b:
	{
		// }
		bool L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.EventSystems.UIBehaviour::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIBehaviour__ctor_m24C66A65DDD996E779871C6655CF11B871F11337 (UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D* __this, const RuntimeMethod* method) 
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
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* PointerEventData_get_pointerDrag_m36BF08A32216845A8095C5F74DFE6C9959A11E96_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, const RuntimeMethod* method) 
{
	{
		// public GameObject pointerDrag { get; set; }
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___U3CpointerDragU3Ek__BackingField_6;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool PointerEventData_get_dragging_mE0AD837F228E3830D4A74657AD3D47F53F6C87E9_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, const RuntimeMethod* method) 
{
	{
		// public bool dragging { get; set; }
		bool L_0 = __this->___U3CdraggingU3Ek__BackingField_22;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 Vector2_op_Subtraction_m44475FCDAD2DA2F98D78A6625EC2DCDFE8803837_inline (Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___0_a, Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___1_b, const RuntimeMethod* method) 
{
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_0 = ___0_a;
		float L_1 = L_0.___x_0;
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_2 = ___1_b;
		float L_3 = L_2.___x_0;
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_4 = ___0_a;
		float L_5 = L_4.___y_1;
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_6 = ___1_b;
		float L_7 = L_6.___y_1;
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_8;
		memset((&L_8), 0, sizeof(L_8));
		Vector2__ctor_m9525B79969AFFE3254B303A40997A56DEEB6F548_inline((&L_8), ((float)il2cpp_codegen_subtract(L_1, L_3)), ((float)il2cpp_codegen_subtract(L_5, L_7)), /*hidden argument*/NULL);
		V_0 = L_8;
		goto IL_0023;
	}

IL_0023:
	{
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_9 = V_0;
		return L_9;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Vector2_get_sqrMagnitude_mA16336720C14EEF8BA9B55AE33B98C9EE2082BDC_inline (Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7* __this, const RuntimeMethod* method) 
{
	float V_0 = 0.0f;
	{
		float L_0 = __this->___x_0;
		float L_1 = __this->___x_0;
		float L_2 = __this->___y_1;
		float L_3 = __this->___y_1;
		V_0 = ((float)il2cpp_codegen_add(((float)il2cpp_codegen_multiply(L_0, L_1)), ((float)il2cpp_codegen_multiply(L_2, L_3))));
		goto IL_001f;
	}

IL_001f:
	{
		float L_4 = V_0;
		return L_4;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 Vector2_get_zero_m32506C40EC2EE7D5D4410BF40D3EE683A3D5F32C_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_0 = ((Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7_StaticFields*)il2cpp_codegen_static_fields_for(Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7_il2cpp_TypeInfo_var))->___zeroVector_2;
		V_0 = L_0;
		goto IL_0009;
	}

IL_0009:
	{
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_1 = V_0;
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PointerEventData_set_delta_mD200AF7CCAEAD92D947091902AF864CB4ACE0F1D_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___0_value, const RuntimeMethod* method) 
{
	{
		// public Vector2 delta { get; set; }
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_0 = ___0_value;
		__this->___U3CdeltaU3Ek__BackingField_14 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 PointerEventData_get_pointerCurrentRaycast_m1C6B7D707CEE9C6574DD443289D90102EDC7A2C4_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, const RuntimeMethod* method) 
{
	{
		// public RaycastResult pointerCurrentRaycast { get; set; }
		RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 L_0 = __this->___U3CpointerCurrentRaycastU3Ek__BackingField_8;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PointerEventData_set_eligibleForClick_m360125CB3E348F3CF64C39F163467A842E479C21_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		// public bool eligibleForClick { get; set; }
		bool L_0 = ___0_value;
		__this->___U3CeligibleForClickU3Ek__BackingField_11 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PointerEventData_set_dragging_m43982B3F95F05986F40A736914CFBC45D2A9BB8E_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		// public bool dragging { get; set; }
		bool L_0 = ___0_value;
		__this->___U3CdraggingU3Ek__BackingField_22 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PointerEventData_set_useDragThreshold_m63FE2034E4B240F1A0A902B1EB893B3DBA2D848B_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		// public bool useDragThreshold { get; set; }
		bool L_0 = ___0_value;
		__this->___U3CuseDragThresholdU3Ek__BackingField_21 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 PointerEventData_get_position_m5BE71C28EB72EFB8435749E4E6E839213AEF458C_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, const RuntimeMethod* method) 
{
	{
		// public Vector2 position { get; set; }
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_0 = __this->___U3CpositionU3Ek__BackingField_13;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PointerEventData_set_pressPosition_m85544FBAB798DABE70067508294A6C4841A95379_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___0_value, const RuntimeMethod* method) 
{
	{
		// public Vector2 pressPosition { get; set; }
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_0 = ___0_value;
		__this->___U3CpressPositionU3Ek__BackingField_15 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PointerEventData_set_pointerPressRaycast_m55CA127474B4CBCA795A9C872B7630AAF766F852_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 ___0_value, const RuntimeMethod* method) 
{
	{
		// public RaycastResult pointerPressRaycast { get; set; }
		RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 L_0 = ___0_value;
		__this->___U3CpointerPressRaycastU3Ek__BackingField_9 = L_0;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___U3CpointerPressRaycastU3Ek__BackingField_9))->___m_GameObject_0), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___U3CpointerPressRaycastU3Ek__BackingField_9))->___module_1), (void*)NULL);
		#endif
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* PointerEventData_get_pointerEnter_m6CE76D5C0C36C4666CDDE348B57885C52D495A4B_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, const RuntimeMethod* method) 
{
	{
		// public GameObject pointerEnter { get; set; }
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___U3CpointerEnterU3Ek__BackingField_2;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PointerEventData_set_pointerEnter_m2DA660C24CBDE9B83DF2B2D09D9AF0E94A770D17_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_value, const RuntimeMethod* method) 
{
	{
		// public GameObject pointerEnter { get; set; }
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = ___0_value;
		__this->___U3CpointerEnterU3Ek__BackingField_2 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CpointerEnterU3Ek__BackingField_2), (void*)L_0);
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* PointerEventData_get_lastPress_m46720C62503214A44EE947679A8BA307BC2AEEDC_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, const RuntimeMethod* method) 
{
	{
		// public GameObject lastPress { get; private set; }
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___U3ClastPressU3Ek__BackingField_4;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float PointerEventData_get_clickTime_m5ABE0298E8CEF28B6BD7E750E940756CD78AB96E_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, const RuntimeMethod* method) 
{
	{
		// public float clickTime { get; set; }
		float L_0 = __this->___U3CclickTimeU3Ek__BackingField_18;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t PointerEventData_get_clickCount_m3977011C09DB9F904B1AAC3708B821B8D6AC0F9F_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, const RuntimeMethod* method) 
{
	{
		// public int clickCount { get; set; }
		int32_t L_0 = __this->___U3CclickCountU3Ek__BackingField_19;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PointerEventData_set_clickCount_m0A87C2C367987492F310786DC9C3DF1616EA4D49_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int clickCount { get; set; }
		int32_t L_0 = ___0_value;
		__this->___U3CclickCountU3Ek__BackingField_19 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PointerEventData_set_clickTime_m93D27EB35F490AC9100369A23002F09148F85996_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, float ___0_value, const RuntimeMethod* method) 
{
	{
		// public float clickTime { get; set; }
		float L_0 = ___0_value;
		__this->___U3CclickTimeU3Ek__BackingField_18 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PointerEventData_set_rawPointerPress_mEEC4E3C7CD00F1DDCD3DA98DA5837E71BB8455E3_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_value, const RuntimeMethod* method) 
{
	{
		// public GameObject rawPointerPress { get; set; }
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = ___0_value;
		__this->___U3CrawPointerPressU3Ek__BackingField_5 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CrawPointerPressU3Ek__BackingField_5), (void*)L_0);
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PointerEventData_set_pointerDrag_m0E8D72362B07962843671C39ADC8F4D5E4915010_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_value, const RuntimeMethod* method) 
{
	{
		// public GameObject pointerDrag { get; set; }
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = ___0_value;
		__this->___U3CpointerDragU3Ek__BackingField_6 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CpointerDragU3Ek__BackingField_6), (void*)L_0);
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool PointerEventData_get_eligibleForClick_m4B01A1640C694FD7421BDFB19CF763BC85672C8E_inline (PointerEventData_t9670F3C7D823CCB738A1604C72A1EB90292396FB* __this, const RuntimeMethod* method) 
{
	{
		// public bool eligibleForClick { get; set; }
		bool L_0 = __this->___U3CeligibleForClickU3Ek__BackingField_11;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7* GetRayIntersectionAllCallback_Invoke_m917AA4108EBDC724AFEF39BFD06A586B7461F497_inline (GetRayIntersectionAllCallback_t52E7AE4ECEA3F9744FF7F8448F852C872A70315C* __this, Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 ___0_r, float ___1_f, int32_t ___2_i, const RuntimeMethod* method) 
{
	typedef RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7* (*FunctionPointerType) (RuntimeObject*, Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00, float, int32_t, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_r, ___1_f, ___2_i, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t GetRayIntersectionAllNonAllocCallback_Invoke_mFAA36E9AF362DC72204EEF53B28DBFC3367D09A7_inline (GetRayIntersectionAllNonAllocCallback_t28D7ACEBBE525DE0CBEA67986E4C3891D694F980* __this, Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 ___0_r, RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7* ___1_results, float ___2_f, int32_t ___3_i, const RuntimeMethod* method) 
{
	typedef int32_t (*FunctionPointerType) (RuntimeObject*, Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00, RaycastHit2DU5BU5D_t28739C686586993113318B63C84927FD43063FC7*, float, int32_t, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_r, ___1_results, ___2_f, ___3_i, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector2_op_Implicit_m6D9CABB2C791A192867D7A4559D132BE86DD3EB7_inline (Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___0_v, const RuntimeMethod* method) 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_0 = ___0_v;
		float L_1 = L_0.___x_0;
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_2 = ___0_v;
		float L_3 = L_2.___y_1;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4;
		memset((&L_4), 0, sizeof(L_4));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_4), L_1, L_3, (0.0f), /*hidden argument*/NULL);
		V_0 = L_4;
		goto IL_001a;
	}

IL_001a:
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_5 = V_0;
		return L_5;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Vector3_Distance_m2314DB9B8BD01157E013DF87BEA557375C7F9FF9_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_a, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___1_b, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	float V_0 = 0.0f;
	float V_1 = 0.0f;
	float V_2 = 0.0f;
	float V_3 = 0.0f;
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ___0_a;
		float L_1 = L_0.___x_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_2 = ___1_b;
		float L_3 = L_2.___x_2;
		V_0 = ((float)il2cpp_codegen_subtract(L_1, L_3));
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4 = ___0_a;
		float L_5 = L_4.___y_3;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_6 = ___1_b;
		float L_7 = L_6.___y_3;
		V_1 = ((float)il2cpp_codegen_subtract(L_5, L_7));
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_8 = ___0_a;
		float L_9 = L_8.___z_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_10 = ___1_b;
		float L_11 = L_10.___z_4;
		V_2 = ((float)il2cpp_codegen_subtract(L_9, L_11));
		float L_12 = V_0;
		float L_13 = V_0;
		float L_14 = V_1;
		float L_15 = V_1;
		float L_16 = V_2;
		float L_17 = V_2;
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_18;
		L_18 = sqrt(((double)((float)il2cpp_codegen_add(((float)il2cpp_codegen_add(((float)il2cpp_codegen_multiply(L_12, L_13)), ((float)il2cpp_codegen_multiply(L_14, L_15)))), ((float)il2cpp_codegen_multiply(L_16, L_17))))));
		V_3 = ((float)L_18);
		goto IL_0040;
	}

IL_0040:
	{
		float L_19 = V_3;
		return L_19;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_op_Subtraction_mE42023FF80067CB44A1D4A27EB7CF2B24CABB828_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_a, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___1_b, const RuntimeMethod* method) 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ___0_a;
		float L_1 = L_0.___x_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_2 = ___1_b;
		float L_3 = L_2.___x_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4 = ___0_a;
		float L_5 = L_4.___y_3;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_6 = ___1_b;
		float L_7 = L_6.___y_3;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_8 = ___0_a;
		float L_9 = L_8.___z_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_10 = ___1_b;
		float L_11 = L_10.___z_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_12;
		memset((&L_12), 0, sizeof(L_12));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_12), ((float)il2cpp_codegen_subtract(L_1, L_3)), ((float)il2cpp_codegen_subtract(L_5, L_7)), ((float)il2cpp_codegen_subtract(L_9, L_11)), /*hidden argument*/NULL);
		V_0 = L_12;
		goto IL_0030;
	}

IL_0030:
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_13 = V_0;
		return L_13;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Vector3_Dot_mBB86BB940AA0A32FA7D3C02AC42E5BC7095A5D52_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_lhs, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___1_rhs, const RuntimeMethod* method) 
{
	float V_0 = 0.0f;
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ___0_lhs;
		float L_1 = L_0.___x_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_2 = ___1_rhs;
		float L_3 = L_2.___x_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4 = ___0_lhs;
		float L_5 = L_4.___y_3;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_6 = ___1_rhs;
		float L_7 = L_6.___y_3;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_8 = ___0_lhs;
		float L_9 = L_8.___z_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_10 = ___1_rhs;
		float L_11 = L_10.___z_4;
		V_0 = ((float)il2cpp_codegen_add(((float)il2cpp_codegen_add(((float)il2cpp_codegen_multiply(L_1, L_3)), ((float)il2cpp_codegen_multiply(L_5, L_7)))), ((float)il2cpp_codegen_multiply(L_9, L_11))));
		goto IL_002d;
	}

IL_002d:
	{
		float L_12 = V_0;
		return L_12;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_get_zero_m0C1249C3F25B1C70EAD3CC8B31259975A457AE39_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ((Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_StaticFields*)il2cpp_codegen_static_fields_for(Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_il2cpp_TypeInfo_var))->___zeroVector_5;
		V_0 = L_0;
		goto IL_0009;
	}

IL_0009:
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_1 = V_0;
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector3_op_Inequality_m9F170CDFBF1E490E559DA5D06D6547501A402BBF_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_lhs, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___1_rhs, const RuntimeMethod* method) 
{
	bool V_0 = false;
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ___0_lhs;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_1 = ___1_rhs;
		bool L_2;
		L_2 = Vector3_op_Equality_mCDCBB8D2EDC3D3BF20F31A25ACB34705D352B479_inline(L_0, L_1, NULL);
		V_0 = (bool)((((int32_t)L_2) == ((int32_t)0))? 1 : 0);
		goto IL_000e;
	}

IL_000e:
	{
		bool L_3 = V_0;
		return L_3;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Mathf_Approximately_m1DADD012A8FC82E11FB282501AE2EBBF9A77150B_inline (float ___0_a, float ___1_b, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	{
		float L_0 = ___1_b;
		float L_1 = ___0_a;
		float L_2;
		L_2 = fabsf(((float)il2cpp_codegen_subtract(L_0, L_1)));
		float L_3 = ___0_a;
		float L_4;
		L_4 = fabsf(L_3);
		float L_5 = ___1_b;
		float L_6;
		L_6 = fabsf(L_5);
		float L_7;
		L_7 = Mathf_Max_mF5379E63D2BBAC76D090748695D833934F8AD051_inline(L_4, L_6, NULL);
		float L_8 = ((Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682_StaticFields*)il2cpp_codegen_static_fields_for(Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682_il2cpp_TypeInfo_var))->___Epsilon_0;
		float L_9;
		L_9 = Mathf_Max_mF5379E63D2BBAC76D090748695D833934F8AD051_inline(((float)il2cpp_codegen_multiply((9.99999997E-07f), L_7)), ((float)il2cpp_codegen_multiply(L_8, (8.0f))), NULL);
		V_0 = (bool)((((float)L_2) < ((float)L_9))? 1 : 0);
		goto IL_0035;
	}

IL_0035:
	{
		bool L_10 = V_0;
		return L_10;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8* RaycastAllCallback_Invoke_mB30319766AF5F0D5145A6C0AFFEA829A31A5D4B7_inline (RaycastAllCallback_t4AFFDCDAA6F02DD74E1E2DE455BA011D82BED47A* __this, Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 ___0_r, float ___1_f, int32_t ___2_i, const RuntimeMethod* method) 
{
	typedef RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8* (*FunctionPointerType) (RuntimeObject*, Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00, float, int32_t, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_r, ___1_f, ___2_i, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t GetRaycastNonAllocCallback_Invoke_m36411365E9622819DAB93D0BB0F169FEE99F07D9_inline (GetRaycastNonAllocCallback_tC3DA6EE6063FE663DD0A9FC52439D825DE4A1FFC* __this, Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 ___0_r, RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8* ___1_results, float ___2_f, int32_t ___3_i, const RuntimeMethod* method) 
{
	typedef int32_t (*FunctionPointerType) (RuntimeObject*, Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00, RaycastHitU5BU5D_t008B8309DE422FE7567068D743D68054D5EBF1A8*, float, int32_t, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_r, ___1_results, ___2_f, ___3_i, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_get_up_m128AF3FDC820BF59D5DE86D973E7DE3F20C3AEBA_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ((Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_StaticFields*)il2cpp_codegen_static_fields_for(Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_il2cpp_TypeInfo_var))->___upVector_7;
		V_0 = L_0;
		goto IL_0009;
	}

IL_0009:
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_1 = V_0;
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 Vector2_op_Implicit_mE8EBEE9291F11BB02F062D6E000F4798968CBD96_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_v, const RuntimeMethod* method) 
{
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ___0_v;
		float L_1 = L_0.___x_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_2 = ___0_v;
		float L_3 = L_2.___y_3;
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_4;
		memset((&L_4), 0, sizeof(L_4));
		Vector2__ctor_m9525B79969AFFE3254B303A40997A56DEEB6F548_inline((&L_4), L_1, L_3, /*hidden argument*/NULL);
		V_0 = L_4;
		goto IL_0015;
	}

IL_0015:
	{
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_5 = V_0;
		return L_5;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR KeyValuePair_2_tDC26B09C26BA829DDE331BCB6AF7C508C763D7A3 Enumerator_get_Current_m90160D324DA0D9F5624A345F47D8E226A118911A_gshared_inline (Enumerator_tE92C1AC40A104A179B94F8A013728FD9314CFBD3* __this, const RuntimeMethod* method) 
{
	{
		KeyValuePair_2_tDC26B09C26BA829DDE331BCB6AF7C508C763D7A3 L_0 = __this->____current_3;
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
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_mE2EBEDC861C1EC398EDBE6CF2C9FB604AA71523E_gshared_inline (List_1_t8292C421BBB00D7661DC07462822936152BAB446* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size_2;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEB6DFEA132B5B7BF540D34177054003185D250E7_gshared_inline (List_1_t8292C421BBB00D7661DC07462822936152BAB446* __this, RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 ___0_item, const RuntimeMethod* method) 
{
	RaycastResultU5BU5D_tEAF6B3C3088179304676571328CBB001D8CECBC7* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version_3;
		__this->____version_3 = ((int32_t)il2cpp_codegen_add(L_0, 1));
		RaycastResultU5BU5D_tEAF6B3C3088179304676571328CBB001D8CECBC7* L_1 = __this->____items_1;
		V_0 = L_1;
		int32_t L_2 = __this->____size_2;
		V_1 = L_2;
		int32_t L_3 = V_1;
		RaycastResultU5BU5D_tEAF6B3C3088179304676571328CBB001D8CECBC7* L_4 = V_0;
		NullCheck(L_4);
		if ((!(((uint32_t)L_3) < ((uint32_t)((int32_t)(((RuntimeArray*)L_4)->max_length))))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_5 = V_1;
		__this->____size_2 = ((int32_t)il2cpp_codegen_add(L_5, 1));
		RaycastResultU5BU5D_tEAF6B3C3088179304676571328CBB001D8CECBC7* L_6 = V_0;
		int32_t L_7 = V_1;
		RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 L_8 = ___0_item;
		NullCheck(L_6);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(L_7), (RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023)L_8);
		return;
	}

IL_0034:
	{
		RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023 L_9 = ___0_item;
		((  void (*) (List_1_t8292C421BBB00D7661DC07462822936152BAB446*, RaycastResult_tEC6A7B7CABA99C386F054F01E498AEC426CF8023, const RuntimeMethod*))il2cpp_codegen_get_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 11)))(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Vector2__ctor_m9525B79969AFFE3254B303A40997A56DEEB6F548_inline (Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7* __this, float ___0_x, float ___1_y, const RuntimeMethod* method) 
{
	{
		float L_0 = ___0_x;
		__this->___x_0 = L_0;
		float L_1 = ___1_y;
		__this->___y_1 = L_1;
		return;
	}
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
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector3_op_Equality_mCDCBB8D2EDC3D3BF20F31A25ACB34705D352B479_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_lhs, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___1_rhs, const RuntimeMethod* method) 
{
	float V_0 = 0.0f;
	float V_1 = 0.0f;
	float V_2 = 0.0f;
	float V_3 = 0.0f;
	bool V_4 = false;
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ___0_lhs;
		float L_1 = L_0.___x_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_2 = ___1_rhs;
		float L_3 = L_2.___x_2;
		V_0 = ((float)il2cpp_codegen_subtract(L_1, L_3));
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4 = ___0_lhs;
		float L_5 = L_4.___y_3;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_6 = ___1_rhs;
		float L_7 = L_6.___y_3;
		V_1 = ((float)il2cpp_codegen_subtract(L_5, L_7));
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_8 = ___0_lhs;
		float L_9 = L_8.___z_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_10 = ___1_rhs;
		float L_11 = L_10.___z_4;
		V_2 = ((float)il2cpp_codegen_subtract(L_9, L_11));
		float L_12 = V_0;
		float L_13 = V_0;
		float L_14 = V_1;
		float L_15 = V_1;
		float L_16 = V_2;
		float L_17 = V_2;
		V_3 = ((float)il2cpp_codegen_add(((float)il2cpp_codegen_add(((float)il2cpp_codegen_multiply(L_12, L_13)), ((float)il2cpp_codegen_multiply(L_14, L_15)))), ((float)il2cpp_codegen_multiply(L_16, L_17))));
		float L_18 = V_3;
		V_4 = (bool)((((float)L_18) < ((float)(9.99999944E-11f)))? 1 : 0);
		goto IL_0043;
	}

IL_0043:
	{
		bool L_19 = V_4;
		return L_19;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Mathf_Max_mF5379E63D2BBAC76D090748695D833934F8AD051_inline (float ___0_a, float ___1_b, const RuntimeMethod* method) 
{
	float V_0 = 0.0f;
	float G_B3_0 = 0.0f;
	{
		float L_0 = ___0_a;
		float L_1 = ___1_b;
		if ((((float)L_0) > ((float)L_1)))
		{
			goto IL_0008;
		}
	}
	{
		float L_2 = ___1_b;
		G_B3_0 = L_2;
		goto IL_0009;
	}

IL_0008:
	{
		float L_3 = ___0_a;
		G_B3_0 = L_3;
	}

IL_0009:
	{
		V_0 = G_B3_0;
		goto IL_000c;
	}

IL_000c:
	{
		float L_4 = V_0;
		return L_4;
	}
}
