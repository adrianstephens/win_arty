#pragma once
// generated by isopod tools
// namespaces:
// Windows.Data.Text

#include "Windows.Data.Text.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IVectorView;
template<typename T> struct IIterable;
}
template<typename TResult> struct IAsyncOperation;
}}

// defs

template<> struct def<Windows::Data::Text::TextSegment> : value_type<unsigned, unsigned> {};
template<> struct def<Windows::Data::Text::ISemanticTextQueryFactory> : interface_type<> {};
template<> struct def<Windows::Data::Text::ISemanticTextQuery> : interface_type<> {};
template<> struct def<Windows::Data::Text::SemanticTextQuery> : class_type<Platform::Object, Windows::Data::Text::ISemanticTextQuery>, custom_activators {};
template<> struct def<Windows::Data::Text::UnicodeGeneralCategory> : enum_type<int> {};
template<> struct def<Windows::Data::Text::UnicodeNumericType> : enum_type<int> {};
template<> struct def<Windows::Data::Text::IUnicodeCharactersStatics> : interface_type<> {};
template<> struct def<Windows::Data::Text::UnicodeCharacters> : class_type<Platform::Object, Platform::Object> {};
template<> struct def<Windows::Data::Text::AlternateNormalizationFormat> : enum_type<int> {};
template<> struct def<Windows::Data::Text::IAlternateWordForm> : interface_type<> {};
template<> struct def<Windows::Data::Text::AlternateWordForm> : class_type<Platform::Object, Windows::Data::Text::IAlternateWordForm> {};
template<> struct def<Windows::Data::Text::ISelectableWordSegment> : interface_type<> {};
template<> struct def<Windows::Data::Text::IWordSegment> : interface_type<> {};
template<> struct def<Windows::Data::Text::WordSegment> : class_type<Platform::Object, Windows::Data::Text::IWordSegment> {};
template<> struct def<Windows::Data::Text::WordSegmentsTokenizingHandler> : delegate_type {};
template<> struct def<Windows::Data::Text::IWordsSegmenter> : interface_type<> {};
template<> struct def<Windows::Data::Text::IWordsSegmenterFactory> : interface_type<> {};
template<> struct def<Windows::Data::Text::WordsSegmenter> : class_type<Platform::Object, Windows::Data::Text::IWordsSegmenter>, custom_activators {};
template<> struct def<Windows::Data::Text::SelectableWordSegment> : class_type<Platform::Object, Windows::Data::Text::ISelectableWordSegment> {};
template<> struct def<Windows::Data::Text::SelectableWordSegmentsTokenizingHandler> : delegate_type {};
template<> struct def<Windows::Data::Text::ISelectableWordsSegmenter> : interface_type<> {};
template<> struct def<Windows::Data::Text::ISelectableWordsSegmenterFactory> : interface_type<> {};
template<> struct def<Windows::Data::Text::SelectableWordsSegmenter> : class_type<Platform::Object, Windows::Data::Text::ISelectableWordsSegmenter>, custom_activators {};
template<> struct def<Windows::Data::Text::ITextPredictionGenerator> : interface_type<> {};
template<> struct def<Windows::Data::Text::ITextPredictionGeneratorFactory> : interface_type<> {};
template<> struct def<Windows::Data::Text::TextPredictionGenerator> : class_type<Platform::Object, Windows::Data::Text::ITextPredictionGenerator>, custom_activators {};
template<> struct def<Windows::Data::Text::ITextConversionGenerator> : interface_type<> {};
template<> struct def<Windows::Data::Text::ITextConversionGeneratorFactory> : interface_type<> {};
template<> struct def<Windows::Data::Text::TextConversionGenerator> : class_type<Platform::Object, Windows::Data::Text::ITextConversionGenerator>, custom_activators {};
template<> struct def<Windows::Data::Text::ITextReverseConversionGenerator> : interface_type<> {};
template<> struct def<Windows::Data::Text::ITextReverseConversionGeneratorFactory> : interface_type<> {};
template<> struct def<Windows::Data::Text::ITextReverseConversionGenerator2> : interface_type<> {};
template<> struct def<Windows::Data::Text::TextReverseConversionGenerator> : class_type<Platform::Object, Windows::Data::Text::ITextReverseConversionGenerator, Windows::Data::Text::ITextReverseConversionGenerator2>, custom_activators {};
template<> struct def<Windows::Data::Text::ITextPhoneme> : interface_type<> {};
template<> struct def<Windows::Data::Text::TextPhoneme> : class_type<Platform::Object, Windows::Data::Text::ITextPhoneme> {};

// uuids

