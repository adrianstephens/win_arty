#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Storage { namespace Compression {
struct ICompressor;
enum class CompressAlgorithm : int {
	InvalidAlgorithm = 0,
	NullAlgorithm = 1,
	Mszip = 2,
	Xpress = 3,
	XpressHuff = 4,
	Lzms = 5,
};
struct ICompressorFactory;
struct Compressor;
struct IDecompressor;
struct IDecompressorFactory;
struct Decompressor;
}}}
} // namespace iso_winrt
