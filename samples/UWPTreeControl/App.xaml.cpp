//
// App.xaml.cpp
// Implementation of the App class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "App.xaml.h"
#include "winrt/Windows.Storage.h"
#include "winrt/Windows.Storage.FileProperties.h"

using namespace UWPTreeControl;

using namespace Platform;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

using namespace Windows::Storage;
void MakeXbf(Windows::UI::Xaml::Markup::IXamlMetadataProvider *provider) {
#if 0
	ptr<StorageFolder> folder = ApplicationData::Current->LocalFolder;

	auto	input	= co_await folder->GetFileAsync(L"MainPage.xaml");
	auto	output	= co_await folder->CreateFileAsync(L"MainPage.xbf", CreationCollisionOption::ReplaceExisting);

	auto	inputs		= ref_new<Vector<ptr<Streams::IRandomAccessStream>>>();
	auto	outputs		= ref_new<Vector<ptr<Streams::IRandomAccessStream>>>();

	inputs->Append(co_await input->OpenReadAsync());
	outputs->Append(co_await output->OpenAsync(FileAccessMode::ReadWrite, StorageOpenOptions::None));

	Markup::XamlBinaryWriter::Write(inputs, outputs, provider);
#endif
}
/// <summary>
/// Initializes the singleton application object.  This is the first line of authored code
/// executed, and as such is the logical equivalent of main() or WinMain().
/// </summary>
App::App() : provider(new XamlTypeInfo::Provider()) {
	Suspending += {this, &App::OnSuspending};
	MakeXbf(this);
}

/// <summary>
/// Invoked when the application is launched normally by the end user.  Other entry points
/// will be used such as when the application is launched to open a specific file.
/// </summary>
/// <param name="e">Details about the launch request and process.</param>
void App::OnLaunched(ptr<Windows::ApplicationModel::Activation::LaunchActivatedEventArgs> e) {
	auto rootFrame = (ptr<Frame>)Window::Current->Content;

	// Do not repeat app initialization when the Window already has content,
	// just ensure that the window is active
	if (rootFrame == nullptr) {
		// Create a Frame to act as the navigation context and associate it with
		// a SuspensionManager key
		rootFrame = ref_new<Frame>();

		rootFrame->NavigationFailed += {this, &App::OnNavigationFailed};

//		if (e->PreviousExecutionState == ApplicationExecutionState::Terminated) {
			// TODO: Restore the saved session state only when appropriate, scheduling the
			// final launch steps after the restore is complete

//		}

		if (e->PrelaunchActivated == false) {
			if (rootFrame->Content == nullptr) {
				// When the navigation stack isn't restored navigate to the first page,
				// configuring the new page by passing required information as a navigation
				// parameter
				rootFrame->Navigate(typeof<MainPage>(), e->Arguments());
			}
			// Place the frame in the current Window
			Window::Current->Content = rootFrame;
			// Ensure the current window is active
			Window::Current->Activate();
		}
	} else {
		if (e->PrelaunchActivated == false) {
			if (rootFrame->Content == nullptr) {
				// When the navigation stack isn't restored navigate to the first page,
				// configuring the new page by passing required information as a navigation
				// parameter
				rootFrame->Navigate(typeof<MainPage>(), e->Arguments());
			}
			// Ensure the current window is active
			Window::Current->Activate();
		}
	}
}

/// <summary>
/// Invoked when application execution is being suspended.  Application state is saved
/// without knowing whether the application will be terminated or resumed with the contents
/// of memory still intact.
/// </summary>
/// <param name="sender">The source of the suspend request.</param>
/// <param name="e">Details about the suspend request.</param>
void App::OnSuspending(ptr<Object> sender, ptr<SuspendingEventArgs> e) {
	(void)sender;  // Unused parameter
	(void)e;   // Unused parameter

	//TODO: Save application state and stop any background activity
}

/// <summary>
/// Invoked when Navigation to a certain page fails
/// </summary>
/// <param name="sender">The Frame which failed navigation</param>
/// <param name="e">Details about the navigation failure</param>
void App::OnNavigationFailed(ptr<Object> sender, ptr<Navigation::NavigationFailedEventArgs> e) {
	throw FailureException(L"Failed to load Page " + e->SourcePageType().Name);
}

ptr<Markup::IXamlType> App::GetXamlType(Interop::TypeName type) {
	return provider->GetXamlType(type);
}

ptr<Markup::IXamlType> App::GetXamlType(hstring_ref fullName) {
	return provider->GetXamlType(fullName);
}

ptr<Array<Markup::XmlnsDefinition>> App::GetXmlnsDefinitions() {
	static Markup::XmlnsDefinition	defs[] = {
		{L"x",	L"y"},
	};
	return ref_new<Array<Markup::XmlnsDefinition>>(defs);
}

int __stdcall WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
//	XamlTypeInfo::Provider	provider;
//	MakeXbf(&provider);

	Application::Start([](auto &&) {
		ref_new<App>();
	});
}