template<> struct uuid<Windows::Data::Text::ISemanticTextQueryFactory> { define_guid(0x238C0503, 0xF995, 0x4587, 0x87, 0x77, 0xA2, 0xB7, 0xD8, 0xA, 0xCF, 0xEF);};
template<> struct uuid<Windows::Data::Text::ISemanticTextQuery> { define_guid(0x6A1CAB51, 0x1FB2, 0x4909, 0x80, 0xB8, 0x35, 0x73, 0x1A, 0x2B, 0x3E, 0x7F);};
template<> struct uuid<Windows::Data::Text::IUnicodeCharactersStatics> { define_guid(0x97909E87, 0x9291, 0x4F91, 0xB6, 0xC8, 0xB6, 0xE3, 0x59, 0xD7, 0xA7, 0xFB);};
template<> struct uuid<Windows::Data::Text::IAlternateWordForm> { define_guid(0x47396C1E, 0x51B9, 0x4207, 0x91, 0x46, 0x24, 0x8E, 0x63, 0x6A, 0x1D, 0x1D);};
template<> struct uuid<Windows::Data::Text::ISelectableWordSegment> { define_guid(0x916A4CB7, 0x8AA7, 0x4C78, 0xB3, 0x74, 0x5D, 0xED, 0xB7, 0x52, 0xE6, 0xB);};
template<> struct uuid<Windows::Data::Text::IWordSegment> { define_guid(0xD2D4BA6D, 0x987C, 0x4CC0, 0xB6, 0xBD, 0xD4, 0x9A, 0x11, 0xB3, 0x8F, 0x9A);};
template<> struct uuid<Windows::Data::Text::WordSegmentsTokenizingHandler> { define_guid(0xA5DD6357, 0xBF2A, 0x4C4F, 0xA3, 0x1F, 0x29, 0xE7, 0x1C, 0x6F, 0x8B, 0x35);};
template<> struct uuid<Windows::Data::Text::IWordsSegmenter> { define_guid(0x86B4D4D1, 0xB2FE, 0x4E34, 0xA8, 0x1D, 0x66, 0x64, 0x3, 0x0, 0x45, 0x4F);};
template<> struct uuid<Windows::Data::Text::IWordsSegmenterFactory> { define_guid(0xE6977274, 0xFC35, 0x455C, 0x8B, 0xFB, 0x6D, 0x7F, 0x46, 0x53, 0xCA, 0x97);};
template<> struct uuid<Windows::Data::Text::SelectableWordSegmentsTokenizingHandler> { define_guid(0x3A3DFC9C, 0xAEDE, 0x4DC7, 0x9E, 0x6C, 0x41, 0xC0, 0x44, 0xBD, 0x35, 0x92);};
template<> struct uuid<Windows::Data::Text::ISelectableWordsSegmenter> { define_guid(0xF6DC31E7, 0x4B13, 0x45C5, 0x88, 0x97, 0x7D, 0x71, 0x26, 0x9E, 0x8, 0x5D);};
template<> struct uuid<Windows::Data::Text::ISelectableWordsSegmenterFactory> { define_guid(0x8C7A7648, 0x6057, 0x4339, 0xBC, 0x70, 0xF2, 0x10, 0x1, 0xA, 0x41, 0x50);};
template<> struct uuid<Windows::Data::Text::ITextPredictionGenerator> { define_guid(0x5EACAB07, 0xABF1, 0x4CB6, 0x9D, 0x9E, 0x32, 0x6F, 0x2B, 0x46, 0x87, 0x56);};
template<> struct uuid<Windows::Data::Text::ITextPredictionGeneratorFactory> { define_guid(0x7257B416, 0x8BA2, 0x4751, 0x9D, 0x30, 0x9D, 0x85, 0x43, 0x56, 0x53, 0xA2);};
template<> struct uuid<Windows::Data::Text::ITextConversionGenerator> { define_guid(0x3606A5E, 0x2AA9, 0x4AB6, 0xAF, 0x8B, 0xA5, 0x62, 0xB6, 0x3A, 0x89, 0x92);};
template<> struct uuid<Windows::Data::Text::ITextConversionGeneratorFactory> { define_guid(0xFCAA3781, 0x3083, 0x49AB, 0xBE, 0x15, 0x56, 0xDF, 0xBB, 0xB7, 0x4D, 0x6F);};
template<> struct uuid<Windows::Data::Text::ITextReverseConversionGenerator> { define_guid(0x51E7F514, 0x9C51, 0x4D86, 0xAE, 0x1B, 0xB4, 0x98, 0xFB, 0xAD, 0x83, 0x13);};
template<> struct uuid<Windows::Data::Text::ITextReverseConversionGeneratorFactory> { define_guid(0x63BED326, 0x1FDA, 0x41F6, 0x89, 0xD5, 0x23, 0xDD, 0xEA, 0x3C, 0x72, 0x9A);};
template<> struct uuid<Windows::Data::Text::ITextReverseConversionGenerator2> { define_guid(0x1AAFD2EC, 0x85D6, 0x46FD, 0x82, 0x8A, 0x3A, 0x48, 0x30, 0xFA, 0x6E, 0x18);};
template<> struct uuid<Windows::Data::Text::ITextPhoneme> { define_guid(0x9362A40A, 0x9B7A, 0x4569, 0x94, 0xCF, 0xD8, 0x4F, 0x2F, 0x38, 0xCF, 0x9B);};

