#pragma once
// generated by isopod tools
// namespaces:
// Windows.UI.Input.Inking.Analysis

#include "Windows.UI.Input.Inking.Analysis.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IIterable;
template<typename T> struct IVectorView;
}}
namespace UI { namespace Input { namespace Inking {
struct InkStroke;
}}}}

// defs

template<> struct def<Windows::UI::Input::Inking::Analysis::InkAnalysisDrawingKind> : enum_type<int> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::InkAnalysisNodeKind> : enum_type<int> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::InkAnalysisStatus> : enum_type<int> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::InkAnalysisStrokeKind> : enum_type<int> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::IInkAnalyzer> : interface_type<> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::IInkAnalysisNode> : overridable_type<> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::IInkAnalysisRoot> : interface_type<Windows::UI::Input::Inking::Analysis::IInkAnalysisNode> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::InkAnalysisRoot> : class_type<Platform::Object, Windows::UI::Input::Inking::Analysis::IInkAnalysisRoot> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::IInkAnalysisResult> : interface_type<> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::InkAnalysisResult> : class_type<Platform::Object, Windows::UI::Input::Inking::Analysis::IInkAnalysisResult> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::InkAnalyzer> : class_type<Platform::Object, Windows::UI::Input::Inking::Analysis::IInkAnalyzer> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::IInkAnalyzerFactory> : overridable_type<> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::InkAnalysisNode> : class_type<Platform::Object, Windows::UI::Input::Inking::Analysis::IInkAnalysisNode> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::IInkAnalysisWritingRegion> : interface_type<Windows::UI::Input::Inking::Analysis::IInkAnalysisNode> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::InkAnalysisWritingRegion> : class_type<Platform::Object, Windows::UI::Input::Inking::Analysis::IInkAnalysisWritingRegion> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::IInkAnalysisParagraph> : interface_type<Windows::UI::Input::Inking::Analysis::IInkAnalysisNode> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::InkAnalysisParagraph> : class_type<Platform::Object, Windows::UI::Input::Inking::Analysis::IInkAnalysisParagraph> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::IInkAnalysisListItem> : interface_type<Windows::UI::Input::Inking::Analysis::IInkAnalysisNode> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::InkAnalysisListItem> : class_type<Platform::Object, Windows::UI::Input::Inking::Analysis::IInkAnalysisListItem> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::IInkAnalysisInkBullet> : interface_type<Windows::UI::Input::Inking::Analysis::IInkAnalysisNode> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::InkAnalysisInkBullet> : class_type<Platform::Object, Windows::UI::Input::Inking::Analysis::IInkAnalysisInkBullet> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::IInkAnalysisLine> : interface_type<Windows::UI::Input::Inking::Analysis::IInkAnalysisNode> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::InkAnalysisLine> : class_type<Platform::Object, Windows::UI::Input::Inking::Analysis::IInkAnalysisLine> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::IInkAnalysisInkWord> : interface_type<Windows::UI::Input::Inking::Analysis::IInkAnalysisNode> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::InkAnalysisInkWord> : class_type<Platform::Object, Windows::UI::Input::Inking::Analysis::IInkAnalysisInkWord> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::IInkAnalysisInkDrawing> : interface_type<Windows::UI::Input::Inking::Analysis::IInkAnalysisNode> {};
template<> struct def<Windows::UI::Input::Inking::Analysis::InkAnalysisInkDrawing> : class_type<Platform::Object, Windows::UI::Input::Inking::Analysis::IInkAnalysisInkDrawing> {};

// uuids

