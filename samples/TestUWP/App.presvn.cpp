//
// App.xaml.cpp
// Implementation of the App class.
//
#include "base/coroutine.h"
#include "winrt.h"
#include "base/vector.h"

#include "winrt/windows.applicationmodel.h"
#include "winrt/windows.storage.h"
#include "winrt/windows.graphics.h"
#include "winrt/windows.graphics.display.h"
#include "winrt/windows.graphics.imaging.h"
#include "winrt/windows.ui.h"
#include "winrt/windows.ui.core.h"
#include "winrt/windows.ui.input.h"
#include "winrt/windows.ui.xaml.h"
#include "winrt/windows.ui.xaml.controls.h"
#include "winrt/windows.ui.viewmanagement.h"
#include "winrt/windows.media.audio.h"
#include "winrt/Windows.Globalization.DateTimeFormatting.h"

#pragma comment(lib, "windowsapp") 

using namespace iso_winrt;
using namespace Platform;
using namespace Windows;

using namespace Foundation;
using namespace Collections;

using namespace ApplicationModel::Core;
using namespace ApplicationModel::Activation;
using namespace UI;
using namespace Xaml::Controls;
using namespace Numerics;
using namespace Globalization::DateTimeFormatting;
using namespace Graphics::Display;

class App1 : public compose<App1, Xaml::Application> {
public:
//	ptr<Xaml::ResourceDictionary>	Resources;


//	void OnWindowCreated(Xaml::WindowCreatedEventArgs* args) {
//	}

	void OnLaunched(ApplicationModel::Activation::LaunchActivatedEventArgs* args) {
		auto txtBlock				= ref_new<Xaml::Controls::TextBlock>();
		txtBlock->Text				= L"Hello World ( Welcome to UWP/C++ tutorial)";
		txtBlock->TextAlignment		= Xaml::TextAlignment::Center;
		txtBlock->VerticalAlignment = Xaml::VerticalAlignment::Center;

		ptr<Xaml::Window>	window	= Xaml::Window::Current;
		window->Content = txtBlock.get();
		window->Activate();

		auto	dialog  = ref_new<Xaml::Controls::ContentDialog>();
		dialog->Title	= L"No wifi connection";
		dialog->Content	= L"Check connection and try again.";
		dialog->CloseButtonText(L"Ok");
		dialog->ShowAsync();
	}
};

#if 1
struct CalendarApp : compose<CalendarApp, Xaml::Application> {
	void OnLaunched(LaunchActivatedEventArgs *args) {
		auto panel = ref_new<StackPanel>();
		panel->Padding = {50.0, 50.0};
		m_children = panel->Children;

		auto	picker = ref_new<CalendarDatePicker>();
		FormatDateTime(picker, clock::now());

		picker->DateChanged += [this](const ptr<CalendarDatePicker> &picker, CalendarDatePickerDateChangedEventArgs *args) {
			FormatDateTime(picker, args->NewDate->Value);
		};

		ptr<Xaml::Window>	window = Xaml::Window::Current;
		window->Content = panel;
		window->Activate();
	}

	void FormatDateTime(const ptr<CalendarDatePicker> &picker, const DateTime &value) {
		m_children->Clear();
		m_children->Append(picker);

		auto formatter = ref_new<DateTimeFormatter>(L"shortdate shorttime");
		AppendTextBlock(L"Windows.Globalization: " + formatter->Format(value));

/*		time_t utc = clock::to_time_t(value);
		tm local{};

		if (0 == localtime_s(&local, &utc)) {
			std::array<wchar_t, 100> buffer{};
			wcsftime(buffer.data(), buffer.size(), L"std: %F %T", &local);

			AppendTextBlock(buffer.data());
		}*/
	}

	void AppendTextBlock(const hstring& text) {
		auto	block = ref_new<TextBlock>();

		block->FontFamily	= ref_new<Xaml::Media::FontFamily>(L"Segoe UI Semibold");
		block->FontSize		= 28.0;
		block->TextWrapping	= Xaml::TextWrapping::Wrap;
		block->Padding		= {0.0, 10.0};
		block->Text			= text;

		m_children->Append(block);
	}

