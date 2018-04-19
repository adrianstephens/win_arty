#ifndef SHA_H
#define SHA_H

#include "base/array.h"
#include "base/strings.h"
#include "base/bits.h"
#include "stream.h"

namespace iso {

//-----------------------------------------------------------------------------
//	SHA1
//-----------------------------------------------------------------------------

class SHA1 : public block_writer<SHA1, 64> {
	static constexpr int block_size = 64;

	static constexpr uint32 ch(uint32 x, uint32 y, uint32 z)	{ return (x & y) ^ (~x & z); }
	static constexpr uint32 py(uint32 x, uint32 y, uint32 z)	{ return x ^ y ^ z; }
	static constexpr uint32 mj(uint32 x, uint32 y, uint32 z)	{ return (x & y) ^ (x & z) ^ (y & z); }
	static constexpr uint32 rl30(uint32 x)						{ return rotate_left<30>(x); }

	static constexpr uint32 r0(uint32 v, uint32 w, uint32 x, uint32 y, uint32 z, uint32 i) { return z + ch(w, x, y) + i + 0x5A827999 + rotate_left(v, 5); }
	static constexpr uint32 r1(uint32 v, uint32 w, uint32 x, uint32 y, uint32 z, uint32 i) { return z + py(w, x, y) + i + 0x6ED9EBA1 + rotate_left(v, 5); }
	static constexpr uint32 r2(uint32 v, uint32 w, uint32 x, uint32 y, uint32 z, uint32 i) { return z + mj(w, x, y) + i + 0x8F1BBCDC + rotate_left(v, 5); }
	static constexpr uint32 r3(uint32 v, uint32 w, uint32 x, uint32 y, uint32 z, uint32 i) { return z + py(w, x, y) + i + 0xCA62C1D6 + rotate_left(v, 5); }

	static constexpr uint32 r0s(uint32 v, uint32 w, uint32 x, uint32 y, uint32 z, uint32 i) { return r0(v, w, rl30(x), rl30(y), rl30(z), i); }
	static constexpr uint32 r1s(uint32 v, uint32 w, uint32 x, uint32 y, uint32 z, uint32 i) { return r1(v, w, rl30(x), rl30(y), rl30(z), i); }
	static constexpr uint32 r2s(uint32 v, uint32 w, uint32 x, uint32 y, uint32 z, uint32 i) { return r2(v, w, rl30(x), rl30(y), rl30(z), i); }
	static constexpr uint32 r3s(uint32 v, uint32 w, uint32 x, uint32 y, uint32 z, uint32 i) { return r3(v, w, rl30(x), rl30(y), rl30(z), i); }

	struct State {
		uint32	a, b, c, d, e;

		constexpr State	R0(uint32 w) const { return State{ r0(a,b,c,d,e,w),	a, rl30(b), c, d }; }
		constexpr State	R1(uint32 w) const { return State{ r1(a,b,c,d,e,w),	a, rl30(b), c, d }; }
		constexpr State	R2(uint32 w) const { return State{ r2(a,b,c,d,e,w),	a, rl30(b), c, d }; }
		constexpr State	R3(uint32 w) const { return State{ r3(a,b,c,d,e,w),	a, rl30(b), c, d }; }

		friend constexpr State operator+(const State &x, const State &y) { return State{x.a + y.a, x.b + y.b, x.c + y.c, x.d + y.d, x.e + y.e}; }
	};
	
	static constexpr State	init_state() { return {0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476, 0xc3d2e1f0}; }

	typedef	constexpr_array<uint32, 80> w_array_all;

	struct w_array {
		constexpr_array<uint32, 16> t;

		constexpr uint32 at(size_t i) const noexcept {
			return i < 16 ? t.t[i] : rotate_left(at(i - 3) ^ at(i - 8) ^ at(i - 14) ^ at(i - 16), 1);
		}
		uint32 at(size_t i) {
			return i < 16 ? t[i] : t[i & 15] = rotate_left<1>(t[(i - 3) & 15] ^ t[(i - 8) & 15] ^ t[(i - 14) & 15] ^ t[i & 15]);
		}

		template<size_t N, size_t... I> static constexpr constexpr_array<uint32, 16> get(constexpr_array<uint8, N> const &input, uint32 start_pos, const index_list<I...>) noexcept {
			return {{bytes_to_u4(input[start_pos + I * 4 + 3], input[start_pos + I * 4 + 2], input[start_pos + I * 4 + 1], input[start_pos + I * 4 + 0])...}};
		}

