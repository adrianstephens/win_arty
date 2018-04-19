#include "sha.h"
#include "base/bits.h"
#include "base/algorithm.h"

using namespace iso;

void SHA1::process(const void *data) {
	w_array	W(data);

#if 0
	State	state2	= state;

	uint32	w0, w1, w2, w3, w4;
	w0 = W.at( 0); w1 = W.at( 1); w2 = W.at( 2); w3 = W.at( 3); w4 = W.at( 4); state2 = state2.R0(w0).R0(w1).R0(w2).R0(w3).R0(w4);
	w0 = W.at( 5); w1 = W.at( 6); w2 = W.at( 7); w3 = W.at( 8); w4 = W.at( 9); state2 = state2.R0(w0).R0(w1).R0(w2).R0(w3).R0(w4);
	w0 = W.at(10); w1 = W.at(11); w2 = W.at(12); w3 = W.at(13); w4 = W.at(14); state2 = state2.R0(w0).R0(w1).R0(w2).R0(w3).R0(w4);
	w0 = W.at(15); w1 = W.at(16); w2 = W.at(17); w3 = W.at(18); w4 = W.at(19); state2 = state2.R0(w0).R0(w1).R0(w2).R0(w3).R0(w4);
	w0 = W.at(20); w1 = W.at(21); w2 = W.at(22); w3 = W.at(23); w4 = W.at(24); state2 = state2.R1(w0).R1(w1).R1(w2).R1(w3).R1(w4);
	w0 = W.at(25); w1 = W.at(26); w2 = W.at(27); w3 = W.at(28); w4 = W.at(29); state2 = state2.R1(w0).R1(w1).R1(w2).R1(w3).R1(w4);
	w0 = W.at(30); w1 = W.at(31); w2 = W.at(32); w3 = W.at(33); w4 = W.at(34); state2 = state2.R1(w0).R1(w1).R1(w2).R1(w3).R1(w4);
	w0 = W.at(35); w1 = W.at(36); w2 = W.at(37); w3 = W.at(38); w4 = W.at(39); state2 = state2.R1(w0).R1(w1).R1(w2).R1(w3).R1(w4);
	w0 = W.at(40); w1 = W.at(41); w2 = W.at(42); w3 = W.at(43); w4 = W.at(44); state2 = state2.R2(w0).R2(w1).R2(w2).R2(w3).R2(w4);
	w0 = W.at(45); w1 = W.at(46); w2 = W.at(47); w3 = W.at(48); w4 = W.at(49); state2 = state2.R2(w0).R2(w1).R2(w2).R2(w3).R2(w4);
	w0 = W.at(50); w1 = W.at(51); w2 = W.at(52); w3 = W.at(53); w4 = W.at(54); state2 = state2.R2(w0).R2(w1).R2(w2).R2(w3).R2(w4);
	w0 = W.at(55); w1 = W.at(56); w2 = W.at(57); w3 = W.at(58); w4 = W.at(59); state2 = state2.R2(w0).R2(w1).R2(w2).R2(w3).R2(w4);
	w0 = W.at(60); w1 = W.at(61); w2 = W.at(62); w3 = W.at(63); w4 = W.at(64); state2 = state2.R3(w0).R3(w1).R3(w2).R3(w3).R3(w4);
	w0 = W.at(65); w1 = W.at(66); w2 = W.at(67); w3 = W.at(68); w4 = W.at(69); state2 = state2.R3(w0).R3(w1).R3(w2).R3(w3).R3(w4);
	w0 = W.at(70); w1 = W.at(71); w2 = W.at(72); w3 = W.at(73); w4 = W.at(74); state2 = state2.R3(w0).R3(w1).R3(w2).R3(w3).R3(w4);
	w0 = W.at(75); w1 = W.at(76); w2 = W.at(77); w3 = W.at(78); w4 = W.at(79); state2 = state2.R3(w0).R3(w1).R3(w2).R3(w3).R3(w4);

	state = state + state2;

#else

	// Copy state[] to working vars
	uint32 a = state.a;
	uint32 b = state.b;
	uint32 c = state.c;
	uint32 d = state.d;
	uint32 e = state.e;
	// 4 rounds of 20 operations each. Loop unrolled.
#if 1
	e = r0(a, b, c, d, e, W.at( 0)); b = rl30(b); d = r0(e, a, b, c, d, W.at( 1)); a = rl30(a); c = r0(d, e, a, b, c, W.at( 2)); e = rl30(e); b = r0(c, d, e, a, b, W.at( 3)); d = rl30(d); a = r0(b, c, d, e, a, W.at( 4)); c = rl30(c);
	e = r0(a, b, c, d, e, W.at( 5)); b = rl30(b); d = r0(e, a, b, c, d, W.at( 6)); a = rl30(a); c = r0(d, e, a, b, c, W.at( 7)); e = rl30(e); b = r0(c, d, e, a, b, W.at( 8)); d = rl30(d); a = r0(b, c, d, e, a, W.at( 9)); c = rl30(c);
	e = r0(a, b, c, d, e, W.at(10)); b = rl30(b); d = r0(e, a, b, c, d, W.at(11)); a = rl30(a); c = r0(d, e, a, b, c, W.at(12)); e = rl30(e); b = r0(c, d, e, a, b, W.at(13)); d = rl30(d); a = r0(b, c, d, e, a, W.at(14)); c = rl30(c);
	e = r0(a, b, c, d, e, W.at(15)); b = rl30(b); d = r0(e, a, b, c, d, W.at(16)); a = rl30(a); c = r0(d, e, a, b, c, W.at(17)); e = rl30(e); b = r0(c, d, e, a, b, W.at(18)); d = rl30(d); a = r0(b, c, d, e, a, W.at(19)); c = rl30(c);
	e = r1(a, b, c, d, e, W.at(20)); b = rl30(b); d = r1(e, a, b, c, d, W.at(21)); a = rl30(a); c = r1(d, e, a, b, c, W.at(22)); e = rl30(e); b = r1(c, d, e, a, b, W.at(23)); d = rl30(d); a = r1(b, c, d, e, a, W.at(24)); c = rl30(c);
	e = r1(a, b, c, d, e, W.at(25)); b = rl30(b); d = r1(e, a, b, c, d, W.at(26)); a = rl30(a); c = r1(d, e, a, b, c, W.at(27)); e = rl30(e); b = r1(c, d, e, a, b, W.at(28)); d = rl30(d); a = r1(b, c, d, e, a, W.at(29)); c = rl30(c);
	e = r1(a, b, c, d, e, W.at(30)); b = rl30(b); d = r1(e, a, b, c, d, W.at(31)); a = rl30(a); c = r1(d, e, a, b, c, W.at(32)); e = rl30(e); b = r1(c, d, e, a, b, W.at(33)); d = rl30(d); a = r1(b, c, d, e, a, W.at(34)); c = rl30(c);
	e = r1(a, b, c, d, e, W.at(35)); b = rl30(b); d = r1(e, a, b, c, d, W.at(36)); a = rl30(a); c = r1(d, e, a, b, c, W.at(37)); e = rl30(e); b = r1(c, d, e, a, b, W.at(38)); d = rl30(d); a = r1(b, c, d, e, a, W.at(39)); c = rl30(c);
	e = r2(a, b, c, d, e, W.at(40)); b = rl30(b); d = r2(e, a, b, c, d, W.at(41)); a = rl30(a); c = r2(d, e, a, b, c, W.at(42)); e = rl30(e); b = r2(c, d, e, a, b, W.at(43)); d = rl30(d); a = r2(b, c, d, e, a, W.at(44)); c = rl30(c);
	e = r2(a, b, c, d, e, W.at(45)); b = rl30(b); d = r2(e, a, b, c, d, W.at(46)); a = rl30(a); c = r2(d, e, a, b, c, W.at(47)); e = rl30(e); b = r2(c, d, e, a, b, W.at(48)); d = rl30(d); a = r2(b, c, d, e, a, W.at(49)); c = rl30(c);
	e = r2(a, b, c, d, e, W.at(50)); b = rl30(b); d = r2(e, a, b, c, d, W.at(51)); a = rl30(a); c = r2(d, e, a, b, c, W.at(52)); e = rl30(e); b = r2(c, d, e, a, b, W.at(53)); d = rl30(d); a = r2(b, c, d, e, a, W.at(54)); c = rl30(c);
	e = r2(a, b, c, d, e, W.at(55)); b = rl30(b); d = r2(e, a, b, c, d, W.at(56)); a = rl30(a); c = r2(d, e, a, b, c, W.at(57)); e = rl30(e); b = r2(c, d, e, a, b, W.at(58)); d = rl30(d); a = r2(b, c, d, e, a, W.at(59)); c = rl30(c);
	e = r3(a, b, c, d, e, W.at(60)); b = rl30(b); d = r3(e, a, b, c, d, W.at(61)); a = rl30(a); c = r3(d, e, a, b, c, W.at(62)); e = rl30(e); b = r3(c, d, e, a, b, W.at(63)); d = rl30(d); a = r3(b, c, d, e, a, W.at(64)); c = rl30(c);
	e = r3(a, b, c, d, e, W.at(65)); b = rl30(b); d = r3(e, a, b, c, d, W.at(66)); a = rl30(a); c = r3(d, e, a, b, c, W.at(67)); e = rl30(e); b = r3(c, d, e, a, b, W.at(68)); d = rl30(d); a = r3(b, c, d, e, a, W.at(69)); c = rl30(c);
	e = r3(a, b, c, d, e, W.at(70)); b = rl30(b); d = r3(e, a, b, c, d, W.at(71)); a = rl30(a); c = r3(d, e, a, b, c, W.at(72)); e = rl30(e); b = r3(c, d, e, a, b, W.at(73)); d = rl30(d); a = r3(b, c, d, e, a, W.at(74)); c = rl30(c);
	e = r3(a, b, c, d, e, W.at(75)); b = rl30(b); d = r3(e, a, b, c, d, W.at(76)); a = rl30(a); c = r3(d, e, a, b, c, W.at(77)); e = rl30(e); b = r3(c, d, e, a, b, W.at(78)); d = rl30(d); a = r3(b, c, d, e, a, W.at(79)); c = rl30(c);
#else
	e = r0(a, b, c,			d,		e,		W.at( 0)); d = r0(e, a, rl30(b), c,			d,	   W.at( 1)); c = r0(d, e, rl30(a), rl30(b), c,		  W.at( 2)); b = r0(c, d, rl30(e), rl30(a), rl30(b), W.at( 3)); a = r0(b, c, rl30(d), rl30(e), rl30(a), W.at( 4));
	e = r0(a, b, rl30(c), rl30(d), rl30(e), W.at( 5)); d = r0(e, a, rl30(b), rl30(c), rl30(d), W.at( 6)); c = r0(d, e, rl30(a), rl30(b), rl30(c), W.at( 7)); b = r0(c, d, rl30(e), rl30(a), rl30(b), W.at( 8)); a = r0(b, c, rl30(d), rl30(e), rl30(a), W.at( 9));
	e = r0(a, b, rl30(c), rl30(d), rl30(e), W.at(10)); d = r0(e, a, rl30(b), rl30(c), rl30(d), W.at(11)); c = r0(d, e, rl30(a), rl30(b), rl30(c), W.at(12)); b = r0(c, d, rl30(e), rl30(a), rl30(b), W.at(13)); a = r0(b, c, rl30(d), rl30(e), rl30(a), W.at(14));
	e = r0(a, b, rl30(c), rl30(d), rl30(e), W.at(15)); d = r0(e, a, rl30(b), rl30(c), rl30(d), W.at(16)); c = r0(d, e, rl30(a), rl30(b), rl30(c), W.at(17)); b = r0(c, d, rl30(e), rl30(a), rl30(b), W.at(18)); a = r0(b, c, rl30(d), rl30(e), rl30(a), W.at(19));
	e = r1(a, b, rl30(c), rl30(d), rl30(e), W.at(20)); d = r1(e, a, rl30(b), rl30(c), rl30(d), W.at(21)); c = r1(d, e, rl30(a), rl30(b), rl30(c), W.at(22)); b = r1(c, d, rl30(e), rl30(a), rl30(b), W.at(23)); a = r1(b, c, rl30(d), rl30(e), rl30(a), W.at(24));
	e = r1(a, b, rl30(c), rl30(d), rl30(e), W.at(25)); d = r1(e, a, rl30(b), rl30(c), rl30(d), W.at(26)); c = r1(d, e, rl30(a), rl30(b), rl30(c), W.at(27)); b = r1(c, d, rl30(e), rl30(a), rl30(b), W.at(28)); a = r1(b, c, rl30(d), rl30(e), rl30(a), W.at(29));
	e = r1(a, b, rl30(c), rl30(d), rl30(e), W.at(30)); d = r1(e, a, rl30(b), rl30(c), rl30(d), W.at(31)); c = r1(d, e, rl30(a), rl30(b), rl30(c), W.at(32)); b = r1(c, d, rl30(e), rl30(a), rl30(b), W.at(33)); a = r1(b, c, rl30(d), rl30(e), rl30(a), W.at(34));
	e = r1(a, b, rl30(c), rl30(d), rl30(e), W.at(35)); d = r1(e, a, rl30(b), rl30(c), rl30(d), W.at(36)); c = r1(d, e, rl30(a), rl30(b), rl30(c), W.at(37)); b = r1(c, d, rl30(e), rl30(a), rl30(b), W.at(38)); a = r1(b, c, rl30(d), rl30(e), rl30(a), W.at(39));
	e = r2(a, b, rl30(c), rl30(d), rl30(e), W.at(40)); d = r2(e, a, rl30(b), rl30(c), rl30(d), W.at(41)); c = r2(d, e, rl30(a), rl30(b), rl30(c), W.at(42)); b = r2(c, d, rl30(e), rl30(a), rl30(b), W.at(43)); a = r2(b, c, rl30(d), rl30(e), rl30(a), W.at(44));
	e = r2(a, b, rl30(c), rl30(d), rl30(e), W.at(45)); d = r2(e, a, rl30(b), rl30(c), rl30(d), W.at(46)); c = r2(d, e, rl30(a), rl30(b), rl30(c), W.at(47)); b = r2(c, d, rl30(e), rl30(a), rl30(b), W.at(48)); a = r2(b, c, rl30(d), rl30(e), rl30(a), W.at(49));
	e = r2(a, b, rl30(c), rl30(d), rl30(e), W.at(50)); d = r2(e, a, rl30(b), rl30(c), rl30(d), W.at(51)); c = r2(d, e, rl30(a), rl30(b), rl30(c), W.at(52)); b = r2(c, d, rl30(e), rl30(a), rl30(b), W.at(53)); a = r2(b, c, rl30(d), rl30(e), rl30(a), W.at(54));
	e = r2(a, b, rl30(c), rl30(d), rl30(e), W.at(55)); d = r2(e, a, rl30(b), rl30(c), rl30(d), W.at(56)); c = r2(d, e, rl30(a), rl30(b), rl30(c), W.at(57)); b = r2(c, d, rl30(e), rl30(a), rl30(b), W.at(58)); a = r2(b, c, rl30(d), rl30(e), rl30(a), W.at(59));
	e = r3(a, b, rl30(c), rl30(d), rl30(e), W.at(60)); d = r3(e, a, rl30(b), rl30(c), rl30(d), W.at(61)); c = r3(d, e, rl30(a), rl30(b), rl30(c), W.at(62)); b = r3(c, d, rl30(e), rl30(a), rl30(b), W.at(63)); a = r3(b, c, rl30(d), rl30(e), rl30(a), W.at(64));
	e = r3(a, b, rl30(c), rl30(d), rl30(e), W.at(65)); d = r3(e, a, rl30(b), rl30(c), rl30(d), W.at(66)); c = r3(d, e, rl30(a), rl30(b), rl30(c), W.at(67)); b = r3(c, d, rl30(e), rl30(a), rl30(b), W.at(68)); a = r3(b, c, rl30(d), rl30(e), rl30(a), W.at(69));
	e = r3(a, b, rl30(c), rl30(d), rl30(e), W.at(70)); d = r3(e, a, rl30(b), rl30(c), rl30(d), W.at(71)); c = r3(d, e, rl30(a), rl30(b), rl30(c), W.at(72)); b = r3(c, d, rl30(e), rl30(a), rl30(b), W.at(73)); a = r3(b, c, rl30(d), rl30(e), rl30(a), W.at(74));
	e = r3(a, b, rl30(c), rl30(d), rl30(e), W.at(75)); d = r3(e, a, rl30(b), rl30(c), rl30(d), W.at(76)); c = r3(d, e, rl30(a), rl30(b), rl30(c), W.at(77)); b = r3(c, d, rl30(e), rl30(a), rl30(b), W.at(78)); a = r3(b, c, rl30(d), rl30(e), rl30(a), W.at(79));
	c = rl30(c); d = rl30(d); e = rl30(e);
#endif
	// Add the working vars back into state[]
	state.a += a;
	state.b += b;
	state.c += c;
	state.d += d;
	state.e += e;
#endif
}

