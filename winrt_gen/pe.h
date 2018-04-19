#ifndef PE_H
#define PE_H

#include "base/defs.h"
#include "base/strings.h"
#include "base/pointer.h"

//-----------------------------------------------------------------------------
//	PORTABLE EXECUTABLE FORMAT
//-----------------------------------------------------------------------------
namespace pe {
//	DOS .EXE header

struct TIMEDATE {
//	iso::uint32	secs2:5, mins:6, hours:5, day:5, month:4, year1980:7;
	iso::uint32	secs_from1970;
};

struct DOS_HEADER : iso::littleendian {
	enum {MAGIC = 'ZM', PARAGRAPH = 16, PAGE = 512};
	uint16	magic;			//	Magic number
	uint16	cblp;			//	Bytes on last page of file
	uint16	cp;				//	Pages in file
	uint16	crlc;			//	Relocations
	uint16	cparhdr;		//	Size of header in paragraphs
	uint16	minalloc;		//	Minimum extra paragraphs needed
	uint16	maxalloc;		//	Maximum extra paragraphs needed
	uint16	ss;				//	Initial (relative) SS value
	uint16	sp;				//	Initial SP value
	uint16	csum;			//	Checksum
	uint16	ip;				//	Initial IP value
	uint16	cs;				//	Initial (relative) CS value
	uint16	lfarlc;			//	File address of relocation table
	uint16	ovno;			//	Overlay number
};

struct DOS_RELOC : iso::littleendian {
	uint16	offset;
	uint16	segment;
};

struct EXE_HEADER : DOS_HEADER {
	uint16	res[4];			//	Reserved words
	uint16	oemid;			//	OEM identifier (for e_oeminfo)
	uint16	oeminfo;		//	OEM information; e_oemid specific
	uint16	res2[10];		//	Reserved words
	int32	lfanew;			//	File address of new exe header
};

struct FILE_HEADER : iso::littleendian {
	uint16		Machine;
	uint16		NumberOfSections;
	TIMEDATE	TimeDateStamp;
	uint32		PointerToSymbolTable;
	uint32		NumberOfSymbols;
	uint16		SizeOfOptionalHeader;
	uint16		Characteristics;
};

enum MACHINE {
	MACHINE_UNKNOWN			= 0,
	MACHINE_I386			= 0x014c,	// Intel 386.
	MACHINE_R3000			= 0x0162,	// MIPS little-endian, 0x160 big-endian
	MACHINE_R4000			= 0x0166,	// MIPS little-endian
	MACHINE_R10000			= 0x0168,	// MIPS little-endian
	MACHINE_WCEMIPSV2		= 0x0169,	// MIPS little-endian WCE v2
	MACHINE_ALPHA			= 0x0184,	// Alpha_AXP
	MACHINE_SH3				= 0x01a2,	// SH3 little-endian
	MACHINE_SH3DSP			= 0x01a3,
	MACHINE_SH3E			= 0x01a4,	// SH3E little-endian
	MACHINE_SH4				= 0x01a6,	// SH4 little-endian
	MACHINE_SH5				= 0x01a8,	// SH5
	MACHINE_ARM				= 0x01c0,	// ARM Little-Endian
	MACHINE_THUMB			= 0x01c2,
	MACHINE_AM33			= 0x01d3,
	MACHINE_POWERPC			= 0x01F0,	// IBM PowerPC Little-Endian
	MACHINE_POWERPCFP		= 0x01f1,
	MACHINE_X360			= 0x01f2,
	MACHINE_IA64			= 0x0200,	// Intel 64
	MACHINE_MIPS16			= 0x0266,	// MIPS
	MACHINE_ALPHA64			= 0x0284,	// ALPHA64
	MACHINE_MIPSFPU			= 0x0366,	// MIPS
	MACHINE_MIPSFPU16		= 0x0466,	// MIPS
	MACHINE_AXP64			= MACHINE_ALPHA64,
	MACHINE_TRICORE			= 0x0520,	// Infineon
	MACHINE_CEF				= 0x0CEF,
	MACHINE_EBC				= 0x0EBC,	// EFI Byte Code
	MACHINE_AMD64			= 0x8664,	// AMD64 (K8)
	MACHINE_M32R			= 0x9041,	// M32R little-endian
	MACHINE_CEE				= 0xC0EE,
};

enum CHARACTERISTICS {
	RELOCS_STRIPPED			= 0x0001,
	EXECUTABLE_IMAGE		= 0x0002,
	LINE_NUMS_STRIPPED		= 0x0004,
	LOCAL_SYMS_STRIPPED		= 0x0008,
	AGGRESSIVE_WS_TRIM		= 0x0010,
	LARGE_ADDRESS_AWARE		= 0x0020,
	RESERVED				= 0x0040,
	BYTES_REVERSED_LO		= 0x0080,
	IS_32BIT				= 0x0100,
	DEBUG_STRIPPED			= 0x0200,
	REMOVABLE_RUN_FROM_SWAP	= 0x0400,
	NET_RUN_FROM_SWAP		= 0x0800,
	SYSTEM					= 0x1000,
	DLL						= 0x2000,
	UP_SYSTEM_ONLY			= 0x4000,
	BYTES_REVERSED_HI		= 0x8000,
};

struct DATA_DIRECTORY : iso::littleendian {
	uint32 VirtualAddress;
	uint32 Size;
};

struct OPTIONAL_HEADER : iso::littleendian {
	enum {
		MAGIC_NT32	= 0x10b,
		MAGIC_NT64	= 0x20b,
		MAGIC_ROM	= 0x107,
	};
	// Directory Entries
	enum {
		EXPORT			= 0,	// EXPORT_DIRECTORY		Export Directory
		IMPORT			= 1,	// IMPORT_DIRECTORY		Import Directory
		RESOURCE		= 2,	// Resource Directory
		EXCEPTION		= 3,	// Exception Directory
		SECURITY		= 4,	// Security Directory
		BASERELOC		= 5,	// Base Relocation Table
		DEBUG_DIR		= 6,	// Debug Directory
		COPYRIGHT		= 7,	// (X86 usage)
		ARCHITECTURE	= 7,	// Architecture Specific Data
		GLOBALPTR		= 8,	// RVA of GP
		TLS				= 9,
		LOAD_CONFIG		= 10,	// Load Configuration Directory
		BOUND_IMPORT	= 11,	// Bound Import Directory in headers
		IAT				= 12,	// Import Address Table
		DELAY_IMPORT	= 13,
		CLR_DESCRIPTOR	= 14,
	};
	uint16	Magic;
	uint8	MajorLinkerVersion;
	uint8	MinorLinkerVersion;
	uint32	SizeOfCode;
	uint32	SizeOfInitializedData;
	uint32	SizeOfUninitializedData;
	uint32	AddressOfEntryPoint;
	uint32	BaseOfCode;
};

struct OPTIONAL_HEADER32 : OPTIONAL_HEADER {
	uint32	BaseOfData;
	uint32	ImageBase;
	uint32	SectionAlignment;
	uint32	FileAlignment;
	uint16	MajorOperatingSystemVersion;
	uint16	MinorOperatingSystemVersion;
	uint16	MajorImageVersion;
	uint16	MinorImageVersion;
	uint16	MajorSubsystemVersion;
	uint16	MinorSubsystemVersion;
	uint32	Win32VersionValue;
	uint32	SizeOfImage;
	uint32	SizeOfHeaders;
	uint32	CheckSum;
	uint16	Subsystem;
	uint16	DllCharacteristics;
	uint32	SizeOfStackReserve;
	uint32	SizeOfStackCommit;
	uint32	SizeOfHeapReserve;
	uint32	SizeOfHeapCommit;
	uint32	LoaderFlags;
	uint32	NumberOfRvaAndSizes;
	DATA_DIRECTORY DataDirectory[16];
};

struct OPTIONAL_HEADER64 : OPTIONAL_HEADER {
	uint64	ImageBase;
	uint32	SectionAlignment;
	uint32	FileAlignment;
	uint16	MajorOperatingSystemVersion;
	uint16	MinorOperatingSystemVersion;
	uint16	MajorImageVersion;
	uint16	MinorImageVersion;
	uint16	MajorSubsystemVersion;
	uint16	MinorSubsystemVersion;
	uint32	Win32VersionValue;
	uint32	SizeOfImage;
	uint32	SizeOfHeaders;
	uint32	CheckSum;
	uint16	Subsystem;
	uint16	DllCharacteristics;
	uint64	SizeOfStackReserve;
	uint64	SizeOfStackCommit;
	uint64	SizeOfHeapReserve;
	uint64	SizeOfHeapCommit;
	uint32	LoaderFlags;
	uint32	NumberOfRvaAndSizes;
	DATA_DIRECTORY DataDirectory[16];
};

//EXPORT
struct EXPORT_DIRECTORY : iso::littleendian {
	uint32		ExportFlags;			// Reserved, must be 0.
	TIMEDATE	TimeDateStamp;			// The time and date that the export data was created.
	xint16		MajorVersion;			// The major version number. The major and minor version numbers can be set by the user.
	xint16		MinorVersion;			// The minor version number.
	xint32		DLLName;				// The address of the ASCII string that contains the name of the DLL. This address is relative to the image base.
	uint32		OrdinalBase;			// The starting ordinal number for exports in this image. This field specifies the starting ordinal number for the export address table. It is usually set to 1.
	uint32		NumberEntries;			// The number of entries in the export address table.
	uint32		NumberNames;			// The number of entries in the name pointer table. This is also the number of entries in the ordinal table.
	xint32		FunctionTable;			// RVA of functions
	xint32		NameTable;				// RVA of names
	xint32		OrdinalTable;			// RVA from base of image
};

//IMPORT
struct IMPORT_DIRECTORY : iso::littleendian {
	struct DESCRIPTOR {
		union {
			uint32	Characteristics;	// 0 for terminating null import descriptor
			uint32	OriginalFirstThunk;	// RVA to original unbound IAT (PIMAGE_THUNK_DATA)
		};
		TIMEDATE	TimeDateStamp;			// 0 if not bound, -1 if bound, and real date\time stamp in IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT (new BIND)	// O.W. date/time stamp of DLL bound to (Old BIND)
		uint32		ForwarderChain;			// -1 if no forwarders
		uint32		DllName;
		uint32		FirstThunk;				// RVA to IAT (if bound this IAT has actual addresses)
	};

