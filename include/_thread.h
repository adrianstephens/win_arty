#ifndef _THREAD_H
#define _THREAD_H

#include "base/defs.h"
#include "base/functions.h"
#include <windows.h>
#include <mmsystem.h>
#undef min
#undef max

#define THREAD_STACK_DEFAULT 32768//8192

namespace iso {
//-----------------------------------------------------------------------------
//	Time
//-----------------------------------------------------------------------------
class Time {
public:
	typedef	int64 type;
	static type		get_freq()		{ LARGE_INTEGER q; QueryPerformanceFrequency(&q); return q.QuadPart; }
	static type		get()			{ LARGE_INTEGER t; QueryPerformanceCounter(&t); return t.QuadPart; }
	static float	to_secs(type t)	{ return float(t) / get_freq(); }
private:
	type	start;
public:
	Time() : start(get())		{}
	void		Reset()			{ start = get(); }
	operator	float()	const	{ return to_secs(get() - start);	}
};

struct Timeout {
	DWORD	u;
	constexpr Timeout()					: u(INFINITE)	{}
//	constexpr Timeout(const _infinity&)	: u(INFINITE)	{}
	constexpr Timeout(float s)			: u(DWORD(s * 1000))	{}
	operator DWORD() const { return u; }
};

//-----------------------------------------------------------------------------
// Thread Local Storage
//-----------------------------------------------------------------------------

class _TLS {
	DWORD	tls;
protected:
	void	set(void *p)	const	{ TlsSetValue(tls, p);		}
	void	*get()			const	{ return TlsGetValue(tls);	}
	_TLS()		: tls(TlsAlloc())	{}
};

template<class T> class TLS : _TLS {
	struct temp {
		TLS	&tls;
		T	t;
		temp(TLS &_tls) : tls(_tls), t(_tls) {}
		~temp()						{ tls = t; }
		T* operator->()				{ return &t; }
	};
public:
	TLS()							{}
	TLS(const T &t)					{ set((void*&)t);			}
	const T &operator=(const T &t)	{ set((void*&)t); return t;	}
	operator const T()				{ return arbitrary(get());	}
	temp operator->()				{ return temp(*this);		}
};

template<class T> class TLS<T*> : _TLS {
public:
	TLS()							{}
	TLS(T *t)						{ set(t);					}
	T *operator=(T *t)				{ set(t); return t;			}
	operator T*()					{ return (T*)get();			}
	T *operator->()					{ return (T*)get();			}
	T &operator *()					{ return *(T*)get();		}
};

//-----------------------------------------------------------------------------
// Thread
//-----------------------------------------------------------------------------

struct ThreadPriority {
	enum type {
		HIGHEST	= THREAD_PRIORITY_HIGHEST,
		HIGH	= THREAD_PRIORITY_ABOVE_NORMAL,
		DEFAULT = THREAD_PRIORITY_NORMAL,
		LOW		= THREAD_PRIORITY_BELOW_NORMAL,
		LOWEST	= THREAD_PRIORITY_LOWEST,
	} value;
	ThreadPriority(type v) : value(v)	{}
};

class Thread {
	static TLS<Thread*> curr;
	template<class T>	static DWORD WINAPI proc(T *t) { curr = t; return (*t)(); }
	void	_create(const char *name, int stack_size, ThreadPriority priority, void *p, LPTHREAD_START_ROUTINE proc);

	HANDLE	h;
public:
	static Thread*	current()			{ return curr; }
	static uint64	current_id()		{ return (uint64)::GetCurrentThreadId(); }
	static void		sleep(float t = 0)	{ Sleep(DWORD(t * 1000)); }
	static void		yield()				{ ::SwitchToThread(); }
	static void		exit(int ret)		{ ExitThread(ret); }
	static int		processors()		{ SYSTEM_INFO info; GetSystemInfo(&info); return info.dwNumberOfProcessors; }

	void			SetAffinity(uint64 affinity)	{ SetThreadAffinityMask(h, affinity); }
	void			SetProcessor(int processor)		{ SetAffinity(uint64(1) << processor); }
	bool			Start()							{ return h && ResumeThread(h) != (DWORD)-1; }
	void			Suspend()						{ SuspendThread(h);	}
	int				Join(Timeout timeout = Timeout());