// types

namespace Windows { namespace Data { namespace Text {

// ISemanticTextQueryFactory
struct ISemanticTextQueryFactory : IInspectable {
	virtual STDMETHODIMP _Create(HSTRING aqsFilter, SemanticTextQuery* *result);
	virtual STDMETHODIMP _CreateWithLanguage(HSTRING aqsFilter, HSTRING filterLanguage, SemanticTextQuery* *result);
};

// ISemanticTextQuery
struct ISemanticTextQuery_raw : IInspectable {
	virtual STDMETHODIMP _Find(HSTRING content, Foundation::Collections::IVectorView<TextSegment>* *result);
	virtual STDMETHODIMP _FindInProperty(HSTRING propertyContent, HSTRING propertyName, Foundation::Collections::IVectorView<TextSegment>* *result);
};
template<typename X> struct ISemanticTextQuery_adaptor : X {
	ptr<Foundation::Collections::IVectorView<TextSegment>> Find(hstring_ref content) { Foundation::Collections::IVectorView<TextSegment>* result; hrcheck(X::get()->_Find(content, &result)); return from_abi(result); }
	ptr<Foundation::Collections::IVectorView<TextSegment>> FindInProperty(hstring_ref propertyContent, hstring_ref propertyName) { Foundation::Collections::IVectorView<TextSegment>* result; hrcheck(X::get()->_FindInProperty(propertyContent, propertyName, &result)); return from_abi(result); }
};
template<typename X> struct adapt<ISemanticTextQuery, X> : Windows::Data::Text::ISemanticTextQuery_adaptor<X> { typedef adapt ISemanticTextQuery; };
struct ISemanticTextQuery : ISemanticTextQuery_raw, generate<ISemanticTextQuery> {};

// SemanticTextQuery
template<typename> struct SemanticTextQuery_statics {
	static SemanticTextQuery *activate(hstring_ref aqsFilter) { SemanticTextQuery *result; hrcheck(get_activation_factory<SemanticTextQuery, ISemanticTextQueryFactory>()->_Create(aqsFilter, &result)); return result; }
	static SemanticTextQuery *activate(hstring_ref aqsFilter, hstring_ref filterLanguage) { SemanticTextQuery *result; hrcheck(get_activation_factory<SemanticTextQuery, ISemanticTextQueryFactory>()->_CreateWithLanguage(aqsFilter, filterLanguage, &result)); return result; }
};

template<typename X> struct statics<SemanticTextQuery, X> : X, Windows::Data::Text::SemanticTextQuery_statics<void> {
	using Windows::Data::Text::SemanticTextQuery_statics<void>::activate;
	typedef typename X::root_type SemanticTextQuery;
};
struct SemanticTextQuery : generate<SemanticTextQuery> {};

// IUnicodeCharactersStatics
struct IUnicodeCharactersStatics : IInspectable {
	virtual STDMETHODIMP _GetCodepointFromSurrogatePair(unsigned highSurrogate, unsigned lowSurrogate, unsigned *codepoint);
	virtual STDMETHODIMP _GetSurrogatePairFromCodepoint(unsigned codepoint, char *highSurrogate, char *lowSurrogate);
	virtual STDMETHODIMP _IsHighSurrogate(unsigned codepoint, bool *value);
	virtual STDMETHODIMP _IsLowSurrogate(unsigned codepoint, bool *value);
	virtual STDMETHODIMP _IsSupplementary(unsigned codepoint, bool *value);
	virtual STDMETHODIMP _IsNoncharacter(unsigned codepoint, bool *value);
	virtual STDMETHODIMP _IsWhitespace(unsigned codepoint, bool *value);
	virtual STDMETHODIMP _IsAlphabetic(unsigned codepoint, bool *value);
	virtual STDMETHODIMP _IsCased(unsigned codepoint, bool *value);
	virtual STDMETHODIMP _IsUppercase(unsigned codepoint, bool *value);
	virtual STDMETHODIMP _IsLowercase(unsigned codepoint, bool *value);
	virtual STDMETHODIMP _IsIdStart(unsigned codepoint, bool *value);
	virtual STDMETHODIMP _IsIdContinue(unsigned codepoint, bool *value);
	virtual STDMETHODIMP _IsGraphemeBase(unsigned codepoint, bool *value);
	virtual STDMETHODIMP _IsGraphemeExtend(unsigned codepoint, bool *value);
	virtual STDMETHODIMP _GetNumericType(unsigned codepoint, UnicodeNumericType *value);
	virtual STDMETHODIMP _GetGeneralCategory(unsigned codepoint, UnicodeGeneralCategory *value);
};

// UnicodeCharacters
template<typename> struct UnicodeCharacters_statics {
	static unsigned GetCodepointFromSurrogatePair(unsigned highSurrogate, unsigned lowSurrogate) { unsigned codepoint; hrcheck(get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>()->_GetCodepointFromSurrogatePair(highSurrogate, lowSurrogate, &codepoint)); return codepoint; }
	static char GetSurrogatePairFromCodepoint(unsigned codepoint, char *highSurrogate) { char lowSurrogate; hrcheck(get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>()->_GetSurrogatePairFromCodepoint(codepoint, highSurrogate, &lowSurrogate)); return lowSurrogate; }
	static bool IsHighSurrogate(unsigned codepoint) { bool value; hrcheck(get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>()->_IsHighSurrogate(codepoint, &value)); return value; }
	static bool IsLowSurrogate(unsigned codepoint) { bool value; hrcheck(get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>()->_IsLowSurrogate(codepoint, &value)); return value; }
	static bool IsSupplementary(unsigned codepoint) { bool value; hrcheck(get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>()->_IsSupplementary(codepoint, &value)); return value; }
	static bool IsNoncharacter(unsigned codepoint) { bool value; hrcheck(get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>()->_IsNoncharacter(codepoint, &value)); return value; }
	static bool IsWhitespace(unsigned codepoint) { bool value; hrcheck(get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>()->_IsWhitespace(codepoint, &value)); return value; }
	static bool IsAlphabetic(unsigned codepoint) { bool value; hrcheck(get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>()->_IsAlphabetic(codepoint, &value)); return value; }
	static bool IsCased(unsigned codepoint) { bool value; hrcheck(get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>()->_IsCased(codepoint, &value)); return value; }
	static bool IsUppercase(unsigned codepoint) { bool value; hrcheck(get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>()->_IsUppercase(codepoint, &value)); return value; }
	static bool IsLowercase(unsigned codepoint) { bool value; hrcheck(get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>()->_IsLowercase(codepoint, &value)); return value; }
	static bool IsIdStart(unsigned codepoint) { bool value; hrcheck(get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>()->_IsIdStart(codepoint, &value)); return value; }
	static bool IsIdContinue(unsigned codepoint) { bool value; hrcheck(get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>()->_IsIdContinue(codepoint, &value)); return value; }
	static bool IsGraphemeBase(unsigned codepoint) { bool value; hrcheck(get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>()->_IsGraphemeBase(codepoint, &value)); return value; }
	static bool IsGraphemeExtend(unsigned codepoint) { bool value; hrcheck(get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>()->_IsGraphemeExtend(codepoint, &value)); return value; }
	static UnicodeNumericType GetNumericType(unsigned codepoint) { UnicodeNumericType value; hrcheck(get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>()->_GetNumericType(codepoint, &value)); return value; }
	static UnicodeGeneralCategory GetGeneralCategory(unsigned codepoint) { UnicodeGeneralCategory value; hrcheck(get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>()->_GetGeneralCategory(codepoint, &value)); return value; }
};

template<typename X> struct statics<UnicodeCharacters, X> : X, Windows::Data::Text::UnicodeCharacters_statics<void> {
	typedef typename X::root_type UnicodeCharacters;
};
struct UnicodeCharacters : generate<UnicodeCharacters> {};

// IAlternateWordForm
struct IAlternateWordForm_raw : IInspectable {
	virtual STDMETHODIMP _get_SourceTextSegment(TextSegment *value);
	virtual STDMETHODIMP _get_AlternateText(HSTRING *value);
	virtual STDMETHODIMP _get_NormalizationFormat(AlternateNormalizationFormat *value);
};
template<typename X> struct IAlternateWordForm_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IAlternateWordForm_adaptor::AlternateText)->_get_AlternateText(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} AlternateText;
		struct : property {
			AlternateNormalizationFormat get() { AlternateNormalizationFormat value; hrcheck(enc(&IAlternateWordForm_adaptor::NormalizationFormat)->_get_NormalizationFormat(&value)); return value; }
			AlternateNormalizationFormat operator()() { return get(); }
			operator AlternateNormalizationFormat () { return get(); }
		} NormalizationFormat;
		struct : property {
			TextSegment get() { TextSegment value; hrcheck(enc(&IAlternateWordForm_adaptor::SourceTextSegment)->_get_SourceTextSegment(&value)); return value; }
			TextSegment operator()() { return get(); }
			operator TextSegment () { return get(); }
		} SourceTextSegment;
	};
	IAlternateWordForm_adaptor() {}
};
template<typename X> struct adapt<IAlternateWordForm, X> : Windows::Data::Text::IAlternateWordForm_adaptor<X> { typedef adapt IAlternateWordForm; };
struct IAlternateWordForm : IAlternateWordForm_raw, generate<IAlternateWordForm> {};