	struct BY_NAME {
		uint16		hint;
		const char	name[];
	};

	struct THUNK_DATA64 {
		static const uint64 ORDINAL = 0x8000000000000000ull;
		union {
			uint64 ForwarderString;	// PBYTE 
			uint64 Function;		// Puint32
			uint64 Ordinal;
			uint64 AddressOfData;	// PIMAGE_IMPORT_BY_NAME
		};
		bool is_ordinal()	const	{ return !!(Ordinal & ORDINAL); }
		bool exists()		const	{ return Ordinal != 0; }
	};

	struct THUNK_DATA32 {
		static const uint32 ORDINAL = 0x80000000;
		union {
			uint32 ForwarderString;	// PBYTE 
			uint32 Function;		// Puint32
			uint32 Ordinal;
			uint32 AddressOfData;	// PIMAGE_IMPORT_BY_NAME
		};
		bool is_ordinal()	const	{ return !!(Ordinal & ORDINAL); }
		bool exists()		const	{ return Ordinal != 0; }
	};

	DESCRIPTOR	desc[];
};

//TLS
struct TLS_DIRECTORY64 : iso::littleendian {
	typedef	void TLS_CALLBACK(void *DllHandle, uint32 Reason, void *Reserved);
	xint64	StartAddressOfRawData;
	xint64	EndAddressOfRawData;
	xint64	AddressOfIndex;		  // Puint32
	xint64	AddressOfCallBacks;	  // TLS_CALLBACK**;
	xint32	SizeOfZeroFill;
	union {
		uint32	Characteristics;
		struct {
			uint32 Reserved0	: 20;
			uint32 Alignment	: 4;
			uint32 Reserved1	: 8;
		};
	};
};

struct TLS_DIRECTORY32 : iso::littleendian {
	typedef	void TLS_CALLBACK(void *DllHandle, uint32 Reason, void *Reserved);
	xint32	StartAddressOfRawData;
	xint32	EndAddressOfRawData;
	xint32	AddressOfIndex;			// Puint32
	xint32	AddressOfCallBacks;		// TLS_CALLBACK**
	xint32	SizeOfZeroFill;
	union {
		uint32 Characteristics;
		struct {
			uint32 Reserved0	: 20;
			uint32 Alignment	: 4;
			uint32 Reserved1	: 8;
		};
	};
};

//BOUND_IMPORT
struct BOUND_IMPORT_DIRECTORY : iso::littleendian {
	struct DESCRIPTOR {
		struct REF {
			TIMEDATE	TimeDateStamp;
			iso::offset_pointer<char, uint16, BOUND_IMPORT_DIRECTORY>	ModuleName;
			uint16		Reserved;
		};

