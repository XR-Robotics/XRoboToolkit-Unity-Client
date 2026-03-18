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

// System.Collections.Generic.Dictionary`2<System.Int32,System.Globalization.CultureInfo>
struct Dictionary_2_t9FA6D82CAFC18769F7515BB51D1C56DAE09381C3;
// System.Collections.Generic.Dictionary`2<System.String,System.Globalization.CultureInfo>
struct Dictionary_2_tE1603CE612C16451D1E56FF4D4859D4FE4087C28;
// System.Byte[]
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
// System.Char[]
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
// System.IntPtr[]
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
// System.Object[]
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
// System.Diagnostics.StackTrace[]
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
// System.String[]
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
// Mono.Security.ASN1
struct ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F;
// System.ArgumentNullException
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129;
// System.Collections.ArrayList
struct ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A;
// System.Globalization.Calendar
struct Calendar_t0A117CC7532A54C17188C2EFEA1F79DB20DF3A3B;
// System.Globalization.CompareInfo
struct CompareInfo_t1B1A6AC3486B570C76ABA52149C9BD4CD82F9E57;
// System.Globalization.CultureData
struct CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D;
// System.Globalization.CultureInfo
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0;
// System.Globalization.DateTimeFormatInfo
struct DateTimeFormatInfo_t0457520F9FA7B5C8EAAEB3AD50413B6AEEB7458A;
// System.FormatException
struct FormatException_tCD210E92627903FFEDAAA706C08FB6222B4D012B;
// System.Collections.IDictionary
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
// System.IFormatProvider
struct IFormatProvider_tC202922D43BFF3525109ABF3FB79625F5646AB52;
// System.NotSupportedException
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A;
// System.Globalization.NumberFormatInfo
struct NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472;
// System.Runtime.Serialization.SafeSerializationManager
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
// System.String
struct String_t;
// System.Text.StringBuilder
struct StringBuilder_t;
// System.Globalization.TextInfo
struct TextInfo_tD3BAFCFD77418851E7D5CB8D2588F47019E414B4;
// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;

IL2CPP_EXTERN_C RuntimeClass* ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* BitConverter_t6E99605185963BC12B3D369E13F2B88997E64A27_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* FormatException_tCD210E92627903FFEDAAA706C08FB6222B4D012B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringBuilder_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral07C3F7BAA7B4AB0D6D2DA7749FA8ACA206FD73F8;
IL2CPP_EXTERN_C String_t* _stringLiteral103949F0C75755294C4E46F97193DE6B9FC8DAD7;
IL2CPP_EXTERN_C String_t* _stringLiteral1A9141C6D604CE4530FB3983D2DD3178E36CC069;
IL2CPP_EXTERN_C String_t* _stringLiteral1B548BEAD44216247E991F18006F8DEA22021F68;
IL2CPP_EXTERN_C String_t* _stringLiteral393DDC767F48626B0317297F8A961E12A2DFC6B6;
IL2CPP_EXTERN_C String_t* _stringLiteral64EF02A69B970330DD01FA1A603CAE5EFC04FB89;
IL2CPP_EXTERN_C String_t* _stringLiteral949E308288B2FD68A8A495751C8D81446AE026E7;
IL2CPP_EXTERN_C String_t* _stringLiteralB4A94E440E57B3321B2097CEC9E046D28EE1C0CD;
IL2CPP_EXTERN_C String_t* _stringLiteralF3E84B722399601AD7E281754E917478AA9AD48D;
IL2CPP_EXTERN_C const RuntimeMethod* ASN1Convert_ToInt32_m956785EB4A235575C21677C16D2F6CBE54787032_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ASN1Convert_ToOid_mBCE4FD3970C556190FB00A6AD409A6ABB4C627D8_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ASN1__ctor_m950BFCCF44A987ACBA12142624AA222200EE503E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Array_Empty_TisRuntimeObject_mFB8A63D602BB6974D31E20300D9EB89C6FE7C278_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Array_Reverse_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m4298AF0CA764FA936F9C5ED3606D1B4E2EC9EBA2_RuntimeMethod_var;
struct CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D_marshaled_com;
struct CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D_marshaled_pinvoke;
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_com;
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// <Module>
struct U3CModuleU3E_t90149EF90407715CC46EB5A9704669888393F1DE 
{
};

// System.EmptyArray`1<System.Object>
struct EmptyArray_1_tDF0DD7256B115243AA6BD5558417387A734240EE  : public RuntimeObject
{
};

// Mono.Security.ASN1
struct ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F  : public RuntimeObject
{
	// System.Byte Mono.Security.ASN1::m_nTag
	uint8_t ___m_nTag_0;
	// System.Byte[] Mono.Security.ASN1::m_aValue
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___m_aValue_1;
	// System.Collections.ArrayList Mono.Security.ASN1::elist
	ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* ___elist_2;
};

// Mono.Security.ASN1Convert
struct ASN1Convert_tDA6D2B7710D7868F3D559D5BE7F2C7816BB50AB6  : public RuntimeObject
{
};

// System.Collections.ArrayList
struct ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A  : public RuntimeObject
{
	// System.Object[] System.Collections.ArrayList::_items
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ____items_0;
	// System.Int32 System.Collections.ArrayList::_size
	int32_t ____size_1;
	// System.Int32 System.Collections.ArrayList::_version
	int32_t ____version_2;
	// System.Object System.Collections.ArrayList::_syncRoot
	RuntimeObject* ____syncRoot_3;
};

// System.BitConverter
struct BitConverter_t6E99605185963BC12B3D369E13F2B88997E64A27  : public RuntimeObject
{
};

// Mono.Security.BitConverterLE
struct BitConverterLE_tB6EF365ED05024FCC12DA3939B10FDEBDB29E1BD  : public RuntimeObject
{
};

// Mono.Security.Cryptography.CryptoConvert
struct CryptoConvert_t676AC22DA6332E9936696ECC97197AB7B1BC7252  : public RuntimeObject
{
};

// System.Globalization.CultureInfo
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0  : public RuntimeObject
{
	// System.Boolean System.Globalization.CultureInfo::m_isReadOnly
	bool ___m_isReadOnly_3;
	// System.Int32 System.Globalization.CultureInfo::cultureID
	int32_t ___cultureID_4;
	// System.Int32 System.Globalization.CultureInfo::parent_lcid
	int32_t ___parent_lcid_5;
	// System.Int32 System.Globalization.CultureInfo::datetime_index
	int32_t ___datetime_index_6;
	// System.Int32 System.Globalization.CultureInfo::number_index
	int32_t ___number_index_7;
	// System.Int32 System.Globalization.CultureInfo::default_calendar_type
	int32_t ___default_calendar_type_8;
	// System.Boolean System.Globalization.CultureInfo::m_useUserOverride
	bool ___m_useUserOverride_9;
	// System.Globalization.NumberFormatInfo modreq(System.Runtime.CompilerServices.IsVolatile) System.Globalization.CultureInfo::numInfo
	NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* ___numInfo_10;
	// System.Globalization.DateTimeFormatInfo modreq(System.Runtime.CompilerServices.IsVolatile) System.Globalization.CultureInfo::dateTimeInfo
	DateTimeFormatInfo_t0457520F9FA7B5C8EAAEB3AD50413B6AEEB7458A* ___dateTimeInfo_11;
	// System.Globalization.TextInfo modreq(System.Runtime.CompilerServices.IsVolatile) System.Globalization.CultureInfo::textInfo
	TextInfo_tD3BAFCFD77418851E7D5CB8D2588F47019E414B4* ___textInfo_12;
	// System.String System.Globalization.CultureInfo::m_name
	String_t* ___m_name_13;
	// System.String System.Globalization.CultureInfo::englishname
	String_t* ___englishname_14;
	// System.String System.Globalization.CultureInfo::nativename
	String_t* ___nativename_15;
	// System.String System.Globalization.CultureInfo::iso3lang
	String_t* ___iso3lang_16;
	// System.String System.Globalization.CultureInfo::iso2lang
	String_t* ___iso2lang_17;
	// System.String System.Globalization.CultureInfo::win3lang
	String_t* ___win3lang_18;
	// System.String System.Globalization.CultureInfo::territory
	String_t* ___territory_19;
	// System.String[] System.Globalization.CultureInfo::native_calendar_names
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___native_calendar_names_20;
	// System.Globalization.CompareInfo modreq(System.Runtime.CompilerServices.IsVolatile) System.Globalization.CultureInfo::compareInfo
	CompareInfo_t1B1A6AC3486B570C76ABA52149C9BD4CD82F9E57* ___compareInfo_21;
	// System.Void* System.Globalization.CultureInfo::textinfo_data
	void* ___textinfo_data_22;
	// System.Int32 System.Globalization.CultureInfo::m_dataItem
	int32_t ___m_dataItem_23;
	// System.Globalization.Calendar System.Globalization.CultureInfo::calendar
	Calendar_t0A117CC7532A54C17188C2EFEA1F79DB20DF3A3B* ___calendar_24;
	// System.Globalization.CultureInfo System.Globalization.CultureInfo::parent_culture
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___parent_culture_25;
	// System.Boolean System.Globalization.CultureInfo::constructed
	bool ___constructed_26;
	// System.Byte[] System.Globalization.CultureInfo::cached_serialized_form
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___cached_serialized_form_27;
	// System.Globalization.CultureData System.Globalization.CultureInfo::m_cultureData
	CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D* ___m_cultureData_28;
	// System.Boolean System.Globalization.CultureInfo::m_isInherited
	bool ___m_isInherited_29;
};
// Native definition for P/Invoke marshalling of System.Globalization.CultureInfo
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_pinvoke
{
	int32_t ___m_isReadOnly_3;
	int32_t ___cultureID_4;
	int32_t ___parent_lcid_5;
	int32_t ___datetime_index_6;
	int32_t ___number_index_7;
	int32_t ___default_calendar_type_8;
	int32_t ___m_useUserOverride_9;
	NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* ___numInfo_10;
	DateTimeFormatInfo_t0457520F9FA7B5C8EAAEB3AD50413B6AEEB7458A* ___dateTimeInfo_11;
	TextInfo_tD3BAFCFD77418851E7D5CB8D2588F47019E414B4* ___textInfo_12;
	char* ___m_name_13;
	char* ___englishname_14;
	char* ___nativename_15;
	char* ___iso3lang_16;
	char* ___iso2lang_17;
	char* ___win3lang_18;
	char* ___territory_19;
	char** ___native_calendar_names_20;
	CompareInfo_t1B1A6AC3486B570C76ABA52149C9BD4CD82F9E57* ___compareInfo_21;
	void* ___textinfo_data_22;
	int32_t ___m_dataItem_23;
	Calendar_t0A117CC7532A54C17188C2EFEA1F79DB20DF3A3B* ___calendar_24;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_pinvoke* ___parent_culture_25;
	int32_t ___constructed_26;
	Il2CppSafeArray/*NONE*/* ___cached_serialized_form_27;
	CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D_marshaled_pinvoke* ___m_cultureData_28;
	int32_t ___m_isInherited_29;
};
// Native definition for COM marshalling of System.Globalization.CultureInfo
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_com
{
	int32_t ___m_isReadOnly_3;
	int32_t ___cultureID_4;
	int32_t ___parent_lcid_5;
	int32_t ___datetime_index_6;
	int32_t ___number_index_7;
	int32_t ___default_calendar_type_8;
	int32_t ___m_useUserOverride_9;
	NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* ___numInfo_10;
	DateTimeFormatInfo_t0457520F9FA7B5C8EAAEB3AD50413B6AEEB7458A* ___dateTimeInfo_11;
	TextInfo_tD3BAFCFD77418851E7D5CB8D2588F47019E414B4* ___textInfo_12;
	Il2CppChar* ___m_name_13;
	Il2CppChar* ___englishname_14;
	Il2CppChar* ___nativename_15;
	Il2CppChar* ___iso3lang_16;
	Il2CppChar* ___iso2lang_17;
	Il2CppChar* ___win3lang_18;
	Il2CppChar* ___territory_19;
	Il2CppChar** ___native_calendar_names_20;
	CompareInfo_t1B1A6AC3486B570C76ABA52149C9BD4CD82F9E57* ___compareInfo_21;
	void* ___textinfo_data_22;
	int32_t ___m_dataItem_23;
	Calendar_t0A117CC7532A54C17188C2EFEA1F79DB20DF3A3B* ___calendar_24;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_com* ___parent_culture_25;
	int32_t ___constructed_26;
	Il2CppSafeArray/*NONE*/* ___cached_serialized_form_27;
	CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D_marshaled_com* ___m_cultureData_28;
	int32_t ___m_isInherited_29;
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

// System.UInt64
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF 
{
	// System.UInt64 System.UInt64::m_value
	uint64_t ___m_value_0;
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

// System.SystemException
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};

// System.ArgumentException
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
	// System.String System.ArgumentException::_paramName
	String_t* ____paramName_18;
};

