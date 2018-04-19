#include "thread.h"

namespace iso {

//-----------------------------------------------------------------------------
// Thread
//-----------------------------------------------------------------------------

TLS<Thread*> Thread::curr;

struct ThreadName {
	DWORD	dwType;		// Must be 0x1000
	LPCSTR	szName;		// Pointer to name (in user address space)
	DWORD	dwThreadID;	// Thread ID (-1 for caller thread)
	DWORD	dwFlags;	// Reserved for future use; must be zero
	ThreadName(DWORD id, LPCSTR name) : dwType(0x1000), szName(name), dwThreadID(id), dwFlags(0) {
		__try {
			RaiseException(0x406D1388, 0, sizeof(*this)/sizeof(DWORD), (ULONG_PTR*)this);
		} __except(EXCEPTION_CONTINUE_EXECUTION) {
		}
	}
};

void Thread::_create(const char *name, int stack_size, ThreadPriority priority, void *p, LPTHREAD_START_ROUTINE proc) {
	DWORD	id;
	if (h = CreateThread(NULL, stack_size, proc, p, CREATE_SUSPENDED, &id)) {
		SetThreadPriority(h, priority.value);
		ThreadName(id, name);
	}
}

int Thread::Join(Timeout timeout) {
	DWORD ret = 0;
	if (WaitForSingleObject(h, timeout) == WAIT_OBJECT_0)
		GetExitCodeThread(h, &ret);
	return ret;
}

}

