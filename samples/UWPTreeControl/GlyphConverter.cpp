#include "pch.h"
#include "winrt/binding.h"

namespace UWPTreeControl {
	using namespace iso_winrt;
	using namespace Platform;
	using namespace Windows::UI::Xaml;

//	[Windows::UI::Xaml::Data::Bindable]
//	[Windows::Foundation::Metadata::WebHostHidden]
	class GlyphConverter : public bindable, public runtime<GlyphConverter, Data::IValueConverter> {
	public:
		GlyphConverter() {}

		// Inherited via IValueConverter
		ptr<Object> Convert(ptr<Object> value, Interop::TypeName targetType, ptr<Object> parameter, ptr<String> language) {
			return unbox<bool>(value)
				? ExpandedGlyph
				: CollapsedGlyph;
		}
		ptr<Object> ConvertBack(ptr<Object> value, Interop::TypeName targetType, ptr<Object> parameter, ptr<String> language) {
			return value;
		}

		ptr<String> ExpandedGlyph;
		ptr<String> CollapsedGlyph;
	};
}

template<> iso_winrt::member iso_winrt::members<UWPTreeControl::GlyphConverter>::a[] = {
	make_member("ExpandedGlyph",	&UWPTreeControl::GlyphConverter::ExpandedGlyph),
	make_member("CollapsedGlyph",	&UWPTreeControl::GlyphConverter::CollapsedGlyph),
};

