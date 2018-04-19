#pragma once
// generated by isopod tools
// namespaces:
// Windows.Globalization.Fonts

#include "Windows.Globalization.Fonts.0.h"
#include "Windows.UI.Text.0.h"

namespace iso_winrt {

// forward types


// defs

template<> struct def<Windows::Globalization::Fonts::ILanguageFont> : interface_type<> {};
template<> struct def<Windows::Globalization::Fonts::LanguageFont> : class_type<Platform::Object, Windows::Globalization::Fonts::ILanguageFont> {};
template<> struct def<Windows::Globalization::Fonts::ILanguageFontGroupFactory> : interface_type<> {};
template<> struct def<Windows::Globalization::Fonts::ILanguageFontGroup> : interface_type<> {};
template<> struct def<Windows::Globalization::Fonts::LanguageFontGroup> : class_type<Platform::Object, Windows::Globalization::Fonts::ILanguageFontGroup>, custom_activators {};

// uuids

template<> struct uuid<Windows::Globalization::Fonts::ILanguageFont> { define_guid(0xB12E5C3A, 0xB76D, 0x459B, 0xBE, 0xEB, 0x90, 0x11, 0x51, 0xCD, 0x77, 0xD1);};
template<> struct uuid<Windows::Globalization::Fonts::ILanguageFontGroupFactory> { define_guid(0xFCAEAC67, 0x4E77, 0x49C7, 0xB8, 0x56, 0xDD, 0xE9, 0x34, 0xFC, 0x73, 0x5B);};
template<> struct uuid<Windows::Globalization::Fonts::ILanguageFontGroup> { define_guid(0xF33A7FC3, 0x3A5C, 0x4AEA, 0xB9, 0xFF, 0xB3, 0x9F, 0xB2, 0x42, 0xF7, 0xF6);};

// types

namespace Windows { namespace Globalization { namespace Fonts {

// ILanguageFont
struct ILanguageFont_raw : IInspectable {
	virtual STDMETHODIMP _get_FontFamily(HSTRING *value);
	virtual STDMETHODIMP _get_FontWeight(UI::Text::FontWeight *weight);
	virtual STDMETHODIMP _get_FontStretch(UI::Text::FontStretch *stretch);
	virtual STDMETHODIMP _get_FontStyle(UI::Text::FontStyle *style);
	virtual STDMETHODIMP _get_ScaleFactor(double *scale);
};
template<typename X> struct ILanguageFont_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&ILanguageFont_adaptor::FontFamily)->_get_FontFamily(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} FontFamily;
		struct : property {
			UI::Text::FontStretch get() { UI::Text::FontStretch stretch; hrcheck(enc(&ILanguageFont_adaptor::FontStretch)->_get_FontStretch(&stretch)); return stretch; }
			UI::Text::FontStretch operator()() { return get(); }
			operator UI::Text::FontStretch () { return get(); }
		} FontStretch;
		struct : property {
			UI::Text::FontStyle get() { UI::Text::FontStyle style; hrcheck(enc(&ILanguageFont_adaptor::FontStyle)->_get_FontStyle(&style)); return style; }
			UI::Text::FontStyle operator()() { return get(); }
			operator UI::Text::FontStyle () { return get(); }
		} FontStyle;
		struct : property {
			UI::Text::FontWeight get() { UI::Text::FontWeight weight; hrcheck(enc(&ILanguageFont_adaptor::FontWeight)->_get_FontWeight(&weight)); return weight; }
			UI::Text::FontWeight operator()() { return get(); }
			operator UI::Text::FontWeight () { return get(); }
		} FontWeight;
		struct : property {
			double get() { double scale; hrcheck(enc(&ILanguageFont_adaptor::ScaleFactor)->_get_ScaleFactor(&scale)); return scale; }
			double operator()() { return get(); }
			operator double () { return get(); }
		} ScaleFactor;
	};
	ILanguageFont_adaptor() {}
};
template<typename X> struct adapt<ILanguageFont, X> : Windows::Globalization::Fonts::ILanguageFont_adaptor<X> { typedef adapt ILanguageFont; };
struct ILanguageFont : ILanguageFont_raw, generate<ILanguageFont> {};

// LanguageFont
template<typename X> struct statics<LanguageFont, X> : X {
	typedef typename X::root_type LanguageFont;
};
struct LanguageFont : generate<LanguageFont> {};

// ILanguageFontGroupFactory
struct ILanguageFontGroupFactory : IInspectable {
	virtual STDMETHODIMP _CreateLanguageFontGroup(HSTRING languageTag, LanguageFontGroup* *recommendedFonts);
};

// ILanguageFontGroup
struct ILanguageFontGroup_raw : IInspectable {
	virtual STDMETHODIMP _get_UITextFont(LanguageFont* *value);
	virtual STDMETHODIMP _get_UIHeadingFont(LanguageFont* *value);
	virtual STDMETHODIMP _get_UITitleFont(LanguageFont* *value);
	virtual STDMETHODIMP _get_UICaptionFont(LanguageFont* *value);
	virtual STDMETHODIMP _get_UINotificationHeadingFont(LanguageFont* *value);
	virtual STDMETHODIMP _get_TraditionalDocumentFont(LanguageFont* *value);
	virtual STDMETHODIMP _get_ModernDocumentFont(LanguageFont* *value);
	virtual STDMETHODIMP _get_DocumentHeadingFont(LanguageFont* *value);
	virtual STDMETHODIMP _get_FixedWidthTextFont(LanguageFont* *value);
	virtual STDMETHODIMP _get_DocumentAlternate1Font(LanguageFont* *value);
	virtual STDMETHODIMP _get_DocumentAlternate2Font(LanguageFont* *value);
};
template<typename X> struct ILanguageFontGroup_adaptor : X {
	union {
		struct : property {
			ptr<LanguageFont> get() { LanguageFont* value; hrcheck(enc(&ILanguageFontGroup_adaptor::DocumentAlternate1Font)->_get_DocumentAlternate1Font(&value)); return from_abi(value); }
			ptr<LanguageFont> operator()() { return get(); }
			operator ptr<LanguageFont> () { return get(); }
			ptr<LanguageFont> operator->() { return get(); }
		} DocumentAlternate1Font;
		struct : property {
			ptr<LanguageFont> get() { LanguageFont* value; hrcheck(enc(&ILanguageFontGroup_adaptor::DocumentAlternate2Font)->_get_DocumentAlternate2Font(&value)); return from_abi(value); }
			ptr<LanguageFont> operator()() { return get(); }
			operator ptr<LanguageFont> () { return get(); }
			ptr<LanguageFont> operator->() { return get(); }
		} DocumentAlternate2Font;
		struct : property {
			ptr<LanguageFont> get() { LanguageFont* value; hrcheck(enc(&ILanguageFontGroup_adaptor::DocumentHeadingFont)->_get_DocumentHeadingFont(&value)); return from_abi(value); }
			ptr<LanguageFont> operator()() { return get(); }
			operator ptr<LanguageFont> () { return get(); }
			ptr<LanguageFont> operator->() { return get(); }
		} DocumentHeadingFont;
		struct : property {
			ptr<LanguageFont> get() { LanguageFont* value; hrcheck(enc(&ILanguageFontGroup_adaptor::FixedWidthTextFont)->_get_FixedWidthTextFont(&value)); return from_abi(value); }
			ptr<LanguageFont> operator()() { return get(); }
			operator ptr<LanguageFont> () { return get(); }
			ptr<LanguageFont> operator->() { return get(); }
		} FixedWidthTextFont;
		struct : property {
			ptr<LanguageFont> get() { LanguageFont* value; hrcheck(enc(&ILanguageFontGroup_adaptor::ModernDocumentFont)->_get_ModernDocumentFont(&value)); return from_abi(value); }
			ptr<LanguageFont> operator()() { return get(); }
			operator ptr<LanguageFont> () { return get(); }
			ptr<LanguageFont> operator->() { return get(); }
		} ModernDocumentFont;
		struct : property {
			ptr<LanguageFont> get() { LanguageFont* value; hrcheck(enc(&ILanguageFontGroup_adaptor::TraditionalDocumentFont)->_get_TraditionalDocumentFont(&value)); return from_abi(value); }
			ptr<LanguageFont> operator()() { return get(); }
			operator ptr<LanguageFont> () { return get(); }
			ptr<LanguageFont> operator->() { return get(); }
		} TraditionalDocumentFont;
		struct : property {
			ptr<LanguageFont> get() { LanguageFont* value; hrcheck(enc(&ILanguageFontGroup_adaptor::UICaptionFont)->_get_UICaptionFont(&value)); return from_abi(value); }
			ptr<LanguageFont> operator()() { return get(); }
			operator ptr<LanguageFont> () { return get(); }
			ptr<LanguageFont> operator->() { return get(); }
		} UICaptionFont;
		struct : property {
			ptr<LanguageFont> get() { LanguageFont* value; hrcheck(enc(&ILanguageFontGroup_adaptor::UIHeadingFont)->_get_UIHeadingFont(&value)); return from_abi(value); }
			ptr<LanguageFont> operator()() { return get(); }
			operator ptr<LanguageFont> () { return get(); }
			ptr<LanguageFont> operator->() { return get(); }
		} UIHeadingFont;
		struct : property {
			ptr<LanguageFont> get() { LanguageFont* value; hrcheck(enc(&ILanguageFontGroup_adaptor::UINotificationHeadingFont)->_get_UINotificationHeadingFont(&value)); return from_abi(value); }
			ptr<LanguageFont> operator()() { return get(); }
			operator ptr<LanguageFont> () { return get(); }
			ptr<LanguageFont> operator->() { return get(); }
		} UINotificationHeadingFont;
		struct : property {
			ptr<LanguageFont> get() { LanguageFont* value; hrcheck(enc(&ILanguageFontGroup_adaptor::UITextFont)->_get_UITextFont(&value)); return from_abi(value); }
			ptr<LanguageFont> operator()() { return get(); }
			operator ptr<LanguageFont> () { return get(); }
			ptr<LanguageFont> operator->() { return get(); }
		} UITextFont;
		struct : property {
			ptr<LanguageFont> get() { LanguageFont* value; hrcheck(enc(&ILanguageFontGroup_adaptor::UITitleFont)->_get_UITitleFont(&value)); return from_abi(value); }
			ptr<LanguageFont> operator()() { return get(); }
			operator ptr<LanguageFont> () { return get(); }
			ptr<LanguageFont> operator->() { return get(); }
		} UITitleFont;
	};
	ILanguageFontGroup_adaptor() {}
};
template<typename X> struct adapt<ILanguageFontGroup, X> : Windows::Globalization::Fonts::ILanguageFontGroup_adaptor<X> { typedef adapt ILanguageFontGroup; };
struct ILanguageFontGroup : ILanguageFontGroup_raw, generate<ILanguageFontGroup> {};

// LanguageFontGroup
template<typename> struct LanguageFontGroup_statics {
	static LanguageFontGroup *activate(hstring_ref languageTag) { LanguageFontGroup *recommendedFonts; hrcheck(get_activation_factory<LanguageFontGroup, ILanguageFontGroupFactory>()->_CreateLanguageFontGroup(languageTag, &recommendedFonts)); return recommendedFonts; }
};

template<typename X> struct statics<LanguageFontGroup, X> : X, Windows::Globalization::Fonts::LanguageFontGroup_statics<void> {
	using Windows::Globalization::Fonts::LanguageFontGroup_statics<void>::activate;
	typedef typename X::root_type LanguageFontGroup;
};
struct LanguageFontGroup : generate<LanguageFontGroup> {};
}}}
} // namespace iso_winrt