template<> struct uuid<Windows::UI::Input::Inking::Analysis::IInkAnalyzer> { define_guid(0xF12B8F95, 0x866, 0x4DC5, 0x8C, 0x77, 0xF8, 0x86, 0x14, 0xDF, 0xE3, 0x8C);};
template<> struct uuid<Windows::UI::Input::Inking::Analysis::IInkAnalysisNode> { define_guid(0x30831F05, 0x5F64, 0x4A2C, 0xBA, 0x37, 0x4F, 0x48, 0x87, 0x87, 0x95, 0x74);};
template<> struct uuid<Windows::UI::Input::Inking::Analysis::IInkAnalysisRoot> { define_guid(0x3FB6A3C4, 0x2FDE, 0x4061, 0x85, 0x2, 0xA9, 0xF, 0x32, 0x54, 0x5B, 0x84);};
template<> struct uuid<Windows::UI::Input::Inking::Analysis::IInkAnalysisResult> { define_guid(0x8948BA79, 0xA243, 0x4AA3, 0xA2, 0x94, 0x1F, 0x98, 0xBD, 0xF, 0xF5, 0x80);};
template<> struct uuid<Windows::UI::Input::Inking::Analysis::IInkAnalyzerFactory> { define_guid(0x29138686, 0x1963, 0x49D8, 0x95, 0x89, 0xE1, 0x43, 0x84, 0xC7, 0x69, 0xE3);};
template<> struct uuid<Windows::UI::Input::Inking::Analysis::IInkAnalysisWritingRegion> { define_guid(0xDD6D6231, 0xBD16, 0x4663, 0xB5, 0xAE, 0x94, 0x1D, 0x30, 0x43, 0xEF, 0x5B);};
template<> struct uuid<Windows::UI::Input::Inking::Analysis::IInkAnalysisParagraph> { define_guid(0xD9AD045C, 0xCD1, 0x4DD4, 0xA6, 0x8B, 0xEB, 0x1F, 0x12, 0xB3, 0xD7, 0x27);};
template<> struct uuid<Windows::UI::Input::Inking::Analysis::IInkAnalysisListItem> { define_guid(0xB4E3C23F, 0xC4C3, 0x4C3A, 0xA1, 0xA6, 0x9D, 0x85, 0x54, 0x7E, 0xE5, 0x86);};
template<> struct uuid<Windows::UI::Input::Inking::Analysis::IInkAnalysisInkBullet> { define_guid(0xEE049368, 0x6110, 0x4136, 0x95, 0xF9, 0xEE, 0x80, 0x9F, 0xC2, 0x0, 0x30);};
template<> struct uuid<Windows::UI::Input::Inking::Analysis::IInkAnalysisLine> { define_guid(0xA06D048D, 0x2B8D, 0x4754, 0xAD, 0x5A, 0xD0, 0x87, 0x11, 0x93, 0xA9, 0x56);};
template<> struct uuid<Windows::UI::Input::Inking::Analysis::IInkAnalysisInkWord> { define_guid(0x4BD228AD, 0x83AF, 0x4034, 0x8F, 0x3B, 0xF8, 0x68, 0x7D, 0xFF, 0xF4, 0x36);};
template<> struct uuid<Windows::UI::Input::Inking::Analysis::IInkAnalysisInkDrawing> { define_guid(0x6A85ED1F, 0x1FE4, 0x4E15, 0x89, 0x8C, 0x8E, 0x11, 0x23, 0x77, 0xE0, 0x21);};

// types

