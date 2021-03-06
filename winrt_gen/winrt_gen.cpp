#include "base/strings.h"
#include "base/array.h"
#include "base/hash.h"
#include "filename.h"
#include "stream.h"
#include "clr.h"
#include "pe.h"

using namespace iso;

struct Options {
	bool	help, version, quiet;
	void	SetOption(const char *line) {
		switch (line[1]) {
			case 'v':
				version	= true;
				break;
			default:
				help	= true;
				break;
		}
	}
	Options() {
		clear(*this);
	}
};

struct CommandLine : array<string, 3>, Options {
	bool				checkdate;

	CommandLine(int argc, const char *argv[]);

	void	printf(const char *format, ...) {
		if (!quiet) {
			va_list valist;
			va_start(valist, format);
			fixed_string<512>	fs(format, valist);
			_iso_debug_print(fs);
		}
	}
	bool	CheckDate(const filename &fn1, const filename &fn2);
};

CommandLine::CommandLine(int argc, const char *argv[]) {
	for (int i = 0; i < argc; i++) {
		const char	*line	= argv[i];
		if (*line == '-') {
			SetOption(line);

		} else if (size() < capacity()) {
			push_back(line);
		}
	}
}

void MakeMDH(const clr::METADATA &md, string_accum &sa0, string_accum &sa, const dynamic_array<const char*> &namespaces);

streamptr RVA(dynamic_array<pe::SECTION_HEADER>	&sections, uint64 rva) {
	for (auto &i : sections) {
		if (between(rva, i.VirtualAddress, i.VirtualAddress + i.SizeOfRawData))
			return rva - i.VirtualAddress + i.PointerToRawData;
	}
	return 0;
}

void Process(const filename &winmd, const filename &dest) {
	create_dir(dest);

	FileInput	file(winmd);

	pe::EXE_HEADER	hdr;
	file.read(hdr);
	if (hdr.magic != pe::DOS_HEADER::MAGIC)
		return;

	file.seek(hdr.lfanew);
	if (file.get<uint32be>() != ('PE' << 16))
		return;
	
	pe::FILE_HEADER		header;
	malloc_block		opt;
	dynamic_array<pe::SECTION_HEADER>	sections;

	file.read(header);
	if (header.SizeOfOptionalHeader)
		opt = malloc_block(file, header.SizeOfOptionalHeader);
	
	sections.read(file, header.NumberOfSections);

	malloc_block		clr_descriptor;
	if (pe::OPTIONAL_HEADER	*opt0 = opt) {
		if (opt0->Magic == pe::OPTIONAL_HEADER::MAGIC_NT32) {
			pe::OPTIONAL_HEADER32	*opt32	= opt;
			auto	&dd = opt32->DataDirectory[pe::OPTIONAL_HEADER::CLR_DESCRIPTOR];
			file.seek(RVA(sections, dd.VirtualAddress));
			clr_descriptor = malloc_block(file, dd.Size);

		} else if (opt0->Magic == pe::OPTIONAL_HEADER::MAGIC_NT64) {
			pe::OPTIONAL_HEADER64	*opt64	= opt;
			auto	&dd = opt64->DataDirectory[pe::OPTIONAL_HEADER::CLR_DESCRIPTOR];
			file.seek(RVA(sections, dd.VirtualAddress));
			clr_descriptor = malloc_block(file, dd.Size);
		}
	}

	if (clr::HEADER *header = clr_descriptor) {
		file.seek(RVA(sections, header->MetaData.VirtualAddress));
		malloc_block		meta_data(file, header->MetaData.Size);
		clr::METADATA_ROOT	*meta_root	= meta_data;
		clr::TABLES			*tables		= 0;
		clr::METADATA		md;

		for (auto &h : meta_root->Headers()) {
			memory_block	mem((char*)meta_root + h.Offset, h.Size);
			if (str(h.Name) == "#~")			tables							= mem;
			else if (str(h.Name) == "#Strings")	md.heaps[clr::HEAP_String]		= mem;
			else if (str(h.Name) == "#US")		md.heaps[clr::HEAP_UserString]	= mem;
			else if (str(h.Name) == "#GUID")	md.heaps[clr::HEAP_GUID]		= mem;
			else if (str(h.Name) == "#Blob")	md.heaps[clr::HEAP_Blob]		= mem;
		}

		void	*p	= md.InitTables(tables);
		clr::METADATA_READER	r(p, &md, tables->HeapSizes);
		for (uint64 b = tables->Valid; b; b = clear_lowest(b))
			r.ReadTable((clr::TABLETYPE)lowest_set_index(b));

		hash_set2<const char*>	all_ns;
		for (auto &i : md.GetTable<clr::TypeDef>())
			all_ns.insert(i.namespce);

		for (auto i : all_ns) {
			if (i == cstr("Windows.UI.Xaml.Controls.Primitives"))
				continue;

			if (i && i[0]) {
				dynamic_array<const char*> ns;
				ns.push_back(i);
				if (i == cstr("Windows.UI.Xaml.Controls"))
					ns.push_back("Windows.UI.Xaml.Controls.Primitives");

				string			s0, s;
				string_builder	sa0(s0), sa(s);
				MakeMDH(md, sa0, sa, ns);
				sa0.flush();
				sa.flush();

				filename	out		= filename(dest).add_dir(i).add_ext("h");
				filename	out0	= filename(dest).add_dir(i).add_ext("0.h");
				FileOutput(out).write(s);
				FileOutput(out0).write(s0);
			}
		}
	}
}

//<input.winmd> <dest folder>

int main(int argc, const char *argv[], char *envp[]) {
	CommandLine	com(argc, argv);
	Process(com[1], com[2]);
	return 0;
}