		template<size_t N> static constexpr uint32 at(const constexpr_array<uint32, N> &prev, int i) {
			return i < 0 ? prev[N + i] : rotate_left(at(prev, i - 3) ^ at(prev, i - 8) ^ at(prev, i - 14) ^ at(prev, i - 16), 1);
		}
		template<size_t... I, size_t N> static constexpr constexpr_array<uint32, 16> next(const constexpr_array<uint32, N> &prev, const index_list<I...>) {
			return {{at(prev, I)...}};
		}
		template<size_t... I, size_t N> static constexpr auto next_chunk(const constexpr_array<uint32, N> &input, const index_list<I...> il) {
			return next_chunk(input + w_array::next(input, il), il);
		}
		template<size_t... I> static constexpr auto next_chunk(const constexpr_array<uint32, 64> &input, const index_list<I...> il) {
			return input + next(input, il);
		}
		constexpr auto all() const {
			return next_chunk(t, make_index_list<16>());
		}

		w_array(const void *data) {
			for (int i = 0; i < 16; i++)
				t[i] = ((uint32be*)data)[i];
		}
		template<size_t N> constexpr w_array(const constexpr_array<uint8, N> &input, uint32 start_pos) : t(get(input, start_pos, make_index_list<16>())) {}
	};

	template<size_t I> static constexpr State R0x(const w_array &W, const State &blk)				{ return R0x<I + 1>(W, blk.R0(W.at(I +  0))); }
	template<size_t I> static constexpr State R1x(const w_array &W, const State &blk)				{ return R1x<I + 1>(W, blk.R1(W.at(I + 20))); }
	template<size_t I> static constexpr State R2x(const w_array &W, const State &blk)				{ return R2x<I + 1>(W, blk.R2(W.at(I + 40))); }
	template<size_t I> static constexpr State R3x(const w_array &W, const State &blk)				{ return R3x<I + 1>(W, blk.R3(W.at(I + 60))); }

	template<> specialised(static) constexpr State R0x<19>(const w_array &W, const State &blk)		{ return blk.R0(W.at(19 +  0)); }
	template<> specialised(static) constexpr State R1x<19>(const w_array &W, const State &blk)		{ return blk.R1(W.at(19 + 20)); }
	template<> specialised(static) constexpr State R2x<19>(const w_array &W, const State &blk)		{ return blk.R2(W.at(19 + 40)); }
	template<> specialised(static) constexpr State R3x<19>(const w_array &W, const State &blk)		{ return blk.R3(W.at(19 + 60)); }

	template<size_t I> static constexpr State R0x(const w_array_all &W, const State &blk)			{ return R0x<I + 1>(W, blk.R0(W[I +  0])); }
	template<size_t I> static constexpr State R1x(const w_array_all &W, const State &blk)			{ return R1x<I + 1>(W, blk.R1(W[I + 20])); }
	template<size_t I> static constexpr State R2x(const w_array_all &W, const State &blk)			{ return R2x<I + 1>(W, blk.R2(W[I + 40])); }
	template<size_t I> static constexpr State R3x(const w_array_all &W, const State &blk)			{ return R3x<I + 1>(W, blk.R3(W[I + 60])); }

	template<> specialised(static) constexpr State R0x<19>(const w_array_all &W, const State &blk)	{ return blk.R0(W[19 +  0]); }
	template<> specialised(static) constexpr State R1x<19>(const w_array_all &W, const State &blk)	{ return blk.R1(W[19 + 20]); }
	template<> specialised(static) constexpr State R2x<19>(const w_array_all &W, const State &blk)	{ return blk.R2(W[19 + 40]); }
	template<> specialised(static) constexpr State R3x<19>(const w_array_all &W, const State &blk)	{ return blk.R3(W[19 + 60]); }

	template<typename W> constexpr static State process_block(const W &w, const State &blk) {
		return R3x<0>(w, R2x<0>(w, R1x<0>(w, R0x<0>(w, blk)	))) + blk;
	}

	constexpr static State process_block(const w_array &W, const State &blk) {
		return process_block(W.all(), blk);
	}

	template<size_t N> static constexpr State finalize(const constexpr_array<uint8, N> &input, const State &blk) noexcept;
	template<> specialised(static) constexpr State finalize<block_size>(const constexpr_array<uint8, block_size> &input, const State &blk) noexcept {
		return process_block(w_array(input, 0).all(), blk);
	}
	template<> specialised(static) constexpr State finalize<block_size * 2>(const constexpr_array<uint8, block_size * 2> &input, const State &blk) noexcept {
		return process_block(w_array(input, block_size).all(), process_block(w_array(input, 0).all(), blk));
	}