namespace Windows { namespace UI { namespace Input { namespace Inking { namespace Analysis {

// IInkAnalyzer
struct IInkAnalyzer_raw : IInspectable {
	virtual STDMETHODIMP _get_AnalysisRoot(InkAnalysisRoot* *value);
	virtual STDMETHODIMP _get_IsAnalyzing(bool *value);
	virtual STDMETHODIMP _AddDataForStroke(InkStroke* stroke);
	virtual STDMETHODIMP _AddDataForStrokes(Foundation::Collections::IIterable<InkStroke*>* strokes);
	virtual STDMETHODIMP _ClearDataForAllStrokes();
	virtual STDMETHODIMP _RemoveDataForStroke(unsigned strokeId);
	virtual STDMETHODIMP _RemoveDataForStrokes(Foundation::Collections::IIterable<unsigned>* strokeIds);
	virtual STDMETHODIMP _ReplaceDataForStroke(InkStroke* stroke);
	virtual STDMETHODIMP _SetStrokeDataKind(unsigned strokeId, InkAnalysisStrokeKind strokeKind);
	virtual STDMETHODIMP _AnalyzeAsync(Foundation::IAsyncOperation<InkAnalysisResult*>* *result);
};
template<typename X> struct IInkAnalyzer_adaptor : X {
	union {
		struct : property {
			ptr<InkAnalysisRoot> get() { InkAnalysisRoot* value; hrcheck(enc(&IInkAnalyzer_adaptor::AnalysisRoot)->_get_AnalysisRoot(&value)); return from_abi(value); }
			ptr<InkAnalysisRoot> operator()() { return get(); }
			operator ptr<InkAnalysisRoot> () { return get(); }
			ptr<InkAnalysisRoot> operator->() { return get(); }
		} AnalysisRoot;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IInkAnalyzer_adaptor::IsAnalyzing)->_get_IsAnalyzing(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} IsAnalyzing;
	};
	void AddDataForStroke(pptr<InkStroke> stroke) { hrcheck(X::get()->_AddDataForStroke(stroke)); }
	void AddDataForStrokes(pptr<Foundation::Collections::IIterable<ptr<InkStroke>>> strokes) { hrcheck(X::get()->_AddDataForStrokes(to_abi(strokes))); }
	void ClearDataForAllStrokes() { hrcheck(X::get()->_ClearDataForAllStrokes()); }
	void RemoveDataForStroke(unsigned strokeId) { hrcheck(X::get()->_RemoveDataForStroke(strokeId)); }
	void RemoveDataForStrokes(pptr<Foundation::Collections::IIterable<unsigned>> strokeIds) { hrcheck(X::get()->_RemoveDataForStrokes(to_abi(strokeIds))); }
	void ReplaceDataForStroke(pptr<InkStroke> stroke) { hrcheck(X::get()->_ReplaceDataForStroke(stroke)); }
	void SetStrokeDataKind(unsigned strokeId, InkAnalysisStrokeKind strokeKind) { hrcheck(X::get()->_SetStrokeDataKind(strokeId, strokeKind)); }
	ptr<Foundation::IAsyncOperation<ptr<InkAnalysisResult>>> AnalyzeAsync() { Foundation::IAsyncOperation<InkAnalysisResult*>* result; hrcheck(X::get()->_AnalyzeAsync(&result)); return from_abi(result); }
	IInkAnalyzer_adaptor() {}
};
template<typename X> struct adapt<IInkAnalyzer, X> : Windows::UI::Input::Inking::Analysis::IInkAnalyzer_adaptor<X> { typedef adapt IInkAnalyzer; };
struct IInkAnalyzer : IInkAnalyzer_raw, generate<IInkAnalyzer> {};

// IInkAnalysisNode
struct IInkAnalysisNode_raw : IInspectable {
	virtual STDMETHODIMP _get_Id(unsigned *value) = 0;
	virtual STDMETHODIMP _get_Kind(InkAnalysisNodeKind *value) = 0;
	virtual STDMETHODIMP _get_BoundingRect(Foundation::Rect *value) = 0;
	virtual STDMETHODIMP _get_RotatedBoundingRect(Foundation::Collections::IVectorView<Foundation::Point>* *value) = 0;
	virtual STDMETHODIMP _get_Children(Foundation::Collections::IVectorView<IInkAnalysisNode*>* *value) = 0;
	virtual STDMETHODIMP _get_Parent(IInkAnalysisNode* *value) = 0;
	virtual STDMETHODIMP _GetStrokeIds(Foundation::Collections::IVectorView<unsigned>* *strokeIds) = 0;
};
template<typename X> struct IInkAnalysisNode_adaptor : X {
	union {
		struct : property {
			Foundation::Rect get() { Foundation::Rect value; hrcheck(enc(&IInkAnalysisNode_adaptor::BoundingRect)->_get_BoundingRect(&value)); return value; }
			Foundation::Rect operator()() { return get(); }
			operator Foundation::Rect () { return get(); }
		} BoundingRect;
		struct : property {
			ptr<Foundation::Collections::IVectorView<ptr<IInkAnalysisNode>>> get() { Foundation::Collections::IVectorView<IInkAnalysisNode*>* value; hrcheck(enc(&IInkAnalysisNode_adaptor::Children)->_get_Children(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<ptr<IInkAnalysisNode>>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<ptr<IInkAnalysisNode>>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<ptr<IInkAnalysisNode>>> operator->() { return get(); }
		} Children;
		struct : property {
			unsigned get() { unsigned value; hrcheck(enc(&IInkAnalysisNode_adaptor::Id)->_get_Id(&value)); return value; }
			unsigned operator()() { return get(); }
			operator unsigned () { return get(); }
		} Id;
		struct : property {
			InkAnalysisNodeKind get() { InkAnalysisNodeKind value; hrcheck(enc(&IInkAnalysisNode_adaptor::Kind)->_get_Kind(&value)); return value; }
			InkAnalysisNodeKind operator()() { return get(); }
			operator InkAnalysisNodeKind () { return get(); }
		} Kind;
		struct : property {
			ptr<IInkAnalysisNode> get() { IInkAnalysisNode* value; hrcheck(enc(&IInkAnalysisNode_adaptor::Parent)->_get_Parent(&value)); return from_abi(value); }
			ptr<IInkAnalysisNode> operator()() { return get(); }
			operator ptr<IInkAnalysisNode> () { return get(); }
			ptr<IInkAnalysisNode> operator->() { return get(); }
		} Parent;
		struct : property {
			ptr<Foundation::Collections::IVectorView<Foundation::Point>> get() { Foundation::Collections::IVectorView<Foundation::Point>* value; hrcheck(enc(&IInkAnalysisNode_adaptor::RotatedBoundingRect)->_get_RotatedBoundingRect(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<Foundation::Point>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<Foundation::Point>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<Foundation::Point>> operator->() { return get(); }
		} RotatedBoundingRect;
	};
	ptr<Foundation::Collections::IVectorView<unsigned>> GetStrokeIds() { Foundation::Collections::IVectorView<unsigned>* strokeIds; hrcheck(X::get()->_GetStrokeIds(&strokeIds)); return from_abi(strokeIds); }
	IInkAnalysisNode_adaptor() {}
};
template<typename X> struct adapt<IInkAnalysisNode, X> : Windows::UI::Input::Inking::Analysis::IInkAnalysisNode_adaptor<X> { typedef adapt IInkAnalysisNode; };
template<typename X> struct IInkAnalysisNode_unadaptor : X {
	STDMETHODIMP _get_Id(unsigned *value) { return hrtry([&, this] { get_prop(value, Id); }); }
	STDMETHODIMP _get_Kind(InkAnalysisNodeKind *value) { return hrtry([&, this] { get_prop(value, Kind); }); }
	STDMETHODIMP _get_BoundingRect(Foundation::Rect *value) { return hrtry([&, this] { get_prop(value, BoundingRect); }); }
	STDMETHODIMP _get_RotatedBoundingRect(Foundation::Collections::IVectorView<Foundation::Point>* *value) { return hrtry([&, this] { get_prop(value, RotatedBoundingRect); }); }
	STDMETHODIMP _get_Children(Foundation::Collections::IVectorView<IInkAnalysisNode*>* *value) { return hrtry([&, this] { get_prop(value, Children); }); }
	STDMETHODIMP _get_Parent(IInkAnalysisNode* *value) { return hrtry([&, this] { get_prop(value, Parent); }); }
	STDMETHODIMP _GetStrokeIds(Foundation::Collections::IVectorView<unsigned>* *strokeIds) { return hrtry([&, this] { *strokeIds = to_abi(X::get()->GetStrokeIds()); }); }
};
template<typename X> struct unadapt<IInkAnalysisNode, X> : Windows::UI::Input::Inking::Analysis::IInkAnalysisNode_unadaptor<X> {};
struct IInkAnalysisNode : IInkAnalysisNode_raw, generate<IInkAnalysisNode> {};

// IInkAnalysisRoot
struct IInkAnalysisRoot_raw : IInspectable {
	virtual STDMETHODIMP _get_RecognizedText(HSTRING *value);
	virtual STDMETHODIMP _FindNodes(InkAnalysisNodeKind nodeKind, Foundation::Collections::IVectorView<IInkAnalysisNode*>* *result);
};
template<typename X> struct IInkAnalysisRoot_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IInkAnalysisRoot_adaptor::RecognizedText)->_get_RecognizedText(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} RecognizedText;
	};
	ptr<Foundation::Collections::IVectorView<ptr<IInkAnalysisNode>>> FindNodes(InkAnalysisNodeKind nodeKind) { Foundation::Collections::IVectorView<IInkAnalysisNode*>* result; hrcheck(X::get()->_FindNodes(nodeKind, &result)); return from_abi(result); }
	IInkAnalysisRoot_adaptor() {}
};
template<typename X> struct adapt<IInkAnalysisRoot, X> : Windows::UI::Input::Inking::Analysis::IInkAnalysisRoot_adaptor<X> { typedef adapt IInkAnalysisRoot; };
struct IInkAnalysisRoot : IInkAnalysisRoot_raw, generate<IInkAnalysisRoot> {};

// InkAnalysisRoot
template<typename X> struct statics<InkAnalysisRoot, X> : X {
	typedef typename X::root_type InkAnalysisRoot;
};
struct InkAnalysisRoot : generate<InkAnalysisRoot> {};

// IInkAnalysisResult
struct IInkAnalysisResult_raw : IInspectable {
	virtual STDMETHODIMP _get_Status(InkAnalysisStatus *value);
};
template<typename X> struct IInkAnalysisResult_adaptor : X {
	union {
		struct : property {
			InkAnalysisStatus get() { InkAnalysisStatus value; hrcheck(enc(&IInkAnalysisResult_adaptor::Status)->_get_Status(&value)); return value; }
			InkAnalysisStatus operator()() { return get(); }
			operator InkAnalysisStatus () { return get(); }
		} Status;
	};
	IInkAnalysisResult_adaptor() {}
};
template<typename X> struct adapt<IInkAnalysisResult, X> : Windows::UI::Input::Inking::Analysis::IInkAnalysisResult_adaptor<X> { typedef adapt IInkAnalysisResult; };
struct IInkAnalysisResult : IInkAnalysisResult_raw, generate<IInkAnalysisResult> {};

// InkAnalysisResult
template<typename X> struct statics<InkAnalysisResult, X> : X {
	typedef typename X::root_type InkAnalysisResult;
};
struct InkAnalysisResult : generate<InkAnalysisResult> {};

// InkAnalyzer
template<typename X> struct statics<InkAnalyzer, X> : X {
	typedef typename X::root_type InkAnalyzer;
};
struct InkAnalyzer : generate<InkAnalyzer> {};

// IInkAnalyzerFactory
struct IInkAnalyzerFactory_raw : IInspectable {
	virtual STDMETHODIMP _CreateAnalyzer(InkAnalyzer* *result) = 0;
};
template<typename X> struct IInkAnalyzerFactory_adaptor : X {
	ptr<InkAnalyzer> CreateAnalyzer() { InkAnalyzer* result; hrcheck(X::get()->_CreateAnalyzer(&result)); return from_abi(result); }
};
template<typename X> struct adapt<IInkAnalyzerFactory, X> : Windows::UI::Input::Inking::Analysis::IInkAnalyzerFactory_adaptor<X> { typedef adapt IInkAnalyzerFactory; };
template<typename X> struct IInkAnalyzerFactory_unadaptor : X {
	STDMETHODIMP _CreateAnalyzer(InkAnalyzer* *result) { return hrtry([&, this] { *result = to_abi(X::get()->CreateAnalyzer()); }); }
};
template<typename X> struct unadapt<IInkAnalyzerFactory, X> : Windows::UI::Input::Inking::Analysis::IInkAnalyzerFactory_unadaptor<X> {};
struct IInkAnalyzerFactory : IInkAnalyzerFactory_raw, generate<IInkAnalyzerFactory> {};

// InkAnalysisNode
template<typename X> struct statics<InkAnalysisNode, X> : X {
	typedef typename X::root_type InkAnalysisNode;
};
struct InkAnalysisNode : generate<InkAnalysisNode> {};

// IInkAnalysisWritingRegion
struct IInkAnalysisWritingRegion_raw : IInspectable {
	virtual STDMETHODIMP _get_RecognizedText(HSTRING *value);
};
template<typename X> struct IInkAnalysisWritingRegion_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IInkAnalysisWritingRegion_adaptor::RecognizedText)->_get_RecognizedText(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} RecognizedText;
	};
	IInkAnalysisWritingRegion_adaptor() {}
};
template<typename X> struct adapt<IInkAnalysisWritingRegion, X> : Windows::UI::Input::Inking::Analysis::IInkAnalysisWritingRegion_adaptor<X> { typedef adapt IInkAnalysisWritingRegion; };
struct IInkAnalysisWritingRegion : IInkAnalysisWritingRegion_raw, generate<IInkAnalysisWritingRegion> {};

// InkAnalysisWritingRegion
template<typename X> struct statics<InkAnalysisWritingRegion, X> : X {
	typedef typename X::root_type InkAnalysisWritingRegion;
};
struct InkAnalysisWritingRegion : generate<InkAnalysisWritingRegion> {};

// IInkAnalysisParagraph
struct IInkAnalysisParagraph_raw : IInspectable {
	virtual STDMETHODIMP _get_RecognizedText(HSTRING *value);
};
template<typename X> struct IInkAnalysisParagraph_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IInkAnalysisParagraph_adaptor::RecognizedText)->_get_RecognizedText(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} RecognizedText;
	};
	IInkAnalysisParagraph_adaptor() {}
};
template<typename X> struct adapt<IInkAnalysisParagraph, X> : Windows::UI::Input::Inking::Analysis::IInkAnalysisParagraph_adaptor<X> { typedef adapt IInkAnalysisParagraph; };
struct IInkAnalysisParagraph : IInkAnalysisParagraph_raw, generate<IInkAnalysisParagraph> {};

// InkAnalysisParagraph
template<typename X> struct statics<InkAnalysisParagraph, X> : X {
	typedef typename X::root_type InkAnalysisParagraph;
};
struct InkAnalysisParagraph : generate<InkAnalysisParagraph> {};

// IInkAnalysisListItem
struct IInkAnalysisListItem_raw : IInspectable {
	virtual STDMETHODIMP _get_RecognizedText(HSTRING *value);
};
template<typename X> struct IInkAnalysisListItem_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IInkAnalysisListItem_adaptor::RecognizedText)->_get_RecognizedText(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} RecognizedText;
	};
	IInkAnalysisListItem_adaptor() {}
};
template<typename X> struct adapt<IInkAnalysisListItem, X> : Windows::UI::Input::Inking::Analysis::IInkAnalysisListItem_adaptor<X> { typedef adapt IInkAnalysisListItem; };
struct IInkAnalysisListItem : IInkAnalysisListItem_raw, generate<IInkAnalysisListItem> {};

