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
struct InvokerActionInvoker0
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj)
	{
		method->invoker_method(methodPtr, method, obj, NULL, NULL);
	}
};
template <typename T1>
struct InvokerActionInvoker1;
template <typename T1>
struct InvokerActionInvoker1<T1*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1)
	{
		void* params[1] = { p1 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};

// System.Action`1<UnityEngine.Font>
struct Action_1_tD91E4D0ED3C2E385D3BDD4B3EA48B5F99D39F1DC;
// System.Collections.Generic.Dictionary`2<System.Object,System.Object>
struct Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA;
// System.Collections.Generic.Dictionary`2<System.String,UnityEngine.GUIStyle>
struct Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F;
// System.Collections.Generic.IEqualityComparer`1<System.Object>
struct IEqualityComparer_1_t2CA7720C7ADCCDECD3B02E45878B4478619D5347;
// System.Collections.Generic.IEqualityComparer`1<System.String>
struct IEqualityComparer_1_tAE94C8F24AD5B94D4EE85CA9FC59E3409D41CAF7;
// System.Collections.Generic.Dictionary`2/KeyCollection<System.String,UnityEngine.GUIStyle>
struct KeyCollection_t851423C7344032A1F54545C69FC6507778294D6C;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.Object,System.Object>
struct ValueCollection_t038245E04B5D2A80048D9F8021A23E69A0C9DBAA;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.String,UnityEngine.GUIStyle>
struct ValueCollection_t6CD4B9552B29D570FBA4E0145D0C98841ECCC8C1;
// System.Collections.Generic.Dictionary`2/Entry<System.String,UnityEngine.GUIStyle>[]
struct EntryU5BU5D_tAEFE165DEE6FDB9F2B657E11D15B8C95DD88B0C2;
// System.Byte[]
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
// System.Char[]
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
// System.Delegate[]
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
// UnityEngine.GUILayoutOption[]
struct GUILayoutOptionU5BU5D_t24AB80AB9355D784F2C65E12A4D0CC2E0C914CA2;
// UnityEngine.GUIStyle[]
struct GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC;
// System.Int32[]
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
// System.Object[]
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
// System.String[]
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
// System.Type[]
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
// System.Reflection.Binder
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
// System.CultureAwareComparer
struct CultureAwareComparer_t5822A6535A6EB4C448D1B7736067D1188BAEE8CD;
// System.Delegate
struct Delegate_t;
// System.DelegateData
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
// System.Enum
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2;
// UnityEngine.Event
struct Event_tEBC6F24B56CE22B9C9AD1AC6C24A6B83BC3860CB;
// UnityEngine.Font
struct Font_tC95270EA3198038970422D78B74A7F2E218A96B6;
// UnityEngine.GUILayoutEntry
struct GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F;
// UnityEngine.GUILayoutOption
struct GUILayoutOption_t8B0AA056521747053A3176FCC43E9C3608940A14;
// UnityEngine.GUISettings
struct GUISettings_tF2CA7E8B9F62F1FC013BFF053B5FA2709EBA3847;
// UnityEngine.GUISkin
struct GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9;
// UnityEngine.GUIStyle
struct GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580;
// UnityEngine.GUIStyleState
struct GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95;
// System.Collections.IEnumerator
struct IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA;
// System.Reflection.MemberFilter
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
// System.Reflection.MethodInfo
struct MethodInfo_t;
// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C;
// System.OrdinalCaseSensitiveComparer
struct OrdinalCaseSensitiveComparer_t581CA7CB51DCF00B6012A697A4B4B3067144521A;
// System.OrdinalIgnoreCaseComparer
struct OrdinalIgnoreCaseComparer_t8BAE11990A4C855D3BCBBFB42F4EF8D45088FBB0;
// UnityEngine.RectOffset
struct RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5;
// UnityEngine.ScriptableObject
struct ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A;
// UnityEngine.SliderState
struct SliderState_t7BBFAEF918BAA1EE6116C3979993E4EC7DC54FC8;
// System.String
struct String_t;
// System.StringComparer
struct StringComparer_t6268F19CA34879176651429C0D8A3D0002BB8E06;
// System.Type
struct Type_t;
// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
// UnityEngine.Font/FontTextureRebuildCallback
struct FontTextureRebuildCallback_t76D5E172DF8AA57E67763D453AAC40F0961D09B1;
// UnityEngine.GUISkin/SkinChangedDelegate
struct SkinChangedDelegate_tA6D456E853D58AD2EF8A599F543C7E5BA8E94B98;

IL2CPP_EXTERN_C RuntimeClass* Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Enumerator_t6FCF94B18593967BB1EA62E38DDD1FA537144AA9_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* EventType_tC62F0D77DB08D7326B58B2D8CF43BD45CFD3203E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GUISettings_tF2CA7E8B9F62F1FC013BFF053B5FA2709EBA3847_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringComparer_t6268F19CA34879176651429C0D8A3D0002BB8E06_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral0484F5252B12C569CD2F3AEE4FCFD5DBE3C5967F;
IL2CPP_EXTERN_C String_t* _stringLiteral05CF9CF5853B675491570E9D20951E373F208902;
IL2CPP_EXTERN_C String_t* _stringLiteral0993C31116DED8F2DAA78B6A73E3149497A84400;
IL2CPP_EXTERN_C String_t* _stringLiteral123B2E5CFC7B5F49F61A9A7E042BC077972AB7EA;
IL2CPP_EXTERN_C String_t* _stringLiteral20E39C3AB7068FAFD9E4B868E16D2E5BC64D4952;
IL2CPP_EXTERN_C String_t* _stringLiteral2386E77CF610F786B06A91AF2C1B3FD2282D2745;
IL2CPP_EXTERN_C String_t* _stringLiteral2ACA29C4E59869B5D453E2775263A84E06EDA03D;
IL2CPP_EXTERN_C String_t* _stringLiteral3A5D56B26B1A9CEDE88C8DBEC1D7FF8296992654;
IL2CPP_EXTERN_C String_t* _stringLiteral3A8647DA913120027BE0BCA389585AB5B1E2C75D;
IL2CPP_EXTERN_C String_t* _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0;
IL2CPP_EXTERN_C String_t* _stringLiteral3C4F52AE03EA8FEF5DEAA4BF1DCF2792C970C821;
IL2CPP_EXTERN_C String_t* _stringLiteral514D6E12CA97253D25F742A6EB2CC9B8B2EE8149;
IL2CPP_EXTERN_C String_t* _stringLiteral5934735AA968E0CB7CB39062B758A93F76F5591C;
IL2CPP_EXTERN_C String_t* _stringLiteral5FCA7CBE61ADC605F9F35C467CFE5D765D935400;
IL2CPP_EXTERN_C String_t* _stringLiteral622B9A1A51AC02C383A8F43FC542A76D2C0AF6A2;
IL2CPP_EXTERN_C String_t* _stringLiteral6866F44FE25F48E7BF04C35DA2F4C670D2021A33;
IL2CPP_EXTERN_C String_t* _stringLiteral74DA73DF8411070FEB987DE79D4529EE39FB3D96;
IL2CPP_EXTERN_C String_t* _stringLiteral760865C55F22E06913EE529E43E0A4EC6D4C2957;
IL2CPP_EXTERN_C String_t* _stringLiteral780401B090EAF1BCE81DDE534AEE885AE001D0DB;
IL2CPP_EXTERN_C String_t* _stringLiteral7D88FE441DA1C11DA793F92B7B7665BEED176766;
IL2CPP_EXTERN_C String_t* _stringLiteral80F799C8D4F8B264EFFA6ADAB5F6D1169403E1C4;
IL2CPP_EXTERN_C String_t* _stringLiteral8174CA9CD84F86539853890382CF5C587FB8B9BE;
IL2CPP_EXTERN_C String_t* _stringLiteral85E4DD1872CA9889B201BF423506257FB4DB467C;
IL2CPP_EXTERN_C String_t* _stringLiteral86037F1A053094FF729BA5C5CACF4EDF8B6B38A3;
IL2CPP_EXTERN_C String_t* _stringLiteral8635E0BF76851ADF21ED9AAEC3F8566DAE26898E;
IL2CPP_EXTERN_C String_t* _stringLiteral8E59446B468A9A7AC0FBE64297CB598A1D6DD96C;
IL2CPP_EXTERN_C String_t* _stringLiteral900D858FE9ABCD2ED2B25CD27110A78ADCC6EC6B;
IL2CPP_EXTERN_C String_t* _stringLiteral9844A7472D6104C0F2F6D65CB10A10F7C0C637C0;
IL2CPP_EXTERN_C String_t* _stringLiteral9B9EF66DAA3B5CC54EF182295D9A9980A1C9B23D;
IL2CPP_EXTERN_C String_t* _stringLiteral9F15982CC17EE718C2AFB3B1C125ACC1A65D2362;
IL2CPP_EXTERN_C String_t* _stringLiteralA7BF1F00A512D96C33F2BBA9B709990FB1899ECF;
IL2CPP_EXTERN_C String_t* _stringLiteralA8B948094C8FA05C32A4A7D097D73A3418E2EEA1;
IL2CPP_EXTERN_C String_t* _stringLiteralB31A5E45A7336CF4E926743AF852C59783F5D947;
IL2CPP_EXTERN_C String_t* _stringLiteralC8AFE89D158D2722B833D3EB38ECF175C82B1722;
IL2CPP_EXTERN_C String_t* _stringLiteralCB34F9B2DD59C1BD2C15FA5E7192661406CCDF4C;
IL2CPP_EXTERN_C String_t* _stringLiteralCC53E2F11D267A4FEC8C78116C6E1E0AC0021CA5;
IL2CPP_EXTERN_C String_t* _stringLiteralCEA0ED0066879A12EF7428466404FD5A318EEDDA;
IL2CPP_EXTERN_C String_t* _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709;
IL2CPP_EXTERN_C String_t* _stringLiteralF3D711BA856837A5D3C34CA2103E03C173D6F4C7;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_TryGetValue_m0F9A65F9363E92E29717C15EEEA8A71A2DB8D402_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_m39AE7A2B779870855E3AC853F234C40F6735ACF9_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_get_Values_m923D794849584E9B0675E86D09B54BA6691944D2_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ValueCollection_GetEnumerator_m88DC4BD4D4952C7D4B15BE9CC164DF1EAA69A197_RuntimeMethod_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95_marshaled_com;
struct GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95_marshaled_pinvoke;
struct GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_marshaled_com;
struct GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_marshaled_pinvoke;
struct RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5_marshaled_com;

struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct GUILayoutOptionU5BU5D_t24AB80AB9355D784F2C65E12A4D0CC2E0C914CA2;
struct GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Collections.Generic.Dictionary`2<System.String,UnityEngine.GUIStyle>
struct Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_tAEFE165DEE6FDB9F2B657E11D15B8C95DD88B0C2* ____entries_1;
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
	KeyCollection_t851423C7344032A1F54545C69FC6507778294D6C* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_t6CD4B9552B29D570FBA4E0145D0C98841ECCC8C1* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.Collections.Generic.Dictionary`2/ValueCollection<System.String,UnityEngine.GUIStyle>
struct ValueCollection_t6CD4B9552B29D570FBA4E0145D0C98841ECCC8C1  : public RuntimeObject
{
	// System.Collections.Generic.Dictionary`2<TKey,TValue> System.Collections.Generic.Dictionary`2/ValueCollection::_dictionary
	Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* ____dictionary_0;
};

// <PrivateImplementationDetails>
struct U3CPrivateImplementationDetailsU3E_tCA0A4120E1B13462A402E739CE2DD9CA72BAC713  : public RuntimeObject
{
};

// System.Reflection.MemberInfo
struct MemberInfo_t  : public RuntimeObject
{
};

// UnityEngine.SliderState
struct SliderState_t7BBFAEF918BAA1EE6116C3979993E4EC7DC54FC8  : public RuntimeObject
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

// System.StringComparer
struct StringComparer_t6268F19CA34879176651429C0D8A3D0002BB8E06  : public RuntimeObject
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

// System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator<System.Object,System.Object>
struct Enumerator_t44124D16E0B2F7308FF4069BE06369B5A83896EB 
{
	// System.Collections.Generic.Dictionary`2<TKey,TValue> System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator::_dictionary
	Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* ____dictionary_0;
	// System.Int32 System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator::_index
	int32_t ____index_1;
	// System.Int32 System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator::_version
	int32_t ____version_2;
	// TValue System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator::_currentValue
	RuntimeObject* ____currentValue_3;
};

// System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator<System.String,UnityEngine.GUIStyle>
struct Enumerator_t6FCF94B18593967BB1EA62E38DDD1FA537144AA9 
{
	// System.Collections.Generic.Dictionary`2<TKey,TValue> System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator::_dictionary
	Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* ____dictionary_0;
	// System.Int32 System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator::_index
	int32_t ____index_1;
	// System.Int32 System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator::_version
	int32_t ____version_2;
	// TValue System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator::_currentValue
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ____currentValue_3;
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

// UnityEngine.Color
struct Color_tD001788D726C3A7F1379BEED0260B9591F440C1F 
{
	// System.Single UnityEngine.Color::r
	float ___r_0;
	// System.Single UnityEngine.Color::g
	float ___g_1;
	// System.Single UnityEngine.Color::b
	float ___b_2;
	// System.Single UnityEngine.Color::a
	float ___a_3;
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

// System.OrdinalComparer
struct OrdinalComparer_tBB06915E213A5D4C8C617ED5478E8BF30C2B2170  : public StringComparer_t6268F19CA34879176651429C0D8A3D0002BB8E06
{
	// System.Boolean System.OrdinalComparer::_ignoreCase
	bool ____ignoreCase_4;
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

// System.UInt32
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	// System.UInt32 System.UInt32::m_value
	uint32_t ___m_value_0;
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

// UnityEngine.Event
struct Event_tEBC6F24B56CE22B9C9AD1AC6C24A6B83BC3860CB  : public RuntimeObject
{
	// System.IntPtr UnityEngine.Event::m_Ptr
	intptr_t ___m_Ptr_0;
};
// Native definition for P/Invoke marshalling of UnityEngine.Event
struct Event_tEBC6F24B56CE22B9C9AD1AC6C24A6B83BC3860CB_marshaled_pinvoke
{
	intptr_t ___m_Ptr_0;
};
// Native definition for COM marshalling of UnityEngine.Event
struct Event_tEBC6F24B56CE22B9C9AD1AC6C24A6B83BC3860CB_marshaled_com
{
	intptr_t ___m_Ptr_0;
};

// UnityEngine.EventType
struct EventType_tC62F0D77DB08D7326B58B2D8CF43BD45CFD3203E 
{
	// System.Int32 UnityEngine.EventType::value__
	int32_t ___value___2;
};

// UnityEngine.GUILayoutEntry
struct GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F  : public RuntimeObject
{
	// System.Single UnityEngine.GUILayoutEntry::minWidth
	float ___minWidth_0;
	// System.Single UnityEngine.GUILayoutEntry::maxWidth
	float ___maxWidth_1;
	// System.Single UnityEngine.GUILayoutEntry::minHeight
	float ___minHeight_2;
	// System.Single UnityEngine.GUILayoutEntry::maxHeight
	float ___maxHeight_3;
	// UnityEngine.Rect UnityEngine.GUILayoutEntry::rect
	Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D ___rect_4;
	// System.Int32 UnityEngine.GUILayoutEntry::stretchWidth
	int32_t ___stretchWidth_5;
	// System.Int32 UnityEngine.GUILayoutEntry::stretchHeight
	int32_t ___stretchHeight_6;
	// System.Boolean UnityEngine.GUILayoutEntry::consideredForMargin
	bool ___consideredForMargin_7;
	// UnityEngine.GUIStyle UnityEngine.GUILayoutEntry::m_Style
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_Style_8;
};

// UnityEngine.GUISettings
struct GUISettings_tF2CA7E8B9F62F1FC013BFF053B5FA2709EBA3847  : public RuntimeObject
{
	// System.Boolean UnityEngine.GUISettings::m_DoubleClickSelectsWord
	bool ___m_DoubleClickSelectsWord_0;
	// System.Boolean UnityEngine.GUISettings::m_TripleClickSelectsLine
	bool ___m_TripleClickSelectsLine_1;
	// UnityEngine.Color UnityEngine.GUISettings::m_CursorColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_CursorColor_2;
	// System.Single UnityEngine.GUISettings::m_CursorFlashSpeed
	float ___m_CursorFlashSpeed_3;
	// UnityEngine.Color UnityEngine.GUISettings::m_SelectionColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_SelectionColor_4;
};

// UnityEngine.GUIStyleState
struct GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95  : public RuntimeObject
{
	// System.IntPtr UnityEngine.GUIStyleState::m_Ptr
	intptr_t ___m_Ptr_0;
	// UnityEngine.GUIStyle UnityEngine.GUIStyleState::m_SourceStyle
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_SourceStyle_1;
};
// Native definition for P/Invoke marshalling of UnityEngine.GUIStyleState
struct GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95_marshaled_pinvoke
{
	intptr_t ___m_Ptr_0;
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_marshaled_pinvoke* ___m_SourceStyle_1;
};
// Native definition for COM marshalling of UnityEngine.GUIStyleState
struct GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95_marshaled_com
{
	intptr_t ___m_Ptr_0;
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_marshaled_com* ___m_SourceStyle_1;
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

// System.OrdinalIgnoreCaseComparer
struct OrdinalIgnoreCaseComparer_t8BAE11990A4C855D3BCBBFB42F4EF8D45088FBB0  : public OrdinalComparer_tBB06915E213A5D4C8C617ED5478E8BF30C2B2170
{
};

// UnityEngine.RectOffset
struct RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5  : public RuntimeObject
{
	// System.IntPtr UnityEngine.RectOffset::m_Ptr
	intptr_t ___m_Ptr_0;
	// System.Object UnityEngine.RectOffset::m_SourceStyle
	RuntimeObject* ___m_SourceStyle_1;
};
// Native definition for P/Invoke marshalling of UnityEngine.RectOffset
struct RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5_marshaled_pinvoke
{
	intptr_t ___m_Ptr_0;
	Il2CppIUnknown* ___m_SourceStyle_1;
};
// Native definition for COM marshalling of UnityEngine.RectOffset
struct RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5_marshaled_com
{
	intptr_t ___m_Ptr_0;
	Il2CppIUnknown* ___m_SourceStyle_1;
};

// System.RuntimeTypeHandle
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	// System.IntPtr System.RuntimeTypeHandle::value
	intptr_t ___value_0;
};

// UnityEngine.GUILayoutOption/Type
struct Type_t94B090894A3B9A5C5AEBD91800DB10688CC00F4A 
{
	// System.Int32 UnityEngine.GUILayoutOption/Type::value__
	int32_t ___value___2;
};

// UnityEngine.Font
struct Font_tC95270EA3198038970422D78B74A7F2E218A96B6  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
	// UnityEngine.Font/FontTextureRebuildCallback UnityEngine.Font::m_FontTextureRebuildCallback
	FontTextureRebuildCallback_t76D5E172DF8AA57E67763D453AAC40F0961D09B1* ___m_FontTextureRebuildCallback_5;
};

// UnityEngine.GUILayoutOption
struct GUILayoutOption_t8B0AA056521747053A3176FCC43E9C3608940A14  : public RuntimeObject
{
	// UnityEngine.GUILayoutOption/Type UnityEngine.GUILayoutOption::type
	int32_t ___type_0;
	// System.Object UnityEngine.GUILayoutOption::value
	RuntimeObject* ___value_1;
};

// UnityEngine.GUIStyle
struct GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580  : public RuntimeObject
{
	// System.IntPtr UnityEngine.GUIStyle::m_Ptr
	intptr_t ___m_Ptr_0;
	// UnityEngine.GUIStyleState UnityEngine.GUIStyle::m_Normal
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95* ___m_Normal_1;
	// UnityEngine.GUIStyleState UnityEngine.GUIStyle::m_Hover
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95* ___m_Hover_2;
	// UnityEngine.GUIStyleState UnityEngine.GUIStyle::m_Active
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95* ___m_Active_3;
	// UnityEngine.GUIStyleState UnityEngine.GUIStyle::m_Focused
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95* ___m_Focused_4;
	// UnityEngine.GUIStyleState UnityEngine.GUIStyle::m_OnNormal
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95* ___m_OnNormal_5;
	// UnityEngine.GUIStyleState UnityEngine.GUIStyle::m_OnHover
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95* ___m_OnHover_6;
	// UnityEngine.GUIStyleState UnityEngine.GUIStyle::m_OnActive
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95* ___m_OnActive_7;
	// UnityEngine.GUIStyleState UnityEngine.GUIStyle::m_OnFocused
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95* ___m_OnFocused_8;
	// UnityEngine.RectOffset UnityEngine.GUIStyle::m_Border
	RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5* ___m_Border_9;
	// UnityEngine.RectOffset UnityEngine.GUIStyle::m_Padding
	RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5* ___m_Padding_10;
	// UnityEngine.RectOffset UnityEngine.GUIStyle::m_Margin
	RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5* ___m_Margin_11;
	// UnityEngine.RectOffset UnityEngine.GUIStyle::m_Overflow
	RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5* ___m_Overflow_12;
	// System.String UnityEngine.GUIStyle::m_Name
	String_t* ___m_Name_13;
};
// Native definition for P/Invoke marshalling of UnityEngine.GUIStyle
struct GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_marshaled_pinvoke
{
	intptr_t ___m_Ptr_0;
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95_marshaled_pinvoke* ___m_Normal_1;
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95_marshaled_pinvoke* ___m_Hover_2;
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95_marshaled_pinvoke* ___m_Active_3;
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95_marshaled_pinvoke* ___m_Focused_4;
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95_marshaled_pinvoke* ___m_OnNormal_5;
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95_marshaled_pinvoke* ___m_OnHover_6;
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95_marshaled_pinvoke* ___m_OnActive_7;
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95_marshaled_pinvoke* ___m_OnFocused_8;
	RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5_marshaled_pinvoke ___m_Border_9;
	RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5_marshaled_pinvoke ___m_Padding_10;
	RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5_marshaled_pinvoke ___m_Margin_11;
	RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5_marshaled_pinvoke ___m_Overflow_12;
	char* ___m_Name_13;
};
// Native definition for COM marshalling of UnityEngine.GUIStyle
struct GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_marshaled_com
{
	intptr_t ___m_Ptr_0;
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95_marshaled_com* ___m_Normal_1;
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95_marshaled_com* ___m_Hover_2;
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95_marshaled_com* ___m_Active_3;
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95_marshaled_com* ___m_Focused_4;
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95_marshaled_com* ___m_OnNormal_5;
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95_marshaled_com* ___m_OnHover_6;
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95_marshaled_com* ___m_OnActive_7;
	GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95_marshaled_com* ___m_OnFocused_8;
	RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5_marshaled_com* ___m_Border_9;
	RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5_marshaled_com* ___m_Padding_10;
	RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5_marshaled_com* ___m_Margin_11;
	RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5_marshaled_com* ___m_Overflow_12;
	Il2CppChar* ___m_Name_13;
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

// System.Type
struct Type_t  : public MemberInfo_t
{
	// System.RuntimeTypeHandle System.Type::_impl
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl_8;
};

// UnityEngine.GUISkin
struct GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9  : public ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A
{
	// UnityEngine.Font UnityEngine.GUISkin::m_Font
	Font_tC95270EA3198038970422D78B74A7F2E218A96B6* ___m_Font_4;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_box
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_box_5;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_button
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_button_6;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_toggle
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_toggle_7;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_label
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_label_8;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_textField
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_textField_9;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_textArea
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_textArea_10;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_window
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_window_11;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_horizontalSlider
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_horizontalSlider_12;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_horizontalSliderThumb
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_horizontalSliderThumb_13;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_horizontalSliderThumbExtent
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_horizontalSliderThumbExtent_14;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_verticalSlider
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_verticalSlider_15;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_verticalSliderThumb
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_verticalSliderThumb_16;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_verticalSliderThumbExtent
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_verticalSliderThumbExtent_17;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_SliderMixed
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_SliderMixed_18;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_horizontalScrollbar
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_horizontalScrollbar_19;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_horizontalScrollbarThumb
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_horizontalScrollbarThumb_20;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_horizontalScrollbarLeftButton
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_horizontalScrollbarLeftButton_21;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_horizontalScrollbarRightButton
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_horizontalScrollbarRightButton_22;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_verticalScrollbar
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_verticalScrollbar_23;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_verticalScrollbarThumb
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_verticalScrollbarThumb_24;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_verticalScrollbarUpButton
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_verticalScrollbarUpButton_25;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_verticalScrollbarDownButton
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_verticalScrollbarDownButton_26;
	// UnityEngine.GUIStyle UnityEngine.GUISkin::m_ScrollView
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___m_ScrollView_27;
	// UnityEngine.GUIStyle[] UnityEngine.GUISkin::m_CustomStyles
	GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC* ___m_CustomStyles_28;
	// UnityEngine.GUISettings UnityEngine.GUISkin::m_Settings
	GUISettings_tF2CA7E8B9F62F1FC013BFF053B5FA2709EBA3847* ___m_Settings_29;
	// System.Collections.Generic.Dictionary`2<System.String,UnityEngine.GUIStyle> UnityEngine.GUISkin::m_Styles
	Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* ___m_Styles_31;
};

// UnityEngine.GUISkin/SkinChangedDelegate
struct SkinChangedDelegate_tA6D456E853D58AD2EF8A599F543C7E5BA8E94B98  : public MulticastDelegate_t
{
};

// System.Collections.Generic.Dictionary`2<System.String,UnityEngine.GUIStyle>

// System.Collections.Generic.Dictionary`2<System.String,UnityEngine.GUIStyle>

// System.Collections.Generic.Dictionary`2/ValueCollection<System.String,UnityEngine.GUIStyle>

// System.Collections.Generic.Dictionary`2/ValueCollection<System.String,UnityEngine.GUIStyle>

// <PrivateImplementationDetails>

// <PrivateImplementationDetails>

// UnityEngine.SliderState

// UnityEngine.SliderState

// System.String
struct String_t_StaticFields
{
	// System.String System.String::Empty
	String_t* ___Empty_6;
};

// System.String

// System.StringComparer
struct StringComparer_t6268F19CA34879176651429C0D8A3D0002BB8E06_StaticFields
{
	// System.CultureAwareComparer System.StringComparer::s_invariantCulture
	CultureAwareComparer_t5822A6535A6EB4C448D1B7736067D1188BAEE8CD* ___s_invariantCulture_0;
	// System.CultureAwareComparer System.StringComparer::s_invariantCultureIgnoreCase
	CultureAwareComparer_t5822A6535A6EB4C448D1B7736067D1188BAEE8CD* ___s_invariantCultureIgnoreCase_1;
	// System.OrdinalCaseSensitiveComparer System.StringComparer::s_ordinal
	OrdinalCaseSensitiveComparer_t581CA7CB51DCF00B6012A697A4B4B3067144521A* ___s_ordinal_2;
	// System.OrdinalIgnoreCaseComparer System.StringComparer::s_ordinalIgnoreCase
	OrdinalIgnoreCaseComparer_t8BAE11990A4C855D3BCBBFB42F4EF8D45088FBB0* ___s_ordinalIgnoreCase_3;
};

// System.StringComparer

// System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator<System.Object,System.Object>

// System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator<System.Object,System.Object>

// System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator<System.String,UnityEngine.GUIStyle>

// System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator<System.String,UnityEngine.GUIStyle>

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

// UnityEngine.Color

// UnityEngine.Color

// System.Enum
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_StaticFields
{
	// System.Char[] System.Enum::enumSeperatorCharArray
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___enumSeperatorCharArray_0;
};

// System.Enum

// System.Int32

// System.Int32

// System.IntPtr
struct IntPtr_t_StaticFields
{
	// System.IntPtr System.IntPtr::Zero
	intptr_t ___Zero_1;
};

// System.IntPtr

// UnityEngine.Rect

// UnityEngine.Rect

// System.Single

// System.Single

// System.UInt32

// System.UInt32

// System.Void

// System.Void

// System.Delegate

// System.Delegate

// UnityEngine.Event
struct Event_tEBC6F24B56CE22B9C9AD1AC6C24A6B83BC3860CB_StaticFields
{
	// UnityEngine.Event UnityEngine.Event::s_Current
	Event_tEBC6F24B56CE22B9C9AD1AC6C24A6B83BC3860CB* ___s_Current_1;
	// UnityEngine.Event UnityEngine.Event::s_MasterEvent
	Event_tEBC6F24B56CE22B9C9AD1AC6C24A6B83BC3860CB* ___s_MasterEvent_2;
};

// UnityEngine.Event

// UnityEngine.EventType

// UnityEngine.EventType

// UnityEngine.GUILayoutEntry
struct GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F_StaticFields
{
	// UnityEngine.Rect UnityEngine.GUILayoutEntry::kDummyRect
	Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D ___kDummyRect_9;
	// System.Int32 UnityEngine.GUILayoutEntry::indent
	int32_t ___indent_10;
};

// UnityEngine.GUILayoutEntry

// UnityEngine.GUISettings

// UnityEngine.GUISettings

// UnityEngine.GUIStyleState

// UnityEngine.GUIStyleState

// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_StaticFields
{
	// System.Int32 UnityEngine.Object::OffsetOfInstanceIDInCPlusPlusObject
	int32_t ___OffsetOfInstanceIDInCPlusPlusObject_1;
};

// UnityEngine.Object

// System.OrdinalIgnoreCaseComparer

// System.OrdinalIgnoreCaseComparer

// UnityEngine.RectOffset

// UnityEngine.RectOffset

// UnityEngine.GUILayoutOption/Type

// UnityEngine.GUILayoutOption/Type

// UnityEngine.Font
struct Font_tC95270EA3198038970422D78B74A7F2E218A96B6_StaticFields
{
	// System.Action`1<UnityEngine.Font> UnityEngine.Font::textureRebuilt
	Action_1_tD91E4D0ED3C2E385D3BDD4B3EA48B5F99D39F1DC* ___textureRebuilt_4;
};

// UnityEngine.Font

// UnityEngine.GUILayoutOption

// UnityEngine.GUILayoutOption

// UnityEngine.GUIStyle
struct GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_StaticFields
{
	// System.Boolean UnityEngine.GUIStyle::showKeyboardFocus
	bool ___showKeyboardFocus_14;
	// UnityEngine.GUIStyle UnityEngine.GUIStyle::s_None
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___s_None_15;
};

// UnityEngine.GUIStyle

// UnityEngine.ScriptableObject

// UnityEngine.ScriptableObject

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

// UnityEngine.GUISkin
struct GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_StaticFields
{
	// UnityEngine.GUIStyle UnityEngine.GUISkin::ms_Error
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___ms_Error_30;
	// UnityEngine.GUISkin/SkinChangedDelegate UnityEngine.GUISkin::m_SkinChanged
	SkinChangedDelegate_tA6D456E853D58AD2EF8A599F543C7E5BA8E94B98* ___m_SkinChanged_32;
	// UnityEngine.GUISkin UnityEngine.GUISkin::current
	GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* ___current_33;
};

// UnityEngine.GUISkin

// UnityEngine.GUISkin/SkinChangedDelegate

// UnityEngine.GUISkin/SkinChangedDelegate
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// UnityEngine.GUIStyle[]
struct GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC  : public RuntimeArray
{
	ALIGN_FIELD (8) GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* m_Items[1];

	inline GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* value)
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
// UnityEngine.GUILayoutOption[]
struct GUILayoutOptionU5BU5D_t24AB80AB9355D784F2C65E12A4D0CC2E0C914CA2  : public RuntimeArray
{
	ALIGN_FIELD (8) GUILayoutOption_t8B0AA056521747053A3176FCC43E9C3608940A14* m_Items[1];

	inline GUILayoutOption_t8B0AA056521747053A3176FCC43E9C3608940A14* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline GUILayoutOption_t8B0AA056521747053A3176FCC43E9C3608940A14** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, GUILayoutOption_t8B0AA056521747053A3176FCC43E9C3608940A14* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline GUILayoutOption_t8B0AA056521747053A3176FCC43E9C3608940A14* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline GUILayoutOption_t8B0AA056521747053A3176FCC43E9C3608940A14** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, GUILayoutOption_t8B0AA056521747053A3176FCC43E9C3608940A14* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
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


// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::.ctor(System.Collections.Generic.IEqualityComparer`1<TKey>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_mB2760A703784902BE10E873BC760166EC9693D63_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::set_Item(TKey,TValue)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_m1A840355E8EDAECEA9D0C6F5E51B248FAA449CBD_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Object>::TryGetValue(TKey,TValue&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryGetValue_mD15380A4ED7CDEE99EA45881577D26BA9CE1B849_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, RuntimeObject** ___1_value, const RuntimeMethod* method) ;
// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2<System.Object,System.Object>::get_Values()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueCollection_t038245E04B5D2A80048D9F8021A23E69A0C9DBAA* Dictionary_2_get_Values_mA0C01DEA55329E55380E96BBD04D4D228B437EC5_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, const RuntimeMethod* method) ;
// System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator<TKey,TValue> System.Collections.Generic.Dictionary`2/ValueCollection<System.Object,System.Object>::GetEnumerator()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t44124D16E0B2F7308FF4069BE06369B5A83896EB ValueCollection_GetEnumerator_m025EE28BE2F31676E08BC3D7C8E39D8232BDBBF8_gshared (ValueCollection_t038245E04B5D2A80048D9F8021A23E69A0C9DBAA* __this, const RuntimeMethod* method) ;

// System.Void UnityEngine.GUISettings::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISettings__ctor_m4AA9AFBD94306E007937909CB7F542DF2E491404 (GUISettings_tF2CA7E8B9F62F1FC013BFF053B5FA2709EBA3847* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.ScriptableObject::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ScriptableObject__ctor_mD037FDB0B487295EA47F79A4DB1BF1846C9087FF (ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.GUISkin::Apply()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Object::op_Equality(UnityEngine.Object,UnityEngine.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_x, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_y, const RuntimeMethod* method) ;
// System.Void UnityEngine.GUIStyle::SetDefaultFont(UnityEngine.Font)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUIStyle_SetDefaultFont_mD6B98375749805CA5084CA8C5D6A1295359AE0E3 (Font_tC95270EA3198038970422D78B74A7F2E218A96B6* ___0_font, const RuntimeMethod* method) ;
// System.Void UnityEngine.GUIStyle::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9 (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.GUIStyle::set_name(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020 (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* __this, String_t* ___0_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.Debug::Log(System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Debug_Log_m87A9A3C761FF5C43ED8A53B16190A53D08F818BB (RuntimeObject* ___0_message, const RuntimeMethod* method) ;
// System.Void UnityEngine.GUISkin::BuildStyleCache()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_BuildStyleCache_m8E99CC278C76A6DA63A24BFD2DE42AE313C0F7E1 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) ;
// System.StringComparer System.StringComparer::get_OrdinalIgnoreCase()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR StringComparer_t6268F19CA34879176651429C0D8A3D0002BB8E06* StringComparer_get_OrdinalIgnoreCase_m071AA1B1747345CCA058A3879EBDEBBA2EA4B169_inline (const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.String,UnityEngine.GUIStyle>::.ctor(System.Collections.Generic.IEqualityComparer`1<TKey>)
inline void Dictionary_2__ctor_m39AE7A2B779870855E3AC853F234C40F6735ACF9 (Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F*, RuntimeObject*, const RuntimeMethod*))Dictionary_2__ctor_mB2760A703784902BE10E873BC760166EC9693D63_gshared)(__this, ___0_comparer, method);
}
// System.Void System.Collections.Generic.Dictionary`2<System.String,UnityEngine.GUIStyle>::set_Item(TKey,TValue)
inline void Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0 (Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* __this, String_t* ___0_key, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F*, String_t*, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*, const RuntimeMethod*))Dictionary_2_set_Item_m1A840355E8EDAECEA9D0C6F5E51B248FAA449CBD_gshared)(__this, ___0_key, ___1_value, method);
}
// System.String UnityEngine.GUIStyle::get_name()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* GUIStyle_get_name_mDF9EF43C46A0B9431DAF4EB0CE1D18EA32E16B75 (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* __this, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<System.String,UnityEngine.GUIStyle>::TryGetValue(TKey,TValue&)
inline bool Dictionary_2_TryGetValue_m0F9A65F9363E92E29717C15EEEA8A71A2DB8D402 (Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* __this, String_t* ___0_key, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580** ___1_value, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F*, String_t*, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580**, const RuntimeMethod*))Dictionary_2_TryGetValue_mD15380A4ED7CDEE99EA45881577D26BA9CE1B849_gshared)(__this, ___0_key, ___1_value, method);
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_error()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_error_mB953A37C8F3296E529190A34E18506C735848C01 (const RuntimeMethod* method) ;
// System.Void UnityEngine.GUIStyle::set_stretchHeight(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUIStyle_set_stretchHeight_m51C55ED43AA4EDE125E0C423FA0D301E81C09378 (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* __this, bool ___0_value, const RuntimeMethod* method) ;
// UnityEngine.GUIStyleState UnityEngine.GUIStyle::get_normal()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95* GUIStyle_get_normal_mDEA2808FBD692E505784BD9E521738B4321BCA8F (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* __this, const RuntimeMethod* method) ;
// UnityEngine.Color UnityEngine.Color::get_red()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Color_tD001788D726C3A7F1379BEED0260B9591F440C1F Color_get_red_mA2E53E7173FDC97E68E335049AB0FAAEE43A844D_inline (const RuntimeMethod* method) ;
// System.Void UnityEngine.GUIStyleState::set_textColor(UnityEngine.Color)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUIStyleState_set_textColor_m5868D12858E6402247953BCCDDA7A543BE6084F1 (GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95* __this, Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___0_value, const RuntimeMethod* method) ;
// UnityEngine.GUIStyle UnityEngine.GUISkin::FindStyle(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_FindStyle_mF82C37E2481D2B9E96C26EFE0353F8954F844FFE (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, String_t* ___0_styleName, const RuntimeMethod* method) ;
// System.String UnityEngine.Object::get_name()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* __this, const RuntimeMethod* method) ;
// UnityEngine.Event UnityEngine.Event::get_current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Event_tEBC6F24B56CE22B9C9AD1AC6C24A6B83BC3860CB* Event_get_current_mBD7135E10C392EAD61AC0A0D2489EF758C8A3FAD (const RuntimeMethod* method) ;
// UnityEngine.EventType UnityEngine.Event::get_type()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Event_get_type_m8A825D6DA432B967DAA3E22E5C8571620A75F8A8 (Event_tEBC6F24B56CE22B9C9AD1AC6C24A6B83BC3860CB* __this, const RuntimeMethod* method) ;
// System.String System.Enum::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Enum_ToString_m946B0B83C4470457D0FF555D862022C72BB55741 (RuntimeObject* __this, const RuntimeMethod* method) ;
// System.String System.String::Concat(System.String[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m647EBF831F54B6DF7D5AFA5FD012CF4EE7571B6A (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___0_values, const RuntimeMethod* method) ;
// System.Void UnityEngine.Debug::LogWarning(System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Debug_LogWarning_m33EF1B897E0C7C6FF538989610BFAFFEF4628CA9 (RuntimeObject* ___0_message, const RuntimeMethod* method) ;
// UnityEngine.Font UnityEngine.GUISkin::get_font()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Font_tC95270EA3198038970422D78B74A7F2E218A96B6* GUISkin_get_font_m806CF702C59E43DF55BA441030A60F80E9D8CFD5 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.GUISkin/SkinChangedDelegate::Invoke()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void SkinChangedDelegate_Invoke_mD14214487F9A0E4DD7EB7F97927D03EC8F1A3B4C_inline (SkinChangedDelegate_tA6D456E853D58AD2EF8A599F543C7E5BA8E94B98* __this, const RuntimeMethod* method) ;
// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2<System.String,UnityEngine.GUIStyle>::get_Values()
inline ValueCollection_t6CD4B9552B29D570FBA4E0145D0C98841ECCC8C1* Dictionary_2_get_Values_m923D794849584E9B0675E86D09B54BA6691944D2 (Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* __this, const RuntimeMethod* method)
{
	return ((  ValueCollection_t6CD4B9552B29D570FBA4E0145D0C98841ECCC8C1* (*) (Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F*, const RuntimeMethod*))Dictionary_2_get_Values_mA0C01DEA55329E55380E96BBD04D4D228B437EC5_gshared)(__this, method);
}
// System.Collections.Generic.Dictionary`2/ValueCollection/Enumerator<TKey,TValue> System.Collections.Generic.Dictionary`2/ValueCollection<System.String,UnityEngine.GUIStyle>::GetEnumerator()
inline Enumerator_t6FCF94B18593967BB1EA62E38DDD1FA537144AA9 ValueCollection_GetEnumerator_m88DC4BD4D4952C7D4B15BE9CC164DF1EAA69A197 (ValueCollection_t6CD4B9552B29D570FBA4E0145D0C98841ECCC8C1* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t6FCF94B18593967BB1EA62E38DDD1FA537144AA9 (*) (ValueCollection_t6CD4B9552B29D570FBA4E0145D0C98841ECCC8C1*, const RuntimeMethod*))ValueCollection_GetEnumerator_m025EE28BE2F31676E08BC3D7C8E39D8232BDBBF8_gshared)(__this, method);
}
// System.Void System.Object::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
// UnityEngine.GUIStyle UnityEngine.GUILayoutEntry::get_style()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUILayoutEntry_get_style_mEFB6A8443849EC32BD84059C09632B53E44A5876 (GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* __this, const RuntimeMethod* method) ;
// UnityEngine.RectOffset UnityEngine.GUIStyle::get_margin()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5* GUIStyle_get_margin_mD0AABA2CB3FB0CFC3C414635E6225D3003315D1B (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* __this, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.RectOffset::get_left()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RectOffset_get_left_mA406D7AFF76E48507EF143CDB1D157C4D5430D90 (RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5* __this, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.RectOffset::get_right()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RectOffset_get_right_m07C826B0BC79B0CBC01F5FF489D456C553F047BF (RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5* __this, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.RectOffset::get_top()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RectOffset_get_top_m82E49FB93A5BD417131136F5A7DBA0F251F10263 (RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5* __this, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.RectOffset::get_bottom()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RectOffset_get_bottom_mDF9C1EC125F94245D5532C34FCFB65BE0F2A9D0B (RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.Rect::.ctor(System.Single,System.Single,System.Single,System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Rect__ctor_m18C3033D135097BEE424AAA68D91C706D2647F23 (Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* __this, float ___0_x, float ___1_y, float ___2_width, float ___3_height, const RuntimeMethod* method) ;
// UnityEngine.GUIStyle UnityEngine.GUIStyle::get_none()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUIStyle_get_none_m808A9FE1F78920E4A29ED3484B99588B46D88938 (const RuntimeMethod* method) ;
// System.Void UnityEngine.GUILayoutEntry::set_style(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUILayoutEntry_set_style_m0A23F7EFF504A581FC6CA86EF3BE753F060AC48A (GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.Rect::set_x(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Rect_set_x_mAB91AB71898A20762BC66FD0723C4C739C4C3406 (Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* __this, float ___0_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.Rect::set_width(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Rect_set_width_m93B6217CF3EFF89F9B0C81F34D7345DE90B93E5A (Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* __this, float ___0_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.Rect::set_y(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Rect_set_y_mDE91F4B98A6E8623EFB1250FF6526D5DB5855629 (Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* __this, float ___0_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.Rect::set_height(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Rect_set_height_mD00038E6E06637137A5626CA8CD421924005BF03 (Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* __this, float ___0_value, const RuntimeMethod* method) ;
// System.Single UnityEngine.GUIStyle::get_fixedWidth()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float GUIStyle_get_fixedWidth_m9CB5B4E096287F75F4E4E3376590C7C085E28DE8 (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.GUIStyle::get_stretchWidth()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool GUIStyle_get_stretchWidth_m528FFD3EB3104D0322F2EADBBE7DBFF3FB34CB37 (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* __this, const RuntimeMethod* method) ;
// System.Single UnityEngine.GUIStyle::get_fixedHeight()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float GUIStyle_get_fixedHeight_m009155CF284509A87E6037D0A392A630FA728F7A (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.GUIStyle::get_stretchHeight()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool GUIStyle_get_stretchHeight_m5ACA8F9CD25746932719C927159A105AADA5061F (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* __this, const RuntimeMethod* method) ;
// System.String System.String::Concat(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m9E3155FB84015C823606188F53B47CB44C444991 (String_t* ___0_str0, String_t* ___1_str1, const RuntimeMethod* method) ;
// System.Type System.Object::GetType()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3 (RuntimeObject* __this, const RuntimeMethod* method) ;
// System.Single UnityEngine.Rect::get_x()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Rect_get_x_mB267B718E0D067F2BAE31BA477647FBF964916EB (Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* __this, const RuntimeMethod* method) ;
// System.Single UnityEngine.Rect::get_xMax()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Rect_get_xMax_m2339C7D2FCDA98A9B007F815F6E2059BA6BE425F (Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* __this, const RuntimeMethod* method) ;
// System.Single UnityEngine.Rect::get_y()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Rect_get_y_mC733E8D49F3CE21B2A3D40A1B72D687F22C97F49 (Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* __this, const RuntimeMethod* method) ;
// System.Single UnityEngine.Rect::get_yMax()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Rect_get_yMax_mBC37BEE1CD632AADD8B9EAF9FE3BA143F79CAF8E (Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* __this, const RuntimeMethod* method) ;
// System.String UnityEngine.UnityString::Format(System.String,System.Object[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* UnityString_Format_m98A0629641086A1BE20BBF7F4EADDE3FE3877D85 (String_t* ___0_fmt, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___1_args, const RuntimeMethod* method) ;
// System.String System.Single::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Single_ToString_mE282EDA9CA4F7DF88432D807732837A629D04972 (float* __this, const RuntimeMethod* method) ;
// System.Char System.String::get_Chars(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppChar String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3 (String_t* __this, int32_t ___0_index, const RuntimeMethod* method) ;
// System.Int32 System.String::get_Length()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.Color::.ctor(System.Single,System.Single,System.Single,System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Color__ctor_m3786F0D6E510D9CFA544523A955870BD2A514C8C_inline (Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* __this, float ___0_r, float ___1_g, float ___2_b, float ___3_a, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void UnityEngine.GUISkin::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin__ctor_mAA94A46B37D9C2F70962435F250BBA202CD1EC7A (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GUISettings_tF2CA7E8B9F62F1FC013BFF053B5FA2709EBA3847_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		GUISettings_tF2CA7E8B9F62F1FC013BFF053B5FA2709EBA3847* L_0 = (GUISettings_tF2CA7E8B9F62F1FC013BFF053B5FA2709EBA3847*)il2cpp_codegen_object_new(GUISettings_tF2CA7E8B9F62F1FC013BFF053B5FA2709EBA3847_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		GUISettings__ctor_m4AA9AFBD94306E007937909CB7F542DF2E491404(L_0, NULL);
		__this->___m_Settings_29 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Settings_29), (void*)L_0);
		__this->___m_Styles_31 = (Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Styles_31), (void*)(Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F*)NULL);
		ScriptableObject__ctor_mD037FDB0B487295EA47F79A4DB1BF1846C9087FF(__this, NULL);
		GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC* L_1 = (GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC*)(GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC*)SZArrayNew(GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC_il2cpp_TypeInfo_var, (uint32_t)1);
		__this->___m_CustomStyles_28 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_CustomStyles_28), (void*)L_1);
		return;
	}
}
// System.Void UnityEngine.GUISkin::OnEnable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_OnEnable_m5A7FE1F57C549711FCCC2DB0322F8667129AA0BF (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	{
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// System.Void UnityEngine.GUISkin::CleanupRoots()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_CleanupRoots_mAD2E77BE9440832E8BC8CAA9C7F2D85C3D2F8B17 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		((GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_StaticFields*)il2cpp_codegen_static_fields_for(GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_il2cpp_TypeInfo_var))->___current_33 = (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&((GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_StaticFields*)il2cpp_codegen_static_fields_for(GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_il2cpp_TypeInfo_var))->___current_33), (void*)(GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9*)NULL);
		((GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_StaticFields*)il2cpp_codegen_static_fields_for(GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_il2cpp_TypeInfo_var))->___ms_Error_30 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&((GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_StaticFields*)il2cpp_codegen_static_fields_for(GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_il2cpp_TypeInfo_var))->___ms_Error_30), (void*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)NULL);
		return;
	}
}
// UnityEngine.Font UnityEngine.GUISkin::get_font()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Font_tC95270EA3198038970422D78B74A7F2E218A96B6* GUISkin_get_font_m806CF702C59E43DF55BA441030A60F80E9D8CFD5 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	Font_tC95270EA3198038970422D78B74A7F2E218A96B6* V_0 = NULL;
	{
		Font_tC95270EA3198038970422D78B74A7F2E218A96B6* L_0 = __this->___m_Font_4;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		Font_tC95270EA3198038970422D78B74A7F2E218A96B6* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_font(UnityEngine.Font)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_font_mF98516DE4363C888D7215006D51BD527F3F9DDA9 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, Font_tC95270EA3198038970422D78B74A7F2E218A96B6* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	{
		Font_tC95270EA3198038970422D78B74A7F2E218A96B6* L_0 = ___0_value;
		__this->___m_Font_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Font_4), (void*)L_0);
		GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* L_1 = ((GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_StaticFields*)il2cpp_codegen_static_fields_for(GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_il2cpp_TypeInfo_var))->___current_33;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_1, __this, NULL);
		V_0 = L_2;
		bool L_3 = V_0;
		if (!L_3)
		{
			goto IL_0023;
		}
	}
	{
		Font_tC95270EA3198038970422D78B74A7F2E218A96B6* L_4 = __this->___m_Font_4;
		il2cpp_codegen_runtime_class_init_inline(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		GUIStyle_SetDefaultFont_mD6B98375749805CA5084CA8C5D6A1295359AE0E3(L_4, NULL);
	}

IL_0023:
	{
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_box()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_box_m21BE7FC56D903B95BAFAE8890425D330EA88D893 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_box_5;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_box(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_box_m82E578044569D3831D103FFA1413D81DABF74711 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_box_5 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_box_5), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_label()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_label_m99E1A8D6D8592F88F581437D24DB1EDE05C63E5E (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_label_8;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_label(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_label_m7E9E63BBA37F93D886F7E6AF70772ECD7894462B (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_label_8 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_label_8), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_textField()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_textField_mC554496BAB959445F0CFA30BDC5736DC1F057D48 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_textField_9;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_textField(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_textField_m4730F5B544F2A87AF3CA75A01FE845E5D40E06BE (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_textField_9 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_textField_9), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_textArea()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_textArea_m0ECBC9D126D930490F96E100B27F245E555EB7D1 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_textArea_10;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_textArea(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_textArea_m916CC2135EE608D81035D3E96787735534DF4E9D (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_textArea_10 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_textArea_10), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_button()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_button_m51948EBD478CF9223522AD29B7FBD1BABAABE289 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_button_6;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_button(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_button_m45F7F5CBF3E9286F4CD601AA92C0C3207C0BB373 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_button_6 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_button_6), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_toggle()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_toggle_mD5F318C602494C478F09C2D48741EC7A9CF5B849 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_toggle_7;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_toggle(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_toggle_mFE0DA0EC1F1952464B85894CCCFECFA5E0E0C57E (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_toggle_7 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_toggle_7), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_window()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_window_m760DAF129E72775DFD18CB71720AD306345E91C2 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_window_11;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_window(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_window_mA74900E5D554578F3F45DD858B79C5A8FA4A6220 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_window_11 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_window_11), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_horizontalSlider()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_horizontalSlider_mAA1753FEEDBA6E28A3A56C3E44A8F5B3D6C8336B (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_horizontalSlider_12;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_horizontalSlider(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_horizontalSlider_m8357A90F358C1A040308C8D0DEE363D3ABA71575 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_horizontalSlider_12 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_horizontalSlider_12), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_horizontalSliderThumb()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_horizontalSliderThumb_m9EE5EF8204397C2946D7F384AB7D8A17693837BD (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_horizontalSliderThumb_13;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_horizontalSliderThumb(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_horizontalSliderThumb_m1042BED23F10E28042D77D7E738F86C1FEDF460E (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_horizontalSliderThumb_13 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_horizontalSliderThumb_13), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_horizontalSliderThumbExtent()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_horizontalSliderThumbExtent_m6408F303B8932D6E74B307070689A96EA082D612 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_horizontalSliderThumbExtent_14;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_horizontalSliderThumbExtent(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_horizontalSliderThumbExtent_m8F4C637DB7E25697AB463B9F2F8D50D8493609C1 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_horizontalSliderThumbExtent_14 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_horizontalSliderThumbExtent_14), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_sliderMixed()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_sliderMixed_mFD8CBA8BE229E299D63822AE3E632DABCC27FF61 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_SliderMixed_18;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_sliderMixed(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_sliderMixed_m8A129FB05FAA0970C01A8C3DB14903E13F8E37B3 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_SliderMixed_18 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_SliderMixed_18), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_verticalSlider()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_verticalSlider_mB7EC86D11019F1892365E9C6F2A846A68879BBD5 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_verticalSlider_15;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_verticalSlider(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_verticalSlider_m02D94C0BFF867BD8B1ECE05AB50F7F2475DF0E35 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_verticalSlider_15 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_verticalSlider_15), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_verticalSliderThumb()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_verticalSliderThumb_m3D86347FFC94841C8B6CA94F9F946C76E96EBADB (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_verticalSliderThumb_16;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_verticalSliderThumb(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_verticalSliderThumb_mFBFA636B05068A0E7D24C8C3B06044AB2ACD4C58 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_verticalSliderThumb_16 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_verticalSliderThumb_16), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_verticalSliderThumbExtent()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_verticalSliderThumbExtent_m299DED8D10A1CE0F22B43BAF47D70DA1EB079AFA (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_verticalSliderThumbExtent_17;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_verticalSliderThumbExtent(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_verticalSliderThumbExtent_m3ECC754FC08BCFA5C3264A6B83C9EE280C1EFCDD (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_verticalSliderThumbExtent_17 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_verticalSliderThumbExtent_17), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_horizontalScrollbar()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_horizontalScrollbar_m945A39FBD098D3800A189FC34B9CE9E8AFF3AEEA (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_horizontalScrollbar_19;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_horizontalScrollbar(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_horizontalScrollbar_mF08764A78F23728E6FE157F08B9A0127157071FA (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_horizontalScrollbar_19 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_horizontalScrollbar_19), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_horizontalScrollbarThumb()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_horizontalScrollbarThumb_m5011EED1650028044BCC7F6DE2829AC0243208BB (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_horizontalScrollbarThumb_20;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_horizontalScrollbarThumb(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_horizontalScrollbarThumb_mDDADEFFD5BF9B88AC4A37AEA13B6FCCC28A3F696 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_horizontalScrollbarThumb_20 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_horizontalScrollbarThumb_20), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_horizontalScrollbarLeftButton()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_horizontalScrollbarLeftButton_m4A6E58CF80A66F58CF5792B31D08A2D74BF40567 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_horizontalScrollbarLeftButton_21;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_horizontalScrollbarLeftButton(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_horizontalScrollbarLeftButton_m3FDB02C1FDE47BCE92068EA21C531F1F6D667DBC (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_horizontalScrollbarLeftButton_21 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_horizontalScrollbarLeftButton_21), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_horizontalScrollbarRightButton()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_horizontalScrollbarRightButton_mADFCABC3339BE56E2BAD5443789D8D4FBDD73DAC (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_horizontalScrollbarRightButton_22;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_horizontalScrollbarRightButton(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_horizontalScrollbarRightButton_mE5ED9D2BB554FC29F6A69C81B9361A5E6E004CFD (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_horizontalScrollbarRightButton_22 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_horizontalScrollbarRightButton_22), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_verticalScrollbar()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_verticalScrollbar_m600012E344D3EB4C687E8A4BE78CE33068374D2A (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_verticalScrollbar_23;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_verticalScrollbar(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_verticalScrollbar_m4F55D5B66DB408A5009FC00ABBB9AFFA0C65FFEC (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_verticalScrollbar_23 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_verticalScrollbar_23), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_verticalScrollbarThumb()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_verticalScrollbarThumb_m62663C3DDC40AC91FD4666FBF844DCD83DDA7DE6 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_verticalScrollbarThumb_24;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_verticalScrollbarThumb(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_verticalScrollbarThumb_mECEC0DC79CCD9AABBF6CBA3CE5141C38699B5EC6 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_verticalScrollbarThumb_24 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_verticalScrollbarThumb_24), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_verticalScrollbarUpButton()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_verticalScrollbarUpButton_m0B5575CA6AFB1C74899BF931296EFC39B2C1A902 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_verticalScrollbarUpButton_25;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_verticalScrollbarUpButton(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_verticalScrollbarUpButton_mF50F99BC770529789363EC9B1C37E610FF8A708C (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_verticalScrollbarUpButton_25 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_verticalScrollbarUpButton_25), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_verticalScrollbarDownButton()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_verticalScrollbarDownButton_mFC75161EDB03597ECF09E189C8A57F0E64213E3D (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_verticalScrollbarDownButton_26;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_verticalScrollbarDownButton(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_verticalScrollbarDownButton_m37DD0E232BB98BD219494A297DDBE7620104D328 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_verticalScrollbarDownButton_26 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_verticalScrollbarDownButton_26), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_scrollView()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_scrollView_m5466CD77A4A7E01320DB0E0F57253D41226BB0B8 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_ScrollView_27;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_scrollView(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_scrollView_mF2D35906BC020D81F909E65B420494F254E4DC32 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_ScrollView_27 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_ScrollView_27), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUIStyle[] UnityEngine.GUISkin::get_customStyles()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC* GUISkin_get_customStyles_mAC8A1CFD5756E6C0D367E06B4BDC365E6F6BC39B (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC* V_0 = NULL;
	{
		GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC* L_0 = __this->___m_CustomStyles_28;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUISkin::set_customStyles(UnityEngine.GUIStyle[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_set_customStyles_mD22F50472DDB0A9770B18F0A15D3F73EEEC4A8B2 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC* L_0 = ___0_value;
		__this->___m_CustomStyles_28 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_CustomStyles_28), (void*)L_0);
		GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104(__this, NULL);
		return;
	}
}
// UnityEngine.GUISettings UnityEngine.GUISkin::get_settings()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUISettings_tF2CA7E8B9F62F1FC013BFF053B5FA2709EBA3847* GUISkin_get_settings_mCBAE5727D7774FAEE47CCC8B4C47AC321DDD85C2 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	GUISettings_tF2CA7E8B9F62F1FC013BFF053B5FA2709EBA3847* V_0 = NULL;
	{
		GUISettings_tF2CA7E8B9F62F1FC013BFF053B5FA2709EBA3847* L_0 = __this->___m_Settings_29;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUISettings_tF2CA7E8B9F62F1FC013BFF053B5FA2709EBA3847* L_1 = V_0;
		return L_1;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::get_error()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_get_error_mB953A37C8F3296E529190A34E18506C735848C01 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral5FCA7CBE61ADC605F9F35C467CFE5D765D935400);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_1 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ((GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_StaticFields*)il2cpp_codegen_static_fields_for(GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_il2cpp_TypeInfo_var))->___ms_Error_30;
		V_0 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_0) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0029;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_2 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_2, NULL);
		((GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_StaticFields*)il2cpp_codegen_static_fields_for(GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_il2cpp_TypeInfo_var))->___ms_Error_30 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&((GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_StaticFields*)il2cpp_codegen_static_fields_for(GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_il2cpp_TypeInfo_var))->___ms_Error_30), (void*)L_2);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_3 = ((GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_StaticFields*)il2cpp_codegen_static_fields_for(GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_il2cpp_TypeInfo_var))->___ms_Error_30;
		NullCheck(L_3);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_3, _stringLiteral5FCA7CBE61ADC605F9F35C467CFE5D765D935400, NULL);
	}

IL_0029:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_4 = ((GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_StaticFields*)il2cpp_codegen_static_fields_for(GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_il2cpp_TypeInfo_var))->___ms_Error_30;
		V_1 = L_4;
		goto IL_0031;
	}

IL_0031:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_5 = V_1;
		return L_5;
	}
}
// System.Void UnityEngine.GUISkin::Apply()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_Apply_mA85017BE8C994F6220112EE8D00D3C37C1FF2104 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral74DA73DF8411070FEB987DE79D4529EE39FB3D96);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	{
		GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC* L_0 = __this->___m_CustomStyles_28;
		V_0 = (bool)((((RuntimeObject*)(GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC*)L_0) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0019;
		}
	}
	{
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_Log_m87A9A3C761FF5C43ED8A53B16190A53D08F818BB(_stringLiteral74DA73DF8411070FEB987DE79D4529EE39FB3D96, NULL);
	}

IL_0019:
	{
		GUISkin_BuildStyleCache_m8E99CC278C76A6DA63A24BFD2DE42AE313C0F7E1(__this, NULL);
		return;
	}
}
// System.Void UnityEngine.GUISkin::BuildStyleCache()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_BuildStyleCache_m8E99CC278C76A6DA63A24BFD2DE42AE313C0F7E1 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_TryGetValue_m0F9A65F9363E92E29717C15EEEA8A71A2DB8D402_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_m39AE7A2B779870855E3AC853F234C40F6735ACF9_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringComparer_t6268F19CA34879176651429C0D8A3D0002BB8E06_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral05CF9CF5853B675491570E9D20951E373F208902);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2ACA29C4E59869B5D453E2775263A84E06EDA03D);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral3A5D56B26B1A9CEDE88C8DBEC1D7FF8296992654);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral3A8647DA913120027BE0BCA389585AB5B1E2C75D);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral3C4F52AE03EA8FEF5DEAA4BF1DCF2792C970C821);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral514D6E12CA97253D25F742A6EB2CC9B8B2EE8149);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral622B9A1A51AC02C383A8F43FC542A76D2C0AF6A2);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral6866F44FE25F48E7BF04C35DA2F4C670D2021A33);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral760865C55F22E06913EE529E43E0A4EC6D4C2957);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral780401B090EAF1BCE81DDE534AEE885AE001D0DB);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7D88FE441DA1C11DA793F92B7B7665BEED176766);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral8174CA9CD84F86539853890382CF5C587FB8B9BE);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral86037F1A053094FF729BA5C5CACF4EDF8B6B38A3);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral8635E0BF76851ADF21ED9AAEC3F8566DAE26898E);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral8E59446B468A9A7AC0FBE64297CB598A1D6DD96C);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral9844A7472D6104C0F2F6D65CB10A10F7C0C637C0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral9F15982CC17EE718C2AFB3B1C125ACC1A65D2362);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralA7BF1F00A512D96C33F2BBA9B709990FB1899ECF);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralA8B948094C8FA05C32A4A7D097D73A3418E2EEA1);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB31A5E45A7336CF4E926743AF852C59783F5D947);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC8AFE89D158D2722B833D3EB38ECF175C82B1722);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCB34F9B2DD59C1BD2C15FA5E7192661406CCDF4C);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCC53E2F11D267A4FEC8C78116C6E1E0AC0021CA5);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCEA0ED0066879A12EF7428466404FD5A318EEDDA);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF3D711BA856837A5D3C34CA2103E03C173D6F4C7);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	bool V_2 = false;
	bool V_3 = false;
	bool V_4 = false;
	bool V_5 = false;
	bool V_6 = false;
	bool V_7 = false;
	bool V_8 = false;
	bool V_9 = false;
	bool V_10 = false;
	bool V_11 = false;
	bool V_12 = false;
	bool V_13 = false;
	bool V_14 = false;
	bool V_15 = false;
	bool V_16 = false;
	bool V_17 = false;
	bool V_18 = false;
	bool V_19 = false;
	bool V_20 = false;
	int32_t V_21 = 0;
	bool V_22 = false;
	bool V_23 = false;
	bool V_24 = false;
	bool V_25 = false;
	bool V_26 = false;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_box_5;
		V_0 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_0) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0019;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_2 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_2, NULL);
		__this->___m_box_5 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_box_5), (void*)L_2);
	}

IL_0019:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_3 = __this->___m_button_6;
		V_1 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_3) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_4 = V_1;
		if (!L_4)
		{
			goto IL_0031;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_5 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_5);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_5, NULL);
		__this->___m_button_6 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_button_6), (void*)L_5);
	}

IL_0031:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_6 = __this->___m_toggle_7;
		V_2 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_6) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_7 = V_2;
		if (!L_7)
		{
			goto IL_0049;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_8 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_8);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_8, NULL);
		__this->___m_toggle_7 = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_toggle_7), (void*)L_8);
	}