	template<class T> Thread(T *t, const char *name = 0, int stack_size = THREAD_STACK_DEFAULT, ThreadPriority priority = ThreadPriority::DEFAULT) {
		_create(name, stack_size, priority, t, (LPTHREAD_START_ROUTINE)proc<T>);
	}
	template<class T> Thread(T *t, const char *name, ThreadPriority priority) {
		_create(name, THREAD_STACK_DEFAULT, priority, t, (LPTHREAD_START_ROUTINE)proc<T>);
	}
	~Thread()	{ CloseHandle(h); }
};

//-----------------------------------------------------------------------------
// Event
//-----------------------------------------------------------------------------

class Event {
	HANDLE	h;
public:
	Event(bool manual_reset = false, bool set = false)	{ h = CreateEvent(nullptr, manual_reset, set, nullptr); }
	~Event()									{ CloseHandle(h); }
	bool	Signal()							{ return !!SetEvent(h); }
	bool	Clear()								{ return !!ResetEvent(h); }
	bool	Wait(Timeout timeout = Timeout())	{ return  WaitForSingleObject(h, timeout) == WAIT_OBJECT_0; }
};

//-----------------------------------------------------------------------------
// CriticalSection
//-----------------------------------------------------------------------------
class CriticalSection {
	friend class ConditionVariable;
	CRITICAL_SECTION	cs;
public:
	CriticalSection(int spincount)	{ InitializeCriticalSectionAndSpinCount(&cs, spincount); }
	CriticalSection()				{ InitializeCriticalSection(&cs);			}
	~CriticalSection()				{ DeleteCriticalSection(&cs);				}

	void	SetSpinCount(int count)	{ SetCriticalSectionSpinCount(&cs, count);	}
	void	Lock()					{ EnterCriticalSection(&cs);				}
	bool	TryLock()				{ return !!TryEnterCriticalSection(&cs);	}
	void	UnLock()				{ LeaveCriticalSection(&cs);				}
};

//-----------------------------------------------------------------------------
// Mutex
//-----------------------------------------------------------------------------
class Mutex {
	HANDLE	h;
public:
	Mutex(bool locked = false)					{ h = CreateMutex(NULL, locked, NULL); }
	~Mutex()									{ CloseHandle(h); }
	bool	Lock(Timeout timeout = Timeout())	{ return WaitForSingleObject(h, timeout) == WAIT_OBJECT_0; }
	void	UnLock()							{ ReleaseMutex(h); }
	operator HANDLE() const						{ return h; }
};

//-----------------------------------------------------------------------------
// Semaphore
//-----------------------------------------------------------------------------
class Semaphore {
	HANDLE	h;
	Semaphore(const Semaphore&) = delete;
	Semaphore& operator=(const Semaphore&) = delete;
public:
	static HANDLE Shared(int initial_count = 1)	{
		SECURITY_ATTRIBUTES	sa = {sizeof(SECURITY_ATTRIBUTES), NULL, TRUE};
		return CreateSemaphore(&sa, initial_count, 0x7fffffff, NULL);
	}
	Semaphore(HANDLE _h) : h(_h)				{}
	Semaphore(int count = 1)					{ h = CreateSemaphore(NULL, count, 0x7fffffff, NULL); }
	~Semaphore()								{ CloseHandle(h); }
	bool	Lock(Timeout timeout = Timeout())	{ return WaitForSingleObject(h, timeout) == WAIT_OBJECT_0; }
	void	UnLock(int count = 1)				{ ReleaseSemaphore(h, count, NULL); }
	operator HANDLE() const						{ return h; }
};

//-----------------------------------------------------------------------------
// ConditionVariable
//-----------------------------------------------------------------------------

class ConditionVariable {
	CONDITION_VARIABLE cv;
public:
	ConditionVariable()	{ InitializeConditionVariable(&cv); }
	bool	Lock(CriticalSection &cs, Timeout timeout = Timeout())	{ return !!SleepConditionVariableCS(&cv, &cs.cs, timeout); }
//	bool	Lock(SRWLock &lock, Timeout timeout = Timeout(), bool shared = false)	{ SleepConditionVariableSRW(&cv, &lock, timeout, shared ? CONDITION_VARIABLE_LOCKMODE_SHARED : 0); }
	void	UnLockAll()												{ WakeAllConditionVariable(&cv); }
	void	UnLock()												{ WakeConditionVariable(&cv); }
};

} //namespace iso
#endif // _THREAD_H