// System.FormatException
struct FormatException_tCD210E92627903FFEDAAA706C08FB6222B4D012B  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};

// System.NotSupportedException
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
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

// <Module>

// <Module>

// System.EmptyArray`1<System.Object>
struct EmptyArray_1_tDF0DD7256B115243AA6BD5558417387A734240EE_StaticFields
{
	// T[] System.EmptyArray`1::Value
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___Value_0;
};

// System.EmptyArray`1<System.Object>

// Mono.Security.ASN1

// Mono.Security.ASN1

// Mono.Security.ASN1Convert

// Mono.Security.ASN1Convert

// System.Collections.ArrayList

// System.Collections.ArrayList

// System.BitConverter
struct BitConverter_t6E99605185963BC12B3D369E13F2B88997E64A27_StaticFields
{
	// System.Boolean System.BitConverter::IsLittleEndian
	bool ___IsLittleEndian_0;
};

// System.BitConverter

// Mono.Security.BitConverterLE

// Mono.Security.BitConverterLE

// Mono.Security.Cryptography.CryptoConvert

// Mono.Security.Cryptography.CryptoConvert

// System.Globalization.CultureInfo
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_StaticFields
{
	// System.Globalization.CultureInfo modreq(System.Runtime.CompilerServices.IsVolatile) System.Globalization.CultureInfo::invariant_culture_info
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___invariant_culture_info_0;
	// System.Object System.Globalization.CultureInfo::shared_table_lock
	RuntimeObject* ___shared_table_lock_1;
	// System.Globalization.CultureInfo System.Globalization.CultureInfo::default_current_culture
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___default_current_culture_2;
	// System.Globalization.CultureInfo modreq(System.Runtime.CompilerServices.IsVolatile) System.Globalization.CultureInfo::s_DefaultThreadCurrentUICulture
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___s_DefaultThreadCurrentUICulture_34;
	// System.Globalization.CultureInfo modreq(System.Runtime.CompilerServices.IsVolatile) System.Globalization.CultureInfo::s_DefaultThreadCurrentCulture
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___s_DefaultThreadCurrentCulture_35;
	// System.Collections.Generic.Dictionary`2<System.Int32,System.Globalization.CultureInfo> System.Globalization.CultureInfo::shared_by_number
	Dictionary_2_t9FA6D82CAFC18769F7515BB51D1C56DAE09381C3* ___shared_by_number_36;
	// System.Collections.Generic.Dictionary`2<System.String,System.Globalization.CultureInfo> System.Globalization.CultureInfo::shared_by_name
	Dictionary_2_tE1603CE612C16451D1E56FF4D4859D4FE4087C28* ___shared_by_name_37;
	// System.Globalization.CultureInfo System.Globalization.CultureInfo::s_UserPreferredCultureInfoInAppX
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___s_UserPreferredCultureInfoInAppX_38;
	// System.Boolean System.Globalization.CultureInfo::IsTaiwanSku
	bool ___IsTaiwanSku_39;
};

// System.Globalization.CultureInfo

// System.String
struct String_t_StaticFields
{
	// System.String System.String::Empty
	String_t* ___Empty_6;
};

// System.String

// System.Text.StringBuilder

// System.Text.StringBuilder

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

// System.Int32

// System.Int32

// System.UInt64

// System.UInt64

// System.Void

// System.Void

// System.FormatException

// System.FormatException

// System.NotSupportedException

// System.NotSupportedException

// System.ArgumentNullException

// System.ArgumentNullException

// System.ArgumentOutOfRangeException

// System.ArgumentOutOfRangeException
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// System.Byte[]
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031  : public RuntimeArray
{
	ALIGN_FIELD (8) uint8_t m_Items[1];

	inline uint8_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline uint8_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, uint8_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline uint8_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline uint8_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, uint8_t value)
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


// T[] System.Array::Empty<System.Object>()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* Array_Empty_TisRuntimeObject_mFB8A63D602BB6974D31E20300D9EB89C6FE7C278_gshared_inline (const RuntimeMethod* method) ;
// System.Void System.Array::Reverse<System.Byte>(T[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m4298AF0CA764FA936F9C5ED3606D1B4E2EC9EBA2_gshared (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_array, const RuntimeMethod* method) ;