// AlternateWordForm
template<typename X> struct statics<AlternateWordForm, X> : X {
	typedef typename X::root_type AlternateWordForm;
};
struct AlternateWordForm : generate<AlternateWordForm> {};

// ISelectableWordSegment
struct ISelectableWordSegment_raw : IInspectable {
	virtual STDMETHODIMP _get_Text(HSTRING *value);
	virtual STDMETHODIMP _get_SourceTextSegment(TextSegment *value);
};
template<typename X> struct ISelectableWordSegment_adaptor : X {
	union {
		struct : property {
			TextSegment get() { TextSegment value; hrcheck(enc(&ISelectableWordSegment_adaptor::SourceTextSegment)->_get_SourceTextSegment(&value)); return value; }
			TextSegment operator()() { return get(); }
			operator TextSegment () { return get(); }
		} SourceTextSegment;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&ISelectableWordSegment_adaptor::Text)->_get_Text(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Text;
	};
	ISelectableWordSegment_adaptor() {}
};
template<typename X> struct adapt<ISelectableWordSegment, X> : Windows::Data::Text::ISelectableWordSegment_adaptor<X> { typedef adapt ISelectableWordSegment; };
struct ISelectableWordSegment : ISelectableWordSegment_raw, generate<ISelectableWordSegment> {};

