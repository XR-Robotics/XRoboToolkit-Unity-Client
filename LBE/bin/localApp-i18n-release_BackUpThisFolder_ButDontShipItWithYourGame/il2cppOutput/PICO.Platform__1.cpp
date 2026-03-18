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
template <typename R>
struct GenericVirtualFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (const RuntimeMethod* method, RuntimeObject* obj)
	{
		VirtualInvokeData invokeData;
		il2cpp_codegen_get_generic_virtual_invoke_data(method, obj, &invokeData);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
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
template <typename R>
struct GenericInterfaceFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (const RuntimeMethod* method, RuntimeObject* obj)
	{
		VirtualInvokeData invokeData;
		il2cpp_codegen_get_generic_interface_invoke_data(method, obj, &invokeData);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
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
template <typename R, typename T1, typename T2>
struct InvokerFuncInvoker2;
template <typename R, typename T1, typename T2>
struct InvokerFuncInvoker2<R, T1*, T2*>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2)
	{
		R ret;
		void* params[2] = { p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};

// System.Action`1<UnityEngine.AsyncOperation>
struct Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB;
// System.Collections.Generic.Dictionary`2<System.Int32,System.Text.Encoding>
struct Dictionary_2_t87EDE08B2E48F793A22DE50D6B3CC2E7EBB2DB54;
// System.Collections.Generic.Dictionary`2<System.Int32Enum,System.Int32>
struct Dictionary_2_tFCDE91BDD0207A67521C455FD60B9EAA6E0E6B62;
// System.Collections.Generic.Dictionary`2<System.Object,System.Int32Enum>
struct Dictionary_2_t2A9A7F3ECFC3483F89253F3C4BB5BE98A37F6EF3;
// System.Collections.Generic.Dictionary`2<Pico.Platform.RtcPrivilege,System.Int32>
struct Dictionary_2_tFA4E3C6BBA632C5BEEBB77A03650502241C2D607;
// System.Collections.Generic.Dictionary`2<System.String,System.String>
struct Dictionary_2_t46B2DB028096FA2B828359E52F37F3105A83AD83;
// System.Collections.Generic.Dictionary`2<System.String,Pico.Platform.UserRelationType>
struct Dictionary_2_tFFB4984E3277B96D7DD77603CA615351CE58744C;
// Pico.Platform.Message`1/Handler<Pico.Platform.Models.AsrResult>
struct Handler_tE5970BF7190FDDDFE47C25F9F98FC3037D7F753F;
// Pico.Platform.Message`1/Handler<System.Int32>
struct Handler_t51AE26B34C94E80FFE0A43298E5E7BCF0085B456;
// Pico.Platform.Message`1/Handler<System.Int32Enum>
struct Handler_tB73A87C4788188C83AABC7D2F6641CEF5AAFBA96;
// Pico.Platform.Message`1/Handler<System.Object>
struct Handler_t7C4295C020EB651F0A93127B11D3315DD6007787;
// Pico.Platform.Message`1/Handler<Pico.Platform.Models.PermissionResult>
struct Handler_tF65149A494CDA59437FE06A5E974BDECEB45C2B3;
// Pico.Platform.Message`1/Handler<Pico.Platform.PlatformInitializeResult>
struct Handler_t514BEA54A8C9B5734E3D678B336DDA196A366022;
// Pico.Platform.Message`1/Handler<Pico.Platform.RtcAudioPlaybackDevice>
struct Handler_t9E74A09C7774D66FE0B94FDFE1DFA6DDEC5859ED;
// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcBinaryMessageReceived>
struct Handler_t1549946AE7DD631785DEE828E599E4CC5F232986;
// Pico.Platform.Message`1/Handler<Pico.Platform.RtcConnectionState>
struct Handler_t38CC844160733F92880FA63972B403BF586D39B1;
// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcJoinRoomResult>
struct Handler_tAFF89B31CBE84C07A66A39AC220981DEC2B648C7;
// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcLeaveRoomResult>
struct Handler_t53CDA67D66BFBB13CE74EC8B6623D88EB60E6CAE;
// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcLocalAudioPropertiesReport>
struct Handler_tAC738204727C49FCB4492833A34C3C4A619CEC8E;
// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcMessageSendResult>
struct Handler_t19833D1404BED864BD881EC7D6947C4BE818F739;
// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcMuteInfo>
struct Handler_t031AC8F825D5CD006D0F5F9FE16EB538F31C1101;
// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRemoteAudioPropertiesReport>
struct Handler_t2765C77EA08935A8D61BD6074F539B8BA92581B9;
// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRoomError>
struct Handler_tAB0E94E2155E2F41351762B712D4F71A3E696890;
// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRoomMessageReceived>
struct Handler_t063B85C34774FF958AF1A957B4854AF1D6B23888;
// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRoomStats>
struct Handler_t75AD0D0BA45ACBB20855ADA2457EB304BF32C5B9;
// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRoomWarn>
struct Handler_tCAF1D3F2723A4B7251F1BC23304D41F30171BA7E;
// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcStreamSyncInfo>
struct Handler_t4BEE9C610174E243B1AA20525A10BBD66E21BDF5;
// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserJoinInfo>
struct Handler_t560A0AAA9073BD8BEBEA299A0C30C715A673E10D;
// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserLeaveInfo>
struct Handler_t163FC6326170437BFF25564AF32923B777FDDE24;
// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserMessageReceived>
struct Handler_t32B3FC4A52987EC7404B0AC82BD702C403DB3C40;
// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserPublishInfo>
struct Handler_tD0453CC0FF093CB47FCC2768A008B81EA8988C7F;
// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserUnPublishInfo>
struct Handler_t7B5EC3663F375895202BECAC07552A9F3DCD971D;
// Pico.Platform.Message`1/Handler<Pico.Platform.Models.SpeechError>
struct Handler_t4491361073BF898EF4019198FE0FA845AEA8C7C6;
// Pico.Platform.Message`1/Handler<System.String>
struct Handler_tE2837A49F6F6E0632D5E94EF3412C338F6526C86;
// Pico.Platform.Message`1/Handler<Pico.Platform.Models.User>
struct Handler_t3014C5064A71B62349A0B6C599C034BA36D6E17E;
// System.Collections.Generic.IEqualityComparer`1<Pico.Platform.RtcPrivilege>
struct IEqualityComparer_1_t623CFE53D6DBDDB9514B4C2FD4F24F30B96DB173;
// System.Collections.Generic.IEqualityComparer`1<System.String>
struct IEqualityComparer_1_tAE94C8F24AD5B94D4EE85CA9FC59E3409D41CAF7;
// System.Collections.Generic.Dictionary`2/KeyCollection<Pico.Platform.RtcPrivilege,System.Int32>
struct KeyCollection_tD6EC0C8CA3770A4D5AA70DE315028D365F3019B8;
// System.Collections.Generic.Dictionary`2/KeyCollection<System.String,System.String>
struct KeyCollection_t2EDD317F5771E575ACB63527B5AFB71291040342;
// System.Collections.Generic.Dictionary`2/KeyCollection<System.String,Pico.Platform.UserRelationType>
struct KeyCollection_tB39BE178CDFA58872734D7D9D7A2B273DF42DD59;
// System.Collections.Generic.List`1<Pico.Platform.Models.AchievementDefinition>
struct List_1_t10AC4D431308924325EECB4A49074CCAD3525C5D;
// System.Collections.Generic.List`1<Pico.Platform.Models.AchievementProgress>
struct List_1_tB745982DEF869D4B1F9C78EE82DF592AB431896B;
// System.Collections.Generic.List`1<Pico.Platform.Models.ApplicationInvite>
struct List_1_tE88D817DED2AB9E24E7A5629200C2087045253F5;
// System.Collections.Generic.List`1<Pico.Platform.Models.AssetDetails>
struct List_1_t99C4055E7A18C1DF32B7AECA7EE4535206181597;
// System.Collections.Generic.List`1<Pico.Platform.Models.Challenge>
struct List_1_t1270A6FA80F83E5E821A0DAE5FB3C06865ACB59C;
// System.Collections.Generic.List`1<Pico.Platform.Models.ChallengeEntry>
struct List_1_t3A2B2890CB7F9F96B159F90ED3C352D0F69BFC03;
// System.Collections.Generic.List`1<Pico.Platform.Models.Destination>
struct List_1_t5C085F464CB50B6E73049AC6D994648AA7E2410E;
// System.Collections.Generic.List`1<Pico.Platform.Models.Leaderboard>
struct List_1_t724694C0B4027B186B04C28FF07C047043904083;
// System.Collections.Generic.List`1<Pico.Platform.Models.LeaderboardEntry>
struct List_1_tC943684C0EBEF2BD2CFD9D2B29FC554E51FBB6A8;
// System.Collections.Generic.List`1<Pico.Platform.Models.MatchmakingAdminSnapshotCandidate>
struct List_1_tABBB0A07DB48EE3A69D8AE19FD395C748196C1A1;
// System.Collections.Generic.List`1<Pico.Platform.Models.MatchmakingRoom>
struct List_1_tA41CDF0D6A3ED7853A9F821A69838D214E8DD5CB;
// System.Collections.Generic.List`1<System.Object>
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D;
// System.Collections.Generic.List`1<Pico.Platform.Models.Product>
struct List_1_tECB4BC629C4B6ABBCAC7C8ADCEFEBA5518203F3C;
// System.Collections.Generic.List`1<Pico.Platform.Models.Purchase>
struct List_1_t0BED0F374F8819664848045406304C5C43B290F8;
// System.Collections.Generic.List`1<Pico.Platform.Models.Room>
struct List_1_t17BC494950CA211E4E00DDC3979C43A2750F5DF8;
// System.Collections.Generic.List`1<Pico.Platform.Models.RoomInviteNotification>
struct List_1_t56C8E4CBC81C6319DB682BE3E114E43F68C3AB09;
// System.Collections.Generic.List`1<Pico.Platform.Models.SportDailySummary>
struct List_1_t6C36B6FAA48E5DAE13D84C1C2C9D39AEEF86399F;
// System.Collections.Generic.List`1<Pico.Platform.Models.User>
struct List_1_tA51A980F281692A23CBC3DFCF8131D4AD8565A1C;
// System.Collections.Generic.List`1<Pico.Platform.Models.UserRoom>
struct List_1_t68B676CB2F1554E5228FD7A20B97B490395C7E2C;
// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.AchievementDefinition>
struct MessageArray_1_t007C8F0F960A812D5EBEBD1E0DEB87A40D9F0051;
// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.AchievementProgress>
struct MessageArray_1_tA2FC832E9F92BC2639E48F182ED14B04435430CA;
// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.ApplicationInvite>
struct MessageArray_1_tBD7F57C2576E156E6CA055C10BDF9CF1A640AAB8;
// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.AssetDetails>
struct MessageArray_1_t3588ACF0944917D806087EF192359A96F2EF26D6;
// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Challenge>
struct MessageArray_1_t3AD15036E7E447220D0A42DE4FB31045C546D530;
// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.ChallengeEntry>
struct MessageArray_1_t7879F9CC787398F1DCC478C7DFC9D19EB4D4837E;
// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Destination>
struct MessageArray_1_t77601FC32D4AB8164AF6BDA2F26DA8D5510A8C1D;
// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Leaderboard>
struct MessageArray_1_tF4173B1C53148BB935C764587034896F121CCA0A;
// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.LeaderboardEntry>
struct MessageArray_1_tB8E04BD481F9ACE36C3AC7750EC6E3168CF6ED31;
// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.MatchmakingAdminSnapshotCandidate>
struct MessageArray_1_tE23B1EF897AC360EF5B5030E9C24FB894F1930F1;
// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.MatchmakingRoom>
struct MessageArray_1_t8EC5BA1648CB587D9A9B26B0134F98287F69DB97;
// Pico.Platform.Models.MessageArray`1<System.Object>
struct MessageArray_1_t1751A681AAC7438BEA74C4EC6F2FE5EF88CBEEE5;
// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Product>
struct MessageArray_1_tC6F5900777FE83D0B145BC0F27D11D16A33673A0;
// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Purchase>
struct MessageArray_1_t05AA39A5AA11CCE42EA326113EC8CB01D26F8E92;
// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Room>
struct MessageArray_1_t13175CA17EF1C58A6CE16C1C5CC33E66B189C0DB;
// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.RoomInviteNotification>
struct MessageArray_1_t48F2634F7CE492870D7F60BCDB4ECBAEABA4E185;
// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.SportDailySummary>
struct MessageArray_1_t50FAA95B2043C09E0B1018F924FCDEAD40EDFE38;
// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.User>
struct MessageArray_1_t3FBFD71C2ED89BC1E98F61EFDB0C5C6DADE06A17;
// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.UserRoom>
struct MessageArray_1_tBDB39162E4555FCBD64BB106117908AC8831F004;
// Pico.Platform.Message`1<Pico.Platform.Models.AsrResult>
struct Message_1_t691396D32AD137434599EDC37E2A709FD643BE84;
// Pico.Platform.Message`1<System.Int32>
struct Message_1_t8EB1CC5139379A0C8CE73C2A114E15A5C7202F84;
// Pico.Platform.Message`1<Pico.Platform.Models.PermissionResult>
struct Message_1_t457063293F5E86604105C51764B8EB632AA81945;
// Pico.Platform.Message`1<Pico.Platform.PlatformInitializeResult>
struct Message_1_t58D0E25C5F7D6B97F64C48CFE6DA11BE5D1A3EF1;
// Pico.Platform.Message`1<Pico.Platform.RtcAudioPlaybackDevice>
struct Message_1_tD3F011B9505742725EF147CE96661B2BAE2DED41;
// Pico.Platform.Message`1<Pico.Platform.Models.RtcBinaryMessageReceived>
struct Message_1_t13C112DCC65803696FEB8BDE3FA2C38D335A5BE4;
// Pico.Platform.Message`1<Pico.Platform.RtcConnectionState>
struct Message_1_t6F67AF9483664BE8CA4981F3D000D2978F89EB46;
// Pico.Platform.Message`1<Pico.Platform.Models.RtcJoinRoomResult>
struct Message_1_t1A6CDBB41CA0FBFE74E92C5C5D20DE86D041324B;
// Pico.Platform.Message`1<Pico.Platform.Models.RtcLeaveRoomResult>
struct Message_1_t1EA3C8D6E4D67FEA93CC7224DD5AD0B6CAB5D6FD;
// Pico.Platform.Message`1<Pico.Platform.Models.RtcLocalAudioPropertiesReport>
struct Message_1_tCFF2399AAA1DAF5EAAF6408A1E5F76D5D32AA25E;
// Pico.Platform.Message`1<Pico.Platform.Models.RtcMessageSendResult>
struct Message_1_t8A12AF93D7598B8E0E2DC7A037B6C8EDCA558175;
// Pico.Platform.Message`1<Pico.Platform.Models.RtcMuteInfo>
struct Message_1_t379E7F364AD30DFC45F9D6ED7A73D032C9AD3659;
// Pico.Platform.Message`1<Pico.Platform.Models.RtcRemoteAudioPropertiesReport>
struct Message_1_t8E0A65B55DE25F98592950EEA045E176459893FD;
// Pico.Platform.Message`1<Pico.Platform.Models.RtcRoomError>
struct Message_1_t50A77FEF54018D1AF31362C0293FC4D2F380F1C0;
// Pico.Platform.Message`1<Pico.Platform.Models.RtcRoomMessageReceived>
struct Message_1_t442F7E93957E30817786F19BCD3048B62E2D09C7;
// Pico.Platform.Message`1<Pico.Platform.Models.RtcRoomStats>
struct Message_1_t230C3849643B857EB38AC9172EA2255B042CB904;
// Pico.Platform.Message`1<Pico.Platform.Models.RtcRoomWarn>
struct Message_1_t2C531B2C37BCBF40D59CE68FE4576E72DF4DFE22;
// Pico.Platform.Message`1<Pico.Platform.Models.RtcStreamSyncInfo>
struct Message_1_t42B3B059FF02B4ED663811E6AC9D55447A24FE6A;
// Pico.Platform.Message`1<Pico.Platform.Models.RtcUserJoinInfo>
struct Message_1_t3A7DA7ABAF513A374E2A856D49C8CB5780B9E7A8;
// Pico.Platform.Message`1<Pico.Platform.Models.RtcUserLeaveInfo>
struct Message_1_t7F93EEE9D712CEC3EB313FA13DCF9B24B9C8CB32;
// Pico.Platform.Message`1<Pico.Platform.Models.RtcUserMessageReceived>
struct Message_1_t6FCF2A7681B018AB0EDA9A47AB98FF61E42FDDD1;
// Pico.Platform.Message`1<Pico.Platform.Models.RtcUserPublishInfo>
struct Message_1_tDF8E478FBF5AA63CB491DB7269E911BD3AA98E09;
// Pico.Platform.Message`1<Pico.Platform.Models.RtcUserUnPublishInfo>
struct Message_1_t16EF7D6D99F7030AD1B5F6FF7F7029192ACD7983;
// Pico.Platform.Message`1<Pico.Platform.Models.SpeechError>
struct Message_1_tE20F300AB51A842963A27A575438121DFF5B0D9C;
// Pico.Platform.Message`1<System.String>
struct Message_1_t533D45A5AD889BDDA9FE96440D1E886151533D70;
// Pico.Platform.Message`1<Pico.Platform.Models.User>
struct Message_1_tE6876B2F0C46A93682EA4E2DD435A5D3F37E73C2;
// Pico.Platform.Task`1<Pico.Platform.Models.EntitlementCheckResult>
struct Task_1_t6577C6759208FE196021557BB439FE81946FDB36;
// Pico.Platform.Task`1<System.Int32Enum>
struct Task_1_t38E2E7C305FFAA88BB7CA2F3E338181D20C3768D;
// Pico.Platform.Task`1<Pico.Platform.Models.LaunchFriendResult>
struct Task_1_t89353573F66DF40A563FFC7023237C238E5D7F0D;
// Pico.Platform.Task`1<System.Object>
struct Task_1_t7A1D919E5E4E10281920DFF788F966BD9DDF4DD2;
// Pico.Platform.Task`1<Pico.Platform.Models.OrgScopedID>
struct Task_1_tED4A061EA242D6FF39FF61442A0E7F55A6880B2E;
// Pico.Platform.Task`1<Pico.Platform.Models.PermissionResult>
struct Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF;
// Pico.Platform.Task`1<Pico.Platform.PlatformInitializeResult>
struct Task_1_t733E89BDEF2E1BD0B822AE037A0F380656723ACE;
// Pico.Platform.Task`1<Pico.Platform.Models.SportDailySummaryList>
struct Task_1_t1B98E66164E4AE432D604C7B75AF7848981FF051;
// Pico.Platform.Task`1<Pico.Platform.Models.SportSummary>
struct Task_1_tB6CDA113D3E1699F4874976AC36FB7624B4F9244;
// Pico.Platform.Task`1<Pico.Platform.Models.SportUserInfo>
struct Task_1_t1B92E95AEAE34C4D979EA9DC46E4A0B69313B747;
// Pico.Platform.Task`1<System.String>
struct Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF;
// Pico.Platform.Task`1<Pico.Platform.Models.User>
struct Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42;
// Pico.Platform.Task`1<Pico.Platform.Models.UserList>
struct Task_1_tEFD858E38F809577D01E5C61C4E04401C1579F24;
// Pico.Platform.Task`1<Pico.Platform.Models.UserRelationResult>
struct Task_1_tB4B0FA80F5FD7ED902B09091C88E2146F2BAE9C1;
// Pico.Platform.Task`1<Pico.Platform.Models.UserRoomList>
struct Task_1_t63D243DB7237B9BDC42B877FB86F30ABDF4C37EF;
// UnityEngine.UI.CoroutineTween.TweenRunner`1<UnityEngine.UI.CoroutineTween.ColorTween>
struct TweenRunner_1_t5BB0582F926E75E2FE795492679A6CF55A4B4BC4;
// System.Collections.Generic.Dictionary`2/ValueCollection<Pico.Platform.RtcPrivilege,System.Int32>
struct ValueCollection_tA371BC51BC2CC0CDE0AC89FE7437A896E1AB7A0D;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.String,System.String>
struct ValueCollection_t238D0D2427C6B841A01F522A41540165A2C4AE76;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.String,Pico.Platform.UserRelationType>
struct ValueCollection_t2E5EC2FBD6E6D03DDE2D65650C2A1B69CED77E21;
// System.Collections.Generic.Dictionary`2/Entry<Pico.Platform.RtcPrivilege,System.Int32>[]
struct EntryU5BU5D_t38553BE78159FA6CCBEDA290331AC5134E82AE89;
// System.Collections.Generic.Dictionary`2/Entry<System.String,System.String>[]
struct EntryU5BU5D_t1AF33AD0B7330843448956EC4277517081658AE7;
// System.Collections.Generic.Dictionary`2/Entry<System.String,Pico.Platform.UserRelationType>[]
struct EntryU5BU5D_tFC7C5DDFE53BD8FD0DACAFCE15AE61448033DF56;
// Pico.Platform.Models.AchievementDefinition[]
struct AchievementDefinitionU5BU5D_tD45280A798177E339C7F71BEA08B42FBC1324806;
// Pico.Platform.Models.AchievementProgress[]
struct AchievementProgressU5BU5D_t116D1223032641932BDB37219A7C0EEE9628107A;
// Pico.Platform.Models.ApplicationInvite[]
struct ApplicationInviteU5BU5D_tFEC3D38D47E91DA4E4859DF99DFA649C726B8B1D;
// Pico.Platform.Models.AssetDetails[]
struct AssetDetailsU5BU5D_tDFD25B55AA42A540A7F1AE1B0DFB4F4A99E607A9;
// System.Byte[]
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
// Pico.Platform.Models.CaptureInfo[]
struct CaptureInfoU5BU5D_tFA6FAA7D7AE3BBB1688FD52AE43DE5032184993E;
// Pico.Platform.Models.Challenge[]
struct ChallengeU5BU5D_tD70C30ED4DDCC167BFB807A20076D422DD522DFC;
// Pico.Platform.Models.ChallengeEntry[]
struct ChallengeEntryU5BU5D_t01DC002B76F7F4CE1070F74F8475CFE177A1AB72;
// System.Char[]
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
// System.Delegate[]
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
// Pico.Platform.Models.Destination[]
struct DestinationU5BU5D_t8A295AD29D924C3496379E613BF75381A9812A14;
// System.Int32[]
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
// System.IntPtr[]
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
// Pico.Platform.Models.Leaderboard[]
struct LeaderboardU5BU5D_t228A8CBD32C5E10AAC389ABCF0A9188B66E287D4;
// Pico.Platform.Models.LeaderboardEntry[]
struct LeaderboardEntryU5BU5D_t1E730BC8E35CD591F53C791F553A7BDB7D7B9F7A;
// Pico.Platform.Models.MatchmakingAdminSnapshotCandidate[]
struct MatchmakingAdminSnapshotCandidateU5BU5D_t7472DB57A6C6C52E8EEF83AD0B13B118AA683DF5;
// Pico.Platform.Models.MatchmakingRoom[]
struct MatchmakingRoomU5BU5D_t15CBD754E9AA79A2D96C20A2B446F16C0052AC74;
// System.Object[]
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
// Pico.Platform.Models.Product[]
struct ProductU5BU5D_tE4833FDC634EF457AA9978D99883A22B899D0CD5;
// Pico.Platform.Models.Purchase[]
struct PurchaseU5BU5D_t2470799E07346B5DDC326FD66E807F8D3509FA46;
// Pico.Platform.Models.RecordInfo[]
struct RecordInfoU5BU5D_t1505D0DB4C486883C741B73244F4130B5AF19854;
// Pico.Platform.Models.Room[]
struct RoomU5BU5D_t65395623B3E4D69C7430C314A2AB8B6E2B0ACA79;
// Pico.Platform.Models.RoomInviteNotification[]
struct RoomInviteNotificationU5BU5D_t9975E8DA69A572BB6D35A08EB32D43FEE31CEAA2;
// Pico.Platform.Models.RtcLocalAudioPropertiesInfo[]
struct RtcLocalAudioPropertiesInfoU5BU5D_tECCE986B1F5EE0EA71E955DE541538066669D2C7;
// Pico.Platform.Models.RtcRemoteAudioPropertiesInfo[]
struct RtcRemoteAudioPropertiesInfoU5BU5D_t4DD6EF874C9C2844E1101DAE658C91D04DC92952;
// Pico.Platform.Models.SportDailySummary[]
struct SportDailySummaryU5BU5D_t73B931C0CDA0A57B1620B8E2198C6DFA768953AB;
// System.Diagnostics.StackTrace[]
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
// System.String[]
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
// UnityEngine.UIVertex[]
struct UIVertexU5BU5D_tBC532486B45D071A520751A90E819C77BA4E3D2F;
// Pico.Platform.Models.User[]
struct UserU5BU5D_t837772AE1B0DAAE3734C4D1A50D2C00923A3D4DF;
// Pico.Platform.Models.UserRoom[]
struct UserRoomU5BU5D_t6CA1BBB733313CD8E3B344CD94E1666653050D24;
// UnityEngine.Vector2[]
struct Vector2U5BU5D_tFEBBC94BCC6C9C88277BA04047D2B3FDB6ED7FDA;
// UnityEngine.Vector3[]
struct Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C;
// Pico.Platform.Models.AchievementDefinition
struct AchievementDefinition_t09D5E334A9AF0321426DB09B4B36E72626423019;
// Pico.Platform.Models.AchievementDefinitionList
struct AchievementDefinitionList_t8C4BD92DEDBC06F39E7584124E90000B86B41744;
// Pico.Platform.Models.AchievementProgress
struct AchievementProgress_t1E252101294D86D61BE435D76B192BE5E85F67DB;
// Pico.Platform.Models.AchievementProgressList
struct AchievementProgressList_t5C10551DC794BBA8F5FF05832B2D044B40447504;
// Pico.Platform.Models.AchievementUpdate
struct AchievementUpdate_t41C493D095A1BB1BFC2C4BB0A17696AB038C8474;
// Pico.Platform.Models.ApplicationInvite
struct ApplicationInvite_t95D2E15775E4CD15D060CDF6CF25EDB854EB67D7;
// Pico.Platform.Models.ApplicationInviteList
struct ApplicationInviteList_tCFA701E5249821E8B9BBFD13F595859AFFAB19DB;
// Pico.Platform.Models.ApplicationVersion
struct ApplicationVersion_t62CE03D7C8FBF594FDE1979E76974E0E3E707156;
// System.ArgumentException
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263;
// Pico.Platform.Models.AsrResult
struct AsrResult_t004816647ADC1F06A8D0AE66C355906FB022BEA5;
// Pico.Platform.Models.AssetDetails
struct AssetDetails_t8F8B8199F92068253768AABE9EB4314FFB926AE2;
// Pico.Platform.Models.AssetDetailsList
struct AssetDetailsList_tB4AE1D412F214C001FEA90572C4244B92F4CF797;
// Pico.Platform.Models.AssetFileDeleteForSafety
struct AssetFileDeleteForSafety_tE0658EB374DF5E9FFEB4D95D7CF5CDBA40E8EABA;
// Pico.Platform.Models.AssetFileDeleteResult
struct AssetFileDeleteResult_t69B9AFEF34255AED9E99D39461203AD4310CC434;
// Pico.Platform.Models.AssetFileDownloadCancelResult
struct AssetFileDownloadCancelResult_t3DBDC2912716D7BF23B8B8C7CC417C90AD405B43;
// Pico.Platform.Models.AssetFileDownloadResult
struct AssetFileDownloadResult_tD0B1698C03580D6A8A9CD407B09D147D0F02F639;
// Pico.Platform.Models.AssetFileDownloadUpdate
struct AssetFileDownloadUpdate_tBAD90D69A25568EC45F334942C219ABFBD5DA6E2;
// Pico.Platform.Models.AssetStatus
struct AssetStatus_t1D527E1B3D8881BD413FE56B7E928774704F8206;
// System.AsyncCallback
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C;
// UnityEngine.Canvas
struct Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26;
// UnityEngine.CanvasRenderer
struct CanvasRenderer_tAB9A55A976C4E3B2B37D0CE5616E5685A8B43860;
// Pico.Platform.Models.CaptureInfo
struct CaptureInfo_t522928357E5822ACBC5FC59A060BDBABFF3DF575;
// UnityEngine.Networking.CertificateHandler
struct CertificateHandler_t148B524FA5DB39F3ABADB181CD420FC505C33804;
// Pico.Platform.Models.Challenge
struct Challenge_t4D4126711B52D78CEDA93B79EC0EFF69927E3971;
// Pico.Platform.Models.ChallengeEntry
struct ChallengeEntry_t16F06D309BE271B368F93F4F66001E1270B6EEAB;
// Pico.Platform.Models.ChallengeEntryList
struct ChallengeEntryList_tF2741C9A3F98553DC191BB26844528DC5525BB87;
// Pico.Platform.Models.ChallengeList
struct ChallengeList_t46D99E7063774C36EF661DC3875AADDFC03E12D2;
// Pico.Platform.Models.ChallengeOptions
struct ChallengeOptions_t9A8A307A2A43C1E1022510A14E02515DF5191DD8;
// System.Globalization.CodePageDataItem
struct CodePageDataItem_t52460FA30AE37F4F26ACB81055E58002262F19F2;
// UnityEngine.Component
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3;
// UnityEngine.Coroutine
struct Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B;
// System.Text.DecoderFallback
struct DecoderFallback_t7324102215E4ED41EC065C02EB501CB0BC23CD90;
// System.Delegate
struct Delegate_t;
// System.DelegateData
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
// Pico.Platform.Models.Destination
struct Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211;
// Pico.Platform.Models.DestinationList
struct DestinationList_t41BB93309FA194DCC59A75DF41CE7FE6FC8E08EF;
// Pico.Platform.Models.DetectSensitiveResult
struct DetectSensitiveResult_t3F811A4C213815D1A2E488BCC02B4F0927C06381;
// UnityEngine.Networking.DownloadHandler
struct DownloadHandler_t1B56C7D3F65D97A1E4B566A14A1E783EA8AE4EBB;
// UnityEngine.Networking.DownloadHandlerTexture
struct DownloadHandlerTexture_t45E2D719000AA1594E648810F0B57A77FA7C568C;
// System.Text.EncoderFallback
struct EncoderFallback_tD2C40CE114AA9D8E1F7196608B2D088548015293;
// System.Text.Encoding
struct Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095;
// Pico.Platform.Models.EntitlementCheckResult
struct EntitlementCheckResult_tDCC132CD30FB7907CB5575B3C629531914BCD061;
// Pico.Platform.Models.Error
struct Error_t3CA63648FA025A8FBA63EA102526BE2F757CAF88;
// UnityEngine.UI.FontData
struct FontData_tB8E562846C6CB59C43260F69AE346B9BF3157224;
// UnityEngine.GameObject
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F;
// System.IAsyncResult
struct IAsyncResult_t7B9B5A0ECB35DCEC31B8A8122C37D687369253B5;
// System.Collections.IDictionary
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
// System.Collections.IEnumerator
struct IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA;
// Pico.Platform.Models.KVPair
struct KVPair_t3B78D7F4C5A144597A4D25D3E998B119380117F0;
// Pico.Platform.Models.KVPairArray
struct KVPairArray_t2D18141BDF81CCF74F01AD0CD6D940BFF0D65E1F;
// Pico.Platform.Models.LaunchDetails
struct LaunchDetails_t83DFB7E65E221A238FA66531C7C470C75FFACE21;
// Pico.Platform.Models.LaunchFriendResult
struct LaunchFriendResult_tE14F761B20423DF2AA66723EEB659CEA351551A1;
// Pico.Platform.Models.Leaderboard
struct Leaderboard_t6D83DEF000B68074D583D0D92AED4AE1EFB14595;
// Pico.Platform.Models.LeaderboardEntry
struct LeaderboardEntry_tDFA599CDDC7EC20F2041B9BCF885BAE5A8B7DF9F;
// Pico.Platform.Models.LeaderboardEntryList
struct LeaderboardEntryList_t6B5536586844053D032CB41222DC969C7FC0DC8D;
// Pico.Platform.Models.LeaderboardList
struct LeaderboardList_t8BED638069122AD476155B80846591364CB07B06;
// Pico.Platform.Models.MatchmakingAdminSnapshot
struct MatchmakingAdminSnapshot_tF75B3A1A51D503587990BECC068C30E7671EE451;
// Pico.Platform.Models.MatchmakingAdminSnapshotCandidate
struct MatchmakingAdminSnapshotCandidate_t2325F5337C73FF55AB6D932F2A14C97E3A813CCC;
// Pico.Platform.Models.MatchmakingAdminSnapshotCandidateList
struct MatchmakingAdminSnapshotCandidateList_tCB8BE369951F7307CA9A1AF9C7FE4B6253339C94;
// Pico.Platform.Models.MatchmakingBrowseResult
struct MatchmakingBrowseResult_tC20A58B18DE8FF7F9A4E7450063ACB8FC38D2C58;
// Pico.Platform.Models.MatchmakingEnqueueResult
struct MatchmakingEnqueueResult_t620CF96FB5A92A1783E9882E651C0CA76E2E3D8D;
// Pico.Platform.Models.MatchmakingEnqueueResultAndRoom
struct MatchmakingEnqueueResultAndRoom_t01215772818E3385FC96DCE8D46E9906FCA8D9FC;
// Pico.Platform.Models.MatchmakingRoom
struct MatchmakingRoom_t564ECF1B3DF437F6B3DE5EC03A5E173193CE6C74;
// Pico.Platform.Models.MatchmakingRoomList
struct MatchmakingRoomList_t97325021F617542B368184443F745CC637C866B7;
// Pico.Platform.Models.MatchmakingStats
struct MatchmakingStats_tA7354632354901085E56D8553EF6B4A584424184;
// UnityEngine.Material
struct Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3;
// UnityEngine.Mesh
struct Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4;
// Pico.Platform.Message
struct Message_t2DF6F94E79BCFC7D36B4D1219F09D5DF8D241F83;
// System.Reflection.MethodInfo
struct MethodInfo_t;
// UnityEngine.MonoBehaviour
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71;
// System.NotSupportedException
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A;
// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C;
// Pico.Platform.Models.OrgScopedID
struct OrgScopedID_tE7AFDD1678D708DC9371763230892D40F965A581;
// Pico.Platform.Models.Packet
struct Packet_tE7ABCB3CA16D45A82E180266269EC1B89F8054A9;
// Pico.Platform.Models.PermissionResult
struct PermissionResult_t235EBFBF617C649652D95D6EEB96D6C1E66EE3CF;
// Pico.Platform.Models.PresenceJoinIntent
struct PresenceJoinIntent_t708F6CB20BA715DA328B67F38BFD1376DF6364D3;
// Pico.Platform.Models.Product
struct Product_t1507FCF7293FA1250C325F33FEA9C46DBD487D66;
// Pico.Platform.Models.ProductList
struct ProductList_t60557078ACE42730D11C630A551C5ECF6DD48160;
// Pico.Platform.PtrManager
struct PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2;
// Pico.Platform.Models.Purchase
struct Purchase_t4EB26AC15A7E0936D3E6722DA01B1DF84A3D469A;
// Pico.Platform.Models.PurchaseList
struct PurchaseList_tE73ABD4A2D17ED67A2A410C78B54519A32A16C03;
// UnityEngine.UI.RawImage
struct RawImage_tFF12F7DB574FBDC1863CF607C7A12A5D9F8D6179;
// Pico.Platform.Models.RecordInfo
struct RecordInfo_t391FC28285898D9D06E379287A88F5A4BA4A6019;
// UnityEngine.UI.RectMask2D
struct RectMask2D_tACF92BE999C791A665BD1ADEABF5BCEB82846670;
// UnityEngine.RectTransform
struct RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5;
// UnityEngine.Renderer
struct Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF;
// Pico.Platform.Models.Room
struct Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135;
// Pico.Platform.Models.RoomInviteNotification
struct RoomInviteNotification_t056C5D7720D5A52379CEB33A2BEB26EDB399E048;
// Pico.Platform.Models.RoomInviteNotificationList
struct RoomInviteNotificationList_t1203312F5F6E7E53899A09886C7716CD0C55D9A6;
// Pico.Platform.Models.RoomList
struct RoomList_t3B275914D4B281B7FAB5C1AD597F11D664367694;
// Pico.Platform.RoomOptions
struct RoomOptions_tC6C155D94F2675BA84336CA56BCDEBEA022835B7;
// Pico.Platform.Models.RtcAudioFrame
struct RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59;
// Pico.Platform.Models.RtcAudioPropertyInfo
struct RtcAudioPropertyInfo_tA10BA2C71B943D7A31ED99324B58ECBC13C05268;
// Pico.Platform.RtcAudioPropertyOptions
struct RtcAudioPropertyOptions_t5E394E488DDCF996DB82E9326E71B465A4D6D23E;
// Pico.Platform.Models.RtcBinaryMessageReceived
struct RtcBinaryMessageReceived_t27A81B34E30B69FD73D308AEBB3C92201FA00FB2;
// Pico.Platform.RtcGetTokenOptions
struct RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0;
// Pico.Platform.Models.RtcJoinRoomResult
struct RtcJoinRoomResult_t7B3739D043DA3F0754EA07F27CC81279A5673D3C;
// Pico.Platform.Models.RtcLeaveRoomResult
struct RtcLeaveRoomResult_t7FC19B99E6788124464A77D25421776CB62301FF;
// Pico.Platform.Models.RtcLocalAudioPropertiesInfo
struct RtcLocalAudioPropertiesInfo_tDEE2268599EA8C3EC747871F690C5743321ED49E;
// Pico.Platform.Models.RtcLocalAudioPropertiesReport
struct RtcLocalAudioPropertiesReport_t0AA9BC3CF8E0B67661E0CF11B68EBEE27C9D9E7D;
// Pico.Platform.Models.RtcMediaDeviceChangeInfo
struct RtcMediaDeviceChangeInfo_tB2715659230514BAEF53E2329D648EC92B790850;
// Pico.Platform.Models.RtcMessageSendResult
struct RtcMessageSendResult_t175C63F675CA721C614F552DAED8AD5CDD8D19D9;
// Pico.Platform.Models.RtcMuteInfo
struct RtcMuteInfo_t42EFA88A13E9A461000A46AEE9B3BD8017AC5416;
// Pico.Platform.Models.RtcRemoteAudioPropertiesInfo
struct RtcRemoteAudioPropertiesInfo_t756C00636961DE878EE3D2DAD934F01DC0DE3C06;
// Pico.Platform.Models.RtcRemoteAudioPropertiesReport
struct RtcRemoteAudioPropertiesReport_t575A87A1EE3387315239DA4AF54DAA70B4E5EB78;
// Pico.Platform.Models.RtcRemoteStreamKey
struct RtcRemoteStreamKey_tA69532F8EF7C977014612F775D146C3038C61E0E;
// Pico.Platform.Models.RtcRoomError
struct RtcRoomError_t9E2842355A967FB7C0C5170BBAE107B299384383;
// Pico.Platform.Models.RtcRoomMessageReceived
struct RtcRoomMessageReceived_t2BDF5904A9D3EEF6D72D964485D208779637F7DD;
// Pico.Platform.RtcRoomOptions
struct RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A;
// Pico.Platform.Models.RtcRoomStats
struct RtcRoomStats_t82FFF1123D5D67FC8D0027DD78C0BCD933C419CE;
// Pico.Platform.Models.RtcRoomWarn
struct RtcRoomWarn_t606796009EEE6543FEC76C7457FB6F8156C06BD4;
// Pico.Platform.Models.RtcStreamSyncInfo
struct RtcStreamSyncInfo_tDF6615A963654FDED33B6E427CC2377459A814C8;
// Pico.Platform.RtcStreamSyncInfoOptions
struct RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073;
// Pico.Platform.Models.RtcUserJoinInfo
struct RtcUserJoinInfo_t2B639AA4EA2CEC3216FF167FA01780A3F6B7B747;
// Pico.Platform.Models.RtcUserLeaveInfo
struct RtcUserLeaveInfo_tC24C9CCF5AEE733D5431F5C973C813C2C36C54FE;
// Pico.Platform.Models.RtcUserMessageReceived
struct RtcUserMessageReceived_t156E2473096464ECCB4B298A7644E6C572A6292E;
// Pico.Platform.Models.RtcUserPublishInfo
struct RtcUserPublishInfo_t8873B6131F1DFF54983FEA638F386647C53ABE2F;
// Pico.Platform.Models.RtcUserUnPublishInfo
struct RtcUserUnPublishInfo_tF48236E711888E683F08D6FC0716FE12A582E99A;
// Pico.Platform.Framework.Runner
struct Runner_tB8E78BC8FEC1129C330C7EF44FE5BBFC57BFB7B8;
// System.Runtime.Serialization.SafeSerializationManager
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
// Pico.Platform.Models.SendInvitesResult
struct SendInvitesResult_tF1FCB62C7DDA973DC7DDE54DC9DEEF5FC77B8B57;
// Pico.Platform.Models.SessionMedia
struct SessionMedia_tCFC23B02299EDBE3E3749B48286C4CD403C89A07;
// Pico.Platform.Samples.SimpleDemo
struct SimpleDemo_tB73BB92662E2E45C09FAD8C176DC8690E0FD4195;
// Pico.Platform.Models.SpeechError
struct SpeechError_t370B79F899E733FECFC5D12BFA22AB0E146C96FB;
// Pico.Platform.SpeechService
struct SpeechService_t4136B8573DC4D69E06013EC67BCD1E4052C18EE9;
// Pico.Platform.Models.SportDailySummary
struct SportDailySummary_t1202315FC8419F0C908ACF448A0DF4EF207756F0;
// Pico.Platform.Models.SportDailySummaryList
struct SportDailySummaryList_tDB9E5A80ED100417F113C33891F04F9CF8DB5BC6;
// Pico.Platform.Models.SportSummary
struct SportSummary_t6193CC64BC93B9813F42F50B37479017FB3067D1;
// Pico.Platform.Models.SportUserInfo
struct SportUserInfo_tFA26719517B940DC321942A68AE48D23AFAE5D78;
// Pico.Platform.StartAsrOptions
struct StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F;
// System.String
struct String_t;
// Pico.Platform.Models.SubscriptionStatus
struct SubscriptionStatus_tB2999CB0297F3E98A32D66E36872B688BD5ABA17;
// Pico.Platform.Models.SupplementaryMetric
struct SupplementaryMetric_t28C1258D6CB519A099746C713C51A1F14C2C242A;
// Pico.Platform.Models.SystemInfo
struct SystemInfo_t53AF5429861C13B1769EA33EAA762275B333CCA0;
// UnityEngine.UI.Text
struct Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62;
// UnityEngine.TextGenerator
struct TextGenerator_t85D00417640A53953556C01F9D4E7DDE1ABD8FEC;
// UnityEngine.Texture
struct Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700;
// UnityEngine.Texture2D
struct Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4;
// UnityEngine.Events.UnityAction
struct UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7;
// UnityEngine.Networking.UnityWebRequest
struct UnityWebRequest_t6233B8E22992FC2364A831C1ACB033EF3260C39F;
// UnityEngine.Networking.UnityWebRequestAsyncOperation
struct UnityWebRequestAsyncOperation_t14BE94558FF3A2CFC2EFBE2511A3A88252042B8C;
// UnityEngine.Networking.UploadHandler
struct UploadHandler_t7E504B1A83346248A0C8C4AF73A893226CB83EF6;
// System.Uri
struct Uri_t1500A52B5F71A04F5D05C0852D0F2A0941842A0E;
// Pico.Platform.Models.User
struct User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4;
// Pico.Platform.Models.UserList
struct UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F;
// Pico.Platform.Models.UserRelationResult
struct UserRelationResult_t4C1646A5BAF0830D84E5A417EAB9BD502A1ACD3D;
// Pico.Platform.Models.UserRoom
struct UserRoom_t4A96B7A9523274CA1C6722C4E90D12991C3B11DB;
// Pico.Platform.Models.UserRoomList
struct UserRoomList_t4AA0685A4D566E046B275555AC21E1A102C16A73;
// UnityEngine.UI.VertexHelper
struct VertexHelper_tB905FCB02AE67CBEE5F265FE37A5938FC5D136FE;
// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
// Pico.Platform.CLIB/RtcProcessAudioFrameFunction
struct RtcProcessAudioFrameFunction_t91998EE2CD7760356A3A9E75620AEB591C1F2344;
// UnityEngine.UI.MaskableGraphic/CullStateChangedEvent
struct CullStateChangedEvent_t6073CD0D951EC1256BF74B8F9107D68FC89B99B8;
// Pico.Platform.RtcService/ProcessAudioFrameFunction
struct ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5;
// Pico.Platform.Samples.SimpleDemo/<DownloadImage>d__7
struct U3CDownloadImageU3Ed__7_t12CD4C58AE44E71AC9B06FF3969E6AD7057D8367;

IL2CPP_EXTERN_C RuntimeClass* AchievementDefinition_t09D5E334A9AF0321426DB09B4B36E72626423019_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* AchievementProgress_t1E252101294D86D61BE435D76B192BE5E85F67DB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ApplicationInviteList_tCFA701E5249821E8B9BBFD13F595859AFFAB19DB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ApplicationInvite_t95D2E15775E4CD15D060CDF6CF25EDB854EB67D7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* AssetDetails_t8F8B8199F92068253768AABE9EB4314FFB926AE2_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* CaptureInfoU5BU5D_tFA6FAA7D7AE3BBB1688FD52AE43DE5032184993E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* CaptureInfo_t522928357E5822ACBC5FC59A060BDBABFF3DF575_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ChallengeEntry_t16F06D309BE271B368F93F4F66001E1270B6EEAB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Challenge_t4D4126711B52D78CEDA93B79EC0EFF69927E3971_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Convert_t7097FF336D592F7C06D88A98349A44646F91EFFC_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* DownloadHandlerTexture_t45E2D719000AA1594E648810F0B57A77FA7C568C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Exception_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GC_t920F9CF6EBB7C787E5010A4352E1B587F356DC58_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Handler_t3014C5064A71B62349A0B6C599C034BA36D6E17E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Handler_t514BEA54A8C9B5734E3D678B336DDA196A366022_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Handler_tF65149A494CDA59437FE06A5E974BDECEB45C2B3_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IntPtr_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* KVPair_t3B78D7F4C5A144597A4D25D3E998B119380117F0_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* LeaderboardEntry_tDFA599CDDC7EC20F2041B9BCF885BAE5A8B7DF9F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Leaderboard_t6D83DEF000B68074D583D0D92AED4AE1EFB14595_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* MatchmakingAdminSnapshotCandidateList_tCB8BE369951F7307CA9A1AF9C7FE4B6253339C94_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* MatchmakingAdminSnapshotCandidate_t2325F5337C73FF55AB6D932F2A14C97E3A813CCC_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* MatchmakingAdminSnapshot_tF75B3A1A51D503587990BECC068C30E7671EE451_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* MatchmakingEnqueueResult_t620CF96FB5A92A1783E9882E651C0CA76E2E3D8D_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* MatchmakingRoomList_t97325021F617542B368184443F745CC637C866B7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* MatchmakingRoom_t564ECF1B3DF437F6B3DE5EC03A5E173193CE6C74_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* PlatformInitializeResult_t24F044FE2324F44AF83DB194C1051EC41F6586C5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Product_t1507FCF7293FA1250C325F33FEA9C46DBD487D66_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Purchase_t4EB26AC15A7E0936D3E6722DA01B1DF84A3D469A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RecordInfoU5BU5D_t1505D0DB4C486883C741B73244F4130B5AF19854_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RecordInfo_t391FC28285898D9D06E379287A88F5A4BA4A6019_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RoomInviteNotification_t056C5D7720D5A52379CEB33A2BEB26EDB399E048_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RtcAudioPropertyInfo_tA10BA2C71B943D7A31ED99324B58ECBC13C05268_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RtcAudioPropertyOptions_t5E394E488DDCF996DB82E9326E71B465A4D6D23E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RtcLocalAudioPropertiesInfoU5BU5D_tECCE986B1F5EE0EA71E955DE541538066669D2C7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RtcLocalAudioPropertiesInfo_tDEE2268599EA8C3EC747871F690C5743321ED49E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RtcProcessAudioFrameFunction_t91998EE2CD7760356A3A9E75620AEB591C1F2344_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RtcRemoteAudioPropertiesInfoU5BU5D_t4DD6EF874C9C2844E1101DAE658C91D04DC92952_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RtcRemoteAudioPropertiesInfo_t756C00636961DE878EE3D2DAD934F01DC0DE3C06_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RtcRemoteStreamKey_tA69532F8EF7C977014612F775D146C3038C61E0E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RtcService_t22C275834C979544290EE8B61C467477647BD1BF_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SportDailySummary_t1202315FC8419F0C908ACF448A0DF4EF207756F0_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* String_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SupplementaryMetric_t28C1258D6CB519A099746C713C51A1F14C2C242A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Task_1_t1B92E95AEAE34C4D979EA9DC46E4A0B69313B747_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Task_1_t1B98E66164E4AE432D604C7B75AF7848981FF051_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Task_1_t63D243DB7237B9BDC42B877FB86F30ABDF4C37EF_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Task_1_t6577C6759208FE196021557BB439FE81946FDB36_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Task_1_t89353573F66DF40A563FFC7023237C238E5D7F0D_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Task_1_tB4B0FA80F5FD7ED902B09091C88E2146F2BAE9C1_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Task_1_tB6CDA113D3E1699F4874976AC36FB7624B4F9244_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Task_1_tED4A061EA242D6FF39FF61442A0E7F55A6880B2E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Task_1_tEFD858E38F809577D01E5C61C4E04401C1579F24_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CDownloadImageU3Ed__7_t12CD4C58AE44E71AC9B06FF3969E6AD7057D8367_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UIntPtr_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UnityException_tA1EC1E95ADE689CF6EB7FAFF77C160AE1F559067_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UserRoom_t4A96B7A9523274CA1C6722C4E90D12991C3B11DB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral117F539165B45A5AC4BAAE9D28D7843EC5548C9E;
IL2CPP_EXTERN_C String_t* _stringLiteral156065397842C897754F95F8B45CD763A37AA319;
IL2CPP_EXTERN_C String_t* _stringLiteral17F876F233361D29F71A2CA748E8C6128A4464BE;
IL2CPP_EXTERN_C String_t* _stringLiteral2756C3F879AF25F2833BF607BB657D6246B88DF3;
IL2CPP_EXTERN_C String_t* _stringLiteral399A0FC4CB5C00718DE77B8FB9DE3E6A8C8B50BE;
IL2CPP_EXTERN_C String_t* _stringLiteral4092B25B116FA20453318CF2C73A263E43DCD2AB;
IL2CPP_EXTERN_C String_t* _stringLiteral4711236842612E0241200A841882573A4D49C0D3;
IL2CPP_EXTERN_C String_t* _stringLiteral4B8EE1D99E55FDC8FBE52391086C2F425F6AA626;
IL2CPP_EXTERN_C String_t* _stringLiteral4C05F264F2827749B257C389B7C1B994AD67E8C3;
IL2CPP_EXTERN_C String_t* _stringLiteral59729EB1145C8E83047D8BBCA2C6DC8F6A082DBF;
IL2CPP_EXTERN_C String_t* _stringLiteral6B73ED795945027531E9522BB906B336CDA394F4;
IL2CPP_EXTERN_C String_t* _stringLiteral6D2C56060B3F7353031AD314517C27945CC39748;
IL2CPP_EXTERN_C String_t* _stringLiteral73ECF991CB2C809BD76AEB6EF481BB2C816E93F3;
IL2CPP_EXTERN_C String_t* _stringLiteral84D6EACB0A96EDCCCEF46D2C88A45B685E4996E2;
IL2CPP_EXTERN_C String_t* _stringLiteral8586A9D31F622A392F306BE35308D8768CC6A80A;
IL2CPP_EXTERN_C String_t* _stringLiteral89DB2D99D71D2BFDF5BE40CCB2C9A0F3763DD1A4;
IL2CPP_EXTERN_C String_t* _stringLiteral89DED4B57F2A5D3967765BE97C28C32EDC26B793;
IL2CPP_EXTERN_C String_t* _stringLiteral99A5C4ED7B3FAB6ED3A26CA5392626EAAACE7B0A;
IL2CPP_EXTERN_C String_t* _stringLiteral9BBB32CCC21BB366F147DF39A51834651CDC854F;
IL2CPP_EXTERN_C String_t* _stringLiteral9F2FC455622BDBE357503CE0FA4CBF83FF54FE04;
IL2CPP_EXTERN_C String_t* _stringLiteralB7C45DD316C68ABF3429C20058C2981C652192F2;
IL2CPP_EXTERN_C String_t* _stringLiteralC18C9BB6DF0D5C60CE5A5D2D3D6111BEB6F8CCEB;
IL2CPP_EXTERN_C String_t* _stringLiteralCBE3AB8700B962CFC2BA454CED3E5EC7EB5AC5C1;
IL2CPP_EXTERN_C String_t* _stringLiteralCD98202A6EC5293093FBD559FA1C99CE6B98344E;
IL2CPP_EXTERN_C String_t* _stringLiteralD23483827499BCEE53BD792FEB5BBB36D3A5E63A;
IL2CPP_EXTERN_C String_t* _stringLiteralD8D751988DD5B3888B0ACDB2BFE22E5FA8BBBEEC;
IL2CPP_EXTERN_C String_t* _stringLiteralF1CAF49A3BB6501D9753F41A12098ECDF0CCE5A4;
IL2CPP_EXTERN_C String_t* _stringLiteralFFF368B92F042A6F27288FB4036FCD460758F47B;
IL2CPP_EXTERN_C const RuntimeMethod* Component_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_mC91ACC92AD57CA6CA00991DAF1DB3830BCE07AF8_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Add_m4A0CF999D0DF4986DF249FD0DB95889F2FD423A9_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_GetEnumerator_mD22822F067AD3D9BCA373A0546FE8615909B0FEC_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_m742B839DF18EB8A76B381A28B11F1FAB2FFDC0CC_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_Dispose_m9ED4E52C26F04192D41980F154879E9D585E9791_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_MoveNext_m424B03CFB200058B8CE11047A5D7B6C0EEF5BE36_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_get_Current_mDE9C73F49F1A0AACB90F99DEB8FDC16508F49543_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* GameObject_AddComponent_TisRunner_tB8E78BC8FEC1129C330C7EF44FE5BBFC57BFB7B8_m274D6F612B4E1E560945FD2406F657DBE0060979_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* GameObject_GetComponent_TisRunner_tB8E78BC8FEC1129C330C7EF44FE5BBFC57BFB7B8_m02D34C860CE1EDFBEE672B22BBD2AD9E6B55DEA9_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* KeyValuePair_2_get_Key_m371FAFC80DB00656F29F2E3A607A15D8F1A4D9A2_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* KeyValuePair_2_get_Value_m4E42B1A68B9D4E0CD522118A7CE586CC714A92B6_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m184EE05AA8961970FF60E58756ED8BE4F017374E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m1914F43100B594ABF59084FCF1FCFA2D848E9025_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m1BA57A9C6578828099352E29E2BDA8357F2EFCD0_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m4F59D0CC812DAC6ECC6BFC85CDD3210501B8FFD0_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m7817B44F55F4B07BD59D677CB6CAD10D578EAC86_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m9BB55A99B1916D012AB4E3E0A2CAB3E7EFA4513D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_mA524A94B70C813C1BA791AF84F038FC221A00FC8_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_mAC66765B1249EE653786600439164EBFDD4CD46B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_mB7F4419CE7EA8D9E393B3D5CF160812DB776DD9C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_mC7D6941F0CB7269D1259683EB81DAF543E912E13_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_mCC5C1CBC4EADCF51A55299EAD6C37250FC897458_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_mCEA246871367366985CC1373045B5CAC13DDECA6_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_mD04F4301A11C785E216B4D3B39B7BBA17AC556D0_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_mD38485CA318AF8F55C5985FACCBAA11B2D534F69_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_mE84497F7EEB65DCBE2B85C3A5F3FF2DC6422FED0_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_mEADFAAEBDAE002FF709831869BFB21C97F3E6545_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_mF7A5FDE71163AB620C0E8DB3CF2D72A13B43ED19_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_mFA38C07130F30DDA8AFCD688E19E79D20832CF90_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_set_Capacity_m450A27888E6E123248BB184BB5FA984716BEEA65_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_set_Capacity_m4B212271F60F59CA181E583E2FA1000A14E49C55_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_set_Capacity_m53C9442D7A2C89C4DC109B654F6515D05DE52B16_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_set_Capacity_m5832DE315E2469EA21365A385436DD5F7824940A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_set_Capacity_m587217153D2FA93F4FC0889992B6BA1FA2D95A87_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_set_Capacity_m5D4C4FA3EEC9734BCBF629BCC57F31DB95D20AC3_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_set_Capacity_m5DBD95CCEA8193924616281AFF64AA00130E135C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_set_Capacity_m7C5EB735CBD98B3B2B64F7FA49954FD5ED73D728_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_set_Capacity_m963CDE36EB1DC3435DF73BC25E0C47DCB90B73EA_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_set_Capacity_m9C560D90140238E989BCCCBF65E8EB846AF78497_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_set_Capacity_mA24D986986B27033E4B1A500D132B53EAF4F974D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_set_Capacity_mAE4CCF57EB35D4AFBB85D1E658B88B9226F3EDB6_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_set_Capacity_mBC09D6DE59BD632D853F41ACEA81571B2F8CBAC6_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_set_Capacity_mCA9040FB8D0912244F96B1C4B829379A6145F529_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_set_Capacity_mD3BF3BBF9B8537037A4A49B234555D9FDC3C7F1E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_set_Capacity_mD5F6FA2BE282F629E5D80DDC855BCC02C875A92C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_set_Capacity_mD8859A91DF45D79EC817B5FD13518AA8FEC1A777_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_set_Capacity_mFAD4171F2861E97F209DAECB9E5C50BCD34018E4_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MessageArray_1__ctor_m070935432E3EC3110B908F76DBAF98885CFDDB32_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MessageArray_1__ctor_m070B185DC9BE9A46B820CFCFED8A57D14830275F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MessageArray_1__ctor_m1A4632C39F931579FEBF2FEA60B370A49C699D53_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MessageArray_1__ctor_m3BC499DB56D4BA1111B6D6E1C8CB126A69677139_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MessageArray_1__ctor_m42C5998DCEE5808E1E75BDC255282820B0FCDE4E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MessageArray_1__ctor_m44916C4D5F46A3D4CB182D99F9E370CBFA347B97_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MessageArray_1__ctor_m667099D521C9333D86ABAA3B49FBF8DF9D833999_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MessageArray_1__ctor_m67D3B507B26914F09606DA7A23A8061AC239B379_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MessageArray_1__ctor_m7E276C8FEE63D2AA74F36394E1EBE4DA877D36C4_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MessageArray_1__ctor_mA5A42AA1E725EA805913577703E01D8889C8B184_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MessageArray_1__ctor_mAA26037C5A2D6E5B1A17B51AFAA9B774B6089B55_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MessageArray_1__ctor_mB185D5F8F245E3548B7E1F83E5D80079D940BEA1_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MessageArray_1__ctor_mB4514016DE6C8FA4D4FA07951B03B60B17241AF4_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MessageArray_1__ctor_mC023B4EA85DD7FE3EAA208D782D302DBDBAF0695_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MessageArray_1__ctor_mC6CA9C8AA50186FFCDF3CA2E5A30AE34E21DE5D2_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MessageArray_1__ctor_mDF051A62863C8BF176120076EFE94E48880CCF09_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MessageArray_1__ctor_mE5F28B4391D395F2076F7B3E76B2E9481C2151D5_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MessageArray_1__ctor_mFF477189E1B6F9EDC567DBA6165ECCB6EEA64992_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MessageArray_1_get_HasNextPage_m3E11E7F669019355A0341BB70330132A889C7709_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MessageArray_1_get_HasNextPage_m72A1A98F96C990D8BA6BA6E2FAA11C72813859E0_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Packet_GetBytes_m338C6646444C8C294FFFE5686F1EABAF17C06784_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Packet_GetBytes_mA6CF76305AA065D7CC120D0883D390B69CAC4529_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* RtcLocalAudioPropertiesReport__ctor_m5EC1418129644EF39E90281288475FDD0C14B8D0_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* RtcService_InnerAudioProcessor_m663C1AC6BC552D87E0EF075932933D89EA182C22_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SimpleDemo_U3CEnterDemoU3Eb__5_0_m177780F4F6EC2BAF980E03603F1050A5E5940F11_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SimpleDemo_U3CStartU3Eb__4_0_m8CEF654CAA456652353B08AD57EF5DACAAAB556D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SimpleDemo_U3CgetUserU3Eb__6_0_mCC18EBE12D82481458FD41732726F882551508FF_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Task_1_OnComplete_m320B333161C5C0070440A132234F801A7BC74020_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Task_1_OnComplete_m35202096110B84EDEDE3B5E67432C170C35F885B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Task_1_OnComplete_m7241FFC878E940C536582E977114C52EDFE412BE_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Task_1__ctor_m1CF0C62EAAB2FD4823E55B281F816BE4AD7A46DC_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Task_1__ctor_m322A3D30581A57328E35B1AA000C12DA27802B9B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Task_1__ctor_m50BEB35518BC513A0C8F5CAE163C038761DDEBD7_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Task_1__ctor_m59D89B840C2D9E7B876A8866DCA1A7BD562B7E56_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Task_1__ctor_m663084DE28D5D98B9394EDB79C8DF0E4CCEB3CC9_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Task_1__ctor_m6C02EE853BD7EA7A09FCD1178C0CC092548CD102_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Task_1__ctor_m7C42D45457C38313FD29A5A7B8FA37EBD5C083BB_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Task_1__ctor_m970BDF1E00FFB8C1E8DF0B795F86CADC4D0FFAA5_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Task_1__ctor_m97DCC7BC2E162881ED2A246242E9A4C8D61C82A3_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Task_1__ctor_mAF2B532E3BB55BD9BDA955D466B020D6C389AEE6_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Task_1__ctor_mCDB56AC9CB59A5C05526C208A7E6DBDB1AA37F66_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Task_1__ctor_mFAD053AE97133C07CA97D23B1899267A85F7C677_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CDownloadImageU3Ed__7_System_Collections_IEnumerator_Reset_m9518B33BC141B6CA28A96185DC117A0318E13001_RuntimeMethod_var;
struct CertificateHandler_t148B524FA5DB39F3ABADB181CD420FC505C33804_marshaled_com;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct DownloadHandler_t1B56C7D3F65D97A1E4B566A14A1E783EA8AE4EBB_marshaled_com;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;
struct UnityWebRequest_t6233B8E22992FC2364A831C1ACB033EF3260C39F_marshaled_com;
struct UnityWebRequest_t6233B8E22992FC2364A831C1ACB033EF3260C39F_marshaled_pinvoke;
struct UploadHandler_t7E504B1A83346248A0C8C4AF73A893226CB83EF6_marshaled_com;

struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct CaptureInfoU5BU5D_tFA6FAA7D7AE3BBB1688FD52AE43DE5032184993E;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct RecordInfoU5BU5D_t1505D0DB4C486883C741B73244F4130B5AF19854;
struct RtcLocalAudioPropertiesInfoU5BU5D_tECCE986B1F5EE0EA71E955DE541538066669D2C7;
struct RtcRemoteAudioPropertiesInfoU5BU5D_t4DD6EF874C9C2844E1101DAE658C91D04DC92952;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Collections.Generic.Dictionary`2<Pico.Platform.RtcPrivilege,System.Int32>
struct Dictionary_2_tFA4E3C6BBA632C5BEEBB77A03650502241C2D607  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_t38553BE78159FA6CCBEDA290331AC5134E82AE89* ____entries_1;
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
	KeyCollection_tD6EC0C8CA3770A4D5AA70DE315028D365F3019B8* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_tA371BC51BC2CC0CDE0AC89FE7437A896E1AB7A0D* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.Collections.Generic.Dictionary`2<System.String,System.String>
struct Dictionary_2_t46B2DB028096FA2B828359E52F37F3105A83AD83  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_t1AF33AD0B7330843448956EC4277517081658AE7* ____entries_1;
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
	KeyCollection_t2EDD317F5771E575ACB63527B5AFB71291040342* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_t238D0D2427C6B841A01F522A41540165A2C4AE76* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.Collections.Generic.Dictionary`2<System.String,Pico.Platform.UserRelationType>
struct Dictionary_2_tFFB4984E3277B96D7DD77603CA615351CE58744C  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_tFC7C5DDFE53BD8FD0DACAFCE15AE61448033DF56* ____entries_1;
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
	KeyCollection_tB39BE178CDFA58872734D7D9D7A2B273DF42DD59* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_t2E5EC2FBD6E6D03DDE2D65650C2A1B69CED77E21* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.AchievementDefinition>
struct List_1_t10AC4D431308924325EECB4A49074CCAD3525C5D  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	AchievementDefinitionU5BU5D_tD45280A798177E339C7F71BEA08B42FBC1324806* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.AchievementProgress>
struct List_1_tB745982DEF869D4B1F9C78EE82DF592AB431896B  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	AchievementProgressU5BU5D_t116D1223032641932BDB37219A7C0EEE9628107A* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.ApplicationInvite>
struct List_1_tE88D817DED2AB9E24E7A5629200C2087045253F5  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	ApplicationInviteU5BU5D_tFEC3D38D47E91DA4E4859DF99DFA649C726B8B1D* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.AssetDetails>
struct List_1_t99C4055E7A18C1DF32B7AECA7EE4535206181597  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	AssetDetailsU5BU5D_tDFD25B55AA42A540A7F1AE1B0DFB4F4A99E607A9* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.Challenge>
struct List_1_t1270A6FA80F83E5E821A0DAE5FB3C06865ACB59C  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	ChallengeU5BU5D_tD70C30ED4DDCC167BFB807A20076D422DD522DFC* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.ChallengeEntry>
struct List_1_t3A2B2890CB7F9F96B159F90ED3C352D0F69BFC03  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	ChallengeEntryU5BU5D_t01DC002B76F7F4CE1070F74F8475CFE177A1AB72* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.Destination>
struct List_1_t5C085F464CB50B6E73049AC6D994648AA7E2410E  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	DestinationU5BU5D_t8A295AD29D924C3496379E613BF75381A9812A14* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.Leaderboard>
struct List_1_t724694C0B4027B186B04C28FF07C047043904083  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	LeaderboardU5BU5D_t228A8CBD32C5E10AAC389ABCF0A9188B66E287D4* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.LeaderboardEntry>
struct List_1_tC943684C0EBEF2BD2CFD9D2B29FC554E51FBB6A8  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	LeaderboardEntryU5BU5D_t1E730BC8E35CD591F53C791F553A7BDB7D7B9F7A* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.MatchmakingAdminSnapshotCandidate>
struct List_1_tABBB0A07DB48EE3A69D8AE19FD395C748196C1A1  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	MatchmakingAdminSnapshotCandidateU5BU5D_t7472DB57A6C6C52E8EEF83AD0B13B118AA683DF5* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.MatchmakingRoom>
struct List_1_tA41CDF0D6A3ED7853A9F821A69838D214E8DD5CB  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	MatchmakingRoomU5BU5D_t15CBD754E9AA79A2D96C20A2B446F16C0052AC74* ____items_1;
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

// System.Collections.Generic.List`1<Pico.Platform.Models.Product>
struct List_1_tECB4BC629C4B6ABBCAC7C8ADCEFEBA5518203F3C  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	ProductU5BU5D_tE4833FDC634EF457AA9978D99883A22B899D0CD5* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.Purchase>
struct List_1_t0BED0F374F8819664848045406304C5C43B290F8  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	PurchaseU5BU5D_t2470799E07346B5DDC326FD66E807F8D3509FA46* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.Room>
struct List_1_t17BC494950CA211E4E00DDC3979C43A2750F5DF8  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	RoomU5BU5D_t65395623B3E4D69C7430C314A2AB8B6E2B0ACA79* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.RoomInviteNotification>
struct List_1_t56C8E4CBC81C6319DB682BE3E114E43F68C3AB09  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	RoomInviteNotificationU5BU5D_t9975E8DA69A572BB6D35A08EB32D43FEE31CEAA2* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.SportDailySummary>
struct List_1_t6C36B6FAA48E5DAE13D84C1C2C9D39AEEF86399F  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	SportDailySummaryU5BU5D_t73B931C0CDA0A57B1620B8E2198C6DFA768953AB* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.User>
struct List_1_tA51A980F281692A23CBC3DFCF8131D4AD8565A1C  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	UserU5BU5D_t837772AE1B0DAAE3734C4D1A50D2C00923A3D4DF* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.UserRoom>
struct List_1_t68B676CB2F1554E5228FD7A20B97B490395C7E2C  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	UserRoomU5BU5D_t6CA1BBB733313CD8E3B344CD94E1666653050D24* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// Pico.Platform.Models.AchievementUpdate
struct AchievementUpdate_t41C493D095A1BB1BFC2C4BB0A17696AB038C8474  : public RuntimeObject
{
	// System.Boolean Pico.Platform.Models.AchievementUpdate::JustUnlocked
	bool ___JustUnlocked_0;
	// System.String Pico.Platform.Models.AchievementUpdate::Name
	String_t* ___Name_1;
};

// Pico.Platform.Models.ApplicationInvite
struct ApplicationInvite_t95D2E15775E4CD15D060CDF6CF25EDB854EB67D7  : public RuntimeObject
{
	// Pico.Platform.Models.Destination Pico.Platform.Models.ApplicationInvite::Destination
	Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211* ___Destination_0;
	// Pico.Platform.Models.User Pico.Platform.Models.ApplicationInvite::Recipient
	User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4* ___Recipient_1;
	// System.UInt64 Pico.Platform.Models.ApplicationInvite::ID
	uint64_t ___ID_2;
	// System.Boolean Pico.Platform.Models.ApplicationInvite::IsActive
	bool ___IsActive_3;
	// System.String Pico.Platform.Models.ApplicationInvite::LobbySessionId
	String_t* ___LobbySessionId_4;
	// System.String Pico.Platform.Models.ApplicationInvite::MatchSessionId
	String_t* ___MatchSessionId_5;
};

// Pico.Platform.Models.ApplicationVersion
struct ApplicationVersion_t62CE03D7C8FBF594FDE1979E76974E0E3E707156  : public RuntimeObject
{
	// System.Int64 Pico.Platform.Models.ApplicationVersion::CurrentCode
	int64_t ___CurrentCode_0;
	// System.String Pico.Platform.Models.ApplicationVersion::CurrentName
	String_t* ___CurrentName_1;
	// System.Int64 Pico.Platform.Models.ApplicationVersion::LatestCode
	int64_t ___LatestCode_2;
	// System.String Pico.Platform.Models.ApplicationVersion::LatestName
	String_t* ___LatestName_3;
};

// Pico.Platform.Models.AsrResult
struct AsrResult_t004816647ADC1F06A8D0AE66C355906FB022BEA5  : public RuntimeObject
{
	// System.String Pico.Platform.Models.AsrResult::Text
	String_t* ___Text_0;
	// System.Boolean Pico.Platform.Models.AsrResult::IsFinalResult
	bool ___IsFinalResult_1;
};

// Pico.Platform.Models.AssetDetails
struct AssetDetails_t8F8B8199F92068253768AABE9EB4314FFB926AE2  : public RuntimeObject
{
	// System.UInt64 Pico.Platform.Models.AssetDetails::AssetId
	uint64_t ___AssetId_0;
	// System.String Pico.Platform.Models.AssetDetails::AssetType
	String_t* ___AssetType_1;
	// System.String Pico.Platform.Models.AssetDetails::DownloadStatus
	String_t* ___DownloadStatus_2;
	// System.String Pico.Platform.Models.AssetDetails::Filepath
	String_t* ___Filepath_3;
	// System.String Pico.Platform.Models.AssetDetails::Metadata
	String_t* ___Metadata_4;
	// System.String Pico.Platform.Models.AssetDetails::Filename
	String_t* ___Filename_5;
	// System.Int32 Pico.Platform.Models.AssetDetails::Version
	int32_t ___Version_6;
	// System.String Pico.Platform.Models.AssetDetails::IapStatus
	String_t* ___IapStatus_7;
	// System.String Pico.Platform.Models.AssetDetails::IapSku
	String_t* ___IapSku_8;
	// System.String Pico.Platform.Models.AssetDetails::IapName
	String_t* ___IapName_9;
	// System.String Pico.Platform.Models.AssetDetails::IapPrice
	String_t* ___IapPrice_10;
	// System.String Pico.Platform.Models.AssetDetails::IapCurrency
	String_t* ___IapCurrency_11;
	// System.String Pico.Platform.Models.AssetDetails::IapDescription
	String_t* ___IapDescription_12;
	// System.String Pico.Platform.Models.AssetDetails::IapIcon
	String_t* ___IapIcon_13;
};

// Pico.Platform.Models.AssetFileDeleteForSafety
struct AssetFileDeleteForSafety_tE0658EB374DF5E9FFEB4D95D7CF5CDBA40E8EABA  : public RuntimeObject
{
	// System.UInt64 Pico.Platform.Models.AssetFileDeleteForSafety::AssetId
	uint64_t ___AssetId_0;
	// System.String Pico.Platform.Models.AssetFileDeleteForSafety::Reason
	String_t* ___Reason_1;
};

// Pico.Platform.Models.AssetFileDeleteResult
struct AssetFileDeleteResult_t69B9AFEF34255AED9E99D39461203AD4310CC434  : public RuntimeObject
{
	// System.String Pico.Platform.Models.AssetFileDeleteResult::Filepath
	String_t* ___Filepath_0;
	// System.Boolean Pico.Platform.Models.AssetFileDeleteResult::Success
	bool ___Success_1;
	// System.UInt64 Pico.Platform.Models.AssetFileDeleteResult::AssetId
	uint64_t ___AssetId_2;
};

// Pico.Platform.Models.AssetFileDownloadCancelResult
struct AssetFileDownloadCancelResult_t3DBDC2912716D7BF23B8B8C7CC417C90AD405B43  : public RuntimeObject
{
	// System.String Pico.Platform.Models.AssetFileDownloadCancelResult::Filepath
	String_t* ___Filepath_0;
	// System.Boolean Pico.Platform.Models.AssetFileDownloadCancelResult::Success
	bool ___Success_1;
	// System.UInt64 Pico.Platform.Models.AssetFileDownloadCancelResult::AssetId
	uint64_t ___AssetId_2;
};

// Pico.Platform.Models.AssetFileDownloadResult
struct AssetFileDownloadResult_tD0B1698C03580D6A8A9CD407B09D147D0F02F639  : public RuntimeObject
{
	// System.UInt64 Pico.Platform.Models.AssetFileDownloadResult::AssetId
	uint64_t ___AssetId_0;
	// System.String Pico.Platform.Models.AssetFileDownloadResult::Filepath
	String_t* ___Filepath_1;
};

// Pico.Platform.Models.AssetStatus
struct AssetStatus_t1D527E1B3D8881BD413FE56B7E928774704F8206  : public RuntimeObject
{
	// System.UInt64 Pico.Platform.Models.AssetStatus::AssetId
	uint64_t ___AssetId_0;
	// System.String Pico.Platform.Models.AssetStatus::Filename
	String_t* ___Filename_1;
	// System.String Pico.Platform.Models.AssetStatus::Filepath
	String_t* ___Filepath_2;
	// System.String Pico.Platform.Models.AssetStatus::DownloadStatus
	String_t* ___DownloadStatus_3;
};

// Pico.Platform.Models.AssetType
struct AssetType_t4D9491CFFC741E8CC2C629D37B9B20F35810F5F2  : public RuntimeObject
{
};

// Pico.Platform.Models.CaptureInfo
struct CaptureInfo_t522928357E5822ACBC5FC59A060BDBABFF3DF575  : public RuntimeObject
{
	// System.String Pico.Platform.Models.CaptureInfo::ImagePath
	String_t* ___ImagePath_0;
	// System.String Pico.Platform.Models.CaptureInfo::JobId
	String_t* ___JobId_1;
};

// Pico.Platform.CoreService
struct CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014  : public RuntimeObject
{
};

// Pico.Platform.Models.Destination
struct Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211  : public RuntimeObject
{
	// System.String Pico.Platform.Models.Destination::ApiName
	String_t* ___ApiName_0;
	// System.String Pico.Platform.Models.Destination::DeeplinkMessage
	String_t* ___DeeplinkMessage_1;
	// System.String Pico.Platform.Models.Destination::DisplayName
	String_t* ___DisplayName_2;
};

// Pico.Platform.Models.DownloadStatus
struct DownloadStatus_t59E0A136462DD7C5CA4DE2177B95D1F04259B44C  : public RuntimeObject
{
};

// System.Text.Encoding
struct Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095  : public RuntimeObject
{
	// System.Int32 System.Text.Encoding::m_codePage
	int32_t ___m_codePage_9;
	// System.Globalization.CodePageDataItem System.Text.Encoding::dataItem
	CodePageDataItem_t52460FA30AE37F4F26ACB81055E58002262F19F2* ___dataItem_10;
	// System.Boolean System.Text.Encoding::m_deserializedFromEverett
	bool ___m_deserializedFromEverett_11;
	// System.Boolean System.Text.Encoding::m_isReadOnly
	bool ___m_isReadOnly_12;
	// System.Text.EncoderFallback System.Text.Encoding::encoderFallback
	EncoderFallback_tD2C40CE114AA9D8E1F7196608B2D088548015293* ___encoderFallback_13;
	// System.Text.DecoderFallback System.Text.Encoding::decoderFallback
	DecoderFallback_t7324102215E4ED41EC065C02EB501CB0BC23CD90* ___decoderFallback_14;
};

// Pico.Platform.Models.EntitlementCheckResult
struct EntitlementCheckResult_tDCC132CD30FB7907CB5575B3C629531914BCD061  : public RuntimeObject
{
	// System.Boolean Pico.Platform.Models.EntitlementCheckResult::HasEntitlement
	bool ___HasEntitlement_0;
	// System.Int32 Pico.Platform.Models.EntitlementCheckResult::StatusCode
	int32_t ___StatusCode_1;
	// System.String Pico.Platform.Models.EntitlementCheckResult::StatusMessage
	String_t* ___StatusMessage_2;
};

// Pico.Platform.Models.Error
struct Error_t3CA63648FA025A8FBA63EA102526BE2F757CAF88  : public RuntimeObject
{
	// System.Int32 Pico.Platform.Models.Error::Code
	int32_t ___Code_0;
	// System.String Pico.Platform.Models.Error::Message
	String_t* ___Message_1;
};

// Pico.Platform.Models.IapStatus
struct IapStatus_t4911C8B5D7FBA8BA8D639D73CE9314CEBF270BB5  : public RuntimeObject
{
};

// Pico.Platform.Models.LaunchFriendResult
struct LaunchFriendResult_tE14F761B20423DF2AA66723EEB659CEA351551A1  : public RuntimeObject
{
	// System.Boolean Pico.Platform.Models.LaunchFriendResult::DidCancel
	bool ___DidCancel_0;
	// System.Boolean Pico.Platform.Models.LaunchFriendResult::DidSendRequest
	bool ___DidSendRequest_1;
};

// Pico.Platform.Models.Leaderboard
struct Leaderboard_t6D83DEF000B68074D583D0D92AED4AE1EFB14595  : public RuntimeObject
{
	// System.String Pico.Platform.Models.Leaderboard::ApiName
	String_t* ___ApiName_0;
	// System.UInt64 Pico.Platform.Models.Leaderboard::ID
	uint64_t ___ID_1;
	// Pico.Platform.Models.Destination Pico.Platform.Models.Leaderboard::DestinationOptional
	Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211* ___DestinationOptional_2;
};

// Pico.Platform.Models.MatchmakingAdminSnapshot
struct MatchmakingAdminSnapshot_tF75B3A1A51D503587990BECC068C30E7671EE451  : public RuntimeObject
{
	// Pico.Platform.Models.MatchmakingAdminSnapshotCandidateList Pico.Platform.Models.MatchmakingAdminSnapshot::CandidateList
	MatchmakingAdminSnapshotCandidateList_tCB8BE369951F7307CA9A1AF9C7FE4B6253339C94* ___CandidateList_0;
	// System.Double Pico.Platform.Models.MatchmakingAdminSnapshot::MyCurrentThreshold
	double ___MyCurrentThreshold_1;
};

// Pico.Platform.Models.MatchmakingAdminSnapshotCandidate
struct MatchmakingAdminSnapshotCandidate_t2325F5337C73FF55AB6D932F2A14C97E3A813CCC  : public RuntimeObject
{
	// System.Boolean Pico.Platform.Models.MatchmakingAdminSnapshotCandidate::CanMatch
	bool ___CanMatch_0;
	// System.Double Pico.Platform.Models.MatchmakingAdminSnapshotCandidate::MyTotalScore
	double ___MyTotalScore_1;
	// System.Double Pico.Platform.Models.MatchmakingAdminSnapshotCandidate::TheirCurrentThreshold
	double ___TheirCurrentThreshold_2;
};

// Pico.Platform.Models.MatchmakingBrowseResult
struct MatchmakingBrowseResult_tC20A58B18DE8FF7F9A4E7450063ACB8FC38D2C58  : public RuntimeObject
{
	// Pico.Platform.Models.MatchmakingEnqueueResult Pico.Platform.Models.MatchmakingBrowseResult::EnqueueResult
	MatchmakingEnqueueResult_t620CF96FB5A92A1783E9882E651C0CA76E2E3D8D* ___EnqueueResult_0;
	// Pico.Platform.Models.MatchmakingRoomList Pico.Platform.Models.MatchmakingBrowseResult::MatchmakingRooms
	MatchmakingRoomList_t97325021F617542B368184443F745CC637C866B7* ___MatchmakingRooms_1;
};

// Pico.Platform.Models.MatchmakingEnqueueResult
struct MatchmakingEnqueueResult_t620CF96FB5A92A1783E9882E651C0CA76E2E3D8D  : public RuntimeObject
{
	// Pico.Platform.Models.MatchmakingAdminSnapshot Pico.Platform.Models.MatchmakingEnqueueResult::AdminSnapshotOptional
	MatchmakingAdminSnapshot_tF75B3A1A51D503587990BECC068C30E7671EE451* ___AdminSnapshotOptional_0;
	// System.UInt32 Pico.Platform.Models.MatchmakingEnqueueResult::AverageWait
	uint32_t ___AverageWait_1;
	// System.UInt32 Pico.Platform.Models.MatchmakingEnqueueResult::MatchesInLastHourCount
	uint32_t ___MatchesInLastHourCount_2;
	// System.UInt32 Pico.Platform.Models.MatchmakingEnqueueResult::MaxExpectedWait
	uint32_t ___MaxExpectedWait_3;
	// System.String Pico.Platform.Models.MatchmakingEnqueueResult::Pool
	String_t* ___Pool_4;
	// System.UInt32 Pico.Platform.Models.MatchmakingEnqueueResult::RecentMatchPercentage
	uint32_t ___RecentMatchPercentage_5;
};

// Pico.Platform.Models.MatchmakingEnqueueResultAndRoom
struct MatchmakingEnqueueResultAndRoom_t01215772818E3385FC96DCE8D46E9906FCA8D9FC  : public RuntimeObject
{
	// Pico.Platform.Models.MatchmakingEnqueueResult Pico.Platform.Models.MatchmakingEnqueueResultAndRoom::MatchmakingEnqueueResult
	MatchmakingEnqueueResult_t620CF96FB5A92A1783E9882E651C0CA76E2E3D8D* ___MatchmakingEnqueueResult_0;
	// Pico.Platform.Models.Room Pico.Platform.Models.MatchmakingEnqueueResultAndRoom::Room
	Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135* ___Room_1;
};

// Pico.Platform.Models.MatchmakingRoom
struct MatchmakingRoom_t564ECF1B3DF437F6B3DE5EC03A5E173193CE6C74  : public RuntimeObject
{
	// Pico.Platform.Models.Room Pico.Platform.Models.MatchmakingRoom::Room
	Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135* ___Room_0;
	// System.UInt32 Pico.Platform.Models.MatchmakingRoom::PingTime
	uint32_t ___PingTime_1;
	// System.Boolean Pico.Platform.Models.MatchmakingRoom::HasPingTime
	bool ___HasPingTime_2;
};

// Pico.Platform.Models.MatchmakingStats
struct MatchmakingStats_tA7354632354901085E56D8553EF6B4A584424184  : public RuntimeObject
{
	// System.UInt32 Pico.Platform.Models.MatchmakingStats::DrawCount
	uint32_t ___DrawCount_0;
	// System.UInt32 Pico.Platform.Models.MatchmakingStats::LossCount
	uint32_t ___LossCount_1;
	// System.UInt32 Pico.Platform.Models.MatchmakingStats::SkillLevel
	uint32_t ___SkillLevel_2;
	// System.Double Pico.Platform.Models.MatchmakingStats::SkillMean
	double ___SkillMean_3;
	// System.Double Pico.Platform.Models.MatchmakingStats::SkillStandardDeviation
	double ___SkillStandardDeviation_4;
	// System.UInt32 Pico.Platform.Models.MatchmakingStats::WinCount
	uint32_t ___WinCount_5;
};

// Pico.Platform.Models.OrgScopedID
struct OrgScopedID_tE7AFDD1678D708DC9371763230892D40F965A581  : public RuntimeObject
{
	// System.String Pico.Platform.Models.OrgScopedID::ID
	String_t* ___ID_0;
};

// Pico.Platform.Models.PermissionResult
struct PermissionResult_t235EBFBF617C649652D95D6EEB96D6C1E66EE3CF  : public RuntimeObject
{
	// System.String[] Pico.Platform.Models.PermissionResult::AuthorizedPermissions
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___AuthorizedPermissions_0;
	// System.String Pico.Platform.Models.PermissionResult::AccessToken
	String_t* ___AccessToken_1;
	// System.String Pico.Platform.Models.PermissionResult::UserID
	String_t* ___UserID_2;
};

// Pico.Platform.Models.Permissions
struct Permissions_t9DB55E53A2F5A49CAEC70D4F6FF11E7F40CCBAAA  : public RuntimeObject
{
};

// Pico.Platform.Models.PresenceJoinIntent
struct PresenceJoinIntent_t708F6CB20BA715DA328B67F38BFD1376DF6364D3  : public RuntimeObject
{
	// System.String Pico.Platform.Models.PresenceJoinIntent::DeeplinkMessage
	String_t* ___DeeplinkMessage_0;
	// System.String Pico.Platform.Models.PresenceJoinIntent::DestinationApiName
	String_t* ___DestinationApiName_1;
	// System.String Pico.Platform.Models.PresenceJoinIntent::LobbySessionId
	String_t* ___LobbySessionId_2;
	// System.String Pico.Platform.Models.PresenceJoinIntent::MatchSessionId
	String_t* ___MatchSessionId_3;
	// System.String Pico.Platform.Models.PresenceJoinIntent::Extra
	String_t* ___Extra_4;
};

// Pico.Platform.Models.RecordInfo
struct RecordInfo_t391FC28285898D9D06E379287A88F5A4BA4A6019  : public RuntimeObject
{
	// System.String Pico.Platform.Models.RecordInfo::VideoPath
	String_t* ___VideoPath_0;
	// System.Int32 Pico.Platform.Models.RecordInfo::DurationInMilliSeconds
	int32_t ___DurationInMilliSeconds_1;
	// System.Int32 Pico.Platform.Models.RecordInfo::Width
	int32_t ___Width_2;
	// System.Int32 Pico.Platform.Models.RecordInfo::Height
	int32_t ___Height_3;
	// System.String Pico.Platform.Models.RecordInfo::JobId
	String_t* ___JobId_4;
};

// Pico.Platform.Models.RtcAudioPropertyInfo
struct RtcAudioPropertyInfo_tA10BA2C71B943D7A31ED99324B58ECBC13C05268  : public RuntimeObject
{
	// System.Int32 Pico.Platform.Models.RtcAudioPropertyInfo::Volume
	int32_t ___Volume_0;
};

// Pico.Platform.Models.RtcBinaryMessageReceived
struct RtcBinaryMessageReceived_t27A81B34E30B69FD73D308AEBB3C92201FA00FB2  : public RuntimeObject
{
	// System.String Pico.Platform.Models.RtcBinaryMessageReceived::UserId
	String_t* ___UserId_0;
	// System.Byte[] Pico.Platform.Models.RtcBinaryMessageReceived::Data
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___Data_1;
	// System.String Pico.Platform.Models.RtcBinaryMessageReceived::RoomId
	String_t* ___RoomId_2;
};

// Pico.Platform.Models.RtcLeaveRoomResult
struct RtcLeaveRoomResult_t7FC19B99E6788124464A77D25421776CB62301FF  : public RuntimeObject
{
	// System.String Pico.Platform.Models.RtcLeaveRoomResult::RoomId
	String_t* ___RoomId_0;
};

// Pico.Platform.Models.RtcLocalAudioPropertiesReport
struct RtcLocalAudioPropertiesReport_t0AA9BC3CF8E0B67661E0CF11B68EBEE27C9D9E7D  : public RuntimeObject
{
	// Pico.Platform.Models.RtcLocalAudioPropertiesInfo[] Pico.Platform.Models.RtcLocalAudioPropertiesReport::AudioPropertiesInfos
	RtcLocalAudioPropertiesInfoU5BU5D_tECCE986B1F5EE0EA71E955DE541538066669D2C7* ___AudioPropertiesInfos_0;
};

// Pico.Platform.Models.RtcMessageSendResult
struct RtcMessageSendResult_t175C63F675CA721C614F552DAED8AD5CDD8D19D9  : public RuntimeObject
{
	// System.Int64 Pico.Platform.Models.RtcMessageSendResult::MessageId
	int64_t ___MessageId_0;
	// System.Int32 Pico.Platform.Models.RtcMessageSendResult::Error
	int32_t ___Error_1;
	// System.String Pico.Platform.Models.RtcMessageSendResult::RoomId
	String_t* ___RoomId_2;
};

// Pico.Platform.Models.RtcRemoteAudioPropertiesInfo
struct RtcRemoteAudioPropertiesInfo_t756C00636961DE878EE3D2DAD934F01DC0DE3C06  : public RuntimeObject
{
	// Pico.Platform.Models.RtcRemoteStreamKey Pico.Platform.Models.RtcRemoteAudioPropertiesInfo::StreamKey
	RtcRemoteStreamKey_tA69532F8EF7C977014612F775D146C3038C61E0E* ___StreamKey_0;
	// Pico.Platform.Models.RtcAudioPropertyInfo Pico.Platform.Models.RtcRemoteAudioPropertiesInfo::AudioPropertiesInfo
	RtcAudioPropertyInfo_tA10BA2C71B943D7A31ED99324B58ECBC13C05268* ___AudioPropertiesInfo_1;
};

// Pico.Platform.Models.RtcRemoteAudioPropertiesReport
struct RtcRemoteAudioPropertiesReport_t575A87A1EE3387315239DA4AF54DAA70B4E5EB78  : public RuntimeObject
{
	// Pico.Platform.Models.RtcRemoteAudioPropertiesInfo[] Pico.Platform.Models.RtcRemoteAudioPropertiesReport::AudioPropertiesInfos
	RtcRemoteAudioPropertiesInfoU5BU5D_t4DD6EF874C9C2844E1101DAE658C91D04DC92952* ___AudioPropertiesInfos_0;
	// System.Int32 Pico.Platform.Models.RtcRemoteAudioPropertiesReport::TotalRemoteVolume
	int32_t ___TotalRemoteVolume_1;
};

// Pico.Platform.Models.RtcRoomError
struct RtcRoomError_t9E2842355A967FB7C0C5170BBAE107B299384383  : public RuntimeObject
{
	// System.Int32 Pico.Platform.Models.RtcRoomError::Code
	int32_t ___Code_0;
	// System.String Pico.Platform.Models.RtcRoomError::RoomId
	String_t* ___RoomId_1;
};

// Pico.Platform.Models.RtcRoomMessageReceived
struct RtcRoomMessageReceived_t2BDF5904A9D3EEF6D72D964485D208779637F7DD  : public RuntimeObject
{
	// System.String Pico.Platform.Models.RtcRoomMessageReceived::UserId
	String_t* ___UserId_0;
	// System.String Pico.Platform.Models.RtcRoomMessageReceived::Message
	String_t* ___Message_1;
	// System.String Pico.Platform.Models.RtcRoomMessageReceived::RoomId
	String_t* ___RoomId_2;
};

// Pico.Platform.Models.RtcRoomStats
struct RtcRoomStats_t82FFF1123D5D67FC8D0027DD78C0BCD933C419CE  : public RuntimeObject
{
	// System.Int32 Pico.Platform.Models.RtcRoomStats::TotalDuration
	int32_t ___TotalDuration_0;
	// System.Int32 Pico.Platform.Models.RtcRoomStats::UserCount
	int32_t ___UserCount_1;
	// System.String Pico.Platform.Models.RtcRoomStats::RoomId
	String_t* ___RoomId_2;
};

// Pico.Platform.Models.RtcRoomWarn
struct RtcRoomWarn_t606796009EEE6543FEC76C7457FB6F8156C06BD4  : public RuntimeObject
{
	// System.Int32 Pico.Platform.Models.RtcRoomWarn::Code
	int32_t ___Code_0;
	// System.String Pico.Platform.Models.RtcRoomWarn::RoomId
	String_t* ___RoomId_1;
};

// Pico.Platform.RtcService
struct RtcService_t22C275834C979544290EE8B61C467477647BD1BF  : public RuntimeObject
{
};

// Pico.Platform.Models.RtcUserJoinInfo
struct RtcUserJoinInfo_t2B639AA4EA2CEC3216FF167FA01780A3F6B7B747  : public RuntimeObject
{
	// System.String Pico.Platform.Models.RtcUserJoinInfo::UserId
	String_t* ___UserId_0;
	// System.String Pico.Platform.Models.RtcUserJoinInfo::UserExtra
	String_t* ___UserExtra_1;
	// System.Int32 Pico.Platform.Models.RtcUserJoinInfo::Elapsed
	int32_t ___Elapsed_2;
	// System.String Pico.Platform.Models.RtcUserJoinInfo::RoomId
	String_t* ___RoomId_3;
};

// Pico.Platform.Models.RtcUserMessageReceived
struct RtcUserMessageReceived_t156E2473096464ECCB4B298A7644E6C572A6292E  : public RuntimeObject
{
	// System.String Pico.Platform.Models.RtcUserMessageReceived::UserId
	String_t* ___UserId_0;
	// System.String Pico.Platform.Models.RtcUserMessageReceived::Message
	String_t* ___Message_1;
	// System.String Pico.Platform.Models.RtcUserMessageReceived::RoomId
	String_t* ___RoomId_2;
};

// Pico.Platform.Models.SendInvitesResult
struct SendInvitesResult_tF1FCB62C7DDA973DC7DDE54DC9DEEF5FC77B8B57  : public RuntimeObject
{
	// Pico.Platform.Models.ApplicationInviteList Pico.Platform.Models.SendInvitesResult::Invites
	ApplicationInviteList_tCFA701E5249821E8B9BBFD13F595859AFFAB19DB* ___Invites_0;
};

// Pico.Platform.Models.SessionMedia
struct SessionMedia_tCFC23B02299EDBE3E3749B48286C4CD403C89A07  : public RuntimeObject
{
	// Pico.Platform.Models.CaptureInfo[] Pico.Platform.Models.SessionMedia::Images
	CaptureInfoU5BU5D_tFA6FAA7D7AE3BBB1688FD52AE43DE5032184993E* ___Images_0;
	// Pico.Platform.Models.RecordInfo[] Pico.Platform.Models.SessionMedia::Videos
	RecordInfoU5BU5D_t1505D0DB4C486883C741B73244F4130B5AF19854* ___Videos_1;
};

// Pico.Platform.Models.SpeechError
struct SpeechError_t370B79F899E733FECFC5D12BFA22AB0E146C96FB  : public RuntimeObject
{
	// System.String Pico.Platform.Models.SpeechError::Message
	String_t* ___Message_0;
	// System.String Pico.Platform.Models.SpeechError::SessionId
	String_t* ___SessionId_1;
	// System.Int32 Pico.Platform.Models.SpeechError::Code
	int32_t ___Code_2;
};

// Pico.Platform.SpeechService
struct SpeechService_t4136B8573DC4D69E06013EC67BCD1E4052C18EE9  : public RuntimeObject
{
};

// Pico.Platform.SportService
struct SportService_tD1EA179C868835154FF7C4CB89C1EDB968C94AE5  : public RuntimeObject
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

// Pico.Platform.Models.SupplementaryMetric
struct SupplementaryMetric_t28C1258D6CB519A099746C713C51A1F14C2C242A  : public RuntimeObject
{
	// System.UInt64 Pico.Platform.Models.SupplementaryMetric::ID
	uint64_t ___ID_0;
	// System.Int64 Pico.Platform.Models.SupplementaryMetric::Metric
	int64_t ___Metric_1;
};

// Pico.Platform.Models.SystemInfo
struct SystemInfo_t53AF5429861C13B1769EA33EAA762275B333CCA0  : public RuntimeObject
{
	// System.String Pico.Platform.Models.SystemInfo::ROMVersion
	String_t* ___ROMVersion_0;
	// System.String Pico.Platform.Models.SystemInfo::Locale
	String_t* ___Locale_1;
	// System.String Pico.Platform.Models.SystemInfo::ProductName
	String_t* ___ProductName_2;
	// System.Boolean Pico.Platform.Models.SystemInfo::IsCnDevice
	bool ___IsCnDevice_3;
	// System.String Pico.Platform.Models.SystemInfo::MatrixVersionName
	String_t* ___MatrixVersionName_4;
	// System.Int64 Pico.Platform.Models.SystemInfo::MatrixVersionCode
	int64_t ___MatrixVersionCode_5;
};

// Pico.Platform.Task
struct Task_t4FEBAE6911008FF1A81989732EF0BAC5BCD1E5D2  : public RuntimeObject
{
	// System.UInt64 Pico.Platform.Task::TaskId
	uint64_t ___TaskId_0;
	// System.Boolean Pico.Platform.Task::HasSetCallback
	bool ___HasSetCallback_1;
};

// Pico.Platform.Models.UserRoom
struct UserRoom_t4A96B7A9523274CA1C6722C4E90D12991C3B11DB  : public RuntimeObject
{
	// Pico.Platform.Models.User Pico.Platform.Models.UserRoom::User
	User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4* ___User_0;
	// Pico.Platform.Models.Room Pico.Platform.Models.UserRoom::Room
	Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135* ___Room_1;
};

// Pico.Platform.UserService
struct UserService_t008C27A8E9F8D4372EA78973FDFCAD2EEFCFF2A5  : public RuntimeObject
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

// UnityEngine.YieldInstruction
struct YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D  : public RuntimeObject
{
};
// Native definition for P/Invoke marshalling of UnityEngine.YieldInstruction
struct YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_pinvoke
{
};
// Native definition for COM marshalling of UnityEngine.YieldInstruction
struct YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_com
{
};

// Pico.Platform.Samples.SimpleDemo/<DownloadImage>d__7
struct U3CDownloadImageU3Ed__7_t12CD4C58AE44E71AC9B06FF3969E6AD7057D8367  : public RuntimeObject
{
	// System.Int32 Pico.Platform.Samples.SimpleDemo/<DownloadImage>d__7::<>1__state
	int32_t ___U3CU3E1__state_0;
	// System.Object Pico.Platform.Samples.SimpleDemo/<DownloadImage>d__7::<>2__current
	RuntimeObject* ___U3CU3E2__current_1;
	// System.String Pico.Platform.Samples.SimpleDemo/<DownloadImage>d__7::mediaUrl
	String_t* ___mediaUrl_2;
	// Pico.Platform.Samples.SimpleDemo Pico.Platform.Samples.SimpleDemo/<DownloadImage>d__7::<>4__this
	SimpleDemo_tB73BB92662E2E45C09FAD8C176DC8690E0FD4195* ___U3CU3E4__this_3;
	// UnityEngine.UI.RawImage Pico.Platform.Samples.SimpleDemo/<DownloadImage>d__7::rawImage
	RawImage_tFF12F7DB574FBDC1863CF607C7A12A5D9F8D6179* ___rawImage_4;
	// UnityEngine.Networking.UnityWebRequest Pico.Platform.Samples.SimpleDemo/<DownloadImage>d__7::<request>5__2
	UnityWebRequest_t6233B8E22992FC2364A831C1ACB033EF3260C39F* ___U3CrequestU3E5__2_5;
};

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.AchievementDefinition>
struct MessageArray_1_t007C8F0F960A812D5EBEBD1E0DEB87A40D9F0051  : public List_1_t10AC4D431308924325EECB4A49074CCAD3525C5D
{
	// System.String Pico.Platform.Models.MessageArray`1::NextPageParam
	String_t* ___NextPageParam_6;
	// System.String Pico.Platform.Models.MessageArray`1::PreviousPageParam
	String_t* ___PreviousPageParam_7;
};

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.AchievementProgress>
struct MessageArray_1_tA2FC832E9F92BC2639E48F182ED14B04435430CA  : public List_1_tB745982DEF869D4B1F9C78EE82DF592AB431896B
{
	// System.String Pico.Platform.Models.MessageArray`1::NextPageParam
	String_t* ___NextPageParam_6;
	// System.String Pico.Platform.Models.MessageArray`1::PreviousPageParam
	String_t* ___PreviousPageParam_7;
};

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.ApplicationInvite>
struct MessageArray_1_tBD7F57C2576E156E6CA055C10BDF9CF1A640AAB8  : public List_1_tE88D817DED2AB9E24E7A5629200C2087045253F5
{
	// System.String Pico.Platform.Models.MessageArray`1::NextPageParam
	String_t* ___NextPageParam_6;
	// System.String Pico.Platform.Models.MessageArray`1::PreviousPageParam
	String_t* ___PreviousPageParam_7;
};

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.AssetDetails>
struct MessageArray_1_t3588ACF0944917D806087EF192359A96F2EF26D6  : public List_1_t99C4055E7A18C1DF32B7AECA7EE4535206181597
{
	// System.String Pico.Platform.Models.MessageArray`1::NextPageParam
	String_t* ___NextPageParam_6;
	// System.String Pico.Platform.Models.MessageArray`1::PreviousPageParam
	String_t* ___PreviousPageParam_7;
};

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Challenge>
struct MessageArray_1_t3AD15036E7E447220D0A42DE4FB31045C546D530  : public List_1_t1270A6FA80F83E5E821A0DAE5FB3C06865ACB59C
{
	// System.String Pico.Platform.Models.MessageArray`1::NextPageParam
	String_t* ___NextPageParam_6;
	// System.String Pico.Platform.Models.MessageArray`1::PreviousPageParam
	String_t* ___PreviousPageParam_7;
};

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.ChallengeEntry>
struct MessageArray_1_t7879F9CC787398F1DCC478C7DFC9D19EB4D4837E  : public List_1_t3A2B2890CB7F9F96B159F90ED3C352D0F69BFC03
{
	// System.String Pico.Platform.Models.MessageArray`1::NextPageParam
	String_t* ___NextPageParam_6;
	// System.String Pico.Platform.Models.MessageArray`1::PreviousPageParam
	String_t* ___PreviousPageParam_7;
};

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Destination>
struct MessageArray_1_t77601FC32D4AB8164AF6BDA2F26DA8D5510A8C1D  : public List_1_t5C085F464CB50B6E73049AC6D994648AA7E2410E
{
	// System.String Pico.Platform.Models.MessageArray`1::NextPageParam
	String_t* ___NextPageParam_6;
	// System.String Pico.Platform.Models.MessageArray`1::PreviousPageParam
	String_t* ___PreviousPageParam_7;
};

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Leaderboard>
struct MessageArray_1_tF4173B1C53148BB935C764587034896F121CCA0A  : public List_1_t724694C0B4027B186B04C28FF07C047043904083
{
	// System.String Pico.Platform.Models.MessageArray`1::NextPageParam
	String_t* ___NextPageParam_6;
	// System.String Pico.Platform.Models.MessageArray`1::PreviousPageParam
	String_t* ___PreviousPageParam_7;
};

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.LeaderboardEntry>
struct MessageArray_1_tB8E04BD481F9ACE36C3AC7750EC6E3168CF6ED31  : public List_1_tC943684C0EBEF2BD2CFD9D2B29FC554E51FBB6A8
{
	// System.String Pico.Platform.Models.MessageArray`1::NextPageParam
	String_t* ___NextPageParam_6;
	// System.String Pico.Platform.Models.MessageArray`1::PreviousPageParam
	String_t* ___PreviousPageParam_7;
};

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.MatchmakingAdminSnapshotCandidate>
struct MessageArray_1_tE23B1EF897AC360EF5B5030E9C24FB894F1930F1  : public List_1_tABBB0A07DB48EE3A69D8AE19FD395C748196C1A1
{
	// System.String Pico.Platform.Models.MessageArray`1::NextPageParam
	String_t* ___NextPageParam_6;
	// System.String Pico.Platform.Models.MessageArray`1::PreviousPageParam
	String_t* ___PreviousPageParam_7;
};

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.MatchmakingRoom>
struct MessageArray_1_t8EC5BA1648CB587D9A9B26B0134F98287F69DB97  : public List_1_tA41CDF0D6A3ED7853A9F821A69838D214E8DD5CB
{
	// System.String Pico.Platform.Models.MessageArray`1::NextPageParam
	String_t* ___NextPageParam_6;
	// System.String Pico.Platform.Models.MessageArray`1::PreviousPageParam
	String_t* ___PreviousPageParam_7;
};

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Product>
struct MessageArray_1_tC6F5900777FE83D0B145BC0F27D11D16A33673A0  : public List_1_tECB4BC629C4B6ABBCAC7C8ADCEFEBA5518203F3C
{
	// System.String Pico.Platform.Models.MessageArray`1::NextPageParam
	String_t* ___NextPageParam_6;
	// System.String Pico.Platform.Models.MessageArray`1::PreviousPageParam
	String_t* ___PreviousPageParam_7;
};

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Purchase>
struct MessageArray_1_t05AA39A5AA11CCE42EA326113EC8CB01D26F8E92  : public List_1_t0BED0F374F8819664848045406304C5C43B290F8
{
	// System.String Pico.Platform.Models.MessageArray`1::NextPageParam
	String_t* ___NextPageParam_6;
	// System.String Pico.Platform.Models.MessageArray`1::PreviousPageParam
	String_t* ___PreviousPageParam_7;
};

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Room>
struct MessageArray_1_t13175CA17EF1C58A6CE16C1C5CC33E66B189C0DB  : public List_1_t17BC494950CA211E4E00DDC3979C43A2750F5DF8
{
	// System.String Pico.Platform.Models.MessageArray`1::NextPageParam
	String_t* ___NextPageParam_6;
	// System.String Pico.Platform.Models.MessageArray`1::PreviousPageParam
	String_t* ___PreviousPageParam_7;
};

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.RoomInviteNotification>
struct MessageArray_1_t48F2634F7CE492870D7F60BCDB4ECBAEABA4E185  : public List_1_t56C8E4CBC81C6319DB682BE3E114E43F68C3AB09
{
	// System.String Pico.Platform.Models.MessageArray`1::NextPageParam
	String_t* ___NextPageParam_6;
	// System.String Pico.Platform.Models.MessageArray`1::PreviousPageParam
	String_t* ___PreviousPageParam_7;
};

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.SportDailySummary>
struct MessageArray_1_t50FAA95B2043C09E0B1018F924FCDEAD40EDFE38  : public List_1_t6C36B6FAA48E5DAE13D84C1C2C9D39AEEF86399F
{
	// System.String Pico.Platform.Models.MessageArray`1::NextPageParam
	String_t* ___NextPageParam_6;
	// System.String Pico.Platform.Models.MessageArray`1::PreviousPageParam
	String_t* ___PreviousPageParam_7;
};

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.User>
struct MessageArray_1_t3FBFD71C2ED89BC1E98F61EFDB0C5C6DADE06A17  : public List_1_tA51A980F281692A23CBC3DFCF8131D4AD8565A1C
{
	// System.String Pico.Platform.Models.MessageArray`1::NextPageParam
	String_t* ___NextPageParam_6;
	// System.String Pico.Platform.Models.MessageArray`1::PreviousPageParam
	String_t* ___PreviousPageParam_7;
};

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.UserRoom>
struct MessageArray_1_tBDB39162E4555FCBD64BB106117908AC8831F004  : public List_1_t68B676CB2F1554E5228FD7A20B97B490395C7E2C
{
	// System.String Pico.Platform.Models.MessageArray`1::NextPageParam
	String_t* ___NextPageParam_6;
	// System.String Pico.Platform.Models.MessageArray`1::PreviousPageParam
	String_t* ___PreviousPageParam_7;
};

// Pico.Platform.Task`1<Pico.Platform.Models.EntitlementCheckResult>
struct Task_1_t6577C6759208FE196021557BB439FE81946FDB36  : public Task_t4FEBAE6911008FF1A81989732EF0BAC5BCD1E5D2
{
};

// Pico.Platform.Task`1<Pico.Platform.Models.LaunchFriendResult>
struct Task_1_t89353573F66DF40A563FFC7023237C238E5D7F0D  : public Task_t4FEBAE6911008FF1A81989732EF0BAC5BCD1E5D2
{
};

// Pico.Platform.Task`1<Pico.Platform.Models.OrgScopedID>
struct Task_1_tED4A061EA242D6FF39FF61442A0E7F55A6880B2E  : public Task_t4FEBAE6911008FF1A81989732EF0BAC5BCD1E5D2
{
};

// Pico.Platform.Task`1<Pico.Platform.Models.PermissionResult>
struct Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF  : public Task_t4FEBAE6911008FF1A81989732EF0BAC5BCD1E5D2
{
};

// Pico.Platform.Task`1<Pico.Platform.PlatformInitializeResult>
struct Task_1_t733E89BDEF2E1BD0B822AE037A0F380656723ACE  : public Task_t4FEBAE6911008FF1A81989732EF0BAC5BCD1E5D2
{
};

// Pico.Platform.Task`1<Pico.Platform.Models.SportDailySummaryList>
struct Task_1_t1B98E66164E4AE432D604C7B75AF7848981FF051  : public Task_t4FEBAE6911008FF1A81989732EF0BAC5BCD1E5D2
{
};

// Pico.Platform.Task`1<Pico.Platform.Models.SportSummary>
struct Task_1_tB6CDA113D3E1699F4874976AC36FB7624B4F9244  : public Task_t4FEBAE6911008FF1A81989732EF0BAC5BCD1E5D2
{
};

// Pico.Platform.Task`1<Pico.Platform.Models.SportUserInfo>
struct Task_1_t1B92E95AEAE34C4D979EA9DC46E4A0B69313B747  : public Task_t4FEBAE6911008FF1A81989732EF0BAC5BCD1E5D2
{
};

// Pico.Platform.Task`1<System.String>
struct Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF  : public Task_t4FEBAE6911008FF1A81989732EF0BAC5BCD1E5D2
{
};

// Pico.Platform.Task`1<Pico.Platform.Models.User>
struct Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42  : public Task_t4FEBAE6911008FF1A81989732EF0BAC5BCD1E5D2
{
};

// Pico.Platform.Task`1<Pico.Platform.Models.UserList>
struct Task_1_tEFD858E38F809577D01E5C61C4E04401C1579F24  : public Task_t4FEBAE6911008FF1A81989732EF0BAC5BCD1E5D2
{
};

// Pico.Platform.Task`1<Pico.Platform.Models.UserRelationResult>
struct Task_1_tB4B0FA80F5FD7ED902B09091C88E2146F2BAE9C1  : public Task_t4FEBAE6911008FF1A81989732EF0BAC5BCD1E5D2
{
};

// Pico.Platform.Task`1<Pico.Platform.Models.UserRoomList>
struct Task_1_t63D243DB7237B9BDC42B877FB86F30ABDF4C37EF  : public Task_t4FEBAE6911008FF1A81989732EF0BAC5BCD1E5D2
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

// System.DateTime
struct DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D 
{
	// System.UInt64 System.DateTime::_dateData
	uint64_t ____dateData_46;
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

// System.UIntPtr
struct UIntPtr_t 
{
	// System.Void* System.UIntPtr::_pointer
	void* ____pointer_1;
};

// Pico.Platform.Models.UserRelationResult
struct UserRelationResult_t4C1646A5BAF0830D84E5A417EAB9BD502A1ACD3D  : public Dictionary_2_tFFB4984E3277B96D7DD77603CA615351CE58744C
{
};

// UnityEngine.Vector4
struct Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 
{
	// System.Single UnityEngine.Vector4::x
	float ___x_1;
	// System.Single UnityEngine.Vector4::y
	float ___y_2;
	// System.Single UnityEngine.Vector4::z
	float ___z_3;
	// System.Single UnityEngine.Vector4::w
	float ___w_4;
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

// Pico.Platform.Models.AchievementDefinitionList
struct AchievementDefinitionList_t8C4BD92DEDBC06F39E7584124E90000B86B41744  : public MessageArray_1_t007C8F0F960A812D5EBEBD1E0DEB87A40D9F0051
{
	// System.UInt64 Pico.Platform.Models.AchievementDefinitionList::TotalSize
	uint64_t ___TotalSize_8;
};

// Pico.Platform.Models.AchievementProgress
struct AchievementProgress_t1E252101294D86D61BE435D76B192BE5E85F67DB  : public RuntimeObject
{
	// System.UInt64 Pico.Platform.Models.AchievementProgress::ID
	uint64_t ___ID_0;
	// System.String Pico.Platform.Models.AchievementProgress::Bitfield
	String_t* ___Bitfield_1;
	// System.Int64 Pico.Platform.Models.AchievementProgress::Count
	int64_t ___Count_2;
	// System.Boolean Pico.Platform.Models.AchievementProgress::IsUnlocked
	bool ___IsUnlocked_3;
	// System.String Pico.Platform.Models.AchievementProgress::Name
	String_t* ___Name_4;
	// System.DateTime Pico.Platform.Models.AchievementProgress::UnlockTime
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___UnlockTime_5;
	// System.Byte[] Pico.Platform.Models.AchievementProgress::ExtraData
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___ExtraData_6;
};

// Pico.Platform.Models.AchievementProgressList
struct AchievementProgressList_t5C10551DC794BBA8F5FF05832B2D044B40447504  : public MessageArray_1_tA2FC832E9F92BC2639E48F182ED14B04435430CA
{
	// System.UInt64 Pico.Platform.Models.AchievementProgressList::TotalSize
	uint64_t ___TotalSize_8;
};

// Pico.Platform.AchievementType
struct AchievementType_tEA5F508A1F095AEB5A69E821011B68EB91D08BAF 
{
	// System.Int32 Pico.Platform.AchievementType::value__
	int32_t ___value___2;
};

// Pico.Platform.AchievementWritePolicy
struct AchievementWritePolicy_t2F5A3D341E26EC9D0EB8612712A7B6E69F1ED106 
{
	// System.Int32 Pico.Platform.AchievementWritePolicy::value__
	int32_t ___value___2;
};

// Pico.Platform.AddonsType
struct AddonsType_t3EB1EDDB46AE8232D5AF777D437AA5DE7E94944E 
{
	// System.Int32 Pico.Platform.AddonsType::value__
	int32_t ___value___2;
};

// Unity.Collections.Allocator
struct Allocator_t996642592271AAD9EE688F142741D512C07B5824 
{
	// System.Int32 Unity.Collections.Allocator::value__
	int32_t ___value___2;
};

// Pico.Platform.Models.ApplicationInviteList
struct ApplicationInviteList_tCFA701E5249821E8B9BBFD13F595859AFFAB19DB  : public MessageArray_1_tBD7F57C2576E156E6CA055C10BDF9CF1A640AAB8
{
};

// Pico.Platform.AsrEngineInitResult
struct AsrEngineInitResult_t355966672E519A8C49220817FC1899EE7F76324B 
{
	// System.Int32 Pico.Platform.AsrEngineInitResult::value__
	int32_t ___value___2;
};

// Pico.Platform.Models.AssetDetailsList
struct AssetDetailsList_tB4AE1D412F214C001FEA90572C4244B92F4CF797  : public MessageArray_1_t3588ACF0944917D806087EF192359A96F2EF26D6
{
};

// Pico.Platform.AssetFileDownloadCompleteStatus
struct AssetFileDownloadCompleteStatus_t45128CE79E5A6B9767E6B343006BBDCB5EC110F6 
{
	// System.Int32 Pico.Platform.AssetFileDownloadCompleteStatus::value__
	int32_t ___value___2;
};

// UnityEngine.AsyncOperation
struct AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C  : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D
{
	// System.IntPtr UnityEngine.AsyncOperation::m_Ptr
	intptr_t ___m_Ptr_0;
	// System.Action`1<UnityEngine.AsyncOperation> UnityEngine.AsyncOperation::m_completeCallback
	Action_1_tE8693FF0E67CDBA52BAFB211BFF1844D076ABAFB* ___m_completeCallback_1;
};
// Native definition for P/Invoke marshalling of UnityEngine.AsyncOperation
struct AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C_marshaled_pinvoke : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_pinvoke
{
	intptr_t ___m_Ptr_0;
	Il2CppMethodPointer ___m_completeCallback_1;
};
// Native definition for COM marshalling of UnityEngine.AsyncOperation
struct AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C_marshaled_com : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_com
{
	intptr_t ___m_Ptr_0;
	Il2CppMethodPointer ___m_completeCallback_1;
};

// Pico.Platform.CancelReason
struct CancelReason_tB06F162C1F4EE4C0E2EB4E684F3F33A3F5545651 
{
	// System.Int32 Pico.Platform.CancelReason::value__
	int32_t ___value___2;
};

// UnityEngine.Networking.CertificateHandler
struct CertificateHandler_t148B524FA5DB39F3ABADB181CD420FC505C33804  : public RuntimeObject
{
	// System.IntPtr UnityEngine.Networking.CertificateHandler::m_Ptr
	intptr_t ___m_Ptr_0;
};
// Native definition for P/Invoke marshalling of UnityEngine.Networking.CertificateHandler
struct CertificateHandler_t148B524FA5DB39F3ABADB181CD420FC505C33804_marshaled_pinvoke
{
	intptr_t ___m_Ptr_0;
};
// Native definition for COM marshalling of UnityEngine.Networking.CertificateHandler
struct CertificateHandler_t148B524FA5DB39F3ABADB181CD420FC505C33804_marshaled_com
{
	intptr_t ___m_Ptr_0;
};

// Pico.Platform.ChallengeCreationType
struct ChallengeCreationType_tDEB2773E102C64383319282483D32481E86DCCB7 
{
	// System.Int32 Pico.Platform.ChallengeCreationType::value__
	int32_t ___value___2;
};

// Pico.Platform.Models.ChallengeEntry
struct ChallengeEntry_t16F06D309BE271B368F93F4F66001E1270B6EEAB  : public RuntimeObject
{
	// System.String Pico.Platform.Models.ChallengeEntry::DisplayScore
	String_t* ___DisplayScore_0;
	// System.Byte[] Pico.Platform.Models.ChallengeEntry::ExtraData
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___ExtraData_1;
	// System.UInt64 Pico.Platform.Models.ChallengeEntry::ID
	uint64_t ___ID_2;
	// System.Int32 Pico.Platform.Models.ChallengeEntry::Rank
	int32_t ___Rank_3;
	// System.Int64 Pico.Platform.Models.ChallengeEntry::Score
	int64_t ___Score_4;
	// System.DateTime Pico.Platform.Models.ChallengeEntry::Timestamp
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___Timestamp_5;
	// Pico.Platform.Models.User Pico.Platform.Models.ChallengeEntry::User
	User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4* ___User_6;
};

// Pico.Platform.Models.ChallengeEntryList
struct ChallengeEntryList_tF2741C9A3F98553DC191BB26844528DC5525BB87  : public MessageArray_1_t7879F9CC787398F1DCC478C7DFC9D19EB4D4837E
{
	// System.UInt64 Pico.Platform.Models.ChallengeEntryList::TotalCount
	uint64_t ___TotalCount_8;
};

// Pico.Platform.Models.ChallengeList
struct ChallengeList_t46D99E7063774C36EF661DC3875AADDFC03E12D2  : public MessageArray_1_t3AD15036E7E447220D0A42DE4FB31045C546D530
{
	// System.UInt64 Pico.Platform.Models.ChallengeList::TotalCount
	uint64_t ___TotalCount_8;
};

// Pico.Platform.Models.ChallengeOptions
struct ChallengeOptions_t9A8A307A2A43C1E1022510A14E02515DF5191DD8  : public RuntimeObject
{
	// System.IntPtr Pico.Platform.Models.ChallengeOptions::Handle
	intptr_t ___Handle_0;
};

// Pico.Platform.ChallengeViewerFilter
struct ChallengeViewerFilter_tC60A72AB3526448D89CB2E0E5F5F7CF5B847D661 
{
	// System.Int32 Pico.Platform.ChallengeViewerFilter::value__
	int32_t ___value___2;
};

// Pico.Platform.ChallengeVisibility
struct ChallengeVisibility_t9549F35CF3B1813151EE174AD66F669507421C76 
{
	// System.Int32 Pico.Platform.ChallengeVisibility::value__
	int32_t ___value___2;
};

// UnityEngine.Coroutine
struct Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B  : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D
{
	// System.IntPtr UnityEngine.Coroutine::m_Ptr
	intptr_t ___m_Ptr_0;
};
// Native definition for P/Invoke marshalling of UnityEngine.Coroutine
struct Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B_marshaled_pinvoke : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_pinvoke
{
	intptr_t ___m_Ptr_0;
};
// Native definition for COM marshalling of UnityEngine.Coroutine
struct Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B_marshaled_com : public YieldInstruction_tFCE35FD0907950EFEE9BC2890AC664E41C53728D_marshaled_com
{
	intptr_t ___m_Ptr_0;
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

// Pico.Platform.Models.DestinationList
struct DestinationList_t41BB93309FA194DCC59A75DF41CE7FE6FC8E08EF  : public MessageArray_1_t77601FC32D4AB8164AF6BDA2F26DA8D5510A8C1D
{
};

// Pico.Platform.DiscountType
struct DiscountType_t0EF4F031D0D1BF487E82A4A48BFD2C4D54C72D29 
{
	// System.Int32 Pico.Platform.DiscountType::value__
	int32_t ___value___2;
};

// UnityEngine.Networking.DownloadHandler
struct DownloadHandler_t1B56C7D3F65D97A1E4B566A14A1E783EA8AE4EBB  : public RuntimeObject
{
	// System.IntPtr UnityEngine.Networking.DownloadHandler::m_Ptr
	intptr_t ___m_Ptr_0;
};
// Native definition for P/Invoke marshalling of UnityEngine.Networking.DownloadHandler
struct DownloadHandler_t1B56C7D3F65D97A1E4B566A14A1E783EA8AE4EBB_marshaled_pinvoke
{
	intptr_t ___m_Ptr_0;
};
// Native definition for COM marshalling of UnityEngine.Networking.DownloadHandler
struct DownloadHandler_t1B56C7D3F65D97A1E4B566A14A1E783EA8AE4EBB_marshaled_com
{
	intptr_t ___m_Ptr_0;
};

// Pico.Platform.EntitlementStatus
struct EntitlementStatus_tC4057550BD7FD5D0CB1D735C164A0A3702350AD5 
{
	// System.Int32 Pico.Platform.EntitlementStatus::value__
	int32_t ___value___2;
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

// Pico.Platform.Gender
struct Gender_t52F6587FE389C083CA2AE269BE44C2A0F061CF62 
{
	// System.Int32 Pico.Platform.Gender::value__
	int32_t ___value___2;
};

// System.Int32Enum
struct Int32Enum_tCBAC8BA2BFF3A845FA599F303093BBBA374B6F0C 
{
	// System.Int32 System.Int32Enum::value__
	int32_t ___value___2;
};

// Pico.Platform.Models.KVPair
struct KVPair_t3B78D7F4C5A144597A4D25D3E998B119380117F0  : public RuntimeObject
{
	// System.IntPtr Pico.Platform.Models.KVPair::Handle
	intptr_t ___Handle_0;
	// System.Boolean Pico.Platform.Models.KVPair::destroyable
	bool ___destroyable_1;
};

// Pico.Platform.Models.KVPairArray
struct KVPairArray_t2D18141BDF81CCF74F01AD0CD6D940BFF0D65E1F  : public RuntimeObject
{
	// System.UInt32 Pico.Platform.Models.KVPairArray::<Size>k__BackingField
	uint32_t ___U3CSizeU3Ek__BackingField_0;
	// System.IntPtr Pico.Platform.Models.KVPairArray::Handle
	intptr_t ___Handle_1;
};

// Pico.Platform.KVPairType
struct KVPairType_tA45172A6D1D9CB8E462AABF3594CB44DB38B931A 
{
	// System.Int32 Pico.Platform.KVPairType::value__
	int32_t ___value___2;
};

// Pico.Platform.LaunchType
struct LaunchType_tF0CB7F487B723A3891591E1267F875246156E40C 
{
	// System.Int32 Pico.Platform.LaunchType::value__
	int32_t ___value___2;
};

// Pico.Platform.Models.LeaderboardEntry
struct LeaderboardEntry_tDFA599CDDC7EC20F2041B9BCF885BAE5A8B7DF9F  : public RuntimeObject
{
	// System.String Pico.Platform.Models.LeaderboardEntry::DisplayScore
	String_t* ___DisplayScore_0;
	// System.Byte[] Pico.Platform.Models.LeaderboardEntry::ExtraData
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___ExtraData_1;
	// System.UInt64 Pico.Platform.Models.LeaderboardEntry::ID
	uint64_t ___ID_2;
	// System.Int32 Pico.Platform.Models.LeaderboardEntry::Rank
	int32_t ___Rank_3;
	// System.Int64 Pico.Platform.Models.LeaderboardEntry::Score
	int64_t ___Score_4;
	// Pico.Platform.Models.SupplementaryMetric Pico.Platform.Models.LeaderboardEntry::SupplementaryMetricOptional
	SupplementaryMetric_t28C1258D6CB519A099746C713C51A1F14C2C242A* ___SupplementaryMetricOptional_5;
	// System.DateTime Pico.Platform.Models.LeaderboardEntry::Timestamp
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___Timestamp_6;
	// Pico.Platform.Models.User Pico.Platform.Models.LeaderboardEntry::User
	User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4* ___User_7;
};

// Pico.Platform.Models.LeaderboardEntryList
struct LeaderboardEntryList_t6B5536586844053D032CB41222DC969C7FC0DC8D  : public MessageArray_1_tB8E04BD481F9ACE36C3AC7750EC6E3168CF6ED31
{
	// System.UInt64 Pico.Platform.Models.LeaderboardEntryList::TotalCount
	uint64_t ___TotalCount_8;
};

// Pico.Platform.Models.LeaderboardList
struct LeaderboardList_t8BED638069122AD476155B80846591364CB07B06  : public MessageArray_1_tF4173B1C53148BB935C764587034896F121CCA0A
{
	// System.UInt64 Pico.Platform.Models.LeaderboardList::TotalCount
	uint64_t ___TotalCount_8;
};

// Pico.Platform.Models.MatchmakingAdminSnapshotCandidateList
struct MatchmakingAdminSnapshotCandidateList_tCB8BE369951F7307CA9A1AF9C7FE4B6253339C94  : public MessageArray_1_tE23B1EF897AC360EF5B5030E9C24FB894F1930F1
{
	// System.UInt64 Pico.Platform.Models.MatchmakingAdminSnapshotCandidateList::TotalCount
	uint64_t ___TotalCount_8;
};

// Pico.Platform.Models.MatchmakingRoomList
struct MatchmakingRoomList_t97325021F617542B368184443F745CC637C866B7  : public MessageArray_1_t8EC5BA1648CB587D9A9B26B0134F98287F69DB97
{
	// System.Int32 Pico.Platform.Models.MatchmakingRoomList::TotalCount
	int32_t ___TotalCount_8;
};

// Pico.Platform.MessageType
struct MessageType_tD05738EB91F71587C5267075B6CC497B6C48DB13 
{
	// System.Int32 Pico.Platform.MessageType::value__
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

// Pico.Platform.Models.Packet
struct Packet_tE7ABCB3CA16D45A82E180266269EC1B89F8054A9  : public RuntimeObject
{
	// System.UInt64 Pico.Platform.Models.Packet::size
	uint64_t ___size_0;
	// System.IntPtr Pico.Platform.Models.Packet::handler
	intptr_t ___handler_1;
};

// Pico.Platform.PeriodType
struct PeriodType_t2461A4CA1700061B20D1D05FE9CCB96A9D8B9238 
{
	// System.Int32 Pico.Platform.PeriodType::value__
	int32_t ___value___2;
};

// Pico.Platform.PlatformInitializeResult
struct PlatformInitializeResult_t24F044FE2324F44AF83DB194C1051EC41F6586C5 
{
	// System.Int32 Pico.Platform.PlatformInitializeResult::value__
	int32_t ___value___2;
};

// Pico.Platform.Models.ProductList
struct ProductList_t60557078ACE42730D11C630A551C5ECF6DD48160  : public MessageArray_1_tC6F5900777FE83D0B145BC0F27D11D16A33673A0
{
};

// Pico.Platform.PtrManager
struct PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2  : public RuntimeObject
{
	// System.IntPtr Pico.Platform.PtrManager::ptr
	intptr_t ___ptr_0;
	// System.Boolean Pico.Platform.PtrManager::freed
	bool ___freed_1;
};

// Pico.Platform.Models.PurchaseList
struct PurchaseList_tE73ABD4A2D17ED67A2A410C78B54519A32A16C03  : public MessageArray_1_t05AA39A5AA11CCE42EA326113EC8CB01D26F8E92
{
};

// Pico.Platform.Models.RoomInviteNotification
struct RoomInviteNotification_t056C5D7720D5A52379CEB33A2BEB26EDB399E048  : public RuntimeObject
{
	// System.UInt64 Pico.Platform.Models.RoomInviteNotification::ID
	uint64_t ___ID_0;
	// System.UInt64 Pico.Platform.Models.RoomInviteNotification::RoomID
	uint64_t ___RoomID_1;
	// System.String Pico.Platform.Models.RoomInviteNotification::SenderID
	String_t* ___SenderID_2;
	// System.DateTime Pico.Platform.Models.RoomInviteNotification::SentTime
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___SentTime_3;
};

// Pico.Platform.Models.RoomInviteNotificationList
struct RoomInviteNotificationList_t1203312F5F6E7E53899A09886C7716CD0C55D9A6  : public MessageArray_1_t48F2634F7CE492870D7F60BCDB4ECBAEABA4E185
{
	// System.Int32 Pico.Platform.Models.RoomInviteNotificationList::TotalCount
	int32_t ___TotalCount_8;
};

// Pico.Platform.RoomJoinPolicy
struct RoomJoinPolicy_tFB9FF0DE9C9979EE930A49B4F80A84F68A4FF591 
{
	// System.Int32 Pico.Platform.RoomJoinPolicy::value__
	int32_t ___value___2;
};

// Pico.Platform.RoomJoinability
struct RoomJoinability_tB866585AF34586B24544CB7C866FF836386710C1 
{
	// System.Int32 Pico.Platform.RoomJoinability::value__
	int32_t ___value___2;
};

// Pico.Platform.Models.RoomList
struct RoomList_t3B275914D4B281B7FAB5C1AD597F11D664367694  : public MessageArray_1_t13175CA17EF1C58A6CE16C1C5CC33E66B189C0DB
{
	// System.Int32 Pico.Platform.Models.RoomList::TotalCount
	int32_t ___TotalCount_8;
	// System.Int32 Pico.Platform.Models.RoomList::CurIndex
	int32_t ___CurIndex_9;
	// System.Int32 Pico.Platform.Models.RoomList::PageSize
	int32_t ___PageSize_10;
};

// Pico.Platform.RoomOptions
struct RoomOptions_tC6C155D94F2675BA84336CA56BCDEBEA022835B7  : public RuntimeObject
{
	// System.IntPtr Pico.Platform.RoomOptions::Handle
	intptr_t ___Handle_0;
};

// Pico.Platform.RoomType
struct RoomType_tA5B85B262F23E7DA0CFFD3190E04437759FA4986 
{
	// System.Int32 Pico.Platform.RoomType::value__
	int32_t ___value___2;
};

// Pico.Platform.RtcAudioChannel
struct RtcAudioChannel_t9FB7E8CDE013A6C4EC9761C72EEC325AE66CA3B7 
{
	// System.Int32 Pico.Platform.RtcAudioChannel::value__
	int32_t ___value___2;
};

// Pico.Platform.RtcAudioPlaybackDevice
struct RtcAudioPlaybackDevice_tDA7F6B0124EA249A9CB7114E16A5144876FA31A9 
{
	// System.Int32 Pico.Platform.RtcAudioPlaybackDevice::value__
	int32_t ___value___2;
};

// Pico.Platform.RtcAudioPropertyOptions
struct RtcAudioPropertyOptions_t5E394E488DDCF996DB82E9326E71B465A4D6D23E  : public RuntimeObject
{
	// System.IntPtr Pico.Platform.RtcAudioPropertyOptions::Handle
	intptr_t ___Handle_0;
};

// Pico.Platform.RtcAudioSampleRate
struct RtcAudioSampleRate_tB435805FA5C3074213F65FBB2BDD13BA22256247 
{
	// System.Int32 Pico.Platform.RtcAudioSampleRate::value__
	int32_t ___value___2;
};

// Pico.Platform.RtcAudioScenarioType
struct RtcAudioScenarioType_t4CEEB27805830CAD3714C88E865A84203986AD41 
{
	// System.Int32 Pico.Platform.RtcAudioScenarioType::value__
	int32_t ___value___2;
};

// Pico.Platform.RtcEarMonitorMode
struct RtcEarMonitorMode_t72900CCE84BE5279164E7277E45533C89975914F 
{
	// System.Int32 Pico.Platform.RtcEarMonitorMode::value__
	int32_t ___value___2;
};

// Pico.Platform.RtcEngineInitResult
struct RtcEngineInitResult_t43963260B4952A0DF85488C332E7FBA6B49A2DD5 
{
	// System.Int32 Pico.Platform.RtcEngineInitResult::value__
	int32_t ___value___2;
};

// Pico.Platform.RtcGetTokenOptions
struct RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0  : public RuntimeObject
{
	// System.IntPtr Pico.Platform.RtcGetTokenOptions::Handle
	intptr_t ___Handle_0;
};

// Pico.Platform.RtcJoinRoomType
struct RtcJoinRoomType_tFF45822D37F37AFFC9AE70D9B1E5B525C65858F5 
{
	// System.Int32 Pico.Platform.RtcJoinRoomType::value__
	int32_t ___value___2;
};

// Pico.Platform.RtcMediaDeviceError
struct RtcMediaDeviceError_t3663EE65C2081BCB818784B6562AFBAFC4D55C95 
{
	// System.Int32 Pico.Platform.RtcMediaDeviceError::value__
	int32_t ___value___2;
};

// Pico.Platform.RtcMediaDeviceState
struct RtcMediaDeviceState_t2A5A45069AB034FCA8799571319AF6A3646877A7 
{
	// System.Int32 Pico.Platform.RtcMediaDeviceState::value__
	int32_t ___value___2;
};

// Pico.Platform.RtcMediaDeviceType
struct RtcMediaDeviceType_t857BA568456607068FBF75464763E7493DA161D1 
{
	// System.Int32 Pico.Platform.RtcMediaDeviceType::value__
	int32_t ___value___2;
};

// Pico.Platform.RtcMediaStreamType
struct RtcMediaStreamType_tDC462729578B27971A877E8310EA834266105387 
{
	// System.Int32 Pico.Platform.RtcMediaStreamType::value__
	int32_t ___value___2;
};

// Pico.Platform.RtcMuteState
struct RtcMuteState_t4421A8FC44C81B925C5D263B7464B0B514FB14FE 
{
	// System.Int32 Pico.Platform.RtcMuteState::value__
	int32_t ___value___2;
};

// Pico.Platform.RtcPauseResumeMediaType
struct RtcPauseResumeMediaType_tA70517A28B21E6A5A94EA33677F7E386D147EFE1 
{
	// System.Int32 Pico.Platform.RtcPauseResumeMediaType::value__
	int32_t ___value___2;
};

// Pico.Platform.RtcPrivilege
struct RtcPrivilege_t14F7BB1AB3E0DAC2BFBEC28F81514E60C35ABCB7 
{
	// System.Int32 Pico.Platform.RtcPrivilege::value__
	int32_t ___value___2;
};

// Pico.Platform.RtcRoomOptions
struct RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A  : public RuntimeObject
{
	// System.String Pico.Platform.RtcRoomOptions::RoomId
	String_t* ___RoomId_0;
	// System.IntPtr Pico.Platform.RtcRoomOptions::Handle
	intptr_t ___Handle_1;
};

// Pico.Platform.RtcRoomProfileType
struct RtcRoomProfileType_t456974D8BF28826965E628D8DF6D0B40796339F0 
{
	// System.Int32 Pico.Platform.RtcRoomProfileType::value__
	int32_t ___value___2;
};

// Pico.Platform.RtcStreamIndex
struct RtcStreamIndex_tF77AC46522EBBB54F7C72CCBB2624AC7A36AFAED 
{
	// System.Int32 Pico.Platform.RtcStreamIndex::value__
	int32_t ___value___2;
};

// Pico.Platform.RtcStreamRemoveReason
struct RtcStreamRemoveReason_tE8A2D29200EAB969983A2C87AFBBEEFC9DBBAF77 
{
	// System.Int32 Pico.Platform.RtcStreamRemoveReason::value__
	int32_t ___value___2;
};

// Pico.Platform.RtcStreamSyncInfoOptions
struct RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073  : public RuntimeObject
{
	// System.IntPtr Pico.Platform.RtcStreamSyncInfoOptions::Handle
	intptr_t ___Handle_0;
};

// Pico.Platform.RtcSyncInfoStreamType
struct RtcSyncInfoStreamType_t1ABF2CB81A75E9BF8C71CA9BAA5E4D17D6B926C0 
{
	// System.Int32 Pico.Platform.RtcSyncInfoStreamType::value__
	int32_t ___value___2;
};

// Pico.Platform.RtcUserLeaveReasonType
struct RtcUserLeaveReasonType_tEDC66D7F5EC535F1683439E79AAD420417A07488 
{
	// System.Int32 Pico.Platform.RtcUserLeaveReasonType::value__
	int32_t ___value___2;
};

// UnityEngine.RuntimePlatform
struct RuntimePlatform_t9A8AAF204603076FCAAECCCC05DA386AEE7BF66E 
{
	// System.Int32 UnityEngine.RuntimePlatform::value__
	int32_t ___value___2;
};

// Pico.Platform.SensitiveProposal
struct SensitiveProposal_t7CEF7211B8F026CFB59FCF0BD0C5D87A6C581FD0 
{
	// System.Int32 Pico.Platform.SensitiveProposal::value__
	int32_t ___value___2;
};

// Pico.Platform.Models.SportDailySummary
struct SportDailySummary_t1202315FC8419F0C908ACF448A0DF4EF207756F0  : public RuntimeObject
{
	// System.Int64 Pico.Platform.Models.SportDailySummary::Id
	int64_t ___Id_0;
	// System.DateTime Pico.Platform.Models.SportDailySummary::Date
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___Date_1;
	// System.Int32 Pico.Platform.Models.SportDailySummary::DurationInSeconds
	int32_t ___DurationInSeconds_2;
	// System.Int32 Pico.Platform.Models.SportDailySummary::PlanDurationInMinutes
	int32_t ___PlanDurationInMinutes_3;
	// System.Double Pico.Platform.Models.SportDailySummary::Calorie
	double ___Calorie_4;
	// System.Double Pico.Platform.Models.SportDailySummary::PlanCalorie
	double ___PlanCalorie_5;
};

// Pico.Platform.Models.SportDailySummaryList
struct SportDailySummaryList_tDB9E5A80ED100417F113C33891F04F9CF8DB5BC6  : public MessageArray_1_t50FAA95B2043C09E0B1018F924FCDEAD40EDFE38
{
};

// Pico.Platform.Models.SportSummary
struct SportSummary_t6193CC64BC93B9813F42F50B37479017FB3067D1  : public RuntimeObject
{
	// System.Int32 Pico.Platform.Models.SportSummary::DurationInSeconds
	int32_t ___DurationInSeconds_0;
	// System.Double Pico.Platform.Models.SportSummary::Calorie
	double ___Calorie_1;
	// System.DateTime Pico.Platform.Models.SportSummary::StartTime
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___StartTime_2;
	// System.DateTime Pico.Platform.Models.SportSummary::EndTime
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___EndTime_3;
};

// Pico.Platform.SportTarget
struct SportTarget_t311B92798B94C8C61CF8B649355CFC5727AD9785 
{
	// System.Int32 Pico.Platform.SportTarget::value__
	int32_t ___value___2;
};

// Pico.Platform.StartAsrOptions
struct StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F  : public RuntimeObject
{
	// System.IntPtr Pico.Platform.StartAsrOptions::Handle
	intptr_t ___Handle_0;
};

// UnityEngine.Networking.UploadHandler
struct UploadHandler_t7E504B1A83346248A0C8C4AF73A893226CB83EF6  : public RuntimeObject
{
	// System.IntPtr UnityEngine.Networking.UploadHandler::m_Ptr
	intptr_t ___m_Ptr_0;
};
// Native definition for P/Invoke marshalling of UnityEngine.Networking.UploadHandler
struct UploadHandler_t7E504B1A83346248A0C8C4AF73A893226CB83EF6_marshaled_pinvoke
{
	intptr_t ___m_Ptr_0;
};
// Native definition for COM marshalling of UnityEngine.Networking.UploadHandler
struct UploadHandler_t7E504B1A83346248A0C8C4AF73A893226CB83EF6_marshaled_com
{
	intptr_t ___m_Ptr_0;
};

// Pico.Platform.Models.UserList
struct UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F  : public MessageArray_1_t3FBFD71C2ED89BC1E98F61EFDB0C5C6DADE06A17
{
};

// Pico.Platform.UserPresenceStatus
struct UserPresenceStatus_t88F19F847438F59EA481A389513434C469926560 
{
	// System.Int32 Pico.Platform.UserPresenceStatus::value__
	int32_t ___value___2;
};

// Pico.Platform.UserRelationType
struct UserRelationType_t1A4FFBC1BF4954E5080B43FEA2A53F3AB8B520F9 
{
	// System.Int32 Pico.Platform.UserRelationType::value__
	int32_t ___value___2;
};

// Pico.Platform.Models.UserRoomList
struct UserRoomList_t4AA0685A4D566E046B275555AC21E1A102C16A73  : public MessageArray_1_tBDB39162E4555FCBD64BB106117908AC8831F004
{
};

// System.Collections.Generic.KeyValuePair`2<System.Int32Enum,System.Int32>
struct KeyValuePair_2_t8119C4668B01DE5BDC84EDBA81EE010B6CA16C5C 
{
	// TKey System.Collections.Generic.KeyValuePair`2::key
	int32_t ___key_0;
	// TValue System.Collections.Generic.KeyValuePair`2::value
	int32_t ___value_1;
};

// System.Collections.Generic.KeyValuePair`2<Pico.Platform.RtcPrivilege,System.Int32>
struct KeyValuePair_2_t3B924E448F08153464BEA8D03A541C9BC936424A 
{
	// TKey System.Collections.Generic.KeyValuePair`2::key
	int32_t ___key_0;
	// TValue System.Collections.Generic.KeyValuePair`2::value
	int32_t ___value_1;
};

// Unity.Collections.NativeArray`1<System.Byte>
struct NativeArray_1_t81F55263465517B73C455D3400CF67B4BADD85CF 
{
	// System.Void* Unity.Collections.NativeArray`1::m_Buffer
	void* ___m_Buffer_0;
	// System.Int32 Unity.Collections.NativeArray`1::m_Length
	int32_t ___m_Length_1;
	// Unity.Collections.Allocator Unity.Collections.NativeArray`1::m_AllocatorLabel
	int32_t ___m_AllocatorLabel_2;
};

// Pico.Platform.Models.AchievementDefinition
struct AchievementDefinition_t09D5E334A9AF0321426DB09B4B36E72626423019  : public RuntimeObject
{
	// Pico.Platform.AchievementType Pico.Platform.Models.AchievementDefinition::Type
	int32_t ___Type_0;
	// System.String Pico.Platform.Models.AchievementDefinition::Name
	String_t* ___Name_1;
	// System.UInt32 Pico.Platform.Models.AchievementDefinition::BitfieldLength
	uint32_t ___BitfieldLength_2;
	// System.Int64 Pico.Platform.Models.AchievementDefinition::Target
	int64_t ___Target_3;
	// System.String Pico.Platform.Models.AchievementDefinition::Description
	String_t* ___Description_4;
	// System.String Pico.Platform.Models.AchievementDefinition::Title
	String_t* ___Title_5;
	// System.Boolean Pico.Platform.Models.AchievementDefinition::IsArchived
	bool ___IsArchived_6;
	// System.Boolean Pico.Platform.Models.AchievementDefinition::IsSecret
	bool ___IsSecret_7;
	// System.UInt64 Pico.Platform.Models.AchievementDefinition::ID
	uint64_t ___ID_8;
	// System.String Pico.Platform.Models.AchievementDefinition::UnlockedDescription
	String_t* ___UnlockedDescription_9;
	// Pico.Platform.AchievementWritePolicy Pico.Platform.Models.AchievementDefinition::WritePolicy
	int32_t ___WritePolicy_10;
	// System.String Pico.Platform.Models.AchievementDefinition::LockedImageURL
	String_t* ___LockedImageURL_11;
	// System.String Pico.Platform.Models.AchievementDefinition::UnlockedImageURL
	String_t* ___UnlockedImageURL_12;
};

// Pico.Platform.Models.AssetFileDownloadUpdate
struct AssetFileDownloadUpdate_tBAD90D69A25568EC45F334942C219ABFBD5DA6E2  : public RuntimeObject
{
	// System.UInt64 Pico.Platform.Models.AssetFileDownloadUpdate::AssetId
	uint64_t ___AssetId_0;
	// System.UInt64 Pico.Platform.Models.AssetFileDownloadUpdate::BytesTotal
	uint64_t ___BytesTotal_1;
	// System.Int64 Pico.Platform.Models.AssetFileDownloadUpdate::BytesTransferred
	int64_t ___BytesTransferred_2;
	// Pico.Platform.AssetFileDownloadCompleteStatus Pico.Platform.Models.AssetFileDownloadUpdate::CompleteStatus
	int32_t ___CompleteStatus_3;
};

// Pico.Platform.Models.Challenge
struct Challenge_t4D4126711B52D78CEDA93B79EC0EFF69927E3971  : public RuntimeObject
{
	// Pico.Platform.ChallengeCreationType Pico.Platform.Models.Challenge::CreationType
	int32_t ___CreationType_0;
	// System.UInt64 Pico.Platform.Models.Challenge::ID
	uint64_t ___ID_1;
	// System.DateTime Pico.Platform.Models.Challenge::StartDate
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___StartDate_2;
	// System.DateTime Pico.Platform.Models.Challenge::EndDate
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___EndDate_3;
	// Pico.Platform.Models.UserList Pico.Platform.Models.Challenge::ParticipantsOptional
	UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F* ___ParticipantsOptional_4;
	// Pico.Platform.Models.UserList Pico.Platform.Models.Challenge::InvitedUsersOptional
	UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F* ___InvitedUsersOptional_5;
	// Pico.Platform.Models.Leaderboard Pico.Platform.Models.Challenge::Leaderboard
	Leaderboard_t6D83DEF000B68074D583D0D92AED4AE1EFB14595* ___Leaderboard_6;
	// System.String Pico.Platform.Models.Challenge::Title
	String_t* ___Title_7;
	// Pico.Platform.ChallengeVisibility Pico.Platform.Models.Challenge::Visibility
	int32_t ___Visibility_8;
};

// UnityEngine.Component
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// Pico.Platform.Models.DetectSensitiveResult
struct DetectSensitiveResult_t3F811A4C213815D1A2E488BCC02B4F0927C06381  : public RuntimeObject
{
	// System.String Pico.Platform.Models.DetectSensitiveResult::FilteredText
	String_t* ___FilteredText_0;
	// Pico.Platform.SensitiveProposal Pico.Platform.Models.DetectSensitiveResult::Proposal
	int32_t ___Proposal_1;
};

// UnityEngine.GameObject
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// Pico.Platform.Models.LaunchDetails
struct LaunchDetails_t83DFB7E65E221A238FA66531C7C470C75FFACE21  : public RuntimeObject
{
	// Pico.Platform.LaunchType Pico.Platform.Models.LaunchDetails::LaunchType
	int32_t ___LaunchType_0;
	// System.String Pico.Platform.Models.LaunchDetails::DeeplinkMessage
	String_t* ___DeeplinkMessage_1;
	// System.String Pico.Platform.Models.LaunchDetails::DestinationApiName
	String_t* ___DestinationApiName_2;
	// System.String Pico.Platform.Models.LaunchDetails::LobbySessionID
	String_t* ___LobbySessionID_3;
	// System.String Pico.Platform.Models.LaunchDetails::MatchSessionID
	String_t* ___MatchSessionID_4;
	// System.String Pico.Platform.Models.LaunchDetails::Extra
	String_t* ___Extra_5;
	// System.UInt64 Pico.Platform.Models.LaunchDetails::RoomID
	uint64_t ___RoomID_6;
	// System.UInt64 Pico.Platform.Models.LaunchDetails::ChallengeID
	uint64_t ___ChallengeID_7;
	// System.String Pico.Platform.Models.LaunchDetails::TrackingID
	String_t* ___TrackingID_8;
};

// UnityEngine.Material
struct Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// Pico.Platform.Message
struct Message_t2DF6F94E79BCFC7D36B4D1219F09D5DF8D241F83  : public RuntimeObject
{
	// Pico.Platform.MessageType Pico.Platform.Message::Type
	int32_t ___Type_0;
	// System.UInt64 Pico.Platform.Message::RequestID
	uint64_t ___RequestID_1;
	// Pico.Platform.Models.Error Pico.Platform.Message::Error
	Error_t3CA63648FA025A8FBA63EA102526BE2F757CAF88* ___Error_2;
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

// Pico.Platform.Models.Product
struct Product_t1507FCF7293FA1250C325F33FEA9C46DBD487D66  : public RuntimeObject
{
	// System.String Pico.Platform.Models.Product::Description
	String_t* ___Description_0;
	// System.String Pico.Platform.Models.Product::DetailDescription
	String_t* ___DetailDescription_1;
	// System.String Pico.Platform.Models.Product::Price
	String_t* ___Price_2;
	// System.String Pico.Platform.Models.Product::Currency
	String_t* ___Currency_3;
	// System.String Pico.Platform.Models.Product::Name
	String_t* ___Name_4;
	// System.String Pico.Platform.Models.Product::SKU
	String_t* ___SKU_5;
	// System.String Pico.Platform.Models.Product::Icon
	String_t* ___Icon_6;
	// Pico.Platform.AddonsType Pico.Platform.Models.Product::AddonsType
	int32_t ___AddonsType_7;
	// Pico.Platform.PeriodType Pico.Platform.Models.Product::PeriodType
	int32_t ___PeriodType_8;
	// Pico.Platform.PeriodType Pico.Platform.Models.Product::TrialPeriodUnit
	int32_t ___TrialPeriodUnit_9;
	// System.Int32 Pico.Platform.Models.Product::TrialPeriodValue
	int32_t ___TrialPeriodValue_10;
	// System.String Pico.Platform.Models.Product::OriginalPrice
	String_t* ___OriginalPrice_11;
	// System.String Pico.Platform.Models.Product::OuterId
	String_t* ___OuterId_12;
	// System.Boolean Pico.Platform.Models.Product::IsContinuous
	bool ___IsContinuous_13;
};

// Pico.Platform.Models.Purchase
struct Purchase_t4EB26AC15A7E0936D3E6722DA01B1DF84A3D469A  : public RuntimeObject
{
	// System.DateTime Pico.Platform.Models.Purchase::ExpirationTime
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___ExpirationTime_0;
	// System.DateTime Pico.Platform.Models.Purchase::GrantTime
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___GrantTime_1;
	// System.String Pico.Platform.Models.Purchase::ID
	String_t* ___ID_2;
	// System.String Pico.Platform.Models.Purchase::SKU
	String_t* ___SKU_3;
	// System.String Pico.Platform.Models.Purchase::Icon
	String_t* ___Icon_4;
	// Pico.Platform.AddonsType Pico.Platform.Models.Purchase::AddonsType
	int32_t ___AddonsType_5;
	// System.String Pico.Platform.Models.Purchase::OuterId
	String_t* ___OuterId_6;
	// Pico.Platform.PeriodType Pico.Platform.Models.Purchase::CurrentPeriodType
	int32_t ___CurrentPeriodType_7;
	// Pico.Platform.PeriodType Pico.Platform.Models.Purchase::NextPeriodType
	int32_t ___NextPeriodType_8;
	// System.DateTime Pico.Platform.Models.Purchase::NextPayTime
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___NextPayTime_9;
	// Pico.Platform.DiscountType Pico.Platform.Models.Purchase::DiscountType
	int32_t ___DiscountType_10;
	// System.String Pico.Platform.Models.Purchase::OrderComment
	String_t* ___OrderComment_11;
};

// Pico.Platform.Models.Room
struct Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135  : public RuntimeObject
{
	// System.Collections.Generic.Dictionary`2<System.String,System.String> Pico.Platform.Models.Room::DataStore
	Dictionary_2_t46B2DB028096FA2B828359E52F37F3105A83AD83* ___DataStore_0;
	// System.String Pico.Platform.Models.Room::Description
	String_t* ___Description_1;
	// System.UInt64 Pico.Platform.Models.Room::RoomId
	uint64_t ___RoomId_2;
	// System.Boolean Pico.Platform.Models.Room::IsMembershipLocked
	bool ___IsMembershipLocked_3;
	// Pico.Platform.RoomJoinPolicy Pico.Platform.Models.Room::RoomJoinPolicy
	int32_t ___RoomJoinPolicy_4;
	// Pico.Platform.RoomJoinability Pico.Platform.Models.Room::RoomJoinability
	int32_t ___RoomJoinability_5;
	// System.UInt32 Pico.Platform.Models.Room::MaxUsers
	uint32_t ___MaxUsers_6;
	// Pico.Platform.Models.User Pico.Platform.Models.Room::OwnerOptional
	User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4* ___OwnerOptional_7;
	// Pico.Platform.RoomType Pico.Platform.Models.Room::RoomType
	int32_t ___RoomType_8;
	// Pico.Platform.Models.UserList Pico.Platform.Models.Room::UsersOptional
	UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F* ___UsersOptional_9;
	// System.String Pico.Platform.Models.Room::Name
	String_t* ___Name_10;
	// System.UInt32 Pico.Platform.Models.Room::PlayerNumber
	uint32_t ___PlayerNumber_11;
};

// Pico.Platform.Models.RtcAudioFrame
struct RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59  : public RuntimeObject
{
	// Pico.Platform.RtcAudioChannel Pico.Platform.Models.RtcAudioFrame::Channel
	int32_t ___Channel_0;
	// System.IntPtr Pico.Platform.Models.RtcAudioFrame::Data
	intptr_t ___Data_1;
	// System.Int64 Pico.Platform.Models.RtcAudioFrame::DataSize
	int64_t ___DataSize_2;
	// Pico.Platform.RtcAudioSampleRate Pico.Platform.Models.RtcAudioFrame::SampleRate
	int32_t ___SampleRate_3;
	// System.Int64 Pico.Platform.Models.RtcAudioFrame::TimeStampInUs
	int64_t ___TimeStampInUs_4;
};

// Pico.Platform.Models.RtcJoinRoomResult
struct RtcJoinRoomResult_t7B3739D043DA3F0754EA07F27CC81279A5673D3C  : public RuntimeObject
{
	// System.String Pico.Platform.Models.RtcJoinRoomResult::RoomId
	String_t* ___RoomId_0;
	// System.String Pico.Platform.Models.RtcJoinRoomResult::UserId
	String_t* ___UserId_1;
	// System.Int32 Pico.Platform.Models.RtcJoinRoomResult::ErrorCode
	int32_t ___ErrorCode_2;
	// System.Int32 Pico.Platform.Models.RtcJoinRoomResult::Elapsed
	int32_t ___Elapsed_3;
	// Pico.Platform.RtcJoinRoomType Pico.Platform.Models.RtcJoinRoomResult::JoinType
	int32_t ___JoinType_4;
};

// Pico.Platform.Models.RtcLocalAudioPropertiesInfo
struct RtcLocalAudioPropertiesInfo_tDEE2268599EA8C3EC747871F690C5743321ED49E  : public RuntimeObject
{
	// Pico.Platform.RtcStreamIndex Pico.Platform.Models.RtcLocalAudioPropertiesInfo::StreamIndex
	int32_t ___StreamIndex_0;
	// Pico.Platform.Models.RtcAudioPropertyInfo Pico.Platform.Models.RtcLocalAudioPropertiesInfo::AudioPropertyInfo
	RtcAudioPropertyInfo_tA10BA2C71B943D7A31ED99324B58ECBC13C05268* ___AudioPropertyInfo_1;
};

// Pico.Platform.Models.RtcMediaDeviceChangeInfo
struct RtcMediaDeviceChangeInfo_tB2715659230514BAEF53E2329D648EC92B790850  : public RuntimeObject
{
	// System.String Pico.Platform.Models.RtcMediaDeviceChangeInfo::DeviceId
	String_t* ___DeviceId_0;
	// Pico.Platform.RtcMediaDeviceType Pico.Platform.Models.RtcMediaDeviceChangeInfo::DeviceType
	int32_t ___DeviceType_1;
	// Pico.Platform.RtcMediaDeviceState Pico.Platform.Models.RtcMediaDeviceChangeInfo::DeviceState
	int32_t ___DeviceState_2;
	// Pico.Platform.RtcMediaDeviceError Pico.Platform.Models.RtcMediaDeviceChangeInfo::DeviceError
	int32_t ___DeviceError_3;
};

// Pico.Platform.Models.RtcMuteInfo
struct RtcMuteInfo_t42EFA88A13E9A461000A46AEE9B3BD8017AC5416  : public RuntimeObject
{
	// System.String Pico.Platform.Models.RtcMuteInfo::UserId
	String_t* ___UserId_0;
	// Pico.Platform.RtcMuteState Pico.Platform.Models.RtcMuteInfo::MuteState
	int32_t ___MuteState_1;
};

// Pico.Platform.Models.RtcRemoteStreamKey
struct RtcRemoteStreamKey_tA69532F8EF7C977014612F775D146C3038C61E0E  : public RuntimeObject
{
	// System.String Pico.Platform.Models.RtcRemoteStreamKey::RoomId
	String_t* ___RoomId_0;
	// System.String Pico.Platform.Models.RtcRemoteStreamKey::UserId
	String_t* ___UserId_1;
	// Pico.Platform.RtcStreamIndex Pico.Platform.Models.RtcRemoteStreamKey::RtcStreamIndex
	int32_t ___RtcStreamIndex_2;
};

// Pico.Platform.Models.RtcStreamSyncInfo
struct RtcStreamSyncInfo_tDF6615A963654FDED33B6E427CC2377459A814C8  : public RuntimeObject
{
	// Pico.Platform.Models.RtcRemoteStreamKey Pico.Platform.Models.RtcStreamSyncInfo::StreamKey
	RtcRemoteStreamKey_tA69532F8EF7C977014612F775D146C3038C61E0E* ___StreamKey_0;
	// Pico.Platform.RtcSyncInfoStreamType Pico.Platform.Models.RtcStreamSyncInfo::StreamType
	int32_t ___StreamType_1;
	// System.Byte[] Pico.Platform.Models.RtcStreamSyncInfo::Data
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___Data_2;
};

// Pico.Platform.Models.RtcUserLeaveInfo
struct RtcUserLeaveInfo_tC24C9CCF5AEE733D5431F5C973C813C2C36C54FE  : public RuntimeObject
{
	// System.String Pico.Platform.Models.RtcUserLeaveInfo::UserId
	String_t* ___UserId_0;
	// Pico.Platform.RtcUserLeaveReasonType Pico.Platform.Models.RtcUserLeaveInfo::OfflineReason
	int32_t ___OfflineReason_1;
	// System.String Pico.Platform.Models.RtcUserLeaveInfo::RoomId
	String_t* ___RoomId_2;
};

// Pico.Platform.Models.RtcUserPublishInfo
struct RtcUserPublishInfo_t8873B6131F1DFF54983FEA638F386647C53ABE2F  : public RuntimeObject
{
	// System.String Pico.Platform.Models.RtcUserPublishInfo::UserId
	String_t* ___UserId_0;
	// Pico.Platform.RtcMediaStreamType Pico.Platform.Models.RtcUserPublishInfo::MediaStreamType
	int32_t ___MediaStreamType_1;
	// System.String Pico.Platform.Models.RtcUserPublishInfo::RoomId
	String_t* ___RoomId_2;
};

// Pico.Platform.Models.RtcUserUnPublishInfo
struct RtcUserUnPublishInfo_tF48236E711888E683F08D6FC0716FE12A582E99A  : public RuntimeObject
{
	// System.String Pico.Platform.Models.RtcUserUnPublishInfo::UserId
	String_t* ___UserId_0;
	// Pico.Platform.RtcMediaStreamType Pico.Platform.Models.RtcUserUnPublishInfo::MediaStreamType
	int32_t ___MediaStreamType_1;
	// Pico.Platform.RtcStreamRemoveReason Pico.Platform.Models.RtcUserUnPublishInfo::Reason
	int32_t ___Reason_2;
	// System.String Pico.Platform.Models.RtcUserUnPublishInfo::RoomId
	String_t* ___RoomId_3;
};

// Pico.Platform.Models.SportUserInfo
struct SportUserInfo_tFA26719517B940DC321942A68AE48D23AFAE5D78  : public RuntimeObject
{
	// Pico.Platform.Gender Pico.Platform.Models.SportUserInfo::Gender
	int32_t ___Gender_0;
	// System.DateTime Pico.Platform.Models.SportUserInfo::Birthday
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___Birthday_1;
	// System.Int32 Pico.Platform.Models.SportUserInfo::Stature
	int32_t ___Stature_2;
	// System.Int32 Pico.Platform.Models.SportUserInfo::Weight
	int32_t ___Weight_3;
	// System.Int32 Pico.Platform.Models.SportUserInfo::SportLevel
	int32_t ___SportLevel_4;
	// System.Int32 Pico.Platform.Models.SportUserInfo::DailyDurationInMinutes
	int32_t ___DailyDurationInMinutes_5;
	// System.Int32 Pico.Platform.Models.SportUserInfo::DaysPerWeek
	int32_t ___DaysPerWeek_6;
	// Pico.Platform.SportTarget Pico.Platform.Models.SportUserInfo::SportTarget
	int32_t ___SportTarget_7;
};

// Pico.Platform.Models.SubscriptionStatus
struct SubscriptionStatus_tB2999CB0297F3E98A32D66E36872B688BD5ABA17  : public RuntimeObject
{
	// System.String Pico.Platform.Models.SubscriptionStatus::SKU
	String_t* ___SKU_0;
	// System.String Pico.Platform.Models.SubscriptionStatus::OuterId
	String_t* ___OuterId_1;
	// System.DateTime Pico.Platform.Models.SubscriptionStatus::StartTime
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___StartTime_2;
	// System.DateTime Pico.Platform.Models.SubscriptionStatus::EndTime
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___EndTime_3;
	// Pico.Platform.PeriodType Pico.Platform.Models.SubscriptionStatus::PeriodType
	int32_t ___PeriodType_4;
	// Pico.Platform.EntitlementStatus Pico.Platform.Models.SubscriptionStatus::EntitlementStatus
	int32_t ___EntitlementStatus_5;
	// Pico.Platform.CancelReason Pico.Platform.Models.SubscriptionStatus::CancelReason
	int32_t ___CancelReason_6;
	// System.Boolean Pico.Platform.Models.SubscriptionStatus::IsFreeTrial
	bool ___IsFreeTrial_7;
	// System.Int32 Pico.Platform.Models.SubscriptionStatus::NextPeriod
	int32_t ___NextPeriod_8;
};

// System.SystemException
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};

// UnityEngine.Texture
struct Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// UnityEngine.UnityException
struct UnityException_tA1EC1E95ADE689CF6EB7FAFF77C160AE1F559067  : public Exception_t
{
};

// UnityEngine.Networking.UnityWebRequest
struct UnityWebRequest_t6233B8E22992FC2364A831C1ACB033EF3260C39F  : public RuntimeObject
{
	// System.IntPtr UnityEngine.Networking.UnityWebRequest::m_Ptr
	intptr_t ___m_Ptr_0;
	// UnityEngine.Networking.DownloadHandler UnityEngine.Networking.UnityWebRequest::m_DownloadHandler
	DownloadHandler_t1B56C7D3F65D97A1E4B566A14A1E783EA8AE4EBB* ___m_DownloadHandler_1;
	// UnityEngine.Networking.UploadHandler UnityEngine.Networking.UnityWebRequest::m_UploadHandler
	UploadHandler_t7E504B1A83346248A0C8C4AF73A893226CB83EF6* ___m_UploadHandler_2;
	// UnityEngine.Networking.CertificateHandler UnityEngine.Networking.UnityWebRequest::m_CertificateHandler
	CertificateHandler_t148B524FA5DB39F3ABADB181CD420FC505C33804* ___m_CertificateHandler_3;
	// System.Uri UnityEngine.Networking.UnityWebRequest::m_Uri
	Uri_t1500A52B5F71A04F5D05C0852D0F2A0941842A0E* ___m_Uri_4;
	// System.Boolean UnityEngine.Networking.UnityWebRequest::<disposeCertificateHandlerOnDispose>k__BackingField
	bool ___U3CdisposeCertificateHandlerOnDisposeU3Ek__BackingField_5;
	// System.Boolean UnityEngine.Networking.UnityWebRequest::<disposeDownloadHandlerOnDispose>k__BackingField
	bool ___U3CdisposeDownloadHandlerOnDisposeU3Ek__BackingField_6;
	// System.Boolean UnityEngine.Networking.UnityWebRequest::<disposeUploadHandlerOnDispose>k__BackingField
	bool ___U3CdisposeUploadHandlerOnDisposeU3Ek__BackingField_7;
};
// Native definition for P/Invoke marshalling of UnityEngine.Networking.UnityWebRequest
struct UnityWebRequest_t6233B8E22992FC2364A831C1ACB033EF3260C39F_marshaled_pinvoke
{
	intptr_t ___m_Ptr_0;
	DownloadHandler_t1B56C7D3F65D97A1E4B566A14A1E783EA8AE4EBB_marshaled_pinvoke ___m_DownloadHandler_1;
	UploadHandler_t7E504B1A83346248A0C8C4AF73A893226CB83EF6_marshaled_pinvoke ___m_UploadHandler_2;
	CertificateHandler_t148B524FA5DB39F3ABADB181CD420FC505C33804_marshaled_pinvoke ___m_CertificateHandler_3;
	Uri_t1500A52B5F71A04F5D05C0852D0F2A0941842A0E* ___m_Uri_4;
	int32_t ___U3CdisposeCertificateHandlerOnDisposeU3Ek__BackingField_5;
	int32_t ___U3CdisposeDownloadHandlerOnDisposeU3Ek__BackingField_6;
	int32_t ___U3CdisposeUploadHandlerOnDisposeU3Ek__BackingField_7;
};
// Native definition for COM marshalling of UnityEngine.Networking.UnityWebRequest
struct UnityWebRequest_t6233B8E22992FC2364A831C1ACB033EF3260C39F_marshaled_com
{
	intptr_t ___m_Ptr_0;
	DownloadHandler_t1B56C7D3F65D97A1E4B566A14A1E783EA8AE4EBB_marshaled_com* ___m_DownloadHandler_1;
	UploadHandler_t7E504B1A83346248A0C8C4AF73A893226CB83EF6_marshaled_com* ___m_UploadHandler_2;
	CertificateHandler_t148B524FA5DB39F3ABADB181CD420FC505C33804_marshaled_com* ___m_CertificateHandler_3;
	Uri_t1500A52B5F71A04F5D05C0852D0F2A0941842A0E* ___m_Uri_4;
	int32_t ___U3CdisposeCertificateHandlerOnDisposeU3Ek__BackingField_5;
	int32_t ___U3CdisposeDownloadHandlerOnDisposeU3Ek__BackingField_6;
	int32_t ___U3CdisposeUploadHandlerOnDisposeU3Ek__BackingField_7;
};

// UnityEngine.Networking.UnityWebRequestAsyncOperation
struct UnityWebRequestAsyncOperation_t14BE94558FF3A2CFC2EFBE2511A3A88252042B8C  : public AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C
{
	// UnityEngine.Networking.UnityWebRequest UnityEngine.Networking.UnityWebRequestAsyncOperation::<webRequest>k__BackingField
	UnityWebRequest_t6233B8E22992FC2364A831C1ACB033EF3260C39F* ___U3CwebRequestU3Ek__BackingField_2;
};
// Native definition for P/Invoke marshalling of UnityEngine.Networking.UnityWebRequestAsyncOperation
struct UnityWebRequestAsyncOperation_t14BE94558FF3A2CFC2EFBE2511A3A88252042B8C_marshaled_pinvoke : public AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C_marshaled_pinvoke
{
	UnityWebRequest_t6233B8E22992FC2364A831C1ACB033EF3260C39F_marshaled_pinvoke* ___U3CwebRequestU3Ek__BackingField_2;
};
// Native definition for COM marshalling of UnityEngine.Networking.UnityWebRequestAsyncOperation
struct UnityWebRequestAsyncOperation_t14BE94558FF3A2CFC2EFBE2511A3A88252042B8C_marshaled_com : public AsyncOperation_tD2789250E4B098DEDA92B366A577E500A92D2D3C_marshaled_com
{
	UnityWebRequest_t6233B8E22992FC2364A831C1ACB033EF3260C39F_marshaled_com* ___U3CwebRequestU3Ek__BackingField_2;
};

// Pico.Platform.Models.User
struct User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4  : public RuntimeObject
{
	// System.String Pico.Platform.Models.User::DisplayName
	String_t* ___DisplayName_0;
	// System.String Pico.Platform.Models.User::ImageUrl
	String_t* ___ImageUrl_1;
	// System.String Pico.Platform.Models.User::SmallImageUrl
	String_t* ___SmallImageUrl_2;
	// System.String Pico.Platform.Models.User::ID
	String_t* ___ID_3;
	// Pico.Platform.UserPresenceStatus Pico.Platform.Models.User::PresenceStatus
	int32_t ___PresenceStatus_4;
	// Pico.Platform.Gender Pico.Platform.Models.User::Gender
	int32_t ___Gender_5;
	// System.String Pico.Platform.Models.User::Presence
	String_t* ___Presence_6;
	// System.String Pico.Platform.Models.User::PresenceDeeplinkMessage
	String_t* ___PresenceDeeplinkMessage_7;
	// System.String Pico.Platform.Models.User::PresenceDestinationApiName
	String_t* ___PresenceDestinationApiName_8;
	// System.String Pico.Platform.Models.User::PresenceLobbySessionId
	String_t* ___PresenceLobbySessionId_9;
	// System.String Pico.Platform.Models.User::PresenceMatchSessionId
	String_t* ___PresenceMatchSessionId_10;
	// System.String Pico.Platform.Models.User::PresenceExtra
	String_t* ___PresenceExtra_11;
	// System.Boolean Pico.Platform.Models.User::PresenceIsJoinable
	bool ___PresenceIsJoinable_12;
	// System.String Pico.Platform.Models.User::InviteToken
	String_t* ___InviteToken_13;
	// System.String Pico.Platform.Models.User::StoreRegion
	String_t* ___StoreRegion_14;
};

// System.Collections.Generic.Dictionary`2/Enumerator<System.Int32Enum,System.Int32>
struct Enumerator_t628F4A89865D78D3344C93277ACECBDE97BE739A 
{
	// System.Collections.Generic.Dictionary`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator::_dictionary
	Dictionary_2_tFCDE91BDD0207A67521C455FD60B9EAA6E0E6B62* ____dictionary_0;
	// System.Int32 System.Collections.Generic.Dictionary`2/Enumerator::_version
	int32_t ____version_1;
	// System.Int32 System.Collections.Generic.Dictionary`2/Enumerator::_index
	int32_t ____index_2;
	// System.Collections.Generic.KeyValuePair`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator::_current
	KeyValuePair_2_t8119C4668B01DE5BDC84EDBA81EE010B6CA16C5C ____current_3;
	// System.Int32 System.Collections.Generic.Dictionary`2/Enumerator::_getEnumeratorRetType
	int32_t ____getEnumeratorRetType_4;
};

// System.Collections.Generic.Dictionary`2/Enumerator<Pico.Platform.RtcPrivilege,System.Int32>
struct Enumerator_tA829CFCA6EB6821F225A3ADB1DFE03AC172EBA69 
{
	// System.Collections.Generic.Dictionary`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator::_dictionary
	Dictionary_2_tFA4E3C6BBA632C5BEEBB77A03650502241C2D607* ____dictionary_0;
	// System.Int32 System.Collections.Generic.Dictionary`2/Enumerator::_version
	int32_t ____version_1;
	// System.Int32 System.Collections.Generic.Dictionary`2/Enumerator::_index
	int32_t ____index_2;
	// System.Collections.Generic.KeyValuePair`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator::_current
	KeyValuePair_2_t3B924E448F08153464BEA8D03A541C9BC936424A ____current_3;
	// System.Int32 System.Collections.Generic.Dictionary`2/Enumerator::_getEnumeratorRetType
	int32_t ____getEnumeratorRetType_4;
};

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.AsrResult>
struct Handler_tE5970BF7190FDDDFE47C25F9F98FC3037D7F753F  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<System.Int32>
struct Handler_t51AE26B34C94E80FFE0A43298E5E7BCF0085B456  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.PermissionResult>
struct Handler_tF65149A494CDA59437FE06A5E974BDECEB45C2B3  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.PlatformInitializeResult>
struct Handler_t514BEA54A8C9B5734E3D678B336DDA196A366022  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.RtcAudioPlaybackDevice>
struct Handler_t9E74A09C7774D66FE0B94FDFE1DFA6DDEC5859ED  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcBinaryMessageReceived>
struct Handler_t1549946AE7DD631785DEE828E599E4CC5F232986  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.RtcConnectionState>
struct Handler_t38CC844160733F92880FA63972B403BF586D39B1  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcJoinRoomResult>
struct Handler_tAFF89B31CBE84C07A66A39AC220981DEC2B648C7  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcLeaveRoomResult>
struct Handler_t53CDA67D66BFBB13CE74EC8B6623D88EB60E6CAE  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcLocalAudioPropertiesReport>
struct Handler_tAC738204727C49FCB4492833A34C3C4A619CEC8E  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcMessageSendResult>
struct Handler_t19833D1404BED864BD881EC7D6947C4BE818F739  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcMuteInfo>
struct Handler_t031AC8F825D5CD006D0F5F9FE16EB538F31C1101  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRemoteAudioPropertiesReport>
struct Handler_t2765C77EA08935A8D61BD6074F539B8BA92581B9  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRoomError>
struct Handler_tAB0E94E2155E2F41351762B712D4F71A3E696890  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRoomMessageReceived>
struct Handler_t063B85C34774FF958AF1A957B4854AF1D6B23888  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRoomStats>
struct Handler_t75AD0D0BA45ACBB20855ADA2457EB304BF32C5B9  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRoomWarn>
struct Handler_tCAF1D3F2723A4B7251F1BC23304D41F30171BA7E  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcStreamSyncInfo>
struct Handler_t4BEE9C610174E243B1AA20525A10BBD66E21BDF5  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserJoinInfo>
struct Handler_t560A0AAA9073BD8BEBEA299A0C30C715A673E10D  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserLeaveInfo>
struct Handler_t163FC6326170437BFF25564AF32923B777FDDE24  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserMessageReceived>
struct Handler_t32B3FC4A52987EC7404B0AC82BD702C403DB3C40  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserPublishInfo>
struct Handler_tD0453CC0FF093CB47FCC2768A008B81EA8988C7F  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserUnPublishInfo>
struct Handler_t7B5EC3663F375895202BECAC07552A9F3DCD971D  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.SpeechError>
struct Handler_t4491361073BF898EF4019198FE0FA845AEA8C7C6  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<System.String>
struct Handler_tE2837A49F6F6E0632D5E94EF3412C338F6526C86  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.User>
struct Handler_t3014C5064A71B62349A0B6C599C034BA36D6E17E  : public MulticastDelegate_t
{
};

// Pico.Platform.Message`1<Pico.Platform.Models.PermissionResult>
struct Message_1_t457063293F5E86604105C51764B8EB632AA81945  : public Message_t2DF6F94E79BCFC7D36B4D1219F09D5DF8D241F83
{
	// T Pico.Platform.Message`1::Data
	PermissionResult_t235EBFBF617C649652D95D6EEB96D6C1E66EE3CF* ___Data_3;
};

// Pico.Platform.Message`1<Pico.Platform.PlatformInitializeResult>
struct Message_1_t58D0E25C5F7D6B97F64C48CFE6DA11BE5D1A3EF1  : public Message_t2DF6F94E79BCFC7D36B4D1219F09D5DF8D241F83
{
	// T Pico.Platform.Message`1::Data
	int32_t ___Data_3;
};

// Pico.Platform.Message`1<Pico.Platform.Models.User>
struct Message_1_tE6876B2F0C46A93682EA4E2DD435A5D3F37E73C2  : public Message_t2DF6F94E79BCFC7D36B4D1219F09D5DF8D241F83
{
	// T Pico.Platform.Message`1::Data
	User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4* ___Data_3;
};

// System.ArgumentException
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
	// System.String System.ArgumentException::_paramName
	String_t* ____paramName_18;
};

// System.AsyncCallback
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C  : public MulticastDelegate_t
{
};

// UnityEngine.Behaviour
struct Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};

// UnityEngine.Networking.DownloadHandlerTexture
struct DownloadHandlerTexture_t45E2D719000AA1594E648810F0B57A77FA7C568C  : public DownloadHandler_t1B56C7D3F65D97A1E4B566A14A1E783EA8AE4EBB
{
	// Unity.Collections.NativeArray`1<System.Byte> UnityEngine.Networking.DownloadHandlerTexture::m_NativeData
	NativeArray_1_t81F55263465517B73C455D3400CF67B4BADD85CF ___m_NativeData_1;
	// UnityEngine.Texture2D UnityEngine.Networking.DownloadHandlerTexture::mTexture
	Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* ___mTexture_2;
	// System.Boolean UnityEngine.Networking.DownloadHandlerTexture::mHasTexture
	bool ___mHasTexture_3;
	// System.Boolean UnityEngine.Networking.DownloadHandlerTexture::mNonReadable
	bool ___mNonReadable_4;
};
// Native definition for P/Invoke marshalling of UnityEngine.Networking.DownloadHandlerTexture
struct DownloadHandlerTexture_t45E2D719000AA1594E648810F0B57A77FA7C568C_marshaled_pinvoke : public DownloadHandler_t1B56C7D3F65D97A1E4B566A14A1E783EA8AE4EBB_marshaled_pinvoke
{
	NativeArray_1_t81F55263465517B73C455D3400CF67B4BADD85CF ___m_NativeData_1;
	Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* ___mTexture_2;
	int32_t ___mHasTexture_3;
	int32_t ___mNonReadable_4;
};
// Native definition for COM marshalling of UnityEngine.Networking.DownloadHandlerTexture
struct DownloadHandlerTexture_t45E2D719000AA1594E648810F0B57A77FA7C568C_marshaled_com : public DownloadHandler_t1B56C7D3F65D97A1E4B566A14A1E783EA8AE4EBB_marshaled_com
{
	NativeArray_1_t81F55263465517B73C455D3400CF67B4BADD85CF ___m_NativeData_1;
	Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* ___mTexture_2;
	int32_t ___mHasTexture_3;
	int32_t ___mNonReadable_4;
};

// System.NotSupportedException
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};

// UnityEngine.Renderer
struct Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};

// UnityEngine.Texture2D
struct Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4  : public Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700
{
};

// Pico.Platform.CLIB/RtcProcessAudioFrameFunction
struct RtcProcessAudioFrameFunction_t91998EE2CD7760356A3A9E75620AEB591C1F2344  : public MulticastDelegate_t
{
};

// Pico.Platform.RtcService/ProcessAudioFrameFunction
struct ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5  : public MulticastDelegate_t
{
};

// UnityEngine.MonoBehaviour
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
};

// Pico.Platform.Framework.Runner
struct Runner_tB8E78BC8FEC1129C330C7EF44FE5BBFC57BFB7B8  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
};

// Pico.Platform.Samples.SimpleDemo
struct SimpleDemo_tB73BB92662E2E45C09FAD8C176DC8690E0FD4195  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// System.Boolean Pico.Platform.Samples.SimpleDemo::useAsyncInit
	bool ___useAsyncInit_4;
	// UnityEngine.UI.RawImage Pico.Platform.Samples.SimpleDemo::headImage
	RawImage_tFF12F7DB574FBDC1863CF607C7A12A5D9F8D6179* ___headImage_5;
	// UnityEngine.UI.Text Pico.Platform.Samples.SimpleDemo::nameText
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___nameText_6;
	// UnityEngine.UI.Text Pico.Platform.Samples.SimpleDemo::logText
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___logText_7;
};

// UnityEngine.EventSystems.UIBehaviour
struct UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
};

// UnityEngine.UI.Graphic
struct Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931  : public UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D
{
	// UnityEngine.Material UnityEngine.UI.Graphic::m_Material
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___m_Material_6;
	// UnityEngine.Color UnityEngine.UI.Graphic::m_Color
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_Color_7;
	// System.Boolean UnityEngine.UI.Graphic::m_SkipLayoutUpdate
	bool ___m_SkipLayoutUpdate_8;
	// System.Boolean UnityEngine.UI.Graphic::m_SkipMaterialUpdate
	bool ___m_SkipMaterialUpdate_9;
	// System.Boolean UnityEngine.UI.Graphic::m_RaycastTarget
	bool ___m_RaycastTarget_10;
	// System.Boolean UnityEngine.UI.Graphic::m_RaycastTargetCache
	bool ___m_RaycastTargetCache_11;
	// UnityEngine.Vector4 UnityEngine.UI.Graphic::m_RaycastPadding
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___m_RaycastPadding_12;
	// UnityEngine.RectTransform UnityEngine.UI.Graphic::m_RectTransform
	RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5* ___m_RectTransform_13;
	// UnityEngine.CanvasRenderer UnityEngine.UI.Graphic::m_CanvasRenderer
	CanvasRenderer_tAB9A55A976C4E3B2B37D0CE5616E5685A8B43860* ___m_CanvasRenderer_14;
	// UnityEngine.Canvas UnityEngine.UI.Graphic::m_Canvas
	Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* ___m_Canvas_15;
	// System.Boolean UnityEngine.UI.Graphic::m_VertsDirty
	bool ___m_VertsDirty_16;
	// System.Boolean UnityEngine.UI.Graphic::m_MaterialDirty
	bool ___m_MaterialDirty_17;
	// UnityEngine.Events.UnityAction UnityEngine.UI.Graphic::m_OnDirtyLayoutCallback
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___m_OnDirtyLayoutCallback_18;
	// UnityEngine.Events.UnityAction UnityEngine.UI.Graphic::m_OnDirtyVertsCallback
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___m_OnDirtyVertsCallback_19;
	// UnityEngine.Events.UnityAction UnityEngine.UI.Graphic::m_OnDirtyMaterialCallback
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___m_OnDirtyMaterialCallback_20;
	// UnityEngine.Mesh UnityEngine.UI.Graphic::m_CachedMesh
	Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___m_CachedMesh_23;
	// UnityEngine.Vector2[] UnityEngine.UI.Graphic::m_CachedUvs
	Vector2U5BU5D_tFEBBC94BCC6C9C88277BA04047D2B3FDB6ED7FDA* ___m_CachedUvs_24;
	// UnityEngine.UI.CoroutineTween.TweenRunner`1<UnityEngine.UI.CoroutineTween.ColorTween> UnityEngine.UI.Graphic::m_ColorTweenRunner
	TweenRunner_1_t5BB0582F926E75E2FE795492679A6CF55A4B4BC4* ___m_ColorTweenRunner_25;
	// System.Boolean UnityEngine.UI.Graphic::<useLegacyMeshGeneration>k__BackingField
	bool ___U3CuseLegacyMeshGenerationU3Ek__BackingField_26;
};

// UnityEngine.UI.MaskableGraphic
struct MaskableGraphic_tFC5B6BE351C90DE53744DF2A70940242774B361E  : public Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931
{
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_ShouldRecalculateStencil
	bool ___m_ShouldRecalculateStencil_27;
	// UnityEngine.Material UnityEngine.UI.MaskableGraphic::m_MaskMaterial
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___m_MaskMaterial_28;
	// UnityEngine.UI.RectMask2D UnityEngine.UI.MaskableGraphic::m_ParentMask
	RectMask2D_tACF92BE999C791A665BD1ADEABF5BCEB82846670* ___m_ParentMask_29;
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_Maskable
	bool ___m_Maskable_30;
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_IsMaskingGraphic
	bool ___m_IsMaskingGraphic_31;
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_IncludeForMasking
	bool ___m_IncludeForMasking_32;
	// UnityEngine.UI.MaskableGraphic/CullStateChangedEvent UnityEngine.UI.MaskableGraphic::m_OnCullStateChanged
	CullStateChangedEvent_t6073CD0D951EC1256BF74B8F9107D68FC89B99B8* ___m_OnCullStateChanged_33;
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_ShouldRecalculate
	bool ___m_ShouldRecalculate_34;
	// System.Int32 UnityEngine.UI.MaskableGraphic::m_StencilValue
	int32_t ___m_StencilValue_35;
	// UnityEngine.Vector3[] UnityEngine.UI.MaskableGraphic::m_Corners
	Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* ___m_Corners_36;
};

// UnityEngine.UI.RawImage
struct RawImage_tFF12F7DB574FBDC1863CF607C7A12A5D9F8D6179  : public MaskableGraphic_tFC5B6BE351C90DE53744DF2A70940242774B361E
{
	// UnityEngine.Texture UnityEngine.UI.RawImage::m_Texture
	Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___m_Texture_37;
	// UnityEngine.Rect UnityEngine.UI.RawImage::m_UVRect
	Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D ___m_UVRect_38;
};

// UnityEngine.UI.Text
struct Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62  : public MaskableGraphic_tFC5B6BE351C90DE53744DF2A70940242774B361E
{
	// UnityEngine.UI.FontData UnityEngine.UI.Text::m_FontData
	FontData_tB8E562846C6CB59C43260F69AE346B9BF3157224* ___m_FontData_37;
	// System.String UnityEngine.UI.Text::m_Text
	String_t* ___m_Text_38;
	// UnityEngine.TextGenerator UnityEngine.UI.Text::m_TextCache
	TextGenerator_t85D00417640A53953556C01F9D4E7DDE1ABD8FEC* ___m_TextCache_39;
	// UnityEngine.TextGenerator UnityEngine.UI.Text::m_TextCacheForLayout
	TextGenerator_t85D00417640A53953556C01F9D4E7DDE1ABD8FEC* ___m_TextCacheForLayout_40;
	// System.Boolean UnityEngine.UI.Text::m_DisableFontTextureRebuiltCallback
	bool ___m_DisableFontTextureRebuiltCallback_42;
	// UnityEngine.UIVertex[] UnityEngine.UI.Text::m_TempVerts
	UIVertexU5BU5D_tBC532486B45D071A520751A90E819C77BA4E3D2F* ___m_TempVerts_43;
};

// System.Collections.Generic.Dictionary`2<Pico.Platform.RtcPrivilege,System.Int32>

// System.Collections.Generic.Dictionary`2<Pico.Platform.RtcPrivilege,System.Int32>

// System.Collections.Generic.Dictionary`2<System.String,System.String>

// System.Collections.Generic.Dictionary`2<System.String,System.String>

// System.Collections.Generic.Dictionary`2<System.String,Pico.Platform.UserRelationType>

// System.Collections.Generic.Dictionary`2<System.String,Pico.Platform.UserRelationType>

// System.Collections.Generic.List`1<Pico.Platform.Models.AchievementDefinition>
struct List_1_t10AC4D431308924325EECB4A49074CCAD3525C5D_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	AchievementDefinitionU5BU5D_tD45280A798177E339C7F71BEA08B42FBC1324806* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.AchievementDefinition>

// System.Collections.Generic.List`1<Pico.Platform.Models.AchievementProgress>
struct List_1_tB745982DEF869D4B1F9C78EE82DF592AB431896B_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	AchievementProgressU5BU5D_t116D1223032641932BDB37219A7C0EEE9628107A* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.AchievementProgress>

// System.Collections.Generic.List`1<Pico.Platform.Models.ApplicationInvite>
struct List_1_tE88D817DED2AB9E24E7A5629200C2087045253F5_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	ApplicationInviteU5BU5D_tFEC3D38D47E91DA4E4859DF99DFA649C726B8B1D* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.ApplicationInvite>

// System.Collections.Generic.List`1<Pico.Platform.Models.AssetDetails>
struct List_1_t99C4055E7A18C1DF32B7AECA7EE4535206181597_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	AssetDetailsU5BU5D_tDFD25B55AA42A540A7F1AE1B0DFB4F4A99E607A9* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.AssetDetails>

// System.Collections.Generic.List`1<Pico.Platform.Models.Challenge>
struct List_1_t1270A6FA80F83E5E821A0DAE5FB3C06865ACB59C_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	ChallengeU5BU5D_tD70C30ED4DDCC167BFB807A20076D422DD522DFC* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.Challenge>

// System.Collections.Generic.List`1<Pico.Platform.Models.ChallengeEntry>
struct List_1_t3A2B2890CB7F9F96B159F90ED3C352D0F69BFC03_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	ChallengeEntryU5BU5D_t01DC002B76F7F4CE1070F74F8475CFE177A1AB72* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.ChallengeEntry>

// System.Collections.Generic.List`1<Pico.Platform.Models.Destination>
struct List_1_t5C085F464CB50B6E73049AC6D994648AA7E2410E_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	DestinationU5BU5D_t8A295AD29D924C3496379E613BF75381A9812A14* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.Destination>

// System.Collections.Generic.List`1<Pico.Platform.Models.Leaderboard>
struct List_1_t724694C0B4027B186B04C28FF07C047043904083_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	LeaderboardU5BU5D_t228A8CBD32C5E10AAC389ABCF0A9188B66E287D4* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.Leaderboard>

// System.Collections.Generic.List`1<Pico.Platform.Models.LeaderboardEntry>
struct List_1_tC943684C0EBEF2BD2CFD9D2B29FC554E51FBB6A8_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	LeaderboardEntryU5BU5D_t1E730BC8E35CD591F53C791F553A7BDB7D7B9F7A* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.LeaderboardEntry>

// System.Collections.Generic.List`1<Pico.Platform.Models.MatchmakingAdminSnapshotCandidate>
struct List_1_tABBB0A07DB48EE3A69D8AE19FD395C748196C1A1_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	MatchmakingAdminSnapshotCandidateU5BU5D_t7472DB57A6C6C52E8EEF83AD0B13B118AA683DF5* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.MatchmakingAdminSnapshotCandidate>

// System.Collections.Generic.List`1<Pico.Platform.Models.MatchmakingRoom>
struct List_1_tA41CDF0D6A3ED7853A9F821A69838D214E8DD5CB_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	MatchmakingRoomU5BU5D_t15CBD754E9AA79A2D96C20A2B446F16C0052AC74* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.MatchmakingRoom>

// System.Collections.Generic.List`1<System.Object>
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<System.Object>

// System.Collections.Generic.List`1<Pico.Platform.Models.Product>
struct List_1_tECB4BC629C4B6ABBCAC7C8ADCEFEBA5518203F3C_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	ProductU5BU5D_tE4833FDC634EF457AA9978D99883A22B899D0CD5* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.Product>

// System.Collections.Generic.List`1<Pico.Platform.Models.Purchase>
struct List_1_t0BED0F374F8819664848045406304C5C43B290F8_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	PurchaseU5BU5D_t2470799E07346B5DDC326FD66E807F8D3509FA46* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.Purchase>

// System.Collections.Generic.List`1<Pico.Platform.Models.Room>
struct List_1_t17BC494950CA211E4E00DDC3979C43A2750F5DF8_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	RoomU5BU5D_t65395623B3E4D69C7430C314A2AB8B6E2B0ACA79* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.Room>

// System.Collections.Generic.List`1<Pico.Platform.Models.RoomInviteNotification>
struct List_1_t56C8E4CBC81C6319DB682BE3E114E43F68C3AB09_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	RoomInviteNotificationU5BU5D_t9975E8DA69A572BB6D35A08EB32D43FEE31CEAA2* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.RoomInviteNotification>

// System.Collections.Generic.List`1<Pico.Platform.Models.SportDailySummary>
struct List_1_t6C36B6FAA48E5DAE13D84C1C2C9D39AEEF86399F_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	SportDailySummaryU5BU5D_t73B931C0CDA0A57B1620B8E2198C6DFA768953AB* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.SportDailySummary>

// System.Collections.Generic.List`1<Pico.Platform.Models.User>
struct List_1_tA51A980F281692A23CBC3DFCF8131D4AD8565A1C_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	UserU5BU5D_t837772AE1B0DAAE3734C4D1A50D2C00923A3D4DF* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.User>

// System.Collections.Generic.List`1<Pico.Platform.Models.UserRoom>
struct List_1_t68B676CB2F1554E5228FD7A20B97B490395C7E2C_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	UserRoomU5BU5D_t6CA1BBB733313CD8E3B344CD94E1666653050D24* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<Pico.Platform.Models.UserRoom>

// Pico.Platform.Models.AchievementUpdate

// Pico.Platform.Models.AchievementUpdate

// Pico.Platform.Models.ApplicationInvite

// Pico.Platform.Models.ApplicationInvite

// Pico.Platform.Models.ApplicationVersion

// Pico.Platform.Models.ApplicationVersion

// Pico.Platform.Models.AsrResult

// Pico.Platform.Models.AsrResult

// Pico.Platform.Models.AssetDetails

// Pico.Platform.Models.AssetDetails

// Pico.Platform.Models.AssetFileDeleteForSafety

// Pico.Platform.Models.AssetFileDeleteForSafety

// Pico.Platform.Models.AssetFileDeleteResult

// Pico.Platform.Models.AssetFileDeleteResult

// Pico.Platform.Models.AssetFileDownloadCancelResult

// Pico.Platform.Models.AssetFileDownloadCancelResult

// Pico.Platform.Models.AssetFileDownloadResult

// Pico.Platform.Models.AssetFileDownloadResult

// Pico.Platform.Models.AssetStatus

// Pico.Platform.Models.AssetStatus

// Pico.Platform.Models.AssetType

// Pico.Platform.Models.AssetType

// Pico.Platform.Models.CaptureInfo

// Pico.Platform.Models.CaptureInfo

// Pico.Platform.CoreService
struct CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields
{
	// System.Boolean Pico.Platform.CoreService::Initialized
	bool ___Initialized_0;
	// System.String Pico.Platform.CoreService::NotInitializedError
	String_t* ___NotInitializedError_1;
};

// Pico.Platform.CoreService

// Pico.Platform.Models.Destination

// Pico.Platform.Models.Destination

// Pico.Platform.Models.DownloadStatus

// Pico.Platform.Models.DownloadStatus

// System.Text.Encoding
struct Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095_StaticFields
{
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::defaultEncoding
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___defaultEncoding_0;
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::unicodeEncoding
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___unicodeEncoding_1;
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::bigEndianUnicode
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___bigEndianUnicode_2;
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::utf7Encoding
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___utf7Encoding_3;
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::utf8Encoding
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___utf8Encoding_4;
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::utf32Encoding
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___utf32Encoding_5;
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::asciiEncoding
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___asciiEncoding_6;
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::latin1Encoding
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___latin1Encoding_7;
	// System.Collections.Generic.Dictionary`2<System.Int32,System.Text.Encoding> modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::encodings
	Dictionary_2_t87EDE08B2E48F793A22DE50D6B3CC2E7EBB2DB54* ___encodings_8;
	// System.Object System.Text.Encoding::s_InternalSyncObject
	RuntimeObject* ___s_InternalSyncObject_15;
};

// System.Text.Encoding

// Pico.Platform.Models.EntitlementCheckResult

// Pico.Platform.Models.EntitlementCheckResult

// Pico.Platform.Models.Error

// Pico.Platform.Models.Error

// Pico.Platform.Models.IapStatus

// Pico.Platform.Models.IapStatus

// Pico.Platform.Models.LaunchFriendResult

// Pico.Platform.Models.LaunchFriendResult

// Pico.Platform.Models.Leaderboard

// Pico.Platform.Models.Leaderboard

// Pico.Platform.Models.MatchmakingAdminSnapshot

// Pico.Platform.Models.MatchmakingAdminSnapshot

// Pico.Platform.Models.MatchmakingAdminSnapshotCandidate

// Pico.Platform.Models.MatchmakingAdminSnapshotCandidate

// Pico.Platform.Models.MatchmakingBrowseResult

// Pico.Platform.Models.MatchmakingBrowseResult

// Pico.Platform.Models.MatchmakingEnqueueResult

// Pico.Platform.Models.MatchmakingEnqueueResult

// Pico.Platform.Models.MatchmakingEnqueueResultAndRoom

// Pico.Platform.Models.MatchmakingEnqueueResultAndRoom

// Pico.Platform.Models.MatchmakingRoom

// Pico.Platform.Models.MatchmakingRoom

// Pico.Platform.Models.MatchmakingStats

// Pico.Platform.Models.MatchmakingStats

// Pico.Platform.Models.OrgScopedID

// Pico.Platform.Models.OrgScopedID

// Pico.Platform.Models.PermissionResult

// Pico.Platform.Models.PermissionResult

// Pico.Platform.Models.Permissions

// Pico.Platform.Models.Permissions

// Pico.Platform.Models.PresenceJoinIntent

// Pico.Platform.Models.PresenceJoinIntent

// Pico.Platform.Models.RecordInfo

// Pico.Platform.Models.RecordInfo

// Pico.Platform.Models.RtcAudioPropertyInfo

// Pico.Platform.Models.RtcAudioPropertyInfo

// Pico.Platform.Models.RtcBinaryMessageReceived

// Pico.Platform.Models.RtcBinaryMessageReceived

// Pico.Platform.Models.RtcLeaveRoomResult

// Pico.Platform.Models.RtcLeaveRoomResult

// Pico.Platform.Models.RtcLocalAudioPropertiesReport

// Pico.Platform.Models.RtcLocalAudioPropertiesReport

// Pico.Platform.Models.RtcMessageSendResult

// Pico.Platform.Models.RtcMessageSendResult

// Pico.Platform.Models.RtcRemoteAudioPropertiesInfo

// Pico.Platform.Models.RtcRemoteAudioPropertiesInfo

// Pico.Platform.Models.RtcRemoteAudioPropertiesReport

// Pico.Platform.Models.RtcRemoteAudioPropertiesReport

// Pico.Platform.Models.RtcRoomError

// Pico.Platform.Models.RtcRoomError

// Pico.Platform.Models.RtcRoomMessageReceived

// Pico.Platform.Models.RtcRoomMessageReceived

// Pico.Platform.Models.RtcRoomStats

// Pico.Platform.Models.RtcRoomStats

// Pico.Platform.Models.RtcRoomWarn

// Pico.Platform.Models.RtcRoomWarn

// Pico.Platform.RtcService
struct RtcService_t22C275834C979544290EE8B61C467477647BD1BF_StaticFields
{
	// Pico.Platform.RtcService/ProcessAudioFrameFunction Pico.Platform.RtcService::audioProcessor
	ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5* ___audioProcessor_0;
};

// Pico.Platform.RtcService

// Pico.Platform.Models.RtcUserJoinInfo

// Pico.Platform.Models.RtcUserJoinInfo

// Pico.Platform.Models.RtcUserMessageReceived

// Pico.Platform.Models.RtcUserMessageReceived

// Pico.Platform.Models.SendInvitesResult

// Pico.Platform.Models.SendInvitesResult

// Pico.Platform.Models.SessionMedia

// Pico.Platform.Models.SessionMedia

// Pico.Platform.Models.SpeechError

// Pico.Platform.Models.SpeechError

// Pico.Platform.SpeechService

// Pico.Platform.SpeechService

// Pico.Platform.SportService

// Pico.Platform.SportService

// System.String
struct String_t_StaticFields
{
	// System.String System.String::Empty
	String_t* ___Empty_6;
};

// System.String

// Pico.Platform.Models.SupplementaryMetric

// Pico.Platform.Models.SupplementaryMetric

// Pico.Platform.Models.SystemInfo

// Pico.Platform.Models.SystemInfo

// Pico.Platform.Models.UserRoom

// Pico.Platform.Models.UserRoom

// Pico.Platform.UserService

// Pico.Platform.UserService

// Pico.Platform.Samples.SimpleDemo/<DownloadImage>d__7

// Pico.Platform.Samples.SimpleDemo/<DownloadImage>d__7

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.AchievementDefinition>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.AchievementDefinition>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.AchievementProgress>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.AchievementProgress>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.ApplicationInvite>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.ApplicationInvite>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.AssetDetails>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.AssetDetails>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Challenge>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Challenge>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.ChallengeEntry>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.ChallengeEntry>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Destination>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Destination>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Leaderboard>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Leaderboard>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.LeaderboardEntry>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.LeaderboardEntry>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.MatchmakingAdminSnapshotCandidate>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.MatchmakingAdminSnapshotCandidate>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.MatchmakingRoom>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.MatchmakingRoom>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Product>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Product>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Purchase>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Purchase>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Room>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Room>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.RoomInviteNotification>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.RoomInviteNotification>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.SportDailySummary>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.SportDailySummary>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.User>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.User>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.UserRoom>

// Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.UserRoom>

// Pico.Platform.Task`1<Pico.Platform.Models.EntitlementCheckResult>

// Pico.Platform.Task`1<Pico.Platform.Models.EntitlementCheckResult>

// Pico.Platform.Task`1<Pico.Platform.Models.LaunchFriendResult>

// Pico.Platform.Task`1<Pico.Platform.Models.LaunchFriendResult>

// Pico.Platform.Task`1<Pico.Platform.Models.OrgScopedID>

// Pico.Platform.Task`1<Pico.Platform.Models.OrgScopedID>

// Pico.Platform.Task`1<Pico.Platform.Models.PermissionResult>

// Pico.Platform.Task`1<Pico.Platform.Models.PermissionResult>

// Pico.Platform.Task`1<Pico.Platform.PlatformInitializeResult>

// Pico.Platform.Task`1<Pico.Platform.PlatformInitializeResult>

// Pico.Platform.Task`1<Pico.Platform.Models.SportDailySummaryList>

// Pico.Platform.Task`1<Pico.Platform.Models.SportDailySummaryList>

// Pico.Platform.Task`1<Pico.Platform.Models.SportSummary>

// Pico.Platform.Task`1<Pico.Platform.Models.SportSummary>

// Pico.Platform.Task`1<Pico.Platform.Models.SportUserInfo>

// Pico.Platform.Task`1<Pico.Platform.Models.SportUserInfo>

// Pico.Platform.Task`1<System.String>

// Pico.Platform.Task`1<System.String>

// Pico.Platform.Task`1<Pico.Platform.Models.User>

// Pico.Platform.Task`1<Pico.Platform.Models.User>

// Pico.Platform.Task`1<Pico.Platform.Models.UserList>

// Pico.Platform.Task`1<Pico.Platform.Models.UserList>

// Pico.Platform.Task`1<Pico.Platform.Models.UserRelationResult>

// Pico.Platform.Task`1<Pico.Platform.Models.UserRelationResult>

// Pico.Platform.Task`1<Pico.Platform.Models.UserRoomList>

// Pico.Platform.Task`1<Pico.Platform.Models.UserRoomList>

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

// System.DateTime
struct DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_StaticFields
{
	// System.Int32[] System.DateTime::s_daysToMonth365
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___s_daysToMonth365_30;
	// System.Int32[] System.DateTime::s_daysToMonth366
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___s_daysToMonth366_31;
	// System.DateTime System.DateTime::MinValue
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___MinValue_32;
	// System.DateTime System.DateTime::MaxValue
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___MaxValue_33;
	// System.DateTime System.DateTime::UnixEpoch
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___UnixEpoch_34;
};

// System.DateTime

// System.Double

// System.Double

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

// System.UInt32

// System.UInt32

// System.UInt64

// System.UInt64

// System.UIntPtr
struct UIntPtr_t_StaticFields
{
	// System.UIntPtr System.UIntPtr::Zero
	uintptr_t ___Zero_0;
};

// System.UIntPtr

// Pico.Platform.Models.UserRelationResult

// Pico.Platform.Models.UserRelationResult

// System.Void

// System.Void

// Pico.Platform.Models.AchievementDefinitionList

// Pico.Platform.Models.AchievementDefinitionList

// Pico.Platform.Models.AchievementProgress

// Pico.Platform.Models.AchievementProgress

// Pico.Platform.Models.AchievementProgressList

// Pico.Platform.Models.AchievementProgressList

// Pico.Platform.AchievementType

// Pico.Platform.AchievementType

// Pico.Platform.AchievementWritePolicy

// Pico.Platform.AchievementWritePolicy

// Pico.Platform.AddonsType

// Pico.Platform.AddonsType

// Pico.Platform.Models.ApplicationInviteList

// Pico.Platform.Models.ApplicationInviteList

// Pico.Platform.AsrEngineInitResult

// Pico.Platform.AsrEngineInitResult

// Pico.Platform.Models.AssetDetailsList

// Pico.Platform.Models.AssetDetailsList

// Pico.Platform.AssetFileDownloadCompleteStatus

// Pico.Platform.AssetFileDownloadCompleteStatus

// Pico.Platform.CancelReason

// Pico.Platform.CancelReason

// Pico.Platform.ChallengeCreationType

// Pico.Platform.ChallengeCreationType

// Pico.Platform.Models.ChallengeEntry

// Pico.Platform.Models.ChallengeEntry

// Pico.Platform.Models.ChallengeEntryList

// Pico.Platform.Models.ChallengeEntryList

// Pico.Platform.Models.ChallengeList

// Pico.Platform.Models.ChallengeList

// Pico.Platform.Models.ChallengeOptions

// Pico.Platform.Models.ChallengeOptions

// Pico.Platform.ChallengeViewerFilter

// Pico.Platform.ChallengeViewerFilter

// Pico.Platform.ChallengeVisibility

// Pico.Platform.ChallengeVisibility

// UnityEngine.Coroutine

// UnityEngine.Coroutine

// System.Delegate

// System.Delegate

// Pico.Platform.Models.DestinationList

// Pico.Platform.Models.DestinationList

// Pico.Platform.DiscountType

// Pico.Platform.DiscountType

// UnityEngine.Networking.DownloadHandler

// UnityEngine.Networking.DownloadHandler

// Pico.Platform.EntitlementStatus

// Pico.Platform.EntitlementStatus

// System.Exception
struct Exception_t_StaticFields
{
	// System.Object System.Exception::s_EDILock
	RuntimeObject* ___s_EDILock_0;
};

// System.Exception

// Pico.Platform.Gender

// Pico.Platform.Gender

// System.Int32Enum

// System.Int32Enum

// Pico.Platform.Models.KVPair

// Pico.Platform.Models.KVPair

// Pico.Platform.Models.KVPairArray

// Pico.Platform.Models.KVPairArray

// Pico.Platform.KVPairType

// Pico.Platform.KVPairType

// Pico.Platform.LaunchType

// Pico.Platform.LaunchType

// Pico.Platform.Models.LeaderboardEntry

// Pico.Platform.Models.LeaderboardEntry

// Pico.Platform.Models.LeaderboardEntryList

// Pico.Platform.Models.LeaderboardEntryList

// Pico.Platform.Models.LeaderboardList

// Pico.Platform.Models.LeaderboardList

// Pico.Platform.Models.MatchmakingAdminSnapshotCandidateList

// Pico.Platform.Models.MatchmakingAdminSnapshotCandidateList

// Pico.Platform.Models.MatchmakingRoomList

// Pico.Platform.Models.MatchmakingRoomList

// Pico.Platform.MessageType

// Pico.Platform.MessageType

// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_StaticFields
{
	// System.Int32 UnityEngine.Object::OffsetOfInstanceIDInCPlusPlusObject
	int32_t ___OffsetOfInstanceIDInCPlusPlusObject_1;
};

// UnityEngine.Object

// Pico.Platform.Models.Packet

// Pico.Platform.Models.Packet

// Pico.Platform.PeriodType

// Pico.Platform.PeriodType

// Pico.Platform.PlatformInitializeResult

// Pico.Platform.PlatformInitializeResult

// Pico.Platform.Models.ProductList

// Pico.Platform.Models.ProductList

// Pico.Platform.PtrManager

// Pico.Platform.PtrManager

// Pico.Platform.Models.PurchaseList

// Pico.Platform.Models.PurchaseList

// Pico.Platform.Models.RoomInviteNotification

// Pico.Platform.Models.RoomInviteNotification

// Pico.Platform.Models.RoomInviteNotificationList

// Pico.Platform.Models.RoomInviteNotificationList

// Pico.Platform.RoomJoinPolicy

// Pico.Platform.RoomJoinPolicy

// Pico.Platform.RoomJoinability

// Pico.Platform.RoomJoinability

// Pico.Platform.Models.RoomList

// Pico.Platform.Models.RoomList

// Pico.Platform.RoomOptions

// Pico.Platform.RoomOptions

// Pico.Platform.RoomType

// Pico.Platform.RoomType

// Pico.Platform.RtcAudioChannel

// Pico.Platform.RtcAudioChannel

// Pico.Platform.RtcAudioPlaybackDevice

// Pico.Platform.RtcAudioPlaybackDevice

// Pico.Platform.RtcAudioPropertyOptions

// Pico.Platform.RtcAudioPropertyOptions

// Pico.Platform.RtcAudioSampleRate

// Pico.Platform.RtcAudioSampleRate

// Pico.Platform.RtcAudioScenarioType

// Pico.Platform.RtcAudioScenarioType

// Pico.Platform.RtcEarMonitorMode

// Pico.Platform.RtcEarMonitorMode

// Pico.Platform.RtcEngineInitResult

// Pico.Platform.RtcEngineInitResult

// Pico.Platform.RtcGetTokenOptions

// Pico.Platform.RtcGetTokenOptions

// Pico.Platform.RtcJoinRoomType

// Pico.Platform.RtcJoinRoomType

// Pico.Platform.RtcMediaDeviceError

// Pico.Platform.RtcMediaDeviceError

// Pico.Platform.RtcMediaDeviceState

// Pico.Platform.RtcMediaDeviceState

// Pico.Platform.RtcMediaDeviceType

// Pico.Platform.RtcMediaDeviceType

// Pico.Platform.RtcMediaStreamType

// Pico.Platform.RtcMediaStreamType

// Pico.Platform.RtcMuteState

// Pico.Platform.RtcMuteState

// Pico.Platform.RtcPauseResumeMediaType

// Pico.Platform.RtcPauseResumeMediaType

// Pico.Platform.RtcPrivilege

// Pico.Platform.RtcPrivilege

// Pico.Platform.RtcRoomOptions

// Pico.Platform.RtcRoomOptions

// Pico.Platform.RtcRoomProfileType

// Pico.Platform.RtcRoomProfileType

// Pico.Platform.RtcStreamIndex

// Pico.Platform.RtcStreamIndex

// Pico.Platform.RtcStreamRemoveReason

// Pico.Platform.RtcStreamRemoveReason

// Pico.Platform.RtcStreamSyncInfoOptions

// Pico.Platform.RtcStreamSyncInfoOptions

// Pico.Platform.RtcSyncInfoStreamType

// Pico.Platform.RtcSyncInfoStreamType

// Pico.Platform.RtcUserLeaveReasonType

// Pico.Platform.RtcUserLeaveReasonType

// UnityEngine.RuntimePlatform

// UnityEngine.RuntimePlatform

// Pico.Platform.SensitiveProposal

// Pico.Platform.SensitiveProposal

// Pico.Platform.Models.SportDailySummary

// Pico.Platform.Models.SportDailySummary

// Pico.Platform.Models.SportDailySummaryList

// Pico.Platform.Models.SportDailySummaryList

// Pico.Platform.Models.SportSummary

// Pico.Platform.Models.SportSummary

// Pico.Platform.SportTarget

// Pico.Platform.SportTarget

// Pico.Platform.StartAsrOptions

// Pico.Platform.StartAsrOptions

// Pico.Platform.Models.UserList

// Pico.Platform.Models.UserList

// Pico.Platform.UserPresenceStatus

// Pico.Platform.UserPresenceStatus

// Pico.Platform.UserRelationType

// Pico.Platform.UserRelationType

// Pico.Platform.Models.UserRoomList

// Pico.Platform.Models.UserRoomList

// System.Collections.Generic.KeyValuePair`2<System.Int32Enum,System.Int32>

// System.Collections.Generic.KeyValuePair`2<System.Int32Enum,System.Int32>

// System.Collections.Generic.KeyValuePair`2<Pico.Platform.RtcPrivilege,System.Int32>

// System.Collections.Generic.KeyValuePair`2<Pico.Platform.RtcPrivilege,System.Int32>

// Pico.Platform.Models.AchievementDefinition

// Pico.Platform.Models.AchievementDefinition

// Pico.Platform.Models.AssetFileDownloadUpdate

// Pico.Platform.Models.AssetFileDownloadUpdate

// Pico.Platform.Models.Challenge

// Pico.Platform.Models.Challenge

// UnityEngine.Component

// UnityEngine.Component

// Pico.Platform.Models.DetectSensitiveResult

// Pico.Platform.Models.DetectSensitiveResult

// UnityEngine.GameObject

// UnityEngine.GameObject

// Pico.Platform.Models.LaunchDetails

// Pico.Platform.Models.LaunchDetails

// UnityEngine.Material

// UnityEngine.Material

// Pico.Platform.Message

// Pico.Platform.Message

// Pico.Platform.Models.Product

// Pico.Platform.Models.Product

// Pico.Platform.Models.Purchase

// Pico.Platform.Models.Purchase

// Pico.Platform.Models.Room

// Pico.Platform.Models.Room

// Pico.Platform.Models.RtcAudioFrame

// Pico.Platform.Models.RtcAudioFrame

// Pico.Platform.Models.RtcJoinRoomResult

// Pico.Platform.Models.RtcJoinRoomResult

// Pico.Platform.Models.RtcLocalAudioPropertiesInfo

// Pico.Platform.Models.RtcLocalAudioPropertiesInfo

// Pico.Platform.Models.RtcMediaDeviceChangeInfo

// Pico.Platform.Models.RtcMediaDeviceChangeInfo

// Pico.Platform.Models.RtcMuteInfo

// Pico.Platform.Models.RtcMuteInfo

// Pico.Platform.Models.RtcRemoteStreamKey

// Pico.Platform.Models.RtcRemoteStreamKey

// Pico.Platform.Models.RtcStreamSyncInfo

// Pico.Platform.Models.RtcStreamSyncInfo

// Pico.Platform.Models.RtcUserLeaveInfo

// Pico.Platform.Models.RtcUserLeaveInfo

// Pico.Platform.Models.RtcUserPublishInfo

// Pico.Platform.Models.RtcUserPublishInfo

// Pico.Platform.Models.RtcUserUnPublishInfo

// Pico.Platform.Models.RtcUserUnPublishInfo

// Pico.Platform.Models.SportUserInfo

// Pico.Platform.Models.SportUserInfo

// Pico.Platform.Models.SubscriptionStatus

// Pico.Platform.Models.SubscriptionStatus

// UnityEngine.Texture
struct Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700_StaticFields
{
	// System.Int32 UnityEngine.Texture::GenerateAllMips
	int32_t ___GenerateAllMips_4;
};

// UnityEngine.Texture

// UnityEngine.UnityException

// UnityEngine.UnityException

// UnityEngine.Networking.UnityWebRequest

// UnityEngine.Networking.UnityWebRequest

// UnityEngine.Networking.UnityWebRequestAsyncOperation

// UnityEngine.Networking.UnityWebRequestAsyncOperation

// Pico.Platform.Models.User

// Pico.Platform.Models.User

// System.Collections.Generic.Dictionary`2/Enumerator<System.Int32Enum,System.Int32>

// System.Collections.Generic.Dictionary`2/Enumerator<System.Int32Enum,System.Int32>

// System.Collections.Generic.Dictionary`2/Enumerator<Pico.Platform.RtcPrivilege,System.Int32>

// System.Collections.Generic.Dictionary`2/Enumerator<Pico.Platform.RtcPrivilege,System.Int32>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.AsrResult>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.AsrResult>

// Pico.Platform.Message`1/Handler<System.Int32>

// Pico.Platform.Message`1/Handler<System.Int32>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.PermissionResult>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.PermissionResult>

// Pico.Platform.Message`1/Handler<Pico.Platform.PlatformInitializeResult>

// Pico.Platform.Message`1/Handler<Pico.Platform.PlatformInitializeResult>

// Pico.Platform.Message`1/Handler<Pico.Platform.RtcAudioPlaybackDevice>

// Pico.Platform.Message`1/Handler<Pico.Platform.RtcAudioPlaybackDevice>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcBinaryMessageReceived>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcBinaryMessageReceived>

// Pico.Platform.Message`1/Handler<Pico.Platform.RtcConnectionState>

// Pico.Platform.Message`1/Handler<Pico.Platform.RtcConnectionState>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcJoinRoomResult>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcJoinRoomResult>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcLeaveRoomResult>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcLeaveRoomResult>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcLocalAudioPropertiesReport>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcLocalAudioPropertiesReport>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcMessageSendResult>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcMessageSendResult>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcMuteInfo>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcMuteInfo>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRemoteAudioPropertiesReport>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRemoteAudioPropertiesReport>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRoomError>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRoomError>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRoomMessageReceived>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRoomMessageReceived>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRoomStats>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRoomStats>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRoomWarn>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRoomWarn>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcStreamSyncInfo>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcStreamSyncInfo>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserJoinInfo>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserJoinInfo>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserLeaveInfo>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserLeaveInfo>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserMessageReceived>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserMessageReceived>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserPublishInfo>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserPublishInfo>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserUnPublishInfo>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserUnPublishInfo>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.SpeechError>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.SpeechError>

// Pico.Platform.Message`1/Handler<System.String>

// Pico.Platform.Message`1/Handler<System.String>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.User>

// Pico.Platform.Message`1/Handler<Pico.Platform.Models.User>

// Pico.Platform.Message`1<Pico.Platform.Models.PermissionResult>

// Pico.Platform.Message`1<Pico.Platform.Models.PermissionResult>

// Pico.Platform.Message`1<Pico.Platform.PlatformInitializeResult>

// Pico.Platform.Message`1<Pico.Platform.PlatformInitializeResult>

// Pico.Platform.Message`1<Pico.Platform.Models.User>

// Pico.Platform.Message`1<Pico.Platform.Models.User>

// System.ArgumentException

// System.ArgumentException

// System.AsyncCallback

// System.AsyncCallback

// UnityEngine.Networking.DownloadHandlerTexture

// UnityEngine.Networking.DownloadHandlerTexture

// System.NotSupportedException

// System.NotSupportedException

// UnityEngine.Renderer

// UnityEngine.Renderer

// UnityEngine.Texture2D

// UnityEngine.Texture2D

// Pico.Platform.CLIB/RtcProcessAudioFrameFunction

// Pico.Platform.CLIB/RtcProcessAudioFrameFunction

// Pico.Platform.RtcService/ProcessAudioFrameFunction

// Pico.Platform.RtcService/ProcessAudioFrameFunction

// UnityEngine.MonoBehaviour

// UnityEngine.MonoBehaviour

// Pico.Platform.Framework.Runner

// Pico.Platform.Framework.Runner

// Pico.Platform.Samples.SimpleDemo

// Pico.Platform.Samples.SimpleDemo

// UnityEngine.UI.RawImage

// UnityEngine.UI.RawImage

// UnityEngine.UI.Text
struct Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62_StaticFields
{
	// UnityEngine.Material UnityEngine.UI.Text::s_DefaultText
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___s_DefaultText_41;
};

// UnityEngine.UI.Text
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
// Pico.Platform.Models.CaptureInfo[]
struct CaptureInfoU5BU5D_tFA6FAA7D7AE3BBB1688FD52AE43DE5032184993E  : public RuntimeArray
{
	ALIGN_FIELD (8) CaptureInfo_t522928357E5822ACBC5FC59A060BDBABFF3DF575* m_Items[1];

	inline CaptureInfo_t522928357E5822ACBC5FC59A060BDBABFF3DF575* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline CaptureInfo_t522928357E5822ACBC5FC59A060BDBABFF3DF575** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, CaptureInfo_t522928357E5822ACBC5FC59A060BDBABFF3DF575* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline CaptureInfo_t522928357E5822ACBC5FC59A060BDBABFF3DF575* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline CaptureInfo_t522928357E5822ACBC5FC59A060BDBABFF3DF575** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, CaptureInfo_t522928357E5822ACBC5FC59A060BDBABFF3DF575* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
// Pico.Platform.Models.RecordInfo[]
struct RecordInfoU5BU5D_t1505D0DB4C486883C741B73244F4130B5AF19854  : public RuntimeArray
{
	ALIGN_FIELD (8) RecordInfo_t391FC28285898D9D06E379287A88F5A4BA4A6019* m_Items[1];

	inline RecordInfo_t391FC28285898D9D06E379287A88F5A4BA4A6019* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RecordInfo_t391FC28285898D9D06E379287A88F5A4BA4A6019** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RecordInfo_t391FC28285898D9D06E379287A88F5A4BA4A6019* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline RecordInfo_t391FC28285898D9D06E379287A88F5A4BA4A6019* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RecordInfo_t391FC28285898D9D06E379287A88F5A4BA4A6019** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RecordInfo_t391FC28285898D9D06E379287A88F5A4BA4A6019* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
// Pico.Platform.Models.RtcLocalAudioPropertiesInfo[]
struct RtcLocalAudioPropertiesInfoU5BU5D_tECCE986B1F5EE0EA71E955DE541538066669D2C7  : public RuntimeArray
{
	ALIGN_FIELD (8) RtcLocalAudioPropertiesInfo_tDEE2268599EA8C3EC747871F690C5743321ED49E* m_Items[1];

	inline RtcLocalAudioPropertiesInfo_tDEE2268599EA8C3EC747871F690C5743321ED49E* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RtcLocalAudioPropertiesInfo_tDEE2268599EA8C3EC747871F690C5743321ED49E** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RtcLocalAudioPropertiesInfo_tDEE2268599EA8C3EC747871F690C5743321ED49E* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline RtcLocalAudioPropertiesInfo_tDEE2268599EA8C3EC747871F690C5743321ED49E* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RtcLocalAudioPropertiesInfo_tDEE2268599EA8C3EC747871F690C5743321ED49E** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RtcLocalAudioPropertiesInfo_tDEE2268599EA8C3EC747871F690C5743321ED49E* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
// Pico.Platform.Models.RtcRemoteAudioPropertiesInfo[]
struct RtcRemoteAudioPropertiesInfoU5BU5D_t4DD6EF874C9C2844E1101DAE658C91D04DC92952  : public RuntimeArray
{
	ALIGN_FIELD (8) RtcRemoteAudioPropertiesInfo_t756C00636961DE878EE3D2DAD934F01DC0DE3C06* m_Items[1];

	inline RtcRemoteAudioPropertiesInfo_t756C00636961DE878EE3D2DAD934F01DC0DE3C06* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RtcRemoteAudioPropertiesInfo_t756C00636961DE878EE3D2DAD934F01DC0DE3C06** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RtcRemoteAudioPropertiesInfo_t756C00636961DE878EE3D2DAD934F01DC0DE3C06* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline RtcRemoteAudioPropertiesInfo_t756C00636961DE878EE3D2DAD934F01DC0DE3C06* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RtcRemoteAudioPropertiesInfo_t756C00636961DE878EE3D2DAD934F01DC0DE3C06** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RtcRemoteAudioPropertiesInfo_t756C00636961DE878EE3D2DAD934F01DC0DE3C06* value)
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


// System.Collections.Generic.Dictionary`2/Enumerator<TKey,TValue> System.Collections.Generic.Dictionary`2<System.Int32Enum,System.Int32>::GetEnumerator()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t628F4A89865D78D3344C93277ACECBDE97BE739A Dictionary_2_GetEnumerator_m3F34B328374AAC0B9166EFF8B61DBB8E41250811_gshared (Dictionary_2_tFCDE91BDD0207A67521C455FD60B9EAA6E0E6B62* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2/Enumerator<System.Int32Enum,System.Int32>::Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator_Dispose_m80803B80A715D70AB5CF3C6EE6ECAF2A0BEFD876_gshared (Enumerator_t628F4A89865D78D3344C93277ACECBDE97BE739A* __this, const RuntimeMethod* method) ;
// System.Collections.Generic.KeyValuePair`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator<System.Int32Enum,System.Int32>::get_Current()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR KeyValuePair_2_t8119C4668B01DE5BDC84EDBA81EE010B6CA16C5C Enumerator_get_Current_m511016491079A010B4344AA4E125147FAF6D679F_gshared_inline (Enumerator_t628F4A89865D78D3344C93277ACECBDE97BE739A* __this, const RuntimeMethod* method) ;
// TKey System.Collections.Generic.KeyValuePair`2<System.Int32Enum,System.Int32>::get_Key()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t KeyValuePair_2_get_Key_m380DA6E4F786B9C61012C4427405FC5FD48413A1_gshared_inline (KeyValuePair_2_t8119C4668B01DE5BDC84EDBA81EE010B6CA16C5C* __this, const RuntimeMethod* method) ;
// TValue System.Collections.Generic.KeyValuePair`2<System.Int32Enum,System.Int32>::get_Value()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t KeyValuePair_2_get_Value_m3F5DAA82C39D5EFEAE4B1F8389E1DD38732777CC_gshared_inline (KeyValuePair_2_t8119C4668B01DE5BDC84EDBA81EE010B6CA16C5C* __this, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2/Enumerator<System.Int32Enum,System.Int32>::MoveNext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_m2B81AF70E031A662ECD2B22E5377190610523770_gshared (Enumerator_t628F4A89865D78D3344C93277ACECBDE97BE739A* __this, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Task`1<System.Object>::.ctor(System.UInt64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Task_1__ctor_mB5EFF6D4F82D6929289AD587B3332A870C2FBFEC_gshared (Task_1_t7A1D919E5E4E10281920DFF788F966BD9DDF4DD2* __this, uint64_t ___0_taskId, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.Models.MessageArray`1<System.Object>::get_HasNextPage()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool MessageArray_1_get_HasNextPage_mB9584B37665BB97F4772D4A8950F48C0CECB86F5_gshared (MessageArray_1_t1751A681AAC7438BEA74C4EC6F2FE5EF88CBEEE5* __this, const RuntimeMethod* method) ;
// T UnityEngine.GameObject::GetComponent<System.Object>()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* GameObject_GetComponent_TisRuntimeObject_m6EAED4AA356F0F48288F67899E5958792395563B_gshared (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method) ;
// T UnityEngine.GameObject::AddComponent<System.Object>()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* GameObject_AddComponent_TisRuntimeObject_m69B93700FACCF372F5753371C6E8FB780800B824_gshared (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MessageArray`1<System.Object>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageArray_1__ctor_m9B6627200A9DB24455505C010AE4DD7BEF61F451_gshared (MessageArray_1_t1751A681AAC7438BEA74C4EC6F2FE5EF88CBEEE5* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::set_Capacity(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_mD826E33A9E5EBC19C714653217071790693E0B95_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, int32_t ___0_value, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::Add(T)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Int32Enum>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_mE0470880427DED948EF413AD5E9525F41CAF7D1D_gshared (Dictionary_2_t2A9A7F3ECFC3483F89253F3C4BB5BE98A37F6EF3* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Int32Enum>::Add(TKey,TValue)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Add_m53A4E919CB3AE7CC74379031E14C1AEA9DB7A933_gshared (Dictionary_2_t2A9A7F3ECFC3483F89253F3C4BB5BE98A37F6EF3* __this, RuntimeObject* ___0_key, int32_t ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Message`1/Handler<System.Int32Enum>::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Handler__ctor_m4756AACB8B3E1F08083F2079268FC131592BD9A2_gshared (Handler_tB73A87C4788188C83AABC7D2F6641CEF5AAFBA96* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
// Pico.Platform.Task`1<T> Pico.Platform.Task`1<System.Int32Enum>::OnComplete(Pico.Platform.Message`1/Handler<T>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_t38E2E7C305FFAA88BB7CA2F3E338181D20C3768D* Task_1_OnComplete_mD66F6B1B8E2031658AD47304B96F5375209226A1_gshared (Task_1_t38E2E7C305FFAA88BB7CA2F3E338181D20C3768D* __this, Handler_tB73A87C4788188C83AABC7D2F6641CEF5AAFBA96* ___0_handler, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Message`1/Handler<System.Object>::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Handler__ctor_mF22E9A275A92F5E87F8FC119ADB9AB74849705F6_gshared (Handler_t7C4295C020EB651F0A93127B11D3315DD6007787* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
// Pico.Platform.Task`1<T> Pico.Platform.Task`1<System.Object>::OnComplete(Pico.Platform.Message`1/Handler<T>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_t7A1D919E5E4E10281920DFF788F966BD9DDF4DD2* Task_1_OnComplete_m84874DB788370D7C4112AC71C6E46A4E9EBC9827_gshared (Task_1_t7A1D919E5E4E10281920DFF788F966BD9DDF4DD2* __this, Handler_t7C4295C020EB651F0A93127B11D3315DD6007787* ___0_handler, const RuntimeMethod* method) ;
// T UnityEngine.Component::GetComponent<System.Object>()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Component_GetComponent_TisRuntimeObject_m7181F81CAEC2CF53F5D2BC79B7425C16E1F80D33_gshared (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;

// System.Void System.Object::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_RoomOptions_Create()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_RoomOptions_Create_m6ECBE2AC605C2102BC18A9BBC5D696E3F0AEBC6B (const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RoomOptions_SetDataStoreString(System.IntPtr,System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RoomOptions_SetDataStoreString_mF4AAB5DAC9E0AEFDD29CA454D9E3CAD2939D7094 (intptr_t ___0_handle, String_t* ___1_key, String_t* ___2_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RoomOptions_ClearDataStore(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RoomOptions_ClearDataStore_m08E7EFA13A1700BA8B953C5C4D69ED2AE6B6B1DB (intptr_t ___0_handle, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RoomOptions_SetExcludeRecentlyMet(System.IntPtr,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RoomOptions_SetExcludeRecentlyMet_mD1B8195171FDACE7B7D21376FBBE02CEB23AD964 (intptr_t ___0_handle, bool ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RoomOptions_SetMaxUserResults(System.IntPtr,System.UInt32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RoomOptions_SetMaxUserResults_m7CB686A444F6BF00424635009E098E6114E736F0 (intptr_t ___0_handle, uint32_t ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RoomOptions_SetRoomId(System.IntPtr,System.UInt64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RoomOptions_SetRoomId_mF64B0F142484998CB3DB49BACAB7A19F8B6B9655 (intptr_t ___0_handle, uint64_t ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RoomOptions_SetName(System.IntPtr,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RoomOptions_SetName_mACE0C9CF32D1F4D89B6B0B195969DA4B082A265E (intptr_t ___0_handle, String_t* ___1_name, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RoomOptions_SetPassword(System.IntPtr,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RoomOptions_SetPassword_m744B749EA6C835A66E42A5940C550CA022944AE3 (intptr_t ___0_handle, String_t* ___1_password, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RoomOptions_SetTurnOffUpdates(System.IntPtr,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RoomOptions_SetTurnOffUpdates_m7CB0F5C3189BC1A4A3C0D34DBC15DDEF541C0E9A (intptr_t ___0_handle, bool ___1_value, const RuntimeMethod* method) ;
// System.Void System.Object::Finalize()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object_Finalize_mC98C96301CCABFE00F1A7EF8E15DF507CACD42B2 (RuntimeObject* __this, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RoomOptions_Destroy(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RoomOptions_Destroy_m0336694A1A622F8383DA0D257FFC107BA620E804 (intptr_t ___0_handle, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.RtcService::InnerAudioProcessor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RtcService_InnerAudioProcessor_m663C1AC6BC552D87E0EF075932933D89EA182C22 (intptr_t ___0_ptr, const RuntimeMethod* method) ;
// UnityEngine.RuntimePlatform UnityEngine.Application::get_platform()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Application_get_platform_m59EF7D6155D18891B24767F83F388160B1FF2138 (const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Android.Permission::HasUserAuthorizedPermission(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Permission_HasUserAuthorizedPermission_mF4C90E13124E28F6F672200E489CC25A9B645B8B (String_t* ___0_permission, const RuntimeMethod* method) ;
// System.Void UnityEngine.Android.Permission::RequestUserPermission(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Permission_RequestUserPermission_mF9CF3A21AAF34B311137C4D00B3AD6A6C2694242 (String_t* ___0_permission, const RuntimeMethod* method) ;
// Pico.Platform.RtcEngineInitResult Pico.Platform.CLIB::ppf_Rtc_InitRtcEngine()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_Rtc_InitRtcEngine_m20BB8DD19DDA0DE689AED5FDFCC401E17A2B0DFF (const RuntimeMethod* method) ;
// System.Void UnityEngine.Debug::LogError(System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2 (RuntimeObject* ___0_message, const RuntimeMethod* method) ;
// System.Void Pico.Platform.RtcGetTokenOptions::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcGetTokenOptions__ctor_mCA91FB23D9E95538924CA5A36D7A0060A0DA1F12 (RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* __this, const RuntimeMethod* method) ;
// System.Void Pico.Platform.RtcGetTokenOptions::SetRoomId(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcGetTokenOptions_SetRoomId_mEC2981B140C843025675715E718FA4BBBCAF5465 (RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* __this, String_t* ___0_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.RtcGetTokenOptions::SetUserId(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcGetTokenOptions_SetUserId_mAC8EC85CB4D28EE5124B3DF53DCB4DA5AB3D8A74 (RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* __this, String_t* ___0_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.RtcGetTokenOptions::SetTtl(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcGetTokenOptions_SetTtl_m4EBA04258BF46009456989FA5C35B0C5E3CA85C0 (RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* __this, int32_t ___0_value, const RuntimeMethod* method) ;
// System.Collections.Generic.Dictionary`2/Enumerator<TKey,TValue> System.Collections.Generic.Dictionary`2<Pico.Platform.RtcPrivilege,System.Int32>::GetEnumerator()
inline Enumerator_tA829CFCA6EB6821F225A3ADB1DFE03AC172EBA69 Dictionary_2_GetEnumerator_mD22822F067AD3D9BCA373A0546FE8615909B0FEC (Dictionary_2_tFA4E3C6BBA632C5BEEBB77A03650502241C2D607* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_tA829CFCA6EB6821F225A3ADB1DFE03AC172EBA69 (*) (Dictionary_2_tFA4E3C6BBA632C5BEEBB77A03650502241C2D607*, const RuntimeMethod*))Dictionary_2_GetEnumerator_m3F34B328374AAC0B9166EFF8B61DBB8E41250811_gshared)(__this, method);
}
// System.Void System.Collections.Generic.Dictionary`2/Enumerator<Pico.Platform.RtcPrivilege,System.Int32>::Dispose()
inline void Enumerator_Dispose_m9ED4E52C26F04192D41980F154879E9D585E9791 (Enumerator_tA829CFCA6EB6821F225A3ADB1DFE03AC172EBA69* __this, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_tA829CFCA6EB6821F225A3ADB1DFE03AC172EBA69*, const RuntimeMethod*))Enumerator_Dispose_m80803B80A715D70AB5CF3C6EE6ECAF2A0BEFD876_gshared)(__this, method);
}
// System.Collections.Generic.KeyValuePair`2<TKey,TValue> System.Collections.Generic.Dictionary`2/Enumerator<Pico.Platform.RtcPrivilege,System.Int32>::get_Current()
inline KeyValuePair_2_t3B924E448F08153464BEA8D03A541C9BC936424A Enumerator_get_Current_mDE9C73F49F1A0AACB90F99DEB8FDC16508F49543_inline (Enumerator_tA829CFCA6EB6821F225A3ADB1DFE03AC172EBA69* __this, const RuntimeMethod* method)
{
	return ((  KeyValuePair_2_t3B924E448F08153464BEA8D03A541C9BC936424A (*) (Enumerator_tA829CFCA6EB6821F225A3ADB1DFE03AC172EBA69*, const RuntimeMethod*))Enumerator_get_Current_m511016491079A010B4344AA4E125147FAF6D679F_gshared_inline)(__this, method);
}
// TKey System.Collections.Generic.KeyValuePair`2<Pico.Platform.RtcPrivilege,System.Int32>::get_Key()
inline int32_t KeyValuePair_2_get_Key_m371FAFC80DB00656F29F2E3A607A15D8F1A4D9A2_inline (KeyValuePair_2_t3B924E448F08153464BEA8D03A541C9BC936424A* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (KeyValuePair_2_t3B924E448F08153464BEA8D03A541C9BC936424A*, const RuntimeMethod*))KeyValuePair_2_get_Key_m380DA6E4F786B9C61012C4427405FC5FD48413A1_gshared_inline)(__this, method);
}
// TValue System.Collections.Generic.KeyValuePair`2<Pico.Platform.RtcPrivilege,System.Int32>::get_Value()
inline int32_t KeyValuePair_2_get_Value_m4E42B1A68B9D4E0CD522118A7CE586CC714A92B6_inline (KeyValuePair_2_t3B924E448F08153464BEA8D03A541C9BC936424A* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (KeyValuePair_2_t3B924E448F08153464BEA8D03A541C9BC936424A*, const RuntimeMethod*))KeyValuePair_2_get_Value_m3F5DAA82C39D5EFEAE4B1F8389E1DD38732777CC_gshared_inline)(__this, method);
}
// System.Void Pico.Platform.RtcGetTokenOptions::SetPrivileges(Pico.Platform.RtcPrivilege,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcGetTokenOptions_SetPrivileges_m9BA7C7F94C4C7701F1AAF6B8AE73772F589D6F2B (RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* __this, int32_t ___0_key, int32_t ___1_value, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2/Enumerator<Pico.Platform.RtcPrivilege,System.Int32>::MoveNext()
inline bool Enumerator_MoveNext_m424B03CFB200058B8CE11047A5D7B6C0EEF5BE36 (Enumerator_tA829CFCA6EB6821F225A3ADB1DFE03AC172EBA69* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_tA829CFCA6EB6821F225A3ADB1DFE03AC172EBA69*, const RuntimeMethod*))Enumerator_MoveNext_m2B81AF70E031A662ECD2B22E5377190610523770_gshared)(__this, method);
}
// System.IntPtr Pico.Platform.RtcGetTokenOptions::op_Explicit(Pico.Platform.RtcGetTokenOptions)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t RtcGetTokenOptions_op_Explicit_m6C383C66020E9B97450516BA56A4804EE11AF49E (RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* ___0_options, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_Rtc_GetToken(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_Rtc_GetToken_m8F52B9679DC5BF49DC30C44678011848F161673A (intptr_t ___0_options, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Task`1<System.String>::.ctor(System.UInt64)
inline void Task_1__ctor_m1CF0C62EAAB2FD4823E55B281F816BE4AD7A46DC (Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF* __this, uint64_t ___0_taskId, const RuntimeMethod* method)
{
	((  void (*) (Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF*, uint64_t, const RuntimeMethod*))Task_1__ctor_mB5EFF6D4F82D6929289AD587B3332A870C2FBFEC_gshared)(__this, ___0_taskId, method);
}
// System.Void Pico.Platform.RtcRoomOptions::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRoomOptions__ctor_m753D1C11608C22036A76D99B3C862D89B347E274 (RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* __this, const RuntimeMethod* method) ;
// System.Void Pico.Platform.RtcRoomOptions::SetRoomId(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRoomOptions_SetRoomId_m1EC97F209EAB97E51EF3EEAFD8C6D62B6CAD2ED6 (RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* __this, String_t* ___0_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.RtcRoomOptions::SetUserId(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRoomOptions_SetUserId_m33FD3B38340AF5C0F0A57BFB514C5DA81BFE10BC (RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* __this, String_t* ___0_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.RtcRoomOptions::SetToken(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRoomOptions_SetToken_mE7CAA2DC3B2B75013EDE6C974339572E0CEC7CC0 (RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* __this, String_t* ___0_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.RtcRoomOptions::SetRoomProfileType(Pico.Platform.RtcRoomProfileType)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRoomOptions_SetRoomProfileType_m45350524D2610FA5CD5C4D5723EEA2A2FCF5E0F2 (RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* __this, int32_t ___0_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.RtcRoomOptions::SetIsAutoSubscribeAudio(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRoomOptions_SetIsAutoSubscribeAudio_m0A6C2D07889202383FE2627313F63E081CA25531 (RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* __this, bool ___0_value, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.RtcRoomOptions::op_Explicit(Pico.Platform.RtcRoomOptions)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t RtcRoomOptions_op_Explicit_mF71D4601FAFEA41A4EA24DBF479115F06149B7CB (RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* ___0_options, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_Rtc_JoinRoom(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_Rtc_JoinRoom_m4E5EC93A0D7A396D28CA13001EF6E6E5A49CF0B2 (intptr_t ___0_roomOptions, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.RtcService::LeaveRoom(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RtcService_LeaveRoom_m24F28302428DEE9794E878DBA9C441164D93269E (String_t* ___0_roomId, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_Rtc_LeaveRoom(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_Rtc_LeaveRoom_m97EBB2B10B3323F2917A661B3FC3899C778F0092 (String_t* ___0_roomId, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_Rtc_SetAudioPlaybackDevice(Pico.Platform.RtcAudioPlaybackDevice)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_Rtc_SetAudioPlaybackDevice_mD1332D4C61830FC5FA37D79D79B7AAE9A4B29444 (int32_t ___0_device, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_Rtc_RoomPauseAllSubscribedStream(System.String,Pico.Platform.RtcPauseResumeMediaType)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_Rtc_RoomPauseAllSubscribedStream_m34D0AD40880E89C0C1370213858B61D7D06055E8 (String_t* ___0_roomId, int32_t ___1_mediaType, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_Rtc_RoomResumeAllSubscribedStream(System.String,Pico.Platform.RtcPauseResumeMediaType)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_Rtc_RoomResumeAllSubscribedStream_m8DAEA8FA957F0E6CCC78DCAD0F482BFAECAECFF5 (String_t* ___0_roomId, int32_t ___1_mediaType, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.RtcAudioFrame::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcAudioFrame__ctor_mAF8A3A50316BDC0FFFE39C0FCF28E25F185B5E9A (RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.RtcService/ProcessAudioFrameFunction::Invoke(Pico.Platform.Models.RtcAudioFrame)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t ProcessAudioFrameFunction_Invoke_m5EC2CDFD611F5CDC64BD8A36A025E8C08FF061D6_inline (ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5* __this, RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59* ___0_frame, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB/RtcProcessAudioFrameFunction::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcProcessAudioFrameFunction__ctor_m55F453E056A84CA415A7E8B7CF428BF0A7901A50 (RtcProcessAudioFrameFunction_t91998EE2CD7760356A3A9E75620AEB591C1F2344* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_Rtc_RegisterLocalAudioProcessor(Pico.Platform.CLIB/RtcProcessAudioFrameFunction,Pico.Platform.RtcAudioChannel,Pico.Platform.RtcAudioSampleRate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_Rtc_RegisterLocalAudioProcessor_mF40BE44B52397C73F3E98736217222546F1FE166 (RtcProcessAudioFrameFunction_t91998EE2CD7760356A3A9E75620AEB591C1F2344* ___0_rtcProcessAudioFrameFunction, int32_t ___1_channel, int32_t ___2_sampleRate, const RuntimeMethod* method) ;
// System.Void Pico.Platform.RtcAudioPropertyOptions::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcAudioPropertyOptions__ctor_m5D01ABC1098566CAD6A7000775D6CA381D70509F (RtcAudioPropertyOptions_t5E394E488DDCF996DB82E9326E71B465A4D6D23E* __this, const RuntimeMethod* method) ;
// System.Void Pico.Platform.RtcAudioPropertyOptions::SetInterval(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcAudioPropertyOptions_SetInterval_m8075C50D77C3347FB74433C8D73FBA38E3416005 (RtcAudioPropertyOptions_t5E394E488DDCF996DB82E9326E71B465A4D6D23E* __this, int32_t ___0_value, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.RtcAudioPropertyOptions::op_Explicit(Pico.Platform.RtcAudioPropertyOptions)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t RtcAudioPropertyOptions_op_Explicit_mAA54B25B681E9C597F68538D3339153E5748FB9A (RtcAudioPropertyOptions_t5E394E488DDCF996DB82E9326E71B465A4D6D23E* ___0_options, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_Rtc_EnableAudioPropertiesReport(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_Rtc_EnableAudioPropertiesReport_m97025C0A2787682A37CEEFC30F7DBB89D5831533 (intptr_t ___0_config, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_Rtc_RoomPublishStream(System.String,Pico.Platform.RtcMediaStreamType)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_Rtc_RoomPublishStream_m999BF20CA150068F21BB66C40AD84A9768BC2033 (String_t* ___0_roomId, int32_t ___1_streamType, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_Rtc_RoomUnPublishStream(System.String,Pico.Platform.RtcMediaStreamType)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_Rtc_RoomUnPublishStream_m00FEBEC578FA2194B9E8A8B48FBFB928E5FDB138 (String_t* ___0_roomId, int32_t ___1_streamType, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_Rtc_DestroyRoom(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_Rtc_DestroyRoom_m9624553A2D673BC8441668054A0456836613D50D (String_t* ___0_roomId, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_Rtc_StartAudioCapture()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_Rtc_StartAudioCapture_m8700CD4674A20317315792FF01A293DC9EE03B5D (const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_Rtc_StopAudioCapture()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_Rtc_StopAudioCapture_m9314204AA68DEC851FD5F446DB4E65B1B7DCC67E (const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_Rtc_SetCaptureVolume(Pico.Platform.RtcStreamIndex,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_Rtc_SetCaptureVolume_mF57DFC4F22BF53E417A49455A3FB35D4E80CFC73 (int32_t ___0_index, int32_t ___1_volume, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_Rtc_SetPlaybackVolume(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_Rtc_SetPlaybackVolume_m5C43C4FF094E1034EA128BF265E10B7055C65A8D (int32_t ___0_volume, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_Rtc_SetEarMonitorMode(Pico.Platform.RtcEarMonitorMode)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_Rtc_SetEarMonitorMode_m3A40312D08EF057E864EC56020773481AB184F0C (int32_t ___0_earMonitorMode, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_Rtc_SetEarMonitorVolume(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_Rtc_SetEarMonitorVolume_m18A7BBD03541E7EFF142C6F976D002BBB9D61AE4 (int32_t ___0_volume, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_Rtc_MuteLocalAudio(Pico.Platform.RtcMuteState)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_Rtc_MuteLocalAudio_m77706FE3988E9393BACD03870F2641AD938DDA7E (int32_t ___0_muteState, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_Rtc_UpdateToken(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_Rtc_UpdateToken_mF6E21D718D5EA93B515E07C2DFFCCFD96985EDBB (String_t* ___0_roomId, String_t* ___1_token, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_Rtc_SetAudioScenario(Pico.Platform.RtcAudioScenarioType)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_Rtc_SetAudioScenario_mC636AA2606FA3F31BE8BF487B8B05CA8E88B0EA1 (int32_t ___0_scenario, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_Rtc_RoomSetRemoteAudioPlaybackVolume(System.String,System.String,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_Rtc_RoomSetRemoteAudioPlaybackVolume_m7433C4EC934EE144B19D75B7AE556CC89EFCF6EB (String_t* ___0_roomId, String_t* ___1_userId, int32_t ___2_volume, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_Rtc_RoomSubscribeStream(System.String,System.String,Pico.Platform.RtcMediaStreamType)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_Rtc_RoomSubscribeStream_mC7D8349F283518760FF8D7C1068651DF3B7DC779 (String_t* ___0_roomId, String_t* ___1_userId, int32_t ___2_mediaType, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_Rtc_RoomUnsubscribeStream(System.String,System.String,Pico.Platform.RtcMediaStreamType)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_Rtc_RoomUnsubscribeStream_m3C9352F9B827AC824A03C96E5FFA327C8D8CBF7F (String_t* ___0_roomId, String_t* ___1_userId, int32_t ___2_mediaType, const RuntimeMethod* method) ;
// System.Void Pico.Platform.PtrManager::.ctor(System.Byte[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PtrManager__ctor_m7BEAACAEBEE05EF15116C986BAB9A1DA2002A478 (PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_a, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_Rtc_SendRoomBinaryMessage(System.String,System.IntPtr,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_Rtc_SendRoomBinaryMessage_m3ED7D7134269914FE9FC7EB789C89658EB6FDA8F (String_t* ___0_roomId, intptr_t ___1_message, int32_t ___2_length, const RuntimeMethod* method) ;
// System.Void Pico.Platform.PtrManager::Free()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PtrManager_Free_mF57A82180453684532E9C29833A96C28D8BA7D05 (PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2* __this, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_Rtc_SendRoomMessage(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_Rtc_SendRoomMessage_m9E0EBE88DD65721EFE48D813A74C22860A8A03B5 (String_t* ___0_roomId, String_t* ___1_message, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_Rtc_SendUserBinaryMessage(System.String,System.String,System.IntPtr,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_Rtc_SendUserBinaryMessage_m822EB94F0C78D74D76EF162C90ADA3F3B56E936F (String_t* ___0_roomId, String_t* ___1_userId, intptr_t ___2_message, int32_t ___3_length, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_Rtc_SendUserMessage(System.String,System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_Rtc_SendUserMessage_mF5F42745A4FEF34004712FB21A340155506CEF01 (String_t* ___0_roomId, String_t* ___1_userId, String_t* ___2_message, const RuntimeMethod* method) ;
// System.Void Pico.Platform.RtcStreamSyncInfoOptions::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcStreamSyncInfoOptions__ctor_m9D86B190CCE9ADF893542CCB8FEB7EEF4309CE7E (RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073* __this, const RuntimeMethod* method) ;
// System.Void Pico.Platform.RtcStreamSyncInfoOptions::SetRepeatCount(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcStreamSyncInfoOptions_SetRepeatCount_mEC362A0008CECC40F6C5B3DE011BC44DBE66256B (RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073* __this, int32_t ___0_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.RtcStreamSyncInfoOptions::SetStreamIndex(Pico.Platform.RtcStreamIndex)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcStreamSyncInfoOptions_SetStreamIndex_m76FF4534D8271C81C0263995DC0554961184DA34 (RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073* __this, int32_t ___0_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.RtcStreamSyncInfoOptions::SetStreamType(Pico.Platform.RtcSyncInfoStreamType)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcStreamSyncInfoOptions_SetStreamType_m75AF0A32A37BC87F68C105FB7DA0E3737C3BF977 (RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073* __this, int32_t ___0_value, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.RtcStreamSyncInfoOptions::op_Explicit(Pico.Platform.RtcStreamSyncInfoOptions)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t RtcStreamSyncInfoOptions_op_Explicit_m36286E8D49E4A5A299A71C763E9421343B2E71FC (RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073* ___0_options, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_Rtc_SendStreamSyncInfo(System.IntPtr,System.Int32,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_Rtc_SendStreamSyncInfo_mA91C187D432205B5CE0234D1EB60B7B78A216F69 (intptr_t ___0_data, int32_t ___1_length, intptr_t ___2_config, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Looper::RegisterNotifyHandler(Pico.Platform.MessageType,System.Delegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015 (int32_t ___0_type, Delegate_t* ___1_handler, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_RtcStreamSyncInfoOptions_Create()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_RtcStreamSyncInfoOptions_Create_m58EE568E749D28D2598EBBAC97492FD722157648 (const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RtcStreamSyncInfoOptions_SetRepeatCount(System.IntPtr,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RtcStreamSyncInfoOptions_SetRepeatCount_m3A7E7085D9B3106EC3B39654CE672545D328F178 (intptr_t ___0_obj, int32_t ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RtcStreamSyncInfoOptions_SetStreamIndex(System.IntPtr,Pico.Platform.RtcStreamIndex)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RtcStreamSyncInfoOptions_SetStreamIndex_m792067CEFBC2A89E1C18D06B77E9A83018885817 (intptr_t ___0_obj, int32_t ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RtcStreamSyncInfoOptions_SetStreamType(System.IntPtr,Pico.Platform.RtcSyncInfoStreamType)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RtcStreamSyncInfoOptions_SetStreamType_mDB18D271F6C9F70032C64E7CF46398F4658E43C4 (intptr_t ___0_obj, int32_t ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RtcStreamSyncInfoOptions_Destroy(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RtcStreamSyncInfoOptions_Destroy_m340714991FE081051E645B634A1A80297A5A90F8 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_RtcRoomOptions_Create()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_RtcRoomOptions_Create_m5A7470272AD4EB1BCE2680FD1849D82B268458BD (const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RtcRoomOptions_SetRoomProfileType(System.IntPtr,Pico.Platform.RtcRoomProfileType)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RtcRoomOptions_SetRoomProfileType_mA8D5D60BE6D0D635E4378B9B8414E435F15561C7 (intptr_t ___0_obj, int32_t ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RtcRoomOptions_SetIsAutoSubscribeAudio(System.IntPtr,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RtcRoomOptions_SetIsAutoSubscribeAudio_m2B2FE59EC7F5C5CF7C06767CCBFC3DAC14D5D897 (intptr_t ___0_obj, bool ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RtcRoomOptions_SetRoomId(System.IntPtr,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RtcRoomOptions_SetRoomId_mB4AA3C4EF1DCB602E71CD0FB733CDC7E3E818D40 (intptr_t ___0_obj, String_t* ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RtcRoomOptions_SetUserId(System.IntPtr,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RtcRoomOptions_SetUserId_mE7B72158E324346228B79051D3501F4E015B3576 (intptr_t ___0_obj, String_t* ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RtcRoomOptions_SetUserExtra(System.IntPtr,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RtcRoomOptions_SetUserExtra_mB595CA8CF567FE5164530CB9B9E898570C8BCF62 (intptr_t ___0_obj, String_t* ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RtcRoomOptions_SetToken(System.IntPtr,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RtcRoomOptions_SetToken_m35F8E820E30889AE95CBE3C9AD32D062E538B724 (intptr_t ___0_obj, String_t* ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RtcRoomOptions_Destroy(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RtcRoomOptions_Destroy_mB4989A466D6F0B28733950F3CF5E403F1AA1CECC (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_RtcGetTokenOptions_Create()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_RtcGetTokenOptions_Create_mA61E59DCF1BC9FB87A723CC4AFC9D21F190FA845 (const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RtcGetTokenOptions_SetUserId(System.IntPtr,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RtcGetTokenOptions_SetUserId_m586793AA5C1529DC2386DEE4AA59F09382A1E700 (intptr_t ___0_obj, String_t* ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RtcGetTokenOptions_SetRoomId(System.IntPtr,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RtcGetTokenOptions_SetRoomId_mE00C2681841BEB04C1D8289CCA8B6B2CB5C1D055 (intptr_t ___0_obj, String_t* ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RtcGetTokenOptions_SetTtl(System.IntPtr,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RtcGetTokenOptions_SetTtl_m65237B01F848B526EFD856E0F588E1E1E32556AE (intptr_t ___0_obj, int32_t ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RtcGetTokenOptions_SetPrivileges(System.IntPtr,Pico.Platform.RtcPrivilege,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RtcGetTokenOptions_SetPrivileges_m66B6F166451610D8A4F3516EF60415E746A4316A (intptr_t ___0_obj, int32_t ___1_k, int32_t ___2_v, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RtcGetTokenOptions_ClearPrivileges(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RtcGetTokenOptions_ClearPrivileges_m7EEEBA39B866C6DF24D7D63CDF3E1151486EA9CE (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RtcGetTokenOptions_Destroy(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RtcGetTokenOptions_Destroy_m032E141DBA3E2792D3C706C675E5EF127E3CE6E9 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_RtcAudioPropertyOptions_Create()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_RtcAudioPropertyOptions_Create_mCCF97FD2B44B3BC089C254253E58CD2B11BD3D42 (const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RtcAudioPropertyOptions_SetInterval(System.IntPtr,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RtcAudioPropertyOptions_SetInterval_m60586BE91C418B9D72AF664F47B6946E52FD4AF3 (intptr_t ___0_obj, int32_t ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_RtcAudioPropertyOptions_Destroy(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_RtcAudioPropertyOptions_Destroy_mF7FBEB5F27F730C5FBDF659D820A88B28E7B2A15 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.AsrEngineInitResult Pico.Platform.CLIB::ppf_Speech_InitAsrEngine()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_Speech_InitAsrEngine_mE4DC5D454207DDC4C1C6814D8E704CDF7AE60145 (const RuntimeMethod* method) ;
// System.Void Pico.Platform.StartAsrOptions::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartAsrOptions__ctor_m9051AC9B99E34B2FA533CF775053B6BB8961A465 (StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F* __this, const RuntimeMethod* method) ;
// System.Void Pico.Platform.StartAsrOptions::SetAutoStop(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartAsrOptions_SetAutoStop_mA87C46C8228C8658306339DF20A6100479737B90 (StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F* __this, bool ___0_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.StartAsrOptions::SetShowPunctual(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartAsrOptions_SetShowPunctual_m08A66F2736751EDAFA614A573E4472A929AD48F7 (StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F* __this, bool ___0_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.StartAsrOptions::SetVadMaxDurationInSeconds(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartAsrOptions_SetVadMaxDurationInSeconds_mD7132FE9CAD9A57A747C78F8C231C67422054D2F (StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F* __this, int32_t ___0_value, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.StartAsrOptions::op_Explicit(Pico.Platform.StartAsrOptions)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t StartAsrOptions_op_Explicit_m9AAFCEA0EFAD89ECFFD8F5F0ED0EF5425874EF63 (StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F* ___0_options, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_Speech_StartAsr(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_Speech_StartAsr_m9F0659C938B2EB972D51DD56A21EDC2F56E4E825 (intptr_t ___0_option, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_Speech_StopAsr()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_Speech_StopAsr_m152FA1B9067EBF9B11C9423A3C9D9B93A3D3514B (const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_StartAsrOptions_Create()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_StartAsrOptions_Create_mD16FDD2ADE6427BED56C2BE226202C86731FF6B5 (const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_StartAsrOptions_SetAutoStop(System.IntPtr,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_StartAsrOptions_SetAutoStop_mC46EA758EB5C3935B5CF77049A28B90E54A313AE (intptr_t ___0_obj, bool ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_StartAsrOptions_SetVadMaxDurationInSeconds(System.IntPtr,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_StartAsrOptions_SetVadMaxDurationInSeconds_m58766F2DEFA01B015B6CF08C4E664B3CB02BA244 (intptr_t ___0_obj, int32_t ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_StartAsrOptions_SetShowPunctual(System.IntPtr,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_StartAsrOptions_SetShowPunctual_m634A7C0830075E813E254431252C8EE4741A5E8A (intptr_t ___0_obj, bool ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_StartAsrOptions_Destroy(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_StartAsrOptions_Destroy_mD0E1920B99B37A0E6A111E1D37C9824F4AC7E3C6 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_Sport_GetUserInfo()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_Sport_GetUserInfo_m2A8BA47ED2F14BD2E2870466C7780D4E4F925A47 (const RuntimeMethod* method) ;
// System.Void Pico.Platform.Task`1<Pico.Platform.Models.SportUserInfo>::.ctor(System.UInt64)
inline void Task_1__ctor_m663084DE28D5D98B9394EDB79C8DF0E4CCEB3CC9 (Task_1_t1B92E95AEAE34C4D979EA9DC46E4A0B69313B747* __this, uint64_t ___0_taskId, const RuntimeMethod* method)
{
	((  void (*) (Task_1_t1B92E95AEAE34C4D979EA9DC46E4A0B69313B747*, uint64_t, const RuntimeMethod*))Task_1__ctor_mB5EFF6D4F82D6929289AD587B3332A870C2FBFEC_gshared)(__this, ___0_taskId, method);
}
// System.Int64 Pico.Platform.TimeUtil::DateTimeToMilliSeconds(System.DateTime)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t TimeUtil_DateTimeToMilliSeconds_mB80B1C7EA348F059DB520F63D61898BD07D82E53 (DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___0_t, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_Sport_GetDailySummary(System.Int64,System.Int64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_Sport_GetDailySummary_m1294198CD9DA6F48D82E9161612C8BE9D554AEA5 (int64_t ___0_beginTime, int64_t ___1_endTime, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Task`1<Pico.Platform.Models.SportDailySummaryList>::.ctor(System.UInt64)
inline void Task_1__ctor_mAF2B532E3BB55BD9BDA955D466B020D6C389AEE6 (Task_1_t1B98E66164E4AE432D604C7B75AF7848981FF051* __this, uint64_t ___0_taskId, const RuntimeMethod* method)
{
	((  void (*) (Task_1_t1B98E66164E4AE432D604C7B75AF7848981FF051*, uint64_t, const RuntimeMethod*))Task_1__ctor_mB5EFF6D4F82D6929289AD587B3332A870C2FBFEC_gshared)(__this, ___0_taskId, method);
}
// System.UInt64 Pico.Platform.CLIB::ppf_Sport_GetSummary(System.Int64,System.Int64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_Sport_GetSummary_m55B952DC067DD8A59593BF9F070FCCA547831744 (int64_t ___0_beginTime, int64_t ___1_endTime, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Task`1<Pico.Platform.Models.SportSummary>::.ctor(System.UInt64)
inline void Task_1__ctor_mCDB56AC9CB59A5C05526C208A7E6DBDB1AA37F66 (Task_1_tB6CDA113D3E1699F4874976AC36FB7624B4F9244* __this, uint64_t ___0_taskId, const RuntimeMethod* method)
{
	((  void (*) (Task_1_tB6CDA113D3E1699F4874976AC36FB7624B4F9244*, uint64_t, const RuntimeMethod*))Task_1__ctor_mB5EFF6D4F82D6929289AD587B3332A870C2FBFEC_gshared)(__this, ___0_taskId, method);
}
// System.UInt64 Pico.Platform.CLIB::ppf_User_GetAccessToken()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_User_GetAccessToken_m4B8E4EA084A131250844BE9C53EC722FC06C5628 (const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_User_GetOrgScopedID(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_User_GetOrgScopedID_m6B22DE2722B232E577B9DCFF97820F487B0D676D (String_t* ___0_userID, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Task`1<Pico.Platform.Models.OrgScopedID>::.ctor(System.UInt64)
inline void Task_1__ctor_m59D89B840C2D9E7B876A8866DCA1A7BD562B7E56 (Task_1_tED4A061EA242D6FF39FF61442A0E7F55A6880B2E* __this, uint64_t ___0_taskId, const RuntimeMethod* method)
{
	((  void (*) (Task_1_tED4A061EA242D6FF39FF61442A0E7F55A6880B2E*, uint64_t, const RuntimeMethod*))Task_1__ctor_mB5EFF6D4F82D6929289AD587B3332A870C2FBFEC_gshared)(__this, ___0_taskId, method);
}
// System.UInt64 Pico.Platform.CLIB::ppf_User_GetLoggedInUser()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_User_GetLoggedInUser_m735249852E8973AC38B5117E8C481C81B3B540E0 (const RuntimeMethod* method) ;
// System.Void Pico.Platform.Task`1<Pico.Platform.Models.User>::.ctor(System.UInt64)
inline void Task_1__ctor_m322A3D30581A57328E35B1AA000C12DA27802B9B (Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42* __this, uint64_t ___0_taskId, const RuntimeMethod* method)
{
	((  void (*) (Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42*, uint64_t, const RuntimeMethod*))Task_1__ctor_mB5EFF6D4F82D6929289AD587B3332A870C2FBFEC_gshared)(__this, ___0_taskId, method);
}
// System.UInt64 Pico.Platform.CLIB::ppf_User_Get(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_User_Get_m282DFCBEA159F8A3FCFBFCFD6735219277A45EAB (String_t* ___0_userID, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_User_GetLoggedInUserFriends()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_User_GetLoggedInUserFriends_m7D5683CE9CCA26BE5DF700F094695DC418E50055 (const RuntimeMethod* method) ;
// System.Void Pico.Platform.Task`1<Pico.Platform.Models.UserList>::.ctor(System.UInt64)
inline void Task_1__ctor_m50BEB35518BC513A0C8F5CAE163C038761DDEBD7 (Task_1_tEFD858E38F809577D01E5C61C4E04401C1579F24* __this, uint64_t ___0_taskId, const RuntimeMethod* method)
{
	((  void (*) (Task_1_tEFD858E38F809577D01E5C61C4E04401C1579F24*, uint64_t, const RuntimeMethod*))Task_1__ctor_mB5EFF6D4F82D6929289AD587B3332A870C2FBFEC_gshared)(__this, ___0_taskId, method);
}
// System.UInt64 Pico.Platform.CLIB::ppf_User_GetRelations(System.String[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_User_GetRelations_m2524B1C0BAF70D69E96276AFDB1DAEAFCDF54F98 (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___0_userIds, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Task`1<Pico.Platform.Models.UserRelationResult>::.ctor(System.UInt64)
inline void Task_1__ctor_m970BDF1E00FFB8C1E8DF0B795F86CADC4D0FFAA5 (Task_1_tB4B0FA80F5FD7ED902B09091C88E2146F2BAE9C1* __this, uint64_t ___0_taskId, const RuntimeMethod* method)
{
	((  void (*) (Task_1_tB4B0FA80F5FD7ED902B09091C88E2146F2BAE9C1*, uint64_t, const RuntimeMethod*))Task_1__ctor_mB5EFF6D4F82D6929289AD587B3332A870C2FBFEC_gshared)(__this, ___0_taskId, method);
}
// System.UInt64 Pico.Platform.CLIB::ppf_User_LaunchFriendRequestFlow(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_User_LaunchFriendRequestFlow_m15E2D4F598E46D37667BC00EB358F9723BCCC72D (String_t* ___0_userID, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Task`1<Pico.Platform.Models.LaunchFriendResult>::.ctor(System.UInt64)
inline void Task_1__ctor_m6C02EE853BD7EA7A09FCD1178C0CC092548CD102 (Task_1_t89353573F66DF40A563FFC7023237C238E5D7F0D* __this, uint64_t ___0_taskId, const RuntimeMethod* method)
{
	((  void (*) (Task_1_t89353573F66DF40A563FFC7023237C238E5D7F0D*, uint64_t, const RuntimeMethod*))Task_1__ctor_mB5EFF6D4F82D6929289AD587B3332A870C2FBFEC_gshared)(__this, ___0_taskId, method);
}
// System.UInt64 Pico.Platform.CLIB::ppf_User_GetLoggedInUserFriendsAndRooms()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_User_GetLoggedInUserFriendsAndRooms_m902D49F2E864C23B23316F0DD046C9B6E68FD055 (const RuntimeMethod* method) ;
// System.Void Pico.Platform.Task`1<Pico.Platform.Models.UserRoomList>::.ctor(System.UInt64)
inline void Task_1__ctor_m7C42D45457C38313FD29A5A7B8FA37EBD5C083BB (Task_1_t63D243DB7237B9BDC42B877FB86F30ABDF4C37EF* __this, uint64_t ___0_taskId, const RuntimeMethod* method)
{
	((  void (*) (Task_1_t63D243DB7237B9BDC42B877FB86F30ABDF4C37EF*, uint64_t, const RuntimeMethod*))Task_1__ctor_mB5EFF6D4F82D6929289AD587B3332A870C2FBFEC_gshared)(__this, ___0_taskId, method);
}
// System.Boolean Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.UserRoom>::get_HasNextPage()
inline bool MessageArray_1_get_HasNextPage_m72A1A98F96C990D8BA6BA6E2FAA11C72813859E0 (MessageArray_1_tBDB39162E4555FCBD64BB106117908AC8831F004* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (MessageArray_1_tBDB39162E4555FCBD64BB106117908AC8831F004*, const RuntimeMethod*))MessageArray_1_get_HasNextPage_mB9584B37665BB97F4772D4A8950F48C0CECB86F5_gshared)(__this, method);
}
// System.Void UnityEngine.Debug::LogWarning(System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Debug_LogWarning_m33EF1B897E0C7C6FF538989610BFAFFEF4628CA9 (RuntimeObject* ___0_message, const RuntimeMethod* method) ;
// System.Boolean System.String::IsNullOrEmpty(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478 (String_t* ___0_value, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_User_GetNextUserAndRoomArrayPage(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_User_GetNextUserAndRoomArrayPage_m34B809096725072233997C2D085FD30289F61B8F (String_t* ___0_param, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.User>::get_HasNextPage()
inline bool MessageArray_1_get_HasNextPage_m3E11E7F669019355A0341BB70330132A889C7709 (MessageArray_1_t3FBFD71C2ED89BC1E98F61EFDB0C5C6DADE06A17* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (MessageArray_1_t3FBFD71C2ED89BC1E98F61EFDB0C5C6DADE06A17*, const RuntimeMethod*))MessageArray_1_get_HasNextPage_mB9584B37665BB97F4772D4A8950F48C0CECB86F5_gshared)(__this, method);
}
// System.UInt64 Pico.Platform.CLIB::ppf_User_GetNextUserArrayPage(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_User_GetNextUserArrayPage_m630DE021C106AE95F1BAA9F1026E472B231D0F83 (String_t* ___0_param, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_User_GetAuthorizedPermissions()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_User_GetAuthorizedPermissions_m6880448E60B81B9F798A4F5204F2204E46CE4601 (const RuntimeMethod* method) ;
// System.Void Pico.Platform.Task`1<Pico.Platform.Models.PermissionResult>::.ctor(System.UInt64)
inline void Task_1__ctor_m97DCC7BC2E162881ED2A246242E9A4C8D61C82A3 (Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF* __this, uint64_t ___0_taskId, const RuntimeMethod* method)
{
	((  void (*) (Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF*, uint64_t, const RuntimeMethod*))Task_1__ctor_mB5EFF6D4F82D6929289AD587B3332A870C2FBFEC_gshared)(__this, ___0_taskId, method);
}
// System.UInt64 Pico.Platform.CLIB::ppf_User_RequestUserPermissions(System.String[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_User_RequestUserPermissions_m0ADE8D5D1456A820208263EDBE7BB50D1F3D6213 (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___0_permissions, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_User_EntitlementCheck(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_User_EntitlementCheck_mAC2BD7051DB1F53018404540E98BBB8A5675EEF7 (bool ___0_killApp, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Task`1<Pico.Platform.Models.EntitlementCheckResult>::.ctor(System.UInt64)
inline void Task_1__ctor_mFAD053AE97133C07CA97D23B1899267A85F7C677 (Task_1_t6577C6759208FE196021557BB439FE81946FDB36* __this, uint64_t ___0_taskId, const RuntimeMethod* method)
{
	((  void (*) (Task_1_t6577C6759208FE196021557BB439FE81946FDB36*, uint64_t, const RuntimeMethod*))Task_1__ctor_mB5EFF6D4F82D6929289AD587B3332A870C2FBFEC_gshared)(__this, ___0_taskId, method);
}
// System.UInt64 Pico.Platform.CLIB::ppf_User_GetIdToken()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_User_GetIdToken_m66CB8D500505BAC1F462B2C8672030BF54F2AA63 (const RuntimeMethod* method) ;
// UnityEngine.GameObject UnityEngine.GameObject::Find(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* GameObject_Find_m7A669B4EEC2617AB82F6E3FF007CDCD9F21DB300 (String_t* ___0_name, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Object::op_Equality(UnityEngine.Object,UnityEngine.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_x, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_y, const RuntimeMethod* method) ;
// System.Void UnityEngine.GameObject::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameObject__ctor_m37D512B05D292F954792225E6C6EEE95293A9B88 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, String_t* ___0_name, const RuntimeMethod* method) ;
// T UnityEngine.GameObject::GetComponent<Pico.Platform.Framework.Runner>()
inline Runner_tB8E78BC8FEC1129C330C7EF44FE5BBFC57BFB7B8* GameObject_GetComponent_TisRunner_tB8E78BC8FEC1129C330C7EF44FE5BBFC57BFB7B8_m02D34C860CE1EDFBEE672B22BBD2AD9E6B55DEA9 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method)
{
	return ((  Runner_tB8E78BC8FEC1129C330C7EF44FE5BBFC57BFB7B8* (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, const RuntimeMethod*))GameObject_GetComponent_TisRuntimeObject_m6EAED4AA356F0F48288F67899E5958792395563B_gshared)(__this, method);
}
// T UnityEngine.GameObject::AddComponent<Pico.Platform.Framework.Runner>()
inline Runner_tB8E78BC8FEC1129C330C7EF44FE5BBFC57BFB7B8* GameObject_AddComponent_TisRunner_tB8E78BC8FEC1129C330C7EF44FE5BBFC57BFB7B8_m274D6F612B4E1E560945FD2406F657DBE0060979 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method)
{
	return ((  Runner_tB8E78BC8FEC1129C330C7EF44FE5BBFC57BFB7B8* (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, const RuntimeMethod*))GameObject_AddComponent_TisRuntimeObject_m69B93700FACCF372F5753371C6E8FB780800B824_gshared)(__this, method);
}
// UnityEngine.GameObject UnityEngine.Component::get_gameObject()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.Object::DontDestroyOnLoad(UnityEngine.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object_DontDestroyOnLoad_m4B70C3AEF886C176543D1295507B6455C9DCAEA7 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_target, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Looper::ProcessMessages(System.UInt32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Looper_ProcessMessages_m7C7CF1ACF44351564A132E7D90171E90E0FFF932 (uint32_t ___0_limit, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Looper::Clear()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Looper_Clear_m0DA1691ED55DF49956837BAC3D0885DBE57AA21C (const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Application::get_isEditor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Application_get_isEditor_mEAC51E3ACE6DCE438087FB14BD75A3C219D354D0 (const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_PcUnInitialize()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_PcUnInitialize_m7074DC685E62F923952DB2D230FDD635EFCEFFB5 (const RuntimeMethod* method) ;
// System.Void UnityEngine.MonoBehaviour::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_Error_GetCode(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_Error_GetCode_m83CDC4F4594220EB3E1728EC2A12C0A97C1DF726 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Error_GetMessage(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Error_GetMessage_m67E801205964BF67CCAB45CAB6EEED1CF1569EE3 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String System.String::Format(System.String,System.Object,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987 (String_t* ___0_format, RuntimeObject* ___1_arg0, RuntimeObject* ___2_arg1, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_AchievementUpdate_GetJustUnlocked(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_AchievementUpdate_GetJustUnlocked_m649313BA69DC60BF18A61930E31805AC67E98399 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AchievementUpdate_GetName(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AchievementUpdate_GetName_m74D11D889569EA272F04A388E3067B305940D4BA (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.AchievementType Pico.Platform.CLIB::ppf_AchievementDefinition_GetType(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_AchievementDefinition_GetType_m9ED9C6E33230099A352866C55612557A86CD8E76 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AchievementDefinition_GetName(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AchievementDefinition_GetName_m40AC711F58D6D47429F62626D6E530D233E998C4 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt32 Pico.Platform.CLIB::ppf_AchievementDefinition_GetBitfieldLength(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t CLIB_ppf_AchievementDefinition_GetBitfieldLength_m9ABE1530AF84F78881367F12E2E462F64B00EB80 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_AchievementDefinition_GetTarget(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_AchievementDefinition_GetTarget_mDB8C95FE116B50EEE4E5440E341878379AA092C4 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AchievementDefinition_GetDescription(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AchievementDefinition_GetDescription_m5B17D99559144012DBABC08D342B5DD54DFD2162 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AchievementDefinition_GetTitle(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AchievementDefinition_GetTitle_m269BD7513E21E364284135C41D4EDDCC94D22C09 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_AchievementDefinition_IsArchived(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_AchievementDefinition_IsArchived_mE1F890443D813FEF7A395BC7864C8BEFBDB4C73D (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_AchievementDefinition_IsSecret(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_AchievementDefinition_IsSecret_mB164028EA11B9DD095C58CB35E1E88E43056F23D (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_AchievementDefinition_GetID(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_AchievementDefinition_GetID_m13BE35631301DF777173A6EC78812006AEFD64A6 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AchievementDefinition_GetUnlockedDescription(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AchievementDefinition_GetUnlockedDescription_m237E276A6D957899D343541C7D68432B9CE2C595 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.AchievementWritePolicy Pico.Platform.CLIB::ppf_AchievementDefinition_GetWritePolicy(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_AchievementDefinition_GetWritePolicy_m68421AA81D7BF8C02FE42377293DDCE8B9F27C65 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AchievementDefinition_GetLockedImageURL(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AchievementDefinition_GetLockedImageURL_mC21FCE13618FE80315D9FE5849F2111E5A8CD045 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AchievementDefinition_GetUnlockedImageURL(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AchievementDefinition_GetUnlockedImageURL_mCD98CBABA4DBD7899BF2D6997CB8692029CB8FDF (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.AchievementDefinition>::.ctor()
inline void MessageArray_1__ctor_m7E276C8FEE63D2AA74F36394E1EBE4DA877D36C4 (MessageArray_1_t007C8F0F960A812D5EBEBD1E0DEB87A40D9F0051* __this, const RuntimeMethod* method)
{
	((  void (*) (MessageArray_1_t007C8F0F960A812D5EBEBD1E0DEB87A40D9F0051*, const RuntimeMethod*))MessageArray_1__ctor_m9B6627200A9DB24455505C010AE4DD7BEF61F451_gshared)(__this, method);
}
// System.UIntPtr Pico.Platform.CLIB::ppf_AchievementDefinitionArray_GetTotalSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_AchievementDefinitionArray_GetTotalSize_mF31F7BDA19A5EA6C45A634BF599151A0463080F1 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 System.UIntPtr::op_Explicit(System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t UIntPtr_op_Explicit_mC39E70F0324C1C514A3044790BC19C5FC4C58E1C (uintptr_t ___0_value, const RuntimeMethod* method) ;
// System.UIntPtr Pico.Platform.CLIB::ppf_AchievementDefinitionArray_GetSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_AchievementDefinitionArray_GetSize_m51F7C01149B2A39AC0283478E501E55EC399BB6E (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt32 System.UIntPtr::op_Explicit(System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8 (uintptr_t ___0_value, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.AchievementDefinition>::set_Capacity(System.Int32)
inline void List_1_set_Capacity_mD3BF3BBF9B8537037A4A49B234555D9FDC3C7F1E (List_1_t10AC4D431308924325EECB4A49074CCAD3525C5D* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_t10AC4D431308924325EECB4A49074CCAD3525C5D*, int32_t, const RuntimeMethod*))List_1_set_Capacity_mD826E33A9E5EBC19C714653217071790693E0B95_gshared)(__this, ___0_value, method);
}
// System.UIntPtr System.UIntPtr::op_Explicit(System.UInt32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t UIntPtr_op_Explicit_mD94DCD8965DD2E7D5A3370A04CCEDBE5937C078C (uint32_t ___0_value, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_AchievementDefinitionArray_GetElement(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_AchievementDefinitionArray_GetElement_m1EB6B1FB8C5A866418BA5CFA4F3C7D4B8BA373A8 (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.AchievementDefinition::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AchievementDefinition__ctor_mBFA904DECEC666C753BB00AFBC500B34BDB73A65 (AchievementDefinition_t09D5E334A9AF0321426DB09B4B36E72626423019* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.AchievementDefinition>::Add(T)
inline void List_1_Add_m7817B44F55F4B07BD59D677CB6CAD10D578EAC86_inline (List_1_t10AC4D431308924325EECB4A49074CCAD3525C5D* __this, AchievementDefinition_t09D5E334A9AF0321426DB09B4B36E72626423019* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t10AC4D431308924325EECB4A49074CCAD3525C5D*, AchievementDefinition_t09D5E334A9AF0321426DB09B4B36E72626423019*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.Boolean Pico.Platform.CLIB::ppf_AchievementDefinitionArray_HasNextPage(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_AchievementDefinitionArray_HasNextPage_m263DA3AD8437FE234FDCB5B36AC5DE1D990DB07F (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_AchievementProgress_GetID(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_AchievementProgress_GetID_m9032B19F4708D4A29D538FD11C92BB5A1EBC6F2B (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AchievementProgress_GetBitfield(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AchievementProgress_GetBitfield_mAC09D75110C5E5B0DA12BA99F1DE7A8C22A4A8A3 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_AchievementProgress_GetCount(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_AchievementProgress_GetCount_m00A61E88B3CA7923FA350A477ECA37C540C1D330 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_AchievementProgress_GetIsUnlocked(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_AchievementProgress_GetIsUnlocked_mFC57F2A6EDC67632044956C1F484E7CDDA82C4C5 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AchievementProgress_GetName(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AchievementProgress_GetName_m6DE79723249AC5DB4C0A591667D1F83B94337421 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt32 Pico.Platform.CLIB::ppf_AchievementProgress_GetExtraDataLength(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t CLIB_ppf_AchievementProgress_GetExtraDataLength_mA6AC4C1BF07A30402E6486948D83B3D1F07C2547 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_AchievementProgress_GetExtraData(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_AchievementProgress_GetExtraData_m89E77878CDDD6408578057D03DCBF302C238FF6F (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.Runtime.InteropServices.Marshal::Copy(System.IntPtr,System.Byte[],System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Marshal_Copy_mF7402FFDB520EA1B8D1C32B368DBEE4B13F1BE77 (intptr_t ___0_source, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___1_destination, int32_t ___2_startIndex, int32_t ___3_length, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_AchievementProgress_GetUnlockTime(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_AchievementProgress_GetUnlockTime_mC0337111967A8F1E297D7B5F2C0FE3374A5AEDA2 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.DateTime Pico.Platform.TimeUtil::SecondsToDateTime(System.Int64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D TimeUtil_SecondsToDateTime_m5DC84ED0EEB5AB8AAF833B2F5FF5E9F075C165F4 (int64_t ___0_seconds, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.AchievementProgress>::.ctor()
inline void MessageArray_1__ctor_m3BC499DB56D4BA1111B6D6E1C8CB126A69677139 (MessageArray_1_tA2FC832E9F92BC2639E48F182ED14B04435430CA* __this, const RuntimeMethod* method)
{
	((  void (*) (MessageArray_1_tA2FC832E9F92BC2639E48F182ED14B04435430CA*, const RuntimeMethod*))MessageArray_1__ctor_m9B6627200A9DB24455505C010AE4DD7BEF61F451_gshared)(__this, method);
}
// System.UIntPtr Pico.Platform.CLIB::ppf_AchievementProgressArray_GetTotalSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_AchievementProgressArray_GetTotalSize_mDB5D88F1D417F36320E57CD41FBD6243D94B136D (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UIntPtr Pico.Platform.CLIB::ppf_AchievementProgressArray_GetSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_AchievementProgressArray_GetSize_mE6301BFD7F2C556E00E0E09823E6B41609624872 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.AchievementProgress>::set_Capacity(System.Int32)
inline void List_1_set_Capacity_mBC09D6DE59BD632D853F41ACEA81571B2F8CBAC6 (List_1_tB745982DEF869D4B1F9C78EE82DF592AB431896B* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_tB745982DEF869D4B1F9C78EE82DF592AB431896B*, int32_t, const RuntimeMethod*))List_1_set_Capacity_mD826E33A9E5EBC19C714653217071790693E0B95_gshared)(__this, ___0_value, method);
}
// System.IntPtr Pico.Platform.CLIB::ppf_AchievementProgressArray_GetElement(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_AchievementProgressArray_GetElement_mD73CB92CE71EC97799808766C5138E090CB1C639 (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.AchievementProgress::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AchievementProgress__ctor_m595AB23BF0591ECEAD689D530D125C5819277357 (AchievementProgress_t1E252101294D86D61BE435D76B192BE5E85F67DB* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.AchievementProgress>::Add(T)
inline void List_1_Add_mF7A5FDE71163AB620C0E8DB3CF2D72A13B43ED19_inline (List_1_tB745982DEF869D4B1F9C78EE82DF592AB431896B* __this, AchievementProgress_t1E252101294D86D61BE435D76B192BE5E85F67DB* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tB745982DEF869D4B1F9C78EE82DF592AB431896B*, AchievementProgress_t1E252101294D86D61BE435D76B192BE5E85F67DB*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.Boolean Pico.Platform.CLIB::ppf_AchievementProgressArray_HasNextPage(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_AchievementProgressArray_HasNextPage_mDFE3A23DCFA732521F82F1BF92AA1A38F350980F (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_LaunchDetails_GetDeeplinkMessage(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_LaunchDetails_GetDeeplinkMessage_m1ED848F21AC964F7A965CD9339D07F9DF8EE321F (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_LaunchDetails_GetDestinationApiName(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_LaunchDetails_GetDestinationApiName_m2EA9533CA6339133DD1BA2E521A7A5EC0EE50227 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_LaunchDetails_GetLobbySessionID(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_LaunchDetails_GetLobbySessionID_mB532DCDABA451173E4C93FAA4A890DAAAEDFFB9E (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_LaunchDetails_GetMatchSessionID(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_LaunchDetails_GetMatchSessionID_m663601B6487F40956EAD564BE11F43343E97A429 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_LaunchDetails_GetExtra(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_LaunchDetails_GetExtra_mC5CCE217372DE9E0CAD3618C830DE5F0B2B6A196 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_LaunchDetails_GetRoomID(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_LaunchDetails_GetRoomID_mA1C0ADF43CF43F9B686AF3703ACE51981EC5F699 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_LaunchDetails_GetChallengeID(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_LaunchDetails_GetChallengeID_m535246BDC2687D9C525EC51E199F9E229E0E4729 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_LaunchDetails_GetTrackingID(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_LaunchDetails_GetTrackingID_m576041A6FC11F3E84ABDCA86A6E2241BC7E0F90F (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.LaunchType Pico.Platform.CLIB::ppf_LaunchDetails_GetLaunchType(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_LaunchDetails_GetLaunchType_m278AB8B05EBCBD3E0F0C72BEF1380557CBFE8BB6 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_SystemInfo_GetROMVersion(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_SystemInfo_GetROMVersion_m4E99BE5C919678532BDBE52B17A719ED65744444 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_SystemInfo_GetLocale(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_SystemInfo_GetLocale_m9B053C1AD304D4BF02CF185555A809756841F027 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_SystemInfo_GetProductName(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_SystemInfo_GetProductName_mF4C630400839A663B0720A556121DF0CBF352684 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_SystemInfo_GetIsCnDevice(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_SystemInfo_GetIsCnDevice_m8E4BF6499CA8E77746AED57C7FAC08E3EA1A02DB (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_SystemInfo_GetMatrixVersionName(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_SystemInfo_GetMatrixVersionName_m476AE75AD43BD030D59FF0EE63C9837F8D9C5DD6 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_SystemInfo_GetMatrixVersionCode(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_SystemInfo_GetMatrixVersionCode_m1DB3C0280D4FA8624A283C0D1F587A4732CE785B (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_ApplicationVersion_GetCurrentCode(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_ApplicationVersion_GetCurrentCode_m76EA30CE2F678D72840356C482A4B9735E09F5FE (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_ApplicationVersion_GetCurrentName(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_ApplicationVersion_GetCurrentName_mBC9A6FF9306378558D87F7AA681FAF908F961187 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_ApplicationVersion_GetLatestCode(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_ApplicationVersion_GetLatestCode_mCB1793CE63A9BE4F3580C125B98A5385157589E4 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_ApplicationVersion_GetLatestName(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_ApplicationVersion_GetLatestName_m0387B60DE0A54F192002C878BF51526BDB31E5C4 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_AssetDetails_GetAssetId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_AssetDetails_GetAssetId_m30DE47693AEDD19CCAE8B2F3C38B04B89484C836 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AssetDetails_GetAssetType(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AssetDetails_GetAssetType_mA17FB114E8F3B6E9F66B86ADA3880C0755FB0601 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AssetDetails_GetDownloadStatus(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AssetDetails_GetDownloadStatus_mED60EA7CD536F9636DC5B7B5748A2DC3F158DC37 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AssetDetails_GetIapStatus(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AssetDetails_GetIapStatus_m8E562F5D48D1EB6014C7763684112C5D7D0F2251 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AssetDetails_GetFilepath(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AssetDetails_GetFilepath_m0C39ABF75009F407A268D9422BD13D2608C9E7BA (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AssetDetails_GetMetadata(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AssetDetails_GetMetadata_m6B7DF5682E75B9C137FF575CE26FADA96D6784FC (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AssetDetails_GetFilename(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AssetDetails_GetFilename_m9A6AF247B29775D4CB01F5B14F6C5E61CE865A35 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_AssetDetails_GetVersion(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_AssetDetails_GetVersion_m0E2E4F9D9EE10CC8BDE443880FB18C192F144A17 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AssetDetails_GetIapSku(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AssetDetails_GetIapSku_m38C9DF49A059A0D83B4AC0DFBE3DD25440E9DD8B (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AssetDetails_GetIapName(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AssetDetails_GetIapName_m88BB2AEB76425C40DBA8CA36A664CB95709E765C (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AssetDetails_GetIapPrice(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AssetDetails_GetIapPrice_m2C04DE9C3B27FB1FE33D5B6F645AB8F7DC88DC37 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AssetDetails_GetIapCurrency(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AssetDetails_GetIapCurrency_mC01C4AF66437ADCBABC46EFF3C6152675A871D30 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AssetDetails_GetIapDescription(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AssetDetails_GetIapDescription_mD42158477344196D02B31BC337131244BF447E6C (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AssetDetails_GetIapIcon(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AssetDetails_GetIapIcon_m8AB0CB439BA3BAEF078786F8375137E843C02948 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.AssetDetails>::.ctor()
inline void MessageArray_1__ctor_mB185D5F8F245E3548B7E1F83E5D80079D940BEA1 (MessageArray_1_t3588ACF0944917D806087EF192359A96F2EF26D6* __this, const RuntimeMethod* method)
{
	((  void (*) (MessageArray_1_t3588ACF0944917D806087EF192359A96F2EF26D6*, const RuntimeMethod*))MessageArray_1__ctor_m9B6627200A9DB24455505C010AE4DD7BEF61F451_gshared)(__this, method);
}
// System.UIntPtr Pico.Platform.CLIB::ppf_AssetDetailsArray_GetSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_AssetDetailsArray_GetSize_m433BBD041067F04F5A10E4555861C8C0E8E96343 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.AssetDetails>::set_Capacity(System.Int32)
inline void List_1_set_Capacity_m587217153D2FA93F4FC0889992B6BA1FA2D95A87 (List_1_t99C4055E7A18C1DF32B7AECA7EE4535206181597* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_t99C4055E7A18C1DF32B7AECA7EE4535206181597*, int32_t, const RuntimeMethod*))List_1_set_Capacity_mD826E33A9E5EBC19C714653217071790693E0B95_gshared)(__this, ___0_value, method);
}
// System.UIntPtr System.UIntPtr::op_Explicit(System.UInt64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t UIntPtr_op_Explicit_mF1E7911DD5AC13B5E59EE8C7903469D12A3861E8 (uint64_t ___0_value, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_AssetDetailsArray_GetElement(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_AssetDetailsArray_GetElement_m10868E5C3DD1E1D8CA388914F737E5FEDCC9088B (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.AssetDetails::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AssetDetails__ctor_mBEA8F407B875F1B5BD9F8828669D9ED98AAF4CB7 (AssetDetails_t8F8B8199F92068253768AABE9EB4314FFB926AE2* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.AssetDetails>::Add(T)
inline void List_1_Add_mCEA246871367366985CC1373045B5CAC13DDECA6_inline (List_1_t99C4055E7A18C1DF32B7AECA7EE4535206181597* __this, AssetDetails_t8F8B8199F92068253768AABE9EB4314FFB926AE2* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t99C4055E7A18C1DF32B7AECA7EE4535206181597*, AssetDetails_t8F8B8199F92068253768AABE9EB4314FFB926AE2*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.String Pico.Platform.CLIB::ppf_AssetDetailsArray_GetNextPageParam(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AssetDetailsArray_GetNextPageParam_m8A0847EFFB18FFFE801E963116D144755C8294A5 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_AssetFileDeleteForSafety_GetAssetId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_AssetFileDeleteForSafety_GetAssetId_m0A5642ABB68637F41417042A90035B6AF9359E3C (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AssetFileDeleteForSafety_GetReason(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AssetFileDeleteForSafety_GetReason_m0D6348551BAFED2CE1F6C17624F15893CB41C677 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AssetFileDeleteResult_GetFilepath(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AssetFileDeleteResult_GetFilepath_mB84C04D52EBD9346D092B9D2161D62AB381C406A (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_AssetFileDeleteResult_GetSuccess(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_AssetFileDeleteResult_GetSuccess_mDB773D149D3628F18AFCDE385558CCB796C961B5 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_AssetFileDeleteResult_GetAssetId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_AssetFileDeleteResult_GetAssetId_m864E006BC66298F8F1C5C2E3249226C0FE6AE5A8 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AssetFileDownloadCancelResult_GetFilepath(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AssetFileDownloadCancelResult_GetFilepath_mA20231654B8597E8CE8C9D499A7B6AACADE4AF1B (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_AssetFileDownloadCancelResult_GetSuccess(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_AssetFileDownloadCancelResult_GetSuccess_m1FEC0B12273C3D5CB158C214AFC7B381AD9A1ACE (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_AssetFileDownloadCancelResult_GetAssetId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_AssetFileDownloadCancelResult_GetAssetId_mA7AC7A878088611C0D01507973C984AE25020C0C (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_AssetFileDownloadResult_GetAssetId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_AssetFileDownloadResult_GetAssetId_m084817E52E3DCB845C1C1DA28486F2EADD4451C2 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AssetFileDownloadResult_GetFilepath(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AssetFileDownloadResult_GetFilepath_mC92EC74711BD43A2E3D64FF4273A40A7DDAEA5EC (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_AssetFileDownloadUpdate_GetAssetId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_AssetFileDownloadUpdate_GetAssetId_m0B5861262081CF39932B510FE0532CDBADDB18E9 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_AssetFileDownloadUpdate_GetBytesTotal(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_AssetFileDownloadUpdate_GetBytesTotal_m2578FBE12DAEFE371E2A0F0D94E5571372F27BDD (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_AssetFileDownloadUpdate_GetBytesTransferred(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_AssetFileDownloadUpdate_GetBytesTransferred_mA46C09C8767665DE93EB0E4EBE8B12D485EB205A (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.AssetFileDownloadCompleteStatus Pico.Platform.CLIB::ppf_AssetFileDownloadUpdate_GetCompleteStatus(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_AssetFileDownloadUpdate_GetCompleteStatus_mA680F3622C6096FE2807B34E7D3BB600BD2AE36E (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_AssetStatus_GetAssetId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_AssetStatus_GetAssetId_mBD919DEE87A88BF455AD0DF2E0BAB83C51EA95B5 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AssetStatus_GetFilename(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AssetStatus_GetFilename_mAA6D2BF9B08A31F4AF83AD3B47EAAF817257B4BE (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AssetStatus_GetFilepath(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AssetStatus_GetFilepath_mFEC1C050C3A3CD55F6FDF44EA1385690D9D25E51 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AssetStatus_GetDownloadStatus(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AssetStatus_GetDownloadStatus_m28B0087E3075BADB1EE9C62106743BBA74F2ADD1 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_ChallengeOptions_Create()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_ChallengeOptions_Create_m28D5B612C88C3522258407C203552F10E7189140 (const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.TimeUtil::DateTimeToSeconds(System.DateTime)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t TimeUtil_DateTimeToSeconds_mEC9188A159C402CEDEB78D0BF7EED1B8CF7C7DB3 (DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___0_t, const RuntimeMethod* method) ;
// System.UInt64 System.Convert::ToUInt64(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t Convert_ToUInt64_m53C3A45C87A06F25957619222B04EABFD214373C (int32_t ___0_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_ChallengeOptions_SetEndDate(System.IntPtr,System.UInt64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_ChallengeOptions_SetEndDate_mF4902730467C441843A26599A5E156C0A9FDB10A (intptr_t ___0_handle, uint64_t ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_ChallengeOptions_SetIncludeActiveChallenges(System.IntPtr,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_ChallengeOptions_SetIncludeActiveChallenges_m8C145331B3DCD21F60DE0E333527F0A7A93AA4F0 (intptr_t ___0_handle, bool ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_ChallengeOptions_SetIncludeFutureChallenges(System.IntPtr,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_ChallengeOptions_SetIncludeFutureChallenges_m94B3A8141A52A1B7F7275ED9CAA4A70EA6D62D7F (intptr_t ___0_handle, bool ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_ChallengeOptions_SetIncludePastChallenges(System.IntPtr,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_ChallengeOptions_SetIncludePastChallenges_m7CDE72B71B97C616393B8DFE1DD5D13C29501D7D (intptr_t ___0_handle, bool ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_ChallengeOptions_SetLeaderboardName(System.IntPtr,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_ChallengeOptions_SetLeaderboardName_m91E5B54B48A198FFB8059C9EA7BC6B50D2F4C186 (intptr_t ___0_handle, String_t* ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_ChallengeOptions_SetStartDate(System.IntPtr,System.UInt64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_ChallengeOptions_SetStartDate_m00B9A69ACAD71F33AD0BDE547AE02411E62B4D10 (intptr_t ___0_handle, uint64_t ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_ChallengeOptions_SetTitle(System.IntPtr,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_ChallengeOptions_SetTitle_m413EA0AEA4EC27ECC6358A97994A87EEB31C69A8 (intptr_t ___0_handle, String_t* ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_ChallengeOptions_SetViewerFilter(System.IntPtr,Pico.Platform.ChallengeViewerFilter)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_ChallengeOptions_SetViewerFilter_mBB2183526B05441DCF1B93575FEC458ACDC15D6B (intptr_t ___0_handle, int32_t ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_ChallengeOptions_SetVisibility(System.IntPtr,Pico.Platform.ChallengeVisibility)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_ChallengeOptions_SetVisibility_mF62A54CE695BC12D40A25151308E3C18EB57B1AE (intptr_t ___0_handle, int32_t ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_ChallengeOptions_Destroy(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_ChallengeOptions_Destroy_m499648832560882E78FB7E6905C97A2B36F12B31 (intptr_t ___0_handle, const RuntimeMethod* method) ;
// Pico.Platform.ChallengeCreationType Pico.Platform.CLIB::ppf_Challenge_GetCreationType(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_Challenge_GetCreationType_m54722CFBBA46F0D71C731D213729B7CEB0C58CD5 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_Challenge_GetEndDate(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_Challenge_GetEndDate_mCBDF7A2ED8714C96DA08DAF97248744C3F7157E8 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_Challenge_GetID(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_Challenge_GetID_mD003C6246D2607B8CD23B585BA9E86559BBD0F89 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_Challenge_GetInvitedUsers(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_Challenge_GetInvitedUsers_m4DF924A13B70554F30FAB4587F806B628C5FF915 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean System.IntPtr::op_Equality(System.IntPtr,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool IntPtr_op_Equality_m7D9CDCDE9DC2A0C2C614633F4921E90187FAB271 (intptr_t ___0_value1, intptr_t ___1_value2, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.UserList::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UserList__ctor_m4FEB49DD26A4410363EE489A1D289C8725776F4D (UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F* __this, intptr_t ___0_a, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_Challenge_GetLeaderboard(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_Challenge_GetLeaderboard_m2D06346ECDCADDE7C68C5F2CFBBC5E7EA4713C40 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.Leaderboard::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Leaderboard__ctor_m2A2DEAE53680BB01FA25EF33302C76475BC2445A (Leaderboard_t6D83DEF000B68074D583D0D92AED4AE1EFB14595* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_Challenge_GetParticipants(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_Challenge_GetParticipants_m8874B80EBB40D1B07BA5B32800D3297E6F1BE178 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_Challenge_GetStartDate(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_Challenge_GetStartDate_m8AAA44D2E70AAADCB8EC1C80098C161CDE23A967 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Challenge_GetTitle(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Challenge_GetTitle_m4F7315685093D3CA0959F8F5EFF7EAAB1147C71E (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.ChallengeVisibility Pico.Platform.CLIB::ppf_Challenge_GetVisibility(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_Challenge_GetVisibility_m7689009EADB3EB1AA23DD990122020B47FA3B720 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Challenge>::.ctor()
inline void MessageArray_1__ctor_mC023B4EA85DD7FE3EAA208D782D302DBDBAF0695 (MessageArray_1_t3AD15036E7E447220D0A42DE4FB31045C546D530* __this, const RuntimeMethod* method)
{
	((  void (*) (MessageArray_1_t3AD15036E7E447220D0A42DE4FB31045C546D530*, const RuntimeMethod*))MessageArray_1__ctor_m9B6627200A9DB24455505C010AE4DD7BEF61F451_gshared)(__this, method);
}
// System.UInt64 Pico.Platform.CLIB::ppf_ChallengeArray_GetTotalCount(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_ChallengeArray_GetTotalCount_m1DF20B06D266246E545B890BDD803210C57CFF11 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_ChallengeArray_HasNextPage(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_ChallengeArray_HasNextPage_m8F637C349327898187C00BB1964E0EE7D2990583 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_ChallengeArray_HasPreviousPage(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_ChallengeArray_HasPreviousPage_m489DF72D11CEE7B26316A8CA8B03908A0522241C (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UIntPtr Pico.Platform.CLIB::ppf_ChallengeArray_GetSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_ChallengeArray_GetSize_m19A7CA4D96B1793CC7526D13557AF0E443291460 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.Challenge>::set_Capacity(System.Int32)
inline void List_1_set_Capacity_mD8859A91DF45D79EC817B5FD13518AA8FEC1A777 (List_1_t1270A6FA80F83E5E821A0DAE5FB3C06865ACB59C* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_t1270A6FA80F83E5E821A0DAE5FB3C06865ACB59C*, int32_t, const RuntimeMethod*))List_1_set_Capacity_mD826E33A9E5EBC19C714653217071790693E0B95_gshared)(__this, ___0_value, method);
}
// System.IntPtr Pico.Platform.CLIB::ppf_ChallengeArray_GetElement(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_ChallengeArray_GetElement_m7FF8FEA78E6FF39583992782FE650FE1206EA841 (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.Challenge::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Challenge__ctor_m874B7BFA0E469D7E10DCB22ACDB3790700D8EA8F (Challenge_t4D4126711B52D78CEDA93B79EC0EFF69927E3971* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.Challenge>::Add(T)
inline void List_1_Add_m1BA57A9C6578828099352E29E2BDA8357F2EFCD0_inline (List_1_t1270A6FA80F83E5E821A0DAE5FB3C06865ACB59C* __this, Challenge_t4D4126711B52D78CEDA93B79EC0EFF69927E3971* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t1270A6FA80F83E5E821A0DAE5FB3C06865ACB59C*, Challenge_t4D4126711B52D78CEDA93B79EC0EFF69927E3971*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.String Pico.Platform.CLIB::ppf_ChallengeEntry_GetDisplayScore(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_ChallengeEntry_GetDisplayScore_m67936B244D533E7B57F43A1D2B04BB8F9CB4D499 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_ChallengeEntry_GetExtraData(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_ChallengeEntry_GetExtraData_m4EA44F5AB49FD115736AE0A8DB570F88AA92C55C (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt32 Pico.Platform.CLIB::ppf_ChallengeEntry_GetExtraDataLength(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t CLIB_ppf_ChallengeEntry_GetExtraDataLength_m56C802D4C29D806C6E8AD2F85E04FF4A60BAFCEE (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Byte[] Pico.Platform.MarshalUtil::ByteArrayFromNative(System.IntPtr,System.UInt32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* MarshalUtil_ByteArrayFromNative_m3285FDD06424A5CB82BD0EE8C63BBB8F8C2482DB (intptr_t ___0_ptr, uint32_t ___1_length, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_ChallengeEntry_GetID(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_ChallengeEntry_GetID_mA93758CC818587B6660FC3CEA39BF8BBBD23C2BD (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_ChallengeEntry_GetRank(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_ChallengeEntry_GetRank_m9C9213605C2B9413A8E14D06B4D59955A5A50D73 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_ChallengeEntry_GetScore(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_ChallengeEntry_GetScore_m51C80C491AF519ECBBAAF4CD22BAA2A8AB48ED0A (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_ChallengeEntry_GetTimestamp(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_ChallengeEntry_GetTimestamp_mE4222E9BCD2E2B7A0BCDA4A9B73CCB9BAD76C807 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_ChallengeEntry_GetUser(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_ChallengeEntry_GetUser_m2BCB9AFF38A65B6137FC60AC761A01D0B6FB3A8B (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.User::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void User__ctor_m0A17383A33457E27EB6AD299C81C77AC1802E0D1 (User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4* __this, intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.ChallengeEntry>::.ctor()
inline void MessageArray_1__ctor_mA5A42AA1E725EA805913577703E01D8889C8B184 (MessageArray_1_t7879F9CC787398F1DCC478C7DFC9D19EB4D4837E* __this, const RuntimeMethod* method)
{
	((  void (*) (MessageArray_1_t7879F9CC787398F1DCC478C7DFC9D19EB4D4837E*, const RuntimeMethod*))MessageArray_1__ctor_m9B6627200A9DB24455505C010AE4DD7BEF61F451_gshared)(__this, method);
}
// System.UInt64 Pico.Platform.CLIB::ppf_ChallengeEntryArray_GetTotalCount(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_ChallengeEntryArray_GetTotalCount_mC0727FFA226C37F8292D50EF06980CA813721A7B (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_ChallengeEntryArray_HasNextPage(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_ChallengeEntryArray_HasNextPage_m17DD52B8EBF5733D4FDD9999005177A8FA5E66CA (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_ChallengeEntryArray_HasPreviousPage(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_ChallengeEntryArray_HasPreviousPage_m2E70F20E0BA239B512B68698C9D13E0C1AAA993C (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UIntPtr Pico.Platform.CLIB::ppf_ChallengeEntryArray_GetSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_ChallengeEntryArray_GetSize_m2F77700C22B836B21C1CEE5F29CF52EF0729C3A9 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.ChallengeEntry>::set_Capacity(System.Int32)
inline void List_1_set_Capacity_m5832DE315E2469EA21365A385436DD5F7824940A (List_1_t3A2B2890CB7F9F96B159F90ED3C352D0F69BFC03* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_t3A2B2890CB7F9F96B159F90ED3C352D0F69BFC03*, int32_t, const RuntimeMethod*))List_1_set_Capacity_mD826E33A9E5EBC19C714653217071790693E0B95_gshared)(__this, ___0_value, method);
}
// System.IntPtr Pico.Platform.CLIB::ppf_ChallengeEntryArray_GetElement(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_ChallengeEntryArray_GetElement_mEDC2E296E561D950ACB61D61DC5201D8385421A4 (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.ChallengeEntry::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChallengeEntry__ctor_mD68661A405B254CB2F675286E7CE8419B3B304A1 (ChallengeEntry_t16F06D309BE271B368F93F4F66001E1270B6EEAB* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.ChallengeEntry>::Add(T)
inline void List_1_Add_m1914F43100B594ABF59084FCF1FCFA2D848E9025_inline (List_1_t3A2B2890CB7F9F96B159F90ED3C352D0F69BFC03* __this, ChallengeEntry_t16F06D309BE271B368F93F4F66001E1270B6EEAB* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t3A2B2890CB7F9F96B159F90ED3C352D0F69BFC03*, ChallengeEntry_t16F06D309BE271B368F93F4F66001E1270B6EEAB*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.Void Pico.Platform.Models.KVPairArray::set_Size(System.UInt32)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void KVPairArray_set_Size_mEF25D67ACDCEB5A98B41B65D53C7752DCDC51F4C_inline (KVPairArray_t2D18141BDF81CCF74F01AD0CD6D940BFF0D65E1F* __this, uint32_t ___0_value, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_KeyValuePairArray_Create(System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_KeyValuePairArray_Create_m6F54BFFE5EE7E6ABA1752058D12134CF2CBD97F6 (uintptr_t ___0_size, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_KeyValuePairArray_Destroy(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_KeyValuePairArray_Destroy_m13DB772246A8F5676AEB1C20C90B353652110DF6 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_KeyValuePairArray_GetElement(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_KeyValuePairArray_GetElement_mE950CFCB71BAD525B897B7C4D278CB108EC4C617 (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.KVPair::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void KVPair__ctor_m28A5FAFB2A42292D238E2A51A86E88A6EA1C8E70 (KVPair_t3B78D7F4C5A144597A4D25D3E998B119380117F0* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_KeyValuePair_Create()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_KeyValuePair_Create_mA79AD02F3A312A65355B495A08360391C01B5FF6 (const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_KeyValuePair_SetIntValue(System.IntPtr,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_KeyValuePair_SetIntValue_mC497AAC5BC9441B3EDA5F76157E0A277C98EF91A (intptr_t ___0_obj, int32_t ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_KeyValuePair_SetStringValue(System.IntPtr,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_KeyValuePair_SetStringValue_m5F0A5632F7637FDC3C126481941D9FF3B71E0755 (intptr_t ___0_obj, String_t* ___1_value, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_KeyValuePair_SetDoubleValue(System.IntPtr,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_KeyValuePair_SetDoubleValue_mA7E44BB1493EDBEBCFFF44F05D9C3F85A1FE2CF8 (intptr_t ___0_obj, double ___1_value, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_KeyValuePair_GetIntValue(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_KeyValuePair_GetIntValue_m7AE0ECBD0C910DC87AEC76B78841152854253699 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_KeyValuePair_GetStringValue(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_KeyValuePair_GetStringValue_mF16E2228192E638B64886EEE165C82BF11CDDE52 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Double Pico.Platform.CLIB::ppf_KeyValuePair_GetDoubleValue(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double CLIB_ppf_KeyValuePair_GetDoubleValue_m56CD38E0B7348C51FEB3465E61382C9AD1E09BF9 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_KeyValuePair_SetKey(System.IntPtr,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_KeyValuePair_SetKey_m3B06ECCBEEB5CC87ADD5FFAD6981F87D295FBA38 (intptr_t ___0_obj, String_t* ___1_key, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_KeyValuePair_GetKey(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_KeyValuePair_GetKey_mEF5F8BDB87CC7F89999AC4E17C117D2DDB1B9218 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.KVPairType Pico.Platform.CLIB::ppf_KeyValuePair_GetValueType(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_KeyValuePair_GetValueType_mCFC2798E5D55D9D7D07EEA1C75CAC1016AD60887 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_KeyValuePair_Destroy(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_KeyValuePair_Destroy_m7B7220611476C9701A52F66D112E43D92CEB565E (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_DetectSensitiveResult_GetFilteredText(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_DetectSensitiveResult_GetFilteredText_mDDDE2F0034C8E04BD2EB83A613CA4C05E7E0E480 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.SensitiveProposal Pico.Platform.CLIB::ppf_DetectSensitiveResult_GetProposal(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_DetectSensitiveResult_GetProposal_m2B9E448CE776FE5A9AA77F4E80A63057ACD3B486 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_CaptureInfo_GetImagePath(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_CaptureInfo_GetImagePath_m244258184C6AB978A2BFDAF65ECF8871FCEB2970 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_CaptureInfo_GetJobId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_CaptureInfo_GetJobId_m82FD585826C8CA38269BAEF8BEC2D7978471A759 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RecordInfo_GetVideoPath(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RecordInfo_GetVideoPath_m2E2AC69C63DA6D160606CA864BE72D887FD21DFB (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_RecordInfo_GetDurationInMilliSeconds(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RecordInfo_GetDurationInMilliSeconds_mD05B3267C985B017CFA3735A226AD903B734529B (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_RecordInfo_GetWidth(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RecordInfo_GetWidth_mF57EE42B5F16E2C0D601AEDD9C38BB2EBDDC38C5 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_RecordInfo_GetHeight(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RecordInfo_GetHeight_m0E4967A34E1AFFFD63FC6FF56EBB8C8DA70175ED (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RecordInfo_GetJobId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RecordInfo_GetJobId_mFDA5187B9A0231E5990963F53ACE5B15899C8FBC (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UIntPtr Pico.Platform.CLIB::ppf_SessionMedia_GetImagesSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_SessionMedia_GetImagesSize_m6FD9B49191EC82E4DE3DC9A12E99107797452A8F (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_SessionMedia_GetImages(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_SessionMedia_GetImages_mBA8936A842A2AF4E37005F895A64BFA0B45B0143 (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.CaptureInfo::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CaptureInfo__ctor_m37807B6D793D0C2EE7004FD38C0BFB9768B9B515 (CaptureInfo_t522928357E5822ACBC5FC59A060BDBABFF3DF575* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.UIntPtr Pico.Platform.CLIB::ppf_SessionMedia_GetVideosSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_SessionMedia_GetVideosSize_m09B378F0FC0DC9F7869EDAFCF8399CE5E0E188FF (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_SessionMedia_GetVideos(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_SessionMedia_GetVideos_mCF9FA64B011A556A9F42B67BF119E170FED184D1 (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.RecordInfo::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RecordInfo__ctor_m62B1FA6DDC2D03A3F8FFF3239A1D7D7209897627 (RecordInfo_t391FC28285898D9D06E379287A88F5A4BA4A6019* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Product_GetDescription(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Product_GetDescription_mD1B0779646243AA5FB9688ECB436C3440DFAC700 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Product_GetDetailDescription(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Product_GetDetailDescription_mA8F954985EF6C5BCC48B2507AE5BC313094C8DDD (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Product_GetPrice(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Product_GetPrice_m8652C7A00E9EFC1916452594FD90B1843AE19354 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Product_GetCurrency(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Product_GetCurrency_mEE194462F6866E2D1DD209839973F97868925AE8 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Product_GetName(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Product_GetName_mD6CBAC72CD5E96A0445933B767E72A7A92C3DD29 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Product_GetSKU(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Product_GetSKU_m43A370DCC294314B0C85CE1D82303A8134C1AF01 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Product_GetIcon(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Product_GetIcon_m4DA4D8820C994B721BAF067740422F0AE7E92DB7 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.AddonsType Pico.Platform.CLIB::ppf_Product_GetAddonsType(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_Product_GetAddonsType_m6B3F5E884CA75B4401A176ADF3C525AEAC1543D3 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.PeriodType Pico.Platform.CLIB::ppf_Product_GetPeriodType(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_Product_GetPeriodType_mFB4E69F348D9C29A8EEAD2627734E7081BD16F8D (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.PeriodType Pico.Platform.CLIB::ppf_Product_GetTrialPeriodUnit(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_Product_GetTrialPeriodUnit_mAC8F88A36DE9ACFF22503D38484AF9A21D31466F (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_Product_GetTrialPeriodValue(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_Product_GetTrialPeriodValue_m0B7A544E5F45A6C9C6582C60469F06FD953298C4 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Product_GetOuterId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Product_GetOuterId_m267AFFBDEE32F2C381823A9B6BD748DC47F6BDAB (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Product_GetOriginalPrice(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Product_GetOriginalPrice_m235B0BE70565566B7689EEB90B7BEB398A3F433D (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_Product_IsContinuous(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_Product_IsContinuous_m020687081765F96283B5981EBF0772FE172D147F (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Product>::.ctor()
inline void MessageArray_1__ctor_m070935432E3EC3110B908F76DBAF98885CFDDB32 (MessageArray_1_tC6F5900777FE83D0B145BC0F27D11D16A33673A0* __this, const RuntimeMethod* method)
{
	((  void (*) (MessageArray_1_tC6F5900777FE83D0B145BC0F27D11D16A33673A0*, const RuntimeMethod*))MessageArray_1__ctor_m9B6627200A9DB24455505C010AE4DD7BEF61F451_gshared)(__this, method);
}
// System.UIntPtr Pico.Platform.CLIB::ppf_ProductArray_GetSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_ProductArray_GetSize_m97628B5E987760A2E7A917DFEE15F7F853EFF096 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.Product>::set_Capacity(System.Int32)
inline void List_1_set_Capacity_m450A27888E6E123248BB184BB5FA984716BEEA65 (List_1_tECB4BC629C4B6ABBCAC7C8ADCEFEBA5518203F3C* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_tECB4BC629C4B6ABBCAC7C8ADCEFEBA5518203F3C*, int32_t, const RuntimeMethod*))List_1_set_Capacity_mD826E33A9E5EBC19C714653217071790693E0B95_gshared)(__this, ___0_value, method);
}
// System.IntPtr Pico.Platform.CLIB::ppf_ProductArray_GetElement(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_ProductArray_GetElement_m9270AA523463622CF92F5F4D32249D280E62163E (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.Product::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Product__ctor_m2B89360C220C7AF2D5772983DFFA37D45E959C80 (Product_t1507FCF7293FA1250C325F33FEA9C46DBD487D66* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.Product>::Add(T)
inline void List_1_Add_mAC66765B1249EE653786600439164EBFDD4CD46B_inline (List_1_tECB4BC629C4B6ABBCAC7C8ADCEFEBA5518203F3C* __this, Product_t1507FCF7293FA1250C325F33FEA9C46DBD487D66* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tECB4BC629C4B6ABBCAC7C8ADCEFEBA5518203F3C*, Product_t1507FCF7293FA1250C325F33FEA9C46DBD487D66*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.String Pico.Platform.CLIB::ppf_ProductArray_GetNextPageParam(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_ProductArray_GetNextPageParam_mA37EED0D81F0DD2F3341B70951CB11AD180773AC (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_Purchase_GetExpirationTime(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_Purchase_GetExpirationTime_mA67E34B8181562A639DC76496A6A3DB2798E5463 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.DateTime Pico.Platform.TimeUtil::MilliSecondsToDateTime(System.Int64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D TimeUtil_MilliSecondsToDateTime_mF1197E9C5865487072B28200D665A6AEEA15F54C (int64_t ___0_milliSeconds, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_Purchase_GetGrantTime(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_Purchase_GetGrantTime_mBA17D386F2842A720F4240C23007B174F8178612 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Purchase_GetID(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Purchase_GetID_mDC7B79E2B3572603BF51704168A5612DE29A69EE (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Purchase_GetSKU(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Purchase_GetSKU_mA89770C220CF5AC77D41E117519FD3CE8C58742D (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Purchase_GetIcon(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Purchase_GetIcon_mBC898A37C6D4B800F2F92036C9C114B8170DB8E0 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.AddonsType Pico.Platform.CLIB::ppf_Purchase_GetAddonsType(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_Purchase_GetAddonsType_m82F2A1C27298CE21B4DEF36E71E733D0CA5F76A8 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Purchase_GetOuterId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Purchase_GetOuterId_mD609AFEEFA9C7086F96C8CB4F64D14D72C403618 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.PeriodType Pico.Platform.CLIB::ppf_Purchase_GetCurrentPeriodType(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_Purchase_GetCurrentPeriodType_mB7967308B7B6E9428DD24C233BB82EBD854D5C82 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.PeriodType Pico.Platform.CLIB::ppf_Purchase_GetNextPeriodType(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_Purchase_GetNextPeriodType_m3D1B5702CE7ADE0657FD3F47EEE7CC4DC0B625FB (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_Purchase_GetNextPayTime(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_Purchase_GetNextPayTime_mEC3DEFC0111F54758740837010589B4975729D08 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.DiscountType Pico.Platform.CLIB::ppf_Purchase_GetDiscountType(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_Purchase_GetDiscountType_mFC8540A1E5708C25F478127E8EE94190B4B52F65 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Purchase_GetOrderComment(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Purchase_GetOrderComment_mD71C08EAF31B97086796ED9D408729953687F545 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Purchase>::.ctor()
inline void MessageArray_1__ctor_m42C5998DCEE5808E1E75BDC255282820B0FCDE4E (MessageArray_1_t05AA39A5AA11CCE42EA326113EC8CB01D26F8E92* __this, const RuntimeMethod* method)
{
	((  void (*) (MessageArray_1_t05AA39A5AA11CCE42EA326113EC8CB01D26F8E92*, const RuntimeMethod*))MessageArray_1__ctor_m9B6627200A9DB24455505C010AE4DD7BEF61F451_gshared)(__this, method);
}
// System.UIntPtr Pico.Platform.CLIB::ppf_PurchaseArray_GetSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_PurchaseArray_GetSize_mA0DD6A9962FE6027F7479292AB1B5738FD1A882E (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.Purchase>::set_Capacity(System.Int32)
inline void List_1_set_Capacity_mAE4CCF57EB35D4AFBB85D1E658B88B9226F3EDB6 (List_1_t0BED0F374F8819664848045406304C5C43B290F8* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_t0BED0F374F8819664848045406304C5C43B290F8*, int32_t, const RuntimeMethod*))List_1_set_Capacity_mD826E33A9E5EBC19C714653217071790693E0B95_gshared)(__this, ___0_value, method);
}
// System.IntPtr Pico.Platform.CLIB::ppf_PurchaseArray_GetElement(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_PurchaseArray_GetElement_m4CC474C11ACDBA7C89D1230980D69DC9A2D1F7C3 (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.Purchase::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Purchase__ctor_m7632482DEC5F4C2996224366FAE1009D916A6CCF (Purchase_t4EB26AC15A7E0936D3E6722DA01B1DF84A3D469A* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.Purchase>::Add(T)
inline void List_1_Add_mEADFAAEBDAE002FF709831869BFB21C97F3E6545_inline (List_1_t0BED0F374F8819664848045406304C5C43B290F8* __this, Purchase_t4EB26AC15A7E0936D3E6722DA01B1DF84A3D469A* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t0BED0F374F8819664848045406304C5C43B290F8*, Purchase_t4EB26AC15A7E0936D3E6722DA01B1DF84A3D469A*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.String Pico.Platform.CLIB::ppf_PurchaseArray_GetNextPageParam(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_PurchaseArray_GetNextPageParam_mA8D3B2B96F786E717986A0BF59D3A48083195025 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_SubscriptionStatus_GetSKU(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_SubscriptionStatus_GetSKU_m5595F9F55F1503D5561F9EF34CEDEC817BBFB1F8 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_SubscriptionStatus_GetOuterId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_SubscriptionStatus_GetOuterId_mFD523578B31BFC34A584F37C0DA6EC8F05C5EDDA (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_SubscriptionStatus_GetStartTime(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_SubscriptionStatus_GetStartTime_m6BF1EF8ADCBB86DD1B4C18FE01E60275AC3B6D13 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_SubscriptionStatus_GetEndTime(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_SubscriptionStatus_GetEndTime_m706198F960CC228B8DB969F5D06E4C469DFB8054 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.PeriodType Pico.Platform.CLIB::ppf_SubscriptionStatus_GetPeriodType(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_SubscriptionStatus_GetPeriodType_m21BFF84CCB3DAC33C671214718143CADF98BE13C (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.EntitlementStatus Pico.Platform.CLIB::ppf_SubscriptionStatus_GetEntitlementStatus(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_SubscriptionStatus_GetEntitlementStatus_m17EB83072450EFEDC2003F5A91C30E6941180F3E (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.CancelReason Pico.Platform.CLIB::ppf_SubscriptionStatus_GetCancelReason(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_SubscriptionStatus_GetCancelReason_m9CA3C5B29A788E48D6C6270839F6844522CF167B (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_SubscriptionStatus_GetIsFreeTrial(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_SubscriptionStatus_GetIsFreeTrial_m6B838DA3E66F24F6177D7484F7AEF298BA6BA71E (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_SubscriptionStatus_GetNextPeriod(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_SubscriptionStatus_GetNextPeriod_mA29187B347B2E79C402190E2F129BE3BA51222B4 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Leaderboard_GetApiName(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Leaderboard_GetApiName_m3C44DFA46E56BAC07EDB706A4ADBAB260BBB5512 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_Leaderboard_GetID(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_Leaderboard_GetID_mB2B837031119D9D620AEC7AB717267B55611A1A6 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_Leaderboard_GetDestination(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_Leaderboard_GetDestination_mFCB9EC7188152DBA1F8B8EE64BBE49A9A16F6AB6 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.Destination::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Destination__ctor_mB1261B84D715AED778CC96E68B1F2C0907CF8543 (Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Leaderboard>::.ctor()
inline void MessageArray_1__ctor_mDF051A62863C8BF176120076EFE94E48880CCF09 (MessageArray_1_tF4173B1C53148BB935C764587034896F121CCA0A* __this, const RuntimeMethod* method)
{
	((  void (*) (MessageArray_1_tF4173B1C53148BB935C764587034896F121CCA0A*, const RuntimeMethod*))MessageArray_1__ctor_m9B6627200A9DB24455505C010AE4DD7BEF61F451_gshared)(__this, method);
}
// System.UInt64 Pico.Platform.CLIB::ppf_LeaderboardArray_GetTotalCount(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_LeaderboardArray_GetTotalCount_mE26F608C8EEAEE8C90A61F15B1E9C307667351DD (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_LeaderboardArray_HasNextPage(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_LeaderboardArray_HasNextPage_m0283D91B507A12D29EAD6557E14EB38EF65ACB87 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UIntPtr Pico.Platform.CLIB::ppf_LeaderboardArray_GetSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_LeaderboardArray_GetSize_mE4CDF1698DDEB674D5D80707B8C773850F1AD373 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.Leaderboard>::set_Capacity(System.Int32)
inline void List_1_set_Capacity_m963CDE36EB1DC3435DF73BC25E0C47DCB90B73EA (List_1_t724694C0B4027B186B04C28FF07C047043904083* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_t724694C0B4027B186B04C28FF07C047043904083*, int32_t, const RuntimeMethod*))List_1_set_Capacity_mD826E33A9E5EBC19C714653217071790693E0B95_gshared)(__this, ___0_value, method);
}
// System.IntPtr Pico.Platform.CLIB::ppf_LeaderboardArray_GetElement(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_LeaderboardArray_GetElement_m0E311CEEB7A307240A1090CAC1E8FEA66B8150A0 (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.Leaderboard>::Add(T)
inline void List_1_Add_mCC5C1CBC4EADCF51A55299EAD6C37250FC897458_inline (List_1_t724694C0B4027B186B04C28FF07C047043904083* __this, Leaderboard_t6D83DEF000B68074D583D0D92AED4AE1EFB14595* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t724694C0B4027B186B04C28FF07C047043904083*, Leaderboard_t6D83DEF000B68074D583D0D92AED4AE1EFB14595*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.UInt64 Pico.Platform.CLIB::ppf_SupplementaryMetric_GetID(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_SupplementaryMetric_GetID_m8BE37395168CC4A43F55FAEF84F4802666BC08A6 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_SupplementaryMetric_GetMetric(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_SupplementaryMetric_GetMetric_mF5AAFFA6AB2EB9FF451C3BB1520B107077164497 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_LeaderboardEntry_GetDisplayScore(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_LeaderboardEntry_GetDisplayScore_mEE5F0A6BE447A93D8283FE72064D9C4CCD850808 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_LeaderboardEntry_GetExtraData(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_LeaderboardEntry_GetExtraData_m0A15944A0014F6A15EF55660F3FBBA7A4E4E6E4C (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt32 Pico.Platform.CLIB::ppf_LeaderboardEntry_GetExtraDataLength(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t CLIB_ppf_LeaderboardEntry_GetExtraDataLength_m87680D3362D47D7097051C8CFE4843AC9B7DEC1C (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_LeaderboardEntry_GetID(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_LeaderboardEntry_GetID_m729C4E3230616AB7987BF79BDCA2F9F6DCA6A61B (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_LeaderboardEntry_GetRank(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_LeaderboardEntry_GetRank_m74818B002D623F894496C066DB61A372241E9D9F (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_LeaderboardEntry_GetScore(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_LeaderboardEntry_GetScore_m3806DB60A56B51FEF526D0A9C766B9A17318A355 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_LeaderboardEntry_GetTimestamp(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_LeaderboardEntry_GetTimestamp_m235480C0DC5A324DE8AAC7DE40C52531DC9D1AB6 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_LeaderboardEntry_GetUser(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_LeaderboardEntry_GetUser_m1D2A3F19B7EE38A6DD695B8FECAEBD5C19518E31 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_LeaderboardEntry_GetSupplementaryMetric(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_LeaderboardEntry_GetSupplementaryMetric_m2867CD031D7DA78D4D040918983A0CB8A6514422 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.SupplementaryMetric::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SupplementaryMetric__ctor_m4344D6AE0DB6BE0F5D79A62F613F6AD477BEC46C (SupplementaryMetric_t28C1258D6CB519A099746C713C51A1F14C2C242A* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.LeaderboardEntry>::.ctor()
inline void MessageArray_1__ctor_mC6CA9C8AA50186FFCDF3CA2E5A30AE34E21DE5D2 (MessageArray_1_tB8E04BD481F9ACE36C3AC7750EC6E3168CF6ED31* __this, const RuntimeMethod* method)
{
	((  void (*) (MessageArray_1_tB8E04BD481F9ACE36C3AC7750EC6E3168CF6ED31*, const RuntimeMethod*))MessageArray_1__ctor_m9B6627200A9DB24455505C010AE4DD7BEF61F451_gshared)(__this, method);
}
// System.Boolean Pico.Platform.CLIB::ppf_LeaderboardEntryArray_HasNextPage(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_LeaderboardEntryArray_HasNextPage_mBE803587B662F538084710F22E2172B41AF7BFBE (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_LeaderboardEntryArray_HasPreviousPage(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_LeaderboardEntryArray_HasPreviousPage_mC57A7D0351CC71FD09239FBBFADAB6696FB89AEA (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UIntPtr Pico.Platform.CLIB::ppf_LeaderboardEntryArray_GetSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_LeaderboardEntryArray_GetSize_m5515778739F91A78D5C16C00D24E6C2A1D6414A7 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.LeaderboardEntry>::set_Capacity(System.Int32)
inline void List_1_set_Capacity_m4B212271F60F59CA181E583E2FA1000A14E49C55 (List_1_tC943684C0EBEF2BD2CFD9D2B29FC554E51FBB6A8* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_tC943684C0EBEF2BD2CFD9D2B29FC554E51FBB6A8*, int32_t, const RuntimeMethod*))List_1_set_Capacity_mD826E33A9E5EBC19C714653217071790693E0B95_gshared)(__this, ___0_value, method);
}
// System.IntPtr Pico.Platform.CLIB::ppf_LeaderboardEntryArray_GetElement(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_LeaderboardEntryArray_GetElement_m3C349B967A2270ABE5B7C8D06573CF32E8E2D50A (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.LeaderboardEntry::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LeaderboardEntry__ctor_mFA163C827FC8CB49FC78292F3659A08DA0D2602A (LeaderboardEntry_tDFA599CDDC7EC20F2041B9BCF885BAE5A8B7DF9F* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.LeaderboardEntry>::Add(T)
inline void List_1_Add_m9BB55A99B1916D012AB4E3E0A2CAB3E7EFA4513D_inline (List_1_tC943684C0EBEF2BD2CFD9D2B29FC554E51FBB6A8* __this, LeaderboardEntry_tDFA599CDDC7EC20F2041B9BCF885BAE5A8B7DF9F* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tC943684C0EBEF2BD2CFD9D2B29FC554E51FBB6A8*, LeaderboardEntry_tDFA599CDDC7EC20F2041B9BCF885BAE5A8B7DF9F*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.UInt64 Pico.Platform.CLIB::ppf_LeaderboardEntryArray_GetTotalCount(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_LeaderboardEntryArray_GetTotalCount_m9F341000A8F8BE7E5D7985791DD5525CFBC782EB (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_MatchmakingAdminSnapshot_GetCandidates(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_MatchmakingAdminSnapshot_GetCandidates_m0CB683248FD83BD4A535EBD9CC3A1336C206673D (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MatchmakingAdminSnapshotCandidateList::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MatchmakingAdminSnapshotCandidateList__ctor_m50F375A22DF5875C52AB1E3D16267248A6433AD9 (MatchmakingAdminSnapshotCandidateList_tCB8BE369951F7307CA9A1AF9C7FE4B6253339C94* __this, intptr_t ___0_a, const RuntimeMethod* method) ;
// System.Double Pico.Platform.CLIB::ppf_MatchmakingAdminSnapshot_GetMyCurrentThreshold(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double CLIB_ppf_MatchmakingAdminSnapshot_GetMyCurrentThreshold_m1D6BE3E5F0A324CEE7B071C54CEDB4B6A18048AC (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_MatchmakingAdminSnapshotCandidate_GetCanMatch(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_MatchmakingAdminSnapshotCandidate_GetCanMatch_mDB3D34E534353B6F04752F4DF3457864650CCAD8 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Double Pico.Platform.CLIB::ppf_MatchmakingAdminSnapshotCandidate_GetMyTotalScore(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double CLIB_ppf_MatchmakingAdminSnapshotCandidate_GetMyTotalScore_mCF7A89A0A4901CF46E22531D1A06EDE19C62B3DE (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Double Pico.Platform.CLIB::ppf_MatchmakingAdminSnapshotCandidate_GetTheirCurrentThreshold(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double CLIB_ppf_MatchmakingAdminSnapshotCandidate_GetTheirCurrentThreshold_mF9F6AE9503B4234FB10B4B3EBDC01B4EA6365A8B (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.MatchmakingAdminSnapshotCandidate>::.ctor()
inline void MessageArray_1__ctor_mE5F28B4391D395F2076F7B3E76B2E9481C2151D5 (MessageArray_1_tE23B1EF897AC360EF5B5030E9C24FB894F1930F1* __this, const RuntimeMethod* method)
{
	((  void (*) (MessageArray_1_tE23B1EF897AC360EF5B5030E9C24FB894F1930F1*, const RuntimeMethod*))MessageArray_1__ctor_m9B6627200A9DB24455505C010AE4DD7BEF61F451_gshared)(__this, method);
}
// System.UIntPtr Pico.Platform.CLIB::ppf_MatchmakingAdminSnapshotCandidateArray_GetSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_MatchmakingAdminSnapshotCandidateArray_GetSize_m8A34154291D351ADB872A315BDFFF8F4829F13B1 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.MatchmakingAdminSnapshotCandidate>::set_Capacity(System.Int32)
inline void List_1_set_Capacity_m9C560D90140238E989BCCCBF65E8EB846AF78497 (List_1_tABBB0A07DB48EE3A69D8AE19FD395C748196C1A1* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_tABBB0A07DB48EE3A69D8AE19FD395C748196C1A1*, int32_t, const RuntimeMethod*))List_1_set_Capacity_mD826E33A9E5EBC19C714653217071790693E0B95_gshared)(__this, ___0_value, method);
}
// System.UIntPtr Pico.Platform.CLIB::ppf_MatchmakingAdminSnapshotCandidateArray_GetTotalCount(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_MatchmakingAdminSnapshotCandidateArray_GetTotalCount_m32171B9F840C1BB58BC5133F6996B70DB522AB8A (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_MatchmakingAdminSnapshotCandidateArray_GetElement(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_MatchmakingAdminSnapshotCandidateArray_GetElement_m995C8E82A7465BAC0FA0DC0B5635B2CC3EF7D0F0 (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MatchmakingAdminSnapshotCandidate::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MatchmakingAdminSnapshotCandidate__ctor_m3F82611D0119A6464ECE680CFF74F29F07BD7B5F (MatchmakingAdminSnapshotCandidate_t2325F5337C73FF55AB6D932F2A14C97E3A813CCC* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.MatchmakingAdminSnapshotCandidate>::Add(T)
inline void List_1_Add_mE84497F7EEB65DCBE2B85C3A5F3FF2DC6422FED0_inline (List_1_tABBB0A07DB48EE3A69D8AE19FD395C748196C1A1* __this, MatchmakingAdminSnapshotCandidate_t2325F5337C73FF55AB6D932F2A14C97E3A813CCC* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tABBB0A07DB48EE3A69D8AE19FD395C748196C1A1*, MatchmakingAdminSnapshotCandidate_t2325F5337C73FF55AB6D932F2A14C97E3A813CCC*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.IntPtr Pico.Platform.CLIB::ppf_MatchmakingBrowseResult_GetEnqueueResult(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_MatchmakingBrowseResult_GetEnqueueResult_m62835610E7E862A8F90CD939A40FA4B7F8B04DAA (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MatchmakingEnqueueResult::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MatchmakingEnqueueResult__ctor_m1DBC53F8E1F86E378EBEAC70B8F4970AB5E522B2 (MatchmakingEnqueueResult_t620CF96FB5A92A1783E9882E651C0CA76E2E3D8D* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_MatchmakingBrowseResult_GetRooms(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_MatchmakingBrowseResult_GetRooms_m1B6E3043995372FDD6DEA166137833B3BE1BC7DE (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MatchmakingRoomList::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MatchmakingRoomList__ctor_mBF3ED0010AE228A6D6F3C03B33A5766A8DC45A2C (MatchmakingRoomList_t97325021F617542B368184443F745CC637C866B7* __this, intptr_t ___0_a, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_MatchmakingEnqueueResult_GetAdminSnapshot(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_MatchmakingEnqueueResult_GetAdminSnapshot_m87701284D7265519A6B100F8F6B159259DFF3118 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MatchmakingAdminSnapshot::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MatchmakingAdminSnapshot__ctor_m17C01478ACBD07391C18DD67F372B6471E2E971F (MatchmakingAdminSnapshot_tF75B3A1A51D503587990BECC068C30E7671EE451* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.UInt32 Pico.Platform.CLIB::ppf_MatchmakingEnqueueResult_GetAverageWait(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t CLIB_ppf_MatchmakingEnqueueResult_GetAverageWait_m8FECAEC6709FA5A2FBDE7DC205D6E57D43941828 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt32 Pico.Platform.CLIB::ppf_MatchmakingEnqueueResult_GetMatchesInLastHourCount(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t CLIB_ppf_MatchmakingEnqueueResult_GetMatchesInLastHourCount_mF388BE2C8932701C42D1DF7D08AB933AC7231408 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt32 Pico.Platform.CLIB::ppf_MatchmakingEnqueueResult_GetMaxExpectedWait(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t CLIB_ppf_MatchmakingEnqueueResult_GetMaxExpectedWait_m25210EB92326DFE11D42E0F5B3524485D68A3A42 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_MatchmakingEnqueueResult_GetPool(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_MatchmakingEnqueueResult_GetPool_mA9A02C7043D099D9D62B0F36DC1C628E73FF858C (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt32 Pico.Platform.CLIB::ppf_MatchmakingEnqueueResult_GetRecentMatchPercentage(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t CLIB_ppf_MatchmakingEnqueueResult_GetRecentMatchPercentage_mBB8931E1C1A4577CD3C44C8591700B5A4948B4EC (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_MatchmakingEnqueueResultAndRoom_GetMatchmakingEnqueueResult(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_MatchmakingEnqueueResultAndRoom_GetMatchmakingEnqueueResult_mED20A27D4CFF9F5276D9AC63FE29F1B6C5A7AB15 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_MatchmakingEnqueueResultAndRoom_GetRoom(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_MatchmakingEnqueueResultAndRoom_GetRoom_m86009926F9CA13C7F5CD77CEF97F249D6740B792 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.Room::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Room__ctor_mB6AF794D98BC22F1081870DD63E403520D1172A4 (Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.UInt32 Pico.Platform.CLIB::ppf_MatchmakingRoom_GetPingTime(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t CLIB_ppf_MatchmakingRoom_GetPingTime_mAA23B36D8A287BA035E6ED85F526D3F14AF78DC1 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_MatchmakingRoom_GetRoom(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_MatchmakingRoom_GetRoom_m0E5CBF5B108FE569A7F3FDA771CA8C6C1F9212A7 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_MatchmakingRoom_HasPingTime(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_MatchmakingRoom_HasPingTime_mDC473D8557C77E6171E24B8FEBB87135C971F025 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.MatchmakingRoom>::.ctor()
inline void MessageArray_1__ctor_mB4514016DE6C8FA4D4FA07951B03B60B17241AF4 (MessageArray_1_t8EC5BA1648CB587D9A9B26B0134F98287F69DB97* __this, const RuntimeMethod* method)
{
	((  void (*) (MessageArray_1_t8EC5BA1648CB587D9A9B26B0134F98287F69DB97*, const RuntimeMethod*))MessageArray_1__ctor_m9B6627200A9DB24455505C010AE4DD7BEF61F451_gshared)(__this, method);
}
// System.Int32 Pico.Platform.CLIB::ppf_MatchmakingRoomArray_GetTotalCount(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_MatchmakingRoomArray_GetTotalCount_mBFC4A61756F15490A4E65617803E4DF9555076DD (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UIntPtr Pico.Platform.CLIB::ppf_MatchmakingRoomArray_GetSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_MatchmakingRoomArray_GetSize_m3E0F05F00CAB266C337B39C36066975FA408CE99 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.MatchmakingRoom>::set_Capacity(System.Int32)
inline void List_1_set_Capacity_mFAD4171F2861E97F209DAECB9E5C50BCD34018E4 (List_1_tA41CDF0D6A3ED7853A9F821A69838D214E8DD5CB* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_tA41CDF0D6A3ED7853A9F821A69838D214E8DD5CB*, int32_t, const RuntimeMethod*))List_1_set_Capacity_mD826E33A9E5EBC19C714653217071790693E0B95_gshared)(__this, ___0_value, method);
}
// System.IntPtr Pico.Platform.CLIB::ppf_MatchmakingRoomArray_GetElement(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_MatchmakingRoomArray_GetElement_m23B64ADB8084AAB92FB7CEA0668DE9A1E5233A42 (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MatchmakingRoom::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MatchmakingRoom__ctor_m46F4C484B14D0EFE7025B8533694403B300BA600 (MatchmakingRoom_t564ECF1B3DF437F6B3DE5EC03A5E173193CE6C74* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.MatchmakingRoom>::Add(T)
inline void List_1_Add_mC7D6941F0CB7269D1259683EB81DAF543E912E13_inline (List_1_tA41CDF0D6A3ED7853A9F821A69838D214E8DD5CB* __this, MatchmakingRoom_t564ECF1B3DF437F6B3DE5EC03A5E173193CE6C74* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tA41CDF0D6A3ED7853A9F821A69838D214E8DD5CB*, MatchmakingRoom_t564ECF1B3DF437F6B3DE5EC03A5E173193CE6C74*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.UInt32 Pico.Platform.CLIB::ppf_MatchmakingStats_GetDrawCount(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t CLIB_ppf_MatchmakingStats_GetDrawCount_mF4A456FC1B4466E8C9811C09BE8182AAD7457C59 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt32 Pico.Platform.CLIB::ppf_MatchmakingStats_GetLossCount(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t CLIB_ppf_MatchmakingStats_GetLossCount_mBB791178F0B33C965D307702642E9AF81E5DD8B9 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt32 Pico.Platform.CLIB::ppf_MatchmakingStats_GetSkillLevel(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t CLIB_ppf_MatchmakingStats_GetSkillLevel_mA2724D972FC9C34685DE2133B15F24A310985F03 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Double Pico.Platform.CLIB::ppf_MatchmakingStats_GetSkillMean(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double CLIB_ppf_MatchmakingStats_GetSkillMean_mBF97220B599E89F923BF50B2093551F627A4D1E3 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Double Pico.Platform.CLIB::ppf_MatchmakingStats_GetSkillStandardDeviation(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double CLIB_ppf_MatchmakingStats_GetSkillStandardDeviation_m2325D7197971CD4E7B360EFDD698D579CD8E518F (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt32 Pico.Platform.CLIB::ppf_MatchmakingStats_GetWinCount(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t CLIB_ppf_MatchmakingStats_GetWinCount_mEBFA9453303F0D58F10B941BD5EFA84A672FC6AE (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_RoomInviteNotification_GetID(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_RoomInviteNotification_GetID_mD6D10056CC12F0A434A6CC2740DDC1A952FEDB2D (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_RoomInviteNotification_GetRoomID(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_RoomInviteNotification_GetRoomID_mE73AAC70259740E82090E8687216CD4AC29DD87C (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RoomInviteNotification_GetSenderID(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RoomInviteNotification_GetSenderID_m1D46374A1FAB8BADEEE67D5DBCCBE18DAE4A354F (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_RoomInviteNotification_GetSentTime(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_RoomInviteNotification_GetSentTime_mAEC1C6674E386A69539B2FA682BBBF2459DD0B19 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String System.String::Format(System.String,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8 (String_t* ___0_format, RuntimeObject* ___1_arg0, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.RoomInviteNotification>::.ctor()
inline void MessageArray_1__ctor_mFF477189E1B6F9EDC567DBA6165ECCB6EEA64992 (MessageArray_1_t48F2634F7CE492870D7F60BCDB4ECBAEABA4E185* __this, const RuntimeMethod* method)
{
	((  void (*) (MessageArray_1_t48F2634F7CE492870D7F60BCDB4ECBAEABA4E185*, const RuntimeMethod*))MessageArray_1__ctor_m9B6627200A9DB24455505C010AE4DD7BEF61F451_gshared)(__this, method);
}
// System.Int32 Pico.Platform.CLIB::ppf_RoomInviteNotificationArray_GetTotalCount(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RoomInviteNotificationArray_GetTotalCount_m49BDB4D93FC555216E86B5DD8275B6DAB19850CB (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_RoomInviteNotificationArray_HasNextPage(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_RoomInviteNotificationArray_HasNextPage_mE7D2FE60429DA2B997AE8CDA87FF5B48626A119E (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UIntPtr Pico.Platform.CLIB::ppf_RoomInviteNotificationArray_GetSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_RoomInviteNotificationArray_GetSize_m8DB92AE82619BEEE1AB8BC0669A94B56E6C03FBA (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.RoomInviteNotification>::set_Capacity(System.Int32)
inline void List_1_set_Capacity_mD5F6FA2BE282F629E5D80DDC855BCC02C875A92C (List_1_t56C8E4CBC81C6319DB682BE3E114E43F68C3AB09* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_t56C8E4CBC81C6319DB682BE3E114E43F68C3AB09*, int32_t, const RuntimeMethod*))List_1_set_Capacity_mD826E33A9E5EBC19C714653217071790693E0B95_gshared)(__this, ___0_value, method);
}
// System.IntPtr Pico.Platform.CLIB::ppf_RoomInviteNotificationArray_GetElement(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_RoomInviteNotificationArray_GetElement_mAADDBBD091434F67605C7E98B721EAB83DC3A0D8 (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.RoomInviteNotification::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RoomInviteNotification__ctor_mDA79BD8FFD71AA71B259F71C4F7ADC58D97C8801 (RoomInviteNotification_t056C5D7720D5A52379CEB33A2BEB26EDB399E048* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.RoomInviteNotification>::Add(T)
inline void List_1_Add_mD38485CA318AF8F55C5985FACCBAA11B2D534F69_inline (List_1_t56C8E4CBC81C6319DB682BE3E114E43F68C3AB09* __this, RoomInviteNotification_t056C5D7720D5A52379CEB33A2BEB26EDB399E048* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t56C8E4CBC81C6319DB682BE3E114E43F68C3AB09*, RoomInviteNotification_t056C5D7720D5A52379CEB33A2BEB26EDB399E048*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.UIntPtr Pico.Platform.CLIB::ppf_Packet_GetSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_Packet_GetSize_mB04A129338AA0D2154D3DB303C4DFC6D64311858 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_Packet_GetBytes(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_Packet_GetBytes_mF023FD284DEE919E175C1C48DBE2D22D6EE97381 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.ArgumentException::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465 (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* __this, String_t* ___0_message, const RuntimeMethod* method) ;
// System.Text.Encoding System.Text.Encoding::get_UTF8()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* Encoding_get_UTF8_m9FA98A53CE96FD6D02982625C5246DD36C1235C9 (const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Packet_GetSenderID(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Packet_GetSenderID_m94CE0688625FD51880BEAA2CDBE9C28EEAB7CD97 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.Packet::Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Packet_Dispose_m31A384FDEF4FA99104B062F2739AC7EE812A1D12 (Packet_tE7ABCB3CA16D45A82E180266269EC1B89F8054A9* __this, const RuntimeMethod* method) ;
// System.Void Pico.Platform.CLIB::ppf_Packet_Free(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CLIB_ppf_Packet_Free_m0922C9E7C571AAC53155733B5BC94C8A1299078E (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.GC::SuppressFinalize(System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GC_SuppressFinalize_m71815DBD5A0CD2EA1BE43317B08B7A14949EDC65 (RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Destination_GetApiName(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Destination_GetApiName_m0358EA5D0C2969A214D5D61E0F49A4F1CA223B48 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Destination_GetDeeplinkMessage(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Destination_GetDeeplinkMessage_mB3126F2C2D771F7FE39D1A7394AEA01BD6D976A0 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Destination_GetDisplayName(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Destination_GetDisplayName_m57C826273ECA1263EC1434BE117FA7D369745BD7 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Destination>::.ctor()
inline void MessageArray_1__ctor_m070B185DC9BE9A46B820CFCFED8A57D14830275F (MessageArray_1_t77601FC32D4AB8164AF6BDA2F26DA8D5510A8C1D* __this, const RuntimeMethod* method)
{
	((  void (*) (MessageArray_1_t77601FC32D4AB8164AF6BDA2F26DA8D5510A8C1D*, const RuntimeMethod*))MessageArray_1__ctor_m9B6627200A9DB24455505C010AE4DD7BEF61F451_gshared)(__this, method);
}
// System.UIntPtr Pico.Platform.CLIB::ppf_DestinationArray_GetSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_DestinationArray_GetSize_mA1EDBE551B0CC115EA4775DBE0582B063C1353D6 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.Destination>::set_Capacity(System.Int32)
inline void List_1_set_Capacity_mA24D986986B27033E4B1A500D132B53EAF4F974D (List_1_t5C085F464CB50B6E73049AC6D994648AA7E2410E* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_t5C085F464CB50B6E73049AC6D994648AA7E2410E*, int32_t, const RuntimeMethod*))List_1_set_Capacity_mD826E33A9E5EBC19C714653217071790693E0B95_gshared)(__this, ___0_value, method);
}
// System.IntPtr Pico.Platform.CLIB::ppf_DestinationArray_GetElement(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_DestinationArray_GetElement_mA7387DBCB2F0792EC947B62AF1543C5D1FE083DE (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.Destination>::Add(T)
inline void List_1_Add_m4F59D0CC812DAC6ECC6BFC85CDD3210501B8FFD0_inline (List_1_t5C085F464CB50B6E73049AC6D994648AA7E2410E* __this, Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t5C085F464CB50B6E73049AC6D994648AA7E2410E*, Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.String Pico.Platform.CLIB::ppf_DestinationArray_GetNextPageParam(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_DestinationArray_GetNextPageParam_m91A57A95DE03A15CED98D64A436A189075C78E85 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_ApplicationInvite_GetDestination(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_ApplicationInvite_GetDestination_mA84E56331981169F0CFFDA755B04A556AE7D952A (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_ApplicationInvite_GetRecipient(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_ApplicationInvite_GetRecipient_m01707F7228F5D1B789120759EB5427B8046580E8 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_ApplicationInvite_GetID(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_ApplicationInvite_GetID_m3DB722CF432C2AFF8FB726B0DB2FA15A83019D95 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_ApplicationInvite_GetIsActive(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_ApplicationInvite_GetIsActive_m7DBE6151519B3634BEAD930EC7B8FF9A35255C60 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_ApplicationInvite_GetLobbySessionId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_ApplicationInvite_GetLobbySessionId_m80D075C4696B4D93B5527C540B20C6BC65C85572 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_ApplicationInvite_GetMatchSessionId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_ApplicationInvite_GetMatchSessionId_m801472832EC6DBE1432DD98D8E32395D7BE1A84F (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.ApplicationInvite>::.ctor()
inline void MessageArray_1__ctor_m667099D521C9333D86ABAA3B49FBF8DF9D833999 (MessageArray_1_tBD7F57C2576E156E6CA055C10BDF9CF1A640AAB8* __this, const RuntimeMethod* method)
{
	((  void (*) (MessageArray_1_tBD7F57C2576E156E6CA055C10BDF9CF1A640AAB8*, const RuntimeMethod*))MessageArray_1__ctor_m9B6627200A9DB24455505C010AE4DD7BEF61F451_gshared)(__this, method);
}
// System.UIntPtr Pico.Platform.CLIB::ppf_ApplicationInviteArray_GetSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_ApplicationInviteArray_GetSize_m2DF9E43B4A0A2176BD28C9B1DDD4CD560A05E1AD (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.ApplicationInvite>::set_Capacity(System.Int32)
inline void List_1_set_Capacity_mCA9040FB8D0912244F96B1C4B829379A6145F529 (List_1_tE88D817DED2AB9E24E7A5629200C2087045253F5* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_tE88D817DED2AB9E24E7A5629200C2087045253F5*, int32_t, const RuntimeMethod*))List_1_set_Capacity_mD826E33A9E5EBC19C714653217071790693E0B95_gshared)(__this, ___0_value, method);
}
// System.IntPtr Pico.Platform.CLIB::ppf_ApplicationInviteArray_GetElement(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_ApplicationInviteArray_GetElement_m0D79E2A49F2F3F058AD49889360B1100FE7E8B02 (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.ApplicationInvite::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ApplicationInvite__ctor_m0A9B118AFC2B0FB82F841901E3AE34B083AFF954 (ApplicationInvite_t95D2E15775E4CD15D060CDF6CF25EDB854EB67D7* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.ApplicationInvite>::Add(T)
inline void List_1_Add_m184EE05AA8961970FF60E58756ED8BE4F017374E_inline (List_1_tE88D817DED2AB9E24E7A5629200C2087045253F5* __this, ApplicationInvite_t95D2E15775E4CD15D060CDF6CF25EDB854EB67D7* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tE88D817DED2AB9E24E7A5629200C2087045253F5*, ApplicationInvite_t95D2E15775E4CD15D060CDF6CF25EDB854EB67D7*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.String Pico.Platform.CLIB::ppf_ApplicationInviteArray_GetNextPageParam(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_ApplicationInviteArray_GetNextPageParam_mB55F86F34B099B43F98135C6CD57C7586FD1F18D (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_SendInvitesResult_GetInvites(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_SendInvitesResult_GetInvites_mB909189924E191656201ACF2753F80A4286267E0 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.ApplicationInviteList::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ApplicationInviteList__ctor_mF3D2F58B366BD4BF1634F9EF207061494C7826FE (ApplicationInviteList_tCFA701E5249821E8B9BBFD13F595859AFFAB19DB* __this, intptr_t ___0_a, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_PresenceJoinIntent_GetDeeplinkMessage(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_PresenceJoinIntent_GetDeeplinkMessage_mEC5BD9E839DAEC976EA134948DD816E5B9261B37 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_PresenceJoinIntent_GetDestinationApiName(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_PresenceJoinIntent_GetDestinationApiName_mF87288B9573B0363E84219192BA157F0A9BD072D (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_PresenceJoinIntent_GetLobbySessionId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_PresenceJoinIntent_GetLobbySessionId_m3D139C17978DC32D20928AB0EAC3303180A3D18D (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_PresenceJoinIntent_GetMatchSessionId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_PresenceJoinIntent_GetMatchSessionId_m6A00ED473DCD613E13BFC9A97E1897C05F57EE8C (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_PresenceJoinIntent_GetExtra(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_PresenceJoinIntent_GetExtra_m939574DE3F4E9C43D212B73D89EB729266F724E0 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt32 Pico.Platform.CLIB::ppf_Room_GetPlayerNumber(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t CLIB_ppf_Room_GetPlayerNumber_mF381C436C9F47A2382903E4ECEE26D94F7B4CC4C (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_Room_GetDataStore(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_Room_GetDataStore_mD837F6F5F9D8454C3CED911061B3182798B58A75 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Collections.Generic.Dictionary`2<System.String,System.String> Pico.Platform.CLIB::DataStoreFromNative(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Dictionary_2_t46B2DB028096FA2B828359E52F37F3105A83AD83* CLIB_DataStoreFromNative_m765A5372300BCCB3279F02A012FDDF4E30ED626A (intptr_t ___0_ppfDataStore, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Room_GetDescription(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Room_GetDescription_m0B3F47015616F855934978A1E3363FF8133B2B2D (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt64 Pico.Platform.CLIB::ppf_Room_GetID(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t CLIB_ppf_Room_GetID_mA3F30744CFD4B32773033B92C35D36EDCFC52302 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_Room_GetIsMembershipLocked(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_Room_GetIsMembershipLocked_m1B8FC8CD5743C03D290C0D1252D3254AE6E36137 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.RoomJoinPolicy Pico.Platform.CLIB::ppf_Room_GetJoinPolicy(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_Room_GetJoinPolicy_m9D566A4693F674501E54329CA22962C45D4356AB (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.RoomJoinability Pico.Platform.CLIB::ppf_Room_GetJoinability(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_Room_GetJoinability_mCA89ED58AAB4D55330CFFB99E77AD3126DB2C52A (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UInt32 Pico.Platform.CLIB::ppf_Room_GetMaxUsers(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t CLIB_ppf_Room_GetMaxUsers_m72EAD2F61A6C02DFC70142B2D8FA1D8B623B6159 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_Room_GetName(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_Room_GetName_m87A770FD459F4539848860C47986204CCEE10162 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.RoomType Pico.Platform.CLIB::ppf_Room_GetType(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_Room_GetType_mA5FCEBA4DC0D3B9D9DDCE628BFC7009C0398FF4B (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_Room_GetOwner(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_Room_GetOwner_m431345003BF1B39434CBC260A90E38C1D582180C (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_Room_GetUsers(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_Room_GetUsers_mEEBAF8CF27478C8D3DACBACBF5465AC8A887F4A9 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.Room>::.ctor()
inline void MessageArray_1__ctor_m44916C4D5F46A3D4CB182D99F9E370CBFA347B97 (MessageArray_1_t13175CA17EF1C58A6CE16C1C5CC33E66B189C0DB* __this, const RuntimeMethod* method)
{
	((  void (*) (MessageArray_1_t13175CA17EF1C58A6CE16C1C5CC33E66B189C0DB*, const RuntimeMethod*))MessageArray_1__ctor_m9B6627200A9DB24455505C010AE4DD7BEF61F451_gshared)(__this, method);
}
// System.Int32 Pico.Platform.CLIB::ppf_RoomArray_GetTotalCount(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RoomArray_GetTotalCount_m2661AEA71C41F53C8AC1225268F82F5EF5D80A57 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_RoomArray_GetPageIndex(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RoomArray_GetPageIndex_m62BC5997CFD307B686887BF746D683DE74791386 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_RoomArray_GetPageSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RoomArray_GetPageSize_m500EFA10A28E0EA6400521CBDAB553FA9E815793 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_RoomArray_HasNextPage(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_RoomArray_HasNextPage_m5E21A22CDD09E128D8185D93CBBD970AB7386B33 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UIntPtr Pico.Platform.CLIB::ppf_RoomArray_GetSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_RoomArray_GetSize_mE6F66F2A0AA5392B901AAC29B48B609CB25319D9 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.Room>::set_Capacity(System.Int32)
inline void List_1_set_Capacity_m5D4C4FA3EEC9734BCBF629BCC57F31DB95D20AC3 (List_1_t17BC494950CA211E4E00DDC3979C43A2750F5DF8* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_t17BC494950CA211E4E00DDC3979C43A2750F5DF8*, int32_t, const RuntimeMethod*))List_1_set_Capacity_mD826E33A9E5EBC19C714653217071790693E0B95_gshared)(__this, ___0_value, method);
}
// System.IntPtr Pico.Platform.CLIB::ppf_RoomArray_GetElement(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_RoomArray_GetElement_mBB99290A1434BC5F54FB13DAD7EE244C59F58DBB (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.Room>::Add(T)
inline void List_1_Add_mD04F4301A11C785E216B4D3B39B7BBA17AC556D0_inline (List_1_t17BC494950CA211E4E00DDC3979C43A2750F5DF8* __this, Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t17BC494950CA211E4E00DDC3979C43A2750F5DF8*, Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.String Pico.Platform.CLIB::ppf_RtcBinaryMessageReceived_GetUserId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcBinaryMessageReceived_GetUserId_m478FB5FD03D4B5E3C7B64D81EC4302871E488983 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_RtcBinaryMessageReceived_GetData(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_RtcBinaryMessageReceived_GetData_m81ABEA3C4B96053A8A7C3E8BFCD88E62BAE4ACE4 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_RtcBinaryMessageReceived_GetLength(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcBinaryMessageReceived_GetLength_m6D5E0F8F65662C06B8EF7878D9B63BEA03F0149B (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcBinaryMessageReceived_GetRoomId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcBinaryMessageReceived_GetRoomId_mEF08BBA5951DE0FF99FA66EABC400270CBCEFDCB (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.RtcAudioChannel Pico.Platform.CLIB::ppf_RtcAudioFrame_GetChannel(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcAudioFrame_GetChannel_mD6D1E07ADF59FE9E2028C71EDC07401E81580C37 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_RtcAudioFrame_GetDataSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_RtcAudioFrame_GetDataSize_m0F23B0997DD19BB022CC11AE23C5EB3A8F4717E2 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.RtcAudioSampleRate Pico.Platform.CLIB::ppf_RtcAudioFrame_GetSampleRate(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcAudioFrame_GetSampleRate_mA4E8F41486076F9DA889BC35E9B3BDBC9C166D15 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_RtcAudioFrame_GetTimeStampInUs(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_RtcAudioFrame_GetTimeStampInUs_m0041CF3BD08AF21B83680DE3C14DE3B3EE7A9DD6 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_RtcAudioFrame_GetData(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_RtcAudioFrame_GetData_m7CE07FFC43BA3BDA471CD5CC6091152AE9D51FAD (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.Runtime.InteropServices.Marshal::Copy(System.Byte[],System.Int32,System.IntPtr,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Marshal_Copy_m0FD7BFE70EE28FC67B67A6225AD58F95FEE7EB85 (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_source, int32_t ___1_startIndex, intptr_t ___2_destination, int32_t ___3_length, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_RtcMessageSendResult_GetMessageId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_RtcMessageSendResult_GetMessageId_m84BFDE85197263777DC7E3A4A4CE0448B3F35B4D (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_RtcMessageSendResult_GetError(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcMessageSendResult_GetError_m1D6E956099B565274366B009ED16FFA6314D8906 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcMessageSendResult_GetRoomId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcMessageSendResult_GetRoomId_m075541A68FE8AF0FB5C647A738BCFE390FA79DCD (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcUserUnPublishInfo_GetUserId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcUserUnPublishInfo_GetUserId_m2AD74BDEC261D1B4EFF2BC75EE2B63DE7C7128B8 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.RtcMediaStreamType Pico.Platform.CLIB::ppf_RtcUserUnPublishInfo_GetMediaStreamType(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcUserUnPublishInfo_GetMediaStreamType_mEBAA1257A91DA1176359E5FFBC22BA5E4CA7827B (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.RtcStreamRemoveReason Pico.Platform.CLIB::ppf_RtcUserUnPublishInfo_GetReason(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcUserUnPublishInfo_GetReason_m5523F98C749506DC858C9B6FCC488A4B8893482D (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcUserUnPublishInfo_GetRoomId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcUserUnPublishInfo_GetRoomId_m862D932E2E63653FC3C8C219E2854A6E8467487D (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcUserPublishInfo_GetUserId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcUserPublishInfo_GetUserId_mD536E2D18A7FE9469C68A1A896006B66283C29AF (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.RtcMediaStreamType Pico.Platform.CLIB::ppf_RtcUserPublishInfo_GetMediaStreamType(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcUserPublishInfo_GetMediaStreamType_mD685C6967DBF6EBD5CE2D69A128001E3013B78BF (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcUserPublishInfo_GetRoomId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcUserPublishInfo_GetRoomId_m7E3EFAE76F5A2203078B101139E1BC358479DC15 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcRoomMessageReceived_GetUserId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcRoomMessageReceived_GetUserId_m71EB1F5F678313095D8363D6E9BFCBCC6360B7EB (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcRoomMessageReceived_GetMessage(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcRoomMessageReceived_GetMessage_m518329CB1155942FF688118A63F4646C1F761A36 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcRoomMessageReceived_GetRoomId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcRoomMessageReceived_GetRoomId_mBDCA14ED6669936E2FC042828E41B5E047E62D73 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcUserMessageReceived_GetUserId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcUserMessageReceived_GetUserId_mF533611B5554D19A87DDA117D6392B36F696FA32 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcUserMessageReceived_GetMessage(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcUserMessageReceived_GetMessage_m42471F11BBB06C03967CE05084E2B39601BB8948 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcUserMessageReceived_GetRoomId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcUserMessageReceived_GetRoomId_m1BF852B51AEFEFE6234A5DFB619CF2557EB958EC (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_RtcStreamSyncInfo_GetStreamKey(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_RtcStreamSyncInfo_GetStreamKey_m322991CAE437275C9D8B083BBB49873B5EACF8EE (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.RtcRemoteStreamKey::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRemoteStreamKey__ctor_mA8181CF8D33199DCDEE57AE098F0FF9558C00875 (RtcRemoteStreamKey_tA69532F8EF7C977014612F775D146C3038C61E0E* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// Pico.Platform.RtcSyncInfoStreamType Pico.Platform.CLIB::ppf_RtcStreamSyncInfo_GetStreamType(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcStreamSyncInfo_GetStreamType_mFA1FDA3DF9B685216E5D800FFEA53B9F26B666CE (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_RtcStreamSyncInfo_GetData(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_RtcStreamSyncInfo_GetData_mE0A7B33ACED6C41D71FAD9C28C47A364CEA6079A (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_RtcStreamSyncInfo_GetLength(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcStreamSyncInfo_GetLength_m0F4F4414BD684565B89550F1A09ACF35B4FF33AC (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_RtcAudioPropertyInfo_GetVolume(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcAudioPropertyInfo_GetVolume_m9474186E2E8DC2F5EA26F9BEEC7089C05948945E (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcJoinRoomResult_GetRoomId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcJoinRoomResult_GetRoomId_m04AE68133066E50638087B9058D7B9B3CBCE8B43 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcJoinRoomResult_GetUserId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcJoinRoomResult_GetUserId_m0CFD8C64966F9833BB1CEF57203161AE233B4EF8 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_RtcJoinRoomResult_GetErrorCode(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcJoinRoomResult_GetErrorCode_mF2A0FC1F97D6650A93B30E7FE911899A1719E966 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_RtcJoinRoomResult_GetElapsed(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcJoinRoomResult_GetElapsed_m29C0057D84EB39E560E11C9ED4C624624B32AD18 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.RtcJoinRoomType Pico.Platform.CLIB::ppf_RtcJoinRoomResult_GetJoinType(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcJoinRoomResult_GetJoinType_mE542290DDE8C760ABABA9CFB59E5D5CA4A735597 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcLeaveRoomResult_GetRoomId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcLeaveRoomResult_GetRoomId_mB02EE9AE6A9E7FFD51F79BB546AD052AB5F63897 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.RtcStreamIndex Pico.Platform.CLIB::ppf_RtcLocalAudioPropertiesInfo_GetStreamIndex(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcLocalAudioPropertiesInfo_GetStreamIndex_mB7ACF6AB0A3CC4F5500227D3C3D02C89ACAC7DBA (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_RtcLocalAudioPropertiesInfo_GetAudioPropertyInfo(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_RtcLocalAudioPropertiesInfo_GetAudioPropertyInfo_mC539E7606ADF0FADFB7ECBD139B35BF7BD0F0D93 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.RtcAudioPropertyInfo::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcAudioPropertyInfo__ctor_mC061C4E479AA1830243454373F9FF6FEDC6C96DD (RtcAudioPropertyInfo_tA10BA2C71B943D7A31ED99324B58ECBC13C05268* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.UIntPtr Pico.Platform.CLIB::ppf_RtcLocalAudioPropertiesReport_GetAudioPropertiesInfosSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_RtcLocalAudioPropertiesReport_GetAudioPropertiesInfosSize_mE5764E08811AE948FF5E24E71082CCBCF3912CFE (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_RtcLocalAudioPropertiesReport_GetAudioPropertiesInfos(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_RtcLocalAudioPropertiesReport_GetAudioPropertiesInfos_mE0778B47DA70715114CAC02EAEF2BA8CA2D2FFB2 (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.RtcLocalAudioPropertiesInfo::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcLocalAudioPropertiesInfo__ctor_m62EA3EAC77FF4AA26A9A1E437EC790B4BFA936D4 (RtcLocalAudioPropertiesInfo_tDEE2268599EA8C3EC747871F690C5743321ED49E* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcMediaDeviceChangeInfo_GetDeviceId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcMediaDeviceChangeInfo_GetDeviceId_mD080CF35717527AC3A39D3DB669A418A3536FACF (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.RtcMediaDeviceType Pico.Platform.CLIB::ppf_RtcMediaDeviceChangeInfo_GetDeviceType(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcMediaDeviceChangeInfo_GetDeviceType_mF351F9687B4EE87DB2B92BAB1778D6498534257B (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.RtcMediaDeviceState Pico.Platform.CLIB::ppf_RtcMediaDeviceChangeInfo_GetDeviceState(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcMediaDeviceChangeInfo_GetDeviceState_mA052BC17A25AF289F52F5F842AF9360E4322FD78 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.RtcMediaDeviceError Pico.Platform.CLIB::ppf_RtcMediaDeviceChangeInfo_GetDeviceError(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcMediaDeviceChangeInfo_GetDeviceError_m5DD51953D1D6B47D38BEA7CAA5BFAAAEBE93BF1B (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcMuteInfo_GetUserId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcMuteInfo_GetUserId_mECDD26685782CF1C9C0BF2B387FDA97F90855D79 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.RtcMuteState Pico.Platform.CLIB::ppf_RtcMuteInfo_GetMuteState(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcMuteInfo_GetMuteState_m6D2A6AD463AEACC90E5C553AC61B6639BF219F5C (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_RtcRemoteAudioPropertiesInfo_GetStreamKey(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_RtcRemoteAudioPropertiesInfo_GetStreamKey_m29701F1CAD40F4E3CEA2CB0AFDAF32687C31ED75 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_RtcRemoteAudioPropertiesInfo_GetAudioPropertiesInfo(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_RtcRemoteAudioPropertiesInfo_GetAudioPropertiesInfo_m1FD8D4C46811BE8C893AA9079AAC0821BEA3835C (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UIntPtr Pico.Platform.CLIB::ppf_RtcRemoteAudioPropertiesReport_GetAudioPropertiesInfosSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_RtcRemoteAudioPropertiesReport_GetAudioPropertiesInfosSize_mDC7D1FA23CCCFB05934D0B09620CF7FBEB56BEE7 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_RtcRemoteAudioPropertiesReport_GetAudioPropertiesInfos(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_RtcRemoteAudioPropertiesReport_GetAudioPropertiesInfos_mB861D881206B2E67963B1FD1E36708EFA96B3C60 (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.RtcRemoteAudioPropertiesInfo::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRemoteAudioPropertiesInfo__ctor_mB57DCD21659CC7D50B528459D77BCD195151A538 (RtcRemoteAudioPropertiesInfo_t756C00636961DE878EE3D2DAD934F01DC0DE3C06* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_RtcRemoteAudioPropertiesReport_GetTotalRemoteVolume(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcRemoteAudioPropertiesReport_GetTotalRemoteVolume_mE273A923B61FEB94104FCE5F74F2F13D73111A8D (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcRemoteStreamKey_GetRoomId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcRemoteStreamKey_GetRoomId_mEC240EDB6E553C1BB7858D3EC192E7F4EC6ABF8C (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcRemoteStreamKey_GetUserId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcRemoteStreamKey_GetUserId_m752740195D7553E90ACC9A9F5DB55FF828F32C1B (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.RtcStreamIndex Pico.Platform.CLIB::ppf_RtcRemoteStreamKey_GetStreamIndex(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcRemoteStreamKey_GetStreamIndex_m04DA08988BEFC2FDBA1A4FF953FA21C17B7C46BF (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_RtcRoomError_GetCode(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcRoomError_GetCode_mD43CFDED25CF9BB29B81733140B7861B5E74B1D0 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcRoomError_GetRoomId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcRoomError_GetRoomId_m49DD269CFA22AE87ABAD01B04A2226B96F44278A (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_RtcRoomStats_GetTotalDuration(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcRoomStats_GetTotalDuration_mD290C803D191A9D7F8494D918DAA7A60BE53C1A8 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_RtcRoomStats_GetUserCount(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcRoomStats_GetUserCount_m5FF2D4018EFCF23C3BFA492DD1AEAB0AC181EDD1 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcRoomStats_GetRoomId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcRoomStats_GetRoomId_m0714FFD58930EF37598D7173AF86AB6BC4A4C59B (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_RtcRoomWarn_GetCode(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcRoomWarn_GetCode_mA07CDF200989FBD62FF5D36AA6D7A0FF859E07FD (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcRoomWarn_GetRoomId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcRoomWarn_GetRoomId_mCF5B71B2EED77BA0CC8955E9821C260EEE40B0A1 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcUserJoinInfo_GetUserId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcUserJoinInfo_GetUserId_mAB7DC7757B17BA43E1F677E0DAF097FA82EE45ED (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcUserJoinInfo_GetUserExtra(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcUserJoinInfo_GetUserExtra_mBEE960EDE2EAE2185937FE1EF20899A103B2B95C (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_RtcUserJoinInfo_GetElapsed(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcUserJoinInfo_GetElapsed_mCA4C9F7D363B7069999375A725496EC51950A75D (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcUserJoinInfo_GetRoomId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcUserJoinInfo_GetRoomId_m42A8B4AC3AFBCEF578550E778512120FBFFEC536 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcUserLeaveInfo_GetUserId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcUserLeaveInfo_GetUserId_mAEC74CE8B7BDB7860BD0DD256209ACAC6DBFA654 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.RtcUserLeaveReasonType Pico.Platform.CLIB::ppf_RtcUserLeaveInfo_GetOfflineReason(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_RtcUserLeaveInfo_GetOfflineReason_m086FDF661763803175EC997688F200A36E1BFEE8 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_RtcUserLeaveInfo_GetRoomId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_RtcUserLeaveInfo_GetRoomId_m518491FFC6B2A1CE2F13233721EECC2909230CF1 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_AsrResult_GetText(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_AsrResult_GetText_m98DC33A218EA20F4007023A3C9A9DAE655DC3981 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_AsrResult_GetIsFinalResult(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_AsrResult_GetIsFinalResult_mFA662FC4CE8DA4E8B6D4721940DF8F350863BDC1 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_SpeechError_GetMessage(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_SpeechError_GetMessage_mA9F88B85A0105651418FE850415A6DE0EBF73C02 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_SpeechError_GetCode(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_SpeechError_GetCode_m776FFB712F888806C1F3EF2832E6FBF703D3CD54 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_SpeechError_GetSessionId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_SpeechError_GetSessionId_m0CA11F6BAED5DB0FB2839B213E0E17E1A8B4F600 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_SportDailySummary_GetId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_SportDailySummary_GetId_mD0C7B8787EAE9F59909A790CAFD2571868596D6E (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_SportDailySummary_GetDate(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_SportDailySummary_GetDate_mD2688B53970514537C71524FA509B773751E0E6D (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_SportDailySummary_GetDurationInSeconds(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_SportDailySummary_GetDurationInSeconds_mB3CC475B83BD6172711D50E395583FA551AEC8F6 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_SportDailySummary_GetPlanDurationInMinutes(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_SportDailySummary_GetPlanDurationInMinutes_m5D35BAF66BE477FBA087DFCD04BF3F17710ADB7E (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Double Pico.Platform.CLIB::ppf_SportDailySummary_GetCalorie(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double CLIB_ppf_SportDailySummary_GetCalorie_m6E4BE90C8F10CAE8521D8B445EDF93C0B19B5D64 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Double Pico.Platform.CLIB::ppf_SportDailySummary_GetPlanCalorie(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double CLIB_ppf_SportDailySummary_GetPlanCalorie_mB82EC6532FB7EF2001A89D37929F321D7E1B73AF (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.SportDailySummary>::.ctor()
inline void MessageArray_1__ctor_m1A4632C39F931579FEBF2FEA60B370A49C699D53 (MessageArray_1_t50FAA95B2043C09E0B1018F924FCDEAD40EDFE38* __this, const RuntimeMethod* method)
{
	((  void (*) (MessageArray_1_t50FAA95B2043C09E0B1018F924FCDEAD40EDFE38*, const RuntimeMethod*))MessageArray_1__ctor_m9B6627200A9DB24455505C010AE4DD7BEF61F451_gshared)(__this, method);
}
// System.UIntPtr Pico.Platform.CLIB::ppf_SportDailySummaryArray_GetSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_SportDailySummaryArray_GetSize_m5095964C0C481DE77230E452B5B019EA2BD8C993 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.SportDailySummary>::set_Capacity(System.Int32)
inline void List_1_set_Capacity_m7C5EB735CBD98B3B2B64F7FA49954FD5ED73D728 (List_1_t6C36B6FAA48E5DAE13D84C1C2C9D39AEEF86399F* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6C36B6FAA48E5DAE13D84C1C2C9D39AEEF86399F*, int32_t, const RuntimeMethod*))List_1_set_Capacity_mD826E33A9E5EBC19C714653217071790693E0B95_gshared)(__this, ___0_value, method);
}
// System.IntPtr Pico.Platform.CLIB::ppf_SportDailySummaryArray_GetElement(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_SportDailySummaryArray_GetElement_mA3D507B82F2BCDC0B57FDBA460EE45C43AF85584 (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.SportDailySummary::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SportDailySummary__ctor_m414B482BE61A12E06A1A9AD9754172A30A153607 (SportDailySummary_t1202315FC8419F0C908ACF448A0DF4EF207756F0* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.SportDailySummary>::Add(T)
inline void List_1_Add_mB7F4419CE7EA8D9E393B3D5CF160812DB776DD9C_inline (List_1_t6C36B6FAA48E5DAE13D84C1C2C9D39AEEF86399F* __this, SportDailySummary_t1202315FC8419F0C908ACF448A0DF4EF207756F0* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6C36B6FAA48E5DAE13D84C1C2C9D39AEEF86399F*, SportDailySummary_t1202315FC8419F0C908ACF448A0DF4EF207756F0*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.Int64 Pico.Platform.CLIB::ppf_SportSummary_GetDurationInSeconds(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_SportSummary_GetDurationInSeconds_mEA277BCC9042996C88F05700B6F5F5E141CACE11 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Double Pico.Platform.CLIB::ppf_SportSummary_GetCalorie(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double CLIB_ppf_SportSummary_GetCalorie_mD0DED681090542C6772B89E941887D99F79C493F (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_SportSummary_GetStartTime(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_SportSummary_GetStartTime_m8B1F09B26AF08C93109B09230F61E765F14E5AB1 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_SportSummary_GetEndTime(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_SportSummary_GetEndTime_m0D4A52380219D1A445CFA7F717EE13AD0040D9D9 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.Gender Pico.Platform.CLIB::ppf_SportUserInfo_GetGender(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_SportUserInfo_GetGender_m4BA39777D6E8DCADBDD516A351E5525C79C2C632 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int64 Pico.Platform.CLIB::ppf_SportUserInfo_GetBirthday(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t CLIB_ppf_SportUserInfo_GetBirthday_m96446A5C5EE2E53AE7E9219F54BFC6069DC46779 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_SportUserInfo_GetStature(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_SportUserInfo_GetStature_m5308010D0B887831F1D027C7A7CA6EE4C3198C0B (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_SportUserInfo_GetWeight(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_SportUserInfo_GetWeight_m0917EEEDE18EEF40D96E5800918CB2A182350954 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_SportUserInfo_GetSportLevel(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_SportUserInfo_GetSportLevel_m50993DC43A4FF63D1F69C20072C1C4A4F6130ED3 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_SportUserInfo_GetDailyDurationInMinutes(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_SportUserInfo_GetDailyDurationInMinutes_m94D2A7F60CFA76305B38B721A092F32A2E3F9AA0 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_SportUserInfo_GetDaysPerWeek(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_SportUserInfo_GetDaysPerWeek_m6E4BFC9A8DFEB59492044F6B588646D21334B26D (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.SportTarget Pico.Platform.CLIB::ppf_SportUserInfo_GetSportTarget(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_SportUserInfo_GetSportTarget_m9C89EC1396CC22229A482F2095B6BD0662E2FEED (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_User_GetDisplayName(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_User_GetDisplayName_m6495233A8495D847FA8F01794081DDDC82EC514D (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_User_GetImageUrl(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_User_GetImageUrl_mF54B7F71B18B868BE97323D8F9D8D4B7FDDDCF6D (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_User_GetID(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_User_GetID_mFCED817FC648DDC3918EB0D56652F88342640033 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_User_GetInviteToken(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_User_GetInviteToken_m758417F040077D7413AD6E6B70A8F90C3DC44D17 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.UserPresenceStatus Pico.Platform.CLIB::ppf_User_GetPresenceStatus(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_User_GetPresenceStatus_m56F7990DB626B12C02E9C31E46DF1F2E3E71BE9F (intptr_t ___0_obj, const RuntimeMethod* method) ;
// Pico.Platform.Gender Pico.Platform.CLIB::ppf_User_GetGender(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_User_GetGender_mC6AA156708699C5B255F83D1B42FFDD20E56095E (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_User_GetPresence(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_User_GetPresence_m256411CC38F04771EA51021A5DE7730E181FB3CF (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_User_GetPresenceDeeplinkMessage(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_User_GetPresenceDeeplinkMessage_m2DA0CD3BE73EAD3BF0FE8F11629220E7F0B71276 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_User_GetPresenceDestinationApiName(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_User_GetPresenceDestinationApiName_mCAE5F575A00155B4B2E55B8D9B2A6814F90195CF (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_User_GetPresenceLobbySessionId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_User_GetPresenceLobbySessionId_m702C4BD3E75BD3EF160174ECB05F70F145051A26 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_User_GetPresenceMatchSessionId(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_User_GetPresenceMatchSessionId_m7FA4BBC2A376AEAC6CA8B25AFF69C76ACA3788CB (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_User_GetPresenceExtra(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_User_GetPresenceExtra_m12730CEEC5DC9E8737B6E2915C30F90F27D1F2C3 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_User_GetPresenceIsJoinable(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_User_GetPresenceIsJoinable_mFFA9BCA736B46C756A8ED1120DE8DE7DFF6BE133 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_User_GetSmallImageUrl(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_User_GetSmallImageUrl_m16BE75B35032EA60BE97C76FBE1F9436F7B5BD89 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_User_GetStoreRegion(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_User_GetStoreRegion_mE2E6D71E336324B0AF7AC2196293C613B85624BF (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.User>::.ctor()
inline void MessageArray_1__ctor_m67D3B507B26914F09606DA7A23A8061AC239B379 (MessageArray_1_t3FBFD71C2ED89BC1E98F61EFDB0C5C6DADE06A17* __this, const RuntimeMethod* method)
{
	((  void (*) (MessageArray_1_t3FBFD71C2ED89BC1E98F61EFDB0C5C6DADE06A17*, const RuntimeMethod*))MessageArray_1__ctor_m9B6627200A9DB24455505C010AE4DD7BEF61F451_gshared)(__this, method);
}
// System.UIntPtr Pico.Platform.CLIB::ppf_UserArray_GetSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_UserArray_GetSize_m303552B1FB5CE41D8FAB1842B601C9FF0D24B8ED (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.User>::set_Capacity(System.Int32)
inline void List_1_set_Capacity_m53C9442D7A2C89C4DC109B654F6515D05DE52B16 (List_1_tA51A980F281692A23CBC3DFCF8131D4AD8565A1C* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_tA51A980F281692A23CBC3DFCF8131D4AD8565A1C*, int32_t, const RuntimeMethod*))List_1_set_Capacity_mD826E33A9E5EBC19C714653217071790693E0B95_gshared)(__this, ___0_value, method);
}
// System.IntPtr Pico.Platform.CLIB::ppf_UserArray_GetElement(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_UserArray_GetElement_mA1E157914FFB811246B91FDE3EB6E5442CAC195D (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.User>::Add(T)
inline void List_1_Add_mFA38C07130F30DDA8AFCD688E19E79D20832CF90_inline (List_1_tA51A980F281692A23CBC3DFCF8131D4AD8565A1C* __this, User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tA51A980F281692A23CBC3DFCF8131D4AD8565A1C*, User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.String Pico.Platform.CLIB::ppf_UserArray_GetNextPageParam(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_UserArray_GetNextPageParam_m4698658C6DF4F21C3429E5BE1AE5C6D3AFAA395C (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_OrgScopedID_GetID(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_OrgScopedID_GetID_mA71FE5E5CCADE9A14878DB489CC90E98B2B18580 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_LaunchFriendRequestFlowResult_GetDidCancel(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_LaunchFriendRequestFlowResult_GetDidCancel_m049AD52959673162088772F82B3176442B1CA202 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.CLIB::ppf_LaunchFriendRequestFlowResult_GetDidSendRequest(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_LaunchFriendRequestFlowResult_GetDidSendRequest_m426F17F796ACB947A2E2BE3787834E3BF2E45E30 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_UserAndRoom_GetUser(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_UserAndRoom_GetUser_m530AD82C352C6974FC63728017898AA4DE1B7B6A (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.IntPtr Pico.Platform.CLIB::ppf_UserAndRoom_GetRoom(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_UserAndRoom_GetRoom_mA50990611C540C1B797CD00EEB25E5E4EFEABE04 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Boolean System.IntPtr::op_Inequality(System.IntPtr,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool IntPtr_op_Inequality_m90EFC9C4CAD9A33E309F2DDF98EE4E1DD253637B (intptr_t ___0_value1, intptr_t ___1_value2, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.MessageArray`1<Pico.Platform.Models.UserRoom>::.ctor()
inline void MessageArray_1__ctor_mAA26037C5A2D6E5B1A17B51AFAA9B774B6089B55 (MessageArray_1_tBDB39162E4555FCBD64BB106117908AC8831F004* __this, const RuntimeMethod* method)
{
	((  void (*) (MessageArray_1_tBDB39162E4555FCBD64BB106117908AC8831F004*, const RuntimeMethod*))MessageArray_1__ctor_m9B6627200A9DB24455505C010AE4DD7BEF61F451_gshared)(__this, method);
}
// System.UIntPtr Pico.Platform.CLIB::ppf_UserAndRoomArray_GetSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_UserAndRoomArray_GetSize_mCB6FEA277D47CA3F634B69E732D83DA24AE0EAD7 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.UserRoom>::set_Capacity(System.Int32)
inline void List_1_set_Capacity_m5DBD95CCEA8193924616281AFF64AA00130E135C (List_1_t68B676CB2F1554E5228FD7A20B97B490395C7E2C* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_t68B676CB2F1554E5228FD7A20B97B490395C7E2C*, int32_t, const RuntimeMethod*))List_1_set_Capacity_mD826E33A9E5EBC19C714653217071790693E0B95_gshared)(__this, ___0_value, method);
}
// System.IntPtr Pico.Platform.CLIB::ppf_UserAndRoomArray_GetElement(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t CLIB_ppf_UserAndRoomArray_GetElement_mD2CEA492181B39DBD061F31EC3879FF458CD8E4D (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Models.UserRoom::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UserRoom__ctor_m3E7FC1E25A29BBC8B65D0404A85D40F8A29023EE (UserRoom_t4A96B7A9523274CA1C6722C4E90D12991C3B11DB* __this, intptr_t ___0_o, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<Pico.Platform.Models.UserRoom>::Add(T)
inline void List_1_Add_mA524A94B70C813C1BA791AF84F038FC221A00FC8_inline (List_1_t68B676CB2F1554E5228FD7A20B97B490395C7E2C* __this, UserRoom_t4A96B7A9523274CA1C6722C4E90D12991C3B11DB* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t68B676CB2F1554E5228FD7A20B97B490395C7E2C*, UserRoom_t4A96B7A9523274CA1C6722C4E90D12991C3B11DB*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.String Pico.Platform.CLIB::ppf_UserAndRoomArray_GetNextPageParam(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_UserAndRoomArray_GetNextPageParam_mA2D3FE47D469C868C7F452C0E3E0CA8ED3653510 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.UIntPtr Pico.Platform.CLIB::ppf_PermissionResult_GetAuthorizedPermissionsSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uintptr_t CLIB_ppf_PermissionResult_GetAuthorizedPermissionsSize_m4379AB6D3FB2839EB21C9523AB5F93908E3A7413 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_PermissionResult_GetAuthorizedPermissions(System.IntPtr,System.UIntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_PermissionResult_GetAuthorizedPermissions_mFAA231129FD3E515528A631EE1D69968E581EACB (intptr_t ___0_obj, uintptr_t ___1_index, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_PermissionResult_GetAccessToken(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_PermissionResult_GetAccessToken_mC5F06ECD94631D7386D345B6979FC2F369B8D920 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_PermissionResult_GetUserID(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_PermissionResult_GetUserID_mA1FDD0446E05016439D2010D77C6A8A067948A69 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.String,Pico.Platform.UserRelationType>::.ctor()
inline void Dictionary_2__ctor_m742B839DF18EB8A76B381A28B11F1FAB2FFDC0CC (Dictionary_2_tFFB4984E3277B96D7DD77603CA615351CE58744C* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tFFB4984E3277B96D7DD77603CA615351CE58744C*, const RuntimeMethod*))Dictionary_2__ctor_mE0470880427DED948EF413AD5E9525F41CAF7D1D_gshared)(__this, method);
}
// System.Int32 Pico.Platform.CLIB::ppf_UserRelationResult_GetRelationsSize(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_UserRelationResult_GetRelationsSize_mF8875AAC141FDE96F53DC11824C80F2E1839CC09 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_UserRelationResult_GetRelationsKey(System.IntPtr,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_UserRelationResult_GetRelationsKey_mB73EF1DCBFF1C89887585243DF714E3FA5754125 (intptr_t ___0_obj, int32_t ___1_index, const RuntimeMethod* method) ;
// Pico.Platform.UserRelationType Pico.Platform.CLIB::ppf_UserRelationResult_GetRelationsValue(System.IntPtr,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_UserRelationResult_GetRelationsValue_m0A26F5C1B9E1C97580698AF2E7AD3B613DEB8850 (intptr_t ___0_obj, int32_t ___1_index, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.String,Pico.Platform.UserRelationType>::Add(TKey,TValue)
inline void Dictionary_2_Add_m4A0CF999D0DF4986DF249FD0DB95889F2FD423A9 (Dictionary_2_tFFB4984E3277B96D7DD77603CA615351CE58744C* __this, String_t* ___0_key, int32_t ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tFFB4984E3277B96D7DD77603CA615351CE58744C*, String_t*, int32_t, const RuntimeMethod*))Dictionary_2_Add_m53A4E919CB3AE7CC74379031E14C1AEA9DB7A933_gshared)(__this, ___0_key, ___1_value, method);
}
// System.Boolean Pico.Platform.CLIB::ppf_EntitlementCheckResult_GetHasEntitlement(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CLIB_ppf_EntitlementCheckResult_GetHasEntitlement_mE806526F233A0C0C2E5C19CF2B79FBF63A3C8F18 (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Int32 Pico.Platform.CLIB::ppf_EntitlementCheckResult_GetStatusCode(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CLIB_ppf_EntitlementCheckResult_GetStatusCode_m6FC69C3765542D93B42BC88E313E868EBDD49D7B (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.String Pico.Platform.CLIB::ppf_EntitlementCheckResult_GetStatusMessage(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CLIB_ppf_EntitlementCheckResult_GetStatusMessage_m83B8F941AE4DF09661F8BC0EED9AD8FD1F09E4BF (intptr_t ___0_obj, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Samples.SimpleDemo::Log(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SimpleDemo_Log_m62FA177CD0CF6D603ED9007ECB86EB58799159F0 (SimpleDemo_tB73BB92662E2E45C09FAD8C176DC8690E0FD4195* __this, String_t* ___0_s, const RuntimeMethod* method) ;
// Pico.Platform.Task`1<Pico.Platform.PlatformInitializeResult> Pico.Platform.CoreService::AsyncInitialize(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_t733E89BDEF2E1BD0B822AE037A0F380656723ACE* CoreService_AsyncInitialize_m8A638C8765E79B40AA6320F400C97845B73DDD39 (String_t* ___0_appId, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Message`1/Handler<Pico.Platform.PlatformInitializeResult>::.ctor(System.Object,System.IntPtr)
inline void Handler__ctor_m10B31F3C417FE2E85931E31619351B7403FFA7DA (Handler_t514BEA54A8C9B5734E3D678B336DDA196A366022* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Handler_t514BEA54A8C9B5734E3D678B336DDA196A366022*, RuntimeObject*, intptr_t, const RuntimeMethod*))Handler__ctor_m4756AACB8B3E1F08083F2079268FC131592BD9A2_gshared)(__this, ___0_object, ___1_method, method);
}
// Pico.Platform.Task`1<T> Pico.Platform.Task`1<Pico.Platform.PlatformInitializeResult>::OnComplete(Pico.Platform.Message`1/Handler<T>)
inline Task_1_t733E89BDEF2E1BD0B822AE037A0F380656723ACE* Task_1_OnComplete_m35202096110B84EDEDE3B5E67432C170C35F885B (Task_1_t733E89BDEF2E1BD0B822AE037A0F380656723ACE* __this, Handler_t514BEA54A8C9B5734E3D678B336DDA196A366022* ___0_handler, const RuntimeMethod* method)
{
	return ((  Task_1_t733E89BDEF2E1BD0B822AE037A0F380656723ACE* (*) (Task_1_t733E89BDEF2E1BD0B822AE037A0F380656723ACE*, Handler_t514BEA54A8C9B5734E3D678B336DDA196A366022*, const RuntimeMethod*))Task_1_OnComplete_mD66F6B1B8E2031658AD47304B96F5375209226A1_gshared)(__this, ___0_handler, method);
}
// System.Void Pico.Platform.CoreService::Initialize(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CoreService_Initialize_m188D60D285D9A378B766140AF97D433B09073039 (String_t* ___0_appId, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Samples.SimpleDemo::EnterDemo()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SimpleDemo_EnterDemo_mC8D76400FCF45640B119D265459272BCF763B723 (SimpleDemo_tB73BB92662E2E45C09FAD8C176DC8690E0FD4195* __this, const RuntimeMethod* method) ;
// Pico.Platform.Task`1<Pico.Platform.Models.PermissionResult> Pico.Platform.UserService::RequestUserPermissions(System.String[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF* UserService_RequestUserPermissions_mFEF7C7A702416B8F5EB7F6543B33A327836C46CF (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___0_permissionList, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Message`1/Handler<Pico.Platform.Models.PermissionResult>::.ctor(System.Object,System.IntPtr)
inline void Handler__ctor_m3A431787B4BF4D615DD543208A4A6FDF86C84855 (Handler_tF65149A494CDA59437FE06A5E974BDECEB45C2B3* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Handler_tF65149A494CDA59437FE06A5E974BDECEB45C2B3*, RuntimeObject*, intptr_t, const RuntimeMethod*))Handler__ctor_mF22E9A275A92F5E87F8FC119ADB9AB74849705F6_gshared)(__this, ___0_object, ___1_method, method);
}
// Pico.Platform.Task`1<T> Pico.Platform.Task`1<Pico.Platform.Models.PermissionResult>::OnComplete(Pico.Platform.Message`1/Handler<T>)
inline Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF* Task_1_OnComplete_m320B333161C5C0070440A132234F801A7BC74020 (Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF* __this, Handler_tF65149A494CDA59437FE06A5E974BDECEB45C2B3* ___0_handler, const RuntimeMethod* method)
{
	return ((  Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF* (*) (Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF*, Handler_tF65149A494CDA59437FE06A5E974BDECEB45C2B3*, const RuntimeMethod*))Task_1_OnComplete_m84874DB788370D7C4112AC71C6E46A4E9EBC9827_gshared)(__this, ___0_handler, method);
}
// Pico.Platform.Task`1<Pico.Platform.Models.User> Pico.Platform.UserService::GetLoggedInUser()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42* UserService_GetLoggedInUser_mEF12425F8814F7C5E08382C6C5E00CEE18073E8B (const RuntimeMethod* method) ;
// System.Void Pico.Platform.Message`1/Handler<Pico.Platform.Models.User>::.ctor(System.Object,System.IntPtr)
inline void Handler__ctor_m1E95747E31598AD2B68B9458AB372F09549FDC8D (Handler_t3014C5064A71B62349A0B6C599C034BA36D6E17E* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Handler_t3014C5064A71B62349A0B6C599C034BA36D6E17E*, RuntimeObject*, intptr_t, const RuntimeMethod*))Handler__ctor_mF22E9A275A92F5E87F8FC119ADB9AB74849705F6_gshared)(__this, ___0_object, ___1_method, method);
}
// Pico.Platform.Task`1<T> Pico.Platform.Task`1<Pico.Platform.Models.User>::OnComplete(Pico.Platform.Message`1/Handler<T>)
inline Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42* Task_1_OnComplete_m7241FFC878E940C536582E977114C52EDFE412BE (Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42* __this, Handler_t3014C5064A71B62349A0B6C599C034BA36D6E17E* ___0_handler, const RuntimeMethod* method)
{
	return ((  Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42* (*) (Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42*, Handler_t3014C5064A71B62349A0B6C599C034BA36D6E17E*, const RuntimeMethod*))Task_1_OnComplete_m84874DB788370D7C4112AC71C6E46A4E9EBC9827_gshared)(__this, ___0_handler, method);
}
// System.Void Pico.Platform.Samples.SimpleDemo/<DownloadImage>d__7::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CDownloadImageU3Ed__7__ctor_mD97A09CDDEC301DE3704B12E5D3412B449DF0697 (U3CDownloadImageU3Ed__7_t12CD4C58AE44E71AC9B06FF3969E6AD7057D8367* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) ;
// System.Void UnityEngine.Debug::Log(System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Debug_Log_m87A9A3C761FF5C43ED8A53B16190A53D08F818BB (RuntimeObject* ___0_message, const RuntimeMethod* method) ;
// System.Boolean Pico.Platform.Message::get_IsError()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Message_get_IsError_m0D80E2415924AE94A030FB3CF345FFB48FE480F9 (Message_t2DF6F94E79BCFC7D36B4D1219F09D5DF8D241F83* __this, const RuntimeMethod* method) ;
// Pico.Platform.Models.Error Pico.Platform.Message::GetError()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Error_t3CA63648FA025A8FBA63EA102526BE2F757CAF88* Message_GetError_mF2A3F96565CB80619FBD1DFE8E7C9FB1A0BA5A99_inline (Message_t2DF6F94E79BCFC7D36B4D1219F09D5DF8D241F83* __this, const RuntimeMethod* method) ;
// System.String System.String::Join(System.String,System.String[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Join_m557B6B554B87C1742FA0B128500073B421ED0BFD (String_t* ___0_separator, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___1_value, const RuntimeMethod* method) ;
// System.String System.String::Concat(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m9E3155FB84015C823606188F53B47CB44C444991 (String_t* ___0_str0, String_t* ___1_str1, const RuntimeMethod* method) ;
// System.Void Pico.Platform.Samples.SimpleDemo::getUser()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SimpleDemo_getUser_m35B04756C5973CB7C1F3F6F98DF3C4F37FB88F56 (SimpleDemo_tB73BB92662E2E45C09FAD8C176DC8690E0FD4195* __this, const RuntimeMethod* method) ;
// System.Collections.IEnumerator Pico.Platform.Samples.SimpleDemo::DownloadImage(System.String,UnityEngine.UI.RawImage)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* SimpleDemo_DownloadImage_m5AD82188A53C0A2A70C567A27C366282FCB09E94 (SimpleDemo_tB73BB92662E2E45C09FAD8C176DC8690E0FD4195* __this, String_t* ___0_mediaUrl, RawImage_tFF12F7DB574FBDC1863CF607C7A12A5D9F8D6179* ___1_rawImage, const RuntimeMethod* method) ;
// UnityEngine.Coroutine UnityEngine.MonoBehaviour::StartCoroutine(System.Collections.IEnumerator)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* MonoBehaviour_StartCoroutine_m4CAFF732AA28CD3BDC5363B44A863575530EC812 (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, RuntimeObject* ___0_routine, const RuntimeMethod* method) ;
// System.String System.String::Concat(System.String,System.String,System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m093934F71A9B351911EE46311674ED463B180006 (String_t* ___0_str0, String_t* ___1_str1, String_t* ___2_str2, String_t* ___3_str3, const RuntimeMethod* method) ;
// UnityEngine.Networking.UnityWebRequest UnityEngine.Networking.UnityWebRequestTexture::GetTexture(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnityWebRequest_t6233B8E22992FC2364A831C1ACB033EF3260C39F* UnityWebRequestTexture_GetTexture_mEEC74BBC5190D4012A0B87C5D439AF59E22EF2EF (String_t* ___0_uri, const RuntimeMethod* method) ;
// UnityEngine.Networking.UnityWebRequestAsyncOperation UnityEngine.Networking.UnityWebRequest::SendWebRequest()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnityWebRequestAsyncOperation_t14BE94558FF3A2CFC2EFBE2511A3A88252042B8C* UnityWebRequest_SendWebRequest_mA3CD13983BAA5074A0640EDD661B1E46E6DB6C13 (UnityWebRequest_t6233B8E22992FC2364A831C1ACB033EF3260C39F* __this, const RuntimeMethod* method) ;
// System.Int64 UnityEngine.Networking.UnityWebRequest::get_responseCode()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t UnityWebRequest_get_responseCode_m012C177F61435D5D120A21D7A03FFF7B0F8B904B (UnityWebRequest_t6233B8E22992FC2364A831C1ACB033EF3260C39F* __this, const RuntimeMethod* method) ;
// UnityEngine.Networking.DownloadHandler UnityEngine.Networking.UnityWebRequest::get_downloadHandler()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DownloadHandler_t1B56C7D3F65D97A1E4B566A14A1E783EA8AE4EBB* UnityWebRequest_get_downloadHandler_m1AA91B23D9D594A4F4FE2975FC356C508528F1D5 (UnityWebRequest_t6233B8E22992FC2364A831C1ACB033EF3260C39F* __this, const RuntimeMethod* method) ;
// UnityEngine.Texture2D UnityEngine.Networking.DownloadHandlerTexture::get_texture()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* DownloadHandlerTexture_get_texture_m170B5539995EB5984E98E426F52983589F7BEB7C (DownloadHandlerTexture_t45E2D719000AA1594E648810F0B57A77FA7C568C* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.UI.RawImage::set_texture(UnityEngine.Texture)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RawImage_set_texture_mC016318C95CC17A826D57DD219DBCB6DFD295C02 (RawImage_tFF12F7DB574FBDC1863CF607C7A12A5D9F8D6179* __this, Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___0_value, const RuntimeMethod* method) ;
// T UnityEngine.Component::GetComponent<UnityEngine.Renderer>()
inline Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* Component_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_mC91ACC92AD57CA6CA00991DAF1DB3830BCE07AF8 (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method)
{
	return ((  Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* (*) (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3*, const RuntimeMethod*))Component_GetComponent_TisRuntimeObject_m7181F81CAEC2CF53F5D2BC79B7425C16E1F80D33_gshared)(__this, method);
}
// UnityEngine.Material UnityEngine.Renderer::get_material()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* Renderer_get_material_m5BA2A00816C4CC66580D4B2E409CF10718C15656 (Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.Material::set_mainTexture(UnityEngine.Texture)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Material_set_mainTexture_m389E048BA9C81B603EBF36BD792212B296317AC0 (Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* __this, Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___0_value, const RuntimeMethod* method) ;
// System.Void System.NotSupportedException::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NotSupportedException__ctor_m1398D0CDE19B36AA3DE9392879738C1EA2439CDF (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* __this, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void Pico.Platform.RoomOptions::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RoomOptions__ctor_m575ABE0CB642F3A565A1B46995AFD5C7BFF17220 (RoomOptions_tC6C155D94F2675BA84336CA56BCDEBEA022835B7* __this, const RuntimeMethod* method) 
{
	{
		// public RoomOptions()
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Handle = CLIB.ppf_RoomOptions_Create();
		intptr_t L_0;
		L_0 = CLIB_ppf_RoomOptions_Create_m6ECBE2AC605C2102BC18A9BBC5D696E3F0AEBC6B(NULL);
		__this->___Handle_0 = L_0;
		// }
		return;
	}
}
// System.Void Pico.Platform.RoomOptions::SetDataStore(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RoomOptions_SetDataStore_mD2918B7E5F7682EF389E24BC7E86620FC2B5ED92 (RoomOptions_tC6C155D94F2675BA84336CA56BCDEBEA022835B7* __this, String_t* ___0_key, String_t* ___1_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_RoomOptions_SetDataStoreString(Handle, key, value);
		intptr_t L_0 = __this->___Handle_0;
		String_t* L_1 = ___0_key;
		String_t* L_2 = ___1_value;
		CLIB_ppf_RoomOptions_SetDataStoreString_mF4AAB5DAC9E0AEFDD29CA454D9E3CAD2939D7094(L_0, L_1, L_2, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RoomOptions::ClearDataStore()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RoomOptions_ClearDataStore_m4DFF7CE299148685166C8660FF9357EF579076B1 (RoomOptions_tC6C155D94F2675BA84336CA56BCDEBEA022835B7* __this, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_RoomOptions_ClearDataStore(Handle);
		intptr_t L_0 = __this->___Handle_0;
		CLIB_ppf_RoomOptions_ClearDataStore_m08E7EFA13A1700BA8B953C5C4D69ED2AE6B6B1DB(L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RoomOptions::SetExcludeRecentlyMet(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RoomOptions_SetExcludeRecentlyMet_mB3DDFB65BE9AED1C730A3FEE915EFCB181FA57C8 (RoomOptions_tC6C155D94F2675BA84336CA56BCDEBEA022835B7* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_RoomOptions_SetExcludeRecentlyMet(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		bool L_1 = ___0_value;
		CLIB_ppf_RoomOptions_SetExcludeRecentlyMet_mD1B8195171FDACE7B7D21376FBBE02CEB23AD964(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RoomOptions::SetMaxUserResults(System.UInt32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RoomOptions_SetMaxUserResults_mCBA16A9D5EADBC6A22B1355A61130EF4CEFDE671 (RoomOptions_tC6C155D94F2675BA84336CA56BCDEBEA022835B7* __this, uint32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_RoomOptions_SetMaxUserResults(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		uint32_t L_1 = ___0_value;
		CLIB_ppf_RoomOptions_SetMaxUserResults_m7CB686A444F6BF00424635009E098E6114E736F0(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RoomOptions::SetRoomId(System.UInt64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RoomOptions_SetRoomId_mD9315F94A1A36C694D8BBAC408072C884B9CFED9 (RoomOptions_tC6C155D94F2675BA84336CA56BCDEBEA022835B7* __this, uint64_t ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_RoomOptions_SetRoomId(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		uint64_t L_1 = ___0_value;
		CLIB_ppf_RoomOptions_SetRoomId_mF64B0F142484998CB3DB49BACAB7A19F8B6B9655(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RoomOptions::SetRoomName(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RoomOptions_SetRoomName_mF13CD35EE1D61715C2FB02A9F7CD983D70490D85 (RoomOptions_tC6C155D94F2675BA84336CA56BCDEBEA022835B7* __this, String_t* ___0_roomName, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_RoomOptions_SetName(Handle, roomName);
		intptr_t L_0 = __this->___Handle_0;
		String_t* L_1 = ___0_roomName;
		CLIB_ppf_RoomOptions_SetName_mACE0C9CF32D1F4D89B6B0B195969DA4B082A265E(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RoomOptions::SetPassword(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RoomOptions_SetPassword_m5323FCDBC642B3161C3B5C58090D0F041F4C19F4 (RoomOptions_tC6C155D94F2675BA84336CA56BCDEBEA022835B7* __this, String_t* ___0_password, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_RoomOptions_SetPassword(Handle, password);
		intptr_t L_0 = __this->___Handle_0;
		String_t* L_1 = ___0_password;
		CLIB_ppf_RoomOptions_SetPassword_m744B749EA6C835A66E42A5940C550CA022944AE3(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RoomOptions::SetTurnOffUpdates(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RoomOptions_SetTurnOffUpdates_mFFC7DCEA750AFE137BB9AF5865A0023E107F93A1 (RoomOptions_tC6C155D94F2675BA84336CA56BCDEBEA022835B7* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_RoomOptions_SetTurnOffUpdates(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		bool L_1 = ___0_value;
		CLIB_ppf_RoomOptions_SetTurnOffUpdates_m7CB0F5C3189BC1A4A3C0D34DBC15DDEF541C0E9A(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.IntPtr Pico.Platform.RoomOptions::op_Explicit(Pico.Platform.RoomOptions)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t RoomOptions_op_Explicit_m160FF5FE60C41FDD18D2CB346EED21F1F3E3CC78 (RoomOptions_tC6C155D94F2675BA84336CA56BCDEBEA022835B7* ___0_roomOptions, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// return roomOptions != null ? roomOptions.Handle : IntPtr.Zero;
		RoomOptions_tC6C155D94F2675BA84336CA56BCDEBEA022835B7* L_0 = ___0_roomOptions;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		intptr_t L_1 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		return L_1;
	}

IL_0009:
	{
		RoomOptions_tC6C155D94F2675BA84336CA56BCDEBEA022835B7* L_2 = ___0_roomOptions;
		NullCheck(L_2);
		intptr_t L_3 = L_2->___Handle_0;
		return L_3;
	}
}
// System.Void Pico.Platform.RoomOptions::Finalize()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RoomOptions_Finalize_m999EEE1957A19E1D7B7270C18524B1B367400CED (RoomOptions_tC6C155D94F2675BA84336CA56BCDEBEA022835B7* __this, const RuntimeMethod* method) 
{
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_000d:
			{// begin finally (depth: 1)
				// }
				Object_Finalize_mC98C96301CCABFE00F1A7EF8E15DF507CACD42B2(__this, NULL);
				return;
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			// CLIB.ppf_RoomOptions_Destroy(Handle);
			intptr_t L_0 = __this->___Handle_0;
			CLIB_ppf_RoomOptions_Destroy_m0336694A1A622F8383DA0D257FFC107BA620E804(L_0, NULL);
			goto IL_0014;
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0014:
	{
		// }
		return;
	}
}
// System.IntPtr Pico.Platform.RoomOptions::GetHandle()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t RoomOptions_GetHandle_m0C9DCC01EC26AC5586AC037C2FC3A8A8C389F247 (RoomOptions_tC6C155D94F2675BA84336CA56BCDEBEA022835B7* __this, const RuntimeMethod* method) 
{
	{
		// return Handle;
		intptr_t L_0 = __this->___Handle_0;
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
extern "C" int32_t CDECL ReversePInvokeWrapper_RtcService_InnerAudioProcessor_m663C1AC6BC552D87E0EF075932933D89EA182C22(intptr_t ___0_ptr)
{
	il2cpp::vm::ScopedThreadAttacher _vmThreadHelper;

	// Managed method invocation
	int32_t returnValue;
	returnValue = RtcService_InnerAudioProcessor_m663C1AC6BC552D87E0EF075932933D89EA182C22(___0_ptr, NULL);

	return returnValue;
}
// Pico.Platform.RtcEngineInitResult Pico.Platform.RtcService::InitRtcEngine()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RtcService_InitRtcEngine_m8CFD3447FE5884ADA7E671B54C3474DE6492E5FC (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral6D2C56060B3F7353031AD314517C27945CC39748);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (Application.platform == RuntimePlatform.Android && !Permission.HasUserAuthorizedPermission(Permission.Microphone))
		int32_t L_0;
		L_0 = Application_get_platform_m59EF7D6155D18891B24767F83F388160B1FF2138(NULL);
		if ((!(((uint32_t)L_0) == ((uint32_t)((int32_t)11)))))
		{
			goto IL_001f;
		}
	}
	{
		bool L_1;
		L_1 = Permission_HasUserAuthorizedPermission_mF4C90E13124E28F6F672200E489CC25A9B645B8B(_stringLiteral6D2C56060B3F7353031AD314517C27945CC39748, NULL);
		if (L_1)
		{
			goto IL_001f;
		}
	}
	{
		// Permission.RequestUserPermission(Permission.Microphone);
		Permission_RequestUserPermission_mF9CF3A21AAF34B311137C4D00B3AD6A6C2694242(_stringLiteral6D2C56060B3F7353031AD314517C27945CC39748, NULL);
	}

IL_001f:
	{
		// return CLIB.ppf_Rtc_InitRtcEngine();
		int32_t L_2;
		L_2 = CLIB_ppf_Rtc_InitRtcEngine_m20BB8DD19DDA0DE689AED5FDFCC401E17A2B0DFF(NULL);
		return L_2;
	}
}
// Pico.Platform.Task`1<System.String> Pico.Platform.RtcService::GetToken(System.String,System.String,System.Int32,System.Collections.Generic.Dictionary`2<Pico.Platform.RtcPrivilege,System.Int32>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF* RtcService_GetToken_m228DA2D75D8BE8DA4496774D60FD83E05C575A0A (String_t* ___0_roomId, String_t* ___1_userId, int32_t ___2_ttl, Dictionary_2_tFA4E3C6BBA632C5BEEBB77A03650502241C2D607* ___3_privileges, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_GetEnumerator_mD22822F067AD3D9BCA373A0546FE8615909B0FEC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_Dispose_m9ED4E52C26F04192D41980F154879E9D585E9791_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_MoveNext_m424B03CFB200058B8CE11047A5D7B6C0EEF5BE36_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_get_Current_mDE9C73F49F1A0AACB90F99DEB8FDC16508F49543_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&KeyValuePair_2_get_Key_m371FAFC80DB00656F29F2E3A607A15D8F1A4D9A2_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&KeyValuePair_2_get_Value_m4E42B1A68B9D4E0CD522118A7CE586CC714A92B6_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1__ctor_m1CF0C62EAAB2FD4823E55B281F816BE4AD7A46DC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* V_0 = NULL;
	Enumerator_tA829CFCA6EB6821F225A3ADB1DFE03AC172EBA69 V_1;
	memset((&V_1), 0, sizeof(V_1));
	KeyValuePair_2_t3B924E448F08153464BEA8D03A541C9BC936424A V_2;
	memset((&V_2), 0, sizeof(V_2));
	{
		// if (!CoreService.Initialized)
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		bool L_0 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___Initialized_0;
		if (L_0)
		{
			goto IL_0013;
		}
	}
	{
		// Debug.LogError(CoreService.NotInitializedError);
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		String_t* L_1 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___NotInitializedError_1;
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_1, NULL);
		// return null;
		return (Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF*)NULL;
	}

IL_0013:
	{
		// var tokenOption = new RtcGetTokenOptions();
		RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* L_2 = (RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0*)il2cpp_codegen_object_new(RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		RtcGetTokenOptions__ctor_mCA91FB23D9E95538924CA5A36D7A0060A0DA1F12(L_2, NULL);
		V_0 = L_2;
		// tokenOption.SetRoomId(roomId);
		RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* L_3 = V_0;
		String_t* L_4 = ___0_roomId;
		NullCheck(L_3);
		RtcGetTokenOptions_SetRoomId_mEC2981B140C843025675715E718FA4BBBCAF5465(L_3, L_4, NULL);
		// tokenOption.SetUserId(userId);
		RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* L_5 = V_0;
		String_t* L_6 = ___1_userId;
		NullCheck(L_5);
		RtcGetTokenOptions_SetUserId_mAC8EC85CB4D28EE5124B3DF53DCB4DA5AB3D8A74(L_5, L_6, NULL);
		// tokenOption.SetTtl(ttl);
		RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* L_7 = V_0;
		int32_t L_8 = ___2_ttl;
		NullCheck(L_7);
		RtcGetTokenOptions_SetTtl_m4EBA04258BF46009456989FA5C35B0C5E3CA85C0(L_7, L_8, NULL);
		// if (privileges != null)
		Dictionary_2_tFA4E3C6BBA632C5BEEBB77A03650502241C2D607* L_9 = ___3_privileges;
		if (!L_9)
		{
			goto IL_006f;
		}
	}
	{
		// foreach (var i in privileges)
		Dictionary_2_tFA4E3C6BBA632C5BEEBB77A03650502241C2D607* L_10 = ___3_privileges;
		NullCheck(L_10);
		Enumerator_tA829CFCA6EB6821F225A3ADB1DFE03AC172EBA69 L_11;
		L_11 = Dictionary_2_GetEnumerator_mD22822F067AD3D9BCA373A0546FE8615909B0FEC(L_10, Dictionary_2_GetEnumerator_mD22822F067AD3D9BCA373A0546FE8615909B0FEC_RuntimeMethod_var);
		V_1 = L_11;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0061:
			{// begin finally (depth: 1)
				Enumerator_Dispose_m9ED4E52C26F04192D41980F154879E9D585E9791((&V_1), Enumerator_Dispose_m9ED4E52C26F04192D41980F154879E9D585E9791_RuntimeMethod_var);
				return;
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			{
				goto IL_0056_1;
			}

IL_003a_1:
			{
				// foreach (var i in privileges)
				KeyValuePair_2_t3B924E448F08153464BEA8D03A541C9BC936424A L_12;
				L_12 = Enumerator_get_Current_mDE9C73F49F1A0AACB90F99DEB8FDC16508F49543_inline((&V_1), Enumerator_get_Current_mDE9C73F49F1A0AACB90F99DEB8FDC16508F49543_RuntimeMethod_var);
				V_2 = L_12;
				// tokenOption.SetPrivileges(i.Key, i.Value);
				RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* L_13 = V_0;
				int32_t L_14;
				L_14 = KeyValuePair_2_get_Key_m371FAFC80DB00656F29F2E3A607A15D8F1A4D9A2_inline((&V_2), KeyValuePair_2_get_Key_m371FAFC80DB00656F29F2E3A607A15D8F1A4D9A2_RuntimeMethod_var);
				int32_t L_15;
				L_15 = KeyValuePair_2_get_Value_m4E42B1A68B9D4E0CD522118A7CE586CC714A92B6_inline((&V_2), KeyValuePair_2_get_Value_m4E42B1A68B9D4E0CD522118A7CE586CC714A92B6_RuntimeMethod_var);
				NullCheck(L_13);
				RtcGetTokenOptions_SetPrivileges_m9BA7C7F94C4C7701F1AAF6B8AE73772F589D6F2B(L_13, L_14, L_15, NULL);
			}

IL_0056_1:
			{
				// foreach (var i in privileges)
				bool L_16;
				L_16 = Enumerator_MoveNext_m424B03CFB200058B8CE11047A5D7B6C0EEF5BE36((&V_1), Enumerator_MoveNext_m424B03CFB200058B8CE11047A5D7B6C0EEF5BE36_RuntimeMethod_var);
				if (L_16)
				{
					goto IL_003a_1;
				}
			}
			{
				goto IL_006f;
			}
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_006f:
	{
		// return new Task<string>(CLIB.ppf_Rtc_GetToken((IntPtr) tokenOption));
		RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* L_17 = V_0;
		intptr_t L_18;
		L_18 = RtcGetTokenOptions_op_Explicit_m6C383C66020E9B97450516BA56A4804EE11AF49E(L_17, NULL);
		uint64_t L_19;
		L_19 = CLIB_ppf_Rtc_GetToken_m8F52B9679DC5BF49DC30C44678011848F161673A(L_18, NULL);
		Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF* L_20 = (Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF*)il2cpp_codegen_object_new(Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF_il2cpp_TypeInfo_var);
		NullCheck(L_20);
		Task_1__ctor_m1CF0C62EAAB2FD4823E55B281F816BE4AD7A46DC(L_20, L_19, Task_1__ctor_m1CF0C62EAAB2FD4823E55B281F816BE4AD7A46DC_RuntimeMethod_var);
		return L_20;
	}
}
// System.Int32 Pico.Platform.RtcService::JoinRoom(System.String,System.String,System.String,Pico.Platform.RtcRoomProfileType,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RtcService_JoinRoom_m3782263B9253042E21F4A5AF8605338E63532B79 (String_t* ___0_roomId, String_t* ___1_userId, String_t* ___2_token, int32_t ___3_roomProfileType, bool ___4_isAutoSubscribeAudio, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// var roomOption = new RtcRoomOptions();
		RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* L_0 = (RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A*)il2cpp_codegen_object_new(RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		RtcRoomOptions__ctor_m753D1C11608C22036A76D99B3C862D89B347E274(L_0, NULL);
		// roomOption.SetRoomId(roomId);
		RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* L_1 = L_0;
		String_t* L_2 = ___0_roomId;
		NullCheck(L_1);
		RtcRoomOptions_SetRoomId_m1EC97F209EAB97E51EF3EEAFD8C6D62B6CAD2ED6(L_1, L_2, NULL);
		// roomOption.SetUserId(userId);
		RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* L_3 = L_1;
		String_t* L_4 = ___1_userId;
		NullCheck(L_3);
		RtcRoomOptions_SetUserId_m33FD3B38340AF5C0F0A57BFB514C5DA81BFE10BC(L_3, L_4, NULL);
		// roomOption.SetToken(token);
		RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* L_5 = L_3;
		String_t* L_6 = ___2_token;
		NullCheck(L_5);
		RtcRoomOptions_SetToken_mE7CAA2DC3B2B75013EDE6C974339572E0CEC7CC0(L_5, L_6, NULL);
		// roomOption.SetRoomProfileType(roomProfileType);
		RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* L_7 = L_5;
		int32_t L_8 = ___3_roomProfileType;
		NullCheck(L_7);
		RtcRoomOptions_SetRoomProfileType_m45350524D2610FA5CD5C4D5723EEA2A2FCF5E0F2(L_7, L_8, NULL);
		// roomOption.SetIsAutoSubscribeAudio(isAutoSubscribeAudio);
		RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* L_9 = L_7;
		bool L_10 = ___4_isAutoSubscribeAudio;
		NullCheck(L_9);
		RtcRoomOptions_SetIsAutoSubscribeAudio_m0A6C2D07889202383FE2627313F63E081CA25531(L_9, L_10, NULL);
		// return CLIB.ppf_Rtc_JoinRoom((IntPtr) roomOption);
		intptr_t L_11;
		L_11 = RtcRoomOptions_op_Explicit_mF71D4601FAFEA41A4EA24DBF479115F06149B7CB(L_9, NULL);
		int32_t L_12;
		L_12 = CLIB_ppf_Rtc_JoinRoom_m4E5EC93A0D7A396D28CA13001EF6E6E5A49CF0B2(L_11, NULL);
		return L_12;
	}
}
// System.Int32 Pico.Platform.RtcService::JoinRoom2(Pico.Platform.RtcRoomOptions,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RtcService_JoinRoom2_m216395D3F7BD023C56D707C947FF624FAADC4984 (RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* ___0_joinRoomOptions, bool ___1_leaveIfInRoom, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		// var res = CLIB.ppf_Rtc_JoinRoom((IntPtr) joinRoomOptions);
		RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* L_0 = ___0_joinRoomOptions;
		intptr_t L_1;
		L_1 = RtcRoomOptions_op_Explicit_mF71D4601FAFEA41A4EA24DBF479115F06149B7CB(L_0, NULL);
		int32_t L_2;
		L_2 = CLIB_ppf_Rtc_JoinRoom_m4E5EC93A0D7A396D28CA13001EF6E6E5A49CF0B2(L_1, NULL);
		V_0 = L_2;
		// if (leaveIfInRoom && res == -2)
		bool L_3 = ___1_leaveIfInRoom;
		if (!L_3)
		{
			goto IL_002c;
		}
	}
	{
		int32_t L_4 = V_0;
		if ((!(((uint32_t)L_4) == ((uint32_t)((int32_t)-2)))))
		{
			goto IL_002c;
		}
	}
	{
		// LeaveRoom(joinRoomOptions.RoomId);
		RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* L_5 = ___0_joinRoomOptions;
		NullCheck(L_5);
		String_t* L_6 = L_5->___RoomId_0;
		int32_t L_7;
		L_7 = RtcService_LeaveRoom_m24F28302428DEE9794E878DBA9C441164D93269E(L_6, NULL);
		// res = CLIB.ppf_Rtc_JoinRoom((IntPtr) joinRoomOptions);
		RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* L_8 = ___0_joinRoomOptions;
		intptr_t L_9;
		L_9 = RtcRoomOptions_op_Explicit_mF71D4601FAFEA41A4EA24DBF479115F06149B7CB(L_8, NULL);
		int32_t L_10;
		L_10 = CLIB_ppf_Rtc_JoinRoom_m4E5EC93A0D7A396D28CA13001EF6E6E5A49CF0B2(L_9, NULL);
		V_0 = L_10;
	}

IL_002c:
	{
		// return res;
		int32_t L_11 = V_0;
		return L_11;
	}
}
// System.Int32 Pico.Platform.RtcService::JoinRoomWithRetry(System.String,System.String,System.String,Pico.Platform.RtcRoomProfileType,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RtcService_JoinRoomWithRetry_m8CE086D7FBD84EE07092E134826E2E56A2DCB77D (String_t* ___0_roomId, String_t* ___1_userId, String_t* ___2_token, int32_t ___3_roomProfileType, bool ___4_isAutoSubscribeAudio, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* V_0 = NULL;
	int32_t V_1 = 0;
	{
		// var roomOption = new RtcRoomOptions();
		RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* L_0 = (RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A*)il2cpp_codegen_object_new(RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		RtcRoomOptions__ctor_m753D1C11608C22036A76D99B3C862D89B347E274(L_0, NULL);
		V_0 = L_0;
		// roomOption.SetRoomId(roomId);
		RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* L_1 = V_0;
		String_t* L_2 = ___0_roomId;
		NullCheck(L_1);
		RtcRoomOptions_SetRoomId_m1EC97F209EAB97E51EF3EEAFD8C6D62B6CAD2ED6(L_1, L_2, NULL);
		// roomOption.SetUserId(userId);
		RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* L_3 = V_0;
		String_t* L_4 = ___1_userId;
		NullCheck(L_3);
		RtcRoomOptions_SetUserId_m33FD3B38340AF5C0F0A57BFB514C5DA81BFE10BC(L_3, L_4, NULL);
		// roomOption.SetToken(token);
		RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* L_5 = V_0;
		String_t* L_6 = ___2_token;
		NullCheck(L_5);
		RtcRoomOptions_SetToken_mE7CAA2DC3B2B75013EDE6C974339572E0CEC7CC0(L_5, L_6, NULL);
		// roomOption.SetRoomProfileType(roomProfileType);
		RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* L_7 = V_0;
		int32_t L_8 = ___3_roomProfileType;
		NullCheck(L_7);
		RtcRoomOptions_SetRoomProfileType_m45350524D2610FA5CD5C4D5723EEA2A2FCF5E0F2(L_7, L_8, NULL);
		// roomOption.SetIsAutoSubscribeAudio(isAutoSubscribeAudio);
		RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* L_9 = V_0;
		bool L_10 = ___4_isAutoSubscribeAudio;
		NullCheck(L_9);
		RtcRoomOptions_SetIsAutoSubscribeAudio_m0A6C2D07889202383FE2627313F63E081CA25531(L_9, L_10, NULL);
		// var res = CLIB.ppf_Rtc_JoinRoom((IntPtr) roomOption);
		RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* L_11 = V_0;
		intptr_t L_12;
		L_12 = RtcRoomOptions_op_Explicit_mF71D4601FAFEA41A4EA24DBF479115F06149B7CB(L_11, NULL);
		int32_t L_13;
		L_13 = CLIB_ppf_Rtc_JoinRoom_m4E5EC93A0D7A396D28CA13001EF6E6E5A49CF0B2(L_12, NULL);
		V_1 = L_13;
		// if (res == -2)
		int32_t L_14 = V_1;
		if ((!(((uint32_t)L_14) == ((uint32_t)((int32_t)-2)))))
		{
			goto IL_004e;
		}
	}
	{
		// LeaveRoom(roomId);
		String_t* L_15 = ___0_roomId;
		int32_t L_16;
		L_16 = RtcService_LeaveRoom_m24F28302428DEE9794E878DBA9C441164D93269E(L_15, NULL);
		// res = CLIB.ppf_Rtc_JoinRoom((IntPtr) roomOption);
		RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* L_17 = V_0;
		intptr_t L_18;
		L_18 = RtcRoomOptions_op_Explicit_mF71D4601FAFEA41A4EA24DBF479115F06149B7CB(L_17, NULL);
		int32_t L_19;
		L_19 = CLIB_ppf_Rtc_JoinRoom_m4E5EC93A0D7A396D28CA13001EF6E6E5A49CF0B2(L_18, NULL);
		V_1 = L_19;
	}

IL_004e:
	{
		// return res;
		int32_t L_20 = V_1;
		return L_20;
	}
}
// System.Int32 Pico.Platform.RtcService::LeaveRoom(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RtcService_LeaveRoom_m24F28302428DEE9794E878DBA9C441164D93269E (String_t* ___0_roomId, const RuntimeMethod* method) 
{
	{
		// return CLIB.ppf_Rtc_LeaveRoom(roomId);
		String_t* L_0 = ___0_roomId;
		int32_t L_1;
		L_1 = CLIB_ppf_Rtc_LeaveRoom_m97EBB2B10B3323F2917A661B3FC3899C778F0092(L_0, NULL);
		return L_1;
	}
}
// System.Void Pico.Platform.RtcService::SetAudioPlaybackDevice(Pico.Platform.RtcAudioPlaybackDevice)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetAudioPlaybackDevice_m16BCB06A9BD80AE60C9181430DCE925E2458ED24 (int32_t ___0_device, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_Rtc_SetAudioPlaybackDevice(device);
		int32_t L_0 = ___0_device;
		CLIB_ppf_Rtc_SetAudioPlaybackDevice_mD1332D4C61830FC5FA37D79D79B7AAE9A4B29444(L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::RoomPauseAllSubscribedStream(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_RoomPauseAllSubscribedStream_mA94FB050D8FC17E8BBDC40153AB89AA22D25662E (String_t* ___0_roomId, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_Rtc_RoomPauseAllSubscribedStream(roomId, RtcPauseResumeMediaType.Audio);
		String_t* L_0 = ___0_roomId;
		CLIB_ppf_Rtc_RoomPauseAllSubscribedStream_m34D0AD40880E89C0C1370213858B61D7D06055E8(L_0, 0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::RoomResumeAllSubscribedStream(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_RoomResumeAllSubscribedStream_m3619DFCD75324DAE2705D69847131F278F5A3EE4 (String_t* ___0_roomId, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_Rtc_RoomResumeAllSubscribedStream(roomId, RtcPauseResumeMediaType.Audio);
		String_t* L_0 = ___0_roomId;
		CLIB_ppf_Rtc_RoomResumeAllSubscribedStream_m8DAEA8FA957F0E6CCC78DCAD0F482BFAECAECFF5(L_0, 0, NULL);
		// }
		return;
	}
}
// System.Int32 Pico.Platform.RtcService::InnerAudioProcessor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RtcService_InnerAudioProcessor_m663C1AC6BC552D87E0EF075932933D89EA182C22 (intptr_t ___0_ptr, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RtcService_t22C275834C979544290EE8B61C467477647BD1BF_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (audioProcessor != null)
		ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5* L_0 = ((RtcService_t22C275834C979544290EE8B61C467477647BD1BF_StaticFields*)il2cpp_codegen_static_fields_for(RtcService_t22C275834C979544290EE8B61C467477647BD1BF_il2cpp_TypeInfo_var))->___audioProcessor_0;
		if (!L_0)
		{
			goto IL_0018;
		}
	}
	{
		// return audioProcessor(new RtcAudioFrame(ptr));
		ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5* L_1 = ((RtcService_t22C275834C979544290EE8B61C467477647BD1BF_StaticFields*)il2cpp_codegen_static_fields_for(RtcService_t22C275834C979544290EE8B61C467477647BD1BF_il2cpp_TypeInfo_var))->___audioProcessor_0;
		intptr_t L_2 = ___0_ptr;
		RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59* L_3 = (RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59*)il2cpp_codegen_object_new(RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		RtcAudioFrame__ctor_mAF8A3A50316BDC0FFFE39C0FCF28E25F185B5E9A(L_3, L_2, NULL);
		NullCheck(L_1);
		int32_t L_4;
		L_4 = ProcessAudioFrameFunction_Invoke_m5EC2CDFD611F5CDC64BD8A36A025E8C08FF061D6_inline(L_1, L_3, NULL);
		return L_4;
	}

IL_0018:
	{
		// return 0;
		return 0;
	}
}
// System.Void Pico.Platform.RtcService::RegisterLocalAudioProcessor(Pico.Platform.RtcService/ProcessAudioFrameFunction,Pico.Platform.RtcAudioChannel,Pico.Platform.RtcAudioSampleRate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_RegisterLocalAudioProcessor_m58CB81757B963E0FC677025F0277A87159AB3D96 (ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5* ___0_processor, int32_t ___1_channel, int32_t ___2_sampleRate, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RtcProcessAudioFrameFunction_t91998EE2CD7760356A3A9E75620AEB591C1F2344_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RtcService_InnerAudioProcessor_m663C1AC6BC552D87E0EF075932933D89EA182C22_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RtcService_t22C275834C979544290EE8B61C467477647BD1BF_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// audioProcessor = processor;
		ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5* L_0 = ___0_processor;
		((RtcService_t22C275834C979544290EE8B61C467477647BD1BF_StaticFields*)il2cpp_codegen_static_fields_for(RtcService_t22C275834C979544290EE8B61C467477647BD1BF_il2cpp_TypeInfo_var))->___audioProcessor_0 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((RtcService_t22C275834C979544290EE8B61C467477647BD1BF_StaticFields*)il2cpp_codegen_static_fields_for(RtcService_t22C275834C979544290EE8B61C467477647BD1BF_il2cpp_TypeInfo_var))->___audioProcessor_0), (void*)L_0);
		// CLIB.ppf_Rtc_RegisterLocalAudioProcessor(InnerAudioProcessor, channel, sampleRate);
		RtcProcessAudioFrameFunction_t91998EE2CD7760356A3A9E75620AEB591C1F2344* L_1 = (RtcProcessAudioFrameFunction_t91998EE2CD7760356A3A9E75620AEB591C1F2344*)il2cpp_codegen_object_new(RtcProcessAudioFrameFunction_t91998EE2CD7760356A3A9E75620AEB591C1F2344_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		RtcProcessAudioFrameFunction__ctor_m55F453E056A84CA415A7E8B7CF428BF0A7901A50(L_1, NULL, (intptr_t)((void*)RtcService_InnerAudioProcessor_m663C1AC6BC552D87E0EF075932933D89EA182C22_RuntimeMethod_var), NULL);
		int32_t L_2 = ___1_channel;
		int32_t L_3 = ___2_sampleRate;
		CLIB_ppf_Rtc_RegisterLocalAudioProcessor_mF40BE44B52397C73F3E98736217222546F1FE166(L_1, L_2, L_3, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::EnableAudioPropertiesReport(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_EnableAudioPropertiesReport_m962D3D000DFE783E1EEFE59EF0A84D218C73D8E6 (int32_t ___0_interval, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RtcAudioPropertyOptions_t5E394E488DDCF996DB82E9326E71B465A4D6D23E_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// var conf = new RtcAudioPropertyOptions();
		RtcAudioPropertyOptions_t5E394E488DDCF996DB82E9326E71B465A4D6D23E* L_0 = (RtcAudioPropertyOptions_t5E394E488DDCF996DB82E9326E71B465A4D6D23E*)il2cpp_codegen_object_new(RtcAudioPropertyOptions_t5E394E488DDCF996DB82E9326E71B465A4D6D23E_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		RtcAudioPropertyOptions__ctor_m5D01ABC1098566CAD6A7000775D6CA381D70509F(L_0, NULL);
		// conf.SetInterval(interval);
		RtcAudioPropertyOptions_t5E394E488DDCF996DB82E9326E71B465A4D6D23E* L_1 = L_0;
		int32_t L_2 = ___0_interval;
		NullCheck(L_1);
		RtcAudioPropertyOptions_SetInterval_m8075C50D77C3347FB74433C8D73FBA38E3416005(L_1, L_2, NULL);
		// CLIB.ppf_Rtc_EnableAudioPropertiesReport((IntPtr) conf);
		intptr_t L_3;
		L_3 = RtcAudioPropertyOptions_op_Explicit_mAA54B25B681E9C597F68538D3339153E5748FB9A(L_1, NULL);
		CLIB_ppf_Rtc_EnableAudioPropertiesReport_m97025C0A2787682A37CEEFC30F7DBB89D5831533(L_3, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::PublishRoom(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_PublishRoom_mEE5D6786FF2EC07CFD59375E9ADC60E33D2D8E86 (String_t* ___0_roomId, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_Rtc_RoomPublishStream(roomId, RtcMediaStreamType.Audio);
		String_t* L_0 = ___0_roomId;
		CLIB_ppf_Rtc_RoomPublishStream_m999BF20CA150068F21BB66C40AD84A9768BC2033(L_0, 1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::UnPublishRoom(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_UnPublishRoom_m34592A5C3B59C5C1ACAA0BE0C9D7CAFAB3E362F7 (String_t* ___0_roomId, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_Rtc_RoomUnPublishStream(roomId, RtcMediaStreamType.Audio);
		String_t* L_0 = ___0_roomId;
		CLIB_ppf_Rtc_RoomUnPublishStream_m00FEBEC578FA2194B9E8A8B48FBFB928E5FDB138(L_0, 1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::DestroyRoom(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_DestroyRoom_m6D553521DCD3D2A943F0B1DFF20B9AA4978913B9 (String_t* ___0_roomId, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_Rtc_DestroyRoom(roomId);
		String_t* L_0 = ___0_roomId;
		CLIB_ppf_Rtc_DestroyRoom_m9624553A2D673BC8441668054A0456836613D50D(L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::StartAudioCapture()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_StartAudioCapture_mF0DA2F73E5B7E3FBDF12FF883391C4EF15CB852D (const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_Rtc_StartAudioCapture();
		CLIB_ppf_Rtc_StartAudioCapture_m8700CD4674A20317315792FF01A293DC9EE03B5D(NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::StopAudioCapture()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_StopAudioCapture_mCBE5DADCBEA31AB76D2BF7E2B2D70929C9D535A7 (const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_Rtc_StopAudioCapture();
		CLIB_ppf_Rtc_StopAudioCapture_m9314204AA68DEC851FD5F446DB4E65B1B7DCC67E(NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetCaptureVolume(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetCaptureVolume_mEE326C6BADAE50B581A2C44B44411165A62A71AB (int32_t ___0_volume, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_Rtc_SetCaptureVolume(RtcStreamIndex.Main, volume);
		int32_t L_0 = ___0_volume;
		CLIB_ppf_Rtc_SetCaptureVolume_mF57DFC4F22BF53E417A49455A3FB35D4E80CFC73(0, L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetPlaybackVolume(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetPlaybackVolume_m677C38B515B81C488FA486F7F5D6446D49D07C3A (int32_t ___0_volume, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_Rtc_SetPlaybackVolume(volume);
		int32_t L_0 = ___0_volume;
		CLIB_ppf_Rtc_SetPlaybackVolume_m5C43C4FF094E1034EA128BF265E10B7055C65A8D(L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetEarMonitorMode(Pico.Platform.RtcEarMonitorMode)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetEarMonitorMode_mD8D611AF6E8068A2B4F53FC96CEF69ECDBD5AEA1 (int32_t ___0_mode, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_Rtc_SetEarMonitorMode(mode);
		int32_t L_0 = ___0_mode;
		CLIB_ppf_Rtc_SetEarMonitorMode_m3A40312D08EF057E864EC56020773481AB184F0C(L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetEarMonitorVolume(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetEarMonitorVolume_mA72A4B6C43B754BDBA6A66FD0F24F4ED0A990575 (int32_t ___0_volume, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_Rtc_SetEarMonitorVolume(volume);
		int32_t L_0 = ___0_volume;
		CLIB_ppf_Rtc_SetEarMonitorVolume_m18A7BBD03541E7EFF142C6F976D002BBB9D61AE4(L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::MuteLocalAudio(Pico.Platform.RtcMuteState)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_MuteLocalAudio_m17017BE2D4274302111347DD1B88ADF2C13659E4 (int32_t ___0_rtcMuteState, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_Rtc_MuteLocalAudio(rtcMuteState);
		int32_t L_0 = ___0_rtcMuteState;
		CLIB_ppf_Rtc_MuteLocalAudio_m77706FE3988E9393BACD03870F2641AD938DDA7E(L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::UpdateToken(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_UpdateToken_mD860DBD249EF4448F974954FAACF64A18D9B3C11 (String_t* ___0_roomId, String_t* ___1_token, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_Rtc_UpdateToken(roomId, token);
		String_t* L_0 = ___0_roomId;
		String_t* L_1 = ___1_token;
		CLIB_ppf_Rtc_UpdateToken_mF6E21D718D5EA93B515E07C2DFFCCFD96985EDBB(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetAudioScenario(Pico.Platform.RtcAudioScenarioType)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetAudioScenario_m8DEFD5F7961B4DEEBF89509DBD6A23A62D75231F (int32_t ___0_scenarioType, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_Rtc_SetAudioScenario(scenarioType);
		int32_t L_0 = ___0_scenarioType;
		CLIB_ppf_Rtc_SetAudioScenario_mC636AA2606FA3F31BE8BF487B8B05CA8E88B0EA1(L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::RoomSetRemoteAudioPlaybackVolume(System.String,System.String,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_RoomSetRemoteAudioPlaybackVolume_m981CA20823E8E0F250AA964F9EB9DB0E26BEBAE0 (String_t* ___0_roomId, String_t* ___1_userId, int32_t ___2_volume, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_Rtc_RoomSetRemoteAudioPlaybackVolume(roomId, userId, volume);
		String_t* L_0 = ___0_roomId;
		String_t* L_1 = ___1_userId;
		int32_t L_2 = ___2_volume;
		CLIB_ppf_Rtc_RoomSetRemoteAudioPlaybackVolume_m7433C4EC934EE144B19D75B7AE556CC89EFCF6EB(L_0, L_1, L_2, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::RoomSubscribeStream(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_RoomSubscribeStream_m41B409CF7ECD851EA659A244FBF8A5A4EE3E22E9 (String_t* ___0_roomId, String_t* ___1_userId, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_Rtc_RoomSubscribeStream(roomId, userId, RtcMediaStreamType.Audio);
		String_t* L_0 = ___0_roomId;
		String_t* L_1 = ___1_userId;
		CLIB_ppf_Rtc_RoomSubscribeStream_mC7D8349F283518760FF8D7C1068651DF3B7DC779(L_0, L_1, 1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::RoomUnSubscribeStream(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_RoomUnSubscribeStream_m0DE28E1583C633D45193390228BBFF756158F3BC (String_t* ___0_roomId, String_t* ___1_userId, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_Rtc_RoomUnsubscribeStream(roomId, userId, RtcMediaStreamType.Audio);
		String_t* L_0 = ___0_roomId;
		String_t* L_1 = ___1_userId;
		CLIB_ppf_Rtc_RoomUnsubscribeStream_m3C9352F9B827AC824A03C96E5FFA327C8D8CBF7F(L_0, L_1, 1, NULL);
		// }
		return;
	}
}
// System.Int64 Pico.Platform.RtcService::SendRoomBinaryMessage(System.String,System.Byte[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t RtcService_SendRoomBinaryMessage_m6B48B971DEB3A71493C99BCFB41A5E379BF32910 (String_t* ___0_roomId, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___1_message, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2* V_0 = NULL;
	{
		// var ptr = new PtrManager(message);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___1_message;
		PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2* L_1 = (PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2*)il2cpp_codegen_object_new(PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		PtrManager__ctor_m7BEAACAEBEE05EF15116C986BAB9A1DA2002A478(L_1, L_0, NULL);
		V_0 = L_1;
		// var ans = CLIB.ppf_Rtc_SendRoomBinaryMessage(roomId, ptr.ptr, message.Length);
		String_t* L_2 = ___0_roomId;
		PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2* L_3 = V_0;
		NullCheck(L_3);
		intptr_t L_4 = L_3->___ptr_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = ___1_message;
		NullCheck(L_5);
		int64_t L_6;
		L_6 = CLIB_ppf_Rtc_SendRoomBinaryMessage_m3ED7D7134269914FE9FC7EB789C89658EB6FDA8F(L_2, L_4, ((int32_t)(((RuntimeArray*)L_5)->max_length)), NULL);
		// ptr.Free();
		PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2* L_7 = V_0;
		NullCheck(L_7);
		PtrManager_Free_mF57A82180453684532E9C29833A96C28D8BA7D05(L_7, NULL);
		// return ans;
		return L_6;
	}
}
// System.Int64 Pico.Platform.RtcService::SendRoomMessage(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t RtcService_SendRoomMessage_m0F9CD695740455C83F22DF58630C01BEFD2982B1 (String_t* ___0_roomId, String_t* ___1_message, const RuntimeMethod* method) 
{
	{
		// return CLIB.ppf_Rtc_SendRoomMessage(roomId, message);
		String_t* L_0 = ___0_roomId;
		String_t* L_1 = ___1_message;
		int64_t L_2;
		L_2 = CLIB_ppf_Rtc_SendRoomMessage_m9E0EBE88DD65721EFE48D813A74C22860A8A03B5(L_0, L_1, NULL);
		return L_2;
	}
}
// System.Int64 Pico.Platform.RtcService::SendUserBinaryMessage(System.String,System.String,System.Byte[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t RtcService_SendUserBinaryMessage_mCB97BBCAF6EB8A7A76CFD407B45A5F956DBC6606 (String_t* ___0_roomId, String_t* ___1_userId, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___2_message, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2* V_0 = NULL;
	{
		// var ptr = new PtrManager(message);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___2_message;
		PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2* L_1 = (PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2*)il2cpp_codegen_object_new(PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		PtrManager__ctor_m7BEAACAEBEE05EF15116C986BAB9A1DA2002A478(L_1, L_0, NULL);
		V_0 = L_1;
		// var ans = CLIB.ppf_Rtc_SendUserBinaryMessage(roomId, userId, ptr.ptr, message.Length);
		String_t* L_2 = ___0_roomId;
		String_t* L_3 = ___1_userId;
		PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2* L_4 = V_0;
		NullCheck(L_4);
		intptr_t L_5 = L_4->___ptr_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_6 = ___2_message;
		NullCheck(L_6);
		int64_t L_7;
		L_7 = CLIB_ppf_Rtc_SendUserBinaryMessage_m822EB94F0C78D74D76EF162C90ADA3F3B56E936F(L_2, L_3, L_5, ((int32_t)(((RuntimeArray*)L_6)->max_length)), NULL);
		// ptr.Free();
		PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2* L_8 = V_0;
		NullCheck(L_8);
		PtrManager_Free_mF57A82180453684532E9C29833A96C28D8BA7D05(L_8, NULL);
		// return ans;
		return L_7;
	}
}
// System.Int64 Pico.Platform.RtcService::SendUserMessage(System.String,System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t RtcService_SendUserMessage_mF5F9172924B7BD1084FEBA1582271B8D6EB53AB3 (String_t* ___0_roomId, String_t* ___1_userId, String_t* ___2_message, const RuntimeMethod* method) 
{
	{
		// return CLIB.ppf_Rtc_SendUserMessage(roomId, userId, message);
		String_t* L_0 = ___0_roomId;
		String_t* L_1 = ___1_userId;
		String_t* L_2 = ___2_message;
		int64_t L_3;
		L_3 = CLIB_ppf_Rtc_SendUserMessage_mF5F42745A4FEF34004712FB21A340155506CEF01(L_0, L_1, L_2, NULL);
		return L_3;
	}
}
// System.Int32 Pico.Platform.RtcService::SendStreamSyncInfo(System.Byte[],System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RtcService_SendStreamSyncInfo_mB9BAEBCD9D9DA8646BD489926006E0DE1FA1EBBF (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_data, int32_t ___1_repeatCount, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073* V_0 = NULL;
	PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2* V_1 = NULL;
	{
		// var config = new RtcStreamSyncInfoOptions();
		RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073* L_0 = (RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073*)il2cpp_codegen_object_new(RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		RtcStreamSyncInfoOptions__ctor_m9D86B190CCE9ADF893542CCB8FEB7EEF4309CE7E(L_0, NULL);
		V_0 = L_0;
		// config.SetRepeatCount(repeatCount);
		RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073* L_1 = V_0;
		int32_t L_2 = ___1_repeatCount;
		NullCheck(L_1);
		RtcStreamSyncInfoOptions_SetRepeatCount_mEC362A0008CECC40F6C5B3DE011BC44DBE66256B(L_1, L_2, NULL);
		// config.SetStreamIndex(RtcStreamIndex.Main);
		RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073* L_3 = V_0;
		NullCheck(L_3);
		RtcStreamSyncInfoOptions_SetStreamIndex_m76FF4534D8271C81C0263995DC0554961184DA34(L_3, 0, NULL);
		// config.SetStreamType(RtcSyncInfoStreamType.Audio);
		RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073* L_4 = V_0;
		NullCheck(L_4);
		RtcStreamSyncInfoOptions_SetStreamType_m75AF0A32A37BC87F68C105FB7DA0E3737C3BF977(L_4, 0, NULL);
		// var ptr = new PtrManager(data);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = ___0_data;
		PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2* L_6 = (PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2*)il2cpp_codegen_object_new(PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2_il2cpp_TypeInfo_var);
		NullCheck(L_6);
		PtrManager__ctor_m7BEAACAEBEE05EF15116C986BAB9A1DA2002A478(L_6, L_5, NULL);
		V_1 = L_6;
		// var ans = CLIB.ppf_Rtc_SendStreamSyncInfo(ptr.ptr, data.Length, (IntPtr) config);
		PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2* L_7 = V_1;
		NullCheck(L_7);
		intptr_t L_8 = L_7->___ptr_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9 = ___0_data;
		NullCheck(L_9);
		RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073* L_10 = V_0;
		intptr_t L_11;
		L_11 = RtcStreamSyncInfoOptions_op_Explicit_m36286E8D49E4A5A299A71C763E9421343B2E71FC(L_10, NULL);
		int32_t L_12;
		L_12 = CLIB_ppf_Rtc_SendStreamSyncInfo_mA91C187D432205B5CE0234D1EB60B7B78A216F69(L_8, ((int32_t)(((RuntimeArray*)L_9)->max_length)), L_11, NULL);
		// ptr.Free();
		PtrManager_t833E3E357C817D8CBC5DE7472FDF5AB9C13F2BA2* L_13 = V_1;
		NullCheck(L_13);
		PtrManager_Free_mF57A82180453684532E9C29833A96C28D8BA7D05(L_13, NULL);
		// return ans;
		return L_12;
	}
}
// System.Void Pico.Platform.RtcService::SetOnTokenWillExpire(Pico.Platform.Message`1/Handler<System.String>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnTokenWillExpire_m62284B70EA146FC1268F6E0243E124A3FA4BE2C2 (Handler_tE2837A49F6F6E0632D5E94EF3412C338F6526C86* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnTokenWillExpire, handler);
		Handler_tE2837A49F6F6E0632D5E94EF3412C338F6526C86* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10219), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnRoomMessageReceived(Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRoomMessageReceived>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnRoomMessageReceived_mEE234847995A8A3C887B54A99AAFDD4F4829726A (Handler_t063B85C34774FF958AF1A957B4854AF1D6B23888* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnRoomMessageReceived, handler);
		Handler_t063B85C34774FF958AF1A957B4854AF1D6B23888* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10217), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnRoomBinaryMessageReceived(Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcBinaryMessageReceived>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnRoomBinaryMessageReceived_m8C37D1A4BB4B2077B0E81EE85A6979972DA3E3B3 (Handler_t1549946AE7DD631785DEE828E599E4CC5F232986* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnRoomBinaryMessageReceived, handler);
		Handler_t1549946AE7DD631785DEE828E599E4CC5F232986* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10223), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnUserMessageReceived(Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserMessageReceived>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnUserMessageReceived_mFAFA95CA10E70EEB1C25B601A057639160BB4725 (Handler_t32B3FC4A52987EC7404B0AC82BD702C403DB3C40* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnUserMessageReceived, handler);
		Handler_t32B3FC4A52987EC7404B0AC82BD702C403DB3C40* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10218), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnUserBinaryMessageReceived(Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcBinaryMessageReceived>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnUserBinaryMessageReceived_mAEC374611130A9795BDADB88687F21FCACB6033D (Handler_t1549946AE7DD631785DEE828E599E4CC5F232986* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnUserBinaryMessageReceived, handler);
		Handler_t1549946AE7DD631785DEE828E599E4CC5F232986* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10226), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnRoomMessageSendResult(Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcMessageSendResult>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnRoomMessageSendResult_m3103B58648CC5E3B2A647D4BA6A1B458AED9D734 (Handler_t19833D1404BED864BD881EC7D6947C4BE818F739* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnRoomMessageSendResult, handler);
		Handler_t19833D1404BED864BD881EC7D6947C4BE818F739* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10230), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnUserMessageSendResult(Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcMessageSendResult>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnUserMessageSendResult_mEA4292387F7F798D1666C9F86445A62AF4DC2872 (Handler_t19833D1404BED864BD881EC7D6947C4BE818F739* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnUserMessageSendResult, handler);
		Handler_t19833D1404BED864BD881EC7D6947C4BE818F739* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10228), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnUserPublishStream(Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserPublishInfo>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnUserPublishStream_m908893F7D093DD75C6CDE3E9AFF3674D4A89F5B1 (Handler_tD0453CC0FF093CB47FCC2768A008B81EA8988C7F* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnUserPublishStream, handler);
		Handler_tD0453CC0FF093CB47FCC2768A008B81EA8988C7F* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10231), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnUserUnPublishStream(Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserUnPublishInfo>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnUserUnPublishStream_m6980E54D537145F7C13FB389F0A937607FB84236 (Handler_t7B5EC3663F375895202BECAC07552A9F3DCD971D* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnUserUnPublishStream, handler);
		Handler_t7B5EC3663F375895202BECAC07552A9F3DCD971D* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10232), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnStreamSyncInfoReceived(Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcStreamSyncInfo>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnStreamSyncInfoReceived_m9E62FAF704FE413C97F03895963B9CC279A52CFB (Handler_t4BEE9C610174E243B1AA20525A10BBD66E21BDF5* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnStreamSyncInfoReceived, handler);
		Handler_t4BEE9C610174E243B1AA20525A10BBD66E21BDF5* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10220), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnJoinRoomResultCallback(Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcJoinRoomResult>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnJoinRoomResultCallback_mA19906E0C26C51CBBC166A1C232E1F6DBCE01238 (Handler_tAFF89B31CBE84C07A66A39AC220981DEC2B648C7* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnJoinRoom, handler);
		Handler_tAFF89B31CBE84C07A66A39AC220981DEC2B648C7* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10201), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnLeaveRoomResultCallback(Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcLeaveRoomResult>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnLeaveRoomResultCallback_m19E57F1CC4F83730B63EBCC0DF1D1EBAEB891813 (Handler_t53CDA67D66BFBB13CE74EC8B6623D88EB60E6CAE* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnLeaveRoom, handler);
		Handler_t53CDA67D66BFBB13CE74EC8B6623D88EB60E6CAE* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10202), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnUserJoinRoomResultCallback(Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserJoinInfo>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnUserJoinRoomResultCallback_m1EA0B7C739EC23115E11B223D0C3D81B31953D34 (Handler_t560A0AAA9073BD8BEBEA299A0C30C715A673E10D* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnUserJoinRoom, handler);
		Handler_t560A0AAA9073BD8BEBEA299A0C30C715A673E10D* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10204), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnUserLeaveRoomResultCallback(Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcUserLeaveInfo>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnUserLeaveRoomResultCallback_m8DA5A2E2CDD523B29E2CED9FC32794ACD350C6B7 (Handler_t163FC6326170437BFF25564AF32923B777FDDE24* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnUserLeaveRoom, handler);
		Handler_t163FC6326170437BFF25564AF32923B777FDDE24* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10203), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnRoomStatsCallback(Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRoomStats>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnRoomStatsCallback_m186B41016E002BFA46E347E778091F95EF732E41 (Handler_t75AD0D0BA45ACBB20855ADA2457EB304BF32C5B9* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnRoomStats, handler);
		Handler_t75AD0D0BA45ACBB20855ADA2457EB304BF32C5B9* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10200), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnWarnCallback(Pico.Platform.Message`1/Handler<System.Int32>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnWarnCallback_m43D4E89F6FE8D46AF1A682AC9B947E7DBA694687 (Handler_t51AE26B34C94E80FFE0A43298E5E7BCF0085B456* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnWarn, handler);
		Handler_t51AE26B34C94E80FFE0A43298E5E7BCF0085B456* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10206), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnErrorCallback(Pico.Platform.Message`1/Handler<System.Int32>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnErrorCallback_m9F08039B1416D6169430DE08694E9C4FEC4928ED (Handler_t51AE26B34C94E80FFE0A43298E5E7BCF0085B456* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnError, handler);
		Handler_t51AE26B34C94E80FFE0A43298E5E7BCF0085B456* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10209), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnRoomWarnCallback(Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRoomWarn>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnRoomWarnCallback_m400F490F0DABB37F9ED61E126569823FF2D6FE41 (Handler_tCAF1D3F2723A4B7251F1BC23304D41F30171BA7E* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnRoomWarn, handler);
		Handler_tCAF1D3F2723A4B7251F1BC23304D41F30171BA7E* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10207), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnRoomErrorCallback(Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRoomError>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnRoomErrorCallback_mD906D67149802F5ED99045D3B6B0A18B60372E0F (Handler_tAB0E94E2155E2F41351762B712D4F71A3E696890* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnRoomError, handler);
		Handler_tAB0E94E2155E2F41351762B712D4F71A3E696890* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10208), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnConnectionStateChangeCallback(Pico.Platform.Message`1/Handler<Pico.Platform.RtcConnectionState>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnConnectionStateChangeCallback_m950EAA7B5E413BEFF5DAC4F898CD8066E5673A24 (Handler_t38CC844160733F92880FA63972B403BF586D39B1* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnConnectionStateChange, handler);
		Handler_t38CC844160733F92880FA63972B403BF586D39B1* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10205), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnUserMuteAudio(Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcMuteInfo>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnUserMuteAudio_m8842D05F8B89D9A401E79ABABE6E477977C34679 (Handler_t031AC8F825D5CD006D0F5F9FE16EB538F31C1101* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnUserMuteAudio, handler);
		Handler_t031AC8F825D5CD006D0F5F9FE16EB538F31C1101* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10215), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnUserStartAudioCapture(Pico.Platform.Message`1/Handler<System.String>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnUserStartAudioCapture_mB0F6F207058DD34493019BAF3062FF7FCB8DD40C (Handler_tE2837A49F6F6E0632D5E94EF3412C338F6526C86* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnUserStartAudioCapture, handler);
		Handler_tE2837A49F6F6E0632D5E94EF3412C338F6526C86* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10210), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnUserStopAudioCapture(Pico.Platform.Message`1/Handler<System.String>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnUserStopAudioCapture_m37BB90937CF2D79B415CE2B1AE45959CAFA3EDA8 (Handler_tE2837A49F6F6E0632D5E94EF3412C338F6526C86* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnUserStopAudioCapture, handler);
		Handler_tE2837A49F6F6E0632D5E94EF3412C338F6526C86* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10214), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnAudioPlaybackDeviceChange(Pico.Platform.Message`1/Handler<Pico.Platform.RtcAudioPlaybackDevice>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnAudioPlaybackDeviceChange_mD5EDABCFA996E8CB520E7D16BB23206C104AC7D0 (Handler_t9E74A09C7774D66FE0B94FDFE1DFA6DDEC5859ED* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnAudioPlaybackDeviceChanged, handler);
		Handler_t9E74A09C7774D66FE0B94FDFE1DFA6DDEC5859ED* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10211), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnLocalAudioPropertiesReport(Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcLocalAudioPropertiesReport>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnLocalAudioPropertiesReport_mD647E749A414A483896817C4C530F09E34EB8000 (Handler_tAC738204727C49FCB4492833A34C3C4A619CEC8E* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnLocalAudioPropertiesReport, handler);
		Handler_tAC738204727C49FCB4492833A34C3C4A619CEC8E* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10213), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcService::SetOnRemoteAudioPropertiesReport(Pico.Platform.Message`1/Handler<Pico.Platform.Models.RtcRemoteAudioPropertiesReport>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcService_SetOnRemoteAudioPropertiesReport_m07BF3E4B2DB1008AA02CC3CC682B211616506BCF (Handler_t2765C77EA08935A8D61BD6074F539B8BA92581B9* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Rtc_OnRemoteAudioPropertiesReport, handler);
		Handler_t2765C77EA08935A8D61BD6074F539B8BA92581B9* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)10212), L_0, NULL);
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
int32_t ProcessAudioFrameFunction_Invoke_m5EC2CDFD611F5CDC64BD8A36A025E8C08FF061D6_Multicast(ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5* __this, RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59* ___0_frame, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates_13->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates_13->GetAddressAtUnchecked(0));
	int32_t retVal = 0;
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5* currentDelegate = reinterpret_cast<ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5*>(delegatesToInvoke[i]);
		typedef int32_t (*FunctionPointerType) (RuntimeObject*, RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59*, const RuntimeMethod*);
		retVal = ((FunctionPointerType)currentDelegate->___invoke_impl_1)((Il2CppObject*)currentDelegate->___method_code_6, ___0_frame, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method_3));
	}
	return retVal;
}
int32_t ProcessAudioFrameFunction_Invoke_m5EC2CDFD611F5CDC64BD8A36A025E8C08FF061D6_OpenInst(ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5* __this, RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59* ___0_frame, const RuntimeMethod* method)
{
	NullCheck(___0_frame);
	typedef int32_t (*FunctionPointerType) (RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59*, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___method_ptr_0)(___0_frame, method);
}
int32_t ProcessAudioFrameFunction_Invoke_m5EC2CDFD611F5CDC64BD8A36A025E8C08FF061D6_OpenStatic(ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5* __this, RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59* ___0_frame, const RuntimeMethod* method)
{
	typedef int32_t (*FunctionPointerType) (RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59*, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___method_ptr_0)(___0_frame, method);
}
int32_t ProcessAudioFrameFunction_Invoke_m5EC2CDFD611F5CDC64BD8A36A025E8C08FF061D6_OpenStaticInvoker(ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5* __this, RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59* ___0_frame, const RuntimeMethod* method)
{
	return InvokerFuncInvoker1< int32_t, RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59* >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, ___0_frame);
}
int32_t ProcessAudioFrameFunction_Invoke_m5EC2CDFD611F5CDC64BD8A36A025E8C08FF061D6_ClosedStaticInvoker(ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5* __this, RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59* ___0_frame, const RuntimeMethod* method)
{
	return InvokerFuncInvoker2< int32_t, RuntimeObject*, RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59* >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, __this->___m_target_2, ___0_frame);
}
int32_t ProcessAudioFrameFunction_Invoke_m5EC2CDFD611F5CDC64BD8A36A025E8C08FF061D6_OpenVirtual(ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5* __this, RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59* ___0_frame, const RuntimeMethod* method)
{
	NullCheck(___0_frame);
	return VirtualFuncInvoker0< int32_t >::Invoke(il2cpp_codegen_method_get_slot(method), ___0_frame);
}
int32_t ProcessAudioFrameFunction_Invoke_m5EC2CDFD611F5CDC64BD8A36A025E8C08FF061D6_OpenInterface(ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5* __this, RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59* ___0_frame, const RuntimeMethod* method)
{
	NullCheck(___0_frame);
	return InterfaceFuncInvoker0< int32_t >::Invoke(il2cpp_codegen_method_get_slot(method), il2cpp_codegen_method_get_declaring_type(method), ___0_frame);
}
int32_t ProcessAudioFrameFunction_Invoke_m5EC2CDFD611F5CDC64BD8A36A025E8C08FF061D6_OpenGenericVirtual(ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5* __this, RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59* ___0_frame, const RuntimeMethod* method)
{
	NullCheck(___0_frame);
	return GenericVirtualFuncInvoker0< int32_t >::Invoke(method, ___0_frame);
}
int32_t ProcessAudioFrameFunction_Invoke_m5EC2CDFD611F5CDC64BD8A36A025E8C08FF061D6_OpenGenericInterface(ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5* __this, RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59* ___0_frame, const RuntimeMethod* method)
{
	NullCheck(___0_frame);
	return GenericInterfaceFuncInvoker0< int32_t >::Invoke(method, ___0_frame);
}
// System.Void Pico.Platform.RtcService/ProcessAudioFrameFunction::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProcessAudioFrameFunction__ctor_mB63C465A7D6EA4ED5A425D0F961AB935ED9C31B7 (ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
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
				__this->___invoke_impl_1 = (intptr_t)&ProcessAudioFrameFunction_Invoke_m5EC2CDFD611F5CDC64BD8A36A025E8C08FF061D6_OpenStaticInvoker;
			else
				__this->___invoke_impl_1 = (intptr_t)&ProcessAudioFrameFunction_Invoke_m5EC2CDFD611F5CDC64BD8A36A025E8C08FF061D6_ClosedStaticInvoker;
		else
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&ProcessAudioFrameFunction_Invoke_m5EC2CDFD611F5CDC64BD8A36A025E8C08FF061D6_OpenStatic;
			else
				{
					__this->___invoke_impl_1 = __this->___method_ptr_0;
					__this->___method_code_6 = (intptr_t)__this->___m_target_2;
				}
	}
	else
	{
		bool isOpen = parameterCount == 0;
		if (isOpen)
		{
			if (__this->___method_is_virtual_12)
			{
				if (il2cpp_codegen_method_is_generic_instance_method((RuntimeMethod*)___1_method))
					if (il2cpp_codegen_method_is_interface_method((RuntimeMethod*)___1_method))
						__this->___invoke_impl_1 = (intptr_t)&ProcessAudioFrameFunction_Invoke_m5EC2CDFD611F5CDC64BD8A36A025E8C08FF061D6_OpenGenericInterface;
					else
						__this->___invoke_impl_1 = (intptr_t)&ProcessAudioFrameFunction_Invoke_m5EC2CDFD611F5CDC64BD8A36A025E8C08FF061D6_OpenGenericVirtual;
				else
					if (il2cpp_codegen_method_is_interface_method((RuntimeMethod*)___1_method))
						__this->___invoke_impl_1 = (intptr_t)&ProcessAudioFrameFunction_Invoke_m5EC2CDFD611F5CDC64BD8A36A025E8C08FF061D6_OpenInterface;
					else
						__this->___invoke_impl_1 = (intptr_t)&ProcessAudioFrameFunction_Invoke_m5EC2CDFD611F5CDC64BD8A36A025E8C08FF061D6_OpenVirtual;
			}
			else
			{
				__this->___invoke_impl_1 = (intptr_t)&ProcessAudioFrameFunction_Invoke_m5EC2CDFD611F5CDC64BD8A36A025E8C08FF061D6_OpenInst;
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
	__this->___extra_arg_5 = (intptr_t)&ProcessAudioFrameFunction_Invoke_m5EC2CDFD611F5CDC64BD8A36A025E8C08FF061D6_Multicast;
}
// System.Int32 Pico.Platform.RtcService/ProcessAudioFrameFunction::Invoke(Pico.Platform.Models.RtcAudioFrame)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ProcessAudioFrameFunction_Invoke_m5EC2CDFD611F5CDC64BD8A36A025E8C08FF061D6 (ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5* __this, RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59* ___0_frame, const RuntimeMethod* method) 
{
	typedef int32_t (*FunctionPointerType) (RuntimeObject*, RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59*, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_frame, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
// System.IAsyncResult Pico.Platform.RtcService/ProcessAudioFrameFunction::BeginInvoke(Pico.Platform.Models.RtcAudioFrame,System.AsyncCallback,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ProcessAudioFrameFunction_BeginInvoke_m18E036E1B3C2DE7BC8F84048F264523B29D85E5A (ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5* __this, RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59* ___0_frame, AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___1_callback, RuntimeObject* ___2_object, const RuntimeMethod* method) 
{
	void *__d_args[2] = {0};
	__d_args[0] = ___0_frame;
	return (RuntimeObject*)il2cpp_codegen_delegate_begin_invoke((RuntimeDelegate*)__this, __d_args, (RuntimeDelegate*)___1_callback, (RuntimeObject*)___2_object);
}
// System.Int32 Pico.Platform.RtcService/ProcessAudioFrameFunction::EndInvoke(System.IAsyncResult)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ProcessAudioFrameFunction_EndInvoke_mB3475E6B559FD9E7A51ED673BD7368E267DF0AC1 (ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5* __this, RuntimeObject* ___0_result, const RuntimeMethod* method) 
{
	RuntimeObject *__result = il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___0_result, 0);
	return *(int32_t*)UnBox ((RuntimeObject*)__result);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void Pico.Platform.RtcStreamSyncInfoOptions::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcStreamSyncInfoOptions__ctor_m9D86B190CCE9ADF893542CCB8FEB7EEF4309CE7E (RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073* __this, const RuntimeMethod* method) 
{
	{
		// public RtcStreamSyncInfoOptions()
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Handle = CLIB.ppf_RtcStreamSyncInfoOptions_Create();
		intptr_t L_0;
		L_0 = CLIB_ppf_RtcStreamSyncInfoOptions_Create_m58EE568E749D28D2598EBBAC97492FD722157648(NULL);
		__this->___Handle_0 = L_0;
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcStreamSyncInfoOptions::SetRepeatCount(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcStreamSyncInfoOptions_SetRepeatCount_mEC362A0008CECC40F6C5B3DE011BC44DBE66256B (RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_RtcStreamSyncInfoOptions_SetRepeatCount(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		int32_t L_1 = ___0_value;
		CLIB_ppf_RtcStreamSyncInfoOptions_SetRepeatCount_m3A7E7085D9B3106EC3B39654CE672545D328F178(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcStreamSyncInfoOptions::SetStreamIndex(Pico.Platform.RtcStreamIndex)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcStreamSyncInfoOptions_SetStreamIndex_m76FF4534D8271C81C0263995DC0554961184DA34 (RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_RtcStreamSyncInfoOptions_SetStreamIndex(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		int32_t L_1 = ___0_value;
		CLIB_ppf_RtcStreamSyncInfoOptions_SetStreamIndex_m792067CEFBC2A89E1C18D06B77E9A83018885817(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcStreamSyncInfoOptions::SetStreamType(Pico.Platform.RtcSyncInfoStreamType)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcStreamSyncInfoOptions_SetStreamType_m75AF0A32A37BC87F68C105FB7DA0E3737C3BF977 (RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_RtcStreamSyncInfoOptions_SetStreamType(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		int32_t L_1 = ___0_value;
		CLIB_ppf_RtcStreamSyncInfoOptions_SetStreamType_mDB18D271F6C9F70032C64E7CF46398F4658E43C4(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.IntPtr Pico.Platform.RtcStreamSyncInfoOptions::op_Explicit(Pico.Platform.RtcStreamSyncInfoOptions)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t RtcStreamSyncInfoOptions_op_Explicit_m36286E8D49E4A5A299A71C763E9421343B2E71FC (RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073* ___0_options, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// return options != null ? options.Handle : IntPtr.Zero;
		RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073* L_0 = ___0_options;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		intptr_t L_1 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		return L_1;
	}

IL_0009:
	{
		RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073* L_2 = ___0_options;
		NullCheck(L_2);
		intptr_t L_3 = L_2->___Handle_0;
		return L_3;
	}
}
// System.Void Pico.Platform.RtcStreamSyncInfoOptions::Finalize()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcStreamSyncInfoOptions_Finalize_mD7F8F12816ED55BC14D898727AAFEA8741D13820 (RtcStreamSyncInfoOptions_t4FA264B6AF6AD36A00CA65401EA64107AD7E7073* __this, const RuntimeMethod* method) 
{
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_000d:
			{// begin finally (depth: 1)
				// }
				Object_Finalize_mC98C96301CCABFE00F1A7EF8E15DF507CACD42B2(__this, NULL);
				return;
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			// CLIB.ppf_RtcStreamSyncInfoOptions_Destroy(Handle);
			intptr_t L_0 = __this->___Handle_0;
			CLIB_ppf_RtcStreamSyncInfoOptions_Destroy_m340714991FE081051E645B634A1A80297A5A90F8(L_0, NULL);
			goto IL_0014;
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0014:
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
// System.Void Pico.Platform.RtcRoomOptions::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRoomOptions__ctor_m753D1C11608C22036A76D99B3C862D89B347E274 (RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* __this, const RuntimeMethod* method) 
{
	{
		// public RtcRoomOptions()
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Handle = CLIB.ppf_RtcRoomOptions_Create();
		intptr_t L_0;
		L_0 = CLIB_ppf_RtcRoomOptions_Create_m5A7470272AD4EB1BCE2680FD1849D82B268458BD(NULL);
		__this->___Handle_1 = L_0;
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcRoomOptions::SetRoomProfileType(Pico.Platform.RtcRoomProfileType)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRoomOptions_SetRoomProfileType_m45350524D2610FA5CD5C4D5723EEA2A2FCF5E0F2 (RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_RtcRoomOptions_SetRoomProfileType(Handle, value);
		intptr_t L_0 = __this->___Handle_1;
		int32_t L_1 = ___0_value;
		CLIB_ppf_RtcRoomOptions_SetRoomProfileType_mA8D5D60BE6D0D635E4378B9B8414E435F15561C7(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcRoomOptions::SetIsAutoSubscribeAudio(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRoomOptions_SetIsAutoSubscribeAudio_m0A6C2D07889202383FE2627313F63E081CA25531 (RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_RtcRoomOptions_SetIsAutoSubscribeAudio(Handle, value);
		intptr_t L_0 = __this->___Handle_1;
		bool L_1 = ___0_value;
		CLIB_ppf_RtcRoomOptions_SetIsAutoSubscribeAudio_m2B2FE59EC7F5C5CF7C06767CCBFC3DAC14D5D897(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcRoomOptions::SetRoomId(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRoomOptions_SetRoomId_m1EC97F209EAB97E51EF3EEAFD8C6D62B6CAD2ED6 (RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		// this.RoomId = value;
		String_t* L_0 = ___0_value;
		__this->___RoomId_0 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___RoomId_0), (void*)L_0);
		// CLIB.ppf_RtcRoomOptions_SetRoomId(Handle, value);
		intptr_t L_1 = __this->___Handle_1;
		String_t* L_2 = ___0_value;
		CLIB_ppf_RtcRoomOptions_SetRoomId_mB4AA3C4EF1DCB602E71CD0FB733CDC7E3E818D40(L_1, L_2, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcRoomOptions::SetUserId(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRoomOptions_SetUserId_m33FD3B38340AF5C0F0A57BFB514C5DA81BFE10BC (RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_RtcRoomOptions_SetUserId(Handle, value);
		intptr_t L_0 = __this->___Handle_1;
		String_t* L_1 = ___0_value;
		CLIB_ppf_RtcRoomOptions_SetUserId_mE7B72158E324346228B79051D3501F4E015B3576(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcRoomOptions::SetUserExtra(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRoomOptions_SetUserExtra_mC725D8F9B0B5148AA8510F043AC2E715C7D84562 (RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_RtcRoomOptions_SetUserExtra(Handle, value);
		intptr_t L_0 = __this->___Handle_1;
		String_t* L_1 = ___0_value;
		CLIB_ppf_RtcRoomOptions_SetUserExtra_mB595CA8CF567FE5164530CB9B9E898570C8BCF62(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcRoomOptions::SetToken(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRoomOptions_SetToken_mE7CAA2DC3B2B75013EDE6C974339572E0CEC7CC0 (RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_RtcRoomOptions_SetToken(Handle, value);
		intptr_t L_0 = __this->___Handle_1;
		String_t* L_1 = ___0_value;
		CLIB_ppf_RtcRoomOptions_SetToken_m35F8E820E30889AE95CBE3C9AD32D062E538B724(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.IntPtr Pico.Platform.RtcRoomOptions::op_Explicit(Pico.Platform.RtcRoomOptions)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t RtcRoomOptions_op_Explicit_mF71D4601FAFEA41A4EA24DBF479115F06149B7CB (RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* ___0_options, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// return options != null ? options.Handle : IntPtr.Zero;
		RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* L_0 = ___0_options;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		intptr_t L_1 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		return L_1;
	}

IL_0009:
	{
		RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* L_2 = ___0_options;
		NullCheck(L_2);
		intptr_t L_3 = L_2->___Handle_1;
		return L_3;
	}
}
// System.Void Pico.Platform.RtcRoomOptions::Finalize()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRoomOptions_Finalize_mA8D6C0D9BFFECF35457E454A2EC0D5D658CFC2BB (RtcRoomOptions_t32BE3A203D53066A2AC79CE37F297BBEB4E42B2A* __this, const RuntimeMethod* method) 
{
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_000d:
			{// begin finally (depth: 1)
				// }
				Object_Finalize_mC98C96301CCABFE00F1A7EF8E15DF507CACD42B2(__this, NULL);
				return;
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			// CLIB.ppf_RtcRoomOptions_Destroy(Handle);
			intptr_t L_0 = __this->___Handle_1;
			CLIB_ppf_RtcRoomOptions_Destroy_mB4989A466D6F0B28733950F3CF5E403F1AA1CECC(L_0, NULL);
			goto IL_0014;
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0014:
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
// System.Void Pico.Platform.RtcGetTokenOptions::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcGetTokenOptions__ctor_mCA91FB23D9E95538924CA5A36D7A0060A0DA1F12 (RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* __this, const RuntimeMethod* method) 
{
	{
		// public RtcGetTokenOptions()
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Handle = CLIB.ppf_RtcGetTokenOptions_Create();
		intptr_t L_0;
		L_0 = CLIB_ppf_RtcGetTokenOptions_Create_mA61E59DCF1BC9FB87A723CC4AFC9D21F190FA845(NULL);
		__this->___Handle_0 = L_0;
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcGetTokenOptions::SetUserId(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcGetTokenOptions_SetUserId_mAC8EC85CB4D28EE5124B3DF53DCB4DA5AB3D8A74 (RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_RtcGetTokenOptions_SetUserId(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		String_t* L_1 = ___0_value;
		CLIB_ppf_RtcGetTokenOptions_SetUserId_m586793AA5C1529DC2386DEE4AA59F09382A1E700(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcGetTokenOptions::SetRoomId(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcGetTokenOptions_SetRoomId_mEC2981B140C843025675715E718FA4BBBCAF5465 (RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_RtcGetTokenOptions_SetRoomId(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		String_t* L_1 = ___0_value;
		CLIB_ppf_RtcGetTokenOptions_SetRoomId_mE00C2681841BEB04C1D8289CCA8B6B2CB5C1D055(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcGetTokenOptions::SetTtl(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcGetTokenOptions_SetTtl_m4EBA04258BF46009456989FA5C35B0C5E3CA85C0 (RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_RtcGetTokenOptions_SetTtl(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		int32_t L_1 = ___0_value;
		CLIB_ppf_RtcGetTokenOptions_SetTtl_m65237B01F848B526EFD856E0F588E1E1E32556AE(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcGetTokenOptions::SetPrivileges(Pico.Platform.RtcPrivilege,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcGetTokenOptions_SetPrivileges_m9BA7C7F94C4C7701F1AAF6B8AE73772F589D6F2B (RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* __this, int32_t ___0_key, int32_t ___1_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_RtcGetTokenOptions_SetPrivileges(Handle, key, value);
		intptr_t L_0 = __this->___Handle_0;
		int32_t L_1 = ___0_key;
		int32_t L_2 = ___1_value;
		CLIB_ppf_RtcGetTokenOptions_SetPrivileges_m66B6F166451610D8A4F3516EF60415E746A4316A(L_0, L_1, L_2, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcGetTokenOptions::ClearPrivileges()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcGetTokenOptions_ClearPrivileges_m548048BBEEE0DA5BC362275784078A63612D1465 (RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* __this, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_RtcGetTokenOptions_ClearPrivileges(Handle);
		intptr_t L_0 = __this->___Handle_0;
		CLIB_ppf_RtcGetTokenOptions_ClearPrivileges_m7EEEBA39B866C6DF24D7D63CDF3E1151486EA9CE(L_0, NULL);
		// }
		return;
	}
}
// System.IntPtr Pico.Platform.RtcGetTokenOptions::op_Explicit(Pico.Platform.RtcGetTokenOptions)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t RtcGetTokenOptions_op_Explicit_m6C383C66020E9B97450516BA56A4804EE11AF49E (RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* ___0_options, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// return options != null ? options.Handle : IntPtr.Zero;
		RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* L_0 = ___0_options;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		intptr_t L_1 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		return L_1;
	}

IL_0009:
	{
		RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* L_2 = ___0_options;
		NullCheck(L_2);
		intptr_t L_3 = L_2->___Handle_0;
		return L_3;
	}
}
// System.Void Pico.Platform.RtcGetTokenOptions::Finalize()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcGetTokenOptions_Finalize_mB5CE4F609E6D0885127897CB5590DE8AF041F6BA (RtcGetTokenOptions_t6535D1FCF515A08D5CCDE76F7BF9FBEB6B42F6D0* __this, const RuntimeMethod* method) 
{
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_000d:
			{// begin finally (depth: 1)
				// }
				Object_Finalize_mC98C96301CCABFE00F1A7EF8E15DF507CACD42B2(__this, NULL);
				return;
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			// CLIB.ppf_RtcGetTokenOptions_Destroy(Handle);
			intptr_t L_0 = __this->___Handle_0;
			CLIB_ppf_RtcGetTokenOptions_Destroy_m032E141DBA3E2792D3C706C675E5EF127E3CE6E9(L_0, NULL);
			goto IL_0014;
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0014:
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
// System.Void Pico.Platform.RtcAudioPropertyOptions::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcAudioPropertyOptions__ctor_m5D01ABC1098566CAD6A7000775D6CA381D70509F (RtcAudioPropertyOptions_t5E394E488DDCF996DB82E9326E71B465A4D6D23E* __this, const RuntimeMethod* method) 
{
	{
		// public RtcAudioPropertyOptions()
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Handle = CLIB.ppf_RtcAudioPropertyOptions_Create();
		intptr_t L_0;
		L_0 = CLIB_ppf_RtcAudioPropertyOptions_Create_mCCF97FD2B44B3BC089C254253E58CD2B11BD3D42(NULL);
		__this->___Handle_0 = L_0;
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcAudioPropertyOptions::SetInterval(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcAudioPropertyOptions_SetInterval_m8075C50D77C3347FB74433C8D73FBA38E3416005 (RtcAudioPropertyOptions_t5E394E488DDCF996DB82E9326E71B465A4D6D23E* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_RtcAudioPropertyOptions_SetInterval(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		int32_t L_1 = ___0_value;
		CLIB_ppf_RtcAudioPropertyOptions_SetInterval_m60586BE91C418B9D72AF664F47B6946E52FD4AF3(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.RtcAudioPropertyOptions::Finalize()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcAudioPropertyOptions_Finalize_m3E314A6827113DAD8622F5A52F3231F31A0C5B5F (RtcAudioPropertyOptions_t5E394E488DDCF996DB82E9326E71B465A4D6D23E* __this, const RuntimeMethod* method) 
{
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_000d:
			{// begin finally (depth: 1)
				// }
				Object_Finalize_mC98C96301CCABFE00F1A7EF8E15DF507CACD42B2(__this, NULL);
				return;
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			// CLIB.ppf_RtcAudioPropertyOptions_Destroy(Handle);
			intptr_t L_0 = __this->___Handle_0;
			CLIB_ppf_RtcAudioPropertyOptions_Destroy_mF7FBEB5F27F730C5FBDF659D820A88B28E7B2A15(L_0, NULL);
			goto IL_0014;
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0014:
	{
		// }
		return;
	}
}
// System.IntPtr Pico.Platform.RtcAudioPropertyOptions::op_Explicit(Pico.Platform.RtcAudioPropertyOptions)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t RtcAudioPropertyOptions_op_Explicit_mAA54B25B681E9C597F68538D3339153E5748FB9A (RtcAudioPropertyOptions_t5E394E488DDCF996DB82E9326E71B465A4D6D23E* ___0_options, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// return options != null ? options.Handle : IntPtr.Zero;
		RtcAudioPropertyOptions_t5E394E488DDCF996DB82E9326E71B465A4D6D23E* L_0 = ___0_options;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		intptr_t L_1 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		return L_1;
	}

IL_0009:
	{
		RtcAudioPropertyOptions_t5E394E488DDCF996DB82E9326E71B465A4D6D23E* L_2 = ___0_options;
		NullCheck(L_2);
		intptr_t L_3 = L_2->___Handle_0;
		return L_3;
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
// Pico.Platform.AsrEngineInitResult Pico.Platform.SpeechService::InitAsrEngine()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SpeechService_InitAsrEngine_m34FEB1C9509F508B6E13EE6DE12FC31463AC1F45 (const RuntimeMethod* method) 
{
	{
		// return CLIB.ppf_Speech_InitAsrEngine();
		int32_t L_0;
		L_0 = CLIB_ppf_Speech_InitAsrEngine_mE4DC5D454207DDC4C1C6814D8E704CDF7AE60145(NULL);
		return L_0;
	}
}
// System.Int32 Pico.Platform.SpeechService::StartAsr(System.Boolean,System.Boolean,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SpeechService_StartAsr_m6B5E46DD7D6C9AFEC0243B8A4D32553111012E98 (bool ___0_autoStop, bool ___1_showPunctual, int32_t ___2_vadMaxDurationInSeconds, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// var option = new StartAsrOptions();
		StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F* L_0 = (StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F*)il2cpp_codegen_object_new(StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		StartAsrOptions__ctor_m9051AC9B99E34B2FA533CF775053B6BB8961A465(L_0, NULL);
		// option.SetAutoStop(autoStop);
		StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F* L_1 = L_0;
		bool L_2 = ___0_autoStop;
		NullCheck(L_1);
		StartAsrOptions_SetAutoStop_mA87C46C8228C8658306339DF20A6100479737B90(L_1, L_2, NULL);
		// option.SetShowPunctual(showPunctual);
		StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F* L_3 = L_1;
		bool L_4 = ___1_showPunctual;
		NullCheck(L_3);
		StartAsrOptions_SetShowPunctual_m08A66F2736751EDAFA614A573E4472A929AD48F7(L_3, L_4, NULL);
		// option.SetVadMaxDurationInSeconds(vadMaxDurationInSeconds);
		StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F* L_5 = L_3;
		int32_t L_6 = ___2_vadMaxDurationInSeconds;
		NullCheck(L_5);
		StartAsrOptions_SetVadMaxDurationInSeconds_mD7132FE9CAD9A57A747C78F8C231C67422054D2F(L_5, L_6, NULL);
		// return CLIB.ppf_Speech_StartAsr((IntPtr) option);
		intptr_t L_7;
		L_7 = StartAsrOptions_op_Explicit_m9AAFCEA0EFAD89ECFFD8F5F0ED0EF5425874EF63(L_5, NULL);
		int32_t L_8;
		L_8 = CLIB_ppf_Speech_StartAsr_m9F0659C938B2EB972D51DD56A21EDC2F56E4E825(L_7, NULL);
		return L_8;
	}
}
// System.Void Pico.Platform.SpeechService::StopAsr()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpeechService_StopAsr_mF55F7E675178899152017EFBE97119D969092C1F (const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_Speech_StopAsr();
		CLIB_ppf_Speech_StopAsr_m152FA1B9067EBF9B11C9423A3C9D9B93A3D3514B(NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.SpeechService::SetOnAsrResultCallback(Pico.Platform.Message`1/Handler<Pico.Platform.Models.AsrResult>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpeechService_SetOnAsrResultCallback_mAC05F506CC6124034DE524036E8D7E5A38D67C59 (Handler_tE5970BF7190FDDDFE47C25F9F98FC3037D7F753F* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Speech_OnAsrResult, handler);
		Handler_tE5970BF7190FDDDFE47C25F9F98FC3037D7F753F* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)14001), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.SpeechService::SetOnSpeechErrorCallback(Pico.Platform.Message`1/Handler<Pico.Platform.Models.SpeechError>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpeechService_SetOnSpeechErrorCallback_m7AB87F51F67E922F03AB16195A43D30986FE8940 (Handler_t4491361073BF898EF4019198FE0FA845AEA8C7C6* ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.RegisterNotifyHandler(MessageType.Notification_Speech_OnSpeechError, handler);
		Handler_t4491361073BF898EF4019198FE0FA845AEA8C7C6* L_0 = ___0_handler;
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_RegisterNotifyHandler_mED8ACEA4DA0157458B4890037F5D56902EB21015(((int32_t)14002), L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.SpeechService::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpeechService__ctor_m31B753A59C629DAFF14ED9031C3D8426D8652535 (SpeechService_t4136B8573DC4D69E06013EC67BCD1E4052C18EE9* __this, const RuntimeMethod* method) 
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
// System.Void Pico.Platform.StartAsrOptions::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartAsrOptions__ctor_m9051AC9B99E34B2FA533CF775053B6BB8961A465 (StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F* __this, const RuntimeMethod* method) 
{
	{
		// public StartAsrOptions()
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Handle = CLIB.ppf_StartAsrOptions_Create();
		intptr_t L_0;
		L_0 = CLIB_ppf_StartAsrOptions_Create_mD16FDD2ADE6427BED56C2BE226202C86731FF6B5(NULL);
		__this->___Handle_0 = L_0;
		// }
		return;
	}
}
// System.Void Pico.Platform.StartAsrOptions::SetAutoStop(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartAsrOptions_SetAutoStop_mA87C46C8228C8658306339DF20A6100479737B90 (StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_StartAsrOptions_SetAutoStop(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		bool L_1 = ___0_value;
		CLIB_ppf_StartAsrOptions_SetAutoStop_mC46EA758EB5C3935B5CF77049A28B90E54A313AE(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.StartAsrOptions::SetVadMaxDurationInSeconds(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartAsrOptions_SetVadMaxDurationInSeconds_mD7132FE9CAD9A57A747C78F8C231C67422054D2F (StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_StartAsrOptions_SetVadMaxDurationInSeconds(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		int32_t L_1 = ___0_value;
		CLIB_ppf_StartAsrOptions_SetVadMaxDurationInSeconds_m58766F2DEFA01B015B6CF08C4E664B3CB02BA244(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.StartAsrOptions::SetShowPunctual(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartAsrOptions_SetShowPunctual_m08A66F2736751EDAFA614A573E4472A929AD48F7 (StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_StartAsrOptions_SetShowPunctual(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		bool L_1 = ___0_value;
		CLIB_ppf_StartAsrOptions_SetShowPunctual_m634A7C0830075E813E254431252C8EE4741A5E8A(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.IntPtr Pico.Platform.StartAsrOptions::op_Explicit(Pico.Platform.StartAsrOptions)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t StartAsrOptions_op_Explicit_m9AAFCEA0EFAD89ECFFD8F5F0ED0EF5425874EF63 (StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F* ___0_options, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// return options != null ? options.Handle : IntPtr.Zero;
		StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F* L_0 = ___0_options;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		intptr_t L_1 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		return L_1;
	}

IL_0009:
	{
		StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F* L_2 = ___0_options;
		NullCheck(L_2);
		intptr_t L_3 = L_2->___Handle_0;
		return L_3;
	}
}
// System.Void Pico.Platform.StartAsrOptions::Finalize()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StartAsrOptions_Finalize_m2E83A925607ECC2A1AD0B912F7688757A286D4E4 (StartAsrOptions_t336161334FBFF33C9F13BC5F722DEF6EAA1A633F* __this, const RuntimeMethod* method) 
{
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_000d:
			{// begin finally (depth: 1)
				// }
				Object_Finalize_mC98C96301CCABFE00F1A7EF8E15DF507CACD42B2(__this, NULL);
				return;
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			// CLIB.ppf_StartAsrOptions_Destroy(Handle);
			intptr_t L_0 = __this->___Handle_0;
			CLIB_ppf_StartAsrOptions_Destroy_mD0E1920B99B37A0E6A111E1D37C9824F4AC7E3C6(L_0, NULL);
			goto IL_0014;
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0014:
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
// Pico.Platform.Task`1<Pico.Platform.Models.SportUserInfo> Pico.Platform.SportService::GetUserInfo()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_t1B92E95AEAE34C4D979EA9DC46E4A0B69313B747* SportService_GetUserInfo_m6D7E68028671D005F52F6326DD88031C32B090F9 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1__ctor_m663084DE28D5D98B9394EDB79C8DF0E4CCEB3CC9_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1_t1B92E95AEAE34C4D979EA9DC46E4A0B69313B747_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!CoreService.Initialized)
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		bool L_0 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___Initialized_0;
		if (L_0)
		{
			goto IL_0013;
		}
	}
	{
		// Debug.LogError(CoreService.NotInitializedError);
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		String_t* L_1 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___NotInitializedError_1;
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_1, NULL);
		// return null;
		return (Task_1_t1B92E95AEAE34C4D979EA9DC46E4A0B69313B747*)NULL;
	}

IL_0013:
	{
		// return new Task<SportUserInfo>(CLIB.ppf_Sport_GetUserInfo());
		uint64_t L_2;
		L_2 = CLIB_ppf_Sport_GetUserInfo_m2A8BA47ED2F14BD2E2870466C7780D4E4F925A47(NULL);
		Task_1_t1B92E95AEAE34C4D979EA9DC46E4A0B69313B747* L_3 = (Task_1_t1B92E95AEAE34C4D979EA9DC46E4A0B69313B747*)il2cpp_codegen_object_new(Task_1_t1B92E95AEAE34C4D979EA9DC46E4A0B69313B747_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		Task_1__ctor_m663084DE28D5D98B9394EDB79C8DF0E4CCEB3CC9(L_3, L_2, Task_1__ctor_m663084DE28D5D98B9394EDB79C8DF0E4CCEB3CC9_RuntimeMethod_var);
		return L_3;
	}
}
// Pico.Platform.Task`1<Pico.Platform.Models.SportDailySummaryList> Pico.Platform.SportService::GetDailySummary(System.DateTime,System.DateTime)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_t1B98E66164E4AE432D604C7B75AF7848981FF051* SportService_GetDailySummary_m8ED4459356732329B59B385E013E579ECB0C222E (DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___0_beginTime, DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___1_endTime, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1__ctor_mAF2B532E3BB55BD9BDA955D466B020D6C389AEE6_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1_t1B98E66164E4AE432D604C7B75AF7848981FF051_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!CoreService.Initialized)
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		bool L_0 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___Initialized_0;
		if (L_0)
		{
			goto IL_0013;
		}
	}
	{
		// Debug.LogError(CoreService.NotInitializedError);
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		String_t* L_1 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___NotInitializedError_1;
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_1, NULL);
		// return null;
		return (Task_1_t1B98E66164E4AE432D604C7B75AF7848981FF051*)NULL;
	}

IL_0013:
	{
		// return new Task<SportDailySummaryList>(CLIB.ppf_Sport_GetDailySummary(TimeUtil.DateTimeToMilliSeconds(beginTime), TimeUtil.DateTimeToMilliSeconds(endTime)));
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_2 = ___0_beginTime;
		il2cpp_codegen_runtime_class_init_inline(TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		int64_t L_3;
		L_3 = TimeUtil_DateTimeToMilliSeconds_mB80B1C7EA348F059DB520F63D61898BD07D82E53(L_2, NULL);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_4 = ___1_endTime;
		int64_t L_5;
		L_5 = TimeUtil_DateTimeToMilliSeconds_mB80B1C7EA348F059DB520F63D61898BD07D82E53(L_4, NULL);
		uint64_t L_6;
		L_6 = CLIB_ppf_Sport_GetDailySummary_m1294198CD9DA6F48D82E9161612C8BE9D554AEA5(L_3, L_5, NULL);
		Task_1_t1B98E66164E4AE432D604C7B75AF7848981FF051* L_7 = (Task_1_t1B98E66164E4AE432D604C7B75AF7848981FF051*)il2cpp_codegen_object_new(Task_1_t1B98E66164E4AE432D604C7B75AF7848981FF051_il2cpp_TypeInfo_var);
		NullCheck(L_7);
		Task_1__ctor_mAF2B532E3BB55BD9BDA955D466B020D6C389AEE6(L_7, L_6, Task_1__ctor_mAF2B532E3BB55BD9BDA955D466B020D6C389AEE6_RuntimeMethod_var);
		return L_7;
	}
}
// Pico.Platform.Task`1<Pico.Platform.Models.SportSummary> Pico.Platform.SportService::GetSummary(System.DateTime,System.DateTime)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_tB6CDA113D3E1699F4874976AC36FB7624B4F9244* SportService_GetSummary_m4F15B0CDC9E0D46EB2D5ECFBD7AFAA7A8AAE8DE2 (DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___0_beginTime, DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___1_endTime, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1__ctor_mCDB56AC9CB59A5C05526C208A7E6DBDB1AA37F66_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1_tB6CDA113D3E1699F4874976AC36FB7624B4F9244_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!CoreService.Initialized)
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		bool L_0 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___Initialized_0;
		if (L_0)
		{
			goto IL_0013;
		}
	}
	{
		// Debug.LogError(CoreService.NotInitializedError);
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		String_t* L_1 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___NotInitializedError_1;
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_1, NULL);
		// return null;
		return (Task_1_tB6CDA113D3E1699F4874976AC36FB7624B4F9244*)NULL;
	}

IL_0013:
	{
		// return new Task<SportSummary>(CLIB.ppf_Sport_GetSummary(TimeUtil.DateTimeToMilliSeconds(beginTime), TimeUtil.DateTimeToMilliSeconds(endTime)));
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_2 = ___0_beginTime;
		il2cpp_codegen_runtime_class_init_inline(TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		int64_t L_3;
		L_3 = TimeUtil_DateTimeToMilliSeconds_mB80B1C7EA348F059DB520F63D61898BD07D82E53(L_2, NULL);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_4 = ___1_endTime;
		int64_t L_5;
		L_5 = TimeUtil_DateTimeToMilliSeconds_mB80B1C7EA348F059DB520F63D61898BD07D82E53(L_4, NULL);
		uint64_t L_6;
		L_6 = CLIB_ppf_Sport_GetSummary_m55B952DC067DD8A59593BF9F070FCCA547831744(L_3, L_5, NULL);
		Task_1_tB6CDA113D3E1699F4874976AC36FB7624B4F9244* L_7 = (Task_1_tB6CDA113D3E1699F4874976AC36FB7624B4F9244*)il2cpp_codegen_object_new(Task_1_tB6CDA113D3E1699F4874976AC36FB7624B4F9244_il2cpp_TypeInfo_var);
		NullCheck(L_7);
		Task_1__ctor_mCDB56AC9CB59A5C05526C208A7E6DBDB1AA37F66(L_7, L_6, Task_1__ctor_mCDB56AC9CB59A5C05526C208A7E6DBDB1AA37F66_RuntimeMethod_var);
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
// Pico.Platform.Task`1<System.String> Pico.Platform.UserService::GetAccessToken()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF* UserService_GetAccessToken_mA024607BAB2356BDB777EDDAFF58ABE2FC774249 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1__ctor_m1CF0C62EAAB2FD4823E55B281F816BE4AD7A46DC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!CoreService.Initialized)
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		bool L_0 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___Initialized_0;
		if (L_0)
		{
			goto IL_0013;
		}
	}
	{
		// Debug.LogError(CoreService.NotInitializedError);
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		String_t* L_1 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___NotInitializedError_1;
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_1, NULL);
		// return null;
		return (Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF*)NULL;
	}

IL_0013:
	{
		// return new Task<string>(CLIB.ppf_User_GetAccessToken());
		uint64_t L_2;
		L_2 = CLIB_ppf_User_GetAccessToken_m4B8E4EA084A131250844BE9C53EC722FC06C5628(NULL);
		Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF* L_3 = (Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF*)il2cpp_codegen_object_new(Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		Task_1__ctor_m1CF0C62EAAB2FD4823E55B281F816BE4AD7A46DC(L_3, L_2, Task_1__ctor_m1CF0C62EAAB2FD4823E55B281F816BE4AD7A46DC_RuntimeMethod_var);
		return L_3;
	}
}
// Pico.Platform.Task`1<Pico.Platform.Models.OrgScopedID> Pico.Platform.UserService::GetOrgScopedID(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_tED4A061EA242D6FF39FF61442A0E7F55A6880B2E* UserService_GetOrgScopedID_m384492046692A8BB1D2329AAA500082F1DE1F2BA (String_t* ___0_userID, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1__ctor_m59D89B840C2D9E7B876A8866DCA1A7BD562B7E56_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1_tED4A061EA242D6FF39FF61442A0E7F55A6880B2E_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!CoreService.Initialized)
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		bool L_0 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___Initialized_0;
		if (L_0)
		{
			goto IL_0013;
		}
	}
	{
		// Debug.LogError(CoreService.NotInitializedError);
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		String_t* L_1 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___NotInitializedError_1;
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_1, NULL);
		// return null;
		return (Task_1_tED4A061EA242D6FF39FF61442A0E7F55A6880B2E*)NULL;
	}

IL_0013:
	{
		// return new Task<OrgScopedID>(CLIB.ppf_User_GetOrgScopedID(userID));
		String_t* L_2 = ___0_userID;
		uint64_t L_3;
		L_3 = CLIB_ppf_User_GetOrgScopedID_m6B22DE2722B232E577B9DCFF97820F487B0D676D(L_2, NULL);
		Task_1_tED4A061EA242D6FF39FF61442A0E7F55A6880B2E* L_4 = (Task_1_tED4A061EA242D6FF39FF61442A0E7F55A6880B2E*)il2cpp_codegen_object_new(Task_1_tED4A061EA242D6FF39FF61442A0E7F55A6880B2E_il2cpp_TypeInfo_var);
		NullCheck(L_4);
		Task_1__ctor_m59D89B840C2D9E7B876A8866DCA1A7BD562B7E56(L_4, L_3, Task_1__ctor_m59D89B840C2D9E7B876A8866DCA1A7BD562B7E56_RuntimeMethod_var);
		return L_4;
	}
}
// Pico.Platform.Task`1<Pico.Platform.Models.User> Pico.Platform.UserService::GetLoggedInUser()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42* UserService_GetLoggedInUser_mEF12425F8814F7C5E08382C6C5E00CEE18073E8B (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1__ctor_m322A3D30581A57328E35B1AA000C12DA27802B9B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!CoreService.Initialized)
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		bool L_0 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___Initialized_0;
		if (L_0)
		{
			goto IL_0013;
		}
	}
	{
		// Debug.LogError(CoreService.NotInitializedError);
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		String_t* L_1 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___NotInitializedError_1;
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_1, NULL);
		// return null;
		return (Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42*)NULL;
	}

IL_0013:
	{
		// return new Task<User>(CLIB.ppf_User_GetLoggedInUser());
		uint64_t L_2;
		L_2 = CLIB_ppf_User_GetLoggedInUser_m735249852E8973AC38B5117E8C481C81B3B540E0(NULL);
		Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42* L_3 = (Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42*)il2cpp_codegen_object_new(Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		Task_1__ctor_m322A3D30581A57328E35B1AA000C12DA27802B9B(L_3, L_2, Task_1__ctor_m322A3D30581A57328E35B1AA000C12DA27802B9B_RuntimeMethod_var);
		return L_3;
	}
}
// Pico.Platform.Task`1<Pico.Platform.Models.User> Pico.Platform.UserService::Get(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42* UserService_Get_mAE5D8756DD42AF1402833C9C160B65C0CB6F2D84 (String_t* ___0_userId, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1__ctor_m322A3D30581A57328E35B1AA000C12DA27802B9B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!CoreService.Initialized)
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		bool L_0 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___Initialized_0;
		if (L_0)
		{
			goto IL_0013;
		}
	}
	{
		// Debug.LogError(CoreService.NotInitializedError);
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		String_t* L_1 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___NotInitializedError_1;
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_1, NULL);
		// return null;
		return (Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42*)NULL;
	}

IL_0013:
	{
		// return new Task<User>(CLIB.ppf_User_Get(userId));
		String_t* L_2 = ___0_userId;
		uint64_t L_3;
		L_3 = CLIB_ppf_User_Get_m282DFCBEA159F8A3FCFBFCFD6735219277A45EAB(L_2, NULL);
		Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42* L_4 = (Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42*)il2cpp_codegen_object_new(Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42_il2cpp_TypeInfo_var);
		NullCheck(L_4);
		Task_1__ctor_m322A3D30581A57328E35B1AA000C12DA27802B9B(L_4, L_3, Task_1__ctor_m322A3D30581A57328E35B1AA000C12DA27802B9B_RuntimeMethod_var);
		return L_4;
	}
}
// Pico.Platform.Task`1<Pico.Platform.Models.UserList> Pico.Platform.UserService::GetFriends()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_tEFD858E38F809577D01E5C61C4E04401C1579F24* UserService_GetFriends_m58E561BDF1D435E200357F09F32DB0E23981B001 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1__ctor_m50BEB35518BC513A0C8F5CAE163C038761DDEBD7_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1_tEFD858E38F809577D01E5C61C4E04401C1579F24_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!CoreService.Initialized)
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		bool L_0 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___Initialized_0;
		if (L_0)
		{
			goto IL_0013;
		}
	}
	{
		// Debug.LogError(CoreService.NotInitializedError);
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		String_t* L_1 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___NotInitializedError_1;
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_1, NULL);
		// return null;
		return (Task_1_tEFD858E38F809577D01E5C61C4E04401C1579F24*)NULL;
	}

IL_0013:
	{
		// return new Task<UserList>(CLIB.ppf_User_GetLoggedInUserFriends());
		uint64_t L_2;
		L_2 = CLIB_ppf_User_GetLoggedInUserFriends_m7D5683CE9CCA26BE5DF700F094695DC418E50055(NULL);
		Task_1_tEFD858E38F809577D01E5C61C4E04401C1579F24* L_3 = (Task_1_tEFD858E38F809577D01E5C61C4E04401C1579F24*)il2cpp_codegen_object_new(Task_1_tEFD858E38F809577D01E5C61C4E04401C1579F24_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		Task_1__ctor_m50BEB35518BC513A0C8F5CAE163C038761DDEBD7(L_3, L_2, Task_1__ctor_m50BEB35518BC513A0C8F5CAE163C038761DDEBD7_RuntimeMethod_var);
		return L_3;
	}
}
// Pico.Platform.Task`1<Pico.Platform.Models.UserRelationResult> Pico.Platform.UserService::GetUserRelations(System.String[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_tB4B0FA80F5FD7ED902B09091C88E2146F2BAE9C1* UserService_GetUserRelations_m49C55F05FF492BD93E364974F104B1953CEFAA82 (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___0_userIds, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1__ctor_m970BDF1E00FFB8C1E8DF0B795F86CADC4D0FFAA5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1_tB4B0FA80F5FD7ED902B09091C88E2146F2BAE9C1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!CoreService.Initialized)
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		bool L_0 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___Initialized_0;
		if (L_0)
		{
			goto IL_0013;
		}
	}
	{
		// Debug.LogError(CoreService.NotInitializedError);
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		String_t* L_1 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___NotInitializedError_1;
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_1, NULL);
		// return null;
		return (Task_1_tB4B0FA80F5FD7ED902B09091C88E2146F2BAE9C1*)NULL;
	}

IL_0013:
	{
		// return new Task<UserRelationResult>(CLIB.ppf_User_GetRelations(userIds));
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_2 = ___0_userIds;
		uint64_t L_3;
		L_3 = CLIB_ppf_User_GetRelations_m2524B1C0BAF70D69E96276AFDB1DAEAFCDF54F98(L_2, NULL);
		Task_1_tB4B0FA80F5FD7ED902B09091C88E2146F2BAE9C1* L_4 = (Task_1_tB4B0FA80F5FD7ED902B09091C88E2146F2BAE9C1*)il2cpp_codegen_object_new(Task_1_tB4B0FA80F5FD7ED902B09091C88E2146F2BAE9C1_il2cpp_TypeInfo_var);
		NullCheck(L_4);
		Task_1__ctor_m970BDF1E00FFB8C1E8DF0B795F86CADC4D0FFAA5(L_4, L_3, Task_1__ctor_m970BDF1E00FFB8C1E8DF0B795F86CADC4D0FFAA5_RuntimeMethod_var);
		return L_4;
	}
}
// Pico.Platform.Task`1<Pico.Platform.Models.LaunchFriendResult> Pico.Platform.UserService::LaunchFriendRequestFlow(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_t89353573F66DF40A563FFC7023237C238E5D7F0D* UserService_LaunchFriendRequestFlow_mC06F26E01775DD3BA3A051713EDEE58E1C74643D (String_t* ___0_userId, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1__ctor_m6C02EE853BD7EA7A09FCD1178C0CC092548CD102_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1_t89353573F66DF40A563FFC7023237C238E5D7F0D_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!CoreService.Initialized)
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		bool L_0 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___Initialized_0;
		if (L_0)
		{
			goto IL_0013;
		}
	}
	{
		// Debug.LogError(CoreService.NotInitializedError);
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		String_t* L_1 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___NotInitializedError_1;
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_1, NULL);
		// return null;
		return (Task_1_t89353573F66DF40A563FFC7023237C238E5D7F0D*)NULL;
	}

IL_0013:
	{
		// return new Task<LaunchFriendResult>(CLIB.ppf_User_LaunchFriendRequestFlow(userId));
		String_t* L_2 = ___0_userId;
		uint64_t L_3;
		L_3 = CLIB_ppf_User_LaunchFriendRequestFlow_m15E2D4F598E46D37667BC00EB358F9723BCCC72D(L_2, NULL);
		Task_1_t89353573F66DF40A563FFC7023237C238E5D7F0D* L_4 = (Task_1_t89353573F66DF40A563FFC7023237C238E5D7F0D*)il2cpp_codegen_object_new(Task_1_t89353573F66DF40A563FFC7023237C238E5D7F0D_il2cpp_TypeInfo_var);
		NullCheck(L_4);
		Task_1__ctor_m6C02EE853BD7EA7A09FCD1178C0CC092548CD102(L_4, L_3, Task_1__ctor_m6C02EE853BD7EA7A09FCD1178C0CC092548CD102_RuntimeMethod_var);
		return L_4;
	}
}
// Pico.Platform.Task`1<Pico.Platform.Models.UserRoomList> Pico.Platform.UserService::GetFriendsAndRooms()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_t63D243DB7237B9BDC42B877FB86F30ABDF4C37EF* UserService_GetFriendsAndRooms_mDE3E2C69BDB6E048BF6FB43DCA356605F3658244 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1__ctor_m7C42D45457C38313FD29A5A7B8FA37EBD5C083BB_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1_t63D243DB7237B9BDC42B877FB86F30ABDF4C37EF_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!CoreService.Initialized)
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		bool L_0 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___Initialized_0;
		if (L_0)
		{
			goto IL_0013;
		}
	}
	{
		// Debug.LogError(CoreService.NotInitializedError);
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		String_t* L_1 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___NotInitializedError_1;
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_1, NULL);
		// return null;
		return (Task_1_t63D243DB7237B9BDC42B877FB86F30ABDF4C37EF*)NULL;
	}

IL_0013:
	{
		// return new Task<UserRoomList>(CLIB.ppf_User_GetLoggedInUserFriendsAndRooms());
		uint64_t L_2;
		L_2 = CLIB_ppf_User_GetLoggedInUserFriendsAndRooms_m902D49F2E864C23B23316F0DD046C9B6E68FD055(NULL);
		Task_1_t63D243DB7237B9BDC42B877FB86F30ABDF4C37EF* L_3 = (Task_1_t63D243DB7237B9BDC42B877FB86F30ABDF4C37EF*)il2cpp_codegen_object_new(Task_1_t63D243DB7237B9BDC42B877FB86F30ABDF4C37EF_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		Task_1__ctor_m7C42D45457C38313FD29A5A7B8FA37EBD5C083BB(L_3, L_2, Task_1__ctor_m7C42D45457C38313FD29A5A7B8FA37EBD5C083BB_RuntimeMethod_var);
		return L_3;
	}
}
// Pico.Platform.Task`1<Pico.Platform.Models.UserRoomList> Pico.Platform.UserService::GetNextUserAndRoomListPage(Pico.Platform.Models.UserRoomList)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_t63D243DB7237B9BDC42B877FB86F30ABDF4C37EF* UserService_GetNextUserAndRoomListPage_m00EA6281353DAEA9C7F9F227B1EF8D7743E41929 (UserRoomList_t4AA0685A4D566E046B275555AC21E1A102C16A73* ___0_list, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageArray_1_get_HasNextPage_m72A1A98F96C990D8BA6BA6E2FAA11C72813859E0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1__ctor_m7C42D45457C38313FD29A5A7B8FA37EBD5C083BB_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1_t63D243DB7237B9BDC42B877FB86F30ABDF4C37EF_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral59729EB1145C8E83047D8BBCA2C6DC8F6A082DBF);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral8586A9D31F622A392F306BE35308D8768CC6A80A);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!CoreService.Initialized)
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		bool L_0 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___Initialized_0;
		if (L_0)
		{
			goto IL_0013;
		}
	}
	{
		// Debug.LogError(CoreService.NotInitializedError);
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		String_t* L_1 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___NotInitializedError_1;
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_1, NULL);
		// return null;
		return (Task_1_t63D243DB7237B9BDC42B877FB86F30ABDF4C37EF*)NULL;
	}

IL_0013:
	{
		// if (!list.HasNextPage)
		UserRoomList_t4AA0685A4D566E046B275555AC21E1A102C16A73* L_2 = ___0_list;
		NullCheck(L_2);
		bool L_3;
		L_3 = MessageArray_1_get_HasNextPage_m72A1A98F96C990D8BA6BA6E2FAA11C72813859E0(L_2, MessageArray_1_get_HasNextPage_m72A1A98F96C990D8BA6BA6E2FAA11C72813859E0_RuntimeMethod_var);
		if (L_3)
		{
			goto IL_0027;
		}
	}
	{
		// Debug.LogWarning("GetNextUserAndRoomListPage: List has no next page");
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogWarning_m33EF1B897E0C7C6FF538989610BFAFFEF4628CA9(_stringLiteral8586A9D31F622A392F306BE35308D8768CC6A80A, NULL);
		// return null;
		return (Task_1_t63D243DB7237B9BDC42B877FB86F30ABDF4C37EF*)NULL;
	}

IL_0027:
	{
		// if (String.IsNullOrEmpty(list.NextPageParam))
		UserRoomList_t4AA0685A4D566E046B275555AC21E1A102C16A73* L_4 = ___0_list;
		NullCheck(L_4);
		String_t* L_5 = ((MessageArray_1_tBDB39162E4555FCBD64BB106117908AC8831F004*)L_4)->___NextPageParam_6;
		bool L_6;
		L_6 = String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478(L_5, NULL);
		if (!L_6)
		{
			goto IL_0040;
		}
	}
	{
		// Debug.LogWarning("GetNextUserAndRoomListPage: list.NextPageParam is empty");
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogWarning_m33EF1B897E0C7C6FF538989610BFAFFEF4628CA9(_stringLiteral59729EB1145C8E83047D8BBCA2C6DC8F6A082DBF, NULL);
		// return null;
		return (Task_1_t63D243DB7237B9BDC42B877FB86F30ABDF4C37EF*)NULL;
	}

IL_0040:
	{
		// return new Task<UserRoomList>(CLIB.ppf_User_GetNextUserAndRoomArrayPage(list.NextPageParam));
		UserRoomList_t4AA0685A4D566E046B275555AC21E1A102C16A73* L_7 = ___0_list;
		NullCheck(L_7);
		String_t* L_8 = ((MessageArray_1_tBDB39162E4555FCBD64BB106117908AC8831F004*)L_7)->___NextPageParam_6;
		uint64_t L_9;
		L_9 = CLIB_ppf_User_GetNextUserAndRoomArrayPage_m34B809096725072233997C2D085FD30289F61B8F(L_8, NULL);
		Task_1_t63D243DB7237B9BDC42B877FB86F30ABDF4C37EF* L_10 = (Task_1_t63D243DB7237B9BDC42B877FB86F30ABDF4C37EF*)il2cpp_codegen_object_new(Task_1_t63D243DB7237B9BDC42B877FB86F30ABDF4C37EF_il2cpp_TypeInfo_var);
		NullCheck(L_10);
		Task_1__ctor_m7C42D45457C38313FD29A5A7B8FA37EBD5C083BB(L_10, L_9, Task_1__ctor_m7C42D45457C38313FD29A5A7B8FA37EBD5C083BB_RuntimeMethod_var);
		return L_10;
	}
}
// Pico.Platform.Task`1<Pico.Platform.Models.UserList> Pico.Platform.UserService::GetNextUserListPage(Pico.Platform.Models.UserList)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_tEFD858E38F809577D01E5C61C4E04401C1579F24* UserService_GetNextUserListPage_m459C9EB3E0CDE4CBCAA95CA407E40D465BC82463 (UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F* ___0_list, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageArray_1_get_HasNextPage_m3E11E7F669019355A0341BB70330132A889C7709_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1__ctor_m50BEB35518BC513A0C8F5CAE163C038761DDEBD7_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1_tEFD858E38F809577D01E5C61C4E04401C1579F24_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral156065397842C897754F95F8B45CD763A37AA319);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral6B73ED795945027531E9522BB906B336CDA394F4);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!CoreService.Initialized)
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		bool L_0 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___Initialized_0;
		if (L_0)
		{
			goto IL_0013;
		}
	}
	{
		// Debug.LogError(CoreService.NotInitializedError);
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		String_t* L_1 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___NotInitializedError_1;
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_1, NULL);
		// return null;
		return (Task_1_tEFD858E38F809577D01E5C61C4E04401C1579F24*)NULL;
	}

IL_0013:
	{
		// if (!list.HasNextPage)
		UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F* L_2 = ___0_list;
		NullCheck(L_2);
		bool L_3;
		L_3 = MessageArray_1_get_HasNextPage_m3E11E7F669019355A0341BB70330132A889C7709(L_2, MessageArray_1_get_HasNextPage_m3E11E7F669019355A0341BB70330132A889C7709_RuntimeMethod_var);
		if (L_3)
		{
			goto IL_0027;
		}
	}
	{
		// Debug.LogWarning("GetNextUserListPage: List has no next page");
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogWarning_m33EF1B897E0C7C6FF538989610BFAFFEF4628CA9(_stringLiteral156065397842C897754F95F8B45CD763A37AA319, NULL);
		// return null;
		return (Task_1_tEFD858E38F809577D01E5C61C4E04401C1579F24*)NULL;
	}

IL_0027:
	{
		// if (String.IsNullOrEmpty(list.NextPageParam))
		UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F* L_4 = ___0_list;
		NullCheck(L_4);
		String_t* L_5 = ((MessageArray_1_t3FBFD71C2ED89BC1E98F61EFDB0C5C6DADE06A17*)L_4)->___NextPageParam_6;
		bool L_6;
		L_6 = String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478(L_5, NULL);
		if (!L_6)
		{
			goto IL_0040;
		}
	}
	{
		// Debug.LogWarning("GetNextUserListPage: list.NextPageParam is empty");
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogWarning_m33EF1B897E0C7C6FF538989610BFAFFEF4628CA9(_stringLiteral6B73ED795945027531E9522BB906B336CDA394F4, NULL);
		// return null;
		return (Task_1_tEFD858E38F809577D01E5C61C4E04401C1579F24*)NULL;
	}

IL_0040:
	{
		// return new Task<UserList>(CLIB.ppf_User_GetNextUserArrayPage(list.NextPageParam));
		UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F* L_7 = ___0_list;
		NullCheck(L_7);
		String_t* L_8 = ((MessageArray_1_t3FBFD71C2ED89BC1E98F61EFDB0C5C6DADE06A17*)L_7)->___NextPageParam_6;
		uint64_t L_9;
		L_9 = CLIB_ppf_User_GetNextUserArrayPage_m630DE021C106AE95F1BAA9F1026E472B231D0F83(L_8, NULL);
		Task_1_tEFD858E38F809577D01E5C61C4E04401C1579F24* L_10 = (Task_1_tEFD858E38F809577D01E5C61C4E04401C1579F24*)il2cpp_codegen_object_new(Task_1_tEFD858E38F809577D01E5C61C4E04401C1579F24_il2cpp_TypeInfo_var);
		NullCheck(L_10);
		Task_1__ctor_m50BEB35518BC513A0C8F5CAE163C038761DDEBD7(L_10, L_9, Task_1__ctor_m50BEB35518BC513A0C8F5CAE163C038761DDEBD7_RuntimeMethod_var);
		return L_10;
	}
}
// Pico.Platform.Task`1<Pico.Platform.Models.PermissionResult> Pico.Platform.UserService::GetAuthorizedPermissions()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF* UserService_GetAuthorizedPermissions_mABE79E25E883746577A6343D90EF57964B3BC12E (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1__ctor_m97DCC7BC2E162881ED2A246242E9A4C8D61C82A3_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!CoreService.Initialized)
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		bool L_0 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___Initialized_0;
		if (L_0)
		{
			goto IL_0013;
		}
	}
	{
		// Debug.LogError(CoreService.NotInitializedError);
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		String_t* L_1 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___NotInitializedError_1;
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_1, NULL);
		// return null;
		return (Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF*)NULL;
	}

IL_0013:
	{
		// return new Task<PermissionResult>(CLIB.ppf_User_GetAuthorizedPermissions());
		uint64_t L_2;
		L_2 = CLIB_ppf_User_GetAuthorizedPermissions_m6880448E60B81B9F798A4F5204F2204E46CE4601(NULL);
		Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF* L_3 = (Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF*)il2cpp_codegen_object_new(Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		Task_1__ctor_m97DCC7BC2E162881ED2A246242E9A4C8D61C82A3(L_3, L_2, Task_1__ctor_m97DCC7BC2E162881ED2A246242E9A4C8D61C82A3_RuntimeMethod_var);
		return L_3;
	}
}
// Pico.Platform.Task`1<Pico.Platform.Models.PermissionResult> Pico.Platform.UserService::RequestUserPermissions(System.String[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF* UserService_RequestUserPermissions_mFEF7C7A702416B8F5EB7F6543B33A327836C46CF (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___0_permissionList, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1__ctor_m97DCC7BC2E162881ED2A246242E9A4C8D61C82A3_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!CoreService.Initialized)
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		bool L_0 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___Initialized_0;
		if (L_0)
		{
			goto IL_0013;
		}
	}
	{
		// Debug.LogError(CoreService.NotInitializedError);
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		String_t* L_1 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___NotInitializedError_1;
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_1, NULL);
		// return null;
		return (Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF*)NULL;
	}

IL_0013:
	{
		// return new Task<PermissionResult>(CLIB.ppf_User_RequestUserPermissions(permissionList));
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_2 = ___0_permissionList;
		uint64_t L_3;
		L_3 = CLIB_ppf_User_RequestUserPermissions_m0ADE8D5D1456A820208263EDBE7BB50D1F3D6213(L_2, NULL);
		Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF* L_4 = (Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF*)il2cpp_codegen_object_new(Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF_il2cpp_TypeInfo_var);
		NullCheck(L_4);
		Task_1__ctor_m97DCC7BC2E162881ED2A246242E9A4C8D61C82A3(L_4, L_3, Task_1__ctor_m97DCC7BC2E162881ED2A246242E9A4C8D61C82A3_RuntimeMethod_var);
		return L_4;
	}
}
// Pico.Platform.Task`1<Pico.Platform.Models.EntitlementCheckResult> Pico.Platform.UserService::EntitlementCheck(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_t6577C6759208FE196021557BB439FE81946FDB36* UserService_EntitlementCheck_mEABCDD79004691CC9F6499C2CB9A42D06BA34625 (bool ___0_killApp, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1__ctor_mFAD053AE97133C07CA97D23B1899267A85F7C677_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1_t6577C6759208FE196021557BB439FE81946FDB36_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!CoreService.Initialized)
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		bool L_0 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___Initialized_0;
		if (L_0)
		{
			goto IL_0013;
		}
	}
	{
		// Debug.LogError(CoreService.NotInitializedError);
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		String_t* L_1 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___NotInitializedError_1;
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_1, NULL);
		// return null;
		return (Task_1_t6577C6759208FE196021557BB439FE81946FDB36*)NULL;
	}

IL_0013:
	{
		// return new Task<EntitlementCheckResult>(CLIB.ppf_User_EntitlementCheck(killApp));
		bool L_2 = ___0_killApp;
		uint64_t L_3;
		L_3 = CLIB_ppf_User_EntitlementCheck_mAC2BD7051DB1F53018404540E98BBB8A5675EEF7(L_2, NULL);
		Task_1_t6577C6759208FE196021557BB439FE81946FDB36* L_4 = (Task_1_t6577C6759208FE196021557BB439FE81946FDB36*)il2cpp_codegen_object_new(Task_1_t6577C6759208FE196021557BB439FE81946FDB36_il2cpp_TypeInfo_var);
		NullCheck(L_4);
		Task_1__ctor_mFAD053AE97133C07CA97D23B1899267A85F7C677(L_4, L_3, Task_1__ctor_mFAD053AE97133C07CA97D23B1899267A85F7C677_RuntimeMethod_var);
		return L_4;
	}
}
// Pico.Platform.Task`1<System.String> Pico.Platform.UserService::GetIdToken()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF* UserService_GetIdToken_m545D9D1766EEE44CB063972F6C20E2E5ACBD8A7D (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1__ctor_m1CF0C62EAAB2FD4823E55B281F816BE4AD7A46DC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (!CoreService.Initialized)
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		bool L_0 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___Initialized_0;
		if (L_0)
		{
			goto IL_0013;
		}
	}
	{
		// Debug.LogError(CoreService.NotInitializedError);
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		String_t* L_1 = ((CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_StaticFields*)il2cpp_codegen_static_fields_for(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var))->___NotInitializedError_1;
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_1, NULL);
		// return null;
		return (Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF*)NULL;
	}

IL_0013:
	{
		// return new Task<string>(CLIB.ppf_User_GetIdToken());
		uint64_t L_2;
		L_2 = CLIB_ppf_User_GetIdToken_m66CB8D500505BAC1F462B2C8672030BF54F2AA63(NULL);
		Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF* L_3 = (Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF*)il2cpp_codegen_object_new(Task_1_t25E59609375A87704F09DB2AA51B13C8D17A44DF_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		Task_1__ctor_m1CF0C62EAAB2FD4823E55B281F816BE4AD7A46DC(L_3, L_2, Task_1__ctor_m1CF0C62EAAB2FD4823E55B281F816BE4AD7A46DC_RuntimeMethod_var);
		return L_3;
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
// System.Void Pico.Platform.Framework.Runner::RegisterGameObject()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Runner_RegisterGameObject_mA4759FDBE99AFA80772C7286EEFE57409EF92248 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_AddComponent_TisRunner_tB8E78BC8FEC1129C330C7EF44FE5BBFC57BFB7B8_m274D6F612B4E1E560945FD2406F657DBE0060979_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_GetComponent_TisRunner_tB8E78BC8FEC1129C330C7EF44FE5BBFC57BFB7B8_m02D34C860CE1EDFBEE672B22BBD2AD9E6B55DEA9_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral4092B25B116FA20453318CF2C73A263E43DCD2AB);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* V_1 = NULL;
	{
		// var name = "Pico.Platform.Runner";
		V_0 = _stringLiteral4092B25B116FA20453318CF2C73A263E43DCD2AB;
		// GameObject g = GameObject.Find(name);
		String_t* L_0 = V_0;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_1;
		L_1 = GameObject_Find_m7A669B4EEC2617AB82F6E3FF007CDCD9F21DB300(L_0, NULL);
		V_1 = L_1;
		// if (g == null)
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_2 = V_1;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_3;
		L_3 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_2, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_3)
		{
			goto IL_001d;
		}
	}
	{
		// g = new GameObject(name);
		String_t* L_4 = V_0;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_5 = (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*)il2cpp_codegen_object_new(GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var);
		NullCheck(L_5);
		GameObject__ctor_m37D512B05D292F954792225E6C6EEE95293A9B88(L_5, L_4, NULL);
		V_1 = L_5;
	}

IL_001d:
	{
		// if (g.GetComponent<Runner>() == null)
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_6 = V_1;
		NullCheck(L_6);
		Runner_tB8E78BC8FEC1129C330C7EF44FE5BBFC57BFB7B8* L_7;
		L_7 = GameObject_GetComponent_TisRunner_tB8E78BC8FEC1129C330C7EF44FE5BBFC57BFB7B8_m02D34C860CE1EDFBEE672B22BBD2AD9E6B55DEA9(L_6, GameObject_GetComponent_TisRunner_tB8E78BC8FEC1129C330C7EF44FE5BBFC57BFB7B8_m02D34C860CE1EDFBEE672B22BBD2AD9E6B55DEA9_RuntimeMethod_var);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_8;
		L_8 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_7, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_8)
		{
			goto IL_0032;
		}
	}
	{
		// g.AddComponent<Runner>();
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_9 = V_1;
		NullCheck(L_9);
		Runner_tB8E78BC8FEC1129C330C7EF44FE5BBFC57BFB7B8* L_10;
		L_10 = GameObject_AddComponent_TisRunner_tB8E78BC8FEC1129C330C7EF44FE5BBFC57BFB7B8_m274D6F612B4E1E560945FD2406F657DBE0060979(L_9, GameObject_AddComponent_TisRunner_tB8E78BC8FEC1129C330C7EF44FE5BBFC57BFB7B8_m274D6F612B4E1E560945FD2406F657DBE0060979_RuntimeMethod_var);
	}

IL_0032:
	{
		// }
		return;
	}
}
// System.Void Pico.Platform.Framework.Runner::Awake()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Runner_Awake_mE245DB952642BE6BAE9E2C57DB0B7B48EF1CA069 (Runner_tB8E78BC8FEC1129C330C7EF44FE5BBFC57BFB7B8* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// DontDestroyOnLoad(gameObject);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0;
		L_0 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(__this, NULL);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		Object_DontDestroyOnLoad_m4B70C3AEF886C176543D1295507B6455C9DCAEA7(L_0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.Framework.Runner::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Runner_Update_m99603550489B5FDFCA822D4540BCF721D6A4FCDA (Runner_tB8E78BC8FEC1129C330C7EF44FE5BBFC57BFB7B8* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.ProcessMessages();
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_ProcessMessages_m7C7CF1ACF44351564A132E7D90171E90E0FFF932(0, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.Framework.Runner::OnApplicationQuit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Runner_OnApplicationQuit_mA637DA934244EB4CACAE996A3B07E0CC20449513 (Runner_tB8E78BC8FEC1129C330C7EF44FE5BBFC57BFB7B8* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Looper.Clear();
		il2cpp_codegen_runtime_class_init_inline(Looper_t55865921F88FD546B4F2DA0211A39072EB73A4A8_il2cpp_TypeInfo_var);
		Looper_Clear_m0DA1691ED55DF49956837BAC3D0885DBE57AA21C(NULL);
		// if (Application.isEditor || Application.platform == RuntimePlatform.WindowsPlayer || Application.platform == RuntimePlatform.WindowsEditor)
		bool L_0;
		L_0 = Application_get_isEditor_mEAC51E3ACE6DCE438087FB14BD75A3C219D354D0(NULL);
		if (L_0)
		{
			goto IL_001c;
		}
	}
	{
		int32_t L_1;
		L_1 = Application_get_platform_m59EF7D6155D18891B24767F83F388160B1FF2138(NULL);
		if ((((int32_t)L_1) == ((int32_t)2)))
		{
			goto IL_001c;
		}
	}
	{
		int32_t L_2;
		L_2 = Application_get_platform_m59EF7D6155D18891B24767F83F388160B1FF2138(NULL);
		if ((!(((uint32_t)L_2) == ((uint32_t)7))))
		{
			goto IL_0022;
		}
	}

IL_001c:
	{
		// CLIB.ppf_PcUnInitialize();
		int32_t L_3;
		L_3 = CLIB_ppf_PcUnInitialize_m7074DC685E62F923952DB2D230FDD635EFCEFFB5(NULL);
	}

IL_0022:
	{
		// }
		return;
	}
}
// System.Void Pico.Platform.Framework.Runner::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Runner__ctor_m46CE8B1B10B3CDC8BCFE5FA70CECD9875DBA66A5 (Runner_tB8E78BC8FEC1129C330C7EF44FE5BBFC57BFB7B8* __this, const RuntimeMethod* method) 
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
// System.Void Pico.Platform.Models.Error::.ctor(System.Int32,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Error__ctor_mD086D4A119466BCDA32BA36115D07F32E434AA23 (Error_t3CA63648FA025A8FBA63EA102526BE2F757CAF88* __this, int32_t ___0_code, String_t* ___1_msg, const RuntimeMethod* method) 
{
	{
		// public Error(int code, string msg)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// this.Code = code;
		int32_t L_0 = ___0_code;
		__this->___Code_0 = L_0;
		// this.Message = msg;
		String_t* L_1 = ___1_msg;
		__this->___Message_1 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Message_1), (void*)L_1);
		// }
		return;
	}
}
// System.Void Pico.Platform.Models.Error::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Error__ctor_m8052B65BEB2FF3B17140BD95A28E15C52627B657 (Error_t3CA63648FA025A8FBA63EA102526BE2F757CAF88* __this, intptr_t ___0_handle, const RuntimeMethod* method) 
{
	{
		// public Error(IntPtr handle)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// this.Code = CLIB.ppf_Error_GetCode(handle);
		intptr_t L_0 = ___0_handle;
		int32_t L_1;
		L_1 = CLIB_ppf_Error_GetCode_m83CDC4F4594220EB3E1728EC2A12C0A97C1DF726(L_0, NULL);
		__this->___Code_0 = L_1;
		// this.Message = CLIB.ppf_Error_GetMessage(handle);
		intptr_t L_2 = ___0_handle;
		String_t* L_3;
		L_3 = CLIB_ppf_Error_GetMessage_m67E801205964BF67CCAB45CAB6EEED1CF1569EE3(L_2, NULL);
		__this->___Message_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Message_1), (void*)L_3);
		// }
		return;
	}
}
// System.String Pico.Platform.Models.Error::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Error_ToString_mB42DDE26A6A583053A817900B8D40C417C17BA30 (Error_t3CA63648FA025A8FBA63EA102526BE2F757CAF88* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD23483827499BCEE53BD792FEB5BBB36D3A5E63A);
		s_Il2CppMethodInitialized = true;
	}
	{
		// return $"Error(Code={this.Code},Message={this.Message})";
		int32_t L_0 = __this->___Code_0;
		int32_t L_1 = L_0;
		RuntimeObject* L_2 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_1);
		String_t* L_3 = __this->___Message_1;
		String_t* L_4;
		L_4 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteralD23483827499BCEE53BD792FEB5BBB36D3A5E63A, L_2, L_3, NULL);
		return L_4;
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
// System.Void Pico.Platform.Models.AchievementUpdate::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AchievementUpdate__ctor_m0C98395F38AA4DA2620A4B6B97E47B06E1C5E835 (AchievementUpdate_t41C493D095A1BB1BFC2C4BB0A17696AB038C8474* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public AchievementUpdate(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// JustUnlocked = CLIB.ppf_AchievementUpdate_GetJustUnlocked(o);
		intptr_t L_0 = ___0_o;
		bool L_1;
		L_1 = CLIB_ppf_AchievementUpdate_GetJustUnlocked_m649313BA69DC60BF18A61930E31805AC67E98399(L_0, NULL);
		__this->___JustUnlocked_0 = L_1;
		// Name = CLIB.ppf_AchievementUpdate_GetName(o);
		intptr_t L_2 = ___0_o;
		String_t* L_3;
		L_3 = CLIB_ppf_AchievementUpdate_GetName_m74D11D889569EA272F04A388E3067B305940D4BA(L_2, NULL);
		__this->___Name_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Name_1), (void*)L_3);
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
// System.Void Pico.Platform.Models.AchievementDefinition::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AchievementDefinition__ctor_mBFA904DECEC666C753BB00AFBC500B34BDB73A65 (AchievementDefinition_t09D5E334A9AF0321426DB09B4B36E72626423019* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public AchievementDefinition(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Type = CLIB.ppf_AchievementDefinition_GetType(o);
		intptr_t L_0 = ___0_o;
		int32_t L_1;
		L_1 = CLIB_ppf_AchievementDefinition_GetType_m9ED9C6E33230099A352866C55612557A86CD8E76(L_0, NULL);
		__this->___Type_0 = L_1;
		// Name = CLIB.ppf_AchievementDefinition_GetName(o);
		intptr_t L_2 = ___0_o;
		String_t* L_3;
		L_3 = CLIB_ppf_AchievementDefinition_GetName_m40AC711F58D6D47429F62626D6E530D233E998C4(L_2, NULL);
		__this->___Name_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Name_1), (void*)L_3);
		// BitfieldLength = CLIB.ppf_AchievementDefinition_GetBitfieldLength(o);
		intptr_t L_4 = ___0_o;
		uint32_t L_5;
		L_5 = CLIB_ppf_AchievementDefinition_GetBitfieldLength_m9ABE1530AF84F78881367F12E2E462F64B00EB80(L_4, NULL);
		__this->___BitfieldLength_2 = L_5;
		// Target = CLIB.ppf_AchievementDefinition_GetTarget(o);
		intptr_t L_6 = ___0_o;
		int64_t L_7;
		L_7 = CLIB_ppf_AchievementDefinition_GetTarget_mDB8C95FE116B50EEE4E5440E341878379AA092C4(L_6, NULL);
		__this->___Target_3 = L_7;
		// Description = CLIB.ppf_AchievementDefinition_GetDescription(o);
		intptr_t L_8 = ___0_o;
		String_t* L_9;
		L_9 = CLIB_ppf_AchievementDefinition_GetDescription_m5B17D99559144012DBABC08D342B5DD54DFD2162(L_8, NULL);
		__this->___Description_4 = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Description_4), (void*)L_9);
		// Title = CLIB.ppf_AchievementDefinition_GetTitle(o);
		intptr_t L_10 = ___0_o;
		String_t* L_11;
		L_11 = CLIB_ppf_AchievementDefinition_GetTitle_m269BD7513E21E364284135C41D4EDDCC94D22C09(L_10, NULL);
		__this->___Title_5 = L_11;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Title_5), (void*)L_11);
		// IsArchived = CLIB.ppf_AchievementDefinition_IsArchived(o);
		intptr_t L_12 = ___0_o;
		bool L_13;
		L_13 = CLIB_ppf_AchievementDefinition_IsArchived_mE1F890443D813FEF7A395BC7864C8BEFBDB4C73D(L_12, NULL);
		__this->___IsArchived_6 = L_13;
		// IsSecret = CLIB.ppf_AchievementDefinition_IsSecret(o);
		intptr_t L_14 = ___0_o;
		bool L_15;
		L_15 = CLIB_ppf_AchievementDefinition_IsSecret_mB164028EA11B9DD095C58CB35E1E88E43056F23D(L_14, NULL);
		__this->___IsSecret_7 = L_15;
		// ID = CLIB.ppf_AchievementDefinition_GetID(o);
		intptr_t L_16 = ___0_o;
		uint64_t L_17;
		L_17 = CLIB_ppf_AchievementDefinition_GetID_m13BE35631301DF777173A6EC78812006AEFD64A6(L_16, NULL);
		__this->___ID_8 = L_17;
		// UnlockedDescription = CLIB.ppf_AchievementDefinition_GetUnlockedDescription(o);
		intptr_t L_18 = ___0_o;
		String_t* L_19;
		L_19 = CLIB_ppf_AchievementDefinition_GetUnlockedDescription_m237E276A6D957899D343541C7D68432B9CE2C595(L_18, NULL);
		__this->___UnlockedDescription_9 = L_19;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___UnlockedDescription_9), (void*)L_19);
		// WritePolicy = CLIB.ppf_AchievementDefinition_GetWritePolicy(o);
		intptr_t L_20 = ___0_o;
		int32_t L_21;
		L_21 = CLIB_ppf_AchievementDefinition_GetWritePolicy_m68421AA81D7BF8C02FE42377293DDCE8B9F27C65(L_20, NULL);
		__this->___WritePolicy_10 = L_21;
		// LockedImageURL = CLIB.ppf_AchievementDefinition_GetLockedImageURL(o);
		intptr_t L_22 = ___0_o;
		String_t* L_23;
		L_23 = CLIB_ppf_AchievementDefinition_GetLockedImageURL_mC21FCE13618FE80315D9FE5849F2111E5A8CD045(L_22, NULL);
		__this->___LockedImageURL_11 = L_23;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___LockedImageURL_11), (void*)L_23);
		// UnlockedImageURL = CLIB.ppf_AchievementDefinition_GetUnlockedImageURL(o);
		intptr_t L_24 = ___0_o;
		String_t* L_25;
		L_25 = CLIB_ppf_AchievementDefinition_GetUnlockedImageURL_mCD98CBABA4DBD7899BF2D6997CB8692029CB8FDF(L_24, NULL);
		__this->___UnlockedImageURL_12 = L_25;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___UnlockedImageURL_12), (void*)L_25);
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
// System.Void Pico.Platform.Models.AchievementDefinitionList::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AchievementDefinitionList__ctor_m420118BDD718EED34F4A144D5838A22CD306920F (AchievementDefinitionList_t8C4BD92DEDBC06F39E7584124E90000B86B41744* __this, intptr_t ___0_a, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AchievementDefinition_t09D5E334A9AF0321426DB09B4B36E72626423019_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m7817B44F55F4B07BD59D677CB6CAD10D578EAC86_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_set_Capacity_mD3BF3BBF9B8537037A4A49B234555D9FDC3C7F1E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageArray_1__ctor_m7E276C8FEE63D2AA74F36394E1EBE4DA877D36C4_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&String_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB7C45DD316C68ABF3429C20058C2981C652192F2);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	uint32_t V_1 = 0;
	AchievementDefinitionList_t8C4BD92DEDBC06F39E7584124E90000B86B41744* G_B5_0 = NULL;
	AchievementDefinitionList_t8C4BD92DEDBC06F39E7584124E90000B86B41744* G_B4_0 = NULL;
	String_t* G_B6_0 = NULL;
	AchievementDefinitionList_t8C4BD92DEDBC06F39E7584124E90000B86B41744* G_B6_1 = NULL;
	{
		// public AchievementDefinitionList(IntPtr a)
		MessageArray_1__ctor_m7E276C8FEE63D2AA74F36394E1EBE4DA877D36C4(__this, MessageArray_1__ctor_m7E276C8FEE63D2AA74F36394E1EBE4DA877D36C4_RuntimeMethod_var);
		// TotalSize = (ulong) CLIB.ppf_AchievementDefinitionArray_GetTotalSize(a);
		intptr_t L_0 = ___0_a;
		uintptr_t L_1;
		L_1 = CLIB_ppf_AchievementDefinitionArray_GetTotalSize_mF31F7BDA19A5EA6C45A634BF599151A0463080F1(L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint64_t L_2;
		L_2 = UIntPtr_op_Explicit_mC39E70F0324C1C514A3044790BC19C5FC4C58E1C(L_1, NULL);
		__this->___TotalSize_8 = L_2;
		// var count = (int) CLIB.ppf_AchievementDefinitionArray_GetSize(a);
		intptr_t L_3 = ___0_a;
		uintptr_t L_4;
		L_4 = CLIB_ppf_AchievementDefinitionArray_GetSize_m51F7C01149B2A39AC0283478E501E55EC399BB6E(L_3, NULL);
		uint32_t L_5;
		L_5 = UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8(L_4, NULL);
		V_0 = L_5;
		// this.Capacity = count;
		int32_t L_6 = V_0;
		List_1_set_Capacity_mD3BF3BBF9B8537037A4A49B234555D9FDC3C7F1E(__this, L_6, List_1_set_Capacity_mD3BF3BBF9B8537037A4A49B234555D9FDC3C7F1E_RuntimeMethod_var);
		// for (uint i = 0; i < count; i++)
		V_1 = 0;
		goto IL_0049;
	}

IL_002e:
	{
		// this.Add(new AchievementDefinition(CLIB.ppf_AchievementDefinitionArray_GetElement(a, (UIntPtr) i)));
		intptr_t L_7 = ___0_a;
		uint32_t L_8 = V_1;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_9;
		L_9 = UIntPtr_op_Explicit_mD94DCD8965DD2E7D5A3370A04CCEDBE5937C078C(L_8, NULL);
		intptr_t L_10;
		L_10 = CLIB_ppf_AchievementDefinitionArray_GetElement_m1EB6B1FB8C5A866418BA5CFA4F3C7D4B8BA373A8(L_7, L_9, NULL);
		AchievementDefinition_t09D5E334A9AF0321426DB09B4B36E72626423019* L_11 = (AchievementDefinition_t09D5E334A9AF0321426DB09B4B36E72626423019*)il2cpp_codegen_object_new(AchievementDefinition_t09D5E334A9AF0321426DB09B4B36E72626423019_il2cpp_TypeInfo_var);
		NullCheck(L_11);
		AchievementDefinition__ctor_mBFA904DECEC666C753BB00AFBC500B34BDB73A65(L_11, L_10, NULL);
		List_1_Add_m7817B44F55F4B07BD59D677CB6CAD10D578EAC86_inline(__this, L_11, List_1_Add_m7817B44F55F4B07BD59D677CB6CAD10D578EAC86_RuntimeMethod_var);
		// for (uint i = 0; i < count; i++)
		uint32_t L_12 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add((int32_t)L_12, 1));
	}

IL_0049:
	{
		// for (uint i = 0; i < count; i++)
		uint32_t L_13 = V_1;
		int32_t L_14 = V_0;
		if ((((int64_t)((int64_t)(uint64_t)L_13)) < ((int64_t)((int64_t)L_14))))
		{
			goto IL_002e;
		}
	}
	{
		// NextPageParam = CLIB.ppf_AchievementDefinitionArray_HasNextPage(a) ? "true" : string.Empty;
		intptr_t L_15 = ___0_a;
		bool L_16;
		L_16 = CLIB_ppf_AchievementDefinitionArray_HasNextPage_m263DA3AD8437FE234FDCB5B36AC5DE1D990DB07F(L_15, NULL);
		G_B4_0 = __this;
		if (L_16)
		{
			G_B5_0 = __this;
			goto IL_005f;
		}
	}
	{
		String_t* L_17 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->___Empty_6;
		G_B6_0 = L_17;
		G_B6_1 = G_B4_0;
		goto IL_0064;
	}

IL_005f:
	{
		G_B6_0 = _stringLiteralB7C45DD316C68ABF3429C20058C2981C652192F2;
		G_B6_1 = G_B5_0;
	}

IL_0064:
	{
		NullCheck(G_B6_1);
		((MessageArray_1_t007C8F0F960A812D5EBEBD1E0DEB87A40D9F0051*)G_B6_1)->___NextPageParam_6 = G_B6_0;
		Il2CppCodeGenWriteBarrier((void**)(&((MessageArray_1_t007C8F0F960A812D5EBEBD1E0DEB87A40D9F0051*)G_B6_1)->___NextPageParam_6), (void*)G_B6_0);
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
// System.Void Pico.Platform.Models.AchievementProgress::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AchievementProgress__ctor_m595AB23BF0591ECEAD689D530D125C5819277357 (AchievementProgress_t1E252101294D86D61BE435D76B192BE5E85F67DB* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	uint32_t V_0 = 0;
	uint64_t V_1 = 0;
	{
		// public AchievementProgress(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// ID = CLIB.ppf_AchievementProgress_GetID(o);
		intptr_t L_0 = ___0_o;
		uint64_t L_1;
		L_1 = CLIB_ppf_AchievementProgress_GetID_m9032B19F4708D4A29D538FD11C92BB5A1EBC6F2B(L_0, NULL);
		__this->___ID_0 = L_1;
		// Bitfield = CLIB.ppf_AchievementProgress_GetBitfield(o);
		intptr_t L_2 = ___0_o;
		String_t* L_3;
		L_3 = CLIB_ppf_AchievementProgress_GetBitfield_mAC09D75110C5E5B0DA12BA99F1DE7A8C22A4A8A3(L_2, NULL);
		__this->___Bitfield_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Bitfield_1), (void*)L_3);
		// Count = CLIB.ppf_AchievementProgress_GetCount(o);
		intptr_t L_4 = ___0_o;
		int64_t L_5;
		L_5 = CLIB_ppf_AchievementProgress_GetCount_m00A61E88B3CA7923FA350A477ECA37C540C1D330(L_4, NULL);
		__this->___Count_2 = L_5;
		// IsUnlocked = CLIB.ppf_AchievementProgress_GetIsUnlocked(o);
		intptr_t L_6 = ___0_o;
		bool L_7;
		L_7 = CLIB_ppf_AchievementProgress_GetIsUnlocked_mFC57F2A6EDC67632044956C1F484E7CDDA82C4C5(L_6, NULL);
		__this->___IsUnlocked_3 = L_7;
		// Name = CLIB.ppf_AchievementProgress_GetName(o);
		intptr_t L_8 = ___0_o;
		String_t* L_9;
		L_9 = CLIB_ppf_AchievementProgress_GetName_m6DE79723249AC5DB4C0A591667D1F83B94337421(L_8, NULL);
		__this->___Name_4 = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Name_4), (void*)L_9);
		// uint size = CLIB.ppf_AchievementProgress_GetExtraDataLength(o);
		intptr_t L_10 = ___0_o;
		uint32_t L_11;
		L_11 = CLIB_ppf_AchievementProgress_GetExtraDataLength_mA6AC4C1BF07A30402E6486948D83B3D1F07C2547(L_10, NULL);
		V_0 = L_11;
		// ExtraData = new byte[size];
		uint32_t L_12 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_13 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)L_12);
		__this->___ExtraData_6 = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___ExtraData_6), (void*)L_13);
		// Marshal.Copy(CLIB.ppf_AchievementProgress_GetExtraData(o), ExtraData, 0, (int) size);
		intptr_t L_14 = ___0_o;
		intptr_t L_15;
		L_15 = CLIB_ppf_AchievementProgress_GetExtraData_m89E77878CDDD6408578057D03DCBF302C238FF6F(L_14, NULL);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_16 = __this->___ExtraData_6;
		uint32_t L_17 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		Marshal_Copy_mF7402FFDB520EA1B8D1C32B368DBEE4B13F1BE77(L_15, L_16, 0, L_17, NULL);
		// var unlockTime = CLIB.ppf_AchievementProgress_GetUnlockTime(o);
		intptr_t L_18 = ___0_o;
		uint64_t L_19;
		L_19 = CLIB_ppf_AchievementProgress_GetUnlockTime_mC0337111967A8F1E297D7B5F2C0FE3374A5AEDA2(L_18, NULL);
		V_1 = L_19;
		// if (unlockTime != 0)
		uint64_t L_20 = V_1;
		if (!L_20)
		{
			goto IL_007e;
		}
	}
	{
		// UnlockTime = TimeUtil.SecondsToDateTime((long) unlockTime);
		uint64_t L_21 = V_1;
		il2cpp_codegen_runtime_class_init_inline(TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_22;
		L_22 = TimeUtil_SecondsToDateTime_m5DC84ED0EEB5AB8AAF833B2F5FF5E9F075C165F4(L_21, NULL);
		__this->___UnlockTime_5 = L_22;
	}

IL_007e:
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
// System.Void Pico.Platform.Models.AchievementProgressList::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AchievementProgressList__ctor_mBFB8FA3C17CE8B41127F2AADCA83A4FC43650F5B (AchievementProgressList_t5C10551DC794BBA8F5FF05832B2D044B40447504* __this, intptr_t ___0_a, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AchievementProgress_t1E252101294D86D61BE435D76B192BE5E85F67DB_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mF7A5FDE71163AB620C0E8DB3CF2D72A13B43ED19_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_set_Capacity_mBC09D6DE59BD632D853F41ACEA81571B2F8CBAC6_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageArray_1__ctor_m3BC499DB56D4BA1111B6D6E1C8CB126A69677139_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&String_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB7C45DD316C68ABF3429C20058C2981C652192F2);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	uint32_t V_1 = 0;
	AchievementProgressList_t5C10551DC794BBA8F5FF05832B2D044B40447504* G_B5_0 = NULL;
	AchievementProgressList_t5C10551DC794BBA8F5FF05832B2D044B40447504* G_B4_0 = NULL;
	String_t* G_B6_0 = NULL;
	AchievementProgressList_t5C10551DC794BBA8F5FF05832B2D044B40447504* G_B6_1 = NULL;
	{
		// public AchievementProgressList(IntPtr a)
		MessageArray_1__ctor_m3BC499DB56D4BA1111B6D6E1C8CB126A69677139(__this, MessageArray_1__ctor_m3BC499DB56D4BA1111B6D6E1C8CB126A69677139_RuntimeMethod_var);
		// TotalSize = (ulong) CLIB.ppf_AchievementProgressArray_GetTotalSize(a);
		intptr_t L_0 = ___0_a;
		uintptr_t L_1;
		L_1 = CLIB_ppf_AchievementProgressArray_GetTotalSize_mDB5D88F1D417F36320E57CD41FBD6243D94B136D(L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint64_t L_2;
		L_2 = UIntPtr_op_Explicit_mC39E70F0324C1C514A3044790BC19C5FC4C58E1C(L_1, NULL);
		__this->___TotalSize_8 = L_2;
		// var count = (int) CLIB.ppf_AchievementProgressArray_GetSize(a);
		intptr_t L_3 = ___0_a;
		uintptr_t L_4;
		L_4 = CLIB_ppf_AchievementProgressArray_GetSize_mE6301BFD7F2C556E00E0E09823E6B41609624872(L_3, NULL);
		uint32_t L_5;
		L_5 = UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8(L_4, NULL);
		V_0 = L_5;
		// this.Capacity = count;
		int32_t L_6 = V_0;
		List_1_set_Capacity_mBC09D6DE59BD632D853F41ACEA81571B2F8CBAC6(__this, L_6, List_1_set_Capacity_mBC09D6DE59BD632D853F41ACEA81571B2F8CBAC6_RuntimeMethod_var);
		// for (uint i = 0; i < count; i++)
		V_1 = 0;
		goto IL_0049;
	}

IL_002e:
	{
		// this.Add(new AchievementProgress(CLIB.ppf_AchievementProgressArray_GetElement(a, (UIntPtr) i)));
		intptr_t L_7 = ___0_a;
		uint32_t L_8 = V_1;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_9;
		L_9 = UIntPtr_op_Explicit_mD94DCD8965DD2E7D5A3370A04CCEDBE5937C078C(L_8, NULL);
		intptr_t L_10;
		L_10 = CLIB_ppf_AchievementProgressArray_GetElement_mD73CB92CE71EC97799808766C5138E090CB1C639(L_7, L_9, NULL);
		AchievementProgress_t1E252101294D86D61BE435D76B192BE5E85F67DB* L_11 = (AchievementProgress_t1E252101294D86D61BE435D76B192BE5E85F67DB*)il2cpp_codegen_object_new(AchievementProgress_t1E252101294D86D61BE435D76B192BE5E85F67DB_il2cpp_TypeInfo_var);
		NullCheck(L_11);
		AchievementProgress__ctor_m595AB23BF0591ECEAD689D530D125C5819277357(L_11, L_10, NULL);
		List_1_Add_mF7A5FDE71163AB620C0E8DB3CF2D72A13B43ED19_inline(__this, L_11, List_1_Add_mF7A5FDE71163AB620C0E8DB3CF2D72A13B43ED19_RuntimeMethod_var);
		// for (uint i = 0; i < count; i++)
		uint32_t L_12 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add((int32_t)L_12, 1));
	}

IL_0049:
	{
		// for (uint i = 0; i < count; i++)
		uint32_t L_13 = V_1;
		int32_t L_14 = V_0;
		if ((((int64_t)((int64_t)(uint64_t)L_13)) < ((int64_t)((int64_t)L_14))))
		{
			goto IL_002e;
		}
	}
	{
		// NextPageParam = CLIB.ppf_AchievementProgressArray_HasNextPage(a) ? "true" : string.Empty;
		intptr_t L_15 = ___0_a;
		bool L_16;
		L_16 = CLIB_ppf_AchievementProgressArray_HasNextPage_mDFE3A23DCFA732521F82F1BF92AA1A38F350980F(L_15, NULL);
		G_B4_0 = __this;
		if (L_16)
		{
			G_B5_0 = __this;
			goto IL_005f;
		}
	}
	{
		String_t* L_17 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->___Empty_6;
		G_B6_0 = L_17;
		G_B6_1 = G_B4_0;
		goto IL_0064;
	}

IL_005f:
	{
		G_B6_0 = _stringLiteralB7C45DD316C68ABF3429C20058C2981C652192F2;
		G_B6_1 = G_B5_0;
	}

IL_0064:
	{
		NullCheck(G_B6_1);
		((MessageArray_1_tA2FC832E9F92BC2639E48F182ED14B04435430CA*)G_B6_1)->___NextPageParam_6 = G_B6_0;
		Il2CppCodeGenWriteBarrier((void**)(&((MessageArray_1_tA2FC832E9F92BC2639E48F182ED14B04435430CA*)G_B6_1)->___NextPageParam_6), (void*)G_B6_0);
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
// System.Void Pico.Platform.Models.LaunchDetails::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LaunchDetails__ctor_m21F671411766F6DD49D7B258CCB07DCC0547E8C2 (LaunchDetails_t83DFB7E65E221A238FA66531C7C470C75FFACE21* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public LaunchDetails(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// DeeplinkMessage = CLIB.ppf_LaunchDetails_GetDeeplinkMessage(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_LaunchDetails_GetDeeplinkMessage_m1ED848F21AC964F7A965CD9339D07F9DF8EE321F(L_0, NULL);
		__this->___DeeplinkMessage_1 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___DeeplinkMessage_1), (void*)L_1);
		// DestinationApiName = CLIB.ppf_LaunchDetails_GetDestinationApiName(o);
		intptr_t L_2 = ___0_o;
		String_t* L_3;
		L_3 = CLIB_ppf_LaunchDetails_GetDestinationApiName_m2EA9533CA6339133DD1BA2E521A7A5EC0EE50227(L_2, NULL);
		__this->___DestinationApiName_2 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___DestinationApiName_2), (void*)L_3);
		// LobbySessionID = CLIB.ppf_LaunchDetails_GetLobbySessionID(o);
		intptr_t L_4 = ___0_o;
		String_t* L_5;
		L_5 = CLIB_ppf_LaunchDetails_GetLobbySessionID_mB532DCDABA451173E4C93FAA4A890DAAAEDFFB9E(L_4, NULL);
		__this->___LobbySessionID_3 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___LobbySessionID_3), (void*)L_5);
		// MatchSessionID = CLIB.ppf_LaunchDetails_GetMatchSessionID(o);
		intptr_t L_6 = ___0_o;
		String_t* L_7;
		L_7 = CLIB_ppf_LaunchDetails_GetMatchSessionID_m663601B6487F40956EAD564BE11F43343E97A429(L_6, NULL);
		__this->___MatchSessionID_4 = L_7;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___MatchSessionID_4), (void*)L_7);
		// Extra = CLIB.ppf_LaunchDetails_GetExtra(o);
		intptr_t L_8 = ___0_o;
		String_t* L_9;
		L_9 = CLIB_ppf_LaunchDetails_GetExtra_mC5CCE217372DE9E0CAD3618C830DE5F0B2B6A196(L_8, NULL);
		__this->___Extra_5 = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Extra_5), (void*)L_9);
		// RoomID = CLIB.ppf_LaunchDetails_GetRoomID(o);
		intptr_t L_10 = ___0_o;
		uint64_t L_11;
		L_11 = CLIB_ppf_LaunchDetails_GetRoomID_mA1C0ADF43CF43F9B686AF3703ACE51981EC5F699(L_10, NULL);
		__this->___RoomID_6 = L_11;
		// ChallengeID = CLIB.ppf_LaunchDetails_GetChallengeID(o);
		intptr_t L_12 = ___0_o;
		uint64_t L_13;
		L_13 = CLIB_ppf_LaunchDetails_GetChallengeID_m535246BDC2687D9C525EC51E199F9E229E0E4729(L_12, NULL);
		__this->___ChallengeID_7 = L_13;
		// TrackingID = CLIB.ppf_LaunchDetails_GetTrackingID(o);
		intptr_t L_14 = ___0_o;
		String_t* L_15;
		L_15 = CLIB_ppf_LaunchDetails_GetTrackingID_m576041A6FC11F3E84ABDCA86A6E2241BC7E0F90F(L_14, NULL);
		__this->___TrackingID_8 = L_15;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___TrackingID_8), (void*)L_15);
		// LaunchType = CLIB.ppf_LaunchDetails_GetLaunchType(o);
		intptr_t L_16 = ___0_o;
		int32_t L_17;
		L_17 = CLIB_ppf_LaunchDetails_GetLaunchType_m278AB8B05EBCBD3E0F0C72BEF1380557CBFE8BB6(L_16, NULL);
		__this->___LaunchType_0 = L_17;
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
// System.Void Pico.Platform.Models.SystemInfo::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SystemInfo__ctor_m42FFED547423FBE9E52CD77071745D3E090B0E6C (SystemInfo_t53AF5429861C13B1769EA33EAA762275B333CCA0* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public SystemInfo(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// ROMVersion = CLIB.ppf_SystemInfo_GetROMVersion(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_SystemInfo_GetROMVersion_m4E99BE5C919678532BDBE52B17A719ED65744444(L_0, NULL);
		__this->___ROMVersion_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___ROMVersion_0), (void*)L_1);
		// Locale = CLIB.ppf_SystemInfo_GetLocale(o);
		intptr_t L_2 = ___0_o;
		String_t* L_3;
		L_3 = CLIB_ppf_SystemInfo_GetLocale_m9B053C1AD304D4BF02CF185555A809756841F027(L_2, NULL);
		__this->___Locale_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Locale_1), (void*)L_3);
		// ProductName = CLIB.ppf_SystemInfo_GetProductName(o);
		intptr_t L_4 = ___0_o;
		String_t* L_5;
		L_5 = CLIB_ppf_SystemInfo_GetProductName_mF4C630400839A663B0720A556121DF0CBF352684(L_4, NULL);
		__this->___ProductName_2 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___ProductName_2), (void*)L_5);
		// IsCnDevice = CLIB.ppf_SystemInfo_GetIsCnDevice(o);
		intptr_t L_6 = ___0_o;
		bool L_7;
		L_7 = CLIB_ppf_SystemInfo_GetIsCnDevice_m8E4BF6499CA8E77746AED57C7FAC08E3EA1A02DB(L_6, NULL);
		__this->___IsCnDevice_3 = L_7;
		// MatrixVersionName = CLIB.ppf_SystemInfo_GetMatrixVersionName(o);
		intptr_t L_8 = ___0_o;
		String_t* L_9;
		L_9 = CLIB_ppf_SystemInfo_GetMatrixVersionName_m476AE75AD43BD030D59FF0EE63C9837F8D9C5DD6(L_8, NULL);
		__this->___MatrixVersionName_4 = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___MatrixVersionName_4), (void*)L_9);
		// MatrixVersionCode = CLIB.ppf_SystemInfo_GetMatrixVersionCode(o);
		intptr_t L_10 = ___0_o;
		int64_t L_11;
		L_11 = CLIB_ppf_SystemInfo_GetMatrixVersionCode_m1DB3C0280D4FA8624A283C0D1F587A4732CE785B(L_10, NULL);
		__this->___MatrixVersionCode_5 = L_11;
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
// System.Void Pico.Platform.Models.ApplicationVersion::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ApplicationVersion__ctor_mC817855683EE9B9BD257C3332B993097B50CE465 (ApplicationVersion_t62CE03D7C8FBF594FDE1979E76974E0E3E707156* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public ApplicationVersion(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// CurrentCode = CLIB.ppf_ApplicationVersion_GetCurrentCode(o);
		intptr_t L_0 = ___0_o;
		int64_t L_1;
		L_1 = CLIB_ppf_ApplicationVersion_GetCurrentCode_m76EA30CE2F678D72840356C482A4B9735E09F5FE(L_0, NULL);
		__this->___CurrentCode_0 = L_1;
		// CurrentName = CLIB.ppf_ApplicationVersion_GetCurrentName(o);
		intptr_t L_2 = ___0_o;
		String_t* L_3;
		L_3 = CLIB_ppf_ApplicationVersion_GetCurrentName_mBC9A6FF9306378558D87F7AA681FAF908F961187(L_2, NULL);
		__this->___CurrentName_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___CurrentName_1), (void*)L_3);
		// LatestCode = CLIB.ppf_ApplicationVersion_GetLatestCode(o);
		intptr_t L_4 = ___0_o;
		int64_t L_5;
		L_5 = CLIB_ppf_ApplicationVersion_GetLatestCode_mCB1793CE63A9BE4F3580C125B98A5385157589E4(L_4, NULL);
		__this->___LatestCode_2 = L_5;
		// LatestName = CLIB.ppf_ApplicationVersion_GetLatestName(o);
		intptr_t L_6 = ___0_o;
		String_t* L_7;
		L_7 = CLIB_ppf_ApplicationVersion_GetLatestName_m0387B60DE0A54F192002C878BF51526BDB31E5C4(L_6, NULL);
		__this->___LatestName_3 = L_7;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___LatestName_3), (void*)L_7);
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
// System.Void Pico.Platform.Models.AssetDetails::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AssetDetails__ctor_mBEA8F407B875F1B5BD9F8828669D9ED98AAF4CB7 (AssetDetails_t8F8B8199F92068253768AABE9EB4314FFB926AE2* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public AssetDetails(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// AssetId = CLIB.ppf_AssetDetails_GetAssetId(o);
		intptr_t L_0 = ___0_o;
		uint64_t L_1;
		L_1 = CLIB_ppf_AssetDetails_GetAssetId_m30DE47693AEDD19CCAE8B2F3C38B04B89484C836(L_0, NULL);
		__this->___AssetId_0 = L_1;
		// AssetType = CLIB.ppf_AssetDetails_GetAssetType(o);
		intptr_t L_2 = ___0_o;
		String_t* L_3;
		L_3 = CLIB_ppf_AssetDetails_GetAssetType_mA17FB114E8F3B6E9F66B86ADA3880C0755FB0601(L_2, NULL);
		__this->___AssetType_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___AssetType_1), (void*)L_3);
		// DownloadStatus = CLIB.ppf_AssetDetails_GetDownloadStatus(o);
		intptr_t L_4 = ___0_o;
		String_t* L_5;
		L_5 = CLIB_ppf_AssetDetails_GetDownloadStatus_mED60EA7CD536F9636DC5B7B5748A2DC3F158DC37(L_4, NULL);
		__this->___DownloadStatus_2 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___DownloadStatus_2), (void*)L_5);
		// IapStatus = CLIB.ppf_AssetDetails_GetIapStatus(o);
		intptr_t L_6 = ___0_o;
		String_t* L_7;
		L_7 = CLIB_ppf_AssetDetails_GetIapStatus_m8E562F5D48D1EB6014C7763684112C5D7D0F2251(L_6, NULL);
		__this->___IapStatus_7 = L_7;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___IapStatus_7), (void*)L_7);
		// Filepath = CLIB.ppf_AssetDetails_GetFilepath(o);
		intptr_t L_8 = ___0_o;
		String_t* L_9;
		L_9 = CLIB_ppf_AssetDetails_GetFilepath_m0C39ABF75009F407A268D9422BD13D2608C9E7BA(L_8, NULL);
		__this->___Filepath_3 = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Filepath_3), (void*)L_9);
		// Metadata = CLIB.ppf_AssetDetails_GetMetadata(o);
		intptr_t L_10 = ___0_o;
		String_t* L_11;
		L_11 = CLIB_ppf_AssetDetails_GetMetadata_m6B7DF5682E75B9C137FF575CE26FADA96D6784FC(L_10, NULL);
		__this->___Metadata_4 = L_11;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Metadata_4), (void*)L_11);
		// Filename = CLIB.ppf_AssetDetails_GetFilename(o);
		intptr_t L_12 = ___0_o;
		String_t* L_13;
		L_13 = CLIB_ppf_AssetDetails_GetFilename_m9A6AF247B29775D4CB01F5B14F6C5E61CE865A35(L_12, NULL);
		__this->___Filename_5 = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Filename_5), (void*)L_13);
		// Version = CLIB.ppf_AssetDetails_GetVersion(o);
		intptr_t L_14 = ___0_o;
		int32_t L_15;
		L_15 = CLIB_ppf_AssetDetails_GetVersion_m0E2E4F9D9EE10CC8BDE443880FB18C192F144A17(L_14, NULL);
		__this->___Version_6 = L_15;
		// IapSku = CLIB.ppf_AssetDetails_GetIapSku(o);
		intptr_t L_16 = ___0_o;
		String_t* L_17;
		L_17 = CLIB_ppf_AssetDetails_GetIapSku_m38C9DF49A059A0D83B4AC0DFBE3DD25440E9DD8B(L_16, NULL);
		__this->___IapSku_8 = L_17;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___IapSku_8), (void*)L_17);
		// IapName = CLIB.ppf_AssetDetails_GetIapName(o);
		intptr_t L_18 = ___0_o;
		String_t* L_19;
		L_19 = CLIB_ppf_AssetDetails_GetIapName_m88BB2AEB76425C40DBA8CA36A664CB95709E765C(L_18, NULL);
		__this->___IapName_9 = L_19;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___IapName_9), (void*)L_19);
		// IapPrice = CLIB.ppf_AssetDetails_GetIapPrice(o);
		intptr_t L_20 = ___0_o;
		String_t* L_21;
		L_21 = CLIB_ppf_AssetDetails_GetIapPrice_m2C04DE9C3B27FB1FE33D5B6F645AB8F7DC88DC37(L_20, NULL);
		__this->___IapPrice_10 = L_21;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___IapPrice_10), (void*)L_21);
		// IapCurrency = CLIB.ppf_AssetDetails_GetIapCurrency(o);
		intptr_t L_22 = ___0_o;
		String_t* L_23;
		L_23 = CLIB_ppf_AssetDetails_GetIapCurrency_mC01C4AF66437ADCBABC46EFF3C6152675A871D30(L_22, NULL);
		__this->___IapCurrency_11 = L_23;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___IapCurrency_11), (void*)L_23);
		// IapDescription = CLIB.ppf_AssetDetails_GetIapDescription(o);
		intptr_t L_24 = ___0_o;
		String_t* L_25;
		L_25 = CLIB_ppf_AssetDetails_GetIapDescription_mD42158477344196D02B31BC337131244BF447E6C(L_24, NULL);
		__this->___IapDescription_12 = L_25;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___IapDescription_12), (void*)L_25);
		// IapIcon = CLIB.ppf_AssetDetails_GetIapIcon(o);
		intptr_t L_26 = ___0_o;
		String_t* L_27;
		L_27 = CLIB_ppf_AssetDetails_GetIapIcon_m8AB0CB439BA3BAEF078786F8375137E843C02948(L_26, NULL);
		__this->___IapIcon_13 = L_27;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___IapIcon_13), (void*)L_27);
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
// System.Void Pico.Platform.Models.AssetDetailsList::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AssetDetailsList__ctor_mC012BBCD469522E1B2FCC0005EE98B0FFB3A8C9A (AssetDetailsList_tB4AE1D412F214C001FEA90572C4244B92F4CF797* __this, intptr_t ___0_a, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AssetDetails_t8F8B8199F92068253768AABE9EB4314FFB926AE2_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mCEA246871367366985CC1373045B5CAC13DDECA6_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_set_Capacity_m587217153D2FA93F4FC0889992B6BA1FA2D95A87_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageArray_1__ctor_mB185D5F8F245E3548B7E1F83E5D80079D940BEA1_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		// public AssetDetailsList(IntPtr a)
		MessageArray_1__ctor_mB185D5F8F245E3548B7E1F83E5D80079D940BEA1(__this, MessageArray_1__ctor_mB185D5F8F245E3548B7E1F83E5D80079D940BEA1_RuntimeMethod_var);
		// var count = (int) CLIB.ppf_AssetDetailsArray_GetSize(a);
		intptr_t L_0 = ___0_a;
		uintptr_t L_1;
		L_1 = CLIB_ppf_AssetDetailsArray_GetSize_m433BBD041067F04F5A10E4555861C8C0E8E96343(L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint32_t L_2;
		L_2 = UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8(L_1, NULL);
		V_0 = L_2;
		// this.Capacity = count;
		int32_t L_3 = V_0;
		List_1_set_Capacity_m587217153D2FA93F4FC0889992B6BA1FA2D95A87(__this, L_3, List_1_set_Capacity_m587217153D2FA93F4FC0889992B6BA1FA2D95A87_RuntimeMethod_var);
		// for (int i = 0; i < count; i++)
		V_1 = 0;
		goto IL_0039;
	}

IL_001d:
	{
		// this.Add(new AssetDetails(CLIB.ppf_AssetDetailsArray_GetElement(a, (UIntPtr) i)));
		intptr_t L_4 = ___0_a;
		int32_t L_5 = V_1;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_6;
		L_6 = UIntPtr_op_Explicit_mF1E7911DD5AC13B5E59EE8C7903469D12A3861E8(((int64_t)L_5), NULL);
		intptr_t L_7;
		L_7 = CLIB_ppf_AssetDetailsArray_GetElement_m10868E5C3DD1E1D8CA388914F737E5FEDCC9088B(L_4, L_6, NULL);
		AssetDetails_t8F8B8199F92068253768AABE9EB4314FFB926AE2* L_8 = (AssetDetails_t8F8B8199F92068253768AABE9EB4314FFB926AE2*)il2cpp_codegen_object_new(AssetDetails_t8F8B8199F92068253768AABE9EB4314FFB926AE2_il2cpp_TypeInfo_var);
		NullCheck(L_8);
		AssetDetails__ctor_mBEA8F407B875F1B5BD9F8828669D9ED98AAF4CB7(L_8, L_7, NULL);
		List_1_Add_mCEA246871367366985CC1373045B5CAC13DDECA6_inline(__this, L_8, List_1_Add_mCEA246871367366985CC1373045B5CAC13DDECA6_RuntimeMethod_var);
		// for (int i = 0; i < count; i++)
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0039:
	{
		// for (int i = 0; i < count; i++)
		int32_t L_10 = V_1;
		int32_t L_11 = V_0;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_001d;
		}
	}
	{
		// NextPageParam = CLIB.ppf_AssetDetailsArray_GetNextPageParam(a);
		intptr_t L_12 = ___0_a;
		String_t* L_13;
		L_13 = CLIB_ppf_AssetDetailsArray_GetNextPageParam_m8A0847EFFB18FFFE801E963116D144755C8294A5(L_12, NULL);
		((MessageArray_1_t3588ACF0944917D806087EF192359A96F2EF26D6*)__this)->___NextPageParam_6 = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((MessageArray_1_t3588ACF0944917D806087EF192359A96F2EF26D6*)__this)->___NextPageParam_6), (void*)L_13);
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
// System.Void Pico.Platform.Models.AssetFileDeleteForSafety::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AssetFileDeleteForSafety__ctor_mA1DF1CEE228473B86B7058EB9830C09A46BE2288 (AssetFileDeleteForSafety_tE0658EB374DF5E9FFEB4D95D7CF5CDBA40E8EABA* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public AssetFileDeleteForSafety(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// AssetId = CLIB.ppf_AssetFileDeleteForSafety_GetAssetId(o);
		intptr_t L_0 = ___0_o;
		uint64_t L_1;
		L_1 = CLIB_ppf_AssetFileDeleteForSafety_GetAssetId_m0A5642ABB68637F41417042A90035B6AF9359E3C(L_0, NULL);
		__this->___AssetId_0 = L_1;
		// Reason = CLIB.ppf_AssetFileDeleteForSafety_GetReason(o);
		intptr_t L_2 = ___0_o;
		String_t* L_3;
		L_3 = CLIB_ppf_AssetFileDeleteForSafety_GetReason_m0D6348551BAFED2CE1F6C17624F15893CB41C677(L_2, NULL);
		__this->___Reason_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Reason_1), (void*)L_3);
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
// System.Void Pico.Platform.Models.AssetFileDeleteResult::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AssetFileDeleteResult__ctor_mC14021AC0F3BEB45E3B4B5BD3863AAB167501868 (AssetFileDeleteResult_t69B9AFEF34255AED9E99D39461203AD4310CC434* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public AssetFileDeleteResult(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Filepath = CLIB.ppf_AssetFileDeleteResult_GetFilepath(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_AssetFileDeleteResult_GetFilepath_mB84C04D52EBD9346D092B9D2161D62AB381C406A(L_0, NULL);
		__this->___Filepath_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Filepath_0), (void*)L_1);
		// Success = CLIB.ppf_AssetFileDeleteResult_GetSuccess(o);
		intptr_t L_2 = ___0_o;
		bool L_3;
		L_3 = CLIB_ppf_AssetFileDeleteResult_GetSuccess_mDB773D149D3628F18AFCDE385558CCB796C961B5(L_2, NULL);
		__this->___Success_1 = L_3;
		// AssetId = CLIB.ppf_AssetFileDeleteResult_GetAssetId(o);
		intptr_t L_4 = ___0_o;
		uint64_t L_5;
		L_5 = CLIB_ppf_AssetFileDeleteResult_GetAssetId_m864E006BC66298F8F1C5C2E3249226C0FE6AE5A8(L_4, NULL);
		__this->___AssetId_2 = L_5;
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
// System.Void Pico.Platform.Models.AssetFileDownloadCancelResult::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AssetFileDownloadCancelResult__ctor_mF6853F13948239A7B5E245537DA63E95AA535BA8 (AssetFileDownloadCancelResult_t3DBDC2912716D7BF23B8B8C7CC417C90AD405B43* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public AssetFileDownloadCancelResult(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Filepath = CLIB.ppf_AssetFileDownloadCancelResult_GetFilepath(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_AssetFileDownloadCancelResult_GetFilepath_mA20231654B8597E8CE8C9D499A7B6AACADE4AF1B(L_0, NULL);
		__this->___Filepath_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Filepath_0), (void*)L_1);
		// Success = CLIB.ppf_AssetFileDownloadCancelResult_GetSuccess(o);
		intptr_t L_2 = ___0_o;
		bool L_3;
		L_3 = CLIB_ppf_AssetFileDownloadCancelResult_GetSuccess_m1FEC0B12273C3D5CB158C214AFC7B381AD9A1ACE(L_2, NULL);
		__this->___Success_1 = L_3;
		// AssetId = CLIB.ppf_AssetFileDownloadCancelResult_GetAssetId(o);
		intptr_t L_4 = ___0_o;
		uint64_t L_5;
		L_5 = CLIB_ppf_AssetFileDownloadCancelResult_GetAssetId_mA7AC7A878088611C0D01507973C984AE25020C0C(L_4, NULL);
		__this->___AssetId_2 = L_5;
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
// System.Void Pico.Platform.Models.AssetFileDownloadResult::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AssetFileDownloadResult__ctor_m5B6A97F829C862AA9E310F31ABD62222D6F211D4 (AssetFileDownloadResult_tD0B1698C03580D6A8A9CD407B09D147D0F02F639* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public AssetFileDownloadResult(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// AssetId = CLIB.ppf_AssetFileDownloadResult_GetAssetId(o);
		intptr_t L_0 = ___0_o;
		uint64_t L_1;
		L_1 = CLIB_ppf_AssetFileDownloadResult_GetAssetId_m084817E52E3DCB845C1C1DA28486F2EADD4451C2(L_0, NULL);
		__this->___AssetId_0 = L_1;
		// Filepath = CLIB.ppf_AssetFileDownloadResult_GetFilepath(o);
		intptr_t L_2 = ___0_o;
		String_t* L_3;
		L_3 = CLIB_ppf_AssetFileDownloadResult_GetFilepath_mC92EC74711BD43A2E3D64FF4273A40A7DDAEA5EC(L_2, NULL);
		__this->___Filepath_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Filepath_1), (void*)L_3);
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
// System.Void Pico.Platform.Models.AssetFileDownloadUpdate::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AssetFileDownloadUpdate__ctor_m64EE082158C5EE8715D02147D6815DE0B0E9610F (AssetFileDownloadUpdate_tBAD90D69A25568EC45F334942C219ABFBD5DA6E2* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public AssetFileDownloadUpdate(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// AssetId = CLIB.ppf_AssetFileDownloadUpdate_GetAssetId(o);
		intptr_t L_0 = ___0_o;
		uint64_t L_1;
		L_1 = CLIB_ppf_AssetFileDownloadUpdate_GetAssetId_m0B5861262081CF39932B510FE0532CDBADDB18E9(L_0, NULL);
		__this->___AssetId_0 = L_1;
		// BytesTotal = CLIB.ppf_AssetFileDownloadUpdate_GetBytesTotal(o);
		intptr_t L_2 = ___0_o;
		uint64_t L_3;
		L_3 = CLIB_ppf_AssetFileDownloadUpdate_GetBytesTotal_m2578FBE12DAEFE371E2A0F0D94E5571372F27BDD(L_2, NULL);
		__this->___BytesTotal_1 = L_3;
		// BytesTransferred = CLIB.ppf_AssetFileDownloadUpdate_GetBytesTransferred(o);
		intptr_t L_4 = ___0_o;
		int64_t L_5;
		L_5 = CLIB_ppf_AssetFileDownloadUpdate_GetBytesTransferred_mA46C09C8767665DE93EB0E4EBE8B12D485EB205A(L_4, NULL);
		__this->___BytesTransferred_2 = L_5;
		// CompleteStatus = CLIB.ppf_AssetFileDownloadUpdate_GetCompleteStatus(o);
		intptr_t L_6 = ___0_o;
		int32_t L_7;
		L_7 = CLIB_ppf_AssetFileDownloadUpdate_GetCompleteStatus_mA680F3622C6096FE2807B34E7D3BB600BD2AE36E(L_6, NULL);
		__this->___CompleteStatus_3 = L_7;
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
// System.Void Pico.Platform.Models.AssetStatus::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AssetStatus__ctor_m77769BA88433031AB374DD2CF6B704703D86EE98 (AssetStatus_t1D527E1B3D8881BD413FE56B7E928774704F8206* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public AssetStatus(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// AssetId = CLIB.ppf_AssetStatus_GetAssetId(o);
		intptr_t L_0 = ___0_o;
		uint64_t L_1;
		L_1 = CLIB_ppf_AssetStatus_GetAssetId_mBD919DEE87A88BF455AD0DF2E0BAB83C51EA95B5(L_0, NULL);
		__this->___AssetId_0 = L_1;
		// Filename = CLIB.ppf_AssetStatus_GetFilename(o);
		intptr_t L_2 = ___0_o;
		String_t* L_3;
		L_3 = CLIB_ppf_AssetStatus_GetFilename_mAA6D2BF9B08A31F4AF83AD3B47EAAF817257B4BE(L_2, NULL);
		__this->___Filename_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Filename_1), (void*)L_3);
		// Filepath = CLIB.ppf_AssetStatus_GetFilepath(o);
		intptr_t L_4 = ___0_o;
		String_t* L_5;
		L_5 = CLIB_ppf_AssetStatus_GetFilepath_mFEC1C050C3A3CD55F6FDF44EA1385690D9D25E51(L_4, NULL);
		__this->___Filepath_2 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Filepath_2), (void*)L_5);
		// DownloadStatus = CLIB.ppf_AssetStatus_GetDownloadStatus(o);
		intptr_t L_6 = ___0_o;
		String_t* L_7;
		L_7 = CLIB_ppf_AssetStatus_GetDownloadStatus_m28B0087E3075BADB1EE9C62106743BBA74F2ADD1(L_6, NULL);
		__this->___DownloadStatus_3 = L_7;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___DownloadStatus_3), (void*)L_7);
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
// System.Void Pico.Platform.Models.ChallengeOptions::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChallengeOptions__ctor_m2E4BEEF7754A8322451EE9B1C3282920AD76F1A6 (ChallengeOptions_t9A8A307A2A43C1E1022510A14E02515DF5191DD8* __this, const RuntimeMethod* method) 
{
	{
		// public ChallengeOptions()
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Handle = CLIB.ppf_ChallengeOptions_Create();
		intptr_t L_0;
		L_0 = CLIB_ppf_ChallengeOptions_Create_m28D5B612C88C3522258407C203552F10E7189140(NULL);
		__this->___Handle_0 = L_0;
		// }
		return;
	}
}
// System.Void Pico.Platform.Models.ChallengeOptions::SetEndDate(System.DateTime)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChallengeOptions_SetEndDate_mDA233FB5E2B650E0397787428A0ADDEEB9DD2140 (ChallengeOptions_t9A8A307A2A43C1E1022510A14E02515DF5191DD8* __this, DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Convert_t7097FF336D592F7C06D88A98349A44646F91EFFC_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// CLIB.ppf_ChallengeOptions_SetEndDate(Handle, Convert.ToUInt64(TimeUtil.DateTimeToSeconds(value)));
		intptr_t L_0 = __this->___Handle_0;
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_1 = ___0_value;
		il2cpp_codegen_runtime_class_init_inline(TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		int32_t L_2;
		L_2 = TimeUtil_DateTimeToSeconds_mEC9188A159C402CEDEB78D0BF7EED1B8CF7C7DB3(L_1, NULL);
		il2cpp_codegen_runtime_class_init_inline(Convert_t7097FF336D592F7C06D88A98349A44646F91EFFC_il2cpp_TypeInfo_var);
		uint64_t L_3;
		L_3 = Convert_ToUInt64_m53C3A45C87A06F25957619222B04EABFD214373C(L_2, NULL);
		CLIB_ppf_ChallengeOptions_SetEndDate_mF4902730467C441843A26599A5E156C0A9FDB10A(L_0, L_3, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.Models.ChallengeOptions::SetIncludeActiveChallenges(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChallengeOptions_SetIncludeActiveChallenges_mD26CE951E3AEB35BF11A3EF9CD80DF944A4A580B (ChallengeOptions_t9A8A307A2A43C1E1022510A14E02515DF5191DD8* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_ChallengeOptions_SetIncludeActiveChallenges(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		bool L_1 = ___0_value;
		CLIB_ppf_ChallengeOptions_SetIncludeActiveChallenges_m8C145331B3DCD21F60DE0E333527F0A7A93AA4F0(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.Models.ChallengeOptions::SetIncludeFutureChallenges(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChallengeOptions_SetIncludeFutureChallenges_mA4260BAEBA89513A4E76DACA815E50A04E76F2B1 (ChallengeOptions_t9A8A307A2A43C1E1022510A14E02515DF5191DD8* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_ChallengeOptions_SetIncludeFutureChallenges(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		bool L_1 = ___0_value;
		CLIB_ppf_ChallengeOptions_SetIncludeFutureChallenges_m94B3A8141A52A1B7F7275ED9CAA4A70EA6D62D7F(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.Models.ChallengeOptions::SetIncludePastChallenges(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChallengeOptions_SetIncludePastChallenges_m45E3A2B1CDB0AC464A7757C4D212316728AF6124 (ChallengeOptions_t9A8A307A2A43C1E1022510A14E02515DF5191DD8* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_ChallengeOptions_SetIncludePastChallenges(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		bool L_1 = ___0_value;
		CLIB_ppf_ChallengeOptions_SetIncludePastChallenges_m7CDE72B71B97C616393B8DFE1DD5D13C29501D7D(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.Models.ChallengeOptions::SetLeaderboardName(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChallengeOptions_SetLeaderboardName_m9B6CA1355C85B5A974000C119845D32C97E5D4F7 (ChallengeOptions_t9A8A307A2A43C1E1022510A14E02515DF5191DD8* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_ChallengeOptions_SetLeaderboardName(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		String_t* L_1 = ___0_value;
		CLIB_ppf_ChallengeOptions_SetLeaderboardName_m91E5B54B48A198FFB8059C9EA7BC6B50D2F4C186(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.Models.ChallengeOptions::SetStartDate(System.DateTime)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChallengeOptions_SetStartDate_mF2F3EE59E210F88F5ACD2495A5D4EDF36A1775F8 (ChallengeOptions_t9A8A307A2A43C1E1022510A14E02515DF5191DD8* __this, DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Convert_t7097FF336D592F7C06D88A98349A44646F91EFFC_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// CLIB.ppf_ChallengeOptions_SetStartDate(Handle, Convert.ToUInt64(TimeUtil.DateTimeToSeconds(value)));
		intptr_t L_0 = __this->___Handle_0;
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_1 = ___0_value;
		il2cpp_codegen_runtime_class_init_inline(TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		int32_t L_2;
		L_2 = TimeUtil_DateTimeToSeconds_mEC9188A159C402CEDEB78D0BF7EED1B8CF7C7DB3(L_1, NULL);
		il2cpp_codegen_runtime_class_init_inline(Convert_t7097FF336D592F7C06D88A98349A44646F91EFFC_il2cpp_TypeInfo_var);
		uint64_t L_3;
		L_3 = Convert_ToUInt64_m53C3A45C87A06F25957619222B04EABFD214373C(L_2, NULL);
		CLIB_ppf_ChallengeOptions_SetStartDate_m00B9A69ACAD71F33AD0BDE547AE02411E62B4D10(L_0, L_3, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.Models.ChallengeOptions::SetTitle(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChallengeOptions_SetTitle_m820E41942175F8D4AF93B24FE043A5070F20BD99 (ChallengeOptions_t9A8A307A2A43C1E1022510A14E02515DF5191DD8* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_ChallengeOptions_SetTitle(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		String_t* L_1 = ___0_value;
		CLIB_ppf_ChallengeOptions_SetTitle_m413EA0AEA4EC27ECC6358A97994A87EEB31C69A8(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.Models.ChallengeOptions::SetViewerFilter(Pico.Platform.ChallengeViewerFilter)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChallengeOptions_SetViewerFilter_m08A885AC74C522B5BB864C9FC0E22FF6E4D3DB7E (ChallengeOptions_t9A8A307A2A43C1E1022510A14E02515DF5191DD8* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_ChallengeOptions_SetViewerFilter(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		int32_t L_1 = ___0_value;
		CLIB_ppf_ChallengeOptions_SetViewerFilter_mBB2183526B05441DCF1B93575FEC458ACDC15D6B(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.Models.ChallengeOptions::SetVisibility(Pico.Platform.ChallengeVisibility)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChallengeOptions_SetVisibility_m577194240D8635F55AE827A3143920E275A2BFE3 (ChallengeOptions_t9A8A307A2A43C1E1022510A14E02515DF5191DD8* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_ChallengeOptions_SetVisibility(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		int32_t L_1 = ___0_value;
		CLIB_ppf_ChallengeOptions_SetVisibility_mF62A54CE695BC12D40A25151308E3C18EB57B1AE(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.IntPtr Pico.Platform.Models.ChallengeOptions::op_Explicit(Pico.Platform.Models.ChallengeOptions)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t ChallengeOptions_op_Explicit_mC373A0A038484BA5BB13D5B20BE0550722523E4C (ChallengeOptions_t9A8A307A2A43C1E1022510A14E02515DF5191DD8* ___0_options, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// return options != null ? options.Handle : IntPtr.Zero;
		ChallengeOptions_t9A8A307A2A43C1E1022510A14E02515DF5191DD8* L_0 = ___0_options;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		intptr_t L_1 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		return L_1;
	}

IL_0009:
	{
		ChallengeOptions_t9A8A307A2A43C1E1022510A14E02515DF5191DD8* L_2 = ___0_options;
		NullCheck(L_2);
		intptr_t L_3 = L_2->___Handle_0;
		return L_3;
	}
}
// System.Void Pico.Platform.Models.ChallengeOptions::Finalize()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChallengeOptions_Finalize_m93DF0C049D8F3A3BF80EC9801AF3E68C75ABC8F9 (ChallengeOptions_t9A8A307A2A43C1E1022510A14E02515DF5191DD8* __this, const RuntimeMethod* method) 
{
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_000d:
			{// begin finally (depth: 1)
				// }
				Object_Finalize_mC98C96301CCABFE00F1A7EF8E15DF507CACD42B2(__this, NULL);
				return;
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			// CLIB.ppf_ChallengeOptions_Destroy(Handle);
			intptr_t L_0 = __this->___Handle_0;
			CLIB_ppf_ChallengeOptions_Destroy_m499648832560882E78FB7E6905C97A2B36F12B31(L_0, NULL);
			goto IL_0014;
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0014:
	{
		// }
		return;
	}
}
// System.IntPtr Pico.Platform.Models.ChallengeOptions::GetHandle()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t ChallengeOptions_GetHandle_m485A6EEF3D4D9E805583E87DED3F2F77D6AC2DBC (ChallengeOptions_t9A8A307A2A43C1E1022510A14E02515DF5191DD8* __this, const RuntimeMethod* method) 
{
	{
		// return Handle;
		intptr_t L_0 = __this->___Handle_0;
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
// System.Void Pico.Platform.Models.Challenge::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Challenge__ctor_m874B7BFA0E469D7E10DCB22ACDB3790700D8EA8F (Challenge_t4D4126711B52D78CEDA93B79EC0EFF69927E3971* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Leaderboard_t6D83DEF000B68074D583D0D92AED4AE1EFB14595_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* V_0 = NULL;
	intptr_t V_1;
	memset((&V_1), 0, sizeof(V_1));
	intptr_t V_2;
	memset((&V_2), 0, sizeof(V_2));
	Exception_t* V_3 = NULL;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		// public Challenge(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// CreationType = CLIB.ppf_Challenge_GetCreationType(o);
		intptr_t L_0 = ___0_o;
		int32_t L_1;
		L_1 = CLIB_ppf_Challenge_GetCreationType_m54722CFBBA46F0D71C731D213729B7CEB0C58CD5(L_0, NULL);
		__this->___CreationType_0 = L_1;
	}
	try
	{// begin try (depth: 1)
		// EndDate = TimeUtil.SecondsToDateTime((long) CLIB.ppf_Challenge_GetEndDate(o));
		intptr_t L_2 = ___0_o;
		uint64_t L_3;
		L_3 = CLIB_ppf_Challenge_GetEndDate_mCBDF7A2ED8714C96DA08DAF97248744C3F7157E8(L_2, NULL);
		il2cpp_codegen_runtime_class_init_inline(TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_4;
		L_4 = TimeUtil_SecondsToDateTime_m5DC84ED0EEB5AB8AAF833B2F5FF5E9F075C165F4(L_3, NULL);
		__this->___EndDate_3 = L_4;
		// }
		goto IL_0043;
	}// end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0025;
		}
		throw e;
	}

CATCH_0025:
	{// begin catch(System.Exception)
		Exception_t* L_5 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		// catch (Exception e)
		V_0 = L_5;
		// Debug.LogWarning($"Challenge Set EndDate: ppf_Challenge_GetEndDate(o) = {CLIB.ppf_Challenge_GetEndDate(o)}, Exception: {e}");
		intptr_t L_6 = ___0_o;
		uint64_t L_7;
		L_7 = CLIB_ppf_Challenge_GetEndDate_mCBDF7A2ED8714C96DA08DAF97248744C3F7157E8(L_6, NULL);
		uint64_t L_8 = L_7;
		RuntimeObject* L_9 = Box(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var)), &L_8);
		Exception_t* L_10 = V_0;
		String_t* L_11;
		L_11 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral73ECF991CB2C809BD76AEB6EF481BB2C816E93F3)), L_9, L_10, NULL);
		il2cpp_codegen_runtime_class_init_inline(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var)));
		Debug_LogWarning_m33EF1B897E0C7C6FF538989610BFAFFEF4628CA9(L_11, NULL);
		// }
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0043;
	}// end catch (depth: 1)

IL_0043:
	{
		// ID = CLIB.ppf_Challenge_GetID(o);
		intptr_t L_12 = ___0_o;
		uint64_t L_13;
		L_13 = CLIB_ppf_Challenge_GetID_mD003C6246D2607B8CD23B585BA9E86559BBD0F89(L_12, NULL);
		__this->___ID_1 = L_13;
		// var pointer = CLIB.ppf_Challenge_GetInvitedUsers(o);
		intptr_t L_14 = ___0_o;
		intptr_t L_15;
		L_15 = CLIB_ppf_Challenge_GetInvitedUsers_m4DF924A13B70554F30FAB4587F806B628C5FF915(L_14, NULL);
		V_1 = L_15;
		// if (pointer == IntPtr.Zero)
		intptr_t L_16 = V_1;
		intptr_t L_17 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		bool L_18;
		L_18 = IntPtr_op_Equality_m7D9CDCDE9DC2A0C2C614633F4921E90187FAB271(L_16, L_17, NULL);
		if (!L_18)
		{
			goto IL_006c;
		}
	}
	{
		// InvitedUsersOptional = null;
		__this->___InvitedUsersOptional_5 = (UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___InvitedUsersOptional_5), (void*)(UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F*)NULL);
		goto IL_0078;
	}

IL_006c:
	{
		// InvitedUsersOptional = new UserList(pointer);
		intptr_t L_19 = V_1;
		UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F* L_20 = (UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F*)il2cpp_codegen_object_new(UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F_il2cpp_TypeInfo_var);
		NullCheck(L_20);
		UserList__ctor_m4FEB49DD26A4410363EE489A1D289C8725776F4D(L_20, L_19, NULL);
		__this->___InvitedUsersOptional_5 = L_20;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___InvitedUsersOptional_5), (void*)L_20);
	}

IL_0078:
	{
		// Leaderboard = new Leaderboard(CLIB.ppf_Challenge_GetLeaderboard(o));
		intptr_t L_21 = ___0_o;
		intptr_t L_22;
		L_22 = CLIB_ppf_Challenge_GetLeaderboard_m2D06346ECDCADDE7C68C5F2CFBBC5E7EA4713C40(L_21, NULL);
		Leaderboard_t6D83DEF000B68074D583D0D92AED4AE1EFB14595* L_23 = (Leaderboard_t6D83DEF000B68074D583D0D92AED4AE1EFB14595*)il2cpp_codegen_object_new(Leaderboard_t6D83DEF000B68074D583D0D92AED4AE1EFB14595_il2cpp_TypeInfo_var);
		NullCheck(L_23);
		Leaderboard__ctor_m2A2DEAE53680BB01FA25EF33302C76475BC2445A(L_23, L_22, NULL);
		__this->___Leaderboard_6 = L_23;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Leaderboard_6), (void*)L_23);
		// var pointer = CLIB.ppf_Challenge_GetParticipants(o);
		intptr_t L_24 = ___0_o;
		intptr_t L_25;
		L_25 = CLIB_ppf_Challenge_GetParticipants_m8874B80EBB40D1B07BA5B32800D3297E6F1BE178(L_24, NULL);
		V_2 = L_25;
		// if (pointer == IntPtr.Zero)
		intptr_t L_26 = V_2;
		intptr_t L_27 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		bool L_28;
		L_28 = IntPtr_op_Equality_m7D9CDCDE9DC2A0C2C614633F4921E90187FAB271(L_26, L_27, NULL);
		if (!L_28)
		{
			goto IL_00a6;
		}
	}
	{
		// ParticipantsOptional = null;
		__this->___ParticipantsOptional_4 = (UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___ParticipantsOptional_4), (void*)(UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F*)NULL);
		goto IL_00b2;
	}

IL_00a6:
	{
		// ParticipantsOptional = new UserList(pointer);
		intptr_t L_29 = V_2;
		UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F* L_30 = (UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F*)il2cpp_codegen_object_new(UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F_il2cpp_TypeInfo_var);
		NullCheck(L_30);
		UserList__ctor_m4FEB49DD26A4410363EE489A1D289C8725776F4D(L_30, L_29, NULL);
		__this->___ParticipantsOptional_4 = L_30;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___ParticipantsOptional_4), (void*)L_30);
	}

IL_00b2:
	{
	}
	try
	{// begin try (depth: 1)
		// StartDate = TimeUtil.SecondsToDateTime((long) CLIB.ppf_Challenge_GetStartDate(o));
		intptr_t L_31 = ___0_o;
		uint64_t L_32;
		L_32 = CLIB_ppf_Challenge_GetStartDate_m8AAA44D2E70AAADCB8EC1C80098C161CDE23A967(L_31, NULL);
		il2cpp_codegen_runtime_class_init_inline(TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_33;
		L_33 = TimeUtil_SecondsToDateTime_m5DC84ED0EEB5AB8AAF833B2F5FF5E9F075C165F4(L_32, NULL);
		__this->___StartDate_2 = L_33;
		// }
		goto IL_00e4;
	}// end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_00c6;
		}
		throw e;
	}

CATCH_00c6:
	{// begin catch(System.Exception)
		Exception_t* L_34 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		// catch (Exception e)
		V_3 = L_34;
		// Debug.LogWarning($"Challenge Set StartDate: ppf_Challenge_GetStartDate(o) = {CLIB.ppf_Challenge_GetStartDate(o)}, Exception: {e}");
		intptr_t L_35 = ___0_o;
		uint64_t L_36;
		L_36 = CLIB_ppf_Challenge_GetStartDate_m8AAA44D2E70AAADCB8EC1C80098C161CDE23A967(L_35, NULL);
		uint64_t L_37 = L_36;
		RuntimeObject* L_38 = Box(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var)), &L_37);
		Exception_t* L_39 = V_3;
		String_t* L_40;
		L_40 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral4C05F264F2827749B257C389B7C1B994AD67E8C3)), L_38, L_39, NULL);
		il2cpp_codegen_runtime_class_init_inline(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var)));
		Debug_LogWarning_m33EF1B897E0C7C6FF538989610BFAFFEF4628CA9(L_40, NULL);
		// }
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_00e4;
	}// end catch (depth: 1)

IL_00e4:
	{
		// Title = CLIB.ppf_Challenge_GetTitle(o);
		intptr_t L_41 = ___0_o;
		String_t* L_42;
		L_42 = CLIB_ppf_Challenge_GetTitle_m4F7315685093D3CA0959F8F5EFF7EAAB1147C71E(L_41, NULL);
		__this->___Title_7 = L_42;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Title_7), (void*)L_42);
		// Visibility = CLIB.ppf_Challenge_GetVisibility(o);
		intptr_t L_43 = ___0_o;
		int32_t L_44;
		L_44 = CLIB_ppf_Challenge_GetVisibility_m7689009EADB3EB1AA23DD990122020B47FA3B720(L_43, NULL);
		__this->___Visibility_8 = L_44;
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
// System.Void Pico.Platform.Models.ChallengeList::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChallengeList__ctor_m590F163693CD06432A1421F1831D1ECB1E9E3F12 (ChallengeList_t46D99E7063774C36EF661DC3875AADDFC03E12D2* __this, intptr_t ___0_a, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Challenge_t4D4126711B52D78CEDA93B79EC0EFF69927E3971_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m1BA57A9C6578828099352E29E2BDA8357F2EFCD0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_set_Capacity_mD8859A91DF45D79EC817B5FD13518AA8FEC1A777_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageArray_1__ctor_mC023B4EA85DD7FE3EAA208D782D302DBDBAF0695_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&String_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB7C45DD316C68ABF3429C20058C2981C652192F2);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	uint32_t V_1 = 0;
	ChallengeList_t46D99E7063774C36EF661DC3875AADDFC03E12D2* G_B2_0 = NULL;
	ChallengeList_t46D99E7063774C36EF661DC3875AADDFC03E12D2* G_B1_0 = NULL;
	String_t* G_B3_0 = NULL;
	ChallengeList_t46D99E7063774C36EF661DC3875AADDFC03E12D2* G_B3_1 = NULL;
	ChallengeList_t46D99E7063774C36EF661DC3875AADDFC03E12D2* G_B5_0 = NULL;
	ChallengeList_t46D99E7063774C36EF661DC3875AADDFC03E12D2* G_B4_0 = NULL;
	String_t* G_B6_0 = NULL;
	ChallengeList_t46D99E7063774C36EF661DC3875AADDFC03E12D2* G_B6_1 = NULL;
	{
		// public ChallengeList(IntPtr a)
		MessageArray_1__ctor_mC023B4EA85DD7FE3EAA208D782D302DBDBAF0695(__this, MessageArray_1__ctor_mC023B4EA85DD7FE3EAA208D782D302DBDBAF0695_RuntimeMethod_var);
		// TotalCount = CLIB.ppf_ChallengeArray_GetTotalCount(a);
		intptr_t L_0 = ___0_a;
		uint64_t L_1;
		L_1 = CLIB_ppf_ChallengeArray_GetTotalCount_m1DF20B06D266246E545B890BDD803210C57CFF11(L_0, NULL);
		__this->___TotalCount_8 = L_1;
		// NextPageParam = CLIB.ppf_ChallengeArray_HasNextPage(a) ? "true" : string.Empty;
		intptr_t L_2 = ___0_a;
		bool L_3;
		L_3 = CLIB_ppf_ChallengeArray_HasNextPage_m8F637C349327898187C00BB1964E0EE7D2990583(L_2, NULL);
		G_B1_0 = __this;
		if (L_3)
		{
			G_B2_0 = __this;
			goto IL_0022;
		}
	}
	{
		String_t* L_4 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->___Empty_6;
		G_B3_0 = L_4;
		G_B3_1 = G_B1_0;
		goto IL_0027;
	}

IL_0022:
	{
		G_B3_0 = _stringLiteralB7C45DD316C68ABF3429C20058C2981C652192F2;
		G_B3_1 = G_B2_0;
	}

IL_0027:
	{
		NullCheck(G_B3_1);
		((MessageArray_1_t3AD15036E7E447220D0A42DE4FB31045C546D530*)G_B3_1)->___NextPageParam_6 = G_B3_0;
		Il2CppCodeGenWriteBarrier((void**)(&((MessageArray_1_t3AD15036E7E447220D0A42DE4FB31045C546D530*)G_B3_1)->___NextPageParam_6), (void*)G_B3_0);
		// PreviousPageParam = CLIB.ppf_ChallengeArray_HasPreviousPage(a) ? "true" : String.Empty;
		intptr_t L_5 = ___0_a;
		bool L_6;
		L_6 = CLIB_ppf_ChallengeArray_HasPreviousPage_m489DF72D11CEE7B26316A8CA8B03908A0522241C(L_5, NULL);
		G_B4_0 = __this;
		if (L_6)
		{
			G_B5_0 = __this;
			goto IL_003c;
		}
	}
	{
		String_t* L_7 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->___Empty_6;
		G_B6_0 = L_7;
		G_B6_1 = G_B4_0;
		goto IL_0041;
	}

IL_003c:
	{
		G_B6_0 = _stringLiteralB7C45DD316C68ABF3429C20058C2981C652192F2;
		G_B6_1 = G_B5_0;
	}

IL_0041:
	{
		NullCheck(G_B6_1);
		((MessageArray_1_t3AD15036E7E447220D0A42DE4FB31045C546D530*)G_B6_1)->___PreviousPageParam_7 = G_B6_0;
		Il2CppCodeGenWriteBarrier((void**)(&((MessageArray_1_t3AD15036E7E447220D0A42DE4FB31045C546D530*)G_B6_1)->___PreviousPageParam_7), (void*)G_B6_0);
		// int count = (int) CLIB.ppf_ChallengeArray_GetSize(a);
		intptr_t L_8 = ___0_a;
		uintptr_t L_9;
		L_9 = CLIB_ppf_ChallengeArray_GetSize_m19A7CA4D96B1793CC7526D13557AF0E443291460(L_8, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint32_t L_10;
		L_10 = UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8(L_9, NULL);
		V_0 = L_10;
		// this.Capacity = count;
		int32_t L_11 = V_0;
		List_1_set_Capacity_mD8859A91DF45D79EC817B5FD13518AA8FEC1A777(__this, L_11, List_1_set_Capacity_mD8859A91DF45D79EC817B5FD13518AA8FEC1A777_RuntimeMethod_var);
		// for (uint i = 0; i < count; i++)
		V_1 = 0;
		goto IL_0078;
	}

IL_005d:
	{
		// this.Add(new Challenge(CLIB.ppf_ChallengeArray_GetElement(a, (UIntPtr) i)));
		intptr_t L_12 = ___0_a;
		uint32_t L_13 = V_1;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_14;
		L_14 = UIntPtr_op_Explicit_mD94DCD8965DD2E7D5A3370A04CCEDBE5937C078C(L_13, NULL);
		intptr_t L_15;
		L_15 = CLIB_ppf_ChallengeArray_GetElement_m7FF8FEA78E6FF39583992782FE650FE1206EA841(L_12, L_14, NULL);
		Challenge_t4D4126711B52D78CEDA93B79EC0EFF69927E3971* L_16 = (Challenge_t4D4126711B52D78CEDA93B79EC0EFF69927E3971*)il2cpp_codegen_object_new(Challenge_t4D4126711B52D78CEDA93B79EC0EFF69927E3971_il2cpp_TypeInfo_var);
		NullCheck(L_16);
		Challenge__ctor_m874B7BFA0E469D7E10DCB22ACDB3790700D8EA8F(L_16, L_15, NULL);
		List_1_Add_m1BA57A9C6578828099352E29E2BDA8357F2EFCD0_inline(__this, L_16, List_1_Add_m1BA57A9C6578828099352E29E2BDA8357F2EFCD0_RuntimeMethod_var);
		// for (uint i = 0; i < count; i++)
		uint32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add((int32_t)L_17, 1));
	}

IL_0078:
	{
		// for (uint i = 0; i < count; i++)
		uint32_t L_18 = V_1;
		int32_t L_19 = V_0;
		if ((((int64_t)((int64_t)(uint64_t)L_18)) < ((int64_t)((int64_t)L_19))))
		{
			goto IL_005d;
		}
	}
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
// System.Void Pico.Platform.Models.ChallengeEntry::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChallengeEntry__ctor_mD68661A405B254CB2F675286E7CE8419B3B304A1 (ChallengeEntry_t16F06D309BE271B368F93F4F66001E1270B6EEAB* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	intptr_t V_0;
	memset((&V_0), 0, sizeof(V_0));
	uint32_t V_1 = 0;
	Exception_t* V_2 = NULL;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		// public ChallengeEntry(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// DisplayScore = CLIB.ppf_ChallengeEntry_GetDisplayScore(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_ChallengeEntry_GetDisplayScore_m67936B244D533E7B57F43A1D2B04BB8F9CB4D499(L_0, NULL);
		__this->___DisplayScore_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___DisplayScore_0), (void*)L_1);
		// var extraDataPtr = CLIB.ppf_ChallengeEntry_GetExtraData(o);
		intptr_t L_2 = ___0_o;
		intptr_t L_3;
		L_3 = CLIB_ppf_ChallengeEntry_GetExtraData_m4EA44F5AB49FD115736AE0A8DB570F88AA92C55C(L_2, NULL);
		V_0 = L_3;
		// var extraDataSize = CLIB.ppf_ChallengeEntry_GetExtraDataLength(o);
		intptr_t L_4 = ___0_o;
		uint32_t L_5;
		L_5 = CLIB_ppf_ChallengeEntry_GetExtraDataLength_m56C802D4C29D806C6E8AD2F85E04FF4A60BAFCEE(L_4, NULL);
		V_1 = L_5;
		// ExtraData = MarshalUtil.ByteArrayFromNative(extraDataPtr, extraDataSize);
		intptr_t L_6 = V_0;
		uint32_t L_7 = V_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_8;
		L_8 = MarshalUtil_ByteArrayFromNative_m3285FDD06424A5CB82BD0EE8C63BBB8F8C2482DB(L_6, L_7, NULL);
		__this->___ExtraData_1 = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___ExtraData_1), (void*)L_8);
		// ID = CLIB.ppf_ChallengeEntry_GetID(o);
		intptr_t L_9 = ___0_o;
		uint64_t L_10;
		L_10 = CLIB_ppf_ChallengeEntry_GetID_mA93758CC818587B6660FC3CEA39BF8BBBD23C2BD(L_9, NULL);
		__this->___ID_2 = L_10;
		// Rank = CLIB.ppf_ChallengeEntry_GetRank(o);
		intptr_t L_11 = ___0_o;
		int32_t L_12;
		L_12 = CLIB_ppf_ChallengeEntry_GetRank_m9C9213605C2B9413A8E14D06B4D59955A5A50D73(L_11, NULL);
		__this->___Rank_3 = L_12;
		// Score = CLIB.ppf_ChallengeEntry_GetScore(o);
		intptr_t L_13 = ___0_o;
		int64_t L_14;
		L_14 = CLIB_ppf_ChallengeEntry_GetScore_m51C80C491AF519ECBBAAF4CD22BAA2A8AB48ED0A(L_13, NULL);
		__this->___Score_4 = L_14;
	}
	try
	{// begin try (depth: 1)
		// Timestamp = TimeUtil.SecondsToDateTime((long) CLIB.ppf_ChallengeEntry_GetTimestamp(o));
		intptr_t L_15 = ___0_o;
		uint64_t L_16;
		L_16 = CLIB_ppf_ChallengeEntry_GetTimestamp_mE4222E9BCD2E2B7A0BCDA4A9B73CCB9BAD76C807(L_15, NULL);
		il2cpp_codegen_runtime_class_init_inline(TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_17;
		L_17 = TimeUtil_SecondsToDateTime_m5DC84ED0EEB5AB8AAF833B2F5FF5E9F075C165F4(L_16, NULL);
		__this->___Timestamp_5 = L_17;
		// }
		goto IL_0082;
	}// end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0064;
		}
		throw e;
	}

CATCH_0064:
	{// begin catch(System.Exception)
		Exception_t* L_18 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		// catch (Exception e)
		V_2 = L_18;
		// Debug.LogWarning($"ChallengeEntry Set Timestamp: ppf_ChallengeEntry_GetTimestamp(o) = {CLIB.ppf_ChallengeEntry_GetTimestamp(o)}, Exception: {e}");
		intptr_t L_19 = ___0_o;
		uint64_t L_20;
		L_20 = CLIB_ppf_ChallengeEntry_GetTimestamp_mE4222E9BCD2E2B7A0BCDA4A9B73CCB9BAD76C807(L_19, NULL);
		uint64_t L_21 = L_20;
		RuntimeObject* L_22 = Box(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var)), &L_21);
		Exception_t* L_23 = V_2;
		String_t* L_24;
		L_24 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral399A0FC4CB5C00718DE77B8FB9DE3E6A8C8B50BE)), L_22, L_23, NULL);
		il2cpp_codegen_runtime_class_init_inline(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var)));
		Debug_LogWarning_m33EF1B897E0C7C6FF538989610BFAFFEF4628CA9(L_24, NULL);
		// }
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0082;
	}// end catch (depth: 1)

IL_0082:
	{
		// User = new User(CLIB.ppf_ChallengeEntry_GetUser(o));
		intptr_t L_25 = ___0_o;
		intptr_t L_26;
		L_26 = CLIB_ppf_ChallengeEntry_GetUser_m2BCB9AFF38A65B6137FC60AC761A01D0B6FB3A8B(L_25, NULL);
		User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4* L_27 = (User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4*)il2cpp_codegen_object_new(User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4_il2cpp_TypeInfo_var);
		NullCheck(L_27);
		User__ctor_m0A17383A33457E27EB6AD299C81C77AC1802E0D1(L_27, L_26, NULL);
		__this->___User_6 = L_27;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___User_6), (void*)L_27);
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
// System.Void Pico.Platform.Models.ChallengeEntryList::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChallengeEntryList__ctor_mE32548CF4E83DD21C0F12934D315A4E7C4D31AD6 (ChallengeEntryList_tF2741C9A3F98553DC191BB26844528DC5525BB87* __this, intptr_t ___0_a, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ChallengeEntry_t16F06D309BE271B368F93F4F66001E1270B6EEAB_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m1914F43100B594ABF59084FCF1FCFA2D848E9025_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_set_Capacity_m5832DE315E2469EA21365A385436DD5F7824940A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageArray_1__ctor_mA5A42AA1E725EA805913577703E01D8889C8B184_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&String_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB7C45DD316C68ABF3429C20058C2981C652192F2);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	uint32_t V_1 = 0;
	ChallengeEntryList_tF2741C9A3F98553DC191BB26844528DC5525BB87* G_B2_0 = NULL;
	ChallengeEntryList_tF2741C9A3F98553DC191BB26844528DC5525BB87* G_B1_0 = NULL;
	String_t* G_B3_0 = NULL;
	ChallengeEntryList_tF2741C9A3F98553DC191BB26844528DC5525BB87* G_B3_1 = NULL;
	ChallengeEntryList_tF2741C9A3F98553DC191BB26844528DC5525BB87* G_B5_0 = NULL;
	ChallengeEntryList_tF2741C9A3F98553DC191BB26844528DC5525BB87* G_B4_0 = NULL;
	String_t* G_B6_0 = NULL;
	ChallengeEntryList_tF2741C9A3F98553DC191BB26844528DC5525BB87* G_B6_1 = NULL;
	{
		// public ChallengeEntryList(IntPtr a)
		MessageArray_1__ctor_mA5A42AA1E725EA805913577703E01D8889C8B184(__this, MessageArray_1__ctor_mA5A42AA1E725EA805913577703E01D8889C8B184_RuntimeMethod_var);
		// TotalCount = CLIB.ppf_ChallengeEntryArray_GetTotalCount(a);
		intptr_t L_0 = ___0_a;
		uint64_t L_1;
		L_1 = CLIB_ppf_ChallengeEntryArray_GetTotalCount_mC0727FFA226C37F8292D50EF06980CA813721A7B(L_0, NULL);
		__this->___TotalCount_8 = L_1;
		// NextPageParam = CLIB.ppf_ChallengeEntryArray_HasNextPage(a) ? "true" : string.Empty;
		intptr_t L_2 = ___0_a;
		bool L_3;
		L_3 = CLIB_ppf_ChallengeEntryArray_HasNextPage_m17DD52B8EBF5733D4FDD9999005177A8FA5E66CA(L_2, NULL);
		G_B1_0 = __this;
		if (L_3)
		{
			G_B2_0 = __this;
			goto IL_0022;
		}
	}
	{
		String_t* L_4 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->___Empty_6;
		G_B3_0 = L_4;
		G_B3_1 = G_B1_0;
		goto IL_0027;
	}

IL_0022:
	{
		G_B3_0 = _stringLiteralB7C45DD316C68ABF3429C20058C2981C652192F2;
		G_B3_1 = G_B2_0;
	}

IL_0027:
	{
		NullCheck(G_B3_1);
		((MessageArray_1_t7879F9CC787398F1DCC478C7DFC9D19EB4D4837E*)G_B3_1)->___NextPageParam_6 = G_B3_0;
		Il2CppCodeGenWriteBarrier((void**)(&((MessageArray_1_t7879F9CC787398F1DCC478C7DFC9D19EB4D4837E*)G_B3_1)->___NextPageParam_6), (void*)G_B3_0);
		// PreviousPageParam = CLIB.ppf_ChallengeEntryArray_HasPreviousPage(a) ? "true" : string.Empty;
		intptr_t L_5 = ___0_a;
		bool L_6;
		L_6 = CLIB_ppf_ChallengeEntryArray_HasPreviousPage_m2E70F20E0BA239B512B68698C9D13E0C1AAA993C(L_5, NULL);
		G_B4_0 = __this;
		if (L_6)
		{
			G_B5_0 = __this;
			goto IL_003c;
		}
	}
	{
		String_t* L_7 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->___Empty_6;
		G_B6_0 = L_7;
		G_B6_1 = G_B4_0;
		goto IL_0041;
	}

IL_003c:
	{
		G_B6_0 = _stringLiteralB7C45DD316C68ABF3429C20058C2981C652192F2;
		G_B6_1 = G_B5_0;
	}

IL_0041:
	{
		NullCheck(G_B6_1);
		((MessageArray_1_t7879F9CC787398F1DCC478C7DFC9D19EB4D4837E*)G_B6_1)->___PreviousPageParam_7 = G_B6_0;
		Il2CppCodeGenWriteBarrier((void**)(&((MessageArray_1_t7879F9CC787398F1DCC478C7DFC9D19EB4D4837E*)G_B6_1)->___PreviousPageParam_7), (void*)G_B6_0);
		// int count = (int) CLIB.ppf_ChallengeEntryArray_GetSize(a);
		intptr_t L_8 = ___0_a;
		uintptr_t L_9;
		L_9 = CLIB_ppf_ChallengeEntryArray_GetSize_m2F77700C22B836B21C1CEE5F29CF52EF0729C3A9(L_8, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint32_t L_10;
		L_10 = UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8(L_9, NULL);
		V_0 = L_10;
		// this.Capacity = count;
		int32_t L_11 = V_0;
		List_1_set_Capacity_m5832DE315E2469EA21365A385436DD5F7824940A(__this, L_11, List_1_set_Capacity_m5832DE315E2469EA21365A385436DD5F7824940A_RuntimeMethod_var);
		// for (uint i = 0; i < count; i++)
		V_1 = 0;
		goto IL_0078;
	}

IL_005d:
	{
		// this.Add(new ChallengeEntry(CLIB.ppf_ChallengeEntryArray_GetElement(a, (UIntPtr) i)));
		intptr_t L_12 = ___0_a;
		uint32_t L_13 = V_1;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_14;
		L_14 = UIntPtr_op_Explicit_mD94DCD8965DD2E7D5A3370A04CCEDBE5937C078C(L_13, NULL);
		intptr_t L_15;
		L_15 = CLIB_ppf_ChallengeEntryArray_GetElement_mEDC2E296E561D950ACB61D61DC5201D8385421A4(L_12, L_14, NULL);
		ChallengeEntry_t16F06D309BE271B368F93F4F66001E1270B6EEAB* L_16 = (ChallengeEntry_t16F06D309BE271B368F93F4F66001E1270B6EEAB*)il2cpp_codegen_object_new(ChallengeEntry_t16F06D309BE271B368F93F4F66001E1270B6EEAB_il2cpp_TypeInfo_var);
		NullCheck(L_16);
		ChallengeEntry__ctor_mD68661A405B254CB2F675286E7CE8419B3B304A1(L_16, L_15, NULL);
		List_1_Add_m1914F43100B594ABF59084FCF1FCFA2D848E9025_inline(__this, L_16, List_1_Add_m1914F43100B594ABF59084FCF1FCFA2D848E9025_RuntimeMethod_var);
		// for (uint i = 0; i < count; i++)
		uint32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add((int32_t)L_17, 1));
	}

IL_0078:
	{
		// for (uint i = 0; i < count; i++)
		uint32_t L_18 = V_1;
		int32_t L_19 = V_0;
		if ((((int64_t)((int64_t)(uint64_t)L_18)) < ((int64_t)((int64_t)L_19))))
		{
			goto IL_005d;
		}
	}
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
// System.UInt32 Pico.Platform.Models.KVPairArray::get_Size()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t KVPairArray_get_Size_m791FA5D137AE74B4A1AA97C39AEDE37A9916EE10 (KVPairArray_t2D18141BDF81CCF74F01AD0CD6D940BFF0D65E1F* __this, const RuntimeMethod* method) 
{
	{
		// public uint Size { get; private set; }
		uint32_t L_0 = __this->___U3CSizeU3Ek__BackingField_0;
		return L_0;
	}
}
// System.Void Pico.Platform.Models.KVPairArray::set_Size(System.UInt32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void KVPairArray_set_Size_mEF25D67ACDCEB5A98B41B65D53C7752DCDC51F4C (KVPairArray_t2D18141BDF81CCF74F01AD0CD6D940BFF0D65E1F* __this, uint32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public uint Size { get; private set; }
		uint32_t L_0 = ___0_value;
		__this->___U3CSizeU3Ek__BackingField_0 = L_0;
		return;
	}
}
// System.IntPtr Pico.Platform.Models.KVPairArray::GetHandle()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t KVPairArray_GetHandle_m389281C5195EBBD58347A4189B74F7C0A502DDA9 (KVPairArray_t2D18141BDF81CCF74F01AD0CD6D940BFF0D65E1F* __this, const RuntimeMethod* method) 
{
	{
		// return Handle;
		intptr_t L_0 = __this->___Handle_1;
		return L_0;
	}
}
// System.Void Pico.Platform.Models.KVPairArray::.ctor(System.UInt32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void KVPairArray__ctor_m4F6917590761EBFF6B9B805FEE49015DB7768BA1 (KVPairArray_t2D18141BDF81CCF74F01AD0CD6D940BFF0D65E1F* __this, uint32_t ___0_size, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public KVPairArray(uint size)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Size = size;
		uint32_t L_0 = ___0_size;
		KVPairArray_set_Size_mEF25D67ACDCEB5A98B41B65D53C7752DCDC51F4C_inline(__this, L_0, NULL);
		// Handle = CLIB.ppf_KeyValuePairArray_Create((UIntPtr) size);
		uint32_t L_1 = ___0_size;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_2;
		L_2 = UIntPtr_op_Explicit_mD94DCD8965DD2E7D5A3370A04CCEDBE5937C078C(L_1, NULL);
		intptr_t L_3;
		L_3 = CLIB_ppf_KeyValuePairArray_Create_m6F54BFFE5EE7E6ABA1752058D12134CF2CBD97F6(L_2, NULL);
		__this->___Handle_1 = L_3;
		// }
		return;
	}
}
// System.Void Pico.Platform.Models.KVPairArray::Finalize()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void KVPairArray_Finalize_mA12E637E27AB493FECE735C2FC709D0EB4D95C75 (KVPairArray_t2D18141BDF81CCF74F01AD0CD6D940BFF0D65E1F* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0018:
			{// begin finally (depth: 1)
				// }
				Object_Finalize_mC98C96301CCABFE00F1A7EF8E15DF507CACD42B2(__this, NULL);
				return;
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			// CLIB.ppf_KeyValuePairArray_Destroy(Handle);
			intptr_t L_0 = __this->___Handle_1;
			CLIB_ppf_KeyValuePairArray_Destroy_m13DB772246A8F5676AEB1C20C90B353652110DF6(L_0, NULL);
			// Handle = IntPtr.Zero;
			intptr_t L_1 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
			__this->___Handle_1 = L_1;
			goto IL_001f;
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_001f:
	{
		// }
		return;
	}
}
// Pico.Platform.Models.KVPair Pico.Platform.Models.KVPairArray::GetElement(System.UInt32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR KVPair_t3B78D7F4C5A144597A4D25D3E998B119380117F0* KVPairArray_GetElement_mBCB16A773753147C85E56DE455DA4AE059191BDA (KVPairArray_t2D18141BDF81CCF74F01AD0CD6D940BFF0D65E1F* __this, uint32_t ___0_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&KVPair_t3B78D7F4C5A144597A4D25D3E998B119380117F0_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// return new KVPair(CLIB.ppf_KeyValuePairArray_GetElement(Handle, (UIntPtr) index));
		intptr_t L_0 = __this->___Handle_1;
		uint32_t L_1 = ___0_index;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_2;
		L_2 = UIntPtr_op_Explicit_mD94DCD8965DD2E7D5A3370A04CCEDBE5937C078C(L_1, NULL);
		intptr_t L_3;
		L_3 = CLIB_ppf_KeyValuePairArray_GetElement_mE950CFCB71BAD525B897B7C4D278CB108EC4C617(L_0, L_2, NULL);
		KVPair_t3B78D7F4C5A144597A4D25D3E998B119380117F0* L_4 = (KVPair_t3B78D7F4C5A144597A4D25D3E998B119380117F0*)il2cpp_codegen_object_new(KVPair_t3B78D7F4C5A144597A4D25D3E998B119380117F0_il2cpp_TypeInfo_var);
		NullCheck(L_4);
		KVPair__ctor_m28A5FAFB2A42292D238E2A51A86E88A6EA1C8E70(L_4, L_3, NULL);
		return L_4;
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
// System.Void Pico.Platform.Models.KVPair::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void KVPair__ctor_mD1C402192A97E94D6EF9356F05E69FEFFDA1906A (KVPair_t3B78D7F4C5A144597A4D25D3E998B119380117F0* __this, const RuntimeMethod* method) 
{
	{
		// bool destroyable = true;
		__this->___destroyable_1 = (bool)1;
		// public KVPair()
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Handle = CLIB.ppf_KeyValuePair_Create();
		intptr_t L_0;
		L_0 = CLIB_ppf_KeyValuePair_Create_mA79AD02F3A312A65355B495A08360391C01B5FF6(NULL);
		__this->___Handle_0 = L_0;
		// }
		return;
	}
}
// System.Void Pico.Platform.Models.KVPair::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void KVPair__ctor_m28A5FAFB2A42292D238E2A51A86E88A6EA1C8E70 (KVPair_t3B78D7F4C5A144597A4D25D3E998B119380117F0* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// bool destroyable = true;
		__this->___destroyable_1 = (bool)1;
		// public KVPair(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Handle = o;
		intptr_t L_0 = ___0_o;
		__this->___Handle_0 = L_0;
		// destroyable = false;
		__this->___destroyable_1 = (bool)0;
		// }
		return;
	}
}
// System.Void Pico.Platform.Models.KVPair::SetIntValue(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void KVPair_SetIntValue_m4022E86A4D16FE34A363D1D83A499E46D576C1BB (KVPair_t3B78D7F4C5A144597A4D25D3E998B119380117F0* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_KeyValuePair_SetIntValue(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		int32_t L_1 = ___0_value;
		CLIB_ppf_KeyValuePair_SetIntValue_mC497AAC5BC9441B3EDA5F76157E0A277C98EF91A(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.Models.KVPair::SetStringValue(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void KVPair_SetStringValue_mECC788009B804AFBA8737D4BB560D8359002C7A8 (KVPair_t3B78D7F4C5A144597A4D25D3E998B119380117F0* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_KeyValuePair_SetStringValue(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		String_t* L_1 = ___0_value;
		CLIB_ppf_KeyValuePair_SetStringValue_m5F0A5632F7637FDC3C126481941D9FF3B71E0755(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.Models.KVPair::SetDoubleValue(System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void KVPair_SetDoubleValue_mAED848E9BAE1EE8DC5113E7B31D22F47EEADD83F (KVPair_t3B78D7F4C5A144597A4D25D3E998B119380117F0* __this, double ___0_value, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_KeyValuePair_SetDoubleValue(Handle, value);
		intptr_t L_0 = __this->___Handle_0;
		double L_1 = ___0_value;
		CLIB_ppf_KeyValuePair_SetDoubleValue_mA7E44BB1493EDBEBCFFF44F05D9C3F85A1FE2CF8(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Int32 Pico.Platform.Models.KVPair::GetIntValue()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t KVPair_GetIntValue_m1442D0348BDFB42E7AFC2AED90A6E42CC87607FC (KVPair_t3B78D7F4C5A144597A4D25D3E998B119380117F0* __this, const RuntimeMethod* method) 
{
	{
		// return CLIB.ppf_KeyValuePair_GetIntValue(Handle);
		intptr_t L_0 = __this->___Handle_0;
		int32_t L_1;
		L_1 = CLIB_ppf_KeyValuePair_GetIntValue_m7AE0ECBD0C910DC87AEC76B78841152854253699(L_0, NULL);
		return L_1;
	}
}
// System.String Pico.Platform.Models.KVPair::GetStringValue()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* KVPair_GetStringValue_m7F2275CC86A9B8A127A25FBB5177A1BFBEC686AF (KVPair_t3B78D7F4C5A144597A4D25D3E998B119380117F0* __this, const RuntimeMethod* method) 
{
	{
		// return CLIB.ppf_KeyValuePair_GetStringValue(Handle);
		intptr_t L_0 = __this->___Handle_0;
		String_t* L_1;
		L_1 = CLIB_ppf_KeyValuePair_GetStringValue_mF16E2228192E638B64886EEE165C82BF11CDDE52(L_0, NULL);
		return L_1;
	}
}
// System.Double Pico.Platform.Models.KVPair::GetDoubleValue()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double KVPair_GetDoubleValue_mBD7D726BEA28E90D6F6B02A10C089A26828AC7F9 (KVPair_t3B78D7F4C5A144597A4D25D3E998B119380117F0* __this, const RuntimeMethod* method) 
{
	{
		// return CLIB.ppf_KeyValuePair_GetDoubleValue(Handle);
		intptr_t L_0 = __this->___Handle_0;
		double L_1;
		L_1 = CLIB_ppf_KeyValuePair_GetDoubleValue_m56CD38E0B7348C51FEB3465E61382C9AD1E09BF9(L_0, NULL);
		return L_1;
	}
}
// System.Void Pico.Platform.Models.KVPair::SetKey(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void KVPair_SetKey_m1D117E89B96B556874E3E70BAC0AA38789DF5C3C (KVPair_t3B78D7F4C5A144597A4D25D3E998B119380117F0* __this, String_t* ___0_key, const RuntimeMethod* method) 
{
	{
		// CLIB.ppf_KeyValuePair_SetKey(Handle, key);
		intptr_t L_0 = __this->___Handle_0;
		String_t* L_1 = ___0_key;
		CLIB_ppf_KeyValuePair_SetKey_m3B06ECCBEEB5CC87ADD5FFAD6981F87D295FBA38(L_0, L_1, NULL);
		// }
		return;
	}
}
// System.String Pico.Platform.Models.KVPair::GetKey()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* KVPair_GetKey_m963F223634D6846B456D58CBE7E3D1E457D834A0 (KVPair_t3B78D7F4C5A144597A4D25D3E998B119380117F0* __this, const RuntimeMethod* method) 
{
	{
		// return CLIB.ppf_KeyValuePair_GetKey(Handle);
		intptr_t L_0 = __this->___Handle_0;
		String_t* L_1;
		L_1 = CLIB_ppf_KeyValuePair_GetKey_mEF5F8BDB87CC7F89999AC4E17C117D2DDB1B9218(L_0, NULL);
		return L_1;
	}
}
// Pico.Platform.KVPairType Pico.Platform.Models.KVPair::GetValueType()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t KVPair_GetValueType_m9464A0576B73D8BC8C598466F76AEFEFCEAEB093 (KVPair_t3B78D7F4C5A144597A4D25D3E998B119380117F0* __this, const RuntimeMethod* method) 
{
	{
		// return (KVPairType) CLIB.ppf_KeyValuePair_GetValueType(Handle);
		intptr_t L_0 = __this->___Handle_0;
		int32_t L_1;
		L_1 = CLIB_ppf_KeyValuePair_GetValueType_mCFC2798E5D55D9D7D07EEA1C75CAC1016AD60887(L_0, NULL);
		return L_1;
	}
}
// System.Void Pico.Platform.Models.KVPair::Finalize()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void KVPair_Finalize_mD56D4EC7772C1094BCF20EE12881ED15B0B987D4 (KVPair_t3B78D7F4C5A144597A4D25D3E998B119380117F0* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0020:
			{// begin finally (depth: 1)
				// }
				Object_Finalize_mC98C96301CCABFE00F1A7EF8E15DF507CACD42B2(__this, NULL);
				return;
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			{
				// if (destroyable)
				bool L_0 = __this->___destroyable_1;
				if (!L_0)
				{
					goto IL_001e_1;
				}
			}
			{
				// CLIB.ppf_KeyValuePair_Destroy(Handle);
				intptr_t L_1 = __this->___Handle_0;
				CLIB_ppf_KeyValuePair_Destroy_m7B7220611476C9701A52F66D112E43D92CEB565E(L_1, NULL);
				// Handle = IntPtr.Zero;
				intptr_t L_2 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
				__this->___Handle_0 = L_2;
			}

IL_001e_1:
			{
				goto IL_0027;
			}
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0027:
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
// System.Void Pico.Platform.Models.DetectSensitiveResult::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DetectSensitiveResult__ctor_m8AB12882BD96F72BE43FFDA5B67519FC734818FD (DetectSensitiveResult_t3F811A4C213815D1A2E488BCC02B4F0927C06381* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public DetectSensitiveResult(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// FilteredText = CLIB.ppf_DetectSensitiveResult_GetFilteredText(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_DetectSensitiveResult_GetFilteredText_mDDDE2F0034C8E04BD2EB83A613CA4C05E7E0E480(L_0, NULL);
		__this->___FilteredText_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___FilteredText_0), (void*)L_1);
		// Proposal = CLIB.ppf_DetectSensitiveResult_GetProposal(o);
		intptr_t L_2 = ___0_o;
		int32_t L_3;
		L_3 = CLIB_ppf_DetectSensitiveResult_GetProposal_m2B9E448CE776FE5A9AA77F4E80A63057ACD3B486(L_2, NULL);
		__this->___Proposal_1 = L_3;
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
// System.Void Pico.Platform.Models.CaptureInfo::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CaptureInfo__ctor_m37807B6D793D0C2EE7004FD38C0BFB9768B9B515 (CaptureInfo_t522928357E5822ACBC5FC59A060BDBABFF3DF575* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public CaptureInfo(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// ImagePath = CLIB.ppf_CaptureInfo_GetImagePath(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_CaptureInfo_GetImagePath_m244258184C6AB978A2BFDAF65ECF8871FCEB2970(L_0, NULL);
		__this->___ImagePath_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___ImagePath_0), (void*)L_1);
		// JobId = CLIB.ppf_CaptureInfo_GetJobId(o);
		intptr_t L_2 = ___0_o;
		String_t* L_3;
		L_3 = CLIB_ppf_CaptureInfo_GetJobId_m82FD585826C8CA38269BAEF8BEC2D7978471A759(L_2, NULL);
		__this->___JobId_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___JobId_1), (void*)L_3);
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
// System.Void Pico.Platform.Models.RecordInfo::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RecordInfo__ctor_m62B1FA6DDC2D03A3F8FFF3239A1D7D7209897627 (RecordInfo_t391FC28285898D9D06E379287A88F5A4BA4A6019* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public RecordInfo(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// VideoPath = CLIB.ppf_RecordInfo_GetVideoPath(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_RecordInfo_GetVideoPath_m2E2AC69C63DA6D160606CA864BE72D887FD21DFB(L_0, NULL);
		__this->___VideoPath_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___VideoPath_0), (void*)L_1);
		// DurationInMilliSeconds = CLIB.ppf_RecordInfo_GetDurationInMilliSeconds(o);
		intptr_t L_2 = ___0_o;
		int32_t L_3;
		L_3 = CLIB_ppf_RecordInfo_GetDurationInMilliSeconds_mD05B3267C985B017CFA3735A226AD903B734529B(L_2, NULL);
		__this->___DurationInMilliSeconds_1 = L_3;
		// Width = CLIB.ppf_RecordInfo_GetWidth(o);
		intptr_t L_4 = ___0_o;
		int32_t L_5;
		L_5 = CLIB_ppf_RecordInfo_GetWidth_mF57EE42B5F16E2C0D601AEDD9C38BB2EBDDC38C5(L_4, NULL);
		__this->___Width_2 = L_5;
		// Height = CLIB.ppf_RecordInfo_GetHeight(o);
		intptr_t L_6 = ___0_o;
		int32_t L_7;
		L_7 = CLIB_ppf_RecordInfo_GetHeight_m0E4967A34E1AFFFD63FC6FF56EBB8C8DA70175ED(L_6, NULL);
		__this->___Height_3 = L_7;
		// JobId = CLIB.ppf_RecordInfo_GetJobId(o);
		intptr_t L_8 = ___0_o;
		String_t* L_9;
		L_9 = CLIB_ppf_RecordInfo_GetJobId_mFDA5187B9A0231E5990963F53ACE5B15899C8FBC(L_8, NULL);
		__this->___JobId_4 = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___JobId_4), (void*)L_9);
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
// System.Void Pico.Platform.Models.SessionMedia::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SessionMedia__ctor_mB07225E10E8D33F70802F145706CB104A3BBF565 (SessionMedia_tCFC23B02299EDBE3E3749B48286C4CD403C89A07* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CaptureInfoU5BU5D_tFA6FAA7D7AE3BBB1688FD52AE43DE5032184993E_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CaptureInfo_t522928357E5822ACBC5FC59A060BDBABFF3DF575_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RecordInfoU5BU5D_t1505D0DB4C486883C741B73244F4130B5AF19854_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RecordInfo_t391FC28285898D9D06E379287A88F5A4BA4A6019_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	{
		// public SessionMedia(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// int sz = (int) CLIB.ppf_SessionMedia_GetImagesSize(o);
		intptr_t L_0 = ___0_o;
		uintptr_t L_1;
		L_1 = CLIB_ppf_SessionMedia_GetImagesSize_m6FD9B49191EC82E4DE3DC9A12E99107797452A8F(L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint32_t L_2;
		L_2 = UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8(L_1, NULL);
		V_0 = L_2;
		// Images = new CaptureInfo[sz];
		int32_t L_3 = V_0;
		CaptureInfoU5BU5D_tFA6FAA7D7AE3BBB1688FD52AE43DE5032184993E* L_4 = (CaptureInfoU5BU5D_tFA6FAA7D7AE3BBB1688FD52AE43DE5032184993E*)(CaptureInfoU5BU5D_tFA6FAA7D7AE3BBB1688FD52AE43DE5032184993E*)SZArrayNew(CaptureInfoU5BU5D_tFA6FAA7D7AE3BBB1688FD52AE43DE5032184993E_il2cpp_TypeInfo_var, (uint32_t)L_3);
		__this->___Images_0 = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Images_0), (void*)L_4);
		// for (int i = 0; i < sz; i++)
		V_1 = 0;
		goto IL_0040;
	}

IL_0022:
	{
		// Images[i] = new CaptureInfo(CLIB.ppf_SessionMedia_GetImages(o, (UIntPtr) i));
		CaptureInfoU5BU5D_tFA6FAA7D7AE3BBB1688FD52AE43DE5032184993E* L_5 = __this->___Images_0;
		int32_t L_6 = V_1;
		intptr_t L_7 = ___0_o;
		int32_t L_8 = V_1;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_9;
		L_9 = UIntPtr_op_Explicit_mF1E7911DD5AC13B5E59EE8C7903469D12A3861E8(((int64_t)L_8), NULL);
		intptr_t L_10;
		L_10 = CLIB_ppf_SessionMedia_GetImages_mBA8936A842A2AF4E37005F895A64BFA0B45B0143(L_7, L_9, NULL);
		CaptureInfo_t522928357E5822ACBC5FC59A060BDBABFF3DF575* L_11 = (CaptureInfo_t522928357E5822ACBC5FC59A060BDBABFF3DF575*)il2cpp_codegen_object_new(CaptureInfo_t522928357E5822ACBC5FC59A060BDBABFF3DF575_il2cpp_TypeInfo_var);
		NullCheck(L_11);
		CaptureInfo__ctor_m37807B6D793D0C2EE7004FD38C0BFB9768B9B515(L_11, L_10, NULL);
		NullCheck(L_5);
		ArrayElementTypeCheck (L_5, L_11);
		(L_5)->SetAt(static_cast<il2cpp_array_size_t>(L_6), (CaptureInfo_t522928357E5822ACBC5FC59A060BDBABFF3DF575*)L_11);
		// for (int i = 0; i < sz; i++)
		int32_t L_12 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
	}

IL_0040:
	{
		// for (int i = 0; i < sz; i++)
		int32_t L_13 = V_1;
		int32_t L_14 = V_0;
		if ((((int32_t)L_13) < ((int32_t)L_14)))
		{
			goto IL_0022;
		}
	}
	{
		// int sz = (int) CLIB.ppf_SessionMedia_GetVideosSize(o);
		intptr_t L_15 = ___0_o;
		uintptr_t L_16;
		L_16 = CLIB_ppf_SessionMedia_GetVideosSize_m09B378F0FC0DC9F7869EDAFCF8399CE5E0E188FF(L_15, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint32_t L_17;
		L_17 = UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8(L_16, NULL);
		V_2 = L_17;
		// Videos = new RecordInfo[sz];
		int32_t L_18 = V_2;
		RecordInfoU5BU5D_t1505D0DB4C486883C741B73244F4130B5AF19854* L_19 = (RecordInfoU5BU5D_t1505D0DB4C486883C741B73244F4130B5AF19854*)(RecordInfoU5BU5D_t1505D0DB4C486883C741B73244F4130B5AF19854*)SZArrayNew(RecordInfoU5BU5D_t1505D0DB4C486883C741B73244F4130B5AF19854_il2cpp_TypeInfo_var, (uint32_t)L_18);
		__this->___Videos_1 = L_19;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Videos_1), (void*)L_19);
		// for (int i = 0; i < sz; i++)
		V_3 = 0;
		goto IL_007e;
	}

IL_0060:
	{
		// Videos[i] = new RecordInfo(CLIB.ppf_SessionMedia_GetVideos(o, (UIntPtr) i));
		RecordInfoU5BU5D_t1505D0DB4C486883C741B73244F4130B5AF19854* L_20 = __this->___Videos_1;
		int32_t L_21 = V_3;
		intptr_t L_22 = ___0_o;
		int32_t L_23 = V_3;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_24;
		L_24 = UIntPtr_op_Explicit_mF1E7911DD5AC13B5E59EE8C7903469D12A3861E8(((int64_t)L_23), NULL);
		intptr_t L_25;
		L_25 = CLIB_ppf_SessionMedia_GetVideos_mCF9FA64B011A556A9F42B67BF119E170FED184D1(L_22, L_24, NULL);
		RecordInfo_t391FC28285898D9D06E379287A88F5A4BA4A6019* L_26 = (RecordInfo_t391FC28285898D9D06E379287A88F5A4BA4A6019*)il2cpp_codegen_object_new(RecordInfo_t391FC28285898D9D06E379287A88F5A4BA4A6019_il2cpp_TypeInfo_var);
		NullCheck(L_26);
		RecordInfo__ctor_m62B1FA6DDC2D03A3F8FFF3239A1D7D7209897627(L_26, L_25, NULL);
		NullCheck(L_20);
		ArrayElementTypeCheck (L_20, L_26);
		(L_20)->SetAt(static_cast<il2cpp_array_size_t>(L_21), (RecordInfo_t391FC28285898D9D06E379287A88F5A4BA4A6019*)L_26);
		// for (int i = 0; i < sz; i++)
		int32_t L_27 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_27, 1));
	}

IL_007e:
	{
		// for (int i = 0; i < sz; i++)
		int32_t L_28 = V_3;
		int32_t L_29 = V_2;
		if ((((int32_t)L_28) < ((int32_t)L_29)))
		{
			goto IL_0060;
		}
	}
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
// System.Void Pico.Platform.Models.Product::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Product__ctor_m2B89360C220C7AF2D5772983DFFA37D45E959C80 (Product_t1507FCF7293FA1250C325F33FEA9C46DBD487D66* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public Product(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Description = CLIB.ppf_Product_GetDescription(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_Product_GetDescription_mD1B0779646243AA5FB9688ECB436C3440DFAC700(L_0, NULL);
		__this->___Description_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Description_0), (void*)L_1);
		// DetailDescription = CLIB.ppf_Product_GetDetailDescription(o);
		intptr_t L_2 = ___0_o;
		String_t* L_3;
		L_3 = CLIB_ppf_Product_GetDetailDescription_mA8F954985EF6C5BCC48B2507AE5BC313094C8DDD(L_2, NULL);
		__this->___DetailDescription_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___DetailDescription_1), (void*)L_3);
		// Price = CLIB.ppf_Product_GetPrice(o);
		intptr_t L_4 = ___0_o;
		String_t* L_5;
		L_5 = CLIB_ppf_Product_GetPrice_m8652C7A00E9EFC1916452594FD90B1843AE19354(L_4, NULL);
		__this->___Price_2 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Price_2), (void*)L_5);
		// Currency = CLIB.ppf_Product_GetCurrency(o);
		intptr_t L_6 = ___0_o;
		String_t* L_7;
		L_7 = CLIB_ppf_Product_GetCurrency_mEE194462F6866E2D1DD209839973F97868925AE8(L_6, NULL);
		__this->___Currency_3 = L_7;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Currency_3), (void*)L_7);
		// Name = CLIB.ppf_Product_GetName(o);
		intptr_t L_8 = ___0_o;
		String_t* L_9;
		L_9 = CLIB_ppf_Product_GetName_mD6CBAC72CD5E96A0445933B767E72A7A92C3DD29(L_8, NULL);
		__this->___Name_4 = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Name_4), (void*)L_9);
		// SKU = CLIB.ppf_Product_GetSKU(o);
		intptr_t L_10 = ___0_o;
		String_t* L_11;
		L_11 = CLIB_ppf_Product_GetSKU_m43A370DCC294314B0C85CE1D82303A8134C1AF01(L_10, NULL);
		__this->___SKU_5 = L_11;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___SKU_5), (void*)L_11);
		// Icon = CLIB.ppf_Product_GetIcon(o);
		intptr_t L_12 = ___0_o;
		String_t* L_13;
		L_13 = CLIB_ppf_Product_GetIcon_m4DA4D8820C994B721BAF067740422F0AE7E92DB7(L_12, NULL);
		__this->___Icon_6 = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Icon_6), (void*)L_13);
		// AddonsType = CLIB.ppf_Product_GetAddonsType(o);
		intptr_t L_14 = ___0_o;
		int32_t L_15;
		L_15 = CLIB_ppf_Product_GetAddonsType_m6B3F5E884CA75B4401A176ADF3C525AEAC1543D3(L_14, NULL);
		__this->___AddonsType_7 = L_15;
		// PeriodType = CLIB.ppf_Product_GetPeriodType(o);
		intptr_t L_16 = ___0_o;
		int32_t L_17;
		L_17 = CLIB_ppf_Product_GetPeriodType_mFB4E69F348D9C29A8EEAD2627734E7081BD16F8D(L_16, NULL);
		__this->___PeriodType_8 = L_17;
		// TrialPeriodUnit = CLIB.ppf_Product_GetTrialPeriodUnit(o);
		intptr_t L_18 = ___0_o;
		int32_t L_19;
		L_19 = CLIB_ppf_Product_GetTrialPeriodUnit_mAC8F88A36DE9ACFF22503D38484AF9A21D31466F(L_18, NULL);
		__this->___TrialPeriodUnit_9 = L_19;
		// TrialPeriodValue = CLIB.ppf_Product_GetTrialPeriodValue(o);
		intptr_t L_20 = ___0_o;
		int32_t L_21;
		L_21 = CLIB_ppf_Product_GetTrialPeriodValue_m0B7A544E5F45A6C9C6582C60469F06FD953298C4(L_20, NULL);
		__this->___TrialPeriodValue_10 = L_21;
		// OuterId = CLIB.ppf_Product_GetOuterId(o);
		intptr_t L_22 = ___0_o;
		String_t* L_23;
		L_23 = CLIB_ppf_Product_GetOuterId_m267AFFBDEE32F2C381823A9B6BD748DC47F6BDAB(L_22, NULL);
		__this->___OuterId_12 = L_23;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___OuterId_12), (void*)L_23);
		// OriginalPrice = CLIB.ppf_Product_GetOriginalPrice(o);
		intptr_t L_24 = ___0_o;
		String_t* L_25;
		L_25 = CLIB_ppf_Product_GetOriginalPrice_m235B0BE70565566B7689EEB90B7BEB398A3F433D(L_24, NULL);
		__this->___OriginalPrice_11 = L_25;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___OriginalPrice_11), (void*)L_25);
		// IsContinuous = CLIB.ppf_Product_IsContinuous(o);
		intptr_t L_26 = ___0_o;
		bool L_27;
		L_27 = CLIB_ppf_Product_IsContinuous_m020687081765F96283B5981EBF0772FE172D147F(L_26, NULL);
		__this->___IsContinuous_13 = L_27;
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
// System.Void Pico.Platform.Models.ProductList::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProductList__ctor_mEFB4D04F2EEAF14DA4A1685980EDD46C0E2E9141 (ProductList_t60557078ACE42730D11C630A551C5ECF6DD48160* __this, intptr_t ___0_a, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAC66765B1249EE653786600439164EBFDD4CD46B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_set_Capacity_m450A27888E6E123248BB184BB5FA984716BEEA65_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageArray_1__ctor_m070935432E3EC3110B908F76DBAF98885CFDDB32_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Product_t1507FCF7293FA1250C325F33FEA9C46DBD487D66_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		// public ProductList(IntPtr a)
		MessageArray_1__ctor_m070935432E3EC3110B908F76DBAF98885CFDDB32(__this, MessageArray_1__ctor_m070935432E3EC3110B908F76DBAF98885CFDDB32_RuntimeMethod_var);
		// var count = (int) CLIB.ppf_ProductArray_GetSize(a);
		intptr_t L_0 = ___0_a;
		uintptr_t L_1;
		L_1 = CLIB_ppf_ProductArray_GetSize_m97628B5E987760A2E7A917DFEE15F7F853EFF096(L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint32_t L_2;
		L_2 = UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8(L_1, NULL);
		V_0 = L_2;
		// this.Capacity = count;
		int32_t L_3 = V_0;
		List_1_set_Capacity_m450A27888E6E123248BB184BB5FA984716BEEA65(__this, L_3, List_1_set_Capacity_m450A27888E6E123248BB184BB5FA984716BEEA65_RuntimeMethod_var);
		// for (int i = 0; i < count; i++)
		V_1 = 0;
		goto IL_0039;
	}

IL_001d:
	{
		// this.Add(new Product(CLIB.ppf_ProductArray_GetElement(a, (UIntPtr) i)));
		intptr_t L_4 = ___0_a;
		int32_t L_5 = V_1;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_6;
		L_6 = UIntPtr_op_Explicit_mF1E7911DD5AC13B5E59EE8C7903469D12A3861E8(((int64_t)L_5), NULL);
		intptr_t L_7;
		L_7 = CLIB_ppf_ProductArray_GetElement_m9270AA523463622CF92F5F4D32249D280E62163E(L_4, L_6, NULL);
		Product_t1507FCF7293FA1250C325F33FEA9C46DBD487D66* L_8 = (Product_t1507FCF7293FA1250C325F33FEA9C46DBD487D66*)il2cpp_codegen_object_new(Product_t1507FCF7293FA1250C325F33FEA9C46DBD487D66_il2cpp_TypeInfo_var);
		NullCheck(L_8);
		Product__ctor_m2B89360C220C7AF2D5772983DFFA37D45E959C80(L_8, L_7, NULL);
		List_1_Add_mAC66765B1249EE653786600439164EBFDD4CD46B_inline(__this, L_8, List_1_Add_mAC66765B1249EE653786600439164EBFDD4CD46B_RuntimeMethod_var);
		// for (int i = 0; i < count; i++)
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0039:
	{
		// for (int i = 0; i < count; i++)
		int32_t L_10 = V_1;
		int32_t L_11 = V_0;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_001d;
		}
	}
	{
		// NextPageParam = CLIB.ppf_ProductArray_GetNextPageParam(a);
		intptr_t L_12 = ___0_a;
		String_t* L_13;
		L_13 = CLIB_ppf_ProductArray_GetNextPageParam_mA37EED0D81F0DD2F3341B70951CB11AD180773AC(L_12, NULL);
		((MessageArray_1_tC6F5900777FE83D0B145BC0F27D11D16A33673A0*)__this)->___NextPageParam_6 = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((MessageArray_1_tC6F5900777FE83D0B145BC0F27D11D16A33673A0*)__this)->___NextPageParam_6), (void*)L_13);
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
// System.Void Pico.Platform.Models.Purchase::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Purchase__ctor_m7632482DEC5F4C2996224366FAE1009D916A6CCF (Purchase_t4EB26AC15A7E0936D3E6722DA01B1DF84A3D469A* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public Purchase(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// ExpirationTime = TimeUtil.MilliSecondsToDateTime(CLIB.ppf_Purchase_GetExpirationTime(o));
		intptr_t L_0 = ___0_o;
		int64_t L_1;
		L_1 = CLIB_ppf_Purchase_GetExpirationTime_mA67E34B8181562A639DC76496A6A3DB2798E5463(L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_2;
		L_2 = TimeUtil_MilliSecondsToDateTime_mF1197E9C5865487072B28200D665A6AEEA15F54C(L_1, NULL);
		__this->___ExpirationTime_0 = L_2;
		// GrantTime = TimeUtil.MilliSecondsToDateTime(CLIB.ppf_Purchase_GetGrantTime(o));
		intptr_t L_3 = ___0_o;
		int64_t L_4;
		L_4 = CLIB_ppf_Purchase_GetGrantTime_mBA17D386F2842A720F4240C23007B174F8178612(L_3, NULL);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_5;
		L_5 = TimeUtil_MilliSecondsToDateTime_mF1197E9C5865487072B28200D665A6AEEA15F54C(L_4, NULL);
		__this->___GrantTime_1 = L_5;
		// ID = CLIB.ppf_Purchase_GetID(o);
		intptr_t L_6 = ___0_o;
		String_t* L_7;
		L_7 = CLIB_ppf_Purchase_GetID_mDC7B79E2B3572603BF51704168A5612DE29A69EE(L_6, NULL);
		__this->___ID_2 = L_7;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___ID_2), (void*)L_7);
		// SKU = CLIB.ppf_Purchase_GetSKU(o);
		intptr_t L_8 = ___0_o;
		String_t* L_9;
		L_9 = CLIB_ppf_Purchase_GetSKU_mA89770C220CF5AC77D41E117519FD3CE8C58742D(L_8, NULL);
		__this->___SKU_3 = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___SKU_3), (void*)L_9);
		// Icon = CLIB.ppf_Purchase_GetIcon(o);
		intptr_t L_10 = ___0_o;
		String_t* L_11;
		L_11 = CLIB_ppf_Purchase_GetIcon_mBC898A37C6D4B800F2F92036C9C114B8170DB8E0(L_10, NULL);
		__this->___Icon_4 = L_11;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Icon_4), (void*)L_11);
		// AddonsType = CLIB.ppf_Purchase_GetAddonsType(o);
		intptr_t L_12 = ___0_o;
		int32_t L_13;
		L_13 = CLIB_ppf_Purchase_GetAddonsType_m82F2A1C27298CE21B4DEF36E71E733D0CA5F76A8(L_12, NULL);
		__this->___AddonsType_5 = L_13;
		// OuterId = CLIB.ppf_Purchase_GetOuterId(o);
		intptr_t L_14 = ___0_o;
		String_t* L_15;
		L_15 = CLIB_ppf_Purchase_GetOuterId_mD609AFEEFA9C7086F96C8CB4F64D14D72C403618(L_14, NULL);
		__this->___OuterId_6 = L_15;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___OuterId_6), (void*)L_15);
		// CurrentPeriodType = CLIB.ppf_Purchase_GetCurrentPeriodType(o);
		intptr_t L_16 = ___0_o;
		int32_t L_17;
		L_17 = CLIB_ppf_Purchase_GetCurrentPeriodType_mB7967308B7B6E9428DD24C233BB82EBD854D5C82(L_16, NULL);
		__this->___CurrentPeriodType_7 = L_17;
		// NextPeriodType = CLIB.ppf_Purchase_GetNextPeriodType(o);
		intptr_t L_18 = ___0_o;
		int32_t L_19;
		L_19 = CLIB_ppf_Purchase_GetNextPeriodType_m3D1B5702CE7ADE0657FD3F47EEE7CC4DC0B625FB(L_18, NULL);
		__this->___NextPeriodType_8 = L_19;
		// NextPayTime = TimeUtil.MilliSecondsToDateTime(CLIB.ppf_Purchase_GetNextPayTime(o));
		intptr_t L_20 = ___0_o;
		int64_t L_21;
		L_21 = CLIB_ppf_Purchase_GetNextPayTime_mEC3DEFC0111F54758740837010589B4975729D08(L_20, NULL);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_22;
		L_22 = TimeUtil_MilliSecondsToDateTime_mF1197E9C5865487072B28200D665A6AEEA15F54C(L_21, NULL);
		__this->___NextPayTime_9 = L_22;
		// DiscountType = CLIB.ppf_Purchase_GetDiscountType(o);
		intptr_t L_23 = ___0_o;
		int32_t L_24;
		L_24 = CLIB_ppf_Purchase_GetDiscountType_mFC8540A1E5708C25F478127E8EE94190B4B52F65(L_23, NULL);
		__this->___DiscountType_10 = L_24;
		// OrderComment = CLIB.ppf_Purchase_GetOrderComment(o);
		intptr_t L_25 = ___0_o;
		String_t* L_26;
		L_26 = CLIB_ppf_Purchase_GetOrderComment_mD71C08EAF31B97086796ED9D408729953687F545(L_25, NULL);
		__this->___OrderComment_11 = L_26;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___OrderComment_11), (void*)L_26);
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
// System.Void Pico.Platform.Models.PurchaseList::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PurchaseList__ctor_m5E57010B8B89CEBD9571D9831E52011ABE8B30A4 (PurchaseList_tE73ABD4A2D17ED67A2A410C78B54519A32A16C03* __this, intptr_t ___0_a, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mEADFAAEBDAE002FF709831869BFB21C97F3E6545_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_set_Capacity_mAE4CCF57EB35D4AFBB85D1E658B88B9226F3EDB6_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageArray_1__ctor_m42C5998DCEE5808E1E75BDC255282820B0FCDE4E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Purchase_t4EB26AC15A7E0936D3E6722DA01B1DF84A3D469A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		// public PurchaseList(IntPtr a)
		MessageArray_1__ctor_m42C5998DCEE5808E1E75BDC255282820B0FCDE4E(__this, MessageArray_1__ctor_m42C5998DCEE5808E1E75BDC255282820B0FCDE4E_RuntimeMethod_var);
		// var count = (int) CLIB.ppf_PurchaseArray_GetSize(a);
		intptr_t L_0 = ___0_a;
		uintptr_t L_1;
		L_1 = CLIB_ppf_PurchaseArray_GetSize_mA0DD6A9962FE6027F7479292AB1B5738FD1A882E(L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint32_t L_2;
		L_2 = UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8(L_1, NULL);
		V_0 = L_2;
		// this.Capacity = count;
		int32_t L_3 = V_0;
		List_1_set_Capacity_mAE4CCF57EB35D4AFBB85D1E658B88B9226F3EDB6(__this, L_3, List_1_set_Capacity_mAE4CCF57EB35D4AFBB85D1E658B88B9226F3EDB6_RuntimeMethod_var);
		// for (int i = 0; i < count; i++)
		V_1 = 0;
		goto IL_0039;
	}

IL_001d:
	{
		// this.Add(new Purchase(CLIB.ppf_PurchaseArray_GetElement(a, (UIntPtr) i)));
		intptr_t L_4 = ___0_a;
		int32_t L_5 = V_1;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_6;
		L_6 = UIntPtr_op_Explicit_mF1E7911DD5AC13B5E59EE8C7903469D12A3861E8(((int64_t)L_5), NULL);
		intptr_t L_7;
		L_7 = CLIB_ppf_PurchaseArray_GetElement_m4CC474C11ACDBA7C89D1230980D69DC9A2D1F7C3(L_4, L_6, NULL);
		Purchase_t4EB26AC15A7E0936D3E6722DA01B1DF84A3D469A* L_8 = (Purchase_t4EB26AC15A7E0936D3E6722DA01B1DF84A3D469A*)il2cpp_codegen_object_new(Purchase_t4EB26AC15A7E0936D3E6722DA01B1DF84A3D469A_il2cpp_TypeInfo_var);
		NullCheck(L_8);
		Purchase__ctor_m7632482DEC5F4C2996224366FAE1009D916A6CCF(L_8, L_7, NULL);
		List_1_Add_mEADFAAEBDAE002FF709831869BFB21C97F3E6545_inline(__this, L_8, List_1_Add_mEADFAAEBDAE002FF709831869BFB21C97F3E6545_RuntimeMethod_var);
		// for (int i = 0; i < count; i++)
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0039:
	{
		// for (int i = 0; i < count; i++)
		int32_t L_10 = V_1;
		int32_t L_11 = V_0;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_001d;
		}
	}
	{
		// NextPageParam = CLIB.ppf_PurchaseArray_GetNextPageParam(a);
		intptr_t L_12 = ___0_a;
		String_t* L_13;
		L_13 = CLIB_ppf_PurchaseArray_GetNextPageParam_mA8D3B2B96F786E717986A0BF59D3A48083195025(L_12, NULL);
		((MessageArray_1_t05AA39A5AA11CCE42EA326113EC8CB01D26F8E92*)__this)->___NextPageParam_6 = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((MessageArray_1_t05AA39A5AA11CCE42EA326113EC8CB01D26F8E92*)__this)->___NextPageParam_6), (void*)L_13);
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
// System.Void Pico.Platform.Models.SubscriptionStatus::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SubscriptionStatus__ctor_mD5354B2DD20B48D6865C8C88C76E62FB1E98C9E7 (SubscriptionStatus_tB2999CB0297F3E98A32D66E36872B688BD5ABA17* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public SubscriptionStatus(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// SKU = CLIB.ppf_SubscriptionStatus_GetSKU(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_SubscriptionStatus_GetSKU_m5595F9F55F1503D5561F9EF34CEDEC817BBFB1F8(L_0, NULL);
		__this->___SKU_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___SKU_0), (void*)L_1);
		// OuterId = CLIB.ppf_SubscriptionStatus_GetOuterId(o);
		intptr_t L_2 = ___0_o;
		String_t* L_3;
		L_3 = CLIB_ppf_SubscriptionStatus_GetOuterId_mFD523578B31BFC34A584F37C0DA6EC8F05C5EDDA(L_2, NULL);
		__this->___OuterId_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___OuterId_1), (void*)L_3);
		// StartTime = TimeUtil.MilliSecondsToDateTime(CLIB.ppf_SubscriptionStatus_GetStartTime(o));
		intptr_t L_4 = ___0_o;
		int64_t L_5;
		L_5 = CLIB_ppf_SubscriptionStatus_GetStartTime_m6BF1EF8ADCBB86DD1B4C18FE01E60275AC3B6D13(L_4, NULL);
		il2cpp_codegen_runtime_class_init_inline(TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_6;
		L_6 = TimeUtil_MilliSecondsToDateTime_mF1197E9C5865487072B28200D665A6AEEA15F54C(L_5, NULL);
		__this->___StartTime_2 = L_6;
		// EndTime = TimeUtil.MilliSecondsToDateTime(CLIB.ppf_SubscriptionStatus_GetEndTime(o));
		intptr_t L_7 = ___0_o;
		int64_t L_8;
		L_8 = CLIB_ppf_SubscriptionStatus_GetEndTime_m706198F960CC228B8DB969F5D06E4C469DFB8054(L_7, NULL);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_9;
		L_9 = TimeUtil_MilliSecondsToDateTime_mF1197E9C5865487072B28200D665A6AEEA15F54C(L_8, NULL);
		__this->___EndTime_3 = L_9;
		// PeriodType = CLIB.ppf_SubscriptionStatus_GetPeriodType(o);
		intptr_t L_10 = ___0_o;
		int32_t L_11;
		L_11 = CLIB_ppf_SubscriptionStatus_GetPeriodType_m21BFF84CCB3DAC33C671214718143CADF98BE13C(L_10, NULL);
		__this->___PeriodType_4 = L_11;
		// EntitlementStatus = CLIB.ppf_SubscriptionStatus_GetEntitlementStatus(o);
		intptr_t L_12 = ___0_o;
		int32_t L_13;
		L_13 = CLIB_ppf_SubscriptionStatus_GetEntitlementStatus_m17EB83072450EFEDC2003F5A91C30E6941180F3E(L_12, NULL);
		__this->___EntitlementStatus_5 = L_13;
		// CancelReason = CLIB.ppf_SubscriptionStatus_GetCancelReason(o);
		intptr_t L_14 = ___0_o;
		int32_t L_15;
		L_15 = CLIB_ppf_SubscriptionStatus_GetCancelReason_m9CA3C5B29A788E48D6C6270839F6844522CF167B(L_14, NULL);
		__this->___CancelReason_6 = L_15;
		// IsFreeTrial = CLIB.ppf_SubscriptionStatus_GetIsFreeTrial(o);
		intptr_t L_16 = ___0_o;
		bool L_17;
		L_17 = CLIB_ppf_SubscriptionStatus_GetIsFreeTrial_m6B838DA3E66F24F6177D7484F7AEF298BA6BA71E(L_16, NULL);
		__this->___IsFreeTrial_7 = L_17;
		// NextPeriod = CLIB.ppf_SubscriptionStatus_GetNextPeriod(o);
		intptr_t L_18 = ___0_o;
		int32_t L_19;
		L_19 = CLIB_ppf_SubscriptionStatus_GetNextPeriod_mA29187B347B2E79C402190E2F129BE3BA51222B4(L_18, NULL);
		__this->___NextPeriod_8 = L_19;
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
// System.Void Pico.Platform.Models.Leaderboard::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Leaderboard__ctor_m2A2DEAE53680BB01FA25EF33302C76475BC2445A (Leaderboard_t6D83DEF000B68074D583D0D92AED4AE1EFB14595* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	intptr_t V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		// public Leaderboard(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// ApiName = CLIB.ppf_Leaderboard_GetApiName(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_Leaderboard_GetApiName_m3C44DFA46E56BAC07EDB706A4ADBAB260BBB5512(L_0, NULL);
		__this->___ApiName_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___ApiName_0), (void*)L_1);
		// ID = CLIB.ppf_Leaderboard_GetID(o);
		intptr_t L_2 = ___0_o;
		uint64_t L_3;
		L_3 = CLIB_ppf_Leaderboard_GetID_mB2B837031119D9D620AEC7AB717267B55611A1A6(L_2, NULL);
		__this->___ID_1 = L_3;
		// var pointer = CLIB.ppf_Leaderboard_GetDestination(o);
		intptr_t L_4 = ___0_o;
		intptr_t L_5;
		L_5 = CLIB_ppf_Leaderboard_GetDestination_mFCB9EC7188152DBA1F8B8EE64BBE49A9A16F6AB6(L_4, NULL);
		V_0 = L_5;
		// if (pointer == IntPtr.Zero)
		intptr_t L_6 = V_0;
		intptr_t L_7 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		bool L_8;
		L_8 = IntPtr_op_Equality_m7D9CDCDE9DC2A0C2C614633F4921E90187FAB271(L_6, L_7, NULL);
		if (!L_8)
		{
			goto IL_003a;
		}
	}
	{
		// DestinationOptional = null;
		__this->___DestinationOptional_2 = (Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___DestinationOptional_2), (void*)(Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211*)NULL);
		return;
	}

IL_003a:
	{
		// DestinationOptional = new Destination(pointer);
		intptr_t L_9 = V_0;
		Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211* L_10 = (Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211*)il2cpp_codegen_object_new(Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211_il2cpp_TypeInfo_var);
		NullCheck(L_10);
		Destination__ctor_mB1261B84D715AED778CC96E68B1F2C0907CF8543(L_10, L_9, NULL);
		__this->___DestinationOptional_2 = L_10;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___DestinationOptional_2), (void*)L_10);
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
// System.Void Pico.Platform.Models.LeaderboardList::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LeaderboardList__ctor_m081285F5CA0D77E487C83DDFFF5C9FE1AB70F18C (LeaderboardList_t8BED638069122AD476155B80846591364CB07B06* __this, intptr_t ___0_a, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Leaderboard_t6D83DEF000B68074D583D0D92AED4AE1EFB14595_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mCC5C1CBC4EADCF51A55299EAD6C37250FC897458_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_set_Capacity_m963CDE36EB1DC3435DF73BC25E0C47DCB90B73EA_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageArray_1__ctor_mDF051A62863C8BF176120076EFE94E48880CCF09_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&String_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB7C45DD316C68ABF3429C20058C2981C652192F2);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	LeaderboardList_t8BED638069122AD476155B80846591364CB07B06* G_B2_0 = NULL;
	LeaderboardList_t8BED638069122AD476155B80846591364CB07B06* G_B1_0 = NULL;
	String_t* G_B3_0 = NULL;
	LeaderboardList_t8BED638069122AD476155B80846591364CB07B06* G_B3_1 = NULL;
	{
		// public LeaderboardList(IntPtr a)
		MessageArray_1__ctor_mDF051A62863C8BF176120076EFE94E48880CCF09(__this, MessageArray_1__ctor_mDF051A62863C8BF176120076EFE94E48880CCF09_RuntimeMethod_var);
		// TotalCount = CLIB.ppf_LeaderboardArray_GetTotalCount(a);
		intptr_t L_0 = ___0_a;
		uint64_t L_1;
		L_1 = CLIB_ppf_LeaderboardArray_GetTotalCount_mE26F608C8EEAEE8C90A61F15B1E9C307667351DD(L_0, NULL);
		__this->___TotalCount_8 = L_1;
		// NextPageParam = CLIB.ppf_LeaderboardArray_HasNextPage(a) ? "true" : string.Empty;
		intptr_t L_2 = ___0_a;
		bool L_3;
		L_3 = CLIB_ppf_LeaderboardArray_HasNextPage_m0283D91B507A12D29EAD6557E14EB38EF65ACB87(L_2, NULL);
		G_B1_0 = __this;
		if (L_3)
		{
			G_B2_0 = __this;
			goto IL_0022;
		}
	}
	{
		String_t* L_4 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->___Empty_6;
		G_B3_0 = L_4;
		G_B3_1 = G_B1_0;
		goto IL_0027;
	}

IL_0022:
	{
		G_B3_0 = _stringLiteralB7C45DD316C68ABF3429C20058C2981C652192F2;
		G_B3_1 = G_B2_0;
	}

IL_0027:
	{
		NullCheck(G_B3_1);
		((MessageArray_1_tF4173B1C53148BB935C764587034896F121CCA0A*)G_B3_1)->___NextPageParam_6 = G_B3_0;
		Il2CppCodeGenWriteBarrier((void**)(&((MessageArray_1_tF4173B1C53148BB935C764587034896F121CCA0A*)G_B3_1)->___NextPageParam_6), (void*)G_B3_0);
		// var count = (int) CLIB.ppf_LeaderboardArray_GetSize(a);
		intptr_t L_5 = ___0_a;
		uintptr_t L_6;
		L_6 = CLIB_ppf_LeaderboardArray_GetSize_mE4CDF1698DDEB674D5D80707B8C773850F1AD373(L_5, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint32_t L_7;
		L_7 = UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8(L_6, NULL);
		V_0 = L_7;
		// this.Capacity = count;
		int32_t L_8 = V_0;
		List_1_set_Capacity_m963CDE36EB1DC3435DF73BC25E0C47DCB90B73EA(__this, L_8, List_1_set_Capacity_m963CDE36EB1DC3435DF73BC25E0C47DCB90B73EA_RuntimeMethod_var);
		// for (var i = 0; i < count; i++)
		V_1 = 0;
		goto IL_005f;
	}

IL_0043:
	{
		// Add(new Leaderboard(CLIB.ppf_LeaderboardArray_GetElement(a, (UIntPtr) i)));
		intptr_t L_9 = ___0_a;
		int32_t L_10 = V_1;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_11;
		L_11 = UIntPtr_op_Explicit_mF1E7911DD5AC13B5E59EE8C7903469D12A3861E8(((int64_t)L_10), NULL);
		intptr_t L_12;
		L_12 = CLIB_ppf_LeaderboardArray_GetElement_m0E311CEEB7A307240A1090CAC1E8FEA66B8150A0(L_9, L_11, NULL);
		Leaderboard_t6D83DEF000B68074D583D0D92AED4AE1EFB14595* L_13 = (Leaderboard_t6D83DEF000B68074D583D0D92AED4AE1EFB14595*)il2cpp_codegen_object_new(Leaderboard_t6D83DEF000B68074D583D0D92AED4AE1EFB14595_il2cpp_TypeInfo_var);
		NullCheck(L_13);
		Leaderboard__ctor_m2A2DEAE53680BB01FA25EF33302C76475BC2445A(L_13, L_12, NULL);
		List_1_Add_mCC5C1CBC4EADCF51A55299EAD6C37250FC897458_inline(__this, L_13, List_1_Add_mCC5C1CBC4EADCF51A55299EAD6C37250FC897458_RuntimeMethod_var);
		// for (var i = 0; i < count; i++)
		int32_t L_14 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_14, 1));
	}

IL_005f:
	{
		// for (var i = 0; i < count; i++)
		int32_t L_15 = V_1;
		int32_t L_16 = V_0;
		if ((((int32_t)L_15) < ((int32_t)L_16)))
		{
			goto IL_0043;
		}
	}
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
// System.Void Pico.Platform.Models.SupplementaryMetric::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SupplementaryMetric__ctor_m4344D6AE0DB6BE0F5D79A62F613F6AD477BEC46C (SupplementaryMetric_t28C1258D6CB519A099746C713C51A1F14C2C242A* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public SupplementaryMetric(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// ID = CLIB.ppf_SupplementaryMetric_GetID(o);
		intptr_t L_0 = ___0_o;
		uint64_t L_1;
		L_1 = CLIB_ppf_SupplementaryMetric_GetID_m8BE37395168CC4A43F55FAEF84F4802666BC08A6(L_0, NULL);
		__this->___ID_0 = L_1;
		// Metric = CLIB.ppf_SupplementaryMetric_GetMetric(o);
		intptr_t L_2 = ___0_o;
		int64_t L_3;
		L_3 = CLIB_ppf_SupplementaryMetric_GetMetric_mF5AAFFA6AB2EB9FF451C3BB1520B107077164497(L_2, NULL);
		__this->___Metric_1 = L_3;
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
// System.Void Pico.Platform.Models.LeaderboardEntry::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LeaderboardEntry__ctor_mFA163C827FC8CB49FC78292F3659A08DA0D2602A (LeaderboardEntry_tDFA599CDDC7EC20F2041B9BCF885BAE5A8B7DF9F* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SupplementaryMetric_t28C1258D6CB519A099746C713C51A1F14C2C242A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	intptr_t V_0;
	memset((&V_0), 0, sizeof(V_0));
	uint32_t V_1 = 0;
	intptr_t V_2;
	memset((&V_2), 0, sizeof(V_2));
	{
		// public LeaderboardEntry(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// DisplayScore = CLIB.ppf_LeaderboardEntry_GetDisplayScore(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_LeaderboardEntry_GetDisplayScore_mEE5F0A6BE447A93D8283FE72064D9C4CCD850808(L_0, NULL);
		__this->___DisplayScore_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___DisplayScore_0), (void*)L_1);
		// var extraDataPtr = CLIB.ppf_LeaderboardEntry_GetExtraData(o);
		intptr_t L_2 = ___0_o;
		intptr_t L_3;
		L_3 = CLIB_ppf_LeaderboardEntry_GetExtraData_m0A15944A0014F6A15EF55660F3FBBA7A4E4E6E4C(L_2, NULL);
		V_0 = L_3;
		// var extraDataSize = CLIB.ppf_LeaderboardEntry_GetExtraDataLength(o);
		intptr_t L_4 = ___0_o;
		uint32_t L_5;
		L_5 = CLIB_ppf_LeaderboardEntry_GetExtraDataLength_m87680D3362D47D7097051C8CFE4843AC9B7DEC1C(L_4, NULL);
		V_1 = L_5;
		// ExtraData = MarshalUtil.ByteArrayFromNative(extraDataPtr, extraDataSize);
		intptr_t L_6 = V_0;
		uint32_t L_7 = V_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_8;
		L_8 = MarshalUtil_ByteArrayFromNative_m3285FDD06424A5CB82BD0EE8C63BBB8F8C2482DB(L_6, L_7, NULL);
		__this->___ExtraData_1 = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___ExtraData_1), (void*)L_8);
		// ID = CLIB.ppf_LeaderboardEntry_GetID(o);
		intptr_t L_9 = ___0_o;
		uint64_t L_10;
		L_10 = CLIB_ppf_LeaderboardEntry_GetID_m729C4E3230616AB7987BF79BDCA2F9F6DCA6A61B(L_9, NULL);
		__this->___ID_2 = L_10;
		// Rank = CLIB.ppf_LeaderboardEntry_GetRank(o);
		intptr_t L_11 = ___0_o;
		int32_t L_12;
		L_12 = CLIB_ppf_LeaderboardEntry_GetRank_m74818B002D623F894496C066DB61A372241E9D9F(L_11, NULL);
		__this->___Rank_3 = L_12;
		// Score = CLIB.ppf_LeaderboardEntry_GetScore(o);
		intptr_t L_13 = ___0_o;
		int64_t L_14;
		L_14 = CLIB_ppf_LeaderboardEntry_GetScore_m3806DB60A56B51FEF526D0A9C766B9A17318A355(L_13, NULL);
		__this->___Score_4 = L_14;
		// Timestamp = TimeUtil.SecondsToDateTime((long) CLIB.ppf_LeaderboardEntry_GetTimestamp(o));
		intptr_t L_15 = ___0_o;
		uint64_t L_16;
		L_16 = CLIB_ppf_LeaderboardEntry_GetTimestamp_m235480C0DC5A324DE8AAC7DE40C52531DC9D1AB6(L_15, NULL);
		il2cpp_codegen_runtime_class_init_inline(TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_17;
		L_17 = TimeUtil_SecondsToDateTime_m5DC84ED0EEB5AB8AAF833B2F5FF5E9F075C165F4(L_16, NULL);
		__this->___Timestamp_6 = L_17;
		// User = new User(CLIB.ppf_LeaderboardEntry_GetUser(o));
		intptr_t L_18 = ___0_o;
		intptr_t L_19;
		L_19 = CLIB_ppf_LeaderboardEntry_GetUser_m1D2A3F19B7EE38A6DD695B8FECAEBD5C19518E31(L_18, NULL);
		User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4* L_20 = (User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4*)il2cpp_codegen_object_new(User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4_il2cpp_TypeInfo_var);
		NullCheck(L_20);
		User__ctor_m0A17383A33457E27EB6AD299C81C77AC1802E0D1(L_20, L_19, NULL);
		__this->___User_7 = L_20;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___User_7), (void*)L_20);
		// var pointer = CLIB.ppf_LeaderboardEntry_GetSupplementaryMetric(o);
		intptr_t L_21 = ___0_o;
		intptr_t L_22;
		L_22 = CLIB_ppf_LeaderboardEntry_GetSupplementaryMetric_m2867CD031D7DA78D4D040918983A0CB8A6514422(L_21, NULL);
		V_2 = L_22;
		// if (pointer == IntPtr.Zero)
		intptr_t L_23 = V_2;
		intptr_t L_24 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		bool L_25;
		L_25 = IntPtr_op_Equality_m7D9CDCDE9DC2A0C2C614633F4921E90187FAB271(L_23, L_24, NULL);
		if (!L_25)
		{
			goto IL_008f;
		}
	}
	{
		// SupplementaryMetricOptional = null;
		__this->___SupplementaryMetricOptional_5 = (SupplementaryMetric_t28C1258D6CB519A099746C713C51A1F14C2C242A*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___SupplementaryMetricOptional_5), (void*)(SupplementaryMetric_t28C1258D6CB519A099746C713C51A1F14C2C242A*)NULL);
		return;
	}

IL_008f:
	{
		// SupplementaryMetricOptional = new SupplementaryMetric(pointer);
		intptr_t L_26 = V_2;
		SupplementaryMetric_t28C1258D6CB519A099746C713C51A1F14C2C242A* L_27 = (SupplementaryMetric_t28C1258D6CB519A099746C713C51A1F14C2C242A*)il2cpp_codegen_object_new(SupplementaryMetric_t28C1258D6CB519A099746C713C51A1F14C2C242A_il2cpp_TypeInfo_var);
		NullCheck(L_27);
		SupplementaryMetric__ctor_m4344D6AE0DB6BE0F5D79A62F613F6AD477BEC46C(L_27, L_26, NULL);
		__this->___SupplementaryMetricOptional_5 = L_27;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___SupplementaryMetricOptional_5), (void*)L_27);
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
// System.Void Pico.Platform.Models.LeaderboardEntryList::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LeaderboardEntryList__ctor_mA7DD0E76A29DD8A4360F294F4C63ADA264A42FF1 (LeaderboardEntryList_t6B5536586844053D032CB41222DC969C7FC0DC8D* __this, intptr_t ___0_a, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&LeaderboardEntry_tDFA599CDDC7EC20F2041B9BCF885BAE5A8B7DF9F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m9BB55A99B1916D012AB4E3E0A2CAB3E7EFA4513D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_set_Capacity_m4B212271F60F59CA181E583E2FA1000A14E49C55_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageArray_1__ctor_mC6CA9C8AA50186FFCDF3CA2E5A30AE34E21DE5D2_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&String_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB7C45DD316C68ABF3429C20058C2981C652192F2);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	uint32_t V_1 = 0;
	LeaderboardEntryList_t6B5536586844053D032CB41222DC969C7FC0DC8D* G_B2_0 = NULL;
	LeaderboardEntryList_t6B5536586844053D032CB41222DC969C7FC0DC8D* G_B1_0 = NULL;
	String_t* G_B3_0 = NULL;
	LeaderboardEntryList_t6B5536586844053D032CB41222DC969C7FC0DC8D* G_B3_1 = NULL;
	LeaderboardEntryList_t6B5536586844053D032CB41222DC969C7FC0DC8D* G_B5_0 = NULL;
	LeaderboardEntryList_t6B5536586844053D032CB41222DC969C7FC0DC8D* G_B4_0 = NULL;
	String_t* G_B6_0 = NULL;
	LeaderboardEntryList_t6B5536586844053D032CB41222DC969C7FC0DC8D* G_B6_1 = NULL;
	{
		// public LeaderboardEntryList(IntPtr a)
		MessageArray_1__ctor_mC6CA9C8AA50186FFCDF3CA2E5A30AE34E21DE5D2(__this, MessageArray_1__ctor_mC6CA9C8AA50186FFCDF3CA2E5A30AE34E21DE5D2_RuntimeMethod_var);
		// NextPageParam = CLIB.ppf_LeaderboardEntryArray_HasNextPage(a) ? "true" : string.Empty;
		intptr_t L_0 = ___0_a;
		bool L_1;
		L_1 = CLIB_ppf_LeaderboardEntryArray_HasNextPage_mBE803587B662F538084710F22E2172B41AF7BFBE(L_0, NULL);
		G_B1_0 = __this;
		if (L_1)
		{
			G_B2_0 = __this;
			goto IL_0016;
		}
	}
	{
		String_t* L_2 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->___Empty_6;
		G_B3_0 = L_2;
		G_B3_1 = G_B1_0;
		goto IL_001b;
	}

IL_0016:
	{
		G_B3_0 = _stringLiteralB7C45DD316C68ABF3429C20058C2981C652192F2;
		G_B3_1 = G_B2_0;
	}

IL_001b:
	{
		NullCheck(G_B3_1);
		((MessageArray_1_tB8E04BD481F9ACE36C3AC7750EC6E3168CF6ED31*)G_B3_1)->___NextPageParam_6 = G_B3_0;
		Il2CppCodeGenWriteBarrier((void**)(&((MessageArray_1_tB8E04BD481F9ACE36C3AC7750EC6E3168CF6ED31*)G_B3_1)->___NextPageParam_6), (void*)G_B3_0);
		// PreviousPageParam = CLIB.ppf_LeaderboardEntryArray_HasPreviousPage(a) ? "true" : string.Empty;
		intptr_t L_3 = ___0_a;
		bool L_4;
		L_4 = CLIB_ppf_LeaderboardEntryArray_HasPreviousPage_mC57A7D0351CC71FD09239FBBFADAB6696FB89AEA(L_3, NULL);
		G_B4_0 = __this;
		if (L_4)
		{
			G_B5_0 = __this;
			goto IL_0030;
		}
	}
	{
		String_t* L_5 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->___Empty_6;
		G_B6_0 = L_5;
		G_B6_1 = G_B4_0;
		goto IL_0035;
	}

IL_0030:
	{
		G_B6_0 = _stringLiteralB7C45DD316C68ABF3429C20058C2981C652192F2;
		G_B6_1 = G_B5_0;
	}

IL_0035:
	{
		NullCheck(G_B6_1);
		((MessageArray_1_tB8E04BD481F9ACE36C3AC7750EC6E3168CF6ED31*)G_B6_1)->___PreviousPageParam_7 = G_B6_0;
		Il2CppCodeGenWriteBarrier((void**)(&((MessageArray_1_tB8E04BD481F9ACE36C3AC7750EC6E3168CF6ED31*)G_B6_1)->___PreviousPageParam_7), (void*)G_B6_0);
		// var count = (int) CLIB.ppf_LeaderboardEntryArray_GetSize(a);
		intptr_t L_6 = ___0_a;
		uintptr_t L_7;
		L_7 = CLIB_ppf_LeaderboardEntryArray_GetSize_m5515778739F91A78D5C16C00D24E6C2A1D6414A7(L_6, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint32_t L_8;
		L_8 = UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8(L_7, NULL);
		V_0 = L_8;
		// this.Capacity = count;
		int32_t L_9 = V_0;
		List_1_set_Capacity_m4B212271F60F59CA181E583E2FA1000A14E49C55(__this, L_9, List_1_set_Capacity_m4B212271F60F59CA181E583E2FA1000A14E49C55_RuntimeMethod_var);
		// for (uint i = 0; i < count; i++)
		V_1 = 0;
		goto IL_006c;
	}

IL_0051:
	{
		// this.Add(new LeaderboardEntry(CLIB.ppf_LeaderboardEntryArray_GetElement(a, (UIntPtr) i)));
		intptr_t L_10 = ___0_a;
		uint32_t L_11 = V_1;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_12;
		L_12 = UIntPtr_op_Explicit_mD94DCD8965DD2E7D5A3370A04CCEDBE5937C078C(L_11, NULL);
		intptr_t L_13;
		L_13 = CLIB_ppf_LeaderboardEntryArray_GetElement_m3C349B967A2270ABE5B7C8D06573CF32E8E2D50A(L_10, L_12, NULL);
		LeaderboardEntry_tDFA599CDDC7EC20F2041B9BCF885BAE5A8B7DF9F* L_14 = (LeaderboardEntry_tDFA599CDDC7EC20F2041B9BCF885BAE5A8B7DF9F*)il2cpp_codegen_object_new(LeaderboardEntry_tDFA599CDDC7EC20F2041B9BCF885BAE5A8B7DF9F_il2cpp_TypeInfo_var);
		NullCheck(L_14);
		LeaderboardEntry__ctor_mFA163C827FC8CB49FC78292F3659A08DA0D2602A(L_14, L_13, NULL);
		List_1_Add_m9BB55A99B1916D012AB4E3E0A2CAB3E7EFA4513D_inline(__this, L_14, List_1_Add_m9BB55A99B1916D012AB4E3E0A2CAB3E7EFA4513D_RuntimeMethod_var);
		// for (uint i = 0; i < count; i++)
		uint32_t L_15 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add((int32_t)L_15, 1));
	}

IL_006c:
	{
		// for (uint i = 0; i < count; i++)
		uint32_t L_16 = V_1;
		int32_t L_17 = V_0;
		if ((((int64_t)((int64_t)(uint64_t)L_16)) < ((int64_t)((int64_t)L_17))))
		{
			goto IL_0051;
		}
	}
	{
		// TotalCount = CLIB.ppf_LeaderboardEntryArray_GetTotalCount(a);
		intptr_t L_18 = ___0_a;
		uint64_t L_19;
		L_19 = CLIB_ppf_LeaderboardEntryArray_GetTotalCount_m9F341000A8F8BE7E5D7985791DD5525CFBC782EB(L_18, NULL);
		__this->___TotalCount_8 = L_19;
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
// System.Void Pico.Platform.Models.MatchmakingAdminSnapshot::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MatchmakingAdminSnapshot__ctor_m17C01478ACBD07391C18DD67F372B6471E2E971F (MatchmakingAdminSnapshot_tF75B3A1A51D503587990BECC068C30E7671EE451* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MatchmakingAdminSnapshotCandidateList_tCB8BE369951F7307CA9A1AF9C7FE4B6253339C94_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public MatchmakingAdminSnapshot(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// CandidateList = new MatchmakingAdminSnapshotCandidateList(CLIB.ppf_MatchmakingAdminSnapshot_GetCandidates(o));
		intptr_t L_0 = ___0_o;
		intptr_t L_1;
		L_1 = CLIB_ppf_MatchmakingAdminSnapshot_GetCandidates_m0CB683248FD83BD4A535EBD9CC3A1336C206673D(L_0, NULL);
		MatchmakingAdminSnapshotCandidateList_tCB8BE369951F7307CA9A1AF9C7FE4B6253339C94* L_2 = (MatchmakingAdminSnapshotCandidateList_tCB8BE369951F7307CA9A1AF9C7FE4B6253339C94*)il2cpp_codegen_object_new(MatchmakingAdminSnapshotCandidateList_tCB8BE369951F7307CA9A1AF9C7FE4B6253339C94_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		MatchmakingAdminSnapshotCandidateList__ctor_m50F375A22DF5875C52AB1E3D16267248A6433AD9(L_2, L_1, NULL);
		__this->___CandidateList_0 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___CandidateList_0), (void*)L_2);
		// MyCurrentThreshold = CLIB.ppf_MatchmakingAdminSnapshot_GetMyCurrentThreshold(o);
		intptr_t L_3 = ___0_o;
		double L_4;
		L_4 = CLIB_ppf_MatchmakingAdminSnapshot_GetMyCurrentThreshold_m1D6BE3E5F0A324CEE7B071C54CEDB4B6A18048AC(L_3, NULL);
		__this->___MyCurrentThreshold_1 = L_4;
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
// System.Void Pico.Platform.Models.MatchmakingAdminSnapshotCandidate::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MatchmakingAdminSnapshotCandidate__ctor_m3F82611D0119A6464ECE680CFF74F29F07BD7B5F (MatchmakingAdminSnapshotCandidate_t2325F5337C73FF55AB6D932F2A14C97E3A813CCC* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public MatchmakingAdminSnapshotCandidate(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// CanMatch = CLIB.ppf_MatchmakingAdminSnapshotCandidate_GetCanMatch(o);
		intptr_t L_0 = ___0_o;
		bool L_1;
		L_1 = CLIB_ppf_MatchmakingAdminSnapshotCandidate_GetCanMatch_mDB3D34E534353B6F04752F4DF3457864650CCAD8(L_0, NULL);
		__this->___CanMatch_0 = L_1;
		// MyTotalScore = CLIB.ppf_MatchmakingAdminSnapshotCandidate_GetMyTotalScore(o);
		intptr_t L_2 = ___0_o;
		double L_3;
		L_3 = CLIB_ppf_MatchmakingAdminSnapshotCandidate_GetMyTotalScore_mCF7A89A0A4901CF46E22531D1A06EDE19C62B3DE(L_2, NULL);
		__this->___MyTotalScore_1 = L_3;
		// TheirCurrentThreshold = CLIB.ppf_MatchmakingAdminSnapshotCandidate_GetTheirCurrentThreshold(o);
		intptr_t L_4 = ___0_o;
		double L_5;
		L_5 = CLIB_ppf_MatchmakingAdminSnapshotCandidate_GetTheirCurrentThreshold_mF9F6AE9503B4234FB10B4B3EBDC01B4EA6365A8B(L_4, NULL);
		__this->___TheirCurrentThreshold_2 = L_5;
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
// System.Void Pico.Platform.Models.MatchmakingAdminSnapshotCandidateList::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MatchmakingAdminSnapshotCandidateList__ctor_m50F375A22DF5875C52AB1E3D16267248A6433AD9 (MatchmakingAdminSnapshotCandidateList_tCB8BE369951F7307CA9A1AF9C7FE4B6253339C94* __this, intptr_t ___0_a, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mE84497F7EEB65DCBE2B85C3A5F3FF2DC6422FED0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_set_Capacity_m9C560D90140238E989BCCCBF65E8EB846AF78497_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MatchmakingAdminSnapshotCandidate_t2325F5337C73FF55AB6D932F2A14C97E3A813CCC_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageArray_1__ctor_mE5F28B4391D395F2076F7B3E76B2E9481C2151D5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		// public MatchmakingAdminSnapshotCandidateList(IntPtr a)
		MessageArray_1__ctor_mE5F28B4391D395F2076F7B3E76B2E9481C2151D5(__this, MessageArray_1__ctor_mE5F28B4391D395F2076F7B3E76B2E9481C2151D5_RuntimeMethod_var);
		// var count = (int) CLIB.ppf_MatchmakingAdminSnapshotCandidateArray_GetSize(a);
		intptr_t L_0 = ___0_a;
		uintptr_t L_1;
		L_1 = CLIB_ppf_MatchmakingAdminSnapshotCandidateArray_GetSize_m8A34154291D351ADB872A315BDFFF8F4829F13B1(L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint32_t L_2;
		L_2 = UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8(L_1, NULL);
		V_0 = L_2;
		// this.Capacity = count;
		int32_t L_3 = V_0;
		List_1_set_Capacity_m9C560D90140238E989BCCCBF65E8EB846AF78497(__this, L_3, List_1_set_Capacity_m9C560D90140238E989BCCCBF65E8EB846AF78497_RuntimeMethod_var);
		// TotalCount = (ulong)CLIB.ppf_MatchmakingAdminSnapshotCandidateArray_GetTotalCount(a);
		intptr_t L_4 = ___0_a;
		uintptr_t L_5;
		L_5 = CLIB_ppf_MatchmakingAdminSnapshotCandidateArray_GetTotalCount_m32171B9F840C1BB58BC5133F6996B70DB522AB8A(L_4, NULL);
		uint64_t L_6;
		L_6 = UIntPtr_op_Explicit_mC39E70F0324C1C514A3044790BC19C5FC4C58E1C(L_5, NULL);
		__this->___TotalCount_8 = L_6;
		// for (int i = 0; i < count; i++)
		V_1 = 0;
		goto IL_004a;
	}

IL_002e:
	{
		// this.Add(new MatchmakingAdminSnapshotCandidate(CLIB.ppf_MatchmakingAdminSnapshotCandidateArray_GetElement(a, (UIntPtr) i)));
		intptr_t L_7 = ___0_a;
		int32_t L_8 = V_1;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_9;
		L_9 = UIntPtr_op_Explicit_mF1E7911DD5AC13B5E59EE8C7903469D12A3861E8(((int64_t)L_8), NULL);
		intptr_t L_10;
		L_10 = CLIB_ppf_MatchmakingAdminSnapshotCandidateArray_GetElement_m995C8E82A7465BAC0FA0DC0B5635B2CC3EF7D0F0(L_7, L_9, NULL);
		MatchmakingAdminSnapshotCandidate_t2325F5337C73FF55AB6D932F2A14C97E3A813CCC* L_11 = (MatchmakingAdminSnapshotCandidate_t2325F5337C73FF55AB6D932F2A14C97E3A813CCC*)il2cpp_codegen_object_new(MatchmakingAdminSnapshotCandidate_t2325F5337C73FF55AB6D932F2A14C97E3A813CCC_il2cpp_TypeInfo_var);
		NullCheck(L_11);
		MatchmakingAdminSnapshotCandidate__ctor_m3F82611D0119A6464ECE680CFF74F29F07BD7B5F(L_11, L_10, NULL);
		List_1_Add_mE84497F7EEB65DCBE2B85C3A5F3FF2DC6422FED0_inline(__this, L_11, List_1_Add_mE84497F7EEB65DCBE2B85C3A5F3FF2DC6422FED0_RuntimeMethod_var);
		// for (int i = 0; i < count; i++)
		int32_t L_12 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
	}

IL_004a:
	{
		// for (int i = 0; i < count; i++)
		int32_t L_13 = V_1;
		int32_t L_14 = V_0;
		if ((((int32_t)L_13) < ((int32_t)L_14)))
		{
			goto IL_002e;
		}
	}
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
// System.Void Pico.Platform.Models.MatchmakingBrowseResult::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MatchmakingBrowseResult__ctor_m101E8779EA83ECCC58E6FA35A6AFB285A717C331 (MatchmakingBrowseResult_tC20A58B18DE8FF7F9A4E7450063ACB8FC38D2C58* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MatchmakingEnqueueResult_t620CF96FB5A92A1783E9882E651C0CA76E2E3D8D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MatchmakingRoomList_t97325021F617542B368184443F745CC637C866B7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public MatchmakingBrowseResult(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// EnqueueResult = new MatchmakingEnqueueResult(CLIB.ppf_MatchmakingBrowseResult_GetEnqueueResult(o));
		intptr_t L_0 = ___0_o;
		intptr_t L_1;
		L_1 = CLIB_ppf_MatchmakingBrowseResult_GetEnqueueResult_m62835610E7E862A8F90CD939A40FA4B7F8B04DAA(L_0, NULL);
		MatchmakingEnqueueResult_t620CF96FB5A92A1783E9882E651C0CA76E2E3D8D* L_2 = (MatchmakingEnqueueResult_t620CF96FB5A92A1783E9882E651C0CA76E2E3D8D*)il2cpp_codegen_object_new(MatchmakingEnqueueResult_t620CF96FB5A92A1783E9882E651C0CA76E2E3D8D_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		MatchmakingEnqueueResult__ctor_m1DBC53F8E1F86E378EBEAC70B8F4970AB5E522B2(L_2, L_1, NULL);
		__this->___EnqueueResult_0 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___EnqueueResult_0), (void*)L_2);
		// MatchmakingRooms = new MatchmakingRoomList(CLIB.ppf_MatchmakingBrowseResult_GetRooms(o));
		intptr_t L_3 = ___0_o;
		intptr_t L_4;
		L_4 = CLIB_ppf_MatchmakingBrowseResult_GetRooms_m1B6E3043995372FDD6DEA166137833B3BE1BC7DE(L_3, NULL);
		MatchmakingRoomList_t97325021F617542B368184443F745CC637C866B7* L_5 = (MatchmakingRoomList_t97325021F617542B368184443F745CC637C866B7*)il2cpp_codegen_object_new(MatchmakingRoomList_t97325021F617542B368184443F745CC637C866B7_il2cpp_TypeInfo_var);
		NullCheck(L_5);
		MatchmakingRoomList__ctor_mBF3ED0010AE228A6D6F3C03B33A5766A8DC45A2C(L_5, L_4, NULL);
		__this->___MatchmakingRooms_1 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___MatchmakingRooms_1), (void*)L_5);
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
// System.Void Pico.Platform.Models.MatchmakingEnqueueResult::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MatchmakingEnqueueResult__ctor_m1DBC53F8E1F86E378EBEAC70B8F4970AB5E522B2 (MatchmakingEnqueueResult_t620CF96FB5A92A1783E9882E651C0CA76E2E3D8D* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MatchmakingAdminSnapshot_tF75B3A1A51D503587990BECC068C30E7671EE451_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	intptr_t V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		// public MatchmakingEnqueueResult(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// var pointer = CLIB.ppf_MatchmakingEnqueueResult_GetAdminSnapshot(o);
		intptr_t L_0 = ___0_o;
		intptr_t L_1;
		L_1 = CLIB_ppf_MatchmakingEnqueueResult_GetAdminSnapshot_m87701284D7265519A6B100F8F6B159259DFF3118(L_0, NULL);
		V_0 = L_1;
		// if (pointer == IntPtr.Zero)
		intptr_t L_2 = V_0;
		intptr_t L_3 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		bool L_4;
		L_4 = IntPtr_op_Equality_m7D9CDCDE9DC2A0C2C614633F4921E90187FAB271(L_2, L_3, NULL);
		if (!L_4)
		{
			goto IL_0023;
		}
	}
	{
		// AdminSnapshotOptional = null;
		__this->___AdminSnapshotOptional_0 = (MatchmakingAdminSnapshot_tF75B3A1A51D503587990BECC068C30E7671EE451*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___AdminSnapshotOptional_0), (void*)(MatchmakingAdminSnapshot_tF75B3A1A51D503587990BECC068C30E7671EE451*)NULL);
		goto IL_002f;
	}

IL_0023:
	{
		// AdminSnapshotOptional = new MatchmakingAdminSnapshot(pointer);
		intptr_t L_5 = V_0;
		MatchmakingAdminSnapshot_tF75B3A1A51D503587990BECC068C30E7671EE451* L_6 = (MatchmakingAdminSnapshot_tF75B3A1A51D503587990BECC068C30E7671EE451*)il2cpp_codegen_object_new(MatchmakingAdminSnapshot_tF75B3A1A51D503587990BECC068C30E7671EE451_il2cpp_TypeInfo_var);
		NullCheck(L_6);
		MatchmakingAdminSnapshot__ctor_m17C01478ACBD07391C18DD67F372B6471E2E971F(L_6, L_5, NULL);
		__this->___AdminSnapshotOptional_0 = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___AdminSnapshotOptional_0), (void*)L_6);
	}

IL_002f:
	{
		// AverageWait = CLIB.ppf_MatchmakingEnqueueResult_GetAverageWait(o);
		intptr_t L_7 = ___0_o;
		uint32_t L_8;
		L_8 = CLIB_ppf_MatchmakingEnqueueResult_GetAverageWait_m8FECAEC6709FA5A2FBDE7DC205D6E57D43941828(L_7, NULL);
		__this->___AverageWait_1 = L_8;
		// MatchesInLastHourCount = CLIB.ppf_MatchmakingEnqueueResult_GetMatchesInLastHourCount(o);
		intptr_t L_9 = ___0_o;
		uint32_t L_10;
		L_10 = CLIB_ppf_MatchmakingEnqueueResult_GetMatchesInLastHourCount_mF388BE2C8932701C42D1DF7D08AB933AC7231408(L_9, NULL);
		__this->___MatchesInLastHourCount_2 = L_10;
		// MaxExpectedWait = CLIB.ppf_MatchmakingEnqueueResult_GetMaxExpectedWait(o);
		intptr_t L_11 = ___0_o;
		uint32_t L_12;
		L_12 = CLIB_ppf_MatchmakingEnqueueResult_GetMaxExpectedWait_m25210EB92326DFE11D42E0F5B3524485D68A3A42(L_11, NULL);
		__this->___MaxExpectedWait_3 = L_12;
		// Pool = CLIB.ppf_MatchmakingEnqueueResult_GetPool(o);
		intptr_t L_13 = ___0_o;
		String_t* L_14;
		L_14 = CLIB_ppf_MatchmakingEnqueueResult_GetPool_mA9A02C7043D099D9D62B0F36DC1C628E73FF858C(L_13, NULL);
		__this->___Pool_4 = L_14;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Pool_4), (void*)L_14);
		// RecentMatchPercentage = CLIB.ppf_MatchmakingEnqueueResult_GetRecentMatchPercentage(o);
		intptr_t L_15 = ___0_o;
		uint32_t L_16;
		L_16 = CLIB_ppf_MatchmakingEnqueueResult_GetRecentMatchPercentage_mBB8931E1C1A4577CD3C44C8591700B5A4948B4EC(L_15, NULL);
		__this->___RecentMatchPercentage_5 = L_16;
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
// System.Void Pico.Platform.Models.MatchmakingEnqueueResultAndRoom::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MatchmakingEnqueueResultAndRoom__ctor_mFC020AD2EF28241926570B5722672EF24C5EFADA (MatchmakingEnqueueResultAndRoom_t01215772818E3385FC96DCE8D46E9906FCA8D9FC* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MatchmakingEnqueueResult_t620CF96FB5A92A1783E9882E651C0CA76E2E3D8D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public MatchmakingEnqueueResultAndRoom(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// MatchmakingEnqueueResult = new MatchmakingEnqueueResult(CLIB.ppf_MatchmakingEnqueueResultAndRoom_GetMatchmakingEnqueueResult(o));
		intptr_t L_0 = ___0_o;
		intptr_t L_1;
		L_1 = CLIB_ppf_MatchmakingEnqueueResultAndRoom_GetMatchmakingEnqueueResult_mED20A27D4CFF9F5276D9AC63FE29F1B6C5A7AB15(L_0, NULL);
		MatchmakingEnqueueResult_t620CF96FB5A92A1783E9882E651C0CA76E2E3D8D* L_2 = (MatchmakingEnqueueResult_t620CF96FB5A92A1783E9882E651C0CA76E2E3D8D*)il2cpp_codegen_object_new(MatchmakingEnqueueResult_t620CF96FB5A92A1783E9882E651C0CA76E2E3D8D_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		MatchmakingEnqueueResult__ctor_m1DBC53F8E1F86E378EBEAC70B8F4970AB5E522B2(L_2, L_1, NULL);
		__this->___MatchmakingEnqueueResult_0 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___MatchmakingEnqueueResult_0), (void*)L_2);
		// Room = new Room(CLIB.ppf_MatchmakingEnqueueResultAndRoom_GetRoom(o));
		intptr_t L_3 = ___0_o;
		intptr_t L_4;
		L_4 = CLIB_ppf_MatchmakingEnqueueResultAndRoom_GetRoom_m86009926F9CA13C7F5CD77CEF97F249D6740B792(L_3, NULL);
		Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135* L_5 = (Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135*)il2cpp_codegen_object_new(Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135_il2cpp_TypeInfo_var);
		NullCheck(L_5);
		Room__ctor_mB6AF794D98BC22F1081870DD63E403520D1172A4(L_5, L_4, NULL);
		__this->___Room_1 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Room_1), (void*)L_5);
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
// System.Void Pico.Platform.Models.MatchmakingRoom::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MatchmakingRoom__ctor_m46F4C484B14D0EFE7025B8533694403B300BA600 (MatchmakingRoom_t564ECF1B3DF437F6B3DE5EC03A5E173193CE6C74* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public MatchmakingRoom(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// this.PingTime = CLIB.ppf_MatchmakingRoom_GetPingTime(o);
		intptr_t L_0 = ___0_o;
		uint32_t L_1;
		L_1 = CLIB_ppf_MatchmakingRoom_GetPingTime_mAA23B36D8A287BA035E6ED85F526D3F14AF78DC1(L_0, NULL);
		__this->___PingTime_1 = L_1;
		// this.Room = new Models.Room(CLIB.ppf_MatchmakingRoom_GetRoom(o));
		intptr_t L_2 = ___0_o;
		intptr_t L_3;
		L_3 = CLIB_ppf_MatchmakingRoom_GetRoom_m0E5CBF5B108FE569A7F3FDA771CA8C6C1F9212A7(L_2, NULL);
		Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135* L_4 = (Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135*)il2cpp_codegen_object_new(Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135_il2cpp_TypeInfo_var);
		NullCheck(L_4);
		Room__ctor_mB6AF794D98BC22F1081870DD63E403520D1172A4(L_4, L_3, NULL);
		__this->___Room_0 = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Room_0), (void*)L_4);
		// this.HasPingTime = CLIB.ppf_MatchmakingRoom_HasPingTime(o);
		intptr_t L_5 = ___0_o;
		bool L_6;
		L_6 = CLIB_ppf_MatchmakingRoom_HasPingTime_mDC473D8557C77E6171E24B8FEBB87135C971F025(L_5, NULL);
		__this->___HasPingTime_2 = L_6;
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
// System.Void Pico.Platform.Models.MatchmakingRoomList::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MatchmakingRoomList__ctor_mBF3ED0010AE228A6D6F3C03B33A5766A8DC45A2C (MatchmakingRoomList_t97325021F617542B368184443F745CC637C866B7* __this, intptr_t ___0_a, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mC7D6941F0CB7269D1259683EB81DAF543E912E13_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_set_Capacity_mFAD4171F2861E97F209DAECB9E5C50BCD34018E4_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MatchmakingRoom_t564ECF1B3DF437F6B3DE5EC03A5E173193CE6C74_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageArray_1__ctor_mB4514016DE6C8FA4D4FA07951B03B60B17241AF4_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	uint32_t V_1 = 0;
	{
		// public MatchmakingRoomList(IntPtr a)
		MessageArray_1__ctor_mB4514016DE6C8FA4D4FA07951B03B60B17241AF4(__this, MessageArray_1__ctor_mB4514016DE6C8FA4D4FA07951B03B60B17241AF4_RuntimeMethod_var);
		// TotalCount = CLIB.ppf_MatchmakingRoomArray_GetTotalCount(a);
		intptr_t L_0 = ___0_a;
		int32_t L_1;
		L_1 = CLIB_ppf_MatchmakingRoomArray_GetTotalCount_mBFC4A61756F15490A4E65617803E4DF9555076DD(L_0, NULL);
		__this->___TotalCount_8 = L_1;
		// int count = (int) CLIB.ppf_MatchmakingRoomArray_GetSize(a);
		intptr_t L_2 = ___0_a;
		uintptr_t L_3;
		L_3 = CLIB_ppf_MatchmakingRoomArray_GetSize_m3E0F05F00CAB266C337B39C36066975FA408CE99(L_2, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint32_t L_4;
		L_4 = UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8(L_3, NULL);
		V_0 = L_4;
		// this.Capacity = count;
		int32_t L_5 = V_0;
		List_1_set_Capacity_mFAD4171F2861E97F209DAECB9E5C50BCD34018E4(__this, L_5, List_1_set_Capacity_mFAD4171F2861E97F209DAECB9E5C50BCD34018E4_RuntimeMethod_var);
		// for (uint i = 0; i < count; i++)
		V_1 = 0;
		goto IL_0044;
	}

IL_0029:
	{
		// this.Add(new MatchmakingRoom(CLIB.ppf_MatchmakingRoomArray_GetElement(a, (UIntPtr) i)));
		intptr_t L_6 = ___0_a;
		uint32_t L_7 = V_1;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_8;
		L_8 = UIntPtr_op_Explicit_mD94DCD8965DD2E7D5A3370A04CCEDBE5937C078C(L_7, NULL);
		intptr_t L_9;
		L_9 = CLIB_ppf_MatchmakingRoomArray_GetElement_m23B64ADB8084AAB92FB7CEA0668DE9A1E5233A42(L_6, L_8, NULL);
		MatchmakingRoom_t564ECF1B3DF437F6B3DE5EC03A5E173193CE6C74* L_10 = (MatchmakingRoom_t564ECF1B3DF437F6B3DE5EC03A5E173193CE6C74*)il2cpp_codegen_object_new(MatchmakingRoom_t564ECF1B3DF437F6B3DE5EC03A5E173193CE6C74_il2cpp_TypeInfo_var);
		NullCheck(L_10);
		MatchmakingRoom__ctor_m46F4C484B14D0EFE7025B8533694403B300BA600(L_10, L_9, NULL);
		List_1_Add_mC7D6941F0CB7269D1259683EB81DAF543E912E13_inline(__this, L_10, List_1_Add_mC7D6941F0CB7269D1259683EB81DAF543E912E13_RuntimeMethod_var);
		// for (uint i = 0; i < count; i++)
		uint32_t L_11 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add((int32_t)L_11, 1));
	}

IL_0044:
	{
		// for (uint i = 0; i < count; i++)
		uint32_t L_12 = V_1;
		int32_t L_13 = V_0;
		if ((((int64_t)((int64_t)(uint64_t)L_12)) < ((int64_t)((int64_t)L_13))))
		{
			goto IL_0029;
		}
	}
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
// System.Void Pico.Platform.Models.MatchmakingStats::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MatchmakingStats__ctor_mCD836C7E6D18085BEC85B00E26821CDC9389F801 (MatchmakingStats_tA7354632354901085E56D8553EF6B4A584424184* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public MatchmakingStats(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// DrawCount = CLIB.ppf_MatchmakingStats_GetDrawCount(o);
		intptr_t L_0 = ___0_o;
		uint32_t L_1;
		L_1 = CLIB_ppf_MatchmakingStats_GetDrawCount_mF4A456FC1B4466E8C9811C09BE8182AAD7457C59(L_0, NULL);
		__this->___DrawCount_0 = L_1;
		// LossCount = CLIB.ppf_MatchmakingStats_GetLossCount(o);
		intptr_t L_2 = ___0_o;
		uint32_t L_3;
		L_3 = CLIB_ppf_MatchmakingStats_GetLossCount_mBB791178F0B33C965D307702642E9AF81E5DD8B9(L_2, NULL);
		__this->___LossCount_1 = L_3;
		// SkillLevel = CLIB.ppf_MatchmakingStats_GetSkillLevel(o);
		intptr_t L_4 = ___0_o;
		uint32_t L_5;
		L_5 = CLIB_ppf_MatchmakingStats_GetSkillLevel_mA2724D972FC9C34685DE2133B15F24A310985F03(L_4, NULL);
		__this->___SkillLevel_2 = L_5;
		// SkillMean = CLIB.ppf_MatchmakingStats_GetSkillMean(o);
		intptr_t L_6 = ___0_o;
		double L_7;
		L_7 = CLIB_ppf_MatchmakingStats_GetSkillMean_mBF97220B599E89F923BF50B2093551F627A4D1E3(L_6, NULL);
		__this->___SkillMean_3 = L_7;
		// SkillStandardDeviation = CLIB.ppf_MatchmakingStats_GetSkillStandardDeviation(o);
		intptr_t L_8 = ___0_o;
		double L_9;
		L_9 = CLIB_ppf_MatchmakingStats_GetSkillStandardDeviation_m2325D7197971CD4E7B360EFDD698D579CD8E518F(L_8, NULL);
		__this->___SkillStandardDeviation_4 = L_9;
		// WinCount = CLIB.ppf_MatchmakingStats_GetWinCount(o);
		intptr_t L_10 = ___0_o;
		uint32_t L_11;
		L_11 = CLIB_ppf_MatchmakingStats_GetWinCount_mEBFA9453303F0D58F10B941BD5EFA84A672FC6AE(L_10, NULL);
		__this->___WinCount_5 = L_11;
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
// System.Void Pico.Platform.Models.RoomInviteNotification::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RoomInviteNotification__ctor_mDA79BD8FFD71AA71B259F71C4F7ADC58D97C8801 (RoomInviteNotification_t056C5D7720D5A52379CEB33A2BEB26EDB399E048* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	UnityException_tA1EC1E95ADE689CF6EB7FAFF77C160AE1F559067* V_0 = NULL;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		// public RoomInviteNotification(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// ID = CLIB.ppf_RoomInviteNotification_GetID(o);
		intptr_t L_0 = ___0_o;
		uint64_t L_1;
		L_1 = CLIB_ppf_RoomInviteNotification_GetID_mD6D10056CC12F0A434A6CC2740DDC1A952FEDB2D(L_0, NULL);
		__this->___ID_0 = L_1;
		// RoomID = CLIB.ppf_RoomInviteNotification_GetRoomID(o);
		intptr_t L_2 = ___0_o;
		uint64_t L_3;
		L_3 = CLIB_ppf_RoomInviteNotification_GetRoomID_mE73AAC70259740E82090E8687216CD4AC29DD87C(L_2, NULL);
		__this->___RoomID_1 = L_3;
		// SenderID = CLIB.ppf_RoomInviteNotification_GetSenderID(o);
		intptr_t L_4 = ___0_o;
		String_t* L_5;
		L_5 = CLIB_ppf_RoomInviteNotification_GetSenderID_m1D46374A1FAB8BADEEE67D5DBCCBE18DAE4A354F(L_4, NULL);
		__this->___SenderID_2 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___SenderID_2), (void*)L_5);
		// SentTime = new DateTime();
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D* L_6 = (DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D*)(&__this->___SentTime_3);
		il2cpp_codegen_initobj(L_6, sizeof(DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D));
	}
	try
	{// begin try (depth: 1)
		// SentTime = TimeUtil.SecondsToDateTime((long) CLIB.ppf_RoomInviteNotification_GetSentTime(o));
		intptr_t L_7 = ___0_o;
		uint64_t L_8;
		L_8 = CLIB_ppf_RoomInviteNotification_GetSentTime_mAEC1C6674E386A69539B2FA682BBBF2459DD0B19(L_7, NULL);
		il2cpp_codegen_runtime_class_init_inline(TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_9;
		L_9 = TimeUtil_SecondsToDateTime_m5DC84ED0EEB5AB8AAF833B2F5FF5E9F075C165F4(L_8, NULL);
		__this->___SentTime_3 = L_9;
		// }
		goto IL_005c;
	}// end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&UnityException_tA1EC1E95ADE689CF6EB7FAFF77C160AE1F559067_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0049;
		}
		throw e;
	}

CATCH_0049:
	{// begin catch(UnityEngine.UnityException)
		UnityException_tA1EC1E95ADE689CF6EB7FAFF77C160AE1F559067* L_10 = ((UnityException_tA1EC1E95ADE689CF6EB7FAFF77C160AE1F559067*)IL2CPP_GET_ACTIVE_EXCEPTION(UnityException_tA1EC1E95ADE689CF6EB7FAFF77C160AE1F559067*));;
		// catch (UnityException ex)
		V_0 = L_10;
		// Debug.LogWarning($"RoomInviteNotification get SentTime fail {ex}");
		UnityException_tA1EC1E95ADE689CF6EB7FAFF77C160AE1F559067* L_11 = V_0;
		String_t* L_12;
		L_12 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral9BBB32CCC21BB366F147DF39A51834651CDC854F)), L_11, NULL);
		il2cpp_codegen_runtime_class_init_inline(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var)));
		Debug_LogWarning_m33EF1B897E0C7C6FF538989610BFAFFEF4628CA9(L_12, NULL);
		// throw;
		IL2CPP_RETHROW_MANAGED_EXCEPTION(IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*));
	}// end catch (depth: 1)

IL_005c:
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
// System.Void Pico.Platform.Models.RoomInviteNotificationList::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RoomInviteNotificationList__ctor_m73A4AA4D73528CD773599E60DF850261321BF738 (RoomInviteNotificationList_t1203312F5F6E7E53899A09886C7716CD0C55D9A6* __this, intptr_t ___0_a, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mD38485CA318AF8F55C5985FACCBAA11B2D534F69_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_set_Capacity_mD5F6FA2BE282F629E5D80DDC855BCC02C875A92C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageArray_1__ctor_mFF477189E1B6F9EDC567DBA6165ECCB6EEA64992_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RoomInviteNotification_t056C5D7720D5A52379CEB33A2BEB26EDB399E048_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&String_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB7C45DD316C68ABF3429C20058C2981C652192F2);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	uint32_t V_1 = 0;
	RoomInviteNotificationList_t1203312F5F6E7E53899A09886C7716CD0C55D9A6* G_B2_0 = NULL;
	RoomInviteNotificationList_t1203312F5F6E7E53899A09886C7716CD0C55D9A6* G_B1_0 = NULL;
	String_t* G_B3_0 = NULL;
	RoomInviteNotificationList_t1203312F5F6E7E53899A09886C7716CD0C55D9A6* G_B3_1 = NULL;
	{
		// public RoomInviteNotificationList(IntPtr a)
		MessageArray_1__ctor_mFF477189E1B6F9EDC567DBA6165ECCB6EEA64992(__this, MessageArray_1__ctor_mFF477189E1B6F9EDC567DBA6165ECCB6EEA64992_RuntimeMethod_var);
		// TotalCount = CLIB.ppf_RoomInviteNotificationArray_GetTotalCount(a);
		intptr_t L_0 = ___0_a;
		int32_t L_1;
		L_1 = CLIB_ppf_RoomInviteNotificationArray_GetTotalCount_m49BDB4D93FC555216E86B5DD8275B6DAB19850CB(L_0, NULL);
		__this->___TotalCount_8 = L_1;
		// NextPageParam = CLIB.ppf_RoomInviteNotificationArray_HasNextPage(a) ? "true" : string.Empty;
		intptr_t L_2 = ___0_a;
		bool L_3;
		L_3 = CLIB_ppf_RoomInviteNotificationArray_HasNextPage_mE7D2FE60429DA2B997AE8CDA87FF5B48626A119E(L_2, NULL);
		G_B1_0 = __this;
		if (L_3)
		{
			G_B2_0 = __this;
			goto IL_0022;
		}
	}
	{
		String_t* L_4 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->___Empty_6;
		G_B3_0 = L_4;
		G_B3_1 = G_B1_0;
		goto IL_0027;
	}

IL_0022:
	{
		G_B3_0 = _stringLiteralB7C45DD316C68ABF3429C20058C2981C652192F2;
		G_B3_1 = G_B2_0;
	}

IL_0027:
	{
		NullCheck(G_B3_1);
		((MessageArray_1_t48F2634F7CE492870D7F60BCDB4ECBAEABA4E185*)G_B3_1)->___NextPageParam_6 = G_B3_0;
		Il2CppCodeGenWriteBarrier((void**)(&((MessageArray_1_t48F2634F7CE492870D7F60BCDB4ECBAEABA4E185*)G_B3_1)->___NextPageParam_6), (void*)G_B3_0);
		// int count = (int) CLIB.ppf_RoomInviteNotificationArray_GetSize(a);
		intptr_t L_5 = ___0_a;
		uintptr_t L_6;
		L_6 = CLIB_ppf_RoomInviteNotificationArray_GetSize_m8DB92AE82619BEEE1AB8BC0669A94B56E6C03FBA(L_5, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint32_t L_7;
		L_7 = UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8(L_6, NULL);
		V_0 = L_7;
		// this.Capacity = count;
		int32_t L_8 = V_0;
		List_1_set_Capacity_mD5F6FA2BE282F629E5D80DDC855BCC02C875A92C(__this, L_8, List_1_set_Capacity_mD5F6FA2BE282F629E5D80DDC855BCC02C875A92C_RuntimeMethod_var);
		// for (uint i = 0; i < count; i++)
		V_1 = 0;
		goto IL_005e;
	}

IL_0043:
	{
		// this.Add(new RoomInviteNotification(CLIB.ppf_RoomInviteNotificationArray_GetElement(a, (UIntPtr)i)));
		intptr_t L_9 = ___0_a;
		uint32_t L_10 = V_1;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_11;
		L_11 = UIntPtr_op_Explicit_mD94DCD8965DD2E7D5A3370A04CCEDBE5937C078C(L_10, NULL);
		intptr_t L_12;
		L_12 = CLIB_ppf_RoomInviteNotificationArray_GetElement_mAADDBBD091434F67605C7E98B721EAB83DC3A0D8(L_9, L_11, NULL);
		RoomInviteNotification_t056C5D7720D5A52379CEB33A2BEB26EDB399E048* L_13 = (RoomInviteNotification_t056C5D7720D5A52379CEB33A2BEB26EDB399E048*)il2cpp_codegen_object_new(RoomInviteNotification_t056C5D7720D5A52379CEB33A2BEB26EDB399E048_il2cpp_TypeInfo_var);
		NullCheck(L_13);
		RoomInviteNotification__ctor_mDA79BD8FFD71AA71B259F71C4F7ADC58D97C8801(L_13, L_12, NULL);
		List_1_Add_mD38485CA318AF8F55C5985FACCBAA11B2D534F69_inline(__this, L_13, List_1_Add_mD38485CA318AF8F55C5985FACCBAA11B2D534F69_RuntimeMethod_var);
		// for (uint i = 0; i < count; i++)
		uint32_t L_14 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add((int32_t)L_14, 1));
	}

IL_005e:
	{
		// for (uint i = 0; i < count; i++)
		uint32_t L_15 = V_1;
		int32_t L_16 = V_0;
		if ((((int64_t)((int64_t)(uint64_t)L_15)) < ((int64_t)((int64_t)L_16))))
		{
			goto IL_0043;
		}
	}
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
// System.Void Pico.Platform.Models.Packet::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Packet__ctor_m5C43214F5C91CFF8027D837A947DB120FC5FE09F (Packet_tE7ABCB3CA16D45A82E180266269EC1B89F8054A9* __this, intptr_t ___0_handler, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public Packet(IntPtr handler)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// this.handler = handler;
		intptr_t L_0 = ___0_handler;
		__this->___handler_1 = L_0;
		// this.size = (ulong) CLIB.ppf_Packet_GetSize(handler);
		intptr_t L_1 = ___0_handler;
		uintptr_t L_2;
		L_2 = CLIB_ppf_Packet_GetSize_mB04A129338AA0D2154D3DB303C4DFC6D64311858(L_1, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint64_t L_3;
		L_3 = UIntPtr_op_Explicit_mC39E70F0324C1C514A3044790BC19C5FC4C58E1C(L_2, NULL);
		__this->___size_0 = L_3;
		// }
		return;
	}
}
// System.UInt64 Pico.Platform.Models.Packet::GetBytes(System.Byte[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t Packet_GetBytes_mA6CF76305AA065D7CC120D0883D390B69CAC4529 (Packet_tE7ABCB3CA16D45A82E180266269EC1B89F8054A9* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_dest, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if ((ulong) dest.LongLength >= size)
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___0_dest;
		NullCheck(L_0);
		uint64_t L_1 = __this->___size_0;
		if ((!(((uint64_t)((int64_t)((int32_t)(((RuntimeArray*)L_0)->max_length)))) >= ((uint64_t)L_1))))
		{
			goto IL_002b;
		}
	}
	{
		// Marshal.Copy(CLIB.ppf_Packet_GetBytes(handler), dest, 0, (int) size);
		intptr_t L_2 = __this->___handler_1;
		intptr_t L_3;
		L_3 = CLIB_ppf_Packet_GetBytes_mF023FD284DEE919E175C1C48DBE2D22D6EE97381(L_2, NULL);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = ___0_dest;
		uint64_t L_5 = __this->___size_0;
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		Marshal_Copy_mF7402FFDB520EA1B8D1C32B368DBEE4B13F1BE77(L_3, L_4, 0, ((int32_t)L_5), NULL);
		// return size;
		uint64_t L_6 = __this->___size_0;
		return L_6;
	}

IL_002b:
	{
		// throw new ArgumentException($"Dest array can't  hold {size} bytes");
		uint64_t L_7 = __this->___size_0;
		uint64_t L_8 = L_7;
		RuntimeObject* L_9 = Box(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var)), &L_8);
		String_t* L_10;
		L_10 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral117F539165B45A5AC4BAAE9D28D7843EC5548C9E)), L_9, NULL);
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_11 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		NullCheck(L_11);
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_11, L_10, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_11, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Packet_GetBytes_mA6CF76305AA065D7CC120D0883D390B69CAC4529_RuntimeMethod_var)));
	}
}
// System.String Pico.Platform.Models.Packet::GetBytes()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Packet_GetBytes_m338C6646444C8C294FFFE5686F1EABAF17C06784 (Packet_tE7ABCB3CA16D45A82E180266269EC1B89F8054A9* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Packet_GetBytes_m338C6646444C8C294FFFE5686F1EABAF17C06784_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&String_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_0 = NULL;
	{
		// if (size > 0)
		uint64_t L_0 = __this->___size_0;
		if ((!(((uint64_t)L_0) > ((uint64_t)((int64_t)0)))))
		{
			goto IL_003c;
		}
	}
	{
		// byte[] bytes = new byte[size];
		uint64_t L_1 = __this->___size_0;
		if ((uint64_t)(L_1) > INTPTR_MAX) IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), Packet_GetBytes_m338C6646444C8C294FFFE5686F1EABAF17C06784_RuntimeMethod_var);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((intptr_t)L_1));
		V_0 = L_2;
		// Marshal.Copy(CLIB.ppf_Packet_GetBytes(handler), bytes, 0, (int) size);
		intptr_t L_3 = __this->___handler_1;
		intptr_t L_4;
		L_4 = CLIB_ppf_Packet_GetBytes_mF023FD284DEE919E175C1C48DBE2D22D6EE97381(L_3, NULL);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = V_0;
		uint64_t L_6 = __this->___size_0;
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		Marshal_Copy_mF7402FFDB520EA1B8D1C32B368DBEE4B13F1BE77(L_4, L_5, 0, ((int32_t)L_6), NULL);
		// return System.Text.Encoding.UTF8.GetString(bytes);
		Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* L_7;
		L_7 = Encoding_get_UTF8_m9FA98A53CE96FD6D02982625C5246DD36C1235C9(NULL);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_8 = V_0;
		NullCheck(L_7);
		String_t* L_9;
		L_9 = VirtualFuncInvoker1< String_t*, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* >::Invoke(33 /* System.String System.Text.Encoding::GetString(System.Byte[]) */, L_7, L_8);
		return L_9;
	}

IL_003c:
	{
		// return string.Empty;
		String_t* L_10 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->___Empty_6;
		return L_10;
	}
}
// System.String Pico.Platform.Models.Packet::get_SenderId()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Packet_get_SenderId_mB8BFEDC8A6E6F97D55A2B5B5B04A25C834E853D3 (Packet_tE7ABCB3CA16D45A82E180266269EC1B89F8054A9* __this, const RuntimeMethod* method) 
{
	{
		// get { return CLIB.ppf_Packet_GetSenderID(handler); }
		intptr_t L_0 = __this->___handler_1;
		String_t* L_1;
		L_1 = CLIB_ppf_Packet_GetSenderID_m94CE0688625FD51880BEAA2CDBE9C28EEAB7CD97(L_0, NULL);
		return L_1;
	}
}
// System.UInt64 Pico.Platform.Models.Packet::get_Size()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t Packet_get_Size_m1F6CA0C7A29793E39D7C97D8888B66E0A5C90DD5 (Packet_tE7ABCB3CA16D45A82E180266269EC1B89F8054A9* __this, const RuntimeMethod* method) 
{
	{
		// get { return size; }
		uint64_t L_0 = __this->___size_0;
		return L_0;
	}
}
// System.Void Pico.Platform.Models.Packet::Finalize()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Packet_Finalize_m3D78A8A8A722F914BEA161A7459856B1C0AE59FB (Packet_tE7ABCB3CA16D45A82E180266269EC1B89F8054A9* __this, const RuntimeMethod* method) 
{
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0008:
			{// begin finally (depth: 1)
				// }
				Object_Finalize_mC98C96301CCABFE00F1A7EF8E15DF507CACD42B2(__this, NULL);
				return;
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			// Dispose();
			Packet_Dispose_m31A384FDEF4FA99104B062F2739AC7EE812A1D12(__this, NULL);
			goto IL_000f;
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_000f:
	{
		// }
		return;
	}
}
// System.Void Pico.Platform.Models.Packet::Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Packet_Dispose_m31A384FDEF4FA99104B062F2739AC7EE812A1D12 (Packet_tE7ABCB3CA16D45A82E180266269EC1B89F8054A9* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GC_t920F9CF6EBB7C787E5010A4352E1B587F356DC58_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// CLIB.ppf_Packet_Free(handler);
		intptr_t L_0 = __this->___handler_1;
		CLIB_ppf_Packet_Free_m0922C9E7C571AAC53155733B5BC94C8A1299078E(L_0, NULL);
		// GC.SuppressFinalize(this);
		il2cpp_codegen_runtime_class_init_inline(GC_t920F9CF6EBB7C787E5010A4352E1B587F356DC58_il2cpp_TypeInfo_var);
		GC_SuppressFinalize_m71815DBD5A0CD2EA1BE43317B08B7A14949EDC65(__this, NULL);
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
// System.Void Pico.Platform.Models.Destination::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Destination__ctor_mB1261B84D715AED778CC96E68B1F2C0907CF8543 (Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public Destination(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// ApiName = CLIB.ppf_Destination_GetApiName(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_Destination_GetApiName_m0358EA5D0C2969A214D5D61E0F49A4F1CA223B48(L_0, NULL);
		__this->___ApiName_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___ApiName_0), (void*)L_1);
		// DeeplinkMessage = CLIB.ppf_Destination_GetDeeplinkMessage(o);
		intptr_t L_2 = ___0_o;
		String_t* L_3;
		L_3 = CLIB_ppf_Destination_GetDeeplinkMessage_mB3126F2C2D771F7FE39D1A7394AEA01BD6D976A0(L_2, NULL);
		__this->___DeeplinkMessage_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___DeeplinkMessage_1), (void*)L_3);
		// DisplayName = CLIB.ppf_Destination_GetDisplayName(o);
		intptr_t L_4 = ___0_o;
		String_t* L_5;
		L_5 = CLIB_ppf_Destination_GetDisplayName_m57C826273ECA1263EC1434BE117FA7D369745BD7(L_4, NULL);
		__this->___DisplayName_2 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___DisplayName_2), (void*)L_5);
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
// System.Void Pico.Platform.Models.DestinationList::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DestinationList__ctor_m047765177D1DB62F5343E709061ABE0D74F92683 (DestinationList_t41BB93309FA194DCC59A75DF41CE7FE6FC8E08EF* __this, intptr_t ___0_a, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m4F59D0CC812DAC6ECC6BFC85CDD3210501B8FFD0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_set_Capacity_mA24D986986B27033E4B1A500D132B53EAF4F974D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageArray_1__ctor_m070B185DC9BE9A46B820CFCFED8A57D14830275F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		// public DestinationList(IntPtr a)
		MessageArray_1__ctor_m070B185DC9BE9A46B820CFCFED8A57D14830275F(__this, MessageArray_1__ctor_m070B185DC9BE9A46B820CFCFED8A57D14830275F_RuntimeMethod_var);
		// var count = (int) CLIB.ppf_DestinationArray_GetSize(a);
		intptr_t L_0 = ___0_a;
		uintptr_t L_1;
		L_1 = CLIB_ppf_DestinationArray_GetSize_mA1EDBE551B0CC115EA4775DBE0582B063C1353D6(L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint32_t L_2;
		L_2 = UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8(L_1, NULL);
		V_0 = L_2;
		// this.Capacity = count;
		int32_t L_3 = V_0;
		List_1_set_Capacity_mA24D986986B27033E4B1A500D132B53EAF4F974D(__this, L_3, List_1_set_Capacity_mA24D986986B27033E4B1A500D132B53EAF4F974D_RuntimeMethod_var);
		// for (int i = 0; i < count; i++)
		V_1 = 0;
		goto IL_0039;
	}

IL_001d:
	{
		// this.Add(new Destination(CLIB.ppf_DestinationArray_GetElement(a, (UIntPtr) i)));
		intptr_t L_4 = ___0_a;
		int32_t L_5 = V_1;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_6;
		L_6 = UIntPtr_op_Explicit_mF1E7911DD5AC13B5E59EE8C7903469D12A3861E8(((int64_t)L_5), NULL);
		intptr_t L_7;
		L_7 = CLIB_ppf_DestinationArray_GetElement_mA7387DBCB2F0792EC947B62AF1543C5D1FE083DE(L_4, L_6, NULL);
		Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211* L_8 = (Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211*)il2cpp_codegen_object_new(Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211_il2cpp_TypeInfo_var);
		NullCheck(L_8);
		Destination__ctor_mB1261B84D715AED778CC96E68B1F2C0907CF8543(L_8, L_7, NULL);
		List_1_Add_m4F59D0CC812DAC6ECC6BFC85CDD3210501B8FFD0_inline(__this, L_8, List_1_Add_m4F59D0CC812DAC6ECC6BFC85CDD3210501B8FFD0_RuntimeMethod_var);
		// for (int i = 0; i < count; i++)
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0039:
	{
		// for (int i = 0; i < count; i++)
		int32_t L_10 = V_1;
		int32_t L_11 = V_0;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_001d;
		}
	}
	{
		// NextPageParam = CLIB.ppf_DestinationArray_GetNextPageParam(a);
		intptr_t L_12 = ___0_a;
		String_t* L_13;
		L_13 = CLIB_ppf_DestinationArray_GetNextPageParam_m91A57A95DE03A15CED98D64A436A189075C78E85(L_12, NULL);
		((MessageArray_1_t77601FC32D4AB8164AF6BDA2F26DA8D5510A8C1D*)__this)->___NextPageParam_6 = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((MessageArray_1_t77601FC32D4AB8164AF6BDA2F26DA8D5510A8C1D*)__this)->___NextPageParam_6), (void*)L_13);
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
// System.Void Pico.Platform.Models.ApplicationInvite::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ApplicationInvite__ctor_m0A9B118AFC2B0FB82F841901E3AE34B083AFF954 (ApplicationInvite_t95D2E15775E4CD15D060CDF6CF25EDB854EB67D7* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public ApplicationInvite(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Destination = new Destination(CLIB.ppf_ApplicationInvite_GetDestination(o));
		intptr_t L_0 = ___0_o;
		intptr_t L_1;
		L_1 = CLIB_ppf_ApplicationInvite_GetDestination_mA84E56331981169F0CFFDA755B04A556AE7D952A(L_0, NULL);
		Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211* L_2 = (Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211*)il2cpp_codegen_object_new(Destination_tA15CF6CD249A4E5BB7F74D6807F786FABDE29211_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		Destination__ctor_mB1261B84D715AED778CC96E68B1F2C0907CF8543(L_2, L_1, NULL);
		__this->___Destination_0 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Destination_0), (void*)L_2);
		// Recipient = new User(CLIB.ppf_ApplicationInvite_GetRecipient(o));
		intptr_t L_3 = ___0_o;
		intptr_t L_4;
		L_4 = CLIB_ppf_ApplicationInvite_GetRecipient_m01707F7228F5D1B789120759EB5427B8046580E8(L_3, NULL);
		User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4* L_5 = (User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4*)il2cpp_codegen_object_new(User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4_il2cpp_TypeInfo_var);
		NullCheck(L_5);
		User__ctor_m0A17383A33457E27EB6AD299C81C77AC1802E0D1(L_5, L_4, NULL);
		__this->___Recipient_1 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Recipient_1), (void*)L_5);
		// ID = CLIB.ppf_ApplicationInvite_GetID(o);
		intptr_t L_6 = ___0_o;
		uint64_t L_7;
		L_7 = CLIB_ppf_ApplicationInvite_GetID_m3DB722CF432C2AFF8FB726B0DB2FA15A83019D95(L_6, NULL);
		__this->___ID_2 = L_7;
		// IsActive = CLIB.ppf_ApplicationInvite_GetIsActive(o);
		intptr_t L_8 = ___0_o;
		bool L_9;
		L_9 = CLIB_ppf_ApplicationInvite_GetIsActive_m7DBE6151519B3634BEAD930EC7B8FF9A35255C60(L_8, NULL);
		__this->___IsActive_3 = L_9;
		// LobbySessionId = CLIB.ppf_ApplicationInvite_GetLobbySessionId(o);
		intptr_t L_10 = ___0_o;
		String_t* L_11;
		L_11 = CLIB_ppf_ApplicationInvite_GetLobbySessionId_m80D075C4696B4D93B5527C540B20C6BC65C85572(L_10, NULL);
		__this->___LobbySessionId_4 = L_11;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___LobbySessionId_4), (void*)L_11);
		// MatchSessionId = CLIB.ppf_ApplicationInvite_GetMatchSessionId(o);
		intptr_t L_12 = ___0_o;
		String_t* L_13;
		L_13 = CLIB_ppf_ApplicationInvite_GetMatchSessionId_m801472832EC6DBE1432DD98D8E32395D7BE1A84F(L_12, NULL);
		__this->___MatchSessionId_5 = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___MatchSessionId_5), (void*)L_13);
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
// System.Void Pico.Platform.Models.ApplicationInviteList::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ApplicationInviteList__ctor_mF3D2F58B366BD4BF1634F9EF207061494C7826FE (ApplicationInviteList_tCFA701E5249821E8B9BBFD13F595859AFFAB19DB* __this, intptr_t ___0_a, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ApplicationInvite_t95D2E15775E4CD15D060CDF6CF25EDB854EB67D7_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m184EE05AA8961970FF60E58756ED8BE4F017374E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_set_Capacity_mCA9040FB8D0912244F96B1C4B829379A6145F529_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageArray_1__ctor_m667099D521C9333D86ABAA3B49FBF8DF9D833999_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		// public ApplicationInviteList(IntPtr a)
		MessageArray_1__ctor_m667099D521C9333D86ABAA3B49FBF8DF9D833999(__this, MessageArray_1__ctor_m667099D521C9333D86ABAA3B49FBF8DF9D833999_RuntimeMethod_var);
		// var count = (int) CLIB.ppf_ApplicationInviteArray_GetSize(a);
		intptr_t L_0 = ___0_a;
		uintptr_t L_1;
		L_1 = CLIB_ppf_ApplicationInviteArray_GetSize_m2DF9E43B4A0A2176BD28C9B1DDD4CD560A05E1AD(L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint32_t L_2;
		L_2 = UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8(L_1, NULL);
		V_0 = L_2;
		// this.Capacity = count;
		int32_t L_3 = V_0;
		List_1_set_Capacity_mCA9040FB8D0912244F96B1C4B829379A6145F529(__this, L_3, List_1_set_Capacity_mCA9040FB8D0912244F96B1C4B829379A6145F529_RuntimeMethod_var);
		// for (int i = 0; i < count; i++)
		V_1 = 0;
		goto IL_0039;
	}

IL_001d:
	{
		// this.Add(new ApplicationInvite(CLIB.ppf_ApplicationInviteArray_GetElement(a, (UIntPtr) i)));
		intptr_t L_4 = ___0_a;
		int32_t L_5 = V_1;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_6;
		L_6 = UIntPtr_op_Explicit_mF1E7911DD5AC13B5E59EE8C7903469D12A3861E8(((int64_t)L_5), NULL);
		intptr_t L_7;
		L_7 = CLIB_ppf_ApplicationInviteArray_GetElement_m0D79E2A49F2F3F058AD49889360B1100FE7E8B02(L_4, L_6, NULL);
		ApplicationInvite_t95D2E15775E4CD15D060CDF6CF25EDB854EB67D7* L_8 = (ApplicationInvite_t95D2E15775E4CD15D060CDF6CF25EDB854EB67D7*)il2cpp_codegen_object_new(ApplicationInvite_t95D2E15775E4CD15D060CDF6CF25EDB854EB67D7_il2cpp_TypeInfo_var);
		NullCheck(L_8);
		ApplicationInvite__ctor_m0A9B118AFC2B0FB82F841901E3AE34B083AFF954(L_8, L_7, NULL);
		List_1_Add_m184EE05AA8961970FF60E58756ED8BE4F017374E_inline(__this, L_8, List_1_Add_m184EE05AA8961970FF60E58756ED8BE4F017374E_RuntimeMethod_var);
		// for (int i = 0; i < count; i++)
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0039:
	{
		// for (int i = 0; i < count; i++)
		int32_t L_10 = V_1;
		int32_t L_11 = V_0;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_001d;
		}
	}
	{
		// NextPageParam = CLIB.ppf_ApplicationInviteArray_GetNextPageParam(a);
		intptr_t L_12 = ___0_a;
		String_t* L_13;
		L_13 = CLIB_ppf_ApplicationInviteArray_GetNextPageParam_mB55F86F34B099B43F98135C6CD57C7586FD1F18D(L_12, NULL);
		((MessageArray_1_tBD7F57C2576E156E6CA055C10BDF9CF1A640AAB8*)__this)->___NextPageParam_6 = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((MessageArray_1_tBD7F57C2576E156E6CA055C10BDF9CF1A640AAB8*)__this)->___NextPageParam_6), (void*)L_13);
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
// System.Void Pico.Platform.Models.SendInvitesResult::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SendInvitesResult__ctor_m669F65E6C225768F1BA741341D73F7180B4E03F3 (SendInvitesResult_tF1FCB62C7DDA973DC7DDE54DC9DEEF5FC77B8B57* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ApplicationInviteList_tCFA701E5249821E8B9BBFD13F595859AFFAB19DB_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public SendInvitesResult(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Invites = new ApplicationInviteList(CLIB.ppf_SendInvitesResult_GetInvites(o));
		intptr_t L_0 = ___0_o;
		intptr_t L_1;
		L_1 = CLIB_ppf_SendInvitesResult_GetInvites_mB909189924E191656201ACF2753F80A4286267E0(L_0, NULL);
		ApplicationInviteList_tCFA701E5249821E8B9BBFD13F595859AFFAB19DB* L_2 = (ApplicationInviteList_tCFA701E5249821E8B9BBFD13F595859AFFAB19DB*)il2cpp_codegen_object_new(ApplicationInviteList_tCFA701E5249821E8B9BBFD13F595859AFFAB19DB_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		ApplicationInviteList__ctor_mF3D2F58B366BD4BF1634F9EF207061494C7826FE(L_2, L_1, NULL);
		__this->___Invites_0 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Invites_0), (void*)L_2);
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
// System.Void Pico.Platform.Models.PresenceJoinIntent::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PresenceJoinIntent__ctor_m592B2B2ABFC03E0612F7E14D9FA75415A108C5D0 (PresenceJoinIntent_t708F6CB20BA715DA328B67F38BFD1376DF6364D3* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public PresenceJoinIntent(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// DeeplinkMessage = CLIB.ppf_PresenceJoinIntent_GetDeeplinkMessage(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_PresenceJoinIntent_GetDeeplinkMessage_mEC5BD9E839DAEC976EA134948DD816E5B9261B37(L_0, NULL);
		__this->___DeeplinkMessage_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___DeeplinkMessage_0), (void*)L_1);
		// DestinationApiName = CLIB.ppf_PresenceJoinIntent_GetDestinationApiName(o);
		intptr_t L_2 = ___0_o;
		String_t* L_3;
		L_3 = CLIB_ppf_PresenceJoinIntent_GetDestinationApiName_mF87288B9573B0363E84219192BA157F0A9BD072D(L_2, NULL);
		__this->___DestinationApiName_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___DestinationApiName_1), (void*)L_3);
		// LobbySessionId = CLIB.ppf_PresenceJoinIntent_GetLobbySessionId(o);
		intptr_t L_4 = ___0_o;
		String_t* L_5;
		L_5 = CLIB_ppf_PresenceJoinIntent_GetLobbySessionId_m3D139C17978DC32D20928AB0EAC3303180A3D18D(L_4, NULL);
		__this->___LobbySessionId_2 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___LobbySessionId_2), (void*)L_5);
		// MatchSessionId = CLIB.ppf_PresenceJoinIntent_GetMatchSessionId(o);
		intptr_t L_6 = ___0_o;
		String_t* L_7;
		L_7 = CLIB_ppf_PresenceJoinIntent_GetMatchSessionId_m6A00ED473DCD613E13BFC9A97E1897C05F57EE8C(L_6, NULL);
		__this->___MatchSessionId_3 = L_7;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___MatchSessionId_3), (void*)L_7);
		// Extra = CLIB.ppf_PresenceJoinIntent_GetExtra(o);
		intptr_t L_8 = ___0_o;
		String_t* L_9;
		L_9 = CLIB_ppf_PresenceJoinIntent_GetExtra_m939574DE3F4E9C43D212B73D89EB729266F724E0(L_8, NULL);
		__this->___Extra_4 = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Extra_4), (void*)L_9);
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
// System.Void Pico.Platform.Models.Room::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Room__ctor_mB6AF794D98BC22F1081870DD63E403520D1172A4 (Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	intptr_t V_0;
	memset((&V_0), 0, sizeof(V_0));
	intptr_t V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		// public Room(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// PlayerNumber = CLIB.ppf_Room_GetPlayerNumber(o);
		intptr_t L_0 = ___0_o;
		uint32_t L_1;
		L_1 = CLIB_ppf_Room_GetPlayerNumber_mF381C436C9F47A2382903E4ECEE26D94F7B4CC4C(L_0, NULL);
		__this->___PlayerNumber_11 = L_1;
		// DataStore = CLIB.DataStoreFromNative(CLIB.ppf_Room_GetDataStore(o));
		intptr_t L_2 = ___0_o;
		intptr_t L_3;
		L_3 = CLIB_ppf_Room_GetDataStore_mD837F6F5F9D8454C3CED911061B3182798B58A75(L_2, NULL);
		Dictionary_2_t46B2DB028096FA2B828359E52F37F3105A83AD83* L_4;
		L_4 = CLIB_DataStoreFromNative_m765A5372300BCCB3279F02A012FDDF4E30ED626A(L_3, NULL);
		__this->___DataStore_0 = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___DataStore_0), (void*)L_4);
		// Description = CLIB.ppf_Room_GetDescription(o);
		intptr_t L_5 = ___0_o;
		String_t* L_6;
		L_6 = CLIB_ppf_Room_GetDescription_m0B3F47015616F855934978A1E3363FF8133B2B2D(L_5, NULL);
		__this->___Description_1 = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Description_1), (void*)L_6);
		// RoomId = CLIB.ppf_Room_GetID(o);
		intptr_t L_7 = ___0_o;
		uint64_t L_8;
		L_8 = CLIB_ppf_Room_GetID_mA3F30744CFD4B32773033B92C35D36EDCFC52302(L_7, NULL);
		__this->___RoomId_2 = L_8;
		// IsMembershipLocked = CLIB.ppf_Room_GetIsMembershipLocked(o);
		intptr_t L_9 = ___0_o;
		bool L_10;
		L_10 = CLIB_ppf_Room_GetIsMembershipLocked_m1B8FC8CD5743C03D290C0D1252D3254AE6E36137(L_9, NULL);
		__this->___IsMembershipLocked_3 = L_10;
		// RoomJoinPolicy = (RoomJoinPolicy) CLIB.ppf_Room_GetJoinPolicy(o);
		intptr_t L_11 = ___0_o;
		int32_t L_12;
		L_12 = CLIB_ppf_Room_GetJoinPolicy_m9D566A4693F674501E54329CA22962C45D4356AB(L_11, NULL);
		__this->___RoomJoinPolicy_4 = L_12;
		// RoomJoinability = (RoomJoinability) CLIB.ppf_Room_GetJoinability(o);
		intptr_t L_13 = ___0_o;
		int32_t L_14;
		L_14 = CLIB_ppf_Room_GetJoinability_mCA89ED58AAB4D55330CFFB99E77AD3126DB2C52A(L_13, NULL);
		__this->___RoomJoinability_5 = L_14;
		// MaxUsers = CLIB.ppf_Room_GetMaxUsers(o);
		intptr_t L_15 = ___0_o;
		uint32_t L_16;
		L_16 = CLIB_ppf_Room_GetMaxUsers_m72EAD2F61A6C02DFC70142B2D8FA1D8B623B6159(L_15, NULL);
		__this->___MaxUsers_6 = L_16;
		// Name = CLIB.ppf_Room_GetName(o);
		intptr_t L_17 = ___0_o;
		String_t* L_18;
		L_18 = CLIB_ppf_Room_GetName_m87A770FD459F4539848860C47986204CCEE10162(L_17, NULL);
		__this->___Name_10 = L_18;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Name_10), (void*)L_18);
		// RoomType = (RoomType) CLIB.ppf_Room_GetType(o);
		intptr_t L_19 = ___0_o;
		int32_t L_20;
		L_20 = CLIB_ppf_Room_GetType_mA5FCEBA4DC0D3B9D9DDCE628BFC7009C0398FF4B(L_19, NULL);
		__this->___RoomType_8 = L_20;
		// var ptr = CLIB.ppf_Room_GetOwner(o);
		intptr_t L_21 = ___0_o;
		intptr_t L_22;
		L_22 = CLIB_ppf_Room_GetOwner_m431345003BF1B39434CBC260A90E38C1D582180C(L_21, NULL);
		V_0 = L_22;
		// if (ptr == IntPtr.Zero)
		intptr_t L_23 = V_0;
		intptr_t L_24 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		bool L_25;
		L_25 = IntPtr_op_Equality_m7D9CDCDE9DC2A0C2C614633F4921E90187FAB271(L_23, L_24, NULL);
		if (!L_25)
		{
			goto IL_00a0;
		}
	}
	{
		// OwnerOptional = null;
		__this->___OwnerOptional_7 = (User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___OwnerOptional_7), (void*)(User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4*)NULL);
		goto IL_00ac;
	}

IL_00a0:
	{
		// OwnerOptional = new User(ptr);
		intptr_t L_26 = V_0;
		User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4* L_27 = (User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4*)il2cpp_codegen_object_new(User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4_il2cpp_TypeInfo_var);
		NullCheck(L_27);
		User__ctor_m0A17383A33457E27EB6AD299C81C77AC1802E0D1(L_27, L_26, NULL);
		__this->___OwnerOptional_7 = L_27;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___OwnerOptional_7), (void*)L_27);
	}

IL_00ac:
	{
		// var ptr = CLIB.ppf_Room_GetUsers(o);
		intptr_t L_28 = ___0_o;
		intptr_t L_29;
		L_29 = CLIB_ppf_Room_GetUsers_mEEBAF8CF27478C8D3DACBACBF5465AC8A887F4A9(L_28, NULL);
		V_1 = L_29;
		// if (ptr == IntPtr.Zero)
		intptr_t L_30 = V_1;
		intptr_t L_31 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		bool L_32;
		L_32 = IntPtr_op_Equality_m7D9CDCDE9DC2A0C2C614633F4921E90187FAB271(L_30, L_31, NULL);
		if (!L_32)
		{
			goto IL_00c8;
		}
	}
	{
		// UsersOptional = null;
		__this->___UsersOptional_9 = (UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___UsersOptional_9), (void*)(UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F*)NULL);
		return;
	}

IL_00c8:
	{
		// UsersOptional = new UserList(ptr);
		intptr_t L_33 = V_1;
		UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F* L_34 = (UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F*)il2cpp_codegen_object_new(UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F_il2cpp_TypeInfo_var);
		NullCheck(L_34);
		UserList__ctor_m4FEB49DD26A4410363EE489A1D289C8725776F4D(L_34, L_33, NULL);
		__this->___UsersOptional_9 = L_34;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___UsersOptional_9), (void*)L_34);
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
// System.Void Pico.Platform.Models.RoomList::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RoomList__ctor_mEBDDF23698AD7ED54D4673ADB003D6182A4A0CD3 (RoomList_t3B275914D4B281B7FAB5C1AD597F11D664367694* __this, intptr_t ___0_a, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mD04F4301A11C785E216B4D3B39B7BBA17AC556D0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_set_Capacity_m5D4C4FA3EEC9734BCBF629BCC57F31DB95D20AC3_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageArray_1__ctor_m44916C4D5F46A3D4CB182D99F9E370CBFA347B97_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&String_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB7C45DD316C68ABF3429C20058C2981C652192F2);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	uint32_t V_1 = 0;
	RoomList_t3B275914D4B281B7FAB5C1AD597F11D664367694* G_B2_0 = NULL;
	RoomList_t3B275914D4B281B7FAB5C1AD597F11D664367694* G_B1_0 = NULL;
	String_t* G_B3_0 = NULL;
	RoomList_t3B275914D4B281B7FAB5C1AD597F11D664367694* G_B3_1 = NULL;
	{
		// public RoomList(IntPtr a)
		MessageArray_1__ctor_m44916C4D5F46A3D4CB182D99F9E370CBFA347B97(__this, MessageArray_1__ctor_m44916C4D5F46A3D4CB182D99F9E370CBFA347B97_RuntimeMethod_var);
		// TotalCount = CLIB.ppf_RoomArray_GetTotalCount(a);
		intptr_t L_0 = ___0_a;
		int32_t L_1;
		L_1 = CLIB_ppf_RoomArray_GetTotalCount_m2661AEA71C41F53C8AC1225268F82F5EF5D80A57(L_0, NULL);
		__this->___TotalCount_8 = L_1;
		// CurIndex = CLIB.ppf_RoomArray_GetPageIndex(a);
		intptr_t L_2 = ___0_a;
		int32_t L_3;
		L_3 = CLIB_ppf_RoomArray_GetPageIndex_m62BC5997CFD307B686887BF746D683DE74791386(L_2, NULL);
		__this->___CurIndex_9 = L_3;
		// PageSize = CLIB.ppf_RoomArray_GetPageSize(a);
		intptr_t L_4 = ___0_a;
		int32_t L_5;
		L_5 = CLIB_ppf_RoomArray_GetPageSize_m500EFA10A28E0EA6400521CBDAB553FA9E815793(L_4, NULL);
		__this->___PageSize_10 = L_5;
		// NextPageParam = CLIB.ppf_RoomArray_HasNextPage(a) ? "true" : string.Empty;
		intptr_t L_6 = ___0_a;
		bool L_7;
		L_7 = CLIB_ppf_RoomArray_HasNextPage_m5E21A22CDD09E128D8185D93CBBD970AB7386B33(L_6, NULL);
		G_B1_0 = __this;
		if (L_7)
		{
			G_B2_0 = __this;
			goto IL_003a;
		}
	}
	{
		String_t* L_8 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->___Empty_6;
		G_B3_0 = L_8;
		G_B3_1 = G_B1_0;
		goto IL_003f;
	}

IL_003a:
	{
		G_B3_0 = _stringLiteralB7C45DD316C68ABF3429C20058C2981C652192F2;
		G_B3_1 = G_B2_0;
	}

IL_003f:
	{
		NullCheck(G_B3_1);
		((MessageArray_1_t13175CA17EF1C58A6CE16C1C5CC33E66B189C0DB*)G_B3_1)->___NextPageParam_6 = G_B3_0;
		Il2CppCodeGenWriteBarrier((void**)(&((MessageArray_1_t13175CA17EF1C58A6CE16C1C5CC33E66B189C0DB*)G_B3_1)->___NextPageParam_6), (void*)G_B3_0);
		// int count = (int) CLIB.ppf_RoomArray_GetSize(a);
		intptr_t L_9 = ___0_a;
		uintptr_t L_10;
		L_10 = CLIB_ppf_RoomArray_GetSize_mE6F66F2A0AA5392B901AAC29B48B609CB25319D9(L_9, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint32_t L_11;
		L_11 = UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8(L_10, NULL);
		V_0 = L_11;
		// this.Capacity = count;
		int32_t L_12 = V_0;
		List_1_set_Capacity_m5D4C4FA3EEC9734BCBF629BCC57F31DB95D20AC3(__this, L_12, List_1_set_Capacity_m5D4C4FA3EEC9734BCBF629BCC57F31DB95D20AC3_RuntimeMethod_var);
		// for (uint i = 0; i < count; i++)
		V_1 = 0;
		goto IL_0076;
	}

IL_005b:
	{
		// this.Add(new Room(CLIB.ppf_RoomArray_GetElement(a, (UIntPtr)i)));
		intptr_t L_13 = ___0_a;
		uint32_t L_14 = V_1;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_15;
		L_15 = UIntPtr_op_Explicit_mD94DCD8965DD2E7D5A3370A04CCEDBE5937C078C(L_14, NULL);
		intptr_t L_16;
		L_16 = CLIB_ppf_RoomArray_GetElement_mBB99290A1434BC5F54FB13DAD7EE244C59F58DBB(L_13, L_15, NULL);
		Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135* L_17 = (Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135*)il2cpp_codegen_object_new(Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135_il2cpp_TypeInfo_var);
		NullCheck(L_17);
		Room__ctor_mB6AF794D98BC22F1081870DD63E403520D1172A4(L_17, L_16, NULL);
		List_1_Add_mD04F4301A11C785E216B4D3B39B7BBA17AC556D0_inline(__this, L_17, List_1_Add_mD04F4301A11C785E216B4D3B39B7BBA17AC556D0_RuntimeMethod_var);
		// for (uint i = 0; i < count; i++)
		uint32_t L_18 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add((int32_t)L_18, 1));
	}

IL_0076:
	{
		// for (uint i = 0; i < count; i++)
		uint32_t L_19 = V_1;
		int32_t L_20 = V_0;
		if ((((int64_t)((int64_t)(uint64_t)L_19)) < ((int64_t)((int64_t)L_20))))
		{
			goto IL_005b;
		}
	}
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
// System.Void Pico.Platform.Models.RtcBinaryMessageReceived::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcBinaryMessageReceived__ctor_m68DAEA37EDB5FEF2C0E7E7A194894468CCE61039 (RtcBinaryMessageReceived_t27A81B34E30B69FD73D308AEBB3C92201FA00FB2* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	intptr_t V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	{
		// public RtcBinaryMessageReceived(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// UserId = CLIB.ppf_RtcBinaryMessageReceived_GetUserId(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_RtcBinaryMessageReceived_GetUserId_m478FB5FD03D4B5E3C7B64D81EC4302871E488983(L_0, NULL);
		__this->___UserId_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___UserId_0), (void*)L_1);
		// var ptr = CLIB.ppf_RtcBinaryMessageReceived_GetData(o);
		intptr_t L_2 = ___0_o;
		intptr_t L_3;
		L_3 = CLIB_ppf_RtcBinaryMessageReceived_GetData_m81ABEA3C4B96053A8A7C3E8BFCD88E62BAE4ACE4(L_2, NULL);
		V_0 = L_3;
		// var sz = CLIB.ppf_RtcBinaryMessageReceived_GetLength(o);
		intptr_t L_4 = ___0_o;
		int32_t L_5;
		L_5 = CLIB_ppf_RtcBinaryMessageReceived_GetLength_m6D5E0F8F65662C06B8EF7878D9B63BEA03F0149B(L_4, NULL);
		V_1 = L_5;
		// Data = MarshalUtil.ByteArrayFromNative(ptr, (uint) sz);
		intptr_t L_6 = V_0;
		int32_t L_7 = V_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_8;
		L_8 = MarshalUtil_ByteArrayFromNative_m3285FDD06424A5CB82BD0EE8C63BBB8F8C2482DB(L_6, L_7, NULL);
		__this->___Data_1 = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Data_1), (void*)L_8);
		// RoomId = CLIB.ppf_RtcBinaryMessageReceived_GetRoomId(o);
		intptr_t L_9 = ___0_o;
		String_t* L_10;
		L_10 = CLIB_ppf_RtcBinaryMessageReceived_GetRoomId_mEF08BBA5951DE0FF99FA66EABC400270CBCEFDCB(L_9, NULL);
		__this->___RoomId_2 = L_10;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___RoomId_2), (void*)L_10);
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
// System.Void Pico.Platform.Models.RtcAudioFrame::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcAudioFrame__ctor_mAF8A3A50316BDC0FFFE39C0FCF28E25F185B5E9A (RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public RtcAudioFrame(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Channel = CLIB.ppf_RtcAudioFrame_GetChannel(o);
		intptr_t L_0 = ___0_o;
		int32_t L_1;
		L_1 = CLIB_ppf_RtcAudioFrame_GetChannel_mD6D1E07ADF59FE9E2028C71EDC07401E81580C37(L_0, NULL);
		__this->___Channel_0 = L_1;
		// DataSize = CLIB.ppf_RtcAudioFrame_GetDataSize(o);
		intptr_t L_2 = ___0_o;
		int64_t L_3;
		L_3 = CLIB_ppf_RtcAudioFrame_GetDataSize_m0F23B0997DD19BB022CC11AE23C5EB3A8F4717E2(L_2, NULL);
		__this->___DataSize_2 = L_3;
		// SampleRate = CLIB.ppf_RtcAudioFrame_GetSampleRate(o);
		intptr_t L_4 = ___0_o;
		int32_t L_5;
		L_5 = CLIB_ppf_RtcAudioFrame_GetSampleRate_mA4E8F41486076F9DA889BC35E9B3BDBC9C166D15(L_4, NULL);
		__this->___SampleRate_3 = L_5;
		// TimeStampInUs = CLIB.ppf_RtcAudioFrame_GetTimeStampInUs(o);
		intptr_t L_6 = ___0_o;
		int64_t L_7;
		L_7 = CLIB_ppf_RtcAudioFrame_GetTimeStampInUs_m0041CF3BD08AF21B83680DE3C14DE3B3EE7A9DD6(L_6, NULL);
		__this->___TimeStampInUs_4 = L_7;
		// Data = CLIB.ppf_RtcAudioFrame_GetData(o);
		intptr_t L_8 = ___0_o;
		intptr_t L_9;
		L_9 = CLIB_ppf_RtcAudioFrame_GetData_m7CE07FFC43BA3BDA471CD5CC6091152AE9D51FAD(L_8, NULL);
		__this->___Data_1 = L_9;
		// }
		return;
	}
}
// System.Byte[] Pico.Platform.Models.RtcAudioFrame::GetData()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* RtcAudioFrame_GetData_m40190CFA38F67C5EA55F3963E96660955E242AD3 (RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59* __this, const RuntimeMethod* method) 
{
	{
		// return MarshalUtil.ByteArrayFromNative(this.Data, (uint) this.DataSize);
		intptr_t L_0 = __this->___Data_1;
		int64_t L_1 = __this->___DataSize_2;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2;
		L_2 = MarshalUtil_ByteArrayFromNative_m3285FDD06424A5CB82BD0EE8C63BBB8F8C2482DB(L_0, ((int32_t)(uint32_t)L_1), NULL);
		return L_2;
	}
}
// System.Void Pico.Platform.Models.RtcAudioFrame::SetData(System.Byte[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcAudioFrame_SetData_m26BE8873272F1424F9E4EC2B4932075214E026A5 (RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_data, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// Marshal.Copy(data, 0, this.Data, (int) this.DataSize);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___0_data;
		intptr_t L_1 = __this->___Data_1;
		int64_t L_2 = __this->___DataSize_2;
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		Marshal_Copy_m0FD7BFE70EE28FC67B67A6225AD58F95FEE7EB85(L_0, 0, L_1, ((int32_t)L_2), NULL);
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
// System.Void Pico.Platform.Models.RtcMessageSendResult::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcMessageSendResult__ctor_m47D9BEA1D198088E92B9AEA378DDF2993FEE316E (RtcMessageSendResult_t175C63F675CA721C614F552DAED8AD5CDD8D19D9* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public RtcMessageSendResult(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// MessageId = CLIB.ppf_RtcMessageSendResult_GetMessageId(o);
		intptr_t L_0 = ___0_o;
		int64_t L_1;
		L_1 = CLIB_ppf_RtcMessageSendResult_GetMessageId_m84BFDE85197263777DC7E3A4A4CE0448B3F35B4D(L_0, NULL);
		__this->___MessageId_0 = L_1;
		// Error = CLIB.ppf_RtcMessageSendResult_GetError(o);
		intptr_t L_2 = ___0_o;
		int32_t L_3;
		L_3 = CLIB_ppf_RtcMessageSendResult_GetError_m1D6E956099B565274366B009ED16FFA6314D8906(L_2, NULL);
		__this->___Error_1 = L_3;
		// RoomId = CLIB.ppf_RtcMessageSendResult_GetRoomId(o);
		intptr_t L_4 = ___0_o;
		String_t* L_5;
		L_5 = CLIB_ppf_RtcMessageSendResult_GetRoomId_m075541A68FE8AF0FB5C647A738BCFE390FA79DCD(L_4, NULL);
		__this->___RoomId_2 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___RoomId_2), (void*)L_5);
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
// System.Void Pico.Platform.Models.RtcUserUnPublishInfo::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcUserUnPublishInfo__ctor_mC9D23482725E312E7C768F1DF446C317B3C1D54F (RtcUserUnPublishInfo_tF48236E711888E683F08D6FC0716FE12A582E99A* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public RtcUserUnPublishInfo(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// UserId = CLIB.ppf_RtcUserUnPublishInfo_GetUserId(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_RtcUserUnPublishInfo_GetUserId_m2AD74BDEC261D1B4EFF2BC75EE2B63DE7C7128B8(L_0, NULL);
		__this->___UserId_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___UserId_0), (void*)L_1);
		// MediaStreamType = CLIB.ppf_RtcUserUnPublishInfo_GetMediaStreamType(o);
		intptr_t L_2 = ___0_o;
		int32_t L_3;
		L_3 = CLIB_ppf_RtcUserUnPublishInfo_GetMediaStreamType_mEBAA1257A91DA1176359E5FFBC22BA5E4CA7827B(L_2, NULL);
		__this->___MediaStreamType_1 = L_3;
		// Reason = CLIB.ppf_RtcUserUnPublishInfo_GetReason(o);
		intptr_t L_4 = ___0_o;
		int32_t L_5;
		L_5 = CLIB_ppf_RtcUserUnPublishInfo_GetReason_m5523F98C749506DC858C9B6FCC488A4B8893482D(L_4, NULL);
		__this->___Reason_2 = L_5;
		// RoomId = CLIB.ppf_RtcUserUnPublishInfo_GetRoomId(o);
		intptr_t L_6 = ___0_o;
		String_t* L_7;
		L_7 = CLIB_ppf_RtcUserUnPublishInfo_GetRoomId_m862D932E2E63653FC3C8C219E2854A6E8467487D(L_6, NULL);
		__this->___RoomId_3 = L_7;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___RoomId_3), (void*)L_7);
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
// System.Void Pico.Platform.Models.RtcUserPublishInfo::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcUserPublishInfo__ctor_m7F8F28605A4333DBEAB0CD5E00CA744567B09491 (RtcUserPublishInfo_t8873B6131F1DFF54983FEA638F386647C53ABE2F* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public RtcUserPublishInfo(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// UserId = CLIB.ppf_RtcUserPublishInfo_GetUserId(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_RtcUserPublishInfo_GetUserId_mD536E2D18A7FE9469C68A1A896006B66283C29AF(L_0, NULL);
		__this->___UserId_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___UserId_0), (void*)L_1);
		// MediaStreamType = CLIB.ppf_RtcUserPublishInfo_GetMediaStreamType(o);
		intptr_t L_2 = ___0_o;
		int32_t L_3;
		L_3 = CLIB_ppf_RtcUserPublishInfo_GetMediaStreamType_mD685C6967DBF6EBD5CE2D69A128001E3013B78BF(L_2, NULL);
		__this->___MediaStreamType_1 = L_3;
		// RoomId = CLIB.ppf_RtcUserPublishInfo_GetRoomId(o);
		intptr_t L_4 = ___0_o;
		String_t* L_5;
		L_5 = CLIB_ppf_RtcUserPublishInfo_GetRoomId_m7E3EFAE76F5A2203078B101139E1BC358479DC15(L_4, NULL);
		__this->___RoomId_2 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___RoomId_2), (void*)L_5);
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
// System.Void Pico.Platform.Models.RtcRoomMessageReceived::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRoomMessageReceived__ctor_m8D86C9D5AA77B39D55575DC04AF8B1E4E3F24C4E (RtcRoomMessageReceived_t2BDF5904A9D3EEF6D72D964485D208779637F7DD* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public RtcRoomMessageReceived(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// UserId = CLIB.ppf_RtcRoomMessageReceived_GetUserId(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_RtcRoomMessageReceived_GetUserId_m71EB1F5F678313095D8363D6E9BFCBCC6360B7EB(L_0, NULL);
		__this->___UserId_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___UserId_0), (void*)L_1);
		// Message = CLIB.ppf_RtcRoomMessageReceived_GetMessage(o);
		intptr_t L_2 = ___0_o;
		String_t* L_3;
		L_3 = CLIB_ppf_RtcRoomMessageReceived_GetMessage_m518329CB1155942FF688118A63F4646C1F761A36(L_2, NULL);
		__this->___Message_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Message_1), (void*)L_3);
		// RoomId = CLIB.ppf_RtcRoomMessageReceived_GetRoomId(o);
		intptr_t L_4 = ___0_o;
		String_t* L_5;
		L_5 = CLIB_ppf_RtcRoomMessageReceived_GetRoomId_mBDCA14ED6669936E2FC042828E41B5E047E62D73(L_4, NULL);
		__this->___RoomId_2 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___RoomId_2), (void*)L_5);
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
// System.Void Pico.Platform.Models.RtcUserMessageReceived::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcUserMessageReceived__ctor_mA15829E6AAF21A3F2A08AE972367B1A998C3440E (RtcUserMessageReceived_t156E2473096464ECCB4B298A7644E6C572A6292E* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public RtcUserMessageReceived(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// UserId = CLIB.ppf_RtcUserMessageReceived_GetUserId(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_RtcUserMessageReceived_GetUserId_mF533611B5554D19A87DDA117D6392B36F696FA32(L_0, NULL);
		__this->___UserId_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___UserId_0), (void*)L_1);
		// Message = CLIB.ppf_RtcUserMessageReceived_GetMessage(o);
		intptr_t L_2 = ___0_o;
		String_t* L_3;
		L_3 = CLIB_ppf_RtcUserMessageReceived_GetMessage_m42471F11BBB06C03967CE05084E2B39601BB8948(L_2, NULL);
		__this->___Message_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Message_1), (void*)L_3);
		// RoomId = CLIB.ppf_RtcUserMessageReceived_GetRoomId(o);
		intptr_t L_4 = ___0_o;
		String_t* L_5;
		L_5 = CLIB_ppf_RtcUserMessageReceived_GetRoomId_m1BF852B51AEFEFE6234A5DFB619CF2557EB958EC(L_4, NULL);
		__this->___RoomId_2 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___RoomId_2), (void*)L_5);
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
// System.Void Pico.Platform.Models.RtcStreamSyncInfo::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcStreamSyncInfo__ctor_mBAE942B8B6AEBBC8BCB241FE9042B4E51AFEFBC3 (RtcStreamSyncInfo_tDF6615A963654FDED33B6E427CC2377459A814C8* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RtcRemoteStreamKey_tA69532F8EF7C977014612F775D146C3038C61E0E_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	intptr_t V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	{
		// public RtcStreamSyncInfo(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// StreamKey = new RtcRemoteStreamKey(CLIB.ppf_RtcStreamSyncInfo_GetStreamKey(o));
		intptr_t L_0 = ___0_o;
		intptr_t L_1;
		L_1 = CLIB_ppf_RtcStreamSyncInfo_GetStreamKey_m322991CAE437275C9D8B083BBB49873B5EACF8EE(L_0, NULL);
		RtcRemoteStreamKey_tA69532F8EF7C977014612F775D146C3038C61E0E* L_2 = (RtcRemoteStreamKey_tA69532F8EF7C977014612F775D146C3038C61E0E*)il2cpp_codegen_object_new(RtcRemoteStreamKey_tA69532F8EF7C977014612F775D146C3038C61E0E_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		RtcRemoteStreamKey__ctor_mA8181CF8D33199DCDEE57AE098F0FF9558C00875(L_2, L_1, NULL);
		__this->___StreamKey_0 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___StreamKey_0), (void*)L_2);
		// StreamType = CLIB.ppf_RtcStreamSyncInfo_GetStreamType(o);
		intptr_t L_3 = ___0_o;
		int32_t L_4;
		L_4 = CLIB_ppf_RtcStreamSyncInfo_GetStreamType_mFA1FDA3DF9B685216E5D800FFEA53B9F26B666CE(L_3, NULL);
		__this->___StreamType_1 = L_4;
		// var ptr = CLIB.ppf_RtcStreamSyncInfo_GetData(o);
		intptr_t L_5 = ___0_o;
		intptr_t L_6;
		L_6 = CLIB_ppf_RtcStreamSyncInfo_GetData_mE0A7B33ACED6C41D71FAD9C28C47A364CEA6079A(L_5, NULL);
		V_0 = L_6;
		// var sz = CLIB.ppf_RtcStreamSyncInfo_GetLength(o);
		intptr_t L_7 = ___0_o;
		int32_t L_8;
		L_8 = CLIB_ppf_RtcStreamSyncInfo_GetLength_m0F4F4414BD684565B89550F1A09ACF35B4FF33AC(L_7, NULL);
		V_1 = L_8;
		// Data = MarshalUtil.ByteArrayFromNative(ptr, (uint) sz);
		intptr_t L_9 = V_0;
		int32_t L_10 = V_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_11;
		L_11 = MarshalUtil_ByteArrayFromNative_m3285FDD06424A5CB82BD0EE8C63BBB8F8C2482DB(L_9, L_10, NULL);
		__this->___Data_2 = L_11;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Data_2), (void*)L_11);
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
// System.Void Pico.Platform.Models.RtcAudioPropertyInfo::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcAudioPropertyInfo__ctor_mC061C4E479AA1830243454373F9FF6FEDC6C96DD (RtcAudioPropertyInfo_tA10BA2C71B943D7A31ED99324B58ECBC13C05268* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public RtcAudioPropertyInfo(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Volume = CLIB.ppf_RtcAudioPropertyInfo_GetVolume(o);
		intptr_t L_0 = ___0_o;
		int32_t L_1;
		L_1 = CLIB_ppf_RtcAudioPropertyInfo_GetVolume_m9474186E2E8DC2F5EA26F9BEEC7089C05948945E(L_0, NULL);
		__this->___Volume_0 = L_1;
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
// System.Void Pico.Platform.Models.RtcJoinRoomResult::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcJoinRoomResult__ctor_mC049DBA41EE89458E531FE5B02AA9D370B3CCF24 (RtcJoinRoomResult_t7B3739D043DA3F0754EA07F27CC81279A5673D3C* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public RtcJoinRoomResult(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// RoomId = CLIB.ppf_RtcJoinRoomResult_GetRoomId(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_RtcJoinRoomResult_GetRoomId_m04AE68133066E50638087B9058D7B9B3CBCE8B43(L_0, NULL);
		__this->___RoomId_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___RoomId_0), (void*)L_1);
		// UserId = CLIB.ppf_RtcJoinRoomResult_GetUserId(o);
		intptr_t L_2 = ___0_o;
		String_t* L_3;
		L_3 = CLIB_ppf_RtcJoinRoomResult_GetUserId_m0CFD8C64966F9833BB1CEF57203161AE233B4EF8(L_2, NULL);
		__this->___UserId_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___UserId_1), (void*)L_3);
		// ErrorCode = CLIB.ppf_RtcJoinRoomResult_GetErrorCode(o);
		intptr_t L_4 = ___0_o;
		int32_t L_5;
		L_5 = CLIB_ppf_RtcJoinRoomResult_GetErrorCode_mF2A0FC1F97D6650A93B30E7FE911899A1719E966(L_4, NULL);
		__this->___ErrorCode_2 = L_5;
		// Elapsed = CLIB.ppf_RtcJoinRoomResult_GetElapsed(o);
		intptr_t L_6 = ___0_o;
		int32_t L_7;
		L_7 = CLIB_ppf_RtcJoinRoomResult_GetElapsed_m29C0057D84EB39E560E11C9ED4C624624B32AD18(L_6, NULL);
		__this->___Elapsed_3 = L_7;
		// JoinType = CLIB.ppf_RtcJoinRoomResult_GetJoinType(o);
		intptr_t L_8 = ___0_o;
		int32_t L_9;
		L_9 = CLIB_ppf_RtcJoinRoomResult_GetJoinType_mE542290DDE8C760ABABA9CFB59E5D5CA4A735597(L_8, NULL);
		__this->___JoinType_4 = L_9;
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
// System.Void Pico.Platform.Models.RtcLeaveRoomResult::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcLeaveRoomResult__ctor_mB9FE004632192B4B0031279A1C3FAB3165133D42 (RtcLeaveRoomResult_t7FC19B99E6788124464A77D25421776CB62301FF* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public RtcLeaveRoomResult(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// RoomId = CLIB.ppf_RtcLeaveRoomResult_GetRoomId(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_RtcLeaveRoomResult_GetRoomId_mB02EE9AE6A9E7FFD51F79BB546AD052AB5F63897(L_0, NULL);
		__this->___RoomId_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___RoomId_0), (void*)L_1);
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
// System.Void Pico.Platform.Models.RtcLocalAudioPropertiesInfo::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcLocalAudioPropertiesInfo__ctor_m62EA3EAC77FF4AA26A9A1E437EC790B4BFA936D4 (RtcLocalAudioPropertiesInfo_tDEE2268599EA8C3EC747871F690C5743321ED49E* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RtcAudioPropertyInfo_tA10BA2C71B943D7A31ED99324B58ECBC13C05268_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public RtcLocalAudioPropertiesInfo(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// StreamIndex = CLIB.ppf_RtcLocalAudioPropertiesInfo_GetStreamIndex(o);
		intptr_t L_0 = ___0_o;
		int32_t L_1;
		L_1 = CLIB_ppf_RtcLocalAudioPropertiesInfo_GetStreamIndex_mB7ACF6AB0A3CC4F5500227D3C3D02C89ACAC7DBA(L_0, NULL);
		__this->___StreamIndex_0 = L_1;
		// AudioPropertyInfo = new RtcAudioPropertyInfo(CLIB.ppf_RtcLocalAudioPropertiesInfo_GetAudioPropertyInfo(o));
		intptr_t L_2 = ___0_o;
		intptr_t L_3;
		L_3 = CLIB_ppf_RtcLocalAudioPropertiesInfo_GetAudioPropertyInfo_mC539E7606ADF0FADFB7ECBD139B35BF7BD0F0D93(L_2, NULL);
		RtcAudioPropertyInfo_tA10BA2C71B943D7A31ED99324B58ECBC13C05268* L_4 = (RtcAudioPropertyInfo_tA10BA2C71B943D7A31ED99324B58ECBC13C05268*)il2cpp_codegen_object_new(RtcAudioPropertyInfo_tA10BA2C71B943D7A31ED99324B58ECBC13C05268_il2cpp_TypeInfo_var);
		NullCheck(L_4);
		RtcAudioPropertyInfo__ctor_mC061C4E479AA1830243454373F9FF6FEDC6C96DD(L_4, L_3, NULL);
		__this->___AudioPropertyInfo_1 = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___AudioPropertyInfo_1), (void*)L_4);
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
// System.Void Pico.Platform.Models.RtcLocalAudioPropertiesReport::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcLocalAudioPropertiesReport__ctor_m5EC1418129644EF39E90281288475FDD0C14B8D0 (RtcLocalAudioPropertiesReport_t0AA9BC3CF8E0B67661E0CF11B68EBEE27C9D9E7D* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RtcLocalAudioPropertiesInfoU5BU5D_tECCE986B1F5EE0EA71E955DE541538066669D2C7_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RtcLocalAudioPropertiesInfo_tDEE2268599EA8C3EC747871F690C5743321ED49E_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RtcLocalAudioPropertiesReport__ctor_m5EC1418129644EF39E90281288475FDD0C14B8D0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	uint64_t V_0 = 0;
	uint32_t V_1 = 0;
	{
		// public RtcLocalAudioPropertiesReport(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// ulong total = (ulong) CLIB.ppf_RtcLocalAudioPropertiesReport_GetAudioPropertiesInfosSize(o);
		intptr_t L_0 = ___0_o;
		uintptr_t L_1;
		L_1 = CLIB_ppf_RtcLocalAudioPropertiesReport_GetAudioPropertiesInfosSize_mE5764E08811AE948FF5E24E71082CCBCF3912CFE(L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint64_t L_2;
		L_2 = UIntPtr_op_Explicit_mC39E70F0324C1C514A3044790BC19C5FC4C58E1C(L_1, NULL);
		V_0 = L_2;
		// AudioPropertiesInfos = new RtcLocalAudioPropertiesInfo[total];
		uint64_t L_3 = V_0;
		if ((uint64_t)(L_3) > INTPTR_MAX) IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), RtcLocalAudioPropertiesReport__ctor_m5EC1418129644EF39E90281288475FDD0C14B8D0_RuntimeMethod_var);
		RtcLocalAudioPropertiesInfoU5BU5D_tECCE986B1F5EE0EA71E955DE541538066669D2C7* L_4 = (RtcLocalAudioPropertiesInfoU5BU5D_tECCE986B1F5EE0EA71E955DE541538066669D2C7*)(RtcLocalAudioPropertiesInfoU5BU5D_tECCE986B1F5EE0EA71E955DE541538066669D2C7*)SZArrayNew(RtcLocalAudioPropertiesInfoU5BU5D_tECCE986B1F5EE0EA71E955DE541538066669D2C7_il2cpp_TypeInfo_var, (uint32_t)((intptr_t)L_3));
		__this->___AudioPropertiesInfos_0 = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___AudioPropertiesInfos_0), (void*)L_4);
		// for (uint i = 0; i < total; i++)
		V_1 = 0;
		goto IL_0040;
	}

IL_0023:
	{
		// AudioPropertiesInfos[i] = new RtcLocalAudioPropertiesInfo(CLIB.ppf_RtcLocalAudioPropertiesReport_GetAudioPropertiesInfos(o, (UIntPtr) i));
		RtcLocalAudioPropertiesInfoU5BU5D_tECCE986B1F5EE0EA71E955DE541538066669D2C7* L_5 = __this->___AudioPropertiesInfos_0;
		uint32_t L_6 = V_1;
		intptr_t L_7 = ___0_o;
		uint32_t L_8 = V_1;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_9;
		L_9 = UIntPtr_op_Explicit_mD94DCD8965DD2E7D5A3370A04CCEDBE5937C078C(L_8, NULL);
		intptr_t L_10;
		L_10 = CLIB_ppf_RtcLocalAudioPropertiesReport_GetAudioPropertiesInfos_mE0778B47DA70715114CAC02EAEF2BA8CA2D2FFB2(L_7, L_9, NULL);
		RtcLocalAudioPropertiesInfo_tDEE2268599EA8C3EC747871F690C5743321ED49E* L_11 = (RtcLocalAudioPropertiesInfo_tDEE2268599EA8C3EC747871F690C5743321ED49E*)il2cpp_codegen_object_new(RtcLocalAudioPropertiesInfo_tDEE2268599EA8C3EC747871F690C5743321ED49E_il2cpp_TypeInfo_var);
		NullCheck(L_11);
		RtcLocalAudioPropertiesInfo__ctor_m62EA3EAC77FF4AA26A9A1E437EC790B4BFA936D4(L_11, L_10, NULL);
		NullCheck(L_5);
		ArrayElementTypeCheck (L_5, L_11);
		(L_5)->SetAt(static_cast<il2cpp_array_size_t>(L_6), (RtcLocalAudioPropertiesInfo_tDEE2268599EA8C3EC747871F690C5743321ED49E*)L_11);
		// for (uint i = 0; i < total; i++)
		uint32_t L_12 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add((int32_t)L_12, 1));
	}

IL_0040:
	{
		// for (uint i = 0; i < total; i++)
		uint32_t L_13 = V_1;
		uint64_t L_14 = V_0;
		if ((!(((uint64_t)((int64_t)(uint64_t)L_13)) >= ((uint64_t)L_14))))
		{
			goto IL_0023;
		}
	}
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
// System.Void Pico.Platform.Models.RtcMediaDeviceChangeInfo::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcMediaDeviceChangeInfo__ctor_m8500EDE2340DEFF93732EAEB521C70CB5CE22D6B (RtcMediaDeviceChangeInfo_tB2715659230514BAEF53E2329D648EC92B790850* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public RtcMediaDeviceChangeInfo(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// DeviceId = CLIB.ppf_RtcMediaDeviceChangeInfo_GetDeviceId(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_RtcMediaDeviceChangeInfo_GetDeviceId_mD080CF35717527AC3A39D3DB669A418A3536FACF(L_0, NULL);
		__this->___DeviceId_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___DeviceId_0), (void*)L_1);
		// DeviceType = CLIB.ppf_RtcMediaDeviceChangeInfo_GetDeviceType(o);
		intptr_t L_2 = ___0_o;
		int32_t L_3;
		L_3 = CLIB_ppf_RtcMediaDeviceChangeInfo_GetDeviceType_mF351F9687B4EE87DB2B92BAB1778D6498534257B(L_2, NULL);
		__this->___DeviceType_1 = L_3;
		// DeviceState = CLIB.ppf_RtcMediaDeviceChangeInfo_GetDeviceState(o);
		intptr_t L_4 = ___0_o;
		int32_t L_5;
		L_5 = CLIB_ppf_RtcMediaDeviceChangeInfo_GetDeviceState_mA052BC17A25AF289F52F5F842AF9360E4322FD78(L_4, NULL);
		__this->___DeviceState_2 = L_5;
		// DeviceError = CLIB.ppf_RtcMediaDeviceChangeInfo_GetDeviceError(o);
		intptr_t L_6 = ___0_o;
		int32_t L_7;
		L_7 = CLIB_ppf_RtcMediaDeviceChangeInfo_GetDeviceError_m5DD51953D1D6B47D38BEA7CAA5BFAAAEBE93BF1B(L_6, NULL);
		__this->___DeviceError_3 = L_7;
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
// System.Void Pico.Platform.Models.RtcMuteInfo::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcMuteInfo__ctor_m3C54BEB8F5A442973EBFED444563DE9D02C52DC4 (RtcMuteInfo_t42EFA88A13E9A461000A46AEE9B3BD8017AC5416* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public RtcMuteInfo(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// UserId = CLIB.ppf_RtcMuteInfo_GetUserId(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_RtcMuteInfo_GetUserId_mECDD26685782CF1C9C0BF2B387FDA97F90855D79(L_0, NULL);
		__this->___UserId_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___UserId_0), (void*)L_1);
		// MuteState = CLIB.ppf_RtcMuteInfo_GetMuteState(o);
		intptr_t L_2 = ___0_o;
		int32_t L_3;
		L_3 = CLIB_ppf_RtcMuteInfo_GetMuteState_m6D2A6AD463AEACC90E5C553AC61B6639BF219F5C(L_2, NULL);
		__this->___MuteState_1 = L_3;
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
// System.Void Pico.Platform.Models.RtcRemoteAudioPropertiesInfo::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRemoteAudioPropertiesInfo__ctor_mB57DCD21659CC7D50B528459D77BCD195151A538 (RtcRemoteAudioPropertiesInfo_t756C00636961DE878EE3D2DAD934F01DC0DE3C06* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RtcAudioPropertyInfo_tA10BA2C71B943D7A31ED99324B58ECBC13C05268_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RtcRemoteStreamKey_tA69532F8EF7C977014612F775D146C3038C61E0E_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public RtcRemoteAudioPropertiesInfo(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// StreamKey = new RtcRemoteStreamKey(CLIB.ppf_RtcRemoteAudioPropertiesInfo_GetStreamKey(o));
		intptr_t L_0 = ___0_o;
		intptr_t L_1;
		L_1 = CLIB_ppf_RtcRemoteAudioPropertiesInfo_GetStreamKey_m29701F1CAD40F4E3CEA2CB0AFDAF32687C31ED75(L_0, NULL);
		RtcRemoteStreamKey_tA69532F8EF7C977014612F775D146C3038C61E0E* L_2 = (RtcRemoteStreamKey_tA69532F8EF7C977014612F775D146C3038C61E0E*)il2cpp_codegen_object_new(RtcRemoteStreamKey_tA69532F8EF7C977014612F775D146C3038C61E0E_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		RtcRemoteStreamKey__ctor_mA8181CF8D33199DCDEE57AE098F0FF9558C00875(L_2, L_1, NULL);
		__this->___StreamKey_0 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___StreamKey_0), (void*)L_2);
		// AudioPropertiesInfo = new RtcAudioPropertyInfo(CLIB.ppf_RtcRemoteAudioPropertiesInfo_GetAudioPropertiesInfo(o));
		intptr_t L_3 = ___0_o;
		intptr_t L_4;
		L_4 = CLIB_ppf_RtcRemoteAudioPropertiesInfo_GetAudioPropertiesInfo_m1FD8D4C46811BE8C893AA9079AAC0821BEA3835C(L_3, NULL);
		RtcAudioPropertyInfo_tA10BA2C71B943D7A31ED99324B58ECBC13C05268* L_5 = (RtcAudioPropertyInfo_tA10BA2C71B943D7A31ED99324B58ECBC13C05268*)il2cpp_codegen_object_new(RtcAudioPropertyInfo_tA10BA2C71B943D7A31ED99324B58ECBC13C05268_il2cpp_TypeInfo_var);
		NullCheck(L_5);
		RtcAudioPropertyInfo__ctor_mC061C4E479AA1830243454373F9FF6FEDC6C96DD(L_5, L_4, NULL);
		__this->___AudioPropertiesInfo_1 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___AudioPropertiesInfo_1), (void*)L_5);
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
// System.Void Pico.Platform.Models.RtcRemoteAudioPropertiesReport::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRemoteAudioPropertiesReport__ctor_mF7C56319B7F5278B9D0F6E43EB9DCAA12206AE22 (RtcRemoteAudioPropertiesReport_t575A87A1EE3387315239DA4AF54DAA70B4E5EB78* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RtcRemoteAudioPropertiesInfoU5BU5D_t4DD6EF874C9C2844E1101DAE658C91D04DC92952_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RtcRemoteAudioPropertiesInfo_t756C00636961DE878EE3D2DAD934F01DC0DE3C06_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	uint32_t V_0 = 0;
	{
		// public RtcRemoteAudioPropertiesReport(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// AudioPropertiesInfos = new RtcRemoteAudioPropertiesInfo[(int) CLIB.ppf_RtcRemoteAudioPropertiesReport_GetAudioPropertiesInfosSize(o)];
		intptr_t L_0 = ___0_o;
		uintptr_t L_1;
		L_1 = CLIB_ppf_RtcRemoteAudioPropertiesReport_GetAudioPropertiesInfosSize_mDC7D1FA23CCCFB05934D0B09620CF7FBEB56BEE7(L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint32_t L_2;
		L_2 = UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8(L_1, NULL);
		RtcRemoteAudioPropertiesInfoU5BU5D_t4DD6EF874C9C2844E1101DAE658C91D04DC92952* L_3 = (RtcRemoteAudioPropertiesInfoU5BU5D_t4DD6EF874C9C2844E1101DAE658C91D04DC92952*)(RtcRemoteAudioPropertiesInfoU5BU5D_t4DD6EF874C9C2844E1101DAE658C91D04DC92952*)SZArrayNew(RtcRemoteAudioPropertiesInfoU5BU5D_t4DD6EF874C9C2844E1101DAE658C91D04DC92952_il2cpp_TypeInfo_var, (uint32_t)L_2);
		__this->___AudioPropertiesInfos_0 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___AudioPropertiesInfos_0), (void*)L_3);
		// for (uint i = 0; i < AudioPropertiesInfos.Length; i++)
		V_0 = 0;
		goto IL_003d;
	}

IL_0020:
	{
		// AudioPropertiesInfos[i] = new RtcRemoteAudioPropertiesInfo(CLIB.ppf_RtcRemoteAudioPropertiesReport_GetAudioPropertiesInfos(o, (UIntPtr) i));
		RtcRemoteAudioPropertiesInfoU5BU5D_t4DD6EF874C9C2844E1101DAE658C91D04DC92952* L_4 = __this->___AudioPropertiesInfos_0;
		uint32_t L_5 = V_0;
		intptr_t L_6 = ___0_o;
		uint32_t L_7 = V_0;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_8;
		L_8 = UIntPtr_op_Explicit_mD94DCD8965DD2E7D5A3370A04CCEDBE5937C078C(L_7, NULL);
		intptr_t L_9;
		L_9 = CLIB_ppf_RtcRemoteAudioPropertiesReport_GetAudioPropertiesInfos_mB861D881206B2E67963B1FD1E36708EFA96B3C60(L_6, L_8, NULL);
		RtcRemoteAudioPropertiesInfo_t756C00636961DE878EE3D2DAD934F01DC0DE3C06* L_10 = (RtcRemoteAudioPropertiesInfo_t756C00636961DE878EE3D2DAD934F01DC0DE3C06*)il2cpp_codegen_object_new(RtcRemoteAudioPropertiesInfo_t756C00636961DE878EE3D2DAD934F01DC0DE3C06_il2cpp_TypeInfo_var);
		NullCheck(L_10);
		RtcRemoteAudioPropertiesInfo__ctor_mB57DCD21659CC7D50B528459D77BCD195151A538(L_10, L_9, NULL);
		NullCheck(L_4);
		ArrayElementTypeCheck (L_4, L_10);
		(L_4)->SetAt(static_cast<il2cpp_array_size_t>(L_5), (RtcRemoteAudioPropertiesInfo_t756C00636961DE878EE3D2DAD934F01DC0DE3C06*)L_10);
		// for (uint i = 0; i < AudioPropertiesInfos.Length; i++)
		uint32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add((int32_t)L_11, 1));
	}

IL_003d:
	{
		// for (uint i = 0; i < AudioPropertiesInfos.Length; i++)
		uint32_t L_12 = V_0;
		RtcRemoteAudioPropertiesInfoU5BU5D_t4DD6EF874C9C2844E1101DAE658C91D04DC92952* L_13 = __this->___AudioPropertiesInfos_0;
		NullCheck(L_13);
		if ((((int64_t)((int64_t)(uint64_t)L_12)) < ((int64_t)((int64_t)((int32_t)(((RuntimeArray*)L_13)->max_length))))))
		{
			goto IL_0020;
		}
	}
	{
		// TotalRemoteVolume = CLIB.ppf_RtcRemoteAudioPropertiesReport_GetTotalRemoteVolume(o);
		intptr_t L_14 = ___0_o;
		int32_t L_15;
		L_15 = CLIB_ppf_RtcRemoteAudioPropertiesReport_GetTotalRemoteVolume_mE273A923B61FEB94104FCE5F74F2F13D73111A8D(L_14, NULL);
		__this->___TotalRemoteVolume_1 = L_15;
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
// System.Void Pico.Platform.Models.RtcRemoteStreamKey::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRemoteStreamKey__ctor_mA8181CF8D33199DCDEE57AE098F0FF9558C00875 (RtcRemoteStreamKey_tA69532F8EF7C977014612F775D146C3038C61E0E* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public RtcRemoteStreamKey(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// RoomId = CLIB.ppf_RtcRemoteStreamKey_GetRoomId(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_RtcRemoteStreamKey_GetRoomId_mEC240EDB6E553C1BB7858D3EC192E7F4EC6ABF8C(L_0, NULL);
		__this->___RoomId_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___RoomId_0), (void*)L_1);
		// UserId = CLIB.ppf_RtcRemoteStreamKey_GetUserId(o);
		intptr_t L_2 = ___0_o;
		String_t* L_3;
		L_3 = CLIB_ppf_RtcRemoteStreamKey_GetUserId_m752740195D7553E90ACC9A9F5DB55FF828F32C1B(L_2, NULL);
		__this->___UserId_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___UserId_1), (void*)L_3);
		// RtcStreamIndex = CLIB.ppf_RtcRemoteStreamKey_GetStreamIndex(o);
		intptr_t L_4 = ___0_o;
		int32_t L_5;
		L_5 = CLIB_ppf_RtcRemoteStreamKey_GetStreamIndex_m04DA08988BEFC2FDBA1A4FF953FA21C17B7C46BF(L_4, NULL);
		__this->___RtcStreamIndex_2 = L_5;
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
// System.Void Pico.Platform.Models.RtcRoomError::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRoomError__ctor_m217646918A21BB202206C9A9AE150E02749192BC (RtcRoomError_t9E2842355A967FB7C0C5170BBAE107B299384383* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public RtcRoomError(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Code = CLIB.ppf_RtcRoomError_GetCode(o);
		intptr_t L_0 = ___0_o;
		int32_t L_1;
		L_1 = CLIB_ppf_RtcRoomError_GetCode_mD43CFDED25CF9BB29B81733140B7861B5E74B1D0(L_0, NULL);
		__this->___Code_0 = L_1;
		// RoomId = CLIB.ppf_RtcRoomError_GetRoomId(o);
		intptr_t L_2 = ___0_o;
		String_t* L_3;
		L_3 = CLIB_ppf_RtcRoomError_GetRoomId_m49DD269CFA22AE87ABAD01B04A2226B96F44278A(L_2, NULL);
		__this->___RoomId_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___RoomId_1), (void*)L_3);
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
// System.Void Pico.Platform.Models.RtcRoomStats::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRoomStats__ctor_mEC96AB8DB2C5DF4D934943EB7AFED398165F3766 (RtcRoomStats_t82FFF1123D5D67FC8D0027DD78C0BCD933C419CE* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public RtcRoomStats(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// TotalDuration = CLIB.ppf_RtcRoomStats_GetTotalDuration(o);
		intptr_t L_0 = ___0_o;
		int32_t L_1;
		L_1 = CLIB_ppf_RtcRoomStats_GetTotalDuration_mD290C803D191A9D7F8494D918DAA7A60BE53C1A8(L_0, NULL);
		__this->___TotalDuration_0 = L_1;
		// UserCount = CLIB.ppf_RtcRoomStats_GetUserCount(o);
		intptr_t L_2 = ___0_o;
		int32_t L_3;
		L_3 = CLIB_ppf_RtcRoomStats_GetUserCount_m5FF2D4018EFCF23C3BFA492DD1AEAB0AC181EDD1(L_2, NULL);
		__this->___UserCount_1 = L_3;
		// RoomId = CLIB.ppf_RtcRoomStats_GetRoomId(o);
		intptr_t L_4 = ___0_o;
		String_t* L_5;
		L_5 = CLIB_ppf_RtcRoomStats_GetRoomId_m0714FFD58930EF37598D7173AF86AB6BC4A4C59B(L_4, NULL);
		__this->___RoomId_2 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___RoomId_2), (void*)L_5);
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
// System.Void Pico.Platform.Models.RtcRoomWarn::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcRoomWarn__ctor_m7CDFA2A91713BE86F1329061C8C1268EB01F7FBB (RtcRoomWarn_t606796009EEE6543FEC76C7457FB6F8156C06BD4* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public RtcRoomWarn(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Code = CLIB.ppf_RtcRoomWarn_GetCode(o);
		intptr_t L_0 = ___0_o;
		int32_t L_1;
		L_1 = CLIB_ppf_RtcRoomWarn_GetCode_mA07CDF200989FBD62FF5D36AA6D7A0FF859E07FD(L_0, NULL);
		__this->___Code_0 = L_1;
		// RoomId = CLIB.ppf_RtcRoomWarn_GetRoomId(o);
		intptr_t L_2 = ___0_o;
		String_t* L_3;
		L_3 = CLIB_ppf_RtcRoomWarn_GetRoomId_mCF5B71B2EED77BA0CC8955E9821C260EEE40B0A1(L_2, NULL);
		__this->___RoomId_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___RoomId_1), (void*)L_3);
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
// System.Void Pico.Platform.Models.RtcUserJoinInfo::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcUserJoinInfo__ctor_mE3B9C66118A91C8F980048A6DE9735CB1874B7EA (RtcUserJoinInfo_t2B639AA4EA2CEC3216FF167FA01780A3F6B7B747* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public RtcUserJoinInfo(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// UserId = CLIB.ppf_RtcUserJoinInfo_GetUserId(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_RtcUserJoinInfo_GetUserId_mAB7DC7757B17BA43E1F677E0DAF097FA82EE45ED(L_0, NULL);
		__this->___UserId_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___UserId_0), (void*)L_1);
		// UserExtra = CLIB.ppf_RtcUserJoinInfo_GetUserExtra(o);
		intptr_t L_2 = ___0_o;
		String_t* L_3;
		L_3 = CLIB_ppf_RtcUserJoinInfo_GetUserExtra_mBEE960EDE2EAE2185937FE1EF20899A103B2B95C(L_2, NULL);
		__this->___UserExtra_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___UserExtra_1), (void*)L_3);
		// Elapsed = CLIB.ppf_RtcUserJoinInfo_GetElapsed(o);
		intptr_t L_4 = ___0_o;
		int32_t L_5;
		L_5 = CLIB_ppf_RtcUserJoinInfo_GetElapsed_mCA4C9F7D363B7069999375A725496EC51950A75D(L_4, NULL);
		__this->___Elapsed_2 = L_5;
		// RoomId = CLIB.ppf_RtcUserJoinInfo_GetRoomId(o);
		intptr_t L_6 = ___0_o;
		String_t* L_7;
		L_7 = CLIB_ppf_RtcUserJoinInfo_GetRoomId_m42A8B4AC3AFBCEF578550E778512120FBFFEC536(L_6, NULL);
		__this->___RoomId_3 = L_7;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___RoomId_3), (void*)L_7);
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
// System.Void Pico.Platform.Models.RtcUserLeaveInfo::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RtcUserLeaveInfo__ctor_mDD91E36255CD46659679A2F2E649779737F37ED7 (RtcUserLeaveInfo_tC24C9CCF5AEE733D5431F5C973C813C2C36C54FE* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public RtcUserLeaveInfo(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// UserId = CLIB.ppf_RtcUserLeaveInfo_GetUserId(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_RtcUserLeaveInfo_GetUserId_mAEC74CE8B7BDB7860BD0DD256209ACAC6DBFA654(L_0, NULL);
		__this->___UserId_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___UserId_0), (void*)L_1);
		// OfflineReason = CLIB.ppf_RtcUserLeaveInfo_GetOfflineReason(o);
		intptr_t L_2 = ___0_o;
		int32_t L_3;
		L_3 = CLIB_ppf_RtcUserLeaveInfo_GetOfflineReason_m086FDF661763803175EC997688F200A36E1BFEE8(L_2, NULL);
		__this->___OfflineReason_1 = L_3;
		// RoomId = CLIB.ppf_RtcUserLeaveInfo_GetRoomId(o);
		intptr_t L_4 = ___0_o;
		String_t* L_5;
		L_5 = CLIB_ppf_RtcUserLeaveInfo_GetRoomId_m518491FFC6B2A1CE2F13233721EECC2909230CF1(L_4, NULL);
		__this->___RoomId_2 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___RoomId_2), (void*)L_5);
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
// System.Void Pico.Platform.Models.AsrResult::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AsrResult__ctor_mD74BAFECAE819544CF068FE7AE3BB1C7838AD349 (AsrResult_t004816647ADC1F06A8D0AE66C355906FB022BEA5* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public AsrResult(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Text = CLIB.ppf_AsrResult_GetText(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_AsrResult_GetText_m98DC33A218EA20F4007023A3C9A9DAE655DC3981(L_0, NULL);
		__this->___Text_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Text_0), (void*)L_1);
		// IsFinalResult = CLIB.ppf_AsrResult_GetIsFinalResult(o);
		intptr_t L_2 = ___0_o;
		bool L_3;
		L_3 = CLIB_ppf_AsrResult_GetIsFinalResult_mFA662FC4CE8DA4E8B6D4721940DF8F350863BDC1(L_2, NULL);
		__this->___IsFinalResult_1 = L_3;
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
// System.Void Pico.Platform.Models.SpeechError::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpeechError__ctor_m024F1E267FD9A5927AF077A6CA675E8CC4DA612D (SpeechError_t370B79F899E733FECFC5D12BFA22AB0E146C96FB* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public SpeechError(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Message = CLIB.ppf_SpeechError_GetMessage(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_SpeechError_GetMessage_mA9F88B85A0105651418FE850415A6DE0EBF73C02(L_0, NULL);
		__this->___Message_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Message_0), (void*)L_1);
		// Code = CLIB.ppf_SpeechError_GetCode(o);
		intptr_t L_2 = ___0_o;
		int32_t L_3;
		L_3 = CLIB_ppf_SpeechError_GetCode_m776FFB712F888806C1F3EF2832E6FBF703D3CD54(L_2, NULL);
		__this->___Code_2 = L_3;
		// SessionId = CLIB.ppf_SpeechError_GetSessionId(o);
		intptr_t L_4 = ___0_o;
		String_t* L_5;
		L_5 = CLIB_ppf_SpeechError_GetSessionId_m0CA11F6BAED5DB0FB2839B213E0E17E1A8B4F600(L_4, NULL);
		__this->___SessionId_1 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___SessionId_1), (void*)L_5);
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
// System.Void Pico.Platform.Models.SportDailySummary::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SportDailySummary__ctor_m414B482BE61A12E06A1A9AD9754172A30A153607 (SportDailySummary_t1202315FC8419F0C908ACF448A0DF4EF207756F0* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public SportDailySummary(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Id = CLIB.ppf_SportDailySummary_GetId(o);
		intptr_t L_0 = ___0_o;
		int64_t L_1;
		L_1 = CLIB_ppf_SportDailySummary_GetId_mD0C7B8787EAE9F59909A790CAFD2571868596D6E(L_0, NULL);
		__this->___Id_0 = L_1;
		// Date = TimeUtil.MilliSecondsToDateTime(CLIB.ppf_SportDailySummary_GetDate(o));
		intptr_t L_2 = ___0_o;
		int64_t L_3;
		L_3 = CLIB_ppf_SportDailySummary_GetDate_mD2688B53970514537C71524FA509B773751E0E6D(L_2, NULL);
		il2cpp_codegen_runtime_class_init_inline(TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_4;
		L_4 = TimeUtil_MilliSecondsToDateTime_mF1197E9C5865487072B28200D665A6AEEA15F54C(L_3, NULL);
		__this->___Date_1 = L_4;
		// DurationInSeconds = CLIB.ppf_SportDailySummary_GetDurationInSeconds(o);
		intptr_t L_5 = ___0_o;
		int32_t L_6;
		L_6 = CLIB_ppf_SportDailySummary_GetDurationInSeconds_mB3CC475B83BD6172711D50E395583FA551AEC8F6(L_5, NULL);
		__this->___DurationInSeconds_2 = L_6;
		// PlanDurationInMinutes = CLIB.ppf_SportDailySummary_GetPlanDurationInMinutes(o);
		intptr_t L_7 = ___0_o;
		int32_t L_8;
		L_8 = CLIB_ppf_SportDailySummary_GetPlanDurationInMinutes_m5D35BAF66BE477FBA087DFCD04BF3F17710ADB7E(L_7, NULL);
		__this->___PlanDurationInMinutes_3 = L_8;
		// Calorie = CLIB.ppf_SportDailySummary_GetCalorie(o);
		intptr_t L_9 = ___0_o;
		double L_10;
		L_10 = CLIB_ppf_SportDailySummary_GetCalorie_m6E4BE90C8F10CAE8521D8B445EDF93C0B19B5D64(L_9, NULL);
		__this->___Calorie_4 = L_10;
		// PlanCalorie = CLIB.ppf_SportDailySummary_GetPlanCalorie(o);
		intptr_t L_11 = ___0_o;
		double L_12;
		L_12 = CLIB_ppf_SportDailySummary_GetPlanCalorie_mB82EC6532FB7EF2001A89D37929F321D7E1B73AF(L_11, NULL);
		__this->___PlanCalorie_5 = L_12;
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
// System.Void Pico.Platform.Models.SportDailySummaryList::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SportDailySummaryList__ctor_m8FC1C7E60CC6DE1D8123051A2C7BDA886BD91FE2 (SportDailySummaryList_tDB9E5A80ED100417F113C33891F04F9CF8DB5BC6* __this, intptr_t ___0_a, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mB7F4419CE7EA8D9E393B3D5CF160812DB776DD9C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_set_Capacity_m7C5EB735CBD98B3B2B64F7FA49954FD5ED73D728_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageArray_1__ctor_m1A4632C39F931579FEBF2FEA60B370A49C699D53_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SportDailySummary_t1202315FC8419F0C908ACF448A0DF4EF207756F0_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		// public SportDailySummaryList(IntPtr a)
		MessageArray_1__ctor_m1A4632C39F931579FEBF2FEA60B370A49C699D53(__this, MessageArray_1__ctor_m1A4632C39F931579FEBF2FEA60B370A49C699D53_RuntimeMethod_var);
		// var count = (int) CLIB.ppf_SportDailySummaryArray_GetSize(a);
		intptr_t L_0 = ___0_a;
		uintptr_t L_1;
		L_1 = CLIB_ppf_SportDailySummaryArray_GetSize_m5095964C0C481DE77230E452B5B019EA2BD8C993(L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint32_t L_2;
		L_2 = UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8(L_1, NULL);
		V_0 = L_2;
		// this.Capacity = count;
		int32_t L_3 = V_0;
		List_1_set_Capacity_m7C5EB735CBD98B3B2B64F7FA49954FD5ED73D728(__this, L_3, List_1_set_Capacity_m7C5EB735CBD98B3B2B64F7FA49954FD5ED73D728_RuntimeMethod_var);
		// for (int i = 0; i < count; i++)
		V_1 = 0;
		goto IL_0039;
	}

IL_001d:
	{
		// this.Add(new SportDailySummary(CLIB.ppf_SportDailySummaryArray_GetElement(a, (UIntPtr) i)));
		intptr_t L_4 = ___0_a;
		int32_t L_5 = V_1;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_6;
		L_6 = UIntPtr_op_Explicit_mF1E7911DD5AC13B5E59EE8C7903469D12A3861E8(((int64_t)L_5), NULL);
		intptr_t L_7;
		L_7 = CLIB_ppf_SportDailySummaryArray_GetElement_mA3D507B82F2BCDC0B57FDBA460EE45C43AF85584(L_4, L_6, NULL);
		SportDailySummary_t1202315FC8419F0C908ACF448A0DF4EF207756F0* L_8 = (SportDailySummary_t1202315FC8419F0C908ACF448A0DF4EF207756F0*)il2cpp_codegen_object_new(SportDailySummary_t1202315FC8419F0C908ACF448A0DF4EF207756F0_il2cpp_TypeInfo_var);
		NullCheck(L_8);
		SportDailySummary__ctor_m414B482BE61A12E06A1A9AD9754172A30A153607(L_8, L_7, NULL);
		List_1_Add_mB7F4419CE7EA8D9E393B3D5CF160812DB776DD9C_inline(__this, L_8, List_1_Add_mB7F4419CE7EA8D9E393B3D5CF160812DB776DD9C_RuntimeMethod_var);
		// for (int i = 0; i < count; i++)
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0039:
	{
		// for (int i = 0; i < count; i++)
		int32_t L_10 = V_1;
		int32_t L_11 = V_0;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_001d;
		}
	}
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
// System.Void Pico.Platform.Models.SportSummary::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SportSummary__ctor_mE98EC8E61F32FF6863DA6F8712DED3A2AD97AB6B (SportSummary_t6193CC64BC93B9813F42F50B37479017FB3067D1* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public SportSummary(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// DurationInSeconds = (int) CLIB.ppf_SportSummary_GetDurationInSeconds(o);
		intptr_t L_0 = ___0_o;
		int64_t L_1;
		L_1 = CLIB_ppf_SportSummary_GetDurationInSeconds_mEA277BCC9042996C88F05700B6F5F5E141CACE11(L_0, NULL);
		__this->___DurationInSeconds_0 = ((int32_t)L_1);
		// Calorie = CLIB.ppf_SportSummary_GetCalorie(o);
		intptr_t L_2 = ___0_o;
		double L_3;
		L_3 = CLIB_ppf_SportSummary_GetCalorie_mD0DED681090542C6772B89E941887D99F79C493F(L_2, NULL);
		__this->___Calorie_1 = L_3;
		// StartTime = TimeUtil.MilliSecondsToDateTime(CLIB.ppf_SportSummary_GetStartTime(o));
		intptr_t L_4 = ___0_o;
		int64_t L_5;
		L_5 = CLIB_ppf_SportSummary_GetStartTime_m8B1F09B26AF08C93109B09230F61E765F14E5AB1(L_4, NULL);
		il2cpp_codegen_runtime_class_init_inline(TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_6;
		L_6 = TimeUtil_MilliSecondsToDateTime_mF1197E9C5865487072B28200D665A6AEEA15F54C(L_5, NULL);
		__this->___StartTime_2 = L_6;
		// EndTime = TimeUtil.MilliSecondsToDateTime(CLIB.ppf_SportSummary_GetEndTime(o));
		intptr_t L_7 = ___0_o;
		int64_t L_8;
		L_8 = CLIB_ppf_SportSummary_GetEndTime_m0D4A52380219D1A445CFA7F717EE13AD0040D9D9(L_7, NULL);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_9;
		L_9 = TimeUtil_MilliSecondsToDateTime_mF1197E9C5865487072B28200D665A6AEEA15F54C(L_8, NULL);
		__this->___EndTime_3 = L_9;
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
// System.Void Pico.Platform.Models.SportUserInfo::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SportUserInfo__ctor_m3DB7227F31818D9566EFD97958D27345D78AD1AC (SportUserInfo_tFA26719517B940DC321942A68AE48D23AFAE5D78* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public SportUserInfo(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Gender = CLIB.ppf_SportUserInfo_GetGender(o);
		intptr_t L_0 = ___0_o;
		int32_t L_1;
		L_1 = CLIB_ppf_SportUserInfo_GetGender_m4BA39777D6E8DCADBDD516A351E5525C79C2C632(L_0, NULL);
		__this->___Gender_0 = L_1;
		// Birthday = TimeUtil.MilliSecondsToDateTime(CLIB.ppf_SportUserInfo_GetBirthday(o));
		intptr_t L_2 = ___0_o;
		int64_t L_3;
		L_3 = CLIB_ppf_SportUserInfo_GetBirthday_m96446A5C5EE2E53AE7E9219F54BFC6069DC46779(L_2, NULL);
		il2cpp_codegen_runtime_class_init_inline(TimeUtil_t5452C06092BC6F084DE46286E7F0D4FA1E970C36_il2cpp_TypeInfo_var);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_4;
		L_4 = TimeUtil_MilliSecondsToDateTime_mF1197E9C5865487072B28200D665A6AEEA15F54C(L_3, NULL);
		__this->___Birthday_1 = L_4;
		// Stature = CLIB.ppf_SportUserInfo_GetStature(o);
		intptr_t L_5 = ___0_o;
		int32_t L_6;
		L_6 = CLIB_ppf_SportUserInfo_GetStature_m5308010D0B887831F1D027C7A7CA6EE4C3198C0B(L_5, NULL);
		__this->___Stature_2 = L_6;
		// Weight = CLIB.ppf_SportUserInfo_GetWeight(o);
		intptr_t L_7 = ___0_o;
		int32_t L_8;
		L_8 = CLIB_ppf_SportUserInfo_GetWeight_m0917EEEDE18EEF40D96E5800918CB2A182350954(L_7, NULL);
		__this->___Weight_3 = L_8;
		// SportLevel = CLIB.ppf_SportUserInfo_GetSportLevel(o);
		intptr_t L_9 = ___0_o;
		int32_t L_10;
		L_10 = CLIB_ppf_SportUserInfo_GetSportLevel_m50993DC43A4FF63D1F69C20072C1C4A4F6130ED3(L_9, NULL);
		__this->___SportLevel_4 = L_10;
		// DailyDurationInMinutes = CLIB.ppf_SportUserInfo_GetDailyDurationInMinutes(o);
		intptr_t L_11 = ___0_o;
		int32_t L_12;
		L_12 = CLIB_ppf_SportUserInfo_GetDailyDurationInMinutes_m94D2A7F60CFA76305B38B721A092F32A2E3F9AA0(L_11, NULL);
		__this->___DailyDurationInMinutes_5 = L_12;
		// DaysPerWeek = CLIB.ppf_SportUserInfo_GetDaysPerWeek(o);
		intptr_t L_13 = ___0_o;
		int32_t L_14;
		L_14 = CLIB_ppf_SportUserInfo_GetDaysPerWeek_m6E4BFC9A8DFEB59492044F6B588646D21334B26D(L_13, NULL);
		__this->___DaysPerWeek_6 = L_14;
		// SportTarget = CLIB.ppf_SportUserInfo_GetSportTarget(o);
		intptr_t L_15 = ___0_o;
		int32_t L_16;
		L_16 = CLIB_ppf_SportUserInfo_GetSportTarget_m9C89EC1396CC22229A482F2095B6BD0662E2FEED(L_15, NULL);
		__this->___SportTarget_7 = L_16;
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
// System.Void Pico.Platform.Models.User::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void User__ctor_m0A17383A33457E27EB6AD299C81C77AC1802E0D1 (User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4* __this, intptr_t ___0_obj, const RuntimeMethod* method) 
{
	{
		// public User(IntPtr obj)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// DisplayName = CLIB.ppf_User_GetDisplayName(obj);
		intptr_t L_0 = ___0_obj;
		String_t* L_1;
		L_1 = CLIB_ppf_User_GetDisplayName_m6495233A8495D847FA8F01794081DDDC82EC514D(L_0, NULL);
		__this->___DisplayName_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___DisplayName_0), (void*)L_1);
		// ImageUrl = CLIB.ppf_User_GetImageUrl(obj);
		intptr_t L_2 = ___0_obj;
		String_t* L_3;
		L_3 = CLIB_ppf_User_GetImageUrl_mF54B7F71B18B868BE97323D8F9D8D4B7FDDDCF6D(L_2, NULL);
		__this->___ImageUrl_1 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___ImageUrl_1), (void*)L_3);
		// ID = CLIB.ppf_User_GetID(obj);
		intptr_t L_4 = ___0_obj;
		String_t* L_5;
		L_5 = CLIB_ppf_User_GetID_mFCED817FC648DDC3918EB0D56652F88342640033(L_4, NULL);
		__this->___ID_3 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___ID_3), (void*)L_5);
		// InviteToken = CLIB.ppf_User_GetInviteToken(obj);
		intptr_t L_6 = ___0_obj;
		String_t* L_7;
		L_7 = CLIB_ppf_User_GetInviteToken_m758417F040077D7413AD6E6B70A8F90C3DC44D17(L_6, NULL);
		__this->___InviteToken_13 = L_7;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___InviteToken_13), (void*)L_7);
		// PresenceStatus = CLIB.ppf_User_GetPresenceStatus(obj);
		intptr_t L_8 = ___0_obj;
		int32_t L_9;
		L_9 = CLIB_ppf_User_GetPresenceStatus_m56F7990DB626B12C02E9C31E46DF1F2E3E71BE9F(L_8, NULL);
		__this->___PresenceStatus_4 = L_9;
		// Gender = CLIB.ppf_User_GetGender(obj);
		intptr_t L_10 = ___0_obj;
		int32_t L_11;
		L_11 = CLIB_ppf_User_GetGender_mC6AA156708699C5B255F83D1B42FFDD20E56095E(L_10, NULL);
		__this->___Gender_5 = L_11;
		// Presence = CLIB.ppf_User_GetPresence(obj);
		intptr_t L_12 = ___0_obj;
		String_t* L_13;
		L_13 = CLIB_ppf_User_GetPresence_m256411CC38F04771EA51021A5DE7730E181FB3CF(L_12, NULL);
		__this->___Presence_6 = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Presence_6), (void*)L_13);
		// PresenceDeeplinkMessage = CLIB.ppf_User_GetPresenceDeeplinkMessage(obj);
		intptr_t L_14 = ___0_obj;
		String_t* L_15;
		L_15 = CLIB_ppf_User_GetPresenceDeeplinkMessage_m2DA0CD3BE73EAD3BF0FE8F11629220E7F0B71276(L_14, NULL);
		__this->___PresenceDeeplinkMessage_7 = L_15;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___PresenceDeeplinkMessage_7), (void*)L_15);
		// PresenceDestinationApiName = CLIB.ppf_User_GetPresenceDestinationApiName(obj);
		intptr_t L_16 = ___0_obj;
		String_t* L_17;
		L_17 = CLIB_ppf_User_GetPresenceDestinationApiName_mCAE5F575A00155B4B2E55B8D9B2A6814F90195CF(L_16, NULL);
		__this->___PresenceDestinationApiName_8 = L_17;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___PresenceDestinationApiName_8), (void*)L_17);
		// PresenceLobbySessionId = CLIB.ppf_User_GetPresenceLobbySessionId(obj);
		intptr_t L_18 = ___0_obj;
		String_t* L_19;
		L_19 = CLIB_ppf_User_GetPresenceLobbySessionId_m702C4BD3E75BD3EF160174ECB05F70F145051A26(L_18, NULL);
		__this->___PresenceLobbySessionId_9 = L_19;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___PresenceLobbySessionId_9), (void*)L_19);
		// PresenceMatchSessionId = CLIB.ppf_User_GetPresenceMatchSessionId(obj);
		intptr_t L_20 = ___0_obj;
		String_t* L_21;
		L_21 = CLIB_ppf_User_GetPresenceMatchSessionId_m7FA4BBC2A376AEAC6CA8B25AFF69C76ACA3788CB(L_20, NULL);
		__this->___PresenceMatchSessionId_10 = L_21;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___PresenceMatchSessionId_10), (void*)L_21);
		// PresenceExtra = CLIB.ppf_User_GetPresenceExtra(obj);
		intptr_t L_22 = ___0_obj;
		String_t* L_23;
		L_23 = CLIB_ppf_User_GetPresenceExtra_m12730CEEC5DC9E8737B6E2915C30F90F27D1F2C3(L_22, NULL);
		__this->___PresenceExtra_11 = L_23;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___PresenceExtra_11), (void*)L_23);
		// PresenceIsJoinable = CLIB.ppf_User_GetPresenceIsJoinable(obj);
		intptr_t L_24 = ___0_obj;
		bool L_25;
		L_25 = CLIB_ppf_User_GetPresenceIsJoinable_mFFA9BCA736B46C756A8ED1120DE8DE7DFF6BE133(L_24, NULL);
		__this->___PresenceIsJoinable_12 = L_25;
		// SmallImageUrl = CLIB.ppf_User_GetSmallImageUrl(obj);
		intptr_t L_26 = ___0_obj;
		String_t* L_27;
		L_27 = CLIB_ppf_User_GetSmallImageUrl_m16BE75B35032EA60BE97C76FBE1F9436F7B5BD89(L_26, NULL);
		__this->___SmallImageUrl_2 = L_27;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___SmallImageUrl_2), (void*)L_27);
		// InviteToken = CLIB.ppf_User_GetInviteToken(obj);
		intptr_t L_28 = ___0_obj;
		String_t* L_29;
		L_29 = CLIB_ppf_User_GetInviteToken_m758417F040077D7413AD6E6B70A8F90C3DC44D17(L_28, NULL);
		__this->___InviteToken_13 = L_29;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___InviteToken_13), (void*)L_29);
		// StoreRegion = CLIB.ppf_User_GetStoreRegion(obj);
		intptr_t L_30 = ___0_obj;
		String_t* L_31;
		L_31 = CLIB_ppf_User_GetStoreRegion_mE2E6D71E336324B0AF7AC2196293C613B85624BF(L_30, NULL);
		__this->___StoreRegion_14 = L_31;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___StoreRegion_14), (void*)L_31);
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
// System.Void Pico.Platform.Models.UserList::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UserList__ctor_m4FEB49DD26A4410363EE489A1D289C8725776F4D (UserList_t5DD5257033AB7F06FBA7064529EE1C57F3ACAD2F* __this, intptr_t ___0_a, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mFA38C07130F30DDA8AFCD688E19E79D20832CF90_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_set_Capacity_m53C9442D7A2C89C4DC109B654F6515D05DE52B16_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageArray_1__ctor_m67D3B507B26914F09606DA7A23A8061AC239B379_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		// public UserList(IntPtr a)
		MessageArray_1__ctor_m67D3B507B26914F09606DA7A23A8061AC239B379(__this, MessageArray_1__ctor_m67D3B507B26914F09606DA7A23A8061AC239B379_RuntimeMethod_var);
		// var count = (int) CLIB.ppf_UserArray_GetSize(a);
		intptr_t L_0 = ___0_a;
		uintptr_t L_1;
		L_1 = CLIB_ppf_UserArray_GetSize_m303552B1FB5CE41D8FAB1842B601C9FF0D24B8ED(L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint32_t L_2;
		L_2 = UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8(L_1, NULL);
		V_0 = L_2;
		// this.Capacity = count;
		int32_t L_3 = V_0;
		List_1_set_Capacity_m53C9442D7A2C89C4DC109B654F6515D05DE52B16(__this, L_3, List_1_set_Capacity_m53C9442D7A2C89C4DC109B654F6515D05DE52B16_RuntimeMethod_var);
		// for (int i = 0; i < count; i++)
		V_1 = 0;
		goto IL_0039;
	}

IL_001d:
	{
		// this.Add(new User(CLIB.ppf_UserArray_GetElement(a, (UIntPtr) i)));
		intptr_t L_4 = ___0_a;
		int32_t L_5 = V_1;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_6;
		L_6 = UIntPtr_op_Explicit_mF1E7911DD5AC13B5E59EE8C7903469D12A3861E8(((int64_t)L_5), NULL);
		intptr_t L_7;
		L_7 = CLIB_ppf_UserArray_GetElement_mA1E157914FFB811246B91FDE3EB6E5442CAC195D(L_4, L_6, NULL);
		User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4* L_8 = (User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4*)il2cpp_codegen_object_new(User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4_il2cpp_TypeInfo_var);
		NullCheck(L_8);
		User__ctor_m0A17383A33457E27EB6AD299C81C77AC1802E0D1(L_8, L_7, NULL);
		List_1_Add_mFA38C07130F30DDA8AFCD688E19E79D20832CF90_inline(__this, L_8, List_1_Add_mFA38C07130F30DDA8AFCD688E19E79D20832CF90_RuntimeMethod_var);
		// for (int i = 0; i < count; i++)
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0039:
	{
		// for (int i = 0; i < count; i++)
		int32_t L_10 = V_1;
		int32_t L_11 = V_0;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_001d;
		}
	}
	{
		// NextPageParam = CLIB.ppf_UserArray_GetNextPageParam(a);
		intptr_t L_12 = ___0_a;
		String_t* L_13;
		L_13 = CLIB_ppf_UserArray_GetNextPageParam_m4698658C6DF4F21C3429E5BE1AE5C6D3AFAA395C(L_12, NULL);
		((MessageArray_1_t3FBFD71C2ED89BC1E98F61EFDB0C5C6DADE06A17*)__this)->___NextPageParam_6 = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((MessageArray_1_t3FBFD71C2ED89BC1E98F61EFDB0C5C6DADE06A17*)__this)->___NextPageParam_6), (void*)L_13);
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
// System.Void Pico.Platform.Models.OrgScopedID::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OrgScopedID__ctor_m8B947B00E380275E6DE53DC460E4A2B9637CD51F (OrgScopedID_tE7AFDD1678D708DC9371763230892D40F965A581* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public OrgScopedID(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// ID = CLIB.ppf_OrgScopedID_GetID(o);
		intptr_t L_0 = ___0_o;
		String_t* L_1;
		L_1 = CLIB_ppf_OrgScopedID_GetID_mA71FE5E5CCADE9A14878DB489CC90E98B2B18580(L_0, NULL);
		__this->___ID_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___ID_0), (void*)L_1);
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
// System.Void Pico.Platform.Models.LaunchFriendResult::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LaunchFriendResult__ctor_m0E0F34D600BA68115EB544FC32B7B909613982E1 (LaunchFriendResult_tE14F761B20423DF2AA66723EEB659CEA351551A1* __this, intptr_t ___0_obj, const RuntimeMethod* method) 
{
	{
		// public LaunchFriendResult(IntPtr obj)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// DidCancel = CLIB.ppf_LaunchFriendRequestFlowResult_GetDidCancel(obj);
		intptr_t L_0 = ___0_obj;
		bool L_1;
		L_1 = CLIB_ppf_LaunchFriendRequestFlowResult_GetDidCancel_m049AD52959673162088772F82B3176442B1CA202(L_0, NULL);
		__this->___DidCancel_0 = L_1;
		// DidSendRequest = CLIB.ppf_LaunchFriendRequestFlowResult_GetDidSendRequest(obj);
		intptr_t L_2 = ___0_obj;
		bool L_3;
		L_3 = CLIB_ppf_LaunchFriendRequestFlowResult_GetDidSendRequest_m426F17F796ACB947A2E2BE3787834E3BF2E45E30(L_2, NULL);
		__this->___DidSendRequest_1 = L_3;
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
// System.Void Pico.Platform.Models.UserRoom::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UserRoom__ctor_m3E7FC1E25A29BBC8B65D0404A85D40F8A29023EE (UserRoom_t4A96B7A9523274CA1C6722C4E90D12991C3B11DB* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	intptr_t V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		// public UserRoom(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// User = new User(CLIB.ppf_UserAndRoom_GetUser(o));
		intptr_t L_0 = ___0_o;
		intptr_t L_1;
		L_1 = CLIB_ppf_UserAndRoom_GetUser_m530AD82C352C6974FC63728017898AA4DE1B7B6A(L_0, NULL);
		User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4* L_2 = (User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4*)il2cpp_codegen_object_new(User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		User__ctor_m0A17383A33457E27EB6AD299C81C77AC1802E0D1(L_2, L_1, NULL);
		__this->___User_0 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___User_0), (void*)L_2);
		// var ptr = CLIB.ppf_UserAndRoom_GetRoom(o);
		intptr_t L_3 = ___0_o;
		intptr_t L_4;
		L_4 = CLIB_ppf_UserAndRoom_GetRoom_mA50990611C540C1B797CD00EEB25E5E4EFEABE04(L_3, NULL);
		V_0 = L_4;
		// if (ptr != IntPtr.Zero)
		intptr_t L_5 = V_0;
		intptr_t L_6 = ((IntPtr_t_StaticFields*)il2cpp_codegen_static_fields_for(IntPtr_t_il2cpp_TypeInfo_var))->___Zero_1;
		bool L_7;
		L_7 = IntPtr_op_Inequality_m90EFC9C4CAD9A33E309F2DDF98EE4E1DD253637B(L_5, L_6, NULL);
		if (!L_7)
		{
			goto IL_0037;
		}
	}
	{
		// Room = new Room(ptr);
		intptr_t L_8 = V_0;
		Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135* L_9 = (Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135*)il2cpp_codegen_object_new(Room_tBD64D83E5B1B76A68476651AB2E548F1587A1135_il2cpp_TypeInfo_var);
		NullCheck(L_9);
		Room__ctor_mB6AF794D98BC22F1081870DD63E403520D1172A4(L_9, L_8, NULL);
		__this->___Room_1 = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___Room_1), (void*)L_9);
	}

IL_0037:
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
// System.Void Pico.Platform.Models.UserRoomList::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UserRoomList__ctor_mFFF359CD38182A01E577DA619D6C042F2B0FF55C (UserRoomList_t4AA0685A4D566E046B275555AC21E1A102C16A73* __this, intptr_t ___0_a, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mA524A94B70C813C1BA791AF84F038FC221A00FC8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_set_Capacity_m5DBD95CCEA8193924616281AFF64AA00130E135C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageArray_1__ctor_mAA26037C5A2D6E5B1A17B51AFAA9B774B6089B55_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UserRoom_t4A96B7A9523274CA1C6722C4E90D12991C3B11DB_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		// public UserRoomList(IntPtr a)
		MessageArray_1__ctor_mAA26037C5A2D6E5B1A17B51AFAA9B774B6089B55(__this, MessageArray_1__ctor_mAA26037C5A2D6E5B1A17B51AFAA9B774B6089B55_RuntimeMethod_var);
		// var count = (int) CLIB.ppf_UserAndRoomArray_GetSize(a);
		intptr_t L_0 = ___0_a;
		uintptr_t L_1;
		L_1 = CLIB_ppf_UserAndRoomArray_GetSize_mCB6FEA277D47CA3F634B69E732D83DA24AE0EAD7(L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint32_t L_2;
		L_2 = UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8(L_1, NULL);
		V_0 = L_2;
		// this.Capacity = count;
		int32_t L_3 = V_0;
		List_1_set_Capacity_m5DBD95CCEA8193924616281AFF64AA00130E135C(__this, L_3, List_1_set_Capacity_m5DBD95CCEA8193924616281AFF64AA00130E135C_RuntimeMethod_var);
		// for (int i = 0; i < count; i++)
		V_1 = 0;
		goto IL_0039;
	}

IL_001d:
	{
		// this.Add(new UserRoom(CLIB.ppf_UserAndRoomArray_GetElement(a, (UIntPtr) i)));
		intptr_t L_4 = ___0_a;
		int32_t L_5 = V_1;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_6;
		L_6 = UIntPtr_op_Explicit_mF1E7911DD5AC13B5E59EE8C7903469D12A3861E8(((int64_t)L_5), NULL);
		intptr_t L_7;
		L_7 = CLIB_ppf_UserAndRoomArray_GetElement_mD2CEA492181B39DBD061F31EC3879FF458CD8E4D(L_4, L_6, NULL);
		UserRoom_t4A96B7A9523274CA1C6722C4E90D12991C3B11DB* L_8 = (UserRoom_t4A96B7A9523274CA1C6722C4E90D12991C3B11DB*)il2cpp_codegen_object_new(UserRoom_t4A96B7A9523274CA1C6722C4E90D12991C3B11DB_il2cpp_TypeInfo_var);
		NullCheck(L_8);
		UserRoom__ctor_m3E7FC1E25A29BBC8B65D0404A85D40F8A29023EE(L_8, L_7, NULL);
		List_1_Add_mA524A94B70C813C1BA791AF84F038FC221A00FC8_inline(__this, L_8, List_1_Add_mA524A94B70C813C1BA791AF84F038FC221A00FC8_RuntimeMethod_var);
		// for (int i = 0; i < count; i++)
		int32_t L_9 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0039:
	{
		// for (int i = 0; i < count; i++)
		int32_t L_10 = V_1;
		int32_t L_11 = V_0;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_001d;
		}
	}
	{
		// NextPageParam = CLIB.ppf_UserAndRoomArray_GetNextPageParam(a);
		intptr_t L_12 = ___0_a;
		String_t* L_13;
		L_13 = CLIB_ppf_UserAndRoomArray_GetNextPageParam_mA2D3FE47D469C868C7F452C0E3E0CA8ED3653510(L_12, NULL);
		((MessageArray_1_tBDB39162E4555FCBD64BB106117908AC8831F004*)__this)->___NextPageParam_6 = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((MessageArray_1_tBDB39162E4555FCBD64BB106117908AC8831F004*)__this)->___NextPageParam_6), (void*)L_13);
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
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void Pico.Platform.Models.PermissionResult::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PermissionResult__ctor_mCB821885F8026F74C2180290301E13E52D9F9C15 (PermissionResult_t235EBFBF617C649652D95D6EEB96D6C1E66EE3CF* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIntPtr_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		// public PermissionResult(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// int sz = (int) CLIB.ppf_PermissionResult_GetAuthorizedPermissionsSize(o);
		intptr_t L_0 = ___0_o;
		uintptr_t L_1;
		L_1 = CLIB_ppf_PermissionResult_GetAuthorizedPermissionsSize_m4379AB6D3FB2839EB21C9523AB5F93908E3A7413(L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uint32_t L_2;
		L_2 = UIntPtr_op_Explicit_m7802FC2BA4C3A18601BB8B58ED4708E0F07663E8(L_1, NULL);
		V_0 = L_2;
		// AuthorizedPermissions = new string[sz];
		int32_t L_3 = V_0;
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_4 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)L_3);
		__this->___AuthorizedPermissions_0 = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___AuthorizedPermissions_0), (void*)L_4);
		// for (int i = 0; i < sz; i++)
		V_1 = 0;
		goto IL_003b;
	}

IL_0022:
	{
		// AuthorizedPermissions[i] = CLIB.ppf_PermissionResult_GetAuthorizedPermissions(o, (UIntPtr) i);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_5 = __this->___AuthorizedPermissions_0;
		int32_t L_6 = V_1;
		intptr_t L_7 = ___0_o;
		int32_t L_8 = V_1;
		il2cpp_codegen_runtime_class_init_inline(UIntPtr_t_il2cpp_TypeInfo_var);
		uintptr_t L_9;
		L_9 = UIntPtr_op_Explicit_mF1E7911DD5AC13B5E59EE8C7903469D12A3861E8(((int64_t)L_8), NULL);
		String_t* L_10;
		L_10 = CLIB_ppf_PermissionResult_GetAuthorizedPermissions_mFAA231129FD3E515528A631EE1D69968E581EACB(L_7, L_9, NULL);
		NullCheck(L_5);
		ArrayElementTypeCheck (L_5, L_10);
		(L_5)->SetAt(static_cast<il2cpp_array_size_t>(L_6), (String_t*)L_10);
		// for (int i = 0; i < sz; i++)
		int32_t L_11 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_003b:
	{
		// for (int i = 0; i < sz; i++)
		int32_t L_12 = V_1;
		int32_t L_13 = V_0;
		if ((((int32_t)L_12) < ((int32_t)L_13)))
		{
			goto IL_0022;
		}
	}
	{
		// AccessToken = CLIB.ppf_PermissionResult_GetAccessToken(o);
		intptr_t L_14 = ___0_o;
		String_t* L_15;
		L_15 = CLIB_ppf_PermissionResult_GetAccessToken_mC5F06ECD94631D7386D345B6979FC2F369B8D920(L_14, NULL);
		__this->___AccessToken_1 = L_15;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___AccessToken_1), (void*)L_15);
		// UserID = CLIB.ppf_PermissionResult_GetUserID(o);
		intptr_t L_16 = ___0_o;
		String_t* L_17;
		L_17 = CLIB_ppf_PermissionResult_GetUserID_mA1FDD0446E05016439D2010D77C6A8A067948A69(L_16, NULL);
		__this->___UserID_2 = L_17;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___UserID_2), (void*)L_17);
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
// System.Void Pico.Platform.Models.UserRelationResult::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UserRelationResult__ctor_mF2D858814FEABDB3475A9BF35592D67E4D8C25D8 (UserRelationResult_t4C1646A5BAF0830D84E5A417EAB9BD502A1ACD3D* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Add_m4A0CF999D0DF4986DF249FD0DB95889F2FD423A9_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_m742B839DF18EB8A76B381A28B11F1FAB2FFDC0CC_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	String_t* V_2 = NULL;
	int32_t V_3 = 0;
	{
		// public UserRelationResult(IntPtr o)
		Dictionary_2__ctor_m742B839DF18EB8A76B381A28B11F1FAB2FFDC0CC(__this, Dictionary_2__ctor_m742B839DF18EB8A76B381A28B11F1FAB2FFDC0CC_RuntimeMethod_var);
		// int sz = (int) CLIB.ppf_UserRelationResult_GetRelationsSize(o);
		intptr_t L_0 = ___0_o;
		int32_t L_1;
		L_1 = CLIB_ppf_UserRelationResult_GetRelationsSize_mF8875AAC141FDE96F53DC11824C80F2E1839CC09(L_0, NULL);
		V_0 = L_1;
		// for (int i = 0; i < sz; i++)
		V_1 = 0;
		goto IL_002d;
	}

IL_0011:
	{
		// string userId = CLIB.ppf_UserRelationResult_GetRelationsKey(o, i);
		intptr_t L_2 = ___0_o;
		int32_t L_3 = V_1;
		String_t* L_4;
		L_4 = CLIB_ppf_UserRelationResult_GetRelationsKey_mB73EF1DCBFF1C89887585243DF714E3FA5754125(L_2, L_3, NULL);
		V_2 = L_4;
		// UserRelationType relation = CLIB.ppf_UserRelationResult_GetRelationsValue(o, i);
		intptr_t L_5 = ___0_o;
		int32_t L_6 = V_1;
		int32_t L_7;
		L_7 = CLIB_ppf_UserRelationResult_GetRelationsValue_m0A26F5C1B9E1C97580698AF2E7AD3B613DEB8850(L_5, L_6, NULL);
		V_3 = L_7;
		// Add(userId, relation);
		String_t* L_8 = V_2;
		int32_t L_9 = V_3;
		Dictionary_2_Add_m4A0CF999D0DF4986DF249FD0DB95889F2FD423A9(__this, L_8, L_9, Dictionary_2_Add_m4A0CF999D0DF4986DF249FD0DB95889F2FD423A9_RuntimeMethod_var);
		// for (int i = 0; i < sz; i++)
		int32_t L_10 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_10, 1));
	}

IL_002d:
	{
		// for (int i = 0; i < sz; i++)
		int32_t L_11 = V_1;
		int32_t L_12 = V_0;
		if ((((int32_t)L_11) < ((int32_t)L_12)))
		{
			goto IL_0011;
		}
	}
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
// System.Void Pico.Platform.Models.EntitlementCheckResult::.ctor(System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntitlementCheckResult__ctor_m4945D2A4DFBFE69CB799C0187A598086F20BB81F (EntitlementCheckResult_tDCC132CD30FB7907CB5575B3C629531914BCD061* __this, intptr_t ___0_o, const RuntimeMethod* method) 
{
	{
		// public EntitlementCheckResult(IntPtr o)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// HasEntitlement = CLIB.ppf_EntitlementCheckResult_GetHasEntitlement(o);
		intptr_t L_0 = ___0_o;
		bool L_1;
		L_1 = CLIB_ppf_EntitlementCheckResult_GetHasEntitlement_mE806526F233A0C0C2E5C19CF2B79FBF63A3C8F18(L_0, NULL);
		__this->___HasEntitlement_0 = L_1;
		// StatusCode = CLIB.ppf_EntitlementCheckResult_GetStatusCode(o);
		intptr_t L_2 = ___0_o;
		int32_t L_3;
		L_3 = CLIB_ppf_EntitlementCheckResult_GetStatusCode_m6FC69C3765542D93B42BC88E313E868EBDD49D7B(L_2, NULL);
		__this->___StatusCode_1 = L_3;
		// StatusMessage = CLIB.ppf_EntitlementCheckResult_GetStatusMessage(o);
		intptr_t L_4 = ___0_o;
		String_t* L_5;
		L_5 = CLIB_ppf_EntitlementCheckResult_GetStatusMessage_m83B8F941AE4DF09661F8BC0EED9AD8FD1F09E4BF(L_4, NULL);
		__this->___StatusMessage_2 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___StatusMessage_2), (void*)L_5);
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
// System.Void Pico.Platform.Samples.SimpleDemo::Start()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SimpleDemo_Start_m1F51948771757E048165957CC25FAF1B6985F145 (SimpleDemo_tB73BB92662E2E45C09FAD8C176DC8690E0FD4195* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Handler_t514BEA54A8C9B5734E3D678B336DDA196A366022_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SimpleDemo_U3CStartU3Eb__4_0_m8CEF654CAA456652353B08AD57EF5DACAAAB556D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1_OnComplete_m35202096110B84EDEDE3B5E67432C170C35F885B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral4711236842612E0241200A841882573A4D49C0D3);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* V_0 = NULL;
	UnityException_tA1EC1E95ADE689CF6EB7FAFF77C160AE1F559067* V_1 = NULL;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		// Log($"UseAsyncInit={useAsyncInit}");
		bool L_0 = __this->___useAsyncInit_4;
		bool L_1 = L_0;
		RuntimeObject* L_2 = Box(Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_il2cpp_TypeInfo_var, &L_1);
		String_t* L_3;
		L_3 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(_stringLiteral4711236842612E0241200A841882573A4D49C0D3, L_2, NULL);
		SimpleDemo_Log_m62FA177CD0CF6D603ED9007ECB86EB58799159F0(__this, L_3, NULL);
		// if (useAsyncInit)
		bool L_4 = __this->___useAsyncInit_4;
		if (!L_4)
		{
			goto IL_0051;
		}
	}
	try
	{// begin try (depth: 1)
		// CoreService.AsyncInitialize().OnComplete(m =>
		// {
		//     if (m.IsError)
		//     {
		//         Log($"Async initialize failed: code={m.GetError().Code} message={m.GetError().Message}");
		//         return;
		//     }
		// 
		//     if (m.Data != PlatformInitializeResult.Success && m.Data != PlatformInitializeResult.AlreadyInitialized)
		//     {
		//         Log($"Async initialize failed: result={m.Data}");
		//         return;
		//     }
		// 
		//     Log("AsyncInitialize Successfully");
		//     EnterDemo();
		// });
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		Task_1_t733E89BDEF2E1BD0B822AE037A0F380656723ACE* L_5;
		L_5 = CoreService_AsyncInitialize_m8A638C8765E79B40AA6320F400C97845B73DDD39((String_t*)NULL, NULL);
		Handler_t514BEA54A8C9B5734E3D678B336DDA196A366022* L_6 = (Handler_t514BEA54A8C9B5734E3D678B336DDA196A366022*)il2cpp_codegen_object_new(Handler_t514BEA54A8C9B5734E3D678B336DDA196A366022_il2cpp_TypeInfo_var);
		NullCheck(L_6);
		Handler__ctor_m10B31F3C417FE2E85931E31619351B7403FFA7DA(L_6, __this, (intptr_t)((void*)SimpleDemo_U3CStartU3Eb__4_0_m8CEF654CAA456652353B08AD57EF5DACAAAB556D_RuntimeMethod_var), NULL);
		NullCheck(L_5);
		Task_1_t733E89BDEF2E1BD0B822AE037A0F380656723ACE* L_7;
		L_7 = Task_1_OnComplete_m35202096110B84EDEDE3B5E67432C170C35F885B(L_5, L_6, Task_1_OnComplete_m35202096110B84EDEDE3B5E67432C170C35F885B_RuntimeMethod_var);
		// }
		goto IL_0074;
	}// end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_003d;
		}
		throw e;
	}

CATCH_003d:
	{// begin catch(System.Exception)
		Exception_t* L_8 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		// catch (Exception e)
		V_0 = L_8;
		// Log($"Async Initialize Failed:{e}");
		Exception_t* L_9 = V_0;
		String_t* L_10;
		L_10 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralCD98202A6EC5293093FBD559FA1C99CE6B98344E)), L_9, NULL);
		SimpleDemo_Log_m62FA177CD0CF6D603ED9007ECB86EB58799159F0(__this, L_10, NULL);
		// return;
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0074;
	}// end catch (depth: 1)

IL_0051:
	{
	}
	try
	{// begin try (depth: 1)
		// CoreService.Initialize();
		il2cpp_codegen_runtime_class_init_inline(CoreService_t4DFB7E380E9F9FE1CC69655706D948165B6D7014_il2cpp_TypeInfo_var);
		CoreService_Initialize_m188D60D285D9A378B766140AF97D433B09073039((String_t*)NULL, NULL);
		// }
		goto IL_006e;
	}// end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&UnityException_tA1EC1E95ADE689CF6EB7FAFF77C160AE1F559067_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_005a;
		}
		throw e;
	}

CATCH_005a:
	{// begin catch(UnityEngine.UnityException)
		UnityException_tA1EC1E95ADE689CF6EB7FAFF77C160AE1F559067* L_11 = ((UnityException_tA1EC1E95ADE689CF6EB7FAFF77C160AE1F559067*)IL2CPP_GET_ACTIVE_EXCEPTION(UnityException_tA1EC1E95ADE689CF6EB7FAFF77C160AE1F559067*));;
		// catch (UnityException e)
		V_1 = L_11;
		// Log($"Init Platform SDK error:{e}");
		UnityException_tA1EC1E95ADE689CF6EB7FAFF77C160AE1F559067* L_12 = V_1;
		String_t* L_13;
		L_13 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral89DED4B57F2A5D3967765BE97C28C32EDC26B793)), L_12, NULL);
		SimpleDemo_Log_m62FA177CD0CF6D603ED9007ECB86EB58799159F0(__this, L_13, NULL);
		// throw;
		IL2CPP_RETHROW_MANAGED_EXCEPTION(IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*));
	}// end catch (depth: 1)

IL_006e:
	{
		// EnterDemo();
		SimpleDemo_EnterDemo_mC8D76400FCF45640B119D265459272BCF763B723(__this, NULL);
	}

IL_0074:
	{
		// }
		return;
	}
}
// System.Void Pico.Platform.Samples.SimpleDemo::EnterDemo()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SimpleDemo_EnterDemo_mC8D76400FCF45640B119D265459272BCF763B723 (SimpleDemo_tB73BB92662E2E45C09FAD8C176DC8690E0FD4195* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Handler_tF65149A494CDA59437FE06A5E974BDECEB45C2B3_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SimpleDemo_U3CEnterDemoU3Eb__5_0_m177780F4F6EC2BAF980E03603F1050A5E5940F11_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1_OnComplete_m320B333161C5C0070440A132234F801A7BC74020_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD8D751988DD5B3888B0ACDB2BFE22E5FA8BBBEEC);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF1CAF49A3BB6501D9753F41A12098ECDF0CCE5A4);
		s_Il2CppMethodInitialized = true;
	}
	{
		// UserService.RequestUserPermissions(new[] {Permissions.UserInfo, Permissions.FriendRelation}).OnComplete(m =>
		// {
		//     if (m.IsError)
		//     {
		//         Log($"Permission failed code={m.Error.Code} message={m.Error.Message}");
		//         return;
		//     }
		// 
		//     Log($"RequestUserPermissions successfully:{String.Join(",", m.Data.AuthorizedPermissions)}");
		//     getUser();
		// });
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_0 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)2);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_1 = L_0;
		NullCheck(L_1);
		ArrayElementTypeCheck (L_1, _stringLiteralD8D751988DD5B3888B0ACDB2BFE22E5FA8BBBEEC);
		(L_1)->SetAt(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteralD8D751988DD5B3888B0ACDB2BFE22E5FA8BBBEEC);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_2 = L_1;
		NullCheck(L_2);
		ArrayElementTypeCheck (L_2, _stringLiteralF1CAF49A3BB6501D9753F41A12098ECDF0CCE5A4);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(1), (String_t*)_stringLiteralF1CAF49A3BB6501D9753F41A12098ECDF0CCE5A4);
		Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF* L_3;
		L_3 = UserService_RequestUserPermissions_mFEF7C7A702416B8F5EB7F6543B33A327836C46CF(L_2, NULL);
		Handler_tF65149A494CDA59437FE06A5E974BDECEB45C2B3* L_4 = (Handler_tF65149A494CDA59437FE06A5E974BDECEB45C2B3*)il2cpp_codegen_object_new(Handler_tF65149A494CDA59437FE06A5E974BDECEB45C2B3_il2cpp_TypeInfo_var);
		NullCheck(L_4);
		Handler__ctor_m3A431787B4BF4D615DD543208A4A6FDF86C84855(L_4, __this, (intptr_t)((void*)SimpleDemo_U3CEnterDemoU3Eb__5_0_m177780F4F6EC2BAF980E03603F1050A5E5940F11_RuntimeMethod_var), NULL);
		NullCheck(L_3);
		Task_1_tE3764055BFBB9E941E6BE5F6DF0B487A7B6B9BDF* L_5;
		L_5 = Task_1_OnComplete_m320B333161C5C0070440A132234F801A7BC74020(L_3, L_4, Task_1_OnComplete_m320B333161C5C0070440A132234F801A7BC74020_RuntimeMethod_var);
		// }
		return;
	}
}
// System.Void Pico.Platform.Samples.SimpleDemo::getUser()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SimpleDemo_getUser_m35B04756C5973CB7C1F3F6F98DF3C4F37FB88F56 (SimpleDemo_tB73BB92662E2E45C09FAD8C176DC8690E0FD4195* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Handler_t3014C5064A71B62349A0B6C599C034BA36D6E17E_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SimpleDemo_U3CgetUserU3Eb__6_0_mCC18EBE12D82481458FD41732726F882551508FF_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Task_1_OnComplete_m7241FFC878E940C536582E977114C52EDFE412BE_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// UserService.GetLoggedInUser().OnComplete(m =>
		// {
		//     if (m.IsError)
		//     {
		//         Debug.Log($"GetLoggedInUser failed:code={m.Error.Code} message={m.Error.Message}");
		//         return;
		//     }
		// 
		//     StartCoroutine(DownloadImage(m.Data.ImageUrl, headImage));
		//     nameText.text = m.Data.DisplayName;
		//     Log($"DisplayName={m.Data.DisplayName} UserId={m.Data.ID}");
		// });
		Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42* L_0;
		L_0 = UserService_GetLoggedInUser_mEF12425F8814F7C5E08382C6C5E00CEE18073E8B(NULL);
		Handler_t3014C5064A71B62349A0B6C599C034BA36D6E17E* L_1 = (Handler_t3014C5064A71B62349A0B6C599C034BA36D6E17E*)il2cpp_codegen_object_new(Handler_t3014C5064A71B62349A0B6C599C034BA36D6E17E_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		Handler__ctor_m1E95747E31598AD2B68B9458AB372F09549FDC8D(L_1, __this, (intptr_t)((void*)SimpleDemo_U3CgetUserU3Eb__6_0_mCC18EBE12D82481458FD41732726F882551508FF_RuntimeMethod_var), NULL);
		NullCheck(L_0);
		Task_1_tB52620DC9E610A2CFD02FD23959DC3FB04599E42* L_2;
		L_2 = Task_1_OnComplete_m7241FFC878E940C536582E977114C52EDFE412BE(L_0, L_1, Task_1_OnComplete_m7241FFC878E940C536582E977114C52EDFE412BE_RuntimeMethod_var);
		// }
		return;
	}
}
// System.Collections.IEnumerator Pico.Platform.Samples.SimpleDemo::DownloadImage(System.String,UnityEngine.UI.RawImage)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* SimpleDemo_DownloadImage_m5AD82188A53C0A2A70C567A27C366282FCB09E94 (SimpleDemo_tB73BB92662E2E45C09FAD8C176DC8690E0FD4195* __this, String_t* ___0_mediaUrl, RawImage_tFF12F7DB574FBDC1863CF607C7A12A5D9F8D6179* ___1_rawImage, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CDownloadImageU3Ed__7_t12CD4C58AE44E71AC9B06FF3969E6AD7057D8367_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		U3CDownloadImageU3Ed__7_t12CD4C58AE44E71AC9B06FF3969E6AD7057D8367* L_0 = (U3CDownloadImageU3Ed__7_t12CD4C58AE44E71AC9B06FF3969E6AD7057D8367*)il2cpp_codegen_object_new(U3CDownloadImageU3Ed__7_t12CD4C58AE44E71AC9B06FF3969E6AD7057D8367_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		U3CDownloadImageU3Ed__7__ctor_mD97A09CDDEC301DE3704B12E5D3412B449DF0697(L_0, 0, NULL);
		U3CDownloadImageU3Ed__7_t12CD4C58AE44E71AC9B06FF3969E6AD7057D8367* L_1 = L_0;
		NullCheck(L_1);
		L_1->___U3CU3E4__this_3 = __this;
		Il2CppCodeGenWriteBarrier((void**)(&L_1->___U3CU3E4__this_3), (void*)__this);
		U3CDownloadImageU3Ed__7_t12CD4C58AE44E71AC9B06FF3969E6AD7057D8367* L_2 = L_1;
		String_t* L_3 = ___0_mediaUrl;
		NullCheck(L_2);
		L_2->___mediaUrl_2 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&L_2->___mediaUrl_2), (void*)L_3);
		U3CDownloadImageU3Ed__7_t12CD4C58AE44E71AC9B06FF3969E6AD7057D8367* L_4 = L_2;
		RawImage_tFF12F7DB574FBDC1863CF607C7A12A5D9F8D6179* L_5 = ___1_rawImage;
		NullCheck(L_4);
		L_4->___rawImage_4 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&L_4->___rawImage_4), (void*)L_5);
		return L_4;
	}
}
// System.Void Pico.Platform.Samples.SimpleDemo::Log(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SimpleDemo_Log_m62FA177CD0CF6D603ED9007ECB86EB58799159F0 (SimpleDemo_tB73BB92662E2E45C09FAD8C176DC8690E0FD4195* __this, String_t* ___0_s, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// logText.text = s;
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___logText_7;
		String_t* L_1 = ___0_s;
		NullCheck(L_0);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, L_1);
		// Debug.Log(s);
		String_t* L_2 = ___0_s;
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_Log_m87A9A3C761FF5C43ED8A53B16190A53D08F818BB(L_2, NULL);
		// }
		return;
	}
}
// System.Void Pico.Platform.Samples.SimpleDemo::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SimpleDemo__ctor_m31D25AE403EE0EA1FB17834FF5FD05DEDD702DE1 (SimpleDemo_tB73BB92662E2E45C09FAD8C176DC8690E0FD4195* __this, const RuntimeMethod* method) 
{
	{
		// public bool useAsyncInit = true;
		__this->___useAsyncInit_4 = (bool)1;
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
// System.Void Pico.Platform.Samples.SimpleDemo::<Start>b__4_0(Pico.Platform.Message`1<Pico.Platform.PlatformInitializeResult>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SimpleDemo_U3CStartU3Eb__4_0_m8CEF654CAA456652353B08AD57EF5DACAAAB556D (SimpleDemo_tB73BB92662E2E45C09FAD8C176DC8690E0FD4195* __this, Message_1_t58D0E25C5F7D6B97F64C48CFE6DA11BE5D1A3EF1* ___0_m, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlatformInitializeResult_t24F044FE2324F44AF83DB194C1051EC41F6586C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral17F876F233361D29F71A2CA748E8C6128A4464BE);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2756C3F879AF25F2833BF607BB657D6246B88DF3);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralFFF368B92F042A6F27288FB4036FCD460758F47B);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (m.IsError)
		Message_1_t58D0E25C5F7D6B97F64C48CFE6DA11BE5D1A3EF1* L_0 = ___0_m;
		NullCheck(L_0);
		bool L_1;
		L_1 = Message_get_IsError_m0D80E2415924AE94A030FB3CF345FFB48FE480F9(L_0, NULL);
		if (!L_1)
		{
			goto IL_0034;
		}
	}
	{
		// Log($"Async initialize failed: code={m.GetError().Code} message={m.GetError().Message}");
		Message_1_t58D0E25C5F7D6B97F64C48CFE6DA11BE5D1A3EF1* L_2 = ___0_m;
		NullCheck(L_2);
		Error_t3CA63648FA025A8FBA63EA102526BE2F757CAF88* L_3;
		L_3 = Message_GetError_mF2A3F96565CB80619FBD1DFE8E7C9FB1A0BA5A99_inline(L_2, NULL);
		NullCheck(L_3);
		int32_t L_4 = L_3->___Code_0;
		int32_t L_5 = L_4;
		RuntimeObject* L_6 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_5);
		Message_1_t58D0E25C5F7D6B97F64C48CFE6DA11BE5D1A3EF1* L_7 = ___0_m;
		NullCheck(L_7);
		Error_t3CA63648FA025A8FBA63EA102526BE2F757CAF88* L_8;
		L_8 = Message_GetError_mF2A3F96565CB80619FBD1DFE8E7C9FB1A0BA5A99_inline(L_7, NULL);
		NullCheck(L_8);
		String_t* L_9 = L_8->___Message_1;
		String_t* L_10;
		L_10 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral17F876F233361D29F71A2CA748E8C6128A4464BE, L_6, L_9, NULL);
		SimpleDemo_Log_m62FA177CD0CF6D603ED9007ECB86EB58799159F0(__this, L_10, NULL);
		// return;
		return;
	}

IL_0034:
	{
		// if (m.Data != PlatformInitializeResult.Success && m.Data != PlatformInitializeResult.AlreadyInitialized)
		Message_1_t58D0E25C5F7D6B97F64C48CFE6DA11BE5D1A3EF1* L_11 = ___0_m;
		NullCheck(L_11);
		int32_t L_12 = L_11->___Data_3;
		if (!L_12)
		{
			goto IL_0061;
		}
	}
	{
		Message_1_t58D0E25C5F7D6B97F64C48CFE6DA11BE5D1A3EF1* L_13 = ___0_m;
		NullCheck(L_13);
		int32_t L_14 = L_13->___Data_3;
		if ((((int32_t)L_14) == ((int32_t)(-1))))
		{
			goto IL_0061;
		}
	}
	{
		// Log($"Async initialize failed: result={m.Data}");
		Message_1_t58D0E25C5F7D6B97F64C48CFE6DA11BE5D1A3EF1* L_15 = ___0_m;
		NullCheck(L_15);
		int32_t L_16 = L_15->___Data_3;
		int32_t L_17 = L_16;
		RuntimeObject* L_18 = Box(PlatformInitializeResult_t24F044FE2324F44AF83DB194C1051EC41F6586C5_il2cpp_TypeInfo_var, &L_17);
		String_t* L_19;
		L_19 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(_stringLiteralFFF368B92F042A6F27288FB4036FCD460758F47B, L_18, NULL);
		SimpleDemo_Log_m62FA177CD0CF6D603ED9007ECB86EB58799159F0(__this, L_19, NULL);
		// return;
		return;
	}

IL_0061:
	{
		// Log("AsyncInitialize Successfully");
		SimpleDemo_Log_m62FA177CD0CF6D603ED9007ECB86EB58799159F0(__this, _stringLiteral2756C3F879AF25F2833BF607BB657D6246B88DF3, NULL);
		// EnterDemo();
		SimpleDemo_EnterDemo_mC8D76400FCF45640B119D265459272BCF763B723(__this, NULL);
		// });
		return;
	}
}
// System.Void Pico.Platform.Samples.SimpleDemo::<EnterDemo>b__5_0(Pico.Platform.Message`1<Pico.Platform.Models.PermissionResult>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SimpleDemo_U3CEnterDemoU3Eb__5_0_m177780F4F6EC2BAF980E03603F1050A5E5940F11 (SimpleDemo_tB73BB92662E2E45C09FAD8C176DC8690E0FD4195* __this, Message_1_t457063293F5E86604105C51764B8EB632AA81945* ___0_m, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral4B8EE1D99E55FDC8FBE52391086C2F425F6AA626);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral84D6EACB0A96EDCCCEF46D2C88A45B685E4996E2);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC18C9BB6DF0D5C60CE5A5D2D3D6111BEB6F8CCEB);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (m.IsError)
		Message_1_t457063293F5E86604105C51764B8EB632AA81945* L_0 = ___0_m;
		NullCheck(L_0);
		bool L_1;
		L_1 = Message_get_IsError_m0D80E2415924AE94A030FB3CF345FFB48FE480F9(L_0, NULL);
		if (!L_1)
		{
			goto IL_0034;
		}
	}
	{
		// Log($"Permission failed code={m.Error.Code} message={m.Error.Message}");
		Message_1_t457063293F5E86604105C51764B8EB632AA81945* L_2 = ___0_m;
		NullCheck(L_2);
		Error_t3CA63648FA025A8FBA63EA102526BE2F757CAF88* L_3 = ((Message_t2DF6F94E79BCFC7D36B4D1219F09D5DF8D241F83*)L_2)->___Error_2;
		NullCheck(L_3);
		int32_t L_4 = L_3->___Code_0;
		int32_t L_5 = L_4;
		RuntimeObject* L_6 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_5);
		Message_1_t457063293F5E86604105C51764B8EB632AA81945* L_7 = ___0_m;
		NullCheck(L_7);
		Error_t3CA63648FA025A8FBA63EA102526BE2F757CAF88* L_8 = ((Message_t2DF6F94E79BCFC7D36B4D1219F09D5DF8D241F83*)L_7)->___Error_2;
		NullCheck(L_8);
		String_t* L_9 = L_8->___Message_1;
		String_t* L_10;
		L_10 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral84D6EACB0A96EDCCCEF46D2C88A45B685E4996E2, L_6, L_9, NULL);
		SimpleDemo_Log_m62FA177CD0CF6D603ED9007ECB86EB58799159F0(__this, L_10, NULL);
		// return;
		return;
	}

IL_0034:
	{
		// Log($"RequestUserPermissions successfully:{String.Join(",", m.Data.AuthorizedPermissions)}");
		Message_1_t457063293F5E86604105C51764B8EB632AA81945* L_11 = ___0_m;
		NullCheck(L_11);
		PermissionResult_t235EBFBF617C649652D95D6EEB96D6C1E66EE3CF* L_12 = L_11->___Data_3;
		NullCheck(L_12);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_13 = L_12->___AuthorizedPermissions_0;
		String_t* L_14;
		L_14 = String_Join_m557B6B554B87C1742FA0B128500073B421ED0BFD(_stringLiteralC18C9BB6DF0D5C60CE5A5D2D3D6111BEB6F8CCEB, L_13, NULL);
		String_t* L_15;
		L_15 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral4B8EE1D99E55FDC8FBE52391086C2F425F6AA626, L_14, NULL);
		SimpleDemo_Log_m62FA177CD0CF6D603ED9007ECB86EB58799159F0(__this, L_15, NULL);
		// getUser();
		SimpleDemo_getUser_m35B04756C5973CB7C1F3F6F98DF3C4F37FB88F56(__this, NULL);
		// });
		return;
	}
}
// System.Void Pico.Platform.Samples.SimpleDemo::<getUser>b__6_0(Pico.Platform.Message`1<Pico.Platform.Models.User>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SimpleDemo_U3CgetUserU3Eb__6_0_mCC18EBE12D82481458FD41732726F882551508FF (SimpleDemo_tB73BB92662E2E45C09FAD8C176DC8690E0FD4195* __this, Message_1_tE6876B2F0C46A93682EA4E2DD435A5D3F37E73C2* ___0_m, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral89DB2D99D71D2BFDF5BE40CCB2C9A0F3763DD1A4);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral99A5C4ED7B3FAB6ED3A26CA5392626EAAACE7B0A);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral9F2FC455622BDBE357503CE0FA4CBF83FF54FE04);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (m.IsError)
		Message_1_tE6876B2F0C46A93682EA4E2DD435A5D3F37E73C2* L_0 = ___0_m;
		NullCheck(L_0);
		bool L_1;
		L_1 = Message_get_IsError_m0D80E2415924AE94A030FB3CF345FFB48FE480F9(L_0, NULL);
		if (!L_1)
		{
			goto IL_0033;
		}
	}
	{
		// Debug.Log($"GetLoggedInUser failed:code={m.Error.Code} message={m.Error.Message}");
		Message_1_tE6876B2F0C46A93682EA4E2DD435A5D3F37E73C2* L_2 = ___0_m;
		NullCheck(L_2);
		Error_t3CA63648FA025A8FBA63EA102526BE2F757CAF88* L_3 = ((Message_t2DF6F94E79BCFC7D36B4D1219F09D5DF8D241F83*)L_2)->___Error_2;
		NullCheck(L_3);
		int32_t L_4 = L_3->___Code_0;
		int32_t L_5 = L_4;
		RuntimeObject* L_6 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_5);
		Message_1_tE6876B2F0C46A93682EA4E2DD435A5D3F37E73C2* L_7 = ___0_m;
		NullCheck(L_7);
		Error_t3CA63648FA025A8FBA63EA102526BE2F757CAF88* L_8 = ((Message_t2DF6F94E79BCFC7D36B4D1219F09D5DF8D241F83*)L_7)->___Error_2;
		NullCheck(L_8);
		String_t* L_9 = L_8->___Message_1;
		String_t* L_10;
		L_10 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral89DB2D99D71D2BFDF5BE40CCB2C9A0F3763DD1A4, L_6, L_9, NULL);
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_Log_m87A9A3C761FF5C43ED8A53B16190A53D08F818BB(L_10, NULL);
		// return;
		return;
	}

IL_0033:
	{
		// StartCoroutine(DownloadImage(m.Data.ImageUrl, headImage));
		Message_1_tE6876B2F0C46A93682EA4E2DD435A5D3F37E73C2* L_11 = ___0_m;
		NullCheck(L_11);
		User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4* L_12 = L_11->___Data_3;
		NullCheck(L_12);
		String_t* L_13 = L_12->___ImageUrl_1;
		RawImage_tFF12F7DB574FBDC1863CF607C7A12A5D9F8D6179* L_14 = __this->___headImage_5;
		RuntimeObject* L_15;
		L_15 = SimpleDemo_DownloadImage_m5AD82188A53C0A2A70C567A27C366282FCB09E94(__this, L_13, L_14, NULL);
		Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* L_16;
		L_16 = MonoBehaviour_StartCoroutine_m4CAFF732AA28CD3BDC5363B44A863575530EC812(__this, L_15, NULL);
		// nameText.text = m.Data.DisplayName;
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_17 = __this->___nameText_6;
		Message_1_tE6876B2F0C46A93682EA4E2DD435A5D3F37E73C2* L_18 = ___0_m;
		NullCheck(L_18);
		User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4* L_19 = L_18->___Data_3;
		NullCheck(L_19);
		String_t* L_20 = L_19->___DisplayName_0;
		NullCheck(L_17);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_17, L_20);
		// Log($"DisplayName={m.Data.DisplayName} UserId={m.Data.ID}");
		Message_1_tE6876B2F0C46A93682EA4E2DD435A5D3F37E73C2* L_21 = ___0_m;
		NullCheck(L_21);
		User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4* L_22 = L_21->___Data_3;
		NullCheck(L_22);
		String_t* L_23 = L_22->___DisplayName_0;
		Message_1_tE6876B2F0C46A93682EA4E2DD435A5D3F37E73C2* L_24 = ___0_m;
		NullCheck(L_24);
		User_t37DF053AC9F41CDB2B22463F16BE016A70A2C2A4* L_25 = L_24->___Data_3;
		NullCheck(L_25);
		String_t* L_26 = L_25->___ID_3;
		String_t* L_27;
		L_27 = String_Concat_m093934F71A9B351911EE46311674ED463B180006(_stringLiteral9F2FC455622BDBE357503CE0FA4CBF83FF54FE04, L_23, _stringLiteral99A5C4ED7B3FAB6ED3A26CA5392626EAAACE7B0A, L_26, NULL);
		SimpleDemo_Log_m62FA177CD0CF6D603ED9007ECB86EB58799159F0(__this, L_27, NULL);
		// });
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
// System.Void Pico.Platform.Samples.SimpleDemo/<DownloadImage>d__7::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CDownloadImageU3Ed__7__ctor_mD97A09CDDEC301DE3704B12E5D3412B449DF0697 (U3CDownloadImageU3Ed__7_t12CD4C58AE44E71AC9B06FF3969E6AD7057D8367* __this, int32_t ___0_U3CU3E1__state, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_U3CU3E1__state;
		__this->___U3CU3E1__state_0 = L_0;
		return;
	}
}
// System.Void Pico.Platform.Samples.SimpleDemo/<DownloadImage>d__7::System.IDisposable.Dispose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CDownloadImageU3Ed__7_System_IDisposable_Dispose_m924BDF10FF6EA0A2260AAC1D7D156A39FB62DA72 (U3CDownloadImageU3Ed__7_t12CD4C58AE44E71AC9B06FF3969E6AD7057D8367* __this, const RuntimeMethod* method) 
{
	{
		return;
	}
}
// System.Boolean Pico.Platform.Samples.SimpleDemo/<DownloadImage>d__7::MoveNext()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool U3CDownloadImageU3Ed__7_MoveNext_m491893E0E2E12353D6727EB234F62D66BB9A44C3 (U3CDownloadImageU3Ed__7_t12CD4C58AE44E71AC9B06FF3969E6AD7057D8367* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_mC91ACC92AD57CA6CA00991DAF1DB3830BCE07AF8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DownloadHandlerTexture_t45E2D719000AA1594E648810F0B57A77FA7C568C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCBE3AB8700B962CFC2BA454CED3E5EC7EB5AC5C1);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	SimpleDemo_tB73BB92662E2E45C09FAD8C176DC8690E0FD4195* V_1 = NULL;
	{
		int32_t L_0 = __this->___U3CU3E1__state_0;
		V_0 = L_0;
		SimpleDemo_tB73BB92662E2E45C09FAD8C176DC8690E0FD4195* L_1 = __this->___U3CU3E4__this_3;
		V_1 = L_1;
		int32_t L_2 = V_0;
		if (!L_2)
		{
			goto IL_0017;
		}
	}
	{
		int32_t L_3 = V_0;
		if ((((int32_t)L_3) == ((int32_t)1)))
		{
			goto IL_0049;
		}
	}
	{
		return (bool)0;
	}

IL_0017:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// UnityWebRequest request = UnityWebRequestTexture.GetTexture(mediaUrl);
		String_t* L_4 = __this->___mediaUrl_2;
		UnityWebRequest_t6233B8E22992FC2364A831C1ACB033EF3260C39F* L_5;
		L_5 = UnityWebRequestTexture_GetTexture_mEEC74BBC5190D4012A0B87C5D439AF59E22EF2EF(L_4, NULL);
		__this->___U3CrequestU3E5__2_5 = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CrequestU3E5__2_5), (void*)L_5);
		// yield return request.SendWebRequest();
		UnityWebRequest_t6233B8E22992FC2364A831C1ACB033EF3260C39F* L_6 = __this->___U3CrequestU3E5__2_5;
		NullCheck(L_6);
		UnityWebRequestAsyncOperation_t14BE94558FF3A2CFC2EFBE2511A3A88252042B8C* L_7;
		L_7 = UnityWebRequest_SendWebRequest_mA3CD13983BAA5074A0640EDD661B1E46E6DB6C13(L_6, NULL);
		__this->___U3CU3E2__current_1 = L_7;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CU3E2__current_1), (void*)L_7);
		__this->___U3CU3E1__state_0 = 1;
		return (bool)1;
	}

IL_0049:
	{
		__this->___U3CU3E1__state_0 = (-1);
		// if (request.responseCode != 200)
		UnityWebRequest_t6233B8E22992FC2364A831C1ACB033EF3260C39F* L_8 = __this->___U3CrequestU3E5__2_5;
		NullCheck(L_8);
		int64_t L_9;
		L_9 = UnityWebRequest_get_responseCode_m012C177F61435D5D120A21D7A03FFF7B0F8B904B(L_8, NULL);
		if ((((int64_t)L_9) == ((int64_t)((int64_t)((int32_t)200)))))
		{
			goto IL_0070;
		}
	}
	{
		// Log("Load image failed");
		SimpleDemo_tB73BB92662E2E45C09FAD8C176DC8690E0FD4195* L_10 = V_1;
		NullCheck(L_10);
		SimpleDemo_Log_m62FA177CD0CF6D603ED9007ECB86EB58799159F0(L_10, _stringLiteralCBE3AB8700B962CFC2BA454CED3E5EC7EB5AC5C1, NULL);
		goto IL_00ba;
	}

IL_0070:
	{
		// rawImage.texture = ((DownloadHandlerTexture) request.downloadHandler).texture;
		RawImage_tFF12F7DB574FBDC1863CF607C7A12A5D9F8D6179* L_11 = __this->___rawImage_4;
		UnityWebRequest_t6233B8E22992FC2364A831C1ACB033EF3260C39F* L_12 = __this->___U3CrequestU3E5__2_5;
		NullCheck(L_12);
		DownloadHandler_t1B56C7D3F65D97A1E4B566A14A1E783EA8AE4EBB* L_13;
		L_13 = UnityWebRequest_get_downloadHandler_m1AA91B23D9D594A4F4FE2975FC356C508528F1D5(L_12, NULL);
		NullCheck(((DownloadHandlerTexture_t45E2D719000AA1594E648810F0B57A77FA7C568C*)CastclassSealed((RuntimeObject*)L_13, DownloadHandlerTexture_t45E2D719000AA1594E648810F0B57A77FA7C568C_il2cpp_TypeInfo_var)));
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_14;
		L_14 = DownloadHandlerTexture_get_texture_m170B5539995EB5984E98E426F52983589F7BEB7C(((DownloadHandlerTexture_t45E2D719000AA1594E648810F0B57A77FA7C568C*)CastclassSealed((RuntimeObject*)L_13, DownloadHandlerTexture_t45E2D719000AA1594E648810F0B57A77FA7C568C_il2cpp_TypeInfo_var)), NULL);
		NullCheck(L_11);
		RawImage_set_texture_mC016318C95CC17A826D57DD219DBCB6DFD295C02(L_11, L_14, NULL);
		// rawImage.GetComponent<Renderer>().material.mainTexture = ((DownloadHandlerTexture) request.downloadHandler).texture;
		RawImage_tFF12F7DB574FBDC1863CF607C7A12A5D9F8D6179* L_15 = __this->___rawImage_4;
		NullCheck(L_15);
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_16;
		L_16 = Component_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_mC91ACC92AD57CA6CA00991DAF1DB3830BCE07AF8(L_15, Component_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_mC91ACC92AD57CA6CA00991DAF1DB3830BCE07AF8_RuntimeMethod_var);
		NullCheck(L_16);
		Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* L_17;
		L_17 = Renderer_get_material_m5BA2A00816C4CC66580D4B2E409CF10718C15656(L_16, NULL);
		UnityWebRequest_t6233B8E22992FC2364A831C1ACB033EF3260C39F* L_18 = __this->___U3CrequestU3E5__2_5;
		NullCheck(L_18);
		DownloadHandler_t1B56C7D3F65D97A1E4B566A14A1E783EA8AE4EBB* L_19;
		L_19 = UnityWebRequest_get_downloadHandler_m1AA91B23D9D594A4F4FE2975FC356C508528F1D5(L_18, NULL);
		NullCheck(((DownloadHandlerTexture_t45E2D719000AA1594E648810F0B57A77FA7C568C*)CastclassSealed((RuntimeObject*)L_19, DownloadHandlerTexture_t45E2D719000AA1594E648810F0B57A77FA7C568C_il2cpp_TypeInfo_var)));
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_20;
		L_20 = DownloadHandlerTexture_get_texture_m170B5539995EB5984E98E426F52983589F7BEB7C(((DownloadHandlerTexture_t45E2D719000AA1594E648810F0B57A77FA7C568C*)CastclassSealed((RuntimeObject*)L_19, DownloadHandlerTexture_t45E2D719000AA1594E648810F0B57A77FA7C568C_il2cpp_TypeInfo_var)), NULL);
		NullCheck(L_17);
		Material_set_mainTexture_m389E048BA9C81B603EBF36BD792212B296317AC0(L_17, L_20, NULL);
	}

IL_00ba:
	{
		// }
		return (bool)0;
	}
}
// System.Object Pico.Platform.Samples.SimpleDemo/<DownloadImage>d__7::System.Collections.Generic.IEnumerator<System.Object>.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CDownloadImageU3Ed__7_System_Collections_Generic_IEnumeratorU3CSystem_ObjectU3E_get_Current_m5E9617890DD9C00491F8A23ACF0E6255A1C0A3E4 (U3CDownloadImageU3Ed__7_t12CD4C58AE44E71AC9B06FF3969E6AD7057D8367* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
// System.Void Pico.Platform.Samples.SimpleDemo/<DownloadImage>d__7::System.Collections.IEnumerator.Reset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CDownloadImageU3Ed__7_System_Collections_IEnumerator_Reset_m9518B33BC141B6CA28A96185DC117A0318E13001 (U3CDownloadImageU3Ed__7_t12CD4C58AE44E71AC9B06FF3969E6AD7057D8367* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NullCheck(L_0);
		NotSupportedException__ctor_m1398D0CDE19B36AA3DE9392879738C1EA2439CDF(L_0, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&U3CDownloadImageU3Ed__7_System_Collections_IEnumerator_Reset_m9518B33BC141B6CA28A96185DC117A0318E13001_RuntimeMethod_var)));
	}
}
// System.Object Pico.Platform.Samples.SimpleDemo/<DownloadImage>d__7::System.Collections.IEnumerator.get_Current()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CDownloadImageU3Ed__7_System_Collections_IEnumerator_get_Current_m2965D2A1CE24A0DE24B062109B27D9037F8F4BA0 (U3CDownloadImageU3Ed__7_t12CD4C58AE44E71AC9B06FF3969E6AD7057D8367* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CU3E2__current_1;
		return L_0;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t ProcessAudioFrameFunction_Invoke_m5EC2CDFD611F5CDC64BD8A36A025E8C08FF061D6_inline (ProcessAudioFrameFunction_tA63B392DEA3AFF4C8FD9068F4A056EBB4F21E8A5* __this, RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59* ___0_frame, const RuntimeMethod* method) 
{
	typedef int32_t (*FunctionPointerType) (RuntimeObject*, RtcAudioFrame_t300062CFB69D590AAC05453E8CB2D5F3DDED8B59*, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_frame, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void KVPairArray_set_Size_mEF25D67ACDCEB5A98B41B65D53C7752DCDC51F4C_inline (KVPairArray_t2D18141BDF81CCF74F01AD0CD6D940BFF0D65E1F* __this, uint32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public uint Size { get; private set; }
		uint32_t L_0 = ___0_value;
		__this->___U3CSizeU3Ek__BackingField_0 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Error_t3CA63648FA025A8FBA63EA102526BE2F757CAF88* Message_GetError_mF2A3F96565CB80619FBD1DFE8E7C9FB1A0BA5A99_inline (Message_t2DF6F94E79BCFC7D36B4D1219F09D5DF8D241F83* __this, const RuntimeMethod* method) 
{
	{
		// return Error;
		Error_t3CA63648FA025A8FBA63EA102526BE2F757CAF88* L_0 = __this->___Error_2;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR KeyValuePair_2_t8119C4668B01DE5BDC84EDBA81EE010B6CA16C5C Enumerator_get_Current_m511016491079A010B4344AA4E125147FAF6D679F_gshared_inline (Enumerator_t628F4A89865D78D3344C93277ACECBDE97BE739A* __this, const RuntimeMethod* method) 
{
	{
		KeyValuePair_2_t8119C4668B01DE5BDC84EDBA81EE010B6CA16C5C L_0 = __this->____current_3;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t KeyValuePair_2_get_Key_m380DA6E4F786B9C61012C4427405FC5FD48413A1_gshared_inline (KeyValuePair_2_t8119C4668B01DE5BDC84EDBA81EE010B6CA16C5C* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___key_0;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t KeyValuePair_2_get_Value_m3F5DAA82C39D5EFEAE4B1F8389E1DD38732777CC_gshared_inline (KeyValuePair_2_t8119C4668B01DE5BDC84EDBA81EE010B6CA16C5C* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___value_1;
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