// System.Void Mono.Security.ASN1::.ctor(System.Byte,System.Byte[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ASN1__ctor_mAA538F9E1BE0DE739E9747BC3BC71DC030B018AA (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, uint8_t ___0_tag, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___1_data, const RuntimeMethod* method) ;
// System.Void System.Object::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
// System.Void System.NotSupportedException::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* __this, String_t* ___0_message, const RuntimeMethod* method) ;
// System.Void System.Buffer::BlockCopy(System.Array,System.Int32,System.Array,System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_BlockCopy_m2F7BC0C5BA97C500E3F87D5008718F797E02B358 (RuntimeArray* ___0_src, int32_t ___1_srcOffset, RuntimeArray* ___2_dst, int32_t ___3_dstOffset, int32_t ___4_count, const RuntimeMethod* method) ;
// System.Void Mono.Security.ASN1::Decode(System.Byte[],System.Int32&,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ASN1_Decode_mC4CF3CB2CC1DB454AA9C720BA79520956FB1F77B (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_asn1, int32_t* ___1_anPos, int32_t ___2_anLength, const RuntimeMethod* method) ;
// System.Object System.Array::Clone()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Array_Clone_m66C9D0727C9BAA0995E4142F29B45BC03582E042 (RuntimeArray* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.ArrayList::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArrayList__ctor_m07DC369002304B483B9FC41DBDAF4A25AC3C9F80 (ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* __this, const RuntimeMethod* method) ;
// System.Int32 Mono.Security.ASN1::get_Count()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ASN1_get_Count_mBE45E73126FAD2694E9059CAC53B7AC9A5F60833 (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, const RuntimeMethod* method) ;
// System.Void Mono.Security.ASN1::DecodeTLV(System.Byte[],System.Int32&,System.Byte&,System.Int32&,System.Byte[]&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ASN1_DecodeTLV_mD4465394202DA7B0D37B9453CDE039233969E9DF (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_asn1, int32_t* ___1_pos, uint8_t* ___2_tag, int32_t* ___3_length, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** ___4_content, const RuntimeMethod* method) ;
// Mono.Security.ASN1 Mono.Security.ASN1::Add(Mono.Security.ASN1)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* ASN1_Add_m4C61487A6CCF48D5CEB0D97B248FE31F9FCD849F (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* ___0_asn1, const RuntimeMethod* method) ;
// System.Void System.Text.StringBuilder::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D (StringBuilder_t* __this, const RuntimeMethod* method) ;
// System.String System.Byte::ToString(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Byte_ToString_m793A41EEEB7B422F6FE658E99D2F7683F59EE310 (uint8_t* __this, String_t* ___0_format, const RuntimeMethod* method) ;
// System.String System.Environment::get_NewLine()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Environment_get_NewLine_m8BF68A4EFDAFFB66500984CE779629811BA98FFF (const RuntimeMethod* method) ;
// System.Text.StringBuilder System.Text.StringBuilder::AppendFormat(System.String,System.Object,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_AppendFormat_mAB076D92DC92723B2224D75987BE463AF1CE7132 (StringBuilder_t* __this, String_t* ___0_format, RuntimeObject* ___1_arg0, RuntimeObject* ___2_arg1, const RuntimeMethod* method) ;
// System.Byte[] Mono.Security.ASN1::get_Value()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ASN1_get_Value_mA6F9BE5AC19AC060AC42673C8FD5AA864EA046B6 (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, const RuntimeMethod* method) ;
// System.Text.StringBuilder System.Text.StringBuilder::Append(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D (StringBuilder_t* __this, String_t* ___0_value, const RuntimeMethod* method) ;
// System.Text.StringBuilder System.Text.StringBuilder::AppendFormat(System.String,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_AppendFormat_mFA88863E4018C2912D1A783E0EA6DAE4F594124F (StringBuilder_t* __this, String_t* ___0_format, RuntimeObject* ___1_arg0, const RuntimeMethod* method) ;
// T[] System.Array::Empty<System.Object>()
inline ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* Array_Empty_TisRuntimeObject_mFB8A63D602BB6974D31E20300D9EB89C6FE7C278_inline (const RuntimeMethod* method)
{
	return ((  ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* (*) (const RuntimeMethod*))Array_Empty_TisRuntimeObject_mFB8A63D602BB6974D31E20300D9EB89C6FE7C278_gshared_inline)(method);
}
// System.Text.StringBuilder System.Text.StringBuilder::AppendFormat(System.String,System.Object[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_AppendFormat_m14CB447291E6149BCF32E5E37DA21514BAD9C151 (StringBuilder_t* __this, String_t* ___0_format, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___1_args, const RuntimeMethod* method) ;
// System.Byte[] Mono.Security.BitConverterLE::GetBytes(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* BitConverterLE_GetBytes_mEEFE00015D501FBBD32225D9C45A2C2A0673E9C7 (int32_t ___0_value, const RuntimeMethod* method) ;
// System.Void System.Array::Reverse<System.Byte>(T[])
inline void Array_Reverse_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m4298AF0CA764FA936F9C5ED3606D1B4E2EC9EBA2 (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_array, const RuntimeMethod* method)
{
	((  void (*) (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*, const RuntimeMethod*))Array_Reverse_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m4298AF0CA764FA936F9C5ED3606D1B4E2EC9EBA2_gshared)(___0_array, method);
}
// System.Void Mono.Security.ASN1::.ctor(System.Byte)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ASN1__ctor_mA9AE2197367C1E13DBFDA67E0A383167F52CC114 (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, uint8_t ___0_tag, const RuntimeMethod* method) ;
// System.Void Mono.Security.ASN1::set_Value(System.Byte[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ASN1_set_Value_mAFFA885810928715B379EAD478AA3961E8ACD589 (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_value, const RuntimeMethod* method) ;
// System.Void System.ArgumentNullException::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* __this, String_t* ___0_paramName, const RuntimeMethod* method) ;
// System.Byte Mono.Security.ASN1::get_Tag()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint8_t ASN1_get_Tag_m1984CF0DDF54424E61BA3650D93CBA0DCB58F232_inline (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, const RuntimeMethod* method) ;
// System.Void System.FormatException::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void FormatException__ctor_mE04AEA59C0EEFF4BD34B7CE8601F9D331D1D473E (FormatException_tCD210E92627903FFEDAAA706C08FB6222B4D012B* __this, String_t* ___0_message, const RuntimeMethod* method) ;
// System.Globalization.CultureInfo System.Globalization.CultureInfo::get_InvariantCulture()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* CultureInfo_get_InvariantCulture_mD1E96DC845E34B10F78CB744B0CB5D7D63CEB1E6 (const RuntimeMethod* method) ;
// System.String System.Byte::ToString(System.IFormatProvider)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Byte_ToString_m3F9787FE9A306FE63F388635DEE2733F91588A86 (uint8_t* __this, RuntimeObject* ___0_provider, const RuntimeMethod* method) ;
// System.String System.UInt64::ToString(System.IFormatProvider)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* UInt64_ToString_mCDDACF05D6B5B3ECB10B1FEEE58ED3407973E7A7 (uint64_t* __this, RuntimeObject* ___0_provider, const RuntimeMethod* method) ;
// System.Byte[] Mono.Security.BitConverterLE::GetUIntBytes(System.Byte*)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* BitConverterLE_GetUIntBytes_mED0A55F565721091E851FD6108E128C3CBCB87F0 (uint8_t* ___0_bytes, const RuntimeMethod* method) ;
// System.Void System.Text.StringBuilder::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StringBuilder__ctor_m2619CA8D2C3476DF1A302D9D941498BB1C6164C5 (StringBuilder_t* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
// System.String System.Byte::ToString(System.String,System.IFormatProvider)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Byte_ToString_m64EE358F20093EE61D30F9A21638D9E9EE8F87EC (uint8_t* __this, String_t* ___0_format, RuntimeObject* ___1_provider, const RuntimeMethod* method) ;
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
// System.Void Mono.Security.ASN1::.ctor(System.Byte)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ASN1__ctor_mA9AE2197367C1E13DBFDA67E0A383167F52CC114 (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, uint8_t ___0_tag, const RuntimeMethod* method) 
{
	{
		uint8_t L_0 = ___0_tag;
		ASN1__ctor_mAA538F9E1BE0DE739E9747BC3BC71DC030B018AA(__this, L_0, (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)NULL, NULL);
		return;
	}
}
// System.Void Mono.Security.ASN1::.ctor(System.Byte,System.Byte[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ASN1__ctor_mAA538F9E1BE0DE739E9747BC3BC71DC030B018AA (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, uint8_t ___0_tag, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___1_data, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		uint8_t L_0 = ___0_tag;
		__this->___m_nTag_0 = L_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = ___1_data;
		__this->___m_aValue_1 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_aValue_1), (void*)L_1);
		return;
	}
}
// System.Void Mono.Security.ASN1::.ctor(System.Byte[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ASN1__ctor_m950BFCCF44A987ACBA12142624AA222200EE503E (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_data, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___0_data;
		NullCheck(L_0);
		int32_t L_1 = 0;
		uint8_t L_2 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_1));
		__this->___m_nTag_0 = L_2;
		V_0 = 0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = ___0_data;
		NullCheck(L_3);
		int32_t L_4 = 1;
		uint8_t L_5 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		V_1 = L_5;
		int32_t L_6 = V_1;
		if ((((int32_t)L_6) <= ((int32_t)((int32_t)128))))
		{
			goto IL_0045;
		}
	}
	{
		int32_t L_7 = V_1;
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_7, ((int32_t)128)));
		V_1 = 0;
		V_2 = 0;
		goto IL_003f;
	}

IL_002b:
	{
		int32_t L_8 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_multiply(L_8, ((int32_t)256)));
		int32_t L_9 = V_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_10 = ___0_data;
		int32_t L_11 = V_2;
		NullCheck(L_10);
		int32_t L_12 = ((int32_t)il2cpp_codegen_add(L_11, 2));
		uint8_t L_13 = (L_10)->GetAt(static_cast<il2cpp_array_size_t>(L_12));
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, (int32_t)L_13));
		int32_t L_14 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_14, 1));
	}

IL_003f:
	{
		int32_t L_15 = V_2;
		int32_t L_16 = V_0;
		if ((((int32_t)L_15) < ((int32_t)L_16)))
		{
			goto IL_002b;
		}
	}
	{
		goto IL_0058;
	}

IL_0045:
	{
		int32_t L_17 = V_1;
		if ((!(((uint32_t)L_17) == ((uint32_t)((int32_t)128)))))
		{
			goto IL_0058;
		}
	}
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_18 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NullCheck(L_18);
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_18, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral393DDC767F48626B0317297F8A961E12A2DFC6B6)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_18, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ASN1__ctor_m950BFCCF44A987ACBA12142624AA222200EE503E_RuntimeMethod_var)));
	}

IL_0058:
	{
		int32_t L_19 = V_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_20 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)L_19);
		__this->___m_aValue_1 = L_20;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_aValue_1), (void*)L_20);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_21 = ___0_data;
		int32_t L_22 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_23 = __this->___m_aValue_1;
		int32_t L_24 = V_1;
		Buffer_BlockCopy_m2F7BC0C5BA97C500E3F87D5008718F797E02B358((RuntimeArray*)L_21, ((int32_t)il2cpp_codegen_add(2, L_22)), (RuntimeArray*)L_23, 0, L_24, NULL);
		uint8_t L_25 = __this->___m_nTag_0;
		if ((!(((uint32_t)((int32_t)((int32_t)L_25&((int32_t)32)))) == ((uint32_t)((int32_t)32)))))
		{
			goto IL_009a;
		}
	}
	{
		V_3 = 0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_26 = __this->___m_aValue_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_27 = __this->___m_aValue_1;
		NullCheck(L_27);
		ASN1_Decode_mC4CF3CB2CC1DB454AA9C720BA79520956FB1F77B(__this, L_26, (&V_3), ((int32_t)(((RuntimeArray*)L_27)->max_length)), NULL);
	}