// IWordSegment
struct IWordSegment_raw : IInspectable {
	virtual STDMETHODIMP _get_Text(HSTRING *value);
	virtual STDMETHODIMP _get_SourceTextSegment(TextSegment *value);
	virtual STDMETHODIMP _get_AlternateForms(Foundation::Collections::IVectorView<AlternateWordForm*>* *value);
};
template<typename X> struct IWordSegment_adaptor : X {
	union {
		struct : property {
			ptr<Foundation::Collections::IVectorView<ptr<AlternateWordForm>>> get() { Foundation::Collections::IVectorView<AlternateWordForm*>* value; hrcheck(enc(&IWordSegment_adaptor::AlternateForms)->_get_AlternateForms(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<ptr<AlternateWordForm>>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<ptr<AlternateWordForm>>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<ptr<AlternateWordForm>>> operator->() { return get(); }
		} AlternateForms;
		struct : property {
			TextSegment get() { TextSegment value; hrcheck(enc(&IWordSegment_adaptor::SourceTextSegment)->_get_SourceTextSegment(&value)); return value; }
			TextSegment operator()() { return get(); }
			operator TextSegment () { return get(); }
		} SourceTextSegment;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IWordSegment_adaptor::Text)->_get_Text(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Text;
	};
	IWordSegment_adaptor() {}
};
template<typename X> struct adapt<IWordSegment, X> : Windows::Data::Text::IWordSegment_adaptor<X> { typedef adapt IWordSegment; };
struct IWordSegment : IWordSegment_raw, generate<IWordSegment> {};

// WordSegment
template<typename X> struct statics<WordSegment, X> : X {
	typedef typename X::root_type WordSegment;
};
struct WordSegment : generate<WordSegment> {};

// WordSegmentsTokenizingHandler
struct WordSegmentsTokenizingHandler : IUnknown {
	virtual STDMETHODIMP _Invoke(Foundation::Collections::IIterable<WordSegment*>* precedingWords, Foundation::Collections::IIterable<WordSegment*>* words) = 0;
};

// IWordsSegmenter
struct IWordsSegmenter_raw : IInspectable {
	virtual STDMETHODIMP _get_ResolvedLanguage(HSTRING *value);
	virtual STDMETHODIMP _GetTokenAt(HSTRING text, unsigned startIndex, WordSegment* *result);
	virtual STDMETHODIMP _GetTokens(HSTRING text, Foundation::Collections::IVectorView<WordSegment*>* *result);
	virtual STDMETHODIMP _Tokenize(HSTRING text, unsigned startIndex, WordSegmentsTokenizingHandler* handler);
};
template<typename X> struct IWordsSegmenter_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IWordsSegmenter_adaptor::ResolvedLanguage)->_get_ResolvedLanguage(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} ResolvedLanguage;
	};
	ptr<WordSegment> GetTokenAt(hstring_ref text, unsigned startIndex) { WordSegment* result; hrcheck(X::get()->_GetTokenAt(text, startIndex, &result)); return from_abi(result); }
	ptr<Foundation::Collections::IVectorView<ptr<WordSegment>>> GetTokens(hstring_ref text) { Foundation::Collections::IVectorView<WordSegment*>* result; hrcheck(X::get()->_GetTokens(text, &result)); return from_abi(result); }
	void Tokenize(hstring_ref text, unsigned startIndex, handler_ref<WordSegmentsTokenizingHandler> handler) { hrcheck(X::get()->_Tokenize(text, startIndex, handler)); }
	IWordsSegmenter_adaptor() {}
};
template<typename X> struct adapt<IWordsSegmenter, X> : Windows::Data::Text::IWordsSegmenter_adaptor<X> { typedef adapt IWordsSegmenter; };
struct IWordsSegmenter : IWordsSegmenter_raw, generate<IWordsSegmenter> {};

// IWordsSegmenterFactory
struct IWordsSegmenterFactory : IInspectable {
	virtual STDMETHODIMP _CreateWithLanguage(HSTRING language, WordsSegmenter* *result);
};

