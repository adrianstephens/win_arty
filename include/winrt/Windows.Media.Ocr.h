#pragma once
// generated by isopod tools
// namespaces:
// Windows.Media.Ocr

#include "Windows.Media.Ocr.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IVectorView;
}}
namespace Globalization {
struct Language;
}
namespace Graphics { namespace Imaging {
struct SoftwareBitmap;
}}}

// defs

template<> struct def<Windows::Media::Ocr::IOcrWord> : interface_type<> {};
template<> struct def<Windows::Media::Ocr::IOcrLine> : interface_type<> {};
template<> struct def<Windows::Media::Ocr::OcrWord> : class_type<Platform::Object, Windows::Media::Ocr::IOcrWord> {};
template<> struct def<Windows::Media::Ocr::IOcrResult> : interface_type<> {};
template<> struct def<Windows::Media::Ocr::OcrLine> : class_type<Platform::Object, Windows::Media::Ocr::IOcrLine> {};
template<> struct def<Windows::Media::Ocr::IOcrEngine> : interface_type<> {};
template<> struct def<Windows::Media::Ocr::OcrResult> : class_type<Platform::Object, Windows::Media::Ocr::IOcrResult> {};
template<> struct def<Windows::Media::Ocr::IOcrEngineStatics> : interface_type<> {};
template<> struct def<Windows::Media::Ocr::OcrEngine> : class_type<Platform::Object, Windows::Media::Ocr::IOcrEngine> {};

// uuids

template<> struct uuid<Windows::Media::Ocr::IOcrWord> { define_guid(0x3C2A477A, 0x5CD9, 0x3525, 0xBA, 0x2A, 0x23, 0xD1, 0xE0, 0xA6, 0x8A, 0x1D);};
template<> struct uuid<Windows::Media::Ocr::IOcrLine> { define_guid(0x43A16F, 0xE31F, 0x3A24, 0x89, 0x9C, 0xD4, 0x44, 0xBD, 0x8, 0x81, 0x24);};
template<> struct uuid<Windows::Media::Ocr::IOcrResult> { define_guid(0x9BD235B2, 0x175B, 0x3D6A, 0x92, 0xE2, 0x38, 0x8C, 0x20, 0x6E, 0x2F, 0x63);};
template<> struct uuid<Windows::Media::Ocr::IOcrEngine> { define_guid(0x5A14BC41, 0x5B76, 0x3140, 0xB6, 0x80, 0x88, 0x25, 0x56, 0x26, 0x83, 0xAC);};
template<> struct uuid<Windows::Media::Ocr::IOcrEngineStatics> { define_guid(0x5BFFA85A, 0x3384, 0x3540, 0x99, 0x40, 0x69, 0x91, 0x20, 0xD4, 0x28, 0xA8);};

// types