IL_009a:
	{
		return;
	}
}
// System.Int32 Mono.Security.ASN1::get_Count()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ASN1_get_Count_mBE45E73126FAD2694E9059CAC53B7AC9A5F60833 (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, const RuntimeMethod* method) 
{
	{
		ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* L_0 = __this->___elist_2;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		return 0;
	}

IL_000a:
	{
		ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* L_1 = __this->___elist_2;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = VirtualFuncInvoker0< int32_t >::Invoke(22 /* System.Int32 System.Collections.ArrayList::get_Count() */, L_1);
		return L_2;
	}
}
// System.Byte Mono.Security.ASN1::get_Tag()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t ASN1_get_Tag_m1984CF0DDF54424E61BA3650D93CBA0DCB58F232 (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, const RuntimeMethod* method) 
{
	{
		uint8_t L_0 = __this->___m_nTag_0;
		return L_0;
	}
}
// System.Byte[] Mono.Security.ASN1::get_Value()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ASN1_get_Value_mA6F9BE5AC19AC060AC42673C8FD5AA864EA046B6 (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = __this->___m_aValue_1;
		if (L_0)
		{
			goto IL_000f;
		}
	}
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1;
		L_1 = VirtualFuncInvoker0< ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* >::Invoke(4 /* System.Byte[] Mono.Security.ASN1::GetBytes() */, __this);
	}

IL_000f:
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = __this->___m_aValue_1;
		NullCheck((RuntimeArray*)L_2);
		RuntimeObject* L_3;
		L_3 = Array_Clone_m66C9D0727C9BAA0995E4142F29B45BC03582E042((RuntimeArray*)L_2, NULL);
		return ((ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)Castclass((RuntimeObject*)L_3, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var));
	}
}
// System.Void Mono.Security.ASN1::set_Value(System.Byte[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ASN1_set_Value_mAFFA885810928715B379EAD478AA3961E8ACD589 (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___0_value;
		if (!L_0)
		{
			goto IL_0014;
		}
	}
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = ___0_value;
		NullCheck((RuntimeArray*)L_1);
		RuntimeObject* L_2;
		L_2 = Array_Clone_m66C9D0727C9BAA0995E4142F29B45BC03582E042((RuntimeArray*)L_1, NULL);
		__this->___m_aValue_1 = ((ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)Castclass((RuntimeObject*)L_2, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var));
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_aValue_1), (void*)((ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)Castclass((RuntimeObject*)L_2, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var)));
	}

IL_0014:
	{
		return;
	}
}
// Mono.Security.ASN1 Mono.Security.ASN1::Add(Mono.Security.ASN1)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* ASN1_Add_m4C61487A6CCF48D5CEB0D97B248FE31F9FCD849F (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* ___0_asn1, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* L_0 = ___0_asn1;
		if (!L_0)
		{
			goto IL_0023;
		}
	}
	{
		ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* L_1 = __this->___elist_2;
		if (L_1)
		{
			goto IL_0016;
		}
	}
	{
		ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* L_2 = (ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A*)il2cpp_codegen_object_new(ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		ArrayList__ctor_m07DC369002304B483B9FC41DBDAF4A25AC3C9F80(L_2, NULL);
		__this->___elist_2 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___elist_2), (void*)L_2);
	}

IL_0016:
	{
		ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* L_3 = __this->___elist_2;
		ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* L_4 = ___0_asn1;
		NullCheck(L_3);
		int32_t L_5;
		L_5 = VirtualFuncInvoker1< int32_t, RuntimeObject* >::Invoke(29 /* System.Int32 System.Collections.ArrayList::Add(System.Object) */, L_3, L_4);
	}

IL_0023:
	{
		ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* L_6 = ___0_asn1;
		return L_6;
	}
}
// System.Byte[] Mono.Security.ASN1::GetBytes()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ASN1_GetBytes_m3B7DABFDBE6BF7F9C926E4C8A16FC6BE6D1CE67B (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_0 = NULL;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* V_4 = NULL;
	int32_t V_5 = 0;
	RuntimeObject* V_6 = NULL;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_7 = NULL;
	RuntimeObject* V_8 = NULL;
	int32_t V_9 = 0;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_10 = NULL;
	int32_t V_11 = 0;
	{
		V_0 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)NULL;
		int32_t L_0;
		L_0 = ASN1_get_Count_mBE45E73126FAD2694E9059CAC53B7AC9A5F60833(__this, NULL);
		if ((((int32_t)L_0) <= ((int32_t)0)))
		{
			goto IL_00b8;
		}
	}
	{
		V_3 = 0;
		ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* L_1 = (ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A*)il2cpp_codegen_object_new(ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		ArrayList__ctor_m07DC369002304B483B9FC41DBDAF4A25AC3C9F80(L_1, NULL);
		V_4 = L_1;
		ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* L_2 = __this->___elist_2;
		NullCheck(L_2);
		RuntimeObject* L_3;
		L_3 = VirtualFuncInvoker0< RuntimeObject* >::Invoke(35 /* System.Collections.IEnumerator System.Collections.ArrayList::GetEnumerator() */, L_2);
		V_6 = L_3;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0055:
			{// begin finally (depth: 1)
				{
					RuntimeObject* L_4 = V_6;
					V_8 = ((RuntimeObject*)IsInst((RuntimeObject*)L_4, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var));
					RuntimeObject* L_5 = V_8;
					if (!L_5)
					{
						goto IL_0069;
					}
				}
				{
					RuntimeObject* L_6 = V_8;
					NullCheck(L_6);
					InterfaceActionInvoker0::Invoke(0 /* System.Void System.IDisposable::Dispose() */, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_6);
				}

IL_0069:
				{
					return;
				}
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			{
				goto IL_004a_1;
			}

IL_0026_1:
			{
				RuntimeObject* L_7 = V_6;
				NullCheck(L_7);
				RuntimeObject* L_8;
				L_8 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(1 /* System.Object System.Collections.IEnumerator::get_Current() */, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_7);
				NullCheck(((ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F*)CastclassClass((RuntimeObject*)L_8, ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F_il2cpp_TypeInfo_var)));
				ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9;
				L_9 = VirtualFuncInvoker0< ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* >::Invoke(4 /* System.Byte[] Mono.Security.ASN1::GetBytes() */, ((ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F*)CastclassClass((RuntimeObject*)L_8, ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F_il2cpp_TypeInfo_var)));
				V_7 = L_9;
				ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* L_10 = V_4;
				ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_11 = V_7;
				NullCheck(L_10);
				int32_t L_12;
				L_12 = VirtualFuncInvoker1< int32_t, RuntimeObject* >::Invoke(29 /* System.Int32 System.Collections.ArrayList::Add(System.Object) */, L_10, (RuntimeObject*)L_11);
				int32_t L_13 = V_3;
				ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_14 = V_7;
				NullCheck(L_14);
				V_3 = ((int32_t)il2cpp_codegen_add(L_13, ((int32_t)(((RuntimeArray*)L_14)->max_length))));
			}

IL_004a_1:
			{
				RuntimeObject* L_15 = V_6;
				NullCheck(L_15);
				bool L_16;
				L_16 = InterfaceFuncInvoker0< bool >::Invoke(0 /* System.Boolean System.Collections.IEnumerator::MoveNext() */, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_15);
				if (L_16)
				{
					goto IL_0026_1;
				}
			}
			{
				goto IL_006a;
			}
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_006a:
	{
		int32_t L_17 = V_3;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_18 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)L_17);
		V_0 = L_18;
		V_5 = 0;
		V_9 = 0;
		goto IL_00a7;
	}

IL_0079:
	{
		ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* L_19 = V_4;
		int32_t L_20 = V_9;
		NullCheck(L_19);
		RuntimeObject* L_21;
		L_21 = VirtualFuncInvoker1< RuntimeObject*, int32_t >::Invoke(27 /* System.Object System.Collections.ArrayList::get_Item(System.Int32) */, L_19, L_20);
		V_10 = ((ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)Castclass((RuntimeObject*)L_21, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_22 = V_10;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_23 = V_0;
		int32_t L_24 = V_5;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_25 = V_10;
		NullCheck(L_25);
		Buffer_BlockCopy_m2F7BC0C5BA97C500E3F87D5008718F797E02B358((RuntimeArray*)L_22, 0, (RuntimeArray*)L_23, L_24, ((int32_t)(((RuntimeArray*)L_25)->max_length)), NULL);
		int32_t L_26 = V_5;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_27 = V_10;
		NullCheck(L_27);
		V_5 = ((int32_t)il2cpp_codegen_add(L_26, ((int32_t)(((RuntimeArray*)L_27)->max_length))));
		int32_t L_28 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_28, 1));
	}

IL_00a7:
	{
		int32_t L_29 = V_9;
		ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* L_30 = __this->___elist_2;
		NullCheck(L_30);
		int32_t L_31;
		L_31 = VirtualFuncInvoker0< int32_t >::Invoke(22 /* System.Int32 System.Collections.ArrayList::get_Count() */, L_30);
		if ((((int32_t)L_29) < ((int32_t)L_31)))
		{
			goto IL_0079;
		}
	}
	{
		goto IL_00c7;
	}

IL_00b8:
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_32 = __this->___m_aValue_1;
		if (!L_32)
		{
			goto IL_00c7;
		}
	}
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_33 = __this->___m_aValue_1;
		V_0 = L_33;
	}

IL_00c7:
	{
		V_2 = 0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_34 = V_0;
		if (!L_34)
		{
			goto IL_01e6;
		}
	}
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_35 = V_0;
		NullCheck(L_35);
		V_11 = ((int32_t)(((RuntimeArray*)L_35)->max_length));
		int32_t L_36 = V_11;
		if ((((int32_t)L_36) <= ((int32_t)((int32_t)127))))
		{
			goto IL_01bd;
		}
	}
	{
		int32_t L_37 = V_11;
		if ((((int32_t)L_37) > ((int32_t)((int32_t)255))))
		{
			goto IL_010c;
		}
	}
	{
		int32_t L_38 = V_11;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_39 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_add(3, L_38)));
		V_1 = L_39;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_40 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_41 = V_1;
		int32_t L_42 = V_11;
		Buffer_BlockCopy_m2F7BC0C5BA97C500E3F87D5008718F797E02B358((RuntimeArray*)L_40, 0, (RuntimeArray*)L_41, 3, L_42, NULL);
		V_2 = ((int32_t)129);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_43 = V_1;
		int32_t L_44 = V_11;
		NullCheck(L_43);
		(L_43)->SetAt(static_cast<il2cpp_array_size_t>(2), (uint8_t)((int32_t)(uint8_t)L_44));
		goto IL_01d5;
	}