// WordsSegmenter
template<typename> struct WordsSegmenter_statics {
	static WordsSegmenter *activate(hstring_ref language) { WordsSegmenter *result; hrcheck(get_activation_factory<WordsSegmenter, IWordsSegmenterFactory>()->_CreateWithLanguage(language, &result)); return result; }
};

template<typename X> struct statics<WordsSegmenter, X> : X, Windows::Data::Text::WordsSegmenter_statics<void> {
	using Windows::Data::Text::WordsSegmenter_statics<void>::activate;
	typedef typename X::root_type WordsSegmenter;
};
struct WordsSegmenter : generate<WordsSegmenter> {};

// SelectableWordSegment
template<typename X> struct statics<SelectableWordSegment, X> : X {
	typedef typename X::root_type SelectableWordSegment;
};
struct SelectableWordSegment : generate<SelectableWordSegment> {};

// SelectableWordSegmentsTokenizingHandler
struct SelectableWordSegmentsTokenizingHandler : IUnknown {
	virtual STDMETHODIMP _Invoke(Foundation::Collections::IIterable<SelectableWordSegment*>* precedingWords, Foundation::Collections::IIterable<SelectableWordSegment*>* words) = 0;
};

// ISelectableWordsSegmenter
struct ISelectableWordsSegmenter_raw : IInspectable {
	virtual STDMETHODIMP _get_ResolvedLanguage(HSTRING *value);
	virtual STDMETHODIMP _GetTokenAt(HSTRING text, unsigned startIndex, SelectableWordSegment* *result);
	virtual STDMETHODIMP _GetTokens(HSTRING text, Foundation::Collections::IVectorView<SelectableWordSegment*>* *result);
	virtual STDMETHODIMP _Tokenize(HSTRING text, unsigned startIndex, SelectableWordSegmentsTokenizingHandler* handler);
};
template<typename X> struct ISelectableWordsSegmenter_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&ISelectableWordsSegmenter_adaptor::ResolvedLanguage)->_get_ResolvedLanguage(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} ResolvedLanguage;
	};
	ptr<SelectableWordSegment> GetTokenAt(hstring_ref text, unsigned startIndex) { SelectableWordSegment* result; hrcheck(X::get()->_GetTokenAt(text, startIndex, &result)); return from_abi(result); }
	ptr<Foundation::Collections::IVectorView<ptr<SelectableWordSegment>>> GetTokens(hstring_ref text) { Foundation::Collections::IVectorView<SelectableWordSegment*>* result; hrcheck(X::get()->_GetTokens(text, &result)); return from_abi(result); }
	void Tokenize(hstring_ref text, unsigned startIndex, handler_ref<SelectableWordSegmentsTokenizingHandler> handler) { hrcheck(X::get()->_Tokenize(text, startIndex, handler)); }
	ISelectableWordsSegmenter_adaptor() {}
};
template<typename X> struct adapt<ISelectableWordsSegmenter, X> : Windows::Data::Text::ISelectableWordsSegmenter_adaptor<X> { typedef adapt ISelectableWordsSegmenter; };
struct ISelectableWordsSegmenter : ISelectableWordsSegmenter_raw, generate<ISelectableWordsSegmenter> {};

// ISelectableWordsSegmenterFactory
struct ISelectableWordsSegmenterFactory : IInspectable {
	virtual STDMETHODIMP _CreateWithLanguage(HSTRING language, SelectableWordsSegmenter* *result);
};

// SelectableWordsSegmenter
template<typename> struct SelectableWordsSegmenter_statics {
	static SelectableWordsSegmenter *activate(hstring_ref language) { SelectableWordsSegmenter *result; hrcheck(get_activation_factory<SelectableWordsSegmenter, ISelectableWordsSegmenterFactory>()->_CreateWithLanguage(language, &result)); return result; }
};

template<typename X> struct statics<SelectableWordsSegmenter, X> : X, Windows::Data::Text::SelectableWordsSegmenter_statics<void> {
	using Windows::Data::Text::SelectableWordsSegmenter_statics<void>::activate;
	typedef typename X::root_type SelectableWordsSegmenter;
};
struct SelectableWordsSegmenter : generate<SelectableWordsSegmenter> {};

