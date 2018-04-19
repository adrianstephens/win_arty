#pragma once
// generated by isopod tools
// namespaces:
// Windows.Media.SpeechSynthesis

#include "Windows.Media.SpeechSynthesis.0.h"
#include "Windows.Media.Core.h"
#include "Windows.Storage.Streams.h"
#include "Windows.Foundation.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IVectorView;
}}
namespace Media {
struct IMediaMarker;
}}

// defs

template<> struct def<Windows::Media::SpeechSynthesis::VoiceGender> : enum_type<int> {};
template<> struct def<Windows::Media::SpeechSynthesis::IVoiceInformation> : interface_type<> {};
template<> struct def<Windows::Media::SpeechSynthesis::VoiceInformation> : class_type<Platform::Object, Windows::Media::SpeechSynthesis::IVoiceInformation> {};
template<> struct def<Windows::Media::SpeechSynthesis::IInstalledVoicesStatic> : interface_type<> {};
template<> struct def<Windows::Media::SpeechSynthesis::IInstalledVoicesStatic2> : interface_type<> {};
template<> struct def<Windows::Media::SpeechSynthesis::ISpeechSynthesisStream> : interface_type<Windows::Storage::Streams::IRandomAccessStreamWithContentType, Windows::Storage::Streams::IRandomAccessStream, Windows::Foundation::IClosable, Windows::Storage::Streams::IInputStream, Windows::Storage::Streams::IOutputStream, Windows::Storage::Streams::IContentTypeProvider> {};
template<> struct def<Windows::Media::SpeechSynthesis::SpeechSynthesisStream> : class_type<Platform::Object, Windows::Media::SpeechSynthesis::ISpeechSynthesisStream, Windows::Media::Core::ITimedMetadataTrackProvider> {};
template<> struct def<Windows::Media::SpeechSynthesis::ISpeechSynthesizer> : interface_type<> {};
template<> struct def<Windows::Media::SpeechSynthesis::ISpeechSynthesizer2> : interface_type<> {};
template<> struct def<Windows::Media::SpeechSynthesis::SpeechPunctuationSilence> : enum_type<int> {};
template<> struct def<Windows::Media::SpeechSynthesis::SpeechAppendedSilence> : enum_type<int> {};
template<> struct def<Windows::Media::SpeechSynthesis::ISpeechSynthesizerOptions3> : interface_type<> {};
template<> struct def<Windows::Media::SpeechSynthesis::ISpeechSynthesizerOptions2> : interface_type<> {};
template<> struct def<Windows::Media::SpeechSynthesis::ISpeechSynthesizerOptions> : interface_type<> {};
template<> struct def<Windows::Media::SpeechSynthesis::SpeechSynthesizerOptions> : class_type<Platform::Object, Windows::Media::SpeechSynthesis::ISpeechSynthesizerOptions, Windows::Media::SpeechSynthesis::ISpeechSynthesizerOptions2, Windows::Media::SpeechSynthesis::ISpeechSynthesizerOptions3> {};
template<> struct def<Windows::Media::SpeechSynthesis::SpeechSynthesizer> : class_type<Platform::Object, Windows::Media::SpeechSynthesis::ISpeechSynthesizer, Windows::Foundation::IClosable, Windows::Media::SpeechSynthesis::ISpeechSynthesizer2> {};

// uuids

