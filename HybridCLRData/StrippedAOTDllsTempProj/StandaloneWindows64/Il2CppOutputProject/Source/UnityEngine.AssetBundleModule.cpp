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

struct Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263;
struct AssetBundle_tB38418819A49060CD738CB21541649340F082943;
struct AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6;
struct AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621;
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C;
struct AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C;
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
struct IAsyncResult_t7B9B5A0ECB35DCEC31B8A8122C37D687369253B5;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
struct MethodInfo_t;
struct NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB;
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C;
struct ResourceRequest_tE6953FBA45EAAEFE866C635B9E7852044E62D868;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct String_t;
struct Type_t;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;

IL2CPP_EXTERN_C Il2CppSequencePoint g_sequencePointsUnityEngine_AssetBundleModule[];
IL2CPP_EXTERN_C RuntimeClass* Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Type_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeField* ResourceRequest_tE6953FBA45EAAEFE866C635B9E7852044E62D868____m_Type_FieldInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral358518C7B9669F4CD21363772C3317136923413A;
IL2CPP_EXTERN_C String_t* _stringLiteral51AFAC88FE0F5AA20A5F618F48C4CEAB7CC3DB34;
IL2CPP_EXTERN_C String_t* _stringLiteral820724398B4A28E6B958D19B3FC28BB8BF2787D3;
IL2CPP_EXTERN_C String_t* _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709;
IL2CPP_EXTERN_C const RuntimeMethod* AssetBundleCreateRequest__ctor_mAD1A6314795AC1B548A29A32E01815D33B6D0B46_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AssetBundleRequest__ctor_mD73743E1532E41D8AD2871C00A7FCDA5157171C0_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AssetBundleRequest_get_asset_mE9FDA3900215925371E7D15E7E19AA98713F5D6C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AssetBundle_LoadAllAssetsAsync_m01938F14A24C6C0C08BA6480D1384D674AD1DDB7_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AssetBundle_LoadAllAssetsAsync_m6BF82A05B486AA713460D4BC836E1445F2B45DB9_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AssetBundle_LoadAllAssets_m00E63EFF07B8E986754B7AFB3B8566B2B99C2241_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AssetBundle_LoadAllAssets_m0A8F41292C96F658A89B0E8D0ADB2E8395DD7F62_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AssetBundle_LoadAssetAsync_m686CB93D1D35DD784C74FFE8343D5626D736FF32_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AssetBundle_LoadAssetAsync_mDAE70E6DD6F9D5360A5D0C7A74F3989174C2FEDB_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AssetBundle_LoadAssetWithSubAssetsAsync_m5FC8920EC24E5D629664A30F7AE46F114ECD4D05_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AssetBundle_LoadAssetWithSubAssetsAsync_m8352895AE4BB09248808FCB3C66458DB911C1D7B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AssetBundle_LoadAssetWithSubAssets_m664A6B7E93502E26177F6C218FAB79A218DF841F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AssetBundle_LoadAssetWithSubAssets_m8F1B9E2F3DED19105612E7874487ADEC890480AF_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AssetBundle_LoadAsset_m021FE0B52DD660E54AE4C225D9AE66147902B8FE_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AssetBundle_LoadAsset_m25926A405F3AB79A4DF2447F23A09957EC7F063E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AssetBundle_LoadFromFileAsync_m4C768290B7B6EE3CF7483BD4F0D338D496735F94_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AssetBundle_LoadFromFile_mAFD7B0E8F0A0A88E9BB60180EBA0A99B8B3F2629_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AssetBundle_LoadFromMemory_mBA6847E4133DBBE3CCBCFFF31A40FA943DB95BBA_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AssetBundle__ctor_m12989CA081324BB49ED893BDA5E3B4E758D61410_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeType* AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* AssetBundle_tB38418819A49060CD738CB21541649340F082943_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_0_0_0_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct U3CModuleU3E_tAE2FD82E48B7893673000630524705C468010525 
{
};
struct MemberInfo_t  : public RuntimeObject
{
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};
struct YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D  : public RuntimeObject
{
};
struct YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_pinvoke
{
};
struct YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_com
{
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	uint8_t ___m_value;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	uint32_t ___m_value;
};
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF 
{
	uint64_t ___m_value;
};
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
struct AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C  : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D
{
	intptr_t ___m_Ptr;
	Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB* ___m_completeCallback;
};
struct AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C_marshaled_pinvoke : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_pinvoke
{
	intptr_t ___m_Ptr;
	Il2CppMethodPointer ___m_completeCallback;
};
struct AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C_marshaled_com : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_com
{
	intptr_t ___m_Ptr;
	Il2CppMethodPointer ___m_completeCallback;
};
struct Delegate_t  : public RuntimeObject
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	RuntimeObject* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	bool ___method_is_virtual;
};
struct Delegate_t_marshaled_pinvoke
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct Delegate_t_marshaled_com
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct Exception_t  : public RuntimeObject
{
	String_t* ____className;
	String_t* ____message;
	RuntimeObject* ____data;
	Exception_t* ____innerException;
	String_t* ____helpURL;
	RuntimeObject* ____stackTrace;
	String_t* ____stackTraceString;
	String_t* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	RuntimeObject* ____dynamicMethods;
	int32_t ____HResult;
	String_t* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_pinvoke
{
	char* ____className;
	char* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_pinvoke* ____innerException;
	char* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	char* ____stackTraceString;
	char* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	char* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className;
	Il2CppChar* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_com* ____innerException;
	Il2CppChar* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	Il2CppChar* ____stackTraceString;
	Il2CppChar* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	Il2CppChar* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C  : public RuntimeObject
{
	intptr_t ___m_CachedPtr;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_pinvoke
{
	intptr_t ___m_CachedPtr;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_com
{
	intptr_t ___m_CachedPtr;
};
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	intptr_t ___value;
};
struct AssetBundle_tB38418819A49060CD738CB21541649340F082943  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};
struct AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6  : public AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C
{
};
struct AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6_marshaled_pinvoke : public AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C_marshaled_pinvoke
{
};
struct AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6_marshaled_com : public AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C_marshaled_com
{
};
struct AssetBundleRecompressOperation_tFDA1FB5AE1E072FC6CAC1CF0064C13D77F87CDDE  : public AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C
{
};
struct AssetBundleRecompressOperation_tFDA1FB5AE1E072FC6CAC1CF0064C13D77F87CDDE_marshaled_pinvoke : public AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C_marshaled_pinvoke
{
};
struct AssetBundleRecompressOperation_tFDA1FB5AE1E072FC6CAC1CF0064C13D77F87CDDE_marshaled_com : public AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C_marshaled_com
{
};
struct AssetBundleUnloadOperation_tB96802FE8BBAC2B74D933BAF5F502EF9112095FD  : public AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C
{
};
struct AssetBundleUnloadOperation_tB96802FE8BBAC2B74D933BAF5F502EF9112095FD_marshaled_pinvoke : public AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C_marshaled_pinvoke
{
};
struct AssetBundleUnloadOperation_tB96802FE8BBAC2B74D933BAF5F502EF9112095FD_marshaled_com : public AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C_marshaled_com
{
};
struct MulticastDelegate_t  : public Delegate_t
{
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* ___delegates;
};
struct MulticastDelegate_t_marshaled_pinvoke : public Delegate_t_marshaled_pinvoke
{
	Delegate_t_marshaled_pinvoke** ___delegates;
};
struct MulticastDelegate_t_marshaled_com : public Delegate_t_marshaled_com
{
	Delegate_t_marshaled_com** ___delegates;
};
struct ResourceRequest_tE6953FBA45EAAEFE866C635B9E7852044E62D868  : public AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C
{
	String_t* ___m_Path;
	Type_t* ___m_Type;
};
struct ResourceRequest_tE6953FBA45EAAEFE866C635B9E7852044E62D868_marshaled_pinvoke : public AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C_marshaled_pinvoke
{
	char* ___m_Path;
	Type_t* ___m_Type;
};
struct ResourceRequest_tE6953FBA45EAAEFE866C635B9E7852044E62D868_marshaled_com : public AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C_marshaled_com
{
	Il2CppChar* ___m_Path;
	Type_t* ___m_Type;
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct Type_t  : public MemberInfo_t
{
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl;
};
struct Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB  : public MulticastDelegate_t
{
};
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
	String_t* ____paramName;
};
struct AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621  : public ResourceRequest_tE6953FBA45EAAEFE866C635B9E7852044E62D868
{
};
struct AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_marshaled_pinvoke : public ResourceRequest_tE6953FBA45EAAEFE866C635B9E7852044E62D868_marshaled_pinvoke
{
};
struct AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_marshaled_com : public ResourceRequest_tE6953FBA45EAAEFE866C635B9E7852044E62D868_marshaled_com
{
};
struct NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_StaticFields
{
	int32_t ___OffsetOfInstanceIDInCPlusPlusObject;
};
struct Type_t_StaticFields
{
	Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235* ___s_defaultBinder;
	Il2CppChar ___Delimiter;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___EmptyTypes;
	RuntimeObject* ___Missing;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterAttribute;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterName;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterNameIgnoreCase;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
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
struct ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A  : public RuntimeArray
{
	ALIGN_FIELD (8) Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* m_Items[1];

	inline Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};



IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_m2149FA40CEC8D82AC20D3508AB40C0D8EFEF68E6 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6* AssetBundle_LoadFromFileAsync_Internal_mB3D099E653D4AF91E5EA8CDCC49E8AB1BBAB764B (String_t* ___0_path, uint32_t ___1_crc, uint64_t ___2_offset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundle_tB38418819A49060CD738CB21541649340F082943* AssetBundle_LoadFromFile_Internal_m806E92FA35F9FF7F9868058055FB347B9E35BD74 (String_t* ___0_path, uint32_t ___1_crc, uint64_t ___2_offset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundle_tB38418819A49060CD738CB21541649340F082943* AssetBundle_LoadFromMemory_Internal_m05D4AAA1B9AF41422A57A602AED64172D29C4305 (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_binary, uint32_t ___1_crc, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57 (RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ___0_handle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* AssetBundle_LoadAsset_m021FE0B52DD660E54AE4C225D9AE66147902B8FE (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NullReferenceException__ctor_mA41317A57F5C1C0E3F59C7EB25ABD484564B23D4 (NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465 (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC (Type_t* ___0_left, Type_t* ___1_right, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* AssetBundle_LoadAsset_Internal_mD096392756815901FE982C1AF64DDF0846551433 (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* AssetBundle_LoadAssetAsync_mDAE70E6DD6F9D5360A5D0C7A74F3989174C2FEDB (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* AssetBundle_LoadAssetAsync_Internal_m2F3749CA103E883447AE6629E342D4C0D39A2FBE (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* AssetBundle_LoadAssetWithSubAssets_m664A6B7E93502E26177F6C218FAB79A218DF841F (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* AssetBundle_LoadAssetWithSubAssets_Internal_m14AE2B2D7696182CBDF12087E8D3FEA867290DA8 (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* AssetBundle_LoadAssetWithSubAssetsAsync_m8352895AE4BB09248808FCB3C66458DB911C1D7B (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* AssetBundle_LoadAssetWithSubAssetsAsync_Internal_m9C189D40BB6E14EFB7432173EC273BE9C5E900D4 (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* AssetBundle_LoadAllAssets_m0A8F41292C96F658A89B0E8D0ADB2E8395DD7F62 (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, Type_t* ___0_type, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* AssetBundle_LoadAllAssetsAsync_m6BF82A05B486AA713460D4BC836E1445F2B45DB9 (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, Type_t* ___0_type, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AsyncOperation__ctor_m53CF89405A1E2DA6F517D05792826F5784B0D6EC (AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ResourceRequest__ctor_m11F59D90927F0F2598D8776E2CB64CD106D54FAC (ResourceRequest_tE6953FBA45EAAEFE866C635B9E7852044E62D868* __this, const RuntimeMethod* method) ;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AssetBundle__ctor_m12989CA081324BB49ED893BDA5E3B4E758D61410 (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle__ctor_m12989CA081324BB49ED893BDA5E3B4E758D61410_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_tB38418819A49060CD738CB21541649340F082943_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, AssetBundle__ctor_m12989CA081324BB49ED893BDA5E3B4E758D61410_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 0));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 1));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 2));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 3));
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		Object__ctor_m2149FA40CEC8D82AC20D3508AB40C0D8EFEF68E6(__this, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 3));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 4));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 5));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AssetBundle_UnloadAllAssetBundles_mF68ACFAF3AB098C0E083552C235B20508C58C11D (bool ___0_unloadAllObjects, const RuntimeMethod* method) 
{
	typedef void (*AssetBundle_UnloadAllAssetBundles_mF68ACFAF3AB098C0E083552C235B20508C58C11D_ftn) (bool);
	static AssetBundle_UnloadAllAssetBundles_mF68ACFAF3AB098C0E083552C235B20508C58C11D_ftn _il2cpp_icall_func;
	if (!_il2cpp_icall_func)
	_il2cpp_icall_func = (AssetBundle_UnloadAllAssetBundles_mF68ACFAF3AB098C0E083552C235B20508C58C11D_ftn)il2cpp_codegen_resolve_icall ("UnityEngine.AssetBundle::UnloadAllAssetBundles(System.Boolean)");
	_il2cpp_icall_func(___0_unloadAllObjects);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6* AssetBundle_LoadFromFileAsync_Internal_mB3D099E653D4AF91E5EA8CDCC49E8AB1BBAB764B (String_t* ___0_path, uint32_t ___1_crc, uint64_t ___2_offset, const RuntimeMethod* method) 
{
	typedef AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6* (*AssetBundle_LoadFromFileAsync_Internal_mB3D099E653D4AF91E5EA8CDCC49E8AB1BBAB764B_ftn) (String_t*, uint32_t, uint64_t);
	static AssetBundle_LoadFromFileAsync_Internal_mB3D099E653D4AF91E5EA8CDCC49E8AB1BBAB764B_ftn _il2cpp_icall_func;
	if (!_il2cpp_icall_func)
	_il2cpp_icall_func = (AssetBundle_LoadFromFileAsync_Internal_mB3D099E653D4AF91E5EA8CDCC49E8AB1BBAB764B_ftn)il2cpp_codegen_resolve_icall ("UnityEngine.AssetBundle::LoadFromFileAsync_Internal(System.String,System.UInt32,System.UInt64)");
	AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6* icallRetVal = _il2cpp_icall_func(___0_path, ___1_crc, ___2_offset);
	return icallRetVal;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6* AssetBundle_LoadFromFileAsync_m4C768290B7B6EE3CF7483BD4F0D338D496735F94 (String_t* ___0_path, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_LoadFromFileAsync_m4C768290B7B6EE3CF7483BD4F0D338D496735F94_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_path));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, AssetBundle_LoadFromFileAsync_m4C768290B7B6EE3CF7483BD4F0D338D496735F94_RuntimeMethod_var, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 6));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 7));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 8));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 9));
		String_t* L_0 = ___0_path;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 10));
		AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6* L_1;
		L_1 = AssetBundle_LoadFromFileAsync_Internal_mB3D099E653D4AF91E5EA8CDCC49E8AB1BBAB764B(L_0, 0, ((int64_t)0), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 10));
		V_0 = L_1;
		goto IL_000d;
	}

