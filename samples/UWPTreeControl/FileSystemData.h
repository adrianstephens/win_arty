#pragma once

namespace UWPTreeControl
{
	using namespace iso_winrt;

//	[Windows::UI::Xaml::Data::Bindable]
//	[Windows::Foundation::Metadata::WebHostHidden]
	class FileSystemData : public bindable, public runtime<FileSystemData, Platform::Object> {
	public:
		FileSystemData(ptr<Platform::String> name) : Name(name), IsFolder(false) {}
		~FileSystemData() {}

		ptr<Platform::String> Name;
		bool IsFolder;
	};
}

template<> iso_winrt::member iso_winrt::members<UWPTreeControl::FileSystemData>::a[] = {
	make_member("IsFolder",			&UWPTreeControl::FileSystemData::IsFolder),
	make_member("Name",				&UWPTreeControl::FileSystemData::Name),
};