template<> struct uuid<Windows::Media::SpeechSynthesis::IVoiceInformation> { define_guid(0xB127D6A4, 0x1291, 0x4604, 0xAA, 0x9C, 0x83, 0x13, 0x40, 0x83, 0x35, 0x2C);};
template<> struct uuid<Windows::Media::SpeechSynthesis::IInstalledVoicesStatic> { define_guid(0x7D526ECC, 0x7533, 0x4C3F, 0x85, 0xBE, 0x88, 0x8C, 0x2B, 0xAE, 0xEB, 0xDC);};
template<> struct uuid<Windows::Media::SpeechSynthesis::IInstalledVoicesStatic2> { define_guid(0x64255F2E, 0x358D, 0x4058, 0xBE, 0x9A, 0xFD, 0x3F, 0xCB, 0x42, 0x35, 0x30);};
template<> struct uuid<Windows::Media::SpeechSynthesis::ISpeechSynthesisStream> { define_guid(0x83E46E93, 0x244C, 0x4622, 0xBA, 0xB, 0x62, 0x29, 0xC4, 0xD0, 0xD6, 0x5D);};
template<> struct uuid<Windows::Media::SpeechSynthesis::ISpeechSynthesizer> { define_guid(0xCE9F7C76, 0x97F4, 0x4CED, 0xAD, 0x68, 0xD5, 0x1C, 0x45, 0x8E, 0x45, 0xC6);};
template<> struct uuid<Windows::Media::SpeechSynthesis::ISpeechSynthesizer2> { define_guid(0xA7C5ECB2, 0x4339, 0x4D6A, 0xBB, 0xF8, 0xC7, 0xA4, 0xF1, 0x54, 0x4C, 0x2E);};
template<> struct uuid<Windows::Media::SpeechSynthesis::ISpeechSynthesizerOptions3> { define_guid(0x401ED877, 0x902C, 0x4814, 0xA5, 0x82, 0xA5, 0xD0, 0xC0, 0x76, 0x9F, 0xA8);};
template<> struct uuid<Windows::Media::SpeechSynthesis::ISpeechSynthesizerOptions2> { define_guid(0x1CBEF60E, 0x119C, 0x4BED, 0xB1, 0x18, 0xD2, 0x50, 0xC3, 0xA2, 0x57, 0x93);};
template<> struct uuid<Windows::Media::SpeechSynthesis::ISpeechSynthesizerOptions> { define_guid(0xA0E23871, 0xCC3D, 0x43C9, 0x91, 0xB1, 0xEE, 0x18, 0x53, 0x24, 0xD8, 0x3D);};

// types

namespace Windows { namespace Media { namespace SpeechSynthesis {

// IVoiceInformation
struct IVoiceInformation_raw : IInspectable {
	virtual STDMETHODIMP _get_DisplayName(HSTRING *value);
	virtual STDMETHODIMP _get_Id(HSTRING *value);
	virtual STDMETHODIMP _get_Language(HSTRING *value);
	virtual STDMETHODIMP _get_Description(HSTRING *value);
	virtual STDMETHODIMP _get_Gender(VoiceGender *value);
};
template<typename X> struct IVoiceInformation_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IVoiceInformation_adaptor::Description)->_get_Description(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Description;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IVoiceInformation_adaptor::DisplayName)->_get_DisplayName(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} DisplayName;
		struct : property {
			VoiceGender get() { VoiceGender value; hrcheck(enc(&IVoiceInformation_adaptor::Gender)->_get_Gender(&value)); return value; }
			VoiceGender operator()() { return get(); }
			operator VoiceGender () { return get(); }
		} Gender;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IVoiceInformation_adaptor::Id)->_get_Id(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Id;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IVoiceInformation_adaptor::Language)->_get_Language(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Language;
	};
	IVoiceInformation_adaptor() {}
};
template<typename X> struct adapt<IVoiceInformation, X> : Windows::Media::SpeechSynthesis::IVoiceInformation_adaptor<X> { typedef adapt IVoiceInformation; };
struct IVoiceInformation : IVoiceInformation_raw, generate<IVoiceInformation> {};

// VoiceInformation
template<typename X> struct statics<VoiceInformation, X> : X {
	typedef typename X::root_type VoiceInformation;
};
struct VoiceInformation : generate<VoiceInformation> {};

// IInstalledVoicesStatic
struct IInstalledVoicesStatic : IInspectable {
	virtual STDMETHODIMP _get_AllVoices(Foundation::Collections::IVectorView<VoiceInformation*>* *value);
	virtual STDMETHODIMP _get_DefaultVoice(VoiceInformation* *value);
};

// IInstalledVoicesStatic2
struct IInstalledVoicesStatic2 : IInspectable {
	virtual STDMETHODIMP _TrySetDefaultVoiceAsync(VoiceInformation* voice, Foundation::IAsyncOperation<bool>* *result);
};