namespace Windows { namespace Media { namespace Ocr {

// IOcrWord
struct IOcrWord_raw : IInspectable {
	virtual STDMETHODIMP _get_BoundingRect(Foundation::Rect *value);
	virtual STDMETHODIMP _get_Text(HSTRING *value);
};
template<typename X> struct IOcrWord_adaptor : X {
	union {
		struct : property {
			Foundation::Rect get() { Foundation::Rect value; hrcheck(enc(&IOcrWord_adaptor::BoundingRect)->_get_BoundingRect(&value)); return value; }
			Foundation::Rect operator()() { return get(); }
			operator Foundation::Rect () { return get(); }
		} BoundingRect;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IOcrWord_adaptor::Text)->_get_Text(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Text;
	};
	IOcrWord_adaptor() {}
};
template<typename X> struct adapt<IOcrWord, X> : Windows::Media::Ocr::IOcrWord_adaptor<X> { typedef adapt IOcrWord; };
struct IOcrWord : IOcrWord_raw, generate<IOcrWord> {};

// IOcrLine
struct IOcrLine_raw : IInspectable {
	virtual STDMETHODIMP _get_Words(Foundation::Collections::IVectorView<OcrWord*>* *value);
	virtual STDMETHODIMP _get_Text(HSTRING *value);
};
template<typename X> struct IOcrLine_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IOcrLine_adaptor::Text)->_get_Text(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Text;
		struct : property {
			ptr<Foundation::Collections::IVectorView<ptr<OcrWord>>> get() { Foundation::Collections::IVectorView<OcrWord*>* value; hrcheck(enc(&IOcrLine_adaptor::Words)->_get_Words(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<ptr<OcrWord>>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<ptr<OcrWord>>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<ptr<OcrWord>>> operator->() { return get(); }
		} Words;
	};
	IOcrLine_adaptor() {}
};
template<typename X> struct adapt<IOcrLine, X> : Windows::Media::Ocr::IOcrLine_adaptor<X> { typedef adapt IOcrLine; };
struct IOcrLine : IOcrLine_raw, generate<IOcrLine> {};

// OcrWord
template<typename X> struct statics<OcrWord, X> : X {
	typedef typename X::root_type OcrWord;
};
struct OcrWord : generate<OcrWord> {};

// IOcrResult
struct IOcrResult_raw : IInspectable {
	virtual STDMETHODIMP _get_Lines(Foundation::Collections::IVectorView<OcrLine*>* *value);
	virtual STDMETHODIMP _get_TextAngle(Foundation::IReference<double>* *value);
	virtual STDMETHODIMP _get_Text(HSTRING *value);
};
template<typename X> struct IOcrResult_adaptor : X {
	union {
		struct : property {
			ptr<Foundation::Collections::IVectorView<ptr<OcrLine>>> get() { Foundation::Collections::IVectorView<OcrLine*>* value; hrcheck(enc(&IOcrResult_adaptor::Lines)->_get_Lines(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<ptr<OcrLine>>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<ptr<OcrLine>>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<ptr<OcrLine>>> operator->() { return get(); }
		} Lines;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IOcrResult_adaptor::Text)->_get_Text(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Text;
		struct : property {
			ptr<Foundation::IReference<double>> get() { Foundation::IReference<double>* value; hrcheck(enc(&IOcrResult_adaptor::TextAngle)->_get_TextAngle(&value)); return from_abi(value); }
			ptr<Foundation::IReference<double>> operator()() { return get(); }
			operator ptr<Foundation::IReference<double>> () { return get(); }
			ptr<Foundation::IReference<double>> operator->() { return get(); }
		} TextAngle;
	};
	IOcrResult_adaptor() {}
};
template<typename X> struct adapt<IOcrResult, X> : Windows::Media::Ocr::IOcrResult_adaptor<X> { typedef adapt IOcrResult; };
struct IOcrResult : IOcrResult_raw, generate<IOcrResult> {};

// OcrLine
template<typename X> struct statics<OcrLine, X> : X {
	typedef typename X::root_type OcrLine;
};
struct OcrLine : generate<OcrLine> {};

// IOcrEngine
struct IOcrEngine_raw : IInspectable {
	virtual STDMETHODIMP _RecognizeAsync(Graphics::Imaging::SoftwareBitmap* bitmap, Foundation::IAsyncOperation<OcrResult*>* *result);
	virtual STDMETHODIMP _get_RecognizerLanguage(Globalization::Language* *value);
};
template<typename X> struct IOcrEngine_adaptor : X {
	union {
		struct : property {
			ptr<Globalization::Language> get() { Globalization::Language* value; hrcheck(enc(&IOcrEngine_adaptor::RecognizerLanguage)->_get_RecognizerLanguage(&value)); return from_abi(value); }
			ptr<Globalization::Language> operator()() { return get(); }
			operator ptr<Globalization::Language> () { return get(); }
			ptr<Globalization::Language> operator->() { return get(); }
		} RecognizerLanguage;
	};
	ptr<Foundation::IAsyncOperation<ptr<OcrResult>>> RecognizeAsync(pptr<Graphics::Imaging::SoftwareBitmap> bitmap) { Foundation::IAsyncOperation<OcrResult*>* result; hrcheck(X::get()->_RecognizeAsync(bitmap, &result)); return from_abi(result); }
	IOcrEngine_adaptor() {}
};
template<typename X> struct adapt<IOcrEngine, X> : Windows::Media::Ocr::IOcrEngine_adaptor<X> { typedef adapt IOcrEngine; };
struct IOcrEngine : IOcrEngine_raw, generate<IOcrEngine> {};

// OcrResult
template<typename X> struct statics<OcrResult, X> : X {
	typedef typename X::root_type OcrResult;
};
struct OcrResult : generate<OcrResult> {};

// IOcrEngineStatics
struct IOcrEngineStatics : IInspectable {
	virtual STDMETHODIMP _get_MaxImageDimension(unsigned *value);
	virtual STDMETHODIMP _get_AvailableRecognizerLanguages(Foundation::Collections::IVectorView<Globalization::Language*>* *value);
	virtual STDMETHODIMP _IsLanguageSupported(Globalization::Language* language, bool *result);
	virtual STDMETHODIMP _TryCreateFromLanguage(Globalization::Language* language, OcrEngine* *result);
	virtual STDMETHODIMP _TryCreateFromUserProfileLanguages(OcrEngine* *result);
};

// OcrEngine
template<typename> struct OcrEngine_statics {
	static struct _AvailableRecognizerLanguages : property {
		ptr<Foundation::Collections::IVectorView<ptr<Globalization::Language>>> get() { Foundation::Collections::IVectorView<Globalization::Language*>* value; hrcheck(get_activation_factory<OcrEngine, IOcrEngineStatics>()->_get_AvailableRecognizerLanguages(&value)); return from_abi(value); }
		ptr<Foundation::Collections::IVectorView<ptr<Globalization::Language>>> operator()() { return get(); }
		operator ptr<Foundation::Collections::IVectorView<ptr<Globalization::Language>>> () { return get(); }
		ptr<Foundation::Collections::IVectorView<ptr<Globalization::Language>>> operator->() { return get(); }
	} AvailableRecognizerLanguages;
	static struct _MaxImageDimension : property {
		unsigned get() { unsigned value; hrcheck(get_activation_factory<OcrEngine, IOcrEngineStatics>()->_get_MaxImageDimension(&value)); return value; }
		unsigned operator()() { return get(); }
		operator unsigned () { return get(); }
	} MaxImageDimension;
	static bool IsLanguageSupported(pptr<Globalization::Language> language) { bool result; hrcheck(get_activation_factory<OcrEngine, IOcrEngineStatics>()->_IsLanguageSupported(language, &result)); return result; }
	static ptr<OcrEngine> TryCreateFromLanguage(pptr<Globalization::Language> language) { OcrEngine* result; hrcheck(get_activation_factory<OcrEngine, IOcrEngineStatics>()->_TryCreateFromLanguage(language, &result)); return from_abi(result); }
	static ptr<OcrEngine> TryCreateFromUserProfileLanguages() { OcrEngine* result; hrcheck(get_activation_factory<OcrEngine, IOcrEngineStatics>()->_TryCreateFromUserProfileLanguages(&result)); return from_abi(result); }
};
template<typename X> typename OcrEngine_statics<X>::_AvailableRecognizerLanguages OcrEngine_statics<X>::AvailableRecognizerLanguages;
template<typename X> typename OcrEngine_statics<X>::_MaxImageDimension OcrEngine_statics<X>::MaxImageDimension;

template<typename X> struct statics<OcrEngine, X> : X, Windows::Media::Ocr::OcrEngine_statics<void> {
	typedef typename X::root_type OcrEngine;
};
struct OcrEngine : generate<OcrEngine> {};
}}}
} // namespace iso_winrt