IL_000d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 11));
		AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6* L_2 = V_0;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundle_tB38418819A49060CD738CB21541649340F082943* AssetBundle_LoadFromFile_Internal_m806E92FA35F9FF7F9868058055FB347B9E35BD74 (String_t* ___0_path, uint32_t ___1_crc, uint64_t ___2_offset, const RuntimeMethod* method) 
{
	typedef AssetBundle_tB38418819A49060CD738CB21541649340F082943* (*AssetBundle_LoadFromFile_Internal_m806E92FA35F9FF7F9868058055FB347B9E35BD74_ftn) (String_t*, uint32_t, uint64_t);
	static AssetBundle_LoadFromFile_Internal_m806E92FA35F9FF7F9868058055FB347B9E35BD74_ftn _il2cpp_icall_func;
	if (!_il2cpp_icall_func)
	_il2cpp_icall_func = (AssetBundle_LoadFromFile_Internal_m806E92FA35F9FF7F9868058055FB347B9E35BD74_ftn)il2cpp_codegen_resolve_icall ("UnityEngine.AssetBundle::LoadFromFile_Internal(System.String,System.UInt32,System.UInt64)");
	AssetBundle_tB38418819A49060CD738CB21541649340F082943* icallRetVal = _il2cpp_icall_func(___0_path, ___1_crc, ___2_offset);
	return icallRetVal;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundle_tB38418819A49060CD738CB21541649340F082943* AssetBundle_LoadFromFile_mAFD7B0E8F0A0A88E9BB60180EBA0A99B8B3F2629 (String_t* ___0_path, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_LoadFromFile_mAFD7B0E8F0A0A88E9BB60180EBA0A99B8B3F2629_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_tB38418819A49060CD738CB21541649340F082943_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	AssetBundle_tB38418819A49060CD738CB21541649340F082943* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_path));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, AssetBundle_LoadFromFile_mAFD7B0E8F0A0A88E9BB60180EBA0A99B8B3F2629_RuntimeMethod_var, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 12));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 13));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 14));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 15));
		String_t* L_0 = ___0_path;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 16));
		AssetBundle_tB38418819A49060CD738CB21541649340F082943* L_1;
		L_1 = AssetBundle_LoadFromFile_Internal_m806E92FA35F9FF7F9868058055FB347B9E35BD74(L_0, 0, ((int64_t)0), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 16));
		V_0 = L_1;
		goto IL_000d;
	}

