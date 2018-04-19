#pragma once
// generated by isopod tools
// namespaces:
// Windows.ApplicationModel.UserActivities.Core

#include "Windows.ApplicationModel.UserActivities.Core.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace ApplicationModel { namespace UserActivities {
struct UserActivityChannel;
struct UserActivity;
struct UserActivitySession;
}}}

// defs

template<> struct def<Windows::ApplicationModel::UserActivities::Core::ICoreUserActivityManagerStatics> : interface_type<> {};
template<> struct def<Windows::ApplicationModel::UserActivities::Core::CoreUserActivityManager> : class_type<Platform::Object, Platform::Object> {};

// uuids

template<> struct uuid<Windows::ApplicationModel::UserActivities::Core::ICoreUserActivityManagerStatics> { define_guid(0xCA3ADB02, 0xA4BE, 0x4D4D, 0xBF, 0xA8, 0x67, 0x95, 0xF4, 0x26, 0x4E, 0xFB);};

// types

namespace Windows { namespace ApplicationModel { namespace UserActivities { namespace Core {

// ICoreUserActivityManagerStatics
struct ICoreUserActivityManagerStatics : IInspectable {
	virtual STDMETHODIMP _CreateUserActivitySessionInBackground(UserActivity* activity, UserActivitySession* *result);
	virtual STDMETHODIMP _DeleteUserActivitySessionsInTimeRangeAsync(UserActivityChannel* channel, Foundation::DateTime startTime, Foundation::DateTime endTime, Foundation::IAsyncAction* *operation);
};

// CoreUserActivityManager
template<typename> struct CoreUserActivityManager_statics {
	static ptr<UserActivitySession> CreateUserActivitySessionInBackground(pptr<UserActivity> activity) { UserActivitySession* result; hrcheck(get_activation_factory<CoreUserActivityManager, ICoreUserActivityManagerStatics>()->_CreateUserActivitySessionInBackground(activity, &result)); return from_abi(result); }
	static ptr<Foundation::IAsyncAction> DeleteUserActivitySessionsInTimeRangeAsync(pptr<UserActivityChannel> channel, const Foundation::DateTime& startTime, const Foundation::DateTime& endTime) { Foundation::IAsyncAction* operation; hrcheck(get_activation_factory<CoreUserActivityManager, ICoreUserActivityManagerStatics>()->_DeleteUserActivitySessionsInTimeRangeAsync(channel, startTime, endTime, &operation)); return from_abi(operation); }
};

template<typename X> struct statics<CoreUserActivityManager, X> : X, Windows::ApplicationModel::UserActivities::Core::CoreUserActivityManager_statics<void> {
	typedef typename X::root_type CoreUserActivityManager;
};
struct CoreUserActivityManager : generate<CoreUserActivityManager> {};
}}}}
} // namespace iso_winrt