	ptr<UIElementCollection> m_children;
};
#endif

#if 1

struct ids {
	ULONG	count;
	IID		*p;
	ids(ULONG _count, IID *_p) : count(_count), p(_p) {}
	ids(ids &&b) : count(b.count), p(b.p) { b.p = 0; }
	~ids() {
		if (p)
			CoTaskMemFree(p);
	}
};

template<typename T> ids get_ids(T *t) {
	ULONG	count;
	IID		*p;
	query<IInspectable>(t)->GetIids(&count, &p);
	return ids(count, p);
}
template<typename T> ids get_ids(const ptr<T> &t) {
	return get_ids(t.get());
}

struct BlocksApp : public runtime<BlocksApp, IFrameworkViewSource, IFrameworkView> {
	ptr<Composition::CompositionTarget>	m_target;
	ptr<Composition::VisualCollection>	m_visuals;
	ptr<Composition::Visual>			m_selected;
	Point					m_offset;

	ptr<IFrameworkView> CreateView() {
		return this;
	}
	void Initialize(CoreApplicationView*)	{}
	void Uninitialize()						{}
	void Load(hstring_ref)					{}

	void Run() {
		auto window = Core::CoreWindow::GetForCurrentThread();
		window->Activate();

//		window->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessUntilQuit);

		auto dispatcher = window->Dispatcher();
		dispatcher->ProcessEvents(Core::CoreProcessEventsOption::ProcessUntilQuit);
	}

	void SetWindow(Windows::UI::Core::CoreWindow* window) {
		auto	compositor	= ref_new<Windows::UI::Composition::Compositor>();
		auto	root		= compositor->CreateContainerVisual();
		m_target			= compositor->CreateTargetForCurrentView();
		m_target->Root		= root;
		m_visuals			= root->Children;

		auto	x = types_unique<int, char>::type();

		auto	ids = get_ids(this);

		ptr<Vector<int>>	vec = ref_new<Vector<int>>();
		vec->Append(100);
		for (auto i : vec) {
			ISO_TRACEF(i) << '\n';
		}
		auto	ids2 = get_ids(vec);

		for (auto i : vec->GetView()) {
			ISO_TRACEF(i) << '\n';
		}

		window->PointerPressed += [this](Core::CoreWindow *window, Core::PointerEventArgs *args) {
			Point point = args->CurrentPoint->Position;
			for (ptr<Composition::Visual> visual : m_visuals) {
				Vector3 offset	= visual->Offset;
				Vector2 size	= visual->Size;

				if (point.X >= offset.X
				&&	point.X < offset.X + size.X
				&&	point.Y >= offset.Y
				&&	point.Y < offset.Y + size.Y
				) {
					m_selected = visual;
					m_offset.X = offset.X - point.X;
					m_offset.Y = offset.Y - point.Y;
				}
			}

			if (m_selected) {
				m_visuals->Remove(m_selected);
				m_visuals->InsertAtTop(m_selected);
			} else {
				AddVisual(point);
			}
		};
		window->PointerMoved += [this](Core::CoreWindow *window, Core::PointerEventArgs *args) {
			if (m_selected) {
				Point point = args->CurrentPoint->Position;

				m_selected->Offset = {
					point.X + m_offset.X,
					point.Y + m_offset.Y,
					0.0f
				};
			}
		};

		window->PointerReleased += [this](Core::CoreWindow *window, Core::PointerEventArgs *args) {
			m_selected = nullptr;
		};
	}


	void AddVisual(Point &point) {
		auto&	compositor	= m_visuals->Compositor;
		auto	visual		= compositor->CreateSpriteVisual();

		static Color colors[] = {
			{0xDC, 0x5B, 0x9B, 0xD5},
			{0xDC, 0xED, 0x7D, 0x31},
			{0xDC, 0x70, 0xAD, 0x47},
			{0xDC, 0xFF, 0xC0, 0x00}
		};

		static unsigned last = 0;
		unsigned const next = ++last % num_elements(colors);
		visual->Brush = compositor->CreateColorBrush(colors[next]);

		float const BlockSize = 100.0f;

		visual->Size = {
			BlockSize,
			BlockSize
		};

		visual->Offset =  {
			point.X - BlockSize / 2.0f,
			point.Y - BlockSize / 2.0f,
			0.0f,
		};

		m_visuals->InsertAtTop(visual);

		m_selected = visual;
		m_offset.X = -BlockSize / 2.0f;
		m_offset.Y = -BlockSize / 2.0f;
	}
};
#endif