IL_000d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 17));
		AssetBundle_tB38418819A49060CD738CB21541649340F082943* L_2 = V_0;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundle_tB38418819A49060CD738CB21541649340F082943* AssetBundle_LoadFromMemory_Internal_m05D4AAA1B9AF41422A57A602AED64172D29C4305 (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_binary, uint32_t ___1_crc, const RuntimeMethod* method) 
{
	typedef AssetBundle_tB38418819A49060CD738CB21541649340F082943* (*AssetBundle_LoadFromMemory_Internal_m05D4AAA1B9AF41422A57A602AED64172D29C4305_ftn) (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*, uint32_t);
	static AssetBundle_LoadFromMemory_Internal_m05D4AAA1B9AF41422A57A602AED64172D29C4305_ftn _il2cpp_icall_func;
	if (!_il2cpp_icall_func)
	_il2cpp_icall_func = (AssetBundle_LoadFromMemory_Internal_m05D4AAA1B9AF41422A57A602AED64172D29C4305_ftn)il2cpp_codegen_resolve_icall ("UnityEngine.AssetBundle::LoadFromMemory_Internal(System.Byte[],System.UInt32)");
	AssetBundle_tB38418819A49060CD738CB21541649340F082943* icallRetVal = _il2cpp_icall_func(___0_binary, ___1_crc);
	return icallRetVal;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundle_tB38418819A49060CD738CB21541649340F082943* AssetBundle_LoadFromMemory_mBA6847E4133DBBE3CCBCFFF31A40FA943DB95BBA (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_binary, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_LoadFromMemory_mBA6847E4133DBBE3CCBCFFF31A40FA943DB95BBA_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_tB38418819A49060CD738CB21541649340F082943_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	AssetBundle_tB38418819A49060CD738CB21541649340F082943* V_0 = NULL;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_binary));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, AssetBundle_LoadFromMemory_mBA6847E4133DBBE3CCBCFFF31A40FA943DB95BBA_RuntimeMethod_var, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 18));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 19));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 20));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 21));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___0_binary;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 22));
		AssetBundle_tB38418819A49060CD738CB21541649340F082943* L_1;
		L_1 = AssetBundle_LoadFromMemory_Internal_m05D4AAA1B9AF41422A57A602AED64172D29C4305(L_0, 0, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 22));
		V_0 = L_1;
		goto IL_000b;
	}

IL_000b:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 23));
		AssetBundle_tB38418819A49060CD738CB21541649340F082943* L_2 = V_0;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* AssetBundle_LoadAsset_m25926A405F3AB79A4DF2447F23A09957EC7F063E (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, String_t* ___0_name, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_LoadAsset_m25926A405F3AB79A4DF2447F23A09957EC7F063E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_tB38418819A49060CD738CB21541649340F082943_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* V_0 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_name));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, AssetBundle_LoadAsset_m25926A405F3AB79A4DF2447F23A09957EC7F063E_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 24));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 25));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 26));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 27));
		String_t* L_0 = ___0_name;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_1 = { reinterpret_cast<intptr_t> (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_0_0_0_var) };
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 28));
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_2;
		L_2 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_1, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 28));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 29));
		Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* L_3;
		L_3 = AssetBundle_LoadAsset_m021FE0B52DD660E54AE4C225D9AE66147902B8FE(__this, L_0, L_2, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 29));
		V_0 = L_3;
		goto IL_0015;
	}

IL_0015:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 30));
		Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* L_4 = V_0;
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* AssetBundle_LoadAsset_m021FE0B52DD660E54AE4C225D9AE66147902B8FE (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_LoadAsset_m021FE0B52DD660E54AE4C225D9AE66147902B8FE_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_tB38418819A49060CD738CB21541649340F082943_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	bool V_2 = false;
	Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* V_3 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_name), (&___1_type));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, AssetBundle_LoadAsset_m021FE0B52DD660E54AE4C225D9AE66147902B8FE_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 31));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 32));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 33));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 34));
		String_t* L_0 = ___0_name;
		V_0 = (bool)((((RuntimeObject*)(String_t*)L_0) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 35));
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 36));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 37));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 38));
		NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB* L_2 = (NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB_il2cpp_TypeInfo_var)));
		NullReferenceException__ctor_mA41317A57F5C1C0E3F59C7EB25ABD484564B23D4(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral51AFAC88FE0F5AA20A5F618F48C4CEAB7CC3DB34)), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 38));
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&AssetBundle_LoadAsset_m021FE0B52DD660E54AE4C225D9AE66147902B8FE_RuntimeMethod_var)));
	}

IL_0015:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 39));
		String_t* L_3 = ___0_name;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 40));
		NullCheck(L_3);
		int32_t L_4;
		L_4 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_3, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 40));
		V_1 = (bool)((((int32_t)L_4) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 41));
		bool L_5 = V_1;
		if (!L_5)
		{
			goto IL_002e;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 42));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 43));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 44));
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_6 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_6, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral358518C7B9669F4CD21363772C3317136923413A)), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 44));
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_6, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&AssetBundle_LoadAsset_m021FE0B52DD660E54AE4C225D9AE66147902B8FE_RuntimeMethod_var)));
	}

IL_002e:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 45));
		Type_t* L_7 = ___1_type;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 46));
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		bool L_8;
		L_8 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_7, (Type_t*)NULL, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 46));
		V_2 = L_8;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 47));
		bool L_9 = V_2;
		if (!L_9)
		{
			goto IL_0045;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 48));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 49));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 50));
		NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB* L_10 = (NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB_il2cpp_TypeInfo_var)));
		NullReferenceException__ctor_mA41317A57F5C1C0E3F59C7EB25ABD484564B23D4(L_10, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral820724398B4A28E6B958D19B3FC28BB8BF2787D3)), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 50));
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_10, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&AssetBundle_LoadAsset_m021FE0B52DD660E54AE4C225D9AE66147902B8FE_RuntimeMethod_var)));
	}

IL_0045:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 51));
		String_t* L_11 = ___0_name;
		Type_t* L_12 = ___1_type;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 52));
		Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* L_13;
		L_13 = AssetBundle_LoadAsset_Internal_mD096392756815901FE982C1AF64DDF0846551433(__this, L_11, L_12, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 52));
		V_3 = L_13;
		goto IL_0050;
	}