const uint32 *SHA1::terminate() {
	uint32	o = p & 63;
	block[o] = 0x80;
	memset(block + o + 1, 0, 63 - o);
	if (o > 64 - 8) {
		process(block);
		memset(block, 0, 64);
	}
	uint8	*len = block + 64;
	for (uint64 t = p * 8; t; t = t >> 8)
		*--len = t & 0xff;
	process(block);
	return &state.a;
}

//-----------------------------------------------------------------------------
//	SHA2
//-----------------------------------------------------------------------------

/*
Note 2: For each round, there is one round constant k[i] and one entry in the message schedule array w[i], 0 <= i <= 63
Note 3: The compression function uses 8 working variables, a through h
Note 4: Big-endian convention is used when expressing the constants in this pseudocode,
	and when parsing message block data from bytes to words, for example,
	the first word of the input message "abc" after padding is 0x61626380
*/

//512 bit chunk
template<> void SHA2<uint32>::process(const void *data) {
	//round constants (first 32 bits of the fractional parts of the cube roots of the first 64 primes 2..311) :
	static const uint32 k[64] = {
		0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
		0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
		0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
		0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
		0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
		0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
		0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
		0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
	};

	uint32		w[64];

	//copy chunk into first 16 words w[0..15] of the message schedule array
	copyn((uint32be*)data, w, 16);

	//extend the first 16 words into the remaining 48 words w[16..63] of the message schedule array:
	for (int i = 16; i < 64; i++) {
		uint32	s0 = rotate_right(w[i - 15], 7) ^ rotate_right(w[i - 15], 18) ^ (w[i - 15] >> 3);
		uint32	s1 = rotate_right(w[i - 2], 17) ^ rotate_right(w[i - 2], 19) ^ (w[i - 2] >> 10);
		w[i] = w[i - 16] + s0 + w[i - 7] + s1;
	}

	//Initialize working variables to current hash value:
	uint32	a = state[0];
	uint32	b = state[1];
	uint32	c = state[2];
	uint32	d = state[3];
	uint32	e = state[4];
	uint32	f = state[5];
	uint32	g = state[6];
	uint32	h = state[7];

	//Compression function main loop:
	for (int i = 0; i < 64; i++) {
		uint32	s1 = rotate_right(e, 6) ^ rotate_right(e, 11) ^ rotate_right(e, 25);
		uint32	ch = (e & f) ^ (~e & g);
		uint32	t1 = h + s1 + ch + k[i] + w[i];
		uint32	s0 = rotate_right(a, 2) ^ rotate_right(a, 13) ^ rotate_right(a, 22);
		uint32	maj = (a & b) ^ (a & c) ^ (b & c);
		uint32	t2 = s0 + maj;

		h = g;
		g = f;
		f = e;
		e = d + t1;
		d = c;
		c = b;
		b = a;
		a = t1 + t2;
	}

	//Add the compressed chunk to the current hash value:
	state[0] += a;
	state[1] += b;
	state[2] += c;
	state[3] += d;
	state[4] += e;
	state[5] += f;
	state[6] += g;
	state[7] += h;
}


