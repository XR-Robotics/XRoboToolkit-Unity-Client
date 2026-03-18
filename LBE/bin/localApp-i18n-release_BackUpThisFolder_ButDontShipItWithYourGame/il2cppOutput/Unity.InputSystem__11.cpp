#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>


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
struct InterfaceActionInvoker0
{
	typedef void (*Action)(void*, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename R>
struct InterfaceFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};

// System.Collections.Generic.Dictionary`2<UnityEngine.InputSystem.Utilities.InternedString,System.Object>
struct Dictionary_2_t25574638E247E1D55E6ED2A97A5C38F3EBA31BA9;
// System.Collections.Generic.Dictionary`2<UnityEngine.InputSystem.Utilities.InternedString,System.Type>
struct Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D;
// System.Func`2<System.Char,System.Boolean>
struct Func_2_tF409A653B8F770E0A30CD80D21764FB1DDB2A28F;
// System.Func`2<UnityEngine.InputSystem.Utilities.InternedString,System.Object>
struct Func_2_t63BCD2DEBA7363CAD4DAAF9703EF65C11A4C7BBB;
// System.Func`2<UnityEngine.InputSystem.Utilities.InternedString,System.String>
struct Func_2_tE0082B3C229A425A69ECDABB19259709EC9F540F;
// System.Func`2<System.Object,System.Object>
struct Func_2_tACBF5A1656250800CE861707354491F0611F6624;
// System.Func`2<System.String,System.String>
struct Func_2_t85D1F7C2022B349817C22FC72C474CD33FFABE93;
// System.Collections.Generic.HashSet`1<System.String>
struct HashSet_1_tEFC6605F7DE53F71946C33FD371E53C3100F2178;
// System.Collections.Generic.IEnumerable`1<UnityEngine.InputSystem.Utilities.InternedString>
struct IEnumerable_1_t5359DEC999AA35C7E2DE775B0455A4760550ED7F;
// System.Collections.Generic.IEnumerable`1<System.Object>
struct IEnumerable_1_tF95C9E01A913DD50575531C8305932628663D9E9;
// System.Collections.Generic.IEnumerable`1<System.String>
struct IEnumerable_1_t349E66EC5F09B881A8E52EE40A1AB9EC60E08E44;
// System.Collections.Generic.IEnumerable`1<UnityEngine.InputSystem.Utilities.Substring>
struct IEnumerable_1_tDE18BB328ED95FB272AE8FAE3C13576909589F4D;
// System.Collections.Generic.IEnumerable`1<UnityEngine.InputSystem.InputBindingCompositeContext/PartBinding>
struct IEnumerable_1_t45141F64D6D882336B8DCC6510DC6B9C3294C6AA;
// System.Collections.Generic.IEnumerator`1<System.String>
struct IEnumerator_1_t73FD060C436E3C4264A734C8F8DCC01DFF6046B8;
// System.Collections.Generic.IEnumerator`1<UnityEngine.InputSystem.Utilities.Substring>
struct IEnumerator_1_t28314E682493CA936A454DA48BFB000CAF4F5D74;
// System.Collections.Generic.IEqualityComparer`1<UnityEngine.InputSystem.Utilities.InternedString>
struct IEqualityComparer_1_tEA6D87A5AB670819FF91305D215B209552281584;
// UnityEngine.InputSystem.InputBindingComposite`1<System.Single>
struct InputBindingComposite_1_t2D5E67CAF6C6931B703564ED5FF2CC1D32B9814E;
// UnityEngine.InputSystem.InputBindingComposite`1<UnityEngine.Vector2>
struct InputBindingComposite_1_tB7B7EA7F16E4FA573E09983CFE2AE8C7D4616588;
// UnityEngine.InputSystem.InputBindingComposite`1<UnityEngine.Vector3>
struct InputBindingComposite_1_t34CD8E199158A65EE0E5DBCE8CC705AF3C4B3306;
// System.Collections.Generic.Dictionary`2/KeyCollection<UnityEngine.InputSystem.Utilities.InternedString,System.Object>
struct KeyCollection_t443F242E6072F26AA8803C1BF50400B0692392C6;
// System.Collections.Generic.Dictionary`2/KeyCollection<UnityEngine.InputSystem.Utilities.InternedString,System.Type>
struct KeyCollection_tF0B6D6FBE89245B5B34798233471D53A6BF802A3;
// System.Collections.Generic.Dictionary`2/ValueCollection<UnityEngine.InputSystem.Utilities.InternedString,System.Type>
struct ValueCollection_tD63A626D1918F702C79B868362E823BDCFD426CD;
// System.Collections.Generic.Dictionary`2/Entry<UnityEngine.InputSystem.Utilities.InternedString,System.Type>[]
struct EntryU5BU5D_t05A444C605D7D354DA1A1A00317821912EB2F4A7;
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
// System.Diagnostics.StackTrace[]
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
// System.String[]
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
// System.Type[]
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
// System.ArgumentException
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263;
// System.ArgumentNullException
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129;
// System.ArgumentOutOfRangeException
struct ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F;
// UnityEngine.InputSystem.Composites.AxisComposite
struct AxisComposite_t9E3B9C369A8F748691611245821471645D31D2AC;
// System.Reflection.Binder
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
// UnityEngine.InputSystem.Composites.ButtonWithOneModifier
struct ButtonWithOneModifier_t407B77B4960C57B1DEC84F631F91B1E135343222;
// UnityEngine.InputSystem.Composites.ButtonWithTwoModifiers
struct ButtonWithTwoModifiers_tCA30378981527D0F306883EABED0657FA5FE7C59;
// System.DelegateData
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
// System.Reflection.FieldInfo
struct FieldInfo_t;
// System.Collections.IDictionary
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
// System.Collections.IEnumerator
struct IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA;
// UnityEngine.InputSystem.InputActionState
struct InputActionState_t780948EA293BAA800AD8699518B58B59FFB8A700;
// UnityEngine.InputSystem.InputBindingComposite
struct InputBindingComposite_tA9230435A30FB5B2D4967D6FAE7EFABBBF26C0C0;
// UnityEngine.InputSystem.InputControl
struct InputControl_t74F06B623518F992BF8E38656A5E0857169E3E2E;
// UnityEngine.InputSystem.InputDevice
struct InputDevice_t8BCF67533E872A75779C24C93D1D7085B72D364B;
// UnityEngine.InputSystem.InputSettings
struct InputSettings_tBA8835B505722A59702A08BCBA46ECF0B0274EEF;
// System.InvalidOperationException
struct InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB;
// System.Reflection.MemberFilter
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
// System.Reflection.MemberInfo
struct MemberInfo_t;
// System.Reflection.MethodInfo
struct MethodInfo_t;
// System.NotSupportedException
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A;
// UnityEngine.InputSystem.Composites.OneModifierComposite
struct OneModifierComposite_tC18745AC641308E913620A321BF1CCE00D60E55B;
// System.Reflection.PropertyInfo
struct PropertyInfo_t;
// System.Runtime.Serialization.SafeSerializationManager
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
// UnityEngine.Sprite
struct Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99;
// System.String
struct String_t;
// System.Text.StringBuilder
struct StringBuilder_t;
// UnityEngine.Texture2D
struct Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4;
// UnityEngine.InputSystem.Composites.TwoModifiersComposite
struct TwoModifiersComposite_t7B84C109D0750D4F515629DD0D3D5C6373F42CA3;
// System.Type
struct Type_t;
// UnityEngine.InputSystem.Composites.Vector2Composite
struct Vector2Composite_tCAE11D025FE085E66E963DCCD6559D042A713908;
// UnityEngine.InputSystem.Composites.Vector3Composite
struct Vector3Composite_t014892920D73110CD43E6CC997E0FAA5860A62E0;
// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
// UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9
struct U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF;
// UnityEngine.InputSystem.Utilities.StringHelpers/<Tokenize>d__8
struct U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B;
// UnityEngine.InputSystem.Utilities.TypeTable/<>c
struct U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA;

IL2CPP_EXTERN_C RuntimeClass* ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Char_t521A6F19B456D956AF452D926C32709DC03D6B17_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* FieldInfo_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Func_2_tE0082B3C229A425A69ECDABB19259709EC9F540F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerable_1_t45141F64D6D882336B8DCC6510DC6B9C3294C6AA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerator_1_t5AFCED6452B2551E59D8997046D5F19C8F731FB3_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* InputSystem_t4120CA4FE7DCFD56AF9391933FC3F1F485350164_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IntPtr_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* MethodInfo_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* PropertyInfo_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringBuilder_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* String_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Substring_t2E16755269E6716C22074D6BC0A9099915E67849_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Type_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeField* TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E____table_0_FieldInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral007174B876FA7EECC4152046B9308966D3E2B5B8;
IL2CPP_EXTERN_C String_t* _stringLiteral0BA8CB3B900ECEF5E697192B8CDA6B626EB0CE72;
IL2CPP_EXTERN_C String_t* _stringLiteral115036F179EA48E7662F9BE55E0E00A42DDE6DA7;
IL2CPP_EXTERN_C String_t* _stringLiteral14B651F3933E2742FD0FE0E45504AD43A5985248;
IL2CPP_EXTERN_C String_t* _stringLiteral1C62C7650E13E5763946286B7B28B980E977B33C;
IL2CPP_EXTERN_C String_t* _stringLiteral28F49FF685EF5968942FC2C44FA5408C4659B72C;
IL2CPP_EXTERN_C String_t* _stringLiteral2900020C8C73B769305C05646CF927B358E92966;
IL2CPP_EXTERN_C String_t* _stringLiteral294F098A1D5E681EDEE8F43BFA8F45CFBA5798A7;
IL2CPP_EXTERN_C String_t* _stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1;
IL2CPP_EXTERN_C String_t* _stringLiteral316316045E2DB71BB9C0748EE882DBF00C83FD8E;
IL2CPP_EXTERN_C String_t* _stringLiteral3775297E15AD530F68BA7AF3896E3A261B24AD81;
IL2CPP_EXTERN_C String_t* _stringLiteral38FB386B58970DA493E868CAC2AC6550E559B5D7;
IL2CPP_EXTERN_C String_t* _stringLiteral54955F5500C6186211E2357D711CD0C3E4017D6B;
IL2CPP_EXTERN_C String_t* _stringLiteral5AEDE79F00BF8508555B948D1DE12F274399430A;
IL2CPP_EXTERN_C String_t* _stringLiteral628D1F19515023762299C5A2AF8A34A399049CE6;
IL2CPP_EXTERN_C String_t* _stringLiteral7720D93C700AB5486B175C224CEF31CC1C99380B;
IL2CPP_EXTERN_C String_t* _stringLiteral82BA8BFC18D84C67108B27396795EDFAEE187B83;
IL2CPP_EXTERN_C String_t* _stringLiteral8494AF0C90D5A0F8C5D03F528442880CE6820192;
IL2CPP_EXTERN_C String_t* _stringLiteral88B5D0E6F79C8EDF1FD287D9EBCA6E2CBBA34F67;
IL2CPP_EXTERN_C String_t* _stringLiteralA185F0FDE2E3A93D140F407291AA8AA60D14D5DA;
IL2CPP_EXTERN_C String_t* _stringLiteralAF29A356E2E2350A3712E86EFEC38A631035EEDC;
IL2CPP_EXTERN_C String_t* _stringLiteralBFCC6EE94F1B7AA05A04750903E25F93A7188AE0;
IL2CPP_EXTERN_C String_t* _stringLiteralC205D54CE3878136AF6661FE2D0B347BEC57D5AB;
IL2CPP_EXTERN_C String_t* _stringLiteralC263EA29ADF3548CFEBC57B532EED28451A56C10;
IL2CPP_EXTERN_C String_t* _stringLiteralC3002A2B85A3B7DFD395054441915FBAB742D4EE;
IL2CPP_EXTERN_C String_t* _stringLiteralC4E550DB7753938B55BD2444CB204B2C254AF826;
IL2CPP_EXTERN_C String_t* _stringLiteralCE18B047107AA23D1AA9B2ED32D316148E02655F;
IL2CPP_EXTERN_C String_t* _stringLiteralCFDA33CEC1161BE8CA5B06D2480EA1925FA4ACBE;
IL2CPP_EXTERN_C String_t* _stringLiteralD6315798FF47A5A5AB2AD03739B4783B2AD1305B;
IL2CPP_EXTERN_C String_t* _stringLiteralD890B2BC5E5200965CD02403ABB6C221A614A1B7;
IL2CPP_EXTERN_C String_t* _stringLiteralDAF2BD03270A51BF9C135F3694DCAD2D3E66F465;
IL2CPP_EXTERN_C String_t* _stringLiteralDE7D042A807341C354F398C43F38F92D9AFDAA21;
IL2CPP_EXTERN_C String_t* _stringLiteralE1E5CE10BE86E259146E8ADE82FB423C65C3FFD7;
IL2CPP_EXTERN_C String_t* _stringLiteralE3165827D406DD8F354BE7515C630A771E98916A;
IL2CPP_EXTERN_C String_t* _stringLiteralE3AB954C27345B5777E41817C31696D6AC0E87C1;
IL2CPP_EXTERN_C String_t* _stringLiteralE3DFC065B6A6D9931B797808DD066491AAB82B29;
IL2CPP_EXTERN_C String_t* _stringLiteralEE71910C7E19B0D89B96AF6011CDFDAF6EA1CF1C;
IL2CPP_EXTERN_C String_t* _stringLiteralF1E972CD03013DE732424893507C3C55D004E089;
IL2CPP_EXTERN_C String_t* _stringLiteralF3C6C902DBF80139640F6554F0C3392016A8ADF7;
IL2CPP_EXTERN_C String_t* _stringLiteralF3FEA1B7EED06B84D345A14D3BB9E817F4B9EAFE;
IL2CPP_EXTERN_C String_t* _stringLiteralF4D7DE161067DE7FFAB264EC7D3DCF921ADBA5A5;
IL2CPP_EXTERN_C String_t* _stringLiteralF58E021D305C0B41C91B9C363C9DBF5F652FDAE9;
IL2CPP_EXTERN_C String_t* _stringLiteralFE3CDBE9D3C244138D4F64C1BEB914490F7E7BBD;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_GetEnumerator_m09228E70F30816068825C9BB4B45519E7143CE7A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_TryGetValue_m4AFE96490465DE101600F734AF44C7E4AE513860_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_mD10EC6AB3D41E49C23882A85B368A08800DFC5EE_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_get_Keys_mFDE9D7FC672A995E064B6F14DBC9EB0B0D15BFAF_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_set_Item_mACF6DD3A83F9F41061E7C4DD48F58C07BFAA31C7_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerable_Select_TisInternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_TisString_t_m3FCCE6DBA6A159830BE8363BF5BA444BCBF4B186_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_Dispose_m767111BF89218E9F0CD407F44CD9FF1CC6079B87_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_MoveNext_mEB31860F9718BC0DB2D231F91D9A78D9666B54EF_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_get_Current_m8161C19F09FC9E5EFD3BCE87B8907B3F660FFF51_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* InputBindingComposite_1__ctor_m652D65F50D8E8B067F415C8EB34CBB411E3037C8_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* InputBindingComposite_1__ctor_m7A3EC8A3F30D4FD3E13C1FDD38CFB5B41B461545_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* InputBindingComposite_1__ctor_mCC1C23E6E7958682F8F851C7EF1C1C179E21D789_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* KeyValuePair_2_get_Key_mE8768535ABCD24F453DC1EC5127CBD303DEC29A5_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* KeyValuePair_2_get_Value_m9803DE61209750BB22E4E1A58A5DFB943EAFCB80_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* NativeArrayUnsafeUtility_GetUnsafePtr_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m20D988AA4B5A020595A6FF21F9B26D67BF73B76E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* StringHelpers_CharacterSeparatedListsHaveAtLeastOneCommonElement_m0A3E70D748E3E17DEA06FAD3553F3049F169A190_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* StringHelpers_ExpandTemplateString_mA00BD22DF8D3C21CF5DB7420C5BAB9935B5EF86B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* StringHelpers_GetPlural_m5A928581053494366B2905658A9919737955AEBA_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* StringHelpers_ReadStringFromBuffer_m08BAA47EF90D3F3A74A8AA354871C18FA7D9B8D2_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* StringHelpers_WriteStringToBuffer_m0719C102DC096F1A565020ED8D1B71BC6B26B8DF_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Substring_get_Item_m278F3C7634F20487F36267C4BD49BC96DAE4CAC4_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Texture2D_GetRawTextureData_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m3F258FE3486B29D798DCFECF41E9845382EF5CC2_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TypeHelpers_GetGenericTypeArgumentFromHierarchy_m9CE3EA9B8DFBBBC2BD6BFB81B4D66FB6922C089C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TypeTable_AddTypeRegistration_mAC83549CC944F2EE8371A00B82B203B9B8DD5B7E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TypeTable_FindNameForType_m5974594EAAEB68C4488B8C9CFABF931B7666FB00_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* TypeTable_LookupTypeRegistration_m89DCEA471CDF7CDB994D67D3726482805C0AE29A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CSplitU3Ed__9_System_Collections_IEnumerator_Reset_mB5816591871F45CED738B000C124AECD6783056C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CTokenizeU3Ed__8_System_Collections_IEnumerator_Reset_m8FB2BAFA8C54922ACD753AA18C5D50CDFC31B3C8_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CU3Ec_U3Cget_namesU3Eb__2_0_m106D3E5FF1FBF96009877C31E3F0684CD8943EC9_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* UnsafeUtility_SizeOf_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m506739DDFD44F4F6CE36D20C36BFA90D7F56E4AE_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeType* Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* RuntimeObject_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_0_0_0_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Collections.Generic.Dictionary`2<UnityEngine.InputSystem.Utilities.InternedString,System.Type>
struct Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_t05A444C605D7D354DA1A1A00317821912EB2F4A7* ____entries_1;
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
	KeyCollection_tF0B6D6FBE89245B5B34798233471D53A6BF802A3* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_tD63A626D1918F702C79B868362E823BDCFD426CD* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.Collections.Generic.Dictionary`2/KeyCollection<UnityEngine.InputSystem.Utilities.InternedString,System.Type>
struct KeyCollection_tF0B6D6FBE89245B5B34798233471D53A6BF802A3  : public RuntimeObject
{
	// System.Collections.Generic.Dictionary`2<TKey,TValue> System.Collections.Generic.Dictionary`2/KeyCollection::_dictionary
	Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D* ____dictionary_0;
};

// <PrivateImplementationDetails>
struct U3CPrivateImplementationDetailsU3E_tF62B85DD2C59D87BA6C8DA02965E1F3203A64E53  : public RuntimeObject
{
};

// UnityEngine.InputSystem.InputBindingComposite
struct InputBindingComposite_tA9230435A30FB5B2D4967D6FAE7EFABBBF26C0C0  : public RuntimeObject
{
};

// System.Reflection.MemberInfo
struct MemberInfo_t  : public RuntimeObject
{
};

// UnityEngine.InputSystem.Utilities.ReadOnlyArrayExtensions
struct ReadOnlyArrayExtensions_tC3315EA41D787AC9DE011A2E5D9A771E37FAE61D  : public RuntimeObject
{
};

// UnityEngine.InputSystem.Utilities.SpriteUtilities
struct SpriteUtilities_t68F11FCB248E3C90D3E11B9E416710AB689D6518  : public RuntimeObject
{
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

// UnityEngine.InputSystem.Utilities.StringHelpers
struct StringHelpers_t3FFB10FA36ABE7FB6496D420593169678B21AC3D  : public RuntimeObject
{
};

// UnityEngine.InputSystem.Utilities.TypeHelpers
struct TypeHelpers_tF2D4804F9906DD09986DC5852EE53402EA9B3FA3  : public RuntimeObject
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

// UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9
struct U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF  : public RuntimeObject
{
	// System.Int32 UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9::<>1__state
	int32_t ___U3CU3E1__state_0;
	// System.String UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9::<>2__current
	String_t* ___U3CU3E2__current_1;
	// System.Int32 UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9::<>l__initialThreadId
	int32_t ___U3CU3El__initialThreadId_2;
	// System.String UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9::str
	String_t* ___str_3;
	// System.String UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9::<>3__str
	String_t* ___U3CU3E3__str_4;
	// System.Func`2<System.Char,System.Boolean> UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9::predicate
	Func_2_tF409A653B8F770E0A30CD80D21764FB1DDB2A28F* ___predicate_5;
	// System.Func`2<System.Char,System.Boolean> UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9::<>3__predicate
	Func_2_tF409A653B8F770E0A30CD80D21764FB1DDB2A28F* ___U3CU3E3__predicate_6;
	// System.Int32 UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9::<length>5__2
	int32_t ___U3ClengthU3E5__2_7;
	// System.Int32 UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9::<position>5__3
	int32_t ___U3CpositionU3E5__3_8;
};

// UnityEngine.InputSystem.Utilities.TypeTable/<>c
struct U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA  : public RuntimeObject
{
};

// UnityEngine.InputSystem.InputBindingComposite`1<System.Single>
struct InputBindingComposite_1_t2D5E67CAF6C6931B703564ED5FF2CC1D32B9814E  : public InputBindingComposite_tA9230435A30FB5B2D4967D6FAE7EFABBBF26C0C0
{
};

// UnityEngine.InputSystem.InputBindingComposite`1<UnityEngine.Vector2>
struct InputBindingComposite_1_tB7B7EA7F16E4FA573E09983CFE2AE8C7D4616588  : public InputBindingComposite_tA9230435A30FB5B2D4967D6FAE7EFABBBF26C0C0
{
};

// UnityEngine.InputSystem.InputBindingComposite`1<UnityEngine.Vector3>
struct InputBindingComposite_1_t34CD8E199158A65EE0E5DBCE8CC705AF3C4B3306  : public InputBindingComposite_tA9230435A30FB5B2D4967D6FAE7EFABBBF26C0C0
{
};

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	// System.Boolean System.Boolean::m_value
	bool ___m_value_0;
};

// System.Byte
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	// System.Byte System.Byte::m_value
	uint8_t ___m_value_0;
};

// System.Char
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17 
{
	// System.Char System.Char::m_value
	Il2CppChar ___m_value_0;
};

// UnityEngine.Color32
struct Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			// System.Int32 UnityEngine.Color32::rgba
			int32_t ___rgba_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int32_t ___rgba_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			// System.Byte UnityEngine.Color32::r
			uint8_t ___r_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint8_t ___r_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___g_2_OffsetPadding[1];
			// System.Byte UnityEngine.Color32::g
			uint8_t ___g_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___g_2_OffsetPadding_forAlignmentOnly[1];
			uint8_t ___g_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___b_3_OffsetPadding[2];
			// System.Byte UnityEngine.Color32::b
			uint8_t ___b_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___b_3_OffsetPadding_forAlignmentOnly[2];
			uint8_t ___b_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___a_4_OffsetPadding[3];
			// System.Byte UnityEngine.Color32::a
			uint8_t ___a_4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___a_4_OffsetPadding_forAlignmentOnly[3];
			uint8_t ___a_4_forAlignmentOnly;
		};
	};
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

// System.Reflection.FieldInfo
struct FieldInfo_t  : public MemberInfo_t
{
};

// UnityEngine.InputSystem.Utilities.FourCC
struct FourCC_tA6CAA4015BC25A7F1053B6C512202D57A9C994ED 
{
	// System.Int32 UnityEngine.InputSystem.Utilities.FourCC::m_Code
	int32_t ___m_Code_0;
};

// UnityEngine.InputSystem.InputBindingCompositeContext
struct InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390 
{
	// UnityEngine.InputSystem.InputActionState UnityEngine.InputSystem.InputBindingCompositeContext::m_State
	InputActionState_t780948EA293BAA800AD8699518B58B59FFB8A700* ___m_State_0;
	// System.Int32 UnityEngine.InputSystem.InputBindingCompositeContext::m_BindingIndex
	int32_t ___m_BindingIndex_1;
};
// Native definition for P/Invoke marshalling of UnityEngine.InputSystem.InputBindingCompositeContext
struct InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390_marshaled_pinvoke
{
	InputActionState_t780948EA293BAA800AD8699518B58B59FFB8A700* ___m_State_0;
	int32_t ___m_BindingIndex_1;
};
// Native definition for COM marshalling of UnityEngine.InputSystem.InputBindingCompositeContext
struct InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390_marshaled_com
{
	InputActionState_t780948EA293BAA800AD8699518B58B59FFB8A700* ___m_State_0;
	int32_t ___m_BindingIndex_1;
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

// UnityEngine.InputSystem.Utilities.InternedString
struct InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 
{
	// System.String UnityEngine.InputSystem.Utilities.InternedString::m_StringOriginalCase
	String_t* ___m_StringOriginalCase_0;
	// System.String UnityEngine.InputSystem.Utilities.InternedString::m_StringLowerCase
	String_t* ___m_StringLowerCase_1;
};
// Native definition for P/Invoke marshalling of UnityEngine.InputSystem.Utilities.InternedString
struct InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_marshaled_pinvoke
{
	char* ___m_StringOriginalCase_0;
	char* ___m_StringLowerCase_1;
};
// Native definition for COM marshalling of UnityEngine.InputSystem.Utilities.InternedString
struct InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_marshaled_com
{
	Il2CppChar* ___m_StringOriginalCase_0;
	Il2CppChar* ___m_StringLowerCase_1;
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

// System.Reflection.MethodBase
struct MethodBase_t  : public MemberInfo_t
{
};

// UnityEngine.InputSystem.Composites.OneModifierComposite
struct OneModifierComposite_tC18745AC641308E913620A321BF1CCE00D60E55B  : public InputBindingComposite_tA9230435A30FB5B2D4967D6FAE7EFABBBF26C0C0
{
	// System.Int32 UnityEngine.InputSystem.Composites.OneModifierComposite::modifier
	int32_t ___modifier_1;
	// System.Int32 UnityEngine.InputSystem.Composites.OneModifierComposite::binding
	int32_t ___binding_2;
	// System.Boolean UnityEngine.InputSystem.Composites.OneModifierComposite::overrideModifiersNeedToBePressedFirst
	bool ___overrideModifiersNeedToBePressedFirst_3;
	// System.Int32 UnityEngine.InputSystem.Composites.OneModifierComposite::m_ValueSizeInBytes
	int32_t ___m_ValueSizeInBytes_4;
	// System.Type UnityEngine.InputSystem.Composites.OneModifierComposite::m_ValueType
	Type_t* ___m_ValueType_5;
	// System.Boolean UnityEngine.InputSystem.Composites.OneModifierComposite::m_BindingIsButton
	bool ___m_BindingIsButton_6;
};

// System.Reflection.PropertyInfo
struct PropertyInfo_t  : public MemberInfo_t
{
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

// UnityEngine.InputSystem.Utilities.Substring
struct Substring_t2E16755269E6716C22074D6BC0A9099915E67849 
{
	// System.String UnityEngine.InputSystem.Utilities.Substring::m_String
	String_t* ___m_String_0;
	// System.Int32 UnityEngine.InputSystem.Utilities.Substring::m_Index
	int32_t ___m_Index_1;
	// System.Int32 UnityEngine.InputSystem.Utilities.Substring::m_Length
	int32_t ___m_Length_2;
};
// Native definition for P/Invoke marshalling of UnityEngine.InputSystem.Utilities.Substring
struct Substring_t2E16755269E6716C22074D6BC0A9099915E67849_marshaled_pinvoke
{
	char* ___m_String_0;
	int32_t ___m_Index_1;
	int32_t ___m_Length_2;
};
// Native definition for COM marshalling of UnityEngine.InputSystem.Utilities.Substring
struct Substring_t2E16755269E6716C22074D6BC0A9099915E67849_marshaled_com
{
	Il2CppChar* ___m_String_0;
	int32_t ___m_Index_1;
	int32_t ___m_Length_2;
};

// UnityEngine.InputSystem.Composites.TwoModifiersComposite
struct TwoModifiersComposite_t7B84C109D0750D4F515629DD0D3D5C6373F42CA3  : public InputBindingComposite_tA9230435A30FB5B2D4967D6FAE7EFABBBF26C0C0
{
	// System.Int32 UnityEngine.InputSystem.Composites.TwoModifiersComposite::modifier1
	int32_t ___modifier1_1;
	// System.Int32 UnityEngine.InputSystem.Composites.TwoModifiersComposite::modifier2
	int32_t ___modifier2_2;
	// System.Int32 UnityEngine.InputSystem.Composites.TwoModifiersComposite::binding
	int32_t ___binding_3;
	// System.Boolean UnityEngine.InputSystem.Composites.TwoModifiersComposite::overrideModifiersNeedToBePressedFirst
	bool ___overrideModifiersNeedToBePressedFirst_4;
	// System.Int32 UnityEngine.InputSystem.Composites.TwoModifiersComposite::m_ValueSizeInBytes
	int32_t ___m_ValueSizeInBytes_5;
	// System.Type UnityEngine.InputSystem.Composites.TwoModifiersComposite::m_ValueType
	Type_t* ___m_ValueType_6;
	// System.Boolean UnityEngine.InputSystem.Composites.TwoModifiersComposite::m_BindingIsButton
	bool ___m_BindingIsButton_7;
};

// UnityEngine.InputSystem.Utilities.TypeTable
struct TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E 
{
	// System.Collections.Generic.Dictionary`2<UnityEngine.InputSystem.Utilities.InternedString,System.Type> UnityEngine.InputSystem.Utilities.TypeTable::table
	Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D* ___table_0;
};
// Native definition for P/Invoke marshalling of UnityEngine.InputSystem.Utilities.TypeTable
struct TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_marshaled_pinvoke
{
	Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D* ___table_0;
};
// Native definition for COM marshalling of UnityEngine.InputSystem.Utilities.TypeTable
struct TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_marshaled_com
{
	Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D* ___table_0;
};

// System.UInt16
struct UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455 
{
	// System.UInt16 System.UInt16::m_value
	uint16_t ___m_value_0;
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

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=1038
struct __StaticArrayInitTypeSizeU3D1038_tC28C31F75224CEC520DB0A52F7C747BDF0E8A242 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D1038_tC28C31F75224CEC520DB0A52F7C747BDF0E8A242__padding[1038];
	};
};

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=104
struct __StaticArrayInitTypeSizeU3D104_tA1677EB9042DF28F651C756F41B1B978A10472EA 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D104_tA1677EB9042DF28F651C756F41B1B978A10472EA__padding[104];
	};
};

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=1575
struct __StaticArrayInitTypeSizeU3D1575_tA8B5FF47C1B66730DBCAE65E998D5358992BC062 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D1575_tA8B5FF47C1B66730DBCAE65E998D5358992BC062__padding[1575];
	};
};

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=234
struct __StaticArrayInitTypeSizeU3D234_t6F71BB8FF9822A3A3833BAB22E81F6B6955A781F 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D234_t6F71BB8FF9822A3A3833BAB22E81F6B6955A781F__padding[234];
	};
};

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=24
struct __StaticArrayInitTypeSizeU3D24_t226C5F521B67F6FD3E9C29695114434A267A6141 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D24_t226C5F521B67F6FD3E9C29695114434A267A6141__padding[24];
	};
};

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=371
struct __StaticArrayInitTypeSizeU3D371_tE9F5A574450793E6E499EB69CDD3047D5F5F00F9 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D371_tE9F5A574450793E6E499EB69CDD3047D5F5F00F9__padding[371];
	};
};

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=4011
struct __StaticArrayInitTypeSizeU3D4011_tC6D32A64151F5DC52182F93CCD84032758712B89 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D4011_tC6D32A64151F5DC52182F93CCD84032758712B89__padding[4011];
	};
};

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=460
struct __StaticArrayInitTypeSizeU3D460_t4ABB4E2DEDD6BE50A063561639D025CC2BDD5394 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D460_t4ABB4E2DEDD6BE50A063561639D025CC2BDD5394__padding[460];
	};
};

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=84
struct __StaticArrayInitTypeSizeU3D84_t625EC17B34CB913B5E4B2EA6DB080F5BAF99EAEC 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D84_t625EC17B34CB913B5E4B2EA6DB080F5BAF99EAEC__padding[84];
	};
};

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=976
struct __StaticArrayInitTypeSizeU3D976_t61AF54C311BB0D3BB3FA5795EB3A69AFB6A26BA0 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D976_t61AF54C311BB0D3BB3FA5795EB3A69AFB6A26BA0__padding[976];
	};
};

// UnityEngine.InputSystem.InputBindingCompositeContext/PartBinding
struct PartBinding_tB263B939F5CC92F02FD1C8892A194F9BC8A53D38 
{
	// System.Int32 UnityEngine.InputSystem.InputBindingCompositeContext/PartBinding::<part>k__BackingField
	int32_t ___U3CpartU3Ek__BackingField_0;
	// UnityEngine.InputSystem.InputControl UnityEngine.InputSystem.InputBindingCompositeContext/PartBinding::<control>k__BackingField
	InputControl_t74F06B623518F992BF8E38656A5E0857169E3E2E* ___U3CcontrolU3Ek__BackingField_1;
};
// Native definition for P/Invoke marshalling of UnityEngine.InputSystem.InputBindingCompositeContext/PartBinding
struct PartBinding_tB263B939F5CC92F02FD1C8892A194F9BC8A53D38_marshaled_pinvoke
{
	int32_t ___U3CpartU3Ek__BackingField_0;
	InputControl_t74F06B623518F992BF8E38656A5E0857169E3E2E* ___U3CcontrolU3Ek__BackingField_1;
};
// Native definition for COM marshalling of UnityEngine.InputSystem.InputBindingCompositeContext/PartBinding
struct PartBinding_tB263B939F5CC92F02FD1C8892A194F9BC8A53D38_marshaled_com
{
	int32_t ___U3CpartU3Ek__BackingField_0;
	InputControl_t74F06B623518F992BF8E38656A5E0857169E3E2E* ___U3CcontrolU3Ek__BackingField_1;
};

// System.Collections.Generic.KeyValuePair`2<UnityEngine.InputSystem.Utilities.InternedString,System.Object>
struct KeyValuePair_2_tC24A74EF64A292F5C6BA77D0B04CD6620D2DE3AC 
{
	// TKey System.Collections.Generic.KeyValuePair`2::key
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___key_0;
	// TValue System.Collections.Generic.KeyValuePair`2::value
	RuntimeObject* ___value_1;
};

// System.Collections.Generic.KeyValuePair`2<UnityEngine.InputSystem.Utilities.InternedString,System.Type>
struct KeyValuePair_2_t859F90B137C9291C0E478FBE85ABB18F30B91A27 
{
	// TKey System.Collections.Generic.KeyValuePair`2::key
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___key_0;
	// TValue System.Collections.Generic.KeyValuePair`2::value
	Type_t* ___value_1;
};

// Unity.Collections.Allocator
struct Allocator_t996642592271AAD9EE688F142741D512C07B5824 
{
	// System.Int32 Unity.Collections.Allocator::value__
	int32_t ___value___2;
};

// UnityEngine.InputSystem.Composites.ButtonWithOneModifier
struct ButtonWithOneModifier_t407B77B4960C57B1DEC84F631F91B1E135343222  : public InputBindingComposite_1_t2D5E67CAF6C6931B703564ED5FF2CC1D32B9814E
{
	// System.Int32 UnityEngine.InputSystem.Composites.ButtonWithOneModifier::modifier
	int32_t ___modifier_1;
	// System.Int32 UnityEngine.InputSystem.Composites.ButtonWithOneModifier::button
	int32_t ___button_2;
	// System.Boolean UnityEngine.InputSystem.Composites.ButtonWithOneModifier::overrideModifiersNeedToBePressedFirst
	bool ___overrideModifiersNeedToBePressedFirst_3;
};

// UnityEngine.InputSystem.Composites.ButtonWithTwoModifiers
struct ButtonWithTwoModifiers_tCA30378981527D0F306883EABED0657FA5FE7C59  : public InputBindingComposite_1_t2D5E67CAF6C6931B703564ED5FF2CC1D32B9814E
{
	// System.Int32 UnityEngine.InputSystem.Composites.ButtonWithTwoModifiers::modifier1
	int32_t ___modifier1_1;
	// System.Int32 UnityEngine.InputSystem.Composites.ButtonWithTwoModifiers::modifier2
	int32_t ___modifier2_2;
	// System.Int32 UnityEngine.InputSystem.Composites.ButtonWithTwoModifiers::button
	int32_t ___button_3;
	// System.Boolean UnityEngine.InputSystem.Composites.ButtonWithTwoModifiers::overrideModifiersNeedToBePressedFirst
	bool ___overrideModifiersNeedToBePressedFirst_4;
};

// UnityEngine.Experimental.Rendering.DefaultFormat
struct DefaultFormat_t76E7B829061170DA4EE4B2B6574C47DD182B7BF3 
{
	// System.Int32 UnityEngine.Experimental.Rendering.DefaultFormat::value__
	int32_t ___value___2;
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

// UnityEngine.InputSystem.LowLevel.InputStateBlock
struct InputStateBlock_t0E05211ACF29A99C0FE7FC9EA7042196BFF1F3B5 
{
	// UnityEngine.InputSystem.Utilities.FourCC UnityEngine.InputSystem.LowLevel.InputStateBlock::<format>k__BackingField
	FourCC_tA6CAA4015BC25A7F1053B6C512202D57A9C994ED ___U3CformatU3Ek__BackingField_40;
	// System.UInt32 UnityEngine.InputSystem.LowLevel.InputStateBlock::m_ByteOffset
	uint32_t ___m_ByteOffset_41;
	// System.UInt32 UnityEngine.InputSystem.LowLevel.InputStateBlock::<bitOffset>k__BackingField
	uint32_t ___U3CbitOffsetU3Ek__BackingField_42;
	// System.UInt32 UnityEngine.InputSystem.LowLevel.InputStateBlock::<sizeInBits>k__BackingField
	uint32_t ___U3CsizeInBitsU3Ek__BackingField_43;
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

// System.RuntimeTypeHandle
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	// System.IntPtr System.RuntimeTypeHandle::value
	intptr_t ___value_0;
};

// UnityEngine.SpriteMeshType
struct SpriteMeshType_t7CB782FB09795AB29328035B4D802242FBADD7FB 
{
	// System.Int32 UnityEngine.SpriteMeshType::value__
	int32_t ___value___2;
};

// System.StringComparison
struct StringComparison_tE14A55CCFA001A5AC85D754179BF2888F45CC94D 
{
	// System.Int32 System.StringComparison::value__
	int32_t ___value___2;
};

// UnityEngine.Experimental.Rendering.TextureCreationFlags
struct TextureCreationFlags_t7671FF285C96A03BDCD7BA2F50388C09ED4A54A3 
{
	// System.Int32 UnityEngine.Experimental.Rendering.TextureCreationFlags::value__
	int32_t ___value___2;
};

// System.TypeCode
struct TypeCode_tBEF9BE86C8BCF5A6B82F3381219738D27804EF79 
{
	// System.Int32 System.TypeCode::value__
	int32_t ___value___2;
};

// UnityEngine.InputSystem.Composites.AxisComposite/WhichSideWins
struct WhichSideWins_t628E6122D6B0C02EEF82EA347AA5665EB690E862 
{
	// System.Int32 UnityEngine.InputSystem.Composites.AxisComposite/WhichSideWins::value__
	int32_t ___value___2;
};

// UnityEngine.InputSystem.InputControl/ControlFlags
struct ControlFlags_t9C297F208DE19CEB00A0560F7FDE59F6A2004132 
{
	// System.Int32 UnityEngine.InputSystem.InputControl/ControlFlags::value__
	int32_t ___value___2;
};

// UnityEngine.InputSystem.InputSettings/BackgroundBehavior
struct BackgroundBehavior_t4D397A0FC3ECD31C1A4DB8C2D09BBC4E71BFC1D6 
{
	// System.Int32 UnityEngine.InputSystem.InputSettings/BackgroundBehavior::value__
	int32_t ___value___2;
};

// UnityEngine.InputSystem.InputSettings/EditorInputBehaviorInPlayMode
struct EditorInputBehaviorInPlayMode_tC47B44FACCF39F8E2DCA21270D51417B5DEF814D 
{
	// System.Int32 UnityEngine.InputSystem.InputSettings/EditorInputBehaviorInPlayMode::value__
	int32_t ___value___2;
};

// UnityEngine.InputSystem.InputSettings/UpdateMode
struct UpdateMode_tCD49766B755C4CD8E1F2DE8D57798DAC2C5CBF32 
{
	// System.Int32 UnityEngine.InputSystem.InputSettings/UpdateMode::value__
	int32_t ___value___2;
};

// UnityEngine.InputSystem.Utilities.StringHelpers/<Tokenize>d__8
struct U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B  : public RuntimeObject
{
	// System.Int32 UnityEngine.InputSystem.Utilities.StringHelpers/<Tokenize>d__8::<>1__state
	int32_t ___U3CU3E1__state_0;
	// UnityEngine.InputSystem.Utilities.Substring UnityEngine.InputSystem.Utilities.StringHelpers/<Tokenize>d__8::<>2__current
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___U3CU3E2__current_1;
	// System.Int32 UnityEngine.InputSystem.Utilities.StringHelpers/<Tokenize>d__8::<>l__initialThreadId
	int32_t ___U3CU3El__initialThreadId_2;
	// System.String UnityEngine.InputSystem.Utilities.StringHelpers/<Tokenize>d__8::str
	String_t* ___str_3;
	// System.String UnityEngine.InputSystem.Utilities.StringHelpers/<Tokenize>d__8::<>3__str
	String_t* ___U3CU3E3__str_4;
	// System.Int32 UnityEngine.InputSystem.Utilities.StringHelpers/<Tokenize>d__8::<length>5__2
	int32_t ___U3ClengthU3E5__2_5;
	// System.Int32 UnityEngine.InputSystem.Utilities.StringHelpers/<Tokenize>d__8::<endPos>5__3
	int32_t ___U3CendPosU3E5__3_6;
};

// UnityEngine.InputSystem.Composites.Vector2Composite/Mode
struct Mode_tC3E9CF3E48612D8E2FD67CDBA91095417B9124B6 
{
	// System.Int32 UnityEngine.InputSystem.Composites.Vector2Composite/Mode::value__
	int32_t ___value___2;
};

// UnityEngine.InputSystem.Composites.Vector3Composite/Mode
struct Mode_t32EC4762B4B95EDB16453EDE0DF14640CE841CA0 
{
	// System.Int32 UnityEngine.InputSystem.Composites.Vector3Composite/Mode::value__
	int32_t ___value___2;
};

// System.Collections.Generic.Dictionary`2/Enumerator<UnityEngine.InputSystem.Utilities.InternedString,System.Object>
struct Enumerator_tA3FD4A2E68B869CA74DA02EF77286DF5BFB3FE31 
{
	// System.Collections.Generic.Dictionary`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator::_dictionary
	Dictionary_2_t25574638E247E1D55E6ED2A97A5C38F3EBA31BA9* ____dictionary_0;
	// System.Int32 System.Collections.Generic.Dictionary`2/Enumerator::_version
	int32_t ____version_1;
	// System.Int32 System.Collections.Generic.Dictionary`2/Enumerator::_index
	int32_t ____index_2;
	// System.Collections.Generic.KeyValuePair`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator::_current
	KeyValuePair_2_tC24A74EF64A292F5C6BA77D0B04CD6620D2DE3AC ____current_3;
	// System.Int32 System.Collections.Generic.Dictionary`2/Enumerator::_getEnumeratorRetType
	int32_t ____getEnumeratorRetType_4;
};

// System.Collections.Generic.Dictionary`2/Enumerator<UnityEngine.InputSystem.Utilities.InternedString,System.Type>
struct Enumerator_tC7FEC7C0C46B33E076C8049925C674971CBC97DE 
{
	// System.Collections.Generic.Dictionary`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator::_dictionary
	Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D* ____dictionary_0;
	// System.Int32 System.Collections.Generic.Dictionary`2/Enumerator::_version
	int32_t ____version_1;
	// System.Int32 System.Collections.Generic.Dictionary`2/Enumerator::_index
	int32_t ____index_2;
	// System.Collections.Generic.KeyValuePair`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator::_current
	KeyValuePair_2_t859F90B137C9291C0E478FBE85ABB18F30B91A27 ____current_3;
	// System.Int32 System.Collections.Generic.Dictionary`2/Enumerator::_getEnumeratorRetType
	int32_t ____getEnumeratorRetType_4;
};

// Unity.Collections.NativeArray`1<UnityEngine.Color32>
struct NativeArray_1_t0783F5E3C7AF6C600A6A20DA7A32D82CA836528D 
{
	// System.Void* Unity.Collections.NativeArray`1::m_Buffer
	void* ___m_Buffer_0;
	// System.Int32 Unity.Collections.NativeArray`1::m_Length
	int32_t ___m_Length_1;
	// Unity.Collections.Allocator Unity.Collections.NativeArray`1::m_AllocatorLabel
	int32_t ___m_AllocatorLabel_2;
};

// UnityEngine.InputSystem.Composites.AxisComposite
struct AxisComposite_t9E3B9C369A8F748691611245821471645D31D2AC  : public InputBindingComposite_1_t2D5E67CAF6C6931B703564ED5FF2CC1D32B9814E
{
	// System.Int32 UnityEngine.InputSystem.Composites.AxisComposite::negative
	int32_t ___negative_1;
	// System.Int32 UnityEngine.InputSystem.Composites.AxisComposite::positive
	int32_t ___positive_2;
	// System.Single UnityEngine.InputSystem.Composites.AxisComposite::minValue
	float ___minValue_3;
	// System.Single UnityEngine.InputSystem.Composites.AxisComposite::maxValue
	float ___maxValue_4;
	// UnityEngine.InputSystem.Composites.AxisComposite/WhichSideWins UnityEngine.InputSystem.Composites.AxisComposite::whichSideWins
	int32_t ___whichSideWins_5;
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

// UnityEngine.InputSystem.Utilities.PrimitiveValue
struct PrimitiveValue_t1CC37566F40746757D5E3F87474A05909D85C2D4 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			// System.TypeCode UnityEngine.InputSystem.Utilities.PrimitiveValue::m_Type
			int32_t ___m_Type_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int32_t ___m_Type_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_BoolValue_1_OffsetPadding[4];
			// System.Boolean UnityEngine.InputSystem.Utilities.PrimitiveValue::m_BoolValue
			bool ___m_BoolValue_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_BoolValue_1_OffsetPadding_forAlignmentOnly[4];
			bool ___m_BoolValue_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_CharValue_2_OffsetPadding[4];
			// System.Char UnityEngine.InputSystem.Utilities.PrimitiveValue::m_CharValue
			Il2CppChar ___m_CharValue_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_CharValue_2_OffsetPadding_forAlignmentOnly[4];
			Il2CppChar ___m_CharValue_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_ByteValue_3_OffsetPadding[4];
			// System.Byte UnityEngine.InputSystem.Utilities.PrimitiveValue::m_ByteValue
			uint8_t ___m_ByteValue_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_ByteValue_3_OffsetPadding_forAlignmentOnly[4];
			uint8_t ___m_ByteValue_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_SByteValue_4_OffsetPadding[4];
			// System.SByte UnityEngine.InputSystem.Utilities.PrimitiveValue::m_SByteValue
			int8_t ___m_SByteValue_4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_SByteValue_4_OffsetPadding_forAlignmentOnly[4];
			int8_t ___m_SByteValue_4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_ShortValue_5_OffsetPadding[4];
			// System.Int16 UnityEngine.InputSystem.Utilities.PrimitiveValue::m_ShortValue
			int16_t ___m_ShortValue_5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_ShortValue_5_OffsetPadding_forAlignmentOnly[4];
			int16_t ___m_ShortValue_5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_UShortValue_6_OffsetPadding[4];
			// System.UInt16 UnityEngine.InputSystem.Utilities.PrimitiveValue::m_UShortValue
			uint16_t ___m_UShortValue_6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_UShortValue_6_OffsetPadding_forAlignmentOnly[4];
			uint16_t ___m_UShortValue_6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_IntValue_7_OffsetPadding[4];
			// System.Int32 UnityEngine.InputSystem.Utilities.PrimitiveValue::m_IntValue
			int32_t ___m_IntValue_7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_IntValue_7_OffsetPadding_forAlignmentOnly[4];
			int32_t ___m_IntValue_7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_UIntValue_8_OffsetPadding[4];
			// System.UInt32 UnityEngine.InputSystem.Utilities.PrimitiveValue::m_UIntValue
			uint32_t ___m_UIntValue_8;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_UIntValue_8_OffsetPadding_forAlignmentOnly[4];
			uint32_t ___m_UIntValue_8_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_LongValue_9_OffsetPadding[4];
			// System.Int64 UnityEngine.InputSystem.Utilities.PrimitiveValue::m_LongValue
			int64_t ___m_LongValue_9;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_LongValue_9_OffsetPadding_forAlignmentOnly[4];
			int64_t ___m_LongValue_9_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_ULongValue_10_OffsetPadding[4];
			// System.UInt64 UnityEngine.InputSystem.Utilities.PrimitiveValue::m_ULongValue
			uint64_t ___m_ULongValue_10;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_ULongValue_10_OffsetPadding_forAlignmentOnly[4];
			uint64_t ___m_ULongValue_10_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_FloatValue_11_OffsetPadding[4];
			// System.Single UnityEngine.InputSystem.Utilities.PrimitiveValue::m_FloatValue
			float ___m_FloatValue_11;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_FloatValue_11_OffsetPadding_forAlignmentOnly[4];
			float ___m_FloatValue_11_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_DoubleValue_12_OffsetPadding[4];
			// System.Double UnityEngine.InputSystem.Utilities.PrimitiveValue::m_DoubleValue
			double ___m_DoubleValue_12;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_DoubleValue_12_OffsetPadding_forAlignmentOnly[4];
			double ___m_DoubleValue_12_forAlignmentOnly;
		};
	};
};
// Native definition for P/Invoke marshalling of UnityEngine.InputSystem.Utilities.PrimitiveValue
struct PrimitiveValue_t1CC37566F40746757D5E3F87474A05909D85C2D4_marshaled_pinvoke
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			int32_t ___m_Type_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int32_t ___m_Type_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_BoolValue_1_OffsetPadding[4];
			int32_t ___m_BoolValue_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_BoolValue_1_OffsetPadding_forAlignmentOnly[4];
			int32_t ___m_BoolValue_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_CharValue_2_OffsetPadding[4];
			uint8_t ___m_CharValue_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_CharValue_2_OffsetPadding_forAlignmentOnly[4];
			uint8_t ___m_CharValue_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_ByteValue_3_OffsetPadding[4];
			uint8_t ___m_ByteValue_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_ByteValue_3_OffsetPadding_forAlignmentOnly[4];
			uint8_t ___m_ByteValue_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_SByteValue_4_OffsetPadding[4];
			int8_t ___m_SByteValue_4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_SByteValue_4_OffsetPadding_forAlignmentOnly[4];
			int8_t ___m_SByteValue_4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_ShortValue_5_OffsetPadding[4];
			int16_t ___m_ShortValue_5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_ShortValue_5_OffsetPadding_forAlignmentOnly[4];
			int16_t ___m_ShortValue_5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_UShortValue_6_OffsetPadding[4];
			uint16_t ___m_UShortValue_6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_UShortValue_6_OffsetPadding_forAlignmentOnly[4];
			uint16_t ___m_UShortValue_6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_IntValue_7_OffsetPadding[4];
			int32_t ___m_IntValue_7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_IntValue_7_OffsetPadding_forAlignmentOnly[4];
			int32_t ___m_IntValue_7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_UIntValue_8_OffsetPadding[4];
			uint32_t ___m_UIntValue_8;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_UIntValue_8_OffsetPadding_forAlignmentOnly[4];
			uint32_t ___m_UIntValue_8_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_LongValue_9_OffsetPadding[4];
			int64_t ___m_LongValue_9;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_LongValue_9_OffsetPadding_forAlignmentOnly[4];
			int64_t ___m_LongValue_9_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_ULongValue_10_OffsetPadding[4];
			uint64_t ___m_ULongValue_10;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_ULongValue_10_OffsetPadding_forAlignmentOnly[4];
			uint64_t ___m_ULongValue_10_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_FloatValue_11_OffsetPadding[4];
			float ___m_FloatValue_11;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_FloatValue_11_OffsetPadding_forAlignmentOnly[4];
			float ___m_FloatValue_11_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_DoubleValue_12_OffsetPadding[4];
			double ___m_DoubleValue_12;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_DoubleValue_12_OffsetPadding_forAlignmentOnly[4];
			double ___m_DoubleValue_12_forAlignmentOnly;
		};
	};
};
// Native definition for COM marshalling of UnityEngine.InputSystem.Utilities.PrimitiveValue
struct PrimitiveValue_t1CC37566F40746757D5E3F87474A05909D85C2D4_marshaled_com
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			int32_t ___m_Type_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int32_t ___m_Type_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_BoolValue_1_OffsetPadding[4];
			int32_t ___m_BoolValue_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_BoolValue_1_OffsetPadding_forAlignmentOnly[4];
			int32_t ___m_BoolValue_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_CharValue_2_OffsetPadding[4];
			uint8_t ___m_CharValue_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_CharValue_2_OffsetPadding_forAlignmentOnly[4];
			uint8_t ___m_CharValue_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_ByteValue_3_OffsetPadding[4];
			uint8_t ___m_ByteValue_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_ByteValue_3_OffsetPadding_forAlignmentOnly[4];
			uint8_t ___m_ByteValue_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_SByteValue_4_OffsetPadding[4];
			int8_t ___m_SByteValue_4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_SByteValue_4_OffsetPadding_forAlignmentOnly[4];
			int8_t ___m_SByteValue_4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_ShortValue_5_OffsetPadding[4];
			int16_t ___m_ShortValue_5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_ShortValue_5_OffsetPadding_forAlignmentOnly[4];
			int16_t ___m_ShortValue_5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_UShortValue_6_OffsetPadding[4];
			uint16_t ___m_UShortValue_6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_UShortValue_6_OffsetPadding_forAlignmentOnly[4];
			uint16_t ___m_UShortValue_6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_IntValue_7_OffsetPadding[4];
			int32_t ___m_IntValue_7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_IntValue_7_OffsetPadding_forAlignmentOnly[4];
			int32_t ___m_IntValue_7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_UIntValue_8_OffsetPadding[4];
			uint32_t ___m_UIntValue_8;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_UIntValue_8_OffsetPadding_forAlignmentOnly[4];
			uint32_t ___m_UIntValue_8_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_LongValue_9_OffsetPadding[4];
			int64_t ___m_LongValue_9;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_LongValue_9_OffsetPadding_forAlignmentOnly[4];
			int64_t ___m_LongValue_9_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_ULongValue_10_OffsetPadding[4];
			uint64_t ___m_ULongValue_10;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_ULongValue_10_OffsetPadding_forAlignmentOnly[4];
			uint64_t ___m_ULongValue_10_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_FloatValue_11_OffsetPadding[4];
			float ___m_FloatValue_11;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_FloatValue_11_OffsetPadding_forAlignmentOnly[4];
			float ___m_FloatValue_11_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___m_DoubleValue_12_OffsetPadding[4];
			double ___m_DoubleValue_12;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___m_DoubleValue_12_OffsetPadding_forAlignmentOnly[4];
			double ___m_DoubleValue_12_forAlignmentOnly;
		};
	};
};

// UnityEngine.ScriptableObject
struct ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};
// Native definition for P/Invoke marshalling of UnityEngine.ScriptableObject
struct ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A_marshaled_pinvoke : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_pinvoke
{
};
// Native definition for COM marshalling of UnityEngine.ScriptableObject
struct ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A_marshaled_com : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_com
{
};

// UnityEngine.Sprite
struct Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// System.SystemException
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};

// UnityEngine.Texture
struct Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// System.Type
struct Type_t  : public MemberInfo_t
{
	// System.RuntimeTypeHandle System.Type::_impl
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl_8;
};

// UnityEngine.InputSystem.Composites.Vector2Composite
struct Vector2Composite_tCAE11D025FE085E66E963DCCD6559D042A713908  : public InputBindingComposite_1_tB7B7EA7F16E4FA573E09983CFE2AE8C7D4616588
{
	// System.Int32 UnityEngine.InputSystem.Composites.Vector2Composite::up
	int32_t ___up_1;
	// System.Int32 UnityEngine.InputSystem.Composites.Vector2Composite::down
	int32_t ___down_2;
	// System.Int32 UnityEngine.InputSystem.Composites.Vector2Composite::left
	int32_t ___left_3;
	// System.Int32 UnityEngine.InputSystem.Composites.Vector2Composite::right
	int32_t ___right_4;
	// System.Boolean UnityEngine.InputSystem.Composites.Vector2Composite::normalize
	bool ___normalize_5;
	// UnityEngine.InputSystem.Composites.Vector2Composite/Mode UnityEngine.InputSystem.Composites.Vector2Composite::mode
	int32_t ___mode_6;
};

// UnityEngine.InputSystem.Composites.Vector3Composite
struct Vector3Composite_t014892920D73110CD43E6CC997E0FAA5860A62E0  : public InputBindingComposite_1_t34CD8E199158A65EE0E5DBCE8CC705AF3C4B3306
{
	// System.Int32 UnityEngine.InputSystem.Composites.Vector3Composite::up
	int32_t ___up_1;
	// System.Int32 UnityEngine.InputSystem.Composites.Vector3Composite::down
	int32_t ___down_2;
	// System.Int32 UnityEngine.InputSystem.Composites.Vector3Composite::left
	int32_t ___left_3;
	// System.Int32 UnityEngine.InputSystem.Composites.Vector3Composite::right
	int32_t ___right_4;
	// System.Int32 UnityEngine.InputSystem.Composites.Vector3Composite::forward
	int32_t ___forward_5;
	// System.Int32 UnityEngine.InputSystem.Composites.Vector3Composite::backward
	int32_t ___backward_6;
	// UnityEngine.InputSystem.Composites.Vector3Composite/Mode UnityEngine.InputSystem.Composites.Vector3Composite::mode
	int32_t ___mode_7;
};

// System.Func`2<System.Char,System.Boolean>
struct Func_2_tF409A653B8F770E0A30CD80D21764FB1DDB2A28F  : public MulticastDelegate_t
{
};

// System.Func`2<UnityEngine.InputSystem.Utilities.InternedString,System.String>
struct Func_2_tE0082B3C229A425A69ECDABB19259709EC9F540F  : public MulticastDelegate_t
{
};

// System.Func`2<System.Object,System.Object>
struct Func_2_tACBF5A1656250800CE861707354491F0611F6624  : public MulticastDelegate_t
{
};

// System.Func`2<System.String,System.String>
struct Func_2_t85D1F7C2022B349817C22FC72C474CD33FFABE93  : public MulticastDelegate_t
{
};

// System.ArgumentException
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
	// System.String System.ArgumentException::_paramName
	String_t* ____paramName_18;
};

// UnityEngine.InputSystem.InputControl
struct InputControl_t74F06B623518F992BF8E38656A5E0857169E3E2E  : public RuntimeObject
{
	// UnityEngine.InputSystem.LowLevel.InputStateBlock UnityEngine.InputSystem.InputControl::m_StateBlock
	InputStateBlock_t0E05211ACF29A99C0FE7FC9EA7042196BFF1F3B5 ___m_StateBlock_0;
	// UnityEngine.InputSystem.Utilities.InternedString UnityEngine.InputSystem.InputControl::m_Name
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___m_Name_1;
	// System.String UnityEngine.InputSystem.InputControl::m_Path
	String_t* ___m_Path_2;
	// System.String UnityEngine.InputSystem.InputControl::m_DisplayName
	String_t* ___m_DisplayName_3;
	// System.String UnityEngine.InputSystem.InputControl::m_DisplayNameFromLayout
	String_t* ___m_DisplayNameFromLayout_4;
	// System.String UnityEngine.InputSystem.InputControl::m_ShortDisplayName
	String_t* ___m_ShortDisplayName_5;
	// System.String UnityEngine.InputSystem.InputControl::m_ShortDisplayNameFromLayout
	String_t* ___m_ShortDisplayNameFromLayout_6;
	// UnityEngine.InputSystem.Utilities.InternedString UnityEngine.InputSystem.InputControl::m_Layout
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___m_Layout_7;
	// UnityEngine.InputSystem.Utilities.InternedString UnityEngine.InputSystem.InputControl::m_Variants
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___m_Variants_8;
	// UnityEngine.InputSystem.InputDevice UnityEngine.InputSystem.InputControl::m_Device
	InputDevice_t8BCF67533E872A75779C24C93D1D7085B72D364B* ___m_Device_9;
	// UnityEngine.InputSystem.InputControl UnityEngine.InputSystem.InputControl::m_Parent
	InputControl_t74F06B623518F992BF8E38656A5E0857169E3E2E* ___m_Parent_10;
	// System.Int32 UnityEngine.InputSystem.InputControl::m_UsageCount
	int32_t ___m_UsageCount_11;
	// System.Int32 UnityEngine.InputSystem.InputControl::m_UsageStartIndex
	int32_t ___m_UsageStartIndex_12;
	// System.Int32 UnityEngine.InputSystem.InputControl::m_AliasCount
	int32_t ___m_AliasCount_13;
	// System.Int32 UnityEngine.InputSystem.InputControl::m_AliasStartIndex
	int32_t ___m_AliasStartIndex_14;
	// System.Int32 UnityEngine.InputSystem.InputControl::m_ChildCount
	int32_t ___m_ChildCount_15;
	// System.Int32 UnityEngine.InputSystem.InputControl::m_ChildStartIndex
	int32_t ___m_ChildStartIndex_16;
	// UnityEngine.InputSystem.InputControl/ControlFlags UnityEngine.InputSystem.InputControl::m_ControlFlags
	int32_t ___m_ControlFlags_17;
	// System.Boolean UnityEngine.InputSystem.InputControl::m_CachedValueIsStale
	bool ___m_CachedValueIsStale_18;
	// System.Boolean UnityEngine.InputSystem.InputControl::m_UnprocessedCachedValueIsStale
	bool ___m_UnprocessedCachedValueIsStale_19;
	// UnityEngine.InputSystem.Utilities.PrimitiveValue UnityEngine.InputSystem.InputControl::m_DefaultState
	PrimitiveValue_t1CC37566F40746757D5E3F87474A05909D85C2D4 ___m_DefaultState_20;
	// UnityEngine.InputSystem.Utilities.PrimitiveValue UnityEngine.InputSystem.InputControl::m_MinValue
	PrimitiveValue_t1CC37566F40746757D5E3F87474A05909D85C2D4 ___m_MinValue_21;
	// UnityEngine.InputSystem.Utilities.PrimitiveValue UnityEngine.InputSystem.InputControl::m_MaxValue
	PrimitiveValue_t1CC37566F40746757D5E3F87474A05909D85C2D4 ___m_MaxValue_22;
	// UnityEngine.InputSystem.Utilities.FourCC UnityEngine.InputSystem.InputControl::m_OptimizedControlDataType
	FourCC_tA6CAA4015BC25A7F1053B6C512202D57A9C994ED ___m_OptimizedControlDataType_23;
};

// UnityEngine.InputSystem.InputSettings
struct InputSettings_tBA8835B505722A59702A08BCBA46ECF0B0274EEF  : public ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A
{
	// System.String[] UnityEngine.InputSystem.InputSettings::m_SupportedDevices
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___m_SupportedDevices_4;
	// UnityEngine.InputSystem.InputSettings/UpdateMode UnityEngine.InputSystem.InputSettings::m_UpdateMode
	int32_t ___m_UpdateMode_5;
	// System.Int32 UnityEngine.InputSystem.InputSettings::m_MaxEventBytesPerUpdate
	int32_t ___m_MaxEventBytesPerUpdate_6;
	// System.Int32 UnityEngine.InputSystem.InputSettings::m_MaxQueuedEventsPerUpdate
	int32_t ___m_MaxQueuedEventsPerUpdate_7;
	// System.Boolean UnityEngine.InputSystem.InputSettings::m_CompensateForScreenOrientation
	bool ___m_CompensateForScreenOrientation_8;
	// UnityEngine.InputSystem.InputSettings/BackgroundBehavior UnityEngine.InputSystem.InputSettings::m_BackgroundBehavior
	int32_t ___m_BackgroundBehavior_9;
	// UnityEngine.InputSystem.InputSettings/EditorInputBehaviorInPlayMode UnityEngine.InputSystem.InputSettings::m_EditorInputBehaviorInPlayMode
	int32_t ___m_EditorInputBehaviorInPlayMode_10;
	// System.Single UnityEngine.InputSystem.InputSettings::m_DefaultDeadzoneMin
	float ___m_DefaultDeadzoneMin_11;
	// System.Single UnityEngine.InputSystem.InputSettings::m_DefaultDeadzoneMax
	float ___m_DefaultDeadzoneMax_12;
	// System.Single UnityEngine.InputSystem.InputSettings::m_DefaultButtonPressPoint
	float ___m_DefaultButtonPressPoint_13;
	// System.Single UnityEngine.InputSystem.InputSettings::m_ButtonReleaseThreshold
	float ___m_ButtonReleaseThreshold_14;
	// System.Single UnityEngine.InputSystem.InputSettings::m_DefaultTapTime
	float ___m_DefaultTapTime_15;
	// System.Single UnityEngine.InputSystem.InputSettings::m_DefaultSlowTapTime
	float ___m_DefaultSlowTapTime_16;
	// System.Single UnityEngine.InputSystem.InputSettings::m_DefaultHoldTime
	float ___m_DefaultHoldTime_17;
	// System.Single UnityEngine.InputSystem.InputSettings::m_TapRadius
	float ___m_TapRadius_18;
	// System.Single UnityEngine.InputSystem.InputSettings::m_MultiTapDelayTime
	float ___m_MultiTapDelayTime_19;
	// System.Boolean UnityEngine.InputSystem.InputSettings::m_DisableRedundantEventsMerging
	bool ___m_DisableRedundantEventsMerging_20;
	// System.Boolean UnityEngine.InputSystem.InputSettings::m_ShortcutKeysConsumeInputs
	bool ___m_ShortcutKeysConsumeInputs_21;
	// System.Collections.Generic.HashSet`1<System.String> UnityEngine.InputSystem.InputSettings::m_FeatureFlags
	HashSet_1_tEFC6605F7DE53F71946C33FD371E53C3100F2178* ___m_FeatureFlags_22;
};

// System.InvalidOperationException
struct InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};

// System.NotSupportedException
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};

// UnityEngine.Texture2D
struct Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4  : public Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700
{
};

// System.ArgumentNullException
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129  : public ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263
{
};

// System.ArgumentOutOfRangeException
struct ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F  : public ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263
{
	// System.Object System.ArgumentOutOfRangeException::_actualValue
	RuntimeObject* ____actualValue_19;
};

// System.Collections.Generic.Dictionary`2<UnityEngine.InputSystem.Utilities.InternedString,System.Type>

// System.Collections.Generic.Dictionary`2<UnityEngine.InputSystem.Utilities.InternedString,System.Type>

// System.Collections.Generic.Dictionary`2/KeyCollection<UnityEngine.InputSystem.Utilities.InternedString,System.Type>

// System.Collections.Generic.Dictionary`2/KeyCollection<UnityEngine.InputSystem.Utilities.InternedString,System.Type>

// <PrivateImplementationDetails>
struct U3CPrivateImplementationDetailsU3E_tF62B85DD2C59D87BA6C8DA02965E1F3203A64E53_StaticFields
{
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=1575 <PrivateImplementationDetails>::20D6FD557BDCEEB113CF0C3EFEF501EB9D7AC4BA787A6A8C0EE057D8A217C869
	__StaticArrayInitTypeSizeU3D1575_tA8B5FF47C1B66730DBCAE65E998D5358992BC062 ___20D6FD557BDCEEB113CF0C3EFEF501EB9D7AC4BA787A6A8C0EE057D8A217C869_0;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=4011 <PrivateImplementationDetails>::63B74E5F0660F3254FE5AC58EE3CD9AC8FF8948DD7A5C9B54D0F8E0C67B3260F
	__StaticArrayInitTypeSizeU3D4011_tC6D32A64151F5DC52182F93CCD84032758712B89 ___63B74E5F0660F3254FE5AC58EE3CD9AC8FF8948DD7A5C9B54D0F8E0C67B3260F_1;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=234 <PrivateImplementationDetails>::754FF720715FE60E11AD0300104CDEEB8E30183CF25B417CB06EEF78356058EB
	__StaticArrayInitTypeSizeU3D234_t6F71BB8FF9822A3A3833BAB22E81F6B6955A781F ___754FF720715FE60E11AD0300104CDEEB8E30183CF25B417CB06EEF78356058EB_2;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=976 <PrivateImplementationDetails>::874A158EE5E9824634584F1FFF431FA5FC62C2D71CA9FCDCAA012D8A6A926392
	__StaticArrayInitTypeSizeU3D976_t61AF54C311BB0D3BB3FA5795EB3A69AFB6A26BA0 ___874A158EE5E9824634584F1FFF431FA5FC62C2D71CA9FCDCAA012D8A6A926392_3;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=460 <PrivateImplementationDetails>::A9936AC77D07F78E7B0473F80D59F6E15FD898CEF491CA47D4EB1BA2AA6A4E66
	__StaticArrayInitTypeSizeU3D460_t4ABB4E2DEDD6BE50A063561639D025CC2BDD5394 ___A9936AC77D07F78E7B0473F80D59F6E15FD898CEF491CA47D4EB1BA2AA6A4E66_4;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=371 <PrivateImplementationDetails>::BD3331923AE2D87F6296377CB80C86CE12BF445ED38D4485D28FACFEC06BFF5B
	__StaticArrayInitTypeSizeU3D371_tE9F5A574450793E6E499EB69CDD3047D5F5F00F9 ___BD3331923AE2D87F6296377CB80C86CE12BF445ED38D4485D28FACFEC06BFF5B_5;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=84 <PrivateImplementationDetails>::D9D05356900CBD90C107CDBD184BC94526EC3F9228772F900FC7C60E3FE82B5A
	__StaticArrayInitTypeSizeU3D84_t625EC17B34CB913B5E4B2EA6DB080F5BAF99EAEC ___D9D05356900CBD90C107CDBD184BC94526EC3F9228772F900FC7C60E3FE82B5A_6;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=1038 <PrivateImplementationDetails>::DECF56A62725B03F2A8BBB3B372DB9FB38E9C95146DAF31983F2C2EDE07A762B
	__StaticArrayInitTypeSizeU3D1038_tC28C31F75224CEC520DB0A52F7C747BDF0E8A242 ___DECF56A62725B03F2A8BBB3B372DB9FB38E9C95146DAF31983F2C2EDE07A762B_7;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=24 <PrivateImplementationDetails>::EEAB0A49E323B940CB01CCD3E80D47F1566617F04466CD5D6190ACDBC495CB2A
	__StaticArrayInitTypeSizeU3D24_t226C5F521B67F6FD3E9C29695114434A267A6141 ___EEAB0A49E323B940CB01CCD3E80D47F1566617F04466CD5D6190ACDBC495CB2A_8;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=104 <PrivateImplementationDetails>::FFCB0A1E90587D61767DBCE765CBEC8743DC4A67B865900B464ED065E4625BD5
	__StaticArrayInitTypeSizeU3D104_tA1677EB9042DF28F651C756F41B1B978A10472EA ___FFCB0A1E90587D61767DBCE765CBEC8743DC4A67B865900B464ED065E4625BD5_9;
};

// <PrivateImplementationDetails>

// UnityEngine.InputSystem.InputBindingComposite
struct InputBindingComposite_tA9230435A30FB5B2D4967D6FAE7EFABBBF26C0C0_StaticFields
{
	// UnityEngine.InputSystem.Utilities.TypeTable UnityEngine.InputSystem.InputBindingComposite::s_Composites
	TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E ___s_Composites_0;
};

// UnityEngine.InputSystem.InputBindingComposite

// System.Reflection.MemberInfo

// System.Reflection.MemberInfo

// UnityEngine.InputSystem.Utilities.ReadOnlyArrayExtensions

// UnityEngine.InputSystem.Utilities.ReadOnlyArrayExtensions

// UnityEngine.InputSystem.Utilities.SpriteUtilities

// UnityEngine.InputSystem.Utilities.SpriteUtilities

// System.String
struct String_t_StaticFields
{
	// System.String System.String::Empty
	String_t* ___Empty_6;
};

// System.String

// System.Text.StringBuilder

// System.Text.StringBuilder

// UnityEngine.InputSystem.Utilities.StringHelpers

// UnityEngine.InputSystem.Utilities.StringHelpers

// UnityEngine.InputSystem.Utilities.TypeHelpers

// UnityEngine.InputSystem.Utilities.TypeHelpers

// UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9

// UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9

// UnityEngine.InputSystem.Utilities.TypeTable/<>c
struct U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA_StaticFields
{
	// UnityEngine.InputSystem.Utilities.TypeTable/<>c UnityEngine.InputSystem.Utilities.TypeTable/<>c::<>9
	U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA* ___U3CU3E9_0;
	// System.Func`2<UnityEngine.InputSystem.Utilities.InternedString,System.String> UnityEngine.InputSystem.Utilities.TypeTable/<>c::<>9__2_0
	Func_2_tE0082B3C229A425A69ECDABB19259709EC9F540F* ___U3CU3E9__2_0_1;
};

// UnityEngine.InputSystem.Utilities.TypeTable/<>c

// UnityEngine.InputSystem.InputBindingComposite`1<System.Single>

// UnityEngine.InputSystem.InputBindingComposite`1<System.Single>

// UnityEngine.InputSystem.InputBindingComposite`1<UnityEngine.Vector2>

// UnityEngine.InputSystem.InputBindingComposite`1<UnityEngine.Vector2>

// UnityEngine.InputSystem.InputBindingComposite`1<UnityEngine.Vector3>

// UnityEngine.InputSystem.InputBindingComposite`1<UnityEngine.Vector3>

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	// System.String System.Boolean::TrueString
	String_t* ___TrueString_5;
	// System.String System.Boolean::FalseString
	String_t* ___FalseString_6;
};

// System.Boolean

// System.Byte

// System.Byte

// System.Char
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17_StaticFields
{
	// System.Byte[] System.Char::s_categoryForLatin1
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___s_categoryForLatin1_3;
};

// System.Char

// UnityEngine.Color32

// UnityEngine.Color32

// System.Double

// System.Double

// System.Reflection.FieldInfo

// System.Reflection.FieldInfo

// UnityEngine.InputSystem.InputBindingCompositeContext

// UnityEngine.InputSystem.InputBindingCompositeContext

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

// UnityEngine.InputSystem.Utilities.InternedString

// UnityEngine.InputSystem.Utilities.InternedString

// UnityEngine.Mathf
struct Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682_StaticFields
{
	// System.Single UnityEngine.Mathf::Epsilon
	float ___Epsilon_0;
};

// UnityEngine.Mathf

// UnityEngine.InputSystem.Composites.OneModifierComposite

// UnityEngine.InputSystem.Composites.OneModifierComposite

// System.Reflection.PropertyInfo

// System.Reflection.PropertyInfo

// UnityEngine.Rect

// UnityEngine.Rect

// System.Single

// System.Single

// UnityEngine.InputSystem.Utilities.Substring

// UnityEngine.InputSystem.Utilities.Substring

// UnityEngine.InputSystem.Composites.TwoModifiersComposite

// UnityEngine.InputSystem.Composites.TwoModifiersComposite

// UnityEngine.InputSystem.Utilities.TypeTable

// UnityEngine.InputSystem.Utilities.TypeTable

// System.UInt16

// System.UInt16

// System.UInt32

// System.UInt32

// System.UInt64

// System.UInt64

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

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=1038

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=1038

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=104

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=104

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=1575

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=1575

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=234

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=234

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=24

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=24

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=371

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=371

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=4011

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=4011

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=460

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=460

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=84

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=84

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=976

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=976

// UnityEngine.InputSystem.InputBindingCompositeContext/PartBinding

// UnityEngine.InputSystem.InputBindingCompositeContext/PartBinding

// System.Collections.Generic.KeyValuePair`2<UnityEngine.InputSystem.Utilities.InternedString,System.Object>

// System.Collections.Generic.KeyValuePair`2<UnityEngine.InputSystem.Utilities.InternedString,System.Object>

// System.Collections.Generic.KeyValuePair`2<UnityEngine.InputSystem.Utilities.InternedString,System.Type>

// System.Collections.Generic.KeyValuePair`2<UnityEngine.InputSystem.Utilities.InternedString,System.Type>

// UnityEngine.InputSystem.Composites.ButtonWithOneModifier

// UnityEngine.InputSystem.Composites.ButtonWithOneModifier

// UnityEngine.InputSystem.Composites.ButtonWithTwoModifiers

// UnityEngine.InputSystem.Composites.ButtonWithTwoModifiers

// UnityEngine.Experimental.Rendering.DefaultFormat

// UnityEngine.Experimental.Rendering.DefaultFormat

// System.Reflection.MethodInfo

// System.Reflection.MethodInfo

// System.RuntimeTypeHandle

// System.RuntimeTypeHandle

// UnityEngine.SpriteMeshType

// UnityEngine.SpriteMeshType

// System.StringComparison

// System.StringComparison

// UnityEngine.Experimental.Rendering.TextureCreationFlags

// UnityEngine.Experimental.Rendering.TextureCreationFlags

// System.TypeCode

// System.TypeCode

// UnityEngine.InputSystem.Composites.AxisComposite/WhichSideWins

// UnityEngine.InputSystem.Composites.AxisComposite/WhichSideWins

// UnityEngine.InputSystem.Utilities.StringHelpers/<Tokenize>d__8

// UnityEngine.InputSystem.Utilities.StringHelpers/<Tokenize>d__8

// UnityEngine.InputSystem.Composites.Vector2Composite/Mode

// UnityEngine.InputSystem.Composites.Vector2Composite/Mode

// UnityEngine.InputSystem.Composites.Vector3Composite/Mode

// UnityEngine.InputSystem.Composites.Vector3Composite/Mode

// System.Collections.Generic.Dictionary`2/Enumerator<UnityEngine.InputSystem.Utilities.InternedString,System.Object>

// System.Collections.Generic.Dictionary`2/Enumerator<UnityEngine.InputSystem.Utilities.InternedString,System.Object>

// System.Collections.Generic.Dictionary`2/Enumerator<UnityEngine.InputSystem.Utilities.InternedString,System.Type>

// System.Collections.Generic.Dictionary`2/Enumerator<UnityEngine.InputSystem.Utilities.InternedString,System.Type>

// Unity.Collections.NativeArray`1<UnityEngine.Color32>

// Unity.Collections.NativeArray`1<UnityEngine.Color32>

// UnityEngine.InputSystem.Composites.AxisComposite

// UnityEngine.InputSystem.Composites.AxisComposite

// UnityEngine.Sprite

// UnityEngine.Sprite

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

// UnityEngine.InputSystem.Composites.Vector2Composite

// UnityEngine.InputSystem.Composites.Vector2Composite

// UnityEngine.InputSystem.Composites.Vector3Composite

// UnityEngine.InputSystem.Composites.Vector3Composite

// System.Func`2<System.Char,System.Boolean>

// System.Func`2<System.Char,System.Boolean>

// System.Func`2<UnityEngine.InputSystem.Utilities.InternedString,System.String>

// System.Func`2<UnityEngine.InputSystem.Utilities.InternedString,System.String>

// System.Func`2<System.Object,System.Object>

// System.Func`2<System.Object,System.Object>

// System.Func`2<System.String,System.String>

// System.Func`2<System.String,System.String>

// System.ArgumentException

// System.ArgumentException

// UnityEngine.InputSystem.InputControl

// UnityEngine.InputSystem.InputControl

// UnityEngine.InputSystem.InputSettings
struct InputSettings_tBA8835B505722A59702A08BCBA46ECF0B0274EEF_StaticFields
{
	// System.Boolean UnityEngine.InputSystem.InputSettings::optimizedControlsFeatureEnabled
	bool ___optimizedControlsFeatureEnabled_23;
	// System.Boolean UnityEngine.InputSystem.InputSettings::readValueCachingFeatureEnabled
	bool ___readValueCachingFeatureEnabled_24;
	// System.Boolean UnityEngine.InputSystem.InputSettings::paranoidReadValueCachingChecksEnabled
	bool ___paranoidReadValueCachingChecksEnabled_25;
};

// UnityEngine.InputSystem.InputSettings

// System.InvalidOperationException

// System.InvalidOperationException

// System.NotSupportedException

// System.NotSupportedException

// UnityEngine.Texture2D

// UnityEngine.Texture2D

// System.ArgumentNullException

// System.ArgumentNullException

// System.ArgumentOutOfRangeException

// System.ArgumentOutOfRangeException
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// System.Type[]
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB  : public RuntimeArray
{
	ALIGN_FIELD (8) Type_t* m_Items[1];

	inline Type_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Type_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Type_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Type_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Type_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Type_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};


// Unity.Collections.NativeArray`1<T> UnityEngine.Texture2D::GetRawTextureData<UnityEngine.Color32>()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_t0783F5E3C7AF6C600A6A20DA7A32D82CA836528D Texture2D_GetRawTextureData_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m3F258FE3486B29D798DCFECF41E9845382EF5CC2_gshared (Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* __this, const RuntimeMethod* method) ;
// System.Void* Unity.Collections.LowLevel.Unsafe.NativeArrayUnsafeUtility::GetUnsafePtr<UnityEngine.Color32>(Unity.Collections.NativeArray`1<T>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void* NativeArrayUnsafeUtility_GetUnsafePtr_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m20D988AA4B5A020595A6FF21F9B26D67BF73B76E_gshared (NativeArray_1_t0783F5E3C7AF6C600A6A20DA7A32D82CA836528D ___0_nativeArray, const RuntimeMethod* method) ;
// System.Int32 Unity.Collections.LowLevel.Unsafe.UnsafeUtility::SizeOf<UnityEngine.Color32>()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m506739DDFD44F4F6CE36D20C36BFA90D7F56E4AE_gshared_inline (const RuntimeMethod* method) ;
// TResult System.Func`2<System.Object,System.Object>::Invoke(T)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Func_2_Invoke_mDBA25DA5DA5B7E056FB9B026AF041F1385FB58A9_gshared_inline (Func_2_tACBF5A1656250800CE861707354491F0611F6624* __this, RuntimeObject* ___0_arg, const RuntimeMethod* method) ;
// TResult System.Func`2<System.Char,System.Boolean>::Invoke(T)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m4733F0A0FE136C9F8DCE4963455215585E8BE2CD_gshared_inline (Func_2_tF409A653B8F770E0A30CD80D21764FB1DDB2A28F* __this, Il2CppChar ___0_arg, const RuntimeMethod* method) ;
// System.Collections.Generic.Dictionary`2/KeyCollection<TKey,TValue> System.Collections.Generic.Dictionary`2<UnityEngine.InputSystem.Utilities.InternedString,System.Object>::get_Keys()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR KeyCollection_t443F242E6072F26AA8803C1BF50400B0692392C6* Dictionary_2_get_Keys_m6B4FEC85C78AA00269F440121A5297DB65B6D164_gshared (Dictionary_2_t25574638E247E1D55E6ED2A97A5C38F3EBA31BA9* __this, const RuntimeMethod* method) ;
// System.Void System.Func`2<UnityEngine.InputSystem.Utilities.InternedString,System.Object>::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Func_2__ctor_mEA865389B1F3B9B7F55A65C4B937BF1A2F7258AC_gshared (Func_2_t63BCD2DEBA7363CAD4DAAF9703EF65C11A4C7BBB* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
// System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable::Select<UnityEngine.InputSystem.Utilities.InternedString,System.Object>(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,TResult>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Enumerable_Select_TisInternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_TisRuntimeObject_m180F51FA24B8CA2B15DB5B031C1A50981AF30CD9_gshared (RuntimeObject* ___0_source, Func_2_t63BCD2DEBA7363CAD4DAAF9703EF65C11A4C7BBB* ___1_selector, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<UnityEngine.InputSystem.Utilities.InternedString,System.Object>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_mD34AE4C80C1F230BC1EA62AB9020FFA9BC0DE8E0_gshared (Dictionary_2_t25574638E247E1D55E6ED2A97A5C38F3EBA31BA9* __this, const RuntimeMethod* method) ;
// System.Collections.Generic.Dictionary`2/Enumerator<TKey,TValue> System.Collections.Generic.Dictionary`2<UnityEngine.InputSystem.Utilities.InternedString,System.Object>::GetEnumerator()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tA3FD4A2E68B869CA74DA02EF77286DF5BFB3FE31 Dictionary_2_GetEnumerator_m3BF9969257B323347AA34745C6DCD37D1F9BF174_gshared (Dictionary_2_t25574638E247E1D55E6ED2A97A5C38F3EBA31BA9* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2/Enumerator<UnityEngine.InputSystem.Utilities.InternedString,System.Object>::Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator_Dispose_mC351F7DAFCD1DF4CCFF3E49D092773C72D84C292_gshared (Enumerator_tA3FD4A2E68B869CA74DA02EF77286DF5BFB3FE31* __this, const RuntimeMethod* method) ;
// System.Collections.Generic.KeyValuePair`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator<UnityEngine.InputSystem.Utilities.InternedString,System.Object>::get_Current()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR KeyValuePair_2_tC24A74EF64A292F5C6BA77D0B04CD6620D2DE3AC Enumerator_get_Current_mB1068DBFCAA4C19D082D5717DF265CBA6D66D4BE_gshared_inline (Enumerator_tA3FD4A2E68B869CA74DA02EF77286DF5BFB3FE31* __this, const RuntimeMethod* method) ;
// TValue System.Collections.Generic.KeyValuePair`2<UnityEngine.InputSystem.Utilities.InternedString,System.Object>::get_Value()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* KeyValuePair_2_get_Value_m1425379DCDEDB955455E242B31CD2AE43552B441_gshared_inline (KeyValuePair_2_tC24A74EF64A292F5C6BA77D0B04CD6620D2DE3AC* __this, const RuntimeMethod* method) ;
// TKey System.Collections.Generic.KeyValuePair`2<UnityEngine.InputSystem.Utilities.InternedString,System.Object>::get_Key()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 KeyValuePair_2_get_Key_mC668DBB7580ADCE4B3D87DA1C6E91F6E56B9EE84_gshared_inline (KeyValuePair_2_tC24A74EF64A292F5C6BA77D0B04CD6620D2DE3AC* __this, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2/Enumerator<UnityEngine.InputSystem.Utilities.InternedString,System.Object>::MoveNext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_m4BE8613970A8112E3042718B64AC74A4EF3355BF_gshared (Enumerator_tA3FD4A2E68B869CA74DA02EF77286DF5BFB3FE31* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<UnityEngine.InputSystem.Utilities.InternedString,System.Object>::set_Item(TKey,TValue)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_m725DDAF4C8BD4FBCD106BFFB1B4B5B74D7696281_gshared (Dictionary_2_t25574638E247E1D55E6ED2A97A5C38F3EBA31BA9* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<UnityEngine.InputSystem.Utilities.InternedString,System.Object>::TryGetValue(TKey,TValue&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryGetValue_m5FF3432937DE0E166259F54A0CFC568A388F7439_gshared (Dictionary_2_t25574638E247E1D55E6ED2A97A5C38F3EBA31BA9* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_key, RuntimeObject** ___1_value, const RuntimeMethod* method) ;
// TValue UnityEngine.InputSystem.InputBindingCompositeContext::ReadValue<System.Single>(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648_gshared (InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* __this, int32_t ___0_partNumber, const RuntimeMethod* method) ;
// System.Void UnityEngine.InputSystem.InputBindingComposite`1<System.Single>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InputBindingComposite_1__ctor_m652D65F50D8E8B067F415C8EB34CBB411E3037C8_gshared (InputBindingComposite_1_t2D5E67CAF6C6931B703564ED5FF2CC1D32B9814E* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.InputSystem.InputBindingComposite`1<UnityEngine.Vector2>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InputBindingComposite_1__ctor_m7A3EC8A3F30D4FD3E13C1FDD38CFB5B41B461545_gshared (InputBindingComposite_1_tB7B7EA7F16E4FA573E09983CFE2AE8C7D4616588* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.InputSystem.InputBindingComposite`1<UnityEngine.Vector3>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InputBindingComposite_1__ctor_mCC1C23E6E7958682F8F851C7EF1C1C179E21D789_gshared (InputBindingComposite_1_t34CD8E199158A65EE0E5DBCE8CC705AF3C4B3306* __this, const RuntimeMethod* method) ;

// System.Void UnityEngine.Texture2D::.ctor(System.Int32,System.Int32,UnityEngine.Experimental.Rendering.DefaultFormat,UnityEngine.Experimental.Rendering.TextureCreationFlags)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Texture2D__ctor_mC16513DD7E46C5CF1D85F985D13D78F4F481DCD7 (Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* __this, int32_t ___0_width, int32_t ___1_height, int32_t ___2_format, int32_t ___3_flags, const RuntimeMethod* method) ;
// Unity.Collections.NativeArray`1<T> UnityEngine.Texture2D::GetRawTextureData<UnityEngine.Color32>()
inline NativeArray_1_t0783F5E3C7AF6C600A6A20DA7A32D82CA836528D Texture2D_GetRawTextureData_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m3F258FE3486B29D798DCFECF41E9845382EF5CC2 (Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* __this, const RuntimeMethod* method)
{
	return ((  NativeArray_1_t0783F5E3C7AF6C600A6A20DA7A32D82CA836528D (*) (Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4*, const RuntimeMethod*))Texture2D_GetRawTextureData_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m3F258FE3486B29D798DCFECF41E9845382EF5CC2_gshared)(__this, method);
}
// System.Void* Unity.Collections.LowLevel.Unsafe.NativeArrayUnsafeUtility::GetUnsafePtr<UnityEngine.Color32>(Unity.Collections.NativeArray`1<T>)
inline void* NativeArrayUnsafeUtility_GetUnsafePtr_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m20D988AA4B5A020595A6FF21F9B26D67BF73B76E (NativeArray_1_t0783F5E3C7AF6C600A6A20DA7A32D82CA836528D ___0_nativeArray, const RuntimeMethod* method)
{
	return ((  void* (*) (NativeArray_1_t0783F5E3C7AF6C600A6A20DA7A32D82CA836528D, const RuntimeMethod*))NativeArrayUnsafeUtility_GetUnsafePtr_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m20D988AA4B5A020595A6FF21F9B26D67BF73B76E_gshared)(___0_nativeArray, method);
}
// System.Int32 Unity.Collections.LowLevel.Unsafe.UnsafeUtility::SizeOf<UnityEngine.Color32>()
inline int32_t UnsafeUtility_SizeOf_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m506739DDFD44F4F6CE36D20C36BFA90D7F56E4AE_inline (const RuntimeMethod* method)
{
	return ((  int32_t (*) (const RuntimeMethod*))UnsafeUtility_SizeOf_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m506739DDFD44F4F6CE36D20C36BFA90D7F56E4AE_gshared_inline)(method);
}
// System.Void Unity.Collections.LowLevel.Unsafe.UnsafeUtility::MemSet(System.Void*,System.Byte,System.Int64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtility_MemSet_m4CD74CD43260EB2962A46F57E0D93DD5C332FC2B (void* ___0_destination, uint8_t ___1_value, int64_t ___2_size, const RuntimeMethod* method) ;
// System.Void UnityEngine.Texture2D::Apply()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Texture2D_Apply_mA014182C9EE0BBF6EEE3B286854F29E50EB972DC (Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.Rect::.ctor(System.Single,System.Single,System.Single,System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Rect__ctor_m18C3033D135097BEE424AAA68D91C706D2647F23 (Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* __this, float ___0_x, float ___1_y, float ___2_width, float ___3_height, const RuntimeMethod* method) ;
// System.Void UnityEngine.Vector2::.ctor(System.Single,System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Vector2__ctor_m9525B79969AFFE3254B303A40997A56DEEB6F548_inline (Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7* __this, float ___0_x, float ___1_y, const RuntimeMethod* method) ;
// UnityEngine.Sprite UnityEngine.Sprite::Create(UnityEngine.Texture2D,UnityEngine.Rect,UnityEngine.Vector2,System.Single,System.UInt32,UnityEngine.SpriteMeshType)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* Sprite_Create_m519615D3E7835F70DC5B4CB93A4A481E14265C69 (Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* ___0_texture, Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D ___1_rect, Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___2_pivot, float ___3_pixelsPerUnit, uint32_t ___4_extrude, int32_t ___5_meshType, const RuntimeMethod* method) ;
// System.Char System.String::get_Chars(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppChar String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3 (String_t* __this, int32_t ___0_index, const RuntimeMethod* method) ;
// System.Boolean System.String::Contains(System.Char)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_Contains_mC67F1B9E92187E2BB125A560160DA30A5BA703F2 (String_t* __this, Il2CppChar ___0_value, const RuntimeMethod* method) ;
// System.Int32 System.String::get_Length()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) ;
// System.Void System.Text.StringBuilder::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D (StringBuilder_t* __this, const RuntimeMethod* method) ;
// System.Int32 System.String::IndexOf(System.Char)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t String_IndexOf_mE21E78F35EF4A7768E385A72814C88D22B689966 (String_t* __this, Il2CppChar ___0_value, const RuntimeMethod* method) ;
// System.Text.StringBuilder System.Text.StringBuilder::Append(System.Char)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1 (StringBuilder_t* __this, Il2CppChar ___0_value, const RuntimeMethod* method) ;
// System.Int32 System.String::IndexOf(System.String,System.StringComparison)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t String_IndexOf_m490810CB7ADA9230AC0F8D78E213A8EFED129F55 (String_t* __this, String_t* ___0_value, int32_t ___1_comparisonType, const RuntimeMethod* method) ;
// System.Void System.ArgumentNullException::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* __this, String_t* ___0_paramName, const RuntimeMethod* method) ;
// System.Boolean System.String::op_Equality(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1 (String_t* ___0_a, String_t* ___1_b, const RuntimeMethod* method) ;
// System.String System.String::Concat(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m9E3155FB84015C823606188F53B47CB44C444991 (String_t* ___0_str0, String_t* ___1_str1, const RuntimeMethod* method) ;
// System.String System.String::Format(System.String,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8 (String_t* ___0_format, RuntimeObject* ___1_arg0, const RuntimeMethod* method) ;
// System.String System.String::Trim()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Trim_mCD6D8C6D4CFD15225D12DB7D3E0544CA80FB8DA5 (String_t* __this, const RuntimeMethod* method) ;
// System.Boolean System.String::EndsWith(System.String,System.StringComparison)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_EndsWith_m5E5D307CA6AEB7C08CE782B4693B19D07ADC9075 (String_t* __this, String_t* ___0_value, int32_t ___1_comparisonType, const RuntimeMethod* method) ;
// System.String System.String::Substring(System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Substring_mB1D94F47935D22E130FF2C01DBB6A4135FBB76CE (String_t* __this, int32_t ___0_startIndex, int32_t ___1_length, const RuntimeMethod* method) ;
// System.Boolean System.Int64::TryParse(System.String,System.Int64&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Int64_TryParse_m3FC0128C89CC2331239FC2A0A749BF33455F03D2 (String_t* ___0_s, int64_t* ___1_result, const RuntimeMethod* method) ;
// System.Int32 System.String::IndexOf(System.Char,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t String_IndexOf_m15B90A59047584420D227EE3A7EAC0C5EAF676F4 (String_t* __this, Il2CppChar ___0_value, int32_t ___1_startIndex, const RuntimeMethod* method) ;
// System.Void UnityEngine.InputSystem.Utilities.StringHelpers/<Tokenize>d__8::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CTokenizeU3Ed__8__ctor_mFCB5DCEF9B0F44B630C8C831ADC12246A0CA2785 (U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) ;
// System.Void UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CSplitU3Ed__9__ctor_m531A6132094F2E8117F46518BCD07DBECF2F8B60 (U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) ;
// System.Char System.Char::ToLowerInvariant(System.Char)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppChar Char_ToLowerInvariant_m983C1CD07015E41B97D71F466B4B686F1145E60D (Il2CppChar ___0_c, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.InputSystem.Utilities.StringHelpers::WriteStringToBuffer(System.String,System.IntPtr,System.Int32,System.UInt32&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool StringHelpers_WriteStringToBuffer_m0719C102DC096F1A565020ED8D1B71BC6B26B8DF (String_t* ___0_text, intptr_t ___1_buffer, int32_t ___2_bufferSizeInCharacters, uint32_t* ___3_offset, const RuntimeMethod* method) ;
// System.Boolean System.IntPtr::op_Equality(System.IntPtr,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool IntPtr_op_Equality_m7D9CDCDE9DC2A0C2C614633F4921E90187FAB271 (intptr_t ___0_value1, intptr_t ___1_value2, const RuntimeMethod* method) ;
// System.Boolean System.String::IsNullOrEmpty(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478 (String_t* ___0_value, const RuntimeMethod* method) ;
// System.Void System.ArgumentException::.ctor(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62 (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* __this, String_t* ___0_message, String_t* ___1_paramName, const RuntimeMethod* method) ;
// System.Void* System.IntPtr::op_Explicit(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void* IntPtr_op_Explicit_m2728CBA081E79B97DDCF1D4FAD77B309CA1E94BF (intptr_t ___0_value, const RuntimeMethod* method) ;
// System.String UnityEngine.InputSystem.Utilities.StringHelpers::ReadStringFromBuffer(System.IntPtr,System.Int32,System.UInt32&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* StringHelpers_ReadStringFromBuffer_m08BAA47EF90D3F3A74A8AA354871C18FA7D9B8D2 (intptr_t ___0_buffer, int32_t ___1_bufferSize, uint32_t* ___2_offset, const RuntimeMethod* method) ;
// System.Void System.IntPtr::.ctor(System.Void*)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void IntPtr__ctor_m4F9A9B80F01996B610D5AE4797F20B98ECD0A3D9_inline (intptr_t* __this, void* ___0_value, const RuntimeMethod* method) ;
// System.String System.Runtime.InteropServices.Marshal::PtrToStringUni(System.IntPtr,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Marshal_PtrToStringUni_mF3D662C7F7255D6DDA07416FA6520886F66D0070 (intptr_t ___0_ptr, int32_t ___1_len, const RuntimeMethod* method) ;
// System.Boolean System.Char::IsControl(System.Char)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Char_IsControl_m133C10360BE82B7580E4D3ECE3C881A6C82B3F7F (Il2CppChar ___0_c, const RuntimeMethod* method) ;
// System.Boolean System.Char::IsWhiteSpace(System.Char)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Char_IsWhiteSpace_m02AEC6EA19513CAFC6882CFCA54C45794D2B5924 (Il2CppChar ___0_c, const RuntimeMethod* method) ;
// System.Boolean System.String::Equals(System.String,System.String,System.StringComparison)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_Equals_mCC34895D0DB2AD440C9D8767032215BC86B5C48B (String_t* ___0_a, String_t* ___1_b, int32_t ___2_comparisonType, const RuntimeMethod* method) ;
// TResult System.Func`2<System.String,System.String>::Invoke(T)
inline String_t* Func_2_Invoke_mED071D4A847678204A843F11D77F10D168FE4D2D_inline (Func_2_t85D1F7C2022B349817C22FC72C474CD33FFABE93* __this, String_t* ___0_arg, const RuntimeMethod* method)
{
	return ((  String_t* (*) (Func_2_t85D1F7C2022B349817C22FC72C474CD33FFABE93*, String_t*, const RuntimeMethod*))Func_2_Invoke_mDBA25DA5DA5B7E056FB9B026AF041F1385FB58A9_gshared_inline)(__this, ___0_arg, method);
}
// System.Text.StringBuilder System.Text.StringBuilder::Append(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D (StringBuilder_t* __this, String_t* ___0_value, const RuntimeMethod* method) ;
// System.Void System.Object::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
// System.Int32 System.Environment::get_CurrentManagedThreadId()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Environment_get_CurrentManagedThreadId_m66483AADCCC13272EBDCD94D31D2E52603C24BDF (const RuntimeMethod* method) ;
// TResult System.Func`2<System.Char,System.Boolean>::Invoke(T)
inline bool Func_2_Invoke_m4733F0A0FE136C9F8DCE4963455215585E8BE2CD_inline (Func_2_tF409A653B8F770E0A30CD80D21764FB1DDB2A28F* __this, Il2CppChar ___0_arg, const RuntimeMethod* method)
{
	return ((  bool (*) (Func_2_tF409A653B8F770E0A30CD80D21764FB1DDB2A28F*, Il2CppChar, const RuntimeMethod*))Func_2_Invoke_m4733F0A0FE136C9F8DCE4963455215585E8BE2CD_gshared_inline)(__this, ___0_arg, method);
}
// System.Void System.NotSupportedException::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NotSupportedException__ctor_m1398D0CDE19B36AA3DE9392879738C1EA2439CDF (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* __this, const RuntimeMethod* method) ;
// System.Collections.Generic.IEnumerator`1<System.String> UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9::System.Collections.Generic.IEnumerable<System.String>.GetEnumerator()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CSplitU3Ed__9_System_Collections_Generic_IEnumerableU3CSystem_StringU3E_GetEnumerator_m60A98974B57E1F33794FE9CC8A472C3E52C09511 (U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.InputSystem.Utilities.Substring::.ctor(System.String,System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Substring__ctor_m26B51DCD265326C6BCEAD778F0FC45407BB5F745 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, String_t* ___0_str, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
// System.Collections.Generic.IEnumerator`1<UnityEngine.InputSystem.Utilities.Substring> UnityEngine.InputSystem.Utilities.StringHelpers/<Tokenize>d__8::System.Collections.Generic.IEnumerable<UnityEngine.InputSystem.Utilities.Substring>.GetEnumerator()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CTokenizeU3Ed__8_System_Collections_Generic_IEnumerableU3CUnityEngine_InputSystem_Utilities_SubstringU3E_GetEnumerator_m79F809FB39EEDCBAEBBCB6D0BFC16E86A858C9BE (U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.InputSystem.Utilities.Substring::get_isEmpty()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Substring_get_isEmpty_m595F6475C26E9FFE44A503FC412CCB059B0FBC47 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.InputSystem.Utilities.Substring::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Substring__ctor_m5EF457666A6E65F74FA240D42360D666FD477937 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, String_t* ___0_str, const RuntimeMethod* method) ;
// System.Void UnityEngine.InputSystem.Utilities.Substring::.ctor(System.String,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Substring__ctor_mD29CA4E0387A9343B5A0839A92A7AC13468621D9 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, String_t* ___0_str, int32_t ___1_index, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.InputSystem.Utilities.Substring::Equals(UnityEngine.InputSystem.Utilities.Substring)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Substring_Equals_m90DCA9419D3654340F7660D99B85C7F817B3E76F (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___0_other, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.InputSystem.Utilities.Substring::Equals(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Substring_Equals_mBACFC276E8FD4DB04E356A41595EA284FC431CC7 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, String_t* ___0_other, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.InputSystem.Utilities.Substring::Equals(System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Substring_Equals_m34CEE374E83C2E31E0C90566412EA4B17BEEFA46 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.InputSystem.Utilities.Substring::CompareTo(UnityEngine.InputSystem.Utilities.Substring)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Substring_CompareTo_m73D1F0A207D0D12553B2BD44961097FCAD4F2AA1 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___0_other, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.InputSystem.Utilities.Substring::get_length()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Substring_get_length_m55986408214CA7DBD05548C1E226DC2E4D6E78FC_inline (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.InputSystem.Utilities.InternedString::get_length()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t InternedString_get_length_m4C5C8B69056154F3B5CF7D696A9D72803FC3FAFD (InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735* __this, const RuntimeMethod* method) ;
// System.String UnityEngine.InputSystem.Utilities.InternedString::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* InternedString_ToString_mED327D67EF001C5EDFF284336F13C3E3F025993A (InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735* __this, const RuntimeMethod* method) ;
// System.Int32 System.String::Compare(System.String,System.Int32,System.String,System.Int32,System.Int32,System.StringComparison)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t String_Compare_m68FBA6075A0142439B0249D884863356D99090CF (String_t* ___0_strA, int32_t ___1_indexA, String_t* ___2_strB, int32_t ___3_indexB, int32_t ___4_length, int32_t ___5_comparisonType, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.InputSystem.Utilities.Substring::Equals(UnityEngine.InputSystem.Utilities.InternedString)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Substring_Equals_m1A54740A335BF499C1A804182A4485A04F769C10 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_other, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.InputSystem.Utilities.Substring::Compare(UnityEngine.InputSystem.Utilities.Substring,UnityEngine.InputSystem.Utilities.Substring,System.StringComparison)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Substring_Compare_mEB3378051C685973B36959D7EE7F7C661508D81A (Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___0_left, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___1_right, int32_t ___2_comparison, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.InputSystem.Utilities.Substring::StartsWith(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Substring_StartsWith_mCC5D1EC1C8F0CE526DE26CF1A8F21463716EB09E (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, String_t* ___0_str, const RuntimeMethod* method) ;
// System.String UnityEngine.InputSystem.Utilities.Substring::Substr(System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Substring_Substr_mCEF29557E9E2EB77B0FC67DD5894B763D5B08077 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, int32_t ___0_index, int32_t ___1_length, const RuntimeMethod* method) ;
// System.String UnityEngine.InputSystem.Utilities.Substring::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Substring_ToString_m321AF6BA186DB01349CE3C710F1EA773D38FEF6D (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.InputSystem.Utilities.Substring::GetHashCode()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Substring_GetHashCode_m68743D4DB46190219FCBA41BACC476D7083D5986 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.InputSystem.Utilities.Substring::get_index()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Substring_get_index_mEF04F0C2A5292FEC77A6DE1C13C81B719C9D3012_inline (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, const RuntimeMethod* method) ;
// System.Void System.ArgumentOutOfRangeException::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* __this, String_t* ___0_paramName, const RuntimeMethod* method) ;
// System.Char UnityEngine.InputSystem.Utilities.Substring::get_Item(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppChar Substring_get_Item_m278F3C7634F20487F36267C4BD49BC96DAE4CAC4 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, int32_t ___0_index, const RuntimeMethod* method) ;
// System.Boolean System.Reflection.FieldInfo::op_Inequality(System.Reflection.FieldInfo,System.Reflection.FieldInfo)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool FieldInfo_op_Inequality_m95789A98E646494987E66A9E4188DCA86185066B (FieldInfo_t* ___0_left, FieldInfo_t* ___1_right, const RuntimeMethod* method) ;
// System.Boolean System.Reflection.PropertyInfo::op_Inequality(System.Reflection.PropertyInfo,System.Reflection.PropertyInfo)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool PropertyInfo_op_Inequality_mE75A4F14CC678D8A670730FBD4338C718CACB51B (PropertyInfo_t* ___0_left, PropertyInfo_t* ___1_right, const RuntimeMethod* method) ;
// System.Boolean System.Reflection.MethodInfo::op_Inequality(System.Reflection.MethodInfo,System.Reflection.MethodInfo)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool MethodInfo_op_Inequality_mB73597A1FCC2F906DBCADDEC68A1B7D5B7E89FA8 (MethodInfo_t* ___0_left, MethodInfo_t* ___1_right, const RuntimeMethod* method) ;
// System.Boolean System.Type::get_IsPrimitive()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Type_get_IsPrimitive_m46ACAAB8F754D37713E3E45437705F4F58FAFA18 (Type_t* __this, const RuntimeMethod* method) ;
// System.Type System.Type::GetTypeFromHandle(System.RuntimeTypeHandle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57 (RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ___0_handle, const RuntimeMethod* method) ;
// System.Boolean System.Type::op_Equality(System.Type,System.Type)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC (Type_t* ___0_left, Type_t* ___1_right, const RuntimeMethod* method) ;
// System.Boolean System.Type::get_IsInterface()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Type_get_IsInterface_m484A7D9321E72758EABE7F36AE266EB0905957EC (Type_t* __this, const RuntimeMethod* method) ;
// System.Type UnityEngine.InputSystem.Utilities.TypeHelpers::GetGenericTypeArgumentFromHierarchy(System.Type,System.Type,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* TypeHelpers_GetGenericTypeArgumentFromHierarchy_m9CE3EA9B8DFBBBC2BD6BFB81B4D66FB6922C089C (Type_t* ___0_type, Type_t* ___1_genericTypeDefinition, int32_t ___2_argumentIndex, const RuntimeMethod* method) ;
// System.Boolean System.Type::op_Inequality(System.Type,System.Type)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Type_op_Inequality_m83209C7BB3C05DFBEA3B6199B0BEFE8037301172 (Type_t* ___0_left, Type_t* ___1_right, const RuntimeMethod* method) ;
// System.Collections.Generic.Dictionary`2/KeyCollection<TKey,TValue> System.Collections.Generic.Dictionary`2<UnityEngine.InputSystem.Utilities.InternedString,System.Type>::get_Keys()
inline KeyCollection_tF0B6D6FBE89245B5B34798233471D53A6BF802A3* Dictionary_2_get_Keys_mFDE9D7FC672A995E064B6F14DBC9EB0B0D15BFAF (Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D* __this, const RuntimeMethod* method)
{
	return ((  KeyCollection_tF0B6D6FBE89245B5B34798233471D53A6BF802A3* (*) (Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D*, const RuntimeMethod*))Dictionary_2_get_Keys_m6B4FEC85C78AA00269F440121A5297DB65B6D164_gshared)(__this, method);
}
// System.Void System.Func`2<UnityEngine.InputSystem.Utilities.InternedString,System.String>::.ctor(System.Object,System.IntPtr)
inline void Func_2__ctor_m6763116FA3257580D87BD903E24793FCD6D82548 (Func_2_tE0082B3C229A425A69ECDABB19259709EC9F540F* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Func_2_tE0082B3C229A425A69ECDABB19259709EC9F540F*, RuntimeObject*, intptr_t, const RuntimeMethod*))Func_2__ctor_mEA865389B1F3B9B7F55A65C4B937BF1A2F7258AC_gshared)(__this, ___0_object, ___1_method, method);
}
// System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable::Select<UnityEngine.InputSystem.Utilities.InternedString,System.String>(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,TResult>)
inline RuntimeObject* Enumerable_Select_TisInternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_TisString_t_m3FCCE6DBA6A159830BE8363BF5BA444BCBF4B186 (RuntimeObject* ___0_source, Func_2_tE0082B3C229A425A69ECDABB19259709EC9F540F* ___1_selector, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (RuntimeObject*, Func_2_tE0082B3C229A425A69ECDABB19259709EC9F540F*, const RuntimeMethod*))Enumerable_Select_TisInternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_TisRuntimeObject_m180F51FA24B8CA2B15DB5B031C1A50981AF30CD9_gshared)(___0_source, ___1_selector, method);
}
// System.Collections.Generic.IEnumerable`1<System.String> UnityEngine.InputSystem.Utilities.TypeTable::get_names()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* TypeTable_get_names_mDE4C37C80FF83DA878F42A69F48AEB9656052F0A (TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E* __this, const RuntimeMethod* method) ;
// System.Collections.Generic.IEnumerable`1<UnityEngine.InputSystem.Utilities.InternedString> UnityEngine.InputSystem.Utilities.TypeTable::get_internedNames()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* TypeTable_get_internedNames_m12DFD70B16C0F9F67C30BA95FC91286954E5F60B (TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<UnityEngine.InputSystem.Utilities.InternedString,System.Type>::.ctor()
inline void Dictionary_2__ctor_mD10EC6AB3D41E49C23882A85B368A08800DFC5EE (Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D*, const RuntimeMethod*))Dictionary_2__ctor_mD34AE4C80C1F230BC1EA62AB9020FFA9BC0DE8E0_gshared)(__this, method);
}
// System.Void UnityEngine.InputSystem.Utilities.TypeTable::Initialize()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TypeTable_Initialize_m5EE09E37850E04357BB26CC52183617C08A11D0C (TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E* __this, const RuntimeMethod* method) ;
// System.Collections.Generic.Dictionary`2/Enumerator<TKey,TValue> System.Collections.Generic.Dictionary`2<UnityEngine.InputSystem.Utilities.InternedString,System.Type>::GetEnumerator()
inline Enumerator_tC7FEC7C0C46B33E076C8049925C674971CBC97DE Dictionary_2_GetEnumerator_m09228E70F30816068825C9BB4B45519E7143CE7A (Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_tC7FEC7C0C46B33E076C8049925C674971CBC97DE (*) (Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D*, const RuntimeMethod*))Dictionary_2_GetEnumerator_m3BF9969257B323347AA34745C6DCD37D1F9BF174_gshared)(__this, method);
}
// System.Void System.Collections.Generic.Dictionary`2/Enumerator<UnityEngine.InputSystem.Utilities.InternedString,System.Type>::Dispose()
inline void Enumerator_Dispose_m767111BF89218E9F0CD407F44CD9FF1CC6079B87 (Enumerator_tC7FEC7C0C46B33E076C8049925C674971CBC97DE* __this, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_tC7FEC7C0C46B33E076C8049925C674971CBC97DE*, const RuntimeMethod*))Enumerator_Dispose_mC351F7DAFCD1DF4CCFF3E49D092773C72D84C292_gshared)(__this, method);
}
// System.Collections.Generic.KeyValuePair`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator<UnityEngine.InputSystem.Utilities.InternedString,System.Type>::get_Current()
inline KeyValuePair_2_t859F90B137C9291C0E478FBE85ABB18F30B91A27 Enumerator_get_Current_m8161C19F09FC9E5EFD3BCE87B8907B3F660FFF51_inline (Enumerator_tC7FEC7C0C46B33E076C8049925C674971CBC97DE* __this, const RuntimeMethod* method)
{
	return ((  KeyValuePair_2_t859F90B137C9291C0E478FBE85ABB18F30B91A27 (*) (Enumerator_tC7FEC7C0C46B33E076C8049925C674971CBC97DE*, const RuntimeMethod*))Enumerator_get_Current_mB1068DBFCAA4C19D082D5717DF265CBA6D66D4BE_gshared_inline)(__this, method);
}
// TValue System.Collections.Generic.KeyValuePair`2<UnityEngine.InputSystem.Utilities.InternedString,System.Type>::get_Value()
inline Type_t* KeyValuePair_2_get_Value_m9803DE61209750BB22E4E1A58A5DFB943EAFCB80_inline (KeyValuePair_2_t859F90B137C9291C0E478FBE85ABB18F30B91A27* __this, const RuntimeMethod* method)
{
	return ((  Type_t* (*) (KeyValuePair_2_t859F90B137C9291C0E478FBE85ABB18F30B91A27*, const RuntimeMethod*))KeyValuePair_2_get_Value_m1425379DCDEDB955455E242B31CD2AE43552B441_gshared_inline)(__this, method);
}
// TKey System.Collections.Generic.KeyValuePair`2<UnityEngine.InputSystem.Utilities.InternedString,System.Type>::get_Key()
inline InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 KeyValuePair_2_get_Key_mE8768535ABCD24F453DC1EC5127CBD303DEC29A5_inline (KeyValuePair_2_t859F90B137C9291C0E478FBE85ABB18F30B91A27* __this, const RuntimeMethod* method)
{
	return ((  InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 (*) (KeyValuePair_2_t859F90B137C9291C0E478FBE85ABB18F30B91A27*, const RuntimeMethod*))KeyValuePair_2_get_Key_mC668DBB7580ADCE4B3D87DA1C6E91F6E56B9EE84_gshared_inline)(__this, method);
}
// System.Boolean System.Collections.Generic.Dictionary`2/Enumerator<UnityEngine.InputSystem.Utilities.InternedString,System.Type>::MoveNext()
inline bool Enumerator_MoveNext_mEB31860F9718BC0DB2D231F91D9A78D9666B54EF (Enumerator_tC7FEC7C0C46B33E076C8049925C674971CBC97DE* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_tC7FEC7C0C46B33E076C8049925C674971CBC97DE*, const RuntimeMethod*))Enumerator_MoveNext_m4BE8613970A8112E3042718B64AC74A4EF3355BF_gshared)(__this, method);
}
// UnityEngine.InputSystem.Utilities.InternedString UnityEngine.InputSystem.Utilities.TypeTable::FindNameForType(System.Type)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 TypeTable_FindNameForType_m5974594EAAEB68C4488B8C9CFABF931B7666FB00 (TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E* __this, Type_t* ___0_type, const RuntimeMethod* method) ;
// System.Void UnityEngine.InputSystem.Utilities.InternedString::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InternedString__ctor_m2E9672D46D84C82F705DE799CE8B6123EB95E935 (InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735* __this, String_t* ___0_text, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<UnityEngine.InputSystem.Utilities.InternedString,System.Type>::set_Item(TKey,TValue)
inline void Dictionary_2_set_Item_mACF6DD3A83F9F41061E7C4DD48F58C07BFAA31C7 (Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_key, Type_t* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D*, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735, Type_t*, const RuntimeMethod*))Dictionary_2_set_Item_m725DDAF4C8BD4FBCD106BFFB1B4B5B74D7696281_gshared)(__this, ___0_key, ___1_value, method);
}
// System.Void UnityEngine.InputSystem.Utilities.TypeTable::AddTypeRegistration(System.String,System.Type)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TypeTable_AddTypeRegistration_mAC83549CC944F2EE8371A00B82B203B9B8DD5B7E (TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method) ;
// System.Void System.InvalidOperationException::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162 (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* __this, String_t* ___0_message, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<UnityEngine.InputSystem.Utilities.InternedString,System.Type>::TryGetValue(TKey,TValue&)
inline bool Dictionary_2_TryGetValue_m4AFE96490465DE101600F734AF44C7E4AE513860 (Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_key, Type_t** ___1_value, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D*, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735, Type_t**, const RuntimeMethod*))Dictionary_2_TryGetValue_m5FF3432937DE0E166259F54A0CFC568A388F7439_gshared)(__this, ___0_key, ___1_value, method);
}
// System.Type UnityEngine.InputSystem.Utilities.TypeTable::LookupTypeRegistration(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* TypeTable_LookupTypeRegistration_m89DCEA471CDF7CDB994D67D3726482805C0AE29A (TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E* __this, String_t* ___0_name, const RuntimeMethod* method) ;
// System.Void UnityEngine.InputSystem.Utilities.TypeTable/<>c::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__ctor_m272D75733C8074A4CB8134DEB9A4BD7442005F5A (U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA* __this, const RuntimeMethod* method) ;
// TValue UnityEngine.InputSystem.InputBindingCompositeContext::ReadValue<System.Single>(System.Int32)
inline float InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648 (InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* __this, int32_t ___0_partNumber, const RuntimeMethod* method)
{
	return ((  float (*) (InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390*, int32_t, const RuntimeMethod*))InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648_gshared)(__this, ___0_partNumber, method);
}
// System.Single UnityEngine.InputSystem.Composites.AxisComposite::get_midPoint()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float AxisComposite_get_midPoint_m95E5A7ADEDF11A5E0946073FE3EB3DBB56E9C14B (AxisComposite_t9E3B9C369A8F748691611245821471645D31D2AC* __this, const RuntimeMethod* method) ;
// System.Single UnityEngine.InputSystem.Processors.NormalizeProcessor::Normalize(System.Single,System.Single,System.Single,System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float NormalizeProcessor_Normalize_m6B8C94BD2D8640D46A0EFD1FF10B4E311C46DBEB (float ___0_value, float ___1_min, float ___2_max, float ___3_zero, const RuntimeMethod* method) ;
// System.Void UnityEngine.InputSystem.InputBindingComposite`1<System.Single>::.ctor()
inline void InputBindingComposite_1__ctor_m652D65F50D8E8B067F415C8EB34CBB411E3037C8 (InputBindingComposite_1_t2D5E67CAF6C6931B703564ED5FF2CC1D32B9814E* __this, const RuntimeMethod* method)
{
	((  void (*) (InputBindingComposite_1_t2D5E67CAF6C6931B703564ED5FF2CC1D32B9814E*, const RuntimeMethod*))InputBindingComposite_1__ctor_m652D65F50D8E8B067F415C8EB34CBB411E3037C8_gshared)(__this, method);
}
// System.Boolean UnityEngine.InputSystem.Composites.ButtonWithOneModifier::ModifierIsPressed(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ButtonWithOneModifier_ModifierIsPressed_mEAF7D55D5DFF9A23D2F467E889EDFF82355E8E80 (ButtonWithOneModifier_t407B77B4960C57B1DEC84F631F91B1E135343222* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.InputSystem.InputBindingCompositeContext::ReadValueAsButton(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool InputBindingCompositeContext_ReadValueAsButton_mD3F30463AD217008C8DC0F42BA59BDC8EB37D0DB (InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* __this, int32_t ___0_partNumber, const RuntimeMethod* method) ;
// System.Double UnityEngine.InputSystem.InputBindingCompositeContext::GetPressTime(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double InputBindingCompositeContext_GetPressTime_mA919F3E37F086C2BFEEB6EB17A75B1A6CFF2E58A (InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* __this, int32_t ___0_partNumber, const RuntimeMethod* method) ;
// UnityEngine.InputSystem.InputSettings UnityEngine.InputSystem.InputSystem::get_settings()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR InputSettings_tBA8835B505722A59702A08BCBA46ECF0B0274EEF* InputSystem_get_settings_m8E3E9C0907904CBDBAE96354142AB0A87C7A3B74 (const RuntimeMethod* method) ;
// System.Boolean UnityEngine.InputSystem.InputSettings::get_shortcutKeysConsumeInput()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool InputSettings_get_shortcutKeysConsumeInput_m916DC677CCE3E4F3AD3BA48C5723965007CBE670_inline (InputSettings_tBA8835B505722A59702A08BCBA46ECF0B0274EEF* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.InputSystem.Composites.ButtonWithTwoModifiers::ModifiersArePressed(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ButtonWithTwoModifiers_ModifiersArePressed_m0713025DE1116397F560856674D56D3D228C781E (ButtonWithTwoModifiers_tCA30378981527D0F306883EABED0657FA5FE7C59* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.InputSystem.Composites.OneModifierComposite::ModifierIsPressed(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool OneModifierComposite_ModifierIsPressed_m25EEA39878124B169F67C7A2752EBD7890F44C48 (OneModifierComposite_tC18745AC641308E913620A321BF1CCE00D60E55B* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) ;
// System.Single UnityEngine.InputSystem.InputBindingCompositeContext::EvaluateMagnitude(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float InputBindingCompositeContext_EvaluateMagnitude_m418436D265278E622B80FD3CB6E6366F5DDD2E1A (InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* __this, int32_t ___0_partNumber, const RuntimeMethod* method) ;
// System.Void UnityEngine.InputSystem.InputBindingCompositeContext::ReadValue(System.Int32,System.Void*,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InputBindingCompositeContext_ReadValue_mC797CA9EDA827FF511B0771EEF21F1B271CF16D8 (InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* __this, int32_t ___0_partNumber, void* ___1_buffer, int32_t ___2_bufferSize, const RuntimeMethod* method) ;
// System.Void Unity.Collections.LowLevel.Unsafe.UnsafeUtility::MemClear(System.Void*,System.Int64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtility_MemClear_m6C4377117084A11A667A567BC2F5E606A632A7C1 (void* ___0_destination, int64_t ___1_size, const RuntimeMethod* method) ;
// System.Void UnityEngine.InputSystem.Composites.OneModifierComposite::DetermineValueTypeAndSize(UnityEngine.InputSystem.InputBindingCompositeContext&,System.Int32,System.Type&,System.Int32&,System.Boolean&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OneModifierComposite_DetermineValueTypeAndSize_m872B0A8E5DEA6864048B0D08DE31FFBA40C442AA (InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, int32_t ___1_part, Type_t** ___2_valueType, int32_t* ___3_valueSizeInBytes, bool* ___4_isButton, const RuntimeMethod* method) ;
// System.Object UnityEngine.InputSystem.InputBindingCompositeContext::ReadValueAsObject(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* InputBindingCompositeContext_ReadValueAsObject_mB707A8B03313DBFE4A3DF4867FE6A20AAAFB1882 (InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* __this, int32_t ___0_partNumber, const RuntimeMethod* method) ;
// System.Collections.Generic.IEnumerable`1<UnityEngine.InputSystem.InputBindingCompositeContext/PartBinding> UnityEngine.InputSystem.InputBindingCompositeContext::get_controls()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* InputBindingCompositeContext_get_controls_m142FECF8374D6E0E3B012C8D376AB913E9634C69 (InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* __this, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.InputSystem.InputBindingCompositeContext/PartBinding::get_part()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t PartBinding_get_part_m93F95BE7AAA2BF480FBD669060C2D1920D5B8943_inline (PartBinding_tB263B939F5CC92F02FD1C8892A194F9BC8A53D38* __this, const RuntimeMethod* method) ;
// UnityEngine.InputSystem.InputControl UnityEngine.InputSystem.InputBindingCompositeContext/PartBinding::get_control()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InputControl_t74F06B623518F992BF8E38656A5E0857169E3E2E* PartBinding_get_control_m96F4C9715F4976504BB4B9BC15D9869E66DDB4F9_inline (PartBinding_tB263B939F5CC92F02FD1C8892A194F9BC8A53D38* __this, const RuntimeMethod* method) ;
// System.Int32 System.Math::Max(System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Math_Max_m530EBA549AFD98CFC2BD29FE86C6376E67DF11CF (int32_t ___0_val1, int32_t ___1_val2, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.InputSystem.InputControl::get_isButton()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool InputControl_get_isButton_m4634F4F40450AA969DA851B73E2A2226239F3BEF (InputControl_t74F06B623518F992BF8E38656A5E0857169E3E2E* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.InputSystem.InputBindingComposite::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InputBindingComposite__ctor_m911F4FDF8BFA44468F8D0493531190FE15242A4A (InputBindingComposite_tA9230435A30FB5B2D4967D6FAE7EFABBBF26C0C0* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.InputSystem.Composites.TwoModifiersComposite::ModifiersArePressed(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool TwoModifiersComposite_ModifiersArePressed_m0D7D12C3139BE7B2CDB1DBDB3C2A59AE584F49C8 (TwoModifiersComposite_t7B84C109D0750D4F515629DD0D3D5C6373F42CA3* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) ;
// UnityEngine.Vector2 UnityEngine.InputSystem.Controls.DpadControl::MakeDpadVector(System.Single,System.Single,System.Single,System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 DpadControl_MakeDpadVector_m5F53CF11B80175D8FF9856B2E126978C65C82CE6 (float ___0_up, float ___1_down, float ___2_left, float ___3_right, const RuntimeMethod* method) ;
// UnityEngine.Vector2 UnityEngine.InputSystem.Controls.DpadControl::MakeDpadVector(System.Boolean,System.Boolean,System.Boolean,System.Boolean,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 DpadControl_MakeDpadVector_mAA0FB9313820797F8F1DCB006A8F2341604CB7F5 (bool ___0_up, bool ___1_down, bool ___2_left, bool ___3_right, bool ___4_normalize, const RuntimeMethod* method) ;
// System.Single UnityEngine.Vector2::get_magnitude()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Vector2_get_magnitude_m5C59B4056420AEFDB291AD0914A3F675330A75CE_inline (Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.InputSystem.InputBindingComposite`1<UnityEngine.Vector2>::.ctor()
inline void InputBindingComposite_1__ctor_m7A3EC8A3F30D4FD3E13C1FDD38CFB5B41B461545 (InputBindingComposite_1_tB7B7EA7F16E4FA573E09983CFE2AE8C7D4616588* __this, const RuntimeMethod* method)
{
	((  void (*) (InputBindingComposite_1_tB7B7EA7F16E4FA573E09983CFE2AE8C7D4616588*, const RuntimeMethod*))InputBindingComposite_1__ctor_m7A3EC8A3F30D4FD3E13C1FDD38CFB5B41B461545_gshared)(__this, method);
}
// System.Void UnityEngine.Vector3::.ctor(System.Single,System.Single,System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* __this, float ___0_x, float ___1_y, float ___2_z, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Vector3::get_normalized()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_get_normalized_m736BBF65D5CDA7A18414370D15B4DFCC1E466F07_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.InputSystem.InputBindingComposite`1<UnityEngine.Vector3>::.ctor()
inline void InputBindingComposite_1__ctor_mCC1C23E6E7958682F8F851C7EF1C1C179E21D789 (InputBindingComposite_1_t34CD8E199158A65EE0E5DBCE8CC705AF3C4B3306* __this, const RuntimeMethod* method)
{
	((  void (*) (InputBindingComposite_1_t34CD8E199158A65EE0E5DBCE8CC705AF3C4B3306*, const RuntimeMethod*))InputBindingComposite_1__ctor_mCC1C23E6E7958682F8F851C7EF1C1C179E21D789_gshared)(__this, method);
}
// UnityEngine.Vector3 UnityEngine.Vector3::Normalize(UnityEngine.Vector3)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_Normalize_mEF8349CC39674236CFC694189AFD36E31F89AC8F_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_value, const RuntimeMethod* method) ;
// System.Single UnityEngine.Vector3::Magnitude(UnityEngine.Vector3)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Vector3_Magnitude_m21652D951393A3D7CE92CE40049A0E7F76544D1B_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_vector, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Vector3::op_Division(UnityEngine.Vector3,System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_op_Division_mCC6BB24E372AB96B8380D1678446EF6A8BAE13BB_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_a, float ___1_d, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Vector3::get_zero()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_get_zero_m0C1249C3F25B1C70EAD3CC8B31259975A457AE39_inline (const RuntimeMethod* method) ;
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
// UnityEngine.Sprite UnityEngine.InputSystem.Utilities.SpriteUtilities::CreateCircleSprite(System.Int32,UnityEngine.Color32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* SpriteUtilities_CreateCircleSprite_m2E675657AD712875B5FBBCD24101A55116A80A72 (int32_t ___0_radius, Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___1_colour, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NativeArrayUnsafeUtility_GetUnsafePtr_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m20D988AA4B5A020595A6FF21F9B26D67BF73B76E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Texture2D_GetRawTextureData_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m3F258FE3486B29D798DCFECF41E9845382EF5CC2_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeUtility_SizeOf_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m506739DDFD44F4F6CE36D20C36BFA90D7F56E4AE_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* V_1 = NULL;
	NativeArray_1_t0783F5E3C7AF6C600A6A20DA7A32D82CA836528D V_2;
	memset((&V_2), 0, sizeof(V_2));
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* V_3 = NULL;
	uint32_t* V_4 = NULL;
	uint64_t V_5 = 0;
	float V_6 = 0.0f;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* V_9 = NULL;
	int32_t V_10 = 0;
	{
		// var d = radius * 2;
		int32_t L_0 = ___0_radius;
		V_0 = ((int32_t)il2cpp_codegen_multiply(L_0, 2));
		// var texture = new Texture2D(d, d, DefaultFormat.LDR, TextureCreationFlags.None);
		int32_t L_1 = V_0;
		int32_t L_2 = V_0;
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_3 = (Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4*)il2cpp_codegen_object_new(Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		Texture2D__ctor_mC16513DD7E46C5CF1D85F985D13D78F4F481DCD7(L_3, L_1, L_2, 0, 0, NULL);
		V_1 = L_3;
		// var colours = texture.GetRawTextureData<Color32>();
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_4 = V_1;
		NullCheck(L_4);
		NativeArray_1_t0783F5E3C7AF6C600A6A20DA7A32D82CA836528D L_5;
		L_5 = Texture2D_GetRawTextureData_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m3F258FE3486B29D798DCFECF41E9845382EF5CC2(L_4, Texture2D_GetRawTextureData_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m3F258FE3486B29D798DCFECF41E9845382EF5CC2_RuntimeMethod_var);
		V_2 = L_5;
		// var coloursPtr = (Color32*)colours.GetUnsafePtr();
		NativeArray_1_t0783F5E3C7AF6C600A6A20DA7A32D82CA836528D L_6 = V_2;
		void* L_7;
		L_7 = NativeArrayUnsafeUtility_GetUnsafePtr_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m20D988AA4B5A020595A6FF21F9B26D67BF73B76E(L_6, NativeArrayUnsafeUtility_GetUnsafePtr_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m20D988AA4B5A020595A6FF21F9B26D67BF73B76E_RuntimeMethod_var);
		V_3 = (Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B*)L_7;
		// UnsafeUtility.MemSet(coloursPtr, 0, colours.Length * UnsafeUtility.SizeOf<Color32>());
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_8 = V_3;
		int32_t L_9;
		L_9 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&V_2))->___m_Length_1);
		int32_t L_10;
		L_10 = UnsafeUtility_SizeOf_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m506739DDFD44F4F6CE36D20C36BFA90D7F56E4AE_inline(UnsafeUtility_SizeOf_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m506739DDFD44F4F6CE36D20C36BFA90D7F56E4AE_RuntimeMethod_var);
		UnsafeUtility_MemSet_m4CD74CD43260EB2962A46F57E0D93DD5C332FC2B((void*)L_8, (uint8_t)0, ((int64_t)((int32_t)il2cpp_codegen_multiply(L_9, L_10))), NULL);
		// var colorPtr = (uint*)UnsafeUtility.AddressOf(ref colour);
		void* L_11;
		L_11 = il2cpp_codegen_unsafe_cast((&___1_colour));
		V_4 = (uint32_t*)L_11;
		// var colourAsULong = *(ulong*)colorPtr << 32 | *colorPtr;
		uint32_t* L_12 = V_4;
		int64_t L_13 = *((int64_t*)L_12);
		uint32_t* L_14 = V_4;
		int32_t L_15 = (*(L_14));
		V_5 = ((int64_t)(((int64_t)(L_13<<((int32_t)32)))|((int64_t)(uint64_t)((uint32_t)L_15))));
		// float rSquared = radius * radius;
		int32_t L_16 = ___0_radius;
		int32_t L_17 = ___0_radius;
		V_6 = ((float)((int32_t)il2cpp_codegen_multiply(L_16, L_17)));
		// for (var y = -radius; y < radius; y++)
		int32_t L_18 = ___0_radius;
		V_7 = ((-L_18));
		goto IL_00b5;
	}

IL_0053:
	{
		// var halfWidth = (int)Mathf.Sqrt(rSquared - y * y);
		float L_19 = V_6;
		int32_t L_20 = V_7;
		int32_t L_21 = V_7;
		float L_22;
		L_22 = sqrtf(((float)il2cpp_codegen_subtract(L_19, ((float)((int32_t)il2cpp_codegen_multiply(L_20, L_21))))));
		V_8 = il2cpp_codegen_cast_double_to_int<int32_t>(L_22);
		// var ptr = coloursPtr
		//     + (y + radius) * d  // the position of the memory at the start of the row at the current y coordinate
		//     + radius - halfWidth;   // the position along the row where we should start inserting colours
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_23 = V_3;
		int32_t L_24 = V_7;
		int32_t L_25 = ___0_radius;
		int32_t L_26 = V_0;
		uint32_t L_27 = sizeof(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B);
		int32_t L_28 = ___0_radius;
		uint32_t L_29 = sizeof(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B);
		int32_t L_30 = V_8;
		uint32_t L_31 = sizeof(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B);
		V_9 = ((Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B*)il2cpp_codegen_subtract((intptr_t)((Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B*)il2cpp_codegen_add((intptr_t)((Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B*)il2cpp_codegen_add((intptr_t)L_23, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_add(L_24, L_25)), L_26))), (int32_t)L_27)))), ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_28), (int32_t)L_29)))), ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_30), (int32_t)L_31))));
		// for (var x = 0; x < halfWidth; x++)
		V_10 = 0;
		goto IL_00a9;
	}

IL_0090:
	{
		// *(ulong*)ptr = colourAsULong;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_32 = V_9;
		uint64_t L_33 = V_5;
		*((int64_t*)L_32) = (int64_t)L_33;
		// ptr += 2;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_34 = V_9;
		uint32_t L_35 = sizeof(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B);
		V_9 = ((Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B*)il2cpp_codegen_add((intptr_t)L_34, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)2), (int32_t)L_35))));
		// for (var x = 0; x < halfWidth; x++)
		int32_t L_36 = V_10;
		V_10 = ((int32_t)il2cpp_codegen_add(L_36, 1));
	}

IL_00a9:
	{
		// for (var x = 0; x < halfWidth; x++)
		int32_t L_37 = V_10;
		int32_t L_38 = V_8;
		if ((((int32_t)L_37) < ((int32_t)L_38)))
		{
			goto IL_0090;
		}
	}
	{
		// for (var y = -radius; y < radius; y++)
		int32_t L_39 = V_7;
		V_7 = ((int32_t)il2cpp_codegen_add(L_39, 1));
	}

IL_00b5:
	{
		// for (var y = -radius; y < radius; y++)
		int32_t L_40 = V_7;
		int32_t L_41 = ___0_radius;
		if ((((int32_t)L_40) < ((int32_t)L_41)))
		{
			goto IL_0053;
		}
	}
	{
		// texture.Apply();
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_42 = V_1;
		NullCheck(L_42);
		Texture2D_Apply_mA014182C9EE0BBF6EEE3B286854F29E50EB972DC(L_42, NULL);
		// var sprite = Sprite.Create(texture, new Rect(0, 0, d, d), new Vector2(radius, radius), 1, 0, SpriteMeshType.FullRect);
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_43 = V_1;
		int32_t L_44 = V_0;
		int32_t L_45 = V_0;
		Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D L_46;
		memset((&L_46), 0, sizeof(L_46));
		Rect__ctor_m18C3033D135097BEE424AAA68D91C706D2647F23((&L_46), (0.0f), (0.0f), ((float)L_44), ((float)L_45), /*hidden argument*/NULL);
		int32_t L_47 = ___0_radius;
		int32_t L_48 = ___0_radius;
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_49;
		memset((&L_49), 0, sizeof(L_49));
		Vector2__ctor_m9525B79969AFFE3254B303A40997A56DEEB6F548_inline((&L_49), ((float)L_47), ((float)L_48), /*hidden argument*/NULL);
		Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* L_50;
		L_50 = Sprite_Create_m519615D3E7835F70DC5B4CB93A4A481E14265C69(L_43, L_46, L_49, (1.0f), 0, 0, NULL);
		// return sprite;
		return L_50;
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
// System.String UnityEngine.InputSystem.Utilities.StringHelpers::Escape(System.String,System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* StringHelpers_Escape_mC7D149B1F430F68BA748DE0C0374F4B1EE9D2C58 (String_t* ___0_str, String_t* ___1_chars, String_t* ___2_replacements, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	StringBuilder_t* V_1 = NULL;
	String_t* V_2 = NULL;
	int32_t V_3 = 0;
	Il2CppChar V_4 = 0x0;
	Il2CppChar V_5 = 0x0;
	int32_t V_6 = 0;
	{
		// if (str == null)
		String_t* L_0 = ___0_str;
		if (L_0)
		{
			goto IL_0005;
		}
	}
	{
		// return null;
		return (String_t*)NULL;
	}

IL_0005:
	{
		// var hasCharacterThatNeedsEscaping = false;
		V_0 = (bool)0;
		// foreach (var ch in str)
		String_t* L_1 = ___0_str;
		V_2 = L_1;
		V_3 = 0;
		goto IL_0028;
	}

IL_000d:
	{
		// foreach (var ch in str)
		String_t* L_2 = V_2;
		int32_t L_3 = V_3;
		NullCheck(L_2);
		Il2CppChar L_4;
		L_4 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_2, L_3, NULL);
		V_4 = L_4;
		// if (chars.Contains(ch))
		String_t* L_5 = ___1_chars;
		Il2CppChar L_6 = V_4;
		NullCheck(L_5);
		bool L_7;
		L_7 = String_Contains_mC67F1B9E92187E2BB125A560160DA30A5BA703F2(L_5, L_6, NULL);
		if (!L_7)
		{
			goto IL_0024;
		}
	}
	{
		// hasCharacterThatNeedsEscaping = true;
		V_0 = (bool)1;
		// break;
		goto IL_0031;
	}

IL_0024:
	{
		int32_t L_8 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_8, 1));
	}

IL_0028:
	{
		// foreach (var ch in str)
		int32_t L_9 = V_3;
		String_t* L_10 = V_2;
		NullCheck(L_10);
		int32_t L_11;
		L_11 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_10, NULL);
		if ((((int32_t)L_9) < ((int32_t)L_11)))
		{
			goto IL_000d;
		}
	}

IL_0031:
	{
		// if (!hasCharacterThatNeedsEscaping)
		bool L_12 = V_0;
		if (L_12)
		{
			goto IL_0036;
		}
	}
	{
		// return str;
		String_t* L_13 = ___0_str;
		return L_13;
	}

IL_0036:
	{
		// var builder = new StringBuilder();
		StringBuilder_t* L_14 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		NullCheck(L_14);
		StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D(L_14, NULL);
		V_1 = L_14;
		// foreach (var ch in str)
		String_t* L_15 = ___0_str;
		V_2 = L_15;
		V_3 = 0;
		goto IL_0081;
	}

IL_0042:
	{
		// foreach (var ch in str)
		String_t* L_16 = V_2;
		int32_t L_17 = V_3;
		NullCheck(L_16);
		Il2CppChar L_18;
		L_18 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_16, L_17, NULL);
		V_5 = L_18;
		// var index = chars.IndexOf(ch);
		String_t* L_19 = ___1_chars;
		Il2CppChar L_20 = V_5;
		NullCheck(L_19);
		int32_t L_21;
		L_21 = String_IndexOf_mE21E78F35EF4A7768E385A72814C88D22B689966(L_19, L_20, NULL);
		V_6 = L_21;
		// if (index == -1)
		int32_t L_22 = V_6;
		if ((!(((uint32_t)L_22) == ((uint32_t)(-1)))))
		{
			goto IL_0065;
		}
	}
	{
		// builder.Append(ch);
		StringBuilder_t* L_23 = V_1;
		Il2CppChar L_24 = V_5;
		NullCheck(L_23);
		StringBuilder_t* L_25;
		L_25 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_23, L_24, NULL);
		goto IL_007d;
	}

IL_0065:
	{
		// builder.Append('\\');
		StringBuilder_t* L_26 = V_1;
		NullCheck(L_26);
		StringBuilder_t* L_27;
		L_27 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_26, ((int32_t)92), NULL);
		// builder.Append(replacements[index]);
		StringBuilder_t* L_28 = V_1;
		String_t* L_29 = ___2_replacements;
		int32_t L_30 = V_6;
		NullCheck(L_29);
		Il2CppChar L_31;
		L_31 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_29, L_30, NULL);
		NullCheck(L_28);
		StringBuilder_t* L_32;
		L_32 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_28, L_31, NULL);
	}

IL_007d:
	{
		int32_t L_33 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_33, 1));
	}

IL_0081:
	{
		// foreach (var ch in str)
		int32_t L_34 = V_3;
		String_t* L_35 = V_2;
		NullCheck(L_35);
		int32_t L_36;
		L_36 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_35, NULL);
		if ((((int32_t)L_34) < ((int32_t)L_36)))
		{
			goto IL_0042;
		}
	}
	{
		// return builder.ToString();
		StringBuilder_t* L_37 = V_1;
		NullCheck(L_37);
		String_t* L_38;
		L_38 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_37);
		return L_38;
	}
}
// System.String UnityEngine.InputSystem.Utilities.StringHelpers::Unescape(System.String,System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* StringHelpers_Unescape_m1D5A3A094308ACB6D69D936B52E7835BF1263B0B (String_t* ___0_str, String_t* ___1_chars, String_t* ___2_replacements, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	StringBuilder_t* V_0 = NULL;
	int32_t V_1 = 0;
	Il2CppChar V_2 = 0x0;
	int32_t V_3 = 0;
	{
		// if (str == null)
		String_t* L_0 = ___0_str;
		if (L_0)
		{
			goto IL_0005;
		}
	}
	{
		// return str;
		String_t* L_1 = ___0_str;
		return L_1;
	}

IL_0005:
	{
		// if (!str.Contains('\\'))
		String_t* L_2 = ___0_str;
		NullCheck(L_2);
		bool L_3;
		L_3 = String_Contains_mC67F1B9E92187E2BB125A560160DA30A5BA703F2(L_2, ((int32_t)92), NULL);
		if (L_3)
		{
			goto IL_0011;
		}
	}
	{
		// return str;
		String_t* L_4 = ___0_str;
		return L_4;
	}

IL_0011:
	{
		// var builder = new StringBuilder();
		StringBuilder_t* L_5 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		NullCheck(L_5);
		StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D(L_5, NULL);
		V_0 = L_5;
		// for (var i = 0; i < str.Length; ++i)
		V_1 = 0;
		goto IL_0071;
	}

IL_001b:
	{
		// var ch = str[i];
		String_t* L_6 = ___0_str;
		int32_t L_7 = V_1;
		NullCheck(L_6);
		Il2CppChar L_8;
		L_8 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_6, L_7, NULL);
		V_2 = L_8;
		// if (ch == '\\' && i < str.Length - 2)
		Il2CppChar L_9 = V_2;
		if ((!(((uint32_t)L_9) == ((uint32_t)((int32_t)92)))))
		{
			goto IL_0065;
		}
	}
	{
		int32_t L_10 = V_1;
		String_t* L_11 = ___0_str;
		NullCheck(L_11);
		int32_t L_12;
		L_12 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_11, NULL);
		if ((((int32_t)L_10) >= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_12, 2)))))
		{
			goto IL_0065;
		}
	}
	{
		// ++i;
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
		// ch = str[i];
		String_t* L_14 = ___0_str;
		int32_t L_15 = V_1;
		NullCheck(L_14);
		Il2CppChar L_16;
		L_16 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_14, L_15, NULL);
		V_2 = L_16;
		// var index = chars.IndexOf(ch);
		String_t* L_17 = ___1_chars;
		Il2CppChar L_18 = V_2;
		NullCheck(L_17);
		int32_t L_19;
		L_19 = String_IndexOf_mE21E78F35EF4A7768E385A72814C88D22B689966(L_17, L_18, NULL);
		V_3 = L_19;
		// if (index != -1)
		int32_t L_20 = V_3;
		if ((((int32_t)L_20) == ((int32_t)(-1))))
		{
			goto IL_005b;
		}
	}
	{
		// builder.Append(replacements[index]);
		StringBuilder_t* L_21 = V_0;
		String_t* L_22 = ___2_replacements;
		int32_t L_23 = V_3;
		NullCheck(L_22);
		Il2CppChar L_24;
		L_24 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_22, L_23, NULL);
		NullCheck(L_21);
		StringBuilder_t* L_25;
		L_25 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_21, L_24, NULL);
		goto IL_006d;
	}

IL_005b:
	{
		// builder.Append(ch);
		StringBuilder_t* L_26 = V_0;
		Il2CppChar L_27 = V_2;
		NullCheck(L_26);
		StringBuilder_t* L_28;
		L_28 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_26, L_27, NULL);
		goto IL_006d;
	}

IL_0065:
	{
		// builder.Append(ch);
		StringBuilder_t* L_29 = V_0;
		Il2CppChar L_30 = V_2;
		NullCheck(L_29);
		StringBuilder_t* L_31;
		L_31 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_29, L_30, NULL);
	}

IL_006d:
	{
		// for (var i = 0; i < str.Length; ++i)
		int32_t L_32 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_32, 1));
	}

IL_0071:
	{
		// for (var i = 0; i < str.Length; ++i)
		int32_t L_33 = V_1;
		String_t* L_34 = ___0_str;
		NullCheck(L_34);
		int32_t L_35;
		L_35 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_34, NULL);
		if ((((int32_t)L_33) < ((int32_t)L_35)))
		{
			goto IL_001b;
		}
	}
	{
		// return builder.ToString();
		StringBuilder_t* L_36 = V_0;
		NullCheck(L_36);
		String_t* L_37;
		L_37 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_36);
		return L_37;
	}
}
// System.Boolean UnityEngine.InputSystem.Utilities.StringHelpers::Contains(System.String,System.Char)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool StringHelpers_Contains_m82DF79195262C5C3C7AE75D4615402274BAAEEC5 (String_t* ___0_str, Il2CppChar ___1_ch, const RuntimeMethod* method) 
{
	{
		// if (str == null)
		String_t* L_0 = ___0_str;
		if (L_0)
		{
			goto IL_0005;
		}
	}
	{
		// return false;
		return (bool)0;
	}

IL_0005:
	{
		// return str.IndexOf(ch) != -1;
		String_t* L_1 = ___0_str;
		Il2CppChar L_2 = ___1_ch;
		NullCheck(L_1);
		int32_t L_3;
		L_3 = String_IndexOf_mE21E78F35EF4A7768E385A72814C88D22B689966(L_1, L_2, NULL);
		return (bool)((((int32_t)((((int32_t)L_3) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// System.Boolean UnityEngine.InputSystem.Utilities.StringHelpers::Contains(System.String,System.String,System.StringComparison)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool StringHelpers_Contains_m3E0C5D7404AE7B0D97452951A6ECE12618C03DCB (String_t* ___0_str, String_t* ___1_text, int32_t ___2_comparison, const RuntimeMethod* method) 
{
	{
		// if (str == null)
		String_t* L_0 = ___0_str;
		if (L_0)
		{
			goto IL_0005;
		}
	}
	{
		// return false;
		return (bool)0;
	}

IL_0005:
	{
		// return str.IndexOf(text, comparison) != -1;
		String_t* L_1 = ___0_str;
		String_t* L_2 = ___1_text;
		int32_t L_3 = ___2_comparison;
		NullCheck(L_1);
		int32_t L_4;
		L_4 = String_IndexOf_m490810CB7ADA9230AC0F8D78E213A8EFED129F55(L_1, L_2, L_3, NULL);
		return (bool)((((int32_t)((((int32_t)L_4) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// System.String UnityEngine.InputSystem.Utilities.StringHelpers::GetPlural(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* StringHelpers_GetPlural_m5A928581053494366B2905658A9919737955AEBA (String_t* ___0_str, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral294F098A1D5E681EDEE8F43BFA8F45CFBA5798A7);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral3775297E15AD530F68BA7AF3896E3A261B24AD81);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral628D1F19515023762299C5A2AF8A34A399049CE6);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral82BA8BFC18D84C67108B27396795EDFAEE187B83);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD6315798FF47A5A5AB2AD03739B4783B2AD1305B);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDAF2BD03270A51BF9C135F3694DCAD2D3E66F465);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDE7D042A807341C354F398C43F38F92D9AFDAA21);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralEE71910C7E19B0D89B96AF6011CDFDAF6EA1CF1C);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF3FEA1B7EED06B84D345A14D3BB9E817F4B9EAFE);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (str == null)
		String_t* L_0 = ___0_str;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		// throw new ArgumentNullException(nameof(str));
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		NullCheck(L_1);
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralA185F0FDE2E3A93D140F407291AA8AA60D14D5DA)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&StringHelpers_GetPlural_m5A928581053494366B2905658A9919737955AEBA_RuntimeMethod_var)));
	}

IL_000e:
	{
		String_t* L_2 = ___0_str;
		bool L_3;
		L_3 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_2, _stringLiteral294F098A1D5E681EDEE8F43BFA8F45CFBA5798A7, NULL);
		if (L_3)
		{
			goto IL_0044;
		}
	}
	{
		String_t* L_4 = ___0_str;
		bool L_5;
		L_5 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_4, _stringLiteralF3FEA1B7EED06B84D345A14D3BB9E817F4B9EAFE, NULL);
		if (L_5)
		{
			goto IL_004a;
		}
	}
	{
		String_t* L_6 = ___0_str;
		bool L_7;
		L_7 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_6, _stringLiteralEE71910C7E19B0D89B96AF6011CDFDAF6EA1CF1C, NULL);
		if (L_7)
		{
			goto IL_0050;
		}
	}
	{
		String_t* L_8 = ___0_str;
		bool L_9;
		L_9 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_8, _stringLiteralD6315798FF47A5A5AB2AD03739B4783B2AD1305B, NULL);
		if (L_9)
		{
			goto IL_0056;
		}
	}
	{
		goto IL_005c;
	}

IL_0044:
	{
		// case "Mouse": return "Mice";
		return _stringLiteral628D1F19515023762299C5A2AF8A34A399049CE6;
	}

IL_004a:
	{
		// case "mouse": return "mice";
		return _stringLiteral3775297E15AD530F68BA7AF3896E3A261B24AD81;
	}

IL_0050:
	{
		// case "Axis": return "Axes";
		return _stringLiteralDE7D042A807341C354F398C43F38F92D9AFDAA21;
	}

IL_0056:
	{
		// case "axis": return "axes";
		return _stringLiteral82BA8BFC18D84C67108B27396795EDFAEE187B83;
	}

IL_005c:
	{
		// return str + 's';
		String_t* L_10 = ___0_str;
		String_t* L_11;
		L_11 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(L_10, _stringLiteralDAF2BD03270A51BF9C135F3694DCAD2D3E66F465, NULL);
		return L_11;
	}
}
// System.String UnityEngine.InputSystem.Utilities.StringHelpers::NicifyMemorySize(System.Int64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* StringHelpers_NicifyMemorySize_m12E1910BF1FC6445BB44D7903731CE04F52447E6 (int64_t ___0_numBytes, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1C62C7650E13E5763946286B7B28B980E977B33C);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral28F49FF685EF5968942FC2C44FA5408C4659B72C);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7720D93C700AB5486B175C224CEF31CC1C99380B);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral88B5D0E6F79C8EDF1FD287D9EBCA6E2CBBA34F67);
		s_Il2CppMethodInitialized = true;
	}
	int64_t V_0 = 0;
	float V_1 = 0.0f;
	int64_t V_2 = 0;
	float V_3 = 0.0f;
	int64_t V_4 = 0;
	float V_5 = 0.0f;
	{
		// if (numBytes > 1024 * 1024 * 1024)
		int64_t L_0 = ___0_numBytes;
		if ((((int64_t)L_0) <= ((int64_t)((int64_t)((int32_t)1073741824)))))
		{
			goto IL_0036;
		}
	}
	{
		// var gb = numBytes / (1024 * 1024 * 1024);
		int64_t L_1 = ___0_numBytes;
		V_0 = ((int64_t)(L_1/((int64_t)((int32_t)1073741824))));
		// var remainder = (numBytes % (1024 * 1024 * 1024)) / 1.0f;
		int64_t L_2 = ___0_numBytes;
		V_1 = ((float)(((float)((int64_t)(L_2%((int64_t)((int32_t)1073741824)))))/(1.0f)));
		// return $"{gb + remainder} GB";
		int64_t L_3 = V_0;
		float L_4 = V_1;
		float L_5 = ((float)il2cpp_codegen_add(((float)L_3), L_4));
		RuntimeObject* L_6 = Box(Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var, &L_5);
		String_t* L_7;
		L_7 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(_stringLiteral88B5D0E6F79C8EDF1FD287D9EBCA6E2CBBA34F67, L_6, NULL);
		return L_7;
	}

IL_0036:
	{
		// if (numBytes > 1024 * 1024)
		int64_t L_8 = ___0_numBytes;
		if ((((int64_t)L_8) <= ((int64_t)((int64_t)((int32_t)1048576)))))
		{
			goto IL_006c;
		}
	}
	{
		// var mb = numBytes / (1024 * 1024);
		int64_t L_9 = ___0_numBytes;
		V_2 = ((int64_t)(L_9/((int64_t)((int32_t)1048576))));
		// var remainder = (numBytes % (1024 * 1024)) / 1.0f;
		int64_t L_10 = ___0_numBytes;
		V_3 = ((float)(((float)((int64_t)(L_10%((int64_t)((int32_t)1048576)))))/(1.0f)));
		// return $"{mb + remainder} MB";
		int64_t L_11 = V_2;
		float L_12 = V_3;
		float L_13 = ((float)il2cpp_codegen_add(((float)L_11), L_12));
		RuntimeObject* L_14 = Box(Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var, &L_13);
		String_t* L_15;
		L_15 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(_stringLiteral7720D93C700AB5486B175C224CEF31CC1C99380B, L_14, NULL);
		return L_15;
	}

IL_006c:
	{
		// if (numBytes > 1024)
		int64_t L_16 = ___0_numBytes;
		if ((((int64_t)L_16) <= ((int64_t)((int64_t)((int32_t)1024)))))
		{
			goto IL_00a6;
		}
	}
	{
		// var kb = numBytes / 1024;
		int64_t L_17 = ___0_numBytes;
		V_4 = ((int64_t)(L_17/((int64_t)((int32_t)1024))));
		// var remainder = (numBytes % 1024) / 1.0f;
		int64_t L_18 = ___0_numBytes;
		V_5 = ((float)(((float)((int64_t)(L_18%((int64_t)((int32_t)1024)))))/(1.0f)));
		// return $"{kb + remainder} KB";
		int64_t L_19 = V_4;
		float L_20 = V_5;
		float L_21 = ((float)il2cpp_codegen_add(((float)L_19), L_20));
		RuntimeObject* L_22 = Box(Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var, &L_21);
		String_t* L_23;
		L_23 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(_stringLiteral28F49FF685EF5968942FC2C44FA5408C4659B72C, L_22, NULL);
		return L_23;
	}

IL_00a6:
	{
		// return $"{numBytes} Bytes";
		int64_t L_24 = ___0_numBytes;
		int64_t L_25 = L_24;
		RuntimeObject* L_26 = Box(Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var, &L_25);
		String_t* L_27;
		L_27 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(_stringLiteral1C62C7650E13E5763946286B7B28B980E977B33C, L_26, NULL);
		return L_27;
	}
}
// System.Boolean UnityEngine.InputSystem.Utilities.StringHelpers::FromNicifiedMemorySize(System.String,System.Int64&,System.Int64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool StringHelpers_FromNicifiedMemorySize_mE0CAA17D1D9B7CC9EA1932CA345D1F381368893D (String_t* ___0_text, int64_t* ___1_result, int64_t ___2_defaultMultiplier, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral14B651F3933E2742FD0FE0E45504AD43A5985248);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralAF29A356E2E2350A3712E86EFEC38A631035EEDC);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC4E550DB7753938B55BD2444CB204B2C254AF826);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF1E972CD03013DE732424893507C3C55D004E089);
		s_Il2CppMethodInitialized = true;
	}
	int64_t V_0 = 0;
	int64_t V_1 = 0;
	{
		// text = text.Trim();
		String_t* L_0 = ___0_text;
		NullCheck(L_0);
		String_t* L_1;
		L_1 = String_Trim_mCD6D8C6D4CFD15225D12DB7D3E0544CA80FB8DA5(L_0, NULL);
		___0_text = L_1;
		// var multiplier = defaultMultiplier;
		int64_t L_2 = ___2_defaultMultiplier;
		V_0 = L_2;
		// if (text.EndsWith("MB", StringComparison.InvariantCultureIgnoreCase))
		String_t* L_3 = ___0_text;
		NullCheck(L_3);
		bool L_4;
		L_4 = String_EndsWith_m5E5D307CA6AEB7C08CE782B4693B19D07ADC9075(L_3, _stringLiteralC4E550DB7753938B55BD2444CB204B2C254AF826, 3, NULL);
		if (!L_4)
		{
			goto IL_0032;
		}
	}
	{
		// multiplier = 1024 * 1024;
		V_0 = ((int64_t)((int32_t)1048576));
		// text = text.Substring(0, text.Length - 2);
		String_t* L_5 = ___0_text;
		String_t* L_6 = ___0_text;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_6, NULL);
		NullCheck(L_5);
		String_t* L_8;
		L_8 = String_Substring_mB1D94F47935D22E130FF2C01DBB6A4135FBB76CE(L_5, 0, ((int32_t)il2cpp_codegen_subtract(L_7, 2)), NULL);
		___0_text = L_8;
		goto IL_00ad;
	}

IL_0032:
	{
		// else if (text.EndsWith("GB", StringComparison.InvariantCultureIgnoreCase))
		String_t* L_9 = ___0_text;
		NullCheck(L_9);
		bool L_10;
		L_10 = String_EndsWith_m5E5D307CA6AEB7C08CE782B4693B19D07ADC9075(L_9, _stringLiteralF1E972CD03013DE732424893507C3C55D004E089, 3, NULL);
		if (!L_10)
		{
			goto IL_005a;
		}
	}
	{
		// multiplier = 1024 * 1024 * 1024;
		V_0 = ((int64_t)((int32_t)1073741824));
		// text = text.Substring(0, text.Length - 2);
		String_t* L_11 = ___0_text;
		String_t* L_12 = ___0_text;
		NullCheck(L_12);
		int32_t L_13;
		L_13 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_12, NULL);
		NullCheck(L_11);
		String_t* L_14;
		L_14 = String_Substring_mB1D94F47935D22E130FF2C01DBB6A4135FBB76CE(L_11, 0, ((int32_t)il2cpp_codegen_subtract(L_13, 2)), NULL);
		___0_text = L_14;
		goto IL_00ad;
	}

IL_005a:
	{
		// else if (text.EndsWith("KB", StringComparison.InvariantCultureIgnoreCase))
		String_t* L_15 = ___0_text;
		NullCheck(L_15);
		bool L_16;
		L_16 = String_EndsWith_m5E5D307CA6AEB7C08CE782B4693B19D07ADC9075(L_15, _stringLiteral14B651F3933E2742FD0FE0E45504AD43A5985248, 3, NULL);
		if (!L_16)
		{
			goto IL_0082;
		}
	}
	{
		// multiplier = 1024;
		V_0 = ((int64_t)((int32_t)1024));
		// text = text.Substring(0, text.Length - 2);
		String_t* L_17 = ___0_text;
		String_t* L_18 = ___0_text;
		NullCheck(L_18);
		int32_t L_19;
		L_19 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_18, NULL);
		NullCheck(L_17);
		String_t* L_20;
		L_20 = String_Substring_mB1D94F47935D22E130FF2C01DBB6A4135FBB76CE(L_17, 0, ((int32_t)il2cpp_codegen_subtract(L_19, 2)), NULL);
		___0_text = L_20;
		goto IL_00ad;
	}

IL_0082:
	{
		// else if (text.EndsWith("Bytes", StringComparison.InvariantCultureIgnoreCase))
		String_t* L_21 = ___0_text;
		NullCheck(L_21);
		bool L_22;
		L_22 = String_EndsWith_m5E5D307CA6AEB7C08CE782B4693B19D07ADC9075(L_21, _stringLiteralAF29A356E2E2350A3712E86EFEC38A631035EEDC, 3, NULL);
		if (!L_22)
		{
			goto IL_00ad;
		}
	}
	{
		// multiplier = 1;
		V_0 = ((int64_t)1);
		// text = text.Substring(0, text.Length - "Bytes".Length);
		String_t* L_23 = ___0_text;
		String_t* L_24 = ___0_text;
		NullCheck(L_24);
		int32_t L_25;
		L_25 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_24, NULL);
		NullCheck(_stringLiteralAF29A356E2E2350A3712E86EFEC38A631035EEDC);
		int32_t L_26;
		L_26 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(_stringLiteralAF29A356E2E2350A3712E86EFEC38A631035EEDC, NULL);
		NullCheck(L_23);
		String_t* L_27;
		L_27 = String_Substring_mB1D94F47935D22E130FF2C01DBB6A4135FBB76CE(L_23, 0, ((int32_t)il2cpp_codegen_subtract(L_25, L_26)), NULL);
		___0_text = L_27;
	}

IL_00ad:
	{
		// if (!long.TryParse(text, out var num))
		String_t* L_28 = ___0_text;
		bool L_29;
		L_29 = Int64_TryParse_m3FC0128C89CC2331239FC2A0A749BF33455F03D2(L_28, (&V_1), NULL);
		if (L_29)
		{
			goto IL_00bd;
		}
	}
	{
		// result = default;
		int64_t* L_30 = ___1_result;
		*((int64_t*)L_30) = (int64_t)((int64_t)0);
		// return false;
		return (bool)0;
	}

IL_00bd:
	{
		// result = num * multiplier;
		int64_t* L_31 = ___1_result;
		int64_t L_32 = V_1;
		int64_t L_33 = V_0;
		*((int64_t*)L_31) = (int64_t)((int64_t)il2cpp_codegen_multiply(L_32, L_33));
		// return true;
		return (bool)1;
	}
}
// System.Int32 UnityEngine.InputSystem.Utilities.StringHelpers::CountOccurrences(System.String,System.Char)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t StringHelpers_CountOccurrences_mF1BB446EF34C10970969D34799E8D5F4AC2BA0B1 (String_t* ___0_str, Il2CppChar ___1_ch, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	{
		// if (str == null)
		String_t* L_0 = ___0_str;
		if (L_0)
		{
			goto IL_0005;
		}
	}
	{
		// return 0;
		return 0;
	}

IL_0005:
	{
		// var length = str.Length;
		String_t* L_1 = ___0_str;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_1, NULL);
		V_0 = L_2;
		// var index = 0;
		V_1 = 0;
		// var count = 0;
		V_2 = 0;
		goto IL_0027;
	}

IL_0012:
	{
		// var nextIndex = str.IndexOf(ch, index);
		String_t* L_3 = ___0_str;
		Il2CppChar L_4 = ___1_ch;
		int32_t L_5 = V_1;
		NullCheck(L_3);
		int32_t L_6;
		L_6 = String_IndexOf_m15B90A59047584420D227EE3A7EAC0C5EAF676F4(L_3, L_4, L_5, NULL);
		V_3 = L_6;
		// if (nextIndex == -1)
		int32_t L_7 = V_3;
		if ((((int32_t)L_7) == ((int32_t)(-1))))
		{
			goto IL_002b;
		}
	}
	{
		// ++count;
		int32_t L_8 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_8, 1));
		// index = nextIndex + 1;
		int32_t L_9 = V_3;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0027:
	{
		// while (index < length)
		int32_t L_10 = V_1;
		int32_t L_11 = V_0;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0012;
		}
	}

IL_002b:
	{
		// return count;
		int32_t L_12 = V_2;
		return L_12;
	}
}
// System.Collections.Generic.IEnumerable`1<UnityEngine.InputSystem.Utilities.Substring> UnityEngine.InputSystem.Utilities.StringHelpers::Tokenize(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* StringHelpers_Tokenize_mD01A8F510135AF699052593B08F9890F690D18B0 (String_t* ___0_str, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B* L_0 = (U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B*)il2cpp_codegen_object_new(U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		U3CTokenizeU3Ed__8__ctor_mFCB5DCEF9B0F44B630C8C831ADC12246A0CA2785(L_0, ((int32_t)-2), NULL);
		U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B* L_1 = L_0;
		String_t* L_2 = ___0_str;
		NullCheck(L_1);
		L_1->___U3CU3E3__str_4 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&L_1->___U3CU3E3__str_4), (void*)L_2);
		return L_1;
	}
}
// System.Collections.Generic.IEnumerable`1<System.String> UnityEngine.InputSystem.Utilities.StringHelpers::Split(System.String,System.Func`2<System.Char,System.Boolean>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* StringHelpers_Split_m60C45D240967D0DC8B9C651A25597B31C16A5FF8 (String_t* ___0_str, Func_2_tF409A653B8F770E0A30CD80D21764FB1DDB2A28F* ___1_predicate, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF* L_0 = (U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF*)il2cpp_codegen_object_new(U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		U3CSplitU3Ed__9__ctor_m531A6132094F2E8117F46518BCD07DBECF2F8B60(L_0, ((int32_t)-2), NULL);
		U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF* L_1 = L_0;
		String_t* L_2 = ___0_str;
		NullCheck(L_1);
		L_1->___U3CU3E3__str_4 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&L_1->___U3CU3E3__str_4), (void*)L_2);
		U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF* L_3 = L_1;
		Func_2_tF409A653B8F770E0A30CD80D21764FB1DDB2A28F* L_4 = ___1_predicate;
		NullCheck(L_3);
		L_3->___U3CU3E3__predicate_6 = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&L_3->___U3CU3E3__predicate_6), (void*)L_4);
		return L_3;
	}
}
// System.Boolean UnityEngine.InputSystem.Utilities.StringHelpers::CharacterSeparatedListsHaveAtLeastOneCommonElement(System.String,System.String,System.Char)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool StringHelpers_CharacterSeparatedListsHaveAtLeastOneCommonElement_m0A3E70D748E3E17DEA06FAD3553F3049F169A190 (String_t* ___0_firstList, String_t* ___1_secondList, Il2CppChar ___2_separator, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	bool V_10 = false;
	int32_t V_11 = 0;
	Il2CppChar V_12 = 0x0;
	{
		// if (firstList == null)
		String_t* L_0 = ___0_firstList;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		// throw new ArgumentNullException(nameof(firstList));
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		NullCheck(L_1);
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral54955F5500C6186211E2357D711CD0C3E4017D6B)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&StringHelpers_CharacterSeparatedListsHaveAtLeastOneCommonElement_m0A3E70D748E3E17DEA06FAD3553F3049F169A190_RuntimeMethod_var)));
	}

IL_000e:
	{
		// if (secondList == null)
		String_t* L_2 = ___1_secondList;
		if (L_2)
		{
			goto IL_001c;
		}
	}
	{
		// throw new ArgumentNullException(nameof(secondList));
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_3 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		NullCheck(L_3);
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralCFDA33CEC1161BE8CA5B06D2480EA1925FA4ACBE)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&StringHelpers_CharacterSeparatedListsHaveAtLeastOneCommonElement_m0A3E70D748E3E17DEA06FAD3553F3049F169A190_RuntimeMethod_var)));
	}

IL_001c:
	{
		// var indexInFirst = 0;
		V_0 = 0;
		// var lengthOfFirst = firstList.Length;
		String_t* L_4 = ___0_firstList;
		NullCheck(L_4);
		int32_t L_5;
		L_5 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_4, NULL);
		V_1 = L_5;
		// var lengthOfSecond = secondList.Length;
		String_t* L_6 = ___1_secondList;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_6, NULL);
		V_2 = L_7;
		goto IL_00fe;
	}

IL_0031:
	{
		// if (firstList[indexInFirst] == separator)
		String_t* L_8 = ___0_firstList;
		int32_t L_9 = V_0;
		NullCheck(L_8);
		Il2CppChar L_10;
		L_10 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_8, L_9, NULL);
		Il2CppChar L_11 = ___2_separator;
		if ((!(((uint32_t)L_10) == ((uint32_t)L_11))))
		{
			goto IL_003f;
		}
	}
	{
		// ++indexInFirst;
		int32_t L_12 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_12, 1));
	}

IL_003f:
	{
		// var endIndexInFirst = indexInFirst + 1;
		int32_t L_13 = V_0;
		V_3 = ((int32_t)il2cpp_codegen_add(L_13, 1));
		goto IL_0049;
	}

IL_0045:
	{
		// ++endIndexInFirst;
		int32_t L_14 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_14, 1));
	}

IL_0049:
	{
		// while (endIndexInFirst < lengthOfFirst && firstList[endIndexInFirst] != separator)
		int32_t L_15 = V_3;
		int32_t L_16 = V_1;
		if ((((int32_t)L_15) >= ((int32_t)L_16)))
		{
			goto IL_0057;
		}
	}
	{
		String_t* L_17 = ___0_firstList;
		int32_t L_18 = V_3;
		NullCheck(L_17);
		Il2CppChar L_19;
		L_19 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_17, L_18, NULL);
		Il2CppChar L_20 = ___2_separator;
		if ((!(((uint32_t)L_19) == ((uint32_t)L_20))))
		{
			goto IL_0045;
		}
	}

IL_0057:
	{
		// var lengthOfCurrentInFirst = endIndexInFirst - indexInFirst;
		int32_t L_21 = V_3;
		int32_t L_22 = V_0;
		V_4 = ((int32_t)il2cpp_codegen_subtract(L_21, L_22));
		// var indexInSecond = 0;
		V_5 = 0;
		goto IL_00f2;
	}

IL_0064:
	{
		// if (secondList[indexInSecond] == separator)
		String_t* L_23 = ___1_secondList;
		int32_t L_24 = V_5;
		NullCheck(L_23);
		Il2CppChar L_25;
		L_25 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_23, L_24, NULL);
		Il2CppChar L_26 = ___2_separator;
		if ((!(((uint32_t)L_25) == ((uint32_t)L_26))))
		{
			goto IL_0075;
		}
	}
	{
		// ++indexInSecond;
		int32_t L_27 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_27, 1));
	}

IL_0075:
	{
		// var endIndexInSecond = indexInSecond + 1;
		int32_t L_28 = V_5;
		V_6 = ((int32_t)il2cpp_codegen_add(L_28, 1));
		goto IL_0083;
	}

IL_007d:
	{
		// ++endIndexInSecond;
		int32_t L_29 = V_6;
		V_6 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_0083:
	{
		// while (endIndexInSecond < lengthOfSecond && secondList[endIndexInSecond] != separator)
		int32_t L_30 = V_6;
		int32_t L_31 = V_2;
		if ((((int32_t)L_30) >= ((int32_t)L_31)))
		{
			goto IL_0093;
		}
	}
	{
		String_t* L_32 = ___1_secondList;
		int32_t L_33 = V_6;
		NullCheck(L_32);
		Il2CppChar L_34;
		L_34 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_32, L_33, NULL);
		Il2CppChar L_35 = ___2_separator;
		if ((!(((uint32_t)L_34) == ((uint32_t)L_35))))
		{
			goto IL_007d;
		}
	}

IL_0093:
	{
		// var lengthOfCurrentInSecond = endIndexInSecond - indexInSecond;
		int32_t L_36 = V_6;
		int32_t L_37 = V_5;
		V_7 = ((int32_t)il2cpp_codegen_subtract(L_36, L_37));
		// if (lengthOfCurrentInFirst == lengthOfCurrentInSecond)
		int32_t L_38 = V_4;
		int32_t L_39 = V_7;
		if ((!(((uint32_t)L_38) == ((uint32_t)L_39))))
		{
			goto IL_00ec;
		}
	}
	{
		// var startIndexInFirst = indexInFirst;
		int32_t L_40 = V_0;
		V_8 = L_40;
		// var startIndexInSecond = indexInSecond;
		int32_t L_41 = V_5;
		V_9 = L_41;
		// var isMatch = true;
		V_10 = (bool)1;
		// for (var i = 0; i < lengthOfCurrentInFirst; ++i)
		V_11 = 0;
		goto IL_00e0;
	}

IL_00af:
	{
		// var first = firstList[startIndexInFirst + i];
		String_t* L_42 = ___0_firstList;
		int32_t L_43 = V_8;
		int32_t L_44 = V_11;
		NullCheck(L_42);
		Il2CppChar L_45;
		L_45 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_42, ((int32_t)il2cpp_codegen_add(L_43, L_44)), NULL);
		// var second = secondList[startIndexInSecond + i];
		String_t* L_46 = ___1_secondList;
		int32_t L_47 = V_9;
		int32_t L_48 = V_11;
		NullCheck(L_46);
		Il2CppChar L_49;
		L_49 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_46, ((int32_t)il2cpp_codegen_add(L_47, L_48)), NULL);
		V_12 = L_49;
		// if (char.ToLowerInvariant(first) != char.ToLowerInvariant(second))
		il2cpp_codegen_runtime_class_init_inline(Char_t521A6F19B456D956AF452D926C32709DC03D6B17_il2cpp_TypeInfo_var);
		Il2CppChar L_50;
		L_50 = Char_ToLowerInvariant_m983C1CD07015E41B97D71F466B4B686F1145E60D(L_45, NULL);
		Il2CppChar L_51 = V_12;
		Il2CppChar L_52;
		L_52 = Char_ToLowerInvariant_m983C1CD07015E41B97D71F466B4B686F1145E60D(L_51, NULL);
		if ((((int32_t)L_50) == ((int32_t)L_52)))
		{
			goto IL_00da;
		}
	}
	{
		// isMatch = false;
		V_10 = (bool)0;
		// break;
		goto IL_00e6;
	}

IL_00da:
	{
		// for (var i = 0; i < lengthOfCurrentInFirst; ++i)
		int32_t L_53 = V_11;
		V_11 = ((int32_t)il2cpp_codegen_add(L_53, 1));
	}

IL_00e0:
	{
		// for (var i = 0; i < lengthOfCurrentInFirst; ++i)
		int32_t L_54 = V_11;
		int32_t L_55 = V_4;
		if ((((int32_t)L_54) < ((int32_t)L_55)))
		{
			goto IL_00af;
		}
	}

IL_00e6:
	{
		// if (isMatch)
		bool L_56 = V_10;
		if (!L_56)
		{
			goto IL_00ec;
		}
	}
	{
		// return true;
		return (bool)1;
	}

IL_00ec:
	{
		// indexInSecond = endIndexInSecond + 1;
		int32_t L_57 = V_6;
		V_5 = ((int32_t)il2cpp_codegen_add(L_57, 1));
	}

IL_00f2:
	{
		// while (indexInSecond < lengthOfSecond)
		int32_t L_58 = V_5;
		int32_t L_59 = V_2;
		if ((((int32_t)L_58) < ((int32_t)L_59)))
		{
			goto IL_0064;
		}
	}
	{
		// indexInFirst = endIndexInFirst + 1;
		int32_t L_60 = V_3;
		V_0 = ((int32_t)il2cpp_codegen_add(L_60, 1));
	}

IL_00fe:
	{
		// while (indexInFirst < lengthOfFirst)
		int32_t L_61 = V_0;
		int32_t L_62 = V_1;
		if ((((int32_t)L_61) < ((int32_t)L_62)))
		{
			goto IL_0031;
		}
	}
	{
		// return false;
		return (bool)0;
	}
}
// System.Int32 UnityEngine.InputSystem.Utilities.StringHelpers::ParseInt(System.String,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t StringHelpers_ParseInt_m600E65559911341994B31B343474D76F111A67DF (String_t* ___0_str, int32_t ___1_pos, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	{
		// var multiply = 1;
		V_0 = 1;
		// var result = 0;
		V_1 = 0;
		// var length = str.Length;
		String_t* L_0 = ___0_str;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_0, NULL);
		V_2 = L_1;
		goto IL_0031;
	}

IL_000d:
	{
		// var ch = str[pos];
		String_t* L_2 = ___0_str;
		int32_t L_3 = ___1_pos;
		NullCheck(L_2);
		Il2CppChar L_4;
		L_4 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_2, L_3, NULL);
		// var digit = ch - '0';
		V_3 = ((int32_t)il2cpp_codegen_subtract((int32_t)L_4, ((int32_t)48)));
		// if (digit < 0 || digit > 9)
		int32_t L_5 = V_3;
		if ((((int32_t)L_5) < ((int32_t)0)))
		{
			goto IL_0035;
		}
	}
	{
		int32_t L_6 = V_3;
		if ((((int32_t)L_6) > ((int32_t)((int32_t)9))))
		{
			goto IL_0035;
		}
	}
	{
		// result = result * multiply + digit;
		int32_t L_7 = V_1;
		int32_t L_8 = V_0;
		int32_t L_9 = V_3;
		V_1 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(L_7, L_8)), L_9));
		// multiply *= 10;
		int32_t L_10 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_multiply(L_10, ((int32_t)10)));
		// ++pos;
		int32_t L_11 = ___1_pos;
		___1_pos = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_0031:
	{
		// while (pos < length)
		int32_t L_12 = ___1_pos;
		int32_t L_13 = V_2;
		if ((((int32_t)L_12) < ((int32_t)L_13)))
		{
			goto IL_000d;
		}
	}

IL_0035:
	{
		// return result;
		int32_t L_14 = V_1;
		return L_14;
	}
}
// System.Boolean UnityEngine.InputSystem.Utilities.StringHelpers::WriteStringToBuffer(System.String,System.IntPtr,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool StringHelpers_WriteStringToBuffer_m3224AFFDC9D2D04E9112B8812CDEEC6FE363D66F (String_t* ___0_text, intptr_t ___1_buffer, int32_t ___2_bufferSizeInCharacters, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	{
		// uint offset = 0;
		V_0 = 0;
		// return WriteStringToBuffer(text, buffer, bufferSizeInCharacters, ref offset);
		String_t* L_0 = ___0_text;
		intptr_t L_1 = ___1_buffer;
		int32_t L_2 = ___2_bufferSizeInCharacters;
		bool L_3;
		L_3 = StringHelpers_WriteStringToBuffer_m0719C102DC096F1A565020ED8D1B71BC6B26B8DF(L_0, L_1, L_2, (&V_0), NULL);
		return L_3;
	}
}
// System.Boolean UnityEngine.InputSystem.Utilities.StringHelpers::WriteStringToBuffer(System.String,System.IntPtr,System.Int32,System.UInt32&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool StringHelpers_WriteStringToBuffer_m0719C102DC096F1A565020ED8D1B71BC6B26B8DF (String_t* ___0_text, intptr_t ___1_buffer, int32_t ___2_bufferSizeInCharacters, uint32_t* ___3_offset, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int64_t V_1 = 0;
	uint8_t* V_2 = NULL;
	int32_t V_3 = 0;
	int32_t G_B5_0 = 0;
	{
		// if (buffer == IntPtr.Zero)
		intptr_t L_0 = ___1_buffer;
		intptr_t L_1 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		bool L_2;
		L_2 = IntPtr_op_Equality_m7D9CDCDE9DC2A0C2C614633F4921E90187FAB271(L_0, L_1, NULL);
		if (!L_2)
		{
			goto IL_0018;
		}
	}
	{
		// throw new ArgumentNullException("buffer");
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_3 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		NullCheck(L_3);
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC263EA29ADF3548CFEBC57B532EED28451A56C10)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&StringHelpers_WriteStringToBuffer_m0719C102DC096F1A565020ED8D1B71BC6B26B8DF_RuntimeMethod_var)));
	}

IL_0018:
	{
		// var length = string.IsNullOrEmpty(text) ? 0 : text.Length;
		String_t* L_4 = ___0_text;
		bool L_5;
		L_5 = String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478(L_4, NULL);
		if (L_5)
		{
			goto IL_0028;
		}
	}
	{
		String_t* L_6 = ___0_text;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_6, NULL);
		G_B5_0 = L_7;
		goto IL_0029;
	}

IL_0028:
	{
		G_B5_0 = 0;
	}

IL_0029:
	{
		V_0 = G_B5_0;
		// if (length > ushort.MaxValue)
		int32_t L_8 = V_0;
		if ((((int32_t)L_8) <= ((int32_t)((int32_t)65535))))
		{
			goto IL_0051;
		}
	}
	{
		// throw new ArgumentException(string.Format("String exceeds max size of {0} characters", ushort.MaxValue), "text");
		uint16_t L_9 = ((uint16_t)((int32_t)65535));
		RuntimeObject* L_10 = Box(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var)), &L_9);
		String_t* L_11;
		L_11 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral5AEDE79F00BF8508555B948D1DE12F274399430A)), L_10, NULL);
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_12 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		NullCheck(L_12);
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_12, L_11, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralBFCC6EE94F1B7AA05A04750903E25F93A7188AE0)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_12, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&StringHelpers_WriteStringToBuffer_m0719C102DC096F1A565020ED8D1B71BC6B26B8DF_RuntimeMethod_var)));
	}

IL_0051:
	{
		// var endOffset = offset + sizeof(char) * length + sizeof(int);
		uint32_t* L_13 = ___3_offset;
		int32_t L_14 = *((uint32_t*)L_13);
		int32_t L_15 = V_0;
		V_1 = ((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(((int64_t)(uint64_t)((uint32_t)L_14)), ((int64_t)((int32_t)il2cpp_codegen_multiply(2, L_15))))), ((int64_t)4)));
		// if (endOffset > bufferSizeInCharacters)
		int64_t L_16 = V_1;
		int32_t L_17 = ___2_bufferSizeInCharacters;
		if ((((int64_t)L_16) <= ((int64_t)((int64_t)L_17))))
		{
			goto IL_0064;
		}
	}
	{
		// return false;
		return (bool)0;
	}

IL_0064:
	{
		// var ptr = ((byte*)buffer) + offset;
		intptr_t L_18 = ___1_buffer;
		void* L_19;
		L_19 = IntPtr_op_Explicit_m2728CBA081E79B97DDCF1D4FAD77B309CA1E94BF(L_18, NULL);
		uint32_t* L_20 = ___3_offset;
		int32_t L_21 = *((uint32_t*)L_20);
		V_2 = (uint8_t*)((void*)il2cpp_codegen_add((intptr_t)L_19, (intptr_t)((uintptr_t)L_21)));
		// *((ushort*)ptr) = (ushort)length;
		uint8_t* L_22 = V_2;
		int32_t L_23 = V_0;
		*((int16_t*)L_22) = (int16_t)((int32_t)(uint16_t)L_23);
		// ptr += sizeof(ushort);
		uint8_t* L_24 = V_2;
		V_2 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_24, 2));
		// for (var i = 0; i < length; ++i, ptr += sizeof(char))
		V_3 = 0;
		goto IL_008c;
	}

IL_007b:
	{
		// *((char*)ptr) = text[i];
		uint8_t* L_25 = V_2;
		String_t* L_26 = ___0_text;
		int32_t L_27 = V_3;
		NullCheck(L_26);
		Il2CppChar L_28;
		L_28 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_26, L_27, NULL);
		*((int16_t*)L_25) = (int16_t)L_28;
		// for (var i = 0; i < length; ++i, ptr += sizeof(char))
		int32_t L_29 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_29, 1));
		// for (var i = 0; i < length; ++i, ptr += sizeof(char))
		uint8_t* L_30 = V_2;
		V_2 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_30, 2));
	}

IL_008c:
	{
		// for (var i = 0; i < length; ++i, ptr += sizeof(char))
		int32_t L_31 = V_3;
		int32_t L_32 = V_0;
		if ((((int32_t)L_31) < ((int32_t)L_32)))
		{
			goto IL_007b;
		}
	}
	{
		// offset = (uint)endOffset;
		uint32_t* L_33 = ___3_offset;
		int64_t L_34 = V_1;
		*((int32_t*)L_33) = (int32_t)((int32_t)(uint32_t)L_34);
		// return true;
		return (bool)1;
	}
}
// System.String UnityEngine.InputSystem.Utilities.StringHelpers::ReadStringFromBuffer(System.IntPtr,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* StringHelpers_ReadStringFromBuffer_m2D73BEC46047561991586041C6195B9CC776DA0D (intptr_t ___0_buffer, int32_t ___1_bufferSize, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	{
		// uint offset = 0;
		V_0 = 0;
		// return ReadStringFromBuffer(buffer, bufferSize, ref offset);
		intptr_t L_0 = ___0_buffer;
		int32_t L_1 = ___1_bufferSize;
		String_t* L_2;
		L_2 = StringHelpers_ReadStringFromBuffer_m08BAA47EF90D3F3A74A8AA354871C18FA7D9B8D2(L_0, L_1, (&V_0), NULL);
		return L_2;
	}
}
// System.String UnityEngine.InputSystem.Utilities.StringHelpers::ReadStringFromBuffer(System.IntPtr,System.Int32,System.UInt32&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* StringHelpers_ReadStringFromBuffer_m08BAA47EF90D3F3A74A8AA354871C18FA7D9B8D2 (intptr_t ___0_buffer, int32_t ___1_bufferSize, uint32_t* ___2_offset, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	uint8_t* V_0 = NULL;
	uint16_t V_1 = 0;
	int64_t V_2 = 0;
	{
		// if (buffer == IntPtr.Zero)
		intptr_t L_0 = ___0_buffer;
		intptr_t L_1 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		bool L_2;
		L_2 = IntPtr_op_Equality_m7D9CDCDE9DC2A0C2C614633F4921E90187FAB271(L_0, L_1, NULL);
		if (!L_2)
		{
			goto IL_0018;
		}
	}
	{
		// throw new ArgumentNullException(nameof(buffer));
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_3 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		NullCheck(L_3);
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC263EA29ADF3548CFEBC57B532EED28451A56C10)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&StringHelpers_ReadStringFromBuffer_m08BAA47EF90D3F3A74A8AA354871C18FA7D9B8D2_RuntimeMethod_var)));
	}

IL_0018:
	{
		// if (offset + sizeof(int) > bufferSize)
		uint32_t* L_4 = ___2_offset;
		int32_t L_5 = *((uint32_t*)L_4);
		int32_t L_6 = ___1_bufferSize;
		if ((((int64_t)((int64_t)(uint64_t)((uint32_t)((int32_t)il2cpp_codegen_add(L_5, 4))))) <= ((int64_t)((int64_t)L_6))))
		{
			goto IL_0023;
		}
	}
	{
		// return null;
		return (String_t*)NULL;
	}

IL_0023:
	{
		// var ptr = ((byte*)buffer) + offset;
		intptr_t L_7 = ___0_buffer;
		void* L_8;
		L_8 = IntPtr_op_Explicit_m2728CBA081E79B97DDCF1D4FAD77B309CA1E94BF(L_7, NULL);
		uint32_t* L_9 = ___2_offset;
		int32_t L_10 = *((uint32_t*)L_9);
		V_0 = (uint8_t*)((void*)il2cpp_codegen_add((intptr_t)L_8, (intptr_t)((uintptr_t)L_10)));
		// var length = *((ushort*)ptr);
		uint8_t* L_11 = V_0;
		int32_t L_12 = *((uint16_t*)L_11);
		V_1 = (uint16_t)L_12;
		// ptr += sizeof(ushort);
		uint8_t* L_13 = V_0;
		V_0 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_13, 2));
		// if (length == 0)
		uint16_t L_14 = V_1;
		if (L_14)
		{
			goto IL_003a;
		}
	}
	{
		// return null;
		return (String_t*)NULL;
	}

IL_003a:
	{
		// var endOffset = offset + sizeof(char) * length + sizeof(int);
		uint32_t* L_15 = ___2_offset;
		int32_t L_16 = *((uint32_t*)L_15);
		uint16_t L_17 = V_1;
		V_2 = ((int64_t)il2cpp_codegen_add(((int64_t)il2cpp_codegen_add(((int64_t)(uint64_t)((uint32_t)L_16)), ((int64_t)((int32_t)il2cpp_codegen_multiply(2, (int32_t)L_17))))), ((int64_t)4)));
		// if (endOffset > bufferSize)
		int64_t L_18 = V_2;
		int32_t L_19 = ___1_bufferSize;
		if ((((int64_t)L_18) <= ((int64_t)((int64_t)L_19))))
		{
			goto IL_004d;
		}
	}
	{
		// return null;
		return (String_t*)NULL;
	}

IL_004d:
	{
		// var text = Marshal.PtrToStringUni(new IntPtr(ptr), length);
		uint8_t* L_20 = V_0;
		intptr_t L_21;
		memset((&L_21), 0, sizeof(L_21));
		IntPtr__ctor_m4F9A9B80F01996B610D5AE4797F20B98ECD0A3D9_inline((&L_21), (void*)L_20, /*hidden argument*/NULL);
		uint16_t L_22 = V_1;
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		String_t* L_23;
		L_23 = Marshal_PtrToStringUni_mF3D662C7F7255D6DDA07416FA6520886F66D0070(L_21, L_22, NULL);
		// offset = (uint)endOffset;
		uint32_t* L_24 = ___2_offset;
		int64_t L_25 = V_2;
		*((int32_t*)L_24) = (int32_t)((int32_t)(uint32_t)L_25);
		// return text;
		return L_23;
	}
}
// System.Boolean UnityEngine.InputSystem.Utilities.StringHelpers::IsPrintable(System.Char)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool StringHelpers_IsPrintable_m3FC3310E35B07361A9CAA2FB45FFE42137E64151 (Il2CppChar ___0_ch, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// return !char.IsControl(ch) && !char.IsWhiteSpace(ch);
		Il2CppChar L_0 = ___0_ch;
		il2cpp_codegen_runtime_class_init_inline(Char_t521A6F19B456D956AF452D926C32709DC03D6B17_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Char_IsControl_m133C10360BE82B7580E4D3ECE3C881A6C82B3F7F(L_0, NULL);
		if (L_1)
		{
			goto IL_0012;
		}
	}
	{
		Il2CppChar L_2 = ___0_ch;
		il2cpp_codegen_runtime_class_init_inline(Char_t521A6F19B456D956AF452D926C32709DC03D6B17_il2cpp_TypeInfo_var);
		bool L_3;
		L_3 = Char_IsWhiteSpace_m02AEC6EA19513CAFC6882CFCA54C45794D2B5924(L_2, NULL);
		return (bool)((((int32_t)L_3) == ((int32_t)0))? 1 : 0);
	}

IL_0012:
	{
		return (bool)0;
	}
}
// System.String UnityEngine.InputSystem.Utilities.StringHelpers::WithAllWhitespaceStripped(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* StringHelpers_WithAllWhitespaceStripped_m4247E8F61C69ED5DAA964724249797874195B7DD (String_t* ___0_str, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	StringBuilder_t* V_0 = NULL;
	String_t* V_1 = NULL;
	int32_t V_2 = 0;
	Il2CppChar V_3 = 0x0;
	{
		// var buffer = new StringBuilder();
		StringBuilder_t* L_0 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D(L_0, NULL);
		V_0 = L_0;
		// foreach (var ch in str)
		String_t* L_1 = ___0_str;
		V_1 = L_1;
		V_2 = 0;
		goto IL_0028;
	}

IL_000c:
	{
		// foreach (var ch in str)
		String_t* L_2 = V_1;
		int32_t L_3 = V_2;
		NullCheck(L_2);
		Il2CppChar L_4;
		L_4 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_2, L_3, NULL);
		V_3 = L_4;
		// if (!char.IsWhiteSpace(ch))
		Il2CppChar L_5 = V_3;
		il2cpp_codegen_runtime_class_init_inline(Char_t521A6F19B456D956AF452D926C32709DC03D6B17_il2cpp_TypeInfo_var);
		bool L_6;
		L_6 = Char_IsWhiteSpace_m02AEC6EA19513CAFC6882CFCA54C45794D2B5924(L_5, NULL);
		if (L_6)
		{
			goto IL_0024;
		}
	}
	{
		// buffer.Append(ch);
		StringBuilder_t* L_7 = V_0;
		Il2CppChar L_8 = V_3;
		NullCheck(L_7);
		StringBuilder_t* L_9;
		L_9 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_7, L_8, NULL);
	}

IL_0024:
	{
		int32_t L_10 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_10, 1));
	}

IL_0028:
	{
		// foreach (var ch in str)
		int32_t L_11 = V_2;
		String_t* L_12 = V_1;
		NullCheck(L_12);
		int32_t L_13;
		L_13 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_12, NULL);
		if ((((int32_t)L_11) < ((int32_t)L_13)))
		{
			goto IL_000c;
		}
	}
	{
		// return buffer.ToString();
		StringBuilder_t* L_14 = V_0;
		NullCheck(L_14);
		String_t* L_15;
		L_15 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_14);
		return L_15;
	}
}
// System.Boolean UnityEngine.InputSystem.Utilities.StringHelpers::InvariantEqualsIgnoreCase(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool StringHelpers_InvariantEqualsIgnoreCase_m7067DACDAAA29F69B419B89171E6FCF5366ACB44 (String_t* ___0_left, String_t* ___1_right, const RuntimeMethod* method) 
{
	{
		// if (string.IsNullOrEmpty(left))
		String_t* L_0 = ___0_left;
		bool L_1;
		L_1 = String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478(L_0, NULL);
		if (!L_1)
		{
			goto IL_000f;
		}
	}
	{
		// return string.IsNullOrEmpty(right);
		String_t* L_2 = ___1_right;
		bool L_3;
		L_3 = String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478(L_2, NULL);
		return L_3;
	}

IL_000f:
	{
		// return string.Equals(left, right, StringComparison.InvariantCultureIgnoreCase);
		String_t* L_4 = ___0_left;
		String_t* L_5 = ___1_right;
		bool L_6;
		L_6 = String_Equals_mCC34895D0DB2AD440C9D8767032215BC86B5C48B(L_4, L_5, 3, NULL);
		return L_6;
	}
}
// System.String UnityEngine.InputSystem.Utilities.StringHelpers::ExpandTemplateString(System.String,System.Func`2<System.String,System.String>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* StringHelpers_ExpandTemplateString_mA00BD22DF8D3C21CF5DB7420C5BAB9935B5EF86B (String_t* ___0_template, Func_2_t85D1F7C2022B349817C22FC72C474CD33FFABE93* ___1_mapFunc, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	StringBuilder_t* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	Il2CppChar V_3 = 0x0;
	int32_t V_4 = 0;
	String_t* V_5 = NULL;
	String_t* V_6 = NULL;
	{
		// if (string.IsNullOrEmpty(template))
		String_t* L_0 = ___0_template;
		bool L_1;
		L_1 = String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478(L_0, NULL);
		if (!L_1)
		{
			goto IL_0013;
		}
	}
	{
		// throw new ArgumentNullException(nameof(template));
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_2 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		NullCheck(L_2);
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralFE3CDBE9D3C244138D4F64C1BEB914490F7E7BBD)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&StringHelpers_ExpandTemplateString_mA00BD22DF8D3C21CF5DB7420C5BAB9935B5EF86B_RuntimeMethod_var)));
	}

IL_0013:
	{
		// if (mapFunc == null)
		Func_2_t85D1F7C2022B349817C22FC72C474CD33FFABE93* L_3 = ___1_mapFunc;
		if (L_3)
		{
			goto IL_0021;
		}
	}
	{
		// throw new ArgumentNullException(nameof(mapFunc));
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_4 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		NullCheck(L_4);
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC3002A2B85A3B7DFD395054441915FBAB742D4EE)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&StringHelpers_ExpandTemplateString_mA00BD22DF8D3C21CF5DB7420C5BAB9935B5EF86B_RuntimeMethod_var)));
	}

IL_0021:
	{
		// var buffer = new StringBuilder();
		StringBuilder_t* L_5 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		NullCheck(L_5);
		StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D(L_5, NULL);
		V_0 = L_5;
		// var length = template.Length;
		String_t* L_6 = ___0_template;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_6, NULL);
		V_1 = L_7;
		// for (var i = 0; i < length; ++i)
		V_2 = 0;
		goto IL_008a;
	}

IL_0032:
	{
		// var ch = template[i];
		String_t* L_8 = ___0_template;
		int32_t L_9 = V_2;
		NullCheck(L_8);
		Il2CppChar L_10;
		L_10 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_8, L_9, NULL);
		V_3 = L_10;
		// if (ch != '{')
		Il2CppChar L_11 = V_3;
		if ((((int32_t)L_11) == ((int32_t)((int32_t)123))))
		{
			goto IL_0049;
		}
	}
	{
		// buffer.Append(ch);
		StringBuilder_t* L_12 = V_0;
		Il2CppChar L_13 = V_3;
		NullCheck(L_12);
		StringBuilder_t* L_14;
		L_14 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_12, L_13, NULL);
		// continue;
		goto IL_0086;
	}

IL_0049:
	{
		// ++i;
		int32_t L_15 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_15, 1));
		// var tokenStartPos = i;
		int32_t L_16 = V_2;
		V_4 = L_16;
		goto IL_0056;
	}

IL_0052:
	{
		// ++i;
		int32_t L_17 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_0056:
	{
		// while (i < length && template[i] != '}')
		int32_t L_18 = V_2;
		int32_t L_19 = V_1;
		if ((((int32_t)L_18) >= ((int32_t)L_19)))
		{
			goto IL_0065;
		}
	}
	{
		String_t* L_20 = ___0_template;
		int32_t L_21 = V_2;
		NullCheck(L_20);
		Il2CppChar L_22;
		L_22 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_20, L_21, NULL);
		if ((!(((uint32_t)L_22) == ((uint32_t)((int32_t)125)))))
		{
			goto IL_0052;
		}
	}

IL_0065:
	{
		// var token = template.Substring(tokenStartPos, i - tokenStartPos);
		String_t* L_23 = ___0_template;
		int32_t L_24 = V_4;
		int32_t L_25 = V_2;
		int32_t L_26 = V_4;
		NullCheck(L_23);
		String_t* L_27;
		L_27 = String_Substring_mB1D94F47935D22E130FF2C01DBB6A4135FBB76CE(L_23, L_24, ((int32_t)il2cpp_codegen_subtract(L_25, L_26)), NULL);
		V_5 = L_27;
		// var mapped = mapFunc(token);
		Func_2_t85D1F7C2022B349817C22FC72C474CD33FFABE93* L_28 = ___1_mapFunc;
		String_t* L_29 = V_5;
		NullCheck(L_28);
		String_t* L_30;
		L_30 = Func_2_Invoke_mED071D4A847678204A843F11D77F10D168FE4D2D_inline(L_28, L_29, NULL);
		V_6 = L_30;
		// buffer.Append(mapped);
		StringBuilder_t* L_31 = V_0;
		String_t* L_32 = V_6;
		NullCheck(L_31);
		StringBuilder_t* L_33;
		L_33 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_31, L_32, NULL);
	}

IL_0086:
	{
		// for (var i = 0; i < length; ++i)
		int32_t L_34 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_008a:
	{
		// for (var i = 0; i < length; ++i)
		int32_t L_35 = V_2;
		int32_t L_36 = V_1;
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_0032;
		}
	}
	{
		// return buffer.ToString();
		StringBuilder_t* L_37 = V_0;
		NullCheck(L_37);
		String_t* L_38;
		L_38 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_37);
		return L_38;
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
// System.Void UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CSplitU3Ed__9__ctor_m531A6132094F2E8117F46518BCD07DBECF2F8B60 (U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_U3CU3E1__state;
		__this->___U3CU3E1__state_0 = L_0;
		int32_t L_1;
		L_1 = Environment_get_CurrentManagedThreadId_m66483AADCCC13272EBDCD94D31D2E52603C24BDF(NULL);
		__this->___U3CU3El__initialThreadId_2 = L_1;
		return;
	}
}
// System.Void UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9::System.IDisposable.Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CSplitU3Ed__9_System_IDisposable_Dispose_mD41FA09A8BBBCF5510D180FB611029B2F2B1845D (U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF* __this, const RuntimeMethod* method) 
{
	{
		return;
	}
}
// System.Boolean UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9::MoveNext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool U3CSplitU3Ed__9_MoveNext_m080213910073BC24DF99D9BCFF90A286A185D10E (U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	Il2CppChar V_1 = 0x0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	{
		int32_t L_0 = __this->___U3CU3E1__state_0;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if (!L_1)
		{
			goto IL_0013;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_00fd;
		}
	}
	{
		return (bool)0;
	}

IL_0013:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// if (string.IsNullOrEmpty(str))
		String_t* L_3 = __this->___str_3;
		bool L_4;
		L_4 = String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478(L_3, NULL);
		if (!L_4)
		{
			goto IL_0029;
		}
	}
	{
		// yield break;
		return (bool)0;
	}

IL_0029:
	{
		// var length = str.Length;
		String_t* L_5 = __this->___str_3;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_5, NULL);
		__this->___U3ClengthU3E5__2_7 = L_6;
		// var position = 0;
		__this->___U3CpositionU3E5__3_8 = 0;
		goto IL_0104;
	}

IL_0046:
	{
		// var ch = str[position];
		String_t* L_7 = __this->___str_3;
		int32_t L_8 = __this->___U3CpositionU3E5__3_8;
		NullCheck(L_7);
		Il2CppChar L_9;
		L_9 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_7, L_8, NULL);
		V_1 = L_9;
		// if (predicate(ch))
		Func_2_tF409A653B8F770E0A30CD80D21764FB1DDB2A28F* L_10 = __this->___predicate_5;
		Il2CppChar L_11 = V_1;
		NullCheck(L_10);
		bool L_12;
		L_12 = Func_2_Invoke_m4733F0A0FE136C9F8DCE4963455215585E8BE2CD_inline(L_10, L_11, NULL);
		if (!L_12)
		{
			goto IL_007d;
		}
	}
	{
		// ++position;
		int32_t L_13 = __this->___U3CpositionU3E5__3_8;
		V_4 = ((int32_t)il2cpp_codegen_add(L_13, 1));
		int32_t L_14 = V_4;
		__this->___U3CpositionU3E5__3_8 = L_14;
		// continue;
		goto IL_0104;
	}

IL_007d:
	{
		// var startPosition = position;
		int32_t L_15 = __this->___U3CpositionU3E5__3_8;
		V_2 = L_15;
		// ++position;
		int32_t L_16 = __this->___U3CpositionU3E5__3_8;
		V_4 = ((int32_t)il2cpp_codegen_add(L_16, 1));
		int32_t L_17 = V_4;
		__this->___U3CpositionU3E5__3_8 = L_17;
		goto IL_00ca;
	}

IL_0098:
	{
		// ch = str[position];
		String_t* L_18 = __this->___str_3;
		int32_t L_19 = __this->___U3CpositionU3E5__3_8;
		NullCheck(L_18);
		Il2CppChar L_20;
		L_20 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_18, L_19, NULL);
		V_1 = L_20;
		// if (predicate(ch))
		Func_2_tF409A653B8F770E0A30CD80D21764FB1DDB2A28F* L_21 = __this->___predicate_5;
		Il2CppChar L_22 = V_1;
		NullCheck(L_21);
		bool L_23;
		L_23 = Func_2_Invoke_m4733F0A0FE136C9F8DCE4963455215585E8BE2CD_inline(L_21, L_22, NULL);
		if (L_23)
		{
			goto IL_00d8;
		}
	}
	{
		// ++position;
		int32_t L_24 = __this->___U3CpositionU3E5__3_8;
		V_4 = ((int32_t)il2cpp_codegen_add(L_24, 1));
		int32_t L_25 = V_4;
		__this->___U3CpositionU3E5__3_8 = L_25;
	}

IL_00ca:
	{
		// while (position < length)
		int32_t L_26 = __this->___U3CpositionU3E5__3_8;
		int32_t L_27 = __this->___U3ClengthU3E5__2_7;
		if ((((int32_t)L_26) < ((int32_t)L_27)))
		{
			goto IL_0098;
		}
	}

IL_00d8:
	{
		// var endPosition = position;
		int32_t L_28 = __this->___U3CpositionU3E5__3_8;
		V_3 = L_28;
		// yield return str.Substring(startPosition, endPosition - startPosition);
		String_t* L_29 = __this->___str_3;
		int32_t L_30 = V_2;
		int32_t L_31 = V_3;
		int32_t L_32 = V_2;
		NullCheck(L_29);
		String_t* L_33;
		L_33 = String_Substring_mB1D94F47935D22E130FF2C01DBB6A4135FBB76CE(L_29, L_30, ((int32_t)il2cpp_codegen_subtract(L_31, L_32)), NULL);
		__this->___U3CU3E2__current_1 = L_33;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CU3E2__current_1), (void*)L_33);
		__this->___U3CU3E1__state_0 = 1;
		return (bool)1;
	}

IL_00fd:
	{
		__this->___U3CU3E1__state_0 = (-1);
	}

IL_0104:
	{
		// while (position < length)
		int32_t L_34 = __this->___U3CpositionU3E5__3_8;
		int32_t L_35 = __this->___U3ClengthU3E5__2_7;
		if ((((int32_t)L_34) < ((int32_t)L_35)))
		{
			goto IL_0046;
		}
	}
	{
		// }
		return (bool)0;
	}
}
// System.String UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9::System.Collections.Generic.IEnumerator<System.String>.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* U3CSplitU3Ed__9_System_Collections_Generic_IEnumeratorU3CSystem_StringU3E_get_Current_m76EA356A2DA07E9AD1E26E750F598F7C620D7C2B (U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF* __this, const RuntimeMethod* method) 
{
	{
		String_t* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
// System.Void UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9::System.Collections.IEnumerator.Reset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CSplitU3Ed__9_System_Collections_IEnumerator_Reset_mB5816591871F45CED738B000C124AECD6783056C (U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NullCheck(L_0);
		NotSupportedException__ctor_m1398D0CDE19B36AA3DE9392879738C1EA2439CDF(L_0, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&U3CSplitU3Ed__9_System_Collections_IEnumerator_Reset_mB5816591871F45CED738B000C124AECD6783056C_RuntimeMethod_var)));
	}
}
// System.Object UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9::System.Collections.IEnumerator.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CSplitU3Ed__9_System_Collections_IEnumerator_get_Current_mF10D40E241033C8369ABF610410ABFF9F1BD4348 (U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF* __this, const RuntimeMethod* method) 
{
	{
		String_t* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
// System.Collections.Generic.IEnumerator`1<System.String> UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9::System.Collections.Generic.IEnumerable<System.String>.GetEnumerator()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CSplitU3Ed__9_System_Collections_Generic_IEnumerableU3CSystem_StringU3E_GetEnumerator_m60A98974B57E1F33794FE9CC8A472C3E52C09511 (U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF* V_0 = NULL;
	{
		int32_t L_0 = __this->___U3CU3E1__state_0;
		if ((!(((uint32_t)L_0) == ((uint32_t)((int32_t)-2)))))
		{
			goto IL_0022;
		}
	}
	{
		int32_t L_1 = __this->___U3CU3El__initialThreadId_2;
		int32_t L_2;
		L_2 = Environment_get_CurrentManagedThreadId_m66483AADCCC13272EBDCD94D31D2E52603C24BDF(NULL);
		if ((!(((uint32_t)L_1) == ((uint32_t)L_2))))
		{
			goto IL_0022;
		}
	}
	{
		__this->___U3CU3E1__state_0 = 0;
		V_0 = __this;
		goto IL_0029;
	}

IL_0022:
	{
		U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF* L_3 = (U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF*)il2cpp_codegen_object_new(U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		U3CSplitU3Ed__9__ctor_m531A6132094F2E8117F46518BCD07DBECF2F8B60(L_3, 0, NULL);
		V_0 = L_3;
	}

IL_0029:
	{
		U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF* L_4 = V_0;
		String_t* L_5 = __this->___U3CU3E3__str_4;
		NullCheck(L_4);
		L_4->___str_3 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&L_4->___str_3), (void*)L_5);
		U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF* L_6 = V_0;
		Func_2_tF409A653B8F770E0A30CD80D21764FB1DDB2A28F* L_7 = __this->___U3CU3E3__predicate_6;
		NullCheck(L_6);
		L_6->___predicate_5 = L_7;
		Il2CppCodeGenWriteBarrier((void**)(&L_6->___predicate_5), (void*)L_7);
		U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF* L_8 = V_0;
		return L_8;
	}
}
// System.Collections.IEnumerator UnityEngine.InputSystem.Utilities.StringHelpers/<Split>d__9::System.Collections.IEnumerable.GetEnumerator()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CSplitU3Ed__9_System_Collections_IEnumerable_GetEnumerator_mE009151D16A2FC0F1C4D01A3E91691D39A840643 (U3CSplitU3Ed__9_tDF7D6AF6AAF8F188C3A8AC7B3CFA6B382F6D8CDF* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0;
		L_0 = U3CSplitU3Ed__9_System_Collections_Generic_IEnumerableU3CSystem_StringU3E_GetEnumerator_m60A98974B57E1F33794FE9CC8A472C3E52C09511(__this, NULL);
		return L_0;
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
// System.Void UnityEngine.InputSystem.Utilities.StringHelpers/<Tokenize>d__8::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CTokenizeU3Ed__8__ctor_mFCB5DCEF9B0F44B630C8C831ADC12246A0CA2785 (U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_U3CU3E1__state;
		__this->___U3CU3E1__state_0 = L_0;
		int32_t L_1;
		L_1 = Environment_get_CurrentManagedThreadId_m66483AADCCC13272EBDCD94D31D2E52603C24BDF(NULL);
		__this->___U3CU3El__initialThreadId_2 = L_1;
		return;
	}
}
// System.Void UnityEngine.InputSystem.Utilities.StringHelpers/<Tokenize>d__8::System.IDisposable.Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CTokenizeU3Ed__8_System_IDisposable_Dispose_m121A2EBBDA3BE988C3F3B3A39F31F3E8A959FAD2 (U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B* __this, const RuntimeMethod* method) 
{
	{
		return;
	}
}
// System.Boolean UnityEngine.InputSystem.Utilities.StringHelpers/<Tokenize>d__8::MoveNext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool U3CTokenizeU3Ed__8_MoveNext_m8796806F9FDE0FE1825ACD68AE7E705F27DDAF3E (U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		int32_t L_0 = __this->___U3CU3E1__state_0;
		V_0 = L_0;
		int32_t L_1 = V_0;
		switch (L_1)
		{
			case 0:
			{
				goto IL_001b;
			}
			case 1:
			{
				goto IL_0111;
			}
			case 2:
			{
				goto IL_0185;
			}
		}
	}
	{
		return (bool)0;
	}

IL_001b:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// var pos = 0;
		V_1 = 0;
		// var length = str.Length;
		String_t* L_2 = __this->___str_3;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_2, NULL);
		__this->___U3ClengthU3E5__2_5 = L_3;
		goto IL_0193;
	}

IL_003a:
	{
		// ++pos;
		int32_t L_4 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_4, 1));
	}

IL_003e:
	{
		// while (pos < length && char.IsWhiteSpace(str[pos]))
		int32_t L_5 = V_1;
		int32_t L_6 = __this->___U3ClengthU3E5__2_5;
		if ((((int32_t)L_5) >= ((int32_t)L_6)))
		{
			goto IL_005a;
		}
	}
	{
		String_t* L_7 = __this->___str_3;
		int32_t L_8 = V_1;
		NullCheck(L_7);
		Il2CppChar L_9;
		L_9 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_7, L_8, NULL);
		il2cpp_codegen_runtime_class_init_inline(Char_t521A6F19B456D956AF452D926C32709DC03D6B17_il2cpp_TypeInfo_var);
		bool L_10;
		L_10 = Char_IsWhiteSpace_m02AEC6EA19513CAFC6882CFCA54C45794D2B5924(L_9, NULL);
		if (L_10)
		{
			goto IL_003a;
		}
	}

IL_005a:
	{
		// if (pos == length)
		int32_t L_11 = V_1;
		int32_t L_12 = __this->___U3ClengthU3E5__2_5;
		if ((((int32_t)L_11) == ((int32_t)L_12)))
		{
			goto IL_019f;
		}
	}
	{
		// if (str[pos] == '"')
		String_t* L_13 = __this->___str_3;
		int32_t L_14 = V_1;
		NullCheck(L_13);
		Il2CppChar L_15;
		L_15 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_13, L_14, NULL);
		if ((!(((uint32_t)L_15) == ((uint32_t)((int32_t)34)))))
		{
			goto IL_0123;
		}
	}
	{
		// ++pos;
		int32_t L_16 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_16, 1));
		// var endPos = pos;
		int32_t L_17 = V_1;
		__this->___U3CendPosU3E5__3_6 = L_17;
		goto IL_00cb;
	}

IL_0086:
	{
		// if (str[endPos] == '\\' && endPos < length - 1)
		String_t* L_18 = __this->___str_3;
		int32_t L_19 = __this->___U3CendPosU3E5__3_6;
		NullCheck(L_18);
		Il2CppChar L_20;
		L_20 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_18, L_19, NULL);
		if ((!(((uint32_t)L_20) == ((uint32_t)((int32_t)92)))))
		{
			goto IL_00bb;
		}
	}
	{
		int32_t L_21 = __this->___U3CendPosU3E5__3_6;
		int32_t L_22 = __this->___U3ClengthU3E5__2_5;
		if ((((int32_t)L_21) >= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_22, 1)))))
		{
			goto IL_00bb;
		}
	}
	{
		// ++endPos;
		int32_t L_23 = __this->___U3CendPosU3E5__3_6;
		V_2 = ((int32_t)il2cpp_codegen_add(L_23, 1));
		int32_t L_24 = V_2;
		__this->___U3CendPosU3E5__3_6 = L_24;
	}

IL_00bb:
	{
		// ++endPos;
		int32_t L_25 = __this->___U3CendPosU3E5__3_6;
		V_2 = ((int32_t)il2cpp_codegen_add(L_25, 1));
		int32_t L_26 = V_2;
		__this->___U3CendPosU3E5__3_6 = L_26;
	}

IL_00cb:
	{
		// while (endPos < length && str[endPos] != '\"')
		int32_t L_27 = __this->___U3CendPosU3E5__3_6;
		int32_t L_28 = __this->___U3ClengthU3E5__2_5;
		if ((((int32_t)L_27) >= ((int32_t)L_28)))
		{
			goto IL_00ee;
		}
	}
	{
		String_t* L_29 = __this->___str_3;
		int32_t L_30 = __this->___U3CendPosU3E5__3_6;
		NullCheck(L_29);
		Il2CppChar L_31;
		L_31 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_29, L_30, NULL);
		if ((!(((uint32_t)L_31) == ((uint32_t)((int32_t)34)))))
		{
			goto IL_0086;
		}
	}

IL_00ee:
	{
		// yield return new Substring(str, pos, endPos - pos);
		String_t* L_32 = __this->___str_3;
		int32_t L_33 = V_1;
		int32_t L_34 = __this->___U3CendPosU3E5__3_6;
		int32_t L_35 = V_1;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_36;
		memset((&L_36), 0, sizeof(L_36));
		Substring__ctor_m26B51DCD265326C6BCEAD778F0FC45407BB5F745((&L_36), L_32, L_33, ((int32_t)il2cpp_codegen_subtract(L_34, L_35)), /*hidden argument*/NULL);
		__this->___U3CU3E2__current_1 = L_36;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___U3CU3E2__current_1))->___m_String_0), (void*)NULL);
		__this->___U3CU3E1__state_0 = 1;
		return (bool)1;
	}

IL_0111:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// pos = endPos + 1;
		int32_t L_37 = __this->___U3CendPosU3E5__3_6;
		V_1 = ((int32_t)il2cpp_codegen_add(L_37, 1));
		goto IL_0193;
	}

IL_0123:
	{
		// var endPos = pos;
		int32_t L_38 = V_1;
		__this->___U3CendPosU3E5__3_6 = L_38;
		goto IL_013c;
	}

IL_012c:
	{
		// ++endPos;
		int32_t L_39 = __this->___U3CendPosU3E5__3_6;
		V_2 = ((int32_t)il2cpp_codegen_add(L_39, 1));
		int32_t L_40 = V_2;
		__this->___U3CendPosU3E5__3_6 = L_40;
	}

IL_013c:
	{
		// while (endPos < length && !char.IsWhiteSpace(str[endPos]))
		int32_t L_41 = __this->___U3CendPosU3E5__3_6;
		int32_t L_42 = __this->___U3ClengthU3E5__2_5;
		if ((((int32_t)L_41) >= ((int32_t)L_42)))
		{
			goto IL_0162;
		}
	}
	{
		String_t* L_43 = __this->___str_3;
		int32_t L_44 = __this->___U3CendPosU3E5__3_6;
		NullCheck(L_43);
		Il2CppChar L_45;
		L_45 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_43, L_44, NULL);
		il2cpp_codegen_runtime_class_init_inline(Char_t521A6F19B456D956AF452D926C32709DC03D6B17_il2cpp_TypeInfo_var);
		bool L_46;
		L_46 = Char_IsWhiteSpace_m02AEC6EA19513CAFC6882CFCA54C45794D2B5924(L_45, NULL);
		if (!L_46)
		{
			goto IL_012c;
		}
	}

IL_0162:
	{
		// yield return new Substring(str, pos, endPos - pos);
		String_t* L_47 = __this->___str_3;
		int32_t L_48 = V_1;
		int32_t L_49 = __this->___U3CendPosU3E5__3_6;
		int32_t L_50 = V_1;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_51;
		memset((&L_51), 0, sizeof(L_51));
		Substring__ctor_m26B51DCD265326C6BCEAD778F0FC45407BB5F745((&L_51), L_47, L_48, ((int32_t)il2cpp_codegen_subtract(L_49, L_50)), /*hidden argument*/NULL);
		__this->___U3CU3E2__current_1 = L_51;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___U3CU3E2__current_1))->___m_String_0), (void*)NULL);
		__this->___U3CU3E1__state_0 = 2;
		return (bool)1;
	}

IL_0185:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// pos = endPos;
		int32_t L_52 = __this->___U3CendPosU3E5__3_6;
		V_1 = L_52;
	}

IL_0193:
	{
		// while (pos < length)
		int32_t L_53 = V_1;
		int32_t L_54 = __this->___U3ClengthU3E5__2_5;
		if ((((int32_t)L_53) < ((int32_t)L_54)))
		{
			goto IL_003e;
		}
	}

IL_019f:
	{
		// }
		return (bool)0;
	}
}
// UnityEngine.InputSystem.Utilities.Substring UnityEngine.InputSystem.Utilities.StringHelpers/<Tokenize>d__8::System.Collections.Generic.IEnumerator<UnityEngine.InputSystem.Utilities.Substring>.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Substring_t2E16755269E6716C22074D6BC0A9099915E67849 U3CTokenizeU3Ed__8_System_Collections_Generic_IEnumeratorU3CUnityEngine_InputSystem_Utilities_SubstringU3E_get_Current_mEDA880C925219C930290013867BAE1EEE24AD856 (U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B* __this, const RuntimeMethod* method) 
{
	{
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
// System.Void UnityEngine.InputSystem.Utilities.StringHelpers/<Tokenize>d__8::System.Collections.IEnumerator.Reset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CTokenizeU3Ed__8_System_Collections_IEnumerator_Reset_m8FB2BAFA8C54922ACD753AA18C5D50CDFC31B3C8 (U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NullCheck(L_0);
		NotSupportedException__ctor_m1398D0CDE19B36AA3DE9392879738C1EA2439CDF(L_0, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&U3CTokenizeU3Ed__8_System_Collections_IEnumerator_Reset_m8FB2BAFA8C54922ACD753AA18C5D50CDFC31B3C8_RuntimeMethod_var)));
	}
}
// System.Object UnityEngine.InputSystem.Utilities.StringHelpers/<Tokenize>d__8::System.Collections.IEnumerator.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CTokenizeU3Ed__8_System_Collections_IEnumerator_get_Current_mF332A900E71F3D43FC05A69934A2BD162F2D9A5F (U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Substring_t2E16755269E6716C22074D6BC0A9099915E67849_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_0 = __this->___U3CU3E2__current_1;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_1 = L_0;
		RuntimeObject* L_2 = Box(Substring_t2E16755269E6716C22074D6BC0A9099915E67849_il2cpp_TypeInfo_var, &L_1);
		return L_2;
	}
}
// System.Collections.Generic.IEnumerator`1<UnityEngine.InputSystem.Utilities.Substring> UnityEngine.InputSystem.Utilities.StringHelpers/<Tokenize>d__8::System.Collections.Generic.IEnumerable<UnityEngine.InputSystem.Utilities.Substring>.GetEnumerator()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CTokenizeU3Ed__8_System_Collections_Generic_IEnumerableU3CUnityEngine_InputSystem_Utilities_SubstringU3E_GetEnumerator_m79F809FB39EEDCBAEBBCB6D0BFC16E86A858C9BE (U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B* V_0 = NULL;
	{
		int32_t L_0 = __this->___U3CU3E1__state_0;
		if ((!(((uint32_t)L_0) == ((uint32_t)((int32_t)-2)))))
		{
			goto IL_0022;
		}
	}
	{
		int32_t L_1 = __this->___U3CU3El__initialThreadId_2;
		int32_t L_2;
		L_2 = Environment_get_CurrentManagedThreadId_m66483AADCCC13272EBDCD94D31D2E52603C24BDF(NULL);
		if ((!(((uint32_t)L_1) == ((uint32_t)L_2))))
		{
			goto IL_0022;
		}
	}
	{
		__this->___U3CU3E1__state_0 = 0;
		V_0 = __this;
		goto IL_0029;
	}

IL_0022:
	{
		U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B* L_3 = (U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B*)il2cpp_codegen_object_new(U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		U3CTokenizeU3Ed__8__ctor_mFCB5DCEF9B0F44B630C8C831ADC12246A0CA2785(L_3, 0, NULL);
		V_0 = L_3;
	}

IL_0029:
	{
		U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B* L_4 = V_0;
		String_t* L_5 = __this->___U3CU3E3__str_4;
		NullCheck(L_4);
		L_4->___str_3 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&L_4->___str_3), (void*)L_5);
		U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B* L_6 = V_0;
		return L_6;
	}
}
// System.Collections.IEnumerator UnityEngine.InputSystem.Utilities.StringHelpers/<Tokenize>d__8::System.Collections.IEnumerable.GetEnumerator()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CTokenizeU3Ed__8_System_Collections_IEnumerable_GetEnumerator_m90947DCE3F3BF336F8E7041A66A5FACEED1E5BB2 (U3CTokenizeU3Ed__8_t974A4A167882F66AC70C15513407BB7218E6E64B* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0;
		L_0 = U3CTokenizeU3Ed__8_System_Collections_Generic_IEnumerableU3CUnityEngine_InputSystem_Utilities_SubstringU3E_GetEnumerator_m79F809FB39EEDCBAEBBCB6D0BFC16E86A858C9BE(__this, NULL);
		return L_0;
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
// Conversion methods for marshalling of: UnityEngine.InputSystem.Utilities.Substring
IL2CPP_EXTERN_C void Substring_t2E16755269E6716C22074D6BC0A9099915E67849_marshal_pinvoke(const Substring_t2E16755269E6716C22074D6BC0A9099915E67849& unmarshaled, Substring_t2E16755269E6716C22074D6BC0A9099915E67849_marshaled_pinvoke& marshaled)
{
	marshaled.___m_String_0 = il2cpp_codegen_marshal_string(unmarshaled.___m_String_0);
	marshaled.___m_Index_1 = unmarshaled.___m_Index_1;
	marshaled.___m_Length_2 = unmarshaled.___m_Length_2;
}
IL2CPP_EXTERN_C void Substring_t2E16755269E6716C22074D6BC0A9099915E67849_marshal_pinvoke_back(const Substring_t2E16755269E6716C22074D6BC0A9099915E67849_marshaled_pinvoke& marshaled, Substring_t2E16755269E6716C22074D6BC0A9099915E67849& unmarshaled)
{
	unmarshaled.___m_String_0 = il2cpp_codegen_marshal_string_result(marshaled.___m_String_0);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___m_String_0), (void*)il2cpp_codegen_marshal_string_result(marshaled.___m_String_0));
	int32_t unmarshaledm_Index_temp_1 = 0;
	unmarshaledm_Index_temp_1 = marshaled.___m_Index_1;
	unmarshaled.___m_Index_1 = unmarshaledm_Index_temp_1;
	int32_t unmarshaledm_Length_temp_2 = 0;
	unmarshaledm_Length_temp_2 = marshaled.___m_Length_2;
	unmarshaled.___m_Length_2 = unmarshaledm_Length_temp_2;
}
// Conversion method for clean up from marshalling of: UnityEngine.InputSystem.Utilities.Substring
IL2CPP_EXTERN_C void Substring_t2E16755269E6716C22074D6BC0A9099915E67849_marshal_pinvoke_cleanup(Substring_t2E16755269E6716C22074D6BC0A9099915E67849_marshaled_pinvoke& marshaled)
{
	il2cpp_codegen_marshal_free(marshaled.___m_String_0);
	marshaled.___m_String_0 = NULL;
}
// Conversion methods for marshalling of: UnityEngine.InputSystem.Utilities.Substring
IL2CPP_EXTERN_C void Substring_t2E16755269E6716C22074D6BC0A9099915E67849_marshal_com(const Substring_t2E16755269E6716C22074D6BC0A9099915E67849& unmarshaled, Substring_t2E16755269E6716C22074D6BC0A9099915E67849_marshaled_com& marshaled)
{
	marshaled.___m_String_0 = il2cpp_codegen_marshal_bstring(unmarshaled.___m_String_0);
	marshaled.___m_Index_1 = unmarshaled.___m_Index_1;
	marshaled.___m_Length_2 = unmarshaled.___m_Length_2;
}
IL2CPP_EXTERN_C void Substring_t2E16755269E6716C22074D6BC0A9099915E67849_marshal_com_back(const Substring_t2E16755269E6716C22074D6BC0A9099915E67849_marshaled_com& marshaled, Substring_t2E16755269E6716C22074D6BC0A9099915E67849& unmarshaled)
{
	unmarshaled.___m_String_0 = il2cpp_codegen_marshal_bstring_result(marshaled.___m_String_0);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___m_String_0), (void*)il2cpp_codegen_marshal_bstring_result(marshaled.___m_String_0));
	int32_t unmarshaledm_Index_temp_1 = 0;
	unmarshaledm_Index_temp_1 = marshaled.___m_Index_1;
	unmarshaled.___m_Index_1 = unmarshaledm_Index_temp_1;
	int32_t unmarshaledm_Length_temp_2 = 0;
	unmarshaledm_Length_temp_2 = marshaled.___m_Length_2;
	unmarshaled.___m_Length_2 = unmarshaledm_Length_temp_2;
}
// Conversion method for clean up from marshalling of: UnityEngine.InputSystem.Utilities.Substring
IL2CPP_EXTERN_C void Substring_t2E16755269E6716C22074D6BC0A9099915E67849_marshal_com_cleanup(Substring_t2E16755269E6716C22074D6BC0A9099915E67849_marshaled_com& marshaled)
{
	il2cpp_codegen_marshal_free_bstring(marshaled.___m_String_0);
	marshaled.___m_String_0 = NULL;
}
// System.Boolean UnityEngine.InputSystem.Utilities.Substring::get_isEmpty()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Substring_get_isEmpty_m595F6475C26E9FFE44A503FC412CCB059B0FBC47 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, const RuntimeMethod* method) 
{
	{
		// public bool isEmpty => m_Length == 0;
		int32_t L_0 = __this->___m_Length_2;
		return (bool)((((int32_t)L_0) == ((int32_t)0))? 1 : 0);
	}
}
IL2CPP_EXTERN_C  bool Substring_get_isEmpty_m595F6475C26E9FFE44A503FC412CCB059B0FBC47_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Substring_t2E16755269E6716C22074D6BC0A9099915E67849*>(__this + _offset);
	bool _returnValue;
	_returnValue = Substring_get_isEmpty_m595F6475C26E9FFE44A503FC412CCB059B0FBC47(_thisAdjusted, method);
	return _returnValue;
}
// System.Void UnityEngine.InputSystem.Utilities.Substring::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Substring__ctor_m5EF457666A6E65F74FA240D42360D666FD477937 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, String_t* ___0_str, const RuntimeMethod* method) 
{
	{
		// m_String = str;
		String_t* L_0 = ___0_str;
		__this->___m_String_0 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_String_0), (void*)L_0);
		// m_Index = 0;
		__this->___m_Index_1 = 0;
		// if (str != null)
		String_t* L_1 = ___0_str;
		if (!L_1)
		{
			goto IL_001e;
		}
	}
	{
		// m_Length = str.Length;
		String_t* L_2 = ___0_str;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_2, NULL);
		__this->___m_Length_2 = L_3;
		return;
	}

IL_001e:
	{
		// m_Length = 0;
		__this->___m_Length_2 = 0;
		// }
		return;
	}
}
IL2CPP_EXTERN_C  void Substring__ctor_m5EF457666A6E65F74FA240D42360D666FD477937_AdjustorThunk (RuntimeObject* __this, String_t* ___0_str, const RuntimeMethod* method)
{
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Substring_t2E16755269E6716C22074D6BC0A9099915E67849*>(__this + _offset);
	Substring__ctor_m5EF457666A6E65F74FA240D42360D666FD477937(_thisAdjusted, ___0_str, method);
}
// System.Void UnityEngine.InputSystem.Utilities.Substring::.ctor(System.String,System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Substring__ctor_m26B51DCD265326C6BCEAD778F0FC45407BB5F745 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, String_t* ___0_str, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) 
{
	{
		// m_String = str;
		String_t* L_0 = ___0_str;
		__this->___m_String_0 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_String_0), (void*)L_0);
		// m_Index = index;
		int32_t L_1 = ___1_index;
		__this->___m_Index_1 = L_1;
		// m_Length = length;
		int32_t L_2 = ___2_length;
		__this->___m_Length_2 = L_2;
		// }
		return;
	}
}
IL2CPP_EXTERN_C  void Substring__ctor_m26B51DCD265326C6BCEAD778F0FC45407BB5F745_AdjustorThunk (RuntimeObject* __this, String_t* ___0_str, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method)
{
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Substring_t2E16755269E6716C22074D6BC0A9099915E67849*>(__this + _offset);
	Substring__ctor_m26B51DCD265326C6BCEAD778F0FC45407BB5F745(_thisAdjusted, ___0_str, ___1_index, ___2_length, method);
}
// System.Void UnityEngine.InputSystem.Utilities.Substring::.ctor(System.String,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Substring__ctor_mD29CA4E0387A9343B5A0839A92A7AC13468621D9 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, String_t* ___0_str, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		// m_String = str;
		String_t* L_0 = ___0_str;
		__this->___m_String_0 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_String_0), (void*)L_0);
		// m_Index = index;
		int32_t L_1 = ___1_index;
		__this->___m_Index_1 = L_1;
		// m_Length = str.Length - index;
		String_t* L_2 = ___0_str;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_2, NULL);
		int32_t L_4 = ___1_index;
		__this->___m_Length_2 = ((int32_t)il2cpp_codegen_subtract(L_3, L_4));
		// }
		return;
	}
}
IL2CPP_EXTERN_C  void Substring__ctor_mD29CA4E0387A9343B5A0839A92A7AC13468621D9_AdjustorThunk (RuntimeObject* __this, String_t* ___0_str, int32_t ___1_index, const RuntimeMethod* method)
{
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Substring_t2E16755269E6716C22074D6BC0A9099915E67849*>(__this + _offset);
	Substring__ctor_mD29CA4E0387A9343B5A0839A92A7AC13468621D9(_thisAdjusted, ___0_str, ___1_index, method);
}
// System.Boolean UnityEngine.InputSystem.Utilities.Substring::Equals(System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Substring_Equals_m34CEE374E83C2E31E0C90566412EA4B17BEEFA46 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&String_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Substring_t2E16755269E6716C22074D6BC0A9099915E67849_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849 V_0;
	memset((&V_0), 0, sizeof(V_0));
	String_t* V_1 = NULL;
	{
		// if (obj is Substring other)
		RuntimeObject* L_0 = ___0_obj;
		if (!((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, Substring_t2E16755269E6716C22074D6BC0A9099915E67849_il2cpp_TypeInfo_var)))
		{
			goto IL_0017;
		}
	}
	{
		RuntimeObject* L_1 = ___0_obj;
		V_0 = ((*(Substring_t2E16755269E6716C22074D6BC0A9099915E67849*)((Substring_t2E16755269E6716C22074D6BC0A9099915E67849*)(Substring_t2E16755269E6716C22074D6BC0A9099915E67849*)UnBox(L_1, Substring_t2E16755269E6716C22074D6BC0A9099915E67849_il2cpp_TypeInfo_var))));
		// return Equals(other);
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_2 = V_0;
		bool L_3;
		L_3 = Substring_Equals_m90DCA9419D3654340F7660D99B85C7F817B3E76F(__this, L_2, NULL);
		return L_3;
	}

IL_0017:
	{
		// if (obj is string str)
		RuntimeObject* L_4 = ___0_obj;
		V_1 = ((String_t*)IsInstSealed((RuntimeObject*)L_4, String_t_il2cpp_TypeInfo_var));
		String_t* L_5 = V_1;
		if (!L_5)
		{
			goto IL_0029;
		}
	}
	{
		// return Equals(str);
		String_t* L_6 = V_1;
		bool L_7;
		L_7 = Substring_Equals_mBACFC276E8FD4DB04E356A41595EA284FC431CC7(__this, L_6, NULL);
		return L_7;
	}

IL_0029:
	{
		// return false;
		return (bool)0;
	}
}
IL2CPP_EXTERN_C  bool Substring_Equals_m34CEE374E83C2E31E0C90566412EA4B17BEEFA46_AdjustorThunk (RuntimeObject* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method)
{
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Substring_t2E16755269E6716C22074D6BC0A9099915E67849*>(__this + _offset);
	bool _returnValue;
	_returnValue = Substring_Equals_m34CEE374E83C2E31E0C90566412EA4B17BEEFA46(_thisAdjusted, ___0_obj, method);
	return _returnValue;
}
// System.Boolean UnityEngine.InputSystem.Utilities.Substring::Equals(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Substring_Equals_mBACFC276E8FD4DB04E356A41595EA284FC431CC7 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, String_t* ___0_other, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		// if (string.IsNullOrEmpty(other))
		String_t* L_0 = ___0_other;
		bool L_1;
		L_1 = String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478(L_0, NULL);
		if (!L_1)
		{
			goto IL_0012;
		}
	}
	{
		// return m_Length == 0;
		int32_t L_2 = __this->___m_Length_2;
		return (bool)((((int32_t)L_2) == ((int32_t)0))? 1 : 0);
	}

IL_0012:
	{
		// if (other.Length != m_Length)
		String_t* L_3 = ___0_other;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_3, NULL);
		int32_t L_5 = __this->___m_Length_2;
		if ((((int32_t)L_4) == ((int32_t)L_5)))
		{
			goto IL_0022;
		}
	}
	{
		// return false;
		return (bool)0;
	}

IL_0022:
	{
		// for (var i = 0; i < m_Length; ++i)
		V_0 = 0;
		goto IL_0048;
	}

IL_0026:
	{
		// if (other[i] != m_String[m_Index + i])
		String_t* L_6 = ___0_other;
		int32_t L_7 = V_0;
		NullCheck(L_6);
		Il2CppChar L_8;
		L_8 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_6, L_7, NULL);
		String_t* L_9 = __this->___m_String_0;
		int32_t L_10 = __this->___m_Index_1;
		int32_t L_11 = V_0;
		NullCheck(L_9);
		Il2CppChar L_12;
		L_12 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_9, ((int32_t)il2cpp_codegen_add(L_10, L_11)), NULL);
		if ((((int32_t)L_8) == ((int32_t)L_12)))
		{
			goto IL_0044;
		}
	}
	{
		// return false;
		return (bool)0;
	}

IL_0044:
	{
		// for (var i = 0; i < m_Length; ++i)
		int32_t L_13 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0048:
	{
		// for (var i = 0; i < m_Length; ++i)
		int32_t L_14 = V_0;
		int32_t L_15 = __this->___m_Length_2;
		if ((((int32_t)L_14) < ((int32_t)L_15)))
		{
			goto IL_0026;
		}
	}
	{
		// return true;
		return (bool)1;
	}
}
IL2CPP_EXTERN_C  bool Substring_Equals_mBACFC276E8FD4DB04E356A41595EA284FC431CC7_AdjustorThunk (RuntimeObject* __this, String_t* ___0_other, const RuntimeMethod* method)
{
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Substring_t2E16755269E6716C22074D6BC0A9099915E67849*>(__this + _offset);
	bool _returnValue;
	_returnValue = Substring_Equals_mBACFC276E8FD4DB04E356A41595EA284FC431CC7(_thisAdjusted, ___0_other, method);
	return _returnValue;
}
// System.Boolean UnityEngine.InputSystem.Utilities.Substring::Equals(UnityEngine.InputSystem.Utilities.Substring)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Substring_Equals_m90DCA9419D3654340F7660D99B85C7F817B3E76F (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___0_other, const RuntimeMethod* method) 
{
	{
		// return CompareTo(other) == 0;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_0 = ___0_other;
		int32_t L_1;
		L_1 = Substring_CompareTo_m73D1F0A207D0D12553B2BD44961097FCAD4F2AA1(__this, L_0, NULL);
		return (bool)((((int32_t)L_1) == ((int32_t)0))? 1 : 0);
	}
}
IL2CPP_EXTERN_C  bool Substring_Equals_m90DCA9419D3654340F7660D99B85C7F817B3E76F_AdjustorThunk (RuntimeObject* __this, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___0_other, const RuntimeMethod* method)
{
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Substring_t2E16755269E6716C22074D6BC0A9099915E67849*>(__this + _offset);
	bool _returnValue;
	_returnValue = Substring_Equals_m90DCA9419D3654340F7660D99B85C7F817B3E76F(_thisAdjusted, ___0_other, method);
	return _returnValue;
}
// System.Boolean UnityEngine.InputSystem.Utilities.Substring::Equals(UnityEngine.InputSystem.Utilities.InternedString)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Substring_Equals_m1A54740A335BF499C1A804182A4485A04F769C10 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_other, const RuntimeMethod* method) 
{
	{
		// if (length != other.length)
		int32_t L_0;
		L_0 = Substring_get_length_m55986408214CA7DBD05548C1E226DC2E4D6E78FC_inline(__this, NULL);
		int32_t L_1;
		L_1 = InternedString_get_length_m4C5C8B69056154F3B5CF7D696A9D72803FC3FAFD((&___0_other), NULL);
		if ((((int32_t)L_0) == ((int32_t)L_1)))
		{
			goto IL_0011;
		}
	}
	{
		// return false;
		return (bool)0;
	}

IL_0011:
	{
		// return string.Compare(m_String, m_Index, other.ToString(), 0, length,
		//     StringComparison.OrdinalIgnoreCase) == 0;
		String_t* L_2 = __this->___m_String_0;
		int32_t L_3 = __this->___m_Index_1;
		String_t* L_4;
		L_4 = InternedString_ToString_mED327D67EF001C5EDFF284336F13C3E3F025993A((&___0_other), NULL);
		int32_t L_5;
		L_5 = Substring_get_length_m55986408214CA7DBD05548C1E226DC2E4D6E78FC_inline(__this, NULL);
		int32_t L_6;
		L_6 = String_Compare_m68FBA6075A0142439B0249D884863356D99090CF(L_2, L_3, L_4, 0, L_5, 5, NULL);
		return (bool)((((int32_t)L_6) == ((int32_t)0))? 1 : 0);
	}
}
IL2CPP_EXTERN_C  bool Substring_Equals_m1A54740A335BF499C1A804182A4485A04F769C10_AdjustorThunk (RuntimeObject* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_other, const RuntimeMethod* method)
{
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Substring_t2E16755269E6716C22074D6BC0A9099915E67849*>(__this + _offset);
	bool _returnValue;
	_returnValue = Substring_Equals_m1A54740A335BF499C1A804182A4485A04F769C10(_thisAdjusted, ___0_other, method);
	return _returnValue;
}
// System.Int32 UnityEngine.InputSystem.Utilities.Substring::CompareTo(UnityEngine.InputSystem.Utilities.Substring)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Substring_CompareTo_m73D1F0A207D0D12553B2BD44961097FCAD4F2AA1 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___0_other, const RuntimeMethod* method) 
{
	{
		// return Compare(this, other, StringComparison.CurrentCulture);
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_0 = (*(Substring_t2E16755269E6716C22074D6BC0A9099915E67849*)__this);
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_1 = ___0_other;
		int32_t L_2;
		L_2 = Substring_Compare_mEB3378051C685973B36959D7EE7F7C661508D81A(L_0, L_1, 0, NULL);
		return L_2;
	}
}
IL2CPP_EXTERN_C  int32_t Substring_CompareTo_m73D1F0A207D0D12553B2BD44961097FCAD4F2AA1_AdjustorThunk (RuntimeObject* __this, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___0_other, const RuntimeMethod* method)
{
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Substring_t2E16755269E6716C22074D6BC0A9099915E67849*>(__this + _offset);
	int32_t _returnValue;
	_returnValue = Substring_CompareTo_m73D1F0A207D0D12553B2BD44961097FCAD4F2AA1(_thisAdjusted, ___0_other, method);
	return _returnValue;
}
// System.Int32 UnityEngine.InputSystem.Utilities.Substring::Compare(UnityEngine.InputSystem.Utilities.Substring,UnityEngine.InputSystem.Utilities.Substring,System.StringComparison)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Substring_Compare_mEB3378051C685973B36959D7EE7F7C661508D81A (Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___0_left, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___1_right, int32_t ___2_comparison, const RuntimeMethod* method) 
{
	{
		// if (left.m_Length != right.m_Length)
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_0 = ___0_left;
		int32_t L_1 = L_0.___m_Length_2;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_2 = ___1_right;
		int32_t L_3 = L_2.___m_Length_2;
		if ((((int32_t)L_1) == ((int32_t)L_3)))
		{
			goto IL_0020;
		}
	}
	{
		// if (left.m_Length < right.m_Length)
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_4 = ___0_left;
		int32_t L_5 = L_4.___m_Length_2;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_6 = ___1_right;
		int32_t L_7 = L_6.___m_Length_2;
		if ((((int32_t)L_5) >= ((int32_t)L_7)))
		{
			goto IL_001e;
		}
	}
	{
		// return -1;
		return (-1);
	}

IL_001e:
	{
		// return 1;
		return 1;
	}

IL_0020:
	{
		// return string.Compare(left.m_String, left.m_Index, right.m_String, right.m_Index, left.m_Length,
		//     comparison);
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_8 = ___0_left;
		String_t* L_9 = L_8.___m_String_0;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_10 = ___0_left;
		int32_t L_11 = L_10.___m_Index_1;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_12 = ___1_right;
		String_t* L_13 = L_12.___m_String_0;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_14 = ___1_right;
		int32_t L_15 = L_14.___m_Index_1;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_16 = ___0_left;
		int32_t L_17 = L_16.___m_Length_2;
		int32_t L_18 = ___2_comparison;
		int32_t L_19;
		L_19 = String_Compare_m68FBA6075A0142439B0249D884863356D99090CF(L_9, L_11, L_13, L_15, L_17, L_18, NULL);
		return L_19;
	}
}
// System.Boolean UnityEngine.InputSystem.Utilities.Substring::StartsWith(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Substring_StartsWith_mCC5D1EC1C8F0CE526DE26CF1A8F21463716EB09E (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, String_t* ___0_str, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		// if (str.Length > length)
		String_t* L_0 = ___0_str;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_0, NULL);
		int32_t L_2;
		L_2 = Substring_get_length_m55986408214CA7DBD05548C1E226DC2E4D6E78FC_inline(__this, NULL);
		if ((((int32_t)L_1) <= ((int32_t)L_2)))
		{
			goto IL_0010;
		}
	}
	{
		// return false;
		return (bool)0;
	}

IL_0010:
	{
		// for (var i = 0; i < str.Length; ++i)
		V_0 = 0;
		goto IL_0036;
	}

IL_0014:
	{
		// if (m_String[m_Index + i] != str[i])
		String_t* L_3 = __this->___m_String_0;
		int32_t L_4 = __this->___m_Index_1;
		int32_t L_5 = V_0;
		NullCheck(L_3);
		Il2CppChar L_6;
		L_6 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_3, ((int32_t)il2cpp_codegen_add(L_4, L_5)), NULL);
		String_t* L_7 = ___0_str;
		int32_t L_8 = V_0;
		NullCheck(L_7);
		Il2CppChar L_9;
		L_9 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_7, L_8, NULL);
		if ((((int32_t)L_6) == ((int32_t)L_9)))
		{
			goto IL_0032;
		}
	}
	{
		// return false;
		return (bool)0;
	}

IL_0032:
	{
		// for (var i = 0; i < str.Length; ++i)
		int32_t L_10 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_10, 1));
	}

IL_0036:
	{
		// for (var i = 0; i < str.Length; ++i)
		int32_t L_11 = V_0;
		String_t* L_12 = ___0_str;
		NullCheck(L_12);
		int32_t L_13;
		L_13 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_12, NULL);
		if ((((int32_t)L_11) < ((int32_t)L_13)))
		{
			goto IL_0014;
		}
	}
	{
		// return true;
		return (bool)1;
	}
}
IL2CPP_EXTERN_C  bool Substring_StartsWith_mCC5D1EC1C8F0CE526DE26CF1A8F21463716EB09E_AdjustorThunk (RuntimeObject* __this, String_t* ___0_str, const RuntimeMethod* method)
{
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Substring_t2E16755269E6716C22074D6BC0A9099915E67849*>(__this + _offset);
	bool _returnValue;
	_returnValue = Substring_StartsWith_mCC5D1EC1C8F0CE526DE26CF1A8F21463716EB09E(_thisAdjusted, ___0_str, method);
	return _returnValue;
}
// System.String UnityEngine.InputSystem.Utilities.Substring::Substr(System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Substring_Substr_mCEF29557E9E2EB77B0FC67DD5894B763D5B08077 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, int32_t ___0_index, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		// if (length < 0)
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_000e;
		}
	}
	{
		// length = this.length - index;
		int32_t L_1;
		L_1 = Substring_get_length_m55986408214CA7DBD05548C1E226DC2E4D6E78FC_inline(__this, NULL);
		int32_t L_2 = ___0_index;
		___1_length = ((int32_t)il2cpp_codegen_subtract(L_1, L_2));
	}

IL_000e:
	{
		// return m_String.Substring(m_Index + index, length);
		String_t* L_3 = __this->___m_String_0;
		int32_t L_4 = __this->___m_Index_1;
		int32_t L_5 = ___0_index;
		int32_t L_6 = ___1_length;
		NullCheck(L_3);
		String_t* L_7;
		L_7 = String_Substring_mB1D94F47935D22E130FF2C01DBB6A4135FBB76CE(L_3, ((int32_t)il2cpp_codegen_add(L_4, L_5)), L_6, NULL);
		return L_7;
	}
}
IL2CPP_EXTERN_C  String_t* Substring_Substr_mCEF29557E9E2EB77B0FC67DD5894B763D5B08077_AdjustorThunk (RuntimeObject* __this, int32_t ___0_index, int32_t ___1_length, const RuntimeMethod* method)
{
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Substring_t2E16755269E6716C22074D6BC0A9099915E67849*>(__this + _offset);
	String_t* _returnValue;
	_returnValue = Substring_Substr_mCEF29557E9E2EB77B0FC67DD5894B763D5B08077(_thisAdjusted, ___0_index, ___1_length, method);
	return _returnValue;
}
// System.String UnityEngine.InputSystem.Utilities.Substring::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Substring_ToString_m321AF6BA186DB01349CE3C710F1EA773D38FEF6D (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&String_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (m_String == null)
		String_t* L_0 = __this->___m_String_0;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		// return string.Empty;
		String_t* L_1 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->___Empty_6;
		return L_1;
	}

IL_000e:
	{
		// return m_String.Substring(m_Index, m_Length);
		String_t* L_2 = __this->___m_String_0;
		int32_t L_3 = __this->___m_Index_1;
		int32_t L_4 = __this->___m_Length_2;
		NullCheck(L_2);
		String_t* L_5;
		L_5 = String_Substring_mB1D94F47935D22E130FF2C01DBB6A4135FBB76CE(L_2, L_3, L_4, NULL);
		return L_5;
	}
}
IL2CPP_EXTERN_C  String_t* Substring_ToString_m321AF6BA186DB01349CE3C710F1EA773D38FEF6D_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Substring_t2E16755269E6716C22074D6BC0A9099915E67849*>(__this + _offset);
	String_t* _returnValue;
	_returnValue = Substring_ToString_m321AF6BA186DB01349CE3C710F1EA773D38FEF6D(_thisAdjusted, method);
	return _returnValue;
}
// System.Int32 UnityEngine.InputSystem.Utilities.Substring::GetHashCode()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Substring_GetHashCode_m68743D4DB46190219FCBA41BACC476D7083D5986 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, const RuntimeMethod* method) 
{
	{
		// if (m_String == null)
		String_t* L_0 = __this->___m_String_0;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		// return 0;
		return 0;
	}

IL_000a:
	{
		// if (m_Index == 0 && m_Length == m_String.Length)
		int32_t L_1 = __this->___m_Index_1;
		if (L_1)
		{
			goto IL_0031;
		}
	}
	{
		int32_t L_2 = __this->___m_Length_2;
		String_t* L_3 = __this->___m_String_0;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_3, NULL);
		if ((!(((uint32_t)L_2) == ((uint32_t)L_4))))
		{
			goto IL_0031;
		}
	}
	{
		// return m_String.GetHashCode();
		String_t* L_5 = __this->___m_String_0;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = VirtualFuncInvoker0< int32_t >::Invoke(2 /* System.Int32 System.Object::GetHashCode() */, L_5);
		return L_6;
	}

IL_0031:
	{
		// return ToString().GetHashCode();
		String_t* L_7;
		L_7 = Substring_ToString_m321AF6BA186DB01349CE3C710F1EA773D38FEF6D(__this, NULL);
		NullCheck(L_7);
		int32_t L_8;
		L_8 = VirtualFuncInvoker0< int32_t >::Invoke(2 /* System.Int32 System.Object::GetHashCode() */, L_7);
		return L_8;
	}
}
IL2CPP_EXTERN_C  int32_t Substring_GetHashCode_m68743D4DB46190219FCBA41BACC476D7083D5986_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Substring_t2E16755269E6716C22074D6BC0A9099915E67849*>(__this + _offset);
	int32_t _returnValue;
	_returnValue = Substring_GetHashCode_m68743D4DB46190219FCBA41BACC476D7083D5986(_thisAdjusted, method);
	return _returnValue;
}
// System.Boolean UnityEngine.InputSystem.Utilities.Substring::op_Equality(UnityEngine.InputSystem.Utilities.Substring,UnityEngine.InputSystem.Utilities.Substring)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Substring_op_Equality_m093669AA9FEF9B2F321B2CBD70FEC8DC0E63ABE3 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___0_a, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___1_b, const RuntimeMethod* method) 
{
	{
		// return a.Equals(b);
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_0 = ___1_b;
		bool L_1;
		L_1 = Substring_Equals_m90DCA9419D3654340F7660D99B85C7F817B3E76F((&___0_a), L_0, NULL);
		return L_1;
	}
}
// System.Boolean UnityEngine.InputSystem.Utilities.Substring::op_Inequality(UnityEngine.InputSystem.Utilities.Substring,UnityEngine.InputSystem.Utilities.Substring)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Substring_op_Inequality_m9758D33CBBE9908CB8B1D55325B5FE39B63E8326 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___0_a, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___1_b, const RuntimeMethod* method) 
{
	{
		// return !a.Equals(b);
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_0 = ___1_b;
		bool L_1;
		L_1 = Substring_Equals_m90DCA9419D3654340F7660D99B85C7F817B3E76F((&___0_a), L_0, NULL);
		return (bool)((((int32_t)L_1) == ((int32_t)0))? 1 : 0);
	}
}
// System.Boolean UnityEngine.InputSystem.Utilities.Substring::op_Equality(UnityEngine.InputSystem.Utilities.Substring,UnityEngine.InputSystem.Utilities.InternedString)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Substring_op_Equality_mAA299F9DFF15320318C38BC113F990B5AA3A8E0A (Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___0_a, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___1_b, const RuntimeMethod* method) 
{
	{
		// return a.Equals(b);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_0 = ___1_b;
		bool L_1;
		L_1 = Substring_Equals_m1A54740A335BF499C1A804182A4485A04F769C10((&___0_a), L_0, NULL);
		return L_1;
	}
}
// System.Boolean UnityEngine.InputSystem.Utilities.Substring::op_Inequality(UnityEngine.InputSystem.Utilities.Substring,UnityEngine.InputSystem.Utilities.InternedString)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Substring_op_Inequality_mEBFD5CCB8D32B8EF62B9CFB4FC41E0EDE877BA75 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___0_a, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___1_b, const RuntimeMethod* method) 
{
	{
		// return !a.Equals(b);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_0 = ___1_b;
		bool L_1;
		L_1 = Substring_Equals_m1A54740A335BF499C1A804182A4485A04F769C10((&___0_a), L_0, NULL);
		return (bool)((((int32_t)L_1) == ((int32_t)0))? 1 : 0);
	}
}
// System.Boolean UnityEngine.InputSystem.Utilities.Substring::op_Equality(UnityEngine.InputSystem.Utilities.InternedString,UnityEngine.InputSystem.Utilities.Substring)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Substring_op_Equality_m9E29C02420DACFE79B798C13BDD1CBE9E9E121A1 (InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_a, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___1_b, const RuntimeMethod* method) 
{
	{
		// return b.Equals(a);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_0 = ___0_a;
		bool L_1;
		L_1 = Substring_Equals_m1A54740A335BF499C1A804182A4485A04F769C10((&___1_b), L_0, NULL);
		return L_1;
	}
}
// System.Boolean UnityEngine.InputSystem.Utilities.Substring::op_Inequality(UnityEngine.InputSystem.Utilities.InternedString,UnityEngine.InputSystem.Utilities.Substring)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Substring_op_Inequality_mFA42B36862D56E6B78AFF805BAF4AF753F032F48 (InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_a, Substring_t2E16755269E6716C22074D6BC0A9099915E67849 ___1_b, const RuntimeMethod* method) 
{
	{
		// return !b.Equals(a);
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_0 = ___0_a;
		bool L_1;
		L_1 = Substring_Equals_m1A54740A335BF499C1A804182A4485A04F769C10((&___1_b), L_0, NULL);
		return (bool)((((int32_t)L_1) == ((int32_t)0))? 1 : 0);
	}
}
// UnityEngine.InputSystem.Utilities.Substring UnityEngine.InputSystem.Utilities.Substring::op_Implicit(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Substring_t2E16755269E6716C22074D6BC0A9099915E67849 Substring_op_Implicit_mABF0BF448C43C80A01DE18A232F89B9EE19CDF89 (String_t* ___0_s, const RuntimeMethod* method) 
{
	{
		// return new Substring(s);
		String_t* L_0 = ___0_s;
		Substring_t2E16755269E6716C22074D6BC0A9099915E67849 L_1;
		memset((&L_1), 0, sizeof(L_1));
		Substring__ctor_m5EF457666A6E65F74FA240D42360D666FD477937((&L_1), L_0, /*hidden argument*/NULL);
		return L_1;
	}
}
// System.Int32 UnityEngine.InputSystem.Utilities.Substring::get_length()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Substring_get_length_m55986408214CA7DBD05548C1E226DC2E4D6E78FC (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, const RuntimeMethod* method) 
{
	{
		// public int length => m_Length;
		int32_t L_0 = __this->___m_Length_2;
		return L_0;
	}
}
IL2CPP_EXTERN_C  int32_t Substring_get_length_m55986408214CA7DBD05548C1E226DC2E4D6E78FC_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Substring_t2E16755269E6716C22074D6BC0A9099915E67849*>(__this + _offset);
	int32_t _returnValue;
	_returnValue = Substring_get_length_m55986408214CA7DBD05548C1E226DC2E4D6E78FC_inline(_thisAdjusted, method);
	return _returnValue;
}
// System.Int32 UnityEngine.InputSystem.Utilities.Substring::get_index()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Substring_get_index_mEF04F0C2A5292FEC77A6DE1C13C81B719C9D3012 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, const RuntimeMethod* method) 
{
	{
		// public int index => m_Index;
		int32_t L_0 = __this->___m_Index_1;
		return L_0;
	}
}
IL2CPP_EXTERN_C  int32_t Substring_get_index_mEF04F0C2A5292FEC77A6DE1C13C81B719C9D3012_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Substring_t2E16755269E6716C22074D6BC0A9099915E67849*>(__this + _offset);
	int32_t _returnValue;
	_returnValue = Substring_get_index_mEF04F0C2A5292FEC77A6DE1C13C81B719C9D3012_inline(_thisAdjusted, method);
	return _returnValue;
}
// System.Char UnityEngine.InputSystem.Utilities.Substring::get_Item(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppChar Substring_get_Item_m278F3C7634F20487F36267C4BD49BC96DAE4CAC4 (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		// if (index < 0 || index >= m_Length)
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) < ((int32_t)0)))
		{
			goto IL_000d;
		}
	}
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->___m_Length_2;
		if ((((int32_t)L_1) < ((int32_t)L_2)))
		{
			goto IL_0018;
		}
	}

IL_000d:
	{
		// throw new ArgumentOutOfRangeException(nameof(index));
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_3 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		NullCheck(L_3);
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Substring_get_Item_m278F3C7634F20487F36267C4BD49BC96DAE4CAC4_RuntimeMethod_var)));
	}

IL_0018:
	{
		// return m_String[m_Index + index];
		String_t* L_4 = __this->___m_String_0;
		int32_t L_5 = __this->___m_Index_1;
		int32_t L_6 = ___0_index;
		NullCheck(L_4);
		Il2CppChar L_7;
		L_7 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_4, ((int32_t)il2cpp_codegen_add(L_5, L_6)), NULL);
		return L_7;
	}
}
IL2CPP_EXTERN_C  Il2CppChar Substring_get_Item_m278F3C7634F20487F36267C4BD49BC96DAE4CAC4_AdjustorThunk (RuntimeObject* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	Substring_t2E16755269E6716C22074D6BC0A9099915E67849* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Substring_t2E16755269E6716C22074D6BC0A9099915E67849*>(__this + _offset);
	Il2CppChar _returnValue;
	_returnValue = Substring_get_Item_m278F3C7634F20487F36267C4BD49BC96DAE4CAC4(_thisAdjusted, ___0_index, method);
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
// System.Boolean UnityEngine.InputSystem.Utilities.TypeHelpers::IsInt(System.TypeCode)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool TypeHelpers_IsInt_mF21E7C110075BB092C997266BA351C89CCEDC2DA (int32_t ___0_type, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_type;
		switch (((int32_t)il2cpp_codegen_subtract((int32_t)L_0, 5)))
		{
			case 0:
			{
				goto IL_002c;
			}
			case 1:
			{
				goto IL_002a;
			}
			case 2:
			{
				goto IL_002e;
			}
			case 3:
			{
				goto IL_0034;
			}
			case 4:
			{
				goto IL_0030;
			}
			case 5:
			{
				goto IL_0036;
			}
			case 6:
			{
				goto IL_0032;
			}
			case 7:
			{
				goto IL_0038;
			}
		}
	}
	{
		goto IL_003a;
	}

IL_002a:
	{
		// case TypeCode.Byte: return true;
		return (bool)1;
	}

IL_002c:
	{
		// case TypeCode.SByte: return true;
		return (bool)1;
	}

IL_002e:
	{
		// case TypeCode.Int16: return true;
		return (bool)1;
	}

IL_0030:
	{
		// case TypeCode.Int32: return true;
		return (bool)1;
	}

IL_0032:
	{
		// case TypeCode.Int64: return true;
		return (bool)1;
	}

IL_0034:
	{
		// case TypeCode.UInt16: return true;
		return (bool)1;
	}

IL_0036:
	{
		// case TypeCode.UInt32: return true;
		return (bool)1;
	}

IL_0038:
	{
		// case TypeCode.UInt64: return true;
		return (bool)1;
	}

IL_003a:
	{
		// return false;
		return (bool)0;
	}
}
// System.Type UnityEngine.InputSystem.Utilities.TypeHelpers::GetValueType(System.Reflection.MemberInfo)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* TypeHelpers_GetValueType_m95FEE9C23AE46BC79D1149B270D7519C5065997A (MemberInfo_t* ___0_member, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&FieldInfo_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MethodInfo_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PropertyInfo_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	FieldInfo_t* V_0 = NULL;
	PropertyInfo_t* V_1 = NULL;
	MethodInfo_t* V_2 = NULL;
	{
		// var field = member as FieldInfo;
		MemberInfo_t* L_0 = ___0_member;
		V_0 = ((FieldInfo_t*)IsInstClass((RuntimeObject*)L_0, FieldInfo_t_il2cpp_TypeInfo_var));
		// if (field != null)
		FieldInfo_t* L_1 = V_0;
		bool L_2;
		L_2 = FieldInfo_op_Inequality_m95789A98E646494987E66A9E4188DCA86185066B(L_1, (FieldInfo_t*)NULL, NULL);
		if (!L_2)
		{
			goto IL_0017;
		}
	}
	{
		// return field.FieldType;
		FieldInfo_t* L_3 = V_0;
		NullCheck(L_3);
		Type_t* L_4;
		L_4 = VirtualFuncInvoker0< Type_t* >::Invoke(16 /* System.Type System.Reflection.FieldInfo::get_FieldType() */, L_3);
		return L_4;
	}

IL_0017:
	{
		// var property = member as PropertyInfo;
		MemberInfo_t* L_5 = ___0_member;
		V_1 = ((PropertyInfo_t*)IsInstClass((RuntimeObject*)L_5, PropertyInfo_t_il2cpp_TypeInfo_var));
		// if (property != null)
		PropertyInfo_t* L_6 = V_1;
		bool L_7;
		L_7 = PropertyInfo_op_Inequality_mE75A4F14CC678D8A670730FBD4338C718CACB51B(L_6, (PropertyInfo_t*)NULL, NULL);
		if (!L_7)
		{
			goto IL_002e;
		}
	}
	{
		// return property.PropertyType;
		PropertyInfo_t* L_8 = V_1;
		NullCheck(L_8);
		Type_t* L_9;
		L_9 = VirtualFuncInvoker0< Type_t* >::Invoke(15 /* System.Type System.Reflection.PropertyInfo::get_PropertyType() */, L_8);
		return L_9;
	}

IL_002e:
	{
		// var method = member as MethodInfo;
		MemberInfo_t* L_10 = ___0_member;
		V_2 = ((MethodInfo_t*)IsInstClass((RuntimeObject*)L_10, MethodInfo_t_il2cpp_TypeInfo_var));
		// if (method != null)
		MethodInfo_t* L_11 = V_2;
		bool L_12;
		L_12 = MethodInfo_op_Inequality_mB73597A1FCC2F906DBCADDEC68A1B7D5B7E89FA8(L_11, (MethodInfo_t*)NULL, NULL);
		if (!L_12)
		{
			goto IL_0045;
		}
	}
	{
		// return method.ReturnType;
		MethodInfo_t* L_13 = V_2;
		NullCheck(L_13);
		Type_t* L_14;
		L_14 = VirtualFuncInvoker0< Type_t* >::Invoke(38 /* System.Type System.Reflection.MethodInfo::get_ReturnType() */, L_13);
		return L_14;
	}

IL_0045:
	{
		// return null;
		return (Type_t*)NULL;
	}
}
// System.String UnityEngine.InputSystem.Utilities.TypeHelpers::GetNiceTypeName(System.Type)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* TypeHelpers_GetNiceTypeName_m9B7F0217784CAAADCA77152C0EDAE78811B187F2 (Type_t* ___0_type, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral007174B876FA7EECC4152046B9308966D3E2B5B8);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0BA8CB3B900ECEF5E697192B8CDA6B626EB0CE72);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral115036F179EA48E7662F9BE55E0E00A42DDE6DA7);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral316316045E2DB71BB9C0748EE882DBF00C83FD8E);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral38FB386B58970DA493E868CAC2AC6550E559B5D7);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC205D54CE3878136AF6661FE2D0B347BEC57D5AB);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD890B2BC5E5200965CD02403ABB6C221A614A1B7);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE1E5CE10BE86E259146E8ADE82FB423C65C3FFD7);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE3165827D406DD8F354BE7515C630A771E98916A);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE3AB954C27345B5777E41817C31696D6AC0E87C1);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE3DFC065B6A6D9931B797808DD066491AAB82B29);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (type.IsPrimitive)
		Type_t* L_0 = ___0_type;
		NullCheck(L_0);
		bool L_1;
		L_1 = Type_get_IsPrimitive_m46ACAAB8F754D37713E3E45437705F4F58FAFA18(L_0, NULL);
		if (!L_1)
		{
			goto IL_0113;
		}
	}
	{
		// if (type == typeof(int))
		Type_t* L_2 = ___0_type;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_3 = { reinterpret_cast<intptr_t> (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_4;
		L_4 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_3, NULL);
		bool L_5;
		L_5 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_2, L_4, NULL);
		if (!L_5)
		{
			goto IL_0023;
		}
	}
	{
		// return "int";
		return _stringLiteral0BA8CB3B900ECEF5E697192B8CDA6B626EB0CE72;
	}

IL_0023:
	{
		// if (type == typeof(float))
		Type_t* L_6 = ___0_type;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_8;
		L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
		bool L_9;
		L_9 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_6, L_8, NULL);
		if (!L_9)
		{
			goto IL_003b;
		}
	}
	{
		// return "float";
		return _stringLiteralE3DFC065B6A6D9931B797808DD066491AAB82B29;
	}

IL_003b:
	{
		// if (type == typeof(char))
		Type_t* L_10 = ___0_type;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		bool L_13;
		L_13 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_10, L_12, NULL);
		if (!L_13)
		{
			goto IL_0053;
		}
	}
	{
		// return "char";
		return _stringLiteral38FB386B58970DA493E868CAC2AC6550E559B5D7;
	}

IL_0053:
	{
		// if (type == typeof(byte))
		Type_t* L_14 = ___0_type;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_15 = { reinterpret_cast<intptr_t> (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_16;
		L_16 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_15, NULL);
		bool L_17;
		L_17 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_14, L_16, NULL);
		if (!L_17)
		{
			goto IL_006b;
		}
	}
	{
		// return "byte";
		return _stringLiteralE1E5CE10BE86E259146E8ADE82FB423C65C3FFD7;
	}

IL_006b:
	{
		// if (type == typeof(short))
		Type_t* L_18 = ___0_type;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_19 = { reinterpret_cast<intptr_t> (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_20;
		L_20 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_19, NULL);
		bool L_21;
		L_21 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_18, L_20, NULL);
		if (!L_21)
		{
			goto IL_0083;
		}
	}
	{
		// return "short";
		return _stringLiteral115036F179EA48E7662F9BE55E0E00A42DDE6DA7;
	}

IL_0083:
	{
		// if (type == typeof(long))
		Type_t* L_22 = ___0_type;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_23 = { reinterpret_cast<intptr_t> (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_24;
		L_24 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_23, NULL);
		bool L_25;
		L_25 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_22, L_24, NULL);
		if (!L_25)
		{
			goto IL_009b;
		}
	}
	{
		// return "long";
		return _stringLiteralD890B2BC5E5200965CD02403ABB6C221A614A1B7;
	}

IL_009b:
	{
		// if (type == typeof(double))
		Type_t* L_26 = ___0_type;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_27 = { reinterpret_cast<intptr_t> (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_28;
		L_28 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_27, NULL);
		bool L_29;
		L_29 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_26, L_28, NULL);
		if (!L_29)
		{
			goto IL_00b3;
		}
	}
	{
		// return "double";
		return _stringLiteral007174B876FA7EECC4152046B9308966D3E2B5B8;
	}

IL_00b3:
	{
		// if (type == typeof(uint))
		Type_t* L_30 = ___0_type;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_31 = { reinterpret_cast<intptr_t> (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_32;
		L_32 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_31, NULL);
		bool L_33;
		L_33 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_30, L_32, NULL);
		if (!L_33)
		{
			goto IL_00cb;
		}
	}
	{
		// return "uint";
		return _stringLiteralE3165827D406DD8F354BE7515C630A771E98916A;
	}

IL_00cb:
	{
		// if (type == typeof(sbyte))
		Type_t* L_34 = ___0_type;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_35 = { reinterpret_cast<intptr_t> (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_36;
		L_36 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_35, NULL);
		bool L_37;
		L_37 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_34, L_36, NULL);
		if (!L_37)
		{
			goto IL_00e3;
		}
	}
	{
		// return "sbyte";
		return _stringLiteralC205D54CE3878136AF6661FE2D0B347BEC57D5AB;
	}

IL_00e3:
	{
		// if (type == typeof(ushort))
		Type_t* L_38 = ___0_type;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_39 = { reinterpret_cast<intptr_t> (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_40;
		L_40 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_39, NULL);
		bool L_41;
		L_41 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_38, L_40, NULL);
		if (!L_41)
		{
			goto IL_00fb;
		}
	}
	{
		// return "ushort";
		return _stringLiteral316316045E2DB71BB9C0748EE882DBF00C83FD8E;
	}

IL_00fb:
	{
		// if (type == typeof(ulong))
		Type_t* L_42 = ___0_type;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_43 = { reinterpret_cast<intptr_t> (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_44;
		L_44 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_43, NULL);
		bool L_45;
		L_45 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_42, L_44, NULL);
		if (!L_45)
		{
			goto IL_0113;
		}
	}
	{
		// return "ulong";
		return _stringLiteralE3AB954C27345B5777E41817C31696D6AC0E87C1;
	}

IL_0113:
	{
		// return type.Name;
		Type_t* L_46 = ___0_type;
		NullCheck(L_46);
		String_t* L_47;
		L_47 = VirtualFuncInvoker0< String_t* >::Invoke(7 /* System.String System.Reflection.MemberInfo::get_Name() */, L_46);
		return L_47;
	}
}
// System.Type UnityEngine.InputSystem.Utilities.TypeHelpers::GetGenericTypeArgumentFromHierarchy(System.Type,System.Type,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* TypeHelpers_GetGenericTypeArgumentFromHierarchy_m9CE3EA9B8DFBBBC2BD6BFB81B4D66FB6922C089C (Type_t* ___0_type, Type_t* ___1_genericTypeDefinition, int32_t ___2_argumentIndex, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RuntimeObject_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* V_1 = NULL;
	int32_t V_2 = 0;
	Type_t* V_3 = NULL;
	Type_t* V_4 = NULL;
	{
		// if (type == null)
		Type_t* L_0 = ___0_type;
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_0, (Type_t*)NULL, NULL);
		if (!L_1)
		{
			goto IL_0014;
		}
	}
	{
		// throw new ArgumentNullException(nameof(type));
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_2 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		NullCheck(L_2);
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF3C6C902DBF80139640F6554F0C3392016A8ADF7)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&TypeHelpers_GetGenericTypeArgumentFromHierarchy_m9CE3EA9B8DFBBBC2BD6BFB81B4D66FB6922C089C_RuntimeMethod_var)));
	}

IL_0014:
	{
		// if (genericTypeDefinition == null)
		Type_t* L_3 = ___1_genericTypeDefinition;
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_3, (Type_t*)NULL, NULL);
		if (!L_4)
		{
			goto IL_0028;
		}
	}
	{
		// throw new ArgumentNullException(nameof(genericTypeDefinition));
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_5 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		NullCheck(L_5);
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_5, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2900020C8C73B769305C05646CF927B358E92966)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_5, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&TypeHelpers_GetGenericTypeArgumentFromHierarchy_m9CE3EA9B8DFBBBC2BD6BFB81B4D66FB6922C089C_RuntimeMethod_var)));
	}

IL_0028:
	{
		// if (argumentIndex < 0)
		int32_t L_6 = ___2_argumentIndex;
		if ((((int32_t)L_6) >= ((int32_t)0)))
		{
			goto IL_0037;
		}
	}
	{
		// throw new ArgumentOutOfRangeException(nameof(argumentIndex));
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_7 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		NullCheck(L_7);
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_7, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral8494AF0C90D5A0F8C5D03F528442880CE6820192)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&TypeHelpers_GetGenericTypeArgumentFromHierarchy_m9CE3EA9B8DFBBBC2BD6BFB81B4D66FB6922C089C_RuntimeMethod_var)));
	}

IL_0037:
	{
		// if (genericTypeDefinition.IsInterface)
		Type_t* L_8 = ___1_genericTypeDefinition;
		NullCheck(L_8);
		bool L_9;
		L_9 = Type_get_IsInterface_m484A7D9321E72758EABE7F36AE266EB0905957EC(L_8, NULL);
		if (!L_9)
		{
			goto IL_00d5;
		}
	}

IL_0042:
	{
		// var interfaces = type.GetInterfaces();
		Type_t* L_10 = ___0_type;
		NullCheck(L_10);
		TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* L_11;
		L_11 = VirtualFuncInvoker0< TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* >::Invoke(112 /* System.Type[] System.Type::GetInterfaces() */, L_10);
		// var haveFoundInterface = false;
		V_0 = (bool)0;
		// foreach (var element in interfaces)
		V_1 = L_11;
		V_2 = 0;
		goto IL_008b;
	}

IL_004f:
	{
		// foreach (var element in interfaces)
		TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* L_12 = V_1;
		int32_t L_13 = V_2;
		NullCheck(L_12);
		int32_t L_14 = L_13;
		Type_t* L_15 = (L_12)->GetAt(static_cast<il2cpp_array_size_t>(L_14));
		V_3 = L_15;
		// if (element.IsConstructedGenericType &&
		//     element.GetGenericTypeDefinition() == genericTypeDefinition)
		Type_t* L_16 = V_3;
		NullCheck(L_16);
		bool L_17;
		L_17 = VirtualFuncInvoker0< bool >::Invoke(36 /* System.Boolean System.Type::get_IsConstructedGenericType() */, L_16);
		if (!L_17)
		{
			goto IL_0070;
		}
	}
	{
		Type_t* L_18 = V_3;
		NullCheck(L_18);
		Type_t* L_19;
		L_19 = VirtualFuncInvoker0< Type_t* >::Invoke(47 /* System.Type System.Type::GetGenericTypeDefinition() */, L_18);
		Type_t* L_20 = ___1_genericTypeDefinition;
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		bool L_21;
		L_21 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_19, L_20, NULL);
		if (!L_21)
		{
			goto IL_0070;
		}
	}
	{
		// type = element;
		Type_t* L_22 = V_3;
		___0_type = L_22;
		// haveFoundInterface = true;
		V_0 = (bool)1;
		// break;
		goto IL_0091;
	}

IL_0070:
	{
		// var typeArgument =
		//     GetGenericTypeArgumentFromHierarchy(element, genericTypeDefinition, argumentIndex);
		Type_t* L_23 = V_3;
		Type_t* L_24 = ___1_genericTypeDefinition;
		int32_t L_25 = ___2_argumentIndex;
		Type_t* L_26;
		L_26 = TypeHelpers_GetGenericTypeArgumentFromHierarchy_m9CE3EA9B8DFBBBC2BD6BFB81B4D66FB6922C089C(L_23, L_24, L_25, NULL);
		V_4 = L_26;
		// if (typeArgument != null)
		Type_t* L_27 = V_4;
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		bool L_28;
		L_28 = Type_op_Inequality_m83209C7BB3C05DFBEA3B6199B0BEFE8037301172(L_27, (Type_t*)NULL, NULL);
		if (!L_28)
		{
			goto IL_0087;
		}
	}
	{
		// return typeArgument;
		Type_t* L_29 = V_4;
		return L_29;
	}

IL_0087:
	{
		int32_t L_30 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_30, 1));
	}

IL_008b:
	{
		// foreach (var element in interfaces)
		int32_t L_31 = V_2;
		TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* L_32 = V_1;
		NullCheck(L_32);
		if ((((int32_t)L_31) < ((int32_t)((int32_t)(((RuntimeArray*)L_32)->max_length)))))
		{
			goto IL_004f;
		}
	}

IL_0091:
	{
		// if (haveFoundInterface)
		bool L_33 = V_0;
		if (L_33)
		{
			goto IL_00eb;
		}
	}
	{
		// type = type.BaseType;
		Type_t* L_34 = ___0_type;
		NullCheck(L_34);
		Type_t* L_35;
		L_35 = VirtualFuncInvoker0< Type_t* >::Invoke(108 /* System.Type System.Type::get_BaseType() */, L_34);
		___0_type = L_35;
		// if (type == null || type == typeof(object))
		Type_t* L_36 = ___0_type;
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		bool L_37;
		L_37 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_36, (Type_t*)NULL, NULL);
		if (L_37)
		{
			goto IL_00b7;
		}
	}
	{
		Type_t* L_38 = ___0_type;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_39 = { reinterpret_cast<intptr_t> (RuntimeObject_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_40;
		L_40 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_39, NULL);
		bool L_41;
		L_41 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_38, L_40, NULL);
		if (!L_41)
		{
			goto IL_0042;
		}
	}

IL_00b7:
	{
		// return null;
		return (Type_t*)NULL;
	}

IL_00b9:
	{
		// type = type.BaseType;
		Type_t* L_42 = ___0_type;
		NullCheck(L_42);
		Type_t* L_43;
		L_43 = VirtualFuncInvoker0< Type_t* >::Invoke(108 /* System.Type System.Type::get_BaseType() */, L_42);
		___0_type = L_43;
		// if (type == typeof(object))
		Type_t* L_44 = ___0_type;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_45 = { reinterpret_cast<intptr_t> (RuntimeObject_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_46;
		L_46 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_45, NULL);
		bool L_47;
		L_47 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_44, L_46, NULL);
		if (!L_47)
		{
			goto IL_00d5;
		}
	}
	{
		// return null;
		return (Type_t*)NULL;
	}

IL_00d5:
	{
		// while (!type.IsConstructedGenericType || type.GetGenericTypeDefinition() != genericTypeDefinition)
		Type_t* L_48 = ___0_type;
		NullCheck(L_48);
		bool L_49;
		L_49 = VirtualFuncInvoker0< bool >::Invoke(36 /* System.Boolean System.Type::get_IsConstructedGenericType() */, L_48);
		if (!L_49)
		{
			goto IL_00b9;
		}
	}
	{
		Type_t* L_50 = ___0_type;
		NullCheck(L_50);
		Type_t* L_51;
		L_51 = VirtualFuncInvoker0< Type_t* >::Invoke(47 /* System.Type System.Type::GetGenericTypeDefinition() */, L_50);
		Type_t* L_52 = ___1_genericTypeDefinition;
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		bool L_53;
		L_53 = Type_op_Inequality_m83209C7BB3C05DFBEA3B6199B0BEFE8037301172(L_51, L_52, NULL);
		if (L_53)
		{
			goto IL_00b9;
		}
	}

IL_00eb:
	{
		// return type.GenericTypeArguments[argumentIndex];
		Type_t* L_54 = ___0_type;
		NullCheck(L_54);
		TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* L_55;
		L_55 = VirtualFuncInvoker0< TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* >::Invoke(48 /* System.Type[] System.Type::get_GenericTypeArguments() */, L_54);
		int32_t L_56 = ___2_argumentIndex;
		NullCheck(L_55);
		int32_t L_57 = L_56;
		Type_t* L_58 = (L_55)->GetAt(static_cast<il2cpp_array_size_t>(L_57));
		return L_58;
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
// Conversion methods for marshalling of: UnityEngine.InputSystem.Utilities.TypeTable
IL2CPP_EXTERN_C void TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_marshal_pinvoke(const TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E& unmarshaled, TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_marshaled_pinvoke& marshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E____table_0_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* ___table_0Exception = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '%s' of type '%s'.", TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E____table_0_FieldInfo_var, TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_0_0_0_var);
	IL2CPP_RAISE_MANAGED_EXCEPTION(___table_0Exception, NULL);
}
IL2CPP_EXTERN_C void TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_marshal_pinvoke_back(const TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_marshaled_pinvoke& marshaled, TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E& unmarshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E____table_0_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* ___table_0Exception = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '%s' of type '%s'.", TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E____table_0_FieldInfo_var, TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_0_0_0_var);
	IL2CPP_RAISE_MANAGED_EXCEPTION(___table_0Exception, NULL);
}
// Conversion method for clean up from marshalling of: UnityEngine.InputSystem.Utilities.TypeTable
IL2CPP_EXTERN_C void TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_marshal_pinvoke_cleanup(TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_marshaled_pinvoke& marshaled)
{
}
// Conversion methods for marshalling of: UnityEngine.InputSystem.Utilities.TypeTable
IL2CPP_EXTERN_C void TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_marshal_com(const TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E& unmarshaled, TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_marshaled_com& marshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E____table_0_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* ___table_0Exception = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '%s' of type '%s'.", TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E____table_0_FieldInfo_var, TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_0_0_0_var);
	IL2CPP_RAISE_MANAGED_EXCEPTION(___table_0Exception, NULL);
}
IL2CPP_EXTERN_C void TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_marshal_com_back(const TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_marshaled_com& marshaled, TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E& unmarshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E____table_0_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* ___table_0Exception = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '%s' of type '%s'.", TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E____table_0_FieldInfo_var, TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_0_0_0_var);
	IL2CPP_RAISE_MANAGED_EXCEPTION(___table_0Exception, NULL);
}
// Conversion method for clean up from marshalling of: UnityEngine.InputSystem.Utilities.TypeTable
IL2CPP_EXTERN_C void TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_marshal_com_cleanup(TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E_marshaled_com& marshaled)
{
}
// System.Collections.Generic.IEnumerable`1<System.String> UnityEngine.InputSystem.Utilities.TypeTable::get_names()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* TypeTable_get_names_mDE4C37C80FF83DA878F42A69F48AEB9656052F0A (TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_get_Keys_mFDE9D7FC672A995E064B6F14DBC9EB0B0D15BFAF_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerable_Select_TisInternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_TisString_t_m3FCCE6DBA6A159830BE8363BF5BA444BCBF4B186_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Func_2_tE0082B3C229A425A69ECDABB19259709EC9F540F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec_U3Cget_namesU3Eb__2_0_m106D3E5FF1FBF96009877C31E3F0684CD8943EC9_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Func_2_tE0082B3C229A425A69ECDABB19259709EC9F540F* G_B2_0 = NULL;
	KeyCollection_tF0B6D6FBE89245B5B34798233471D53A6BF802A3* G_B2_1 = NULL;
	Func_2_tE0082B3C229A425A69ECDABB19259709EC9F540F* G_B1_0 = NULL;
	KeyCollection_tF0B6D6FBE89245B5B34798233471D53A6BF802A3* G_B1_1 = NULL;
	{
		// public IEnumerable<string> names => table.Keys.Select(x => x.ToString());
		Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D* L_0 = __this->___table_0;
		NullCheck(L_0);
		KeyCollection_tF0B6D6FBE89245B5B34798233471D53A6BF802A3* L_1;
		L_1 = Dictionary_2_get_Keys_mFDE9D7FC672A995E064B6F14DBC9EB0B0D15BFAF(L_0, Dictionary_2_get_Keys_mFDE9D7FC672A995E064B6F14DBC9EB0B0D15BFAF_RuntimeMethod_var);
		il2cpp_codegen_runtime_class_init_inline(U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA_il2cpp_TypeInfo_var);
		Func_2_tE0082B3C229A425A69ECDABB19259709EC9F540F* L_2 = ((U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA_il2cpp_TypeInfo_var))->___U3CU3E9__2_0_1;
		Func_2_tE0082B3C229A425A69ECDABB19259709EC9F540F* L_3 = L_2;
		G_B1_0 = L_3;
		G_B1_1 = L_1;
		if (L_3)
		{
			G_B2_0 = L_3;
			G_B2_1 = L_1;
			goto IL_002a;
		}
	}
	{
		il2cpp_codegen_runtime_class_init_inline(U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA_il2cpp_TypeInfo_var);
		U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA* L_4 = ((U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA_il2cpp_TypeInfo_var))->___U3CU3E9_0;
		Func_2_tE0082B3C229A425A69ECDABB19259709EC9F540F* L_5 = (Func_2_tE0082B3C229A425A69ECDABB19259709EC9F540F*)il2cpp_codegen_object_new(Func_2_tE0082B3C229A425A69ECDABB19259709EC9F540F_il2cpp_TypeInfo_var);
		NullCheck(L_5);
		Func_2__ctor_m6763116FA3257580D87BD903E24793FCD6D82548(L_5, L_4, (intptr_t)((void*)U3CU3Ec_U3Cget_namesU3Eb__2_0_m106D3E5FF1FBF96009877C31E3F0684CD8943EC9_RuntimeMethod_var), NULL);
		Func_2_tE0082B3C229A425A69ECDABB19259709EC9F540F* L_6 = L_5;
		((U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA_il2cpp_TypeInfo_var))->___U3CU3E9__2_0_1 = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA_il2cpp_TypeInfo_var))->___U3CU3E9__2_0_1), (void*)L_6);
		G_B2_0 = L_6;
		G_B2_1 = G_B1_1;
	}

IL_002a:
	{
		RuntimeObject* L_7;
		L_7 = Enumerable_Select_TisInternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_TisString_t_m3FCCE6DBA6A159830BE8363BF5BA444BCBF4B186(G_B2_1, G_B2_0, Enumerable_Select_TisInternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735_TisString_t_m3FCCE6DBA6A159830BE8363BF5BA444BCBF4B186_RuntimeMethod_var);
		return L_7;
	}
}
IL2CPP_EXTERN_C  RuntimeObject* TypeTable_get_names_mDE4C37C80FF83DA878F42A69F48AEB9656052F0A_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E*>(__this + _offset);
	RuntimeObject* _returnValue;
	_returnValue = TypeTable_get_names_mDE4C37C80FF83DA878F42A69F48AEB9656052F0A(_thisAdjusted, method);
	return _returnValue;
}
// System.Collections.Generic.IEnumerable`1<UnityEngine.InputSystem.Utilities.InternedString> UnityEngine.InputSystem.Utilities.TypeTable::get_internedNames()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* TypeTable_get_internedNames_m12DFD70B16C0F9F67C30BA95FC91286954E5F60B (TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_get_Keys_mFDE9D7FC672A995E064B6F14DBC9EB0B0D15BFAF_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public IEnumerable<InternedString> internedNames => table.Keys;
		Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D* L_0 = __this->___table_0;
		NullCheck(L_0);
		KeyCollection_tF0B6D6FBE89245B5B34798233471D53A6BF802A3* L_1;
		L_1 = Dictionary_2_get_Keys_mFDE9D7FC672A995E064B6F14DBC9EB0B0D15BFAF(L_0, Dictionary_2_get_Keys_mFDE9D7FC672A995E064B6F14DBC9EB0B0D15BFAF_RuntimeMethod_var);
		return L_1;
	}
}
IL2CPP_EXTERN_C  RuntimeObject* TypeTable_get_internedNames_m12DFD70B16C0F9F67C30BA95FC91286954E5F60B_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E*>(__this + _offset);
	RuntimeObject* _returnValue;
	_returnValue = TypeTable_get_internedNames_m12DFD70B16C0F9F67C30BA95FC91286954E5F60B(_thisAdjusted, method);
	return _returnValue;
}
// System.Void UnityEngine.InputSystem.Utilities.TypeTable::Initialize()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TypeTable_Initialize_m5EE09E37850E04357BB26CC52183617C08A11D0C (TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_mD10EC6AB3D41E49C23882A85B368A08800DFC5EE_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// table = new Dictionary<InternedString, Type>();
		Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D* L_0 = (Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D*)il2cpp_codegen_object_new(Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Dictionary_2__ctor_mD10EC6AB3D41E49C23882A85B368A08800DFC5EE(L_0, Dictionary_2__ctor_mD10EC6AB3D41E49C23882A85B368A08800DFC5EE_RuntimeMethod_var);
		__this->___table_0 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___table_0), (void*)L_0);
		// }
		return;
	}
}
IL2CPP_EXTERN_C  void TypeTable_Initialize_m5EE09E37850E04357BB26CC52183617C08A11D0C_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E*>(__this + _offset);
	TypeTable_Initialize_m5EE09E37850E04357BB26CC52183617C08A11D0C(_thisAdjusted, method);
}
// UnityEngine.InputSystem.Utilities.InternedString UnityEngine.InputSystem.Utilities.TypeTable::FindNameForType(System.Type)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 TypeTable_FindNameForType_m5974594EAAEB68C4488B8C9CFABF931B7666FB00 (TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E* __this, Type_t* ___0_type, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_GetEnumerator_m09228E70F30816068825C9BB4B45519E7143CE7A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_Dispose_m767111BF89218E9F0CD407F44CD9FF1CC6079B87_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_MoveNext_mEB31860F9718BC0DB2D231F91D9A78D9666B54EF_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_get_Current_m8161C19F09FC9E5EFD3BCE87B8907B3F660FFF51_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&KeyValuePair_2_get_Key_mE8768535ABCD24F453DC1EC5127CBD303DEC29A5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&KeyValuePair_2_get_Value_m9803DE61209750BB22E4E1A58A5DFB943EAFCB80_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Enumerator_tC7FEC7C0C46B33E076C8049925C674971CBC97DE V_0;
	memset((&V_0), 0, sizeof(V_0));
	KeyValuePair_2_t859F90B137C9291C0E478FBE85ABB18F30B91A27 V_1;
	memset((&V_1), 0, sizeof(V_1));
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 V_2;
	memset((&V_2), 0, sizeof(V_2));
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 V_3;
	memset((&V_3), 0, sizeof(V_3));
	{
		// if (type == null)
		Type_t* L_0 = ___0_type;
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_0, (Type_t*)NULL, NULL);
		if (!L_1)
		{
			goto IL_0014;
		}
	}
	{
		// throw new ArgumentNullException(nameof(type));
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_2 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		NullCheck(L_2);
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF3C6C902DBF80139640F6554F0C3392016A8ADF7)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&TypeTable_FindNameForType_m5974594EAAEB68C4488B8C9CFABF931B7666FB00_RuntimeMethod_var)));
	}

IL_0014:
	{
		// foreach (var pair in table)
		Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D* L_3 = __this->___table_0;
		NullCheck(L_3);
		Enumerator_tC7FEC7C0C46B33E076C8049925C674971CBC97DE L_4;
		L_4 = Dictionary_2_GetEnumerator_m09228E70F30816068825C9BB4B45519E7143CE7A(L_3, Dictionary_2_GetEnumerator_m09228E70F30816068825C9BB4B45519E7143CE7A_RuntimeMethod_var);
		V_0 = L_4;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_004e:
			{// begin finally (depth: 1)
				Enumerator_Dispose_m767111BF89218E9F0CD407F44CD9FF1CC6079B87((&V_0), Enumerator_Dispose_m767111BF89218E9F0CD407F44CD9FF1CC6079B87_RuntimeMethod_var);
				return;
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			{
				goto IL_0043_1;
			}

IL_0022_1:
			{
				// foreach (var pair in table)
				KeyValuePair_2_t859F90B137C9291C0E478FBE85ABB18F30B91A27 L_5;
				L_5 = Enumerator_get_Current_m8161C19F09FC9E5EFD3BCE87B8907B3F660FFF51_inline((&V_0), Enumerator_get_Current_m8161C19F09FC9E5EFD3BCE87B8907B3F660FFF51_RuntimeMethod_var);
				V_1 = L_5;
				// if (pair.Value == type)
				Type_t* L_6;
				L_6 = KeyValuePair_2_get_Value_m9803DE61209750BB22E4E1A58A5DFB943EAFCB80_inline((&V_1), KeyValuePair_2_get_Value_m9803DE61209750BB22E4E1A58A5DFB943EAFCB80_RuntimeMethod_var);
				Type_t* L_7 = ___0_type;
				il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
				bool L_8;
				L_8 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_6, L_7, NULL);
				if (!L_8)
				{
					goto IL_0043_1;
				}
			}
			{
				// return pair.Key;
				InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_9;
				L_9 = KeyValuePair_2_get_Key_mE8768535ABCD24F453DC1EC5127CBD303DEC29A5_inline((&V_1), KeyValuePair_2_get_Key_mE8768535ABCD24F453DC1EC5127CBD303DEC29A5_RuntimeMethod_var);
				V_2 = L_9;
				goto IL_0066;
			}

IL_0043_1:
			{
				// foreach (var pair in table)
				bool L_10;
				L_10 = Enumerator_MoveNext_mEB31860F9718BC0DB2D231F91D9A78D9666B54EF((&V_0), Enumerator_MoveNext_mEB31860F9718BC0DB2D231F91D9A78D9666B54EF_RuntimeMethod_var);
				if (L_10)
				{
					goto IL_0022_1;
				}
			}
			{
				goto IL_005c;
			}
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_005c:
	{
		// return new InternedString();
		il2cpp_codegen_initobj((&V_3), sizeof(InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735));
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_11 = V_3;
		return L_11;
	}

IL_0066:
	{
		// }
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_12 = V_2;
		return L_12;
	}
}
IL2CPP_EXTERN_C  InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 TypeTable_FindNameForType_m5974594EAAEB68C4488B8C9CFABF931B7666FB00_AdjustorThunk (RuntimeObject* __this, Type_t* ___0_type, const RuntimeMethod* method)
{
	TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E*>(__this + _offset);
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 _returnValue;
	_returnValue = TypeTable_FindNameForType_m5974594EAAEB68C4488B8C9CFABF931B7666FB00(_thisAdjusted, ___0_type, method);
	return _returnValue;
}
// System.Void UnityEngine.InputSystem.Utilities.TypeTable::AddTypeRegistration(System.String,System.Type)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TypeTable_AddTypeRegistration_mAC83549CC944F2EE8371A00B82B203B9B8DD5B7E (TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_set_Item_mACF6DD3A83F9F41061E7C4DD48F58C07BFAA31C7_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		// if (string.IsNullOrEmpty(name))
		String_t* L_0 = ___0_name;
		bool L_1;
		L_1 = String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478(L_0, NULL);
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		// throw new ArgumentException("Name cannot be null or empty", nameof(name));
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_2 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		NullCheck(L_2);
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF4D7DE161067DE7FFAB264EC7D3DCF921ADBA5A5)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralCE18B047107AA23D1AA9B2ED32D316148E02655F)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&TypeTable_AddTypeRegistration_mAC83549CC944F2EE8371A00B82B203B9B8DD5B7E_RuntimeMethod_var)));
	}

IL_0018:
	{
		// if (type == null)
		Type_t* L_3 = ___1_type;
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_3, (Type_t*)NULL, NULL);
		if (!L_4)
		{
			goto IL_002c;
		}
	}
	{
		// throw new ArgumentNullException(nameof(type));
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_5 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		NullCheck(L_5);
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_5, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF3C6C902DBF80139640F6554F0C3392016A8ADF7)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_5, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&TypeTable_AddTypeRegistration_mAC83549CC944F2EE8371A00B82B203B9B8DD5B7E_RuntimeMethod_var)));
	}

IL_002c:
	{
		// var internedName = new InternedString(name);
		String_t* L_6 = ___0_name;
		InternedString__ctor_m2E9672D46D84C82F705DE799CE8B6123EB95E935((&V_0), L_6, NULL);
		// table[internedName] = type;
		Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D* L_7 = __this->___table_0;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_8 = V_0;
		Type_t* L_9 = ___1_type;
		NullCheck(L_7);
		Dictionary_2_set_Item_mACF6DD3A83F9F41061E7C4DD48F58C07BFAA31C7(L_7, L_8, L_9, Dictionary_2_set_Item_mACF6DD3A83F9F41061E7C4DD48F58C07BFAA31C7_RuntimeMethod_var);
		// }
		return;
	}
}
IL2CPP_EXTERN_C  void TypeTable_AddTypeRegistration_mAC83549CC944F2EE8371A00B82B203B9B8DD5B7E_AdjustorThunk (RuntimeObject* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method)
{
	TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E*>(__this + _offset);
	TypeTable_AddTypeRegistration_mAC83549CC944F2EE8371A00B82B203B9B8DD5B7E(_thisAdjusted, ___0_name, ___1_type, method);
}
// System.Type UnityEngine.InputSystem.Utilities.TypeTable::LookupTypeRegistration(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* TypeTable_LookupTypeRegistration_m89DCEA471CDF7CDB994D67D3726482805C0AE29A (TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E* __this, String_t* ___0_name, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_TryGetValue_m4AFE96490465DE101600F734AF44C7E4AE513860_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 V_0;
	memset((&V_0), 0, sizeof(V_0));
	Type_t* V_1 = NULL;
	{
		// if (string.IsNullOrEmpty(name))
		String_t* L_0 = ___0_name;
		bool L_1;
		L_1 = String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478(L_0, NULL);
		if (!L_1)
		{
			goto IL_000a;
		}
	}
	{
		// return null;
		return (Type_t*)NULL;
	}

IL_000a:
	{
		// if (table == null)
		Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D* L_2 = __this->___table_0;
		if (L_2)
		{
			goto IL_001d;
		}
	}
	{
		// throw new InvalidOperationException("Input System not yet initialized");
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_3 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		NullCheck(L_3);
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF58E021D305C0B41C91B9C363C9DBF5F652FDAE9)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&TypeTable_LookupTypeRegistration_m89DCEA471CDF7CDB994D67D3726482805C0AE29A_RuntimeMethod_var)));
	}

IL_001d:
	{
		// var internedName = new InternedString(name);
		String_t* L_4 = ___0_name;
		InternedString__ctor_m2E9672D46D84C82F705DE799CE8B6123EB95E935((&V_0), L_4, NULL);
		// if (table.TryGetValue(internedName, out var type))
		Dictionary_2_t1FFEE4C9AF6AF524CAD4FDCEA8F3AB34E585451D* L_5 = __this->___table_0;
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_6 = V_0;
		NullCheck(L_5);
		bool L_7;
		L_7 = Dictionary_2_TryGetValue_m4AFE96490465DE101600F734AF44C7E4AE513860(L_5, L_6, (&V_1), Dictionary_2_TryGetValue_m4AFE96490465DE101600F734AF44C7E4AE513860_RuntimeMethod_var);
		if (!L_7)
		{
			goto IL_0037;
		}
	}
	{
		// return type;
		Type_t* L_8 = V_1;
		return L_8;
	}

IL_0037:
	{
		// return null;
		return (Type_t*)NULL;
	}
}
IL2CPP_EXTERN_C  Type_t* TypeTable_LookupTypeRegistration_m89DCEA471CDF7CDB994D67D3726482805C0AE29A_AdjustorThunk (RuntimeObject* __this, String_t* ___0_name, const RuntimeMethod* method)
{
	TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<TypeTable_tEAC1ECAD849469DEA65DA2FC65B19C2D4739B67E*>(__this + _offset);
	Type_t* _returnValue;
	_returnValue = TypeTable_LookupTypeRegistration_m89DCEA471CDF7CDB994D67D3726482805C0AE29A(_thisAdjusted, ___0_name, method);
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
// System.Void UnityEngine.InputSystem.Utilities.TypeTable/<>c::.cctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__cctor_mAD0F0023FEF4044713EBAEF65A689FAFBF1547D0 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA* L_0 = (U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA*)il2cpp_codegen_object_new(U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		U3CU3Ec__ctor_m272D75733C8074A4CB8134DEB9A4BD7442005F5A(L_0, NULL);
		((U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA_il2cpp_TypeInfo_var))->___U3CU3E9_0 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA_il2cpp_TypeInfo_var))->___U3CU3E9_0), (void*)L_0);
		return;
	}
}
// System.Void UnityEngine.InputSystem.Utilities.TypeTable/<>c::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__ctor_m272D75733C8074A4CB8134DEB9A4BD7442005F5A (U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
// System.String UnityEngine.InputSystem.Utilities.TypeTable/<>c::<get_names>b__2_0(UnityEngine.InputSystem.Utilities.InternedString)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* U3CU3Ec_U3Cget_namesU3Eb__2_0_m106D3E5FF1FBF96009877C31E3F0684CD8943EC9 (U3CU3Ec_t77EE13A2DF0F0EE25274DE8AA8898CF60A1ECEBA* __this, InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 ___0_x, const RuntimeMethod* method) 
{
	{
		// public IEnumerable<string> names => table.Keys.Select(x => x.ToString());
		String_t* L_0;
		L_0 = InternedString_ToString_mED327D67EF001C5EDFF284336F13C3E3F025993A((&___0_x), NULL);
		return L_0;
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
// System.Single UnityEngine.InputSystem.Composites.AxisComposite::get_midPoint()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float AxisComposite_get_midPoint_m95E5A7ADEDF11A5E0946073FE3EB3DBB56E9C14B (AxisComposite_t9E3B9C369A8F748691611245821471645D31D2AC* __this, const RuntimeMethod* method) 
{
	{
		// public float midPoint => (maxValue + minValue) / 2;
		float L_0 = __this->___maxValue_4;
		float L_1 = __this->___minValue_3;
		return ((float)(((float)il2cpp_codegen_add(L_0, L_1))/(2.0f)));
	}
}
// System.Single UnityEngine.InputSystem.Composites.AxisComposite::ReadValue(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float AxisComposite_ReadValue_mB6A4941AFFFB504B7F2A49C83C86633A6178994E (AxisComposite_t9E3B9C369A8F748691611245821471645D31D2AC* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	float V_0 = 0.0f;
	float V_1 = 0.0f;
	bool V_2 = false;
	bool V_3 = false;
	float V_4 = 0.0f;
	int32_t V_5 = 0;
	{
		// var negativeValue = Mathf.Abs(context.ReadValue<float>(negative));
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_0 = ___0_context;
		int32_t L_1 = __this->___negative_1;
		float L_2;
		L_2 = InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648(L_0, L_1, InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648_RuntimeMethod_var);
		float L_3;
		L_3 = fabsf(L_2);
		V_0 = L_3;
		// var positiveValue = Mathf.Abs(context.ReadValue<float>(positive));
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_4 = ___0_context;
		int32_t L_5 = __this->___positive_2;
		float L_6;
		L_6 = InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648(L_4, L_5, InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648_RuntimeMethod_var);
		float L_7;
		L_7 = fabsf(L_6);
		V_1 = L_7;
		// var negativeIsActuated = negativeValue > Mathf.Epsilon;
		float L_8 = V_0;
		float L_9 = ((Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682_StaticFields*)il2cpp_codegen_static_fields_for(Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682_il2cpp_TypeInfo_var))->___Epsilon_0;
		V_2 = (bool)((((float)L_8) > ((float)L_9))? 1 : 0);
		// var positiveIsActuated = positiveValue > Mathf.Epsilon;
		float L_10 = V_1;
		float L_11 = ((Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682_StaticFields*)il2cpp_codegen_static_fields_for(Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682_il2cpp_TypeInfo_var))->___Epsilon_0;
		V_3 = (bool)((((float)L_10) > ((float)L_11))? 1 : 0);
		// if (negativeIsActuated == positiveIsActuated)
		bool L_12 = V_2;
		bool L_13 = V_3;
		if ((!(((uint32_t)L_12) == ((uint32_t)L_13))))
		{
			goto IL_0066;
		}
	}
	{
		// switch (whichSideWins)
		int32_t L_14 = __this->___whichSideWins_5;
		V_5 = L_14;
		int32_t L_15 = V_5;
		switch (L_15)
		{
			case 0:
			{
				goto IL_005f;
			}
			case 1:
			{
				goto IL_005b;
			}
			case 2:
			{
				goto IL_0057;
			}
		}
	}
	{
		goto IL_0066;
	}

IL_0057:
	{
		// positiveIsActuated = false;
		V_3 = (bool)0;
		// break;
		goto IL_0066;
	}

IL_005b:
	{
		// negativeIsActuated = false;
		V_2 = (bool)0;
		// break;
		goto IL_0066;
	}

IL_005f:
	{
		// return midPoint;
		float L_16;
		L_16 = AxisComposite_get_midPoint_m95E5A7ADEDF11A5E0946073FE3EB3DBB56E9C14B(__this, NULL);
		return L_16;
	}

IL_0066:
	{
		// var mid = midPoint;
		float L_17;
		L_17 = AxisComposite_get_midPoint_m95E5A7ADEDF11A5E0946073FE3EB3DBB56E9C14B(__this, NULL);
		V_4 = L_17;
		// if (negativeIsActuated)
		bool L_18 = V_2;
		if (!L_18)
		{
			goto IL_0080;
		}
	}
	{
		// return mid - (mid - minValue) * negativeValue;
		float L_19 = V_4;
		float L_20 = V_4;
		float L_21 = __this->___minValue_3;
		float L_22 = V_0;
		return ((float)il2cpp_codegen_subtract(L_19, ((float)il2cpp_codegen_multiply(((float)il2cpp_codegen_subtract(L_20, L_21)), L_22))));
	}

IL_0080:
	{
		// return mid + (maxValue - mid) * positiveValue;
		float L_23 = V_4;
		float L_24 = __this->___maxValue_4;
		float L_25 = V_4;
		float L_26 = V_1;
		return ((float)il2cpp_codegen_add(L_23, ((float)il2cpp_codegen_multiply(((float)il2cpp_codegen_subtract(L_24, L_25)), L_26))));
	}
}
// System.Single UnityEngine.InputSystem.Composites.AxisComposite::EvaluateMagnitude(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float AxisComposite_EvaluateMagnitude_mC09E5455DCA8A7E4B1001E378382A66C2DADAA48 (AxisComposite_t9E3B9C369A8F748691611245821471645D31D2AC* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) 
{
	float V_0 = 0.0f;
	{
		// var value = ReadValue(ref context);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_0 = ___0_context;
		float L_1;
		L_1 = VirtualFuncInvoker1< float, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* >::Invoke(10 /* TValue UnityEngine.InputSystem.InputBindingComposite`1<System.Single>::ReadValue(UnityEngine.InputSystem.InputBindingCompositeContext&) */, __this, L_0);
		V_0 = L_1;
		// if (value < midPoint)
		float L_2 = V_0;
		float L_3;
		L_3 = AxisComposite_get_midPoint_m95E5A7ADEDF11A5E0946073FE3EB3DBB56E9C14B(__this, NULL);
		if ((!(((float)L_2) < ((float)L_3))))
		{
			goto IL_003b;
		}
	}
	{
		// value = Mathf.Abs(value - midPoint);
		float L_4 = V_0;
		float L_5;
		L_5 = AxisComposite_get_midPoint_m95E5A7ADEDF11A5E0946073FE3EB3DBB56E9C14B(__this, NULL);
		float L_6;
		L_6 = fabsf(((float)il2cpp_codegen_subtract(L_4, L_5)));
		V_0 = L_6;
		// return NormalizeProcessor.Normalize(value, 0, Mathf.Abs(minValue), 0);
		float L_7 = V_0;
		float L_8 = __this->___minValue_3;
		float L_9;
		L_9 = fabsf(L_8);
		float L_10;
		L_10 = NormalizeProcessor_Normalize_m6B8C94BD2D8640D46A0EFD1FF10B4E311C46DBEB(L_7, (0.0f), L_9, (0.0f), NULL);
		return L_10;
	}

IL_003b:
	{
		// value = Mathf.Abs(value - midPoint);
		float L_11 = V_0;
		float L_12;
		L_12 = AxisComposite_get_midPoint_m95E5A7ADEDF11A5E0946073FE3EB3DBB56E9C14B(__this, NULL);
		float L_13;
		L_13 = fabsf(((float)il2cpp_codegen_subtract(L_11, L_12)));
		V_0 = L_13;
		// return NormalizeProcessor.Normalize(value, 0, Mathf.Abs(maxValue), 0);
		float L_14 = V_0;
		float L_15 = __this->___maxValue_4;
		float L_16;
		L_16 = fabsf(L_15);
		float L_17;
		L_17 = NormalizeProcessor_Normalize_m6B8C94BD2D8640D46A0EFD1FF10B4E311C46DBEB(L_14, (0.0f), L_16, (0.0f), NULL);
		return L_17;
	}
}
// System.Void UnityEngine.InputSystem.Composites.AxisComposite::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AxisComposite__ctor_m4E736548F5FF6FD260080DB105A10CE59E447EC2 (AxisComposite_t9E3B9C369A8F748691611245821471645D31D2AC* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&InputBindingComposite_1__ctor_m652D65F50D8E8B067F415C8EB34CBB411E3037C8_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public float minValue = -1;
		__this->___minValue_3 = (-1.0f);
		// public float maxValue = 1;
		__this->___maxValue_4 = (1.0f);
		InputBindingComposite_1__ctor_m652D65F50D8E8B067F415C8EB34CBB411E3037C8(__this, InputBindingComposite_1__ctor_m652D65F50D8E8B067F415C8EB34CBB411E3037C8_RuntimeMethod_var);
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
// System.Single UnityEngine.InputSystem.Composites.ButtonWithOneModifier::ReadValue(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float ButtonWithOneModifier_ReadValue_m439AB954F407DC5590C539DD486A04624AA07791 (ButtonWithOneModifier_t407B77B4960C57B1DEC84F631F91B1E135343222* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (ModifierIsPressed(ref context))
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_0 = ___0_context;
		bool L_1;
		L_1 = ButtonWithOneModifier_ModifierIsPressed_mEAF7D55D5DFF9A23D2F467E889EDFF82355E8E80(__this, L_0, NULL);
		if (!L_1)
		{
			goto IL_0016;
		}
	}
	{
		// return context.ReadValue<float>(button);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_2 = ___0_context;
		int32_t L_3 = __this->___button_2;
		float L_4;
		L_4 = InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648(L_2, L_3, InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648_RuntimeMethod_var);
		return L_4;
	}

IL_0016:
	{
		// return default;
		return (0.0f);
	}
}
// System.Boolean UnityEngine.InputSystem.Composites.ButtonWithOneModifier::ModifierIsPressed(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ButtonWithOneModifier_ModifierIsPressed_mEAF7D55D5DFF9A23D2F467E889EDFF82355E8E80 (ButtonWithOneModifier_t407B77B4960C57B1DEC84F631F91B1E135343222* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) 
{
	bool V_0 = false;
	double V_1 = 0.0;
	{
		// var modifierDown = context.ReadValueAsButton(modifier);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_0 = ___0_context;
		int32_t L_1 = __this->___modifier_1;
		bool L_2;
		L_2 = InputBindingCompositeContext_ReadValueAsButton_mD3F30463AD217008C8DC0F42BA59BDC8EB37D0DB(L_0, L_1, NULL);
		V_0 = L_2;
		// if (modifierDown && !overrideModifiersNeedToBePressedFirst)
		bool L_3 = V_0;
		if (!L_3)
		{
			goto IL_0038;
		}
	}
	{
		bool L_4 = __this->___overrideModifiersNeedToBePressedFirst_3;
		if (L_4)
		{
			goto IL_0038;
		}
	}
	{
		// var timestamp = context.GetPressTime(button);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_5 = ___0_context;
		int32_t L_6 = __this->___button_2;
		double L_7;
		L_7 = InputBindingCompositeContext_GetPressTime_mA919F3E37F086C2BFEEB6EB17A75B1A6CFF2E58A(L_5, L_6, NULL);
		V_1 = L_7;
		// var timestamp1 = context.GetPressTime(modifier);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_8 = ___0_context;
		int32_t L_9 = __this->___modifier_1;
		double L_10;
		L_10 = InputBindingCompositeContext_GetPressTime_mA919F3E37F086C2BFEEB6EB17A75B1A6CFF2E58A(L_8, L_9, NULL);
		// return timestamp1 <= timestamp;
		double L_11 = V_1;
		return (bool)((((int32_t)((!(((double)L_10) <= ((double)L_11)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0038:
	{
		// return modifierDown;
		bool L_12 = V_0;
		return L_12;
	}
}
// System.Single UnityEngine.InputSystem.Composites.ButtonWithOneModifier::EvaluateMagnitude(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float ButtonWithOneModifier_EvaluateMagnitude_m5620878936698B7CB4AD5BBD698EC2FF062A9505 (ButtonWithOneModifier_t407B77B4960C57B1DEC84F631F91B1E135343222* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) 
{
	{
		// return ReadValue(ref context);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_0 = ___0_context;
		float L_1;
		L_1 = VirtualFuncInvoker1< float, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* >::Invoke(10 /* TValue UnityEngine.InputSystem.InputBindingComposite`1<System.Single>::ReadValue(UnityEngine.InputSystem.InputBindingCompositeContext&) */, __this, L_0);
		return L_1;
	}
}
// System.Void UnityEngine.InputSystem.Composites.ButtonWithOneModifier::FinishSetup(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ButtonWithOneModifier_FinishSetup_m92274A88D5AEAA4436E4009B0B32533331B0C968 (ButtonWithOneModifier_t407B77B4960C57B1DEC84F631F91B1E135343222* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&InputSystem_t4120CA4FE7DCFD56AF9391933FC3F1F485350164_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!overrideModifiersNeedToBePressedFirst)
		bool L_0 = __this->___overrideModifiersNeedToBePressedFirst_3;
		if (L_0)
		{
			goto IL_001b;
		}
	}
	{
		// overrideModifiersNeedToBePressedFirst = !InputSystem.settings.shortcutKeysConsumeInput;
		il2cpp_codegen_runtime_class_init_inline(InputSystem_t4120CA4FE7DCFD56AF9391933FC3F1F485350164_il2cpp_TypeInfo_var);
		InputSettings_tBA8835B505722A59702A08BCBA46ECF0B0274EEF* L_1;
		L_1 = InputSystem_get_settings_m8E3E9C0907904CBDBAE96354142AB0A87C7A3B74(NULL);
		NullCheck(L_1);
		bool L_2;
		L_2 = InputSettings_get_shortcutKeysConsumeInput_m916DC677CCE3E4F3AD3BA48C5723965007CBE670_inline(L_1, NULL);
		__this->___overrideModifiersNeedToBePressedFirst_3 = (bool)((((int32_t)L_2) == ((int32_t)0))? 1 : 0);
	}

IL_001b:
	{
		// }
		return;
	}
}
// System.Void UnityEngine.InputSystem.Composites.ButtonWithOneModifier::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ButtonWithOneModifier__ctor_m7B7F85E23B5C441609E4155452F6D4AC05E2B639 (ButtonWithOneModifier_t407B77B4960C57B1DEC84F631F91B1E135343222* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&InputBindingComposite_1__ctor_m652D65F50D8E8B067F415C8EB34CBB411E3037C8_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		InputBindingComposite_1__ctor_m652D65F50D8E8B067F415C8EB34CBB411E3037C8(__this, InputBindingComposite_1__ctor_m652D65F50D8E8B067F415C8EB34CBB411E3037C8_RuntimeMethod_var);
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
// System.Single UnityEngine.InputSystem.Composites.ButtonWithTwoModifiers::ReadValue(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float ButtonWithTwoModifiers_ReadValue_m37221E24FA2D2429BABF071D71DA89E255B8CBA9 (ButtonWithTwoModifiers_tCA30378981527D0F306883EABED0657FA5FE7C59* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (ModifiersArePressed(ref context))
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_0 = ___0_context;
		bool L_1;
		L_1 = ButtonWithTwoModifiers_ModifiersArePressed_m0713025DE1116397F560856674D56D3D228C781E(__this, L_0, NULL);
		if (!L_1)
		{
			goto IL_0016;
		}
	}
	{
		// return context.ReadValue<float>(button);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_2 = ___0_context;
		int32_t L_3 = __this->___button_3;
		float L_4;
		L_4 = InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648(L_2, L_3, InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648_RuntimeMethod_var);
		return L_4;
	}

IL_0016:
	{
		// return default;
		return (0.0f);
	}
}
// System.Boolean UnityEngine.InputSystem.Composites.ButtonWithTwoModifiers::ModifiersArePressed(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ButtonWithTwoModifiers_ModifiersArePressed_m0713025DE1116397F560856674D56D3D228C781E (ButtonWithTwoModifiers_tCA30378981527D0F306883EABED0657FA5FE7C59* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) 
{
	bool V_0 = false;
	double V_1 = 0.0;
	double V_2 = 0.0;
	int32_t G_B3_0 = 0;
	{
		// var modifiersDown = context.ReadValueAsButton(modifier1) && context.ReadValueAsButton(modifier2);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_0 = ___0_context;
		int32_t L_1 = __this->___modifier1_1;
		bool L_2;
		L_2 = InputBindingCompositeContext_ReadValueAsButton_mD3F30463AD217008C8DC0F42BA59BDC8EB37D0DB(L_0, L_1, NULL);
		if (!L_2)
		{
			goto IL_001c;
		}
	}
	{
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_3 = ___0_context;
		int32_t L_4 = __this->___modifier2_2;
		bool L_5;
		L_5 = InputBindingCompositeContext_ReadValueAsButton_mD3F30463AD217008C8DC0F42BA59BDC8EB37D0DB(L_3, L_4, NULL);
		G_B3_0 = ((int32_t)(L_5));
		goto IL_001d;
	}

IL_001c:
	{
		G_B3_0 = 0;
	}

IL_001d:
	{
		V_0 = (bool)G_B3_0;
		// if (modifiersDown && !overrideModifiersNeedToBePressedFirst)
		bool L_6 = V_0;
		if (!L_6)
		{
			goto IL_005c;
		}
	}
	{
		bool L_7 = __this->___overrideModifiersNeedToBePressedFirst_4;
		if (L_7)
		{
			goto IL_005c;
		}
	}
	{
		// var timestamp = context.GetPressTime(button);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_8 = ___0_context;
		int32_t L_9 = __this->___button_3;
		double L_10;
		L_10 = InputBindingCompositeContext_GetPressTime_mA919F3E37F086C2BFEEB6EB17A75B1A6CFF2E58A(L_8, L_9, NULL);
		V_1 = L_10;
		// var timestamp1 = context.GetPressTime(modifier1);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_11 = ___0_context;
		int32_t L_12 = __this->___modifier1_1;
		double L_13;
		L_13 = InputBindingCompositeContext_GetPressTime_mA919F3E37F086C2BFEEB6EB17A75B1A6CFF2E58A(L_11, L_12, NULL);
		// var timestamp2 = context.GetPressTime(modifier2);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_14 = ___0_context;
		int32_t L_15 = __this->___modifier2_2;
		double L_16;
		L_16 = InputBindingCompositeContext_GetPressTime_mA919F3E37F086C2BFEEB6EB17A75B1A6CFF2E58A(L_14, L_15, NULL);
		V_2 = L_16;
		// return timestamp1 <= timestamp && timestamp2 <= timestamp;
		double L_17 = V_1;
		if ((!(((double)L_13) <= ((double)L_17))))
		{
			goto IL_005a;
		}
	}
	{
		double L_18 = V_2;
		double L_19 = V_1;
		return (bool)((((int32_t)((!(((double)L_18) <= ((double)L_19)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_005a:
	{
		return (bool)0;
	}

IL_005c:
	{
		// return modifiersDown;
		bool L_20 = V_0;
		return L_20;
	}
}
// System.Single UnityEngine.InputSystem.Composites.ButtonWithTwoModifiers::EvaluateMagnitude(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float ButtonWithTwoModifiers_EvaluateMagnitude_mFA7A056972DA25A3D63AB79E19E366F3F68DB900 (ButtonWithTwoModifiers_tCA30378981527D0F306883EABED0657FA5FE7C59* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) 
{
	{
		// return ReadValue(ref context);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_0 = ___0_context;
		float L_1;
		L_1 = VirtualFuncInvoker1< float, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* >::Invoke(10 /* TValue UnityEngine.InputSystem.InputBindingComposite`1<System.Single>::ReadValue(UnityEngine.InputSystem.InputBindingCompositeContext&) */, __this, L_0);
		return L_1;
	}
}
// System.Void UnityEngine.InputSystem.Composites.ButtonWithTwoModifiers::FinishSetup(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ButtonWithTwoModifiers_FinishSetup_m72B6515E3E75435A6F0E533DFEEEDCF987315568 (ButtonWithTwoModifiers_tCA30378981527D0F306883EABED0657FA5FE7C59* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&InputSystem_t4120CA4FE7DCFD56AF9391933FC3F1F485350164_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!overrideModifiersNeedToBePressedFirst)
		bool L_0 = __this->___overrideModifiersNeedToBePressedFirst_4;
		if (L_0)
		{
			goto IL_001b;
		}
	}
	{
		// overrideModifiersNeedToBePressedFirst = !InputSystem.settings.shortcutKeysConsumeInput;
		il2cpp_codegen_runtime_class_init_inline(InputSystem_t4120CA4FE7DCFD56AF9391933FC3F1F485350164_il2cpp_TypeInfo_var);
		InputSettings_tBA8835B505722A59702A08BCBA46ECF0B0274EEF* L_1;
		L_1 = InputSystem_get_settings_m8E3E9C0907904CBDBAE96354142AB0A87C7A3B74(NULL);
		NullCheck(L_1);
		bool L_2;
		L_2 = InputSettings_get_shortcutKeysConsumeInput_m916DC677CCE3E4F3AD3BA48C5723965007CBE670_inline(L_1, NULL);
		__this->___overrideModifiersNeedToBePressedFirst_4 = (bool)((((int32_t)L_2) == ((int32_t)0))? 1 : 0);
	}

IL_001b:
	{
		// }
		return;
	}
}
// System.Void UnityEngine.InputSystem.Composites.ButtonWithTwoModifiers::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ButtonWithTwoModifiers__ctor_m200626B0BEBB78BC03D64F561D3727DE1D2D5325 (ButtonWithTwoModifiers_tCA30378981527D0F306883EABED0657FA5FE7C59* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&InputBindingComposite_1__ctor_m652D65F50D8E8B067F415C8EB34CBB411E3037C8_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		InputBindingComposite_1__ctor_m652D65F50D8E8B067F415C8EB34CBB411E3037C8(__this, InputBindingComposite_1__ctor_m652D65F50D8E8B067F415C8EB34CBB411E3037C8_RuntimeMethod_var);
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
// System.Type UnityEngine.InputSystem.Composites.OneModifierComposite::get_valueType()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* OneModifierComposite_get_valueType_m5E2ABFE018FE89563F657E18C3DCB5EEA8BF2673 (OneModifierComposite_tC18745AC641308E913620A321BF1CCE00D60E55B* __this, const RuntimeMethod* method) 
{
	{
		// public override Type valueType => m_ValueType;
		Type_t* L_0 = __this->___m_ValueType_5;
		return L_0;
	}
}
// System.Int32 UnityEngine.InputSystem.Composites.OneModifierComposite::get_valueSizeInBytes()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OneModifierComposite_get_valueSizeInBytes_m910E77B6AB3AAF8E47F0DA92CD16C47784E66A1C (OneModifierComposite_tC18745AC641308E913620A321BF1CCE00D60E55B* __this, const RuntimeMethod* method) 
{
	{
		// public override int valueSizeInBytes => m_ValueSizeInBytes;
		int32_t L_0 = __this->___m_ValueSizeInBytes_4;
		return L_0;
	}
}
// System.Single UnityEngine.InputSystem.Composites.OneModifierComposite::EvaluateMagnitude(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float OneModifierComposite_EvaluateMagnitude_mA42D5A4588ED01010B8642529A70E665BB9C6923 (OneModifierComposite_tC18745AC641308E913620A321BF1CCE00D60E55B* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) 
{
	{
		// if (ModifierIsPressed(ref context))
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_0 = ___0_context;
		bool L_1;
		L_1 = OneModifierComposite_ModifierIsPressed_m25EEA39878124B169F67C7A2752EBD7890F44C48(__this, L_0, NULL);
		if (!L_1)
		{
			goto IL_0016;
		}
	}
	{
		// return context.EvaluateMagnitude(binding);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_2 = ___0_context;
		int32_t L_3 = __this->___binding_2;
		float L_4;
		L_4 = InputBindingCompositeContext_EvaluateMagnitude_m418436D265278E622B80FD3CB6E6366F5DDD2E1A(L_2, L_3, NULL);
		return L_4;
	}

IL_0016:
	{
		// return default;
		return (0.0f);
	}
}
// System.Void UnityEngine.InputSystem.Composites.OneModifierComposite::ReadValue(UnityEngine.InputSystem.InputBindingCompositeContext&,System.Void*,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OneModifierComposite_ReadValue_mFFCA6F249ACC7FB1137FC8DC42FEF8893AF5764B (OneModifierComposite_tC18745AC641308E913620A321BF1CCE00D60E55B* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, void* ___1_buffer, int32_t ___2_bufferSize, const RuntimeMethod* method) 
{
	{
		// if (ModifierIsPressed(ref context))
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_0 = ___0_context;
		bool L_1;
		L_1 = OneModifierComposite_ModifierIsPressed_m25EEA39878124B169F67C7A2752EBD7890F44C48(__this, L_0, NULL);
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		// context.ReadValue(binding, buffer, bufferSize);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_2 = ___0_context;
		int32_t L_3 = __this->___binding_2;
		void* L_4 = ___1_buffer;
		int32_t L_5 = ___2_bufferSize;
		InputBindingCompositeContext_ReadValue_mC797CA9EDA827FF511B0771EEF21F1B271CF16D8(L_2, L_3, L_4, L_5, NULL);
		return;
	}

IL_0018:
	{
		// UnsafeUtility.MemClear(buffer, m_ValueSizeInBytes);
		void* L_6 = ___1_buffer;
		int32_t L_7 = __this->___m_ValueSizeInBytes_4;
		UnsafeUtility_MemClear_m6C4377117084A11A667A567BC2F5E606A632A7C1(L_6, ((int64_t)L_7), NULL);
		// }
		return;
	}
}
// System.Boolean UnityEngine.InputSystem.Composites.OneModifierComposite::ModifierIsPressed(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool OneModifierComposite_ModifierIsPressed_m25EEA39878124B169F67C7A2752EBD7890F44C48 (OneModifierComposite_tC18745AC641308E913620A321BF1CCE00D60E55B* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) 
{
	bool V_0 = false;
	double V_1 = 0.0;
	{
		// var modifierDown = context.ReadValueAsButton(modifier);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_0 = ___0_context;
		int32_t L_1 = __this->___modifier_1;
		bool L_2;
		L_2 = InputBindingCompositeContext_ReadValueAsButton_mD3F30463AD217008C8DC0F42BA59BDC8EB37D0DB(L_0, L_1, NULL);
		V_0 = L_2;
		// if (modifierDown && m_BindingIsButton && !overrideModifiersNeedToBePressedFirst)
		bool L_3 = V_0;
		if (!L_3)
		{
			goto IL_0040;
		}
	}
	{
		bool L_4 = __this->___m_BindingIsButton_6;
		if (!L_4)
		{
			goto IL_0040;
		}
	}
	{
		bool L_5 = __this->___overrideModifiersNeedToBePressedFirst_3;
		if (L_5)
		{
			goto IL_0040;
		}
	}
	{
		// var timestamp = context.GetPressTime(binding);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_6 = ___0_context;
		int32_t L_7 = __this->___binding_2;
		double L_8;
		L_8 = InputBindingCompositeContext_GetPressTime_mA919F3E37F086C2BFEEB6EB17A75B1A6CFF2E58A(L_6, L_7, NULL);
		V_1 = L_8;
		// var timestamp1 = context.GetPressTime(modifier);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_9 = ___0_context;
		int32_t L_10 = __this->___modifier_1;
		double L_11;
		L_11 = InputBindingCompositeContext_GetPressTime_mA919F3E37F086C2BFEEB6EB17A75B1A6CFF2E58A(L_9, L_10, NULL);
		// return timestamp1 <= timestamp;
		double L_12 = V_1;
		return (bool)((((int32_t)((!(((double)L_11) <= ((double)L_12)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0040:
	{
		// return modifierDown;
		bool L_13 = V_0;
		return L_13;
	}
}
// System.Void UnityEngine.InputSystem.Composites.OneModifierComposite::FinishSetup(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OneModifierComposite_FinishSetup_m91EE0D3C7261D70C6C72173F1F18650A9C007620 (OneModifierComposite_tC18745AC641308E913620A321BF1CCE00D60E55B* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&InputSystem_t4120CA4FE7DCFD56AF9391933FC3F1F485350164_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// DetermineValueTypeAndSize(ref context, binding, out m_ValueType, out m_ValueSizeInBytes, out m_BindingIsButton);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_0 = ___0_context;
		int32_t L_1 = __this->___binding_2;
		Type_t** L_2 = (Type_t**)(&__this->___m_ValueType_5);
		int32_t* L_3 = (int32_t*)(&__this->___m_ValueSizeInBytes_4);
		bool* L_4 = (bool*)(&__this->___m_BindingIsButton_6);
		OneModifierComposite_DetermineValueTypeAndSize_m872B0A8E5DEA6864048B0D08DE31FFBA40C442AA(L_0, L_1, L_2, L_3, L_4, NULL);
		// if (!overrideModifiersNeedToBePressedFirst)
		bool L_5 = __this->___overrideModifiersNeedToBePressedFirst_3;
		if (L_5)
		{
			goto IL_0039;
		}
	}
	{
		// overrideModifiersNeedToBePressedFirst = !InputSystem.settings.shortcutKeysConsumeInput;
		il2cpp_codegen_runtime_class_init_inline(InputSystem_t4120CA4FE7DCFD56AF9391933FC3F1F485350164_il2cpp_TypeInfo_var);
		InputSettings_tBA8835B505722A59702A08BCBA46ECF0B0274EEF* L_6;
		L_6 = InputSystem_get_settings_m8E3E9C0907904CBDBAE96354142AB0A87C7A3B74(NULL);
		NullCheck(L_6);
		bool L_7;
		L_7 = InputSettings_get_shortcutKeysConsumeInput_m916DC677CCE3E4F3AD3BA48C5723965007CBE670_inline(L_6, NULL);
		__this->___overrideModifiersNeedToBePressedFirst_3 = (bool)((((int32_t)L_7) == ((int32_t)0))? 1 : 0);
	}

IL_0039:
	{
		// }
		return;
	}
}
// System.Object UnityEngine.InputSystem.Composites.OneModifierComposite::ReadValueAsObject(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* OneModifierComposite_ReadValueAsObject_mE7F10A702C1FC6CF14A127CB653733BE056C445B (OneModifierComposite_tC18745AC641308E913620A321BF1CCE00D60E55B* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) 
{
	{
		// if (context.ReadValueAsButton(modifier))
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_0 = ___0_context;
		int32_t L_1 = __this->___modifier_1;
		bool L_2;
		L_2 = InputBindingCompositeContext_ReadValueAsButton_mD3F30463AD217008C8DC0F42BA59BDC8EB37D0DB(L_0, L_1, NULL);
		if (!L_2)
		{
			goto IL_001b;
		}
	}
	{
		// return context.ReadValueAsObject(binding);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_3 = ___0_context;
		int32_t L_4 = __this->___binding_2;
		RuntimeObject* L_5;
		L_5 = InputBindingCompositeContext_ReadValueAsObject_mB707A8B03313DBFE4A3DF4867FE6A20AAAFB1882(L_3, L_4, NULL);
		return L_5;
	}

IL_001b:
	{
		// return null;
		return NULL;
	}
}
// System.Void UnityEngine.InputSystem.Composites.OneModifierComposite::DetermineValueTypeAndSize(UnityEngine.InputSystem.InputBindingCompositeContext&,System.Int32,System.Type&,System.Int32&,System.Boolean&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OneModifierComposite_DetermineValueTypeAndSize_m872B0A8E5DEA6864048B0D08DE31FFBA40C442AA (InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, int32_t ___1_part, Type_t** ___2_valueType, int32_t* ___3_valueSizeInBytes, bool* ___4_isButton, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerable_1_t45141F64D6D882336B8DCC6510DC6B9C3294C6AA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_1_t5AFCED6452B2551E59D8997046D5F19C8F731FB3_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Type_t* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	PartBinding_tB263B939F5CC92F02FD1C8892A194F9BC8A53D38 V_2;
	memset((&V_2), 0, sizeof(V_2));
	Type_t* V_3 = NULL;
	{
		// valueSizeInBytes = 0;
		int32_t* L_0 = ___3_valueSizeInBytes;
		*((int32_t*)L_0) = (int32_t)0;
		// isButton = true;
		bool* L_1 = ___4_isButton;
		*((int8_t*)L_1) = (int8_t)1;
		// Type type = null;
		V_0 = (Type_t*)NULL;
		// foreach (var control in context.controls)
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_2 = ___0_context;
		RuntimeObject* L_3;
		L_3 = InputBindingCompositeContext_get_controls_m142FECF8374D6E0E3B012C8D376AB913E9634C69(L_2, NULL);
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0 /* System.Collections.Generic.IEnumerator`1<T> System.Collections.Generic.IEnumerable`1<UnityEngine.InputSystem.InputBindingCompositeContext/PartBinding>::GetEnumerator() */, IEnumerable_1_t45141F64D6D882336B8DCC6510DC6B9C3294C6AA_il2cpp_TypeInfo_var, L_3);
		V_1 = L_4;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0091:
			{// begin finally (depth: 1)
				{
					RuntimeObject* L_5 = V_1;
					if (!L_5)
					{
						goto IL_009a;
					}
				}
				{
					RuntimeObject* L_6 = V_1;
					NullCheck(L_6);
					InterfaceActionInvoker0::Invoke(0 /* System.Void System.IDisposable::Dispose() */, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_6);
				}

IL_009a:
				{
					return;
				}
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			{
				goto IL_0087_1;
			}

IL_0017_1:
			{
				// foreach (var control in context.controls)
				RuntimeObject* L_7 = V_1;
				NullCheck(L_7);
				PartBinding_tB263B939F5CC92F02FD1C8892A194F9BC8A53D38 L_8;
				L_8 = InterfaceFuncInvoker0< PartBinding_tB263B939F5CC92F02FD1C8892A194F9BC8A53D38 >::Invoke(0 /* T System.Collections.Generic.IEnumerator`1<UnityEngine.InputSystem.InputBindingCompositeContext/PartBinding>::get_Current() */, IEnumerator_1_t5AFCED6452B2551E59D8997046D5F19C8F731FB3_il2cpp_TypeInfo_var, L_7);
				V_2 = L_8;
				// if (control.part != part)
				int32_t L_9;
				L_9 = PartBinding_get_part_m93F95BE7AAA2BF480FBD669060C2D1920D5B8943_inline((&V_2), NULL);
				int32_t L_10 = ___1_part;
				if ((!(((uint32_t)L_9) == ((uint32_t)L_10))))
				{
					goto IL_0087_1;
				}
			}
			{
				// var controlType = control.control.valueType;
				InputControl_t74F06B623518F992BF8E38656A5E0857169E3E2E* L_11;
				L_11 = PartBinding_get_control_m96F4C9715F4976504BB4B9BC15D9869E66DDB4F9_inline((&V_2), NULL);
				NullCheck(L_11);
				Type_t* L_12;
				L_12 = VirtualFuncInvoker0< Type_t* >::Invoke(4 /* System.Type UnityEngine.InputSystem.InputControl::get_valueType() */, L_11);
				V_3 = L_12;
				// if (type == null || controlType.IsAssignableFrom(type))
				Type_t* L_13 = V_0;
				il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
				bool L_14;
				L_14 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_13, (Type_t*)NULL, NULL);
				if (L_14)
				{
					goto IL_0047_1;
				}
			}
			{
				Type_t* L_15 = V_3;
				Type_t* L_16 = V_0;
				NullCheck(L_15);
				bool L_17;
				L_17 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(21 /* System.Boolean System.Type::IsAssignableFrom(System.Type) */, L_15, L_16);
				if (!L_17)
				{
					goto IL_004b_1;
				}
			}

IL_0047_1:
			{
				// type = controlType;
				Type_t* L_18 = V_3;
				V_0 = L_18;
				goto IL_005f_1;
			}

IL_004b_1:
			{
				// else if (!type.IsAssignableFrom(controlType))
				Type_t* L_19 = V_0;
				Type_t* L_20 = V_3;
				NullCheck(L_19);
				bool L_21;
				L_21 = VirtualFuncInvoker1< bool, Type_t* >::Invoke(21 /* System.Boolean System.Type::IsAssignableFrom(System.Type) */, L_19, L_20);
				if (L_21)
				{
					goto IL_005f_1;
				}
			}
			{
				// type = typeof(Object);
				RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_22 = { reinterpret_cast<intptr_t> (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_0_0_0_var) };
				il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
				Type_t* L_23;
				L_23 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_22, NULL);
				V_0 = L_23;
			}

IL_005f_1:
			{
				// valueSizeInBytes = Math.Max(control.control.valueSizeInBytes, valueSizeInBytes);
				int32_t* L_24 = ___3_valueSizeInBytes;
				InputControl_t74F06B623518F992BF8E38656A5E0857169E3E2E* L_25;
				L_25 = PartBinding_get_control_m96F4C9715F4976504BB4B9BC15D9869E66DDB4F9_inline((&V_2), NULL);
				NullCheck(L_25);
				int32_t L_26;
				L_26 = VirtualFuncInvoker0< int32_t >::Invoke(5 /* System.Int32 UnityEngine.InputSystem.InputControl::get_valueSizeInBytes() */, L_25);
				int32_t* L_27 = ___3_valueSizeInBytes;
				int32_t L_28 = *((int32_t*)L_27);
				il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
				int32_t L_29;
				L_29 = Math_Max_m530EBA549AFD98CFC2BD29FE86C6376E67DF11CF(L_26, L_28, NULL);
				*((int32_t*)L_24) = (int32_t)L_29;
				// isButton &= control.control.isButton;
				bool* L_30 = ___4_isButton;
				bool* L_31 = ___4_isButton;
				int32_t L_32 = *((uint8_t*)L_31);
				InputControl_t74F06B623518F992BF8E38656A5E0857169E3E2E* L_33;
				L_33 = PartBinding_get_control_m96F4C9715F4976504BB4B9BC15D9869E66DDB4F9_inline((&V_2), NULL);
				NullCheck(L_33);
				bool L_34;
				L_34 = InputControl_get_isButton_m4634F4F40450AA969DA851B73E2A2226239F3BEF(L_33, NULL);
				*((int8_t*)L_30) = (int8_t)((int32_t)(L_32&(int32_t)L_34));
			}

IL_0087_1:
			{
				// foreach (var control in context.controls)
				RuntimeObject* L_35 = V_1;
				NullCheck(L_35);
				bool L_36;
				L_36 = InterfaceFuncInvoker0< bool >::Invoke(0 /* System.Boolean System.Collections.IEnumerator::MoveNext() */, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_35);
				if (L_36)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_009b;
			}
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_009b:
	{
		// valueType = type;
		Type_t** L_37 = ___2_valueType;
		Type_t* L_38 = V_0;
		*((RuntimeObject**)L_37) = (RuntimeObject*)L_38;
		Il2CppCodeGenWriteBarrier((void**)(RuntimeObject**)L_37, (void*)(RuntimeObject*)L_38);
		// }
		return;
	}
}
// System.Void UnityEngine.InputSystem.Composites.OneModifierComposite::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OneModifierComposite__ctor_mB03D8DE49D44A7C6FF0AB59B5CF4F35E2F6C7A26 (OneModifierComposite_tC18745AC641308E913620A321BF1CCE00D60E55B* __this, const RuntimeMethod* method) 
{
	{
		InputBindingComposite__ctor_m911F4FDF8BFA44468F8D0493531190FE15242A4A(__this, NULL);
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
// System.Type UnityEngine.InputSystem.Composites.TwoModifiersComposite::get_valueType()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* TwoModifiersComposite_get_valueType_mD7C59304C3F9F7C9A49C29F705E500781CAE6125 (TwoModifiersComposite_t7B84C109D0750D4F515629DD0D3D5C6373F42CA3* __this, const RuntimeMethod* method) 
{
	{
		// public override Type valueType => m_ValueType;
		Type_t* L_0 = __this->___m_ValueType_6;
		return L_0;
	}
}
// System.Int32 UnityEngine.InputSystem.Composites.TwoModifiersComposite::get_valueSizeInBytes()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t TwoModifiersComposite_get_valueSizeInBytes_m534C8107DAC6BC8F0DCCE80128D5BDB13F4F662A (TwoModifiersComposite_t7B84C109D0750D4F515629DD0D3D5C6373F42CA3* __this, const RuntimeMethod* method) 
{
	{
		// public override int valueSizeInBytes => m_ValueSizeInBytes;
		int32_t L_0 = __this->___m_ValueSizeInBytes_5;
		return L_0;
	}
}
// System.Single UnityEngine.InputSystem.Composites.TwoModifiersComposite::EvaluateMagnitude(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float TwoModifiersComposite_EvaluateMagnitude_mBAC0B38247A658D8487B23A3BBD54CC8DFD37314 (TwoModifiersComposite_t7B84C109D0750D4F515629DD0D3D5C6373F42CA3* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) 
{
	{
		// if (ModifiersArePressed(ref context))
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_0 = ___0_context;
		bool L_1;
		L_1 = TwoModifiersComposite_ModifiersArePressed_m0D7D12C3139BE7B2CDB1DBDB3C2A59AE584F49C8(__this, L_0, NULL);
		if (!L_1)
		{
			goto IL_0016;
		}
	}
	{
		// return context.EvaluateMagnitude(binding);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_2 = ___0_context;
		int32_t L_3 = __this->___binding_3;
		float L_4;
		L_4 = InputBindingCompositeContext_EvaluateMagnitude_m418436D265278E622B80FD3CB6E6366F5DDD2E1A(L_2, L_3, NULL);
		return L_4;
	}

IL_0016:
	{
		// return default;
		return (0.0f);
	}
}
// System.Void UnityEngine.InputSystem.Composites.TwoModifiersComposite::ReadValue(UnityEngine.InputSystem.InputBindingCompositeContext&,System.Void*,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TwoModifiersComposite_ReadValue_mD57B7904321CE14F2796449A3A7E832FE27459B4 (TwoModifiersComposite_t7B84C109D0750D4F515629DD0D3D5C6373F42CA3* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, void* ___1_buffer, int32_t ___2_bufferSize, const RuntimeMethod* method) 
{
	{
		// if (ModifiersArePressed(ref context))
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_0 = ___0_context;
		bool L_1;
		L_1 = TwoModifiersComposite_ModifiersArePressed_m0D7D12C3139BE7B2CDB1DBDB3C2A59AE584F49C8(__this, L_0, NULL);
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		// context.ReadValue(binding, buffer, bufferSize);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_2 = ___0_context;
		int32_t L_3 = __this->___binding_3;
		void* L_4 = ___1_buffer;
		int32_t L_5 = ___2_bufferSize;
		InputBindingCompositeContext_ReadValue_mC797CA9EDA827FF511B0771EEF21F1B271CF16D8(L_2, L_3, L_4, L_5, NULL);
		return;
	}

IL_0018:
	{
		// UnsafeUtility.MemClear(buffer, m_ValueSizeInBytes);
		void* L_6 = ___1_buffer;
		int32_t L_7 = __this->___m_ValueSizeInBytes_5;
		UnsafeUtility_MemClear_m6C4377117084A11A667A567BC2F5E606A632A7C1(L_6, ((int64_t)L_7), NULL);
		// }
		return;
	}
}
// System.Boolean UnityEngine.InputSystem.Composites.TwoModifiersComposite::ModifiersArePressed(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool TwoModifiersComposite_ModifiersArePressed_m0D7D12C3139BE7B2CDB1DBDB3C2A59AE584F49C8 (TwoModifiersComposite_t7B84C109D0750D4F515629DD0D3D5C6373F42CA3* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) 
{
	bool V_0 = false;
	double V_1 = 0.0;
	double V_2 = 0.0;
	int32_t G_B3_0 = 0;
	{
		// var modifiersDown = context.ReadValueAsButton(modifier1) && context.ReadValueAsButton(modifier2);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_0 = ___0_context;
		int32_t L_1 = __this->___modifier1_1;
		bool L_2;
		L_2 = InputBindingCompositeContext_ReadValueAsButton_mD3F30463AD217008C8DC0F42BA59BDC8EB37D0DB(L_0, L_1, NULL);
		if (!L_2)
		{
			goto IL_001c;
		}
	}
	{
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_3 = ___0_context;
		int32_t L_4 = __this->___modifier2_2;
		bool L_5;
		L_5 = InputBindingCompositeContext_ReadValueAsButton_mD3F30463AD217008C8DC0F42BA59BDC8EB37D0DB(L_3, L_4, NULL);
		G_B3_0 = ((int32_t)(L_5));
		goto IL_001d;
	}

IL_001c:
	{
		G_B3_0 = 0;
	}

IL_001d:
	{
		V_0 = (bool)G_B3_0;
		// if (modifiersDown && m_BindingIsButton && !overrideModifiersNeedToBePressedFirst)
		bool L_6 = V_0;
		if (!L_6)
		{
			goto IL_0064;
		}
	}
	{
		bool L_7 = __this->___m_BindingIsButton_7;
		if (!L_7)
		{
			goto IL_0064;
		}
	}
	{
		bool L_8 = __this->___overrideModifiersNeedToBePressedFirst_4;
		if (L_8)
		{
			goto IL_0064;
		}
	}
	{
		// var timestamp = context.GetPressTime(binding);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_9 = ___0_context;
		int32_t L_10 = __this->___binding_3;
		double L_11;
		L_11 = InputBindingCompositeContext_GetPressTime_mA919F3E37F086C2BFEEB6EB17A75B1A6CFF2E58A(L_9, L_10, NULL);
		V_1 = L_11;
		// var timestamp1 = context.GetPressTime(modifier1);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_12 = ___0_context;
		int32_t L_13 = __this->___modifier1_1;
		double L_14;
		L_14 = InputBindingCompositeContext_GetPressTime_mA919F3E37F086C2BFEEB6EB17A75B1A6CFF2E58A(L_12, L_13, NULL);
		// var timestamp2 = context.GetPressTime(modifier2);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_15 = ___0_context;
		int32_t L_16 = __this->___modifier2_2;
		double L_17;
		L_17 = InputBindingCompositeContext_GetPressTime_mA919F3E37F086C2BFEEB6EB17A75B1A6CFF2E58A(L_15, L_16, NULL);
		V_2 = L_17;
		// return timestamp1 <= timestamp && timestamp2 <= timestamp;
		double L_18 = V_1;
		if ((!(((double)L_14) <= ((double)L_18))))
		{
			goto IL_0062;
		}
	}
	{
		double L_19 = V_2;
		double L_20 = V_1;
		return (bool)((((int32_t)((!(((double)L_19) <= ((double)L_20)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0062:
	{
		return (bool)0;
	}

IL_0064:
	{
		// return modifiersDown;
		bool L_21 = V_0;
		return L_21;
	}
}
// System.Void UnityEngine.InputSystem.Composites.TwoModifiersComposite::FinishSetup(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TwoModifiersComposite_FinishSetup_mE13073D787D428DF4B1DD76A525F543D266CBF38 (TwoModifiersComposite_t7B84C109D0750D4F515629DD0D3D5C6373F42CA3* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&InputSystem_t4120CA4FE7DCFD56AF9391933FC3F1F485350164_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// OneModifierComposite.DetermineValueTypeAndSize(ref context, binding, out m_ValueType, out m_ValueSizeInBytes, out m_BindingIsButton);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_0 = ___0_context;
		int32_t L_1 = __this->___binding_3;
		Type_t** L_2 = (Type_t**)(&__this->___m_ValueType_6);
		int32_t* L_3 = (int32_t*)(&__this->___m_ValueSizeInBytes_5);
		bool* L_4 = (bool*)(&__this->___m_BindingIsButton_7);
		OneModifierComposite_DetermineValueTypeAndSize_m872B0A8E5DEA6864048B0D08DE31FFBA40C442AA(L_0, L_1, L_2, L_3, L_4, NULL);
		// if (!overrideModifiersNeedToBePressedFirst)
		bool L_5 = __this->___overrideModifiersNeedToBePressedFirst_4;
		if (L_5)
		{
			goto IL_0039;
		}
	}
	{
		// overrideModifiersNeedToBePressedFirst = !InputSystem.settings.shortcutKeysConsumeInput;
		il2cpp_codegen_runtime_class_init_inline(InputSystem_t4120CA4FE7DCFD56AF9391933FC3F1F485350164_il2cpp_TypeInfo_var);
		InputSettings_tBA8835B505722A59702A08BCBA46ECF0B0274EEF* L_6;
		L_6 = InputSystem_get_settings_m8E3E9C0907904CBDBAE96354142AB0A87C7A3B74(NULL);
		NullCheck(L_6);
		bool L_7;
		L_7 = InputSettings_get_shortcutKeysConsumeInput_m916DC677CCE3E4F3AD3BA48C5723965007CBE670_inline(L_6, NULL);
		__this->___overrideModifiersNeedToBePressedFirst_4 = (bool)((((int32_t)L_7) == ((int32_t)0))? 1 : 0);
	}

IL_0039:
	{
		// }
		return;
	}
}
// System.Object UnityEngine.InputSystem.Composites.TwoModifiersComposite::ReadValueAsObject(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* TwoModifiersComposite_ReadValueAsObject_m167D7477D6B669FF931EF962102B39F44305BFAE (TwoModifiersComposite_t7B84C109D0750D4F515629DD0D3D5C6373F42CA3* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) 
{
	{
		// if (context.ReadValueAsButton(modifier1) && context.ReadValueAsButton(modifier2))
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_0 = ___0_context;
		int32_t L_1 = __this->___modifier1_1;
		bool L_2;
		L_2 = InputBindingCompositeContext_ReadValueAsButton_mD3F30463AD217008C8DC0F42BA59BDC8EB37D0DB(L_0, L_1, NULL);
		if (!L_2)
		{
			goto IL_0029;
		}
	}
	{
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_3 = ___0_context;
		int32_t L_4 = __this->___modifier2_2;
		bool L_5;
		L_5 = InputBindingCompositeContext_ReadValueAsButton_mD3F30463AD217008C8DC0F42BA59BDC8EB37D0DB(L_3, L_4, NULL);
		if (!L_5)
		{
			goto IL_0029;
		}
	}
	{
		// return context.ReadValueAsObject(binding);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_6 = ___0_context;
		int32_t L_7 = __this->___binding_3;
		RuntimeObject* L_8;
		L_8 = InputBindingCompositeContext_ReadValueAsObject_mB707A8B03313DBFE4A3DF4867FE6A20AAAFB1882(L_6, L_7, NULL);
		return L_8;
	}

IL_0029:
	{
		// return null;
		return NULL;
	}
}
// System.Void UnityEngine.InputSystem.Composites.TwoModifiersComposite::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TwoModifiersComposite__ctor_m46086F35D8EE4E52A60DB087F8C7D5E5AA3CB880 (TwoModifiersComposite_t7B84C109D0750D4F515629DD0D3D5C6373F42CA3* __this, const RuntimeMethod* method) 
{
	{
		InputBindingComposite__ctor_m911F4FDF8BFA44468F8D0493531190FE15242A4A(__this, NULL);
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
// UnityEngine.Vector2 UnityEngine.InputSystem.Composites.Vector2Composite::ReadValue(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 Vector2Composite_ReadValue_m32E400A5EEBEDD51B029B08B7E35777A91A85439 (Vector2Composite_tCAE11D025FE085E66E963DCCD6559D042A713908* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	bool V_1 = false;
	bool V_2 = false;
	bool V_3 = false;
	float V_4 = 0.0f;
	float V_5 = 0.0f;
	float V_6 = 0.0f;
	bool G_B4_0 = false;
	bool G_B3_0 = false;
	{
		// var mode = this.mode;
		int32_t L_0 = __this->___mode_6;
		V_0 = L_0;
		// if (mode == Mode.Analog)
		int32_t L_1 = V_0;
		if ((!(((uint32_t)L_1) == ((uint32_t)2))))
		{
			goto IL_004d;
		}
	}
	{
		// var upValue = context.ReadValue<float>(up);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_2 = ___0_context;
		int32_t L_3 = __this->___up_1;
		float L_4;
		L_4 = InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648(L_2, L_3, InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648_RuntimeMethod_var);
		// var downValue = context.ReadValue<float>(down);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_5 = ___0_context;
		int32_t L_6 = __this->___down_2;
		float L_7;
		L_7 = InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648(L_5, L_6, InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648_RuntimeMethod_var);
		V_4 = L_7;
		// var leftValue = context.ReadValue<float>(left);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_8 = ___0_context;
		int32_t L_9 = __this->___left_3;
		float L_10;
		L_10 = InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648(L_8, L_9, InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648_RuntimeMethod_var);
		V_5 = L_10;
		// var rightValue = context.ReadValue<float>(right);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_11 = ___0_context;
		int32_t L_12 = __this->___right_4;
		float L_13;
		L_13 = InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648(L_11, L_12, InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648_RuntimeMethod_var);
		V_6 = L_13;
		// return DpadControl.MakeDpadVector(upValue, downValue, leftValue, rightValue);
		float L_14 = V_4;
		float L_15 = V_5;
		float L_16 = V_6;
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_17;
		L_17 = DpadControl_MakeDpadVector_m5F53CF11B80175D8FF9856B2E126978C65C82CE6(L_4, L_14, L_15, L_16, NULL);
		return L_17;
	}

IL_004d:
	{
		// var upIsPressed = context.ReadValueAsButton(up);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_18 = ___0_context;
		int32_t L_19 = __this->___up_1;
		bool L_20;
		L_20 = InputBindingCompositeContext_ReadValueAsButton_mD3F30463AD217008C8DC0F42BA59BDC8EB37D0DB(L_18, L_19, NULL);
		// var downIsPressed = context.ReadValueAsButton(down);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_21 = ___0_context;
		int32_t L_22 = __this->___down_2;
		bool L_23;
		L_23 = InputBindingCompositeContext_ReadValueAsButton_mD3F30463AD217008C8DC0F42BA59BDC8EB37D0DB(L_21, L_22, NULL);
		V_1 = L_23;
		// var leftIsPressed = context.ReadValueAsButton(left);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_24 = ___0_context;
		int32_t L_25 = __this->___left_3;
		bool L_26;
		L_26 = InputBindingCompositeContext_ReadValueAsButton_mD3F30463AD217008C8DC0F42BA59BDC8EB37D0DB(L_24, L_25, NULL);
		V_2 = L_26;
		// var rightIsPressed = context.ReadValueAsButton(right);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_27 = ___0_context;
		int32_t L_28 = __this->___right_4;
		bool L_29;
		L_29 = InputBindingCompositeContext_ReadValueAsButton_mD3F30463AD217008C8DC0F42BA59BDC8EB37D0DB(L_27, L_28, NULL);
		V_3 = L_29;
		// if (!normalize) // Was on by default.
		bool L_30 = __this->___normalize_5;
		G_B3_0 = L_20;
		if (L_30)
		{
			G_B4_0 = L_20;
			goto IL_008a;
		}
	}
	{
		// mode = Mode.Digital;
		V_0 = 1;
		G_B4_0 = G_B3_0;
	}

IL_008a:
	{
		// return DpadControl.MakeDpadVector(upIsPressed, downIsPressed, leftIsPressed, rightIsPressed, mode == Mode.DigitalNormalized);
		bool L_31 = V_1;
		bool L_32 = V_2;
		bool L_33 = V_3;
		int32_t L_34 = V_0;
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_35;
		L_35 = DpadControl_MakeDpadVector_mAA0FB9313820797F8F1DCB006A8F2341604CB7F5(G_B4_0, L_31, L_32, L_33, (bool)((((int32_t)L_34) == ((int32_t)0))? 1 : 0), NULL);
		return L_35;
	}
}
// System.Single UnityEngine.InputSystem.Composites.Vector2Composite::EvaluateMagnitude(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Vector2Composite_EvaluateMagnitude_m019D431241F2FA113EB0CF79D0092315AA5942CE (Vector2Composite_tCAE11D025FE085E66E963DCCD6559D042A713908* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) 
{
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		// var value = ReadValue(ref context);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_0 = ___0_context;
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_1;
		L_1 = VirtualFuncInvoker1< Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* >::Invoke(10 /* TValue UnityEngine.InputSystem.InputBindingComposite`1<UnityEngine.Vector2>::ReadValue(UnityEngine.InputSystem.InputBindingCompositeContext&) */, __this, L_0);
		V_0 = L_1;
		// return value.magnitude;
		float L_2;
		L_2 = Vector2_get_magnitude_m5C59B4056420AEFDB291AD0914A3F675330A75CE_inline((&V_0), NULL);
		return L_2;
	}
}
// System.Void UnityEngine.InputSystem.Composites.Vector2Composite::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector2Composite__ctor_m1625F6C3829296D1C12B55EF496E38EDC8D05006 (Vector2Composite_tCAE11D025FE085E66E963DCCD6559D042A713908* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&InputBindingComposite_1__ctor_m7A3EC8A3F30D4FD3E13C1FDD38CFB5B41B461545_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public bool normalize = true;
		__this->___normalize_5 = (bool)1;
		InputBindingComposite_1__ctor_m7A3EC8A3F30D4FD3E13C1FDD38CFB5B41B461545(__this, InputBindingComposite_1__ctor_m7A3EC8A3F30D4FD3E13C1FDD38CFB5B41B461545_RuntimeMethod_var);
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
// UnityEngine.Vector3 UnityEngine.InputSystem.Composites.Vector3Composite::ReadValue(UnityEngine.InputSystem.InputBindingCompositeContext&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3Composite_ReadValue_m6D1BA73F518C68CDF4AEDAF1A48BA2F7ABF59AE1 (Vector3Composite_t014892920D73110CD43E6CC997E0FAA5860A62E0* __this, InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* ___0_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	float V_0 = 0.0f;
	float V_1 = 0.0f;
	float V_2 = 0.0f;
	float V_3 = 0.0f;
	float V_4 = 0.0f;
	float V_5 = 0.0f;
	float V_6 = 0.0f;
	float V_7 = 0.0f;
	float V_8 = 0.0f;
	float V_9 = 0.0f;
	float V_10 = 0.0f;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_11;
	memset((&V_11), 0, sizeof(V_11));
	float G_B5_0 = 0.0f;
	float G_B8_0 = 0.0f;
	float G_B11_0 = 0.0f;
	float G_B14_0 = 0.0f;
	float G_B17_0 = 0.0f;
	float G_B20_0 = 0.0f;
	{
		// if (mode == Mode.Analog)
		int32_t L_0 = __this->___mode_7;
		if (L_0)
		{
			goto IL_0065;
		}
	}
	{
		// var upValue = context.ReadValue<float>(up);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_1 = ___0_context;
		int32_t L_2 = __this->___up_1;
		float L_3;
		L_3 = InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648(L_1, L_2, InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648_RuntimeMethod_var);
		V_0 = L_3;
		// var downValue = context.ReadValue<float>(down);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_4 = ___0_context;
		int32_t L_5 = __this->___down_2;
		float L_6;
		L_6 = InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648(L_4, L_5, InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648_RuntimeMethod_var);
		V_1 = L_6;
		// var leftValue = context.ReadValue<float>(left);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_7 = ___0_context;
		int32_t L_8 = __this->___left_3;
		float L_9;
		L_9 = InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648(L_7, L_8, InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648_RuntimeMethod_var);
		V_2 = L_9;
		// var rightValue = context.ReadValue<float>(right);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_10 = ___0_context;
		int32_t L_11 = __this->___right_4;
		float L_12;
		L_12 = InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648(L_10, L_11, InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648_RuntimeMethod_var);
		// var forwardValue = context.ReadValue<float>(forward);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_13 = ___0_context;
		int32_t L_14 = __this->___forward_5;
		float L_15;
		L_15 = InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648(L_13, L_14, InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648_RuntimeMethod_var);
		V_3 = L_15;
		// var backwardValue = context.ReadValue<float>(backward);
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_16 = ___0_context;
		int32_t L_17 = __this->___backward_6;
		float L_18;
		L_18 = InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648(L_16, L_17, InputBindingCompositeContext_ReadValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m633155685894F37EA0AE034D68AE0635EF444648_RuntimeMethod_var);
		V_4 = L_18;
		// return new Vector3(rightValue - leftValue, upValue - downValue, forwardValue - backwardValue);
		float L_19 = V_2;
		float L_20 = V_0;
		float L_21 = V_1;
		float L_22 = V_3;
		float L_23 = V_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_24;
		memset((&L_24), 0, sizeof(L_24));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_24), ((float)il2cpp_codegen_subtract(L_12, L_19)), ((float)il2cpp_codegen_subtract(L_20, L_21)), ((float)il2cpp_codegen_subtract(L_22, L_23)), /*hidden argument*/NULL);
		return L_24;
	}

IL_0065:
	{
		// var upValue = context.ReadValueAsButton(up) ? 1f : 0f;
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_25 = ___0_context;
		int32_t L_26 = __this->___up_1;
		bool L_27;
		L_27 = InputBindingCompositeContext_ReadValueAsButton_mD3F30463AD217008C8DC0F42BA59BDC8EB37D0DB(L_25, L_26, NULL);
		if (L_27)
		{
			goto IL_007a;
		}
	}
	{
		G_B5_0 = (0.0f);
		goto IL_007f;
	}

IL_007a:
	{
		G_B5_0 = (1.0f);
	}

IL_007f:
	{
		V_5 = G_B5_0;
		// var downValue = context.ReadValueAsButton(down) ? -1f : 0f;
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_28 = ___0_context;
		int32_t L_29 = __this->___down_2;
		bool L_30;
		L_30 = InputBindingCompositeContext_ReadValueAsButton_mD3F30463AD217008C8DC0F42BA59BDC8EB37D0DB(L_28, L_29, NULL);
		if (L_30)
		{
			goto IL_0096;
		}
	}
	{
		G_B8_0 = (0.0f);
		goto IL_009b;
	}

IL_0096:
	{
		G_B8_0 = (-1.0f);
	}

IL_009b:
	{
		V_6 = G_B8_0;
		// var leftValue = context.ReadValueAsButton(left) ? -1f : 0f;
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_31 = ___0_context;
		int32_t L_32 = __this->___left_3;
		bool L_33;
		L_33 = InputBindingCompositeContext_ReadValueAsButton_mD3F30463AD217008C8DC0F42BA59BDC8EB37D0DB(L_31, L_32, NULL);
		if (L_33)
		{
			goto IL_00b2;
		}
	}
	{
		G_B11_0 = (0.0f);
		goto IL_00b7;
	}

IL_00b2:
	{
		G_B11_0 = (-1.0f);
	}

IL_00b7:
	{
		V_7 = G_B11_0;
		// var rightValue = context.ReadValueAsButton(right) ? 1f : 0f;
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_34 = ___0_context;
		int32_t L_35 = __this->___right_4;
		bool L_36;
		L_36 = InputBindingCompositeContext_ReadValueAsButton_mD3F30463AD217008C8DC0F42BA59BDC8EB37D0DB(L_34, L_35, NULL);
		if (L_36)
		{
			goto IL_00ce;
		}
	}
	{
		G_B14_0 = (0.0f);
		goto IL_00d3;
	}

IL_00ce:
	{
		G_B14_0 = (1.0f);
	}

IL_00d3:
	{
		V_8 = G_B14_0;
		// var forwardValue = context.ReadValueAsButton(forward) ? 1f : 0f;
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_37 = ___0_context;
		int32_t L_38 = __this->___forward_5;
		bool L_39;
		L_39 = InputBindingCompositeContext_ReadValueAsButton_mD3F30463AD217008C8DC0F42BA59BDC8EB37D0DB(L_37, L_38, NULL);
		if (L_39)
		{
			goto IL_00ea;
		}
	}
	{
		G_B17_0 = (0.0f);
		goto IL_00ef;
	}

IL_00ea:
	{
		G_B17_0 = (1.0f);
	}

IL_00ef:
	{
		V_9 = G_B17_0;
		// var backwardValue = context.ReadValueAsButton(backward) ? -1f : 0f;
		InputBindingCompositeContext_t961CAA1DF29D7D4E0AE0AEF22400B285E17B1390* L_40 = ___0_context;
		int32_t L_41 = __this->___backward_6;
		bool L_42;
		L_42 = InputBindingCompositeContext_ReadValueAsButton_mD3F30463AD217008C8DC0F42BA59BDC8EB37D0DB(L_40, L_41, NULL);
		if (L_42)
		{
			goto IL_0106;
		}
	}
	{
		G_B20_0 = (0.0f);
		goto IL_010b;
	}

IL_0106:
	{
		G_B20_0 = (-1.0f);
	}

IL_010b:
	{
		V_10 = G_B20_0;
		// var vector = new Vector3(leftValue + rightValue, upValue + downValue, forwardValue + backwardValue);
		float L_43 = V_7;
		float L_44 = V_8;
		float L_45 = V_5;
		float L_46 = V_6;
		float L_47 = V_9;
		float L_48 = V_10;
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&V_11), ((float)il2cpp_codegen_add(L_43, L_44)), ((float)il2cpp_codegen_add(L_45, L_46)), ((float)il2cpp_codegen_add(L_47, L_48)), NULL);
		// if (mode == Mode.DigitalNormalized)
		int32_t L_49 = __this->___mode_7;
		if ((!(((uint32_t)L_49) == ((uint32_t)1))))
		{
			goto IL_0135;
		}
	}
	{
		// vector = vector.normalized;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_50;
		L_50 = Vector3_get_normalized_m736BBF65D5CDA7A18414370D15B4DFCC1E466F07_inline((&V_11), NULL);
		V_11 = L_50;
	}

IL_0135:
	{
		// return vector;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_51 = V_11;
		return L_51;
	}
}
// System.Void UnityEngine.InputSystem.Composites.Vector3Composite::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector3Composite__ctor_m7411C64277DE74720952DC246F08B6970AB6F5DD (Vector3Composite_t014892920D73110CD43E6CC997E0FAA5860A62E0* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&InputBindingComposite_1__ctor_mCC1C23E6E7958682F8F851C7EF1C1C179E21D789_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		InputBindingComposite_1__ctor_mCC1C23E6E7958682F8F851C7EF1C1C179E21D789(__this, InputBindingComposite_1__ctor_mCC1C23E6E7958682F8F851C7EF1C1C179E21D789_RuntimeMethod_var);
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
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____stringLength_4;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void IntPtr__ctor_m4F9A9B80F01996B610D5AE4797F20B98ECD0A3D9_inline (intptr_t* __this, void* ___0_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_value;
		*__this = ((intptr_t)L_0);
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Substring_get_length_m55986408214CA7DBD05548C1E226DC2E4D6E78FC_inline (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, const RuntimeMethod* method) 
{
	{
		// public int length => m_Length;
		int32_t L_0 = __this->___m_Length_2;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Substring_get_index_mEF04F0C2A5292FEC77A6DE1C13C81B719C9D3012_inline (Substring_t2E16755269E6716C22074D6BC0A9099915E67849* __this, const RuntimeMethod* method) 
{
	{
		// public int index => m_Index;
		int32_t L_0 = __this->___m_Index_1;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool InputSettings_get_shortcutKeysConsumeInput_m916DC677CCE3E4F3AD3BA48C5723965007CBE670_inline (InputSettings_tBA8835B505722A59702A08BCBA46ECF0B0274EEF* __this, const RuntimeMethod* method) 
{
	{
		// get => m_ShortcutKeysConsumeInputs;
		bool L_0 = __this->___m_ShortcutKeysConsumeInputs_21;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t PartBinding_get_part_m93F95BE7AAA2BF480FBD669060C2D1920D5B8943_inline (PartBinding_tB263B939F5CC92F02FD1C8892A194F9BC8A53D38* __this, const RuntimeMethod* method) 
{
	{
		// public int part { get; set; }
		int32_t L_0 = __this->___U3CpartU3Ek__BackingField_0;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InputControl_t74F06B623518F992BF8E38656A5E0857169E3E2E* PartBinding_get_control_m96F4C9715F4976504BB4B9BC15D9869E66DDB4F9_inline (PartBinding_tB263B939F5CC92F02FD1C8892A194F9BC8A53D38* __this, const RuntimeMethod* method) 
{
	{
		// public InputControl control { get; set; }
		InputControl_t74F06B623518F992BF8E38656A5E0857169E3E2E* L_0 = __this->___U3CcontrolU3Ek__BackingField_1;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Vector2_get_magnitude_m5C59B4056420AEFDB291AD0914A3F675330A75CE_inline (Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	float V_0 = 0.0f;
	{
		float L_0 = __this->___x_0;
		float L_1 = __this->___x_0;
		float L_2 = __this->___y_1;
		float L_3 = __this->___y_1;
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_4;
		L_4 = sqrt(((double)((float)il2cpp_codegen_add(((float)il2cpp_codegen_multiply(L_0, L_1)), ((float)il2cpp_codegen_multiply(L_2, L_3))))));
		V_0 = ((float)L_4);
		goto IL_0026;
	}

IL_0026:
	{
		float L_5 = V_0;
		return L_5;
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
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_get_normalized_m736BBF65D5CDA7A18414370D15B4DFCC1E466F07_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* __this, const RuntimeMethod* method) 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = (*(Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2*)__this);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_1;
		L_1 = Vector3_Normalize_mEF8349CC39674236CFC694189AFD36E31F89AC8F_inline(L_0, NULL);
		V_0 = L_1;
		goto IL_000f;
	}

IL_000f:
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_2 = V_0;
		return L_2;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_SizeOf_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m506739DDFD44F4F6CE36D20C36BFA90D7F56E4AE_gshared_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Func_2_Invoke_mDBA25DA5DA5B7E056FB9B026AF041F1385FB58A9_gshared_inline (Func_2_tACBF5A1656250800CE861707354491F0611F6624* __this, RuntimeObject* ___0_arg, const RuntimeMethod* method) 
{
	typedef RuntimeObject* (*FunctionPointerType) (RuntimeObject*, RuntimeObject*, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m4733F0A0FE136C9F8DCE4963455215585E8BE2CD_gshared_inline (Func_2_tF409A653B8F770E0A30CD80D21764FB1DDB2A28F* __this, Il2CppChar ___0_arg, const RuntimeMethod* method) 
{
	typedef bool (*FunctionPointerType) (RuntimeObject*, Il2CppChar, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR KeyValuePair_2_tC24A74EF64A292F5C6BA77D0B04CD6620D2DE3AC Enumerator_get_Current_mB1068DBFCAA4C19D082D5717DF265CBA6D66D4BE_gshared_inline (Enumerator_tA3FD4A2E68B869CA74DA02EF77286DF5BFB3FE31* __this, const RuntimeMethod* method) 
{
	{
		KeyValuePair_2_tC24A74EF64A292F5C6BA77D0B04CD6620D2DE3AC L_0 = __this->____current_3;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* KeyValuePair_2_get_Value_m1425379DCDEDB955455E242B31CD2AE43552B441_gshared_inline (KeyValuePair_2_tC24A74EF64A292F5C6BA77D0B04CD6620D2DE3AC* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___value_1;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 KeyValuePair_2_get_Key_mC668DBB7580ADCE4B3D87DA1C6E91F6E56B9EE84_gshared_inline (KeyValuePair_2_tC24A74EF64A292F5C6BA77D0B04CD6620D2DE3AC* __this, const RuntimeMethod* method) 
{
	{
		InternedString_t8D62A48CB7D85AAE9CFCCCFB0A77AC2844905735 L_0 = __this->___key_0;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_Normalize_mEF8349CC39674236CFC694189AFD36E31F89AC8F_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_value, const RuntimeMethod* method) 
{
	float V_0 = 0.0f;
	bool V_1 = false;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_2;
	memset((&V_2), 0, sizeof(V_2));
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ___0_value;
		float L_1;
		L_1 = Vector3_Magnitude_m21652D951393A3D7CE92CE40049A0E7F76544D1B_inline(L_0, NULL);
		V_0 = L_1;
		float L_2 = V_0;
		V_1 = (bool)((((float)L_2) > ((float)(9.99999975E-06f)))? 1 : 0);
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_001e;
		}
	}
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4 = ___0_value;
		float L_5 = V_0;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_6;
		L_6 = Vector3_op_Division_mCC6BB24E372AB96B8380D1678446EF6A8BAE13BB_inline(L_4, L_5, NULL);
		V_2 = L_6;
		goto IL_0026;
	}

IL_001e:
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_7;
		L_7 = Vector3_get_zero_m0C1249C3F25B1C70EAD3CC8B31259975A457AE39_inline(NULL);
		V_2 = L_7;
		goto IL_0026;
	}

IL_0026:
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_8 = V_2;
		return L_8;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Vector3_Magnitude_m21652D951393A3D7CE92CE40049A0E7F76544D1B_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_vector, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	float V_0 = 0.0f;
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ___0_vector;
		float L_1 = L_0.___x_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_2 = ___0_vector;
		float L_3 = L_2.___x_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4 = ___0_vector;
		float L_5 = L_4.___y_3;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_6 = ___0_vector;
		float L_7 = L_6.___y_3;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_8 = ___0_vector;
		float L_9 = L_8.___z_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_10 = ___0_vector;
		float L_11 = L_10.___z_4;
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_12;
		L_12 = sqrt(((double)((float)il2cpp_codegen_add(((float)il2cpp_codegen_add(((float)il2cpp_codegen_multiply(L_1, L_3)), ((float)il2cpp_codegen_multiply(L_5, L_7)))), ((float)il2cpp_codegen_multiply(L_9, L_11))))));
		V_0 = ((float)L_12);
		goto IL_0034;
	}

IL_0034:
	{
		float L_13 = V_0;
		return L_13;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_op_Division_mCC6BB24E372AB96B8380D1678446EF6A8BAE13BB_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_a, float ___1_d, const RuntimeMethod* method) 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ___0_a;
		float L_1 = L_0.___x_2;
		float L_2 = ___1_d;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_3 = ___0_a;
		float L_4 = L_3.___y_3;
		float L_5 = ___1_d;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_6 = ___0_a;
		float L_7 = L_6.___z_4;
		float L_8 = ___1_d;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_9;
		memset((&L_9), 0, sizeof(L_9));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_9), ((float)(L_1/L_2)), ((float)(L_4/L_5)), ((float)(L_7/L_8)), /*hidden argument*/NULL);
		V_0 = L_9;
		goto IL_0021;
	}

IL_0021:
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_10 = V_0;
		return L_10;
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