// ITextPredictionGenerator
struct ITextPredictionGenerator_raw : IInspectable {
	virtual STDMETHODIMP _get_ResolvedLanguage(HSTRING *value);
	virtual STDMETHODIMP _get_LanguageAvailableButNotInstalled(bool *value);
	virtual STDMETHODIMP _GetCandidatesAsync(HSTRING input, Foundation::IAsyncOperation<Foundation::Collections::IVectorView<HSTRING>*>* *result);
	virtual STDMETHODIMP _GetCandidatesWithMaxCountAsync(HSTRING input, unsigned maxCandidates, Foundation::IAsyncOperation<Foundation::Collections::IVectorView<HSTRING>*>* *result);
};
template<typename X> struct ITextPredictionGenerator_adaptor : X {
	union {
		struct : property {
			bool get() { bool value; hrcheck(enc(&ITextPredictionGenerator_adaptor::LanguageAvailableButNotInstalled)->_get_LanguageAvailableButNotInstalled(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} LanguageAvailableButNotInstalled;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&ITextPredictionGenerator_adaptor::ResolvedLanguage)->_get_ResolvedLanguage(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} ResolvedLanguage;
	};
	ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<hstring>>>> GetCandidatesAsync(hstring_ref input) { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<HSTRING>*>* result; hrcheck(X::get()->_GetCandidatesAsync(input, &result)); return from_abi(result); }
	ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<hstring>>>> GetCandidatesAsync(hstring_ref input, unsigned maxCandidates) { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<HSTRING>*>* result; hrcheck(X::get()->_GetCandidatesWithMaxCountAsync(input, maxCandidates, &result)); return from_abi(result); }
	ITextPredictionGenerator_adaptor() {}
};
template<typename X> struct adapt<ITextPredictionGenerator, X> : Windows::Data::Text::ITextPredictionGenerator_adaptor<X> { typedef adapt ITextPredictionGenerator; };
struct ITextPredictionGenerator : ITextPredictionGenerator_raw, generate<ITextPredictionGenerator> {};

// ITextPredictionGeneratorFactory
struct ITextPredictionGeneratorFactory : IInspectable {
	virtual STDMETHODIMP _Create(HSTRING languageTag, TextPredictionGenerator* *result);
};

// TextPredictionGenerator
template<typename> struct TextPredictionGenerator_statics {
	static TextPredictionGenerator *activate(hstring_ref languageTag) { TextPredictionGenerator *result; hrcheck(get_activation_factory<TextPredictionGenerator, ITextPredictionGeneratorFactory>()->_Create(languageTag, &result)); return result; }
};

template<typename X> struct statics<TextPredictionGenerator, X> : X, Windows::Data::Text::TextPredictionGenerator_statics<void> {
	using Windows::Data::Text::TextPredictionGenerator_statics<void>::activate;
	typedef typename X::root_type TextPredictionGenerator;
};
struct TextPredictionGenerator : generate<TextPredictionGenerator> {
	using ITextPredictionGenerator::GetCandidatesAsync;
};

// ITextConversionGenerator
struct ITextConversionGenerator_raw : IInspectable {
	virtual STDMETHODIMP _get_ResolvedLanguage(HSTRING *value);
	virtual STDMETHODIMP _get_LanguageAvailableButNotInstalled(bool *value);
	virtual STDMETHODIMP _GetCandidatesAsync(HSTRING input, Foundation::IAsyncOperation<Foundation::Collections::IVectorView<HSTRING>*>* *result);
	virtual STDMETHODIMP _GetCandidatesWithMaxCountAsync(HSTRING input, unsigned maxCandidates, Foundation::IAsyncOperation<Foundation::Collections::IVectorView<HSTRING>*>* *result);
};
template<typename X> struct ITextConversionGenerator_adaptor : X {
	union {
		struct : property {
			bool get() { bool value; hrcheck(enc(&ITextConversionGenerator_adaptor::LanguageAvailableButNotInstalled)->_get_LanguageAvailableButNotInstalled(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} LanguageAvailableButNotInstalled;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&ITextConversionGenerator_adaptor::ResolvedLanguage)->_get_ResolvedLanguage(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} ResolvedLanguage;
	};
	ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<hstring>>>> GetCandidatesAsync(hstring_ref input) { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<HSTRING>*>* result; hrcheck(X::get()->_GetCandidatesAsync(input, &result)); return from_abi(result); }
	ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<hstring>>>> GetCandidatesAsync(hstring_ref input, unsigned maxCandidates) { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<HSTRING>*>* result; hrcheck(X::get()->_GetCandidatesWithMaxCountAsync(input, maxCandidates, &result)); return from_abi(result); }
	ITextConversionGenerator_adaptor() {}
};
template<typename X> struct adapt<ITextConversionGenerator, X> : Windows::Data::Text::ITextConversionGenerator_adaptor<X> { typedef adapt ITextConversionGenerator; };
struct ITextConversionGenerator : ITextConversionGenerator_raw, generate<ITextConversionGenerator> {};

// ITextConversionGeneratorFactory
struct ITextConversionGeneratorFactory : IInspectable {
	virtual STDMETHODIMP _Create(HSTRING languageTag, TextConversionGenerator* *result);
};

// TextConversionGenerator
template<typename> struct TextConversionGenerator_statics {
	static TextConversionGenerator *activate(hstring_ref languageTag) { TextConversionGenerator *result; hrcheck(get_activation_factory<TextConversionGenerator, ITextConversionGeneratorFactory>()->_Create(languageTag, &result)); return result; }
};

template<typename X> struct statics<TextConversionGenerator, X> : X, Windows::Data::Text::TextConversionGenerator_statics<void> {
	using Windows::Data::Text::TextConversionGenerator_statics<void>::activate;
	typedef typename X::root_type TextConversionGenerator;
};
struct TextConversionGenerator : generate<TextConversionGenerator> {
	using ITextConversionGenerator::GetCandidatesAsync;
};

// ITextReverseConversionGenerator
struct ITextReverseConversionGenerator_raw : IInspectable {
	virtual STDMETHODIMP _get_ResolvedLanguage(HSTRING *value);
	virtual STDMETHODIMP _get_LanguageAvailableButNotInstalled(bool *value);
	virtual STDMETHODIMP _ConvertBackAsync(HSTRING input, Foundation::IAsyncOperation<HSTRING>* *result);
};
template<typename X> struct ITextReverseConversionGenerator_adaptor : X {
	union {
		struct : property {
			bool get() { bool value; hrcheck(enc(&ITextReverseConversionGenerator_adaptor::LanguageAvailableButNotInstalled)->_get_LanguageAvailableButNotInstalled(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} LanguageAvailableButNotInstalled;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&ITextReverseConversionGenerator_adaptor::ResolvedLanguage)->_get_ResolvedLanguage(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} ResolvedLanguage;
	};
	ptr<Foundation::IAsyncOperation<hstring>> ConvertBackAsync(hstring_ref input) { Foundation::IAsyncOperation<HSTRING>* result; hrcheck(X::get()->_ConvertBackAsync(input, &result)); return from_abi(result); }
	ITextReverseConversionGenerator_adaptor() {}
};
template<typename X> struct adapt<ITextReverseConversionGenerator, X> : Windows::Data::Text::ITextReverseConversionGenerator_adaptor<X> { typedef adapt ITextReverseConversionGenerator; };
struct ITextReverseConversionGenerator : ITextReverseConversionGenerator_raw, generate<ITextReverseConversionGenerator> {};

// ITextReverseConversionGeneratorFactory
struct ITextReverseConversionGeneratorFactory : IInspectable {
	virtual STDMETHODIMP _Create(HSTRING languageTag, TextReverseConversionGenerator* *result);
};

// ITextReverseConversionGenerator2
struct ITextReverseConversionGenerator2_raw : IInspectable {
	virtual STDMETHODIMP _GetPhonemesAsync(HSTRING input, Foundation::IAsyncOperation<Foundation::Collections::IVectorView<TextPhoneme*>*>* *result);
};
template<typename X> struct ITextReverseConversionGenerator2_adaptor : X {
	ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<ptr<TextPhoneme>>>>> GetPhonemesAsync(hstring_ref input) { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<TextPhoneme*>*>* result; hrcheck(X::get()->_GetPhonemesAsync(input, &result)); return from_abi(result); }
};
template<typename X> struct adapt<ITextReverseConversionGenerator2, X> : Windows::Data::Text::ITextReverseConversionGenerator2_adaptor<X> { typedef adapt ITextReverseConversionGenerator2; };
struct ITextReverseConversionGenerator2 : ITextReverseConversionGenerator2_raw, generate<ITextReverseConversionGenerator2> {};

// TextReverseConversionGenerator
template<typename> struct TextReverseConversionGenerator_statics {
	static TextReverseConversionGenerator *activate(hstring_ref languageTag) { TextReverseConversionGenerator *result; hrcheck(get_activation_factory<TextReverseConversionGenerator, ITextReverseConversionGeneratorFactory>()->_Create(languageTag, &result)); return result; }
};

template<typename X> struct statics<TextReverseConversionGenerator, X> : X, Windows::Data::Text::TextReverseConversionGenerator_statics<void> {
	using Windows::Data::Text::TextReverseConversionGenerator_statics<void>::activate;
	typedef typename X::root_type TextReverseConversionGenerator;
};
struct TextReverseConversionGenerator : generate<TextReverseConversionGenerator> {};

// ITextPhoneme
struct ITextPhoneme_raw : IInspectable {
	virtual STDMETHODIMP _get_DisplayText(HSTRING *value);
	virtual STDMETHODIMP _get_ReadingText(HSTRING *value);
};
template<typename X> struct ITextPhoneme_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&ITextPhoneme_adaptor::DisplayText)->_get_DisplayText(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} DisplayText;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&ITextPhoneme_adaptor::ReadingText)->_get_ReadingText(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} ReadingText;
	};
	ITextPhoneme_adaptor() {}
};
template<typename X> struct adapt<ITextPhoneme, X> : Windows::Data::Text::ITextPhoneme_adaptor<X> { typedef adapt ITextPhoneme; };
struct ITextPhoneme : ITextPhoneme_raw, generate<ITextPhoneme> {};

// TextPhoneme
template<typename X> struct statics<TextPhoneme, X> : X {
	typedef typename X::root_type TextPhoneme;
};
struct TextPhoneme : generate<TextPhoneme> {};
}}}
} // namespace iso_winrt