IL_0050:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 53));
		Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* L_14 = V_3;
		return L_14;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* AssetBundle_LoadAsset_Internal_mD096392756815901FE982C1AF64DDF0846551433 (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method) 
{
	typedef Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* (*AssetBundle_LoadAsset_Internal_mD096392756815901FE982C1AF64DDF0846551433_ftn) (AssetBundle_tB38418819A49060CD738CB21541649340F082943*, String_t*, Type_t*);
	static AssetBundle_LoadAsset_Internal_mD096392756815901FE982C1AF64DDF0846551433_ftn _il2cpp_icall_func;
	if (!_il2cpp_icall_func)
	_il2cpp_icall_func = (AssetBundle_LoadAsset_Internal_mD096392756815901FE982C1AF64DDF0846551433_ftn)il2cpp_codegen_resolve_icall ("UnityEngine.AssetBundle::LoadAsset_Internal(System.String,System.Type)");
	Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* icallRetVal = _il2cpp_icall_func(__this, ___0_name, ___1_type);
	return icallRetVal;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* AssetBundle_LoadAssetAsync_m686CB93D1D35DD784C74FFE8343D5626D736FF32 (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, String_t* ___0_name, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_LoadAssetAsync_m686CB93D1D35DD784C74FFE8343D5626D736FF32_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_tB38418819A49060CD738CB21541649340F082943_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* V_0 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_name));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, AssetBundle_LoadAssetAsync_m686CB93D1D35DD784C74FFE8343D5626D736FF32_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 54));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 55));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 56));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 57));
		String_t* L_0 = ___0_name;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_1 = { reinterpret_cast<intptr_t> (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_0_0_0_var) };
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 58));
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_2;
		L_2 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_1, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 58));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 59));
		AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* L_3;
		L_3 = AssetBundle_LoadAssetAsync_mDAE70E6DD6F9D5360A5D0C7A74F3989174C2FEDB(__this, L_0, L_2, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 59));
		V_0 = L_3;
		goto IL_0015;
	}

IL_0015:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 60));
		AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* L_4 = V_0;
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* AssetBundle_LoadAssetAsync_mDAE70E6DD6F9D5360A5D0C7A74F3989174C2FEDB (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_LoadAssetAsync_mDAE70E6DD6F9D5360A5D0C7A74F3989174C2FEDB_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_tB38418819A49060CD738CB21541649340F082943_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	bool V_2 = false;
	AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* V_3 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_name), (&___1_type));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, AssetBundle_LoadAssetAsync_mDAE70E6DD6F9D5360A5D0C7A74F3989174C2FEDB_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 61));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 62));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 63));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 64));
		String_t* L_0 = ___0_name;
		V_0 = (bool)((((RuntimeObject*)(String_t*)L_0) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 65));
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 66));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 67));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 68));
		NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB* L_2 = (NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB_il2cpp_TypeInfo_var)));
		NullReferenceException__ctor_mA41317A57F5C1C0E3F59C7EB25ABD484564B23D4(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral51AFAC88FE0F5AA20A5F618F48C4CEAB7CC3DB34)), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 68));
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&AssetBundle_LoadAssetAsync_mDAE70E6DD6F9D5360A5D0C7A74F3989174C2FEDB_RuntimeMethod_var)));
	}

IL_0015:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 69));
		String_t* L_3 = ___0_name;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 70));
		NullCheck(L_3);
		int32_t L_4;
		L_4 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_3, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 70));
		V_1 = (bool)((((int32_t)L_4) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 71));
		bool L_5 = V_1;
		if (!L_5)
		{
			goto IL_002e;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 72));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 73));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 74));
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_6 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_6, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral358518C7B9669F4CD21363772C3317136923413A)), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 74));
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_6, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&AssetBundle_LoadAssetAsync_mDAE70E6DD6F9D5360A5D0C7A74F3989174C2FEDB_RuntimeMethod_var)));
	}

IL_002e:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 75));
		Type_t* L_7 = ___1_type;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 76));
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		bool L_8;
		L_8 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_7, (Type_t*)NULL, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 76));
		V_2 = L_8;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 77));
		bool L_9 = V_2;
		if (!L_9)
		{
			goto IL_0045;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 78));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 79));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 80));
		NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB* L_10 = (NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB_il2cpp_TypeInfo_var)));
		NullReferenceException__ctor_mA41317A57F5C1C0E3F59C7EB25ABD484564B23D4(L_10, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral820724398B4A28E6B958D19B3FC28BB8BF2787D3)), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 80));
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_10, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&AssetBundle_LoadAssetAsync_mDAE70E6DD6F9D5360A5D0C7A74F3989174C2FEDB_RuntimeMethod_var)));
	}

IL_0045:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 81));
		String_t* L_11 = ___0_name;
		Type_t* L_12 = ___1_type;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 82));
		AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* L_13;
		L_13 = AssetBundle_LoadAssetAsync_Internal_m2F3749CA103E883447AE6629E342D4C0D39A2FBE(__this, L_11, L_12, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 82));
		V_3 = L_13;
		goto IL_0050;
	}

IL_0050:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 83));
		AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* L_14 = V_3;
		return L_14;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* AssetBundle_LoadAssetWithSubAssets_m8F1B9E2F3DED19105612E7874487ADEC890480AF (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, String_t* ___0_name, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_LoadAssetWithSubAssets_m8F1B9E2F3DED19105612E7874487ADEC890480AF_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_tB38418819A49060CD738CB21541649340F082943_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* V_0 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_name));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, AssetBundle_LoadAssetWithSubAssets_m8F1B9E2F3DED19105612E7874487ADEC890480AF_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 84));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 85));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 86));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 87));
		String_t* L_0 = ___0_name;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_1 = { reinterpret_cast<intptr_t> (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_0_0_0_var) };
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 88));
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_2;
		L_2 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_1, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 88));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 89));
		ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* L_3;
		L_3 = AssetBundle_LoadAssetWithSubAssets_m664A6B7E93502E26177F6C218FAB79A218DF841F(__this, L_0, L_2, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 89));
		V_0 = L_3;
		goto IL_0015;
	}

IL_0015:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 90));
		ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* L_4 = V_0;
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* AssetBundle_LoadAssetWithSubAssets_m664A6B7E93502E26177F6C218FAB79A218DF841F (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_LoadAssetWithSubAssets_m664A6B7E93502E26177F6C218FAB79A218DF841F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_tB38418819A49060CD738CB21541649340F082943_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	bool V_2 = false;
	ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* V_3 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_name), (&___1_type));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, AssetBundle_LoadAssetWithSubAssets_m664A6B7E93502E26177F6C218FAB79A218DF841F_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 91));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 92));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 93));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 94));
		String_t* L_0 = ___0_name;
		V_0 = (bool)((((RuntimeObject*)(String_t*)L_0) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 95));
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 96));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 97));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 98));
		NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB* L_2 = (NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB_il2cpp_TypeInfo_var)));
		NullReferenceException__ctor_mA41317A57F5C1C0E3F59C7EB25ABD484564B23D4(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral51AFAC88FE0F5AA20A5F618F48C4CEAB7CC3DB34)), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 98));
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&AssetBundle_LoadAssetWithSubAssets_m664A6B7E93502E26177F6C218FAB79A218DF841F_RuntimeMethod_var)));
	}

IL_0015:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 99));
		String_t* L_3 = ___0_name;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 100));
		NullCheck(L_3);
		int32_t L_4;
		L_4 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_3, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 100));
		V_1 = (bool)((((int32_t)L_4) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 101));
		bool L_5 = V_1;
		if (!L_5)
		{
			goto IL_002e;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 102));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 103));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 104));
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_6 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_6, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral358518C7B9669F4CD21363772C3317136923413A)), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 104));
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_6, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&AssetBundle_LoadAssetWithSubAssets_m664A6B7E93502E26177F6C218FAB79A218DF841F_RuntimeMethod_var)));
	}

IL_002e:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 105));
		Type_t* L_7 = ___1_type;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 106));
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		bool L_8;
		L_8 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_7, (Type_t*)NULL, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 106));
		V_2 = L_8;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 107));
		bool L_9 = V_2;
		if (!L_9)
		{
			goto IL_0045;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 108));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 109));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 110));
		NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB* L_10 = (NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB_il2cpp_TypeInfo_var)));
		NullReferenceException__ctor_mA41317A57F5C1C0E3F59C7EB25ABD484564B23D4(L_10, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral820724398B4A28E6B958D19B3FC28BB8BF2787D3)), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 110));
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_10, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&AssetBundle_LoadAssetWithSubAssets_m664A6B7E93502E26177F6C218FAB79A218DF841F_RuntimeMethod_var)));
	}

IL_0045:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 111));
		String_t* L_11 = ___0_name;
		Type_t* L_12 = ___1_type;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 112));
		ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* L_13;
		L_13 = AssetBundle_LoadAssetWithSubAssets_Internal_m14AE2B2D7696182CBDF12087E8D3FEA867290DA8(__this, L_11, L_12, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 112));
		V_3 = L_13;
		goto IL_0050;
	}