IL_010c:
	{
		int32_t L_45 = V_11;
		if ((((int32_t)L_45) > ((int32_t)((int32_t)65535))))
		{
			goto IL_0143;
		}
	}
	{
		int32_t L_46 = V_11;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_47 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_add(4, L_46)));
		V_1 = L_47;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_48 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_49 = V_1;
		int32_t L_50 = V_11;
		Buffer_BlockCopy_m2F7BC0C5BA97C500E3F87D5008718F797E02B358((RuntimeArray*)L_48, 0, (RuntimeArray*)L_49, 4, L_50, NULL);
		V_2 = ((int32_t)130);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_51 = V_1;
		int32_t L_52 = V_11;
		NullCheck(L_51);
		(L_51)->SetAt(static_cast<il2cpp_array_size_t>(2), (uint8_t)((int32_t)(uint8_t)((int32_t)(L_52>>8))));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_53 = V_1;
		int32_t L_54 = V_11;
		NullCheck(L_53);
		(L_53)->SetAt(static_cast<il2cpp_array_size_t>(3), (uint8_t)((int32_t)(uint8_t)L_54));
		goto IL_01d5;
	}

IL_0143:
	{
		int32_t L_55 = V_11;
		if ((((int32_t)L_55) > ((int32_t)((int32_t)16777215))))
		{
			goto IL_0180;
		}
	}
	{
		int32_t L_56 = V_11;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_57 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_add(5, L_56)));
		V_1 = L_57;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_58 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_59 = V_1;
		int32_t L_60 = V_11;
		Buffer_BlockCopy_m2F7BC0C5BA97C500E3F87D5008718F797E02B358((RuntimeArray*)L_58, 0, (RuntimeArray*)L_59, 5, L_60, NULL);
		V_2 = ((int32_t)131);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_61 = V_1;
		int32_t L_62 = V_11;
		NullCheck(L_61);
		(L_61)->SetAt(static_cast<il2cpp_array_size_t>(2), (uint8_t)((int32_t)(uint8_t)((int32_t)(L_62>>((int32_t)16)))));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_63 = V_1;
		int32_t L_64 = V_11;
		NullCheck(L_63);
		(L_63)->SetAt(static_cast<il2cpp_array_size_t>(3), (uint8_t)((int32_t)(uint8_t)((int32_t)(L_64>>8))));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_65 = V_1;
		int32_t L_66 = V_11;
		NullCheck(L_65);
		(L_65)->SetAt(static_cast<il2cpp_array_size_t>(4), (uint8_t)((int32_t)(uint8_t)L_66));
		goto IL_01d5;
	}

IL_0180:
	{
		int32_t L_67 = V_11;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_68 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_add(6, L_67)));
		V_1 = L_68;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_69 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_70 = V_1;
		int32_t L_71 = V_11;
		Buffer_BlockCopy_m2F7BC0C5BA97C500E3F87D5008718F797E02B358((RuntimeArray*)L_69, 0, (RuntimeArray*)L_70, 6, L_71, NULL);
		V_2 = ((int32_t)132);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_72 = V_1;
		int32_t L_73 = V_11;
		NullCheck(L_72);
		(L_72)->SetAt(static_cast<il2cpp_array_size_t>(2), (uint8_t)((int32_t)(uint8_t)((int32_t)(L_73>>((int32_t)24)))));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_74 = V_1;
		int32_t L_75 = V_11;
		NullCheck(L_74);
		(L_74)->SetAt(static_cast<il2cpp_array_size_t>(3), (uint8_t)((int32_t)(uint8_t)((int32_t)(L_75>>((int32_t)16)))));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_76 = V_1;
		int32_t L_77 = V_11;
		NullCheck(L_76);
		(L_76)->SetAt(static_cast<il2cpp_array_size_t>(4), (uint8_t)((int32_t)(uint8_t)((int32_t)(L_77>>8))));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_78 = V_1;
		int32_t L_79 = V_11;
		NullCheck(L_78);
		(L_78)->SetAt(static_cast<il2cpp_array_size_t>(5), (uint8_t)((int32_t)(uint8_t)L_79));
		goto IL_01d5;
	}

IL_01bd:
	{
		int32_t L_80 = V_11;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_81 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_add(2, L_80)));
		V_1 = L_81;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_82 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_83 = V_1;
		int32_t L_84 = V_11;
		Buffer_BlockCopy_m2F7BC0C5BA97C500E3F87D5008718F797E02B358((RuntimeArray*)L_82, 0, (RuntimeArray*)L_83, 2, L_84, NULL);
		int32_t L_85 = V_11;
		V_2 = L_85;
	}

IL_01d5:
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_86 = __this->___m_aValue_1;
		if (L_86)
		{
			goto IL_01ed;
		}
	}
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_87 = V_0;
		__this->___m_aValue_1 = L_87;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_aValue_1), (void*)L_87);
		goto IL_01ed;
	}

IL_01e6:
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_88 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)2);
		V_1 = L_88;
	}

IL_01ed:
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_89 = V_1;
		uint8_t L_90 = __this->___m_nTag_0;
		NullCheck(L_89);
		(L_89)->SetAt(static_cast<il2cpp_array_size_t>(0), (uint8_t)L_90);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_91 = V_1;
		int32_t L_92 = V_2;
		NullCheck(L_91);
		(L_91)->SetAt(static_cast<il2cpp_array_size_t>(1), (uint8_t)((int32_t)(uint8_t)L_92));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_93 = V_1;
		return L_93;
	}
}
// System.Void Mono.Security.ASN1::Decode(System.Byte[],System.Int32&,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ASN1_Decode_mC4CF3CB2CC1DB454AA9C720BA79520956FB1F77B (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_asn1, int32_t* ___1_anPos, int32_t ___2_anLength, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	uint8_t V_0 = 0x0;
	int32_t V_1 = 0;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_2 = NULL;
	ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* V_3 = NULL;
	int32_t V_4 = 0;
	{
		goto IL_0040;
	}

IL_0002:
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___0_asn1;
		int32_t* L_1 = ___1_anPos;
		ASN1_DecodeTLV_mD4465394202DA7B0D37B9453CDE039233969E9DF(__this, L_0, L_1, (&V_0), (&V_1), (&V_2), NULL);
		uint8_t L_2 = V_0;
		if (!L_2)
		{
			goto IL_0040;
		}
	}
	{
		uint8_t L_3 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = V_2;
		ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* L_5 = (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F*)il2cpp_codegen_object_new(ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F_il2cpp_TypeInfo_var);
		NullCheck(L_5);
		ASN1__ctor_mAA538F9E1BE0DE739E9747BC3BC71DC030B018AA(L_5, L_3, L_4, NULL);
		ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* L_6;
		L_6 = ASN1_Add_m4C61487A6CCF48D5CEB0D97B248FE31F9FCD849F(__this, L_5, NULL);
		V_3 = L_6;
		uint8_t L_7 = V_0;
		if ((!(((uint32_t)((int32_t)((int32_t)L_7&((int32_t)32)))) == ((uint32_t)((int32_t)32)))))
		{
			goto IL_003a;
		}
	}
	{
		int32_t* L_8 = ___1_anPos;
		int32_t L_9 = *((int32_t*)L_8);
		V_4 = L_9;
		ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* L_10 = V_3;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_11 = ___0_asn1;
		int32_t L_12 = V_4;
		int32_t L_13 = V_1;
		NullCheck(L_10);
		ASN1_Decode_mC4CF3CB2CC1DB454AA9C720BA79520956FB1F77B(L_10, L_11, (&V_4), ((int32_t)il2cpp_codegen_add(L_12, L_13)), NULL);
	}

IL_003a:
	{
		int32_t* L_14 = ___1_anPos;
		int32_t* L_15 = ___1_anPos;
		int32_t L_16 = *((int32_t*)L_15);
		int32_t L_17 = V_1;
		*((int32_t*)L_14) = (int32_t)((int32_t)il2cpp_codegen_add(L_16, L_17));
	}

IL_0040:
	{
		int32_t* L_18 = ___1_anPos;
		int32_t L_19 = *((int32_t*)L_18);
		int32_t L_20 = ___2_anLength;
		if ((((int32_t)L_19) < ((int32_t)((int32_t)il2cpp_codegen_subtract(L_20, 1)))))
		{
			goto IL_0002;
		}
	}
	{
		return;
	}
}
// System.Void Mono.Security.ASN1::DecodeTLV(System.Byte[],System.Int32&,System.Byte&,System.Int32&,System.Byte[]&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ASN1_DecodeTLV_mD4465394202DA7B0D37B9453CDE039233969E9DF (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_asn1, int32_t* ___1_pos, uint8_t* ___2_tag, int32_t* ___3_length, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** ___4_content, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		uint8_t* L_0 = ___2_tag;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = ___0_asn1;
		int32_t* L_2 = ___1_pos;
		int32_t* L_3 = ___1_pos;
		int32_t L_4 = *((int32_t*)L_3);
		V_0 = L_4;
		int32_t L_5 = V_0;
		*((int32_t*)L_2) = (int32_t)((int32_t)il2cpp_codegen_add(L_5, 1));
		int32_t L_6 = V_0;
		NullCheck(L_1);
		int32_t L_7 = L_6;
		uint8_t L_8 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_7));
		*((int8_t*)L_0) = (int8_t)L_8;
		int32_t* L_9 = ___3_length;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_10 = ___0_asn1;
		int32_t* L_11 = ___1_pos;
		int32_t* L_12 = ___1_pos;
		int32_t L_13 = *((int32_t*)L_12);
		V_0 = L_13;
		int32_t L_14 = V_0;
		*((int32_t*)L_11) = (int32_t)((int32_t)il2cpp_codegen_add(L_14, 1));
		int32_t L_15 = V_0;
		NullCheck(L_10);
		int32_t L_16 = L_15;
		uint8_t L_17 = (L_10)->GetAt(static_cast<il2cpp_array_size_t>(L_16));
		*((int32_t*)L_9) = (int32_t)L_17;
		int32_t* L_18 = ___3_length;
		int32_t L_19 = *((int32_t*)L_18);
		if ((!(((uint32_t)((int32_t)(L_19&((int32_t)128)))) == ((uint32_t)((int32_t)128)))))
		{
			goto IL_005a;
		}
	}
	{
		int32_t* L_20 = ___3_length;
		int32_t L_21 = *((int32_t*)L_20);
		V_1 = ((int32_t)(L_21&((int32_t)127)));
		int32_t* L_22 = ___3_length;
		*((int32_t*)L_22) = (int32_t)0;
		V_2 = 0;
		goto IL_0056;
	}