// ISpeechSynthesisStream
struct ISpeechSynthesisStream_raw : IInspectable {
	virtual STDMETHODIMP _get_Markers(Foundation::Collections::IVectorView<IMediaMarker*>* *value);
};
template<typename X> struct ISpeechSynthesisStream_adaptor : X {
	union {
		struct : property {
			ptr<Foundation::Collections::IVectorView<ptr<IMediaMarker>>> get() { Foundation::Collections::IVectorView<IMediaMarker*>* value; hrcheck(enc(&ISpeechSynthesisStream_adaptor::Markers)->_get_Markers(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<ptr<IMediaMarker>>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<ptr<IMediaMarker>>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<ptr<IMediaMarker>>> operator->() { return get(); }
		} Markers;
	};
	ISpeechSynthesisStream_adaptor() {}
};
template<typename X> struct adapt<ISpeechSynthesisStream, X> : Windows::Media::SpeechSynthesis::ISpeechSynthesisStream_adaptor<X> { typedef adapt ISpeechSynthesisStream; };
struct ISpeechSynthesisStream : ISpeechSynthesisStream_raw, generate<ISpeechSynthesisStream> {};

// SpeechSynthesisStream
template<typename X> struct statics<SpeechSynthesisStream, X> : X {
	typedef typename X::root_type SpeechSynthesisStream;
};
struct SpeechSynthesisStream : generate<SpeechSynthesisStream> {};

// ISpeechSynthesizer
struct ISpeechSynthesizer_raw : IInspectable {
	virtual STDMETHODIMP _SynthesizeTextToStreamAsync(HSTRING text, Foundation::IAsyncOperation<SpeechSynthesisStream*>* *operation);
	virtual STDMETHODIMP _SynthesizeSsmlToStreamAsync(HSTRING Ssml, Foundation::IAsyncOperation<SpeechSynthesisStream*>* *operation);
	virtual STDMETHODIMP _put_Voice(VoiceInformation* value);
	virtual STDMETHODIMP _get_Voice(VoiceInformation* *value);
};
template<typename X> struct ISpeechSynthesizer_adaptor : X {
	union {
		struct : property {
			ptr<VoiceInformation> get() { VoiceInformation* value; hrcheck(enc(&ISpeechSynthesizer_adaptor::Voice)->_get_Voice(&value)); return from_abi(value); }
			ptr<VoiceInformation> operator()() { return get(); }
			operator ptr<VoiceInformation> () { return get(); }
			ptr<VoiceInformation> operator->() { return get(); }
			void put(pptr<VoiceInformation> value) { hrcheck(enc(&ISpeechSynthesizer_adaptor::Voice)->_put_Voice(value)); }
			void operator=(pptr<VoiceInformation> value) { put(value); }
			void operator()(pptr<VoiceInformation> value) { put(value); }
		} Voice;
	};
	ptr<Foundation::IAsyncOperation<ptr<SpeechSynthesisStream>>> SynthesizeTextToStreamAsync(hstring_ref text) { Foundation::IAsyncOperation<SpeechSynthesisStream*>* operation; hrcheck(X::get()->_SynthesizeTextToStreamAsync(text, &operation)); return from_abi(operation); }
	ptr<Foundation::IAsyncOperation<ptr<SpeechSynthesisStream>>> SynthesizeSsmlToStreamAsync(hstring_ref Ssml) { Foundation::IAsyncOperation<SpeechSynthesisStream*>* operation; hrcheck(X::get()->_SynthesizeSsmlToStreamAsync(Ssml, &operation)); return from_abi(operation); }
	ISpeechSynthesizer_adaptor() {}
};
template<typename X> struct adapt<ISpeechSynthesizer, X> : Windows::Media::SpeechSynthesis::ISpeechSynthesizer_adaptor<X> { typedef adapt ISpeechSynthesizer; };
struct ISpeechSynthesizer : ISpeechSynthesizer_raw, generate<ISpeechSynthesizer> {};

// ISpeechSynthesizer2
struct ISpeechSynthesizer2_raw : IInspectable {
	virtual STDMETHODIMP _get_Options(SpeechSynthesizerOptions* *value);
};
template<typename X> struct ISpeechSynthesizer2_adaptor : X {
	union {
		struct : property {
			ptr<SpeechSynthesizerOptions> get() { SpeechSynthesizerOptions* value; hrcheck(enc(&ISpeechSynthesizer2_adaptor::Options)->_get_Options(&value)); return from_abi(value); }
			ptr<SpeechSynthesizerOptions> operator()() { return get(); }
			operator ptr<SpeechSynthesizerOptions> () { return get(); }
			ptr<SpeechSynthesizerOptions> operator->() { return get(); }
		} Options;
	};
	ISpeechSynthesizer2_adaptor() {}
};
template<typename X> struct adapt<ISpeechSynthesizer2, X> : Windows::Media::SpeechSynthesis::ISpeechSynthesizer2_adaptor<X> { typedef adapt ISpeechSynthesizer2; };
struct ISpeechSynthesizer2 : ISpeechSynthesizer2_raw, generate<ISpeechSynthesizer2> {};

// ISpeechSynthesizerOptions3
struct ISpeechSynthesizerOptions3_raw : IInspectable {
	virtual STDMETHODIMP _get_AppendedSilence(SpeechAppendedSilence *value);
	virtual STDMETHODIMP _put_AppendedSilence(SpeechAppendedSilence value);
	virtual STDMETHODIMP _get_PunctuationSilence(SpeechPunctuationSilence *value);
	virtual STDMETHODIMP _put_PunctuationSilence(SpeechPunctuationSilence value);
};
template<typename X> struct ISpeechSynthesizerOptions3_adaptor : X {
	union {
		struct : property {
			SpeechAppendedSilence get() { SpeechAppendedSilence value; hrcheck(enc(&ISpeechSynthesizerOptions3_adaptor::AppendedSilence)->_get_AppendedSilence(&value)); return value; }
			SpeechAppendedSilence operator()() { return get(); }
			operator SpeechAppendedSilence () { return get(); }
			void put(SpeechAppendedSilence value) { hrcheck(enc(&ISpeechSynthesizerOptions3_adaptor::AppendedSilence)->_put_AppendedSilence(value)); }
			void operator=(SpeechAppendedSilence value) { put(value); }
			void operator()(SpeechAppendedSilence value) { put(value); }
		} AppendedSilence;
		struct : property {
			SpeechPunctuationSilence get() { SpeechPunctuationSilence value; hrcheck(enc(&ISpeechSynthesizerOptions3_adaptor::PunctuationSilence)->_get_PunctuationSilence(&value)); return value; }
			SpeechPunctuationSilence operator()() { return get(); }
			operator SpeechPunctuationSilence () { return get(); }
			void put(SpeechPunctuationSilence value) { hrcheck(enc(&ISpeechSynthesizerOptions3_adaptor::PunctuationSilence)->_put_PunctuationSilence(value)); }
			void operator=(SpeechPunctuationSilence value) { put(value); }
			void operator()(SpeechPunctuationSilence value) { put(value); }
		} PunctuationSilence;
	};
	ISpeechSynthesizerOptions3_adaptor() {}
};
template<typename X> struct adapt<ISpeechSynthesizerOptions3, X> : Windows::Media::SpeechSynthesis::ISpeechSynthesizerOptions3_adaptor<X> { typedef adapt ISpeechSynthesizerOptions3; };
struct ISpeechSynthesizerOptions3 : ISpeechSynthesizerOptions3_raw, generate<ISpeechSynthesizerOptions3> {};

// ISpeechSynthesizerOptions2
struct ISpeechSynthesizerOptions2_raw : IInspectable {
	virtual STDMETHODIMP _get_AudioVolume(double *value);
	virtual STDMETHODIMP _put_AudioVolume(double value);
	virtual STDMETHODIMP _get_SpeakingRate(double *value);
	virtual STDMETHODIMP _put_SpeakingRate(double value);
	virtual STDMETHODIMP _get_AudioPitch(double *value);
	virtual STDMETHODIMP _put_AudioPitch(double value);
};
template<typename X> struct ISpeechSynthesizerOptions2_adaptor : X {
	union {
		struct : property {
			double get() { double value; hrcheck(enc(&ISpeechSynthesizerOptions2_adaptor::AudioPitch)->_get_AudioPitch(&value)); return value; }
			double operator()() { return get(); }
			operator double () { return get(); }
			void put(double value) { hrcheck(enc(&ISpeechSynthesizerOptions2_adaptor::AudioPitch)->_put_AudioPitch(value)); }
			void operator=(double value) { put(value); }
			void operator()(double value) { put(value); }
		} AudioPitch;
		struct : property {
			double get() { double value; hrcheck(enc(&ISpeechSynthesizerOptions2_adaptor::AudioVolume)->_get_AudioVolume(&value)); return value; }
			double operator()() { return get(); }
			operator double () { return get(); }
			void put(double value) { hrcheck(enc(&ISpeechSynthesizerOptions2_adaptor::AudioVolume)->_put_AudioVolume(value)); }
			void operator=(double value) { put(value); }
			void operator()(double value) { put(value); }
		} AudioVolume;
		struct : property {
			double get() { double value; hrcheck(enc(&ISpeechSynthesizerOptions2_adaptor::SpeakingRate)->_get_SpeakingRate(&value)); return value; }
			double operator()() { return get(); }
			operator double () { return get(); }
			void put(double value) { hrcheck(enc(&ISpeechSynthesizerOptions2_adaptor::SpeakingRate)->_put_SpeakingRate(value)); }
			void operator=(double value) { put(value); }
			void operator()(double value) { put(value); }
		} SpeakingRate;
	};
	ISpeechSynthesizerOptions2_adaptor() {}
};
template<typename X> struct adapt<ISpeechSynthesizerOptions2, X> : Windows::Media::SpeechSynthesis::ISpeechSynthesizerOptions2_adaptor<X> { typedef adapt ISpeechSynthesizerOptions2; };
struct ISpeechSynthesizerOptions2 : ISpeechSynthesizerOptions2_raw, generate<ISpeechSynthesizerOptions2> {};

// ISpeechSynthesizerOptions
struct ISpeechSynthesizerOptions_raw : IInspectable {
	virtual STDMETHODIMP _get_IncludeWordBoundaryMetadata(bool *value);
	virtual STDMETHODIMP _put_IncludeWordBoundaryMetadata(bool value);
	virtual STDMETHODIMP _get_IncludeSentenceBoundaryMetadata(bool *value);
	virtual STDMETHODIMP _put_IncludeSentenceBoundaryMetadata(bool value);
};
template<typename X> struct ISpeechSynthesizerOptions_adaptor : X {
	union {
		struct : property {
			bool get() { bool value; hrcheck(enc(&ISpeechSynthesizerOptions_adaptor::IncludeSentenceBoundaryMetadata)->_get_IncludeSentenceBoundaryMetadata(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&ISpeechSynthesizerOptions_adaptor::IncludeSentenceBoundaryMetadata)->_put_IncludeSentenceBoundaryMetadata(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} IncludeSentenceBoundaryMetadata;
		struct : property {
			bool get() { bool value; hrcheck(enc(&ISpeechSynthesizerOptions_adaptor::IncludeWordBoundaryMetadata)->_get_IncludeWordBoundaryMetadata(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&ISpeechSynthesizerOptions_adaptor::IncludeWordBoundaryMetadata)->_put_IncludeWordBoundaryMetadata(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} IncludeWordBoundaryMetadata;
	};
	ISpeechSynthesizerOptions_adaptor() {}
};
template<typename X> struct adapt<ISpeechSynthesizerOptions, X> : Windows::Media::SpeechSynthesis::ISpeechSynthesizerOptions_adaptor<X> { typedef adapt ISpeechSynthesizerOptions; };
struct ISpeechSynthesizerOptions : ISpeechSynthesizerOptions_raw, generate<ISpeechSynthesizerOptions> {};

// SpeechSynthesizerOptions
template<typename X> struct statics<SpeechSynthesizerOptions, X> : X {
	typedef typename X::root_type SpeechSynthesizerOptions;
};
struct SpeechSynthesizerOptions : generate<SpeechSynthesizerOptions> {};

// SpeechSynthesizer
template<typename> struct SpeechSynthesizer_statics {
	static struct _AllVoices : property {
		ptr<Foundation::Collections::IVectorView<ptr<VoiceInformation>>> get() { Foundation::Collections::IVectorView<VoiceInformation*>* value; hrcheck(get_activation_factory<SpeechSynthesizer, IInstalledVoicesStatic>()->_get_AllVoices(&value)); return from_abi(value); }
		ptr<Foundation::Collections::IVectorView<ptr<VoiceInformation>>> operator()() { return get(); }
		operator ptr<Foundation::Collections::IVectorView<ptr<VoiceInformation>>> () { return get(); }
		ptr<Foundation::Collections::IVectorView<ptr<VoiceInformation>>> operator->() { return get(); }
	} AllVoices;
	static struct _DefaultVoice : property {
		ptr<VoiceInformation> get() { VoiceInformation* value; hrcheck(get_activation_factory<SpeechSynthesizer, IInstalledVoicesStatic>()->_get_DefaultVoice(&value)); return from_abi(value); }
		ptr<VoiceInformation> operator()() { return get(); }
		operator ptr<VoiceInformation> () { return get(); }
		ptr<VoiceInformation> operator->() { return get(); }
	} DefaultVoice;
	static ptr<Foundation::IAsyncOperation<bool>> TrySetDefaultVoiceAsync(pptr<VoiceInformation> voice) { Foundation::IAsyncOperation<bool>* result; hrcheck(get_activation_factory<SpeechSynthesizer, IInstalledVoicesStatic2>()->_TrySetDefaultVoiceAsync(voice, &result)); return from_abi(result); }
};
template<typename X> typename SpeechSynthesizer_statics<X>::_AllVoices SpeechSynthesizer_statics<X>::AllVoices;
template<typename X> typename SpeechSynthesizer_statics<X>::_DefaultVoice SpeechSynthesizer_statics<X>::DefaultVoice;

template<typename X> struct statics<SpeechSynthesizer, X> : X, Windows::Media::SpeechSynthesis::SpeechSynthesizer_statics<void> {
	typedef typename X::root_type SpeechSynthesizer;
};
struct SpeechSynthesizer : generate<SpeechSynthesizer> {};
}}}
} // namespace iso_winrt
