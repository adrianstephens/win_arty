#pragma once
// generated by isopod tools
// namespaces:
// Windows.Web.Http.Filters

#include "Windows.Web.Http.Filters.0.h"
#include "Windows.Networking.Sockets.0.h"
#include "Windows.Security.Cryptography.Certificates.0.h"
#include "Windows.Web.Http.0.h"
#include "Windows.Foundation.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IVector;
template<typename T> struct IVectorView;
}}
namespace Security { namespace Credentials {
struct PasswordCredential;
}}}

// defs

template<> struct def<Windows::Web::Http::Filters::IHttpFilter> : overridable_type<Windows::Foundation::IClosable> {};
template<> struct def<Windows::Web::Http::Filters::HttpCacheReadBehavior> : enum_type<int> {};
template<> struct def<Windows::Web::Http::Filters::HttpCacheWriteBehavior> : enum_type<int> {};
template<> struct def<Windows::Web::Http::Filters::HttpCookieUsageBehavior> : enum_type<int> {};
template<> struct def<Windows::Web::Http::Filters::IHttpCacheControl> : interface_type<> {};
template<> struct def<Windows::Web::Http::Filters::IHttpServerCustomValidationRequestedEventArgs> : interface_type<> {};
template<> struct def<Windows::Web::Http::Filters::IHttpBaseProtocolFilter4> : interface_type<Windows::Web::Http::Filters::IHttpFilter> {};
template<> struct def<Windows::Web::Http::Filters::IHttpBaseProtocolFilter3> : interface_type<Windows::Web::Http::Filters::IHttpFilter> {};
template<> struct def<Windows::Web::Http::Filters::IHttpBaseProtocolFilter2> : interface_type<Windows::Web::Http::Filters::IHttpFilter> {};
template<> struct def<Windows::Web::Http::Filters::IHttpBaseProtocolFilter> : interface_type<Windows::Web::Http::Filters::IHttpFilter> {};
template<> struct def<Windows::Web::Http::Filters::HttpBaseProtocolFilter> : class_type<Platform::Object, Windows::Web::Http::Filters::IHttpBaseProtocolFilter, Windows::Web::Http::Filters::IHttpBaseProtocolFilter4, Windows::Web::Http::Filters::IHttpBaseProtocolFilter3, Windows::Web::Http::Filters::IHttpBaseProtocolFilter2> {};
template<> struct def<Windows::Web::Http::Filters::HttpCacheControl> : class_type<Platform::Object, Windows::Web::Http::Filters::IHttpCacheControl> {};
template<> struct def<Windows::Web::Http::Filters::HttpServerCustomValidationRequestedEventArgs> : class_type<Platform::Object, Windows::Web::Http::Filters::IHttpServerCustomValidationRequestedEventArgs> {};

// uuids

template<> struct uuid<Windows::Web::Http::Filters::IHttpFilter> { define_guid(0xA4CB6DD5, 0x902, 0x439E, 0xBF, 0xD7, 0xE1, 0x25, 0x52, 0xB1, 0x65, 0xCE);};
template<> struct uuid<Windows::Web::Http::Filters::IHttpCacheControl> { define_guid(0xC77E1CB4, 0x3CEA, 0x4EB5, 0xAC, 0x85, 0x4, 0xE1, 0x86, 0xE6, 0x3A, 0xB7);};
template<> struct uuid<Windows::Web::Http::Filters::IHttpServerCustomValidationRequestedEventArgs> { define_guid(0x3165FE32, 0xE7DD, 0x48B7, 0xA3, 0x61, 0x93, 0x9C, 0x75, 0xE, 0x63, 0xCC);};
template<> struct uuid<Windows::Web::Http::Filters::IHttpBaseProtocolFilter4> { define_guid(0x9FE36CCF, 0x2983, 0x4893, 0x94, 0x1F, 0xEB, 0x51, 0x8C, 0xA8, 0xCE, 0xF9);};
template<> struct uuid<Windows::Web::Http::Filters::IHttpBaseProtocolFilter3> { define_guid(0xD43F4D4C, 0xBD42, 0x43AE, 0x87, 0x17, 0xAD, 0x2C, 0x8F, 0x4B, 0x29, 0x37);};
template<> struct uuid<Windows::Web::Http::Filters::IHttpBaseProtocolFilter2> { define_guid(0x2EC30013, 0x9427, 0x4900, 0xA0, 0x17, 0xFA, 0x7D, 0xA3, 0xB5, 0xC9, 0xAE);};
template<> struct uuid<Windows::Web::Http::Filters::IHttpBaseProtocolFilter> { define_guid(0x71C89B09, 0xE131, 0x4B54, 0xA5, 0x3C, 0xEB, 0x43, 0xFF, 0x37, 0xE9, 0xBB);};