IL_0050:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 113));
		ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* L_14 = V_3;
		return L_14;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* AssetBundle_LoadAssetWithSubAssetsAsync_m5FC8920EC24E5D629664A30F7AE46F114ECD4D05 (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, String_t* ___0_name, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_LoadAssetWithSubAssetsAsync_m5FC8920EC24E5D629664A30F7AE46F114ECD4D05_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_tB38418819A49060CD738CB21541649340F082943_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* V_0 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_name));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, AssetBundle_LoadAssetWithSubAssetsAsync_m5FC8920EC24E5D629664A30F7AE46F114ECD4D05_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 114));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 115));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 116));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 117));
		String_t* L_0 = ___0_name;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_1 = { reinterpret_cast<intptr_t> (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_0_0_0_var) };
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 118));
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_2;
		L_2 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_1, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 118));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 119));
		AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* L_3;
		L_3 = AssetBundle_LoadAssetWithSubAssetsAsync_m8352895AE4BB09248808FCB3C66458DB911C1D7B(__this, L_0, L_2, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 119));
		V_0 = L_3;
		goto IL_0015;
	}

IL_0015:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 120));
		AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* L_4 = V_0;
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* AssetBundle_LoadAssetWithSubAssetsAsync_m8352895AE4BB09248808FCB3C66458DB911C1D7B (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_LoadAssetWithSubAssetsAsync_m8352895AE4BB09248808FCB3C66458DB911C1D7B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_tB38418819A49060CD738CB21541649340F082943_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	bool V_2 = false;
	AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* V_3 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_name), (&___1_type));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, AssetBundle_LoadAssetWithSubAssetsAsync_m8352895AE4BB09248808FCB3C66458DB911C1D7B_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 121));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 122));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 123));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 124));
		String_t* L_0 = ___0_name;
		V_0 = (bool)((((RuntimeObject*)(String_t*)L_0) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 125));
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 126));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 127));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 128));
		NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB* L_2 = (NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB_il2cpp_TypeInfo_var)));
		NullReferenceException__ctor_mA41317A57F5C1C0E3F59C7EB25ABD484564B23D4(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral51AFAC88FE0F5AA20A5F618F48C4CEAB7CC3DB34)), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 128));
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&AssetBundle_LoadAssetWithSubAssetsAsync_m8352895AE4BB09248808FCB3C66458DB911C1D7B_RuntimeMethod_var)));
	}

IL_0015:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 129));
		String_t* L_3 = ___0_name;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 130));
		NullCheck(L_3);
		int32_t L_4;
		L_4 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_3, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 130));
		V_1 = (bool)((((int32_t)L_4) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 131));
		bool L_5 = V_1;
		if (!L_5)
		{
			goto IL_002e;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 132));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 133));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 134));
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_6 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_6, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral358518C7B9669F4CD21363772C3317136923413A)), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 134));
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_6, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&AssetBundle_LoadAssetWithSubAssetsAsync_m8352895AE4BB09248808FCB3C66458DB911C1D7B_RuntimeMethod_var)));
	}

IL_002e:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 135));
		Type_t* L_7 = ___1_type;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 136));
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		bool L_8;
		L_8 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_7, (Type_t*)NULL, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 136));
		V_2 = L_8;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 137));
		bool L_9 = V_2;
		if (!L_9)
		{
			goto IL_0045;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 138));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 139));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 140));
		NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB* L_10 = (NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB_il2cpp_TypeInfo_var)));
		NullReferenceException__ctor_mA41317A57F5C1C0E3F59C7EB25ABD484564B23D4(L_10, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral820724398B4A28E6B958D19B3FC28BB8BF2787D3)), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 140));
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_10, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&AssetBundle_LoadAssetWithSubAssetsAsync_m8352895AE4BB09248808FCB3C66458DB911C1D7B_RuntimeMethod_var)));
	}

IL_0045:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 141));
		String_t* L_11 = ___0_name;
		Type_t* L_12 = ___1_type;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 142));
		AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* L_13;
		L_13 = AssetBundle_LoadAssetWithSubAssetsAsync_Internal_m9C189D40BB6E14EFB7432173EC273BE9C5E900D4(__this, L_11, L_12, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 142));
		V_3 = L_13;
		goto IL_0050;
	}

IL_0050:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 143));
		AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* L_14 = V_3;
		return L_14;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* AssetBundle_LoadAllAssets_m00E63EFF07B8E986754B7AFB3B8566B2B99C2241 (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_LoadAllAssets_m00E63EFF07B8E986754B7AFB3B8566B2B99C2241_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_tB38418819A49060CD738CB21541649340F082943_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* V_0 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, AssetBundle_LoadAllAssets_m00E63EFF07B8E986754B7AFB3B8566B2B99C2241_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 144));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 145));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 146));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 147));
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_0_0_0_var) };
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 148));
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 148));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 149));
		ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* L_2;
		L_2 = AssetBundle_LoadAllAssets_m0A8F41292C96F658A89B0E8D0ADB2E8395DD7F62(__this, L_1, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 149));
		V_0 = L_2;
		goto IL_0014;
	}

IL_0014:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 150));
		ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* L_3 = V_0;
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* AssetBundle_LoadAllAssets_m0A8F41292C96F658A89B0E8D0ADB2E8395DD7F62 (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, Type_t* ___0_type, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_LoadAllAssets_m0A8F41292C96F658A89B0E8D0ADB2E8395DD7F62_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_tB38418819A49060CD738CB21541649340F082943_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* V_1 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_type));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, AssetBundle_LoadAllAssets_m0A8F41292C96F658A89B0E8D0ADB2E8395DD7F62_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 151));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 152));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 153));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 154));
		Type_t* L_0 = ___0_type;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 155));
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_0, (Type_t*)NULL, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 155));
		V_0 = L_1;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 156));
		bool L_2 = V_0;
		if (!L_2)
		{
			goto IL_0018;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 157));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 158));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 159));
		NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB* L_3 = (NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB_il2cpp_TypeInfo_var)));
		NullReferenceException__ctor_mA41317A57F5C1C0E3F59C7EB25ABD484564B23D4(L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral820724398B4A28E6B958D19B3FC28BB8BF2787D3)), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 159));
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&AssetBundle_LoadAllAssets_m0A8F41292C96F658A89B0E8D0ADB2E8395DD7F62_RuntimeMethod_var)));
	}

IL_0018:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 160));
		Type_t* L_4 = ___0_type;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 161));
		ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* L_5;
		L_5 = AssetBundle_LoadAssetWithSubAssets_Internal_m14AE2B2D7696182CBDF12087E8D3FEA867290DA8(__this, _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, L_4, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 161));
		V_1 = L_5;
		goto IL_0027;
	}

IL_0027:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 162));
		ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* L_6 = V_1;
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* AssetBundle_LoadAllAssetsAsync_m01938F14A24C6C0C08BA6480D1384D674AD1DDB7 (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_LoadAllAssetsAsync_m01938F14A24C6C0C08BA6480D1384D674AD1DDB7_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_tB38418819A49060CD738CB21541649340F082943_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* V_0 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, AssetBundle_LoadAllAssetsAsync_m01938F14A24C6C0C08BA6480D1384D674AD1DDB7_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 163));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 164));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 165));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 166));
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_0_0_0_var) };
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 167));
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 167));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 168));
		AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* L_2;
		L_2 = AssetBundle_LoadAllAssetsAsync_m6BF82A05B486AA713460D4BC836E1445F2B45DB9(__this, L_1, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 168));
		V_0 = L_2;
		goto IL_0014;
	}

IL_0014:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 169));
		AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* L_3 = V_0;
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* AssetBundle_LoadAllAssetsAsync_m6BF82A05B486AA713460D4BC836E1445F2B45DB9 (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, Type_t* ___0_type, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_LoadAllAssetsAsync_m6BF82A05B486AA713460D4BC836E1445F2B45DB9_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundle_tB38418819A49060CD738CB21541649340F082943_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* V_1 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___0_type));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, AssetBundle_LoadAllAssetsAsync_m6BF82A05B486AA713460D4BC836E1445F2B45DB9_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 170));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 171));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 172));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 173));
		Type_t* L_0 = ___0_type;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 174));
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_0, (Type_t*)NULL, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 174));
		V_0 = L_1;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 175));
		bool L_2 = V_0;
		if (!L_2)
		{
			goto IL_0018;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 176));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 177));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 178));
		NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB* L_3 = (NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NullReferenceException_tBDE63A6D24569B964908408389070C6A9F5005BB_il2cpp_TypeInfo_var)));
		NullReferenceException__ctor_mA41317A57F5C1C0E3F59C7EB25ABD484564B23D4(L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral820724398B4A28E6B958D19B3FC28BB8BF2787D3)), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 178));
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&AssetBundle_LoadAllAssetsAsync_m6BF82A05B486AA713460D4BC836E1445F2B45DB9_RuntimeMethod_var)));
	}

