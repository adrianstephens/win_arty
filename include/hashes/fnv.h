#ifndef FNV_H
#define FNV_H

#include "base/bits.h"
#include "stream.h"

namespace iso {

//-----------------------------------------------------------------------------
//	FNV
//-----------------------------------------------------------------------------

template<typename T> struct FNV_vals;
template<> struct FNV_vals<uint32> { static const uint32 prime = 0x01000193U,		basis = 0x811C9DC5U; };
template<> struct FNV_vals<uint64> { static const uint64 prime = 0x0100000001B3ULL,	basis = 0xcbf29ce484222325ULL; };

template<typename T, typename W> inline T _FNV(const W *buffer, size_t count, T hash) {
	for (const W *p = buffer, *e = p + count; p < e; ++p)
		hash = T((hash * FNV_vals<T>::prime) ^ *p);
	return hash;
}
template<typename T> inline T _FNV(const char *buffer, T hash) {
	while (char c = *buffer++)
		hash = T(hash * FNV_vals<T>::prime) ^ c;
	return hash;
}
template<typename T, typename W> inline T _FNVa(const W *buffer, size_t count, T hash) {
	for (const W *p = buffer, *e = p + count; p < e; ++p)
		hash = T((hash ^ *p) * FNV_vals<T>::prime);
	return hash;
}
template<typename T> inline T _FNVa(const char *buffer, T hash) {
	while (char c = *buffer++)
		hash = T((hash ^ c) * FNV_vals<T>::prime);
	return hash;
}

template<typename T> T FNV_basis()		{ return _FNV("chongo <Landon Curt Noll> /\\../\\", T(0));}

template<typename T> T FNV0(const void *buffer, size_t len)					{ return buffer && len ? _FNV((const uint8*)buffer, len, T(0)) : 0;}
template<typename T> T FNV0(const char *buffer)								{ return buffer ? _FNV(buffer, T(0)) : 0;}
template<typename T, typename X> T FNV0(const X &x)							{ return FNV0<T>(&x, sizeof(X)); }
template<typename T, typename W> T FNV0_str(const W *buffer, size_t len)	{ return buffer && len ? _FNV(buffer, len, T(0)) : 0; }

template<typename T> T FNV1(const void *buffer, size_t len)					{ return buffer && len ? _FNV((const uint8*)buffer, len, FNV_vals<T>::basis) : 0; }
template<typename T> T FNV1(const char *buffer)								{ return buffer ? _FNV(buffer, FNV_vals<T>::basis) : 0; }
template<typename T, typename X> T FNV1(const X &x)							{ return FNV1<T>(&x, sizeof(X)); }
template<typename T, typename W> T FNV1_str(const W *buffer, size_t len)	{ return buffer && len ? _FNV(buffer, len, FNV_vals<T>::basis) : 0; }

template<typename T> T FNV1a(const void *buffer, size_t len)				{ return buffer && len ? _FNVa((const uint8*)buffer, len, FNV_vals<T>::basis) : 0; }
template<typename T> T FNV1a(const char *buffer)							{ return buffer ? _FNVa(buffer, FNV_vals<T>::basis) : 0; }
template<typename T, typename X> T FNV1a(const X &x)						{ return FNV1a<T>(&x, sizeof(X)); }
template<typename T, typename W> T FNV1a_str(const W *buffer, size_t len)	{ return buffer && len ? _FNVa(buffer, len, FNV_vals<T>::basis) : 0; }


// non power of 2 bits
template<int N> struct fnv_type { typedef typename T_if<(N<=32), uint32, uint64>::type	type; };

template<int N, typename T> inline T	xor_fold(T i)			{ return (i ^ (i >> N)) & bits(N); }
template<> inline uint32				xor_fold<32>(uint32 i)	{ return i; }
template<> inline uint64				xor_fold<64>(uint64 i)	{ return i; }

template<int N, typename W> typename fnv_type<N>::type FNV0(const W *buffer, size_t len) {
	return buffer ? xor_fold<N>(_FNV(buffer, len, typename fnv_type<N>::type(0))) : 0;
}
template<int N> typename fnv_type<N>::type FNV0(const char *buffer) {
	return buffer ? xor_fold<N>(_FNV(buffer, typename fnv_type<N>::type(0))) : 0;
}
template<int N, typename W> typename fnv_type<N>::type FNV1(const W *buffer, size_t len) {
	return buffer && len ? xor_fold<N>(_FNV(buffer, len, FNV_vals<typename fnv_type<N>::type>::basis)) : 0;
}
template<int N> typename fnv_type<N>::type FNV1(const char *buffer) {
	return buffer ? xor_fold<N>(_FNV(buffer, FNV_vals<typename fnv_type<N>::type>::basis)) : 0;
}
template<int N, typename W> typename fnv_type<N>::type FNV1a(const W *buffer, size_t len) {
	return buffer && len ? xor_fold<N>(_FNVa(buffer, len, FNV_vals<typename fnv_type<N>::type>::basis)) : 0;
}
template<int N> typename fnv_type<N>::type FNV1a(const char *buffer) {
	return buffer ? xor_fold<N>(_FNVa(buffer, FNV_vals<typename fnv_type<N>::type>::basis)) : 0;
}

template<int N> struct FNV : writer_mixin<FNV<N>> {
	typedef typename fnv_type<N>::type	CODE;
	CODE	state;

	FNV() : state()									{}
	void			reset()					{ state = 0; }
	int				writebuff(const void *data, size_t size) { state = _FNV((const uint8*)data, size, state); return (int)size; }
	CODE			terminate()	const		{ return state; }
	CODE			digest()	const		{ return terminate(); }
	operator CODE()				const		{ return terminate(); }
};

} // namespace iso

#endif	// FNV_H