		TIMEDATE	TimeDateStamp;
		iso::offset_pointer<char, uint16, BOUND_IMPORT_DIRECTORY>	ModuleName;
		uint16		NumberOfModuleForwarderRefs;
		REF			Refs[1];
		const DESCRIPTOR *next() const { return (const DESCRIPTOR*)&Refs[NumberOfModuleForwarderRefs]; }
	};
	DESCRIPTOR	desc[];
};

//DELAY_IMPORT
struct DELAY_IMPORT_DIRECTORY : iso::littleendian {
	struct DESCRIPTOR {
		union {
			uint32 AllAttributes;
			struct {
				uint32 RvaBased				: 1;	// Delay load version 2
				uint32 ReservedAttributes	: 31;
			};
		};

		xint32		DllName;						// RVA to the name of the target library (NULL-terminate ASCII string)
		xint32		ModuleHandle;					// RVA to the HMODULE caching location (PHMODULE)
		xint32		ImportAddressTable;				// RVA to the start	of the IAT (PIMAGE_THUNK_DATA)
		xint32		ImportNameTable;				// RVA to the start	of the name	table (PIMAGE_THUNK_DATA::AddressOfData)
		xint32		BoundImportAddressTable;		// RVA to an optional bound	IAT
		xint32		UnloadInformationTable;			// RVA to an optional unload info table
		TIMEDATE	TimeDateStamp;					// 0 if	not	bound, otherwise, date/time	of the target DLL
	};
	DESCRIPTOR	desc[];
};

//DEBUG_DIR
struct DEBUG_DIRECTORY : iso::littleendian {
	enum TYPE {
		UNKNOWN			= 0,
		COFF			= 1,
		CODEVIEW		= 2,
		FPO				= 3,
		MISC			= 4,
		EXCEPTION		= 5,
		FIXUP			= 6,
		OMAP_TO_SRC		= 7,
		OMAP_FROM_SRC	= 8,
		BORLAND			= 9,
		RESERVED10		= 10,
		CLSID			= 11,
		VC_FEATURE		= 12,
		POGO			= 13,
		ILTCG			= 14,
		MPX				= 15,
	};
	uint32		Characteristics;
	TIMEDATE	TimeDateStamp;
	xint16		MajorVersion;
	xint16		MinorVersion;
	xint32		Type;
	xint32		SizeOfData;
	xint32		AddressOfRawData;
	xint32		PointerToRawData;
};

//LOAD_CONFIG
struct CODE_INTEGRITY : iso::littleendian {
	xint16		Flags;
	xint16		Catalog;			// 0xFFFF means not available
	xint32		CatalogOffset;
	xint32		Reserved;
};

struct LOAD_CONFIG_DIRECTORY32 : iso::littleendian {
	uint32		Size;
	TIMEDATE	TimeDateStamp;
	xint16		MajorVersion;
	xint16		MinorVersion;
	xint32		GlobalFlagsClear;
	xint32		GlobalFlagsSet;
	xint32		CriticalSectionDefaultTimeout;
	xint32		DeCommitFreeBlockThreshold;
	xint32		DeCommitTotalFreeThreshold;
	xint32		LockPrefixTable;
	xint32		MaximumAllocationSize;
	xint32		VirtualMemoryThreshold;
	xint32		ProcessHeapFlags;
	xint32		ProcessAffinityMask;
	xint16		CSDVersion;
	xint16		Reserved1;
	xint32		EditList;
	xint32		SecurityCookie;
	xint32		SEHandlerTable;
	xint32		SEHandlerCount;
	xint32		GuardCFCheckFunctionPointer;
	xint32		GuardCFDispatchFunctionPointer;
	xint32		GuardCFFunctionTable;
	xint32		GuardCFFunctionCount;
	xint32		GuardFlags;
	CODE_INTEGRITY CodeIntegrity;
};

struct LOAD_CONFIG_DIRECTORY64 : iso::littleendian {
	uint32		Size;
	TIMEDATE	TimeDateStamp;
	xint16		MajorVersion;
	xint16		MinorVersion;
	xint32		GlobalFlagsClear;
	xint32		GlobalFlagsSet;
	xint32		CriticalSectionDefaultTimeout;
	xint64		DeCommitFreeBlockThreshold;
	xint64		DeCommitTotalFreeThreshold;
	xint64		LockPrefixTable;
	xint64		MaximumAllocationSize;
	xint64		VirtualMemoryThreshold;
	xint64		ProcessAffinityMask;
	xint32		ProcessHeapFlags;
	xint16		CSDVersion;
	xint16		Reserved1;
	xint64		EditList;
	xint64		SecurityCookie;
	xint64		SEHandlerTable;
	xint64		SEHandlerCount;
	xint64		GuardCFCheckFunctionPointer;
	xint64		GuardCFDispatchFunctionPointer;
	xint64		GuardCFFunctionTable;
	xint64		GuardCFFunctionCount;
	xint32		GuardFlags;
	CODE_INTEGRITY CodeIntegrity;
};

//EXCEPTION
struct EXCEPTION_DIRECTORY : iso::littleendian {
	struct CE_ENTRY {
		xint32 FuncStart;
		uint32 PrologLen:8, FuncLen:22, ThirtyTwoBit:1, ExceptionFlag:1;
	};
	struct ARM_ENTRY {
		xint32 BeginAddress;
		uint32 Flag:2, FunctionLength:11, Ret:2, H:1, Reg:3, R:1, L:1, C:1, StackAdjust:10;
	};
	struct ARM64_ENTRY {
		xint32 BeginAddress;
		uint32 Flag:2, FunctionLength:11, RegF:3, RegI:4, H:1, CR:2, FrameSize:9;
	};
	struct ALPHA64_ENTRY {
		xint64 BeginAddress;
		xint64 EndAddress;
		xint64 ExceptionHandler;
		xint64 HandlerData;
		xint64 PrologEndAddress;
	};
	struct ALPHA_ENTRY {
		xint32 BeginAddress;
		xint32 EndAddress;
		xint32 ExceptionHandler;
		xint32 HandlerData;
		xint32 PrologEndAddress;
	};
	struct ENTRY {
		xint32 BeginAddress;
		xint32 EndAddress;
		xint32 UnwindInfoAddress;
	};
	ENTRY	Entries[];
};

enum UNWIND_OP {
	UWOP_PUSH_NONVOL		= 0,	//1 node		Push a nonvolatile integer register, decrementing RSP by 8. info indicates register: RAX=0,RCX=1,RDX=2,RBX=3,RSP=4,RBP=5,RSI=6,RDI=7,R8 to R15=8..15
	UWOP_ALLOC_LARGE		= 1,	//2 or 3 nodes	Allocate area on the stack. info=0: size = next slot * 8; info=1: size = next two slots
	UWOP_ALLOC_SMALL		= 2,	//1 node		Allocate area on the stack of info * 8 + 8
	UWOP_SET_FPREG			= 3,	//1 node		Set frame pointer register as rsp + offset*16
	UWOP_SAVE_NONVOL		= 4,	//2 nodes		Save a nonvolatile integer register on the stack. info = register, offset = next*8
	UWOP_SAVE_NONVOL_FAR	= 5,	//3 nodes		Save a nonvolatile integer register on the stack. info = register, offset = next 2 slots
	UWOP_SAVE_XMM128		= 8,	//2 nodes		Save all 128 bits of a nonvolatile XMM register on the stack. info = register, offset = next * 16
	UWOP_SAVE_XMM128_FAR	= 9,	//3 nodes		Save all 128 bits of a nonvolatile XMM register on the stack. info = register, offset = next 2 slots
	UWOP_PUSH_MACHFRAME		= 10,	//1 node		Push a machine frame. info = 0 => stack: RSP+32, SS, RSP+24, Old RSP, RSP+16, EFLAGS, RSP+8, CS, RSP, RIP; info = 1 => stack: RSP+40, SS, RSP+32, Old RSP, RSP+24, EFLAGS, RSP+16, CS, RSP+8, RIP, RSP, Error code
};

struct UNWIND_INFO : iso::littleendian {
	enum FLAGS {
		EHANDLER	= 1 << 0,	// function has an exception handler - called when looking for functions that need to examine exceptions
		UHANDLER	= 1 << 1,	// function has a termination handler - called when unwinding an exception
		CHAINED		= 1 << 2,	// this is a copy of a previous EXCEPTION_DIRECTORY::ENTRY for chaining
	};
	struct HANDLER {
		xint32	address;
		uint8	variable[];
	};
	union CODE {
		struct {
			uint8	prolog_offset;
			uint8	unwind_code:4, info:4;
		};
		uint16	u;
	};
	uint8	version:3, flags:5;
	uint8	prolog_size;	// Length of the function prolog in bytes
	uint8	num_codes;
	uint8	frame_reg:4, frame_offset:4;
	CODE	codes[];
	// HANDLER or chained EXCEPTION_DIRECTORY::ENTRY
};

struct SECTION_HEADER :	iso::littleendian {
	char	Name[8];
	xint32	VirtualSize;	// or PhysicalAddress
	xint32	VirtualAddress;
	xint32	SizeOfRawData;
	xint32	PointerToRawData;
	xint32	PointerToRelocations;
	xint32	PointerToLinenumbers;
	int16	NumberOfRelocations;
	int16	NumberOfLinenumbers;
	xint32	Characteristics;
};

enum SCN_CHARACTERISTICS {
//	SCN_						= 0x00000000,
//	SCN_						= 0x00000001,
//	SCN_						= 0x00000002,
//	SCN_						= 0x00000004,
	SCN_TYPE_NO_PAD				= 0x00000008,
//	SCN_						= 0x00000010,
	SCN_CNT_CODE				= 0x00000020,
	SCN_CNT_INITIALIZED_DATA	= 0x00000040,
	SCN_CNT_UNINITIALIZED_DATA	= 0x00000080,
	SCN_LNK_OTHER				= 0x00000100,
	SCN_LNK_INFO				= 0x00000200,
//	SCN_						= 0x00000400,
	SCN_LNK_REMOVE				= 0x00000800,
	SCN_LNK_COMDAT				= 0x00001000,
	SCN_GPREL					= 0x00008000,
	SCN_MEM_PURGEABLE			= 0x00020000,
	SCN_MEM_16BIT				= 0x00020000,
	SCN_MEM_LOCKED				= 0x00040000,
	SCN_MEM_PRELOAD				= 0x00080000,
	SCN_ALIGN_1BYTES			= 0x00100000,
	SCN_ALIGN_2BYTES			= 0x00200000,
	SCN_ALIGN_4BYTES			= 0x00300000,
	SCN_ALIGN_8BYTES			= 0x00400000,
	SCN_ALIGN_16BYTES			= 0x00500000,
	SCN_ALIGN_32BYTES			= 0x00600000,
	SCN_ALIGN_64BYTES			= 0x00700000,
	SCN_ALIGN_128BYTES			= 0x00800000,
	SCN_ALIGN_256BYTES			= 0x00900000,
	SCN_ALIGN_512BYTES			= 0x00A00000,
	SCN_ALIGN_1024BYTES			= 0x00B00000,
	SCN_ALIGN_2048BYTES			= 0x00C00000,
	SCN_ALIGN_4096BYTES			= 0x00D00000,
	SCN_ALIGN_8192BYTES			= 0x00E00000,
	SCN_LNK_NRELOC_OVFL			= 0x01000000,
	SCN_MEM_DISCARDABLE			= 0x02000000,
	SCN_MEM_NOT_CACHED			= 0x04000000,
	SCN_MEM_NOT_PAGED			= 0x08000000,
	SCN_MEM_SHARED				= 0x10000000,
	SCN_MEM_EXECUTE				= 0x20000000,
	SCN_MEM_READ				= 0x40000000,
	SCN_MEM_WRITE				= 0x80000000,
};

//-----------------------------------------------------------------------------
//	symbols
//-----------------------------------------------------------------------------

struct SYMBOL_NAME : iso::littleendian {
	union {
		char	ShortName[8];
		struct {
			uint32	Short;		// if 0, use LongName
			uint32	Long;		// offset into string table
		};
	};
	bool	is_short()	{
		return Short != 0;
	}
	bool	set_short(const char *v)	{
		char	*d = ShortName;
		while (d < ShortName + 8 && (*d++ = *v))
			++v;
		if (*v)
			return false;
		while (d < ShortName + 8)
			*d++ = 0;
		return true;
	}
};

struct SYMBOL : iso::packed_types<iso::littleendian> {
	SYMBOL_NAME	Name;
	uint32		Value;
	int16		SectionNumber;
	uint16		Type;
	uint8		StorageClass;
	uint8		NumberOfAuxSymbols;
	SYMBOL()	{}
};

enum SYM_SECTION {
	SYM_UNDEFINED				= 0,
	SYM_ABSOLUTE				= -1,
	SYM_DEBUG					= -2,
};

// NOTE: types not really used
enum SYM_TYPE {
	SYM_TYPE_NULL				= 0,
	SYM_TYPE_VOID				= 1,
	SYM_TYPE_CHAR				= 2,
	SYM_TYPE_SHORT				= 3,
	SYM_TYPE_INT				= 4,
	SYM_TYPE_LONG				= 5,
	SYM_TYPE_FLOAT				= 6,
	SYM_TYPE_DOUBLE				= 7,
	SYM_TYPE_STRUCT				= 8,
	SYM_TYPE_UNION				= 9,
	SYM_TYPE_ENUM				= 10,
	SYM_TYPE_MOE				= 11,
	SYM_TYPE_BYTE				= 12,
	SYM_TYPE_WORD				= 13,
	SYM_TYPE_UINT				= 14,
	SYM_TYPE_uint32				= 15,
	SYM_TYPE_PCODE				= 0x8000,
	