IL_003a:
	{
		int32_t* L_23 = ___3_length;
		int32_t* L_24 = ___3_length;
		int32_t L_25 = *((int32_t*)L_24);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_26 = ___0_asn1;
		int32_t* L_27 = ___1_pos;
		int32_t* L_28 = ___1_pos;
		int32_t L_29 = *((int32_t*)L_28);
		V_0 = L_29;
		int32_t L_30 = V_0;
		*((int32_t*)L_27) = (int32_t)((int32_t)il2cpp_codegen_add(L_30, 1));
		int32_t L_31 = V_0;
		NullCheck(L_26);
		int32_t L_32 = L_31;
		uint8_t L_33 = (L_26)->GetAt(static_cast<il2cpp_array_size_t>(L_32));
		*((int32_t*)L_23) = (int32_t)((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(L_25, ((int32_t)256))), (int32_t)L_33));
		int32_t L_34 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_0056:
	{
		int32_t L_35 = V_2;
		int32_t L_36 = V_1;
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_003a;
		}
	}

IL_005a:
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** L_37 = ___4_content;
		int32_t* L_38 = ___3_length;
		int32_t L_39 = *((int32_t*)L_38);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_40 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)L_39);
		*((RuntimeObject**)L_37) = (RuntimeObject*)L_40;
		Il2CppCodeGenWriteBarrier((void**)(RuntimeObject**)L_37, (void*)(RuntimeObject*)L_40);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_41 = ___0_asn1;
		int32_t* L_42 = ___1_pos;
		int32_t L_43 = *((int32_t*)L_42);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** L_44 = ___4_content;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_45 = *((ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031**)L_44);
		int32_t* L_46 = ___3_length;
		int32_t L_47 = *((int32_t*)L_46);
		Buffer_BlockCopy_m2F7BC0C5BA97C500E3F87D5008718F797E02B358((RuntimeArray*)L_41, L_43, (RuntimeArray*)L_45, 0, L_47, NULL);
		return;
	}
}
// Mono.Security.ASN1 Mono.Security.ASN1::get_Item(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* ASN1_get_Item_mF105DA24F3BE9FA3697229CF99B1602B736B647F (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* V_0 = NULL;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	try
	{// begin try (depth: 1)
		{
			ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* L_0 = __this->___elist_2;
			if (!L_0)
			{
				goto IL_0016_1;
			}
		}
		{
			int32_t L_1 = ___0_index;
			ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* L_2 = __this->___elist_2;
			NullCheck(L_2);
			int32_t L_3;
			L_3 = VirtualFuncInvoker0< int32_t >::Invoke(22 /* System.Int32 System.Collections.ArrayList::get_Count() */, L_2);
			if ((((int32_t)L_1) < ((int32_t)L_3)))
			{
				goto IL_001a_1;
			}
		}

IL_0016_1:
		{
			V_0 = (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F*)NULL;
			goto IL_0033;
		}

IL_001a_1:
		{
			ArrayList_t7A8E5AF0C4378015B5731ABE2BED8F2782FEEF8A* L_4 = __this->___elist_2;
			int32_t L_5 = ___0_index;
			NullCheck(L_4);
			RuntimeObject* L_6;
			L_6 = VirtualFuncInvoker1< RuntimeObject*, int32_t >::Invoke(27 /* System.Object System.Collections.ArrayList::get_Item(System.Int32) */, L_4, L_5);
			V_0 = ((ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F*)CastclassClass((RuntimeObject*)L_6, ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F_il2cpp_TypeInfo_var));
			goto IL_0033;
		}
	}// end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_002e;
		}
		throw e;
	}

CATCH_002e:
	{// begin catch(System.ArgumentOutOfRangeException)
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_7 = ((ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)IL2CPP_GET_ACTIVE_EXCEPTION(ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*));;
		V_0 = (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F*)NULL;
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0033;
	}// end catch (depth: 1)

IL_0033:
	{
		ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* L_8 = V_0;
		return L_8;
	}
}
// System.String Mono.Security.ASN1::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* ASN1_ToString_m4995F083B02F8FEF578ECA6EE73A257821F50A00 (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Array_Empty_TisRuntimeObject_mFB8A63D602BB6974D31E20300D9EB89C6FE7C278_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral103949F0C75755294C4E46F97193DE6B9FC8DAD7);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1A9141C6D604CE4530FB3983D2DD3178E36CC069);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1B548BEAD44216247E991F18006F8DEA22021F68);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral949E308288B2FD68A8A495751C8D81446AE026E7);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB4A94E440E57B3321B2097CEC9E046D28EE1C0CD);
		s_Il2CppMethodInitialized = true;
	}
	StringBuilder_t* V_0 = NULL;
	int32_t V_1 = 0;
	{
		StringBuilder_t* L_0 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D(L_0, NULL);
		V_0 = L_0;
		StringBuilder_t* L_1 = V_0;
		uint8_t* L_2 = (uint8_t*)(&__this->___m_nTag_0);
		String_t* L_3;
		L_3 = Byte_ToString_m793A41EEEB7B422F6FE658E99D2F7683F59EE310(L_2, _stringLiteralB4A94E440E57B3321B2097CEC9E046D28EE1C0CD, NULL);
		String_t* L_4;
		L_4 = Environment_get_NewLine_m8BF68A4EFDAFFB66500984CE779629811BA98FFF(NULL);
		NullCheck(L_1);
		StringBuilder_t* L_5;
		L_5 = StringBuilder_AppendFormat_mAB076D92DC92723B2224D75987BE463AF1CE7132(L_1, _stringLiteral103949F0C75755294C4E46F97193DE6B9FC8DAD7, L_3, L_4, NULL);
		StringBuilder_t* L_6 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7;
		L_7 = ASN1_get_Value_mA6F9BE5AC19AC060AC42673C8FD5AA864EA046B6(__this, NULL);
		NullCheck(L_7);
		int32_t L_8 = ((int32_t)(((RuntimeArray*)L_7)->max_length));
		RuntimeObject* L_9 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_8);
		String_t* L_10;
		L_10 = Environment_get_NewLine_m8BF68A4EFDAFFB66500984CE779629811BA98FFF(NULL);
		NullCheck(L_6);
		StringBuilder_t* L_11;
		L_11 = StringBuilder_AppendFormat_mAB076D92DC92723B2224D75987BE463AF1CE7132(L_6, _stringLiteral1B548BEAD44216247E991F18006F8DEA22021F68, L_9, L_10, NULL);
		StringBuilder_t* L_12 = V_0;
		NullCheck(L_12);
		StringBuilder_t* L_13;
		L_13 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_12, _stringLiteral1A9141C6D604CE4530FB3983D2DD3178E36CC069, NULL);
		StringBuilder_t* L_14 = V_0;
		String_t* L_15;
		L_15 = Environment_get_NewLine_m8BF68A4EFDAFFB66500984CE779629811BA98FFF(NULL);
		NullCheck(L_14);
		StringBuilder_t* L_16;
		L_16 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_14, L_15, NULL);
		V_1 = 0;
		goto IL_00a0;
	}

IL_0061:
	{
		StringBuilder_t* L_17 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_18;
		L_18 = ASN1_get_Value_mA6F9BE5AC19AC060AC42673C8FD5AA864EA046B6(__this, NULL);
		int32_t L_19 = V_1;
		NullCheck(L_18);
		String_t* L_20;
		L_20 = Byte_ToString_m793A41EEEB7B422F6FE658E99D2F7683F59EE310(((L_18)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_19))), _stringLiteralB4A94E440E57B3321B2097CEC9E046D28EE1C0CD, NULL);
		NullCheck(L_17);
		StringBuilder_t* L_21;
		L_21 = StringBuilder_AppendFormat_mFA88863E4018C2912D1A783E0EA6DAE4F594124F(L_17, _stringLiteral949E308288B2FD68A8A495751C8D81446AE026E7, L_20, NULL);
		int32_t L_22 = V_1;
		if (((int32_t)(((int32_t)il2cpp_codegen_add(L_22, 1))%((int32_t)16))))
		{
			goto IL_009c;
		}
	}
	{
		StringBuilder_t* L_23 = V_0;
		String_t* L_24;
		L_24 = Environment_get_NewLine_m8BF68A4EFDAFFB66500984CE779629811BA98FFF(NULL);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_25;
		L_25 = Array_Empty_TisRuntimeObject_mFB8A63D602BB6974D31E20300D9EB89C6FE7C278_inline(Array_Empty_TisRuntimeObject_mFB8A63D602BB6974D31E20300D9EB89C6FE7C278_RuntimeMethod_var);
		NullCheck(L_23);
		StringBuilder_t* L_26;
		L_26 = StringBuilder_AppendFormat_m14CB447291E6149BCF32E5E37DA21514BAD9C151(L_23, L_24, L_25, NULL);
	}

IL_009c:
	{
		int32_t L_27 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_27, 1));
	}