	template<size_t N> static constexpr State process_input(const constexpr_array<uint8, N> &input, uint32 i, const State &blk) noexcept {
		return i + block_size <= N
			? process_input(input, i + block_size, process_block(w_array(input, i), blk))
			: finalize(
				slice<N % block_size>(input, i) + uint8(0x80) + constexpr_array<uint8, (block_size << int(N % block_size + 9 > block_size)) - (N % block_size + 9)>{} + be_byte_array(uint64(N * 8)),
				blk
			);
	}

	static constexpr auto to_byte_array(const State &blk) {
		return be_byte_array(blk.a) + be_byte_array(blk.b) + be_byte_array(blk.c) + be_byte_array(blk.d) + be_byte_array(blk.e);
	}

	State	state;
public:
	void			process(const void *data);
	const uint32*	terminate();

	struct CODE : fixed_array<uint8, 20> {
		CODE() {}
		CODE(const uint32 s[5]) { (fixed_array<uint32be, 5>&)*this = s; }
	};

	SHA1()									: state(init_state())	{}
	SHA1(const void *buffer, size_t size)	: state(init_state())	{ writebuff(buffer, size); }
	template<typename X> SHA1(const X &x)	: state(init_state())	{ this->write(x); }

	operator CODE()		{ return terminate(); }
	CODE	digest()	{ return terminate(); }
	void	reset()		{ state = init_state(); p = 0; }

	template<size_t N> static constexpr auto calculate(const constexpr_array<uint8, N> &input) {
		return to_byte_array(process_input(input, 0, init_state()));
	}
	template<size_t N> static constexpr auto calculate(const char (&input)[N]) {
		return to_byte_array(process_input(make_constexpr_string<uint8>(input), 0, init_state()));
	}
};

inline auto to_string(const SHA1::CODE &sha) {
	return to_hex_string<20>(sha.begin());
}

//-----------------------------------------------------------------------------
//	SHA2
//-----------------------------------------------------------------------------

template<typename T> class SHA2 : public block_writer<SHA2<T>, sizeof(T) * 16> {
	fixed_array<T, 8>	state;
public:
	enum {BLOCK_SIZE = sizeof(T) * 16};
	void		process(const void *data);
	const T*	terminate();
	SHA2(const T i[8]) : state((fixed_array<T, 8>)i)	{}
	void		reset(const T i[8]) { state = fixed_array<T, 8>(i); }
};

template<typename T> const T *SHA2<T>::terminate() {
	memory_block	b	= this->buffered();
	uint8			*e	= b.end();
	*e	= 0x80;
	memset(e + 1, 0, BLOCK_SIZE - b.length() - 1);
	if (b.length() > BLOCK_SIZE - sizeof(T) * 2) {
		process(b);
		memset(b, 0, BLOCK_SIZE);
	}
	uint8	*len = b + BLOCK_SIZE;
	for (uint64 t = this->tell() * 8; t; t = t >> 8)
		*--len = t & 0xff;
	process(b);
	return state.begin();
}

template<typename T, int N> class SHA2_N : public SHA2<T> {
	static const T init_state[8];
public:
	struct CODE : fixed_array<uint8, N * sizeof(T)> {
		CODE() {}
		CODE(const T s[N]) { (fixed_array<typename T_bigendian_type<T>::type, N>&)*this = s; }
	};
	SHA2_N()								: SHA2<T>(init_state) {}
	SHA2_N(const void *buffer, size_t size)	: SHA2<T>(init_state)	{ this->writebuff(buffer, size); }
	template<typename X> SHA2_N(const X &x)	: SHA2<T>(init_state)	{ this->write(x); }

	operator CODE()		{ return this->terminate(); }
	CODE	digest()	{ return this->terminate(); }
	void	reset()		{ SHA2<T>::reset(init_state); this->p = 0; }
};

typedef SHA2_N<uint32, 7>	SHA224;
typedef SHA2_N<uint32, 8>	SHA256;
typedef SHA2_N<uint64, 6>	SHA384;
typedef SHA2_N<uint64, 8>	SHA512;


//constexpr version
#if 1

struct constexpr_sha1 {


};
#endif

} //namespace iso

#endif// SHA_H