	SYM_TYPE_NORMAL				= 0x20,//?
};

enum SYM_DTYPE {
	SYM_DTYPE_NULL				= 0,
	SYM_DTYPE_POINTER			= 1,
	SYM_DTYPE_FUNCTION			= 2,
	SYM_DTYPE_ARRAY				= 3,
};

enum SYM_CLASS {
	SYM_CLASS_END_OF_FUNCTION	= 0xFF,
	SYM_CLASS_NULL				= 0,
	SYM_CLASS_AUTOMATIC			= 1,
	SYM_CLASS_EXTERNAL			= 2,
	SYM_CLASS_STATIC			= 3,
	SYM_CLASS_REGISTER			= 4,
	SYM_CLASS_EXTERNAL_DEF		= 5,
	SYM_CLASS_LABEL				= 6,
	SYM_CLASS_UNDEFINED_LABEL	= 7,
	SYM_CLASS_MEMBER_OF_STRUCT	= 8,
	SYM_CLASS_ARGUMENT			= 9,
	SYM_CLASS_STRUCT_TAG		= 10,
	SYM_CLASS_MEMBER_OF_UNION	= 11,
	SYM_CLASS_UNION_TAG			= 12,
	SYM_CLASS_TYPE_DEFINITION	= 13,
	SYM_CLASS_UNDEFINED_STATIC	= 14,
	SYM_CLASS_ENUM_TAG			= 15,
	SYM_CLASS_MEMBER_OF_ENUM	= 16,
	SYM_CLASS_REGISTER_PARAM	= 17,
	SYM_CLASS_BIT_FIELD			= 18,
	SYM_CLASS_BLOCK				= 100,
	SYM_CLASS_FUNCTION			= 101,
	SYM_CLASS_END_OF_STRUCT		= 102,
	SYM_CLASS_FILE				= 103,
	SYM_CLASS_SECTION			= 104,
	SYM_CLASS_WEAK_EXTERNAL		= 105,
	SYM_CLASS_CLR_TOKEN			= 107,
};

struct AUXSYMBOL_FUNC : iso::packed_types<iso::littleendian> {
	uint32	TagIndex;
	uint32	TotalSize;
	uint32	PointerToLinenumber;
	uint32	PointerToNextFunction;
	uint16	Unused;
};

struct AUXSYMBOL_BFEF : iso::packed_types<iso::littleendian> {
	uint32	Unused;
	uint16	Linenumber;
	uint16	Unused2[3];
	uint32	PointerToNextFunction;// (.bf only)
	uint16	Unused3;
};

struct AUXSYMBOL_WEAK : iso::packed_types<iso::littleendian> {
	uint32	TagIndex;
	uint32	Characteristics;
	uint16	Unused[5];
};

struct AUXSYMBOL_FILE {
	char	FileName[18];
};

struct AUXSYMBOL_SECT : iso::packed_types<iso::littleendian> {
	uint32	Length;
	uint16	NumberOfRelocations;
	uint16	NumberOfLinenumbers;
	uint32	CheckSum;
	uint16	Number;
	uint8	Selection;
	uint8	Unused[3];
};

enum COMDAT_SECTION {
	COMDAT_SELECT_NODUPLICATES	= 1,
	COMDAT_SELECT_ANY			= 2,
	COMDAT_SELECT_SAME_SIZE		= 3,
	COMDAT_SELECT_EXACT_MATCH	= 4,
	COMDAT_SELECT_ASSOCIATIVE	= 5,
	COMDAT_SELECT_LARGEST		= 6,
};

//-----------------------------------------------------------------------------
//	resources
//-----------------------------------------------------------------------------

enum RESOURCE_TYPE {
	IRT_NONE			= 0,
	IRT_CURSOR			= 1,
	IRT_BITMAP			= 2,
	IRT_ICON			= 3,
	IRT_MENU			= 4,
	IRT_DIALOG			= 5,
	IRT_STRING			= 6,
	IRT_FONTDIR			= 7,
	IRT_FONT			= 8,
	IRT_ACCELERATOR		= 9,
	IRT_RCDATA			= 10,
	IRT_MESSAGETABLE	= 11,
	IRT_GROUP_CURSOR	= 12,
	IRT_GROUP_ICON		= 14,
	IRT_VERSION			= 16,
	IRT_DLGINCLUDE		= 17,
	IRT_PLUGPLAY		= 19,
	IRT_VXD				= 20,
	IRT_ANICURSOR		= 21,
	IRT_ANIICON			= 22,
	IRT_HTML			= 23,
	IRT_MANIFEST		= 24,
	IRT_TOOLBAR			= 241,
};

struct RESOURCE_DIRECTORY_ENTRY : iso::littleendian {
	union {
		struct {
			uint32 NameOffset:31;
			uint32 NameIsString:1;
		};
		uint32	Name;
		uint16	Id;
	};
	union {
		uint32	OffsetToData;
		struct {
			uint32	OffsetToDirectory:31;
			uint32	DataIsDirectory:1;
		};
	};
};

struct RESOURCE_DIR_STRING : iso::littleendian {
	uint16		Length;
	char		NameString[1];
};

struct RESOURCE_DIR_STRING_U : iso::littleendian {
	uint16		Length;
	wchar_t		NameString[1];
};

struct RESOURCE_DATA_ENTRY : iso::littleendian {
	uint32		OffsetToData;
	uint32		Size;
	uint32		CodePage;
	uint32		Reserved;
};

struct RESOURCE_DIRECTORY : iso::littleendian {
	uint32		Characteristics;
	TIMEDATE	TimeDateStamp;
	uint16		MajorVersion;
	uint16		MinorVersion;
	uint16		NumberOfNamedEntries;
	uint16		NumberOfIdEntries;
	int			size() const { return NumberOfIdEntries + NumberOfNamedEntries; }
	iso::range<const RESOURCE_DIRECTORY_ENTRY*>	entries() const { return iso::make_range_n((const RESOURCE_DIRECTORY_ENTRY*)(this + 1), NumberOfIdEntries + NumberOfNamedEntries); }
};

struct RESOURCE_ICONDIR : iso::littleendian {
	enum TYPE {
		ICON	= 1,
		CURSOR	= 2,
	};
	struct ENTRY {
		iso::uint8	Width;
		iso::uint8	Height;
		iso::uint8	ColorCount;
		iso::uint8	Reserved;		// Reserved (must be 0)
		uint16		Planes;			// Color Planes
		uint16		BitCount;		// Bits per pixel
		uint32		BytesInRes;
		uint32		ImageOffset;
	};
	uint16	Reserved;
	uint16	Type;
	uint16	Count;
	iso::range<const ENTRY*>	entries() const { return iso::make_range_n((const ENTRY*)(this + 1), Count); }
	bool	valid()		const { return Reserved == 0 && (Type == ICON || Type == CURSOR); }
};

} // namespace pe