IL_0049:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_9 = __this->___m_label_8;
		V_3 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_9) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_10 = V_3;
		if (!L_10)
		{
			goto IL_0061;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_11 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_11);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_11, NULL);
		__this->___m_label_8 = L_11;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_label_8), (void*)L_11);
	}

IL_0061:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_12 = __this->___m_window_11;
		V_4 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_12) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_13 = V_4;
		if (!L_13)
		{
			goto IL_007b;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_14 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_14);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_14, NULL);
		__this->___m_window_11 = L_14;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_window_11), (void*)L_14);
	}

IL_007b:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_15 = __this->___m_textField_9;
		V_5 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_15) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_16 = V_5;
		if (!L_16)
		{
			goto IL_0095;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_17 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_17);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_17, NULL);
		__this->___m_textField_9 = L_17;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_textField_9), (void*)L_17);
	}

IL_0095:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_18 = __this->___m_textArea_10;
		V_6 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_18) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_19 = V_6;
		if (!L_19)
		{
			goto IL_00af;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_20 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_20);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_20, NULL);
		__this->___m_textArea_10 = L_20;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_textArea_10), (void*)L_20);
	}

IL_00af:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_21 = __this->___m_horizontalSlider_12;
		V_7 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_21) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_22 = V_7;
		if (!L_22)
		{
			goto IL_00c9;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_23 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_23);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_23, NULL);
		__this->___m_horizontalSlider_12 = L_23;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_horizontalSlider_12), (void*)L_23);
	}