#if 1
struct MainPage : compose<MainPage, Page> {
	MainPage() {
		Xaml::Application::LoadComponent((ptr<Object>)this, ref_new<Uri>(L"ms-appx:///MainPage.xaml"));
	}

	auto GetRuntimeClassName() {
		return L"MainPage";
	}
};

struct MarkupApp : compose<MarkupApp, Xaml::Application> {
	void OnLaunched(LaunchActivatedEventArgs const *) {
		ptr<Xaml::Window> window = Xaml::Window::Current;

		if (!window->Content())
			window->Content = new MainPage;

		window->Activate();
	}
};
#endif

#include "winrt/windows.media.ocr.h"
#include "winrt/windows.storage.pickers.h"


using namespace Windows::Storage;
using namespace Windows::Storage::Streams;
using namespace Windows::Graphics::Imaging;
using namespace Windows::Media::Ocr;
using namespace Windows::Storage::Pickers;

struct OCRApp : compose<OCRApp, Xaml::Application> {
	void OnLaunched(LaunchActivatedEventArgs const *) {
		auto	block = ref_new<Xaml::Controls::TextBlock>();

		block->FontFamily		= ref_new<Xaml::Media::FontFamily>(L"Segoe UI Semibold");
		block->FontSize			= 72.0;
		block->Foreground		= ref_new<Xaml::Media::SolidColorBrush>(Colors::Orange);
		block->VerticalAlignment= Xaml::VerticalAlignment::Center;
		block->TextAlignment	= Xaml::TextAlignment::Center;
		block->TextWrapping		= Xaml::TextWrapping::Wrap;

		auto window = Xaml::Window::Current();
		window->Content = block;
		window->Activate();

		Async(block);
	}

	void Async(ptr<TextBlock> block) {
		auto	picker = ref_new<FileOpenPicker>();
		picker->FileTypeFilter->Append(L".png");
		picker->SuggestedStartLocation = PickerLocationId::PicturesLibrary;
		auto file = co_await picker->PickSingleFileAsync();

		if (file == nullptr) {
			return;
		}

		apartment_context ui_thread;
		co_await background();

		auto stream		= co_await file->OpenAsync(FileAccessMode::Read);
		auto decoder	= co_await BitmapDecoder::CreateAsync(stream);
		auto bitmap		= co_await decoder->GetSoftwareBitmapAsync();
		auto engine		= OcrEngine::TryCreateFromUserProfileLanguages();
		auto result		= co_await engine->RecognizeAsync(bitmap);

		co_await ui_thread;
		block->Text = result->Text;
	}
};

void testy() {
	using namespace Windows::Media;
	using namespace Audio;

	auto						settings	= ref_new<AudioGraphSettings>(Render::AudioRenderCategory::SoundEffects);
	auto						creator	= co_await AudioGraph::CreateAsync(settings);
	AudioGraphCreationStatus	status	= creator->Status;
	ptr<AudioGraph>				graph	= creator->Graph();

	auto						result	= co_await graph->CreateDeviceInputNodeAsync(Capture::MediaCategory::Media);
	ptr<AudioDeviceInputNode>	node	= result->DeviceInputNode;
	ISO_TRACEF("got node\n");
//	node->Close();
}

void test_WindowsAudioGraph();

int __stdcall wWinMain(HINSTANCE, HINSTANCE, PWSTR, int) {
	test_WindowsAudioGraph();

//	testy();
#if 0
	Xaml::Application::Start([](auto &&) { new CalendarApp; });  
#elif 0
	Xaml::Application::Start([](auto &&) { new MarkupApp; });
#elif 0
	Xaml::Application::Start([](auto &&) { new OCRApp; });
#else
	auto	app = new BlocksApp;
	Windows::ApplicationModel::Core::CoreApplication::Run(app);
#endif
}

