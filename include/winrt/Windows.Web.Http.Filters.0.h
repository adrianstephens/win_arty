#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Web { namespace Http { namespace Filters {
struct IHttpFilter;
enum class HttpCacheReadBehavior : int {
	Default = 0,
	MostRecent = 1,
	OnlyFromCache = 2,
	NoCache = 3,
};
enum class HttpCacheWriteBehavior : int {
	Default = 0,
	NoCache = 1,
};
enum class HttpCookieUsageBehavior : int {
	Default = 0,
	NoCookies = 1,
};
struct IHttpCacheControl;
struct IHttpServerCustomValidationRequestedEventArgs;
struct IHttpBaseProtocolFilter4;
struct IHttpBaseProtocolFilter3;
struct IHttpBaseProtocolFilter2;
struct IHttpBaseProtocolFilter;
struct HttpBaseProtocolFilter;
struct HttpCacheControl;
struct HttpServerCustomValidationRequestedEventArgs;
}}}}
} // namespace iso_winrt