IL_00c9:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_24 = __this->___m_horizontalSliderThumb_13;
		V_8 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_24) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_25 = V_8;
		if (!L_25)
		{
			goto IL_00e3;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_26 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_26);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_26, NULL);
		__this->___m_horizontalSliderThumb_13 = L_26;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_horizontalSliderThumb_13), (void*)L_26);
	}

IL_00e3:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_27 = __this->___m_verticalSlider_15;
		V_9 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_27) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_28 = V_9;
		if (!L_28)
		{
			goto IL_00fd;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_29 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_29);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_29, NULL);
		__this->___m_verticalSlider_15 = L_29;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_verticalSlider_15), (void*)L_29);
	}

IL_00fd:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_30 = __this->___m_verticalSliderThumb_16;
		V_10 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_30) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_31 = V_10;
		if (!L_31)
		{
			goto IL_0117;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_32 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_32);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_32, NULL);
		__this->___m_verticalSliderThumb_16 = L_32;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_verticalSliderThumb_16), (void*)L_32);
	}

IL_0117:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_33 = __this->___m_horizontalScrollbar_19;
		V_11 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_33) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_34 = V_11;
		if (!L_34)
		{
			goto IL_0131;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_35 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_35);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_35, NULL);
		__this->___m_horizontalScrollbar_19 = L_35;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_horizontalScrollbar_19), (void*)L_35);
	}

