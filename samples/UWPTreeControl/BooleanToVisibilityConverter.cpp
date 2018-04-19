#include "pch.h"
#include "winrt/binding.h"

namespace UWPTreeControl {
	using namespace iso_winrt;
	using namespace Platform;
	using namespace Windows::UI::Xaml;

//	[Windows::UI::Xaml::Data::Bindable]
//	[Windows::Foundation::Metadata::WebHostHidden]
	class BooleanToVisibilityConverter : public bindable, public runtime<BooleanToVisibilityConverter, Data::IValueConverter> {
	public:
		BooleanToVisibilityConverter()	{}

		// Inherited via IValueConverter
		ptr<Object> Convert(ptr<Object> value, Interop::TypeName targetType, ptr<Object> parameter, ptr<String> language) {
			return (object)int(unbox<bool>(value) != IsInverse ? Visibility::Visible : Visibility::Collapsed);
		}
		ptr<Object> ConvertBack(ptr<Object> value, Interop::TypeName targetType, ptr<Object> parameter, ptr<String> language) {
			return value;
		}

		bool IsInverse = false;
	};

}
template<> iso_winrt::member iso_winrt::members<UWPTreeControl::BooleanToVisibilityConverter>::a[] = {
	make_member("IsInverse",			&UWPTreeControl::BooleanToVisibilityConverter::IsInverse),
};