// types

namespace Windows { namespace Web { namespace Http { namespace Filters {

// IHttpFilter
struct IHttpFilter_raw : IInspectable {
	virtual STDMETHODIMP _SendRequestAsync(HttpRequestMessage* request, Foundation::IAsyncOperationWithProgress<HttpResponseMessage*, HttpProgress>* *operation) = 0;
};
template<typename X> struct IHttpFilter_adaptor : X {
	ptr<Foundation::IAsyncOperationWithProgress<ptr<HttpResponseMessage>, HttpProgress>> SendRequestAsync(pptr<HttpRequestMessage> request) { Foundation::IAsyncOperationWithProgress<HttpResponseMessage*, HttpProgress>* operation; hrcheck(X::get()->_SendRequestAsync(request, &operation)); return from_abi(operation); }
};
template<typename X> struct adapt<IHttpFilter, X> : Windows::Web::Http::Filters::IHttpFilter_adaptor<X> { typedef adapt IHttpFilter; };
template<typename X> struct IHttpFilter_unadaptor : X {
	STDMETHODIMP _SendRequestAsync(HttpRequestMessage* request, Foundation::IAsyncOperationWithProgress<HttpResponseMessage*, HttpProgress>* *operation) { return hrtry([&, this] { *operation = to_abi(X::get()->SendRequestAsync(request)); }); }
};
template<typename X> struct unadapt<IHttpFilter, X> : Windows::Web::Http::Filters::IHttpFilter_unadaptor<X> {};
struct IHttpFilter : IHttpFilter_raw, generate<IHttpFilter> {};

// IHttpCacheControl
struct IHttpCacheControl_raw : IInspectable {
	virtual STDMETHODIMP _get_ReadBehavior(HttpCacheReadBehavior *value);
	virtual STDMETHODIMP _put_ReadBehavior(HttpCacheReadBehavior value);
	virtual STDMETHODIMP _get_WriteBehavior(HttpCacheWriteBehavior *value);
	virtual STDMETHODIMP _put_WriteBehavior(HttpCacheWriteBehavior value);
};
template<typename X> struct IHttpCacheControl_adaptor : X {
	union {
		struct : property {
			HttpCacheReadBehavior get() { HttpCacheReadBehavior value; hrcheck(enc(&IHttpCacheControl_adaptor::ReadBehavior)->_get_ReadBehavior(&value)); return value; }
			HttpCacheReadBehavior operator()() { return get(); }
			operator HttpCacheReadBehavior () { return get(); }
			void put(HttpCacheReadBehavior value) { hrcheck(enc(&IHttpCacheControl_adaptor::ReadBehavior)->_put_ReadBehavior(value)); }
			void operator=(HttpCacheReadBehavior value) { put(value); }
			void operator()(HttpCacheReadBehavior value) { put(value); }
		} ReadBehavior;
		struct : property {
			HttpCacheWriteBehavior get() { HttpCacheWriteBehavior value; hrcheck(enc(&IHttpCacheControl_adaptor::WriteBehavior)->_get_WriteBehavior(&value)); return value; }
			HttpCacheWriteBehavior operator()() { return get(); }
			operator HttpCacheWriteBehavior () { return get(); }
			void put(HttpCacheWriteBehavior value) { hrcheck(enc(&IHttpCacheControl_adaptor::WriteBehavior)->_put_WriteBehavior(value)); }
			void operator=(HttpCacheWriteBehavior value) { put(value); }
			void operator()(HttpCacheWriteBehavior value) { put(value); }
		} WriteBehavior;
	};
	IHttpCacheControl_adaptor() {}
};
template<typename X> struct adapt<IHttpCacheControl, X> : Windows::Web::Http::Filters::IHttpCacheControl_adaptor<X> { typedef adapt IHttpCacheControl; };
struct IHttpCacheControl : IHttpCacheControl_raw, generate<IHttpCacheControl> {};

// IHttpServerCustomValidationRequestedEventArgs
struct IHttpServerCustomValidationRequestedEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_RequestMessage(HttpRequestMessage* *value);
	virtual STDMETHODIMP _get_ServerCertificate(Security::Cryptography::Certificates::Certificate* *value);
	virtual STDMETHODIMP _get_ServerCertificateErrorSeverity(Networking::Sockets::SocketSslErrorSeverity *value);
	virtual STDMETHODIMP _get_ServerCertificateErrors(Foundation::Collections::IVectorView<Security::Cryptography::Certificates::ChainValidationResult>* *value);
	virtual STDMETHODIMP _get_ServerIntermediateCertificates(Foundation::Collections::IVectorView<Security::Cryptography::Certificates::Certificate*>* *value);
	virtual STDMETHODIMP _Reject();
	virtual STDMETHODIMP _GetDeferral(Foundation::Deferral* *result);
};
template<typename X> struct IHttpServerCustomValidationRequestedEventArgs_adaptor : X {
	union {
		struct : property {
			ptr<HttpRequestMessage> get() { HttpRequestMessage* value; hrcheck(enc(&IHttpServerCustomValidationRequestedEventArgs_adaptor::RequestMessage)->_get_RequestMessage(&value)); return from_abi(value); }
			ptr<HttpRequestMessage> operator()() { return get(); }
			operator ptr<HttpRequestMessage> () { return get(); }
			ptr<HttpRequestMessage> operator->() { return get(); }
		} RequestMessage;
		struct : property {
			ptr<Security::Cryptography::Certificates::Certificate> get() { Security::Cryptography::Certificates::Certificate* value; hrcheck(enc(&IHttpServerCustomValidationRequestedEventArgs_adaptor::ServerCertificate)->_get_ServerCertificate(&value)); return from_abi(value); }
			ptr<Security::Cryptography::Certificates::Certificate> operator()() { return get(); }
			operator ptr<Security::Cryptography::Certificates::Certificate> () { return get(); }
			ptr<Security::Cryptography::Certificates::Certificate> operator->() { return get(); }
		} ServerCertificate;
		struct : property {
			Networking::Sockets::SocketSslErrorSeverity get() { Networking::Sockets::SocketSslErrorSeverity value; hrcheck(enc(&IHttpServerCustomValidationRequestedEventArgs_adaptor::ServerCertificateErrorSeverity)->_get_ServerCertificateErrorSeverity(&value)); return value; }
			Networking::Sockets::SocketSslErrorSeverity operator()() { return get(); }
			operator Networking::Sockets::SocketSslErrorSeverity () { return get(); }
		} ServerCertificateErrorSeverity;
		struct : property {
			ptr<Foundation::Collections::IVectorView<Security::Cryptography::Certificates::ChainValidationResult>> get() { Foundation::Collections::IVectorView<Security::Cryptography::Certificates::ChainValidationResult>* value; hrcheck(enc(&IHttpServerCustomValidationRequestedEventArgs_adaptor::ServerCertificateErrors)->_get_ServerCertificateErrors(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<Security::Cryptography::Certificates::ChainValidationResult>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<Security::Cryptography::Certificates::ChainValidationResult>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<Security::Cryptography::Certificates::ChainValidationResult>> operator->() { return get(); }
		} ServerCertificateErrors;
		struct : property {
			ptr<Foundation::Collections::IVectorView<ptr<Security::Cryptography::Certificates::Certificate>>> get() { Foundation::Collections::IVectorView<Security::Cryptography::Certificates::Certificate*>* value; hrcheck(enc(&IHttpServerCustomValidationRequestedEventArgs_adaptor::ServerIntermediateCertificates)->_get_ServerIntermediateCertificates(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<ptr<Security::Cryptography::Certificates::Certificate>>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<ptr<Security::Cryptography::Certificates::Certificate>>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<ptr<Security::Cryptography::Certificates::Certificate>>> operator->() { return get(); }
		} ServerIntermediateCertificates;
	};
	void Reject() { hrcheck(X::get()->_Reject()); }
	ptr<Foundation::Deferral> GetDeferral() { Foundation::Deferral* result; hrcheck(X::get()->_GetDeferral(&result)); return from_abi(result); }
	IHttpServerCustomValidationRequestedEventArgs_adaptor() {}
};
template<typename X> struct adapt<IHttpServerCustomValidationRequestedEventArgs, X> : Windows::Web::Http::Filters::IHttpServerCustomValidationRequestedEventArgs_adaptor<X> { typedef adapt IHttpServerCustomValidationRequestedEventArgs; };
struct IHttpServerCustomValidationRequestedEventArgs : IHttpServerCustomValidationRequestedEventArgs_raw, generate<IHttpServerCustomValidationRequestedEventArgs> {};

// IHttpBaseProtocolFilter4
struct IHttpBaseProtocolFilter4_raw : IInspectable {
	virtual STDMETHODIMP _add_ServerCustomValidationRequested(Foundation::TypedEventHandler<HttpBaseProtocolFilter*, HttpServerCustomValidationRequestedEventArgs*>* eventHandler, Foundation::EventRegistrationToken *eventCookie);
	virtual STDMETHODIMP _remove_ServerCustomValidationRequested(Foundation::EventRegistrationToken eventCookie);
	virtual STDMETHODIMP _ClearAuthenticationCache();
};
template<typename X> struct IHttpBaseProtocolFilter4_adaptor : X {
	union {
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<HttpBaseProtocolFilter>, ptr<HttpServerCustomValidationRequestedEventArgs>>> eventHandler) { Foundation::EventRegistrationToken eventCookie; hrcheck(enc(&IHttpBaseProtocolFilter4_adaptor::ServerCustomValidationRequested)->_add_ServerCustomValidationRequested(to_abi(eventHandler), &eventCookie)); return eventCookie; }
			void operator-=(const Foundation::EventRegistrationToken& eventCookie) { hrcheck(enc(&IHttpBaseProtocolFilter4_adaptor::ServerCustomValidationRequested)->_remove_ServerCustomValidationRequested(eventCookie)); }
		} ServerCustomValidationRequested;
	};
	void ClearAuthenticationCache() { hrcheck(X::get()->_ClearAuthenticationCache()); }
	IHttpBaseProtocolFilter4_adaptor() {}
};
template<typename X> struct adapt<IHttpBaseProtocolFilter4, X> : Windows::Web::Http::Filters::IHttpBaseProtocolFilter4_adaptor<X> { typedef adapt IHttpBaseProtocolFilter4; };
struct IHttpBaseProtocolFilter4 : IHttpBaseProtocolFilter4_raw, generate<IHttpBaseProtocolFilter4> {};

// IHttpBaseProtocolFilter3
struct IHttpBaseProtocolFilter3_raw : IInspectable {
	virtual STDMETHODIMP _get_CookieUsageBehavior(HttpCookieUsageBehavior *value);
	virtual STDMETHODIMP _put_CookieUsageBehavior(HttpCookieUsageBehavior value);
};
template<typename X> struct IHttpBaseProtocolFilter3_adaptor : X {
	union {
		struct : property {
			HttpCookieUsageBehavior get() { HttpCookieUsageBehavior value; hrcheck(enc(&IHttpBaseProtocolFilter3_adaptor::CookieUsageBehavior)->_get_CookieUsageBehavior(&value)); return value; }
			HttpCookieUsageBehavior operator()() { return get(); }
			operator HttpCookieUsageBehavior () { return get(); }
			void put(HttpCookieUsageBehavior value) { hrcheck(enc(&IHttpBaseProtocolFilter3_adaptor::CookieUsageBehavior)->_put_CookieUsageBehavior(value)); }
			void operator=(HttpCookieUsageBehavior value) { put(value); }
			void operator()(HttpCookieUsageBehavior value) { put(value); }
		} CookieUsageBehavior;
	};
	IHttpBaseProtocolFilter3_adaptor() {}
};
template<typename X> struct adapt<IHttpBaseProtocolFilter3, X> : Windows::Web::Http::Filters::IHttpBaseProtocolFilter3_adaptor<X> { typedef adapt IHttpBaseProtocolFilter3; };
struct IHttpBaseProtocolFilter3 : IHttpBaseProtocolFilter3_raw, generate<IHttpBaseProtocolFilter3> {};

// IHttpBaseProtocolFilter2
struct IHttpBaseProtocolFilter2_raw : IInspectable {
	virtual STDMETHODIMP _get_MaxVersion(HttpVersion *value);
	virtual STDMETHODIMP _put_MaxVersion(HttpVersion value);
};
template<typename X> struct IHttpBaseProtocolFilter2_adaptor : X {
	union {
		struct : property {
			HttpVersion get() { HttpVersion value; hrcheck(enc(&IHttpBaseProtocolFilter2_adaptor::MaxVersion)->_get_MaxVersion(&value)); return value; }
			HttpVersion operator()() { return get(); }
			operator HttpVersion () { return get(); }
			void put(HttpVersion value) { hrcheck(enc(&IHttpBaseProtocolFilter2_adaptor::MaxVersion)->_put_MaxVersion(value)); }
			void operator=(HttpVersion value) { put(value); }
			void operator()(HttpVersion value) { put(value); }
		} MaxVersion;
	};
	IHttpBaseProtocolFilter2_adaptor() {}
};
template<typename X> struct adapt<IHttpBaseProtocolFilter2, X> : Windows::Web::Http::Filters::IHttpBaseProtocolFilter2_adaptor<X> { typedef adapt IHttpBaseProtocolFilter2; };
struct IHttpBaseProtocolFilter2 : IHttpBaseProtocolFilter2_raw, generate<IHttpBaseProtocolFilter2> {};

// IHttpBaseProtocolFilter
struct IHttpBaseProtocolFilter_raw : IInspectable {
	virtual STDMETHODIMP _get_AllowAutoRedirect(bool *value);
	virtual STDMETHODIMP _put_AllowAutoRedirect(bool value);
	virtual STDMETHODIMP _get_AllowUI(bool *value);
	virtual STDMETHODIMP _put_AllowUI(bool value);
	virtual STDMETHODIMP _get_AutomaticDecompression(bool *value);
	virtual STDMETHODIMP _put_AutomaticDecompression(bool value);
	virtual STDMETHODIMP _get_CacheControl(HttpCacheControl* *value);
	virtual STDMETHODIMP _get_CookieManager(HttpCookieManager* *value);
	virtual STDMETHODIMP _get_ClientCertificate(Security::Cryptography::Certificates::Certificate* *value);
	virtual STDMETHODIMP _put_ClientCertificate(Security::Cryptography::Certificates::Certificate* value);
	virtual STDMETHODIMP _get_IgnorableServerCertificateErrors(Foundation::Collections::IVector<Security::Cryptography::Certificates::ChainValidationResult>* *value);
	virtual STDMETHODIMP _get_MaxConnectionsPerServer(unsigned *value);
	virtual STDMETHODIMP _put_MaxConnectionsPerServer(unsigned value);
	virtual STDMETHODIMP _get_ProxyCredential(Security::Credentials::PasswordCredential* *value);
	virtual STDMETHODIMP _put_ProxyCredential(Security::Credentials::PasswordCredential* value);
	virtual STDMETHODIMP _get_ServerCredential(Security::Credentials::PasswordCredential* *value);
	virtual STDMETHODIMP _put_ServerCredential(Security::Credentials::PasswordCredential* value);
	virtual STDMETHODIMP _get_UseProxy(bool *value);
	virtual STDMETHODIMP _put_UseProxy(bool value);
};
template<typename X> struct IHttpBaseProtocolFilter_adaptor : X {
	union {
		struct : property {
			bool get() { bool value; hrcheck(enc(&IHttpBaseProtocolFilter_adaptor::AllowAutoRedirect)->_get_AllowAutoRedirect(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&IHttpBaseProtocolFilter_adaptor::AllowAutoRedirect)->_put_AllowAutoRedirect(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} AllowAutoRedirect;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IHttpBaseProtocolFilter_adaptor::AllowUI)->_get_AllowUI(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&IHttpBaseProtocolFilter_adaptor::AllowUI)->_put_AllowUI(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} AllowUI;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IHttpBaseProtocolFilter_adaptor::AutomaticDecompression)->_get_AutomaticDecompression(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&IHttpBaseProtocolFilter_adaptor::AutomaticDecompression)->_put_AutomaticDecompression(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} AutomaticDecompression;
		struct : property {
			ptr<HttpCacheControl> get() { HttpCacheControl* value; hrcheck(enc(&IHttpBaseProtocolFilter_adaptor::CacheControl)->_get_CacheControl(&value)); return from_abi(value); }
			ptr<HttpCacheControl> operator()() { return get(); }
			operator ptr<HttpCacheControl> () { return get(); }
			ptr<HttpCacheControl> operator->() { return get(); }
		} CacheControl;
		struct : property {
			ptr<Security::Cryptography::Certificates::Certificate> get() { Security::Cryptography::Certificates::Certificate* value; hrcheck(enc(&IHttpBaseProtocolFilter_adaptor::ClientCertificate)->_get_ClientCertificate(&value)); return from_abi(value); }
			ptr<Security::Cryptography::Certificates::Certificate> operator()() { return get(); }
			operator ptr<Security::Cryptography::Certificates::Certificate> () { return get(); }
			ptr<Security::Cryptography::Certificates::Certificate> operator->() { return get(); }
			void put(pptr<Security::Cryptography::Certificates::Certificate> value) { hrcheck(enc(&IHttpBaseProtocolFilter_adaptor::ClientCertificate)->_put_ClientCertificate(value)); }
			void operator=(pptr<Security::Cryptography::Certificates::Certificate> value) { put(value); }
			void operator()(pptr<Security::Cryptography::Certificates::Certificate> value) { put(value); }
		} ClientCertificate;
		struct : property {
			ptr<HttpCookieManager> get() { HttpCookieManager* value; hrcheck(enc(&IHttpBaseProtocolFilter_adaptor::CookieManager)->_get_CookieManager(&value)); return from_abi(value); }
			ptr<HttpCookieManager> operator()() { return get(); }
			operator ptr<HttpCookieManager> () { return get(); }
			ptr<HttpCookieManager> operator->() { return get(); }
		} CookieManager;
		struct : property {
			ptr<Foundation::Collections::IVector<Security::Cryptography::Certificates::ChainValidationResult>> get() { Foundation::Collections::IVector<Security::Cryptography::Certificates::ChainValidationResult>* value; hrcheck(enc(&IHttpBaseProtocolFilter_adaptor::IgnorableServerCertificateErrors)->_get_IgnorableServerCertificateErrors(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVector<Security::Cryptography::Certificates::ChainValidationResult>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVector<Security::Cryptography::Certificates::ChainValidationResult>> () { return get(); }
			ptr<Foundation::Collections::IVector<Security::Cryptography::Certificates::ChainValidationResult>> operator->() { return get(); }
		} IgnorableServerCertificateErrors;
		struct : property {
			unsigned get() { unsigned value; hrcheck(enc(&IHttpBaseProtocolFilter_adaptor::MaxConnectionsPerServer)->_get_MaxConnectionsPerServer(&value)); return value; }
			unsigned operator()() { return get(); }
			operator unsigned () { return get(); }
			void put(unsigned value) { hrcheck(enc(&IHttpBaseProtocolFilter_adaptor::MaxConnectionsPerServer)->_put_MaxConnectionsPerServer(value)); }
			void operator=(unsigned value) { put(value); }
			void operator()(unsigned value) { put(value); }
		} MaxConnectionsPerServer;
		struct : property {
			ptr<Security::Credentials::PasswordCredential> get() { Security::Credentials::PasswordCredential* value; hrcheck(enc(&IHttpBaseProtocolFilter_adaptor::ProxyCredential)->_get_ProxyCredential(&value)); return from_abi(value); }
			ptr<Security::Credentials::PasswordCredential> operator()() { return get(); }
			operator ptr<Security::Credentials::PasswordCredential> () { return get(); }
			ptr<Security::Credentials::PasswordCredential> operator->() { return get(); }
			void put(pptr<Security::Credentials::PasswordCredential> value) { hrcheck(enc(&IHttpBaseProtocolFilter_adaptor::ProxyCredential)->_put_ProxyCredential(value)); }
			void operator=(pptr<Security::Credentials::PasswordCredential> value) { put(value); }
			void operator()(pptr<Security::Credentials::PasswordCredential> value) { put(value); }
		} ProxyCredential;
		struct : property {
			ptr<Security::Credentials::PasswordCredential> get() { Security::Credentials::PasswordCredential* value; hrcheck(enc(&IHttpBaseProtocolFilter_adaptor::ServerCredential)->_get_ServerCredential(&value)); return from_abi(value); }
			ptr<Security::Credentials::PasswordCredential> operator()() { return get(); }
			operator ptr<Security::Credentials::PasswordCredential> () { return get(); }
			ptr<Security::Credentials::PasswordCredential> operator->() { return get(); }
			void put(pptr<Security::Credentials::PasswordCredential> value) { hrcheck(enc(&IHttpBaseProtocolFilter_adaptor::ServerCredential)->_put_ServerCredential(value)); }
			void operator=(pptr<Security::Credentials::PasswordCredential> value) { put(value); }
			void operator()(pptr<Security::Credentials::PasswordCredential> value) { put(value); }
		} ServerCredential;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IHttpBaseProtocolFilter_adaptor::UseProxy)->_get_UseProxy(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&IHttpBaseProtocolFilter_adaptor::UseProxy)->_put_UseProxy(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} UseProxy;
	};
	IHttpBaseProtocolFilter_adaptor() {}
};
template<typename X> struct adapt<IHttpBaseProtocolFilter, X> : Windows::Web::Http::Filters::IHttpBaseProtocolFilter_adaptor<X> { typedef adapt IHttpBaseProtocolFilter; };
struct IHttpBaseProtocolFilter : IHttpBaseProtocolFilter_raw, generate<IHttpBaseProtocolFilter> {};

// HttpBaseProtocolFilter
template<typename X> struct statics<HttpBaseProtocolFilter, X> : X {
	typedef typename X::root_type HttpBaseProtocolFilter;
};
struct HttpBaseProtocolFilter : generate<HttpBaseProtocolFilter> {};

// HttpCacheControl
template<typename X> struct statics<HttpCacheControl, X> : X {
	typedef typename X::root_type HttpCacheControl;
};
struct HttpCacheControl : generate<HttpCacheControl> {};

// HttpServerCustomValidationRequestedEventArgs
template<typename X> struct statics<HttpServerCustomValidationRequestedEventArgs, X> : X {
	typedef typename X::root_type HttpServerCustomValidationRequestedEventArgs;
};
struct HttpServerCustomValidationRequestedEventArgs : generate<HttpServerCustomValidationRequestedEventArgs> {};
}}}}
} // namespace iso_winrt