IL_0131:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_36 = __this->___m_horizontalScrollbarThumb_20;
		V_12 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_36) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_37 = V_12;
		if (!L_37)
		{
			goto IL_014b;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_38 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_38);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_38, NULL);
		__this->___m_horizontalScrollbarThumb_20 = L_38;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_horizontalScrollbarThumb_20), (void*)L_38);
	}

IL_014b:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_39 = __this->___m_horizontalScrollbarLeftButton_21;
		V_13 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_39) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_40 = V_13;
		if (!L_40)
		{
			goto IL_0165;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_41 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_41);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_41, NULL);
		__this->___m_horizontalScrollbarLeftButton_21 = L_41;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_horizontalScrollbarLeftButton_21), (void*)L_41);
	}

IL_0165:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_42 = __this->___m_horizontalScrollbarRightButton_22;
		V_14 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_42) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_43 = V_14;
		if (!L_43)
		{
			goto IL_017f;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_44 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_44);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_44, NULL);
		__this->___m_horizontalScrollbarRightButton_22 = L_44;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_horizontalScrollbarRightButton_22), (void*)L_44);
	}

IL_017f:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_45 = __this->___m_verticalScrollbar_23;
		V_15 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_45) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_46 = V_15;
		if (!L_46)
		{
			goto IL_0199;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_47 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_47);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_47, NULL);
		__this->___m_verticalScrollbar_23 = L_47;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_verticalScrollbar_23), (void*)L_47);
	}

IL_0199:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_48 = __this->___m_verticalScrollbarThumb_24;
		V_16 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_48) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_49 = V_16;
		if (!L_49)
		{
			goto IL_01b3;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_50 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_50);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_50, NULL);
		__this->___m_verticalScrollbarThumb_24 = L_50;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_verticalScrollbarThumb_24), (void*)L_50);
	}

IL_01b3:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_51 = __this->___m_verticalScrollbarUpButton_25;
		V_17 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_51) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_52 = V_17;
		if (!L_52)
		{
			goto IL_01cd;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_53 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_53);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_53, NULL);
		__this->___m_verticalScrollbarUpButton_25 = L_53;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_verticalScrollbarUpButton_25), (void*)L_53);
	}

IL_01cd:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_54 = __this->___m_verticalScrollbarDownButton_26;
		V_18 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_54) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_55 = V_18;
		if (!L_55)
		{
			goto IL_01e7;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_56 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_56);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_56, NULL);
		__this->___m_verticalScrollbarDownButton_26 = L_56;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_verticalScrollbarDownButton_26), (void*)L_56);
	}

IL_01e7:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_57 = __this->___m_ScrollView_27;
		V_19 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_57) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_58 = V_19;
		if (!L_58)
		{
			goto IL_0201;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_59 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_59);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_59, NULL);
		__this->___m_ScrollView_27 = L_59;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_ScrollView_27), (void*)L_59);
	}