IL_00a0:
	{
		int32_t L_28 = V_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_29;
		L_29 = ASN1_get_Value_mA6F9BE5AC19AC060AC42673C8FD5AA864EA046B6(__this, NULL);
		NullCheck(L_29);
		if ((((int32_t)L_28) < ((int32_t)((int32_t)(((RuntimeArray*)L_29)->max_length)))))
		{
			goto IL_0061;
		}
	}
	{
		StringBuilder_t* L_30 = V_0;
		NullCheck(L_30);
		String_t* L_31;
		L_31 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_30);
		return L_31;
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
// Mono.Security.ASN1 Mono.Security.ASN1Convert::FromInt32(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* ASN1Convert_FromInt32_mACAC096211E525F124BE0D50D90524ADCB6EA198 (int32_t ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Array_Reverse_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m4298AF0CA764FA936F9C5ED3606D1B4E2EC9EBA2_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_0 = NULL;
	int32_t V_1 = 0;
	ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* V_2 = NULL;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_3 = NULL;
	{
		int32_t L_0 = ___0_value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1;
		L_1 = BitConverterLE_GetBytes_mEEFE00015D501FBBD32225D9C45A2C2A0673E9C7(L_0, NULL);
		V_0 = L_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = V_0;
		Array_Reverse_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m4298AF0CA764FA936F9C5ED3606D1B4E2EC9EBA2(L_2, Array_Reverse_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m4298AF0CA764FA936F9C5ED3606D1B4E2EC9EBA2_RuntimeMethod_var);
		V_1 = 0;
		goto IL_0015;
	}

IL_0011:
	{
		int32_t L_3 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_3, 1));
	}

IL_0015:
	{
		int32_t L_4 = V_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = V_0;
		NullCheck(L_5);
		if ((((int32_t)L_4) >= ((int32_t)((int32_t)(((RuntimeArray*)L_5)->max_length)))))
		{
			goto IL_0020;
		}
	}
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_6 = V_0;
		int32_t L_7 = V_1;
		NullCheck(L_6);
		int32_t L_8 = L_7;
		uint8_t L_9 = (L_6)->GetAt(static_cast<il2cpp_array_size_t>(L_8));
		if (!L_9)
		{
			goto IL_0011;
		}
	}

IL_0020:
	{
		ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* L_10 = (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F*)il2cpp_codegen_object_new(ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F_il2cpp_TypeInfo_var);
		NullCheck(L_10);
		ASN1__ctor_mA9AE2197367C1E13DBFDA67E0A383167F52CC114(L_10, (uint8_t)2, NULL);
		V_2 = L_10;
		int32_t L_11 = V_1;
		if (!L_11)
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_12 = V_1;
		if ((((int32_t)L_12) == ((int32_t)4)))
		{
			goto IL_0039;
		}
	}
	{
		goto IL_0047;
	}

IL_0030:
	{
		ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* L_13 = V_2;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_14 = V_0;
		NullCheck(L_13);
		ASN1_set_Value_mAFFA885810928715B379EAD478AA3961E8ACD589(L_13, L_14, NULL);
		goto IL_0063;
	}

IL_0039:
	{
		ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* L_15 = V_2;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_16 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)1);
		NullCheck(L_15);
		ASN1_set_Value_mAFFA885810928715B379EAD478AA3961E8ACD589(L_15, L_16, NULL);
		goto IL_0063;
	}

IL_0047:
	{
		int32_t L_17 = V_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_18 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_subtract(4, L_17)));
		V_3 = L_18;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_19 = V_0;
		int32_t L_20 = V_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_21 = V_3;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_22 = V_3;
		NullCheck(L_22);
		Buffer_BlockCopy_m2F7BC0C5BA97C500E3F87D5008718F797E02B358((RuntimeArray*)L_19, L_20, (RuntimeArray*)L_21, 0, ((int32_t)(((RuntimeArray*)L_22)->max_length)), NULL);
		ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* L_23 = V_2;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_24 = V_3;
		NullCheck(L_23);
		ASN1_set_Value_mAFFA885810928715B379EAD478AA3961E8ACD589(L_23, L_24, NULL);
	}

IL_0063:
	{
		ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* L_25 = V_2;
		return L_25;
	}
}
// System.Int32 Mono.Security.ASN1Convert::ToInt32(Mono.Security.ASN1)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ASN1Convert_ToInt32_m956785EB4A235575C21677C16D2F6CBE54787032 (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* ___0_asn1, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* L_0 = ___0_asn1;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		NullCheck(L_1);
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral64EF02A69B970330DD01FA1A603CAE5EFC04FB89)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ASN1Convert_ToInt32_m956785EB4A235575C21677C16D2F6CBE54787032_RuntimeMethod_var)));
	}

IL_000e:
	{
		ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* L_2 = ___0_asn1;
		NullCheck(L_2);
		uint8_t L_3;
		L_3 = ASN1_get_Tag_m1984CF0DDF54424E61BA3650D93CBA0DCB58F232_inline(L_2, NULL);
		if ((((int32_t)L_3) == ((int32_t)2)))
		{
			goto IL_0022;
		}
	}
	{
		FormatException_tCD210E92627903FFEDAAA706C08FB6222B4D012B* L_4 = (FormatException_tCD210E92627903FFEDAAA706C08FB6222B4D012B*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&FormatException_tCD210E92627903FFEDAAA706C08FB6222B4D012B_il2cpp_TypeInfo_var)));
		NullCheck(L_4);
		FormatException__ctor_mE04AEA59C0EEFF4BD34B7CE8601F9D331D1D473E(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral07C3F7BAA7B4AB0D6D2DA7749FA8ACA206FD73F8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ASN1Convert_ToInt32_m956785EB4A235575C21677C16D2F6CBE54787032_RuntimeMethod_var)));
	}

IL_0022:
	{
		V_0 = 0;
		V_1 = 0;
		goto IL_0039;
	}

IL_0028:
	{
		int32_t L_5 = V_0;
		ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* L_6 = ___0_asn1;
		NullCheck(L_6);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7;
		L_7 = ASN1_get_Value_mA6F9BE5AC19AC060AC42673C8FD5AA864EA046B6(L_6, NULL);
		int32_t L_8 = V_1;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		uint8_t L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		V_0 = ((int32_t)il2cpp_codegen_add(((int32_t)(L_5<<8)), (int32_t)L_10));
		int32_t L_11 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_0039:
	{
		int32_t L_12 = V_1;
		ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* L_13 = ___0_asn1;
		NullCheck(L_13);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_14;
		L_14 = ASN1_get_Value_mA6F9BE5AC19AC060AC42673C8FD5AA864EA046B6(L_13, NULL);
		NullCheck(L_14);
		if ((((int32_t)L_12) < ((int32_t)((int32_t)(((RuntimeArray*)L_14)->max_length)))))
		{
			goto IL_0028;
		}
	}
	{
		int32_t L_15 = V_0;
		return L_15;
	}
}
// System.String Mono.Security.ASN1Convert::ToOid(Mono.Security.ASN1)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* ASN1Convert_ToOid_mBCE4FD3970C556190FB00A6AD409A6ABB4C627D8 (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* ___0_asn1, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF3E84B722399601AD7E281754E917478AA9AD48D);
		s_Il2CppMethodInitialized = true;
	}
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_0 = NULL;
	StringBuilder_t* V_1 = NULL;
	uint8_t V_2 = 0x0;
	uint8_t V_3 = 0x0;
	uint64_t V_4 = 0;
	{
		ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* L_0 = ___0_asn1;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		NullCheck(L_1);
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral64EF02A69B970330DD01FA1A603CAE5EFC04FB89)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ASN1Convert_ToOid_mBCE4FD3970C556190FB00A6AD409A6ABB4C627D8_RuntimeMethod_var)));
	}

IL_000e:
	{
		ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* L_2 = ___0_asn1;
		NullCheck(L_2);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3;
		L_3 = ASN1_get_Value_mA6F9BE5AC19AC060AC42673C8FD5AA864EA046B6(L_2, NULL);
		V_0 = L_3;
		StringBuilder_t* L_4 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		NullCheck(L_4);
		StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D(L_4, NULL);
		V_1 = L_4;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = V_0;
		NullCheck(L_5);
		int32_t L_6 = 0;
		uint8_t L_7 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_6));
		V_2 = (uint8_t)((int32_t)(uint8_t)((int32_t)((int32_t)L_7/((int32_t)40))));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_8 = V_0;
		NullCheck(L_8);
		int32_t L_9 = 0;
		uint8_t L_10 = (L_8)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		V_3 = (uint8_t)((int32_t)(uint8_t)((int32_t)((int32_t)L_10%((int32_t)40))));
		uint8_t L_11 = V_2;
		if ((((int32_t)L_11) <= ((int32_t)2)))
		{
			goto IL_003c;
		}
	}
	{
		uint8_t L_12 = V_3;
		uint8_t L_13 = V_2;
		V_3 = (uint8_t)((int32_t)(uint8_t)((int32_t)il2cpp_codegen_add((int32_t)L_12, ((int32_t)(uint8_t)((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_subtract((int32_t)L_13, 2)), ((int32_t)40)))))));
		V_2 = (uint8_t)2;
	}

IL_003c:
	{
		StringBuilder_t* L_14 = V_1;
		il2cpp_codegen_runtime_class_init_inline(CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_il2cpp_TypeInfo_var);
		CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* L_15;
		L_15 = CultureInfo_get_InvariantCulture_mD1E96DC845E34B10F78CB744B0CB5D7D63CEB1E6(NULL);
		String_t* L_16;
		L_16 = Byte_ToString_m3F9787FE9A306FE63F388635DEE2733F91588A86((&V_2), L_15, NULL);
		NullCheck(L_14);
		StringBuilder_t* L_17;
		L_17 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_14, L_16, NULL);
		StringBuilder_t* L_18 = V_1;
		NullCheck(L_18);
		StringBuilder_t* L_19;
		L_19 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_18, _stringLiteralF3E84B722399601AD7E281754E917478AA9AD48D, NULL);
		StringBuilder_t* L_20 = V_1;
		CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* L_21;
		L_21 = CultureInfo_get_InvariantCulture_mD1E96DC845E34B10F78CB744B0CB5D7D63CEB1E6(NULL);
		String_t* L_22;
		L_22 = Byte_ToString_m3F9787FE9A306FE63F388635DEE2733F91588A86((&V_3), L_21, NULL);
		NullCheck(L_20);
		StringBuilder_t* L_23;
		L_23 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_20, L_22, NULL);
		V_4 = ((int64_t)0);
		V_2 = (uint8_t)1;
		goto IL_00bd;
	}

