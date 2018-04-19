#pragma once

#include "base.h"

namespace iso_winrt {

//-----------------------------------------------------------------------------
//	clock
//-----------------------------------------------------------------------------

struct clock {
	static Windows::Foundation::DateTime now() noexcept {
		FILETIME ft;
		::GetSystemTimePreciseAsFileTime(&ft);
		return from_FILETIME(ft);
	}

	static FILETIME to_FILETIME(const Windows::Foundation::DateTime &time) noexcept {
		ISO_ASSERT(time.UniversalTime >= 0);
		return FILETIME{DWORD(time.UniversalTime), DWORD(time.UniversalTime>>32)};
	}

	static Windows::Foundation::DateTime from_FILETIME(const FILETIME &ft) noexcept {
		ISO_ASSERT(static_cast<int>(ft.dwHighDateTime) >= 0);
		return Windows::Foundation::DateTime{ft.dwLowDateTime + (int64(ft.dwHighDateTime) << 32)};
	}
};

} // namespace iso_winrt