IL_0201:
	{
		il2cpp_codegen_runtime_class_init_inline(StringComparer_t6268F19CA34879176651429C0D8A3D0002BB8E06_il2cpp_TypeInfo_var);
		StringComparer_t6268F19CA34879176651429C0D8A3D0002BB8E06* L_60;
		L_60 = StringComparer_get_OrdinalIgnoreCase_m071AA1B1747345CCA058A3879EBDEBBA2EA4B169_inline(NULL);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_61 = (Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F*)il2cpp_codegen_object_new(Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F_il2cpp_TypeInfo_var);
		NullCheck(L_61);
		Dictionary_2__ctor_m39AE7A2B779870855E3AC853F234C40F6735ACF9(L_61, L_60, Dictionary_2__ctor_m39AE7A2B779870855E3AC853F234C40F6735ACF9_RuntimeMethod_var);
		__this->___m_Styles_31 = L_61;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Styles_31), (void*)L_61);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_62 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_63 = __this->___m_box_5;
		NullCheck(L_62);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_62, _stringLiteral3C4F52AE03EA8FEF5DEAA4BF1DCF2792C970C821, L_63, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_64 = __this->___m_box_5;
		NullCheck(L_64);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_64, _stringLiteral3C4F52AE03EA8FEF5DEAA4BF1DCF2792C970C821, NULL);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_65 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_66 = __this->___m_button_6;
		NullCheck(L_65);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_65, _stringLiteral3A5D56B26B1A9CEDE88C8DBEC1D7FF8296992654, L_66, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_67 = __this->___m_button_6;
		NullCheck(L_67);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_67, _stringLiteral3A5D56B26B1A9CEDE88C8DBEC1D7FF8296992654, NULL);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_68 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_69 = __this->___m_toggle_7;
		NullCheck(L_68);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_68, _stringLiteral760865C55F22E06913EE529E43E0A4EC6D4C2957, L_69, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_70 = __this->___m_toggle_7;
		NullCheck(L_70);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_70, _stringLiteral760865C55F22E06913EE529E43E0A4EC6D4C2957, NULL);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_71 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_72 = __this->___m_label_8;
		NullCheck(L_71);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_71, _stringLiteral8174CA9CD84F86539853890382CF5C587FB8B9BE, L_72, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_73 = __this->___m_label_8;
		NullCheck(L_73);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_73, _stringLiteral8174CA9CD84F86539853890382CF5C587FB8B9BE, NULL);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_74 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_75 = __this->___m_window_11;
		NullCheck(L_74);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_74, _stringLiteralCEA0ED0066879A12EF7428466404FD5A318EEDDA, L_75, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_76 = __this->___m_window_11;
		NullCheck(L_76);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_76, _stringLiteralCEA0ED0066879A12EF7428466404FD5A318EEDDA, NULL);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_77 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_78 = __this->___m_textField_9;
		NullCheck(L_77);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_77, _stringLiteral05CF9CF5853B675491570E9D20951E373F208902, L_78, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_79 = __this->___m_textField_9;
		NullCheck(L_79);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_79, _stringLiteral05CF9CF5853B675491570E9D20951E373F208902, NULL);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_80 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_81 = __this->___m_textArea_10;
		NullCheck(L_80);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_80, _stringLiteral8E59446B468A9A7AC0FBE64297CB598A1D6DD96C, L_81, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_82 = __this->___m_textArea_10;
		NullCheck(L_82);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_82, _stringLiteral8E59446B468A9A7AC0FBE64297CB598A1D6DD96C, NULL);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_83 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_84 = __this->___m_horizontalSlider_12;
		NullCheck(L_83);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_83, _stringLiteralA7BF1F00A512D96C33F2BBA9B709990FB1899ECF, L_84, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_85 = __this->___m_horizontalSlider_12;
		NullCheck(L_85);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_85, _stringLiteralA7BF1F00A512D96C33F2BBA9B709990FB1899ECF, NULL);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_86 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_87 = __this->___m_horizontalSliderThumb_13;
		NullCheck(L_86);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_86, _stringLiteralA8B948094C8FA05C32A4A7D097D73A3418E2EEA1, L_87, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_88 = __this->___m_horizontalSliderThumb_13;
		NullCheck(L_88);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_88, _stringLiteralA8B948094C8FA05C32A4A7D097D73A3418E2EEA1, NULL);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_89 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_90 = __this->___m_verticalSlider_15;
		NullCheck(L_89);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_89, _stringLiteral514D6E12CA97253D25F742A6EB2CC9B8B2EE8149, L_90, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_91 = __this->___m_verticalSlider_15;
		NullCheck(L_91);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_91, _stringLiteral514D6E12CA97253D25F742A6EB2CC9B8B2EE8149, NULL);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_92 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_93 = __this->___m_verticalSliderThumb_16;
		NullCheck(L_92);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_92, _stringLiteralCC53E2F11D267A4FEC8C78116C6E1E0AC0021CA5, L_93, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_94 = __this->___m_verticalSliderThumb_16;
		NullCheck(L_94);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_94, _stringLiteralCC53E2F11D267A4FEC8C78116C6E1E0AC0021CA5, NULL);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_95 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_96 = __this->___m_horizontalScrollbar_19;
		NullCheck(L_95);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_95, _stringLiteral780401B090EAF1BCE81DDE534AEE885AE001D0DB, L_96, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_97 = __this->___m_horizontalScrollbar_19;
		NullCheck(L_97);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_97, _stringLiteral780401B090EAF1BCE81DDE534AEE885AE001D0DB, NULL);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_98 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_99 = __this->___m_horizontalScrollbarThumb_20;
		NullCheck(L_98);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_98, _stringLiteral7D88FE441DA1C11DA793F92B7B7665BEED176766, L_99, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_100 = __this->___m_horizontalScrollbarThumb_20;
		NullCheck(L_100);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_100, _stringLiteral7D88FE441DA1C11DA793F92B7B7665BEED176766, NULL);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_101 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_102 = __this->___m_horizontalScrollbarLeftButton_21;
		NullCheck(L_101);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_101, _stringLiteral2ACA29C4E59869B5D453E2775263A84E06EDA03D, L_102, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_103 = __this->___m_horizontalScrollbarLeftButton_21;
		NullCheck(L_103);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_103, _stringLiteral2ACA29C4E59869B5D453E2775263A84E06EDA03D, NULL);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_104 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_105 = __this->___m_horizontalScrollbarRightButton_22;
		NullCheck(L_104);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_104, _stringLiteralC8AFE89D158D2722B833D3EB38ECF175C82B1722, L_105, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_106 = __this->___m_horizontalScrollbarRightButton_22;
		NullCheck(L_106);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_106, _stringLiteralC8AFE89D158D2722B833D3EB38ECF175C82B1722, NULL);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_107 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_108 = __this->___m_verticalScrollbar_23;
		NullCheck(L_107);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_107, _stringLiteralF3D711BA856837A5D3C34CA2103E03C173D6F4C7, L_108, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_109 = __this->___m_verticalScrollbar_23;
		NullCheck(L_109);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_109, _stringLiteralF3D711BA856837A5D3C34CA2103E03C173D6F4C7, NULL);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_110 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_111 = __this->___m_verticalScrollbarThumb_24;
		NullCheck(L_110);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_110, _stringLiteral86037F1A053094FF729BA5C5CACF4EDF8B6B38A3, L_111, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_112 = __this->___m_verticalScrollbarThumb_24;
		NullCheck(L_112);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_112, _stringLiteral86037F1A053094FF729BA5C5CACF4EDF8B6B38A3, NULL);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_113 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_114 = __this->___m_verticalScrollbarUpButton_25;
		NullCheck(L_113);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_113, _stringLiteral8635E0BF76851ADF21ED9AAEC3F8566DAE26898E, L_114, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_115 = __this->___m_verticalScrollbarUpButton_25;
		NullCheck(L_115);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_115, _stringLiteral8635E0BF76851ADF21ED9AAEC3F8566DAE26898E, NULL);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_116 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_117 = __this->___m_verticalScrollbarDownButton_26;
		NullCheck(L_116);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_116, _stringLiteral3A8647DA913120027BE0BCA389585AB5B1E2C75D, L_117, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_118 = __this->___m_verticalScrollbarDownButton_26;
		NullCheck(L_118);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_118, _stringLiteral3A8647DA913120027BE0BCA389585AB5B1E2C75D, NULL);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_119 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_120 = __this->___m_ScrollView_27;
		NullCheck(L_119);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_119, _stringLiteral9844A7472D6104C0F2F6D65CB10A10F7C0C637C0, L_120, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_121 = __this->___m_ScrollView_27;
		NullCheck(L_121);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_121, _stringLiteral9844A7472D6104C0F2F6D65CB10A10F7C0C637C0, NULL);
		GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC* L_122 = __this->___m_CustomStyles_28;
		V_20 = (bool)((!(((RuntimeObject*)(GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC*)L_122) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		bool L_123 = V_20;
		if (!L_123)
		{
			goto IL_0598;
		}
	}
	{
		V_21 = 0;
		goto IL_0585;
	}

IL_0546:
	{
		GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC* L_124 = __this->___m_CustomStyles_28;
		int32_t L_125 = V_21;
		NullCheck(L_124);
		int32_t L_126 = L_125;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_127 = (L_124)->GetAt(static_cast<il2cpp_array_size_t>(L_126));
		V_22 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_127) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_128 = V_22;
		if (!L_128)
		{
			goto IL_055b;
		}
	}
	{
		goto IL_057f;
	}

IL_055b:
	{
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_129 = __this->___m_Styles_31;
		GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC* L_130 = __this->___m_CustomStyles_28;
		int32_t L_131 = V_21;
		NullCheck(L_130);
		int32_t L_132 = L_131;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_133 = (L_130)->GetAt(static_cast<il2cpp_array_size_t>(L_132));
		NullCheck(L_133);
		String_t* L_134;
		L_134 = GUIStyle_get_name_mDF9EF43C46A0B9431DAF4EB0CE1D18EA32E16B75(L_133, NULL);
		GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC* L_135 = __this->___m_CustomStyles_28;
		int32_t L_136 = V_21;
		NullCheck(L_135);
		int32_t L_137 = L_136;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_138 = (L_135)->GetAt(static_cast<il2cpp_array_size_t>(L_137));
		NullCheck(L_129);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_129, L_134, L_138, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
	}

IL_057f:
	{
		int32_t L_139 = V_21;
		V_21 = ((int32_t)il2cpp_codegen_add(L_139, 1));
	}

IL_0585:
	{
		int32_t L_140 = V_21;
		GUIStyleU5BU5D_t1BA4BCF4D4D32DF07E9B84F1750D964DF33B0FEC* L_141 = __this->___m_CustomStyles_28;
		NullCheck(L_141);
		V_23 = (bool)((((int32_t)L_140) < ((int32_t)((int32_t)(((RuntimeArray*)L_141)->max_length))))? 1 : 0);
		bool L_142 = V_23;
		if (L_142)
		{
			goto IL_0546;
		}
	}
	{
	}

IL_0598:
	{
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_143 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580** L_144 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580**)(&__this->___m_horizontalSliderThumbExtent_14);
		NullCheck(L_143);
		bool L_145;
		L_145 = Dictionary_2_TryGetValue_m0F9A65F9363E92E29717C15EEEA8A71A2DB8D402(L_143, _stringLiteralCB34F9B2DD59C1BD2C15FA5E7192661406CCDF4C, L_144, Dictionary_2_TryGetValue_m0F9A65F9363E92E29717C15EEEA8A71A2DB8D402_RuntimeMethod_var);
		V_24 = (bool)((((int32_t)L_145) == ((int32_t)0))? 1 : 0);
		bool L_146 = V_24;
		if (!L_146)
		{
			goto IL_05ec;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_147 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_147);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_147, NULL);
		__this->___m_horizontalSliderThumbExtent_14 = L_147;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_horizontalSliderThumbExtent_14), (void*)L_147);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_148 = __this->___m_horizontalSliderThumbExtent_14;
		NullCheck(L_148);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_148, _stringLiteral6866F44FE25F48E7BF04C35DA2F4C670D2021A33, NULL);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_149 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_150 = __this->___m_horizontalSliderThumbExtent_14;
		NullCheck(L_149);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_149, _stringLiteralCB34F9B2DD59C1BD2C15FA5E7192661406CCDF4C, L_150, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
	}

IL_05ec:
	{
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_151 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580** L_152 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580**)(&__this->___m_SliderMixed_18);
		NullCheck(L_151);
		bool L_153;
		L_153 = Dictionary_2_TryGetValue_m0F9A65F9363E92E29717C15EEEA8A71A2DB8D402(L_151, _stringLiteral9F15982CC17EE718C2AFB3B1C125ACC1A65D2362, L_152, Dictionary_2_TryGetValue_m0F9A65F9363E92E29717C15EEEA8A71A2DB8D402_RuntimeMethod_var);
		V_25 = (bool)((((int32_t)L_153) == ((int32_t)0))? 1 : 0);
		bool L_154 = V_25;
		if (!L_154)
		{
			goto IL_0640;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_155 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_155);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_155, NULL);
		__this->___m_SliderMixed_18 = L_155;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_SliderMixed_18), (void*)L_155);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_156 = __this->___m_SliderMixed_18;
		NullCheck(L_156);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_156, _stringLiteral9F15982CC17EE718C2AFB3B1C125ACC1A65D2362, NULL);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_157 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_158 = __this->___m_SliderMixed_18;
		NullCheck(L_157);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_157, _stringLiteral9F15982CC17EE718C2AFB3B1C125ACC1A65D2362, L_158, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
	}

IL_0640:
	{
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_159 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580** L_160 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580**)(&__this->___m_verticalSliderThumbExtent_17);
		NullCheck(L_159);
		bool L_161;
		L_161 = Dictionary_2_TryGetValue_m0F9A65F9363E92E29717C15EEEA8A71A2DB8D402(L_159, _stringLiteral622B9A1A51AC02C383A8F43FC542A76D2C0AF6A2, L_160, Dictionary_2_TryGetValue_m0F9A65F9363E92E29717C15EEEA8A71A2DB8D402_RuntimeMethod_var);
		V_26 = (bool)((((int32_t)L_161) == ((int32_t)0))? 1 : 0);
		bool L_162 = V_26;
		if (!L_162)
		{
			goto IL_0694;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_163 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)il2cpp_codegen_object_new(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		NullCheck(L_163);
		GUIStyle__ctor_mE15E33802C5A2EA787E445A6D424813E1D5B75A9(L_163, NULL);
		__this->___m_verticalSliderThumbExtent_17 = L_163;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_verticalSliderThumbExtent_17), (void*)L_163);
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_164 = __this->___m_Styles_31;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_165 = __this->___m_verticalSliderThumbExtent_17;
		NullCheck(L_164);
		Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0(L_164, _stringLiteral622B9A1A51AC02C383A8F43FC542A76D2C0AF6A2, L_165, Dictionary_2_set_Item_m7AAEE4C854832ED7DD6A5222330DD59F71BA04A0_RuntimeMethod_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_166 = __this->___m_verticalSliderThumbExtent_17;
		NullCheck(L_166);
		GUIStyle_set_name_mE618266DC07236117AAE05FE8D2B14A595FCF020(L_166, _stringLiteralB31A5E45A7336CF4E926743AF852C59783F5D947, NULL);
	}

IL_0694:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_167;
		L_167 = GUISkin_get_error_mB953A37C8F3296E529190A34E18506C735848C01(NULL);
		NullCheck(L_167);
		GUIStyle_set_stretchHeight_m51C55ED43AA4EDE125E0C423FA0D301E81C09378(L_167, (bool)1, NULL);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_168;
		L_168 = GUISkin_get_error_mB953A37C8F3296E529190A34E18506C735848C01(NULL);
		NullCheck(L_168);
		GUIStyleState_t7A948723D9DCDFD8EE4F418B6EC909C18E023F95* L_169;
		L_169 = GUIStyle_get_normal_mDEA2808FBD692E505784BD9E521738B4321BCA8F(L_168, NULL);
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_170;
		L_170 = Color_get_red_mA2E53E7173FDC97E68E335049AB0FAAEE43A844D_inline(NULL);
		NullCheck(L_169);
		GUIStyleState_set_textColor_m5868D12858E6402247953BCCDDA7A543BE6084F1(L_169, L_170, NULL);
		return;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::GetStyle(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_GetStyle_mF024BC5177A2AD477ACF44D87BE6A629C91562CA (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, String_t* ___0_styleName, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EventType_tC62F0D77DB08D7326B58B2D8CF43BD45CFD3203E_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral123B2E5CFC7B5F49F61A9A7E042BC077972AB7EA);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral5934735AA968E0CB7CB39062B758A93F76F5591C);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral85E4DD1872CA9889B201BF423506257FB4DB467C);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral9B9EF66DAA3B5CC54EF182295D9A9980A1C9B23D);
		s_Il2CppMethodInitialized = true;
	}
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	bool V_1 = false;
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_2 = NULL;
	int32_t V_3 = 0;
	int32_t G_B4_0 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B4_1 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B4_2 = NULL;
	int32_t G_B3_0 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B3_1 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B3_2 = NULL;
	String_t* G_B5_0 = NULL;
	int32_t G_B5_1 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B5_2 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B5_3 = NULL;
	{
		String_t* L_0 = ___0_styleName;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1;
		L_1 = GUISkin_FindStyle_mF82C37E2481D2B9E96C26EFE0353F8954F844FFE(__this, L_0, NULL);
		V_0 = L_1;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_2 = V_0;
		V_1 = (bool)((!(((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_2) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_0015;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_4 = V_0;
		V_2 = L_4;
		goto IL_007c;
	}

IL_0015:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_5 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)6);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_6 = L_5;
		NullCheck(L_6);
		ArrayElementTypeCheck (L_6, _stringLiteral9B9EF66DAA3B5CC54EF182295D9A9980A1C9B23D);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteral9B9EF66DAA3B5CC54EF182295D9A9980A1C9B23D);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_7 = L_6;
		String_t* L_8 = ___0_styleName;
		NullCheck(L_7);
		ArrayElementTypeCheck (L_7, L_8);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(1), (String_t*)L_8);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_9 = L_7;
		NullCheck(L_9);
		ArrayElementTypeCheck (L_9, _stringLiteral5934735AA968E0CB7CB39062B758A93F76F5591C);
		(L_9)->SetAt(static_cast<il2cpp_array_size_t>(2), (String_t*)_stringLiteral5934735AA968E0CB7CB39062B758A93F76F5591C);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_10 = L_9;
		String_t* L_11;
		L_11 = Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392(__this, NULL);
		NullCheck(L_10);
		ArrayElementTypeCheck (L_10, L_11);
		(L_10)->SetAt(static_cast<il2cpp_array_size_t>(3), (String_t*)L_11);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_12 = L_10;
		NullCheck(L_12);
		ArrayElementTypeCheck (L_12, _stringLiteral85E4DD1872CA9889B201BF423506257FB4DB467C);
		(L_12)->SetAt(static_cast<il2cpp_array_size_t>(4), (String_t*)_stringLiteral85E4DD1872CA9889B201BF423506257FB4DB467C);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_13 = L_12;
		Event_tEBC6F24B56CE22B9C9AD1AC6C24A6B83BC3860CB* L_14;
		L_14 = Event_get_current_mBD7135E10C392EAD61AC0A0D2489EF758C8A3FAD(NULL);
		G_B3_0 = 5;
		G_B3_1 = L_13;
		G_B3_2 = L_13;
		if (L_14)
		{
			G_B4_0 = 5;
			G_B4_1 = L_13;
			G_B4_2 = L_13;
			goto IL_0050;
		}
	}
	{
		G_B5_0 = _stringLiteral123B2E5CFC7B5F49F61A9A7E042BC077972AB7EA;
		G_B5_1 = G_B3_0;
		G_B5_2 = G_B3_1;
		G_B5_3 = G_B3_2;
		goto IL_0068;
	}