//-----------------------------------------------------------------------------
//	COFF
//-----------------------------------------------------------------------------

namespace coff {

struct IMPORT_HEADER : iso::littleendian {
	enum TYPE {
		CODE			= 0,
		DATA			= 1,
		CONSTANT		= 2,
	};
	enum NAME_TYPE {
		ORDINAL			= 0,	// Import by ordinal
		NAME			= 1,	// Import name == public symbol name.
		NAME_NO_PREFIX	= 2,	// Import name == public symbol name skipping leading ?, @, or optionally _.
		NAME_UNDECORATE	= 3,	// Import name == public symbol name skipping leading ?, @, or optionally _ and truncating at first @
	};
	union {
		uint16	Ordinal;	// if grf & IMPORT_OBJECT_ORDINAL
		uint16	Hint;
	};
	uint16	flags;//Type:2, NameType:3, Reserved:11;
};

struct ANON_HEADER : iso::littleendian {
	uint16			Sig1;				// Must be MACHINE_UNKNOWN
	uint16			Sig2;				// Must be 0xffff
	uint16			Version;			// >= 1 (implies the CLSID field is present); >= 2 (implies the Flags field is present - otherwise V1)
	uint16			Machine;
	pe::TIMEDATE	TimeDateStamp;
//	GUID			ClassID;			// only if Version >= 1
//	uint32			SizeOfData;
//	uint32			Flags;				// Version >= 2; 0x1 -> contains metadata
//	uint32			MetaDataSize;		// Size of CLR metadata
//	uint32			MetaDataOffset;		// Offset of CLR metadata
};

struct ANON_XBOXONE : iso::littleendian {
	static constexpr GUID guid = {0x0CB3FE38, 0xD9A5, 0x4DAB, {0xAC, 0x9B, 0xd6, 0xb6, 0x22, 0x26, 0x53, 0xc2}};
	uint32			a;	//00070C13
	pe::TIMEDATE	TimeDateStamp;
	uint32			b;	//004652CF
	uint32			c;	//00000010
	uint32			d;	//00000000
};

struct ANON_BIGOBJ : iso::littleendian {
	static constexpr GUID guid = {0xD1BAA1C7, 0xBAEE, 0x4ba9, {0xAF, 0x20, 0xFA, 0xF6, 0x6A, 0xA4, 0xDC, 0xB8}};
	uint32	NumberOfSections;
	uint32	PointerToSymbolTable;
	uint32	NumberOfSymbols;
};

struct SYMBOL_BIGOBJ : iso::packed_types<iso::littleendian> {
	pe::SYMBOL_NAME	Name;
	uint32		Value;
	uint32		SectionNumber;
	uint16		Type;
	uint8		StorageClass;
	uint8		NumberOfAuxSymbols;
};

//{0CB3FE38-D9A5-4DAB-AC9B-D6B6222653C2}

} // namespace coff
#endif	//PE_H
