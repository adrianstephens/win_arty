#pragma once
// generated by isopod tools
// namespaces:
// Windows.UI.Notifications.Management

#include "Windows.UI.Notifications.Management.0.h"
#include "Windows.UI.Notifications.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IVectorView;
}}}

// defs

template<> struct def<Windows::UI::Notifications::Management::IUserNotificationListenerStatics> : interface_type<> {};
template<> struct def<Windows::UI::Notifications::Management::UserNotificationListenerAccessStatus> : enum_type<int> {};
template<> struct def<Windows::UI::Notifications::Management::IUserNotificationListener> : interface_type<> {};
template<> struct def<Windows::UI::Notifications::Management::UserNotificationListener> : class_type<Platform::Object, Windows::UI::Notifications::Management::IUserNotificationListener> {};

// uuids

template<> struct uuid<Windows::UI::Notifications::Management::IUserNotificationListenerStatics> { define_guid(0xFF6123CF, 0x4386, 0x4AA3, 0xB7, 0x3D, 0xB8, 0x4, 0xE5, 0xB6, 0x3B, 0x23);};
template<> struct uuid<Windows::UI::Notifications::Management::IUserNotificationListener> { define_guid(0x62553E41, 0x8A06, 0x4CEF, 0x82, 0x15, 0x60, 0x33, 0xA5, 0xBE, 0x4B, 0x3);};

// types

namespace Windows { namespace UI { namespace Notifications { namespace Management {

// IUserNotificationListenerStatics
struct IUserNotificationListenerStatics : IInspectable {
	virtual STDMETHODIMP _get_Current(UserNotificationListener* *result);
};

// IUserNotificationListener
struct IUserNotificationListener_raw : IInspectable {
	virtual STDMETHODIMP _RequestAccessAsync(Foundation::IAsyncOperation<UserNotificationListenerAccessStatus>* *result);
	virtual STDMETHODIMP _GetAccessStatus(UserNotificationListenerAccessStatus *accessStatus);
	virtual STDMETHODIMP _add_NotificationChanged(Foundation::TypedEventHandler<UserNotificationListener*, UserNotificationChangedEventArgs*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_NotificationChanged(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _GetNotificationsAsync(NotificationKinds kinds, Foundation::IAsyncOperation<Foundation::Collections::IVectorView<UserNotification*>*>* *result);
	virtual STDMETHODIMP _GetNotification(unsigned notificationId, UserNotification* *result);
	virtual STDMETHODIMP _ClearNotifications();
	virtual STDMETHODIMP _RemoveNotification(unsigned notificationId);
};
template<typename X> struct IUserNotificationListener_adaptor : X {
	union {
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<UserNotificationListener>, ptr<UserNotificationChangedEventArgs>>> handler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IUserNotificationListener_adaptor::NotificationChanged)->_add_NotificationChanged(to_abi(handler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IUserNotificationListener_adaptor::NotificationChanged)->_remove_NotificationChanged(token)); }
		} NotificationChanged;
	};
	ptr<Foundation::IAsyncOperation<UserNotificationListenerAccessStatus>> RequestAccessAsync() { Foundation::IAsyncOperation<UserNotificationListenerAccessStatus>* result; hrcheck(X::get()->_RequestAccessAsync(&result)); return from_abi(result); }
	UserNotificationListenerAccessStatus GetAccessStatus() { UserNotificationListenerAccessStatus accessStatus; hrcheck(X::get()->_GetAccessStatus(&accessStatus)); return accessStatus; }
	ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<ptr<UserNotification>>>>> GetNotificationsAsync(NotificationKinds kinds) { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<UserNotification*>*>* result; hrcheck(X::get()->_GetNotificationsAsync(kinds, &result)); return from_abi(result); }
	ptr<UserNotification> GetNotification(unsigned notificationId) { UserNotification* result; hrcheck(X::get()->_GetNotification(notificationId, &result)); return from_abi(result); }
	void ClearNotifications() { hrcheck(X::get()->_ClearNotifications()); }
	void RemoveNotification(unsigned notificationId) { hrcheck(X::get()->_RemoveNotification(notificationId)); }
	IUserNotificationListener_adaptor() {}
};
template<typename X> struct adapt<IUserNotificationListener, X> : Windows::UI::Notifications::Management::IUserNotificationListener_adaptor<X> { typedef adapt IUserNotificationListener; };
struct IUserNotificationListener : IUserNotificationListener_raw, generate<IUserNotificationListener> {};

// UserNotificationListener
template<typename> struct UserNotificationListener_statics {
	static struct _Current : property {
		ptr<UserNotificationListener> get() { UserNotificationListener* result; hrcheck(get_activation_factory<UserNotificationListener, IUserNotificationListenerStatics>()->_get_Current(&result)); return from_abi(result); }
		ptr<UserNotificationListener> operator()() { return get(); }
		operator ptr<UserNotificationListener> () { return get(); }
		ptr<UserNotificationListener> operator->() { return get(); }
	} Current;
};
template<typename X> typename UserNotificationListener_statics<X>::_Current UserNotificationListener_statics<X>::Current;

template<typename X> struct statics<UserNotificationListener, X> : X, Windows::UI::Notifications::Management::UserNotificationListener_statics<void> {
	typedef typename X::root_type UserNotificationListener;
};
struct UserNotificationListener : generate<UserNotificationListener> {};
}}}}
} // namespace iso_winrt