IL_0050:
	{
		Event_tEBC6F24B56CE22B9C9AD1AC6C24A6B83BC3860CB* L_15;
		L_15 = Event_get_current_mBD7135E10C392EAD61AC0A0D2489EF758C8A3FAD(NULL);
		NullCheck(L_15);
		int32_t L_16;
		L_16 = Event_get_type_m8A825D6DA432B967DAA3E22E5C8571620A75F8A8(L_15, NULL);
		V_3 = L_16;
		Il2CppFakeBox<int32_t> L_17(EventType_tC62F0D77DB08D7326B58B2D8CF43BD45CFD3203E_il2cpp_TypeInfo_var, (&V_3));
		String_t* L_18;
		L_18 = Enum_ToString_m946B0B83C4470457D0FF555D862022C72BB55741((Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2*)(&L_17), NULL);
		G_B5_0 = L_18;
		G_B5_1 = G_B4_0;
		G_B5_2 = G_B4_1;
		G_B5_3 = G_B4_2;
	}

IL_0068:
	{
		NullCheck(G_B5_2);
		ArrayElementTypeCheck (G_B5_2, G_B5_0);
		(G_B5_2)->SetAt(static_cast<il2cpp_array_size_t>(G_B5_1), (String_t*)G_B5_0);
		String_t* L_19;
		L_19 = String_Concat_m647EBF831F54B6DF7D5AFA5FD012CF4EE7571B6A(G_B5_3, NULL);
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogWarning_m33EF1B897E0C7C6FF538989610BFAFFEF4628CA9(L_19, NULL);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_20;
		L_20 = GUISkin_get_error_mB953A37C8F3296E529190A34E18506C735848C01(NULL);
		V_2 = L_20;
		goto IL_007c;
	}

IL_007c:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_21 = V_2;
		return L_21;
	}
}
// UnityEngine.GUIStyle UnityEngine.GUISkin::FindStyle(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUISkin_FindStyle_mF82C37E2481D2B9E96C26EFE0353F8954F844FFE (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, String_t* ___0_styleName, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_TryGetValue_m0F9A65F9363E92E29717C15EEEA8A71A2DB8D402_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	bool V_1 = false;
	bool V_2 = false;
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_3 = NULL;
	{
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_0 = __this->___m_Styles_31;
		V_1 = (bool)((((RuntimeObject*)(Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F*)L_0) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_1 = V_1;
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		GUISkin_BuildStyleCache_m8E99CC278C76A6DA63A24BFD2DE42AE313C0F7E1(__this, NULL);
	}

IL_0015:
	{
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_2 = __this->___m_Styles_31;
		String_t* L_3 = ___0_styleName;
		NullCheck(L_2);
		bool L_4;
		L_4 = Dictionary_2_TryGetValue_m0F9A65F9363E92E29717C15EEEA8A71A2DB8D402(L_2, L_3, (&V_0), Dictionary_2_TryGetValue_m0F9A65F9363E92E29717C15EEEA8A71A2DB8D402_RuntimeMethod_var);
		V_2 = L_4;
		bool L_5 = V_2;
		if (!L_5)
		{
			goto IL_002b;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_6 = V_0;
		V_3 = L_6;
		goto IL_002f;
	}

IL_002b:
	{
		V_3 = (GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)NULL;
		goto IL_002f;
	}

IL_002f:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_7 = V_3;
		return L_7;
	}
}
// System.Void UnityEngine.GUISkin::MakeCurrent()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUISkin_MakeCurrent_mDB3BB1FBA5BD2FEDDA3F32F11170F47A6444AEED (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	{
		((GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_StaticFields*)il2cpp_codegen_static_fields_for(GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_il2cpp_TypeInfo_var))->___current_33 = __this;
		Il2CppCodeGenWriteBarrier((void**)(&((GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_StaticFields*)il2cpp_codegen_static_fields_for(GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_il2cpp_TypeInfo_var))->___current_33), (void*)__this);
		Font_tC95270EA3198038970422D78B74A7F2E218A96B6* L_0;
		L_0 = GUISkin_get_font_m806CF702C59E43DF55BA441030A60F80E9D8CFD5(__this, NULL);
		il2cpp_codegen_runtime_class_init_inline(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		GUIStyle_SetDefaultFont_mD6B98375749805CA5084CA8C5D6A1295359AE0E3(L_0, NULL);
		SkinChangedDelegate_tA6D456E853D58AD2EF8A599F543C7E5BA8E94B98* L_1 = ((GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_StaticFields*)il2cpp_codegen_static_fields_for(GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_il2cpp_TypeInfo_var))->___m_SkinChanged_32;
		V_0 = (bool)((!(((RuntimeObject*)(SkinChangedDelegate_tA6D456E853D58AD2EF8A599F543C7E5BA8E94B98*)L_1) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		bool L_2 = V_0;
		if (!L_2)
		{
			goto IL_002a;
		}
	}
	{
		SkinChangedDelegate_tA6D456E853D58AD2EF8A599F543C7E5BA8E94B98* L_3 = ((GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_StaticFields*)il2cpp_codegen_static_fields_for(GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9_il2cpp_TypeInfo_var))->___m_SkinChanged_32;
		NullCheck(L_3);
		SkinChangedDelegate_Invoke_mD14214487F9A0E4DD7EB7F97927D03EC8F1A3B4C_inline(L_3, NULL);
	}

IL_002a:
	{
		return;
	}
}
// System.Collections.IEnumerator UnityEngine.GUISkin::GetEnumerator()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* GUISkin_GetEnumerator_mEC308E2DA9A94E09C622D13F82EB7ECCECF8AFF0 (GUISkin_t8C65CE1424D4B5D8D73022E266BDAD3BDE8612D9* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_get_Values_m923D794849584E9B0675E86D09B54BA6691944D2_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_t6FCF94B18593967BB1EA62E38DDD1FA537144AA9_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ValueCollection_GetEnumerator_m88DC4BD4D4952C7D4B15BE9CC164DF1EAA69A197_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	RuntimeObject* V_1 = NULL;
	{
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_0 = __this->___m_Styles_31;
		V_0 = (bool)((((RuntimeObject*)(Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F*)L_0) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		GUISkin_BuildStyleCache_m8E99CC278C76A6DA63A24BFD2DE42AE313C0F7E1(__this, NULL);
	}

IL_0015:
	{
		Dictionary_2_tEFC8016EC28460E6CE058A5F413FAB656883AA5F* L_2 = __this->___m_Styles_31;
		NullCheck(L_2);
		ValueCollection_t6CD4B9552B29D570FBA4E0145D0C98841ECCC8C1* L_3;
		L_3 = Dictionary_2_get_Values_m923D794849584E9B0675E86D09B54BA6691944D2(L_2, Dictionary_2_get_Values_m923D794849584E9B0675E86D09B54BA6691944D2_RuntimeMethod_var);
		NullCheck(L_3);
		Enumerator_t6FCF94B18593967BB1EA62E38DDD1FA537144AA9 L_4;
		L_4 = ValueCollection_GetEnumerator_m88DC4BD4D4952C7D4B15BE9CC164DF1EAA69A197(L_3, ValueCollection_GetEnumerator_m88DC4BD4D4952C7D4B15BE9CC164DF1EAA69A197_RuntimeMethod_var);
		Enumerator_t6FCF94B18593967BB1EA62E38DDD1FA537144AA9 L_5 = L_4;
		RuntimeObject* L_6 = Box(Enumerator_t6FCF94B18593967BB1EA62E38DDD1FA537144AA9_il2cpp_TypeInfo_var, &L_5);
		V_1 = (RuntimeObject*)L_6;
		goto IL_002d;
	}

IL_002d:
	{
		RuntimeObject* L_7 = V_1;
		return L_7;
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
void SkinChangedDelegate_Invoke_mD14214487F9A0E4DD7EB7F97927D03EC8F1A3B4C_Multicast(SkinChangedDelegate_tA6D456E853D58AD2EF8A599F543C7E5BA8E94B98* __this, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates_13->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates_13->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		SkinChangedDelegate_tA6D456E853D58AD2EF8A599F543C7E5BA8E94B98* currentDelegate = reinterpret_cast<SkinChangedDelegate_tA6D456E853D58AD2EF8A599F543C7E5BA8E94B98*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl_1)((Il2CppObject*)currentDelegate->___method_code_6, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method_3));
	}
}
void SkinChangedDelegate_Invoke_mD14214487F9A0E4DD7EB7F97927D03EC8F1A3B4C_OpenInst(SkinChangedDelegate_tA6D456E853D58AD2EF8A599F543C7E5BA8E94B98* __this, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(method);
}
void SkinChangedDelegate_Invoke_mD14214487F9A0E4DD7EB7F97927D03EC8F1A3B4C_OpenStatic(SkinChangedDelegate_tA6D456E853D58AD2EF8A599F543C7E5BA8E94B98* __this, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(method);
}
void SkinChangedDelegate_Invoke_mD14214487F9A0E4DD7EB7F97927D03EC8F1A3B4C_OpenStaticInvoker(SkinChangedDelegate_tA6D456E853D58AD2EF8A599F543C7E5BA8E94B98* __this, const RuntimeMethod* method)
{
	InvokerActionInvoker0::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL);
}
void SkinChangedDelegate_Invoke_mD14214487F9A0E4DD7EB7F97927D03EC8F1A3B4C_ClosedStaticInvoker(SkinChangedDelegate_tA6D456E853D58AD2EF8A599F543C7E5BA8E94B98* __this, const RuntimeMethod* method)
{
	InvokerActionInvoker1< RuntimeObject* >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, __this->___m_target_2);
}
IL2CPP_EXTERN_C  void DelegatePInvokeWrapper_SkinChangedDelegate_tA6D456E853D58AD2EF8A599F543C7E5BA8E94B98 (SkinChangedDelegate_tA6D456E853D58AD2EF8A599F543C7E5BA8E94B98* __this, const RuntimeMethod* method)
{
	typedef void (DEFAULT_CALL *PInvokeFunc)();
	PInvokeFunc il2cppPInvokeFunc = reinterpret_cast<PInvokeFunc>(il2cpp_codegen_get_reverse_pinvoke_function_ptr(__this));
	// Native function invocation
	il2cppPInvokeFunc();

}
// System.Void UnityEngine.GUISkin/SkinChangedDelegate::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SkinChangedDelegate__ctor_m20D33B3868351B98B708468F7A8192C1ACF85CD1 (SkinChangedDelegate_tA6D456E853D58AD2EF8A599F543C7E5BA8E94B98* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr_0 = (intptr_t)il2cpp_codegen_get_virtual_call_method_pointer((RuntimeMethod*)___1_method);
	__this->___method_3 = ___1_method;
	__this->___m_target_2 = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target_2), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code_6 = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 0;
		if (il2cpp_codegen_call_method_via_invoker((RuntimeMethod*)___1_method))
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&SkinChangedDelegate_Invoke_mD14214487F9A0E4DD7EB7F97927D03EC8F1A3B4C_OpenStaticInvoker;
			else
				__this->___invoke_impl_1 = (intptr_t)&SkinChangedDelegate_Invoke_mD14214487F9A0E4DD7EB7F97927D03EC8F1A3B4C_ClosedStaticInvoker;
		else
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&SkinChangedDelegate_Invoke_mD14214487F9A0E4DD7EB7F97927D03EC8F1A3B4C_OpenStatic;
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
	__this->___extra_arg_5 = (intptr_t)&SkinChangedDelegate_Invoke_mD14214487F9A0E4DD7EB7F97927D03EC8F1A3B4C_Multicast;
}
// System.Void UnityEngine.GUISkin/SkinChangedDelegate::Invoke()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SkinChangedDelegate_Invoke_mD14214487F9A0E4DD7EB7F97927D03EC8F1A3B4C (SkinChangedDelegate_tA6D456E853D58AD2EF8A599F543C7E5BA8E94B98* __this, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void UnityEngine.SliderState::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SliderState__ctor_m650A11534C71EF571FD631CC3E910B756A16889E (SliderState_t7BBFAEF918BAA1EE6116C3979993E4EC7DC54FC8* __this, const RuntimeMethod* method) 
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
// UnityEngine.GUIStyle UnityEngine.GUILayoutEntry::get_style()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* GUILayoutEntry_get_style_mEFB6A8443849EC32BD84059C09632B53E44A5876 (GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* __this, const RuntimeMethod* method) 
{
	GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* V_0 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = __this->___m_Style_8;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = V_0;
		return L_1;
	}
}
// System.Void UnityEngine.GUILayoutEntry::set_style(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUILayoutEntry_set_style_m0A23F7EFF504A581FC6CA86EF3BE753F060AC48A (GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_value, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_value;
		__this->___m_Style_8 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Style_8), (void*)L_0);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1 = ___0_value;
		VirtualActionInvoker1< GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* >::Invoke(12 /* System.Void UnityEngine.GUILayoutEntry::ApplyStyleSettings(UnityEngine.GUIStyle) */, __this, L_1);
		return;
	}
}
// System.Int32 UnityEngine.GUILayoutEntry::get_marginLeft()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t GUILayoutEntry_get_marginLeft_m3B362DA8241B4008C2A6CDA693295A609F765221 (GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* __this, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0;
		L_0 = GUILayoutEntry_get_style_mEFB6A8443849EC32BD84059C09632B53E44A5876(__this, NULL);
		NullCheck(L_0);
		RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5* L_1;
		L_1 = GUIStyle_get_margin_mD0AABA2CB3FB0CFC3C414635E6225D3003315D1B(L_0, NULL);
		NullCheck(L_1);
		int32_t L_2;
		L_2 = RectOffset_get_left_mA406D7AFF76E48507EF143CDB1D157C4D5430D90(L_1, NULL);
		return L_2;
	}
}
// System.Int32 UnityEngine.GUILayoutEntry::get_marginRight()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t GUILayoutEntry_get_marginRight_m032808DC8C04B31150407F3F61E71865C2636D7F (GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* __this, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0;
		L_0 = GUILayoutEntry_get_style_mEFB6A8443849EC32BD84059C09632B53E44A5876(__this, NULL);
		NullCheck(L_0);
		RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5* L_1;
		L_1 = GUIStyle_get_margin_mD0AABA2CB3FB0CFC3C414635E6225D3003315D1B(L_0, NULL);
		NullCheck(L_1);
		int32_t L_2;
		L_2 = RectOffset_get_right_m07C826B0BC79B0CBC01F5FF489D456C553F047BF(L_1, NULL);
		return L_2;
	}
}
// System.Int32 UnityEngine.GUILayoutEntry::get_marginTop()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t GUILayoutEntry_get_marginTop_m47BAB82D31A45E21F9AAB8229265788C0D19487C (GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* __this, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0;
		L_0 = GUILayoutEntry_get_style_mEFB6A8443849EC32BD84059C09632B53E44A5876(__this, NULL);
		NullCheck(L_0);
		RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5* L_1;
		L_1 = GUIStyle_get_margin_mD0AABA2CB3FB0CFC3C414635E6225D3003315D1B(L_0, NULL);
		NullCheck(L_1);
		int32_t L_2;
		L_2 = RectOffset_get_top_m82E49FB93A5BD417131136F5A7DBA0F251F10263(L_1, NULL);
		return L_2;
	}
}
// System.Int32 UnityEngine.GUILayoutEntry::get_marginBottom()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t GUILayoutEntry_get_marginBottom_m2BCCF0FC72E0230E155E7A26BA9FFD904AD4C221 (GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* __this, const RuntimeMethod* method) 
{
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0;
		L_0 = GUILayoutEntry_get_style_mEFB6A8443849EC32BD84059C09632B53E44A5876(__this, NULL);
		NullCheck(L_0);
		RectOffset_t6358774A0DEEABA4586840CB9BC7DC88B39660B5* L_1;
		L_1 = GUIStyle_get_margin_mD0AABA2CB3FB0CFC3C414635E6225D3003315D1B(L_0, NULL);
		NullCheck(L_1);
		int32_t L_2;
		L_2 = RectOffset_get_bottom_mDF9C1EC125F94245D5532C34FCFB65BE0F2A9D0B(L_1, NULL);
		return L_2;
	}
}
// System.Int32 UnityEngine.GUILayoutEntry::get_marginHorizontal()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t GUILayoutEntry_get_marginHorizontal_m9847FB7747542BB322195F9CF4B75F55339CD7B5 (GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = VirtualFuncInvoker0< int32_t >::Invoke(4 /* System.Int32 UnityEngine.GUILayoutEntry::get_marginLeft() */, __this);
		int32_t L_1;
		L_1 = VirtualFuncInvoker0< int32_t >::Invoke(5 /* System.Int32 UnityEngine.GUILayoutEntry::get_marginRight() */, __this);
		return ((int32_t)il2cpp_codegen_add(L_0, L_1));
	}
}
// System.Int32 UnityEngine.GUILayoutEntry::get_marginVertical()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t GUILayoutEntry_get_marginVertical_mCD309A186E80B22E75DD8F15D2598B9B739C7AD3 (GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = VirtualFuncInvoker0< int32_t >::Invoke(7 /* System.Int32 UnityEngine.GUILayoutEntry::get_marginBottom() */, __this);
		int32_t L_1;
		L_1 = VirtualFuncInvoker0< int32_t >::Invoke(6 /* System.Int32 UnityEngine.GUILayoutEntry::get_marginTop() */, __this);
		return ((int32_t)il2cpp_codegen_add(L_0, L_1));
	}
}
// System.Void UnityEngine.GUILayoutEntry::.ctor(System.Single,System.Single,System.Single,System.Single,UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUILayoutEntry__ctor_m011B3DA69713EEA6BD98D4056B5ADE01F237E5B2 (GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* __this, float ___0__minWidth, float ___1__maxWidth, float ___2__minHeight, float ___3__maxHeight, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___4__style, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	{
		Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D L_0;
		memset((&L_0), 0, sizeof(L_0));
		Rect__ctor_m18C3033D135097BEE424AAA68D91C706D2647F23((&L_0), (0.0f), (0.0f), (0.0f), (0.0f), /*hidden argument*/NULL);
		__this->___rect_4 = L_0;
		__this->___consideredForMargin_7 = (bool)1;
		il2cpp_codegen_runtime_class_init_inline(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_1;
		L_1 = GUIStyle_get_none_m808A9FE1F78920E4A29ED3484B99588B46D88938(NULL);
		__this->___m_Style_8 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Style_8), (void*)L_1);
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		float L_2 = ___0__minWidth;
		__this->___minWidth_0 = L_2;
		float L_3 = ___1__maxWidth;
		__this->___maxWidth_1 = L_3;
		float L_4 = ___2__minHeight;
		__this->___minHeight_2 = L_4;
		float L_5 = ___3__maxHeight;
		__this->___maxHeight_3 = L_5;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_6 = ___4__style;
		V_0 = (bool)((((RuntimeObject*)(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580*)L_6) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_7 = V_0;
		if (!L_7)
		{
			goto IL_0066;
		}
	}
	{
		il2cpp_codegen_runtime_class_init_inline(GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580_il2cpp_TypeInfo_var);
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_8;
		L_8 = GUIStyle_get_none_m808A9FE1F78920E4A29ED3484B99588B46D88938(NULL);
		___4__style = L_8;
	}

IL_0066:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_9 = ___4__style;
		GUILayoutEntry_set_style_m0A23F7EFF504A581FC6CA86EF3BE753F060AC48A(__this, L_9, NULL);
		return;
	}
}
// System.Void UnityEngine.GUILayoutEntry::CalcWidth()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUILayoutEntry_CalcWidth_m77BB8C0413A27303E4E61CB53586FD4A825C5EF3 (GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* __this, const RuntimeMethod* method) 
{
	{
		return;
	}
}
// System.Void UnityEngine.GUILayoutEntry::CalcHeight()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUILayoutEntry_CalcHeight_m295D607AB2FDD78D7C665BB3FB3A495E2E8CC0A6 (GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* __this, const RuntimeMethod* method) 
{
	{
		return;
	}
}
// System.Void UnityEngine.GUILayoutEntry::SetHorizontal(System.Single,System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUILayoutEntry_SetHorizontal_m268577E88A2AE5870C14EFDA9CB88C94CAC2ACE9 (GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* __this, float ___0_x, float ___1_width, const RuntimeMethod* method) 
{
	{
		Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* L_0 = (Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D*)(&__this->___rect_4);
		float L_1 = ___0_x;
		Rect_set_x_mAB91AB71898A20762BC66FD0723C4C739C4C3406(L_0, L_1, NULL);
		Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* L_2 = (Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D*)(&__this->___rect_4);
		float L_3 = ___1_width;
		Rect_set_width_m93B6217CF3EFF89F9B0C81F34D7345DE90B93E5A(L_2, L_3, NULL);
		return;
	}
}
// System.Void UnityEngine.GUILayoutEntry::SetVertical(System.Single,System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUILayoutEntry_SetVertical_mA20893626441C55001C1940C53A6A100DD22D61F (GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* __this, float ___0_y, float ___1_height, const RuntimeMethod* method) 
{
	{
		Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* L_0 = (Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D*)(&__this->___rect_4);
		float L_1 = ___0_y;
		Rect_set_y_mDE91F4B98A6E8623EFB1250FF6526D5DB5855629(L_0, L_1, NULL);
		Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* L_2 = (Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D*)(&__this->___rect_4);
		float L_3 = ___1_height;
		Rect_set_height_mD00038E6E06637137A5626CA8CD421924005BF03(L_2, L_3, NULL);
		return;
	}
}
// System.Void UnityEngine.GUILayoutEntry::ApplyStyleSettings(UnityEngine.GUIStyle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUILayoutEntry_ApplyStyleSettings_m2D3679DAF547D104FE48E7D6D8E27B639F6A666B (GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* __this, GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* ___0_style, const RuntimeMethod* method) 
{
	GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* G_B2_0 = NULL;
	GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* G_B1_0 = NULL;
	GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* G_B3_0 = NULL;
	int32_t G_B4_0 = 0;
	GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* G_B4_1 = NULL;
	GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* G_B6_0 = NULL;
	GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* G_B5_0 = NULL;
	GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* G_B7_0 = NULL;
	int32_t G_B8_0 = 0;
	GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* G_B8_1 = NULL;
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_0 = ___0_style;
		NullCheck(L_0);
		float L_1;
		L_1 = GUIStyle_get_fixedWidth_m9CB5B4E096287F75F4E4E3376590C7C085E28DE8(L_0, NULL);
		G_B1_0 = __this;
		if ((!(((float)L_1) == ((float)(0.0f)))))
		{
			G_B2_0 = __this;
			goto IL_0017;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_2 = ___0_style;
		NullCheck(L_2);
		bool L_3;
		L_3 = GUIStyle_get_stretchWidth_m528FFD3EB3104D0322F2EADBBE7DBFF3FB34CB37(L_2, NULL);
		G_B2_0 = G_B1_0;
		if (L_3)
		{
			G_B3_0 = G_B1_0;
			goto IL_001a;
		}
	}

IL_0017:
	{
		G_B4_0 = 0;
		G_B4_1 = G_B2_0;
		goto IL_001b;
	}

IL_001a:
	{
		G_B4_0 = 1;
		G_B4_1 = G_B3_0;
	}

IL_001b:
	{
		NullCheck(G_B4_1);
		G_B4_1->___stretchWidth_5 = G_B4_0;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_4 = ___0_style;
		NullCheck(L_4);
		float L_5;
		L_5 = GUIStyle_get_fixedHeight_m009155CF284509A87E6037D0A392A630FA728F7A(L_4, NULL);
		G_B5_0 = __this;
		if ((!(((float)L_5) == ((float)(0.0f)))))
		{
			G_B6_0 = __this;
			goto IL_0036;
		}
	}
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_6 = ___0_style;
		NullCheck(L_6);
		bool L_7;
		L_7 = GUIStyle_get_stretchHeight_m5ACA8F9CD25746932719C927159A105AADA5061F(L_6, NULL);
		G_B6_0 = G_B5_0;
		if (L_7)
		{
			G_B7_0 = G_B5_0;
			goto IL_0039;
		}
	}