// InkAnalysisListItem
template<typename X> struct statics<InkAnalysisListItem, X> : X {
	typedef typename X::root_type InkAnalysisListItem;
};
struct InkAnalysisListItem : generate<InkAnalysisListItem> {};

// IInkAnalysisInkBullet
struct IInkAnalysisInkBullet_raw : IInspectable {
	virtual STDMETHODIMP _get_RecognizedText(HSTRING *value);
};
template<typename X> struct IInkAnalysisInkBullet_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IInkAnalysisInkBullet_adaptor::RecognizedText)->_get_RecognizedText(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} RecognizedText;
	};
	IInkAnalysisInkBullet_adaptor() {}
};
template<typename X> struct adapt<IInkAnalysisInkBullet, X> : Windows::UI::Input::Inking::Analysis::IInkAnalysisInkBullet_adaptor<X> { typedef adapt IInkAnalysisInkBullet; };
struct IInkAnalysisInkBullet : IInkAnalysisInkBullet_raw, generate<IInkAnalysisInkBullet> {};

// InkAnalysisInkBullet
template<typename X> struct statics<InkAnalysisInkBullet, X> : X {
	typedef typename X::root_type InkAnalysisInkBullet;
};
struct InkAnalysisInkBullet : generate<InkAnalysisInkBullet> {};

