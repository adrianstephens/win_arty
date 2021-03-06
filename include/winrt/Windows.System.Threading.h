#pragma once
// generated by isopod tools
// namespaces:
// Windows.System.Threading

#include "Windows.System.Threading.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types


// defs

template<> struct def<Windows::System::Threading::WorkItemPriority> : enum_type<int> {};
template<> struct def<Windows::System::Threading::WorkItemOptions> : enum_type<unsigned> {};
template<> struct def<Windows::System::Threading::TimerElapsedHandler> : delegate_type {};
template<> struct def<Windows::System::Threading::IThreadPoolTimerStatics> : interface_type<> {};
template<> struct def<Windows::System::Threading::IThreadPoolTimer> : interface_type<> {};
template<> struct def<Windows::System::Threading::ThreadPoolTimer> : class_type<Platform::Object, Windows::System::Threading::IThreadPoolTimer> {};
template<> struct def<Windows::System::Threading::TimerDestroyedHandler> : delegate_type {};
template<> struct def<Windows::System::Threading::WorkItemHandler> : delegate_type {};
template<> struct def<Windows::System::Threading::IThreadPoolStatics> : interface_type<> {};
template<> struct def<Windows::System::Threading::ThreadPool> : class_type<Platform::Object, Platform::Object> {};

// uuids

template<> struct uuid<Windows::System::Threading::TimerElapsedHandler> { define_guid(0xFAAEA667, 0xFBEB, 0x49CB, 0xAD, 0xB2, 0x71, 0x18, 0x4C, 0x55, 0x6E, 0x43);};
template<> struct uuid<Windows::System::Threading::IThreadPoolTimerStatics> { define_guid(0x1A8A9D02, 0xE482, 0x461B, 0xB8, 0xC7, 0x8E, 0xFA, 0xD1, 0xCC, 0xE5, 0x90);};
template<> struct uuid<Windows::System::Threading::IThreadPoolTimer> { define_guid(0x594EBE78, 0x55EA, 0x4A88, 0xA5, 0xD, 0x34, 0x2, 0xAE, 0x1F, 0x9C, 0xF2);};
template<> struct uuid<Windows::System::Threading::TimerDestroyedHandler> { define_guid(0x34ED19FA, 0x8384, 0x4EB9, 0x82, 0x9, 0xFB, 0x50, 0x94, 0xEE, 0xEC, 0x35);};
template<> struct uuid<Windows::System::Threading::WorkItemHandler> { define_guid(0x1D1A8B8B, 0xFA66, 0x414F, 0x9C, 0xBD, 0xB6, 0x5F, 0xC9, 0x9D, 0x17, 0xFA);};
template<> struct uuid<Windows::System::Threading::IThreadPoolStatics> { define_guid(0xB6BF67DD, 0x84BD, 0x44F8, 0xAC, 0x1C, 0x93, 0xEB, 0xCB, 0x9D, 0xBA, 0x91);};

// types

