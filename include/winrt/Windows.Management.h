#pragma once
// generated by isopod tools
// namespaces:
// Windows.Management

#include "Windows.Management.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IVectorView;
template<typename T> struct IIterable;
}}}

// defs

template<> struct def<Windows::Management::MdmAlertMark> : enum_type<int> {};
template<> struct def<Windows::Management::MdmAlertDataType> : enum_type<int> {};
template<> struct def<Windows::Management::IMdmAlert> : interface_type<> {};
template<> struct def<Windows::Management::MdmSessionState> : enum_type<int> {};
template<> struct def<Windows::Management::IMdmSession> : interface_type<> {};
template<> struct def<Windows::Management::MdmAlert> : class_type<Platform::Object, Windows::Management::IMdmAlert> {};
template<> struct def<Windows::Management::IMdmSessionManagerStatics> : interface_type<> {};
template<> struct def<Windows::Management::MdmSession> : class_type<Platform::Object, Windows::Management::IMdmSession> {};
template<> struct def<Windows::Management::MdmSessionManager> : class_type<Platform::Object, Platform::Object> {};

// uuids

template<> struct uuid<Windows::Management::IMdmAlert> { define_guid(0xB0FBC327, 0x28C1, 0x4B52, 0xA5, 0x48, 0xC5, 0x80, 0x7C, 0xAF, 0x70, 0xB6);};
template<> struct uuid<Windows::Management::IMdmSession> { define_guid(0xFE89314C, 0x8F64, 0x4797, 0xA9, 0xD7, 0x9D, 0x88, 0xF8, 0x6A, 0xE1, 0x66);};
template<> struct uuid<Windows::Management::IMdmSessionManagerStatics> { define_guid(0xCF4AD959, 0xF745, 0x4B79, 0x9B, 0x5C, 0xDE, 0xB, 0xF8, 0xEF, 0xE4, 0x4B);};

// types

namespace Windows { namespace Management {

// IMdmAlert
struct IMdmAlert_raw : IInspectable {
	virtual STDMETHODIMP _get_Data(HSTRING *value);
	virtual STDMETHODIMP _put_Data(HSTRING value);
	virtual STDMETHODIMP _get_Format(MdmAlertDataType *value);
	virtual STDMETHODIMP _put_Format(MdmAlertDataType value);
	virtual STDMETHODIMP _get_Mark(MdmAlertMark *value);
	virtual STDMETHODIMP _put_Mark(MdmAlertMark value);
	virtual STDMETHODIMP _get_Source(HSTRING *value);
	virtual STDMETHODIMP _put_Source(HSTRING value);
	virtual STDMETHODIMP _get_Status(unsigned *value);
	virtual STDMETHODIMP _get_Target(HSTRING *value);
	virtual STDMETHODIMP _put_Target(HSTRING value);
	virtual STDMETHODIMP _get_Type(HSTRING *value);
	virtual STDMETHODIMP _put_Type(HSTRING value);
};
template<typename X> struct IMdmAlert_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IMdmAlert_adaptor::Data)->_get_Data(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IMdmAlert_adaptor::Data)->_put_Data(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} Data;
		struct : property {
			MdmAlertDataType get() { MdmAlertDataType value; hrcheck(enc(&IMdmAlert_adaptor::Format)->_get_Format(&value)); return value; }
			MdmAlertDataType operator()() { return get(); }
			operator MdmAlertDataType () { return get(); }
			void put(MdmAlertDataType value) { hrcheck(enc(&IMdmAlert_adaptor::Format)->_put_Format(value)); }
			void operator=(MdmAlertDataType value) { put(value); }
			void operator()(MdmAlertDataType value) { put(value); }
		} Format;
		struct : property {
			MdmAlertMark get() { MdmAlertMark value; hrcheck(enc(&IMdmAlert_adaptor::Mark)->_get_Mark(&value)); return value; }
			MdmAlertMark operator()() { return get(); }
			operator MdmAlertMark () { return get(); }
			void put(MdmAlertMark value) { hrcheck(enc(&IMdmAlert_adaptor::Mark)->_put_Mark(value)); }
			void operator=(MdmAlertMark value) { put(value); }
			void operator()(MdmAlertMark value) { put(value); }
		} Mark;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IMdmAlert_adaptor::Source)->_get_Source(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IMdmAlert_adaptor::Source)->_put_Source(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} Source;
		struct : property {
			unsigned get() { unsigned value; hrcheck(enc(&IMdmAlert_adaptor::Status)->_get_Status(&value)); return value; }
			unsigned operator()() { return get(); }
			operator unsigned () { return get(); }
		} Status;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IMdmAlert_adaptor::Target)->_get_Target(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IMdmAlert_adaptor::Target)->_put_Target(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} Target;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IMdmAlert_adaptor::Type)->_get_Type(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IMdmAlert_adaptor::Type)->_put_Type(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} Type;
	};
	IMdmAlert_adaptor() {}
};
template<typename X> struct adapt<IMdmAlert, X> : Windows::Management::IMdmAlert_adaptor<X> { typedef adapt IMdmAlert; };
struct IMdmAlert : IMdmAlert_raw, generate<IMdmAlert> {};

