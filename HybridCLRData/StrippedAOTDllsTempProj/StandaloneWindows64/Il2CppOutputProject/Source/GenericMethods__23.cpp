#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif




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
template <typename T1>
struct InvokerActionInvoker1;
template <typename T1>
struct InvokerActionInvoker1<T1*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1)
	{
		void* params[1] = { p1 };
		method->invoker_method(methodPtr, method, obj, params, params[0]);
	}
};
template <typename T1, typename T2>
struct InvokerActionInvoker2;
template <typename T1, typename T2>
struct InvokerActionInvoker2<T1*, T2*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2)
	{
		void* params[2] = { p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, params[1]);
	}
};
template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3;
template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3<T1*, T2*, T3*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2, T3* p3)
	{
		void* params[3] = { p1, p2, p3 };
		method->invoker_method(methodPtr, method, obj, params, params[2]);
	}
};
template <typename R, typename T1>
struct InvokerFuncInvoker1;
template <typename R, typename T1>
struct InvokerFuncInvoker1<R, T1*>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1)
	{
		R ret;
		void* params[1] = { p1 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};
template <typename R, typename T1, typename T2, typename T3>
struct InvokerFuncInvoker3;
template <typename R, typename T1, typename T2, typename T3>
struct InvokerFuncInvoker3<R, T1*, T2*, T3*>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2, T3* p3)
	{
		R ret;
		void* params[3] = { p1, p2, p3 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};
struct ConstrainedActionInvoker0
{
	static inline void Invoke (RuntimeClass* type, const RuntimeMethod* constrainedMethod, void* boxBuffer, void* obj)
	{
		il2cpp_codegen_runtime_constrained_call(type, constrainedMethod, boxBuffer, obj, NULL, NULL);
	}
};
template <typename R>
struct ConstrainedFuncInvoker0
{
	static inline R Invoke (RuntimeClass* type, const RuntimeMethod* constrainedMethod, void* boxBuffer, void* obj)
	{
		R ret;
		il2cpp_codegen_runtime_constrained_call(type, constrainedMethod, boxBuffer, obj, NULL, &ret);
		return ret;
	}
};

struct U3CU3Ec__DisplayClass45_0_1_t3426FDD1940B82C867508C4438EADE01343EC1E0;
struct U3CU3Ec__DisplayClass45_0_1_tA8B40135106B9C75057C689789E8670F2E1B1DC2;
struct U3CU3Ec__DisplayClass45_0_1_tC5DD57B2E5D051E5596DE1A51C9E4425B2A46AA4;
struct Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA;
struct Dictionary_2_t142ECE5B11E3D2798B504FD495B5255E4B384999;
struct Dictionary_2_t46B2DB028096FA2B828359E52F37F3105A83AD83;
struct Dictionary_2_t5C2E7FB7B7937B7B7ED253CCFBCAC0F4529BE070;
struct Dictionary_2_t5C32AF17A5801FB3109E5B0E622BA8402A04E08E;
struct Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77;
struct Dictionary_2_tC4AFDCE8692140598135DC6DC47DAE0316B1B73B;
struct HashSet_1_t880BFA45E1B559D083B73CCDB37486E2A752A6F8;
struct HashSet_1_t8D7DDA2E479996184F65A01093921B4B05F6AAB3;
struct HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885;
struct HashSet_1_t3C714ED4E24C9148451DD03953F8EF7AA4F5E47A;
struct HashSet_1_tEFC6605F7DE53F71946C33FD371E53C3100F2178;
struct HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87;
struct IDictionary_2_t823399AD16F88CDEB25958D8CB61771376A5ADED;
struct IEqualityComparer_1_t2CA7720C7ADCCDECD3B02E45878B4478619D5347;
struct IEqualityComparer_1_t47CC0B235E693652D181B679FF6D61A469ECC122;
struct IEqualityComparer_1_t4DF2A20545E1B70AB7BED5FA55829CE934911AAE;
struct IList_1_t6EE90D273EFCF5E7E4C37FAB712E70BB6F1B4BFF;
struct KeyCollection_tB45A861D090B15129521119AE48ED3813820A974;
struct KeyCollection_tB792ACBAE0B99278B0B7B0F7440B4788E98F0D55;
struct KeyCollection_tA4BB8B89B999710FCC0E56743A2B7C3506295B95;
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D;
struct List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD;
struct List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A;
struct List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5;
struct Predicate_1_t8342C85FF4E41CD1F7024AC0CDC3E5312A32CB12;
struct Predicate_1_tB8E1CB39BCA82FC44F9608B8B75AFA61E47EB81A;
struct ValueCollection_t038245E04B5D2A80048D9F8021A23E69A0C9DBAA;
struct ValueCollection_tC492596681BD51AB34FC76FA76C15C9B3FFB7B40;
struct ValueCollection_t20DCEA743670F431E60622B82ECF0ADE122F8707;
struct downmix_func_1_tF54CFC946A3147244C91F03F0A69E5F14AB8461C;
struct downmix_func_1_t8CB50463E746CCBB4FFAE8EC889A02B92ED9F08B;
struct downmix_func_1_t2D72777593561EEC6CFDD92FFD20BF708F537039;
struct opus_copy_channel_in_func_1_t73990C8C629DA94EEF8E66726DF516DDE7108033;
struct opus_copy_channel_in_func_1_t484D84949EB9FE0FFB9617C739F465DE3E898F3F;
struct opus_copy_channel_in_func_1_tF3C7FBC38C3C10B5DF45A5E2E931749B4708E1B2;
struct opus_copy_channel_out_func_1_t2805945BE854CD39521CBB1514A4097CC0333344;
struct opus_copy_channel_out_func_1_t85951F56EF7450B05E135DF219F8BF05B4D5E030;
struct opus_copy_channel_out_func_1_tF57D8B7B7DB4FBB20B0699A0AEFCD074B6636351;
struct EntryU5BU5D_t1E85CBF91297C9D62A0FC2AD29FD24E33C8A5E54;
struct EntryU5BU5D_tF740C626B28CBB6757BD70F46E0AFB6A991253E3;
struct EntryU5BU5D_t3A16C0F0B7C73AF1072623F52689E362CA9A06F5;
struct SlotU5BU5D_tF596AD324082C553DB364C768406A40BB3C85343;
struct SlotU5BU5D_t2B9148416634BCB8743E1F61254B305F1882FF1D;
struct ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA;
struct Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E;
struct SByteU5BU5DU5BU5D_t9042899DE0306D67CDDEDC06C44CEFAD76730699;
struct SingleU5BU5DU5BU5D_tB190BCEA7F01FD9CFF9FC1273681C9F0C75359E4;
struct AnalysisInfoU5BU5D_t0B98AF2EA580D4245A039DD655F844EEFAD57624;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct FFTStateU5BU5D_t7AA8289EB7D7012973489BF252B0D6BA0CDEC18D;
struct Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct OpusDecoderU5BU5D_t208A6B826C1F7F0CEAEEF2F4D4AA5844540C59D1;
struct OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F;
struct SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913;
struct SideInfoIndicesU5BU5D_t0A640081E82459999C82F2E6805AF91459E7C8B8;
struct SilkChannelEncoderU5BU5D_tBA29067A90CFA762728A1D297853F3661ADD6CA8;
struct SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C;
struct UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA;
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC;
struct CertIDU5BU5D_tAB111E9242A68FDF576EDF0A4C73F23E7DD3C802;
struct AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116;
struct AsymmetricKeyEntry_tCFF238901FF3D148864D369C08411F808A74823A;
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C;
struct BcpgInputStream_tF18B0731823D3F95CDE495105A0F030D52FCF917;
struct BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026;
struct CeltDecoder_t95399694FD55B3B670FB5F17B6DED864F805F3C1;
struct CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F;
struct CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5;
struct ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81;
struct DecControlState_tE48BD82D78873A6621D55F0A1C63C6D9920C5FAB;
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
struct DerObjectIdentifier_tF8C1E5EA899C458D5984B4437815CB2A9DA650E6;
struct EncControlState_t1F753CF3968665C2171A288F862D70168F348019;
struct EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679;
struct IAsyncResult_t7B9B5A0ECB35DCEC31B8A8122C37D687369253B5;
struct MDCTLookup_t1A4D19310C741D19B9223906DB1F8DF9142B47F0;
struct MLP_tA83162012493CDEEA8BA052A456D1F63D93F838F;
struct MethodInfo_t;
struct NLSFCodebook_t66697193682292E885146F5B7E12441B8C92948D;
struct OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D;
struct OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44;
struct OpusMSDecoder_tA24EBFD8B5A8C5D6C12AABAE8403EF562FFBA83A;
struct OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573;
struct OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0;
struct ParameterOverride_t4B8E2A574A094A139B512403B38CE2B594A72A90;
struct PgpObject_tB68A2D2CE41D9D71FF1AD186EAF590BEE8271B77;
struct PgpObjectFactory_t74515C653C2839560F3C5AA5DCCE780F61DB9959;
struct PkixNameConstraintValidator_t37319B18D89CFCC08C6571FA993AB447686380DA;
struct PulseCache_t75AB34328A08825D93209FB10974043D6FD3D6DC;
struct SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37;
struct SideInfoIndices_t0F6EB57DAF75DC84F0F45A84EC8AA6B20F66432B;
struct SilkChannelEncoder_t9D54D1C6FC4B873E9CE81F196A0ACBA6C2A5C4E3;
struct SilkDecoder_tF9133433B06ABBB148CC6377669CF0977FDC6E56;
struct SilkEncoder_t7AB5C2F712CDB92EBFCDAF8E9743C5A39B7CFD6D;
struct SilkLPState_t5574D5F0B72CF9BE0592B53E394EE2B9B5AF1332;
struct SilkNSQState_tEF7DB353A0776C1A7186B49A06559727C7D26EF4;
struct SilkPrefilterState_t74D81627CB998CFCFAE2D542B06464D1FE374D95;
struct SilkResamplerState_t065BE7B78D538D4743A9B581F41B3E729B8213B5;
struct SilkShapeState_t5F2633103E4A2C958A26F00B9C4D6F3ABB9D9736;
struct SilkVADState_t182A6E2529CC4C2076B05777475380B35F3F3E68;
struct StereoEncodeState_t7A3E8E15775C15DF7CA3FA8B9B7F4824DDF22435;
struct StereoWidthState_t6D080EFAD3AC590D3319CE7BA4DDA0132E7822A2;
struct String_t;
struct TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;

IL2CPP_EXTERN_C RuntimeClass* AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* AnimationLayerMixerPlayable_tAD8D28A1E2FB76567E9748CDD11699AEF0B4317D_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* AnimationMixerPlayable_t2984697B87B8719A34519FCF2130545D6D7AB6C0_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* AnimationMotionXToDeltaPlayable_t3946605ADB0B4C054A27B3D65A59F8EB75B6BE18_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* AnimationOffsetPlayable_t39A1B1103995D63650F606BA2EA4ABDF9484AFB4_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* AnimationRemoveScalePlayable_t915611F6D3CC150DDCAF56412AC3E5ACB518A9DD_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Bands_tD5744B61D102D4A0692787D6E9227EC981D1F873_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* CeltCommon_t5CD2203CC4CC8046F30E401748B268C2C42530D1_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* EncControlState_t1F753CF3968665C2171A288F862D70168F348019_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* QuantizeBands_tE23B88063E2F1D6FE379FFF3D12B7E5A351F9284_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C const RuntimeMethod* Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Nullable_1_get_Value_m0DF3B826A745419D26A168689AEB4BE6F8698ECA_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ReadOnlySpan_1_op_Implicit_mCB2B03DD84141A56335B242E9AE355600A05C383_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Span_1__ctor_mE18EBB601FBFA01BA29FE353364700952A9091FE_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91_RuntimeMethod_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;

struct Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct OpusDecoderU5BU5D_t208A6B826C1F7F0CEAEEF2F4D4AA5844540C59D1;
struct OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F;
struct SilkChannelEncoderU5BU5D_tBA29067A90CFA762728A1D297853F3661ADD6CA8;
struct SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C;
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC;
struct CertIDU5BU5D_tAB111E9242A68FDF576EDF0A4C73F23E7DD3C802;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct U3CU3Ec__DisplayClass45_0_1_t3426FDD1940B82C867508C4438EADE01343EC1E0  : public RuntimeObject
{
	RuntimeObject* ___c;
	RuntimeObject* ___k;
};
struct U3CU3Ec__DisplayClass45_0_1_tA8B40135106B9C75057C689789E8670F2E1B1DC2 : public RuntimeObject {};
struct Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	EntryU5BU5D_t1E85CBF91297C9D62A0FC2AD29FD24E33C8A5E54* ____entries;
	int32_t ____count;
	int32_t ____freeList;
	int32_t ____freeCount;
	int32_t ____version;
	RuntimeObject* ____comparer;
	KeyCollection_tB45A861D090B15129521119AE48ED3813820A974* ____keys;
	ValueCollection_t038245E04B5D2A80048D9F8021A23E69A0C9DBAA* ____values;
	RuntimeObject* ____syncRoot;
};
struct Dictionary_2_t5C32AF17A5801FB3109E5B0E622BA8402A04E08E  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	EntryU5BU5D_tF740C626B28CBB6757BD70F46E0AFB6A991253E3* ____entries;
	int32_t ____count;
	int32_t ____freeList;
	int32_t ____freeCount;
	int32_t ____version;
	RuntimeObject* ____comparer;
	KeyCollection_tB792ACBAE0B99278B0B7B0F7440B4788E98F0D55* ____keys;
	ValueCollection_tC492596681BD51AB34FC76FA76C15C9B3FFB7B40* ____values;
	RuntimeObject* ____syncRoot;
};
struct Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	EntryU5BU5D_t3A16C0F0B7C73AF1072623F52689E362CA9A06F5* ____entries;
	int32_t ____count;
	int32_t ____freeList;
	int32_t ____freeCount;
	int32_t ____version;
	RuntimeObject* ____comparer;
	KeyCollection_tA4BB8B89B999710FCC0E56743A2B7C3506295B95* ____keys;
	ValueCollection_t20DCEA743670F431E60622B82ECF0ADE122F8707* ____values;
	RuntimeObject* ____syncRoot;
};
struct HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	SlotU5BU5D_tF596AD324082C553DB364C768406A40BB3C85343* ____slots;
	int32_t ____count;
	int32_t ____lastIndex;
	int32_t ____freeList;
	RuntimeObject* ____comparer;
	int32_t ____version;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ____siInfo;
};
struct HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	SlotU5BU5D_t2B9148416634BCB8743E1F61254B305F1882FF1D* ____slots;
	int32_t ____count;
	int32_t ____lastIndex;
	int32_t ____freeList;
	RuntimeObject* ____comparer;
	int32_t ____version;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ____siInfo;
};
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D  : public RuntimeObject
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A  : public RuntimeObject
{
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5  : public RuntimeObject
{
	CertIDU5BU5D_tAB111E9242A68FDF576EDF0A4C73F23E7DD3C802* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116  : public RuntimeObject
{
	int32_t ___valid;
	float ___tonality;
	float ___tonality_slope;
	float ___noisiness;
	float ___activity;
	float ___music_prob;
	int32_t ___bandwidth;
};
struct BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026  : public RuntimeObject
{
	int32_t ___Val;
};
struct CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5  : public RuntimeObject
{
	int32_t ___Fs;
	int32_t ___overlap;
	int32_t ___nbEBands;
	int32_t ___effEBands;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___preemph;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* ___eBands;
	int32_t ___maxLM;
	int32_t ___nbShortMdcts;
	int32_t ___shortMdctSize;
	int32_t ___nbAllocVectors;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___allocVectors;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* ___logN;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___window;
	MDCTLookup_t1A4D19310C741D19B9223906DB1F8DF9142B47F0* ___mdct;
	PulseCache_t75AB34328A08825D93209FB10974043D6FD3D6DC* ___cache;
};
struct ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81  : public RuntimeObject
{
	int32_t ___nb_channels;
	int32_t ___nb_streams;
	int32_t ___nb_coupled_streams;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___mapping;
};
struct EncControlState_t1F753CF3968665C2171A288F862D70168F348019  : public RuntimeObject
{
	int32_t ___nChannelsAPI;
	int32_t ___nChannelsInternal;
	int32_t ___API_sampleRate;
	int32_t ___maxInternalSampleRate;
	int32_t ___minInternalSampleRate;
	int32_t ___desiredInternalSampleRate;
	int32_t ___payloadSize_ms;
	int32_t ___bitRate;
	int32_t ___packetLossPercentage;
	int32_t ___complexity;
	int32_t ___useInBandFEC;
	int32_t ___useDTX;
	int32_t ___useCBR;
	int32_t ___maxBits;
	int32_t ___toMono;
	int32_t ___opusCanSwitch;
	int32_t ___reducedDependency;
	int32_t ___internalSampleRate;
	int32_t ___allowBandwidthSwitch;
	int32_t ___inWBmodeWithoutVariableLP;
	int32_t ___stereoWidth_Q14;
	int32_t ___switchReady;
};
struct EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679  : public RuntimeObject
{
	uint32_t ___storage;
	uint32_t ___end_offs;
	uint32_t ___end_window;
	int32_t ___nend_bits;
	int32_t ___nbits_total;
	uint32_t ___offs;
	uint32_t ___rng;
	uint32_t ___val;
	uint32_t ___ext;
	int32_t ___rem;
	int32_t ___error;
};
struct MDCTLookup_t1A4D19310C741D19B9223906DB1F8DF9142B47F0  : public RuntimeObject
{
	int32_t ___n;
	int32_t ___maxshift;
	FFTStateU5BU5D_t7AA8289EB7D7012973489BF252B0D6BA0CDEC18D* ___kfft;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* ___trig;
};
struct OpusMSDecoder_tA24EBFD8B5A8C5D6C12AABAE8403EF562FFBA83A  : public RuntimeObject
{
	ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* ___layout;
	OpusDecoderU5BU5D_t208A6B826C1F7F0CEAEEF2F4D4AA5844540C59D1* ___decoders;
};
struct OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0  : public RuntimeObject
{
	uint8_t ___toc;
	int32_t ___nb_frames;
	ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA* ___frames;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___frames_ptrs;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* ___len;
	int32_t ___framesize;
};
struct ParameterOverride_t4B8E2A574A094A139B512403B38CE2B594A72A90  : public RuntimeObject
{
	bool ___overrideState;
};
struct PgpObject_tB68A2D2CE41D9D71FF1AD186EAF590BEE8271B77  : public RuntimeObject
{
};
struct PgpObjectFactory_t74515C653C2839560F3C5AA5DCCE780F61DB9959  : public RuntimeObject
{
	BcpgInputStream_tF18B0731823D3F95CDE495105A0F030D52FCF917* ___bcpgIn;
};
struct Pkcs12Store_tAAFF3FADB8346BBEF21AD4A243AC71B79806D005  : public RuntimeObject
{
	Dictionary_2_t142ECE5B11E3D2798B504FD495B5255E4B384999* ___m_keys;
	List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* ___m_keysOrder;
	Dictionary_2_t46B2DB028096FA2B828359E52F37F3105A83AD83* ___m_localIds;
	Dictionary_2_t5C2E7FB7B7937B7B7ED253CCFBCAC0F4529BE070* ___m_certs;
	List_1_tF470A3BE5C1B5B68E1325EF3F109D172E60BD7CD* ___m_certsOrder;
	Dictionary_2_tC4AFDCE8692140598135DC6DC47DAE0316B1B73B* ___m_chainCerts;
	List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* ___m_chainCertsOrder;
	Dictionary_2_t5C2E7FB7B7937B7B7ED253CCFBCAC0F4529BE070* ___m_keyCerts;
	DerObjectIdentifier_tF8C1E5EA899C458D5984B4437815CB2A9DA650E6* ___keyAlgorithm;
	DerObjectIdentifier_tF8C1E5EA899C458D5984B4437815CB2A9DA650E6* ___keyPrfAlgorithm;
	DerObjectIdentifier_tF8C1E5EA899C458D5984B4437815CB2A9DA650E6* ___certAlgorithm;
	bool ___useDerEncoding;
	bool ___reverseCertificates;
	AsymmetricKeyEntry_tCFF238901FF3D148864D369C08411F808A74823A* ___unmarkedKeyEntry;
};
struct PkixNameConstraintValidator_t37319B18D89CFCC08C6571FA993AB447686380DA  : public RuntimeObject
{
	HashSet_1_t8D7DDA2E479996184F65A01093921B4B05F6AAB3* ___excludedSubtreesDN;
	HashSet_1_tEFC6605F7DE53F71946C33FD371E53C3100F2178* ___excludedSubtreesDns;
	HashSet_1_tEFC6605F7DE53F71946C33FD371E53C3100F2178* ___excludedSubtreesEmail;
	HashSet_1_tEFC6605F7DE53F71946C33FD371E53C3100F2178* ___excludedSubtreesUri;
	HashSet_1_t880BFA45E1B559D083B73CCDB37486E2A752A6F8* ___excludedSubtreesIP;
	HashSet_1_t3C714ED4E24C9148451DD03953F8EF7AA4F5E47A* ___excludedSubtreesOtherName;
	HashSet_1_t8D7DDA2E479996184F65A01093921B4B05F6AAB3* ___permittedSubtreesDN;
	HashSet_1_tEFC6605F7DE53F71946C33FD371E53C3100F2178* ___permittedSubtreesDns;
	HashSet_1_tEFC6605F7DE53F71946C33FD371E53C3100F2178* ___permittedSubtreesEmail;
	HashSet_1_tEFC6605F7DE53F71946C33FD371E53C3100F2178* ___permittedSubtreesUri;
	HashSet_1_t880BFA45E1B559D083B73CCDB37486E2A752A6F8* ___permittedSubtreesIP;
	HashSet_1_t3C714ED4E24C9148451DD03953F8EF7AA4F5E47A* ___permittedSubtreesOtherName;
};
struct PlayableExtensions_t86D67105B499492AE917BF5A7CFBEEEB5FADED7E  : public RuntimeObject
{
};
struct SilkChannelEncoder_t9D54D1C6FC4B873E9CE81F196A0ACBA6C2A5C4E3  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___In_HP_State;
	int32_t ___variable_HP_smth1_Q15;
	int32_t ___variable_HP_smth2_Q15;
	SilkLPState_t5574D5F0B72CF9BE0592B53E394EE2B9B5AF1332* ___sLP;
	SilkVADState_t182A6E2529CC4C2076B05777475380B35F3F3E68* ___sVAD;
	SilkNSQState_tEF7DB353A0776C1A7186B49A06559727C7D26EF4* ___sNSQ;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* ___prev_NLSFq_Q15;
	int32_t ___speech_activity_Q8;
	int32_t ___allow_bandwidth_switch;
	int8_t ___LBRRprevLastGainIndex;
	int8_t ___prevSignalType;
	int32_t ___prevLag;
	int32_t ___pitch_LPC_win_length;
	int32_t ___max_pitch_lag;
	int32_t ___API_fs_Hz;
	int32_t ___prev_API_fs_Hz;
	int32_t ___maxInternal_fs_Hz;
	int32_t ___minInternal_fs_Hz;
	int32_t ___desiredInternal_fs_Hz;
	int32_t ___fs_kHz;
	int32_t ___nb_subfr;
	int32_t ___frame_length;
	int32_t ___subfr_length;
	int32_t ___ltp_mem_length;
	int32_t ___la_pitch;
	int32_t ___la_shape;
	int32_t ___shapeWinLength;
	int32_t ___TargetRate_bps;
	int32_t ___PacketSize_ms;
	int32_t ___PacketLoss_perc;
	int32_t ___frameCounter;
	int32_t ___Complexity;
	int32_t ___nStatesDelayedDecision;
	int32_t ___useInterpolatedNLSFs;
	int32_t ___shapingLPCOrder;
	int32_t ___predictLPCOrder;
	int32_t ___pitchEstimationComplexity;
	int32_t ___pitchEstimationLPCOrder;
	int32_t ___pitchEstimationThreshold_Q16;
	int32_t ___LTPQuantLowComplexity;
	int32_t ___mu_LTP_Q9;
	int32_t ___sum_log_gain_Q7;
	int32_t ___NLSF_MSVQ_Survivors;
	int32_t ___first_frame_after_reset;
	int32_t ___controlled_since_last_payload;
	int32_t ___warping_Q16;
	int32_t ___useCBR;
	int32_t ___prefillFlag;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___pitch_lag_low_bits_iCDF;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___pitch_contour_iCDF;
	NLSFCodebook_t66697193682292E885146F5B7E12441B8C92948D* ___psNLSF_CB;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___input_quality_bands_Q15;
	int32_t ___input_tilt_Q15;
	int32_t ___SNR_dB_Q7;
	SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913* ___VAD_flags;
	int8_t ___LBRR_flag;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___LBRR_flags;
	SideInfoIndices_t0F6EB57DAF75DC84F0F45A84EC8AA6B20F66432B* ___indices;
	SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913* ___pulses;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* ___inputBuf;
	int32_t ___inputBufIx;
	int32_t ___nFramesPerPacket;
	int32_t ___nFramesEncoded;
	int32_t ___nChannelsAPI;
	int32_t ___nChannelsInternal;
	int32_t ___channelNb;
	int32_t ___frames_since_onset;
	int32_t ___ec_prevSignalType;
	int16_t ___ec_prevLagIndex;
	SilkResamplerState_t065BE7B78D538D4743A9B581F41B3E729B8213B5* ___resampler_state;
	int32_t ___useDTX;
	int32_t ___inDTX;
	int32_t ___noSpeechCounter;
	int32_t ___useInBandFEC;
	int32_t ___LBRR_enabled;
	int32_t ___LBRR_GainIncreases;
	SideInfoIndicesU5BU5D_t0A640081E82459999C82F2E6805AF91459E7C8B8* ___indices_LBRR;
	SByteU5BU5DU5BU5D_t9042899DE0306D67CDDEDC06C44CEFAD76730699* ___pulses_LBRR;
	SilkShapeState_t5F2633103E4A2C958A26F00B9C4D6F3ABB9D9736* ___sShape;
	SilkPrefilterState_t74D81627CB998CFCFAE2D542B06464D1FE374D95* ___sPrefilt;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* ___x_buf;
	int32_t ___LTPCorr_Q15;
};
struct SilkEncoder_t7AB5C2F712CDB92EBFCDAF8E9743C5A39B7CFD6D  : public RuntimeObject
{
	SilkChannelEncoderU5BU5D_tBA29067A90CFA762728A1D297853F3661ADD6CA8* ___state_Fxx;
	StereoEncodeState_t7A3E8E15775C15DF7CA3FA8B9B7F4824DDF22435* ___sStereo;
	int32_t ___nBitsUsedLBRR;
	int32_t ___nBitsExceeded;
	int32_t ___nChannelsAPI;
	int32_t ___nChannelsInternal;
	int32_t ___nPrevChannelsInternal;
	int32_t ___timeSinceSwitchAllowed_ms;
	int32_t ___allowBandwidthSwitch;
	int32_t ___prev_decode_only_middle;
};
struct StereoWidthState_t6D080EFAD3AC590D3319CE7BA4DDA0132E7822A2  : public RuntimeObject
{
	int32_t ___XX;
	int32_t ___XY;
	int32_t ___YY;
	int32_t ___smoothed_width;
	int32_t ___max_follower;
};
struct Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199  : public RuntimeObject
{
};
struct TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709  : public RuntimeObject
{
	bool ___enabled;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___angle;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___d_angle;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___d2_angle;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___inmem;
	int32_t ___mem_fill;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___prev_band_tonality;
	float ___prev_tonality;
	SingleU5BU5DU5BU5D_tB190BCEA7F01FD9CFF9FC1273681C9F0C75359E4* ___E;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___lowE;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___highE;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___meanE;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___mem;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___cmean;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___std;
	float ___music_prob;
	float ___Etracker;
	float ___lowECount;
	int32_t ___E_count;
	int32_t ___last_music;
	int32_t ___last_transition;
	int32_t ___count;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___subframe_mem;
	int32_t ___analysis_offset;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___pspeech;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___pmusic;
	float ___speech_confidence;
	float ___music_confidence;
	int32_t ___speech_confidence_count;
	int32_t ___music_confidence_count;
	int32_t ___write_pos;
	int32_t ___read_pos;
	int32_t ___read_subframe;
	AnalysisInfoU5BU5D_t0B98AF2EA580D4245A039DD655F844EEFAD57624* ___info;
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
struct Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8 
{
	HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* ____set;
	int32_t ____index;
	int32_t ____version;
	RuntimeObject* ____current;
};
typedef Il2CppFullySharedGenericStruct Enumerator_t0D36BD6D63D775CDEAF8501F5A252535FFFF52CB;
struct Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 
{
	bool ___hasValue;
	int32_t ___value;
};
struct ParameterOverride_1_tAF4A5BC7953AAC0B47E4048AAF45DE5D46D6F98C  : public ParameterOverride_t4B8E2A574A094A139B512403B38CE2B594A72A90
{
	bool ___value;
};
struct ParameterOverride_1_t9289C5BEA43DBDEDF5862BFE9BF6208D198D3675  : public ParameterOverride_t4B8E2A574A094A139B512403B38CE2B594A72A90
{
	int32_t ___value;
};
struct ParameterOverride_1_tD5562735DCF56E13A6E77D5FCE083DF6E99D5B3D  : public ParameterOverride_t4B8E2A574A094A139B512403B38CE2B594A72A90
{
	RuntimeObject* ___value;
};
struct ParameterOverride_1_tF22AA147D92D52ECA8DCF500194976E7EFCCD27F  : public ParameterOverride_t4B8E2A574A094A139B512403B38CE2B594A72A90
{
	float ___value;
};
struct ParameterOverride_1_tC0878B394E2104ACFBA6CE8629ED7E83346025AA : public ParameterOverride_t4B8E2A574A094A139B512403B38CE2B594A72A90 {};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	uint8_t ___m_value;
};
struct Color_tD001788D726C3A7F1379BEED0260B9591F440C1F 
{
	float ___r;
	float ___g;
	float ___b;
	float ___a;
};
struct Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F 
{
	double ___m_value;
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2  : public ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_pinvoke
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_com
{
};
struct Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175 
{
	int16_t ___m_value;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	float ___m_value;
};
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	uint32_t ___m_value;
};
struct Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 
{
	float ___x;
	float ___y;
};
struct Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 
{
	float ___x;
	float ___y;
	float ___z;
};
struct Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 
{
	float ___x;
	float ___y;
	float ___z;
	float ___w;
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
struct CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 
{
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___m_id;
};
struct CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6_marshaled_pinvoke
{
	Il2CppSafeArray* ___m_id;
};
struct CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6_marshaled_com
{
	Il2CppSafeArray* ___m_id;
};
struct U3CU3Ec__DisplayClass45_0_1_tC5DD57B2E5D051E5596DE1A51C9E4425B2A46AA4  : public RuntimeObject
{
	RuntimeObject* ___c;
	CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 ___k;
};
struct ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC 
{
	intptr_t ____value;
};
struct ByReference_1_t684A5DEB656E6DED2A2A46C6F5AA6B296984D850 
{
	intptr_t ____value;
};
struct ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 
{
	intptr_t ____value;
};
struct ByReference_1_t187A583E432E494CF3EE45BF80D58DB8309BF70A 
{
	intptr_t ____value;
};
struct ByReference_1_t607C1F3BC28B0E21B969461CDB0720FB01A82141 
{
	intptr_t ____value;
};
struct ParameterOverride_1_t32E21FA53107C174D9A77919A9628DA90C84E785  : public ParameterOverride_t4B8E2A574A094A139B512403B38CE2B594A72A90
{
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___value;
};
struct ParameterOverride_1_tD0D241E8B4C5C26C43B7768194903854E4C42061  : public ParameterOverride_t4B8E2A574A094A139B512403B38CE2B594A72A90
{
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___value;
};
struct ParameterOverride_1_t22D7B77092ED927D18B620934135FAAD02002E2A  : public ParameterOverride_t4B8E2A574A094A139B512403B38CE2B594A72A90
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___value;
};
struct ParameterOverride_1_t520B53CC4F37D67D0689376B8F1A4FB1C74D8DC7  : public ParameterOverride_t4B8E2A574A094A139B512403B38CE2B594A72A90
{
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___value;
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
struct DirectorWrapMode_t25EBFAAB0FD6C649DD657C6A0A6EB3FB2ACC1A99 
{
	int32_t ___value__;
};
struct Int32Enum_tCBAC8BA2BFF3A845FA599F303093BBBA374B6F0C 
{
	int32_t ___value__;
};
struct OpusApplication_tA1B721DD3AD4A6A49E43D7FCFC0E9629430E73FA 
{
	int32_t ___value__;
};
struct OpusBandwidth_t16DB83FCF3B881D8A2E0B04D180C7B3B05A1C657 
{
	int32_t ___value__;
};
struct OpusFramesize_tEF9CB53790D0C90B844323DBFFC13673AF3CE748 
{
	int32_t ___value__;
};
struct OpusMode_tE77E1F0A14C92F7DEB23AA4B541F92C1B06A0193 
{
	int32_t ___value__;
};
struct OpusSignal_t1C489C42AB19D9F2F4DB5EE2844A07B9197DA86F 
{
	int32_t ___value__;
};
struct PlayState_tC54D3C31D69D8394457D7EC5712E56B0891A5750 
{
	int32_t ___value__;
};
struct PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E 
{
	intptr_t ___m_Handle;
	uint32_t ___m_Version;
};
struct PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 
{
	intptr_t ___m_Handle;
	uint32_t ___m_Version;
};
struct ParameterOverride_1_t63850BEC32FACF94E47CFF944CF6B58B2543653F  : public ParameterOverride_t4B8E2A574A094A139B512403B38CE2B594A72A90
{
	int32_t ___value;
};
struct ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D 
{
	ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 
{
	ByReference_1_t684A5DEB656E6DED2A2A46C6F5AA6B296984D850 ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D 
{
	ByReference_1_t187A583E432E494CF3EE45BF80D58DB8309BF70A ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC 
{
	ByReference_1_t607C1F3BC28B0E21B969461CDB0720FB01A82141 ____pointer;
	int32_t ____length;
};
struct ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000 
{
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 ___m_Handle;
};
struct Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 
{
	ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC ____pointer;
	int32_t ____length;
};
struct Span_1_tC1B695440A1567664C2665D76D5614739FDF453D 
{
	ByReference_1_t684A5DEB656E6DED2A2A46C6F5AA6B296984D850 ____pointer;
	int32_t ____length;
};
struct Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 
{
	ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 ____pointer;
	int32_t ____length;
};
struct Span_1_t7578EBC2679C3216D7A6FA0DAECAF2256A33CF4C 
{
	ByReference_1_t187A583E432E494CF3EE45BF80D58DB8309BF70A ____pointer;
	int32_t ____length;
};
struct Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54 
{
	ByReference_1_t607C1F3BC28B0E21B969461CDB0720FB01A82141 ____pointer;
	int32_t ____length;
};
struct AnimationLayerMixerPlayable_tAD8D28A1E2FB76567E9748CDD11699AEF0B4317D 
{
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 ___m_Handle;
};
struct AnimationMixerPlayable_t2984697B87B8719A34519FCF2130545D6D7AB6C0 
{
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 ___m_Handle;
};
struct AnimationMotionXToDeltaPlayable_t3946605ADB0B4C054A27B3D65A59F8EB75B6BE18 
{
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 ___m_Handle;
};
struct AnimationOffsetPlayable_t39A1B1103995D63650F606BA2EA4ABDF9484AFB4 
{
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 ___m_Handle;
};
struct AnimationRemoveScalePlayable_t915611F6D3CC150DDCAF56412AC3E5ACB518A9DD 
{
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 ___m_Handle;
};
struct AudioClipPlayable_tD4B758E68CAE03CB0CD31F90C8A3E603B97143A0 
{
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 ___m_Handle;
};
struct AudioMixerPlayable_t6AADDF0C53DF1B4C17969EC24B3B4E4975F3A56C 
{
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 ___m_Handle;
};
struct CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F  : public RuntimeObject
{
	CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* ___mode;
	int32_t ___channels;
	int32_t ___stream_channels;
	int32_t ___force_intra;
	int32_t ___clip;
	int32_t ___disable_pf;
	int32_t ___complexity;
	int32_t ___upsample;
	int32_t ___start;
	int32_t ___end;
	int32_t ___bitrate;
	int32_t ___vbr;
	int32_t ___signalling;
	int32_t ___constrained_vbr;
	int32_t ___loss_rate;
	int32_t ___lsb_depth;
	int32_t ___variable_duration;
	int32_t ___lfe;
	uint32_t ___rng;
	int32_t ___spread_decision;
	int32_t ___delayedIntra;
	int32_t ___tonal_average;
	int32_t ___lastCodedBands;
	int32_t ___hf_average;
	int32_t ___tapset_decision;
	int32_t ___prefilter_period;
	int32_t ___prefilter_gain;
	int32_t ___prefilter_tapset;
	int32_t ___consec_transient;
	AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* ___analysis;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___preemph_memE;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___preemph_memD;
	int32_t ___vbr_reservoir;
	int32_t ___vbr_drift;
	int32_t ___vbr_offset;
	int32_t ___vbr_count;
	int32_t ___overlap_max;
	int32_t ___stereo_saving;
	int32_t ___intensity;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___energy_mask;
	int32_t ___spec_avg;
	Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* ___in_mem;
	Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* ___prefilter_mem;
	Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* ___oldBandE;
	Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* ___oldLogE;
	Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* ___oldLogE2;
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
struct OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D  : public RuntimeObject
{
	int32_t ___channels;
	int32_t ___Fs;
	DecControlState_tE48BD82D78873A6621D55F0A1C63C6D9920C5FAB* ___DecControl;
	int32_t ___decode_gain;
	int32_t ___stream_channels;
	int32_t ___bandwidth;
	int32_t ___mode;
	int32_t ___prev_mode;
	int32_t ___frame_size;
	int32_t ___prev_redundancy;
	int32_t ___last_packet_duration;
	uint32_t ___rangeFinal;
	SilkDecoder_tF9133433B06ABBB148CC6377669CF0977FDC6E56* ___SilkDecoder;
	CeltDecoder_t95399694FD55B3B670FB5F17B6DED864F805F3C1* ___Celt_Decoder;
};
struct OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44  : public RuntimeObject
{
	EncControlState_t1F753CF3968665C2171A288F862D70168F348019* ___silk_mode;
	int32_t ___application;
	int32_t ___channels;
	int32_t ___delay_compensation;
	int32_t ___force_channels;
	int32_t ___signal_type;
	int32_t ___user_bandwidth;
	int32_t ___max_bandwidth;
	int32_t ___user_forced_mode;
	int32_t ___voice_ratio;
	int32_t ___Fs;
	int32_t ___use_vbr;
	int32_t ___vbr_constraint;
	int32_t ___variable_duration;
	int32_t ___bitrate_bps;
	int32_t ___user_bitrate_bps;
	int32_t ___lsb_depth;
	int32_t ___encoder_buffer;
	int32_t ___lfe;
	TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* ___analysis;
	int32_t ___stream_channels;
	int16_t ___hybrid_stereo_width_Q14;
	int32_t ___variable_HP_smth2_Q15;
	int32_t ___prev_HB_gain;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___hp_mem;
	int32_t ___mode;
	int32_t ___prev_mode;
	int32_t ___prev_channels;
	int32_t ___prev_framesize;
	int32_t ___bandwidth;
	int32_t ___silk_bw_switch;
	int32_t ___first;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___energy_masking;
	StereoWidthState_t6D080EFAD3AC590D3319CE7BA4DDA0132E7822A2* ___width_mem;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* ___delay_buffer;
	int32_t ___detected_bandwidth;
	uint32_t ___rangeFinal;
	Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 ____vqLevel;
	SilkEncoder_t7AB5C2F712CDB92EBFCDAF8E9743C5A39B7CFD6D* ___SilkEncoder;
	CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* ___Celt_Encoder;
};
struct OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573  : public RuntimeObject
{
	ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* ___layout;
	int32_t ___lfe_stream;
	int32_t ___application;
	int32_t ___variable_duration;
	int32_t ___surround;
	int32_t ___bitrate_bps;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___subframe_mem;
	OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F* ___encoders;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___window_mem;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___preemph_mem;
};
struct Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F 
{
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 ___m_Handle;
};
struct Predicate_1_t8342C85FF4E41CD1F7024AC0CDC3E5312A32CB12  : public MulticastDelegate_t
{
};
struct Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107  : public MulticastDelegate_t
{
};
struct Predicate_1_tB8E1CB39BCA82FC44F9608B8B75AFA61E47EB81A  : public MulticastDelegate_t
{
};
struct downmix_func_1_tF54CFC946A3147244C91F03F0A69E5F14AB8461C  : public MulticastDelegate_t
{
};
struct downmix_func_1_t8CB50463E746CCBB4FFAE8EC889A02B92ED9F08B  : public MulticastDelegate_t
{
};
struct downmix_func_1_t2D72777593561EEC6CFDD92FFD20BF708F537039  : public MulticastDelegate_t
{
};
struct opus_copy_channel_in_func_1_t73990C8C629DA94EEF8E66726DF516DDE7108033  : public MulticastDelegate_t
{
};
struct opus_copy_channel_in_func_1_t484D84949EB9FE0FFB9617C739F465DE3E898F3F  : public MulticastDelegate_t
{
};
struct opus_copy_channel_in_func_1_tF3C7FBC38C3C10B5DF45A5E2E931749B4708E1B2  : public MulticastDelegate_t
{
};
struct opus_copy_channel_out_func_1_t2805945BE854CD39521CBB1514A4097CC0333344  : public MulticastDelegate_t
{
};
struct opus_copy_channel_out_func_1_t85951F56EF7450B05E135DF219F8BF05B4D5E030  : public MulticastDelegate_t
{
};
struct opus_copy_channel_out_func_1_tF57D8B7B7DB4FBB20B0699A0AEFCD074B6636351  : public MulticastDelegate_t
{
};
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D_StaticFields
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___s_emptyArray;
};
struct List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields
{
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___s_emptyArray;
};
struct List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5_StaticFields
{
	CertIDU5BU5D_tAB111E9242A68FDF576EDF0A4C73F23E7DD3C802* ___s_emptyArray;
};
struct CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5_StaticFields
{
	CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* ___mode48000_960_120;
};
struct EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679_StaticFields
{
	UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA* ___correction;
};
struct PkixNameConstraintValidator_t37319B18D89CFCC08C6571FA993AB447686380DA_StaticFields
{
	DerObjectIdentifier_tF8C1E5EA899C458D5984B4437815CB2A9DA650E6* ___SerialNumberOid;
};
struct Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_StaticFields
{
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___dct_table;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___analysis_window;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___tbands;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___extra_bands;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___weights;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___topo;
	MLP_tA83162012493CDEEA8BA052A456D1F63D93F838F* ___net;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___tansig_table;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___mono_voice_bandwidth_thresholds;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___mono_music_bandwidth_thresholds;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___stereo_voice_bandwidth_thresholds;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___stereo_music_bandwidth_thresholds;
	Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* ___mode_thresholds;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct IntPtr_t_StaticFields
{
	intptr_t ___Zero;
};
struct Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7_StaticFields
{
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___zeroVector;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___oneVector;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___upVector;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___downVector;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___leftVector;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___rightVector;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___positiveInfinityVector;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___negativeInfinityVector;
};
struct Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_StaticFields
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___zeroVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___oneVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___upVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___downVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___leftVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___rightVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___forwardVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___backVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___positiveInfinityVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___negativeInfinityVector;
};
struct Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_StaticFields
{
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___zeroVector;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___oneVector;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___positiveInfinityVector;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___negativeInfinityVector;
};
struct PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_StaticFields
{
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 ___m_Null;
};
struct ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000_StaticFields
{
	ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000 ___m_NullPlayable;
};
struct AnimationLayerMixerPlayable_tAD8D28A1E2FB76567E9748CDD11699AEF0B4317D_StaticFields
{
	AnimationLayerMixerPlayable_tAD8D28A1E2FB76567E9748CDD11699AEF0B4317D ___m_NullPlayable;
};
struct AnimationMixerPlayable_t2984697B87B8719A34519FCF2130545D6D7AB6C0_StaticFields
{
	AnimationMixerPlayable_t2984697B87B8719A34519FCF2130545D6D7AB6C0 ___m_NullPlayable;
};
struct AnimationMotionXToDeltaPlayable_t3946605ADB0B4C054A27B3D65A59F8EB75B6BE18_StaticFields
{
	AnimationMotionXToDeltaPlayable_t3946605ADB0B4C054A27B3D65A59F8EB75B6BE18 ___m_NullPlayable;
};
struct AnimationOffsetPlayable_t39A1B1103995D63650F606BA2EA4ABDF9484AFB4_StaticFields
{
	AnimationOffsetPlayable_t39A1B1103995D63650F606BA2EA4ABDF9484AFB4 ___m_NullPlayable;
};
struct AnimationRemoveScalePlayable_t915611F6D3CC150DDCAF56412AC3E5ACB518A9DD_StaticFields
{
	AnimationRemoveScalePlayable_t915611F6D3CC150DDCAF56412AC3E5ACB518A9DD ___m_NullPlayable;
};
struct OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D_StaticFields
{
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___SILENCE;
};
struct OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44_StaticFields
{
	Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* ___vqTable;
};
struct OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_StaticFields
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___diff_table;
};
struct Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_StaticFields
{
	Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___m_NullPlayable;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
struct Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB  : public RuntimeArray
{
	ALIGN_FIELD (8) int16_t m_Items[1];

	inline int16_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline int16_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, int16_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline int16_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline int16_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, int16_t value)
	{
		m_Items[index] = value;
	}
};
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
struct Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E  : public RuntimeArray
{
	ALIGN_FIELD (8) Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* m_Items[1];

	inline Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C  : public RuntimeArray
{
	ALIGN_FIELD (8) float m_Items[1];

	inline float GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline float* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, float value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline float GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline float* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, float value)
	{
		m_Items[index] = value;
	}
};
struct SilkChannelEncoderU5BU5D_tBA29067A90CFA762728A1D297853F3661ADD6CA8  : public RuntimeArray
{
	ALIGN_FIELD (8) SilkChannelEncoder_t9D54D1C6FC4B873E9CE81F196A0ACBA6C2A5C4E3* m_Items[1];

	inline SilkChannelEncoder_t9D54D1C6FC4B873E9CE81F196A0ACBA6C2A5C4E3* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline SilkChannelEncoder_t9D54D1C6FC4B873E9CE81F196A0ACBA6C2A5C4E3** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, SilkChannelEncoder_t9D54D1C6FC4B873E9CE81F196A0ACBA6C2A5C4E3* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline SilkChannelEncoder_t9D54D1C6FC4B873E9CE81F196A0ACBA6C2A5C4E3* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline SilkChannelEncoder_t9D54D1C6FC4B873E9CE81F196A0ACBA6C2A5C4E3** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, SilkChannelEncoder_t9D54D1C6FC4B873E9CE81F196A0ACBA6C2A5C4E3* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC  : public RuntimeArray
{
	ALIGN_FIELD (8) uint8_t m_Items[1];

	inline uint8_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + il2cpp_array_calc_byte_offset(this, index);
	}
	inline uint8_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + il2cpp_array_calc_byte_offset(this, index);
	}
};
struct OpusDecoderU5BU5D_t208A6B826C1F7F0CEAEEF2F4D4AA5844540C59D1  : public RuntimeArray
{
	ALIGN_FIELD (8) OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* m_Items[1];

	inline OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F  : public RuntimeArray
{
	ALIGN_FIELD (8) OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* m_Items[1];

	inline OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
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
struct CertIDU5BU5D_tAB111E9242A68FDF576EDF0A4C73F23E7DD3C802  : public RuntimeArray
{
	ALIGN_FIELD (8) CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 m_Items[1];

	inline CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_id), (void*)NULL);
	}
	inline CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_id), (void*)NULL);
	}
};


IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_gshared_inline (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Analysis_run_analysis_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m69F1371361914F4F1CD53BB2A4948DCACFC8A738_gshared (TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* ___0_analysis, CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* ___1_celt_mode, ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D ___2_analysis_pcm, int32_t ___3_analysis_frame_size, int32_t ___4_frame_size, int32_t ___5_c1, int32_t ___6_c2, int32_t ___7_C, int32_t ___8_Fs, int32_t ___9_lsb_depth, downmix_func_1_t8CB50463E746CCBB4FFAE8EC889A02B92ED9F08B* ___10_downmix, AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* ___11_analysis_info, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Nullable_1_get_Value_m0DF3B826A745419D26A168689AEB4BE6F8698ECA_gshared (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91_gshared (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_array, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D ReadOnlySpan_1_op_Implicit_m34F703695513C3D0AA303A14106E72DD7455C2F1_gshared (SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___0_array, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusEncoder_opus_encode_native_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_mEC592DA223E634EAE136DDFFF74F938B95E398F1_gshared (OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* __this, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 ___0_pcm, int32_t ___1_pcm_ptr, int32_t ___2_frame_size, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___3_data, int32_t ___4_data_ptr, int32_t ___5_out_data_bytes, int32_t ___6_lsb_depth, ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D ___7_analysis_pcm, int32_t ___8_analysis_size, int32_t ___9_c1, int32_t ___10_c2, int32_t ___11_analysis_channels, downmix_func_1_t8CB50463E746CCBB4FFAE8EC889A02B92ED9F08B* ___12_downmix, int32_t ___13_float_api, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tC1B695440A1567664C2665D76D5614739FDF453D Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_gshared (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* ___0_array, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_gshared_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, int32_t ___0_start, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mE18EBB601FBFA01BA29FE353364700952A9091FE_gshared_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_gshared_inline (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void opus_copy_channel_out_func_1_Invoke_m25EF632F19B8D56B7FB9C58D141E42FED126F81D_gshared_inline (opus_copy_channel_out_func_1_t2805945BE854CD39521CBB1514A4097CC0333344* __this, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D ___0_dst, int32_t ___1_dst_stride, int32_t ___2_dst_channel, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D ___3_src, int32_t ___4_src_ptr, int32_t ___5_src_stride, int32_t ___6_frame_size, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void opus_copy_channel_out_func_1_Invoke_mB9C23E8CD1EED40F2F28F55B16E7F42E95D95441_gshared_inline (opus_copy_channel_out_func_1_t85951F56EF7450B05E135DF219F8BF05B4D5E030* __this, Span_1_t7578EBC2679C3216D7A6FA0DAECAF2256A33CF4C ___0_dst, int32_t ___1_dst_stride, int32_t ___2_dst_channel, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D ___3_src, int32_t ___4_src_ptr, int32_t ___5_src_stride, int32_t ___6_frame_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CodecHelpers_compute_frame_size_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m383EA214DC0D0ABD3988FC7C148510734632BF0E_gshared (ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 ___0_analysis_pcm, int32_t ___1_frame_size, int32_t ___2_variable_duration, int32_t ___3_C, int32_t ___4_Fs, int32_t ___5_bitrate_bps, int32_t ___6_delay_compensation, downmix_func_1_tF54CFC946A3147244C91F03F0A69E5F14AB8461C* ___7_downmix, SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___8_subframe_mem, bool ___9_analysis_enabled, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OpusMSEncoder_surround_analysis_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m6704E92CF00A6B3ECE45AA3E065DAA70429B4918_gshared (CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* ___0_celt_mode, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 ___1_pcm, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___2_bandLogE, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___3_mem, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___4_preemph_mem, int32_t ___5_len, int32_t ___6_overlap, int32_t ___7_channels, int32_t ___8_rate, opus_copy_channel_in_func_1_t73990C8C629DA94EEF8E66726DF516DDE7108033* ___9_copy_channel_in, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void opus_copy_channel_in_func_1_Invoke_mE863D518D4E113322D44FEBB0E6A4112575A199E_gshared_inline (opus_copy_channel_in_func_1_t73990C8C629DA94EEF8E66726DF516DDE7108033* __this, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D ___0_dst, int32_t ___1_dst_ptr, int32_t ___2_dst_stride, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 ___3_src, int32_t ___4_src_stride, int32_t ___5_src_channel, int32_t ___6_frame_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 ReadOnlySpan_1_op_Implicit_mCB2B03DD84141A56335B242E9AE355600A05C383_gshared (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* ___0_array, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusEncoder_opus_encode_native_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m66C341F34A3F47A261A454C4DD185BE1507C02E5_gshared (OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* __this, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 ___0_pcm, int32_t ___1_pcm_ptr, int32_t ___2_frame_size, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___3_data, int32_t ___4_data_ptr, int32_t ___5_out_data_bytes, int32_t ___6_lsb_depth, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 ___7_analysis_pcm, int32_t ___8_analysis_size, int32_t ___9_c1, int32_t ___10_c2, int32_t ___11_analysis_channels, downmix_func_1_tF54CFC946A3147244C91F03F0A69E5F14AB8461C* ___12_downmix, int32_t ___13_float_api, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CodecHelpers_compute_frame_size_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_mC29E99157EBE887241410699A4D42C0B53FC4F5D_gshared (ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D ___0_analysis_pcm, int32_t ___1_frame_size, int32_t ___2_variable_duration, int32_t ___3_C, int32_t ___4_Fs, int32_t ___5_bitrate_bps, int32_t ___6_delay_compensation, downmix_func_1_t8CB50463E746CCBB4FFAE8EC889A02B92ED9F08B* ___7_downmix, SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___8_subframe_mem, bool ___9_analysis_enabled, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OpusMSEncoder_surround_analysis_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m9B9E4738B7BD6EEABF4D6378222B971D6775D65B_gshared (CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* ___0_celt_mode, ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D ___1_pcm, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___2_bandLogE, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___3_mem, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___4_preemph_mem, int32_t ___5_len, int32_t ___6_overlap, int32_t ___7_channels, int32_t ___8_rate, opus_copy_channel_in_func_1_t484D84949EB9FE0FFB9617C739F465DE3E898F3F* ___9_copy_channel_in, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void opus_copy_channel_in_func_1_Invoke_m6D03E61EA06F045BA121921DC606E861E540D67D_gshared_inline (opus_copy_channel_in_func_1_t484D84949EB9FE0FFB9617C739F465DE3E898F3F* __this, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D ___0_dst, int32_t ___1_dst_ptr, int32_t ___2_dst_stride, ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D ___3_src, int32_t ___4_src_stride, int32_t ___5_src_channel, int32_t ___6_frame_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8_gshared (int32_t ___0_x, int32_t ___1_y, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC_gshared (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_array, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Clear_mCFB5EA7351D5860D2B91592B91A84CA265A41433_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Clear_m16C1F2C61FED5955F10EB36BC1CB2DF34B128994_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Clear_m8B10E39C816C1A55D0DBCE1F83E06212561DEBE8_gshared (Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Clear_m6357ACBCD4516CB4B5CE08FB7CAB85FA8F1E29A3_gshared_inline (List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_ContainsKey_m703047C213F7AB55C9DC346596287773A1F670CD_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_get_Comparer_m29B8217F824FC30BC2DE82EDA9759C0CD5EE6063_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pkcs12Store_RemoveOrdering_TisRuntimeObject_m6075B9C982D468D5CBE405DF6D523C6FAB17169A_gshared (RuntimeObject* ___0_c, List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ___1_o, RuntimeObject* ___2_k, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_m1A840355E8EDAECEA9D0C6F5E51B248FAA449CBD_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_ContainsKey_m99A920E5F0A5E4DC6D9BA3CE06457A7D6886EF30_gshared (Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77* __this, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_get_Comparer_m62BC32ED557CC6C4B8D17CDDE089026A5FA2C635_gshared (Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pkcs12Store_RemoveOrdering_TisCertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6_mDAEDA60DC524912A0C27C1517478835FD2344AD7_gshared (RuntimeObject* ___0_c, List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* ___1_o, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 ___2_k, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mB2B488D34F1A96DF5D4A58A40374FC84B4B2A377_gshared_inline (List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* __this, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_m8D95E96F74963AC7C0BD8CFBEB6B7564C4DE87D6_gshared (Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77* __this, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m5C7C45E75D951A75843F3F7AADD56ECD64F6BC86_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m79A129C6C90F1F53B80189D35F54E5C5765308D9_gshared (Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77* __this, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CollectionUtilities_Remove_TisRuntimeObject_TisRuntimeObject_m130B6F4F89CFE4220CCC1BC3C572BD22F33A4D03_gshared (RuntimeObject* ___0_d, RuntimeObject* ___1_k, RuntimeObject** ___2_v, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__DisplayClass45_0_1__ctor_m6ECC37F4DD01881E15CDB2E0E861E057EEE4D038_gshared (U3CU3Ec__DisplayClass45_0_1_t3426FDD1940B82C867508C4438EADE01343EC1E0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Predicate_1__ctor_m3E007299121A15DF80F4A210FF8C20E5DF688F20_gshared (Predicate_1_t8342C85FF4E41CD1F7024AC0CDC3E5312A32CB12* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m9875FFE328FA833B2617915FF976DEDA4724EBC3_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, Predicate_1_t8342C85FF4E41CD1F7024AC0CDC3E5312A32CB12* ___0_match, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m54F62297ADEE4D4FDA697F49ED807BF901201B54_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__DisplayClass45_0_1__ctor_m29E8FD1000EF0300B33971C6137E44B8FAD2CE24_gshared (U3CU3Ec__DisplayClass45_0_1_tC5DD57B2E5D051E5596DE1A51C9E4425B2A46AA4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Predicate_1__ctor_mB25D862104E995A05A4ADDDB9B6E5D1248C707B0_gshared (Predicate_1_tB8E1CB39BCA82FC44F9608B8B75AFA61E47EB81A* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mA44D25D71BF94D4C389465BD8BE3139D18000A3D_gshared (List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* __this, Predicate_1_tB8E1CB39BCA82FC44F9608B8B75AFA61E47EB81A* ___0_match, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m3EA20C82CFE1BDDD044B4C273F9DA16237A8EEFA_gshared (List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t HashSet_1_get_Count_m41CC85EEB7855CEFA3BC7A32F115387939318ED3_gshared_inline (HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8 HashSet_1_GetEnumerator_m143B98FEED7E9CABA2C494AB2F04DAD60A504635_gshared (HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator_Dispose_mFB582AEAA2E73F3128B5571197BEDE256A83F657_gshared (Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Enumerator_get_Current_m139A176CD271A0532D75BE08DA7831C8C45CE28F_gshared_inline (Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HashSet_1_Contains_m9BACE52BFA0BD83C601529D3629118453E459BBB_gshared (HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_m27565F5ACCCC75C3DD34CC4CAE3E6AEFEB9144A6_gshared (Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool PlayableHandle_IsPlayableOfType_TisAudioClipPlayable_tD4B758E68CAE03CB0CD31F90C8A3E603B97143A0_m95809D16DD3494AEB0E9E652B42E0CE3167BEE0E_gshared (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Playable_IsPlayableOfType_TisAudioClipPlayable_tD4B758E68CAE03CB0CD31F90C8A3E603B97143A0_m94FCB00FCEC927F1EAB530CFEC8EE9CCB388CF8A_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool PlayableHandle_IsPlayableOfType_TisAudioMixerPlayable_t6AADDF0C53DF1B4C17969EC24B3B4E4975F3A56C_m28F89BE3D7CCE69B28258CC5B1C7D4E814F48CAB_gshared (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Playable_IsPlayableOfType_TisAudioMixerPlayable_t6AADDF0C53DF1B4C17969EC24B3B4E4975F3A56C_m61519D5329775A9F560D019477CAF48C17777D62_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Playable_IsPlayableOfType_TisIl2CppFullySharedGenericStruct_m295C4DE8654EB520ABA0C31EAF1E01D89A770DDB_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 ScriptPlayable_1_GetHandle_mFBB086A8188A0D77BB5CF4A1A03031EA9B67D22A_gshared (ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m947BF95D54571BF3897F96822B7A8FDA5853497B_gshared_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, uint8_t* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_mA5D746142AF298C8C2B2EBC5EBC337E78F81F1F8_gshared (List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* __this, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 ___0_item, const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntropyCoder__ctor_m94DD0C4B87D72A98041935C6879744E5FBF72E73 (EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AnalysisInfo__ctor_m9F52F6126A6EB1E81FD9A18DF4B9E24F357D782E (AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* CeltEncoder_GetMode_m51534658A97582FB288A8023F6AA133BFBB8AC1F_inline (CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* __this, const RuntimeMethod* method) ;
inline bool Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_inline (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28*, const RuntimeMethod*))Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_gshared_inline)(__this, method);
}
inline void Analysis_run_analysis_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m69F1371361914F4F1CD53BB2A4948DCACFC8A738 (TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* ___0_analysis, CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* ___1_celt_mode, ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D ___2_analysis_pcm, int32_t ___3_analysis_frame_size, int32_t ___4_frame_size, int32_t ___5_c1, int32_t ___6_c2, int32_t ___7_C, int32_t ___8_Fs, int32_t ___9_lsb_depth, downmix_func_1_t8CB50463E746CCBB4FFAE8EC889A02B92ED9F08B* ___10_downmix, AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* ___11_analysis_info, const RuntimeMethod* method)
{
	((  void (*) (TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709*, CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5*, ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, downmix_func_1_t8CB50463E746CCBB4FFAE8EC889A02B92ED9F08B*, AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116*, const RuntimeMethod*))Analysis_run_analysis_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m69F1371361914F4F1CD53BB2A4948DCACFC8A738_gshared)(___0_analysis, ___1_celt_mode, ___2_analysis_pcm, ___3_analysis_frame_size, ___4_frame_size, ___5_c1, ___6_c2, ___7_C, ___8_Fs, ___9_lsb_depth, ___10_downmix, ___11_analysis_info, method);
}
inline int32_t Nullable_1_get_Value_m0DF3B826A745419D26A168689AEB4BE6F8698ECA (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28*, const RuntimeMethod*))Nullable_1_get_Value_m0DF3B826A745419D26A168689AEB4BE6F8698ECA_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusEncoder_GetVariableQualityBitrate_m6FFBB73E7634B913CF7E2CC60B9076164F1FD0F0 (int32_t ___0_vqLevel, float ___1_music_prob, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CodecHelpers_compute_stereo_width_mA9CC3FA2171877D74ABBB105235A850A5719949E (ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 ___0_pcm, int32_t ___1_pcm_ptr, int32_t ___2_frame_size, int32_t ___3_Fs, StereoWidthState_t6D080EFAD3AC590D3319CE7BA4DDA0132E7822A2* ___4_mem, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusEncoder_user_bitrate_to_bitrate_m18DBA826BE2FA33650295C2A6CD39A9E9C8D683F (OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* __this, int32_t ___0_user_bitrate, int32_t ___1_frame_size, int32_t ___2_max_data_bytes, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t CodecHelpers_gen_toc_m55919D0EC27589F5328AD925AA91F8B0D4A9EBA2 (int32_t ___0_mode, int32_t ___1_framerate, int32_t ___2_bandwidth, int32_t ___3_channels, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusRepacketizer_PadPacket_m31BC672C1100238AAE7DF0EEC74000D8CD39AD8E (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___0_data, int32_t ___1_data_offset, int32_t ___2_len, int32_t ___3_new_len, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_MULT16_32_Q15_m26878C33EF631092FEDA6A0054F6B2C0D0B256B2_inline (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EncControlState__ctor_mCAD689C6947CC4E7B25982B1948387269E41363C (EncControlState_t1F753CF3968665C2171A288F862D70168F348019* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t EncodeAPI_silk_InitEncoder_m09EF9258259F34A9CE9707CB9463B3CA9C3D4B42 (SilkEncoder_t7AB5C2F712CDB92EBFCDAF8E9743C5A39B7CFD6D* ___0_encState, EncControlState_t1F753CF3968665C2171A288F862D70168F348019* ___1_encStatus, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusBandwidthHelpers_MIN_m35CCCD819EE4224365BF648B953A8ADC347EA987 (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusBandwidthHelpers_MAX_mF31797F605DA051DD3FB61542A8C376114316B83 (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CeltEncoder_SetLSBDepth_mB8EDAF4F6B3646DDDFCA55BB31B350F8CAACCEE9 (CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OpusRepacketizer__ctor_mC4456456D2AAD30181CA3EC5FF721E31477B6996 (OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* __this, const RuntimeMethod* method) ;
inline Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91 (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_array, const RuntimeMethod* method)
{
	return ((  Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 (*) (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*, const RuntimeMethod*))Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91_gshared)(___0_array, method);
}
inline ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D ReadOnlySpan_1_op_Implicit_m34F703695513C3D0AA303A14106E72DD7455C2F1 (SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___0_array, const RuntimeMethod* method)
{
	return ((  ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D (*) (SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C*, const RuntimeMethod*))ReadOnlySpan_1_op_Implicit_m34F703695513C3D0AA303A14106E72DD7455C2F1_gshared)(___0_array, method);
}
inline int32_t OpusEncoder_opus_encode_native_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_mEC592DA223E634EAE136DDFFF74F938B95E398F1 (OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* __this, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 ___0_pcm, int32_t ___1_pcm_ptr, int32_t ___2_frame_size, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___3_data, int32_t ___4_data_ptr, int32_t ___5_out_data_bytes, int32_t ___6_lsb_depth, ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D ___7_analysis_pcm, int32_t ___8_analysis_size, int32_t ___9_c1, int32_t ___10_c2, int32_t ___11_analysis_channels, downmix_func_1_t8CB50463E746CCBB4FFAE8EC889A02B92ED9F08B* ___12_downmix, int32_t ___13_float_api, const RuntimeMethod* method)
{
	return ((  int32_t (*) (OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44*, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71, int32_t, int32_t, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305, int32_t, int32_t, int32_t, ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D, int32_t, int32_t, int32_t, int32_t, downmix_func_1_t8CB50463E746CCBB4FFAE8EC889A02B92ED9F08B*, int32_t, const RuntimeMethod*))OpusEncoder_opus_encode_native_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_mEC592DA223E634EAE136DDFFF74F938B95E398F1_gshared)(__this, ___0_pcm, ___1_pcm_ptr, ___2_frame_size, ___3_data, ___4_data_ptr, ___5_out_data_bytes, ___6_lsb_depth, ___7_analysis_pcm, ___8_analysis_size, ___9_c1, ___10_c2, ___11_analysis_channels, ___12_downmix, ___13_float_api, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusRepacketizer_AddPacket_mEF0C260D9D7AF7EE2243A598509FBE6197D0F510 (OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* __this, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___0_data, int32_t ___1_data_offset, int32_t ___2_len, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusRepacketizer_opus_repacketizer_out_range_impl_m580835FE0C1A5F8831B645CF5488B8ED9E443F13 (OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* __this, int32_t ___0_begin, int32_t ___1_end, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___2_data, int32_t ___3_data_ptr, int32_t ___4_maxlen, int32_t ___5_self_delimited, int32_t ___6_pad, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntropyCoder_enc_init_m0C80505BF71E0CAF14DAF6DCD1E2FA384F3B2C1D (EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* __this, uint32_t ___0__size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Arrays_MemCopy_m6694E7C365EE590A29753D43699215FBC8162E89 (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* ___0_src, int32_t ___1_src_idx, Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* ___2_dst, int32_t ___3_dst_idx, int32_t ___4_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_lin2log_m3D1BBF1C15B7B47836676F7D48D1DB73DF4B887C_inline (int32_t ___0_inLin, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_LSHIFT_mE90E3163A0D3526D05046763E167F2271AB0B953_inline (int32_t ___0_a, int32_t ___1_shift, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_SMLAWB_m8A023DCCC323ED0EB2CCF43D6ED6357B587EAAD2_inline (int32_t ___0_a32, int32_t ___1_b32, int32_t ___2_c32, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_RSHIFT_m0ACD93ACB5B27378849FAD9F6440B867FA755103_inline (int32_t ___0_a, int32_t ___1_shift, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_log2lin_mFB61AF160BBA8A179F17F7B375639DDCEDA19090_inline (int32_t ___0_inLog_Q7, const RuntimeMethod* method) ;
inline Span_1_tC1B695440A1567664C2665D76D5614739FDF453D Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* ___0_array, const RuntimeMethod* method)
{
	return ((  Span_1_tC1B695440A1567664C2665D76D5614739FDF453D (*) (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*, const RuntimeMethod*))Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_gshared)(___0_array, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CodecHelpers_hp_cutoff_mB1C77C6709A6092DB5B4E0270AE636F585114D48 (ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 ___0_input, int32_t ___1_input_ptr, int32_t ___2_cutoff_Hz, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D ___3_output, int32_t ___4_output_ptr, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___5_hp_mem, int32_t ___6_len, int32_t ___7_channels, int32_t ___8_Fs, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CodecHelpers_dc_reject_m66023F849A9C35E040B2DDA37ABF9A793F476ABE (ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 ___0_input, int32_t ___1_input_ptr, int32_t ___2_cutoff_Hz, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D ___3_output, int32_t ___4_output_ptr, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___5_hp_mem, int32_t ___6_len, int32_t ___7_channels, int32_t ___8_Fs, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_SHL32_m759CE9A6D5B83434728CB2C33BA4320DFACBD900_inline (int32_t ___0_a, int32_t ___1_shift, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_SHR32_mE532A866351E7866B6A1BAD8A8E9306DE22AE05F_inline (int32_t ___0_a, int32_t ___1_shift, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_MIN16_mD65F33577C97F96B9FE9B2540589BA7FADF52F5E_inline (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_MAX16_m4D603BAD0F242EB66ED76BE982BC3907D9DF44A5_inline (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_HALF16_mCC975475CB9BE63D15752AA7AA0F3E44598ADB4D_inline (int32_t ___0_x, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_MULT16_16_m86CC5979188CE7184708F6DC86E20F35D4501777_inline (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_PSHR32_m795531FF9BB2EDD62D70EC3925DC6CA0F8B50983_inline (int32_t ___0_a, int32_t ___1_shift, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_MAX32_m603F38A48C71C4DF8E2938A811D591A5B3485B65_inline (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_IMAX_mFECDD1F5C3C0962AF8B0140E78A6C3A25BCF9C23_inline (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BoxedValueInt__ctor_m6EC58F06F4673535F2682F1731C6F36FC073A36A (BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* __this, int32_t ___0_v, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CodecHelpers_gain_fade_mB38DEC7BAD27021D38F3577722DFB025B8657774 (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* ___0_buffer, int32_t ___1_buf_ptr, int32_t ___2_g1, int32_t ___3_g2, int32_t ___4_overlap48, int32_t ___5_frame_size, int32_t ___6_channels, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___7_window, int32_t ___8_Fs, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Arrays_MemSetShort_m8C49EA240FDBFE594D42AEB7C682C4B48683D01E (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* ___0_array, int16_t ___1_value, int32_t ___2_length, const RuntimeMethod* method) ;
inline Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, int32_t ___0_start, const RuntimeMethod* method)
{
	return ((  Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 (*) (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305*, int32_t, const RuntimeMethod*))Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_gshared_inline)(__this, ___0_start, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t EncodeAPI_silk_Encode_m03CA6F3640C38ACB077A8718E63B9AF31C2F73DC (SilkEncoder_t7AB5C2F712CDB92EBFCDAF8E9743C5A39B7CFD6D* ___0_psEnc, EncControlState_t1F753CF3968665C2171A288F862D70168F348019* ___1_encControl, Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* ___2_samplesIn, int32_t ___3_nSamplesIn, EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* ___4_psRangeEnc, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___5_encodedDataOut, BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* ___6_nBytesOut, int32_t ___7_prefillFlag, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CeltEncoder_SetEndBand_m767B785A3E059611D2E876D483F43673419EBA0D (CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CeltEncoder_SetChannels_m044A630FD1013D07F49245B2C009452B31BB1CC5 (CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CeltEncoder_SetBitrate_mCF59724BF7FF4D5F66B571C27B99B4C5F424AAB0 (CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CeltEncoder_SetVBR_mB2A8CFC94909FB78E5D6B5CCEC287AE5C26748BB (CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* __this, bool ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CeltEncoder_SetPrediction_m880E0433982007C125828ED68A45A4A134798EB4 (CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t EntropyCoder_tell_m29422D894C6D91518823D9C94D3CC93ACEA2350A (EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CeltEncoder_SetVBRConstraint_mCA7F81F0B4A945B523C40A8C49AC3EB27B8DE057 (CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* __this, bool ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Arrays_MemMoveShort_m07C394C79F74EE49ACB696FB6B519B9C6ACD7CB0 (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* ___0_array, int32_t ___1_src_idx, int32_t ___2_dst_idx, int32_t ___3_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_SHL16_mDE053DF36529BA35606160EBC860F23260B23A87_inline (int32_t ___0_a, int32_t ___1_shift, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CodecHelpers_stereo_fade_mFC6173FD066FAC8E29FD80632BC92FC90CB188CC (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* ___0_pcm_buf, int32_t ___1_g1, int32_t ___2_g2, int32_t ___3_overlap48, int32_t ___4_frame_size, int32_t ___5_channels, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___6_window, int32_t ___7_Fs, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntropyCoder_enc_bit_logp_mC1EAC72518B155F99BBCBEDA4B2CC46D3B411386 (EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* __this, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___0_buf, int32_t ___1__val, uint32_t ___2__logp, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntropyCoder_enc_uint_m837AC206B7D194AC7114DE24B7D5858D1D7C48AA (EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* __this, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___0_buf, uint32_t ___1__fl, uint32_t ___2__ft, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntropyCoder_enc_done_m25B7802F220D99E2CE5C1C34F99E7B8622126BCD (EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* __this, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___0_buf, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntropyCoder_enc_shrink_m2993D050F3B8C868157623824E04629980073C88 (EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* __this, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___0_buf, uint32_t ___1__size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CeltEncoder_SetAnalysis_m96468AD3A56A695114BD18D2FC056144ECDA48E5 (CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* __this, AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CeltEncoder_SetStartBand_mC5BFCE123D5E277F500238D96D5042CC6630A8D7 (CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CeltEncoder_celt_encode_with_ec_m2FF33A330E55AB3C586618444D6615182988E8CF (CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* __this, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D ___0_pcm, int32_t ___1_pcm_ptr, int32_t ___2_frame_size, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___3_compressed, int32_t ___4_compressed_ptr, int32_t ___5_nbCompressedBytes, EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* ___6_enc, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t CeltEncoder_GetFinalRange_m4BF672C1B80DD81A5D86981BA9EB8CE699F159CF_inline (CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CeltEncoder_ResetState_m1C30EBAD2FA89D556072892E54D8414AC010618B (CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* __this, const RuntimeMethod* method) ;
inline void Span_1__ctor_mE18EBB601FBFA01BA29FE353364700952A9091FE_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305*, void*, int32_t, const RuntimeMethod*))Span_1__ctor_mE18EBB601FBFA01BA29FE353364700952A9091FE_gshared_inline)(__this, ___0_pointer, ___1_length, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusMSDecoder_get_SampleRate_m00241E93F2188AB42BCE48A4A6191386EB16BB86 (OpusMSDecoder_tA24EBFD8B5A8C5D6C12AABAE8403EF562FFBA83A* __this, const RuntimeMethod* method) ;
inline int32_t ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_inline (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D*, const RuntimeMethod*))ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_gshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusMSDecoder_opus_multistream_packet_validate_m3E2D2CF1B4A698FD791C8A3BA0C3A2E605A22CC6 (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D ___0_data, int32_t ___1_nb_streams, int32_t ___2_Fs, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusDecoder_opus_decode_native_m226953E91BEF13C44CF5706AFD0B3238251F9567 (OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* __this, ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D ___0_data, int32_t ___1_data_ptr, int32_t ___2_len, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D ___3_pcm_out, int32_t ___4_pcm_out_ptr, int32_t ___5_frame_size, int32_t ___6_decode_fec, int32_t ___7_self_delimited, int32_t* ___8_packet_offset, int32_t ___9_soft_clip, const RuntimeMethod* method) ;
inline void opus_copy_channel_out_func_1_Invoke_m25EF632F19B8D56B7FB9C58D141E42FED126F81D_inline (opus_copy_channel_out_func_1_t2805945BE854CD39521CBB1514A4097CC0333344* __this, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D ___0_dst, int32_t ___1_dst_stride, int32_t ___2_dst_channel, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D ___3_src, int32_t ___4_src_ptr, int32_t ___5_src_stride, int32_t ___6_frame_size, const RuntimeMethod* method)
{
	((  void (*) (opus_copy_channel_out_func_1_t2805945BE854CD39521CBB1514A4097CC0333344*, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D, int32_t, int32_t, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D, int32_t, int32_t, int32_t, const RuntimeMethod*))opus_copy_channel_out_func_1_Invoke_m25EF632F19B8D56B7FB9C58D141E42FED126F81D_gshared_inline)(__this, ___0_dst, ___1_dst_stride, ___2_dst_channel, ___3_src, ___4_src_ptr, ___5_src_stride, ___6_frame_size, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusMultistream_get_left_channel_mBC9BCAA485D1095C537AA8A8DFB38355DCB06A04 (ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* ___0_layout, int32_t ___1_stream_id, int32_t ___2_prev, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusMultistream_get_right_channel_m1F24FA4BC9F11ADF386C3B9CAB948C1EBCC95C3F (ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* ___0_layout, int32_t ___1_stream_id, int32_t ___2_prev, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusMultistream_get_mono_channel_mD28CFC9E8DF9F999251643576CECC59C132EA292 (ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* ___0_layout, int32_t ___1_stream_id, int32_t ___2_prev, const RuntimeMethod* method) ;
inline void opus_copy_channel_out_func_1_Invoke_mB9C23E8CD1EED40F2F28F55B16E7F42E95D95441_inline (opus_copy_channel_out_func_1_t85951F56EF7450B05E135DF219F8BF05B4D5E030* __this, Span_1_t7578EBC2679C3216D7A6FA0DAECAF2256A33CF4C ___0_dst, int32_t ___1_dst_stride, int32_t ___2_dst_channel, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D ___3_src, int32_t ___4_src_ptr, int32_t ___5_src_stride, int32_t ___6_frame_size, const RuntimeMethod* method)
{
	((  void (*) (opus_copy_channel_out_func_1_t85951F56EF7450B05E135DF219F8BF05B4D5E030*, Span_1_t7578EBC2679C3216D7A6FA0DAECAF2256A33CF4C, int32_t, int32_t, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D, int32_t, int32_t, int32_t, const RuntimeMethod*))opus_copy_channel_out_func_1_Invoke_mB9C23E8CD1EED40F2F28F55B16E7F42E95D95441_gshared_inline)(__this, ___0_dst, ___1_dst_stride, ___2_dst_channel, ___3_src, ___4_src_ptr, ___5_src_stride, ___6_frame_size, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t OpusEncoder_get_SampleRate_m07B4CE6A7F1CAD6FA65936B9CF4F0F7536966E52_inline (OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool OpusEncoder_get_UseVBR_m5476585F8DDFEC3AF5C54713C82340E7007A4389 (OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* OpusEncoder_GetCeltMode_m6EC596A3D230516010AAB28BE0D2EDF48B9B793D (OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusEncoder_get_Lookahead_mC173676834FE358C9449C8B6A791005CC854075E (OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* __this, const RuntimeMethod* method) ;
inline int32_t CodecHelpers_compute_frame_size_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m383EA214DC0D0ABD3988FC7C148510734632BF0E (ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 ___0_analysis_pcm, int32_t ___1_frame_size, int32_t ___2_variable_duration, int32_t ___3_C, int32_t ___4_Fs, int32_t ___5_bitrate_bps, int32_t ___6_delay_compensation, downmix_func_1_tF54CFC946A3147244C91F03F0A69E5F14AB8461C* ___7_downmix, SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___8_subframe_mem, bool ___9_analysis_enabled, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, downmix_func_1_tF54CFC946A3147244C91F03F0A69E5F14AB8461C*, SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C*, bool, const RuntimeMethod*))CodecHelpers_compute_frame_size_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m383EA214DC0D0ABD3988FC7C148510734632BF0E_gshared)(___0_analysis_pcm, ___1_frame_size, ___2_variable_duration, ___3_C, ___4_Fs, ___5_bitrate_bps, ___6_delay_compensation, ___7_downmix, ___8_subframe_mem, ___9_analysis_enabled, method);
}
inline void OpusMSEncoder_surround_analysis_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m6704E92CF00A6B3ECE45AA3E065DAA70429B4918 (CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* ___0_celt_mode, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 ___1_pcm, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___2_bandLogE, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___3_mem, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___4_preemph_mem, int32_t ___5_len, int32_t ___6_overlap, int32_t ___7_channels, int32_t ___8_rate, opus_copy_channel_in_func_1_t73990C8C629DA94EEF8E66726DF516DDE7108033* ___9_copy_channel_in, const RuntimeMethod* method)
{
	((  void (*) (CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5*, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*, int32_t, int32_t, int32_t, int32_t, opus_copy_channel_in_func_1_t73990C8C629DA94EEF8E66726DF516DDE7108033*, const RuntimeMethod*))OpusMSEncoder_surround_analysis_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m6704E92CF00A6B3ECE45AA3E065DAA70429B4918_gshared)(___0_celt_mode, ___1_pcm, ___2_bandLogE, ___3_mem, ___4_preemph_mem, ___5_len, ___6_overlap, ___7_channels, ___8_rate, ___9_copy_channel_in, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusMSEncoder_surround_rate_allocation_m0E90A088523C9263B2D659D378A7C1CCD306829B (OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_out_rates, int32_t ___1_frame_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OpusEncoder_set_Bitrate_m7B8AD5518E3DB9D28E3F376195747340D266AF6E (OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OpusEncoder_set_Bandwidth_m1401E2DE4B403C8A4CB8BEF736AE48C02861C726 (OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void OpusEncoder_set_ForceMode_m27C03E1D80CD7B099DC5C9603ECCE70B99FB7201_inline (OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OpusEncoder_set_ForceChannels_m23F0A9A42C5094A4E2B32DCE3479BEE9C3BCB2A8 (OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OpusRepacketizer_Reset_m259455126D7AD3CFA796AA0B31C118D95D4C6AED (OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* __this, const RuntimeMethod* method) ;
inline void opus_copy_channel_in_func_1_Invoke_mE863D518D4E113322D44FEBB0E6A4112575A199E_inline (opus_copy_channel_in_func_1_t73990C8C629DA94EEF8E66726DF516DDE7108033* __this, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D ___0_dst, int32_t ___1_dst_ptr, int32_t ___2_dst_stride, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 ___3_src, int32_t ___4_src_stride, int32_t ___5_src_channel, int32_t ___6_frame_size, const RuntimeMethod* method)
{
	((  void (*) (opus_copy_channel_in_func_1_t73990C8C629DA94EEF8E66726DF516DDE7108033*, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D, int32_t, int32_t, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71, int32_t, int32_t, int32_t, const RuntimeMethod*))opus_copy_channel_in_func_1_Invoke_mE863D518D4E113322D44FEBB0E6A4112575A199E_gshared_inline)(__this, ___0_dst, ___1_dst_ptr, ___2_dst_stride, ___3_src, ___4_src_stride, ___5_src_channel, ___6_frame_size, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OpusEncoder_SetEnergyMask_mF239BDE66F682A18292CE1F5BE2AADBA657E69E9 (OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_value, const RuntimeMethod* method) ;
inline ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 ReadOnlySpan_1_op_Implicit_mCB2B03DD84141A56335B242E9AE355600A05C383 (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* ___0_array, const RuntimeMethod* method)
{
	return ((  ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 (*) (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*, const RuntimeMethod*))ReadOnlySpan_1_op_Implicit_mCB2B03DD84141A56335B242E9AE355600A05C383_gshared)(___0_array, method);
}
inline int32_t OpusEncoder_opus_encode_native_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m66C341F34A3F47A261A454C4DD185BE1507C02E5 (OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* __this, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 ___0_pcm, int32_t ___1_pcm_ptr, int32_t ___2_frame_size, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___3_data, int32_t ___4_data_ptr, int32_t ___5_out_data_bytes, int32_t ___6_lsb_depth, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 ___7_analysis_pcm, int32_t ___8_analysis_size, int32_t ___9_c1, int32_t ___10_c2, int32_t ___11_analysis_channels, downmix_func_1_tF54CFC946A3147244C91F03F0A69E5F14AB8461C* ___12_downmix, int32_t ___13_float_api, const RuntimeMethod* method)
{
	return ((  int32_t (*) (OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44*, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71, int32_t, int32_t, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305, int32_t, int32_t, int32_t, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71, int32_t, int32_t, int32_t, int32_t, downmix_func_1_tF54CFC946A3147244C91F03F0A69E5F14AB8461C*, int32_t, const RuntimeMethod*))OpusEncoder_opus_encode_native_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m66C341F34A3F47A261A454C4DD185BE1507C02E5_gshared)(__this, ___0_pcm, ___1_pcm_ptr, ___2_frame_size, ___3_data, ___4_data_ptr, ___5_out_data_bytes, ___6_lsb_depth, ___7_analysis_pcm, ___8_analysis_size, ___9_c1, ___10_c2, ___11_analysis_channels, ___12_downmix, ___13_float_api, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t OpusRepacketizer_GetNumFrames_m2244AD084D7E8802DB6AC4A1F1CAEFDCBF125A23_inline (OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* __this, const RuntimeMethod* method) ;
inline int32_t CodecHelpers_compute_frame_size_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_mC29E99157EBE887241410699A4D42C0B53FC4F5D (ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D ___0_analysis_pcm, int32_t ___1_frame_size, int32_t ___2_variable_duration, int32_t ___3_C, int32_t ___4_Fs, int32_t ___5_bitrate_bps, int32_t ___6_delay_compensation, downmix_func_1_t8CB50463E746CCBB4FFAE8EC889A02B92ED9F08B* ___7_downmix, SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___8_subframe_mem, bool ___9_analysis_enabled, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, downmix_func_1_t8CB50463E746CCBB4FFAE8EC889A02B92ED9F08B*, SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C*, bool, const RuntimeMethod*))CodecHelpers_compute_frame_size_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_mC29E99157EBE887241410699A4D42C0B53FC4F5D_gshared)(___0_analysis_pcm, ___1_frame_size, ___2_variable_duration, ___3_C, ___4_Fs, ___5_bitrate_bps, ___6_delay_compensation, ___7_downmix, ___8_subframe_mem, ___9_analysis_enabled, method);
}
inline void OpusMSEncoder_surround_analysis_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m9B9E4738B7BD6EEABF4D6378222B971D6775D65B (CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* ___0_celt_mode, ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D ___1_pcm, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___2_bandLogE, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___3_mem, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___4_preemph_mem, int32_t ___5_len, int32_t ___6_overlap, int32_t ___7_channels, int32_t ___8_rate, opus_copy_channel_in_func_1_t484D84949EB9FE0FFB9617C739F465DE3E898F3F* ___9_copy_channel_in, const RuntimeMethod* method)
{
	((  void (*) (CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5*, ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*, int32_t, int32_t, int32_t, int32_t, opus_copy_channel_in_func_1_t484D84949EB9FE0FFB9617C739F465DE3E898F3F*, const RuntimeMethod*))OpusMSEncoder_surround_analysis_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m9B9E4738B7BD6EEABF4D6378222B971D6775D65B_gshared)(___0_celt_mode, ___1_pcm, ___2_bandLogE, ___3_mem, ___4_preemph_mem, ___5_len, ___6_overlap, ___7_channels, ___8_rate, ___9_copy_channel_in, method);
}
inline void opus_copy_channel_in_func_1_Invoke_m6D03E61EA06F045BA121921DC606E861E540D67D_inline (opus_copy_channel_in_func_1_t484D84949EB9FE0FFB9617C739F465DE3E898F3F* __this, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D ___0_dst, int32_t ___1_dst_ptr, int32_t ___2_dst_stride, ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D ___3_src, int32_t ___4_src_stride, int32_t ___5_src_channel, int32_t ___6_frame_size, const RuntimeMethod* method)
{
	((  void (*) (opus_copy_channel_in_func_1_t484D84949EB9FE0FFB9617C739F465DE3E898F3F*, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D, int32_t, int32_t, ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D, int32_t, int32_t, int32_t, const RuntimeMethod*))opus_copy_channel_in_func_1_Invoke_m6D03E61EA06F045BA121921DC606E861E540D67D_gshared_inline)(__this, ___0_dst, ___1_dst_ptr, ___2_dst_stride, ___3_src, ___4_src_stride, ___5_src_channel, ___6_frame_size, method);
}
inline Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8 (int32_t ___0_x, int32_t ___1_y, const RuntimeMethod* method)
{
	return ((  Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* (*) (int32_t, int32_t, const RuntimeMethod*))Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8_gshared)(___0_x, ___1_y, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CeltCommon_resampling_factor_m6C156552D07405BDE82F1EE6386D518515ACE3DD (int32_t ___0_rate, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OpusMSEncoder_channel_pos_m5FF9B9CDE29B029E06F5AF09EFD8359BFAE20B6E (int32_t ___0_channels, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___1_pos, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Arrays_MemCopy_m3B172AAA9447D50DF1AE71C15662FB5005858B3F (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_src, int32_t ___1_src_idx, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___2_dst, int32_t ___3_dst_idx, int32_t ___4_length, const RuntimeMethod* method) ;
inline Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_array, const RuntimeMethod* method)
{
	return ((  Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 (*) (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*, const RuntimeMethod*))Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC_gshared)(___0_array, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CeltCommon_celt_preemphasis_m21C67E565A36929D27B417626A565BC7B688FC23 (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* ___0_pcmp, Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 ___1_inp, int32_t ___2_inp_ptr, int32_t ___3_N, int32_t ___4_CC, int32_t ___5_upsample, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___6_coef, BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* ___7_mem, int32_t ___8_clip, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MDCT_clt_mdct_forward_m574EDCF759544B7757CA02E5A5B9CD44ABD80793 (MDCTLookup_t1A4D19310C741D19B9223906DB1F8DF9142B47F0* ___0_l, Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 ___1_input, int32_t ___2_input_ptr, Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 ___3_output, int32_t ___4_output_ptr, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___5_window, int32_t ___6_overlap, int32_t ___7_shift, int32_t ___8_stride, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Bands_compute_band_energies_m6162BA578721FCAFBD60AFCB17CB0B7F2753AB26 (CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* ___0_m, Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* ___1_X, Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* ___2_bandE, int32_t ___3_end, int32_t ___4_C, int32_t ___5_LM, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void QuantizeBands_amp2Log2_m0C280EEAE3F9FA53CC72CC1A6E5EF65E2EC2AF8F (CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* ___0_m, int32_t ___1_effEnd, int32_t ___2_end, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___3_bandE, Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 ___4_bandLogE, int32_t ___5_bandLogE_ptr, int32_t ___6_C, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusMSEncoder_logSum_mC189C2CAB88090345C3C24D4D5C103F0D5341A87 (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_MIN32_mE77013C78A201F2EF11AE030F4E6DFC4815008F9_inline (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_celt_log2_m72E298D8304AC7AB2F8334898CA897FF185F8784_inline (int32_t ___0_x, const RuntimeMethod* method) ;
inline void List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690 (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
inline void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D*, RuntimeObject*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PgpObject_tB68A2D2CE41D9D71FF1AD186EAF590BEE8271B77* PgpObjectFactory_NextPgpObject_m66C1B3C58A35A3D9C9036ADD42B9F709988C5F1D (PgpObjectFactory_t74515C653C2839560F3C5AA5DCCE780F61DB9959* __this, const RuntimeMethod* method) ;
inline void Dictionary_2_Clear_mCFB5EA7351D5860D2B91592B91A84CA265A41433 (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA*, const RuntimeMethod*))Dictionary_2_Clear_mCFB5EA7351D5860D2B91592B91A84CA265A41433_gshared)(__this, method);
}
inline void List_1_Clear_m16C1F2C61FED5955F10EB36BC1CB2DF34B128994_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D*, const RuntimeMethod*))List_1_Clear_m16C1F2C61FED5955F10EB36BC1CB2DF34B128994_gshared_inline)(__this, method);
}
inline void Dictionary_2_Clear_m8B10E39C816C1A55D0DBCE1F83E06212561DEBE8 (Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77*, const RuntimeMethod*))Dictionary_2_Clear_m8B10E39C816C1A55D0DBCE1F83E06212561DEBE8_gshared)(__this, method);
}
inline void List_1_Clear_m6357ACBCD4516CB4B5CE08FB7CAB85FA8F1E29A3_inline (List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5*, const RuntimeMethod*))List_1_Clear_m6357ACBCD4516CB4B5CE08FB7CAB85FA8F1E29A3_gshared_inline)(__this, method);
}
inline bool Dictionary_2_ContainsKey_m703047C213F7AB55C9DC346596287773A1F670CD (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA*, RuntimeObject*, const RuntimeMethod*))Dictionary_2_ContainsKey_m703047C213F7AB55C9DC346596287773A1F670CD_gshared)(__this, ___0_key, method);
}
inline RuntimeObject* Dictionary_2_get_Comparer_m29B8217F824FC30BC2DE82EDA9759C0CD5EE6063 (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA*, const RuntimeMethod*))Dictionary_2_get_Comparer_m29B8217F824FC30BC2DE82EDA9759C0CD5EE6063_gshared)(__this, method);
}
inline void Pkcs12Store_RemoveOrdering_TisRuntimeObject_m6075B9C982D468D5CBE405DF6D523C6FAB17169A (RuntimeObject* ___0_c, List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ___1_o, RuntimeObject* ___2_k, const RuntimeMethod* method)
{
	((  void (*) (RuntimeObject*, List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D*, RuntimeObject*, const RuntimeMethod*))Pkcs12Store_RemoveOrdering_TisRuntimeObject_m6075B9C982D468D5CBE405DF6D523C6FAB17169A_gshared)(___0_c, ___1_o, ___2_k, method);
}
inline void Dictionary_2_set_Item_m1A840355E8EDAECEA9D0C6F5E51B248FAA449CBD (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA*, RuntimeObject*, RuntimeObject*, const RuntimeMethod*))Dictionary_2_set_Item_m1A840355E8EDAECEA9D0C6F5E51B248FAA449CBD_gshared)(__this, ___0_key, ___1_value, method);
}
inline bool Dictionary_2_ContainsKey_m99A920E5F0A5E4DC6D9BA3CE06457A7D6886EF30 (Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77* __this, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77*, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6, const RuntimeMethod*))Dictionary_2_ContainsKey_m99A920E5F0A5E4DC6D9BA3CE06457A7D6886EF30_gshared)(__this, ___0_key, method);
}
inline RuntimeObject* Dictionary_2_get_Comparer_m62BC32ED557CC6C4B8D17CDDE089026A5FA2C635 (Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77* __this, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77*, const RuntimeMethod*))Dictionary_2_get_Comparer_m62BC32ED557CC6C4B8D17CDDE089026A5FA2C635_gshared)(__this, method);
}
inline void Pkcs12Store_RemoveOrdering_TisCertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6_mDAEDA60DC524912A0C27C1517478835FD2344AD7 (RuntimeObject* ___0_c, List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* ___1_o, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 ___2_k, const RuntimeMethod* method)
{
	((  void (*) (RuntimeObject*, List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5*, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6, const RuntimeMethod*))Pkcs12Store_RemoveOrdering_TisCertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6_mDAEDA60DC524912A0C27C1517478835FD2344AD7_gshared)(___0_c, ___1_o, ___2_k, method);
}
inline void List_1_Add_mB2B488D34F1A96DF5D4A58A40374FC84B4B2A377_inline (List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* __this, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5*, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6, const RuntimeMethod*))List_1_Add_mB2B488D34F1A96DF5D4A58A40374FC84B4B2A377_gshared_inline)(__this, ___0_item, method);
}
inline void Dictionary_2_set_Item_m8D95E96F74963AC7C0BD8CFBEB6B7564C4DE87D6 (Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77* __this, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77*, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6, RuntimeObject*, const RuntimeMethod*))Dictionary_2_set_Item_m8D95E96F74963AC7C0BD8CFBEB6B7564C4DE87D6_gshared)(__this, ___0_key, ___1_value, method);
}
inline bool Dictionary_2_Remove_m5C7C45E75D951A75843F3F7AADD56ECD64F6BC86 (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA*, RuntimeObject*, const RuntimeMethod*))Dictionary_2_Remove_m5C7C45E75D951A75843F3F7AADD56ECD64F6BC86_gshared)(__this, ___0_key, method);
}
inline bool Dictionary_2_Remove_m79A129C6C90F1F53B80189D35F54E5C5765308D9 (Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77* __this, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77*, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6, const RuntimeMethod*))Dictionary_2_Remove_m79A129C6C90F1F53B80189D35F54E5C5765308D9_gshared)(__this, ___0_key, method);
}
inline bool CollectionUtilities_Remove_TisRuntimeObject_TisRuntimeObject_m130B6F4F89CFE4220CCC1BC3C572BD22F33A4D03 (RuntimeObject* ___0_d, RuntimeObject* ___1_k, RuntimeObject** ___2_v, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, RuntimeObject*, RuntimeObject**, const RuntimeMethod*))CollectionUtilities_Remove_TisRuntimeObject_TisRuntimeObject_m130B6F4F89CFE4220CCC1BC3C572BD22F33A4D03_gshared)(___0_d, ___1_k, ___2_v, method);
}
inline void U3CU3Ec__DisplayClass45_0_1__ctor_m6ECC37F4DD01881E15CDB2E0E861E057EEE4D038 (U3CU3Ec__DisplayClass45_0_1_t3426FDD1940B82C867508C4438EADE01343EC1E0* __this, const RuntimeMethod* method)
{
	((  void (*) (U3CU3Ec__DisplayClass45_0_1_t3426FDD1940B82C867508C4438EADE01343EC1E0*, const RuntimeMethod*))U3CU3Ec__DisplayClass45_0_1__ctor_m6ECC37F4DD01881E15CDB2E0E861E057EEE4D038_gshared)(__this, method);
}
inline void Predicate_1__ctor_m3E007299121A15DF80F4A210FF8C20E5DF688F20 (Predicate_1_t8342C85FF4E41CD1F7024AC0CDC3E5312A32CB12* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Predicate_1_t8342C85FF4E41CD1F7024AC0CDC3E5312A32CB12*, RuntimeObject*, intptr_t, const RuntimeMethod*))Predicate_1__ctor_m3E007299121A15DF80F4A210FF8C20E5DF688F20_gshared)(__this, ___0_object, ___1_method, method);
}
inline int32_t List_1_FindIndex_m9875FFE328FA833B2617915FF976DEDA4724EBC3 (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, Predicate_1_t8342C85FF4E41CD1F7024AC0CDC3E5312A32CB12* ___0_match, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D*, Predicate_1_t8342C85FF4E41CD1F7024AC0CDC3E5312A32CB12*, const RuntimeMethod*))List_1_FindIndex_m9875FFE328FA833B2617915FF976DEDA4724EBC3_gshared)(__this, ___0_match, method);
}
inline void List_1_RemoveAt_m54F62297ADEE4D4FDA697F49ED807BF901201B54 (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	((  void (*) (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D*, int32_t, const RuntimeMethod*))List_1_RemoveAt_m54F62297ADEE4D4FDA697F49ED807BF901201B54_gshared)(__this, ___0_index, method);
}
inline void U3CU3Ec__DisplayClass45_0_1__ctor_m29E8FD1000EF0300B33971C6137E44B8FAD2CE24 (U3CU3Ec__DisplayClass45_0_1_tC5DD57B2E5D051E5596DE1A51C9E4425B2A46AA4* __this, const RuntimeMethod* method)
{
	((  void (*) (U3CU3Ec__DisplayClass45_0_1_tC5DD57B2E5D051E5596DE1A51C9E4425B2A46AA4*, const RuntimeMethod*))U3CU3Ec__DisplayClass45_0_1__ctor_m29E8FD1000EF0300B33971C6137E44B8FAD2CE24_gshared)(__this, method);
}
inline void Predicate_1__ctor_mB25D862104E995A05A4ADDDB9B6E5D1248C707B0 (Predicate_1_tB8E1CB39BCA82FC44F9608B8B75AFA61E47EB81A* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Predicate_1_tB8E1CB39BCA82FC44F9608B8B75AFA61E47EB81A*, RuntimeObject*, intptr_t, const RuntimeMethod*))Predicate_1__ctor_mB25D862104E995A05A4ADDDB9B6E5D1248C707B0_gshared)(__this, ___0_object, ___1_method, method);
}
inline int32_t List_1_FindIndex_mA44D25D71BF94D4C389465BD8BE3139D18000A3D (List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* __this, Predicate_1_tB8E1CB39BCA82FC44F9608B8B75AFA61E47EB81A* ___0_match, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5*, Predicate_1_tB8E1CB39BCA82FC44F9608B8B75AFA61E47EB81A*, const RuntimeMethod*))List_1_FindIndex_mA44D25D71BF94D4C389465BD8BE3139D18000A3D_gshared)(__this, ___0_match, method);
}
inline void List_1_RemoveAt_m3EA20C82CFE1BDDD044B4C273F9DA16237A8EEFA (List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	((  void (*) (List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5*, int32_t, const RuntimeMethod*))List_1_RemoveAt_m3EA20C82CFE1BDDD044B4C273F9DA16237A8EEFA_gshared)(__this, ___0_index, method);
}
inline int32_t HashSet_1_get_Count_m41CC85EEB7855CEFA3BC7A32F115387939318ED3_inline (HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885*, const RuntimeMethod*))HashSet_1_get_Count_m41CC85EEB7855CEFA3BC7A32F115387939318ED3_gshared_inline)(__this, method);
}
inline Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8 HashSet_1_GetEnumerator_m143B98FEED7E9CABA2C494AB2F04DAD60A504635 (HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8 (*) (HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885*, const RuntimeMethod*))HashSet_1_GetEnumerator_m143B98FEED7E9CABA2C494AB2F04DAD60A504635_gshared)(__this, method);
}
inline void Enumerator_Dispose_mFB582AEAA2E73F3128B5571197BEDE256A83F657 (Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8* __this, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8*, const RuntimeMethod*))Enumerator_Dispose_mFB582AEAA2E73F3128B5571197BEDE256A83F657_gshared)(__this, method);
}
inline RuntimeObject* Enumerator_get_Current_m139A176CD271A0532D75BE08DA7831C8C45CE28F_inline (Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8* __this, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8*, const RuntimeMethod*))Enumerator_get_Current_m139A176CD271A0532D75BE08DA7831C8C45CE28F_gshared_inline)(__this, method);
}
inline bool HashSet_1_Contains_m9BACE52BFA0BD83C601529D3629118453E459BBB (HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* __this, RuntimeObject* ___0_item, const RuntimeMethod* method)
{
	return ((  bool (*) (HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885*, RuntimeObject*, const RuntimeMethod*))HashSet_1_Contains_m9BACE52BFA0BD83C601529D3629118453E459BBB_gshared)(__this, ___0_item, method);
}
inline bool Enumerator_MoveNext_m27565F5ACCCC75C3DD34CC4CAE3E6AEFEB9144A6 (Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8*, const RuntimeMethod*))Enumerator_MoveNext_m27565F5ACCCC75C3DD34CC4CAE3E6AEFEB9144A6_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8 (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F* __this, const RuntimeMethod* method) ;
inline bool PlayableHandle_IsPlayableOfType_TisAudioClipPlayable_tD4B758E68CAE03CB0CD31F90C8A3E603B97143A0_m95809D16DD3494AEB0E9E652B42E0CE3167BEE0E (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4*, const RuntimeMethod*))PlayableHandle_IsPlayableOfType_TisAudioClipPlayable_tD4B758E68CAE03CB0CD31F90C8A3E603B97143A0_m95809D16DD3494AEB0E9E652B42E0CE3167BEE0E_gshared)(__this, method);
}
inline bool Playable_IsPlayableOfType_TisAudioClipPlayable_tD4B758E68CAE03CB0CD31F90C8A3E603B97143A0_m94FCB00FCEC927F1EAB530CFEC8EE9CCB388CF8A (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F*, const RuntimeMethod*))Playable_IsPlayableOfType_TisAudioClipPlayable_tD4B758E68CAE03CB0CD31F90C8A3E603B97143A0_m94FCB00FCEC927F1EAB530CFEC8EE9CCB388CF8A_gshared)(__this, method);
}
inline bool PlayableHandle_IsPlayableOfType_TisAudioMixerPlayable_t6AADDF0C53DF1B4C17969EC24B3B4E4975F3A56C_m28F89BE3D7CCE69B28258CC5B1C7D4E814F48CAB (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4*, const RuntimeMethod*))PlayableHandle_IsPlayableOfType_TisAudioMixerPlayable_t6AADDF0C53DF1B4C17969EC24B3B4E4975F3A56C_m28F89BE3D7CCE69B28258CC5B1C7D4E814F48CAB_gshared)(__this, method);
}
inline bool Playable_IsPlayableOfType_TisAudioMixerPlayable_t6AADDF0C53DF1B4C17969EC24B3B4E4975F3A56C_m61519D5329775A9F560D019477CAF48C17777D62 (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F*, const RuntimeMethod*))Playable_IsPlayableOfType_TisAudioMixerPlayable_t6AADDF0C53DF1B4C17969EC24B3B4E4975F3A56C_m61519D5329775A9F560D019477CAF48C17777D62_gshared)(__this, method);
}
inline bool Playable_IsPlayableOfType_TisIl2CppFullySharedGenericStruct_m295C4DE8654EB520ABA0C31EAF1E01D89A770DDB (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F*, const RuntimeMethod*))Playable_IsPlayableOfType_TisIl2CppFullySharedGenericStruct_m295C4DE8654EB520ABA0C31EAF1E01D89A770DDB_gshared)(__this, method);
}
inline PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 ScriptPlayable_1_GetHandle_mFBB086A8188A0D77BB5CF4A1A03031EA9B67D22A (ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000* __this, const RuntimeMethod* method)
{
	return ((  PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 (*) (ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000*, const RuntimeMethod*))ScriptPlayable_1_GetHandle_mFBB086A8188A0D77BB5CF4A1A03031EA9B67D22A_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double PlayableHandle_GetDuration_mE3CF9C12CA5A186288A7F1981A92F043100E02A7 (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E PlayableHandle_GetGraph_m03AFC9F0B66AC13A120EC37F6964200C9973CE24 (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F PlayableHandle_GetInput_m3F42E2CF0D7DFA2396295133D02622C1BE3A8633 (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, int32_t ___0_inputPort, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t PlayableHandle_GetInputCount_m7FE60883E4B7C9AF7D39F28A044924ADBD5E5121 (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float PlayableHandle_GetInputWeight_m0C5D7A870D6DDE9F1A5193907ADCA0335DC6207A (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, int32_t ___0_inputIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t PlayableHandle_GetPlayState_m14547B804BB9B9B9E2B20B3F0975334CC99E778F (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double PlayableHandle_GetPreviousTime_m0C6881E900DF5FE7281699876DFE48BA64DEC1BF (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double PlayableHandle_GetTime_m27CB24B86EF0E6A4BD2C53907A677059B5D2BD5D (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t PlayableHandle_GetTimeWrapMode_m3C4CF421B7470E04537C45092DA9A1D242A5D1B4 (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool PlayableHandle_IsDone_mF5DAB54F941BC13799577396526E3901CF639DE6 (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool PlayableHandle_IsValid_m07631D12846BAAF2CC302E69A28A44BFE9EB5098 (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableHandle_Pause_m75833A31BA17AC8900736C6F5AC778D033001B32 (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableHandle_Play_m1EF8E1105EB6A4A9B0D6638A57CDCBCEEDC6FB2D (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableHandle_SetDuration_m4E07F9F3A90B2F3CE10325D9F405993F03CCA08B (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, double ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 AudioClipPlayable_GetHandle_mEA1D664328FF9B08E4F7D5EBCD4B51A754D97C44 (AudioClipPlayable_tD4B758E68CAE03CB0CD31F90C8A3E603B97143A0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableHandle_SetInputCount_m6067CD3616C428F777903FCBFD789060A2185DEE (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 AnimationLayerMixerPlayable_GetHandle_m324A98D0B0BFC0441377D65CAE93C914F828721F (AnimationLayerMixerPlayable_tAD8D28A1E2FB76567E9748CDD11699AEF0B4317D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool PlayableHandle_SetInputWeight_m8647C2593A24870E429A0832FC26EE2241CC302E (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, int32_t ___0_inputIndex, float ___1_weight, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 AnimationMixerPlayable_GetHandle_mBA6CEB1579A713A985D474E75BC282728318882F (AnimationMixerPlayable_t2984697B87B8719A34519FCF2130545D6D7AB6C0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 AnimationMotionXToDeltaPlayable_GetHandle_m09F605E78AD7F0135C7F57EB048031091A50E3A2 (AnimationMotionXToDeltaPlayable_t3946605ADB0B4C054A27B3D65A59F8EB75B6BE18* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 AnimationOffsetPlayable_GetHandle_m769BEFF90379AEAB0C579F7800953458CE3EBA78 (AnimationOffsetPlayable_t39A1B1103995D63650F606BA2EA4ABDF9484AFB4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 AnimationRemoveScalePlayable_GetHandle_mFFA58B879F31327187A20ED30E1C814B7BEAA9C6 (AnimationRemoveScalePlayable_t915611F6D3CC150DDCAF56412AC3E5ACB518A9DD* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableHandle_SetInputWeight_mCC570E6D826D79987CC4E021DA9E7C0B700C0AC1 (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 ___0_input, float ___1_weight, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 AudioMixerPlayable_GetHandle_m6C182D9794E901D123223BB57738A302BEAB41FD (AudioMixerPlayable_t6AADDF0C53DF1B4C17969EC24B3B4E4975F3A56C* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableHandle_SetPropagateSetTime_mD1458DFF49EF07D73884A9BBAC31358579C8931B (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, bool ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableHandle_SetSpeed_m39D426AE0DF93F876C2C1EDF9417C11B97A305E9 (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, double ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableHandle_SetTime_m6D255AB6779F3DC278813F1C016FE4EBC9F4B1E4 (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, double ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableHandle_SetTimeWrapMode_m88B50CE0AABE0183BBF12ACEC5E84CBEDAB76C2F (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4* __this, int32_t ___0_mode, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Inlines_silk_CLZ_FRAC_m52AC70C7D15EEBDA3942DD78876AB11EA17646C3_inline (int32_t ___0_input, int32_t* ___1_lz, int32_t* ___2_frac_Q7, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_MUL_m9A77BFD928CCAE45F57B7A10CB9F70D490D0C8AE_inline (int32_t ___0_a32, int32_t ___1_b32, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_SMULWB_mB0EE85575CC4960FEF6C551F34CFEFEC88AD9623_inline (int32_t ___0_a32, int32_t ___1_b32, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_SMULBB_m356DF98499DAAA55E6D101C6A46C7FFA0E3FFAC3_inline (int32_t ___0_a32, int32_t ___1_b32, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_ADD_RSHIFT32_mFFB05D8832CA3D810BD6B1FD0C5C1FD1523652FF_inline (int32_t ___0_a, int32_t ___1_b, int32_t ___2_shift, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_MLA_m15F9E5FB62CB367ACA53909EA8308880BC369DC2_inline (int32_t ___0_a32, int32_t ___1_b32, int32_t ___2_c32, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_EXTEND32_mE5EBC463B9835A2B476DCBB7D51D91C1876773F6_inline (int32_t ___0_x, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56 (const RuntimeMethod* method) ;
inline void Span_1__ctor_m947BF95D54571BF3897F96822B7A8FDA5853497B_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, uint8_t* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305*, uint8_t*, int32_t, const RuntimeMethod*))Span_1__ctor_m947BF95D54571BF3897F96822B7A8FDA5853497B_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline void List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4 (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D*, RuntimeObject*, const RuntimeMethod*))List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4_gshared)(__this, ___0_item, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB (RuntimeArray* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
inline void List_1_AddWithResize_mA5D746142AF298C8C2B2EBC5EBC337E78F81F1F8 (List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* __this, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5*, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6, const RuntimeMethod*))List_1_AddWithResize_mA5D746142AF298C8C2B2EBC5EBC337E78F81F1F8_gshared)(__this, ___0_item, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_CLZ32_m975B6E91C19261EFAB22308A3A7C2B97E576A197_inline (int32_t ___0_in32, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_ROR32_m7B2F1BA4281F2CCCE053E73032C9E50AADC1EBC9_inline (int32_t ___0_a32, int32_t ___1_rot, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_ADD32_m6FFC7DC9AC00CDEC5ED7F9B9785A190F7BF8C81F_inline (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_EC_ILOG_m2C5271EC2BB43C3DC9B682F54CF30EB35E952533_inline (uint32_t ___0_x, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t Inlines_silk_ROR32_mC598FED457636AB7E43C622D6435614B3E7A9A0A_inline (uint32_t ___0_a32, int32_t ___1_rot, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusEncoder_opus_encode_native_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_mEC592DA223E634EAE136DDFFF74F938B95E398F1_gshared (OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* __this, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 ___0_pcm, int32_t ___1_pcm_ptr, int32_t ___2_frame_size, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___3_data, int32_t ___4_data_ptr, int32_t ___5_out_data_bytes, int32_t ___6_lsb_depth, ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D ___7_analysis_pcm, int32_t ___8_analysis_size, int32_t ___9_c1, int32_t ___10_c2, int32_t ___11_analysis_channels, downmix_func_1_t8CB50463E746CCBB4FFAE8EC889A02B92ED9F08B* ___12_downmix, int32_t ___13_float_api, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EncControlState_t1F753CF3968665C2171A288F862D70168F348019_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Nullable_1_get_Value_m0DF3B826A745419D26A168689AEB4BE6F8698ECA_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1__ctor_mE18EBB601FBFA01BA29FE353364700952A9091FE_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	SilkEncoder_t7AB5C2F712CDB92EBFCDAF8E9743C5A39B7CFD6D* V_0 = NULL;
	CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* V_5 = NULL;
	int32_t V_6 = 0;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	int32_t V_11 = 0;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t V_14 = 0;
	uint32_t V_15 = 0;
	int32_t V_16 = 0;
	int32_t V_17 = 0;
	int32_t V_18 = 0;
	int32_t V_19 = 0;
	int32_t V_20 = 0;
	int32_t V_21 = 0;
	int32_t V_22 = 0;
	int32_t V_23 = 0;
	int32_t V_24 = 0;
	int32_t V_25 = 0;
	int32_t V_26 = 0;
	int32_t V_27 = 0;
	CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* V_28 = NULL;
	AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* V_29 = NULL;
	int32_t V_30 = 0;
	int32_t V_31 = 0;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* V_32 = NULL;
	int32_t V_33 = 0;
	int32_t V_34 = 0;
	int32_t V_35 = 0;
	int32_t V_36 = 0;
	int32_t V_37 = 0;
	int32_t V_38 = 0;
	int32_t V_39 = 0;
	int32_t V_40 = 0;
	int32_t V_41 = 0;
	EncControlState_t1F753CF3968665C2171A288F862D70168F348019* V_42 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_43 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_44 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_45 = NULL;
	int32_t V_46 = 0;
	int32_t V_47 = 0;
	int32_t V_48 = 0;
	int32_t V_49 = 0;
	int32_t V_50 = 0;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_51 = NULL;
	int32_t V_52 = 0;
	int32_t V_53 = 0;
	int32_t V_54 = 0;
	int32_t V_55 = 0;
	int32_t V_56 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* V_57 = NULL;
	int32_t V_58 = 0;
	int32_t V_59 = 0;
	int32_t V_60 = 0;
	int32_t V_61 = 0;
	int32_t V_62 = 0;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* V_63 = NULL;
	BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* V_64 = NULL;
	int32_t V_65 = 0;
	int32_t V_66 = 0;
	int32_t V_67 = 0;
	int32_t V_68 = 0;
	int32_t V_69 = 0;
	int32_t V_70 = 0;
	int16_t V_71 = 0;
	int32_t V_72 = 0;
	int32_t V_73 = 0;
	BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* V_74 = NULL;
	int32_t V_75 = 0;
	int32_t V_76 = 0;
	int32_t V_77 = 0;
	int32_t V_78 = 0;
	int32_t V_79 = 0;
	int32_t V_80 = 0;
	int32_t V_81 = 0;
	int32_t V_82 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 V_83;
	memset((&V_83), 0, sizeof(V_83));
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 V_84;
	memset((&V_84), 0, sizeof(V_84));
	int32_t V_85 = 0;
	int32_t V_86 = 0;
	int32_t G_B46_0 = 0;
	OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* G_B84_0 = NULL;
	OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* G_B83_0 = NULL;
	int32_t G_B85_0 = 0;
	OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* G_B85_1 = NULL;
	OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* G_B98_0 = NULL;
	OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* G_B97_0 = NULL;
	int32_t G_B99_0 = 0;
	OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* G_B99_1 = NULL;
	int32_t G_B113_0 = 0;
	int32_t G_B112_0 = 0;
	int32_t G_B114_0 = 0;
	int32_t G_B114_1 = 0;
	int32_t G_B131_0 = 0;
	int32_t G_B214_0 = 0;
	int32_t G_B232_0 = 0;
	int32_t G_B232_1 = 0;
	int32_t G_B232_2 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B232_3;
	memset((&G_B232_3), 0, sizeof(G_B232_3));
	int32_t G_B232_4 = 0;
	int32_t G_B232_5 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B232_6 = NULL;
	int32_t G_B231_0 = 0;
	int32_t G_B231_1 = 0;
	int32_t G_B231_2 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B231_3;
	memset((&G_B231_3), 0, sizeof(G_B231_3));
	int32_t G_B231_4 = 0;
	int32_t G_B231_5 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B231_6 = NULL;
	int32_t G_B233_0 = 0;
	int32_t G_B233_1 = 0;
	int32_t G_B233_2 = 0;
	int32_t G_B233_3 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B233_4;
	memset((&G_B233_4), 0, sizeof(G_B233_4));
	int32_t G_B233_5 = 0;
	int32_t G_B233_6 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B233_7 = NULL;
	int32_t G_B252_0 = 0;
	int32_t G_B252_1 = 0;
	EncControlState_t1F753CF3968665C2171A288F862D70168F348019* G_B252_2 = NULL;
	int32_t G_B251_0 = 0;
	int32_t G_B251_1 = 0;
	EncControlState_t1F753CF3968665C2171A288F862D70168F348019* G_B251_2 = NULL;
	int32_t G_B253_0 = 0;
	int32_t G_B253_1 = 0;
	int32_t G_B253_2 = 0;
	EncControlState_t1F753CF3968665C2171A288F862D70168F348019* G_B253_3 = NULL;
	int32_t G_B262_0 = 0;
	int32_t G_B265_0 = 0;
	EncControlState_t1F753CF3968665C2171A288F862D70168F348019* G_B305_0 = NULL;
	EncControlState_t1F753CF3968665C2171A288F862D70168F348019* G_B304_0 = NULL;
	int32_t G_B306_0 = 0;
	EncControlState_t1F753CF3968665C2171A288F862D70168F348019* G_B306_1 = NULL;
	int32_t G_B338_0 = 0;
	int32_t G_B337_0 = 0;
	int32_t G_B339_0 = 0;
	int32_t G_B339_1 = 0;
	int32_t G_B345_0 = 0;
	int32_t G_B375_0 = 0;
	int32_t G_B378_0 = 0;
	int32_t G_B382_0 = 0;
	int32_t G_B382_1 = 0;
	int32_t G_B381_0 = 0;
	int32_t G_B381_1 = 0;
	int32_t G_B383_0 = 0;
	int32_t G_B383_1 = 0;
	int32_t G_B383_2 = 0;
	{
		V_3 = 0;
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_0 = (EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679*)il2cpp_codegen_object_new(EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679_il2cpp_TypeInfo_var);
		EntropyCoder__ctor_m94DD0C4B87D72A98041935C6879744E5FBF72E73(L_0, NULL);
		V_5 = L_0;
		V_7 = 0;
		V_8 = 0;
		V_9 = 0;
		V_10 = 0;
		V_11 = 0;
		V_14 = 0;
		V_15 = (uint32_t)0;
		AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* L_1 = (AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116*)il2cpp_codegen_object_new(AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116_il2cpp_TypeInfo_var);
		AnalysisInfo__ctor_m9F52F6126A6EB1E81FD9A18DF4B9E24F357D782E(L_1, NULL);
		V_29 = L_1;
		V_30 = (-1);
		V_31 = (-1);
		int32_t L_2 = ___5_out_data_bytes;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)1276), L_2, NULL);
		V_25 = L_3;
		__this->___rangeFinal = (uint32_t)0;
		int32_t L_4 = __this->___variable_duration;
		if (L_4)
		{
			goto IL_0098;
		}
	}
	{
		int32_t L_5 = ___2_frame_size;
		int32_t L_6 = __this->___Fs;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)400), L_5))) == ((int32_t)L_6)))
		{
			goto IL_0098;
		}
	}
	{
		int32_t L_7 = ___2_frame_size;
		int32_t L_8 = __this->___Fs;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)200), L_7))) == ((int32_t)L_8)))
		{
			goto IL_0098;
		}
	}
	{
		int32_t L_9 = ___2_frame_size;
		int32_t L_10 = __this->___Fs;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)100), L_9))) == ((int32_t)L_10)))
		{
			goto IL_0098;
		}
	}
	{
		int32_t L_11 = ___2_frame_size;
		int32_t L_12 = __this->___Fs;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)50), L_11))) == ((int32_t)L_12)))
		{
			goto IL_0098;
		}
	}
	{
		int32_t L_13 = ___2_frame_size;
		int32_t L_14 = __this->___Fs;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)25), L_13))) == ((int32_t)L_14)))
		{
			goto IL_0098;
		}
	}
	{
		int32_t L_15 = ___2_frame_size;
		int32_t L_16 = __this->___Fs;
		if ((!(((uint32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)50), L_15))) == ((uint32_t)((int32_t)il2cpp_codegen_multiply(3, L_16))))))
		{
			goto IL_00ac;
		}
	}

IL_0098:
	{
		int32_t L_17 = ___2_frame_size;
		int32_t L_18 = __this->___Fs;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)400), L_17))) < ((int32_t)L_18)))
		{
			goto IL_00ac;
		}
	}
	{
		int32_t L_19 = V_25;
		if ((((int32_t)L_19) > ((int32_t)0)))
		{
			goto IL_00ae;
		}
	}

IL_00ac:
	{
		return (-1);
	}

IL_00ae:
	{
		SilkEncoder_t7AB5C2F712CDB92EBFCDAF8E9743C5A39B7CFD6D* L_20 = __this->___SilkEncoder;
		V_0 = L_20;
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_21 = __this->___Celt_Encoder;
		V_1 = L_21;
		int32_t L_22 = __this->___application;
		if ((!(((uint32_t)L_22) == ((uint32_t)((int32_t)2051)))))
		{
			goto IL_00ce;
		}
	}
	{
		V_20 = 0;
		goto IL_00d6;
	}

IL_00ce:
	{
		int32_t L_23 = __this->___delay_compensation;
		V_20 = L_23;
	}

IL_00d6:
	{
		int32_t L_24 = ___6_lsb_depth;
		int32_t L_25 = __this->___lsb_depth;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_26;
		L_26 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(L_24, L_25, NULL);
		___6_lsb_depth = L_26;
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_27 = V_1;
		NullCheck(L_27);
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_28;
		L_28 = CeltEncoder_GetMode_m51534658A97582FB288A8023F6AA133BFBB8AC1F_inline(L_27, NULL);
		V_28 = L_28;
		__this->___voice_ratio = (-1);
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_29 = __this->___analysis;
		NullCheck(L_29);
		bool L_30 = L_29->___enabled;
		if (!L_30)
		{
			goto IL_0246;
		}
	}
	{
		AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* L_31 = V_29;
		NullCheck(L_31);
		L_31->___valid = 0;
		Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28* L_32 = (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28*)(&__this->____vqLevel);
		bool L_33;
		L_33 = Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_inline(L_32, Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_RuntimeMethod_var);
		if (L_33)
		{
			goto IL_0127;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_34 = __this->___silk_mode;
		NullCheck(L_34);
		int32_t L_35 = L_34->___complexity;
		if ((((int32_t)L_35) < ((int32_t)7)))
		{
			goto IL_0172;
		}
	}

IL_0127:
	{
		int32_t L_36 = __this->___Fs;
		if ((!(((uint32_t)L_36) == ((uint32_t)((int32_t)48000)))))
		{
			goto IL_0172;
		}
	}
	{
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_37 = __this->___analysis;
		NullCheck(L_37);
		int32_t L_38 = L_37->___read_pos;
		V_30 = L_38;
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_39 = __this->___analysis;
		NullCheck(L_39);
		int32_t L_40 = L_39->___read_subframe;
		V_31 = L_40;
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_41 = __this->___analysis;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_42 = V_28;
		ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D L_43 = ___7_analysis_pcm;
		int32_t L_44 = ___8_analysis_size;
		int32_t L_45 = ___2_frame_size;
		int32_t L_46 = ___9_c1;
		int32_t L_47 = ___10_c2;
		int32_t L_48 = ___11_analysis_channels;
		int32_t L_49 = __this->___Fs;
		int32_t L_50 = ___6_lsb_depth;
		downmix_func_1_t8CB50463E746CCBB4FFAE8EC889A02B92ED9F08B* L_51 = ___12_downmix;
		AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* L_52 = V_29;
		Analysis_run_analysis_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m69F1371361914F4F1CD53BB2A4948DCACFC8A738(L_41, L_42, L_43, L_44, L_45, L_46, L_47, L_48, L_49, L_50, L_51, L_52, il2cpp_rgctx_method(method->rgctx_data, 2));
	}

IL_0172:
	{
		__this->___detected_bandwidth = (int32_t)0;
		AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* L_53 = V_29;
		NullCheck(L_53);
		int32_t L_54 = L_53->___valid;
		if (!L_54)
		{
			goto IL_0246;
		}
	}
	{
		int32_t L_55 = __this->___signal_type;
		if ((!(((uint32_t)L_55) == ((uint32_t)((int32_t)-1000)))))
		{
			goto IL_01b8;
		}
	}
	{
		AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* L_56 = V_29;
		NullCheck(L_56);
		float L_57 = L_56->___music_prob;
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_58;
		L_58 = floor(((double)((float)il2cpp_codegen_add((0.5f), ((float)il2cpp_codegen_multiply((100.0f), ((float)il2cpp_codegen_subtract((1.0f), L_57))))))));
		__this->___voice_ratio = il2cpp_codegen_cast_double_to_int<int32_t>(L_58);
	}

IL_01b8:
	{
		AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* L_59 = V_29;
		NullCheck(L_59);
		int32_t L_60 = L_59->___bandwidth;
		V_33 = L_60;
		int32_t L_61 = V_33;
		if ((((int32_t)L_61) > ((int32_t)((int32_t)12))))
		{
			goto IL_01d4;
		}
	}
	{
		__this->___detected_bandwidth = (int32_t)((int32_t)1101);
		goto IL_0218;
	}

IL_01d4:
	{
		int32_t L_62 = V_33;
		if ((((int32_t)L_62) > ((int32_t)((int32_t)14))))
		{
			goto IL_01e7;
		}
	}
	{
		__this->___detected_bandwidth = (int32_t)((int32_t)1102);
		goto IL_0218;
	}

IL_01e7:
	{
		int32_t L_63 = V_33;
		if ((((int32_t)L_63) > ((int32_t)((int32_t)16))))
		{
			goto IL_01fa;
		}
	}
	{
		__this->___detected_bandwidth = (int32_t)((int32_t)1103);
		goto IL_0218;
	}

IL_01fa:
	{
		int32_t L_64 = V_33;
		if ((((int32_t)L_64) > ((int32_t)((int32_t)18))))
		{
			goto IL_020d;
		}
	}
	{
		__this->___detected_bandwidth = (int32_t)((int32_t)1104);
		goto IL_0218;
	}

IL_020d:
	{
		__this->___detected_bandwidth = (int32_t)((int32_t)1105);
	}

IL_0218:
	{
		Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28* L_65 = (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28*)(&__this->____vqLevel);
		bool L_66;
		L_66 = Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_inline(L_65, Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_RuntimeMethod_var);
		if (!L_66)
		{
			goto IL_0246;
		}
	}
	{
		Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28* L_67 = (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28*)(&__this->____vqLevel);
		int32_t L_68;
		L_68 = Nullable_1_get_Value_m0DF3B826A745419D26A168689AEB4BE6F8698ECA(L_67, Nullable_1_get_Value_m0DF3B826A745419D26A168689AEB4BE6F8698ECA_RuntimeMethod_var);
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_69 = __this->___analysis;
		NullCheck(L_69);
		float L_70 = L_69->___music_prob;
		il2cpp_codegen_runtime_class_init_inline(OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44_il2cpp_TypeInfo_var);
		int32_t L_71;
		L_71 = OpusEncoder_GetVariableQualityBitrate_m6FFBB73E7634B913CF7E2CC60B9076164F1FD0F0(L_68, L_70, NULL);
		__this->___user_bitrate_bps = L_71;
	}

IL_0246:
	{
		int32_t L_72 = __this->___channels;
		if ((!(((uint32_t)L_72) == ((uint32_t)2))))
		{
			goto IL_0270;
		}
	}
	{
		int32_t L_73 = __this->___force_channels;
		if ((((int32_t)L_73) == ((int32_t)1)))
		{
			goto IL_0270;
		}
	}
	{
		ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 L_74 = ___0_pcm;
		int32_t L_75 = ___1_pcm_ptr;
		int32_t L_76 = ___2_frame_size;
		int32_t L_77 = __this->___Fs;
		StereoWidthState_t6D080EFAD3AC590D3319CE7BA4DDA0132E7822A2* L_78 = __this->___width_mem;
		int32_t L_79;
		L_79 = CodecHelpers_compute_stereo_width_mA9CC3FA2171877D74ABBB105235A850A5719949E(L_74, L_75, L_76, L_77, L_78, NULL);
		V_27 = L_79;
		goto IL_0273;
	}

IL_0270:
	{
		V_27 = 0;
	}

IL_0273:
	{
		int32_t L_80 = V_20;
		V_26 = L_80;
		int32_t L_81 = __this->___user_bitrate_bps;
		int32_t L_82 = ___2_frame_size;
		int32_t L_83 = V_25;
		int32_t L_84;
		L_84 = OpusEncoder_user_bitrate_to_bitrate_m18DBA826BE2FA33650295C2A6CD39A9E9C8D683F(__this, L_81, L_82, L_83, NULL);
		__this->___bitrate_bps = L_84;
		int32_t L_85 = __this->___Fs;
		int32_t L_86 = ___2_frame_size;
		V_21 = ((int32_t)(L_85/L_86));
		int32_t L_87 = __this->___use_vbr;
		if (L_87)
		{
			goto IL_02d8;
		}
	}
	{
		int32_t L_88 = __this->___Fs;
		int32_t L_89 = ___2_frame_size;
		V_35 = ((int32_t)(((int32_t)il2cpp_codegen_multiply(3, L_88))/L_89));
		int32_t L_90 = __this->___bitrate_bps;
		int32_t L_91 = V_35;
		int32_t L_92 = V_35;
		int32_t L_93 = V_25;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_94;
		L_94 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)(((int32_t)il2cpp_codegen_add(((int32_t)(((int32_t)il2cpp_codegen_multiply(3, L_90))/8)), ((int32_t)(L_91/2))))/L_92)), L_93, NULL);
		V_34 = L_94;
		int32_t L_95 = V_34;
		int32_t L_96 = V_35;
		__this->___bitrate_bps = ((int32_t)(((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_multiply(L_95, L_96)), 8))/3));
		int32_t L_97 = V_34;
		V_25 = L_97;
	}

IL_02d8:
	{
		int32_t L_98 = V_25;
		if ((((int32_t)L_98) < ((int32_t)3)))
		{
			goto IL_0310;
		}
	}
	{
		int32_t L_99 = __this->___bitrate_bps;
		int32_t L_100 = V_21;
		if ((((int32_t)L_99) < ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_multiply(3, L_100)), 8)))))
		{
			goto IL_0310;
		}
	}
	{
		int32_t L_101 = V_21;
		if ((((int32_t)L_101) >= ((int32_t)((int32_t)50))))
		{
			goto IL_03dd;
		}
	}
	{
		int32_t L_102 = V_25;
		int32_t L_103 = V_21;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(L_102, L_103))) < ((int32_t)((int32_t)300))))
		{
			goto IL_0310;
		}
	}
	{
		int32_t L_104 = __this->___bitrate_bps;
		if ((((int32_t)L_104) >= ((int32_t)((int32_t)2400))))
		{
			goto IL_03dd;
		}
	}

IL_0310:
	{
		int32_t L_105 = __this->___mode;
		V_36 = L_105;
		int32_t L_106 = __this->___bandwidth;
		if (!L_106)
		{
			goto IL_0328;
		}
	}
	{
		int32_t L_107 = __this->___bandwidth;
		G_B46_0 = ((int32_t)(L_107));
		goto IL_032d;
	}

IL_0328:
	{
		G_B46_0 = ((int32_t)1101);
	}

IL_032d:
	{
		V_37 = (int32_t)G_B46_0;
		int32_t L_108 = V_36;
		if (L_108)
		{
			goto IL_033a;
		}
	}
	{
		V_36 = (int32_t)((int32_t)1000);
	}

IL_033a:
	{
		int32_t L_109 = V_21;
		if ((((int32_t)L_109) <= ((int32_t)((int32_t)100))))
		{
			goto IL_0347;
		}
	}
	{
		V_36 = (int32_t)((int32_t)1002);
	}

IL_0347:
	{
		int32_t L_110 = V_21;
		if ((((int32_t)L_110) >= ((int32_t)((int32_t)50))))
		{
			goto IL_0354;
		}
	}
	{
		V_36 = (int32_t)((int32_t)1000);
	}

IL_0354:
	{
		int32_t L_111 = V_36;
		if ((!(((uint32_t)L_111) == ((uint32_t)((int32_t)1000)))))
		{
			goto IL_036f;
		}
	}
	{
		int32_t L_112 = V_37;
		if ((((int32_t)L_112) <= ((int32_t)((int32_t)1103))))
		{
			goto IL_036f;
		}
	}
	{
		V_37 = (int32_t)((int32_t)1103);
		goto IL_03a3;
	}

IL_036f:
	{
		int32_t L_113 = V_36;
		if ((!(((uint32_t)L_113) == ((uint32_t)((int32_t)1002)))))
		{
			goto IL_038a;
		}
	}
	{
		int32_t L_114 = V_37;
		if ((!(((uint32_t)L_114) == ((uint32_t)((int32_t)1102)))))
		{
			goto IL_038a;
		}
	}
	{
		V_37 = (int32_t)((int32_t)1101);
		goto IL_03a3;
	}

IL_038a:
	{
		int32_t L_115 = V_36;
		if ((!(((uint32_t)L_115) == ((uint32_t)((int32_t)1001)))))
		{
			goto IL_03a3;
		}
	}
	{
		int32_t L_116 = V_37;
		if ((((int32_t)L_116) > ((int32_t)((int32_t)1104))))
		{
			goto IL_03a3;
		}
	}
	{
		V_37 = (int32_t)((int32_t)1104);
	}

IL_03a3:
	{
		int32_t L_117 = ___4_data_ptr;
		uint8_t* L_118;
		L_118 = il2cpp_span_get_item((uint8_t*)((Il2CppByReference*)&(((&___3_data))->____pointer))->value, (L_117), ((&___3_data))->____length);
		int32_t L_119 = V_36;
		int32_t L_120 = V_21;
		int32_t L_121 = V_37;
		int32_t L_122 = __this->___stream_channels;
		uint8_t L_123;
		L_123 = CodecHelpers_gen_toc_m55919D0EC27589F5328AD925AA91F8B0D4A9EBA2(L_119, L_120, L_121, L_122, NULL);
		*((int8_t*)L_118) = (int8_t)L_123;
		V_3 = 1;
		int32_t L_124 = __this->___use_vbr;
		if (L_124)
		{
			goto IL_03db;
		}
	}
	{
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_125 = ___3_data;
		int32_t L_126 = ___4_data_ptr;
		int32_t L_127 = V_3;
		int32_t L_128 = V_25;
		int32_t L_129;
		L_129 = OpusRepacketizer_PadPacket_m31BC672C1100238AAE7DF0EEC74000D8CD39AD8E(L_125, L_126, L_127, L_128, NULL);
		V_3 = L_129;
		int32_t L_130 = V_3;
		if (L_130)
		{
			goto IL_03db;
		}
	}
	{
		int32_t L_131 = V_25;
		V_3 = L_131;
	}

IL_03db:
	{
		int32_t L_132 = V_3;
		return L_132;
	}

IL_03dd:
	{
		int32_t L_133 = V_21;
		int32_t L_134 = V_25;
		V_22 = ((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_multiply(L_133, L_134)), 8));
		int32_t L_135 = __this->___bitrate_bps;
		int32_t L_136 = __this->___channels;
		int32_t L_137 = __this->___Fs;
		int32_t L_138 = ___2_frame_size;
		V_19 = ((int32_t)il2cpp_codegen_subtract(L_135, ((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)40), L_136)), ((int32_t)20))), ((int32_t)il2cpp_codegen_subtract(((int32_t)(L_137/L_138)), ((int32_t)50)))))));
		int32_t L_139 = __this->___signal_type;
		if ((!(((uint32_t)L_139) == ((uint32_t)((int32_t)3001)))))
		{
			goto IL_041a;
		}
	}
	{
		V_18 = ((int32_t)127);
		goto IL_0476;
	}

IL_041a:
	{
		int32_t L_140 = __this->___signal_type;
		if ((!(((uint32_t)L_140) == ((uint32_t)((int32_t)3002)))))
		{
			goto IL_042c;
		}
	}
	{
		V_18 = 0;
		goto IL_0476;
	}

IL_042c:
	{
		int32_t L_141 = __this->___voice_ratio;
		if ((((int32_t)L_141) < ((int32_t)0)))
		{
			goto IL_045f;
		}
	}
	{
		int32_t L_142 = __this->___voice_ratio;
		V_18 = ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_142, ((int32_t)327)))>>8));
		int32_t L_143 = __this->___application;
		if ((!(((uint32_t)L_143) == ((uint32_t)((int32_t)2049)))))
		{
			goto IL_0476;
		}
	}
	{
		int32_t L_144 = V_18;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_145;
		L_145 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(L_144, ((int32_t)115), NULL);
		V_18 = L_145;
		goto IL_0476;
	}

IL_045f:
	{
		int32_t L_146 = __this->___application;
		if ((!(((uint32_t)L_146) == ((uint32_t)((int32_t)2048)))))
		{
			goto IL_0472;
		}
	}
	{
		V_18 = ((int32_t)115);
		goto IL_0476;
	}

IL_0472:
	{
		V_18 = ((int32_t)48);
	}

IL_0476:
	{
		int32_t L_147 = __this->___force_channels;
		if ((((int32_t)L_147) == ((int32_t)((int32_t)-1000))))
		{
			goto IL_049a;
		}
	}
	{
		int32_t L_148 = __this->___channels;
		if ((!(((uint32_t)L_148) == ((uint32_t)2))))
		{
			goto IL_049a;
		}
	}
	{
		int32_t L_149 = __this->___force_channels;
		__this->___stream_channels = L_149;
		goto IL_04ec;
	}

IL_049a:
	{
		int32_t L_150 = __this->___channels;
		if ((!(((uint32_t)L_150) == ((uint32_t)2))))
		{
			goto IL_04e0;
		}
	}
	{
		V_38 = ((int32_t)il2cpp_codegen_add(((int32_t)30000), ((int32_t)(0>>((int32_t)14)))));
		int32_t L_151 = __this->___stream_channels;
		if ((!(((uint32_t)L_151) == ((uint32_t)2))))
		{
			goto IL_04c4;
		}
	}
	{
		int32_t L_152 = V_38;
		V_38 = ((int32_t)il2cpp_codegen_subtract(L_152, ((int32_t)1000)));
		goto IL_04ce;
	}

IL_04c4:
	{
		int32_t L_153 = V_38;
		V_38 = ((int32_t)il2cpp_codegen_add(L_153, ((int32_t)1000)));
	}

IL_04ce:
	{
		int32_t L_154 = V_19;
		int32_t L_155 = V_38;
		if ((((int32_t)L_154) > ((int32_t)L_155)))
		{
			G_B84_0 = __this;
			goto IL_04d8;
		}
		G_B83_0 = __this;
	}
	{
		G_B85_0 = 1;
		G_B85_1 = G_B83_0;
		goto IL_04d9;
	}

IL_04d8:
	{
		G_B85_0 = 2;
		G_B85_1 = G_B84_0;
	}

IL_04d9:
	{
		NullCheck(G_B85_1);
		G_B85_1->___stream_channels = G_B85_0;
		goto IL_04ec;
	}

IL_04e0:
	{
		int32_t L_156 = __this->___channels;
		__this->___stream_channels = L_156;
	}

IL_04ec:
	{
		int32_t L_157 = __this->___bitrate_bps;
		int32_t L_158 = __this->___stream_channels;
		int32_t L_159 = __this->___Fs;
		int32_t L_160 = ___2_frame_size;
		V_19 = ((int32_t)il2cpp_codegen_subtract(L_157, ((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)40), L_158)), ((int32_t)20))), ((int32_t)il2cpp_codegen_subtract(((int32_t)(L_159/L_160)), ((int32_t)50)))))));
		int32_t L_161 = __this->___application;
		if ((!(((uint32_t)L_161) == ((uint32_t)((int32_t)2051)))))
		{
			goto IL_052a;
		}
	}
	{
		__this->___mode = (int32_t)((int32_t)1002);
		goto IL_0655;
	}

IL_052a:
	{
		int32_t L_162 = __this->___user_forced_mode;
		if ((!(((uint32_t)L_162) == ((uint32_t)((int32_t)-1000)))))
		{
			goto IL_0649;
		}
	}
	{
		int32_t L_163 = V_27;
		il2cpp_codegen_runtime_class_init_inline(Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var);
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_164 = ((Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_StaticFields*)il2cpp_codegen_static_fields_for(Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var))->___mode_thresholds;
		NullCheck(L_164);
		int32_t L_165 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_166 = (L_164)->GetAt(static_cast<il2cpp_array_size_t>(L_165));
		NullCheck(L_166);
		int32_t L_167 = 0;
		int32_t L_168 = (L_166)->GetAt(static_cast<il2cpp_array_size_t>(L_167));
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_169;
		L_169 = Inlines_MULT16_32_Q15_m26878C33EF631092FEDA6A0054F6B2C0D0B256B2_inline(((int32_t)il2cpp_codegen_subtract(((int32_t)32767), L_163)), L_168, NULL);
		int32_t L_170 = V_27;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_171 = ((Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_StaticFields*)il2cpp_codegen_static_fields_for(Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var))->___mode_thresholds;
		NullCheck(L_171);
		int32_t L_172 = 1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_173 = (L_171)->GetAt(static_cast<il2cpp_array_size_t>(L_172));
		NullCheck(L_173);
		int32_t L_174 = 0;
		int32_t L_175 = (L_173)->GetAt(static_cast<il2cpp_array_size_t>(L_174));
		int32_t L_176;
		L_176 = Inlines_MULT16_32_Q15_m26878C33EF631092FEDA6A0054F6B2C0D0B256B2_inline(L_170, L_175, NULL);
		V_39 = ((int32_t)il2cpp_codegen_add(L_169, L_176));
		int32_t L_177 = V_27;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_178 = ((Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_StaticFields*)il2cpp_codegen_static_fields_for(Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var))->___mode_thresholds;
		NullCheck(L_178);
		int32_t L_179 = 1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_180 = (L_178)->GetAt(static_cast<il2cpp_array_size_t>(L_179));
		NullCheck(L_180);
		int32_t L_181 = 1;
		int32_t L_182 = (L_180)->GetAt(static_cast<il2cpp_array_size_t>(L_181));
		int32_t L_183;
		L_183 = Inlines_MULT16_32_Q15_m26878C33EF631092FEDA6A0054F6B2C0D0B256B2_inline(((int32_t)il2cpp_codegen_subtract(((int32_t)32767), L_177)), L_182, NULL);
		int32_t L_184 = V_27;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_185 = ((Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_StaticFields*)il2cpp_codegen_static_fields_for(Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var))->___mode_thresholds;
		NullCheck(L_185);
		int32_t L_186 = 1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_187 = (L_185)->GetAt(static_cast<il2cpp_array_size_t>(L_186));
		NullCheck(L_187);
		int32_t L_188 = 1;
		int32_t L_189 = (L_187)->GetAt(static_cast<il2cpp_array_size_t>(L_188));
		int32_t L_190;
		L_190 = Inlines_MULT16_32_Q15_m26878C33EF631092FEDA6A0054F6B2C0D0B256B2_inline(L_184, L_189, NULL);
		V_40 = ((int32_t)il2cpp_codegen_add(L_183, L_190));
		int32_t L_191 = V_40;
		int32_t L_192 = V_18;
		int32_t L_193 = V_18;
		int32_t L_194 = V_39;
		int32_t L_195 = V_40;
		V_41 = ((int32_t)il2cpp_codegen_add(L_191, ((int32_t)(((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_multiply(L_192, L_193)), ((int32_t)il2cpp_codegen_subtract(L_194, L_195))))>>((int32_t)14)))));
		int32_t L_196 = __this->___application;
		if ((!(((uint32_t)L_196) == ((uint32_t)((int32_t)2048)))))
		{
			goto IL_05b6;
		}
	}
	{
		int32_t L_197 = V_41;
		V_41 = ((int32_t)il2cpp_codegen_add(L_197, ((int32_t)8000)));
	}

IL_05b6:
	{
		int32_t L_198 = __this->___prev_mode;
		if ((!(((uint32_t)L_198) == ((uint32_t)((int32_t)1002)))))
		{
			goto IL_05cf;
		}
	}
	{
		int32_t L_199 = V_41;
		V_41 = ((int32_t)il2cpp_codegen_subtract(L_199, ((int32_t)4000)));
		goto IL_05e2;
	}

IL_05cf:
	{
		int32_t L_200 = __this->___prev_mode;
		if ((((int32_t)L_200) <= ((int32_t)0)))
		{
			goto IL_05e2;
		}
	}
	{
		int32_t L_201 = V_41;
		V_41 = ((int32_t)il2cpp_codegen_add(L_201, ((int32_t)4000)));
	}

IL_05e2:
	{
		int32_t L_202 = V_19;
		int32_t L_203 = V_41;
		if ((((int32_t)L_202) >= ((int32_t)L_203)))
		{
			G_B98_0 = __this;
			goto IL_05f0;
		}
		G_B97_0 = __this;
	}
	{
		G_B99_0 = ((int32_t)1000);
		G_B99_1 = G_B97_0;
		goto IL_05f5;
	}

IL_05f0:
	{
		G_B99_0 = ((int32_t)1002);
		G_B99_1 = G_B98_0;
	}

IL_05f5:
	{
		NullCheck(G_B99_1);
		G_B99_1->___mode = (int32_t)G_B99_0;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_204 = __this->___silk_mode;
		NullCheck(L_204);
		int32_t L_205 = L_204->___useInBandFEC;
		if (!L_205)
		{
			goto IL_0629;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_206 = __this->___silk_mode;
		NullCheck(L_206);
		int32_t L_207 = L_206->___packetLossPercentage;
		int32_t L_208 = V_18;
		if ((((int32_t)L_207) <= ((int32_t)((int32_t)(((int32_t)il2cpp_codegen_subtract(((int32_t)128), L_208))>>4)))))
		{
			goto IL_0629;
		}
	}
	{
		__this->___mode = (int32_t)((int32_t)1000);
	}

IL_0629:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_209 = __this->___silk_mode;
		NullCheck(L_209);
		int32_t L_210 = L_209->___useDTX;
		if (!L_210)
		{
			goto IL_0655;
		}
	}
	{
		int32_t L_211 = V_18;
		if ((((int32_t)L_211) <= ((int32_t)((int32_t)100))))
		{
			goto IL_0655;
		}
	}
	{
		__this->___mode = (int32_t)((int32_t)1000);
		goto IL_0655;
	}

IL_0649:
	{
		int32_t L_212 = __this->___user_forced_mode;
		__this->___mode = L_212;
	}

IL_0655:
	{
		int32_t L_213 = __this->___mode;
		if ((((int32_t)L_213) == ((int32_t)((int32_t)1002))))
		{
			goto IL_0679;
		}
	}
	{
		int32_t L_214 = ___2_frame_size;
		int32_t L_215 = __this->___Fs;
		if ((((int32_t)L_214) >= ((int32_t)((int32_t)(L_215/((int32_t)100))))))
		{
			goto IL_0679;
		}
	}
	{
		__this->___mode = (int32_t)((int32_t)1002);
	}

IL_0679:
	{
		int32_t L_216 = __this->___lfe;
		if (!L_216)
		{
			goto IL_068c;
		}
	}
	{
		__this->___mode = (int32_t)((int32_t)1002);
	}

IL_068c:
	{
		int32_t L_217 = V_25;
		int32_t L_218 = V_21;
		if ((((int32_t)L_218) > ((int32_t)((int32_t)50))))
		{
			G_B113_0 = L_217;
			goto IL_069b;
		}
		G_B112_0 = L_217;
	}
	{
		G_B114_0 = ((int32_t)8000);
		G_B114_1 = G_B112_0;
		goto IL_06a0;
	}

IL_069b:
	{
		G_B114_0 = ((int32_t)12000);
		G_B114_1 = G_B113_0;
	}

IL_06a0:
	{
		int32_t L_219 = ___2_frame_size;
		int32_t L_220 = __this->___Fs;
		if ((((int32_t)G_B114_1) >= ((int32_t)((int32_t)(((int32_t)il2cpp_codegen_multiply(G_B114_0, L_219))/((int32_t)il2cpp_codegen_multiply(L_220, 8)))))))
		{
			goto IL_06b8;
		}
	}
	{
		__this->___mode = (int32_t)((int32_t)1002);
	}

IL_06b8:
	{
		int32_t L_221 = __this->___stream_channels;
		if ((!(((uint32_t)L_221) == ((uint32_t)1))))
		{
			goto IL_0706;
		}
	}
	{
		int32_t L_222 = __this->___prev_channels;
		if ((!(((uint32_t)L_222) == ((uint32_t)2))))
		{
			goto IL_0706;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_223 = __this->___silk_mode;
		NullCheck(L_223);
		int32_t L_224 = L_223->___toMono;
		if (L_224)
		{
			goto IL_0706;
		}
	}
	{
		int32_t L_225 = __this->___mode;
		if ((((int32_t)L_225) == ((int32_t)((int32_t)1002))))
		{
			goto IL_0706;
		}
	}
	{
		int32_t L_226 = __this->___prev_mode;
		if ((((int32_t)L_226) == ((int32_t)((int32_t)1002))))
		{
			goto IL_0706;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_227 = __this->___silk_mode;
		NullCheck(L_227);
		L_227->___toMono = 1;
		__this->___stream_channels = 2;
		goto IL_0712;
	}

IL_0706:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_228 = __this->___silk_mode;
		NullCheck(L_228);
		L_228->___toMono = 0;
	}

IL_0712:
	{
		int32_t L_229 = __this->___prev_mode;
		if ((((int32_t)L_229) <= ((int32_t)0)))
		{
			goto IL_0789;
		}
	}
	{
		int32_t L_230 = __this->___mode;
		if ((((int32_t)L_230) == ((int32_t)((int32_t)1002))))
		{
			goto IL_0735;
		}
	}
	{
		int32_t L_231 = __this->___prev_mode;
		if ((((int32_t)L_231) == ((int32_t)((int32_t)1002))))
		{
			goto IL_074f;
		}
	}

IL_0735:
	{
		int32_t L_232 = __this->___mode;
		if ((!(((uint32_t)L_232) == ((uint32_t)((int32_t)1002)))))
		{
			goto IL_0789;
		}
	}
	{
		int32_t L_233 = __this->___prev_mode;
		if ((((int32_t)L_233) == ((int32_t)((int32_t)1002))))
		{
			goto IL_0789;
		}
	}

IL_074f:
	{
		V_9 = 1;
		int32_t L_234 = __this->___mode;
		if ((!(((uint32_t)L_234) == ((uint32_t)((int32_t)1002)))))
		{
			goto IL_0762;
		}
	}
	{
		G_B131_0 = 0;
		goto IL_0763;
	}

IL_0762:
	{
		G_B131_0 = 1;
	}

IL_0763:
	{
		V_11 = G_B131_0;
		int32_t L_235 = V_11;
		if (L_235)
		{
			goto IL_0789;
		}
	}
	{
		int32_t L_236 = ___2_frame_size;
		int32_t L_237 = __this->___Fs;
		if ((((int32_t)L_236) < ((int32_t)((int32_t)(L_237/((int32_t)100))))))
		{
			goto IL_0786;
		}
	}
	{
		int32_t L_238 = __this->___prev_mode;
		__this->___mode = L_238;
		V_14 = 1;
		goto IL_0789;
	}

IL_0786:
	{
		V_9 = 0;
	}

IL_0789:
	{
		int32_t L_239 = __this->___silk_bw_switch;
		if (!L_239)
		{
			goto IL_07a1;
		}
	}
	{
		V_9 = 1;
		V_11 = 1;
		__this->___silk_bw_switch = 0;
		V_7 = 1;
	}

IL_07a1:
	{
		int32_t L_240 = V_9;
		if (!L_240)
		{
			goto IL_07ec;
		}
	}
	{
		int32_t L_241 = V_25;
		int32_t L_242 = __this->___Fs;
		int32_t L_243 = ___2_frame_size;
		int32_t L_244 = __this->___Fs;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_245;
		L_245 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)257), ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_241, ((int32_t)(L_242/((int32_t)200)))))/((int32_t)il2cpp_codegen_add(L_243, ((int32_t)(L_244/((int32_t)200))))))), NULL);
		V_10 = L_245;
		int32_t L_246 = __this->___use_vbr;
		if (!L_246)
		{
			goto IL_07ec;
		}
	}
	{
		int32_t L_247 = V_10;
		int32_t L_248 = __this->___bitrate_bps;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_249;
		L_249 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(L_247, ((int32_t)(L_248/((int32_t)1600))), NULL);
		V_10 = L_249;
	}

IL_07ec:
	{
		int32_t L_250 = __this->___mode;
		if ((((int32_t)L_250) == ((int32_t)((int32_t)1002))))
		{
			goto IL_0819;
		}
	}
	{
		int32_t L_251 = __this->___prev_mode;
		if ((!(((uint32_t)L_251) == ((uint32_t)((int32_t)1002)))))
		{
			goto IL_0819;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_252 = (EncControlState_t1F753CF3968665C2171A288F862D70168F348019*)il2cpp_codegen_object_new(EncControlState_t1F753CF3968665C2171A288F862D70168F348019_il2cpp_TypeInfo_var);
		EncControlState__ctor_mCAD689C6947CC4E7B25982B1948387269E41363C(L_252, NULL);
		V_42 = L_252;
		SilkEncoder_t7AB5C2F712CDB92EBFCDAF8E9743C5A39B7CFD6D* L_253 = V_0;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_254 = V_42;
		int32_t L_255;
		L_255 = EncodeAPI_silk_InitEncoder_m09EF9258259F34A9CE9707CB9463B3CA9C3D4B42(L_253, L_254, NULL);
		V_7 = 1;
	}

IL_0819:
	{
		int32_t L_256 = __this->___mode;
		if ((((int32_t)L_256) == ((int32_t)((int32_t)1002))))
		{
			goto IL_083e;
		}
	}
	{
		int32_t L_257 = __this->___first;
		if (L_257)
		{
			goto IL_083e;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_258 = __this->___silk_mode;
		NullCheck(L_258);
		int32_t L_259 = L_258->___allowBandwidthSwitch;
		if (!L_259)
		{
			goto IL_0975;
		}
	}

IL_083e:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_260 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)8);
		V_45 = L_260;
		V_46 = (int32_t)((int32_t)1105);
		int32_t L_261 = V_19;
		V_47 = L_261;
		int32_t L_262 = __this->___mode;
		if ((((int32_t)L_262) == ((int32_t)((int32_t)1002))))
		{
			goto IL_0886;
		}
	}
	{
		int32_t L_263 = V_47;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_264 = __this->___silk_mode;
		NullCheck(L_264);
		int32_t L_265 = L_264->___complexity;
		V_47 = ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_263, ((int32_t)il2cpp_codegen_add(((int32_t)45), L_265))))/((int32_t)50)));
		int32_t L_266 = __this->___use_vbr;
		if (L_266)
		{
			goto IL_0886;
		}
	}
	{
		int32_t L_267 = V_47;
		V_47 = ((int32_t)il2cpp_codegen_subtract(L_267, ((int32_t)1000)));
	}

IL_0886:
	{
		int32_t L_268 = __this->___channels;
		if ((!(((uint32_t)L_268) == ((uint32_t)2))))
		{
			goto IL_08a8;
		}
	}
	{
		int32_t L_269 = __this->___force_channels;
		if ((((int32_t)L_269) == ((int32_t)1)))
		{
			goto IL_08a8;
		}
	}
	{
		il2cpp_codegen_runtime_class_init_inline(Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_270 = ((Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_StaticFields*)il2cpp_codegen_static_fields_for(Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var))->___stereo_voice_bandwidth_thresholds;
		V_43 = L_270;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_271 = ((Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_StaticFields*)il2cpp_codegen_static_fields_for(Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var))->___stereo_music_bandwidth_thresholds;
		V_44 = L_271;
		goto IL_08b6;
	}

IL_08a8:
	{
		il2cpp_codegen_runtime_class_init_inline(Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_272 = ((Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_StaticFields*)il2cpp_codegen_static_fields_for(Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var))->___mono_voice_bandwidth_thresholds;
		V_43 = L_272;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_273 = ((Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_StaticFields*)il2cpp_codegen_static_fields_for(Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var))->___mono_music_bandwidth_thresholds;
		V_44 = L_273;
	}

IL_08b6:
	{
		V_2 = 0;
		goto IL_08d9;
	}

IL_08ba:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_274 = V_45;
		int32_t L_275 = V_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_276 = V_44;
		int32_t L_277 = V_2;
		NullCheck(L_276);
		int32_t L_278 = L_277;
		int32_t L_279 = (L_276)->GetAt(static_cast<il2cpp_array_size_t>(L_278));
		int32_t L_280 = V_18;
		int32_t L_281 = V_18;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_282 = V_43;
		int32_t L_283 = V_2;
		NullCheck(L_282);
		int32_t L_284 = L_283;
		int32_t L_285 = (L_282)->GetAt(static_cast<il2cpp_array_size_t>(L_284));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_286 = V_44;
		int32_t L_287 = V_2;
		NullCheck(L_286);
		int32_t L_288 = L_287;
		int32_t L_289 = (L_286)->GetAt(static_cast<il2cpp_array_size_t>(L_288));
		NullCheck(L_274);
		(L_274)->SetAt(static_cast<il2cpp_array_size_t>(L_275), (int32_t)((int32_t)il2cpp_codegen_add(L_279, ((int32_t)(((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_multiply(L_280, L_281)), ((int32_t)il2cpp_codegen_subtract(L_285, L_289))))>>((int32_t)14))))));
		int32_t L_290 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_290, 1));
	}

IL_08d9:
	{
		int32_t L_291 = V_2;
		if ((((int32_t)L_291) < ((int32_t)8)))
		{
			goto IL_08ba;
		}
	}

IL_08dd:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_292 = V_45;
		int32_t L_293 = V_46;
		NullCheck(L_292);
		int32_t L_294 = ((int32_t)il2cpp_codegen_multiply(2, ((int32_t)il2cpp_codegen_subtract((int32_t)L_293, ((int32_t)1102)))));
		int32_t L_295 = (L_292)->GetAt(static_cast<il2cpp_array_size_t>(L_294));
		V_48 = L_295;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_296 = V_45;
		int32_t L_297 = V_46;
		NullCheck(L_296);
		int32_t L_298 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(2, ((int32_t)il2cpp_codegen_subtract((int32_t)L_297, ((int32_t)1102))))), 1));
		int32_t L_299 = (L_296)->GetAt(static_cast<il2cpp_array_size_t>(L_298));
		V_49 = L_299;
		int32_t L_300 = __this->___first;
		if (L_300)
		{
			goto IL_091f;
		}
	}
	{
		int32_t L_301 = __this->___bandwidth;
		int32_t L_302 = V_46;
		if ((((int32_t)L_301) < ((int32_t)L_302)))
		{
			goto IL_0918;
		}
	}
	{
		int32_t L_303 = V_48;
		int32_t L_304 = V_49;
		V_48 = ((int32_t)il2cpp_codegen_subtract(L_303, L_304));
		goto IL_091f;
	}

IL_0918:
	{
		int32_t L_305 = V_48;
		int32_t L_306 = V_49;
		V_48 = ((int32_t)il2cpp_codegen_add(L_305, L_306));
	}

IL_091f:
	{
		int32_t L_307 = V_47;
		int32_t L_308 = V_48;
		if ((((int32_t)L_307) >= ((int32_t)L_308)))
		{
			goto IL_0933;
		}
	}
	{
		int32_t L_309 = V_46;
		int32_t L_310 = ((int32_t)il2cpp_codegen_subtract((int32_t)L_309, 1));
		V_46 = (int32_t)L_310;
		if ((((int32_t)L_310) > ((int32_t)((int32_t)1101))))
		{
			goto IL_08dd;
		}
	}

IL_0933:
	{
		int32_t L_311 = V_46;
		__this->___bandwidth = L_311;
		int32_t L_312 = __this->___first;
		if (L_312)
		{
			goto IL_0975;
		}
	}
	{
		int32_t L_313 = __this->___mode;
		if ((((int32_t)L_313) == ((int32_t)((int32_t)1002))))
		{
			goto IL_0975;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_314 = __this->___silk_mode;
		NullCheck(L_314);
		int32_t L_315 = L_314->___inWBmodeWithoutVariableLP;
		if (L_315)
		{
			goto IL_0975;
		}
	}
	{
		int32_t L_316 = __this->___bandwidth;
		if ((((int32_t)L_316) <= ((int32_t)((int32_t)1103))))
		{
			goto IL_0975;
		}
	}
	{
		__this->___bandwidth = (int32_t)((int32_t)1103);
	}

IL_0975:
	{
		int32_t L_317 = __this->___bandwidth;
		int32_t L_318 = __this->___max_bandwidth;
		if ((((int32_t)L_317) <= ((int32_t)L_318)))
		{
			goto IL_098f;
		}
	}
	{
		int32_t L_319 = __this->___max_bandwidth;
		__this->___bandwidth = L_319;
	}

IL_098f:
	{
		int32_t L_320 = __this->___user_bandwidth;
		if ((((int32_t)L_320) == ((int32_t)((int32_t)-1000))))
		{
			goto IL_09a8;
		}
	}
	{
		int32_t L_321 = __this->___user_bandwidth;
		__this->___bandwidth = L_321;
	}

IL_09a8:
	{
		int32_t L_322 = __this->___mode;
		if ((((int32_t)L_322) == ((int32_t)((int32_t)1002))))
		{
			goto IL_09d4;
		}
	}
	{
		int32_t L_323 = V_22;
		if ((((int32_t)L_323) >= ((int32_t)((int32_t)15000))))
		{
			goto IL_09d4;
		}
	}
	{
		int32_t L_324 = __this->___bandwidth;
		int32_t L_325;
		L_325 = OpusBandwidthHelpers_MIN_m35CCCD819EE4224365BF648B953A8ADC347EA987(L_324, (int32_t)((int32_t)1103), NULL);
		__this->___bandwidth = L_325;
	}

IL_09d4:
	{
		int32_t L_326 = __this->___Fs;
		if ((((int32_t)L_326) > ((int32_t)((int32_t)24000))))
		{
			goto IL_09f9;
		}
	}
	{
		int32_t L_327 = __this->___bandwidth;
		if ((((int32_t)L_327) <= ((int32_t)((int32_t)1104))))
		{
			goto IL_09f9;
		}
	}
	{
		__this->___bandwidth = (int32_t)((int32_t)1104);
	}

IL_09f9:
	{
		int32_t L_328 = __this->___Fs;
		if ((((int32_t)L_328) > ((int32_t)((int32_t)16000))))
		{
			goto IL_0a1e;
		}
	}
	{
		int32_t L_329 = __this->___bandwidth;
		if ((((int32_t)L_329) <= ((int32_t)((int32_t)1103))))
		{
			goto IL_0a1e;
		}
	}
	{
		__this->___bandwidth = (int32_t)((int32_t)1103);
	}

IL_0a1e:
	{
		int32_t L_330 = __this->___Fs;
		if ((((int32_t)L_330) > ((int32_t)((int32_t)12000))))
		{
			goto IL_0a43;
		}
	}
	{
		int32_t L_331 = __this->___bandwidth;
		if ((((int32_t)L_331) <= ((int32_t)((int32_t)1102))))
		{
			goto IL_0a43;
		}
	}
	{
		__this->___bandwidth = (int32_t)((int32_t)1102);
	}

IL_0a43:
	{
		int32_t L_332 = __this->___Fs;
		if ((((int32_t)L_332) > ((int32_t)((int32_t)8000))))
		{
			goto IL_0a68;
		}
	}
	{
		int32_t L_333 = __this->___bandwidth;
		if ((((int32_t)L_333) <= ((int32_t)((int32_t)1101))))
		{
			goto IL_0a68;
		}
	}
	{
		__this->___bandwidth = (int32_t)((int32_t)1101);
	}

IL_0a68:
	{
		int32_t L_334 = __this->___detected_bandwidth;
		if (!L_334)
		{
			goto IL_0b32;
		}
	}
	{
		int32_t L_335 = __this->___user_bandwidth;
		if ((!(((uint32_t)L_335) == ((uint32_t)((int32_t)-1000)))))
		{
			goto IL_0b32;
		}
	}
	{
		int32_t L_336 = V_19;
		int32_t L_337 = __this->___stream_channels;
		if ((((int32_t)L_336) > ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)18000), L_337)))))
		{
			goto IL_0aa9;
		}
	}
	{
		int32_t L_338 = __this->___mode;
		if ((!(((uint32_t)L_338) == ((uint32_t)((int32_t)1002)))))
		{
			goto IL_0aa9;
		}
	}
	{
		V_50 = (int32_t)((int32_t)1101);
		goto IL_0b08;
	}

IL_0aa9:
	{
		int32_t L_339 = V_19;
		int32_t L_340 = __this->___stream_channels;
		if ((((int32_t)L_339) > ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)24000), L_340)))))
		{
			goto IL_0acf;
		}
	}
	{
		int32_t L_341 = __this->___mode;
		if ((!(((uint32_t)L_341) == ((uint32_t)((int32_t)1002)))))
		{
			goto IL_0acf;
		}
	}
	{
		V_50 = (int32_t)((int32_t)1102);
		goto IL_0b08;
	}

IL_0acf:
	{
		int32_t L_342 = V_19;
		int32_t L_343 = __this->___stream_channels;
		if ((((int32_t)L_342) > ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)30000), L_343)))))
		{
			goto IL_0ae8;
		}
	}
	{
		V_50 = (int32_t)((int32_t)1103);
		goto IL_0b08;
	}

IL_0ae8:
	{
		int32_t L_344 = V_19;
		int32_t L_345 = __this->___stream_channels;
		if ((((int32_t)L_344) > ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)44000), L_345)))))
		{
			goto IL_0b01;
		}
	}
	{
		V_50 = (int32_t)((int32_t)1104);
		goto IL_0b08;
	}

IL_0b01:
	{
		V_50 = (int32_t)((int32_t)1105);
	}

IL_0b08:
	{
		int32_t L_346 = __this->___detected_bandwidth;
		int32_t L_347 = V_50;
		int32_t L_348;
		L_348 = OpusBandwidthHelpers_MAX_mF31797F605DA051DD3FB61542A8C376114316B83(L_346, L_347, NULL);
		__this->___detected_bandwidth = L_348;
		int32_t L_349 = __this->___bandwidth;
		int32_t L_350 = __this->___detected_bandwidth;
		int32_t L_351;
		L_351 = OpusBandwidthHelpers_MIN_m35CCCD819EE4224365BF648B953A8ADC347EA987(L_349, L_350, NULL);
		__this->___bandwidth = L_351;
	}

IL_0b32:
	{
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_352 = V_1;
		int32_t L_353 = ___6_lsb_depth;
		NullCheck(L_352);
		CeltEncoder_SetLSBDepth_mB8EDAF4F6B3646DDDFCA55BB31B350F8CAACCEE9(L_352, L_353, NULL);
		int32_t L_354 = __this->___mode;
		if ((!(((uint32_t)L_354) == ((uint32_t)((int32_t)1002)))))
		{
			goto IL_0b5f;
		}
	}
	{
		int32_t L_355 = __this->___bandwidth;
		if ((!(((uint32_t)L_355) == ((uint32_t)((int32_t)1102)))))
		{
			goto IL_0b5f;
		}
	}
	{
		__this->___bandwidth = (int32_t)((int32_t)1103);
	}

IL_0b5f:
	{
		int32_t L_356 = __this->___lfe;
		if (!L_356)
		{
			goto IL_0b72;
		}
	}
	{
		__this->___bandwidth = (int32_t)((int32_t)1101);
	}

IL_0b72:
	{
		int32_t L_357 = ___2_frame_size;
		int32_t L_358 = __this->___Fs;
		if ((((int32_t)L_357) <= ((int32_t)((int32_t)(L_358/((int32_t)50))))))
		{
			goto IL_0d77;
		}
	}
	{
		int32_t L_359 = __this->___mode;
		if ((((int32_t)L_359) == ((int32_t)((int32_t)1002))))
		{
			goto IL_0b9e;
		}
	}
	{
		int32_t L_360 = __this->___bandwidth;
		if ((((int32_t)L_360) <= ((int32_t)((int32_t)1103))))
		{
			goto IL_0d77;
		}
	}

IL_0b9e:
	{
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_361 = __this->___analysis;
		NullCheck(L_361);
		bool L_362 = L_361->___enabled;
		if (!L_362)
		{
			goto IL_0bca;
		}
	}
	{
		int32_t L_363 = V_30;
		if ((((int32_t)L_363) == ((int32_t)(-1))))
		{
			goto IL_0bca;
		}
	}
	{
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_364 = __this->___analysis;
		int32_t L_365 = V_30;
		NullCheck(L_364);
		L_364->___read_pos = L_365;
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_366 = __this->___analysis;
		int32_t L_367 = V_31;
		NullCheck(L_366);
		L_366->___read_subframe = L_367;
	}

IL_0bca:
	{
		int32_t L_368 = ___2_frame_size;
		int32_t L_369 = __this->___Fs;
		if ((((int32_t)L_368) > ((int32_t)((int32_t)(L_369/((int32_t)25))))))
		{
			goto IL_0bd9;
		}
	}
	{
		G_B214_0 = 2;
		goto IL_0bda;
	}

IL_0bd9:
	{
		G_B214_0 = 3;
	}

IL_0bda:
	{
		V_52 = G_B214_0;
		int32_t L_370 = ___5_out_data_bytes;
		int32_t L_371 = V_52;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_372;
		L_372 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)1276), ((int32_t)(((int32_t)il2cpp_codegen_subtract(L_370, 3))/L_371)), NULL);
		V_58 = L_372;
		int32_t L_373 = V_52;
		int32_t L_374 = V_58;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_375 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(L_373, L_374)));
		V_51 = L_375;
		OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* L_376 = (OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0*)il2cpp_codegen_object_new(OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0_il2cpp_TypeInfo_var);
		OpusRepacketizer__ctor_mC4456456D2AAD30181CA3EC5FF721E31477B6996(L_376, NULL);
		V_57 = L_376;
		int32_t L_377 = __this->___user_forced_mode;
		V_56 = L_377;
		int32_t L_378 = __this->___user_bandwidth;
		V_53 = L_378;
		int32_t L_379 = __this->___force_channels;
		V_54 = L_379;
		int32_t L_380 = __this->___mode;
		__this->___user_forced_mode = L_380;
		int32_t L_381 = __this->___bandwidth;
		__this->___user_bandwidth = L_381;
		int32_t L_382 = __this->___stream_channels;
		__this->___force_channels = L_382;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_383 = __this->___silk_mode;
		NullCheck(L_383);
		int32_t L_384 = L_383->___toMono;
		V_55 = L_384;
		int32_t L_385 = V_55;
		if (!L_385)
		{
			goto IL_0c58;
		}
	}
	{
		__this->___force_channels = 1;
		goto IL_0c64;
	}

IL_0c58:
	{
		int32_t L_386 = __this->___stream_channels;
		__this->___prev_channels = L_386;
	}

IL_0c64:
	{
		V_2 = 0;
		goto IL_0cfb;
	}

IL_0c6b:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_387 = __this->___silk_mode;
		NullCheck(L_387);
		L_387->___toMono = 0;
		int32_t L_388 = V_14;
		if (!L_388)
		{
			goto IL_0c8d;
		}
	}
	{
		int32_t L_389 = V_2;
		int32_t L_390 = V_52;
		if ((!(((uint32_t)L_389) == ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_390, 1))))))
		{
			goto IL_0c8d;
		}
	}
	{
		__this->___user_forced_mode = (int32_t)((int32_t)1002);
	}

IL_0c8d:
	{
		ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 L_391 = ___0_pcm;
		int32_t L_392 = ___1_pcm_ptr;
		int32_t L_393 = V_2;
		int32_t L_394 = __this->___channels;
		int32_t L_395 = __this->___Fs;
		int32_t L_396 = __this->___Fs;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_397 = V_51;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_398;
		L_398 = Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91(L_397, Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91_RuntimeMethod_var);
		int32_t L_399 = V_2;
		int32_t L_400 = V_58;
		int32_t L_401 = V_58;
		int32_t L_402 = ___6_lsb_depth;
		ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D L_403;
		L_403 = ReadOnlySpan_1_op_Implicit_m34F703695513C3D0AA303A14106E72DD7455C2F1((SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C*)NULL, il2cpp_rgctx_method(method->rgctx_data, 3));
		int32_t L_404 = ___9_c1;
		int32_t L_405 = ___10_c2;
		int32_t L_406 = ___11_analysis_channels;
		downmix_func_1_t8CB50463E746CCBB4FFAE8EC889A02B92ED9F08B* L_407 = ___12_downmix;
		int32_t L_408 = ___13_float_api;
		int32_t L_409;
		L_409 = OpusEncoder_opus_encode_native_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_mEC592DA223E634EAE136DDFFF74F938B95E398F1(__this, L_391, ((int32_t)il2cpp_codegen_add(L_392, ((int32_t)il2cpp_codegen_multiply(L_393, ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_394, L_395))/((int32_t)50))))))), ((int32_t)(L_396/((int32_t)50))), L_398, ((int32_t)il2cpp_codegen_multiply(L_399, L_400)), L_401, L_402, L_403, 0, L_404, L_405, L_406, L_407, L_408, il2cpp_rgctx_method(method->rgctx_data, 6));
		V_60 = L_409;
		int32_t L_410 = V_60;
		if ((((int32_t)L_410) >= ((int32_t)0)))
		{
			goto IL_0cdb;
		}
	}
	{
		return ((int32_t)-3);
	}

IL_0cdb:
	{
		OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* L_411 = V_57;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_412 = V_51;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_413;
		L_413 = Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91(L_412, Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91_RuntimeMethod_var);
		int32_t L_414 = V_2;
		int32_t L_415 = V_58;
		int32_t L_416 = V_60;
		NullCheck(L_411);
		int32_t L_417;
		L_417 = OpusRepacketizer_AddPacket_mEF0C260D9D7AF7EE2243A598509FBE6197D0F510(L_411, L_413, ((int32_t)il2cpp_codegen_multiply(L_414, L_415)), L_416, NULL);
		V_3 = L_417;
		int32_t L_418 = V_3;
		if ((((int32_t)L_418) >= ((int32_t)0)))
		{
			goto IL_0cf7;
		}
	}
	{
		return ((int32_t)-3);
	}

IL_0cf7:
	{
		int32_t L_419 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_419, 1));
	}

IL_0cfb:
	{
		int32_t L_420 = V_2;
		int32_t L_421 = V_52;
		if ((((int32_t)L_420) < ((int32_t)L_421)))
		{
			goto IL_0c6b;
		}
	}
	{
		int32_t L_422 = __this->___use_vbr;
		if (!L_422)
		{
			goto IL_0d11;
		}
	}
	{
		int32_t L_423 = ___5_out_data_bytes;
		V_59 = L_423;
		goto IL_0d2b;
	}

IL_0d11:
	{
		int32_t L_424 = __this->___bitrate_bps;
		int32_t L_425 = V_52;
		int32_t L_426 = ___5_out_data_bytes;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_427;
		L_427 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)(((int32_t)il2cpp_codegen_multiply(3, L_424))/((int32_t)(((int32_t)1200)/L_425)))), L_426, NULL);
		V_59 = L_427;
	}

IL_0d2b:
	{
		OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* L_428 = V_57;
		int32_t L_429 = V_52;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_430 = ___3_data;
		int32_t L_431 = ___4_data_ptr;
		int32_t L_432 = V_59;
		int32_t L_433 = __this->___use_vbr;
		if (!L_433)
		{
			G_B232_0 = 0;
			G_B232_1 = L_432;
			G_B232_2 = L_431;
			G_B232_3 = L_430;
			G_B232_4 = L_429;
			G_B232_5 = 0;
			G_B232_6 = L_428;
			goto IL_0d42;
		}
		G_B231_0 = 0;
		G_B231_1 = L_432;
		G_B231_2 = L_431;
		G_B231_3 = L_430;
		G_B231_4 = L_429;
		G_B231_5 = 0;
		G_B231_6 = L_428;
	}
	{
		G_B233_0 = 0;
		G_B233_1 = G_B231_0;
		G_B233_2 = G_B231_1;
		G_B233_3 = G_B231_2;
		G_B233_4 = G_B231_3;
		G_B233_5 = G_B231_4;
		G_B233_6 = G_B231_5;
		G_B233_7 = G_B231_6;
		goto IL_0d43;
	}

IL_0d42:
	{
		G_B233_0 = 1;
		G_B233_1 = G_B232_0;
		G_B233_2 = G_B232_1;
		G_B233_3 = G_B232_2;
		G_B233_4 = G_B232_3;
		G_B233_5 = G_B232_4;
		G_B233_6 = G_B232_5;
		G_B233_7 = G_B232_6;
	}

IL_0d43:
	{
		NullCheck(G_B233_7);
		int32_t L_434;
		L_434 = OpusRepacketizer_opus_repacketizer_out_range_impl_m580835FE0C1A5F8831B645CF5488B8ED9E443F13(G_B233_7, G_B233_6, G_B233_5, G_B233_4, G_B233_3, G_B233_2, G_B233_1, G_B233_0, NULL);
		V_3 = L_434;
		int32_t L_435 = V_3;
		if ((((int32_t)L_435) >= ((int32_t)0)))
		{
			goto IL_0d50;
		}
	}
	{
		return ((int32_t)-3);
	}

IL_0d50:
	{
		int32_t L_436 = V_56;
		__this->___user_forced_mode = L_436;
		int32_t L_437 = V_53;
		__this->___user_bandwidth = L_437;
		int32_t L_438 = V_54;
		__this->___force_channels = L_438;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_439 = __this->___silk_mode;
		int32_t L_440 = V_55;
		NullCheck(L_439);
		L_439->___toMono = L_440;
		int32_t L_441 = V_3;
		return L_441;
	}

IL_0d77:
	{
		int32_t L_442 = __this->___bandwidth;
		V_23 = L_442;
		int32_t L_443 = __this->___mode;
		if ((!(((uint32_t)L_443) == ((uint32_t)((int32_t)1000)))))
		{
			goto IL_0da0;
		}
	}
	{
		int32_t L_444 = V_23;
		if ((((int32_t)L_444) <= ((int32_t)((int32_t)1103))))
		{
			goto IL_0da0;
		}
	}
	{
		__this->___mode = (int32_t)((int32_t)1001);
	}

IL_0da0:
	{
		int32_t L_445 = __this->___mode;
		if ((!(((uint32_t)L_445) == ((uint32_t)((int32_t)1001)))))
		{
			goto IL_0dc1;
		}
	}
	{
		int32_t L_446 = V_23;
		if ((((int32_t)L_446) > ((int32_t)((int32_t)1103))))
		{
			goto IL_0dc1;
		}
	}
	{
		__this->___mode = (int32_t)((int32_t)1000);
	}

IL_0dc1:
	{
		int32_t L_447 = V_25;
		int32_t L_448 = V_10;
		int32_t L_449 = __this->___bitrate_bps;
		int32_t L_450 = ___2_frame_size;
		int32_t L_451 = __this->___Fs;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_452;
		L_452 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)il2cpp_codegen_subtract(L_447, L_448)), ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_449, L_450))/((int32_t)il2cpp_codegen_multiply(L_451, 8)))), NULL);
		V_6 = ((int32_t)il2cpp_codegen_subtract(L_452, 1));
		int32_t L_453 = ___4_data_ptr;
		___4_data_ptr = ((int32_t)il2cpp_codegen_add(L_453, 1));
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_454 = V_5;
		int32_t L_455 = V_25;
		NullCheck(L_454);
		EntropyCoder_enc_init_m0C80505BF71E0CAF14DAF6DCD1E2FA384F3B2C1D(L_454, (uint32_t)((int32_t)il2cpp_codegen_subtract(L_455, 1)), NULL);
		int32_t L_456 = V_26;
		int32_t L_457 = ___2_frame_size;
		int32_t L_458 = __this->___channels;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_459 = (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)SZArrayNew(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_add(L_456, L_457)), L_458)));
		V_12 = L_459;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_460 = __this->___delay_buffer;
		int32_t L_461 = __this->___encoder_buffer;
		int32_t L_462 = V_26;
		int32_t L_463 = __this->___channels;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_464 = V_12;
		int32_t L_465 = V_26;
		int32_t L_466 = __this->___channels;
		Arrays_MemCopy_m6694E7C365EE590A29753D43699215FBC8162E89(L_460, ((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_subtract(L_461, L_462)), L_463)), L_464, 0, ((int32_t)il2cpp_codegen_multiply(L_465, L_466)), NULL);
		int32_t L_467 = __this->___mode;
		if ((!(((uint32_t)L_467) == ((uint32_t)((int32_t)1002)))))
		{
			goto IL_0e48;
		}
	}
	{
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_468;
		L_468 = Inlines_silk_lin2log_m3D1BBF1C15B7B47836676F7D48D1DB73DF4B887C_inline(((int32_t)60), NULL);
		int32_t L_469;
		L_469 = Inlines_silk_LSHIFT_mE90E3163A0D3526D05046763E167F2271AB0B953_inline(L_468, 8, NULL);
		V_17 = L_469;
		goto IL_0e57;
	}

IL_0e48:
	{
		SilkEncoder_t7AB5C2F712CDB92EBFCDAF8E9743C5A39B7CFD6D* L_470 = V_0;
		NullCheck(L_470);
		SilkChannelEncoderU5BU5D_tBA29067A90CFA762728A1D297853F3661ADD6CA8* L_471 = L_470->___state_Fxx;
		NullCheck(L_471);
		int32_t L_472 = 0;
		SilkChannelEncoder_t9D54D1C6FC4B873E9CE81F196A0ACBA6C2A5C4E3* L_473 = (L_471)->GetAt(static_cast<il2cpp_array_size_t>(L_472));
		NullCheck(L_473);
		int32_t L_474 = L_473->___variable_HP_smth1_Q15;
		V_17 = L_474;
	}

IL_0e57:
	{
		int32_t L_475 = __this->___variable_HP_smth2_Q15;
		int32_t L_476 = V_17;
		int32_t L_477 = __this->___variable_HP_smth2_Q15;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_478;
		L_478 = Inlines_silk_SMLAWB_m8A023DCCC323ED0EB2CCF43D6ED6357B587EAAD2_inline(L_475, ((int32_t)il2cpp_codegen_subtract(L_476, L_477)), ((int32_t)983), NULL);
		__this->___variable_HP_smth2_Q15 = L_478;
		int32_t L_479 = __this->___variable_HP_smth2_Q15;
		int32_t L_480;
		L_480 = Inlines_silk_RSHIFT_m0ACD93ACB5B27378849FAD9F6440B867FA755103_inline(L_479, 8, NULL);
		int32_t L_481;
		L_481 = Inlines_silk_log2lin_mFB61AF160BBA8A179F17F7B375639DDCEDA19090_inline(L_480, NULL);
		V_16 = L_481;
		int32_t L_482 = __this->___application;
		if ((!(((uint32_t)L_482) == ((uint32_t)((int32_t)2048)))))
		{
			goto IL_0ec4;
		}
	}
	{
		ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 L_483 = ___0_pcm;
		int32_t L_484 = ___1_pcm_ptr;
		int32_t L_485 = V_16;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_486 = V_12;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_487;
		L_487 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_486, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_488 = V_26;
		int32_t L_489 = __this->___channels;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_490 = __this->___hp_mem;
		int32_t L_491 = ___2_frame_size;
		int32_t L_492 = __this->___channels;
		int32_t L_493 = __this->___Fs;
		CodecHelpers_hp_cutoff_mB1C77C6709A6092DB5B4E0270AE636F585114D48(L_483, L_484, L_485, L_487, ((int32_t)il2cpp_codegen_multiply(L_488, L_489)), L_490, L_491, L_492, L_493, NULL);
		goto IL_0eef;
	}

IL_0ec4:
	{
		ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 L_494 = ___0_pcm;
		int32_t L_495 = ___1_pcm_ptr;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_496 = V_12;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_497;
		L_497 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_496, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_498 = V_26;
		int32_t L_499 = __this->___channels;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_500 = __this->___hp_mem;
		int32_t L_501 = ___2_frame_size;
		int32_t L_502 = __this->___channels;
		int32_t L_503 = __this->___Fs;
		CodecHelpers_dc_reject_m66023F849A9C35E040B2DDA37ABF9A793F476ABE(L_494, L_495, 3, L_497, ((int32_t)il2cpp_codegen_multiply(L_498, L_499)), L_500, L_501, L_502, L_503, NULL);
	}

IL_0eef:
	{
		V_24 = ((int32_t)32767);
		int32_t L_504 = __this->___mode;
		if ((((int32_t)L_504) == ((int32_t)((int32_t)1002))))
		{
			goto IL_1582;
		}
	}
	{
		int32_t L_505 = __this->___channels;
		int32_t L_506 = ___2_frame_size;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_507 = (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)SZArrayNew(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(L_505, L_506)));
		V_63 = L_507;
		int32_t L_508 = V_6;
		int32_t L_509 = V_21;
		V_61 = ((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_multiply(8, L_508)), L_509));
		int32_t L_510 = __this->___mode;
		if ((!(((uint32_t)L_510) == ((uint32_t)((int32_t)1001)))))
		{
			goto IL_103a;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_511 = __this->___silk_mode;
		int32_t L_512 = __this->___stream_channels;
		int32_t L_513 = __this->___Fs;
		int32_t L_514 = ___2_frame_size;
		if ((((int32_t)L_513) == ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)100), L_514)))))
		{
			G_B252_0 = ((int32_t)5000);
			G_B252_1 = L_512;
			G_B252_2 = L_511;
			goto IL_0f4e;
		}
		G_B251_0 = ((int32_t)5000);
		G_B251_1 = L_512;
		G_B251_2 = L_511;
	}
	{
		G_B253_0 = 0;
		G_B253_1 = G_B251_0;
		G_B253_2 = G_B251_1;
		G_B253_3 = G_B251_2;
		goto IL_0f53;
	}

IL_0f4e:
	{
		G_B253_0 = ((int32_t)1000);
		G_B253_1 = G_B252_0;
		G_B253_2 = G_B252_1;
		G_B253_3 = G_B252_2;
	}

IL_0f53:
	{
		NullCheck(G_B253_3);
		G_B253_3->___bitRate = ((int32_t)il2cpp_codegen_multiply(G_B253_2, ((int32_t)il2cpp_codegen_add(G_B253_1, G_B253_0))));
		int32_t L_515 = V_23;
		if ((!(((uint32_t)L_515) == ((uint32_t)((int32_t)1104)))))
		{
			goto IL_0f89;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_516 = __this->___silk_mode;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_517 = L_516;
		NullCheck(L_517);
		int32_t L_518 = L_517->___bitRate;
		int32_t L_519 = V_61;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_520 = __this->___silk_mode;
		NullCheck(L_520);
		int32_t L_521 = L_520->___bitRate;
		NullCheck(L_517);
		L_517->___bitRate = ((int32_t)il2cpp_codegen_add(L_518, ((int32_t)(((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_subtract(L_519, L_521)), 2))/3))));
		goto IL_0fad;
	}

IL_0f89:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_522 = __this->___silk_mode;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_523 = L_522;
		NullCheck(L_523);
		int32_t L_524 = L_523->___bitRate;
		int32_t L_525 = V_61;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_526 = __this->___silk_mode;
		NullCheck(L_526);
		int32_t L_527 = L_526->___bitRate;
		NullCheck(L_523);
		L_523->___bitRate = ((int32_t)il2cpp_codegen_add(L_524, ((int32_t)(((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_subtract(L_525, L_527)), 3))/5))));
	}

IL_0fad:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_528 = __this->___silk_mode;
		NullCheck(L_528);
		int32_t L_529 = L_528->___bitRate;
		int32_t L_530 = V_61;
		if ((((int32_t)L_529) <= ((int32_t)((int32_t)(((int32_t)il2cpp_codegen_multiply(L_530, 4))/5)))))
		{
			goto IL_0fd1;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_531 = __this->___silk_mode;
		int32_t L_532 = V_61;
		NullCheck(L_531);
		L_531->___bitRate = ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_532, 4))/5));
	}

IL_0fd1:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_533 = __this->___energy_masking;
		if (L_533)
		{
			goto IL_1047;
		}
	}
	{
		int32_t L_534 = V_61;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_535 = __this->___silk_mode;
		NullCheck(L_535);
		int32_t L_536 = L_535->___bitRate;
		V_62 = ((int32_t)il2cpp_codegen_subtract(L_534, L_536));
		int32_t L_537 = V_23;
		if ((((int32_t)L_537) == ((int32_t)((int32_t)1104))))
		{
			goto IL_0ff9;
		}
	}
	{
		G_B262_0 = ((int32_t)3600);
		goto IL_0ffe;
	}

IL_0ff9:
	{
		G_B262_0 = ((int32_t)3000);
	}

IL_0ffe:
	{
		V_65 = G_B262_0;
		int32_t L_538 = V_62;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_539;
		L_539 = Inlines_SHL32_m759CE9A6D5B83434728CB2C33BA4320DFACBD900_inline(L_538, ((int32_t)9), NULL);
		int32_t L_540 = V_62;
		int32_t L_541 = __this->___stream_channels;
		int32_t L_542 = V_65;
		int32_t L_543;
		L_543 = Inlines_SHR32_mE532A866351E7866B6A1BAD8A8E9306DE22AE05F_inline(((int32_t)il2cpp_codegen_add(L_540, ((int32_t)il2cpp_codegen_multiply(L_541, L_542)))), 6, NULL);
		V_24 = ((int32_t)(L_539/L_543));
		int32_t L_544 = V_24;
		if ((((int32_t)L_544) < ((int32_t)((int32_t)28086))))
		{
			goto IL_102e;
		}
	}
	{
		G_B265_0 = ((int32_t)32767);
		goto IL_1036;
	}

IL_102e:
	{
		int32_t L_545 = V_24;
		G_B265_0 = ((int32_t)il2cpp_codegen_add(L_545, ((int32_t)4681)));
	}

IL_1036:
	{
		V_24 = G_B265_0;
		goto IL_1047;
	}

IL_103a:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_546 = __this->___silk_mode;
		int32_t L_547 = V_61;
		NullCheck(L_546);
		L_546->___bitRate = L_547;
	}

IL_1047:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_548 = __this->___energy_masking;
		if (!L_548)
		{
			goto IL_11a0;
		}
	}
	{
		int32_t L_549 = __this->___use_vbr;
		if (!L_549)
		{
			goto IL_11a0;
		}
	}
	{
		int32_t L_550 = __this->___lfe;
		if (L_550)
		{
			goto IL_11a0;
		}
	}
	{
		V_66 = 0;
		V_70 = ((int32_t)17);
		V_71 = (int16_t)((int32_t)16000);
		int32_t L_551 = __this->___bandwidth;
		if ((!(((uint32_t)L_551) == ((uint32_t)((int32_t)1101)))))
		{
			goto IL_1090;
		}
	}
	{
		V_70 = ((int32_t)13);
		V_71 = (int16_t)((int32_t)8000);
		goto IL_10a8;
	}

IL_1090:
	{
		int32_t L_552 = __this->___bandwidth;
		if ((!(((uint32_t)L_552) == ((uint32_t)((int32_t)1102)))))
		{
			goto IL_10a8;
		}
	}
	{
		V_70 = ((int32_t)15);
		V_71 = (int16_t)((int32_t)12000);
	}

IL_10a8:
	{
		V_69 = 0;
		goto IL_10f9;
	}

IL_10ad:
	{
		V_2 = 0;
		goto IL_10ee;
	}

IL_10b1:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_553 = __this->___energy_masking;
		int32_t L_554 = V_69;
		int32_t L_555 = V_2;
		NullCheck(L_553);
		int32_t L_556 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_554)), L_555));
		int32_t L_557 = (L_553)->GetAt(static_cast<il2cpp_array_size_t>(L_556));
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_558;
		L_558 = Inlines_MIN16_mD65F33577C97F96B9FE9B2540589BA7FADF52F5E_inline(L_557, ((int32_t)512), NULL);
		int32_t L_559;
		L_559 = Inlines_MAX16_m4D603BAD0F242EB66ED76BE982BC3907D9DF44A5_inline(L_558, ((int32_t)-2048), NULL);
		V_72 = L_559;
		int32_t L_560 = V_72;
		if ((((int32_t)L_560) <= ((int32_t)0)))
		{
			goto IL_10e3;
		}
	}
	{
		int32_t L_561 = V_72;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_562;
		L_562 = Inlines_HALF16_mCC975475CB9BE63D15752AA7AA0F3E44598ADB4D_inline(L_561, NULL);
		V_72 = L_562;
	}

IL_10e3:
	{
		int32_t L_563 = V_66;
		int32_t L_564 = V_72;
		V_66 = ((int32_t)il2cpp_codegen_add(L_563, L_564));
		int32_t L_565 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_565, 1));
	}

IL_10ee:
	{
		int32_t L_566 = V_2;
		int32_t L_567 = V_70;
		if ((((int32_t)L_566) < ((int32_t)L_567)))
		{
			goto IL_10b1;
		}
	}
	{
		int32_t L_568 = V_69;
		V_69 = ((int32_t)il2cpp_codegen_add(L_568, 1));
	}

IL_10f9:
	{
		int32_t L_569 = V_69;
		int32_t L_570 = __this->___channels;
		if ((((int32_t)L_569) < ((int32_t)L_570)))
		{
			goto IL_10ad;
		}
	}
	{
		int32_t L_571 = V_66;
		int32_t L_572 = V_70;
		int32_t L_573 = __this->___channels;
		V_67 = ((int32_t)il2cpp_codegen_multiply(((int32_t)(L_571/L_572)), L_573));
		int32_t L_574 = V_67;
		V_67 = ((int32_t)il2cpp_codegen_add(L_574, ((int32_t)205)));
		int16_t L_575 = V_71;
		int32_t L_576 = V_67;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_577;
		L_577 = Inlines_MULT16_16_m86CC5979188CE7184708F6DC86E20F35D4501777_inline((int32_t)L_575, L_576, NULL);
		int32_t L_578;
		L_578 = Inlines_PSHR32_m795531FF9BB2EDD62D70EC3925DC6CA0F8B50983_inline(L_577, ((int32_t)10), NULL);
		V_68 = L_578;
		int32_t L_579 = V_68;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_580 = __this->___silk_mode;
		NullCheck(L_580);
		int32_t L_581 = L_580->___bitRate;
		int32_t L_582;
		L_582 = Inlines_MAX32_m603F38A48C71C4DF8E2938A811D591A5B3485B65_inline(L_579, ((int32_t)(((int32_t)il2cpp_codegen_multiply(((int32_t)-2), L_581))/3)), NULL);
		V_68 = L_582;
		int32_t L_583 = __this->___bandwidth;
		if ((((int32_t)L_583) == ((int32_t)((int32_t)1104))))
		{
			goto IL_1160;
		}
	}
	{
		int32_t L_584 = __this->___bandwidth;
		if ((!(((uint32_t)L_584) == ((uint32_t)((int32_t)1105)))))
		{
			goto IL_117a;
		}
	}

IL_1160:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_585 = __this->___silk_mode;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_586 = L_585;
		NullCheck(L_586);
		int32_t L_587 = L_586->___bitRate;
		int32_t L_588 = V_68;
		NullCheck(L_586);
		L_586->___bitRate = ((int32_t)il2cpp_codegen_add(L_587, ((int32_t)(((int32_t)il2cpp_codegen_multiply(3, L_588))/5))));
		goto IL_118e;
	}

IL_117a:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_589 = __this->___silk_mode;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_590 = L_589;
		NullCheck(L_590);
		int32_t L_591 = L_590->___bitRate;
		int32_t L_592 = V_68;
		NullCheck(L_590);
		L_590->___bitRate = ((int32_t)il2cpp_codegen_add(L_591, L_592));
	}

IL_118e:
	{
		int32_t L_593 = V_6;
		int32_t L_594 = V_68;
		int32_t L_595 = ___2_frame_size;
		int32_t L_596 = __this->___Fs;
		V_6 = ((int32_t)il2cpp_codegen_add(L_593, ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_594, L_595))/((int32_t)il2cpp_codegen_multiply(8, L_596))))));
	}

IL_11a0:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_597 = __this->___silk_mode;
		int32_t L_598 = ___2_frame_size;
		int32_t L_599 = __this->___Fs;
		NullCheck(L_597);
		L_597->___payloadSize_ms = ((int32_t)(((int32_t)il2cpp_codegen_multiply(((int32_t)1000), L_598))/L_599));
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_600 = __this->___silk_mode;
		int32_t L_601 = __this->___channels;
		NullCheck(L_600);
		L_600->___nChannelsAPI = L_601;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_602 = __this->___silk_mode;
		int32_t L_603 = __this->___stream_channels;
		NullCheck(L_602);
		L_602->___nChannelsInternal = L_603;
		int32_t L_604 = V_23;
		if ((!(((uint32_t)L_604) == ((uint32_t)((int32_t)1101)))))
		{
			goto IL_11f6;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_605 = __this->___silk_mode;
		NullCheck(L_605);
		L_605->___desiredInternalSampleRate = ((int32_t)8000);
		goto IL_1221;
	}

IL_11f6:
	{
		int32_t L_606 = V_23;
		if ((!(((uint32_t)L_606) == ((uint32_t)((int32_t)1102)))))
		{
			goto IL_1211;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_607 = __this->___silk_mode;
		NullCheck(L_607);
		L_607->___desiredInternalSampleRate = ((int32_t)12000);
		goto IL_1221;
	}

IL_1211:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_608 = __this->___silk_mode;
		NullCheck(L_608);
		L_608->___desiredInternalSampleRate = ((int32_t)16000);
	}

IL_1221:
	{
		int32_t L_609 = __this->___mode;
		if ((!(((uint32_t)L_609) == ((uint32_t)((int32_t)1001)))))
		{
			goto IL_1240;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_610 = __this->___silk_mode;
		NullCheck(L_610);
		L_610->___minInternalSampleRate = ((int32_t)16000);
		goto IL_1250;
	}

IL_1240:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_611 = __this->___silk_mode;
		NullCheck(L_611);
		L_611->___minInternalSampleRate = ((int32_t)8000);
	}

IL_1250:
	{
		int32_t L_612 = __this->___mode;
		if ((!(((uint32_t)L_612) == ((uint32_t)((int32_t)1000)))))
		{
			goto IL_12f6;
		}
	}
	{
		int32_t L_613 = V_22;
		V_73 = L_613;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_614 = __this->___silk_mode;
		NullCheck(L_614);
		L_614->___maxInternalSampleRate = ((int32_t)16000);
		int32_t L_615 = V_21;
		if ((((int32_t)L_615) <= ((int32_t)((int32_t)50))))
		{
			goto IL_1282;
		}
	}
	{
		int32_t L_616 = V_73;
		V_73 = ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_616, 2))/3));
	}

IL_1282:
	{
		int32_t L_617 = V_73;
		if ((((int32_t)L_617) >= ((int32_t)((int32_t)13000))))
		{
			goto IL_12bb;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_618 = __this->___silk_mode;
		NullCheck(L_618);
		L_618->___maxInternalSampleRate = ((int32_t)12000);
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_619 = __this->___silk_mode;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_620 = __this->___silk_mode;
		NullCheck(L_620);
		int32_t L_621 = L_620->___desiredInternalSampleRate;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_622;
		L_622 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)12000), L_621, NULL);
		NullCheck(L_619);
		L_619->___desiredInternalSampleRate = L_622;
	}

IL_12bb:
	{
		int32_t L_623 = V_73;
		if ((((int32_t)L_623) >= ((int32_t)((int32_t)9600))))
		{
			goto IL_1306;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_624 = __this->___silk_mode;
		NullCheck(L_624);
		L_624->___maxInternalSampleRate = ((int32_t)8000);
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_625 = __this->___silk_mode;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_626 = __this->___silk_mode;
		NullCheck(L_626);
		int32_t L_627 = L_626->___desiredInternalSampleRate;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_628;
		L_628 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)8000), L_627, NULL);
		NullCheck(L_625);
		L_625->___desiredInternalSampleRate = L_628;
		goto IL_1306;
	}

IL_12f6:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_629 = __this->___silk_mode;
		NullCheck(L_629);
		L_629->___maxInternalSampleRate = ((int32_t)16000);
	}

IL_1306:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_630 = __this->___silk_mode;
		int32_t L_631 = __this->___use_vbr;
		if (!L_631)
		{
			G_B305_0 = L_630;
			goto IL_1317;
		}
		G_B304_0 = L_630;
	}
	{
		G_B306_0 = 0;
		G_B306_1 = G_B304_0;
		goto IL_1318;
	}

IL_1317:
	{
		G_B306_0 = 1;
		G_B306_1 = G_B305_0;
	}

IL_1318:
	{
		NullCheck(G_B306_1);
		G_B306_1->___useCBR = G_B306_0;
		int32_t L_632 = V_25;
		int32_t L_633 = V_10;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_634;
		L_634 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)1275), ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_632, 1)), L_633)), NULL);
		V_4 = L_634;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_635 = __this->___silk_mode;
		int32_t L_636 = V_4;
		NullCheck(L_635);
		L_635->___maxBits = ((int32_t)il2cpp_codegen_multiply(L_636, 8));
		int32_t L_637 = __this->___mode;
		if ((!(((uint32_t)L_637) == ((uint32_t)((int32_t)1001)))))
		{
			goto IL_1368;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_638 = __this->___silk_mode;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_639 = __this->___silk_mode;
		NullCheck(L_639);
		int32_t L_640 = L_639->___maxBits;
		NullCheck(L_638);
		L_638->___maxBits = ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_640, ((int32_t)9)))/((int32_t)10)));
	}

IL_1368:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_641 = __this->___silk_mode;
		NullCheck(L_641);
		int32_t L_642 = L_641->___useCBR;
		if (!L_642)
		{
			goto IL_13ba;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_643 = __this->___silk_mode;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_644 = __this->___silk_mode;
		NullCheck(L_644);
		int32_t L_645 = L_644->___bitRate;
		int32_t L_646 = ___2_frame_size;
		int32_t L_647 = __this->___Fs;
		NullCheck(L_643);
		L_643->___maxBits = ((int32_t)il2cpp_codegen_multiply(((int32_t)(((int32_t)il2cpp_codegen_multiply(L_645, L_646))/((int32_t)il2cpp_codegen_multiply(L_647, 8)))), 8));
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_648 = __this->___silk_mode;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_649 = __this->___silk_mode;
		NullCheck(L_649);
		int32_t L_650 = L_649->___bitRate;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_651;
		L_651 = Inlines_IMAX_mFECDD1F5C3C0962AF8B0140E78A6C3A25BCF9C23_inline(1, ((int32_t)il2cpp_codegen_subtract(L_650, ((int32_t)2000))), NULL);
		NullCheck(L_648);
		L_648->___bitRate = L_651;
	}

IL_13ba:
	{
		int32_t L_652 = V_7;
		if (!L_652)
		{
			goto IL_1471;
		}
	}
	{
		BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* L_653 = (BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026*)il2cpp_codegen_object_new(BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026_il2cpp_TypeInfo_var);
		BoxedValueInt__ctor_m6EC58F06F4673535F2682F1731C6F36FC073A36A(L_653, 0, NULL);
		V_74 = L_653;
		int32_t L_654 = __this->___channels;
		int32_t L_655 = __this->___encoder_buffer;
		int32_t L_656 = __this->___delay_compensation;
		int32_t L_657 = __this->___Fs;
		V_75 = ((int32_t)il2cpp_codegen_multiply(L_654, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_655, L_656)), ((int32_t)(L_657/((int32_t)400)))))));
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_658 = __this->___delay_buffer;
		int32_t L_659 = V_75;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_660 = V_28;
		NullCheck(L_660);
		int32_t L_661 = L_660->___overlap;
		int32_t L_662 = __this->___Fs;
		int32_t L_663 = __this->___channels;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_664 = V_28;
		NullCheck(L_664);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_665 = L_664->___window;
		int32_t L_666 = __this->___Fs;
		CodecHelpers_gain_fade_mB38DEC7BAD27021D38F3577722DFB025B8657774(L_658, L_659, 0, ((int32_t)32767), L_661, ((int32_t)(L_662/((int32_t)400))), L_663, L_665, L_666, NULL);
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_667 = __this->___delay_buffer;
		int32_t L_668 = V_75;
		Arrays_MemSetShort_m8C49EA240FDBFE594D42AEB7C682C4B48683D01E(L_667, (int16_t)0, L_668, NULL);
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_669 = __this->___delay_buffer;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_670 = V_63;
		int32_t L_671 = __this->___encoder_buffer;
		int32_t L_672 = __this->___channels;
		Arrays_MemCopy_m6694E7C365EE590A29753D43699215FBC8162E89(L_669, 0, L_670, 0, ((int32_t)il2cpp_codegen_multiply(L_671, L_672)), NULL);
		SilkEncoder_t7AB5C2F712CDB92EBFCDAF8E9743C5A39B7CFD6D* L_673 = V_0;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_674 = __this->___silk_mode;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_675 = V_63;
		int32_t L_676 = __this->___encoder_buffer;
		int32_t L_677 = ___4_data_ptr;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_678;
		L_678 = Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_inline((&___3_data), L_677, Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_RuntimeMethod_var);
		BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* L_679 = V_74;
		int32_t L_680;
		L_680 = EncodeAPI_silk_Encode_m03CA6F3640C38ACB077A8718E63B9AF31C2F73DC(L_673, L_674, L_675, L_676, (EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679*)NULL, L_678, L_679, 1, NULL);
	}

IL_1471:
	{
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_681 = V_12;
		int32_t L_682 = V_26;
		int32_t L_683 = __this->___channels;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_684 = V_63;
		int32_t L_685 = ___2_frame_size;
		int32_t L_686 = __this->___channels;
		Arrays_MemCopy_m6694E7C365EE590A29753D43699215FBC8162E89(L_681, ((int32_t)il2cpp_codegen_multiply(L_682, L_683)), L_684, 0, ((int32_t)il2cpp_codegen_multiply(L_685, L_686)), NULL);
		int32_t L_687 = V_4;
		BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* L_688 = (BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026*)il2cpp_codegen_object_new(BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026_il2cpp_TypeInfo_var);
		BoxedValueInt__ctor_m6EC58F06F4673535F2682F1731C6F36FC073A36A(L_688, L_687, NULL);
		V_64 = L_688;
		SilkEncoder_t7AB5C2F712CDB92EBFCDAF8E9743C5A39B7CFD6D* L_689 = V_0;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_690 = __this->___silk_mode;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_691 = V_63;
		int32_t L_692 = ___2_frame_size;
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_693 = V_5;
		int32_t L_694 = ___4_data_ptr;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_695;
		L_695 = Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_inline((&___3_data), L_694, Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_RuntimeMethod_var);
		BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* L_696 = V_64;
		int32_t L_697;
		L_697 = EncodeAPI_silk_Encode_m03CA6F3640C38ACB077A8718E63B9AF31C2F73DC(L_689, L_690, L_691, L_692, L_693, L_695, L_696, 0, NULL);
		V_3 = L_697;
		BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* L_698 = V_64;
		NullCheck(L_698);
		int32_t L_699 = L_698->___Val;
		V_4 = L_699;
		int32_t L_700 = V_3;
		if (!L_700)
		{
			goto IL_14c2;
		}
	}
	{
		return ((int32_t)-3);
	}

IL_14c2:
	{
		int32_t L_701 = V_4;
		if (L_701)
		{
			goto IL_14f6;
		}
	}
	{
		__this->___rangeFinal = (uint32_t)0;
		int32_t L_702 = ___4_data_ptr;
		uint8_t* L_703;
		L_703 = il2cpp_span_get_item((uint8_t*)((Il2CppByReference*)&(((&___3_data))->____pointer))->value, (((int32_t)il2cpp_codegen_subtract(L_702, 1))), ((&___3_data))->____length);
		int32_t L_704 = __this->___mode;
		int32_t L_705 = __this->___Fs;
		int32_t L_706 = ___2_frame_size;
		int32_t L_707 = V_23;
		int32_t L_708 = __this->___stream_channels;
		uint8_t L_709;
		L_709 = CodecHelpers_gen_toc_m55919D0EC27589F5328AD925AA91F8B0D4A9EBA2(L_704, ((int32_t)(L_705/L_706)), L_707, L_708, NULL);
		*((int8_t*)L_703) = (int8_t)L_709;
		return 1;
	}

IL_14f6:
	{
		int32_t L_710 = __this->___mode;
		if ((!(((uint32_t)L_710) == ((uint32_t)((int32_t)1000)))))
		{
			goto IL_1552;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_711 = __this->___silk_mode;
		NullCheck(L_711);
		int32_t L_712 = L_711->___internalSampleRate;
		if ((!(((uint32_t)L_712) == ((uint32_t)((int32_t)8000)))))
		{
			goto IL_151e;
		}
	}
	{
		V_23 = (int32_t)((int32_t)1101);
		goto IL_1552;
	}

IL_151e:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_713 = __this->___silk_mode;
		NullCheck(L_713);
		int32_t L_714 = L_713->___internalSampleRate;
		if ((!(((uint32_t)L_714) == ((uint32_t)((int32_t)12000)))))
		{
			goto IL_1539;
		}
	}
	{
		V_23 = (int32_t)((int32_t)1102);
		goto IL_1552;
	}

IL_1539:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_715 = __this->___silk_mode;
		NullCheck(L_715);
		int32_t L_716 = L_715->___internalSampleRate;
		if ((!(((uint32_t)L_716) == ((uint32_t)((int32_t)16000)))))
		{
			goto IL_1552;
		}
	}
	{
		V_23 = (int32_t)((int32_t)1103);
	}

IL_1552:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_717 = __this->___silk_mode;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_718 = __this->___silk_mode;
		NullCheck(L_718);
		int32_t L_719 = L_718->___switchReady;
		NullCheck(L_717);
		L_717->___opusCanSwitch = L_719;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_720 = __this->___silk_mode;
		NullCheck(L_720);
		int32_t L_721 = L_720->___opusCanSwitch;
		if (!L_721)
		{
			goto IL_1582;
		}
	}
	{
		V_9 = 1;
		V_11 = 0;
		__this->___silk_bw_switch = 1;
	}

IL_1582:
	{
		V_76 = ((int32_t)21);
		int32_t L_722 = V_23;
		switch (((int32_t)il2cpp_codegen_subtract((int32_t)L_722, ((int32_t)1101))))
		{
			case 0:
			{
				goto IL_15a9;
			}
			case 1:
			{
				goto IL_15af;
			}
			case 2:
			{
				goto IL_15af;
			}
			case 3:
			{
				goto IL_15b5;
			}
			case 4:
			{
				goto IL_15bb;
			}
		}
	}
	{
		goto IL_15bf;
	}

IL_15a9:
	{
		V_76 = ((int32_t)13);
		goto IL_15bf;
	}

IL_15af:
	{
		V_76 = ((int32_t)17);
		goto IL_15bf;
	}

IL_15b5:
	{
		V_76 = ((int32_t)19);
		goto IL_15bf;
	}

IL_15bb:
	{
		V_76 = ((int32_t)21);
	}

IL_15bf:
	{
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_723 = V_1;
		int32_t L_724 = V_76;
		NullCheck(L_723);
		CeltEncoder_SetEndBand_m767B785A3E059611D2E876D483F43673419EBA0D(L_723, L_724, NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_725 = V_1;
		int32_t L_726 = __this->___stream_channels;
		NullCheck(L_725);
		CeltEncoder_SetChannels_m044A630FD1013D07F49245B2C009452B31BB1CC5(L_725, L_726, NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_727 = V_1;
		NullCheck(L_727);
		CeltEncoder_SetBitrate_mCF59724BF7FF4D5F66B571C27B99B4C5F424AAB0(L_727, (-1), NULL);
		int32_t L_728 = __this->___mode;
		if ((((int32_t)L_728) == ((int32_t)((int32_t)1000))))
		{
			goto IL_1725;
		}
	}
	{
		V_77 = 2;
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_729 = V_1;
		NullCheck(L_729);
		CeltEncoder_SetVBR_mB2A8CFC94909FB78E5D6B5CCEC287AE5C26748BB(L_729, (bool)0, NULL);
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_730 = __this->___silk_mode;
		NullCheck(L_730);
		int32_t L_731 = L_730->___reducedDependency;
		if (!L_731)
		{
			goto IL_1604;
		}
	}
	{
		V_77 = 0;
	}

IL_1604:
	{
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_732 = V_1;
		int32_t L_733 = V_77;
		NullCheck(L_732);
		CeltEncoder_SetPrediction_m880E0433982007C125828ED68A45A4A134798EB4(L_732, L_733, NULL);
		int32_t L_734 = __this->___mode;
		if ((!(((uint32_t)L_734) == ((uint32_t)((int32_t)1001)))))
		{
			goto IL_167e;
		}
	}
	{
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_735 = V_5;
		NullCheck(L_735);
		int32_t L_736;
		L_736 = EntropyCoder_tell_m29422D894C6D91518823D9C94D3CC93ACEA2350A(L_735, NULL);
		V_78 = ((int32_t)(((int32_t)il2cpp_codegen_add(L_736, 7))>>3));
		int32_t L_737 = V_9;
		if (!L_737)
		{
			goto IL_1640;
		}
	}
	{
		int32_t L_738 = V_78;
		int32_t L_739 = __this->___mode;
		if ((((int32_t)L_739) == ((int32_t)((int32_t)1001))))
		{
			G_B338_0 = L_738;
			goto IL_163c;
		}
		G_B337_0 = L_738;
	}
	{
		G_B339_0 = 1;
		G_B339_1 = G_B337_0;
		goto IL_163d;
	}

IL_163c:
	{
		G_B339_0 = 3;
		G_B339_1 = G_B338_0;
	}

IL_163d:
	{
		V_78 = ((int32_t)il2cpp_codegen_add(G_B339_1, G_B339_0));
	}

IL_1640:
	{
		int32_t L_740 = __this->___use_vbr;
		if (!L_740)
		{
			goto IL_166b;
		}
	}
	{
		int32_t L_741 = V_78;
		int32_t L_742 = V_6;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_743 = __this->___silk_mode;
		NullCheck(L_743);
		int32_t L_744 = L_743->___bitRate;
		int32_t L_745 = ___2_frame_size;
		int32_t L_746 = __this->___Fs;
		V_13 = ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_741, L_742)), ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_744, L_745))/((int32_t)il2cpp_codegen_multiply(8, L_746))))));
		goto IL_1728;
	}

IL_166b:
	{
		int32_t L_747 = V_78;
		int32_t L_748 = V_6;
		if ((((int32_t)L_747) > ((int32_t)L_748)))
		{
			goto IL_1675;
		}
	}
	{
		int32_t L_749 = V_6;
		G_B345_0 = L_749;
		goto IL_1677;
	}

IL_1675:
	{
		int32_t L_750 = V_78;
		G_B345_0 = L_750;
	}

IL_1677:
	{
		V_13 = G_B345_0;
		goto IL_1728;
	}

IL_167e:
	{
		int32_t L_751 = __this->___use_vbr;
		if (!L_751)
		{
			goto IL_171f;
		}
	}
	{
		V_79 = 0;
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_752 = __this->___analysis;
		NullCheck(L_752);
		bool L_753 = L_752->___enabled;
		if (!L_753)
		{
			goto IL_16ef;
		}
	}
	{
		int32_t L_754 = __this->___variable_duration;
		if ((!(((uint32_t)L_754) == ((uint32_t)((int32_t)5010)))))
		{
			goto IL_16ef;
		}
	}
	{
		int32_t L_755 = ___2_frame_size;
		int32_t L_756 = __this->___Fs;
		if ((((int32_t)L_755) == ((int32_t)((int32_t)(L_756/((int32_t)50))))))
		{
			goto IL_16ef;
		}
	}
	{
		int32_t L_757 = __this->___stream_channels;
		int32_t L_758 = __this->___Fs;
		int32_t L_759 = ___2_frame_size;
		V_79 = ((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)60), L_757)), ((int32_t)40))), ((int32_t)il2cpp_codegen_subtract(((int32_t)(L_758/L_759)), ((int32_t)50)))));
		AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* L_760 = V_29;
		NullCheck(L_760);
		int32_t L_761 = L_760->___valid;
		if (!L_761)
		{
			goto IL_16ef;
		}
	}
	{
		int32_t L_762 = V_79;
		AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* L_763 = V_29;
		NullCheck(L_763);
		float L_764 = L_763->___tonality;
		V_79 = il2cpp_codegen_cast_double_to_int<int32_t>(((float)il2cpp_codegen_multiply(((float)L_762), ((float)il2cpp_codegen_add((1.0f), ((float)il2cpp_codegen_multiply((0.5f), L_764)))))));
	}

IL_16ef:
	{
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_765 = V_1;
		NullCheck(L_765);
		CeltEncoder_SetVBR_mB2A8CFC94909FB78E5D6B5CCEC287AE5C26748BB(L_765, (bool)1, NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_766 = V_1;
		int32_t L_767 = __this->___vbr_constraint;
		NullCheck(L_766);
		CeltEncoder_SetVBRConstraint_mCA7F81F0B4A945B523C40A8C49AC3EB27B8DE057(L_766, (bool)((!(((uint32_t)L_767) <= ((uint32_t)0)))? 1 : 0), NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_768 = V_1;
		int32_t L_769 = __this->___bitrate_bps;
		int32_t L_770 = V_79;
		NullCheck(L_768);
		CeltEncoder_SetBitrate_mCF59724BF7FF4D5F66B571C27B99B4C5F424AAB0(L_768, ((int32_t)il2cpp_codegen_add(L_769, L_770)), NULL);
		int32_t L_771 = V_25;
		int32_t L_772 = V_10;
		V_13 = ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_771, 1)), L_772));
		goto IL_1728;
	}

IL_171f:
	{
		int32_t L_773 = V_6;
		V_13 = L_773;
		goto IL_1728;
	}

IL_1725:
	{
		V_13 = 0;
	}

IL_1728:
	{
		int32_t L_774 = __this->___channels;
		int32_t L_775 = __this->___Fs;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_776 = (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)SZArrayNew(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var, (uint32_t)((int32_t)(((int32_t)il2cpp_codegen_multiply(L_774, L_775))/((int32_t)400))));
		V_32 = L_776;
		int32_t L_777 = __this->___mode;
		if ((((int32_t)L_777) == ((int32_t)((int32_t)1000))))
		{
			goto IL_17a4;
		}
	}
	{
		int32_t L_778 = __this->___mode;
		int32_t L_779 = __this->___prev_mode;
		if ((((int32_t)L_778) == ((int32_t)L_779)))
		{
			goto IL_17a4;
		}
	}
	{
		int32_t L_780 = __this->___prev_mode;
		if ((((int32_t)L_780) <= ((int32_t)0)))
		{
			goto IL_17a4;
		}
	}
	{
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_781 = __this->___delay_buffer;
		int32_t L_782 = __this->___encoder_buffer;
		int32_t L_783 = V_26;
		int32_t L_784 = __this->___Fs;
		int32_t L_785 = __this->___channels;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_786 = V_32;
		int32_t L_787 = __this->___channels;
		int32_t L_788 = __this->___Fs;
		Arrays_MemCopy_m6694E7C365EE590A29753D43699215FBC8162E89(L_781, ((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_782, L_783)), ((int32_t)(L_784/((int32_t)400))))), L_785)), L_786, 0, ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_787, L_788))/((int32_t)400))), NULL);
	}

IL_17a4:
	{
		int32_t L_789 = __this->___channels;
		int32_t L_790 = __this->___encoder_buffer;
		int32_t L_791 = ___2_frame_size;
		int32_t L_792 = V_26;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(L_789, ((int32_t)il2cpp_codegen_subtract(L_790, ((int32_t)il2cpp_codegen_add(L_791, L_792))))))) <= ((int32_t)0)))
		{
			goto IL_180c;
		}
	}
	{
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_793 = __this->___delay_buffer;
		int32_t L_794 = __this->___channels;
		int32_t L_795 = ___2_frame_size;
		int32_t L_796 = __this->___channels;
		int32_t L_797 = __this->___encoder_buffer;
		int32_t L_798 = ___2_frame_size;
		int32_t L_799 = V_26;
		Arrays_MemMoveShort_m07C394C79F74EE49ACB696FB6B519B9C6ACD7CB0(L_793, ((int32_t)il2cpp_codegen_multiply(L_794, L_795)), 0, ((int32_t)il2cpp_codegen_multiply(L_796, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_797, L_798)), L_799)))), NULL);
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_800 = V_12;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_801 = __this->___delay_buffer;
		int32_t L_802 = __this->___channels;
		int32_t L_803 = __this->___encoder_buffer;
		int32_t L_804 = ___2_frame_size;
		int32_t L_805 = V_26;
		int32_t L_806 = ___2_frame_size;
		int32_t L_807 = V_26;
		int32_t L_808 = __this->___channels;
		Arrays_MemCopy_m6694E7C365EE590A29753D43699215FBC8162E89(L_800, 0, L_801, ((int32_t)il2cpp_codegen_multiply(L_802, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_803, L_804)), L_805)))), ((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_add(L_806, L_807)), L_808)), NULL);
		goto IL_1839;
	}

IL_180c:
	{
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_809 = V_12;
		int32_t L_810 = ___2_frame_size;
		int32_t L_811 = V_26;
		int32_t L_812 = __this->___encoder_buffer;
		int32_t L_813 = __this->___channels;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_814 = __this->___delay_buffer;
		int32_t L_815 = __this->___encoder_buffer;
		int32_t L_816 = __this->___channels;
		Arrays_MemCopy_m6694E7C365EE590A29753D43699215FBC8162E89(L_809, ((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_810, L_811)), L_812)), L_813)), L_814, 0, ((int32_t)il2cpp_codegen_multiply(L_815, L_816)), NULL);
	}

IL_1839:
	{
		int32_t L_817 = __this->___prev_HB_gain;
		if ((((int32_t)L_817) < ((int32_t)((int32_t)32767))))
		{
			goto IL_184f;
		}
	}
	{
		int32_t L_818 = V_24;
		if ((((int32_t)L_818) >= ((int32_t)((int32_t)32767))))
		{
			goto IL_187a;
		}
	}

IL_184f:
	{
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_819 = V_12;
		int32_t L_820 = __this->___prev_HB_gain;
		int32_t L_821 = V_24;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_822 = V_28;
		NullCheck(L_822);
		int32_t L_823 = L_822->___overlap;
		int32_t L_824 = ___2_frame_size;
		int32_t L_825 = __this->___channels;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_826 = V_28;
		NullCheck(L_826);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_827 = L_826->___window;
		int32_t L_828 = __this->___Fs;
		CodecHelpers_gain_fade_mB38DEC7BAD27021D38F3577722DFB025B8657774(L_819, 0, L_820, L_821, L_823, L_824, L_825, L_827, L_828, NULL);
	}

IL_187a:
	{
		int32_t L_829 = V_24;
		__this->___prev_HB_gain = L_829;
		int32_t L_830 = __this->___mode;
		if ((!(((uint32_t)L_830) == ((uint32_t)((int32_t)1001)))))
		{
			goto IL_1898;
		}
	}
	{
		int32_t L_831 = __this->___stream_channels;
		if ((!(((uint32_t)L_831) == ((uint32_t)1))))
		{
			goto IL_18bd;
		}
	}

IL_1898:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_832 = __this->___silk_mode;
		int32_t L_833 = V_19;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_834;
		L_834 = Inlines_IMAX_mFECDD1F5C3C0962AF8B0140E78A6C3A25BCF9C23_inline(0, ((int32_t)il2cpp_codegen_subtract(L_833, ((int32_t)30000))), NULL);
		int32_t L_835;
		L_835 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)16384), ((int32_t)il2cpp_codegen_multiply(2, L_834)), NULL);
		NullCheck(L_832);
		L_832->___stereoWidth_Q14 = L_835;
	}

IL_18bd:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_836 = __this->___energy_masking;
		if (L_836)
		{
			goto IL_1977;
		}
	}
	{
		int32_t L_837 = __this->___channels;
		if ((!(((uint32_t)L_837) == ((uint32_t)2))))
		{
			goto IL_1977;
		}
	}
	{
		int16_t L_838 = __this->___hybrid_stereo_width_Q14;
		if ((((int32_t)L_838) < ((int32_t)((int32_t)16384))))
		{
			goto IL_18f6;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_839 = __this->___silk_mode;
		NullCheck(L_839);
		int32_t L_840 = L_839->___stereoWidth_Q14;
		if ((((int32_t)L_840) >= ((int32_t)((int32_t)16384))))
		{
			goto IL_1977;
		}
	}

IL_18f6:
	{
		int16_t L_841 = __this->___hybrid_stereo_width_Q14;
		V_80 = (int32_t)L_841;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_842 = __this->___silk_mode;
		NullCheck(L_842);
		int32_t L_843 = L_842->___stereoWidth_Q14;
		V_81 = L_843;
		int32_t L_844 = V_80;
		if ((((int32_t)L_844) == ((int32_t)((int32_t)16384))))
		{
			goto IL_191e;
		}
	}
	{
		int32_t L_845 = V_80;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_846;
		L_846 = Inlines_SHL16_mDE053DF36529BA35606160EBC860F23260B23A87_inline(L_845, 1, NULL);
		G_B375_0 = L_846;
		goto IL_1923;
	}

IL_191e:
	{
		G_B375_0 = ((int32_t)32767);
	}

IL_1923:
	{
		V_80 = G_B375_0;
		int32_t L_847 = V_81;
		if ((((int32_t)L_847) == ((int32_t)((int32_t)16384))))
		{
			goto IL_1938;
		}
	}
	{
		int32_t L_848 = V_81;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_849;
		L_849 = Inlines_SHL16_mDE053DF36529BA35606160EBC860F23260B23A87_inline(L_848, 1, NULL);
		G_B378_0 = L_849;
		goto IL_193d;
	}

IL_1938:
	{
		G_B378_0 = ((int32_t)32767);
	}

IL_193d:
	{
		V_81 = G_B378_0;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_850 = V_12;
		int32_t L_851 = V_80;
		int32_t L_852 = V_81;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_853 = V_28;
		NullCheck(L_853);
		int32_t L_854 = L_853->___overlap;
		int32_t L_855 = ___2_frame_size;
		int32_t L_856 = __this->___channels;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_857 = V_28;
		NullCheck(L_857);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_858 = L_857->___window;
		int32_t L_859 = __this->___Fs;
		CodecHelpers_stereo_fade_mFC6173FD066FAC8E29FD80632BC92FC90CB188CC(L_850, L_851, L_852, L_854, L_855, L_856, L_858, L_859, NULL);
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_860 = __this->___silk_mode;
		NullCheck(L_860);
		int32_t L_861 = L_860->___stereoWidth_Q14;
		__this->___hybrid_stereo_width_Q14 = ((int16_t)L_861);
	}

IL_1977:
	{
		int32_t L_862 = __this->___mode;
		if ((((int32_t)L_862) == ((int32_t)((int32_t)1002))))
		{
			goto IL_1a7b;
		}
	}
	{
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_863 = V_5;
		NullCheck(L_863);
		int32_t L_864;
		L_864 = EntropyCoder_tell_m29422D894C6D91518823D9C94D3CC93ACEA2350A(L_863, NULL);
		int32_t L_865 = __this->___mode;
		if ((((int32_t)L_865) == ((int32_t)((int32_t)1001))))
		{
			G_B382_0 = ((int32_t)20);
			G_B382_1 = ((int32_t)il2cpp_codegen_add(L_864, ((int32_t)17)));
			goto IL_19a3;
		}
		G_B381_0 = ((int32_t)20);
		G_B381_1 = ((int32_t)il2cpp_codegen_add(L_864, ((int32_t)17)));
	}
	{
		G_B383_0 = 0;
		G_B383_1 = G_B381_0;
		G_B383_2 = G_B381_1;
		goto IL_19a4;
	}

IL_19a3:
	{
		G_B383_0 = 1;
		G_B383_1 = G_B382_0;
		G_B383_2 = G_B382_1;
	}

IL_19a4:
	{
		int32_t L_866 = V_25;
		if ((((int32_t)((int32_t)il2cpp_codegen_add(G_B383_2, ((int32_t)il2cpp_codegen_multiply(G_B383_1, G_B383_0))))) > ((int32_t)((int32_t)il2cpp_codegen_multiply(8, ((int32_t)il2cpp_codegen_subtract(L_866, 1)))))))
		{
			goto IL_1a7b;
		}
	}
	{
		int32_t L_867 = __this->___mode;
		if ((!(((uint32_t)L_867) == ((uint32_t)((int32_t)1001)))))
		{
			goto IL_19e6;
		}
	}
	{
		int32_t L_868 = V_9;
		if (L_868)
		{
			goto IL_19d2;
		}
	}
	{
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_869 = V_5;
		NullCheck(L_869);
		int32_t L_870;
		L_870 = EntropyCoder_tell_m29422D894C6D91518823D9C94D3CC93ACEA2350A(L_869, NULL);
		int32_t L_871 = V_13;
		if ((((int32_t)((int32_t)il2cpp_codegen_add(L_870, ((int32_t)37)))) > ((int32_t)((int32_t)il2cpp_codegen_multiply(8, L_871)))))
		{
			goto IL_19e6;
		}
	}

IL_19d2:
	{
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_872 = V_5;
		int32_t L_873 = ___4_data_ptr;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_874;
		L_874 = Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_inline((&___3_data), L_873, Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_RuntimeMethod_var);
		int32_t L_875 = V_9;
		NullCheck(L_872);
		EntropyCoder_enc_bit_logp_mC1EAC72518B155F99BBCBEDA4B2CC46D3B411386(L_872, L_874, L_875, (uint32_t)((int32_t)12), NULL);
	}

IL_19e6:
	{
		int32_t L_876 = V_9;
		if (!L_876)
		{
			goto IL_1a7e;
		}
	}
	{
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_877 = V_5;
		int32_t L_878 = ___4_data_ptr;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_879;
		L_879 = Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_inline((&___3_data), L_878, Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_RuntimeMethod_var);
		int32_t L_880 = V_11;
		NullCheck(L_877);
		EntropyCoder_enc_bit_logp_mC1EAC72518B155F99BBCBEDA4B2CC46D3B411386(L_877, L_879, L_880, (uint32_t)1, NULL);
		int32_t L_881 = __this->___mode;
		if ((!(((uint32_t)L_881) == ((uint32_t)((int32_t)1001)))))
		{
			goto IL_1a18;
		}
	}
	{
		int32_t L_882 = V_25;
		int32_t L_883 = V_13;
		V_82 = ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_882, 1)), L_883));
		goto IL_1a2a;
	}

IL_1a18:
	{
		int32_t L_884 = V_25;
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_885 = V_5;
		NullCheck(L_885);
		int32_t L_886;
		L_886 = EntropyCoder_tell_m29422D894C6D91518823D9C94D3CC93ACEA2350A(L_885, NULL);
		V_82 = ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_884, 1)), ((int32_t)(((int32_t)il2cpp_codegen_add(L_886, 7))>>3))));
	}

IL_1a2a:
	{
		int32_t L_887 = V_82;
		int32_t L_888 = __this->___bitrate_bps;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_889;
		L_889 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(L_887, ((int32_t)(L_888/((int32_t)1600))), NULL);
		V_10 = L_889;
		int32_t L_890 = V_10;
		int32_t L_891;
		L_891 = Inlines_IMAX_mFECDD1F5C3C0962AF8B0140E78A6C3A25BCF9C23_inline(2, L_890, NULL);
		int32_t L_892;
		L_892 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)257), L_891, NULL);
		V_10 = L_892;
		int32_t L_893 = __this->___mode;
		if ((!(((uint32_t)L_893) == ((uint32_t)((int32_t)1001)))))
		{
			goto IL_1a7e;
		}
	}
	{
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_894 = V_5;
		int32_t L_895 = ___4_data_ptr;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_896;
		L_896 = Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_inline((&___3_data), L_895, Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_RuntimeMethod_var);
		int32_t L_897 = V_10;
		NullCheck(L_894);
		EntropyCoder_enc_uint_m837AC206B7D194AC7114DE24B7D5858D1D7C48AA(L_894, L_896, (uint32_t)((int32_t)il2cpp_codegen_subtract(L_897, 2)), (uint32_t)((int32_t)256), NULL);
		goto IL_1a7e;
	}

IL_1a7b:
	{
		V_9 = 0;
	}

IL_1a7e:
	{
		int32_t L_898 = V_9;
		if (L_898)
		{
			goto IL_1a8c;
		}
	}
	{
		__this->___silk_bw_switch = 0;
		V_10 = 0;
	}

IL_1a8c:
	{
		int32_t L_899 = __this->___mode;
		if ((((int32_t)L_899) == ((int32_t)((int32_t)1002))))
		{
			goto IL_1a9d;
		}
	}
	{
		V_8 = ((int32_t)17);
	}

IL_1a9d:
	{
		int32_t L_900 = __this->___mode;
		if ((!(((uint32_t)L_900) == ((uint32_t)((int32_t)1000)))))
		{
			goto IL_1acb;
		}
	}
	{
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_901 = V_5;
		NullCheck(L_901);
		int32_t L_902;
		L_902 = EntropyCoder_tell_m29422D894C6D91518823D9C94D3CC93ACEA2350A(L_901, NULL);
		V_3 = ((int32_t)(((int32_t)il2cpp_codegen_add(L_902, 7))>>3));
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_903 = V_5;
		int32_t L_904 = ___4_data_ptr;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_905;
		L_905 = Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_inline((&___3_data), L_904, Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_RuntimeMethod_var);
		NullCheck(L_903);
		EntropyCoder_enc_done_m25B7802F220D99E2CE5C1C34F99E7B8622126BCD(L_903, L_905, NULL);
		int32_t L_906 = V_3;
		V_13 = L_906;
		goto IL_1aed;
	}

IL_1acb:
	{
		int32_t L_907 = V_25;
		int32_t L_908 = V_10;
		int32_t L_909 = V_13;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_910;
		L_910 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_907, 1)), L_908)), L_909, NULL);
		V_13 = L_910;
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_911 = V_5;
		int32_t L_912 = ___4_data_ptr;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_913;
		L_913 = Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_inline((&___3_data), L_912, Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_RuntimeMethod_var);
		int32_t L_914 = V_13;
		NullCheck(L_911);
		EntropyCoder_enc_shrink_m2993D050F3B8C868157623824E04629980073C88(L_911, L_913, (uint32_t)L_914, NULL);
	}

IL_1aed:
	{
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_915 = __this->___analysis;
		NullCheck(L_915);
		bool L_916 = L_915->___enabled;
		if (!L_916)
		{
			goto IL_1afe;
		}
	}
	{
		int32_t L_917 = V_9;
		if (L_917)
		{
			goto IL_1b0b;
		}
	}

IL_1afe:
	{
		int32_t L_918 = __this->___mode;
		if ((((int32_t)L_918) == ((int32_t)((int32_t)1000))))
		{
			goto IL_1b13;
		}
	}

IL_1b0b:
	{
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_919 = V_1;
		AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* L_920 = V_29;
		NullCheck(L_919);
		CeltEncoder_SetAnalysis_m96468AD3A56A695114BD18D2FC056144ECDA48E5(L_919, L_920, NULL);
	}

IL_1b13:
	{
		int32_t L_921 = V_9;
		if (!L_921)
		{
			goto IL_1b61;
		}
	}
	{
		int32_t L_922 = V_11;
		if (!L_922)
		{
			goto IL_1b61;
		}
	}
	{
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_923 = V_1;
		NullCheck(L_923);
		CeltEncoder_SetStartBand_mC5BFCE123D5E277F500238D96D5042CC6630A8D7(L_923, 0, NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_924 = V_1;
		NullCheck(L_924);
		CeltEncoder_SetVBR_mB2A8CFC94909FB78E5D6B5CCEC287AE5C26748BB(L_924, (bool)0, NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_925 = V_1;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_926 = V_12;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_927;
		L_927 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_926, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_928 = __this->___Fs;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_929 = ___3_data;
		int32_t L_930 = ___4_data_ptr;
		int32_t L_931 = V_13;
		int32_t L_932 = V_10;
		NullCheck(L_925);
		int32_t L_933;
		L_933 = CeltEncoder_celt_encode_with_ec_m2FF33A330E55AB3C586618444D6615182988E8CF(L_925, L_927, 0, ((int32_t)(L_928/((int32_t)200))), L_929, ((int32_t)il2cpp_codegen_add(L_930, L_931)), L_932, (EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679*)NULL, NULL);
		if ((((int32_t)L_933) >= ((int32_t)0)))
		{
			goto IL_1b53;
		}
	}
	{
		return ((int32_t)-3);
	}

IL_1b53:
	{
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_934 = V_1;
		NullCheck(L_934);
		uint32_t L_935;
		L_935 = CeltEncoder_GetFinalRange_m4BF672C1B80DD81A5D86981BA9EB8CE699F159CF_inline(L_934, NULL);
		V_15 = L_935;
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_936 = V_1;
		NullCheck(L_936);
		CeltEncoder_ResetState_m1C30EBAD2FA89D556072892E54D8414AC010618B(L_936, NULL);
	}

IL_1b61:
	{
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_937 = V_1;
		int32_t L_938 = V_8;
		NullCheck(L_937);
		CeltEncoder_SetStartBand_mC5BFCE123D5E277F500238D96D5042CC6630A8D7(L_937, L_938, NULL);
		int32_t L_939 = __this->___mode;
		if ((((int32_t)L_939) == ((int32_t)((int32_t)1000))))
		{
			goto IL_1bfb;
		}
	}
	{
		int32_t L_940 = __this->___mode;
		int32_t L_941 = __this->___prev_mode;
		if ((((int32_t)L_940) == ((int32_t)L_941)))
		{
			goto IL_1bc9;
		}
	}
	{
		int32_t L_942 = __this->___prev_mode;
		if ((((int32_t)L_942) <= ((int32_t)0)))
		{
			goto IL_1bc9;
		}
	}
	{
		uintptr_t L_943 = ((uintptr_t)2);
		int8_t* L_944 = (int8_t*) (L_943 ? alloca(L_943) : NULL);
		memset(L_944, 0, L_943);
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_945;
		memset((&L_945), 0, sizeof(L_945));
		Span_1__ctor_mE18EBB601FBFA01BA29FE353364700952A9091FE_inline((&L_945), (void*)(L_944), 2, Span_1__ctor_mE18EBB601FBFA01BA29FE353364700952A9091FE_RuntimeMethod_var);
		V_83 = L_945;
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_946 = V_1;
		NullCheck(L_946);
		CeltEncoder_ResetState_m1C30EBAD2FA89D556072892E54D8414AC010618B(L_946, NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_947 = V_1;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_948 = V_32;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_949;
		L_949 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_948, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_950 = __this->___Fs;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_951 = V_83;
		NullCheck(L_947);
		int32_t L_952;
		L_952 = CeltEncoder_celt_encode_with_ec_m2FF33A330E55AB3C586618444D6615182988E8CF(L_947, L_949, 0, ((int32_t)(L_950/((int32_t)400))), L_951, 0, 2, (EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679*)NULL, NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_953 = V_1;
		NullCheck(L_953);
		CeltEncoder_SetPrediction_m880E0433982007C125828ED68A45A4A134798EB4(L_953, 0, NULL);
	}

IL_1bc9:
	{
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_954 = V_5;
		NullCheck(L_954);
		int32_t L_955;
		L_955 = EntropyCoder_tell_m29422D894C6D91518823D9C94D3CC93ACEA2350A(L_954, NULL);
		int32_t L_956 = V_13;
		if ((((int32_t)L_955) > ((int32_t)((int32_t)il2cpp_codegen_multiply(8, L_956)))))
		{
			goto IL_1bfb;
		}
	}
	{
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_957 = V_1;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_958 = V_12;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_959;
		L_959 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_958, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_960 = ___2_frame_size;
		int32_t L_961 = ___4_data_ptr;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_962;
		L_962 = Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_inline((&___3_data), L_961, Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_RuntimeMethod_var);
		int32_t L_963 = V_13;
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_964 = V_5;
		NullCheck(L_957);
		int32_t L_965;
		L_965 = CeltEncoder_celt_encode_with_ec_m2FF33A330E55AB3C586618444D6615182988E8CF(L_957, L_959, 0, L_960, L_962, 0, L_963, L_964, NULL);
		V_3 = L_965;
		int32_t L_966 = V_3;
		if ((((int32_t)L_966) >= ((int32_t)0)))
		{
			goto IL_1bfb;
		}
	}
	{
		return ((int32_t)-3);
	}

IL_1bfb:
	{
		int32_t L_967 = V_9;
		if (!L_967)
		{
			goto IL_1c9a;
		}
	}
	{
		int32_t L_968 = V_11;
		if (L_968)
		{
			goto IL_1c9a;
		}
	}
	{
		uintptr_t L_969 = ((uintptr_t)2);
		int8_t* L_970 = (int8_t*) (L_969 ? alloca(L_969) : NULL);
		memset(L_970, 0, L_969);
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_971;
		memset((&L_971), 0, sizeof(L_971));
		Span_1__ctor_mE18EBB601FBFA01BA29FE353364700952A9091FE_inline((&L_971), (void*)(L_970), 2, Span_1__ctor_mE18EBB601FBFA01BA29FE353364700952A9091FE_RuntimeMethod_var);
		V_84 = L_971;
		int32_t L_972 = __this->___Fs;
		V_85 = ((int32_t)(L_972/((int32_t)200)));
		int32_t L_973 = __this->___Fs;
		V_86 = ((int32_t)(L_973/((int32_t)400)));
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_974 = V_1;
		NullCheck(L_974);
		CeltEncoder_ResetState_m1C30EBAD2FA89D556072892E54D8414AC010618B(L_974, NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_975 = V_1;
		NullCheck(L_975);
		CeltEncoder_SetStartBand_mC5BFCE123D5E277F500238D96D5042CC6630A8D7(L_975, 0, NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_976 = V_1;
		NullCheck(L_976);
		CeltEncoder_SetPrediction_m880E0433982007C125828ED68A45A4A134798EB4(L_976, 0, NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_977 = V_1;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_978 = V_12;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_979;
		L_979 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_978, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_980 = __this->___channels;
		int32_t L_981 = ___2_frame_size;
		int32_t L_982 = V_85;
		int32_t L_983 = V_86;
		int32_t L_984 = V_86;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_985 = V_84;
		NullCheck(L_977);
		int32_t L_986;
		L_986 = CeltEncoder_celt_encode_with_ec_m2FF33A330E55AB3C586618444D6615182988E8CF(L_977, L_979, ((int32_t)il2cpp_codegen_multiply(L_980, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_981, L_982)), L_983)))), L_984, L_985, 0, 2, (EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679*)NULL, NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_987 = V_1;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_988 = V_12;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_989;
		L_989 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_988, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_990 = __this->___channels;
		int32_t L_991 = ___2_frame_size;
		int32_t L_992 = V_85;
		int32_t L_993 = V_85;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_994 = ___3_data;
		int32_t L_995 = ___4_data_ptr;
		int32_t L_996 = V_13;
		int32_t L_997 = V_10;
		NullCheck(L_987);
		int32_t L_998;
		L_998 = CeltEncoder_celt_encode_with_ec_m2FF33A330E55AB3C586618444D6615182988E8CF(L_987, L_989, ((int32_t)il2cpp_codegen_multiply(L_990, ((int32_t)il2cpp_codegen_subtract(L_991, L_992)))), L_993, L_994, ((int32_t)il2cpp_codegen_add(L_995, L_996)), L_997, (EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679*)NULL, NULL);
		if ((((int32_t)L_998) >= ((int32_t)0)))
		{
			goto IL_1c92;
		}
	}
	{
		return ((int32_t)-3);
	}

IL_1c92:
	{
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_999 = V_1;
		NullCheck(L_999);
		uint32_t L_1000;
		L_1000 = CeltEncoder_GetFinalRange_m4BF672C1B80DD81A5D86981BA9EB8CE699F159CF_inline(L_999, NULL);
		V_15 = L_1000;
	}

IL_1c9a:
	{
		int32_t L_1001 = ___4_data_ptr;
		___4_data_ptr = ((int32_t)il2cpp_codegen_subtract(L_1001, 1));
		int32_t L_1002 = ___4_data_ptr;
		uint8_t* L_1003;
		L_1003 = il2cpp_span_get_item((uint8_t*)((Il2CppByReference*)&(((&___3_data))->____pointer))->value, (L_1002), ((&___3_data))->____length);
		int32_t L_1004 = __this->___mode;
		int32_t L_1005 = __this->___Fs;
		int32_t L_1006 = ___2_frame_size;
		int32_t L_1007 = V_23;
		int32_t L_1008 = __this->___stream_channels;
		uint8_t L_1009;
		L_1009 = CodecHelpers_gen_toc_m55919D0EC27589F5328AD925AA91F8B0D4A9EBA2(L_1004, ((int32_t)(L_1005/L_1006)), L_1007, L_1008, NULL);
		*((int8_t*)L_1003) = (int8_t)L_1009;
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_1010 = V_5;
		NullCheck(L_1010);
		uint32_t L_1011 = L_1010->___rng;
		uint32_t L_1012 = V_15;
		__this->___rangeFinal = (uint32_t)((int32_t)((int32_t)L_1011^(int32_t)L_1012));
		int32_t L_1013 = V_14;
		if (!L_1013)
		{
			goto IL_1ce6;
		}
	}
	{
		__this->___prev_mode = (int32_t)((int32_t)1002);
		goto IL_1cf2;
	}

IL_1ce6:
	{
		int32_t L_1014 = __this->___mode;
		__this->___prev_mode = L_1014;
	}

IL_1cf2:
	{
		int32_t L_1015 = __this->___stream_channels;
		__this->___prev_channels = L_1015;
		int32_t L_1016 = ___2_frame_size;
		__this->___prev_framesize = L_1016;
		__this->___first = 0;
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_1017 = V_5;
		NullCheck(L_1017);
		int32_t L_1018;
		L_1018 = EntropyCoder_tell_m29422D894C6D91518823D9C94D3CC93ACEA2350A(L_1017, NULL);
		int32_t L_1019 = V_25;
		if ((((int32_t)L_1018) <= ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_subtract(L_1019, 1)), 8)))))
		{
			goto IL_1d3b;
		}
	}
	{
		int32_t L_1020 = V_25;
		if ((((int32_t)L_1020) >= ((int32_t)2)))
		{
			goto IL_1d23;
		}
	}
	{
		return ((int32_t)-2);
	}

IL_1d23:
	{
		int32_t L_1021 = ___4_data_ptr;
		uint8_t* L_1022;
		L_1022 = il2cpp_span_get_item((uint8_t*)((Il2CppByReference*)&(((&___3_data))->____pointer))->value, (((int32_t)il2cpp_codegen_add(L_1021, 1))), ((&___3_data))->____length);
		*((int8_t*)L_1022) = (int8_t)0;
		V_3 = 1;
		__this->___rangeFinal = (uint32_t)0;
		goto IL_1d64;
	}

IL_1d3b:
	{
		int32_t L_1023 = __this->___mode;
		if ((!(((uint32_t)L_1023) == ((uint32_t)((int32_t)1000)))))
		{
			goto IL_1d64;
		}
	}
	{
		int32_t L_1024 = V_9;
		if (L_1024)
		{
			goto IL_1d64;
		}
	}
	{
		goto IL_1d52;
	}

IL_1d4e:
	{
		int32_t L_1025 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_1025, 1));
	}

IL_1d52:
	{
		int32_t L_1026 = V_3;
		if ((((int32_t)L_1026) <= ((int32_t)2)))
		{
			goto IL_1d64;
		}
	}
	{
		int32_t L_1027 = ___4_data_ptr;
		int32_t L_1028 = V_3;
		uint8_t* L_1029;
		L_1029 = il2cpp_span_get_item((uint8_t*)((Il2CppByReference*)&(((&___3_data))->____pointer))->value, (((int32_t)il2cpp_codegen_add(L_1027, L_1028))), ((&___3_data))->____length);
		int32_t L_1030 = *((uint8_t*)L_1029);
		if (!L_1030)
		{
			goto IL_1d4e;
		}
	}

IL_1d64:
	{
		int32_t L_1031 = V_3;
		int32_t L_1032 = V_10;
		V_3 = ((int32_t)il2cpp_codegen_add(L_1031, ((int32_t)il2cpp_codegen_add(1, L_1032))));
		int32_t L_1033 = __this->___use_vbr;
		if (L_1033)
		{
			goto IL_1d87;
		}
	}
	{
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_1034 = ___3_data;
		int32_t L_1035 = ___4_data_ptr;
		int32_t L_1036 = V_3;
		int32_t L_1037 = V_25;
		int32_t L_1038;
		L_1038 = OpusRepacketizer_PadPacket_m31BC672C1100238AAE7DF0EEC74000D8CD39AD8E(L_1034, L_1035, L_1036, L_1037, NULL);
		if (!L_1038)
		{
			goto IL_1d84;
		}
	}
	{
		return ((int32_t)-3);
	}

IL_1d84:
	{
		int32_t L_1039 = V_25;
		V_3 = L_1039;
	}

IL_1d87:
	{
		int32_t L_1040 = V_3;
		return L_1040;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusEncoder_opus_encode_native_TisIl2CppFullySharedGenericAny_m7BF0A752A920C268A481ACE3A1D81444857478F0_gshared (OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* __this, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 ___0_pcm, int32_t ___1_pcm_ptr, int32_t ___2_frame_size, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___3_data, int32_t ___4_data_ptr, int32_t ___5_out_data_bytes, int32_t ___6_lsb_depth, ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC ___7_analysis_pcm, int32_t ___8_analysis_size, int32_t ___9_c1, int32_t ___10_c2, int32_t ___11_analysis_channels, downmix_func_1_t2D72777593561EEC6CFDD92FFD20BF708F537039* ___12_downmix, int32_t ___13_float_api, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EncControlState_t1F753CF3968665C2171A288F862D70168F348019_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Nullable_1_get_Value_m0DF3B826A745419D26A168689AEB4BE6F8698ECA_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1__ctor_mE18EBB601FBFA01BA29FE353364700952A9091FE_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	SilkEncoder_t7AB5C2F712CDB92EBFCDAF8E9743C5A39B7CFD6D* V_0 = NULL;
	CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* V_5 = NULL;
	int32_t V_6 = 0;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	int32_t V_10 = 0;
	int32_t V_11 = 0;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t V_14 = 0;
	uint32_t V_15 = 0;
	int32_t V_16 = 0;
	int32_t V_17 = 0;
	int32_t V_18 = 0;
	int32_t V_19 = 0;
	int32_t V_20 = 0;
	int32_t V_21 = 0;
	int32_t V_22 = 0;
	int32_t V_23 = 0;
	int32_t V_24 = 0;
	int32_t V_25 = 0;
	int32_t V_26 = 0;
	int32_t V_27 = 0;
	CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* V_28 = NULL;
	AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* V_29 = NULL;
	int32_t V_30 = 0;
	int32_t V_31 = 0;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* V_32 = NULL;
	int32_t V_33 = 0;
	int32_t V_34 = 0;
	int32_t V_35 = 0;
	int32_t V_36 = 0;
	int32_t V_37 = 0;
	int32_t V_38 = 0;
	int32_t V_39 = 0;
	int32_t V_40 = 0;
	int32_t V_41 = 0;
	EncControlState_t1F753CF3968665C2171A288F862D70168F348019* V_42 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_43 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_44 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_45 = NULL;
	int32_t V_46 = 0;
	int32_t V_47 = 0;
	int32_t V_48 = 0;
	int32_t V_49 = 0;
	int32_t V_50 = 0;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_51 = NULL;
	int32_t V_52 = 0;
	int32_t V_53 = 0;
	int32_t V_54 = 0;
	int32_t V_55 = 0;
	int32_t V_56 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* V_57 = NULL;
	int32_t V_58 = 0;
	int32_t V_59 = 0;
	int32_t V_60 = 0;
	int32_t V_61 = 0;
	int32_t V_62 = 0;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* V_63 = NULL;
	BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* V_64 = NULL;
	int32_t V_65 = 0;
	int32_t V_66 = 0;
	int32_t V_67 = 0;
	int32_t V_68 = 0;
	int32_t V_69 = 0;
	int32_t V_70 = 0;
	int16_t V_71 = 0;
	int32_t V_72 = 0;
	int32_t V_73 = 0;
	BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* V_74 = NULL;
	int32_t V_75 = 0;
	int32_t V_76 = 0;
	int32_t V_77 = 0;
	int32_t V_78 = 0;
	int32_t V_79 = 0;
	int32_t V_80 = 0;
	int32_t V_81 = 0;
	int32_t V_82 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 V_83;
	memset((&V_83), 0, sizeof(V_83));
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 V_84;
	memset((&V_84), 0, sizeof(V_84));
	int32_t V_85 = 0;
	int32_t V_86 = 0;
	int32_t G_B46_0 = 0;
	OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* G_B84_0 = NULL;
	OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* G_B83_0 = NULL;
	int32_t G_B85_0 = 0;
	OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* G_B85_1 = NULL;
	OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* G_B98_0 = NULL;
	OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* G_B97_0 = NULL;
	int32_t G_B99_0 = 0;
	OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* G_B99_1 = NULL;
	int32_t G_B113_0 = 0;
	int32_t G_B112_0 = 0;
	int32_t G_B114_0 = 0;
	int32_t G_B114_1 = 0;
	int32_t G_B131_0 = 0;
	int32_t G_B214_0 = 0;
	int32_t G_B232_0 = 0;
	int32_t G_B232_1 = 0;
	int32_t G_B232_2 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B232_3;
	memset((&G_B232_3), 0, sizeof(G_B232_3));
	int32_t G_B232_4 = 0;
	int32_t G_B232_5 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B232_6 = NULL;
	int32_t G_B231_0 = 0;
	int32_t G_B231_1 = 0;
	int32_t G_B231_2 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B231_3;
	memset((&G_B231_3), 0, sizeof(G_B231_3));
	int32_t G_B231_4 = 0;
	int32_t G_B231_5 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B231_6 = NULL;
	int32_t G_B233_0 = 0;
	int32_t G_B233_1 = 0;
	int32_t G_B233_2 = 0;
	int32_t G_B233_3 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B233_4;
	memset((&G_B233_4), 0, sizeof(G_B233_4));
	int32_t G_B233_5 = 0;
	int32_t G_B233_6 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B233_7 = NULL;
	int32_t G_B252_0 = 0;
	int32_t G_B252_1 = 0;
	EncControlState_t1F753CF3968665C2171A288F862D70168F348019* G_B252_2 = NULL;
	int32_t G_B251_0 = 0;
	int32_t G_B251_1 = 0;
	EncControlState_t1F753CF3968665C2171A288F862D70168F348019* G_B251_2 = NULL;
	int32_t G_B253_0 = 0;
	int32_t G_B253_1 = 0;
	int32_t G_B253_2 = 0;
	EncControlState_t1F753CF3968665C2171A288F862D70168F348019* G_B253_3 = NULL;
	int32_t G_B262_0 = 0;
	int32_t G_B265_0 = 0;
	EncControlState_t1F753CF3968665C2171A288F862D70168F348019* G_B305_0 = NULL;
	EncControlState_t1F753CF3968665C2171A288F862D70168F348019* G_B304_0 = NULL;
	int32_t G_B306_0 = 0;
	EncControlState_t1F753CF3968665C2171A288F862D70168F348019* G_B306_1 = NULL;
	int32_t G_B338_0 = 0;
	int32_t G_B337_0 = 0;
	int32_t G_B339_0 = 0;
	int32_t G_B339_1 = 0;
	int32_t G_B345_0 = 0;
	int32_t G_B375_0 = 0;
	int32_t G_B378_0 = 0;
	int32_t G_B382_0 = 0;
	int32_t G_B382_1 = 0;
	int32_t G_B381_0 = 0;
	int32_t G_B381_1 = 0;
	int32_t G_B383_0 = 0;
	int32_t G_B383_1 = 0;
	int32_t G_B383_2 = 0;
	{
		V_3 = 0;
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_0 = (EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679*)il2cpp_codegen_object_new(EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679_il2cpp_TypeInfo_var);
		EntropyCoder__ctor_m94DD0C4B87D72A98041935C6879744E5FBF72E73(L_0, NULL);
		V_5 = L_0;
		V_7 = 0;
		V_8 = 0;
		V_9 = 0;
		V_10 = 0;
		V_11 = 0;
		V_14 = 0;
		V_15 = (uint32_t)0;
		AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* L_1 = (AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116*)il2cpp_codegen_object_new(AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116_il2cpp_TypeInfo_var);
		AnalysisInfo__ctor_m9F52F6126A6EB1E81FD9A18DF4B9E24F357D782E(L_1, NULL);
		V_29 = L_1;
		V_30 = (-1);
		V_31 = (-1);
		int32_t L_2 = ___5_out_data_bytes;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)1276), L_2, NULL);
		V_25 = L_3;
		__this->___rangeFinal = (uint32_t)0;
		int32_t L_4 = __this->___variable_duration;
		if (L_4)
		{
			goto IL_0098;
		}
	}
	{
		int32_t L_5 = ___2_frame_size;
		int32_t L_6 = __this->___Fs;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)400), L_5))) == ((int32_t)L_6)))
		{
			goto IL_0098;
		}
	}
	{
		int32_t L_7 = ___2_frame_size;
		int32_t L_8 = __this->___Fs;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)200), L_7))) == ((int32_t)L_8)))
		{
			goto IL_0098;
		}
	}
	{
		int32_t L_9 = ___2_frame_size;
		int32_t L_10 = __this->___Fs;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)100), L_9))) == ((int32_t)L_10)))
		{
			goto IL_0098;
		}
	}
	{
		int32_t L_11 = ___2_frame_size;
		int32_t L_12 = __this->___Fs;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)50), L_11))) == ((int32_t)L_12)))
		{
			goto IL_0098;
		}
	}
	{
		int32_t L_13 = ___2_frame_size;
		int32_t L_14 = __this->___Fs;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)25), L_13))) == ((int32_t)L_14)))
		{
			goto IL_0098;
		}
	}
	{
		int32_t L_15 = ___2_frame_size;
		int32_t L_16 = __this->___Fs;
		if ((!(((uint32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)50), L_15))) == ((uint32_t)((int32_t)il2cpp_codegen_multiply(3, L_16))))))
		{
			goto IL_00ac;
		}
	}

IL_0098:
	{
		int32_t L_17 = ___2_frame_size;
		int32_t L_18 = __this->___Fs;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)400), L_17))) < ((int32_t)L_18)))
		{
			goto IL_00ac;
		}
	}
	{
		int32_t L_19 = V_25;
		if ((((int32_t)L_19) > ((int32_t)0)))
		{
			goto IL_00ae;
		}
	}

IL_00ac:
	{
		return (-1);
	}

IL_00ae:
	{
		SilkEncoder_t7AB5C2F712CDB92EBFCDAF8E9743C5A39B7CFD6D* L_20 = __this->___SilkEncoder;
		V_0 = L_20;
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_21 = __this->___Celt_Encoder;
		V_1 = L_21;
		int32_t L_22 = __this->___application;
		if ((!(((uint32_t)L_22) == ((uint32_t)((int32_t)2051)))))
		{
			goto IL_00ce;
		}
	}
	{
		V_20 = 0;
		goto IL_00d6;
	}

IL_00ce:
	{
		int32_t L_23 = __this->___delay_compensation;
		V_20 = L_23;
	}

IL_00d6:
	{
		int32_t L_24 = ___6_lsb_depth;
		int32_t L_25 = __this->___lsb_depth;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_26;
		L_26 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(L_24, L_25, NULL);
		___6_lsb_depth = L_26;
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_27 = V_1;
		NullCheck(L_27);
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_28;
		L_28 = CeltEncoder_GetMode_m51534658A97582FB288A8023F6AA133BFBB8AC1F_inline(L_27, NULL);
		V_28 = L_28;
		__this->___voice_ratio = (-1);
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_29 = __this->___analysis;
		NullCheck(L_29);
		bool L_30 = L_29->___enabled;
		if (!L_30)
		{
			goto IL_0246;
		}
	}
	{
		AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* L_31 = V_29;
		NullCheck(L_31);
		L_31->___valid = 0;
		Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28* L_32 = (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28*)(&__this->____vqLevel);
		bool L_33;
		L_33 = Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_inline(L_32, Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_RuntimeMethod_var);
		if (L_33)
		{
			goto IL_0127;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_34 = __this->___silk_mode;
		NullCheck(L_34);
		int32_t L_35 = L_34->___complexity;
		if ((((int32_t)L_35) < ((int32_t)7)))
		{
			goto IL_0172;
		}
	}

IL_0127:
	{
		int32_t L_36 = __this->___Fs;
		if ((!(((uint32_t)L_36) == ((uint32_t)((int32_t)48000)))))
		{
			goto IL_0172;
		}
	}
	{
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_37 = __this->___analysis;
		NullCheck(L_37);
		int32_t L_38 = L_37->___read_pos;
		V_30 = L_38;
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_39 = __this->___analysis;
		NullCheck(L_39);
		int32_t L_40 = L_39->___read_subframe;
		V_31 = L_40;
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_41 = __this->___analysis;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_42 = V_28;
		ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC L_43 = ___7_analysis_pcm;
		int32_t L_44 = ___8_analysis_size;
		int32_t L_45 = ___2_frame_size;
		int32_t L_46 = ___9_c1;
		int32_t L_47 = ___10_c2;
		int32_t L_48 = ___11_analysis_channels;
		int32_t L_49 = __this->___Fs;
		int32_t L_50 = ___6_lsb_depth;
		downmix_func_1_t2D72777593561EEC6CFDD92FFD20BF708F537039* L_51 = ___12_downmix;
		AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* L_52 = V_29;
		((  void (*) (TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709*, CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5*, ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, downmix_func_1_t2D72777593561EEC6CFDD92FFD20BF708F537039*, AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(L_41, L_42, L_43, L_44, L_45, L_46, L_47, L_48, L_49, L_50, L_51, L_52, il2cpp_rgctx_method(method->rgctx_data, 2));
	}

IL_0172:
	{
		__this->___detected_bandwidth = (int32_t)0;
		AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* L_53 = V_29;
		NullCheck(L_53);
		int32_t L_54 = L_53->___valid;
		if (!L_54)
		{
			goto IL_0246;
		}
	}
	{
		int32_t L_55 = __this->___signal_type;
		if ((!(((uint32_t)L_55) == ((uint32_t)((int32_t)-1000)))))
		{
			goto IL_01b8;
		}
	}
	{
		AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* L_56 = V_29;
		NullCheck(L_56);
		float L_57 = L_56->___music_prob;
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_58;
		L_58 = floor(((double)((float)il2cpp_codegen_add((0.5f), ((float)il2cpp_codegen_multiply((100.0f), ((float)il2cpp_codegen_subtract((1.0f), L_57))))))));
		__this->___voice_ratio = il2cpp_codegen_cast_double_to_int<int32_t>(L_58);
	}

IL_01b8:
	{
		AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* L_59 = V_29;
		NullCheck(L_59);
		int32_t L_60 = L_59->___bandwidth;
		V_33 = L_60;
		int32_t L_61 = V_33;
		if ((((int32_t)L_61) > ((int32_t)((int32_t)12))))
		{
			goto IL_01d4;
		}
	}
	{
		__this->___detected_bandwidth = (int32_t)((int32_t)1101);
		goto IL_0218;
	}

IL_01d4:
	{
		int32_t L_62 = V_33;
		if ((((int32_t)L_62) > ((int32_t)((int32_t)14))))
		{
			goto IL_01e7;
		}
	}
	{
		__this->___detected_bandwidth = (int32_t)((int32_t)1102);
		goto IL_0218;
	}

IL_01e7:
	{
		int32_t L_63 = V_33;
		if ((((int32_t)L_63) > ((int32_t)((int32_t)16))))
		{
			goto IL_01fa;
		}
	}
	{
		__this->___detected_bandwidth = (int32_t)((int32_t)1103);
		goto IL_0218;
	}

IL_01fa:
	{
		int32_t L_64 = V_33;
		if ((((int32_t)L_64) > ((int32_t)((int32_t)18))))
		{
			goto IL_020d;
		}
	}
	{
		__this->___detected_bandwidth = (int32_t)((int32_t)1104);
		goto IL_0218;
	}

IL_020d:
	{
		__this->___detected_bandwidth = (int32_t)((int32_t)1105);
	}

IL_0218:
	{
		Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28* L_65 = (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28*)(&__this->____vqLevel);
		bool L_66;
		L_66 = Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_inline(L_65, Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_RuntimeMethod_var);
		if (!L_66)
		{
			goto IL_0246;
		}
	}
	{
		Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28* L_67 = (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28*)(&__this->____vqLevel);
		int32_t L_68;
		L_68 = Nullable_1_get_Value_m0DF3B826A745419D26A168689AEB4BE6F8698ECA(L_67, Nullable_1_get_Value_m0DF3B826A745419D26A168689AEB4BE6F8698ECA_RuntimeMethod_var);
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_69 = __this->___analysis;
		NullCheck(L_69);
		float L_70 = L_69->___music_prob;
		il2cpp_codegen_runtime_class_init_inline(OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44_il2cpp_TypeInfo_var);
		int32_t L_71;
		L_71 = OpusEncoder_GetVariableQualityBitrate_m6FFBB73E7634B913CF7E2CC60B9076164F1FD0F0(L_68, L_70, NULL);
		__this->___user_bitrate_bps = L_71;
	}

IL_0246:
	{
		int32_t L_72 = __this->___channels;
		if ((!(((uint32_t)L_72) == ((uint32_t)2))))
		{
			goto IL_0270;
		}
	}
	{
		int32_t L_73 = __this->___force_channels;
		if ((((int32_t)L_73) == ((int32_t)1)))
		{
			goto IL_0270;
		}
	}
	{
		ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 L_74 = ___0_pcm;
		int32_t L_75 = ___1_pcm_ptr;
		int32_t L_76 = ___2_frame_size;
		int32_t L_77 = __this->___Fs;
		StereoWidthState_t6D080EFAD3AC590D3319CE7BA4DDA0132E7822A2* L_78 = __this->___width_mem;
		int32_t L_79;
		L_79 = CodecHelpers_compute_stereo_width_mA9CC3FA2171877D74ABBB105235A850A5719949E(L_74, L_75, L_76, L_77, L_78, NULL);
		V_27 = L_79;
		goto IL_0273;
	}

IL_0270:
	{
		V_27 = 0;
	}

IL_0273:
	{
		int32_t L_80 = V_20;
		V_26 = L_80;
		int32_t L_81 = __this->___user_bitrate_bps;
		int32_t L_82 = ___2_frame_size;
		int32_t L_83 = V_25;
		int32_t L_84;
		L_84 = OpusEncoder_user_bitrate_to_bitrate_m18DBA826BE2FA33650295C2A6CD39A9E9C8D683F(__this, L_81, L_82, L_83, NULL);
		__this->___bitrate_bps = L_84;
		int32_t L_85 = __this->___Fs;
		int32_t L_86 = ___2_frame_size;
		V_21 = ((int32_t)(L_85/L_86));
		int32_t L_87 = __this->___use_vbr;
		if (L_87)
		{
			goto IL_02d8;
		}
	}
	{
		int32_t L_88 = __this->___Fs;
		int32_t L_89 = ___2_frame_size;
		V_35 = ((int32_t)(((int32_t)il2cpp_codegen_multiply(3, L_88))/L_89));
		int32_t L_90 = __this->___bitrate_bps;
		int32_t L_91 = V_35;
		int32_t L_92 = V_35;
		int32_t L_93 = V_25;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_94;
		L_94 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)(((int32_t)il2cpp_codegen_add(((int32_t)(((int32_t)il2cpp_codegen_multiply(3, L_90))/8)), ((int32_t)(L_91/2))))/L_92)), L_93, NULL);
		V_34 = L_94;
		int32_t L_95 = V_34;
		int32_t L_96 = V_35;
		__this->___bitrate_bps = ((int32_t)(((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_multiply(L_95, L_96)), 8))/3));
		int32_t L_97 = V_34;
		V_25 = L_97;
	}

IL_02d8:
	{
		int32_t L_98 = V_25;
		if ((((int32_t)L_98) < ((int32_t)3)))
		{
			goto IL_0310;
		}
	}
	{
		int32_t L_99 = __this->___bitrate_bps;
		int32_t L_100 = V_21;
		if ((((int32_t)L_99) < ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_multiply(3, L_100)), 8)))))
		{
			goto IL_0310;
		}
	}
	{
		int32_t L_101 = V_21;
		if ((((int32_t)L_101) >= ((int32_t)((int32_t)50))))
		{
			goto IL_03dd;
		}
	}
	{
		int32_t L_102 = V_25;
		int32_t L_103 = V_21;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(L_102, L_103))) < ((int32_t)((int32_t)300))))
		{
			goto IL_0310;
		}
	}
	{
		int32_t L_104 = __this->___bitrate_bps;
		if ((((int32_t)L_104) >= ((int32_t)((int32_t)2400))))
		{
			goto IL_03dd;
		}
	}

IL_0310:
	{
		int32_t L_105 = __this->___mode;
		V_36 = L_105;
		int32_t L_106 = __this->___bandwidth;
		if (!L_106)
		{
			goto IL_0328;
		}
	}
	{
		int32_t L_107 = __this->___bandwidth;
		G_B46_0 = ((int32_t)(L_107));
		goto IL_032d;
	}

IL_0328:
	{
		G_B46_0 = ((int32_t)1101);
	}

IL_032d:
	{
		V_37 = (int32_t)G_B46_0;
		int32_t L_108 = V_36;
		if (L_108)
		{
			goto IL_033a;
		}
	}
	{
		V_36 = (int32_t)((int32_t)1000);
	}

IL_033a:
	{
		int32_t L_109 = V_21;
		if ((((int32_t)L_109) <= ((int32_t)((int32_t)100))))
		{
			goto IL_0347;
		}
	}
	{
		V_36 = (int32_t)((int32_t)1002);
	}

IL_0347:
	{
		int32_t L_110 = V_21;
		if ((((int32_t)L_110) >= ((int32_t)((int32_t)50))))
		{
			goto IL_0354;
		}
	}
	{
		V_36 = (int32_t)((int32_t)1000);
	}

IL_0354:
	{
		int32_t L_111 = V_36;
		if ((!(((uint32_t)L_111) == ((uint32_t)((int32_t)1000)))))
		{
			goto IL_036f;
		}
	}
	{
		int32_t L_112 = V_37;
		if ((((int32_t)L_112) <= ((int32_t)((int32_t)1103))))
		{
			goto IL_036f;
		}
	}
	{
		V_37 = (int32_t)((int32_t)1103);
		goto IL_03a3;
	}

IL_036f:
	{
		int32_t L_113 = V_36;
		if ((!(((uint32_t)L_113) == ((uint32_t)((int32_t)1002)))))
		{
			goto IL_038a;
		}
	}
	{
		int32_t L_114 = V_37;
		if ((!(((uint32_t)L_114) == ((uint32_t)((int32_t)1102)))))
		{
			goto IL_038a;
		}
	}
	{
		V_37 = (int32_t)((int32_t)1101);
		goto IL_03a3;
	}

IL_038a:
	{
		int32_t L_115 = V_36;
		if ((!(((uint32_t)L_115) == ((uint32_t)((int32_t)1001)))))
		{
			goto IL_03a3;
		}
	}
	{
		int32_t L_116 = V_37;
		if ((((int32_t)L_116) > ((int32_t)((int32_t)1104))))
		{
			goto IL_03a3;
		}
	}
	{
		V_37 = (int32_t)((int32_t)1104);
	}

IL_03a3:
	{
		int32_t L_117 = ___4_data_ptr;
		uint8_t* L_118;
		L_118 = il2cpp_span_get_item((uint8_t*)((Il2CppByReference*)&(((&___3_data))->____pointer))->value, (L_117), ((&___3_data))->____length);
		int32_t L_119 = V_36;
		int32_t L_120 = V_21;
		int32_t L_121 = V_37;
		int32_t L_122 = __this->___stream_channels;
		uint8_t L_123;
		L_123 = CodecHelpers_gen_toc_m55919D0EC27589F5328AD925AA91F8B0D4A9EBA2(L_119, L_120, L_121, L_122, NULL);
		*((int8_t*)L_118) = (int8_t)L_123;
		V_3 = 1;
		int32_t L_124 = __this->___use_vbr;
		if (L_124)
		{
			goto IL_03db;
		}
	}
	{
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_125 = ___3_data;
		int32_t L_126 = ___4_data_ptr;
		int32_t L_127 = V_3;
		int32_t L_128 = V_25;
		int32_t L_129;
		L_129 = OpusRepacketizer_PadPacket_m31BC672C1100238AAE7DF0EEC74000D8CD39AD8E(L_125, L_126, L_127, L_128, NULL);
		V_3 = L_129;
		int32_t L_130 = V_3;
		if (L_130)
		{
			goto IL_03db;
		}
	}
	{
		int32_t L_131 = V_25;
		V_3 = L_131;
	}

IL_03db:
	{
		int32_t L_132 = V_3;
		return L_132;
	}

IL_03dd:
	{
		int32_t L_133 = V_21;
		int32_t L_134 = V_25;
		V_22 = ((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_multiply(L_133, L_134)), 8));
		int32_t L_135 = __this->___bitrate_bps;
		int32_t L_136 = __this->___channels;
		int32_t L_137 = __this->___Fs;
		int32_t L_138 = ___2_frame_size;
		V_19 = ((int32_t)il2cpp_codegen_subtract(L_135, ((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)40), L_136)), ((int32_t)20))), ((int32_t)il2cpp_codegen_subtract(((int32_t)(L_137/L_138)), ((int32_t)50)))))));
		int32_t L_139 = __this->___signal_type;
		if ((!(((uint32_t)L_139) == ((uint32_t)((int32_t)3001)))))
		{
			goto IL_041a;
		}
	}
	{
		V_18 = ((int32_t)127);
		goto IL_0476;
	}

IL_041a:
	{
		int32_t L_140 = __this->___signal_type;
		if ((!(((uint32_t)L_140) == ((uint32_t)((int32_t)3002)))))
		{
			goto IL_042c;
		}
	}
	{
		V_18 = 0;
		goto IL_0476;
	}

IL_042c:
	{
		int32_t L_141 = __this->___voice_ratio;
		if ((((int32_t)L_141) < ((int32_t)0)))
		{
			goto IL_045f;
		}
	}
	{
		int32_t L_142 = __this->___voice_ratio;
		V_18 = ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_142, ((int32_t)327)))>>8));
		int32_t L_143 = __this->___application;
		if ((!(((uint32_t)L_143) == ((uint32_t)((int32_t)2049)))))
		{
			goto IL_0476;
		}
	}
	{
		int32_t L_144 = V_18;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_145;
		L_145 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(L_144, ((int32_t)115), NULL);
		V_18 = L_145;
		goto IL_0476;
	}

IL_045f:
	{
		int32_t L_146 = __this->___application;
		if ((!(((uint32_t)L_146) == ((uint32_t)((int32_t)2048)))))
		{
			goto IL_0472;
		}
	}
	{
		V_18 = ((int32_t)115);
		goto IL_0476;
	}

IL_0472:
	{
		V_18 = ((int32_t)48);
	}

IL_0476:
	{
		int32_t L_147 = __this->___force_channels;
		if ((((int32_t)L_147) == ((int32_t)((int32_t)-1000))))
		{
			goto IL_049a;
		}
	}
	{
		int32_t L_148 = __this->___channels;
		if ((!(((uint32_t)L_148) == ((uint32_t)2))))
		{
			goto IL_049a;
		}
	}
	{
		int32_t L_149 = __this->___force_channels;
		__this->___stream_channels = L_149;
		goto IL_04ec;
	}

IL_049a:
	{
		int32_t L_150 = __this->___channels;
		if ((!(((uint32_t)L_150) == ((uint32_t)2))))
		{
			goto IL_04e0;
		}
	}
	{
		V_38 = ((int32_t)il2cpp_codegen_add(((int32_t)30000), ((int32_t)(0>>((int32_t)14)))));
		int32_t L_151 = __this->___stream_channels;
		if ((!(((uint32_t)L_151) == ((uint32_t)2))))
		{
			goto IL_04c4;
		}
	}
	{
		int32_t L_152 = V_38;
		V_38 = ((int32_t)il2cpp_codegen_subtract(L_152, ((int32_t)1000)));
		goto IL_04ce;
	}

IL_04c4:
	{
		int32_t L_153 = V_38;
		V_38 = ((int32_t)il2cpp_codegen_add(L_153, ((int32_t)1000)));
	}

IL_04ce:
	{
		int32_t L_154 = V_19;
		int32_t L_155 = V_38;
		if ((((int32_t)L_154) > ((int32_t)L_155)))
		{
			G_B84_0 = __this;
			goto IL_04d8;
		}
		G_B83_0 = __this;
	}
	{
		G_B85_0 = 1;
		G_B85_1 = G_B83_0;
		goto IL_04d9;
	}

IL_04d8:
	{
		G_B85_0 = 2;
		G_B85_1 = G_B84_0;
	}

IL_04d9:
	{
		NullCheck(G_B85_1);
		G_B85_1->___stream_channels = G_B85_0;
		goto IL_04ec;
	}

IL_04e0:
	{
		int32_t L_156 = __this->___channels;
		__this->___stream_channels = L_156;
	}

IL_04ec:
	{
		int32_t L_157 = __this->___bitrate_bps;
		int32_t L_158 = __this->___stream_channels;
		int32_t L_159 = __this->___Fs;
		int32_t L_160 = ___2_frame_size;
		V_19 = ((int32_t)il2cpp_codegen_subtract(L_157, ((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)40), L_158)), ((int32_t)20))), ((int32_t)il2cpp_codegen_subtract(((int32_t)(L_159/L_160)), ((int32_t)50)))))));
		int32_t L_161 = __this->___application;
		if ((!(((uint32_t)L_161) == ((uint32_t)((int32_t)2051)))))
		{
			goto IL_052a;
		}
	}
	{
		__this->___mode = (int32_t)((int32_t)1002);
		goto IL_0655;
	}

IL_052a:
	{
		int32_t L_162 = __this->___user_forced_mode;
		if ((!(((uint32_t)L_162) == ((uint32_t)((int32_t)-1000)))))
		{
			goto IL_0649;
		}
	}
	{
		int32_t L_163 = V_27;
		il2cpp_codegen_runtime_class_init_inline(Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var);
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_164 = ((Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_StaticFields*)il2cpp_codegen_static_fields_for(Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var))->___mode_thresholds;
		NullCheck(L_164);
		int32_t L_165 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_166 = (L_164)->GetAt(static_cast<il2cpp_array_size_t>(L_165));
		NullCheck(L_166);
		int32_t L_167 = 0;
		int32_t L_168 = (L_166)->GetAt(static_cast<il2cpp_array_size_t>(L_167));
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_169;
		L_169 = Inlines_MULT16_32_Q15_m26878C33EF631092FEDA6A0054F6B2C0D0B256B2_inline(((int32_t)il2cpp_codegen_subtract(((int32_t)32767), L_163)), L_168, NULL);
		int32_t L_170 = V_27;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_171 = ((Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_StaticFields*)il2cpp_codegen_static_fields_for(Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var))->___mode_thresholds;
		NullCheck(L_171);
		int32_t L_172 = 1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_173 = (L_171)->GetAt(static_cast<il2cpp_array_size_t>(L_172));
		NullCheck(L_173);
		int32_t L_174 = 0;
		int32_t L_175 = (L_173)->GetAt(static_cast<il2cpp_array_size_t>(L_174));
		int32_t L_176;
		L_176 = Inlines_MULT16_32_Q15_m26878C33EF631092FEDA6A0054F6B2C0D0B256B2_inline(L_170, L_175, NULL);
		V_39 = ((int32_t)il2cpp_codegen_add(L_169, L_176));
		int32_t L_177 = V_27;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_178 = ((Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_StaticFields*)il2cpp_codegen_static_fields_for(Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var))->___mode_thresholds;
		NullCheck(L_178);
		int32_t L_179 = 1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_180 = (L_178)->GetAt(static_cast<il2cpp_array_size_t>(L_179));
		NullCheck(L_180);
		int32_t L_181 = 1;
		int32_t L_182 = (L_180)->GetAt(static_cast<il2cpp_array_size_t>(L_181));
		int32_t L_183;
		L_183 = Inlines_MULT16_32_Q15_m26878C33EF631092FEDA6A0054F6B2C0D0B256B2_inline(((int32_t)il2cpp_codegen_subtract(((int32_t)32767), L_177)), L_182, NULL);
		int32_t L_184 = V_27;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_185 = ((Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_StaticFields*)il2cpp_codegen_static_fields_for(Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var))->___mode_thresholds;
		NullCheck(L_185);
		int32_t L_186 = 1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_187 = (L_185)->GetAt(static_cast<il2cpp_array_size_t>(L_186));
		NullCheck(L_187);
		int32_t L_188 = 1;
		int32_t L_189 = (L_187)->GetAt(static_cast<il2cpp_array_size_t>(L_188));
		int32_t L_190;
		L_190 = Inlines_MULT16_32_Q15_m26878C33EF631092FEDA6A0054F6B2C0D0B256B2_inline(L_184, L_189, NULL);
		V_40 = ((int32_t)il2cpp_codegen_add(L_183, L_190));
		int32_t L_191 = V_40;
		int32_t L_192 = V_18;
		int32_t L_193 = V_18;
		int32_t L_194 = V_39;
		int32_t L_195 = V_40;
		V_41 = ((int32_t)il2cpp_codegen_add(L_191, ((int32_t)(((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_multiply(L_192, L_193)), ((int32_t)il2cpp_codegen_subtract(L_194, L_195))))>>((int32_t)14)))));
		int32_t L_196 = __this->___application;
		if ((!(((uint32_t)L_196) == ((uint32_t)((int32_t)2048)))))
		{
			goto IL_05b6;
		}
	}
	{
		int32_t L_197 = V_41;
		V_41 = ((int32_t)il2cpp_codegen_add(L_197, ((int32_t)8000)));
	}

IL_05b6:
	{
		int32_t L_198 = __this->___prev_mode;
		if ((!(((uint32_t)L_198) == ((uint32_t)((int32_t)1002)))))
		{
			goto IL_05cf;
		}
	}
	{
		int32_t L_199 = V_41;
		V_41 = ((int32_t)il2cpp_codegen_subtract(L_199, ((int32_t)4000)));
		goto IL_05e2;
	}

IL_05cf:
	{
		int32_t L_200 = __this->___prev_mode;
		if ((((int32_t)L_200) <= ((int32_t)0)))
		{
			goto IL_05e2;
		}
	}
	{
		int32_t L_201 = V_41;
		V_41 = ((int32_t)il2cpp_codegen_add(L_201, ((int32_t)4000)));
	}

IL_05e2:
	{
		int32_t L_202 = V_19;
		int32_t L_203 = V_41;
		if ((((int32_t)L_202) >= ((int32_t)L_203)))
		{
			G_B98_0 = __this;
			goto IL_05f0;
		}
		G_B97_0 = __this;
	}
	{
		G_B99_0 = ((int32_t)1000);
		G_B99_1 = G_B97_0;
		goto IL_05f5;
	}

IL_05f0:
	{
		G_B99_0 = ((int32_t)1002);
		G_B99_1 = G_B98_0;
	}

IL_05f5:
	{
		NullCheck(G_B99_1);
		G_B99_1->___mode = (int32_t)G_B99_0;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_204 = __this->___silk_mode;
		NullCheck(L_204);
		int32_t L_205 = L_204->___useInBandFEC;
		if (!L_205)
		{
			goto IL_0629;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_206 = __this->___silk_mode;
		NullCheck(L_206);
		int32_t L_207 = L_206->___packetLossPercentage;
		int32_t L_208 = V_18;
		if ((((int32_t)L_207) <= ((int32_t)((int32_t)(((int32_t)il2cpp_codegen_subtract(((int32_t)128), L_208))>>4)))))
		{
			goto IL_0629;
		}
	}
	{
		__this->___mode = (int32_t)((int32_t)1000);
	}

IL_0629:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_209 = __this->___silk_mode;
		NullCheck(L_209);
		int32_t L_210 = L_209->___useDTX;
		if (!L_210)
		{
			goto IL_0655;
		}
	}
	{
		int32_t L_211 = V_18;
		if ((((int32_t)L_211) <= ((int32_t)((int32_t)100))))
		{
			goto IL_0655;
		}
	}
	{
		__this->___mode = (int32_t)((int32_t)1000);
		goto IL_0655;
	}

IL_0649:
	{
		int32_t L_212 = __this->___user_forced_mode;
		__this->___mode = L_212;
	}

IL_0655:
	{
		int32_t L_213 = __this->___mode;
		if ((((int32_t)L_213) == ((int32_t)((int32_t)1002))))
		{
			goto IL_0679;
		}
	}
	{
		int32_t L_214 = ___2_frame_size;
		int32_t L_215 = __this->___Fs;
		if ((((int32_t)L_214) >= ((int32_t)((int32_t)(L_215/((int32_t)100))))))
		{
			goto IL_0679;
		}
	}
	{
		__this->___mode = (int32_t)((int32_t)1002);
	}

IL_0679:
	{
		int32_t L_216 = __this->___lfe;
		if (!L_216)
		{
			goto IL_068c;
		}
	}
	{
		__this->___mode = (int32_t)((int32_t)1002);
	}

IL_068c:
	{
		int32_t L_217 = V_25;
		int32_t L_218 = V_21;
		if ((((int32_t)L_218) > ((int32_t)((int32_t)50))))
		{
			G_B113_0 = L_217;
			goto IL_069b;
		}
		G_B112_0 = L_217;
	}
	{
		G_B114_0 = ((int32_t)8000);
		G_B114_1 = G_B112_0;
		goto IL_06a0;
	}

IL_069b:
	{
		G_B114_0 = ((int32_t)12000);
		G_B114_1 = G_B113_0;
	}

IL_06a0:
	{
		int32_t L_219 = ___2_frame_size;
		int32_t L_220 = __this->___Fs;
		if ((((int32_t)G_B114_1) >= ((int32_t)((int32_t)(((int32_t)il2cpp_codegen_multiply(G_B114_0, L_219))/((int32_t)il2cpp_codegen_multiply(L_220, 8)))))))
		{
			goto IL_06b8;
		}
	}
	{
		__this->___mode = (int32_t)((int32_t)1002);
	}

IL_06b8:
	{
		int32_t L_221 = __this->___stream_channels;
		if ((!(((uint32_t)L_221) == ((uint32_t)1))))
		{
			goto IL_0706;
		}
	}
	{
		int32_t L_222 = __this->___prev_channels;
		if ((!(((uint32_t)L_222) == ((uint32_t)2))))
		{
			goto IL_0706;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_223 = __this->___silk_mode;
		NullCheck(L_223);
		int32_t L_224 = L_223->___toMono;
		if (L_224)
		{
			goto IL_0706;
		}
	}
	{
		int32_t L_225 = __this->___mode;
		if ((((int32_t)L_225) == ((int32_t)((int32_t)1002))))
		{
			goto IL_0706;
		}
	}
	{
		int32_t L_226 = __this->___prev_mode;
		if ((((int32_t)L_226) == ((int32_t)((int32_t)1002))))
		{
			goto IL_0706;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_227 = __this->___silk_mode;
		NullCheck(L_227);
		L_227->___toMono = 1;
		__this->___stream_channels = 2;
		goto IL_0712;
	}

IL_0706:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_228 = __this->___silk_mode;
		NullCheck(L_228);
		L_228->___toMono = 0;
	}

IL_0712:
	{
		int32_t L_229 = __this->___prev_mode;
		if ((((int32_t)L_229) <= ((int32_t)0)))
		{
			goto IL_0789;
		}
	}
	{
		int32_t L_230 = __this->___mode;
		if ((((int32_t)L_230) == ((int32_t)((int32_t)1002))))
		{
			goto IL_0735;
		}
	}
	{
		int32_t L_231 = __this->___prev_mode;
		if ((((int32_t)L_231) == ((int32_t)((int32_t)1002))))
		{
			goto IL_074f;
		}
	}

IL_0735:
	{
		int32_t L_232 = __this->___mode;
		if ((!(((uint32_t)L_232) == ((uint32_t)((int32_t)1002)))))
		{
			goto IL_0789;
		}
	}
	{
		int32_t L_233 = __this->___prev_mode;
		if ((((int32_t)L_233) == ((int32_t)((int32_t)1002))))
		{
			goto IL_0789;
		}
	}

IL_074f:
	{
		V_9 = 1;
		int32_t L_234 = __this->___mode;
		if ((!(((uint32_t)L_234) == ((uint32_t)((int32_t)1002)))))
		{
			goto IL_0762;
		}
	}
	{
		G_B131_0 = 0;
		goto IL_0763;
	}

IL_0762:
	{
		G_B131_0 = 1;
	}

IL_0763:
	{
		V_11 = G_B131_0;
		int32_t L_235 = V_11;
		if (L_235)
		{
			goto IL_0789;
		}
	}
	{
		int32_t L_236 = ___2_frame_size;
		int32_t L_237 = __this->___Fs;
		if ((((int32_t)L_236) < ((int32_t)((int32_t)(L_237/((int32_t)100))))))
		{
			goto IL_0786;
		}
	}
	{
		int32_t L_238 = __this->___prev_mode;
		__this->___mode = L_238;
		V_14 = 1;
		goto IL_0789;
	}

IL_0786:
	{
		V_9 = 0;
	}

IL_0789:
	{
		int32_t L_239 = __this->___silk_bw_switch;
		if (!L_239)
		{
			goto IL_07a1;
		}
	}
	{
		V_9 = 1;
		V_11 = 1;
		__this->___silk_bw_switch = 0;
		V_7 = 1;
	}

IL_07a1:
	{
		int32_t L_240 = V_9;
		if (!L_240)
		{
			goto IL_07ec;
		}
	}
	{
		int32_t L_241 = V_25;
		int32_t L_242 = __this->___Fs;
		int32_t L_243 = ___2_frame_size;
		int32_t L_244 = __this->___Fs;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_245;
		L_245 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)257), ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_241, ((int32_t)(L_242/((int32_t)200)))))/((int32_t)il2cpp_codegen_add(L_243, ((int32_t)(L_244/((int32_t)200))))))), NULL);
		V_10 = L_245;
		int32_t L_246 = __this->___use_vbr;
		if (!L_246)
		{
			goto IL_07ec;
		}
	}
	{
		int32_t L_247 = V_10;
		int32_t L_248 = __this->___bitrate_bps;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_249;
		L_249 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(L_247, ((int32_t)(L_248/((int32_t)1600))), NULL);
		V_10 = L_249;
	}

IL_07ec:
	{
		int32_t L_250 = __this->___mode;
		if ((((int32_t)L_250) == ((int32_t)((int32_t)1002))))
		{
			goto IL_0819;
		}
	}
	{
		int32_t L_251 = __this->___prev_mode;
		if ((!(((uint32_t)L_251) == ((uint32_t)((int32_t)1002)))))
		{
			goto IL_0819;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_252 = (EncControlState_t1F753CF3968665C2171A288F862D70168F348019*)il2cpp_codegen_object_new(EncControlState_t1F753CF3968665C2171A288F862D70168F348019_il2cpp_TypeInfo_var);
		EncControlState__ctor_mCAD689C6947CC4E7B25982B1948387269E41363C(L_252, NULL);
		V_42 = L_252;
		SilkEncoder_t7AB5C2F712CDB92EBFCDAF8E9743C5A39B7CFD6D* L_253 = V_0;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_254 = V_42;
		int32_t L_255;
		L_255 = EncodeAPI_silk_InitEncoder_m09EF9258259F34A9CE9707CB9463B3CA9C3D4B42(L_253, L_254, NULL);
		V_7 = 1;
	}

IL_0819:
	{
		int32_t L_256 = __this->___mode;
		if ((((int32_t)L_256) == ((int32_t)((int32_t)1002))))
		{
			goto IL_083e;
		}
	}
	{
		int32_t L_257 = __this->___first;
		if (L_257)
		{
			goto IL_083e;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_258 = __this->___silk_mode;
		NullCheck(L_258);
		int32_t L_259 = L_258->___allowBandwidthSwitch;
		if (!L_259)
		{
			goto IL_0975;
		}
	}

IL_083e:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_260 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)8);
		V_45 = L_260;
		V_46 = (int32_t)((int32_t)1105);
		int32_t L_261 = V_19;
		V_47 = L_261;
		int32_t L_262 = __this->___mode;
		if ((((int32_t)L_262) == ((int32_t)((int32_t)1002))))
		{
			goto IL_0886;
		}
	}
	{
		int32_t L_263 = V_47;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_264 = __this->___silk_mode;
		NullCheck(L_264);
		int32_t L_265 = L_264->___complexity;
		V_47 = ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_263, ((int32_t)il2cpp_codegen_add(((int32_t)45), L_265))))/((int32_t)50)));
		int32_t L_266 = __this->___use_vbr;
		if (L_266)
		{
			goto IL_0886;
		}
	}
	{
		int32_t L_267 = V_47;
		V_47 = ((int32_t)il2cpp_codegen_subtract(L_267, ((int32_t)1000)));
	}

IL_0886:
	{
		int32_t L_268 = __this->___channels;
		if ((!(((uint32_t)L_268) == ((uint32_t)2))))
		{
			goto IL_08a8;
		}
	}
	{
		int32_t L_269 = __this->___force_channels;
		if ((((int32_t)L_269) == ((int32_t)1)))
		{
			goto IL_08a8;
		}
	}
	{
		il2cpp_codegen_runtime_class_init_inline(Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_270 = ((Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_StaticFields*)il2cpp_codegen_static_fields_for(Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var))->___stereo_voice_bandwidth_thresholds;
		V_43 = L_270;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_271 = ((Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_StaticFields*)il2cpp_codegen_static_fields_for(Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var))->___stereo_music_bandwidth_thresholds;
		V_44 = L_271;
		goto IL_08b6;
	}

IL_08a8:
	{
		il2cpp_codegen_runtime_class_init_inline(Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_272 = ((Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_StaticFields*)il2cpp_codegen_static_fields_for(Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var))->___mono_voice_bandwidth_thresholds;
		V_43 = L_272;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_273 = ((Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_StaticFields*)il2cpp_codegen_static_fields_for(Tables_t8F9681F0651C092F856E5CF5EBE2BA800B384199_il2cpp_TypeInfo_var))->___mono_music_bandwidth_thresholds;
		V_44 = L_273;
	}

IL_08b6:
	{
		V_2 = 0;
		goto IL_08d9;
	}

IL_08ba:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_274 = V_45;
		int32_t L_275 = V_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_276 = V_44;
		int32_t L_277 = V_2;
		NullCheck(L_276);
		int32_t L_278 = L_277;
		int32_t L_279 = (L_276)->GetAt(static_cast<il2cpp_array_size_t>(L_278));
		int32_t L_280 = V_18;
		int32_t L_281 = V_18;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_282 = V_43;
		int32_t L_283 = V_2;
		NullCheck(L_282);
		int32_t L_284 = L_283;
		int32_t L_285 = (L_282)->GetAt(static_cast<il2cpp_array_size_t>(L_284));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_286 = V_44;
		int32_t L_287 = V_2;
		NullCheck(L_286);
		int32_t L_288 = L_287;
		int32_t L_289 = (L_286)->GetAt(static_cast<il2cpp_array_size_t>(L_288));
		NullCheck(L_274);
		(L_274)->SetAt(static_cast<il2cpp_array_size_t>(L_275), (int32_t)((int32_t)il2cpp_codegen_add(L_279, ((int32_t)(((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_multiply(L_280, L_281)), ((int32_t)il2cpp_codegen_subtract(L_285, L_289))))>>((int32_t)14))))));
		int32_t L_290 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_290, 1));
	}

IL_08d9:
	{
		int32_t L_291 = V_2;
		if ((((int32_t)L_291) < ((int32_t)8)))
		{
			goto IL_08ba;
		}
	}

IL_08dd:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_292 = V_45;
		int32_t L_293 = V_46;
		NullCheck(L_292);
		int32_t L_294 = ((int32_t)il2cpp_codegen_multiply(2, ((int32_t)il2cpp_codegen_subtract((int32_t)L_293, ((int32_t)1102)))));
		int32_t L_295 = (L_292)->GetAt(static_cast<il2cpp_array_size_t>(L_294));
		V_48 = L_295;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_296 = V_45;
		int32_t L_297 = V_46;
		NullCheck(L_296);
		int32_t L_298 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(2, ((int32_t)il2cpp_codegen_subtract((int32_t)L_297, ((int32_t)1102))))), 1));
		int32_t L_299 = (L_296)->GetAt(static_cast<il2cpp_array_size_t>(L_298));
		V_49 = L_299;
		int32_t L_300 = __this->___first;
		if (L_300)
		{
			goto IL_091f;
		}
	}
	{
		int32_t L_301 = __this->___bandwidth;
		int32_t L_302 = V_46;
		if ((((int32_t)L_301) < ((int32_t)L_302)))
		{
			goto IL_0918;
		}
	}
	{
		int32_t L_303 = V_48;
		int32_t L_304 = V_49;
		V_48 = ((int32_t)il2cpp_codegen_subtract(L_303, L_304));
		goto IL_091f;
	}

IL_0918:
	{
		int32_t L_305 = V_48;
		int32_t L_306 = V_49;
		V_48 = ((int32_t)il2cpp_codegen_add(L_305, L_306));
	}

IL_091f:
	{
		int32_t L_307 = V_47;
		int32_t L_308 = V_48;
		if ((((int32_t)L_307) >= ((int32_t)L_308)))
		{
			goto IL_0933;
		}
	}
	{
		int32_t L_309 = V_46;
		int32_t L_310 = ((int32_t)il2cpp_codegen_subtract((int32_t)L_309, 1));
		V_46 = (int32_t)L_310;
		if ((((int32_t)L_310) > ((int32_t)((int32_t)1101))))
		{
			goto IL_08dd;
		}
	}

IL_0933:
	{
		int32_t L_311 = V_46;
		__this->___bandwidth = L_311;
		int32_t L_312 = __this->___first;
		if (L_312)
		{
			goto IL_0975;
		}
	}
	{
		int32_t L_313 = __this->___mode;
		if ((((int32_t)L_313) == ((int32_t)((int32_t)1002))))
		{
			goto IL_0975;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_314 = __this->___silk_mode;
		NullCheck(L_314);
		int32_t L_315 = L_314->___inWBmodeWithoutVariableLP;
		if (L_315)
		{
			goto IL_0975;
		}
	}
	{
		int32_t L_316 = __this->___bandwidth;
		if ((((int32_t)L_316) <= ((int32_t)((int32_t)1103))))
		{
			goto IL_0975;
		}
	}
	{
		__this->___bandwidth = (int32_t)((int32_t)1103);
	}

IL_0975:
	{
		int32_t L_317 = __this->___bandwidth;
		int32_t L_318 = __this->___max_bandwidth;
		if ((((int32_t)L_317) <= ((int32_t)L_318)))
		{
			goto IL_098f;
		}
	}
	{
		int32_t L_319 = __this->___max_bandwidth;
		__this->___bandwidth = L_319;
	}

IL_098f:
	{
		int32_t L_320 = __this->___user_bandwidth;
		if ((((int32_t)L_320) == ((int32_t)((int32_t)-1000))))
		{
			goto IL_09a8;
		}
	}
	{
		int32_t L_321 = __this->___user_bandwidth;
		__this->___bandwidth = L_321;
	}

IL_09a8:
	{
		int32_t L_322 = __this->___mode;
		if ((((int32_t)L_322) == ((int32_t)((int32_t)1002))))
		{
			goto IL_09d4;
		}
	}
	{
		int32_t L_323 = V_22;
		if ((((int32_t)L_323) >= ((int32_t)((int32_t)15000))))
		{
			goto IL_09d4;
		}
	}
	{
		int32_t L_324 = __this->___bandwidth;
		int32_t L_325;
		L_325 = OpusBandwidthHelpers_MIN_m35CCCD819EE4224365BF648B953A8ADC347EA987(L_324, (int32_t)((int32_t)1103), NULL);
		__this->___bandwidth = L_325;
	}

IL_09d4:
	{
		int32_t L_326 = __this->___Fs;
		if ((((int32_t)L_326) > ((int32_t)((int32_t)24000))))
		{
			goto IL_09f9;
		}
	}
	{
		int32_t L_327 = __this->___bandwidth;
		if ((((int32_t)L_327) <= ((int32_t)((int32_t)1104))))
		{
			goto IL_09f9;
		}
	}
	{
		__this->___bandwidth = (int32_t)((int32_t)1104);
	}

IL_09f9:
	{
		int32_t L_328 = __this->___Fs;
		if ((((int32_t)L_328) > ((int32_t)((int32_t)16000))))
		{
			goto IL_0a1e;
		}
	}
	{
		int32_t L_329 = __this->___bandwidth;
		if ((((int32_t)L_329) <= ((int32_t)((int32_t)1103))))
		{
			goto IL_0a1e;
		}
	}
	{
		__this->___bandwidth = (int32_t)((int32_t)1103);
	}

IL_0a1e:
	{
		int32_t L_330 = __this->___Fs;
		if ((((int32_t)L_330) > ((int32_t)((int32_t)12000))))
		{
			goto IL_0a43;
		}
	}
	{
		int32_t L_331 = __this->___bandwidth;
		if ((((int32_t)L_331) <= ((int32_t)((int32_t)1102))))
		{
			goto IL_0a43;
		}
	}
	{
		__this->___bandwidth = (int32_t)((int32_t)1102);
	}

IL_0a43:
	{
		int32_t L_332 = __this->___Fs;
		if ((((int32_t)L_332) > ((int32_t)((int32_t)8000))))
		{
			goto IL_0a68;
		}
	}
	{
		int32_t L_333 = __this->___bandwidth;
		if ((((int32_t)L_333) <= ((int32_t)((int32_t)1101))))
		{
			goto IL_0a68;
		}
	}
	{
		__this->___bandwidth = (int32_t)((int32_t)1101);
	}

IL_0a68:
	{
		int32_t L_334 = __this->___detected_bandwidth;
		if (!L_334)
		{
			goto IL_0b32;
		}
	}
	{
		int32_t L_335 = __this->___user_bandwidth;
		if ((!(((uint32_t)L_335) == ((uint32_t)((int32_t)-1000)))))
		{
			goto IL_0b32;
		}
	}
	{
		int32_t L_336 = V_19;
		int32_t L_337 = __this->___stream_channels;
		if ((((int32_t)L_336) > ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)18000), L_337)))))
		{
			goto IL_0aa9;
		}
	}
	{
		int32_t L_338 = __this->___mode;
		if ((!(((uint32_t)L_338) == ((uint32_t)((int32_t)1002)))))
		{
			goto IL_0aa9;
		}
	}
	{
		V_50 = (int32_t)((int32_t)1101);
		goto IL_0b08;
	}

IL_0aa9:
	{
		int32_t L_339 = V_19;
		int32_t L_340 = __this->___stream_channels;
		if ((((int32_t)L_339) > ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)24000), L_340)))))
		{
			goto IL_0acf;
		}
	}
	{
		int32_t L_341 = __this->___mode;
		if ((!(((uint32_t)L_341) == ((uint32_t)((int32_t)1002)))))
		{
			goto IL_0acf;
		}
	}
	{
		V_50 = (int32_t)((int32_t)1102);
		goto IL_0b08;
	}

IL_0acf:
	{
		int32_t L_342 = V_19;
		int32_t L_343 = __this->___stream_channels;
		if ((((int32_t)L_342) > ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)30000), L_343)))))
		{
			goto IL_0ae8;
		}
	}
	{
		V_50 = (int32_t)((int32_t)1103);
		goto IL_0b08;
	}

IL_0ae8:
	{
		int32_t L_344 = V_19;
		int32_t L_345 = __this->___stream_channels;
		if ((((int32_t)L_344) > ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)44000), L_345)))))
		{
			goto IL_0b01;
		}
	}
	{
		V_50 = (int32_t)((int32_t)1104);
		goto IL_0b08;
	}

IL_0b01:
	{
		V_50 = (int32_t)((int32_t)1105);
	}

IL_0b08:
	{
		int32_t L_346 = __this->___detected_bandwidth;
		int32_t L_347 = V_50;
		int32_t L_348;
		L_348 = OpusBandwidthHelpers_MAX_mF31797F605DA051DD3FB61542A8C376114316B83(L_346, L_347, NULL);
		__this->___detected_bandwidth = L_348;
		int32_t L_349 = __this->___bandwidth;
		int32_t L_350 = __this->___detected_bandwidth;
		int32_t L_351;
		L_351 = OpusBandwidthHelpers_MIN_m35CCCD819EE4224365BF648B953A8ADC347EA987(L_349, L_350, NULL);
		__this->___bandwidth = L_351;
	}

IL_0b32:
	{
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_352 = V_1;
		int32_t L_353 = ___6_lsb_depth;
		NullCheck(L_352);
		CeltEncoder_SetLSBDepth_mB8EDAF4F6B3646DDDFCA55BB31B350F8CAACCEE9(L_352, L_353, NULL);
		int32_t L_354 = __this->___mode;
		if ((!(((uint32_t)L_354) == ((uint32_t)((int32_t)1002)))))
		{
			goto IL_0b5f;
		}
	}
	{
		int32_t L_355 = __this->___bandwidth;
		if ((!(((uint32_t)L_355) == ((uint32_t)((int32_t)1102)))))
		{
			goto IL_0b5f;
		}
	}
	{
		__this->___bandwidth = (int32_t)((int32_t)1103);
	}

IL_0b5f:
	{
		int32_t L_356 = __this->___lfe;
		if (!L_356)
		{
			goto IL_0b72;
		}
	}
	{
		__this->___bandwidth = (int32_t)((int32_t)1101);
	}

IL_0b72:
	{
		int32_t L_357 = ___2_frame_size;
		int32_t L_358 = __this->___Fs;
		if ((((int32_t)L_357) <= ((int32_t)((int32_t)(L_358/((int32_t)50))))))
		{
			goto IL_0d77;
		}
	}
	{
		int32_t L_359 = __this->___mode;
		if ((((int32_t)L_359) == ((int32_t)((int32_t)1002))))
		{
			goto IL_0b9e;
		}
	}
	{
		int32_t L_360 = __this->___bandwidth;
		if ((((int32_t)L_360) <= ((int32_t)((int32_t)1103))))
		{
			goto IL_0d77;
		}
	}

IL_0b9e:
	{
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_361 = __this->___analysis;
		NullCheck(L_361);
		bool L_362 = L_361->___enabled;
		if (!L_362)
		{
			goto IL_0bca;
		}
	}
	{
		int32_t L_363 = V_30;
		if ((((int32_t)L_363) == ((int32_t)(-1))))
		{
			goto IL_0bca;
		}
	}
	{
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_364 = __this->___analysis;
		int32_t L_365 = V_30;
		NullCheck(L_364);
		L_364->___read_pos = L_365;
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_366 = __this->___analysis;
		int32_t L_367 = V_31;
		NullCheck(L_366);
		L_366->___read_subframe = L_367;
	}

IL_0bca:
	{
		int32_t L_368 = ___2_frame_size;
		int32_t L_369 = __this->___Fs;
		if ((((int32_t)L_368) > ((int32_t)((int32_t)(L_369/((int32_t)25))))))
		{
			goto IL_0bd9;
		}
	}
	{
		G_B214_0 = 2;
		goto IL_0bda;
	}

IL_0bd9:
	{
		G_B214_0 = 3;
	}

IL_0bda:
	{
		V_52 = G_B214_0;
		int32_t L_370 = ___5_out_data_bytes;
		int32_t L_371 = V_52;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_372;
		L_372 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)1276), ((int32_t)(((int32_t)il2cpp_codegen_subtract(L_370, 3))/L_371)), NULL);
		V_58 = L_372;
		int32_t L_373 = V_52;
		int32_t L_374 = V_58;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_375 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(L_373, L_374)));
		V_51 = L_375;
		OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* L_376 = (OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0*)il2cpp_codegen_object_new(OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0_il2cpp_TypeInfo_var);
		OpusRepacketizer__ctor_mC4456456D2AAD30181CA3EC5FF721E31477B6996(L_376, NULL);
		V_57 = L_376;
		int32_t L_377 = __this->___user_forced_mode;
		V_56 = L_377;
		int32_t L_378 = __this->___user_bandwidth;
		V_53 = L_378;
		int32_t L_379 = __this->___force_channels;
		V_54 = L_379;
		int32_t L_380 = __this->___mode;
		__this->___user_forced_mode = L_380;
		int32_t L_381 = __this->___bandwidth;
		__this->___user_bandwidth = L_381;
		int32_t L_382 = __this->___stream_channels;
		__this->___force_channels = L_382;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_383 = __this->___silk_mode;
		NullCheck(L_383);
		int32_t L_384 = L_383->___toMono;
		V_55 = L_384;
		int32_t L_385 = V_55;
		if (!L_385)
		{
			goto IL_0c58;
		}
	}
	{
		__this->___force_channels = 1;
		goto IL_0c64;
	}

IL_0c58:
	{
		int32_t L_386 = __this->___stream_channels;
		__this->___prev_channels = L_386;
	}

IL_0c64:
	{
		V_2 = 0;
		goto IL_0cfb;
	}

IL_0c6b:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_387 = __this->___silk_mode;
		NullCheck(L_387);
		L_387->___toMono = 0;
		int32_t L_388 = V_14;
		if (!L_388)
		{
			goto IL_0c8d;
		}
	}
	{
		int32_t L_389 = V_2;
		int32_t L_390 = V_52;
		if ((!(((uint32_t)L_389) == ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_390, 1))))))
		{
			goto IL_0c8d;
		}
	}
	{
		__this->___user_forced_mode = (int32_t)((int32_t)1002);
	}

IL_0c8d:
	{
		ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 L_391 = ___0_pcm;
		int32_t L_392 = ___1_pcm_ptr;
		int32_t L_393 = V_2;
		int32_t L_394 = __this->___channels;
		int32_t L_395 = __this->___Fs;
		int32_t L_396 = __this->___Fs;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_397 = V_51;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_398;
		L_398 = Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91(L_397, Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91_RuntimeMethod_var);
		int32_t L_399 = V_2;
		int32_t L_400 = V_58;
		int32_t L_401 = V_58;
		int32_t L_402 = ___6_lsb_depth;
		ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC L_403;
		L_403 = ((  ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC (*) (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))((__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)NULL, il2cpp_rgctx_method(method->rgctx_data, 3));
		int32_t L_404 = ___9_c1;
		int32_t L_405 = ___10_c2;
		int32_t L_406 = ___11_analysis_channels;
		downmix_func_1_t2D72777593561EEC6CFDD92FFD20BF708F537039* L_407 = ___12_downmix;
		int32_t L_408 = ___13_float_api;
		int32_t L_409;
		L_409 = ((  int32_t (*) (OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44*, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71, int32_t, int32_t, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305, int32_t, int32_t, int32_t, ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC, int32_t, int32_t, int32_t, int32_t, downmix_func_1_t2D72777593561EEC6CFDD92FFD20BF708F537039*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 6)))(__this, L_391, ((int32_t)il2cpp_codegen_add(L_392, ((int32_t)il2cpp_codegen_multiply(L_393, ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_394, L_395))/((int32_t)50))))))), ((int32_t)(L_396/((int32_t)50))), L_398, ((int32_t)il2cpp_codegen_multiply(L_399, L_400)), L_401, L_402, L_403, 0, L_404, L_405, L_406, L_407, L_408, il2cpp_rgctx_method(method->rgctx_data, 6));
		V_60 = L_409;
		int32_t L_410 = V_60;
		if ((((int32_t)L_410) >= ((int32_t)0)))
		{
			goto IL_0cdb;
		}
	}
	{
		return ((int32_t)-3);
	}

IL_0cdb:
	{
		OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* L_411 = V_57;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_412 = V_51;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_413;
		L_413 = Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91(L_412, Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91_RuntimeMethod_var);
		int32_t L_414 = V_2;
		int32_t L_415 = V_58;
		int32_t L_416 = V_60;
		NullCheck(L_411);
		int32_t L_417;
		L_417 = OpusRepacketizer_AddPacket_mEF0C260D9D7AF7EE2243A598509FBE6197D0F510(L_411, L_413, ((int32_t)il2cpp_codegen_multiply(L_414, L_415)), L_416, NULL);
		V_3 = L_417;
		int32_t L_418 = V_3;
		if ((((int32_t)L_418) >= ((int32_t)0)))
		{
			goto IL_0cf7;
		}
	}
	{
		return ((int32_t)-3);
	}

IL_0cf7:
	{
		int32_t L_419 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_419, 1));
	}

IL_0cfb:
	{
		int32_t L_420 = V_2;
		int32_t L_421 = V_52;
		if ((((int32_t)L_420) < ((int32_t)L_421)))
		{
			goto IL_0c6b;
		}
	}
	{
		int32_t L_422 = __this->___use_vbr;
		if (!L_422)
		{
			goto IL_0d11;
		}
	}
	{
		int32_t L_423 = ___5_out_data_bytes;
		V_59 = L_423;
		goto IL_0d2b;
	}

IL_0d11:
	{
		int32_t L_424 = __this->___bitrate_bps;
		int32_t L_425 = V_52;
		int32_t L_426 = ___5_out_data_bytes;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_427;
		L_427 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)(((int32_t)il2cpp_codegen_multiply(3, L_424))/((int32_t)(((int32_t)1200)/L_425)))), L_426, NULL);
		V_59 = L_427;
	}

IL_0d2b:
	{
		OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* L_428 = V_57;
		int32_t L_429 = V_52;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_430 = ___3_data;
		int32_t L_431 = ___4_data_ptr;
		int32_t L_432 = V_59;
		int32_t L_433 = __this->___use_vbr;
		if (!L_433)
		{
			G_B232_0 = 0;
			G_B232_1 = L_432;
			G_B232_2 = L_431;
			G_B232_3 = L_430;
			G_B232_4 = L_429;
			G_B232_5 = 0;
			G_B232_6 = L_428;
			goto IL_0d42;
		}
		G_B231_0 = 0;
		G_B231_1 = L_432;
		G_B231_2 = L_431;
		G_B231_3 = L_430;
		G_B231_4 = L_429;
		G_B231_5 = 0;
		G_B231_6 = L_428;
	}
	{
		G_B233_0 = 0;
		G_B233_1 = G_B231_0;
		G_B233_2 = G_B231_1;
		G_B233_3 = G_B231_2;
		G_B233_4 = G_B231_3;
		G_B233_5 = G_B231_4;
		G_B233_6 = G_B231_5;
		G_B233_7 = G_B231_6;
		goto IL_0d43;
	}

IL_0d42:
	{
		G_B233_0 = 1;
		G_B233_1 = G_B232_0;
		G_B233_2 = G_B232_1;
		G_B233_3 = G_B232_2;
		G_B233_4 = G_B232_3;
		G_B233_5 = G_B232_4;
		G_B233_6 = G_B232_5;
		G_B233_7 = G_B232_6;
	}

IL_0d43:
	{
		NullCheck(G_B233_7);
		int32_t L_434;
		L_434 = OpusRepacketizer_opus_repacketizer_out_range_impl_m580835FE0C1A5F8831B645CF5488B8ED9E443F13(G_B233_7, G_B233_6, G_B233_5, G_B233_4, G_B233_3, G_B233_2, G_B233_1, G_B233_0, NULL);
		V_3 = L_434;
		int32_t L_435 = V_3;
		if ((((int32_t)L_435) >= ((int32_t)0)))
		{
			goto IL_0d50;
		}
	}
	{
		return ((int32_t)-3);
	}

IL_0d50:
	{
		int32_t L_436 = V_56;
		__this->___user_forced_mode = L_436;
		int32_t L_437 = V_53;
		__this->___user_bandwidth = L_437;
		int32_t L_438 = V_54;
		__this->___force_channels = L_438;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_439 = __this->___silk_mode;
		int32_t L_440 = V_55;
		NullCheck(L_439);
		L_439->___toMono = L_440;
		int32_t L_441 = V_3;
		return L_441;
	}

IL_0d77:
	{
		int32_t L_442 = __this->___bandwidth;
		V_23 = L_442;
		int32_t L_443 = __this->___mode;
		if ((!(((uint32_t)L_443) == ((uint32_t)((int32_t)1000)))))
		{
			goto IL_0da0;
		}
	}
	{
		int32_t L_444 = V_23;
		if ((((int32_t)L_444) <= ((int32_t)((int32_t)1103))))
		{
			goto IL_0da0;
		}
	}
	{
		__this->___mode = (int32_t)((int32_t)1001);
	}

IL_0da0:
	{
		int32_t L_445 = __this->___mode;
		if ((!(((uint32_t)L_445) == ((uint32_t)((int32_t)1001)))))
		{
			goto IL_0dc1;
		}
	}
	{
		int32_t L_446 = V_23;
		if ((((int32_t)L_446) > ((int32_t)((int32_t)1103))))
		{
			goto IL_0dc1;
		}
	}
	{
		__this->___mode = (int32_t)((int32_t)1000);
	}

IL_0dc1:
	{
		int32_t L_447 = V_25;
		int32_t L_448 = V_10;
		int32_t L_449 = __this->___bitrate_bps;
		int32_t L_450 = ___2_frame_size;
		int32_t L_451 = __this->___Fs;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_452;
		L_452 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)il2cpp_codegen_subtract(L_447, L_448)), ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_449, L_450))/((int32_t)il2cpp_codegen_multiply(L_451, 8)))), NULL);
		V_6 = ((int32_t)il2cpp_codegen_subtract(L_452, 1));
		int32_t L_453 = ___4_data_ptr;
		___4_data_ptr = ((int32_t)il2cpp_codegen_add(L_453, 1));
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_454 = V_5;
		int32_t L_455 = V_25;
		NullCheck(L_454);
		EntropyCoder_enc_init_m0C80505BF71E0CAF14DAF6DCD1E2FA384F3B2C1D(L_454, (uint32_t)((int32_t)il2cpp_codegen_subtract(L_455, 1)), NULL);
		int32_t L_456 = V_26;
		int32_t L_457 = ___2_frame_size;
		int32_t L_458 = __this->___channels;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_459 = (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)SZArrayNew(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_add(L_456, L_457)), L_458)));
		V_12 = L_459;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_460 = __this->___delay_buffer;
		int32_t L_461 = __this->___encoder_buffer;
		int32_t L_462 = V_26;
		int32_t L_463 = __this->___channels;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_464 = V_12;
		int32_t L_465 = V_26;
		int32_t L_466 = __this->___channels;
		Arrays_MemCopy_m6694E7C365EE590A29753D43699215FBC8162E89(L_460, ((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_subtract(L_461, L_462)), L_463)), L_464, 0, ((int32_t)il2cpp_codegen_multiply(L_465, L_466)), NULL);
		int32_t L_467 = __this->___mode;
		if ((!(((uint32_t)L_467) == ((uint32_t)((int32_t)1002)))))
		{
			goto IL_0e48;
		}
	}
	{
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_468;
		L_468 = Inlines_silk_lin2log_m3D1BBF1C15B7B47836676F7D48D1DB73DF4B887C_inline(((int32_t)60), NULL);
		int32_t L_469;
		L_469 = Inlines_silk_LSHIFT_mE90E3163A0D3526D05046763E167F2271AB0B953_inline(L_468, 8, NULL);
		V_17 = L_469;
		goto IL_0e57;
	}

IL_0e48:
	{
		SilkEncoder_t7AB5C2F712CDB92EBFCDAF8E9743C5A39B7CFD6D* L_470 = V_0;
		NullCheck(L_470);
		SilkChannelEncoderU5BU5D_tBA29067A90CFA762728A1D297853F3661ADD6CA8* L_471 = L_470->___state_Fxx;
		NullCheck(L_471);
		int32_t L_472 = 0;
		SilkChannelEncoder_t9D54D1C6FC4B873E9CE81F196A0ACBA6C2A5C4E3* L_473 = (L_471)->GetAt(static_cast<il2cpp_array_size_t>(L_472));
		NullCheck(L_473);
		int32_t L_474 = L_473->___variable_HP_smth1_Q15;
		V_17 = L_474;
	}

IL_0e57:
	{
		int32_t L_475 = __this->___variable_HP_smth2_Q15;
		int32_t L_476 = V_17;
		int32_t L_477 = __this->___variable_HP_smth2_Q15;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_478;
		L_478 = Inlines_silk_SMLAWB_m8A023DCCC323ED0EB2CCF43D6ED6357B587EAAD2_inline(L_475, ((int32_t)il2cpp_codegen_subtract(L_476, L_477)), ((int32_t)983), NULL);
		__this->___variable_HP_smth2_Q15 = L_478;
		int32_t L_479 = __this->___variable_HP_smth2_Q15;
		int32_t L_480;
		L_480 = Inlines_silk_RSHIFT_m0ACD93ACB5B27378849FAD9F6440B867FA755103_inline(L_479, 8, NULL);
		int32_t L_481;
		L_481 = Inlines_silk_log2lin_mFB61AF160BBA8A179F17F7B375639DDCEDA19090_inline(L_480, NULL);
		V_16 = L_481;
		int32_t L_482 = __this->___application;
		if ((!(((uint32_t)L_482) == ((uint32_t)((int32_t)2048)))))
		{
			goto IL_0ec4;
		}
	}
	{
		ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 L_483 = ___0_pcm;
		int32_t L_484 = ___1_pcm_ptr;
		int32_t L_485 = V_16;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_486 = V_12;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_487;
		L_487 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_486, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_488 = V_26;
		int32_t L_489 = __this->___channels;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_490 = __this->___hp_mem;
		int32_t L_491 = ___2_frame_size;
		int32_t L_492 = __this->___channels;
		int32_t L_493 = __this->___Fs;
		CodecHelpers_hp_cutoff_mB1C77C6709A6092DB5B4E0270AE636F585114D48(L_483, L_484, L_485, L_487, ((int32_t)il2cpp_codegen_multiply(L_488, L_489)), L_490, L_491, L_492, L_493, NULL);
		goto IL_0eef;
	}

IL_0ec4:
	{
		ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 L_494 = ___0_pcm;
		int32_t L_495 = ___1_pcm_ptr;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_496 = V_12;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_497;
		L_497 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_496, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_498 = V_26;
		int32_t L_499 = __this->___channels;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_500 = __this->___hp_mem;
		int32_t L_501 = ___2_frame_size;
		int32_t L_502 = __this->___channels;
		int32_t L_503 = __this->___Fs;
		CodecHelpers_dc_reject_m66023F849A9C35E040B2DDA37ABF9A793F476ABE(L_494, L_495, 3, L_497, ((int32_t)il2cpp_codegen_multiply(L_498, L_499)), L_500, L_501, L_502, L_503, NULL);
	}

IL_0eef:
	{
		V_24 = ((int32_t)32767);
		int32_t L_504 = __this->___mode;
		if ((((int32_t)L_504) == ((int32_t)((int32_t)1002))))
		{
			goto IL_1582;
		}
	}
	{
		int32_t L_505 = __this->___channels;
		int32_t L_506 = ___2_frame_size;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_507 = (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)SZArrayNew(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(L_505, L_506)));
		V_63 = L_507;
		int32_t L_508 = V_6;
		int32_t L_509 = V_21;
		V_61 = ((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_multiply(8, L_508)), L_509));
		int32_t L_510 = __this->___mode;
		if ((!(((uint32_t)L_510) == ((uint32_t)((int32_t)1001)))))
		{
			goto IL_103a;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_511 = __this->___silk_mode;
		int32_t L_512 = __this->___stream_channels;
		int32_t L_513 = __this->___Fs;
		int32_t L_514 = ___2_frame_size;
		if ((((int32_t)L_513) == ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)100), L_514)))))
		{
			G_B252_0 = ((int32_t)5000);
			G_B252_1 = L_512;
			G_B252_2 = L_511;
			goto IL_0f4e;
		}
		G_B251_0 = ((int32_t)5000);
		G_B251_1 = L_512;
		G_B251_2 = L_511;
	}
	{
		G_B253_0 = 0;
		G_B253_1 = G_B251_0;
		G_B253_2 = G_B251_1;
		G_B253_3 = G_B251_2;
		goto IL_0f53;
	}

IL_0f4e:
	{
		G_B253_0 = ((int32_t)1000);
		G_B253_1 = G_B252_0;
		G_B253_2 = G_B252_1;
		G_B253_3 = G_B252_2;
	}

IL_0f53:
	{
		NullCheck(G_B253_3);
		G_B253_3->___bitRate = ((int32_t)il2cpp_codegen_multiply(G_B253_2, ((int32_t)il2cpp_codegen_add(G_B253_1, G_B253_0))));
		int32_t L_515 = V_23;
		if ((!(((uint32_t)L_515) == ((uint32_t)((int32_t)1104)))))
		{
			goto IL_0f89;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_516 = __this->___silk_mode;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_517 = L_516;
		NullCheck(L_517);
		int32_t L_518 = L_517->___bitRate;
		int32_t L_519 = V_61;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_520 = __this->___silk_mode;
		NullCheck(L_520);
		int32_t L_521 = L_520->___bitRate;
		NullCheck(L_517);
		L_517->___bitRate = ((int32_t)il2cpp_codegen_add(L_518, ((int32_t)(((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_subtract(L_519, L_521)), 2))/3))));
		goto IL_0fad;
	}

IL_0f89:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_522 = __this->___silk_mode;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_523 = L_522;
		NullCheck(L_523);
		int32_t L_524 = L_523->___bitRate;
		int32_t L_525 = V_61;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_526 = __this->___silk_mode;
		NullCheck(L_526);
		int32_t L_527 = L_526->___bitRate;
		NullCheck(L_523);
		L_523->___bitRate = ((int32_t)il2cpp_codegen_add(L_524, ((int32_t)(((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_subtract(L_525, L_527)), 3))/5))));
	}

IL_0fad:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_528 = __this->___silk_mode;
		NullCheck(L_528);
		int32_t L_529 = L_528->___bitRate;
		int32_t L_530 = V_61;
		if ((((int32_t)L_529) <= ((int32_t)((int32_t)(((int32_t)il2cpp_codegen_multiply(L_530, 4))/5)))))
		{
			goto IL_0fd1;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_531 = __this->___silk_mode;
		int32_t L_532 = V_61;
		NullCheck(L_531);
		L_531->___bitRate = ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_532, 4))/5));
	}

IL_0fd1:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_533 = __this->___energy_masking;
		if (L_533)
		{
			goto IL_1047;
		}
	}
	{
		int32_t L_534 = V_61;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_535 = __this->___silk_mode;
		NullCheck(L_535);
		int32_t L_536 = L_535->___bitRate;
		V_62 = ((int32_t)il2cpp_codegen_subtract(L_534, L_536));
		int32_t L_537 = V_23;
		if ((((int32_t)L_537) == ((int32_t)((int32_t)1104))))
		{
			goto IL_0ff9;
		}
	}
	{
		G_B262_0 = ((int32_t)3600);
		goto IL_0ffe;
	}

IL_0ff9:
	{
		G_B262_0 = ((int32_t)3000);
	}

IL_0ffe:
	{
		V_65 = G_B262_0;
		int32_t L_538 = V_62;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_539;
		L_539 = Inlines_SHL32_m759CE9A6D5B83434728CB2C33BA4320DFACBD900_inline(L_538, ((int32_t)9), NULL);
		int32_t L_540 = V_62;
		int32_t L_541 = __this->___stream_channels;
		int32_t L_542 = V_65;
		int32_t L_543;
		L_543 = Inlines_SHR32_mE532A866351E7866B6A1BAD8A8E9306DE22AE05F_inline(((int32_t)il2cpp_codegen_add(L_540, ((int32_t)il2cpp_codegen_multiply(L_541, L_542)))), 6, NULL);
		V_24 = ((int32_t)(L_539/L_543));
		int32_t L_544 = V_24;
		if ((((int32_t)L_544) < ((int32_t)((int32_t)28086))))
		{
			goto IL_102e;
		}
	}
	{
		G_B265_0 = ((int32_t)32767);
		goto IL_1036;
	}

IL_102e:
	{
		int32_t L_545 = V_24;
		G_B265_0 = ((int32_t)il2cpp_codegen_add(L_545, ((int32_t)4681)));
	}

IL_1036:
	{
		V_24 = G_B265_0;
		goto IL_1047;
	}

IL_103a:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_546 = __this->___silk_mode;
		int32_t L_547 = V_61;
		NullCheck(L_546);
		L_546->___bitRate = L_547;
	}

IL_1047:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_548 = __this->___energy_masking;
		if (!L_548)
		{
			goto IL_11a0;
		}
	}
	{
		int32_t L_549 = __this->___use_vbr;
		if (!L_549)
		{
			goto IL_11a0;
		}
	}
	{
		int32_t L_550 = __this->___lfe;
		if (L_550)
		{
			goto IL_11a0;
		}
	}
	{
		V_66 = 0;
		V_70 = ((int32_t)17);
		V_71 = (int16_t)((int32_t)16000);
		int32_t L_551 = __this->___bandwidth;
		if ((!(((uint32_t)L_551) == ((uint32_t)((int32_t)1101)))))
		{
			goto IL_1090;
		}
	}
	{
		V_70 = ((int32_t)13);
		V_71 = (int16_t)((int32_t)8000);
		goto IL_10a8;
	}

IL_1090:
	{
		int32_t L_552 = __this->___bandwidth;
		if ((!(((uint32_t)L_552) == ((uint32_t)((int32_t)1102)))))
		{
			goto IL_10a8;
		}
	}
	{
		V_70 = ((int32_t)15);
		V_71 = (int16_t)((int32_t)12000);
	}

IL_10a8:
	{
		V_69 = 0;
		goto IL_10f9;
	}

IL_10ad:
	{
		V_2 = 0;
		goto IL_10ee;
	}

IL_10b1:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_553 = __this->___energy_masking;
		int32_t L_554 = V_69;
		int32_t L_555 = V_2;
		NullCheck(L_553);
		int32_t L_556 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_554)), L_555));
		int32_t L_557 = (L_553)->GetAt(static_cast<il2cpp_array_size_t>(L_556));
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_558;
		L_558 = Inlines_MIN16_mD65F33577C97F96B9FE9B2540589BA7FADF52F5E_inline(L_557, ((int32_t)512), NULL);
		int32_t L_559;
		L_559 = Inlines_MAX16_m4D603BAD0F242EB66ED76BE982BC3907D9DF44A5_inline(L_558, ((int32_t)-2048), NULL);
		V_72 = L_559;
		int32_t L_560 = V_72;
		if ((((int32_t)L_560) <= ((int32_t)0)))
		{
			goto IL_10e3;
		}
	}
	{
		int32_t L_561 = V_72;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_562;
		L_562 = Inlines_HALF16_mCC975475CB9BE63D15752AA7AA0F3E44598ADB4D_inline(L_561, NULL);
		V_72 = L_562;
	}

IL_10e3:
	{
		int32_t L_563 = V_66;
		int32_t L_564 = V_72;
		V_66 = ((int32_t)il2cpp_codegen_add(L_563, L_564));
		int32_t L_565 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_565, 1));
	}

IL_10ee:
	{
		int32_t L_566 = V_2;
		int32_t L_567 = V_70;
		if ((((int32_t)L_566) < ((int32_t)L_567)))
		{
			goto IL_10b1;
		}
	}
	{
		int32_t L_568 = V_69;
		V_69 = ((int32_t)il2cpp_codegen_add(L_568, 1));
	}

IL_10f9:
	{
		int32_t L_569 = V_69;
		int32_t L_570 = __this->___channels;
		if ((((int32_t)L_569) < ((int32_t)L_570)))
		{
			goto IL_10ad;
		}
	}
	{
		int32_t L_571 = V_66;
		int32_t L_572 = V_70;
		int32_t L_573 = __this->___channels;
		V_67 = ((int32_t)il2cpp_codegen_multiply(((int32_t)(L_571/L_572)), L_573));
		int32_t L_574 = V_67;
		V_67 = ((int32_t)il2cpp_codegen_add(L_574, ((int32_t)205)));
		int16_t L_575 = V_71;
		int32_t L_576 = V_67;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_577;
		L_577 = Inlines_MULT16_16_m86CC5979188CE7184708F6DC86E20F35D4501777_inline((int32_t)L_575, L_576, NULL);
		int32_t L_578;
		L_578 = Inlines_PSHR32_m795531FF9BB2EDD62D70EC3925DC6CA0F8B50983_inline(L_577, ((int32_t)10), NULL);
		V_68 = L_578;
		int32_t L_579 = V_68;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_580 = __this->___silk_mode;
		NullCheck(L_580);
		int32_t L_581 = L_580->___bitRate;
		int32_t L_582;
		L_582 = Inlines_MAX32_m603F38A48C71C4DF8E2938A811D591A5B3485B65_inline(L_579, ((int32_t)(((int32_t)il2cpp_codegen_multiply(((int32_t)-2), L_581))/3)), NULL);
		V_68 = L_582;
		int32_t L_583 = __this->___bandwidth;
		if ((((int32_t)L_583) == ((int32_t)((int32_t)1104))))
		{
			goto IL_1160;
		}
	}
	{
		int32_t L_584 = __this->___bandwidth;
		if ((!(((uint32_t)L_584) == ((uint32_t)((int32_t)1105)))))
		{
			goto IL_117a;
		}
	}

IL_1160:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_585 = __this->___silk_mode;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_586 = L_585;
		NullCheck(L_586);
		int32_t L_587 = L_586->___bitRate;
		int32_t L_588 = V_68;
		NullCheck(L_586);
		L_586->___bitRate = ((int32_t)il2cpp_codegen_add(L_587, ((int32_t)(((int32_t)il2cpp_codegen_multiply(3, L_588))/5))));
		goto IL_118e;
	}

IL_117a:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_589 = __this->___silk_mode;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_590 = L_589;
		NullCheck(L_590);
		int32_t L_591 = L_590->___bitRate;
		int32_t L_592 = V_68;
		NullCheck(L_590);
		L_590->___bitRate = ((int32_t)il2cpp_codegen_add(L_591, L_592));
	}

IL_118e:
	{
		int32_t L_593 = V_6;
		int32_t L_594 = V_68;
		int32_t L_595 = ___2_frame_size;
		int32_t L_596 = __this->___Fs;
		V_6 = ((int32_t)il2cpp_codegen_add(L_593, ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_594, L_595))/((int32_t)il2cpp_codegen_multiply(8, L_596))))));
	}

IL_11a0:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_597 = __this->___silk_mode;
		int32_t L_598 = ___2_frame_size;
		int32_t L_599 = __this->___Fs;
		NullCheck(L_597);
		L_597->___payloadSize_ms = ((int32_t)(((int32_t)il2cpp_codegen_multiply(((int32_t)1000), L_598))/L_599));
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_600 = __this->___silk_mode;
		int32_t L_601 = __this->___channels;
		NullCheck(L_600);
		L_600->___nChannelsAPI = L_601;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_602 = __this->___silk_mode;
		int32_t L_603 = __this->___stream_channels;
		NullCheck(L_602);
		L_602->___nChannelsInternal = L_603;
		int32_t L_604 = V_23;
		if ((!(((uint32_t)L_604) == ((uint32_t)((int32_t)1101)))))
		{
			goto IL_11f6;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_605 = __this->___silk_mode;
		NullCheck(L_605);
		L_605->___desiredInternalSampleRate = ((int32_t)8000);
		goto IL_1221;
	}

IL_11f6:
	{
		int32_t L_606 = V_23;
		if ((!(((uint32_t)L_606) == ((uint32_t)((int32_t)1102)))))
		{
			goto IL_1211;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_607 = __this->___silk_mode;
		NullCheck(L_607);
		L_607->___desiredInternalSampleRate = ((int32_t)12000);
		goto IL_1221;
	}

IL_1211:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_608 = __this->___silk_mode;
		NullCheck(L_608);
		L_608->___desiredInternalSampleRate = ((int32_t)16000);
	}

IL_1221:
	{
		int32_t L_609 = __this->___mode;
		if ((!(((uint32_t)L_609) == ((uint32_t)((int32_t)1001)))))
		{
			goto IL_1240;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_610 = __this->___silk_mode;
		NullCheck(L_610);
		L_610->___minInternalSampleRate = ((int32_t)16000);
		goto IL_1250;
	}

IL_1240:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_611 = __this->___silk_mode;
		NullCheck(L_611);
		L_611->___minInternalSampleRate = ((int32_t)8000);
	}

IL_1250:
	{
		int32_t L_612 = __this->___mode;
		if ((!(((uint32_t)L_612) == ((uint32_t)((int32_t)1000)))))
		{
			goto IL_12f6;
		}
	}
	{
		int32_t L_613 = V_22;
		V_73 = L_613;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_614 = __this->___silk_mode;
		NullCheck(L_614);
		L_614->___maxInternalSampleRate = ((int32_t)16000);
		int32_t L_615 = V_21;
		if ((((int32_t)L_615) <= ((int32_t)((int32_t)50))))
		{
			goto IL_1282;
		}
	}
	{
		int32_t L_616 = V_73;
		V_73 = ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_616, 2))/3));
	}

IL_1282:
	{
		int32_t L_617 = V_73;
		if ((((int32_t)L_617) >= ((int32_t)((int32_t)13000))))
		{
			goto IL_12bb;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_618 = __this->___silk_mode;
		NullCheck(L_618);
		L_618->___maxInternalSampleRate = ((int32_t)12000);
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_619 = __this->___silk_mode;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_620 = __this->___silk_mode;
		NullCheck(L_620);
		int32_t L_621 = L_620->___desiredInternalSampleRate;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_622;
		L_622 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)12000), L_621, NULL);
		NullCheck(L_619);
		L_619->___desiredInternalSampleRate = L_622;
	}

IL_12bb:
	{
		int32_t L_623 = V_73;
		if ((((int32_t)L_623) >= ((int32_t)((int32_t)9600))))
		{
			goto IL_1306;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_624 = __this->___silk_mode;
		NullCheck(L_624);
		L_624->___maxInternalSampleRate = ((int32_t)8000);
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_625 = __this->___silk_mode;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_626 = __this->___silk_mode;
		NullCheck(L_626);
		int32_t L_627 = L_626->___desiredInternalSampleRate;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_628;
		L_628 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)8000), L_627, NULL);
		NullCheck(L_625);
		L_625->___desiredInternalSampleRate = L_628;
		goto IL_1306;
	}

IL_12f6:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_629 = __this->___silk_mode;
		NullCheck(L_629);
		L_629->___maxInternalSampleRate = ((int32_t)16000);
	}

IL_1306:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_630 = __this->___silk_mode;
		int32_t L_631 = __this->___use_vbr;
		if (!L_631)
		{
			G_B305_0 = L_630;
			goto IL_1317;
		}
		G_B304_0 = L_630;
	}
	{
		G_B306_0 = 0;
		G_B306_1 = G_B304_0;
		goto IL_1318;
	}

IL_1317:
	{
		G_B306_0 = 1;
		G_B306_1 = G_B305_0;
	}

IL_1318:
	{
		NullCheck(G_B306_1);
		G_B306_1->___useCBR = G_B306_0;
		int32_t L_632 = V_25;
		int32_t L_633 = V_10;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_634;
		L_634 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)1275), ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_632, 1)), L_633)), NULL);
		V_4 = L_634;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_635 = __this->___silk_mode;
		int32_t L_636 = V_4;
		NullCheck(L_635);
		L_635->___maxBits = ((int32_t)il2cpp_codegen_multiply(L_636, 8));
		int32_t L_637 = __this->___mode;
		if ((!(((uint32_t)L_637) == ((uint32_t)((int32_t)1001)))))
		{
			goto IL_1368;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_638 = __this->___silk_mode;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_639 = __this->___silk_mode;
		NullCheck(L_639);
		int32_t L_640 = L_639->___maxBits;
		NullCheck(L_638);
		L_638->___maxBits = ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_640, ((int32_t)9)))/((int32_t)10)));
	}

IL_1368:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_641 = __this->___silk_mode;
		NullCheck(L_641);
		int32_t L_642 = L_641->___useCBR;
		if (!L_642)
		{
			goto IL_13ba;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_643 = __this->___silk_mode;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_644 = __this->___silk_mode;
		NullCheck(L_644);
		int32_t L_645 = L_644->___bitRate;
		int32_t L_646 = ___2_frame_size;
		int32_t L_647 = __this->___Fs;
		NullCheck(L_643);
		L_643->___maxBits = ((int32_t)il2cpp_codegen_multiply(((int32_t)(((int32_t)il2cpp_codegen_multiply(L_645, L_646))/((int32_t)il2cpp_codegen_multiply(L_647, 8)))), 8));
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_648 = __this->___silk_mode;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_649 = __this->___silk_mode;
		NullCheck(L_649);
		int32_t L_650 = L_649->___bitRate;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_651;
		L_651 = Inlines_IMAX_mFECDD1F5C3C0962AF8B0140E78A6C3A25BCF9C23_inline(1, ((int32_t)il2cpp_codegen_subtract(L_650, ((int32_t)2000))), NULL);
		NullCheck(L_648);
		L_648->___bitRate = L_651;
	}

IL_13ba:
	{
		int32_t L_652 = V_7;
		if (!L_652)
		{
			goto IL_1471;
		}
	}
	{
		BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* L_653 = (BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026*)il2cpp_codegen_object_new(BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026_il2cpp_TypeInfo_var);
		BoxedValueInt__ctor_m6EC58F06F4673535F2682F1731C6F36FC073A36A(L_653, 0, NULL);
		V_74 = L_653;
		int32_t L_654 = __this->___channels;
		int32_t L_655 = __this->___encoder_buffer;
		int32_t L_656 = __this->___delay_compensation;
		int32_t L_657 = __this->___Fs;
		V_75 = ((int32_t)il2cpp_codegen_multiply(L_654, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_655, L_656)), ((int32_t)(L_657/((int32_t)400)))))));
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_658 = __this->___delay_buffer;
		int32_t L_659 = V_75;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_660 = V_28;
		NullCheck(L_660);
		int32_t L_661 = L_660->___overlap;
		int32_t L_662 = __this->___Fs;
		int32_t L_663 = __this->___channels;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_664 = V_28;
		NullCheck(L_664);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_665 = L_664->___window;
		int32_t L_666 = __this->___Fs;
		CodecHelpers_gain_fade_mB38DEC7BAD27021D38F3577722DFB025B8657774(L_658, L_659, 0, ((int32_t)32767), L_661, ((int32_t)(L_662/((int32_t)400))), L_663, L_665, L_666, NULL);
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_667 = __this->___delay_buffer;
		int32_t L_668 = V_75;
		Arrays_MemSetShort_m8C49EA240FDBFE594D42AEB7C682C4B48683D01E(L_667, (int16_t)0, L_668, NULL);
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_669 = __this->___delay_buffer;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_670 = V_63;
		int32_t L_671 = __this->___encoder_buffer;
		int32_t L_672 = __this->___channels;
		Arrays_MemCopy_m6694E7C365EE590A29753D43699215FBC8162E89(L_669, 0, L_670, 0, ((int32_t)il2cpp_codegen_multiply(L_671, L_672)), NULL);
		SilkEncoder_t7AB5C2F712CDB92EBFCDAF8E9743C5A39B7CFD6D* L_673 = V_0;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_674 = __this->___silk_mode;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_675 = V_63;
		int32_t L_676 = __this->___encoder_buffer;
		int32_t L_677 = ___4_data_ptr;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_678;
		L_678 = Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_inline((&___3_data), L_677, Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_RuntimeMethod_var);
		BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* L_679 = V_74;
		int32_t L_680;
		L_680 = EncodeAPI_silk_Encode_m03CA6F3640C38ACB077A8718E63B9AF31C2F73DC(L_673, L_674, L_675, L_676, (EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679*)NULL, L_678, L_679, 1, NULL);
	}

IL_1471:
	{
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_681 = V_12;
		int32_t L_682 = V_26;
		int32_t L_683 = __this->___channels;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_684 = V_63;
		int32_t L_685 = ___2_frame_size;
		int32_t L_686 = __this->___channels;
		Arrays_MemCopy_m6694E7C365EE590A29753D43699215FBC8162E89(L_681, ((int32_t)il2cpp_codegen_multiply(L_682, L_683)), L_684, 0, ((int32_t)il2cpp_codegen_multiply(L_685, L_686)), NULL);
		int32_t L_687 = V_4;
		BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* L_688 = (BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026*)il2cpp_codegen_object_new(BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026_il2cpp_TypeInfo_var);
		BoxedValueInt__ctor_m6EC58F06F4673535F2682F1731C6F36FC073A36A(L_688, L_687, NULL);
		V_64 = L_688;
		SilkEncoder_t7AB5C2F712CDB92EBFCDAF8E9743C5A39B7CFD6D* L_689 = V_0;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_690 = __this->___silk_mode;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_691 = V_63;
		int32_t L_692 = ___2_frame_size;
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_693 = V_5;
		int32_t L_694 = ___4_data_ptr;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_695;
		L_695 = Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_inline((&___3_data), L_694, Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_RuntimeMethod_var);
		BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* L_696 = V_64;
		int32_t L_697;
		L_697 = EncodeAPI_silk_Encode_m03CA6F3640C38ACB077A8718E63B9AF31C2F73DC(L_689, L_690, L_691, L_692, L_693, L_695, L_696, 0, NULL);
		V_3 = L_697;
		BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* L_698 = V_64;
		NullCheck(L_698);
		int32_t L_699 = L_698->___Val;
		V_4 = L_699;
		int32_t L_700 = V_3;
		if (!L_700)
		{
			goto IL_14c2;
		}
	}
	{
		return ((int32_t)-3);
	}

IL_14c2:
	{
		int32_t L_701 = V_4;
		if (L_701)
		{
			goto IL_14f6;
		}
	}
	{
		__this->___rangeFinal = (uint32_t)0;
		int32_t L_702 = ___4_data_ptr;
		uint8_t* L_703;
		L_703 = il2cpp_span_get_item((uint8_t*)((Il2CppByReference*)&(((&___3_data))->____pointer))->value, (((int32_t)il2cpp_codegen_subtract(L_702, 1))), ((&___3_data))->____length);
		int32_t L_704 = __this->___mode;
		int32_t L_705 = __this->___Fs;
		int32_t L_706 = ___2_frame_size;
		int32_t L_707 = V_23;
		int32_t L_708 = __this->___stream_channels;
		uint8_t L_709;
		L_709 = CodecHelpers_gen_toc_m55919D0EC27589F5328AD925AA91F8B0D4A9EBA2(L_704, ((int32_t)(L_705/L_706)), L_707, L_708, NULL);
		*((int8_t*)L_703) = (int8_t)L_709;
		return 1;
	}

IL_14f6:
	{
		int32_t L_710 = __this->___mode;
		if ((!(((uint32_t)L_710) == ((uint32_t)((int32_t)1000)))))
		{
			goto IL_1552;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_711 = __this->___silk_mode;
		NullCheck(L_711);
		int32_t L_712 = L_711->___internalSampleRate;
		if ((!(((uint32_t)L_712) == ((uint32_t)((int32_t)8000)))))
		{
			goto IL_151e;
		}
	}
	{
		V_23 = (int32_t)((int32_t)1101);
		goto IL_1552;
	}

IL_151e:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_713 = __this->___silk_mode;
		NullCheck(L_713);
		int32_t L_714 = L_713->___internalSampleRate;
		if ((!(((uint32_t)L_714) == ((uint32_t)((int32_t)12000)))))
		{
			goto IL_1539;
		}
	}
	{
		V_23 = (int32_t)((int32_t)1102);
		goto IL_1552;
	}

IL_1539:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_715 = __this->___silk_mode;
		NullCheck(L_715);
		int32_t L_716 = L_715->___internalSampleRate;
		if ((!(((uint32_t)L_716) == ((uint32_t)((int32_t)16000)))))
		{
			goto IL_1552;
		}
	}
	{
		V_23 = (int32_t)((int32_t)1103);
	}

IL_1552:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_717 = __this->___silk_mode;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_718 = __this->___silk_mode;
		NullCheck(L_718);
		int32_t L_719 = L_718->___switchReady;
		NullCheck(L_717);
		L_717->___opusCanSwitch = L_719;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_720 = __this->___silk_mode;
		NullCheck(L_720);
		int32_t L_721 = L_720->___opusCanSwitch;
		if (!L_721)
		{
			goto IL_1582;
		}
	}
	{
		V_9 = 1;
		V_11 = 0;
		__this->___silk_bw_switch = 1;
	}

IL_1582:
	{
		V_76 = ((int32_t)21);
		int32_t L_722 = V_23;
		switch (((int32_t)il2cpp_codegen_subtract((int32_t)L_722, ((int32_t)1101))))
		{
			case 0:
			{
				goto IL_15a9;
			}
			case 1:
			{
				goto IL_15af;
			}
			case 2:
			{
				goto IL_15af;
			}
			case 3:
			{
				goto IL_15b5;
			}
			case 4:
			{
				goto IL_15bb;
			}
		}
	}
	{
		goto IL_15bf;
	}

IL_15a9:
	{
		V_76 = ((int32_t)13);
		goto IL_15bf;
	}

IL_15af:
	{
		V_76 = ((int32_t)17);
		goto IL_15bf;
	}

IL_15b5:
	{
		V_76 = ((int32_t)19);
		goto IL_15bf;
	}

IL_15bb:
	{
		V_76 = ((int32_t)21);
	}

IL_15bf:
	{
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_723 = V_1;
		int32_t L_724 = V_76;
		NullCheck(L_723);
		CeltEncoder_SetEndBand_m767B785A3E059611D2E876D483F43673419EBA0D(L_723, L_724, NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_725 = V_1;
		int32_t L_726 = __this->___stream_channels;
		NullCheck(L_725);
		CeltEncoder_SetChannels_m044A630FD1013D07F49245B2C009452B31BB1CC5(L_725, L_726, NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_727 = V_1;
		NullCheck(L_727);
		CeltEncoder_SetBitrate_mCF59724BF7FF4D5F66B571C27B99B4C5F424AAB0(L_727, (-1), NULL);
		int32_t L_728 = __this->___mode;
		if ((((int32_t)L_728) == ((int32_t)((int32_t)1000))))
		{
			goto IL_1725;
		}
	}
	{
		V_77 = 2;
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_729 = V_1;
		NullCheck(L_729);
		CeltEncoder_SetVBR_mB2A8CFC94909FB78E5D6B5CCEC287AE5C26748BB(L_729, (bool)0, NULL);
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_730 = __this->___silk_mode;
		NullCheck(L_730);
		int32_t L_731 = L_730->___reducedDependency;
		if (!L_731)
		{
			goto IL_1604;
		}
	}
	{
		V_77 = 0;
	}

IL_1604:
	{
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_732 = V_1;
		int32_t L_733 = V_77;
		NullCheck(L_732);
		CeltEncoder_SetPrediction_m880E0433982007C125828ED68A45A4A134798EB4(L_732, L_733, NULL);
		int32_t L_734 = __this->___mode;
		if ((!(((uint32_t)L_734) == ((uint32_t)((int32_t)1001)))))
		{
			goto IL_167e;
		}
	}
	{
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_735 = V_5;
		NullCheck(L_735);
		int32_t L_736;
		L_736 = EntropyCoder_tell_m29422D894C6D91518823D9C94D3CC93ACEA2350A(L_735, NULL);
		V_78 = ((int32_t)(((int32_t)il2cpp_codegen_add(L_736, 7))>>3));
		int32_t L_737 = V_9;
		if (!L_737)
		{
			goto IL_1640;
		}
	}
	{
		int32_t L_738 = V_78;
		int32_t L_739 = __this->___mode;
		if ((((int32_t)L_739) == ((int32_t)((int32_t)1001))))
		{
			G_B338_0 = L_738;
			goto IL_163c;
		}
		G_B337_0 = L_738;
	}
	{
		G_B339_0 = 1;
		G_B339_1 = G_B337_0;
		goto IL_163d;
	}

IL_163c:
	{
		G_B339_0 = 3;
		G_B339_1 = G_B338_0;
	}

IL_163d:
	{
		V_78 = ((int32_t)il2cpp_codegen_add(G_B339_1, G_B339_0));
	}

IL_1640:
	{
		int32_t L_740 = __this->___use_vbr;
		if (!L_740)
		{
			goto IL_166b;
		}
	}
	{
		int32_t L_741 = V_78;
		int32_t L_742 = V_6;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_743 = __this->___silk_mode;
		NullCheck(L_743);
		int32_t L_744 = L_743->___bitRate;
		int32_t L_745 = ___2_frame_size;
		int32_t L_746 = __this->___Fs;
		V_13 = ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_741, L_742)), ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_744, L_745))/((int32_t)il2cpp_codegen_multiply(8, L_746))))));
		goto IL_1728;
	}

IL_166b:
	{
		int32_t L_747 = V_78;
		int32_t L_748 = V_6;
		if ((((int32_t)L_747) > ((int32_t)L_748)))
		{
			goto IL_1675;
		}
	}
	{
		int32_t L_749 = V_6;
		G_B345_0 = L_749;
		goto IL_1677;
	}

IL_1675:
	{
		int32_t L_750 = V_78;
		G_B345_0 = L_750;
	}

IL_1677:
	{
		V_13 = G_B345_0;
		goto IL_1728;
	}

IL_167e:
	{
		int32_t L_751 = __this->___use_vbr;
		if (!L_751)
		{
			goto IL_171f;
		}
	}
	{
		V_79 = 0;
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_752 = __this->___analysis;
		NullCheck(L_752);
		bool L_753 = L_752->___enabled;
		if (!L_753)
		{
			goto IL_16ef;
		}
	}
	{
		int32_t L_754 = __this->___variable_duration;
		if ((!(((uint32_t)L_754) == ((uint32_t)((int32_t)5010)))))
		{
			goto IL_16ef;
		}
	}
	{
		int32_t L_755 = ___2_frame_size;
		int32_t L_756 = __this->___Fs;
		if ((((int32_t)L_755) == ((int32_t)((int32_t)(L_756/((int32_t)50))))))
		{
			goto IL_16ef;
		}
	}
	{
		int32_t L_757 = __this->___stream_channels;
		int32_t L_758 = __this->___Fs;
		int32_t L_759 = ___2_frame_size;
		V_79 = ((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)60), L_757)), ((int32_t)40))), ((int32_t)il2cpp_codegen_subtract(((int32_t)(L_758/L_759)), ((int32_t)50)))));
		AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* L_760 = V_29;
		NullCheck(L_760);
		int32_t L_761 = L_760->___valid;
		if (!L_761)
		{
			goto IL_16ef;
		}
	}
	{
		int32_t L_762 = V_79;
		AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* L_763 = V_29;
		NullCheck(L_763);
		float L_764 = L_763->___tonality;
		V_79 = il2cpp_codegen_cast_double_to_int<int32_t>(((float)il2cpp_codegen_multiply(((float)L_762), ((float)il2cpp_codegen_add((1.0f), ((float)il2cpp_codegen_multiply((0.5f), L_764)))))));
	}

IL_16ef:
	{
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_765 = V_1;
		NullCheck(L_765);
		CeltEncoder_SetVBR_mB2A8CFC94909FB78E5D6B5CCEC287AE5C26748BB(L_765, (bool)1, NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_766 = V_1;
		int32_t L_767 = __this->___vbr_constraint;
		NullCheck(L_766);
		CeltEncoder_SetVBRConstraint_mCA7F81F0B4A945B523C40A8C49AC3EB27B8DE057(L_766, (bool)((!(((uint32_t)L_767) <= ((uint32_t)0)))? 1 : 0), NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_768 = V_1;
		int32_t L_769 = __this->___bitrate_bps;
		int32_t L_770 = V_79;
		NullCheck(L_768);
		CeltEncoder_SetBitrate_mCF59724BF7FF4D5F66B571C27B99B4C5F424AAB0(L_768, ((int32_t)il2cpp_codegen_add(L_769, L_770)), NULL);
		int32_t L_771 = V_25;
		int32_t L_772 = V_10;
		V_13 = ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_771, 1)), L_772));
		goto IL_1728;
	}

IL_171f:
	{
		int32_t L_773 = V_6;
		V_13 = L_773;
		goto IL_1728;
	}

IL_1725:
	{
		V_13 = 0;
	}

IL_1728:
	{
		int32_t L_774 = __this->___channels;
		int32_t L_775 = __this->___Fs;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_776 = (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)SZArrayNew(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var, (uint32_t)((int32_t)(((int32_t)il2cpp_codegen_multiply(L_774, L_775))/((int32_t)400))));
		V_32 = L_776;
		int32_t L_777 = __this->___mode;
		if ((((int32_t)L_777) == ((int32_t)((int32_t)1000))))
		{
			goto IL_17a4;
		}
	}
	{
		int32_t L_778 = __this->___mode;
		int32_t L_779 = __this->___prev_mode;
		if ((((int32_t)L_778) == ((int32_t)L_779)))
		{
			goto IL_17a4;
		}
	}
	{
		int32_t L_780 = __this->___prev_mode;
		if ((((int32_t)L_780) <= ((int32_t)0)))
		{
			goto IL_17a4;
		}
	}
	{
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_781 = __this->___delay_buffer;
		int32_t L_782 = __this->___encoder_buffer;
		int32_t L_783 = V_26;
		int32_t L_784 = __this->___Fs;
		int32_t L_785 = __this->___channels;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_786 = V_32;
		int32_t L_787 = __this->___channels;
		int32_t L_788 = __this->___Fs;
		Arrays_MemCopy_m6694E7C365EE590A29753D43699215FBC8162E89(L_781, ((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_782, L_783)), ((int32_t)(L_784/((int32_t)400))))), L_785)), L_786, 0, ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_787, L_788))/((int32_t)400))), NULL);
	}

IL_17a4:
	{
		int32_t L_789 = __this->___channels;
		int32_t L_790 = __this->___encoder_buffer;
		int32_t L_791 = ___2_frame_size;
		int32_t L_792 = V_26;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(L_789, ((int32_t)il2cpp_codegen_subtract(L_790, ((int32_t)il2cpp_codegen_add(L_791, L_792))))))) <= ((int32_t)0)))
		{
			goto IL_180c;
		}
	}
	{
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_793 = __this->___delay_buffer;
		int32_t L_794 = __this->___channels;
		int32_t L_795 = ___2_frame_size;
		int32_t L_796 = __this->___channels;
		int32_t L_797 = __this->___encoder_buffer;
		int32_t L_798 = ___2_frame_size;
		int32_t L_799 = V_26;
		Arrays_MemMoveShort_m07C394C79F74EE49ACB696FB6B519B9C6ACD7CB0(L_793, ((int32_t)il2cpp_codegen_multiply(L_794, L_795)), 0, ((int32_t)il2cpp_codegen_multiply(L_796, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_797, L_798)), L_799)))), NULL);
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_800 = V_12;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_801 = __this->___delay_buffer;
		int32_t L_802 = __this->___channels;
		int32_t L_803 = __this->___encoder_buffer;
		int32_t L_804 = ___2_frame_size;
		int32_t L_805 = V_26;
		int32_t L_806 = ___2_frame_size;
		int32_t L_807 = V_26;
		int32_t L_808 = __this->___channels;
		Arrays_MemCopy_m6694E7C365EE590A29753D43699215FBC8162E89(L_800, 0, L_801, ((int32_t)il2cpp_codegen_multiply(L_802, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_803, L_804)), L_805)))), ((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_add(L_806, L_807)), L_808)), NULL);
		goto IL_1839;
	}

IL_180c:
	{
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_809 = V_12;
		int32_t L_810 = ___2_frame_size;
		int32_t L_811 = V_26;
		int32_t L_812 = __this->___encoder_buffer;
		int32_t L_813 = __this->___channels;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_814 = __this->___delay_buffer;
		int32_t L_815 = __this->___encoder_buffer;
		int32_t L_816 = __this->___channels;
		Arrays_MemCopy_m6694E7C365EE590A29753D43699215FBC8162E89(L_809, ((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(L_810, L_811)), L_812)), L_813)), L_814, 0, ((int32_t)il2cpp_codegen_multiply(L_815, L_816)), NULL);
	}

IL_1839:
	{
		int32_t L_817 = __this->___prev_HB_gain;
		if ((((int32_t)L_817) < ((int32_t)((int32_t)32767))))
		{
			goto IL_184f;
		}
	}
	{
		int32_t L_818 = V_24;
		if ((((int32_t)L_818) >= ((int32_t)((int32_t)32767))))
		{
			goto IL_187a;
		}
	}

IL_184f:
	{
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_819 = V_12;
		int32_t L_820 = __this->___prev_HB_gain;
		int32_t L_821 = V_24;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_822 = V_28;
		NullCheck(L_822);
		int32_t L_823 = L_822->___overlap;
		int32_t L_824 = ___2_frame_size;
		int32_t L_825 = __this->___channels;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_826 = V_28;
		NullCheck(L_826);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_827 = L_826->___window;
		int32_t L_828 = __this->___Fs;
		CodecHelpers_gain_fade_mB38DEC7BAD27021D38F3577722DFB025B8657774(L_819, 0, L_820, L_821, L_823, L_824, L_825, L_827, L_828, NULL);
	}

IL_187a:
	{
		int32_t L_829 = V_24;
		__this->___prev_HB_gain = L_829;
		int32_t L_830 = __this->___mode;
		if ((!(((uint32_t)L_830) == ((uint32_t)((int32_t)1001)))))
		{
			goto IL_1898;
		}
	}
	{
		int32_t L_831 = __this->___stream_channels;
		if ((!(((uint32_t)L_831) == ((uint32_t)1))))
		{
			goto IL_18bd;
		}
	}

IL_1898:
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_832 = __this->___silk_mode;
		int32_t L_833 = V_19;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_834;
		L_834 = Inlines_IMAX_mFECDD1F5C3C0962AF8B0140E78A6C3A25BCF9C23_inline(0, ((int32_t)il2cpp_codegen_subtract(L_833, ((int32_t)30000))), NULL);
		int32_t L_835;
		L_835 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)16384), ((int32_t)il2cpp_codegen_multiply(2, L_834)), NULL);
		NullCheck(L_832);
		L_832->___stereoWidth_Q14 = L_835;
	}

IL_18bd:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_836 = __this->___energy_masking;
		if (L_836)
		{
			goto IL_1977;
		}
	}
	{
		int32_t L_837 = __this->___channels;
		if ((!(((uint32_t)L_837) == ((uint32_t)2))))
		{
			goto IL_1977;
		}
	}
	{
		int16_t L_838 = __this->___hybrid_stereo_width_Q14;
		if ((((int32_t)L_838) < ((int32_t)((int32_t)16384))))
		{
			goto IL_18f6;
		}
	}
	{
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_839 = __this->___silk_mode;
		NullCheck(L_839);
		int32_t L_840 = L_839->___stereoWidth_Q14;
		if ((((int32_t)L_840) >= ((int32_t)((int32_t)16384))))
		{
			goto IL_1977;
		}
	}

IL_18f6:
	{
		int16_t L_841 = __this->___hybrid_stereo_width_Q14;
		V_80 = (int32_t)L_841;
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_842 = __this->___silk_mode;
		NullCheck(L_842);
		int32_t L_843 = L_842->___stereoWidth_Q14;
		V_81 = L_843;
		int32_t L_844 = V_80;
		if ((((int32_t)L_844) == ((int32_t)((int32_t)16384))))
		{
			goto IL_191e;
		}
	}
	{
		int32_t L_845 = V_80;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_846;
		L_846 = Inlines_SHL16_mDE053DF36529BA35606160EBC860F23260B23A87_inline(L_845, 1, NULL);
		G_B375_0 = L_846;
		goto IL_1923;
	}

IL_191e:
	{
		G_B375_0 = ((int32_t)32767);
	}

IL_1923:
	{
		V_80 = G_B375_0;
		int32_t L_847 = V_81;
		if ((((int32_t)L_847) == ((int32_t)((int32_t)16384))))
		{
			goto IL_1938;
		}
	}
	{
		int32_t L_848 = V_81;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_849;
		L_849 = Inlines_SHL16_mDE053DF36529BA35606160EBC860F23260B23A87_inline(L_848, 1, NULL);
		G_B378_0 = L_849;
		goto IL_193d;
	}

IL_1938:
	{
		G_B378_0 = ((int32_t)32767);
	}

IL_193d:
	{
		V_81 = G_B378_0;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_850 = V_12;
		int32_t L_851 = V_80;
		int32_t L_852 = V_81;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_853 = V_28;
		NullCheck(L_853);
		int32_t L_854 = L_853->___overlap;
		int32_t L_855 = ___2_frame_size;
		int32_t L_856 = __this->___channels;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_857 = V_28;
		NullCheck(L_857);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_858 = L_857->___window;
		int32_t L_859 = __this->___Fs;
		CodecHelpers_stereo_fade_mFC6173FD066FAC8E29FD80632BC92FC90CB188CC(L_850, L_851, L_852, L_854, L_855, L_856, L_858, L_859, NULL);
		EncControlState_t1F753CF3968665C2171A288F862D70168F348019* L_860 = __this->___silk_mode;
		NullCheck(L_860);
		int32_t L_861 = L_860->___stereoWidth_Q14;
		__this->___hybrid_stereo_width_Q14 = ((int16_t)L_861);
	}

IL_1977:
	{
		int32_t L_862 = __this->___mode;
		if ((((int32_t)L_862) == ((int32_t)((int32_t)1002))))
		{
			goto IL_1a7b;
		}
	}
	{
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_863 = V_5;
		NullCheck(L_863);
		int32_t L_864;
		L_864 = EntropyCoder_tell_m29422D894C6D91518823D9C94D3CC93ACEA2350A(L_863, NULL);
		int32_t L_865 = __this->___mode;
		if ((((int32_t)L_865) == ((int32_t)((int32_t)1001))))
		{
			G_B382_0 = ((int32_t)20);
			G_B382_1 = ((int32_t)il2cpp_codegen_add(L_864, ((int32_t)17)));
			goto IL_19a3;
		}
		G_B381_0 = ((int32_t)20);
		G_B381_1 = ((int32_t)il2cpp_codegen_add(L_864, ((int32_t)17)));
	}
	{
		G_B383_0 = 0;
		G_B383_1 = G_B381_0;
		G_B383_2 = G_B381_1;
		goto IL_19a4;
	}

IL_19a3:
	{
		G_B383_0 = 1;
		G_B383_1 = G_B382_0;
		G_B383_2 = G_B382_1;
	}

IL_19a4:
	{
		int32_t L_866 = V_25;
		if ((((int32_t)((int32_t)il2cpp_codegen_add(G_B383_2, ((int32_t)il2cpp_codegen_multiply(G_B383_1, G_B383_0))))) > ((int32_t)((int32_t)il2cpp_codegen_multiply(8, ((int32_t)il2cpp_codegen_subtract(L_866, 1)))))))
		{
			goto IL_1a7b;
		}
	}
	{
		int32_t L_867 = __this->___mode;
		if ((!(((uint32_t)L_867) == ((uint32_t)((int32_t)1001)))))
		{
			goto IL_19e6;
		}
	}
	{
		int32_t L_868 = V_9;
		if (L_868)
		{
			goto IL_19d2;
		}
	}
	{
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_869 = V_5;
		NullCheck(L_869);
		int32_t L_870;
		L_870 = EntropyCoder_tell_m29422D894C6D91518823D9C94D3CC93ACEA2350A(L_869, NULL);
		int32_t L_871 = V_13;
		if ((((int32_t)((int32_t)il2cpp_codegen_add(L_870, ((int32_t)37)))) > ((int32_t)((int32_t)il2cpp_codegen_multiply(8, L_871)))))
		{
			goto IL_19e6;
		}
	}

IL_19d2:
	{
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_872 = V_5;
		int32_t L_873 = ___4_data_ptr;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_874;
		L_874 = Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_inline((&___3_data), L_873, Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_RuntimeMethod_var);
		int32_t L_875 = V_9;
		NullCheck(L_872);
		EntropyCoder_enc_bit_logp_mC1EAC72518B155F99BBCBEDA4B2CC46D3B411386(L_872, L_874, L_875, (uint32_t)((int32_t)12), NULL);
	}

IL_19e6:
	{
		int32_t L_876 = V_9;
		if (!L_876)
		{
			goto IL_1a7e;
		}
	}
	{
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_877 = V_5;
		int32_t L_878 = ___4_data_ptr;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_879;
		L_879 = Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_inline((&___3_data), L_878, Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_RuntimeMethod_var);
		int32_t L_880 = V_11;
		NullCheck(L_877);
		EntropyCoder_enc_bit_logp_mC1EAC72518B155F99BBCBEDA4B2CC46D3B411386(L_877, L_879, L_880, (uint32_t)1, NULL);
		int32_t L_881 = __this->___mode;
		if ((!(((uint32_t)L_881) == ((uint32_t)((int32_t)1001)))))
		{
			goto IL_1a18;
		}
	}
	{
		int32_t L_882 = V_25;
		int32_t L_883 = V_13;
		V_82 = ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_882, 1)), L_883));
		goto IL_1a2a;
	}

IL_1a18:
	{
		int32_t L_884 = V_25;
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_885 = V_5;
		NullCheck(L_885);
		int32_t L_886;
		L_886 = EntropyCoder_tell_m29422D894C6D91518823D9C94D3CC93ACEA2350A(L_885, NULL);
		V_82 = ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_884, 1)), ((int32_t)(((int32_t)il2cpp_codegen_add(L_886, 7))>>3))));
	}

IL_1a2a:
	{
		int32_t L_887 = V_82;
		int32_t L_888 = __this->___bitrate_bps;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_889;
		L_889 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(L_887, ((int32_t)(L_888/((int32_t)1600))), NULL);
		V_10 = L_889;
		int32_t L_890 = V_10;
		int32_t L_891;
		L_891 = Inlines_IMAX_mFECDD1F5C3C0962AF8B0140E78A6C3A25BCF9C23_inline(2, L_890, NULL);
		int32_t L_892;
		L_892 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)257), L_891, NULL);
		V_10 = L_892;
		int32_t L_893 = __this->___mode;
		if ((!(((uint32_t)L_893) == ((uint32_t)((int32_t)1001)))))
		{
			goto IL_1a7e;
		}
	}
	{
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_894 = V_5;
		int32_t L_895 = ___4_data_ptr;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_896;
		L_896 = Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_inline((&___3_data), L_895, Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_RuntimeMethod_var);
		int32_t L_897 = V_10;
		NullCheck(L_894);
		EntropyCoder_enc_uint_m837AC206B7D194AC7114DE24B7D5858D1D7C48AA(L_894, L_896, (uint32_t)((int32_t)il2cpp_codegen_subtract(L_897, 2)), (uint32_t)((int32_t)256), NULL);
		goto IL_1a7e;
	}

IL_1a7b:
	{
		V_9 = 0;
	}

IL_1a7e:
	{
		int32_t L_898 = V_9;
		if (L_898)
		{
			goto IL_1a8c;
		}
	}
	{
		__this->___silk_bw_switch = 0;
		V_10 = 0;
	}

IL_1a8c:
	{
		int32_t L_899 = __this->___mode;
		if ((((int32_t)L_899) == ((int32_t)((int32_t)1002))))
		{
			goto IL_1a9d;
		}
	}
	{
		V_8 = ((int32_t)17);
	}

IL_1a9d:
	{
		int32_t L_900 = __this->___mode;
		if ((!(((uint32_t)L_900) == ((uint32_t)((int32_t)1000)))))
		{
			goto IL_1acb;
		}
	}
	{
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_901 = V_5;
		NullCheck(L_901);
		int32_t L_902;
		L_902 = EntropyCoder_tell_m29422D894C6D91518823D9C94D3CC93ACEA2350A(L_901, NULL);
		V_3 = ((int32_t)(((int32_t)il2cpp_codegen_add(L_902, 7))>>3));
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_903 = V_5;
		int32_t L_904 = ___4_data_ptr;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_905;
		L_905 = Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_inline((&___3_data), L_904, Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_RuntimeMethod_var);
		NullCheck(L_903);
		EntropyCoder_enc_done_m25B7802F220D99E2CE5C1C34F99E7B8622126BCD(L_903, L_905, NULL);
		int32_t L_906 = V_3;
		V_13 = L_906;
		goto IL_1aed;
	}

IL_1acb:
	{
		int32_t L_907 = V_25;
		int32_t L_908 = V_10;
		int32_t L_909 = V_13;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_910;
		L_910 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_907, 1)), L_908)), L_909, NULL);
		V_13 = L_910;
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_911 = V_5;
		int32_t L_912 = ___4_data_ptr;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_913;
		L_913 = Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_inline((&___3_data), L_912, Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_RuntimeMethod_var);
		int32_t L_914 = V_13;
		NullCheck(L_911);
		EntropyCoder_enc_shrink_m2993D050F3B8C868157623824E04629980073C88(L_911, L_913, (uint32_t)L_914, NULL);
	}

IL_1aed:
	{
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_915 = __this->___analysis;
		NullCheck(L_915);
		bool L_916 = L_915->___enabled;
		if (!L_916)
		{
			goto IL_1afe;
		}
	}
	{
		int32_t L_917 = V_9;
		if (L_917)
		{
			goto IL_1b0b;
		}
	}

IL_1afe:
	{
		int32_t L_918 = __this->___mode;
		if ((((int32_t)L_918) == ((int32_t)((int32_t)1000))))
		{
			goto IL_1b13;
		}
	}

IL_1b0b:
	{
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_919 = V_1;
		AnalysisInfo_t7BC497BACDCB35022E1EB117D664DEC856D2A116* L_920 = V_29;
		NullCheck(L_919);
		CeltEncoder_SetAnalysis_m96468AD3A56A695114BD18D2FC056144ECDA48E5(L_919, L_920, NULL);
	}

IL_1b13:
	{
		int32_t L_921 = V_9;
		if (!L_921)
		{
			goto IL_1b61;
		}
	}
	{
		int32_t L_922 = V_11;
		if (!L_922)
		{
			goto IL_1b61;
		}
	}
	{
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_923 = V_1;
		NullCheck(L_923);
		CeltEncoder_SetStartBand_mC5BFCE123D5E277F500238D96D5042CC6630A8D7(L_923, 0, NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_924 = V_1;
		NullCheck(L_924);
		CeltEncoder_SetVBR_mB2A8CFC94909FB78E5D6B5CCEC287AE5C26748BB(L_924, (bool)0, NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_925 = V_1;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_926 = V_12;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_927;
		L_927 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_926, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_928 = __this->___Fs;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_929 = ___3_data;
		int32_t L_930 = ___4_data_ptr;
		int32_t L_931 = V_13;
		int32_t L_932 = V_10;
		NullCheck(L_925);
		int32_t L_933;
		L_933 = CeltEncoder_celt_encode_with_ec_m2FF33A330E55AB3C586618444D6615182988E8CF(L_925, L_927, 0, ((int32_t)(L_928/((int32_t)200))), L_929, ((int32_t)il2cpp_codegen_add(L_930, L_931)), L_932, (EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679*)NULL, NULL);
		if ((((int32_t)L_933) >= ((int32_t)0)))
		{
			goto IL_1b53;
		}
	}
	{
		return ((int32_t)-3);
	}

IL_1b53:
	{
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_934 = V_1;
		NullCheck(L_934);
		uint32_t L_935;
		L_935 = CeltEncoder_GetFinalRange_m4BF672C1B80DD81A5D86981BA9EB8CE699F159CF_inline(L_934, NULL);
		V_15 = L_935;
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_936 = V_1;
		NullCheck(L_936);
		CeltEncoder_ResetState_m1C30EBAD2FA89D556072892E54D8414AC010618B(L_936, NULL);
	}

IL_1b61:
	{
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_937 = V_1;
		int32_t L_938 = V_8;
		NullCheck(L_937);
		CeltEncoder_SetStartBand_mC5BFCE123D5E277F500238D96D5042CC6630A8D7(L_937, L_938, NULL);
		int32_t L_939 = __this->___mode;
		if ((((int32_t)L_939) == ((int32_t)((int32_t)1000))))
		{
			goto IL_1bfb;
		}
	}
	{
		int32_t L_940 = __this->___mode;
		int32_t L_941 = __this->___prev_mode;
		if ((((int32_t)L_940) == ((int32_t)L_941)))
		{
			goto IL_1bc9;
		}
	}
	{
		int32_t L_942 = __this->___prev_mode;
		if ((((int32_t)L_942) <= ((int32_t)0)))
		{
			goto IL_1bc9;
		}
	}
	{
		uintptr_t L_943 = ((uintptr_t)2);
		int8_t* L_944 = (int8_t*) (L_943 ? alloca(L_943) : NULL);
		memset(L_944, 0, L_943);
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_945;
		memset((&L_945), 0, sizeof(L_945));
		Span_1__ctor_mE18EBB601FBFA01BA29FE353364700952A9091FE_inline((&L_945), (void*)(L_944), 2, Span_1__ctor_mE18EBB601FBFA01BA29FE353364700952A9091FE_RuntimeMethod_var);
		V_83 = L_945;
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_946 = V_1;
		NullCheck(L_946);
		CeltEncoder_ResetState_m1C30EBAD2FA89D556072892E54D8414AC010618B(L_946, NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_947 = V_1;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_948 = V_32;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_949;
		L_949 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_948, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_950 = __this->___Fs;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_951 = V_83;
		NullCheck(L_947);
		int32_t L_952;
		L_952 = CeltEncoder_celt_encode_with_ec_m2FF33A330E55AB3C586618444D6615182988E8CF(L_947, L_949, 0, ((int32_t)(L_950/((int32_t)400))), L_951, 0, 2, (EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679*)NULL, NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_953 = V_1;
		NullCheck(L_953);
		CeltEncoder_SetPrediction_m880E0433982007C125828ED68A45A4A134798EB4(L_953, 0, NULL);
	}

IL_1bc9:
	{
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_954 = V_5;
		NullCheck(L_954);
		int32_t L_955;
		L_955 = EntropyCoder_tell_m29422D894C6D91518823D9C94D3CC93ACEA2350A(L_954, NULL);
		int32_t L_956 = V_13;
		if ((((int32_t)L_955) > ((int32_t)((int32_t)il2cpp_codegen_multiply(8, L_956)))))
		{
			goto IL_1bfb;
		}
	}
	{
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_957 = V_1;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_958 = V_12;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_959;
		L_959 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_958, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_960 = ___2_frame_size;
		int32_t L_961 = ___4_data_ptr;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_962;
		L_962 = Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_inline((&___3_data), L_961, Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_RuntimeMethod_var);
		int32_t L_963 = V_13;
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_964 = V_5;
		NullCheck(L_957);
		int32_t L_965;
		L_965 = CeltEncoder_celt_encode_with_ec_m2FF33A330E55AB3C586618444D6615182988E8CF(L_957, L_959, 0, L_960, L_962, 0, L_963, L_964, NULL);
		V_3 = L_965;
		int32_t L_966 = V_3;
		if ((((int32_t)L_966) >= ((int32_t)0)))
		{
			goto IL_1bfb;
		}
	}
	{
		return ((int32_t)-3);
	}

IL_1bfb:
	{
		int32_t L_967 = V_9;
		if (!L_967)
		{
			goto IL_1c9a;
		}
	}
	{
		int32_t L_968 = V_11;
		if (L_968)
		{
			goto IL_1c9a;
		}
	}
	{
		uintptr_t L_969 = ((uintptr_t)2);
		int8_t* L_970 = (int8_t*) (L_969 ? alloca(L_969) : NULL);
		memset(L_970, 0, L_969);
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_971;
		memset((&L_971), 0, sizeof(L_971));
		Span_1__ctor_mE18EBB601FBFA01BA29FE353364700952A9091FE_inline((&L_971), (void*)(L_970), 2, Span_1__ctor_mE18EBB601FBFA01BA29FE353364700952A9091FE_RuntimeMethod_var);
		V_84 = L_971;
		int32_t L_972 = __this->___Fs;
		V_85 = ((int32_t)(L_972/((int32_t)200)));
		int32_t L_973 = __this->___Fs;
		V_86 = ((int32_t)(L_973/((int32_t)400)));
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_974 = V_1;
		NullCheck(L_974);
		CeltEncoder_ResetState_m1C30EBAD2FA89D556072892E54D8414AC010618B(L_974, NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_975 = V_1;
		NullCheck(L_975);
		CeltEncoder_SetStartBand_mC5BFCE123D5E277F500238D96D5042CC6630A8D7(L_975, 0, NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_976 = V_1;
		NullCheck(L_976);
		CeltEncoder_SetPrediction_m880E0433982007C125828ED68A45A4A134798EB4(L_976, 0, NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_977 = V_1;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_978 = V_12;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_979;
		L_979 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_978, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_980 = __this->___channels;
		int32_t L_981 = ___2_frame_size;
		int32_t L_982 = V_85;
		int32_t L_983 = V_86;
		int32_t L_984 = V_86;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_985 = V_84;
		NullCheck(L_977);
		int32_t L_986;
		L_986 = CeltEncoder_celt_encode_with_ec_m2FF33A330E55AB3C586618444D6615182988E8CF(L_977, L_979, ((int32_t)il2cpp_codegen_multiply(L_980, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_981, L_982)), L_983)))), L_984, L_985, 0, 2, (EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679*)NULL, NULL);
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_987 = V_1;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_988 = V_12;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_989;
		L_989 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_988, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_990 = __this->___channels;
		int32_t L_991 = ___2_frame_size;
		int32_t L_992 = V_85;
		int32_t L_993 = V_85;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_994 = ___3_data;
		int32_t L_995 = ___4_data_ptr;
		int32_t L_996 = V_13;
		int32_t L_997 = V_10;
		NullCheck(L_987);
		int32_t L_998;
		L_998 = CeltEncoder_celt_encode_with_ec_m2FF33A330E55AB3C586618444D6615182988E8CF(L_987, L_989, ((int32_t)il2cpp_codegen_multiply(L_990, ((int32_t)il2cpp_codegen_subtract(L_991, L_992)))), L_993, L_994, ((int32_t)il2cpp_codegen_add(L_995, L_996)), L_997, (EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679*)NULL, NULL);
		if ((((int32_t)L_998) >= ((int32_t)0)))
		{
			goto IL_1c92;
		}
	}
	{
		return ((int32_t)-3);
	}

IL_1c92:
	{
		CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* L_999 = V_1;
		NullCheck(L_999);
		uint32_t L_1000;
		L_1000 = CeltEncoder_GetFinalRange_m4BF672C1B80DD81A5D86981BA9EB8CE699F159CF_inline(L_999, NULL);
		V_15 = L_1000;
	}

IL_1c9a:
	{
		int32_t L_1001 = ___4_data_ptr;
		___4_data_ptr = ((int32_t)il2cpp_codegen_subtract(L_1001, 1));
		int32_t L_1002 = ___4_data_ptr;
		uint8_t* L_1003;
		L_1003 = il2cpp_span_get_item((uint8_t*)((Il2CppByReference*)&(((&___3_data))->____pointer))->value, (L_1002), ((&___3_data))->____length);
		int32_t L_1004 = __this->___mode;
		int32_t L_1005 = __this->___Fs;
		int32_t L_1006 = ___2_frame_size;
		int32_t L_1007 = V_23;
		int32_t L_1008 = __this->___stream_channels;
		uint8_t L_1009;
		L_1009 = CodecHelpers_gen_toc_m55919D0EC27589F5328AD925AA91F8B0D4A9EBA2(L_1004, ((int32_t)(L_1005/L_1006)), L_1007, L_1008, NULL);
		*((int8_t*)L_1003) = (int8_t)L_1009;
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_1010 = V_5;
		NullCheck(L_1010);
		uint32_t L_1011 = L_1010->___rng;
		uint32_t L_1012 = V_15;
		__this->___rangeFinal = (uint32_t)((int32_t)((int32_t)L_1011^(int32_t)L_1012));
		int32_t L_1013 = V_14;
		if (!L_1013)
		{
			goto IL_1ce6;
		}
	}
	{
		__this->___prev_mode = (int32_t)((int32_t)1002);
		goto IL_1cf2;
	}

IL_1ce6:
	{
		int32_t L_1014 = __this->___mode;
		__this->___prev_mode = L_1014;
	}

IL_1cf2:
	{
		int32_t L_1015 = __this->___stream_channels;
		__this->___prev_channels = L_1015;
		int32_t L_1016 = ___2_frame_size;
		__this->___prev_framesize = L_1016;
		__this->___first = 0;
		EntropyCoder_t119A7D27E3812CA689C1E43EA9DE65769A403679* L_1017 = V_5;
		NullCheck(L_1017);
		int32_t L_1018;
		L_1018 = EntropyCoder_tell_m29422D894C6D91518823D9C94D3CC93ACEA2350A(L_1017, NULL);
		int32_t L_1019 = V_25;
		if ((((int32_t)L_1018) <= ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_subtract(L_1019, 1)), 8)))))
		{
			goto IL_1d3b;
		}
	}
	{
		int32_t L_1020 = V_25;
		if ((((int32_t)L_1020) >= ((int32_t)2)))
		{
			goto IL_1d23;
		}
	}
	{
		return ((int32_t)-2);
	}

IL_1d23:
	{
		int32_t L_1021 = ___4_data_ptr;
		uint8_t* L_1022;
		L_1022 = il2cpp_span_get_item((uint8_t*)((Il2CppByReference*)&(((&___3_data))->____pointer))->value, (((int32_t)il2cpp_codegen_add(L_1021, 1))), ((&___3_data))->____length);
		*((int8_t*)L_1022) = (int8_t)0;
		V_3 = 1;
		__this->___rangeFinal = (uint32_t)0;
		goto IL_1d64;
	}

IL_1d3b:
	{
		int32_t L_1023 = __this->___mode;
		if ((!(((uint32_t)L_1023) == ((uint32_t)((int32_t)1000)))))
		{
			goto IL_1d64;
		}
	}
	{
		int32_t L_1024 = V_9;
		if (L_1024)
		{
			goto IL_1d64;
		}
	}
	{
		goto IL_1d52;
	}

IL_1d4e:
	{
		int32_t L_1025 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_1025, 1));
	}

IL_1d52:
	{
		int32_t L_1026 = V_3;
		if ((((int32_t)L_1026) <= ((int32_t)2)))
		{
			goto IL_1d64;
		}
	}
	{
		int32_t L_1027 = ___4_data_ptr;
		int32_t L_1028 = V_3;
		uint8_t* L_1029;
		L_1029 = il2cpp_span_get_item((uint8_t*)((Il2CppByReference*)&(((&___3_data))->____pointer))->value, (((int32_t)il2cpp_codegen_add(L_1027, L_1028))), ((&___3_data))->____length);
		int32_t L_1030 = *((uint8_t*)L_1029);
		if (!L_1030)
		{
			goto IL_1d4e;
		}
	}

IL_1d64:
	{
		int32_t L_1031 = V_3;
		int32_t L_1032 = V_10;
		V_3 = ((int32_t)il2cpp_codegen_add(L_1031, ((int32_t)il2cpp_codegen_add(1, L_1032))));
		int32_t L_1033 = __this->___use_vbr;
		if (L_1033)
		{
			goto IL_1d87;
		}
	}
	{
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_1034 = ___3_data;
		int32_t L_1035 = ___4_data_ptr;
		int32_t L_1036 = V_3;
		int32_t L_1037 = V_25;
		int32_t L_1038;
		L_1038 = OpusRepacketizer_PadPacket_m31BC672C1100238AAE7DF0EEC74000D8CD39AD8E(L_1034, L_1035, L_1036, L_1037, NULL);
		if (!L_1038)
		{
			goto IL_1d84;
		}
	}
	{
		return ((int32_t)-3);
	}

IL_1d84:
	{
		int32_t L_1039 = V_25;
		V_3 = L_1039;
	}

IL_1d87:
	{
		int32_t L_1040 = V_3;
		return L_1040;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusMSDecoder_opus_multistream_decode_native_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m17FDF4530AE3141CD35A1483D7CAF7BFC92B17F6_gshared (OpusMSDecoder_tA24EBFD8B5A8C5D6C12AABAE8403EF562FFBA83A* __this, ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D ___0_data, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D ___1_pcm, opus_copy_channel_out_func_1_t2805945BE854CD39521CBB1514A4097CC0333344* ___2_copy_channel_out, int32_t ___3_frame_size, int32_t ___4_decode_fec, int32_t ___5_soft_clip, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* V_5 = NULL;
	int32_t V_6 = 0;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* V_9 = NULL;
	int32_t V_10 = 0;
	int32_t V_11 = 0;
	int32_t V_12 = 0;
	int32_t V_13 = 0;
	int32_t V_14 = 0;
	int32_t V_15 = 0;
	int32_t G_B18_0 = 0;
	int32_t G_B18_1 = 0;
	int32_t G_B18_2 = 0;
	Span_1_tC1B695440A1567664C2665D76D5614739FDF453D G_B18_3;
	memset((&G_B18_3), 0, sizeof(G_B18_3));
	int32_t G_B18_4 = 0;
	int32_t G_B18_5 = 0;
	ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D G_B18_6;
	memset((&G_B18_6), 0, sizeof(G_B18_6));
	OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* G_B18_7 = NULL;
	int32_t G_B17_0 = 0;
	int32_t G_B17_1 = 0;
	int32_t G_B17_2 = 0;
	Span_1_tC1B695440A1567664C2665D76D5614739FDF453D G_B17_3;
	memset((&G_B17_3), 0, sizeof(G_B17_3));
	int32_t G_B17_4 = 0;
	int32_t G_B17_5 = 0;
	ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D G_B17_6;
	memset((&G_B17_6), 0, sizeof(G_B17_6));
	OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* G_B17_7 = NULL;
	int32_t G_B19_0 = 0;
	int32_t G_B19_1 = 0;
	int32_t G_B19_2 = 0;
	int32_t G_B19_3 = 0;
	Span_1_tC1B695440A1567664C2665D76D5614739FDF453D G_B19_4;
	memset((&G_B19_4), 0, sizeof(G_B19_4));
	int32_t G_B19_5 = 0;
	int32_t G_B19_6 = 0;
	ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D G_B19_7;
	memset((&G_B19_7), 0, sizeof(G_B19_7));
	OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* G_B19_8 = NULL;
	{
		V_4 = 0;
		int32_t L_0;
		L_0 = OpusMSDecoder_get_SampleRate_m00241E93F2188AB42BCE48A4A6191386EB16BB86(__this, NULL);
		V_0 = L_0;
		int32_t L_1 = ___3_frame_size;
		int32_t L_2 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(L_1, ((int32_t)il2cpp_codegen_multiply(((int32_t)(L_2/((int32_t)25))), 3)), NULL);
		___3_frame_size = L_3;
		int32_t L_4 = ___3_frame_size;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_5 = (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)SZArrayNew(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(2, L_4)));
		V_5 = L_5;
		V_3 = 0;
		int32_t L_6;
		L_6 = ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_inline((&___0_data), ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_RuntimeMethod_var);
		if (L_6)
		{
			goto IL_0032;
		}
	}
	{
		V_4 = 1;
	}

IL_0032:
	{
		int32_t L_7;
		L_7 = ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_inline((&___0_data), ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_RuntimeMethod_var);
		if ((((int32_t)L_7) >= ((int32_t)0)))
		{
			goto IL_003e;
		}
	}
	{
		return (-1);
	}

IL_003e:
	{
		int32_t L_8 = V_4;
		if (L_8)
		{
			goto IL_005d;
		}
	}
	{
		int32_t L_9;
		L_9 = ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_inline((&___0_data), ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_RuntimeMethod_var);
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_10 = __this->___layout;
		NullCheck(L_10);
		int32_t L_11 = L_10->___nb_streams;
		if ((((int32_t)L_9) >= ((int32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_multiply(2, L_11)), 1)))))
		{
			goto IL_005d;
		}
	}
	{
		return ((int32_t)-4);
	}

IL_005d:
	{
		int32_t L_12 = V_4;
		if (L_12)
		{
			goto IL_0086;
		}
	}
	{
		ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D L_13 = ___0_data;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_14 = __this->___layout;
		NullCheck(L_14);
		int32_t L_15 = L_14->___nb_streams;
		int32_t L_16 = V_0;
		int32_t L_17;
		L_17 = OpusMSDecoder_opus_multistream_packet_validate_m3E2D2CF1B4A698FD791C8A3BA0C3A2E605A22CC6(L_13, L_15, L_16, NULL);
		V_8 = L_17;
		int32_t L_18 = V_8;
		if ((((int32_t)L_18) >= ((int32_t)0)))
		{
			goto IL_007d;
		}
	}
	{
		int32_t L_19 = V_8;
		return L_19;
	}

IL_007d:
	{
		int32_t L_20 = V_8;
		int32_t L_21 = ___3_frame_size;
		if ((((int32_t)L_20) <= ((int32_t)L_21)))
		{
			goto IL_0086;
		}
	}
	{
		return ((int32_t)-2);
	}

IL_0086:
	{
		V_6 = 0;
		int32_t L_22;
		L_22 = ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_inline((&___0_data), ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_RuntimeMethod_var);
		V_7 = L_22;
		V_1 = 0;
		goto IL_01cc;
	}

IL_0099:
	{
		OpusDecoderU5BU5D_t208A6B826C1F7F0CEAEEF2F4D4AA5844540C59D1* L_23 = __this->___decoders;
		int32_t L_24 = V_3;
		int32_t L_25 = L_24;
		V_3 = ((int32_t)il2cpp_codegen_add(L_25, 1));
		NullCheck(L_23);
		int32_t L_26 = L_25;
		OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* L_27 = (L_23)->GetAt(static_cast<il2cpp_array_size_t>(L_26));
		V_9 = L_27;
		int32_t L_28 = V_4;
		if (L_28)
		{
			goto IL_00b8;
		}
	}
	{
		int32_t L_29;
		L_29 = ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_inline((&___0_data), ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_RuntimeMethod_var);
		if ((((int32_t)L_29) > ((int32_t)0)))
		{
			goto IL_00b8;
		}
	}
	{
		return ((int32_t)-3);
	}

IL_00b8:
	{
		OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* L_30 = V_9;
		ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D L_31 = ___0_data;
		int32_t L_32 = V_6;
		int32_t L_33 = V_7;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_34 = V_5;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_35;
		L_35 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_34, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_36 = ___3_frame_size;
		int32_t L_37 = ___4_decode_fec;
		int32_t L_38 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_39 = __this->___layout;
		NullCheck(L_39);
		int32_t L_40 = L_39->___nb_streams;
		if ((!(((uint32_t)L_38) == ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_40, 1))))))
		{
			G_B18_0 = L_37;
			G_B18_1 = L_36;
			G_B18_2 = 0;
			G_B18_3 = L_35;
			G_B18_4 = L_33;
			G_B18_5 = L_32;
			G_B18_6 = L_31;
			G_B18_7 = L_30;
			goto IL_00de;
		}
		G_B17_0 = L_37;
		G_B17_1 = L_36;
		G_B17_2 = 0;
		G_B17_3 = L_35;
		G_B17_4 = L_33;
		G_B17_5 = L_32;
		G_B17_6 = L_31;
		G_B17_7 = L_30;
	}
	{
		G_B19_0 = 0;
		G_B19_1 = G_B17_0;
		G_B19_2 = G_B17_1;
		G_B19_3 = G_B17_2;
		G_B19_4 = G_B17_3;
		G_B19_5 = G_B17_4;
		G_B19_6 = G_B17_5;
		G_B19_7 = G_B17_6;
		G_B19_8 = G_B17_7;
		goto IL_00df;
	}

IL_00de:
	{
		G_B19_0 = 1;
		G_B19_1 = G_B18_0;
		G_B19_2 = G_B18_1;
		G_B19_3 = G_B18_2;
		G_B19_4 = G_B18_3;
		G_B19_5 = G_B18_4;
		G_B19_6 = G_B18_5;
		G_B19_7 = G_B18_6;
		G_B19_8 = G_B18_7;
	}

IL_00df:
	{
		int32_t L_41 = ___5_soft_clip;
		NullCheck(G_B19_8);
		int32_t L_42;
		L_42 = OpusDecoder_opus_decode_native_m226953E91BEF13C44CF5706AFD0B3238251F9567(G_B19_8, G_B19_7, G_B19_6, G_B19_5, G_B19_4, G_B19_3, G_B19_2, G_B19_1, G_B19_0, (&V_11), L_41, NULL);
		V_10 = L_42;
		int32_t L_43 = V_6;
		int32_t L_44 = V_11;
		V_6 = ((int32_t)il2cpp_codegen_add(L_43, L_44));
		int32_t L_45 = V_7;
		int32_t L_46 = V_11;
		V_7 = ((int32_t)il2cpp_codegen_subtract(L_45, L_46));
		int32_t L_47 = V_10;
		if ((((int32_t)L_47) > ((int32_t)0)))
		{
			goto IL_0100;
		}
	}
	{
		int32_t L_48 = V_10;
		return L_48;
	}

IL_0100:
	{
		int32_t L_49 = V_10;
		___3_frame_size = L_49;
		int32_t L_50 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_51 = __this->___layout;
		NullCheck(L_51);
		int32_t L_52 = L_51->___nb_coupled_streams;
		if ((((int32_t)L_50) >= ((int32_t)L_52)))
		{
			goto IL_018c;
		}
	}
	{
		V_13 = (-1);
		goto IL_013a;
	}

IL_0117:
	{
		opus_copy_channel_out_func_1_t2805945BE854CD39521CBB1514A4097CC0333344* L_53 = ___2_copy_channel_out;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_54 = ___1_pcm;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_55 = __this->___layout;
		NullCheck(L_55);
		int32_t L_56 = L_55->___nb_channels;
		int32_t L_57 = V_12;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_58 = V_5;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_59;
		L_59 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_58, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_60 = ___3_frame_size;
		NullCheck(L_53);
		opus_copy_channel_out_func_1_Invoke_m25EF632F19B8D56B7FB9C58D141E42FED126F81D_inline(L_53, L_54, L_56, L_57, L_59, 0, 2, L_60, il2cpp_rgctx_method(method->rgctx_data, 2));
		int32_t L_61 = V_12;
		V_13 = L_61;
	}

IL_013a:
	{
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_62 = __this->___layout;
		int32_t L_63 = V_1;
		int32_t L_64 = V_13;
		int32_t L_65;
		L_65 = OpusMultistream_get_left_channel_mBC9BCAA485D1095C537AA8A8DFB38355DCB06A04(L_62, L_63, L_64, NULL);
		int32_t L_66 = L_65;
		V_12 = L_66;
		if ((!(((uint32_t)L_66) == ((uint32_t)(-1)))))
		{
			goto IL_0117;
		}
	}
	{
		V_13 = (-1);
		goto IL_0176;
	}

IL_0153:
	{
		opus_copy_channel_out_func_1_t2805945BE854CD39521CBB1514A4097CC0333344* L_67 = ___2_copy_channel_out;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_68 = ___1_pcm;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_69 = __this->___layout;
		NullCheck(L_69);
		int32_t L_70 = L_69->___nb_channels;
		int32_t L_71 = V_12;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_72 = V_5;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_73;
		L_73 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_72, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_74 = ___3_frame_size;
		NullCheck(L_67);
		opus_copy_channel_out_func_1_Invoke_m25EF632F19B8D56B7FB9C58D141E42FED126F81D_inline(L_67, L_68, L_70, L_71, L_73, 1, 2, L_74, il2cpp_rgctx_method(method->rgctx_data, 2));
		int32_t L_75 = V_12;
		V_13 = L_75;
	}

IL_0176:
	{
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_76 = __this->___layout;
		int32_t L_77 = V_1;
		int32_t L_78 = V_13;
		int32_t L_79;
		L_79 = OpusMultistream_get_right_channel_m1F24FA4BC9F11ADF386C3B9CAB948C1EBCC95C3F(L_76, L_77, L_78, NULL);
		int32_t L_80 = L_79;
		V_12 = L_80;
		if ((!(((uint32_t)L_80) == ((uint32_t)(-1)))))
		{
			goto IL_0153;
		}
	}
	{
		goto IL_01c8;
	}

IL_018c:
	{
		V_15 = (-1);
		goto IL_01b4;
	}

IL_0191:
	{
		opus_copy_channel_out_func_1_t2805945BE854CD39521CBB1514A4097CC0333344* L_81 = ___2_copy_channel_out;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_82 = ___1_pcm;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_83 = __this->___layout;
		NullCheck(L_83);
		int32_t L_84 = L_83->___nb_channels;
		int32_t L_85 = V_14;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_86 = V_5;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_87;
		L_87 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_86, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_88 = ___3_frame_size;
		NullCheck(L_81);
		opus_copy_channel_out_func_1_Invoke_m25EF632F19B8D56B7FB9C58D141E42FED126F81D_inline(L_81, L_82, L_84, L_85, L_87, 0, 1, L_88, il2cpp_rgctx_method(method->rgctx_data, 2));
		int32_t L_89 = V_14;
		V_15 = L_89;
	}

IL_01b4:
	{
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_90 = __this->___layout;
		int32_t L_91 = V_1;
		int32_t L_92 = V_15;
		int32_t L_93;
		L_93 = OpusMultistream_get_mono_channel_mD28CFC9E8DF9F999251643576CECC59C132EA292(L_90, L_91, L_92, NULL);
		int32_t L_94 = L_93;
		V_14 = L_94;
		if ((!(((uint32_t)L_94) == ((uint32_t)(-1)))))
		{
			goto IL_0191;
		}
	}

IL_01c8:
	{
		int32_t L_95 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_95, 1));
	}

IL_01cc:
	{
		int32_t L_96 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_97 = __this->___layout;
		NullCheck(L_97);
		int32_t L_98 = L_97->___nb_streams;
		if ((((int32_t)L_96) < ((int32_t)L_98)))
		{
			goto IL_0099;
		}
	}
	{
		V_2 = 0;
		goto IL_0216;
	}

IL_01e1:
	{
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_99 = __this->___layout;
		NullCheck(L_99);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_100 = L_99->___mapping;
		int32_t L_101 = V_2;
		NullCheck(L_100);
		int32_t L_102 = L_101;
		uint8_t L_103 = (L_100)->GetAt(static_cast<il2cpp_array_size_t>(L_102));
		if ((!(((uint32_t)L_103) == ((uint32_t)((int32_t)255)))))
		{
			goto IL_0212;
		}
	}
	{
		opus_copy_channel_out_func_1_t2805945BE854CD39521CBB1514A4097CC0333344* L_104 = ___2_copy_channel_out;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_105 = ___1_pcm;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_106 = __this->___layout;
		NullCheck(L_106);
		int32_t L_107 = L_106->___nb_channels;
		int32_t L_108 = V_2;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_109;
		L_109 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D((Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)NULL, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_110 = ___3_frame_size;
		NullCheck(L_104);
		opus_copy_channel_out_func_1_Invoke_m25EF632F19B8D56B7FB9C58D141E42FED126F81D_inline(L_104, L_105, L_107, L_108, L_109, 0, 0, L_110, il2cpp_rgctx_method(method->rgctx_data, 2));
	}

IL_0212:
	{
		int32_t L_111 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_111, 1));
	}

IL_0216:
	{
		int32_t L_112 = V_2;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_113 = __this->___layout;
		NullCheck(L_113);
		int32_t L_114 = L_113->___nb_channels;
		if ((((int32_t)L_112) < ((int32_t)L_114)))
		{
			goto IL_01e1;
		}
	}
	{
		int32_t L_115 = ___3_frame_size;
		return L_115;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusMSDecoder_opus_multistream_decode_native_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m88ACF2C0B07DB5D069E604471ED4BB18CC1A26D4_gshared (OpusMSDecoder_tA24EBFD8B5A8C5D6C12AABAE8403EF562FFBA83A* __this, ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D ___0_data, Span_1_t7578EBC2679C3216D7A6FA0DAECAF2256A33CF4C ___1_pcm, opus_copy_channel_out_func_1_t85951F56EF7450B05E135DF219F8BF05B4D5E030* ___2_copy_channel_out, int32_t ___3_frame_size, int32_t ___4_decode_fec, int32_t ___5_soft_clip, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* V_5 = NULL;
	int32_t V_6 = 0;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* V_9 = NULL;
	int32_t V_10 = 0;
	int32_t V_11 = 0;
	int32_t V_12 = 0;
	int32_t V_13 = 0;
	int32_t V_14 = 0;
	int32_t V_15 = 0;
	int32_t G_B18_0 = 0;
	int32_t G_B18_1 = 0;
	int32_t G_B18_2 = 0;
	Span_1_tC1B695440A1567664C2665D76D5614739FDF453D G_B18_3;
	memset((&G_B18_3), 0, sizeof(G_B18_3));
	int32_t G_B18_4 = 0;
	int32_t G_B18_5 = 0;
	ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D G_B18_6;
	memset((&G_B18_6), 0, sizeof(G_B18_6));
	OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* G_B18_7 = NULL;
	int32_t G_B17_0 = 0;
	int32_t G_B17_1 = 0;
	int32_t G_B17_2 = 0;
	Span_1_tC1B695440A1567664C2665D76D5614739FDF453D G_B17_3;
	memset((&G_B17_3), 0, sizeof(G_B17_3));
	int32_t G_B17_4 = 0;
	int32_t G_B17_5 = 0;
	ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D G_B17_6;
	memset((&G_B17_6), 0, sizeof(G_B17_6));
	OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* G_B17_7 = NULL;
	int32_t G_B19_0 = 0;
	int32_t G_B19_1 = 0;
	int32_t G_B19_2 = 0;
	int32_t G_B19_3 = 0;
	Span_1_tC1B695440A1567664C2665D76D5614739FDF453D G_B19_4;
	memset((&G_B19_4), 0, sizeof(G_B19_4));
	int32_t G_B19_5 = 0;
	int32_t G_B19_6 = 0;
	ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D G_B19_7;
	memset((&G_B19_7), 0, sizeof(G_B19_7));
	OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* G_B19_8 = NULL;
	{
		V_4 = 0;
		int32_t L_0;
		L_0 = OpusMSDecoder_get_SampleRate_m00241E93F2188AB42BCE48A4A6191386EB16BB86(__this, NULL);
		V_0 = L_0;
		int32_t L_1 = ___3_frame_size;
		int32_t L_2 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(L_1, ((int32_t)il2cpp_codegen_multiply(((int32_t)(L_2/((int32_t)25))), 3)), NULL);
		___3_frame_size = L_3;
		int32_t L_4 = ___3_frame_size;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_5 = (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)SZArrayNew(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(2, L_4)));
		V_5 = L_5;
		V_3 = 0;
		int32_t L_6;
		L_6 = ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_inline((&___0_data), ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_RuntimeMethod_var);
		if (L_6)
		{
			goto IL_0032;
		}
	}
	{
		V_4 = 1;
	}

IL_0032:
	{
		int32_t L_7;
		L_7 = ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_inline((&___0_data), ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_RuntimeMethod_var);
		if ((((int32_t)L_7) >= ((int32_t)0)))
		{
			goto IL_003e;
		}
	}
	{
		return (-1);
	}

IL_003e:
	{
		int32_t L_8 = V_4;
		if (L_8)
		{
			goto IL_005d;
		}
	}
	{
		int32_t L_9;
		L_9 = ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_inline((&___0_data), ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_RuntimeMethod_var);
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_10 = __this->___layout;
		NullCheck(L_10);
		int32_t L_11 = L_10->___nb_streams;
		if ((((int32_t)L_9) >= ((int32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_multiply(2, L_11)), 1)))))
		{
			goto IL_005d;
		}
	}
	{
		return ((int32_t)-4);
	}

IL_005d:
	{
		int32_t L_12 = V_4;
		if (L_12)
		{
			goto IL_0086;
		}
	}
	{
		ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D L_13 = ___0_data;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_14 = __this->___layout;
		NullCheck(L_14);
		int32_t L_15 = L_14->___nb_streams;
		int32_t L_16 = V_0;
		int32_t L_17;
		L_17 = OpusMSDecoder_opus_multistream_packet_validate_m3E2D2CF1B4A698FD791C8A3BA0C3A2E605A22CC6(L_13, L_15, L_16, NULL);
		V_8 = L_17;
		int32_t L_18 = V_8;
		if ((((int32_t)L_18) >= ((int32_t)0)))
		{
			goto IL_007d;
		}
	}
	{
		int32_t L_19 = V_8;
		return L_19;
	}

IL_007d:
	{
		int32_t L_20 = V_8;
		int32_t L_21 = ___3_frame_size;
		if ((((int32_t)L_20) <= ((int32_t)L_21)))
		{
			goto IL_0086;
		}
	}
	{
		return ((int32_t)-2);
	}

IL_0086:
	{
		V_6 = 0;
		int32_t L_22;
		L_22 = ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_inline((&___0_data), ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_RuntimeMethod_var);
		V_7 = L_22;
		V_1 = 0;
		goto IL_01cc;
	}

IL_0099:
	{
		OpusDecoderU5BU5D_t208A6B826C1F7F0CEAEEF2F4D4AA5844540C59D1* L_23 = __this->___decoders;
		int32_t L_24 = V_3;
		int32_t L_25 = L_24;
		V_3 = ((int32_t)il2cpp_codegen_add(L_25, 1));
		NullCheck(L_23);
		int32_t L_26 = L_25;
		OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* L_27 = (L_23)->GetAt(static_cast<il2cpp_array_size_t>(L_26));
		V_9 = L_27;
		int32_t L_28 = V_4;
		if (L_28)
		{
			goto IL_00b8;
		}
	}
	{
		int32_t L_29;
		L_29 = ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_inline((&___0_data), ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_RuntimeMethod_var);
		if ((((int32_t)L_29) > ((int32_t)0)))
		{
			goto IL_00b8;
		}
	}
	{
		return ((int32_t)-3);
	}

IL_00b8:
	{
		OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* L_30 = V_9;
		ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D L_31 = ___0_data;
		int32_t L_32 = V_6;
		int32_t L_33 = V_7;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_34 = V_5;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_35;
		L_35 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_34, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_36 = ___3_frame_size;
		int32_t L_37 = ___4_decode_fec;
		int32_t L_38 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_39 = __this->___layout;
		NullCheck(L_39);
		int32_t L_40 = L_39->___nb_streams;
		if ((!(((uint32_t)L_38) == ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_40, 1))))))
		{
			G_B18_0 = L_37;
			G_B18_1 = L_36;
			G_B18_2 = 0;
			G_B18_3 = L_35;
			G_B18_4 = L_33;
			G_B18_5 = L_32;
			G_B18_6 = L_31;
			G_B18_7 = L_30;
			goto IL_00de;
		}
		G_B17_0 = L_37;
		G_B17_1 = L_36;
		G_B17_2 = 0;
		G_B17_3 = L_35;
		G_B17_4 = L_33;
		G_B17_5 = L_32;
		G_B17_6 = L_31;
		G_B17_7 = L_30;
	}
	{
		G_B19_0 = 0;
		G_B19_1 = G_B17_0;
		G_B19_2 = G_B17_1;
		G_B19_3 = G_B17_2;
		G_B19_4 = G_B17_3;
		G_B19_5 = G_B17_4;
		G_B19_6 = G_B17_5;
		G_B19_7 = G_B17_6;
		G_B19_8 = G_B17_7;
		goto IL_00df;
	}

IL_00de:
	{
		G_B19_0 = 1;
		G_B19_1 = G_B18_0;
		G_B19_2 = G_B18_1;
		G_B19_3 = G_B18_2;
		G_B19_4 = G_B18_3;
		G_B19_5 = G_B18_4;
		G_B19_6 = G_B18_5;
		G_B19_7 = G_B18_6;
		G_B19_8 = G_B18_7;
	}

IL_00df:
	{
		int32_t L_41 = ___5_soft_clip;
		NullCheck(G_B19_8);
		int32_t L_42;
		L_42 = OpusDecoder_opus_decode_native_m226953E91BEF13C44CF5706AFD0B3238251F9567(G_B19_8, G_B19_7, G_B19_6, G_B19_5, G_B19_4, G_B19_3, G_B19_2, G_B19_1, G_B19_0, (&V_11), L_41, NULL);
		V_10 = L_42;
		int32_t L_43 = V_6;
		int32_t L_44 = V_11;
		V_6 = ((int32_t)il2cpp_codegen_add(L_43, L_44));
		int32_t L_45 = V_7;
		int32_t L_46 = V_11;
		V_7 = ((int32_t)il2cpp_codegen_subtract(L_45, L_46));
		int32_t L_47 = V_10;
		if ((((int32_t)L_47) > ((int32_t)0)))
		{
			goto IL_0100;
		}
	}
	{
		int32_t L_48 = V_10;
		return L_48;
	}

IL_0100:
	{
		int32_t L_49 = V_10;
		___3_frame_size = L_49;
		int32_t L_50 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_51 = __this->___layout;
		NullCheck(L_51);
		int32_t L_52 = L_51->___nb_coupled_streams;
		if ((((int32_t)L_50) >= ((int32_t)L_52)))
		{
			goto IL_018c;
		}
	}
	{
		V_13 = (-1);
		goto IL_013a;
	}

IL_0117:
	{
		opus_copy_channel_out_func_1_t85951F56EF7450B05E135DF219F8BF05B4D5E030* L_53 = ___2_copy_channel_out;
		Span_1_t7578EBC2679C3216D7A6FA0DAECAF2256A33CF4C L_54 = ___1_pcm;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_55 = __this->___layout;
		NullCheck(L_55);
		int32_t L_56 = L_55->___nb_channels;
		int32_t L_57 = V_12;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_58 = V_5;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_59;
		L_59 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_58, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_60 = ___3_frame_size;
		NullCheck(L_53);
		opus_copy_channel_out_func_1_Invoke_mB9C23E8CD1EED40F2F28F55B16E7F42E95D95441_inline(L_53, L_54, L_56, L_57, L_59, 0, 2, L_60, il2cpp_rgctx_method(method->rgctx_data, 2));
		int32_t L_61 = V_12;
		V_13 = L_61;
	}

IL_013a:
	{
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_62 = __this->___layout;
		int32_t L_63 = V_1;
		int32_t L_64 = V_13;
		int32_t L_65;
		L_65 = OpusMultistream_get_left_channel_mBC9BCAA485D1095C537AA8A8DFB38355DCB06A04(L_62, L_63, L_64, NULL);
		int32_t L_66 = L_65;
		V_12 = L_66;
		if ((!(((uint32_t)L_66) == ((uint32_t)(-1)))))
		{
			goto IL_0117;
		}
	}
	{
		V_13 = (-1);
		goto IL_0176;
	}

IL_0153:
	{
		opus_copy_channel_out_func_1_t85951F56EF7450B05E135DF219F8BF05B4D5E030* L_67 = ___2_copy_channel_out;
		Span_1_t7578EBC2679C3216D7A6FA0DAECAF2256A33CF4C L_68 = ___1_pcm;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_69 = __this->___layout;
		NullCheck(L_69);
		int32_t L_70 = L_69->___nb_channels;
		int32_t L_71 = V_12;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_72 = V_5;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_73;
		L_73 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_72, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_74 = ___3_frame_size;
		NullCheck(L_67);
		opus_copy_channel_out_func_1_Invoke_mB9C23E8CD1EED40F2F28F55B16E7F42E95D95441_inline(L_67, L_68, L_70, L_71, L_73, 1, 2, L_74, il2cpp_rgctx_method(method->rgctx_data, 2));
		int32_t L_75 = V_12;
		V_13 = L_75;
	}

IL_0176:
	{
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_76 = __this->___layout;
		int32_t L_77 = V_1;
		int32_t L_78 = V_13;
		int32_t L_79;
		L_79 = OpusMultistream_get_right_channel_m1F24FA4BC9F11ADF386C3B9CAB948C1EBCC95C3F(L_76, L_77, L_78, NULL);
		int32_t L_80 = L_79;
		V_12 = L_80;
		if ((!(((uint32_t)L_80) == ((uint32_t)(-1)))))
		{
			goto IL_0153;
		}
	}
	{
		goto IL_01c8;
	}

IL_018c:
	{
		V_15 = (-1);
		goto IL_01b4;
	}

IL_0191:
	{
		opus_copy_channel_out_func_1_t85951F56EF7450B05E135DF219F8BF05B4D5E030* L_81 = ___2_copy_channel_out;
		Span_1_t7578EBC2679C3216D7A6FA0DAECAF2256A33CF4C L_82 = ___1_pcm;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_83 = __this->___layout;
		NullCheck(L_83);
		int32_t L_84 = L_83->___nb_channels;
		int32_t L_85 = V_14;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_86 = V_5;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_87;
		L_87 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_86, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_88 = ___3_frame_size;
		NullCheck(L_81);
		opus_copy_channel_out_func_1_Invoke_mB9C23E8CD1EED40F2F28F55B16E7F42E95D95441_inline(L_81, L_82, L_84, L_85, L_87, 0, 1, L_88, il2cpp_rgctx_method(method->rgctx_data, 2));
		int32_t L_89 = V_14;
		V_15 = L_89;
	}

IL_01b4:
	{
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_90 = __this->___layout;
		int32_t L_91 = V_1;
		int32_t L_92 = V_15;
		int32_t L_93;
		L_93 = OpusMultistream_get_mono_channel_mD28CFC9E8DF9F999251643576CECC59C132EA292(L_90, L_91, L_92, NULL);
		int32_t L_94 = L_93;
		V_14 = L_94;
		if ((!(((uint32_t)L_94) == ((uint32_t)(-1)))))
		{
			goto IL_0191;
		}
	}

IL_01c8:
	{
		int32_t L_95 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_95, 1));
	}

IL_01cc:
	{
		int32_t L_96 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_97 = __this->___layout;
		NullCheck(L_97);
		int32_t L_98 = L_97->___nb_streams;
		if ((((int32_t)L_96) < ((int32_t)L_98)))
		{
			goto IL_0099;
		}
	}
	{
		V_2 = 0;
		goto IL_0216;
	}

IL_01e1:
	{
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_99 = __this->___layout;
		NullCheck(L_99);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_100 = L_99->___mapping;
		int32_t L_101 = V_2;
		NullCheck(L_100);
		int32_t L_102 = L_101;
		uint8_t L_103 = (L_100)->GetAt(static_cast<il2cpp_array_size_t>(L_102));
		if ((!(((uint32_t)L_103) == ((uint32_t)((int32_t)255)))))
		{
			goto IL_0212;
		}
	}
	{
		opus_copy_channel_out_func_1_t85951F56EF7450B05E135DF219F8BF05B4D5E030* L_104 = ___2_copy_channel_out;
		Span_1_t7578EBC2679C3216D7A6FA0DAECAF2256A33CF4C L_105 = ___1_pcm;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_106 = __this->___layout;
		NullCheck(L_106);
		int32_t L_107 = L_106->___nb_channels;
		int32_t L_108 = V_2;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_109;
		L_109 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D((Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)NULL, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_110 = ___3_frame_size;
		NullCheck(L_104);
		opus_copy_channel_out_func_1_Invoke_mB9C23E8CD1EED40F2F28F55B16E7F42E95D95441_inline(L_104, L_105, L_107, L_108, L_109, 0, 0, L_110, il2cpp_rgctx_method(method->rgctx_data, 2));
	}

IL_0212:
	{
		int32_t L_111 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_111, 1));
	}

IL_0216:
	{
		int32_t L_112 = V_2;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_113 = __this->___layout;
		NullCheck(L_113);
		int32_t L_114 = L_113->___nb_channels;
		if ((((int32_t)L_112) < ((int32_t)L_114)))
		{
			goto IL_01e1;
		}
	}
	{
		int32_t L_115 = ___3_frame_size;
		return L_115;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusMSDecoder_opus_multistream_decode_native_TisIl2CppFullySharedGenericAny_m51CF954A70C5D6A9F9EB3029976A546129E805F1_gshared (OpusMSDecoder_tA24EBFD8B5A8C5D6C12AABAE8403EF562FFBA83A* __this, ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D ___0_data, Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54 ___1_pcm, opus_copy_channel_out_func_1_tF57D8B7B7DB4FBB20B0699A0AEFCD074B6636351* ___2_copy_channel_out, int32_t ___3_frame_size, int32_t ___4_decode_fec, int32_t ___5_soft_clip, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* V_5 = NULL;
	int32_t V_6 = 0;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* V_9 = NULL;
	int32_t V_10 = 0;
	int32_t V_11 = 0;
	int32_t V_12 = 0;
	int32_t V_13 = 0;
	int32_t V_14 = 0;
	int32_t V_15 = 0;
	int32_t G_B18_0 = 0;
	int32_t G_B18_1 = 0;
	int32_t G_B18_2 = 0;
	Span_1_tC1B695440A1567664C2665D76D5614739FDF453D G_B18_3;
	memset((&G_B18_3), 0, sizeof(G_B18_3));
	int32_t G_B18_4 = 0;
	int32_t G_B18_5 = 0;
	ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D G_B18_6;
	memset((&G_B18_6), 0, sizeof(G_B18_6));
	OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* G_B18_7 = NULL;
	int32_t G_B17_0 = 0;
	int32_t G_B17_1 = 0;
	int32_t G_B17_2 = 0;
	Span_1_tC1B695440A1567664C2665D76D5614739FDF453D G_B17_3;
	memset((&G_B17_3), 0, sizeof(G_B17_3));
	int32_t G_B17_4 = 0;
	int32_t G_B17_5 = 0;
	ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D G_B17_6;
	memset((&G_B17_6), 0, sizeof(G_B17_6));
	OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* G_B17_7 = NULL;
	int32_t G_B19_0 = 0;
	int32_t G_B19_1 = 0;
	int32_t G_B19_2 = 0;
	int32_t G_B19_3 = 0;
	Span_1_tC1B695440A1567664C2665D76D5614739FDF453D G_B19_4;
	memset((&G_B19_4), 0, sizeof(G_B19_4));
	int32_t G_B19_5 = 0;
	int32_t G_B19_6 = 0;
	ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D G_B19_7;
	memset((&G_B19_7), 0, sizeof(G_B19_7));
	OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* G_B19_8 = NULL;
	{
		V_4 = 0;
		int32_t L_0;
		L_0 = OpusMSDecoder_get_SampleRate_m00241E93F2188AB42BCE48A4A6191386EB16BB86(__this, NULL);
		V_0 = L_0;
		int32_t L_1 = ___3_frame_size;
		int32_t L_2 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(L_1, ((int32_t)il2cpp_codegen_multiply(((int32_t)(L_2/((int32_t)25))), 3)), NULL);
		___3_frame_size = L_3;
		int32_t L_4 = ___3_frame_size;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_5 = (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)SZArrayNew(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(2, L_4)));
		V_5 = L_5;
		V_3 = 0;
		int32_t L_6;
		L_6 = ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_inline((&___0_data), ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_RuntimeMethod_var);
		if (L_6)
		{
			goto IL_0032;
		}
	}
	{
		V_4 = 1;
	}

IL_0032:
	{
		int32_t L_7;
		L_7 = ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_inline((&___0_data), ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_RuntimeMethod_var);
		if ((((int32_t)L_7) >= ((int32_t)0)))
		{
			goto IL_003e;
		}
	}
	{
		return (-1);
	}

IL_003e:
	{
		int32_t L_8 = V_4;
		if (L_8)
		{
			goto IL_005d;
		}
	}
	{
		int32_t L_9;
		L_9 = ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_inline((&___0_data), ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_RuntimeMethod_var);
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_10 = __this->___layout;
		NullCheck(L_10);
		int32_t L_11 = L_10->___nb_streams;
		if ((((int32_t)L_9) >= ((int32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_multiply(2, L_11)), 1)))))
		{
			goto IL_005d;
		}
	}
	{
		return ((int32_t)-4);
	}

IL_005d:
	{
		int32_t L_12 = V_4;
		if (L_12)
		{
			goto IL_0086;
		}
	}
	{
		ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D L_13 = ___0_data;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_14 = __this->___layout;
		NullCheck(L_14);
		int32_t L_15 = L_14->___nb_streams;
		int32_t L_16 = V_0;
		int32_t L_17;
		L_17 = OpusMSDecoder_opus_multistream_packet_validate_m3E2D2CF1B4A698FD791C8A3BA0C3A2E605A22CC6(L_13, L_15, L_16, NULL);
		V_8 = L_17;
		int32_t L_18 = V_8;
		if ((((int32_t)L_18) >= ((int32_t)0)))
		{
			goto IL_007d;
		}
	}
	{
		int32_t L_19 = V_8;
		return L_19;
	}

IL_007d:
	{
		int32_t L_20 = V_8;
		int32_t L_21 = ___3_frame_size;
		if ((((int32_t)L_20) <= ((int32_t)L_21)))
		{
			goto IL_0086;
		}
	}
	{
		return ((int32_t)-2);
	}

IL_0086:
	{
		V_6 = 0;
		int32_t L_22;
		L_22 = ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_inline((&___0_data), ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_RuntimeMethod_var);
		V_7 = L_22;
		V_1 = 0;
		goto IL_01cc;
	}

IL_0099:
	{
		OpusDecoderU5BU5D_t208A6B826C1F7F0CEAEEF2F4D4AA5844540C59D1* L_23 = __this->___decoders;
		int32_t L_24 = V_3;
		int32_t L_25 = L_24;
		V_3 = ((int32_t)il2cpp_codegen_add(L_25, 1));
		NullCheck(L_23);
		int32_t L_26 = L_25;
		OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* L_27 = (L_23)->GetAt(static_cast<il2cpp_array_size_t>(L_26));
		V_9 = L_27;
		int32_t L_28 = V_4;
		if (L_28)
		{
			goto IL_00b8;
		}
	}
	{
		int32_t L_29;
		L_29 = ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_inline((&___0_data), ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_RuntimeMethod_var);
		if ((((int32_t)L_29) > ((int32_t)0)))
		{
			goto IL_00b8;
		}
	}
	{
		return ((int32_t)-3);
	}

IL_00b8:
	{
		OpusDecoder_tE0C2F9082DB13240EAB48CE7D78D93A70C47C69D* L_30 = V_9;
		ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D L_31 = ___0_data;
		int32_t L_32 = V_6;
		int32_t L_33 = V_7;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_34 = V_5;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_35;
		L_35 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_34, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_36 = ___3_frame_size;
		int32_t L_37 = ___4_decode_fec;
		int32_t L_38 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_39 = __this->___layout;
		NullCheck(L_39);
		int32_t L_40 = L_39->___nb_streams;
		if ((!(((uint32_t)L_38) == ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_40, 1))))))
		{
			G_B18_0 = L_37;
			G_B18_1 = L_36;
			G_B18_2 = 0;
			G_B18_3 = L_35;
			G_B18_4 = L_33;
			G_B18_5 = L_32;
			G_B18_6 = L_31;
			G_B18_7 = L_30;
			goto IL_00de;
		}
		G_B17_0 = L_37;
		G_B17_1 = L_36;
		G_B17_2 = 0;
		G_B17_3 = L_35;
		G_B17_4 = L_33;
		G_B17_5 = L_32;
		G_B17_6 = L_31;
		G_B17_7 = L_30;
	}
	{
		G_B19_0 = 0;
		G_B19_1 = G_B17_0;
		G_B19_2 = G_B17_1;
		G_B19_3 = G_B17_2;
		G_B19_4 = G_B17_3;
		G_B19_5 = G_B17_4;
		G_B19_6 = G_B17_5;
		G_B19_7 = G_B17_6;
		G_B19_8 = G_B17_7;
		goto IL_00df;
	}

IL_00de:
	{
		G_B19_0 = 1;
		G_B19_1 = G_B18_0;
		G_B19_2 = G_B18_1;
		G_B19_3 = G_B18_2;
		G_B19_4 = G_B18_3;
		G_B19_5 = G_B18_4;
		G_B19_6 = G_B18_5;
		G_B19_7 = G_B18_6;
		G_B19_8 = G_B18_7;
	}

IL_00df:
	{
		int32_t L_41 = ___5_soft_clip;
		NullCheck(G_B19_8);
		int32_t L_42;
		L_42 = OpusDecoder_opus_decode_native_m226953E91BEF13C44CF5706AFD0B3238251F9567(G_B19_8, G_B19_7, G_B19_6, G_B19_5, G_B19_4, G_B19_3, G_B19_2, G_B19_1, G_B19_0, (&V_11), L_41, NULL);
		V_10 = L_42;
		int32_t L_43 = V_6;
		int32_t L_44 = V_11;
		V_6 = ((int32_t)il2cpp_codegen_add(L_43, L_44));
		int32_t L_45 = V_7;
		int32_t L_46 = V_11;
		V_7 = ((int32_t)il2cpp_codegen_subtract(L_45, L_46));
		int32_t L_47 = V_10;
		if ((((int32_t)L_47) > ((int32_t)0)))
		{
			goto IL_0100;
		}
	}
	{
		int32_t L_48 = V_10;
		return L_48;
	}

IL_0100:
	{
		int32_t L_49 = V_10;
		___3_frame_size = L_49;
		int32_t L_50 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_51 = __this->___layout;
		NullCheck(L_51);
		int32_t L_52 = L_51->___nb_coupled_streams;
		if ((((int32_t)L_50) >= ((int32_t)L_52)))
		{
			goto IL_018c;
		}
	}
	{
		V_13 = (-1);
		goto IL_013a;
	}

IL_0117:
	{
		opus_copy_channel_out_func_1_tF57D8B7B7DB4FBB20B0699A0AEFCD074B6636351* L_53 = ___2_copy_channel_out;
		Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54 L_54 = ___1_pcm;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_55 = __this->___layout;
		NullCheck(L_55);
		int32_t L_56 = L_55->___nb_channels;
		int32_t L_57 = V_12;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_58 = V_5;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_59;
		L_59 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_58, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_60 = ___3_frame_size;
		NullCheck(L_53);
		((  void (*) (opus_copy_channel_out_func_1_tF57D8B7B7DB4FBB20B0699A0AEFCD074B6636351*, Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54, int32_t, int32_t, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(L_53, L_54, L_56, L_57, L_59, 0, 2, L_60, il2cpp_rgctx_method(method->rgctx_data, 2));
		int32_t L_61 = V_12;
		V_13 = L_61;
	}

IL_013a:
	{
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_62 = __this->___layout;
		int32_t L_63 = V_1;
		int32_t L_64 = V_13;
		int32_t L_65;
		L_65 = OpusMultistream_get_left_channel_mBC9BCAA485D1095C537AA8A8DFB38355DCB06A04(L_62, L_63, L_64, NULL);
		int32_t L_66 = L_65;
		V_12 = L_66;
		if ((!(((uint32_t)L_66) == ((uint32_t)(-1)))))
		{
			goto IL_0117;
		}
	}
	{
		V_13 = (-1);
		goto IL_0176;
	}

IL_0153:
	{
		opus_copy_channel_out_func_1_tF57D8B7B7DB4FBB20B0699A0AEFCD074B6636351* L_67 = ___2_copy_channel_out;
		Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54 L_68 = ___1_pcm;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_69 = __this->___layout;
		NullCheck(L_69);
		int32_t L_70 = L_69->___nb_channels;
		int32_t L_71 = V_12;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_72 = V_5;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_73;
		L_73 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_72, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_74 = ___3_frame_size;
		NullCheck(L_67);
		((  void (*) (opus_copy_channel_out_func_1_tF57D8B7B7DB4FBB20B0699A0AEFCD074B6636351*, Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54, int32_t, int32_t, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(L_67, L_68, L_70, L_71, L_73, 1, 2, L_74, il2cpp_rgctx_method(method->rgctx_data, 2));
		int32_t L_75 = V_12;
		V_13 = L_75;
	}

IL_0176:
	{
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_76 = __this->___layout;
		int32_t L_77 = V_1;
		int32_t L_78 = V_13;
		int32_t L_79;
		L_79 = OpusMultistream_get_right_channel_m1F24FA4BC9F11ADF386C3B9CAB948C1EBCC95C3F(L_76, L_77, L_78, NULL);
		int32_t L_80 = L_79;
		V_12 = L_80;
		if ((!(((uint32_t)L_80) == ((uint32_t)(-1)))))
		{
			goto IL_0153;
		}
	}
	{
		goto IL_01c8;
	}

IL_018c:
	{
		V_15 = (-1);
		goto IL_01b4;
	}

IL_0191:
	{
		opus_copy_channel_out_func_1_tF57D8B7B7DB4FBB20B0699A0AEFCD074B6636351* L_81 = ___2_copy_channel_out;
		Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54 L_82 = ___1_pcm;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_83 = __this->___layout;
		NullCheck(L_83);
		int32_t L_84 = L_83->___nb_channels;
		int32_t L_85 = V_14;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_86 = V_5;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_87;
		L_87 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_86, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_88 = ___3_frame_size;
		NullCheck(L_81);
		((  void (*) (opus_copy_channel_out_func_1_tF57D8B7B7DB4FBB20B0699A0AEFCD074B6636351*, Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54, int32_t, int32_t, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(L_81, L_82, L_84, L_85, L_87, 0, 1, L_88, il2cpp_rgctx_method(method->rgctx_data, 2));
		int32_t L_89 = V_14;
		V_15 = L_89;
	}

IL_01b4:
	{
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_90 = __this->___layout;
		int32_t L_91 = V_1;
		int32_t L_92 = V_15;
		int32_t L_93;
		L_93 = OpusMultistream_get_mono_channel_mD28CFC9E8DF9F999251643576CECC59C132EA292(L_90, L_91, L_92, NULL);
		int32_t L_94 = L_93;
		V_14 = L_94;
		if ((!(((uint32_t)L_94) == ((uint32_t)(-1)))))
		{
			goto IL_0191;
		}
	}

IL_01c8:
	{
		int32_t L_95 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_95, 1));
	}

IL_01cc:
	{
		int32_t L_96 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_97 = __this->___layout;
		NullCheck(L_97);
		int32_t L_98 = L_97->___nb_streams;
		if ((((int32_t)L_96) < ((int32_t)L_98)))
		{
			goto IL_0099;
		}
	}
	{
		V_2 = 0;
		goto IL_0216;
	}

IL_01e1:
	{
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_99 = __this->___layout;
		NullCheck(L_99);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_100 = L_99->___mapping;
		int32_t L_101 = V_2;
		NullCheck(L_100);
		int32_t L_102 = L_101;
		uint8_t L_103 = (L_100)->GetAt(static_cast<il2cpp_array_size_t>(L_102));
		if ((!(((uint32_t)L_103) == ((uint32_t)((int32_t)255)))))
		{
			goto IL_0212;
		}
	}
	{
		opus_copy_channel_out_func_1_tF57D8B7B7DB4FBB20B0699A0AEFCD074B6636351* L_104 = ___2_copy_channel_out;
		Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54 L_105 = ___1_pcm;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_106 = __this->___layout;
		NullCheck(L_106);
		int32_t L_107 = L_106->___nb_channels;
		int32_t L_108 = V_2;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_109;
		L_109 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D((Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)NULL, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		int32_t L_110 = ___3_frame_size;
		NullCheck(L_104);
		((  void (*) (opus_copy_channel_out_func_1_tF57D8B7B7DB4FBB20B0699A0AEFCD074B6636351*, Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54, int32_t, int32_t, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(L_104, L_105, L_107, L_108, L_109, 0, 0, L_110, il2cpp_rgctx_method(method->rgctx_data, 2));
	}

IL_0212:
	{
		int32_t L_111 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_111, 1));
	}

IL_0216:
	{
		int32_t L_112 = V_2;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_113 = __this->___layout;
		NullCheck(L_113);
		int32_t L_114 = L_113->___nb_channels;
		if ((((int32_t)L_112) < ((int32_t)L_114)))
		{
			goto IL_01e1;
		}
	}
	{
		int32_t L_115 = ___3_frame_size;
		return L_115;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusMSEncoder_opus_multistream_encode_native_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m86EEB5989A203C747F7717DA236F6D7BDD0D6680_gshared (OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573* __this, opus_copy_channel_in_func_1_t73990C8C629DA94EEF8E66726DF516DDE7108033* ___0_copy_channel_in, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 ___1_pcm, int32_t ___2_analysis_frame_size, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___3_data, int32_t ___4_max_data_bytes, int32_t ___5_lsb_depth, downmix_func_1_tF54CFC946A3147244C91F03F0A69E5F14AB8461C* ___6_downmix, int32_t ___7_float_api, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ReadOnlySpan_1_op_Implicit_mCB2B03DD84141A56335B242E9AE355600A05C383_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* V_4 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_5 = NULL;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_6 = NULL;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* V_7 = NULL;
	int32_t V_8 = 0;
	CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* V_9 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_10 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_11 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_12 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_13 = NULL;
	int32_t V_14 = 0;
	int32_t V_15 = 0;
	int32_t V_16 = 0;
	int32_t V_17 = 0;
	int32_t V_18 = 0;
	int32_t V_19 = 0;
	OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* V_20 = NULL;
	int32_t V_21 = 0;
	OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* V_22 = NULL;
	int32_t V_23 = 0;
	int32_t V_24 = 0;
	int32_t V_25 = 0;
	int32_t V_26 = 0;
	int32_t V_27 = 0;
	int32_t V_28 = 0;
	int32_t V_29 = 0;
	int32_t V_30 = 0;
	int32_t V_31 = 0;
	int32_t G_B5_0 = 0;
	int32_t G_B55_0 = 0;
	int32_t G_B54_0 = 0;
	int32_t G_B56_0 = 0;
	int32_t G_B56_1 = 0;
	int32_t G_B64_0 = 0;
	int32_t G_B64_1 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B64_2;
	memset((&G_B64_2), 0, sizeof(G_B64_2));
	int32_t G_B64_3 = 0;
	int32_t G_B64_4 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B64_5 = NULL;
	int32_t G_B63_0 = 0;
	int32_t G_B63_1 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B63_2;
	memset((&G_B63_2), 0, sizeof(G_B63_2));
	int32_t G_B63_3 = 0;
	int32_t G_B63_4 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B63_5 = NULL;
	int32_t G_B65_0 = 0;
	int32_t G_B65_1 = 0;
	int32_t G_B65_2 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B65_3;
	memset((&G_B65_3), 0, sizeof(G_B65_3));
	int32_t G_B65_4 = 0;
	int32_t G_B65_5 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B65_6 = NULL;
	int32_t G_B67_0 = 0;
	int32_t G_B67_1 = 0;
	int32_t G_B67_2 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B67_3;
	memset((&G_B67_3), 0, sizeof(G_B67_3));
	int32_t G_B67_4 = 0;
	int32_t G_B67_5 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B67_6 = NULL;
	int32_t G_B66_0 = 0;
	int32_t G_B66_1 = 0;
	int32_t G_B66_2 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B66_3;
	memset((&G_B66_3), 0, sizeof(G_B66_3));
	int32_t G_B66_4 = 0;
	int32_t G_B66_5 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B66_6 = NULL;
	int32_t G_B68_0 = 0;
	int32_t G_B68_1 = 0;
	int32_t G_B68_2 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B68_3;
	memset((&G_B68_3), 0, sizeof(G_B68_3));
	int32_t G_B68_4 = 0;
	int32_t G_B68_5 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B68_6 = NULL;
	int32_t G_B69_0 = 0;
	int32_t G_B69_1 = 0;
	int32_t G_B69_2 = 0;
	int32_t G_B69_3 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B69_4;
	memset((&G_B69_4), 0, sizeof(G_B69_4));
	int32_t G_B69_5 = 0;
	int32_t G_B69_6 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B69_7 = NULL;
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)3832));
		V_6 = L_0;
		OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* L_1 = (OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0*)il2cpp_codegen_object_new(OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0_il2cpp_TypeInfo_var);
		OpusRepacketizer__ctor_mC4456456D2AAD30181CA3EC5FF721E31477B6996(L_1, NULL);
		V_7 = L_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_2 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)256));
		V_10 = L_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)42));
		V_11 = L_3;
		V_12 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		V_13 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		V_17 = 0;
		int32_t L_4 = __this->___surround;
		if (!L_4)
		{
			goto IL_0049;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = __this->___preemph_mem;
		V_13 = L_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_6 = __this->___window_mem;
		V_12 = L_6;
	}

IL_0049:
	{
		V_2 = 0;
		OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F* L_7 = __this->___encoders;
		int32_t L_8 = V_2;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		NullCheck(L_10);
		int32_t L_11;
		L_11 = OpusEncoder_get_SampleRate_m07B4CE6A7F1CAD6FA65936B9CF4F0F7536966E52_inline(L_10, NULL);
		V_0 = L_11;
		OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F* L_12 = __this->___encoders;
		int32_t L_13 = V_2;
		NullCheck(L_12);
		int32_t L_14 = L_13;
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_15 = (L_12)->GetAt(static_cast<il2cpp_array_size_t>(L_14));
		NullCheck(L_15);
		bool L_16;
		L_16 = OpusEncoder_get_UseVBR_m5476585F8DDFEC3AF5C54713C82340E7007A4389(L_15, NULL);
		if (L_16)
		{
			goto IL_006b;
		}
	}
	{
		G_B5_0 = 0;
		goto IL_006c;
	}

IL_006b:
	{
		G_B5_0 = 1;
	}

IL_006c:
	{
		V_8 = G_B5_0;
		OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F* L_17 = __this->___encoders;
		int32_t L_18 = V_2;
		NullCheck(L_17);
		int32_t L_19 = L_18;
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_20 = (L_17)->GetAt(static_cast<il2cpp_array_size_t>(L_19));
		NullCheck(L_20);
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_21;
		L_21 = OpusEncoder_GetCeltMode_m6EC596A3D230516010AAB28BE0D2EDF48B9B793D(L_20, NULL);
		V_9 = L_21;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_22 = __this->___layout;
		NullCheck(L_22);
		int32_t L_23 = L_22->___nb_streams;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_24 = __this->___layout;
		NullCheck(L_24);
		int32_t L_25 = L_24->___nb_coupled_streams;
		V_19 = ((int32_t)il2cpp_codegen_add(L_23, L_25));
		OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F* L_26 = __this->___encoders;
		int32_t L_27 = V_2;
		NullCheck(L_26);
		int32_t L_28 = L_27;
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_29 = (L_26)->GetAt(static_cast<il2cpp_array_size_t>(L_28));
		NullCheck(L_29);
		int32_t L_30;
		L_30 = OpusEncoder_get_Lookahead_mC173676834FE358C9449C8B6A791005CC854075E(L_29, NULL);
		V_18 = L_30;
		int32_t L_31 = V_18;
		int32_t L_32 = V_0;
		V_18 = ((int32_t)il2cpp_codegen_subtract(L_31, ((int32_t)(L_32/((int32_t)400)))));
		ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 L_33 = ___1_pcm;
		int32_t L_34 = ___2_analysis_frame_size;
		int32_t L_35 = __this->___variable_duration;
		int32_t L_36 = V_19;
		int32_t L_37 = V_0;
		int32_t L_38 = __this->___bitrate_bps;
		int32_t L_39 = V_18;
		downmix_func_1_tF54CFC946A3147244C91F03F0A69E5F14AB8461C* L_40 = ___6_downmix;
		SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* L_41 = __this->___subframe_mem;
		OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F* L_42 = __this->___encoders;
		int32_t L_43 = V_2;
		NullCheck(L_42);
		int32_t L_44 = L_43;
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_45 = (L_42)->GetAt(static_cast<il2cpp_array_size_t>(L_44));
		NullCheck(L_45);
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_46 = L_45->___analysis;
		NullCheck(L_46);
		bool L_47 = L_46->___enabled;
		int32_t L_48;
		L_48 = CodecHelpers_compute_frame_size_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m383EA214DC0D0ABD3988FC7C148510734632BF0E(L_33, L_34, L_35, L_36, L_37, L_38, L_39, L_40, L_41, L_47, il2cpp_rgctx_method(method->rgctx_data, 2));
		V_14 = L_48;
		int32_t L_49 = V_14;
		int32_t L_50 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)400), L_49))) >= ((int32_t)L_50)))
		{
			goto IL_00f2;
		}
	}
	{
		return (-1);
	}

IL_00f2:
	{
		int32_t L_51 = V_14;
		int32_t L_52 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)400), L_51))) == ((int32_t)L_52)))
		{
			goto IL_012c;
		}
	}
	{
		int32_t L_53 = V_14;
		int32_t L_54 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)200), L_53))) == ((int32_t)L_54)))
		{
			goto IL_012c;
		}
	}
	{
		int32_t L_55 = V_14;
		int32_t L_56 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)100), L_55))) == ((int32_t)L_56)))
		{
			goto IL_012c;
		}
	}
	{
		int32_t L_57 = V_14;
		int32_t L_58 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)50), L_57))) == ((int32_t)L_58)))
		{
			goto IL_012c;
		}
	}
	{
		int32_t L_59 = V_14;
		int32_t L_60 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)25), L_59))) == ((int32_t)L_60)))
		{
			goto IL_012c;
		}
	}
	{
		int32_t L_61 = V_14;
		int32_t L_62 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)50), L_61))) == ((int32_t)((int32_t)il2cpp_codegen_multiply(3, L_62)))))
		{
			goto IL_012c;
		}
	}
	{
		return (-1);
	}

IL_012c:
	{
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_63 = __this->___layout;
		NullCheck(L_63);
		int32_t L_64 = L_63->___nb_streams;
		V_16 = ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_multiply(L_64, 2)), 1));
		int32_t L_65 = ___4_max_data_bytes;
		int32_t L_66 = V_16;
		if ((((int32_t)L_65) >= ((int32_t)L_66)))
		{
			goto IL_0146;
		}
	}
	{
		return ((int32_t)-2);
	}

IL_0146:
	{
		int32_t L_67 = V_14;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_68 = (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)SZArrayNew(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(2, L_67)));
		V_4 = L_68;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_69 = __this->___layout;
		NullCheck(L_69);
		int32_t L_70 = L_69->___nb_channels;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_71 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_70)));
		V_5 = L_71;
		int32_t L_72 = __this->___surround;
		if (!L_72)
		{
			goto IL_018d;
		}
	}
	{
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_73 = V_9;
		ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 L_74 = ___1_pcm;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_75 = V_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_76 = V_12;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_77 = V_13;
		int32_t L_78 = V_14;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_79 = __this->___layout;
		NullCheck(L_79);
		int32_t L_80 = L_79->___nb_channels;
		int32_t L_81 = V_0;
		opus_copy_channel_in_func_1_t73990C8C629DA94EEF8E66726DF516DDE7108033* L_82 = ___0_copy_channel_in;
		il2cpp_codegen_runtime_class_init_inline(OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_il2cpp_TypeInfo_var);
		OpusMSEncoder_surround_analysis_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m6704E92CF00A6B3ECE45AA3E065DAA70429B4918(L_73, L_74, L_75, L_76, L_77, L_78, ((int32_t)120), L_80, L_81, L_82, il2cpp_rgctx_method(method->rgctx_data, 4));
	}

IL_018d:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_83 = V_10;
		int32_t L_84 = V_14;
		int32_t L_85;
		L_85 = OpusMSEncoder_surround_rate_allocation_m0E90A088523C9263B2D659D378A7C1CCD306829B(__this, L_83, L_84, NULL);
		V_15 = L_85;
		int32_t L_86 = V_8;
		if (L_86)
		{
			goto IL_01ea;
		}
	}
	{
		int32_t L_87 = __this->___bitrate_bps;
		if ((!(((uint32_t)L_87) == ((uint32_t)((int32_t)-1000)))))
		{
			goto IL_01c1;
		}
	}
	{
		int32_t L_88 = ___4_max_data_bytes;
		int32_t L_89 = V_15;
		int32_t L_90 = V_0;
		int32_t L_91 = V_14;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_92;
		L_92 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(L_88, ((int32_t)(((int32_t)il2cpp_codegen_multiply(3, L_89))/((int32_t)(((int32_t)il2cpp_codegen_multiply(((int32_t)24), L_90))/L_91)))), NULL);
		___4_max_data_bytes = L_92;
		goto IL_01ea;
	}

IL_01c1:
	{
		int32_t L_93 = __this->___bitrate_bps;
		if ((((int32_t)L_93) == ((int32_t)(-1))))
		{
			goto IL_01ea;
		}
	}
	{
		int32_t L_94 = ___4_max_data_bytes;
		int32_t L_95 = V_16;
		int32_t L_96 = __this->___bitrate_bps;
		int32_t L_97 = V_0;
		int32_t L_98 = V_14;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_99;
		L_99 = Inlines_IMAX_mFECDD1F5C3C0962AF8B0140E78A6C3A25BCF9C23_inline(L_95, ((int32_t)(((int32_t)il2cpp_codegen_multiply(3, L_96))/((int32_t)(((int32_t)il2cpp_codegen_multiply(((int32_t)24), L_97))/L_98)))), NULL);
		int32_t L_100;
		L_100 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(L_94, L_99, NULL);
		___4_max_data_bytes = L_100;
	}

IL_01ea:
	{
		V_1 = 0;
		goto IL_02db;
	}

IL_01f1:
	{
		OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F* L_101 = __this->___encoders;
		int32_t L_102 = V_2;
		NullCheck(L_101);
		int32_t L_103 = L_102;
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_104 = (L_101)->GetAt(static_cast<il2cpp_array_size_t>(L_103));
		V_20 = L_104;
		int32_t L_105 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_105, 1));
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_106 = V_20;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_107 = V_10;
		int32_t L_108 = V_1;
		NullCheck(L_107);
		int32_t L_109 = L_108;
		int32_t L_110 = (L_107)->GetAt(static_cast<il2cpp_array_size_t>(L_109));
		NullCheck(L_106);
		OpusEncoder_set_Bitrate_m7B8AD5518E3DB9D28E3F376195747340D266AF6E(L_106, L_110, NULL);
		int32_t L_111 = __this->___surround;
		if (!L_111)
		{
			goto IL_02d7;
		}
	}
	{
		int32_t L_112 = __this->___bitrate_bps;
		V_21 = L_112;
		int32_t L_113 = V_14;
		int32_t L_114 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(L_113, ((int32_t)50)))) >= ((int32_t)L_114)))
		{
			goto IL_0240;
		}
	}
	{
		int32_t L_115 = V_21;
		int32_t L_116 = V_0;
		int32_t L_117 = V_14;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_118 = __this->___layout;
		NullCheck(L_118);
		int32_t L_119 = L_118->___nb_channels;
		V_21 = ((int32_t)il2cpp_codegen_subtract(L_115, ((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_multiply(((int32_t)60), ((int32_t)il2cpp_codegen_subtract(((int32_t)(L_116/L_117)), ((int32_t)50))))), L_119))));
	}

IL_0240:
	{
		int32_t L_120 = V_21;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_121 = __this->___layout;
		NullCheck(L_121);
		int32_t L_122 = L_121->___nb_channels;
		if ((((int32_t)L_120) <= ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)10000), L_122)))))
		{
			goto IL_0263;
		}
	}
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_123 = V_20;
		NullCheck(L_123);
		OpusEncoder_set_Bandwidth_m1401E2DE4B403C8A4CB8BEF736AE48C02861C726(L_123, (int32_t)((int32_t)1105), NULL);
		goto IL_02b5;
	}

IL_0263:
	{
		int32_t L_124 = V_21;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_125 = __this->___layout;
		NullCheck(L_125);
		int32_t L_126 = L_125->___nb_channels;
		if ((((int32_t)L_124) <= ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)7000), L_126)))))
		{
			goto IL_0286;
		}
	}
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_127 = V_20;
		NullCheck(L_127);
		OpusEncoder_set_Bandwidth_m1401E2DE4B403C8A4CB8BEF736AE48C02861C726(L_127, (int32_t)((int32_t)1104), NULL);
		goto IL_02b5;
	}

IL_0286:
	{
		int32_t L_128 = V_21;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_129 = __this->___layout;
		NullCheck(L_129);
		int32_t L_130 = L_129->___nb_channels;
		if ((((int32_t)L_128) <= ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)5000), L_130)))))
		{
			goto IL_02a9;
		}
	}
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_131 = V_20;
		NullCheck(L_131);
		OpusEncoder_set_Bandwidth_m1401E2DE4B403C8A4CB8BEF736AE48C02861C726(L_131, (int32_t)((int32_t)1103), NULL);
		goto IL_02b5;
	}

IL_02a9:
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_132 = V_20;
		NullCheck(L_132);
		OpusEncoder_set_Bandwidth_m1401E2DE4B403C8A4CB8BEF736AE48C02861C726(L_132, (int32_t)((int32_t)1101), NULL);
	}

IL_02b5:
	{
		int32_t L_133 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_134 = __this->___layout;
		NullCheck(L_134);
		int32_t L_135 = L_134->___nb_coupled_streams;
		if ((((int32_t)L_133) >= ((int32_t)L_135)))
		{
			goto IL_02d7;
		}
	}
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_136 = V_20;
		NullCheck(L_136);
		OpusEncoder_set_ForceMode_m27C03E1D80CD7B099DC5C9603ECCE70B99FB7201_inline(L_136, (int32_t)((int32_t)1002), NULL);
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_137 = V_20;
		NullCheck(L_137);
		OpusEncoder_set_ForceChannels_m23F0A9A42C5094A4E2B32DCE3479BEE9C3BCB2A8(L_137, 2, NULL);
	}

IL_02d7:
	{
		int32_t L_138 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_138, 1));
	}

IL_02db:
	{
		int32_t L_139 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_140 = __this->___layout;
		NullCheck(L_140);
		int32_t L_141 = L_140->___nb_streams;
		if ((((int32_t)L_139) < ((int32_t)L_141)))
		{
			goto IL_01f1;
		}
	}
	{
		V_2 = 0;
		V_3 = 0;
		V_1 = 0;
		goto IL_054d;
	}

IL_02f7:
	{
		OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* L_142 = V_7;
		NullCheck(L_142);
		OpusRepacketizer_Reset_m259455126D7AD3CFA796AA0B31C118D95D4C6AED(L_142, NULL);
		OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F* L_143 = __this->___encoders;
		int32_t L_144 = V_2;
		NullCheck(L_143);
		int32_t L_145 = L_144;
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_146 = (L_143)->GetAt(static_cast<il2cpp_array_size_t>(L_145));
		V_22 = L_146;
		int32_t L_147 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_148 = __this->___layout;
		NullCheck(L_148);
		int32_t L_149 = L_148->___nb_coupled_streams;
		if ((((int32_t)L_147) >= ((int32_t)L_149)))
		{
			goto IL_03bf;
		}
	}
	{
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_150 = __this->___layout;
		int32_t L_151 = V_1;
		int32_t L_152;
		L_152 = OpusMultistream_get_left_channel_mBC9BCAA485D1095C537AA8A8DFB38355DCB06A04(L_150, L_151, (-1), NULL);
		V_28 = L_152;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_153 = __this->___layout;
		int32_t L_154 = V_1;
		int32_t L_155;
		L_155 = OpusMultistream_get_right_channel_m1F24FA4BC9F11ADF386C3B9CAB948C1EBCC95C3F(L_153, L_154, (-1), NULL);
		V_29 = L_155;
		opus_copy_channel_in_func_1_t73990C8C629DA94EEF8E66726DF516DDE7108033* L_156 = ___0_copy_channel_in;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_157 = V_4;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_158;
		L_158 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_157, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 L_159 = ___1_pcm;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_160 = __this->___layout;
		NullCheck(L_160);
		int32_t L_161 = L_160->___nb_channels;
		int32_t L_162 = V_28;
		int32_t L_163 = V_14;
		NullCheck(L_156);
		opus_copy_channel_in_func_1_Invoke_mE863D518D4E113322D44FEBB0E6A4112575A199E_inline(L_156, L_158, 0, 2, L_159, L_161, L_162, L_163, il2cpp_rgctx_method(method->rgctx_data, 5));
		opus_copy_channel_in_func_1_t73990C8C629DA94EEF8E66726DF516DDE7108033* L_164 = ___0_copy_channel_in;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_165 = V_4;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_166;
		L_166 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_165, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 L_167 = ___1_pcm;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_168 = __this->___layout;
		NullCheck(L_168);
		int32_t L_169 = L_168->___nb_channels;
		int32_t L_170 = V_29;
		int32_t L_171 = V_14;
		NullCheck(L_164);
		opus_copy_channel_in_func_1_Invoke_mE863D518D4E113322D44FEBB0E6A4112575A199E_inline(L_164, L_166, 1, 2, L_167, L_169, L_170, L_171, il2cpp_rgctx_method(method->rgctx_data, 5));
		int32_t L_172 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_172, 1));
		int32_t L_173 = __this->___surround;
		if (!L_173)
		{
			goto IL_03b5;
		}
	}
	{
		V_27 = 0;
		goto IL_03af;
	}

IL_0386:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_174 = V_11;
		int32_t L_175 = V_27;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_176 = V_5;
		int32_t L_177 = V_28;
		int32_t L_178 = V_27;
		NullCheck(L_176);
		int32_t L_179 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_177)), L_178));
		int32_t L_180 = (L_176)->GetAt(static_cast<il2cpp_array_size_t>(L_179));
		NullCheck(L_174);
		(L_174)->SetAt(static_cast<il2cpp_array_size_t>(L_175), (int32_t)L_180);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_181 = V_11;
		int32_t L_182 = V_27;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_183 = V_5;
		int32_t L_184 = V_29;
		int32_t L_185 = V_27;
		NullCheck(L_183);
		int32_t L_186 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_184)), L_185));
		int32_t L_187 = (L_183)->GetAt(static_cast<il2cpp_array_size_t>(L_186));
		NullCheck(L_181);
		(L_181)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(((int32_t)21), L_182))), (int32_t)L_187);
		int32_t L_188 = V_27;
		V_27 = ((int32_t)il2cpp_codegen_add(L_188, 1));
	}

IL_03af:
	{
		int32_t L_189 = V_27;
		if ((((int32_t)L_189) < ((int32_t)((int32_t)21))))
		{
			goto IL_0386;
		}
	}

IL_03b5:
	{
		int32_t L_190 = V_28;
		V_25 = L_190;
		int32_t L_191 = V_29;
		V_26 = L_191;
		goto IL_0421;
	}

IL_03bf:
	{
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_192 = __this->___layout;
		int32_t L_193 = V_1;
		int32_t L_194;
		L_194 = OpusMultistream_get_mono_channel_mD28CFC9E8DF9F999251643576CECC59C132EA292(L_192, L_193, (-1), NULL);
		V_31 = L_194;
		opus_copy_channel_in_func_1_t73990C8C629DA94EEF8E66726DF516DDE7108033* L_195 = ___0_copy_channel_in;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_196 = V_4;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_197;
		L_197 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_196, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 L_198 = ___1_pcm;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_199 = __this->___layout;
		NullCheck(L_199);
		int32_t L_200 = L_199->___nb_channels;
		int32_t L_201 = V_31;
		int32_t L_202 = V_14;
		NullCheck(L_195);
		opus_copy_channel_in_func_1_Invoke_mE863D518D4E113322D44FEBB0E6A4112575A199E_inline(L_195, L_197, 0, 1, L_198, L_200, L_201, L_202, il2cpp_rgctx_method(method->rgctx_data, 5));
		int32_t L_203 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_203, 1));
		int32_t L_204 = __this->___surround;
		if (!L_204)
		{
			goto IL_041a;
		}
	}
	{
		V_30 = 0;
		goto IL_0414;
	}

IL_03fe:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_205 = V_11;
		int32_t L_206 = V_30;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_207 = V_5;
		int32_t L_208 = V_31;
		int32_t L_209 = V_30;
		NullCheck(L_207);
		int32_t L_210 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_208)), L_209));
		int32_t L_211 = (L_207)->GetAt(static_cast<il2cpp_array_size_t>(L_210));
		NullCheck(L_205);
		(L_205)->SetAt(static_cast<il2cpp_array_size_t>(L_206), (int32_t)L_211);
		int32_t L_212 = V_30;
		V_30 = ((int32_t)il2cpp_codegen_add(L_212, 1));
	}

IL_0414:
	{
		int32_t L_213 = V_30;
		if ((((int32_t)L_213) < ((int32_t)((int32_t)21))))
		{
			goto IL_03fe;
		}
	}

IL_041a:
	{
		int32_t L_214 = V_31;
		V_25 = L_214;
		V_26 = (-1);
	}

IL_0421:
	{
		int32_t L_215 = __this->___surround;
		if (!L_215)
		{
			goto IL_0432;
		}
	}
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_216 = V_22;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_217 = V_11;
		NullCheck(L_216);
		OpusEncoder_SetEnergyMask_mF239BDE66F682A18292CE1F5BE2AADBA657E69E9(L_216, L_217, NULL);
	}

IL_0432:
	{
		int32_t L_218 = ___4_max_data_bytes;
		int32_t L_219 = V_3;
		V_24 = ((int32_t)il2cpp_codegen_subtract(L_218, L_219));
		int32_t L_220 = V_24;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_221 = __this->___layout;
		NullCheck(L_221);
		int32_t L_222 = L_221->___nb_streams;
		int32_t L_223 = V_1;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_224;
		L_224 = Inlines_IMAX_mFECDD1F5C3C0962AF8B0140E78A6C3A25BCF9C23_inline(0, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_multiply(2, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_222, L_223)), 1)))), 1)), NULL);
		V_24 = ((int32_t)il2cpp_codegen_subtract(L_220, L_224));
		int32_t L_225 = V_24;
		int32_t L_226;
		L_226 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(L_225, ((int32_t)3832), NULL);
		V_24 = L_226;
		int32_t L_227 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_228 = __this->___layout;
		NullCheck(L_228);
		int32_t L_229 = L_228->___nb_streams;
		if ((((int32_t)L_227) == ((int32_t)((int32_t)il2cpp_codegen_subtract(L_229, 1)))))
		{
			goto IL_0486;
		}
	}
	{
		int32_t L_230 = V_24;
		int32_t L_231 = V_24;
		if ((((int32_t)L_231) > ((int32_t)((int32_t)253))))
		{
			G_B55_0 = L_230;
			goto IL_0482;
		}
		G_B54_0 = L_230;
	}
	{
		G_B56_0 = 1;
		G_B56_1 = G_B54_0;
		goto IL_0483;
	}

IL_0482:
	{
		G_B56_0 = 2;
		G_B56_1 = G_B55_0;
	}

IL_0483:
	{
		V_24 = ((int32_t)il2cpp_codegen_subtract(G_B56_1, G_B56_0));
	}

IL_0486:
	{
		int32_t L_232 = V_8;
		if (L_232)
		{
			goto IL_04aa;
		}
	}
	{
		int32_t L_233 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_234 = __this->___layout;
		NullCheck(L_234);
		int32_t L_235 = L_234->___nb_streams;
		if ((!(((uint32_t)L_233) == ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_235, 1))))))
		{
			goto IL_04aa;
		}
	}
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_236 = V_22;
		int32_t L_237 = V_24;
		int32_t L_238 = V_0;
		int32_t L_239 = V_14;
		NullCheck(L_236);
		OpusEncoder_set_Bitrate_m7B8AD5518E3DB9D28E3F376195747340D266AF6E(L_236, ((int32_t)il2cpp_codegen_multiply(L_237, ((int32_t)(((int32_t)il2cpp_codegen_multiply(8, L_238))/L_239)))), NULL);
	}

IL_04aa:
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_240 = V_22;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_241 = V_4;
		ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 L_242;
		L_242 = ReadOnlySpan_1_op_Implicit_mCB2B03DD84141A56335B242E9AE355600A05C383(L_241, ReadOnlySpan_1_op_Implicit_mCB2B03DD84141A56335B242E9AE355600A05C383_RuntimeMethod_var);
		int32_t L_243 = V_14;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_244 = V_6;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_245;
		L_245 = Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91(L_244, Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91_RuntimeMethod_var);
		int32_t L_246 = V_24;
		int32_t L_247 = ___5_lsb_depth;
		ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 L_248 = ___1_pcm;
		int32_t L_249 = ___2_analysis_frame_size;
		int32_t L_250 = V_25;
		int32_t L_251 = V_26;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_252 = __this->___layout;
		NullCheck(L_252);
		int32_t L_253 = L_252->___nb_channels;
		downmix_func_1_tF54CFC946A3147244C91F03F0A69E5F14AB8461C* L_254 = ___6_downmix;
		int32_t L_255 = ___7_float_api;
		NullCheck(L_240);
		int32_t L_256;
		L_256 = OpusEncoder_opus_encode_native_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m66C341F34A3F47A261A454C4DD185BE1507C02E5(L_240, L_242, 0, L_243, L_245, 0, L_246, L_247, L_248, L_249, L_250, L_251, L_253, L_254, L_255, il2cpp_rgctx_method(method->rgctx_data, 6));
		V_23 = L_256;
		int32_t L_257 = V_23;
		if ((((int32_t)L_257) >= ((int32_t)0)))
		{
			goto IL_04e6;
		}
	}
	{
		int32_t L_258 = V_23;
		return L_258;
	}

IL_04e6:
	{
		OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* L_259 = V_7;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_260 = V_6;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_261;
		L_261 = Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91(L_260, Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91_RuntimeMethod_var);
		int32_t L_262 = V_23;
		NullCheck(L_259);
		int32_t L_263;
		L_263 = OpusRepacketizer_AddPacket_mEF0C260D9D7AF7EE2243A598509FBE6197D0F510(L_259, L_261, 0, L_262, NULL);
		OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* L_264 = V_7;
		OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* L_265 = V_7;
		NullCheck(L_265);
		int32_t L_266;
		L_266 = OpusRepacketizer_GetNumFrames_m2244AD084D7E8802DB6AC4A1F1CAEFDCBF125A23_inline(L_265, NULL);
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_267 = ___3_data;
		int32_t L_268 = V_17;
		int32_t L_269 = ___4_max_data_bytes;
		int32_t L_270 = V_3;
		int32_t L_271 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_272 = __this->___layout;
		NullCheck(L_272);
		int32_t L_273 = L_272->___nb_streams;
		if ((!(((uint32_t)L_271) == ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_273, 1))))))
		{
			G_B64_0 = ((int32_t)il2cpp_codegen_subtract(L_269, L_270));
			G_B64_1 = L_268;
			G_B64_2 = L_267;
			G_B64_3 = L_266;
			G_B64_4 = 0;
			G_B64_5 = L_264;
			goto IL_051d;
		}
		G_B63_0 = ((int32_t)il2cpp_codegen_subtract(L_269, L_270));
		G_B63_1 = L_268;
		G_B63_2 = L_267;
		G_B63_3 = L_266;
		G_B63_4 = 0;
		G_B63_5 = L_264;
	}
	{
		G_B65_0 = 0;
		G_B65_1 = G_B63_0;
		G_B65_2 = G_B63_1;
		G_B65_3 = G_B63_2;
		G_B65_4 = G_B63_3;
		G_B65_5 = G_B63_4;
		G_B65_6 = G_B63_5;
		goto IL_051e;
	}

IL_051d:
	{
		G_B65_0 = 1;
		G_B65_1 = G_B64_0;
		G_B65_2 = G_B64_1;
		G_B65_3 = G_B64_2;
		G_B65_4 = G_B64_3;
		G_B65_5 = G_B64_4;
		G_B65_6 = G_B64_5;
	}

IL_051e:
	{
		int32_t L_274 = V_8;
		if (L_274)
		{
			G_B67_0 = G_B65_0;
			G_B67_1 = G_B65_1;
			G_B67_2 = G_B65_2;
			G_B67_3 = G_B65_3;
			G_B67_4 = G_B65_4;
			G_B67_5 = G_B65_5;
			G_B67_6 = G_B65_6;
			goto IL_0532;
		}
		G_B66_0 = G_B65_0;
		G_B66_1 = G_B65_1;
		G_B66_2 = G_B65_2;
		G_B66_3 = G_B65_3;
		G_B66_4 = G_B65_4;
		G_B66_5 = G_B65_5;
		G_B66_6 = G_B65_6;
	}
	{
		int32_t L_275 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_276 = __this->___layout;
		NullCheck(L_276);
		int32_t L_277 = L_276->___nb_streams;
		if ((((int32_t)L_275) == ((int32_t)((int32_t)il2cpp_codegen_subtract(L_277, 1)))))
		{
			G_B68_0 = G_B66_0;
			G_B68_1 = G_B66_1;
			G_B68_2 = G_B66_2;
			G_B68_3 = G_B66_3;
			G_B68_4 = G_B66_4;
			G_B68_5 = G_B66_5;
			G_B68_6 = G_B66_6;
			goto IL_0535;
		}
		G_B67_0 = G_B66_0;
		G_B67_1 = G_B66_1;
		G_B67_2 = G_B66_2;
		G_B67_3 = G_B66_3;
		G_B67_4 = G_B66_4;
		G_B67_5 = G_B66_5;
		G_B67_6 = G_B66_6;
	}

IL_0532:
	{
		G_B69_0 = 0;
		G_B69_1 = G_B67_0;
		G_B69_2 = G_B67_1;
		G_B69_3 = G_B67_2;
		G_B69_4 = G_B67_3;
		G_B69_5 = G_B67_4;
		G_B69_6 = G_B67_5;
		G_B69_7 = G_B67_6;
		goto IL_0536;
	}

IL_0535:
	{
		G_B69_0 = 1;
		G_B69_1 = G_B68_0;
		G_B69_2 = G_B68_1;
		G_B69_3 = G_B68_2;
		G_B69_4 = G_B68_3;
		G_B69_5 = G_B68_4;
		G_B69_6 = G_B68_5;
		G_B69_7 = G_B68_6;
	}

IL_0536:
	{
		NullCheck(G_B69_7);
		int32_t L_278;
		L_278 = OpusRepacketizer_opus_repacketizer_out_range_impl_m580835FE0C1A5F8831B645CF5488B8ED9E443F13(G_B69_7, G_B69_6, G_B69_5, G_B69_4, G_B69_3, G_B69_2, G_B69_1, G_B69_0, NULL);
		V_23 = L_278;
		int32_t L_279 = V_17;
		int32_t L_280 = V_23;
		V_17 = ((int32_t)il2cpp_codegen_add(L_279, L_280));
		int32_t L_281 = V_3;
		int32_t L_282 = V_23;
		V_3 = ((int32_t)il2cpp_codegen_add(L_281, L_282));
		int32_t L_283 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_283, 1));
	}

IL_054d:
	{
		int32_t L_284 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_285 = __this->___layout;
		NullCheck(L_285);
		int32_t L_286 = L_285->___nb_streams;
		if ((((int32_t)L_284) < ((int32_t)L_286)))
		{
			goto IL_02f7;
		}
	}
	{
		int32_t L_287 = V_3;
		return L_287;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusMSEncoder_opus_multistream_encode_native_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_mA4D15CC08E78B2374EFADF9DE2FBED8D82267052_gshared (OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573* __this, opus_copy_channel_in_func_1_t484D84949EB9FE0FFB9617C739F465DE3E898F3F* ___0_copy_channel_in, ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D ___1_pcm, int32_t ___2_analysis_frame_size, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___3_data, int32_t ___4_max_data_bytes, int32_t ___5_lsb_depth, downmix_func_1_t8CB50463E746CCBB4FFAE8EC889A02B92ED9F08B* ___6_downmix, int32_t ___7_float_api, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ReadOnlySpan_1_op_Implicit_mCB2B03DD84141A56335B242E9AE355600A05C383_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* V_4 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_5 = NULL;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_6 = NULL;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* V_7 = NULL;
	int32_t V_8 = 0;
	CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* V_9 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_10 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_11 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_12 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_13 = NULL;
	int32_t V_14 = 0;
	int32_t V_15 = 0;
	int32_t V_16 = 0;
	int32_t V_17 = 0;
	int32_t V_18 = 0;
	int32_t V_19 = 0;
	OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* V_20 = NULL;
	int32_t V_21 = 0;
	OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* V_22 = NULL;
	int32_t V_23 = 0;
	int32_t V_24 = 0;
	int32_t V_25 = 0;
	int32_t V_26 = 0;
	int32_t V_27 = 0;
	int32_t V_28 = 0;
	int32_t V_29 = 0;
	int32_t V_30 = 0;
	int32_t V_31 = 0;
	int32_t G_B5_0 = 0;
	int32_t G_B55_0 = 0;
	int32_t G_B54_0 = 0;
	int32_t G_B56_0 = 0;
	int32_t G_B56_1 = 0;
	int32_t G_B64_0 = 0;
	int32_t G_B64_1 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B64_2;
	memset((&G_B64_2), 0, sizeof(G_B64_2));
	int32_t G_B64_3 = 0;
	int32_t G_B64_4 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B64_5 = NULL;
	int32_t G_B63_0 = 0;
	int32_t G_B63_1 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B63_2;
	memset((&G_B63_2), 0, sizeof(G_B63_2));
	int32_t G_B63_3 = 0;
	int32_t G_B63_4 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B63_5 = NULL;
	int32_t G_B65_0 = 0;
	int32_t G_B65_1 = 0;
	int32_t G_B65_2 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B65_3;
	memset((&G_B65_3), 0, sizeof(G_B65_3));
	int32_t G_B65_4 = 0;
	int32_t G_B65_5 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B65_6 = NULL;
	int32_t G_B67_0 = 0;
	int32_t G_B67_1 = 0;
	int32_t G_B67_2 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B67_3;
	memset((&G_B67_3), 0, sizeof(G_B67_3));
	int32_t G_B67_4 = 0;
	int32_t G_B67_5 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B67_6 = NULL;
	int32_t G_B66_0 = 0;
	int32_t G_B66_1 = 0;
	int32_t G_B66_2 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B66_3;
	memset((&G_B66_3), 0, sizeof(G_B66_3));
	int32_t G_B66_4 = 0;
	int32_t G_B66_5 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B66_6 = NULL;
	int32_t G_B68_0 = 0;
	int32_t G_B68_1 = 0;
	int32_t G_B68_2 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B68_3;
	memset((&G_B68_3), 0, sizeof(G_B68_3));
	int32_t G_B68_4 = 0;
	int32_t G_B68_5 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B68_6 = NULL;
	int32_t G_B69_0 = 0;
	int32_t G_B69_1 = 0;
	int32_t G_B69_2 = 0;
	int32_t G_B69_3 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B69_4;
	memset((&G_B69_4), 0, sizeof(G_B69_4));
	int32_t G_B69_5 = 0;
	int32_t G_B69_6 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B69_7 = NULL;
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)3832));
		V_6 = L_0;
		OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* L_1 = (OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0*)il2cpp_codegen_object_new(OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0_il2cpp_TypeInfo_var);
		OpusRepacketizer__ctor_mC4456456D2AAD30181CA3EC5FF721E31477B6996(L_1, NULL);
		V_7 = L_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_2 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)256));
		V_10 = L_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)42));
		V_11 = L_3;
		V_12 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		V_13 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		V_17 = 0;
		int32_t L_4 = __this->___surround;
		if (!L_4)
		{
			goto IL_0049;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = __this->___preemph_mem;
		V_13 = L_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_6 = __this->___window_mem;
		V_12 = L_6;
	}

IL_0049:
	{
		V_2 = 0;
		OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F* L_7 = __this->___encoders;
		int32_t L_8 = V_2;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		NullCheck(L_10);
		int32_t L_11;
		L_11 = OpusEncoder_get_SampleRate_m07B4CE6A7F1CAD6FA65936B9CF4F0F7536966E52_inline(L_10, NULL);
		V_0 = L_11;
		OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F* L_12 = __this->___encoders;
		int32_t L_13 = V_2;
		NullCheck(L_12);
		int32_t L_14 = L_13;
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_15 = (L_12)->GetAt(static_cast<il2cpp_array_size_t>(L_14));
		NullCheck(L_15);
		bool L_16;
		L_16 = OpusEncoder_get_UseVBR_m5476585F8DDFEC3AF5C54713C82340E7007A4389(L_15, NULL);
		if (L_16)
		{
			goto IL_006b;
		}
	}
	{
		G_B5_0 = 0;
		goto IL_006c;
	}

IL_006b:
	{
		G_B5_0 = 1;
	}

IL_006c:
	{
		V_8 = G_B5_0;
		OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F* L_17 = __this->___encoders;
		int32_t L_18 = V_2;
		NullCheck(L_17);
		int32_t L_19 = L_18;
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_20 = (L_17)->GetAt(static_cast<il2cpp_array_size_t>(L_19));
		NullCheck(L_20);
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_21;
		L_21 = OpusEncoder_GetCeltMode_m6EC596A3D230516010AAB28BE0D2EDF48B9B793D(L_20, NULL);
		V_9 = L_21;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_22 = __this->___layout;
		NullCheck(L_22);
		int32_t L_23 = L_22->___nb_streams;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_24 = __this->___layout;
		NullCheck(L_24);
		int32_t L_25 = L_24->___nb_coupled_streams;
		V_19 = ((int32_t)il2cpp_codegen_add(L_23, L_25));
		OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F* L_26 = __this->___encoders;
		int32_t L_27 = V_2;
		NullCheck(L_26);
		int32_t L_28 = L_27;
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_29 = (L_26)->GetAt(static_cast<il2cpp_array_size_t>(L_28));
		NullCheck(L_29);
		int32_t L_30;
		L_30 = OpusEncoder_get_Lookahead_mC173676834FE358C9449C8B6A791005CC854075E(L_29, NULL);
		V_18 = L_30;
		int32_t L_31 = V_18;
		int32_t L_32 = V_0;
		V_18 = ((int32_t)il2cpp_codegen_subtract(L_31, ((int32_t)(L_32/((int32_t)400)))));
		ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D L_33 = ___1_pcm;
		int32_t L_34 = ___2_analysis_frame_size;
		int32_t L_35 = __this->___variable_duration;
		int32_t L_36 = V_19;
		int32_t L_37 = V_0;
		int32_t L_38 = __this->___bitrate_bps;
		int32_t L_39 = V_18;
		downmix_func_1_t8CB50463E746CCBB4FFAE8EC889A02B92ED9F08B* L_40 = ___6_downmix;
		SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* L_41 = __this->___subframe_mem;
		OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F* L_42 = __this->___encoders;
		int32_t L_43 = V_2;
		NullCheck(L_42);
		int32_t L_44 = L_43;
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_45 = (L_42)->GetAt(static_cast<il2cpp_array_size_t>(L_44));
		NullCheck(L_45);
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_46 = L_45->___analysis;
		NullCheck(L_46);
		bool L_47 = L_46->___enabled;
		int32_t L_48;
		L_48 = CodecHelpers_compute_frame_size_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_mC29E99157EBE887241410699A4D42C0B53FC4F5D(L_33, L_34, L_35, L_36, L_37, L_38, L_39, L_40, L_41, L_47, il2cpp_rgctx_method(method->rgctx_data, 2));
		V_14 = L_48;
		int32_t L_49 = V_14;
		int32_t L_50 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)400), L_49))) >= ((int32_t)L_50)))
		{
			goto IL_00f2;
		}
	}
	{
		return (-1);
	}

IL_00f2:
	{
		int32_t L_51 = V_14;
		int32_t L_52 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)400), L_51))) == ((int32_t)L_52)))
		{
			goto IL_012c;
		}
	}
	{
		int32_t L_53 = V_14;
		int32_t L_54 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)200), L_53))) == ((int32_t)L_54)))
		{
			goto IL_012c;
		}
	}
	{
		int32_t L_55 = V_14;
		int32_t L_56 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)100), L_55))) == ((int32_t)L_56)))
		{
			goto IL_012c;
		}
	}
	{
		int32_t L_57 = V_14;
		int32_t L_58 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)50), L_57))) == ((int32_t)L_58)))
		{
			goto IL_012c;
		}
	}
	{
		int32_t L_59 = V_14;
		int32_t L_60 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)25), L_59))) == ((int32_t)L_60)))
		{
			goto IL_012c;
		}
	}
	{
		int32_t L_61 = V_14;
		int32_t L_62 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)50), L_61))) == ((int32_t)((int32_t)il2cpp_codegen_multiply(3, L_62)))))
		{
			goto IL_012c;
		}
	}
	{
		return (-1);
	}

IL_012c:
	{
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_63 = __this->___layout;
		NullCheck(L_63);
		int32_t L_64 = L_63->___nb_streams;
		V_16 = ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_multiply(L_64, 2)), 1));
		int32_t L_65 = ___4_max_data_bytes;
		int32_t L_66 = V_16;
		if ((((int32_t)L_65) >= ((int32_t)L_66)))
		{
			goto IL_0146;
		}
	}
	{
		return ((int32_t)-2);
	}

IL_0146:
	{
		int32_t L_67 = V_14;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_68 = (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)SZArrayNew(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(2, L_67)));
		V_4 = L_68;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_69 = __this->___layout;
		NullCheck(L_69);
		int32_t L_70 = L_69->___nb_channels;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_71 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_70)));
		V_5 = L_71;
		int32_t L_72 = __this->___surround;
		if (!L_72)
		{
			goto IL_018d;
		}
	}
	{
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_73 = V_9;
		ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D L_74 = ___1_pcm;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_75 = V_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_76 = V_12;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_77 = V_13;
		int32_t L_78 = V_14;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_79 = __this->___layout;
		NullCheck(L_79);
		int32_t L_80 = L_79->___nb_channels;
		int32_t L_81 = V_0;
		opus_copy_channel_in_func_1_t484D84949EB9FE0FFB9617C739F465DE3E898F3F* L_82 = ___0_copy_channel_in;
		il2cpp_codegen_runtime_class_init_inline(OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_il2cpp_TypeInfo_var);
		OpusMSEncoder_surround_analysis_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m9B9E4738B7BD6EEABF4D6378222B971D6775D65B(L_73, L_74, L_75, L_76, L_77, L_78, ((int32_t)120), L_80, L_81, L_82, il2cpp_rgctx_method(method->rgctx_data, 4));
	}

IL_018d:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_83 = V_10;
		int32_t L_84 = V_14;
		int32_t L_85;
		L_85 = OpusMSEncoder_surround_rate_allocation_m0E90A088523C9263B2D659D378A7C1CCD306829B(__this, L_83, L_84, NULL);
		V_15 = L_85;
		int32_t L_86 = V_8;
		if (L_86)
		{
			goto IL_01ea;
		}
	}
	{
		int32_t L_87 = __this->___bitrate_bps;
		if ((!(((uint32_t)L_87) == ((uint32_t)((int32_t)-1000)))))
		{
			goto IL_01c1;
		}
	}
	{
		int32_t L_88 = ___4_max_data_bytes;
		int32_t L_89 = V_15;
		int32_t L_90 = V_0;
		int32_t L_91 = V_14;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_92;
		L_92 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(L_88, ((int32_t)(((int32_t)il2cpp_codegen_multiply(3, L_89))/((int32_t)(((int32_t)il2cpp_codegen_multiply(((int32_t)24), L_90))/L_91)))), NULL);
		___4_max_data_bytes = L_92;
		goto IL_01ea;
	}

IL_01c1:
	{
		int32_t L_93 = __this->___bitrate_bps;
		if ((((int32_t)L_93) == ((int32_t)(-1))))
		{
			goto IL_01ea;
		}
	}
	{
		int32_t L_94 = ___4_max_data_bytes;
		int32_t L_95 = V_16;
		int32_t L_96 = __this->___bitrate_bps;
		int32_t L_97 = V_0;
		int32_t L_98 = V_14;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_99;
		L_99 = Inlines_IMAX_mFECDD1F5C3C0962AF8B0140E78A6C3A25BCF9C23_inline(L_95, ((int32_t)(((int32_t)il2cpp_codegen_multiply(3, L_96))/((int32_t)(((int32_t)il2cpp_codegen_multiply(((int32_t)24), L_97))/L_98)))), NULL);
		int32_t L_100;
		L_100 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(L_94, L_99, NULL);
		___4_max_data_bytes = L_100;
	}

IL_01ea:
	{
		V_1 = 0;
		goto IL_02db;
	}

IL_01f1:
	{
		OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F* L_101 = __this->___encoders;
		int32_t L_102 = V_2;
		NullCheck(L_101);
		int32_t L_103 = L_102;
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_104 = (L_101)->GetAt(static_cast<il2cpp_array_size_t>(L_103));
		V_20 = L_104;
		int32_t L_105 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_105, 1));
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_106 = V_20;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_107 = V_10;
		int32_t L_108 = V_1;
		NullCheck(L_107);
		int32_t L_109 = L_108;
		int32_t L_110 = (L_107)->GetAt(static_cast<il2cpp_array_size_t>(L_109));
		NullCheck(L_106);
		OpusEncoder_set_Bitrate_m7B8AD5518E3DB9D28E3F376195747340D266AF6E(L_106, L_110, NULL);
		int32_t L_111 = __this->___surround;
		if (!L_111)
		{
			goto IL_02d7;
		}
	}
	{
		int32_t L_112 = __this->___bitrate_bps;
		V_21 = L_112;
		int32_t L_113 = V_14;
		int32_t L_114 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(L_113, ((int32_t)50)))) >= ((int32_t)L_114)))
		{
			goto IL_0240;
		}
	}
	{
		int32_t L_115 = V_21;
		int32_t L_116 = V_0;
		int32_t L_117 = V_14;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_118 = __this->___layout;
		NullCheck(L_118);
		int32_t L_119 = L_118->___nb_channels;
		V_21 = ((int32_t)il2cpp_codegen_subtract(L_115, ((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_multiply(((int32_t)60), ((int32_t)il2cpp_codegen_subtract(((int32_t)(L_116/L_117)), ((int32_t)50))))), L_119))));
	}

IL_0240:
	{
		int32_t L_120 = V_21;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_121 = __this->___layout;
		NullCheck(L_121);
		int32_t L_122 = L_121->___nb_channels;
		if ((((int32_t)L_120) <= ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)10000), L_122)))))
		{
			goto IL_0263;
		}
	}
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_123 = V_20;
		NullCheck(L_123);
		OpusEncoder_set_Bandwidth_m1401E2DE4B403C8A4CB8BEF736AE48C02861C726(L_123, (int32_t)((int32_t)1105), NULL);
		goto IL_02b5;
	}

IL_0263:
	{
		int32_t L_124 = V_21;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_125 = __this->___layout;
		NullCheck(L_125);
		int32_t L_126 = L_125->___nb_channels;
		if ((((int32_t)L_124) <= ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)7000), L_126)))))
		{
			goto IL_0286;
		}
	}
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_127 = V_20;
		NullCheck(L_127);
		OpusEncoder_set_Bandwidth_m1401E2DE4B403C8A4CB8BEF736AE48C02861C726(L_127, (int32_t)((int32_t)1104), NULL);
		goto IL_02b5;
	}

IL_0286:
	{
		int32_t L_128 = V_21;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_129 = __this->___layout;
		NullCheck(L_129);
		int32_t L_130 = L_129->___nb_channels;
		if ((((int32_t)L_128) <= ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)5000), L_130)))))
		{
			goto IL_02a9;
		}
	}
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_131 = V_20;
		NullCheck(L_131);
		OpusEncoder_set_Bandwidth_m1401E2DE4B403C8A4CB8BEF736AE48C02861C726(L_131, (int32_t)((int32_t)1103), NULL);
		goto IL_02b5;
	}

IL_02a9:
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_132 = V_20;
		NullCheck(L_132);
		OpusEncoder_set_Bandwidth_m1401E2DE4B403C8A4CB8BEF736AE48C02861C726(L_132, (int32_t)((int32_t)1101), NULL);
	}

IL_02b5:
	{
		int32_t L_133 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_134 = __this->___layout;
		NullCheck(L_134);
		int32_t L_135 = L_134->___nb_coupled_streams;
		if ((((int32_t)L_133) >= ((int32_t)L_135)))
		{
			goto IL_02d7;
		}
	}
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_136 = V_20;
		NullCheck(L_136);
		OpusEncoder_set_ForceMode_m27C03E1D80CD7B099DC5C9603ECCE70B99FB7201_inline(L_136, (int32_t)((int32_t)1002), NULL);
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_137 = V_20;
		NullCheck(L_137);
		OpusEncoder_set_ForceChannels_m23F0A9A42C5094A4E2B32DCE3479BEE9C3BCB2A8(L_137, 2, NULL);
	}

IL_02d7:
	{
		int32_t L_138 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_138, 1));
	}

IL_02db:
	{
		int32_t L_139 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_140 = __this->___layout;
		NullCheck(L_140);
		int32_t L_141 = L_140->___nb_streams;
		if ((((int32_t)L_139) < ((int32_t)L_141)))
		{
			goto IL_01f1;
		}
	}
	{
		V_2 = 0;
		V_3 = 0;
		V_1 = 0;
		goto IL_054d;
	}

IL_02f7:
	{
		OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* L_142 = V_7;
		NullCheck(L_142);
		OpusRepacketizer_Reset_m259455126D7AD3CFA796AA0B31C118D95D4C6AED(L_142, NULL);
		OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F* L_143 = __this->___encoders;
		int32_t L_144 = V_2;
		NullCheck(L_143);
		int32_t L_145 = L_144;
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_146 = (L_143)->GetAt(static_cast<il2cpp_array_size_t>(L_145));
		V_22 = L_146;
		int32_t L_147 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_148 = __this->___layout;
		NullCheck(L_148);
		int32_t L_149 = L_148->___nb_coupled_streams;
		if ((((int32_t)L_147) >= ((int32_t)L_149)))
		{
			goto IL_03bf;
		}
	}
	{
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_150 = __this->___layout;
		int32_t L_151 = V_1;
		int32_t L_152;
		L_152 = OpusMultistream_get_left_channel_mBC9BCAA485D1095C537AA8A8DFB38355DCB06A04(L_150, L_151, (-1), NULL);
		V_28 = L_152;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_153 = __this->___layout;
		int32_t L_154 = V_1;
		int32_t L_155;
		L_155 = OpusMultistream_get_right_channel_m1F24FA4BC9F11ADF386C3B9CAB948C1EBCC95C3F(L_153, L_154, (-1), NULL);
		V_29 = L_155;
		opus_copy_channel_in_func_1_t484D84949EB9FE0FFB9617C739F465DE3E898F3F* L_156 = ___0_copy_channel_in;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_157 = V_4;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_158;
		L_158 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_157, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D L_159 = ___1_pcm;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_160 = __this->___layout;
		NullCheck(L_160);
		int32_t L_161 = L_160->___nb_channels;
		int32_t L_162 = V_28;
		int32_t L_163 = V_14;
		NullCheck(L_156);
		opus_copy_channel_in_func_1_Invoke_m6D03E61EA06F045BA121921DC606E861E540D67D_inline(L_156, L_158, 0, 2, L_159, L_161, L_162, L_163, il2cpp_rgctx_method(method->rgctx_data, 5));
		opus_copy_channel_in_func_1_t484D84949EB9FE0FFB9617C739F465DE3E898F3F* L_164 = ___0_copy_channel_in;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_165 = V_4;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_166;
		L_166 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_165, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D L_167 = ___1_pcm;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_168 = __this->___layout;
		NullCheck(L_168);
		int32_t L_169 = L_168->___nb_channels;
		int32_t L_170 = V_29;
		int32_t L_171 = V_14;
		NullCheck(L_164);
		opus_copy_channel_in_func_1_Invoke_m6D03E61EA06F045BA121921DC606E861E540D67D_inline(L_164, L_166, 1, 2, L_167, L_169, L_170, L_171, il2cpp_rgctx_method(method->rgctx_data, 5));
		int32_t L_172 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_172, 1));
		int32_t L_173 = __this->___surround;
		if (!L_173)
		{
			goto IL_03b5;
		}
	}
	{
		V_27 = 0;
		goto IL_03af;
	}

IL_0386:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_174 = V_11;
		int32_t L_175 = V_27;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_176 = V_5;
		int32_t L_177 = V_28;
		int32_t L_178 = V_27;
		NullCheck(L_176);
		int32_t L_179 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_177)), L_178));
		int32_t L_180 = (L_176)->GetAt(static_cast<il2cpp_array_size_t>(L_179));
		NullCheck(L_174);
		(L_174)->SetAt(static_cast<il2cpp_array_size_t>(L_175), (int32_t)L_180);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_181 = V_11;
		int32_t L_182 = V_27;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_183 = V_5;
		int32_t L_184 = V_29;
		int32_t L_185 = V_27;
		NullCheck(L_183);
		int32_t L_186 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_184)), L_185));
		int32_t L_187 = (L_183)->GetAt(static_cast<il2cpp_array_size_t>(L_186));
		NullCheck(L_181);
		(L_181)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(((int32_t)21), L_182))), (int32_t)L_187);
		int32_t L_188 = V_27;
		V_27 = ((int32_t)il2cpp_codegen_add(L_188, 1));
	}

IL_03af:
	{
		int32_t L_189 = V_27;
		if ((((int32_t)L_189) < ((int32_t)((int32_t)21))))
		{
			goto IL_0386;
		}
	}

IL_03b5:
	{
		int32_t L_190 = V_28;
		V_25 = L_190;
		int32_t L_191 = V_29;
		V_26 = L_191;
		goto IL_0421;
	}

IL_03bf:
	{
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_192 = __this->___layout;
		int32_t L_193 = V_1;
		int32_t L_194;
		L_194 = OpusMultistream_get_mono_channel_mD28CFC9E8DF9F999251643576CECC59C132EA292(L_192, L_193, (-1), NULL);
		V_31 = L_194;
		opus_copy_channel_in_func_1_t484D84949EB9FE0FFB9617C739F465DE3E898F3F* L_195 = ___0_copy_channel_in;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_196 = V_4;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_197;
		L_197 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_196, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D L_198 = ___1_pcm;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_199 = __this->___layout;
		NullCheck(L_199);
		int32_t L_200 = L_199->___nb_channels;
		int32_t L_201 = V_31;
		int32_t L_202 = V_14;
		NullCheck(L_195);
		opus_copy_channel_in_func_1_Invoke_m6D03E61EA06F045BA121921DC606E861E540D67D_inline(L_195, L_197, 0, 1, L_198, L_200, L_201, L_202, il2cpp_rgctx_method(method->rgctx_data, 5));
		int32_t L_203 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_203, 1));
		int32_t L_204 = __this->___surround;
		if (!L_204)
		{
			goto IL_041a;
		}
	}
	{
		V_30 = 0;
		goto IL_0414;
	}

IL_03fe:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_205 = V_11;
		int32_t L_206 = V_30;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_207 = V_5;
		int32_t L_208 = V_31;
		int32_t L_209 = V_30;
		NullCheck(L_207);
		int32_t L_210 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_208)), L_209));
		int32_t L_211 = (L_207)->GetAt(static_cast<il2cpp_array_size_t>(L_210));
		NullCheck(L_205);
		(L_205)->SetAt(static_cast<il2cpp_array_size_t>(L_206), (int32_t)L_211);
		int32_t L_212 = V_30;
		V_30 = ((int32_t)il2cpp_codegen_add(L_212, 1));
	}

IL_0414:
	{
		int32_t L_213 = V_30;
		if ((((int32_t)L_213) < ((int32_t)((int32_t)21))))
		{
			goto IL_03fe;
		}
	}

IL_041a:
	{
		int32_t L_214 = V_31;
		V_25 = L_214;
		V_26 = (-1);
	}

IL_0421:
	{
		int32_t L_215 = __this->___surround;
		if (!L_215)
		{
			goto IL_0432;
		}
	}
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_216 = V_22;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_217 = V_11;
		NullCheck(L_216);
		OpusEncoder_SetEnergyMask_mF239BDE66F682A18292CE1F5BE2AADBA657E69E9(L_216, L_217, NULL);
	}

IL_0432:
	{
		int32_t L_218 = ___4_max_data_bytes;
		int32_t L_219 = V_3;
		V_24 = ((int32_t)il2cpp_codegen_subtract(L_218, L_219));
		int32_t L_220 = V_24;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_221 = __this->___layout;
		NullCheck(L_221);
		int32_t L_222 = L_221->___nb_streams;
		int32_t L_223 = V_1;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_224;
		L_224 = Inlines_IMAX_mFECDD1F5C3C0962AF8B0140E78A6C3A25BCF9C23_inline(0, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_multiply(2, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_222, L_223)), 1)))), 1)), NULL);
		V_24 = ((int32_t)il2cpp_codegen_subtract(L_220, L_224));
		int32_t L_225 = V_24;
		int32_t L_226;
		L_226 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(L_225, ((int32_t)3832), NULL);
		V_24 = L_226;
		int32_t L_227 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_228 = __this->___layout;
		NullCheck(L_228);
		int32_t L_229 = L_228->___nb_streams;
		if ((((int32_t)L_227) == ((int32_t)((int32_t)il2cpp_codegen_subtract(L_229, 1)))))
		{
			goto IL_0486;
		}
	}
	{
		int32_t L_230 = V_24;
		int32_t L_231 = V_24;
		if ((((int32_t)L_231) > ((int32_t)((int32_t)253))))
		{
			G_B55_0 = L_230;
			goto IL_0482;
		}
		G_B54_0 = L_230;
	}
	{
		G_B56_0 = 1;
		G_B56_1 = G_B54_0;
		goto IL_0483;
	}

IL_0482:
	{
		G_B56_0 = 2;
		G_B56_1 = G_B55_0;
	}

IL_0483:
	{
		V_24 = ((int32_t)il2cpp_codegen_subtract(G_B56_1, G_B56_0));
	}

IL_0486:
	{
		int32_t L_232 = V_8;
		if (L_232)
		{
			goto IL_04aa;
		}
	}
	{
		int32_t L_233 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_234 = __this->___layout;
		NullCheck(L_234);
		int32_t L_235 = L_234->___nb_streams;
		if ((!(((uint32_t)L_233) == ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_235, 1))))))
		{
			goto IL_04aa;
		}
	}
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_236 = V_22;
		int32_t L_237 = V_24;
		int32_t L_238 = V_0;
		int32_t L_239 = V_14;
		NullCheck(L_236);
		OpusEncoder_set_Bitrate_m7B8AD5518E3DB9D28E3F376195747340D266AF6E(L_236, ((int32_t)il2cpp_codegen_multiply(L_237, ((int32_t)(((int32_t)il2cpp_codegen_multiply(8, L_238))/L_239)))), NULL);
	}

IL_04aa:
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_240 = V_22;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_241 = V_4;
		ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 L_242;
		L_242 = ReadOnlySpan_1_op_Implicit_mCB2B03DD84141A56335B242E9AE355600A05C383(L_241, ReadOnlySpan_1_op_Implicit_mCB2B03DD84141A56335B242E9AE355600A05C383_RuntimeMethod_var);
		int32_t L_243 = V_14;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_244 = V_6;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_245;
		L_245 = Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91(L_244, Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91_RuntimeMethod_var);
		int32_t L_246 = V_24;
		int32_t L_247 = ___5_lsb_depth;
		ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D L_248 = ___1_pcm;
		int32_t L_249 = ___2_analysis_frame_size;
		int32_t L_250 = V_25;
		int32_t L_251 = V_26;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_252 = __this->___layout;
		NullCheck(L_252);
		int32_t L_253 = L_252->___nb_channels;
		downmix_func_1_t8CB50463E746CCBB4FFAE8EC889A02B92ED9F08B* L_254 = ___6_downmix;
		int32_t L_255 = ___7_float_api;
		NullCheck(L_240);
		int32_t L_256;
		L_256 = OpusEncoder_opus_encode_native_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_mEC592DA223E634EAE136DDFFF74F938B95E398F1(L_240, L_242, 0, L_243, L_245, 0, L_246, L_247, L_248, L_249, L_250, L_251, L_253, L_254, L_255, il2cpp_rgctx_method(method->rgctx_data, 6));
		V_23 = L_256;
		int32_t L_257 = V_23;
		if ((((int32_t)L_257) >= ((int32_t)0)))
		{
			goto IL_04e6;
		}
	}
	{
		int32_t L_258 = V_23;
		return L_258;
	}

IL_04e6:
	{
		OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* L_259 = V_7;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_260 = V_6;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_261;
		L_261 = Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91(L_260, Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91_RuntimeMethod_var);
		int32_t L_262 = V_23;
		NullCheck(L_259);
		int32_t L_263;
		L_263 = OpusRepacketizer_AddPacket_mEF0C260D9D7AF7EE2243A598509FBE6197D0F510(L_259, L_261, 0, L_262, NULL);
		OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* L_264 = V_7;
		OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* L_265 = V_7;
		NullCheck(L_265);
		int32_t L_266;
		L_266 = OpusRepacketizer_GetNumFrames_m2244AD084D7E8802DB6AC4A1F1CAEFDCBF125A23_inline(L_265, NULL);
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_267 = ___3_data;
		int32_t L_268 = V_17;
		int32_t L_269 = ___4_max_data_bytes;
		int32_t L_270 = V_3;
		int32_t L_271 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_272 = __this->___layout;
		NullCheck(L_272);
		int32_t L_273 = L_272->___nb_streams;
		if ((!(((uint32_t)L_271) == ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_273, 1))))))
		{
			G_B64_0 = ((int32_t)il2cpp_codegen_subtract(L_269, L_270));
			G_B64_1 = L_268;
			G_B64_2 = L_267;
			G_B64_3 = L_266;
			G_B64_4 = 0;
			G_B64_5 = L_264;
			goto IL_051d;
		}
		G_B63_0 = ((int32_t)il2cpp_codegen_subtract(L_269, L_270));
		G_B63_1 = L_268;
		G_B63_2 = L_267;
		G_B63_3 = L_266;
		G_B63_4 = 0;
		G_B63_5 = L_264;
	}
	{
		G_B65_0 = 0;
		G_B65_1 = G_B63_0;
		G_B65_2 = G_B63_1;
		G_B65_3 = G_B63_2;
		G_B65_4 = G_B63_3;
		G_B65_5 = G_B63_4;
		G_B65_6 = G_B63_5;
		goto IL_051e;
	}

IL_051d:
	{
		G_B65_0 = 1;
		G_B65_1 = G_B64_0;
		G_B65_2 = G_B64_1;
		G_B65_3 = G_B64_2;
		G_B65_4 = G_B64_3;
		G_B65_5 = G_B64_4;
		G_B65_6 = G_B64_5;
	}

IL_051e:
	{
		int32_t L_274 = V_8;
		if (L_274)
		{
			G_B67_0 = G_B65_0;
			G_B67_1 = G_B65_1;
			G_B67_2 = G_B65_2;
			G_B67_3 = G_B65_3;
			G_B67_4 = G_B65_4;
			G_B67_5 = G_B65_5;
			G_B67_6 = G_B65_6;
			goto IL_0532;
		}
		G_B66_0 = G_B65_0;
		G_B66_1 = G_B65_1;
		G_B66_2 = G_B65_2;
		G_B66_3 = G_B65_3;
		G_B66_4 = G_B65_4;
		G_B66_5 = G_B65_5;
		G_B66_6 = G_B65_6;
	}
	{
		int32_t L_275 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_276 = __this->___layout;
		NullCheck(L_276);
		int32_t L_277 = L_276->___nb_streams;
		if ((((int32_t)L_275) == ((int32_t)((int32_t)il2cpp_codegen_subtract(L_277, 1)))))
		{
			G_B68_0 = G_B66_0;
			G_B68_1 = G_B66_1;
			G_B68_2 = G_B66_2;
			G_B68_3 = G_B66_3;
			G_B68_4 = G_B66_4;
			G_B68_5 = G_B66_5;
			G_B68_6 = G_B66_6;
			goto IL_0535;
		}
		G_B67_0 = G_B66_0;
		G_B67_1 = G_B66_1;
		G_B67_2 = G_B66_2;
		G_B67_3 = G_B66_3;
		G_B67_4 = G_B66_4;
		G_B67_5 = G_B66_5;
		G_B67_6 = G_B66_6;
	}

IL_0532:
	{
		G_B69_0 = 0;
		G_B69_1 = G_B67_0;
		G_B69_2 = G_B67_1;
		G_B69_3 = G_B67_2;
		G_B69_4 = G_B67_3;
		G_B69_5 = G_B67_4;
		G_B69_6 = G_B67_5;
		G_B69_7 = G_B67_6;
		goto IL_0536;
	}

IL_0535:
	{
		G_B69_0 = 1;
		G_B69_1 = G_B68_0;
		G_B69_2 = G_B68_1;
		G_B69_3 = G_B68_2;
		G_B69_4 = G_B68_3;
		G_B69_5 = G_B68_4;
		G_B69_6 = G_B68_5;
		G_B69_7 = G_B68_6;
	}

IL_0536:
	{
		NullCheck(G_B69_7);
		int32_t L_278;
		L_278 = OpusRepacketizer_opus_repacketizer_out_range_impl_m580835FE0C1A5F8831B645CF5488B8ED9E443F13(G_B69_7, G_B69_6, G_B69_5, G_B69_4, G_B69_3, G_B69_2, G_B69_1, G_B69_0, NULL);
		V_23 = L_278;
		int32_t L_279 = V_17;
		int32_t L_280 = V_23;
		V_17 = ((int32_t)il2cpp_codegen_add(L_279, L_280));
		int32_t L_281 = V_3;
		int32_t L_282 = V_23;
		V_3 = ((int32_t)il2cpp_codegen_add(L_281, L_282));
		int32_t L_283 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_283, 1));
	}

IL_054d:
	{
		int32_t L_284 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_285 = __this->___layout;
		NullCheck(L_285);
		int32_t L_286 = L_285->___nb_streams;
		if ((((int32_t)L_284) < ((int32_t)L_286)))
		{
			goto IL_02f7;
		}
	}
	{
		int32_t L_287 = V_3;
		return L_287;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t OpusMSEncoder_opus_multistream_encode_native_TisIl2CppFullySharedGenericAny_m96FBAC5BA17A4DE3BA63A66B79F4BD59D0B2AA8D_gshared (OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573* __this, opus_copy_channel_in_func_1_tF3C7FBC38C3C10B5DF45A5E2E931749B4708E1B2* ___0_copy_channel_in, ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC ___1_pcm, int32_t ___2_analysis_frame_size, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___3_data, int32_t ___4_max_data_bytes, int32_t ___5_lsb_depth, downmix_func_1_t2D72777593561EEC6CFDD92FFD20BF708F537039* ___6_downmix, int32_t ___7_float_api, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ReadOnlySpan_1_op_Implicit_mCB2B03DD84141A56335B242E9AE355600A05C383_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* V_4 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_5 = NULL;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_6 = NULL;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* V_7 = NULL;
	int32_t V_8 = 0;
	CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* V_9 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_10 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_11 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_12 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_13 = NULL;
	int32_t V_14 = 0;
	int32_t V_15 = 0;
	int32_t V_16 = 0;
	int32_t V_17 = 0;
	int32_t V_18 = 0;
	int32_t V_19 = 0;
	OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* V_20 = NULL;
	int32_t V_21 = 0;
	OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* V_22 = NULL;
	int32_t V_23 = 0;
	int32_t V_24 = 0;
	int32_t V_25 = 0;
	int32_t V_26 = 0;
	int32_t V_27 = 0;
	int32_t V_28 = 0;
	int32_t V_29 = 0;
	int32_t V_30 = 0;
	int32_t V_31 = 0;
	int32_t G_B5_0 = 0;
	int32_t G_B55_0 = 0;
	int32_t G_B54_0 = 0;
	int32_t G_B56_0 = 0;
	int32_t G_B56_1 = 0;
	int32_t G_B64_0 = 0;
	int32_t G_B64_1 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B64_2;
	memset((&G_B64_2), 0, sizeof(G_B64_2));
	int32_t G_B64_3 = 0;
	int32_t G_B64_4 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B64_5 = NULL;
	int32_t G_B63_0 = 0;
	int32_t G_B63_1 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B63_2;
	memset((&G_B63_2), 0, sizeof(G_B63_2));
	int32_t G_B63_3 = 0;
	int32_t G_B63_4 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B63_5 = NULL;
	int32_t G_B65_0 = 0;
	int32_t G_B65_1 = 0;
	int32_t G_B65_2 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B65_3;
	memset((&G_B65_3), 0, sizeof(G_B65_3));
	int32_t G_B65_4 = 0;
	int32_t G_B65_5 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B65_6 = NULL;
	int32_t G_B67_0 = 0;
	int32_t G_B67_1 = 0;
	int32_t G_B67_2 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B67_3;
	memset((&G_B67_3), 0, sizeof(G_B67_3));
	int32_t G_B67_4 = 0;
	int32_t G_B67_5 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B67_6 = NULL;
	int32_t G_B66_0 = 0;
	int32_t G_B66_1 = 0;
	int32_t G_B66_2 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B66_3;
	memset((&G_B66_3), 0, sizeof(G_B66_3));
	int32_t G_B66_4 = 0;
	int32_t G_B66_5 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B66_6 = NULL;
	int32_t G_B68_0 = 0;
	int32_t G_B68_1 = 0;
	int32_t G_B68_2 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B68_3;
	memset((&G_B68_3), 0, sizeof(G_B68_3));
	int32_t G_B68_4 = 0;
	int32_t G_B68_5 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B68_6 = NULL;
	int32_t G_B69_0 = 0;
	int32_t G_B69_1 = 0;
	int32_t G_B69_2 = 0;
	int32_t G_B69_3 = 0;
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 G_B69_4;
	memset((&G_B69_4), 0, sizeof(G_B69_4));
	int32_t G_B69_5 = 0;
	int32_t G_B69_6 = 0;
	OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* G_B69_7 = NULL;
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)3832));
		V_6 = L_0;
		OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* L_1 = (OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0*)il2cpp_codegen_object_new(OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0_il2cpp_TypeInfo_var);
		OpusRepacketizer__ctor_mC4456456D2AAD30181CA3EC5FF721E31477B6996(L_1, NULL);
		V_7 = L_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_2 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)256));
		V_10 = L_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)42));
		V_11 = L_3;
		V_12 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		V_13 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		V_17 = 0;
		int32_t L_4 = __this->___surround;
		if (!L_4)
		{
			goto IL_0049;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = __this->___preemph_mem;
		V_13 = L_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_6 = __this->___window_mem;
		V_12 = L_6;
	}

IL_0049:
	{
		V_2 = 0;
		OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F* L_7 = __this->___encoders;
		int32_t L_8 = V_2;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		NullCheck(L_10);
		int32_t L_11;
		L_11 = OpusEncoder_get_SampleRate_m07B4CE6A7F1CAD6FA65936B9CF4F0F7536966E52_inline(L_10, NULL);
		V_0 = L_11;
		OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F* L_12 = __this->___encoders;
		int32_t L_13 = V_2;
		NullCheck(L_12);
		int32_t L_14 = L_13;
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_15 = (L_12)->GetAt(static_cast<il2cpp_array_size_t>(L_14));
		NullCheck(L_15);
		bool L_16;
		L_16 = OpusEncoder_get_UseVBR_m5476585F8DDFEC3AF5C54713C82340E7007A4389(L_15, NULL);
		if (L_16)
		{
			goto IL_006b;
		}
	}
	{
		G_B5_0 = 0;
		goto IL_006c;
	}

IL_006b:
	{
		G_B5_0 = 1;
	}

IL_006c:
	{
		V_8 = G_B5_0;
		OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F* L_17 = __this->___encoders;
		int32_t L_18 = V_2;
		NullCheck(L_17);
		int32_t L_19 = L_18;
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_20 = (L_17)->GetAt(static_cast<il2cpp_array_size_t>(L_19));
		NullCheck(L_20);
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_21;
		L_21 = OpusEncoder_GetCeltMode_m6EC596A3D230516010AAB28BE0D2EDF48B9B793D(L_20, NULL);
		V_9 = L_21;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_22 = __this->___layout;
		NullCheck(L_22);
		int32_t L_23 = L_22->___nb_streams;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_24 = __this->___layout;
		NullCheck(L_24);
		int32_t L_25 = L_24->___nb_coupled_streams;
		V_19 = ((int32_t)il2cpp_codegen_add(L_23, L_25));
		OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F* L_26 = __this->___encoders;
		int32_t L_27 = V_2;
		NullCheck(L_26);
		int32_t L_28 = L_27;
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_29 = (L_26)->GetAt(static_cast<il2cpp_array_size_t>(L_28));
		NullCheck(L_29);
		int32_t L_30;
		L_30 = OpusEncoder_get_Lookahead_mC173676834FE358C9449C8B6A791005CC854075E(L_29, NULL);
		V_18 = L_30;
		int32_t L_31 = V_18;
		int32_t L_32 = V_0;
		V_18 = ((int32_t)il2cpp_codegen_subtract(L_31, ((int32_t)(L_32/((int32_t)400)))));
		ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC L_33 = ___1_pcm;
		int32_t L_34 = ___2_analysis_frame_size;
		int32_t L_35 = __this->___variable_duration;
		int32_t L_36 = V_19;
		int32_t L_37 = V_0;
		int32_t L_38 = __this->___bitrate_bps;
		int32_t L_39 = V_18;
		downmix_func_1_t2D72777593561EEC6CFDD92FFD20BF708F537039* L_40 = ___6_downmix;
		SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* L_41 = __this->___subframe_mem;
		OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F* L_42 = __this->___encoders;
		int32_t L_43 = V_2;
		NullCheck(L_42);
		int32_t L_44 = L_43;
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_45 = (L_42)->GetAt(static_cast<il2cpp_array_size_t>(L_44));
		NullCheck(L_45);
		TonalityAnalysisState_tF14D4ECC485210CAEDF424EE770D87E25E3AD709* L_46 = L_45->___analysis;
		NullCheck(L_46);
		bool L_47 = L_46->___enabled;
		int32_t L_48;
		L_48 = ((  int32_t (*) (ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, downmix_func_1_t2D72777593561EEC6CFDD92FFD20BF708F537039*, SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C*, bool, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(L_33, L_34, L_35, L_36, L_37, L_38, L_39, L_40, L_41, L_47, il2cpp_rgctx_method(method->rgctx_data, 2));
		V_14 = L_48;
		int32_t L_49 = V_14;
		int32_t L_50 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)400), L_49))) >= ((int32_t)L_50)))
		{
			goto IL_00f2;
		}
	}
	{
		return (-1);
	}

IL_00f2:
	{
		int32_t L_51 = V_14;
		int32_t L_52 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)400), L_51))) == ((int32_t)L_52)))
		{
			goto IL_012c;
		}
	}
	{
		int32_t L_53 = V_14;
		int32_t L_54 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)200), L_53))) == ((int32_t)L_54)))
		{
			goto IL_012c;
		}
	}
	{
		int32_t L_55 = V_14;
		int32_t L_56 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)100), L_55))) == ((int32_t)L_56)))
		{
			goto IL_012c;
		}
	}
	{
		int32_t L_57 = V_14;
		int32_t L_58 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)50), L_57))) == ((int32_t)L_58)))
		{
			goto IL_012c;
		}
	}
	{
		int32_t L_59 = V_14;
		int32_t L_60 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)25), L_59))) == ((int32_t)L_60)))
		{
			goto IL_012c;
		}
	}
	{
		int32_t L_61 = V_14;
		int32_t L_62 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)50), L_61))) == ((int32_t)((int32_t)il2cpp_codegen_multiply(3, L_62)))))
		{
			goto IL_012c;
		}
	}
	{
		return (-1);
	}

IL_012c:
	{
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_63 = __this->___layout;
		NullCheck(L_63);
		int32_t L_64 = L_63->___nb_streams;
		V_16 = ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_multiply(L_64, 2)), 1));
		int32_t L_65 = ___4_max_data_bytes;
		int32_t L_66 = V_16;
		if ((((int32_t)L_65) >= ((int32_t)L_66)))
		{
			goto IL_0146;
		}
	}
	{
		return ((int32_t)-2);
	}

IL_0146:
	{
		int32_t L_67 = V_14;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_68 = (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)SZArrayNew(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(2, L_67)));
		V_4 = L_68;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_69 = __this->___layout;
		NullCheck(L_69);
		int32_t L_70 = L_69->___nb_channels;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_71 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_70)));
		V_5 = L_71;
		int32_t L_72 = __this->___surround;
		if (!L_72)
		{
			goto IL_018d;
		}
	}
	{
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_73 = V_9;
		ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC L_74 = ___1_pcm;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_75 = V_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_76 = V_12;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_77 = V_13;
		int32_t L_78 = V_14;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_79 = __this->___layout;
		NullCheck(L_79);
		int32_t L_80 = L_79->___nb_channels;
		int32_t L_81 = V_0;
		opus_copy_channel_in_func_1_tF3C7FBC38C3C10B5DF45A5E2E931749B4708E1B2* L_82 = ___0_copy_channel_in;
		il2cpp_codegen_runtime_class_init_inline(OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_il2cpp_TypeInfo_var);
		((  void (*) (CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5*, ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*, int32_t, int32_t, int32_t, int32_t, opus_copy_channel_in_func_1_tF3C7FBC38C3C10B5DF45A5E2E931749B4708E1B2*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)))(L_73, L_74, L_75, L_76, L_77, L_78, ((int32_t)120), L_80, L_81, L_82, il2cpp_rgctx_method(method->rgctx_data, 4));
	}

IL_018d:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_83 = V_10;
		int32_t L_84 = V_14;
		int32_t L_85;
		L_85 = OpusMSEncoder_surround_rate_allocation_m0E90A088523C9263B2D659D378A7C1CCD306829B(__this, L_83, L_84, NULL);
		V_15 = L_85;
		int32_t L_86 = V_8;
		if (L_86)
		{
			goto IL_01ea;
		}
	}
	{
		int32_t L_87 = __this->___bitrate_bps;
		if ((!(((uint32_t)L_87) == ((uint32_t)((int32_t)-1000)))))
		{
			goto IL_01c1;
		}
	}
	{
		int32_t L_88 = ___4_max_data_bytes;
		int32_t L_89 = V_15;
		int32_t L_90 = V_0;
		int32_t L_91 = V_14;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_92;
		L_92 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(L_88, ((int32_t)(((int32_t)il2cpp_codegen_multiply(3, L_89))/((int32_t)(((int32_t)il2cpp_codegen_multiply(((int32_t)24), L_90))/L_91)))), NULL);
		___4_max_data_bytes = L_92;
		goto IL_01ea;
	}

IL_01c1:
	{
		int32_t L_93 = __this->___bitrate_bps;
		if ((((int32_t)L_93) == ((int32_t)(-1))))
		{
			goto IL_01ea;
		}
	}
	{
		int32_t L_94 = ___4_max_data_bytes;
		int32_t L_95 = V_16;
		int32_t L_96 = __this->___bitrate_bps;
		int32_t L_97 = V_0;
		int32_t L_98 = V_14;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_99;
		L_99 = Inlines_IMAX_mFECDD1F5C3C0962AF8B0140E78A6C3A25BCF9C23_inline(L_95, ((int32_t)(((int32_t)il2cpp_codegen_multiply(3, L_96))/((int32_t)(((int32_t)il2cpp_codegen_multiply(((int32_t)24), L_97))/L_98)))), NULL);
		int32_t L_100;
		L_100 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(L_94, L_99, NULL);
		___4_max_data_bytes = L_100;
	}

IL_01ea:
	{
		V_1 = 0;
		goto IL_02db;
	}

IL_01f1:
	{
		OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F* L_101 = __this->___encoders;
		int32_t L_102 = V_2;
		NullCheck(L_101);
		int32_t L_103 = L_102;
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_104 = (L_101)->GetAt(static_cast<il2cpp_array_size_t>(L_103));
		V_20 = L_104;
		int32_t L_105 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_105, 1));
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_106 = V_20;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_107 = V_10;
		int32_t L_108 = V_1;
		NullCheck(L_107);
		int32_t L_109 = L_108;
		int32_t L_110 = (L_107)->GetAt(static_cast<il2cpp_array_size_t>(L_109));
		NullCheck(L_106);
		OpusEncoder_set_Bitrate_m7B8AD5518E3DB9D28E3F376195747340D266AF6E(L_106, L_110, NULL);
		int32_t L_111 = __this->___surround;
		if (!L_111)
		{
			goto IL_02d7;
		}
	}
	{
		int32_t L_112 = __this->___bitrate_bps;
		V_21 = L_112;
		int32_t L_113 = V_14;
		int32_t L_114 = V_0;
		if ((((int32_t)((int32_t)il2cpp_codegen_multiply(L_113, ((int32_t)50)))) >= ((int32_t)L_114)))
		{
			goto IL_0240;
		}
	}
	{
		int32_t L_115 = V_21;
		int32_t L_116 = V_0;
		int32_t L_117 = V_14;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_118 = __this->___layout;
		NullCheck(L_118);
		int32_t L_119 = L_118->___nb_channels;
		V_21 = ((int32_t)il2cpp_codegen_subtract(L_115, ((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_multiply(((int32_t)60), ((int32_t)il2cpp_codegen_subtract(((int32_t)(L_116/L_117)), ((int32_t)50))))), L_119))));
	}

IL_0240:
	{
		int32_t L_120 = V_21;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_121 = __this->___layout;
		NullCheck(L_121);
		int32_t L_122 = L_121->___nb_channels;
		if ((((int32_t)L_120) <= ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)10000), L_122)))))
		{
			goto IL_0263;
		}
	}
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_123 = V_20;
		NullCheck(L_123);
		OpusEncoder_set_Bandwidth_m1401E2DE4B403C8A4CB8BEF736AE48C02861C726(L_123, (int32_t)((int32_t)1105), NULL);
		goto IL_02b5;
	}

IL_0263:
	{
		int32_t L_124 = V_21;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_125 = __this->___layout;
		NullCheck(L_125);
		int32_t L_126 = L_125->___nb_channels;
		if ((((int32_t)L_124) <= ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)7000), L_126)))))
		{
			goto IL_0286;
		}
	}
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_127 = V_20;
		NullCheck(L_127);
		OpusEncoder_set_Bandwidth_m1401E2DE4B403C8A4CB8BEF736AE48C02861C726(L_127, (int32_t)((int32_t)1104), NULL);
		goto IL_02b5;
	}

IL_0286:
	{
		int32_t L_128 = V_21;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_129 = __this->___layout;
		NullCheck(L_129);
		int32_t L_130 = L_129->___nb_channels;
		if ((((int32_t)L_128) <= ((int32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)5000), L_130)))))
		{
			goto IL_02a9;
		}
	}
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_131 = V_20;
		NullCheck(L_131);
		OpusEncoder_set_Bandwidth_m1401E2DE4B403C8A4CB8BEF736AE48C02861C726(L_131, (int32_t)((int32_t)1103), NULL);
		goto IL_02b5;
	}

IL_02a9:
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_132 = V_20;
		NullCheck(L_132);
		OpusEncoder_set_Bandwidth_m1401E2DE4B403C8A4CB8BEF736AE48C02861C726(L_132, (int32_t)((int32_t)1101), NULL);
	}

IL_02b5:
	{
		int32_t L_133 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_134 = __this->___layout;
		NullCheck(L_134);
		int32_t L_135 = L_134->___nb_coupled_streams;
		if ((((int32_t)L_133) >= ((int32_t)L_135)))
		{
			goto IL_02d7;
		}
	}
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_136 = V_20;
		NullCheck(L_136);
		OpusEncoder_set_ForceMode_m27C03E1D80CD7B099DC5C9603ECCE70B99FB7201_inline(L_136, (int32_t)((int32_t)1002), NULL);
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_137 = V_20;
		NullCheck(L_137);
		OpusEncoder_set_ForceChannels_m23F0A9A42C5094A4E2B32DCE3479BEE9C3BCB2A8(L_137, 2, NULL);
	}

IL_02d7:
	{
		int32_t L_138 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_138, 1));
	}

IL_02db:
	{
		int32_t L_139 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_140 = __this->___layout;
		NullCheck(L_140);
		int32_t L_141 = L_140->___nb_streams;
		if ((((int32_t)L_139) < ((int32_t)L_141)))
		{
			goto IL_01f1;
		}
	}
	{
		V_2 = 0;
		V_3 = 0;
		V_1 = 0;
		goto IL_054d;
	}

IL_02f7:
	{
		OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* L_142 = V_7;
		NullCheck(L_142);
		OpusRepacketizer_Reset_m259455126D7AD3CFA796AA0B31C118D95D4C6AED(L_142, NULL);
		OpusEncoderU5BU5D_t58CF37BECBA4FB9AF656FD4209512FBA714D592F* L_143 = __this->___encoders;
		int32_t L_144 = V_2;
		NullCheck(L_143);
		int32_t L_145 = L_144;
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_146 = (L_143)->GetAt(static_cast<il2cpp_array_size_t>(L_145));
		V_22 = L_146;
		int32_t L_147 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_148 = __this->___layout;
		NullCheck(L_148);
		int32_t L_149 = L_148->___nb_coupled_streams;
		if ((((int32_t)L_147) >= ((int32_t)L_149)))
		{
			goto IL_03bf;
		}
	}
	{
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_150 = __this->___layout;
		int32_t L_151 = V_1;
		int32_t L_152;
		L_152 = OpusMultistream_get_left_channel_mBC9BCAA485D1095C537AA8A8DFB38355DCB06A04(L_150, L_151, (-1), NULL);
		V_28 = L_152;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_153 = __this->___layout;
		int32_t L_154 = V_1;
		int32_t L_155;
		L_155 = OpusMultistream_get_right_channel_m1F24FA4BC9F11ADF386C3B9CAB948C1EBCC95C3F(L_153, L_154, (-1), NULL);
		V_29 = L_155;
		opus_copy_channel_in_func_1_tF3C7FBC38C3C10B5DF45A5E2E931749B4708E1B2* L_156 = ___0_copy_channel_in;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_157 = V_4;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_158;
		L_158 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_157, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC L_159 = ___1_pcm;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_160 = __this->___layout;
		NullCheck(L_160);
		int32_t L_161 = L_160->___nb_channels;
		int32_t L_162 = V_28;
		int32_t L_163 = V_14;
		NullCheck(L_156);
		((  void (*) (opus_copy_channel_in_func_1_tF3C7FBC38C3C10B5DF45A5E2E931749B4708E1B2*, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D, int32_t, int32_t, ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 5)))(L_156, L_158, 0, 2, L_159, L_161, L_162, L_163, il2cpp_rgctx_method(method->rgctx_data, 5));
		opus_copy_channel_in_func_1_tF3C7FBC38C3C10B5DF45A5E2E931749B4708E1B2* L_164 = ___0_copy_channel_in;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_165 = V_4;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_166;
		L_166 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_165, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC L_167 = ___1_pcm;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_168 = __this->___layout;
		NullCheck(L_168);
		int32_t L_169 = L_168->___nb_channels;
		int32_t L_170 = V_29;
		int32_t L_171 = V_14;
		NullCheck(L_164);
		((  void (*) (opus_copy_channel_in_func_1_tF3C7FBC38C3C10B5DF45A5E2E931749B4708E1B2*, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D, int32_t, int32_t, ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 5)))(L_164, L_166, 1, 2, L_167, L_169, L_170, L_171, il2cpp_rgctx_method(method->rgctx_data, 5));
		int32_t L_172 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_172, 1));
		int32_t L_173 = __this->___surround;
		if (!L_173)
		{
			goto IL_03b5;
		}
	}
	{
		V_27 = 0;
		goto IL_03af;
	}

IL_0386:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_174 = V_11;
		int32_t L_175 = V_27;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_176 = V_5;
		int32_t L_177 = V_28;
		int32_t L_178 = V_27;
		NullCheck(L_176);
		int32_t L_179 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_177)), L_178));
		int32_t L_180 = (L_176)->GetAt(static_cast<il2cpp_array_size_t>(L_179));
		NullCheck(L_174);
		(L_174)->SetAt(static_cast<il2cpp_array_size_t>(L_175), (int32_t)L_180);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_181 = V_11;
		int32_t L_182 = V_27;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_183 = V_5;
		int32_t L_184 = V_29;
		int32_t L_185 = V_27;
		NullCheck(L_183);
		int32_t L_186 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_184)), L_185));
		int32_t L_187 = (L_183)->GetAt(static_cast<il2cpp_array_size_t>(L_186));
		NullCheck(L_181);
		(L_181)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(((int32_t)21), L_182))), (int32_t)L_187);
		int32_t L_188 = V_27;
		V_27 = ((int32_t)il2cpp_codegen_add(L_188, 1));
	}

IL_03af:
	{
		int32_t L_189 = V_27;
		if ((((int32_t)L_189) < ((int32_t)((int32_t)21))))
		{
			goto IL_0386;
		}
	}

IL_03b5:
	{
		int32_t L_190 = V_28;
		V_25 = L_190;
		int32_t L_191 = V_29;
		V_26 = L_191;
		goto IL_0421;
	}

IL_03bf:
	{
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_192 = __this->___layout;
		int32_t L_193 = V_1;
		int32_t L_194;
		L_194 = OpusMultistream_get_mono_channel_mD28CFC9E8DF9F999251643576CECC59C132EA292(L_192, L_193, (-1), NULL);
		V_31 = L_194;
		opus_copy_channel_in_func_1_tF3C7FBC38C3C10B5DF45A5E2E931749B4708E1B2* L_195 = ___0_copy_channel_in;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_196 = V_4;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_197;
		L_197 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_196, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC L_198 = ___1_pcm;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_199 = __this->___layout;
		NullCheck(L_199);
		int32_t L_200 = L_199->___nb_channels;
		int32_t L_201 = V_31;
		int32_t L_202 = V_14;
		NullCheck(L_195);
		((  void (*) (opus_copy_channel_in_func_1_tF3C7FBC38C3C10B5DF45A5E2E931749B4708E1B2*, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D, int32_t, int32_t, ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 5)))(L_195, L_197, 0, 1, L_198, L_200, L_201, L_202, il2cpp_rgctx_method(method->rgctx_data, 5));
		int32_t L_203 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_203, 1));
		int32_t L_204 = __this->___surround;
		if (!L_204)
		{
			goto IL_041a;
		}
	}
	{
		V_30 = 0;
		goto IL_0414;
	}

IL_03fe:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_205 = V_11;
		int32_t L_206 = V_30;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_207 = V_5;
		int32_t L_208 = V_31;
		int32_t L_209 = V_30;
		NullCheck(L_207);
		int32_t L_210 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_208)), L_209));
		int32_t L_211 = (L_207)->GetAt(static_cast<il2cpp_array_size_t>(L_210));
		NullCheck(L_205);
		(L_205)->SetAt(static_cast<il2cpp_array_size_t>(L_206), (int32_t)L_211);
		int32_t L_212 = V_30;
		V_30 = ((int32_t)il2cpp_codegen_add(L_212, 1));
	}

IL_0414:
	{
		int32_t L_213 = V_30;
		if ((((int32_t)L_213) < ((int32_t)((int32_t)21))))
		{
			goto IL_03fe;
		}
	}

IL_041a:
	{
		int32_t L_214 = V_31;
		V_25 = L_214;
		V_26 = (-1);
	}

IL_0421:
	{
		int32_t L_215 = __this->___surround;
		if (!L_215)
		{
			goto IL_0432;
		}
	}
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_216 = V_22;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_217 = V_11;
		NullCheck(L_216);
		OpusEncoder_SetEnergyMask_mF239BDE66F682A18292CE1F5BE2AADBA657E69E9(L_216, L_217, NULL);
	}

IL_0432:
	{
		int32_t L_218 = ___4_max_data_bytes;
		int32_t L_219 = V_3;
		V_24 = ((int32_t)il2cpp_codegen_subtract(L_218, L_219));
		int32_t L_220 = V_24;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_221 = __this->___layout;
		NullCheck(L_221);
		int32_t L_222 = L_221->___nb_streams;
		int32_t L_223 = V_1;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_224;
		L_224 = Inlines_IMAX_mFECDD1F5C3C0962AF8B0140E78A6C3A25BCF9C23_inline(0, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_multiply(2, ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_subtract(L_222, L_223)), 1)))), 1)), NULL);
		V_24 = ((int32_t)il2cpp_codegen_subtract(L_220, L_224));
		int32_t L_225 = V_24;
		int32_t L_226;
		L_226 = Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline(L_225, ((int32_t)3832), NULL);
		V_24 = L_226;
		int32_t L_227 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_228 = __this->___layout;
		NullCheck(L_228);
		int32_t L_229 = L_228->___nb_streams;
		if ((((int32_t)L_227) == ((int32_t)((int32_t)il2cpp_codegen_subtract(L_229, 1)))))
		{
			goto IL_0486;
		}
	}
	{
		int32_t L_230 = V_24;
		int32_t L_231 = V_24;
		if ((((int32_t)L_231) > ((int32_t)((int32_t)253))))
		{
			G_B55_0 = L_230;
			goto IL_0482;
		}
		G_B54_0 = L_230;
	}
	{
		G_B56_0 = 1;
		G_B56_1 = G_B54_0;
		goto IL_0483;
	}

IL_0482:
	{
		G_B56_0 = 2;
		G_B56_1 = G_B55_0;
	}

IL_0483:
	{
		V_24 = ((int32_t)il2cpp_codegen_subtract(G_B56_1, G_B56_0));
	}

IL_0486:
	{
		int32_t L_232 = V_8;
		if (L_232)
		{
			goto IL_04aa;
		}
	}
	{
		int32_t L_233 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_234 = __this->___layout;
		NullCheck(L_234);
		int32_t L_235 = L_234->___nb_streams;
		if ((!(((uint32_t)L_233) == ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_235, 1))))))
		{
			goto IL_04aa;
		}
	}
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_236 = V_22;
		int32_t L_237 = V_24;
		int32_t L_238 = V_0;
		int32_t L_239 = V_14;
		NullCheck(L_236);
		OpusEncoder_set_Bitrate_m7B8AD5518E3DB9D28E3F376195747340D266AF6E(L_236, ((int32_t)il2cpp_codegen_multiply(L_237, ((int32_t)(((int32_t)il2cpp_codegen_multiply(8, L_238))/L_239)))), NULL);
	}

IL_04aa:
	{
		OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* L_240 = V_22;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_241 = V_4;
		ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 L_242;
		L_242 = ReadOnlySpan_1_op_Implicit_mCB2B03DD84141A56335B242E9AE355600A05C383(L_241, ReadOnlySpan_1_op_Implicit_mCB2B03DD84141A56335B242E9AE355600A05C383_RuntimeMethod_var);
		int32_t L_243 = V_14;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_244 = V_6;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_245;
		L_245 = Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91(L_244, Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91_RuntimeMethod_var);
		int32_t L_246 = V_24;
		int32_t L_247 = ___5_lsb_depth;
		ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC L_248 = ___1_pcm;
		int32_t L_249 = ___2_analysis_frame_size;
		int32_t L_250 = V_25;
		int32_t L_251 = V_26;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_252 = __this->___layout;
		NullCheck(L_252);
		int32_t L_253 = L_252->___nb_channels;
		downmix_func_1_t2D72777593561EEC6CFDD92FFD20BF708F537039* L_254 = ___6_downmix;
		int32_t L_255 = ___7_float_api;
		NullCheck(L_240);
		int32_t L_256;
		L_256 = ((  int32_t (*) (OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44*, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71, int32_t, int32_t, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305, int32_t, int32_t, int32_t, ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC, int32_t, int32_t, int32_t, int32_t, downmix_func_1_t2D72777593561EEC6CFDD92FFD20BF708F537039*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 6)))(L_240, L_242, 0, L_243, L_245, 0, L_246, L_247, L_248, L_249, L_250, L_251, L_253, L_254, L_255, il2cpp_rgctx_method(method->rgctx_data, 6));
		V_23 = L_256;
		int32_t L_257 = V_23;
		if ((((int32_t)L_257) >= ((int32_t)0)))
		{
			goto IL_04e6;
		}
	}
	{
		int32_t L_258 = V_23;
		return L_258;
	}

IL_04e6:
	{
		OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* L_259 = V_7;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_260 = V_6;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_261;
		L_261 = Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91(L_260, Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91_RuntimeMethod_var);
		int32_t L_262 = V_23;
		NullCheck(L_259);
		int32_t L_263;
		L_263 = OpusRepacketizer_AddPacket_mEF0C260D9D7AF7EE2243A598509FBE6197D0F510(L_259, L_261, 0, L_262, NULL);
		OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* L_264 = V_7;
		OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* L_265 = V_7;
		NullCheck(L_265);
		int32_t L_266;
		L_266 = OpusRepacketizer_GetNumFrames_m2244AD084D7E8802DB6AC4A1F1CAEFDCBF125A23_inline(L_265, NULL);
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_267 = ___3_data;
		int32_t L_268 = V_17;
		int32_t L_269 = ___4_max_data_bytes;
		int32_t L_270 = V_3;
		int32_t L_271 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_272 = __this->___layout;
		NullCheck(L_272);
		int32_t L_273 = L_272->___nb_streams;
		if ((!(((uint32_t)L_271) == ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_273, 1))))))
		{
			G_B64_0 = ((int32_t)il2cpp_codegen_subtract(L_269, L_270));
			G_B64_1 = L_268;
			G_B64_2 = L_267;
			G_B64_3 = L_266;
			G_B64_4 = 0;
			G_B64_5 = L_264;
			goto IL_051d;
		}
		G_B63_0 = ((int32_t)il2cpp_codegen_subtract(L_269, L_270));
		G_B63_1 = L_268;
		G_B63_2 = L_267;
		G_B63_3 = L_266;
		G_B63_4 = 0;
		G_B63_5 = L_264;
	}
	{
		G_B65_0 = 0;
		G_B65_1 = G_B63_0;
		G_B65_2 = G_B63_1;
		G_B65_3 = G_B63_2;
		G_B65_4 = G_B63_3;
		G_B65_5 = G_B63_4;
		G_B65_6 = G_B63_5;
		goto IL_051e;
	}

IL_051d:
	{
		G_B65_0 = 1;
		G_B65_1 = G_B64_0;
		G_B65_2 = G_B64_1;
		G_B65_3 = G_B64_2;
		G_B65_4 = G_B64_3;
		G_B65_5 = G_B64_4;
		G_B65_6 = G_B64_5;
	}

IL_051e:
	{
		int32_t L_274 = V_8;
		if (L_274)
		{
			G_B67_0 = G_B65_0;
			G_B67_1 = G_B65_1;
			G_B67_2 = G_B65_2;
			G_B67_3 = G_B65_3;
			G_B67_4 = G_B65_4;
			G_B67_5 = G_B65_5;
			G_B67_6 = G_B65_6;
			goto IL_0532;
		}
		G_B66_0 = G_B65_0;
		G_B66_1 = G_B65_1;
		G_B66_2 = G_B65_2;
		G_B66_3 = G_B65_3;
		G_B66_4 = G_B65_4;
		G_B66_5 = G_B65_5;
		G_B66_6 = G_B65_6;
	}
	{
		int32_t L_275 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_276 = __this->___layout;
		NullCheck(L_276);
		int32_t L_277 = L_276->___nb_streams;
		if ((((int32_t)L_275) == ((int32_t)((int32_t)il2cpp_codegen_subtract(L_277, 1)))))
		{
			G_B68_0 = G_B66_0;
			G_B68_1 = G_B66_1;
			G_B68_2 = G_B66_2;
			G_B68_3 = G_B66_3;
			G_B68_4 = G_B66_4;
			G_B68_5 = G_B66_5;
			G_B68_6 = G_B66_6;
			goto IL_0535;
		}
		G_B67_0 = G_B66_0;
		G_B67_1 = G_B66_1;
		G_B67_2 = G_B66_2;
		G_B67_3 = G_B66_3;
		G_B67_4 = G_B66_4;
		G_B67_5 = G_B66_5;
		G_B67_6 = G_B66_6;
	}

IL_0532:
	{
		G_B69_0 = 0;
		G_B69_1 = G_B67_0;
		G_B69_2 = G_B67_1;
		G_B69_3 = G_B67_2;
		G_B69_4 = G_B67_3;
		G_B69_5 = G_B67_4;
		G_B69_6 = G_B67_5;
		G_B69_7 = G_B67_6;
		goto IL_0536;
	}

IL_0535:
	{
		G_B69_0 = 1;
		G_B69_1 = G_B68_0;
		G_B69_2 = G_B68_1;
		G_B69_3 = G_B68_2;
		G_B69_4 = G_B68_3;
		G_B69_5 = G_B68_4;
		G_B69_6 = G_B68_5;
		G_B69_7 = G_B68_6;
	}

IL_0536:
	{
		NullCheck(G_B69_7);
		int32_t L_278;
		L_278 = OpusRepacketizer_opus_repacketizer_out_range_impl_m580835FE0C1A5F8831B645CF5488B8ED9E443F13(G_B69_7, G_B69_6, G_B69_5, G_B69_4, G_B69_3, G_B69_2, G_B69_1, G_B69_0, NULL);
		V_23 = L_278;
		int32_t L_279 = V_17;
		int32_t L_280 = V_23;
		V_17 = ((int32_t)il2cpp_codegen_add(L_279, L_280));
		int32_t L_281 = V_3;
		int32_t L_282 = V_23;
		V_3 = ((int32_t)il2cpp_codegen_add(L_281, L_282));
		int32_t L_283 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_283, 1));
	}

IL_054d:
	{
		int32_t L_284 = V_1;
		ChannelLayout_tACCD26BF069B4C627D6A787CDD53113EDCB27A81* L_285 = __this->___layout;
		NullCheck(L_285);
		int32_t L_286 = L_285->___nb_streams;
		if ((((int32_t)L_284) < ((int32_t)L_286)))
		{
			goto IL_02f7;
		}
	}
	{
		int32_t L_287 = V_3;
		return L_287;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OpusMSEncoder_surround_analysis_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m6704E92CF00A6B3ECE45AA3E065DAA70429B4918_gshared (CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* ___0_celt_mode, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 ___1_pcm, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___2_bandLogE, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___3_mem, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___4_preemph_mem, int32_t ___5_len, int32_t ___6_overlap, int32_t ___7_channels, int32_t ___8_rate, opus_copy_channel_in_func_1_t73990C8C629DA94EEF8E66726DF516DDE7108033* ___9_copy_channel_in, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Bands_tD5744B61D102D4A0692787D6E9227EC981D1F873_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CeltCommon_t5CD2203CC4CC8046F30E401748B268C2C42530D1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&QuantizeBands_tE23B88063E2F1D6FE379FFF3D12B7E5A351F9284_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* V_7 = NULL;
	Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* V_8 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_9 = NULL;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* V_10 = NULL;
	Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* V_11 = NULL;
	BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* V_12 = NULL;
	int32_t V_13 = 0;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_14 = NULL;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)8);
		V_3 = L_0;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_1;
		L_1 = Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8(1, ((int32_t)21), Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8_RuntimeMethod_var);
		V_7 = L_1;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_2;
		L_2 = Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8(3, ((int32_t)21), Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8_RuntimeMethod_var);
		V_8 = L_2;
		int32_t L_3 = ___8_rate;
		il2cpp_codegen_runtime_class_init_inline(CeltCommon_t5CD2203CC4CC8046F30E401748B268C2C42530D1_il2cpp_TypeInfo_var);
		int32_t L_4;
		L_4 = CeltCommon_resampling_factor_m6C156552D07405BDE82F1EE6386D518515ACE3DD(L_3, NULL);
		V_4 = L_4;
		int32_t L_5 = ___5_len;
		int32_t L_6 = V_4;
		V_5 = ((int32_t)il2cpp_codegen_multiply(L_5, L_6));
		V_2 = 0;
		goto IL_0042;
	}

IL_002f:
	{
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_7 = ___0_celt_mode;
		NullCheck(L_7);
		int32_t L_8 = L_7->___shortMdctSize;
		int32_t L_9 = V_2;
		int32_t L_10 = V_5;
		if ((((int32_t)((int32_t)(L_8<<((int32_t)(L_9&((int32_t)31)))))) == ((int32_t)L_10)))
		{
			goto IL_004b;
		}
	}
	{
		int32_t L_11 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_0042:
	{
		int32_t L_12 = V_2;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_13 = ___0_celt_mode;
		NullCheck(L_13);
		int32_t L_14 = L_13->___maxLM;
		if ((((int32_t)L_12) < ((int32_t)L_14)))
		{
			goto IL_002f;
		}
	}

IL_004b:
	{
		int32_t L_15 = V_5;
		int32_t L_16 = ___6_overlap;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_17 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_add(L_15, L_16)));
		V_9 = L_17;
		int32_t L_18 = ___5_len;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_19 = (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)SZArrayNew(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var, (uint32_t)L_18);
		V_10 = L_19;
		int32_t L_20 = V_5;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_21;
		L_21 = Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8(1, L_20, Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8_RuntimeMethod_var);
		V_11 = L_21;
		int32_t L_22 = ___7_channels;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_23 = V_3;
		il2cpp_codegen_runtime_class_init_inline(OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_il2cpp_TypeInfo_var);
		OpusMSEncoder_channel_pos_m5FF9B9CDE29B029E06F5AF09EFD8359BFAE20B6E(L_22, L_23, NULL);
		V_0 = 0;
		goto IL_0092;
	}

IL_0076:
	{
		V_1 = 0;
		goto IL_0089;
	}

IL_007a:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_24 = V_8;
		int32_t L_25 = V_0;
		NullCheck(L_24);
		int32_t L_26 = L_25;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_27 = (L_24)->GetAt(static_cast<il2cpp_array_size_t>(L_26));
		int32_t L_28 = V_1;
		NullCheck(L_27);
		(L_27)->SetAt(static_cast<il2cpp_array_size_t>(L_28), (int32_t)((int32_t)-28672));
		int32_t L_29 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_0089:
	{
		int32_t L_30 = V_1;
		if ((((int32_t)L_30) < ((int32_t)((int32_t)21))))
		{
			goto IL_007a;
		}
	}
	{
		int32_t L_31 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_31, 1));
	}

IL_0092:
	{
		int32_t L_32 = V_0;
		if ((((int32_t)L_32) < ((int32_t)3)))
		{
			goto IL_0076;
		}
	}
	{
		V_0 = 0;
		goto IL_02a8;
	}

IL_009d:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_33 = ___3_mem;
		int32_t L_34 = V_0;
		int32_t L_35 = ___6_overlap;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_36 = V_9;
		int32_t L_37 = ___6_overlap;
		Arrays_MemCopy_m3B172AAA9447D50DF1AE71C15662FB5005858B3F(L_33, ((int32_t)il2cpp_codegen_multiply(L_34, L_35)), L_36, 0, L_37, NULL);
		opus_copy_channel_in_func_1_t73990C8C629DA94EEF8E66726DF516DDE7108033* L_38 = ___9_copy_channel_in;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_39 = V_10;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_40;
		L_40 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_39, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 L_41 = ___1_pcm;
		int32_t L_42 = ___7_channels;
		int32_t L_43 = V_0;
		int32_t L_44 = ___5_len;
		NullCheck(L_38);
		opus_copy_channel_in_func_1_Invoke_mE863D518D4E113322D44FEBB0E6A4112575A199E_inline(L_38, L_40, 0, 1, L_41, L_42, L_43, L_44, il2cpp_rgctx_method(method->rgctx_data, 2));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_45 = ___4_preemph_mem;
		int32_t L_46 = V_0;
		NullCheck(L_45);
		int32_t L_47 = L_46;
		int32_t L_48 = (L_45)->GetAt(static_cast<il2cpp_array_size_t>(L_47));
		BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* L_49 = (BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026*)il2cpp_codegen_object_new(BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026_il2cpp_TypeInfo_var);
		BoxedValueInt__ctor_m6EC58F06F4673535F2682F1731C6F36FC073A36A(L_49, L_48, NULL);
		V_12 = L_49;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_50 = V_10;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_51 = V_9;
		Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 L_52;
		L_52 = Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC(L_51, Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC_RuntimeMethod_var);
		int32_t L_53 = ___6_overlap;
		int32_t L_54 = V_5;
		int32_t L_55 = V_4;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_56 = ___0_celt_mode;
		NullCheck(L_56);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_57 = L_56->___preemph;
		BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* L_58 = V_12;
		il2cpp_codegen_runtime_class_init_inline(CeltCommon_t5CD2203CC4CC8046F30E401748B268C2C42530D1_il2cpp_TypeInfo_var);
		CeltCommon_celt_preemphasis_m21C67E565A36929D27B417626A565BC7B688FC23(L_50, L_52, L_53, L_54, 1, L_55, L_57, L_58, 0, NULL);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_59 = ___4_preemph_mem;
		int32_t L_60 = V_0;
		BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* L_61 = V_12;
		NullCheck(L_61);
		int32_t L_62 = L_61->___Val;
		NullCheck(L_59);
		(L_59)->SetAt(static_cast<il2cpp_array_size_t>(L_60), (int32_t)L_62);
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_63 = ___0_celt_mode;
		NullCheck(L_63);
		MDCTLookup_t1A4D19310C741D19B9223906DB1F8DF9142B47F0* L_64 = L_63->___mdct;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_65 = V_9;
		Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 L_66;
		L_66 = Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC(L_65, Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC_RuntimeMethod_var);
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_67 = V_11;
		NullCheck(L_67);
		int32_t L_68 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_69 = (L_67)->GetAt(static_cast<il2cpp_array_size_t>(L_68));
		Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 L_70;
		L_70 = Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC(L_69, Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC_RuntimeMethod_var);
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_71 = ___0_celt_mode;
		NullCheck(L_71);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_72 = L_71->___window;
		int32_t L_73 = ___6_overlap;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_74 = ___0_celt_mode;
		NullCheck(L_74);
		int32_t L_75 = L_74->___maxLM;
		int32_t L_76 = V_2;
		MDCT_clt_mdct_forward_m574EDCF759544B7757CA02E5A5B9CD44ABD80793(L_64, L_66, 0, L_70, 0, L_72, L_73, ((int32_t)il2cpp_codegen_subtract(L_75, L_76)), 1, NULL);
		int32_t L_77 = V_4;
		if ((((int32_t)L_77) == ((int32_t)1)))
		{
			goto IL_015c;
		}
	}
	{
		int32_t L_78 = ___5_len;
		V_13 = L_78;
		V_1 = 0;
		goto IL_0145;
	}

IL_0131:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_79 = V_11;
		NullCheck(L_79);
		int32_t L_80 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_81 = (L_79)->GetAt(static_cast<il2cpp_array_size_t>(L_80));
		int32_t L_82 = V_1;
		NullCheck(L_81);
		int32_t* L_83 = ((L_81)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_82)));
		int32_t L_84 = *((int32_t*)L_83);
		int32_t L_85 = V_4;
		*((int32_t*)L_83) = (int32_t)((int32_t)il2cpp_codegen_multiply(L_84, L_85));
		int32_t L_86 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_86, 1));
	}

IL_0145:
	{
		int32_t L_87 = V_1;
		int32_t L_88 = V_13;
		if ((((int32_t)L_87) < ((int32_t)L_88)))
		{
			goto IL_0131;
		}
	}
	{
		goto IL_0157;
	}

IL_014c:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_89 = V_11;
		NullCheck(L_89);
		int32_t L_90 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_91 = (L_89)->GetAt(static_cast<il2cpp_array_size_t>(L_90));
		int32_t L_92 = V_1;
		NullCheck(L_91);
		(L_91)->SetAt(static_cast<il2cpp_array_size_t>(L_92), (int32_t)0);
		int32_t L_93 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_93, 1));
	}

IL_0157:
	{
		int32_t L_94 = V_1;
		int32_t L_95 = V_5;
		if ((((int32_t)L_94) < ((int32_t)L_95)))
		{
			goto IL_014c;
		}
	}

IL_015c:
	{
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_96 = ___0_celt_mode;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_97 = V_11;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_98 = V_7;
		int32_t L_99 = V_2;
		il2cpp_codegen_runtime_class_init_inline(Bands_tD5744B61D102D4A0692787D6E9227EC981D1F873_il2cpp_TypeInfo_var);
		Bands_compute_band_energies_m6162BA578721FCAFBD60AFCB17CB0B7F2753AB26(L_96, L_97, L_98, ((int32_t)21), 1, L_99, NULL);
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_100 = ___0_celt_mode;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_101 = V_7;
		NullCheck(L_101);
		int32_t L_102 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_103 = (L_101)->GetAt(static_cast<il2cpp_array_size_t>(L_102));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_104 = ___2_bandLogE;
		Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 L_105;
		L_105 = Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC(L_104, Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC_RuntimeMethod_var);
		int32_t L_106 = V_0;
		il2cpp_codegen_runtime_class_init_inline(QuantizeBands_tE23B88063E2F1D6FE379FFF3D12B7E5A351F9284_il2cpp_TypeInfo_var);
		QuantizeBands_amp2Log2_m0C280EEAE3F9FA53CC72CC1A6E5EF65E2EC2AF8F(L_100, ((int32_t)21), ((int32_t)21), L_103, L_105, ((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_106)), 1, NULL);
		V_1 = 1;
		goto IL_01b0;
	}

IL_0187:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_107 = ___2_bandLogE;
		int32_t L_108 = V_0;
		int32_t L_109 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_110 = ___2_bandLogE;
		int32_t L_111 = V_0;
		int32_t L_112 = V_1;
		NullCheck(L_110);
		int32_t L_113 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_111)), L_112));
		int32_t L_114 = (L_110)->GetAt(static_cast<il2cpp_array_size_t>(L_113));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_115 = ___2_bandLogE;
		int32_t L_116 = V_0;
		int32_t L_117 = V_1;
		NullCheck(L_115);
		int32_t L_118 = ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_116)), L_117)), 1));
		int32_t L_119 = (L_115)->GetAt(static_cast<il2cpp_array_size_t>(L_118));
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_120;
		L_120 = Inlines_MAX16_m4D603BAD0F242EB66ED76BE982BC3907D9DF44A5_inline(L_114, ((int32_t)il2cpp_codegen_subtract(L_119, ((int32_t)1024))), NULL);
		NullCheck(L_107);
		(L_107)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_108)), L_109))), (int32_t)L_120);
		int32_t L_121 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_121, 1));
	}

IL_01b0:
	{
		int32_t L_122 = V_1;
		if ((((int32_t)L_122) < ((int32_t)((int32_t)21))))
		{
			goto IL_0187;
		}
	}
	{
		V_1 = ((int32_t)19);
		goto IL_01e3;
	}

IL_01ba:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_123 = ___2_bandLogE;
		int32_t L_124 = V_0;
		int32_t L_125 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_126 = ___2_bandLogE;
		int32_t L_127 = V_0;
		int32_t L_128 = V_1;
		NullCheck(L_126);
		int32_t L_129 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_127)), L_128));
		int32_t L_130 = (L_126)->GetAt(static_cast<il2cpp_array_size_t>(L_129));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_131 = ___2_bandLogE;
		int32_t L_132 = V_0;
		int32_t L_133 = V_1;
		NullCheck(L_131);
		int32_t L_134 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_132)), L_133)), 1));
		int32_t L_135 = (L_131)->GetAt(static_cast<il2cpp_array_size_t>(L_134));
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_136;
		L_136 = Inlines_MAX16_m4D603BAD0F242EB66ED76BE982BC3907D9DF44A5_inline(L_130, ((int32_t)il2cpp_codegen_subtract(L_135, ((int32_t)2048))), NULL);
		NullCheck(L_123);
		(L_123)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_124)), L_125))), (int32_t)L_136);
		int32_t L_137 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_subtract(L_137, 1));
	}

IL_01e3:
	{
		int32_t L_138 = V_1;
		if ((((int32_t)L_138) >= ((int32_t)0)))
		{
			goto IL_01ba;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_139 = V_3;
		int32_t L_140 = V_0;
		NullCheck(L_139);
		int32_t L_141 = L_140;
		int32_t L_142 = (L_139)->GetAt(static_cast<il2cpp_array_size_t>(L_141));
		if ((!(((uint32_t)L_142) == ((uint32_t)1))))
		{
			goto IL_0215;
		}
	}
	{
		V_1 = 0;
		goto IL_020e;
	}

IL_01f1:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_143 = V_8;
		NullCheck(L_143);
		int32_t L_144 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_145 = (L_143)->GetAt(static_cast<il2cpp_array_size_t>(L_144));
		int32_t L_146 = V_1;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_147 = V_8;
		NullCheck(L_147);
		int32_t L_148 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_149 = (L_147)->GetAt(static_cast<il2cpp_array_size_t>(L_148));
		int32_t L_150 = V_1;
		NullCheck(L_149);
		int32_t L_151 = L_150;
		int32_t L_152 = (L_149)->GetAt(static_cast<il2cpp_array_size_t>(L_151));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_153 = ___2_bandLogE;
		int32_t L_154 = V_0;
		int32_t L_155 = V_1;
		NullCheck(L_153);
		int32_t L_156 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_154)), L_155));
		int32_t L_157 = (L_153)->GetAt(static_cast<il2cpp_array_size_t>(L_156));
		il2cpp_codegen_runtime_class_init_inline(OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_il2cpp_TypeInfo_var);
		int32_t L_158;
		L_158 = OpusMSEncoder_logSum_mC189C2CAB88090345C3C24D4D5C103F0D5341A87(L_152, L_157, NULL);
		NullCheck(L_145);
		(L_145)->SetAt(static_cast<il2cpp_array_size_t>(L_146), (int32_t)L_158);
		int32_t L_159 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_159, 1));
	}

IL_020e:
	{
		int32_t L_160 = V_1;
		if ((((int32_t)L_160) < ((int32_t)((int32_t)21))))
		{
			goto IL_01f1;
		}
	}
	{
		goto IL_0294;
	}

IL_0215:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_161 = V_3;
		int32_t L_162 = V_0;
		NullCheck(L_161);
		int32_t L_163 = L_162;
		int32_t L_164 = (L_161)->GetAt(static_cast<il2cpp_array_size_t>(L_163));
		if ((!(((uint32_t)L_164) == ((uint32_t)3))))
		{
			goto IL_0243;
		}
	}
	{
		V_1 = 0;
		goto IL_023c;
	}

IL_021f:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_165 = V_8;
		NullCheck(L_165);
		int32_t L_166 = 2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_167 = (L_165)->GetAt(static_cast<il2cpp_array_size_t>(L_166));
		int32_t L_168 = V_1;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_169 = V_8;
		NullCheck(L_169);
		int32_t L_170 = 2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_171 = (L_169)->GetAt(static_cast<il2cpp_array_size_t>(L_170));
		int32_t L_172 = V_1;
		NullCheck(L_171);
		int32_t L_173 = L_172;
		int32_t L_174 = (L_171)->GetAt(static_cast<il2cpp_array_size_t>(L_173));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_175 = ___2_bandLogE;
		int32_t L_176 = V_0;
		int32_t L_177 = V_1;
		NullCheck(L_175);
		int32_t L_178 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_176)), L_177));
		int32_t L_179 = (L_175)->GetAt(static_cast<il2cpp_array_size_t>(L_178));
		il2cpp_codegen_runtime_class_init_inline(OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_il2cpp_TypeInfo_var);
		int32_t L_180;
		L_180 = OpusMSEncoder_logSum_mC189C2CAB88090345C3C24D4D5C103F0D5341A87(L_174, L_179, NULL);
		NullCheck(L_167);
		(L_167)->SetAt(static_cast<il2cpp_array_size_t>(L_168), (int32_t)L_180);
		int32_t L_181 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_181, 1));
	}

IL_023c:
	{
		int32_t L_182 = V_1;
		if ((((int32_t)L_182) < ((int32_t)((int32_t)21))))
		{
			goto IL_021f;
		}
	}
	{
		goto IL_0294;
	}

IL_0243:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_183 = V_3;
		int32_t L_184 = V_0;
		NullCheck(L_183);
		int32_t L_185 = L_184;
		int32_t L_186 = (L_183)->GetAt(static_cast<il2cpp_array_size_t>(L_185));
		if ((!(((uint32_t)L_186) == ((uint32_t)2))))
		{
			goto IL_0294;
		}
	}
	{
		V_1 = 0;
		goto IL_028f;
	}

IL_024d:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_187 = V_8;
		NullCheck(L_187);
		int32_t L_188 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_189 = (L_187)->GetAt(static_cast<il2cpp_array_size_t>(L_188));
		int32_t L_190 = V_1;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_191 = V_8;
		NullCheck(L_191);
		int32_t L_192 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_193 = (L_191)->GetAt(static_cast<il2cpp_array_size_t>(L_192));
		int32_t L_194 = V_1;
		NullCheck(L_193);
		int32_t L_195 = L_194;
		int32_t L_196 = (L_193)->GetAt(static_cast<il2cpp_array_size_t>(L_195));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_197 = ___2_bandLogE;
		int32_t L_198 = V_0;
		int32_t L_199 = V_1;
		NullCheck(L_197);
		int32_t L_200 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_198)), L_199));
		int32_t L_201 = (L_197)->GetAt(static_cast<il2cpp_array_size_t>(L_200));
		il2cpp_codegen_runtime_class_init_inline(OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_il2cpp_TypeInfo_var);
		int32_t L_202;
		L_202 = OpusMSEncoder_logSum_mC189C2CAB88090345C3C24D4D5C103F0D5341A87(L_196, ((int32_t)il2cpp_codegen_subtract(L_201, ((int32_t)512))), NULL);
		NullCheck(L_189);
		(L_189)->SetAt(static_cast<il2cpp_array_size_t>(L_190), (int32_t)L_202);
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_203 = V_8;
		NullCheck(L_203);
		int32_t L_204 = 2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_205 = (L_203)->GetAt(static_cast<il2cpp_array_size_t>(L_204));
		int32_t L_206 = V_1;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_207 = V_8;
		NullCheck(L_207);
		int32_t L_208 = 2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_209 = (L_207)->GetAt(static_cast<il2cpp_array_size_t>(L_208));
		int32_t L_210 = V_1;
		NullCheck(L_209);
		int32_t L_211 = L_210;
		int32_t L_212 = (L_209)->GetAt(static_cast<il2cpp_array_size_t>(L_211));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_213 = ___2_bandLogE;
		int32_t L_214 = V_0;
		int32_t L_215 = V_1;
		NullCheck(L_213);
		int32_t L_216 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_214)), L_215));
		int32_t L_217 = (L_213)->GetAt(static_cast<il2cpp_array_size_t>(L_216));
		int32_t L_218;
		L_218 = OpusMSEncoder_logSum_mC189C2CAB88090345C3C24D4D5C103F0D5341A87(L_212, ((int32_t)il2cpp_codegen_subtract(L_217, ((int32_t)512))), NULL);
		NullCheck(L_205);
		(L_205)->SetAt(static_cast<il2cpp_array_size_t>(L_206), (int32_t)L_218);
		int32_t L_219 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_219, 1));
	}

IL_028f:
	{
		int32_t L_220 = V_1;
		if ((((int32_t)L_220) < ((int32_t)((int32_t)21))))
		{
			goto IL_024d;
		}
	}

IL_0294:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_221 = V_9;
		int32_t L_222 = V_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_223 = ___3_mem;
		int32_t L_224 = V_0;
		int32_t L_225 = ___6_overlap;
		int32_t L_226 = ___6_overlap;
		Arrays_MemCopy_m3B172AAA9447D50DF1AE71C15662FB5005858B3F(L_221, L_222, L_223, ((int32_t)il2cpp_codegen_multiply(L_224, L_225)), L_226, NULL);
		int32_t L_227 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_227, 1));
	}

IL_02a8:
	{
		int32_t L_228 = V_0;
		int32_t L_229 = ___7_channels;
		if ((((int32_t)L_228) < ((int32_t)L_229)))
		{
			goto IL_009d;
		}
	}
	{
		V_1 = 0;
		goto IL_02cf;
	}

IL_02b4:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_230 = V_8;
		NullCheck(L_230);
		int32_t L_231 = 1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_232 = (L_230)->GetAt(static_cast<il2cpp_array_size_t>(L_231));
		int32_t L_233 = V_1;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_234 = V_8;
		NullCheck(L_234);
		int32_t L_235 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_236 = (L_234)->GetAt(static_cast<il2cpp_array_size_t>(L_235));
		int32_t L_237 = V_1;
		NullCheck(L_236);
		int32_t L_238 = L_237;
		int32_t L_239 = (L_236)->GetAt(static_cast<il2cpp_array_size_t>(L_238));
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_240 = V_8;
		NullCheck(L_240);
		int32_t L_241 = 2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_242 = (L_240)->GetAt(static_cast<il2cpp_array_size_t>(L_241));
		int32_t L_243 = V_1;
		NullCheck(L_242);
		int32_t L_244 = L_243;
		int32_t L_245 = (L_242)->GetAt(static_cast<il2cpp_array_size_t>(L_244));
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_246;
		L_246 = Inlines_MIN32_mE77013C78A201F2EF11AE030F4E6DFC4815008F9_inline(L_239, L_245, NULL);
		NullCheck(L_232);
		(L_232)->SetAt(static_cast<il2cpp_array_size_t>(L_233), (int32_t)L_246);
		int32_t L_247 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_247, 1));
	}

IL_02cf:
	{
		int32_t L_248 = V_1;
		if ((((int32_t)L_248) < ((int32_t)((int32_t)21))))
		{
			goto IL_02b4;
		}
	}
	{
		int32_t L_249 = ___7_channels;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_250;
		L_250 = Inlines_celt_log2_m72E298D8304AC7AB2F8334898CA897FF185F8784_inline(((int32_t)(((int32_t)32768)/((int32_t)il2cpp_codegen_subtract(L_249, 1)))), NULL);
		int32_t L_251;
		L_251 = Inlines_HALF16_mCC975475CB9BE63D15752AA7AA0F3E44598ADB4D_inline(L_250, NULL);
		V_6 = L_251;
		V_0 = 0;
		goto IL_030f;
	}

IL_02ee:
	{
		V_1 = 0;
		goto IL_0306;
	}

IL_02f2:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_252 = V_8;
		int32_t L_253 = V_0;
		NullCheck(L_252);
		int32_t L_254 = L_253;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_255 = (L_252)->GetAt(static_cast<il2cpp_array_size_t>(L_254));
		int32_t L_256 = V_1;
		NullCheck(L_255);
		int32_t* L_257 = ((L_255)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_256)));
		int32_t L_258 = *((int32_t*)L_257);
		int32_t L_259 = V_6;
		*((int32_t*)L_257) = (int32_t)((int32_t)il2cpp_codegen_add(L_258, L_259));
		int32_t L_260 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_260, 1));
	}

IL_0306:
	{
		int32_t L_261 = V_1;
		if ((((int32_t)L_261) < ((int32_t)((int32_t)21))))
		{
			goto IL_02f2;
		}
	}
	{
		int32_t L_262 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_262, 1));
	}

IL_030f:
	{
		int32_t L_263 = V_0;
		if ((((int32_t)L_263) < ((int32_t)3)))
		{
			goto IL_02ee;
		}
	}
	{
		V_0 = 0;
		goto IL_0364;
	}

IL_0317:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_264 = V_3;
		int32_t L_265 = V_0;
		NullCheck(L_264);
		int32_t L_266 = L_265;
		int32_t L_267 = (L_264)->GetAt(static_cast<il2cpp_array_size_t>(L_266));
		if (!L_267)
		{
			goto IL_034a;
		}
	}
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_268 = V_8;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_269 = V_3;
		int32_t L_270 = V_0;
		NullCheck(L_269);
		int32_t L_271 = L_270;
		int32_t L_272 = (L_269)->GetAt(static_cast<il2cpp_array_size_t>(L_271));
		NullCheck(L_268);
		int32_t L_273 = ((int32_t)il2cpp_codegen_subtract(L_272, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_274 = (L_268)->GetAt(static_cast<il2cpp_array_size_t>(L_273));
		V_14 = L_274;
		V_1 = 0;
		goto IL_0343;
	}

IL_032a:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_275 = ___2_bandLogE;
		int32_t L_276 = V_0;
		int32_t L_277 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_278 = ___2_bandLogE;
		int32_t L_279 = V_0;
		int32_t L_280 = V_1;
		NullCheck(L_278);
		int32_t L_281 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_279)), L_280));
		int32_t L_282 = (L_278)->GetAt(static_cast<il2cpp_array_size_t>(L_281));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_283 = V_14;
		int32_t L_284 = V_1;
		NullCheck(L_283);
		int32_t L_285 = L_284;
		int32_t L_286 = (L_283)->GetAt(static_cast<il2cpp_array_size_t>(L_285));
		NullCheck(L_275);
		(L_275)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_276)), L_277))), (int32_t)((int32_t)il2cpp_codegen_subtract(L_282, L_286)));
		int32_t L_287 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_287, 1));
	}

IL_0343:
	{
		int32_t L_288 = V_1;
		if ((((int32_t)L_288) < ((int32_t)((int32_t)21))))
		{
			goto IL_032a;
		}
	}
	{
		goto IL_0360;
	}

IL_034a:
	{
		V_1 = 0;
		goto IL_035b;
	}

IL_034e:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_289 = ___2_bandLogE;
		int32_t L_290 = V_0;
		int32_t L_291 = V_1;
		NullCheck(L_289);
		(L_289)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_290)), L_291))), (int32_t)0);
		int32_t L_292 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_292, 1));
	}

IL_035b:
	{
		int32_t L_293 = V_1;
		if ((((int32_t)L_293) < ((int32_t)((int32_t)21))))
		{
			goto IL_034e;
		}
	}

IL_0360:
	{
		int32_t L_294 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_294, 1));
	}

IL_0364:
	{
		int32_t L_295 = V_0;
		int32_t L_296 = ___7_channels;
		if ((((int32_t)L_295) < ((int32_t)L_296)))
		{
			goto IL_0317;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OpusMSEncoder_surround_analysis_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m9B9E4738B7BD6EEABF4D6378222B971D6775D65B_gshared (CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* ___0_celt_mode, ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D ___1_pcm, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___2_bandLogE, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___3_mem, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___4_preemph_mem, int32_t ___5_len, int32_t ___6_overlap, int32_t ___7_channels, int32_t ___8_rate, opus_copy_channel_in_func_1_t484D84949EB9FE0FFB9617C739F465DE3E898F3F* ___9_copy_channel_in, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Bands_tD5744B61D102D4A0692787D6E9227EC981D1F873_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CeltCommon_t5CD2203CC4CC8046F30E401748B268C2C42530D1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&QuantizeBands_tE23B88063E2F1D6FE379FFF3D12B7E5A351F9284_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* V_7 = NULL;
	Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* V_8 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_9 = NULL;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* V_10 = NULL;
	Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* V_11 = NULL;
	BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* V_12 = NULL;
	int32_t V_13 = 0;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_14 = NULL;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)8);
		V_3 = L_0;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_1;
		L_1 = Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8(1, ((int32_t)21), Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8_RuntimeMethod_var);
		V_7 = L_1;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_2;
		L_2 = Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8(3, ((int32_t)21), Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8_RuntimeMethod_var);
		V_8 = L_2;
		int32_t L_3 = ___8_rate;
		il2cpp_codegen_runtime_class_init_inline(CeltCommon_t5CD2203CC4CC8046F30E401748B268C2C42530D1_il2cpp_TypeInfo_var);
		int32_t L_4;
		L_4 = CeltCommon_resampling_factor_m6C156552D07405BDE82F1EE6386D518515ACE3DD(L_3, NULL);
		V_4 = L_4;
		int32_t L_5 = ___5_len;
		int32_t L_6 = V_4;
		V_5 = ((int32_t)il2cpp_codegen_multiply(L_5, L_6));
		V_2 = 0;
		goto IL_0042;
	}

IL_002f:
	{
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_7 = ___0_celt_mode;
		NullCheck(L_7);
		int32_t L_8 = L_7->___shortMdctSize;
		int32_t L_9 = V_2;
		int32_t L_10 = V_5;
		if ((((int32_t)((int32_t)(L_8<<((int32_t)(L_9&((int32_t)31)))))) == ((int32_t)L_10)))
		{
			goto IL_004b;
		}
	}
	{
		int32_t L_11 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_0042:
	{
		int32_t L_12 = V_2;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_13 = ___0_celt_mode;
		NullCheck(L_13);
		int32_t L_14 = L_13->___maxLM;
		if ((((int32_t)L_12) < ((int32_t)L_14)))
		{
			goto IL_002f;
		}
	}

IL_004b:
	{
		int32_t L_15 = V_5;
		int32_t L_16 = ___6_overlap;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_17 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_add(L_15, L_16)));
		V_9 = L_17;
		int32_t L_18 = ___5_len;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_19 = (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)SZArrayNew(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var, (uint32_t)L_18);
		V_10 = L_19;
		int32_t L_20 = V_5;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_21;
		L_21 = Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8(1, L_20, Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8_RuntimeMethod_var);
		V_11 = L_21;
		int32_t L_22 = ___7_channels;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_23 = V_3;
		il2cpp_codegen_runtime_class_init_inline(OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_il2cpp_TypeInfo_var);
		OpusMSEncoder_channel_pos_m5FF9B9CDE29B029E06F5AF09EFD8359BFAE20B6E(L_22, L_23, NULL);
		V_0 = 0;
		goto IL_0092;
	}

IL_0076:
	{
		V_1 = 0;
		goto IL_0089;
	}

IL_007a:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_24 = V_8;
		int32_t L_25 = V_0;
		NullCheck(L_24);
		int32_t L_26 = L_25;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_27 = (L_24)->GetAt(static_cast<il2cpp_array_size_t>(L_26));
		int32_t L_28 = V_1;
		NullCheck(L_27);
		(L_27)->SetAt(static_cast<il2cpp_array_size_t>(L_28), (int32_t)((int32_t)-28672));
		int32_t L_29 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_0089:
	{
		int32_t L_30 = V_1;
		if ((((int32_t)L_30) < ((int32_t)((int32_t)21))))
		{
			goto IL_007a;
		}
	}
	{
		int32_t L_31 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_31, 1));
	}

IL_0092:
	{
		int32_t L_32 = V_0;
		if ((((int32_t)L_32) < ((int32_t)3)))
		{
			goto IL_0076;
		}
	}
	{
		V_0 = 0;
		goto IL_02a8;
	}

IL_009d:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_33 = ___3_mem;
		int32_t L_34 = V_0;
		int32_t L_35 = ___6_overlap;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_36 = V_9;
		int32_t L_37 = ___6_overlap;
		Arrays_MemCopy_m3B172AAA9447D50DF1AE71C15662FB5005858B3F(L_33, ((int32_t)il2cpp_codegen_multiply(L_34, L_35)), L_36, 0, L_37, NULL);
		opus_copy_channel_in_func_1_t484D84949EB9FE0FFB9617C739F465DE3E898F3F* L_38 = ___9_copy_channel_in;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_39 = V_10;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_40;
		L_40 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_39, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D L_41 = ___1_pcm;
		int32_t L_42 = ___7_channels;
		int32_t L_43 = V_0;
		int32_t L_44 = ___5_len;
		NullCheck(L_38);
		opus_copy_channel_in_func_1_Invoke_m6D03E61EA06F045BA121921DC606E861E540D67D_inline(L_38, L_40, 0, 1, L_41, L_42, L_43, L_44, il2cpp_rgctx_method(method->rgctx_data, 2));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_45 = ___4_preemph_mem;
		int32_t L_46 = V_0;
		NullCheck(L_45);
		int32_t L_47 = L_46;
		int32_t L_48 = (L_45)->GetAt(static_cast<il2cpp_array_size_t>(L_47));
		BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* L_49 = (BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026*)il2cpp_codegen_object_new(BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026_il2cpp_TypeInfo_var);
		BoxedValueInt__ctor_m6EC58F06F4673535F2682F1731C6F36FC073A36A(L_49, L_48, NULL);
		V_12 = L_49;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_50 = V_10;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_51 = V_9;
		Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 L_52;
		L_52 = Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC(L_51, Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC_RuntimeMethod_var);
		int32_t L_53 = ___6_overlap;
		int32_t L_54 = V_5;
		int32_t L_55 = V_4;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_56 = ___0_celt_mode;
		NullCheck(L_56);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_57 = L_56->___preemph;
		BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* L_58 = V_12;
		il2cpp_codegen_runtime_class_init_inline(CeltCommon_t5CD2203CC4CC8046F30E401748B268C2C42530D1_il2cpp_TypeInfo_var);
		CeltCommon_celt_preemphasis_m21C67E565A36929D27B417626A565BC7B688FC23(L_50, L_52, L_53, L_54, 1, L_55, L_57, L_58, 0, NULL);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_59 = ___4_preemph_mem;
		int32_t L_60 = V_0;
		BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* L_61 = V_12;
		NullCheck(L_61);
		int32_t L_62 = L_61->___Val;
		NullCheck(L_59);
		(L_59)->SetAt(static_cast<il2cpp_array_size_t>(L_60), (int32_t)L_62);
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_63 = ___0_celt_mode;
		NullCheck(L_63);
		MDCTLookup_t1A4D19310C741D19B9223906DB1F8DF9142B47F0* L_64 = L_63->___mdct;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_65 = V_9;
		Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 L_66;
		L_66 = Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC(L_65, Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC_RuntimeMethod_var);
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_67 = V_11;
		NullCheck(L_67);
		int32_t L_68 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_69 = (L_67)->GetAt(static_cast<il2cpp_array_size_t>(L_68));
		Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 L_70;
		L_70 = Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC(L_69, Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC_RuntimeMethod_var);
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_71 = ___0_celt_mode;
		NullCheck(L_71);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_72 = L_71->___window;
		int32_t L_73 = ___6_overlap;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_74 = ___0_celt_mode;
		NullCheck(L_74);
		int32_t L_75 = L_74->___maxLM;
		int32_t L_76 = V_2;
		MDCT_clt_mdct_forward_m574EDCF759544B7757CA02E5A5B9CD44ABD80793(L_64, L_66, 0, L_70, 0, L_72, L_73, ((int32_t)il2cpp_codegen_subtract(L_75, L_76)), 1, NULL);
		int32_t L_77 = V_4;
		if ((((int32_t)L_77) == ((int32_t)1)))
		{
			goto IL_015c;
		}
	}
	{
		int32_t L_78 = ___5_len;
		V_13 = L_78;
		V_1 = 0;
		goto IL_0145;
	}

IL_0131:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_79 = V_11;
		NullCheck(L_79);
		int32_t L_80 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_81 = (L_79)->GetAt(static_cast<il2cpp_array_size_t>(L_80));
		int32_t L_82 = V_1;
		NullCheck(L_81);
		int32_t* L_83 = ((L_81)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_82)));
		int32_t L_84 = *((int32_t*)L_83);
		int32_t L_85 = V_4;
		*((int32_t*)L_83) = (int32_t)((int32_t)il2cpp_codegen_multiply(L_84, L_85));
		int32_t L_86 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_86, 1));
	}

IL_0145:
	{
		int32_t L_87 = V_1;
		int32_t L_88 = V_13;
		if ((((int32_t)L_87) < ((int32_t)L_88)))
		{
			goto IL_0131;
		}
	}
	{
		goto IL_0157;
	}

IL_014c:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_89 = V_11;
		NullCheck(L_89);
		int32_t L_90 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_91 = (L_89)->GetAt(static_cast<il2cpp_array_size_t>(L_90));
		int32_t L_92 = V_1;
		NullCheck(L_91);
		(L_91)->SetAt(static_cast<il2cpp_array_size_t>(L_92), (int32_t)0);
		int32_t L_93 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_93, 1));
	}

IL_0157:
	{
		int32_t L_94 = V_1;
		int32_t L_95 = V_5;
		if ((((int32_t)L_94) < ((int32_t)L_95)))
		{
			goto IL_014c;
		}
	}

IL_015c:
	{
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_96 = ___0_celt_mode;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_97 = V_11;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_98 = V_7;
		int32_t L_99 = V_2;
		il2cpp_codegen_runtime_class_init_inline(Bands_tD5744B61D102D4A0692787D6E9227EC981D1F873_il2cpp_TypeInfo_var);
		Bands_compute_band_energies_m6162BA578721FCAFBD60AFCB17CB0B7F2753AB26(L_96, L_97, L_98, ((int32_t)21), 1, L_99, NULL);
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_100 = ___0_celt_mode;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_101 = V_7;
		NullCheck(L_101);
		int32_t L_102 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_103 = (L_101)->GetAt(static_cast<il2cpp_array_size_t>(L_102));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_104 = ___2_bandLogE;
		Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 L_105;
		L_105 = Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC(L_104, Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC_RuntimeMethod_var);
		int32_t L_106 = V_0;
		il2cpp_codegen_runtime_class_init_inline(QuantizeBands_tE23B88063E2F1D6FE379FFF3D12B7E5A351F9284_il2cpp_TypeInfo_var);
		QuantizeBands_amp2Log2_m0C280EEAE3F9FA53CC72CC1A6E5EF65E2EC2AF8F(L_100, ((int32_t)21), ((int32_t)21), L_103, L_105, ((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_106)), 1, NULL);
		V_1 = 1;
		goto IL_01b0;
	}

IL_0187:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_107 = ___2_bandLogE;
		int32_t L_108 = V_0;
		int32_t L_109 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_110 = ___2_bandLogE;
		int32_t L_111 = V_0;
		int32_t L_112 = V_1;
		NullCheck(L_110);
		int32_t L_113 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_111)), L_112));
		int32_t L_114 = (L_110)->GetAt(static_cast<il2cpp_array_size_t>(L_113));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_115 = ___2_bandLogE;
		int32_t L_116 = V_0;
		int32_t L_117 = V_1;
		NullCheck(L_115);
		int32_t L_118 = ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_116)), L_117)), 1));
		int32_t L_119 = (L_115)->GetAt(static_cast<il2cpp_array_size_t>(L_118));
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_120;
		L_120 = Inlines_MAX16_m4D603BAD0F242EB66ED76BE982BC3907D9DF44A5_inline(L_114, ((int32_t)il2cpp_codegen_subtract(L_119, ((int32_t)1024))), NULL);
		NullCheck(L_107);
		(L_107)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_108)), L_109))), (int32_t)L_120);
		int32_t L_121 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_121, 1));
	}

IL_01b0:
	{
		int32_t L_122 = V_1;
		if ((((int32_t)L_122) < ((int32_t)((int32_t)21))))
		{
			goto IL_0187;
		}
	}
	{
		V_1 = ((int32_t)19);
		goto IL_01e3;
	}

IL_01ba:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_123 = ___2_bandLogE;
		int32_t L_124 = V_0;
		int32_t L_125 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_126 = ___2_bandLogE;
		int32_t L_127 = V_0;
		int32_t L_128 = V_1;
		NullCheck(L_126);
		int32_t L_129 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_127)), L_128));
		int32_t L_130 = (L_126)->GetAt(static_cast<il2cpp_array_size_t>(L_129));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_131 = ___2_bandLogE;
		int32_t L_132 = V_0;
		int32_t L_133 = V_1;
		NullCheck(L_131);
		int32_t L_134 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_132)), L_133)), 1));
		int32_t L_135 = (L_131)->GetAt(static_cast<il2cpp_array_size_t>(L_134));
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_136;
		L_136 = Inlines_MAX16_m4D603BAD0F242EB66ED76BE982BC3907D9DF44A5_inline(L_130, ((int32_t)il2cpp_codegen_subtract(L_135, ((int32_t)2048))), NULL);
		NullCheck(L_123);
		(L_123)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_124)), L_125))), (int32_t)L_136);
		int32_t L_137 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_subtract(L_137, 1));
	}

IL_01e3:
	{
		int32_t L_138 = V_1;
		if ((((int32_t)L_138) >= ((int32_t)0)))
		{
			goto IL_01ba;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_139 = V_3;
		int32_t L_140 = V_0;
		NullCheck(L_139);
		int32_t L_141 = L_140;
		int32_t L_142 = (L_139)->GetAt(static_cast<il2cpp_array_size_t>(L_141));
		if ((!(((uint32_t)L_142) == ((uint32_t)1))))
		{
			goto IL_0215;
		}
	}
	{
		V_1 = 0;
		goto IL_020e;
	}

IL_01f1:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_143 = V_8;
		NullCheck(L_143);
		int32_t L_144 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_145 = (L_143)->GetAt(static_cast<il2cpp_array_size_t>(L_144));
		int32_t L_146 = V_1;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_147 = V_8;
		NullCheck(L_147);
		int32_t L_148 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_149 = (L_147)->GetAt(static_cast<il2cpp_array_size_t>(L_148));
		int32_t L_150 = V_1;
		NullCheck(L_149);
		int32_t L_151 = L_150;
		int32_t L_152 = (L_149)->GetAt(static_cast<il2cpp_array_size_t>(L_151));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_153 = ___2_bandLogE;
		int32_t L_154 = V_0;
		int32_t L_155 = V_1;
		NullCheck(L_153);
		int32_t L_156 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_154)), L_155));
		int32_t L_157 = (L_153)->GetAt(static_cast<il2cpp_array_size_t>(L_156));
		il2cpp_codegen_runtime_class_init_inline(OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_il2cpp_TypeInfo_var);
		int32_t L_158;
		L_158 = OpusMSEncoder_logSum_mC189C2CAB88090345C3C24D4D5C103F0D5341A87(L_152, L_157, NULL);
		NullCheck(L_145);
		(L_145)->SetAt(static_cast<il2cpp_array_size_t>(L_146), (int32_t)L_158);
		int32_t L_159 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_159, 1));
	}

IL_020e:
	{
		int32_t L_160 = V_1;
		if ((((int32_t)L_160) < ((int32_t)((int32_t)21))))
		{
			goto IL_01f1;
		}
	}
	{
		goto IL_0294;
	}

IL_0215:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_161 = V_3;
		int32_t L_162 = V_0;
		NullCheck(L_161);
		int32_t L_163 = L_162;
		int32_t L_164 = (L_161)->GetAt(static_cast<il2cpp_array_size_t>(L_163));
		if ((!(((uint32_t)L_164) == ((uint32_t)3))))
		{
			goto IL_0243;
		}
	}
	{
		V_1 = 0;
		goto IL_023c;
	}

IL_021f:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_165 = V_8;
		NullCheck(L_165);
		int32_t L_166 = 2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_167 = (L_165)->GetAt(static_cast<il2cpp_array_size_t>(L_166));
		int32_t L_168 = V_1;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_169 = V_8;
		NullCheck(L_169);
		int32_t L_170 = 2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_171 = (L_169)->GetAt(static_cast<il2cpp_array_size_t>(L_170));
		int32_t L_172 = V_1;
		NullCheck(L_171);
		int32_t L_173 = L_172;
		int32_t L_174 = (L_171)->GetAt(static_cast<il2cpp_array_size_t>(L_173));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_175 = ___2_bandLogE;
		int32_t L_176 = V_0;
		int32_t L_177 = V_1;
		NullCheck(L_175);
		int32_t L_178 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_176)), L_177));
		int32_t L_179 = (L_175)->GetAt(static_cast<il2cpp_array_size_t>(L_178));
		il2cpp_codegen_runtime_class_init_inline(OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_il2cpp_TypeInfo_var);
		int32_t L_180;
		L_180 = OpusMSEncoder_logSum_mC189C2CAB88090345C3C24D4D5C103F0D5341A87(L_174, L_179, NULL);
		NullCheck(L_167);
		(L_167)->SetAt(static_cast<il2cpp_array_size_t>(L_168), (int32_t)L_180);
		int32_t L_181 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_181, 1));
	}

IL_023c:
	{
		int32_t L_182 = V_1;
		if ((((int32_t)L_182) < ((int32_t)((int32_t)21))))
		{
			goto IL_021f;
		}
	}
	{
		goto IL_0294;
	}

IL_0243:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_183 = V_3;
		int32_t L_184 = V_0;
		NullCheck(L_183);
		int32_t L_185 = L_184;
		int32_t L_186 = (L_183)->GetAt(static_cast<il2cpp_array_size_t>(L_185));
		if ((!(((uint32_t)L_186) == ((uint32_t)2))))
		{
			goto IL_0294;
		}
	}
	{
		V_1 = 0;
		goto IL_028f;
	}

IL_024d:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_187 = V_8;
		NullCheck(L_187);
		int32_t L_188 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_189 = (L_187)->GetAt(static_cast<il2cpp_array_size_t>(L_188));
		int32_t L_190 = V_1;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_191 = V_8;
		NullCheck(L_191);
		int32_t L_192 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_193 = (L_191)->GetAt(static_cast<il2cpp_array_size_t>(L_192));
		int32_t L_194 = V_1;
		NullCheck(L_193);
		int32_t L_195 = L_194;
		int32_t L_196 = (L_193)->GetAt(static_cast<il2cpp_array_size_t>(L_195));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_197 = ___2_bandLogE;
		int32_t L_198 = V_0;
		int32_t L_199 = V_1;
		NullCheck(L_197);
		int32_t L_200 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_198)), L_199));
		int32_t L_201 = (L_197)->GetAt(static_cast<il2cpp_array_size_t>(L_200));
		il2cpp_codegen_runtime_class_init_inline(OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_il2cpp_TypeInfo_var);
		int32_t L_202;
		L_202 = OpusMSEncoder_logSum_mC189C2CAB88090345C3C24D4D5C103F0D5341A87(L_196, ((int32_t)il2cpp_codegen_subtract(L_201, ((int32_t)512))), NULL);
		NullCheck(L_189);
		(L_189)->SetAt(static_cast<il2cpp_array_size_t>(L_190), (int32_t)L_202);
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_203 = V_8;
		NullCheck(L_203);
		int32_t L_204 = 2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_205 = (L_203)->GetAt(static_cast<il2cpp_array_size_t>(L_204));
		int32_t L_206 = V_1;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_207 = V_8;
		NullCheck(L_207);
		int32_t L_208 = 2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_209 = (L_207)->GetAt(static_cast<il2cpp_array_size_t>(L_208));
		int32_t L_210 = V_1;
		NullCheck(L_209);
		int32_t L_211 = L_210;
		int32_t L_212 = (L_209)->GetAt(static_cast<il2cpp_array_size_t>(L_211));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_213 = ___2_bandLogE;
		int32_t L_214 = V_0;
		int32_t L_215 = V_1;
		NullCheck(L_213);
		int32_t L_216 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_214)), L_215));
		int32_t L_217 = (L_213)->GetAt(static_cast<il2cpp_array_size_t>(L_216));
		int32_t L_218;
		L_218 = OpusMSEncoder_logSum_mC189C2CAB88090345C3C24D4D5C103F0D5341A87(L_212, ((int32_t)il2cpp_codegen_subtract(L_217, ((int32_t)512))), NULL);
		NullCheck(L_205);
		(L_205)->SetAt(static_cast<il2cpp_array_size_t>(L_206), (int32_t)L_218);
		int32_t L_219 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_219, 1));
	}

IL_028f:
	{
		int32_t L_220 = V_1;
		if ((((int32_t)L_220) < ((int32_t)((int32_t)21))))
		{
			goto IL_024d;
		}
	}

IL_0294:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_221 = V_9;
		int32_t L_222 = V_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_223 = ___3_mem;
		int32_t L_224 = V_0;
		int32_t L_225 = ___6_overlap;
		int32_t L_226 = ___6_overlap;
		Arrays_MemCopy_m3B172AAA9447D50DF1AE71C15662FB5005858B3F(L_221, L_222, L_223, ((int32_t)il2cpp_codegen_multiply(L_224, L_225)), L_226, NULL);
		int32_t L_227 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_227, 1));
	}

IL_02a8:
	{
		int32_t L_228 = V_0;
		int32_t L_229 = ___7_channels;
		if ((((int32_t)L_228) < ((int32_t)L_229)))
		{
			goto IL_009d;
		}
	}
	{
		V_1 = 0;
		goto IL_02cf;
	}

IL_02b4:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_230 = V_8;
		NullCheck(L_230);
		int32_t L_231 = 1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_232 = (L_230)->GetAt(static_cast<il2cpp_array_size_t>(L_231));
		int32_t L_233 = V_1;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_234 = V_8;
		NullCheck(L_234);
		int32_t L_235 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_236 = (L_234)->GetAt(static_cast<il2cpp_array_size_t>(L_235));
		int32_t L_237 = V_1;
		NullCheck(L_236);
		int32_t L_238 = L_237;
		int32_t L_239 = (L_236)->GetAt(static_cast<il2cpp_array_size_t>(L_238));
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_240 = V_8;
		NullCheck(L_240);
		int32_t L_241 = 2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_242 = (L_240)->GetAt(static_cast<il2cpp_array_size_t>(L_241));
		int32_t L_243 = V_1;
		NullCheck(L_242);
		int32_t L_244 = L_243;
		int32_t L_245 = (L_242)->GetAt(static_cast<il2cpp_array_size_t>(L_244));
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_246;
		L_246 = Inlines_MIN32_mE77013C78A201F2EF11AE030F4E6DFC4815008F9_inline(L_239, L_245, NULL);
		NullCheck(L_232);
		(L_232)->SetAt(static_cast<il2cpp_array_size_t>(L_233), (int32_t)L_246);
		int32_t L_247 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_247, 1));
	}

IL_02cf:
	{
		int32_t L_248 = V_1;
		if ((((int32_t)L_248) < ((int32_t)((int32_t)21))))
		{
			goto IL_02b4;
		}
	}
	{
		int32_t L_249 = ___7_channels;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_250;
		L_250 = Inlines_celt_log2_m72E298D8304AC7AB2F8334898CA897FF185F8784_inline(((int32_t)(((int32_t)32768)/((int32_t)il2cpp_codegen_subtract(L_249, 1)))), NULL);
		int32_t L_251;
		L_251 = Inlines_HALF16_mCC975475CB9BE63D15752AA7AA0F3E44598ADB4D_inline(L_250, NULL);
		V_6 = L_251;
		V_0 = 0;
		goto IL_030f;
	}

IL_02ee:
	{
		V_1 = 0;
		goto IL_0306;
	}

IL_02f2:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_252 = V_8;
		int32_t L_253 = V_0;
		NullCheck(L_252);
		int32_t L_254 = L_253;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_255 = (L_252)->GetAt(static_cast<il2cpp_array_size_t>(L_254));
		int32_t L_256 = V_1;
		NullCheck(L_255);
		int32_t* L_257 = ((L_255)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_256)));
		int32_t L_258 = *((int32_t*)L_257);
		int32_t L_259 = V_6;
		*((int32_t*)L_257) = (int32_t)((int32_t)il2cpp_codegen_add(L_258, L_259));
		int32_t L_260 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_260, 1));
	}

IL_0306:
	{
		int32_t L_261 = V_1;
		if ((((int32_t)L_261) < ((int32_t)((int32_t)21))))
		{
			goto IL_02f2;
		}
	}
	{
		int32_t L_262 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_262, 1));
	}

IL_030f:
	{
		int32_t L_263 = V_0;
		if ((((int32_t)L_263) < ((int32_t)3)))
		{
			goto IL_02ee;
		}
	}
	{
		V_0 = 0;
		goto IL_0364;
	}

IL_0317:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_264 = V_3;
		int32_t L_265 = V_0;
		NullCheck(L_264);
		int32_t L_266 = L_265;
		int32_t L_267 = (L_264)->GetAt(static_cast<il2cpp_array_size_t>(L_266));
		if (!L_267)
		{
			goto IL_034a;
		}
	}
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_268 = V_8;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_269 = V_3;
		int32_t L_270 = V_0;
		NullCheck(L_269);
		int32_t L_271 = L_270;
		int32_t L_272 = (L_269)->GetAt(static_cast<il2cpp_array_size_t>(L_271));
		NullCheck(L_268);
		int32_t L_273 = ((int32_t)il2cpp_codegen_subtract(L_272, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_274 = (L_268)->GetAt(static_cast<il2cpp_array_size_t>(L_273));
		V_14 = L_274;
		V_1 = 0;
		goto IL_0343;
	}

IL_032a:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_275 = ___2_bandLogE;
		int32_t L_276 = V_0;
		int32_t L_277 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_278 = ___2_bandLogE;
		int32_t L_279 = V_0;
		int32_t L_280 = V_1;
		NullCheck(L_278);
		int32_t L_281 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_279)), L_280));
		int32_t L_282 = (L_278)->GetAt(static_cast<il2cpp_array_size_t>(L_281));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_283 = V_14;
		int32_t L_284 = V_1;
		NullCheck(L_283);
		int32_t L_285 = L_284;
		int32_t L_286 = (L_283)->GetAt(static_cast<il2cpp_array_size_t>(L_285));
		NullCheck(L_275);
		(L_275)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_276)), L_277))), (int32_t)((int32_t)il2cpp_codegen_subtract(L_282, L_286)));
		int32_t L_287 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_287, 1));
	}

IL_0343:
	{
		int32_t L_288 = V_1;
		if ((((int32_t)L_288) < ((int32_t)((int32_t)21))))
		{
			goto IL_032a;
		}
	}
	{
		goto IL_0360;
	}

IL_034a:
	{
		V_1 = 0;
		goto IL_035b;
	}

IL_034e:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_289 = ___2_bandLogE;
		int32_t L_290 = V_0;
		int32_t L_291 = V_1;
		NullCheck(L_289);
		(L_289)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_290)), L_291))), (int32_t)0);
		int32_t L_292 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_292, 1));
	}

IL_035b:
	{
		int32_t L_293 = V_1;
		if ((((int32_t)L_293) < ((int32_t)((int32_t)21))))
		{
			goto IL_034e;
		}
	}

IL_0360:
	{
		int32_t L_294 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_294, 1));
	}

IL_0364:
	{
		int32_t L_295 = V_0;
		int32_t L_296 = ___7_channels;
		if ((((int32_t)L_295) < ((int32_t)L_296)))
		{
			goto IL_0317;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OpusMSEncoder_surround_analysis_TisIl2CppFullySharedGenericAny_m6F8459992F3A4444158FCC8B9A0D89489E92824A_gshared (CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* ___0_celt_mode, ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC ___1_pcm, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___2_bandLogE, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___3_mem, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___4_preemph_mem, int32_t ___5_len, int32_t ___6_overlap, int32_t ___7_channels, int32_t ___8_rate, opus_copy_channel_in_func_1_tF3C7FBC38C3C10B5DF45A5E2E931749B4708E1B2* ___9_copy_channel_in, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Bands_tD5744B61D102D4A0692787D6E9227EC981D1F873_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CeltCommon_t5CD2203CC4CC8046F30E401748B268C2C42530D1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&QuantizeBands_tE23B88063E2F1D6FE379FFF3D12B7E5A351F9284_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_3 = NULL;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* V_7 = NULL;
	Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* V_8 = NULL;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_9 = NULL;
	Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* V_10 = NULL;
	Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* V_11 = NULL;
	BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* V_12 = NULL;
	int32_t V_13 = 0;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_14 = NULL;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)8);
		V_3 = L_0;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_1;
		L_1 = Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8(1, ((int32_t)21), Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8_RuntimeMethod_var);
		V_7 = L_1;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_2;
		L_2 = Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8(3, ((int32_t)21), Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8_RuntimeMethod_var);
		V_8 = L_2;
		int32_t L_3 = ___8_rate;
		il2cpp_codegen_runtime_class_init_inline(CeltCommon_t5CD2203CC4CC8046F30E401748B268C2C42530D1_il2cpp_TypeInfo_var);
		int32_t L_4;
		L_4 = CeltCommon_resampling_factor_m6C156552D07405BDE82F1EE6386D518515ACE3DD(L_3, NULL);
		V_4 = L_4;
		int32_t L_5 = ___5_len;
		int32_t L_6 = V_4;
		V_5 = ((int32_t)il2cpp_codegen_multiply(L_5, L_6));
		V_2 = 0;
		goto IL_0042;
	}

IL_002f:
	{
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_7 = ___0_celt_mode;
		NullCheck(L_7);
		int32_t L_8 = L_7->___shortMdctSize;
		int32_t L_9 = V_2;
		int32_t L_10 = V_5;
		if ((((int32_t)((int32_t)(L_8<<((int32_t)(L_9&((int32_t)31)))))) == ((int32_t)L_10)))
		{
			goto IL_004b;
		}
	}
	{
		int32_t L_11 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_0042:
	{
		int32_t L_12 = V_2;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_13 = ___0_celt_mode;
		NullCheck(L_13);
		int32_t L_14 = L_13->___maxLM;
		if ((((int32_t)L_12) < ((int32_t)L_14)))
		{
			goto IL_002f;
		}
	}

IL_004b:
	{
		int32_t L_15 = V_5;
		int32_t L_16 = ___6_overlap;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_17 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_add(L_15, L_16)));
		V_9 = L_17;
		int32_t L_18 = ___5_len;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_19 = (Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB*)SZArrayNew(Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB_il2cpp_TypeInfo_var, (uint32_t)L_18);
		V_10 = L_19;
		int32_t L_20 = V_5;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_21;
		L_21 = Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8(1, L_20, Arrays_InitTwoDimensionalArray_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFA85410AB6DF1A27AE9F12D59AB6F74523FF9BC8_RuntimeMethod_var);
		V_11 = L_21;
		int32_t L_22 = ___7_channels;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_23 = V_3;
		il2cpp_codegen_runtime_class_init_inline(OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_il2cpp_TypeInfo_var);
		OpusMSEncoder_channel_pos_m5FF9B9CDE29B029E06F5AF09EFD8359BFAE20B6E(L_22, L_23, NULL);
		V_0 = 0;
		goto IL_0092;
	}

IL_0076:
	{
		V_1 = 0;
		goto IL_0089;
	}

IL_007a:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_24 = V_8;
		int32_t L_25 = V_0;
		NullCheck(L_24);
		int32_t L_26 = L_25;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_27 = (L_24)->GetAt(static_cast<il2cpp_array_size_t>(L_26));
		int32_t L_28 = V_1;
		NullCheck(L_27);
		(L_27)->SetAt(static_cast<il2cpp_array_size_t>(L_28), (int32_t)((int32_t)-28672));
		int32_t L_29 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_0089:
	{
		int32_t L_30 = V_1;
		if ((((int32_t)L_30) < ((int32_t)((int32_t)21))))
		{
			goto IL_007a;
		}
	}
	{
		int32_t L_31 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_31, 1));
	}

IL_0092:
	{
		int32_t L_32 = V_0;
		if ((((int32_t)L_32) < ((int32_t)3)))
		{
			goto IL_0076;
		}
	}
	{
		V_0 = 0;
		goto IL_02a8;
	}

IL_009d:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_33 = ___3_mem;
		int32_t L_34 = V_0;
		int32_t L_35 = ___6_overlap;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_36 = V_9;
		int32_t L_37 = ___6_overlap;
		Arrays_MemCopy_m3B172AAA9447D50DF1AE71C15662FB5005858B3F(L_33, ((int32_t)il2cpp_codegen_multiply(L_34, L_35)), L_36, 0, L_37, NULL);
		opus_copy_channel_in_func_1_tF3C7FBC38C3C10B5DF45A5E2E931749B4708E1B2* L_38 = ___9_copy_channel_in;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_39 = V_10;
		Span_1_tC1B695440A1567664C2665D76D5614739FDF453D L_40;
		L_40 = Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D(L_39, Span_1_op_Implicit_m24F375632A31965FA8FAD49F1230ED1E1E7CFC1D_RuntimeMethod_var);
		ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC L_41 = ___1_pcm;
		int32_t L_42 = ___7_channels;
		int32_t L_43 = V_0;
		int32_t L_44 = ___5_len;
		NullCheck(L_38);
		((  void (*) (opus_copy_channel_in_func_1_tF3C7FBC38C3C10B5DF45A5E2E931749B4708E1B2*, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D, int32_t, int32_t, ReadOnlySpan_1_tC416A5627E04F69CA2947A2A13F0A1DF096CABAC, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(L_38, L_40, 0, 1, L_41, L_42, L_43, L_44, il2cpp_rgctx_method(method->rgctx_data, 2));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_45 = ___4_preemph_mem;
		int32_t L_46 = V_0;
		NullCheck(L_45);
		int32_t L_47 = L_46;
		int32_t L_48 = (L_45)->GetAt(static_cast<il2cpp_array_size_t>(L_47));
		BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* L_49 = (BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026*)il2cpp_codegen_object_new(BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026_il2cpp_TypeInfo_var);
		BoxedValueInt__ctor_m6EC58F06F4673535F2682F1731C6F36FC073A36A(L_49, L_48, NULL);
		V_12 = L_49;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_50 = V_10;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_51 = V_9;
		Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 L_52;
		L_52 = Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC(L_51, Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC_RuntimeMethod_var);
		int32_t L_53 = ___6_overlap;
		int32_t L_54 = V_5;
		int32_t L_55 = V_4;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_56 = ___0_celt_mode;
		NullCheck(L_56);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_57 = L_56->___preemph;
		BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* L_58 = V_12;
		il2cpp_codegen_runtime_class_init_inline(CeltCommon_t5CD2203CC4CC8046F30E401748B268C2C42530D1_il2cpp_TypeInfo_var);
		CeltCommon_celt_preemphasis_m21C67E565A36929D27B417626A565BC7B688FC23(L_50, L_52, L_53, L_54, 1, L_55, L_57, L_58, 0, NULL);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_59 = ___4_preemph_mem;
		int32_t L_60 = V_0;
		BoxedValueInt_tB298D3C739935A511B686637B56F84FC76C44026* L_61 = V_12;
		NullCheck(L_61);
		int32_t L_62 = L_61->___Val;
		NullCheck(L_59);
		(L_59)->SetAt(static_cast<il2cpp_array_size_t>(L_60), (int32_t)L_62);
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_63 = ___0_celt_mode;
		NullCheck(L_63);
		MDCTLookup_t1A4D19310C741D19B9223906DB1F8DF9142B47F0* L_64 = L_63->___mdct;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_65 = V_9;
		Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 L_66;
		L_66 = Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC(L_65, Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC_RuntimeMethod_var);
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_67 = V_11;
		NullCheck(L_67);
		int32_t L_68 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_69 = (L_67)->GetAt(static_cast<il2cpp_array_size_t>(L_68));
		Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 L_70;
		L_70 = Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC(L_69, Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC_RuntimeMethod_var);
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_71 = ___0_celt_mode;
		NullCheck(L_71);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_72 = L_71->___window;
		int32_t L_73 = ___6_overlap;
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_74 = ___0_celt_mode;
		NullCheck(L_74);
		int32_t L_75 = L_74->___maxLM;
		int32_t L_76 = V_2;
		MDCT_clt_mdct_forward_m574EDCF759544B7757CA02E5A5B9CD44ABD80793(L_64, L_66, 0, L_70, 0, L_72, L_73, ((int32_t)il2cpp_codegen_subtract(L_75, L_76)), 1, NULL);
		int32_t L_77 = V_4;
		if ((((int32_t)L_77) == ((int32_t)1)))
		{
			goto IL_015c;
		}
	}
	{
		int32_t L_78 = ___5_len;
		V_13 = L_78;
		V_1 = 0;
		goto IL_0145;
	}

IL_0131:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_79 = V_11;
		NullCheck(L_79);
		int32_t L_80 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_81 = (L_79)->GetAt(static_cast<il2cpp_array_size_t>(L_80));
		int32_t L_82 = V_1;
		NullCheck(L_81);
		int32_t* L_83 = ((L_81)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_82)));
		int32_t L_84 = *((int32_t*)L_83);
		int32_t L_85 = V_4;
		*((int32_t*)L_83) = (int32_t)((int32_t)il2cpp_codegen_multiply(L_84, L_85));
		int32_t L_86 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_86, 1));
	}

IL_0145:
	{
		int32_t L_87 = V_1;
		int32_t L_88 = V_13;
		if ((((int32_t)L_87) < ((int32_t)L_88)))
		{
			goto IL_0131;
		}
	}
	{
		goto IL_0157;
	}

IL_014c:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_89 = V_11;
		NullCheck(L_89);
		int32_t L_90 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_91 = (L_89)->GetAt(static_cast<il2cpp_array_size_t>(L_90));
		int32_t L_92 = V_1;
		NullCheck(L_91);
		(L_91)->SetAt(static_cast<il2cpp_array_size_t>(L_92), (int32_t)0);
		int32_t L_93 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_93, 1));
	}

IL_0157:
	{
		int32_t L_94 = V_1;
		int32_t L_95 = V_5;
		if ((((int32_t)L_94) < ((int32_t)L_95)))
		{
			goto IL_014c;
		}
	}

IL_015c:
	{
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_96 = ___0_celt_mode;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_97 = V_11;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_98 = V_7;
		int32_t L_99 = V_2;
		il2cpp_codegen_runtime_class_init_inline(Bands_tD5744B61D102D4A0692787D6E9227EC981D1F873_il2cpp_TypeInfo_var);
		Bands_compute_band_energies_m6162BA578721FCAFBD60AFCB17CB0B7F2753AB26(L_96, L_97, L_98, ((int32_t)21), 1, L_99, NULL);
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_100 = ___0_celt_mode;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_101 = V_7;
		NullCheck(L_101);
		int32_t L_102 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_103 = (L_101)->GetAt(static_cast<il2cpp_array_size_t>(L_102));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_104 = ___2_bandLogE;
		Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 L_105;
		L_105 = Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC(L_104, Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC_RuntimeMethod_var);
		int32_t L_106 = V_0;
		il2cpp_codegen_runtime_class_init_inline(QuantizeBands_tE23B88063E2F1D6FE379FFF3D12B7E5A351F9284_il2cpp_TypeInfo_var);
		QuantizeBands_amp2Log2_m0C280EEAE3F9FA53CC72CC1A6E5EF65E2EC2AF8F(L_100, ((int32_t)21), ((int32_t)21), L_103, L_105, ((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_106)), 1, NULL);
		V_1 = 1;
		goto IL_01b0;
	}

IL_0187:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_107 = ___2_bandLogE;
		int32_t L_108 = V_0;
		int32_t L_109 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_110 = ___2_bandLogE;
		int32_t L_111 = V_0;
		int32_t L_112 = V_1;
		NullCheck(L_110);
		int32_t L_113 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_111)), L_112));
		int32_t L_114 = (L_110)->GetAt(static_cast<il2cpp_array_size_t>(L_113));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_115 = ___2_bandLogE;
		int32_t L_116 = V_0;
		int32_t L_117 = V_1;
		NullCheck(L_115);
		int32_t L_118 = ((int32_t)il2cpp_codegen_subtract(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_116)), L_117)), 1));
		int32_t L_119 = (L_115)->GetAt(static_cast<il2cpp_array_size_t>(L_118));
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_120;
		L_120 = Inlines_MAX16_m4D603BAD0F242EB66ED76BE982BC3907D9DF44A5_inline(L_114, ((int32_t)il2cpp_codegen_subtract(L_119, ((int32_t)1024))), NULL);
		NullCheck(L_107);
		(L_107)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_108)), L_109))), (int32_t)L_120);
		int32_t L_121 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_121, 1));
	}

IL_01b0:
	{
		int32_t L_122 = V_1;
		if ((((int32_t)L_122) < ((int32_t)((int32_t)21))))
		{
			goto IL_0187;
		}
	}
	{
		V_1 = ((int32_t)19);
		goto IL_01e3;
	}

IL_01ba:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_123 = ___2_bandLogE;
		int32_t L_124 = V_0;
		int32_t L_125 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_126 = ___2_bandLogE;
		int32_t L_127 = V_0;
		int32_t L_128 = V_1;
		NullCheck(L_126);
		int32_t L_129 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_127)), L_128));
		int32_t L_130 = (L_126)->GetAt(static_cast<il2cpp_array_size_t>(L_129));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_131 = ___2_bandLogE;
		int32_t L_132 = V_0;
		int32_t L_133 = V_1;
		NullCheck(L_131);
		int32_t L_134 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_132)), L_133)), 1));
		int32_t L_135 = (L_131)->GetAt(static_cast<il2cpp_array_size_t>(L_134));
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_136;
		L_136 = Inlines_MAX16_m4D603BAD0F242EB66ED76BE982BC3907D9DF44A5_inline(L_130, ((int32_t)il2cpp_codegen_subtract(L_135, ((int32_t)2048))), NULL);
		NullCheck(L_123);
		(L_123)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_124)), L_125))), (int32_t)L_136);
		int32_t L_137 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_subtract(L_137, 1));
	}

IL_01e3:
	{
		int32_t L_138 = V_1;
		if ((((int32_t)L_138) >= ((int32_t)0)))
		{
			goto IL_01ba;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_139 = V_3;
		int32_t L_140 = V_0;
		NullCheck(L_139);
		int32_t L_141 = L_140;
		int32_t L_142 = (L_139)->GetAt(static_cast<il2cpp_array_size_t>(L_141));
		if ((!(((uint32_t)L_142) == ((uint32_t)1))))
		{
			goto IL_0215;
		}
	}
	{
		V_1 = 0;
		goto IL_020e;
	}

IL_01f1:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_143 = V_8;
		NullCheck(L_143);
		int32_t L_144 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_145 = (L_143)->GetAt(static_cast<il2cpp_array_size_t>(L_144));
		int32_t L_146 = V_1;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_147 = V_8;
		NullCheck(L_147);
		int32_t L_148 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_149 = (L_147)->GetAt(static_cast<il2cpp_array_size_t>(L_148));
		int32_t L_150 = V_1;
		NullCheck(L_149);
		int32_t L_151 = L_150;
		int32_t L_152 = (L_149)->GetAt(static_cast<il2cpp_array_size_t>(L_151));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_153 = ___2_bandLogE;
		int32_t L_154 = V_0;
		int32_t L_155 = V_1;
		NullCheck(L_153);
		int32_t L_156 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_154)), L_155));
		int32_t L_157 = (L_153)->GetAt(static_cast<il2cpp_array_size_t>(L_156));
		il2cpp_codegen_runtime_class_init_inline(OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_il2cpp_TypeInfo_var);
		int32_t L_158;
		L_158 = OpusMSEncoder_logSum_mC189C2CAB88090345C3C24D4D5C103F0D5341A87(L_152, L_157, NULL);
		NullCheck(L_145);
		(L_145)->SetAt(static_cast<il2cpp_array_size_t>(L_146), (int32_t)L_158);
		int32_t L_159 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_159, 1));
	}

IL_020e:
	{
		int32_t L_160 = V_1;
		if ((((int32_t)L_160) < ((int32_t)((int32_t)21))))
		{
			goto IL_01f1;
		}
	}
	{
		goto IL_0294;
	}

IL_0215:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_161 = V_3;
		int32_t L_162 = V_0;
		NullCheck(L_161);
		int32_t L_163 = L_162;
		int32_t L_164 = (L_161)->GetAt(static_cast<il2cpp_array_size_t>(L_163));
		if ((!(((uint32_t)L_164) == ((uint32_t)3))))
		{
			goto IL_0243;
		}
	}
	{
		V_1 = 0;
		goto IL_023c;
	}

IL_021f:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_165 = V_8;
		NullCheck(L_165);
		int32_t L_166 = 2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_167 = (L_165)->GetAt(static_cast<il2cpp_array_size_t>(L_166));
		int32_t L_168 = V_1;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_169 = V_8;
		NullCheck(L_169);
		int32_t L_170 = 2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_171 = (L_169)->GetAt(static_cast<il2cpp_array_size_t>(L_170));
		int32_t L_172 = V_1;
		NullCheck(L_171);
		int32_t L_173 = L_172;
		int32_t L_174 = (L_171)->GetAt(static_cast<il2cpp_array_size_t>(L_173));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_175 = ___2_bandLogE;
		int32_t L_176 = V_0;
		int32_t L_177 = V_1;
		NullCheck(L_175);
		int32_t L_178 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_176)), L_177));
		int32_t L_179 = (L_175)->GetAt(static_cast<il2cpp_array_size_t>(L_178));
		il2cpp_codegen_runtime_class_init_inline(OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_il2cpp_TypeInfo_var);
		int32_t L_180;
		L_180 = OpusMSEncoder_logSum_mC189C2CAB88090345C3C24D4D5C103F0D5341A87(L_174, L_179, NULL);
		NullCheck(L_167);
		(L_167)->SetAt(static_cast<il2cpp_array_size_t>(L_168), (int32_t)L_180);
		int32_t L_181 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_181, 1));
	}

IL_023c:
	{
		int32_t L_182 = V_1;
		if ((((int32_t)L_182) < ((int32_t)((int32_t)21))))
		{
			goto IL_021f;
		}
	}
	{
		goto IL_0294;
	}

IL_0243:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_183 = V_3;
		int32_t L_184 = V_0;
		NullCheck(L_183);
		int32_t L_185 = L_184;
		int32_t L_186 = (L_183)->GetAt(static_cast<il2cpp_array_size_t>(L_185));
		if ((!(((uint32_t)L_186) == ((uint32_t)2))))
		{
			goto IL_0294;
		}
	}
	{
		V_1 = 0;
		goto IL_028f;
	}

IL_024d:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_187 = V_8;
		NullCheck(L_187);
		int32_t L_188 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_189 = (L_187)->GetAt(static_cast<il2cpp_array_size_t>(L_188));
		int32_t L_190 = V_1;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_191 = V_8;
		NullCheck(L_191);
		int32_t L_192 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_193 = (L_191)->GetAt(static_cast<il2cpp_array_size_t>(L_192));
		int32_t L_194 = V_1;
		NullCheck(L_193);
		int32_t L_195 = L_194;
		int32_t L_196 = (L_193)->GetAt(static_cast<il2cpp_array_size_t>(L_195));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_197 = ___2_bandLogE;
		int32_t L_198 = V_0;
		int32_t L_199 = V_1;
		NullCheck(L_197);
		int32_t L_200 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_198)), L_199));
		int32_t L_201 = (L_197)->GetAt(static_cast<il2cpp_array_size_t>(L_200));
		il2cpp_codegen_runtime_class_init_inline(OpusMSEncoder_t15FC13CEBCCBD201A96D97161595FC67E6295573_il2cpp_TypeInfo_var);
		int32_t L_202;
		L_202 = OpusMSEncoder_logSum_mC189C2CAB88090345C3C24D4D5C103F0D5341A87(L_196, ((int32_t)il2cpp_codegen_subtract(L_201, ((int32_t)512))), NULL);
		NullCheck(L_189);
		(L_189)->SetAt(static_cast<il2cpp_array_size_t>(L_190), (int32_t)L_202);
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_203 = V_8;
		NullCheck(L_203);
		int32_t L_204 = 2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_205 = (L_203)->GetAt(static_cast<il2cpp_array_size_t>(L_204));
		int32_t L_206 = V_1;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_207 = V_8;
		NullCheck(L_207);
		int32_t L_208 = 2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_209 = (L_207)->GetAt(static_cast<il2cpp_array_size_t>(L_208));
		int32_t L_210 = V_1;
		NullCheck(L_209);
		int32_t L_211 = L_210;
		int32_t L_212 = (L_209)->GetAt(static_cast<il2cpp_array_size_t>(L_211));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_213 = ___2_bandLogE;
		int32_t L_214 = V_0;
		int32_t L_215 = V_1;
		NullCheck(L_213);
		int32_t L_216 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_214)), L_215));
		int32_t L_217 = (L_213)->GetAt(static_cast<il2cpp_array_size_t>(L_216));
		int32_t L_218;
		L_218 = OpusMSEncoder_logSum_mC189C2CAB88090345C3C24D4D5C103F0D5341A87(L_212, ((int32_t)il2cpp_codegen_subtract(L_217, ((int32_t)512))), NULL);
		NullCheck(L_205);
		(L_205)->SetAt(static_cast<il2cpp_array_size_t>(L_206), (int32_t)L_218);
		int32_t L_219 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_219, 1));
	}

IL_028f:
	{
		int32_t L_220 = V_1;
		if ((((int32_t)L_220) < ((int32_t)((int32_t)21))))
		{
			goto IL_024d;
		}
	}

IL_0294:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_221 = V_9;
		int32_t L_222 = V_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_223 = ___3_mem;
		int32_t L_224 = V_0;
		int32_t L_225 = ___6_overlap;
		int32_t L_226 = ___6_overlap;
		Arrays_MemCopy_m3B172AAA9447D50DF1AE71C15662FB5005858B3F(L_221, L_222, L_223, ((int32_t)il2cpp_codegen_multiply(L_224, L_225)), L_226, NULL);
		int32_t L_227 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_227, 1));
	}

IL_02a8:
	{
		int32_t L_228 = V_0;
		int32_t L_229 = ___7_channels;
		if ((((int32_t)L_228) < ((int32_t)L_229)))
		{
			goto IL_009d;
		}
	}
	{
		V_1 = 0;
		goto IL_02cf;
	}

IL_02b4:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_230 = V_8;
		NullCheck(L_230);
		int32_t L_231 = 1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_232 = (L_230)->GetAt(static_cast<il2cpp_array_size_t>(L_231));
		int32_t L_233 = V_1;
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_234 = V_8;
		NullCheck(L_234);
		int32_t L_235 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_236 = (L_234)->GetAt(static_cast<il2cpp_array_size_t>(L_235));
		int32_t L_237 = V_1;
		NullCheck(L_236);
		int32_t L_238 = L_237;
		int32_t L_239 = (L_236)->GetAt(static_cast<il2cpp_array_size_t>(L_238));
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_240 = V_8;
		NullCheck(L_240);
		int32_t L_241 = 2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_242 = (L_240)->GetAt(static_cast<il2cpp_array_size_t>(L_241));
		int32_t L_243 = V_1;
		NullCheck(L_242);
		int32_t L_244 = L_243;
		int32_t L_245 = (L_242)->GetAt(static_cast<il2cpp_array_size_t>(L_244));
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_246;
		L_246 = Inlines_MIN32_mE77013C78A201F2EF11AE030F4E6DFC4815008F9_inline(L_239, L_245, NULL);
		NullCheck(L_232);
		(L_232)->SetAt(static_cast<il2cpp_array_size_t>(L_233), (int32_t)L_246);
		int32_t L_247 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_247, 1));
	}

IL_02cf:
	{
		int32_t L_248 = V_1;
		if ((((int32_t)L_248) < ((int32_t)((int32_t)21))))
		{
			goto IL_02b4;
		}
	}
	{
		int32_t L_249 = ___7_channels;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_250;
		L_250 = Inlines_celt_log2_m72E298D8304AC7AB2F8334898CA897FF185F8784_inline(((int32_t)(((int32_t)32768)/((int32_t)il2cpp_codegen_subtract(L_249, 1)))), NULL);
		int32_t L_251;
		L_251 = Inlines_HALF16_mCC975475CB9BE63D15752AA7AA0F3E44598ADB4D_inline(L_250, NULL);
		V_6 = L_251;
		V_0 = 0;
		goto IL_030f;
	}

IL_02ee:
	{
		V_1 = 0;
		goto IL_0306;
	}

IL_02f2:
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_252 = V_8;
		int32_t L_253 = V_0;
		NullCheck(L_252);
		int32_t L_254 = L_253;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_255 = (L_252)->GetAt(static_cast<il2cpp_array_size_t>(L_254));
		int32_t L_256 = V_1;
		NullCheck(L_255);
		int32_t* L_257 = ((L_255)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_256)));
		int32_t L_258 = *((int32_t*)L_257);
		int32_t L_259 = V_6;
		*((int32_t*)L_257) = (int32_t)((int32_t)il2cpp_codegen_add(L_258, L_259));
		int32_t L_260 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_260, 1));
	}

IL_0306:
	{
		int32_t L_261 = V_1;
		if ((((int32_t)L_261) < ((int32_t)((int32_t)21))))
		{
			goto IL_02f2;
		}
	}
	{
		int32_t L_262 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_262, 1));
	}

IL_030f:
	{
		int32_t L_263 = V_0;
		if ((((int32_t)L_263) < ((int32_t)3)))
		{
			goto IL_02ee;
		}
	}
	{
		V_0 = 0;
		goto IL_0364;
	}

IL_0317:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_264 = V_3;
		int32_t L_265 = V_0;
		NullCheck(L_264);
		int32_t L_266 = L_265;
		int32_t L_267 = (L_264)->GetAt(static_cast<il2cpp_array_size_t>(L_266));
		if (!L_267)
		{
			goto IL_034a;
		}
	}
	{
		Int32U5BU5DU5BU5D_t179D865D5B30EFCBC50F82C9774329C15943466E* L_268 = V_8;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_269 = V_3;
		int32_t L_270 = V_0;
		NullCheck(L_269);
		int32_t L_271 = L_270;
		int32_t L_272 = (L_269)->GetAt(static_cast<il2cpp_array_size_t>(L_271));
		NullCheck(L_268);
		int32_t L_273 = ((int32_t)il2cpp_codegen_subtract(L_272, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_274 = (L_268)->GetAt(static_cast<il2cpp_array_size_t>(L_273));
		V_14 = L_274;
		V_1 = 0;
		goto IL_0343;
	}

IL_032a:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_275 = ___2_bandLogE;
		int32_t L_276 = V_0;
		int32_t L_277 = V_1;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_278 = ___2_bandLogE;
		int32_t L_279 = V_0;
		int32_t L_280 = V_1;
		NullCheck(L_278);
		int32_t L_281 = ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_279)), L_280));
		int32_t L_282 = (L_278)->GetAt(static_cast<il2cpp_array_size_t>(L_281));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_283 = V_14;
		int32_t L_284 = V_1;
		NullCheck(L_283);
		int32_t L_285 = L_284;
		int32_t L_286 = (L_283)->GetAt(static_cast<il2cpp_array_size_t>(L_285));
		NullCheck(L_275);
		(L_275)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_276)), L_277))), (int32_t)((int32_t)il2cpp_codegen_subtract(L_282, L_286)));
		int32_t L_287 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_287, 1));
	}

IL_0343:
	{
		int32_t L_288 = V_1;
		if ((((int32_t)L_288) < ((int32_t)((int32_t)21))))
		{
			goto IL_032a;
		}
	}
	{
		goto IL_0360;
	}

IL_034a:
	{
		V_1 = 0;
		goto IL_035b;
	}

IL_034e:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_289 = ___2_bandLogE;
		int32_t L_290 = V_0;
		int32_t L_291 = V_1;
		NullCheck(L_289);
		(L_289)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)21), L_290)), L_291))), (int32_t)0);
		int32_t L_292 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_292, 1));
	}

IL_035b:
	{
		int32_t L_293 = V_1;
		if ((((int32_t)L_293) < ((int32_t)((int32_t)21))))
		{
			goto IL_034e;
		}
	}

IL_0360:
	{
		int32_t L_294 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_294, 1));
	}

IL_0364:
	{
		int32_t L_295 = V_0;
		int32_t L_296 = ___7_channels;
		if ((((int32_t)L_295) < ((int32_t)L_296)))
		{
			goto IL_0317;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ParameterOverride_GetValue_TisBoolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_m0A01250BDAB48851C7D45A7FFE9397A3EB421258_gshared (ParameterOverride_t4B8E2A574A094A139B512403B38CE2B594A72A90* __this, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		NullCheck(((ParameterOverride_1_tAF4A5BC7953AAC0B47E4048AAF45DE5D46D6F98C*)CastclassClass((RuntimeObject*)__this, il2cpp_rgctx_data(method->rgctx_data, 0))));
		bool L_0 = ((ParameterOverride_1_tAF4A5BC7953AAC0B47E4048AAF45DE5D46D6F98C*)CastclassClass((RuntimeObject*)__this, il2cpp_rgctx_data(method->rgctx_data, 0)))->___value;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ParameterOverride_GetValue_TisColor_tD001788D726C3A7F1379BEED0260B9591F440C1F_m5FC5C22A9E7194AB14130CD5E5439DE9B4716A4B_gshared (ParameterOverride_t4B8E2A574A094A139B512403B38CE2B594A72A90* __this, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		NullCheck(((ParameterOverride_1_t32E21FA53107C174D9A77919A9628DA90C84E785*)CastclassClass((RuntimeObject*)__this, il2cpp_rgctx_data(method->rgctx_data, 0))));
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_0 = ((ParameterOverride_1_t32E21FA53107C174D9A77919A9628DA90C84E785*)CastclassClass((RuntimeObject*)__this, il2cpp_rgctx_data(method->rgctx_data, 0)))->___value;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ParameterOverride_GetValue_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m9617DA88B06F012AEC3A6142D6424E890B8B4415_gshared (ParameterOverride_t4B8E2A574A094A139B512403B38CE2B594A72A90* __this, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		NullCheck(((ParameterOverride_1_t9289C5BEA43DBDEDF5862BFE9BF6208D198D3675*)CastclassClass((RuntimeObject*)__this, il2cpp_rgctx_data(method->rgctx_data, 0))));
		int32_t L_0 = ((ParameterOverride_1_t9289C5BEA43DBDEDF5862BFE9BF6208D198D3675*)CastclassClass((RuntimeObject*)__this, il2cpp_rgctx_data(method->rgctx_data, 0)))->___value;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ParameterOverride_GetValue_TisInt32Enum_tCBAC8BA2BFF3A845FA599F303093BBBA374B6F0C_mFE4703FBD56A5699741057453C55795EFC16143D_gshared (ParameterOverride_t4B8E2A574A094A139B512403B38CE2B594A72A90* __this, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		NullCheck(((ParameterOverride_1_t63850BEC32FACF94E47CFF944CF6B58B2543653F*)CastclassClass((RuntimeObject*)__this, il2cpp_rgctx_data(method->rgctx_data, 0))));
		int32_t L_0 = ((ParameterOverride_1_t63850BEC32FACF94E47CFF944CF6B58B2543653F*)CastclassClass((RuntimeObject*)__this, il2cpp_rgctx_data(method->rgctx_data, 0)))->___value;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ParameterOverride_GetValue_TisRuntimeObject_m3125524E3CB84A6966D7441F5A6F92A470CB5BD4_gshared (ParameterOverride_t4B8E2A574A094A139B512403B38CE2B594A72A90* __this, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		NullCheck(((ParameterOverride_1_tD5562735DCF56E13A6E77D5FCE083DF6E99D5B3D*)CastclassClass((RuntimeObject*)__this, il2cpp_rgctx_data(method->rgctx_data, 0))));
		RuntimeObject* L_0 = ((ParameterOverride_1_tD5562735DCF56E13A6E77D5FCE083DF6E99D5B3D*)CastclassClass((RuntimeObject*)__this, il2cpp_rgctx_data(method->rgctx_data, 0)))->___value;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float ParameterOverride_GetValue_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m8426B1A42BF113CB2E07EEAA965528BA5321E282_gshared (ParameterOverride_t4B8E2A574A094A139B512403B38CE2B594A72A90* __this, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		NullCheck(((ParameterOverride_1_tF22AA147D92D52ECA8DCF500194976E7EFCCD27F*)CastclassClass((RuntimeObject*)__this, il2cpp_rgctx_data(method->rgctx_data, 0))));
		float L_0 = ((ParameterOverride_1_tF22AA147D92D52ECA8DCF500194976E7EFCCD27F*)CastclassClass((RuntimeObject*)__this, il2cpp_rgctx_data(method->rgctx_data, 0)))->___value;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ParameterOverride_GetValue_TisVector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7_m58D01DF108E91548F577FD37B7BE03C7E4A8F872_gshared (ParameterOverride_t4B8E2A574A094A139B512403B38CE2B594A72A90* __this, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		NullCheck(((ParameterOverride_1_tD0D241E8B4C5C26C43B7768194903854E4C42061*)CastclassClass((RuntimeObject*)__this, il2cpp_rgctx_data(method->rgctx_data, 0))));
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_0 = ((ParameterOverride_1_tD0D241E8B4C5C26C43B7768194903854E4C42061*)CastclassClass((RuntimeObject*)__this, il2cpp_rgctx_data(method->rgctx_data, 0)))->___value;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ParameterOverride_GetValue_TisVector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_m91EA5885781CD8D444684837EF93C4FBC8A89EA0_gshared (ParameterOverride_t4B8E2A574A094A139B512403B38CE2B594A72A90* __this, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		NullCheck(((ParameterOverride_1_t22D7B77092ED927D18B620934135FAAD02002E2A*)CastclassClass((RuntimeObject*)__this, il2cpp_rgctx_data(method->rgctx_data, 0))));
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ((ParameterOverride_1_t22D7B77092ED927D18B620934135FAAD02002E2A*)CastclassClass((RuntimeObject*)__this, il2cpp_rgctx_data(method->rgctx_data, 0)))->___value;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ParameterOverride_GetValue_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mD7CC78EAA785401D30F4FD62E3E7BD2B53AC09D3_gshared (ParameterOverride_t4B8E2A574A094A139B512403B38CE2B594A72A90* __this, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		NullCheck(((ParameterOverride_1_t520B53CC4F37D67D0689376B8F1A4FB1C74D8DC7*)CastclassClass((RuntimeObject*)__this, il2cpp_rgctx_data(method->rgctx_data, 0))));
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_0 = ((ParameterOverride_1_t520B53CC4F37D67D0689376B8F1A4FB1C74D8DC7*)CastclassClass((RuntimeObject*)__this, il2cpp_rgctx_data(method->rgctx_data, 0)))->___value;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ParameterOverride_GetValue_TisIl2CppFullySharedGenericAny_m4D3F6B7073ACB0194A2A969080F4F89E9BD8F604_gshared (ParameterOverride_t4B8E2A574A094A139B512403B38CE2B594A72A90* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_tE59F76EA30FD0313385F51EEE02F78BC676E4EA2 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_T_tE59F76EA30FD0313385F51EEE02F78BC676E4EA2);
	{
		il2cpp_codegen_memcpy(L_0, il2cpp_codegen_get_instance_field_data_pointer(((ParameterOverride_1_tC0878B394E2104ACFBA6CE8629ED7E83346025AA*)CastclassClass((RuntimeObject*)__this, il2cpp_rgctx_data(method->rgctx_data, 0))), il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->rgctx_data, 0),0)), SizeOf_T_tE59F76EA30FD0313385F51EEE02F78BC676E4EA2);
		il2cpp_codegen_memcpy(il2cppRetVal, L_0, SizeOf_T_tE59F76EA30FD0313385F51EEE02F78BC676E4EA2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* PgpObjectFactory_FilterPgpObjects_TisRuntimeObject_m03C13E6208AFAF0018766F7B56F11D796E84906B_gshared (PgpObjectFactory_t74515C653C2839560F3C5AA5DCCE780F61DB9959* __this, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* V_0 = NULL;
	PgpObject_tB68A2D2CE41D9D71FF1AD186EAF590BEE8271B77* V_1 = NULL;
	RuntimeObject* V_2 = NULL;
	{
		List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* L_0 = (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->rgctx_data, 0));
		List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690(L_0, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		goto IL_0023;
	}

IL_0008:
	{
		PgpObject_tB68A2D2CE41D9D71FF1AD186EAF590BEE8271B77* L_1 = V_1;
		V_2 = ((RuntimeObject*)Castclass((RuntimeObject*)((RuntimeObject*)IsInst((RuntimeObject*)L_1, il2cpp_rgctx_data(method->rgctx_data, 2))), il2cpp_rgctx_data(method->rgctx_data, 2)));
		RuntimeObject* L_2 = V_2;
		if (!L_2)
		{
			goto IL_0023;
		}
	}
	{
		List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* L_3 = V_0;
		RuntimeObject* L_4 = V_2;
		NullCheck(L_3);
		List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_inline(L_3, L_4, il2cpp_rgctx_method(method->rgctx_data, 3));
	}

IL_0023:
	{
		PgpObject_tB68A2D2CE41D9D71FF1AD186EAF590BEE8271B77* L_5;
		L_5 = PgpObjectFactory_NextPgpObject_m66C1B3C58A35A3D9C9036ADD42B9F709988C5F1D(__this, NULL);
		PgpObject_tB68A2D2CE41D9D71FF1AD186EAF590BEE8271B77* L_6 = L_5;
		V_1 = L_6;
		if (L_6)
		{
			goto IL_0008;
		}
	}
	{
		List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* L_7 = V_0;
		return (RuntimeObject*)L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pkcs12Store_Clear_TisRuntimeObject_TisRuntimeObject_m6706E22571DBC9A88207450D8F3D591C7582F686_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* ___0_d, List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ___1_o, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* L_0 = ___0_d;
		NullCheck(L_0);
		Dictionary_2_Clear_mCFB5EA7351D5860D2B91592B91A84CA265A41433(L_0, il2cpp_rgctx_method(method->rgctx_data, 1));
		List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* L_1 = ___1_o;
		NullCheck(L_1);
		List_1_Clear_m16C1F2C61FED5955F10EB36BC1CB2DF34B128994_inline(L_1, il2cpp_rgctx_method(method->rgctx_data, 3));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pkcs12Store_Clear_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m21958436036341C5ADC20776CB0DAF6C8993380D_gshared (Dictionary_2_t5C32AF17A5801FB3109E5B0E622BA8402A04E08E* ___0_d, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* ___1_o, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		Dictionary_2_t5C32AF17A5801FB3109E5B0E622BA8402A04E08E* L_0 = ___0_d;
		NullCheck(L_0);
		((  void (*) (Dictionary_2_t5C32AF17A5801FB3109E5B0E622BA8402A04E08E*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_0, il2cpp_rgctx_method(method->rgctx_data, 1));
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_1 = ___1_o;
		NullCheck(L_1);
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(L_1, il2cpp_rgctx_method(method->rgctx_data, 3));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pkcs12Store_Clear_TisCertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6_TisRuntimeObject_mC47CF905ABFA55469FA1F02A953129A518FC8FE5_gshared (Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77* ___0_d, List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* ___1_o, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77* L_0 = ___0_d;
		NullCheck(L_0);
		Dictionary_2_Clear_m8B10E39C816C1A55D0DBCE1F83E06212561DEBE8(L_0, il2cpp_rgctx_method(method->rgctx_data, 1));
		List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* L_1 = ___1_o;
		NullCheck(L_1);
		List_1_Clear_m6357ACBCD4516CB4B5CE08FB7CAB85FA8F1E29A3_inline(L_1, il2cpp_rgctx_method(method->rgctx_data, 3));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pkcs12Store_Map_TisRuntimeObject_TisRuntimeObject_m93D504D79CD9572B826874E034C3100FE94EA833_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* ___0_d, List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ___1_o, RuntimeObject* ___2_k, RuntimeObject* ___3_v, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* L_0 = ___0_d;
		RuntimeObject* L_1 = ___2_k;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_ContainsKey_m703047C213F7AB55C9DC346596287773A1F670CD(L_0, L_1, il2cpp_rgctx_method(method->rgctx_data, 2));
		if (!L_2)
		{
			goto IL_0016;
		}
	}
	{
		Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* L_3 = ___0_d;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = Dictionary_2_get_Comparer_m29B8217F824FC30BC2DE82EDA9759C0CD5EE6063(L_3, il2cpp_rgctx_method(method->rgctx_data, 3));
		List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* L_5 = ___1_o;
		RuntimeObject* L_6 = ___2_k;
		Pkcs12Store_RemoveOrdering_TisRuntimeObject_m6075B9C982D468D5CBE405DF6D523C6FAB17169A(L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 6));
	}

IL_0016:
	{
		List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* L_7 = ___1_o;
		RuntimeObject* L_8 = ___2_k;
		NullCheck(L_7);
		List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_inline(L_7, L_8, il2cpp_rgctx_method(method->rgctx_data, 7));
		Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* L_9 = ___0_d;
		RuntimeObject* L_10 = ___2_k;
		RuntimeObject* L_11 = ___3_v;
		NullCheck(L_9);
		Dictionary_2_set_Item_m1A840355E8EDAECEA9D0C6F5E51B248FAA449CBD(L_9, L_10, L_11, il2cpp_rgctx_method(method->rgctx_data, 9));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pkcs12Store_Map_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m3001E07B1E2C5D3DBF49414D2279844F497D6A06_gshared (Dictionary_2_t5C32AF17A5801FB3109E5B0E622BA8402A04E08E* ___0_d, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* ___1_o, Il2CppFullySharedGenericAny ___2_k, Il2CppFullySharedGenericAny ___3_v, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_K_t3B8057C67FCBCC57A2E12F89C8FBAC60CEEE1113 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 1));
	const uint32_t SizeOf_V_t32B5D308C7D7CEEA12F8316737AFFB08D0E11647 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 8));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_K_t3B8057C67FCBCC57A2E12F89C8FBAC60CEEE1113);
	const Il2CppFullySharedGenericAny L_6 = L_1;
	const Il2CppFullySharedGenericAny L_8 = L_1;
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_K_t3B8057C67FCBCC57A2E12F89C8FBAC60CEEE1113);
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_V_t32B5D308C7D7CEEA12F8316737AFFB08D0E11647);
	{
		Dictionary_2_t5C32AF17A5801FB3109E5B0E622BA8402A04E08E* L_0 = ___0_d;
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 1)) ? ___2_k : &___2_k), SizeOf_K_t3B8057C67FCBCC57A2E12F89C8FBAC60CEEE1113);
		NullCheck(L_0);
		bool L_2;
		L_2 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)), il2cpp_rgctx_method(method->rgctx_data, 2), L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 1)) ? L_1: *(void**)L_1));
		if (!L_2)
		{
			goto IL_0016;
		}
	}
	{
		Dictionary_2_t5C32AF17A5801FB3109E5B0E622BA8402A04E08E* L_3 = ___0_d;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = ((  RuntimeObject* (*) (Dictionary_2_t5C32AF17A5801FB3109E5B0E622BA8402A04E08E*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(L_3, il2cpp_rgctx_method(method->rgctx_data, 3));
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_5 = ___1_o;
		il2cpp_codegen_memcpy(L_6, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 1)) ? ___2_k : &___2_k), SizeOf_K_t3B8057C67FCBCC57A2E12F89C8FBAC60CEEE1113);
		InvokerActionInvoker3< RuntimeObject*, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 6)), il2cpp_rgctx_method(method->rgctx_data, 6), NULL, L_4, L_5, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 1)) ? L_6: *(void**)L_6));
	}

IL_0016:
	{
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_7 = ___1_o;
		il2cpp_codegen_memcpy(L_8, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 1)) ? ___2_k : &___2_k), SizeOf_K_t3B8057C67FCBCC57A2E12F89C8FBAC60CEEE1113);
		NullCheck(L_7);
		InvokerActionInvoker1< Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 7)), il2cpp_rgctx_method(method->rgctx_data, 7), L_7, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 1)) ? L_8: *(void**)L_8));
		Dictionary_2_t5C32AF17A5801FB3109E5B0E622BA8402A04E08E* L_9 = ___0_d;
		il2cpp_codegen_memcpy(L_10, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 1)) ? ___2_k : &___2_k), SizeOf_K_t3B8057C67FCBCC57A2E12F89C8FBAC60CEEE1113);
		il2cpp_codegen_memcpy(L_11, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 8)) ? ___3_v : &___3_v), SizeOf_V_t32B5D308C7D7CEEA12F8316737AFFB08D0E11647);
		NullCheck(L_9);
		InvokerActionInvoker2< Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 9)), il2cpp_rgctx_method(method->rgctx_data, 9), L_9, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 1)) ? L_10: *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 8)) ? L_11: *(void**)L_11));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pkcs12Store_Map_TisCertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6_TisRuntimeObject_mDA288CA09A97E1ED14060076D577D68F23104C03_gshared (Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77* ___0_d, List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* ___1_o, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 ___2_k, RuntimeObject* ___3_v, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77* L_0 = ___0_d;
		CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 L_1 = ___2_k;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_ContainsKey_m99A920E5F0A5E4DC6D9BA3CE06457A7D6886EF30(L_0, L_1, il2cpp_rgctx_method(method->rgctx_data, 2));
		if (!L_2)
		{
			goto IL_0016;
		}
	}
	{
		Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77* L_3 = ___0_d;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = Dictionary_2_get_Comparer_m62BC32ED557CC6C4B8D17CDDE089026A5FA2C635(L_3, il2cpp_rgctx_method(method->rgctx_data, 3));
		List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* L_5 = ___1_o;
		CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 L_6 = ___2_k;
		Pkcs12Store_RemoveOrdering_TisCertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6_mDAEDA60DC524912A0C27C1517478835FD2344AD7(L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 6));
	}

IL_0016:
	{
		List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* L_7 = ___1_o;
		CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 L_8 = ___2_k;
		NullCheck(L_7);
		List_1_Add_mB2B488D34F1A96DF5D4A58A40374FC84B4B2A377_inline(L_7, L_8, il2cpp_rgctx_method(method->rgctx_data, 7));
		Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77* L_9 = ___0_d;
		CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 L_10 = ___2_k;
		RuntimeObject* L_11 = ___3_v;
		NullCheck(L_9);
		Dictionary_2_set_Item_m8D95E96F74963AC7C0BD8CFBEB6B7564C4DE87D6(L_9, L_10, L_11, il2cpp_rgctx_method(method->rgctx_data, 9));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Pkcs12Store_Remove_TisRuntimeObject_TisRuntimeObject_mCDFA9F9FA08F200D7E0D2932F90F4163E2137D7E_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* ___0_d, List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ___1_o, RuntimeObject* ___2_k, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	bool G_B2_0 = false;
	bool G_B1_0 = false;
	{
		Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* L_0 = ___0_d;
		RuntimeObject* L_1 = ___2_k;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_Remove_m5C7C45E75D951A75843F3F7AADD56ECD64F6BC86(L_0, L_1, il2cpp_rgctx_method(method->rgctx_data, 2));
		bool L_3 = L_2;
		if (!L_3)
		{
			G_B2_0 = L_3;
			goto IL_0017;
		}
		G_B1_0 = L_3;
	}
	{
		Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* L_4 = ___0_d;
		NullCheck(L_4);
		RuntimeObject* L_5;
		L_5 = Dictionary_2_get_Comparer_m29B8217F824FC30BC2DE82EDA9759C0CD5EE6063(L_4, il2cpp_rgctx_method(method->rgctx_data, 3));
		List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* L_6 = ___1_o;
		RuntimeObject* L_7 = ___2_k;
		Pkcs12Store_RemoveOrdering_TisRuntimeObject_m6075B9C982D468D5CBE405DF6D523C6FAB17169A(L_5, L_6, L_7, il2cpp_rgctx_method(method->rgctx_data, 6));
		G_B2_0 = G_B1_0;
	}

IL_0017:
	{
		return G_B2_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Pkcs12Store_Remove_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m7A3FB7234378AA636869DE5AC30B1F70072B6174_gshared (Dictionary_2_t5C32AF17A5801FB3109E5B0E622BA8402A04E08E* ___0_d, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* ___1_o, Il2CppFullySharedGenericAny ___2_k, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_K_t708571F1DBDF8FD2B17C88AFD65367918B3B6DC4 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_K_t708571F1DBDF8FD2B17C88AFD65367918B3B6DC4);
	const Il2CppFullySharedGenericAny L_7 = L_1;
	bool G_B2_0 = false;
	bool G_B1_0 = false;
	{
		Dictionary_2_t5C32AF17A5801FB3109E5B0E622BA8402A04E08E* L_0 = ___0_d;
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 1)) ? ___2_k : &___2_k), SizeOf_K_t708571F1DBDF8FD2B17C88AFD65367918B3B6DC4);
		NullCheck(L_0);
		bool L_2;
		L_2 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)), il2cpp_rgctx_method(method->rgctx_data, 2), L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 1)) ? L_1: *(void**)L_1));
		bool L_3 = L_2;
		if (!L_3)
		{
			G_B2_0 = L_3;
			goto IL_0017;
		}
		G_B1_0 = L_3;
	}
	{
		Dictionary_2_t5C32AF17A5801FB3109E5B0E622BA8402A04E08E* L_4 = ___0_d;
		NullCheck(L_4);
		RuntimeObject* L_5;
		L_5 = ((  RuntimeObject* (*) (Dictionary_2_t5C32AF17A5801FB3109E5B0E622BA8402A04E08E*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(L_4, il2cpp_rgctx_method(method->rgctx_data, 3));
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_6 = ___1_o;
		il2cpp_codegen_memcpy(L_7, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 1)) ? ___2_k : &___2_k), SizeOf_K_t708571F1DBDF8FD2B17C88AFD65367918B3B6DC4);
		InvokerActionInvoker3< RuntimeObject*, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 6)), il2cpp_rgctx_method(method->rgctx_data, 6), NULL, L_5, L_6, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 1)) ? L_7: *(void**)L_7));
		G_B2_0 = G_B1_0;
	}

IL_0017:
	{
		return G_B2_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Pkcs12Store_Remove_TisCertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6_TisRuntimeObject_m74E004E8A6417318DAC3E441248D2ED9AC75CC3D_gshared (Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77* ___0_d, List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* ___1_o, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 ___2_k, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	bool G_B2_0 = false;
	bool G_B1_0 = false;
	{
		Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77* L_0 = ___0_d;
		CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 L_1 = ___2_k;
		NullCheck(L_0);
		bool L_2;
		L_2 = Dictionary_2_Remove_m79A129C6C90F1F53B80189D35F54E5C5765308D9(L_0, L_1, il2cpp_rgctx_method(method->rgctx_data, 2));
		bool L_3 = L_2;
		if (!L_3)
		{
			G_B2_0 = L_3;
			goto IL_0017;
		}
		G_B1_0 = L_3;
	}
	{
		Dictionary_2_tC486EA55BDBF940DB7E051EDE2BE275BCD6D1E77* L_4 = ___0_d;
		NullCheck(L_4);
		RuntimeObject* L_5;
		L_5 = Dictionary_2_get_Comparer_m62BC32ED557CC6C4B8D17CDDE089026A5FA2C635(L_4, il2cpp_rgctx_method(method->rgctx_data, 3));
		List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* L_6 = ___1_o;
		CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 L_7 = ___2_k;
		Pkcs12Store_RemoveOrdering_TisCertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6_mDAEDA60DC524912A0C27C1517478835FD2344AD7(L_5, L_6, L_7, il2cpp_rgctx_method(method->rgctx_data, 6));
		G_B2_0 = G_B1_0;
	}

IL_0017:
	{
		return G_B2_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Pkcs12Store_Remove_TisRuntimeObject_TisRuntimeObject_mCDBAE10E27014B7C9B212D7453B7BDC3E8FB62F5_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* ___0_d, List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ___1_o, RuntimeObject* ___2_k, RuntimeObject** ___3_v, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	bool G_B2_0 = false;
	bool G_B1_0 = false;
	{
		Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* L_0 = ___0_d;
		RuntimeObject* L_1 = ___2_k;
		RuntimeObject** L_2 = ___3_v;
		bool L_3;
		L_3 = CollectionUtilities_Remove_TisRuntimeObject_TisRuntimeObject_m130B6F4F89CFE4220CCC1BC3C572BD22F33A4D03((RuntimeObject*)L_0, L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 3));
		bool L_4 = L_3;
		if (!L_4)
		{
			G_B2_0 = L_4;
			goto IL_0018;
		}
		G_B1_0 = L_4;
	}
	{
		Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* L_5 = ___0_d;
		NullCheck(L_5);
		RuntimeObject* L_6;
		L_6 = Dictionary_2_get_Comparer_m29B8217F824FC30BC2DE82EDA9759C0CD5EE6063(L_5, il2cpp_rgctx_method(method->rgctx_data, 5));
		List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* L_7 = ___1_o;
		RuntimeObject* L_8 = ___2_k;
		Pkcs12Store_RemoveOrdering_TisRuntimeObject_m6075B9C982D468D5CBE405DF6D523C6FAB17169A(L_6, L_7, L_8, il2cpp_rgctx_method(method->rgctx_data, 8));
		G_B2_0 = G_B1_0;
	}

IL_0018:
	{
		return G_B2_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Pkcs12Store_Remove_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m8DC57CE7031B86A1556C6DF701B98A2E0A369F27_gshared (Dictionary_2_t5C32AF17A5801FB3109E5B0E622BA8402A04E08E* ___0_d, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* ___1_o, Il2CppFullySharedGenericAny ___2_k, Il2CppFullySharedGenericAny* ___3_v, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_K_t246A6689247F92EAFD37E9042D8408FF16515AB2 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_K_t246A6689247F92EAFD37E9042D8408FF16515AB2);
	const Il2CppFullySharedGenericAny L_8 = L_1;
	bool G_B2_0 = false;
	bool G_B1_0 = false;
	{
		Dictionary_2_t5C32AF17A5801FB3109E5B0E622BA8402A04E08E* L_0 = ___0_d;
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 1)) ? ___2_k : &___2_k), SizeOf_K_t246A6689247F92EAFD37E9042D8408FF16515AB2);
		Il2CppFullySharedGenericAny* L_2 = ___3_v;
		bool L_3;
		L_3 = InvokerFuncInvoker3< bool, RuntimeObject*, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)), il2cpp_rgctx_method(method->rgctx_data, 3), NULL, (RuntimeObject*)L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 1)) ? L_1: *(void**)L_1), L_2);
		bool L_4 = L_3;
		if (!L_4)
		{
			G_B2_0 = L_4;
			goto IL_0018;
		}
		G_B1_0 = L_4;
	}
	{
		Dictionary_2_t5C32AF17A5801FB3109E5B0E622BA8402A04E08E* L_5 = ___0_d;
		NullCheck(L_5);
		RuntimeObject* L_6;
		L_6 = ((  RuntimeObject* (*) (Dictionary_2_t5C32AF17A5801FB3109E5B0E622BA8402A04E08E*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 5)))(L_5, il2cpp_rgctx_method(method->rgctx_data, 5));
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_7 = ___1_o;
		il2cpp_codegen_memcpy(L_8, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 1)) ? ___2_k : &___2_k), SizeOf_K_t246A6689247F92EAFD37E9042D8408FF16515AB2);
		InvokerActionInvoker3< RuntimeObject*, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 8)), il2cpp_rgctx_method(method->rgctx_data, 8), NULL, L_6, L_7, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 1)) ? L_8: *(void**)L_8));
		G_B2_0 = G_B1_0;
	}

IL_0018:
	{
		return G_B2_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pkcs12Store_RemoveOrdering_TisRuntimeObject_m6075B9C982D468D5CBE405DF6D523C6FAB17169A_gshared (RuntimeObject* ___0_c, List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ___1_o, RuntimeObject* ___2_k, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	U3CU3Ec__DisplayClass45_0_1_t3426FDD1940B82C867508C4438EADE01343EC1E0* V_0 = NULL;
	int32_t V_1 = 0;
	{
		U3CU3Ec__DisplayClass45_0_1_t3426FDD1940B82C867508C4438EADE01343EC1E0* L_0 = (U3CU3Ec__DisplayClass45_0_1_t3426FDD1940B82C867508C4438EADE01343EC1E0*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->rgctx_data, 0));
		U3CU3Ec__DisplayClass45_0_1__ctor_m6ECC37F4DD01881E15CDB2E0E861E057EEE4D038(L_0, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		U3CU3Ec__DisplayClass45_0_1_t3426FDD1940B82C867508C4438EADE01343EC1E0* L_1 = V_0;
		RuntimeObject* L_2 = ___0_c;
		NullCheck(L_1);
		L_1->___c = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&L_1->___c), (void*)L_2);
		U3CU3Ec__DisplayClass45_0_1_t3426FDD1940B82C867508C4438EADE01343EC1E0* L_3 = V_0;
		RuntimeObject* L_4 = ___2_k;
		NullCheck(L_3);
		L_3->___k = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&L_3->___k), (void*)L_4);
		List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* L_5 = ___1_o;
		U3CU3Ec__DisplayClass45_0_1_t3426FDD1940B82C867508C4438EADE01343EC1E0* L_6 = V_0;
		Predicate_1_t8342C85FF4E41CD1F7024AC0CDC3E5312A32CB12* L_7 = (Predicate_1_t8342C85FF4E41CD1F7024AC0CDC3E5312A32CB12*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->rgctx_data, 6));
		Predicate_1__ctor_m3E007299121A15DF80F4A210FF8C20E5DF688F20(L_7, (RuntimeObject*)L_6, (intptr_t)((void*)il2cpp_rgctx_method(method->rgctx_data, 5)), il2cpp_rgctx_method(method->rgctx_data, 7));
		NullCheck(L_5);
		int32_t L_8;
		L_8 = List_1_FindIndex_m9875FFE328FA833B2617915FF976DEDA4724EBC3(L_5, L_7, il2cpp_rgctx_method(method->rgctx_data, 8));
		V_1 = L_8;
		int32_t L_9 = V_1;
		if ((((int32_t)L_9) < ((int32_t)0)))
		{
			goto IL_0032;
		}
	}
	{
		List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* L_10 = ___1_o;
		int32_t L_11 = V_1;
		NullCheck(L_10);
		List_1_RemoveAt_m54F62297ADEE4D4FDA697F49ED807BF901201B54(L_10, L_11, il2cpp_rgctx_method(method->rgctx_data, 9));
	}

IL_0032:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pkcs12Store_RemoveOrdering_TisIl2CppFullySharedGenericAny_m6B6992B7552EB891D31335365FE48801E0AE197D_gshared (RuntimeObject* ___0_c, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* ___1_o, Il2CppFullySharedGenericAny ___2_k, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_K_tE13555A0082AD53EDC22B3F9F626EA38CFD4121B = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 3));
	const Il2CppFullySharedGenericAny L_4 = alloca(SizeOf_K_tE13555A0082AD53EDC22B3F9F626EA38CFD4121B);
	U3CU3Ec__DisplayClass45_0_1_tA8B40135106B9C75057C689789E8670F2E1B1DC2* V_0 = NULL;
	int32_t V_1 = 0;
	{
		U3CU3Ec__DisplayClass45_0_1_tA8B40135106B9C75057C689789E8670F2E1B1DC2* L_0 = (U3CU3Ec__DisplayClass45_0_1_tA8B40135106B9C75057C689789E8670F2E1B1DC2*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->rgctx_data, 0));
		((  void (*) (U3CU3Ec__DisplayClass45_0_1_tA8B40135106B9C75057C689789E8670F2E1B1DC2*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_0, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		U3CU3Ec__DisplayClass45_0_1_tA8B40135106B9C75057C689789E8670F2E1B1DC2* L_1 = V_0;
		RuntimeObject* L_2 = ___0_c;
		NullCheck(L_1);
		il2cpp_codegen_write_instance_field_data<RuntimeObject*>(L_1, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->rgctx_data, 0),0), L_2);
		U3CU3Ec__DisplayClass45_0_1_tA8B40135106B9C75057C689789E8670F2E1B1DC2* L_3 = V_0;
		il2cpp_codegen_memcpy(L_4, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 3)) ? ___2_k : &___2_k), SizeOf_K_tE13555A0082AD53EDC22B3F9F626EA38CFD4121B);
		NullCheck(L_3);
		il2cpp_codegen_write_instance_field_data(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->rgctx_data, 0),1), L_4, SizeOf_K_tE13555A0082AD53EDC22B3F9F626EA38CFD4121B);
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_5 = ___1_o;
		U3CU3Ec__DisplayClass45_0_1_tA8B40135106B9C75057C689789E8670F2E1B1DC2* L_6 = V_0;
		Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* L_7 = (Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->rgctx_data, 6));
		((  void (*) (Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107*, RuntimeObject*, intptr_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 7)))(L_7, (RuntimeObject*)L_6, (intptr_t)((void*)il2cpp_rgctx_method(method->rgctx_data, 5)), il2cpp_rgctx_method(method->rgctx_data, 7));
		NullCheck(L_5);
		int32_t L_8;
		L_8 = ((  int32_t (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 8)))(L_5, L_7, il2cpp_rgctx_method(method->rgctx_data, 8));
		V_1 = L_8;
		int32_t L_9 = V_1;
		if ((((int32_t)L_9) < ((int32_t)0)))
		{
			goto IL_0032;
		}
	}
	{
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_10 = ___1_o;
		int32_t L_11 = V_1;
		NullCheck(L_10);
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 9)))(L_10, L_11, il2cpp_rgctx_method(method->rgctx_data, 9));
	}

IL_0032:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Pkcs12Store_RemoveOrdering_TisCertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6_mDAEDA60DC524912A0C27C1517478835FD2344AD7_gshared (RuntimeObject* ___0_c, List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* ___1_o, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 ___2_k, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	U3CU3Ec__DisplayClass45_0_1_tC5DD57B2E5D051E5596DE1A51C9E4425B2A46AA4* V_0 = NULL;
	int32_t V_1 = 0;
	{
		U3CU3Ec__DisplayClass45_0_1_tC5DD57B2E5D051E5596DE1A51C9E4425B2A46AA4* L_0 = (U3CU3Ec__DisplayClass45_0_1_tC5DD57B2E5D051E5596DE1A51C9E4425B2A46AA4*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->rgctx_data, 0));
		U3CU3Ec__DisplayClass45_0_1__ctor_m29E8FD1000EF0300B33971C6137E44B8FAD2CE24(L_0, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		U3CU3Ec__DisplayClass45_0_1_tC5DD57B2E5D051E5596DE1A51C9E4425B2A46AA4* L_1 = V_0;
		RuntimeObject* L_2 = ___0_c;
		NullCheck(L_1);
		L_1->___c = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&L_1->___c), (void*)L_2);
		U3CU3Ec__DisplayClass45_0_1_tC5DD57B2E5D051E5596DE1A51C9E4425B2A46AA4* L_3 = V_0;
		CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 L_4 = ___2_k;
		NullCheck(L_3);
		L_3->___k = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&L_3->___k))->___m_id), (void*)NULL);
		List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* L_5 = ___1_o;
		U3CU3Ec__DisplayClass45_0_1_tC5DD57B2E5D051E5596DE1A51C9E4425B2A46AA4* L_6 = V_0;
		Predicate_1_tB8E1CB39BCA82FC44F9608B8B75AFA61E47EB81A* L_7 = (Predicate_1_tB8E1CB39BCA82FC44F9608B8B75AFA61E47EB81A*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->rgctx_data, 6));
		Predicate_1__ctor_mB25D862104E995A05A4ADDDB9B6E5D1248C707B0(L_7, (RuntimeObject*)L_6, (intptr_t)((void*)il2cpp_rgctx_method(method->rgctx_data, 5)), il2cpp_rgctx_method(method->rgctx_data, 7));
		NullCheck(L_5);
		int32_t L_8;
		L_8 = List_1_FindIndex_mA44D25D71BF94D4C389465BD8BE3139D18000A3D(L_5, L_7, il2cpp_rgctx_method(method->rgctx_data, 8));
		V_1 = L_8;
		int32_t L_9 = V_1;
		if ((((int32_t)L_9) < ((int32_t)0)))
		{
			goto IL_0032;
		}
	}
	{
		List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* L_10 = ___1_o;
		int32_t L_11 = V_1;
		NullCheck(L_10);
		List_1_RemoveAt_m3EA20C82CFE1BDDD044B4C273F9DA16237A8EEFA(L_10, L_11, il2cpp_rgctx_method(method->rgctx_data, 9));
	}

IL_0032:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool PkixNameConstraintValidator_AreEqualSets_TisRuntimeObject_m274C8F90B282F24E21B381E573D75E99965D73E0_gshared (PkixNameConstraintValidator_t37319B18D89CFCC08C6571FA993AB447686380DA* __this, HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* ___0_set1, HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* ___1_set2, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8 V_0;
	memset((&V_0), 0, sizeof(V_0));
	RuntimeObject* V_1 = NULL;
	bool V_2 = false;
	{
		HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* L_0 = ___0_set1;
		HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* L_1 = ___1_set2;
		if ((!(((RuntimeObject*)(HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885*)L_0) == ((RuntimeObject*)(HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885*)L_1))))
		{
			goto IL_0006;
		}
	}
	{
		return (bool)1;
	}

IL_0006:
	{
		HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* L_2 = ___0_set1;
		if (!L_2)
		{
			goto IL_001a;
		}
	}
	{
		HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* L_3 = ___1_set2;
		if (!L_3)
		{
			goto IL_001a;
		}
	}
	{
		HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* L_4 = ___0_set1;
		NullCheck(L_4);
		int32_t L_5;
		L_5 = HashSet_1_get_Count_m41CC85EEB7855CEFA3BC7A32F115387939318ED3_inline(L_4, il2cpp_rgctx_method(method->rgctx_data, 1));
		HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* L_6 = ___1_set2;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = HashSet_1_get_Count_m41CC85EEB7855CEFA3BC7A32F115387939318ED3_inline(L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		if ((((int32_t)L_5) == ((int32_t)L_7)))
		{
			goto IL_001c;
		}
	}

IL_001a:
	{
		return (bool)0;
	}

IL_001c:
	{
		HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* L_8 = ___0_set1;
		NullCheck(L_8);
		Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8 L_9;
		L_9 = HashSet_1_GetEnumerator_m143B98FEED7E9CABA2C494AB2F04DAD60A504635(L_8, il2cpp_rgctx_method(method->rgctx_data, 2));
		V_0 = L_9;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0045:
			{
				Enumerator_Dispose_mFB582AEAA2E73F3128B5571197BEDE256A83F657((&V_0), il2cpp_rgctx_method(method->rgctx_data, 9));
				return;
			}
		});
		try
		{
			{
				goto IL_003a_1;
			}

IL_0025_1:
			{
				RuntimeObject* L_10;
				L_10 = Enumerator_get_Current_m139A176CD271A0532D75BE08DA7831C8C45CE28F_inline((&V_0), il2cpp_rgctx_method(method->rgctx_data, 4));
				V_1 = L_10;
				HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* L_11 = ___1_set2;
				RuntimeObject* L_12 = V_1;
				NullCheck(L_11);
				bool L_13;
				L_13 = HashSet_1_Contains_m9BACE52BFA0BD83C601529D3629118453E459BBB(L_11, L_12, il2cpp_rgctx_method(method->rgctx_data, 7));
				if (L_13)
				{
					goto IL_003a_1;
				}
			}
			{
				V_2 = (bool)0;
				goto IL_0055;
			}

IL_003a_1:
			{
				bool L_14;
				L_14 = Enumerator_MoveNext_m27565F5ACCCC75C3DD34CC4CAE3E6AEFEB9144A6((&V_0), il2cpp_rgctx_method(method->rgctx_data, 8));
				if (L_14)
				{
					goto IL_0025_1;
				}
			}
			{
				goto IL_0053;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0053:
	{
		return (bool)1;
	}

IL_0055:
	{
		bool L_15 = V_2;
		return L_15;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool PkixNameConstraintValidator_AreEqualSets_TisIl2CppFullySharedGenericAny_m2A39C041B4533E5051C520D9BBD475DB6B8CDF7D_gshared (PkixNameConstraintValidator_t37319B18D89CFCC08C6571FA993AB447686380DA* __this, HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* ___0_set1, HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* ___1_set2, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_Enumerator_tEBAD58D6B14B099507BDD50F70CD6F0DE91ACD31 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 3));
	const uint32_t SizeOf_T_t736538F4BC1A5AC3EBF7C4FB70E30588C883923C = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 6));
	void* L_10 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 3)));
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_T_t736538F4BC1A5AC3EBF7C4FB70E30588C883923C);
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T_t736538F4BC1A5AC3EBF7C4FB70E30588C883923C);
	const Enumerator_t0D36BD6D63D775CDEAF8501F5A252535FFFF52CB L_9 = alloca(SizeOf_Enumerator_tEBAD58D6B14B099507BDD50F70CD6F0DE91ACD31);
	Enumerator_t0D36BD6D63D775CDEAF8501F5A252535FFFF52CB V_0 = alloca(SizeOf_Enumerator_tEBAD58D6B14B099507BDD50F70CD6F0DE91ACD31);
	memset(V_0, 0, SizeOf_Enumerator_tEBAD58D6B14B099507BDD50F70CD6F0DE91ACD31);
	Il2CppFullySharedGenericAny V_1 = alloca(SizeOf_T_t736538F4BC1A5AC3EBF7C4FB70E30588C883923C);
	memset(V_1, 0, SizeOf_T_t736538F4BC1A5AC3EBF7C4FB70E30588C883923C);
	bool V_2 = false;
	{
		HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* L_0 = ___0_set1;
		HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* L_1 = ___1_set2;
		if ((!(((RuntimeObject*)(HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87*)L_0) == ((RuntimeObject*)(HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87*)L_1))))
		{
			goto IL_0006;
		}
	}
	{
		return (bool)1;
	}

IL_0006:
	{
		HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* L_2 = ___0_set1;
		if (!L_2)
		{
			goto IL_001a;
		}
	}
	{
		HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* L_3 = ___1_set2;
		if (!L_3)
		{
			goto IL_001a;
		}
	}
	{
		HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* L_4 = ___0_set1;
		NullCheck(L_4);
		int32_t L_5;
		L_5 = ((  int32_t (*) (HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_4, il2cpp_rgctx_method(method->rgctx_data, 1));
		HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* L_6 = ___1_set2;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = ((  int32_t (*) (HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		if ((((int32_t)L_5) == ((int32_t)L_7)))
		{
			goto IL_001c;
		}
	}

IL_001a:
	{
		return (bool)0;
	}

IL_001c:
	{
		HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* L_8 = ___0_set1;
		NullCheck(L_8);
		InvokerActionInvoker1< Enumerator_t0D36BD6D63D775CDEAF8501F5A252535FFFF52CB* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)), il2cpp_rgctx_method(method->rgctx_data, 2), L_8, (Enumerator_t0D36BD6D63D775CDEAF8501F5A252535FFFF52CB*)L_9);
		il2cpp_codegen_memcpy(V_0, L_9, SizeOf_Enumerator_tEBAD58D6B14B099507BDD50F70CD6F0DE91ACD31);
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0045:
			{
				ConstrainedActionInvoker0::Invoke(il2cpp_rgctx_data(method->rgctx_data, 3), il2cpp_rgctx_method(method->rgctx_data, 9), L_10, (void*)(Enumerator_t0D36BD6D63D775CDEAF8501F5A252535FFFF52CB*)V_0);
				return;
			}
		});
		try
		{
			{
				goto IL_003a_1;
			}

IL_0025_1:
			{
				InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)), il2cpp_rgctx_method(method->rgctx_data, 4), (Enumerator_t0D36BD6D63D775CDEAF8501F5A252535FFFF52CB*)V_0, (Il2CppFullySharedGenericAny*)L_11);
				il2cpp_codegen_memcpy(V_1, L_11, SizeOf_T_t736538F4BC1A5AC3EBF7C4FB70E30588C883923C);
				HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* L_12 = ___1_set2;
				il2cpp_codegen_memcpy(L_13, V_1, SizeOf_T_t736538F4BC1A5AC3EBF7C4FB70E30588C883923C);
				NullCheck(L_12);
				bool L_14;
				L_14 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 7)), il2cpp_rgctx_method(method->rgctx_data, 7), L_12, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 6)) ? L_13: *(void**)L_13));
				if (L_14)
				{
					goto IL_003a_1;
				}
			}
			{
				V_2 = (bool)0;
				goto IL_0055;
			}

IL_003a_1:
			{
				bool L_15;
				L_15 = ((  bool (*) (Enumerator_t0D36BD6D63D775CDEAF8501F5A252535FFFF52CB*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 8)))((Enumerator_t0D36BD6D63D775CDEAF8501F5A252535FFFF52CB*)V_0, il2cpp_rgctx_method(method->rgctx_data, 8));
				if (L_15)
				{
					goto IL_0025_1;
				}
			}
			{
				goto IL_0053;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0053:
	{
		return (bool)1;
	}

IL_0055:
	{
		bool L_16 = V_2;
		return L_16;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t PkixNameConstraintValidator_HashCollection_TisRuntimeObject_m82DE4FB818C6759F610333EA9F7D89DD695BCFF8_gshared (PkixNameConstraintValidator_t37319B18D89CFCC08C6571FA993AB447686380DA* __this, HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* ___0_c, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	int32_t V_0 = 0;
	Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8 V_1;
	memset((&V_1), 0, sizeof(V_1));
	RuntimeObject* V_2 = NULL;
	{
		V_0 = 0;
		HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* L_0 = ___0_c;
		if (!L_0)
		{
			goto IL_003f;
		}
	}
	{
		HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* L_1 = ___0_c;
		NullCheck(L_1);
		Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8 L_2;
		L_2 = HashSet_1_GetEnumerator_m143B98FEED7E9CABA2C494AB2F04DAD60A504635(L_1, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_1 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0031:
			{
				Enumerator_Dispose_mFB582AEAA2E73F3128B5571197BEDE256A83F657((&V_1), il2cpp_rgctx_method(method->rgctx_data, 8));
				return;
			}
		});
		try
		{
			{
				goto IL_0026_1;
			}

IL_000e_1:
			{
				RuntimeObject* L_3;
				L_3 = Enumerator_get_Current_m139A176CD271A0532D75BE08DA7831C8C45CE28F_inline((&V_1), il2cpp_rgctx_method(method->rgctx_data, 3));
				V_2 = L_3;
				int32_t L_4 = V_0;
				NullCheck((V_2));
				int32_t L_5;
				L_5 = VirtualFuncInvoker0< int32_t >::Invoke(2, (V_2));
				V_0 = ((int32_t)il2cpp_codegen_add(L_4, L_5));
			}

IL_0026_1:
			{
				bool L_6;
				L_6 = Enumerator_MoveNext_m27565F5ACCCC75C3DD34CC4CAE3E6AEFEB9144A6((&V_1), il2cpp_rgctx_method(method->rgctx_data, 7));
				if (L_6)
				{
					goto IL_000e_1;
				}
			}
			{
				goto IL_003f;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_003f:
	{
		int32_t L_7 = V_0;
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t PkixNameConstraintValidator_HashCollection_TisIl2CppFullySharedGenericAny_mAF26C23013A2E6D58753F5E215FE363E2E82D24F_gshared (PkixNameConstraintValidator_t37319B18D89CFCC08C6571FA993AB447686380DA* __this, HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* ___0_c, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_Enumerator_t0B67DF6E76A7198E311B7A18484F1E05D66A3319 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 2));
	const uint32_t SizeOf_T_tFD3123821530CE77DC8D5C6854DBC0810543A0E9 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 5));
	void* L_3 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 2)));
	void* L_6 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 5)));
	const Il2CppFullySharedGenericAny L_4 = alloca(SizeOf_T_tFD3123821530CE77DC8D5C6854DBC0810543A0E9);
	const Enumerator_t0D36BD6D63D775CDEAF8501F5A252535FFFF52CB L_2 = alloca(SizeOf_Enumerator_t0B67DF6E76A7198E311B7A18484F1E05D66A3319);
	int32_t V_0 = 0;
	Enumerator_t0D36BD6D63D775CDEAF8501F5A252535FFFF52CB V_1 = alloca(SizeOf_Enumerator_t0B67DF6E76A7198E311B7A18484F1E05D66A3319);
	memset(V_1, 0, SizeOf_Enumerator_t0B67DF6E76A7198E311B7A18484F1E05D66A3319);
	Il2CppFullySharedGenericAny V_2 = alloca(SizeOf_T_tFD3123821530CE77DC8D5C6854DBC0810543A0E9);
	memset(V_2, 0, SizeOf_T_tFD3123821530CE77DC8D5C6854DBC0810543A0E9);
	{
		V_0 = 0;
		HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* L_0 = ___0_c;
		if (!L_0)
		{
			goto IL_003f;
		}
	}
	{
		HashSet_1_t2E820DA94CC6D5A61CA29EBD9BE297C43D691C87* L_1 = ___0_c;
		NullCheck(L_1);
		InvokerActionInvoker1< Enumerator_t0D36BD6D63D775CDEAF8501F5A252535FFFF52CB* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)), il2cpp_rgctx_method(method->rgctx_data, 1), L_1, (Enumerator_t0D36BD6D63D775CDEAF8501F5A252535FFFF52CB*)L_2);
		il2cpp_codegen_memcpy(V_1, L_2, SizeOf_Enumerator_t0B67DF6E76A7198E311B7A18484F1E05D66A3319);
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0031:
			{
				ConstrainedActionInvoker0::Invoke(il2cpp_rgctx_data(method->rgctx_data, 2), il2cpp_rgctx_method(method->rgctx_data, 8), L_3, (void*)(Enumerator_t0D36BD6D63D775CDEAF8501F5A252535FFFF52CB*)V_1);
				return;
			}
		});
		try
		{
			{
				goto IL_0026_1;
			}

IL_000e_1:
			{
				InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)), il2cpp_rgctx_method(method->rgctx_data, 3), (Enumerator_t0D36BD6D63D775CDEAF8501F5A252535FFFF52CB*)V_1, (Il2CppFullySharedGenericAny*)L_4);
				il2cpp_codegen_memcpy(V_2, L_4, SizeOf_T_tFD3123821530CE77DC8D5C6854DBC0810543A0E9);
				int32_t L_5 = V_0;
				int32_t L_7;
				L_7 = ConstrainedFuncInvoker0< int32_t >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 5), il2cpp_rgctx_method(method->rgctx_data, 6), L_6, (void*)(Il2CppFullySharedGenericAny*)V_2);
				V_0 = ((int32_t)il2cpp_codegen_add(L_5, L_7));
			}

IL_0026_1:
			{
				bool L_8;
				L_8 = ((  bool (*) (Enumerator_t0D36BD6D63D775CDEAF8501F5A252535FFFF52CB*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 7)))((Enumerator_t0D36BD6D63D775CDEAF8501F5A252535FFFF52CB*)V_1, il2cpp_rgctx_method(method->rgctx_data, 7));
				if (L_8)
				{
					goto IL_000e_1;
				}
			}
			{
				goto IL_003f;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_003f:
	{
		int32_t L_9 = V_0;
		return L_9;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Playable_IsPlayableOfType_TisAudioClipPlayable_tD4B758E68CAE03CB0CD31F90C8A3E603B97143A0_m94FCB00FCEC927F1EAB530CFEC8EE9CCB388CF8A_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	bool V_1 = false;
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8(__this, NULL);
		V_0 = L_0;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = PlayableHandle_IsPlayableOfType_TisAudioClipPlayable_tD4B758E68CAE03CB0CD31F90C8A3E603B97143A0_m95809D16DD3494AEB0E9E652B42E0CE3167BEE0E((&V_0), il2cpp_rgctx_method(method->rgctx_data, 0));
		V_1 = L_1;
		goto IL_0012;
	}

IL_0012:
	{
		bool L_2 = V_1;
		return L_2;
	}
}
IL2CPP_EXTERN_C  bool Playable_IsPlayableOfType_TisAudioClipPlayable_tD4B758E68CAE03CB0CD31F90C8A3E603B97143A0_m94FCB00FCEC927F1EAB530CFEC8EE9CCB388CF8A_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F*>(__this + _offset);
	bool _returnValue;
	_returnValue = Playable_IsPlayableOfType_TisAudioClipPlayable_tD4B758E68CAE03CB0CD31F90C8A3E603B97143A0_m94FCB00FCEC927F1EAB530CFEC8EE9CCB388CF8A(_thisAdjusted, method);
	return _returnValue;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Playable_IsPlayableOfType_TisAudioMixerPlayable_t6AADDF0C53DF1B4C17969EC24B3B4E4975F3A56C_m61519D5329775A9F560D019477CAF48C17777D62_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	bool V_1 = false;
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8(__this, NULL);
		V_0 = L_0;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = PlayableHandle_IsPlayableOfType_TisAudioMixerPlayable_t6AADDF0C53DF1B4C17969EC24B3B4E4975F3A56C_m28F89BE3D7CCE69B28258CC5B1C7D4E814F48CAB((&V_0), il2cpp_rgctx_method(method->rgctx_data, 0));
		V_1 = L_1;
		goto IL_0012;
	}

IL_0012:
	{
		bool L_2 = V_1;
		return L_2;
	}
}
IL2CPP_EXTERN_C  bool Playable_IsPlayableOfType_TisAudioMixerPlayable_t6AADDF0C53DF1B4C17969EC24B3B4E4975F3A56C_m61519D5329775A9F560D019477CAF48C17777D62_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F*>(__this + _offset);
	bool _returnValue;
	_returnValue = Playable_IsPlayableOfType_TisAudioMixerPlayable_t6AADDF0C53DF1B4C17969EC24B3B4E4975F3A56C_m61519D5329775A9F560D019477CAF48C17777D62(_thisAdjusted, method);
	return _returnValue;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Playable_IsPlayableOfType_TisIl2CppFullySharedGenericStruct_m295C4DE8654EB520ABA0C31EAF1E01D89A770DDB_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	bool V_1 = false;
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8(__this, NULL);
		V_0 = L_0;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = ((  bool (*) (PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))((&V_0), il2cpp_rgctx_method(method->rgctx_data, 0));
		V_1 = L_1;
		goto IL_0012;
	}

IL_0012:
	{
		bool L_2 = V_1;
		return L_2;
	}
}
IL2CPP_EXTERN_C  bool Playable_IsPlayableOfType_TisIl2CppFullySharedGenericStruct_m295C4DE8654EB520ABA0C31EAF1E01D89A770DDB_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F*>(__this + _offset);
	bool _returnValue;
	_returnValue = Playable_IsPlayableOfType_TisIl2CppFullySharedGenericStruct_m295C4DE8654EB520ABA0C31EAF1E01D89A770DDB(_thisAdjusted, method);
	return _returnValue;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double PlayableExtensions_GetDuration_TisScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000_m10FB719E47DDD28BA41ACA5AF6ABCF79B1DDA6B3_gshared (ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000 ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	double V_1 = 0.0;
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_codegen_method_get_declaring_type(il2cpp_rgctx_method(method->rgctx_data, 1)));
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = ScriptPlayable_1_GetHandle_mFBB086A8188A0D77BB5CF4A1A03031EA9B67D22A((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		double L_1;
		L_1 = PlayableHandle_GetDuration_mE3CF9C12CA5A186288A7F1981A92F043100E02A7((&V_0), NULL);
		V_1 = L_1;
		goto IL_0019;
	}

IL_0019:
	{
		double L_2 = V_1;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double PlayableExtensions_GetDuration_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_mF13E68A5E74CF61C80D2EEA8CCEEB6DB0AB620DD_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	double V_1 = 0.0;
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		double L_1;
		L_1 = PlayableHandle_GetDuration_mE3CF9C12CA5A186288A7F1981A92F043100E02A7((&V_0), NULL);
		V_1 = L_1;
		goto IL_0019;
	}

IL_0019:
	{
		double L_2 = V_1;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double PlayableExtensions_GetDuration_TisIl2CppFullySharedGenericStruct_m7ECEE6DBF871739F1B3B6A913703864B3864B067_gshared (Il2CppFullySharedGenericStruct ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_0 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	double V_1 = 0.0;
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = ConstrainedFuncInvoker0< PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 1), L_0, (void*)(Il2CppFullySharedGenericStruct*)___0_playable);
		V_0 = L_1;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		double L_2;
		L_2 = PlayableHandle_GetDuration_mE3CF9C12CA5A186288A7F1981A92F043100E02A7((&V_0), NULL);
		V_1 = L_2;
		goto IL_0019;
	}

IL_0019:
	{
		double L_3 = V_1;
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E PlayableExtensions_GetGraph_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_mC0E9E8DFEBDFE1E6F4955D408283A4A24ACD036A_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E L_1;
		L_1 = PlayableHandle_GetGraph_m03AFC9F0B66AC13A120EC37F6964200C9973CE24((&V_0), NULL);
		V_1 = L_1;
		goto IL_0019;
	}

IL_0019:
	{
		PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E L_2 = V_1;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E PlayableExtensions_GetGraph_TisIl2CppFullySharedGenericStruct_m196B755BFA1C48E6D5E498ABA283DB8F5D12FE68_gshared (Il2CppFullySharedGenericStruct ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_0 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = ConstrainedFuncInvoker0< PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 1), L_0, (void*)(Il2CppFullySharedGenericStruct*)___0_playable);
		V_0 = L_1;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E L_2;
		L_2 = PlayableHandle_GetGraph_m03AFC9F0B66AC13A120EC37F6964200C9973CE24((&V_0), NULL);
		V_1 = L_2;
		goto IL_0019;
	}

IL_0019:
	{
		PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E L_3 = V_1;
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m256EDA8AF27DE9691364BE889E1E888503C07807_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___0_playable, int32_t ___1_inputPort, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		int32_t L_1 = ___1_inputPort;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_2;
		L_2 = PlayableHandle_GetInput_m3F42E2CF0D7DFA2396295133D02622C1BE3A8633((&V_0), L_1, NULL);
		V_1 = L_2;
		goto IL_001a;
	}

IL_001a:
	{
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_3 = V_1;
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F PlayableExtensions_GetInput_TisIl2CppFullySharedGenericStruct_m2A0BCE1E63D1F1C3AAE084884E9E880D2546CE40_gshared (Il2CppFullySharedGenericStruct ___0_playable, int32_t ___1_inputPort, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_0 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = ConstrainedFuncInvoker0< PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 1), L_0, (void*)(Il2CppFullySharedGenericStruct*)___0_playable);
		V_0 = L_1;
		int32_t L_2 = ___1_inputPort;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_3;
		L_3 = PlayableHandle_GetInput_m3F42E2CF0D7DFA2396295133D02622C1BE3A8633((&V_0), L_2, NULL);
		V_1 = L_3;
		goto IL_001a;
	}

IL_001a:
	{
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_4 = V_1;
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m05076661DA9B3B8F581371724ECA46B635F075DA_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		int32_t L_1;
		L_1 = PlayableHandle_GetInputCount_m7FE60883E4B7C9AF7D39F28A044924ADBD5E5121((&V_0), NULL);
		V_1 = L_1;
		goto IL_0019;
	}

IL_0019:
	{
		int32_t L_2 = V_1;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t PlayableExtensions_GetInputCount_TisIl2CppFullySharedGenericStruct_mE9CE8DAB40191965A454C72902F57F31866744C6_gshared (Il2CppFullySharedGenericStruct ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_0 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = ConstrainedFuncInvoker0< PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 1), L_0, (void*)(Il2CppFullySharedGenericStruct*)___0_playable);
		V_0 = L_1;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		int32_t L_2;
		L_2 = PlayableHandle_GetInputCount_m7FE60883E4B7C9AF7D39F28A044924ADBD5E5121((&V_0), NULL);
		V_1 = L_2;
		goto IL_0019;
	}

IL_0019:
	{
		int32_t L_3 = V_1;
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m18D691131C03BF3883EBCFAC7A77B15300F2956B_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___0_playable, int32_t ___1_inputIndex, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	float V_1 = 0.0f;
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		int32_t L_1 = ___1_inputIndex;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		float L_2;
		L_2 = PlayableHandle_GetInputWeight_m0C5D7A870D6DDE9F1A5193907ADCA0335DC6207A((&V_0), L_1, NULL);
		V_1 = L_2;
		goto IL_001a;
	}

IL_001a:
	{
		float L_3 = V_1;
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float PlayableExtensions_GetInputWeight_TisIl2CppFullySharedGenericStruct_mDD47AFA3EFE936FBCD1D265BAFF3DED010AC8FE8_gshared (Il2CppFullySharedGenericStruct ___0_playable, int32_t ___1_inputIndex, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_0 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	float V_1 = 0.0f;
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = ConstrainedFuncInvoker0< PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 1), L_0, (void*)(Il2CppFullySharedGenericStruct*)___0_playable);
		V_0 = L_1;
		int32_t L_2 = ___1_inputIndex;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		float L_3;
		L_3 = PlayableHandle_GetInputWeight_m0C5D7A870D6DDE9F1A5193907ADCA0335DC6207A((&V_0), L_2, NULL);
		V_1 = L_3;
		goto IL_001a;
	}

IL_001a:
	{
		float L_4 = V_1;
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t PlayableExtensions_GetPlayState_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_mD03BF381752F9D5D6FC2AFB1C2BBCE0C72DC65E5_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		int32_t L_1;
		L_1 = PlayableHandle_GetPlayState_m14547B804BB9B9B9E2B20B3F0975334CC99E778F((&V_0), NULL);
		V_1 = L_1;
		goto IL_0019;
	}

IL_0019:
	{
		int32_t L_2 = V_1;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t PlayableExtensions_GetPlayState_TisIl2CppFullySharedGenericStruct_m6DE9625388641874F2E89EE6ABFDB3386014990C_gshared (Il2CppFullySharedGenericStruct ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_0 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = ConstrainedFuncInvoker0< PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 1), L_0, (void*)(Il2CppFullySharedGenericStruct*)___0_playable);
		V_0 = L_1;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		int32_t L_2;
		L_2 = PlayableHandle_GetPlayState_m14547B804BB9B9B9E2B20B3F0975334CC99E778F((&V_0), NULL);
		V_1 = L_2;
		goto IL_0019;
	}

IL_0019:
	{
		int32_t L_3 = V_1;
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double PlayableExtensions_GetPreviousTime_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m0B0343E8E7B8D1406CBFD108E793F9AEF0C3F488_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	double V_1 = 0.0;
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		double L_1;
		L_1 = PlayableHandle_GetPreviousTime_m0C6881E900DF5FE7281699876DFE48BA64DEC1BF((&V_0), NULL);
		V_1 = L_1;
		goto IL_0019;
	}

IL_0019:
	{
		double L_2 = V_1;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double PlayableExtensions_GetPreviousTime_TisIl2CppFullySharedGenericStruct_mBBAA237EE11E331EB2FB151DBAA8CA91554B0B74_gshared (Il2CppFullySharedGenericStruct ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_0 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	double V_1 = 0.0;
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = ConstrainedFuncInvoker0< PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 1), L_0, (void*)(Il2CppFullySharedGenericStruct*)___0_playable);
		V_0 = L_1;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		double L_2;
		L_2 = PlayableHandle_GetPreviousTime_m0C6881E900DF5FE7281699876DFE48BA64DEC1BF((&V_0), NULL);
		V_1 = L_2;
		goto IL_0019;
	}

IL_0019:
	{
		double L_3 = V_1;
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double PlayableExtensions_GetTime_TisScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000_mF42A8FB9BE5011547BAE7A809413A36DF97A628F_gshared (ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000 ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	double V_1 = 0.0;
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_codegen_method_get_declaring_type(il2cpp_rgctx_method(method->rgctx_data, 1)));
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = ScriptPlayable_1_GetHandle_mFBB086A8188A0D77BB5CF4A1A03031EA9B67D22A((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		double L_1;
		L_1 = PlayableHandle_GetTime_m27CB24B86EF0E6A4BD2C53907A677059B5D2BD5D((&V_0), NULL);
		V_1 = L_1;
		goto IL_0019;
	}

IL_0019:
	{
		double L_2 = V_1;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double PlayableExtensions_GetTime_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_mE574862DA5FF24138B43FF7E4AC96A4CA3DB5385_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	double V_1 = 0.0;
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		double L_1;
		L_1 = PlayableHandle_GetTime_m27CB24B86EF0E6A4BD2C53907A677059B5D2BD5D((&V_0), NULL);
		V_1 = L_1;
		goto IL_0019;
	}

IL_0019:
	{
		double L_2 = V_1;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double PlayableExtensions_GetTime_TisIl2CppFullySharedGenericStruct_m32A50AE79C138A2EA2F8A8C087555832A6B492C6_gshared (Il2CppFullySharedGenericStruct ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_0 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	double V_1 = 0.0;
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = ConstrainedFuncInvoker0< PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 1), L_0, (void*)(Il2CppFullySharedGenericStruct*)___0_playable);
		V_0 = L_1;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		double L_2;
		L_2 = PlayableHandle_GetTime_m27CB24B86EF0E6A4BD2C53907A677059B5D2BD5D((&V_0), NULL);
		V_1 = L_2;
		goto IL_0019;
	}

IL_0019:
	{
		double L_3 = V_1;
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t PlayableExtensions_GetTimeWrapMode_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_mBB2C9A0F116BD5C38872FF78DE1540452AD21878_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		int32_t L_1;
		L_1 = PlayableHandle_GetTimeWrapMode_m3C4CF421B7470E04537C45092DA9A1D242A5D1B4((&V_0), NULL);
		V_1 = L_1;
		goto IL_0019;
	}

IL_0019:
	{
		int32_t L_2 = V_1;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t PlayableExtensions_GetTimeWrapMode_TisIl2CppFullySharedGenericStruct_m88D52B953105602D073BFE5F9AAFB833F4EAC545_gshared (Il2CppFullySharedGenericStruct ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_0 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = ConstrainedFuncInvoker0< PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 1), L_0, (void*)(Il2CppFullySharedGenericStruct*)___0_playable);
		V_0 = L_1;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		int32_t L_2;
		L_2 = PlayableHandle_GetTimeWrapMode_m3C4CF421B7470E04537C45092DA9A1D242A5D1B4((&V_0), NULL);
		V_1 = L_2;
		goto IL_0019;
	}

IL_0019:
	{
		int32_t L_3 = V_1;
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool PlayableExtensions_IsDone_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m1C5BC568621154DD43E35F73A2A9D8BD4F7ADB6D_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	bool V_1 = false;
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = PlayableHandle_IsDone_mF5DAB54F941BC13799577396526E3901CF639DE6((&V_0), NULL);
		V_1 = L_1;
		goto IL_0019;
	}

IL_0019:
	{
		bool L_2 = V_1;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool PlayableExtensions_IsDone_TisIl2CppFullySharedGenericStruct_m8F24D092E818554DFC0B86A143F4CBBE1FAA0C89_gshared (Il2CppFullySharedGenericStruct ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_0 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	bool V_1 = false;
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = ConstrainedFuncInvoker0< PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 1), L_0, (void*)(Il2CppFullySharedGenericStruct*)___0_playable);
		V_0 = L_1;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = PlayableHandle_IsDone_mF5DAB54F941BC13799577396526E3901CF639DE6((&V_0), NULL);
		V_1 = L_2;
		goto IL_0019;
	}

IL_0019:
	{
		bool L_3 = V_1;
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool PlayableExtensions_IsValid_TisScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000_mB597801F06F1B3583A8FCFA074EC15EE85EAD3EB_gshared (ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000 ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	bool V_1 = false;
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_codegen_method_get_declaring_type(il2cpp_rgctx_method(method->rgctx_data, 1)));
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = ScriptPlayable_1_GetHandle_mFBB086A8188A0D77BB5CF4A1A03031EA9B67D22A((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = PlayableHandle_IsValid_m07631D12846BAAF2CC302E69A28A44BFE9EB5098((&V_0), NULL);
		V_1 = L_1;
		goto IL_0019;
	}

IL_0019:
	{
		bool L_2 = V_1;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool PlayableExtensions_IsValid_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_mEBB50D8764487C299FFE9DFA47DA4A462B114D0F_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	bool V_1 = false;
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = PlayableHandle_IsValid_m07631D12846BAAF2CC302E69A28A44BFE9EB5098((&V_0), NULL);
		V_1 = L_1;
		goto IL_0019;
	}

IL_0019:
	{
		bool L_2 = V_1;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool PlayableExtensions_IsValid_TisIl2CppFullySharedGenericStruct_m8CC2145A91ECB388554A52E3CFD2BCFC1DDACB0C_gshared (Il2CppFullySharedGenericStruct ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_0 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	bool V_1 = false;
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = ConstrainedFuncInvoker0< PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 1), L_0, (void*)(Il2CppFullySharedGenericStruct*)___0_playable);
		V_0 = L_1;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = PlayableHandle_IsValid_m07631D12846BAAF2CC302E69A28A44BFE9EB5098((&V_0), NULL);
		V_1 = L_2;
		goto IL_0019;
	}

IL_0019:
	{
		bool L_3 = V_1;
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_Pause_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m39105CD234AAF7D45B755B122C591D3E64BE9CE3_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_Pause_m75833A31BA17AC8900736C6F5AC778D033001B32((&V_0), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_Pause_TisIl2CppFullySharedGenericStruct_m1624067EA7BE8277EF93A7FE570CBF82B11D739E_gshared (Il2CppFullySharedGenericStruct ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_0 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = ConstrainedFuncInvoker0< PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 1), L_0, (void*)(Il2CppFullySharedGenericStruct*)___0_playable);
		V_0 = L_1;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_Pause_m75833A31BA17AC8900736C6F5AC778D033001B32((&V_0), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_Play_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m66A14B26C484F272EE45A44C80BA2A1B06A26336_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_Play_m1EF8E1105EB6A4A9B0D6638A57CDCBCEEDC6FB2D((&V_0), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_Play_TisIl2CppFullySharedGenericStruct_m4C429E03AA1CC5D166EE5403114A8EE5A7747194_gshared (Il2CppFullySharedGenericStruct ___0_playable, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_0 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = ConstrainedFuncInvoker0< PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 1), L_0, (void*)(Il2CppFullySharedGenericStruct*)___0_playable);
		V_0 = L_1;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_Play_m1EF8E1105EB6A4A9B0D6638A57CDCBCEEDC6FB2D((&V_0), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetDuration_TisScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000_mFB5268DC99CF461EA3D9AD65F55BD4FFD2EBBFE4_gshared (ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000 ___0_playable, double ___1_value, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_codegen_method_get_declaring_type(il2cpp_rgctx_method(method->rgctx_data, 1)));
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = ScriptPlayable_1_GetHandle_mFBB086A8188A0D77BB5CF4A1A03031EA9B67D22A((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		double L_1 = ___1_value;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_SetDuration_m4E07F9F3A90B2F3CE10325D9F405993F03CCA08B((&V_0), L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetDuration_TisAudioClipPlayable_tD4B758E68CAE03CB0CD31F90C8A3E603B97143A0_m67FC8BE5E310D54C91DB1D492F7393237401332E_gshared (AudioClipPlayable_tD4B758E68CAE03CB0CD31F90C8A3E603B97143A0 ___0_playable, double ___1_value, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = AudioClipPlayable_GetHandle_mEA1D664328FF9B08E4F7D5EBCD4B51A754D97C44((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		double L_1 = ___1_value;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_SetDuration_m4E07F9F3A90B2F3CE10325D9F405993F03CCA08B((&V_0), L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetDuration_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_mAA074B6EFE060AF1F7A91653A9232A29238502F3_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___0_playable, double ___1_value, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		double L_1 = ___1_value;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_SetDuration_m4E07F9F3A90B2F3CE10325D9F405993F03CCA08B((&V_0), L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetDuration_TisIl2CppFullySharedGenericStruct_m8E76A0F5DA9E4AED0A1C79EBC1C9260EDFA521E6_gshared (Il2CppFullySharedGenericStruct ___0_playable, double ___1_value, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_0 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = ConstrainedFuncInvoker0< PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 1), L_0, (void*)(Il2CppFullySharedGenericStruct*)___0_playable);
		V_0 = L_1;
		double L_2 = ___1_value;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_SetDuration_m4E07F9F3A90B2F3CE10325D9F405993F03CCA08B((&V_0), L_2, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetInputCount_TisScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000_m70A8E8591CF45FF0468C77163CFCE92182C83914_gshared (ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000 ___0_playable, int32_t ___1_value, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_codegen_method_get_declaring_type(il2cpp_rgctx_method(method->rgctx_data, 1)));
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = ScriptPlayable_1_GetHandle_mFBB086A8188A0D77BB5CF4A1A03031EA9B67D22A((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		int32_t L_1 = ___1_value;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_SetInputCount_m6067CD3616C428F777903FCBFD789060A2185DEE((&V_0), L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m83E88C6D9DB5E178A5CD37203DBAE1C4009F39AD_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___0_playable, int32_t ___1_value, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		int32_t L_1 = ___1_value;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_SetInputCount_m6067CD3616C428F777903FCBFD789060A2185DEE((&V_0), L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetInputCount_TisIl2CppFullySharedGenericStruct_mA61BA49587B7D0FD0A73754EE3E8C411BCF76CF1_gshared (Il2CppFullySharedGenericStruct ___0_playable, int32_t ___1_value, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_0 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = ConstrainedFuncInvoker0< PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 1), L_0, (void*)(Il2CppFullySharedGenericStruct*)___0_playable);
		V_0 = L_1;
		int32_t L_2 = ___1_value;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_SetInputCount_m6067CD3616C428F777903FCBFD789060A2185DEE((&V_0), L_2, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetInputWeight_TisAnimationLayerMixerPlayable_tAD8D28A1E2FB76567E9748CDD11699AEF0B4317D_m0098458950377EDAC6572E3809127E553600E3B6_gshared (AnimationLayerMixerPlayable_tAD8D28A1E2FB76567E9748CDD11699AEF0B4317D ___0_playable, int32_t ___1_inputIndex, float ___2_weight, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AnimationLayerMixerPlayable_tAD8D28A1E2FB76567E9748CDD11699AEF0B4317D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_runtime_class_init_inline(AnimationLayerMixerPlayable_tAD8D28A1E2FB76567E9748CDD11699AEF0B4317D_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = AnimationLayerMixerPlayable_GetHandle_m324A98D0B0BFC0441377D65CAE93C914F828721F((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		int32_t L_1 = ___1_inputIndex;
		float L_2 = ___2_weight;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		bool L_3;
		L_3 = PlayableHandle_SetInputWeight_m8647C2593A24870E429A0832FC26EE2241CC302E((&V_0), L_1, L_2, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetInputWeight_TisAnimationMixerPlayable_t2984697B87B8719A34519FCF2130545D6D7AB6C0_m941604177D9CFD9616CC14C53798A962F510356A_gshared (AnimationMixerPlayable_t2984697B87B8719A34519FCF2130545D6D7AB6C0 ___0_playable, int32_t ___1_inputIndex, float ___2_weight, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AnimationMixerPlayable_t2984697B87B8719A34519FCF2130545D6D7AB6C0_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_runtime_class_init_inline(AnimationMixerPlayable_t2984697B87B8719A34519FCF2130545D6D7AB6C0_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = AnimationMixerPlayable_GetHandle_mBA6CEB1579A713A985D474E75BC282728318882F((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		int32_t L_1 = ___1_inputIndex;
		float L_2 = ___2_weight;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		bool L_3;
		L_3 = PlayableHandle_SetInputWeight_m8647C2593A24870E429A0832FC26EE2241CC302E((&V_0), L_1, L_2, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetInputWeight_TisAnimationMotionXToDeltaPlayable_t3946605ADB0B4C054A27B3D65A59F8EB75B6BE18_mFC9E59E54BFA297BC37E8392A7647C8E00DBD903_gshared (AnimationMotionXToDeltaPlayable_t3946605ADB0B4C054A27B3D65A59F8EB75B6BE18 ___0_playable, int32_t ___1_inputIndex, float ___2_weight, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AnimationMotionXToDeltaPlayable_t3946605ADB0B4C054A27B3D65A59F8EB75B6BE18_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_runtime_class_init_inline(AnimationMotionXToDeltaPlayable_t3946605ADB0B4C054A27B3D65A59F8EB75B6BE18_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = AnimationMotionXToDeltaPlayable_GetHandle_m09F605E78AD7F0135C7F57EB048031091A50E3A2((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		int32_t L_1 = ___1_inputIndex;
		float L_2 = ___2_weight;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		bool L_3;
		L_3 = PlayableHandle_SetInputWeight_m8647C2593A24870E429A0832FC26EE2241CC302E((&V_0), L_1, L_2, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetInputWeight_TisAnimationOffsetPlayable_t39A1B1103995D63650F606BA2EA4ABDF9484AFB4_m9A6E9B4BC78FE46374FD4AEBE0C687F77647087C_gshared (AnimationOffsetPlayable_t39A1B1103995D63650F606BA2EA4ABDF9484AFB4 ___0_playable, int32_t ___1_inputIndex, float ___2_weight, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AnimationOffsetPlayable_t39A1B1103995D63650F606BA2EA4ABDF9484AFB4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_runtime_class_init_inline(AnimationOffsetPlayable_t39A1B1103995D63650F606BA2EA4ABDF9484AFB4_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = AnimationOffsetPlayable_GetHandle_m769BEFF90379AEAB0C579F7800953458CE3EBA78((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		int32_t L_1 = ___1_inputIndex;
		float L_2 = ___2_weight;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		bool L_3;
		L_3 = PlayableHandle_SetInputWeight_m8647C2593A24870E429A0832FC26EE2241CC302E((&V_0), L_1, L_2, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetInputWeight_TisAnimationRemoveScalePlayable_t915611F6D3CC150DDCAF56412AC3E5ACB518A9DD_m219225CB3C4A831CF64F8CD10A42C8F5BC42F449_gshared (AnimationRemoveScalePlayable_t915611F6D3CC150DDCAF56412AC3E5ACB518A9DD ___0_playable, int32_t ___1_inputIndex, float ___2_weight, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AnimationRemoveScalePlayable_t915611F6D3CC150DDCAF56412AC3E5ACB518A9DD_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_runtime_class_init_inline(AnimationRemoveScalePlayable_t915611F6D3CC150DDCAF56412AC3E5ACB518A9DD_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = AnimationRemoveScalePlayable_GetHandle_mFFA58B879F31327187A20ED30E1C814B7BEAA9C6((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		int32_t L_1 = ___1_inputIndex;
		float L_2 = ___2_weight;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		bool L_3;
		L_3 = PlayableHandle_SetInputWeight_m8647C2593A24870E429A0832FC26EE2241CC302E((&V_0), L_1, L_2, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_mB1486DB439CE14D38B8551ACB9596BB05E8D1BA0_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___0_playable, int32_t ___1_inputIndex, float ___2_weight, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		int32_t L_1 = ___1_inputIndex;
		float L_2 = ___2_weight;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		bool L_3;
		L_3 = PlayableHandle_SetInputWeight_m8647C2593A24870E429A0832FC26EE2241CC302E((&V_0), L_1, L_2, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetInputWeight_TisIl2CppFullySharedGenericStruct_m93AAB77AFD073604215086EAABBF681734E28426_gshared (Il2CppFullySharedGenericStruct ___0_playable, int32_t ___1_inputIndex, float ___2_weight, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_0 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = ConstrainedFuncInvoker0< PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 1), L_0, (void*)(Il2CppFullySharedGenericStruct*)___0_playable);
		V_0 = L_1;
		int32_t L_2 = ___1_inputIndex;
		float L_3 = ___2_weight;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		bool L_4;
		L_4 = PlayableHandle_SetInputWeight_m8647C2593A24870E429A0832FC26EE2241CC302E((&V_0), L_2, L_3, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetInputWeight_TisScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m6CA5017510AA73158321D787C88E3A1A8FBE2FC2_gshared (ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000 ___0_playable, Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___1_input, float ___2_weight, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_codegen_method_get_declaring_type(il2cpp_rgctx_method(method->rgctx_data, 1)));
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = ScriptPlayable_1_GetHandle_mFBB086A8188A0D77BB5CF4A1A03031EA9B67D22A((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___1_input), il2cpp_rgctx_method(method->rgctx_data, 3));
		float L_2 = ___2_weight;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_SetInputWeight_mCC570E6D826D79987CC4E021DA9E7C0B700C0AC1((&V_0), L_1, L_2, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetInputWeight_TisAudioMixerPlayable_t6AADDF0C53DF1B4C17969EC24B3B4E4975F3A56C_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m05BAEF9663CE35D213F86E2D27500F885EBB0661_gshared (AudioMixerPlayable_t6AADDF0C53DF1B4C17969EC24B3B4E4975F3A56C ___0_playable, Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___1_input, float ___2_weight, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = AudioMixerPlayable_GetHandle_m6C182D9794E901D123223BB57738A302BEAB41FD((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___1_input), il2cpp_rgctx_method(method->rgctx_data, 3));
		float L_2 = ___2_weight;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_SetInputWeight_mCC570E6D826D79987CC4E021DA9E7C0B700C0AC1((&V_0), L_1, L_2, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_mA9024FD89E1568432B8B6157D8D17AB3A597583B_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___0_playable, Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___1_input, float ___2_weight, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___1_input), il2cpp_rgctx_method(method->rgctx_data, 3));
		float L_2 = ___2_weight;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_SetInputWeight_mCC570E6D826D79987CC4E021DA9E7C0B700C0AC1((&V_0), L_1, L_2, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetInputWeight_TisIl2CppFullySharedGenericStruct_TisIl2CppFullySharedGenericStruct_mA34078166934E98D0F14DB66EEB9577C5B119F96_gshared (Il2CppFullySharedGenericStruct ___0_playable, Il2CppFullySharedGenericStruct ___1_input, float ___2_weight, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_0 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	void* L_2 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 2)));
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = ConstrainedFuncInvoker0< PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 1), L_0, (void*)(Il2CppFullySharedGenericStruct*)___0_playable);
		V_0 = L_1;
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_3;
		L_3 = ConstrainedFuncInvoker0< PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 2), il2cpp_rgctx_method(method->rgctx_data, 3), L_2, (void*)(Il2CppFullySharedGenericStruct*)___1_input);
		float L_4 = ___2_weight;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_SetInputWeight_mCC570E6D826D79987CC4E021DA9E7C0B700C0AC1((&V_0), L_3, L_4, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetPropagateSetTime_TisScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000_m7E4FFD10537E9A21630138331361CCF94058CD46_gshared (ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000 ___0_playable, bool ___1_value, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_codegen_method_get_declaring_type(il2cpp_rgctx_method(method->rgctx_data, 1)));
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = ScriptPlayable_1_GetHandle_mFBB086A8188A0D77BB5CF4A1A03031EA9B67D22A((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		bool L_1 = ___1_value;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_SetPropagateSetTime_mD1458DFF49EF07D73884A9BBAC31358579C8931B((&V_0), L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetPropagateSetTime_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m48B851F67CB3718355E89200E00347A789E0633B_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___0_playable, bool ___1_value, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		bool L_1 = ___1_value;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_SetPropagateSetTime_mD1458DFF49EF07D73884A9BBAC31358579C8931B((&V_0), L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetPropagateSetTime_TisIl2CppFullySharedGenericStruct_m8537E22163D699BEF991455EC331E158B53F2E32_gshared (Il2CppFullySharedGenericStruct ___0_playable, bool ___1_value, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_0 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = ConstrainedFuncInvoker0< PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 1), L_0, (void*)(Il2CppFullySharedGenericStruct*)___0_playable);
		V_0 = L_1;
		bool L_2 = ___1_value;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_SetPropagateSetTime_mD1458DFF49EF07D73884A9BBAC31358579C8931B((&V_0), L_2, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetSpeed_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m0EF52F9741A4D49B762012D8C70F10D62AA33E51_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___0_playable, double ___1_value, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		double L_1 = ___1_value;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_SetSpeed_m39D426AE0DF93F876C2C1EDF9417C11B97A305E9((&V_0), L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetSpeed_TisIl2CppFullySharedGenericStruct_mAFC1DE4392E42BE450A24C8B2FFCEAA1003100F1_gshared (Il2CppFullySharedGenericStruct ___0_playable, double ___1_value, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_0 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = ConstrainedFuncInvoker0< PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 1), L_0, (void*)(Il2CppFullySharedGenericStruct*)___0_playable);
		V_0 = L_1;
		double L_2 = ___1_value;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_SetSpeed_m39D426AE0DF93F876C2C1EDF9417C11B97A305E9((&V_0), L_2, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetTime_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m031C40F9FA72043E47F88D6F25DD7CF69B81DD26_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___0_playable, double ___1_value, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		double L_1 = ___1_value;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_SetTime_m6D255AB6779F3DC278813F1C016FE4EBC9F4B1E4((&V_0), L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetTime_TisIl2CppFullySharedGenericStruct_m97F9F4C6A3DA335B7C14676DB381F482F4DBDDC0_gshared (Il2CppFullySharedGenericStruct ___0_playable, double ___1_value, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_0 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = ConstrainedFuncInvoker0< PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 1), L_0, (void*)(Il2CppFullySharedGenericStruct*)___0_playable);
		V_0 = L_1;
		double L_2 = ___1_value;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_SetTime_m6D255AB6779F3DC278813F1C016FE4EBC9F4B1E4((&V_0), L_2, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetTimeWrapMode_TisScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000_mE0A42D4E74B9785F4D92C9A3CC182413504767F0_gshared (ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000 ___0_playable, int32_t ___1_value, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_codegen_method_get_declaring_type(il2cpp_rgctx_method(method->rgctx_data, 1)));
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = ScriptPlayable_1_GetHandle_mFBB086A8188A0D77BB5CF4A1A03031EA9B67D22A((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		int32_t L_1 = ___1_value;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_SetTimeWrapMode_m88B50CE0AABE0183BBF12ACEC5E84CBEDAB76C2F((&V_0), L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetTimeWrapMode_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_mEB16CD624564302E875C9F37D4938971A306AA7D_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___0_playable, int32_t ___1_value, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_runtime_class_init_inline(Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_il2cpp_TypeInfo_var);
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_0;
		L_0 = Playable_GetHandle_m39356D23E849DC5428B262092657662C064E04F8((&___0_playable), il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_0;
		int32_t L_1 = ___1_value;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_SetTimeWrapMode_m88B50CE0AABE0183BBF12ACEC5E84CBEDAB76C2F((&V_0), L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableExtensions_SetTimeWrapMode_TisIl2CppFullySharedGenericStruct_m0423504BD2E5E5D54404CE83666ED0F9D44F3B2F_gshared (Il2CppFullySharedGenericStruct ___0_playable, int32_t ___1_value, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_0 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 L_1;
		L_1 = ConstrainedFuncInvoker0< PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 1), L_0, (void*)(Il2CppFullySharedGenericStruct*)___0_playable);
		V_0 = L_1;
		int32_t L_2 = ___1_value;
		il2cpp_codegen_runtime_class_init_inline(PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_il2cpp_TypeInfo_var);
		PlayableHandle_SetTimeWrapMode_m88B50CE0AABE0183BBF12ACEC5E84CBEDAB76C2F((&V_0), L_2, NULL);
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_IMIN_m94016B7063A21AE7667DDAB64A044065034C132B_inline (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_a;
		int32_t L_1 = ___1_b;
		if ((((int32_t)L_0) < ((int32_t)L_1)))
		{
			goto IL_0006;
		}
	}
	{
		int32_t L_2 = ___1_b;
		return L_2;
	}

IL_0006:
	{
		int32_t L_3 = ___0_a;
		return L_3;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* CeltEncoder_GetMode_m51534658A97582FB288A8023F6AA133BFBB8AC1F_inline (CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* __this, const RuntimeMethod* method) 
{
	{
		CeltMode_t4C8BAFB93E466C4ED8720DA0D21842CCA36648C5* L_0 = __this->___mode;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_MULT16_32_Q15_m26878C33EF631092FEDA6A0054F6B2C0D0B256B2_inline (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_a;
		int32_t L_1 = ___1_b;
		int32_t L_2 = ___0_a;
		int32_t L_3 = ___1_b;
		return ((int32_t)il2cpp_codegen_add(((int32_t)(((int32_t)il2cpp_codegen_multiply(L_0, ((int32_t)(L_1>>((int32_t)16)))))<<1)), ((int32_t)(((int32_t)il2cpp_codegen_multiply(L_2, ((int32_t)(L_3&((int32_t)65535)))))>>((int32_t)15)))));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_lin2log_m3D1BBF1C15B7B47836676F7D48D1DB73DF4B887C_inline (int32_t ___0_inLin, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_inLin;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		Inlines_silk_CLZ_FRAC_m52AC70C7D15EEBDA3942DD78876AB11EA17646C3_inline(L_0, (&V_0), (&V_1), NULL);
		int32_t L_1 = V_0;
		int32_t L_2;
		L_2 = Inlines_silk_LSHIFT_mE90E3163A0D3526D05046763E167F2271AB0B953_inline(((int32_t)il2cpp_codegen_subtract(((int32_t)31), L_1)), 7, NULL);
		int32_t L_3 = V_1;
		int32_t L_4 = V_1;
		int32_t L_5 = V_1;
		int32_t L_6;
		L_6 = Inlines_silk_MUL_m9A77BFD928CCAE45F57B7A10CB9F70D490D0C8AE_inline(L_4, ((int32_t)il2cpp_codegen_subtract(((int32_t)128), L_5)), NULL);
		int32_t L_7;
		L_7 = Inlines_silk_SMLAWB_m8A023DCCC323ED0EB2CCF43D6ED6357B587EAAD2_inline(L_3, L_6, ((int32_t)179), NULL);
		return ((int32_t)il2cpp_codegen_add(L_2, L_7));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_LSHIFT_mE90E3163A0D3526D05046763E167F2271AB0B953_inline (int32_t ___0_a, int32_t ___1_shift, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_a;
		int32_t L_1 = ___1_shift;
		return ((int32_t)(L_0<<((int32_t)(L_1&((int32_t)31)))));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_SMLAWB_m8A023DCCC323ED0EB2CCF43D6ED6357B587EAAD2_inline (int32_t ___0_a32, int32_t ___1_b32, int32_t ___2_c32, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		int32_t L_0 = ___0_a32;
		int32_t L_1 = ___1_b32;
		int32_t L_2 = ___2_c32;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Inlines_silk_SMULWB_mB0EE85575CC4960FEF6C551F34CFEFEC88AD9623_inline(L_1, L_2, NULL);
		return ((int32_t)il2cpp_codegen_add(L_0, L_3));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_RSHIFT_m0ACD93ACB5B27378849FAD9F6440B867FA755103_inline (int32_t ___0_a, int32_t ___1_shift, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_a;
		int32_t L_1 = ___1_shift;
		return ((int32_t)(L_0>>((int32_t)(L_1&((int32_t)31)))));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_log2lin_mFB61AF160BBA8A179F17F7B375639DDCEDA19090_inline (int32_t ___0_inLog_Q7, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_inLog_Q7;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0006;
		}
	}
	{
		return 0;
	}

IL_0006:
	{
		int32_t L_1 = ___0_inLog_Q7;
		if ((((int32_t)L_1) < ((int32_t)((int32_t)3967))))
		{
			goto IL_0014;
		}
	}
	{
		return ((int32_t)2147483647LL);
	}

IL_0014:
	{
		int32_t L_2 = ___0_inLog_Q7;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Inlines_silk_RSHIFT_m0ACD93ACB5B27378849FAD9F6440B867FA755103_inline(L_2, 7, NULL);
		int32_t L_4;
		L_4 = Inlines_silk_LSHIFT_mE90E3163A0D3526D05046763E167F2271AB0B953_inline(1, L_3, NULL);
		V_0 = L_4;
		int32_t L_5 = ___0_inLog_Q7;
		V_1 = ((int32_t)(L_5&((int32_t)127)));
		int32_t L_6 = ___0_inLog_Q7;
		if ((((int32_t)L_6) >= ((int32_t)((int32_t)2048))))
		{
			goto IL_0057;
		}
	}
	{
		int32_t L_7 = V_0;
		int32_t L_8 = V_0;
		int32_t L_9 = V_1;
		int32_t L_10 = V_1;
		int32_t L_11 = V_1;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_12;
		L_12 = Inlines_silk_SMULBB_m356DF98499DAAA55E6D101C6A46C7FFA0E3FFAC3_inline(L_10, ((int32_t)il2cpp_codegen_subtract(((int32_t)128), L_11)), NULL);
		int32_t L_13;
		L_13 = Inlines_silk_SMLAWB_m8A023DCCC323ED0EB2CCF43D6ED6357B587EAAD2_inline(L_9, L_12, ((int32_t)-174), NULL);
		int32_t L_14;
		L_14 = Inlines_silk_MUL_m9A77BFD928CCAE45F57B7A10CB9F70D490D0C8AE_inline(L_8, L_13, NULL);
		int32_t L_15;
		L_15 = Inlines_silk_ADD_RSHIFT32_mFFB05D8832CA3D810BD6B1FD0C5C1FD1523652FF_inline(L_7, L_14, 7, NULL);
		V_0 = L_15;
		goto IL_007d;
	}

IL_0057:
	{
		int32_t L_16 = V_0;
		int32_t L_17 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_18;
		L_18 = Inlines_silk_RSHIFT_m0ACD93ACB5B27378849FAD9F6440B867FA755103_inline(L_17, 7, NULL);
		int32_t L_19 = V_1;
		int32_t L_20 = V_1;
		int32_t L_21 = V_1;
		int32_t L_22;
		L_22 = Inlines_silk_SMULBB_m356DF98499DAAA55E6D101C6A46C7FFA0E3FFAC3_inline(L_20, ((int32_t)il2cpp_codegen_subtract(((int32_t)128), L_21)), NULL);
		int32_t L_23;
		L_23 = Inlines_silk_SMLAWB_m8A023DCCC323ED0EB2CCF43D6ED6357B587EAAD2_inline(L_19, L_22, ((int32_t)-174), NULL);
		int32_t L_24;
		L_24 = Inlines_silk_MLA_m15F9E5FB62CB367ACA53909EA8308880BC369DC2_inline(L_16, L_18, L_23, NULL);
		V_0 = L_24;
	}

IL_007d:
	{
		int32_t L_25 = V_0;
		return L_25;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_SHL32_m759CE9A6D5B83434728CB2C33BA4320DFACBD900_inline (int32_t ___0_a, int32_t ___1_shift, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_a;
		int32_t L_1 = ___1_shift;
		return ((int32_t)(L_0<<((int32_t)(L_1&((int32_t)31)))));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_SHR32_mE532A866351E7866B6A1BAD8A8E9306DE22AE05F_inline (int32_t ___0_a, int32_t ___1_shift, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_a;
		int32_t L_1 = ___1_shift;
		return ((int32_t)(L_0>>((int32_t)(L_1&((int32_t)31)))));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_MIN16_mD65F33577C97F96B9FE9B2540589BA7FADF52F5E_inline (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_a;
		int32_t L_1 = ___1_b;
		if ((((int32_t)L_0) < ((int32_t)L_1)))
		{
			goto IL_0006;
		}
	}
	{
		int32_t L_2 = ___1_b;
		return L_2;
	}

IL_0006:
	{
		int32_t L_3 = ___0_a;
		return L_3;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_MAX16_m4D603BAD0F242EB66ED76BE982BC3907D9DF44A5_inline (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_a;
		int32_t L_1 = ___1_b;
		if ((((int32_t)L_0) > ((int32_t)L_1)))
		{
			goto IL_0006;
		}
	}
	{
		int32_t L_2 = ___1_b;
		return L_2;
	}

IL_0006:
	{
		int32_t L_3 = ___0_a;
		return L_3;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_HALF16_mCC975475CB9BE63D15752AA7AA0F3E44598ADB4D_inline (int32_t ___0_x, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		int32_t L_0 = ___0_x;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_1;
		L_1 = Inlines_SHR32_mE532A866351E7866B6A1BAD8A8E9306DE22AE05F_inline(L_0, 1, NULL);
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_MULT16_16_m86CC5979188CE7184708F6DC86E20F35D4501777_inline (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_a;
		int32_t L_1 = ___1_b;
		return ((int32_t)il2cpp_codegen_multiply(L_0, L_1));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_PSHR32_m795531FF9BB2EDD62D70EC3925DC6CA0F8B50983_inline (int32_t ___0_a, int32_t ___1_shift, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		int32_t L_0 = ___0_a;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_1;
		L_1 = Inlines_EXTEND32_mE5EBC463B9835A2B476DCBB7D51D91C1876773F6_inline(1, NULL);
		int32_t L_2 = ___1_shift;
		int32_t L_3 = ___1_shift;
		int32_t L_4;
		L_4 = Inlines_SHR32_mE532A866351E7866B6A1BAD8A8E9306DE22AE05F_inline(((int32_t)il2cpp_codegen_add(L_0, ((int32_t)(((int32_t)(L_1<<((int32_t)(L_2&((int32_t)31)))))>>1)))), L_3, NULL);
		return L_4;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_MAX32_m603F38A48C71C4DF8E2938A811D591A5B3485B65_inline (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_a;
		int32_t L_1 = ___1_b;
		if ((((int32_t)L_0) > ((int32_t)L_1)))
		{
			goto IL_0006;
		}
	}
	{
		int32_t L_2 = ___1_b;
		return L_2;
	}

IL_0006:
	{
		int32_t L_3 = ___0_a;
		return L_3;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_IMAX_mFECDD1F5C3C0962AF8B0140E78A6C3A25BCF9C23_inline (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_a;
		int32_t L_1 = ___1_b;
		if ((((int32_t)L_0) > ((int32_t)L_1)))
		{
			goto IL_0006;
		}
	}
	{
		int32_t L_2 = ___1_b;
		return L_2;
	}

IL_0006:
	{
		int32_t L_3 = ___0_a;
		return L_3;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_SHL16_mDE053DF36529BA35606160EBC860F23260B23A87_inline (int32_t ___0_a, int32_t ___1_shift, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_a;
		int32_t L_1 = ___1_shift;
		return ((int32_t)(L_0<<((int32_t)(L_1&((int32_t)31)))));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t CeltEncoder_GetFinalRange_m4BF672C1B80DD81A5D86981BA9EB8CE699F159CF_inline (CeltEncoder_t7210A972BEC26A9998475386D5C7B36C05F1495F* __this, const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = __this->___rng;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t OpusEncoder_get_SampleRate_m07B4CE6A7F1CAD6FA65936B9CF4F0F7536966E52_inline (OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___Fs;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void OpusEncoder_set_ForceMode_m27C03E1D80CD7B099DC5C9603ECCE70B99FB7201_inline (OpusEncoder_t2A03DAEE607F38FACF0908F9F36F780A95C1BB44* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_value;
		__this->___user_forced_mode = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t OpusRepacketizer_GetNumFrames_m2244AD084D7E8802DB6AC4A1F1CAEFDCBF125A23_inline (OpusRepacketizer_t1AEDC6E5A0FF3C8337B4B6F835EA82ED8595C7F0* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___nb_frames;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_MIN32_mE77013C78A201F2EF11AE030F4E6DFC4815008F9_inline (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_a;
		int32_t L_1 = ___1_b;
		if ((((int32_t)L_0) < ((int32_t)L_1)))
		{
			goto IL_0006;
		}
	}
	{
		int32_t L_2 = ___1_b;
		return L_2;
	}

IL_0006:
	{
		int32_t L_3 = ___0_a;
		return L_3;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_celt_log2_m72E298D8304AC7AB2F8334898CA897FF185F8784_inline (int32_t ___0_x, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		int32_t L_0 = ___0_x;
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_1;
		L_1 = log10(((double)((float)(((float)L_0)/(16384.0f)))));
		double L_2;
		L_2 = log10((2.0));
		return il2cpp_codegen_cast_double_to_int<int32_t>(((float)(((float)il2cpp_codegen_multiply((1024.0f), ((float)L_1)))/((float)L_2))));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_gshared_inline (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28* __this, const RuntimeMethod* method) 
{
	{
		bool L_0 = __this->___hasValue;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_gshared_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, int32_t ___0_start, const RuntimeMethod* method) 
{
	ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_2 = __this->____pointer;
		V_0 = L_2;
		uint8_t* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(uint8_t, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_start;
		uint8_t* L_5;
		L_5 = il2cpp_unsafe_add<uint8_t,int32_t>(L_3, L_4);
		int32_t L_6 = __this->____length;
		int32_t L_7 = ___0_start;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_8;
		memset((&L_8), 0, sizeof(L_8));
		Span_1__ctor_m947BF95D54571BF3897F96822B7A8FDA5853497B_inline((&L_8), L_5, ((int32_t)il2cpp_codegen_subtract(L_6, L_7)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 19));
		return L_8;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mE18EBB601FBFA01BA29FE353364700952A9091FE_gshared_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		uint8_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<uint8_t>((uint8_t*)L_1);
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t ReadOnlySpan_1_get_Length_m54864A0BB817050A9110E85BB5FB31EF63699982_gshared_inline (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void opus_copy_channel_out_func_1_Invoke_m25EF632F19B8D56B7FB9C58D141E42FED126F81D_gshared_inline (opus_copy_channel_out_func_1_t2805945BE854CD39521CBB1514A4097CC0333344* __this, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D ___0_dst, int32_t ___1_dst_stride, int32_t ___2_dst_channel, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D ___3_src, int32_t ___4_src_ptr, int32_t ___5_src_stride, int32_t ___6_frame_size, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D, int32_t, int32_t, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D, int32_t, int32_t, int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_dst, ___1_dst_stride, ___2_dst_channel, ___3_src, ___4_src_ptr, ___5_src_stride, ___6_frame_size, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void opus_copy_channel_out_func_1_Invoke_mB9C23E8CD1EED40F2F28F55B16E7F42E95D95441_gshared_inline (opus_copy_channel_out_func_1_t85951F56EF7450B05E135DF219F8BF05B4D5E030* __this, Span_1_t7578EBC2679C3216D7A6FA0DAECAF2256A33CF4C ___0_dst, int32_t ___1_dst_stride, int32_t ___2_dst_channel, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D ___3_src, int32_t ___4_src_ptr, int32_t ___5_src_stride, int32_t ___6_frame_size, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, Span_1_t7578EBC2679C3216D7A6FA0DAECAF2256A33CF4C, int32_t, int32_t, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D, int32_t, int32_t, int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_dst, ___1_dst_stride, ___2_dst_channel, ___3_src, ___4_src_ptr, ___5_src_stride, ___6_frame_size, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void opus_copy_channel_in_func_1_Invoke_mE863D518D4E113322D44FEBB0E6A4112575A199E_gshared_inline (opus_copy_channel_in_func_1_t73990C8C629DA94EEF8E66726DF516DDE7108033* __this, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D ___0_dst, int32_t ___1_dst_ptr, int32_t ___2_dst_stride, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71 ___3_src, int32_t ___4_src_stride, int32_t ___5_src_channel, int32_t ___6_frame_size, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D, int32_t, int32_t, ReadOnlySpan_1_t43371A70E409718817933691123A1C2EEF874E71, int32_t, int32_t, int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_dst, ___1_dst_ptr, ___2_dst_stride, ___3_src, ___4_src_stride, ___5_src_channel, ___6_frame_size, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void opus_copy_channel_in_func_1_Invoke_m6D03E61EA06F045BA121921DC606E861E540D67D_gshared_inline (opus_copy_channel_in_func_1_t484D84949EB9FE0FFB9617C739F465DE3E898F3F* __this, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D ___0_dst, int32_t ___1_dst_ptr, int32_t ___2_dst_stride, ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D ___3_src, int32_t ___4_src_stride, int32_t ___5_src_channel, int32_t ___6_frame_size, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, Span_1_tC1B695440A1567664C2665D76D5614739FDF453D, int32_t, int32_t, ReadOnlySpan_1_t9C2C8EDE84088EDC61AADD4CA3C2CDC72D135E3D, int32_t, int32_t, int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_dst, ___1_dst_ptr, ___2_dst_stride, ___3_src, ___4_src_stride, ___5_src_channel, ___6_frame_size, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
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
		__this->____size = ((int32_t)il2cpp_codegen_add(L_5, 1));
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
		List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Clear_m16C1F2C61FED5955F10EB36BC1CB2DF34B128994_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
	}
	{
		int32_t L_1 = __this->____size;
		V_0 = L_1;
		__this->____size = 0;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_003c;
		}
	}
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_3 = __this->____items;
		int32_t L_4 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, 0, L_4, NULL);
		return;
	}

IL_003c:
	{
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Clear_m6357ACBCD4516CB4B5CE08FB7CAB85FA8F1E29A3_gshared_inline (List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
	}
	{
		int32_t L_1 = __this->____size;
		V_0 = L_1;
		__this->____size = 0;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_003c;
		}
	}
	{
		CertIDU5BU5D_tAB111E9242A68FDF576EDF0A4C73F23E7DD3C802* L_3 = __this->____items;
		int32_t L_4 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, 0, L_4, NULL);
		return;
	}

IL_003c:
	{
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mB2B488D34F1A96DF5D4A58A40374FC84B4B2A377_gshared_inline (List_1_t8463AB35A738EB7BBB02126DC5B6102204C611A5* __this, CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 ___0_item, const RuntimeMethod* method) 
{
	CertIDU5BU5D_tAB111E9242A68FDF576EDF0A4C73F23E7DD3C802* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		CertIDU5BU5D_tAB111E9242A68FDF576EDF0A4C73F23E7DD3C802* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		CertIDU5BU5D_tAB111E9242A68FDF576EDF0A4C73F23E7DD3C802* L_4 = V_0;
		NullCheck(L_4);
		if ((!(((uint32_t)L_3) < ((uint32_t)((int32_t)(((RuntimeArray*)L_4)->max_length))))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_5 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_5, 1));
		CertIDU5BU5D_tAB111E9242A68FDF576EDF0A4C73F23E7DD3C802* L_6 = V_0;
		int32_t L_7 = V_1;
		CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 L_8 = ___0_item;
		NullCheck(L_6);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(L_7), (CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6)L_8);
		return;
	}

IL_0034:
	{
		CertID_t7F878889DA2B677027FFC1F77DEB92F9E2424AE6 L_9 = ___0_item;
		List_1_AddWithResize_mA5D746142AF298C8C2B2EBC5EBC337E78F81F1F8(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t HashSet_1_get_Count_m41CC85EEB7855CEFA3BC7A32F115387939318ED3_gshared_inline (HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____count;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Enumerator_get_Current_m139A176CD271A0532D75BE08DA7831C8C45CE28F_gshared_inline (Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->____current;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Inlines_silk_CLZ_FRAC_m52AC70C7D15EEBDA3942DD78876AB11EA17646C3_inline (int32_t ___0_input, int32_t* ___1_lz, int32_t* ___2_frac_Q7, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_input;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_1;
		L_1 = Inlines_silk_CLZ32_m975B6E91C19261EFAB22308A3A7C2B97E576A197_inline(L_0, NULL);
		V_0 = L_1;
		int32_t* L_2 = ___1_lz;
		int32_t L_3 = V_0;
		*((int32_t*)L_2) = (int32_t)L_3;
		int32_t* L_4 = ___2_frac_Q7;
		int32_t L_5 = ___0_input;
		int32_t L_6 = V_0;
		int32_t L_7;
		L_7 = Inlines_silk_ROR32_m7B2F1BA4281F2CCCE053E73032C9E50AADC1EBC9_inline(L_5, ((int32_t)il2cpp_codegen_subtract(((int32_t)24), L_6)), NULL);
		*((int32_t*)L_4) = (int32_t)((int32_t)(L_7&((int32_t)127)));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_MUL_m9A77BFD928CCAE45F57B7A10CB9F70D490D0C8AE_inline (int32_t ___0_a32, int32_t ___1_b32, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_a32;
		int32_t L_1 = ___1_b32;
		return ((int32_t)il2cpp_codegen_multiply(L_0, L_1));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_SMULWB_mB0EE85575CC4960FEF6C551F34CFEFEC88AD9623_inline (int32_t ___0_a32, int32_t ___1_b32, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_a32;
		int32_t L_1 = ___1_b32;
		return ((int32_t)((int64_t)(((int64_t)il2cpp_codegen_multiply(((int64_t)L_0), ((int64_t)((int16_t)L_1))))>>((int32_t)16))));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_SMULBB_m356DF98499DAAA55E6D101C6A46C7FFA0E3FFAC3_inline (int32_t ___0_a32, int32_t ___1_b32, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_a32;
		int32_t L_1 = ___1_b32;
		return ((int32_t)il2cpp_codegen_multiply((int32_t)((int16_t)L_0), (int32_t)((int16_t)L_1)));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_ADD_RSHIFT32_mFFB05D8832CA3D810BD6B1FD0C5C1FD1523652FF_inline (int32_t ___0_a, int32_t ___1_b, int32_t ___2_shift, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_a;
		int32_t L_1 = ___1_b;
		int32_t L_2 = ___2_shift;
		return ((int32_t)il2cpp_codegen_add(L_0, ((int32_t)(L_1>>((int32_t)(L_2&((int32_t)31)))))));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_MLA_m15F9E5FB62CB367ACA53909EA8308880BC369DC2_inline (int32_t ___0_a32, int32_t ___1_b32, int32_t ___2_c32, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		int32_t L_0 = ___0_a32;
		int32_t L_1 = ___1_b32;
		int32_t L_2 = ___2_c32;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_3;
		L_3 = Inlines_silk_ADD32_m6FFC7DC9AC00CDEC5ED7F9B9785A190F7BF8C81F_inline(L_0, ((int32_t)il2cpp_codegen_multiply(L_1, L_2)), NULL);
		return L_3;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_EXTEND32_mE5EBC463B9835A2B476DCBB7D51D91C1876773F6_inline (int32_t ___0_x, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_x;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m947BF95D54571BF3897F96822B7A8FDA5853497B_gshared_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, uint8_t* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		uint8_t* L_0 = ___0_ptr;
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_CLZ32_m975B6E91C19261EFAB22308A3A7C2B97E576A197_inline (int32_t ___0_in32, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		int32_t L_0 = ___0_in32;
		if (!L_0)
		{
			goto IL_000d;
		}
	}
	{
		int32_t L_1 = ___0_in32;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		int32_t L_2;
		L_2 = Inlines_EC_ILOG_m2C5271EC2BB43C3DC9B682F54CF30EB35E952533_inline(L_1, NULL);
		return ((int32_t)il2cpp_codegen_subtract(((int32_t)32), L_2));
	}

IL_000d:
	{
		return ((int32_t)32);
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_ROR32_m7B2F1BA4281F2CCCE053E73032C9E50AADC1EBC9_inline (int32_t ___0_a32, int32_t ___1_rot, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		int32_t L_0 = ___0_a32;
		int32_t L_1 = ___1_rot;
		il2cpp_codegen_runtime_class_init_inline(Inlines_tAE9744318C893C75A5222C8223442F933705BB0D_il2cpp_TypeInfo_var);
		uint32_t L_2;
		L_2 = Inlines_silk_ROR32_mC598FED457636AB7E43C622D6435614B3E7A9A0A_inline(L_0, L_1, NULL);
		return L_2;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_silk_ADD32_m6FFC7DC9AC00CDEC5ED7F9B9785A190F7BF8C81F_inline (int32_t ___0_a, int32_t ___1_b, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_a;
		int32_t L_1 = ___1_b;
		return ((int32_t)il2cpp_codegen_add(L_0, L_1));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Inlines_EC_ILOG_m2C5271EC2BB43C3DC9B682F54CF30EB35E952533_inline (uint32_t ___0_x, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t G_B3_0 = 0;
	int32_t G_B5_0 = 0;
	int32_t G_B4_0 = 0;
	int32_t G_B6_0 = 0;
	int32_t G_B6_1 = 0;
	int32_t G_B8_0 = 0;
	int32_t G_B7_0 = 0;
	int32_t G_B9_0 = 0;
	int32_t G_B9_1 = 0;
	int32_t G_B11_0 = 0;
	int32_t G_B10_0 = 0;
	int32_t G_B12_0 = 0;
	int32_t G_B12_1 = 0;
	int32_t G_B14_0 = 0;
	int32_t G_B13_0 = 0;
	int32_t G_B15_0 = 0;
	int32_t G_B15_1 = 0;
	int32_t G_B17_0 = 0;
	int32_t G_B16_0 = 0;
	int32_t G_B18_0 = 0;
	int32_t G_B18_1 = 0;
	{
		uint32_t L_0 = ___0_x;
		if (!L_0)
		{
			goto IL_0006;
		}
	}
	{
		G_B3_0 = 1;
		goto IL_0007;
	}

IL_0006:
	{
		G_B3_0 = 0;
	}

IL_0007:
	{
		uint32_t L_1 = ___0_x;
		if (!((int32_t)((int32_t)L_1&((int32_t)-65536))))
		{
			G_B5_0 = G_B3_0;
			goto IL_0013;
		}
		G_B4_0 = G_B3_0;
	}
	{
		G_B6_0 = 1;
		G_B6_1 = G_B4_0;
		goto IL_0014;
	}

IL_0013:
	{
		G_B6_0 = 0;
		G_B6_1 = G_B5_0;
	}

IL_0014:
	{
		V_0 = ((int32_t)(G_B6_0<<4));
		uint32_t L_2 = ___0_x;
		int32_t L_3 = V_0;
		___0_x = ((int32_t)((uint32_t)L_2>>((int32_t)(L_3&((int32_t)31)))));
		int32_t L_4 = V_0;
		uint32_t L_5 = ___0_x;
		if (!((int32_t)((int32_t)L_5&((int32_t)65280))))
		{
			G_B8_0 = ((int32_t)(G_B6_1|L_4));
			goto IL_002d;
		}
		G_B7_0 = ((int32_t)(G_B6_1|L_4));
	}
	{
		G_B9_0 = 1;
		G_B9_1 = G_B7_0;
		goto IL_002e;
	}

IL_002d:
	{
		G_B9_0 = 0;
		G_B9_1 = G_B8_0;
	}

IL_002e:
	{
		V_0 = ((int32_t)(G_B9_0<<3));
		uint32_t L_6 = ___0_x;
		int32_t L_7 = V_0;
		___0_x = ((int32_t)((uint32_t)L_6>>((int32_t)(L_7&((int32_t)31)))));
		int32_t L_8 = V_0;
		uint32_t L_9 = ___0_x;
		if (!((int32_t)((int32_t)L_9&((int32_t)240))))
		{
			G_B11_0 = ((int32_t)(G_B9_1|L_8));
			goto IL_0047;
		}
		G_B10_0 = ((int32_t)(G_B9_1|L_8));
	}
	{
		G_B12_0 = 1;
		G_B12_1 = G_B10_0;
		goto IL_0048;
	}

IL_0047:
	{
		G_B12_0 = 0;
		G_B12_1 = G_B11_0;
	}

IL_0048:
	{
		V_0 = ((int32_t)(G_B12_0<<2));
		uint32_t L_10 = ___0_x;
		int32_t L_11 = V_0;
		___0_x = ((int32_t)((uint32_t)L_10>>((int32_t)(L_11&((int32_t)31)))));
		int32_t L_12 = V_0;
		uint32_t L_13 = ___0_x;
		if (!((int32_t)((int32_t)L_13&((int32_t)12))))
		{
			G_B14_0 = ((int32_t)(G_B12_1|L_12));
			goto IL_005e;
		}
		G_B13_0 = ((int32_t)(G_B12_1|L_12));
	}
	{
		G_B15_0 = 1;
		G_B15_1 = G_B13_0;
		goto IL_005f;
	}

IL_005e:
	{
		G_B15_0 = 0;
		G_B15_1 = G_B14_0;
	}

IL_005f:
	{
		V_0 = ((int32_t)(G_B15_0<<1));
		uint32_t L_14 = ___0_x;
		int32_t L_15 = V_0;
		___0_x = ((int32_t)((uint32_t)L_14>>((int32_t)(L_15&((int32_t)31)))));
		int32_t L_16 = V_0;
		uint32_t L_17 = ___0_x;
		if (!((int32_t)((int32_t)L_17&2)))
		{
			G_B17_0 = ((int32_t)(G_B15_1|L_16));
			goto IL_0074;
		}
		G_B16_0 = ((int32_t)(G_B15_1|L_16));
	}
	{
		G_B18_0 = 1;
		G_B18_1 = G_B16_0;
		goto IL_0075;
	}

IL_0074:
	{
		G_B18_0 = 0;
		G_B18_1 = G_B17_0;
	}

IL_0075:
	{
		return ((int32_t)il2cpp_codegen_add(G_B18_1, G_B18_0));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t Inlines_silk_ROR32_mC598FED457636AB7E43C622D6435614B3E7A9A0A_inline (uint32_t ___0_a32, int32_t ___1_rot, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___1_rot;
		V_0 = ((int32_t)il2cpp_codegen_subtract(0, L_0));
		int32_t L_1 = ___1_rot;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		uint32_t L_2 = ___0_a32;
		return L_2;
	}

IL_0009:
	{
		int32_t L_3 = ___1_rot;
		if ((((int32_t)L_3) >= ((int32_t)0)))
		{
			goto IL_001e;
		}
	}
	{
		uint32_t L_4 = ___0_a32;
		int32_t L_5 = V_0;
		uint32_t L_6 = ___0_a32;
		int32_t L_7 = V_0;
		return ((int32_t)(((int32_t)((int32_t)L_4<<((int32_t)(L_5&((int32_t)31)))))|((int32_t)((uint32_t)L_6>>((int32_t)(((int32_t)il2cpp_codegen_subtract(((int32_t)32), L_7))&((int32_t)31)))))));
	}

IL_001e:
	{
		uint32_t L_8 = ___0_a32;
		int32_t L_9 = ___1_rot;
		uint32_t L_10 = ___0_a32;
		int32_t L_11 = ___1_rot;
		return ((int32_t)(((int32_t)((int32_t)L_8<<((int32_t)(((int32_t)il2cpp_codegen_subtract(((int32_t)32), L_9))&((int32_t)31)))))|((int32_t)((uint32_t)L_10>>((int32_t)(L_11&((int32_t)31)))))));
	}
}