IL_0036:
	{
		G_B8_0 = 0;
		G_B8_1 = G_B6_0;
		goto IL_003a;
	}

IL_0039:
	{
		G_B8_0 = 1;
		G_B8_1 = G_B7_0;
	}

IL_003a:
	{
		NullCheck(G_B8_1);
		G_B8_1->___stretchHeight_6 = G_B8_0;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_8 = ___0_style;
		__this->___m_Style_8 = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Style_8), (void*)L_8);
		return;
	}
}
// System.Void UnityEngine.GUILayoutEntry::ApplyOptions(UnityEngine.GUILayoutOption[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUILayoutEntry_ApplyOptions_mF024E6CEAAD97888AE293810E01F8431D79456A3 (GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* __this, GUILayoutOptionU5BU5D_t24AB80AB9355D784F2C65E12A4D0CC2E0C914CA2* ___0_options, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	GUILayoutOptionU5BU5D_t24AB80AB9355D784F2C65E12A4D0CC2E0C914CA2* V_1 = NULL;
	int32_t V_2 = 0;
	GUILayoutOption_t8B0AA056521747053A3176FCC43E9C3608940A14* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	float V_6 = 0.0f;
	bool V_7 = false;
	bool V_8 = false;
	bool V_9 = false;
	bool V_10 = false;
	bool V_11 = false;
	bool V_12 = false;
	int32_t G_B26_0 = 0;
	int32_t G_B31_0 = 0;
	{
		GUILayoutOptionU5BU5D_t24AB80AB9355D784F2C65E12A4D0CC2E0C914CA2* L_0 = ___0_options;
		V_0 = (bool)((((RuntimeObject*)(GUILayoutOptionU5BU5D_t24AB80AB9355D784F2C65E12A4D0CC2E0C914CA2*)L_0) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_000e;
		}
	}
	{
		goto IL_0219;
	}

IL_000e:
	{
		GUILayoutOptionU5BU5D_t24AB80AB9355D784F2C65E12A4D0CC2E0C914CA2* L_2 = ___0_options;
		V_1 = L_2;
		V_2 = 0;
		goto IL_01b0;
	}

IL_0018:
	{
		GUILayoutOptionU5BU5D_t24AB80AB9355D784F2C65E12A4D0CC2E0C914CA2* L_3 = V_1;
		int32_t L_4 = V_2;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		GUILayoutOption_t8B0AA056521747053A3176FCC43E9C3608940A14* L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		V_3 = L_6;
		GUILayoutOption_t8B0AA056521747053A3176FCC43E9C3608940A14* L_7 = V_3;
		NullCheck(L_7);
		int32_t L_8 = L_7->___type_0;
		V_5 = L_8;
		int32_t L_9 = V_5;
		V_4 = L_9;
		int32_t L_10 = V_4;
		switch (L_10)
		{
			case 0:
			{
				goto IL_0055;
			}
			case 1:
			{
				goto IL_007d;
			}
			case 2:
			{
				goto IL_00a5;
			}
			case 3:
			{
				goto IL_00db;
			}
			case 4:
			{
				goto IL_0118;
			}
			case 5:
			{
				goto IL_014b;
			}
			case 6:
			{
				goto IL_0185;
			}
			case 7:
			{
				goto IL_0198;
			}
		}
	}
	{
		goto IL_01ab;
	}

IL_0055:
	{
		GUILayoutOption_t8B0AA056521747053A3176FCC43E9C3608940A14* L_11 = V_3;
		NullCheck(L_11);
		RuntimeObject* L_12 = L_11->___value_1;
		float L_13 = ((*(float*)((float*)(float*)UnBox(L_12, Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var))));
		V_6 = L_13;
		__this->___maxWidth_1 = L_13;
		float L_14 = V_6;
		__this->___minWidth_0 = L_14;
		__this->___stretchWidth_5 = 0;
		goto IL_01ab;
	}

IL_007d:
	{
		GUILayoutOption_t8B0AA056521747053A3176FCC43E9C3608940A14* L_15 = V_3;
		NullCheck(L_15);
		RuntimeObject* L_16 = L_15->___value_1;
		float L_17 = ((*(float*)((float*)(float*)UnBox(L_16, Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var))));
		V_6 = L_17;
		__this->___maxHeight_3 = L_17;
		float L_18 = V_6;
		__this->___minHeight_2 = L_18;
		__this->___stretchHeight_6 = 0;
		goto IL_01ab;
	}

IL_00a5:
	{
		GUILayoutOption_t8B0AA056521747053A3176FCC43E9C3608940A14* L_19 = V_3;
		NullCheck(L_19);
		RuntimeObject* L_20 = L_19->___value_1;
		__this->___minWidth_0 = ((*(float*)((float*)(float*)UnBox(L_20, Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var))));
		float L_21 = __this->___maxWidth_1;
		float L_22 = __this->___minWidth_0;
		V_7 = (bool)((((float)L_21) < ((float)L_22))? 1 : 0);
		bool L_23 = V_7;
		if (!L_23)
		{
			goto IL_00d6;
		}
	}
	{
		float L_24 = __this->___minWidth_0;
		__this->___maxWidth_1 = L_24;
	}

IL_00d6:
	{
		goto IL_01ab;
	}

IL_00db:
	{
		GUILayoutOption_t8B0AA056521747053A3176FCC43E9C3608940A14* L_25 = V_3;
		NullCheck(L_25);
		RuntimeObject* L_26 = L_25->___value_1;
		__this->___maxWidth_1 = ((*(float*)((float*)(float*)UnBox(L_26, Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var))));
		float L_27 = __this->___minWidth_0;
		float L_28 = __this->___maxWidth_1;
		V_8 = (bool)((((float)L_27) > ((float)L_28))? 1 : 0);
		bool L_29 = V_8;
		if (!L_29)
		{
			goto IL_010c;
		}
	}
	{
		float L_30 = __this->___maxWidth_1;
		__this->___minWidth_0 = L_30;
	}

IL_010c:
	{
		__this->___stretchWidth_5 = 0;
		goto IL_01ab;
	}

IL_0118:
	{
		GUILayoutOption_t8B0AA056521747053A3176FCC43E9C3608940A14* L_31 = V_3;
		NullCheck(L_31);
		RuntimeObject* L_32 = L_31->___value_1;
		__this->___minHeight_2 = ((*(float*)((float*)(float*)UnBox(L_32, Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var))));
		float L_33 = __this->___maxHeight_3;
		float L_34 = __this->___minHeight_2;
		V_9 = (bool)((((float)L_33) < ((float)L_34))? 1 : 0);
		bool L_35 = V_9;
		if (!L_35)
		{
			goto IL_0149;
		}
	}
	{
		float L_36 = __this->___minHeight_2;
		__this->___maxHeight_3 = L_36;
	}

IL_0149:
	{
		goto IL_01ab;
	}

IL_014b:
	{
		GUILayoutOption_t8B0AA056521747053A3176FCC43E9C3608940A14* L_37 = V_3;
		NullCheck(L_37);
		RuntimeObject* L_38 = L_37->___value_1;
		__this->___maxHeight_3 = ((*(float*)((float*)(float*)UnBox(L_38, Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var))));
		float L_39 = __this->___minHeight_2;
		float L_40 = __this->___maxHeight_3;
		V_10 = (bool)((((float)L_39) > ((float)L_40))? 1 : 0);
		bool L_41 = V_10;
		if (!L_41)
		{
			goto IL_017c;
		}
	}
	{
		float L_42 = __this->___maxHeight_3;
		__this->___minHeight_2 = L_42;
	}

IL_017c:
	{
		__this->___stretchHeight_6 = 0;
		goto IL_01ab;
	}

IL_0185:
	{
		GUILayoutOption_t8B0AA056521747053A3176FCC43E9C3608940A14* L_43 = V_3;
		NullCheck(L_43);
		RuntimeObject* L_44 = L_43->___value_1;
		__this->___stretchWidth_5 = ((*(int32_t*)((int32_t*)(int32_t*)UnBox(L_44, Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var))));
		goto IL_01ab;
	}

IL_0198:
	{
		GUILayoutOption_t8B0AA056521747053A3176FCC43E9C3608940A14* L_45 = V_3;
		NullCheck(L_45);
		RuntimeObject* L_46 = L_45->___value_1;
		__this->___stretchHeight_6 = ((*(int32_t*)((int32_t*)(int32_t*)UnBox(L_46, Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var))));
		goto IL_01ab;
	}

IL_01ab:
	{
		int32_t L_47 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_47, 1));
	}

IL_01b0:
	{
		int32_t L_48 = V_2;
		GUILayoutOptionU5BU5D_t24AB80AB9355D784F2C65E12A4D0CC2E0C914CA2* L_49 = V_1;
		NullCheck(L_49);
		if ((((int32_t)L_48) < ((int32_t)((int32_t)(((RuntimeArray*)L_49)->max_length)))))
		{
			goto IL_0018;
		}
	}
	{
		float L_50 = __this->___maxWidth_1;
		if ((((float)L_50) == ((float)(0.0f))))
		{
			goto IL_01d6;
		}
	}
	{
		float L_51 = __this->___maxWidth_1;
		float L_52 = __this->___minWidth_0;
		G_B26_0 = ((((float)L_51) < ((float)L_52))? 1 : 0);
		goto IL_01d7;
	}

IL_01d6:
	{
		G_B26_0 = 0;
	}

IL_01d7:
	{
		V_11 = (bool)G_B26_0;
		bool L_53 = V_11;
		if (!L_53)
		{
			goto IL_01e9;
		}
	}
	{
		float L_54 = __this->___minWidth_0;
		__this->___maxWidth_1 = L_54;
	}

IL_01e9:
	{
		float L_55 = __this->___maxHeight_3;
		if ((((float)L_55) == ((float)(0.0f))))
		{
			goto IL_0206;
		}
	}
	{
		float L_56 = __this->___maxHeight_3;
		float L_57 = __this->___minHeight_2;
		G_B31_0 = ((((float)L_56) < ((float)L_57))? 1 : 0);
		goto IL_0207;
	}

IL_0206:
	{
		G_B31_0 = 0;
	}

IL_0207:
	{
		V_12 = (bool)G_B31_0;
		bool L_58 = V_12;
		if (!L_58)
		{
			goto IL_0219;
		}
	}
	{
		float L_59 = __this->___minHeight_2;
		__this->___maxHeight_3 = L_59;
	}