IL_0076:
	{
		uint64_t L_24 = V_4;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_25 = V_0;
		uint8_t L_26 = V_2;
		NullCheck(L_25);
		uint8_t L_27 = L_26;
		uint8_t L_28 = (L_25)->GetAt(static_cast<il2cpp_array_size_t>(L_27));
		V_4 = ((int64_t)(((int64_t)((int64_t)L_24<<7))|((int64_t)(uint64_t)((uint32_t)((int32_t)(uint8_t)((int32_t)((int32_t)L_28&((int32_t)127))))))));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_29 = V_0;
		uint8_t L_30 = V_2;
		NullCheck(L_29);
		uint8_t L_31 = L_30;
		uint8_t L_32 = (L_29)->GetAt(static_cast<il2cpp_array_size_t>(L_31));
		if ((((int32_t)((int32_t)((int32_t)L_32&((int32_t)128)))) == ((int32_t)((int32_t)128))))
		{
			goto IL_00b8;
		}
	}
	{
		StringBuilder_t* L_33 = V_1;
		NullCheck(L_33);
		StringBuilder_t* L_34;
		L_34 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_33, _stringLiteralF3E84B722399601AD7E281754E917478AA9AD48D, NULL);
		StringBuilder_t* L_35 = V_1;
		il2cpp_codegen_runtime_class_init_inline(CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_il2cpp_TypeInfo_var);
		CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* L_36;
		L_36 = CultureInfo_get_InvariantCulture_mD1E96DC845E34B10F78CB744B0CB5D7D63CEB1E6(NULL);
		String_t* L_37;
		L_37 = UInt64_ToString_mCDDACF05D6B5B3ECB10B1FEEE58ED3407973E7A7((&V_4), L_36, NULL);
		NullCheck(L_35);
		StringBuilder_t* L_38;
		L_38 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_35, L_37, NULL);
		V_4 = ((int64_t)0);
	}

IL_00b8:
	{
		uint8_t L_39 = V_2;
		V_2 = (uint8_t)((int32_t)(uint8_t)((int32_t)il2cpp_codegen_add((int32_t)L_39, 1)));
	}

IL_00bd:
	{
		uint8_t L_40 = V_2;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_41 = V_0;
		NullCheck(L_41);
		if ((((int32_t)L_40) < ((int32_t)((int32_t)(((RuntimeArray*)L_41)->max_length)))))
		{
			goto IL_0076;
		}
	}
	{
		StringBuilder_t* L_42 = V_1;
		NullCheck(L_42);
		String_t* L_43;
		L_43 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_42);
		return L_43;
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
// System.Byte[] Mono.Security.BitConverterLE::GetUIntBytes(System.Byte*)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* BitConverterLE_GetUIntBytes_mED0A55F565721091E851FD6108E128C3CBCB87F0 (uint8_t* ___0_bytes, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BitConverter_t6E99605185963BC12B3D369E13F2B88997E64A27_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		il2cpp_codegen_runtime_class_init_inline(BitConverter_t6E99605185963BC12B3D369E13F2B88997E64A27_il2cpp_TypeInfo_var);
		bool L_0 = ((BitConverter_t6E99605185963BC12B3D369E13F2B88997E64A27_StaticFields*)il2cpp_codegen_static_fields_for(BitConverter_t6E99605185963BC12B3D369E13F2B88997E64A27_il2cpp_TypeInfo_var))->___IsLittleEndian_0;
		if (!L_0)
		{
			goto IL_0028;
		}
	}
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)4);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = L_1;
		uint8_t* L_3 = ___0_bytes;
		int32_t L_4 = (*(L_3));
		NullCheck(L_2);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(0), (uint8_t)L_4);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = L_2;
		uint8_t* L_6 = ___0_bytes;
		int32_t L_7 = (*(((uint8_t*)il2cpp_codegen_add((intptr_t)L_6, 1))));
		NullCheck(L_5);
		(L_5)->SetAt(static_cast<il2cpp_array_size_t>(1), (uint8_t)L_7);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_8 = L_5;
		uint8_t* L_9 = ___0_bytes;
		int32_t L_10 = (*(((uint8_t*)il2cpp_codegen_add((intptr_t)L_9, 2))));
		NullCheck(L_8);
		(L_8)->SetAt(static_cast<il2cpp_array_size_t>(2), (uint8_t)L_10);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_11 = L_8;
		uint8_t* L_12 = ___0_bytes;
		int32_t L_13 = (*(((uint8_t*)il2cpp_codegen_add((intptr_t)L_12, 3))));
		NullCheck(L_11);
		(L_11)->SetAt(static_cast<il2cpp_array_size_t>(3), (uint8_t)L_13);
		return L_11;
	}

IL_0028:
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_14 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)4);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_15 = L_14;
		uint8_t* L_16 = ___0_bytes;
		int32_t L_17 = (*(((uint8_t*)il2cpp_codegen_add((intptr_t)L_16, 3))));
		NullCheck(L_15);
		(L_15)->SetAt(static_cast<il2cpp_array_size_t>(0), (uint8_t)L_17);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_18 = L_15;
		uint8_t* L_19 = ___0_bytes;
		int32_t L_20 = (*(((uint8_t*)il2cpp_codegen_add((intptr_t)L_19, 2))));
		NullCheck(L_18);
		(L_18)->SetAt(static_cast<il2cpp_array_size_t>(1), (uint8_t)L_20);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_21 = L_18;
		uint8_t* L_22 = ___0_bytes;
		int32_t L_23 = (*(((uint8_t*)il2cpp_codegen_add((intptr_t)L_22, 1))));
		NullCheck(L_21);
		(L_21)->SetAt(static_cast<il2cpp_array_size_t>(2), (uint8_t)L_23);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_24 = L_21;
		uint8_t* L_25 = ___0_bytes;
		int32_t L_26 = (*(L_25));
		NullCheck(L_24);
		(L_24)->SetAt(static_cast<il2cpp_array_size_t>(3), (uint8_t)L_26);
		return L_24;
	}
}
// System.Byte[] Mono.Security.BitConverterLE::GetBytes(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* BitConverterLE_GetBytes_mEEFE00015D501FBBD32225D9C45A2C2A0673E9C7 (int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0;
		L_0 = BitConverterLE_GetUIntBytes_mED0A55F565721091E851FD6108E128C3CBCB87F0((uint8_t*)((uintptr_t)(&___0_value)), NULL);
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
// System.String Mono.Security.Cryptography.CryptoConvert::ToHex(System.Byte[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CryptoConvert_ToHex_m1A0AD4D32CEEC47D3C60CB2E4D05A935C62F261A (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_input, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB4A94E440E57B3321B2097CEC9E046D28EE1C0CD);
		s_Il2CppMethodInitialized = true;
	}
	StringBuilder_t* V_0 = NULL;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_1 = NULL;
	int32_t V_2 = 0;
	uint8_t V_3 = 0x0;
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___0_input;
		if (L_0)
		{
			goto IL_0005;
		}
	}
	{
		return (String_t*)NULL;
	}

IL_0005:
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = ___0_input;
		NullCheck(L_1);
		StringBuilder_t* L_2 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		StringBuilder__ctor_m2619CA8D2C3476DF1A302D9D941498BB1C6164C5(L_2, ((int32_t)il2cpp_codegen_multiply(((int32_t)(((RuntimeArray*)L_1)->max_length)), 2)), NULL);
		V_0 = L_2;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = ___0_input;
		V_1 = L_3;
		V_2 = 0;
		goto IL_0036;
	}

IL_0016:
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = V_1;
		int32_t L_5 = V_2;
		NullCheck(L_4);
		int32_t L_6 = L_5;
		uint8_t L_7 = (L_4)->GetAt(static_cast<il2cpp_array_size_t>(L_6));
		V_3 = L_7;
		StringBuilder_t* L_8 = V_0;
		il2cpp_codegen_runtime_class_init_inline(CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_il2cpp_TypeInfo_var);
		CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* L_9;
		L_9 = CultureInfo_get_InvariantCulture_mD1E96DC845E34B10F78CB744B0CB5D7D63CEB1E6(NULL);
		String_t* L_10;
		L_10 = Byte_ToString_m64EE358F20093EE61D30F9A21638D9E9EE8F87EC((&V_3), _stringLiteralB4A94E440E57B3321B2097CEC9E046D28EE1C0CD, L_9, NULL);
		NullCheck(L_8);
		StringBuilder_t* L_11;
		L_11 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_8, L_10, NULL);
		int32_t L_12 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_12, 1));
	}

IL_0036:
	{
		int32_t L_13 = V_2;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_14 = V_1;
		NullCheck(L_14);
		if ((((int32_t)L_13) < ((int32_t)((int32_t)(((RuntimeArray*)L_14)->max_length)))))
		{
			goto IL_0016;
		}
	}
	{
		StringBuilder_t* L_15 = V_0;
		NullCheck(L_15);
		String_t* L_16;
		L_16 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_15);
		return L_16;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint8_t ASN1_get_Tag_m1984CF0DDF54424E61BA3650D93CBA0DCB58F232_inline (ASN1_t33549D58797C9C33AA83F13AD184EAA00C584A6F* __this, const RuntimeMethod* method) 
{
	{
		uint8_t L_0 = __this->___m_nTag_0;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* Array_Empty_TisRuntimeObject_mFB8A63D602BB6974D31E20300D9EB89C6FE7C278_gshared_inline (const RuntimeMethod* method) 
{
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 0));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_0 = ((EmptyArray_1_tDF0DD7256B115243AA6BD5558417387A734240EE_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 0)))->___Value_0;
		return L_0;
	}
}
