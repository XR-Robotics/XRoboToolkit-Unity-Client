#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>


template <typename R, typename T1>
struct GenericVirtualFuncInvoker1
{
	typedef R (*Func)(void*, T1, const RuntimeMethod*);

	static inline R Invoke (const RuntimeMethod* method, RuntimeObject* obj, T1 p1)
	{
		VirtualInvokeData invokeData;
		il2cpp_codegen_get_generic_virtual_invoke_data(method, obj, &invokeData);
		return ((Func)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};

// Microsoft.Extensions.ObjectPool.ObjectPool`1<System.Text.StringBuilder>
struct ObjectPool_1_tE2419CB2E37566A480FEF1F372068053FC6344D0;
// Microsoft.Extensions.ObjectPool.PooledObjectPolicy`1<System.Object>
struct PooledObjectPolicy_1_t08FF1FB86398BB6C079558E1FBE4F475CC8EB6FE;
// Microsoft.Extensions.ObjectPool.PooledObjectPolicy`1<System.Text.StringBuilder>
struct PooledObjectPolicy_1_tF4889DD6BD081E6F17CB12BC4C23F05A81F4EA02;
// System.Byte[]
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
// System.Char[]
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
// System.Attribute
struct Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA;
// Microsoft.Extensions.ObjectPool.DefaultObjectPoolProvider
struct DefaultObjectPoolProvider_tBA9557146A9C6168E4C7B583AAA06CEC93163E2A;
// Microsoft.CodeAnalysis.EmbeddedAttribute
struct EmbeddedAttribute_tFFF2B991B9DD7AAC90EC30A3749DDE0EFB5EC640;
// System.Runtime.CompilerServices.NullableAttribute
struct NullableAttribute_t3DA9E078D4BB40B76FA2EA8B347C3A5BD3705859;
// System.Runtime.CompilerServices.NullableContextAttribute
struct NullableContextAttribute_t3CA5B726BA396088739D8EBA29DC4F875995ACEA;
// System.Runtime.CompilerServices.NullablePublicOnlyAttribute
struct NullablePublicOnlyAttribute_t0973AB3D46BA7CE014EE22D4AE65EA9C61385464;
// Microsoft.Extensions.ObjectPool.ObjectPoolProvider
struct ObjectPoolProvider_tB9D58A9FCC10DF2C31E97B9D3CBEC974B4389DE3;
// System.String
struct String_t;
// System.Text.StringBuilder
struct StringBuilder_t;
// Microsoft.Extensions.ObjectPool.StringBuilderPooledObjectPolicy
struct StringBuilderPooledObjectPolicy_tE85FA1EA59E1B0C71D33476A5B9745D650EAEF76;

IL2CPP_EXTERN_C RuntimeClass* ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringBuilderPooledObjectPolicy_tE85FA1EA59E1B0C71D33476A5B9745D650EAEF76_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringBuilder_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C const RuntimeMethod* ObjectPoolProvider_Create_TisStringBuilder_t_m56956E8152B61E9BEDBB51892B141571E7249141_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* PooledObjectPolicy_1__ctor_m6E8F35EEBA1E2B0D3C3FED4EC63F82557FC1D145_RuntimeMethod_var;

struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// <Module>
struct U3CModuleU3E_t38620D21F414F3EBE67A07D1E40C6906CE5CDEA4 
{
};

// Microsoft.Extensions.ObjectPool.ObjectPool`1<System.Text.StringBuilder>
struct ObjectPool_1_tE2419CB2E37566A480FEF1F372068053FC6344D0  : public RuntimeObject
{
};

// Microsoft.Extensions.ObjectPool.PooledObjectPolicy`1<System.Text.StringBuilder>
struct PooledObjectPolicy_1_tF4889DD6BD081E6F17CB12BC4C23F05A81F4EA02  : public RuntimeObject
{
};

// System.Attribute
struct Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA  : public RuntimeObject
{
};

// Microsoft.Extensions.ObjectPool.ObjectPoolProvider
struct ObjectPoolProvider_tB9D58A9FCC10DF2C31E97B9D3CBEC974B4389DE3  : public RuntimeObject
{
};

// Microsoft.Extensions.ObjectPool.ObjectPoolProviderExtensions
struct ObjectPoolProviderExtensions_t94E20A2F9F0755AEC85B44272EE22EA93255C835  : public RuntimeObject
{
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

// Microsoft.Extensions.ObjectPool.DefaultObjectPoolProvider
struct DefaultObjectPoolProvider_tBA9557146A9C6168E4C7B583AAA06CEC93163E2A  : public ObjectPoolProvider_tB9D58A9FCC10DF2C31E97B9D3CBEC974B4389DE3
{
	// System.Int32 Microsoft.Extensions.ObjectPool.DefaultObjectPoolProvider::<MaximumRetained>k__BackingField
	int32_t ___U3CMaximumRetainedU3Ek__BackingField_0;
};

// Microsoft.CodeAnalysis.EmbeddedAttribute
struct EmbeddedAttribute_tFFF2B991B9DD7AAC90EC30A3749DDE0EFB5EC640  : public Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA
{
};

// System.Int32
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	// System.Int32 System.Int32::m_value
	int32_t ___m_value_0;
};

// System.Runtime.CompilerServices.NullableAttribute
struct NullableAttribute_t3DA9E078D4BB40B76FA2EA8B347C3A5BD3705859  : public Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA
{
	// System.Byte[] System.Runtime.CompilerServices.NullableAttribute::NullableFlags
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___NullableFlags_0;
};

// System.Runtime.CompilerServices.NullableContextAttribute
struct NullableContextAttribute_t3CA5B726BA396088739D8EBA29DC4F875995ACEA  : public Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA
{
	// System.Byte System.Runtime.CompilerServices.NullableContextAttribute::Flag
	uint8_t ___Flag_0;
};

// System.Runtime.CompilerServices.NullablePublicOnlyAttribute
struct NullablePublicOnlyAttribute_t0973AB3D46BA7CE014EE22D4AE65EA9C61385464  : public Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA
{
	// System.Boolean System.Runtime.CompilerServices.NullablePublicOnlyAttribute::IncludesInternals
	bool ___IncludesInternals_0;
};

// Microsoft.Extensions.ObjectPool.StringBuilderPooledObjectPolicy
struct StringBuilderPooledObjectPolicy_tE85FA1EA59E1B0C71D33476A5B9745D650EAEF76  : public PooledObjectPolicy_1_tF4889DD6BD081E6F17CB12BC4C23F05A81F4EA02
{
	// System.Int32 Microsoft.Extensions.ObjectPool.StringBuilderPooledObjectPolicy::<InitialCapacity>k__BackingField
	int32_t ___U3CInitialCapacityU3Ek__BackingField_0;
	// System.Int32 Microsoft.Extensions.ObjectPool.StringBuilderPooledObjectPolicy::<MaximumRetainedCapacity>k__BackingField
	int32_t ___U3CMaximumRetainedCapacityU3Ek__BackingField_1;
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

// <Module>

// <Module>

// Microsoft.Extensions.ObjectPool.ObjectPool`1<System.Text.StringBuilder>

// Microsoft.Extensions.ObjectPool.ObjectPool`1<System.Text.StringBuilder>

// Microsoft.Extensions.ObjectPool.PooledObjectPolicy`1<System.Text.StringBuilder>

// Microsoft.Extensions.ObjectPool.PooledObjectPolicy`1<System.Text.StringBuilder>

// System.Attribute

// System.Attribute

// Microsoft.Extensions.ObjectPool.ObjectPoolProvider

// Microsoft.Extensions.ObjectPool.ObjectPoolProvider

// Microsoft.Extensions.ObjectPool.ObjectPoolProviderExtensions

// Microsoft.Extensions.ObjectPool.ObjectPoolProviderExtensions

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

// Microsoft.Extensions.ObjectPool.DefaultObjectPoolProvider

// Microsoft.Extensions.ObjectPool.DefaultObjectPoolProvider

// Microsoft.CodeAnalysis.EmbeddedAttribute

// Microsoft.CodeAnalysis.EmbeddedAttribute

// System.Int32

// System.Int32

// System.Runtime.CompilerServices.NullableAttribute

// System.Runtime.CompilerServices.NullableAttribute

// System.Runtime.CompilerServices.NullableContextAttribute

// System.Runtime.CompilerServices.NullableContextAttribute

// System.Runtime.CompilerServices.NullablePublicOnlyAttribute

// System.Runtime.CompilerServices.NullablePublicOnlyAttribute

// Microsoft.Extensions.ObjectPool.StringBuilderPooledObjectPolicy

// Microsoft.Extensions.ObjectPool.StringBuilderPooledObjectPolicy

// System.Void

// System.Void
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


// System.Void Microsoft.Extensions.ObjectPool.PooledObjectPolicy`1<System.Object>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PooledObjectPolicy_1__ctor_m4A60681F23CE0A159C9BA3FD2453CBD2E8500870_gshared (PooledObjectPolicy_1_t08FF1FB86398BB6C079558E1FBE4F475CC8EB6FE* __this, const RuntimeMethod* method) ;

// System.Void System.Attribute::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Attribute__ctor_m79ED1BF1EE36D1E417BA89A0D9F91F8AAD8D19E2 (Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA* __this, const RuntimeMethod* method) ;
// System.Int32 System.Environment::get_ProcessorCount()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Environment_get_ProcessorCount_mDAC34132B9E3B90121F37673DF78F13FCB9497AC (const RuntimeMethod* method) ;
// System.Void Microsoft.Extensions.ObjectPool.ObjectPoolProvider::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ObjectPoolProvider__ctor_mCD6D7E6B43F46DE03EB950919F335CC43E6EEE5B (ObjectPoolProvider_tB9D58A9FCC10DF2C31E97B9D3CBEC974B4389DE3* __this, const RuntimeMethod* method) ;
// System.Void System.Object::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
// System.Void Microsoft.Extensions.ObjectPool.StringBuilderPooledObjectPolicy::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StringBuilderPooledObjectPolicy__ctor_mBBC7CC5B947E04095F42BE1F231D7DEE6C3F7B49 (StringBuilderPooledObjectPolicy_tE85FA1EA59E1B0C71D33476A5B9745D650EAEF76* __this, const RuntimeMethod* method) ;
// System.Int32 Microsoft.Extensions.ObjectPool.StringBuilderPooledObjectPolicy::get_InitialCapacity()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t StringBuilderPooledObjectPolicy_get_InitialCapacity_m91788A73651B9B3D69C5054C5141A214BA98C225_inline (StringBuilderPooledObjectPolicy_tE85FA1EA59E1B0C71D33476A5B9745D650EAEF76* __this, const RuntimeMethod* method) ;
// System.Void System.Text.StringBuilder::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StringBuilder__ctor_m2619CA8D2C3476DF1A302D9D941498BB1C6164C5 (StringBuilder_t* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
// System.Int32 System.Text.StringBuilder::get_Capacity()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t StringBuilder_get_Capacity_m9DBF3B3940BC0BB882CA26F0EDB53896A491AD1E (StringBuilder_t* __this, const RuntimeMethod* method) ;
// System.Int32 Microsoft.Extensions.ObjectPool.StringBuilderPooledObjectPolicy::get_MaximumRetainedCapacity()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t StringBuilderPooledObjectPolicy_get_MaximumRetainedCapacity_m5983D97FDD9D1826755BCC8227C244985996DEE8_inline (StringBuilderPooledObjectPolicy_tE85FA1EA59E1B0C71D33476A5B9745D650EAEF76* __this, const RuntimeMethod* method) ;
// System.Text.StringBuilder System.Text.StringBuilder::Clear()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_Clear_m2D76F6533574F40A4E3E2DC4E730277CBD0AF8F6 (StringBuilder_t* __this, const RuntimeMethod* method) ;
// System.Void Microsoft.Extensions.ObjectPool.PooledObjectPolicy`1<System.Text.StringBuilder>::.ctor()
inline void PooledObjectPolicy_1__ctor_m6E8F35EEBA1E2B0D3C3FED4EC63F82557FC1D145 (PooledObjectPolicy_1_tF4889DD6BD081E6F17CB12BC4C23F05A81F4EA02* __this, const RuntimeMethod* method)
{
	((  void (*) (PooledObjectPolicy_1_tF4889DD6BD081E6F17CB12BC4C23F05A81F4EA02*, const RuntimeMethod*))PooledObjectPolicy_1__ctor_m4A60681F23CE0A159C9BA3FD2453CBD2E8500870_gshared)(__this, method);
}
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
// System.Void Microsoft.CodeAnalysis.EmbeddedAttribute::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EmbeddedAttribute__ctor_mFDA378FD9C7FFAC246FE06DCEC4D495EB025BBF9 (EmbeddedAttribute_tFFF2B991B9DD7AAC90EC30A3749DDE0EFB5EC640* __this, const RuntimeMethod* method) 
{
	{
		Attribute__ctor_m79ED1BF1EE36D1E417BA89A0D9F91F8AAD8D19E2(__this, NULL);
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
// System.Void System.Runtime.CompilerServices.NullableAttribute::.ctor(System.Byte)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NullableAttribute__ctor_m681414C05E932C0634AA5BB0FFA96695D7714726 (NullableAttribute_t3DA9E078D4BB40B76FA2EA8B347C3A5BD3705859* __this, uint8_t ___0_p, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		Attribute__ctor_m79ED1BF1EE36D1E417BA89A0D9F91F8AAD8D19E2(__this, NULL);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)1);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = L_0;
		uint8_t L_2 = ___0_p;
		NullCheck(L_1);
		(L_1)->SetAt(static_cast<il2cpp_array_size_t>(0), (uint8_t)L_2);
		__this->___NullableFlags_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___NullableFlags_0), (void*)L_1);
		return;
	}
}
// System.Void System.Runtime.CompilerServices.NullableAttribute::.ctor(System.Byte[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NullableAttribute__ctor_mD5757017F2114E0EA2CA8899EB012BEFD89DF92E (NullableAttribute_t3DA9E078D4BB40B76FA2EA8B347C3A5BD3705859* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_p, const RuntimeMethod* method) 
{
	{
		Attribute__ctor_m79ED1BF1EE36D1E417BA89A0D9F91F8AAD8D19E2(__this, NULL);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___0_p;
		__this->___NullableFlags_0 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___NullableFlags_0), (void*)L_0);
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
// System.Void System.Runtime.CompilerServices.NullableContextAttribute::.ctor(System.Byte)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NullableContextAttribute__ctor_mDD3C2201B8DD772CA2AB742CD92CFE084C47E28D (NullableContextAttribute_t3CA5B726BA396088739D8EBA29DC4F875995ACEA* __this, uint8_t ___0_p, const RuntimeMethod* method) 
{
	{
		Attribute__ctor_m79ED1BF1EE36D1E417BA89A0D9F91F8AAD8D19E2(__this, NULL);
		uint8_t L_0 = ___0_p;
		__this->___Flag_0 = L_0;
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
// System.Void System.Runtime.CompilerServices.NullablePublicOnlyAttribute::.ctor(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NullablePublicOnlyAttribute__ctor_m43E873BC0EB12137E60FB4BC026B216677C25C4D (NullablePublicOnlyAttribute_t0973AB3D46BA7CE014EE22D4AE65EA9C61385464* __this, bool ___0_p, const RuntimeMethod* method) 
{
	{
		Attribute__ctor_m79ED1BF1EE36D1E417BA89A0D9F91F8AAD8D19E2(__this, NULL);
		bool L_0 = ___0_p;
		__this->___IncludesInternals_0 = L_0;
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
// System.Int32 Microsoft.Extensions.ObjectPool.DefaultObjectPoolProvider::get_MaximumRetained()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t DefaultObjectPoolProvider_get_MaximumRetained_mB34149D4F6E679A36C319C7899E327E830FD614C (DefaultObjectPoolProvider_tBA9557146A9C6168E4C7B583AAA06CEC93163E2A* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___U3CMaximumRetainedU3Ek__BackingField_0;
		return L_0;
	}
}
// System.Void Microsoft.Extensions.ObjectPool.DefaultObjectPoolProvider::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DefaultObjectPoolProvider__ctor_m5928B75C1292064285A7793AD81767D273C2A397 (DefaultObjectPoolProvider_tBA9557146A9C6168E4C7B583AAA06CEC93163E2A* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = Environment_get_ProcessorCount_mDAC34132B9E3B90121F37673DF78F13FCB9497AC(NULL);
		__this->___U3CMaximumRetainedU3Ek__BackingField_0 = ((int32_t)il2cpp_codegen_multiply(L_0, 2));
		ObjectPoolProvider__ctor_mCD6D7E6B43F46DE03EB950919F335CC43E6EEE5B(__this, NULL);
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
// System.Void Microsoft.Extensions.ObjectPool.ObjectPoolProvider::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ObjectPoolProvider__ctor_mCD6D7E6B43F46DE03EB950919F335CC43E6EEE5B (ObjectPoolProvider_tB9D58A9FCC10DF2C31E97B9D3CBEC974B4389DE3* __this, const RuntimeMethod* method) 
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
// Microsoft.Extensions.ObjectPool.ObjectPool`1<System.Text.StringBuilder> Microsoft.Extensions.ObjectPool.ObjectPoolProviderExtensions::CreateStringBuilderPool(Microsoft.Extensions.ObjectPool.ObjectPoolProvider)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ObjectPool_1_tE2419CB2E37566A480FEF1F372068053FC6344D0* ObjectPoolProviderExtensions_CreateStringBuilderPool_m0B3AB832F9DDAEF5F4779B4949C22C8F00D970EE (ObjectPoolProvider_tB9D58A9FCC10DF2C31E97B9D3CBEC974B4389DE3* ___0_provider, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectPoolProvider_Create_TisStringBuilder_t_m56956E8152B61E9BEDBB51892B141571E7249141_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilderPooledObjectPolicy_tE85FA1EA59E1B0C71D33476A5B9745D650EAEF76_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		ObjectPoolProvider_tB9D58A9FCC10DF2C31E97B9D3CBEC974B4389DE3* L_0 = ___0_provider;
		StringBuilderPooledObjectPolicy_tE85FA1EA59E1B0C71D33476A5B9745D650EAEF76* L_1 = (StringBuilderPooledObjectPolicy_tE85FA1EA59E1B0C71D33476A5B9745D650EAEF76*)il2cpp_codegen_object_new(StringBuilderPooledObjectPolicy_tE85FA1EA59E1B0C71D33476A5B9745D650EAEF76_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		StringBuilderPooledObjectPolicy__ctor_mBBC7CC5B947E04095F42BE1F231D7DEE6C3F7B49(L_1, NULL);
		NullCheck(L_0);
		ObjectPool_1_tE2419CB2E37566A480FEF1F372068053FC6344D0* L_2;
		L_2 = GenericVirtualFuncInvoker1< ObjectPool_1_tE2419CB2E37566A480FEF1F372068053FC6344D0*, RuntimeObject* >::Invoke(ObjectPoolProvider_Create_TisStringBuilder_t_m56956E8152B61E9BEDBB51892B141571E7249141_RuntimeMethod_var, L_0, L_1);
		return L_2;
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
// System.Int32 Microsoft.Extensions.ObjectPool.StringBuilderPooledObjectPolicy::get_InitialCapacity()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t StringBuilderPooledObjectPolicy_get_InitialCapacity_m91788A73651B9B3D69C5054C5141A214BA98C225 (StringBuilderPooledObjectPolicy_tE85FA1EA59E1B0C71D33476A5B9745D650EAEF76* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___U3CInitialCapacityU3Ek__BackingField_0;
		return L_0;
	}
}
// System.Int32 Microsoft.Extensions.ObjectPool.StringBuilderPooledObjectPolicy::get_MaximumRetainedCapacity()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t StringBuilderPooledObjectPolicy_get_MaximumRetainedCapacity_m5983D97FDD9D1826755BCC8227C244985996DEE8 (StringBuilderPooledObjectPolicy_tE85FA1EA59E1B0C71D33476A5B9745D650EAEF76* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___U3CMaximumRetainedCapacityU3Ek__BackingField_1;
		return L_0;
	}
}
// System.Text.StringBuilder Microsoft.Extensions.ObjectPool.StringBuilderPooledObjectPolicy::Create()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilderPooledObjectPolicy_Create_mB7A166C994FF45BEDC35E0F69D02D6A39AA042F6 (StringBuilderPooledObjectPolicy_tE85FA1EA59E1B0C71D33476A5B9745D650EAEF76* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		int32_t L_0;
		L_0 = StringBuilderPooledObjectPolicy_get_InitialCapacity_m91788A73651B9B3D69C5054C5141A214BA98C225_inline(__this, NULL);
		StringBuilder_t* L_1 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		StringBuilder__ctor_m2619CA8D2C3476DF1A302D9D941498BB1C6164C5(L_1, L_0, NULL);
		return L_1;
	}
}
// System.Boolean Microsoft.Extensions.ObjectPool.StringBuilderPooledObjectPolicy::Return(System.Text.StringBuilder)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool StringBuilderPooledObjectPolicy_Return_mB72462F6D6699280875E4C5DE1E5687F1DB0CF58 (StringBuilderPooledObjectPolicy_tE85FA1EA59E1B0C71D33476A5B9745D650EAEF76* __this, StringBuilder_t* ___0_obj, const RuntimeMethod* method) 
{
	{
		StringBuilder_t* L_0 = ___0_obj;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = StringBuilder_get_Capacity_m9DBF3B3940BC0BB882CA26F0EDB53896A491AD1E(L_0, NULL);
		int32_t L_2;
		L_2 = StringBuilderPooledObjectPolicy_get_MaximumRetainedCapacity_m5983D97FDD9D1826755BCC8227C244985996DEE8_inline(__this, NULL);
		if ((((int32_t)L_1) <= ((int32_t)L_2)))
		{
			goto IL_0010;
		}
	}
	{
		return (bool)0;
	}

IL_0010:
	{
		StringBuilder_t* L_3 = ___0_obj;
		NullCheck(L_3);
		StringBuilder_t* L_4;
		L_4 = StringBuilder_Clear_m2D76F6533574F40A4E3E2DC4E730277CBD0AF8F6(L_3, NULL);
		return (bool)1;
	}
}
// System.Void Microsoft.Extensions.ObjectPool.StringBuilderPooledObjectPolicy::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StringBuilderPooledObjectPolicy__ctor_mBBC7CC5B947E04095F42BE1F231D7DEE6C3F7B49 (StringBuilderPooledObjectPolicy_tE85FA1EA59E1B0C71D33476A5B9745D650EAEF76* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PooledObjectPolicy_1__ctor_m6E8F35EEBA1E2B0D3C3FED4EC63F82557FC1D145_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		__this->___U3CInitialCapacityU3Ek__BackingField_0 = ((int32_t)100);
		__this->___U3CMaximumRetainedCapacityU3Ek__BackingField_1 = ((int32_t)4096);
		PooledObjectPolicy_1__ctor_m6E8F35EEBA1E2B0D3C3FED4EC63F82557FC1D145(__this, PooledObjectPolicy_1__ctor_m6E8F35EEBA1E2B0D3C3FED4EC63F82557FC1D145_RuntimeMethod_var);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t StringBuilderPooledObjectPolicy_get_InitialCapacity_m91788A73651B9B3D69C5054C5141A214BA98C225_inline (StringBuilderPooledObjectPolicy_tE85FA1EA59E1B0C71D33476A5B9745D650EAEF76* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___U3CInitialCapacityU3Ek__BackingField_0;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t StringBuilderPooledObjectPolicy_get_MaximumRetainedCapacity_m5983D97FDD9D1826755BCC8227C244985996DEE8_inline (StringBuilderPooledObjectPolicy_tE85FA1EA59E1B0C71D33476A5B9745D650EAEF76* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___U3CMaximumRetainedCapacityU3Ek__BackingField_1;
		return L_0;
	}
}