IL_0219:
	{
		return;
	}
}
// System.String UnityEngine.GUILayoutEntry::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* GUILayoutEntry_ToString_mD3785AC5958EB56ECA6E5D325D166C5F5725E615 (GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0484F5252B12C569CD2F3AEE4FCFD5DBE3C5967F);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0993C31116DED8F2DAA78B6A73E3149497A84400);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral20E39C3AB7068FAFD9E4B868E16D2E5BC64D4952);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2386E77CF610F786B06A91AF2C1B3FD2282D2745);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral80F799C8D4F8B264EFFA6ADAB5F6D1169403E1C4);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral900D858FE9ABCD2ED2B25CD27110A78ADCC6EC6B);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	int32_t V_1 = 0;
	bool V_2 = false;
	String_t* V_3 = NULL;
	int32_t G_B5_0 = 0;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* G_B5_1 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* G_B5_2 = NULL;
	String_t* G_B5_3 = NULL;
	int32_t G_B5_4 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B5_5 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B5_6 = NULL;
	int32_t G_B4_0 = 0;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* G_B4_1 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* G_B4_2 = NULL;
	String_t* G_B4_3 = NULL;
	int32_t G_B4_4 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B4_5 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B4_6 = NULL;
	String_t* G_B6_0 = NULL;
	int32_t G_B6_1 = 0;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* G_B6_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* G_B6_3 = NULL;
	String_t* G_B6_4 = NULL;
	int32_t G_B6_5 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B6_6 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B6_7 = NULL;
	int32_t G_B8_0 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B8_1 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B8_2 = NULL;
	int32_t G_B7_0 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B7_1 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B7_2 = NULL;
	String_t* G_B9_0 = NULL;
	int32_t G_B9_1 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B9_2 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B9_3 = NULL;
	int32_t G_B11_0 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B11_1 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B11_2 = NULL;
	int32_t G_B10_0 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B10_1 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B10_2 = NULL;
	String_t* G_B12_0 = NULL;
	int32_t G_B12_1 = 0;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B12_2 = NULL;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* G_B12_3 = NULL;
	{
		V_0 = _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709;
		V_1 = 0;
		goto IL_001b;
	}

IL_000b:
	{
		String_t* L_0 = V_0;
		String_t* L_1;
		L_1 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(L_0, _stringLiteral2386E77CF610F786B06A91AF2C1B3FD2282D2745, NULL);
		V_0 = L_1;
		int32_t L_2 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_2, 1));
	}

IL_001b:
	{
		int32_t L_3 = V_1;
		il2cpp_codegen_runtime_class_init_inline(GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F_il2cpp_TypeInfo_var);
		int32_t L_4 = ((GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F_StaticFields*)il2cpp_codegen_static_fields_for(GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F_il2cpp_TypeInfo_var))->___indent_10;
		V_2 = (bool)((((int32_t)L_3) < ((int32_t)L_4))? 1 : 0);
		bool L_5 = V_2;
		if (L_5)
		{
			goto IL_000b;
		}
	}
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_6 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)((int32_t)12));
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_7 = L_6;
		String_t* L_8 = V_0;
		NullCheck(L_7);
		ArrayElementTypeCheck (L_7, L_8);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(0), (String_t*)L_8);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_9 = L_7;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_10 = (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)(ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)SZArrayNew(ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var, (uint32_t)6);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_11 = L_10;
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_12;
		L_12 = GUILayoutEntry_get_style_mEFB6A8443849EC32BD84059C09632B53E44A5876(__this, NULL);
		G_B4_0 = 0;
		G_B4_1 = L_11;
		G_B4_2 = L_11;
		G_B4_3 = _stringLiteral80F799C8D4F8B264EFFA6ADAB5F6D1169403E1C4;
		G_B4_4 = 1;
		G_B4_5 = L_9;
		G_B4_6 = L_9;
		if (L_12)
		{
			G_B5_0 = 0;
			G_B5_1 = L_11;
			G_B5_2 = L_11;
			G_B5_3 = _stringLiteral80F799C8D4F8B264EFFA6ADAB5F6D1169403E1C4;
			G_B5_4 = 1;
			G_B5_5 = L_9;
			G_B5_6 = L_9;
			goto IL_0050;
		}
	}
	{
		G_B6_0 = _stringLiteral900D858FE9ABCD2ED2B25CD27110A78ADCC6EC6B;
		G_B6_1 = G_B4_0;
		G_B6_2 = G_B4_1;
		G_B6_3 = G_B4_2;
		G_B6_4 = G_B4_3;
		G_B6_5 = G_B4_4;
		G_B6_6 = G_B4_5;
		G_B6_7 = G_B4_6;
		goto IL_005b;
	}

IL_0050:
	{
		GUIStyle_t20BA2F9F3FE9D13AAA607EEEBE5547835A6F6580* L_13;
		L_13 = GUILayoutEntry_get_style_mEFB6A8443849EC32BD84059C09632B53E44A5876(__this, NULL);
		NullCheck(L_13);
		String_t* L_14;
		L_14 = GUIStyle_get_name_mDF9EF43C46A0B9431DAF4EB0CE1D18EA32E16B75(L_13, NULL);
		G_B6_0 = L_14;
		G_B6_1 = G_B5_0;
		G_B6_2 = G_B5_1;
		G_B6_3 = G_B5_2;
		G_B6_4 = G_B5_3;
		G_B6_5 = G_B5_4;
		G_B6_6 = G_B5_5;
		G_B6_7 = G_B5_6;
	}

IL_005b:
	{
		NullCheck(G_B6_2);
		ArrayElementTypeCheck (G_B6_2, G_B6_0);
		(G_B6_2)->SetAt(static_cast<il2cpp_array_size_t>(G_B6_1), (RuntimeObject*)G_B6_0);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_15 = G_B6_3;
		Type_t* L_16;
		L_16 = Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3(__this, NULL);
		NullCheck(L_15);
		ArrayElementTypeCheck (L_15, L_16);
		(L_15)->SetAt(static_cast<il2cpp_array_size_t>(1), (RuntimeObject*)L_16);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_17 = L_15;
		Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* L_18 = (Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D*)(&__this->___rect_4);
		float L_19;
		L_19 = Rect_get_x_mB267B718E0D067F2BAE31BA477647FBF964916EB(L_18, NULL);
		float L_20 = L_19;
		RuntimeObject* L_21 = Box(Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var, &L_20);
		NullCheck(L_17);
		ArrayElementTypeCheck (L_17, L_21);
		(L_17)->SetAt(static_cast<il2cpp_array_size_t>(2), (RuntimeObject*)L_21);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_22 = L_17;
		Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* L_23 = (Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D*)(&__this->___rect_4);
		float L_24;
		L_24 = Rect_get_xMax_m2339C7D2FCDA98A9B007F815F6E2059BA6BE425F(L_23, NULL);
		float L_25 = L_24;
		RuntimeObject* L_26 = Box(Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var, &L_25);
		NullCheck(L_22);
		ArrayElementTypeCheck (L_22, L_26);
		(L_22)->SetAt(static_cast<il2cpp_array_size_t>(3), (RuntimeObject*)L_26);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_27 = L_22;
		Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* L_28 = (Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D*)(&__this->___rect_4);
		float L_29;
		L_29 = Rect_get_y_mC733E8D49F3CE21B2A3D40A1B72D687F22C97F49(L_28, NULL);
		float L_30 = L_29;
		RuntimeObject* L_31 = Box(Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var, &L_30);
		NullCheck(L_27);
		ArrayElementTypeCheck (L_27, L_31);
		(L_27)->SetAt(static_cast<il2cpp_array_size_t>(4), (RuntimeObject*)L_31);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_32 = L_27;
		Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* L_33 = (Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D*)(&__this->___rect_4);
		float L_34;
		L_34 = Rect_get_yMax_mBC37BEE1CD632AADD8B9EAF9FE3BA143F79CAF8E(L_33, NULL);
		float L_35 = L_34;
		RuntimeObject* L_36 = Box(Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var, &L_35);
		NullCheck(L_32);
		ArrayElementTypeCheck (L_32, L_36);
		(L_32)->SetAt(static_cast<il2cpp_array_size_t>(5), (RuntimeObject*)L_36);
		String_t* L_37;
		L_37 = UnityString_Format_m98A0629641086A1BE20BBF7F4EADDE3FE3877D85(G_B6_4, L_32, NULL);
		NullCheck(G_B6_6);
		ArrayElementTypeCheck (G_B6_6, L_37);
		(G_B6_6)->SetAt(static_cast<il2cpp_array_size_t>(G_B6_5), (String_t*)L_37);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_38 = G_B6_7;
		NullCheck(L_38);
		ArrayElementTypeCheck (L_38, _stringLiteral0484F5252B12C569CD2F3AEE4FCFD5DBE3C5967F);
		(L_38)->SetAt(static_cast<il2cpp_array_size_t>(2), (String_t*)_stringLiteral0484F5252B12C569CD2F3AEE4FCFD5DBE3C5967F);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_39 = L_38;
		float* L_40 = (float*)(&__this->___minWidth_0);
		String_t* L_41;
		L_41 = Single_ToString_mE282EDA9CA4F7DF88432D807732837A629D04972(L_40, NULL);
		NullCheck(L_39);
		ArrayElementTypeCheck (L_39, L_41);
		(L_39)->SetAt(static_cast<il2cpp_array_size_t>(3), (String_t*)L_41);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_42 = L_39;
		NullCheck(L_42);
		ArrayElementTypeCheck (L_42, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		(L_42)->SetAt(static_cast<il2cpp_array_size_t>(4), (String_t*)_stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_43 = L_42;
		float* L_44 = (float*)(&__this->___maxWidth_1);
		String_t* L_45;
		L_45 = Single_ToString_mE282EDA9CA4F7DF88432D807732837A629D04972(L_44, NULL);
		NullCheck(L_43);
		ArrayElementTypeCheck (L_43, L_45);
		(L_43)->SetAt(static_cast<il2cpp_array_size_t>(5), (String_t*)L_45);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_46 = L_43;
		int32_t L_47 = __this->___stretchWidth_5;
		G_B7_0 = 6;
		G_B7_1 = L_46;
		G_B7_2 = L_46;
		if (L_47)
		{
			G_B8_0 = 6;
			G_B8_1 = L_46;
			G_B8_2 = L_46;
			goto IL_00f4;
		}
	}
	{
		G_B9_0 = _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709;
		G_B9_1 = G_B7_0;
		G_B9_2 = G_B7_1;
		G_B9_3 = G_B7_2;
		goto IL_00f9;
	}

IL_00f4:
	{
		G_B9_0 = _stringLiteral20E39C3AB7068FAFD9E4B868E16D2E5BC64D4952;
		G_B9_1 = G_B8_0;
		G_B9_2 = G_B8_1;
		G_B9_3 = G_B8_2;
	}

IL_00f9:
	{
		NullCheck(G_B9_2);
		ArrayElementTypeCheck (G_B9_2, G_B9_0);
		(G_B9_2)->SetAt(static_cast<il2cpp_array_size_t>(G_B9_1), (String_t*)G_B9_0);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_48 = G_B9_3;
		NullCheck(L_48);
		ArrayElementTypeCheck (L_48, _stringLiteral0993C31116DED8F2DAA78B6A73E3149497A84400);
		(L_48)->SetAt(static_cast<il2cpp_array_size_t>(7), (String_t*)_stringLiteral0993C31116DED8F2DAA78B6A73E3149497A84400);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_49 = L_48;
		float* L_50 = (float*)(&__this->___minHeight_2);
		String_t* L_51;
		L_51 = Single_ToString_mE282EDA9CA4F7DF88432D807732837A629D04972(L_50, NULL);
		NullCheck(L_49);
		ArrayElementTypeCheck (L_49, L_51);
		(L_49)->SetAt(static_cast<il2cpp_array_size_t>(8), (String_t*)L_51);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_52 = L_49;
		NullCheck(L_52);
		ArrayElementTypeCheck (L_52, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		(L_52)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)9)), (String_t*)_stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_53 = L_52;
		float* L_54 = (float*)(&__this->___maxHeight_3);
		String_t* L_55;
		L_55 = Single_ToString_mE282EDA9CA4F7DF88432D807732837A629D04972(L_54, NULL);
		NullCheck(L_53);
		ArrayElementTypeCheck (L_53, L_55);
		(L_53)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)10)), (String_t*)L_55);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_56 = L_53;
		int32_t L_57 = __this->___stretchHeight_6;
		G_B10_0 = ((int32_t)11);
		G_B10_1 = L_56;
		G_B10_2 = L_56;
		if (L_57)
		{
			G_B11_0 = ((int32_t)11);
			G_B11_1 = L_56;
			G_B11_2 = L_56;
			goto IL_013a;
		}
	}
	{
		G_B12_0 = _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709;
		G_B12_1 = G_B10_0;
		G_B12_2 = G_B10_1;
		G_B12_3 = G_B10_2;
		goto IL_013f;
	}

IL_013a:
	{
		G_B12_0 = _stringLiteral20E39C3AB7068FAFD9E4B868E16D2E5BC64D4952;
		G_B12_1 = G_B11_0;
		G_B12_2 = G_B11_1;
		G_B12_3 = G_B11_2;
	}

IL_013f:
	{
		NullCheck(G_B12_2);
		ArrayElementTypeCheck (G_B12_2, G_B12_0);
		(G_B12_2)->SetAt(static_cast<il2cpp_array_size_t>(G_B12_1), (String_t*)G_B12_0);
		String_t* L_58;
		L_58 = String_Concat_m647EBF831F54B6DF7D5AFA5FD012CF4EE7571B6A(G_B12_3, NULL);
		V_3 = L_58;
		goto IL_0148;
	}

IL_0148:
	{
		String_t* L_59 = V_3;
		return L_59;
	}
}
// System.Void UnityEngine.GUILayoutEntry::.cctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUILayoutEntry__cctor_mF6F64749802F89E5AA0A1458CE99CA5FC0D639C2 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D L_0;
		memset((&L_0), 0, sizeof(L_0));
		Rect__ctor_m18C3033D135097BEE424AAA68D91C706D2647F23((&L_0), (0.0f), (0.0f), (1.0f), (1.0f), /*hidden argument*/NULL);
		((GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F_StaticFields*)il2cpp_codegen_static_fields_for(GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F_il2cpp_TypeInfo_var))->___kDummyRect_9 = L_0;
		((GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F_StaticFields*)il2cpp_codegen_static_fields_for(GUILayoutEntry_tDF59F19DD000820F64B356D5092C4BEDFE109D5F_il2cpp_TypeInfo_var))->___indent_10 = 0;
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
// System.Void UnityEngine.GUILayoutOption::.ctor(UnityEngine.GUILayoutOption/Type,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GUILayoutOption__ctor_m4EF826EA43073869166C8D94A1D9EB7898ACC3AA (GUILayoutOption_t8B0AA056521747053A3176FCC43E9C3608940A14* __this, int32_t ___0_type, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_type;
		__this->___type_0 = L_0;
		RuntimeObject* L_1 = ___1_value;
		__this->___value_1 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___value_1), (void*)L_1);
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
// System.UInt32 <PrivateImplementationDetails>::ComputeStringHash(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t U3CPrivateImplementationDetailsU3E_ComputeStringHash_m3791FADF6D0284BCC1AF6156A077038C2AA23055 (String_t* ___0_s, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		String_t* L_0 = ___0_s;
		if (!L_0)
		{
			goto IL_002c;
		}
	}
	{
		V_0 = ((int32_t)-2128831035);
		V_1 = 0;
		goto IL_0021;
	}

IL_000d:
	{
		String_t* L_1 = ___0_s;
		int32_t L_2 = V_1;
		NullCheck(L_1);
		Il2CppChar L_3;
		L_3 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_1, L_2, NULL);
		uint32_t L_4 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_multiply(((int32_t)((int32_t)L_3^(int32_t)L_4)), ((int32_t)16777619)));
		int32_t L_5 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_5, 1));
	}

IL_0021:
	{
		int32_t L_6 = V_1;
		String_t* L_7 = ___0_s;
		NullCheck(L_7);
		int32_t L_8;
		L_8 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_7, NULL);
		if ((((int32_t)L_6) >= ((int32_t)L_8)))
		{
			goto IL_002c;
		}
	}
	{
		goto IL_000d;
	}

IL_002c:
	{
		uint32_t L_9 = V_0;
		return L_9;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR StringComparer_t6268F19CA34879176651429C0D8A3D0002BB8E06* StringComparer_get_OrdinalIgnoreCase_m071AA1B1747345CCA058A3879EBDEBBA2EA4B169_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringComparer_t6268F19CA34879176651429C0D8A3D0002BB8E06_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		il2cpp_codegen_runtime_class_init_inline(StringComparer_t6268F19CA34879176651429C0D8A3D0002BB8E06_il2cpp_TypeInfo_var);
		OrdinalIgnoreCaseComparer_t8BAE11990A4C855D3BCBBFB42F4EF8D45088FBB0* L_0 = ((StringComparer_t6268F19CA34879176651429C0D8A3D0002BB8E06_StaticFields*)il2cpp_codegen_static_fields_for(StringComparer_t6268F19CA34879176651429C0D8A3D0002BB8E06_il2cpp_TypeInfo_var))->___s_ordinalIgnoreCase_3;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Color_tD001788D726C3A7F1379BEED0260B9591F440C1F Color_get_red_mA2E53E7173FDC97E68E335049AB0FAAEE43A844D_inline (const RuntimeMethod* method) 
{
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_0;
		memset((&L_0), 0, sizeof(L_0));
		Color__ctor_m3786F0D6E510D9CFA544523A955870BD2A514C8C_inline((&L_0), (1.0f), (0.0f), (0.0f), (1.0f), /*hidden argument*/NULL);
		V_0 = L_0;
		goto IL_001d;
	}

IL_001d:
	{
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_1 = V_0;
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void SkinChangedDelegate_Invoke_mD14214487F9A0E4DD7EB7F97927D03EC8F1A3B4C_inline (SkinChangedDelegate_tA6D456E853D58AD2EF8A599F543C7E5BA8E94B98* __this, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____stringLength_4;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Color__ctor_m3786F0D6E510D9CFA544523A955870BD2A514C8C_inline (Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* __this, float ___0_r, float ___1_g, float ___2_b, float ___3_a, const RuntimeMethod* method) 
{
	{
		float L_0 = ___0_r;
		__this->___r_0 = L_0;
		float L_1 = ___1_g;
		__this->___g_1 = L_1;
		float L_2 = ___2_b;
		__this->___b_2 = L_2;
		float L_3 = ___3_a;
		__this->___a_3 = L_3;
		return;
	}
}
