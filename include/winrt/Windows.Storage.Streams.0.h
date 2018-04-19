#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Storage { namespace Streams {
enum class ByteOrder : int {
	LittleEndian = 0,
	BigEndian = 1,
};
enum class UnicodeEncoding : int {
	Utf8 = 0,
	Utf16LE = 1,
	Utf16BE = 2,
};
struct DataReaderLoadOperation;
enum class InputStreamOptions : unsigned {
	None = 0x0,
	Partial = 0x1,
	ReadAhead = 0x2,
};
struct IDataReader;
struct IDataReaderFactory;
struct IDataReaderStatics;
struct DataReader;
struct DataWriterStoreOperation;
struct IDataWriter;
struct IDataWriterFactory;
struct DataWriter;
struct IBufferFactory;
struct IBufferStatics;
struct IBuffer;
struct Buffer;
struct IContentTypeProvider;
struct IInputStream;
struct IOutputStream;
struct IRandomAccessStream;
struct IRandomAccessStreamWithContentType;
struct IRandomAccessStreamReference;
struct IRandomAccessStreamStatics;
struct RandomAccessStream;
struct IInputStreamReference;
struct IRandomAccessStreamReferenceStatics;
struct RandomAccessStreamReference;
enum class FileOpenDisposition : int {
	OpenExisting = 0,
	OpenAlways = 1,
	CreateNew = 2,
	CreateAlways = 3,
	TruncateExisting = 4,
};
struct IFileRandomAccessStreamStatics;
struct FileRandomAccessStream;
struct FileInputStream;
struct FileOutputStream;
struct RandomAccessStreamOverStream;
struct InputStreamOverStream;
struct OutputStreamOverStream;
struct InMemoryRandomAccessStream;
}}}
} // namespace iso_winrt