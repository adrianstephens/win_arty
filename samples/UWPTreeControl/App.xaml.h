//
// App.xaml.h
// Declaration of the App class.
//

#pragma once
#include "winrt/binding.h"

namespace UWPTreeControl
{
	using namespace iso_winrt;

	/// <summary>
	/// Provides application-specific behavior to supplement the default Application class.
	/// </summary>
	class App : public compose<App,
		Windows::UI::Xaml::Application,
		Windows::UI::Xaml::Markup::IXamlMetadataProvider
	> {
	public:
		//[Windows::Foundation::Metadata::DefaultOverload]
		ptr<Windows::UI::Xaml::Markup::IXamlType> GetXamlType(Windows::UI::Xaml::Interop::TypeName type);
		ptr<Windows::UI::Xaml::Markup::IXamlType> GetXamlType(hstring_ref fullName);
		ptr<Platform::Array<Windows::UI::Xaml::Markup::XmlnsDefinition>> GetXmlnsDefinitions();
		void OnLaunched(ptr<Windows::ApplicationModel::Activation::LaunchActivatedEventArgs> e);// override;

	internal:
		App();

	private:
		void OnSuspending(ptr<Platform::Object> sender, ptr<Windows::ApplicationModel::SuspendingEventArgs> e);
		void OnNavigationFailed(ptr<Platform::Object> sender, ptr<Windows::UI::Xaml::Navigation::NavigationFailedEventArgs> e);
		ptr<XamlTypeInfo::Provider> provider;
	};
}
