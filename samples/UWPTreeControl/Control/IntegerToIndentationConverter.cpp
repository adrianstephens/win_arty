#include "pch.h"
#include "winrt/binding.h"

namespace TreeViewControl {
	using namespace iso_winrt;
	using namespace Platform;
	using namespace Windows::UI::Xaml;

//	[Windows::Foundation::Metadata::WebHostHidden]
	class IntegerToIndentationConverter : public trust_level<PartialTrust>, public bindable, public runtime<IntegerToIndentationConverter, Data::IValueConverter> {
	public:
		int IndentMultiplier;

		IntegerToIndentationConverter() : IndentMultiplier(20) {}

		ptr<Object> Convert(ptr<Object> value, Interop::TypeName targetType, ptr<Object> parameter, ptr<String> language) {
			Thickness indent{0, 0, 0, 0};
			if (value)
				indent.Left = unbox<int>(value) * IndentMultiplier;

			return object(indent);
		}
		ptr<Object> ConvertBack(ptr<Object> value, Interop::TypeName targetType, ptr<Object> parameter, ptr<String> language) {
			return value;
		}
	};
}

template<> iso_winrt::member iso_winrt::members<TreeViewControl::IntegerToIndentationConverter>::a[] = {
	make_member("IndentMultiplier", &TreeViewControl::IntegerToIndentationConverter::IndentMultiplier),
};