// IMdmSession
struct IMdmSession_raw : IInspectable {
	virtual STDMETHODIMP _get_Alerts(Foundation::Collections::IVectorView<MdmAlert*>* *value);
	virtual STDMETHODIMP _get_ExtendedError(Foundation::HResult *value);
	virtual STDMETHODIMP _get_Id(HSTRING *value);
	virtual STDMETHODIMP _get_State(MdmSessionState *value);
	virtual STDMETHODIMP _AttachAsync(Foundation::IAsyncAction* *action);
	virtual STDMETHODIMP _Delete();
	virtual STDMETHODIMP _StartAsync(Foundation::IAsyncAction* *action);
	virtual STDMETHODIMP _StartWithAlertsAsync(Foundation::Collections::IIterable<MdmAlert*>* alerts, Foundation::IAsyncAction* *action);
};
template<typename X> struct IMdmSession_adaptor : X {
	union {
		struct : property {
			ptr<Foundation::Collections::IVectorView<ptr<MdmAlert>>> get() { Foundation::Collections::IVectorView<MdmAlert*>* value; hrcheck(enc(&IMdmSession_adaptor::Alerts)->_get_Alerts(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<ptr<MdmAlert>>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<ptr<MdmAlert>>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<ptr<MdmAlert>>> operator->() { return get(); }
		} Alerts;
		struct : property {
			Foundation::HResult get() { Foundation::HResult value; hrcheck(enc(&IMdmSession_adaptor::ExtendedError)->_get_ExtendedError(&value)); return value; }
			Foundation::HResult operator()() { return get(); }
			operator Foundation::HResult () { return get(); }
		} ExtendedError;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IMdmSession_adaptor::Id)->_get_Id(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Id;
		struct : property {
			MdmSessionState get() { MdmSessionState value; hrcheck(enc(&IMdmSession_adaptor::State)->_get_State(&value)); return value; }
			MdmSessionState operator()() { return get(); }
			operator MdmSessionState () { return get(); }
		} State;
	};
	ptr<Foundation::IAsyncAction> AttachAsync() { Foundation::IAsyncAction* action; hrcheck(X::get()->_AttachAsync(&action)); return from_abi(action); }
	void Delete() { hrcheck(X::get()->_Delete()); }
	ptr<Foundation::IAsyncAction> StartAsync() { Foundation::IAsyncAction* action; hrcheck(X::get()->_StartAsync(&action)); return from_abi(action); }
	ptr<Foundation::IAsyncAction> StartAsync(pptr<Foundation::Collections::IIterable<ptr<MdmAlert>>> alerts) { Foundation::IAsyncAction* action; hrcheck(X::get()->_StartWithAlertsAsync(to_abi(alerts), &action)); return from_abi(action); }
	IMdmSession_adaptor() {}
};
template<typename X> struct adapt<IMdmSession, X> : Windows::Management::IMdmSession_adaptor<X> { typedef adapt IMdmSession; };
struct IMdmSession : IMdmSession_raw, generate<IMdmSession> {};

// MdmAlert
template<typename X> struct statics<MdmAlert, X> : X {
	typedef typename X::root_type MdmAlert;
};
struct MdmAlert : generate<MdmAlert> {};

// IMdmSessionManagerStatics
struct IMdmSessionManagerStatics : IInspectable {
	virtual STDMETHODIMP _get_SessionIds(Foundation::Collections::IVectorView<HSTRING>* *value);
	virtual STDMETHODIMP _TryCreateSession(MdmSession* *result);
	virtual STDMETHODIMP _DeleteSessionById(HSTRING sessionId);
	virtual STDMETHODIMP _GetSessionById(HSTRING sessionId, MdmSession* *result);
};

// MdmSession
template<typename X> struct statics<MdmSession, X> : X {
	typedef typename X::root_type MdmSession;
};
struct MdmSession : generate<MdmSession> {
	using IMdmSession::StartAsync;
};

// MdmSessionManager
template<typename> struct MdmSessionManager_statics {
	static struct _SessionIds : property {
		ptr<Foundation::Collections::IVectorView<hstring>> get() { Foundation::Collections::IVectorView<HSTRING>* value; hrcheck(get_activation_factory<MdmSessionManager, IMdmSessionManagerStatics>()->_get_SessionIds(&value)); return from_abi(value); }
		ptr<Foundation::Collections::IVectorView<hstring>> operator()() { return get(); }
		operator ptr<Foundation::Collections::IVectorView<hstring>> () { return get(); }
		ptr<Foundation::Collections::IVectorView<hstring>> operator->() { return get(); }
	} SessionIds;
	static ptr<MdmSession> TryCreateSession() { MdmSession* result; hrcheck(get_activation_factory<MdmSessionManager, IMdmSessionManagerStatics>()->_TryCreateSession(&result)); return from_abi(result); }
	static void DeleteSessionById(hstring_ref sessionId) { hrcheck(get_activation_factory<MdmSessionManager, IMdmSessionManagerStatics>()->_DeleteSessionById(sessionId)); }
	static ptr<MdmSession> GetSessionById(hstring_ref sessionId) { MdmSession* result; hrcheck(get_activation_factory<MdmSessionManager, IMdmSessionManagerStatics>()->_GetSessionById(sessionId, &result)); return from_abi(result); }
};
template<typename X> typename MdmSessionManager_statics<X>::_SessionIds MdmSessionManager_statics<X>::SessionIds;

template<typename X> struct statics<MdmSessionManager, X> : X, Windows::Management::MdmSessionManager_statics<void> {
	typedef typename X::root_type MdmSessionManager;
};
struct MdmSessionManager : generate<MdmSessionManager> {};
}}
} // namespace iso_winrt