inline uint64 ch(uint64 x, uint64 y, uint64 z)	{ return (x & y) | (~x & z); }
inline uint64 maj(uint64 x, uint64 y, uint64 z) { return (x & y) | (x & z) | (y & z); }
inline uint64 sigma1(uint64 x)					{ return rotate_right(x, 28) ^ rotate_right(x, 34) ^ rotate_right(x, 39); }
inline uint64 sigma2(uint64 x)					{ return rotate_right(x, 14) ^ rotate_right(x, 18) ^ rotate_right(x, 41); }
inline uint64 sigma3(uint64 x)					{ return rotate_right(x,  1) ^ rotate_right(x,  8) ^ (x >> 7); }
inline uint64 sigma4(uint64 x)					{ return rotate_right(x, 19) ^ rotate_right(x, 61) ^ (x >> 6); }


//1024 bit chunk
template<> void SHA2<uint64>::process(const void *data) {
	//round constants (first 32 bits of the fractional parts of the cube roots of the first 64 primes 2..311) :
	static const uint64 k[80] = {
		0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc, 0x3956c25bf348b538,
		0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242, 0x12835b0145706fbe,
		0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2, 0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235,
		0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
		0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5, 0x983e5152ee66dfab,
		0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725,
		0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed,
		0x53380d139d95b3df, 0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b,
		0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218,
		0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8, 0x19a4c116b8d2d0c8, 0x1e376c085141ab53,
		0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373,
		0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
		0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b, 0xca273eceea26619c,
		0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba, 0x0a637dc5a2c898a6,
		0x113f9804bef90dae, 0x1b710b35131c471b, 0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc,
		0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817,
	};

	uint64		w[16];
//	uint64		w[80];

	//copy chunk into first 16 words w[0..15] of the message schedule array
	copyn((uint64be*)data, w, 16);

#if 0
	//extend the first 16 words into the remaining 48 words w[16..63] of the message schedule array:
	for (int i = 16; i < 80; i++) {
		uint64	s0 = rotate_right(w[i - 15], 1) ^ rotate_right(w[i - 15], 8) ^ (w[i - 15] >> 7);
		uint64	s1 = rotate_right(w[i - 2], 17) ^ rotate_right(w[i - 2], 61) ^ (w[i - 2] >> 6);
		w[i] = w[i - 16] + s0 + w[i - 7] + s1;
	}
#endif

	//Initialize working variables to current hash value:
	uint64	a = state[0];
	uint64	b = state[1];
	uint64	c = state[2];
	uint64	d = state[3];
	uint64	e = state[4];
	uint64	f = state[5];
	uint64	g = state[6];
	uint64	h = state[7];

	//Compression function main loop:
	for (int i = 0; i < 80; i++) {
		if (i >= 16)
			w[i & 15] += sigma4(w[(i + 14) & 15]) + w[(i + 9) & 15] + sigma3(w[(i + 1) & 15]);

		uint64	t1 = h + sigma2(e) + ch(e, f, g) + k[i] + w[i & 15];
		uint64	t2 = sigma1(a) + maj(a, b, c);


//		uint64	s1 = rotate_right(e, 14) ^ rotate_right(e, 18) ^ rotate_right(e, 41);
//		uint64	ch = (e & f) ^ (~e & g);
//		uint64	t1 = h + s1 + ch + k[i] + w[i];
//		uint64	s0 = rotate_right(a, 28) ^ rotate_right(a, 34) ^ rotate_right(a, 39);
//		uint64	maj = (a & b) ^ (a & c) ^ (b & c);
//		uint64	t2 = s0 + maj;

		h = g;
		g = f;
		f = e;
		e = d + t1;
		d = c;
		c = b;
		b = a;
		a = t1 + t2;
	}

	//Add the compressed chunk to the current hash value:
	state[0] += a;
	state[1] += b;
	state[2] += c;
	state[3] += d;
	state[4] += e;
	state[5] += f;
	state[6] += g;
	state[7] += h;
}

template<> const uint32 SHA256::init_state[8] = { 0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19 };
template<> const uint32 SHA224::init_state[8] = { 0xc1059ed8, 0x367cd507, 0x3070dd17, 0xf70e5939, 0xffc00b31, 0x68581511, 0x64f98fa7, 0xbefa4fa4 };
template<> const uint64 SHA512::init_state[8] = { 0x6a09e667f3bcc908, 0xbb67ae8584caa73b, 0x3c6ef372fe94f82b, 0xa54ff53a5f1d36f1, 0x510e527fade682d1, 0x9b05688c2b3e6c1f, 0x1f83d9abfb41bd6b, 0x5be0cd19137e2179 };
template<> const uint64 SHA384::init_state[8] = { 0xcbbb9d5dc1059ed8, 0x629a292a367cd507, 0x9159015a3070dd17, 0x152fecd8f70e5939, 0x67332667ffc00b31, 0x8eb44a8768581511, 0xdb0c2e0d64f98fa7, 0x47b5481dbefa4fa4 };