IL_0018:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 179));
		Type_t* L_4 = ___0_type;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 180));
		AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* L_5;
		L_5 = AssetBundle_LoadAssetWithSubAssetsAsync_Internal_m9C189D40BB6E14EFB7432173EC273BE9C5E900D4(__this, _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, L_4, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 180));
		V_1 = L_5;
		goto IL_0027;
	}

IL_0027:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 181));
		AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* L_6 = V_1;
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* AssetBundle_LoadAssetAsync_Internal_m2F3749CA103E883447AE6629E342D4C0D39A2FBE (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method) 
{
	typedef AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* (*AssetBundle_LoadAssetAsync_Internal_m2F3749CA103E883447AE6629E342D4C0D39A2FBE_ftn) (AssetBundle_tB38418819A49060CD738CB21541649340F082943*, String_t*, Type_t*);
	static AssetBundle_LoadAssetAsync_Internal_m2F3749CA103E883447AE6629E342D4C0D39A2FBE_ftn _il2cpp_icall_func;
	if (!_il2cpp_icall_func)
	_il2cpp_icall_func = (AssetBundle_LoadAssetAsync_Internal_m2F3749CA103E883447AE6629E342D4C0D39A2FBE_ftn)il2cpp_codegen_resolve_icall ("UnityEngine.AssetBundle::LoadAssetAsync_Internal(System.String,System.Type)");
	AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* icallRetVal = _il2cpp_icall_func(__this, ___0_name, ___1_type);
	return icallRetVal;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AssetBundle_Unload_m0A189871E61A0D6735A2B41B3360A1F0677B636B (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, bool ___0_unloadAllLoadedObjects, const RuntimeMethod* method) 
{
	typedef void (*AssetBundle_Unload_m0A189871E61A0D6735A2B41B3360A1F0677B636B_ftn) (AssetBundle_tB38418819A49060CD738CB21541649340F082943*, bool);
	static AssetBundle_Unload_m0A189871E61A0D6735A2B41B3360A1F0677B636B_ftn _il2cpp_icall_func;
	if (!_il2cpp_icall_func)
	_il2cpp_icall_func = (AssetBundle_Unload_m0A189871E61A0D6735A2B41B3360A1F0677B636B_ftn)il2cpp_codegen_resolve_icall ("UnityEngine.AssetBundle::Unload(System.Boolean)");
	_il2cpp_icall_func(__this, ___0_unloadAllLoadedObjects);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* AssetBundle_LoadAssetWithSubAssets_Internal_m14AE2B2D7696182CBDF12087E8D3FEA867290DA8 (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method) 
{
	typedef ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* (*AssetBundle_LoadAssetWithSubAssets_Internal_m14AE2B2D7696182CBDF12087E8D3FEA867290DA8_ftn) (AssetBundle_tB38418819A49060CD738CB21541649340F082943*, String_t*, Type_t*);
	static AssetBundle_LoadAssetWithSubAssets_Internal_m14AE2B2D7696182CBDF12087E8D3FEA867290DA8_ftn _il2cpp_icall_func;
	if (!_il2cpp_icall_func)
	_il2cpp_icall_func = (AssetBundle_LoadAssetWithSubAssets_Internal_m14AE2B2D7696182CBDF12087E8D3FEA867290DA8_ftn)il2cpp_codegen_resolve_icall ("UnityEngine.AssetBundle::LoadAssetWithSubAssets_Internal(System.String,System.Type)");
	ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* icallRetVal = _il2cpp_icall_func(__this, ___0_name, ___1_type);
	return icallRetVal;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* AssetBundle_LoadAssetWithSubAssetsAsync_Internal_m9C189D40BB6E14EFB7432173EC273BE9C5E900D4 (AssetBundle_tB38418819A49060CD738CB21541649340F082943* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method) 
{
	typedef AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* (*AssetBundle_LoadAssetWithSubAssetsAsync_Internal_m9C189D40BB6E14EFB7432173EC273BE9C5E900D4_ftn) (AssetBundle_tB38418819A49060CD738CB21541649340F082943*, String_t*, Type_t*);
	static AssetBundle_LoadAssetWithSubAssetsAsync_Internal_m9C189D40BB6E14EFB7432173EC273BE9C5E900D4_ftn _il2cpp_icall_func;
	if (!_il2cpp_icall_func)
	_il2cpp_icall_func = (AssetBundle_LoadAssetWithSubAssetsAsync_Internal_m9C189D40BB6E14EFB7432173EC273BE9C5E900D4_ftn)il2cpp_codegen_resolve_icall ("UnityEngine.AssetBundle::LoadAssetWithSubAssetsAsync_Internal(System.String,System.Type)");
	AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* icallRetVal = _il2cpp_icall_func(__this, ___0_name, ___1_type);
	return icallRetVal;
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C void AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6_marshal_pinvoke(const AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6& unmarshaled, AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6_marshaled_pinvoke& marshaled)
{
	marshaled.___m_Ptr = unmarshaled.___m_Ptr;
	marshaled.___m_completeCallback = il2cpp_codegen_marshal_delegate(reinterpret_cast<MulticastDelegate_t*>(unmarshaled.___m_completeCallback));
}
IL2CPP_EXTERN_C void AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6_marshal_pinvoke_back(const AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6_marshaled_pinvoke& marshaled, AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6& unmarshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	intptr_t unmarshaledm_Ptr_temp_0;
	memset((&unmarshaledm_Ptr_temp_0), 0, sizeof(unmarshaledm_Ptr_temp_0));
	unmarshaledm_Ptr_temp_0 = marshaled.___m_Ptr;
	unmarshaled.___m_Ptr = unmarshaledm_Ptr_temp_0;
	unmarshaled.___m_completeCallback = il2cpp_codegen_marshal_function_ptr_to_delegate<Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB>(marshaled.___m_completeCallback, Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB_il2cpp_TypeInfo_var);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___m_completeCallback), (void*)il2cpp_codegen_marshal_function_ptr_to_delegate<Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB>(marshaled.___m_completeCallback, Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB_il2cpp_TypeInfo_var));
}
IL2CPP_EXTERN_C void AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6_marshal_pinvoke_cleanup(AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6_marshaled_pinvoke& marshaled)
{
}
IL2CPP_EXTERN_C void AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6_marshal_com(const AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6& unmarshaled, AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6_marshaled_com& marshaled)
{
	marshaled.___m_Ptr = unmarshaled.___m_Ptr;
	marshaled.___m_completeCallback = il2cpp_codegen_marshal_delegate(reinterpret_cast<MulticastDelegate_t*>(unmarshaled.___m_completeCallback));
}
IL2CPP_EXTERN_C void AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6_marshal_com_back(const AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6_marshaled_com& marshaled, AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6& unmarshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	intptr_t unmarshaledm_Ptr_temp_0;
	memset((&unmarshaledm_Ptr_temp_0), 0, sizeof(unmarshaledm_Ptr_temp_0));
	unmarshaledm_Ptr_temp_0 = marshaled.___m_Ptr;
	unmarshaled.___m_Ptr = unmarshaledm_Ptr_temp_0;
	unmarshaled.___m_completeCallback = il2cpp_codegen_marshal_function_ptr_to_delegate<Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB>(marshaled.___m_completeCallback, Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB_il2cpp_TypeInfo_var);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___m_completeCallback), (void*)il2cpp_codegen_marshal_function_ptr_to_delegate<Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB>(marshaled.___m_completeCallback, Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB_il2cpp_TypeInfo_var));
}
IL2CPP_EXTERN_C void AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6_marshal_com_cleanup(AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6_marshaled_com& marshaled)
{
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AssetBundle_tB38418819A49060CD738CB21541649340F082943* AssetBundleCreateRequest_get_assetBundle_m613FDE589FB86BE1E6920D38ED0706F785D9DB21 (AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6* __this, const RuntimeMethod* method) 
{
	typedef AssetBundle_tB38418819A49060CD738CB21541649340F082943* (*AssetBundleCreateRequest_get_assetBundle_m613FDE589FB86BE1E6920D38ED0706F785D9DB21_ftn) (AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6*);
	static AssetBundleCreateRequest_get_assetBundle_m613FDE589FB86BE1E6920D38ED0706F785D9DB21_ftn _il2cpp_icall_func;
	if (!_il2cpp_icall_func)
	_il2cpp_icall_func = (AssetBundleCreateRequest_get_assetBundle_m613FDE589FB86BE1E6920D38ED0706F785D9DB21_ftn)il2cpp_codegen_resolve_icall ("UnityEngine.AssetBundleCreateRequest::get_assetBundle()");
	AssetBundle_tB38418819A49060CD738CB21541649340F082943* icallRetVal = _il2cpp_icall_func(__this);
	return icallRetVal;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AssetBundleCreateRequest__ctor_mAD1A6314795AC1B548A29A32E01815D33B6D0B46 (AssetBundleCreateRequest_t73B8714B9459A01540E091C3770A408E67188CF6* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundleCreateRequest__ctor_mAD1A6314795AC1B548A29A32E01815D33B6D0B46_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, AssetBundleCreateRequest__ctor_mAD1A6314795AC1B548A29A32E01815D33B6D0B46_RuntimeMethod_var, NULL, NULL, NULL);
	CHECK_PAUSE_POINT;
	{
		AsyncOperation__ctor_m53CF89405A1E2DA6F517D05792826F5784B0D6EC(__this, NULL);
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
IL2CPP_EXTERN_C void AssetBundleRecompressOperation_tFDA1FB5AE1E072FC6CAC1CF0064C13D77F87CDDE_marshal_pinvoke(const AssetBundleRecompressOperation_tFDA1FB5AE1E072FC6CAC1CF0064C13D77F87CDDE& unmarshaled, AssetBundleRecompressOperation_tFDA1FB5AE1E072FC6CAC1CF0064C13D77F87CDDE_marshaled_pinvoke& marshaled)
{
	marshaled.___m_Ptr = unmarshaled.___m_Ptr;
	marshaled.___m_completeCallback = il2cpp_codegen_marshal_delegate(reinterpret_cast<MulticastDelegate_t*>(unmarshaled.___m_completeCallback));
}
IL2CPP_EXTERN_C void AssetBundleRecompressOperation_tFDA1FB5AE1E072FC6CAC1CF0064C13D77F87CDDE_marshal_pinvoke_back(const AssetBundleRecompressOperation_tFDA1FB5AE1E072FC6CAC1CF0064C13D77F87CDDE_marshaled_pinvoke& marshaled, AssetBundleRecompressOperation_tFDA1FB5AE1E072FC6CAC1CF0064C13D77F87CDDE& unmarshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	intptr_t unmarshaledm_Ptr_temp_0;
	memset((&unmarshaledm_Ptr_temp_0), 0, sizeof(unmarshaledm_Ptr_temp_0));
	unmarshaledm_Ptr_temp_0 = marshaled.___m_Ptr;
	unmarshaled.___m_Ptr = unmarshaledm_Ptr_temp_0;
	unmarshaled.___m_completeCallback = il2cpp_codegen_marshal_function_ptr_to_delegate<Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB>(marshaled.___m_completeCallback, Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB_il2cpp_TypeInfo_var);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___m_completeCallback), (void*)il2cpp_codegen_marshal_function_ptr_to_delegate<Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB>(marshaled.___m_completeCallback, Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB_il2cpp_TypeInfo_var));
}
IL2CPP_EXTERN_C void AssetBundleRecompressOperation_tFDA1FB5AE1E072FC6CAC1CF0064C13D77F87CDDE_marshal_pinvoke_cleanup(AssetBundleRecompressOperation_tFDA1FB5AE1E072FC6CAC1CF0064C13D77F87CDDE_marshaled_pinvoke& marshaled)
{
}
IL2CPP_EXTERN_C void AssetBundleRecompressOperation_tFDA1FB5AE1E072FC6CAC1CF0064C13D77F87CDDE_marshal_com(const AssetBundleRecompressOperation_tFDA1FB5AE1E072FC6CAC1CF0064C13D77F87CDDE& unmarshaled, AssetBundleRecompressOperation_tFDA1FB5AE1E072FC6CAC1CF0064C13D77F87CDDE_marshaled_com& marshaled)
{
	marshaled.___m_Ptr = unmarshaled.___m_Ptr;
	marshaled.___m_completeCallback = il2cpp_codegen_marshal_delegate(reinterpret_cast<MulticastDelegate_t*>(unmarshaled.___m_completeCallback));
}
IL2CPP_EXTERN_C void AssetBundleRecompressOperation_tFDA1FB5AE1E072FC6CAC1CF0064C13D77F87CDDE_marshal_com_back(const AssetBundleRecompressOperation_tFDA1FB5AE1E072FC6CAC1CF0064C13D77F87CDDE_marshaled_com& marshaled, AssetBundleRecompressOperation_tFDA1FB5AE1E072FC6CAC1CF0064C13D77F87CDDE& unmarshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	intptr_t unmarshaledm_Ptr_temp_0;
	memset((&unmarshaledm_Ptr_temp_0), 0, sizeof(unmarshaledm_Ptr_temp_0));
	unmarshaledm_Ptr_temp_0 = marshaled.___m_Ptr;
	unmarshaled.___m_Ptr = unmarshaledm_Ptr_temp_0;
	unmarshaled.___m_completeCallback = il2cpp_codegen_marshal_function_ptr_to_delegate<Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB>(marshaled.___m_completeCallback, Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB_il2cpp_TypeInfo_var);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___m_completeCallback), (void*)il2cpp_codegen_marshal_function_ptr_to_delegate<Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB>(marshaled.___m_completeCallback, Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB_il2cpp_TypeInfo_var));
}
IL2CPP_EXTERN_C void AssetBundleRecompressOperation_tFDA1FB5AE1E072FC6CAC1CF0064C13D77F87CDDE_marshal_com_cleanup(AssetBundleRecompressOperation_tFDA1FB5AE1E072FC6CAC1CF0064C13D77F87CDDE_marshaled_com& marshaled)
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
IL2CPP_EXTERN_C void AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_marshal_pinvoke(const AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621& unmarshaled, AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_marshaled_pinvoke& marshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ResourceRequest_tE6953FBA45EAAEFE866C635B9E7852044E62D868____m_Type_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* ___m_TypeException = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '%s' of type '%s': Reference type field marshaling is not supported.", ResourceRequest_tE6953FBA45EAAEFE866C635B9E7852044E62D868____m_Type_FieldInfo_var, AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_0_0_0_var);
	IL2CPP_RAISE_MANAGED_EXCEPTION(___m_TypeException, NULL);
}
IL2CPP_EXTERN_C void AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_marshal_pinvoke_back(const AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_marshaled_pinvoke& marshaled, AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621& unmarshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ResourceRequest_tE6953FBA45EAAEFE866C635B9E7852044E62D868____m_Type_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* ___m_TypeException = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '%s' of type '%s': Reference type field marshaling is not supported.", ResourceRequest_tE6953FBA45EAAEFE866C635B9E7852044E62D868____m_Type_FieldInfo_var, AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_0_0_0_var);
	IL2CPP_RAISE_MANAGED_EXCEPTION(___m_TypeException, NULL);
}
IL2CPP_EXTERN_C void AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_marshal_pinvoke_cleanup(AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_marshaled_pinvoke& marshaled)
{
}
IL2CPP_EXTERN_C void AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_marshal_com(const AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621& unmarshaled, AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_marshaled_com& marshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ResourceRequest_tE6953FBA45EAAEFE866C635B9E7852044E62D868____m_Type_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* ___m_TypeException = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '%s' of type '%s': Reference type field marshaling is not supported.", ResourceRequest_tE6953FBA45EAAEFE866C635B9E7852044E62D868____m_Type_FieldInfo_var, AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_0_0_0_var);
	IL2CPP_RAISE_MANAGED_EXCEPTION(___m_TypeException, NULL);
}
IL2CPP_EXTERN_C void AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_marshal_com_back(const AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_marshaled_com& marshaled, AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621& unmarshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ResourceRequest_tE6953FBA45EAAEFE866C635B9E7852044E62D868____m_Type_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* ___m_TypeException = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '%s' of type '%s': Reference type field marshaling is not supported.", ResourceRequest_tE6953FBA45EAAEFE866C635B9E7852044E62D868____m_Type_FieldInfo_var, AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_0_0_0_var);
	IL2CPP_RAISE_MANAGED_EXCEPTION(___m_TypeException, NULL);
}
IL2CPP_EXTERN_C void AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_marshal_com_cleanup(AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_marshaled_com& marshaled)
{
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* AssetBundleRequest_GetResult_mC1C60D584906835F86BF82C44E8B62B6EB9171D6 (AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* __this, const RuntimeMethod* method) 
{
	typedef Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* (*AssetBundleRequest_GetResult_mC1C60D584906835F86BF82C44E8B62B6EB9171D6_ftn) (AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621*);
	static AssetBundleRequest_GetResult_mC1C60D584906835F86BF82C44E8B62B6EB9171D6_ftn _il2cpp_icall_func;
	if (!_il2cpp_icall_func)
	_il2cpp_icall_func = (AssetBundleRequest_GetResult_mC1C60D584906835F86BF82C44E8B62B6EB9171D6_ftn)il2cpp_codegen_resolve_icall ("UnityEngine.AssetBundleRequest::GetResult()");
	Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* icallRetVal = _il2cpp_icall_func(__this);
	return icallRetVal;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* AssetBundleRequest_get_asset_mE9FDA3900215925371E7D15E7E19AA98713F5D6C (AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundleRequest_get_asset_mE9FDA3900215925371E7D15E7E19AA98713F5D6C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* V_0 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, AssetBundleRequest_get_asset_mE9FDA3900215925371E7D15E7E19AA98713F5D6C_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 182));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 183));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 184));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 185));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 186));
		Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* L_0;
		L_0 = VirtualFuncInvoker0< Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* >::Invoke(4, __this);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 186));
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_AssetBundleModule + 187));
		Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* L_1 = V_0;
		return L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* AssetBundleRequest_get_allAssets_mCA7BF6BCBBDA2E6DF596655254842B5380B4919D (AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* __this, const RuntimeMethod* method) 
{
	typedef ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* (*AssetBundleRequest_get_allAssets_mCA7BF6BCBBDA2E6DF596655254842B5380B4919D_ftn) (AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621*);
	static AssetBundleRequest_get_allAssets_mCA7BF6BCBBDA2E6DF596655254842B5380B4919D_ftn _il2cpp_icall_func;
	if (!_il2cpp_icall_func)
	_il2cpp_icall_func = (AssetBundleRequest_get_allAssets_mCA7BF6BCBBDA2E6DF596655254842B5380B4919D_ftn)il2cpp_codegen_resolve_icall ("UnityEngine.AssetBundleRequest::get_allAssets()");
	ObjectU5BU5D_tD4BF1BEC72A31DF6611C0B8FA3112AF128FC3F8A* icallRetVal = _il2cpp_icall_func(__this);
	return icallRetVal;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AssetBundleRequest__ctor_mD73743E1532E41D8AD2871C00A7FCDA5157171C0 (AssetBundleRequest_tED9F5504E75ED1BCFF8DA9B51F5C7356617E6621* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetBundleRequest__ctor_mD73743E1532E41D8AD2871C00A7FCDA5157171C0_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, AssetBundleRequest__ctor_mD73743E1532E41D8AD2871C00A7FCDA5157171C0_RuntimeMethod_var, NULL, NULL, NULL);
	CHECK_PAUSE_POINT;
	{
		ResourceRequest__ctor_m11F59D90927F0F2598D8776E2CB64CD106D54FAC(__this, NULL);
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
IL2CPP_EXTERN_C void AssetBundleUnloadOperation_tB96802FE8BBAC2B74D933BAF5F502EF9112095FD_marshal_pinvoke(const AssetBundleUnloadOperation_tB96802FE8BBAC2B74D933BAF5F502EF9112095FD& unmarshaled, AssetBundleUnloadOperation_tB96802FE8BBAC2B74D933BAF5F502EF9112095FD_marshaled_pinvoke& marshaled)
{
	marshaled.___m_Ptr = unmarshaled.___m_Ptr;
	marshaled.___m_completeCallback = il2cpp_codegen_marshal_delegate(reinterpret_cast<MulticastDelegate_t*>(unmarshaled.___m_completeCallback));
}
IL2CPP_EXTERN_C void AssetBundleUnloadOperation_tB96802FE8BBAC2B74D933BAF5F502EF9112095FD_marshal_pinvoke_back(const AssetBundleUnloadOperation_tB96802FE8BBAC2B74D933BAF5F502EF9112095FD_marshaled_pinvoke& marshaled, AssetBundleUnloadOperation_tB96802FE8BBAC2B74D933BAF5F502EF9112095FD& unmarshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	intptr_t unmarshaledm_Ptr_temp_0;
	memset((&unmarshaledm_Ptr_temp_0), 0, sizeof(unmarshaledm_Ptr_temp_0));
	unmarshaledm_Ptr_temp_0 = marshaled.___m_Ptr;
	unmarshaled.___m_Ptr = unmarshaledm_Ptr_temp_0;
	unmarshaled.___m_completeCallback = il2cpp_codegen_marshal_function_ptr_to_delegate<Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB>(marshaled.___m_completeCallback, Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB_il2cpp_TypeInfo_var);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___m_completeCallback), (void*)il2cpp_codegen_marshal_function_ptr_to_delegate<Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB>(marshaled.___m_completeCallback, Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB_il2cpp_TypeInfo_var));
}
IL2CPP_EXTERN_C void AssetBundleUnloadOperation_tB96802FE8BBAC2B74D933BAF5F502EF9112095FD_marshal_pinvoke_cleanup(AssetBundleUnloadOperation_tB96802FE8BBAC2B74D933BAF5F502EF9112095FD_marshaled_pinvoke& marshaled)
{
}
IL2CPP_EXTERN_C void AssetBundleUnloadOperation_tB96802FE8BBAC2B74D933BAF5F502EF9112095FD_marshal_com(const AssetBundleUnloadOperation_tB96802FE8BBAC2B74D933BAF5F502EF9112095FD& unmarshaled, AssetBundleUnloadOperation_tB96802FE8BBAC2B74D933BAF5F502EF9112095FD_marshaled_com& marshaled)
{
	marshaled.___m_Ptr = unmarshaled.___m_Ptr;
	marshaled.___m_completeCallback = il2cpp_codegen_marshal_delegate(reinterpret_cast<MulticastDelegate_t*>(unmarshaled.___m_completeCallback));
}
IL2CPP_EXTERN_C void AssetBundleUnloadOperation_tB96802FE8BBAC2B74D933BAF5F502EF9112095FD_marshal_com_back(const AssetBundleUnloadOperation_tB96802FE8BBAC2B74D933BAF5F502EF9112095FD_marshaled_com& marshaled, AssetBundleUnloadOperation_tB96802FE8BBAC2B74D933BAF5F502EF9112095FD& unmarshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	intptr_t unmarshaledm_Ptr_temp_0;
	memset((&unmarshaledm_Ptr_temp_0), 0, sizeof(unmarshaledm_Ptr_temp_0));
	unmarshaledm_Ptr_temp_0 = marshaled.___m_Ptr;
	unmarshaled.___m_Ptr = unmarshaledm_Ptr_temp_0;
	unmarshaled.___m_completeCallback = il2cpp_codegen_marshal_function_ptr_to_delegate<Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB>(marshaled.___m_completeCallback, Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB_il2cpp_TypeInfo_var);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___m_completeCallback), (void*)il2cpp_codegen_marshal_function_ptr_to_delegate<Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB>(marshaled.___m_completeCallback, Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB_il2cpp_TypeInfo_var));
}
IL2CPP_EXTERN_C void AssetBundleUnloadOperation_tB96802FE8BBAC2B74D933BAF5F502EF9112095FD_marshal_com_cleanup(AssetBundleUnloadOperation_tB96802FE8BBAC2B74D933BAF5F502EF9112095FD_marshaled_com& marshaled)
{
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_RuntimeMethod_var, NULL, NULL, NULL);
	CHECK_PAUSE_POINT;
	{
		int32_t L_0 = __this->____stringLength;
		return L_0;
	}
}
