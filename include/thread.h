#ifndef THREAD_H
#define THREAD_H

#include "_thread.h"

namespace iso {

template<typename T> struct ThreadT : Thread { ThreadT() : Thread(static_cast<T*>(this)) {} };

template<typename F> Thread *RunThread(F &&f, int stack_size = THREAD_STACK_DEFAULT, ThreadPriority priority = ThreadPriority::DEFAULT) {
	struct LambdaThread : Thread {
		F	f;
		int	operator()()	{ f(); delete this; return 0; }
		LambdaThread(F &&_f, int stack_size, ThreadPriority priority) : Thread(this, 0, stack_size, priority), f(move(_f)) { Start(); }
	};
	return new LambdaThread(move(f), stack_size, priority);
}

template<typename F> Thread *RunThread(F f, ThreadPriority priority) {
	return RunThread(f, THREAD_STACK_DEFAULT, priority);
}

//-----------------------------------------------------------------------------
// with (...something that supports Lock/UnLock)
//-----------------------------------------------------------------------------

template<typename T> struct with_s {
	T	&t;
	with_s(T &_t) : t(_t)					{ t.Lock();	}
	with_s(T &_t, float timeout) : t(_t)	{ t.Lock(timeout);	}
	~with_s()								{ t.UnLock(); }
};

template<typename T> with_s<T> with(T &t)					{ return with_s<T>(t); }
template<typename T> with_s<T> with(T &t, float timeout)	{ return with_s<T>(t, timeout); }

template<typename T, typename M> struct locked_s : reference<T>, with_s<M> {
	locked_s(T &t, M &m) : reference<T>(t), with_s<M>(m) {}
};

template<typename T, typename M> locked_s<T, M> locked(T &t, M &m)	{ return locked_s<T, M>(t, m); }

#if 0

//---------------------------------------------------------
// LightweightSemaphore
//---------------------------------------------------------
class LightweightSemaphore : Semaphore {
private:
	atomic<int> count;

public:
	LightweightSemaphore(int initialCount = 0) : count(initialCount), Semaphore(0) {}

	bool TryLock() {
		int		count0 = count;
		return count0 > 0 && count.cas(count0, count0 - 1);
	}

	void Lock() {
		if (!TryLock()) {
			for (int spin = 10000; spin--;) {
				if (TryLock())
					return;
			}
			if (count-- <= 0)
				Semaphore::Lock();
		}
	}

	void UnLock(int n = 1) {
		int count0 = count += n;
		if (count0 < n)
			Semaphore::UnLock(n - max(count0, 0));
	}
};

//---------------------------------------------------------
// AutoResetEvent
//---------------------------------------------------------

class AutoResetEvent : LightweightSemaphore {
	// 1 => signaled, 0 => reset and no threads are waiting, -N => reset and N threads are waiting
	atomic<int> status;
public:
	AutoResetEvent(int initialStatus = 0) : status(initialStatus) {}
	void UnLock() {
		for (;;) {
			int status0 = status;
			if (status.cas(status0, status0 < 1 ? status0 + 1 : 1)) {
				if (status0 < 0)
					LightweightSemaphore::UnLock();
				return;
			}
		}
	}
	void Lock() {
		if (--status < 0)
			LightweightSemaphore::Lock();
	}
};
#endif
} // namespace iso

#endif // THREAD_H