// IInkAnalysisLine
struct IInkAnalysisLine_raw : IInspectable {
	virtual STDMETHODIMP _get_RecognizedText(HSTRING *value);
	virtual STDMETHODIMP _get_IndentLevel(int *value);
};
template<typename X> struct IInkAnalysisLine_adaptor : X {
	union {
		struct : property {
			int get() { int value; hrcheck(enc(&IInkAnalysisLine_adaptor::IndentLevel)->_get_IndentLevel(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} IndentLevel;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IInkAnalysisLine_adaptor::RecognizedText)->_get_RecognizedText(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} RecognizedText;
	};
	IInkAnalysisLine_adaptor() {}
};
template<typename X> struct adapt<IInkAnalysisLine, X> : Windows::UI::Input::Inking::Analysis::IInkAnalysisLine_adaptor<X> { typedef adapt IInkAnalysisLine; };
struct IInkAnalysisLine : IInkAnalysisLine_raw, generate<IInkAnalysisLine> {};

// InkAnalysisLine
template<typename X> struct statics<InkAnalysisLine, X> : X {
	typedef typename X::root_type InkAnalysisLine;
};
struct InkAnalysisLine : generate<InkAnalysisLine> {};

// IInkAnalysisInkWord
struct IInkAnalysisInkWord_raw : IInspectable {
	virtual STDMETHODIMP _get_RecognizedText(HSTRING *value);
	virtual STDMETHODIMP _get_TextAlternates(Foundation::Collections::IVectorView<HSTRING>* *value);
};
template<typename X> struct IInkAnalysisInkWord_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IInkAnalysisInkWord_adaptor::RecognizedText)->_get_RecognizedText(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} RecognizedText;
		struct : property {
			ptr<Foundation::Collections::IVectorView<hstring>> get() { Foundation::Collections::IVectorView<HSTRING>* value; hrcheck(enc(&IInkAnalysisInkWord_adaptor::TextAlternates)->_get_TextAlternates(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<hstring>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<hstring>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<hstring>> operator->() { return get(); }
		} TextAlternates;
	};
	IInkAnalysisInkWord_adaptor() {}
};
template<typename X> struct adapt<IInkAnalysisInkWord, X> : Windows::UI::Input::Inking::Analysis::IInkAnalysisInkWord_adaptor<X> { typedef adapt IInkAnalysisInkWord; };
struct IInkAnalysisInkWord : IInkAnalysisInkWord_raw, generate<IInkAnalysisInkWord> {};

// InkAnalysisInkWord
template<typename X> struct statics<InkAnalysisInkWord, X> : X {
	typedef typename X::root_type InkAnalysisInkWord;
};
struct InkAnalysisInkWord : generate<InkAnalysisInkWord> {};

// IInkAnalysisInkDrawing
struct IInkAnalysisInkDrawing_raw : IInspectable {
	virtual STDMETHODIMP _get_DrawingKind(InkAnalysisDrawingKind *value);
	virtual STDMETHODIMP _get_Center(Foundation::Point *value);
	virtual STDMETHODIMP _get_Points(Foundation::Collections::IVectorView<Foundation::Point>* *value);
};
template<typename X> struct IInkAnalysisInkDrawing_adaptor : X {
	union {
		struct : property {
			Foundation::Point get() { Foundation::Point value; hrcheck(enc(&IInkAnalysisInkDrawing_adaptor::Center)->_get_Center(&value)); return value; }
			Foundation::Point operator()() { return get(); }
			operator Foundation::Point () { return get(); }
		} Center;
		struct : property {
			InkAnalysisDrawingKind get() { InkAnalysisDrawingKind value; hrcheck(enc(&IInkAnalysisInkDrawing_adaptor::DrawingKind)->_get_DrawingKind(&value)); return value; }
			InkAnalysisDrawingKind operator()() { return get(); }
			operator InkAnalysisDrawingKind () { return get(); }
		} DrawingKind;
		struct : property {
			ptr<Foundation::Collections::IVectorView<Foundation::Point>> get() { Foundation::Collections::IVectorView<Foundation::Point>* value; hrcheck(enc(&IInkAnalysisInkDrawing_adaptor::Points)->_get_Points(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<Foundation::Point>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<Foundation::Point>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<Foundation::Point>> operator->() { return get(); }
		} Points;
	};
	IInkAnalysisInkDrawing_adaptor() {}
};
template<typename X> struct adapt<IInkAnalysisInkDrawing, X> : Windows::UI::Input::Inking::Analysis::IInkAnalysisInkDrawing_adaptor<X> { typedef adapt IInkAnalysisInkDrawing; };
struct IInkAnalysisInkDrawing : IInkAnalysisInkDrawing_raw, generate<IInkAnalysisInkDrawing> {};

// InkAnalysisInkDrawing
template<typename X> struct statics<InkAnalysisInkDrawing, X> : X {
	typedef typename X::root_type InkAnalysisInkDrawing;
};
struct InkAnalysisInkDrawing : generate<InkAnalysisInkDrawing> {};
}}}}}
} // namespace iso_winrt