namespace Windows { namespace System { namespace Threading {

// TimerElapsedHandler
struct TimerElapsedHandler : IUnknown {
	virtual STDMETHODIMP _Invoke(ThreadPoolTimer* timer) = 0;
};

// IThreadPoolTimerStatics
struct IThreadPoolTimerStatics : IInspectable {
	virtual STDMETHODIMP _CreatePeriodicTimer(TimerElapsedHandler* handler, Foundation::TimeSpan period, ThreadPoolTimer* *timer);
	virtual STDMETHODIMP _CreateTimer(TimerElapsedHandler* handler, Foundation::TimeSpan delay, ThreadPoolTimer* *timer);
	virtual STDMETHODIMP _CreatePeriodicTimerWithCompletion(TimerElapsedHandler* handler, Foundation::TimeSpan period, TimerDestroyedHandler* destroyed, ThreadPoolTimer* *timer);
	virtual STDMETHODIMP _CreateTimerWithCompletion(TimerElapsedHandler* handler, Foundation::TimeSpan delay, TimerDestroyedHandler* destroyed, ThreadPoolTimer* *timer);
};

// IThreadPoolTimer
struct IThreadPoolTimer_raw : IInspectable {
	virtual STDMETHODIMP _get_Period(Foundation::TimeSpan *value);
	virtual STDMETHODIMP _get_Delay(Foundation::TimeSpan *value);
	virtual STDMETHODIMP _Cancel();
};
template<typename X> struct IThreadPoolTimer_adaptor : X {
	union {
		struct : property {
			Foundation::TimeSpan get() { Foundation::TimeSpan value; hrcheck(enc(&IThreadPoolTimer_adaptor::Delay)->_get_Delay(&value)); return value; }
			Foundation::TimeSpan operator()() { return get(); }
			operator Foundation::TimeSpan () { return get(); }
		} Delay;
		struct : property {
			Foundation::TimeSpan get() { Foundation::TimeSpan value; hrcheck(enc(&IThreadPoolTimer_adaptor::Period)->_get_Period(&value)); return value; }
			Foundation::TimeSpan operator()() { return get(); }
			operator Foundation::TimeSpan () { return get(); }
		} Period;
	};
	void Cancel() { hrcheck(X::get()->_Cancel()); }
	IThreadPoolTimer_adaptor() {}
};
template<typename X> struct adapt<IThreadPoolTimer, X> : Windows::System::Threading::IThreadPoolTimer_adaptor<X> { typedef adapt IThreadPoolTimer; };
struct IThreadPoolTimer : IThreadPoolTimer_raw, generate<IThreadPoolTimer> {};

// ThreadPoolTimer
template<typename> struct ThreadPoolTimer_statics {
	static ptr<ThreadPoolTimer> CreatePeriodicTimer(handler_ref<TimerElapsedHandler> handler, const Foundation::TimeSpan& period) { ThreadPoolTimer* timer; hrcheck(get_activation_factory<ThreadPoolTimer, IThreadPoolTimerStatics>()->_CreatePeriodicTimer(handler, period, &timer)); return from_abi(timer); }
	static ptr<ThreadPoolTimer> CreateTimer(handler_ref<TimerElapsedHandler> handler, const Foundation::TimeSpan& delay) { ThreadPoolTimer* timer; hrcheck(get_activation_factory<ThreadPoolTimer, IThreadPoolTimerStatics>()->_CreateTimer(handler, delay, &timer)); return from_abi(timer); }
	static ptr<ThreadPoolTimer> CreatePeriodicTimer(handler_ref<TimerElapsedHandler> handler, const Foundation::TimeSpan& period, handler_ref<TimerDestroyedHandler> destroyed) { ThreadPoolTimer* timer; hrcheck(get_activation_factory<ThreadPoolTimer, IThreadPoolTimerStatics>()->_CreatePeriodicTimerWithCompletion(handler, period, destroyed, &timer)); return from_abi(timer); }
	static ptr<ThreadPoolTimer> CreateTimer(handler_ref<TimerElapsedHandler> handler, const Foundation::TimeSpan& delay, handler_ref<TimerDestroyedHandler> destroyed) { ThreadPoolTimer* timer; hrcheck(get_activation_factory<ThreadPoolTimer, IThreadPoolTimerStatics>()->_CreateTimerWithCompletion(handler, delay, destroyed, &timer)); return from_abi(timer); }
};

template<typename X> struct statics<ThreadPoolTimer, X> : X, Windows::System::Threading::ThreadPoolTimer_statics<void> {
	typedef typename X::root_type ThreadPoolTimer;
};
struct ThreadPoolTimer : generate<ThreadPoolTimer> {};

// TimerDestroyedHandler
struct TimerDestroyedHandler : IUnknown {
	virtual STDMETHODIMP _Invoke(ThreadPoolTimer* timer) = 0;
};

// WorkItemHandler
struct WorkItemHandler : IUnknown {
	virtual STDMETHODIMP _Invoke(Foundation::IAsyncAction* operation) = 0;
};

// IThreadPoolStatics
struct IThreadPoolStatics : IInspectable {
	virtual STDMETHODIMP _RunAsync(WorkItemHandler* handler, Foundation::IAsyncAction* *operation);
	virtual STDMETHODIMP _RunWithPriorityAsync(WorkItemHandler* handler, WorkItemPriority priority, Foundation::IAsyncAction* *operation);
	virtual STDMETHODIMP _RunWithPriorityAndOptionsAsync(WorkItemHandler* handler, WorkItemPriority priority, WorkItemOptions options, Foundation::IAsyncAction* *operation);
};

// ThreadPool
template<typename> struct ThreadPool_statics {
	static ptr<Foundation::IAsyncAction> RunAsync(handler_ref<WorkItemHandler> handler) { Foundation::IAsyncAction* operation; hrcheck(get_activation_factory<ThreadPool, IThreadPoolStatics>()->_RunAsync(handler, &operation)); return from_abi(operation); }
	static ptr<Foundation::IAsyncAction> RunAsync(handler_ref<WorkItemHandler> handler, WorkItemPriority priority) { Foundation::IAsyncAction* operation; hrcheck(get_activation_factory<ThreadPool, IThreadPoolStatics>()->_RunWithPriorityAsync(handler, priority, &operation)); return from_abi(operation); }
	static ptr<Foundation::IAsyncAction> RunAsync(handler_ref<WorkItemHandler> handler, WorkItemPriority priority, WorkItemOptions options) { Foundation::IAsyncAction* operation; hrcheck(get_activation_factory<ThreadPool, IThreadPoolStatics>()->_RunWithPriorityAndOptionsAsync(handler, priority, options, &operation)); return from_abi(operation); }
};

template<typename X> struct statics<ThreadPool, X> : X, Windows::System::Threading::ThreadPool_statics<void> {
	typedef typename X::root_type ThreadPool;
};
struct ThreadPool : generate<ThreadPool> {};
}}}
} // namespace iso_winrt
