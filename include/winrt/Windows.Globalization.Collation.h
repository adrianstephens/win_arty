#pragma once
// generated by isopod tools
// namespaces:
// Windows.Globalization.Collation

#include "Windows.Globalization.Collation.0.h"
#include "Windows.Foundation.Collections.h"

namespace iso_winrt {

// forward types


// defs

template<> struct def<Windows::Globalization::Collation::ICharacterGrouping> : interface_type<> {};
template<> struct def<Windows::Globalization::Collation::CharacterGrouping> : class_type<Platform::Object, Windows::Globalization::Collation::ICharacterGrouping> {};
template<> struct def<Windows::Globalization::Collation::ICharacterGroupingsFactory> : interface_type<> {};
template<> struct def<Windows::Globalization::Collation::ICharacterGroupings> : interface_type<Windows::Foundation::Collections::IVectorView<ptr<Windows::Globalization::Collation::CharacterGrouping>>, Windows::Foundation::Collections::IIterable<ptr<Windows::Globalization::Collation::CharacterGrouping>>> {};
template<> struct def<Windows::Globalization::Collation::CharacterGroupings> : class_type<Platform::Object, Windows::Globalization::Collation::ICharacterGroupings>, custom_activators {};

// uuids

template<> struct uuid<Windows::Globalization::Collation::ICharacterGrouping> { define_guid(0xFAE761BB, 0x805D, 0x4BB0, 0x95, 0xBB, 0xC1, 0xF7, 0xC3, 0xE8, 0xEB, 0x8E);};
template<> struct uuid<Windows::Globalization::Collation::ICharacterGroupingsFactory> { define_guid(0x99EA9FD9, 0x886D, 0x4401, 0x9F, 0x98, 0x69, 0xC8, 0x2D, 0x4C, 0x2F, 0x78);};
template<> struct uuid<Windows::Globalization::Collation::ICharacterGroupings> { define_guid(0xB8D20A75, 0xD4CF, 0x4055, 0x80, 0xE5, 0xCE, 0x16, 0x9C, 0x22, 0x64, 0x96);};

// types

namespace Windows { namespace Globalization { namespace Collation {

// ICharacterGrouping
struct ICharacterGrouping_raw : IInspectable {
	virtual STDMETHODIMP _get_First(HSTRING *value);
	virtual STDMETHODIMP _get_Label(HSTRING *value);
};
template<typename X> struct ICharacterGrouping_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&ICharacterGrouping_adaptor::First)->_get_First(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} First;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&ICharacterGrouping_adaptor::Label)->_get_Label(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Label;
	};
	ICharacterGrouping_adaptor() {}
};
template<typename X> struct adapt<ICharacterGrouping, X> : Windows::Globalization::Collation::ICharacterGrouping_adaptor<X> { typedef adapt ICharacterGrouping; };
struct ICharacterGrouping : ICharacterGrouping_raw, generate<ICharacterGrouping> {};

// CharacterGrouping
template<typename X> struct statics<CharacterGrouping, X> : X {
	typedef typename X::root_type CharacterGrouping;
};
struct CharacterGrouping : generate<CharacterGrouping> {};

// ICharacterGroupingsFactory
struct ICharacterGroupingsFactory : IInspectable {
	virtual STDMETHODIMP _Create(HSTRING language, CharacterGroupings* *result);
};

// ICharacterGroupings
struct ICharacterGroupings_raw : IInspectable {
	virtual STDMETHODIMP _Lookup(HSTRING text, HSTRING *result);
};
template<typename X> struct ICharacterGroupings_adaptor : X {
	hstring Lookup(hstring_ref text) { HSTRING result; hrcheck(X::get()->_Lookup(text, &result)); return from_abi(result); }
};
template<typename X> struct adapt<ICharacterGroupings, X> : Windows::Globalization::Collation::ICharacterGroupings_adaptor<X> { typedef adapt ICharacterGroupings; };
struct ICharacterGroupings : ICharacterGroupings_raw, generate<ICharacterGroupings> {};

// CharacterGroupings
template<typename> struct CharacterGroupings_statics {
	static CharacterGroupings *activate() { CharacterGroupings *t; get_activation_factory<CharacterGroupings>()->ActivateInstance((IInspectable**)&t); return t; }
	static CharacterGroupings *activate(hstring_ref language) { CharacterGroupings *result; hrcheck(get_activation_factory<CharacterGroupings, ICharacterGroupingsFactory>()->_Create(language, &result)); return result; }
};

template<typename X> struct statics<CharacterGroupings, X> : X, Windows::Globalization::Collation::CharacterGroupings_statics<void> {
	using Windows::Globalization::Collation::CharacterGroupings_statics<void>::activate;
	typedef typename X::root_type CharacterGroupings;
};
struct CharacterGroupings : generate<CharacterGroupings> {};
}}}
} // namespace iso_winrt